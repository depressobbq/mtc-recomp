// SDL2 + RT64 backend for Magical Tetris Challenge: window, audio, keyboard/gamepad input.
#include <array>
#include <atomic>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <filesystem>
#include <mutex>
#include <algorithm>
#include <string>
#include <vector>

#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_syswm.h"

#undef None
#undef Status
#undef LockMask
#undef ControlMask
#undef Success
#undef Always

#include "mtc_game.hpp"
#include "sdl_audio.hpp"

namespace mtc {
    std::unique_ptr<ultramodern::renderer::RendererContext> create_rt64_context(uint8_t*, ultramodern::renderer::WindowHandle, bool);
}

namespace {
    constexpr uint16_t N64_A = 0x8000, N64_B = 0x4000, N64_Z = 0x2000, N64_START = 0x1000,
        N64_DU = 0x0800, N64_DD = 0x0400, N64_DL = 0x0200, N64_DR = 0x0100,
        N64_L = 0x0020, N64_R = 0x0010, N64_CU = 0x0008, N64_CD = 0x0004, N64_CL = 0x0002, N64_CR = 0x0001;

    SDL_Window* window = nullptr;
    bool fullscreen = false;

    struct PadState {
        uint16_t buttons = 0;
        float x = 0, y = 0;
        bool connected = false;
    };
    std::mutex input_mutex;
    std::array<PadState, 4> pads{};
    std::vector<SDL_GameController*> controllers;

    enum Stick { StickNone, StickUp, StickDown, StickLeft, StickRight };
    struct KeyBinding {
        SDL_Scancode scancode;
        uint16_t bit;
        Stick stick;
    };
    std::vector<KeyBinding> keymap;

    void build_default_keymap() {
        keymap.clear();
        // D-Pad
        keymap.push_back({ SDL_SCANCODE_UP, N64_DU, StickNone });
        keymap.push_back({ SDL_SCANCODE_DOWN, N64_DD, StickNone });
        keymap.push_back({ SDL_SCANCODE_LEFT, N64_DL, StickNone });
        keymap.push_back({ SDL_SCANCODE_RIGHT, N64_DR, StickNone });
        // Analog stick
        keymap.push_back({ SDL_SCANCODE_W, 0, StickUp });
        keymap.push_back({ SDL_SCANCODE_S, 0, StickDown });
        keymap.push_back({ SDL_SCANCODE_A, 0, StickLeft });
        keymap.push_back({ SDL_SCANCODE_D, 0, StickRight });
        // Face buttons & triggers
        keymap.push_back({ SDL_SCANCODE_X, N64_A, StickNone });
        keymap.push_back({ SDL_SCANCODE_C, N64_B, StickNone });
        keymap.push_back({ SDL_SCANCODE_Z, N64_Z, StickNone });
        keymap.push_back({ SDL_SCANCODE_SPACE, N64_A, StickNone });
        keymap.push_back({ SDL_SCANCODE_RETURN, N64_START, StickNone });
        keymap.push_back({ SDL_SCANCODE_Q, N64_L, StickNone });
        keymap.push_back({ SDL_SCANCODE_E, N64_R, StickNone });
        // C-buttons
        keymap.push_back({ SDL_SCANCODE_I, N64_CU, StickNone });
        keymap.push_back({ SDL_SCANCODE_K, N64_CD, StickNone });
        keymap.push_back({ SDL_SCANCODE_J, N64_CL, StickNone });
        keymap.push_back({ SDL_SCANCODE_L, N64_CR, StickNone });
    }

    void refresh_controllers() {
        for (auto* c : controllers) {
            if (c) SDL_GameControllerClose(c);
        }
        controllers.clear();
        int num = SDL_NumJoysticks();
        for (int i = 0; i < num && (int)controllers.size() < 4; i++) {
            if (SDL_IsGameController(i)) {
                if (auto* c = SDL_GameControllerOpen(i)) {
                    controllers.push_back(c);
                }
            }
        }
    }

    void sample_inputs() {
        std::lock_guard<std::mutex> lock(input_mutex);
        const Uint8* keys = SDL_GetKeyboardState(nullptr);

        for (size_t i = 0; i < pads.size(); i++) {
            pads[i].buttons = 0;
            pads[i].x = 0;
            pads[i].y = 0;
            pads[i].connected = false;
        }

        // Keyboard to player 1
        pads[0].connected = true;
        float kx = 0, ky = 0;
        for (const auto& b : keymap) {
            if (keys[b.scancode]) {
                pads[0].buttons |= b.bit;
                if (b.stick == StickUp) ky += 1.0f;
                if (b.stick == StickDown) ky -= 1.0f;
                if (b.stick == StickLeft) kx -= 1.0f;
                if (b.stick == StickRight) kx += 1.0f;
            }
        }
        pads[0].x = std::clamp(kx, -1.0f, 1.0f);
        pads[0].y = std::clamp(ky, -1.0f, 1.0f);

        // Gamepad inputs
        for (size_t i = 0; i < controllers.size(); i++) {
            auto* c = controllers[i];
            if (!c || !SDL_GameControllerGetAttached(c)) continue;
            pads[i].connected = true;

            auto btn = [&](SDL_GameControllerButton b, uint16_t mask) {
                if (SDL_GameControllerGetButton(c, b)) pads[i].buttons |= mask;
            };

            btn(SDL_CONTROLLER_BUTTON_A, N64_A);
            btn(SDL_CONTROLLER_BUTTON_B, N64_B);
            btn(SDL_CONTROLLER_BUTTON_X, N64_B);
            btn(SDL_CONTROLLER_BUTTON_Y, N64_A);
            btn(SDL_CONTROLLER_BUTTON_START, N64_START);
            btn(SDL_CONTROLLER_BUTTON_LEFTSHOULDER, N64_L);
            btn(SDL_CONTROLLER_BUTTON_RIGHTSHOULDER, N64_R);
            btn(SDL_CONTROLLER_BUTTON_DPAD_UP, N64_DU);
            btn(SDL_CONTROLLER_BUTTON_DPAD_DOWN, N64_DD);
            btn(SDL_CONTROLLER_BUTTON_DPAD_LEFT, N64_DL);
            btn(SDL_CONTROLLER_BUTTON_DPAD_RIGHT, N64_DR);

            if (SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_TRIGGERLEFT) > 8000 ||
                SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_TRIGGERRIGHT) > 8000) {
                pads[i].buttons |= N64_Z;
            }

            int16_t ax = SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_LEFTX);
            int16_t ay = SDL_GameControllerGetAxis(c, SDL_CONTROLLER_AXIS_LEFTY);
            if (std::abs(ax) > 4000) pads[i].x = ax / 32767.0f;
            if (std::abs(ay) > 4000) pads[i].y = -ay / 32767.0f;
        }
    }

    void toggle_fullscreen() {
        fullscreen = !fullscreen;
        SDL_SetWindowFullscreen(window, fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
    }

    void poll_input() {}

    bool get_input(int controller_num, uint16_t* buttons, float* x, float* y) {
        std::lock_guard<std::mutex> lock(input_mutex);
        if (controller_num < 0 || controller_num >= (int)pads.size()) return false;
        const auto& state = pads[controller_num];
        if (buttons) *buttons = state.buttons;
        if (x) *x = state.x;
        if (y) *y = state.y;
        return true;
    }

    void set_rumble(int, bool) {}

    ultramodern::input::connected_device_info_t get_connected_device_info(int controller_num) {
        std::lock_guard<std::mutex> lock(input_mutex);
        if (controller_num < 0 || controller_num >= (int)pads.size() || !pads[controller_num].connected) {
            return {
                .connected_device = ultramodern::input::Device::None,
                .connected_pak = ultramodern::input::Pak::None,
            };
        }
        return {
            .connected_device = ultramodern::input::Device::Controller,
            .connected_pak = ultramodern::input::Pak::None,
        };
    }

    void* create_gfx() {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) < 0) {
            fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
            std::exit(EXIT_FAILURE);
        }
        refresh_controllers();
        return nullptr;
    }

    ultramodern::renderer::WindowHandle create_window(void*) {
        uint32_t flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
#ifdef RT64_SDL_WINDOW_VULKAN
        flags |= SDL_WINDOW_VULKAN;
#endif
        window = SDL_CreateWindow(
            "Magical Tetris Challenge - Recompiled",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            960, 720,
            flags
        );
        if (!window) {
            fprintf(stderr, "SDL_CreateWindow failed: %s\n", SDL_GetError());
            std::exit(EXIT_FAILURE);
        }

#ifdef _WIN32
        SDL_SysWMinfo wmInfo;
        SDL_VERSION(&wmInfo.version);
        SDL_GetWindowWMInfo(window, &wmInfo);
        return { .window = wmInfo.info.win.window, .thread_id = GetCurrentThreadId() };
#else
        return window;
#endif
    }

    void update_gfx(void*) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                    ultramodern::quit();
                    break;
                case SDL_KEYDOWN:
                    if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                        ultramodern::quit();
                    }
                    if (e.key.keysym.scancode == SDL_SCANCODE_F11 && !e.key.repeat) toggle_fullscreen();
                    if (e.key.keysym.scancode == SDL_SCANCODE_RETURN && (e.key.keysym.mod & KMOD_ALT) && !e.key.repeat) toggle_fullscreen();
                    break;
                case SDL_CONTROLLERDEVICEADDED:
                case SDL_CONTROLLERDEVICEREMOVED:
                    refresh_controllers();
                    break;
            }
        }
        sample_inputs();
    }

    void queue_samples(int16_t* data, size_t count) { mtc::audio::queue_samples(data, count); }
    size_t get_frames_remaining() { return mtc::audio::frames_remaining(); }
    void set_frequency(uint32_t freq) { mtc::audio::set_frequency(freq); }

    void message_box(const char* msg) {
        fprintf(stderr, "%s\n", msg);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Magical Tetris Challenge", msg, window);
    }

    std::unique_ptr<ultramodern::renderer::RendererContext> create_render_context(uint8_t* rdram, ultramodern::renderer::WindowHandle wh, bool dev) {
        return mtc::create_rt64_context(rdram, wh, dev);
    }
}

mtc::Backend mtc::make_backend(int argc, char** argv) {
    (void)argc; (void)argv;
    build_default_keymap();
    mtc::audio::open();

    using namespace ultramodern::renderer;
    GraphicsConfig cfg{};
    cfg.developer_mode = false;
    cfg.res_option = Resolution::Auto;
    cfg.wm_option = WindowMode::Windowed;
    cfg.hr_option = HUDRatioMode::Original;
    cfg.api_option = GraphicsApi::Vulkan;
    cfg.ar_option = AspectRatio::Original;
    cfg.msaa_option = Antialiasing::MSAA4X;
    cfg.rr_option = RefreshRate::Display;
    cfg.hpfb_option = HighPrecisionFramebuffer::Auto;
    cfg.ds_option = 1;
    set_graphics_config(cfg);

    mtc::Backend b{
        .renderer = {
            .create_render_context = ::create_render_context,
            .get_graphics_api_name = nullptr,
        },
        .gfx = {
            .create_gfx = create_gfx,
            .create_window = create_window,
            .update_gfx = update_gfx,
        },
        .audio = {
            .queue_samples = queue_samples,
            .get_frames_remaining = get_frames_remaining,
            .set_frequency = set_frequency,
        },
        .input = {
            .poll_input = poll_input,
            .get_input = get_input,
            .set_rumble = set_rumble,
            .get_connected_device_info = get_connected_device_info,
        },
        .events = {
            .vi_callback = nullptr,
            .gfx_init_callback = nullptr,
        },
        .error_handling = {
            .message_box = message_box,
        },
    };
    return b;
}
