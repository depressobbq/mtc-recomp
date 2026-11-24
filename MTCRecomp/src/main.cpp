// Magical Tetris Challenge: Recompiled - Linux Native Port
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <filesystem>
#include "mtc_game.hpp"
#include "librecomp/rsp.hpp"
#include "SDL.h"

extern "C" void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx);
gpr get_entrypoint_address();
void mtc_register_overlays();
RspExitReason mtc_hle_audio_ucode(uint8_t* rdram, uint32_t ucode_addr);

RspExitReason aspMain(uint8_t* rdram, uint32_t ucode_addr);

RspUcodeFunc* mtc_select_rsp_microcode(const OSTask* task) {
    if (task->t.type == M_AUDTASK) {
        return aspMain;
    }
    return nullptr;
}

static constexpr int32_t osViModeNtscLan1_addr = (int32_t)0x800A8110;
static void mtc_on_init(uint8_t* rdram, recomp_context*) {
    osViSetMode(rdram, osViModeNtscLan1_addr);
}

#ifdef _WIN32
static const recomp::Version project_version{ 1, 0, 0, "-windows" };
#else
static const recomp::Version project_version{ 1, 0, 0, "-linux" };
#endif

static std::string get_game_thread_name(const OSThread* t) {
    std::string name = "[MTC] ";
    switch (t->priority) {
        case 150: return name + "PIMGR";
        case 254: return name + "VIMGR";
        default:  return name + "id" + std::to_string(t->id) + "p" + std::to_string(t->priority);
    }
}

std::filesystem::path mtc::data_folder() {
    if (const char* env = std::getenv("MTC_DATA_DIR")) {
        return std::filesystem::path{ env };
    }
    return std::filesystem::current_path() / "mtc_data";
}

static bool ends_with_rom_ext(const std::string& s) {
    for (const char* ext : { ".z64", ".Z64", ".n64", ".N64", ".v64", ".V64" }) {
        size_t n = std::strlen(ext);
        if (s.size() >= n && s.compare(s.size() - n, n, ext) == 0) return true;
    }
    return false;
}

int main(int argc, char** argv) {
    setvbuf(stdout, nullptr, _IONBF, 0);
    setvbuf(stderr, nullptr, _IONBF, 0);

    std::error_code ec;
    std::filesystem::create_directories(mtc::data_folder(), ec);
    recomp::register_config_path(mtc::data_folder());

    recomp::GameEntry mtc_entry{
        .rom_hash = 0x37FDE08DC8AEC6F3ULL,   // XXH3-64 of Magical Tetris Challenge (USA)
        .internal_name = "MAGICAL TETRIS",
        .display_name = "Magical Tetris Challenge",
        .game_id = u8"mtc.n64.us.1.0",
        .mod_game_id = "mtc",
        .save_type = recomp::SaveType::AllowAll,
        .is_enabled = true,
        .entrypoint_address = get_entrypoint_address(),
        .entrypoint = recomp_entrypoint,
        .on_init_callback = mtc_on_init,
    };
    recomp::register_game(mtc_entry);
    mtc_register_overlays();

    // 1. Check CLI argument
    std::vector<char*> args{ argv, argv + argc };
    std::string rom_arg;
    for (int i = 1; i < argc; i++) {
        if (ends_with_rom_ext(argv[i])) rom_arg = argv[i];
    }
    if (!rom_arg.empty()) {
        auto err = recomp::select_rom(rom_arg, mtc_entry.game_id);
        if (err != recomp::RomValidationError::Good) {
            fprintf(stderr, "ROM rejected: %s (error %d)\n", rom_arg.c_str(), (int)err);
            return EXIT_FAILURE;
        }
        printf("ROM accepted and stored in %s\n", mtc::data_folder().string().c_str());
    }

    // 2. Check stored ROMs
    recomp::check_all_stored_roms();
    bool has_valid_rom = recomp::is_rom_valid(mtc_entry.game_id);

    // 3. Auto-detect from candidate paths
    if (!has_valid_rom) {
        std::vector<std::filesystem::path> candidates = {
            "roms/Magical Tetris Challenge (USA).z64",
            "../roms/Magical Tetris Challenge (USA).z64",
            "baserom.us.z64",
            "../baserom.us.z64",
            "Magical Tetris Challenge (USA).z64",
            "baserom.z64"
        };
        for (const auto& candidate : candidates) {
            if (std::filesystem::exists(candidate)) {
                auto err = recomp::select_rom(candidate, mtc_entry.game_id);
                if (err == recomp::RomValidationError::Good) {
                    recomp::check_all_stored_roms();
                    has_valid_rom = recomp::is_rom_valid(mtc_entry.game_id);
                    if (has_valid_rom) {
                        printf("Automatically imported %s into %s\n", candidate.string().c_str(), mtc::data_folder().string().c_str());
                        break;
                    }
                }
            }
        }
    }

    if (!has_valid_rom) {
        fprintf(stderr, "No valid ROM found for Magical Tetris Challenge (USA). Please provide the ROM path.\n");
        return EXIT_FAILURE;
    }

    static char game_flag[] = "--game";
    static char game_name[] = "mtc";
    bool has_game_flag = false;
    for (int i = 1; i < argc; i++) {
        if (std::strcmp(argv[i], "--game") == 0) has_game_flag = true;
    }
    if (!has_game_flag) {
        args.push_back(game_flag);
        args.push_back(game_name);
    }

    mtc::Backend backend = mtc::make_backend(argc, argv);

    recomp::Configuration cfg{};
    cfg.argc = (int)args.size();
    cfg.argv = args.data();
    cfg.project_version = project_version;
    cfg.rsp_callbacks = { .get_rsp_microcode = mtc_select_rsp_microcode };
    cfg.renderer_callbacks = backend.renderer;
    cfg.audio_callbacks = backend.audio;
    cfg.input_callbacks = backend.input;
    cfg.gfx_callbacks = backend.gfx;
    cfg.events_callbacks = backend.events;
    cfg.error_handling_callbacks = backend.error_handling;
    cfg.threads_callbacks = { .get_game_thread_name = get_game_thread_name };

    printf("[MTC] Starting Magical Tetris Challenge recompiled engine...\n");
    recomp::start(cfg);

    return EXIT_SUCCESS;
}
