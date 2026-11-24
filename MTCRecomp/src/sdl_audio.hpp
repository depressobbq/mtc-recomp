#pragma once
#include <cstddef>
#include <cstdint>

namespace mtc::audio {
    void open();
    void queue_samples(int16_t* data, size_t sample_count);
    size_t frames_remaining();
    void set_frequency(uint32_t freq);
    void set_volume(int percent);
}
