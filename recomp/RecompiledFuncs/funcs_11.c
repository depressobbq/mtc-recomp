#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8002D0D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D0D4: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8002D0D8: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x8002D0DC: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8002D0E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002D0E4: beq         $a0, $v0, L_8002D14C
    if (ctx->r4 == ctx->r2) {
        // 0x8002D0E8: slti        $v0, $a0, 0x2
        ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
            goto L_8002D14C;
    }
    // 0x8002D0E8: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8002D0EC: beql        $v0, $zero, L_8002D104
    if (ctx->r2 == 0) {
        // 0x8002D0F0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8002D104;
    }
    goto skip_0;
    // 0x8002D0F0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8002D0F4: beq         $a0, $zero, L_8002D11C
    if (ctx->r4 == 0) {
        // 0x8002D0F8: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8002D11C;
    }
    // 0x8002D0F8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8002D0FC: j           L_8002D1B0
    // 0x8002D100: nop

        goto L_8002D1B0;
    // 0x8002D100: nop

L_8002D104:
    // 0x8002D104: beq         $a0, $v0, L_8002D188
    if (ctx->r4 == ctx->r2) {
        // 0x8002D108: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002D188;
    }
    // 0x8002D108: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D10C: beq         $a0, $v0, L_8002D1A8
    if (ctx->r4 == ctx->r2) {
        // 0x8002D110: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8002D1A8;
    }
    // 0x8002D110: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002D114: j           L_8002D1B0
    // 0x8002D118: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_8002D1B0;
    // 0x8002D118: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8002D11C:
    // 0x8002D11C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002D120: lbu         $v1, 0x6D68($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D68);
    // 0x8002D124: sltiu       $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 < 0XFF ? 1 : 0;
    // 0x8002D128: beq         $v0, $zero, L_8002D180
    if (ctx->r2 == 0) {
        // 0x8002D12C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002D180;
    }
    // 0x8002D12C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D130: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D134: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8002D138: addiu       $v0, $v1, 0x5
    ctx->r2 = ADD32(ctx->r3, 0X5);
    // 0x8002D13C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D140: sb          $v0, 0x6D68($at)
    MEM_B(0X6D68, ctx->r1) = ctx->r2;
    // 0x8002D144: j           L_8002D1B0
    // 0x8002D148: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_8002D1B0;
    // 0x8002D148: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8002D14C:
    // 0x8002D14C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002D150: lbu         $v1, 0x6D68($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D68);
    // 0x8002D154: beq         $v1, $zero, L_8002D178
    if (ctx->r3 == 0) {
        // 0x8002D158: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002D178;
    }
    // 0x8002D158: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D15C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D160: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8002D164: addiu       $v0, $v1, -0x5
    ctx->r2 = ADD32(ctx->r3, -0X5);
    // 0x8002D168: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D16C: sb          $v0, 0x6D68($at)
    MEM_B(0X6D68, ctx->r1) = ctx->r2;
    // 0x8002D170: j           L_8002D1B0
    // 0x8002D174: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_8002D1B0;
    // 0x8002D174: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8002D178:
    // 0x8002D178: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D17C: sb          $zero, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = 0;
L_8002D180:
    // 0x8002D180: j           L_8002D1B0
    // 0x8002D184: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8002D1B0;
    // 0x8002D184: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002D188:
    // 0x8002D188: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D18C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D190: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8002D194: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002D198: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D19C: sb          $v0, 0x6D68($at)
    MEM_B(0X6D68, ctx->r1) = ctx->r2;
    // 0x8002D1A0: j           L_8002D1B0
    // 0x8002D1A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8002D1B0;
    // 0x8002D1A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002D1A8:
    // 0x8002D1A8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D1AC: sb          $zero, 0x6D68($at)
    MEM_B(0X6D68, ctx->r1) = 0;
L_8002D1B0:
    // 0x8002D1B0: bne         $v1, $zero, L_8002D290
    if (ctx->r3 != 0) {
        // 0x8002D1B4: nop
    
            goto L_8002D290;
    }
    // 0x8002D1B4: nop

    // 0x8002D1B8: sll         $v0, $a1, 24
    ctx->r2 = S32(ctx->r5 << 24);
    // 0x8002D1BC: sra         $v1, $v0, 24
    ctx->r3 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8002D1C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002D1C4: beq         $v1, $v0, L_8002D22C
    if (ctx->r3 == ctx->r2) {
        // 0x8002D1C8: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8002D22C;
    }
    // 0x8002D1C8: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8002D1CC: beql        $v0, $zero, L_8002D1E4
    if (ctx->r2 == 0) {
        // 0x8002D1D0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8002D1E4;
    }
    goto skip_1;
    // 0x8002D1D0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_1:
    // 0x8002D1D4: beq         $v1, $zero, L_8002D1FC
    if (ctx->r3 == 0) {
        // 0x8002D1D8: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8002D1FC;
    }
    // 0x8002D1D8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8002D1DC: j           L_8002D290
    // 0x8002D1E0: nop

        goto L_8002D290;
    // 0x8002D1E0: nop

L_8002D1E4:
    // 0x8002D1E4: beq         $v1, $v0, L_8002D268
    if (ctx->r3 == ctx->r2) {
        // 0x8002D1E8: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002D268;
    }
    // 0x8002D1E8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D1EC: beq         $v1, $v0, L_8002D288
    if (ctx->r3 == ctx->r2) {
        // 0x8002D1F0: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8002D288;
    }
    // 0x8002D1F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002D1F4: j           L_8002D290
    // 0x8002D1F8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_8002D290;
    // 0x8002D1F8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8002D1FC:
    // 0x8002D1FC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002D200: lbu         $v1, 0x6D68($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D68);
    // 0x8002D204: sltiu       $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 < 0XFF ? 1 : 0;
    // 0x8002D208: beq         $v0, $zero, L_8002D260
    if (ctx->r2 == 0) {
        // 0x8002D20C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002D260;
    }
    // 0x8002D20C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D210: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D214: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8002D218: addiu       $v0, $v1, 0x5
    ctx->r2 = ADD32(ctx->r3, 0X5);
    // 0x8002D21C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D220: sb          $v0, 0x6D68($at)
    MEM_B(0X6D68, ctx->r1) = ctx->r2;
    // 0x8002D224: j           L_8002D290
    // 0x8002D228: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_8002D290;
    // 0x8002D228: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8002D22C:
    // 0x8002D22C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002D230: lbu         $v1, 0x6D68($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D68);
    // 0x8002D234: beq         $v1, $zero, L_8002D258
    if (ctx->r3 == 0) {
        // 0x8002D238: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002D258;
    }
    // 0x8002D238: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D23C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D240: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8002D244: addiu       $v0, $v1, -0x5
    ctx->r2 = ADD32(ctx->r3, -0X5);
    // 0x8002D248: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D24C: sb          $v0, 0x6D68($at)
    MEM_B(0X6D68, ctx->r1) = ctx->r2;
    // 0x8002D250: j           L_8002D290
    // 0x8002D254: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_8002D290;
    // 0x8002D254: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8002D258:
    // 0x8002D258: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D25C: sb          $zero, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = 0;
L_8002D260:
    // 0x8002D260: j           L_8002D290
    // 0x8002D264: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8002D290;
    // 0x8002D264: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002D268:
    // 0x8002D268: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D26C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D270: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8002D274: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002D278: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D27C: sb          $v0, 0x6D68($at)
    MEM_B(0X6D68, ctx->r1) = ctx->r2;
    // 0x8002D280: j           L_8002D290
    // 0x8002D284: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8002D290;
    // 0x8002D284: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002D288:
    // 0x8002D288: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D28C: sb          $zero, 0x6D68($at)
    MEM_B(0X6D68, ctx->r1) = 0;
L_8002D290:
    // 0x8002D290: jr          $ra
    // 0x8002D294: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    return;
    // 0x8002D294: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
;}
RECOMP_FUNC void func_8002D298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D298: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x8002D29C: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8002D2A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002D2A4: beq         $a0, $v0, L_8002D30C
    if (ctx->r4 == ctx->r2) {
        // 0x8002D2A8: slti        $v0, $a0, 0x2
        ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
            goto L_8002D30C;
    }
    // 0x8002D2A8: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8002D2AC: beql        $v0, $zero, L_8002D2C4
    if (ctx->r2 == 0) {
        // 0x8002D2B0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8002D2C4;
    }
    goto skip_0;
    // 0x8002D2B0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8002D2B4: beq         $a0, $zero, L_8002D2DC
    if (ctx->r4 == 0) {
        // 0x8002D2B8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8002D2DC;
    }
    // 0x8002D2B8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8002D2BC: j           L_8002D370
    // 0x8002D2C0: nop

        goto L_8002D370;
    // 0x8002D2C0: nop

L_8002D2C4:
    // 0x8002D2C4: beq         $a0, $v0, L_8002D348
    if (ctx->r4 == ctx->r2) {
        // 0x8002D2C8: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002D348;
    }
    // 0x8002D2C8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D2CC: beq         $a0, $v0, L_8002D368
    if (ctx->r4 == ctx->r2) {
        // 0x8002D2D0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002D368;
    }
    // 0x8002D2D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002D2D4: j           L_8002D370
    // 0x8002D2D8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8002D370;
    // 0x8002D2D8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8002D2DC:
    // 0x8002D2DC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002D2E0: lbu         $v1, 0x6D69($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D69);
    // 0x8002D2E4: sltiu       $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 < 0XFF ? 1 : 0;
    // 0x8002D2E8: beq         $v0, $zero, L_8002D340
    if (ctx->r2 == 0) {
        // 0x8002D2EC: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002D340;
    }
    // 0x8002D2EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D2F0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D2F4: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8002D2F8: addiu       $v0, $v1, 0x5
    ctx->r2 = ADD32(ctx->r3, 0X5);
    // 0x8002D2FC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D300: sb          $v0, 0x6D69($at)
    MEM_B(0X6D69, ctx->r1) = ctx->r2;
    // 0x8002D304: j           L_8002D370
    // 0x8002D308: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8002D370;
    // 0x8002D308: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8002D30C:
    // 0x8002D30C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002D310: lbu         $v1, 0x6D69($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D69);
    // 0x8002D314: beq         $v1, $zero, L_8002D338
    if (ctx->r3 == 0) {
        // 0x8002D318: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002D338;
    }
    // 0x8002D318: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D31C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D320: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8002D324: addiu       $v0, $v1, -0x5
    ctx->r2 = ADD32(ctx->r3, -0X5);
    // 0x8002D328: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D32C: sb          $v0, 0x6D69($at)
    MEM_B(0X6D69, ctx->r1) = ctx->r2;
    // 0x8002D330: j           L_8002D370
    // 0x8002D334: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8002D370;
    // 0x8002D334: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8002D338:
    // 0x8002D338: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D33C: sb          $zero, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = 0;
L_8002D340:
    // 0x8002D340: j           L_8002D370
    // 0x8002D344: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002D370;
    // 0x8002D344: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002D348:
    // 0x8002D348: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8002D34C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D350: sb          $v1, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r3;
    // 0x8002D354: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8002D358: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D35C: sb          $v1, 0x6D69($at)
    MEM_B(0X6D69, ctx->r1) = ctx->r3;
    // 0x8002D360: j           L_8002D370
    // 0x8002D364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002D370;
    // 0x8002D364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002D368:
    // 0x8002D368: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D36C: sb          $zero, 0x6D69($at)
    MEM_B(0X6D69, ctx->r1) = 0;
L_8002D370:
    // 0x8002D370: jr          $ra
    // 0x8002D374: nop

    return;
    // 0x8002D374: nop

;}
RECOMP_FUNC void func_8002D378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D378: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8002D37C: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x8002D380: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8002D384: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002D388: beq         $a0, $v0, L_8002D3F0
    if (ctx->r4 == ctx->r2) {
        // 0x8002D38C: slti        $v0, $a0, 0x2
        ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
            goto L_8002D3F0;
    }
    // 0x8002D38C: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8002D390: beql        $v0, $zero, L_8002D3A8
    if (ctx->r2 == 0) {
        // 0x8002D394: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8002D3A8;
    }
    goto skip_0;
    // 0x8002D394: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8002D398: beq         $a0, $zero, L_8002D3C0
    if (ctx->r4 == 0) {
        // 0x8002D39C: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8002D3C0;
    }
    // 0x8002D39C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8002D3A0: j           L_8002D454
    // 0x8002D3A4: nop

        goto L_8002D454;
    // 0x8002D3A4: nop

L_8002D3A8:
    // 0x8002D3A8: beq         $a0, $v0, L_8002D42C
    if (ctx->r4 == ctx->r2) {
        // 0x8002D3AC: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002D42C;
    }
    // 0x8002D3AC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D3B0: beq         $a0, $v0, L_8002D44C
    if (ctx->r4 == ctx->r2) {
        // 0x8002D3B4: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8002D44C;
    }
    // 0x8002D3B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002D3B8: j           L_8002D454
    // 0x8002D3BC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_8002D454;
    // 0x8002D3BC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8002D3C0:
    // 0x8002D3C0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002D3C4: lbu         $v1, 0x6D69($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D69);
    // 0x8002D3C8: sltiu       $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 < 0XFF ? 1 : 0;
    // 0x8002D3CC: beq         $v0, $zero, L_8002D424
    if (ctx->r2 == 0) {
        // 0x8002D3D0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002D424;
    }
    // 0x8002D3D0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D3D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D3D8: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8002D3DC: addiu       $v0, $v1, 0x5
    ctx->r2 = ADD32(ctx->r3, 0X5);
    // 0x8002D3E0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D3E4: sb          $v0, 0x6D69($at)
    MEM_B(0X6D69, ctx->r1) = ctx->r2;
    // 0x8002D3E8: j           L_8002D454
    // 0x8002D3EC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_8002D454;
    // 0x8002D3EC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8002D3F0:
    // 0x8002D3F0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002D3F4: lbu         $v1, 0x6D69($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D69);
    // 0x8002D3F8: beq         $v1, $zero, L_8002D41C
    if (ctx->r3 == 0) {
        // 0x8002D3FC: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002D41C;
    }
    // 0x8002D3FC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D400: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D404: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8002D408: addiu       $v0, $v1, -0x5
    ctx->r2 = ADD32(ctx->r3, -0X5);
    // 0x8002D40C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D410: sb          $v0, 0x6D69($at)
    MEM_B(0X6D69, ctx->r1) = ctx->r2;
    // 0x8002D414: j           L_8002D454
    // 0x8002D418: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_8002D454;
    // 0x8002D418: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8002D41C:
    // 0x8002D41C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D420: sb          $zero, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = 0;
L_8002D424:
    // 0x8002D424: j           L_8002D454
    // 0x8002D428: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8002D454;
    // 0x8002D428: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002D42C:
    // 0x8002D42C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D430: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D434: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8002D438: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002D43C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D440: sb          $v0, 0x6D69($at)
    MEM_B(0X6D69, ctx->r1) = ctx->r2;
    // 0x8002D444: j           L_8002D454
    // 0x8002D448: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8002D454;
    // 0x8002D448: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002D44C:
    // 0x8002D44C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D450: sb          $zero, 0x6D69($at)
    MEM_B(0X6D69, ctx->r1) = 0;
L_8002D454:
    // 0x8002D454: bne         $v1, $zero, L_8002D534
    if (ctx->r3 != 0) {
        // 0x8002D458: nop
    
            goto L_8002D534;
    }
    // 0x8002D458: nop

    // 0x8002D45C: sll         $v0, $a1, 24
    ctx->r2 = S32(ctx->r5 << 24);
    // 0x8002D460: sra         $v1, $v0, 24
    ctx->r3 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8002D464: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002D468: beq         $v1, $v0, L_8002D4D0
    if (ctx->r3 == ctx->r2) {
        // 0x8002D46C: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8002D4D0;
    }
    // 0x8002D46C: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8002D470: beql        $v0, $zero, L_8002D488
    if (ctx->r2 == 0) {
        // 0x8002D474: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8002D488;
    }
    goto skip_1;
    // 0x8002D474: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_1:
    // 0x8002D478: beq         $v1, $zero, L_8002D4A0
    if (ctx->r3 == 0) {
        // 0x8002D47C: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8002D4A0;
    }
    // 0x8002D47C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8002D480: j           L_8002D534
    // 0x8002D484: nop

        goto L_8002D534;
    // 0x8002D484: nop

L_8002D488:
    // 0x8002D488: beq         $v1, $v0, L_8002D50C
    if (ctx->r3 == ctx->r2) {
        // 0x8002D48C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002D50C;
    }
    // 0x8002D48C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D490: beq         $v1, $v0, L_8002D52C
    if (ctx->r3 == ctx->r2) {
        // 0x8002D494: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8002D52C;
    }
    // 0x8002D494: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002D498: j           L_8002D534
    // 0x8002D49C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_8002D534;
    // 0x8002D49C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8002D4A0:
    // 0x8002D4A0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002D4A4: lbu         $v1, 0x6D69($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D69);
    // 0x8002D4A8: sltiu       $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 < 0XFF ? 1 : 0;
    // 0x8002D4AC: beq         $v0, $zero, L_8002D504
    if (ctx->r2 == 0) {
        // 0x8002D4B0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002D504;
    }
    // 0x8002D4B0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D4B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D4B8: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8002D4BC: addiu       $v0, $v1, 0x5
    ctx->r2 = ADD32(ctx->r3, 0X5);
    // 0x8002D4C0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D4C4: sb          $v0, 0x6D69($at)
    MEM_B(0X6D69, ctx->r1) = ctx->r2;
    // 0x8002D4C8: j           L_8002D534
    // 0x8002D4CC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_8002D534;
    // 0x8002D4CC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8002D4D0:
    // 0x8002D4D0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002D4D4: lbu         $v1, 0x6D69($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D69);
    // 0x8002D4D8: beq         $v1, $zero, L_8002D4FC
    if (ctx->r3 == 0) {
        // 0x8002D4DC: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002D4FC;
    }
    // 0x8002D4DC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D4E0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D4E4: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8002D4E8: addiu       $v0, $v1, -0x5
    ctx->r2 = ADD32(ctx->r3, -0X5);
    // 0x8002D4EC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D4F0: sb          $v0, 0x6D69($at)
    MEM_B(0X6D69, ctx->r1) = ctx->r2;
    // 0x8002D4F4: j           L_8002D534
    // 0x8002D4F8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_8002D534;
    // 0x8002D4F8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8002D4FC:
    // 0x8002D4FC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D500: sb          $zero, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = 0;
L_8002D504:
    // 0x8002D504: j           L_8002D534
    // 0x8002D508: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8002D534;
    // 0x8002D508: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002D50C:
    // 0x8002D50C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D510: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D514: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8002D518: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002D51C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D520: sb          $v0, 0x6D69($at)
    MEM_B(0X6D69, ctx->r1) = ctx->r2;
    // 0x8002D524: j           L_8002D534
    // 0x8002D528: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8002D534;
    // 0x8002D528: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002D52C:
    // 0x8002D52C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D530: sb          $zero, 0x6D69($at)
    MEM_B(0X6D69, ctx->r1) = 0;
L_8002D534:
    // 0x8002D534: jr          $ra
    // 0x8002D538: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    return;
    // 0x8002D538: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
;}
RECOMP_FUNC void func_8002D53C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D53C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8002D540: lbu         $a1, 0x6D68($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X6D68);
    // 0x8002D544: beq         $a1, $zero, L_8002D5A4
    if (ctx->r5 == 0) {
        // 0x8002D548: lui         $a0, 0xF650
        ctx->r4 = S32(0XF650 << 16);
            goto L_8002D5A4;
    }
    // 0x8002D548: lui         $a0, 0xF650
    ctx->r4 = S32(0XF650 << 16);
    // 0x8002D54C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002D550: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8002D554: ori         $a0, $a0, 0x3C0
    ctx->r4 = ctx->r4 | 0X3C0;
    // 0x8002D558: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8002D55C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D560: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D564: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x8002D568: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8002D56C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002D570: addiu       $v0, $v0, 0x6D70
    ctx->r2 = ADD32(ctx->r2, 0X6D70);
    // 0x8002D574: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8002D578: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8002D57C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D580: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D584: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x8002D588: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8002D58C: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8002D590: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x8002D594: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D598: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D59C: sw          $a0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r4;
    // 0x8002D5A0: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
L_8002D5A4:
    // 0x8002D5A4: jr          $ra
    // 0x8002D5A8: nop

    return;
    // 0x8002D5A8: nop

;}
RECOMP_FUNC void func_8002D5AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D5AC: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8002D5B0: lbu         $a2, 0x6D69($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X6D69);
    // 0x8002D5B4: beq         $a2, $zero, L_8002D62C
    if (ctx->r6 == 0) {
        // 0x8002D5B8: lui         $a1, 0xF650
        ctx->r5 = S32(0XF650 << 16);
            goto L_8002D62C;
    }
    // 0x8002D5B8: lui         $a1, 0xF650
    ctx->r5 = S32(0XF650 << 16);
    // 0x8002D5BC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8002D5C0: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x8002D5C4: ori         $a1, $a1, 0x3C0
    ctx->r5 = ctx->r5 | 0X3C0;
    // 0x8002D5C8: sll         $v1, $a2, 16
    ctx->r3 = S32(ctx->r6 << 16);
    // 0x8002D5CC: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8002D5D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D5D4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D5D8: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x8002D5DC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8002D5E0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002D5E4: addiu       $v0, $v0, 0x6D70
    ctx->r2 = ADD32(ctx->r2, 0X6D70);
    // 0x8002D5E8: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8002D5EC: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x8002D5F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D5F4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D5F8: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x8002D5FC: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x8002D600: sll         $v0, $a2, 24
    ctx->r2 = S32(ctx->r6 << 24);
    // 0x8002D604: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8002D608: sll         $v1, $a2, 8
    ctx->r3 = S32(ctx->r6 << 8);
    // 0x8002D60C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8002D610: or          $v0, $v0, $a2
    ctx->r2 = ctx->r2 | ctx->r6;
    // 0x8002D614: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x8002D618: addiu       $v0, $a0, 0x18
    ctx->r2 = ADD32(ctx->r4, 0X18);
    // 0x8002D61C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D620: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D624: sw          $a1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r5;
    // 0x8002D628: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
L_8002D62C:
    // 0x8002D62C: jr          $ra
    // 0x8002D630: nop

    return;
    // 0x8002D630: nop

;}
RECOMP_FUNC void func_8002D634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D634: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D638: lwc1        $f2, 0x6D60($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6D60);
    // 0x8002D63C: lui         $at, 0xC340
    ctx->r1 = S32(0XC340 << 16);
    // 0x8002D640: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002D644: nop

    // 0x8002D648: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8002D64C: nop

    // 0x8002D650: bc1t        L_8002DC1C
    if (c1cs) {
        // 0x8002D654: nop
    
            goto L_8002DC1C;
    }
    // 0x8002D654: nop

    // 0x8002D658: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x8002D65C: lw          $a3, 0x2FE4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X2FE4);
    // 0x8002D660: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002D664: nop

    // 0x8002D668: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8002D66C: addiu       $v0, $a3, 0x8
    ctx->r2 = ADD32(ctx->r7, 0X8);
    // 0x8002D670: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D674: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D678: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x8002D67C: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8002D680: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002D684: addiu       $v0, $v0, 0x6DB0
    ctx->r2 = ADD32(ctx->r2, 0X6DB0);
    // 0x8002D688: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x8002D68C: addiu       $v0, $a3, 0x10
    ctx->r2 = ADD32(ctx->r7, 0X10);
    // 0x8002D690: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D694: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D698: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x8002D69C: sw          $v0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r2;
    // 0x8002D6A0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002D6A4: bc1f        L_8002D784
    if (!c1cs) {
        // 0x8002D6A8: sw          $v0, 0xC($a3)
        MEM_W(0XC, ctx->r7) = ctx->r2;
            goto L_8002D784;
    }
    // 0x8002D6A8: sw          $v0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r2;
    // 0x8002D6AC: lui         $v1, 0xF650
    ctx->r3 = S32(0XF650 << 16);
    // 0x8002D6B0: ori         $v1, $v1, 0x3C0
    ctx->r3 = ctx->r3 | 0X3C0;
    // 0x8002D6B4: addiu       $v0, $a3, 0x18
    ctx->r2 = ADD32(ctx->r7, 0X18);
    // 0x8002D6B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D6BC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D6C0: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8002D6C4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8002D6C8: nop

    // 0x8002D6CC: andi        $a1, $a1, 0x3FF
    ctx->r5 = ctx->r5 & 0X3FF;
    // 0x8002D6D0: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x8002D6D4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D6D8: lwc1        $f0, 0x6D58($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6D58);
    // 0x8002D6DC: lui         $a2, 0xF650
    ctx->r6 = S32(0XF650 << 16);
    // 0x8002D6E0: or          $v0, $a1, $a2
    ctx->r2 = ctx->r5 | ctx->r6;
    // 0x8002D6E4: sw          $v0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r2;
    // 0x8002D6E8: addiu       $v0, $a3, 0x20
    ctx->r2 = ADD32(ctx->r7, 0X20);
    // 0x8002D6EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D6F0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D6F4: addiu       $v0, $a3, 0x28
    ctx->r2 = ADD32(ctx->r7, 0X28);
    // 0x8002D6F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D6FC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D700: addiu       $v0, $a3, 0x30
    ctx->r2 = ADD32(ctx->r7, 0X30);
    // 0x8002D704: sw          $zero, 0x14($a3)
    MEM_W(0X14, ctx->r7) = 0;
    // 0x8002D708: sw          $a1, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r5;
    // 0x8002D70C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D710: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D714: sw          $v1, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r3;
    // 0x8002D718: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002D71C: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8002D720: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D724: lwc1        $f0, 0x6D64($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6D64);
    // 0x8002D728: andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
    // 0x8002D72C: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x8002D730: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002D734: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8002D738: nop

    // 0x8002D73C: andi        $a0, $a0, 0x3FF
    ctx->r4 = ctx->r4 & 0X3FF;
    // 0x8002D740: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8002D744: lui         $v0, 0xF600
    ctx->r2 = S32(0XF600 << 16);
    // 0x8002D748: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D74C: lwc1        $f0, 0x6D5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6D5C);
    // 0x8002D750: or          $v0, $a0, $v0
    ctx->r2 = ctx->r4 | ctx->r2;
    // 0x8002D754: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8002D758: or          $a2, $a0, $a2
    ctx->r6 = ctx->r4 | ctx->r6;
    // 0x8002D75C: sw          $v1, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r3;
    // 0x8002D760: sw          $a2, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r6;
    // 0x8002D764: sw          $a0, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r4;
    // 0x8002D768: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002D76C: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002D770: nop

    // 0x8002D774: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x8002D778: sll         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2 << 14);
    // 0x8002D77C: or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // 0x8002D780: sw          $v0, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r2;
L_8002D784:
    // 0x8002D784: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D788: lwc1        $f10, 0x6D5C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6D5C);
    // 0x8002D78C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D790: lwc1        $f14, 0x6D58($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X6D58);
    // 0x8002D794: sub.s       $f0, $f10, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x8002D798: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8002D79C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002D7A0: nop

    // 0x8002D7A4: div.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8002D7A8: c.eq.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl == ctx->f4.fl;
    // 0x8002D7AC: nop

    // 0x8002D7B0: bc1f        L_8002D7C4
    if (!c1cs) {
        // 0x8002D7B4: nop
    
            goto L_8002D7C4;
    }
    // 0x8002D7B4: nop

    // 0x8002D7B8: lui         $at, 0x3586
    ctx->r1 = S32(0X3586 << 16);
    // 0x8002D7BC: ori         $at, $at, 0x37BD
    ctx->r1 = ctx->r1 | 0X37BD;
    // 0x8002D7C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_8002D7C4:
    // 0x8002D7C4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D7C8: lwc1        $f12, 0x6D64($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6D64);
    // 0x8002D7CC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D7D0: lwc1        $f16, 0x6D60($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6D60);
    // 0x8002D7D4: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x8002D7D8: div.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8002D7DC: c.eq.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl == ctx->f4.fl;
    // 0x8002D7E0: nop

    // 0x8002D7E4: nop

    // 0x8002D7E8: bc1f        L_8002D7FC
    if (!c1cs) {
        // 0x8002D7EC: lui         $v1, 0xBA00
        ctx->r3 = S32(0XBA00 << 16);
            goto L_8002D7FC;
    }
    // 0x8002D7EC: lui         $v1, 0xBA00
    ctx->r3 = S32(0XBA00 << 16);
    // 0x8002D7F0: lui         $at, 0x3586
    ctx->r1 = S32(0X3586 << 16);
    // 0x8002D7F4: ori         $at, $at, 0x37BD
    ctx->r1 = ctx->r1 | 0X37BD;
    // 0x8002D7F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_8002D7FC:
    // 0x8002D7FC: ori         $v1, $v1, 0xE02
    ctx->r3 = ctx->r3 | 0XE02;
    // 0x8002D800: lui         $t0, 0xFCFF
    ctx->r8 = S32(0XFCFF << 16);
    // 0x8002D804: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x8002D808: lui         $a2, 0xFFFC
    ctx->r6 = S32(0XFFFC << 16);
    // 0x8002D80C: ori         $a2, $a2, 0xF279
    ctx->r6 = ctx->r6 | 0XF279;
    // 0x8002D810: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x8002D814: ori         $t1, $t1, 0x31D
    ctx->r9 = ctx->r9 | 0X31D;
    // 0x8002D818: lui         $a3, 0x55
    ctx->r7 = S32(0X55 << 16);
    // 0x8002D81C: ori         $a3, $a3, 0x3048
    ctx->r7 = ctx->r7 | 0X3048;
    // 0x8002D820: lui         $t2, 0xF500
    ctx->r10 = S32(0XF500 << 16);
    // 0x8002D824: ori         $t2, $t2, 0x100
    ctx->r10 = ctx->r10 | 0X100;
    // 0x8002D828: lui         $t3, 0x73F
    ctx->r11 = S32(0X73F << 16);
    // 0x8002D82C: ori         $t3, $t3, 0xC000
    ctx->r11 = ctx->r11 | 0XC000;
    // 0x8002D830: lui         $t4, 0x73F
    ctx->r12 = S32(0X73F << 16);
    // 0x8002D834: ori         $t4, $t4, 0xF200
    ctx->r12 = ctx->r12 | 0XF200;
    // 0x8002D838: lui         $t5, 0xF540
    ctx->r13 = S32(0XF540 << 16);
    // 0x8002D83C: ori         $t5, $t5, 0x800
    ctx->r13 = ctx->r13 | 0X800;
    // 0x8002D840: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8002D844: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x8002D848: lui         $t6, 0xF
    ctx->r14 = S32(0XF << 16);
    // 0x8002D84C: ori         $t6, $t6, 0xC0FC
    ctx->r14 = ctx->r14 | 0XC0FC;
    // 0x8002D850: lui         $a1, 0xE700
    ctx->r5 = S32(0XE700 << 16);
    // 0x8002D854: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8002D858: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D85C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D860: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x8002D864: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D868: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D86C: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x8002D870: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x8002D874: addiu       $v0, $a0, 0x18
    ctx->r2 = ADD32(ctx->r4, 0X18);
    // 0x8002D878: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D87C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D880: addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
    // 0x8002D884: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D888: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D88C: addiu       $v0, $a0, 0x28
    ctx->r2 = ADD32(ctx->r4, 0X28);
    // 0x8002D890: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D894: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D898: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x8002D89C: sw          $v0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r2;
    // 0x8002D8A0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002D8A4: addiu       $v0, $v0, 0x6B58
    ctx->r2 = ADD32(ctx->r2, 0X6B58);
    // 0x8002D8A8: sw          $v0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r2;
    // 0x8002D8AC: addiu       $v0, $a0, 0x30
    ctx->r2 = ADD32(ctx->r4, 0X30);
    // 0x8002D8B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D8B4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D8B8: lui         $v0, 0xE800
    ctx->r2 = S32(0XE800 << 16);
    // 0x8002D8BC: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
    // 0x8002D8C0: addiu       $v0, $a0, 0x38
    ctx->r2 = ADD32(ctx->r4, 0X38);
    // 0x8002D8C4: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
    // 0x8002D8C8: lui         $a2, 0x700
    ctx->r6 = S32(0X700 << 16);
    // 0x8002D8CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D8D0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D8D4: addiu       $v0, $a0, 0x40
    ctx->r2 = ADD32(ctx->r4, 0X40);
    // 0x8002D8D8: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    // 0x8002D8DC: lui         $v1, 0xE600
    ctx->r3 = S32(0XE600 << 16);
    // 0x8002D8E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D8E4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D8E8: addiu       $v0, $a0, 0x48
    ctx->r2 = ADD32(ctx->r4, 0X48);
    // 0x8002D8EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D8F0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D8F4: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x8002D8F8: sw          $v0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r2;
    // 0x8002D8FC: addiu       $v0, $a0, 0x50
    ctx->r2 = ADD32(ctx->r4, 0X50);
    // 0x8002D900: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D904: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D908: addiu       $v0, $a0, 0x58
    ctx->r2 = ADD32(ctx->r4, 0X58);
    // 0x8002D90C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D910: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D914: lui         $v0, 0xFD50
    ctx->r2 = S32(0XFD50 << 16);
    // 0x8002D918: sw          $v0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r2;
    // 0x8002D91C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002D920: addiu       $v0, $v0, 0x6148
    ctx->r2 = ADD32(ctx->r2, 0X6148);
    // 0x8002D924: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x8002D928: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8002D92C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    // 0x8002D930: sw          $t1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r9;
    // 0x8002D934: sw          $a3, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r7;
    // 0x8002D938: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x8002D93C: sw          $t2, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r10;
    // 0x8002D940: sw          $a2, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r6;
    // 0x8002D944: sw          $v1, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r3;
    // 0x8002D948: sw          $zero, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = 0;
    // 0x8002D94C: sw          $t3, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r11;
    // 0x8002D950: sw          $a1, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r5;
    // 0x8002D954: sw          $zero, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = 0;
    // 0x8002D958: sw          $v0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r2;
    // 0x8002D95C: addiu       $v0, $a0, 0x60
    ctx->r2 = ADD32(ctx->r4, 0X60);
    // 0x8002D960: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D964: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D968: lui         $v0, 0xF550
    ctx->r2 = S32(0XF550 << 16);
    // 0x8002D96C: sw          $v0, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r2;
    // 0x8002D970: addiu       $v0, $a0, 0x68
    ctx->r2 = ADD32(ctx->r4, 0X68);
    // 0x8002D974: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D978: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D97C: addiu       $v0, $a0, 0x70
    ctx->r2 = ADD32(ctx->r4, 0X70);
    // 0x8002D980: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D984: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D988: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x8002D98C: sw          $v0, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r2;
    // 0x8002D990: addiu       $v0, $a0, 0x78
    ctx->r2 = ADD32(ctx->r4, 0X78);
    // 0x8002D994: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D998: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D99C: addiu       $v0, $a0, 0x80
    ctx->r2 = ADD32(ctx->r4, 0X80);
    // 0x8002D9A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D9A4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D9A8: addiu       $v0, $a0, 0x88
    ctx->r2 = ADD32(ctx->r4, 0X88);
    // 0x8002D9AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002D9B0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002D9B4: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x8002D9B8: sw          $a2, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r6;
    // 0x8002D9BC: addiu       $a2, $a0, 0x90
    ctx->r6 = ADD32(ctx->r4, 0X90);
    // 0x8002D9C0: sw          $v1, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->r3;
    // 0x8002D9C4: sw          $v0, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->r2;
    // 0x8002D9C8: trunc.w.s   $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8002D9CC: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8002D9D0: sw          $a1, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r5;
    // 0x8002D9D4: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x8002D9D8: sll         $v0, $v0, 18
    ctx->r2 = S32(ctx->r2 << 18);
    // 0x8002D9DC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002D9E0: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x8002D9E4: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8002D9E8: and         $a1, $a1, $v0
    ctx->r5 = ctx->r5 & ctx->r2;
    // 0x8002D9EC: andi        $a1, $a1, 0xFFC
    ctx->r5 = ctx->r5 & 0XFFC;
    // 0x8002D9F0: sll         $a1, $a1, 12
    ctx->r5 = S32(ctx->r5 << 12);
    // 0x8002D9F4: trunc.w.s   $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8002D9F8: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8002D9FC: nop

    // 0x8002DA00: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8002DA04: sll         $v0, $v0, 18
    ctx->r2 = S32(ctx->r2 << 18);
    // 0x8002DA08: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002DA0C: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x8002DA10: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8002DA14: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8002DA18: andi        $v1, $v1, 0xFFC
    ctx->r3 = ctx->r3 & 0XFFC;
    // 0x8002DA1C: lui         $v0, 0xE400
    ctx->r2 = S32(0XE400 << 16);
    // 0x8002DA20: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8002DA24: or          $a1, $a1, $v1
    ctx->r5 = ctx->r5 | ctx->r3;
    // 0x8002DA28: trunc.w.s   $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8002DA2C: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8002DA30: nop

    // 0x8002DA34: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8002DA38: sll         $v0, $v0, 18
    ctx->r2 = S32(ctx->r2 << 18);
    // 0x8002DA3C: sra         $a3, $v0, 16
    ctx->r7 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002DA40: nor         $v0, $zero, $a3
    ctx->r2 = ~(0 | ctx->r7);
    // 0x8002DA44: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8002DA48: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8002DA4C: andi        $v1, $v1, 0xFFC
    ctx->r3 = ctx->r3 & 0XFFC;
    // 0x8002DA50: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x8002DA54: sw          $a1, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r5;
    // 0x8002DA58: trunc.w.s   $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8002DA5C: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8002DA60: nop

    // 0x8002DA64: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x8002DA68: sll         $v0, $v0, 18
    ctx->r2 = S32(ctx->r2 << 18);
    // 0x8002DA6C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002DA70: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x8002DA74: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8002DA78: and         $a1, $a1, $v0
    ctx->r5 = ctx->r5 & ctx->r2;
    // 0x8002DA7C: andi        $a1, $a1, 0xFFC
    ctx->r5 = ctx->r5 & 0XFFC;
    // 0x8002DA80: or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
    // 0x8002DA84: addiu       $v0, $a0, 0x98
    ctx->r2 = ADD32(ctx->r4, 0X98);
    // 0x8002DA88: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002DA8C: sw          $a2, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r6;
    // 0x8002DA90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002DA94: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002DA98: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x8002DA9C: sw          $zero, 0x64($a0)
    MEM_W(0X64, ctx->r4) = 0;
    // 0x8002DAA0: sw          $t4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r12;
    // 0x8002DAA4: sw          $zero, 0x74($a0)
    MEM_W(0X74, ctx->r4) = 0;
    // 0x8002DAA8: sw          $t5, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r13;
    // 0x8002DAAC: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x8002DAB0: sw          $t6, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r14;
    // 0x8002DAB4: sw          $v1, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->r3;
    // 0x8002DAB8: bgez        $a3, L_8002DB2C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8002DABC: sw          $v0, 0x90($a0)
        MEM_W(0X90, ctx->r4) = ctx->r2;
            goto L_8002DB2C;
    }
    // 0x8002DABC: sw          $v0, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->r2;
    // 0x8002DAC0: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8002DAC4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002DAC8: nop

    // 0x8002DACC: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8002DAD0: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002DAD4: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002DAD8: nop

    // 0x8002DADC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002DAE0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002DAE4: bgez        $v0, L_8002DB04
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002DAE8: nop
    
            goto L_8002DB04;
    }
    // 0x8002DAE8: nop

    // 0x8002DAEC: mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002DAF0: mflo        $v0
    ctx->r2 = lo;
    // 0x8002DAF4: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8002DAF8: nor         $v1, $zero, $v0
    ctx->r3 = ~(0 | ctx->r2);
    // 0x8002DAFC: j           L_8002DB1C
    // 0x8002DB00: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
        goto L_8002DB1C;
    // 0x8002DB00: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
L_8002DB04:
    // 0x8002DB04: nop

    // 0x8002DB08: mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002DB0C: mflo        $v0
    ctx->r2 = lo;
    // 0x8002DB10: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8002DB14: slti        $v1, $v0, 0x1
    ctx->r3 = SIGNED(ctx->r2) < 0X1 ? 1 : 0;
    // 0x8002DB18: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_8002DB1C:
    // 0x8002DB1C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8002DB20: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8002DB24: j           L_8002DB30
    // 0x8002DB28: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
        goto L_8002DB30;
    // 0x8002DB28: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
L_8002DB2C:
    // 0x8002DB2C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8002DB30:
    // 0x8002DB30: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002DB34: lwc1        $f0, 0x6D60($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6D60);
    // 0x8002DB38: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002DB3C: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8002DB40: nop

    // 0x8002DB44: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8002DB48: bgez        $v0, L_8002DBC0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002DB4C: addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
            goto L_8002DBC0;
    }
    // 0x8002DB4C: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x8002DB50: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8002DB54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002DB58: nop

    // 0x8002DB5C: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8002DB60: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002DB64: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002DB68: nop

    // 0x8002DB6C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002DB70: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002DB74: bgez        $v1, L_8002DB98
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002DB78: sll         $v0, $a0, 18
        ctx->r2 = S32(ctx->r4 << 18);
            goto L_8002DB98;
    }
    // 0x8002DB78: sll         $v0, $a0, 18
    ctx->r2 = S32(ctx->r4 << 18);
    // 0x8002DB7C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002DB80: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002DB84: mflo        $v0
    ctx->r2 = lo;
    // 0x8002DB88: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8002DB8C: nor         $v1, $zero, $v0
    ctx->r3 = ~(0 | ctx->r2);
    // 0x8002DB90: j           L_8002DBB0
    // 0x8002DB94: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
        goto L_8002DBB0;
    // 0x8002DB94: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
L_8002DB98:
    // 0x8002DB98: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002DB9C: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002DBA0: mflo        $v0
    ctx->r2 = lo;
    // 0x8002DBA4: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x8002DBA8: slti        $v1, $v0, 0x1
    ctx->r3 = SIGNED(ctx->r2) < 0X1 ? 1 : 0;
    // 0x8002DBAC: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_8002DBB0:
    // 0x8002DBB0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8002DBB4: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8002DBB8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8002DBBC: or          $v0, $a1, $v0
    ctx->r2 = ctx->r5 | ctx->r2;
L_8002DBC0:
    // 0x8002DBC0: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8002DBC4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002DBC8: nop

    // 0x8002DBCC: div.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8002DBD0: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8002DBD4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8002DBD8: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x8002DBDC: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x8002DBE0: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8002DBE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002DBE8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002DBEC: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x8002DBF0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8002DBF4: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8002DBF8: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8002DBFC: nop

    // 0x8002DC00: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8002DC04: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002DC08: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002DC0C: nop

    // 0x8002DC10: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8002DC14: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8002DC18: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
L_8002DC1C:
    // 0x8002DC1C: jr          $ra
    // 0x8002DC20: nop

    return;
    // 0x8002DC20: nop

;}
RECOMP_FUNC void func_8002DC24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DC24: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002DC28: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x8002DC2C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8002DC30: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8002DC34: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8002DC38: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8002DC3C: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x8002DC40: beq         $v0, $zero, L_8002DCAC
    if (ctx->r2 == 0) {
        // 0x8002DC44: sw          $s0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r16;
            goto L_8002DCAC;
    }
    // 0x8002DC44: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8002DC48: addiu       $v0, $zero, -0x20
    ctx->r2 = ADD32(0, -0X20);
    // 0x8002DC4C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002DC50: sw          $v0, 0x6E70($at)
    MEM_W(0X6E70, ctx->r1) = ctx->r2;
    // 0x8002DC54: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002DC58: sw          $v0, 0x6E6C($at)
    MEM_W(0X6E6C, ctx->r1) = ctx->r2;
    // 0x8002DC5C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002DC60: sw          $v0, 0x6E68($at)
    MEM_W(0X6E68, ctx->r1) = ctx->r2;
    // 0x8002DC64: addiu       $v0, $zero, 0x160
    ctx->r2 = ADD32(0, 0X160);
    // 0x8002DC68: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002DC6C: sb          $zero, 0x49B1($at)
    MEM_B(0X49B1, ctx->r1) = 0;
    // 0x8002DC70: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002DC74: sb          $zero, 0x49B0($at)
    MEM_B(0X49B0, ctx->r1) = 0;
    // 0x8002DC78: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002DC7C: sw          $v0, 0x6E7C($at)
    MEM_W(0X6E7C, ctx->r1) = ctx->r2;
    // 0x8002DC80: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002DC84: sw          $v0, 0x6E78($at)
    MEM_W(0X6E78, ctx->r1) = ctx->r2;
    // 0x8002DC88: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002DC8C: sw          $v0, 0x6E74($at)
    MEM_W(0X6E74, ctx->r1) = ctx->r2;
    // 0x8002DC90: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002DC94: sb          $zero, 0x49B3($at)
    MEM_B(0X49B3, ctx->r1) = 0;
    // 0x8002DC98: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002DC9C: sb          $zero, 0x49B2($at)
    MEM_B(0X49B2, ctx->r1) = 0;
    // 0x8002DCA0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002DCA4: j           L_8002E640
    // 0x8002DCA8: sb          $zero, 0x49B4($at)
    MEM_B(0X49B4, ctx->r1) = 0;
        goto L_8002E640;
    // 0x8002DCA8: sb          $zero, 0x49B4($at)
    MEM_B(0X49B4, ctx->r1) = 0;
L_8002DCAC:
    // 0x8002DCAC: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8002DCB0: addiu       $v1, $v1, 0x49B0
    ctx->r3 = ADD32(ctx->r3, 0X49B0);
    // 0x8002DCB4: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8002DCB8: slti        $v0, $v0, 0x64
    ctx->r2 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8002DCBC: bne         $v0, $zero, L_8002DCC8
    if (ctx->r2 != 0) {
        // 0x8002DCC0: addiu       $v0, $zero, 0x63
        ctx->r2 = ADD32(0, 0X63);
            goto L_8002DCC8;
    }
    // 0x8002DCC0: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x8002DCC4: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8002DCC8:
    // 0x8002DCC8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002DCCC: lb          $v0, 0x49B1($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X49B1);
    // 0x8002DCD0: slti        $v0, $v0, 0x64
    ctx->r2 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x8002DCD4: bne         $v0, $zero, L_8002DCE4
    if (ctx->r2 != 0) {
        // 0x8002DCD8: addiu       $v0, $zero, 0x63
        ctx->r2 = ADD32(0, 0X63);
            goto L_8002DCE4;
    }
    // 0x8002DCD8: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x8002DCDC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002DCE0: sb          $v0, 0x49B1($at)
    MEM_B(0X49B1, ctx->r1) = ctx->r2;
L_8002DCE4:
    // 0x8002DCE4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002DCE8: lbu         $v0, 0x2074($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2074);
    // 0x8002DCEC: beq         $v0, $zero, L_8002E640
    if (ctx->r2 == 0) {
        // 0x8002DCF0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002E640;
    }
    // 0x8002DCF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002DCF4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8002DCF8: lbu         $v1, 0x7B9C($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B9C);
    // 0x8002DCFC: bne         $v1, $v0, L_8002DD2C
    if (ctx->r3 != ctx->r2) {
        // 0x8002DD00: nop
    
            goto L_8002DD2C;
    }
    // 0x8002DD00: nop

    // 0x8002DD04: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002DD08: lb          $v0, 0x25A5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A5);
    // 0x8002DD0C: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x8002DD10: beq         $v0, $zero, L_8002DD2C
    if (ctx->r2 == 0) {
        // 0x8002DD14: nop
    
            goto L_8002DD2C;
    }
    // 0x8002DD14: nop

    // 0x8002DD18: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002DD1C: lb          $v0, 0x79F5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F5);
    // 0x8002DD20: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x8002DD24: bne         $v0, $zero, L_8002E640
    if (ctx->r2 != 0) {
        // 0x8002DD28: nop
    
            goto L_8002E640;
    }
    // 0x8002DD28: nop

L_8002DD2C:
    // 0x8002DD2C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8002DD30: lbu         $a0, 0x2612($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X2612);
    // 0x8002DD34: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8002DD38: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x8002DD3C: bne         $v0, $zero, L_8002DDFC
    if (ctx->r2 != 0) {
        // 0x8002DD40: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8002DDFC;
    }
    // 0x8002DD40: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8002DD44: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8002DD48: addiu       $a1, $a1, 0x49B0
    ctx->r5 = ADD32(ctx->r5, 0X49B0);
    // 0x8002DD4C: lb          $v0, 0x0($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X0);
    // 0x8002DD50: beq         $v0, $v1, L_8002DD84
    if (ctx->r2 == ctx->r3) {
        // 0x8002DD54: addiu       $v1, $zero, -0x20
        ctx->r3 = ADD32(0, -0X20);
            goto L_8002DD84;
    }
    // 0x8002DD54: addiu       $v1, $zero, -0x20
    ctx->r3 = ADD32(0, -0X20);
    // 0x8002DD58: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002DD5C: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x8002DD60: sb          $a0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r4;
    // 0x8002DD64: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002DD68: sw          $v1, 0x6E6C($at)
    MEM_W(0X6E6C, ctx->r1) = ctx->r3;
    // 0x8002DD6C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8002DD70: bne         $v0, $v1, L_8002DD84
    if (ctx->r2 != ctx->r3) {
        // 0x8002DD74: addiu       $a0, $zero, 0x1D
        ctx->r4 = ADD32(0, 0X1D);
            goto L_8002DD84;
    }
    // 0x8002DD74: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x8002DD78: jal         0x8000637C
    // 0x8002DD7C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8000637C(rdram, ctx);
        goto after_0;
    // 0x8002DD7C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8002DD80: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8002DD84:
    // 0x8002DD84: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8002DD88: addiu       $t1, $t1, 0x6E68
    ctx->r9 = ADD32(ctx->r9, 0X6E68);
    // 0x8002DD8C: addiu       $a3, $zero, 0x89
    ctx->r7 = ADD32(0, 0X89);
    // 0x8002DD90: lui         $t0, 0x6666
    ctx->r8 = S32(0X6666 << 16);
    // 0x8002DD94: ori         $t0, $t0, 0x6667
    ctx->r8 = ctx->r8 | 0X6667;
    // 0x8002DD98: sll         $v0, $a2, 24
    ctx->r2 = S32(ctx->r6 << 24);
L_8002DD9C:
    // 0x8002DD9C: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8002DDA0: addu        $a0, $v0, $t1
    ctx->r4 = ADD32(ctx->r2, ctx->r9);
    // 0x8002DDA4: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8002DDA8: subu        $s1, $a3, $a1
    ctx->r17 = SUB32(ctx->r7, ctx->r5);
    // 0x8002DDAC: mult        $s1, $t0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002DDB0: sra         $v0, $s1, 31
    ctx->r2 = S32(SIGNED(ctx->r17) >> 31);
    // 0x8002DDB4: mfhi        $t2
    ctx->r10 = hi;
    // 0x8002DDB8: sra         $v1, $t2, 1
    ctx->r3 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8002DDBC: subu        $s1, $v1, $v0
    ctx->r17 = SUB32(ctx->r3, ctx->r2);
    // 0x8002DDC0: beq         $s1, $zero, L_8002DDD0
    if (ctx->r17 == 0) {
        // 0x8002DDC4: addu        $v0, $a1, $s1
        ctx->r2 = ADD32(ctx->r5, ctx->r17);
            goto L_8002DDD0;
    }
    // 0x8002DDC4: addu        $v0, $a1, $s1
    ctx->r2 = ADD32(ctx->r5, ctx->r17);
    // 0x8002DDC8: j           L_8002DDD4
    // 0x8002DDCC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_8002DDD4;
    // 0x8002DDCC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_8002DDD0:
    // 0x8002DDD0: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
L_8002DDD4:
    // 0x8002DDD4: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x8002DDD8: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8002DDDC: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8002DDE0: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8002DDE4: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8002DDE8: bne         $v0, $zero, L_8002DD9C
    if (ctx->r2 != 0) {
        // 0x8002DDEC: sll         $v0, $a2, 24
        ctx->r2 = S32(ctx->r6 << 24);
            goto L_8002DD9C;
    }
    // 0x8002DDEC: sll         $v0, $a2, 24
    ctx->r2 = S32(ctx->r6 << 24);
    // 0x8002DDF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002DDF4: j           L_8002DF54
    // 0x8002DDF8: sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
        goto L_8002DF54;
    // 0x8002DDF8: sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
L_8002DDFC:
    // 0x8002DDFC: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8002DE00: addiu       $t1, $t1, 0x6E68
    ctx->r9 = ADD32(ctx->r9, 0X6E68);
    // 0x8002DE04: lui         $a3, 0x6666
    ctx->r7 = S32(0X6666 << 16);
    // 0x8002DE08: ori         $a3, $a3, 0x6667
    ctx->r7 = ctx->r7 | 0X6667;
    // 0x8002DE0C: addiu       $t0, $zero, -0x20
    ctx->r8 = ADD32(0, -0X20);
    // 0x8002DE10: sll         $v0, $a2, 24
    ctx->r2 = S32(ctx->r6 << 24);
L_8002DE14:
    // 0x8002DE14: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8002DE18: addu        $a0, $v0, $t1
    ctx->r4 = ADD32(ctx->r2, ctx->r9);
    // 0x8002DE1C: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8002DE20: addiu       $s1, $a1, 0x20
    ctx->r17 = ADD32(ctx->r5, 0X20);
    // 0x8002DE24: mult        $s1, $a3
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002DE28: sra         $v0, $s1, 31
    ctx->r2 = S32(SIGNED(ctx->r17) >> 31);
    // 0x8002DE2C: mfhi        $t2
    ctx->r10 = hi;
    // 0x8002DE30: sra         $v1, $t2, 1
    ctx->r3 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8002DE34: subu        $s1, $v1, $v0
    ctx->r17 = SUB32(ctx->r3, ctx->r2);
    // 0x8002DE38: beq         $s1, $zero, L_8002DE48
    if (ctx->r17 == 0) {
        // 0x8002DE3C: subu        $v0, $a1, $s1
        ctx->r2 = SUB32(ctx->r5, ctx->r17);
            goto L_8002DE48;
    }
    // 0x8002DE3C: subu        $v0, $a1, $s1
    ctx->r2 = SUB32(ctx->r5, ctx->r17);
    // 0x8002DE40: j           L_8002DE4C
    // 0x8002DE44: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_8002DE4C;
    // 0x8002DE44: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_8002DE48:
    // 0x8002DE48: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
L_8002DE4C:
    // 0x8002DE4C: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x8002DE50: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8002DE54: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8002DE58: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8002DE5C: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8002DE60: bne         $v0, $zero, L_8002DE14
    if (ctx->r2 != 0) {
        // 0x8002DE64: sll         $v0, $a2, 24
        ctx->r2 = S32(ctx->r6 << 24);
            goto L_8002DE14;
    }
    // 0x8002DE64: sll         $v0, $a2, 24
    ctx->r2 = S32(ctx->r6 << 24);
    // 0x8002DE68: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8002DE6C: addiu       $a2, $a2, 0x49B0
    ctx->r6 = ADD32(ctx->r6, 0X49B0);
    // 0x8002DE70: lb          $v0, 0x0($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X0);
    // 0x8002DE74: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8002DE78: bne         $v0, $zero, L_8002DF54
    if (ctx->r2 != 0) {
        // 0x8002DE7C: sb          $zero, 0x10($sp)
        MEM_B(0X10, ctx->r29) = 0;
            goto L_8002DF54;
    }
    // 0x8002DE7C: sb          $zero, 0x10($sp)
    MEM_B(0X10, ctx->r29) = 0;
    // 0x8002DE80: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8002DE84: addiu       $a1, $a1, 0x6E70
    ctx->r5 = ADD32(ctx->r5, 0X6E70);
    // 0x8002DE88: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8002DE8C: slti        $v0, $a0, 0x89
    ctx->r2 = SIGNED(ctx->r4) < 0X89 ? 1 : 0;
    // 0x8002DE90: beq         $v0, $zero, L_8002DF08
    if (ctx->r2 == 0) {
        // 0x8002DE94: lui         $v0, 0x6666
        ctx->r2 = S32(0X6666 << 16);
            goto L_8002DF08;
    }
    // 0x8002DE94: lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // 0x8002DE98: addiu       $a2, $zero, 0x89
    ctx->r6 = ADD32(0, 0X89);
    // 0x8002DE9C: subu        $s1, $a2, $a0
    ctx->r17 = SUB32(ctx->r6, ctx->r4);
    // 0x8002DEA0: ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // 0x8002DEA4: mult        $s1, $v0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002DEA8: sra         $v0, $s1, 31
    ctx->r2 = S32(SIGNED(ctx->r17) >> 31);
    // 0x8002DEAC: mfhi        $t2
    ctx->r10 = hi;
    // 0x8002DEB0: sra         $v1, $t2, 1
    ctx->r3 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8002DEB4: subu        $s1, $v1, $v0
    ctx->r17 = SUB32(ctx->r3, ctx->r2);
    // 0x8002DEB8: beq         $s1, $zero, L_8002DEC8
    if (ctx->r17 == 0) {
        // 0x8002DEBC: addu        $v0, $a0, $s1
        ctx->r2 = ADD32(ctx->r4, ctx->r17);
            goto L_8002DEC8;
    }
    // 0x8002DEBC: addu        $v0, $a0, $s1
    ctx->r2 = ADD32(ctx->r4, ctx->r17);
    // 0x8002DEC0: j           L_8002DED4
    // 0x8002DEC4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_8002DED4;
    // 0x8002DEC4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_8002DEC8:
    // 0x8002DEC8: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x8002DECC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002DED0: sb          $zero, 0x49B2($at)
    MEM_B(0X49B2, ctx->r1) = 0;
L_8002DED4:
    // 0x8002DED4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002DED8: lbu         $v0, 0x49B4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X49B4);
    // 0x8002DEDC: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8002DEE0: bne         $v0, $zero, L_8002DF60
    if (ctx->r2 != 0) {
        // 0x8002DEE4: addiu       $a0, $zero, 0x27
        ctx->r4 = ADD32(0, 0X27);
            goto L_8002DF60;
    }
    // 0x8002DEE4: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x8002DEE8: jal         0x8000637C
    // 0x8002DEEC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8000637C(rdram, ctx);
        goto after_1;
    // 0x8002DEEC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x8002DEF0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002DEF4: lbu         $v0, 0x49B4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X49B4);
    // 0x8002DEF8: ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // 0x8002DEFC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002DF00: j           L_8002DF60
    // 0x8002DF04: sb          $v0, 0x49B4($at)
    MEM_B(0X49B4, ctx->r1) = ctx->r2;
        goto L_8002DF60;
    // 0x8002DF04: sb          $v0, 0x49B4($at)
    MEM_B(0X49B4, ctx->r1) = ctx->r2;
L_8002DF08:
    // 0x8002DF08: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8002DF0C: addiu       $a0, $a0, 0x49B2
    ctx->r4 = ADD32(ctx->r4, 0X49B2);
    // 0x8002DF10: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8002DF14: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8002DF18: slti        $v0, $v0, 0x3C
    ctx->r2 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // 0x8002DF1C: beq         $v0, $zero, L_8002DF2C
    if (ctx->r2 == 0) {
        // 0x8002DF20: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8002DF2C;
    }
    // 0x8002DF20: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8002DF24: j           L_8002DF60
    // 0x8002DF28: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
        goto L_8002DF60;
    // 0x8002DF28: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_8002DF2C:
    // 0x8002DF2C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8002DF30: lbu         $v1, 0x49B4($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X49B4);
    // 0x8002DF34: addiu       $v0, $zero, -0x20
    ctx->r2 = ADD32(0, -0X20);
    // 0x8002DF38: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x8002DF3C: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x8002DF40: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8002DF44: andi        $v1, $v1, 0xF
    ctx->r3 = ctx->r3 & 0XF;
    // 0x8002DF48: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002DF4C: j           L_8002DF60
    // 0x8002DF50: sb          $v1, 0x49B4($at)
    MEM_B(0X49B4, ctx->r1) = ctx->r3;
        goto L_8002DF60;
    // 0x8002DF50: sb          $v1, 0x49B4($at)
    MEM_B(0X49B4, ctx->r1) = ctx->r3;
L_8002DF54:
    // 0x8002DF54: addiu       $v0, $zero, -0x20
    ctx->r2 = ADD32(0, -0X20);
    // 0x8002DF58: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002DF5C: sw          $v0, 0x6E70($at)
    MEM_W(0X6E70, ctx->r1) = ctx->r2;
L_8002DF60:
    // 0x8002DF60: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8002DF64: lbu         $a0, 0x7A62($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7A62);
    // 0x8002DF68: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8002DF6C: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x8002DF70: bne         $v0, $zero, L_8002E030
    if (ctx->r2 != 0) {
        // 0x8002DF74: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_8002E030;
    }
    // 0x8002DF74: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8002DF78: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8002DF7C: addiu       $a1, $a1, 0x49B1
    ctx->r5 = ADD32(ctx->r5, 0X49B1);
    // 0x8002DF80: lb          $v0, 0x0($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X0);
    // 0x8002DF84: beq         $v0, $v1, L_8002DFB8
    if (ctx->r2 == ctx->r3) {
        // 0x8002DF88: addiu       $v1, $zero, 0x160
        ctx->r3 = ADD32(0, 0X160);
            goto L_8002DFB8;
    }
    // 0x8002DF88: addiu       $v1, $zero, 0x160
    ctx->r3 = ADD32(0, 0X160);
    // 0x8002DF8C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002DF90: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x8002DF94: sb          $a0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r4;
    // 0x8002DF98: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002DF9C: sw          $v1, 0x6E78($at)
    MEM_W(0X6E78, ctx->r1) = ctx->r3;
    // 0x8002DFA0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8002DFA4: bne         $v0, $v1, L_8002DFB8
    if (ctx->r2 != ctx->r3) {
        // 0x8002DFA8: addiu       $a0, $zero, 0x1D
        ctx->r4 = ADD32(0, 0X1D);
            goto L_8002DFB8;
    }
    // 0x8002DFA8: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x8002DFAC: jal         0x8000637C
    // 0x8002DFB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8000637C(rdram, ctx);
        goto after_2;
    // 0x8002DFB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8002DFB4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_8002DFB8:
    // 0x8002DFB8: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8002DFBC: addiu       $t1, $t1, 0x6E68
    ctx->r9 = ADD32(ctx->r9, 0X6E68);
    // 0x8002DFC0: lui         $a3, 0x6666
    ctx->r7 = S32(0X6666 << 16);
    // 0x8002DFC4: ori         $a3, $a3, 0x6667
    ctx->r7 = ctx->r7 | 0X6667;
    // 0x8002DFC8: addiu       $t0, $zero, 0xB6
    ctx->r8 = ADD32(0, 0XB6);
    // 0x8002DFCC: sll         $v0, $a2, 24
    ctx->r2 = S32(ctx->r6 << 24);
L_8002DFD0:
    // 0x8002DFD0: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8002DFD4: addu        $a0, $v0, $t1
    ctx->r4 = ADD32(ctx->r2, ctx->r9);
    // 0x8002DFD8: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8002DFDC: addiu       $s1, $a1, -0xB6
    ctx->r17 = ADD32(ctx->r5, -0XB6);
    // 0x8002DFE0: mult        $s1, $a3
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002DFE4: sra         $v0, $s1, 31
    ctx->r2 = S32(SIGNED(ctx->r17) >> 31);
    // 0x8002DFE8: mfhi        $t2
    ctx->r10 = hi;
    // 0x8002DFEC: sra         $v1, $t2, 1
    ctx->r3 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8002DFF0: subu        $s1, $v1, $v0
    ctx->r17 = SUB32(ctx->r3, ctx->r2);
    // 0x8002DFF4: beq         $s1, $zero, L_8002E004
    if (ctx->r17 == 0) {
        // 0x8002DFF8: subu        $v0, $a1, $s1
        ctx->r2 = SUB32(ctx->r5, ctx->r17);
            goto L_8002E004;
    }
    // 0x8002DFF8: subu        $v0, $a1, $s1
    ctx->r2 = SUB32(ctx->r5, ctx->r17);
    // 0x8002DFFC: j           L_8002E008
    // 0x8002E000: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_8002E008;
    // 0x8002E000: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_8002E004:
    // 0x8002E004: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
L_8002E008:
    // 0x8002E008: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x8002E00C: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8002E010: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8002E014: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8002E018: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8002E01C: bne         $v0, $zero, L_8002DFD0
    if (ctx->r2 != 0) {
        // 0x8002E020: sll         $v0, $a2, 24
        ctx->r2 = S32(ctx->r6 << 24);
            goto L_8002DFD0;
    }
    // 0x8002E020: sll         $v0, $a2, 24
    ctx->r2 = S32(ctx->r6 << 24);
    // 0x8002E024: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002E028: j           L_8002E188
    // 0x8002E02C: sb          $v0, 0x11($sp)
    MEM_B(0X11, ctx->r29) = ctx->r2;
        goto L_8002E188;
    // 0x8002E02C: sb          $v0, 0x11($sp)
    MEM_B(0X11, ctx->r29) = ctx->r2;
L_8002E030:
    // 0x8002E030: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8002E034: addiu       $t1, $t1, 0x6E68
    ctx->r9 = ADD32(ctx->r9, 0X6E68);
    // 0x8002E038: addiu       $a3, $zero, 0x160
    ctx->r7 = ADD32(0, 0X160);
    // 0x8002E03C: lui         $t0, 0x6666
    ctx->r8 = S32(0X6666 << 16);
    // 0x8002E040: ori         $t0, $t0, 0x6667
    ctx->r8 = ctx->r8 | 0X6667;
    // 0x8002E044: sll         $v0, $a2, 24
    ctx->r2 = S32(ctx->r6 << 24);
L_8002E048:
    // 0x8002E048: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8002E04C: addu        $a0, $v0, $t1
    ctx->r4 = ADD32(ctx->r2, ctx->r9);
    // 0x8002E050: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8002E054: subu        $s1, $a3, $a1
    ctx->r17 = SUB32(ctx->r7, ctx->r5);
    // 0x8002E058: mult        $s1, $t0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E05C: sra         $v0, $s1, 31
    ctx->r2 = S32(SIGNED(ctx->r17) >> 31);
    // 0x8002E060: mfhi        $t2
    ctx->r10 = hi;
    // 0x8002E064: sra         $v1, $t2, 1
    ctx->r3 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8002E068: subu        $s1, $v1, $v0
    ctx->r17 = SUB32(ctx->r3, ctx->r2);
    // 0x8002E06C: beq         $s1, $zero, L_8002E07C
    if (ctx->r17 == 0) {
        // 0x8002E070: addu        $v0, $a1, $s1
        ctx->r2 = ADD32(ctx->r5, ctx->r17);
            goto L_8002E07C;
    }
    // 0x8002E070: addu        $v0, $a1, $s1
    ctx->r2 = ADD32(ctx->r5, ctx->r17);
    // 0x8002E074: j           L_8002E080
    // 0x8002E078: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_8002E080;
    // 0x8002E078: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_8002E07C:
    // 0x8002E07C: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
L_8002E080:
    // 0x8002E080: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x8002E084: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8002E088: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8002E08C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8002E090: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8002E094: bne         $v0, $zero, L_8002E048
    if (ctx->r2 != 0) {
        // 0x8002E098: sll         $v0, $a2, 24
        ctx->r2 = S32(ctx->r6 << 24);
            goto L_8002E048;
    }
    // 0x8002E098: sll         $v0, $a2, 24
    ctx->r2 = S32(ctx->r6 << 24);
    // 0x8002E09C: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8002E0A0: addiu       $a2, $a2, 0x49B1
    ctx->r6 = ADD32(ctx->r6, 0X49B1);
    // 0x8002E0A4: lb          $v0, 0x0($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X0);
    // 0x8002E0A8: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8002E0AC: bne         $v0, $zero, L_8002E188
    if (ctx->r2 != 0) {
        // 0x8002E0B0: sb          $zero, 0x11($sp)
        MEM_B(0X11, ctx->r29) = 0;
            goto L_8002E188;
    }
    // 0x8002E0B0: sb          $zero, 0x11($sp)
    MEM_B(0X11, ctx->r29) = 0;
    // 0x8002E0B4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8002E0B8: addiu       $a1, $a1, 0x6E7C
    ctx->r5 = ADD32(ctx->r5, 0X6E7C);
    // 0x8002E0BC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8002E0C0: slti        $v0, $a0, 0xB7
    ctx->r2 = SIGNED(ctx->r4) < 0XB7 ? 1 : 0;
    // 0x8002E0C4: bne         $v0, $zero, L_8002E13C
    if (ctx->r2 != 0) {
        // 0x8002E0C8: addiu       $s1, $a0, -0xB6
        ctx->r17 = ADD32(ctx->r4, -0XB6);
            goto L_8002E13C;
    }
    // 0x8002E0C8: addiu       $s1, $a0, -0xB6
    ctx->r17 = ADD32(ctx->r4, -0XB6);
    // 0x8002E0CC: lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // 0x8002E0D0: ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // 0x8002E0D4: mult        $s1, $v0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E0D8: sra         $v0, $s1, 31
    ctx->r2 = S32(SIGNED(ctx->r17) >> 31);
    // 0x8002E0DC: mfhi        $t2
    ctx->r10 = hi;
    // 0x8002E0E0: sra         $v1, $t2, 1
    ctx->r3 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8002E0E4: subu        $s1, $v1, $v0
    ctx->r17 = SUB32(ctx->r3, ctx->r2);
    // 0x8002E0E8: beq         $s1, $zero, L_8002E0F8
    if (ctx->r17 == 0) {
        // 0x8002E0EC: subu        $v0, $a0, $s1
        ctx->r2 = SUB32(ctx->r4, ctx->r17);
            goto L_8002E0F8;
    }
    // 0x8002E0EC: subu        $v0, $a0, $s1
    ctx->r2 = SUB32(ctx->r4, ctx->r17);
    // 0x8002E0F0: j           L_8002E108
    // 0x8002E0F4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_8002E108;
    // 0x8002E0F4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_8002E0F8:
    // 0x8002E0F8: addiu       $v0, $zero, 0xB6
    ctx->r2 = ADD32(0, 0XB6);
    // 0x8002E0FC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8002E100: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002E104: sb          $zero, 0x49B3($at)
    MEM_B(0X49B3, ctx->r1) = 0;
L_8002E108:
    // 0x8002E108: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002E10C: lbu         $v0, 0x49B4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X49B4);
    // 0x8002E110: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8002E114: bne         $v0, $zero, L_8002E194
    if (ctx->r2 != 0) {
        // 0x8002E118: addiu       $a0, $zero, 0x27
        ctx->r4 = ADD32(0, 0X27);
            goto L_8002E194;
    }
    // 0x8002E118: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x8002E11C: jal         0x8000637C
    // 0x8002E120: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8000637C(rdram, ctx);
        goto after_3;
    // 0x8002E120: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8002E124: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002E128: lbu         $v0, 0x49B4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X49B4);
    // 0x8002E12C: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x8002E130: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002E134: j           L_8002E194
    // 0x8002E138: sb          $v0, 0x49B4($at)
    MEM_B(0X49B4, ctx->r1) = ctx->r2;
        goto L_8002E194;
    // 0x8002E138: sb          $v0, 0x49B4($at)
    MEM_B(0X49B4, ctx->r1) = ctx->r2;
L_8002E13C:
    // 0x8002E13C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8002E140: addiu       $a0, $a0, 0x49B3
    ctx->r4 = ADD32(ctx->r4, 0X49B3);
    // 0x8002E144: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8002E148: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8002E14C: slti        $v0, $v0, 0x3C
    ctx->r2 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // 0x8002E150: beq         $v0, $zero, L_8002E160
    if (ctx->r2 == 0) {
        // 0x8002E154: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8002E160;
    }
    // 0x8002E154: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8002E158: j           L_8002E194
    // 0x8002E15C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
        goto L_8002E194;
    // 0x8002E15C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_8002E160:
    // 0x8002E160: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8002E164: lbu         $v1, 0x49B4($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X49B4);
    // 0x8002E168: addiu       $v0, $zero, 0x160
    ctx->r2 = ADD32(0, 0X160);
    // 0x8002E16C: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x8002E170: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x8002E174: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8002E178: andi        $v1, $v1, 0xF0
    ctx->r3 = ctx->r3 & 0XF0;
    // 0x8002E17C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002E180: j           L_8002E194
    // 0x8002E184: sb          $v1, 0x49B4($at)
    MEM_B(0X49B4, ctx->r1) = ctx->r3;
        goto L_8002E194;
    // 0x8002E184: sb          $v1, 0x49B4($at)
    MEM_B(0X49B4, ctx->r1) = ctx->r3;
L_8002E188:
    // 0x8002E188: addiu       $v0, $zero, 0x160
    ctx->r2 = ADD32(0, 0X160);
    // 0x8002E18C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002E190: sw          $v0, 0x6E7C($at)
    MEM_W(0X6E7C, ctx->r1) = ctx->r2;
L_8002E194:
    // 0x8002E194: jal         0x800346F4
    // 0x8002E198: nop

    func_800346F4(rdram, ctx);
        goto after_4;
    // 0x8002E198: nop

    after_4:
    // 0x8002E19C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002E1A0: lw          $v1, 0x6E68($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6E68);
    // 0x8002E1A4: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8002E1A8: addiu       $v0, $zero, -0x20
    ctx->r2 = ADD32(0, -0X20);
    // 0x8002E1AC: beq         $v1, $v0, L_8002E38C
    if (ctx->r3 == ctx->r2) {
        // 0x8002E1B0: addiu       $a2, $s1, 0x78
        ctx->r6 = ADD32(ctx->r17, 0X78);
            goto L_8002E38C;
    }
    // 0x8002E1B0: addiu       $a2, $s1, 0x78
    ctx->r6 = ADD32(ctx->r17, 0X78);
    // 0x8002E1B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002E1B8: ldc1        $f2, -0x2880($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2880);
    // 0x8002E1BC: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8002E1C0: nop

    // 0x8002E1C4: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x8002E1C8: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8002E1CC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8002E1D0: addiu       $a0, $a0, -0x288C
    ctx->r4 = ADD32(ctx->r4, -0X288C);
    // 0x8002E1D4: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8002E1D8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8002E1DC: nop

    // 0x8002E1E0: jal         0x8004EC44
    // 0x8002E1E4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_5;
    // 0x8002E1E4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_5:
    // 0x8002E1E8: lb          $v0, 0x10($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X10);
    // 0x8002E1EC: beq         $v0, $zero, L_8002E294
    if (ctx->r2 == 0) {
        // 0x8002E1F0: nop
    
            goto L_8002E294;
    }
    // 0x8002E1F0: nop

    // 0x8002E1F4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002E1F8: lw          $v0, 0x6E6C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E6C);
    // 0x8002E1FC: slti        $v0, $v0, 0x89
    ctx->r2 = SIGNED(ctx->r2) < 0X89 ? 1 : 0;
    // 0x8002E200: beq         $v0, $zero, L_8002E294
    if (ctx->r2 == 0) {
        // 0x8002E204: nop
    
            goto L_8002E294;
    }
    // 0x8002E204: nop

    // 0x8002E208: lui         $s2, 0x800C
    ctx->r18 = S32(0X800C << 16);
    // 0x8002E20C: addiu       $s2, $s2, 0x49B0
    ctx->r18 = ADD32(ctx->r18, 0X49B0);
    // 0x8002E210: lb          $a2, 0x0($s2)
    ctx->r6 = MEM_B(ctx->r18, 0X0);
    // 0x8002E214: slti        $v0, $a2, 0x3
    ctx->r2 = SIGNED(ctx->r6) < 0X3 ? 1 : 0;
    // 0x8002E218: bne         $v0, $zero, L_8002E294
    if (ctx->r2 != 0) {
        // 0x8002E21C: addiu       $s0, $sp, 0x18
        ctx->r16 = ADD32(ctx->r29, 0X18);
            goto L_8002E294;
    }
    // 0x8002E21C: addiu       $s0, $sp, 0x18
    ctx->r16 = ADD32(ctx->r29, 0X18);
    // 0x8002E220: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8002E224: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8002E228: addiu       $a1, $a1, -0x2888
    ctx->r5 = ADD32(ctx->r5, -0X2888);
    // 0x8002E22C: jal         0x80066CA0
    // 0x8002E230: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    func_80066CA0(rdram, ctx);
        goto after_6;
    // 0x8002E230: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_6:
    // 0x8002E234: lb          $v0, 0x0($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X0);
    // 0x8002E238: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8002E23C: slti        $v0, $t0, 0xA
    ctx->r2 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x8002E240: beq         $v0, $zero, L_8002E25C
    if (ctx->r2 == 0) {
        // 0x8002E244: lui         $v0, 0x6666
        ctx->r2 = S32(0X6666 << 16);
            goto L_8002E25C;
    }
    // 0x8002E244: lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // 0x8002E248: ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // 0x8002E24C: mult        $t0, $v0
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E250: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8002E254: j           L_8002E26C
    // 0x8002E258: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
        goto L_8002E26C;
    // 0x8002E258: addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
L_8002E25C:
    // 0x8002E25C: ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // 0x8002E260: mult        $t0, $v0
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E264: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8002E268: addiu       $a1, $zero, 0x79
    ctx->r5 = ADD32(0, 0X79);
L_8002E26C:
    // 0x8002E26C: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // 0x8002E270: subu        $a2, $a2, $s1
    ctx->r6 = SUB32(ctx->r6, ctx->r17);
    // 0x8002E274: sra         $v1, $t0, 31
    ctx->r3 = S32(SIGNED(ctx->r8) >> 31);
    // 0x8002E278: mfhi        $t2
    ctx->r10 = hi;
    // 0x8002E27C: sra         $v0, $t2, 1
    ctx->r2 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8002E280: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8002E284: sll         $a3, $v0, 2
    ctx->r7 = S32(ctx->r2 << 2);
    // 0x8002E288: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x8002E28C: jal         0x8004EC44
    // 0x8002E290: subu        $a3, $t0, $a3
    ctx->r7 = SUB32(ctx->r8, ctx->r7);
    func_8004EC44(rdram, ctx);
        goto after_7;
    // 0x8002E290: subu        $a3, $t0, $a3
    ctx->r7 = SUB32(ctx->r8, ctx->r7);
    after_7:
L_8002E294:
    // 0x8002E294: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8002E298: addiu       $s0, $s0, 0x49B0
    ctx->r16 = ADD32(ctx->r16, 0X49B0);
    // 0x8002E29C: lb          $a2, 0x0($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X0);
    // 0x8002E2A0: addiu       $s2, $sp, 0x18
    ctx->r18 = ADD32(ctx->r29, 0X18);
    // 0x8002E2A4: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8002E2A8: addiu       $a1, $a1, -0x2888
    ctx->r5 = ADD32(ctx->r5, -0X2888);
    // 0x8002E2AC: jal         0x80066CA0
    // 0x8002E2B0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80066CA0(rdram, ctx);
        goto after_8;
    // 0x8002E2B0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_8:
    // 0x8002E2B4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8002E2B8: sll         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2 << 24);
    // 0x8002E2BC: sra         $t0, $v1, 24
    ctx->r8 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8002E2C0: slti        $v0, $t0, 0xA
    ctx->r2 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x8002E2C4: beq         $v0, $zero, L_8002E30C
    if (ctx->r2 == 0) {
        // 0x8002E2C8: lui         $v0, 0x6666
        ctx->r2 = S32(0X6666 << 16);
            goto L_8002E30C;
    }
    // 0x8002E2C8: lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // 0x8002E2CC: ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // 0x8002E2D0: mult        $t0, $v0
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E2D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002E2D8: ldc1        $f2, -0x2878($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2878);
    // 0x8002E2DC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002E2E0: lwc1        $f0, 0x6E6C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6E6C);
    // 0x8002E2E4: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x8002E2E8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8002E2EC: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8002E2F0: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // 0x8002E2F4: subu        $a2, $a2, $s1
    ctx->r6 = SUB32(ctx->r6, ctx->r17);
    // 0x8002E2F8: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8002E2FC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8002E300: nop

    // 0x8002E304: j           L_8002E330
    // 0x8002E308: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
        goto L_8002E330;
    // 0x8002E308: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
L_8002E30C:
    // 0x8002E30C: ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // 0x8002E310: mult        $t0, $v0
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E314: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8002E318: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8002E31C: lw          $a1, 0x6E6C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6E6C);
    // 0x8002E320: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // 0x8002E324: subu        $a2, $a2, $s1
    ctx->r6 = SUB32(ctx->r6, ctx->r17);
    // 0x8002E328: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8002E32C: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_8002E330:
    // 0x8002E330: mfhi        $t2
    ctx->r10 = hi;
    // 0x8002E334: sra         $v0, $t2, 1
    ctx->r2 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8002E338: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8002E33C: sll         $a3, $v0, 2
    ctx->r7 = S32(ctx->r2 << 2);
    // 0x8002E340: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x8002E344: subu        $a3, $t0, $a3
    ctx->r7 = SUB32(ctx->r8, ctx->r7);
    // 0x8002E348: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x8002E34C: jal         0x8004EC44
    // 0x8002E350: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    func_8004EC44(rdram, ctx);
        goto after_9;
    // 0x8002E350: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    after_9:
    // 0x8002E354: lb          $v0, 0x10($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X10);
    // 0x8002E358: bne         $v0, $zero, L_8002E3F0
    if (ctx->r2 != 0) {
        // 0x8002E35C: nop
    
            goto L_8002E3F0;
    }
    // 0x8002E35C: nop

    // 0x8002E360: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8002E364: lb          $v1, 0x49B0($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X49B0);
    // 0x8002E368: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8002E36C: bne         $v0, $zero, L_8002E3F0
    if (ctx->r2 != 0) {
        // 0x8002E370: slti        $v0, $v1, 0x14
        ctx->r2 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
            goto L_8002E3F0;
    }
    // 0x8002E370: slti        $v0, $v1, 0x14
    ctx->r2 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x8002E374: beq         $v0, $zero, L_8002E3B8
    if (ctx->r2 == 0) {
        // 0x8002E378: addiu       $a2, $s1, 0x78
        ctx->r6 = ADD32(ctx->r17, 0X78);
            goto L_8002E3B8;
    }
    // 0x8002E378: addiu       $a2, $s1, 0x78
    ctx->r6 = ADD32(ctx->r17, 0X78);
    // 0x8002E37C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8002E380: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002E384: j           L_8002E3C4
    // 0x8002E388: lb          $v0, -0x28A3($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X28A3);
        goto L_8002E3C4;
    // 0x8002E388: lb          $v0, -0x28A3($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X28A3);
L_8002E38C:
    // 0x8002E38C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8002E390: lb          $v1, 0x49B0($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X49B0);
    // 0x8002E394: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8002E398: bne         $v0, $zero, L_8002E3F0
    if (ctx->r2 != 0) {
        // 0x8002E39C: slti        $v0, $v1, 0x14
        ctx->r2 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
            goto L_8002E3F0;
    }
    // 0x8002E39C: slti        $v0, $v1, 0x14
    ctx->r2 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x8002E3A0: beq         $v0, $zero, L_8002E3B8
    if (ctx->r2 == 0) {
        // 0x8002E3A4: addiu       $a2, $s1, 0x78
        ctx->r6 = ADD32(ctx->r17, 0X78);
            goto L_8002E3B8;
    }
    // 0x8002E3A4: addiu       $a2, $s1, 0x78
    ctx->r6 = ADD32(ctx->r17, 0X78);
    // 0x8002E3A8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8002E3AC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002E3B0: j           L_8002E3C4
    // 0x8002E3B4: lb          $v0, -0x28A3($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X28A3);
        goto L_8002E3C4;
    // 0x8002E3B4: lb          $v0, -0x28A3($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X28A3);
L_8002E3B8:
    // 0x8002E3B8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8002E3BC: lb          $v0, -0x288F($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X288F);
    // 0x8002E3C0: addiu       $a2, $s1, 0x78
    ctx->r6 = ADD32(ctx->r17, 0X78);
L_8002E3C4:
    // 0x8002E3C4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8002E3C8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8002E3CC: lw          $a1, 0x6E70($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6E70);
    // 0x8002E3D0: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x8002E3D4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8002E3D8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8002E3DC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002E3E0: addiu       $v0, $v0, 0x6DF0
    ctx->r2 = ADD32(ctx->r2, 0X6DF0);
    // 0x8002E3E4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8002E3E8: jal         0x8004EC44
    // 0x8002E3EC: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    func_8004EC44(rdram, ctx);
        goto after_10;
    // 0x8002E3EC: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    after_10:
L_8002E3F0:
    // 0x8002E3F0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002E3F4: lw          $v1, 0x6E70($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6E70);
    // 0x8002E3F8: addiu       $v0, $zero, 0x160
    ctx->r2 = ADD32(0, 0X160);
    // 0x8002E3FC: beq         $v1, $v0, L_8002E5DC
    if (ctx->r3 == ctx->r2) {
        // 0x8002E400: addiu       $a2, $s1, 0x78
        ctx->r6 = ADD32(ctx->r17, 0X78);
            goto L_8002E5DC;
    }
    // 0x8002E400: addiu       $a2, $s1, 0x78
    ctx->r6 = ADD32(ctx->r17, 0X78);
    // 0x8002E404: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002E408: ldc1        $f2, -0x2870($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2870);
    // 0x8002E40C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002E410: lwc1        $f0, 0x6E74($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6E74);
    // 0x8002E414: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x8002E418: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8002E41C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8002E420: addiu       $a0, $a0, -0x288C
    ctx->r4 = ADD32(ctx->r4, -0X288C);
    // 0x8002E424: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8002E428: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8002E42C: nop

    // 0x8002E430: jal         0x8004EC44
    // 0x8002E434: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_11;
    // 0x8002E434: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_11:
    // 0x8002E438: lb          $v0, 0x11($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X11);
    // 0x8002E43C: beq         $v0, $zero, L_8002E4E4
    if (ctx->r2 == 0) {
        // 0x8002E440: nop
    
            goto L_8002E4E4;
    }
    // 0x8002E440: nop

    // 0x8002E444: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002E448: lw          $v0, 0x6E78($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E78);
    // 0x8002E44C: slti        $v0, $v0, 0xB7
    ctx->r2 = SIGNED(ctx->r2) < 0XB7 ? 1 : 0;
    // 0x8002E450: bne         $v0, $zero, L_8002E4E4
    if (ctx->r2 != 0) {
        // 0x8002E454: nop
    
            goto L_8002E4E4;
    }
    // 0x8002E454: nop

    // 0x8002E458: lui         $s2, 0x800C
    ctx->r18 = S32(0X800C << 16);
    // 0x8002E45C: addiu       $s2, $s2, 0x49B1
    ctx->r18 = ADD32(ctx->r18, 0X49B1);
    // 0x8002E460: lb          $a2, 0x0($s2)
    ctx->r6 = MEM_B(ctx->r18, 0X0);
    // 0x8002E464: slti        $v0, $a2, 0x3
    ctx->r2 = SIGNED(ctx->r6) < 0X3 ? 1 : 0;
    // 0x8002E468: bne         $v0, $zero, L_8002E4E4
    if (ctx->r2 != 0) {
        // 0x8002E46C: addiu       $s0, $sp, 0x18
        ctx->r16 = ADD32(ctx->r29, 0X18);
            goto L_8002E4E4;
    }
    // 0x8002E46C: addiu       $s0, $sp, 0x18
    ctx->r16 = ADD32(ctx->r29, 0X18);
    // 0x8002E470: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8002E474: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8002E478: addiu       $a1, $a1, -0x2888
    ctx->r5 = ADD32(ctx->r5, -0X2888);
    // 0x8002E47C: jal         0x80066CA0
    // 0x8002E480: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    func_80066CA0(rdram, ctx);
        goto after_12;
    // 0x8002E480: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_12:
    // 0x8002E484: lb          $v0, 0x0($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X0);
    // 0x8002E488: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8002E48C: slti        $v0, $t0, 0xA
    ctx->r2 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x8002E490: beq         $v0, $zero, L_8002E4AC
    if (ctx->r2 == 0) {
        // 0x8002E494: lui         $v0, 0x6666
        ctx->r2 = S32(0X6666 << 16);
            goto L_8002E4AC;
    }
    // 0x8002E494: lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // 0x8002E498: ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // 0x8002E49C: mult        $t0, $v0
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E4A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8002E4A4: j           L_8002E4BC
    // 0x8002E4A8: addiu       $a1, $zero, 0xAE
    ctx->r5 = ADD32(0, 0XAE);
        goto L_8002E4BC;
    // 0x8002E4A8: addiu       $a1, $zero, 0xAE
    ctx->r5 = ADD32(0, 0XAE);
L_8002E4AC:
    // 0x8002E4AC: ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // 0x8002E4B0: mult        $t0, $v0
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E4B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8002E4B8: addiu       $a1, $zero, 0xA6
    ctx->r5 = ADD32(0, 0XA6);
L_8002E4BC:
    // 0x8002E4BC: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // 0x8002E4C0: subu        $a2, $a2, $s1
    ctx->r6 = SUB32(ctx->r6, ctx->r17);
    // 0x8002E4C4: sra         $v1, $t0, 31
    ctx->r3 = S32(SIGNED(ctx->r8) >> 31);
    // 0x8002E4C8: mfhi        $t2
    ctx->r10 = hi;
    // 0x8002E4CC: sra         $v0, $t2, 1
    ctx->r2 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8002E4D0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8002E4D4: sll         $a3, $v0, 2
    ctx->r7 = S32(ctx->r2 << 2);
    // 0x8002E4D8: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x8002E4DC: jal         0x8004EC44
    // 0x8002E4E0: subu        $a3, $t0, $a3
    ctx->r7 = SUB32(ctx->r8, ctx->r7);
    func_8004EC44(rdram, ctx);
        goto after_13;
    // 0x8002E4E0: subu        $a3, $t0, $a3
    ctx->r7 = SUB32(ctx->r8, ctx->r7);
    after_13:
L_8002E4E4:
    // 0x8002E4E4: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8002E4E8: addiu       $s0, $s0, 0x49B1
    ctx->r16 = ADD32(ctx->r16, 0X49B1);
    // 0x8002E4EC: lb          $a2, 0x0($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X0);
    // 0x8002E4F0: addiu       $s2, $sp, 0x18
    ctx->r18 = ADD32(ctx->r29, 0X18);
    // 0x8002E4F4: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8002E4F8: addiu       $a1, $a1, -0x2888
    ctx->r5 = ADD32(ctx->r5, -0X2888);
    // 0x8002E4FC: jal         0x80066CA0
    // 0x8002E500: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80066CA0(rdram, ctx);
        goto after_14;
    // 0x8002E500: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_14:
    // 0x8002E504: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8002E508: sll         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2 << 24);
    // 0x8002E50C: sra         $t0, $v1, 24
    ctx->r8 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8002E510: slti        $v0, $t0, 0xA
    ctx->r2 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x8002E514: beq         $v0, $zero, L_8002E55C
    if (ctx->r2 == 0) {
        // 0x8002E518: lui         $v0, 0x6666
        ctx->r2 = S32(0X6666 << 16);
            goto L_8002E55C;
    }
    // 0x8002E518: lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // 0x8002E51C: ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // 0x8002E520: mult        $t0, $v0
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E524: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002E528: ldc1        $f2, -0x2868($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2868);
    // 0x8002E52C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002E530: lwc1        $f0, 0x6E78($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6E78);
    // 0x8002E534: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x8002E538: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8002E53C: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8002E540: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // 0x8002E544: subu        $a2, $a2, $s1
    ctx->r6 = SUB32(ctx->r6, ctx->r17);
    // 0x8002E548: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8002E54C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8002E550: nop

    // 0x8002E554: j           L_8002E580
    // 0x8002E558: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
        goto L_8002E580;
    // 0x8002E558: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
L_8002E55C:
    // 0x8002E55C: ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // 0x8002E560: mult        $t0, $v0
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E564: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8002E568: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8002E56C: lw          $a1, 0x6E78($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6E78);
    // 0x8002E570: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // 0x8002E574: subu        $a2, $a2, $s1
    ctx->r6 = SUB32(ctx->r6, ctx->r17);
    // 0x8002E578: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8002E57C: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_8002E580:
    // 0x8002E580: mfhi        $t2
    ctx->r10 = hi;
    // 0x8002E584: sra         $v0, $t2, 1
    ctx->r2 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8002E588: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8002E58C: sll         $a3, $v0, 2
    ctx->r7 = S32(ctx->r2 << 2);
    // 0x8002E590: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x8002E594: subu        $a3, $t0, $a3
    ctx->r7 = SUB32(ctx->r8, ctx->r7);
    // 0x8002E598: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x8002E59C: jal         0x8004EC44
    // 0x8002E5A0: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    func_8004EC44(rdram, ctx);
        goto after_15;
    // 0x8002E5A0: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    after_15:
    // 0x8002E5A4: lb          $v0, 0x11($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X11);
    // 0x8002E5A8: bne         $v0, $zero, L_8002E640
    if (ctx->r2 != 0) {
        // 0x8002E5AC: nop
    
            goto L_8002E640;
    }
    // 0x8002E5AC: nop

    // 0x8002E5B0: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8002E5B4: lb          $v1, 0x49B1($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X49B1);
    // 0x8002E5B8: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8002E5BC: bne         $v0, $zero, L_8002E640
    if (ctx->r2 != 0) {
        // 0x8002E5C0: slti        $v0, $v1, 0x14
        ctx->r2 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
            goto L_8002E640;
    }
    // 0x8002E5C0: slti        $v0, $v1, 0x14
    ctx->r2 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x8002E5C4: beq         $v0, $zero, L_8002E608
    if (ctx->r2 == 0) {
        // 0x8002E5C8: addiu       $a2, $s1, 0x78
        ctx->r6 = ADD32(ctx->r17, 0X78);
            goto L_8002E608;
    }
    // 0x8002E5C8: addiu       $a2, $s1, 0x78
    ctx->r6 = ADD32(ctx->r17, 0X78);
    // 0x8002E5CC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8002E5D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002E5D4: j           L_8002E614
    // 0x8002E5D8: lb          $v0, -0x28A3($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X28A3);
        goto L_8002E614;
    // 0x8002E5D8: lb          $v0, -0x28A3($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X28A3);
L_8002E5DC:
    // 0x8002E5DC: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8002E5E0: lb          $v1, 0x49B1($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X49B1);
    // 0x8002E5E4: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8002E5E8: bne         $v0, $zero, L_8002E640
    if (ctx->r2 != 0) {
        // 0x8002E5EC: slti        $v0, $v1, 0x14
        ctx->r2 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
            goto L_8002E640;
    }
    // 0x8002E5EC: slti        $v0, $v1, 0x14
    ctx->r2 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x8002E5F0: beq         $v0, $zero, L_8002E608
    if (ctx->r2 == 0) {
        // 0x8002E5F4: addiu       $a2, $s1, 0x78
        ctx->r6 = ADD32(ctx->r17, 0X78);
            goto L_8002E608;
    }
    // 0x8002E5F4: addiu       $a2, $s1, 0x78
    ctx->r6 = ADD32(ctx->r17, 0X78);
    // 0x8002E5F8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8002E5FC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002E600: j           L_8002E614
    // 0x8002E604: lb          $v0, -0x28A3($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X28A3);
        goto L_8002E614;
    // 0x8002E604: lb          $v0, -0x28A3($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X28A3);
L_8002E608:
    // 0x8002E608: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8002E60C: lb          $v0, -0x288F($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X288F);
    // 0x8002E610: addiu       $a2, $s1, 0x78
    ctx->r6 = ADD32(ctx->r17, 0X78);
L_8002E614:
    // 0x8002E614: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8002E618: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8002E61C: lw          $a1, 0x6E7C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6E7C);
    // 0x8002E620: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x8002E624: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8002E628: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8002E62C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002E630: addiu       $v0, $v0, 0x6DF0
    ctx->r2 = ADD32(ctx->r2, 0X6DF0);
    // 0x8002E634: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8002E638: jal         0x8004EC44
    // 0x8002E63C: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    func_8004EC44(rdram, ctx);
        goto after_16;
    // 0x8002E63C: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    after_16:
L_8002E640:
    // 0x8002E640: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8002E644: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8002E648: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8002E64C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8002E650: jr          $ra
    // 0x8002E654: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8002E654: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8002E658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E658: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8002E65C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8002E660: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x8002E664: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8002E668: lw          $v0, -0x34C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34C0);
    // 0x8002E66C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8002E670: lw          $a1, 0x4470($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4470);
    // 0x8002E674: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x8002E678: lwc1        $f20, 0x68($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8002E67C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8002E680: lhu         $s7, 0x6E($sp)
    ctx->r23 = MEM_HU(ctx->r29, 0X6E);
    // 0x8002E684: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8002E688: lbu         $fp, 0x73($sp)
    ctx->r30 = MEM_BU(ctx->r29, 0X73);
    // 0x8002E68C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8002E690: lbu         $s6, 0x77($sp)
    ctx->r22 = MEM_BU(ctx->r29, 0X77);
    // 0x8002E694: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x8002E698: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x8002E69C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002E6A0: andi        $s0, $a0, 0xFF
    ctx->r16 = ctx->r4 & 0XFF;
    // 0x8002E6A4: sdc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X50, ctx->r29);
    // 0x8002E6A8: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x8002E6AC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8002E6B0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8002E6B4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002E6B8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002E6BC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002E6C0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002E6C4: sll         $a2, $v0, 3
    ctx->r6 = S32(ctx->r2 << 3);
    // 0x8002E6C8: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x8002E6CC: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x8002E6D0: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8002E6D4: sll         $a2, $a2, 5
    ctx->r6 = S32(ctx->r6 << 5);
    // 0x8002E6D8: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x8002E6DC: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8002E6E0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8002E6E4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002E6E8: addiu       $v0, $v0, 0x4580
    ctx->r2 = ADD32(ctx->r2, 0X4580);
    // 0x8002E6EC: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8002E6F0: addu        $s1, $a2, $v0
    ctx->r17 = ADD32(ctx->r6, ctx->r2);
    // 0x8002E6F4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8002E6F8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002E6FC: addiu       $v0, $v0, 0x26E0
    ctx->r2 = ADD32(ctx->r2, 0X26E0);
    // 0x8002E700: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8002E704: addu        $s4, $a2, $v0
    ctx->r20 = ADD32(ctx->r6, ctx->r2);
    // 0x8002E708: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002E70C: addiu       $v0, $v0, 0x1230
    ctx->r2 = ADD32(ctx->r2, 0X1230);
    // 0x8002E710: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8002E714: addu        $s2, $a2, $v0
    ctx->r18 = ADD32(ctx->r6, ctx->r2);
    // 0x8002E718: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x8002E71C: addiu       $v0, $v0, -0x7540
    ctx->r2 = ADD32(ctx->r2, -0X7540);
    // 0x8002E720: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002E724: addu        $s3, $a2, $v1
    ctx->r19 = ADD32(ctx->r6, ctx->r3);
    // 0x8002E728: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8002E72C: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // 0x8002E730: jal         0x800178E0
    // 0x8002E734: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    func_800178E0(rdram, ctx);
        goto after_0;
    // 0x8002E734: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_0:
    // 0x8002E738: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8002E73C: bne         $s0, $v0, L_8002E75C
    if (ctx->r16 != ctx->r2) {
        // 0x8002E740: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_8002E75C;
    }
    // 0x8002E740: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8002E744: sll         $v0, $s5, 2
    ctx->r2 = S32(ctx->r21 << 2);
    // 0x8002E748: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002E74C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002E750: lw          $v0, 0x6FA8($at)
    ctx->r2 = MEM_W(ctx->r1, 0X6FA8);
    // 0x8002E754: j           L_8002E774
    // 0x8002E758: sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
        goto L_8002E774;
    // 0x8002E758: sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
L_8002E75C:
    // 0x8002E75C: bne         $s0, $v0, L_8002E774
    if (ctx->r16 != ctx->r2) {
        // 0x8002E760: sll         $v0, $s5, 2
        ctx->r2 = S32(ctx->r21 << 2);
            goto L_8002E774;
    }
    // 0x8002E760: sll         $v0, $s5, 2
    ctx->r2 = S32(ctx->r21 << 2);
    // 0x8002E764: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002E768: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002E76C: lw          $v0, 0x6FE0($at)
    ctx->r2 = MEM_W(ctx->r1, 0X6FE0);
    // 0x8002E770: sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
L_8002E774:
    // 0x8002E774: bne         $s6, $zero, L_8002E78C
    if (ctx->r22 != 0) {
        // 0x8002E778: nop
    
            goto L_8002E78C;
    }
    // 0x8002E778: nop

    // 0x8002E77C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8002E780: addiu       $v0, $v0, 0x4640
    ctx->r2 = ADD32(ctx->r2, 0X4640);
    // 0x8002E784: j           L_8002E798
    // 0x8002E788: sw          $v0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r2;
        goto L_8002E798;
    // 0x8002E788: sw          $v0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r2;
L_8002E78C:
    // 0x8002E78C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8002E790: addiu       $v0, $v0, 0x4660
    ctx->r2 = ADD32(ctx->r2, 0X4660);
    // 0x8002E794: sw          $v0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r2;
L_8002E798:
    // 0x8002E798: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8002E79C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002E7A0: nop

    // 0x8002E7A4: div.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8002E7A8: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x8002E7AC: srl         $v0, $v0, 5
    ctx->r2 = S32(U32(ctx->r2) >> 5);
    // 0x8002E7B0: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8002E7B4: nop

    // 0x8002E7B8: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8002E7BC: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8002E7C0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E7C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002E7C8: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8002E7CC: div.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8002E7D0: lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XC);
    // 0x8002E7D4: srl         $v0, $v0, 5
    ctx->r2 = S32(U32(ctx->r2) >> 5);
    // 0x8002E7D8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8002E7DC: nop

    // 0x8002E7E0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002E7E4: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8002E7E8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8002E7EC: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8002E7F0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8002E7F4: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    // 0x8002E7F8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8002E7FC: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8002E800: nop

    // 0x8002E804: sh          $v0, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r2;
    // 0x8002E808: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // 0x8002E80C: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8002E810: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8002E814: nop

    // 0x8002E818: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002E81C: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x8002E820: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002E824: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002E828: nop

    // 0x8002E82C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002E830: jal         0x80018514
    // 0x8002E834: sh          $v0, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r2;
    func_80018514(rdram, ctx);
        goto after_1;
    // 0x8002E834: sh          $v0, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r2;
    after_1:
    // 0x8002E838: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x8002E83C: ori         $a0, $a0, 0x1402
    ctx->r4 = ctx->r4 | 0X1402;
    // 0x8002E840: lui         $t0, 0xFC11
    ctx->r8 = S32(0XFC11 << 16);
    // 0x8002E844: ori         $t0, $t0, 0x9623
    ctx->r8 = ctx->r8 | 0X9623;
    // 0x8002E848: lui         $a3, 0xFF2F
    ctx->r7 = S32(0XFF2F << 16);
    // 0x8002E84C: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x8002E850: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x8002E854: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x8002E858: lui         $t1, 0x40
    ctx->r9 = S32(0X40 << 16);
    // 0x8002E85C: ori         $t1, $t1, 0x4240
    ctx->r9 = ctx->r9 | 0X4240;
    // 0x8002E860: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x8002E864: ori         $t3, $t3, 0xE02
    ctx->r11 = ctx->r11 | 0XE02;
    // 0x8002E868: lui         $a2, 0xC100
    ctx->r6 = S32(0XC100 << 16);
    // 0x8002E86C: trunc.w.s   $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.u32l = TRUNC_W_S(ctx->f22.fl);
    // 0x8002E870: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8002E874: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002E878: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8002E87C: ori         $a2, $a2, 0x17
    ctx->r6 = ctx->r6 | 0X17;
    // 0x8002E880: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002E884: sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // 0x8002E888: trunc.w.s   $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    ctx->f0.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x8002E88C: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8002E890: nop

    // 0x8002E894: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002E898: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x8002E89C: sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // 0x8002E8A0: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8002E8A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002E8A8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002E8AC: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8002E8B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002E8B4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002E8B8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002E8BC: addiu       $v0, $v0, -0x6790
    ctx->r2 = ADD32(ctx->r2, -0X6790);
    // 0x8002E8C0: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8002E8C4: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8002E8C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002E8CC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002E8D0: lui         $v0, 0xB100
    ctx->r2 = S32(0XB100 << 16);
    // 0x8002E8D4: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x8002E8D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002E8DC: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x8002E8E0: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x8002E8E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002E8E8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002E8EC: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x8002E8F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002E8F4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002E8F8: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x8002E8FC: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // 0x8002E900: addiu       $v0, $zero, -0x100
    ctx->r2 = ADD32(0, -0X100);
    // 0x8002E904: or          $v0, $fp, $v0
    ctx->r2 = ctx->r30 | ctx->r2;
    // 0x8002E908: sw          $v0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r2;
    // 0x8002E90C: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x8002E910: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002E914: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002E918: addiu       $v0, $v1, 0x38
    ctx->r2 = ADD32(ctx->r3, 0X38);
    // 0x8002E91C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002E920: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002E924: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x8002E928: sw          $v0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r2;
    // 0x8002E92C: addiu       $v0, $v1, 0x40
    ctx->r2 = ADD32(ctx->r3, 0X40);
    // 0x8002E930: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002E934: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002E938: addiu       $v0, $v1, 0x48
    ctx->r2 = ADD32(ctx->r3, 0X48);
    // 0x8002E93C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002E940: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002E944: addiu       $v0, $v1, 0x50
    ctx->r2 = ADD32(ctx->r3, 0X50);
    // 0x8002E948: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002E94C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002E950: lui         $v0, 0x517
    ctx->r2 = S32(0X517 << 16);
    // 0x8002E954: sw          $v0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r2;
    // 0x8002E958: addiu       $v0, $v1, 0x58
    ctx->r2 = ADD32(ctx->r3, 0X58);
    // 0x8002E95C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8002E960: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8002E964: sw          $a1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r5;
    // 0x8002E968: sw          $t0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r8;
    // 0x8002E96C: sw          $a3, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r7;
    // 0x8002E970: sw          $t2, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r10;
    // 0x8002E974: sw          $t1, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r9;
    // 0x8002E978: sw          $t3, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r11;
    // 0x8002E97C: sw          $a2, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r6;
    // 0x8002E980: sw          $s4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r20;
    // 0x8002E984: sw          $a2, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r6;
    // 0x8002E988: sw          $s3, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r19;
    // 0x8002E98C: sw          $s2, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r18;
    // 0x8002E990: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002E994: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002E998: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8002E99C: lw          $a0, 0x4470($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4470);
    // 0x8002E9A0: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x8002E9A4: sw          $v0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r2;
    // 0x8002E9A8: addiu       $v0, $v1, 0x60
    ctx->r2 = ADD32(ctx->r3, 0X60);
    // 0x8002E9AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002E9B0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002E9B4: addiu       $v0, $v1, 0x68
    ctx->r2 = ADD32(ctx->r3, 0X68);
    // 0x8002E9B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002E9BC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002E9C0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002E9C4: addiu       $v0, $v0, -0x6850
    ctx->r2 = ADD32(ctx->r2, -0X6850);
    // 0x8002E9C8: sw          $v0, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r2;
    // 0x8002E9CC: addiu       $v0, $v1, 0x70
    ctx->r2 = ADD32(ctx->r3, 0X70);
    // 0x8002E9D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002E9D4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002E9D8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002E9DC: addiu       $v0, $v0, -0x6858
    ctx->r2 = ADD32(ctx->r2, -0X6858);
    // 0x8002E9E0: sw          $s1, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r17;
    // 0x8002E9E4: sw          $t3, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r11;
    // 0x8002E9E8: sw          $zero, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = 0;
    // 0x8002E9EC: sw          $a1, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r5;
    // 0x8002E9F0: sw          $a1, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->r5;
    // 0x8002E9F4: sw          $v0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r2;
    // 0x8002E9F8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002E9FC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002EA00: sw          $a0, 0x4470($at)
    MEM_W(0X4470, ctx->r1) = ctx->r4;
    // 0x8002EA04: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8002EA08: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8002EA0C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8002EA10: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8002EA14: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8002EA18: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002EA1C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002EA20: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002EA24: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002EA28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002EA2C: ldc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X50);
    // 0x8002EA30: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x8002EA34: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x8002EA38: jr          $ra
    // 0x8002EA3C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8002EA3C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8002EA40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EA40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002EA44: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002EA48: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002EA4C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EA50: sb          $zero, 0x49B8($at)
    MEM_B(0X49B8, ctx->r1) = 0;
    // 0x8002EA54: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EA58: sb          $zero, 0x49B7($at)
    MEM_B(0X49B7, ctx->r1) = 0;
    // 0x8002EA5C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EA60: sb          $zero, 0x49B6($at)
    MEM_B(0X49B6, ctx->r1) = 0;
    // 0x8002EA64: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EA68: sb          $zero, 0x49B5($at)
    MEM_B(0X49B5, ctx->r1) = 0;
    // 0x8002EA6C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EA70: sw          $zero, 0x49C0($at)
    MEM_W(0X49C0, ctx->r1) = 0;
    // 0x8002EA74: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EA78: sw          $zero, 0x49BC($at)
    MEM_W(0X49BC, ctx->r1) = 0;
    // 0x8002EA7C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EA80: sw          $zero, 0x49C8($at)
    MEM_W(0X49C8, ctx->r1) = 0;
    // 0x8002EA84: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EA88: sw          $zero, 0x49C4($at)
    MEM_W(0X49C4, ctx->r1) = 0;
    // 0x8002EA8C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EA90: sb          $v0, 0x49CD($at)
    MEM_B(0X49CD, ctx->r1) = ctx->r2;
    // 0x8002EA94: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EA98: sb          $v0, 0x49CC($at)
    MEM_B(0X49CC, ctx->r1) = ctx->r2;
    // 0x8002EA9C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EAA0: sb          $zero, 0x49D9($at)
    MEM_B(0X49D9, ctx->r1) = 0;
    // 0x8002EAA4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EAA8: sb          $zero, 0x49D8($at)
    MEM_B(0X49D8, ctx->r1) = 0;
    // 0x8002EAAC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EAB0: sb          $zero, 0x49DD($at)
    MEM_B(0X49DD, ctx->r1) = 0;
    // 0x8002EAB4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EAB8: sb          $zero, 0x49DC($at)
    MEM_B(0X49DC, ctx->r1) = 0;
    // 0x8002EABC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EAC0: sb          $zero, 0x49DB($at)
    MEM_B(0X49DB, ctx->r1) = 0;
    // 0x8002EAC4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EAC8: sb          $zero, 0x49DA($at)
    MEM_B(0X49DA, ctx->r1) = 0;
    // 0x8002EACC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EAD0: swc1        $f0, 0x49D4($at)
    MEM_W(0X49D4, ctx->r1) = ctx->f0.u32l;
    // 0x8002EAD4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EAD8: jr          $ra
    // 0x8002EADC: swc1        $f0, 0x49D0($at)
    MEM_W(0X49D0, ctx->r1) = ctx->f0.u32l;
    return;
    // 0x8002EADC: swc1        $f0, 0x49D0($at)
    MEM_W(0X49D0, ctx->r1) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_8002EAE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EAE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002EAE4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002EAE8: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x8002EAEC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8002EAF0: beq         $v0, $zero, L_8002EBB0
    if (ctx->r2 == 0) {
        // 0x8002EAF4: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_8002EBB0;
    }
    // 0x8002EAF4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8002EAF8: lw          $v1, 0x3C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3C);
    // 0x8002EAFC: bne         $v1, $v0, L_8002EB4C
    if (ctx->r3 != ctx->r2) {
        // 0x8002EB00: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002EB4C;
    }
    // 0x8002EB00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002EB04: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002EB08: ldc1        $f2, -0x2860($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2860);
    // 0x8002EB0C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EB10: sb          $v0, 0x49B8($at)
    MEM_B(0X49B8, ctx->r1) = ctx->r2;
    // 0x8002EB14: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8002EB18: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8002EB1C: nop

    // 0x8002EB20: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x8002EB24: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8002EB28: addiu       $v0, $zero, 0x8C
    ctx->r2 = ADD32(0, 0X8C);
    // 0x8002EB2C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EB30: sb          $zero, 0x49B7($at)
    MEM_B(0X49B7, ctx->r1) = 0;
    // 0x8002EB34: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EB38: sw          $v0, 0x49C8($at)
    MEM_W(0X49C8, ctx->r1) = ctx->r2;
    // 0x8002EB3C: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8002EB40: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EB44: j           L_8002EB78
    // 0x8002EB48: swc1        $f2, 0x49C0($at)
    MEM_W(0X49C0, ctx->r1) = ctx->f2.u32l;
        goto L_8002EB78;
    // 0x8002EB48: swc1        $f2, 0x49C0($at)
    MEM_W(0X49C0, ctx->r1) = ctx->f2.u32l;
L_8002EB4C:
    // 0x8002EB4C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EB50: sb          $v0, 0x49B7($at)
    MEM_B(0X49B7, ctx->r1) = ctx->r2;
    // 0x8002EB54: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x8002EB58: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EB5C: sw          $v0, 0x49C8($at)
    MEM_W(0X49C8, ctx->r1) = ctx->r2;
    // 0x8002EB60: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8002EB64: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002EB68: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EB6C: sb          $zero, 0x49B8($at)
    MEM_B(0X49B8, ctx->r1) = 0;
    // 0x8002EB70: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EB74: sw          $v0, 0x49C0($at)
    MEM_W(0X49C0, ctx->r1) = ctx->r2;
L_8002EB78:
    // 0x8002EB78: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002EB7C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002EB80: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002EB84: addiu       $a0, $a0, 0x4660
    ctx->r4 = ADD32(ctx->r4, 0X4660);
    // 0x8002EB88: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EB8C: sb          $zero, 0x49D9($at)
    MEM_B(0X49D9, ctx->r1) = 0;
    // 0x8002EB90: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EB94: sb          $zero, 0x49DD($at)
    MEM_B(0X49DD, ctx->r1) = 0;
    // 0x8002EB98: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EB9C: sb          $zero, 0x49DC($at)
    MEM_B(0X49DC, ctx->r1) = 0;
    // 0x8002EBA0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EBA4: swc1        $f0, 0x49D4($at)
    MEM_W(0X49D4, ctx->r1) = ctx->f0.u32l;
    // 0x8002EBA8: j           L_8002EC64
    // 0x8002EBAC: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
        goto L_8002EC64;
    // 0x8002EBAC: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
L_8002EBB0:
    // 0x8002EBB0: lw          $v1, 0x3C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3C);
    // 0x8002EBB4: bne         $v1, $v0, L_8002EC04
    if (ctx->r3 != ctx->r2) {
        // 0x8002EBB8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002EC04;
    }
    // 0x8002EBB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002EBBC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002EBC0: ldc1        $f2, -0x2858($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2858);
    // 0x8002EBC4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EBC8: sb          $v0, 0x49B6($at)
    MEM_B(0X49B6, ctx->r1) = ctx->r2;
    // 0x8002EBCC: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8002EBD0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8002EBD4: nop

    // 0x8002EBD8: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x8002EBDC: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8002EBE0: addiu       $v0, $zero, 0x8C
    ctx->r2 = ADD32(0, 0X8C);
    // 0x8002EBE4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EBE8: sb          $zero, 0x49B5($at)
    MEM_B(0X49B5, ctx->r1) = 0;
    // 0x8002EBEC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EBF0: sw          $v0, 0x49C4($at)
    MEM_W(0X49C4, ctx->r1) = ctx->r2;
    // 0x8002EBF4: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8002EBF8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EBFC: j           L_8002EC30
    // 0x8002EC00: swc1        $f2, 0x49BC($at)
    MEM_W(0X49BC, ctx->r1) = ctx->f2.u32l;
        goto L_8002EC30;
    // 0x8002EC00: swc1        $f2, 0x49BC($at)
    MEM_W(0X49BC, ctx->r1) = ctx->f2.u32l;
L_8002EC04:
    // 0x8002EC04: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EC08: sb          $v0, 0x49B5($at)
    MEM_B(0X49B5, ctx->r1) = ctx->r2;
    // 0x8002EC0C: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x8002EC10: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EC14: sw          $v0, 0x49C4($at)
    MEM_W(0X49C4, ctx->r1) = ctx->r2;
    // 0x8002EC18: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8002EC1C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002EC20: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EC24: sb          $zero, 0x49B6($at)
    MEM_B(0X49B6, ctx->r1) = 0;
    // 0x8002EC28: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EC2C: sw          $v0, 0x49BC($at)
    MEM_W(0X49BC, ctx->r1) = ctx->r2;
L_8002EC30:
    // 0x8002EC30: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002EC34: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002EC38: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002EC3C: addiu       $a0, $a0, 0x4640
    ctx->r4 = ADD32(ctx->r4, 0X4640);
    // 0x8002EC40: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    // 0x8002EC44: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EC48: sb          $zero, 0x49D8($at)
    MEM_B(0X49D8, ctx->r1) = 0;
    // 0x8002EC4C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EC50: sb          $zero, 0x49DB($at)
    MEM_B(0X49DB, ctx->r1) = 0;
    // 0x8002EC54: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EC58: sb          $zero, 0x49DA($at)
    MEM_B(0X49DA, ctx->r1) = 0;
    // 0x8002EC5C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EC60: swc1        $f0, 0x49D0($at)
    MEM_W(0X49D0, ctx->r1) = ctx->f0.u32l;
L_8002EC64:
    // 0x8002EC64: jal         0x8000C4EC
    // 0x8002EC68: nop

    func_8000C4EC(rdram, ctx);
        goto after_0;
    // 0x8002EC68: nop

    after_0:
    // 0x8002EC6C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002EC70: jr          $ra
    // 0x8002EC74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002EC74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002EC78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EC78: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8002EC7C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8002EC80: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x8002EC84: andi        $a1, $s5, 0xFF
    ctx->r5 = ctx->r21 & 0XFF;
    // 0x8002EC88: sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5 << 1);
    // 0x8002EC8C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8002EC90: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8002EC94: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8002EC98: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8002EC9C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8002ECA0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8002ECA4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8002ECA8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8002ECAC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8002ECB0: sdc1        $f30, 0x78($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X78, ctx->r29);
    // 0x8002ECB4: sdc1        $f28, 0x70($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X70, ctx->r29);
    // 0x8002ECB8: sdc1        $f26, 0x68($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X68, ctx->r29);
    // 0x8002ECBC: sdc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X60, ctx->r29);
    // 0x8002ECC0: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x8002ECC4: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x8002ECC8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002ECCC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8002ECD0: lbu         $v0, 0x49DA($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X49DA);
    // 0x8002ECD4: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8002ECD8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8002ECDC: lb          $v1, 0x49B5($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X49B5);
    // 0x8002ECE0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002ECE4: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8002ECE8: sb          $zero, 0x49DA($at)
    MEM_B(0X49DA, ctx->r1) = 0;
    // 0x8002ECEC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002ECF0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8002ECF4: sb          $v0, 0x49DB($at)
    MEM_B(0X49DB, ctx->r1) = ctx->r2;
    // 0x8002ECF8: beq         $v1, $zero, L_8002F118
    if (ctx->r3 == 0) {
        // 0x8002ECFC: sll         $a1, $a1, 2
        ctx->r5 = S32(ctx->r5 << 2);
            goto L_8002F118;
    }
    // 0x8002ECFC: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x8002ED00: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8002ED04: addiu       $v1, $v1, 0x49C4
    ctx->r3 = ADD32(ctx->r3, 0X49C4);
    // 0x8002ED08: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x8002ED0C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002ED10: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8002ED14: bgtz        $v0, L_8002ED28
    if (SIGNED(ctx->r2) > 0) {
        // 0x8002ED18: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8002ED28;
    }
    // 0x8002ED18: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8002ED1C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002ED20: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8002ED24: sb          $zero, 0x49B5($at)
    MEM_B(0X49B5, ctx->r1) = 0;
L_8002ED28:
    // 0x8002ED28: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002ED2C: addiu       $v0, $v0, 0x49D0
    ctx->r2 = ADD32(ctx->r2, 0X49D0);
    // 0x8002ED30: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x8002ED34: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002ED38: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002ED3C: ldc1        $f0, -0x2850($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2850);
    // 0x8002ED40: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8002ED44: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x8002ED48: nop

    // 0x8002ED4C: bc1f        L_8002ED68
    if (!c1cs) {
        // 0x8002ED50: nop
    
            goto L_8002ED68;
    }
    // 0x8002ED50: nop

    // 0x8002ED54: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002ED58: ldc1        $f0, -0x2848($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2848);
    // 0x8002ED5C: sub.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
    // 0x8002ED60: j           L_8002ED74
    // 0x8002ED64: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
        goto L_8002ED74;
    // 0x8002ED64: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
L_8002ED68:
    // 0x8002ED68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002ED6C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002ED70: nop

L_8002ED74:
    // 0x8002ED74: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8002ED78: andi        $s1, $s5, 0xFF
    ctx->r17 = ctx->r21 & 0XFF;
    // 0x8002ED7C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002ED80: addiu       $v0, $v0, 0x49C4
    ctx->r2 = ADD32(ctx->r2, 0X49C4);
    // 0x8002ED84: sll         $a0, $s1, 2
    ctx->r4 = S32(ctx->r17 << 2);
    // 0x8002ED88: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8002ED8C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002ED90: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x8002ED94: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002ED98: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002ED9C: sub.s       $f22, $f0, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8002EDA0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002EDA4: nop

    // 0x8002EDA8: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8002EDAC: nop

    // 0x8002EDB0: nop

    // 0x8002EDB4: bc1f        L_8002EFAC
    if (!c1cs) {
        // 0x8002EDB8: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8002EFAC;
    }
    // 0x8002EDB8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8002EDBC: addu        $s2, $s1, $zero
    ctx->r18 = ADD32(ctx->r17, 0);
    // 0x8002EDC0: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8002EDC4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002EDC8: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8002EDCC: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8002EDD0: addiu       $s1, $s1, 0x6E80
    ctx->r17 = ADD32(ctx->r17, 0X6E80);
    // 0x8002EDD4: addiu       $s4, $s1, 0x4
    ctx->r20 = ADD32(ctx->r17, 0X4);
    // 0x8002EDD8: sll         $fp, $s2, 1
    ctx->r30 = S32(ctx->r18 << 1);
    // 0x8002EDDC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8002EDE0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002EDE4: addiu       $v0, $v0, 0x6FA0
    ctx->r2 = ADD32(ctx->r2, 0X6FA0);
    // 0x8002EDE8: addu        $s7, $s3, $v0
    ctx->r23 = ADD32(ctx->r19, ctx->r2);
    // 0x8002EDEC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002EDF0: addiu       $v0, $v0, 0x49BC
    ctx->r2 = ADD32(ctx->r2, 0X49BC);
    // 0x8002EDF4: addu        $s6, $s3, $v0
    ctx->r22 = ADD32(ctx->r19, ctx->r2);
L_8002EDF8:
    // 0x8002EDF8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8002EDFC: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x8002EE00: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002EE04: lwc1        $f2, 0x0($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8002EE08: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8002EE0C: sub.s       $f22, $f2, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8002EE10: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002EE14: nop

    // 0x8002EE18: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8002EE1C: nop

    // 0x8002EE20: nop

    // 0x8002EE24: bc1f        L_8002EEF8
    if (!c1cs) {
        // 0x8002EE28: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_8002EEF8;
    }
    // 0x8002EE28: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x8002EE2C: c.le.s      $f30, $f22
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f30.fl <= ctx->f22.fl;
    // 0x8002EE30: nop

    // 0x8002EE34: nop

    // 0x8002EE38: bc1f        L_8002EE74
    if (!c1cs) {
        // 0x8002EE3C: andi        $v1, $s0, 0xFF
        ctx->r3 = ctx->r16 & 0XFF;
            goto L_8002EE74;
    }
    // 0x8002EE3C: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // 0x8002EE40: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8002EE44: addu        $v0, $v1, $s1
    ctx->r2 = ADD32(ctx->r3, ctx->r17);
    // 0x8002EE48: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002EE4C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8002EE50: div.s       $f28, $f0, $f30
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f28.fl = DIV_S(ctx->f0.fl, ctx->f30.fl);
    // 0x8002EE54: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x8002EE58: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002EE5C: mul.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x8002EE60: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8002EE64: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002EE68: div.s       $f26, $f2, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f26.fl = DIV_S(ctx->f2.fl, ctx->f30.fl);
    // 0x8002EE6C: j           L_8002EE90
    // 0x8002EE70: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
        goto L_8002EE90;
    // 0x8002EE70: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
L_8002EE74:
    // 0x8002EE74: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8002EE78: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
    // 0x8002EE7C: lwc1        $f28, 0x0($v1)
    ctx->f28.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002EE80: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x8002EE84: lwc1        $f26, 0x0($v0)
    ctx->f26.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002EE88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002EE8C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
L_8002EE90:
    // 0x8002EE90: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002EE94: lwc1        $f12, 0x7038($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7038);
    // 0x8002EE98: jal         0x80060400
    // 0x8002EE9C: mul.s       $f12, $f22, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f12.fl);
    cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8002EE9C: mul.s       $f12, $f22, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f12.fl);
    after_0:
    // 0x8002EEA0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002EEA4: lwc1        $f12, 0x7038($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7038);
    // 0x8002EEA8: mul.s       $f12, $f22, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f12.fl);
    // 0x8002EEAC: jal         0x80061290
    // 0x8002EEB0: mul.s       $f20, $f0, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8002EEB0: mul.s       $f20, $f0, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    after_1:
    // 0x8002EEB4: nop

    // 0x8002EEB8: mul.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8002EEBC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002EEC0: lwc1        $f12, 0x7038($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7038);
    // 0x8002EEC4: mul.s       $f12, $f22, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f12.fl);
    // 0x8002EEC8: jal         0x80061290
    // 0x8002EECC: sub.s       $f24, $f20, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f20.fl - ctx->f0.fl;
    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8002EECC: sub.s       $f24, $f20, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f20.fl - ctx->f0.fl;
    after_2:
    // 0x8002EED0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002EED4: lwc1        $f12, 0x7038($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7038);
    // 0x8002EED8: mul.s       $f12, $f22, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f12.fl);
    // 0x8002EEDC: jal         0x80060400
    // 0x8002EEE0: mul.s       $f20, $f0, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x8002EEE0: mul.s       $f20, $f0, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    after_3:
    // 0x8002EEE4: nop

    // 0x8002EEE8: mul.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8002EEEC: mov.s       $f28, $f24
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    ctx->f28.fl = ctx->f24.fl;
    // 0x8002EEF0: j           L_8002EF1C
    // 0x8002EEF4: add.s       $f26, $f20, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = ctx->f20.fl + ctx->f0.fl;
        goto L_8002EF1C;
    // 0x8002EEF4: add.s       $f26, $f20, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = ctx->f20.fl + ctx->f0.fl;
L_8002EEF8:
    // 0x8002EEF8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8002EEFC: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
    // 0x8002EF00: lwc1        $f28, 0x0($v1)
    ctx->f28.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002EF04: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x8002EF08: lwc1        $f26, 0x0($v0)
    ctx->f26.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002EF0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002EF10: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EF14: addu        $at, $at, $fp
    ctx->r1 = ADD32(ctx->r1, ctx->r30);
    // 0x8002EF18: sb          $v0, 0x49DA($at)
    MEM_B(0X49DA, ctx->r1) = ctx->r2;
L_8002EF1C:
    // 0x8002EF1C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8002EF20: lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X0);
    // 0x8002EF24: lw          $a3, 0x0($s6)
    ctx->r7 = MEM_W(ctx->r22, 0X0);
    // 0x8002EF28: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EF2C: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x8002EF30: lwc1        $f0, 0x49D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X49D0);
    // 0x8002EF34: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x8002EF38: trunc.w.s   $f2, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    ctx->f2.u32l = TRUNC_W_S(ctx->f28.fl);
    // 0x8002EF3C: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002EF40: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8002EF44: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002EF48: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8002EF4C: nop

    // 0x8002EF50: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002EF54: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8002EF58: trunc.w.s   $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    ctx->f0.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x8002EF5C: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8002EF60: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8002EF64: addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // 0x8002EF68: lbu         $v1, 0x49CC($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X49CC);
    // 0x8002EF6C: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x8002EF70: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8002EF74: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x8002EF78: nop

    // 0x8002EF7C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002EF80: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8002EF84: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002EF88: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8002EF8C: jal         0x8002E658
    // 0x8002EF90: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_8002E658(rdram, ctx);
        goto after_4;
    // 0x8002EF90: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_4:
    // 0x8002EF94: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x8002EF98: sltiu       $v0, $v0, 0xE
    ctx->r2 = ctx->r2 < 0XE ? 1 : 0;
    // 0x8002EF9C: bne         $v0, $zero, L_8002EDF8
    if (ctx->r2 != 0) {
        // 0x8002EFA0: andi        $a1, $s5, 0xFF
        ctx->r5 = ctx->r21 & 0XFF;
            goto L_8002EDF8;
    }
    // 0x8002EFA0: andi        $a1, $s5, 0xFF
    ctx->r5 = ctx->r21 & 0XFF;
    // 0x8002EFA4: j           L_8002F034
    // 0x8002EFA8: nop

        goto L_8002F034;
    // 0x8002EFA8: nop

L_8002EFAC:
    // 0x8002EFAC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002EFB0: addiu       $v0, $v0, 0x49BC
    ctx->r2 = ADD32(ctx->r2, 0X49BC);
    // 0x8002EFB4: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x8002EFB8: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x8002EFBC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002EFC0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8002EFC4: lwc1        $f24, 0x6FA0($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X6FA0);
    // 0x8002EFC8: cvt.s.w     $f24, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    ctx->f24.fl = CVT_S_W(ctx->f24.u32l);
    // 0x8002EFCC: addiu       $v1, $a3, -0x1
    ctx->r3 = ADD32(ctx->r7, -0X1);
    // 0x8002EFD0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8002EFD4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002EFD8: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8002EFDC: lwc1        $f0, 0x49D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X49D0);
    // 0x8002EFE0: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8002EFE4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8002EFE8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8002EFEC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8002EFF0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002EFF4: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8002EFF8: lbu         $v0, 0x49CC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X49CC);
    // 0x8002EFFC: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x8002F000: nop

    // 0x8002F004: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002F008: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8002F00C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8002F010: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002F014: jal         0x8002E658
    // 0x8002F018: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_8002E658(rdram, ctx);
        goto after_5;
    // 0x8002F018: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_5:
    // 0x8002F01C: sll         $v1, $s1, 1
    ctx->r3 = S32(ctx->r17 << 1);
    // 0x8002F020: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002F024: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002F028: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8002F02C: sb          $v0, 0x49DA($at)
    MEM_B(0X49DA, ctx->r1) = ctx->r2;
    // 0x8002F030: andi        $a1, $s5, 0xFF
    ctx->r5 = ctx->r21 & 0XFF;
L_8002F034:
    // 0x8002F034: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8002F038: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8002F03C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002F040: lbu         $v1, 0x49DB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X49DB);
    // 0x8002F044: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8002F048: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8002F04C: lbu         $a0, 0x49DA($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X49DA);
    // 0x8002F050: beq         $v1, $a0, L_8002F118
    if (ctx->r3 == ctx->r4) {
        // 0x8002F054: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002F118;
    }
    // 0x8002F054: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002F058: beq         $a0, $v0, L_8002F070
    if (ctx->r4 == ctx->r2) {
        // 0x8002F05C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8002F070;
    }
    // 0x8002F05C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002F060: beq         $a0, $v0, L_8002F0BC
    if (ctx->r4 == ctx->r2) {
        // 0x8002F064: nop
    
            goto L_8002F0BC;
    }
    // 0x8002F064: nop

    // 0x8002F068: j           L_8002F118
    // 0x8002F06C: nop

        goto L_8002F118;
    // 0x8002F06C: nop

L_8002F070:
    // 0x8002F070: bne         $a1, $zero, L_8002F08C
    if (ctx->r5 != 0) {
        // 0x8002F074: nop
    
            goto L_8002F08C;
    }
    // 0x8002F074: nop

    // 0x8002F078: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8002F07C: lbu         $a1, 0x49D8($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X49D8);
    // 0x8002F080: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002F084: j           L_8002F09C
    // 0x8002F088: addiu       $a0, $a0, 0x4640
    ctx->r4 = ADD32(ctx->r4, 0X4640);
        goto L_8002F09C;
    // 0x8002F088: addiu       $a0, $a0, 0x4640
    ctx->r4 = ADD32(ctx->r4, 0X4640);
L_8002F08C:
    // 0x8002F08C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8002F090: lbu         $a1, 0x49D9($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X49D9);
    // 0x8002F094: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002F098: addiu       $a0, $a0, 0x4660
    ctx->r4 = ADD32(ctx->r4, 0X4660);
L_8002F09C:
    // 0x8002F09C: jal         0x8000C4EC
    // 0x8002F0A0: addiu       $a1, $a1, 0x23
    ctx->r5 = ADD32(ctx->r5, 0X23);
    func_8000C4EC(rdram, ctx);
        goto after_6;
    // 0x8002F0A0: addiu       $a1, $a1, 0x23
    ctx->r5 = ADD32(ctx->r5, 0X23);
    after_6:
    // 0x8002F0A4: andi        $a0, $s5, 0xFF
    ctx->r4 = ctx->r21 & 0XFF;
    // 0x8002F0A8: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8002F0AC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8002F0B0: lbu         $v1, 0x49D8($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X49D8);
    // 0x8002F0B4: j           L_8002F104
    // 0x8002F0B8: sltiu       $v0, $v1, 0x4
    ctx->r2 = ctx->r3 < 0X4 ? 1 : 0;
        goto L_8002F104;
    // 0x8002F0B8: sltiu       $v0, $v1, 0x4
    ctx->r2 = ctx->r3 < 0X4 ? 1 : 0;
L_8002F0BC:
    // 0x8002F0BC: bne         $a1, $zero, L_8002F0D8
    if (ctx->r5 != 0) {
        // 0x8002F0C0: nop
    
            goto L_8002F0D8;
    }
    // 0x8002F0C0: nop

    // 0x8002F0C4: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8002F0C8: lbu         $a1, 0x49D8($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X49D8);
    // 0x8002F0CC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002F0D0: j           L_8002F0E8
    // 0x8002F0D4: addiu       $a0, $a0, 0x4640
    ctx->r4 = ADD32(ctx->r4, 0X4640);
        goto L_8002F0E8;
    // 0x8002F0D4: addiu       $a0, $a0, 0x4640
    ctx->r4 = ADD32(ctx->r4, 0X4640);
L_8002F0D8:
    // 0x8002F0D8: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8002F0DC: lbu         $a1, 0x49D9($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X49D9);
    // 0x8002F0E0: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002F0E4: addiu       $a0, $a0, 0x4660
    ctx->r4 = ADD32(ctx->r4, 0X4660);
L_8002F0E8:
    // 0x8002F0E8: jal         0x8000C4EC
    // 0x8002F0EC: addiu       $a1, $a1, 0x23
    ctx->r5 = ADD32(ctx->r5, 0X23);
    func_8000C4EC(rdram, ctx);
        goto after_7;
    // 0x8002F0EC: addiu       $a1, $a1, 0x23
    ctx->r5 = ADD32(ctx->r5, 0X23);
    after_7:
    // 0x8002F0F0: andi        $a0, $s5, 0xFF
    ctx->r4 = ctx->r21 & 0XFF;
    // 0x8002F0F4: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8002F0F8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8002F0FC: lbu         $v1, 0x49D8($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X49D8);
    // 0x8002F100: sltiu       $v0, $v1, 0x14
    ctx->r2 = ctx->r3 < 0X14 ? 1 : 0;
L_8002F104:
    // 0x8002F104: beq         $v0, $zero, L_8002F118
    if (ctx->r2 == 0) {
        // 0x8002F108: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8002F118;
    }
    // 0x8002F108: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8002F10C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002F110: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8002F114: sb          $v0, 0x49D8($at)
    MEM_B(0X49D8, ctx->r1) = ctx->r2;
L_8002F118:
    // 0x8002F118: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F11C: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8002F120: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8002F124: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8002F128: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8002F12C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8002F130: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8002F134: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8002F138: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8002F13C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8002F140: ldc1        $f30, 0x78($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X78);
    // 0x8002F144: ldc1        $f28, 0x70($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X70);
    // 0x8002F148: ldc1        $f26, 0x68($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X68);
    // 0x8002F14C: ldc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X60);
    // 0x8002F150: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x8002F154: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x8002F158: jr          $ra
    // 0x8002F15C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8002F15C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_8002F160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F160: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8002F164: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8002F168: addu        $fp, $a0, $zero
    ctx->r30 = ADD32(ctx->r4, 0);
    // 0x8002F16C: andi        $a1, $fp, 0xFF
    ctx->r5 = ctx->r30 & 0XFF;
    // 0x8002F170: sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5 << 1);
    // 0x8002F174: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8002F178: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8002F17C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8002F180: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8002F184: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8002F188: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8002F18C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8002F190: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8002F194: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8002F198: sdc1        $f30, 0x78($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X78, ctx->r29);
    // 0x8002F19C: sdc1        $f28, 0x70($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X70, ctx->r29);
    // 0x8002F1A0: sdc1        $f26, 0x68($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X68, ctx->r29);
    // 0x8002F1A4: sdc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X60, ctx->r29);
    // 0x8002F1A8: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x8002F1AC: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x8002F1B0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002F1B4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8002F1B8: lbu         $v0, 0x49DA($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X49DA);
    // 0x8002F1BC: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8002F1C0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8002F1C4: lb          $v1, 0x49B6($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X49B6);
    // 0x8002F1C8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002F1CC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8002F1D0: sb          $zero, 0x49DA($at)
    MEM_B(0X49DA, ctx->r1) = 0;
    // 0x8002F1D4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002F1D8: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8002F1DC: sb          $v0, 0x49DB($at)
    MEM_B(0X49DB, ctx->r1) = ctx->r2;
    // 0x8002F1E0: beq         $v1, $zero, L_8002F830
    if (ctx->r3 == 0) {
        // 0x8002F1E4: sll         $a1, $a1, 2
        ctx->r5 = S32(ctx->r5 << 2);
            goto L_8002F830;
    }
    // 0x8002F1E4: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x8002F1E8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002F1EC: addiu       $v0, $v0, 0x49C4
    ctx->r2 = ADD32(ctx->r2, 0X49C4);
    // 0x8002F1F0: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x8002F1F4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002F1F8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8002F1FC: bgtz        $v0, L_8002F210
    if (SIGNED(ctx->r2) > 0) {
        // 0x8002F200: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8002F210;
    }
    // 0x8002F200: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8002F204: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002F208: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8002F20C: sb          $zero, 0x49B6($at)
    MEM_B(0X49B6, ctx->r1) = 0;
L_8002F210:
    // 0x8002F210: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002F214: slti        $v0, $v0, 0x3D
    ctx->r2 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
    // 0x8002F218: bne         $v0, $zero, L_8002F270
    if (ctx->r2 != 0) {
        // 0x8002F21C: nop
    
            goto L_8002F270;
    }
    // 0x8002F21C: nop

    // 0x8002F220: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002F224: addiu       $v0, $v0, 0x49D0
    ctx->r2 = ADD32(ctx->r2, 0X49D0);
    // 0x8002F228: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x8002F22C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002F230: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002F234: ldc1        $f0, -0x2840($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2840);
    // 0x8002F238: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8002F23C: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x8002F240: nop

    // 0x8002F244: bc1f        L_8002F25C
    if (!c1cs) {
        // 0x8002F248: nop
    
            goto L_8002F25C;
    }
    // 0x8002F248: nop

    // 0x8002F24C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002F250: ldc1        $f0, -0x2838($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2838);
    // 0x8002F254: j           L_8002F2B0
    // 0x8002F258: sub.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
        goto L_8002F2B0;
    // 0x8002F258: sub.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
L_8002F25C:
    // 0x8002F25C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002F260: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002F264: nop

    // 0x8002F268: j           L_8002F2B8
    // 0x8002F26C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
        goto L_8002F2B8;
    // 0x8002F26C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_8002F270:
    // 0x8002F270: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002F274: addiu       $v0, $v0, 0x49D0
    ctx->r2 = ADD32(ctx->r2, 0X49D0);
    // 0x8002F278: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x8002F27C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002F280: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002F284: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002F288: nop

    // 0x8002F28C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8002F290: nop

    // 0x8002F294: nop

    // 0x8002F298: bc1f        L_8002F2BC
    if (!c1cs) {
        // 0x8002F29C: andi        $s1, $fp, 0xFF
        ctx->r17 = ctx->r30 & 0XFF;
            goto L_8002F2BC;
    }
    // 0x8002F29C: andi        $s1, $fp, 0xFF
    ctx->r17 = ctx->r30 & 0XFF;
    // 0x8002F2A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002F2A4: ldc1        $f2, -0x2830($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2830);
    // 0x8002F2A8: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8002F2AC: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
L_8002F2B0:
    // 0x8002F2B0: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8002F2B4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_8002F2B8:
    // 0x8002F2B8: andi        $s1, $fp, 0xFF
    ctx->r17 = ctx->r30 & 0XFF;
L_8002F2BC:
    // 0x8002F2BC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002F2C0: addiu       $v0, $v0, 0x49C4
    ctx->r2 = ADD32(ctx->r2, 0X49C4);
    // 0x8002F2C4: sll         $a0, $s1, 2
    ctx->r4 = S32(ctx->r17 << 2);
    // 0x8002F2C8: addu        $v1, $a0, $v0
    ctx->r3 = ADD32(ctx->r4, ctx->r2);
    // 0x8002F2CC: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x8002F2D0: slti        $v0, $a1, 0x3D
    ctx->r2 = SIGNED(ctx->r5) < 0X3D ? 1 : 0;
    // 0x8002F2D4: bne         $v0, $zero, L_8002F5DC
    if (ctx->r2 != 0) {
        // 0x8002F2D8: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8002F5DC;
    }
    // 0x8002F2D8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8002F2DC: addiu       $v0, $a1, -0x5A
    ctx->r2 = ADD32(ctx->r5, -0X5A);
    // 0x8002F2E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002F2E4: mtc1        $v0, $f22
    ctx->f22.u32l = ctx->r2;
    // 0x8002F2E8: nop

    // 0x8002F2EC: cvt.s.w     $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    ctx->f22.fl = CVT_S_W(ctx->f22.u32l);
    // 0x8002F2F0: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8002F2F4: nop

    // 0x8002F2F8: nop

    // 0x8002F2FC: bc1f        L_8002F500
    if (!c1cs) {
        // 0x8002F300: addu        $s2, $s1, $zero
        ctx->r18 = ADD32(ctx->r17, 0);
            goto L_8002F500;
    }
    // 0x8002F300: addu        $s2, $s1, $zero
    ctx->r18 = ADD32(ctx->r17, 0);
    // 0x8002F304: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8002F308: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002F30C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8002F310: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8002F314: addiu       $s1, $s1, 0x6EF0
    ctx->r17 = ADD32(ctx->r17, 0X6EF0);
    // 0x8002F318: addiu       $s4, $s1, 0x4
    ctx->r20 = ADD32(ctx->r17, 0X4);
    // 0x8002F31C: sll         $s7, $s2, 1
    ctx->r23 = S32(ctx->r18 << 1);
    // 0x8002F320: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002F324: addiu       $v0, $v0, 0x6FA0
    ctx->r2 = ADD32(ctx->r2, 0X6FA0);
    // 0x8002F328: addu        $s6, $s3, $v0
    ctx->r22 = ADD32(ctx->r19, ctx->r2);
    // 0x8002F32C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002F330: addiu       $v0, $v0, 0x49BC
    ctx->r2 = ADD32(ctx->r2, 0X49BC);
    // 0x8002F334: addu        $s5, $s3, $v0
    ctx->r21 = ADD32(ctx->r19, ctx->r2);
    // 0x8002F338: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
L_8002F33C:
    // 0x8002F33C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8002F340: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8002F344: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002F348: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8002F34C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002F350: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8002F354: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x8002F358: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002F35C: nop

    // 0x8002F360: sub.s       $f22, $f0, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8002F364: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002F368: nop

    // 0x8002F36C: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8002F370: nop

    // 0x8002F374: nop

    // 0x8002F378: bc1f        L_8002F44C
    if (!c1cs) {
        // 0x8002F37C: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_8002F44C;
    }
    // 0x8002F37C: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x8002F380: c.le.s      $f30, $f22
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f30.fl <= ctx->f22.fl;
    // 0x8002F384: nop

    // 0x8002F388: nop

    // 0x8002F38C: bc1f        L_8002F3C8
    if (!c1cs) {
        // 0x8002F390: andi        $v1, $s0, 0xFF
        ctx->r3 = ctx->r16 & 0XFF;
            goto L_8002F3C8;
    }
    // 0x8002F390: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // 0x8002F394: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8002F398: addu        $v0, $v1, $s1
    ctx->r2 = ADD32(ctx->r3, ctx->r17);
    // 0x8002F39C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002F3A0: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8002F3A4: div.s       $f26, $f0, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f26.fl = DIV_S(ctx->f0.fl, ctx->f30.fl);
    // 0x8002F3A8: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x8002F3AC: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002F3B0: mul.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x8002F3B4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8002F3B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002F3BC: div.s       $f24, $f2, $f30
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f24.fl = DIV_S(ctx->f2.fl, ctx->f30.fl);
    // 0x8002F3C0: j           L_8002F3E4
    // 0x8002F3C4: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
        goto L_8002F3E4;
    // 0x8002F3C4: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
L_8002F3C8:
    // 0x8002F3C8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8002F3CC: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
    // 0x8002F3D0: lwc1        $f26, 0x0($v1)
    ctx->f26.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002F3D4: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x8002F3D8: lwc1        $f24, 0x0($v0)
    ctx->f24.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002F3DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002F3E0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
L_8002F3E4:
    // 0x8002F3E4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002F3E8: lwc1        $f12, 0x703C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X703C);
    // 0x8002F3EC: jal         0x80060400
    // 0x8002F3F0: mul.s       $f12, $f22, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f12.fl);
    cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8002F3F0: mul.s       $f12, $f22, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f12.fl);
    after_0:
    // 0x8002F3F4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002F3F8: lwc1        $f12, 0x703C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X703C);
    // 0x8002F3FC: mul.s       $f12, $f22, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f12.fl);
    // 0x8002F400: jal         0x80061290
    // 0x8002F404: mul.s       $f20, $f0, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8002F404: mul.s       $f20, $f0, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    after_1:
    // 0x8002F408: nop

    // 0x8002F40C: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8002F410: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002F414: lwc1        $f12, 0x703C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X703C);
    // 0x8002F418: mul.s       $f12, $f22, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f12.fl);
    // 0x8002F41C: jal         0x80061290
    // 0x8002F420: sub.s       $f28, $f20, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = ctx->f20.fl - ctx->f0.fl;
    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8002F420: sub.s       $f28, $f20, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = ctx->f20.fl - ctx->f0.fl;
    after_2:
    // 0x8002F424: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002F428: lwc1        $f12, 0x703C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X703C);
    // 0x8002F42C: mul.s       $f12, $f22, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f12.fl);
    // 0x8002F430: jal         0x80060400
    // 0x8002F434: mul.s       $f20, $f0, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x8002F434: mul.s       $f20, $f0, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    after_3:
    // 0x8002F438: nop

    // 0x8002F43C: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8002F440: mov.s       $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    ctx->f26.fl = ctx->f28.fl;
    // 0x8002F444: j           L_8002F470
    // 0x8002F448: add.s       $f24, $f20, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f20.fl + ctx->f0.fl;
        goto L_8002F470;
    // 0x8002F448: add.s       $f24, $f20, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f20.fl + ctx->f0.fl;
L_8002F44C:
    // 0x8002F44C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8002F450: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
    // 0x8002F454: lwc1        $f26, 0x0($v1)
    ctx->f26.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002F458: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x8002F45C: lwc1        $f24, 0x0($v0)
    ctx->f24.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002F460: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002F464: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002F468: addu        $at, $at, $s7
    ctx->r1 = ADD32(ctx->r1, ctx->r23);
    // 0x8002F46C: sb          $v0, 0x49DA($at)
    MEM_B(0X49DA, ctx->r1) = ctx->r2;
L_8002F470:
    // 0x8002F470: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8002F474: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
    // 0x8002F478: lw          $a3, 0x0($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X0);
    // 0x8002F47C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002F480: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x8002F484: lwc1        $f0, 0x49D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X49D0);
    // 0x8002F488: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x8002F48C: trunc.w.s   $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    ctx->f2.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x8002F490: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002F494: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8002F498: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002F49C: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8002F4A0: nop

    // 0x8002F4A4: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002F4A8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8002F4AC: trunc.w.s   $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    ctx->f0.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x8002F4B0: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8002F4B4: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8002F4B8: addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // 0x8002F4BC: lbu         $v1, 0x49CC($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X49CC);
    // 0x8002F4C0: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x8002F4C4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8002F4C8: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x8002F4CC: nop

    // 0x8002F4D0: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002F4D4: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8002F4D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002F4DC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8002F4E0: jal         0x8002E658
    // 0x8002F4E4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_8002E658(rdram, ctx);
        goto after_4;
    // 0x8002F4E4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_4:
    // 0x8002F4E8: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x8002F4EC: sltiu       $v0, $v0, 0x16
    ctx->r2 = ctx->r2 < 0X16 ? 1 : 0;
    // 0x8002F4F0: bne         $v0, $zero, L_8002F33C
    if (ctx->r2 != 0) {
        // 0x8002F4F4: andi        $a1, $fp, 0xFF
        ctx->r5 = ctx->r30 & 0XFF;
            goto L_8002F33C;
    }
    // 0x8002F4F4: andi        $a1, $fp, 0xFF
    ctx->r5 = ctx->r30 & 0XFF;
    // 0x8002F4F8: j           L_8002F710
    // 0x8002F4FC: nop

        goto L_8002F710;
    // 0x8002F4FC: nop

L_8002F500:
    // 0x8002F500: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002F504: addiu       $v0, $v0, 0x49BC
    ctx->r2 = ADD32(ctx->r2, 0X49BC);
    // 0x8002F508: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x8002F50C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8002F510: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002F514: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8002F518: lwc1        $f28, 0x6FA0($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X6FA0);
    // 0x8002F51C: cvt.s.w     $f28, $f28
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    ctx->f28.fl = CVT_S_W(ctx->f28.u32l);
    // 0x8002F520: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8002F524: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002F528: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8002F52C: addiu       $s0, $s0, 0x49D0
    ctx->r16 = ADD32(ctx->r16, 0X49D0);
    // 0x8002F530: addu        $s0, $a0, $s0
    ctx->r16 = ADD32(ctx->r4, ctx->r16);
    // 0x8002F534: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x8002F538: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8002F53C: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8002F540: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8002F544: sub.s       $f2, $f28, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f28.fl - ctx->f2.fl;
    // 0x8002F548: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8002F54C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8002F550: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002F554: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8002F558: lbu         $v0, 0x49CC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X49CC);
    // 0x8002F55C: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8002F560: nop

    // 0x8002F564: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x8002F568: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8002F56C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8002F570: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8002F574: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002F578: jal         0x8002E658
    // 0x8002F57C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_8002E658(rdram, ctx);
        goto after_5;
    // 0x8002F57C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_5:
    // 0x8002F580: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8002F584: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002F588: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8002F58C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8002F590: add.s       $f28, $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f28.fl = ctx->f28.fl + ctx->f2.fl;
    // 0x8002F594: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8002F598: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002F59C: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8002F5A0: lbu         $v0, 0x49CC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X49CC);
    // 0x8002F5A4: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x8002F5A8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8002F5AC: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x8002F5B0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8002F5B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002F5B8: jal         0x8002E658
    // 0x8002F5BC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_8002E658(rdram, ctx);
        goto after_6;
    // 0x8002F5BC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_6:
    // 0x8002F5C0: sll         $v1, $s1, 1
    ctx->r3 = S32(ctx->r17 << 1);
    // 0x8002F5C4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002F5C8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002F5CC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8002F5D0: sb          $v0, 0x49DA($at)
    MEM_B(0X49DA, ctx->r1) = ctx->r2;
    // 0x8002F5D4: j           L_8002F710
    // 0x8002F5D8: andi        $a1, $fp, 0xFF
    ctx->r5 = ctx->r30 & 0XFF;
        goto L_8002F710;
    // 0x8002F5D8: andi        $a1, $fp, 0xFF
    ctx->r5 = ctx->r30 & 0XFF;
L_8002F5DC:
    // 0x8002F5DC: addu        $s7, $v1, $zero
    ctx->r23 = ADD32(ctx->r3, 0);
    // 0x8002F5E0: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8002F5E4: addiu       $s2, $s2, 0x6EF0
    ctx->r18 = ADD32(ctx->r18, 0X6EF0);
    // 0x8002F5E8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002F5EC: addiu       $v0, $v0, 0x6FA0
    ctx->r2 = ADD32(ctx->r2, 0X6FA0);
    // 0x8002F5F0: addu        $s6, $a0, $v0
    ctx->r22 = ADD32(ctx->r4, ctx->r2);
    // 0x8002F5F4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002F5F8: addiu       $v0, $v0, 0x49BC
    ctx->r2 = ADD32(ctx->r2, 0X49BC);
    // 0x8002F5FC: addu        $s5, $a0, $v0
    ctx->r21 = ADD32(ctx->r4, ctx->r2);
    // 0x8002F600: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002F604: addiu       $v0, $v0, 0x49D0
    ctx->r2 = ADD32(ctx->r2, 0X49D0);
    // 0x8002F608: addu        $s4, $a0, $v0
    ctx->r20 = ADD32(ctx->r4, ctx->r2);
    // 0x8002F60C: sll         $s3, $s1, 1
    ctx->r19 = S32(ctx->r17 << 1);
L_8002F610:
    // 0x8002F610: lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X0);
    // 0x8002F614: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8002F618: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002F61C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002F620: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8002F624: mtc1        $v0, $f22
    ctx->f22.u32l = ctx->r2;
    // 0x8002F628: nop

    // 0x8002F62C: cvt.s.w     $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    ctx->f22.fl = CVT_S_W(ctx->f22.u32l);
    // 0x8002F630: div.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8002F634: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x8002F638: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002F63C: ldc1        $f2, -0x2828($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2828);
    // 0x8002F640: sll         $v1, $a1, 3
    ctx->r3 = S32(ctx->r5 << 3);
    // 0x8002F644: addu        $v0, $v1, $s2
    ctx->r2 = ADD32(ctx->r3, ctx->r18);
    // 0x8002F648: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002F64C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8002F650: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8002F654: cvt.d.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f4.d = CVT_D_S(ctx->f4.fl);
    // 0x8002F658: mul.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8002F65C: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x8002F660: addiu       $t0, $t0, 0x6EF4
    ctx->r8 = ADD32(ctx->r8, 0X6EF4);
    // 0x8002F664: lw          $a3, 0x0($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X0);
    // 0x8002F668: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8002F66C: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002F670: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8002F674: lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X0);
    // 0x8002F678: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8002F67C: mul.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f0.d);
    // 0x8002F680: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8002F684: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8002F688: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002F68C: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8002F690: lbu         $v0, 0x49CC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X49CC);
    // 0x8002F694: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8002F698: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8002F69C: cvt.s.d     $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f26.fl = CVT_S_D(ctx->f4.d);
    // 0x8002F6A0: cvt.s.d     $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f24.fl = CVT_S_D(ctx->f2.d);
    // 0x8002F6A4: trunc.w.s   $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    ctx->f0.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x8002F6A8: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8002F6AC: nop

    // 0x8002F6B0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002F6B4: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8002F6B8: nop

    // 0x8002F6BC: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002F6C0: trunc.w.s   $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    ctx->f0.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x8002F6C4: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8002F6C8: nop

    // 0x8002F6CC: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x8002F6D0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8002F6D4: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x8002F6D8: nop

    // 0x8002F6DC: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002F6E0: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8002F6E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002F6E8: jal         0x8002E658
    // 0x8002F6EC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    func_8002E658(rdram, ctx);
        goto after_7;
    // 0x8002F6EC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_7:
    // 0x8002F6F0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002F6F4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002F6F8: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x8002F6FC: sb          $v0, 0x49DA($at)
    MEM_B(0X49DA, ctx->r1) = ctx->r2;
    // 0x8002F700: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x8002F704: sltiu       $v0, $v0, 0x16
    ctx->r2 = ctx->r2 < 0X16 ? 1 : 0;
    // 0x8002F708: bne         $v0, $zero, L_8002F610
    if (ctx->r2 != 0) {
        // 0x8002F70C: andi        $a1, $fp, 0xFF
        ctx->r5 = ctx->r30 & 0XFF;
            goto L_8002F610;
    }
    // 0x8002F70C: andi        $a1, $fp, 0xFF
    ctx->r5 = ctx->r30 & 0XFF;
L_8002F710:
    // 0x8002F710: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8002F714: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8002F718: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002F71C: lbu         $v1, 0x49DB($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X49DB);
    // 0x8002F720: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8002F724: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8002F728: lbu         $a0, 0x49DA($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X49DA);
    // 0x8002F72C: beq         $v1, $a0, L_8002F830
    if (ctx->r3 == ctx->r4) {
        // 0x8002F730: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8002F830;
    }
    // 0x8002F730: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002F734: beq         $a0, $v0, L_8002F7B4
    if (ctx->r4 == ctx->r2) {
        // 0x8002F738: slti        $v0, $a0, 0x3
        ctx->r2 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_8002F7B4;
    }
    // 0x8002F738: slti        $v0, $a0, 0x3
    ctx->r2 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x8002F73C: beq         $v0, $zero, L_8002F754
    if (ctx->r2 == 0) {
        // 0x8002F740: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002F754;
    }
    // 0x8002F740: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002F744: beq         $a0, $v0, L_8002F768
    if (ctx->r4 == ctx->r2) {
        // 0x8002F748: nop
    
            goto L_8002F768;
    }
    // 0x8002F748: nop

    // 0x8002F74C: j           L_8002F830
    // 0x8002F750: nop

        goto L_8002F830;
    // 0x8002F750: nop

L_8002F754:
    // 0x8002F754: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002F758: beq         $a0, $v0, L_8002F814
    if (ctx->r4 == ctx->r2) {
        // 0x8002F75C: nop
    
            goto L_8002F814;
    }
    // 0x8002F75C: nop

    // 0x8002F760: j           L_8002F830
    // 0x8002F764: nop

        goto L_8002F830;
    // 0x8002F764: nop

L_8002F768:
    // 0x8002F768: bne         $a1, $zero, L_8002F784
    if (ctx->r5 != 0) {
        // 0x8002F76C: nop
    
            goto L_8002F784;
    }
    // 0x8002F76C: nop

    // 0x8002F770: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8002F774: lbu         $a1, 0x49D8($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X49D8);
    // 0x8002F778: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002F77C: j           L_8002F794
    // 0x8002F780: addiu       $a0, $a0, 0x4640
    ctx->r4 = ADD32(ctx->r4, 0X4640);
        goto L_8002F794;
    // 0x8002F780: addiu       $a0, $a0, 0x4640
    ctx->r4 = ADD32(ctx->r4, 0X4640);
L_8002F784:
    // 0x8002F784: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8002F788: lbu         $a1, 0x49D9($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X49D9);
    // 0x8002F78C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002F790: addiu       $a0, $a0, 0x4660
    ctx->r4 = ADD32(ctx->r4, 0X4660);
L_8002F794:
    // 0x8002F794: jal         0x8000C4EC
    // 0x8002F798: addiu       $a1, $a1, 0x23
    ctx->r5 = ADD32(ctx->r5, 0X23);
    func_8000C4EC(rdram, ctx);
        goto after_8;
    // 0x8002F798: addiu       $a1, $a1, 0x23
    ctx->r5 = ADD32(ctx->r5, 0X23);
    after_8:
    // 0x8002F79C: andi        $a0, $fp, 0xFF
    ctx->r4 = ctx->r30 & 0XFF;
    // 0x8002F7A0: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8002F7A4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8002F7A8: lbu         $v1, 0x49D8($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X49D8);
    // 0x8002F7AC: j           L_8002F7FC
    // 0x8002F7B0: sltiu       $v0, $v1, 0x4
    ctx->r2 = ctx->r3 < 0X4 ? 1 : 0;
        goto L_8002F7FC;
    // 0x8002F7B0: sltiu       $v0, $v1, 0x4
    ctx->r2 = ctx->r3 < 0X4 ? 1 : 0;
L_8002F7B4:
    // 0x8002F7B4: bne         $a1, $zero, L_8002F7D0
    if (ctx->r5 != 0) {
        // 0x8002F7B8: nop
    
            goto L_8002F7D0;
    }
    // 0x8002F7B8: nop

    // 0x8002F7BC: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8002F7C0: lbu         $a1, 0x49D8($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X49D8);
    // 0x8002F7C4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002F7C8: j           L_8002F7E0
    // 0x8002F7CC: addiu       $a0, $a0, 0x4640
    ctx->r4 = ADD32(ctx->r4, 0X4640);
        goto L_8002F7E0;
    // 0x8002F7CC: addiu       $a0, $a0, 0x4640
    ctx->r4 = ADD32(ctx->r4, 0X4640);
L_8002F7D0:
    // 0x8002F7D0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8002F7D4: lbu         $a1, 0x49D9($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X49D9);
    // 0x8002F7D8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002F7DC: addiu       $a0, $a0, 0x4660
    ctx->r4 = ADD32(ctx->r4, 0X4660);
L_8002F7E0:
    // 0x8002F7E0: jal         0x8000C4EC
    // 0x8002F7E4: addiu       $a1, $a1, 0x23
    ctx->r5 = ADD32(ctx->r5, 0X23);
    func_8000C4EC(rdram, ctx);
        goto after_9;
    // 0x8002F7E4: addiu       $a1, $a1, 0x23
    ctx->r5 = ADD32(ctx->r5, 0X23);
    after_9:
    // 0x8002F7E8: andi        $a0, $fp, 0xFF
    ctx->r4 = ctx->r30 & 0XFF;
    // 0x8002F7EC: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8002F7F0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8002F7F4: lbu         $v1, 0x49D8($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X49D8);
    // 0x8002F7F8: sltiu       $v0, $v1, 0x14
    ctx->r2 = ctx->r3 < 0X14 ? 1 : 0;
L_8002F7FC:
    // 0x8002F7FC: beq         $v0, $zero, L_8002F830
    if (ctx->r2 == 0) {
        // 0x8002F800: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8002F830;
    }
    // 0x8002F800: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8002F804: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002F808: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8002F80C: j           L_8002F830
    // 0x8002F810: sb          $v0, 0x49D8($at)
    MEM_B(0X49D8, ctx->r1) = ctx->r2;
        goto L_8002F830;
    // 0x8002F810: sb          $v0, 0x49D8($at)
    MEM_B(0X49D8, ctx->r1) = ctx->r2;
L_8002F814:
    // 0x8002F814: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002F818: bne         $a1, $zero, L_8002F828
    if (ctx->r5 != 0) {
        // 0x8002F81C: addiu       $a0, $a0, 0x4660
        ctx->r4 = ADD32(ctx->r4, 0X4660);
            goto L_8002F828;
    }
    // 0x8002F81C: addiu       $a0, $a0, 0x4660
    ctx->r4 = ADD32(ctx->r4, 0X4660);
    // 0x8002F820: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8002F824: addiu       $a0, $a0, 0x4640
    ctx->r4 = ADD32(ctx->r4, 0X4640);
L_8002F828:
    // 0x8002F828: jal         0x8000C4EC
    // 0x8002F82C: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    func_8000C4EC(rdram, ctx);
        goto after_10;
    // 0x8002F82C: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    after_10:
L_8002F830:
    // 0x8002F830: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F834: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8002F838: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8002F83C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8002F840: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8002F844: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8002F848: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8002F84C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8002F850: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8002F854: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8002F858: ldc1        $f30, 0x78($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X78);
    // 0x8002F85C: ldc1        $f28, 0x70($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X70);
    // 0x8002F860: ldc1        $f26, 0x68($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X68);
    // 0x8002F864: ldc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X60);
    // 0x8002F868: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x8002F86C: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x8002F870: jr          $ra
    // 0x8002F874: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8002F874: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_8002F878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002F87C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002F880: jal         0x8002EC78
    // 0x8002F884: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002EC78(rdram, ctx);
        goto after_0;
    // 0x8002F884: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // 0x8002F888: jal         0x8002F160
    // 0x8002F88C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002F160(rdram, ctx);
        goto after_1;
    // 0x8002F88C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // 0x8002F890: jal         0x8002EC78
    // 0x8002F894: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002EC78(rdram, ctx);
        goto after_2;
    // 0x8002F894: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x8002F898: jal         0x8002F160
    // 0x8002F89C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002F160(rdram, ctx);
        goto after_3;
    // 0x8002F89C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8002F8A0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002F8A4: jr          $ra
    // 0x8002F8A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002F8A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002F8AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F8AC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002F8B0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8002F8B4: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x8002F8B8: addiu       $s1, $s1, 0x7B71
    ctx->r17 = ADD32(ctx->r17, 0X7B71);
    // 0x8002F8BC: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8002F8C0: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x8002F8C4: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8002F8C8: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8002F8CC: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8002F8D0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8002F8D4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8002F8D8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002F8DC: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x8002F8E0: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x8002F8E4: beq         $a0, $zero, L_8002F8FC
    if (ctx->r4 == 0) {
        // 0x8002F8E8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002F8FC;
    }
    // 0x8002F8E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002F8EC: beq         $a0, $v0, L_8002FBA8
    if (ctx->r4 == ctx->r2) {
        // 0x8002F8F0: nop
    
            goto L_8002FBA8;
    }
    // 0x8002F8F0: nop

    // 0x8002F8F4: j           L_8002FBD4
    // 0x8002F8F8: nop

        goto L_8002FBD4;
    // 0x8002F8F8: nop

L_8002F8FC:
    // 0x8002F8FC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002F900: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002F904: addiu       $v0, $v0, 0x6ACA
    ctx->r2 = ADD32(ctx->r2, 0X6ACA);
    // 0x8002F908: addiu       $s0, $v0, -0x2A
    ctx->r16 = ADD32(ctx->r2, -0X2A);
    // 0x8002F90C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8002F910: sb          $v1, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r3;
    // 0x8002F914: jal         0x80017760
    // 0x8002F918: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    func_80017760(rdram, ctx);
        goto after_0;
    // 0x8002F918: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_0:
    // 0x8002F91C: addiu       $s5, $zero, 0xC0
    ctx->r21 = ADD32(0, 0XC0);
    // 0x8002F920: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x8002F924: addiu       $s1, $s1, -0x57C0
    ctx->r17 = ADD32(ctx->r17, -0X57C0);
    // 0x8002F928: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002F92C: sh          $s5, 0x6AAA($at)
    MEM_H(0X6AAA, ctx->r1) = ctx->r21;
    // 0x8002F930: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002F934: sh          $s5, 0x6AAE($at)
    MEM_H(0X6AAE, ctx->r1) = ctx->r21;
    // 0x8002F938: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002F93C: sw          $s1, 0x6AB0($at)
    MEM_W(0X6AB0, ctx->r1) = ctx->r17;
    // 0x8002F940: jal         0x80066D30
    // 0x8002F944: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066D30(rdram, ctx);
        goto after_1;
    // 0x8002F944: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8002F948: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002F94C: addiu       $v0, $v0, 0x354A
    ctx->r2 = ADD32(ctx->r2, 0X354A);
    // 0x8002F950: addiu       $s0, $v0, -0x2A
    ctx->r16 = ADD32(ctx->r2, -0X2A);
    // 0x8002F954: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8002F958: jal         0x80017760
    // 0x8002F95C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    func_80017760(rdram, ctx);
        goto after_2;
    // 0x8002F95C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_2:
    // 0x8002F960: addiu       $v0, $zero, 0x300
    ctx->r2 = ADD32(0, 0X300);
    // 0x8002F964: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002F968: sh          $s5, 0x352A($at)
    MEM_H(0X352A, ctx->r1) = ctx->r21;
    // 0x8002F96C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002F970: sh          $s5, 0x352E($at)
    MEM_H(0X352E, ctx->r1) = ctx->r21;
    // 0x8002F974: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002F978: sh          $v0, 0x352C($at)
    MEM_H(0X352C, ctx->r1) = ctx->r2;
    // 0x8002F97C: jal         0x80066D30
    // 0x8002F980: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066D30(rdram, ctx);
        goto after_3;
    // 0x8002F980: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8002F984: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x8002F988: addiu       $a0, $a0, -0x1EC0
    ctx->r4 = ADD32(ctx->r4, -0X1EC0);
    // 0x8002F98C: addiu       $a1, $s1, -0x7800
    ctx->r5 = ADD32(ctx->r17, -0X7800);
    // 0x8002F990: jal         0x80006D98
    // 0x8002F994: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    func_80006D98(rdram, ctx);
        goto after_4;
    // 0x8002F994: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    after_4:
    // 0x8002F998: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x8002F99C: addiu       $v0, $v0, -0x7636
    ctx->r2 = ADD32(ctx->r2, -0X7636);
    // 0x8002F9A0: addiu       $s0, $v0, -0x2A
    ctx->r16 = ADD32(ctx->r2, -0X2A);
    // 0x8002F9A4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8002F9A8: jal         0x80017760
    // 0x8002F9AC: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    func_80017760(rdram, ctx);
        goto after_5;
    // 0x8002F9AC: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_5:
    // 0x8002F9B0: addiu       $s1, $zero, 0x600
    ctx->r17 = ADD32(0, 0X600);
    // 0x8002F9B4: addiu       $s2, $zero, 0x240
    ctx->r18 = ADD32(0, 0X240);
    // 0x8002F9B8: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x8002F9BC: addiu       $s4, $s4, -0x75C0
    ctx->r20 = ADD32(ctx->r20, -0X75C0);
    // 0x8002F9C0: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x8002F9C4: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x8002F9C8: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x8002F9CC: addiu       $s3, $s3, -0x2338
    ctx->r19 = ADD32(ctx->r19, -0X2338);
    // 0x8002F9D0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8002F9D4: sh          $s1, -0x765E($at)
    MEM_H(-0X765E, ctx->r1) = ctx->r17;
    // 0x8002F9D8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8002F9DC: sh          $zero, -0x765C($at)
    MEM_H(-0X765C, ctx->r1) = 0;
    // 0x8002F9E0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8002F9E4: sh          $s5, -0x7654($at)
    MEM_H(-0X7654, ctx->r1) = ctx->r21;
    // 0x8002F9E8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8002F9EC: sh          $s1, -0x765A($at)
    MEM_H(-0X765A, ctx->r1) = ctx->r17;
    // 0x8002F9F0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8002F9F4: sh          $s2, -0x7652($at)
    MEM_H(-0X7652, ctx->r1) = ctx->r18;
    // 0x8002F9F8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8002F9FC: sh          $s2, -0x7656($at)
    MEM_H(-0X7656, ctx->r1) = ctx->r18;
    // 0x8002FA00: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8002FA04: sw          $s4, -0x7650($at)
    MEM_W(-0X7650, ctx->r1) = ctx->r20;
    // 0x8002FA08: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8002FA0C: sb          $s7, -0x764A($at)
    MEM_B(-0X764A, ctx->r1) = ctx->r23;
    // 0x8002FA10: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8002FA14: sb          $s6, -0x7649($at)
    MEM_B(-0X7649, ctx->r1) = ctx->r22;
    // 0x8002FA18: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8002FA1C: sh          $zero, -0x7648($at)
    MEM_H(-0X7648, ctx->r1) = 0;
    // 0x8002FA20: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8002FA24: sw          $s3, -0x7630($at)
    MEM_W(-0X7630, ctx->r1) = ctx->r19;
    // 0x8002FA28: jal         0x80066D30
    // 0x8002FA2C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066D30(rdram, ctx);
        goto after_6;
    // 0x8002FA2C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x8002FA30: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002FA34: addiu       $v0, $v0, 0x20D2
    ctx->r2 = ADD32(ctx->r2, 0X20D2);
    // 0x8002FA38: addiu       $s0, $v0, -0x2A
    ctx->r16 = ADD32(ctx->r2, -0X2A);
    // 0x8002FA3C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8002FA40: jal         0x80017760
    // 0x8002FA44: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    func_80017760(rdram, ctx);
        goto after_7;
    // 0x8002FA44: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_7:
    // 0x8002FA48: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002FA4C: sh          $s1, 0x20AA($at)
    MEM_H(0X20AA, ctx->r1) = ctx->r17;
    // 0x8002FA50: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8002FA54: sh          $s1, -0x765C($at)
    MEM_H(-0X765C, ctx->r1) = ctx->r17;
    // 0x8002FA58: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002FA5C: sh          $s5, 0x20B4($at)
    MEM_H(0X20B4, ctx->r1) = ctx->r21;
    // 0x8002FA60: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002FA64: sh          $s1, 0x20AE($at)
    MEM_H(0X20AE, ctx->r1) = ctx->r17;
    // 0x8002FA68: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002FA6C: sh          $s2, 0x20B6($at)
    MEM_H(0X20B6, ctx->r1) = ctx->r18;
    // 0x8002FA70: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002FA74: sh          $s2, 0x20B2($at)
    MEM_H(0X20B2, ctx->r1) = ctx->r18;
    // 0x8002FA78: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002FA7C: sw          $s4, 0x20B8($at)
    MEM_W(0X20B8, ctx->r1) = ctx->r20;
    // 0x8002FA80: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002FA84: sb          $s7, 0x20BE($at)
    MEM_B(0X20BE, ctx->r1) = ctx->r23;
    // 0x8002FA88: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002FA8C: sb          $s6, 0x20BF($at)
    MEM_B(0X20BF, ctx->r1) = ctx->r22;
    // 0x8002FA90: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002FA94: sh          $zero, 0x20C0($at)
    MEM_H(0X20C0, ctx->r1) = 0;
    // 0x8002FA98: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002FA9C: sw          $s3, 0x20D8($at)
    MEM_W(0X20D8, ctx->r1) = ctx->r19;
    // 0x8002FAA0: jal         0x80066D30
    // 0x8002FAA4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066D30(rdram, ctx);
        goto after_8;
    // 0x8002FAA4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // 0x8002FAA8: lui         $a0, 0x11
    ctx->r4 = S32(0X11 << 16);
    // 0x8002FAAC: addiu       $a0, $a0, -0x2EC0
    ctx->r4 = ADD32(ctx->r4, -0X2EC0);
    // 0x8002FAB0: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8002FAB4: jal         0x80006D98
    // 0x8002FAB8: ori         $a2, $zero, 0xD800
    ctx->r6 = 0 | 0XD800;
    func_80006D98(rdram, ctx);
        goto after_9;
    // 0x8002FAB8: ori         $a2, $zero, 0xD800
    ctx->r6 = 0 | 0XD800;
    after_9:
    // 0x8002FABC: lui         $a0, 0x12
    ctx->r4 = S32(0X12 << 16);
    // 0x8002FAC0: addiu       $a0, $a0, -0x56C0
    ctx->r4 = ADD32(ctx->r4, -0X56C0);
    // 0x8002FAC4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8002FAC8: jal         0x80006D98
    // 0x8002FACC: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    func_80006D98(rdram, ctx);
        goto after_10;
    // 0x8002FACC: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_10:
    // 0x8002FAD0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8002FAD4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8002FAD8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8002FADC: jal         0x8000C704
    // 0x8002FAE0: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    func_8000C704(rdram, ctx);
        goto after_11;
    // 0x8002FAE0: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    after_11:
    // 0x8002FAE4: jal         0x80031BEC
    // 0x8002FAE8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    func_80031BEC(rdram, ctx);
        goto after_12;
    // 0x8002FAE8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    after_12:
    // 0x8002FAEC: jal         0x800420B0
    // 0x8002FAF0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    func_800420B0(rdram, ctx);
        goto after_13;
    // 0x8002FAF0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    after_13:
    // 0x8002FAF4: jal         0x80053390
    // 0x8002FAF8: nop

    func_80053390(rdram, ctx);
        goto after_14;
    // 0x8002FAF8: nop

    after_14:
    // 0x8002FAFC: lui         $s5, 0x800D
    ctx->r21 = S32(0X800D << 16);
    // 0x8002FB00: addiu       $s5, $s5, 0x5030
    ctx->r21 = ADD32(ctx->r21, 0X5030);
    // 0x8002FB04: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8002FB08: addiu       $s2, $s2, 0x7040
    ctx->r18 = ADD32(ctx->r18, 0X7040);
    // 0x8002FB0C: addiu       $s4, $s2, 0x4
    ctx->r20 = ADD32(ctx->r18, 0X4);
    // 0x8002FB10: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x8002FB14: addiu       $s3, $s3, -0xD3C
    ctx->r19 = ADD32(ctx->r19, -0XD3C);
L_8002FB18:
    // 0x8002FB18: jal         0x8005357C
    // 0x8002FB1C: nop

    func_8005357C(rdram, ctx);
        goto after_15;
    // 0x8002FB1C: nop

    after_15:
    // 0x8002FB20: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // 0x8002FB24: sll         $a2, $v1, 2
    ctx->r6 = S32(ctx->r3 << 2);
    // 0x8002FB28: addu        $a1, $a2, $s5
    ctx->r5 = ADD32(ctx->r6, ctx->r21);
    // 0x8002FB2C: beq         $v0, $zero, L_8002FB8C
    if (ctx->r2 == 0) {
        // 0x8002FB30: sw          $v0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r2;
            goto L_8002FB8C;
    }
    // 0x8002FB30: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8002FB34: sb          $s1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r17;
    // 0x8002FB38: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8002FB3C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8002FB40: addu        $v0, $v1, $s2
    ctx->r2 = ADD32(ctx->r3, ctx->r18);
    // 0x8002FB44: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8002FB48: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x8002FB4C: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x8002FB50: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8002FB54: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002FB58: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x8002FB5C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8002FB60: sh          $zero, 0x66($v0)
    MEM_H(0X66, ctx->r2) = 0;
    // 0x8002FB64: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8002FB68: sw          $s1, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r17;
    // 0x8002FB6C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8002FB70: addu        $v0, $a2, $s3
    ctx->r2 = ADD32(ctx->r6, ctx->r19);
    // 0x8002FB74: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8002FB78: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x8002FB7C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8002FB80: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x8002FB84: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x8002FB88: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
L_8002FB8C:
    // 0x8002FB8C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002FB90: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x8002FB94: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x8002FB98: beq         $v0, $zero, L_8002FBD4
    if (ctx->r2 == 0) {
        // 0x8002FB9C: nop
    
            goto L_8002FBD4;
    }
    // 0x8002FB9C: nop

    // 0x8002FBA0: j           L_8002FB18
    // 0x8002FBA4: nop

        goto L_8002FB18;
    // 0x8002FBA4: nop

L_8002FBA8:
    // 0x8002FBA8: jal         0x8002CCB0
    // 0x8002FBAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CCB0(rdram, ctx);
        goto after_16;
    // 0x8002FBAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x8002FBB0: bne         $v0, $zero, L_8002FBC8
    if (ctx->r2 != 0) {
        // 0x8002FBB4: nop
    
            goto L_8002FBC8;
    }
    // 0x8002FBB4: nop

    // 0x8002FBB8: jal         0x8002CCB0
    // 0x8002FBBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CCB0(rdram, ctx);
        goto after_17;
    // 0x8002FBBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_17:
    // 0x8002FBC0: beq         $v0, $zero, L_8002FBD4
    if (ctx->r2 == 0) {
        // 0x8002FBC4: nop
    
            goto L_8002FBD4;
    }
    // 0x8002FBC4: nop

L_8002FBC8:
    // 0x8002FBC8: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x8002FBCC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002FBD0: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
L_8002FBD4:
    // 0x8002FBD4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x8002FBD8: addiu       $a0, $a0, -0x7660
    ctx->r4 = ADD32(ctx->r4, -0X7660);
    // 0x8002FBDC: jal         0x80017D38
    // 0x8002FBE0: addiu       $s0, $zero, -0x600
    ctx->r16 = ADD32(0, -0X600);
    func_80017D38(rdram, ctx);
        goto after_18;
    // 0x8002FBE0: addiu       $s0, $zero, -0x600
    ctx->r16 = ADD32(0, -0X600);
    after_18:
    // 0x8002FBE4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x8002FBE8: lhu         $v0, -0x765C($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X765C);
    // 0x8002FBEC: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8002FBF0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8002FBF4: sh          $v0, -0x765C($at)
    MEM_H(-0X765C, ctx->r1) = ctx->r2;
    // 0x8002FBF8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002FBFC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FC00: bne         $v0, $s0, L_8002FC10
    if (ctx->r2 != ctx->r16) {
        // 0x8002FC04: addiu       $v0, $zero, 0x5F8
        ctx->r2 = ADD32(0, 0X5F8);
            goto L_8002FC10;
    }
    // 0x8002FC04: addiu       $v0, $zero, 0x5F8
    ctx->r2 = ADD32(0, 0X5F8);
    // 0x8002FC08: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8002FC0C: sh          $v0, -0x765C($at)
    MEM_H(-0X765C, ctx->r1) = ctx->r2;
L_8002FC10:
    // 0x8002FC10: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8002FC14: jal         0x80017D38
    // 0x8002FC18: addiu       $a0, $a0, 0x20A8
    ctx->r4 = ADD32(ctx->r4, 0X20A8);
    func_80017D38(rdram, ctx);
        goto after_19;
    // 0x8002FC18: addiu       $a0, $a0, 0x20A8
    ctx->r4 = ADD32(ctx->r4, 0X20A8);
    after_19:
    // 0x8002FC1C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002FC20: lhu         $v0, 0x20AC($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X20AC);
    // 0x8002FC24: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8002FC28: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002FC2C: sh          $v0, 0x20AC($at)
    MEM_H(0X20AC, ctx->r1) = ctx->r2;
    // 0x8002FC30: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002FC34: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FC38: bne         $v0, $s0, L_8002FC48
    if (ctx->r2 != ctx->r16) {
        // 0x8002FC3C: addiu       $v0, $zero, 0x5F8
        ctx->r2 = ADD32(0, 0X5F8);
            goto L_8002FC48;
    }
    // 0x8002FC3C: addiu       $v0, $zero, 0x5F8
    ctx->r2 = ADD32(0, 0X5F8);
    // 0x8002FC40: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002FC44: sh          $v0, 0x20AC($at)
    MEM_H(0X20AC, ctx->r1) = ctx->r2;
L_8002FC48:
    // 0x8002FC48: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8002FC4C: jal         0x80017D38
    // 0x8002FC50: addiu       $a0, $a0, 0x6AA0
    ctx->r4 = ADD32(ctx->r4, 0X6AA0);
    func_80017D38(rdram, ctx);
        goto after_20;
    // 0x8002FC50: addiu       $a0, $a0, 0x6AA0
    ctx->r4 = ADD32(ctx->r4, 0X6AA0);
    after_20:
    // 0x8002FC54: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8002FC58: jal         0x80017D38
    // 0x8002FC5C: addiu       $a0, $a0, 0x3520
    ctx->r4 = ADD32(ctx->r4, 0X3520);
    func_80017D38(rdram, ctx);
        goto after_21;
    // 0x8002FC5C: addiu       $a0, $a0, 0x3520
    ctx->r4 = ADD32(ctx->r4, 0X3520);
    after_21:
    // 0x8002FC60: jal         0x80042164
    // 0x8002FC64: nop

    func_80042164(rdram, ctx);
        goto after_22;
    // 0x8002FC64: nop

    after_22:
    // 0x8002FC68: jal         0x80051D6C
    // 0x8002FC6C: nop

    func_80051D6C(rdram, ctx);
        goto after_23;
    // 0x8002FC6C: nop

    after_23:
    // 0x8002FC70: jal         0x800533F0
    // 0x8002FC74: nop

    func_800533F0(rdram, ctx);
        goto after_24;
    // 0x8002FC74: nop

    after_24:
    // 0x8002FC78: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8002FC7C: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x8002FC80: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x8002FC84: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8002FC88: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8002FC8C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FC90: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8002FC94: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8002FC98: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002FC9C: jr          $ra
    // 0x8002FCA0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8002FCA0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8002FCB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FCB0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8002FCB4: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x8002FCB8: addiu       $a3, $a3, 0x2FF0
    ctx->r7 = ADD32(ctx->r7, 0X2FF0);
    // 0x8002FCBC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8002FCC0:
    // 0x8002FCC0: sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6 << 16);
    // 0x8002FCC4: sra         $a1, $v0, 16
    ctx->r5 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FCC8: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_8002FCCC:
    // 0x8002FCCC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FCD0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8002FCD4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002FCD8: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8002FCDC: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8002FCE0: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x8002FCE4: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8002FCE8: beq         $v0, $zero, L_8002FCF8
    if (ctx->r2 == 0) {
        // 0x8002FCEC: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8002FCF8;
    }
    // 0x8002FCEC: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8002FCF0: j           L_8002FD30
    // 0x8002FCF4: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
        goto L_8002FD30;
    // 0x8002FCF4: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
L_8002FCF8:
    // 0x8002FCF8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8002FCFC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002FD00: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FD04: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8002FD08: bne         $v0, $zero, L_8002FCCC
    if (ctx->r2 != 0) {
        // 0x8002FD0C: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_8002FCCC;
    }
    // 0x8002FD0C: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x8002FD10: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x8002FD14: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8002FD18: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002FD1C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FD20: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8002FD24: bnel        $v0, $zero, L_8002FCC0
    if (ctx->r2 != 0) {
        // 0x8002FD28: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8002FCC0;
    }
    goto skip_0;
    // 0x8002FD28: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_0:
    // 0x8002FD2C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8002FD30:
    // 0x8002FD30: jr          $ra
    // 0x8002FD34: nop

    return;
    // 0x8002FD34: nop

;}
RECOMP_FUNC void func_8002FD38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FD38: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8002FD3C: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x8002FD40: addiu       $a3, $a3, 0x2FF0
    ctx->r7 = ADD32(ctx->r7, 0X2FF0);
    // 0x8002FD44: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8002FD48:
    // 0x8002FD48: sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6 << 16);
    // 0x8002FD4C: sra         $a1, $v0, 16
    ctx->r5 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FD50: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_8002FD54:
    // 0x8002FD54: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FD58: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8002FD5C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002FD60: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8002FD64: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8002FD68: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x8002FD6C: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8002FD70: beq         $v0, $zero, L_8002FD80
    if (ctx->r2 == 0) {
        // 0x8002FD74: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8002FD80;
    }
    // 0x8002FD74: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8002FD78: j           L_8002FDB0
    // 0x8002FD7C: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
        goto L_8002FDB0;
    // 0x8002FD7C: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
L_8002FD80:
    // 0x8002FD80: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8002FD84: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002FD88: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FD8C: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8002FD90: bne         $v0, $zero, L_8002FD54
    if (ctx->r2 != 0) {
        // 0x8002FD94: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_8002FD54;
    }
    // 0x8002FD94: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x8002FD98: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x8002FD9C: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8002FDA0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002FDA4: bgezl       $v0, L_8002FD48
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002FDA8: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8002FD48;
    }
    goto skip_0;
    // 0x8002FDA8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_0:
    // 0x8002FDAC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8002FDB0:
    // 0x8002FDB0: jr          $ra
    // 0x8002FDB4: nop

    return;
    // 0x8002FDB4: nop

;}
RECOMP_FUNC void func_8002FDB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FDB8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8002FDBC: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x8002FDC0: addiu       $a3, $a3, 0x2FF0
    ctx->r7 = ADD32(ctx->r7, 0X2FF0);
    // 0x8002FDC4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8002FDC8:
    // 0x8002FDC8: sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6 << 16);
    // 0x8002FDCC: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FDD0: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8002FDD4: addu        $a1, $v0, $a0
    ctx->r5 = ADD32(ctx->r2, ctx->r4);
    // 0x8002FDD8: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
L_8002FDDC:
    // 0x8002FDDC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FDE0: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x8002FDE4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8002FDE8: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8002FDEC: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x8002FDF0: beq         $v0, $zero, L_8002FE00
    if (ctx->r2 == 0) {
        // 0x8002FDF4: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8002FE00;
    }
    // 0x8002FDF4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8002FDF8: j           L_8002FE38
    // 0x8002FDFC: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
        goto L_8002FE38;
    // 0x8002FDFC: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_8002FE00:
    // 0x8002FE00: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8002FE04: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002FE08: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FE0C: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8002FE10: bne         $v0, $zero, L_8002FDDC
    if (ctx->r2 != 0) {
        // 0x8002FE14: sll         $v0, $v1, 16
        ctx->r2 = S32(ctx->r3 << 16);
            goto L_8002FDDC;
    }
    // 0x8002FE14: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8002FE18: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x8002FE1C: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8002FE20: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002FE24: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FE28: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8002FE2C: bnel        $v0, $zero, L_8002FDC8
    if (ctx->r2 != 0) {
        // 0x8002FE30: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8002FDC8;
    }
    goto skip_0;
    // 0x8002FE30: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    skip_0:
    // 0x8002FE34: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8002FE38:
    // 0x8002FE38: jr          $ra
    // 0x8002FE3C: nop

    return;
    // 0x8002FE3C: nop

;}
RECOMP_FUNC void func_8002FE40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FE40: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8002FE44: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x8002FE48: addiu       $a3, $a3, 0x2FF0
    ctx->r7 = ADD32(ctx->r7, 0X2FF0);
    // 0x8002FE4C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8002FE50:
    // 0x8002FE50: sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6 << 16);
    // 0x8002FE54: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FE58: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8002FE5C: addu        $a1, $v0, $a0
    ctx->r5 = ADD32(ctx->r2, ctx->r4);
    // 0x8002FE60: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
L_8002FE64:
    // 0x8002FE64: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FE68: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x8002FE6C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8002FE70: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8002FE74: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x8002FE78: beq         $v0, $zero, L_8002FE88
    if (ctx->r2 == 0) {
        // 0x8002FE7C: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8002FE88;
    }
    // 0x8002FE7C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8002FE80: j           L_8002FEB8
    // 0x8002FE84: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
        goto L_8002FEB8;
    // 0x8002FE84: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_8002FE88:
    // 0x8002FE88: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8002FE8C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002FE90: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FE94: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8002FE98: bne         $v0, $zero, L_8002FE64
    if (ctx->r2 != 0) {
        // 0x8002FE9C: sll         $v0, $v1, 16
        ctx->r2 = S32(ctx->r3 << 16);
            goto L_8002FE64;
    }
    // 0x8002FE9C: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8002FEA0: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x8002FEA4: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8002FEA8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002FEAC: bgezl       $v0, L_8002FE50
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002FEB0: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8002FE50;
    }
    goto skip_0;
    // 0x8002FEB0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    skip_0:
    // 0x8002FEB4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8002FEB8:
    // 0x8002FEB8: jr          $ra
    // 0x8002FEBC: nop

    return;
    // 0x8002FEBC: nop

;}
RECOMP_FUNC void func_8002FEC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FEC0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8002FEC4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8002FEC8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002FECC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8002FED0: sw          $s2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r18;
    // 0x8002FED4: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8002FED8: sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // 0x8002FEDC: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x8002FEE0: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x8002FEE4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002FEE8: addu        $s1, $t0, $zero
    ctx->r17 = ADD32(ctx->r8, 0);
    // 0x8002FEEC: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    // 0x8002FEF0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8002FEF4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8002FEF8: slt         $v1, $a0, $v1
    ctx->r3 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002FEFC: bne         $v1, $zero, L_8002FFC8
    if (ctx->r3 != 0) {
        // 0x8002FF00: addu        $t9, $v0, $zero
        ctx->r25 = ADD32(ctx->r2, 0);
            goto L_8002FFC8;
    }
    // 0x8002FF00: addu        $t9, $v0, $zero
    ctx->r25 = ADD32(ctx->r2, 0);
    // 0x8002FF04: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x8002FF08: sra         $t8, $v0, 16
    ctx->r24 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FF0C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8002FF10: addiu       $t6, $t6, 0x2FF0
    ctx->r14 = ADD32(ctx->r14, 0X2FF0);
    // 0x8002FF14: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x8002FF18: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FF1C: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8002FF20: sra         $t4, $a3, 16
    ctx->r12 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8002FF24: sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6 << 16);
    // 0x8002FF28: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FF2C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8002FF30: addu        $t3, $v0, $a0
    ctx->r11 = ADD32(ctx->r2, ctx->r4);
L_8002FF34:
    // 0x8002FF34: sra         $a1, $a3, 16
    ctx->r5 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8002FF38: slt         $v0, $t8, $a1
    ctx->r2 = SIGNED(ctx->r24) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002FF3C: bnel        $v0, $zero, L_8002FFB4
    if (ctx->r2 != 0) {
        // 0x8002FF40: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8002FFB4;
    }
    goto skip_0;
    // 0x8002FF40: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    skip_0:
    // 0x8002FF44: addu        $t2, $t3, $zero
    ctx->r10 = ADD32(ctx->r11, 0);
    // 0x8002FF48: lw          $t1, 0x110($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X110);
    // 0x8002FF4C: sll         $v0, $t9, 16
    ctx->r2 = S32(ctx->r25 << 16);
    // 0x8002FF50: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FF54: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8002FF58: subu        $v0, $t7, $v0
    ctx->r2 = SUB32(ctx->r15, ctx->r2);
    // 0x8002FF5C: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x8002FF60: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002FF64: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
    // 0x8002FF68: sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17 << 16);
    // 0x8002FF6C: sra         $a2, $v0, 16
    ctx->r6 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FF70: addu        $v0, $t2, $a1
    ctx->r2 = ADD32(ctx->r10, ctx->r5);
L_8002FF74:
    // 0x8002FF74: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8002FF78: subu        $v1, $a1, $t4
    ctx->r3 = SUB32(ctx->r5, ctx->r12);
    // 0x8002FF7C: addu        $v1, $t5, $v1
    ctx->r3 = ADD32(ctx->r13, ctx->r3);
    // 0x8002FF80: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x8002FF84: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8002FF88: lbu         $v1, 0x70($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X70);
    // 0x8002FF8C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8002FF90: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8002FF94: beq         $v1, $zero, L_8002FFA4
    if (ctx->r3 == 0) {
        // 0x8002FF98: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8002FFA4;
    }
    // 0x8002FF98: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002FF9C: bne         $v0, $zero, L_8002FFCC
    if (ctx->r2 != 0) {
        // 0x8002FFA0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002FFCC;
    }
    // 0x8002FFA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002FFA4:
    // 0x8002FFA4: slt         $v0, $a2, $a1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002FFA8: beq         $v0, $zero, L_8002FF74
    if (ctx->r2 == 0) {
        // 0x8002FFAC: addu        $v0, $t2, $a1
        ctx->r2 = ADD32(ctx->r10, ctx->r5);
            goto L_8002FF74;
    }
    // 0x8002FFAC: addu        $v0, $t2, $a1
    ctx->r2 = ADD32(ctx->r10, ctx->r5);
    // 0x8002FFB0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_8002FFB4:
    // 0x8002FFB4: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    // 0x8002FFB8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002FFBC: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002FFC0: beq         $v0, $zero, L_8002FF34
    if (ctx->r2 == 0) {
        // 0x8002FFC4: addiu       $t3, $t3, -0x5
        ctx->r11 = ADD32(ctx->r11, -0X5);
            goto L_8002FF34;
    }
    // 0x8002FFC4: addiu       $t3, $t3, -0x5
    ctx->r11 = ADD32(ctx->r11, -0X5);
L_8002FFC8:
    // 0x8002FFC8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8002FFCC:
    // 0x8002FFCC: lw          $s2, 0x8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X8);
    // 0x8002FFD0: lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4);
    // 0x8002FFD4: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x8002FFD8: jr          $ra
    // 0x8002FFDC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8002FFDC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8002FFE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FFE0: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x8002FFE4: addu        $t2, $a3, $zero
    ctx->r10 = ADD32(ctx->r7, 0);
    // 0x8002FFE8: lhu         $t5, 0x16($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X16);
    // 0x8002FFEC: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8002FFF0: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8002FFF4: addu        $t6, $v0, $zero
    ctx->r14 = ADD32(ctx->r2, 0);
    // 0x8002FFF8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002FFFC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030000: slt         $v0, $v0, $a3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80030004: bne         $v0, $zero, L_80030104
    if (ctx->r2 != 0) {
        // 0x80030008: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80030104;
    }
    // 0x80030008: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8003000C: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80030010: addiu       $t3, $t3, 0x2FF0
    ctx->r11 = ADD32(ctx->r11, 0X2FF0);
    // 0x80030014: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80030018: sra         $t4, $v0, 16
    ctx->r12 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003001C: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
L_80030020:
    // 0x80030020: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80030024: sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10 << 16);
    // 0x80030028: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003002C: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_80030030:
    // 0x80030030: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030034: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80030038: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003003C: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x80030040: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80030044: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x80030048: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8003004C: bnel        $v0, $zero, L_80030054
    if (ctx->r2 != 0) {
        // 0x80030050: addu        $t0, $a1, $zero
        ctx->r8 = ADD32(ctx->r5, 0);
            goto L_80030054;
    }
    goto skip_0;
    // 0x80030050: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    skip_0:
L_80030054:
    // 0x80030054: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x80030058: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8003005C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030060: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030064: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80030068: bne         $v0, $zero, L_80030030
    if (ctx->r2 != 0) {
        // 0x8003006C: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_80030030;
    }
    // 0x8003006C: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80030070: subu        $v0, $t5, $t0
    ctx->r2 = SUB32(ctx->r13, ctx->r8);
    // 0x80030074: subu        $v0, $a2, $v0
    ctx->r2 = SUB32(ctx->r6, ctx->r2);
    // 0x80030078: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8003007C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030080: bltz        $v0, L_800300E0
    if (SIGNED(ctx->r2) < 0) {
        // 0x80030084: addiu       $v1, $t2, 0x1
        ctx->r3 = ADD32(ctx->r10, 0X1);
            goto L_800300E0;
    }
    // 0x80030084: addiu       $v1, $t2, 0x1
    ctx->r3 = ADD32(ctx->r10, 0X1);
    // 0x80030088: sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10 << 16);
    // 0x8003008C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030090: lw          $v1, 0x110($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X110);
    // 0x80030094: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x80030098: addu        $v0, $t4, $v0
    ctx->r2 = ADD32(ctx->r12, ctx->r2);
    // 0x8003009C: addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // 0x800300A0: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_800300A4:
    // 0x800300A4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800300A8: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x800300AC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800300B0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800300B4: addu        $v1, $t0, $v1
    ctx->r3 = ADD32(ctx->r8, ctx->r3);
    // 0x800300B8: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x800300BC: beq         $v0, $zero, L_800300CC
    if (ctx->r2 == 0) {
        // 0x800300C0: addiu       $v0, $a1, -0x1
        ctx->r2 = ADD32(ctx->r5, -0X1);
            goto L_800300CC;
    }
    // 0x800300C0: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x800300C4: j           L_80030104
    // 0x800300C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80030104;
    // 0x800300C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800300CC:
    // 0x800300CC: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800300D0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800300D4: bgez        $v0, L_800300A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800300D8: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_800300A4;
    }
    // 0x800300D8: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x800300DC: addiu       $v1, $t2, 0x1
    ctx->r3 = ADD32(ctx->r10, 0X1);
L_800300E0:
    // 0x800300E0: addu        $t2, $v1, $zero
    ctx->r10 = ADD32(ctx->r3, 0);
    // 0x800300E4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800300E8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800300EC: sll         $v0, $t6, 16
    ctx->r2 = S32(ctx->r14 << 16);
    // 0x800300F0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800300F4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800300F8: beql        $v0, $zero, L_80030020
    if (ctx->r2 == 0) {
        // 0x800300FC: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_80030020;
    }
    goto skip_1;
    // 0x800300FC: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    skip_1:
    // 0x80030100: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80030104:
    // 0x80030104: jr          $ra
    // 0x80030108: nop

    return;
    // 0x80030108: nop

;}
RECOMP_FUNC void func_8003010C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003010C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80030110: sw          $s2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r18;
    // 0x80030114: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80030118: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8003011C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80030120: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80030124: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80030128: sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // 0x8003012C: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x80030130: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x80030134: addu        $t6, $v0, $zero
    ctx->r14 = ADD32(ctx->r2, 0);
    // 0x80030138: addu        $t3, $t6, $zero
    ctx->r11 = ADD32(ctx->r14, 0);
    // 0x8003013C: addu        $t9, $v1, $zero
    ctx->r25 = ADD32(ctx->r3, 0);
    // 0x80030140: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030144: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030148: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8003014C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80030150: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80030154: bne         $v0, $zero, L_80030250
    if (ctx->r2 != 0) {
        // 0x80030158: addu        $s0, $a0, $zero
        ctx->r16 = ADD32(ctx->r4, 0);
            goto L_80030250;
    }
    // 0x80030158: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8003015C: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80030160: sra         $t8, $v0, 16
    ctx->r24 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030164: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80030168: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003016C: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x80030170: sra         $t4, $v0, 16
    ctx->r12 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030174: sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6 << 16);
    // 0x80030178: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003017C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
L_80030180:
    // 0x80030180: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80030184: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030188: slt         $v0, $t8, $v0
    ctx->r2 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003018C: bne         $v0, $zero, L_80030230
    if (ctx->r2 != 0) {
        // 0x80030190: addiu       $v1, $t3, -0x1
        ctx->r3 = ADD32(ctx->r11, -0X1);
            goto L_80030230;
    }
    // 0x80030190: addiu       $v1, $t3, -0x1
    ctx->r3 = ADD32(ctx->r11, -0X1);
    // 0x80030194: lw          $t1, 0x110($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X110);
    // 0x80030198: sll         $v1, $t6, 16
    ctx->r3 = S32(ctx->r14 << 16);
    // 0x8003019C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800301A0: sll         $a0, $t3, 16
    ctx->r4 = S32(ctx->r11 << 16);
    // 0x800301A4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800301A8: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800301AC: subu        $v1, $t7, $v1
    ctx->r3 = SUB32(ctx->r15, ctx->r3);
    // 0x800301B0: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800301B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800301B8: sll         $a3, $v0, 1
    ctx->r7 = S32(ctx->r2 << 1);
    // 0x800301BC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800301C0: addu        $a2, $v0, $a0
    ctx->r6 = ADD32(ctx->r2, ctx->r4);
    // 0x800301C4: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800301C8: addiu       $t2, $t2, 0x2FF0
    ctx->r10 = ADD32(ctx->r10, 0X2FF0);
    // 0x800301CC: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    // 0x800301D0: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800301D4: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_800301D8:
    // 0x800301D8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800301DC: subu        $v1, $v0, $t4
    ctx->r3 = SUB32(ctx->r2, ctx->r12);
    // 0x800301E0: addu        $v1, $t5, $v1
    ctx->r3 = ADD32(ctx->r13, ctx->r3);
    // 0x800301E4: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x800301E8: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x800301EC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800301F0: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x800301F4: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x800301F8: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800301FC: lbu         $v1, 0x82($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X82);
    // 0x80030200: beql        $v0, $zero, L_80030214
    if (ctx->r2 == 0) {
        // 0x80030204: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_80030214;
    }
    goto skip_0;
    // 0x80030204: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x80030208: bnel        $v1, $zero, L_80030210
    if (ctx->r3 != 0) {
        // 0x8003020C: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80030210;
    }
    goto skip_1;
    // 0x8003020C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_1:
L_80030210:
    // 0x80030210: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
L_80030214:
    // 0x80030214: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80030218: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8003021C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030220: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80030224: beq         $v0, $zero, L_800301D8
    if (ctx->r2 == 0) {
        // 0x80030228: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_800301D8;
    }
    // 0x80030228: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x8003022C: addiu       $v1, $t3, -0x1
    ctx->r3 = ADD32(ctx->r11, -0X1);
L_80030230:
    // 0x80030230: addu        $t3, $v1, $zero
    ctx->r11 = ADD32(ctx->r3, 0);
    // 0x80030234: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80030238: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003023C: sll         $v0, $t9, 16
    ctx->r2 = S32(ctx->r25 << 16);
    // 0x80030240: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030244: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80030248: beql        $v1, $zero, L_80030180
    if (ctx->r3 == 0) {
        // 0x8003024C: addu        $a1, $s1, $zero
        ctx->r5 = ADD32(ctx->r17, 0);
            goto L_80030180;
    }
    goto skip_2;
    // 0x8003024C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    skip_2:
L_80030250:
    // 0x80030250: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x80030254: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030258: lw          $s2, 0x8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X8);
    // 0x8003025C: lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4);
    // 0x80030260: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x80030264: jr          $ra
    // 0x80030268: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80030268: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8003026C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003026C: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80030270: addu        $t3, $a3, $zero
    ctx->r11 = ADD32(ctx->r7, 0);
    // 0x80030274: lhu         $t7, 0x16($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X16);
    // 0x80030278: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8003027C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80030280: addu        $t8, $v0, $zero
    ctx->r24 = ADD32(ctx->r2, 0);
    // 0x80030284: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030288: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003028C: slt         $v0, $v0, $a3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80030290: bne         $v0, $zero, L_800303BC
    if (ctx->r2 != 0) {
        // 0x80030294: addu        $t4, $zero, $zero
        ctx->r12 = ADD32(0, 0);
            goto L_800303BC;
    }
    // 0x80030294: addu        $t4, $zero, $zero
    ctx->r12 = ADD32(0, 0);
    // 0x80030298: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8003029C: addiu       $t5, $t5, 0x2FF0
    ctx->r13 = ADD32(ctx->r13, 0X2FF0);
    // 0x800302A0: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x800302A4: sra         $t6, $v0, 16
    ctx->r14 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800302A8: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
L_800302AC:
    // 0x800302AC: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x800302B0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800302B4: sll         $v0, $t3, 16
    ctx->r2 = S32(ctx->r11 << 16);
    // 0x800302B8: sra         $t2, $v0, 16
    ctx->r10 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800302BC: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_800302C0:
    // 0x800302C0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800302C4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800302C8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800302CC: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x800302D0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800302D4: addu        $v1, $v1, $t5
    ctx->r3 = ADD32(ctx->r3, ctx->r13);
    // 0x800302D8: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800302DC: bnel        $v0, $zero, L_800302E4
    if (ctx->r2 != 0) {
        // 0x800302E0: addu        $t0, $a1, $zero
        ctx->r8 = ADD32(ctx->r5, 0);
            goto L_800302E4;
    }
    goto skip_0;
    // 0x800302E0: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    skip_0:
L_800302E4:
    // 0x800302E4: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800302E8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800302EC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800302F0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800302F4: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x800302F8: bne         $v0, $zero, L_800302C0
    if (ctx->r2 != 0) {
        // 0x800302FC: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_800302C0;
    }
    // 0x800302FC: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80030300: subu        $v0, $t7, $t0
    ctx->r2 = SUB32(ctx->r15, ctx->r8);
    // 0x80030304: subu        $v0, $a2, $v0
    ctx->r2 = SUB32(ctx->r6, ctx->r2);
    // 0x80030308: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003030C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80030310: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030314: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030318: slti        $v0, $v0, 0x12
    ctx->r2 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x8003031C: beq         $v0, $zero, L_8003037C
    if (ctx->r2 == 0) {
        // 0x80030320: sll         $v0, $t3, 16
        ctx->r2 = S32(ctx->r11 << 16);
            goto L_8003037C;
    }
    // 0x80030320: sll         $v0, $t3, 16
    ctx->r2 = S32(ctx->r11 << 16);
    // 0x80030324: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030328: lw          $v1, 0x110($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X110);
    // 0x8003032C: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x80030330: addu        $v0, $t6, $v0
    ctx->r2 = ADD32(ctx->r14, ctx->r2);
    // 0x80030334: addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // 0x80030338: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_8003033C:
    // 0x8003033C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030340: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80030344: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80030348: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8003034C: addu        $v1, $t0, $v1
    ctx->r3 = ADD32(ctx->r8, ctx->r3);
    // 0x80030350: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x80030354: bnel        $v0, $zero, L_80030360
    if (ctx->r2 != 0) {
        // 0x80030358: addiu       $a1, $zero, 0x12
        ctx->r5 = ADD32(0, 0X12);
            goto L_80030360;
    }
    goto skip_1;
    // 0x80030358: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    skip_1:
    // 0x8003035C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_80030360:
    // 0x80030360: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x80030364: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80030368: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8003036C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030370: slti        $v0, $v0, 0x12
    ctx->r2 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x80030374: bne         $v0, $zero, L_8003033C
    if (ctx->r2 != 0) {
        // 0x80030378: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_8003033C;
    }
    // 0x80030378: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_8003037C:
    // 0x8003037C: sll         $v1, $t1, 16
    ctx->r3 = S32(ctx->r9 << 16);
    // 0x80030380: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80030384: sll         $v0, $t4, 16
    ctx->r2 = S32(ctx->r12 << 16);
    // 0x80030388: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003038C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80030390: bnel        $v0, $zero, L_80030398
    if (ctx->r2 != 0) {
        // 0x80030394: addu        $t4, $t1, $zero
        ctx->r12 = ADD32(ctx->r9, 0);
            goto L_80030398;
    }
    goto skip_2;
    // 0x80030394: addu        $t4, $t1, $zero
    ctx->r12 = ADD32(ctx->r9, 0);
    skip_2:
L_80030398:
    // 0x80030398: addiu       $v1, $t3, 0x1
    ctx->r3 = ADD32(ctx->r11, 0X1);
    // 0x8003039C: addu        $t3, $v1, $zero
    ctx->r11 = ADD32(ctx->r3, 0);
    // 0x800303A0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800303A4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800303A8: sll         $v0, $t8, 16
    ctx->r2 = S32(ctx->r24 << 16);
    // 0x800303AC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800303B0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800303B4: beql        $v0, $zero, L_800302AC
    if (ctx->r2 == 0) {
        // 0x800303B8: addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
            goto L_800302AC;
    }
    goto skip_3;
    // 0x800303B8: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    skip_3:
L_800303BC:
    // 0x800303BC: sll         $v0, $t4, 16
    ctx->r2 = S32(ctx->r12 << 16);
    // 0x800303C0: jr          $ra
    // 0x800303C4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x800303C4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
;}
RECOMP_FUNC void func_800303C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800303C8: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x800303CC: addu        $t2, $a3, $zero
    ctx->r10 = ADD32(ctx->r7, 0);
    // 0x800303D0: lhu         $t6, 0x16($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X16);
    // 0x800303D4: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x800303D8: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800303DC: addu        $t7, $v0, $zero
    ctx->r15 = ADD32(ctx->r2, 0);
    // 0x800303E0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800303E4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800303E8: slt         $v0, $v0, $a3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800303EC: bne         $v0, $zero, L_800304FC
    if (ctx->r2 != 0) {
        // 0x800303F0: addu        $t3, $zero, $zero
        ctx->r11 = ADD32(0, 0);
            goto L_800304FC;
    }
    // 0x800303F0: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // 0x800303F4: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800303F8: addiu       $t4, $t4, 0x2FF0
    ctx->r12 = ADD32(ctx->r12, 0X2FF0);
    // 0x800303FC: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80030400: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030404: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
L_80030408:
    // 0x80030408: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8003040C: sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10 << 16);
    // 0x80030410: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030414: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_80030418:
    // 0x80030418: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003041C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80030420: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80030424: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x80030428: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8003042C: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x80030430: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80030434: bnel        $v0, $zero, L_8003043C
    if (ctx->r2 != 0) {
        // 0x80030438: addu        $t0, $a1, $zero
        ctx->r8 = ADD32(ctx->r5, 0);
            goto L_8003043C;
    }
    goto skip_0;
    // 0x80030438: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    skip_0:
L_8003043C:
    // 0x8003043C: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x80030440: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80030444: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030448: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003044C: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80030450: bne         $v0, $zero, L_80030418
    if (ctx->r2 != 0) {
        // 0x80030454: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_80030418;
    }
    // 0x80030454: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80030458: subu        $v0, $t6, $t0
    ctx->r2 = SUB32(ctx->r14, ctx->r8);
    // 0x8003045C: subu        $v0, $a2, $v0
    ctx->r2 = SUB32(ctx->r6, ctx->r2);
    // 0x80030460: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80030464: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80030468: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8003046C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030470: slti        $v0, $v0, 0x12
    ctx->r2 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x80030474: beq         $v0, $zero, L_800304DC
    if (ctx->r2 == 0) {
        // 0x80030478: addiu       $v1, $t2, 0x1
        ctx->r3 = ADD32(ctx->r10, 0X1);
            goto L_800304DC;
    }
    // 0x80030478: addiu       $v1, $t2, 0x1
    ctx->r3 = ADD32(ctx->r10, 0X1);
    // 0x8003047C: sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10 << 16);
    // 0x80030480: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030484: lw          $v1, 0x110($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X110);
    // 0x80030488: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x8003048C: addu        $v0, $t5, $v0
    ctx->r2 = ADD32(ctx->r13, ctx->r2);
    // 0x80030490: addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // 0x80030494: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_80030498:
    // 0x80030498: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003049C: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x800304A0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800304A4: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800304A8: addu        $v1, $t0, $v1
    ctx->r3 = ADD32(ctx->r8, ctx->r3);
    // 0x800304AC: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x800304B0: bnel        $v0, $zero, L_800304BC
    if (ctx->r2 != 0) {
        // 0x800304B4: addiu       $a1, $zero, 0x12
        ctx->r5 = ADD32(0, 0X12);
            goto L_800304BC;
    }
    goto skip_1;
    // 0x800304B4: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    skip_1:
    // 0x800304B8: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
L_800304BC:
    // 0x800304BC: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800304C0: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800304C4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800304C8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800304CC: slti        $v0, $v0, 0x12
    ctx->r2 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x800304D0: bne         $v0, $zero, L_80030498
    if (ctx->r2 != 0) {
        // 0x800304D4: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_80030498;
    }
    // 0x800304D4: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x800304D8: addiu       $v1, $t2, 0x1
    ctx->r3 = ADD32(ctx->r10, 0X1);
L_800304DC:
    // 0x800304DC: addu        $t2, $v1, $zero
    ctx->r10 = ADD32(ctx->r3, 0);
    // 0x800304E0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800304E4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800304E8: sll         $v0, $t7, 16
    ctx->r2 = S32(ctx->r15 << 16);
    // 0x800304EC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800304F0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800304F4: beql        $v0, $zero, L_80030408
    if (ctx->r2 == 0) {
        // 0x800304F8: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_80030408;
    }
    goto skip_2;
    // 0x800304F8: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    skip_2:
L_800304FC:
    // 0x800304FC: sll         $v0, $t3, 16
    ctx->r2 = S32(ctx->r11 << 16);
    // 0x80030500: jr          $ra
    // 0x80030504: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x80030504: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
;}
RECOMP_FUNC void func_80030508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030508: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8003050C: lw          $a2, 0x110($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X110);
    // 0x80030510: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80030514:
    // 0x80030514: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80030518: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003051C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80030520: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80030524: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80030528: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_8003052C:
    // 0x8003052C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030530: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80030534: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80030538: lbu         $v0, 0x70($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X70);
    // 0x8003053C: beq         $v0, $zero, L_8003054C
    if (ctx->r2 == 0) {
        // 0x80030540: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8003054C;
    }
    // 0x80030540: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80030544: j           L_8003057C
    // 0x80030548: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8003057C;
    // 0x80030548: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003054C:
    // 0x8003054C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80030550: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030554: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030558: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8003055C: bne         $v0, $zero, L_8003052C
    if (ctx->r2 != 0) {
        // 0x80030560: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_8003052C;
    }
    // 0x80030560: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80030564: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x80030568: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8003056C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030570: bgezl       $v0, L_80030514
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80030574: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80030514;
    }
    goto skip_0;
    // 0x80030574: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_0:
    // 0x80030578: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8003057C:
    // 0x8003057C: jr          $ra
    // 0x80030580: nop

    return;
    // 0x80030580: nop

;}
RECOMP_FUNC void func_80030584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030584: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80030588: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8003058C: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80030590: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // 0x80030594: addu        $t8, $zero, $zero
    ctx->r24 = ADD32(0, 0);
    // 0x80030598: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8003059C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800305A0: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800305A4: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800305A8: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800305AC: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800305B0: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800305B4: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800305B8: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
    // 0x800305BC: lbu         $v1, 0x4C($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X4C);
    // 0x800305C0: addiu       $s7, $zero, 0x12
    ctx->r23 = ADD32(0, 0X12);
    // 0x800305C4: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x800305C8: addiu       $s3, $s3, 0x2FF0
    ctx->r19 = ADD32(ctx->r19, 0X2FF0);
    // 0x800305CC: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x800305D0: sh          $s7, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r23;
    // 0x800305D4: sb          $zero, 0x0($sp)
    MEM_B(0X0, ctx->r29) = 0;
    // 0x800305D8: sb          $v0, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r2;
    // 0x800305DC: sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3 << 24);
    // 0x800305E0: sra         $t7, $v1, 24
    ctx->r15 = S32(SIGNED(ctx->r3) >> 24);
L_800305E4:
    // 0x800305E4: lhu         $s7, 0x16($sp)
    ctx->r23 = MEM_HU(ctx->r29, 0X16);
    // 0x800305E8: sh          $zero, 0xE($sp)
    MEM_H(0XE, ctx->r29) = 0;
    // 0x800305EC: sll         $v0, $s7, 16
    ctx->r2 = S32(ctx->r23 << 16);
    // 0x800305F0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800305F4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_800305F8:
    // 0x800305F8: lb          $v0, 0x54($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X54);
    // 0x800305FC: lw          $v1, 0xDC($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XDC);
    // 0x80030600: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80030604: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80030608: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003060C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80030610: sll         $v0, $t7, 16
    ctx->r2 = S32(ctx->r15 << 16);
    // 0x80030614: sra         $v0, $v0, 14
    ctx->r2 = S32(SIGNED(ctx->r2) >> 14);
    // 0x80030618: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003061C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80030620: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80030624:
    // 0x80030624: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x80030628: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003062C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80030630: addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
L_80030634:
    // 0x80030634: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80030638: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003063C: addu        $v0, $t1, $v1
    ctx->r2 = ADD32(ctx->r9, ctx->r3);
    // 0x80030640: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x80030644: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80030648: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x8003064C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80030650: addu        $v1, $a3, $v1
    ctx->r3 = ADD32(ctx->r7, ctx->r3);
    // 0x80030654: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80030658: addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // 0x8003065C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030660: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030664: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80030668: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x8003066C: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80030670: bne         $v0, $zero, L_80030634
    if (ctx->r2 != 0) {
        // 0x80030674: sh          $a0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r4;
            goto L_80030634;
    }
    // 0x80030674: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x80030678: addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
    // 0x8003067C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80030680: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030684: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030688: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8003068C: bne         $v0, $zero, L_80030624
    if (ctx->r2 != 0) {
        // 0x80030690: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80030624;
    }
    // 0x80030690: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80030694: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80030698: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8003069C:
    // 0x8003069C: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x800306A0: sra         $a1, $v0, 16
    ctx->r5 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800306A4: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_800306A8:
    // 0x800306A8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800306AC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800306B0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800306B4: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800306B8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800306BC: addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // 0x800306C0: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800306C4: beq         $v0, $zero, L_800306D4
    if (ctx->r2 == 0) {
        // 0x800306C8: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_800306D4;
    }
    // 0x800306C8: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800306CC: j           L_8003070C
    // 0x800306D0: addu        $t5, $a1, $zero
    ctx->r13 = ADD32(ctx->r5, 0);
        goto L_8003070C;
    // 0x800306D0: addu        $t5, $a1, $zero
    ctx->r13 = ADD32(ctx->r5, 0);
L_800306D4:
    // 0x800306D4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800306D8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800306DC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800306E0: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x800306E4: bne         $v0, $zero, L_800306A8
    if (ctx->r2 != 0) {
        // 0x800306E8: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_800306A8;
    }
    // 0x800306E8: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x800306EC: addiu       $v0, $a3, 0x1
    ctx->r2 = ADD32(ctx->r7, 0X1);
    // 0x800306F0: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x800306F4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800306F8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800306FC: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80030700: bne         $v0, $zero, L_8003069C
    if (ctx->r2 != 0) {
        // 0x80030704: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8003069C;
    }
    // 0x80030704: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80030708: addu        $t5, $zero, $zero
    ctx->r13 = ADD32(0, 0);
L_8003070C:
    // 0x8003070C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80030710: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80030714:
    // 0x80030714: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x80030718: sra         $a1, $v0, 16
    ctx->r5 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003071C: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_80030720:
    // 0x80030720: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030724: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80030728: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003072C: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80030730: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80030734: addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // 0x80030738: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8003073C: beq         $v0, $zero, L_8003074C
    if (ctx->r2 == 0) {
        // 0x80030740: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8003074C;
    }
    // 0x80030740: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80030744: j           L_8003077C
    // 0x80030748: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
        goto L_8003077C;
    // 0x80030748: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
L_8003074C:
    // 0x8003074C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80030750: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030754: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030758: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8003075C: bne         $v0, $zero, L_80030720
    if (ctx->r2 != 0) {
        // 0x80030760: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_80030720;
    }
    // 0x80030760: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80030764: addiu       $v0, $a3, -0x1
    ctx->r2 = ADD32(ctx->r7, -0X1);
    // 0x80030768: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x8003076C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030770: bgez        $v0, L_80030714
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80030774: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80030714;
    }
    // 0x80030774: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80030778: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
L_8003077C:
    // 0x8003077C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80030780: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80030784:
    // 0x80030784: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x80030788: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003078C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80030790: addu        $a1, $v0, $a0
    ctx->r5 = ADD32(ctx->r2, ctx->r4);
    // 0x80030794: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
L_80030798:
    // 0x80030798: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003079C: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800307A0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800307A4: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800307A8: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x800307AC: beq         $v0, $zero, L_800307BC
    if (ctx->r2 == 0) {
        // 0x800307B0: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_800307BC;
    }
    // 0x800307B0: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800307B4: j           L_800307F4
    // 0x800307B8: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
        goto L_800307F4;
    // 0x800307B8: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
L_800307BC:
    // 0x800307BC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800307C0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800307C4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800307C8: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x800307CC: bne         $v0, $zero, L_80030798
    if (ctx->r2 != 0) {
        // 0x800307D0: sll         $v0, $v1, 16
        ctx->r2 = S32(ctx->r3 << 16);
            goto L_80030798;
    }
    // 0x800307D0: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800307D4: addiu       $v0, $a3, 0x1
    ctx->r2 = ADD32(ctx->r7, 0X1);
    // 0x800307D8: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x800307DC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800307E0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800307E4: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x800307E8: bne         $v0, $zero, L_80030784
    if (ctx->r2 != 0) {
        // 0x800307EC: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80030784;
    }
    // 0x800307EC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800307F0: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
L_800307F4:
    // 0x800307F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800307F8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800307FC:
    // 0x800307FC: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80030800: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030804: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80030808: addu        $a3, $v0, $a0
    ctx->r7 = ADD32(ctx->r2, ctx->r4);
    // 0x8003080C: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
L_80030810:
    // 0x80030810: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030814: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x80030818: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8003081C: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80030820: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x80030824: beq         $v0, $zero, L_80030834
    if (ctx->r2 == 0) {
        // 0x80030828: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80030834;
    }
    // 0x80030828: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8003082C: j           L_80030864
    // 0x80030830: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
        goto L_80030864;
    // 0x80030830: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
L_80030834:
    // 0x80030834: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80030838: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8003083C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030840: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80030844: bne         $v0, $zero, L_80030810
    if (ctx->r2 != 0) {
        // 0x80030848: sll         $v0, $v1, 16
        ctx->r2 = S32(ctx->r3 << 16);
            goto L_80030810;
    }
    // 0x80030848: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8003084C: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x80030850: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80030854: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030858: bgezl       $v0, L_800307FC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003085C: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800307FC;
    }
    goto skip_0;
    // 0x8003085C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    skip_0:
    // 0x80030860: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80030864:
    // 0x80030864: addu        $t6, $zero, $zero
    ctx->r14 = ADD32(0, 0);
    // 0x80030868: sll         $s7, $t5, 16
    ctx->r23 = S32(ctx->r13 << 16);
    // 0x8003086C: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x80030870: sra         $fp, $v0, 16
    ctx->r30 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030874: sra         $t9, $s7, 16
    ctx->r25 = S32(SIGNED(ctx->r23) >> 16);
    // 0x80030878: slt         $s2, $fp, $t9
    ctx->r18 = SIGNED(ctx->r30) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8003087C: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x80030880: sll         $s7, $s0, 16
    ctx->r23 = S32(ctx->r16 << 16);
    // 0x80030884: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x80030888: sra         $s1, $v0, 16
    ctx->r17 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003088C: sra         $s5, $s7, 16
    ctx->r21 = S32(SIGNED(ctx->r23) >> 16);
    // 0x80030890: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x80030894: slt         $s7, $s5, $s1
    ctx->r23 = SIGNED(ctx->r21) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80030898: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
L_8003089C:
    // 0x8003089C: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x800308A0: sra         $a1, $s7, 16
    ctx->r5 = S32(SIGNED(ctx->r23) >> 16);
    // 0x800308A4: slt         $v0, $a1, $s1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800308A8: bnel        $v0, $zero, L_80030950
    if (ctx->r2 != 0) {
        // 0x800308AC: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80030950;
    }
    goto skip_1;
    // 0x800308AC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    skip_1:
    // 0x800308B0: sll         $v0, $t6, 16
    ctx->r2 = S32(ctx->r14 << 16);
    // 0x800308B4: sra         $t4, $v0, 16
    ctx->r12 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800308B8: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800308BC: addu        $a3, $v0, $a1
    ctx->r7 = ADD32(ctx->r2, ctx->r5);
L_800308C0:
    // 0x800308C0: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x800308C4: sra         $a0, $s7, 16
    ctx->r4 = S32(SIGNED(ctx->r23) >> 16);
    // 0x800308C8: slt         $v0, $fp, $a0
    ctx->r2 = SIGNED(ctx->r30) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800308CC: bnel        $v0, $zero, L_80030940
    if (ctx->r2 != 0) {
        // 0x800308D0: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_80030940;
    }
    goto skip_2;
    // 0x800308D0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    skip_2:
    // 0x800308D4: addu        $t3, $a3, $zero
    ctx->r11 = ADD32(ctx->r7, 0);
    // 0x800308D8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800308DC: lw          $t2, 0x110($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X110);
    // 0x800308E0: subu        $v0, $s5, $a1
    ctx->r2 = SUB32(ctx->r21, ctx->r5);
    // 0x800308E4: subu        $v0, $s7, $v0
    ctx->r2 = SUB32(ctx->r23, ctx->r2);
    // 0x800308E8: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x800308EC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800308F0: sll         $t1, $v1, 1
    ctx->r9 = S32(ctx->r3 << 1);
    // 0x800308F4: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x800308F8: sra         $t0, $v0, 16
    ctx->r8 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800308FC: addu        $v0, $t3, $a0
    ctx->r2 = ADD32(ctx->r11, ctx->r4);
L_80030900:
    // 0x80030900: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80030904: subu        $v1, $a0, $t9
    ctx->r3 = SUB32(ctx->r4, ctx->r25);
    // 0x80030908: addu        $v1, $t4, $v1
    ctx->r3 = ADD32(ctx->r12, ctx->r3);
    // 0x8003090C: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x80030910: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x80030914: lbu         $v1, 0x70($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X70);
    // 0x80030918: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x8003091C: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80030920: beq         $v1, $zero, L_80030930
    if (ctx->r3 == 0) {
        // 0x80030924: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80030930;
    }
    // 0x80030924: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80030928: bnel        $v0, $zero, L_80030950
    if (ctx->r2 != 0) {
        // 0x8003092C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80030950;
    }
    goto skip_3;
    // 0x8003092C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_3:
L_80030930:
    // 0x80030930: slt         $v0, $t0, $a0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80030934: beq         $v0, $zero, L_80030900
    if (ctx->r2 == 0) {
        // 0x80030938: addu        $v0, $t3, $a0
        ctx->r2 = ADD32(ctx->r11, ctx->r4);
            goto L_80030900;
    }
    // 0x80030938: addu        $v0, $t3, $a0
    ctx->r2 = ADD32(ctx->r11, ctx->r4);
    // 0x8003093C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
L_80030940:
    // 0x80030940: slt         $v0, $a1, $s1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80030944: beq         $v0, $zero, L_800308C0
    if (ctx->r2 == 0) {
        // 0x80030948: addiu       $a3, $a3, -0x5
        ctx->r7 = ADD32(ctx->r7, -0X5);
            goto L_800308C0;
    }
    // 0x80030948: addiu       $a3, $a3, -0x5
    ctx->r7 = ADD32(ctx->r7, -0X5);
    // 0x8003094C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80030950:
    // 0x80030950: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80030954: bnel        $v0, $zero, L_8003171C
    if (ctx->r2 != 0) {
        // 0x80030958: addiu       $v0, $t6, 0x1
        ctx->r2 = ADD32(ctx->r14, 0X1);
            goto L_8003171C;
    }
    goto skip_4;
    // 0x80030958: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    skip_4:
    // 0x8003095C: bne         $s2, $zero, L_80030A44
    if (ctx->r18 != 0) {
        // 0x80030960: addu        $t0, $t5, $zero
        ctx->r8 = ADD32(ctx->r13, 0);
            goto L_80030A44;
    }
    // 0x80030960: addu        $t0, $t5, $zero
    ctx->r8 = ADD32(ctx->r13, 0);
    // 0x80030964: sll         $v0, $t6, 16
    ctx->r2 = S32(ctx->r14 << 16);
    // 0x80030968: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003096C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80030970:
    // 0x80030970: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80030974: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x80030978: sra         $a3, $v0, 16
    ctx->r7 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003097C: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_80030980:
    // 0x80030980: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030984: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80030988: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003098C: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80030990: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80030994: addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // 0x80030998: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8003099C: bnel        $v0, $zero, L_800309A4
    if (ctx->r2 != 0) {
        // 0x800309A0: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_800309A4;
    }
    goto skip_5;
    // 0x800309A0: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    skip_5:
L_800309A4:
    // 0x800309A4: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800309A8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800309AC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800309B0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800309B4: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x800309B8: bne         $v0, $zero, L_80030980
    if (ctx->r2 != 0) {
        // 0x800309BC: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_80030980;
    }
    // 0x800309BC: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x800309C0: lhu         $s7, 0x16($sp)
    ctx->r23 = MEM_HU(ctx->r29, 0X16);
    // 0x800309C4: subu        $v0, $s0, $a1
    ctx->r2 = SUB32(ctx->r16, ctx->r5);
    // 0x800309C8: subu        $v0, $s7, $v0
    ctx->r2 = SUB32(ctx->r23, ctx->r2);
    // 0x800309CC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800309D0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800309D4: bltz        $v0, L_80030A2C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800309D8: addiu       $v0, $t0, 0x1
        ctx->r2 = ADD32(ctx->r8, 0X1);
            goto L_80030A2C;
    }
    // 0x800309D8: addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
    // 0x800309DC: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x800309E0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800309E4: lw          $v1, 0x110($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X110);
    // 0x800309E8: subu        $v0, $v0, $t9
    ctx->r2 = SUB32(ctx->r2, ctx->r25);
    // 0x800309EC: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x800309F0: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // 0x800309F4: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_800309F8:
    // 0x800309F8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800309FC: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80030A00: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80030A04: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80030A08: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x80030A0C: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x80030A10: bne         $v0, $zero, L_80030C70
    if (ctx->r2 != 0) {
        // 0x80030A14: addiu       $v0, $a0, -0x1
        ctx->r2 = ADD32(ctx->r4, -0X1);
            goto L_80030C70;
    }
    // 0x80030A14: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x80030A18: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80030A1C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030A20: bgez        $v0, L_800309F8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80030A24: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_800309F8;
    }
    // 0x80030A24: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80030A28: addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
L_80030A2C:
    // 0x80030A2C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80030A30: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030A34: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030A38: slt         $v0, $fp, $v0
    ctx->r2 = SIGNED(ctx->r30) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80030A3C: beq         $v0, $zero, L_80030970
    if (ctx->r2 == 0) {
        // 0x80030A40: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80030970;
    }
    // 0x80030A40: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80030A44:
    // 0x80030A44: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80030A48:
    // 0x80030A48: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80030A4C: bnel        $v0, $zero, L_8003171C
    if (ctx->r2 != 0) {
        // 0x80030A50: addiu       $v0, $t6, 0x1
        ctx->r2 = ADD32(ctx->r14, 0X1);
            goto L_8003171C;
    }
    goto skip_6;
    // 0x80030A50: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    skip_6:
    // 0x80030A54: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x80030A58: bne         $s2, $zero, L_80030B5C
    if (ctx->r18 != 0) {
        // 0x80030A5C: addu        $t0, $t5, $zero
        ctx->r8 = ADD32(ctx->r13, 0);
            goto L_80030B5C;
    }
    // 0x80030A5C: addu        $t0, $t5, $zero
    ctx->r8 = ADD32(ctx->r13, 0);
    // 0x80030A60: sll         $v0, $t6, 16
    ctx->r2 = S32(ctx->r14 << 16);
    // 0x80030A64: sra         $t2, $v0, 16
    ctx->r10 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030A68: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80030A6C:
    // 0x80030A6C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80030A70: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x80030A74: sra         $a3, $v0, 16
    ctx->r7 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030A78: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_80030A7C:
    // 0x80030A7C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030A80: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80030A84: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80030A88: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80030A8C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80030A90: addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // 0x80030A94: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80030A98: bnel        $v0, $zero, L_80030AA0
    if (ctx->r2 != 0) {
        // 0x80030A9C: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_80030AA0;
    }
    goto skip_7;
    // 0x80030A9C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    skip_7:
L_80030AA0:
    // 0x80030AA0: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80030AA4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80030AA8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030AAC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030AB0: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80030AB4: bne         $v0, $zero, L_80030A7C
    if (ctx->r2 != 0) {
        // 0x80030AB8: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_80030A7C;
    }
    // 0x80030AB8: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80030ABC: lhu         $s7, 0x16($sp)
    ctx->r23 = MEM_HU(ctx->r29, 0X16);
    // 0x80030AC0: subu        $v0, $s0, $a1
    ctx->r2 = SUB32(ctx->r16, ctx->r5);
    // 0x80030AC4: subu        $v0, $s7, $v0
    ctx->r2 = SUB32(ctx->r23, ctx->r2);
    // 0x80030AC8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80030ACC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80030AD0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030AD4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030AD8: slti        $v0, $v0, 0x12
    ctx->r2 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x80030ADC: beq         $v0, $zero, L_80030B44
    if (ctx->r2 == 0) {
        // 0x80030AE0: addiu       $v0, $t0, 0x1
        ctx->r2 = ADD32(ctx->r8, 0X1);
            goto L_80030B44;
    }
    // 0x80030AE0: addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
    // 0x80030AE4: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x80030AE8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030AEC: lw          $v1, 0x110($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X110);
    // 0x80030AF0: subu        $v0, $v0, $t9
    ctx->r2 = SUB32(ctx->r2, ctx->r25);
    // 0x80030AF4: addu        $v0, $t2, $v0
    ctx->r2 = ADD32(ctx->r10, ctx->r2);
    // 0x80030AF8: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // 0x80030AFC: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_80030B00:
    // 0x80030B00: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030B04: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80030B08: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80030B0C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80030B10: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x80030B14: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x80030B18: bnel        $v0, $zero, L_80030B24
    if (ctx->r2 != 0) {
        // 0x80030B1C: addiu       $a0, $zero, 0x12
        ctx->r4 = ADD32(0, 0X12);
            goto L_80030B24;
    }
    goto skip_8;
    // 0x80030B1C: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    skip_8:
    // 0x80030B20: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_80030B24:
    // 0x80030B24: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80030B28: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80030B2C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030B30: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030B34: slti        $v0, $v0, 0x12
    ctx->r2 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x80030B38: bne         $v0, $zero, L_80030B00
    if (ctx->r2 != 0) {
        // 0x80030B3C: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_80030B00;
    }
    // 0x80030B3C: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80030B40: addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
L_80030B44:
    // 0x80030B44: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80030B48: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030B4C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030B50: slt         $v0, $fp, $v0
    ctx->r2 = SIGNED(ctx->r30) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80030B54: beql        $v0, $zero, L_80030A6C
    if (ctx->r2 == 0) {
        // 0x80030B58: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80030A6C;
    }
    goto skip_9;
    // 0x80030B58: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    skip_9:
L_80030B5C:
    // 0x80030B5C: sb          $t1, 0x0($sp)
    MEM_B(0X0, ctx->r29) = ctx->r9;
    // 0x80030B60: lb          $v0, 0x54($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X54);
    // 0x80030B64: bne         $v0, $zero, L_80030CBC
    if (ctx->r2 != 0) {
        // 0x80030B68: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_80030CBC;
    }
    // 0x80030B68: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80030B6C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80030B70: bne         $s7, $zero, L_80030C30
    if (ctx->r23 != 0) {
        // 0x80030B74: addu        $t0, $s0, $zero
        ctx->r8 = ADD32(ctx->r16, 0);
            goto L_80030C30;
    }
    // 0x80030B74: addu        $t0, $s0, $zero
    ctx->r8 = ADD32(ctx->r16, 0);
    // 0x80030B78: sll         $v0, $t6, 16
    ctx->r2 = S32(ctx->r14 << 16);
    // 0x80030B7C: sra         $t4, $v0, 16
    ctx->r12 = S32(SIGNED(ctx->r2) >> 16);
L_80030B80:
    // 0x80030B80: bne         $s2, $zero, L_80030C14
    if (ctx->r18 != 0) {
        // 0x80030B84: addu        $a1, $t5, $zero
        ctx->r5 = ADD32(ctx->r13, 0);
            goto L_80030C14;
    }
    // 0x80030B84: addu        $a1, $t5, $zero
    ctx->r5 = ADD32(ctx->r13, 0);
    // 0x80030B88: lw          $t3, 0x110($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X110);
    // 0x80030B8C: sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8 << 16);
    // 0x80030B90: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80030B94: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80030B98: subu        $v1, $s5, $a0
    ctx->r3 = SUB32(ctx->r21, ctx->r4);
    // 0x80030B9C: subu        $v1, $s7, $v1
    ctx->r3 = SUB32(ctx->r23, ctx->r3);
    // 0x80030BA0: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80030BA4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80030BA8: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x80030BAC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80030BB0: addu        $t1, $v0, $a0
    ctx->r9 = ADD32(ctx->r2, ctx->r4);
    // 0x80030BB4: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x80030BB8: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030BBC: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_80030BC0:
    // 0x80030BC0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030BC4: subu        $v1, $v0, $t9
    ctx->r3 = SUB32(ctx->r2, ctx->r25);
    // 0x80030BC8: addu        $v1, $t4, $v1
    ctx->r3 = ADD32(ctx->r12, ctx->r3);
    // 0x80030BCC: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x80030BD0: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80030BD4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80030BD8: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80030BDC: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x80030BE0: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x80030BE4: lbu         $v1, 0x82($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X82);
    // 0x80030BE8: beql        $v0, $zero, L_80030BFC
    if (ctx->r2 == 0) {
        // 0x80030BEC: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_80030BFC;
    }
    goto skip_10;
    // 0x80030BEC: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    skip_10:
    // 0x80030BF0: bnel        $v1, $zero, L_80030BF8
    if (ctx->r3 != 0) {
        // 0x80030BF4: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80030BF8;
    }
    goto skip_11;
    // 0x80030BF4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_11:
L_80030BF8:
    // 0x80030BF8: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
L_80030BFC:
    // 0x80030BFC: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80030C00: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030C04: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030C08: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80030C0C: beq         $v0, $zero, L_80030BC0
    if (ctx->r2 == 0) {
        // 0x80030C10: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_80030BC0;
    }
    // 0x80030C10: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_80030C14:
    // 0x80030C14: addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // 0x80030C18: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80030C1C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030C20: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030C24: slt         $v0, $v0, $s1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80030C28: beq         $v0, $zero, L_80030B80
    if (ctx->r2 == 0) {
        // 0x80030C2C: nop
    
            goto L_80030B80;
    }
    // 0x80030C2C: nop

L_80030C30:
    // 0x80030C30: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x80030C34: lbu         $v1, 0x120($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X120);
    // 0x80030C38: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030C3C: sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3 << 24);
    // 0x80030C40: sra         $v0, $v1, 24
    ctx->r2 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80030C44: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80030C48: beq         $v0, $zero, L_80030C78
    if (ctx->r2 == 0) {
        // 0x80030C4C: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_80030C78;
    }
    // 0x80030C4C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80030C50: addiu       $v0, $t6, 0x2
    ctx->r2 = ADD32(ctx->r14, 0X2);
    // 0x80030C54: subu        $v0, $v0, $t5
    ctx->r2 = SUB32(ctx->r2, ctx->r13);
    // 0x80030C58: sb          $a1, 0x120($a2)
    MEM_B(0X120, ctx->r6) = ctx->r5;
    // 0x80030C5C: sb          $v0, 0x122($a2)
    MEM_B(0X122, ctx->r6) = ctx->r2;
    // 0x80030C60: sb          $t7, 0x121($a2)
    MEM_B(0X121, ctx->r6) = ctx->r15;
    // 0x80030C64: lbu         $v0, 0x0($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X0);
    // 0x80030C68: j           L_80031714
    // 0x80030C6C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
        goto L_80031714;
    // 0x80030C6C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_80030C70:
    // 0x80030C70: j           L_80030A48
    // 0x80030C74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80030A48;
    // 0x80030C74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80030C78:
    // 0x80030C78: sra         $v0, $v1, 24
    ctx->r2 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80030C7C: bne         $v0, $a0, L_8003171C
    if (ctx->r2 != ctx->r4) {
        // 0x80030C80: addiu       $v0, $t6, 0x1
        ctx->r2 = ADD32(ctx->r14, 0X1);
            goto L_8003171C;
    }
    // 0x80030C80: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80030C84: lb          $v1, 0x0($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X0);
    // 0x80030C88: lb          $v0, 0x1($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X1);
    // 0x80030C8C: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80030C90: beq         $v1, $zero, L_80031718
    if (ctx->r3 == 0) {
        // 0x80030C94: addiu       $v0, $t6, 0x2
        ctx->r2 = ADD32(ctx->r14, 0X2);
            goto L_80031718;
    }
    // 0x80030C94: addiu       $v0, $t6, 0x2
    ctx->r2 = ADD32(ctx->r14, 0X2);
    // 0x80030C98: subu        $v0, $v0, $t5
    ctx->r2 = SUB32(ctx->r2, ctx->r13);
    // 0x80030C9C: sb          $a1, 0x120($a2)
    MEM_B(0X120, ctx->r6) = ctx->r5;
    // 0x80030CA0: sb          $v0, 0x122($a2)
    MEM_B(0X122, ctx->r6) = ctx->r2;
    // 0x80030CA4: sb          $t7, 0x121($a2)
    MEM_B(0X121, ctx->r6) = ctx->r15;
    // 0x80030CA8: lbu         $v0, 0x0($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X0);
    // 0x80030CAC: j           L_80031714
    // 0x80030CB0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
        goto L_80031714;
    // 0x80030CB0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_80030CB4:
    // 0x80030CB4: j           L_80030E74
    // 0x80030CB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80030E74;
    // 0x80030CB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80030CBC:
    // 0x80030CBC: lbu         $v0, 0x55($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X55);
    // 0x80030CC0: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80030CC4: beq         $v0, $zero, L_800312F4
    if (ctx->r2 == 0) {
        // 0x80030CC8: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_800312F4;
    }
    // 0x80030CC8: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x80030CCC: bne         $s2, $zero, L_80030DEC
    if (ctx->r18 != 0) {
        // 0x80030CD0: addu        $t1, $t5, $zero
        ctx->r9 = ADD32(ctx->r13, 0);
            goto L_80030DEC;
    }
    // 0x80030CD0: addu        $t1, $t5, $zero
    ctx->r9 = ADD32(ctx->r13, 0);
    // 0x80030CD4: sll         $v0, $t6, 16
    ctx->r2 = S32(ctx->r14 << 16);
    // 0x80030CD8: sra         $t3, $v0, 16
    ctx->r11 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030CDC: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
L_80030CE0:
    // 0x80030CE0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80030CE4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80030CE8: sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9 << 16);
    // 0x80030CEC: sra         $a3, $v0, 16
    ctx->r7 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030CF0: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_80030CF4:
    // 0x80030CF4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030CF8: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80030CFC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80030D00: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80030D04: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80030D08: addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // 0x80030D0C: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80030D10: bnel        $v0, $zero, L_80030D18
    if (ctx->r2 != 0) {
        // 0x80030D14: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_80030D18;
    }
    goto skip_12;
    // 0x80030D14: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    skip_12:
L_80030D18:
    // 0x80030D18: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80030D1C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80030D20: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030D24: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030D28: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80030D2C: bne         $v0, $zero, L_80030CF4
    if (ctx->r2 != 0) {
        // 0x80030D30: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_80030CF4;
    }
    // 0x80030D30: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80030D34: lhu         $s7, 0x16($sp)
    ctx->r23 = MEM_HU(ctx->r29, 0X16);
    // 0x80030D38: subu        $v0, $s0, $a1
    ctx->r2 = SUB32(ctx->r16, ctx->r5);
    // 0x80030D3C: subu        $v0, $s7, $v0
    ctx->r2 = SUB32(ctx->r23, ctx->r2);
    // 0x80030D40: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80030D44: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80030D48: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030D4C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030D50: slti        $v0, $v0, 0x12
    ctx->r2 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x80030D54: beq         $v0, $zero, L_80030DB4
    if (ctx->r2 == 0) {
        // 0x80030D58: sll         $v0, $t1, 16
        ctx->r2 = S32(ctx->r9 << 16);
            goto L_80030DB4;
    }
    // 0x80030D58: sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9 << 16);
    // 0x80030D5C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030D60: lw          $v1, 0x110($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X110);
    // 0x80030D64: subu        $v0, $v0, $t9
    ctx->r2 = SUB32(ctx->r2, ctx->r25);
    // 0x80030D68: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x80030D6C: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // 0x80030D70: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_80030D74:
    // 0x80030D74: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030D78: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80030D7C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80030D80: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80030D84: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x80030D88: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x80030D8C: bnel        $v0, $zero, L_80030D98
    if (ctx->r2 != 0) {
        // 0x80030D90: addiu       $a0, $zero, 0x12
        ctx->r4 = ADD32(0, 0X12);
            goto L_80030D98;
    }
    goto skip_13;
    // 0x80030D90: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    skip_13:
    // 0x80030D94: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_80030D98:
    // 0x80030D98: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80030D9C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80030DA0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030DA4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030DA8: slti        $v0, $v0, 0x12
    ctx->r2 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x80030DAC: bne         $v0, $zero, L_80030D74
    if (ctx->r2 != 0) {
        // 0x80030DB0: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_80030D74;
    }
    // 0x80030DB0: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_80030DB4:
    // 0x80030DB4: sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8 << 16);
    // 0x80030DB8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80030DBC: sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10 << 16);
    // 0x80030DC0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030DC4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80030DC8: bnel        $v0, $zero, L_80030DD0
    if (ctx->r2 != 0) {
        // 0x80030DCC: addu        $t2, $t0, $zero
        ctx->r10 = ADD32(ctx->r8, 0);
            goto L_80030DD0;
    }
    goto skip_14;
    // 0x80030DCC: addu        $t2, $t0, $zero
    ctx->r10 = ADD32(ctx->r8, 0);
    skip_14:
L_80030DD0:
    // 0x80030DD0: addiu       $v0, $t1, 0x1
    ctx->r2 = ADD32(ctx->r9, 0X1);
    // 0x80030DD4: addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
    // 0x80030DD8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030DDC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030DE0: slt         $v0, $fp, $v0
    ctx->r2 = SIGNED(ctx->r30) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80030DE4: beql        $v0, $zero, L_80030CE0
    if (ctx->r2 == 0) {
        // 0x80030DE8: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_80030CE0;
    }
    goto skip_15;
    // 0x80030DE8: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    skip_15:
L_80030DEC:
    // 0x80030DEC: sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10 << 16);
    // 0x80030DF0: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030DF4: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80030DF8: bne         $v0, $zero, L_80031114
    if (ctx->r2 != 0) {
        // 0x80030DFC: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_80031114;
    }
    // 0x80030DFC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80030E00: slti        $v0, $v1, 0x7
    ctx->r2 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // 0x80030E04: beq         $v0, $zero, L_80030FC0
    if (ctx->r2 == 0) {
        // 0x80030E08: addiu       $a1, $zero, 0x7
        ctx->r5 = ADD32(0, 0X7);
            goto L_80030FC0;
    }
    // 0x80030E08: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80030E0C: lw          $a3, 0x110($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X110);
    // 0x80030E10: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80030E14:
    // 0x80030E14: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80030E18: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80030E1C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80030E20: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80030E24: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80030E28: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_80030E2C:
    // 0x80030E2C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030E30: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80030E34: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80030E38: lbu         $v0, 0x70($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X70);
    // 0x80030E3C: bne         $v0, $zero, L_80030CB4
    if (ctx->r2 != 0) {
        // 0x80030E40: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_80030CB4;
    }
    // 0x80030E40: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80030E44: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80030E48: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030E4C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030E50: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80030E54: bne         $v0, $zero, L_80030E2C
    if (ctx->r2 != 0) {
        // 0x80030E58: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_80030E2C;
    }
    // 0x80030E58: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80030E5C: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x80030E60: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80030E64: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030E68: bgezl       $v0, L_80030E14
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80030E6C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80030E14;
    }
    goto skip_16;
    // 0x80030E6C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_16:
    // 0x80030E70: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80030E74:
    // 0x80030E74: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80030E78: beq         $v0, $zero, L_80030F8C
    if (ctx->r2 == 0) {
        // 0x80030E7C: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_80030F8C;
    }
    // 0x80030E7C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80030E80: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80030E84: bne         $s7, $zero, L_80030F44
    if (ctx->r23 != 0) {
        // 0x80030E88: addu        $t0, $s0, $zero
        ctx->r8 = ADD32(ctx->r16, 0);
            goto L_80030F44;
    }
    // 0x80030E88: addu        $t0, $s0, $zero
    ctx->r8 = ADD32(ctx->r16, 0);
    // 0x80030E8C: sll         $v0, $t6, 16
    ctx->r2 = S32(ctx->r14 << 16);
    // 0x80030E90: sra         $t4, $v0, 16
    ctx->r12 = S32(SIGNED(ctx->r2) >> 16);
L_80030E94:
    // 0x80030E94: bne         $s2, $zero, L_80030F28
    if (ctx->r18 != 0) {
        // 0x80030E98: addu        $a1, $t5, $zero
        ctx->r5 = ADD32(ctx->r13, 0);
            goto L_80030F28;
    }
    // 0x80030E98: addu        $a1, $t5, $zero
    ctx->r5 = ADD32(ctx->r13, 0);
    // 0x80030E9C: lw          $t3, 0x110($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X110);
    // 0x80030EA0: sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8 << 16);
    // 0x80030EA4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80030EA8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80030EAC: subu        $v1, $s5, $a0
    ctx->r3 = SUB32(ctx->r21, ctx->r4);
    // 0x80030EB0: subu        $v1, $s7, $v1
    ctx->r3 = SUB32(ctx->r23, ctx->r3);
    // 0x80030EB4: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80030EB8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80030EBC: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x80030EC0: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80030EC4: addu        $t1, $v0, $a0
    ctx->r9 = ADD32(ctx->r2, ctx->r4);
    // 0x80030EC8: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x80030ECC: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030ED0: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_80030ED4:
    // 0x80030ED4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030ED8: subu        $v1, $v0, $t9
    ctx->r3 = SUB32(ctx->r2, ctx->r25);
    // 0x80030EDC: addu        $v1, $t4, $v1
    ctx->r3 = ADD32(ctx->r12, ctx->r3);
    // 0x80030EE0: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x80030EE4: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80030EE8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80030EEC: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80030EF0: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x80030EF4: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x80030EF8: lbu         $v1, 0x82($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X82);
    // 0x80030EFC: beql        $v0, $zero, L_80030F10
    if (ctx->r2 == 0) {
        // 0x80030F00: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_80030F10;
    }
    goto skip_17;
    // 0x80030F00: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    skip_17:
    // 0x80030F04: bnel        $v1, $zero, L_80030F0C
    if (ctx->r3 != 0) {
        // 0x80030F08: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80030F0C;
    }
    goto skip_18;
    // 0x80030F08: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_18:
L_80030F0C:
    // 0x80030F0C: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
L_80030F10:
    // 0x80030F10: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80030F14: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030F18: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030F1C: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80030F20: beq         $v0, $zero, L_80030ED4
    if (ctx->r2 == 0) {
        // 0x80030F24: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_80030ED4;
    }
    // 0x80030F24: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_80030F28:
    // 0x80030F28: addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // 0x80030F2C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80030F30: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80030F34: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80030F38: slt         $v0, $v0, $s1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80030F3C: beq         $v0, $zero, L_80030E94
    if (ctx->r2 == 0) {
        // 0x80030F40: nop
    
            goto L_80030E94;
    }
    // 0x80030F40: nop

L_80030F44:
    // 0x80030F44: sll         $v1, $a3, 16
    ctx->r3 = S32(ctx->r7 << 16);
    // 0x80030F48: lbu         $v0, 0x54($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X54);
    // 0x80030F4C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80030F50: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // 0x80030F54: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80030F58: bne         $v0, $zero, L_800316F4
    if (ctx->r2 != 0) {
        // 0x80030F5C: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_800316F4;
    }
    // 0x80030F5C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x80030F60: lbu         $v0, 0x120($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X120);
    // 0x80030F64: sll         $a0, $v0, 24
    ctx->r4 = S32(ctx->r2 << 24);
    // 0x80030F68: sra         $v0, $a0, 24
    ctx->r2 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80030F6C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80030F70: bne         $v0, $zero, L_800316F8
    if (ctx->r2 != 0) {
        // 0x80030F74: addiu       $v0, $t6, 0x2
        ctx->r2 = ADD32(ctx->r14, 0X2);
            goto L_800316F8;
    }
    // 0x80030F74: addiu       $v0, $t6, 0x2
    ctx->r2 = ADD32(ctx->r14, 0X2);
    // 0x80030F78: sra         $v0, $a0, 24
    ctx->r2 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80030F7C: bne         $v0, $v1, L_8003171C
    if (ctx->r2 != ctx->r3) {
        // 0x80030F80: addiu       $v0, $t6, 0x1
        ctx->r2 = ADD32(ctx->r14, 0X1);
            goto L_8003171C;
    }
    // 0x80030F80: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80030F84: j           L_800316E0
    // 0x80030F88: nop

        goto L_800316E0;
    // 0x80030F88: nop

L_80030F8C:
    // 0x80030F8C: lbu         $v0, 0x54($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X54);
    // 0x80030F90: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // 0x80030F94: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80030F98: beq         $v0, $zero, L_8003171C
    if (ctx->r2 == 0) {
        // 0x80030F9C: addiu       $v0, $t6, 0x1
        ctx->r2 = ADD32(ctx->r14, 0X1);
            goto L_8003171C;
    }
    // 0x80030F9C: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80030FA0: lbu         $v0, 0x55($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X55);
    // 0x80030FA4: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80030FA8: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // 0x80030FAC: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80030FB0: beq         $v0, $zero, L_8003171C
    if (ctx->r2 == 0) {
        // 0x80030FB4: addiu       $v0, $t6, 0x1
        ctx->r2 = ADD32(ctx->r14, 0X1);
            goto L_8003171C;
    }
    // 0x80030FB4: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80030FB8: j           L_800316F8
    // 0x80030FBC: addiu       $v0, $t6, 0x2
    ctx->r2 = ADD32(ctx->r14, 0X2);
        goto L_800316F8;
    // 0x80030FBC: addiu       $v0, $t6, 0x2
    ctx->r2 = ADD32(ctx->r14, 0X2);
L_80030FC0:
    // 0x80030FC0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80030FC4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80030FC8: bne         $s7, $zero, L_80031088
    if (ctx->r23 != 0) {
        // 0x80030FCC: addu        $t0, $s0, $zero
        ctx->r8 = ADD32(ctx->r16, 0);
            goto L_80031088;
    }
    // 0x80030FCC: addu        $t0, $s0, $zero
    ctx->r8 = ADD32(ctx->r16, 0);
    // 0x80030FD0: sll         $v0, $t6, 16
    ctx->r2 = S32(ctx->r14 << 16);
    // 0x80030FD4: sra         $t4, $v0, 16
    ctx->r12 = S32(SIGNED(ctx->r2) >> 16);
L_80030FD8:
    // 0x80030FD8: bne         $s2, $zero, L_8003106C
    if (ctx->r18 != 0) {
        // 0x80030FDC: addu        $a1, $t5, $zero
        ctx->r5 = ADD32(ctx->r13, 0);
            goto L_8003106C;
    }
    // 0x80030FDC: addu        $a1, $t5, $zero
    ctx->r5 = ADD32(ctx->r13, 0);
    // 0x80030FE0: lw          $t3, 0x110($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X110);
    // 0x80030FE4: sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8 << 16);
    // 0x80030FE8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80030FEC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80030FF0: subu        $v1, $s5, $a0
    ctx->r3 = SUB32(ctx->r21, ctx->r4);
    // 0x80030FF4: subu        $v1, $s7, $v1
    ctx->r3 = SUB32(ctx->r23, ctx->r3);
    // 0x80030FF8: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80030FFC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80031000: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x80031004: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80031008: addu        $t1, $v0, $a0
    ctx->r9 = ADD32(ctx->r2, ctx->r4);
    // 0x8003100C: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x80031010: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031014: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_80031018:
    // 0x80031018: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003101C: subu        $v1, $v0, $t9
    ctx->r3 = SUB32(ctx->r2, ctx->r25);
    // 0x80031020: addu        $v1, $t4, $v1
    ctx->r3 = ADD32(ctx->r12, ctx->r3);
    // 0x80031024: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x80031028: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x8003102C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80031030: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80031034: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x80031038: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x8003103C: lbu         $v1, 0x82($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X82);
    // 0x80031040: beql        $v0, $zero, L_80031054
    if (ctx->r2 == 0) {
        // 0x80031044: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_80031054;
    }
    goto skip_19;
    // 0x80031044: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    skip_19:
    // 0x80031048: bnel        $v1, $zero, L_80031050
    if (ctx->r3 != 0) {
        // 0x8003104C: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80031050;
    }
    goto skip_20;
    // 0x8003104C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_20:
L_80031050:
    // 0x80031050: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
L_80031054:
    // 0x80031054: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80031058: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8003105C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031060: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80031064: beq         $v0, $zero, L_80031018
    if (ctx->r2 == 0) {
        // 0x80031068: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_80031018;
    }
    // 0x80031068: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_8003106C:
    // 0x8003106C: addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // 0x80031070: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80031074: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80031078: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003107C: slt         $v0, $v0, $s1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80031080: beq         $v0, $zero, L_80030FD8
    if (ctx->r2 == 0) {
        // 0x80031084: nop
    
            goto L_80030FD8;
    }
    // 0x80031084: nop

L_80031088:
    // 0x80031088: sll         $v1, $a3, 16
    ctx->r3 = S32(ctx->r7 << 16);
    // 0x8003108C: lbu         $v0, 0x54($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X54);
    // 0x80031090: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80031094: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // 0x80031098: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8003109C: bne         $v0, $zero, L_800316F4
    if (ctx->r2 != 0) {
        // 0x800310A0: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_800316F4;
    }
    // 0x800310A0: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x800310A4: lbu         $v0, 0x120($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X120);
    // 0x800310A8: sll         $a0, $v0, 24
    ctx->r4 = S32(ctx->r2 << 24);
    // 0x800310AC: sra         $v0, $a0, 24
    ctx->r2 = S32(SIGNED(ctx->r4) >> 24);
    // 0x800310B0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800310B4: beq         $v0, $zero, L_800310D8
    if (ctx->r2 == 0) {
        // 0x800310B8: addiu       $v0, $t6, 0x2
        ctx->r2 = ADD32(ctx->r14, 0X2);
            goto L_800310D8;
    }
    // 0x800310B8: addiu       $v0, $t6, 0x2
    ctx->r2 = ADD32(ctx->r14, 0X2);
    // 0x800310BC: subu        $v0, $v0, $t5
    ctx->r2 = SUB32(ctx->r2, ctx->r13);
    // 0x800310C0: sb          $a1, 0x120($a2)
    MEM_B(0X120, ctx->r6) = ctx->r5;
    // 0x800310C4: sb          $v0, 0x122($a2)
    MEM_B(0X122, ctx->r6) = ctx->r2;
    // 0x800310C8: sb          $t7, 0x121($a2)
    MEM_B(0X121, ctx->r6) = ctx->r15;
    // 0x800310CC: lbu         $v0, 0x0($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X0);
    // 0x800310D0: j           L_80031714
    // 0x800310D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
        goto L_80031714;
    // 0x800310D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_800310D8:
    // 0x800310D8: sra         $v0, $a0, 24
    ctx->r2 = S32(SIGNED(ctx->r4) >> 24);
    // 0x800310DC: bne         $v0, $v1, L_8003171C
    if (ctx->r2 != ctx->r3) {
        // 0x800310E0: addiu       $v0, $t6, 0x1
        ctx->r2 = ADD32(ctx->r14, 0X1);
            goto L_8003171C;
    }
    // 0x800310E0: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x800310E4: lb          $v1, 0x0($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X0);
    // 0x800310E8: lb          $v0, 0x1($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X1);
    // 0x800310EC: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800310F0: beq         $v1, $zero, L_80031718
    if (ctx->r3 == 0) {
        // 0x800310F4: addiu       $v0, $t6, 0x2
        ctx->r2 = ADD32(ctx->r14, 0X2);
            goto L_80031718;
    }
    // 0x800310F4: addiu       $v0, $t6, 0x2
    ctx->r2 = ADD32(ctx->r14, 0X2);
    // 0x800310F8: subu        $v0, $v0, $t5
    ctx->r2 = SUB32(ctx->r2, ctx->r13);
    // 0x800310FC: sb          $a1, 0x120($a2)
    MEM_B(0X120, ctx->r6) = ctx->r5;
    // 0x80031100: sb          $v0, 0x122($a2)
    MEM_B(0X122, ctx->r6) = ctx->r2;
    // 0x80031104: sb          $t7, 0x121($a2)
    MEM_B(0X121, ctx->r6) = ctx->r15;
    // 0x80031108: lbu         $v0, 0x0($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X0);
    // 0x8003110C: j           L_80031714
    // 0x80031110: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
        goto L_80031714;
    // 0x80031110: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_80031114:
    // 0x80031114: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80031118: bne         $s7, $zero, L_800311D8
    if (ctx->r23 != 0) {
        // 0x8003111C: addu        $t0, $s0, $zero
        ctx->r8 = ADD32(ctx->r16, 0);
            goto L_800311D8;
    }
    // 0x8003111C: addu        $t0, $s0, $zero
    ctx->r8 = ADD32(ctx->r16, 0);
    // 0x80031120: sll         $v0, $t6, 16
    ctx->r2 = S32(ctx->r14 << 16);
    // 0x80031124: sra         $t4, $v0, 16
    ctx->r12 = S32(SIGNED(ctx->r2) >> 16);
L_80031128:
    // 0x80031128: bne         $s2, $zero, L_800311BC
    if (ctx->r18 != 0) {
        // 0x8003112C: addu        $a1, $t5, $zero
        ctx->r5 = ADD32(ctx->r13, 0);
            goto L_800311BC;
    }
    // 0x8003112C: addu        $a1, $t5, $zero
    ctx->r5 = ADD32(ctx->r13, 0);
    // 0x80031130: lw          $t3, 0x110($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X110);
    // 0x80031134: sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8 << 16);
    // 0x80031138: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8003113C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80031140: subu        $v1, $s5, $a0
    ctx->r3 = SUB32(ctx->r21, ctx->r4);
    // 0x80031144: subu        $v1, $s7, $v1
    ctx->r3 = SUB32(ctx->r23, ctx->r3);
    // 0x80031148: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x8003114C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80031150: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x80031154: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80031158: addu        $t1, $v0, $a0
    ctx->r9 = ADD32(ctx->r2, ctx->r4);
    // 0x8003115C: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x80031160: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031164: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_80031168:
    // 0x80031168: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003116C: subu        $v1, $v0, $t9
    ctx->r3 = SUB32(ctx->r2, ctx->r25);
    // 0x80031170: addu        $v1, $t4, $v1
    ctx->r3 = ADD32(ctx->r12, ctx->r3);
    // 0x80031174: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x80031178: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x8003117C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80031180: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80031184: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x80031188: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x8003118C: lbu         $v1, 0x82($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X82);
    // 0x80031190: beql        $v0, $zero, L_800311A4
    if (ctx->r2 == 0) {
        // 0x80031194: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_800311A4;
    }
    goto skip_21;
    // 0x80031194: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    skip_21:
    // 0x80031198: bnel        $v1, $zero, L_800311A0
    if (ctx->r3 != 0) {
        // 0x8003119C: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800311A0;
    }
    goto skip_22;
    // 0x8003119C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_22:
L_800311A0:
    // 0x800311A0: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
L_800311A4:
    // 0x800311A4: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800311A8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800311AC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800311B0: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800311B4: beq         $v0, $zero, L_80031168
    if (ctx->r2 == 0) {
        // 0x800311B8: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_80031168;
    }
    // 0x800311B8: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_800311BC:
    // 0x800311BC: addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // 0x800311C0: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x800311C4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800311C8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800311CC: slt         $v0, $v0, $s1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800311D0: beq         $v0, $zero, L_80031128
    if (ctx->r2 == 0) {
        // 0x800311D4: nop
    
            goto L_80031128;
    }
    // 0x800311D4: nop

L_800311D8:
    // 0x800311D8: sll         $v1, $a3, 16
    ctx->r3 = S32(ctx->r7 << 16);
    // 0x800311DC: lbu         $v0, 0x54($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X54);
    // 0x800311E0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800311E4: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // 0x800311E8: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800311EC: bne         $v0, $zero, L_80031264
    if (ctx->r2 != 0) {
        // 0x800311F0: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_80031264;
    }
    // 0x800311F0: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x800311F4: lbu         $v0, 0x120($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X120);
    // 0x800311F8: sll         $a0, $v0, 24
    ctx->r4 = S32(ctx->r2 << 24);
    // 0x800311FC: sra         $v0, $a0, 24
    ctx->r2 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80031200: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80031204: beq         $v0, $zero, L_80031228
    if (ctx->r2 == 0) {
        // 0x80031208: addiu       $v0, $t6, 0x2
        ctx->r2 = ADD32(ctx->r14, 0X2);
            goto L_80031228;
    }
    // 0x80031208: addiu       $v0, $t6, 0x2
    ctx->r2 = ADD32(ctx->r14, 0X2);
    // 0x8003120C: subu        $v0, $v0, $t5
    ctx->r2 = SUB32(ctx->r2, ctx->r13);
    // 0x80031210: sb          $a1, 0x120($a2)
    MEM_B(0X120, ctx->r6) = ctx->r5;
    // 0x80031214: sb          $v0, 0x122($a2)
    MEM_B(0X122, ctx->r6) = ctx->r2;
    // 0x80031218: sb          $t7, 0x121($a2)
    MEM_B(0X121, ctx->r6) = ctx->r15;
    // 0x8003121C: lbu         $v0, 0x0($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X0);
    // 0x80031220: j           L_80031714
    // 0x80031224: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
        goto L_80031714;
    // 0x80031224: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_80031228:
    // 0x80031228: sra         $v0, $a0, 24
    ctx->r2 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8003122C: bne         $v0, $v1, L_8003171C
    if (ctx->r2 != ctx->r3) {
        // 0x80031230: addiu       $v0, $t6, 0x1
        ctx->r2 = ADD32(ctx->r14, 0X1);
            goto L_8003171C;
    }
    // 0x80031230: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80031234: lb          $v1, 0x0($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X0);
    // 0x80031238: lb          $v0, 0x1($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X1);
    // 0x8003123C: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80031240: beq         $v1, $zero, L_80031718
    if (ctx->r3 == 0) {
        // 0x80031244: addiu       $v0, $t6, 0x2
        ctx->r2 = ADD32(ctx->r14, 0X2);
            goto L_80031718;
    }
    // 0x80031244: addiu       $v0, $t6, 0x2
    ctx->r2 = ADD32(ctx->r14, 0X2);
    // 0x80031248: subu        $v0, $v0, $t5
    ctx->r2 = SUB32(ctx->r2, ctx->r13);
    // 0x8003124C: sb          $a1, 0x120($a2)
    MEM_B(0X120, ctx->r6) = ctx->r5;
    // 0x80031250: sb          $v0, 0x122($a2)
    MEM_B(0X122, ctx->r6) = ctx->r2;
    // 0x80031254: sb          $t7, 0x121($a2)
    MEM_B(0X121, ctx->r6) = ctx->r15;
    // 0x80031258: lbu         $v0, 0x0($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X0);
    // 0x8003125C: j           L_80031714
    // 0x80031260: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
        goto L_80031714;
    // 0x80031260: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_80031264:
    // 0x80031264: lbu         $v0, 0x55($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X55);
    // 0x80031268: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8003126C: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // 0x80031270: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80031274: bne         $v0, $zero, L_800316F8
    if (ctx->r2 != 0) {
        // 0x80031278: addiu       $v0, $t6, 0x2
        ctx->r2 = ADD32(ctx->r14, 0X2);
            goto L_800316F8;
    }
    // 0x80031278: addiu       $v0, $t6, 0x2
    ctx->r2 = ADD32(ctx->r14, 0X2);
    // 0x8003127C: lbu         $v0, 0x120($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X120);
    // 0x80031280: sll         $a0, $v0, 24
    ctx->r4 = S32(ctx->r2 << 24);
    // 0x80031284: sra         $v0, $a0, 24
    ctx->r2 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80031288: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003128C: beq         $v0, $zero, L_800312B4
    if (ctx->r2 == 0) {
        // 0x80031290: addiu       $v0, $t6, 0x2
        ctx->r2 = ADD32(ctx->r14, 0X2);
            goto L_800312B4;
    }
    // 0x80031290: addiu       $v0, $t6, 0x2
    ctx->r2 = ADD32(ctx->r14, 0X2);
    // 0x80031294: subu        $v0, $v0, $t5
    ctx->r2 = SUB32(ctx->r2, ctx->r13);
    // 0x80031298: sb          $a1, 0x120($a2)
    MEM_B(0X120, ctx->r6) = ctx->r5;
    // 0x8003129C: sb          $v0, 0x122($a2)
    MEM_B(0X122, ctx->r6) = ctx->r2;
    // 0x800312A0: sb          $t7, 0x121($a2)
    MEM_B(0X121, ctx->r6) = ctx->r15;
    // 0x800312A4: lbu         $v0, 0x0($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X0);
    // 0x800312A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800312AC: j           L_80031714
    // 0x800312B0: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
        goto L_80031714;
    // 0x800312B0: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_800312B4:
    // 0x800312B4: sra         $v0, $a0, 24
    ctx->r2 = S32(SIGNED(ctx->r4) >> 24);
    // 0x800312B8: bne         $v0, $v1, L_8003171C
    if (ctx->r2 != ctx->r3) {
        // 0x800312BC: addiu       $v0, $t6, 0x1
        ctx->r2 = ADD32(ctx->r14, 0X1);
            goto L_8003171C;
    }
    // 0x800312BC: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x800312C0: lb          $v1, 0x0($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X0);
    // 0x800312C4: lb          $v0, 0x1($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X1);
    // 0x800312C8: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800312CC: beq         $v1, $zero, L_80031718
    if (ctx->r3 == 0) {
        // 0x800312D0: addiu       $v0, $t6, 0x2
        ctx->r2 = ADD32(ctx->r14, 0X2);
            goto L_80031718;
    }
    // 0x800312D0: addiu       $v0, $t6, 0x2
    ctx->r2 = ADD32(ctx->r14, 0X2);
    // 0x800312D4: subu        $v0, $v0, $t5
    ctx->r2 = SUB32(ctx->r2, ctx->r13);
    // 0x800312D8: sb          $a1, 0x120($a2)
    MEM_B(0X120, ctx->r6) = ctx->r5;
    // 0x800312DC: sb          $v0, 0x122($a2)
    MEM_B(0X122, ctx->r6) = ctx->r2;
    // 0x800312E0: sb          $t7, 0x121($a2)
    MEM_B(0X121, ctx->r6) = ctx->r15;
    // 0x800312E4: lbu         $v0, 0x0($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X0);
    // 0x800312E8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800312EC: j           L_80031714
    // 0x800312F0: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
        goto L_80031714;
    // 0x800312F0: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_800312F4:
    // 0x800312F4: bne         $s2, $zero, L_80031414
    if (ctx->r18 != 0) {
        // 0x800312F8: addu        $t1, $t5, $zero
        ctx->r9 = ADD32(ctx->r13, 0);
            goto L_80031414;
    }
    // 0x800312F8: addu        $t1, $t5, $zero
    ctx->r9 = ADD32(ctx->r13, 0);
    // 0x800312FC: sll         $v0, $t6, 16
    ctx->r2 = S32(ctx->r14 << 16);
    // 0x80031300: sra         $t3, $v0, 16
    ctx->r11 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031304: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
L_80031308:
    // 0x80031308: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8003130C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80031310: sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9 << 16);
    // 0x80031314: sra         $a3, $v0, 16
    ctx->r7 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031318: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_8003131C:
    // 0x8003131C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031320: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80031324: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80031328: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x8003132C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80031330: addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // 0x80031334: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80031338: bnel        $v0, $zero, L_80031340
    if (ctx->r2 != 0) {
        // 0x8003133C: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_80031340;
    }
    goto skip_23;
    // 0x8003133C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    skip_23:
L_80031340:
    // 0x80031340: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80031344: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80031348: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8003134C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031350: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80031354: bne         $v0, $zero, L_8003131C
    if (ctx->r2 != 0) {
        // 0x80031358: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_8003131C;
    }
    // 0x80031358: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x8003135C: lhu         $s7, 0x16($sp)
    ctx->r23 = MEM_HU(ctx->r29, 0X16);
    // 0x80031360: subu        $v0, $s0, $a1
    ctx->r2 = SUB32(ctx->r16, ctx->r5);
    // 0x80031364: subu        $v0, $s7, $v0
    ctx->r2 = SUB32(ctx->r23, ctx->r2);
    // 0x80031368: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003136C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80031370: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80031374: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031378: slti        $v0, $v0, 0x12
    ctx->r2 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x8003137C: beq         $v0, $zero, L_800313DC
    if (ctx->r2 == 0) {
        // 0x80031380: sll         $v0, $t1, 16
        ctx->r2 = S32(ctx->r9 << 16);
            goto L_800313DC;
    }
    // 0x80031380: sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9 << 16);
    // 0x80031384: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031388: lw          $v1, 0x110($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X110);
    // 0x8003138C: subu        $v0, $v0, $t9
    ctx->r2 = SUB32(ctx->r2, ctx->r25);
    // 0x80031390: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x80031394: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // 0x80031398: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_8003139C:
    // 0x8003139C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800313A0: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x800313A4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800313A8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800313AC: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x800313B0: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x800313B4: bnel        $v0, $zero, L_800313C0
    if (ctx->r2 != 0) {
        // 0x800313B8: addiu       $a0, $zero, 0x12
        ctx->r4 = ADD32(0, 0X12);
            goto L_800313C0;
    }
    goto skip_24;
    // 0x800313B8: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    skip_24:
    // 0x800313BC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800313C0:
    // 0x800313C0: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800313C4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800313C8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800313CC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800313D0: slti        $v0, $v0, 0x12
    ctx->r2 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x800313D4: bne         $v0, $zero, L_8003139C
    if (ctx->r2 != 0) {
        // 0x800313D8: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_8003139C;
    }
    // 0x800313D8: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_800313DC:
    // 0x800313DC: sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8 << 16);
    // 0x800313E0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800313E4: sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10 << 16);
    // 0x800313E8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800313EC: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800313F0: bnel        $v0, $zero, L_800313F8
    if (ctx->r2 != 0) {
        // 0x800313F4: addu        $t2, $t0, $zero
        ctx->r10 = ADD32(ctx->r8, 0);
            goto L_800313F8;
    }
    goto skip_25;
    // 0x800313F4: addu        $t2, $t0, $zero
    ctx->r10 = ADD32(ctx->r8, 0);
    skip_25:
L_800313F8:
    // 0x800313F8: addiu       $v0, $t1, 0x1
    ctx->r2 = ADD32(ctx->r9, 0X1);
    // 0x800313FC: addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
    // 0x80031400: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80031404: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031408: slt         $v0, $fp, $v0
    ctx->r2 = SIGNED(ctx->r30) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003140C: beql        $v0, $zero, L_80031308
    if (ctx->r2 == 0) {
        // 0x80031410: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_80031308;
    }
    goto skip_26;
    // 0x80031410: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    skip_26:
L_80031414:
    // 0x80031414: sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10 << 16);
    // 0x80031418: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003141C: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80031420: beq         $v0, $zero, L_80031570
    if (ctx->r2 == 0) {
        // 0x80031424: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_80031570;
    }
    // 0x80031424: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80031428: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8003142C: bne         $s7, $zero, L_800314EC
    if (ctx->r23 != 0) {
        // 0x80031430: addu        $t0, $s0, $zero
        ctx->r8 = ADD32(ctx->r16, 0);
            goto L_800314EC;
    }
    // 0x80031430: addu        $t0, $s0, $zero
    ctx->r8 = ADD32(ctx->r16, 0);
    // 0x80031434: sll         $v0, $t6, 16
    ctx->r2 = S32(ctx->r14 << 16);
    // 0x80031438: sra         $t4, $v0, 16
    ctx->r12 = S32(SIGNED(ctx->r2) >> 16);
L_8003143C:
    // 0x8003143C: bne         $s2, $zero, L_800314D0
    if (ctx->r18 != 0) {
        // 0x80031440: addu        $a1, $t5, $zero
        ctx->r5 = ADD32(ctx->r13, 0);
            goto L_800314D0;
    }
    // 0x80031440: addu        $a1, $t5, $zero
    ctx->r5 = ADD32(ctx->r13, 0);
    // 0x80031444: lw          $t3, 0x110($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X110);
    // 0x80031448: sll         $a0, $t0, 16
    ctx->r4 = S32(ctx->r8 << 16);
    // 0x8003144C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80031450: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80031454: subu        $v1, $s5, $a0
    ctx->r3 = SUB32(ctx->r21, ctx->r4);
    // 0x80031458: subu        $v1, $s7, $v1
    ctx->r3 = SUB32(ctx->r23, ctx->r3);
    // 0x8003145C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80031460: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80031464: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x80031468: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8003146C: addu        $t1, $v0, $a0
    ctx->r9 = ADD32(ctx->r2, ctx->r4);
    // 0x80031470: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x80031474: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031478: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_8003147C:
    // 0x8003147C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031480: subu        $v1, $v0, $t9
    ctx->r3 = SUB32(ctx->r2, ctx->r25);
    // 0x80031484: addu        $v1, $t4, $v1
    ctx->r3 = ADD32(ctx->r12, ctx->r3);
    // 0x80031488: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x8003148C: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80031490: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80031494: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80031498: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x8003149C: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x800314A0: lbu         $v1, 0x82($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X82);
    // 0x800314A4: beql        $v0, $zero, L_800314B8
    if (ctx->r2 == 0) {
        // 0x800314A8: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_800314B8;
    }
    goto skip_27;
    // 0x800314A8: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    skip_27:
    // 0x800314AC: bnel        $v1, $zero, L_800314B4
    if (ctx->r3 != 0) {
        // 0x800314B0: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800314B4;
    }
    goto skip_28;
    // 0x800314B0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_28:
L_800314B4:
    // 0x800314B4: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
L_800314B8:
    // 0x800314B8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800314BC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800314C0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800314C4: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800314C8: beq         $v0, $zero, L_8003147C
    if (ctx->r2 == 0) {
        // 0x800314CC: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_8003147C;
    }
    // 0x800314CC: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_800314D0:
    // 0x800314D0: addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // 0x800314D4: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x800314D8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800314DC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800314E0: slt         $v0, $v0, $s1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800314E4: beq         $v0, $zero, L_8003143C
    if (ctx->r2 == 0) {
        // 0x800314E8: nop
    
            goto L_8003143C;
    }
    // 0x800314E8: nop

L_800314EC:
    // 0x800314EC: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x800314F0: lbu         $v1, 0x120($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X120);
    // 0x800314F4: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800314F8: sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3 << 24);
    // 0x800314FC: sra         $v0, $v1, 24
    ctx->r2 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80031500: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80031504: beq         $v0, $zero, L_8003152C
    if (ctx->r2 == 0) {
        // 0x80031508: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_8003152C;
    }
    // 0x80031508: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8003150C: addiu       $v0, $t6, 0x2
    ctx->r2 = ADD32(ctx->r14, 0X2);
    // 0x80031510: subu        $v0, $v0, $t5
    ctx->r2 = SUB32(ctx->r2, ctx->r13);
    // 0x80031514: sb          $a1, 0x120($a2)
    MEM_B(0X120, ctx->r6) = ctx->r5;
    // 0x80031518: sb          $v0, 0x122($a2)
    MEM_B(0X122, ctx->r6) = ctx->r2;
    // 0x8003151C: sb          $t7, 0x121($a2)
    MEM_B(0X121, ctx->r6) = ctx->r15;
    // 0x80031520: lbu         $v0, 0x0($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X0);
    // 0x80031524: j           L_80031714
    // 0x80031528: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
        goto L_80031714;
    // 0x80031528: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_8003152C:
    // 0x8003152C: sra         $v0, $v1, 24
    ctx->r2 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80031530: bne         $v0, $a0, L_8003171C
    if (ctx->r2 != ctx->r4) {
        // 0x80031534: addiu       $v0, $t6, 0x1
        ctx->r2 = ADD32(ctx->r14, 0X1);
            goto L_8003171C;
    }
    // 0x80031534: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80031538: lb          $v1, 0x0($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X0);
    // 0x8003153C: lb          $v0, 0x1($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X1);
    // 0x80031540: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80031544: beq         $v1, $zero, L_80031718
    if (ctx->r3 == 0) {
        // 0x80031548: addiu       $v0, $t6, 0x2
        ctx->r2 = ADD32(ctx->r14, 0X2);
            goto L_80031718;
    }
    // 0x80031548: addiu       $v0, $t6, 0x2
    ctx->r2 = ADD32(ctx->r14, 0X2);
    // 0x8003154C: subu        $v0, $v0, $t5
    ctx->r2 = SUB32(ctx->r2, ctx->r13);
    // 0x80031550: sb          $a1, 0x120($a2)
    MEM_B(0X120, ctx->r6) = ctx->r5;
    // 0x80031554: sb          $v0, 0x122($a2)
    MEM_B(0X122, ctx->r6) = ctx->r2;
    // 0x80031558: sb          $t7, 0x121($a2)
    MEM_B(0X121, ctx->r6) = ctx->r15;
    // 0x8003155C: lbu         $v0, 0x0($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X0);
    // 0x80031560: j           L_80031714
    // 0x80031564: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
        goto L_80031714;
    // 0x80031564: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_80031568:
    // 0x80031568: j           L_800315DC
    // 0x8003156C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800315DC;
    // 0x8003156C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80031570:
    // 0x80031570: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80031574: lw          $a3, 0x110($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X110);
    // 0x80031578: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8003157C:
    // 0x8003157C: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80031580: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80031584: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80031588: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003158C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80031590: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_80031594:
    // 0x80031594: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031598: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8003159C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800315A0: lbu         $v0, 0x70($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X70);
    // 0x800315A4: bne         $v0, $zero, L_80031568
    if (ctx->r2 != 0) {
        // 0x800315A8: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_80031568;
    }
    // 0x800315A8: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800315AC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800315B0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800315B4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800315B8: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x800315BC: bne         $v0, $zero, L_80031594
    if (ctx->r2 != 0) {
        // 0x800315C0: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_80031594;
    }
    // 0x800315C0: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x800315C4: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x800315C8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800315CC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800315D0: bgezl       $v0, L_8003157C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800315D4: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8003157C;
    }
    goto skip_29;
    // 0x800315D4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_29:
    // 0x800315D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_800315DC:
    // 0x800315DC: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x800315E0: beq         $v0, $zero, L_80031718
    if (ctx->r2 == 0) {
        // 0x800315E4: sll         $v0, $s0, 16
        ctx->r2 = S32(ctx->r16 << 16);
            goto L_80031718;
    }
    // 0x800315E4: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    // 0x800315E8: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x800315EC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800315F0: slt         $v0, $v0, $s1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800315F4: bne         $v0, $zero, L_800316B4
    if (ctx->r2 != 0) {
        // 0x800315F8: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_800316B4;
    }
    // 0x800315F8: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x800315FC: sll         $v0, $t6, 16
    ctx->r2 = S32(ctx->r14 << 16);
    // 0x80031600: sra         $t4, $v0, 16
    ctx->r12 = S32(SIGNED(ctx->r2) >> 16);
L_80031604:
    // 0x80031604: bne         $s2, $zero, L_80031698
    if (ctx->r18 != 0) {
        // 0x80031608: addu        $a1, $t5, $zero
        ctx->r5 = ADD32(ctx->r13, 0);
            goto L_80031698;
    }
    // 0x80031608: addu        $a1, $t5, $zero
    ctx->r5 = ADD32(ctx->r13, 0);
    // 0x8003160C: lw          $t3, 0x110($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X110);
    // 0x80031610: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x80031614: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80031618: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8003161C: subu        $v1, $s5, $a0
    ctx->r3 = SUB32(ctx->r21, ctx->r4);
    // 0x80031620: subu        $v1, $s7, $v1
    ctx->r3 = SUB32(ctx->r23, ctx->r3);
    // 0x80031624: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80031628: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003162C: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x80031630: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80031634: addu        $t1, $v0, $a0
    ctx->r9 = ADD32(ctx->r2, ctx->r4);
    // 0x80031638: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8003163C: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031640: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_80031644:
    // 0x80031644: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031648: subu        $v1, $v0, $t9
    ctx->r3 = SUB32(ctx->r2, ctx->r25);
    // 0x8003164C: addu        $v1, $t4, $v1
    ctx->r3 = ADD32(ctx->r12, ctx->r3);
    // 0x80031650: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x80031654: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80031658: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8003165C: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80031660: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x80031664: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x80031668: lbu         $v1, 0x82($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X82);
    // 0x8003166C: beql        $v0, $zero, L_80031680
    if (ctx->r2 == 0) {
        // 0x80031670: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_80031680;
    }
    goto skip_30;
    // 0x80031670: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    skip_30:
    // 0x80031674: bnel        $v1, $zero, L_8003167C
    if (ctx->r3 != 0) {
        // 0x80031678: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8003167C;
    }
    goto skip_31;
    // 0x80031678: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_31:
L_8003167C:
    // 0x8003167C: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
L_80031680:
    // 0x80031680: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80031684: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80031688: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003168C: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80031690: beq         $v0, $zero, L_80031644
    if (ctx->r2 == 0) {
        // 0x80031694: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_80031644;
    }
    // 0x80031694: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_80031698:
    // 0x80031698: addiu       $v0, $a3, -0x1
    ctx->r2 = ADD32(ctx->r7, -0X1);
    // 0x8003169C: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x800316A0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800316A4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800316A8: slt         $v0, $v0, $s1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800316AC: beq         $v0, $zero, L_80031604
    if (ctx->r2 == 0) {
        // 0x800316B0: nop
    
            goto L_80031604;
    }
    // 0x800316B0: nop

L_800316B4:
    // 0x800316B4: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x800316B8: lbu         $v1, 0x120($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X120);
    // 0x800316BC: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800316C0: sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3 << 24);
    // 0x800316C4: sra         $v0, $v1, 24
    ctx->r2 = S32(SIGNED(ctx->r3) >> 24);
    // 0x800316C8: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800316CC: bne         $v0, $zero, L_800316F4
    if (ctx->r2 != 0) {
        // 0x800316D0: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_800316F4;
    }
    // 0x800316D0: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800316D4: sra         $v0, $v1, 24
    ctx->r2 = S32(SIGNED(ctx->r3) >> 24);
    // 0x800316D8: bne         $v0, $a0, L_8003171C
    if (ctx->r2 != ctx->r4) {
        // 0x800316DC: addiu       $v0, $t6, 0x1
        ctx->r2 = ADD32(ctx->r14, 0X1);
            goto L_8003171C;
    }
    // 0x800316DC: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
L_800316E0:
    // 0x800316E0: lb          $v1, 0x0($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X0);
    // 0x800316E4: lb          $v0, 0x1($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X1);
    // 0x800316E8: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800316EC: beq         $v1, $zero, L_8003171C
    if (ctx->r3 == 0) {
        // 0x800316F0: addiu       $v0, $t6, 0x1
        ctx->r2 = ADD32(ctx->r14, 0X1);
            goto L_8003171C;
    }
    // 0x800316F0: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
L_800316F4:
    // 0x800316F4: addiu       $v0, $t6, 0x2
    ctx->r2 = ADD32(ctx->r14, 0X2);
L_800316F8:
    // 0x800316F8: subu        $v0, $v0, $t5
    ctx->r2 = SUB32(ctx->r2, ctx->r13);
    // 0x800316FC: sb          $a1, 0x120($a2)
    MEM_B(0X120, ctx->r6) = ctx->r5;
    // 0x80031700: sb          $v0, 0x122($a2)
    MEM_B(0X122, ctx->r6) = ctx->r2;
    // 0x80031704: sb          $t7, 0x121($a2)
    MEM_B(0X121, ctx->r6) = ctx->r15;
    // 0x80031708: lbu         $v0, 0x0($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X0);
    // 0x8003170C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80031710: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_80031714:
    // 0x80031714: sb          $v0, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r2;
L_80031718:
    // 0x80031718: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
L_8003171C:
    // 0x8003171C: addu        $t6, $v0, $zero
    ctx->r14 = ADD32(ctx->r2, 0);
    // 0x80031720: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80031724: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031728: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8003172C: bne         $v0, $zero, L_8003089C
    if (ctx->r2 != 0) {
        // 0x80031730: nop
    
            goto L_8003089C;
    }
    // 0x80031730: nop

    // 0x80031734: lhu         $s7, 0xE($sp)
    ctx->r23 = MEM_HU(ctx->r29, 0XE);
    // 0x80031738: addiu       $v0, $s7, 0x1
    ctx->r2 = ADD32(ctx->r23, 0X1);
    // 0x8003173C: sh          $v0, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r2;
    // 0x80031740: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80031744: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031748: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8003174C: bne         $v0, $zero, L_800305F8
    if (ctx->r2 != 0) {
        // 0x80031750: addiu       $t7, $t7, 0x1
        ctx->r15 = ADD32(ctx->r15, 0X1);
            goto L_800305F8;
    }
    // 0x80031750: addiu       $t7, $t7, 0x1
    ctx->r15 = ADD32(ctx->r15, 0X1);
    // 0x80031754: addu        $v0, $t8, $zero
    ctx->r2 = ADD32(ctx->r24, 0);
    // 0x80031758: beq         $v0, $zero, L_80031780
    if (ctx->r2 == 0) {
        // 0x8003175C: lui         $v1, 0x100
        ctx->r3 = S32(0X100 << 16);
            goto L_80031780;
    }
    // 0x8003175C: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x80031760: lbu         $s7, 0x1F($sp)
    ctx->r23 = MEM_BU(ctx->r29, 0X1F);
    // 0x80031764: addiu       $v0, $s7, 0x1
    ctx->r2 = ADD32(ctx->r23, 0X1);
    // 0x80031768: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    // 0x8003176C: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80031770: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80031774: or          $v0, $s6, $v0
    ctx->r2 = ctx->r22 | ctx->r2;
    // 0x80031778: bne         $v0, $zero, L_800317A4
    if (ctx->r2 != 0) {
        // 0x8003177C: nop
    
            goto L_800317A4;
    }
    // 0x8003177C: nop

L_80031780:
    // 0x80031780: lbu         $v0, 0x4C($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X4C);
    // 0x80031784: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80031788: sra         $t7, $v0, 24
    ctx->r15 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8003178C: lhu         $s7, 0x16($sp)
    ctx->r23 = MEM_HU(ctx->r29, 0X16);
    // 0x80031790: addiu       $v0, $s7, -0x1
    ctx->r2 = ADD32(ctx->r23, -0X1);
    // 0x80031794: sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    // 0x80031798: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8003179C: bgez        $v0, L_800305E4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800317A0: nop
    
            goto L_800305E4;
    }
    // 0x800317A0: nop

L_800317A4:
    // 0x800317A4: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800317A8: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800317AC: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800317B0: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800317B4: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800317B8: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800317BC: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800317C0: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800317C4: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800317C8: jr          $ra
    // 0x800317CC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800317CC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800317D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800317D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800317D4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800317D8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800317DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800317E0: lb          $v1, 0x11F($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X11F);
    // 0x800317E4: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x800317E8: beq         $v0, $zero, L_80031A64
    if (ctx->r2 == 0) {
        // 0x800317EC: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80031A64;
    }
    // 0x800317EC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800317F0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800317F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800317F8: addu        $at, $at, $v0
    gpr jr_addend_80031800 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800317FC: lw          $v0, -0x2820($at)
    ctx->r2 = ADD32(ctx->r1, -0X2820);
    // 0x80031800: jr          $v0
    // 0x80031804: nop

    switch (jr_addend_80031800 >> 2) {
        case 0: goto L_80031810; break;
        case 1: goto L_800319C0; break;
        case 2: goto L_80031A00; break;
        case 3: goto L_80031A20; break;
        case 4: goto L_80031A58; break;
        default: switch_error(__func__, 0x80031800, 0x800AD7E0);
    }
    // 0x80031804: nop

L_80031808:
    // 0x80031808: j           L_800319A4
    // 0x8003180C: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
        goto L_800319A4;
    // 0x8003180C: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_80031810:
    // 0x80031810: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80031814: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80031818:
    // 0x80031818: sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8 << 16);
    // 0x8003181C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80031820: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80031824: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80031828: sll         $a3, $v0, 1
    ctx->r7 = S32(ctx->r2 << 1);
L_8003182C:
    // 0x8003182C: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x80031830: addiu       $a0, $a2, 0x1
    ctx->r4 = ADD32(ctx->r6, 0X1);
    // 0x80031834: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80031838: lw          $v0, 0xB0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB0);
    // 0x8003183C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80031840: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
    // 0x80031844: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80031848: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8003184C: slti        $a0, $a0, 0x12
    ctx->r4 = SIGNED(ctx->r4) < 0X12 ? 1 : 0;
    // 0x80031850: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80031854: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x80031858: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8003185C: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80031860: addu        $v1, $a3, $v1
    ctx->r3 = ADD32(ctx->r7, ctx->r3);
    // 0x80031864: bne         $a0, $zero, L_8003182C
    if (ctx->r4 != 0) {
        // 0x80031868: sb          $v0, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r2;
            goto L_8003182C;
    }
    // 0x80031868: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8003186C: addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
    // 0x80031870: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80031874: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80031878: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003187C: slti        $v0, $v0, 0x1C
    ctx->r2 = SIGNED(ctx->r2) < 0X1C ? 1 : 0;
    // 0x80031880: bne         $v0, $zero, L_80031818
    if (ctx->r2 != 0) {
        // 0x80031884: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80031818;
    }
    // 0x80031884: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80031888: lb          $v1, 0x54($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X54);
    // 0x8003188C: lw          $v0, 0xDC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XDC);
    // 0x80031890: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80031894: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80031898: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003189C: lb          $v0, 0x4C($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X4C);
    // 0x800318A0: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800318A4: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800318A8: addiu       $t1, $t1, 0x2FF0
    ctx->r9 = ADD32(ctx->r9, 0X2FF0);
    // 0x800318AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800318B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800318B4: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
L_800318B8:
    // 0x800318B8: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x800318BC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800318C0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800318C4: addu        $a1, $v1, $v0
    ctx->r5 = ADD32(ctx->r3, ctx->r2);
L_800318C8:
    // 0x800318C8: sll         $v1, $a2, 16
    ctx->r3 = S32(ctx->r6 << 16);
    // 0x800318CC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800318D0: addu        $v0, $a3, $v1
    ctx->r2 = ADD32(ctx->r7, ctx->r3);
    // 0x800318D4: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800318D8: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800318DC: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x800318E0: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x800318E4: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x800318E8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800318EC: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x800318F0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800318F4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800318F8: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x800318FC: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x80031900: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80031904: bne         $v0, $zero, L_800318C8
    if (ctx->r2 != 0) {
        // 0x80031908: sh          $a0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r4;
            goto L_800318C8;
    }
    // 0x80031908: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x8003190C: addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
    // 0x80031910: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80031914: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80031918: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003191C: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80031920: bne         $v0, $zero, L_800318B8
    if (ctx->r2 != 0) {
        // 0x80031924: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_800318B8;
    }
    // 0x80031924: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80031928: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x8003192C: addiu       $a3, $a3, 0x2FF0
    ctx->r7 = ADD32(ctx->r7, 0X2FF0);
    // 0x80031930: sb          $zero, 0x120($s0)
    MEM_B(0X120, ctx->r16) = 0;
    // 0x80031934: sb          $zero, 0x121($s0)
    MEM_B(0X121, ctx->r16) = 0;
    // 0x80031938: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8003193C:
    // 0x8003193C: sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6 << 16);
    // 0x80031940: sra         $a1, $v0, 16
    ctx->r5 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031944: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_80031948:
    // 0x80031948: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003194C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80031950: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80031954: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80031958: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8003195C: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80031960: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80031964: bne         $v0, $zero, L_80031808
    if (ctx->r2 != 0) {
        // 0x80031968: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_80031808;
    }
    // 0x80031968: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8003196C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80031970: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80031974: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031978: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8003197C: bne         $v0, $zero, L_80031948
    if (ctx->r2 != 0) {
        // 0x80031980: sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4 << 16);
            goto L_80031948;
    }
    // 0x80031980: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80031984: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x80031988: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8003198C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80031990: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031994: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80031998: bne         $v0, $zero, L_8003193C
    if (ctx->r2 != 0) {
        // 0x8003199C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8003193C;
    }
    // 0x8003199C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800319A0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800319A4:
    // 0x800319A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800319A8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800319AC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800319B0: jal         0x80030584
    // 0x800319B4: sb          $v0, 0x122($s0)
    MEM_B(0X122, ctx->r16) = ctx->r2;
    func_80030584(rdram, ctx);
        goto after_0;
    // 0x800319B4: sb          $v0, 0x122($s0)
    MEM_B(0X122, ctx->r16) = ctx->r2;
    after_0:
    // 0x800319B8: j           L_80031A44
    // 0x800319BC: nop

        goto L_80031A44;
    // 0x800319BC: nop

L_800319C0:
    // 0x800319C0: lb          $v1, 0x122($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X122);
    // 0x800319C4: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x800319C8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800319CC: beq         $v0, $zero, L_800319E0
    if (ctx->r2 == 0) {
        // 0x800319D0: slti        $v0, $v1, 0x7
        ctx->r2 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
            goto L_800319E0;
    }
    // 0x800319D0: slti        $v0, $v1, 0x7
    ctx->r2 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // 0x800319D4: bnel        $v0, $zero, L_80031A64
    if (ctx->r2 != 0) {
        // 0x800319D8: ori         $a0, $a0, 0x100
        ctx->r4 = ctx->r4 | 0X100;
            goto L_80031A64;
    }
    goto skip_0;
    // 0x800319D8: ori         $a0, $a0, 0x100
    ctx->r4 = ctx->r4 | 0X100;
    skip_0:
    // 0x800319DC: lb          $v1, 0x122($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X122);
L_800319E0:
    // 0x800319E0: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x800319E4: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800319E8: beq         $v0, $zero, L_80031A44
    if (ctx->r2 == 0) {
        // 0x800319EC: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80031A44;
    }
    // 0x800319EC: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800319F0: beq         $v0, $zero, L_80031A64
    if (ctx->r2 == 0) {
        // 0x800319F4: ori         $a0, $a0, 0x200
        ctx->r4 = ctx->r4 | 0X200;
            goto L_80031A64;
    }
    // 0x800319F4: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x800319F8: j           L_80031A44
    // 0x800319FC: nop

        goto L_80031A44;
    // 0x800319FC: nop

L_80031A00:
    // 0x80031A00: lb          $v1, 0x121($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X121);
    // 0x80031A04: lb          $v0, 0x4C($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X4C);
    // 0x80031A08: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80031A0C: beq         $v0, $zero, L_80031A44
    if (ctx->r2 == 0) {
        // 0x80031A10: nop
    
            goto L_80031A44;
    }
    // 0x80031A10: nop

    // 0x80031A14: lhu         $v0, 0x82($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X82);
    // 0x80031A18: j           L_80031A64
    // 0x80031A1C: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
        goto L_80031A64;
    // 0x80031A1C: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
L_80031A20:
    // 0x80031A20: lb          $a1, 0x122($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X122);
    // 0x80031A24: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
    // 0x80031A28: slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80031A2C: beq         $v0, $zero, L_80031A3C
    if (ctx->r2 == 0) {
        // 0x80031A30: slt         $v0, $a1, $v1
        ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80031A3C;
    }
    // 0x80031A30: slt         $v0, $a1, $v1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80031A34: j           L_80031A64
    // 0x80031A38: ori         $a0, $a0, 0x100
    ctx->r4 = ctx->r4 | 0X100;
        goto L_80031A64;
    // 0x80031A38: ori         $a0, $a0, 0x100
    ctx->r4 = ctx->r4 | 0X100;
L_80031A3C:
    // 0x80031A3C: bne         $v0, $zero, L_80031A64
    if (ctx->r2 != 0) {
        // 0x80031A40: ori         $a0, $a0, 0x200
        ctx->r4 = ctx->r4 | 0X200;
            goto L_80031A64;
    }
    // 0x80031A40: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
L_80031A44:
    // 0x80031A44: lbu         $v0, 0x11F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X11F);
    // 0x80031A48: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80031A4C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80031A50: j           L_80031A64
    // 0x80031A54: sb          $v0, 0x11F($s0)
    MEM_B(0X11F, ctx->r16) = ctx->r2;
        goto L_80031A64;
    // 0x80031A54: sb          $v0, 0x11F($s0)
    MEM_B(0X11F, ctx->r16) = ctx->r2;
L_80031A58:
    // 0x80031A58: ori         $a0, $a0, 0x400
    ctx->r4 = ctx->r4 | 0X400;
    // 0x80031A5C: sb          $zero, 0x122($s0)
    MEM_B(0X122, ctx->r16) = 0;
    // 0x80031A60: sb          $zero, 0x121($s0)
    MEM_B(0X121, ctx->r16) = 0;
L_80031A64:
    // 0x80031A64: lw          $v0, 0xB4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB4);
    // 0x80031A68: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x80031A6C: lw          $v0, 0xB8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB8);
    // 0x80031A70: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x80031A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031A78: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80031A7C: jr          $ra
    // 0x80031A80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80031A80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80031A90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031A90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031A94: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80031A98: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x80031A9C: lbu         $v1, 0x6($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X6);
    // 0x80031AA0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80031AA4: addiu       $a1, $a1, -0x3250
    ctx->r5 = ADD32(ctx->r5, -0X3250);
    // 0x80031AA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80031AAC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80031AB0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80031AB4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80031AB8: lw          $a0, -0x6368($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6368);
    // 0x80031ABC: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80031AC0: addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
    // 0x80031AC4: jal         0x8005334C
    // 0x80031AC8: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    func_8005334C(rdram, ctx);
        goto after_0;
    // 0x80031AC8: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    after_0:
    // 0x80031ACC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80031AD0: jr          $ra
    // 0x80031AD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80031AD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80031AD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031AD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031ADC: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x80031AE0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80031AE4: lbu         $v0, 0x6($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X6);
    // 0x80031AE8: sra         $a1, $a1, 22
    ctx->r5 = S32(SIGNED(ctx->r5) >> 22);
    // 0x80031AEC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80031AF0: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x80031AF4: lw          $a0, -0x6368($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6368);
    // 0x80031AF8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80031AFC: addiu       $a1, $a1, -0x3250
    ctx->r5 = ADD32(ctx->r5, -0X3250);
    // 0x80031B00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80031B04: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80031B08: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80031B0C: jal         0x8005334C
    // 0x80031B10: addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    func_8005334C(rdram, ctx);
        goto after_0;
    // 0x80031B10: addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    after_0:
    // 0x80031B14: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80031B18: jr          $ra
    // 0x80031B1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80031B1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80031B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031B20: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x80031B24: sra         $a0, $a0, 22
    ctx->r4 = S32(SIGNED(ctx->r4) >> 22);
    // 0x80031B28: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80031B2C: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x80031B30: lw          $t3, -0xBF4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0XBF4);
    // 0x80031B34: lb          $v0, 0x13($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X13);
    // 0x80031B38: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x80031B3C: sra         $a0, $a3, 24
    ctx->r4 = S32(SIGNED(ctx->r7) >> 24);
    // 0x80031B40: subu        $t1, $v0, $a0
    ctx->r9 = SUB32(ctx->r2, ctx->r4);
    // 0x80031B44: blez        $t1, L_80031BB4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80031B48: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_80031BB4;
    }
    // 0x80031B48: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80031B4C: sll         $v0, $a2, 24
    ctx->r2 = S32(ctx->r6 << 24);
    // 0x80031B50: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80031B54: addiu       $v1, $v1, -0x2F50
    ctx->r3 = ADD32(ctx->r3, -0X2F50);
    // 0x80031B58: sra         $v0, $v0, 19
    ctx->r2 = S32(SIGNED(ctx->r2) >> 19);
    // 0x80031B5C: addu        $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // 0x80031B60: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80031B64: sll         $v0, $a1, 24
    ctx->r2 = S32(ctx->r5 << 24);
    // 0x80031B68: sra         $v0, $v0, 20
    ctx->r2 = S32(SIGNED(ctx->r2) >> 20);
    // 0x80031B6C: addu        $a2, $v0, $a3
    ctx->r6 = ADD32(ctx->r2, ctx->r7);
    // 0x80031B70: addu        $a1, $t1, $zero
    ctx->r5 = ADD32(ctx->r9, 0);
L_80031B74:
    // 0x80031B74: sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8 << 16);
    // 0x80031B78: addiu       $v1, $t0, 0x1
    ctx->r3 = ADD32(ctx->r8, 0X1);
    // 0x80031B7C: addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
    // 0x80031B80: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80031B84: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x80031B88: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80031B8C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80031B90: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x80031B94: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80031B98: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x80031B9C: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x80031BA0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80031BA4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80031BA8: slt         $v1, $v1, $a1
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80031BAC: bne         $v1, $zero, L_80031B74
    if (ctx->r3 != 0) {
        // 0x80031BB0: sh          $v0, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r2;
            goto L_80031B74;
    }
    // 0x80031BB0: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
L_80031BB4:
    // 0x80031BB4: jr          $ra
    // 0x80031BB8: nop

    return;
    // 0x80031BB8: nop

;}
RECOMP_FUNC void func_80031BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031BBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031BC0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80031BC4: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x80031BC8: sra         $a1, $a1, 19
    ctx->r5 = S32(SIGNED(ctx->r5) >> 19);
    // 0x80031BCC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80031BD0: addiu       $v0, $v0, -0x3250
    ctx->r2 = ADD32(ctx->r2, -0X3250);
    // 0x80031BD4: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80031BD8: jal         0x8005334C
    // 0x80031BDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8005334C(rdram, ctx);
        goto after_0;
    // 0x80031BDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80031BE0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80031BE4: jr          $ra
    // 0x80031BE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80031BE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80031BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031BEC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80031BF0: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80031BF4: addiu       $a2, $a2, 0x4478
    ctx->r6 = ADD32(ctx->r6, 0X4478);
    // 0x80031BF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80031BFC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80031C00: sll         $v1, $a1, 24
    ctx->r3 = S32(ctx->r5 << 24);
L_80031C04:
    // 0x80031C04: addiu       $a0, $a1, 0x1
    ctx->r4 = ADD32(ctx->r5, 0X1);
    // 0x80031C08: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80031C0C: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80031C10: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80031C14: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80031C18: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80031C1C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80031C20: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80031C24: addu        $v1, $v0, $a2
    ctx->r3 = ADD32(ctx->r2, ctx->r6);
    // 0x80031C28: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x80031C2C: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80031C30: slti        $a0, $a0, 0x5
    ctx->r4 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // 0x80031C34: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80031C38: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031C3C: sb          $zero, 0x4478($at)
    MEM_B(0X4478, ctx->r1) = 0;
    // 0x80031C40: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x80031C44: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80031C48: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031C4C: sb          $zero, 0x4479($at)
    MEM_B(0X4479, ctx->r1) = 0;
    // 0x80031C50: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80031C54: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80031C58: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031C5C: sb          $zero, 0x447C($at)
    MEM_B(0X447C, ctx->r1) = 0;
    // 0x80031C60: sb          $zero, 0x5($v1)
    MEM_B(0X5, ctx->r3) = 0;
    // 0x80031C64: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80031C68: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031C6C: sb          $zero, 0x447E($at)
    MEM_B(0X447E, ctx->r1) = 0;
    // 0x80031C70: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80031C74: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031C78: sb          $zero, 0x447F($at)
    MEM_B(0X447F, ctx->r1) = 0;
    // 0x80031C7C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80031C80: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031C84: sh          $zero, 0x4480($at)
    MEM_H(0X4480, ctx->r1) = 0;
    // 0x80031C88: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x80031C8C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80031C90: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031C94: sw          $zero, 0x448C($at)
    MEM_W(0X448C, ctx->r1) = 0;
    // 0x80031C98: sh          $zero, 0x12($v1)
    MEM_H(0X12, ctx->r3) = 0;
    // 0x80031C9C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80031CA0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031CA4: sh          $zero, 0x4488($at)
    MEM_H(0X4488, ctx->r1) = 0;
    // 0x80031CA8: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x80031CAC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80031CB0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031CB4: swc1        $f0, 0x4494($at)
    MEM_W(0X4494, ctx->r1) = ctx->f0.u32l;
    // 0x80031CB8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80031CBC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031CC0: sw          $zero, 0x449C($at)
    MEM_W(0X449C, ctx->r1) = 0;
    // 0x80031CC4: sw          $zero, 0x30($v1)
    MEM_W(0X30, ctx->r3) = 0;
    // 0x80031CC8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80031CCC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031CD0: sw          $zero, 0x44A4($at)
    MEM_W(0X44A4, ctx->r1) = 0;
    // 0x80031CD4: bne         $a0, $zero, L_80031C04
    if (ctx->r4 != 0) {
        // 0x80031CD8: sll         $v1, $a1, 24
        ctx->r3 = S32(ctx->r5 << 24);
            goto L_80031C04;
    }
    // 0x80031CD8: sll         $v1, $a1, 24
    ctx->r3 = S32(ctx->r5 << 24);
    // 0x80031CDC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80031CE0: lui         $a2, 0x801E
    ctx->r6 = S32(0X801E << 16);
    // 0x80031CE4: addiu       $a2, $a2, -0x7A70
    ctx->r6 = ADD32(ctx->r6, -0X7A70);
    // 0x80031CE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80031CEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80031CF0: sll         $v1, $a1, 24
    ctx->r3 = S32(ctx->r5 << 24);
L_80031CF4:
    // 0x80031CF4: addiu       $a0, $a1, 0x1
    ctx->r4 = ADD32(ctx->r5, 0X1);
    // 0x80031CF8: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80031CFC: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80031D00: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80031D04: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80031D08: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80031D0C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80031D10: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80031D14: addu        $v1, $v0, $a2
    ctx->r3 = ADD32(ctx->r2, ctx->r6);
    // 0x80031D18: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x80031D1C: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80031D20: slti        $a0, $a0, 0x14
    ctx->r4 = SIGNED(ctx->r4) < 0X14 ? 1 : 0;
    // 0x80031D24: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031D28: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031D2C: sb          $zero, -0x7A70($at)
    MEM_B(-0X7A70, ctx->r1) = 0;
    // 0x80031D30: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x80031D34: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031D38: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031D3C: sb          $zero, -0x7A6F($at)
    MEM_B(-0X7A6F, ctx->r1) = 0;
    // 0x80031D40: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80031D44: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031D48: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031D4C: sb          $zero, -0x7A6C($at)
    MEM_B(-0X7A6C, ctx->r1) = 0;
    // 0x80031D50: sb          $zero, 0x5($v1)
    MEM_B(0X5, ctx->r3) = 0;
    // 0x80031D54: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031D58: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031D5C: sb          $zero, -0x7A6A($at)
    MEM_B(-0X7A6A, ctx->r1) = 0;
    // 0x80031D60: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031D64: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031D68: sb          $zero, -0x7A69($at)
    MEM_B(-0X7A69, ctx->r1) = 0;
    // 0x80031D6C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031D70: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031D74: sh          $zero, -0x7A68($at)
    MEM_H(-0X7A68, ctx->r1) = 0;
    // 0x80031D78: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x80031D7C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031D80: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031D84: sw          $zero, -0x7A5C($at)
    MEM_W(-0X7A5C, ctx->r1) = 0;
    // 0x80031D88: sh          $zero, 0x12($v1)
    MEM_H(0X12, ctx->r3) = 0;
    // 0x80031D8C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031D90: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031D94: sh          $zero, -0x7A60($at)
    MEM_H(-0X7A60, ctx->r1) = 0;
    // 0x80031D98: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x80031D9C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031DA0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031DA4: swc1        $f0, -0x7A54($at)
    MEM_W(-0X7A54, ctx->r1) = ctx->f0.u32l;
    // 0x80031DA8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031DAC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031DB0: sw          $zero, -0x7A4C($at)
    MEM_W(-0X7A4C, ctx->r1) = 0;
    // 0x80031DB4: sw          $zero, 0x30($v1)
    MEM_W(0X30, ctx->r3) = 0;
    // 0x80031DB8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031DBC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80031DC0: sw          $zero, -0x7A44($at)
    MEM_W(-0X7A44, ctx->r1) = 0;
    // 0x80031DC4: bnel        $a0, $zero, L_80031CF4
    if (ctx->r4 != 0) {
        // 0x80031DC8: sll         $v1, $a1, 24
        ctx->r3 = S32(ctx->r5 << 24);
            goto L_80031CF4;
    }
    goto skip_0;
    // 0x80031DC8: sll         $v1, $a1, 24
    ctx->r3 = S32(ctx->r5 << 24);
    skip_0:
    // 0x80031DCC: jr          $ra
    // 0x80031DD0: nop

    return;
    // 0x80031DD0: nop

;}
RECOMP_FUNC void func_80031DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031DD4: lbu         $v1, 0x13($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X13);
    // 0x80031DD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80031DDC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80031DE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80031DE4: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x80031DE8: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x80031DEC: sb          $a3, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r7;
    // 0x80031DF0: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    // 0x80031DF4: sb          $a1, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r5;
    // 0x80031DF8: sb          $a2, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r6;
    // 0x80031DFC: sh          $zero, 0x8($a0)
    MEM_H(0X8, ctx->r4) = 0;
    // 0x80031E00: sb          $zero, 0x7($a0)
    MEM_B(0X7, ctx->r4) = 0;
    // 0x80031E04: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x80031E08: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x80031E0C: sh          $zero, 0x12($a0)
    MEM_H(0X12, ctx->r4) = 0;
    // 0x80031E10: sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    // 0x80031E14: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x80031E18: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x80031E1C: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80031E20: sb          $v1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r3;
    // 0x80031E24: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x80031E28: jr          $ra
    // 0x80031E2C: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80031E2C: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_80031E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031E30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80031E34: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80031E38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031E3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80031E40: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80031E44: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x80031E48: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80031E4C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80031E50: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x80031E54: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80031E58: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x80031E5C: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // 0x80031E60: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    // 0x80031E64: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x80031E68: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x80031E6C: sb          $s0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r16;
    // 0x80031E70: sb          $s1, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r17;
    // 0x80031E74: sh          $zero, 0x8($a0)
    MEM_H(0X8, ctx->r4) = 0;
    // 0x80031E78: sb          $zero, 0x7($a0)
    MEM_B(0X7, ctx->r4) = 0;
    // 0x80031E7C: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x80031E80: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x80031E84: sh          $zero, 0x12($a0)
    MEM_H(0X12, ctx->r4) = 0;
    // 0x80031E88: sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    // 0x80031E8C: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x80031E90: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x80031E94: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80031E98: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x80031E9C: beq         $a2, $zero, L_80031EC4
    if (ctx->r6 == 0) {
        // 0x80031EA0: swc1        $f0, 0x1C($a0)
        MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
            goto L_80031EC4;
    }
    // 0x80031EA0: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x80031EA4: lbu         $v0, 0x6($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X6);
    // 0x80031EA8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80031EAC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80031EB0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80031EB4: lw          $a0, 0x707C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X707C);
    // 0x80031EB8: lui         $a1, 0x8030
    ctx->r5 = S32(0X8030 << 16);
    // 0x80031EBC: j           L_80031EE0
    // 0x80031EC0: addiu       $a1, $a1, 0x700
    ctx->r5 = ADD32(ctx->r5, 0X700);
        goto L_80031EE0;
    // 0x80031EC0: addiu       $a1, $a1, 0x700
    ctx->r5 = ADD32(ctx->r5, 0X700);
L_80031EC4:
    // 0x80031EC4: lbu         $v0, 0x6($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X6);
    // 0x80031EC8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80031ECC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80031ED0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80031ED4: lw          $a0, 0x707C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X707C);
    // 0x80031ED8: lui         $a1, 0x8030
    ctx->r5 = S32(0X8030 << 16);
    // 0x80031EDC: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
L_80031EE0:
    // 0x80031EE0: jal         0x80006D98
    // 0x80031EE4: addiu       $a2, $zero, 0x700
    ctx->r6 = ADD32(0, 0X700);
    func_80006D98(rdram, ctx);
        goto after_0;
    // 0x80031EE4: addiu       $a2, $zero, 0x700
    ctx->r6 = ADD32(0, 0X700);
    after_0:
    // 0x80031EE8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80031EEC: sll         $v1, $s0, 24
    ctx->r3 = S32(ctx->r16 << 24);
    // 0x80031EF0: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80031EF4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80031EF8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80031EFC: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80031F00: sra         $a3, $v0, 24
    ctx->r7 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80031F04: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x80031F08: addiu       $t0, $t0, -0x7A70
    ctx->r8 = ADD32(ctx->r8, -0X7A70);
    // 0x80031F0C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80031F10: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80031F14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80031F18: sll         $v0, $a1, 24
    ctx->r2 = S32(ctx->r5 << 24);
L_80031F1C:
    // 0x80031F1C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80031F20: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x80031F24: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80031F28: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80031F2C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80031F30: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80031F34: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80031F38: addiu       $a0, $a1, 0x1
    ctx->r4 = ADD32(ctx->r5, 0X1);
    // 0x80031F3C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031F40: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80031F44: sb          $a1, -0x7A6E($at)
    MEM_B(-0X7A6E, ctx->r1) = ctx->r5;
    // 0x80031F48: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80031F4C: addu        $v0, $v1, $t0
    ctx->r2 = ADD32(ctx->r3, ctx->r8);
    // 0x80031F50: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x80031F54: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80031F58: slti        $a0, $a0, 0x3
    ctx->r4 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x80031F5C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031F60: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80031F64: sb          $a2, -0x7A70($at)
    MEM_B(-0X7A70, ctx->r1) = ctx->r6;
    // 0x80031F68: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031F6C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80031F70: sb          $zero, -0x7A6F($at)
    MEM_B(-0X7A6F, ctx->r1) = 0;
    // 0x80031F74: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031F78: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80031F7C: sb          $zero, -0x7A6C($at)
    MEM_B(-0X7A6C, ctx->r1) = 0;
    // 0x80031F80: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031F84: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80031F88: sb          $zero, -0x7A6D($at)
    MEM_B(-0X7A6D, ctx->r1) = 0;
    // 0x80031F8C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031F90: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80031F94: sb          $s0, -0x7A6B($at)
    MEM_B(-0X7A6B, ctx->r1) = ctx->r16;
    // 0x80031F98: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031F9C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80031FA0: sb          $s1, -0x7A6A($at)
    MEM_B(-0X7A6A, ctx->r1) = ctx->r17;
    // 0x80031FA4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031FA8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80031FAC: sh          $zero, -0x7A68($at)
    MEM_H(-0X7A68, ctx->r1) = 0;
    // 0x80031FB0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031FB4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80031FB8: sb          $zero, -0x7A69($at)
    MEM_B(-0X7A69, ctx->r1) = 0;
    // 0x80031FBC: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x80031FC0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031FC4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80031FC8: sw          $zero, -0x7A5C($at)
    MEM_W(-0X7A5C, ctx->r1) = 0;
    // 0x80031FCC: sh          $zero, 0x12($v0)
    MEM_H(0X12, ctx->r2) = 0;
    // 0x80031FD0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031FD4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80031FD8: sh          $zero, -0x7A60($at)
    MEM_H(-0X7A60, ctx->r1) = 0;
    // 0x80031FDC: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80031FE0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031FE4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80031FE8: swc1        $f0, -0x7A54($at)
    MEM_W(-0X7A54, ctx->r1) = ctx->f0.u32l;
    // 0x80031FEC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031FF0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80031FF4: sw          $a2, -0x7A44($at)
    MEM_W(-0X7A44, ctx->r1) = ctx->r6;
    // 0x80031FF8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80031FFC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80032000: sw          $zero, -0x7A40($at)
    MEM_W(-0X7A40, ctx->r1) = 0;
    // 0x80032004: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80032008: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8003200C: sw          $zero, -0x7A4C($at)
    MEM_W(-0X7A4C, ctx->r1) = 0;
    // 0x80032010: bne         $a0, $zero, L_80031F1C
    if (ctx->r4 != 0) {
        // 0x80032014: sll         $v0, $a1, 24
        ctx->r2 = S32(ctx->r5 << 24);
            goto L_80031F1C;
    }
    // 0x80032014: sll         $v0, $a1, 24
    ctx->r2 = S32(ctx->r5 << 24);
    // 0x80032018: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8003201C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80032020: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80032024: jr          $ra
    // 0x80032028: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80032028: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8003202C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003202C: lb          $v0, 0x5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5);
    // 0x80032030: beq         $v0, $zero, L_80032048
    if (ctx->r2 == 0) {
        // 0x80032034: lui         $a2, 0x8030
        ctx->r6 = S32(0X8030 << 16);
            goto L_80032048;
    }
    // 0x80032034: lui         $a2, 0x8030
    ctx->r6 = S32(0X8030 << 16);
    // 0x80032038: lui         $a1, 0x8030
    ctx->r5 = S32(0X8030 << 16);
    // 0x8003203C: addiu       $a1, $a1, 0x700
    ctx->r5 = ADD32(ctx->r5, 0X700);
    // 0x80032040: j           L_80032050
    // 0x80032044: ori         $a2, $a2, 0x700
    ctx->r6 = ctx->r6 | 0X700;
        goto L_80032050;
    // 0x80032044: ori         $a2, $a2, 0x700
    ctx->r6 = ctx->r6 | 0X700;
L_80032048:
    // 0x80032048: lui         $a1, 0x8030
    ctx->r5 = S32(0X8030 << 16);
    // 0x8003204C: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
L_80032050:
    // 0x80032050: lbu         $v0, 0x6($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X6);
    // 0x80032054: lbu         $v1, 0x4($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X4);
    // 0x80032058: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003205C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80032060: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80032064: lw          $a0, 0x7060($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7060);
    // 0x80032068: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8003206C: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80032070: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80032074: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80032078: jr          $ra
    // 0x8003207C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    return;
    // 0x8003207C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
;}
RECOMP_FUNC void func_80032080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032080: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80032084: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80032088: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8003208C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80032090: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80032094: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80032098: lbu         $a0, 0x2($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X2);
    // 0x8003209C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800320A0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800320A4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800320A8: lw          $v1, 0x70D0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X70D0);
    // 0x800320AC: lh          $v0, 0x8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X8);
    // 0x800320B0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800320B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800320B8: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800320BC: lb          $a1, 0x0($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X0);
    // 0x800320C0: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x800320C4: addiu       $s0, $s1, 0xC
    ctx->r16 = ADD32(ctx->r17, 0XC);
    // 0x800320C8: jal         0x80053234
    // 0x800320CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80053234(rdram, ctx);
        goto after_0;
    // 0x800320CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800320D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800320D4: jal         0x80051C7C
    // 0x800320D8: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    func_80051C7C(rdram, ctx);
        goto after_1;
    // 0x800320D8: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    after_1:
    // 0x800320DC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800320E0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800320E4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800320E8: jr          $ra
    // 0x800320EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800320EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800320F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800320F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800320F4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800320F8: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x800320FC: beq         $v0, $zero, L_80032124
    if (ctx->r2 == 0) {
        // 0x80032100: nop
    
            goto L_80032124;
    }
    // 0x80032100: nop

    // 0x80032104: lbu         $v0, 0x6($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X6);
    // 0x80032108: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003210C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80032110: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80032114: lw          $a0, 0x707C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X707C);
    // 0x80032118: lui         $a1, 0x8030
    ctx->r5 = S32(0X8030 << 16);
    // 0x8003211C: j           L_80032140
    // 0x80032120: addiu       $a1, $a1, 0x700
    ctx->r5 = ADD32(ctx->r5, 0X700);
        goto L_80032140;
    // 0x80032120: addiu       $a1, $a1, 0x700
    ctx->r5 = ADD32(ctx->r5, 0X700);
L_80032124:
    // 0x80032124: lbu         $v0, 0x6($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X6);
    // 0x80032128: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003212C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80032130: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80032134: lw          $a0, 0x707C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X707C);
    // 0x80032138: lui         $a1, 0x8030
    ctx->r5 = S32(0X8030 << 16);
    // 0x8003213C: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
L_80032140:
    // 0x80032140: jal         0x80006D98
    // 0x80032144: addiu       $a2, $zero, 0x700
    ctx->r6 = ADD32(0, 0X700);
    func_80006D98(rdram, ctx);
        goto after_0;
    // 0x80032144: addiu       $a2, $zero, 0x700
    ctx->r6 = ADD32(0, 0X700);
    after_0:
    // 0x80032148: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003214C: jr          $ra
    // 0x80032150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80032150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80032154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032154: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80032158: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003215C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80032160: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80032164: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80032168: lbu         $a0, 0x2($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X2);
    // 0x8003216C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80032170: beq         $a0, $a2, L_80032234
    if (ctx->r4 == ctx->r6) {
        // 0x80032174: slti        $v0, $a0, 0x2
        ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
            goto L_80032234;
    }
    // 0x80032174: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x80032178: beql        $v0, $zero, L_80032190
    if (ctx->r2 == 0) {
        // 0x8003217C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80032190;
    }
    goto skip_0;
    // 0x8003217C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x80032180: beq         $a0, $zero, L_800321A0
    if (ctx->r4 == 0) {
        // 0x80032184: nop
    
            goto L_800321A0;
    }
    // 0x80032184: nop

    // 0x80032188: j           L_80032248
    // 0x8003218C: nop

        goto L_80032248;
    // 0x8003218C: nop

L_80032190:
    // 0x80032190: beq         $a0, $v0, L_800321B8
    if (ctx->r4 == ctx->r2) {
        // 0x80032194: nop
    
            goto L_800321B8;
    }
    // 0x80032194: nop

    // 0x80032198: j           L_80032248
    // 0x8003219C: nop

        goto L_80032248;
    // 0x8003219C: nop

L_800321A0:
    // 0x800321A0: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x800321A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800321A8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800321AC: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800321B0: j           L_80032248
    // 0x800321B4: lw          $a1, 0x7DA0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7DA0);
        goto L_80032248;
    // 0x800321B4: lw          $a1, 0x7DA0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7DA0);
L_800321B8:
    // 0x800321B8: lbu         $v1, 0x4($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X4);
    // 0x800321BC: beq         $v1, $a2, L_80032204
    if (ctx->r3 == ctx->r6) {
        // 0x800321C0: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80032204;
    }
    // 0x800321C0: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800321C4: beq         $v0, $zero, L_800321DC
    if (ctx->r2 == 0) {
        // 0x800321C8: nop
    
            goto L_800321DC;
    }
    // 0x800321C8: nop

    // 0x800321CC: beq         $v1, $zero, L_800321EC
    if (ctx->r3 == 0) {
        // 0x800321D0: nop
    
            goto L_800321EC;
    }
    // 0x800321D0: nop

    // 0x800321D4: j           L_80032248
    // 0x800321D8: nop

        goto L_80032248;
    // 0x800321D8: nop

L_800321DC:
    // 0x800321DC: beq         $v1, $a0, L_8003221C
    if (ctx->r3 == ctx->r4) {
        // 0x800321E0: nop
    
            goto L_8003221C;
    }
    // 0x800321E0: nop

    // 0x800321E4: j           L_80032248
    // 0x800321E8: nop

        goto L_80032248;
    // 0x800321E8: nop

L_800321EC:
    // 0x800321EC: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x800321F0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800321F4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800321F8: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800321FC: j           L_80032248
    // 0x80032200: lw          $a1, 0x7DBC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7DBC);
        goto L_80032248;
    // 0x80032200: lw          $a1, 0x7DBC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7DBC);
L_80032204:
    // 0x80032204: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80032208: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003220C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80032210: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80032214: j           L_80032248
    // 0x80032218: lw          $a1, 0x7DD8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7DD8);
        goto L_80032248;
    // 0x80032218: lw          $a1, 0x7DD8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7DD8);
L_8003221C:
    // 0x8003221C: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80032220: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032224: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80032228: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8003222C: j           L_80032248
    // 0x80032230: lw          $a1, 0x7DF4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7DF4);
        goto L_80032248;
    // 0x80032230: lw          $a1, 0x7DF4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7DF4);
L_80032234:
    // 0x80032234: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80032238: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003223C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80032240: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80032244: lw          $a1, 0x7E10($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7E10);
L_80032248:
    // 0x80032248: lh          $v0, 0x8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X8);
    // 0x8003224C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032250: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80032254: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80032258: lb          $a1, 0x70F1($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X70F1);
    // 0x8003225C: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80032260: addiu       $s0, $s1, 0xC
    ctx->r16 = ADD32(ctx->r17, 0XC);
    // 0x80032264: jal         0x80053234
    // 0x80032268: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80053234(rdram, ctx);
        goto after_0;
    // 0x80032268: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8003226C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80032270: jal         0x80051C7C
    // 0x80032274: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    func_80051C7C(rdram, ctx);
        goto after_1;
    // 0x80032274: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    after_1:
    // 0x80032278: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8003227C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80032280: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80032284: jr          $ra
    // 0x80032288: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80032288: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8003228C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003228C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80032290: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80032294: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80032298: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8003229C: beq         $v0, $zero, L_800326E4
    if (ctx->r2 == 0) {
        // 0x800322A0: nop
    
            goto L_800326E4;
    }
    // 0x800322A0: nop

    // 0x800322A4: lw          $v0, 0x2C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X2C);
    // 0x800322A8: beq         $v0, $zero, L_800322E0
    if (ctx->r2 == 0) {
        // 0x800322AC: nop
    
            goto L_800322E0;
    }
    // 0x800322AC: nop

    // 0x800322B0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800322B4: lb          $v0, 0x5585($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5585);
    // 0x800322B8: beq         $v0, $zero, L_800322E0
    if (ctx->r2 == 0) {
        // 0x800322BC: nop
    
            goto L_800322E0;
    }
    // 0x800322BC: nop

    // 0x800322C0: lw          $v1, 0x30($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X30);
    // 0x800322C4: sltiu       $v0, $v1, 0xFC
    ctx->r2 = ctx->r3 < 0XFC ? 1 : 0;
    // 0x800322C8: beq         $v0, $zero, L_800322D8
    if (ctx->r2 == 0) {
        // 0x800322CC: addiu       $v0, $v1, 0x3
        ctx->r2 = ADD32(ctx->r3, 0X3);
            goto L_800322D8;
    }
    // 0x800322CC: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // 0x800322D0: j           L_800322E0
    // 0x800322D4: sw          $v0, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r2;
        goto L_800322E0;
    // 0x800322D4: sw          $v0, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r2;
L_800322D8:
    // 0x800322D8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800322DC: sw          $v0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r2;
L_800322E0:
    // 0x800322E0: lbu         $v0, 0x5($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X5);
    // 0x800322E4: beq         $v0, $zero, L_800322F0
    if (ctx->r2 == 0) {
        // 0x800322E8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800322F0;
    }
    // 0x800322E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800322EC: sh          $v0, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r2;
L_800322F0:
    // 0x800322F0: lbu         $v1, 0x5($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X5);
    // 0x800322F4: lbu         $a0, 0x3($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X3);
    // 0x800322F8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800322FC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032300: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032304: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032308: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003230C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80032310: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80032314: lbu         $v1, 0x447E($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X447E);
    // 0x80032318: lbu         $v0, 0x4($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X4);
    // 0x8003231C: beq         $a0, $v0, L_8003234C
    if (ctx->r4 == ctx->r2) {
        // 0x80032320: sb          $v1, 0x6($a1)
        MEM_B(0X6, ctx->r5) = ctx->r3;
            goto L_8003234C;
    }
    // 0x80032320: sb          $v1, 0x6($a1)
    MEM_B(0X6, ctx->r5) = ctx->r3;
    // 0x80032324: lbu         $a0, 0x3($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X3);
    // 0x80032328: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8003232C: sh          $zero, 0x8($a1)
    MEM_H(0X8, ctx->r5) = 0;
    // 0x80032330: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x80032334: beq         $v1, $v0, L_80032344
    if (ctx->r3 == ctx->r2) {
        // 0x80032338: sb          $zero, 0x7($a1)
        MEM_B(0X7, ctx->r5) = 0;
            goto L_80032344;
    }
    // 0x80032338: sb          $zero, 0x7($a1)
    MEM_B(0X7, ctx->r5) = 0;
    // 0x8003233C: j           L_8003234C
    // 0x80032340: sb          $a0, 0x4($a1)
    MEM_B(0X4, ctx->r5) = ctx->r4;
        goto L_8003234C;
    // 0x80032340: sb          $a0, 0x4($a1)
    MEM_B(0X4, ctx->r5) = ctx->r4;
L_80032344:
    // 0x80032344: lbu         $v0, 0x4($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X4);
    // 0x80032348: sb          $v0, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r2;
L_8003234C:
    // 0x8003234C: lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X2);
    // 0x80032350: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80032354: beq         $v1, $v0, L_800323B8
    if (ctx->r3 == ctx->r2) {
        // 0x80032358: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800323B8;
    }
    // 0x80032358: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8003235C: beql        $v0, $zero, L_80032374
    if (ctx->r2 == 0) {
        // 0x80032360: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80032374;
    }
    goto skip_0;
    // 0x80032360: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x80032364: beq         $v1, $zero, L_80032384
    if (ctx->r3 == 0) {
        // 0x80032368: nop
    
            goto L_80032384;
    }
    // 0x80032368: nop

    // 0x8003236C: j           L_8003245C
    // 0x80032370: nop

        goto L_8003245C;
    // 0x80032370: nop

L_80032374:
    // 0x80032374: beq         $v1, $v0, L_8003240C
    if (ctx->r3 == ctx->r2) {
        // 0x80032378: nop
    
            goto L_8003240C;
    }
    // 0x80032378: nop

    // 0x8003237C: j           L_8003245C
    // 0x80032380: nop

        goto L_8003245C;
    // 0x80032380: nop

L_80032384:
    // 0x80032384: lbu         $v0, 0x5($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X5);
    // 0x80032388: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003238C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80032390: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80032394: lw          $v1, 0x7164($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7164);
    // 0x80032398: lbu         $v0, 0x5($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X5);
    // 0x8003239C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800323A0: sw          $v1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r3;
    // 0x800323A4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800323A8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800323AC: lw          $v0, 0x7168($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7168);
    // 0x800323B0: j           L_8003245C
    // 0x800323B4: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
        goto L_8003245C;
    // 0x800323B4: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
L_800323B8:
    // 0x800323B8: lbu         $v0, 0x5($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X5);
    // 0x800323BC: lbu         $v1, 0x6($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X6);
    // 0x800323C0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800323C4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800323C8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800323CC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800323D0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800323D4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800323D8: lw          $a0, 0x71E4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X71E4);
    // 0x800323DC: lbu         $v0, 0x5($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X5);
    // 0x800323E0: lbu         $v1, 0x6($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X6);
    // 0x800323E4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800323E8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800323EC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800323F0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800323F4: sw          $a0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r4;
    // 0x800323F8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800323FC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80032400: lw          $v0, 0x71E8($at)
    ctx->r2 = MEM_W(ctx->r1, 0X71E8);
    // 0x80032404: j           L_8003245C
    // 0x80032408: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
        goto L_8003245C;
    // 0x80032408: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
L_8003240C:
    // 0x8003240C: lbu         $v0, 0x5($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X5);
    // 0x80032410: lbu         $v1, 0x6($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X6);
    // 0x80032414: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80032418: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8003241C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032420: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032424: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80032428: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8003242C: lw          $a0, 0x7174($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7174);
    // 0x80032430: lbu         $v0, 0x5($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X5);
    // 0x80032434: lbu         $v1, 0x6($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X6);
    // 0x80032438: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8003243C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80032440: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032444: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032448: sw          $a0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r4;
    // 0x8003244C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80032450: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80032454: lw          $v0, 0x7178($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7178);
    // 0x80032458: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
L_8003245C:
    // 0x8003245C: lbu         $v0, 0x5($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X5);
    // 0x80032460: beq         $v0, $zero, L_80032474
    if (ctx->r2 == 0) {
        // 0x80032464: nop
    
            goto L_80032474;
    }
    // 0x80032464: nop

    // 0x80032468: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8003246C: j           L_8003247C
    // 0x80032470: lb          $v1, 0x7A48($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X7A48);
        goto L_8003247C;
    // 0x80032470: lb          $v1, 0x7A48($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X7A48);
L_80032474:
    // 0x80032474: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80032478: lb          $v1, 0x25F8($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X25F8);
L_8003247C:
    // 0x8003247C: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x80032480: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032484: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    // 0x80032488: lbu         $a0, 0x2($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X2);
    // 0x8003248C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80032490: beq         $a0, $a2, L_8003265C
    if (ctx->r4 == ctx->r6) {
        // 0x80032494: slti        $v0, $a0, 0x2
        ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
            goto L_8003265C;
    }
    // 0x80032494: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x80032498: beql        $v0, $zero, L_800324B0
    if (ctx->r2 == 0) {
        // 0x8003249C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800324B0;
    }
    goto skip_1;
    // 0x8003249C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_1:
    // 0x800324A0: beq         $a0, $zero, L_800324C0
    if (ctx->r4 == 0) {
        // 0x800324A4: nop
    
            goto L_800324C0;
    }
    // 0x800324A4: nop

    // 0x800324A8: j           L_800326DC
    // 0x800324AC: nop

        goto L_800326DC;
    // 0x800324AC: nop

L_800324B0:
    // 0x800324B0: beq         $a0, $v0, L_80032508
    if (ctx->r4 == ctx->r2) {
        // 0x800324B4: nop
    
            goto L_80032508;
    }
    // 0x800324B4: nop

    // 0x800324B8: j           L_800326DC
    // 0x800324BC: nop

        goto L_800326DC;
    // 0x800324BC: nop

L_800324C0:
    // 0x800324C0: lbu         $v0, 0x6($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X6);
    // 0x800324C4: lbu         $v1, 0x4($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X4);
    // 0x800324C8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800324CC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800324D0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800324D4: lw          $a0, 0x7DA0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7DA0);
    // 0x800324D8: beql        $v1, $zero, L_800326D8
    if (ctx->r3 == 0) {
        // 0x800324DC: sh          $zero, 0x8($a1)
        MEM_H(0X8, ctx->r5) = 0;
            goto L_800326D8;
    }
    goto skip_2;
    // 0x800324DC: sh          $zero, 0x8($a1)
    MEM_H(0X8, ctx->r5) = 0;
    skip_2:
    // 0x800324E0: lh          $v0, 0x8($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X8);
    // 0x800324E4: lbu         $v1, 0x7($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X7);
    // 0x800324E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800324EC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800324F0: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x800324F4: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800324F8: bne         $v0, $zero, L_8003269C
    if (ctx->r2 != 0) {
        // 0x800324FC: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8003269C;
    }
    // 0x800324FC: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80032500: j           L_800326A4
    // 0x80032504: nop

        goto L_800326A4;
    // 0x80032504: nop

L_80032508:
    // 0x80032508: lbu         $v1, 0x4($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X4);
    // 0x8003250C: beq         $v1, $a2, L_800325AC
    if (ctx->r3 == ctx->r6) {
        // 0x80032510: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800325AC;
    }
    // 0x80032510: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80032514: beq         $v0, $zero, L_8003252C
    if (ctx->r2 == 0) {
        // 0x80032518: nop
    
            goto L_8003252C;
    }
    // 0x80032518: nop

    // 0x8003251C: beq         $v1, $zero, L_8003253C
    if (ctx->r3 == 0) {
        // 0x80032520: nop
    
            goto L_8003253C;
    }
    // 0x80032520: nop

    // 0x80032524: j           L_800326DC
    // 0x80032528: nop

        goto L_800326DC;
    // 0x80032528: nop

L_8003252C:
    // 0x8003252C: beq         $v1, $a0, L_800325E8
    if (ctx->r3 == ctx->r4) {
        // 0x80032530: nop
    
            goto L_800325E8;
    }
    // 0x80032530: nop

    // 0x80032534: j           L_800326DC
    // 0x80032538: nop

        goto L_800326DC;
    // 0x80032538: nop

L_8003253C:
    // 0x8003253C: lbu         $v1, 0x5($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X5);
    // 0x80032540: lbu         $a0, 0x6($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X6);
    // 0x80032544: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80032548: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003254C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032550: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032554: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032558: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8003255C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80032560: lbu         $v0, 0x447C($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X447C);
    // 0x80032564: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80032568: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8003256C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80032570: lw          $a0, 0x7DBC($at)
    ctx->r4 = MEM_W(ctx->r1, 0X7DBC);
    // 0x80032574: bnel        $v0, $zero, L_800325A4
    if (ctx->r2 != 0) {
        // 0x80032578: sb          $zero, 0x7($a1)
        MEM_B(0X7, ctx->r5) = 0;
            goto L_800325A4;
    }
    goto skip_3;
    // 0x80032578: sb          $zero, 0x7($a1)
    MEM_B(0X7, ctx->r5) = 0;
    skip_3:
    // 0x8003257C: lh          $v0, 0x8($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X8);
    // 0x80032580: lbu         $v1, 0x7($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X7);
    // 0x80032584: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032588: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8003258C: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x80032590: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80032594: bne         $v0, $zero, L_8003269C
    if (ctx->r2 != 0) {
        // 0x80032598: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8003269C;
    }
    // 0x80032598: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8003259C: j           L_80032624
    // 0x800325A0: nop

        goto L_80032624;
    // 0x800325A0: nop

L_800325A4:
    // 0x800325A4: j           L_800326DC
    // 0x800325A8: sh          $zero, 0x8($a1)
    MEM_H(0X8, ctx->r5) = 0;
        goto L_800326DC;
    // 0x800325A8: sh          $zero, 0x8($a1)
    MEM_H(0X8, ctx->r5) = 0;
L_800325AC:
    // 0x800325AC: lbu         $v0, 0x6($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X6);
    // 0x800325B0: lh          $v1, 0x8($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X8);
    // 0x800325B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800325B8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800325BC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800325C0: lw          $a0, 0x7DD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7DD8);
    // 0x800325C4: lbu         $a2, 0x7($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X7);
    // 0x800325C8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800325CC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800325D0: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x800325D4: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800325D8: bne         $v0, $zero, L_8003261C
    if (ctx->r2 != 0) {
        // 0x800325DC: addiu       $v0, $a2, 0x1
        ctx->r2 = ADD32(ctx->r6, 0X1);
            goto L_8003261C;
    }
    // 0x800325DC: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x800325E0: j           L_800326A4
    // 0x800325E4: nop

        goto L_800326A4;
    // 0x800325E4: nop

L_800325E8:
    // 0x800325E8: lbu         $v0, 0x6($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X6);
    // 0x800325EC: lh          $v1, 0x8($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X8);
    // 0x800325F0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800325F4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800325F8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800325FC: lw          $a0, 0x7DF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7DF4);
    // 0x80032600: lbu         $a2, 0x7($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X7);
    // 0x80032604: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80032608: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8003260C: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80032610: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80032614: beq         $v0, $zero, L_80032624
    if (ctx->r2 == 0) {
        // 0x80032618: addiu       $v0, $a2, 0x1
        ctx->r2 = ADD32(ctx->r6, 0X1);
            goto L_80032624;
    }
    // 0x80032618: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
L_8003261C:
    // 0x8003261C: j           L_800326DC
    // 0x80032620: sb          $v0, 0x7($a1)
    MEM_B(0X7, ctx->r5) = ctx->r2;
        goto L_800326DC;
    // 0x80032620: sb          $v0, 0x7($a1)
    MEM_B(0X7, ctx->r5) = ctx->r2;
L_80032624:
    // 0x80032624: lhu         $v0, 0x8($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X8);
    // 0x80032628: sb          $zero, 0x7($a1)
    MEM_B(0X7, ctx->r5) = 0;
    // 0x8003262C: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80032630: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80032634: sra         $v0, $v0, 14
    ctx->r2 = S32(SIGNED(ctx->r2) >> 14);
    // 0x80032638: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x8003263C: sh          $v1, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r3;
    // 0x80032640: lb          $v0, 0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X1);
    // 0x80032644: beq         $v0, $zero, L_800326DC
    if (ctx->r2 == 0) {
        // 0x80032648: nop
    
            goto L_800326DC;
    }
    // 0x80032648: nop

    // 0x8003264C: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x80032650: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80032654: j           L_800326DC
    // 0x80032658: sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
        goto L_800326DC;
    // 0x80032658: sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
L_8003265C:
    // 0x8003265C: lbu         $v0, 0x6($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X6);
    // 0x80032660: lbu         $v1, 0x4($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X4);
    // 0x80032664: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032668: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8003266C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80032670: lw          $a0, 0x7E10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7E10);
    // 0x80032674: beql        $v1, $zero, L_800326D8
    if (ctx->r3 == 0) {
        // 0x80032678: sh          $zero, 0x8($a1)
        MEM_H(0X8, ctx->r5) = 0;
            goto L_800326D8;
    }
    goto skip_4;
    // 0x80032678: sh          $zero, 0x8($a1)
    MEM_H(0X8, ctx->r5) = 0;
    skip_4:
    // 0x8003267C: lh          $v0, 0x8($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X8);
    // 0x80032680: lbu         $v1, 0x7($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X7);
    // 0x80032684: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032688: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8003268C: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x80032690: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80032694: beq         $v0, $zero, L_800326A4
    if (ctx->r2 == 0) {
        // 0x80032698: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_800326A4;
    }
    // 0x80032698: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_8003269C:
    // 0x8003269C: j           L_800326DC
    // 0x800326A0: sb          $v0, 0x7($a1)
    MEM_B(0X7, ctx->r5) = ctx->r2;
        goto L_800326DC;
    // 0x800326A0: sb          $v0, 0x7($a1)
    MEM_B(0X7, ctx->r5) = ctx->r2;
L_800326A4:
    // 0x800326A4: lhu         $v0, 0x8($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X8);
    // 0x800326A8: sb          $zero, 0x7($a1)
    MEM_B(0X7, ctx->r5) = 0;
    // 0x800326AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800326B0: sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // 0x800326B4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800326B8: sra         $v0, $v0, 14
    ctx->r2 = S32(SIGNED(ctx->r2) >> 14);
    // 0x800326BC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800326C0: lb          $v0, 0x1($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X1);
    // 0x800326C4: beq         $v0, $zero, L_800326DC
    if (ctx->r2 == 0) {
        // 0x800326C8: nop
    
            goto L_800326DC;
    }
    // 0x800326C8: nop

    // 0x800326CC: sh          $zero, 0x8($a1)
    MEM_H(0X8, ctx->r5) = 0;
    // 0x800326D0: j           L_800326DC
    // 0x800326D4: sb          $zero, 0x3($a1)
    MEM_B(0X3, ctx->r5) = 0;
        goto L_800326DC;
    // 0x800326D4: sb          $zero, 0x3($a1)
    MEM_B(0X3, ctx->r5) = 0;
L_800326D8:
    // 0x800326D8: sb          $zero, 0x7($a1)
    MEM_B(0X7, ctx->r5) = 0;
L_800326DC:
    // 0x800326DC: jal         0x80032154
    // 0x800326E0: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    func_80032154(rdram, ctx);
        goto after_0;
    // 0x800326E0: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    after_0:
L_800326E4:
    // 0x800326E4: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800326E8: jr          $ra
    // 0x800326EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800326EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800326F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800326F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800326F4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800326F8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800326FC: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80032700: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80032704: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80032708: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003270C: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80032710: beq         $v0, $zero, L_80032E84
    if (ctx->r2 == 0) {
        // 0x80032714: nop
    
            goto L_80032E84;
    }
    // 0x80032714: nop

    // 0x80032718: lbu         $v1, 0x3($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X3);
    // 0x8003271C: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x80032720: lbu         $s3, 0x5($s1)
    ctx->r19 = MEM_BU(ctx->r17, 0X5);
    // 0x80032724: beq         $v1, $v0, L_800329A8
    if (ctx->r3 == ctx->r2) {
        // 0x80032728: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_800329A8;
    }
    // 0x80032728: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003272C: beq         $v1, $a1, L_80032744
    if (ctx->r3 == ctx->r5) {
        // 0x80032730: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_80032744;
    }
    // 0x80032730: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80032734: beq         $v1, $v0, L_800327B4
    if (ctx->r3 == ctx->r2) {
        // 0x80032738: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800327B4;
    }
    // 0x80032738: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8003273C: j           L_800327D0
    // 0x80032740: nop

        goto L_800327D0;
    // 0x80032740: nop

L_80032744:
    // 0x80032744: lbu         $a0, 0x6($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X6);
    // 0x80032748: xori        $v1, $a0, 0x6
    ctx->r3 = ctx->r4 ^ 0X6;
    // 0x8003274C: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80032750: xori        $v0, $a0, 0x2
    ctx->r2 = ctx->r4 ^ 0X2;
    // 0x80032754: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80032758: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8003275C: beq         $v1, $zero, L_800327D0
    if (ctx->r3 == 0) {
        // 0x80032760: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_800327D0;
    }
    // 0x80032760: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80032764: bne         $a0, $v0, L_8003279C
    if (ctx->r4 != ctx->r2) {
        // 0x80032768: subu        $v0, $a1, $s3
        ctx->r2 = SUB32(ctx->r5, ctx->r19);
            goto L_8003279C;
    }
    // 0x80032768: subu        $v0, $a1, $s3
    ctx->r2 = SUB32(ctx->r5, ctx->r19);
    // 0x8003276C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80032770: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80032774: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80032778: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003277C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80032780: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80032784: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032788: lbu         $v0, 0x447E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X447E);
    // 0x8003278C: bne         $v0, $a1, L_800327D0
    if (ctx->r2 != ctx->r5) {
        // 0x80032790: addiu       $v0, $zero, 0x13
        ctx->r2 = ADD32(0, 0X13);
            goto L_800327D0;
    }
    // 0x80032790: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x80032794: j           L_800327D0
    // 0x80032798: sb          $v0, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r2;
        goto L_800327D0;
    // 0x80032798: sb          $v0, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r2;
L_8003279C:
    // 0x8003279C: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x800327A0: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x800327A4: bne         $v0, $zero, L_800327D0
    if (ctx->r2 != 0) {
        // 0x800327A8: addiu       $v0, $zero, 0x16
        ctx->r2 = ADD32(0, 0X16);
            goto L_800327D0;
    }
    // 0x800327A8: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x800327AC: j           L_800327D0
    // 0x800327B0: sb          $v0, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r2;
        goto L_800327D0;
    // 0x800327B0: sb          $v0, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r2;
L_800327B4:
    // 0x800327B4: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x800327B8: bne         $v1, $v0, L_800327D0
    if (ctx->r3 != ctx->r2) {
        // 0x800327BC: nop
    
            goto L_800327D0;
    }
    // 0x800327BC: nop

    // 0x800327C0: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x800327C4: bne         $v0, $a1, L_800327D0
    if (ctx->r2 != ctx->r5) {
        // 0x800327C8: addiu       $v0, $zero, 0x15
        ctx->r2 = ADD32(0, 0X15);
            goto L_800327D0;
    }
    // 0x800327C8: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    // 0x800327CC: sb          $v0, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r2;
L_800327D0:
    // 0x800327D0: lbu         $a0, 0x4($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X4);
    // 0x800327D4: xori        $v1, $a0, 0x1
    ctx->r3 = ctx->r4 ^ 0X1;
    // 0x800327D8: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x800327DC: xori        $v0, $a0, 0x13
    ctx->r2 = ctx->r4 ^ 0X13;
    // 0x800327E0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800327E4: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800327E8: beq         $v1, $zero, L_80032848
    if (ctx->r3 == 0) {
        // 0x800327EC: xori        $v1, $a0, 0x16
        ctx->r3 = ctx->r4 ^ 0X16;
            goto L_80032848;
    }
    // 0x800327EC: xori        $v1, $a0, 0x16
    ctx->r3 = ctx->r4 ^ 0X16;
    // 0x800327F0: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x800327F4: xori        $v0, $a0, 0xA
    ctx->r2 = ctx->r4 ^ 0XA;
    // 0x800327F8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800327FC: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80032800: beq         $v1, $zero, L_80032848
    if (ctx->r3 == 0) {
        // 0x80032804: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_80032848;
    }
    // 0x80032804: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80032808: beq         $a0, $v0, L_80032848
    if (ctx->r4 == ctx->r2) {
        // 0x8003280C: addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
            goto L_80032848;
    }
    // 0x8003280C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x80032810: beq         $a0, $v0, L_8003282C
    if (ctx->r4 == ctx->r2) {
        // 0x80032814: nop
    
            goto L_8003282C;
    }
    // 0x80032814: nop

    // 0x80032818: lbu         $v0, 0x3($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3);
    // 0x8003281C: sh          $zero, 0x8($s1)
    MEM_H(0X8, ctx->r17) = 0;
    // 0x80032820: sb          $zero, 0x7($s1)
    MEM_B(0X7, ctx->r17) = 0;
    // 0x80032824: j           L_80032898
    // 0x80032828: sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
        goto L_80032898;
    // 0x80032828: sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
L_8003282C:
    // 0x8003282C: lbu         $v1, 0x3($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X3);
    // 0x80032830: addiu       $v0, $v1, -0x9
    ctx->r2 = ADD32(ctx->r3, -0X9);
    // 0x80032834: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80032838: beq         $v0, $zero, L_80032898
    if (ctx->r2 == 0) {
        // 0x8003283C: nop
    
            goto L_80032898;
    }
    // 0x8003283C: nop

    // 0x80032840: j           L_80032890
    // 0x80032844: sb          $v1, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r3;
        goto L_80032890;
    // 0x80032844: sb          $v1, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r3;
L_80032848:
    // 0x80032848: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x8003284C: addiu       $v0, $v0, -0x9
    ctx->r2 = ADD32(ctx->r2, -0X9);
    // 0x80032850: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80032854: beq         $v0, $zero, L_80032898
    if (ctx->r2 == 0) {
        // 0x80032858: nop
    
            goto L_80032898;
    }
    // 0x80032858: nop

    // 0x8003285C: lbu         $a1, 0x3($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X3);
    // 0x80032860: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80032864: xori        $v1, $a0, 0x1
    ctx->r3 = ctx->r4 ^ 0X1;
    // 0x80032868: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8003286C: xori        $v0, $a0, 0x13
    ctx->r2 = ctx->r4 ^ 0X13;
    // 0x80032870: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80032874: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80032878: bnel        $v1, $zero, L_80032890
    if (ctx->r3 != 0) {
        // 0x8003287C: sb          $a1, 0x4($s1)
        MEM_B(0X4, ctx->r17) = ctx->r5;
            goto L_80032890;
    }
    goto skip_0;
    // 0x8003287C: sb          $a1, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r5;
    skip_0:
    // 0x80032880: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x80032884: bne         $a0, $v0, L_80032898
    if (ctx->r4 != ctx->r2) {
        // 0x80032888: nop
    
            goto L_80032898;
    }
    // 0x80032888: nop

    // 0x8003288C: sb          $a1, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r5;
L_80032890:
    // 0x80032890: sh          $zero, 0x8($s1)
    MEM_H(0X8, ctx->r17) = 0;
    // 0x80032894: sb          $zero, 0x7($s1)
    MEM_B(0X7, ctx->r17) = 0;
L_80032898:
    // 0x80032898: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x8003289C: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x800328A0: xori        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 ^ 0X8;
    // 0x800328A4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800328A8: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800328AC: beq         $v1, $zero, L_800328E4
    if (ctx->r3 == 0) {
        // 0x800328B0: nop
    
            goto L_800328E4;
    }
    // 0x800328B0: nop

    // 0x800328B4: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x800328B8: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x800328BC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800328C0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800328C4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800328C8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800328CC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800328D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800328D4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800328D8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800328DC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800328E0: sb          $zero, -0x7A6D($at)
    MEM_B(-0X7A6D, ctx->r1) = 0;
L_800328E4:
    // 0x800328E4: lbu         $v1, 0x4($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X4);
    // 0x800328E8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800328EC: beq         $v1, $v0, L_80032948
    if (ctx->r3 == ctx->r2) {
        // 0x800328F0: slti        $v0, $v1, 0x4
        ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_80032948;
    }
    // 0x800328F0: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800328F4: beq         $v0, $zero, L_8003290C
    if (ctx->r2 == 0) {
        // 0x800328F8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8003290C;
    }
    // 0x800328F8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800328FC: beq         $v1, $v0, L_80032920
    if (ctx->r3 == ctx->r2) {
        // 0x80032900: nop
    
            goto L_80032920;
    }
    // 0x80032900: nop

    // 0x80032904: j           L_800329A8
    // 0x80032908: nop

        goto L_800329A8;
    // 0x80032908: nop

L_8003290C:
    // 0x8003290C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80032910: beq         $v1, $v0, L_80032970
    if (ctx->r3 == ctx->r2) {
        // 0x80032914: nop
    
            goto L_80032970;
    }
    // 0x80032914: nop

    // 0x80032918: j           L_800329A8
    // 0x8003291C: nop

        goto L_800329A8;
    // 0x8003291C: nop

L_80032920:
    // 0x80032920: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80032924: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80032928: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003292C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80032930: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80032934: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032938: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003293C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032940: j           L_80032988
    // 0x80032944: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
        goto L_80032988;
    // 0x80032944: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
L_80032948:
    // 0x80032948: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x8003294C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80032950: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80032954: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80032958: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8003295C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032960: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032964: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032968: j           L_80032988
    // 0x8003296C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
        goto L_80032988;
    // 0x8003296C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
L_80032970:
    // 0x80032970: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80032974: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80032978: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8003297C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80032980: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80032984: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
L_80032988:
    // 0x80032988: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x8003298C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032990: lbu         $v0, -0x7A6C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7A6C);
    // 0x80032994: bne         $v0, $zero, L_800329A8
    if (ctx->r2 != 0) {
        // 0x80032998: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800329A8;
    }
    // 0x80032998: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003299C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800329A0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800329A4: sb          $v0, -0x7A6D($at)
    MEM_B(-0X7A6D, ctx->r1) = ctx->r2;
L_800329A8:
    // 0x800329A8: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x800329AC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800329B0: bne         $v1, $v0, L_80032A14
    if (ctx->r3 != ctx->r2) {
        // 0x800329B4: nop
    
            goto L_80032A14;
    }
    // 0x800329B4: nop

    // 0x800329B8: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x800329BC: xori        $v1, $v0, 0xA
    ctx->r3 = ctx->r2 ^ 0XA;
    // 0x800329C0: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800329C4: xori        $v0, $v0, 0x15
    ctx->r2 = ctx->r2 ^ 0X15;
    // 0x800329C8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800329CC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800329D0: beq         $v1, $zero, L_80032A14
    if (ctx->r3 == 0) {
        // 0x800329D4: nop
    
            goto L_80032A14;
    }
    // 0x800329D4: nop

    // 0x800329D8: lhu         $v1, 0x8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X8);
    // 0x800329DC: addiu       $v0, $v1, -0x6
    ctx->r2 = ADD32(ctx->r3, -0X6);
    // 0x800329E0: sltiu       $v0, $v0, 0x5
    ctx->r2 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x800329E4: beq         $v0, $zero, L_80032A00
    if (ctx->r2 == 0) {
        // 0x800329E8: sll         $v0, $v1, 16
        ctx->r2 = S32(ctx->r3 << 16);
            goto L_80032A00;
    }
    // 0x800329E8: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800329EC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800329F0: addiu       $v0, $v0, -0x5
    ctx->r2 = ADD32(ctx->r2, -0X5);
    // 0x800329F4: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x800329F8: j           L_80032A58
    // 0x800329FC: subu        $a0, $v1, $v0
    ctx->r4 = SUB32(ctx->r3, ctx->r2);
        goto L_80032A58;
    // 0x800329FC: subu        $a0, $v1, $v0
    ctx->r4 = SUB32(ctx->r3, ctx->r2);
L_80032A00:
    // 0x80032A00: lui         $v1, 0x5
    ctx->r3 = S32(0X5 << 16);
    // 0x80032A04: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80032A08: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80032A0C: j           L_80032A58
    // 0x80032A10: andi        $a0, $v0, 0x23
    ctx->r4 = ctx->r2 & 0X23;
        goto L_80032A58;
    // 0x80032A10: andi        $a0, $v0, 0x23
    ctx->r4 = ctx->r2 & 0X23;
L_80032A14:
    // 0x80032A14: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80032A18: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80032A1C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80032A20: beq         $v0, $zero, L_80032A54
    if (ctx->r2 == 0) {
        // 0x80032A24: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_80032A54;
    }
    // 0x80032A24: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80032A28: lbu         $v1, 0x4($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X4);
    // 0x80032A2C: bne         $v1, $v0, L_80032A58
    if (ctx->r3 != ctx->r2) {
        // 0x80032A30: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80032A58;
    }
    // 0x80032A30: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80032A34: lh          $v1, 0x8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X8);
    // 0x80032A38: slti        $v0, $v1, 0x7
    ctx->r2 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // 0x80032A3C: beq         $v0, $zero, L_80032A4C
    if (ctx->r2 == 0) {
        // 0x80032A40: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80032A4C;
    }
    // 0x80032A40: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80032A44: j           L_80032A58
    // 0x80032A48: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
        goto L_80032A58;
    // 0x80032A48: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
L_80032A4C:
    // 0x80032A4C: j           L_80032A58
    // 0x80032A50: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
        goto L_80032A58;
    // 0x80032A50: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
L_80032A54:
    // 0x80032A54: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80032A58:
    // 0x80032A58: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x80032A5C: addiu       $v0, $v1, -0x3
    ctx->r2 = ADD32(ctx->r3, -0X3);
    // 0x80032A60: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80032A64: bne         $v0, $zero, L_80032A9C
    if (ctx->r2 != 0) {
        // 0x80032A68: andi        $v1, $v1, 0xFF
        ctx->r3 = ctx->r3 & 0XFF;
            goto L_80032A9C;
    }
    // 0x80032A68: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80032A6C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80032A70: beq         $v1, $v0, L_80032A9C
    if (ctx->r3 == ctx->r2) {
        // 0x80032A74: sll         $v1, $v1, 2
        ctx->r3 = S32(ctx->r3 << 2);
            goto L_80032A9C;
    }
    // 0x80032A74: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80032A78: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80032A7C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80032A80: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032A84: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032A88: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80032A8C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80032A90: lw          $v0, 0x7E94($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7E94);
    // 0x80032A94: j           L_80032AE8
    // 0x80032A98: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
        goto L_80032AE8;
    // 0x80032A98: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_80032A9C:
    // 0x80032A9C: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80032AA0: bnel        $v0, $zero, L_80032AC4
    if (ctx->r2 != 0) {
        // 0x80032AA4: sll         $v0, $v0, 1
        ctx->r2 = S32(ctx->r2 << 1);
            goto L_80032AC4;
    }
    goto skip_1;
    // 0x80032AA4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    skip_1:
    // 0x80032AA8: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80032AAC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80032AB0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80032AB4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80032AB8: lw          $v0, 0x7E94($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7E94);
    // 0x80032ABC: j           L_80032AE4
    // 0x80032AC0: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
        goto L_80032AE4;
    // 0x80032AC0: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
L_80032AC4:
    // 0x80032AC4: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x80032AC8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80032ACC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032AD0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032AD4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80032AD8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80032ADC: lw          $v0, 0x7E94($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7E94);
    // 0x80032AE0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
L_80032AE4:
    // 0x80032AE4: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_80032AE8:
    // 0x80032AE8: lui         $v0, 0x9249
    ctx->r2 = S32(0X9249 << 16);
    // 0x80032AEC: ori         $v0, $v0, 0x2493
    ctx->r2 = ctx->r2 | 0X2493;
    // 0x80032AF0: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80032AF4: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80032AF8: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x80032AFC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80032B00: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80032B04: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032B08: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032B0C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80032B10: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80032B14: lw          $v0, 0x7E98($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7E98);
    // 0x80032B18: mfhi        $a3
    ctx->r7 = hi;
    // 0x80032B1C: addu        $v1, $a3, $a0
    ctx->r3 = ADD32(ctx->r7, ctx->r4);
    // 0x80032B20: sra         $v1, $v1, 2
    ctx->r3 = S32(SIGNED(ctx->r3) >> 2);
    // 0x80032B24: sra         $a0, $a0, 31
    ctx->r4 = S32(SIGNED(ctx->r4) >> 31);
    // 0x80032B28: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80032B2C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032B30: beq         $s3, $zero, L_80032B44
    if (ctx->r19 == 0) {
        // 0x80032B34: sw          $v0, 0x18($s1)
        MEM_W(0X18, ctx->r17) = ctx->r2;
            goto L_80032B44;
    }
    // 0x80032B34: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // 0x80032B38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80032B3C: j           L_80032B48
    // 0x80032B40: sh          $v0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r2;
        goto L_80032B48;
    // 0x80032B40: sh          $v0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r2;
L_80032B44:
    // 0x80032B44: sh          $zero, 0x10($s1)
    MEM_H(0X10, ctx->r17) = 0;
L_80032B48:
    // 0x80032B48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80032B4C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80032B50: lb          $v0, 0x5($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X5);
    // 0x80032B54: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x80032B58: beq         $v0, $zero, L_80032B74
    if (ctx->r2 == 0) {
        // 0x80032B5C: swc1        $f0, 0x20($s1)
        MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
            goto L_80032B74;
    }
    // 0x80032B5C: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    // 0x80032B60: lui         $a2, 0x8030
    ctx->r6 = S32(0X8030 << 16);
    // 0x80032B64: lui         $v1, 0x8030
    ctx->r3 = S32(0X8030 << 16);
    // 0x80032B68: addiu       $v1, $v1, 0x700
    ctx->r3 = ADD32(ctx->r3, 0X700);
    // 0x80032B6C: j           L_80032B80
    // 0x80032B70: ori         $a2, $a2, 0x700
    ctx->r6 = ctx->r6 | 0X700;
        goto L_80032B80;
    // 0x80032B70: ori         $a2, $a2, 0x700
    ctx->r6 = ctx->r6 | 0X700;
L_80032B74:
    // 0x80032B74: lui         $a2, 0x8030
    ctx->r6 = S32(0X8030 << 16);
    // 0x80032B78: lui         $v1, 0x8030
    ctx->r3 = S32(0X8030 << 16);
    // 0x80032B7C: addiu       $v1, $v1, 0x0
    ctx->r3 = ADD32(ctx->r3, 0X0);
L_80032B80:
    // 0x80032B80: lbu         $a0, 0x6($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X6);
    // 0x80032B84: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x80032B88: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80032B8C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80032B90: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // 0x80032B94: lw          $a1, 0x7060($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7060);
    // 0x80032B98: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032B9C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032BA0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80032BA4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80032BA8: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80032BAC: lw          $a0, 0x70D0($at)
    ctx->r4 = MEM_W(ctx->r1, 0X70D0);
    // 0x80032BB0: lh          $v0, 0x8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X8);
    // 0x80032BB4: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x80032BB8: lbu         $a1, 0x2($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X2);
    // 0x80032BBC: addu        $s2, $v1, $a2
    ctx->r18 = ADD32(ctx->r3, ctx->r6);
    // 0x80032BC0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032BC4: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80032BC8: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80032BCC: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x80032BD0: lb          $a1, 0x0($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X0);
    // 0x80032BD4: addiu       $s0, $s1, 0xC
    ctx->r16 = ADD32(ctx->r17, 0XC);
    // 0x80032BD8: jal         0x80053234
    // 0x80032BDC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80053234(rdram, ctx);
        goto after_0;
    // 0x80032BDC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80032BE0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80032BE4: jal         0x80051C7C
    // 0x80032BE8: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    func_80051C7C(rdram, ctx);
        goto after_1;
    // 0x80032BE8: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    after_1:
    // 0x80032BEC: lh          $v0, 0x8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X8);
    // 0x80032BF0: lbu         $v1, 0x7($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X7);
    // 0x80032BF4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032BF8: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80032BFC: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x80032C00: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80032C04: beq         $v0, $zero, L_80032C14
    if (ctx->r2 == 0) {
        // 0x80032C08: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80032C14;
    }
    // 0x80032C08: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80032C0C: j           L_80032D48
    // 0x80032C10: sb          $v0, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r2;
        goto L_80032D48;
    // 0x80032C10: sb          $v0, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r2;
L_80032C14:
    // 0x80032C14: lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X8);
    // 0x80032C18: sb          $zero, 0x7($s1)
    MEM_B(0X7, ctx->r17) = 0;
    // 0x80032C1C: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // 0x80032C20: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x80032C24: sra         $v0, $v0, 14
    ctx->r2 = S32(SIGNED(ctx->r2) >> 14);
    // 0x80032C28: addu        $v1, $v0, $s2
    ctx->r3 = ADD32(ctx->r2, ctx->r18);
    // 0x80032C2C: sh          $a0, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r4;
    // 0x80032C30: lb          $v0, 0x1($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X1);
    // 0x80032C34: beq         $v0, $zero, L_80032D48
    if (ctx->r2 == 0) {
        // 0x80032C38: nop
    
            goto L_80032D48;
    }
    // 0x80032C38: nop

    // 0x80032C3C: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x80032C40: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80032C44: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80032C48: lb          $v0, 0x7F04($at)
    ctx->r2 = MEM_B(ctx->r1, 0X7F04);
    // 0x80032C4C: beq         $v0, $zero, L_80032CF0
    if (ctx->r2 == 0) {
        // 0x80032C50: nop
    
            goto L_80032CF0;
    }
    // 0x80032C50: nop

    // 0x80032C54: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80032C58: sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
    // 0x80032C5C: sb          $zero, 0x3($s1)
    MEM_B(0X3, ctx->r17) = 0;
    // 0x80032C60: sh          $zero, 0x8($s1)
    MEM_H(0X8, ctx->r17) = 0;
    // 0x80032C64: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80032C68: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80032C6C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80032C70: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80032C74: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032C78: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032C7C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032C80: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80032C84: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x80032C88: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032C8C: lbu         $v0, -0x7A6C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7A6C);
    // 0x80032C90: bne         $v0, $zero, L_80032CA4
    if (ctx->r2 != 0) {
        // 0x80032C94: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_80032CA4;
    }
    // 0x80032C94: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80032C98: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80032C9C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80032CA0: sb          $v0, -0x7A6D($at)
    MEM_B(-0X7A6D, ctx->r1) = ctx->r2;
L_80032CA4:
    // 0x80032CA4: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80032CA8: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80032CAC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80032CB0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80032CB4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80032CB8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032CBC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032CC0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032CC4: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x80032CC8: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x80032CCC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80032CD0: lbu         $v1, -0x7A6C($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X7A6C);
    // 0x80032CD4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80032CD8: bne         $v1, $v0, L_80032D48
    if (ctx->r3 != ctx->r2) {
        // 0x80032CDC: nop
    
            goto L_80032D48;
    }
    // 0x80032CDC: nop

    // 0x80032CE0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80032CE4: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80032CE8: j           L_80032D48
    // 0x80032CEC: sb          $zero, -0x7A6D($at)
    MEM_B(-0X7A6D, ctx->r1) = 0;
        goto L_80032D48;
    // 0x80032CEC: sb          $zero, -0x7A6D($at)
    MEM_B(-0X7A6D, ctx->r1) = 0;
L_80032CF0:
    // 0x80032CF0: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x80032CF4: lbu         $v1, 0x4($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X4);
    // 0x80032CF8: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80032CFC: bne         $v1, $zero, L_80032D48
    if (ctx->r3 != 0) {
        // 0x80032D00: sh          $v0, 0x8($s1)
        MEM_H(0X8, ctx->r17) = ctx->r2;
            goto L_80032D48;
    }
    // 0x80032D00: sh          $v0, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r2;
    // 0x80032D04: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80032D08: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80032D0C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80032D10: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80032D14: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80032D18: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032D1C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032D20: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032D24: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80032D28: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x80032D2C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032D30: lbu         $v0, -0x7A6C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7A6C);
    // 0x80032D34: bne         $v0, $zero, L_80032D48
    if (ctx->r2 != 0) {
        // 0x80032D38: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_80032D48;
    }
    // 0x80032D38: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80032D3C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80032D40: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80032D44: sb          $v0, -0x7A6D($at)
    MEM_B(-0X7A6D, ctx->r1) = ctx->r2;
L_80032D48:
    // 0x80032D48: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x80032D4C: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80032D50: xori        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 ^ 0X8;
    // 0x80032D54: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80032D58: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80032D5C: beq         $v1, $zero, L_80032E84
    if (ctx->r3 == 0) {
        // 0x80032D60: nop
    
            goto L_80032E84;
    }
    // 0x80032D60: nop

    // 0x80032D64: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80032D68: beq         $s3, $zero, L_80032D78
    if (ctx->r19 == 0) {
        // 0x80032D6C: addiu       $a0, $a0, 0x25A0
        ctx->r4 = ADD32(ctx->r4, 0X25A0);
            goto L_80032D78;
    }
    // 0x80032D6C: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    // 0x80032D70: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80032D74: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
L_80032D78:
    // 0x80032D78: jal         0x80016DC0
    // 0x80032D7C: nop

    func_80016DC0(rdram, ctx);
        goto after_2;
    // 0x80032D7C: nop

    after_2:
    // 0x80032D80: slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80032D84: beq         $v0, $zero, L_80032E24
    if (ctx->r2 == 0) {
        // 0x80032D88: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_80032E24;
    }
    // 0x80032D88: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80032D8C: lbu         $v1, 0x4($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X4);
    // 0x80032D90: beq         $v1, $v0, L_80032E84
    if (ctx->r3 == ctx->r2) {
        // 0x80032D94: nop
    
            goto L_80032E84;
    }
    // 0x80032D94: nop

    // 0x80032D98: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80032D9C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80032DA0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80032DA4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80032DA8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80032DAC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032DB0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032DB4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032DB8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032DBC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80032DC0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80032DC4: lbu         $v0, -0x7A6C($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X7A6C);
    // 0x80032DC8: bne         $v0, $zero, L_80032E84
    if (ctx->r2 != 0) {
        // 0x80032DCC: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_80032E84;
    }
    // 0x80032DCC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80032DD0: lbu         $a0, 0x5($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X5);
    // 0x80032DD4: sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
    // 0x80032DD8: sh          $zero, 0x8($s1)
    MEM_H(0X8, ctx->r17) = 0;
    // 0x80032DDC: sb          $zero, 0x7($s1)
    MEM_B(0X7, ctx->r17) = 0;
    // 0x80032DE0: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x80032DE4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80032DE8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80032DEC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80032DF0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032DF4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032DF8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032DFC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032E00: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80032E04: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80032E08: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80032E0C: sb          $v1, -0x7A6D($at)
    MEM_B(-0X7A6D, ctx->r1) = ctx->r3;
    // 0x80032E10: lbu         $v0, 0x3($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3);
    // 0x80032E14: beq         $v0, $zero, L_80032E7C
    if (ctx->r2 == 0) {
        // 0x80032E18: nop
    
            goto L_80032E7C;
    }
    // 0x80032E18: nop

    // 0x80032E1C: j           L_80032E84
    // 0x80032E20: nop

        goto L_80032E84;
    // 0x80032E20: nop

L_80032E24:
    // 0x80032E24: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x80032E28: beq         $v0, $zero, L_80032E84
    if (ctx->r2 == 0) {
        // 0x80032E2C: nop
    
            goto L_80032E84;
    }
    // 0x80032E2C: nop

    // 0x80032E30: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80032E34: sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
    // 0x80032E38: sh          $zero, 0x8($s1)
    MEM_H(0X8, ctx->r17) = 0;
    // 0x80032E3C: sb          $zero, 0x7($s1)
    MEM_B(0X7, ctx->r17) = 0;
    // 0x80032E40: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80032E44: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80032E48: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80032E4C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80032E50: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032E54: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032E58: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032E5C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032E60: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80032E64: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80032E68: sb          $zero, -0x7A6D($at)
    MEM_B(-0X7A6D, ctx->r1) = 0;
    // 0x80032E6C: lbu         $v1, 0x3($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X3);
    // 0x80032E70: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80032E74: bne         $v1, $v0, L_80032E84
    if (ctx->r3 != ctx->r2) {
        // 0x80032E78: nop
    
            goto L_80032E84;
    }
    // 0x80032E78: nop

L_80032E7C:
    // 0x80032E7C: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x80032E80: sb          $v0, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r2;
L_80032E84:
    // 0x80032E84: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80032E88: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80032E8C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80032E90: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80032E94: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80032E98: jr          $ra
    // 0x80032E9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80032E9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80032EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032EA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80032EA4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80032EA8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80032EAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80032EB0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80032EB4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80032EB8: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x80032EBC: beq         $v0, $zero, L_80033094
    if (ctx->r2 == 0) {
        // 0x80032EC0: addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
            goto L_80033094;
    }
    // 0x80032EC0: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x80032EC4: sb          $v0, 0x4($s2)
    MEM_B(0X4, ctx->r18) = ctx->r2;
    // 0x80032EC8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80032ECC: lbu         $v0, 0x447E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X447E);
    // 0x80032ED0: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x80032ED4: beql        $v0, $v1, L_80032EF4
    if (ctx->r2 == ctx->r3) {
        // 0x80032ED8: sb          $zero, 0x5($s2)
        MEM_B(0X5, ctx->r18) = 0;
            goto L_80032EF4;
    }
    goto skip_0;
    // 0x80032ED8: sb          $zero, 0x5($s2)
    MEM_B(0X5, ctx->r18) = 0;
    skip_0:
    // 0x80032EDC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80032EE0: lbu         $v0, 0x44B2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X44B2);
    // 0x80032EE4: bnel        $v0, $v1, L_80032EF4
    if (ctx->r2 != ctx->r3) {
        // 0x80032EE8: sb          $zero, 0x5($s2)
        MEM_B(0X5, ctx->r18) = 0;
            goto L_80032EF4;
    }
    goto skip_1;
    // 0x80032EE8: sb          $zero, 0x5($s2)
    MEM_B(0X5, ctx->r18) = 0;
    skip_1:
    // 0x80032EEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80032EF0: sb          $v0, 0x5($s2)
    MEM_B(0X5, ctx->r18) = ctx->r2;
L_80032EF4:
    // 0x80032EF4: lbu         $v1, 0x5($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X5);
    // 0x80032EF8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80032EFC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032F00: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032F04: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032F08: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x80032F0C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80032F10: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80032F14: lbu         $v1, 0x447C($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X447C);
    // 0x80032F18: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80032F1C: bnel        $v1, $v0, L_80033090
    if (ctx->r3 != ctx->r2) {
        // 0x80032F20: sh          $zero, 0x8($s2)
        MEM_H(0X8, ctx->r18) = 0;
            goto L_80033090;
    }
    goto skip_2;
    // 0x80032F20: sh          $zero, 0x8($s2)
    MEM_H(0X8, ctx->r18) = 0;
    skip_2:
    // 0x80032F24: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80032F28: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80032F2C: lbu         $v1, 0x447E($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X447E);
    // 0x80032F30: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80032F34: bnel        $v1, $v0, L_80033090
    if (ctx->r3 != ctx->r2) {
        // 0x80032F38: sh          $zero, 0x8($s2)
        MEM_H(0X8, ctx->r18) = 0;
            goto L_80033090;
    }
    goto skip_3;
    // 0x80032F38: sh          $zero, 0x8($s2)
    MEM_H(0X8, ctx->r18) = 0;
    skip_3:
    // 0x80032F3C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80032F40: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80032F44: lh          $v0, 0x4480($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X4480);
    // 0x80032F48: slti        $v0, $v0, 0x8
    ctx->r2 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80032F4C: bnel        $v0, $zero, L_80033090
    if (ctx->r2 != 0) {
        // 0x80032F50: sh          $zero, 0x8($s2)
        MEM_H(0X8, ctx->r18) = 0;
            goto L_80033090;
    }
    goto skip_4;
    // 0x80032F50: sh          $zero, 0x8($s2)
    MEM_H(0X8, ctx->r18) = 0;
    skip_4:
    // 0x80032F54: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80032F58: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80032F5C: lw          $v0, 0x448C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X448C);
    // 0x80032F60: lbu         $v1, 0x5($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X5);
    // 0x80032F64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80032F68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80032F6C: sw          $v0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r2;
    // 0x80032F70: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80032F74: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032F78: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032F7C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80032F80: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032F84: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80032F88: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80032F8C: lw          $v0, 0x4490($at)
    ctx->r2 = MEM_W(ctx->r1, 0X4490);
    // 0x80032F90: lb          $v1, 0x5($s2)
    ctx->r3 = MEM_B(ctx->r18, 0X5);
    // 0x80032F94: swc1        $f0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f0.u32l;
    // 0x80032F98: swc1        $f0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f0.u32l;
    // 0x80032F9C: beq         $v1, $zero, L_80032FB8
    if (ctx->r3 == 0) {
        // 0x80032FA0: sw          $v0, 0x18($s2)
        MEM_W(0X18, ctx->r18) = ctx->r2;
            goto L_80032FB8;
    }
    // 0x80032FA0: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // 0x80032FA4: lui         $a2, 0x8030
    ctx->r6 = S32(0X8030 << 16);
    // 0x80032FA8: lui         $a1, 0x8030
    ctx->r5 = S32(0X8030 << 16);
    // 0x80032FAC: addiu       $a1, $a1, 0x700
    ctx->r5 = ADD32(ctx->r5, 0X700);
    // 0x80032FB0: j           L_80032FC4
    // 0x80032FB4: ori         $a2, $a2, 0x700
    ctx->r6 = ctx->r6 | 0X700;
        goto L_80032FC4;
    // 0x80032FB4: ori         $a2, $a2, 0x700
    ctx->r6 = ctx->r6 | 0X700;
L_80032FB8:
    // 0x80032FB8: lui         $a2, 0x8030
    ctx->r6 = S32(0X8030 << 16);
    // 0x80032FBC: lui         $a1, 0x8030
    ctx->r5 = S32(0X8030 << 16);
    // 0x80032FC0: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
L_80032FC4:
    // 0x80032FC4: lbu         $v1, 0x6($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X6);
    // 0x80032FC8: lbu         $v0, 0x4($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X4);
    // 0x80032FCC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80032FD0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80032FD4: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80032FD8: lw          $a0, 0x7060($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7060);
    // 0x80032FDC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80032FE0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80032FE4: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x80032FE8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80032FEC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80032FF0: lw          $v1, 0x70D0($at)
    ctx->r3 = MEM_W(ctx->r1, 0X70D0);
    // 0x80032FF4: lh          $v0, 0x8($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X8);
    // 0x80032FF8: subu        $s0, $s0, $a0
    ctx->r16 = SUB32(ctx->r16, ctx->r4);
    // 0x80032FFC: lbu         $a0, 0x2($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X2);
    // 0x80033000: addu        $s0, $s0, $a2
    ctx->r16 = ADD32(ctx->r16, ctx->r6);
    // 0x80033004: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80033008: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8003300C: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80033010: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80033014: lb          $a1, 0x0($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X0);
    // 0x80033018: addiu       $s1, $s2, 0xC
    ctx->r17 = ADD32(ctx->r18, 0XC);
    // 0x8003301C: jal         0x80053234
    // 0x80033020: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80053234(rdram, ctx);
        goto after_0;
    // 0x80033020: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x80033024: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80033028: jal         0x80051C7C
    // 0x8003302C: sw          $zero, 0x24($s2)
    MEM_W(0X24, ctx->r18) = 0;
    func_80051C7C(rdram, ctx);
        goto after_1;
    // 0x8003302C: sw          $zero, 0x24($s2)
    MEM_W(0X24, ctx->r18) = 0;
    after_1:
    // 0x80033030: lh          $v0, 0x8($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X8);
    // 0x80033034: lbu         $v1, 0x7($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X7);
    // 0x80033038: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003303C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80033040: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x80033044: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80033048: beq         $v0, $zero, L_80033058
    if (ctx->r2 == 0) {
        // 0x8003304C: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80033058;
    }
    // 0x8003304C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80033050: j           L_80033094
    // 0x80033054: sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
        goto L_80033094;
    // 0x80033054: sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
L_80033058:
    // 0x80033058: lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X8);
    // 0x8003305C: sb          $zero, 0x7($s2)
    MEM_B(0X7, ctx->r18) = 0;
    // 0x80033060: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80033064: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80033068: sra         $v0, $v0, 14
    ctx->r2 = S32(SIGNED(ctx->r2) >> 14);
    // 0x8003306C: addu        $s0, $v0, $s0
    ctx->r16 = ADD32(ctx->r2, ctx->r16);
    // 0x80033070: sh          $v1, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r3;
    // 0x80033074: lb          $v0, 0x1($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1);
    // 0x80033078: beq         $v0, $zero, L_80033094
    if (ctx->r2 == 0) {
        // 0x8003307C: nop
    
            goto L_80033094;
    }
    // 0x8003307C: nop

    // 0x80033080: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x80033084: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80033088: j           L_80033094
    // 0x8003308C: sh          $v0, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r2;
        goto L_80033094;
    // 0x8003308C: sh          $v0, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r2;
L_80033090:
    // 0x80033090: sb          $zero, 0x7($s2)
    MEM_B(0X7, ctx->r18) = 0;
L_80033094:
    // 0x80033094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80033098: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003309C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800330A0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800330A4: jr          $ra
    // 0x800330A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800330A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800330AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800330AC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800330B0: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x800330B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800330B8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800330BC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800330C0: beq         $v0, $zero, L_80033128
    if (ctx->r2 == 0) {
        // 0x800330C4: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_80033128;
    }
    // 0x800330C4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800330C8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800330CC: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x800330D0: beq         $v0, $zero, L_80033128
    if (ctx->r2 == 0) {
        // 0x800330D4: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80033128;
    }
    // 0x800330D4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800330D8: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x800330DC: addiu       $s1, $s1, 0x4478
    ctx->r17 = ADD32(ctx->r17, 0X4478);
    // 0x800330E0: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x800330E4: addiu       $s0, $s0, 0x7B8B
    ctx->r16 = ADD32(ctx->r16, 0X7B8B);
    // 0x800330E8: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x800330EC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800330F0: jal         0x80031E30
    // 0x800330F4: srl         $a1, $a1, 4
    ctx->r5 = S32(U32(ctx->r5) >> 4);
    func_80031E30(rdram, ctx);
        goto after_0;
    // 0x800330F4: srl         $a1, $a1, 4
    ctx->r5 = S32(U32(ctx->r5) >> 4);
    after_0:
    // 0x800330F8: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x800330FC: addiu       $a0, $s1, 0x34
    ctx->r4 = ADD32(ctx->r17, 0X34);
    // 0x80033100: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80033104: jal         0x80031E30
    // 0x80033108: andi        $a1, $a1, 0x3
    ctx->r5 = ctx->r5 & 0X3;
    func_80031E30(rdram, ctx);
        goto after_1;
    // 0x80033108: andi        $a1, $a1, 0x3
    ctx->r5 = ctx->r5 & 0X3;
    after_1:
    // 0x8003310C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80033110: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x80033114: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033118: sb          $v0, 0x447A($at)
    MEM_B(0X447A, ctx->r1) = ctx->r2;
    // 0x8003311C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033120: j           L_80033254
    // 0x80033124: sb          $v0, 0x44AE($at)
    MEM_B(0X44AE, ctx->r1) = ctx->r2;
        goto L_80033254;
    // 0x80033124: sb          $v0, 0x44AE($at)
    MEM_B(0X44AE, ctx->r1) = ctx->r2;
L_80033128:
    // 0x80033128: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8003312C: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x80033130: beq         $v0, $zero, L_800331C8
    if (ctx->r2 == 0) {
        // 0x80033134: nop
    
            goto L_800331C8;
    }
    // 0x80033134: nop

    // 0x80033138: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8003313C: lbu         $a1, 0x7B8B($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X7B8B);
    // 0x80033140: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x80033144: addiu       $s1, $s1, 0x4478
    ctx->r17 = ADD32(ctx->r17, 0X4478);
    // 0x80033148: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8003314C: srl         $a1, $a1, 4
    ctx->r5 = S32(U32(ctx->r5) >> 4);
    // 0x80033150: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80033154: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80033158: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8003315C: lw          $s0, 0x7E64($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X7E64);
    // 0x80033160: jal         0x80031E30
    // 0x80033164: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80031E30(rdram, ctx);
        goto after_2;
    // 0x80033164: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_2:
    // 0x80033168: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8003316C: lbu         $v0, 0x7B85($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B85);
    // 0x80033170: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80033174: lb          $v1, 0x25FA($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X25FA);
    // 0x80033178: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8003317C: addu        $a0, $v0, $s0
    ctx->r4 = ADD32(ctx->r2, ctx->r16);
    // 0x80033180: lbu         $v0, -0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X1);
    // 0x80033184: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033188: sb          $v0, 0x447A($at)
    MEM_B(0X447A, ctx->r1) = ctx->r2;
    // 0x8003318C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80033190: beq         $v1, $v0, L_80033254
    if (ctx->r3 == ctx->r2) {
        // 0x80033194: nop
    
            goto L_80033254;
    }
    // 0x80033194: nop

    // 0x80033198: lb          $a1, -0x2($a0)
    ctx->r5 = MEM_B(ctx->r4, -0X2);
    // 0x8003319C: addiu       $a0, $s1, 0x34
    ctx->r4 = ADD32(ctx->r17, 0X34);
    // 0x800331A0: jal         0x80031E30
    // 0x800331A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80031E30(rdram, ctx);
        goto after_3;
    // 0x800331A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800331A8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800331AC: lbu         $v0, 0x7B85($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B85);
    // 0x800331B0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800331B4: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800331B8: lbu         $v0, -0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1);
    // 0x800331BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800331C0: j           L_80033254
    // 0x800331C4: sb          $v0, 0x44AE($at)
    MEM_B(0X44AE, ctx->r1) = ctx->r2;
        goto L_80033254;
    // 0x800331C4: sb          $v0, 0x44AE($at)
    MEM_B(0X44AE, ctx->r1) = ctx->r2;
L_800331C8:
    // 0x800331C8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800331CC: lbu         $a1, 0x7B8B($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X7B8B);
    // 0x800331D0: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x800331D4: addiu       $s1, $s1, 0x44AC
    ctx->r17 = ADD32(ctx->r17, 0X44AC);
    // 0x800331D8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800331DC: andi        $a1, $a1, 0x3
    ctx->r5 = ctx->r5 & 0X3;
    // 0x800331E0: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800331E4: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x800331E8: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800331EC: lw          $s0, 0x7E64($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X7E64);
    // 0x800331F0: jal         0x80031E30
    // 0x800331F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80031E30(rdram, ctx);
        goto after_4;
    // 0x800331F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x800331F8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800331FC: lbu         $v0, 0x7B85($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B85);
    // 0x80033200: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80033204: lb          $v1, 0x7A4A($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X7A4A);
    // 0x80033208: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8003320C: addu        $a0, $v0, $s0
    ctx->r4 = ADD32(ctx->r2, ctx->r16);
    // 0x80033210: lbu         $v0, -0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X1);
    // 0x80033214: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033218: sb          $v0, 0x44AE($at)
    MEM_B(0X44AE, ctx->r1) = ctx->r2;
    // 0x8003321C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80033220: beq         $v1, $v0, L_80033254
    if (ctx->r3 == ctx->r2) {
        // 0x80033224: nop
    
            goto L_80033254;
    }
    // 0x80033224: nop

    // 0x80033228: lb          $a1, -0x2($a0)
    ctx->r5 = MEM_B(ctx->r4, -0X2);
    // 0x8003322C: addiu       $a0, $s1, -0x34
    ctx->r4 = ADD32(ctx->r17, -0X34);
    // 0x80033230: jal         0x80031E30
    // 0x80033234: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80031E30(rdram, ctx);
        goto after_5;
    // 0x80033234: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_5:
    // 0x80033238: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8003323C: lbu         $v0, 0x7B85($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B85);
    // 0x80033240: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80033244: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80033248: lbu         $v0, -0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1);
    // 0x8003324C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033250: sb          $v0, 0x447A($at)
    MEM_B(0X447A, ctx->r1) = ctx->r2;
L_80033254:
    // 0x80033254: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80033258: lbu         $v0, 0x4478($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4478);
    // 0x8003325C: beq         $v0, $zero, L_8003329C
    if (ctx->r2 == 0) {
        // 0x80033260: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8003329C;
    }
    // 0x80033260: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80033264: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80033268: lbu         $v0, 0x447A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X447A);
    // 0x8003326C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80033270: lbu         $v1, 0x447E($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X447E);
    // 0x80033274: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80033278: addiu       $a1, $a1, -0x3250
    ctx->r5 = ADD32(ctx->r5, -0X3250);
    // 0x8003327C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80033280: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80033284: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80033288: lw          $a0, -0x6368($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6368);
    // 0x8003328C: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80033290: addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
    // 0x80033294: jal         0x8005334C
    // 0x80033298: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    func_8005334C(rdram, ctx);
        goto after_6;
    // 0x80033298: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    after_6:
L_8003329C:
    // 0x8003329C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800332A0: lbu         $v0, 0x44AC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X44AC);
    // 0x800332A4: beq         $v0, $zero, L_800332E4
    if (ctx->r2 == 0) {
        // 0x800332A8: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_800332E4;
    }
    // 0x800332A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800332AC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800332B0: lbu         $v0, 0x44AE($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X44AE);
    // 0x800332B4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800332B8: lbu         $v1, 0x44B2($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X44B2);
    // 0x800332BC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800332C0: addiu       $a1, $a1, -0x3250
    ctx->r5 = ADD32(ctx->r5, -0X3250);
    // 0x800332C4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800332C8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800332CC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800332D0: lw          $a0, -0x6368($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6368);
    // 0x800332D4: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800332D8: addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
    // 0x800332DC: jal         0x8005334C
    // 0x800332E0: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    func_8005334C(rdram, ctx);
        goto after_7;
    // 0x800332E0: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    after_7:
L_800332E4:
    // 0x800332E4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x800332E8: addiu       $a0, $a0, -0x4CEC
    ctx->r4 = ADD32(ctx->r4, -0X4CEC);
    // 0x800332EC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800332F0: addiu       $a1, $a1, -0x3170
    ctx->r5 = ADD32(ctx->r5, -0X3170);
    // 0x800332F4: jal         0x8005334C
    // 0x800332F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8005334C(rdram, ctx);
        goto after_8;
    // 0x800332F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x800332FC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80033300: addiu       $a0, $a0, -0x4CCC
    ctx->r4 = ADD32(ctx->r4, -0X4CCC);
    // 0x80033304: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80033308: addiu       $a1, $a1, -0x3130
    ctx->r5 = ADD32(ctx->r5, -0X3130);
    // 0x8003330C: jal         0x8005334C
    // 0x80033310: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8005334C(rdram, ctx);
        goto after_9;
    // 0x80033310: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80033314: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80033318: addiu       $a0, $a0, -0x63C8
    ctx->r4 = ADD32(ctx->r4, -0X63C8);
    // 0x8003331C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80033320: addiu       $a1, $a1, -0x3150
    ctx->r5 = ADD32(ctx->r5, -0X3150);
    // 0x80033324: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033328: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003332C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80033330: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033334: sb          $v0, 0x44E0($at)
    MEM_B(0X44E0, ctx->r1) = ctx->r2;
    // 0x80033338: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8003333C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033340: sb          $v0, 0x44E2($at)
    MEM_B(0X44E2, ctx->r1) = ctx->r2;
    // 0x80033344: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x80033348: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8003334C: sb          $v0, 0x44E3($at)
    MEM_B(0X44E3, ctx->r1) = ctx->r2;
    // 0x80033350: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80033354: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033358: sb          $zero, 0x44E1($at)
    MEM_B(0X44E1, ctx->r1) = 0;
    // 0x8003335C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033360: sb          $zero, 0x44E4($at)
    MEM_B(0X44E4, ctx->r1) = 0;
    // 0x80033364: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033368: sb          $zero, 0x44E5($at)
    MEM_B(0X44E5, ctx->r1) = 0;
    // 0x8003336C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033370: sb          $v0, 0x44E6($at)
    MEM_B(0X44E6, ctx->r1) = ctx->r2;
    // 0x80033374: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033378: sh          $zero, 0x44E8($at)
    MEM_H(0X44E8, ctx->r1) = 0;
    // 0x8003337C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033380: sb          $zero, 0x44E7($at)
    MEM_B(0X44E7, ctx->r1) = 0;
    // 0x80033384: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033388: sw          $zero, 0x44F8($at)
    MEM_W(0X44F8, ctx->r1) = 0;
    // 0x8003338C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033390: sw          $zero, 0x44F4($at)
    MEM_W(0X44F4, ctx->r1) = 0;
    // 0x80033394: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033398: sh          $zero, 0x44F2($at)
    MEM_H(0X44F2, ctx->r1) = 0;
    // 0x8003339C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800333A0: sh          $zero, 0x44F0($at)
    MEM_H(0X44F0, ctx->r1) = 0;
    // 0x800333A4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800333A8: sw          $zero, 0x4510($at)
    MEM_W(0X4510, ctx->r1) = 0;
    // 0x800333AC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800333B0: sw          $zero, 0x450C($at)
    MEM_W(0X450C, ctx->r1) = 0;
    // 0x800333B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800333B8: sw          $zero, 0x4504($at)
    MEM_W(0X4504, ctx->r1) = 0;
    // 0x800333BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800333C0: swc1        $f0, 0x4500($at)
    MEM_W(0X4500, ctx->r1) = ctx->f0.u32l;
    // 0x800333C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800333C8: swc1        $f0, 0x44FC($at)
    MEM_W(0X44FC, ctx->r1) = ctx->f0.u32l;
    // 0x800333CC: jal         0x8005334C
    // 0x800333D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8005334C(rdram, ctx);
        goto after_10;
    // 0x800333D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x800333D4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800333D8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800333DC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800333E0: jr          $ra
    // 0x800333E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800333E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800333E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800333E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800333EC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800333F0: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x800333F4: addiu       $s0, $s0, -0x7A70
    ctx->r16 = ADD32(ctx->r16, -0X7A70);
    // 0x800333F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800333FC: jal         0x8003228C
    // 0x80033400: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003228C(rdram, ctx);
        goto after_0;
    // 0x80033400: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80033404: jal         0x8003228C
    // 0x80033408: addiu       $a0, $s0, 0x9C
    ctx->r4 = ADD32(ctx->r16, 0X9C);
    func_8003228C(rdram, ctx);
        goto after_1;
    // 0x80033408: addiu       $a0, $s0, 0x9C
    ctx->r4 = ADD32(ctx->r16, 0X9C);
    after_1:
    // 0x8003340C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80033410: addiu       $a0, $a0, 0x447E
    ctx->r4 = ADD32(ctx->r4, 0X447E);
    // 0x80033414: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80033418: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8003341C: beq         $v0, $v1, L_80033434
    if (ctx->r2 == ctx->r3) {
        // 0x80033420: nop
    
            goto L_80033434;
    }
    // 0x80033420: nop

    // 0x80033424: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80033428: lbu         $v0, 0x44B2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X44B2);
    // 0x8003342C: bne         $v0, $v1, L_80033460
    if (ctx->r2 != ctx->r3) {
        // 0x80033430: nop
    
            goto L_80033460;
    }
    // 0x80033430: nop

L_80033434:
    // 0x80033434: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80033438: lbu         $v0, 0x447C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X447C);
    // 0x8003343C: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x80033440: beq         $v0, $v1, L_80033458
    if (ctx->r2 == ctx->r3) {
        // 0x80033444: nop
    
            goto L_80033458;
    }
    // 0x80033444: nop

    // 0x80033448: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8003344C: lbu         $v0, 0x44B0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X44B0);
    // 0x80033450: bne         $v0, $v1, L_80033460
    if (ctx->r2 != ctx->r3) {
        // 0x80033454: nop
    
            goto L_80033460;
    }
    // 0x80033454: nop

L_80033458:
    // 0x80033458: jal         0x80032EA0
    // 0x8003345C: addiu       $a0, $a0, 0x62
    ctx->r4 = ADD32(ctx->r4, 0X62);
    func_80032EA0(rdram, ctx);
        goto after_2;
    // 0x8003345C: addiu       $a0, $a0, 0x62
    ctx->r4 = ADD32(ctx->r4, 0X62);
    after_2:
L_80033460:
    // 0x80033460: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80033464: addiu       $s0, $s0, 0x447C
    ctx->r16 = ADD32(ctx->r16, 0X447C);
    // 0x80033468: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x8003346C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80033470: lbu         $a1, 0x44B0($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X44B0);
    // 0x80033474: sltu        $v0, $a1, $a0
    ctx->r2 = ctx->r5 < ctx->r4 ? 1 : 0;
    // 0x80033478: beq         $v0, $zero, L_80033510
    if (ctx->r2 == 0) {
        // 0x8003347C: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_80033510;
    }
    // 0x8003347C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80033480: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80033484: lbu         $v1, 0x447E($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X447E);
    // 0x80033488: bne         $v1, $v0, L_800334B4
    if (ctx->r3 != ctx->r2) {
        // 0x8003348C: xori        $v1, $a0, 0x9
        ctx->r3 = ctx->r4 ^ 0X9;
            goto L_800334B4;
    }
    // 0x8003348C: xori        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 ^ 0X9;
    // 0x80033490: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80033494: xori        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 ^ 0X3;
    // 0x80033498: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8003349C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800334A0: beq         $v1, $zero, L_800334B4
    if (ctx->r3 == 0) {
        // 0x800334A4: nop
    
            goto L_800334B4;
    }
    // 0x800334A4: nop

    // 0x800334A8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x800334AC: jal         0x8003228C
    // 0x800334B0: addiu       $a0, $a0, -0x7A3C
    ctx->r4 = ADD32(ctx->r4, -0X7A3C);
    func_8003228C(rdram, ctx);
        goto after_3;
    // 0x800334B0: addiu       $a0, $a0, -0x7A3C
    ctx->r4 = ADD32(ctx->r4, -0X7A3C);
    after_3:
L_800334B4:
    // 0x800334B4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800334B8: jal         0x800326F0
    // 0x800334BC: addiu       $a0, $a0, 0x4478
    ctx->r4 = ADD32(ctx->r4, 0X4478);
    func_800326F0(rdram, ctx);
        goto after_4;
    // 0x800334BC: addiu       $a0, $a0, 0x4478
    ctx->r4 = ADD32(ctx->r4, 0X4478);
    after_4:
    // 0x800334C0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800334C4: lbu         $v1, 0x44B2($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X44B2);
    // 0x800334C8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800334CC: bne         $v1, $v0, L_80033504
    if (ctx->r3 != ctx->r2) {
        // 0x800334D0: nop
    
            goto L_80033504;
    }
    // 0x800334D0: nop

    // 0x800334D4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800334D8: lbu         $v0, 0x44B0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X44B0);
    // 0x800334DC: xori        $v1, $v0, 0x9
    ctx->r3 = ctx->r2 ^ 0X9;
    // 0x800334E0: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x800334E4: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x800334E8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800334EC: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800334F0: beq         $v1, $zero, L_80033504
    if (ctx->r3 == 0) {
        // 0x800334F4: nop
    
            goto L_80033504;
    }
    // 0x800334F4: nop

    // 0x800334F8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x800334FC: jal         0x8003228C
    // 0x80033500: addiu       $a0, $a0, -0x79A0
    ctx->r4 = ADD32(ctx->r4, -0X79A0);
    func_8003228C(rdram, ctx);
        goto after_5;
    // 0x80033500: addiu       $a0, $a0, -0x79A0
    ctx->r4 = ADD32(ctx->r4, -0X79A0);
    after_5:
L_80033504:
    // 0x80033504: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80033508: j           L_8003372C
    // 0x8003350C: addiu       $a0, $a0, 0x44AC
    ctx->r4 = ADD32(ctx->r4, 0X44AC);
        goto L_8003372C;
    // 0x8003350C: addiu       $a0, $a0, 0x44AC
    ctx->r4 = ADD32(ctx->r4, 0X44AC);
L_80033510:
    // 0x80033510: sltu        $v0, $a0, $a1
    ctx->r2 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x80033514: beq         $v0, $zero, L_80033538
    if (ctx->r2 == 0) {
        // 0x80033518: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_80033538;
    }
    // 0x80033518: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8003351C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80033520: lbu         $v1, 0x44B2($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X44B2);
    // 0x80033524: bne         $v1, $v0, L_800336D4
    if (ctx->r3 != ctx->r2) {
        // 0x80033528: xori        $v1, $a1, 0x9
        ctx->r3 = ctx->r5 ^ 0X9;
            goto L_800336D4;
    }
    // 0x80033528: xori        $v1, $a1, 0x9
    ctx->r3 = ctx->r5 ^ 0X9;
    // 0x8003352C: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80033530: j           L_800336B8
    // 0x80033534: xori        $v0, $a1, 0x3
    ctx->r2 = ctx->r5 ^ 0X3;
        goto L_800336B8;
    // 0x80033534: xori        $v0, $a1, 0x3
    ctx->r2 = ctx->r5 ^ 0X3;
L_80033538:
    // 0x80033538: bne         $a0, $zero, L_800335D4
    if (ctx->r4 != 0) {
        // 0x8003353C: nop
    
            goto L_800335D4;
    }
    // 0x8003353C: nop

    // 0x80033540: bne         $a1, $zero, L_800335D4
    if (ctx->r5 != 0) {
        // 0x80033544: addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
            goto L_800335D4;
    }
    // 0x80033544: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80033548: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8003354C: lbu         $v1, 0x447E($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X447E);
    // 0x80033550: bne         $v1, $a0, L_80033574
    if (ctx->r3 != ctx->r4) {
        // 0x80033554: nop
    
            goto L_80033574;
    }
    // 0x80033554: nop

    // 0x80033558: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x8003355C: jal         0x8003228C
    // 0x80033560: addiu       $a0, $a0, -0x7A3C
    ctx->r4 = ADD32(ctx->r4, -0X7A3C);
    func_8003228C(rdram, ctx);
        goto after_6;
    // 0x80033560: addiu       $a0, $a0, -0x7A3C
    ctx->r4 = ADD32(ctx->r4, -0X7A3C);
    after_6:
    // 0x80033564: jal         0x800326F0
    // 0x80033568: addiu       $a0, $s0, -0x4
    ctx->r4 = ADD32(ctx->r16, -0X4);
    func_800326F0(rdram, ctx);
        goto after_7;
    // 0x80033568: addiu       $a0, $s0, -0x4
    ctx->r4 = ADD32(ctx->r16, -0X4);
    after_7:
    // 0x8003356C: j           L_8003372C
    // 0x80033570: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
        goto L_8003372C;
    // 0x80033570: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
L_80033574:
    // 0x80033574: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80033578: lbu         $v0, 0x44B2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X44B2);
    // 0x8003357C: bne         $v0, $a0, L_800335A0
    if (ctx->r2 != ctx->r4) {
        // 0x80033580: nop
    
            goto L_800335A0;
    }
    // 0x80033580: nop

    // 0x80033584: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x80033588: jal         0x8003228C
    // 0x8003358C: addiu       $a0, $a0, -0x79A0
    ctx->r4 = ADD32(ctx->r4, -0X79A0);
    func_8003228C(rdram, ctx);
        goto after_8;
    // 0x8003358C: addiu       $a0, $a0, -0x79A0
    ctx->r4 = ADD32(ctx->r4, -0X79A0);
    after_8:
L_80033590:
    // 0x80033590: jal         0x800326F0
    // 0x80033594: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    func_800326F0(rdram, ctx);
        goto after_9;
    // 0x80033594: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    after_9:
    // 0x80033598: j           L_80033724
    // 0x8003359C: nop

        goto L_80033724;
    // 0x8003359C: nop

L_800335A0:
    // 0x800335A0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800335A4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800335A8: lb          $v1, 0x7F1C($at)
    ctx->r3 = MEM_B(ctx->r1, 0X7F1C);
    // 0x800335AC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800335B0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800335B4: lb          $v0, 0x7F1C($at)
    ctx->r2 = MEM_B(ctx->r1, 0X7F1C);
    // 0x800335B8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800335BC: beq         $v0, $zero, L_80033590
    if (ctx->r2 == 0) {
        // 0x800335C0: nop
    
            goto L_80033590;
    }
    // 0x800335C0: nop

    // 0x800335C4: jal         0x800326F0
    // 0x800335C8: addiu       $a0, $s0, -0x4
    ctx->r4 = ADD32(ctx->r16, -0X4);
    func_800326F0(rdram, ctx);
        goto after_10;
    // 0x800335C8: addiu       $a0, $s0, -0x4
    ctx->r4 = ADD32(ctx->r16, -0X4);
    after_10:
    // 0x800335CC: j           L_8003372C
    // 0x800335D0: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
        goto L_8003372C;
    // 0x800335D0: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
L_800335D4:
    // 0x800335D4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800335D8: lbu         $a1, 0x447E($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X447E);
    // 0x800335DC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800335E0: lbu         $a0, 0x44B2($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X44B2);
    // 0x800335E4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800335E8: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800335EC: lb          $v1, 0x7F1C($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X7F1C);
    // 0x800335F0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800335F4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800335F8: lb          $v0, 0x7F1C($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7F1C);
    // 0x800335FC: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80033600: beq         $v0, $zero, L_8003369C
    if (ctx->r2 == 0) {
        // 0x80033604: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_8003369C;
    }
    // 0x80033604: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80033608: bne         $a1, $v0, L_80033640
    if (ctx->r5 != ctx->r2) {
        // 0x8003360C: nop
    
            goto L_80033640;
    }
    // 0x8003360C: nop

    // 0x80033610: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80033614: lbu         $v0, 0x447C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X447C);
    // 0x80033618: xori        $v1, $v0, 0x9
    ctx->r3 = ctx->r2 ^ 0X9;
    // 0x8003361C: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80033620: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x80033624: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80033628: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8003362C: beq         $v1, $zero, L_80033640
    if (ctx->r3 == 0) {
        // 0x80033630: nop
    
            goto L_80033640;
    }
    // 0x80033630: nop

    // 0x80033634: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x80033638: jal         0x8003228C
    // 0x8003363C: addiu       $a0, $a0, -0x7A3C
    ctx->r4 = ADD32(ctx->r4, -0X7A3C);
    func_8003228C(rdram, ctx);
        goto after_11;
    // 0x8003363C: addiu       $a0, $a0, -0x7A3C
    ctx->r4 = ADD32(ctx->r4, -0X7A3C);
    after_11:
L_80033640:
    // 0x80033640: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80033644: jal         0x800326F0
    // 0x80033648: addiu       $a0, $a0, 0x4478
    ctx->r4 = ADD32(ctx->r4, 0X4478);
    func_800326F0(rdram, ctx);
        goto after_12;
    // 0x80033648: addiu       $a0, $a0, 0x4478
    ctx->r4 = ADD32(ctx->r4, 0X4478);
    after_12:
    // 0x8003364C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80033650: lbu         $v1, 0x44B2($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X44B2);
    // 0x80033654: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80033658: bne         $v1, $v0, L_80033690
    if (ctx->r3 != ctx->r2) {
        // 0x8003365C: nop
    
            goto L_80033690;
    }
    // 0x8003365C: nop

    // 0x80033660: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80033664: lbu         $v0, 0x44B0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X44B0);
    // 0x80033668: xori        $v1, $v0, 0x9
    ctx->r3 = ctx->r2 ^ 0X9;
    // 0x8003366C: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80033670: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x80033674: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80033678: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8003367C: beq         $v1, $zero, L_80033690
    if (ctx->r3 == 0) {
        // 0x80033680: nop
    
            goto L_80033690;
    }
    // 0x80033680: nop

    // 0x80033684: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x80033688: jal         0x8003228C
    // 0x8003368C: addiu       $a0, $a0, -0x79A0
    ctx->r4 = ADD32(ctx->r4, -0X79A0);
    func_8003228C(rdram, ctx);
        goto after_13;
    // 0x8003368C: addiu       $a0, $a0, -0x79A0
    ctx->r4 = ADD32(ctx->r4, -0X79A0);
    after_13:
L_80033690:
    // 0x80033690: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80033694: j           L_8003372C
    // 0x80033698: addiu       $a0, $a0, 0x44AC
    ctx->r4 = ADD32(ctx->r4, 0X44AC);
        goto L_8003372C;
    // 0x80033698: addiu       $a0, $a0, 0x44AC
    ctx->r4 = ADD32(ctx->r4, 0X44AC);
L_8003369C:
    // 0x8003369C: bne         $a0, $v0, L_800336D4
    if (ctx->r4 != ctx->r2) {
        // 0x800336A0: nop
    
            goto L_800336D4;
    }
    // 0x800336A0: nop

    // 0x800336A4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800336A8: lbu         $v0, 0x44B0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X44B0);
    // 0x800336AC: xori        $v1, $v0, 0x9
    ctx->r3 = ctx->r2 ^ 0X9;
    // 0x800336B0: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x800336B4: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
L_800336B8:
    // 0x800336B8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800336BC: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800336C0: beq         $v1, $zero, L_800336D4
    if (ctx->r3 == 0) {
        // 0x800336C4: nop
    
            goto L_800336D4;
    }
    // 0x800336C4: nop

    // 0x800336C8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x800336CC: jal         0x8003228C
    // 0x800336D0: addiu       $a0, $a0, -0x79A0
    ctx->r4 = ADD32(ctx->r4, -0X79A0);
    func_8003228C(rdram, ctx);
        goto after_14;
    // 0x800336D0: addiu       $a0, $a0, -0x79A0
    ctx->r4 = ADD32(ctx->r4, -0X79A0);
    after_14:
L_800336D4:
    // 0x800336D4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800336D8: jal         0x800326F0
    // 0x800336DC: addiu       $a0, $a0, 0x44AC
    ctx->r4 = ADD32(ctx->r4, 0X44AC);
    func_800326F0(rdram, ctx);
        goto after_15;
    // 0x800336DC: addiu       $a0, $a0, 0x44AC
    ctx->r4 = ADD32(ctx->r4, 0X44AC);
    after_15:
    // 0x800336E0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800336E4: lbu         $v1, 0x447E($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X447E);
    // 0x800336E8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800336EC: bne         $v1, $v0, L_80033724
    if (ctx->r3 != ctx->r2) {
        // 0x800336F0: nop
    
            goto L_80033724;
    }
    // 0x800336F0: nop

    // 0x800336F4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800336F8: lbu         $v0, 0x447C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X447C);
    // 0x800336FC: xori        $v1, $v0, 0x9
    ctx->r3 = ctx->r2 ^ 0X9;
    // 0x80033700: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x80033704: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x80033708: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8003370C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80033710: beq         $v1, $zero, L_80033724
    if (ctx->r3 == 0) {
        // 0x80033714: nop
    
            goto L_80033724;
    }
    // 0x80033714: nop

    // 0x80033718: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x8003371C: jal         0x8003228C
    // 0x80033720: addiu       $a0, $a0, -0x7A3C
    ctx->r4 = ADD32(ctx->r4, -0X7A3C);
    func_8003228C(rdram, ctx);
        goto after_16;
    // 0x80033720: addiu       $a0, $a0, -0x7A3C
    ctx->r4 = ADD32(ctx->r4, -0X7A3C);
    after_16:
L_80033724:
    // 0x80033724: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80033728: addiu       $a0, $a0, 0x4478
    ctx->r4 = ADD32(ctx->r4, 0X4478);
L_8003372C:
    // 0x8003372C: jal         0x800326F0
    // 0x80033730: nop

    func_800326F0(rdram, ctx);
        goto after_17;
    // 0x80033730: nop

    after_17:
    // 0x80033734: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80033738: lbu         $v1, 0x447E($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X447E);
    // 0x8003373C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80033740: bne         $v1, $v0, L_8003376C
    if (ctx->r3 != ctx->r2) {
        // 0x80033744: nop
    
            goto L_8003376C;
    }
    // 0x80033744: nop

    // 0x80033748: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8003374C: lbu         $v0, 0x447C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X447C);
    // 0x80033750: xori        $v1, $v0, 0x9
    ctx->r3 = ctx->r2 ^ 0X9;
    // 0x80033754: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80033758: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x8003375C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80033760: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80033764: beq         $v1, $zero, L_80033778
    if (ctx->r3 == 0) {
        // 0x80033768: nop
    
            goto L_80033778;
    }
    // 0x80033768: nop

L_8003376C:
    // 0x8003376C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x80033770: jal         0x8003228C
    // 0x80033774: addiu       $a0, $a0, -0x7A3C
    ctx->r4 = ADD32(ctx->r4, -0X7A3C);
    func_8003228C(rdram, ctx);
        goto after_18;
    // 0x80033774: addiu       $a0, $a0, -0x7A3C
    ctx->r4 = ADD32(ctx->r4, -0X7A3C);
    after_18:
L_80033778:
    // 0x80033778: lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // 0x8003377C: addiu       $s0, $s0, -0x7A08
    ctx->r16 = ADD32(ctx->r16, -0X7A08);
    // 0x80033780: jal         0x8003228C
    // 0x80033784: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8003228C(rdram, ctx);
        goto after_19;
    // 0x80033784: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_19:
    // 0x80033788: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8003378C: lbu         $v1, 0x44B2($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X44B2);
    // 0x80033790: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80033794: bne         $v1, $v0, L_800337C0
    if (ctx->r3 != ctx->r2) {
        // 0x80033798: nop
    
            goto L_800337C0;
    }
    // 0x80033798: nop

    // 0x8003379C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800337A0: lbu         $v0, 0x44B0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X44B0);
    // 0x800337A4: xori        $v1, $v0, 0x9
    ctx->r3 = ctx->r2 ^ 0X9;
    // 0x800337A8: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800337AC: xori        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 ^ 0X3;
    // 0x800337B0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800337B4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800337B8: beq         $v1, $zero, L_800337C8
    if (ctx->r3 == 0) {
        // 0x800337BC: nop
    
            goto L_800337C8;
    }
    // 0x800337BC: nop

L_800337C0:
    // 0x800337C0: jal         0x8003228C
    // 0x800337C4: addiu       $a0, $s0, 0x68
    ctx->r4 = ADD32(ctx->r16, 0X68);
    func_8003228C(rdram, ctx);
        goto after_20;
    // 0x800337C4: addiu       $a0, $s0, 0x68
    ctx->r4 = ADD32(ctx->r16, 0X68);
    after_20:
L_800337C8:
    // 0x800337C8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x800337CC: jal         0x8003228C
    // 0x800337D0: addiu       $a0, $a0, -0x796C
    ctx->r4 = ADD32(ctx->r4, -0X796C);
    func_8003228C(rdram, ctx);
        goto after_21;
    // 0x800337D0: addiu       $a0, $a0, -0x796C
    ctx->r4 = ADD32(ctx->r4, -0X796C);
    after_21:
    // 0x800337D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800337D8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800337DC: jr          $ra
    // 0x800337E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800337E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800337E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800337E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800337E8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800337EC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800337F0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800337F4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800337F8: lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6);
    // 0x800337FC: lbu         $v1, 0x2($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2);
    // 0x80033800: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80033804: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80033808: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8003380C: lw          $v0, 0x70D0($at)
    ctx->r2 = MEM_W(ctx->r1, 0X70D0);
    // 0x80033810: lh          $a2, 0x8($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X8);
    // 0x80033814: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80033818: lb          $a1, 0x0($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X0);
    // 0x8003381C: addiu       $s1, $s0, 0xC
    ctx->r17 = ADD32(ctx->r16, 0XC);
    // 0x80033820: jal         0x80053234
    // 0x80033824: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80053234(rdram, ctx);
        goto after_0;
    // 0x80033824: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x80033828: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8003382C: jal         0x80051C7C
    // 0x80033830: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    func_80051C7C(rdram, ctx);
        goto after_1;
    // 0x80033830: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    after_1:
    // 0x80033834: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80033838: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003383C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80033840: jr          $ra
    // 0x80033844: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80033844: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80033848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033848: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003384C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80033850: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80033854: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80033858: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003385C: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x80033860: lbu         $a2, 0x3($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X3);
    // 0x80033864: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80033868: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8003386C: lb          $a1, 0x70F0($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X70F0);
    // 0x80033870: addiu       $s1, $s0, 0xC
    ctx->r17 = ADD32(ctx->r16, 0XC);
    // 0x80033874: jal         0x80053234
    // 0x80033878: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80053234(rdram, ctx);
        goto after_0;
    // 0x80033878: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x8003387C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80033880: jal         0x80051C7C
    // 0x80033884: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    func_80051C7C(rdram, ctx);
        goto after_1;
    // 0x80033884: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    after_1:
    // 0x80033888: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8003388C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80033890: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80033894: jr          $ra
    // 0x80033898: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80033898: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8003389C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003389C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800338A0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800338A4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800338A8: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800338AC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800338B0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800338B4: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x800338B8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800338BC: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x800338C0: addiu       $s3, $s3, 0x4478
    ctx->r19 = ADD32(ctx->r19, 0X4478);
    // 0x800338C4: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800338C8: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x800338CC: addiu       $s2, $s2, -0x3250
    ctx->r18 = ADD32(ctx->r18, -0X3250);
    // 0x800338D0: sw          $ra, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r31;
    // 0x800338D4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800338D8: sll         $v1, $s1, 24
    ctx->r3 = S32(ctx->r17 << 24);
L_800338DC:
    // 0x800338DC: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x800338E0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800338E4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800338E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800338EC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800338F0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800338F4: addu        $s0, $v0, $s3
    ctx->r16 = ADD32(ctx->r2, ctx->r19);
    // 0x800338F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800338FC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80033900: sb          $s5, 0x4478($at)
    MEM_B(0X4478, ctx->r1) = ctx->r21;
    // 0x80033904: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033908: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8003390C: sb          $zero, 0x4479($at)
    MEM_B(0X4479, ctx->r1) = 0;
    // 0x80033910: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033914: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80033918: sb          $s4, 0x447A($at)
    MEM_B(0X447A, ctx->r1) = ctx->r20;
    // 0x8003391C: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x80033920: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033924: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80033928: sb          $zero, 0x447C($at)
    MEM_B(0X447C, ctx->r1) = 0;
    // 0x8003392C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033930: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80033934: sb          $zero, 0x447D($at)
    MEM_B(0X447D, ctx->r1) = 0;
    // 0x80033938: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8003393C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80033940: lbu         $a0, 0x7E2C($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7E2C);
    // 0x80033944: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033948: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8003394C: sh          $zero, 0x4480($at)
    MEM_H(0X4480, ctx->r1) = 0;
    // 0x80033950: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033954: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80033958: sb          $zero, 0x447F($at)
    MEM_B(0X447F, ctx->r1) = 0;
    // 0x8003395C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033960: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80033964: sb          $a0, 0x447E($at)
    MEM_B(0X447E, ctx->r1) = ctx->r4;
    // 0x80033968: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8003396C: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x80033970: lb          $a1, 0x7E2C($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X7E2C);
    // 0x80033974: jal         0x80035630
    // 0x80033978: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80035630(rdram, ctx);
        goto after_0;
    // 0x80033978: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8003397C: lbu         $a1, 0x6($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X6);
    // 0x80033980: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80033984: lw          $a0, -0x6350($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6350);
    // 0x80033988: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003398C: sll         $a1, $a1, 5
    ctx->r5 = S32(ctx->r5 << 5);
    // 0x80033990: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x80033994: jal         0x8005334C
    // 0x80033998: addu        $a1, $a1, $s2
    ctx->r5 = ADD32(ctx->r5, ctx->r18);
    func_8005334C(rdram, ctx);
        goto after_1;
    // 0x80033998: addu        $a1, $a1, $s2
    ctx->r5 = ADD32(ctx->r5, ctx->r18);
    after_1:
    // 0x8003399C: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
    // 0x800339A0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800339A4: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800339A8: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800339AC: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800339B0: bne         $v0, $zero, L_800338DC
    if (ctx->r2 != 0) {
        // 0x800339B4: sll         $v1, $s1, 24
        ctx->r3 = S32(ctx->r17 << 24);
            goto L_800338DC;
    }
    // 0x800339B4: sll         $v1, $s1, 24
    ctx->r3 = S32(ctx->r17 << 24);
    // 0x800339B8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800339BC: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x800339C0: beq         $v0, $zero, L_80033A38
    if (ctx->r2 == 0) {
        // 0x800339C4: nop
    
            goto L_80033A38;
    }
    // 0x800339C4: nop

    // 0x800339C8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800339CC: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x800339D0: beq         $v0, $zero, L_80033A38
    if (ctx->r2 == 0) {
        // 0x800339D4: nop
    
            goto L_80033A38;
    }
    // 0x800339D4: nop

    // 0x800339D8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800339DC: lbu         $v0, -0xBE8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XBE8);
    // 0x800339E0: bne         $v0, $zero, L_80033A38
    if (ctx->r2 != 0) {
        // 0x800339E4: nop
    
            goto L_80033A38;
    }
    // 0x800339E4: nop

    // 0x800339E8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800339EC: lb          $v0, 0x25F3($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25F3);
    // 0x800339F0: beq         $v0, $zero, L_80033A10
    if (ctx->r2 == 0) {
        // 0x800339F4: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80033A10;
    }
    // 0x800339F4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800339F8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800339FC: addiu       $v1, $v1, 0x7B8B
    ctx->r3 = ADD32(ctx->r3, 0X7B8B);
    // 0x80033A00: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80033A04: andi        $v0, $v0, 0xF0
    ctx->r2 = ctx->r2 & 0XF0;
    // 0x80033A08: j           L_80033A44
    // 0x80033A0C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
        goto L_80033A44;
    // 0x80033A0C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_80033A10:
    // 0x80033A10: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80033A14: lb          $v0, 0x7A43($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7A43);
    // 0x80033A18: beq         $v0, $zero, L_80033A38
    if (ctx->r2 == 0) {
        // 0x80033A1C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80033A38;
    }
    // 0x80033A1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80033A20: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80033A24: addiu       $v1, $v1, 0x7B8B
    ctx->r3 = ADD32(ctx->r3, 0X7B8B);
    // 0x80033A28: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80033A2C: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x80033A30: j           L_80033A44
    // 0x80033A34: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
        goto L_80033A44;
    // 0x80033A34: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_80033A38:
    // 0x80033A38: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033A3C: sb          $zero, 0x7B8B($at)
    MEM_B(0X7B8B, ctx->r1) = 0;
    // 0x80033A40: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80033A44:
    // 0x80033A44: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80033A48: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x80033A4C: beql        $v0, $zero, L_80033FE0
    if (ctx->r2 == 0) {
        // 0x80033A50: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80033FE0;
    }
    goto skip_0;
    // 0x80033A50: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    skip_0:
    // 0x80033A54: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80033A58: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x80033A5C: beq         $v0, $zero, L_80033E68
    if (ctx->r2 == 0) {
        // 0x80033A60: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80033E68;
    }
    // 0x80033A60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80033A64: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80033A68: lb          $v0, 0x7F24($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7F24);
    // 0x80033A6C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033A70: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80033A74: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80033A78: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80033A7C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80033A80: lbu         $v1, 0x70F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X70F7);
    // 0x80033A84: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80033A88: lb          $v0, 0x7F25($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7F25);
    // 0x80033A8C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033A90: sb          $a2, -0x7A70($at)
    MEM_B(-0X7A70, ctx->r1) = ctx->r6;
    // 0x80033A94: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033A98: sb          $zero, -0x7A6F($at)
    MEM_B(-0X7A6F, ctx->r1) = 0;
    // 0x80033A9C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033AA0: sb          $zero, -0x7A6E($at)
    MEM_B(-0X7A6E, ctx->r1) = 0;
    // 0x80033AA4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033AA8: sb          $zero, -0x7A6C($at)
    MEM_B(-0X7A6C, ctx->r1) = 0;
    // 0x80033AAC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033AB0: sb          $zero, -0x7A6B($at)
    MEM_B(-0X7A6B, ctx->r1) = 0;
    // 0x80033AB4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033AB8: sb          $zero, -0x7A6A($at)
    MEM_B(-0X7A6A, ctx->r1) = 0;
    // 0x80033ABC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033AC0: sh          $zero, -0x7A68($at)
    MEM_H(-0X7A68, ctx->r1) = 0;
    // 0x80033AC4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033AC8: sb          $zero, -0x7A69($at)
    MEM_B(-0X7A69, ctx->r1) = 0;
    // 0x80033ACC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033AD0: sw          $zero, -0x7A58($at)
    MEM_W(-0X7A58, ctx->r1) = 0;
    // 0x80033AD4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033AD8: sw          $zero, -0x7A5C($at)
    MEM_W(-0X7A5C, ctx->r1) = 0;
    // 0x80033ADC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033AE0: sh          $zero, -0x7A5E($at)
    MEM_H(-0X7A5E, ctx->r1) = 0;
    // 0x80033AE4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033AE8: sh          $zero, -0x7A60($at)
    MEM_H(-0X7A60, ctx->r1) = 0;
    // 0x80033AEC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033AF0: swc1        $f0, -0x7A50($at)
    MEM_W(-0X7A50, ctx->r1) = ctx->f0.u32l;
    // 0x80033AF4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033AF8: swc1        $f0, -0x7A54($at)
    MEM_W(-0X7A54, ctx->r1) = ctx->f0.u32l;
    // 0x80033AFC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033B00: sw          $zero, -0x7A40($at)
    MEM_W(-0X7A40, ctx->r1) = 0;
    // 0x80033B04: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033B08: sw          $zero, -0x7A44($at)
    MEM_W(-0X7A44, ctx->r1) = 0;
    // 0x80033B0C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033B10: sw          $zero, -0x7A4C($at)
    MEM_W(-0X7A4C, ctx->r1) = 0;
    // 0x80033B14: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80033B18: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033B1C: sb          $v1, -0x7A6D($at)
    MEM_B(-0X7A6D, ctx->r1) = ctx->r3;
    // 0x80033B20: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80033B24: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80033B28: lbu         $v0, 0x70F7($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X70F7);
    // 0x80033B2C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033B30: sb          $a2, -0x7A3C($at)
    MEM_B(-0X7A3C, ctx->r1) = ctx->r6;
    // 0x80033B34: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033B38: sb          $zero, -0x7A3B($at)
    MEM_B(-0X7A3B, ctx->r1) = 0;
    // 0x80033B3C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033B40: sb          $zero, -0x7A3A($at)
    MEM_B(-0X7A3A, ctx->r1) = 0;
    // 0x80033B44: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033B48: sb          $zero, -0x7A38($at)
    MEM_B(-0X7A38, ctx->r1) = 0;
    // 0x80033B4C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033B50: sb          $zero, -0x7A37($at)
    MEM_B(-0X7A37, ctx->r1) = 0;
    // 0x80033B54: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033B58: sb          $zero, -0x7A36($at)
    MEM_B(-0X7A36, ctx->r1) = 0;
    // 0x80033B5C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033B60: sh          $zero, -0x7A34($at)
    MEM_H(-0X7A34, ctx->r1) = 0;
    // 0x80033B64: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033B68: sb          $zero, -0x7A35($at)
    MEM_B(-0X7A35, ctx->r1) = 0;
    // 0x80033B6C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033B70: sw          $zero, -0x7A24($at)
    MEM_W(-0X7A24, ctx->r1) = 0;
    // 0x80033B74: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033B78: sw          $zero, -0x7A28($at)
    MEM_W(-0X7A28, ctx->r1) = 0;
    // 0x80033B7C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033B80: sb          $v0, -0x7A39($at)
    MEM_B(-0X7A39, ctx->r1) = ctx->r2;
    // 0x80033B84: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033B88: sh          $zero, -0x7A2A($at)
    MEM_H(-0X7A2A, ctx->r1) = 0;
    // 0x80033B8C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80033B90: lb          $v0, 0x7F26($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7F26);
    // 0x80033B94: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80033B98: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033B9C: sh          $zero, -0x7A2C($at)
    MEM_H(-0X7A2C, ctx->r1) = 0;
    // 0x80033BA0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033BA4: swc1        $f0, -0x7A1C($at)
    MEM_W(-0X7A1C, ctx->r1) = ctx->f0.u32l;
    // 0x80033BA8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033BAC: swc1        $f0, -0x7A20($at)
    MEM_W(-0X7A20, ctx->r1) = ctx->f0.u32l;
    // 0x80033BB0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033BB4: sw          $zero, -0x7A0C($at)
    MEM_W(-0X7A0C, ctx->r1) = 0;
    // 0x80033BB8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033BBC: sw          $zero, -0x7A10($at)
    MEM_W(-0X7A10, ctx->r1) = 0;
    // 0x80033BC0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033BC4: sw          $zero, -0x7A18($at)
    MEM_W(-0X7A18, ctx->r1) = 0;
    // 0x80033BC8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80033BCC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80033BD0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80033BD4: lbu         $v1, 0x70F7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X70F7);
    // 0x80033BD8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80033BDC: lb          $v0, 0x7F27($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7F27);
    // 0x80033BE0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033BE4: sb          $a2, -0x7A08($at)
    MEM_B(-0X7A08, ctx->r1) = ctx->r6;
    // 0x80033BE8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033BEC: sb          $zero, -0x7A07($at)
    MEM_B(-0X7A07, ctx->r1) = 0;
    // 0x80033BF0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033BF4: sb          $zero, -0x7A06($at)
    MEM_B(-0X7A06, ctx->r1) = 0;
    // 0x80033BF8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033BFC: sb          $zero, -0x7A04($at)
    MEM_B(-0X7A04, ctx->r1) = 0;
    // 0x80033C00: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033C04: sb          $a2, -0x7A03($at)
    MEM_B(-0X7A03, ctx->r1) = ctx->r6;
    // 0x80033C08: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033C0C: sb          $a3, -0x7A02($at)
    MEM_B(-0X7A02, ctx->r1) = ctx->r7;
    // 0x80033C10: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033C14: sh          $zero, -0x7A00($at)
    MEM_H(-0X7A00, ctx->r1) = 0;
    // 0x80033C18: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033C1C: sb          $zero, -0x7A01($at)
    MEM_B(-0X7A01, ctx->r1) = 0;
    // 0x80033C20: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033C24: sw          $zero, -0x79F0($at)
    MEM_W(-0X79F0, ctx->r1) = 0;
    // 0x80033C28: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033C2C: sw          $zero, -0x79F4($at)
    MEM_W(-0X79F4, ctx->r1) = 0;
    // 0x80033C30: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033C34: sh          $zero, -0x79F6($at)
    MEM_H(-0X79F6, ctx->r1) = 0;
    // 0x80033C38: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033C3C: sh          $zero, -0x79F8($at)
    MEM_H(-0X79F8, ctx->r1) = 0;
    // 0x80033C40: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033C44: swc1        $f0, -0x79E8($at)
    MEM_W(-0X79E8, ctx->r1) = ctx->f0.u32l;
    // 0x80033C48: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033C4C: swc1        $f0, -0x79EC($at)
    MEM_W(-0X79EC, ctx->r1) = ctx->f0.u32l;
    // 0x80033C50: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033C54: sw          $zero, -0x79D8($at)
    MEM_W(-0X79D8, ctx->r1) = 0;
    // 0x80033C58: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033C5C: sw          $zero, -0x79DC($at)
    MEM_W(-0X79DC, ctx->r1) = 0;
    // 0x80033C60: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033C64: sw          $zero, -0x79E4($at)
    MEM_W(-0X79E4, ctx->r1) = 0;
    // 0x80033C68: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80033C6C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033C70: sb          $v1, -0x7A05($at)
    MEM_B(-0X7A05, ctx->r1) = ctx->r3;
    // 0x80033C74: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80033C78: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80033C7C: lbu         $v0, 0x70F7($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X70F7);
    // 0x80033C80: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80033C84: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033C88: sb          $a2, -0x79D4($at)
    MEM_B(-0X79D4, ctx->r1) = ctx->r6;
    // 0x80033C8C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033C90: sb          $zero, -0x79D3($at)
    MEM_B(-0X79D3, ctx->r1) = 0;
    // 0x80033C94: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033C98: sb          $zero, -0x79D2($at)
    MEM_B(-0X79D2, ctx->r1) = 0;
    // 0x80033C9C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033CA0: sb          $zero, -0x79D0($at)
    MEM_B(-0X79D0, ctx->r1) = 0;
    // 0x80033CA4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033CA8: sb          $v0, -0x79D1($at)
    MEM_B(-0X79D1, ctx->r1) = ctx->r2;
    // 0x80033CAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80033CB0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033CB4: sb          $a2, -0x79CF($at)
    MEM_B(-0X79CF, ctx->r1) = ctx->r6;
    // 0x80033CB8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033CBC: sb          $a3, -0x79CE($at)
    MEM_B(-0X79CE, ctx->r1) = ctx->r7;
    // 0x80033CC0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033CC4: sh          $zero, -0x79CC($at)
    MEM_H(-0X79CC, ctx->r1) = 0;
    // 0x80033CC8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033CCC: sb          $zero, -0x79CD($at)
    MEM_B(-0X79CD, ctx->r1) = 0;
    // 0x80033CD0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033CD4: sw          $zero, -0x79BC($at)
    MEM_W(-0X79BC, ctx->r1) = 0;
    // 0x80033CD8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033CDC: sw          $zero, -0x79C0($at)
    MEM_W(-0X79C0, ctx->r1) = 0;
    // 0x80033CE0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033CE4: sh          $zero, -0x79C2($at)
    MEM_H(-0X79C2, ctx->r1) = 0;
    // 0x80033CE8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033CEC: sh          $zero, -0x79C4($at)
    MEM_H(-0X79C4, ctx->r1) = 0;
    // 0x80033CF0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033CF4: swc1        $f0, -0x79B4($at)
    MEM_W(-0X79B4, ctx->r1) = ctx->f0.u32l;
    // 0x80033CF8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033CFC: swc1        $f0, -0x79B8($at)
    MEM_W(-0X79B8, ctx->r1) = ctx->f0.u32l;
    // 0x80033D00: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033D04: sw          $zero, -0x79A4($at)
    MEM_W(-0X79A4, ctx->r1) = 0;
    // 0x80033D08: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033D0C: sw          $zero, -0x79A8($at)
    MEM_W(-0X79A8, ctx->r1) = 0;
    // 0x80033D10: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033D14: sw          $zero, -0x79B0($at)
    MEM_W(-0X79B0, ctx->r1) = 0;
    // 0x80033D18: beq         $v1, $v0, L_80033D5C
    if (ctx->r3 == ctx->r2) {
        // 0x80033D1C: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80033D5C;
    }
    // 0x80033D1C: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80033D20: beql        $v0, $zero, L_80033D38
    if (ctx->r2 == 0) {
        // 0x80033D24: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80033D38;
    }
    goto skip_1;
    // 0x80033D24: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_1:
    // 0x80033D28: beq         $v1, $zero, L_80033D48
    if (ctx->r3 == 0) {
        // 0x80033D2C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80033D48;
    }
    // 0x80033D2C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80033D30: j           L_80034154
    // 0x80033D34: nop

        goto L_80034154;
    // 0x80033D34: nop

L_80033D38:
    // 0x80033D38: beq         $v1, $v0, L_80033DDC
    if (ctx->r3 == ctx->r2) {
        // 0x80033D3C: addiu       $v1, $zero, 0x3
        ctx->r3 = ADD32(0, 0X3);
            goto L_80033DDC;
    }
    // 0x80033D3C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80033D40: j           L_80034154
    // 0x80033D44: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
        goto L_80034154;
    // 0x80033D44: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80033D48:
    // 0x80033D48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80033D4C: sb          $zero, 0x515C($at)
    MEM_B(0X515C, ctx->r1) = 0;
    // 0x80033D50: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80033D54: j           L_80034154
    // 0x80033D58: sb          $a3, 0x515D($at)
    MEM_B(0X515D, ctx->r1) = ctx->r7;
        goto L_80034154;
    // 0x80033D58: sb          $a3, 0x515D($at)
    MEM_B(0X515D, ctx->r1) = ctx->r7;
L_80033D5C:
    // 0x80033D5C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80033D60: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x80033D64: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80033D68: addiu       $v1, $v1, 0x515C
    ctx->r3 = ADD32(ctx->r3, 0X515C);
    // 0x80033D6C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80033D70: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x80033D74: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80033D78: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80033D7C: lbu         $a0, 0x7F34($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7F34);
    // 0x80033D80: bne         $a0, $zero, L_80033D8C
    if (ctx->r4 != 0) {
        // 0x80033D84: sb          $a0, 0x1($v1)
        MEM_B(0X1, ctx->r3) = ctx->r4;
            goto L_80033D8C;
    }
    // 0x80033D84: sb          $a0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r4;
    // 0x80033D88: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_80033D8C:
    // 0x80033D8C: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x80033D90: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80033D94: lhu         $v0, 0x7B76($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7B76);
    // 0x80033D98: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033D9C: sb          $a2, -0x7A07($at)
    MEM_B(-0X7A07, ctx->r1) = ctx->r6;
    // 0x80033DA0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033DA4: sb          $a2, -0x79D3($at)
    MEM_B(-0X79D3, ctx->r1) = ctx->r6;
    // 0x80033DA8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033DAC: sb          $a0, -0x7A02($at)
    MEM_B(-0X7A02, ctx->r1) = ctx->r4;
    // 0x80033DB0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033DB4: sb          $a0, -0x79CE($at)
    MEM_B(-0X79CE, ctx->r1) = ctx->r4;
    // 0x80033DB8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80033DBC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033DC0: sb          $v1, -0x7A6A($at)
    MEM_B(-0X7A6A, ctx->r1) = ctx->r3;
    // 0x80033DC4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033DC8: sb          $v1, -0x7A36($at)
    MEM_B(-0X7A36, ctx->r1) = ctx->r3;
    // 0x80033DCC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033DD0: sh          $v0, 0x7B76($at)
    MEM_H(0X7B76, ctx->r1) = ctx->r2;
    // 0x80033DD4: j           L_80034154
    // 0x80033DD8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
        goto L_80034154;
    // 0x80033DD8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80033DDC:
    // 0x80033DDC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80033DE0: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x80033DE4: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x80033DE8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80033DEC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80033DF0: lbu         $a0, 0x7F34($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7F34);
    // 0x80033DF4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80033DF8: addiu       $a1, $a1, 0x515C
    ctx->r5 = ADD32(ctx->r5, 0X515C);
    // 0x80033DFC: sb          $a3, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r7;
    // 0x80033E00: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
    // 0x80033E04: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80033E08: bne         $v0, $v1, L_80033E18
    if (ctx->r2 != ctx->r3) {
        // 0x80033E0C: sb          $a0, 0x0($a1)
        MEM_B(0X0, ctx->r5) = ctx->r4;
            goto L_80033E18;
    }
    // 0x80033E0C: sb          $a0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r4;
    // 0x80033E10: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80033E14: sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
L_80033E18:
    // 0x80033E18: lbu         $v1, 0x1($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X1);
    // 0x80033E1C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80033E20: lhu         $v0, 0x7B76($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7B76);
    // 0x80033E24: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033E28: sb          $a2, -0x7A6F($at)
    MEM_B(-0X7A6F, ctx->r1) = ctx->r6;
    // 0x80033E2C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033E30: sb          $a2, -0x7A3B($at)
    MEM_B(-0X7A3B, ctx->r1) = ctx->r6;
    // 0x80033E34: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033E38: sb          $a0, -0x7A6A($at)
    MEM_B(-0X7A6A, ctx->r1) = ctx->r4;
    // 0x80033E3C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033E40: sb          $a0, -0x7A36($at)
    MEM_B(-0X7A36, ctx->r1) = ctx->r4;
    // 0x80033E44: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80033E48: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033E4C: sb          $v1, -0x7A02($at)
    MEM_B(-0X7A02, ctx->r1) = ctx->r3;
    // 0x80033E50: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033E54: sb          $v1, -0x79CE($at)
    MEM_B(-0X79CE, ctx->r1) = ctx->r3;
    // 0x80033E58: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80033E5C: sh          $v0, 0x7B76($at)
    MEM_H(0X7B76, ctx->r1) = ctx->r2;
    // 0x80033E60: j           L_80034154
    // 0x80033E64: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
        goto L_80034154;
    // 0x80033E64: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80033E68:
    // 0x80033E68: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80033E6C: lb          $v0, 0x7F24($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7F24);
    // 0x80033E70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033E74: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80033E78: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80033E7C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80033E80: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80033E84: lbu         $a0, 0x70F7($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X70F7);
    // 0x80033E88: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80033E8C: lb          $v0, 0x7F25($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7F25);
    // 0x80033E90: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80033E94: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033E98: sb          $v1, -0x7A70($at)
    MEM_B(-0X7A70, ctx->r1) = ctx->r3;
    // 0x80033E9C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033EA0: sb          $zero, -0x7A6F($at)
    MEM_B(-0X7A6F, ctx->r1) = 0;
    // 0x80033EA4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033EA8: sb          $zero, -0x7A6E($at)
    MEM_B(-0X7A6E, ctx->r1) = 0;
    // 0x80033EAC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033EB0: sb          $zero, -0x7A6C($at)
    MEM_B(-0X7A6C, ctx->r1) = 0;
    // 0x80033EB4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033EB8: sb          $zero, -0x7A6B($at)
    MEM_B(-0X7A6B, ctx->r1) = 0;
    // 0x80033EBC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033EC0: sb          $zero, -0x7A6A($at)
    MEM_B(-0X7A6A, ctx->r1) = 0;
    // 0x80033EC4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033EC8: sh          $zero, -0x7A68($at)
    MEM_H(-0X7A68, ctx->r1) = 0;
    // 0x80033ECC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033ED0: sb          $zero, -0x7A69($at)
    MEM_B(-0X7A69, ctx->r1) = 0;
    // 0x80033ED4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033ED8: sw          $zero, -0x7A58($at)
    MEM_W(-0X7A58, ctx->r1) = 0;
    // 0x80033EDC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033EE0: sw          $zero, -0x7A5C($at)
    MEM_W(-0X7A5C, ctx->r1) = 0;
    // 0x80033EE4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033EE8: sh          $zero, -0x7A5E($at)
    MEM_H(-0X7A5E, ctx->r1) = 0;
    // 0x80033EEC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033EF0: sh          $zero, -0x7A60($at)
    MEM_H(-0X7A60, ctx->r1) = 0;
    // 0x80033EF4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033EF8: swc1        $f0, -0x7A50($at)
    MEM_W(-0X7A50, ctx->r1) = ctx->f0.u32l;
    // 0x80033EFC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033F00: swc1        $f0, -0x7A54($at)
    MEM_W(-0X7A54, ctx->r1) = ctx->f0.u32l;
    // 0x80033F04: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033F08: sw          $zero, -0x7A40($at)
    MEM_W(-0X7A40, ctx->r1) = 0;
    // 0x80033F0C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033F10: sw          $zero, -0x7A44($at)
    MEM_W(-0X7A44, ctx->r1) = 0;
    // 0x80033F14: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033F18: sw          $zero, -0x7A4C($at)
    MEM_W(-0X7A4C, ctx->r1) = 0;
    // 0x80033F1C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80033F20: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033F24: sb          $a0, -0x7A6D($at)
    MEM_B(-0X7A6D, ctx->r1) = ctx->r4;
    // 0x80033F28: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80033F2C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80033F30: lbu         $v0, 0x70F7($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X70F7);
    // 0x80033F34: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033F38: sb          $v1, -0x7A3C($at)
    MEM_B(-0X7A3C, ctx->r1) = ctx->r3;
    // 0x80033F3C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033F40: sb          $zero, -0x7A3B($at)
    MEM_B(-0X7A3B, ctx->r1) = 0;
    // 0x80033F44: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033F48: sb          $zero, -0x7A3A($at)
    MEM_B(-0X7A3A, ctx->r1) = 0;
    // 0x80033F4C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033F50: sb          $zero, -0x7A38($at)
    MEM_B(-0X7A38, ctx->r1) = 0;
    // 0x80033F54: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033F58: sb          $zero, -0x7A37($at)
    MEM_B(-0X7A37, ctx->r1) = 0;
    // 0x80033F5C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033F60: sb          $zero, -0x7A36($at)
    MEM_B(-0X7A36, ctx->r1) = 0;
    // 0x80033F64: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033F68: sh          $zero, -0x7A34($at)
    MEM_H(-0X7A34, ctx->r1) = 0;
    // 0x80033F6C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033F70: sb          $zero, -0x7A35($at)
    MEM_B(-0X7A35, ctx->r1) = 0;
    // 0x80033F74: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033F78: sw          $zero, -0x7A24($at)
    MEM_W(-0X7A24, ctx->r1) = 0;
    // 0x80033F7C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033F80: sw          $zero, -0x7A28($at)
    MEM_W(-0X7A28, ctx->r1) = 0;
    // 0x80033F84: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033F88: sb          $v0, -0x7A39($at)
    MEM_B(-0X7A39, ctx->r1) = ctx->r2;
    // 0x80033F8C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80033F90: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033F94: sh          $zero, -0x7A2A($at)
    MEM_H(-0X7A2A, ctx->r1) = 0;
    // 0x80033F98: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033F9C: sh          $zero, -0x7A2C($at)
    MEM_H(-0X7A2C, ctx->r1) = 0;
    // 0x80033FA0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033FA4: swc1        $f0, -0x7A1C($at)
    MEM_W(-0X7A1C, ctx->r1) = ctx->f0.u32l;
    // 0x80033FA8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033FAC: swc1        $f0, -0x7A20($at)
    MEM_W(-0X7A20, ctx->r1) = ctx->f0.u32l;
    // 0x80033FB0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033FB4: sw          $zero, -0x7A0C($at)
    MEM_W(-0X7A0C, ctx->r1) = 0;
    // 0x80033FB8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033FBC: sw          $zero, -0x7A10($at)
    MEM_W(-0X7A10, ctx->r1) = 0;
    // 0x80033FC0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80033FC4: sw          $zero, -0x7A18($at)
    MEM_W(-0X7A18, ctx->r1) = 0;
    // 0x80033FC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80033FCC: sb          $zero, 0x515C($at)
    MEM_B(0X515C, ctx->r1) = 0;
    // 0x80033FD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80033FD4: sb          $v0, 0x515D($at)
    MEM_B(0X515D, ctx->r1) = ctx->r2;
    // 0x80033FD8: j           L_80034154
    // 0x80033FDC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
        goto L_80034154;
    // 0x80033FDC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80033FE0:
    // 0x80033FE0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80033FE4: lb          $v0, 0x7F26($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7F26);
    // 0x80033FE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033FEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80033FF0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80033FF4: lb          $v1, 0x7F27($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X7F27);
    // 0x80033FF8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80033FFC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80034000: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80034004: lbu         $a1, 0x70F7($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X70F7);
    // 0x80034008: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003400C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80034010: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034014: sb          $v0, -0x7A08($at)
    MEM_B(-0X7A08, ctx->r1) = ctx->r2;
    // 0x80034018: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003401C: sb          $zero, -0x7A07($at)
    MEM_B(-0X7A07, ctx->r1) = 0;
    // 0x80034020: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034024: sb          $zero, -0x7A06($at)
    MEM_B(-0X7A06, ctx->r1) = 0;
    // 0x80034028: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003402C: sb          $zero, -0x7A04($at)
    MEM_B(-0X7A04, ctx->r1) = 0;
    // 0x80034030: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034034: sb          $v0, -0x7A03($at)
    MEM_B(-0X7A03, ctx->r1) = ctx->r2;
    // 0x80034038: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003403C: sb          $a0, -0x7A02($at)
    MEM_B(-0X7A02, ctx->r1) = ctx->r4;
    // 0x80034040: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034044: sh          $zero, -0x7A00($at)
    MEM_H(-0X7A00, ctx->r1) = 0;
    // 0x80034048: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003404C: sb          $zero, -0x7A01($at)
    MEM_B(-0X7A01, ctx->r1) = 0;
    // 0x80034050: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034054: sw          $zero, -0x79F0($at)
    MEM_W(-0X79F0, ctx->r1) = 0;
    // 0x80034058: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003405C: sw          $zero, -0x79F4($at)
    MEM_W(-0X79F4, ctx->r1) = 0;
    // 0x80034060: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034064: sh          $zero, -0x79F6($at)
    MEM_H(-0X79F6, ctx->r1) = 0;
    // 0x80034068: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003406C: sh          $zero, -0x79F8($at)
    MEM_H(-0X79F8, ctx->r1) = 0;
    // 0x80034070: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034074: swc1        $f0, -0x79E8($at)
    MEM_W(-0X79E8, ctx->r1) = ctx->f0.u32l;
    // 0x80034078: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003407C: swc1        $f0, -0x79EC($at)
    MEM_W(-0X79EC, ctx->r1) = ctx->f0.u32l;
    // 0x80034080: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034084: sw          $zero, -0x79D8($at)
    MEM_W(-0X79D8, ctx->r1) = 0;
    // 0x80034088: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003408C: sw          $zero, -0x79DC($at)
    MEM_W(-0X79DC, ctx->r1) = 0;
    // 0x80034090: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034094: sw          $zero, -0x79E4($at)
    MEM_W(-0X79E4, ctx->r1) = 0;
    // 0x80034098: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003409C: sb          $a1, -0x7A05($at)
    MEM_B(-0X7A05, ctx->r1) = ctx->r5;
    // 0x800340A0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800340A4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800340A8: lbu         $v1, 0x70F7($at)
    ctx->r3 = MEM_BU(ctx->r1, 0X70F7);
    // 0x800340AC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800340B0: sb          $v0, -0x79D4($at)
    MEM_B(-0X79D4, ctx->r1) = ctx->r2;
    // 0x800340B4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800340B8: sb          $v0, -0x79CF($at)
    MEM_B(-0X79CF, ctx->r1) = ctx->r2;
    // 0x800340BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800340C0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800340C4: sb          $zero, -0x79D3($at)
    MEM_B(-0X79D3, ctx->r1) = 0;
    // 0x800340C8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800340CC: sb          $zero, -0x79D2($at)
    MEM_B(-0X79D2, ctx->r1) = 0;
    // 0x800340D0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800340D4: sb          $zero, -0x79D0($at)
    MEM_B(-0X79D0, ctx->r1) = 0;
    // 0x800340D8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800340DC: sb          $a0, -0x79CE($at)
    MEM_B(-0X79CE, ctx->r1) = ctx->r4;
    // 0x800340E0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800340E4: sh          $zero, -0x79CC($at)
    MEM_H(-0X79CC, ctx->r1) = 0;
    // 0x800340E8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800340EC: sb          $zero, -0x79CD($at)
    MEM_B(-0X79CD, ctx->r1) = 0;
    // 0x800340F0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800340F4: sw          $zero, -0x79BC($at)
    MEM_W(-0X79BC, ctx->r1) = 0;
    // 0x800340F8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800340FC: sw          $zero, -0x79C0($at)
    MEM_W(-0X79C0, ctx->r1) = 0;
    // 0x80034100: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034104: sb          $v1, -0x79D1($at)
    MEM_B(-0X79D1, ctx->r1) = ctx->r3;
    // 0x80034108: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003410C: sh          $zero, -0x79C2($at)
    MEM_H(-0X79C2, ctx->r1) = 0;
    // 0x80034110: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034114: sh          $zero, -0x79C4($at)
    MEM_H(-0X79C4, ctx->r1) = 0;
    // 0x80034118: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003411C: swc1        $f0, -0x79B4($at)
    MEM_W(-0X79B4, ctx->r1) = ctx->f0.u32l;
    // 0x80034120: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034124: swc1        $f0, -0x79B8($at)
    MEM_W(-0X79B8, ctx->r1) = ctx->f0.u32l;
    // 0x80034128: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003412C: sw          $zero, -0x79A4($at)
    MEM_W(-0X79A4, ctx->r1) = 0;
    // 0x80034130: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034134: sw          $zero, -0x79A8($at)
    MEM_W(-0X79A8, ctx->r1) = 0;
    // 0x80034138: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003413C: sw          $zero, -0x79B0($at)
    MEM_W(-0X79B0, ctx->r1) = 0;
    // 0x80034140: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80034144: sb          $v0, 0x515C($at)
    MEM_B(0X515C, ctx->r1) = ctx->r2;
    // 0x80034148: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003414C: sb          $a0, 0x515D($at)
    MEM_B(0X515D, ctx->r1) = ctx->r4;
    // 0x80034150: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80034154:
    // 0x80034154: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80034158: addiu       $t1, $t1, 0x70F4
    ctx->r9 = ADD32(ctx->r9, 0X70F4);
    // 0x8003415C: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x80034160: addiu       $t0, $t0, -0x79A0
    ctx->r8 = ADD32(ctx->r8, -0X79A0);
    // 0x80034164: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80034168: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003416C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80034170:
    // 0x80034170: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80034174: sll         $v1, $s1, 24
    ctx->r3 = S32(ctx->r17 << 24);
    // 0x80034178: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8003417C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80034180: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80034184: lb          $v0, 0x7F28($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7F28);
    // 0x80034188: addiu       $a0, $s1, 0x1
    ctx->r4 = ADD32(ctx->r17, 0X1);
    // 0x8003418C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80034190: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x80034194: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80034198: slti        $a0, $a0, 0xA
    ctx->r4 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x8003419C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800341A0: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800341A4: lbu         $a2, 0x3($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X3);
    // 0x800341A8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800341AC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800341B0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800341B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800341B8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800341BC: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800341C0: sb          $a3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r7;
    // 0x800341C4: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x800341C8: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x800341CC: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // 0x800341D0: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x800341D4: sb          $a1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r5;
    // 0x800341D8: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x800341DC: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
    // 0x800341E0: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x800341E4: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x800341E8: sh          $zero, 0x12($v0)
    MEM_H(0X12, ctx->r2) = 0;
    // 0x800341EC: sh          $zero, 0x10($v0)
    MEM_H(0X10, ctx->r2) = 0;
    // 0x800341F0: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x800341F4: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x800341F8: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x800341FC: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x80034200: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80034204: bne         $a0, $zero, L_80034170
    if (ctx->r4 != 0) {
        // 0x80034208: sb          $a2, 0x3($v0)
        MEM_B(0X3, ctx->r2) = ctx->r6;
            goto L_80034170;
    }
    // 0x80034208: sb          $a2, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r6;
    // 0x8003420C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80034210: addiu       $a2, $zero, 0x168
    ctx->r6 = ADD32(0, 0X168);
    // 0x80034214: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x80034218: sll         $a0, $s1, 24
    ctx->r4 = S32(ctx->r17 << 24);
L_8003421C:
    // 0x8003421C: addiu       $v1, $s1, 0x1
    ctx->r3 = ADD32(ctx->r17, 0X1);
    // 0x80034220: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
    // 0x80034224: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80034228: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8003422C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80034230: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80034234: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80034238: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003423C: sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3 << 24);
    // 0x80034240: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80034244: slti        $v1, $v1, 0xE
    ctx->r3 = SIGNED(ctx->r3) < 0XE ? 1 : 0;
    // 0x80034248: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003424C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80034250: sw          $a2, -0x7A5C($at)
    MEM_W(-0X7A5C, ctx->r1) = ctx->r6;
    // 0x80034254: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034258: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8003425C: sw          $a1, -0x7A58($at)
    MEM_W(-0X7A58, ctx->r1) = ctx->r5;
    // 0x80034260: bne         $v1, $zero, L_8003421C
    if (ctx->r3 != 0) {
        // 0x80034264: sll         $a0, $s1, 24
        ctx->r4 = S32(ctx->r17 << 24);
            goto L_8003421C;
    }
    // 0x80034264: sll         $a0, $s1, 24
    ctx->r4 = S32(ctx->r17 << 24);
    // 0x80034268: lw          $ra, 0x50($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X50);
    // 0x8003426C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80034270: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80034274: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80034278: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8003427C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80034280: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80034284: jr          $ra
    // 0x80034288: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80034288: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8003428C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003428C: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x80034290: addiu       $v1, $v1, -0x7A70
    ctx->r3 = ADD32(ctx->r3, -0X7A70);
    // 0x80034294: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80034298: beq         $v0, $zero, L_800343D4
    if (ctx->r2 == 0) {
        // 0x8003429C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800343D4;
    }
    // 0x8003429C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800342A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800342A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800342A8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800342AC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800342B0: sb          $v0, -0x7A05($at)
    MEM_B(-0X7A05, ctx->r1) = ctx->r2;
    // 0x800342B4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800342B8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800342BC: sb          $v1, -0x7A08($at)
    MEM_B(-0X7A08, ctx->r1) = ctx->r3;
    // 0x800342C0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800342C4: sb          $zero, -0x7A07($at)
    MEM_B(-0X7A07, ctx->r1) = 0;
    // 0x800342C8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800342CC: sb          $zero, -0x7A06($at)
    MEM_B(-0X7A06, ctx->r1) = 0;
    // 0x800342D0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800342D4: sb          $zero, -0x7A04($at)
    MEM_B(-0X7A04, ctx->r1) = 0;
    // 0x800342D8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800342DC: sb          $v1, -0x7A03($at)
    MEM_B(-0X7A03, ctx->r1) = ctx->r3;
    // 0x800342E0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800342E4: sb          $v0, -0x7A02($at)
    MEM_B(-0X7A02, ctx->r1) = ctx->r2;
    // 0x800342E8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800342EC: sh          $zero, -0x7A00($at)
    MEM_H(-0X7A00, ctx->r1) = 0;
    // 0x800342F0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800342F4: sb          $zero, -0x7A01($at)
    MEM_B(-0X7A01, ctx->r1) = 0;
    // 0x800342F8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800342FC: sw          $zero, -0x79F0($at)
    MEM_W(-0X79F0, ctx->r1) = 0;
    // 0x80034300: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034304: sw          $zero, -0x79F4($at)
    MEM_W(-0X79F4, ctx->r1) = 0;
    // 0x80034308: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003430C: sh          $zero, -0x79F6($at)
    MEM_H(-0X79F6, ctx->r1) = 0;
    // 0x80034310: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034314: sh          $zero, -0x79F8($at)
    MEM_H(-0X79F8, ctx->r1) = 0;
    // 0x80034318: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003431C: sw          $zero, -0x79D8($at)
    MEM_W(-0X79D8, ctx->r1) = 0;
    // 0x80034320: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034324: sw          $zero, -0x79DC($at)
    MEM_W(-0X79DC, ctx->r1) = 0;
    // 0x80034328: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003432C: sw          $zero, -0x79E4($at)
    MEM_W(-0X79E4, ctx->r1) = 0;
    // 0x80034330: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034334: sb          $v1, -0x79D4($at)
    MEM_B(-0X79D4, ctx->r1) = ctx->r3;
    // 0x80034338: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003433C: sb          $zero, -0x79D3($at)
    MEM_B(-0X79D3, ctx->r1) = 0;
    // 0x80034340: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034344: sb          $zero, -0x79D2($at)
    MEM_B(-0X79D2, ctx->r1) = 0;
    // 0x80034348: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003434C: sb          $zero, -0x79D0($at)
    MEM_B(-0X79D0, ctx->r1) = 0;
    // 0x80034350: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034354: sb          $v0, -0x79D1($at)
    MEM_B(-0X79D1, ctx->r1) = ctx->r2;
    // 0x80034358: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003435C: sb          $v1, -0x79CF($at)
    MEM_B(-0X79CF, ctx->r1) = ctx->r3;
    // 0x80034360: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034364: sb          $v0, -0x79CE($at)
    MEM_B(-0X79CE, ctx->r1) = ctx->r2;
    // 0x80034368: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003436C: sh          $zero, -0x79CC($at)
    MEM_H(-0X79CC, ctx->r1) = 0;
    // 0x80034370: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034374: sb          $zero, -0x79CD($at)
    MEM_B(-0X79CD, ctx->r1) = 0;
    // 0x80034378: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003437C: sw          $zero, -0x79BC($at)
    MEM_W(-0X79BC, ctx->r1) = 0;
    // 0x80034380: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034384: sw          $zero, -0x79C0($at)
    MEM_W(-0X79C0, ctx->r1) = 0;
    // 0x80034388: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003438C: sh          $zero, -0x79C2($at)
    MEM_H(-0X79C2, ctx->r1) = 0;
    // 0x80034390: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034394: sh          $zero, -0x79C4($at)
    MEM_H(-0X79C4, ctx->r1) = 0;
    // 0x80034398: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8003439C: swc1        $f0, -0x79E8($at)
    MEM_W(-0X79E8, ctx->r1) = ctx->f0.u32l;
    // 0x800343A0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800343A4: swc1        $f0, -0x79EC($at)
    MEM_W(-0X79EC, ctx->r1) = ctx->f0.u32l;
    // 0x800343A8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800343AC: swc1        $f0, -0x79B4($at)
    MEM_W(-0X79B4, ctx->r1) = ctx->f0.u32l;
    // 0x800343B0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800343B4: swc1        $f0, -0x79B8($at)
    MEM_W(-0X79B8, ctx->r1) = ctx->f0.u32l;
    // 0x800343B8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800343BC: sw          $zero, -0x79A4($at)
    MEM_W(-0X79A4, ctx->r1) = 0;
    // 0x800343C0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800343C4: sw          $zero, -0x79A8($at)
    MEM_W(-0X79A8, ctx->r1) = 0;
    // 0x800343C8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800343CC: j           L_800344FC
    // 0x800343D0: sw          $zero, -0x79B0($at)
    MEM_W(-0X79B0, ctx->r1) = 0;
        goto L_800344FC;
    // 0x800343D0: sw          $zero, -0x79B0($at)
    MEM_W(-0X79B0, ctx->r1) = 0;
L_800343D4:
    // 0x800343D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800343D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800343DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800343E0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800343E4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800343E8: sb          $zero, -0x7A6F($at)
    MEM_B(-0X7A6F, ctx->r1) = 0;
    // 0x800343EC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800343F0: sb          $zero, -0x7A6E($at)
    MEM_B(-0X7A6E, ctx->r1) = 0;
    // 0x800343F4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800343F8: sb          $zero, -0x7A6C($at)
    MEM_B(-0X7A6C, ctx->r1) = 0;
    // 0x800343FC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034400: sb          $zero, -0x7A6D($at)
    MEM_B(-0X7A6D, ctx->r1) = 0;
    // 0x80034404: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034408: sb          $zero, -0x7A6B($at)
    MEM_B(-0X7A6B, ctx->r1) = 0;
    // 0x8003440C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034410: sb          $zero, -0x7A6A($at)
    MEM_B(-0X7A6A, ctx->r1) = 0;
    // 0x80034414: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034418: sh          $zero, -0x7A68($at)
    MEM_H(-0X7A68, ctx->r1) = 0;
    // 0x8003441C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034420: sb          $zero, -0x7A69($at)
    MEM_B(-0X7A69, ctx->r1) = 0;
    // 0x80034424: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034428: sw          $zero, -0x7A58($at)
    MEM_W(-0X7A58, ctx->r1) = 0;
    // 0x8003442C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034430: sw          $zero, -0x7A5C($at)
    MEM_W(-0X7A5C, ctx->r1) = 0;
    // 0x80034434: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034438: sh          $zero, -0x7A5E($at)
    MEM_H(-0X7A5E, ctx->r1) = 0;
    // 0x8003443C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034440: sh          $zero, -0x7A60($at)
    MEM_H(-0X7A60, ctx->r1) = 0;
    // 0x80034444: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034448: sw          $zero, -0x7A40($at)
    MEM_W(-0X7A40, ctx->r1) = 0;
    // 0x8003444C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034450: sw          $zero, -0x7A44($at)
    MEM_W(-0X7A44, ctx->r1) = 0;
    // 0x80034454: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034458: sw          $zero, -0x7A4C($at)
    MEM_W(-0X7A4C, ctx->r1) = 0;
    // 0x8003445C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034460: sb          $v0, -0x7A3C($at)
    MEM_B(-0X7A3C, ctx->r1) = ctx->r2;
    // 0x80034464: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034468: sb          $zero, -0x7A3B($at)
    MEM_B(-0X7A3B, ctx->r1) = 0;
    // 0x8003446C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034470: sb          $zero, -0x7A3A($at)
    MEM_B(-0X7A3A, ctx->r1) = 0;
    // 0x80034474: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034478: sb          $zero, -0x7A38($at)
    MEM_B(-0X7A38, ctx->r1) = 0;
    // 0x8003447C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034480: sb          $v0, -0x7A39($at)
    MEM_B(-0X7A39, ctx->r1) = ctx->r2;
    // 0x80034484: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034488: sb          $zero, -0x7A37($at)
    MEM_B(-0X7A37, ctx->r1) = 0;
    // 0x8003448C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034490: sb          $zero, -0x7A36($at)
    MEM_B(-0X7A36, ctx->r1) = 0;
    // 0x80034494: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034498: sh          $zero, -0x7A34($at)
    MEM_H(-0X7A34, ctx->r1) = 0;
    // 0x8003449C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800344A0: sb          $zero, -0x7A35($at)
    MEM_B(-0X7A35, ctx->r1) = 0;
    // 0x800344A4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800344A8: sw          $zero, -0x7A24($at)
    MEM_W(-0X7A24, ctx->r1) = 0;
    // 0x800344AC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800344B0: sw          $zero, -0x7A28($at)
    MEM_W(-0X7A28, ctx->r1) = 0;
    // 0x800344B4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800344B8: sh          $zero, -0x7A2A($at)
    MEM_H(-0X7A2A, ctx->r1) = 0;
    // 0x800344BC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800344C0: sh          $zero, -0x7A2C($at)
    MEM_H(-0X7A2C, ctx->r1) = 0;
    // 0x800344C4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800344C8: swc1        $f0, -0x7A50($at)
    MEM_W(-0X7A50, ctx->r1) = ctx->f0.u32l;
    // 0x800344CC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800344D0: swc1        $f0, -0x7A54($at)
    MEM_W(-0X7A54, ctx->r1) = ctx->f0.u32l;
    // 0x800344D4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800344D8: swc1        $f0, -0x7A1C($at)
    MEM_W(-0X7A1C, ctx->r1) = ctx->f0.u32l;
    // 0x800344DC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800344E0: swc1        $f0, -0x7A20($at)
    MEM_W(-0X7A20, ctx->r1) = ctx->f0.u32l;
    // 0x800344E4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800344E8: sw          $zero, -0x7A0C($at)
    MEM_W(-0X7A0C, ctx->r1) = 0;
    // 0x800344EC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800344F0: sw          $zero, -0x7A10($at)
    MEM_W(-0X7A10, ctx->r1) = 0;
    // 0x800344F4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800344F8: sw          $zero, -0x7A18($at)
    MEM_W(-0X7A18, ctx->r1) = 0;
L_800344FC:
    // 0x800344FC: jr          $ra
    // 0x80034500: nop

    return;
    // 0x80034500: nop

;}
RECOMP_FUNC void func_80034504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034504: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80034508: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003450C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80034510: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80034514: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80034518: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x8003451C: beq         $v0, $zero, L_800346E0
    if (ctx->r2 == 0) {
        // 0x80034520: addu        $a0, $a1, $zero
        ctx->r4 = ADD32(ctx->r5, 0);
            goto L_800346E0;
    }
    // 0x80034520: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x80034524: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80034528: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x8003452C: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x80034530: beq         $v0, $zero, L_8003455C
    if (ctx->r2 == 0) {
        // 0x80034534: sll         $v0, $a1, 24
        ctx->r2 = S32(ctx->r5 << 24);
            goto L_8003455C;
    }
    // 0x80034534: sll         $v0, $a1, 24
    ctx->r2 = S32(ctx->r5 << 24);
    // 0x80034538: sra         $v0, $v0, 21
    ctx->r2 = S32(SIGNED(ctx->r2) >> 21);
    // 0x8003453C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80034540: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80034544: lw          $v0, 0x7E74($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7E74);
    // 0x80034548: addiu       $v1, $zero, 0xD
    ctx->r3 = ADD32(0, 0XD);
    // 0x8003454C: sb          $v1, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r3;
    // 0x80034550: addiu       $v0, $v0, 0x140
    ctx->r2 = ADD32(ctx->r2, 0X140);
    // 0x80034554: j           L_800345E8
    // 0x80034558: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
        goto L_800345E8;
    // 0x80034558: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_8003455C:
    // 0x8003455C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80034560: bne         $v1, $v0, L_80034594
    if (ctx->r3 != ctx->r2) {
        // 0x80034564: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_80034594;
    }
    // 0x80034564: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80034568: sll         $v0, $a1, 24
    ctx->r2 = S32(ctx->r5 << 24);
    // 0x8003456C: sra         $v0, $v0, 21
    ctx->r2 = S32(SIGNED(ctx->r2) >> 21);
    // 0x80034570: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x80034574: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80034578: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8003457C: lw          $v0, 0x7E74($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7E74);
    // 0x80034580: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80034584: beq         $v0, $zero, L_800345E0
    if (ctx->r2 == 0) {
        // 0x80034588: addiu       $v0, $v1, -0x6
        ctx->r2 = ADD32(ctx->r3, -0X6);
            goto L_800345E0;
    }
    // 0x80034588: addiu       $v0, $v1, -0x6
    ctx->r2 = ADD32(ctx->r3, -0X6);
    // 0x8003458C: j           L_800345E8
    // 0x80034590: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
        goto L_800345E8;
    // 0x80034590: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_80034594:
    // 0x80034594: bne         $v1, $v0, L_800345BC
    if (ctx->r3 != ctx->r2) {
        // 0x80034598: sll         $v0, $a1, 24
        ctx->r2 = S32(ctx->r5 << 24);
            goto L_800345BC;
    }
    // 0x80034598: sll         $v0, $a1, 24
    ctx->r2 = S32(ctx->r5 << 24);
    // 0x8003459C: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x800345A0: slti        $v0, $v1, -0x63
    ctx->r2 = SIGNED(ctx->r3) < -0X63 ? 1 : 0;
    // 0x800345A4: bnel        $v0, $zero, L_800345E4
    if (ctx->r2 != 0) {
        // 0x800345A8: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_800345E4;
    }
    goto skip_0;
    // 0x800345A8: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    skip_0:
    // 0x800345AC: addiu       $v0, $v1, -0x6
    ctx->r2 = ADD32(ctx->r3, -0X6);
    // 0x800345B0: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x800345B4: j           L_800345E4
    // 0x800345B8: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_800345E4;
    // 0x800345B8: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_800345BC:
    // 0x800345BC: sra         $v0, $v0, 21
    ctx->r2 = S32(SIGNED(ctx->r2) >> 21);
    // 0x800345C0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800345C4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800345C8: lw          $v0, 0x7E74($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7E74);
    // 0x800345CC: lbu         $v1, 0x1($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X1);
    // 0x800345D0: bne         $v1, $zero, L_800345E8
    if (ctx->r3 != 0) {
        // 0x800345D4: sw          $v0, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->r2;
            goto L_800345E8;
    }
    // 0x800345D4: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x800345D8: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800345DC: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
L_800345E0:
    // 0x800345E0: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_800345E4:
    // 0x800345E4: sb          $v0, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r2;
L_800345E8:
    // 0x800345E8: lbu         $a1, 0x6($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X6);
    // 0x800345EC: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
    // 0x800345F0: sra         $v0, $v0, 21
    ctx->r2 = S32(SIGNED(ctx->r2) >> 21);
    // 0x800345F4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800345F8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800345FC: lw          $v0, 0x7E78($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7E78);
    // 0x80034600: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80034604: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80034608: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8003460C: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // 0x80034610: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x80034614: jal         0x800355E8
    // 0x80034618: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    func_800355E8(rdram, ctx);
        goto after_0;
    // 0x80034618: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    after_0:
    // 0x8003461C: lh          $v1, 0x8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X8);
    // 0x80034620: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80034624: lbu         $a0, 0x7($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X7);
    // 0x80034628: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8003462C: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x80034630: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80034634: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80034638: beq         $v0, $zero, L_80034648
    if (ctx->r2 == 0) {
        // 0x8003463C: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_80034648;
    }
    // 0x8003463C: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80034640: j           L_8003467C
    // 0x80034644: sb          $v0, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r2;
        goto L_8003467C;
    // 0x80034644: sb          $v0, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r2;
L_80034648:
    // 0x80034648: lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X8);
    // 0x8003464C: sb          $zero, 0x7($s1)
    MEM_B(0X7, ctx->r17) = 0;
    // 0x80034650: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80034654: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80034658: sra         $v0, $v0, 14
    ctx->r2 = S32(SIGNED(ctx->r2) >> 14);
    // 0x8003465C: addu        $a0, $v0, $a2
    ctx->r4 = ADD32(ctx->r2, ctx->r6);
    // 0x80034660: sh          $v1, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r3;
    // 0x80034664: lb          $v0, 0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X1);
    // 0x80034668: beq         $v0, $zero, L_8003467C
    if (ctx->r2 == 0) {
        // 0x8003466C: nop
    
            goto L_8003467C;
    }
    // 0x8003466C: nop

    // 0x80034670: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x80034674: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80034678: sh          $v0, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r2;
L_8003467C:
    // 0x8003467C: lbu         $v1, 0x3($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X3);
    // 0x80034680: lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X4);
    // 0x80034684: beq         $v1, $v0, L_80034698
    if (ctx->r3 == ctx->r2) {
        // 0x80034688: nop
    
            goto L_80034698;
    }
    // 0x80034688: nop

    // 0x8003468C: sb          $v1, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r3;
    // 0x80034690: sh          $zero, 0x8($s1)
    MEM_H(0X8, ctx->r17) = 0;
    // 0x80034694: sb          $zero, 0x7($s1)
    MEM_B(0X7, ctx->r17) = 0;
L_80034698:
    // 0x80034698: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x8003469C: lbu         $a0, 0x2($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X2);
    // 0x800346A0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800346A4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800346A8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800346AC: lw          $v1, 0x70D0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X70D0);
    // 0x800346B0: lh          $v0, 0x8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X8);
    // 0x800346B4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800346B8: lb          $a1, 0x0($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X0);
    // 0x800346BC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800346C0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800346C4: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x800346C8: addiu       $s0, $s1, 0xC
    ctx->r16 = ADD32(ctx->r17, 0XC);
    // 0x800346CC: jal         0x80053234
    // 0x800346D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80053234(rdram, ctx);
        goto after_1;
    // 0x800346D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800346D4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800346D8: jal         0x80051C7C
    // 0x800346DC: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    func_80051C7C(rdram, ctx);
        goto after_2;
    // 0x800346DC: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    after_2:
L_800346E0:
    // 0x800346E0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800346E4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800346E8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800346EC: jr          $ra
    // 0x800346F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800346F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800346F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800346F4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800346F8: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x800346FC: andi        $v1, $v0, 0x1F
    ctx->r3 = ctx->r2 & 0X1F;
    // 0x80034700: slti        $v0, $v1, 0x10
    ctx->r2 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x80034704: beq         $v0, $zero, L_80034720
    if (ctx->r2 == 0) {
        // 0x80034708: slti        $v0, $v1, 0x8
        ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
            goto L_80034720;
    }
    // 0x80034708: slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8003470C: bnel        $v0, $zero, L_80034740
    if (ctx->r2 != 0) {
        // 0x80034710: srl         $v0, $v1, 31
        ctx->r2 = S32(U32(ctx->r3) >> 31);
            goto L_80034740;
    }
    goto skip_0;
    // 0x80034710: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    skip_0:
    // 0x80034714: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80034718: j           L_8003473C
    // 0x8003471C: subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
        goto L_8003473C;
    // 0x8003471C: subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
L_80034720:
    // 0x80034720: addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // 0x80034724: slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x80034728: bnel        $v0, $zero, L_8003473C
    if (ctx->r2 != 0) {
        // 0x8003472C: negu        $v1, $v1
        ctx->r3 = SUB32(0, ctx->r3);
            goto L_8003473C;
    }
    goto skip_1;
    // 0x8003472C: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    skip_1:
    // 0x80034730: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80034734: subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
    // 0x80034738: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_8003473C:
    // 0x8003473C: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
L_80034740:
    // 0x80034740: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80034744: jr          $ra
    // 0x80034748: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    return;
    // 0x80034748: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
;}
RECOMP_FUNC void func_8003474C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003474C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80034750: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80034754: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80034758: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8003475C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80034760: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80034764: beq         $v0, $zero, L_800354AC
    if (ctx->r2 == 0) {
        // 0x80034768: nop
    
            goto L_800354AC;
    }
    // 0x80034768: nop

    // 0x8003476C: lbu         $v1, 0x3($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X3);
    // 0x80034770: sltiu       $v0, $v1, 0x4
    ctx->r2 = ctx->r3 < 0X4 ? 1 : 0;
    // 0x80034774: beq         $v0, $zero, L_80034900
    if (ctx->r2 == 0) {
        // 0x80034778: nop
    
            goto L_80034900;
    }
    // 0x80034778: nop

    // 0x8003477C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80034780: lbu         $a0, 0x7B71($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B71);
    // 0x80034784: sltiu       $v0, $a0, 0x2
    ctx->r2 = ctx->r4 < 0X2 ? 1 : 0;
    // 0x80034788: beq         $v0, $zero, L_800347C4
    if (ctx->r2 == 0) {
        // 0x8003478C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800347C4;
    }
    // 0x8003478C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80034790: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80034794: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80034798: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8003479C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800347A0: lw          $v1, 0x7F38($at)
    ctx->r3 = MEM_W(ctx->r1, 0X7F38);
    // 0x800347A4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800347A8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800347AC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800347B0: lw          $v0, 0x7E74($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7E74);
    // 0x800347B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800347B8: addiu       $v0, $v0, 0x140
    ctx->r2 = ADD32(ctx->r2, 0X140);
    // 0x800347BC: j           L_8003486C
    // 0x800347C0: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
        goto L_8003486C;
    // 0x800347C0: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_800347C4:
    // 0x800347C4: bne         $a0, $v0, L_800347FC
    if (ctx->r4 != ctx->r2) {
        // 0x800347C8: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_800347FC;
    }
    // 0x800347C8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800347CC: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x800347D0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800347D4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800347D8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800347DC: lw          $v1, 0x7F38($at)
    ctx->r3 = MEM_W(ctx->r1, 0X7F38);
    // 0x800347E0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800347E4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800347E8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800347EC: lw          $v0, 0x7E74($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7E74);
    // 0x800347F0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800347F4: j           L_8003486C
    // 0x800347F8: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
        goto L_8003486C;
    // 0x800347F8: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_800347FC:
    // 0x800347FC: bne         $a0, $v0, L_8003481C
    if (ctx->r4 != ctx->r2) {
        // 0x80034800: sll         $v1, $v1, 3
        ctx->r3 = S32(ctx->r3 << 3);
            goto L_8003481C;
    }
    // 0x80034800: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80034804: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x80034808: slti        $v0, $v1, -0x63
    ctx->r2 = SIGNED(ctx->r3) < -0X63 ? 1 : 0;
    // 0x8003480C: bne         $v0, $zero, L_8003486C
    if (ctx->r2 != 0) {
        // 0x80034810: addiu       $v0, $v1, -0x6
        ctx->r2 = ADD32(ctx->r3, -0X6);
            goto L_8003486C;
    }
    // 0x80034810: addiu       $v0, $v1, -0x6
    ctx->r2 = ADD32(ctx->r3, -0X6);
    // 0x80034814: j           L_8003486C
    // 0x80034818: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
        goto L_8003486C;
    // 0x80034818: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_8003481C:
    // 0x8003481C: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80034820: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80034824: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80034828: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8003482C: lw          $a0, 0x7E74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7E74);
    // 0x80034830: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80034834: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80034838: lw          $v0, 0x7F38($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7F38);
    // 0x8003483C: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x80034840: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80034844: subu        $a1, $v1, $a0
    ctx->r5 = SUB32(ctx->r3, ctx->r4);
    // 0x80034848: bgez        $a1, L_80034854
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8003484C: addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
            goto L_80034854;
    }
    // 0x8003484C: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x80034850: addiu       $v0, $a1, 0x3
    ctx->r2 = ADD32(ctx->r5, 0X3);
L_80034854:
    // 0x80034854: sra         $a1, $v0, 2
    ctx->r5 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80034858: beq         $a1, $zero, L_80034868
    if (ctx->r5 == 0) {
        // 0x8003485C: subu        $v0, $v1, $a1
        ctx->r2 = SUB32(ctx->r3, ctx->r5);
            goto L_80034868;
    }
    // 0x8003485C: subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
    // 0x80034860: j           L_8003486C
    // 0x80034864: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
        goto L_8003486C;
    // 0x80034864: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_80034868:
    // 0x80034868: sw          $a0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r4;
L_8003486C:
    // 0x8003486C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80034870: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80034874: andi        $v1, $v0, 0x1F
    ctx->r3 = ctx->r2 & 0X1F;
    // 0x80034878: slti        $v0, $v1, 0x10
    ctx->r2 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x8003487C: beq         $v0, $zero, L_80034898
    if (ctx->r2 == 0) {
        // 0x80034880: slti        $v0, $v1, 0x8
        ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
            goto L_80034898;
    }
    // 0x80034880: slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x80034884: bne         $v0, $zero, L_800348B8
    if (ctx->r2 != 0) {
        // 0x80034888: srl         $v0, $v1, 31
        ctx->r2 = S32(U32(ctx->r3) >> 31);
            goto L_800348B8;
    }
    // 0x80034888: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // 0x8003488C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80034890: j           L_800348B4
    // 0x80034894: subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
        goto L_800348B4;
    // 0x80034894: subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
L_80034898:
    // 0x80034898: addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // 0x8003489C: slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x800348A0: bnel        $v0, $zero, L_800348B4
    if (ctx->r2 != 0) {
        // 0x800348A4: negu        $v1, $v1
        ctx->r3 = SUB32(0, ctx->r3);
            goto L_800348B4;
    }
    goto skip_0;
    // 0x800348A4: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    skip_0:
    // 0x800348A8: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800348AC: subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
    // 0x800348B0: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_800348B4:
    // 0x800348B4: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
L_800348B8:
    // 0x800348B8: lbu         $a0, 0x3($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X3);
    // 0x800348BC: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800348C0: sra         $a1, $v0, 1
    ctx->r5 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800348C4: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x800348C8: bnel        $v0, $zero, L_800348D0
    if (ctx->r2 != 0) {
        // 0x800348CC: negu        $a1, $a1
        ctx->r5 = SUB32(0, ctx->r5);
            goto L_800348D0;
    }
    goto skip_1;
    // 0x800348CC: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    skip_1:
L_800348D0:
    // 0x800348D0: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x800348D4: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x800348D8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800348DC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800348E0: lw          $v1, 0x7F3C($at)
    ctx->r3 = MEM_W(ctx->r1, 0X7F3C);
    // 0x800348E4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800348E8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800348EC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800348F0: lw          $v0, 0x7E78($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7E78);
    // 0x800348F4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800348F8: j           L_800349B0
    // 0x800348FC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
        goto L_800349B0;
    // 0x800348FC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
L_80034900:
    // 0x80034900: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80034904: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x80034908: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x8003490C: beql        $v0, $zero, L_80034930
    if (ctx->r2 == 0) {
        // 0x80034910: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80034930;
    }
    goto skip_2;
    // 0x80034910: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_2:
    // 0x80034914: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80034918: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003491C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80034920: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80034924: lw          $v0, 0x7F38($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7F38);
    // 0x80034928: j           L_80034998
    // 0x8003492C: addiu       $v0, $v0, 0x140
    ctx->r2 = ADD32(ctx->r2, 0X140);
        goto L_80034998;
    // 0x8003492C: addiu       $v0, $v0, 0x140
    ctx->r2 = ADD32(ctx->r2, 0X140);
L_80034930:
    // 0x80034930: bne         $v1, $v0, L_80034964
    if (ctx->r3 != ctx->r2) {
        // 0x80034934: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_80034964;
    }
    // 0x80034934: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80034938: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x8003493C: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x80034940: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80034944: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80034948: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8003494C: lw          $v0, 0x7F38($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7F38);
    // 0x80034950: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80034954: beq         $v0, $zero, L_8003499C
    if (ctx->r2 == 0) {
        // 0x80034958: addiu       $v0, $v1, -0x6
        ctx->r2 = ADD32(ctx->r3, -0X6);
            goto L_8003499C;
    }
    // 0x80034958: addiu       $v0, $v1, -0x6
    ctx->r2 = ADD32(ctx->r3, -0X6);
    // 0x8003495C: j           L_8003499C
    // 0x80034960: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
        goto L_8003499C;
    // 0x80034960: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_80034964:
    // 0x80034964: bne         $v1, $v0, L_80034984
    if (ctx->r3 != ctx->r2) {
        // 0x80034968: nop
    
            goto L_80034984;
    }
    // 0x80034968: nop

    // 0x8003496C: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x80034970: slti        $v0, $v1, -0x63
    ctx->r2 = SIGNED(ctx->r3) < -0X63 ? 1 : 0;
    // 0x80034974: bne         $v0, $zero, L_8003499C
    if (ctx->r2 != 0) {
        // 0x80034978: addiu       $v0, $v1, -0x6
        ctx->r2 = ADD32(ctx->r3, -0X6);
            goto L_8003499C;
    }
    // 0x80034978: addiu       $v0, $v1, -0x6
    ctx->r2 = ADD32(ctx->r3, -0X6);
    // 0x8003497C: j           L_8003499C
    // 0x80034980: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
        goto L_8003499C;
    // 0x80034980: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_80034984:
    // 0x80034984: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80034988: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003498C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80034990: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80034994: lw          $v0, 0x7F38($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7F38);
L_80034998:
    // 0x80034998: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
L_8003499C:
    // 0x8003499C: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x800349A0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800349A4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800349A8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800349AC: lw          $v0, 0x7F3C($at)
    ctx->r2 = MEM_W(ctx->r1, 0X7F3C);
L_800349B0:
    // 0x800349B0: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // 0x800349B4: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x800349B8: addiu       $v0, $v1, -0x5
    ctx->r2 = ADD32(ctx->r3, -0X5);
    // 0x800349BC: sltiu       $v0, $v0, 0x8
    ctx->r2 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x800349C0: beq         $v0, $zero, L_80034ADC
    if (ctx->r2 == 0) {
        // 0x800349C4: andi        $v1, $v1, 0xFF
        ctx->r3 = ctx->r3 & 0XFF;
            goto L_80034ADC;
    }
    // 0x800349C4: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x800349C8: sltiu       $v0, $v1, 0x9
    ctx->r2 = ctx->r3 < 0X9 ? 1 : 0;
    // 0x800349CC: beql        $v0, $zero, L_80034A34
    if (ctx->r2 == 0) {
        // 0x800349D0: addiu       $v1, $v1, -0x9
        ctx->r3 = ADD32(ctx->r3, -0X9);
            goto L_80034A34;
    }
    goto skip_3;
    // 0x800349D0: addiu       $v1, $v1, -0x9
    ctx->r3 = ADD32(ctx->r3, -0X9);
    skip_3:
    // 0x800349D4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800349D8: lb          $v0, 0x515C($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X515C);
    // 0x800349DC: addiu       $v1, $v1, -0x5
    ctx->r3 = ADD32(ctx->r3, -0X5);
    // 0x800349E0: beq         $v1, $v0, L_800349F8
    if (ctx->r3 == ctx->r2) {
        // 0x800349E4: nop
    
            goto L_800349F8;
    }
    // 0x800349E4: nop

    // 0x800349E8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800349EC: lb          $v0, 0x515D($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X515D);
    // 0x800349F0: bne         $v1, $v0, L_80034A90
    if (ctx->r3 != ctx->r2) {
        // 0x800349F4: nop
    
            goto L_80034A90;
    }
    // 0x800349F4: nop

L_800349F8:
    // 0x800349F8: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800349FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80034A00: ldc1        $f0, -0x2800($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2800);
    // 0x80034A04: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80034A08: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x80034A0C: nop

    // 0x80034A10: bc1f        L_80034AF0
    if (!c1cs) {
        // 0x80034A14: nop
    
            goto L_80034AF0;
    }
    // 0x80034A14: nop

    // 0x80034A18: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80034A1C: ldc1        $f0, -0x27F8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X27F8);
    // 0x80034A20: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80034A24: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
    // 0x80034A28: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x80034A2C: j           L_80034AC8
    // 0x80034A30: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
        goto L_80034AC8;
    // 0x80034A30: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
L_80034A34:
    // 0x80034A34: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80034A38: lb          $v0, 0x515C($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X515C);
    // 0x80034A3C: beq         $v1, $v0, L_80034A54
    if (ctx->r3 == ctx->r2) {
        // 0x80034A40: nop
    
            goto L_80034A54;
    }
    // 0x80034A40: nop

    // 0x80034A44: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80034A48: lb          $v0, 0x515D($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X515D);
    // 0x80034A4C: bne         $v1, $v0, L_80034A90
    if (ctx->r3 != ctx->r2) {
        // 0x80034A50: nop
    
            goto L_80034A90;
    }
    // 0x80034A50: nop

L_80034A54:
    // 0x80034A54: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80034A58: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80034A5C: ldc1        $f0, -0x27F0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X27F0);
    // 0x80034A60: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80034A64: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x80034A68: nop

    // 0x80034A6C: bc1f        L_80034AF0
    if (!c1cs) {
        // 0x80034A70: nop
    
            goto L_80034AF0;
    }
    // 0x80034A70: nop

    // 0x80034A74: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80034A78: ldc1        $f0, -0x27E8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X27E8);
    // 0x80034A7C: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80034A80: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
    // 0x80034A84: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x80034A88: j           L_80034AC8
    // 0x80034A8C: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
        goto L_80034AC8;
    // 0x80034A8C: add.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d + ctx->f0.d;
L_80034A90:
    // 0x80034A90: lwc1        $f2, 0x1C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80034A94: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80034A98: ldc1        $f0, -0x27E0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X27E0);
    // 0x80034A9C: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80034AA0: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x80034AA4: nop

    // 0x80034AA8: bc1f        L_80034AF0
    if (!c1cs) {
        // 0x80034AAC: nop
    
            goto L_80034AF0;
    }
    // 0x80034AAC: nop

    // 0x80034AB0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80034AB4: ldc1        $f0, -0x27D8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X27D8);
    // 0x80034AB8: lwc1        $f2, 0x20($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80034ABC: sub.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d - ctx->f0.d;
    // 0x80034AC0: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x80034AC4: sub.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d - ctx->f0.d;
L_80034AC8:
    // 0x80034AC8: cvt.s.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
    // 0x80034ACC: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x80034AD0: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x80034AD4: j           L_80034AF0
    // 0x80034AD8: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
        goto L_80034AF0;
    // 0x80034AD8: swc1        $f2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f2.u32l;
L_80034ADC:
    // 0x80034ADC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80034AE0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80034AE4: nop

    // 0x80034AE8: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x80034AEC: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
L_80034AF0:
    // 0x80034AF0: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x80034AF4: lbu         $a2, 0x3($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X3);
    // 0x80034AF8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80034AFC: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80034B00: lb          $a1, 0x70F0($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X70F0);
    // 0x80034B04: addiu       $s0, $s1, 0xC
    ctx->r16 = ADD32(ctx->r17, 0XC);
    // 0x80034B08: jal         0x80053234
    // 0x80034B0C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80053234(rdram, ctx);
        goto after_0;
    // 0x80034B0C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80034B10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80034B14: jal         0x80051C7C
    // 0x80034B18: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    func_80051C7C(rdram, ctx);
        goto after_1;
    // 0x80034B18: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    after_1:
    // 0x80034B1C: lbu         $v1, 0x3($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X3);
    // 0x80034B20: sltiu       $v0, $v1, 0x4
    ctx->r2 = ctx->r3 < 0X4 ? 1 : 0;
    // 0x80034B24: beq         $v0, $zero, L_800354AC
    if (ctx->r2 == 0) {
        // 0x80034B28: nop
    
            goto L_800354AC;
    }
    // 0x80034B28: nop

    // 0x80034B2C: lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1);
    // 0x80034B30: bne         $v0, $zero, L_8003511C
    if (ctx->r2 != 0) {
        // 0x80034B34: andi        $v0, $v1, 0x1
        ctx->r2 = ctx->r3 & 0X1;
            goto L_8003511C;
    }
    // 0x80034B34: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x80034B38: bne         $v0, $zero, L_800354AC
    if (ctx->r2 != 0) {
        // 0x80034B3C: nop
    
            goto L_800354AC;
    }
    // 0x80034B3C: nop

    // 0x80034B40: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80034B44: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80034B48: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80034B4C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80034B50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80034B54: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80034B58: lhu         $v1, -0x33C8($at)
    ctx->r3 = MEM_HU(ctx->r1, -0X33C8);
    // 0x80034B5C: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x80034B60: beq         $v0, $zero, L_80034BBC
    if (ctx->r2 == 0) {
        // 0x80034B64: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80034BBC;
    }
    // 0x80034B64: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80034B68: lbu         $a0, 0x6($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X6);
    // 0x80034B6C: sltiu       $v0, $a0, 0x3
    ctx->r2 = ctx->r4 < 0X3 ? 1 : 0;
    // 0x80034B70: beq         $v0, $zero, L_80034C14
    if (ctx->r2 == 0) {
        // 0x80034B74: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80034C14;
    }
    // 0x80034B74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80034B78: lbu         $v0, 0x3($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3);
    // 0x80034B7C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80034B80: sb          $a0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r4;
    // 0x80034B84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80034B88: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80034B8C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80034B90: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80034B94: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80034B98: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80034B9C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034BA0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80034BA4: sb          $a0, -0x7A6A($at)
    MEM_B(-0X7A6A, ctx->r1) = ctx->r4;
    // 0x80034BA8: lbu         $a1, 0x5($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X5);
    // 0x80034BAC: jal         0x8000637C
    // 0x80034BB0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8000637C(rdram, ctx);
        goto after_2;
    // 0x80034BB0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x80034BB4: j           L_80034C14
    // 0x80034BB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80034C14;
    // 0x80034BB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80034BBC:
    // 0x80034BBC: andi        $v0, $v1, 0x200
    ctx->r2 = ctx->r3 & 0X200;
    // 0x80034BC0: beq         $v0, $zero, L_80034C14
    if (ctx->r2 == 0) {
        // 0x80034BC4: nop
    
            goto L_80034C14;
    }
    // 0x80034BC4: nop

    // 0x80034BC8: lbu         $a0, 0x6($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X6);
    // 0x80034BCC: beq         $a0, $zero, L_80034C14
    if (ctx->r4 == 0) {
        // 0x80034BD0: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_80034C14;
    }
    // 0x80034BD0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80034BD4: lbu         $v0, 0x3($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3);
    // 0x80034BD8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80034BDC: sb          $a0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r4;
    // 0x80034BE0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80034BE4: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80034BE8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80034BEC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80034BF0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80034BF4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80034BF8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034BFC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80034C00: sb          $a0, -0x7A6A($at)
    MEM_B(-0X7A6A, ctx->r1) = ctx->r4;
    // 0x80034C04: lbu         $a1, 0x5($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X5);
    // 0x80034C08: jal         0x8000637C
    // 0x80034C0C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8000637C(rdram, ctx);
        goto after_3;
    // 0x80034C0C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x80034C10: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_80034C14:
    // 0x80034C14: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80034C18: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x80034C1C: beq         $v0, $zero, L_80034D44
    if (ctx->r2 == 0) {
        // 0x80034C20: nop
    
            goto L_80034D44;
    }
    // 0x80034C20: nop

    // 0x80034C24: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80034C28: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x80034C2C: beq         $v0, $zero, L_80034D44
    if (ctx->r2 == 0) {
        // 0x80034C30: nop
    
            goto L_80034D44;
    }
    // 0x80034C30: nop

    // 0x80034C34: lbu         $v0, 0x3($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3);
    // 0x80034C38: beq         $v0, $zero, L_80034CAC
    if (ctx->r2 == 0) {
        // 0x80034C3C: nop
    
            goto L_80034CAC;
    }
    // 0x80034C3C: nop

    // 0x80034C40: lbu         $a1, 0x6($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X6);
    // 0x80034C44: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80034C48: lb          $v0, 0x515C($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X515C);
    // 0x80034C4C: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80034C50: bne         $a0, $v0, L_80034D44
    if (ctx->r4 != ctx->r2) {
        // 0x80034C54: nop
    
            goto L_80034D44;
    }
    // 0x80034C54: nop

    // 0x80034C58: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x80034C5C: lbu         $v0, -0x7A6F($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7A6F);
    // 0x80034C60: beq         $v0, $zero, L_80034D44
    if (ctx->r2 == 0) {
        // 0x80034C64: andi        $v1, $a2, 0xFF
        ctx->r3 = ctx->r6 & 0XFF;
            goto L_80034D44;
    }
    // 0x80034C64: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x80034C68: bltz        $v1, L_80034D18
    if (SIGNED(ctx->r3) < 0) {
        // 0x80034C6C: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80034D18;
    }
    // 0x80034C6C: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80034C70: bne         $v0, $zero, L_80034C8C
    if (ctx->r2 != 0) {
        // 0x80034C74: sltiu       $v0, $a0, 0x3
        ctx->r2 = ctx->r4 < 0X3 ? 1 : 0;
            goto L_80034C8C;
    }
    // 0x80034C74: sltiu       $v0, $a0, 0x3
    ctx->r2 = ctx->r4 < 0X3 ? 1 : 0;
    // 0x80034C78: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80034C7C: beq         $v1, $v0, L_80034C9C
    if (ctx->r3 == ctx->r2) {
        // 0x80034C80: nop
    
            goto L_80034C9C;
    }
    // 0x80034C80: nop

    // 0x80034C84: j           L_80034D18
    // 0x80034C88: nop

        goto L_80034D18;
    // 0x80034C88: nop

L_80034C8C:
    // 0x80034C8C: bne         $v0, $zero, L_80034D14
    if (ctx->r2 != 0) {
        // 0x80034C90: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_80034D14;
    }
    // 0x80034C90: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x80034C94: j           L_80034D14
    // 0x80034C98: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
        goto L_80034D14;
    // 0x80034C98: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
L_80034C9C:
    // 0x80034C9C: beq         $a0, $zero, L_80034D10
    if (ctx->r4 == 0) {
        // 0x80034CA0: addiu       $v0, $a1, -0x1
        ctx->r2 = ADD32(ctx->r5, -0X1);
            goto L_80034D10;
    }
    // 0x80034CA0: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x80034CA4: j           L_80034D18
    // 0x80034CA8: sb          $v0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r2;
        goto L_80034D18;
    // 0x80034CA8: sb          $v0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r2;
L_80034CAC:
    // 0x80034CAC: lbu         $a1, 0x6($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X6);
    // 0x80034CB0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80034CB4: lb          $v0, 0x515D($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X515D);
    // 0x80034CB8: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80034CBC: bne         $a0, $v0, L_80034D44
    if (ctx->r4 != ctx->r2) {
        // 0x80034CC0: nop
    
            goto L_80034D44;
    }
    // 0x80034CC0: nop

    // 0x80034CC4: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x80034CC8: lbu         $v0, -0x7A07($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7A07);
    // 0x80034CCC: beq         $v0, $zero, L_80034D44
    if (ctx->r2 == 0) {
        // 0x80034CD0: andi        $v1, $a2, 0xFF
        ctx->r3 = ctx->r6 & 0XFF;
            goto L_80034D44;
    }
    // 0x80034CD0: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x80034CD4: bltz        $v1, L_80034D18
    if (SIGNED(ctx->r3) < 0) {
        // 0x80034CD8: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80034D18;
    }
    // 0x80034CD8: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80034CDC: bne         $v0, $zero, L_80034CF8
    if (ctx->r2 != 0) {
        // 0x80034CE0: sltiu       $v0, $a0, 0x3
        ctx->r2 = ctx->r4 < 0X3 ? 1 : 0;
            goto L_80034CF8;
    }
    // 0x80034CE0: sltiu       $v0, $a0, 0x3
    ctx->r2 = ctx->r4 < 0X3 ? 1 : 0;
    // 0x80034CE4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80034CE8: beq         $v1, $v0, L_80034D08
    if (ctx->r3 == ctx->r2) {
        // 0x80034CEC: nop
    
            goto L_80034D08;
    }
    // 0x80034CEC: nop

    // 0x80034CF0: j           L_80034D18
    // 0x80034CF4: nop

        goto L_80034D18;
    // 0x80034CF4: nop

L_80034CF8:
    // 0x80034CF8: bne         $v0, $zero, L_80034D14
    if (ctx->r2 != 0) {
        // 0x80034CFC: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_80034D14;
    }
    // 0x80034CFC: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x80034D00: j           L_80034D14
    // 0x80034D04: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
        goto L_80034D14;
    // 0x80034D04: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
L_80034D08:
    // 0x80034D08: bne         $a0, $zero, L_80034D14
    if (ctx->r4 != 0) {
        // 0x80034D0C: addiu       $v0, $a1, -0x1
        ctx->r2 = ADD32(ctx->r5, -0X1);
            goto L_80034D14;
    }
    // 0x80034D0C: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
L_80034D10:
    // 0x80034D10: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
L_80034D14:
    // 0x80034D14: sb          $v0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r2;
L_80034D18:
    // 0x80034D18: lbu         $v0, 0x3($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3);
    // 0x80034D1C: lbu         $a0, 0x6($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X6);
    // 0x80034D20: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80034D24: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80034D28: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80034D2C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80034D30: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80034D34: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80034D38: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034D3C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80034D40: sb          $a0, -0x7A6A($at)
    MEM_B(-0X7A6A, ctx->r1) = ctx->r4;
L_80034D44:
    // 0x80034D44: lbu         $v0, 0x3($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3);
    // 0x80034D48: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x80034D4C: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x80034D50: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80034D54: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80034D58: sb          $v1, 0x515C($at)
    MEM_B(0X515C, ctx->r1) = ctx->r3;
    // 0x80034D5C: lbu         $a1, 0x5($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X5);
    // 0x80034D60: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x80034D64: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80034D68: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80034D6C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80034D70: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80034D74: lhu         $v0, -0x33C8($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X33C8);
    // 0x80034D78: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x80034D7C: beq         $v0, $zero, L_80034EAC
    if (ctx->r2 == 0) {
        // 0x80034D80: nop
    
            goto L_80034EAC;
    }
    // 0x80034D80: nop

    // 0x80034D84: lbu         $v1, 0x3($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X3);
    // 0x80034D88: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x80034D8C: bne         $v0, $zero, L_80034EAC
    if (ctx->r2 != 0) {
        // 0x80034D90: nop
    
            goto L_80034EAC;
    }
    // 0x80034D90: nop

    // 0x80034D94: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80034D98: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x80034D9C: beq         $v0, $zero, L_80034E0C
    if (ctx->r2 == 0) {
        // 0x80034DA0: nop
    
            goto L_80034E0C;
    }
    // 0x80034DA0: nop

    // 0x80034DA4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80034DA8: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x80034DAC: beq         $v0, $zero, L_80034E0C
    if (ctx->r2 == 0) {
        // 0x80034DB0: nop
    
            goto L_80034E0C;
    }
    // 0x80034DB0: nop

    // 0x80034DB4: beq         $v1, $zero, L_80034DE8
    if (ctx->r3 == 0) {
        // 0x80034DB8: nop
    
            goto L_80034DE8;
    }
    // 0x80034DB8: nop

    // 0x80034DBC: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x80034DC0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80034DC4: lb          $v0, 0x515C($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X515C);
    // 0x80034DC8: bne         $v1, $v0, L_80034E14
    if (ctx->r3 != ctx->r2) {
        // 0x80034DCC: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_80034E14;
    }
    // 0x80034DCC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80034DD0: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x80034DD4: lbu         $v0, -0x7A6F($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7A6F);
    // 0x80034DD8: beq         $v0, $zero, L_80034E14
    if (ctx->r2 == 0) {
        // 0x80034DDC: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_80034E14;
    }
    // 0x80034DDC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80034DE0: j           L_800354A4
    // 0x80034DE4: nop

        goto L_800354A4;
    // 0x80034DE4: nop

L_80034DE8:
    // 0x80034DE8: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x80034DEC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80034DF0: lb          $v0, 0x515D($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X515D);
    // 0x80034DF4: bne         $v1, $v0, L_80034E14
    if (ctx->r3 != ctx->r2) {
        // 0x80034DF8: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_80034E14;
    }
    // 0x80034DF8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80034DFC: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x80034E00: lbu         $v0, -0x7A07($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7A07);
    // 0x80034E04: bne         $v0, $zero, L_800354A4
    if (ctx->r2 != 0) {
        // 0x80034E08: nop
    
            goto L_800354A4;
    }
    // 0x80034E08: nop

L_80034E0C:
    // 0x80034E0C: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x80034E10: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
L_80034E14:
    // 0x80034E14: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80034E18: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80034E1C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80034E20: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80034E24: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80034E28: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80034E2C: lbu         $v1, 0x447C($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X447C);
    // 0x80034E30: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x80034E34: bne         $v1, $v0, L_800354AC
    if (ctx->r3 != ctx->r2) {
        // 0x80034E38: nop
    
            goto L_800354AC;
    }
    // 0x80034E38: nop

    // 0x80034E3C: lbu         $a1, 0x5($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X5);
    // 0x80034E40: jal         0x8000637C
    // 0x80034E44: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_8000637C(rdram, ctx);
        goto after_4;
    // 0x80034E44: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_4:
    // 0x80034E48: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x80034E4C: lbu         $a0, 0x5($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X5);
    // 0x80034E50: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80034E54: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80034E58: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80034E5C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80034E60: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80034E64: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80034E68: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80034E6C: sb          $a0, 0x447D($at)
    MEM_B(0X447D, ctx->r1) = ctx->r4;
    // 0x80034E70: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x80034E74: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80034E78: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80034E7C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80034E80: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80034E84: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80034E88: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80034E8C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80034E90: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80034E94: sb          $v1, 0x447B($at)
    MEM_B(0X447B, ctx->r1) = ctx->r3;
    // 0x80034E98: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80034E9C: beq         $v0, $zero, L_80035058
    if (ctx->r2 == 0) {
        // 0x80034EA0: nop
    
            goto L_80035058;
    }
    // 0x80034EA0: nop

    // 0x80034EA4: j           L_80035024
    // 0x80034EA8: nop

        goto L_80035024;
    // 0x80034EA8: nop

L_80034EAC:
    // 0x80034EAC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80034EB0: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x80034EB4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80034EB8: bne         $v1, $v0, L_800354AC
    if (ctx->r3 != ctx->r2) {
        // 0x80034EBC: nop
    
            goto L_800354AC;
    }
    // 0x80034EBC: nop

    // 0x80034EC0: lbu         $v1, 0x3($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X3);
    // 0x80034EC4: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x80034EC8: bne         $v0, $zero, L_800354AC
    if (ctx->r2 != 0) {
        // 0x80034ECC: nop
    
            goto L_800354AC;
    }
    // 0x80034ECC: nop

    // 0x80034ED0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80034ED4: lbu         $v0, -0x4FB0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4FB0);
    // 0x80034ED8: bne         $v0, $zero, L_800354AC
    if (ctx->r2 != 0) {
        // 0x80034EDC: nop
    
            goto L_800354AC;
    }
    // 0x80034EDC: nop

    // 0x80034EE0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80034EE4: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x80034EE8: beq         $v0, $zero, L_80034FA4
    if (ctx->r2 == 0) {
        // 0x80034EEC: nop
    
            goto L_80034FA4;
    }
    // 0x80034EEC: nop

    // 0x80034EF0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80034EF4: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x80034EF8: beq         $v0, $zero, L_80034FA4
    if (ctx->r2 == 0) {
        // 0x80034EFC: nop
    
            goto L_80034FA4;
    }
    // 0x80034EFC: nop

    // 0x80034F00: beq         $v1, $zero, L_80034F40
    if (ctx->r3 == 0) {
        // 0x80034F04: nop
    
            goto L_80034F40;
    }
    // 0x80034F04: nop

    // 0x80034F08: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x80034F0C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80034F10: lb          $v0, 0x515C($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X515C);
    // 0x80034F14: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x80034F18: bne         $a0, $v0, L_80034FA4
    if (ctx->r4 != ctx->r2) {
        // 0x80034F1C: nop
    
            goto L_80034FA4;
    }
    // 0x80034F1C: nop

    // 0x80034F20: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x80034F24: lbu         $v0, -0x7A6F($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7A6F);
    // 0x80034F28: beq         $v0, $zero, L_80034FA4
    if (ctx->r2 == 0) {
        // 0x80034F2C: sltiu       $v0, $a0, 0x3
        ctx->r2 = ctx->r4 < 0X3 ? 1 : 0;
            goto L_80034FA4;
    }
    // 0x80034F2C: sltiu       $v0, $a0, 0x3
    ctx->r2 = ctx->r4 < 0X3 ? 1 : 0;
    // 0x80034F30: beq         $v0, $zero, L_80034F70
    if (ctx->r2 == 0) {
        // 0x80034F34: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80034F70;
    }
    // 0x80034F34: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80034F38: j           L_80034F78
    // 0x80034F3C: sb          $v0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r2;
        goto L_80034F78;
    // 0x80034F3C: sb          $v0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r2;
L_80034F40:
    // 0x80034F40: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x80034F44: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80034F48: lb          $v0, 0x515D($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X515D);
    // 0x80034F4C: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x80034F50: bne         $a0, $v0, L_80034FA4
    if (ctx->r4 != ctx->r2) {
        // 0x80034F54: nop
    
            goto L_80034FA4;
    }
    // 0x80034F54: nop

    // 0x80034F58: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x80034F5C: lbu         $v0, -0x7A07($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7A07);
    // 0x80034F60: beq         $v0, $zero, L_80034FA4
    if (ctx->r2 == 0) {
        // 0x80034F64: sltiu       $v0, $a0, 0x3
        ctx->r2 = ctx->r4 < 0X3 ? 1 : 0;
            goto L_80034FA4;
    }
    // 0x80034F64: sltiu       $v0, $a0, 0x3
    ctx->r2 = ctx->r4 < 0X3 ? 1 : 0;
    // 0x80034F68: bne         $v0, $zero, L_80034F74
    if (ctx->r2 != 0) {
        // 0x80034F6C: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_80034F74;
    }
    // 0x80034F6C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_80034F70:
    // 0x80034F70: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
L_80034F74:
    // 0x80034F74: sb          $v0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r2;
L_80034F78:
    // 0x80034F78: lbu         $v0, 0x3($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3);
    // 0x80034F7C: lbu         $a0, 0x6($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X6);
    // 0x80034F80: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80034F84: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80034F88: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80034F8C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80034F90: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80034F94: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80034F98: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80034F9C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80034FA0: sb          $a0, -0x7A6A($at)
    MEM_B(-0X7A6A, ctx->r1) = ctx->r4;
L_80034FA4:
    // 0x80034FA4: lbu         $v0, 0x3($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3);
    // 0x80034FA8: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x80034FAC: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x80034FB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80034FB4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80034FB8: sb          $v1, 0x515C($at)
    MEM_B(0X515C, ctx->r1) = ctx->r3;
    // 0x80034FBC: lbu         $a1, 0x5($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X5);
    // 0x80034FC0: jal         0x8000637C
    // 0x80034FC4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_8000637C(rdram, ctx);
        goto after_5;
    // 0x80034FC4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_5:
    // 0x80034FC8: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x80034FCC: lbu         $a0, 0x5($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X5);
    // 0x80034FD0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80034FD4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80034FD8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80034FDC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80034FE0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80034FE4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80034FE8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80034FEC: sb          $a0, 0x447D($at)
    MEM_B(0X447D, ctx->r1) = ctx->r4;
    // 0x80034FF0: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x80034FF4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80034FF8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80034FFC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80035000: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80035004: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80035008: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x8003500C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80035010: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80035014: sb          $v1, 0x447B($at)
    MEM_B(0X447B, ctx->r1) = ctx->r3;
    // 0x80035018: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x8003501C: beq         $v0, $zero, L_80035058
    if (ctx->r2 == 0) {
        // 0x80035020: nop
    
            goto L_80035058;
    }
    // 0x80035020: nop

L_80035024:
    // 0x80035024: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x80035028: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8003502C: addiu       $a1, $a1, 0x7B8B
    ctx->r5 = ADD32(ctx->r5, 0X7B8B);
    // 0x80035030: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80035034: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80035038: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8003503C: lbu         $a0, 0x7E2C($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7E2C);
    // 0x80035040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80035044: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80035048: sb          $v0, 0x7A43($at)
    MEM_B(0X7A43, ctx->r1) = ctx->r2;
    // 0x8003504C: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x80035050: j           L_8003508C
    // 0x80035054: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
        goto L_8003508C;
    // 0x80035054: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
L_80035058:
    // 0x80035058: lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6);
    // 0x8003505C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80035060: addiu       $a1, $a1, 0x7B8B
    ctx->r5 = ADD32(ctx->r5, 0X7B8B);
    // 0x80035064: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x80035068: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8003506C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80035070: lbu         $v1, 0x7E2C($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7E2C);
    // 0x80035074: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80035078: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8003507C: sb          $v0, 0x25F3($at)
    MEM_B(0X25F3, ctx->r1) = ctx->r2;
    // 0x80035080: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80035084: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x80035088: sb          $a0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r4;
L_8003508C:
    // 0x8003508C: lbu         $v1, 0x1($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X1);
    // 0x80035090: lbu         $a0, 0x3($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X3);
    // 0x80035094: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80035098: sb          $v0, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r2;
    // 0x8003509C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800350A0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800350A4: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x800350A8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800350AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800350B0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800350B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800350B8: sb          $v1, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r3;
    // 0x800350BC: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x800350C0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800350C4: lbu         $v1, -0x7A6F($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X7A6F);
    // 0x800350C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800350CC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800350D0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800350D4: sb          $v1, -0x7A6F($at)
    MEM_B(-0X7A6F, ctx->r1) = ctx->r3;
    // 0x800350D8: lbu         $v1, 0x3($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X3);
    // 0x800350DC: lbu         $a0, 0x6($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X6);
    // 0x800350E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800350E4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800350E8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800350EC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800350F0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800350F4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800350F8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800350FC: addiu       $v1, $v1, 0x7B76
    ctx->r3 = ADD32(ctx->r3, 0X7B76);
    // 0x80035100: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80035104: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80035108: sb          $a0, -0x7A6A($at)
    MEM_B(-0X7A6A, ctx->r1) = ctx->r4;
    // 0x8003510C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80035110: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80035114: j           L_800354AC
    // 0x80035118: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
        goto L_800354AC;
    // 0x80035118: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8003511C:
    // 0x8003511C: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x80035120: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80035124: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80035128: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003512C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80035130: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x80035134: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80035138: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8003513C: lbu         $v1, 0x447C($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X447C);
    // 0x80035140: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x80035144: bne         $v1, $v0, L_80035158
    if (ctx->r3 != ctx->r2) {
        // 0x80035148: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_80035158;
    }
    // 0x80035148: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8003514C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80035150: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80035154: sb          $v0, 0x447B($at)
    MEM_B(0X447B, ctx->r1) = ctx->r2;
L_80035158:
    // 0x80035158: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x8003515C: bne         $v0, $zero, L_80035214
    if (ctx->r2 != 0) {
        // 0x80035160: nop
    
            goto L_80035214;
    }
    // 0x80035160: nop

    // 0x80035164: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80035168: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x8003516C: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80035170: beq         $v0, $zero, L_800351C0
    if (ctx->r2 == 0) {
        // 0x80035174: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800351C0;
    }
    // 0x80035174: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80035178: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8003517C: lw          $a2, -0xBF0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0XBF0);
    // 0x80035180: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80035184: addiu       $a3, $a3, -0x2F30
    ctx->r7 = ADD32(ctx->r7, -0X2F30);
L_80035188:
    // 0x80035188: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x8003518C: sra         $v1, $v1, 15
    ctx->r3 = S32(SIGNED(ctx->r3) >> 15);
    // 0x80035190: addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // 0x80035194: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x80035198: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x8003519C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800351A0: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800351A4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800351A8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800351AC: slti        $v0, $v0, 0xF
    ctx->r2 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x800351B0: bne         $v0, $zero, L_80035188
    if (ctx->r2 != 0) {
        // 0x800351B4: sh          $a0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r4;
            goto L_80035188;
    }
    // 0x800351B4: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x800351B8: j           L_800352C8
    // 0x800351BC: nop

        goto L_800352C8;
    // 0x800351BC: nop

L_800351C0:
    // 0x800351C0: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x800351C4: lw          $a2, -0xBF0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0XBF0);
    // 0x800351C8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x800351CC: addiu       $a3, $a3, -0x2F30
    ctx->r7 = ADD32(ctx->r7, -0X2F30);
L_800351D0:
    // 0x800351D0: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x800351D4: addiu       $a0, $a1, 0x1
    ctx->r4 = ADD32(ctx->r5, 0X1);
    // 0x800351D8: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800351DC: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800351E0: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x800351E4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800351E8: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800351EC: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800351F0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800351F4: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800351F8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800351FC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80035200: slti        $a0, $a0, 0xF
    ctx->r4 = SIGNED(ctx->r4) < 0XF ? 1 : 0;
    // 0x80035204: bne         $a0, $zero, L_800351D0
    if (ctx->r4 != 0) {
        // 0x80035208: sh          $v0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r2;
            goto L_800351D0;
    }
    // 0x80035208: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8003520C: j           L_800352C8
    // 0x80035210: nop

        goto L_800352C8;
    // 0x80035210: nop

L_80035214:
    // 0x80035214: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80035218: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x8003521C: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80035220: beq         $v0, $zero, L_8003527C
    if (ctx->r2 == 0) {
        // 0x80035224: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8003527C;
    }
    // 0x80035224: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80035228: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8003522C: lw          $a2, -0xBF0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0XBF0);
    // 0x80035230: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80035234: addiu       $a3, $a3, -0x2F10
    ctx->r7 = ADD32(ctx->r7, -0X2F10);
L_80035238:
    // 0x80035238: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x8003523C: addiu       $a0, $a1, 0x1
    ctx->r4 = ADD32(ctx->r5, 0X1);
    // 0x80035240: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80035244: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80035248: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x8003524C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80035250: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80035254: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80035258: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8003525C: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80035260: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80035264: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80035268: slti        $a0, $a0, 0xF
    ctx->r4 = SIGNED(ctx->r4) < 0XF ? 1 : 0;
    // 0x8003526C: bne         $a0, $zero, L_80035238
    if (ctx->r4 != 0) {
        // 0x80035270: sh          $v0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r2;
            goto L_80035238;
    }
    // 0x80035270: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80035274: j           L_800352C8
    // 0x80035278: nop

        goto L_800352C8;
    // 0x80035278: nop

L_8003527C:
    // 0x8003527C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80035280: lw          $a2, -0xBF0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0XBF0);
    // 0x80035284: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80035288: addiu       $a3, $a3, -0x2F10
    ctx->r7 = ADD32(ctx->r7, -0X2F10);
L_8003528C:
    // 0x8003528C: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80035290: addiu       $a0, $a1, 0x1
    ctx->r4 = ADD32(ctx->r5, 0X1);
    // 0x80035294: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80035298: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8003529C: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x800352A0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800352A4: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800352A8: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800352AC: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800352B0: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800352B4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800352B8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800352BC: slti        $a0, $a0, 0xF
    ctx->r4 = SIGNED(ctx->r4) < 0XF ? 1 : 0;
    // 0x800352C0: bne         $a0, $zero, L_8003528C
    if (ctx->r4 != 0) {
        // 0x800352C4: sh          $v0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r2;
            goto L_8003528C;
    }
    // 0x800352C4: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_800352C8:
    // 0x800352C8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800352CC: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x800352D0: beq         $v0, $zero, L_800354AC
    if (ctx->r2 == 0) {
        // 0x800352D4: nop
    
            goto L_800354AC;
    }
    // 0x800352D4: nop

    // 0x800352D8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800352DC: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x800352E0: beq         $v0, $zero, L_800354AC
    if (ctx->r2 == 0) {
        // 0x800352E4: nop
    
            goto L_800354AC;
    }
    // 0x800352E4: nop

    // 0x800352E8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800352EC: lb          $v0, 0x25F3($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25F3);
    // 0x800352F0: beq         $v0, $zero, L_80035308
    if (ctx->r2 == 0) {
        // 0x800352F4: nop
    
            goto L_80035308;
    }
    // 0x800352F4: nop

    // 0x800352F8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800352FC: lb          $v0, 0x7A43($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7A43);
    // 0x80035300: bne         $v0, $zero, L_800354AC
    if (ctx->r2 != 0) {
        // 0x80035304: nop
    
            goto L_800354AC;
    }
    // 0x80035304: nop

L_80035308:
    // 0x80035308: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8003530C: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x80035310: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80035314: bne         $v1, $v0, L_800354AC
    if (ctx->r3 != ctx->r2) {
        // 0x80035318: nop
    
            goto L_800354AC;
    }
    // 0x80035318: nop

    // 0x8003531C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80035320: lbu         $v0, -0xBE8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XBE8);
    // 0x80035324: beq         $v0, $zero, L_800354AC
    if (ctx->r2 == 0) {
        // 0x80035328: nop
    
            goto L_800354AC;
    }
    // 0x80035328: nop

    // 0x8003532C: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80035330: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80035334: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80035338: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8003533C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80035340: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80035344: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x80035348: andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // 0x8003534C: beq         $v0, $zero, L_800354AC
    if (ctx->r2 == 0) {
        // 0x80035350: nop
    
            goto L_800354AC;
    }
    // 0x80035350: nop

    // 0x80035354: lbu         $v0, 0x3($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3);
    // 0x80035358: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8003535C: bne         $v0, $zero, L_800354AC
    if (ctx->r2 != 0) {
        // 0x80035360: nop
    
            goto L_800354AC;
    }
    // 0x80035360: nop

    // 0x80035364: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80035368: sb          $zero, 0x1($s1)
    MEM_B(0X1, ctx->r17) = 0;
    // 0x8003536C: bne         $v0, $zero, L_8003538C
    if (ctx->r2 != 0) {
        // 0x80035370: sb          $zero, 0x7($s1)
        MEM_B(0X7, ctx->r17) = 0;
            goto L_8003538C;
    }
    // 0x80035370: sb          $zero, 0x7($s1)
    MEM_B(0X7, ctx->r17) = 0;
    // 0x80035374: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80035378: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x8003537C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80035380: sb          $zero, 0x25F3($at)
    MEM_B(0X25F3, ctx->r1) = 0;
    // 0x80035384: j           L_800353A0
    // 0x80035388: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
        goto L_800353A0;
    // 0x80035388: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
L_8003538C:
    // 0x8003538C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80035390: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x80035394: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80035398: sb          $zero, 0x7A43($at)
    MEM_B(0X7A43, ctx->r1) = 0;
    // 0x8003539C: andi        $v0, $v0, 0xF0
    ctx->r2 = ctx->r2 & 0XF0;
L_800353A0:
    // 0x800353A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800353A4: sb          $v0, 0x7B8B($at)
    MEM_B(0X7B8B, ctx->r1) = ctx->r2;
    // 0x800353A8: lbu         $v1, 0x3($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X3);
    // 0x800353AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800353B0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800353B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800353B8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800353BC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800353C0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800353C4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800353C8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800353CC: sb          $zero, -0x7A6F($at)
    MEM_B(-0X7A6F, ctx->r1) = 0;
    // 0x800353D0: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x800353D4: lbu         $a0, 0x5($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X5);
    // 0x800353D8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800353DC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800353E0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800353E4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800353E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800353EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800353F0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800353F4: sb          $a0, 0x447D($at)
    MEM_B(0X447D, ctx->r1) = ctx->r4;
    // 0x800353F8: lbu         $v1, 0x6($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X6);
    // 0x800353FC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80035400: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80035404: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80035408: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003540C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80035410: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80035414: addiu       $v1, $zero, 0x11
    ctx->r3 = ADD32(0, 0X11);
    // 0x80035418: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8003541C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80035420: sb          $v1, 0x447B($at)
    MEM_B(0X447B, ctx->r1) = ctx->r3;
    // 0x80035424: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80035428: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8003542C: addiu       $a0, $a0, -0x2F50
    ctx->r4 = ADD32(ctx->r4, -0X2F50);
    // 0x80035430: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80035434: lw          $t0, -0xBF4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XBF4);
    // 0x80035438: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003543C: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80035440: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80035444: sll         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2 << 5);
    // 0x80035448: addu        $a3, $v1, $a0
    ctx->r7 = ADD32(ctx->r3, ctx->r4);
    // 0x8003544C: sll         $a2, $v0, 4
    ctx->r6 = S32(ctx->r2 << 4);
L_80035450:
    // 0x80035450: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x80035454: addiu       $a0, $a1, 0x1
    ctx->r4 = ADD32(ctx->r5, 0X1);
    // 0x80035458: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8003545C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80035460: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x80035464: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80035468: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8003546C: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80035470: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80035474: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80035478: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8003547C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80035480: slti        $a0, $a0, 0xF
    ctx->r4 = SIGNED(ctx->r4) < 0XF ? 1 : 0;
    // 0x80035484: bne         $a0, $zero, L_80035450
    if (ctx->r4 != 0) {
        // 0x80035488: sh          $v0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r2;
            goto L_80035450;
    }
    // 0x80035488: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8003548C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80035490: addiu       $v1, $v1, 0x7B76
    ctx->r3 = ADD32(ctx->r3, 0X7B76);
    // 0x80035494: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80035498: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8003549C: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800354A0: lbu         $a1, 0x5($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X5);
L_800354A4:
    // 0x800354A4: jal         0x8000637C
    // 0x800354A8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8000637C(rdram, ctx);
        goto after_6;
    // 0x800354A8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_6:
L_800354AC:
    // 0x800354AC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800354B0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800354B4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800354B8: jr          $ra
    // 0x800354BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800354BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800354C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800354C0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800354C4: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x800354C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800354CC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800354D0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800354D4: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x800354D8: bne         $v0, $zero, L_80035504
    if (ctx->r2 != 0) {
        // 0x800354DC: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_80035504;
    }
    // 0x800354DC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800354E0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800354E4: lui         $s1, 0x801E
    ctx->r17 = S32(0X801E << 16);
    // 0x800354E8: addiu       $s1, $s1, -0x7A70
    ctx->r17 = ADD32(ctx->r17, -0X7A70);
L_800354EC:
    // 0x800354EC: jal         0x8003474C
    // 0x800354F0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8003474C(rdram, ctx);
        goto after_0;
    // 0x800354F0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x800354F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800354F8: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x800354FC: bne         $v0, $zero, L_800354EC
    if (ctx->r2 != 0) {
        // 0x80035500: addiu       $s1, $s1, 0x34
        ctx->r17 = ADD32(ctx->r17, 0X34);
            goto L_800354EC;
    }
    // 0x80035500: addiu       $s1, $s1, 0x34
    ctx->r17 = ADD32(ctx->r17, 0X34);
L_80035504:
    // 0x80035504: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x80035508: lui         $s1, 0x801E
    ctx->r17 = S32(0X801E << 16);
    // 0x8003550C: addiu       $s1, $s1, -0x79A0
    ctx->r17 = ADD32(ctx->r17, -0X79A0);
L_80035510:
    // 0x80035510: jal         0x8003474C
    // 0x80035514: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8003474C(rdram, ctx);
        goto after_1;
    // 0x80035514: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x80035518: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003551C: slti        $v0, $s0, 0xE
    ctx->r2 = SIGNED(ctx->r16) < 0XE ? 1 : 0;
    // 0x80035520: bne         $v0, $zero, L_80035510
    if (ctx->r2 != 0) {
        // 0x80035524: addiu       $s1, $s1, 0x34
        ctx->r17 = ADD32(ctx->r17, 0X34);
            goto L_80035510;
    }
    // 0x80035524: addiu       $s1, $s1, 0x34
    ctx->r17 = ADD32(ctx->r17, 0X34);
    // 0x80035528: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8003552C: addiu       $s0, $s0, 0x4478
    ctx->r16 = ADD32(ctx->r16, 0X4478);
    // 0x80035530: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80035534: jal         0x80034504
    // 0x80035538: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80034504(rdram, ctx);
        goto after_2;
    // 0x80035538: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x8003553C: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x80035540: jal         0x80034504
    // 0x80035544: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80034504(rdram, ctx);
        goto after_3;
    // 0x80035544: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80035548: addiu       $a0, $s0, 0x68
    ctx->r4 = ADD32(ctx->r16, 0X68);
    // 0x8003554C: jal         0x80034504
    // 0x80035550: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80034504(rdram, ctx);
        goto after_4;
    // 0x80035550: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80035554: addiu       $a0, $s0, 0x9C
    ctx->r4 = ADD32(ctx->r16, 0X9C);
    // 0x80035558: jal         0x80034504
    // 0x8003555C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80034504(rdram, ctx);
        goto after_5;
    // 0x8003555C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80035560: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80035564: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80035568: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003556C: jr          $ra
    // 0x80035570: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80035570: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
