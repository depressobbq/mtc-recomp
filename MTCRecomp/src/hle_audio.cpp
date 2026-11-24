// High-level emulation (HLE) of the game's audio microcode using mupen64plus-rsp-hle.
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include "librecomp/rsp.hpp"

extern "C" {
#include "hle_audio/hle_internal.h"
void alist_process_audio(struct hle_t* hle);

void HleWarnMessage(void*, const char* message, ...) {
    static int count = 0;
    if (count++ > 20) return;
    va_list ap; va_start(ap, message);
    fprintf(stderr, "[hle audio] "); vfprintf(stderr, message, ap); fprintf(stderr, "\n");
    va_end(ap);
}
void HleVerboseMessage(void*, const char*, ...) {}
void HleInfoMessage(void*, const char*, ...) {}
void HleErrorMessage(void*, const char* message, ...) {
    va_list ap; va_start(ap, message);
    fprintf(stderr, "[hle audio] error: "); vfprintf(stderr, message, ap); fprintf(stderr, "\n");
    va_end(ap);
}
void rsp_break(struct hle_t*, unsigned int) {}
}

namespace {
    hle_t g_hle{};
}

RspExitReason mtc_hle_audio_ucode(uint8_t* rdram, uint32_t /*ucode_addr*/) {
    g_hle.dram = rdram;
    g_hle.dmem = dmem;
    alist_process_audio(&g_hle);
    return RspExitReason::Broke;
}
