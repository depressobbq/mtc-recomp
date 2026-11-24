#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8006A1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A1E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A1E4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006A1E8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8006A1EC: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x8006A1F0: addu        $t1, $a3, $zero
    ctx->r9 = ADD32(ctx->r7, 0);
    // 0x8006A1F4: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x8006A1F8: addiu       $v1, $v0, -0x25
    ctx->r3 = ADD32(ctx->r2, -0X25);
    // 0x8006A1FC: sltiu       $v0, $v1, 0x54
    ctx->r2 = ctx->r3 < 0X54 ? 1 : 0;
    // 0x8006A200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A204: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x8006A208: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x8006A20C: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x8006A210: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x8006A214: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x8006A218: beq         $v0, $zero, L_8006A678
    if (ctx->r2 == 0) {
        // 0x8006A21C: sw          $zero, 0xC($s0)
        MEM_W(0XC, ctx->r16) = 0;
            goto L_8006A678;
    }
    // 0x8006A21C: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x8006A220: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8006A224: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006A228: addu        $at, $at, $v0
    gpr jr_addend_8006A230 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8006A22C: lw          $v0, -0xBE0($at)
    ctx->r2 = ADD32(ctx->r1, -0XBE0);
    // 0x8006A230: jr          $v0
    // 0x8006A234: nop

    switch (jr_addend_8006A230 >> 2) {
        case 0: goto L_8006A65C; break;
        case 1: goto L_8006A678; break;
        case 2: goto L_8006A678; break;
        case 3: goto L_8006A678; break;
        case 4: goto L_8006A678; break;
        case 5: goto L_8006A678; break;
        case 6: goto L_8006A678; break;
        case 7: goto L_8006A678; break;
        case 8: goto L_8006A678; break;
        case 9: goto L_8006A678; break;
        case 10: goto L_8006A678; break;
        case 11: goto L_8006A678; break;
        case 12: goto L_8006A678; break;
        case 13: goto L_8006A678; break;
        case 14: goto L_8006A678; break;
        case 15: goto L_8006A678; break;
        case 16: goto L_8006A678; break;
        case 17: goto L_8006A678; break;
        case 18: goto L_8006A678; break;
        case 19: goto L_8006A678; break;
        case 20: goto L_8006A678; break;
        case 21: goto L_8006A678; break;
        case 22: goto L_8006A678; break;
        case 23: goto L_8006A678; break;
        case 24: goto L_8006A678; break;
        case 25: goto L_8006A678; break;
        case 26: goto L_8006A678; break;
        case 27: goto L_8006A678; break;
        case 28: goto L_8006A678; break;
        case 29: goto L_8006A678; break;
        case 30: goto L_8006A678; break;
        case 31: goto L_8006A678; break;
        case 32: goto L_8006A47C; break;
        case 33: goto L_8006A678; break;
        case 34: goto L_8006A47C; break;
        case 35: goto L_8006A678; break;
        case 36: goto L_8006A678; break;
        case 37: goto L_8006A678; break;
        case 38: goto L_8006A678; break;
        case 39: goto L_8006A678; break;
        case 40: goto L_8006A678; break;
        case 41: goto L_8006A678; break;
        case 42: goto L_8006A678; break;
        case 43: goto L_8006A678; break;
        case 44: goto L_8006A678; break;
        case 45: goto L_8006A678; break;
        case 46: goto L_8006A678; break;
        case 47: goto L_8006A678; break;
        case 48: goto L_8006A678; break;
        case 49: goto L_8006A678; break;
        case 50: goto L_8006A678; break;
        case 51: goto L_8006A36C; break;
        case 52: goto L_8006A678; break;
        case 53: goto L_8006A678; break;
        case 54: goto L_8006A678; break;
        case 55: goto L_8006A678; break;
        case 56: goto L_8006A678; break;
        case 57: goto L_8006A678; break;
        case 58: goto L_8006A678; break;
        case 59: goto L_8006A678; break;
        case 60: goto L_8006A678; break;
        case 61: goto L_8006A678; break;
        case 62: goto L_8006A238; break;
        case 63: goto L_8006A26C; break;
        case 64: goto L_8006A47C; break;
        case 65: goto L_8006A47C; break;
        case 66: goto L_8006A47C; break;
        case 67: goto L_8006A678; break;
        case 68: goto L_8006A26C; break;
        case 69: goto L_8006A678; break;
        case 70: goto L_8006A678; break;
        case 71: goto L_8006A678; break;
        case 72: goto L_8006A678; break;
        case 73: goto L_8006A52C; break;
        case 74: goto L_8006A36C; break;
        case 75: goto L_8006A5CC; break;
        case 76: goto L_8006A678; break;
        case 77: goto L_8006A678; break;
        case 78: goto L_8006A618; break;
        case 79: goto L_8006A678; break;
        case 80: goto L_8006A36C; break;
        case 81: goto L_8006A678; break;
        case 82: goto L_8006A678; break;
        case 83: goto L_8006A36C; break;
        default: switch_error(__func__, 0x8006A230, 0x800AF420);
    }
    // 0x8006A234: nop

L_8006A238:
    // 0x8006A238: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x8006A23C: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8006A240: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x8006A244: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8006A248: addiu       $v1, $zero, -0x4
    ctx->r3 = ADD32(0, -0X4);
    // 0x8006A24C: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8006A250: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006A254: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x8006A258: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x8006A25C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8006A260: addu        $a0, $t1, $a0
    ctx->r4 = ADD32(ctx->r9, ctx->r4);
    // 0x8006A264: j           L_8006A68C
    // 0x8006A268: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
        goto L_8006A68C;
    // 0x8006A268: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_8006A26C:
    // 0x8006A26C: lbu         $v1, 0x34($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X34);
    // 0x8006A270: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    // 0x8006A274: beq         $v1, $v0, L_8006A2A4
    if (ctx->r3 == ctx->r2) {
        // 0x8006A278: addiu       $v0, $zero, 0x4C
        ctx->r2 = ADD32(0, 0X4C);
            goto L_8006A2A4;
    }
    // 0x8006A278: addiu       $v0, $zero, 0x4C
    ctx->r2 = ADD32(0, 0X4C);
    // 0x8006A27C: bne         $v1, $v0, L_8006A2A4
    if (ctx->r3 != ctx->r2) {
        // 0x8006A280: addiu       $v1, $zero, -0x8
        ctx->r3 = ADD32(0, -0X8);
            goto L_8006A2A4;
    }
    // 0x8006A280: addiu       $v1, $zero, -0x8
    ctx->r3 = ADD32(0, -0X8);
    // 0x8006A284: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8006A288: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x8006A28C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006A290: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8006A294: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x8006A298: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8006A29C: j           L_8006A2C8
    // 0x8006A2A0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
        goto L_8006A2C8;
    // 0x8006A2A0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_8006A2A4:
    // 0x8006A2A4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8006A2A8: addiu       $v1, $zero, -0x4
    ctx->r3 = ADD32(0, -0X4);
    // 0x8006A2AC: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8006A2B0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006A2B4: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x8006A2B8: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x8006A2BC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8006A2C0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8006A2C4: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
L_8006A2C8:
    // 0x8006A2C8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8006A2CC: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x8006A2D0: lbu         $v1, 0x34($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X34);
    // 0x8006A2D4: addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
    // 0x8006A2D8: bne         $v1, $v0, L_8006A2FC
    if (ctx->r3 != ctx->r2) {
        // 0x8006A2DC: nop
    
            goto L_8006A2FC;
    }
    // 0x8006A2DC: nop

    // 0x8006A2E0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8006A2E4: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8006A2E8: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8006A2EC: sra         $a1, $v0, 16
    ctx->r5 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006A2F0: sra         $a0, $v0, 31
    ctx->r4 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8006A2F4: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
    // 0x8006A2F8: sw          $a1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r5;
L_8006A2FC:
    // 0x8006A2FC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8006A300: bgez        $v0, L_8006A320
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006A304: nop
    
            goto L_8006A320;
    }
    // 0x8006A304: nop

    // 0x8006A308: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8006A30C: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8006A310: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x8006A314: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x8006A318: j           L_8006A364
    // 0x8006A31C: addiu       $v1, $zero, 0x2D
    ctx->r3 = ADD32(0, 0X2D);
        goto L_8006A364;
    // 0x8006A31C: addiu       $v1, $zero, 0x2D
    ctx->r3 = ADD32(0, 0X2D);
L_8006A320:
    // 0x8006A320: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x8006A324: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x8006A328: beq         $v0, $zero, L_8006A348
    if (ctx->r2 == 0) {
        // 0x8006A32C: andi        $v0, $v1, 0x1
        ctx->r2 = ctx->r3 & 0X1;
            goto L_8006A348;
    }
    // 0x8006A32C: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x8006A330: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8006A334: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8006A338: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x8006A33C: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x8006A340: j           L_8006A364
    // 0x8006A344: addiu       $v1, $zero, 0x2B
    ctx->r3 = ADD32(0, 0X2B);
        goto L_8006A364;
    // 0x8006A344: addiu       $v1, $zero, 0x2B
    ctx->r3 = ADD32(0, 0X2B);
L_8006A348:
    // 0x8006A348: beq         $v0, $zero, L_8006A45C
    if (ctx->r2 == 0) {
        // 0x8006A34C: nop
    
            goto L_8006A45C;
    }
    // 0x8006A34C: nop

    // 0x8006A350: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8006A354: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8006A358: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x8006A35C: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x8006A360: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
L_8006A364:
    // 0x8006A364: j           L_8006A45C
    // 0x8006A368: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
        goto L_8006A45C;
    // 0x8006A368: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_8006A36C:
    // 0x8006A36C: lbu         $v1, 0x34($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X34);
    // 0x8006A370: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    // 0x8006A374: beq         $v1, $v0, L_8006A3A4
    if (ctx->r3 == ctx->r2) {
        // 0x8006A378: addiu       $v0, $zero, 0x4C
        ctx->r2 = ADD32(0, 0X4C);
            goto L_8006A3A4;
    }
    // 0x8006A378: addiu       $v0, $zero, 0x4C
    ctx->r2 = ADD32(0, 0X4C);
    // 0x8006A37C: bne         $v1, $v0, L_8006A3A4
    if (ctx->r3 != ctx->r2) {
        // 0x8006A380: addiu       $v1, $zero, -0x8
        ctx->r3 = ADD32(0, -0X8);
            goto L_8006A3A4;
    }
    // 0x8006A380: addiu       $v1, $zero, -0x8
    ctx->r3 = ADD32(0, -0X8);
    // 0x8006A384: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8006A388: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x8006A38C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006A390: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8006A394: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x8006A398: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8006A39C: j           L_8006A3C8
    // 0x8006A3A0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
        goto L_8006A3C8;
    // 0x8006A3A0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_8006A3A4:
    // 0x8006A3A4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8006A3A8: addiu       $v1, $zero, -0x4
    ctx->r3 = ADD32(0, -0X4);
    // 0x8006A3AC: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8006A3B0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006A3B4: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x8006A3B8: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x8006A3BC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8006A3C0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8006A3C4: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
L_8006A3C8:
    // 0x8006A3C8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8006A3CC: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x8006A3D0: lbu         $v1, 0x34($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X34);
    // 0x8006A3D4: addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
    // 0x8006A3D8: bne         $v1, $v0, L_8006A3EC
    if (ctx->r3 != ctx->r2) {
        // 0x8006A3DC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8006A3EC;
    }
    // 0x8006A3DC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8006A3E0: lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X6);
    // 0x8006A3E4: j           L_8006A3F8
    // 0x8006A3E8: nop

        goto L_8006A3F8;
    // 0x8006A3E8: nop

L_8006A3EC:
    // 0x8006A3EC: bne         $v1, $zero, L_8006A400
    if (ctx->r3 != 0) {
        // 0x8006A3F0: nop
    
            goto L_8006A400;
    }
    // 0x8006A3F0: nop

    // 0x8006A3F4: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
L_8006A3F8:
    // 0x8006A3F8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8006A3FC: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
L_8006A400:
    // 0x8006A400: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x8006A404: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8006A408: beq         $v0, $zero, L_8006A45C
    if (ctx->r2 == 0) {
        // 0x8006A40C: nop
    
            goto L_8006A45C;
    }
    // 0x8006A40C: nop

    // 0x8006A410: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8006A414: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8006A418: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x8006A41C: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x8006A420: addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
    // 0x8006A424: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8006A428: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x8006A42C: xori        $v1, $v0, 0x78
    ctx->r3 = ctx->r2 ^ 0X78;
    // 0x8006A430: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8006A434: xori        $v0, $v0, 0x58
    ctx->r2 = ctx->r2 ^ 0X58;
    // 0x8006A438: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006A43C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8006A440: beq         $v1, $zero, L_8006A45C
    if (ctx->r3 == 0) {
        // 0x8006A444: nop
    
            goto L_8006A45C;
    }
    // 0x8006A444: nop

    // 0x8006A448: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8006A44C: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8006A450: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x8006A454: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x8006A458: sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
L_8006A45C:
    // 0x8006A45C: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8006A460: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006A464: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    // 0x8006A468: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x8006A46C: jal         0x8006B480
    // 0x8006A470: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    func_8006B480(rdram, ctx);
        goto after_0;
    // 0x8006A470: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    after_0:
    // 0x8006A474: j           L_8006A68C
    // 0x8006A478: nop

        goto L_8006A68C;
    // 0x8006A478: nop

L_8006A47C:
    // 0x8006A47C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8006A480: addiu       $v1, $zero, -0x8
    ctx->r3 = ADD32(0, -0X8);
    // 0x8006A484: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x8006A488: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006A48C: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8006A490: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x8006A494: ldc1        $f0, 0x0($v0)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r2, 0X0);
    // 0x8006A498: sdc1        $f0, 0x0($s0)
    CHECK_FR(ctx, 0);
    SD(ctx->f0.u64, 0X0, ctx->r16);
    // 0x8006A49C: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x8006A4A0: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x8006A4A4: beq         $v0, $zero, L_8006A4C4
    if (ctx->r2 == 0) {
        // 0x8006A4A8: nop
    
            goto L_8006A4C4;
    }
    // 0x8006A4A8: nop

    // 0x8006A4AC: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8006A4B0: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8006A4B4: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x8006A4B8: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x8006A4BC: j           L_8006A508
    // 0x8006A4C0: addiu       $v1, $zero, 0x2D
    ctx->r3 = ADD32(0, 0X2D);
        goto L_8006A508;
    // 0x8006A4C0: addiu       $v1, $zero, 0x2D
    ctx->r3 = ADD32(0, 0X2D);
L_8006A4C4:
    // 0x8006A4C4: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x8006A4C8: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x8006A4CC: beq         $v0, $zero, L_8006A4EC
    if (ctx->r2 == 0) {
        // 0x8006A4D0: andi        $v0, $v1, 0x1
        ctx->r2 = ctx->r3 & 0X1;
            goto L_8006A4EC;
    }
    // 0x8006A4D0: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x8006A4D4: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8006A4D8: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8006A4DC: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x8006A4E0: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x8006A4E4: j           L_8006A508
    // 0x8006A4E8: addiu       $v1, $zero, 0x2B
    ctx->r3 = ADD32(0, 0X2B);
        goto L_8006A508;
    // 0x8006A4E8: addiu       $v1, $zero, 0x2B
    ctx->r3 = ADD32(0, 0X2B);
L_8006A4EC:
    // 0x8006A4EC: beq         $v0, $zero, L_8006A50C
    if (ctx->r2 == 0) {
        // 0x8006A4F0: nop
    
            goto L_8006A50C;
    }
    // 0x8006A4F0: nop

    // 0x8006A4F4: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8006A4F8: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8006A4FC: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x8006A500: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x8006A504: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
L_8006A508:
    // 0x8006A508: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_8006A50C:
    // 0x8006A50C: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8006A510: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006A514: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    // 0x8006A518: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x8006A51C: jal         0x8006B6D0
    // 0x8006A520: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    func_8006B6D0(rdram, ctx);
        goto after_1;
    // 0x8006A520: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    after_1:
    // 0x8006A524: j           L_8006A68C
    // 0x8006A528: nop

        goto L_8006A68C;
    // 0x8006A528: nop

L_8006A52C:
    // 0x8006A52C: lbu         $v1, 0x34($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X34);
    // 0x8006A530: addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
    // 0x8006A534: bne         $v1, $v0, L_8006A564
    if (ctx->r3 != ctx->r2) {
        // 0x8006A538: addiu       $v0, $zero, 0x6C
        ctx->r2 = ADD32(0, 0X6C);
            goto L_8006A564;
    }
    // 0x8006A538: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    // 0x8006A53C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8006A540: addiu       $v1, $zero, -0x4
    ctx->r3 = ADD32(0, -0X4);
    // 0x8006A544: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8006A548: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006A54C: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x8006A550: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x8006A554: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8006A558: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
    // 0x8006A55C: j           L_8006A68C
    // 0x8006A560: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
        goto L_8006A68C;
    // 0x8006A560: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8006A564:
    // 0x8006A564: beq         $v1, $v0, L_8006A5A4
    if (ctx->r3 == ctx->r2) {
        // 0x8006A568: addiu       $v0, $zero, 0x4C
        ctx->r2 = ADD32(0, 0X4C);
            goto L_8006A5A4;
    }
    // 0x8006A568: addiu       $v0, $zero, 0x4C
    ctx->r2 = ADD32(0, 0X4C);
    // 0x8006A56C: bne         $v1, $v0, L_8006A5A4
    if (ctx->r3 != ctx->r2) {
        // 0x8006A570: addiu       $v0, $zero, -0x4
        ctx->r2 = ADD32(0, -0X4);
            goto L_8006A5A4;
    }
    // 0x8006A570: addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
    // 0x8006A574: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006A578: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x8006A57C: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // 0x8006A580: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x8006A584: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8006A588: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
    // 0x8006A58C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8006A590: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8006A594: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8006A598: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8006A59C: j           L_8006A68C
    // 0x8006A5A0: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
        goto L_8006A68C;
    // 0x8006A5A0: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
L_8006A5A4:
    // 0x8006A5A4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8006A5A8: addiu       $v1, $zero, -0x4
    ctx->r3 = ADD32(0, -0X4);
    // 0x8006A5AC: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8006A5B0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006A5B4: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x8006A5B8: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x8006A5BC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8006A5C0: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
    // 0x8006A5C4: j           L_8006A68C
    // 0x8006A5C8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_8006A68C;
    // 0x8006A5C8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8006A5CC:
    // 0x8006A5CC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8006A5D0: addiu       $a1, $zero, -0x4
    ctx->r5 = ADD32(0, -0X4);
    // 0x8006A5D4: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x8006A5D8: and         $a0, $a0, $a1
    ctx->r4 = ctx->r4 & ctx->r5;
    // 0x8006A5DC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x8006A5E0: sw          $a1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r5;
    // 0x8006A5E4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8006A5E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006A5EC: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x8006A5F0: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    // 0x8006A5F4: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x8006A5F8: sra         $v0, $a3, 31
    ctx->r2 = S32(SIGNED(ctx->r7) >> 31);
    // 0x8006A5FC: addu        $a2, $t1, $a2
    ctx->r6 = ADD32(ctx->r9, ctx->r6);
    // 0x8006A600: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8006A604: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x8006A608: jal         0x8006B480
    // 0x8006A60C: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    func_8006B480(rdram, ctx);
        goto after_2;
    // 0x8006A60C: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    after_2:
    // 0x8006A610: j           L_8006A68C
    // 0x8006A614: nop

        goto L_8006A68C;
    // 0x8006A614: nop

L_8006A618:
    // 0x8006A618: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8006A61C: addiu       $v1, $zero, -0x4
    ctx->r3 = ADD32(0, -0X4);
    // 0x8006A620: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8006A624: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006A628: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x8006A62C: sw          $v1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r3;
    // 0x8006A630: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8006A634: jal         0x80066C48
    // 0x8006A638: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    strlen_recomp(rdram, ctx);
        goto after_3;
    // 0x8006A638: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    after_3:
    // 0x8006A63C: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x8006A640: bltz        $v1, L_8006A68C
    if (SIGNED(ctx->r3) < 0) {
        // 0x8006A644: sw          $v0, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r2;
            goto L_8006A68C;
    }
    // 0x8006A644: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x8006A648: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006A64C: bnel        $v0, $zero, L_8006A68C
    if (ctx->r2 != 0) {
        // 0x8006A650: sw          $v1, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r3;
            goto L_8006A68C;
    }
    goto skip_0;
    // 0x8006A650: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    skip_0:
    // 0x8006A654: j           L_8006A68C
    // 0x8006A658: nop

        goto L_8006A68C;
    // 0x8006A658: nop

L_8006A65C:
    // 0x8006A65C: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8006A660: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8006A664: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x8006A668: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x8006A66C: addiu       $v1, $zero, 0x25
    ctx->r3 = ADD32(0, 0X25);
    // 0x8006A670: j           L_8006A68C
    // 0x8006A674: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
        goto L_8006A68C;
    // 0x8006A674: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_8006A678:
    // 0x8006A678: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8006A67C: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8006A680: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x8006A684: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x8006A688: sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
L_8006A68C:
    // 0x8006A68C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A690: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006A694: jr          $ra
    // 0x8006A698: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006A698: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8006A6A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A6A0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8006A6A4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8006A6A8: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x8006A6AC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8006A6B0: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x8006A6B4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8006A6B8: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8006A6BC: addiu       $s3, $s3, 0x7960
    ctx->r19 = ADD32(ctx->r19, 0X7960);
    // 0x8006A6C0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8006A6C4: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x8006A6C8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8006A6CC: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x8006A6D0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8006A6D4: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8006A6D8: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8006A6DC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8006A6E0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8006A6E4: jal         0x800693C4
    // 0x8006A6E8: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    func_800693C4(rdram, ctx);
        goto after_0;
    // 0x8006A6E8: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    after_0:
    // 0x8006A6EC: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x8006A6F0: andi        $s7, $s0, 0xFFFF
    ctx->r23 = ctx->r16 & 0XFFFF;
    // 0x8006A6F4: sll         $s0, $s0, 5
    ctx->r16 = S32(ctx->r16 << 5);
    // 0x8006A6F8: addiu       $s2, $s3, 0x26
    ctx->r18 = ADD32(ctx->r19, 0X26);
    // 0x8006A6FC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
L_8006A700:
    // 0x8006A700: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006A704: lbu         $v0, 0x4914($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4914);
    // 0x8006A708: bne         $v0, $fp, L_8006A720
    if (ctx->r2 != ctx->r30) {
        // 0x8006A70C: nop
    
            goto L_8006A720;
    }
    // 0x8006A70C: nop

    // 0x8006A710: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8006A714: lw          $v0, -0x7DA0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DA0);
    // 0x8006A718: beql        $v0, $s4, L_8006A788
    if (ctx->r2 == ctx->r20) {
        // 0x8006A71C: addu        $s2, $s2, $s4
        ctx->r18 = ADD32(ctx->r18, ctx->r20);
            goto L_8006A788;
    }
    goto skip_0;
    // 0x8006A71C: addu        $s2, $s2, $s4
    ctx->r18 = ADD32(ctx->r18, ctx->r20);
    skip_0:
L_8006A720:
    // 0x8006A720: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006A724: sb          $fp, 0x4914($at)
    MEM_B(0X4914, ctx->r1) = ctx->r30;
    // 0x8006A728: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006A72C: sw          $s4, -0x7DA0($at)
    MEM_W(-0X7DA0, ctx->r1) = ctx->r20;
    // 0x8006A730: blez        $s4, L_8006A750
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8006A734: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8006A750;
    }
    // 0x8006A734: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8006A738:
    // 0x8006A738: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    // 0x8006A73C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8006A740: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006A744: slt         $v0, $v1, $s4
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8006A748: bne         $v0, $zero, L_8006A738
    if (ctx->r2 != 0) {
        // 0x8006A74C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8006A738;
    }
    // 0x8006A74C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8006A750:
    // 0x8006A750: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006A754: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006A758: sw          $v0, 0x799C($at)
    MEM_W(0X799C, ctx->r1) = ctx->r2;
    // 0x8006A75C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8006A760: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8006A764: sb          $t0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r8;
    // 0x8006A768: sb          $v0, -0x25($s2)
    MEM_B(-0X25, ctx->r18) = ctx->r2;
    // 0x8006A76C: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
    // 0x8006A770: sb          $v0, -0x24($s2)
    MEM_B(-0X24, ctx->r18) = ctx->r2;
    // 0x8006A774: addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // 0x8006A778: sb          $fp, -0x23($s2)
    MEM_B(-0X23, ctx->r18) = ctx->r30;
    // 0x8006A77C: sb          $t0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r8;
    // 0x8006A780: j           L_8006A78C
    // 0x8006A784: sb          $v0, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r2;
        goto L_8006A78C;
    // 0x8006A784: sb          $v0, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r2;
L_8006A788:
    // 0x8006A788: addu        $s3, $s3, $s4
    ctx->r19 = ADD32(ctx->r19, ctx->r20);
L_8006A78C:
    // 0x8006A78C: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x8006A790: srl         $v0, $s7, 3
    ctx->r2 = S32(U32(ctx->r23) >> 3);
    // 0x8006A794: jal         0x8006AAC0
    // 0x8006A798: sb          $v0, -0x22($s2)
    MEM_B(-0X22, ctx->r18) = ctx->r2;
    func_8006AAC0(rdram, ctx);
        goto after_1;
    // 0x8006A798: sb          $v0, -0x22($s2)
    MEM_B(-0X22, ctx->r18) = ctx->r2;
    after_1:
    // 0x8006A79C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A7A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006A7A4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006A7A8: addiu       $a1, $a1, 0x7960
    ctx->r5 = ADD32(ctx->r5, 0X7960);
    // 0x8006A7AC: or          $v0, $v0, $t0
    ctx->r2 = ctx->r2 | ctx->r8;
    // 0x8006A7B0: jal         0x800677D0
    // 0x8006A7B4: sb          $v0, -0x21($s2)
    MEM_B(-0X21, ctx->r18) = ctx->r2;
    func_800677D0(rdram, ctx);
        goto after_2;
    // 0x8006A7B4: sb          $v0, -0x21($s2)
    MEM_B(-0X21, ctx->r18) = ctx->r2;
    after_2:
    // 0x8006A7B8: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x8006A7BC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006A7C0: jal         0x800619A0
    // 0x8006A7C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8006A7C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8006A7C8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006A7CC: addiu       $a1, $a1, 0x7960
    ctx->r5 = ADD32(ctx->r5, 0X7960);
    // 0x8006A7D0: jal         0x800677D0
    // 0x8006A7D4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800677D0(rdram, ctx);
        goto after_4;
    // 0x8006A7D4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
    // 0x8006A7D8: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x8006A7DC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006A7E0: jal         0x800619A0
    // 0x8006A7E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x8006A7E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8006A7E8: lbu         $v0, -0x24($s2)
    ctx->r2 = MEM_BU(ctx->r18, -0X24);
    // 0x8006A7EC: andi        $v0, $v0, 0xC0
    ctx->r2 = ctx->r2 & 0XC0;
    // 0x8006A7F0: srl         $s0, $v0, 4
    ctx->r16 = S32(U32(ctx->r2) >> 4);
    // 0x8006A7F4: bnel        $s0, $zero, L_8006A84C
    if (ctx->r16 != 0) {
        // 0x8006A7F8: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_8006A84C;
    }
    goto skip_1;
    // 0x8006A7F8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    skip_1:
    // 0x8006A7FC: addiu       $s1, $s3, 0x6
    ctx->r17 = ADD32(ctx->r19, 0X6);
    // 0x8006A800: jal         0x8006AB2C
    // 0x8006A804: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8006AB2C(rdram, ctx);
        goto after_6;
    // 0x8006A804: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_6:
    // 0x8006A808: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x8006A80C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006A810: beq         $v0, $v1, L_8006A834
    if (ctx->r2 == ctx->r3) {
        // 0x8006A814: addu        $a0, $s6, $zero
        ctx->r4 = ADD32(ctx->r22, 0);
            goto L_8006A834;
    }
    // 0x8006A814: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x8006A818: jal         0x8006ABB0
    // 0x8006A81C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8006ABB0(rdram, ctx);
        goto after_7;
    // 0x8006A81C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_7:
    // 0x8006A820: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8006A824: bne         $s0, $zero, L_8006A860
    if (ctx->r16 != 0) {
        // 0x8006A828: nop
    
            goto L_8006A860;
    }
    // 0x8006A828: nop

    // 0x8006A82C: j           L_8006A84C
    // 0x8006A830: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
        goto L_8006A84C;
    // 0x8006A830: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_8006A834:
    // 0x8006A834: lw          $a1, 0x14($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14);
    // 0x8006A838: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8006A83C: jal         0x80066850
    // 0x8006A840: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    bcopy_recomp(rdram, ctx);
        goto after_8;
    // 0x8006A840: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_8:
    // 0x8006A844: j           L_8006A850
    // 0x8006A848: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8006A850;
    // 0x8006A848: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8006A84C:
    // 0x8006A84C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8006A850:
    // 0x8006A850: bne         $s0, $v0, L_8006A860
    if (ctx->r16 != ctx->r2) {
        // 0x8006A854: addu        $v0, $s5, $zero
        ctx->r2 = ADD32(ctx->r21, 0);
            goto L_8006A860;
    }
    // 0x8006A854: addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // 0x8006A858: bgez        $v0, L_8006A700
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006A85C: addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
            goto L_8006A700;
    }
    // 0x8006A85C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_8006A860:
    // 0x8006A860: jal         0x80069430
    // 0x8006A864: nop

    func_80069430(rdram, ctx);
        goto after_9;
    // 0x8006A864: nop

    after_9:
    // 0x8006A868: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8006A86C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8006A870: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8006A874: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8006A878: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8006A87C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8006A880: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8006A884: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8006A888: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8006A88C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8006A890: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8006A894: jr          $ra
    // 0x8006A898: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8006A898: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8006A8A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A8A0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006A8A4: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x8006A8A8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8006A8AC: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x8006A8B0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8006A8B4: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x8006A8B8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8006A8BC: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8006A8C0: addiu       $s2, $s2, 0x7960
    ctx->r18 = ADD32(ctx->r18, 0X7960);
    // 0x8006A8C4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8006A8C8: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x8006A8CC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8006A8D0: addu        $fp, $a3, $zero
    ctx->r30 = ADD32(ctx->r7, 0);
    // 0x8006A8D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006A8D8: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x8006A8DC: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x8006A8E0: sltiu       $v1, $a0, 0x7
    ctx->r3 = ctx->r4 < 0X7 ? 1 : 0;
    // 0x8006A8E4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8006A8E8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8006A8EC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8006A8F0: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8006A8F4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8006A8F8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006A8FC: beq         $v0, $zero, L_8006A90C
    if (ctx->r2 == 0) {
        // 0x8006A900: sw          $s1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r17;
            goto L_8006A90C;
    }
    // 0x8006A900: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8006A904: bne         $a0, $zero, L_8006AA8C
    if (ctx->r4 != 0) {
        // 0x8006A908: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8006AA8C;
    }
    // 0x8006A908: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006A90C:
    // 0x8006A90C: jal         0x800693C4
    // 0x8006A910: andi        $s7, $s0, 0xFFFF
    ctx->r23 = ctx->r16 & 0XFFFF;
    func_800693C4(rdram, ctx);
        goto after_0;
    // 0x8006A910: andi        $s7, $s0, 0xFFFF
    ctx->r23 = ctx->r16 & 0XFFFF;
    after_0:
    // 0x8006A914: sll         $s0, $s0, 5
    ctx->r16 = S32(ctx->r16 << 5);
    // 0x8006A918: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006A91C: addiu       $s1, $s2, 0x26
    ctx->r17 = ADD32(ctx->r18, 0X26);
L_8006A920:
    // 0x8006A920: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006A924: lbu         $v0, 0x4914($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4914);
    // 0x8006A928: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8006A92C: bne         $v0, $t0, L_8006A944
    if (ctx->r2 != ctx->r8) {
        // 0x8006A930: addiu       $t0, $zero, 0x3
        ctx->r8 = ADD32(0, 0X3);
            goto L_8006A944;
    }
    // 0x8006A930: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8006A934: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8006A938: lw          $v0, -0x7DA0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DA0);
    // 0x8006A93C: beql        $v0, $s3, L_8006A9B4
    if (ctx->r2 == ctx->r19) {
        // 0x8006A940: addu        $s1, $s1, $s3
        ctx->r17 = ADD32(ctx->r17, ctx->r19);
            goto L_8006A9B4;
    }
    goto skip_0;
    // 0x8006A940: addu        $s1, $s1, $s3
    ctx->r17 = ADD32(ctx->r17, ctx->r19);
    skip_0:
L_8006A944:
    // 0x8006A944: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006A948: sb          $t0, 0x4914($at)
    MEM_B(0X4914, ctx->r1) = ctx->r8;
    // 0x8006A94C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006A950: sw          $s3, -0x7DA0($at)
    MEM_W(-0X7DA0, ctx->r1) = ctx->r19;
    // 0x8006A954: blez        $s3, L_8006A974
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8006A958: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8006A974;
    }
    // 0x8006A958: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8006A95C:
    // 0x8006A95C: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x8006A960: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006A964: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006A968: slt         $v0, $v1, $s3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8006A96C: bne         $v0, $zero, L_8006A95C
    if (ctx->r2 != 0) {
        // 0x8006A970: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8006A95C;
    }
    // 0x8006A970: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8006A974:
    // 0x8006A974: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8006A978: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006A97C: sw          $t0, 0x799C($at)
    MEM_W(0X799C, ctx->r1) = ctx->r8;
    // 0x8006A980: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8006A984: addiu       $v0, $zero, 0x23
    ctx->r2 = ADD32(0, 0X23);
    // 0x8006A988: sb          $t0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r8;
    // 0x8006A98C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8006A990: sb          $t0, -0x24($s1)
    MEM_B(-0X24, ctx->r17) = ctx->r8;
    // 0x8006A994: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8006A998: sb          $t0, -0x23($s1)
    MEM_B(-0X23, ctx->r17) = ctx->r8;
    // 0x8006A99C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8006A9A0: sb          $v0, -0x25($s1)
    MEM_B(-0X25, ctx->r17) = ctx->r2;
    // 0x8006A9A4: addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // 0x8006A9A8: sb          $t0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r8;
    // 0x8006A9AC: j           L_8006A9B8
    // 0x8006A9B0: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
        goto L_8006A9B8;
    // 0x8006A9B0: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
L_8006A9B4:
    // 0x8006A9B4: addu        $s2, $s2, $s3
    ctx->r18 = ADD32(ctx->r18, ctx->r19);
L_8006A9B8:
    // 0x8006A9B8: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x8006A9BC: srl         $v0, $s7, 3
    ctx->r2 = S32(U32(ctx->r23) >> 3);
    // 0x8006A9C0: jal         0x8006AAC0
    // 0x8006A9C4: sb          $v0, -0x22($s1)
    MEM_B(-0X22, ctx->r17) = ctx->r2;
    func_8006AAC0(rdram, ctx);
        goto after_1;
    // 0x8006A9C4: sb          $v0, -0x22($s1)
    MEM_B(-0X22, ctx->r17) = ctx->r2;
    after_1:
    // 0x8006A9C8: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // 0x8006A9CC: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x8006A9D0: addiu       $a1, $s2, 0x6
    ctx->r5 = ADD32(ctx->r18, 0X6);
    // 0x8006A9D4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8006A9D8: or          $v0, $v0, $t0
    ctx->r2 = ctx->r2 | ctx->r8;
    // 0x8006A9DC: jal         0x80066850
    // 0x8006A9E0: sb          $v0, -0x21($s1)
    MEM_B(-0X21, ctx->r17) = ctx->r2;
    bcopy_recomp(rdram, ctx);
        goto after_2;
    // 0x8006A9E0: sb          $v0, -0x21($s1)
    MEM_B(-0X21, ctx->r17) = ctx->r2;
    after_2:
    // 0x8006A9E4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006A9E8: addiu       $a1, $a1, 0x7960
    ctx->r5 = ADD32(ctx->r5, 0X7960);
    // 0x8006A9EC: jal         0x800677D0
    // 0x8006A9F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800677D0(rdram, ctx);
        goto after_3;
    // 0x8006A9F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8006A9F4: jal         0x8006AB2C
    // 0x8006A9F8: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    func_8006AB2C(rdram, ctx);
        goto after_4;
    // 0x8006A9F8: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    after_4:
    // 0x8006A9FC: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x8006AA00: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006AA04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006AA08: jal         0x800619A0
    // 0x8006AA0C: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x8006AA0C: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    after_5:
    // 0x8006AA10: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006AA14: addiu       $a1, $a1, 0x7960
    ctx->r5 = ADD32(ctx->r5, 0X7960);
    // 0x8006AA18: jal         0x800677D0
    // 0x8006AA1C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800677D0(rdram, ctx);
        goto after_6;
    // 0x8006AA1C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_6:
    // 0x8006AA20: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x8006AA24: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006AA28: jal         0x800619A0
    // 0x8006AA2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x8006AA2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x8006AA30: lbu         $v0, -0x24($s1)
    ctx->r2 = MEM_BU(ctx->r17, -0X24);
    // 0x8006AA34: andi        $v0, $v0, 0xC0
    ctx->r2 = ctx->r2 & 0XC0;
    // 0x8006AA38: srl         $s0, $v0, 4
    ctx->r16 = S32(U32(ctx->r2) >> 4);
    // 0x8006AA3C: bnel        $s0, $zero, L_8006AA6C
    if (ctx->r16 != 0) {
        // 0x8006AA40: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_8006AA6C;
    }
    goto skip_1;
    // 0x8006AA40: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    skip_1:
    // 0x8006AA44: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x8006AA48: andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // 0x8006AA4C: beq         $v0, $v1, L_8006AA6C
    if (ctx->r2 == ctx->r3) {
        // 0x8006AA50: addu        $a0, $s6, $zero
        ctx->r4 = ADD32(ctx->r22, 0);
            goto L_8006AA6C;
    }
    // 0x8006AA50: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x8006AA54: jal         0x8006ABB0
    // 0x8006AA58: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8006ABB0(rdram, ctx);
        goto after_8;
    // 0x8006AA58: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_8:
    // 0x8006AA5C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8006AA60: bne         $s0, $zero, L_8006AA80
    if (ctx->r16 != 0) {
        // 0x8006AA64: nop
    
            goto L_8006AA80;
    }
    // 0x8006AA64: nop

    // 0x8006AA68: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_8006AA6C:
    // 0x8006AA6C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8006AA70: bne         $s0, $v0, L_8006AA80
    if (ctx->r16 != ctx->r2) {
        // 0x8006AA74: addu        $v0, $s5, $zero
        ctx->r2 = ADD32(ctx->r21, 0);
            goto L_8006AA80;
    }
    // 0x8006AA74: addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // 0x8006AA78: bgez        $v0, L_8006A920
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006AA7C: addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
            goto L_8006A920;
    }
    // 0x8006AA7C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_8006AA80:
    // 0x8006AA80: jal         0x80069430
    // 0x8006AA84: nop

    func_80069430(rdram, ctx);
        goto after_9;
    // 0x8006AA84: nop

    after_9:
    // 0x8006AA88: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8006AA8C:
    // 0x8006AA8C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8006AA90: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8006AA94: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8006AA98: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8006AA9C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8006AAA0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8006AAA4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8006AAA8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8006AAAC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8006AAB0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006AAB4: jr          $ra
    // 0x8006AAB8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8006AAB8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8006AAC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AAC0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8006AAC4: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    // 0x8006AAC8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8006AACC: and         $v0, $a0, $a1
    ctx->r2 = ctx->r4 & ctx->r5;
L_8006AAD0:
    // 0x8006AAD0: beq         $v0, $zero, L_8006AAEC
    if (ctx->r2 == 0) {
        // 0x8006AAD4: sll         $v1, $v1, 1
        ctx->r3 = S32(ctx->r3 << 1);
            goto L_8006AAEC;
    }
    // 0x8006AAD4: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8006AAD8: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // 0x8006AADC: beql        $v0, $zero, L_8006AAF8
    if (ctx->r2 == 0) {
        // 0x8006AAE0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8006AAF8;
    }
    goto skip_0;
    // 0x8006AAE0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8006AAE4: j           L_8006AAF8
    // 0x8006AAE8: xori        $v1, $v1, 0x14
    ctx->r3 = ctx->r3 ^ 0X14;
        goto L_8006AAF8;
    // 0x8006AAE8: xori        $v1, $v1, 0x14
    ctx->r3 = ctx->r3 ^ 0X14;
L_8006AAEC:
    // 0x8006AAEC: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // 0x8006AAF0: bnel        $v0, $zero, L_8006AAF8
    if (ctx->r2 != 0) {
        // 0x8006AAF4: xori        $v1, $v1, 0x15
        ctx->r3 = ctx->r3 ^ 0X15;
            goto L_8006AAF8;
    }
    goto skip_1;
    // 0x8006AAF4: xori        $v1, $v1, 0x15
    ctx->r3 = ctx->r3 ^ 0X15;
    skip_1:
L_8006AAF8:
    // 0x8006AAF8: srl         $a1, $a1, 1
    ctx->r5 = S32(U32(ctx->r5) >> 1);
    // 0x8006AAFC: bne         $a1, $zero, L_8006AAD0
    if (ctx->r5 != 0) {
        // 0x8006AB00: and         $v0, $a0, $a1
        ctx->r2 = ctx->r4 & ctx->r5;
            goto L_8006AAD0;
    }
    // 0x8006AB00: and         $v0, $a0, $a1
    ctx->r2 = ctx->r4 & ctx->r5;
    // 0x8006AB04: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8006AB08: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
L_8006AB0C:
    // 0x8006AB0C: andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // 0x8006AB10: bnel        $v0, $zero, L_8006AB18
    if (ctx->r2 != 0) {
        // 0x8006AB14: xori        $v1, $v1, 0x15
        ctx->r3 = ctx->r3 ^ 0X15;
            goto L_8006AB18;
    }
    goto skip_2;
    // 0x8006AB14: xori        $v1, $v1, 0x15
    ctx->r3 = ctx->r3 ^ 0X15;
    skip_2:
L_8006AB18:
    // 0x8006AB18: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8006AB1C: bnel        $a1, $zero, L_8006AB0C
    if (ctx->r5 != 0) {
        // 0x8006AB20: sll         $v1, $v1, 1
        ctx->r3 = S32(ctx->r3 << 1);
            goto L_8006AB0C;
    }
    goto skip_3;
    // 0x8006AB20: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    skip_3:
    // 0x8006AB24: jr          $ra
    // 0x8006AB28: andi        $v0, $v1, 0x1F
    ctx->r2 = ctx->r3 & 0X1F;
    return;
    // 0x8006AB28: andi        $v0, $v1, 0x1F
    ctx->r2 = ctx->r3 & 0X1F;
;}
RECOMP_FUNC void func_8006AB2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AB2C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8006AB30: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
L_8006AB34:
    // 0x8006AB34: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x8006AB38: lbu         $a3, 0x0($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X0);
    // 0x8006AB3C: and         $v0, $a3, $a1
    ctx->r2 = ctx->r7 & ctx->r5;
L_8006AB40:
    // 0x8006AB40: beq         $v0, $zero, L_8006AB5C
    if (ctx->r2 == 0) {
        // 0x8006AB44: sll         $v1, $v1, 1
        ctx->r3 = S32(ctx->r3 << 1);
            goto L_8006AB5C;
    }
    // 0x8006AB44: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8006AB48: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8006AB4C: beql        $v0, $zero, L_8006AB68
    if (ctx->r2 == 0) {
        // 0x8006AB50: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8006AB68;
    }
    goto skip_0;
    // 0x8006AB50: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8006AB54: j           L_8006AB68
    // 0x8006AB58: xori        $v1, $v1, 0x84
    ctx->r3 = ctx->r3 ^ 0X84;
        goto L_8006AB68;
    // 0x8006AB58: xori        $v1, $v1, 0x84
    ctx->r3 = ctx->r3 ^ 0X84;
L_8006AB5C:
    // 0x8006AB5C: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8006AB60: bnel        $v0, $zero, L_8006AB68
    if (ctx->r2 != 0) {
        // 0x8006AB64: xori        $v1, $v1, 0x85
        ctx->r3 = ctx->r3 ^ 0X85;
            goto L_8006AB68;
    }
    goto skip_1;
    // 0x8006AB64: xori        $v1, $v1, 0x85
    ctx->r3 = ctx->r3 ^ 0X85;
    skip_1:
L_8006AB68:
    // 0x8006AB68: srl         $a1, $a1, 1
    ctx->r5 = S32(U32(ctx->r5) >> 1);
    // 0x8006AB6C: bne         $a1, $zero, L_8006AB40
    if (ctx->r5 != 0) {
        // 0x8006AB70: and         $v0, $a3, $a1
        ctx->r2 = ctx->r7 & ctx->r5;
            goto L_8006AB40;
    }
    // 0x8006AB70: and         $v0, $a3, $a1
    ctx->r2 = ctx->r7 & ctx->r5;
    // 0x8006AB74: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8006AB78: bne         $a2, $zero, L_8006AB34
    if (ctx->r6 != 0) {
        // 0x8006AB7C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8006AB34;
    }
    // 0x8006AB7C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006AB80: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
L_8006AB84:
    // 0x8006AB84: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8006AB88: bnel        $v0, $zero, L_8006AB90
    if (ctx->r2 != 0) {
        // 0x8006AB8C: xori        $v1, $v1, 0x85
        ctx->r3 = ctx->r3 ^ 0X85;
            goto L_8006AB90;
    }
    goto skip_2;
    // 0x8006AB8C: xori        $v1, $v1, 0x85
    ctx->r3 = ctx->r3 ^ 0X85;
    skip_2:
L_8006AB90:
    // 0x8006AB90: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8006AB94: sltiu       $v0, $a2, 0x8
    ctx->r2 = ctx->r6 < 0X8 ? 1 : 0;
    // 0x8006AB98: bnel        $v0, $zero, L_8006AB84
    if (ctx->r2 != 0) {
        // 0x8006AB9C: sll         $v1, $v1, 1
        ctx->r3 = S32(ctx->r3 << 1);
            goto L_8006AB84;
    }
    goto skip_3;
    // 0x8006AB9C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    skip_3:
    // 0x8006ABA0: jr          $ra
    // 0x8006ABA4: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    return;
    // 0x8006ABA4: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
;}
RECOMP_FUNC void func_8006ABB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ABB0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006ABB4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8006ABB8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8006ABBC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8006ABC0: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x8006ABC4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8006ABC8: addiu       $v0, $zero, 0xFA
    ctx->r2 = ADD32(0, 0XFA);
    // 0x8006ABCC: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8006ABD0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8006ABD4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006ABD8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006ABDC: sb          $v0, -0x7D5C($at)
    MEM_B(-0X7D5C, ctx->r1) = ctx->r2;
    // 0x8006ABE0: jal         0x8006ACA0
    // 0x8006ABE4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8006ACA0(rdram, ctx);
        goto after_0;
    // 0x8006ABE4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8006ABE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006ABEC: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8006ABF0: addiu       $s1, $s1, 0x7960
    ctx->r17 = ADD32(ctx->r17, 0X7960);
    // 0x8006ABF4: jal         0x800677D0
    // 0x8006ABF8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_800677D0(rdram, ctx);
        goto after_1;
    // 0x8006ABF8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // 0x8006ABFC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8006AC00: addiu       $s0, $sp, 0x18
    ctx->r16 = ADD32(ctx->r29, 0X18);
    // 0x8006AC04: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8006AC08: jal         0x800619A0
    // 0x8006AC0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8006AC0C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8006AC10: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8006AC14: jal         0x800677D0
    // 0x8006AC18: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_800677D0(rdram, ctx);
        goto after_3;
    // 0x8006AC18: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
    // 0x8006AC1C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8006AC20: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8006AC24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006AC28: jal         0x800619A0
    // 0x8006AC2C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x8006AC2C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_4:
    // 0x8006AC30: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8006AC34: jal         0x8006AD34
    // 0x8006AC38: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8006AD34(rdram, ctx);
        goto after_5;
    // 0x8006AC38: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_5:
    // 0x8006AC3C: lbu         $v1, 0x12($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X12);
    // 0x8006AC40: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x8006AC44: beq         $v0, $zero, L_8006AC54
    if (ctx->r2 == 0) {
        // 0x8006AC48: andi        $v0, $v1, 0x2
        ctx->r2 = ctx->r3 & 0X2;
            goto L_8006AC54;
    }
    // 0x8006AC48: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x8006AC4C: bne         $v0, $zero, L_8006AC84
    if (ctx->r2 != 0) {
        // 0x8006AC50: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8006AC84;
    }
    // 0x8006AC50: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8006AC54:
    // 0x8006AC54: lhu         $v0, 0x12($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X12);
    // 0x8006AC58: addiu       $v1, $zero, 0x100
    ctx->r3 = ADD32(0, 0X100);
    // 0x8006AC5C: andi        $v0, $v0, 0x1FF
    ctx->r2 = ctx->r2 & 0X1FF;
    // 0x8006AC60: beq         $v0, $v1, L_8006AC70
    if (ctx->r2 == ctx->r3) {
        // 0x8006AC64: nop
    
            goto L_8006AC70;
    }
    // 0x8006AC64: nop

    // 0x8006AC68: j           L_8006AC84
    // 0x8006AC6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006AC84;
    // 0x8006AC6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006AC70:
    // 0x8006AC70: lbu         $v1, 0x12($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X12);
    // 0x8006AC74: andi        $v1, $v1, 0x4
    ctx->r3 = ctx->r3 & 0X4;
    // 0x8006AC78: bne         $v1, $zero, L_8006AC84
    if (ctx->r3 != 0) {
        // 0x8006AC7C: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8006AC84;
    }
    // 0x8006AC7C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8006AC80: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8006AC84:
    // 0x8006AC84: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8006AC88: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8006AC8C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8006AC90: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8006AC94: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006AC98: jr          $ra
    // 0x8006AC9C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006AC9C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8006ACA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ACA0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8006ACA4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8006ACA8: addiu       $v1, $v1, 0x799C
    ctx->r3 = ADD32(ctx->r3, 0X799C);
    // 0x8006ACAC: addiu       $a2, $v1, -0x3C
    ctx->r6 = ADD32(ctx->r3, -0X3C);
    // 0x8006ACB0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8006ACB4: addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // 0x8006ACB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006ACBC: sb          $v0, 0x4914($at)
    MEM_B(0X4914, ctx->r1) = ctx->r2;
    // 0x8006ACC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006ACC4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8006ACC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006ACCC: sb          $v0, 0x0($sp)
    MEM_B(0X0, ctx->r29) = ctx->r2;
    // 0x8006ACD0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8006ACD4: sb          $v0, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r2;
    // 0x8006ACD8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8006ACDC: sb          $a1, 0x2($sp)
    MEM_B(0X2, ctx->r29) = ctx->r5;
    // 0x8006ACE0: sb          $v0, 0x3($sp)
    MEM_B(0X3, ctx->r29) = ctx->r2;
    // 0x8006ACE4: sb          $v0, 0x4($sp)
    MEM_B(0X4, ctx->r29) = ctx->r2;
    // 0x8006ACE8: blez        $a0, L_8006AD04
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006ACEC: sb          $v0, 0x5($sp)
        MEM_B(0X5, ctx->r29) = ctx->r2;
            goto L_8006AD04;
    }
    // 0x8006ACEC: sb          $v0, 0x5($sp)
    MEM_B(0X5, ctx->r29) = ctx->r2;
L_8006ACF0:
    // 0x8006ACF0: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x8006ACF4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8006ACF8: slt         $v0, $a3, $a0
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8006ACFC: bne         $v0, $zero, L_8006ACF0
    if (ctx->r2 != 0) {
        // 0x8006AD00: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8006ACF0;
    }
    // 0x8006AD00: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8006AD04:
    // 0x8006AD04: lwl         $v0, 0x0($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r29, 0X0);
    // 0x8006AD08: lwr         $v0, 0x3($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r29, 0X3);
    // 0x8006AD0C: lb          $v1, 0x4($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X4);
    // 0x8006AD10: lb          $a0, 0x5($sp)
    ctx->r4 = MEM_B(ctx->r29, 0X5);
    // 0x8006AD14: swl         $v0, 0x0($a2)
    do_swl(rdram, 0X0, ctx->r6, ctx->r2);
    // 0x8006AD18: swr         $v0, 0x3($a2)
    do_swr(rdram, 0X3, ctx->r6, ctx->r2);
    // 0x8006AD1C: sb          $v1, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r3;
    // 0x8006AD20: sb          $a0, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r4;
    // 0x8006AD24: addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // 0x8006AD28: sb          $v0, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r2;
    // 0x8006AD2C: jr          $ra
    // 0x8006AD30: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8006AD30: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8006AD34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AD34: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8006AD38: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8006AD3C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8006AD40: addiu       $a2, $a2, 0x7960
    ctx->r6 = ADD32(ctx->r6, 0X7960);
    // 0x8006AD44: blez        $a0, L_8006AD5C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006AD48: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8006AD5C;
    }
    // 0x8006AD48: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8006AD4C:
    // 0x8006AD4C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006AD50: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8006AD54: bne         $v0, $zero, L_8006AD4C
    if (ctx->r2 != 0) {
        // 0x8006AD58: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8006AD4C;
    }
    // 0x8006AD58: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8006AD5C:
    // 0x8006AD5C: lwl         $v0, 0x0($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r6, 0X0);
    // 0x8006AD60: lwr         $v0, 0x3($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r6, 0X3);
    // 0x8006AD64: lb          $v1, 0x4($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X4);
    // 0x8006AD68: lb          $a0, 0x5($a2)
    ctx->r4 = MEM_B(ctx->r6, 0X5);
    // 0x8006AD6C: swl         $v0, 0x0($sp)
    do_swl(rdram, 0X0, ctx->r29, ctx->r2);
    // 0x8006AD70: swr         $v0, 0x3($sp)
    do_swr(rdram, 0X3, ctx->r29, ctx->r2);
    // 0x8006AD74: sb          $v1, 0x4($sp)
    MEM_B(0X4, ctx->r29) = ctx->r3;
    // 0x8006AD78: sb          $a0, 0x5($sp)
    MEM_B(0X5, ctx->r29) = ctx->r4;
    // 0x8006AD7C: lbu         $v0, 0x1($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1);
    // 0x8006AD80: andi        $v0, $v0, 0xC0
    ctx->r2 = ctx->r2 & 0XC0;
    // 0x8006AD84: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x8006AD88: bne         $v0, $zero, L_8006ADAC
    if (ctx->r2 != 0) {
        // 0x8006AD8C: sb          $v0, 0x3($a3)
        MEM_B(0X3, ctx->r7) = ctx->r2;
            goto L_8006ADAC;
    }
    // 0x8006AD8C: sb          $v0, 0x3($a3)
    MEM_B(0X3, ctx->r7) = ctx->r2;
    // 0x8006AD90: lbu         $v0, 0x4($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X4);
    // 0x8006AD94: lbu         $v1, 0x3($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X3);
    // 0x8006AD98: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8006AD9C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8006ADA0: sh          $v1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r3;
    // 0x8006ADA4: lbu         $v0, 0x5($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X5);
    // 0x8006ADA8: sb          $v0, 0x2($a3)
    MEM_B(0X2, ctx->r7) = ctx->r2;
L_8006ADAC:
    // 0x8006ADAC: jr          $ra
    // 0x8006ADB0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8006ADB0: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8006ADC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ADC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006ADC4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006ADC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006ADCC: jal         0x80068AE0
    // 0x8006ADD0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x8006ADD0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8006ADD4: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x8006ADD8: lw          $v1, -0x7F80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7F80);
    // 0x8006ADDC: nor         $s0, $zero, $s0
    ctx->r16 = ~(0 | ctx->r16);
    // 0x8006ADE0: ori         $s0, $s0, 0x401
    ctx->r16 = ctx->r16 | 0X401;
    // 0x8006ADE4: and         $v1, $v1, $s0
    ctx->r3 = ctx->r3 & ctx->r16;
    // 0x8006ADE8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006ADEC: sw          $v1, -0x7F80($at)
    MEM_W(-0X7F80, ctx->r1) = ctx->r3;
    // 0x8006ADF0: jal         0x80068B00
    // 0x8006ADF4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    __osRestoreInt_recomp(rdram, ctx);
        goto after_1;
    // 0x8006ADF4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // 0x8006ADF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006ADFC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006AE00: jr          $ra
    // 0x8006AE04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006AE04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8006AE10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AE10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006AE14: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006AE18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006AE1C: jal         0x80068AE0
    // 0x8006AE20: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x8006AE20: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8006AE24: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x8006AE28: lw          $v1, -0x7F80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7F80);
    // 0x8006AE2C: or          $v1, $v1, $s0
    ctx->r3 = ctx->r3 | ctx->r16;
    // 0x8006AE30: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006AE34: sw          $v1, -0x7F80($at)
    MEM_W(-0X7F80, ctx->r1) = ctx->r3;
    // 0x8006AE38: jal         0x80068B00
    // 0x8006AE3C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    __osRestoreInt_recomp(rdram, ctx);
        goto after_1;
    // 0x8006AE3C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // 0x8006AE40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006AE44: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006AE48: jr          $ra
    // 0x8006AE4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006AE4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8006AEA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8006AEC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AEC0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006AEC4: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8006AEC8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8006AECC: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8006AED0: addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // 0x8006AED4: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8006AED8: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x8006AEDC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8006AEE0: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x8006AEE4: sw          $ra, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r31;
    // 0x8006AEE8: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8006AEEC: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8006AEF0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8006AEF4: jal         0x800693C4
    // 0x8006AEF8: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    func_800693C4(rdram, ctx);
        goto after_0;
    // 0x8006AEF8: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    after_0:
    // 0x8006AEFC: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8006AF00: addiu       $s4, $s4, 0x7960
    ctx->r20 = ADD32(ctx->r20, 0X7960);
    // 0x8006AF04: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x8006AF08: addiu       $s5, $sp, 0x10
    ctx->r21 = ADD32(ctx->r29, 0X10);
L_8006AF0C:
    // 0x8006AF0C: jal         0x8006B03C
    // 0x8006AF10: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006B03C(rdram, ctx);
        goto after_1;
    // 0x8006AF10: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // 0x8006AF14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006AF18: jal         0x800677D0
    // 0x8006AF1C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_800677D0(rdram, ctx);
        goto after_2;
    // 0x8006AF1C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_2:
    // 0x8006AF20: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8006AF24: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8006AF28: jal         0x800619A0
    // 0x8006AF2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8006AF2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8006AF30: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8006AF34: jal         0x800677D0
    // 0x8006AF38: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_800677D0(rdram, ctx);
        goto after_4;
    // 0x8006AF38: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_4:
    // 0x8006AF3C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8006AF40: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8006AF44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006AF48: jal         0x800619A0
    // 0x8006AF4C: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x8006AF4C: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    after_5:
    // 0x8006AF50: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8006AF54: jal         0x8006B0E0
    // 0x8006AF58: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8006B0E0(rdram, ctx);
        goto after_6;
    // 0x8006AF58: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_6:
    // 0x8006AF5C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006AF60: lbu         $v0, -0x442C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X442C);
    // 0x8006AF64: blez        $v0, L_8006AF98
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8006AF68: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8006AF98;
    }
    // 0x8006AF68: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8006AF6C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8006AF70: addu        $v1, $s5, $zero
    ctx->r3 = ADD32(ctx->r21, 0);
L_8006AF74:
    // 0x8006AF74: lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2);
    // 0x8006AF78: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x8006AF7C: bnel        $v0, $zero, L_8006AF8C
    if (ctx->r2 != 0) {
        // 0x8006AF80: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8006AF8C;
    }
    goto skip_0;
    // 0x8006AF80: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x8006AF84: j           L_8006AF98
    // 0x8006AF88: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
        goto L_8006AF98;
    // 0x8006AF88: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_8006AF8C:
    // 0x8006AF8C: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8006AF90: bne         $v0, $zero, L_8006AF74
    if (ctx->r2 != 0) {
        // 0x8006AF94: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8006AF74;
    }
    // 0x8006AF94: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8006AF98:
    // 0x8006AF98: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8006AF9C: lbu         $v1, -0x442C($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X442C);
    // 0x8006AFA0: xor         $v0, $a0, $v1
    ctx->r2 = ctx->r4 ^ ctx->r3;
    // 0x8006AFA4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8006AFA8: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8006AFAC: and         $s0, $s0, $v0
    ctx->r16 = ctx->r16 & ctx->r2;
    // 0x8006AFB0: bgtz        $s0, L_8006AF0C
    if (SIGNED(ctx->r16) > 0) {
        // 0x8006AFB4: nop
    
            goto L_8006AF0C;
    }
    // 0x8006AFB4: nop

    // 0x8006AFB8: beq         $v1, $zero, L_8006B000
    if (ctx->r3 == 0) {
        // 0x8006AFBC: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8006B000;
    }
    // 0x8006AFBC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8006AFC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006AFC4: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x8006AFC8: addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
L_8006AFCC:
    // 0x8006AFCC: lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X3);
    // 0x8006AFD0: bnel        $v0, $zero, L_8006AFF4
    if (ctx->r2 != 0) {
        // 0x8006AFD4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8006AFF4;
    }
    goto skip_1;
    // 0x8006AFD4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_1:
    // 0x8006AFD8: lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X2);
    // 0x8006AFDC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8006AFE0: beql        $v0, $zero, L_8006AFF4
    if (ctx->r2 == 0) {
        // 0x8006AFE4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8006AFF4;
    }
    goto skip_2;
    // 0x8006AFE4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_2:
    // 0x8006AFE8: sllv        $v0, $a2, $a0
    ctx->r2 = S32(ctx->r6 << (ctx->r4 & 31));
    // 0x8006AFEC: or          $s3, $s3, $v0
    ctx->r19 = ctx->r19 | ctx->r2;
    // 0x8006AFF0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8006AFF4:
    // 0x8006AFF4: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8006AFF8: bne         $v0, $zero, L_8006AFCC
    if (ctx->r2 != 0) {
        // 0x8006AFFC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8006AFCC;
    }
    // 0x8006AFFC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8006B000:
    // 0x8006B000: jal         0x80069430
    // 0x8006B004: nop

    func_80069430(rdram, ctx);
        goto after_7;
    // 0x8006B004: nop

    after_7:
    // 0x8006B008: sb          $s3, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r19;
    // 0x8006B00C: addu        $v0, $s6, $zero
    ctx->r2 = ADD32(ctx->r22, 0);
    // 0x8006B010: lw          $ra, 0x58($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X58);
    // 0x8006B014: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8006B018: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8006B01C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8006B020: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8006B024: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8006B028: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8006B02C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8006B030: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8006B034: jr          $ra
    // 0x8006B038: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8006B038: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_8006B03C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B03C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8006B040: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006B044: lbu         $a1, -0x442C($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X442C);
    // 0x8006B048: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8006B04C: addiu       $a3, $a3, 0x7960
    ctx->r7 = ADD32(ctx->r7, 0X7960);
    // 0x8006B050: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8006B054: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006B058: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8006B05C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006B060: sw          $v0, 0x799C($at)
    MEM_W(0X799C, ctx->r1) = ctx->r2;
    // 0x8006B064: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006B068: sb          $v0, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r2;
    // 0x8006B06C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8006B070: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006B074: sb          $a0, 0x4914($at)
    MEM_B(0X4914, ctx->r1) = ctx->r4;
    // 0x8006B078: sb          $v1, 0x0($sp)
    MEM_B(0X0, ctx->r29) = ctx->r3;
    // 0x8006B07C: sb          $v0, 0x2($sp)
    MEM_B(0X2, ctx->r29) = ctx->r2;
    // 0x8006B080: sb          $a0, 0x3($sp)
    MEM_B(0X3, ctx->r29) = ctx->r4;
    // 0x8006B084: sb          $v1, 0x4($sp)
    MEM_B(0X4, ctx->r29) = ctx->r3;
    // 0x8006B088: sb          $v1, 0x5($sp)
    MEM_B(0X5, ctx->r29) = ctx->r3;
    // 0x8006B08C: sb          $v1, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r3;
    // 0x8006B090: blez        $a1, L_8006B0D0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8006B094: sb          $v1, 0x7($sp)
        MEM_B(0X7, ctx->r29) = ctx->r3;
            goto L_8006B0D0;
    }
    // 0x8006B094: sb          $v1, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r3;
L_8006B098:
    // 0x8006B098: lwl         $v0, 0x0($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r29, 0X0);
    // 0x8006B09C: lwr         $v0, 0x3($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r29, 0X3);
    // 0x8006B0A0: lwl         $v1, 0x4($sp)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r29, 0X4);
    // 0x8006B0A4: lwr         $v1, 0x7($sp)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r29, 0X7);
    // 0x8006B0A8: swl         $v0, 0x0($a3)
    do_swl(rdram, 0X0, ctx->r7, ctx->r2);
    // 0x8006B0AC: swr         $v0, 0x3($a3)
    do_swr(rdram, 0X3, ctx->r7, ctx->r2);
    // 0x8006B0B0: swl         $v1, 0x4($a3)
    do_swl(rdram, 0X4, ctx->r7, ctx->r3);
    // 0x8006B0B4: swr         $v1, 0x7($a3)
    do_swr(rdram, 0X7, ctx->r7, ctx->r3);
    // 0x8006B0B8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006B0BC: lbu         $v0, -0x442C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X442C);
    // 0x8006B0C0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8006B0C4: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006B0C8: bne         $v0, $zero, L_8006B098
    if (ctx->r2 != 0) {
        // 0x8006B0CC: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8006B098;
    }
    // 0x8006B0CC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_8006B0D0:
    // 0x8006B0D0: addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // 0x8006B0D4: sb          $v0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r2;
    // 0x8006B0D8: jr          $ra
    // 0x8006B0DC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8006B0DC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8006B0E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B0E0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8006B0E4: addu        $t3, $a0, $zero
    ctx->r11 = ADD32(ctx->r4, 0);
    // 0x8006B0E8: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // 0x8006B0EC: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8006B0F0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006B0F4: lbu         $v0, -0x442C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X442C);
    // 0x8006B0F8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006B0FC: addiu       $t0, $t0, 0x7960
    ctx->r8 = ADD32(ctx->r8, 0X7960);
    // 0x8006B100: blez        $v0, L_8006B188
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8006B104: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_8006B188;
    }
    // 0x8006B104: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8006B108: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8006B10C: addiu       $a2, $a1, 0x2
    ctx->r6 = ADD32(ctx->r5, 0X2);
L_8006B110:
    // 0x8006B110: lwl         $v0, 0x0($t0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r8, 0X0);
    // 0x8006B114: lwr         $v0, 0x3($t0)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r8, 0X3);
    // 0x8006B118: lwl         $v1, 0x4($t0)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r8, 0X4);
    // 0x8006B11C: lwr         $v1, 0x7($t0)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r8, 0X7);
    // 0x8006B120: swl         $v0, 0x0($sp)
    do_swl(rdram, 0X0, ctx->r29, ctx->r2);
    // 0x8006B124: swr         $v0, 0x3($sp)
    do_swr(rdram, 0X3, ctx->r29, ctx->r2);
    // 0x8006B128: swl         $v1, 0x4($sp)
    do_swl(rdram, 0X4, ctx->r29, ctx->r3);
    // 0x8006B12C: swr         $v1, 0x7($sp)
    do_swr(rdram, 0X7, ctx->r29, ctx->r3);
    // 0x8006B130: lbu         $v0, 0x2($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2);
    // 0x8006B134: andi        $v0, $v0, 0xC0
    ctx->r2 = ctx->r2 & 0XC0;
    // 0x8006B138: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x8006B13C: bne         $v0, $zero, L_8006B168
    if (ctx->r2 != 0) {
        // 0x8006B140: sb          $v0, 0x1($a2)
        MEM_B(0X1, ctx->r6) = ctx->r2;
            goto L_8006B168;
    }
    // 0x8006B140: sb          $v0, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r2;
    // 0x8006B144: lbu         $v0, 0x5($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X5);
    // 0x8006B148: lbu         $v1, 0x4($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X4);
    // 0x8006B14C: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8006B150: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8006B154: sh          $v1, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r3;
    // 0x8006B158: lbu         $v1, 0x6($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X6);
    // 0x8006B15C: sllv        $v0, $t4, $a3
    ctx->r2 = S32(ctx->r12 << (ctx->r7 & 31));
    // 0x8006B160: or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
    // 0x8006B164: sb          $v1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r3;
L_8006B168:
    // 0x8006B168: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8006B16C: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8006B170: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006B174: lbu         $v0, -0x442C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X442C);
    // 0x8006B178: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8006B17C: slt         $v0, $a3, $v0
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006B180: bne         $v0, $zero, L_8006B110
    if (ctx->r2 != 0) {
        // 0x8006B184: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_8006B110;
    }
    // 0x8006B184: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
L_8006B188:
    // 0x8006B188: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
    // 0x8006B18C: jr          $ra
    // 0x8006B190: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8006B190: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8006B1A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8006B330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8006B480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B480: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006B484: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8006B488: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8006B48C: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8006B490: lui         $s6, 0x800B
    ctx->r22 = S32(0X800B << 16);
    // 0x8006B494: addiu       $s6, $s6, -0x7D90
    ctx->r22 = ADD32(ctx->r22, -0X7D90);
    // 0x8006B498: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x8006B49C: addiu       $v0, $zero, 0x58
    ctx->r2 = ADD32(0, 0X58);
    // 0x8006B4A0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8006B4A4: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8006B4A8: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8006B4AC: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8006B4B0: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8006B4B4: bne         $a0, $v0, L_8006B4C4
    if (ctx->r4 != ctx->r2) {
        // 0x8006B4B8: sw          $s0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r16;
            goto L_8006B4C4;
    }
    // 0x8006B4B8: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8006B4BC: lui         $s6, 0x800B
    ctx->r22 = S32(0X800B << 16);
    // 0x8006B4C0: addiu       $s6, $s6, -0x7D7C
    ctx->r22 = ADD32(ctx->r22, -0X7D7C);
L_8006B4C4:
    // 0x8006B4C4: addiu       $v0, $zero, 0x6F
    ctx->r2 = ADD32(0, 0X6F);
    // 0x8006B4C8: beq         $a0, $v0, L_8006B4F0
    if (ctx->r4 == ctx->r2) {
        // 0x8006B4CC: xori        $v1, $a0, 0x78
        ctx->r3 = ctx->r4 ^ 0X78;
            goto L_8006B4F0;
    }
    // 0x8006B4CC: xori        $v1, $a0, 0x78
    ctx->r3 = ctx->r4 ^ 0X78;
    // 0x8006B4D0: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x8006B4D4: xori        $v0, $a0, 0x58
    ctx->r2 = ctx->r4 ^ 0X58;
    // 0x8006B4D8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8006B4DC: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8006B4E0: beq         $v1, $zero, L_8006B4F4
    if (ctx->r3 == 0) {
        // 0x8006B4E4: addiu       $s3, $zero, 0x10
        ctx->r19 = ADD32(0, 0X10);
            goto L_8006B4F4;
    }
    // 0x8006B4E4: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x8006B4E8: j           L_8006B4F4
    // 0x8006B4EC: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
        goto L_8006B4F4;
    // 0x8006B4EC: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
L_8006B4F0:
    // 0x8006B4F0: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
L_8006B4F4:
    // 0x8006B4F4: lw          $s4, 0x0($s1)
    ctx->r20 = MEM_W(ctx->r17, 0X0);
    // 0x8006B4F8: lw          $s5, 0x4($s1)
    ctx->r21 = MEM_W(ctx->r17, 0X4);
    // 0x8006B4FC: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8006B500: xori        $v1, $v0, 0x64
    ctx->r3 = ctx->r2 ^ 0X64;
    // 0x8006B504: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8006B508: xori        $v0, $v0, 0x69
    ctx->r2 = ctx->r2 ^ 0X69;
    // 0x8006B50C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006B510: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8006B514: beq         $v1, $zero, L_8006B538
    if (ctx->r3 == 0) {
        // 0x8006B518: addiu       $s2, $zero, 0x18
        ctx->r18 = ADD32(0, 0X18);
            goto L_8006B538;
    }
    // 0x8006B518: addiu       $s2, $zero, 0x18
    ctx->r18 = ADD32(0, 0X18);
    // 0x8006B51C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8006B520: bgez        $v0, L_8006B538
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006B524: nop
    
            goto L_8006B538;
    }
    // 0x8006B524: nop

    // 0x8006B528: negu        $s5, $s5
    ctx->r21 = SUB32(0, ctx->r21);
    // 0x8006B52C: negu        $s4, $s4
    ctx->r20 = SUB32(0, ctx->r20);
    // 0x8006B530: sltu        $v0, $zero, $s5
    ctx->r2 = 0 < ctx->r21 ? 1 : 0;
    // 0x8006B534: subu        $s4, $s4, $v0
    ctx->r20 = SUB32(ctx->r20, ctx->r2);
L_8006B538:
    // 0x8006B538: bnel        $s4, $zero, L_8006B558
    if (ctx->r20 != 0) {
        // 0x8006B53C: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_8006B558;
    }
    goto skip_0;
    // 0x8006B53C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_0:
    // 0x8006B540: bnel        $s5, $zero, L_8006B558
    if (ctx->r21 != 0) {
        // 0x8006B544: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_8006B558;
    }
    goto skip_1;
    // 0x8006B544: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_1:
    // 0x8006B548: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8006B54C: beq         $v0, $zero, L_8006B584
    if (ctx->r2 == 0) {
        // 0x8006B550: addu        $a3, $s3, $zero
        ctx->r7 = ADD32(ctx->r19, 0);
            goto L_8006B584;
    }
    // 0x8006B550: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // 0x8006B554: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_8006B558:
    // 0x8006B558: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // 0x8006B55C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8006B560: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8006B564: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x8006B568: addiu       $s0, $sp, 0x18
    ctx->r16 = ADD32(ctx->r29, 0X18);
    // 0x8006B56C: jal         0x8006D460
    // 0x8006B570: addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
    __umoddi3_recomp(rdram, ctx);
        goto after_0;
    // 0x8006B570: addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
    after_0:
    // 0x8006B574: addu        $v0, $s6, $v1
    ctx->r2 = ADD32(ctx->r22, ctx->r3);
    // 0x8006B578: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8006B57C: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x8006B580: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
L_8006B584:
    // 0x8006B584: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8006B588: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8006B58C: jal         0x8006D440
    // 0x8006B590: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    __udivdi3_recomp(rdram, ctx);
        goto after_1;
    // 0x8006B590: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_1:
    // 0x8006B594: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8006B598: sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
    // 0x8006B59C: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x8006B5A0: addu        $s0, $s2, $v0
    ctx->r16 = ADD32(ctx->r18, ctx->r2);
L_8006B5A4:
    // 0x8006B5A4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8006B5A8: bgtz        $v0, L_8006B5C4
    if (SIGNED(ctx->r2) > 0) {
        // 0x8006B5AC: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8006B5C4;
    }
    // 0x8006B5AC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8006B5B0: bne         $v0, $zero, L_8006B5CC
    if (ctx->r2 != 0) {
        // 0x8006B5B4: slt         $v0, $zero, $s2
        ctx->r2 = SIGNED(0) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_8006B5CC;
    }
    // 0x8006B5B4: slt         $v0, $zero, $s2
    ctx->r2 = SIGNED(0) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8006B5B8: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8006B5BC: beq         $v0, $zero, L_8006B5CC
    if (ctx->r2 == 0) {
        // 0x8006B5C0: slt         $v0, $zero, $s2
        ctx->r2 = SIGNED(0) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_8006B5CC;
    }
    // 0x8006B5C0: slt         $v0, $zero, $s2
    ctx->r2 = SIGNED(0) < SIGNED(ctx->r18) ? 1 : 0;
L_8006B5C4:
    // 0x8006B5C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8006B5C8: slt         $v0, $zero, $s2
    ctx->r2 = SIGNED(0) < SIGNED(ctx->r18) ? 1 : 0;
L_8006B5CC:
    // 0x8006B5CC: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8006B5D0: beq         $v0, $zero, L_8006B624
    if (ctx->r2 == 0) {
        // 0x8006B5D4: addu        $v1, $s3, $zero
        ctx->r3 = ADD32(ctx->r19, 0);
            goto L_8006B624;
    }
    // 0x8006B5D4: addu        $v1, $s3, $zero
    ctx->r3 = ADD32(ctx->r19, 0);
    // 0x8006B5D8: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x8006B5DC: lw          $a3, 0x4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4);
    // 0x8006B5E0: sra         $v0, $s3, 31
    ctx->r2 = S32(SIGNED(ctx->r19) >> 31);
    // 0x8006B5E4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8006B5E8: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x8006B5EC: jal         0x8006CD74
    // 0x8006B5F0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    lldiv_recomp(rdram, ctx);
        goto after_2;
    // 0x8006B5F0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x8006B5F4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8006B5F8: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8006B5FC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8006B600: sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
    // 0x8006B604: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8006B608: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8006B60C: addu        $v0, $s6, $v1
    ctx->r2 = ADD32(ctx->r22, ctx->r3);
    // 0x8006B610: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8006B614: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8006B618: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8006B61C: j           L_8006B5A4
    // 0x8006B620: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
        goto L_8006B5A4;
    // 0x8006B620: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_8006B624:
    // 0x8006B624: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x8006B628: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8006B62C: addu        $a1, $a1, $s2
    ctx->r5 = ADD32(ctx->r5, ctx->r18);
    // 0x8006B630: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8006B634: subu        $a2, $a2, $s2
    ctx->r6 = SUB32(ctx->r6, ctx->r18);
    // 0x8006B638: jal         0x80066C6C
    // 0x8006B63C: sw          $a2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r6;
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x8006B63C: sw          $a2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r6;
    after_3:
    // 0x8006B640: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8006B644: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x8006B648: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8006B64C: beq         $v0, $zero, L_8006B658
    if (ctx->r2 == 0) {
        // 0x8006B650: subu        $v0, $v1, $a0
        ctx->r2 = SUB32(ctx->r3, ctx->r4);
            goto L_8006B658;
    }
    // 0x8006B650: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // 0x8006B654: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
L_8006B658:
    // 0x8006B658: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8006B65C: bgez        $v0, L_8006B69C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006B660: addiu       $v1, $zero, 0x10
        ctx->r3 = ADD32(0, 0X10);
            goto L_8006B69C;
    }
    // 0x8006B660: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x8006B664: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x8006B668: andi        $v0, $v0, 0x14
    ctx->r2 = ctx->r2 & 0X14;
    // 0x8006B66C: bne         $v0, $v1, L_8006B69C
    if (ctx->r2 != ctx->r3) {
        // 0x8006B670: nop
    
            goto L_8006B69C;
    }
    // 0x8006B670: nop

    // 0x8006B674: lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X28);
    // 0x8006B678: lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XC);
    // 0x8006B67C: lw          $a1, 0x10($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X10);
    // 0x8006B680: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8006B684: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8006B688: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8006B68C: subu        $s2, $v0, $a0
    ctx->r18 = SUB32(ctx->r2, ctx->r4);
    // 0x8006B690: blez        $s2, L_8006B69C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8006B694: addu        $v0, $a1, $s2
        ctx->r2 = ADD32(ctx->r5, ctx->r18);
            goto L_8006B69C;
    }
    // 0x8006B694: addu        $v0, $a1, $s2
    ctx->r2 = ADD32(ctx->r5, ctx->r18);
    // 0x8006B698: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
L_8006B69C:
    // 0x8006B69C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8006B6A0: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8006B6A4: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8006B6A8: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8006B6AC: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8006B6B0: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8006B6B4: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8006B6B8: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8006B6BC: jr          $ra
    // 0x8006B6C0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8006B6C0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_8006B6D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B6D0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8006B6D4: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8006B6D8: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8006B6DC: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8006B6E0: addiu       $s1, $sp, 0x18
    ctx->r17 = ADD32(ctx->r29, 0X18);
    // 0x8006B6E4: sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // 0x8006B6E8: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8006B6EC: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8006B6F0: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8006B6F4: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8006B6F8: sdc1        $f24, 0x78($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X78, ctx->r29);
    // 0x8006B6FC: sdc1        $f22, 0x70($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X70, ctx->r29);
    // 0x8006B700: sdc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X68, ctx->r29);
    // 0x8006B704: lw          $v0, 0x24($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X24);
    // 0x8006B708: ldc1        $f20, 0x0($s3)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r19, 0X0);
    // 0x8006B70C: bgez        $v0, L_8006B71C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006B710: addu        $s5, $a1, $zero
        ctx->r21 = ADD32(ctx->r5, 0);
            goto L_8006B71C;
    }
    // 0x8006B710: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x8006B714: j           L_8006B744
    // 0x8006B718: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_8006B744;
    // 0x8006B718: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8006B71C:
    // 0x8006B71C: bne         $v0, $zero, L_8006B74C
    if (ctx->r2 != 0) {
        // 0x8006B720: addiu       $a0, $sp, 0x38
        ctx->r4 = ADD32(ctx->r29, 0X38);
            goto L_8006B74C;
    }
    // 0x8006B720: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8006B724: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // 0x8006B728: xori        $v1, $v0, 0x67
    ctx->r3 = ctx->r2 ^ 0X67;
    // 0x8006B72C: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8006B730: xori        $v0, $v0, 0x47
    ctx->r2 = ctx->r2 ^ 0X47;
    // 0x8006B734: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006B738: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8006B73C: beq         $v1, $zero, L_8006B74C
    if (ctx->r3 == 0) {
        // 0x8006B740: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006B74C;
    }
    // 0x8006B740: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006B744:
    // 0x8006B744: sw          $v0, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->r2;
    // 0x8006B748: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
L_8006B74C:
    // 0x8006B74C: jal         0x8006BB10
    // 0x8006B750: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8006BB10(rdram, ctx);
        goto after_0;
    // 0x8006B750: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_0:
    // 0x8006B754: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8006B758: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006B75C: blez        $v1, L_8006B7A0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8006B760: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8006B7A0;
    }
    // 0x8006B760: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8006B764: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8006B768: addiu       $a2, $a2, -0xA24
    ctx->r6 = ADD32(ctx->r6, -0XA24);
    // 0x8006B76C: lw          $a3, 0x8($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X8);
    // 0x8006B770: bne         $v1, $v0, L_8006B780
    if (ctx->r3 != ctx->r2) {
        // 0x8006B774: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8006B780;
    }
    // 0x8006B774: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8006B778: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8006B77C: addiu       $a2, $a2, -0xA28
    ctx->r6 = ADD32(ctx->r6, -0XA28);
L_8006B780:
    // 0x8006B780: sw          $v0, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r2;
    // 0x8006B784: lb          $v0, 0x0($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X0);
    // 0x8006B788: lb          $v1, 0x1($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X1);
    // 0x8006B78C: lb          $a0, 0x2($a2)
    ctx->r4 = MEM_B(ctx->r6, 0X2);
    // 0x8006B790: sb          $v0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r2;
    // 0x8006B794: sb          $v1, 0x1($a3)
    MEM_B(0X1, ctx->r7) = ctx->r3;
    // 0x8006B798: j           L_8006BAE0
    // 0x8006B79C: sb          $a0, 0x2($a3)
    MEM_B(0X2, ctx->r7) = ctx->r4;
        goto L_8006BAE0;
    // 0x8006B79C: sb          $a0, 0x2($a3)
    MEM_B(0X2, ctx->r7) = ctx->r4;
L_8006B7A0:
    // 0x8006B7A0: bne         $v1, $zero, L_8006B7B0
    if (ctx->r3 != 0) {
        // 0x8006B7A4: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_8006B7B0;
    }
    // 0x8006B7A4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8006B7A8: j           L_8006BAC0
    // 0x8006B7AC: sh          $zero, 0x38($sp)
    MEM_H(0X38, ctx->r29) = 0;
        goto L_8006BAC0;
    // 0x8006B7AC: sh          $zero, 0x38($sp)
    MEM_H(0X38, ctx->r29) = 0;
L_8006B7B0:
    // 0x8006B7B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006B7B4: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x8006B7B8: nop

    // 0x8006B7BC: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x8006B7C0: nop

    // 0x8006B7C4: nop

    // 0x8006B7C8: bc1tl       L_8006B7D0
    if (c1cs) {
        // 0x8006B7CC: neg.d       $f20, $f20
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
            goto L_8006B7D0;
    }
    goto skip_0;
    // 0x8006B7CC: neg.d       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
    skip_0:
L_8006B7D0:
    // 0x8006B7D0: lh          $v1, 0x38($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X38);
    // 0x8006B7D4: addiu       $v0, $zero, 0x7597
    ctx->r2 = ADD32(0, 0X7597);
    // 0x8006B7D8: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006B7DC: mflo        $v1
    ctx->r3 = lo;
    // 0x8006B7E0: lui         $v0, 0x14F8
    ctx->r2 = S32(0X14F8 << 16);
    // 0x8006B7E4: ori         $v0, $v0, 0xB589
    ctx->r2 = ctx->r2 | 0XB589;
    // 0x8006B7E8: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006B7EC: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8006B7F0: mfhi        $t0
    ctx->r8 = hi;
    // 0x8006B7F4: sra         $v0, $t0, 13
    ctx->r2 = S32(SIGNED(ctx->r8) >> 13);
    // 0x8006B7F8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8006B7FC: addiu       $v1, $v0, -0x4
    ctx->r3 = ADD32(ctx->r2, -0X4);
    // 0x8006B800: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8006B804: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006B808: bgez        $v0, L_8006B858
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006B80C: sh          $v1, 0x38($sp)
        MEM_H(0X38, ctx->r29) = ctx->r3;
            goto L_8006B858;
    }
    // 0x8006B80C: sh          $v1, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r3;
    // 0x8006B810: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8006B814: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x8006B818: addiu       $v1, $zero, -0x4
    ctx->r3 = ADD32(0, -0X4);
    // 0x8006B81C: and         $v1, $v0, $v1
    ctx->r3 = ctx->r2 & ctx->r3;
    // 0x8006B820: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x8006B824: blez        $v1, L_8006B8A4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8006B828: sh          $v0, 0x38($sp)
        MEM_H(0X38, ctx->r29) = ctx->r2;
            goto L_8006B8A4;
    }
    // 0x8006B828: sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // 0x8006B82C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006B830: addiu       $a0, $a0, -0xA70
    ctx->r4 = ADD32(ctx->r4, -0XA70);
L_8006B834:
    // 0x8006B834: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x8006B838: beq         $v0, $zero, L_8006B848
    if (ctx->r2 == 0) {
        // 0x8006B83C: sra         $v1, $v1, 1
        ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
            goto L_8006B848;
    }
    // 0x8006B83C: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8006B840: ldc1        $f0, 0x0($a0)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r4, 0X0);
    // 0x8006B844: mul.d       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f20.d = MUL_D(ctx->f20.d, ctx->f0.d);
L_8006B848:
    // 0x8006B848: bgtz        $v1, L_8006B834
    if (SIGNED(ctx->r3) > 0) {
        // 0x8006B84C: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_8006B834;
    }
    // 0x8006B84C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8006B850: j           L_8006B8A4
    // 0x8006B854: nop

        goto L_8006B8A4;
    // 0x8006B854: nop

L_8006B858:
    // 0x8006B858: blez        $v0, L_8006B8A4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8006B85C: addiu       $v0, $zero, -0x4
        ctx->r2 = ADD32(0, -0X4);
            goto L_8006B8A4;
    }
    // 0x8006B85C: addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
    // 0x8006B860: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006B864: ldc1        $f2, -0xA20($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0XA20);
    // 0x8006B868: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8006B86C: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x8006B870: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8006B874: blez        $v1, L_8006B8A0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8006B878: sh          $v0, 0x38($sp)
        MEM_H(0X38, ctx->r29) = ctx->r2;
            goto L_8006B8A0;
    }
    // 0x8006B878: sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // 0x8006B87C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006B880: addiu       $a0, $a0, -0xA70
    ctx->r4 = ADD32(ctx->r4, -0XA70);
L_8006B884:
    // 0x8006B884: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x8006B888: beq         $v0, $zero, L_8006B898
    if (ctx->r2 == 0) {
        // 0x8006B88C: sra         $v1, $v1, 1
        ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
            goto L_8006B898;
    }
    // 0x8006B88C: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8006B890: ldc1        $f0, 0x0($a0)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r4, 0X0);
    // 0x8006B894: mul.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f0.d);
L_8006B898:
    // 0x8006B898: bgtz        $v1, L_8006B884
    if (SIGNED(ctx->r3) > 0) {
        // 0x8006B89C: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_8006B884;
    }
    // 0x8006B89C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_8006B8A0:
    // 0x8006B8A0: div.d       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f2.d); 
    ctx->f20.d = DIV_D(ctx->f20.d, ctx->f2.d);
L_8006B8A4:
    // 0x8006B8A4: lw          $a0, 0x24($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X24);
    // 0x8006B8A8: andi        $v1, $s5, 0xFF
    ctx->r3 = ctx->r21 & 0XFF;
    // 0x8006B8AC: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x8006B8B0: bne         $v1, $v0, L_8006B8C4
    if (ctx->r3 != ctx->r2) {
        // 0x8006B8B4: addiu       $s2, $a0, 0x6
        ctx->r18 = ADD32(ctx->r4, 0X6);
            goto L_8006B8C4;
    }
    // 0x8006B8B4: addiu       $s2, $a0, 0x6
    ctx->r18 = ADD32(ctx->r4, 0X6);
    // 0x8006B8B8: lh          $v1, 0x38($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X38);
    // 0x8006B8BC: addiu       $v0, $a0, 0xA
    ctx->r2 = ADD32(ctx->r4, 0XA);
    // 0x8006B8C0: addu        $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
L_8006B8C4:
    // 0x8006B8C4: slti        $v0, $s2, 0x14
    ctx->r2 = SIGNED(ctx->r18) < 0X14 ? 1 : 0;
    // 0x8006B8C8: beql        $v0, $zero, L_8006B8D0
    if (ctx->r2 == 0) {
        // 0x8006B8CC: addiu       $s2, $zero, 0x13
        ctx->r18 = ADD32(0, 0X13);
            goto L_8006B8D0;
    }
    goto skip_1;
    // 0x8006B8CC: addiu       $s2, $zero, 0x13
    ctx->r18 = ADD32(0, 0X13);
    skip_1:
L_8006B8D0:
    // 0x8006B8D0: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x8006B8D4: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x8006B8D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006B8DC: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x8006B8E0: mtc1        $zero, $f25
    ctx->f_odd[(25 - 1) * 2] = 0;
    // 0x8006B8E4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006B8E8: ldc1        $f22, -0xA18($at)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r1, -0XA18);
    // 0x8006B8EC: addiu       $s4, $zero, 0x30
    ctx->r20 = ADD32(0, 0X30);
L_8006B8F0:
    // 0x8006B8F0: c.lt.d      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.d < ctx->f20.d;
    // 0x8006B8F4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8006B8F8: nop

    // 0x8006B8FC: bc1t        L_8006B908
    if (c1cs) {
        // 0x8006B900: slt         $v0, $zero, $s2
        ctx->r2 = SIGNED(0) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_8006B908;
    }
    // 0x8006B900: slt         $v0, $zero, $s2
    ctx->r2 = SIGNED(0) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8006B904: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8006B908:
    // 0x8006B908: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006B90C: beq         $v0, $zero, L_8006B994
    if (ctx->r2 == 0) {
        // 0x8006B910: addiu       $s2, $s2, -0x8
        ctx->r18 = ADD32(ctx->r18, -0X8);
            goto L_8006B994;
    }
    // 0x8006B910: addiu       $s2, $s2, -0x8
    ctx->r18 = ADD32(ctx->r18, -0X8);
    // 0x8006B914: trunc.w.d   $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.u32l = TRUNC_W_D(ctx->f20.d);
    // 0x8006B918: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8006B91C: nop

    // 0x8006B920: blez        $s2, L_8006B93C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8006B924: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_8006B93C;
    }
    // 0x8006B924: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8006B928: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x8006B92C: nop

    // 0x8006B930: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x8006B934: sub.d       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f20.d - ctx->f0.d;
    // 0x8006B938: mul.d       $f20, $f0, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f22.d); 
    ctx->f20.d = MUL_D(ctx->f0.d, ctx->f22.d);
L_8006B93C:
    // 0x8006B93C: blez        $a1, L_8006B980
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8006B940: addiu       $s0, $zero, 0x8
        ctx->r16 = ADD32(0, 0X8);
            goto L_8006B980;
    }
    // 0x8006B940: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x8006B944: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_8006B948:
    // 0x8006B948: bltz        $s0, L_8006B980
    if (SIGNED(ctx->r16) < 0) {
        // 0x8006B94C: addiu       $a0, $sp, 0x40
        ctx->r4 = ADD32(ctx->r29, 0X40);
            goto L_8006B980;
    }
    // 0x8006B94C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8006B950: jal         0x8006CCF0
    // 0x8006B954: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    ldiv_recomp(rdram, ctx);
        goto after_1;
    // 0x8006B954: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_1:
    // 0x8006B958: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8006B95C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8006B960: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x8006B964: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x8006B968: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8006B96C: bgtz        $a1, L_8006B948
    if (SIGNED(ctx->r5) > 0) {
        // 0x8006B970: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_8006B948;
    }
    // 0x8006B970: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8006B974: j           L_8006B984
    // 0x8006B978: nop

        goto L_8006B984;
    // 0x8006B978: nop

L_8006B97C:
    // 0x8006B97C: sb          $s4, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r20;
L_8006B980:
    // 0x8006B980: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_8006B984:
    // 0x8006B984: bgezl       $s0, L_8006B97C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8006B988: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8006B97C;
    }
    goto skip_2;
    // 0x8006B988: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_2:
    // 0x8006B98C: j           L_8006B8F0
    // 0x8006B990: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
        goto L_8006B8F0;
    // 0x8006B990: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_8006B994:
    // 0x8006B994: addiu       $v1, $s1, -0x1
    ctx->r3 = ADD32(ctx->r17, -0X1);
    // 0x8006B998: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x8006B99C: subu        $s2, $v1, $v0
    ctx->r18 = SUB32(ctx->r3, ctx->r2);
    // 0x8006B9A0: lhu         $v0, 0x38($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X38);
    // 0x8006B9A4: lbu         $v1, 0x19($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X19);
    // 0x8006B9A8: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x8006B9AC: sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // 0x8006B9B0: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x8006B9B4: bne         $v1, $v0, L_8006B9DC
    if (ctx->r3 != ctx->r2) {
        // 0x8006B9B8: addiu       $s1, $sp, 0x19
        ctx->r17 = ADD32(ctx->r29, 0X19);
            goto L_8006B9DC;
    }
    // 0x8006B9B8: addiu       $s1, $sp, 0x19
    ctx->r17 = ADD32(ctx->r29, 0X19);
    // 0x8006B9BC: addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
L_8006B9C0:
    // 0x8006B9C0: lhu         $v0, 0x38($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X38);
    // 0x8006B9C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006B9C8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8006B9CC: sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // 0x8006B9D0: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x8006B9D4: beq         $v0, $v1, L_8006B9C0
    if (ctx->r2 == ctx->r3) {
        // 0x8006B9D8: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_8006B9C0;
    }
    // 0x8006B9D8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_8006B9DC:
    // 0x8006B9DC: lw          $a1, 0x24($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X24);
    // 0x8006B9E0: andi        $a0, $s5, 0xFF
    ctx->r4 = ctx->r21 & 0XFF;
    // 0x8006B9E4: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x8006B9E8: bne         $a0, $v0, L_8006BA00
    if (ctx->r4 != ctx->r2) {
        // 0x8006B9EC: xori        $v1, $a0, 0x65
        ctx->r3 = ctx->r4 ^ 0X65;
            goto L_8006BA00;
    }
    // 0x8006B9EC: xori        $v1, $a0, 0x65
    ctx->r3 = ctx->r4 ^ 0X65;
    // 0x8006B9F0: lh          $v1, 0x38($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X38);
    // 0x8006B9F4: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x8006B9F8: j           L_8006BA14
    // 0x8006B9FC: addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
        goto L_8006BA14;
    // 0x8006B9FC: addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
L_8006BA00:
    // 0x8006BA00: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8006BA04: xori        $v0, $a0, 0x45
    ctx->r2 = ctx->r4 ^ 0X45;
    // 0x8006BA08: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006BA0C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8006BA10: addu        $a3, $a1, $v1
    ctx->r7 = ADD32(ctx->r5, ctx->r3);
L_8006BA14:
    // 0x8006BA14: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x8006BA18: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006BA1C: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006BA20: bnel        $v0, $zero, L_8006BA28
    if (ctx->r2 != 0) {
        // 0x8006BA24: addu        $a3, $s2, $zero
        ctx->r7 = ADD32(ctx->r18, 0);
            goto L_8006BA28;
    }
    goto skip_3;
    // 0x8006BA24: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    skip_3:
L_8006BA28:
    // 0x8006BA28: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x8006BA2C: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006BA30: blez        $a0, L_8006BAC0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006BA34: slt         $v0, $a0, $s2
        ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_8006BAC0;
    }
    // 0x8006BA34: slt         $v0, $a0, $s2
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8006BA38: beq         $v0, $zero, L_8006BA5C
    if (ctx->r2 == 0) {
        // 0x8006BA3C: addiu       $v1, $zero, 0x30
        ctx->r3 = ADD32(0, 0X30);
            goto L_8006BA5C;
    }
    // 0x8006BA3C: addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
    // 0x8006BA40: addu        $v0, $s1, $a0
    ctx->r2 = ADD32(ctx->r17, ctx->r4);
    // 0x8006BA44: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8006BA48: sltiu       $v0, $v0, 0x35
    ctx->r2 = ctx->r2 < 0X35 ? 1 : 0;
    // 0x8006BA4C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8006BA50: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8006BA54: andi        $v0, $v0, 0x39
    ctx->r2 = ctx->r2 & 0X39;
    // 0x8006BA58: ori         $v1, $v0, 0x30
    ctx->r3 = ctx->r2 | 0X30;
L_8006BA5C:
    // 0x8006BA5C: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
    // 0x8006BA60: addu        $a0, $s1, $a1
    ctx->r4 = ADD32(ctx->r17, ctx->r5);
    // 0x8006BA64: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8006BA68: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
    // 0x8006BA6C: bnel        $v0, $a2, L_8006BA8C
    if (ctx->r2 != ctx->r6) {
        // 0x8006BA70: andi        $v1, $v1, 0xFF
        ctx->r3 = ctx->r3 & 0XFF;
            goto L_8006BA8C;
    }
    goto skip_4;
    // 0x8006BA70: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    skip_4:
L_8006BA74:
    // 0x8006BA74: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8006BA78: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8006BA7C: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8006BA80: beq         $v0, $a2, L_8006BA74
    if (ctx->r2 == ctx->r6) {
        // 0x8006BA84: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_8006BA74;
    }
    // 0x8006BA84: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8006BA88: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
L_8006BA8C:
    // 0x8006BA8C: addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
    // 0x8006BA90: bne         $v1, $v0, L_8006BAA4
    if (ctx->r3 != ctx->r2) {
        // 0x8006BA94: addu        $v1, $s1, $a1
        ctx->r3 = ADD32(ctx->r17, ctx->r5);
            goto L_8006BAA4;
    }
    // 0x8006BA94: addu        $v1, $s1, $a1
    ctx->r3 = ADD32(ctx->r17, ctx->r5);
    // 0x8006BA98: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8006BA9C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006BAA0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8006BAA4:
    // 0x8006BAA4: bgez        $a1, L_8006BAC4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8006BAA8: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_8006BAC4;
    }
    // 0x8006BAA8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8006BAAC: lhu         $v0, 0x38($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X38);
    // 0x8006BAB0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8006BAB4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8006BAB8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006BABC: sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
L_8006BAC0:
    // 0x8006BAC0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_8006BAC4:
    // 0x8006BAC4: lh          $v0, 0x38($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X38);
    // 0x8006BAC8: andi        $a1, $s5, 0xFF
    ctx->r5 = ctx->r21 & 0XFF;
    // 0x8006BACC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8006BAD0: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8006BAD4: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8006BAD8: jal         0x8006BBA8
    // 0x8006BADC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_8006BBA8(rdram, ctx);
        goto after_2;
    // 0x8006BADC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
L_8006BAE0:
    // 0x8006BAE0: lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X60);
    // 0x8006BAE4: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8006BAE8: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8006BAEC: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8006BAF0: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8006BAF4: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8006BAF8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8006BAFC: ldc1        $f24, 0x78($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X78);
    // 0x8006BB00: ldc1        $f22, 0x70($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X70);
    // 0x8006BB04: ldc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X68);
    // 0x8006BB08: jr          $ra
    // 0x8006BB0C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8006BB0C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_8006BB10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BB10: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x8006BB14: andi        $v0, $v1, 0x7FF0
    ctx->r2 = ctx->r3 & 0X7FF0;
    // 0x8006BB18: srl         $a3, $v0, 4
    ctx->r7 = S32(U32(ctx->r2) >> 4);
    // 0x8006BB1C: addu        $a2, $a3, $zero
    ctx->r6 = ADD32(ctx->r7, 0);
    // 0x8006BB20: addiu       $v0, $zero, 0x7FF
    ctx->r2 = ADD32(0, 0X7FF);
    // 0x8006BB24: bne         $a2, $v0, L_8006BB6C
    if (ctx->r6 != ctx->r2) {
        // 0x8006BB28: addu        $t0, $a1, $zero
        ctx->r8 = ADD32(ctx->r5, 0);
            goto L_8006BB6C;
    }
    // 0x8006BB28: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x8006BB2C: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x8006BB30: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8006BB34: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8006BB38: bne         $v0, $zero, L_8006BBA0
    if (ctx->r2 != 0) {
        // 0x8006BB3C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8006BBA0;
    }
    // 0x8006BB3C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8006BB40: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x8006BB44: bne         $v0, $zero, L_8006BBA0
    if (ctx->r2 != 0) {
        // 0x8006BB48: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8006BBA0;
    }
    // 0x8006BB48: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8006BB4C: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x8006BB50: bne         $v0, $zero, L_8006BBA0
    if (ctx->r2 != 0) {
        // 0x8006BB54: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8006BBA0;
    }
    // 0x8006BB54: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8006BB58: lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X6);
    // 0x8006BB5C: bne         $v0, $zero, L_8006BBA0
    if (ctx->r2 != 0) {
        // 0x8006BB60: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8006BBA0;
    }
    // 0x8006BB60: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8006BB64: j           L_8006BBA0
    // 0x8006BB68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006BBA0;
    // 0x8006BB68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006BB6C:
    // 0x8006BB6C: blez        $a2, L_8006BB8C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8006BB70: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8006BB8C;
    }
    // 0x8006BB70: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006BB74: andi        $v1, $v1, 0x800F
    ctx->r3 = ctx->r3 & 0X800F;
    // 0x8006BB78: ori         $v1, $v1, 0x3FF0
    ctx->r3 = ctx->r3 | 0X3FF0;
    // 0x8006BB7C: sh          $v1, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r3;
    // 0x8006BB80: addiu       $v1, $a3, -0x3FE
    ctx->r3 = ADD32(ctx->r7, -0X3FE);
    // 0x8006BB84: j           L_8006BBA0
    // 0x8006BB88: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
        goto L_8006BBA0;
    // 0x8006BB88: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
L_8006BB8C:
    // 0x8006BB8C: bltz        $a2, L_8006BB9C
    if (SIGNED(ctx->r6) < 0) {
        // 0x8006BB90: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8006BB9C;
    }
    // 0x8006BB90: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8006BB94: j           L_8006BBA0
    // 0x8006BB98: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
        goto L_8006BBA0;
    // 0x8006BB98: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
L_8006BB9C:
    // 0x8006BB9C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8006BBA0:
    // 0x8006BBA0: jr          $ra
    // 0x8006BBA4: nop

    return;
    // 0x8006BBA4: nop

;}
RECOMP_FUNC void func_8006BBA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BBA8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006BBAC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8006BBB0: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x8006BBB4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8006BBB8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8006BBBC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8006BBC0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8006BBC4: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x8006BBC8: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8006BBCC: addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // 0x8006BBD0: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8006BBD4: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8006BBD8: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8006BBDC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006BBE0: bgtz        $a3, L_8006BBF4
    if (SIGNED(ctx->r7) > 0) {
        // 0x8006BBE4: addu        $s4, $a1, $zero
        ctx->r20 = ADD32(ctx->r5, 0);
            goto L_8006BBF4;
    }
    // 0x8006BBE4: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x8006BBE8: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8006BBEC: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x8006BBF0: addiu       $s2, $s2, -0xA10
    ctx->r18 = ADD32(ctx->r18, -0XA10);
L_8006BBF4:
    // 0x8006BBF4: andi        $a0, $s3, 0xFF
    ctx->r4 = ctx->r19 & 0XFF;
    // 0x8006BBF8: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8006BBFC: beq         $a0, $a2, L_8006BC3C
    if (ctx->r4 == ctx->r6) {
        // 0x8006BC00: xori        $v1, $a0, 0x67
        ctx->r3 = ctx->r4 ^ 0X67;
            goto L_8006BC3C;
    }
    // 0x8006BC00: xori        $v1, $a0, 0x67
    ctx->r3 = ctx->r4 ^ 0X67;
    // 0x8006BC04: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8006BC08: xori        $v0, $a0, 0x47
    ctx->r2 = ctx->r4 ^ 0X47;
    // 0x8006BC0C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006BC10: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8006BC14: beq         $v1, $zero, L_8006BEE4
    if (ctx->r3 == 0) {
        // 0x8006BC18: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_8006BEE4;
    }
    // 0x8006BC18: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x8006BC1C: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006BC20: slti        $v0, $v1, -0x4
    ctx->r2 = SIGNED(ctx->r3) < -0X4 ? 1 : 0;
    // 0x8006BC24: bne         $v0, $zero, L_8006BE94
    if (ctx->r2 != 0) {
        // 0x8006BC28: andi        $v0, $s3, 0xFF
        ctx->r2 = ctx->r19 & 0XFF;
            goto L_8006BE94;
    }
    // 0x8006BC28: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x8006BC2C: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8006BC30: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006BC34: beq         $v0, $zero, L_8006BE94
    if (ctx->r2 == 0) {
        // 0x8006BC38: andi        $v0, $s3, 0xFF
        ctx->r2 = ctx->r19 & 0XFF;
            goto L_8006BE94;
    }
    // 0x8006BC38: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
L_8006BC3C:
    // 0x8006BC3C: beq         $a0, $a2, L_8006BC84
    if (ctx->r4 == ctx->r6) {
        // 0x8006BC40: addiu       $s4, $a1, 0x1
        ctx->r20 = ADD32(ctx->r5, 0X1);
            goto L_8006BC84;
    }
    // 0x8006BC40: addiu       $s4, $a1, 0x1
    ctx->r20 = ADD32(ctx->r5, 0X1);
    // 0x8006BC44: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x8006BC48: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8006BC4C: bne         $v0, $zero, L_8006BC68
    if (ctx->r2 != 0) {
        // 0x8006BC50: sll         $v1, $s5, 16
        ctx->r3 = S32(ctx->r21 << 16);
            goto L_8006BC68;
    }
    // 0x8006BC50: sll         $v1, $s5, 16
    ctx->r3 = S32(ctx->r21 << 16);
    // 0x8006BC54: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8006BC58: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8006BC5C: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006BC60: bnel        $v0, $zero, L_8006BC68
    if (ctx->r2 != 0) {
        // 0x8006BC64: sw          $v1, 0x24($s1)
        MEM_W(0X24, ctx->r17) = ctx->r3;
            goto L_8006BC68;
    }
    goto skip_0;
    // 0x8006BC64: sw          $v1, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r3;
    skip_0:
L_8006BC68:
    // 0x8006BC68: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x8006BC6C: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8006BC70: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006BC74: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8006BC78: bgez        $v1, L_8006BC84
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8006BC7C: sw          $v1, 0x24($s1)
        MEM_W(0X24, ctx->r17) = ctx->r3;
            goto L_8006BC84;
    }
    // 0x8006BC7C: sw          $v1, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r3;
    // 0x8006BC80: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
L_8006BC84:
    // 0x8006BC84: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8006BC88: sra         $s3, $v0, 16
    ctx->r19 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006BC8C: bgtz        $s3, L_8006BD68
    if (SIGNED(ctx->r19) > 0) {
        // 0x8006BC90: sll         $v0, $s5, 16
        ctx->r2 = S32(ctx->r21 << 16);
            goto L_8006BD68;
    }
    // 0x8006BC90: sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21 << 16);
    // 0x8006BC94: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8006BC98: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x8006BC9C: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8006BCA0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8006BCA4: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x8006BCA8: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x8006BCAC: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8006BCB0: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8006BCB4: bgtz        $v0, L_8006BCCC
    if (SIGNED(ctx->r2) > 0) {
        // 0x8006BCB8: nop
    
            goto L_8006BCCC;
    }
    // 0x8006BCB8: nop

    // 0x8006BCBC: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x8006BCC0: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8006BCC4: beq         $v0, $zero, L_8006BCEC
    if (ctx->r2 == 0) {
        // 0x8006BCC8: sll         $v0, $s4, 16
        ctx->r2 = S32(ctx->r20 << 16);
            goto L_8006BCEC;
    }
    // 0x8006BCC8: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
L_8006BCCC:
    // 0x8006BCCC: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8006BCD0: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x8006BCD4: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8006BCD8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8006BCDC: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x8006BCE0: addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
    // 0x8006BCE4: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8006BCE8: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
L_8006BCEC:
    // 0x8006BCEC: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x8006BCF0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006BCF4: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8006BCF8: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006BCFC: bnel        $v0, $zero, L_8006BD04
    if (ctx->r2 != 0) {
        // 0x8006BD00: negu        $s4, $v1
        ctx->r20 = SUB32(0, ctx->r3);
            goto L_8006BD04;
    }
    goto skip_1;
    // 0x8006BD00: negu        $s4, $v1
    ctx->r20 = SUB32(0, ctx->r3);
    skip_1:
L_8006BD04:
    // 0x8006BD04: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8006BD08: lw          $a0, 0x24($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24);
    // 0x8006BD0C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006BD10: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x8006BD14: sw          $v1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r3;
    // 0x8006BD18: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8006BD1C: sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21 << 16);
    // 0x8006BD20: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006BD24: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006BD28: beq         $v0, $zero, L_8006BD34
    if (ctx->r2 == 0) {
        // 0x8006BD2C: sw          $a0, 0x24($s1)
        MEM_W(0X24, ctx->r17) = ctx->r4;
            goto L_8006BD34;
    }
    // 0x8006BD2C: sw          $a0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r4;
    // 0x8006BD30: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
L_8006BD34:
    // 0x8006BD34: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8006BD38: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8006BD3C: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8006BD40: sll         $s0, $s5, 16
    ctx->r16 = S32(ctx->r21 << 16);
    // 0x8006BD44: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8006BD48: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8006BD4C: sw          $s0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r16;
    // 0x8006BD50: jal         0x80066C6C
    // 0x8006BD54: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x8006BD54: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_0:
    // 0x8006BD58: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8006BD5C: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x8006BD60: j           L_8006C0D8
    // 0x8006BD64: sw          $v0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r2;
        goto L_8006C0D8;
    // 0x8006BD64: sw          $v0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r2;
L_8006BD68:
    // 0x8006BD68: sra         $s0, $v0, 16
    ctx->r16 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006BD6C: slt         $v0, $s0, $s3
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8006BD70: beq         $v0, $zero, L_8006BDE4
    if (ctx->r2 == 0) {
        // 0x8006BD74: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_8006BDE4;
    }
    // 0x8006BD74: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8006BD78: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8006BD7C: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8006BD80: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8006BD84: jal         0x80066C6C
    // 0x8006BD88: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    memcpy_recomp(rdram, ctx);
        goto after_1;
    // 0x8006BD88: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_1:
    // 0x8006BD8C: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x8006BD90: lw          $a0, 0x24($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24);
    // 0x8006BD94: subu        $v0, $s3, $s0
    ctx->r2 = SUB32(ctx->r19, ctx->r16);
    // 0x8006BD98: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // 0x8006BD9C: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x8006BDA0: bgtz        $a0, L_8006BDB8
    if (SIGNED(ctx->r4) > 0) {
        // 0x8006BDA4: sw          $v1, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->r3;
            goto L_8006BDB8;
    }
    // 0x8006BDA4: sw          $v1, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r3;
    // 0x8006BDA8: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x8006BDAC: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8006BDB0: beq         $v0, $zero, L_8006BDD8
    if (ctx->r2 == 0) {
        // 0x8006BDB4: nop
    
            goto L_8006BDD8;
    }
    // 0x8006BDB4: nop

L_8006BDB8:
    // 0x8006BDB8: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8006BDBC: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x8006BDC0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006BDC4: addiu       $v1, $zero, 0x2E
    ctx->r3 = ADD32(0, 0X2E);
    // 0x8006BDC8: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8006BDCC: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    // 0x8006BDD0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006BDD4: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
L_8006BDD8:
    // 0x8006BDD8: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8006BDDC: j           L_8006C0D8
    // 0x8006BDE0: sw          $v0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r2;
        goto L_8006C0D8;
    // 0x8006BDE0: sw          $v0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r2;
L_8006BDE4:
    // 0x8006BDE4: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8006BDE8: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8006BDEC: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8006BDF0: jal         0x80066C6C
    // 0x8006BDF4: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    memcpy_recomp(rdram, ctx);
        goto after_2;
    // 0x8006BDF4: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_2:
    // 0x8006BDF8: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x8006BDFC: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x8006BE00: subu        $s5, $s5, $s4
    ctx->r21 = SUB32(ctx->r21, ctx->r20);
    // 0x8006BE04: addu        $a2, $v0, $s3
    ctx->r6 = ADD32(ctx->r2, ctx->r19);
    // 0x8006BE08: bgtz        $v1, L_8006BE20
    if (SIGNED(ctx->r3) > 0) {
        // 0x8006BE0C: sw          $a2, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->r6;
            goto L_8006BE20;
    }
    // 0x8006BE0C: sw          $a2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r6;
    // 0x8006BE10: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x8006BE14: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8006BE18: beq         $v0, $zero, L_8006BE38
    if (ctx->r2 == 0) {
        // 0x8006BE1C: nop
    
            goto L_8006BE38;
    }
    // 0x8006BE1C: nop

L_8006BE20:
    // 0x8006BE20: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8006BE24: addiu       $v1, $a2, 0x1
    ctx->r3 = ADD32(ctx->r6, 0X1);
    // 0x8006BE28: sw          $v1, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r3;
    // 0x8006BE2C: addiu       $v1, $zero, 0x2E
    ctx->r3 = ADD32(0, 0X2E);
    // 0x8006BE30: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8006BE34: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_8006BE38:
    // 0x8006BE38: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x8006BE3C: sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21 << 16);
    // 0x8006BE40: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006BE44: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006BE48: bnel        $v0, $zero, L_8006BE50
    if (ctx->r2 != 0) {
        // 0x8006BE4C: addu        $s5, $v1, $zero
        ctx->r21 = ADD32(ctx->r3, 0);
            goto L_8006BE50;
    }
    goto skip_2;
    // 0x8006BE4C: addu        $s5, $v1, $zero
    ctx->r21 = ADD32(ctx->r3, 0);
    skip_2:
L_8006BE50:
    // 0x8006BE50: sll         $a1, $s4, 16
    ctx->r5 = S32(ctx->r20 << 16);
    // 0x8006BE54: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006BE58: addu        $a1, $s2, $a1
    ctx->r5 = ADD32(ctx->r18, ctx->r5);
    // 0x8006BE5C: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8006BE60: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8006BE64: sll         $s0, $s5, 16
    ctx->r16 = S32(ctx->r21 << 16);
    // 0x8006BE68: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8006BE6C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8006BE70: jal         0x80066C6C
    // 0x8006BE74: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x8006BE74: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_3:
    // 0x8006BE78: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x8006BE7C: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x8006BE80: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8006BE84: subu        $v1, $v1, $s0
    ctx->r3 = SUB32(ctx->r3, ctx->r16);
    // 0x8006BE88: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x8006BE8C: j           L_8006C0D8
    // 0x8006BE90: sw          $v1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r3;
        goto L_8006C0D8;
    // 0x8006BE90: sw          $v1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r3;
L_8006BE94:
    // 0x8006BE94: xori        $v1, $v0, 0x67
    ctx->r3 = ctx->r2 ^ 0X67;
    // 0x8006BE98: sltiu       $a0, $v1, 0x1
    ctx->r4 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8006BE9C: xori        $v0, $v0, 0x47
    ctx->r2 = ctx->r2 ^ 0X47;
    // 0x8006BEA0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006BEA4: or          $v0, $a0, $v0
    ctx->r2 = ctx->r4 | ctx->r2;
    // 0x8006BEA8: beq         $v0, $zero, L_8006BEE4
    if (ctx->r2 == 0) {
        // 0x8006BEAC: sll         $v1, $s5, 16
        ctx->r3 = S32(ctx->r21 << 16);
            goto L_8006BEE4;
    }
    // 0x8006BEAC: sll         $v1, $s5, 16
    ctx->r3 = S32(ctx->r21 << 16);
    // 0x8006BEB0: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8006BEB4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8006BEB8: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006BEBC: bnel        $v0, $zero, L_8006BEC4
    if (ctx->r2 != 0) {
        // 0x8006BEC0: sw          $v1, 0x24($s1)
        MEM_W(0X24, ctx->r17) = ctx->r3;
            goto L_8006BEC4;
    }
    goto skip_3;
    // 0x8006BEC0: sw          $v1, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r3;
    skip_3:
L_8006BEC4:
    // 0x8006BEC4: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8006BEC8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8006BECC: bgez        $v0, L_8006BED8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006BED0: sw          $v0, 0x24($s1)
        MEM_W(0X24, ctx->r17) = ctx->r2;
            goto L_8006BED8;
    }
    // 0x8006BED0: sw          $v0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r2;
    // 0x8006BED4: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
L_8006BED8:
    // 0x8006BED8: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
    // 0x8006BEDC: andi        $v0, $v0, 0x65
    ctx->r2 = ctx->r2 & 0X65;
    // 0x8006BEE0: ori         $s3, $v0, 0x45
    ctx->r19 = ctx->r2 | 0X45;
L_8006BEE4:
    // 0x8006BEE4: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8006BEE8: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8006BEEC: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x8006BEF0: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8006BEF4: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x8006BEF8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006BEFC: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8006BF00: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8006BF04: bgtz        $v0, L_8006BF1C
    if (SIGNED(ctx->r2) > 0) {
        // 0x8006BF08: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8006BF1C;
    }
    // 0x8006BF08: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8006BF0C: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x8006BF10: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8006BF14: beq         $v0, $zero, L_8006BF38
    if (ctx->r2 == 0) {
        // 0x8006BF18: nop
    
            goto L_8006BF38;
    }
    // 0x8006BF18: nop

L_8006BF1C:
    // 0x8006BF1C: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8006BF20: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x8006BF24: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8006BF28: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8006BF2C: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x8006BF30: addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
    // 0x8006BF34: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8006BF38:
    // 0x8006BF38: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x8006BF3C: blez        $v1, L_8006BF94
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8006BF40: addiu       $v0, $s5, -0x1
        ctx->r2 = ADD32(ctx->r21, -0X1);
            goto L_8006BF94;
    }
    // 0x8006BF40: addiu       $v0, $s5, -0x1
    ctx->r2 = ADD32(ctx->r21, -0X1);
    // 0x8006BF44: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x8006BF48: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8006BF4C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006BF50: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006BF54: bnel        $v0, $zero, L_8006BF5C
    if (ctx->r2 != 0) {
        // 0x8006BF58: addu        $s5, $v1, $zero
        ctx->r21 = ADD32(ctx->r3, 0);
            goto L_8006BF5C;
    }
    goto skip_4;
    // 0x8006BF58: addu        $s5, $v1, $zero
    ctx->r21 = ADD32(ctx->r3, 0);
    skip_4:
L_8006BF5C:
    // 0x8006BF5C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8006BF60: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8006BF64: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x8006BF68: sll         $s0, $s5, 16
    ctx->r16 = S32(ctx->r21 << 16);
    // 0x8006BF6C: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8006BF70: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8006BF74: jal         0x80066C6C
    // 0x8006BF78: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    memcpy_recomp(rdram, ctx);
        goto after_4;
    // 0x8006BF78: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_4:
    // 0x8006BF7C: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x8006BF80: lw          $v1, 0x24($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X24);
    // 0x8006BF84: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8006BF88: subu        $v1, $v1, $s0
    ctx->r3 = SUB32(ctx->r3, ctx->r16);
    // 0x8006BF8C: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x8006BF90: sw          $v1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r3;
L_8006BF94:
    // 0x8006BF94: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8006BF98: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x8006BF9C: addu        $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
    // 0x8006BFA0: sb          $s3, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r19;
    // 0x8006BFA4: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8006BFA8: bltz        $v0, L_8006BFC0
    if (SIGNED(ctx->r2) < 0) {
        // 0x8006BFAC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8006BFC0;
    }
    // 0x8006BFAC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8006BFB0: addiu       $v0, $zero, 0x2B
    ctx->r2 = ADD32(0, 0X2B);
    // 0x8006BFB4: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // 0x8006BFB8: j           L_8006BFD0
    // 0x8006BFBC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8006BFD0;
    // 0x8006BFBC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8006BFC0:
    // 0x8006BFC0: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
    // 0x8006BFC4: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // 0x8006BFC8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8006BFCC: negu        $s4, $s4
    ctx->r20 = SUB32(0, ctx->r20);
L_8006BFD0:
    // 0x8006BFD0: sll         $a1, $s4, 16
    ctx->r5 = S32(ctx->r20 << 16);
    // 0x8006BFD4: sra         $a0, $a1, 16
    ctx->r4 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8006BFD8: slti        $v0, $a0, 0x64
    ctx->r2 = SIGNED(ctx->r4) < 0X64 ? 1 : 0;
    // 0x8006BFDC: bne         $v0, $zero, L_8006C07C
    if (ctx->r2 != 0) {
        // 0x8006BFE0: lui         $v1, 0x6666
        ctx->r3 = S32(0X6666 << 16);
            goto L_8006C07C;
    }
    // 0x8006BFE0: lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
    // 0x8006BFE4: slti        $v0, $a0, 0x3E8
    ctx->r2 = SIGNED(ctx->r4) < 0X3E8 ? 1 : 0;
    // 0x8006BFE8: bne         $v0, $zero, L_8006C034
    if (ctx->r2 != 0) {
        // 0x8006BFEC: lui         $v1, 0x51EB
        ctx->r3 = S32(0X51EB << 16);
            goto L_8006C034;
    }
    // 0x8006BFEC: lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // 0x8006BFF0: lui         $v0, 0x1062
    ctx->r2 = S32(0X1062 << 16);
    // 0x8006BFF4: ori         $v0, $v0, 0x4DD3
    ctx->r2 = ctx->r2 | 0X4DD3;
    // 0x8006BFF8: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BFFC: sra         $v0, $a1, 31
    ctx->r2 = S32(SIGNED(ctx->r5) >> 31);
    // 0x8006C000: mfhi        $t0
    ctx->r8 = hi;
    // 0x8006C004: sra         $v1, $t0, 6
    ctx->r3 = S32(SIGNED(ctx->r8) >> 6);
    // 0x8006C008: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8006C00C: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x8006C010: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // 0x8006C014: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8006C018: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x8006C01C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8006C020: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006C024: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006C028: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8006C02C: subu        $s4, $a0, $v0
    ctx->r20 = SUB32(ctx->r4, ctx->r2);
    // 0x8006C030: lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
L_8006C034:
    // 0x8006C034: ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // 0x8006C038: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8006C03C: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006C040: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006C044: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8006C048: mfhi        $t0
    ctx->r8 = hi;
    // 0x8006C04C: sra         $v1, $t0, 5
    ctx->r3 = S32(SIGNED(ctx->r8) >> 5);
    // 0x8006C050: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8006C054: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x8006C058: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // 0x8006C05C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8006C060: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8006C064: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006C068: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8006C06C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006C070: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006C074: subu        $s4, $a0, $v0
    ctx->r20 = SUB32(ctx->r4, ctx->r2);
    // 0x8006C078: lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
L_8006C07C:
    // 0x8006C07C: ori         $v1, $v1, 0x6667
    ctx->r3 = ctx->r3 | 0X6667;
    // 0x8006C080: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8006C084: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006C088: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006C08C: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8006C090: mfhi        $t0
    ctx->r8 = hi;
    // 0x8006C094: sra         $v1, $t0, 2
    ctx->r3 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8006C098: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8006C09C: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x8006C0A0: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // 0x8006C0A4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8006C0A8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8006C0AC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006C0B0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8006C0B4: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8006C0B8: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x8006C0BC: sb          $a0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r4;
    // 0x8006C0C0: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8006C0C4: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x8006C0C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8006C0CC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006C0D0: subu        $v0, $s2, $v0
    ctx->r2 = SUB32(ctx->r18, ctx->r2);
    // 0x8006C0D4: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
L_8006C0D8:
    // 0x8006C0D8: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x8006C0DC: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x8006C0E0: andi        $v0, $v0, 0x14
    ctx->r2 = ctx->r2 & 0X14;
    // 0x8006C0E4: bne         $v0, $v1, L_8006C124
    if (ctx->r2 != ctx->r3) {
        // 0x8006C0E8: nop
    
            goto L_8006C124;
    }
    // 0x8006C0E8: nop

    // 0x8006C0EC: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x8006C0F0: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x8006C0F4: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x8006C0F8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006C0FC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006C100: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x8006C104: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x8006C108: lw          $a1, 0x28($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X28);
    // 0x8006C10C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006C110: addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // 0x8006C114: slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8006C118: beq         $v0, $zero, L_8006C124
    if (ctx->r2 == 0) {
        // 0x8006C11C: subu        $v0, $a1, $v1
        ctx->r2 = SUB32(ctx->r5, ctx->r3);
            goto L_8006C124;
    }
    // 0x8006C11C: subu        $v0, $a1, $v1
    ctx->r2 = SUB32(ctx->r5, ctx->r3);
    // 0x8006C120: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
L_8006C124:
    // 0x8006C124: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8006C128: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8006C12C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8006C130: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C134: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8006C138: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8006C13C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006C140: jr          $ra
    // 0x8006C144: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8006C144: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8006C150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C150: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006C154: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8006C158: blez        $a1, L_8006C178
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8006C15C: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8006C178;
    }
    // 0x8006C15C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8006C160:
    // 0x8006C160: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8006C164: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006C168: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8006C16C: slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8006C170: bne         $v0, $zero, L_8006C160
    if (ctx->r2 != 0) {
        // 0x8006C174: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8006C160;
    }
    // 0x8006C174: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8006C178:
    // 0x8006C178: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8006C17C: jr          $ra
    // 0x8006C180: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8006C180: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8006C184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C184: addiu       $a3, $a0, 0x1C
    ctx->r7 = ADD32(ctx->r4, 0X1C);
    // 0x8006C188: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x8006C18C: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_8006C190:
    // 0x8006C190: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8006C194: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8006C198: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006C19C: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8006C1A0: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x8006C1A4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8006C1A8: nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // 0x8006C1AC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006C1B0: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x8006C1B4: sltu        $v0, $a0, $a3
    ctx->r2 = ctx->r4 < ctx->r7 ? 1 : 0;
    // 0x8006C1B8: bne         $v0, $zero, L_8006C190
    if (ctx->r2 != 0) {
        // 0x8006C1BC: nop
    
            goto L_8006C190;
    }
    // 0x8006C1BC: nop

    // 0x8006C1C0: jr          $ra
    // 0x8006C1C4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8006C1C4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_8006C1C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C1C8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8006C1CC: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x8006C1D0: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8006C1D4: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x8006C1D8: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x8006C1DC: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x8006C1E0: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8006C1E4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006C1E8: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x8006C1EC: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x8006C1F0: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x8006C1F4: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x8006C1F8: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x8006C1FC: jal         0x80068AC0
    // 0x8006C200: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    osGetCount_recomp(rdram, ctx);
        goto after_0;
    // 0x8006C200: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    after_0:
    // 0x8006C204: sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
    // 0x8006C208: lw          $v0, 0x8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X8);
    // 0x8006C20C: lw          $v1, 0xC($s5)
    ctx->r3 = MEM_W(ctx->r21, 0XC);
    // 0x8006C210: sw          $v0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r2;
    // 0x8006C214: sw          $v1, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r3;
    // 0x8006C218: lw          $v0, 0x10($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X10);
    // 0x8006C21C: lw          $v1, 0x14($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X14);
    // 0x8006C220: sw          $v0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r2;
    // 0x8006C224: sw          $v1, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r3;
    // 0x8006C228: lbu         $v0, 0x65($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X65);
    // 0x8006C22C: beq         $v0, $zero, L_8006C248
    if (ctx->r2 == 0) {
        // 0x8006C230: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_8006C248;
    }
    // 0x8006C230: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8006C234: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8006C238: jal         0x80067500
    // 0x8006C23C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80067500(rdram, ctx);
        goto after_1;
    // 0x8006C23C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x8006C240: bne         $v0, $zero, L_8006C48C
    if (ctx->r2 != 0) {
        // 0x8006C244: nop
    
            goto L_8006C48C;
    }
    // 0x8006C244: nop

L_8006C248:
    // 0x8006C248: addiu       $s4, $sp, 0x18
    ctx->r20 = ADD32(ctx->r29, 0X18);
    // 0x8006C24C: addiu       $s6, $sp, 0x38
    ctx->r22 = ADD32(ctx->r29, 0X38);
    // 0x8006C250: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_8006C254:
    // 0x8006C254: jal         0x80067500
    // 0x8006C258: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    func_80067500(rdram, ctx);
        goto after_2;
    // 0x8006C258: andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    after_2:
    // 0x8006C25C: bne         $v0, $zero, L_8006C48C
    if (ctx->r2 != 0) {
        // 0x8006C260: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8006C48C;
    }
    // 0x8006C260: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8006C264: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x8006C268: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x8006C26C: jal         0x8006A6A0
    // 0x8006C270: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    func_8006A6A0(rdram, ctx);
        goto after_3;
    // 0x8006C270: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_3:
    // 0x8006C274: bne         $v0, $zero, L_8006C48C
    if (ctx->r2 != 0) {
        // 0x8006C278: addiu       $v1, $s4, 0x1
        ctx->r3 = ADD32(ctx->r20, 0X1);
            goto L_8006C48C;
    }
    // 0x8006C278: addiu       $v1, $s4, 0x1
    ctx->r3 = ADD32(ctx->r20, 0X1);
    // 0x8006C27C: ori         $v0, $s2, 0x80
    ctx->r2 = ctx->r18 | 0X80;
    // 0x8006C280: sb          $v0, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r2;
    // 0x8006C284: addiu       $a0, $s4, 0x20
    ctx->r4 = ADD32(ctx->r20, 0X20);
L_8006C288:
    // 0x8006C288: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8006C28C: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x8006C290: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8006C294: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006C298: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8006C29C: bne         $v0, $zero, L_8006C288
    if (ctx->r2 != 0) {
        // 0x8006C2A0: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8006C288;
    }
    // 0x8006C2A0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8006C2A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8006C2A8: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x8006C2AC: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x8006C2B0: jal         0x8006A8A0
    // 0x8006C2B4: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    func_8006A8A0(rdram, ctx);
        goto after_4;
    // 0x8006C2B4: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_4:
    // 0x8006C2B8: bne         $v0, $zero, L_8006C48C
    if (ctx->r2 != 0) {
        // 0x8006C2BC: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8006C48C;
    }
    // 0x8006C2BC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8006C2C0: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x8006C2C4: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x8006C2C8: jal         0x8006A6A0
    // 0x8006C2CC: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    func_8006A6A0(rdram, ctx);
        goto after_5;
    // 0x8006C2CC: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    after_5:
    // 0x8006C2D0: bne         $v0, $zero, L_8006C48C
    if (ctx->r2 != 0) {
        // 0x8006C2D4: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8006C48C;
    }
    // 0x8006C2D4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8006C2D8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8006C2DC: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
L_8006C2E0:
    // 0x8006C2E0: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8006C2E4: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8006C2E8: bne         $v1, $v0, L_8006C308
    if (ctx->r3 != ctx->r2) {
        // 0x8006C2EC: addiu       $v0, $zero, 0x20
        ctx->r2 = ADD32(0, 0X20);
            goto L_8006C308;
    }
    // 0x8006C2EC: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x8006C2F0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006C2F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006C2F8: slti        $v0, $s0, 0x20
    ctx->r2 = SIGNED(ctx->r16) < 0X20 ? 1 : 0;
    // 0x8006C2FC: bne         $v0, $zero, L_8006C2E0
    if (ctx->r2 != 0) {
        // 0x8006C300: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8006C2E0;
    }
    // 0x8006C300: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006C304: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_8006C308:
    // 0x8006C308: bne         $s0, $v0, L_8006C360
    if (ctx->r16 != ctx->r2) {
        // 0x8006C30C: nop
    
            goto L_8006C360;
    }
    // 0x8006C30C: nop

    // 0x8006C310: blez        $s2, L_8006C350
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8006C314: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8006C350;
    }
    // 0x8006C314: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8006C318: jal         0x80067500
    // 0x8006C31C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80067500(rdram, ctx);
        goto after_6;
    // 0x8006C31C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_6:
    // 0x8006C320: bne         $v0, $zero, L_8006C48C
    if (ctx->r2 != 0) {
        // 0x8006C324: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_8006C48C;
    }
    // 0x8006C324: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8006C328: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x8006C32C: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x8006C330: jal         0x8006A6A0
    // 0x8006C334: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    func_8006A6A0(rdram, ctx);
        goto after_7;
    // 0x8006C334: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_7:
    // 0x8006C338: bne         $v0, $zero, L_8006C48C
    if (ctx->r2 != 0) {
        // 0x8006C33C: nop
    
            goto L_8006C48C;
    }
    // 0x8006C33C: nop

    // 0x8006C340: lbu         $v1, 0x18($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X18);
    // 0x8006C344: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x8006C348: bne         $v1, $v0, L_8006C360
    if (ctx->r3 != ctx->r2) {
        // 0x8006C34C: nop
    
            goto L_8006C360;
    }
    // 0x8006C34C: nop

L_8006C350:
    // 0x8006C350: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8006C354: slti        $v0, $s2, 0x3E
    ctx->r2 = SIGNED(ctx->r18) < 0X3E ? 1 : 0;
    // 0x8006C358: bne         $v0, $zero, L_8006C254
    if (ctx->r2 != 0) {
        // 0x8006C35C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8006C254;
    }
    // 0x8006C35C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_8006C360:
    // 0x8006C360: lbu         $v0, 0x65($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X65);
    // 0x8006C364: beq         $v0, $zero, L_8006C37C
    if (ctx->r2 == 0) {
        // 0x8006C368: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8006C37C;
    }
    // 0x8006C368: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8006C36C: jal         0x80067500
    // 0x8006C370: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80067500(rdram, ctx);
        goto after_8;
    // 0x8006C370: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_8:
    // 0x8006C374: bne         $v0, $zero, L_8006C48C
    if (ctx->r2 != 0) {
        // 0x8006C378: nop
    
            goto L_8006C48C;
    }
    // 0x8006C378: nop

L_8006C37C:
    // 0x8006C37C: lhu         $v0, 0x18($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X18);
    // 0x8006C380: addiu       $a2, $s3, 0x1E
    ctx->r6 = ADD32(ctx->r19, 0X1E);
    // 0x8006C384: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8006C388: slt         $v1, $zero, $s2
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8006C38C: sb          $s2, 0x1A($s3)
    MEM_B(0X1A, ctx->r19) = ctx->r18;
    // 0x8006C390: andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
    // 0x8006C394: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8006C398: sh          $v1, 0x18($s3)
    MEM_H(0X18, ctx->r19) = ctx->r3;
    // 0x8006C39C: lbu         $v0, 0x1B($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X1B);
    // 0x8006C3A0: addiu       $a1, $s3, 0x1C
    ctx->r5 = ADD32(ctx->r19, 0X1C);
    // 0x8006C3A4: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8006C3A8: sh          $zero, 0x1E($s3)
    MEM_H(0X1E, ctx->r19) = 0;
    // 0x8006C3AC: sh          $zero, 0x1C($s3)
    MEM_H(0X1C, ctx->r19) = 0;
    // 0x8006C3B0: sb          $v0, 0x1B($s3)
    MEM_B(0X1B, ctx->r19) = ctx->r2;
L_8006C3B4:
    // 0x8006C3B4: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8006C3B8: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8006C3BC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006C3C0: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8006C3C4: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x8006C3C8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8006C3CC: nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // 0x8006C3D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006C3D4: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x8006C3D8: sltu        $v0, $a0, $a3
    ctx->r2 = ctx->r4 < ctx->r7 ? 1 : 0;
    // 0x8006C3DC: bne         $v0, $zero, L_8006C3B4
    if (ctx->r2 != 0) {
        // 0x8006C3E0: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8006C3B4;
    }
    // 0x8006C3E0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8006C3E4: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8006C3E8: addiu       $s2, $sp, 0x18
    ctx->r18 = ADD32(ctx->r29, 0X18);
    // 0x8006C3EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006C3F0: sh          $v0, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r2;
    // 0x8006C3F4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8006C3F8: sh          $v0, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r2;
    // 0x8006C3FC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8006C400: sh          $v0, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r2;
    // 0x8006C404: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8006C408: sh          $v0, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r2;
L_8006C40C:
    // 0x8006C40C: lhu         $a2, 0x40($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X40);
    // 0x8006C410: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8006C414: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x8006C418: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x8006C41C: jal         0x8006A8A0
    // 0x8006C420: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    func_8006A8A0(rdram, ctx);
        goto after_9;
    // 0x8006C420: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_9:
    // 0x8006C424: bne         $v0, $zero, L_8006C48C
    if (ctx->r2 != 0) {
        // 0x8006C428: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8006C48C;
    }
    // 0x8006C428: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006C42C: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8006C430: bne         $v0, $zero, L_8006C40C
    if (ctx->r2 != 0) {
        // 0x8006C434: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_8006C40C;
    }
    // 0x8006C434: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8006C438: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x8006C43C: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x8006C440: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006C444: jal         0x8006A6A0
    // 0x8006C448: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    func_8006A6A0(rdram, ctx);
        goto after_10;
    // 0x8006C448: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_10:
    // 0x8006C44C: beq         $v0, $zero, L_8006C464
    if (ctx->r2 == 0) {
        // 0x8006C450: addu        $a2, $s3, $zero
        ctx->r6 = ADD32(ctx->r19, 0);
            goto L_8006C464;
    }
    // 0x8006C450: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8006C454: j           L_8006C48C
    // 0x8006C458: nop

        goto L_8006C48C;
    // 0x8006C458: nop

L_8006C45C:
    // 0x8006C45C: j           L_8006C48C
    // 0x8006C460: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_8006C48C;
    // 0x8006C460: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_8006C464:
    // 0x8006C464: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8006C468: addiu       $a1, $a2, 0x20
    ctx->r5 = ADD32(ctx->r6, 0X20);
L_8006C46C:
    // 0x8006C46C: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8006C470: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x8006C474: bne         $v1, $v0, L_8006C45C
    if (ctx->r3 != ctx->r2) {
        // 0x8006C478: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8006C45C;
    }
    // 0x8006C478: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8006C47C: slt         $v0, $a2, $a1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8006C480: bne         $v0, $zero, L_8006C46C
    if (ctx->r2 != 0) {
        // 0x8006C484: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8006C46C;
    }
    // 0x8006C484: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006C488: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006C48C:
    // 0x8006C48C: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x8006C490: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x8006C494: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x8006C498: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x8006C49C: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x8006C4A0: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x8006C4A4: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x8006C4A8: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x8006C4AC: jr          $ra
    // 0x8006C4B0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8006C4B0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_8006C4B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C4B4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8006C4B8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8006C4BC: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x8006C4C0: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8006C4C4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8006C4C8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8006C4CC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8006C4D0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8006C4D4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8006C4D8: lbu         $v0, 0x65($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X65);
    // 0x8006C4DC: beq         $v0, $zero, L_8006C4F4
    if (ctx->r2 == 0) {
        // 0x8006C4E0: addu        $s2, $a1, $zero
        ctx->r18 = ADD32(ctx->r5, 0);
            goto L_8006C4F4;
    }
    // 0x8006C4E0: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8006C4E4: jal         0x80067500
    // 0x8006C4E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80067500(rdram, ctx);
        goto after_0;
    // 0x8006C4E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8006C4EC: bne         $v0, $zero, L_8006C5F4
    if (ctx->r2 != 0) {
        // 0x8006C4F0: nop
    
            goto L_8006C5F4;
    }
    // 0x8006C4F0: nop

L_8006C4F4:
    // 0x8006C4F4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8006C4F8: addiu       $s0, $sp, 0x1A
    ctx->r16 = ADD32(ctx->r29, 0X1A);
    // 0x8006C4FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006C500: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // 0x8006C504: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8006C508: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x8006C50C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8006C510: sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // 0x8006C514: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8006C518: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
L_8006C51C:
    // 0x8006C51C: lw          $a0, 0x4($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X4);
    // 0x8006C520: lw          $a1, 0x8($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X8);
    // 0x8006C524: lhu         $a2, 0x0($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X0);
    // 0x8006C528: jal         0x8006A6A0
    // 0x8006C52C: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    func_8006A6A0(rdram, ctx);
        goto after_1;
    // 0x8006C52C: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_1:
    // 0x8006C530: bne         $v0, $zero, L_8006C5F4
    if (ctx->r2 != 0) {
        // 0x8006C534: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_8006C5F4;
    }
    // 0x8006C534: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8006C538: addiu       $a3, $s2, 0x1C
    ctx->r7 = ADD32(ctx->r18, 0X1C);
    // 0x8006C53C: sh          $zero, 0x22($sp)
    MEM_H(0X22, ctx->r29) = 0;
    // 0x8006C540: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
L_8006C544:
    // 0x8006C544: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8006C548: lhu         $v1, 0x20($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X20);
    // 0x8006C54C: lhu         $a0, 0x22($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22);
    // 0x8006C550: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8006C554: addu        $a2, $v1, $v0
    ctx->r6 = ADD32(ctx->r3, ctx->r2);
    // 0x8006C558: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x8006C55C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8006C560: sltu        $v0, $a1, $a3
    ctx->r2 = ctx->r5 < ctx->r7 ? 1 : 0;
    // 0x8006C564: sh          $a2, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r6;
    // 0x8006C568: bne         $v0, $zero, L_8006C544
    if (ctx->r2 != 0) {
        // 0x8006C56C: sh          $a0, 0x22($sp)
        MEM_H(0X22, ctx->r29) = ctx->r4;
            goto L_8006C544;
    }
    // 0x8006C56C: sh          $a0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r4;
    // 0x8006C570: lhu         $v1, 0x1C($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X1C);
    // 0x8006C574: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8006C578: bnel        $v1, $v0, L_8006C594
    if (ctx->r3 != ctx->r2) {
        // 0x8006C57C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8006C594;
    }
    goto skip_0;
    // 0x8006C57C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_0:
    // 0x8006C580: lhu         $v1, 0x1E($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X1E);
    // 0x8006C584: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8006C588: beq         $v1, $v0, L_8006C5A4
    if (ctx->r3 == ctx->r2) {
        // 0x8006C58C: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8006C5A4;
    }
    // 0x8006C58C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8006C590: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8006C594:
    // 0x8006C594: slti        $v0, $s3, 0x4
    ctx->r2 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x8006C598: bne         $v0, $zero, L_8006C51C
    if (ctx->r2 != 0) {
        // 0x8006C59C: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_8006C51C;
    }
    // 0x8006C59C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8006C5A0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8006C5A4:
    // 0x8006C5A4: bne         $s3, $v0, L_8006C5B4
    if (ctx->r19 != ctx->r2) {
        // 0x8006C5A8: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8006C5B4;
    }
    // 0x8006C5A8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8006C5AC: j           L_8006C5F4
    // 0x8006C5B0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_8006C5F4;
    // 0x8006C5B0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_8006C5B4:
    // 0x8006C5B4: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8006C5B8: addiu       $s1, $sp, 0x18
    ctx->r17 = ADD32(ctx->r29, 0X18);
L_8006C5BC:
    // 0x8006C5BC: beql        $s0, $s3, L_8006C5E4
    if (ctx->r16 == ctx->r19) {
        // 0x8006C5C0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8006C5E4;
    }
    goto skip_1;
    // 0x8006C5C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x8006C5C4: lhu         $a2, 0x0($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X0);
    // 0x8006C5C8: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x8006C5CC: lw          $a0, 0x4($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X4);
    // 0x8006C5D0: lw          $a1, 0x8($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X8);
    // 0x8006C5D4: jal         0x8006A8A0
    // 0x8006C5D8: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    func_8006A8A0(rdram, ctx);
        goto after_2;
    // 0x8006C5D8: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_2:
    // 0x8006C5DC: bne         $v0, $zero, L_8006C5F4
    if (ctx->r2 != 0) {
        // 0x8006C5E0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8006C5F4;
    }
    // 0x8006C5E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8006C5E4:
    // 0x8006C5E4: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8006C5E8: bne         $v0, $zero, L_8006C5BC
    if (ctx->r2 != 0) {
        // 0x8006C5EC: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_8006C5BC;
    }
    // 0x8006C5EC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8006C5F0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006C5F4:
    // 0x8006C5F4: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x8006C5F8: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8006C5FC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8006C600: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8006C604: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8006C608: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8006C60C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8006C610: jr          $ra
    // 0x8006C614: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8006C614: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8006C618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C618: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8006C61C: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8006C620: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8006C624: sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // 0x8006C628: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x8006C62C: lbu         $v0, 0x65($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X65);
    // 0x8006C630: beq         $v0, $zero, L_8006C64C
    if (ctx->r2 == 0) {
        // 0x8006C634: nop
    
            goto L_8006C64C;
    }
    // 0x8006C634: nop

    // 0x8006C638: jal         0x80067500
    // 0x8006C63C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80067500(rdram, ctx);
        goto after_0;
    // 0x8006C63C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8006C640: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8006C644: bne         $v1, $zero, L_8006C7D0
    if (ctx->r3 != 0) {
        // 0x8006C648: nop
    
            goto L_8006C7D0;
    }
    // 0x8006C648: nop

L_8006C64C:
    // 0x8006C64C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8006C650: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8006C654: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006C658: jal         0x8006A6A0
    // 0x8006C65C: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    func_8006A6A0(rdram, ctx);
        goto after_1;
    // 0x8006C65C: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x8006C660: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8006C664: bne         $v1, $zero, L_8006C7D0
    if (ctx->r3 != 0) {
        // 0x8006C668: addiu       $a1, $sp, 0x10
        ctx->r5 = ADD32(ctx->r29, 0X10);
            goto L_8006C7D0;
    }
    // 0x8006C668: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8006C66C: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x8006C670: sh          $zero, 0x52($sp)
    MEM_H(0X52, ctx->r29) = 0;
    // 0x8006C674: sh          $zero, 0x50($sp)
    MEM_H(0X50, ctx->r29) = 0;
L_8006C678:
    // 0x8006C678: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x8006C67C: lhu         $v1, 0x50($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X50);
    // 0x8006C680: lhu         $a0, 0x52($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X52);
    // 0x8006C684: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8006C688: addu        $a2, $v1, $v0
    ctx->r6 = ADD32(ctx->r3, ctx->r2);
    // 0x8006C68C: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x8006C690: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8006C694: sltu        $v0, $a1, $a3
    ctx->r2 = ctx->r5 < ctx->r7 ? 1 : 0;
    // 0x8006C698: sh          $a2, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r6;
    // 0x8006C69C: bne         $v0, $zero, L_8006C678
    if (ctx->r2 != 0) {
        // 0x8006C6A0: sh          $a0, 0x52($sp)
        MEM_H(0X52, ctx->r29) = ctx->r4;
            goto L_8006C678;
    }
    // 0x8006C6A0: sh          $a0, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r4;
    // 0x8006C6A4: lhu         $v1, 0x2C($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X2C);
    // 0x8006C6A8: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8006C6AC: bne         $v1, $v0, L_8006C6C4
    if (ctx->r3 != ctx->r2) {
        // 0x8006C6B0: addiu       $s1, $sp, 0x10
        ctx->r17 = ADD32(ctx->r29, 0X10);
            goto L_8006C6C4;
    }
    // 0x8006C6B0: addiu       $s1, $sp, 0x10
    ctx->r17 = ADD32(ctx->r29, 0X10);
    // 0x8006C6B4: lhu         $v1, 0x2E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X2E);
    // 0x8006C6B8: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8006C6BC: beq         $v1, $v0, L_8006C70C
    if (ctx->r3 == ctx->r2) {
        // 0x8006C6C0: nop
    
            goto L_8006C70C;
    }
    // 0x8006C6C0: nop

L_8006C6C4:
    // 0x8006C6C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006C6C8: jal         0x8006C4B4
    // 0x8006C6CC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8006C4B4(rdram, ctx);
        goto after_2;
    // 0x8006C6CC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_2:
    // 0x8006C6D0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8006C6D4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8006C6D8: bne         $v1, $v0, L_8006C704
    if (ctx->r3 != ctx->r2) {
        // 0x8006C6DC: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8006C704;
    }
    // 0x8006C6DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006C6E0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8006C6E4: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // 0x8006C6E8: jal         0x8006C1C8
    // 0x8006C6EC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8006C1C8(rdram, ctx);
        goto after_3;
    // 0x8006C6EC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_3:
    // 0x8006C6F0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8006C6F4: beq         $v1, $zero, L_8006C70C
    if (ctx->r3 == 0) {
        // 0x8006C6F8: nop
    
            goto L_8006C70C;
    }
    // 0x8006C6F8: nop

    // 0x8006C6FC: j           L_8006C7D0
    // 0x8006C700: nop

        goto L_8006C7D0;
    // 0x8006C700: nop

L_8006C704:
    // 0x8006C704: bne         $v1, $zero, L_8006C7D0
    if (ctx->r3 != 0) {
        // 0x8006C708: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8006C7D0;
    }
    // 0x8006C708: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8006C70C:
    // 0x8006C70C: lhu         $v0, 0x18($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X18);
    // 0x8006C710: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8006C714: bne         $v0, $zero, L_8006C754
    if (ctx->r2 != 0) {
        // 0x8006C718: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8006C754;
    }
    // 0x8006C718: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8006C71C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006C720: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8006C724: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // 0x8006C728: jal         0x8006C1C8
    // 0x8006C72C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8006C1C8(rdram, ctx);
        goto after_4;
    // 0x8006C72C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_4:
    // 0x8006C730: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8006C734: bne         $v1, $zero, L_8006C7D0
    if (ctx->r3 != 0) {
        // 0x8006C738: nop
    
            goto L_8006C7D0;
    }
    // 0x8006C738: nop

    // 0x8006C73C: lhu         $v0, 0x48($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X48);
    // 0x8006C740: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8006C744: bne         $v0, $zero, L_8006C754
    if (ctx->r2 != 0) {
        // 0x8006C748: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8006C754;
    }
    // 0x8006C748: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8006C74C: j           L_8006C7D0
    // 0x8006C750: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_8006C7D0;
    // 0x8006C750: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_8006C754:
    // 0x8006C754: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x8006C758: jal         0x80066850
    // 0x8006C75C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    bcopy_recomp(rdram, ctx);
        goto after_5;
    // 0x8006C75C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_5:
    // 0x8006C760: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8006C764: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8006C768: lbu         $v0, 0x1B($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1B);
    // 0x8006C76C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8006C770: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x8006C774: lbu         $v1, 0x1A($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X1A);
    // 0x8006C778: addiu       $a3, $s0, 0x2C
    ctx->r7 = ADD32(ctx->r16, 0X2C);
    // 0x8006C77C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8006C780: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x8006C784: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8006C788: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x8006C78C: sb          $v1, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r3;
    // 0x8006C790: lbu         $v0, 0x64($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X64);
    // 0x8006C794: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8006C798: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // 0x8006C79C: sw          $v1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r3;
    // 0x8006C7A0: lbu         $v1, 0x64($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X64);
    // 0x8006C7A4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006C7A8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8006C7AC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8006C7B0: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x8006C7B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006C7B8: jal         0x8006A6A0
    // 0x8006C7BC: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
    func_8006A6A0(rdram, ctx);
        goto after_6;
    // 0x8006C7BC: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
    after_6:
    // 0x8006C7C0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8006C7C4: sltu        $v0, $zero, $v1
    ctx->r2 = 0 < ctx->r3 ? 1 : 0;
    // 0x8006C7C8: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8006C7CC: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
L_8006C7D0:
    // 0x8006C7D0: lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X60);
    // 0x8006C7D4: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x8006C7D8: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8006C7DC: jr          $ra
    // 0x8006C7E0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8006C7E0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8006C7E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C7E4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006C7E8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8006C7EC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8006C7F0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006C7F4: lbu         $v0, 0x65($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X65);
    // 0x8006C7F8: beq         $v0, $zero, L_8006C82C
    if (ctx->r2 == 0) {
        // 0x8006C7FC: nop
    
            goto L_8006C82C;
    }
    // 0x8006C7FC: nop

    // 0x8006C800: jal         0x80067500
    // 0x8006C804: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80067500(rdram, ctx);
        goto after_0;
    // 0x8006C804: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8006C808: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8006C80C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8006C810: bne         $v1, $v0, L_8006C824
    if (ctx->r3 != ctx->r2) {
        // 0x8006C814: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8006C824;
    }
    // 0x8006C814: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006C818: jal         0x80067500
    // 0x8006C81C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80067500(rdram, ctx);
        goto after_1;
    // 0x8006C81C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x8006C820: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8006C824:
    // 0x8006C824: bne         $v1, $zero, L_8006C88C
    if (ctx->r3 != 0) {
        // 0x8006C828: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8006C88C;
    }
    // 0x8006C828: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8006C82C:
    // 0x8006C82C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8006C830: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8006C834: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006C838: jal         0x8006A6A0
    // 0x8006C83C: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    func_8006A6A0(rdram, ctx);
        goto after_2;
    // 0x8006C83C: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_2:
    // 0x8006C840: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8006C844: beq         $v1, $zero, L_8006C874
    if (ctx->r3 == 0) {
        // 0x8006C848: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8006C874;
    }
    // 0x8006C848: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8006C84C: bne         $v1, $v0, L_8006C88C
    if (ctx->r3 != ctx->r2) {
        // 0x8006C850: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8006C88C;
    }
    // 0x8006C850: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8006C854: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8006C858: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8006C85C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006C860: jal         0x8006A6A0
    // 0x8006C864: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    func_8006A6A0(rdram, ctx);
        goto after_3;
    // 0x8006C864: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x8006C868: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8006C86C: bne         $v1, $zero, L_8006C88C
    if (ctx->r3 != 0) {
        // 0x8006C870: nop
    
            goto L_8006C88C;
    }
    // 0x8006C870: nop

L_8006C874:
    // 0x8006C874: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x8006C878: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8006C87C: jal         0x8006CBE0
    // 0x8006C880: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    bcmp_recomp(rdram, ctx);
        goto after_4;
    // 0x8006C880: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_4:
    // 0x8006C884: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8006C888: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_8006C88C:
    // 0x8006C88C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8006C890: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8006C894: jr          $ra
    // 0x8006C898: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006C898: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8006C89C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C89C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8006C8A0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8006C8A4: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8006C8A8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8006C8AC: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x8006C8B0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8006C8B4: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x8006C8B8: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8006C8BC: addu        $s7, $a3, $zero
    ctx->r23 = ADD32(ctx->r7, 0);
    // 0x8006C8C0: andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // 0x8006C8C4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8006C8C8: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8006C8CC: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8006C8D0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8006C8D4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8006C8D8: bne         $v0, $zero, L_8006C920
    if (ctx->r2 != 0) {
        // 0x8006C8DC: sw          $s0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r16;
            goto L_8006C920;
    }
    // 0x8006C8DC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8006C8E0: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x8006C8E4: lbu         $v1, -0x7D5C($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X7D5C);
    // 0x8006C8E8: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x8006C8EC: bne         $v0, $v1, L_8006C920
    if (ctx->r2 != ctx->r3) {
        // 0x8006C8F0: nop
    
            goto L_8006C920;
    }
    // 0x8006C8F0: nop

    // 0x8006C8F4: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x8006C8F8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8006C8FC: lw          $v0, -0x7D60($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D60);
    // 0x8006C900: bne         $v1, $v0, L_8006C920
    if (ctx->r3 != ctx->r2) {
        // 0x8006C904: nop
    
            goto L_8006C920;
    }
    // 0x8006C904: nop

    // 0x8006C908: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006C90C: addiu       $a0, $a0, 0x74B0
    ctx->r4 = ADD32(ctx->r4, 0X74B0);
    // 0x8006C910: jal         0x80066850
    // 0x8006C914: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    bcopy_recomp(rdram, ctx);
        goto after_0;
    // 0x8006C914: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    after_0:
    // 0x8006C918: j           L_8006CBA4
    // 0x8006C91C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8006CBA4;
    // 0x8006C91C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006C920:
    // 0x8006C920: lbu         $v0, 0x65($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X65);
    // 0x8006C924: beq         $v0, $zero, L_8006C940
    if (ctx->r2 == 0) {
        // 0x8006C928: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_8006C940;
    }
    // 0x8006C928: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8006C92C: jal         0x80067500
    // 0x8006C930: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80067500(rdram, ctx);
        goto after_1;
    // 0x8006C930: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x8006C934: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8006C938: bne         $v1, $zero, L_8006CBA4
    if (ctx->r3 != 0) {
        // 0x8006C93C: nop
    
            goto L_8006CBA4;
    }
    // 0x8006C93C: nop

L_8006C940:
    // 0x8006C940: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x8006C944: bne         $v0, $zero, L_8006C950
    if (ctx->r2 != 0) {
        // 0x8006C948: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_8006C950;
    }
    // 0x8006C948: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8006C94C: lw          $s5, 0x60($s2)
    ctx->r21 = MEM_W(ctx->r18, 0X60);
L_8006C950:
    // 0x8006C950: andi        $v1, $s6, 0xFF
    ctx->r3 = ctx->r22 & 0XFF;
    // 0x8006C954: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006C958: bne         $v1, $v0, L_8006C9A0
    if (ctx->r3 != ctx->r2) {
        // 0x8006C95C: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8006C9A0;
    }
    // 0x8006C95C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8006C960: sll         $v0, $s5, 1
    ctx->r2 = S32(ctx->r21 << 1);
    // 0x8006C964: addu        $a1, $v0, $s4
    ctx->r5 = ADD32(ctx->r2, ctx->r20);
    // 0x8006C968: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8006C96C: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x8006C970: subu        $v0, $v0, $s5
    ctx->r2 = SUB32(ctx->r2, ctx->r21);
    // 0x8006C974: sll         $a2, $v0, 1
    ctx->r6 = S32(ctx->r2 << 1);
    // 0x8006C978: blez        $a2, L_8006C998
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8006C97C: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8006C998;
    }
    // 0x8006C97C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8006C980:
    // 0x8006C980: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8006C984: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006C988: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006C98C: slt         $v0, $a0, $a2
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8006C990: bne         $v0, $zero, L_8006C980
    if (ctx->r2 != 0) {
        // 0x8006C994: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8006C980;
    }
    // 0x8006C994: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8006C998:
    // 0x8006C998: sb          $v1, 0x1($s4)
    MEM_B(0X1, ctx->r20) = ctx->r3;
    // 0x8006C99C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8006C9A0:
    // 0x8006C9A0: andi        $fp, $s6, 0xFF
    ctx->r30 = ctx->r22 & 0XFF;
    // 0x8006C9A4: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x8006C9A8: sll         $s3, $v0, 3
    ctx->r19 = S32(ctx->r2 << 3);
    // 0x8006C9AC: sll         $v0, $s0, 5
    ctx->r2 = S32(ctx->r16 << 5);
L_8006C9B0:
    // 0x8006C9B0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8006C9B4: bne         $fp, $t0, L_8006CA0C
    if (ctx->r30 != ctx->r8) {
        // 0x8006C9B8: addu        $s1, $s4, $v0
        ctx->r17 = ADD32(ctx->r20, ctx->r2);
            goto L_8006CA0C;
    }
    // 0x8006C9B8: addu        $s1, $s4, $v0
    ctx->r17 = ADD32(ctx->r20, ctx->r2);
    // 0x8006C9BC: lw          $a2, 0x54($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X54);
    // 0x8006C9C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8006C9C4: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x8006C9C8: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x8006C9CC: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x8006C9D0: addu        $a2, $a2, $s3
    ctx->r6 = ADD32(ctx->r6, ctx->r19);
    // 0x8006C9D4: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x8006C9D8: jal         0x8006A8A0
    // 0x8006C9DC: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_8006A8A0(rdram, ctx);
        goto after_2;
    // 0x8006C9DC: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_2:
    // 0x8006C9E0: lw          $a2, 0x58($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X58);
    // 0x8006C9E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8006C9E8: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x8006C9EC: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x8006C9F0: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x8006C9F4: addu        $a2, $a2, $s3
    ctx->r6 = ADD32(ctx->r6, ctx->r19);
    // 0x8006C9F8: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x8006C9FC: jal         0x8006A8A0
    // 0x8006CA00: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_8006A8A0(rdram, ctx);
        goto after_3;
    // 0x8006CA00: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_3:
    // 0x8006CA04: j           L_8006CA30
    // 0x8006CA08: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
        goto L_8006CA30;
    // 0x8006CA08: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8006CA0C:
    // 0x8006CA0C: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x8006CA10: lw          $a2, 0x54($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X54);
    // 0x8006CA14: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x8006CA18: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x8006CA1C: addu        $a2, $a2, $s3
    ctx->r6 = ADD32(ctx->r6, ctx->r19);
    // 0x8006CA20: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x8006CA24: jal         0x8006A6A0
    // 0x8006CA28: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_8006A6A0(rdram, ctx);
        goto after_4;
    // 0x8006CA28: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_4:
    // 0x8006CA2C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8006CA30:
    // 0x8006CA30: bne         $v1, $zero, L_8006CB28
    if (ctx->r3 != 0) {
        // 0x8006CA34: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8006CB28;
    }
    // 0x8006CA34: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006CA38: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8006CA3C: bne         $v0, $zero, L_8006C9B0
    if (ctx->r2 != 0) {
        // 0x8006CA40: sll         $v0, $s0, 5
        ctx->r2 = S32(ctx->r16 << 5);
            goto L_8006C9B0;
    }
    // 0x8006CA40: sll         $v0, $s0, 5
    ctx->r2 = S32(ctx->r16 << 5);
    // 0x8006CA44: andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // 0x8006CA48: bnel        $v0, $zero, L_8006CB7C
    if (ctx->r2 != 0) {
        // 0x8006CA4C: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_8006CB7C;
    }
    goto skip_0;
    // 0x8006CA4C: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    skip_0:
    // 0x8006CA50: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8006CA54: sll         $v0, $s5, 1
    ctx->r2 = S32(ctx->r21 << 1);
    // 0x8006CA58: addu        $a1, $v0, $s4
    ctx->r5 = ADD32(ctx->r2, ctx->r20);
    // 0x8006CA5C: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x8006CA60: subu        $v0, $v0, $s5
    ctx->r2 = SUB32(ctx->r2, ctx->r21);
    // 0x8006CA64: sll         $a2, $v0, 1
    ctx->r6 = S32(ctx->r2 << 1);
    // 0x8006CA68: slt         $v0, $v1, $a2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8006CA6C: beq         $v0, $zero, L_8006CA8C
    if (ctx->r2 == 0) {
        // 0x8006CA70: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8006CA8C;
    }
    // 0x8006CA70: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8006CA74:
    // 0x8006CA74: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8006CA78: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006CA7C: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x8006CA80: slt         $v0, $a0, $a2
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8006CA84: bne         $v0, $zero, L_8006CA74
    if (ctx->r2 != 0) {
        // 0x8006CA88: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8006CA74;
    }
    // 0x8006CA88: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8006CA8C:
    // 0x8006CA8C: lbu         $v1, 0x1($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X1);
    // 0x8006CA90: andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // 0x8006CA94: beq         $v0, $v1, L_8006CB78
    if (ctx->r2 == ctx->r3) {
        // 0x8006CA98: andi        $v0, $s7, 0xFF
        ctx->r2 = ctx->r23 & 0XFF;
            goto L_8006CB78;
    }
    // 0x8006CA98: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x8006CA9C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8006CAA0: sll         $s3, $v0, 3
    ctx->r19 = S32(ctx->r2 << 3);
    // 0x8006CAA4: addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
L_8006CAA8:
    // 0x8006CAA8: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x8006CAAC: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x8006CAB0: lw          $a2, 0x58($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X58);
    // 0x8006CAB4: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x8006CAB8: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x8006CABC: addu        $a2, $a2, $s3
    ctx->r6 = ADD32(ctx->r6, ctx->r19);
    // 0x8006CAC0: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x8006CAC4: jal         0x8006A6A0
    // 0x8006CAC8: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_8006A6A0(rdram, ctx);
        goto after_5;
    // 0x8006CAC8: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_5:
    // 0x8006CACC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006CAD0: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8006CAD4: bne         $v0, $zero, L_8006CAA8
    if (ctx->r2 != 0) {
        // 0x8006CAD8: addiu       $v1, $zero, 0x80
        ctx->r3 = ADD32(0, 0X80);
            goto L_8006CAA8;
    }
    // 0x8006CAD8: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
    // 0x8006CADC: sll         $v0, $s5, 1
    ctx->r2 = S32(ctx->r21 << 1);
    // 0x8006CAE0: addu        $a2, $v0, $s4
    ctx->r6 = ADD32(ctx->r2, ctx->r20);
    // 0x8006CAE4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8006CAE8: subu        $v1, $v1, $s5
    ctx->r3 = SUB32(ctx->r3, ctx->r21);
    // 0x8006CAEC: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8006CAF0: blez        $v1, L_8006CB10
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8006CAF4: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8006CB10;
    }
    // 0x8006CAF4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8006CAF8:
    // 0x8006CAF8: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x8006CAFC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006CB00: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8006CB04: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8006CB08: bne         $v0, $zero, L_8006CAF8
    if (ctx->r2 != 0) {
        // 0x8006CB0C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8006CAF8;
    }
    // 0x8006CB0C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8006CB10:
    // 0x8006CB10: lbu         $v1, 0x1($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X1);
    // 0x8006CB14: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8006CB18: beq         $v0, $v1, L_8006CB30
    if (ctx->r2 == ctx->r3) {
        // 0x8006CB1C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8006CB30;
    }
    // 0x8006CB1C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8006CB20: j           L_8006CBA4
    // 0x8006CB24: nop

        goto L_8006CBA4;
    // 0x8006CB24: nop

L_8006CB28:
    // 0x8006CB28: j           L_8006CBA4
    // 0x8006CB2C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8006CBA4;
    // 0x8006CB2C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8006CB30:
    // 0x8006CB30: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8006CB34: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x8006CB38: sll         $s3, $v0, 3
    ctx->r19 = S32(ctx->r2 << 3);
    // 0x8006CB3C: addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
L_8006CB40:
    // 0x8006CB40: lw          $a2, 0x54($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X54);
    // 0x8006CB44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8006CB48: lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X4);
    // 0x8006CB4C: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x8006CB50: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x8006CB54: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x8006CB58: addu        $a2, $a2, $s3
    ctx->r6 = ADD32(ctx->r6, ctx->r19);
    // 0x8006CB5C: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x8006CB60: jal         0x8006A8A0
    // 0x8006CB64: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    func_8006A8A0(rdram, ctx);
        goto after_6;
    // 0x8006CB64: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_6:
    // 0x8006CB68: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006CB6C: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8006CB70: bne         $v0, $zero, L_8006CB40
    if (ctx->r2 != 0) {
        // 0x8006CB74: nop
    
            goto L_8006CB40;
    }
    // 0x8006CB74: nop

L_8006CB78:
    // 0x8006CB78: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
L_8006CB7C:
    // 0x8006CB7C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006CB80: addiu       $a1, $a1, 0x74B0
    ctx->r5 = ADD32(ctx->r5, 0X74B0);
    // 0x8006CB84: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006CB88: sb          $s7, -0x7D5C($at)
    MEM_B(-0X7D5C, ctx->r1) = ctx->r23;
    // 0x8006CB8C: jal         0x80066850
    // 0x8006CB90: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    bcopy_recomp(rdram, ctx);
        goto after_7;
    // 0x8006CB90: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    after_7:
    // 0x8006CB94: lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8);
    // 0x8006CB98: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8006CB9C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006CBA0: sw          $v1, -0x7D60($at)
    MEM_W(-0X7D60, ctx->r1) = ctx->r3;
L_8006CBA4:
    // 0x8006CBA4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CBA8: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8006CBAC: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8006CBB0: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8006CBB4: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8006CBB8: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8006CBBC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8006CBC0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8006CBC4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8006CBC8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8006CBCC: jr          $ra
    // 0x8006CBD0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8006CBD0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void bcmp_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CBE0: xor         $v0, $a0, $a1
    ctx->r2 = ctx->r4 ^ ctx->r5;
    // 0x8006CBE4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x8006CBE8: bne         $at, $zero, L_8006CCBC
    if (ctx->r1 != 0) {
        // 0x8006CBEC: nop
    
            goto L_8006CCBC;
    }
    // 0x8006CBEC: nop

    // 0x8006CBF0: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8006CBF4: bne         $v0, $zero, L_8006CC58
    if (ctx->r2 != 0) {
        // 0x8006CBF8: negu        $t8, $a0
        ctx->r24 = SUB32(0, ctx->r4);
            goto L_8006CC58;
    }
    // 0x8006CBF8: negu        $t8, $a0
    ctx->r24 = SUB32(0, ctx->r4);
    // 0x8006CBFC: andi        $t8, $t8, 0x3
    ctx->r24 = ctx->r24 & 0X3;
    // 0x8006CC00: beq         $t8, $zero, L_8006CC20
    if (ctx->r24 == 0) {
        // 0x8006CC04: subu        $a2, $a2, $t8
        ctx->r6 = SUB32(ctx->r6, ctx->r24);
            goto L_8006CC20;
    }
    // 0x8006CC04: subu        $a2, $a2, $t8
    ctx->r6 = SUB32(ctx->r6, ctx->r24);
    // 0x8006CC08: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8006CC0C: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    // 0x8006CC10: lwl         $v1, 0x0($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r5, 0X0);
    // 0x8006CC14: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x8006CC18: bne         $v0, $v1, L_8006CCE8
    if (ctx->r2 != ctx->r3) {
        // 0x8006CC1C: addu        $a1, $a1, $t8
        ctx->r5 = ADD32(ctx->r5, ctx->r24);
            goto L_8006CCE8;
    }
    // 0x8006CC1C: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
L_8006CC20:
    // 0x8006CC20: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8006CC24: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x8006CC28: beq         $a3, $zero, L_8006CCBC
    if (ctx->r7 == 0) {
        // 0x8006CC2C: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_8006CCBC;
    }
    // 0x8006CC2C: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x8006CC30: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_8006CC34:
    // 0x8006CC34: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8006CC38: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8006CC3C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8006CC40: bne         $v0, $v1, L_8006CCE8
    if (ctx->r2 != ctx->r3) {
        // 0x8006CC44: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8006CCE8;
    }
    // 0x8006CC44: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8006CC48: bne         $a0, $a3, L_8006CC34
    if (ctx->r4 != ctx->r7) {
        // 0x8006CC4C: nop
    
            goto L_8006CC34;
    }
    // 0x8006CC4C: nop

    // 0x8006CC50: b           L_8006CCBC
    // 0x8006CC54: nop

        goto L_8006CCBC;
    // 0x8006CC54: nop

L_8006CC58:
    // 0x8006CC58: negu        $a3, $a1
    ctx->r7 = SUB32(0, ctx->r5);
    // 0x8006CC5C: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x8006CC60: beq         $a3, $zero, L_8006CC88
    if (ctx->r7 == 0) {
        // 0x8006CC64: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_8006CC88;
    }
    // 0x8006CC64: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x8006CC68: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_8006CC6C:
    // 0x8006CC6C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8006CC70: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8006CC74: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006CC78: bne         $v0, $v1, L_8006CCE8
    if (ctx->r2 != ctx->r3) {
        // 0x8006CC7C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8006CCE8;
    }
    // 0x8006CC7C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006CC80: bne         $a0, $a3, L_8006CC6C
    if (ctx->r4 != ctx->r7) {
        // 0x8006CC84: nop
    
            goto L_8006CC6C;
    }
    // 0x8006CC84: nop

L_8006CC88:
    // 0x8006CC88: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8006CC8C: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x8006CC90: beq         $a3, $zero, L_8006CCBC
    if (ctx->r7 == 0) {
        // 0x8006CC94: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_8006CCBC;
    }
    // 0x8006CC94: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x8006CC98: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_8006CC9C:
    // 0x8006CC9C: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    // 0x8006CCA0: lwr         $v0, 0x3($a0)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r4, 0X3);
    // 0x8006CCA4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8006CCA8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8006CCAC: bne         $v0, $v1, L_8006CCE8
    if (ctx->r2 != ctx->r3) {
        // 0x8006CCB0: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8006CCE8;
    }
    // 0x8006CCB0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8006CCB4: bne         $a0, $a3, L_8006CC9C
    if (ctx->r4 != ctx->r7) {
        // 0x8006CCB8: nop
    
            goto L_8006CC9C;
    }
    // 0x8006CCB8: nop

L_8006CCBC:
    // 0x8006CCBC: blez        $a2, L_8006CCE0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8006CCC0: addu        $a3, $a2, $a0
        ctx->r7 = ADD32(ctx->r6, ctx->r4);
            goto L_8006CCE0;
    }
    // 0x8006CCC0: addu        $a3, $a2, $a0
    ctx->r7 = ADD32(ctx->r6, ctx->r4);
L_8006CCC4:
    // 0x8006CCC4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8006CCC8: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8006CCCC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006CCD0: bne         $v0, $v1, L_8006CCE8
    if (ctx->r2 != ctx->r3) {
        // 0x8006CCD4: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8006CCE8;
    }
    // 0x8006CCD4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006CCD8: bne         $a0, $a3, L_8006CCC4
    if (ctx->r4 != ctx->r7) {
        // 0x8006CCDC: nop
    
            goto L_8006CCC4;
    }
    // 0x8006CCDC: nop

L_8006CCE0:
    // 0x8006CCE0: jr          $ra
    // 0x8006CCE4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8006CCE4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006CCE8:
    // 0x8006CCE8: jr          $ra
    // 0x8006CCEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8006CCEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void ldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CCF0: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x8006CCF4: bne         $a2, $zero, L_8006CD00
    if (ctx->r6 != 0) {
        // 0x8006CCF8: nop
    
            goto L_8006CD00;
    }
    // 0x8006CCF8: nop

    // 0x8006CCFC: break       7
    do_break(2147929340);
L_8006CD00:
    // 0x8006CD00: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006CD04: bne         $a2, $at, L_8006CD18
    if (ctx->r6 != ctx->r1) {
        // 0x8006CD08: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8006CD18;
    }
    // 0x8006CD08: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006CD0C: bne         $a1, $at, L_8006CD18
    if (ctx->r5 != ctx->r1) {
        // 0x8006CD10: nop
    
            goto L_8006CD18;
    }
    // 0x8006CD10: nop

    // 0x8006CD14: break       6
    do_break(2147929364);
L_8006CD18:
    // 0x8006CD18: mflo        $v1
    ctx->r3 = lo;
    // 0x8006CD1C: nop

    // 0x8006CD20: nop

    // 0x8006CD24: mult        $a2, $v1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006CD28: mflo        $v0
    ctx->r2 = lo;
    // 0x8006CD2C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006CD30: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x8006CD34: sw          $v1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r3;
    // 0x8006CD38: subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // 0x8006CD3C: bgez        $v1, L_8006CD58
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8006CD40: sw          $a1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r5;
            goto L_8006CD58;
    }
    // 0x8006CD40: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8006CD44: blez        $a1, L_8006CD58
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8006CD48: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8006CD58;
    }
    // 0x8006CD48: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8006CD4C: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x8006CD50: subu        $v0, $a1, $a2
    ctx->r2 = SUB32(ctx->r5, ctx->r6);
    // 0x8006CD54: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
L_8006CD58:
    // 0x8006CD58: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x8006CD5C: lw          $v1, 0x4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4);
    // 0x8006CD60: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8006CD64: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8006CD68: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // 0x8006CD6C: jr          $ra
    // 0x8006CD70: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8006CD70: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void lldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CD74: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006CD78: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8006CD7C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8006CD80: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8006CD84: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8006CD88: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8006CD8C: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x8006CD90: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8006CD94: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006CD98: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x8006CD9C: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x8006CDA0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006CDA4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8006CDA8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006CDAC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8006CDB0: jal         0x8006D2D0
    // 0x8006CDB4: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    __divdi3_recomp(rdram, ctx);
        goto after_0;
    // 0x8006CDB4: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_0:
    // 0x8006CDB8: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8006CDBC: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // 0x8006CDC0: multu       $s3, $a3
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006CDC4: mfhi        $v0
    ctx->r2 = hi;
    // 0x8006CDC8: mflo        $v1
    ctx->r3 = lo;
    // 0x8006CDCC: nop

    // 0x8006CDD0: nop

    // 0x8006CDD4: mult        $s3, $a2
    result = S64(S32(ctx->r19)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006CDD8: mflo        $a0
    ctx->r4 = lo;
    // 0x8006CDDC: nop

    // 0x8006CDE0: nop

    // 0x8006CDE4: mult        $a3, $s2
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006CDE8: mflo        $a1
    ctx->r5 = lo;
    // 0x8006CDEC: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x8006CDF0: sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // 0x8006CDF4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006CDF8: lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10);
    // 0x8006CDFC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8006CE00: sltu        $a1, $s1, $v1
    ctx->r5 = ctx->r17 < ctx->r3 ? 1 : 0;
    // 0x8006CE04: subu        $t1, $s1, $v1
    ctx->r9 = SUB32(ctx->r17, ctx->r3);
    // 0x8006CE08: subu        $t0, $s0, $v0
    ctx->r8 = SUB32(ctx->r16, ctx->r2);
    // 0x8006CE0C: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x8006CE10: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8006CE14: bgez        $a0, L_8006CE64
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006CE18: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_8006CE64;
    }
    // 0x8006CE18: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8006CE1C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8006CE20: bgtzl       $v0, L_8006CE3C
    if (SIGNED(ctx->r2) > 0) {
        // 0x8006CE24: addiu       $v1, $a3, 0x1
        ctx->r3 = ADD32(ctx->r7, 0X1);
            goto L_8006CE3C;
    }
    goto skip_0;
    // 0x8006CE24: addiu       $v1, $a3, 0x1
    ctx->r3 = ADD32(ctx->r7, 0X1);
    skip_0:
    // 0x8006CE28: bne         $v0, $zero, L_8006CE64
    if (ctx->r2 != 0) {
        // 0x8006CE2C: nop
    
            goto L_8006CE64;
    }
    // 0x8006CE2C: nop

    // 0x8006CE30: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8006CE34: beq         $v0, $zero, L_8006CE64
    if (ctx->r2 == 0) {
        // 0x8006CE38: addiu       $v1, $a3, 0x1
        ctx->r3 = ADD32(ctx->r7, 0X1);
            goto L_8006CE64;
    }
    // 0x8006CE38: addiu       $v1, $a3, 0x1
    ctx->r3 = ADD32(ctx->r7, 0X1);
L_8006CE3C:
    // 0x8006CE3C: sltiu       $a0, $v1, 0x1
    ctx->r4 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8006CE40: addu        $v0, $a2, $a0
    ctx->r2 = ADD32(ctx->r6, ctx->r4);
    // 0x8006CE44: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8006CE48: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x8006CE4C: sltu        $a0, $t1, $s3
    ctx->r4 = ctx->r9 < ctx->r19 ? 1 : 0;
    // 0x8006CE50: subu        $v1, $t1, $s3
    ctx->r3 = SUB32(ctx->r9, ctx->r19);
    // 0x8006CE54: subu        $v0, $t0, $s2
    ctx->r2 = SUB32(ctx->r8, ctx->r18);
    // 0x8006CE58: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8006CE5C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8006CE60: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_8006CE64:
    // 0x8006CE64: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x8006CE68: lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X14);
    // 0x8006CE6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006CE70: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8006CE74: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x8006CE78: sw          $v1, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r3;
    // 0x8006CE7C: sw          $a0, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r4;
    // 0x8006CE80: sw          $a1, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r5;
    // 0x8006CE84: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // 0x8006CE88: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8006CE8C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8006CE90: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8006CE94: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8006CE98: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8006CE9C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006CEA0: jr          $ra
    // 0x8006CEA4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006CEA4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8006CEB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CEB0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8006CEB4: lw          $v0, -0x34D0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34D0);
    // 0x8006CEB8: lui         $v1, 0x41C6
    ctx->r3 = S32(0X41C6 << 16);
    // 0x8006CEBC: ori         $v1, $v1, 0x4E6D
    ctx->r3 = ctx->r3 | 0X4E6D;
    // 0x8006CEC0: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006CEC4: mflo        $v0
    ctx->r2 = lo;
    // 0x8006CEC8: addiu       $v1, $v0, 0x3039
    ctx->r3 = ADD32(ctx->r2, 0X3039);
    // 0x8006CECC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CED0: sw          $v1, -0x34D0($at)
    MEM_W(-0X34D0, ctx->r1) = ctx->r3;
    // 0x8006CED4: addiu       $v0, $v0, 0x303A
    ctx->r2 = ADD32(ctx->r2, 0X303A);
    // 0x8006CED8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006CEDC: jr          $ra
    // 0x8006CEE0: andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
    return;
    // 0x8006CEE0: andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
;}
RECOMP_FUNC void func_8006CEE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CEE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CEE8: jr          $ra
    // 0x8006CEEC: sw          $a0, -0x34D0($at)
    MEM_W(-0X34D0, ctx->r1) = ctx->r4;
    return;
    // 0x8006CEEC: sw          $a0, -0x34D0($at)
    MEM_W(-0X34D0, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_8006CEF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CEF0: subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
    // 0x8006CEF4: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8006CEF8: beq         $v0, $zero, L_8006CF54
    if (ctx->r2 == 0) {
        // 0x8006CEFC: andi        $v0, $a0, 0x3
        ctx->r2 = ctx->r4 & 0X3;
            goto L_8006CF54;
    }
    // 0x8006CEFC: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
L_8006CF00:
    // 0x8006CF00: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8006CF04: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006CF08: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8006CF0C: subu        $a2, $v1, $v0
    ctx->r6 = SUB32(ctx->r3, ctx->r2);
    // 0x8006CF10: sltu        $v0, $zero, $a2
    ctx->r2 = 0 < ctx->r6 ? 1 : 0;
    // 0x8006CF14: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8006CF18: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8006CF1C: beq         $v0, $zero, L_8006CF00
    if (ctx->r2 == 0) {
        // 0x8006CF20: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8006CF00;
    }
    // 0x8006CF20: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006CF24: j           L_8006CFEC
    // 0x8006CF28: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
        goto L_8006CFEC;
    // 0x8006CF28: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
L_8006CF2C:
    // 0x8006CF2C: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8006CF30: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006CF34: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8006CF38: subu        $a2, $v1, $v0
    ctx->r6 = SUB32(ctx->r3, ctx->r2);
    // 0x8006CF3C: sltu        $v0, $zero, $a2
    ctx->r2 = 0 < ctx->r6 ? 1 : 0;
    // 0x8006CF40: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8006CF44: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8006CF48: bne         $v0, $zero, L_8006CFE8
    if (ctx->r2 != 0) {
        // 0x8006CF4C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8006CFE8;
    }
    // 0x8006CF4C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006CF50: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
L_8006CF54:
    // 0x8006CF54: bne         $v0, $zero, L_8006CF2C
    if (ctx->r2 != 0) {
        // 0x8006CF58: nop
    
            goto L_8006CF2C;
    }
    // 0x8006CF58: nop

L_8006CF5C:
    // 0x8006CF5C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006CF60: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8006CF64: lw          $a3, 0x0($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X0);
    // 0x8006CF68: subu        $a2, $v1, $a3
    ctx->r6 = SUB32(ctx->r3, ctx->r7);
    // 0x8006CF6C: beq         $a2, $zero, L_8006CFBC
    if (ctx->r6 == 0) {
        // 0x8006CF70: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8006CFBC;
    }
    // 0x8006CF70: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8006CF74: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x8006CF78: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8006CF7C: bnel        $v0, $zero, L_8006CF8C
    if (ctx->r2 != 0) {
        // 0x8006CF80: lui         $v0, 0xFF
        ctx->r2 = S32(0XFF << 16);
            goto L_8006CF8C;
    }
    goto skip_0;
    // 0x8006CF80: lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
    skip_0:
    // 0x8006CF84: j           L_8006CFAC
    // 0x8006CF88: lui         $a2, 0xFF00
    ctx->r6 = S32(0XFF00 << 16);
        goto L_8006CFAC;
    // 0x8006CF88: lui         $a2, 0xFF00
    ctx->r6 = S32(0XFF00 << 16);
L_8006CF8C:
    // 0x8006CF8C: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8006CF90: bnel        $v0, $zero, L_8006CFA0
    if (ctx->r2 != 0) {
        // 0x8006CF94: andi        $v0, $v1, 0xFF00
        ctx->r2 = ctx->r3 & 0XFF00;
            goto L_8006CFA0;
    }
    goto skip_1;
    // 0x8006CF94: andi        $v0, $v1, 0xFF00
    ctx->r2 = ctx->r3 & 0XFF00;
    skip_1:
    // 0x8006CF98: j           L_8006CFAC
    // 0x8006CF9C: lui         $a2, 0xFFFF
    ctx->r6 = S32(0XFFFF << 16);
        goto L_8006CFAC;
    // 0x8006CF9C: lui         $a2, 0xFFFF
    ctx->r6 = S32(0XFFFF << 16);
L_8006CFA0:
    // 0x8006CFA0: bnel        $v0, $zero, L_8006CFEC
    if (ctx->r2 != 0) {
        // 0x8006CFA4: addu        $v0, $a2, $zero
        ctx->r2 = ADD32(ctx->r6, 0);
            goto L_8006CFEC;
    }
    goto skip_2;
    // 0x8006CFA4: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    skip_2:
    // 0x8006CFA8: addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
L_8006CFAC:
    // 0x8006CFAC: and         $v1, $v1, $a2
    ctx->r3 = ctx->r3 & ctx->r6;
    // 0x8006CFB0: and         $v0, $a3, $a2
    ctx->r2 = ctx->r7 & ctx->r6;
    // 0x8006CFB4: j           L_8006CFEC
    // 0x8006CFB8: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
        goto L_8006CFEC;
    // 0x8006CFB8: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
L_8006CFBC:
    // 0x8006CFBC: sll         $v0, $v1, 24
    ctx->r2 = S32(ctx->r3 << 24);
    // 0x8006CFC0: beq         $v0, $zero, L_8006CFE8
    if (ctx->r2 == 0) {
        // 0x8006CFC4: andi        $v0, $v1, 0xFF00
        ctx->r2 = ctx->r3 & 0XFF00;
            goto L_8006CFE8;
    }
    // 0x8006CFC4: andi        $v0, $v1, 0xFF00
    ctx->r2 = ctx->r3 & 0XFF00;
    // 0x8006CFC8: beq         $v0, $zero, L_8006CFE8
    if (ctx->r2 == 0) {
        // 0x8006CFCC: lui         $v0, 0xFF
        ctx->r2 = S32(0XFF << 16);
            goto L_8006CFE8;
    }
    // 0x8006CFCC: lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
    // 0x8006CFD0: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8006CFD4: beq         $v0, $zero, L_8006CFE8
    if (ctx->r2 == 0) {
        // 0x8006CFD8: lui         $v0, 0xFF00
        ctx->r2 = S32(0XFF00 << 16);
            goto L_8006CFE8;
    }
    // 0x8006CFD8: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x8006CFDC: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8006CFE0: bne         $v0, $zero, L_8006CF5C
    if (ctx->r2 != 0) {
        // 0x8006CFE4: nop
    
            goto L_8006CF5C;
    }
    // 0x8006CFE4: nop

L_8006CFE8:
    // 0x8006CFE8: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
L_8006CFEC:
    // 0x8006CFEC: jr          $ra
    // 0x8006CFF0: nop

    return;
    // 0x8006CFF0: nop

;}
RECOMP_FUNC void func_8006D000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D000: subu        $v0, $a1, $a0
    ctx->r2 = SUB32(ctx->r5, ctx->r4);
    // 0x8006D004: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8006D008: beq         $v0, $zero, L_8006D054
    if (ctx->r2 == 0) {
        // 0x8006D00C: addu        $a2, $a0, $zero
        ctx->r6 = ADD32(ctx->r4, 0);
            goto L_8006D054;
    }
    // 0x8006D00C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8006D010: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8006D014: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x8006D018: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006D01C: beq         $v0, $zero, L_8006D0C0
    if (ctx->r2 == 0) {
        // 0x8006D020: addiu       $a2, $a0, 0x1
        ctx->r6 = ADD32(ctx->r4, 0X1);
            goto L_8006D0C0;
    }
    // 0x8006D020: addiu       $a2, $a0, 0x1
    ctx->r6 = ADD32(ctx->r4, 0X1);
L_8006D024:
    // 0x8006D024: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8006D028: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8006D02C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006D030: bne         $v0, $zero, L_8006D024
    if (ctx->r2 != 0) {
        // 0x8006D034: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8006D024;
    }
    // 0x8006D034: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8006D038: j           L_8006D0C0
    // 0x8006D03C: nop

        goto L_8006D0C0;
    // 0x8006D03C: nop

L_8006D040:
    // 0x8006D040: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8006D044: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8006D048: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006D04C: beq         $v0, $zero, L_8006D0C0
    if (ctx->r2 == 0) {
        // 0x8006D050: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8006D0C0;
    }
    // 0x8006D050: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8006D054:
    // 0x8006D054: andi        $v0, $a2, 0x3
    ctx->r2 = ctx->r6 & 0X3;
    // 0x8006D058: bne         $v0, $zero, L_8006D040
    if (ctx->r2 != 0) {
        // 0x8006D05C: nop
    
            goto L_8006D040;
    }
    // 0x8006D05C: nop

L_8006D060:
    // 0x8006D060: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8006D064: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x8006D068: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8006D06C: bne         $v0, $zero, L_8006D07C
    if (ctx->r2 != 0) {
        // 0x8006D070: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8006D07C;
    }
    // 0x8006D070: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8006D074: j           L_8006D0C0
    // 0x8006D078: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
        goto L_8006D0C0;
    // 0x8006D078: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
L_8006D07C:
    // 0x8006D07C: lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
    // 0x8006D080: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8006D084: bne         $v0, $zero, L_8006D098
    if (ctx->r2 != 0) {
        // 0x8006D088: andi        $v0, $v1, 0xFF00
        ctx->r2 = ctx->r3 & 0XFF00;
            goto L_8006D098;
    }
    // 0x8006D088: andi        $v0, $v1, 0xFF00
    ctx->r2 = ctx->r3 & 0XFF00;
    // 0x8006D08C: srl         $v0, $v1, 16
    ctx->r2 = S32(U32(ctx->r3) >> 16);
    // 0x8006D090: j           L_8006D0C0
    // 0x8006D094: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
        goto L_8006D0C0;
    // 0x8006D094: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
L_8006D098:
    // 0x8006D098: beq         $v0, $zero, L_8006D0B8
    if (ctx->r2 == 0) {
        // 0x8006D09C: srl         $v0, $v1, 16
        ctx->r2 = S32(U32(ctx->r3) >> 16);
            goto L_8006D0B8;
    }
    // 0x8006D09C: srl         $v0, $v1, 16
    ctx->r2 = S32(U32(ctx->r3) >> 16);
    // 0x8006D0A0: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x8006D0A4: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8006D0A8: bne         $v0, $zero, L_8006D060
    if (ctx->r2 != 0) {
        // 0x8006D0AC: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8006D060;
    }
    // 0x8006D0AC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8006D0B0: j           L_8006D0C0
    // 0x8006D0B4: nop

        goto L_8006D0C0;
    // 0x8006D0B4: nop

L_8006D0B8:
    // 0x8006D0B8: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x8006D0BC: sb          $zero, 0x2($a2)
    MEM_B(0X2, ctx->r6) = 0;
L_8006D0C0:
    // 0x8006D0C0: jr          $ra
    // 0x8006D0C4: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    return;
    // 0x8006D0C4: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
;}
RECOMP_FUNC void func_8006D0D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D0D4: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006D0D8: mflo        $t0
    ctx->r8 = lo;
    // 0x8006D0DC: nop

    // 0x8006D0E0: nop

    // 0x8006D0E4: multu       $a0, $a3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006D0E8: mflo        $v1
    ctx->r3 = lo;
    // 0x8006D0EC: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x8006D0F0: nop

    // 0x8006D0F4: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006D0F8: mflo        $v1
    ctx->r3 = lo;
    // 0x8006D0FC: mfhi        $v0
    ctx->r2 = hi;
    // 0x8006D100: jr          $ra
    // 0x8006D104: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    return;
    // 0x8006D104: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
;}
RECOMP_FUNC void func_8006D108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D108: xor         $v1, $v1, $v1
    ctx->r3 = ctx->r3 ^ ctx->r3;
    // 0x8006D10C: sltu        $t9, $a2, $a0
    ctx->r25 = ctx->r6 < ctx->r4 ? 1 : 0;
    // 0x8006D110: bne         $t9, $zero, L_8006D150
    if (ctx->r25 != 0) {
        // 0x8006D114: nop
    
            goto L_8006D150;
    }
    // 0x8006D114: nop

    // 0x8006D118: bne         $a0, $a2, L_8006D148
    if (ctx->r4 != ctx->r6) {
        // 0x8006D11C: nop
    
            goto L_8006D148;
    }
    // 0x8006D11C: nop

    // 0x8006D120: sltu        $t9, $a3, $a1
    ctx->r25 = ctx->r7 < ctx->r5 ? 1 : 0;
    // 0x8006D124: bne         $t9, $zero, L_8006D150
    if (ctx->r25 != 0) {
        // 0x8006D128: nop
    
            goto L_8006D150;
    }
    // 0x8006D128: nop

    // 0x8006D12C: bne         $a1, $a3, L_8006D148
    if (ctx->r5 != ctx->r7) {
        // 0x8006D130: nop
    
            goto L_8006D148;
    }
    // 0x8006D130: nop

    // 0x8006D134: xor         $a1, $a1, $a1
    ctx->r5 = ctx->r5 ^ ctx->r5;
    // 0x8006D138: xor         $a0, $a0, $a0
    ctx->r4 = ctx->r4 ^ ctx->r4;
    // 0x8006D13C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8006D140: jr          $ra
    // 0x8006D144: xor         $v0, $v0, $v0
    ctx->r2 = ctx->r2 ^ ctx->r2;
    return;
    // 0x8006D144: xor         $v0, $v0, $v0
    ctx->r2 = ctx->r2 ^ ctx->r2;
L_8006D148:
    // 0x8006D148: jr          $ra
    // 0x8006D14C: xor         $v0, $v0, $v0
    ctx->r2 = ctx->r2 ^ ctx->r2;
    return;
    // 0x8006D14C: xor         $v0, $v0, $v0
    ctx->r2 = ctx->r2 ^ ctx->r2;
L_8006D150:
    // 0x8006D150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006D154: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
L_8006D158:
    // 0x8006D158: and         $t9, $a2, $t0
    ctx->r25 = ctx->r6 & ctx->r8;
    // 0x8006D15C: bne         $t9, $zero, L_8006D1AC
    if (ctx->r25 != 0) {
        // 0x8006D160: nop
    
            goto L_8006D1AC;
    }
    // 0x8006D160: nop

    // 0x8006D164: srl         $t9, $a3, 31
    ctx->r25 = S32(U32(ctx->r7) >> 31);
    // 0x8006D168: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x8006D16C: or          $a2, $a2, $t9
    ctx->r6 = ctx->r6 | ctx->r25;
    // 0x8006D170: sll         $a3, $a3, 1
    ctx->r7 = S32(ctx->r7 << 1);
    // 0x8006D174: sltu        $t9, $a2, $a0
    ctx->r25 = ctx->r6 < ctx->r4 ? 1 : 0;
    // 0x8006D178: bne         $t9, $zero, L_8006D194
    if (ctx->r25 != 0) {
        // 0x8006D17C: nop
    
            goto L_8006D194;
    }
    // 0x8006D17C: nop

    // 0x8006D180: bne         $a0, $a2, L_8006D19C
    if (ctx->r4 != ctx->r6) {
        // 0x8006D184: nop
    
            goto L_8006D19C;
    }
    // 0x8006D184: nop

    // 0x8006D188: sltu        $t9, $a3, $a1
    ctx->r25 = ctx->r7 < ctx->r5 ? 1 : 0;
    // 0x8006D18C: beq         $t9, $zero, L_8006D19C
    if (ctx->r25 == 0) {
        // 0x8006D190: nop
    
            goto L_8006D19C;
    }
    // 0x8006D190: nop

L_8006D194:
    // 0x8006D194: j           L_8006D158
    // 0x8006D198: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
        goto L_8006D158;
    // 0x8006D198: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_8006D19C:
    // 0x8006D19C: sll         $t9, $a2, 31
    ctx->r25 = S32(ctx->r6 << 31);
    // 0x8006D1A0: srl         $a3, $a3, 1
    ctx->r7 = S32(U32(ctx->r7) >> 1);
    // 0x8006D1A4: or          $a3, $a3, $t9
    ctx->r7 = ctx->r7 | ctx->r25;
    // 0x8006D1A8: srl         $a2, $a2, 1
    ctx->r6 = S32(U32(ctx->r6) >> 1);
L_8006D1AC:
    // 0x8006D1AC: sltu        $t9, $a2, $a0
    ctx->r25 = ctx->r6 < ctx->r4 ? 1 : 0;
    // 0x8006D1B0: bne         $t9, $zero, L_8006D1CC
    if (ctx->r25 != 0) {
        // 0x8006D1B4: nop
    
            goto L_8006D1CC;
    }
    // 0x8006D1B4: nop

    // 0x8006D1B8: bne         $a0, $a2, L_8006D1E0
    if (ctx->r4 != ctx->r6) {
        // 0x8006D1BC: nop
    
            goto L_8006D1E0;
    }
    // 0x8006D1BC: nop

    // 0x8006D1C0: sltu        $t9, $a1, $a3
    ctx->r25 = ctx->r5 < ctx->r7 ? 1 : 0;
    // 0x8006D1C4: bne         $t9, $zero, L_8006D1E0
    if (ctx->r25 != 0) {
        // 0x8006D1C8: nop
    
            goto L_8006D1E0;
    }
    // 0x8006D1C8: nop

L_8006D1CC:
    // 0x8006D1CC: sltu        $t9, $a1, $a3
    ctx->r25 = ctx->r5 < ctx->r7 ? 1 : 0;
    // 0x8006D1D0: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x8006D1D4: subu        $a0, $a0, $a2
    ctx->r4 = SUB32(ctx->r4, ctx->r6);
    // 0x8006D1D8: subu        $a0, $a0, $t9
    ctx->r4 = SUB32(ctx->r4, ctx->r25);
    // 0x8006D1DC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_8006D1E0:
    // 0x8006D1E0: sll         $t9, $a2, 31
    ctx->r25 = S32(ctx->r6 << 31);
    // 0x8006D1E4: srl         $a3, $a3, 1
    ctx->r7 = S32(U32(ctx->r7) >> 1);
    // 0x8006D1E8: or          $a3, $a3, $t9
    ctx->r7 = ctx->r7 | ctx->r25;
    // 0x8006D1EC: srl         $a2, $a2, 1
    ctx->r6 = S32(U32(ctx->r6) >> 1);
    // 0x8006D1F0: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x8006D1F4: bne         $v0, $zero, L_8006D1AC
    if (ctx->r2 != 0) {
        // 0x8006D1F8: nop
    
            goto L_8006D1AC;
    }
    // 0x8006D1F8: nop

    // 0x8006D1FC: jr          $ra
    // 0x8006D200: xor         $v0, $v0, $v0
    ctx->r2 = ctx->r2 ^ ctx->r2;
    return;
    // 0x8006D200: xor         $v0, $v0, $v0
    ctx->r2 = ctx->r2 ^ ctx->r2;
;}
RECOMP_FUNC void func_8006D204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D204: divu        $zero, $a0, $a3
    lo = S32(U32(ctx->r4) / U32(ctx->r7)); hi = S32(U32(ctx->r4) % U32(ctx->r7));
    // 0x8006D208: bne         $a3, $zero, L_8006D214
    if (ctx->r7 != 0) {
        // 0x8006D20C: nop
    
            goto L_8006D214;
    }
    // 0x8006D20C: nop

    // 0x8006D210: break       7
    do_break(2147930640);
L_8006D214:
    // 0x8006D214: mflo        $t2
    ctx->r10 = lo;
    // 0x8006D218: mfhi        $a0
    ctx->r4 = hi;
    // 0x8006D21C: xor         $t0, $t0, $t0
    ctx->r8 = ctx->r8 ^ ctx->r8;
L_8006D220:
    // 0x8006D220: beq         $a0, $zero, L_8006D29C
    if (ctx->r4 == 0) {
        // 0x8006D224: nop
    
            goto L_8006D29C;
    }
    // 0x8006D224: nop

    // 0x8006D228: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x8006D22C: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x8006D230: addu        $t1, $a3, $zero
    ctx->r9 = ADD32(ctx->r7, 0);
L_8006D234:
    // 0x8006D234: sll         $t9, $v0, 31
    ctx->r25 = S32(ctx->r2 << 31);
    // 0x8006D238: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x8006D23C: or          $v1, $v1, $t9
    ctx->r3 = ctx->r3 | ctx->r25;
    // 0x8006D240: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x8006D244: bne         $v0, $zero, L_8006D234
    if (ctx->r2 != 0) {
        // 0x8006D248: srl         $t1, $t1, 1
        ctx->r9 = S32(U32(ctx->r9) >> 1);
            goto L_8006D234;
    }
    // 0x8006D248: srl         $t1, $t1, 1
    ctx->r9 = S32(U32(ctx->r9) >> 1);
    // 0x8006D24C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8006D250: divu        $zero, $v1, $t1
    lo = S32(U32(ctx->r3) / U32(ctx->r9)); hi = S32(U32(ctx->r3) % U32(ctx->r9));
    // 0x8006D254: bne         $t1, $zero, L_8006D260
    if (ctx->r9 != 0) {
        // 0x8006D258: nop
    
            goto L_8006D260;
    }
    // 0x8006D258: nop

    // 0x8006D25C: break       7
    do_break(2147930716);
L_8006D260:
    // 0x8006D260: mflo        $v1
    ctx->r3 = lo;
    // 0x8006D264: xor         $v0, $v0, $v0
    ctx->r2 = ctx->r2 ^ ctx->r2;
    // 0x8006D268: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x8006D26C: sltu        $t9, $t0, $v1
    ctx->r25 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x8006D270: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x8006D274: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x8006D278: nop

    // 0x8006D27C: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006D280: mflo        $v1
    ctx->r3 = lo;
    // 0x8006D284: mfhi        $v0
    ctx->r2 = hi;
    // 0x8006D288: sltu        $t9, $a1, $v1
    ctx->r25 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x8006D28C: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x8006D290: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8006D294: j           L_8006D220
    // 0x8006D298: subu        $a0, $a0, $t9
    ctx->r4 = SUB32(ctx->r4, ctx->r25);
        goto L_8006D220;
    // 0x8006D298: subu        $a0, $a0, $t9
    ctx->r4 = SUB32(ctx->r4, ctx->r25);
L_8006D29C:
    // 0x8006D29C: divu        $zero, $a1, $a3
    lo = S32(U32(ctx->r5) / U32(ctx->r7)); hi = S32(U32(ctx->r5) % U32(ctx->r7));
    // 0x8006D2A0: bne         $a3, $zero, L_8006D2AC
    if (ctx->r7 != 0) {
        // 0x8006D2A4: nop
    
            goto L_8006D2AC;
    }
    // 0x8006D2A4: nop

    // 0x8006D2A8: break       7
    do_break(2147930792);
L_8006D2AC:
    // 0x8006D2AC: mflo        $v1
    ctx->r3 = lo;
    // 0x8006D2B0: mfhi        $t1
    ctx->r9 = hi;
    // 0x8006D2B4: xor         $v0, $v0, $v0
    ctx->r2 = ctx->r2 ^ ctx->r2;
    // 0x8006D2B8: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8006D2BC: sltu        $t9, $v1, $t0
    ctx->r25 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x8006D2C0: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x8006D2C4: jr          $ra
    // 0x8006D2C8: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    return;
    // 0x8006D2C8: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
;}
RECOMP_FUNC void __divdi3_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D2D0: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8006D2D4: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x8006D2D8: xor         $v1, $v1, $a2
    ctx->r3 = ctx->r3 ^ ctx->r6;
    // 0x8006D2DC: and         $t9, $t0, $a0
    ctx->r25 = ctx->r8 & ctx->r4;
    // 0x8006D2E0: beq         $t9, $zero, L_8006D300
    if (ctx->r25 == 0) {
        // 0x8006D2E4: nop
    
            goto L_8006D300;
    }
    // 0x8006D2E4: nop

    // 0x8006D2E8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8006D2EC: xor         $a1, $a1, $t1
    ctx->r5 = ctx->r5 ^ ctx->r9;
    // 0x8006D2F0: xor         $a0, $a0, $t1
    ctx->r4 = ctx->r4 ^ ctx->r9;
    // 0x8006D2F4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006D2F8: sltiu       $t9, $a1, 0x1
    ctx->r25 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x8006D2FC: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
L_8006D300:
    // 0x8006D300: and         $t9, $t0, $a2
    ctx->r25 = ctx->r8 & ctx->r6;
    // 0x8006D304: beq         $t9, $zero, L_8006D324
    if (ctx->r25 == 0) {
        // 0x8006D308: nop
    
            goto L_8006D324;
    }
    // 0x8006D308: nop

    // 0x8006D30C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8006D310: xor         $a3, $a3, $t1
    ctx->r7 = ctx->r7 ^ ctx->r9;
    // 0x8006D314: xor         $a2, $a2, $t1
    ctx->r6 = ctx->r6 ^ ctx->r9;
    // 0x8006D318: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8006D31C: sltiu       $t9, $a3, 0x1
    ctx->r25 = ctx->r7 < 0X1 ? 1 : 0;
    // 0x8006D320: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_8006D324:
    // 0x8006D324: and         $v1, $v1, $t0
    ctx->r3 = ctx->r3 & ctx->r8;
    // 0x8006D328: beq         $v1, $zero, L_8006D440
    if (ctx->r3 == 0) {
            // 0x8006D32C: nop

    __udivdi3_recomp(rdram, ctx);
    return;
    }
    // 0x8006D32C: nop

    // 0x8006D330: bne         $a2, $zero, L_8006D34C
    if (ctx->r6 != 0) {
        // 0x8006D334: nop
    
            goto L_8006D34C;
    }
    // 0x8006D334: nop

    // 0x8006D338: addu        $t5, $ra, $zero
    ctx->r13 = ADD32(ctx->r31, 0);
    // 0x8006D33C: jal         0x8006D204
    // 0x8006D340: nop

    func_8006D204(rdram, ctx);
        goto after_0;
    // 0x8006D340: nop

    after_0:
    // 0x8006D344: j           L_8006D35C
    // 0x8006D348: addu        $ra, $t5, $zero
    ctx->r31 = ADD32(ctx->r13, 0);
        goto L_8006D35C;
    // 0x8006D348: addu        $ra, $t5, $zero
    ctx->r31 = ADD32(ctx->r13, 0);
L_8006D34C:
    // 0x8006D34C: addu        $t5, $ra, $zero
    ctx->r13 = ADD32(ctx->r31, 0);
    // 0x8006D350: jal         0x8006D108
    // 0x8006D354: nop

    func_8006D108(rdram, ctx);
        goto after_1;
    // 0x8006D354: nop

    after_1:
    // 0x8006D358: addu        $ra, $t5, $zero
    ctx->r31 = ADD32(ctx->r13, 0);
L_8006D35C:
    // 0x8006D35C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8006D360: xor         $v1, $v1, $a3
    ctx->r3 = ctx->r3 ^ ctx->r7;
    // 0x8006D364: xor         $v0, $v0, $a3
    ctx->r2 = ctx->r2 ^ ctx->r7;
    // 0x8006D368: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006D36C: sltiu       $t9, $v1, 0x1
    ctx->r25 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8006D370: jr          $ra
    // 0x8006D374: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    return;
    // 0x8006D374: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8006D378: nop

    // 0x8006D37C: nop

    // 0x8006D380: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8006D384: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x8006D388: and         $t9, $t0, $a0
    ctx->r25 = ctx->r8 & ctx->r4;
    // 0x8006D38C: beq         $t9, $zero, L_8006D3AC
    if (ctx->r25 == 0) {
        // 0x8006D390: nop
    
            goto L_8006D3AC;
    }
    // 0x8006D390: nop

    // 0x8006D394: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8006D398: xor         $a1, $a1, $t1
    ctx->r5 = ctx->r5 ^ ctx->r9;
    // 0x8006D39C: xor         $a0, $a0, $t1
    ctx->r4 = ctx->r4 ^ ctx->r9;
    // 0x8006D3A0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006D3A4: sltiu       $t9, $a1, 0x1
    ctx->r25 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x8006D3A8: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
L_8006D3AC:
    // 0x8006D3AC: and         $t9, $t0, $a2
    ctx->r25 = ctx->r8 & ctx->r6;
    // 0x8006D3B0: beq         $t9, $zero, L_8006D3D0
    if (ctx->r25 == 0) {
        // 0x8006D3B4: nop
    
            goto L_8006D3D0;
    }
    // 0x8006D3B4: nop

    // 0x8006D3B8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8006D3BC: xor         $a3, $a3, $t1
    ctx->r7 = ctx->r7 ^ ctx->r9;
    // 0x8006D3C0: xor         $a2, $a2, $t1
    ctx->r6 = ctx->r6 ^ ctx->r9;
    // 0x8006D3C4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8006D3C8: sltiu       $t9, $a3, 0x1
    ctx->r25 = ctx->r7 < 0X1 ? 1 : 0;
    // 0x8006D3CC: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_8006D3D0:
    // 0x8006D3D0: and         $v1, $v1, $t0
    ctx->r3 = ctx->r3 & ctx->r8;
    // 0x8006D3D4: beq         $v1, $zero, L_8006D460
    if (ctx->r3 == 0) {
            // 0x8006D3D8: nop

    __umoddi3_recomp(rdram, ctx);
    return;
    }
    // 0x8006D3D8: nop

    // 0x8006D3DC: bne         $a2, $zero, L_8006D400
    if (ctx->r6 != 0) {
        // 0x8006D3E0: nop
    
            goto L_8006D400;
    }
    // 0x8006D3E0: nop

    // 0x8006D3E4: addu        $t5, $ra, $zero
    ctx->r13 = ADD32(ctx->r31, 0);
    // 0x8006D3E8: jal         0x8006D204
    // 0x8006D3EC: nop

    func_8006D204(rdram, ctx);
        goto after_2;
    // 0x8006D3EC: nop

    after_2:
    // 0x8006D3F0: addu        $ra, $t5, $zero
    ctx->r31 = ADD32(ctx->r13, 0);
    // 0x8006D3F4: addu        $v1, $t1, $zero
    ctx->r3 = ADD32(ctx->r9, 0);
    // 0x8006D3F8: j           L_8006D418
    // 0x8006D3FC: xor         $v0, $v0, $v0
    ctx->r2 = ctx->r2 ^ ctx->r2;
        goto L_8006D418;
    // 0x8006D3FC: xor         $v0, $v0, $v0
    ctx->r2 = ctx->r2 ^ ctx->r2;
L_8006D400:
    // 0x8006D400: addu        $t5, $ra, $zero
    ctx->r13 = ADD32(ctx->r31, 0);
    // 0x8006D404: jal         0x8006D108
    // 0x8006D408: nop

    func_8006D108(rdram, ctx);
        goto after_3;
    // 0x8006D408: nop

    after_3:
    // 0x8006D40C: addu        $ra, $t5, $zero
    ctx->r31 = ADD32(ctx->r13, 0);
    // 0x8006D410: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x8006D414: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_8006D418:
    // 0x8006D418: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8006D41C: xor         $v1, $v1, $a3
    ctx->r3 = ctx->r3 ^ ctx->r7;
    // 0x8006D420: xor         $v0, $v0, $a3
    ctx->r2 = ctx->r2 ^ ctx->r7;
    // 0x8006D424: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006D428: sltiu       $t9, $v1, 0x1
    ctx->r25 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8006D42C: jr          $ra
    // 0x8006D430: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    return;
    // 0x8006D430: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
;}
RECOMP_FUNC void __udivdi3_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_8006D108:
    // 0x8006D440: bne         $a2, $zero, L_8006D450
    if (ctx->r6 != 0) {
        // 0x8006D444: nop
    
            goto L_8006D450;
    }
L_8006D204:
    // 0x8006D444: nop

    // 0x8006D448: j           L_8006D204
    // 0x8006D44C: nop

    func_8006D204(rdram, ctx);
    return;
    // 0x8006D44C: nop

L_8006D450:
    // 0x8006D450: j           L_8006D108
    // 0x8006D454: nop

    func_8006D108(rdram, ctx);
    return;
    // 0x8006D454: nop

;}
RECOMP_FUNC void __umoddi3_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D460: bne         $a2, $zero, L_8006D484
    if (ctx->r6 != 0) {
        // 0x8006D464: nop
    
            goto L_8006D484;
    }
    // 0x8006D464: nop

    // 0x8006D468: addu        $t5, $ra, $zero
    ctx->r13 = ADD32(ctx->r31, 0);
    // 0x8006D46C: jal         0x8006D204
    // 0x8006D470: nop

    func_8006D204(rdram, ctx);
        goto after_0;
    // 0x8006D470: nop

    after_0:
    // 0x8006D474: addu        $ra, $t5, $zero
    ctx->r31 = ADD32(ctx->r13, 0);
    // 0x8006D478: addu        $v1, $t1, $zero
    ctx->r3 = ADD32(ctx->r9, 0);
    // 0x8006D47C: jr          $ra
    // 0x8006D480: xor         $v0, $v0, $v0
    ctx->r2 = ctx->r2 ^ ctx->r2;
    return;
    // 0x8006D480: xor         $v0, $v0, $v0
    ctx->r2 = ctx->r2 ^ ctx->r2;
L_8006D484:
    // 0x8006D484: addu        $t5, $ra, $zero
    ctx->r13 = ADD32(ctx->r31, 0);
    // 0x8006D488: jal         0x8006D108
    // 0x8006D48C: nop

    func_8006D108(rdram, ctx);
        goto after_1;
    // 0x8006D48C: nop

    after_1:
    // 0x8006D490: addu        $ra, $t5, $zero
    ctx->r31 = ADD32(ctx->r13, 0);
    // 0x8006D494: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x8006D498: jr          $ra
    // 0x8006D49C: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    return;
    // 0x8006D49C: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
;}
RECOMP_FUNC void func_8006D4A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
