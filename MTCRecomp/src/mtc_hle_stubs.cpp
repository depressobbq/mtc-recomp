#include <cstdint>
#include "recomp.h"

// Fallback stubs for low-level Libultra hardware functions
extern "C" {

void __osSetCompare_recomp(uint8_t* /*rdram*/, recomp_context* /*ctx*/) {
}

void __osAiDeviceBusy_recomp(uint8_t* /*rdram*/, recomp_context* ctx) {
    ctx->r2 = 0;
}

void __osSiDeviceBusy_recomp(uint8_t* /*rdram*/, recomp_context* ctx) {
    ctx->r2 = 0;
}

void __osSiCreateAccessQueue_recomp(uint8_t* /*rdram*/, recomp_context* /*ctx*/) {
}

void __osContGetInitData_recomp(uint8_t* /*rdram*/, recomp_context* ctx) {
    ctx->r2 = 0;
}

void osEPiRawReadIo_recomp(uint8_t* /*rdram*/, recomp_context* ctx) {
    ctx->r2 = 0;
}

void osEPiRawWriteIo_recomp(uint8_t* /*rdram*/, recomp_context* ctx) {
    ctx->r2 = 0;
}

void __osContRamRead_recomp(uint8_t* /*rdram*/, recomp_context* ctx) {
    ctx->r2 = 1; // PFS_ERR_NOPACK
}

void __osContRamWrite_recomp(uint8_t* /*rdram*/, recomp_context* ctx) {
    ctx->r2 = 1; // PFS_ERR_NOPACK
}

}
