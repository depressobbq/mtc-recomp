#include <memory>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cctype>
#include <vector>
#include <atomic>
#include <chrono>
#include <filesystem>

#include "hle/rt64_application.h"
#include "hle/rt64_state.h"
#include "render/rt64_texture_cache.h"

#include "mtc_game.hpp"
#include "ultramodern/ultramodern.hpp"
#include "ultramodern/config.hpp"
#include "ultramodern/renderer_context.hpp"

std::atomic<uint64_t> mtc_dl_count{0}, mtc_screen_count{0};

namespace {
    uint8_t DMEM[0x1000];
    uint8_t IMEM[0x1000];
}

unsigned int MI_INTR_REG = 0;
unsigned int DPC_START_REG = 0;
unsigned int DPC_END_REG = 0;
unsigned int DPC_CURRENT_REG = 0;
unsigned int DPC_STATUS_REG = 0;
unsigned int DPC_CLOCK_REG = 0;
unsigned int DPC_BUFBUSY_REG = 0;
unsigned int DPC_PIPEBUSY_REG = 0;
unsigned int DPC_TMEM_REG = 0;

static void dummy_check_interrupts() {}

static RT64::UserConfiguration::AspectRatio to_rt64(ultramodern::renderer::AspectRatio o) {
    switch (o) {
        case ultramodern::renderer::AspectRatio::Expand: return RT64::UserConfiguration::AspectRatio::Expand;
        case ultramodern::renderer::AspectRatio::Manual: return RT64::UserConfiguration::AspectRatio::Manual;
        default: return RT64::UserConfiguration::AspectRatio::Original;
    }
}
static RT64::UserConfiguration::Antialiasing to_rt64(ultramodern::renderer::Antialiasing o) {
    switch (o) {
        case ultramodern::renderer::Antialiasing::MSAA2X: return RT64::UserConfiguration::Antialiasing::MSAA2X;
        case ultramodern::renderer::Antialiasing::MSAA4X: return RT64::UserConfiguration::Antialiasing::MSAA4X;
        case ultramodern::renderer::Antialiasing::MSAA8X: return RT64::UserConfiguration::Antialiasing::MSAA8X;
        default: return RT64::UserConfiguration::Antialiasing::None;
    }
}
static RT64::UserConfiguration::RefreshRate to_rt64(ultramodern::renderer::RefreshRate o) {
    switch (o) {
        case ultramodern::renderer::RefreshRate::Display: return RT64::UserConfiguration::RefreshRate::Display;
        case ultramodern::renderer::RefreshRate::Manual: return RT64::UserConfiguration::RefreshRate::Manual;
        default: return RT64::UserConfiguration::RefreshRate::Original;
    }
}
static RT64::UserConfiguration::InternalColorFormat to_rt64(ultramodern::renderer::HighPrecisionFramebuffer o) {
    switch (o) {
        case ultramodern::renderer::HighPrecisionFramebuffer::Off: return RT64::UserConfiguration::InternalColorFormat::Standard;
        case ultramodern::renderer::HighPrecisionFramebuffer::On: return RT64::UserConfiguration::InternalColorFormat::High;
        default: return RT64::UserConfiguration::InternalColorFormat::Automatic;
    }
}

static void apply_user_config(RT64::Application* app, const ultramodern::renderer::GraphicsConfig& config) {
    switch (config.res_option) {
        default:
        case ultramodern::renderer::Resolution::Auto:
            app->userConfig.resolution = RT64::UserConfiguration::Resolution::WindowIntegerScale;
            app->userConfig.downsampleMultiplier = 1;
            break;
        case ultramodern::renderer::Resolution::Original:
            app->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
            app->userConfig.resolutionMultiplier = std::max(config.ds_option, 1);
            app->userConfig.downsampleMultiplier = std::max(config.ds_option, 1);
            break;
        case ultramodern::renderer::Resolution::Original2x:
            app->userConfig.resolution = RT64::UserConfiguration::Resolution::Manual;
            app->userConfig.resolutionMultiplier = 2.0 * std::max(config.ds_option, 1);
            app->userConfig.downsampleMultiplier = std::max(config.ds_option, 1);
            break;
    }
    app->userConfig.aspectRatio = to_rt64(config.ar_option);
    app->userConfig.antialiasing = to_rt64(config.msaa_option);
    app->userConfig.refreshRate = to_rt64(config.rr_option);
    app->userConfig.refreshRateTarget = config.rr_manual_value;
    app->userConfig.internalColorFormat = to_rt64(config.hpfb_option);
    app->userConfig.displayBuffering = RT64::UserConfiguration::DisplayBuffering::Triple;
    app->userConfig.threePointFiltering = true;
    app->userConfig.filtering = RT64::UserConfiguration::Filtering::Linear;
    app->userConfig.upscale2D = RT64::UserConfiguration::Upscale2D::All;
}

static ultramodern::renderer::SetupResult map_setup_result(RT64::Application::SetupResult result) {
    switch (result) {
        case RT64::Application::SetupResult::Success: return ultramodern::renderer::SetupResult::Success;
        case RT64::Application::SetupResult::DynamicLibrariesNotFound: return ultramodern::renderer::SetupResult::DynamicLibrariesNotFound;
        case RT64::Application::SetupResult::InvalidGraphicsAPI: return ultramodern::renderer::SetupResult::InvalidGraphicsAPI;
        case RT64::Application::SetupResult::GraphicsAPINotFound: return ultramodern::renderer::SetupResult::GraphicsAPINotFound;
        default: return ultramodern::renderer::SetupResult::GraphicsDeviceNotFound;
    }
}

static ultramodern::renderer::GraphicsApi map_graphics_api(RT64::UserConfiguration::GraphicsAPI api) {
    switch (api) {
        case RT64::UserConfiguration::GraphicsAPI::D3D12: return ultramodern::renderer::GraphicsApi::D3D12;
        case RT64::UserConfiguration::GraphicsAPI::Vulkan: return ultramodern::renderer::GraphicsApi::Vulkan;
        default: return ultramodern::renderer::GraphicsApi::Auto;
    }
}

namespace mtc {
    class RT64Context : public ultramodern::renderer::RendererContext {
    public:
        RT64Context(uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode) {
            auto cfg = ultramodern::renderer::get_graphics_config();

            RT64::Application::Core appCore{};
            appCore.window = window_handle;
            appCore.checkInterrupts = dummy_check_interrupts;
            appCore.MI_INTR_REG = &MI_INTR_REG;
            appCore.DPC_START_REG = &DPC_START_REG;
            appCore.DPC_END_REG = &DPC_END_REG;
            appCore.DPC_CURRENT_REG = &DPC_CURRENT_REG;
            appCore.DPC_STATUS_REG = &DPC_STATUS_REG;
            appCore.DPC_CLOCK_REG = &DPC_CLOCK_REG;
            appCore.DPC_BUFBUSY_REG = &DPC_BUFBUSY_REG;
            appCore.DPC_PIPEBUSY_REG = &DPC_PIPEBUSY_REG;
            appCore.DPC_TMEM_REG = &DPC_TMEM_REG;
            appCore.RDRAM = rdram;
            appCore.DMEM = DMEM;
            appCore.IMEM = IMEM;

            auto vi_regs = ultramodern::renderer::get_vi_regs();
            appCore.VI_STATUS_REG = &vi_regs->VI_STATUS_REG;
            appCore.VI_ORIGIN_REG = &vi_regs->VI_ORIGIN_REG;
            appCore.VI_WIDTH_REG = &vi_regs->VI_WIDTH_REG;
            appCore.VI_INTR_REG = &vi_regs->VI_INTR_REG;
            appCore.VI_V_CURRENT_LINE_REG = &vi_regs->VI_V_CURRENT_LINE_REG;
            appCore.VI_TIMING_REG = &vi_regs->VI_TIMING_REG;
            appCore.VI_V_SYNC_REG = &vi_regs->VI_V_SYNC_REG;
            appCore.VI_H_SYNC_REG = &vi_regs->VI_H_SYNC_REG;
            appCore.VI_LEAP_REG = &vi_regs->VI_LEAP_REG;
            appCore.VI_H_START_REG = &vi_regs->VI_H_START_REG;
            appCore.VI_V_START_REG = &vi_regs->VI_V_START_REG;
            appCore.VI_V_BURST_REG = &vi_regs->VI_V_BURST_REG;
            appCore.VI_X_SCALE_REG = &vi_regs->VI_X_SCALE_REG;
            appCore.VI_Y_SCALE_REG = &vi_regs->VI_Y_SCALE_REG;

            RT64::ApplicationConfiguration appConfig{};
            appConfig.useConfigurationFile = false;
            app = std::make_unique<RT64::Application>(appCore, appConfig);

            apply_user_config(app.get(), cfg);
            app->userConfig.developerMode = developer_mode;
            switch (cfg.api_option) {
                case ultramodern::renderer::GraphicsApi::D3D12: app->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::D3D12; break;
                case ultramodern::renderer::GraphicsApi::Vulkan: app->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::Vulkan; break;
                default: app->userConfig.graphicsAPI = RT64::UserConfiguration::GraphicsAPI::Automatic; break;
            }

            uint32_t thread_id = 0;
#ifdef _WIN32
            thread_id = window_handle.thread_id;
#endif
            setup_result = map_setup_result(app->setup(thread_id));
            chosen_api = map_graphics_api(app->chosenGraphicsAPI);
            if (setup_result != ultramodern::renderer::SetupResult::Success) {
                app = nullptr;
                return;
            }
            app->setFullScreen(cfg.wm_option == ultramodern::renderer::WindowMode::Fullscreen);

            app->enhancementConfig.s2dex.fixBilerpMismatch = true;
            app->enhancementConfig.rect.fixRectLR = true;
            app->updateEnhancementConfig();

            std::filesystem::path dump_dir = "/home/jedi404/Projects/mtc-recomp/dumped_textures";
            std::error_code ec;
            std::filesystem::create_directories(dump_dir, ec);
            app->state->dumpingTexturesDirectory = dump_dir;
            printf("[gfx] Texture dumping enabled to %s\n", dump_dir.string().c_str());
        }

        ~RT64Context() override = default;

        bool valid() override { return static_cast<bool>(app); }

        bool update_config(const ultramodern::renderer::GraphicsConfig& old_config, const ultramodern::renderer::GraphicsConfig& new_config) override {
            if (old_config == new_config) return false;
            if (new_config.wm_option != old_config.wm_option) {
                app->setFullScreen(new_config.wm_option == ultramodern::renderer::WindowMode::Fullscreen);
            }
            apply_user_config(app.get(), new_config);
            app->updateUserConfig(true);
            if (new_config.msaa_option != old_config.msaa_option) {
                app->updateMultisampling();
            }
            return true;
        }

        void enable_instant_present() override {
            app->enhancementConfig.presentation.mode = RT64::EnhancementConfiguration::Presentation::Mode::PresentEarly;
            app->enhancementConfig.s2dex.fixBilerpMismatch = true;
            app->enhancementConfig.rect.fixRectLR = true;
            app->updateEnhancementConfig();
        }

        void send_dl(const OSTask* task) override {
            uint64_t count = ++mtc_dl_count;
            if (count <= 10 || (count % 300 == 0)) {
                const char* ucode_str = (const char*)(app->core.RDRAM + (task->t.ucode_data & 0x3FFFFFF));
                printf("[gfx] send_dl #%lu: ucode=0x%08x, data=0x%08x, dl=0x%08x (tag: %.32s)\n",
                       count, (uint32_t)task->t.ucode, (uint32_t)task->t.ucode_data, (uint32_t)task->t.data_ptr, ucode_str);
            }
            app->state->rsp->reset();
            app->interpreter->loadUCodeGBI(task->t.ucode & 0x3FFFFFF, task->t.ucode_data & 0x3FFFFFF, true);
            app->processDisplayLists(app->core.RDRAM, task->t.data_ptr & 0x3FFFFFF, 0, true);
        }

        void send_dummy_workload(uint32_t) override {}

        void update_screen() override {
            ++mtc_screen_count;
            app->updateScreen();
        }

        void shutdown() override {
            if (app != nullptr) app->end();
        }

        uint32_t get_display_framerate() const override {
            return app->presentQueue->ext.sharedResources->swapChainRate;
        }

        float get_resolution_scale() const override {
            constexpr int ReferenceHeight = 240;
            switch (app->userConfig.resolution) {
                case RT64::UserConfiguration::Resolution::WindowIntegerScale:
                    if (app->sharedQueueResources->swapChainHeight > 0) {
                        return std::max(float((app->sharedQueueResources->swapChainHeight + ReferenceHeight - 1) / ReferenceHeight), 1.0f);
                    }
                    return 1.0f;
                case RT64::UserConfiguration::Resolution::Manual:
                    return float(app->userConfig.resolutionMultiplier);
                default:
                    return 1.0f;
            }
        }

    private:
        std::unique_ptr<RT64::Application> app;
    };

    std::unique_ptr<ultramodern::renderer::RendererContext> create_rt64_context(uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode) {
        return std::make_unique<RT64Context>(rdram, window_handle, developer_mode);
    }
}
