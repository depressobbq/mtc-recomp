#include "sdl_audio.hpp"
#include <algorithm>
#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <vector>
#include "SDL.h"

namespace {
    SDL_AudioDeviceID device = 0;
    uint32_t game_rate = 44100, device_rate = 48000;
    std::mutex mutex;
    std::atomic<float> volume{ 1.0f };
    SDL_AudioStream* stream = nullptr;

    constexpr int device_channels = 2;
    constexpr size_t device_frame_bytes = device_channels * sizeof(float);

    // Headroom in VIs (~16.6ms each). 2 VIs (~33ms) is ideal for Linux PulseAudio/PipeWire.
    uint64_t headroom_vis = 2;

    void rebuild() {
        if (stream) {
            SDL_FreeAudioStream(stream);
            stream = nullptr;
        }
        stream = SDL_NewAudioStream(AUDIO_S16SYS, 2, (int)game_rate, AUDIO_F32SYS, device_channels, (int)device_rate);
        if (!stream) {
            fprintf(stderr, "[audio] SDL_NewAudioStream failed: %s\n", SDL_GetError());
        }
    }

    double queued_ms_locked() {
        if (!device) return 0.0;
        return SDL_GetQueuedAudioSize(device) / double(device_frame_bytes) * 1000.0 / device_rate;
    }
}

namespace mtc::audio {
    void open() {
        if (device != 0) return;
        if (const char* h = std::getenv("MTC_AUDIO_HEADROOM")) {
            headroom_vis = std::strtoull(h, nullptr, 10);
        }
        if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
            fprintf(stderr, "[audio] SDL_InitSubSystem failed: %s\n", SDL_GetError());
            return;
        }

        SDL_AudioSpec want{}, have{};
        want.freq = 48000;
        want.format = AUDIO_F32SYS;
        want.channels = device_channels;
        want.samples = 512; // 512 samples (~10.6ms buffer on Linux) minimizes latency

        device = SDL_OpenAudioDevice(nullptr, 0, &want, &have, SDL_AUDIO_ALLOW_FREQUENCY_CHANGE);
        if (device == 0) {
            fprintf(stderr, "[audio] SDL_OpenAudioDevice failed: %s\n", SDL_GetError());
            return;
        }

        device_rate = (uint32_t)have.freq;
        rebuild();
        SDL_PauseAudioDevice(device, 0);
        printf("[audio] SDL audio initialized: %u Hz (game: %u Hz, buffer: %u samples, headroom: %lu VIs)\n",
            device_rate, game_rate, have.samples, (unsigned long)headroom_vis);
    }

    void set_frequency(uint32_t freq) {
        if (freq == 0 || freq == game_rate) return;
        std::lock_guard<std::mutex> lock(mutex);
        printf("[audio] game sample rate changed: %u Hz -> %u Hz\n", game_rate, freq);
        game_rate = freq;
        rebuild();
    }

    void set_volume(int percent) {
        volume.store(std::clamp(percent, 0, 100) / 100.0f);
    }

    // Reports remaining audio frames to the N64 osAiGetLength() rate controller.
    // Real N64 hardware reports only what's remaining of the current DMA buffer (at most 1 VI's worth).
    // We hold `headroom_vis` frames back so SDL never runs dry, and never report more than 1 VI.
    size_t frames_remaining() {
        if (device == 0) return 0;
        std::lock_guard<std::mutex> lock(mutex);
        uint64_t dev_frames = SDL_GetQueuedAudioSize(device) / device_frame_bytes;
        uint64_t pending = 0;
        if (stream) pending = SDL_AudioStreamAvailable(stream) / device_frame_bytes;
        uint64_t queued = (dev_frames + pending) * game_rate / std::max<uint32_t>(device_rate, 1);
        uint64_t per_vi = game_rate / 60;
        uint64_t headroom = per_vi * headroom_vis;
        uint64_t reported = queued > headroom ? queued - headroom : 0;
        return (size_t)std::min<uint64_t>(reported, per_vi);
    }

    void queue_samples(int16_t* data, size_t sample_count) {
        if (device == 0 || !data || sample_count == 0) return;
        if (sample_count * sizeof(int16_t) > 0x3FFF8) return;

        std::lock_guard<std::mutex> lock(mutex);
        if (!stream) rebuild();
        if (!stream) return;

        // Prevent overflow if something stalls upstream
        if (queued_ms_locked() > 300.0) return;

        size_t frames = sample_count / 2;
        static std::vector<int16_t> lr;
        lr.resize(frames * 2);
        for (size_t i = 0; i < frames; i++) {
            lr[2 * i] = data[2 * i + 1];
            lr[2 * i + 1] = data[2 * i];
        }

        size_t byte_count = lr.size() * sizeof(int16_t);
        if (SDL_AudioStreamPut(stream, lr.data(), (int)byte_count) < 0) {
            fprintf(stderr, "[audio] SDL_AudioStreamPut failed: %s\n", SDL_GetError());
            return;
        }

        int available = SDL_AudioStreamAvailable(stream);
        if (available > 0) {
            std::vector<float> buf(available / sizeof(float));
            int gotten = SDL_AudioStreamGet(stream, buf.data(), available);
            if (gotten > 0) {
                float v = volume.load();
                if (v < 0.999f) {
                    for (float& s : buf) s *= v;
                }
                SDL_QueueAudio(device, buf.data(), (uint32_t)gotten);
            }
        }
    }
}
