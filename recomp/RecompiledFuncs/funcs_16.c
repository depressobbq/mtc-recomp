#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80053FDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053FDC: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x80053FE0: lw          $a1, 0xC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XC);
    // 0x80053FE4: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x80053FE8: lw          $v1, 0x24($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X24);
    // 0x80053FEC: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80053FF0: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x80053FF4: nor         $v0, $zero, $a1
    ctx->r2 = ~(0 | ctx->r5);
    // 0x80053FF8: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80053FFC: and         $a1, $a1, $v0
    ctx->r5 = ctx->r5 & ctx->r2;
    // 0x80054000: slti        $v0, $v1, 0xF1
    ctx->r2 = SIGNED(ctx->r3) < 0XF1 ? 1 : 0;
    // 0x80054004: bne         $v0, $zero, L_80054010
    if (ctx->r2 != 0) {
        // 0x80054008: addu        $t1, $a2, $zero
        ctx->r9 = ADD32(ctx->r6, 0);
            goto L_80054010;
    }
    // 0x80054008: addu        $t1, $a2, $zero
    ctx->r9 = ADD32(ctx->r6, 0);
    // 0x8005400C: addiu       $v1, $zero, 0xF0
    ctx->r3 = ADD32(0, 0XF0);
L_80054010:
    // 0x80054010: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80054014: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x80054018: andi        $v0, $a3, 0x3
    ctx->r2 = ctx->r7 & 0X3;
    // 0x8005401C: bgez        $t0, L_8005403C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80054020: sll         $a3, $v0, 4
        ctx->r7 = S32(ctx->r2 << 4);
            goto L_8005403C;
    }
    // 0x80054020: sll         $a3, $v0, 4
    ctx->r7 = S32(ctx->r2 << 4);
    // 0x80054024: bgez        $t0, L_80054030
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80054028: addu        $v0, $t0, $zero
        ctx->r2 = ADD32(ctx->r8, 0);
            goto L_80054030;
    }
    // 0x80054028: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    // 0x8005402C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_80054030:
    // 0x80054030: subu        $a0, $t2, $v0
    ctx->r4 = SUB32(ctx->r10, ctx->r2);
    // 0x80054034: j           L_80054054
    // 0x80054038: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
        goto L_80054054;
    // 0x80054038: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
L_8005403C:
    // 0x8005403C: addiu       $v0, $t0, 0x10
    ctx->r2 = ADD32(ctx->r8, 0X10);
    // 0x80054040: slti        $v0, $v0, 0x140
    ctx->r2 = SIGNED(ctx->r2) < 0X140 ? 1 : 0;
    // 0x80054044: bne         $v0, $zero, L_80054058
    if (ctx->r2 != 0) {
        // 0x80054048: slt         $v0, $t1, $a1
        ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80054058;
    }
    // 0x80054048: slt         $v0, $t1, $a1
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005404C: addiu       $v0, $zero, 0x140
    ctx->r2 = ADD32(0, 0X140);
    // 0x80054050: subu        $a0, $v0, $t0
    ctx->r4 = SUB32(ctx->r2, ctx->r8);
L_80054054:
    // 0x80054054: slt         $v0, $t1, $a1
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r5) ? 1 : 0;
L_80054058:
    // 0x80054058: beq         $v0, $zero, L_80054070
    if (ctx->r2 == 0) {
        // 0x8005405C: addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
            goto L_80054070;
    }
    // 0x8005405C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80054060: subu        $v1, $a1, $t1
    ctx->r3 = SUB32(ctx->r5, ctx->r9);
    // 0x80054064: subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
    // 0x80054068: j           L_80054080
    // 0x8005406C: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
        goto L_80054080;
    // 0x8005406C: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
L_80054070:
    // 0x80054070: addiu       $v0, $t1, 0x10
    ctx->r2 = ADD32(ctx->r9, 0X10);
    // 0x80054074: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80054078: beql        $v0, $zero, L_80054080
    if (ctx->r2 == 0) {
        // 0x8005407C: subu        $t2, $v1, $t1
        ctx->r10 = SUB32(ctx->r3, ctx->r9);
            goto L_80054080;
    }
    goto skip_0;
    // 0x8005407C: subu        $t2, $v1, $t1
    ctx->r10 = SUB32(ctx->r3, ctx->r9);
    skip_0:
L_80054080:
    // 0x80054080: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80054084: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x80054088: lui         $a2, 0x400
    ctx->r6 = S32(0X400 << 16);
    // 0x8005408C: ori         $a2, $a2, 0x400
    ctx->r6 = ctx->r6 | 0X400;
    // 0x80054090: addu        $v1, $t0, $a0
    ctx->r3 = ADD32(ctx->r8, ctx->r4);
    // 0x80054094: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80054098: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8005409C: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x800540A0: lui         $a0, 0xE400
    ctx->r4 = S32(0XE400 << 16);
    // 0x800540A4: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x800540A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800540AC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800540B0: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x800540B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800540B8: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x800540BC: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x800540C0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800540C4: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x800540C8: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x800540CC: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x800540D0: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x800540D4: sll         $v1, $t1, 2
    ctx->r3 = S32(ctx->r9 << 2);
    // 0x800540D8: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x800540DC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800540E0: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800540E4: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x800540E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800540EC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800540F0: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x800540F4: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x800540F8: addiu       $v0, $a3, 0x10
    ctx->r2 = ADD32(ctx->r7, 0X10);
    // 0x800540FC: subu        $v0, $v0, $t2
    ctx->r2 = SUB32(ctx->r2, ctx->r10);
    // 0x80054100: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80054104: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80054108: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x8005410C: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x80054110: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054114: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80054118: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x8005411C: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80054120: jr          $ra
    // 0x80054124: sw          $a2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r6;
    return;
    // 0x80054124: sw          $a2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r6;
;}
RECOMP_FUNC void func_80054128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005412C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80054130: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80054134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80054138: lh          $v0, 0x64($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X64);
    // 0x8005413C: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80054140: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80054144: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80054148: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005414C: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x80054150: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x80054154: lw          $a2, 0x568C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X568C);
    // 0x80054158: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8005415C: addiu       $a1, $a1, 0xC8
    ctx->r5 = ADD32(ctx->r5, 0XC8);
    // 0x80054160: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    // 0x80054164: jal         0x8004EBF4
    // 0x80054168: addu        $a2, $v0, $a2
    ctx->r6 = ADD32(ctx->r2, ctx->r6);
    func_8004EBF4(rdram, ctx);
        goto after_0;
    // 0x80054168: addu        $a2, $v0, $a2
    ctx->r6 = ADD32(ctx->r2, ctx->r6);
    after_0:
    // 0x8005416C: lhu         $v0, 0x64($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X64);
    // 0x80054170: addiu       $v1, $zero, 0x16
    ctx->r3 = ADD32(0, 0X16);
    // 0x80054174: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80054178: sh          $v0, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r2;
    // 0x8005417C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80054180: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80054184: beql        $v0, $v1, L_8005418C
    if (ctx->r2 == ctx->r3) {
        // 0x80054188: sh          $zero, 0x64($s0)
        MEM_H(0X64, ctx->r16) = 0;
            goto L_8005418C;
    }
    goto skip_0;
    // 0x80054188: sh          $zero, 0x64($s0)
    MEM_H(0X64, ctx->r16) = 0;
    skip_0:
L_8005418C:
    // 0x8005418C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80054190: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80054194: jr          $ra
    // 0x80054198: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80054198: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800541A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800541A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800541A4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800541A8: addiu       $a0, $a0, 0x5582
    ctx->r4 = ADD32(ctx->r4, 0X5582);
    // 0x800541AC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800541B0: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800541B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800541B8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800541BC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800541C0: lw          $v0, 0x5A60($at)
    ctx->r2 = MEM_W(ctx->r1, 0X5A60);
    // 0x800541C4: jalr        $v0
    // 0x800541C8: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800541C8: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    after_0:
    // 0x800541CC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800541D0: jr          $ra
    // 0x800541D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800541D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800541D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800541D8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800541DC: lbu         $v0, 0x5587($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5587);
    // 0x800541E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800541E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800541E8: sb          $v1, 0x5581($at)
    MEM_B(0X5581, ctx->r1) = ctx->r3;
    // 0x800541EC: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x800541F0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800541F4: sb          $zero, 0x5582($at)
    MEM_B(0X5582, ctx->r1) = 0;
    // 0x800541F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800541FC: sb          $v1, 0x7BA0($at)
    MEM_B(0X7BA0, ctx->r1) = ctx->r3;
    // 0x80054200: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80054204: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80054208: sb          $v0, 0x5587($at)
    MEM_B(0X5587, ctx->r1) = ctx->r2;
    // 0x8005420C: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80054210: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80054214: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80054218: bne         $v0, $zero, L_80054228
    if (ctx->r2 != 0) {
        // 0x8005421C: nop
    
            goto L_80054228;
    }
    // 0x8005421C: nop

    // 0x80054220: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80054224: sb          $zero, 0x5587($at)
    MEM_B(0X5587, ctx->r1) = 0;
L_80054228:
    // 0x80054228: jr          $ra
    // 0x8005422C: nop

    return;
    // 0x8005422C: nop

;}
RECOMP_FUNC void func_80054230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054230: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054234: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80054238: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8005423C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80054240: addiu       $a1, $a1, 0x2740
    ctx->r5 = ADD32(ctx->r5, 0X2740);
    // 0x80054244: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80054248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005424C: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x80054250: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80054254: addiu       $v1, $a1, 0x21
    ctx->r3 = ADD32(ctx->r5, 0X21);
    // 0x80054258: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005425C: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x80054260: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80054264: lbu         $a3, 0x7BA0($a3)
    ctx->r7 = MEM_BU(ctx->r7, 0X7BA0);
L_80054268:
    // 0x80054268: sb          $a2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r6;
    // 0x8005426C: sb          $zero, -0x1D($v1)
    MEM_B(-0X1D, ctx->r3) = 0;
    // 0x80054270: sb          $zero, -0x1C($v1)
    MEM_B(-0X1C, ctx->r3) = 0;
    // 0x80054274: sb          $zero, -0x1B($v1)
    MEM_B(-0X1B, ctx->r3) = 0;
    // 0x80054278: sb          $zero, -0x1A($v1)
    MEM_B(-0X1A, ctx->r3) = 0;
    // 0x8005427C: sb          $zero, -0x20($v1)
    MEM_B(-0X20, ctx->r3) = 0;
    // 0x80054280: sb          $a0, -0x1E($v1)
    MEM_B(-0X1E, ctx->r3) = ctx->r4;
    // 0x80054284: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80054288: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8005428C: lbu         $v0, 0x5A6C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5A6C);
    // 0x80054290: sb          $zero, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = 0;
    // 0x80054294: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80054298: bne         $a0, $a3, L_800542A4
    if (ctx->r4 != ctx->r7) {
        // 0x8005429C: sb          $v0, -0x1F($v1)
        MEM_B(-0X1F, ctx->r3) = ctx->r2;
            goto L_800542A4;
    }
    // 0x8005429C: sb          $v0, -0x1F($v1)
    MEM_B(-0X1F, ctx->r3) = ctx->r2;
    // 0x800542A0: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_800542A4:
    // 0x800542A4: addiu       $v1, $v1, 0x24
    ctx->r3 = ADD32(ctx->r3, 0X24);
    // 0x800542A8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800542AC: slti        $v0, $a0, 0xA
    ctx->r2 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x800542B0: bne         $v0, $zero, L_80054268
    if (ctx->r2 != 0) {
        // 0x800542B4: addiu       $a1, $a1, 0x24
        ctx->r5 = ADD32(ctx->r5, 0X24);
            goto L_80054268;
    }
    // 0x800542B4: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    // 0x800542B8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800542BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800542C0: addiu       $v1, $a1, 0x21
    ctx->r3 = ADD32(ctx->r5, 0X21);
L_800542C4:
    // 0x800542C4: sb          $a2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r6;
    // 0x800542C8: sb          $zero, -0x1D($v1)
    MEM_B(-0X1D, ctx->r3) = 0;
    // 0x800542CC: sb          $zero, -0x1C($v1)
    MEM_B(-0X1C, ctx->r3) = 0;
    // 0x800542D0: sb          $zero, -0x1B($v1)
    MEM_B(-0X1B, ctx->r3) = 0;
    // 0x800542D4: sb          $zero, -0x1A($v1)
    MEM_B(-0X1A, ctx->r3) = 0;
    // 0x800542D8: sb          $a2, -0x20($v1)
    MEM_B(-0X20, ctx->r3) = ctx->r6;
    // 0x800542DC: sb          $a0, -0x1E($v1)
    MEM_B(-0X1E, ctx->r3) = ctx->r4;
    // 0x800542E0: sb          $zero, -0x1F($v1)
    MEM_B(-0X1F, ctx->r3) = 0;
    // 0x800542E4: sb          $zero, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = 0;
    // 0x800542E8: bne         $a3, $zero, L_800542F4
    if (ctx->r7 != 0) {
        // 0x800542EC: sb          $zero, 0x0($v1)
        MEM_B(0X0, ctx->r3) = 0;
            goto L_800542F4;
    }
    // 0x800542EC: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800542F0: sb          $a2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r6;
L_800542F4:
    // 0x800542F4: addiu       $v1, $v1, 0x24
    ctx->r3 = ADD32(ctx->r3, 0X24);
    // 0x800542F8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800542FC: slti        $v0, $a0, 0x6
    ctx->r2 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
    // 0x80054300: bne         $v0, $zero, L_800542C4
    if (ctx->r2 != 0) {
        // 0x80054304: addiu       $a1, $a1, 0x24
        ctx->r5 = ADD32(ctx->r5, 0X24);
            goto L_800542C4;
    }
    // 0x80054304: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    // 0x80054308: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8005430C: sb          $zero, 0x5583($at)
    MEM_B(0X5583, ctx->r1) = 0;
    // 0x80054310: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054314: jal         0x80054350
    // 0x80054318: sw          $zero, -0x5E20($at)
    MEM_W(-0X5E20, ctx->r1) = 0;
    func_80054350(rdram, ctx);
        goto after_0;
    // 0x80054318: sw          $zero, -0x5E20($at)
    MEM_W(-0X5E20, ctx->r1) = 0;
    after_0:
    // 0x8005431C: jal         0x80057350
    // 0x80054320: nop

    func_80057350(rdram, ctx);
        goto after_1;
    // 0x80054320: nop

    after_1:
    // 0x80054324: jal         0x800543D4
    // 0x80054328: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800543D4(rdram, ctx);
        goto after_2;
    // 0x80054328: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8005432C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80054330: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80054334: jr          $ra
    // 0x80054338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80054338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005433C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005433C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80054340: addiu       $v0, $v0, 0x3A40
    ctx->r2 = ADD32(ctx->r2, 0X3A40);
    // 0x80054344: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054348: jr          $ra
    // 0x8005434C: sw          $v0, 0x491C($at)
    MEM_W(0X491C, ctx->r1) = ctx->r2;
    return;
    // 0x8005434C: sw          $v0, 0x491C($at)
    MEM_W(0X491C, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_80054350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054350: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80054354: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80054358: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8005435C: addiu       $s1, $s1, 0x3A40
    ctx->r17 = ADD32(ctx->r17, 0X3A40);
    // 0x80054360: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80054364: lui         $s3, 0x6D
    ctx->r19 = S32(0X6D << 16);
    // 0x80054368: addiu       $s3, $s3, 0x33B0
    ctx->r19 = ADD32(ctx->r19, 0X33B0);
    // 0x8005436C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80054370: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80054374: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80054378: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x8005437C: addiu       $s0, $s0, 0x5764
    ctx->r16 = ADD32(ctx->r16, 0X5764);
    // 0x80054380: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
L_80054384:
    // 0x80054384: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80054388: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8005438C: jal         0x80006D98
    // 0x80054390: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80006D98(rdram, ctx);
        goto after_0;
    // 0x80054390: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_0:
    // 0x80054394: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054398: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8005439C: addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // 0x800543A0: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x800543A4: slti        $v0, $s2, 0x1C
    ctx->r2 = SIGNED(ctx->r18) < 0X1C ? 1 : 0;
    // 0x800543A8: bne         $v0, $zero, L_80054384
    if (ctx->r2 != 0) {
        // 0x800543AC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80054384;
    }
    // 0x800543AC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800543B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800543B4: sw          $s1, 0x491C($at)
    MEM_W(0X491C, ctx->r1) = ctx->r17;
    // 0x800543B8: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800543BC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800543C0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800543C4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800543C8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800543CC: jr          $ra
    // 0x800543D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800543D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800543D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800543D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800543D8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800543DC: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800543E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800543E4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800543E8: jal         0x80057330
    // 0x800543EC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80057330(rdram, ctx);
        goto after_0;
    // 0x800543EC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x800543F0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800543F4: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800543F8: addiu       $s0, $s0, 0x2740
    ctx->r16 = ADD32(ctx->r16, 0X2740);
L_800543FC:
    // 0x800543FC: jal         0x800544E4
    // 0x80054400: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800544E4(rdram, ctx);
        goto after_1;
    // 0x80054400: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80054404: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80054408: slti        $v0, $s1, 0x10
    ctx->r2 = SIGNED(ctx->r17) < 0X10 ? 1 : 0;
    // 0x8005440C: bne         $v0, $zero, L_800543FC
    if (ctx->r2 != 0) {
        // 0x80054410: addiu       $s0, $s0, 0x24
        ctx->r16 = ADD32(ctx->r16, 0X24);
            goto L_800543FC;
    }
    // 0x80054410: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
    // 0x80054414: jal         0x80055990
    // 0x80054418: nop

    func_80055990(rdram, ctx);
        goto after_2;
    // 0x80054418: nop

    after_2:
    // 0x8005441C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80054420: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x80054424: jal         0x80055A1C
    // 0x80054428: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    func_80055A1C(rdram, ctx);
        goto after_3;
    // 0x80054428: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_3:
    // 0x8005442C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80054430: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    // 0x80054434: jal         0x80055A1C
    // 0x80054438: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    func_80055A1C(rdram, ctx);
        goto after_4;
    // 0x80054438: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_4:
    // 0x8005443C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x80054440: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    // 0x80054444: jal         0x80055A1C
    // 0x80054448: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    func_80055A1C(rdram, ctx);
        goto after_5;
    // 0x80054448: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_5:
    // 0x8005444C: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x80054450: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80054454: jal         0x80055A1C
    // 0x80054458: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    func_80055A1C(rdram, ctx);
        goto after_6;
    // 0x80054458: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_6:
    // 0x8005445C: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x80054460: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x80054464: jal         0x80055A1C
    // 0x80054468: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    func_80055A1C(rdram, ctx);
        goto after_7;
    // 0x80054468: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_7:
    // 0x8005446C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80054470: lb          $v0, 0x5583($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5583);
    // 0x80054474: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80054478: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8005447C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80054480: lw          $v0, 0x5A78($at)
    ctx->r2 = MEM_W(ctx->r1, 0X5A78);
    // 0x80054484: jalr        $v0
    // 0x80054488: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_8;
    // 0x80054488: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_8:
    // 0x8005448C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80054490: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80054494: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80054498: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005449C: jr          $ra
    // 0x800544A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800544A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800544A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800544A4: jr          $ra
    // 0x800544A8: nop

    return;
    // 0x800544A8: nop

;}
RECOMP_FUNC void func_800544AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800544AC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800544B0: lw          $v0, -0x5E20($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E20);
    // 0x800544B4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800544B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800544BC: bgtz        $v0, L_800544DC
    if (SIGNED(ctx->r2) > 0) {
        // 0x800544C0: sw          $v0, -0x5E20($at)
        MEM_W(-0X5E20, ctx->r1) = ctx->r2;
            goto L_800544DC;
    }
    // 0x800544C0: sw          $v0, -0x5E20($at)
    MEM_W(-0X5E20, ctx->r1) = ctx->r2;
    // 0x800544C4: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x800544C8: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // 0x800544CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800544D0: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
    // 0x800544D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800544D8: sw          $zero, -0x5E20($at)
    MEM_W(-0X5E20, ctx->r1) = 0;
L_800544DC:
    // 0x800544DC: jr          $ra
    // 0x800544E0: nop

    return;
    // 0x800544E0: nop

;}
RECOMP_FUNC void func_800544E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800544E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800544E8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800544EC: lbu         $v1, 0x21($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X21);
    // 0x800544F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800544F4: bne         $v1, $v0, L_80054538
    if (ctx->r3 != ctx->r2) {
        // 0x800544F8: nop
    
            goto L_80054538;
    }
    // 0x800544F8: nop

    // 0x800544FC: lhu         $v0, 0x1C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X1C);
    // 0x80054500: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80054504: sh          $v0, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r2;
    // 0x80054508: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8005450C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80054510: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80054514: beq         $v0, $zero, L_80054524
    if (ctx->r2 == 0) {
        // 0x80054518: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80054524;
    }
    // 0x80054518: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005451C: j           L_80054528
    // 0x80054520: sb          $v0, 0x20($a0)
    MEM_B(0X20, ctx->r4) = ctx->r2;
        goto L_80054528;
    // 0x80054520: sb          $v0, 0x20($a0)
    MEM_B(0X20, ctx->r4) = ctx->r2;
L_80054524:
    // 0x80054524: sb          $zero, 0x20($a0)
    MEM_B(0X20, ctx->r4) = 0;
L_80054528:
    // 0x80054528: lh          $v1, 0x1C($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1C);
    // 0x8005452C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80054530: beql        $v1, $v0, L_80054538
    if (ctx->r3 == ctx->r2) {
        // 0x80054534: sh          $zero, 0x1C($a0)
        MEM_H(0X1C, ctx->r4) = 0;
            goto L_80054538;
    }
    goto skip_0;
    // 0x80054534: sh          $zero, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = 0;
    skip_0:
L_80054538:
    // 0x80054538: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8005453C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80054540: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80054544: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80054548: lw          $v0, 0x5AB8($at)
    ctx->r2 = MEM_W(ctx->r1, 0X5AB8);
    // 0x8005454C: jalr        $v0
    // 0x80054550: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80054550: nop

    after_0:
    // 0x80054554: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80054558: jr          $ra
    // 0x8005455C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005455C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80054560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054564: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80054568: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x8005456C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80054570: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80054574: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80054578: lw          $v0, 0x5AC0($at)
    ctx->r2 = MEM_W(ctx->r1, 0X5AC0);
    // 0x8005457C: jalr        $v0
    // 0x80054580: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80054580: nop

    after_0:
    // 0x80054584: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80054588: jr          $ra
    // 0x8005458C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005458C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80054590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054590: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x80054594: lbu         $v1, 0x3($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X3);
    // 0x80054598: lbu         $a1, 0x3($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X3);
    // 0x8005459C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800545A0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800545A4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800545A8: lwc1        $f0, 0x5ACC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5ACC);
    // 0x800545AC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800545B0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800545B4: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x800545B8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800545BC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800545C0: lwc1        $f0, 0x5AD0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5AD0);
    // 0x800545C4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800545C8: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800545CC: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x800545D0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800545D4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800545D8: lw          $v0, 0x5AFC($at)
    ctx->r2 = MEM_W(ctx->r1, 0X5AFC);
    // 0x800545DC: bne         $v0, $zero, L_800545F8
    if (ctx->r2 != 0) {
        // 0x800545E0: sll         $v0, $a1, 3
        ctx->r2 = S32(ctx->r5 << 3);
            goto L_800545F8;
    }
    // 0x800545E0: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x800545E4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800545E8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800545EC: lw          $v0, 0x5ACC($at)
    ctx->r2 = MEM_W(ctx->r1, 0X5ACC);
    // 0x800545F0: j           L_80054608
    // 0x800545F4: addiu       $v0, $v0, 0xB8
    ctx->r2 = ADD32(ctx->r2, 0XB8);
        goto L_80054608;
    // 0x800545F4: addiu       $v0, $v0, 0xB8
    ctx->r2 = ADD32(ctx->r2, 0XB8);
L_800545F8:
    // 0x800545F8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800545FC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80054600: lw          $v0, 0x5ACC($at)
    ctx->r2 = MEM_W(ctx->r1, 0X5ACC);
    // 0x80054604: addiu       $v0, $v0, -0xB8
    ctx->r2 = ADD32(ctx->r2, -0XB8);
L_80054608:
    // 0x80054608: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8005460C: nop

    // 0x80054610: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80054614: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x80054618: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x8005461C: lbu         $v1, 0x4($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X4);
    // 0x80054620: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80054624: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80054628: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005462C: lw          $v0, 0x5AFC($at)
    ctx->r2 = MEM_W(ctx->r1, 0X5AFC);
    // 0x80054630: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80054634: sb          $v1, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r3;
    // 0x80054638: jr          $ra
    // 0x8005463C: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
    return;
    // 0x8005463C: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_80054640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054644: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80054648: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x8005464C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80054650: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80054654: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80054658: lw          $v0, 0x5B14($at)
    ctx->r2 = MEM_W(ctx->r1, 0X5B14);
    // 0x8005465C: jalr        $v0
    // 0x80054660: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80054660: nop

    after_0:
    // 0x80054664: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80054668: jr          $ra
    // 0x8005466C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005466C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80054670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054670: lbu         $v1, 0x3($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X3);
    // 0x80054674: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x80054678: beq         $v0, $zero, L_800546F4
    if (ctx->r2 == 0) {
        // 0x8005467C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800546F4;
    }
    // 0x8005467C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80054680: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80054684: addu        $at, $at, $v0
    gpr jr_addend_8005468C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80054688: lw          $v0, -0x13C0($at)
    ctx->r2 = ADD32(ctx->r1, -0X13C0);
    // 0x8005468C: jr          $v0
    // 0x80054690: nop

    switch (jr_addend_8005468C >> 2) {
        case 0: goto L_80054694; break;
        case 1: goto L_80054694; break;
        case 2: goto L_800546AC; break;
        case 3: goto L_800546AC; break;
        case 4: goto L_800546C4; break;
        case 5: goto L_800546C4; break;
        default: switch_error(__func__, 0x8005468C, 0x800AEC40);
    }
    // 0x80054690: nop

L_80054694:
    // 0x80054694: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054698: lwc1        $f2, 0x274C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X274C);
    // 0x8005469C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800546A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800546A4: j           L_800546D8
    // 0x800546A8: nop

        goto L_800546D8;
    // 0x800546A8: nop

L_800546AC:
    // 0x800546AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800546B0: lwc1        $f2, 0x274C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X274C);
    // 0x800546B4: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800546B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800546BC: j           L_800546D8
    // 0x800546C0: nop

        goto L_800546D8;
    // 0x800546C0: nop

L_800546C4:
    // 0x800546C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800546C8: lwc1        $f2, 0x274C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X274C);
    // 0x800546CC: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x800546D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800546D4: nop

L_800546D8:
    // 0x800546D8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800546DC: nop

    // 0x800546E0: bc1f        L_800546F4
    if (!c1cs) {
        // 0x800546E4: nop
    
            goto L_800546F4;
    }
    // 0x800546E4: nop

    // 0x800546E8: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x800546EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800546F0: sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
L_800546F4:
    // 0x800546F4: jr          $ra
    // 0x800546F8: nop

    return;
    // 0x800546F8: nop

;}
RECOMP_FUNC void func_800546FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800546FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054700: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80054704: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x80054708: bne         $v0, $zero, L_80054734
    if (ctx->r2 != 0) {
        // 0x8005470C: nop
    
            goto L_80054734;
    }
    // 0x8005470C: nop

    // 0x80054710: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80054714: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80054718: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005471C: nop

    // 0x80054720: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80054724: lwc1        $f2, 0x18($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80054728: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8005472C: j           L_80054758
    // 0x80054730: nop

        goto L_80054758;
    // 0x80054730: nop

L_80054734:
    // 0x80054734: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80054738: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8005473C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80054740: nop

    // 0x80054744: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80054748: lwc1        $f2, 0x18($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8005474C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80054750: nop

    // 0x80054754: nop

L_80054758:
    // 0x80054758: bc1f        L_80054770
    if (!c1cs) {
        // 0x8005475C: swc1        $f0, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
            goto L_80054770;
    }
    // 0x8005475C: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80054760: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x80054764: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
    // 0x80054768: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005476C: sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
L_80054770:
    // 0x80054770: jal         0x800547A0
    // 0x80054774: nop

    func_800547A0(rdram, ctx);
        goto after_0;
    // 0x80054774: nop

    after_0:
    // 0x80054778: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005477C: jr          $ra
    // 0x80054780: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80054780: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80054784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054784: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054788: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005478C: jal         0x800547A0
    // 0x80054790: nop

    func_800547A0(rdram, ctx);
        goto after_0;
    // 0x80054790: nop

    after_0:
    // 0x80054794: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80054798: jr          $ra
    // 0x8005479C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005479C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800547A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800547A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800547A4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800547A8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800547AC: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800547B0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800547B4: lbu         $v1, 0x3($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X3);
    // 0x800547B8: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x800547BC: beq         $v0, $zero, L_80054C68
    if (ctx->r2 == 0) {
        // 0x800547C0: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80054C68;
    }
    // 0x800547C0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800547C4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800547C8: addu        $at, $at, $v0
    gpr jr_addend_800547D0 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800547CC: lw          $v0, -0x1368($at)
    ctx->r2 = ADD32(ctx->r1, -0X1368);
    // 0x800547D0: jr          $v0
    // 0x800547D4: nop

    switch (jr_addend_800547D0 >> 2) {
        case 0: goto L_800547D8; break;
        case 1: goto L_80054844; break;
        case 2: goto L_800549CC; break;
        case 3: goto L_800549F8; break;
        case 4: goto L_80054A24; break;
        case 5: goto L_80054B10; break;
        default: switch_error(__func__, 0x800547D0, 0x800AEC98);
    }
    // 0x800547D4: nop

L_800547D8:
    // 0x800547D8: lbu         $v0, 0x20($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X20);
    // 0x800547DC: bne         $v0, $zero, L_80054814
    if (ctx->r2 != 0) {
        // 0x800547E0: nop
    
            goto L_80054814;
    }
    // 0x800547E0: nop

    // 0x800547E4: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800547E8: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800547EC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800547F0: lw          $a0, 0x5924($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5924);
    // 0x800547F4: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800547F8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800547FC: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80054800: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80054804: jal         0x80055A1C
    // 0x80054808: nop

    func_80055A1C(rdram, ctx);
        goto after_0;
    // 0x80054808: nop

    after_0:
    // 0x8005480C: j           L_80054C68
    // 0x80054810: nop

        goto L_80054C68;
    // 0x80054810: nop

L_80054814:
    // 0x80054814: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80054818: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005481C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80054820: lw          $a0, 0x5924($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5924);
    // 0x80054824: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054828: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8005482C: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80054830: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80054834: jal         0x80055DC0
    // 0x80054838: nop

    func_80055DC0(rdram, ctx);
        goto after_1;
    // 0x80054838: nop

    after_1:
    // 0x8005483C: j           L_80054C68
    // 0x80054840: nop

        goto L_80054C68;
    // 0x80054840: nop

L_80054844:
    // 0x80054844: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x80054848: addiu       $s1, $s1, 0x5587
    ctx->r17 = ADD32(ctx->r17, 0X5587);
    // 0x8005484C: lb          $v0, 0x0($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X0);
    // 0x80054850: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80054854: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80054858: addiu       $a1, $a1, -0x13A8
    ctx->r5 = ADD32(ctx->r5, -0X13A8);
    // 0x8005485C: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x80054860: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x80054864: sll         $a2, $a2, 5
    ctx->r6 = S32(ctx->r6 << 5);
    // 0x80054868: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8005486C: addiu       $v0, $v0, 0xB9C
    ctx->r2 = ADD32(ctx->r2, 0XB9C);
    // 0x80054870: jal         0x80066CA0
    // 0x80054874: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    func_80066CA0(rdram, ctx);
        goto after_2;
    // 0x80054874: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    after_2:
    // 0x80054878: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8005487C: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80054880: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80054884: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054888: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8005488C: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80054890: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80054894: nop

    // 0x80054898: jal         0x8004F1A4
    // 0x8005489C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_3;
    // 0x8005489C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_3:
    // 0x800548A0: lbu         $v0, 0x20($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X20);
    // 0x800548A4: bne         $v0, $zero, L_8005493C
    if (ctx->r2 != 0) {
        // 0x800548A8: addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
            goto L_8005493C;
    }
    // 0x800548A8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800548AC: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800548B0: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800548B4: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800548B8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800548BC: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800548C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800548C4: nop

    // 0x800548C8: jal         0x8004F1A4
    // 0x800548CC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_4;
    // 0x800548CC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_4:
    // 0x800548D0: lb          $v0, 0x0($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X0);
    // 0x800548D4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800548D8: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x800548DC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800548E0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800548E4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800548E8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800548EC: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x800548F0: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800548F4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800548F8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800548FC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80054900: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80054904: lbu         $v0, 0xB94($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB94);
    // 0x80054908: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005490C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80054910: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80054914: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80054918: lw          $a0, 0x594C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X594C);
    // 0x8005491C: trunc.w.s   $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80054920: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80054924: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054928: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8005492C: jal         0x80055A1C
    // 0x80054930: nop

    func_80055A1C(rdram, ctx);
        goto after_5;
    // 0x80054930: nop

    after_5:
    // 0x80054934: j           L_80054C68
    // 0x80054938: nop

        goto L_80054C68;
    // 0x80054938: nop

L_8005493C:
    // 0x8005493C: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80054940: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80054944: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054948: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8005494C: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80054950: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80054954: nop

    // 0x80054958: jal         0x8004F1A4
    // 0x8005495C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    func_8004F1A4(rdram, ctx);
        goto after_6;
    // 0x8005495C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_6:
    // 0x80054960: lb          $v0, 0x0($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X0);
    // 0x80054964: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80054968: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x8005496C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80054970: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80054974: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80054978: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005497C: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80054980: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80054984: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80054988: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005498C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80054990: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80054994: lbu         $v0, 0xB94($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB94);
    // 0x80054998: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005499C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800549A0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800549A4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800549A8: lw          $a0, 0x594C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X594C);
    // 0x800549AC: trunc.w.s   $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800549B0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800549B4: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800549B8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800549BC: jal         0x80055DC0
    // 0x800549C0: nop

    func_80055DC0(rdram, ctx);
        goto after_7;
    // 0x800549C0: nop

    after_7:
    // 0x800549C4: j           L_80054C68
    // 0x800549C8: nop

        goto L_80054C68;
    // 0x800549C8: nop

L_800549CC:
    // 0x800549CC: lbu         $v0, 0x20($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X20);
    // 0x800549D0: bne         $v0, $zero, L_800549EC
    if (ctx->r2 != 0) {
        // 0x800549D4: addiu       $a3, $zero, 0x2
        ctx->r7 = ADD32(0, 0X2);
            goto L_800549EC;
    }
    // 0x800549D4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800549D8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800549DC: addiu       $a0, $a0, -0x13A4
    ctx->r4 = ADD32(ctx->r4, -0X13A4);
    // 0x800549E0: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800549E4: j           L_80054C50
    // 0x800549E8: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
        goto L_80054C50;
    // 0x800549E8: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
L_800549EC:
    // 0x800549EC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800549F0: j           L_80054C44
    // 0x800549F4: addiu       $a0, $a0, -0x13A4
    ctx->r4 = ADD32(ctx->r4, -0X13A4);
        goto L_80054C44;
    // 0x800549F4: addiu       $a0, $a0, -0x13A4
    ctx->r4 = ADD32(ctx->r4, -0X13A4);
L_800549F8:
    // 0x800549F8: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800549FC: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80054A00: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054A04: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80054A08: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80054A0C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80054A10: nop

    // 0x80054A14: jal         0x8005587C
    // 0x80054A18: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8005587C(rdram, ctx);
        goto after_8;
    // 0x80054A18: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // 0x80054A1C: j           L_80054C68
    // 0x80054A20: nop

        goto L_80054C68;
    // 0x80054A20: nop

L_80054A24:
    // 0x80054A24: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80054A28: lb          $v1, 0x5587($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X5587);
    // 0x80054A2C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80054A30: beq         $v1, $v0, L_80054AE4
    if (ctx->r3 == ctx->r2) {
        // 0x80054A34: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80054AE4;
    }
    // 0x80054A34: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80054A38: beq         $v1, $v0, L_80054A6C
    if (ctx->r3 == ctx->r2) {
        // 0x80054A3C: nop
    
            goto L_80054A6C;
    }
    // 0x80054A3C: nop

    // 0x80054A40: lbu         $v0, 0x20($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X20);
    // 0x80054A44: bne         $v0, $zero, L_80054A60
    if (ctx->r2 != 0) {
        // 0x80054A48: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_80054A60;
    }
    // 0x80054A48: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80054A4C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80054A50: addiu       $a0, $a0, -0x139C
    ctx->r4 = ADD32(ctx->r4, -0X139C);
    // 0x80054A54: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80054A58: j           L_80054C50
    // 0x80054A5C: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
        goto L_80054C50;
    // 0x80054A5C: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
L_80054A60:
    // 0x80054A60: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80054A64: j           L_80054C44
    // 0x80054A68: addiu       $a0, $a0, -0x139C
    ctx->r4 = ADD32(ctx->r4, -0X139C);
        goto L_80054C44;
    // 0x80054A68: addiu       $a0, $a0, -0x139C
    ctx->r4 = ADD32(ctx->r4, -0X139C);
L_80054A6C:
    // 0x80054A6C: lbu         $v0, 0x20($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X20);
    // 0x80054A70: bne         $v0, $zero, L_80054AAC
    if (ctx->r2 != 0) {
        // 0x80054A74: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_80054AAC;
    }
    // 0x80054A74: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80054A78: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80054A7C: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80054A80: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80054A84: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80054A88: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80054A8C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80054A90: addiu       $a0, $a0, -0x139C
    ctx->r4 = ADD32(ctx->r4, -0X139C);
    // 0x80054A94: trunc.w.s   $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80054A98: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80054A9C: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054AA0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80054AA4: j           L_80054C60
    // 0x80054AA8: nop

        goto L_80054C60;
    // 0x80054AA8: nop

L_80054AAC:
    // 0x80054AAC: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80054AB0: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80054AB4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80054AB8: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80054ABC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80054AC0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80054AC4: addiu       $a0, $a0, -0x139C
    ctx->r4 = ADD32(ctx->r4, -0X139C);
    // 0x80054AC8: trunc.w.s   $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80054ACC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80054AD0: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054AD4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80054AD8: nop

    // 0x80054ADC: j           L_80054C60
    // 0x80054AE0: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
        goto L_80054C60;
    // 0x80054AE0: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
L_80054AE4:
    // 0x80054AE4: lbu         $v0, 0x20($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X20);
    // 0x80054AE8: bne         $v0, $zero, L_80054B04
    if (ctx->r2 != 0) {
        // 0x80054AEC: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_80054B04;
    }
    // 0x80054AEC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80054AF0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80054AF4: addiu       $a0, $a0, -0x1394
    ctx->r4 = ADD32(ctx->r4, -0X1394);
    // 0x80054AF8: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80054AFC: j           L_80054C50
    // 0x80054B00: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
        goto L_80054C50;
    // 0x80054B00: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
L_80054B04:
    // 0x80054B04: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80054B08: j           L_80054C44
    // 0x80054B0C: addiu       $a0, $a0, -0x1394
    ctx->r4 = ADD32(ctx->r4, -0X1394);
        goto L_80054C44;
    // 0x80054B0C: addiu       $a0, $a0, -0x1394
    ctx->r4 = ADD32(ctx->r4, -0X1394);
L_80054B10:
    // 0x80054B10: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80054B14: lb          $v1, 0x5587($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X5587);
    // 0x80054B18: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80054B1C: beq         $v1, $v0, L_80054C10
    if (ctx->r3 == ctx->r2) {
        // 0x80054B20: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80054C10;
    }
    // 0x80054B20: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80054B24: beq         $v1, $v0, L_80054B78
    if (ctx->r3 == ctx->r2) {
        // 0x80054B28: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80054B78;
    }
    // 0x80054B28: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80054B2C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80054B30: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80054B34: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80054B38: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x80054B3C: lbu         $a2, 0xB91($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XB91);
    // 0x80054B40: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80054B44: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x80054B48: lbu         $a3, 0xB92($a3)
    ctx->r7 = MEM_BU(ctx->r7, 0XB92);
    // 0x80054B4C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80054B50: addiu       $a1, $a1, -0x138C
    ctx->r5 = ADD32(ctx->r5, -0X138C);
    // 0x80054B54: jal         0x80066CA0
    // 0x80054B58: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80066CA0(rdram, ctx);
        goto after_9;
    // 0x80054B58: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_9:
    // 0x80054B5C: lbu         $v0, 0x20($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X20);
    // 0x80054B60: bne         $v0, $zero, L_80054C44
    if (ctx->r2 != 0) {
        // 0x80054B64: addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
            goto L_80054C44;
    }
    // 0x80054B64: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80054B68: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80054B6C: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80054B70: j           L_80054C50
    // 0x80054B74: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_80054C50;
    // 0x80054B74: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_80054B78:
    // 0x80054B78: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80054B7C: lbu         $a2, 0xD70($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XD70);
    // 0x80054B80: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80054B84: lbu         $a3, 0xD71($a3)
    ctx->r7 = MEM_BU(ctx->r7, 0XD71);
    // 0x80054B88: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80054B8C: lbu         $v0, 0xD72($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XD72);
    // 0x80054B90: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80054B94: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80054B98: addiu       $a1, $a1, -0x1380
    ctx->r5 = ADD32(ctx->r5, -0X1380);
    // 0x80054B9C: jal         0x80066CA0
    // 0x80054BA0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80066CA0(rdram, ctx);
        goto after_10;
    // 0x80054BA0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_10:
    // 0x80054BA4: lbu         $v0, 0x20($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X20);
    // 0x80054BA8: bne         $v0, $zero, L_80054BE0
    if (ctx->r2 != 0) {
        // 0x80054BAC: addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
            goto L_80054BE0;
    }
    // 0x80054BAC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80054BB0: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80054BB4: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x80054BB8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80054BBC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80054BC0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80054BC4: trunc.w.s   $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80054BC8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80054BCC: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054BD0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80054BD4: nop

    // 0x80054BD8: j           L_80054C60
    // 0x80054BDC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_80054C60;
    // 0x80054BDC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_80054BE0:
    // 0x80054BE0: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80054BE4: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x80054BE8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80054BEC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80054BF0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80054BF4: trunc.w.s   $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80054BF8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80054BFC: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054C00: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80054C04: nop

    // 0x80054C08: j           L_80054C60
    // 0x80054C0C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
        goto L_80054C60;
    // 0x80054C0C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
L_80054C10:
    // 0x80054C10: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80054C14: lbu         $a2, 0xCD1($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XCD1);
    // 0x80054C18: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80054C1C: addiu       $a1, $a1, -0x1370
    ctx->r5 = ADD32(ctx->r5, -0X1370);
    // 0x80054C20: jal         0x80066CA0
    // 0x80054C24: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80066CA0(rdram, ctx);
        goto after_11;
    // 0x80054C24: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_11:
    // 0x80054C28: lbu         $v0, 0x20($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X20);
    // 0x80054C2C: bne         $v0, $zero, L_80054C44
    if (ctx->r2 != 0) {
        // 0x80054C30: addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
            goto L_80054C44;
    }
    // 0x80054C30: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80054C34: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80054C38: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80054C3C: j           L_80054C50
    // 0x80054C40: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_80054C50;
    // 0x80054C40: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_80054C44:
    // 0x80054C44: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80054C48: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80054C4C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
L_80054C50:
    // 0x80054C50: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054C54: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80054C58: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80054C5C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_80054C60:
    // 0x80054C60: jal         0x8004F1A4
    // 0x80054C64: nop

    func_8004F1A4(rdram, ctx);
        goto after_12;
    // 0x80054C64: nop

    after_12:
L_80054C68:
    // 0x80054C68: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80054C6C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80054C70: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80054C74: jr          $ra
    // 0x80054C78: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80054C78: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80054C7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054C7C: jr          $ra
    // 0x80054C80: nop

    return;
    // 0x80054C80: nop

;}
RECOMP_FUNC void func_80054C84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054C84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054C88: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80054C8C: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x80054C90: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80054C94: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80054C98: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80054C9C: lw          $v0, 0x5B20($at)
    ctx->r2 = MEM_W(ctx->r1, 0X5B20);
    // 0x80054CA0: jalr        $v0
    // 0x80054CA4: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80054CA4: nop

    after_0:
    // 0x80054CA8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80054CAC: jr          $ra
    // 0x80054CB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80054CB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80054CB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054CB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054CB8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80054CBC: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x80054CC0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80054CC4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80054CC8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80054CCC: lwc1        $f0, 0x5B2C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B2C);
    // 0x80054CD0: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x80054CD4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80054CD8: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80054CDC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80054CE0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80054CE4: lwc1        $f0, 0x5B30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B30);
    // 0x80054CE8: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x80054CEC: beq         $v0, $zero, L_80054D34
    if (ctx->r2 == 0) {
        // 0x80054CF0: swc1        $f0, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
            goto L_80054D34;
    }
    // 0x80054CF0: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x80054CF4: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x80054CF8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80054CFC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80054D00: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80054D04: lwc1        $f0, 0x5B7C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5B7C);
    // 0x80054D08: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x80054D0C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80054D10: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x80054D14: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80054D18: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80054D1C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80054D20: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80054D24: lwc1        $f2, 0x5B80($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5B80);
    // 0x80054D28: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x80054D2C: j           L_80054D50
    // 0x80054D30: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
        goto L_80054D50;
    // 0x80054D30: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
L_80054D34:
    // 0x80054D34: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80054D38: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80054D3C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80054D40: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80054D44: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x80054D48: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x80054D4C: swc1        $f2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f2.u32l;
L_80054D50:
    // 0x80054D50: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x80054D54: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80054D58: jal         0x80054D6C
    // 0x80054D5C: sb          $v0, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r2;
    func_80054D6C(rdram, ctx);
        goto after_0;
    // 0x80054D5C: sb          $v0, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r2;
    after_0:
    // 0x80054D60: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80054D64: jr          $ra
    // 0x80054D68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80054D68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80054D6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054D6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054D70: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80054D74: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x80054D78: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80054D7C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80054D80: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80054D84: lw          $v0, 0x5B94($at)
    ctx->r2 = MEM_W(ctx->r1, 0X5B94);
    // 0x80054D88: jalr        $v0
    // 0x80054D8C: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80054D8C: nop

    after_0:
    // 0x80054D90: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80054D94: jr          $ra
    // 0x80054D98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80054D98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80054D9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054D9C: lbu         $v1, 0x3($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X3);
    // 0x80054DA0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80054DA4: bne         $v1, $v0, L_80054DB8
    if (ctx->r3 != ctx->r2) {
        // 0x80054DA8: nop
    
            goto L_80054DB8;
    }
    // 0x80054DA8: nop

    // 0x80054DAC: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x80054DB0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80054DB4: sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
L_80054DB8:
    // 0x80054DB8: jr          $ra
    // 0x80054DBC: nop

    return;
    // 0x80054DBC: nop

;}
RECOMP_FUNC void func_80054DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054DC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054DC4: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80054DC8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80054DCC: lbu         $v1, 0x3($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X3);
    // 0x80054DD0: beq         $v1, $zero, L_80054E34
    if (ctx->r3 == 0) {
        // 0x80054DD4: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80054E34;
    }
    // 0x80054DD4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80054DD8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80054DDC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80054DE0: lbu         $v1, 0x5BAC($at)
    ctx->r3 = MEM_BU(ctx->r1, 0X5BAC);
    // 0x80054DE4: beq         $v1, $v0, L_80054EC8
    if (ctx->r3 == ctx->r2) {
        // 0x80054DE8: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_80054EC8;
    }
    // 0x80054DE8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80054DEC: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80054DF0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80054DF4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80054DF8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80054DFC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80054E00: lbu         $v1, 0x2745($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2745);
    // 0x80054E04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054E08: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80054E0C: lwc1        $f0, 0x2750($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X2750);
    // 0x80054E10: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80054E14: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80054E18: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054E1C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80054E20: sb          $v1, 0x2745($at)
    MEM_B(0X2745, ctx->r1) = ctx->r3;
    // 0x80054E24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054E28: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80054E2C: j           L_80054EC8
    // 0x80054E30: swc1        $f0, 0x2750($at)
    MEM_W(0X2750, ctx->r1) = ctx->f0.u32l;
        goto L_80054EC8;
    // 0x80054E30: swc1        $f0, 0x2750($at)
    MEM_W(0X2750, ctx->r1) = ctx->f0.u32l;
L_80054E34:
    // 0x80054E34: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80054E38: addiu       $a1, $a1, 0x2769
    ctx->r5 = ADD32(ctx->r5, 0X2769);
    // 0x80054E3C: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x80054E40: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80054E44: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80054E48: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80054E4C: lbu         $v0, 0x278D($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X278D);
    // 0x80054E50: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80054E54: lbu         $v1, 0x27B1($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X27B1);
    // 0x80054E58: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80054E5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80054E60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054E64: sw          $zero, 0x2774($at)
    MEM_W(0X2774, ctx->r1) = 0;
    // 0x80054E68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054E6C: sw          $zero, 0x2798($at)
    MEM_W(0X2798, ctx->r1) = 0;
    // 0x80054E70: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054E74: sw          $zero, 0x27BC($at)
    MEM_W(0X27BC, ctx->r1) = 0;
    // 0x80054E78: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80054E7C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80054E80: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80054E84: sb          $a0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r4;
    // 0x80054E88: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054E8C: swc1        $f2, 0x2778($at)
    MEM_W(0X2778, ctx->r1) = ctx->f2.u32l;
    // 0x80054E90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054E94: swc1        $f0, 0x277C($at)
    MEM_W(0X277C, ctx->r1) = ctx->f0.u32l;
    // 0x80054E98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054E9C: sb          $v0, 0x278D($at)
    MEM_B(0X278D, ctx->r1) = ctx->r2;
    // 0x80054EA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054EA4: swc1        $f2, 0x279C($at)
    MEM_W(0X279C, ctx->r1) = ctx->f2.u32l;
    // 0x80054EA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054EAC: swc1        $f0, 0x27A0($at)
    MEM_W(0X27A0, ctx->r1) = ctx->f0.u32l;
    // 0x80054EB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054EB4: sb          $v1, 0x27B1($at)
    MEM_B(0X27B1, ctx->r1) = ctx->r3;
    // 0x80054EB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054EBC: swc1        $f2, 0x27C0($at)
    MEM_W(0X27C0, ctx->r1) = ctx->f2.u32l;
    // 0x80054EC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054EC4: swc1        $f0, 0x27C4($at)
    MEM_W(0X27C4, ctx->r1) = ctx->f0.u32l;
L_80054EC8:
    // 0x80054EC8: lbu         $v0, 0x5($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X5);
    // 0x80054ECC: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x80054ED0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80054ED4: jal         0x80054EE8
    // 0x80054ED8: sb          $v0, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r2;
    func_80054EE8(rdram, ctx);
        goto after_0;
    // 0x80054ED8: sb          $v0, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r2;
    after_0:
    // 0x80054EDC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80054EE0: jr          $ra
    // 0x80054EE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80054EE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80054EE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054EE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054EEC: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80054EF0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80054EF4: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80054EF8: lwc1        $f2, 0x10($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80054EFC: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80054F00: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80054F04: lwc1        $f2, 0x14($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80054F08: lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X2);
    // 0x80054F0C: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80054F10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80054F14: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x80054F18: beq         $v1, $v0, L_80054F60
    if (ctx->r3 == ctx->r2) {
        // 0x80054F1C: swc1        $f4, 0xC($a1)
        MEM_W(0XC, ctx->r5) = ctx->f4.u32l;
            goto L_80054F60;
    }
    // 0x80054F1C: swc1        $f4, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f4.u32l;
    // 0x80054F20: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80054F24: beql        $v0, $zero, L_80054F3C
    if (ctx->r2 == 0) {
        // 0x80054F28: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80054F3C;
    }
    goto skip_0;
    // 0x80054F28: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x80054F2C: beq         $v1, $zero, L_80054F4C
    if (ctx->r3 == 0) {
        // 0x80054F30: nop
    
            goto L_80054F4C;
    }
    // 0x80054F30: nop

    // 0x80054F34: j           L_80054FE0
    // 0x80054F38: nop

        goto L_80054FE0;
    // 0x80054F38: nop

L_80054F3C:
    // 0x80054F3C: beq         $v1, $v0, L_80054FBC
    if (ctx->r3 == ctx->r2) {
        // 0x80054F40: nop
    
            goto L_80054FBC;
    }
    // 0x80054F40: nop

    // 0x80054F44: j           L_80054FE0
    // 0x80054F48: nop

        goto L_80054FE0;
    // 0x80054F48: nop

L_80054F4C:
    // 0x80054F4C: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80054F50: lwc1        $f2, 0x18($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80054F54: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80054F58: j           L_80054F70
    // 0x80054F5C: nop

        goto L_80054F70;
    // 0x80054F5C: nop

L_80054F60:
    // 0x80054F60: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80054F64: lwc1        $f2, 0x18($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80054F68: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80054F6C: nop

L_80054F70:
    // 0x80054F70: bc1f        L_80054FE0
    if (!c1cs) {
        // 0x80054F74: nop
    
            goto L_80054FE0;
    }
    // 0x80054F74: nop

    // 0x80054F78: lbu         $v0, 0x5($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X5);
    // 0x80054F7C: lbu         $a0, 0x3($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X3);
    // 0x80054F80: swc1        $f2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f2.u32l;
    // 0x80054F84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80054F88: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80054F8C: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x80054F90: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80054F94: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80054F98: sb          $v0, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r2;
    // 0x80054F9C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80054FA0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80054FA4: lbu         $v0, 0x2745($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2745);
    // 0x80054FA8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80054FAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054FB0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80054FB4: j           L_80054FE0
    // 0x80054FB8: sb          $v0, 0x2745($at)
    MEM_B(0X2745, ctx->r1) = ctx->r2;
        goto L_80054FE0;
    // 0x80054FB8: sb          $v0, 0x2745($at)
    MEM_B(0X2745, ctx->r1) = ctx->r2;
L_80054FBC:
    // 0x80054FBC: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80054FC0: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80054FC4: nop

    // 0x80054FC8: bc1f        L_80054FE0
    if (!c1cs) {
        // 0x80054FCC: nop
    
            goto L_80054FE0;
    }
    // 0x80054FCC: nop

    // 0x80054FD0: lbu         $v0, 0x5($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X5);
    // 0x80054FD4: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x80054FD8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80054FDC: sb          $v0, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r2;
L_80054FE0:
    // 0x80054FE0: jal         0x80055164
    // 0x80054FE4: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    func_80055164(rdram, ctx);
        goto after_0;
    // 0x80054FE4: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    after_0:
    // 0x80054FE8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80054FEC: jr          $ra
    // 0x80054FF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80054FF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80054FF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054FF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054FF8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80054FFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80055000: jal         0x80055164
    // 0x80055004: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_80055164(rdram, ctx);
        goto after_0;
    // 0x80055004: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80055008: lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X3);
    // 0x8005500C: bne         $v0, $zero, L_8005503C
    if (ctx->r2 != 0) {
        // 0x80055010: addiu       $v1, $zero, 0xB4
        ctx->r3 = ADD32(0, 0XB4);
            goto L_8005503C;
    }
    // 0x80055010: addiu       $v1, $zero, 0xB4
    ctx->r3 = ADD32(0, 0XB4);
    // 0x80055014: lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5);
    // 0x80055018: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8005501C: addiu       $a0, $a0, 0x5583
    ctx->r4 = ADD32(ctx->r4, 0X5583);
    // 0x80055020: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80055024: sb          $v0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r2;
    // 0x80055028: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8005502C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055030: sw          $v1, -0x5E20($at)
    MEM_W(-0X5E20, ctx->r1) = ctx->r3;
    // 0x80055034: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80055038: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_8005503C:
    // 0x8005503C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80055040: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80055044: jr          $ra
    // 0x80055048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80055048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005504C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005504C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80055050: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80055054: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80055058: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8005505C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80055060: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80055064: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80055068: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x8005506C: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80055070: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x80055074: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80055078: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8005507C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80055080: lbu         $v1, 0x5BB8($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X5BB8);
    // 0x80055084: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80055088: beq         $v1, $v0, L_800550E4
    if (ctx->r3 == ctx->r2) {
        // 0x8005508C: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800550E4;
    }
    // 0x8005508C: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80055090: beql        $v0, $zero, L_800550A8
    if (ctx->r2 == 0) {
        // 0x80055094: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800550A8;
    }
    goto skip_0;
    // 0x80055094: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x80055098: beq         $v1, $zero, L_800550B8
    if (ctx->r3 == 0) {
        // 0x8005509C: nop
    
            goto L_800550B8;
    }
    // 0x8005509C: nop

    // 0x800550A0: j           L_80055134
    // 0x800550A4: nop

        goto L_80055134;
    // 0x800550A4: nop

L_800550A8:
    // 0x800550A8: beq         $v1, $v0, L_80055110
    if (ctx->r3 == ctx->r2) {
        // 0x800550AC: nop
    
            goto L_80055110;
    }
    // 0x800550AC: nop

    // 0x800550B0: j           L_80055134
    // 0x800550B4: nop

        goto L_80055134;
    // 0x800550B4: nop

L_800550B8:
    // 0x800550B8: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800550BC: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x800550C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800550C4: nop

    // 0x800550C8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800550CC: nop

    // 0x800550D0: bc1f        L_80055134
    if (!c1cs) {
        // 0x800550D4: nop
    
            goto L_80055134;
    }
    // 0x800550D4: nop

    // 0x800550D8: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x800550DC: j           L_80055130
    // 0x800550E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_80055130;
    // 0x800550E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800550E4:
    // 0x800550E4: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800550E8: lui         $at, 0xC370
    ctx->r1 = S32(0XC370 << 16);
    // 0x800550EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800550F0: nop

    // 0x800550F4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800550F8: nop

    // 0x800550FC: bc1f        L_80055134
    if (!c1cs) {
        // 0x80055100: nop
    
            goto L_80055134;
    }
    // 0x80055100: nop

    // 0x80055104: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x80055108: j           L_80055130
    // 0x8005510C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_80055130;
    // 0x8005510C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80055110:
    // 0x80055110: lwc1        $f0, 0x18($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80055114: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80055118: nop

    // 0x8005511C: bc1f        L_80055134
    if (!c1cs) {
        // 0x80055120: nop
    
            goto L_80055134;
    }
    // 0x80055120: nop

    // 0x80055124: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x80055128: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x8005512C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80055130:
    // 0x80055130: sb          $v0, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r2;
L_80055134:
    // 0x80055134: jal         0x80055164
    // 0x80055138: nop

    func_80055164(rdram, ctx);
        goto after_0;
    // 0x80055138: nop

    after_0:
    // 0x8005513C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80055140: jr          $ra
    // 0x80055144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80055144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80055148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005514C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80055150: jal         0x80055164
    // 0x80055154: nop

    func_80055164(rdram, ctx);
        goto after_0;
    // 0x80055154: nop

    after_0:
    // 0x80055158: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005515C: jr          $ra
    // 0x80055160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80055160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80055164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055164: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80055168: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8005516C: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x80055170: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80055174: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80055178: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8005517C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80055180: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80055184: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80055188: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8005518C: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x80055190: lwc1        $f2, 0xC($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0XC);
    // 0x80055194: lbu         $v1, 0x3($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X3);
    // 0x80055198: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005519C: mfc1        $s3, $f4
    ctx->r19 = (int32_t)ctx->f4.u32l;
    // 0x800551A0: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800551A4: mfc1        $s5, $f0
    ctx->r21 = (int32_t)ctx->f0.u32l;
    // 0x800551A8: beq         $v1, $zero, L_80055854
    if (ctx->r3 == 0) {
        // 0x800551AC: nop
    
            goto L_80055854;
    }
    // 0x800551AC: nop

    // 0x800551B0: lbu         $v0, 0x20($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X20);
    // 0x800551B4: bne         $v0, $zero, L_8005550C
    if (ctx->r2 != 0) {
        // 0x800551B8: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8005550C;
    }
    // 0x800551B8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800551BC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800551C0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800551C4: lw          $a0, 0x5924($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5924);
    // 0x800551C8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800551CC: jal         0x80055A1C
    // 0x800551D0: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    func_80055A1C(rdram, ctx);
        goto after_0;
    // 0x800551D0: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    after_0:
    // 0x800551D4: lbu         $v1, 0x3($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X3);
    // 0x800551D8: lui         $s6, 0x801D
    ctx->r22 = S32(0X801D << 16);
    // 0x800551DC: addiu       $s6, $s6, 0x5587
    ctx->r22 = ADD32(ctx->r22, 0X5587);
    // 0x800551E0: lb          $a0, 0x0($s6)
    ctx->r4 = MEM_B(ctx->r22, 0X0);
    // 0x800551E4: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800551E8: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800551EC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800551F0: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800551F4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800551F8: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x800551FC: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x80055200: lw          $a2, 0xB98($a2)
    ctx->r6 = MEM_W(ctx->r6, 0XB98);
    // 0x80055204: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80055208: addiu       $a1, $a1, -0x1350
    ctx->r5 = ADD32(ctx->r5, -0X1350);
    // 0x8005520C: jal         0x80066CA0
    // 0x80055210: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_1;
    // 0x80055210: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x80055214: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80055218: addiu       $s0, $s3, 0x20
    ctx->r16 = ADD32(ctx->r19, 0X20);
    // 0x8005521C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80055220: addiu       $a2, $s5, 0x8
    ctx->r6 = ADD32(ctx->r21, 0X8);
    // 0x80055224: jal         0x8004F1A4
    // 0x80055228: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_2;
    // 0x80055228: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // 0x8005522C: lb          $v1, 0x0($s6)
    ctx->r3 = MEM_B(ctx->r22, 0X0);
    // 0x80055230: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80055234: beq         $v1, $v0, L_800552D4
    if (ctx->r3 == ctx->r2) {
        // 0x80055238: slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_800552D4;
    }
    // 0x80055238: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8005523C: bne         $v0, $zero, L_80055254
    if (ctx->r2 != 0) {
        // 0x80055240: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80055254;
    }
    // 0x80055240: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80055244: beq         $v1, $v0, L_80055340
    if (ctx->r3 == ctx->r2) {
        // 0x80055248: addiu       $a1, $s3, -0x8
        ctx->r5 = ADD32(ctx->r19, -0X8);
            goto L_80055340;
    }
    // 0x80055248: addiu       $a1, $s3, -0x8
    ctx->r5 = ADD32(ctx->r19, -0X8);
    // 0x8005524C: j           L_80055468
    // 0x80055250: nop

        goto L_80055468;
    // 0x80055250: nop

L_80055254:
    // 0x80055254: bltz        $v1, L_80055468
    if (SIGNED(ctx->r3) < 0) {
        // 0x80055258: nop
    
            goto L_80055468;
    }
    // 0x80055258: nop

    // 0x8005525C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80055260: addiu       $a1, $a1, -0x139C
    ctx->r5 = ADD32(ctx->r5, -0X139C);
    // 0x80055264: jal         0x80066CA0
    // 0x80055268: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_3;
    // 0x80055268: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x8005526C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80055270: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80055274: addiu       $s0, $s5, 0x18
    ctx->r16 = ADD32(ctx->r21, 0X18);
    // 0x80055278: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8005527C: jal         0x8004F1A4
    // 0x80055280: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8004F1A4(rdram, ctx);
        goto after_4;
    // 0x80055280: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_4:
    // 0x80055284: lbu         $v1, 0x3($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X3);
    // 0x80055288: lb          $a0, 0x0($s6)
    ctx->r4 = MEM_B(ctx->r22, 0X0);
    // 0x8005528C: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80055290: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80055294: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80055298: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8005529C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800552A0: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x800552A4: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x800552A8: lbu         $a2, 0xB91($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XB91);
    // 0x800552AC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x800552B0: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x800552B4: lbu         $a3, 0xB92($a3)
    ctx->r7 = MEM_BU(ctx->r7, 0XB92);
    // 0x800552B8: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800552BC: addiu       $a1, $a1, -0x138C
    ctx->r5 = ADD32(ctx->r5, -0X138C);
    // 0x800552C0: jal         0x80066CA0
    // 0x800552C4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_5;
    // 0x800552C4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_5:
    // 0x800552C8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800552CC: j           L_8005545C
    // 0x800552D0: addiu       $a1, $s3, 0x68
    ctx->r5 = ADD32(ctx->r19, 0X68);
        goto L_8005545C;
    // 0x800552D0: addiu       $a1, $s3, 0x68
    ctx->r5 = ADD32(ctx->r19, 0X68);
L_800552D4:
    // 0x800552D4: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800552D8: addiu       $a1, $a1, -0x1394
    ctx->r5 = ADD32(ctx->r5, -0X1394);
    // 0x800552DC: jal         0x80066CA0
    // 0x800552E0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_6;
    // 0x800552E0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_6:
    // 0x800552E4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800552E8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800552EC: addiu       $s0, $s5, 0x18
    ctx->r16 = ADD32(ctx->r21, 0X18);
    // 0x800552F0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800552F4: jal         0x8004F1A4
    // 0x800552F8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8004F1A4(rdram, ctx);
        goto after_7;
    // 0x800552F8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_7:
    // 0x800552FC: lbu         $v1, 0x3($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X3);
    // 0x80055300: lb          $a0, 0x0($s6)
    ctx->r4 = MEM_B(ctx->r22, 0X0);
    // 0x80055304: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80055308: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8005530C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80055310: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80055314: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80055318: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x8005531C: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x80055320: lbu         $a2, 0xB91($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XB91);
    // 0x80055324: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80055328: addiu       $a1, $a1, -0x1370
    ctx->r5 = ADD32(ctx->r5, -0X1370);
    // 0x8005532C: jal         0x80066CA0
    // 0x80055330: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_8;
    // 0x80055330: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_8:
    // 0x80055334: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80055338: j           L_8005545C
    // 0x8005533C: addiu       $a1, $s3, 0x88
    ctx->r5 = ADD32(ctx->r19, 0X88);
        goto L_8005545C;
    // 0x8005533C: addiu       $a1, $s3, 0x88
    ctx->r5 = ADD32(ctx->r19, 0X88);
L_80055340:
    // 0x80055340: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80055344: addiu       $a0, $a0, -0x139C
    ctx->r4 = ADD32(ctx->r4, -0X139C);
    // 0x80055348: addiu       $s0, $s5, 0x18
    ctx->r16 = ADD32(ctx->r21, 0X18);
    // 0x8005534C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80055350: jal         0x8004F1A4
    // 0x80055354: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8004F1A4(rdram, ctx);
        goto after_9;
    // 0x80055354: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_9:
    // 0x80055358: lbu         $v1, 0x3($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X3);
    // 0x8005535C: lb          $a1, 0x0($s6)
    ctx->r5 = MEM_B(ctx->r22, 0X0);
    // 0x80055360: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80055364: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80055368: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8005536C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80055370: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80055374: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80055378: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x8005537C: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x80055380: lbu         $a2, 0xB90($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XB90);
    // 0x80055384: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x80055388: addiu       $s1, $s1, -0x1370
    ctx->r17 = ADD32(ctx->r17, -0X1370);
    // 0x8005538C: jal         0x80066CA0
    // 0x80055390: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80066CA0(rdram, ctx);
        goto after_10;
    // 0x80055390: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_10:
    // 0x80055394: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80055398: addiu       $a1, $s3, 0x40
    ctx->r5 = ADD32(ctx->r19, 0X40);
    // 0x8005539C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800553A0: jal         0x8004F1A4
    // 0x800553A4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_11;
    // 0x800553A4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_11:
    // 0x800553A8: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x800553AC: addiu       $s2, $s2, -0x134C
    ctx->r18 = ADD32(ctx->r18, -0X134C);
    // 0x800553B0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800553B4: addiu       $a1, $s3, 0x5C
    ctx->r5 = ADD32(ctx->r19, 0X5C);
    // 0x800553B8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800553BC: jal         0x8004F1A4
    // 0x800553C0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_12;
    // 0x800553C0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_12:
    // 0x800553C4: lbu         $v1, 0x3($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X3);
    // 0x800553C8: lb          $a0, 0x0($s6)
    ctx->r4 = MEM_B(ctx->r22, 0X0);
    // 0x800553CC: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800553D0: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800553D4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800553D8: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800553DC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800553E0: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x800553E4: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x800553E8: lbu         $a2, 0xB91($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XB91);
    // 0x800553EC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800553F0: jal         0x80066CA0
    // 0x800553F4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_13;
    // 0x800553F4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_13:
    // 0x800553F8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800553FC: addiu       $a1, $s3, 0x68
    ctx->r5 = ADD32(ctx->r19, 0X68);
    // 0x80055400: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80055404: jal         0x8004F1A4
    // 0x80055408: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_14;
    // 0x80055408: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_14:
    // 0x8005540C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80055410: addiu       $a1, $s3, 0x84
    ctx->r5 = ADD32(ctx->r19, 0X84);
    // 0x80055414: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80055418: jal         0x8004F1A4
    // 0x8005541C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_15;
    // 0x8005541C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_15:
    // 0x80055420: lbu         $v1, 0x3($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X3);
    // 0x80055424: lb          $a0, 0x0($s6)
    ctx->r4 = MEM_B(ctx->r22, 0X0);
    // 0x80055428: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x8005542C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80055430: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80055434: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80055438: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005543C: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80055440: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x80055444: lbu         $a2, 0xB92($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XB92);
    // 0x80055448: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8005544C: jal         0x80066CA0
    // 0x80055450: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_16;
    // 0x80055450: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_16:
    // 0x80055454: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80055458: addiu       $a1, $s3, 0x90
    ctx->r5 = ADD32(ctx->r19, 0X90);
L_8005545C:
    // 0x8005545C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80055460: jal         0x8004F1A4
    // 0x80055464: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_17;
    // 0x80055464: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_17:
L_80055468:
    // 0x80055468: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8005546C: addiu       $s0, $s0, 0x5587
    ctx->r16 = ADD32(ctx->r16, 0X5587);
    // 0x80055470: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x80055474: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80055478: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8005547C: addiu       $a1, $a1, -0x13A8
    ctx->r5 = ADD32(ctx->r5, -0X13A8);
    // 0x80055480: lbu         $v0, 0x3($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X3);
    // 0x80055484: sll         $a2, $v1, 2
    ctx->r6 = S32(ctx->r3 << 2);
    // 0x80055488: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x8005548C: sll         $a2, $a2, 5
    ctx->r6 = S32(ctx->r6 << 5);
    // 0x80055490: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80055494: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80055498: addiu       $v1, $v1, 0xB90
    ctx->r3 = ADD32(ctx->r3, 0XB90);
    // 0x8005549C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800554A0: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x800554A4: jal         0x80066CA0
    // 0x800554A8: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    func_80066CA0(rdram, ctx);
        goto after_18;
    // 0x800554A8: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    after_18:
    // 0x800554AC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800554B0: addiu       $a1, $s3, 0xC0
    ctx->r5 = ADD32(ctx->r19, 0XC0);
    // 0x800554B4: addiu       $a2, $s5, 0x18
    ctx->r6 = ADD32(ctx->r21, 0X18);
    // 0x800554B8: jal         0x8004F1A4
    // 0x800554BC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_19;
    // 0x800554BC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_19:
    // 0x800554C0: lbu         $v1, 0x3($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X3);
    // 0x800554C4: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
    // 0x800554C8: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800554CC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800554D0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800554D4: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800554D8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800554DC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800554E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800554E4: lbu         $v0, 0xB94($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB94);
    // 0x800554E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800554EC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800554F0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800554F4: lw          $a0, 0x594C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X594C);
    // 0x800554F8: addiu       $a1, $s3, 0xB8
    ctx->r5 = ADD32(ctx->r19, 0XB8);
    // 0x800554FC: jal         0x80055A1C
    // 0x80055500: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    func_80055A1C(rdram, ctx);
        goto after_20;
    // 0x80055500: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    after_20:
    // 0x80055504: j           L_80055854
    // 0x80055508: nop

        goto L_80055854;
    // 0x80055508: nop

L_8005550C:
    // 0x8005550C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80055510: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80055514: lw          $a0, 0x5924($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5924);
    // 0x80055518: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8005551C: jal         0x80055DC0
    // 0x80055520: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    func_80055DC0(rdram, ctx);
        goto after_21;
    // 0x80055520: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    after_21:
    // 0x80055524: lbu         $v1, 0x3($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X3);
    // 0x80055528: lui         $s6, 0x801D
    ctx->r22 = S32(0X801D << 16);
    // 0x8005552C: addiu       $s6, $s6, 0x5587
    ctx->r22 = ADD32(ctx->r22, 0X5587);
    // 0x80055530: lb          $a0, 0x0($s6)
    ctx->r4 = MEM_B(ctx->r22, 0X0);
    // 0x80055534: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80055538: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8005553C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80055540: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80055544: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80055548: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x8005554C: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x80055550: lw          $a2, 0xB98($a2)
    ctx->r6 = MEM_W(ctx->r6, 0XB98);
    // 0x80055554: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80055558: addiu       $a1, $a1, -0x1350
    ctx->r5 = ADD32(ctx->r5, -0X1350);
    // 0x8005555C: jal         0x80066CA0
    // 0x80055560: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_22;
    // 0x80055560: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_22:
    // 0x80055564: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80055568: addiu       $s0, $s3, 0x20
    ctx->r16 = ADD32(ctx->r19, 0X20);
    // 0x8005556C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80055570: addiu       $a2, $s5, 0x8
    ctx->r6 = ADD32(ctx->r21, 0X8);
    // 0x80055574: jal         0x8004F1A4
    // 0x80055578: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    func_8004F1A4(rdram, ctx);
        goto after_23;
    // 0x80055578: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_23:
    // 0x8005557C: lb          $v1, 0x0($s6)
    ctx->r3 = MEM_B(ctx->r22, 0X0);
    // 0x80055580: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80055584: beq         $v1, $v0, L_80055624
    if (ctx->r3 == ctx->r2) {
        // 0x80055588: slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_80055624;
    }
    // 0x80055588: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8005558C: bne         $v0, $zero, L_800555A4
    if (ctx->r2 != 0) {
        // 0x80055590: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800555A4;
    }
    // 0x80055590: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80055594: beq         $v1, $v0, L_80055690
    if (ctx->r3 == ctx->r2) {
        // 0x80055598: addiu       $a1, $s3, -0x8
        ctx->r5 = ADD32(ctx->r19, -0X8);
            goto L_80055690;
    }
    // 0x80055598: addiu       $a1, $s3, -0x8
    ctx->r5 = ADD32(ctx->r19, -0X8);
    // 0x8005559C: j           L_800557B8
    // 0x800555A0: nop

        goto L_800557B8;
    // 0x800555A0: nop

L_800555A4:
    // 0x800555A4: bltz        $v1, L_800557B8
    if (SIGNED(ctx->r3) < 0) {
        // 0x800555A8: nop
    
            goto L_800557B8;
    }
    // 0x800555A8: nop

    // 0x800555AC: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800555B0: addiu       $a1, $a1, -0x139C
    ctx->r5 = ADD32(ctx->r5, -0X139C);
    // 0x800555B4: jal         0x80066CA0
    // 0x800555B8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_24;
    // 0x800555B8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_24:
    // 0x800555BC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800555C0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800555C4: addiu       $s0, $s5, 0x18
    ctx->r16 = ADD32(ctx->r21, 0X18);
    // 0x800555C8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800555CC: jal         0x8004F1A4
    // 0x800555D0: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    func_8004F1A4(rdram, ctx);
        goto after_25;
    // 0x800555D0: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_25:
    // 0x800555D4: lbu         $v1, 0x3($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X3);
    // 0x800555D8: lb          $a0, 0x0($s6)
    ctx->r4 = MEM_B(ctx->r22, 0X0);
    // 0x800555DC: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800555E0: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800555E4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800555E8: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800555EC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800555F0: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x800555F4: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x800555F8: lbu         $a2, 0xB91($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XB91);
    // 0x800555FC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80055600: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x80055604: lbu         $a3, 0xB92($a3)
    ctx->r7 = MEM_BU(ctx->r7, 0XB92);
    // 0x80055608: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8005560C: addiu       $a1, $a1, -0x138C
    ctx->r5 = ADD32(ctx->r5, -0X138C);
    // 0x80055610: jal         0x80066CA0
    // 0x80055614: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_26;
    // 0x80055614: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_26:
    // 0x80055618: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8005561C: j           L_800557AC
    // 0x80055620: addiu       $a1, $s3, 0x68
    ctx->r5 = ADD32(ctx->r19, 0X68);
        goto L_800557AC;
    // 0x80055620: addiu       $a1, $s3, 0x68
    ctx->r5 = ADD32(ctx->r19, 0X68);
L_80055624:
    // 0x80055624: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80055628: addiu       $a1, $a1, -0x1394
    ctx->r5 = ADD32(ctx->r5, -0X1394);
    // 0x8005562C: jal         0x80066CA0
    // 0x80055630: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_27;
    // 0x80055630: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_27:
    // 0x80055634: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80055638: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8005563C: addiu       $s0, $s5, 0x18
    ctx->r16 = ADD32(ctx->r21, 0X18);
    // 0x80055640: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80055644: jal         0x8004F1A4
    // 0x80055648: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    func_8004F1A4(rdram, ctx);
        goto after_28;
    // 0x80055648: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_28:
    // 0x8005564C: lbu         $v1, 0x3($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X3);
    // 0x80055650: lb          $a0, 0x0($s6)
    ctx->r4 = MEM_B(ctx->r22, 0X0);
    // 0x80055654: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80055658: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8005565C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80055660: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80055664: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80055668: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x8005566C: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x80055670: lbu         $a2, 0xB91($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XB91);
    // 0x80055674: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80055678: addiu       $a1, $a1, -0x1370
    ctx->r5 = ADD32(ctx->r5, -0X1370);
    // 0x8005567C: jal         0x80066CA0
    // 0x80055680: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_29;
    // 0x80055680: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_29:
    // 0x80055684: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80055688: j           L_800557AC
    // 0x8005568C: addiu       $a1, $s3, 0x88
    ctx->r5 = ADD32(ctx->r19, 0X88);
        goto L_800557AC;
    // 0x8005568C: addiu       $a1, $s3, 0x88
    ctx->r5 = ADD32(ctx->r19, 0X88);
L_80055690:
    // 0x80055690: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80055694: addiu       $a0, $a0, -0x139C
    ctx->r4 = ADD32(ctx->r4, -0X139C);
    // 0x80055698: addiu       $s0, $s5, 0x18
    ctx->r16 = ADD32(ctx->r21, 0X18);
    // 0x8005569C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800556A0: jal         0x8004F1A4
    // 0x800556A4: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    func_8004F1A4(rdram, ctx);
        goto after_30;
    // 0x800556A4: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_30:
    // 0x800556A8: lbu         $v1, 0x3($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X3);
    // 0x800556AC: lb          $a1, 0x0($s6)
    ctx->r5 = MEM_B(ctx->r22, 0X0);
    // 0x800556B0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800556B4: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800556B8: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800556BC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800556C0: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800556C4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800556C8: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x800556CC: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x800556D0: lbu         $a2, 0xB90($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XB90);
    // 0x800556D4: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x800556D8: addiu       $s1, $s1, -0x1370
    ctx->r17 = ADD32(ctx->r17, -0X1370);
    // 0x800556DC: jal         0x80066CA0
    // 0x800556E0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80066CA0(rdram, ctx);
        goto after_31;
    // 0x800556E0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_31:
    // 0x800556E4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800556E8: addiu       $a1, $s3, 0x40
    ctx->r5 = ADD32(ctx->r19, 0X40);
    // 0x800556EC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800556F0: jal         0x8004F1A4
    // 0x800556F4: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    func_8004F1A4(rdram, ctx);
        goto after_32;
    // 0x800556F4: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_32:
    // 0x800556F8: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x800556FC: addiu       $s2, $s2, -0x134C
    ctx->r18 = ADD32(ctx->r18, -0X134C);
    // 0x80055700: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80055704: addiu       $a1, $s3, 0x5C
    ctx->r5 = ADD32(ctx->r19, 0X5C);
    // 0x80055708: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8005570C: jal         0x8004F1A4
    // 0x80055710: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    func_8004F1A4(rdram, ctx);
        goto after_33;
    // 0x80055710: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_33:
    // 0x80055714: lbu         $v1, 0x3($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X3);
    // 0x80055718: lb          $a0, 0x0($s6)
    ctx->r4 = MEM_B(ctx->r22, 0X0);
    // 0x8005571C: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80055720: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80055724: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80055728: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8005572C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80055730: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80055734: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x80055738: lbu         $a2, 0xB91($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XB91);
    // 0x8005573C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80055740: jal         0x80066CA0
    // 0x80055744: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_34;
    // 0x80055744: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_34:
    // 0x80055748: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8005574C: addiu       $a1, $s3, 0x68
    ctx->r5 = ADD32(ctx->r19, 0X68);
    // 0x80055750: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80055754: jal         0x8004F1A4
    // 0x80055758: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    func_8004F1A4(rdram, ctx);
        goto after_35;
    // 0x80055758: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_35:
    // 0x8005575C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80055760: addiu       $a1, $s3, 0x84
    ctx->r5 = ADD32(ctx->r19, 0X84);
    // 0x80055764: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80055768: jal         0x8004F1A4
    // 0x8005576C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    func_8004F1A4(rdram, ctx);
        goto after_36;
    // 0x8005576C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_36:
    // 0x80055770: lbu         $v1, 0x3($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X3);
    // 0x80055774: lb          $a0, 0x0($s6)
    ctx->r4 = MEM_B(ctx->r22, 0X0);
    // 0x80055778: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x8005577C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80055780: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80055784: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80055788: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005578C: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80055790: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x80055794: lbu         $a2, 0xB92($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XB92);
    // 0x80055798: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8005579C: jal         0x80066CA0
    // 0x800557A0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_37;
    // 0x800557A0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_37:
    // 0x800557A4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800557A8: addiu       $a1, $s3, 0x90
    ctx->r5 = ADD32(ctx->r19, 0X90);
L_800557AC:
    // 0x800557AC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800557B0: jal         0x8004F1A4
    // 0x800557B4: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    func_8004F1A4(rdram, ctx);
        goto after_38;
    // 0x800557B4: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_38:
L_800557B8:
    // 0x800557B8: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x800557BC: addiu       $s0, $s0, 0x5587
    ctx->r16 = ADD32(ctx->r16, 0X5587);
    // 0x800557C0: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x800557C4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800557C8: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800557CC: addiu       $a1, $a1, -0x13A8
    ctx->r5 = ADD32(ctx->r5, -0X13A8);
    // 0x800557D0: lbu         $v0, 0x3($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X3);
    // 0x800557D4: sll         $a2, $v1, 2
    ctx->r6 = S32(ctx->r3 << 2);
    // 0x800557D8: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x800557DC: sll         $a2, $a2, 5
    ctx->r6 = S32(ctx->r6 << 5);
    // 0x800557E0: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800557E4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800557E8: addiu       $v1, $v1, 0xB90
    ctx->r3 = ADD32(ctx->r3, 0XB90);
    // 0x800557EC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800557F0: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x800557F4: jal         0x80066CA0
    // 0x800557F8: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    func_80066CA0(rdram, ctx);
        goto after_39;
    // 0x800557F8: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    after_39:
    // 0x800557FC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80055800: addiu       $a1, $s3, 0xC0
    ctx->r5 = ADD32(ctx->r19, 0XC0);
    // 0x80055804: addiu       $a2, $s5, 0x18
    ctx->r6 = ADD32(ctx->r21, 0X18);
    // 0x80055808: jal         0x8004F1A4
    // 0x8005580C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    func_8004F1A4(rdram, ctx);
        goto after_40;
    // 0x8005580C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_40:
    // 0x80055810: lbu         $v1, 0x3($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X3);
    // 0x80055814: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
    // 0x80055818: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x8005581C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80055820: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80055824: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80055828: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005582C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80055830: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80055834: lbu         $v0, 0xB94($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB94);
    // 0x80055838: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005583C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80055840: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80055844: lw          $a0, 0x594C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X594C);
    // 0x80055848: addiu       $a1, $s3, 0xB8
    ctx->r5 = ADD32(ctx->r19, 0XB8);
    // 0x8005584C: jal         0x80055DC0
    // 0x80055850: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    func_80055DC0(rdram, ctx);
        goto after_41;
    // 0x80055850: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    after_41:
L_80055854:
    // 0x80055854: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80055858: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8005585C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80055860: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80055864: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80055868: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8005586C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80055870: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80055874: jr          $ra
    // 0x80055878: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80055878: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8005587C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005587C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80055880: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80055884: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x80055888: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8005588C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80055890: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80055894: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80055898: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8005589C: lb          $v1, 0x5587($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X5587);
    // 0x800558A0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800558A4: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800558A8: addiu       $a1, $a1, -0x1350
    ctx->r5 = ADD32(ctx->r5, -0X1350);
    // 0x800558AC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800558B0: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x800558B4: addiu       $s3, $s3, 0x5958
    ctx->r19 = ADD32(ctx->r19, 0X5958);
    // 0x800558B8: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x800558BC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800558C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800558C4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800558C8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800558CC: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800558D0: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x800558D4: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x800558D8: lw          $a2, 0xB98($a2)
    ctx->r6 = MEM_W(ctx->r6, 0XB98);
    // 0x800558DC: addiu       $s0, $sp, 0x10
    ctx->r16 = ADD32(ctx->r29, 0X10);
    // 0x800558E0: jal         0x80066CA0
    // 0x800558E4: addiu       $s4, $sp, 0x19
    ctx->r20 = ADD32(ctx->r29, 0X19);
    func_80066CA0(rdram, ctx);
        goto after_0;
    // 0x800558E4: addiu       $s4, $sp, 0x19
    ctx->r20 = ADD32(ctx->r29, 0X19);
    after_0:
L_800558E8:
    // 0x800558E8: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800558EC: addiu       $v1, $v1, -0x30
    ctx->r3 = ADD32(ctx->r3, -0X30);
    // 0x800558F0: sltiu       $v0, $v1, 0xA
    ctx->r2 = ctx->r3 < 0XA ? 1 : 0;
    // 0x800558F4: beql        $v0, $zero, L_8005593C
    if (ctx->r2 == 0) {
        // 0x800558F8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8005593C;
    }
    goto skip_0;
    // 0x800558F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800558FC: lbu         $v0, 0x20($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X20);
    // 0x80055900: bne         $v0, $zero, L_80055924
    if (ctx->r2 != 0) {
        // 0x80055904: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80055924;
    }
    // 0x80055904: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80055908: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x8005590C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80055910: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80055914: jal         0x80055A1C
    // 0x80055918: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80055A1C(rdram, ctx);
        goto after_1;
    // 0x80055918: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_1:
    // 0x8005591C: j           L_8005593C
    // 0x80055920: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8005593C;
    // 0x80055920: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80055924:
    // 0x80055924: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80055928: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8005592C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80055930: jal         0x80055DC0
    // 0x80055934: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80055DC0(rdram, ctx);
        goto after_2;
    // 0x80055934: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_2:
    // 0x80055938: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8005593C:
    // 0x8005593C: slt         $v0, $s0, $s4
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80055940: bne         $v0, $zero, L_800558E8
    if (ctx->r2 != 0) {
        // 0x80055944: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_800558E8;
    }
    // 0x80055944: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80055948: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x8005594C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80055950: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80055954: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80055958: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8005595C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80055960: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80055964: jr          $ra
    // 0x80055968: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80055968: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8005596C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005596C: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80055970: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x80055974: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x80055978: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // 0x8005597C: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    // 0x80055980: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
    // 0x80055984: sb          $zero, 0x6($a0)
    MEM_B(0X6, ctx->r4) = 0;
    // 0x80055988: jr          $ra
    // 0x8005598C: sb          $zero, 0x7($a0)
    MEM_B(0X7, ctx->r4) = 0;
    return;
    // 0x8005598C: sb          $zero, 0x7($a0)
    MEM_B(0X7, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80055990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055990: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80055994: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80055998: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8005599C: addiu       $s0, $s0, 0x5587
    ctx->r16 = ADD32(ctx->r16, 0X5587);
    // 0x800559A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800559A4: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x800559A8: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800559AC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800559B0: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800559B4: lw          $a0, 0x5BEC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5BEC);
    // 0x800559B8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800559BC: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800559C0: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800559C4: lw          $a1, 0x5BC4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5BC4);
    // 0x800559C8: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x800559CC: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x800559D0: lw          $a2, 0x5BC8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5BC8);
    // 0x800559D4: jal         0x8004F1A4
    // 0x800559D8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8004F1A4(rdram, ctx);
        goto after_0;
    // 0x800559D8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_0:
    // 0x800559DC: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x800559E0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800559E4: bne         $v1, $v0, L_80055A0C
    if (ctx->r3 != ctx->r2) {
        // 0x800559E8: nop
    
            goto L_80055A0C;
    }
    // 0x800559E8: nop

    // 0x800559EC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800559F0: lw          $a0, 0x5BFC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5BFC);
    // 0x800559F4: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800559F8: lw          $a1, 0x5BE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5BE4);
    // 0x800559FC: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x80055A00: lw          $a2, 0x5BE8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5BE8);
    // 0x80055A04: jal         0x8004F1A4
    // 0x80055A08: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8004F1A4(rdram, ctx);
        goto after_1;
    // 0x80055A08: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_1:
L_80055A0C:
    // 0x80055A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80055A10: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80055A14: jr          $ra
    // 0x80055A18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80055A18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80055A1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055A1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80055A20: addu        $t7, $a0, $zero
    ctx->r15 = ADD32(ctx->r4, 0);
    // 0x80055A24: addu        $t9, $a1, $zero
    ctx->r25 = ADD32(ctx->r5, 0);
    // 0x80055A28: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80055A2C: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x80055A30: sll         $v0, $t7, 1
    ctx->r2 = S32(ctx->r15 << 1);
    // 0x80055A34: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80055A38: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80055A3C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80055A40: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80055A44: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80055A48: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80055A4C: lw          $t6, 0x57D4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X57D4);
    // 0x80055A50: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80055A54: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x80055A58: lw          $t8, 0x57D8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X57D8);
    // 0x80055A5C: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x80055A60: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x80055A64: lw          $s1, 0x57DC($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X57DC);
    // 0x80055A68: slti        $v0, $t9, 0x140
    ctx->r2 = SIGNED(ctx->r25) < 0X140 ? 1 : 0;
    // 0x80055A6C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80055A70: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x80055A74: slti        $a0, $a0, 0x1
    ctx->r4 = SIGNED(ctx->r4) < 0X1 ? 1 : 0;
    // 0x80055A78: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80055A7C: addu        $v1, $s0, $t8
    ctx->r3 = ADD32(ctx->r16, ctx->r24);
    // 0x80055A80: slti        $v1, $v1, 0x1
    ctx->r3 = SIGNED(ctx->r3) < 0X1 ? 1 : 0;
    // 0x80055A84: slti        $v0, $s0, 0xF0
    ctx->r2 = SIGNED(ctx->r16) < 0XF0 ? 1 : 0;
    // 0x80055A88: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80055A8C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80055A90: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x80055A94: bne         $a0, $zero, L_80055DAC
    if (ctx->r4 != 0) {
        // 0x80055A98: lui         $v1, 0xBA00
        ctx->r3 = S32(0XBA00 << 16);
            goto L_80055DAC;
    }
    // 0x80055A98: lui         $v1, 0xBA00
    ctx->r3 = S32(0XBA00 << 16);
    // 0x80055A9C: ori         $v1, $v1, 0x1402
    ctx->r3 = ctx->r3 | 0X1402;
    // 0x80055AA0: lui         $a1, 0xFCFF
    ctx->r5 = S32(0XFCFF << 16);
    // 0x80055AA4: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80055AA8: lui         $a0, 0xFFFC
    ctx->r4 = S32(0XFFFC << 16);
    // 0x80055AAC: ori         $a0, $a0, 0xF279
    ctx->r4 = ctx->r4 | 0XF279;
    // 0x80055AB0: lui         $a2, 0xBA00
    ctx->r6 = S32(0XBA00 << 16);
    // 0x80055AB4: ori         $a2, $a2, 0x1301
    ctx->r6 = ctx->r6 | 0X1301;
    // 0x80055AB8: lui         $t0, 0xB900
    ctx->r8 = S32(0XB900 << 16);
    // 0x80055ABC: ori         $t0, $t0, 0x31D
    ctx->r8 = ctx->r8 | 0X31D;
    // 0x80055AC0: lui         $a3, 0xF0A
    ctx->r7 = S32(0XF0A << 16);
    // 0x80055AC4: ori         $a3, $a3, 0x7008
    ctx->r7 = ctx->r7 | 0X7008;
    // 0x80055AC8: lui         $t1, 0xBA00
    ctx->r9 = S32(0XBA00 << 16);
    // 0x80055ACC: ori         $t1, $t1, 0xE02
    ctx->r9 = ctx->r9 | 0XE02;
    // 0x80055AD0: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x80055AD4: ori         $t3, $t3, 0x100
    ctx->r11 = ctx->r11 | 0X100;
    // 0x80055AD8: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80055ADC: lw          $t5, 0x2FE4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2FE4);
    // 0x80055AE0: lui         $t4, 0x703
    ctx->r12 = S32(0X703 << 16);
    // 0x80055AE4: ori         $t4, $t4, 0xC000
    ctx->r12 = ctx->r12 | 0XC000;
    // 0x80055AE8: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x80055AEC: addiu       $v0, $t5, 0x8
    ctx->r2 = ADD32(ctx->r13, 0X8);
    // 0x80055AF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055AF4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055AF8: addiu       $v0, $t5, 0x10
    ctx->r2 = ADD32(ctx->r13, 0X10);
    // 0x80055AFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055B00: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055B04: addiu       $v0, $t5, 0x18
    ctx->r2 = ADD32(ctx->r13, 0X18);
    // 0x80055B08: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055B0C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055B10: addiu       $v0, $t5, 0x20
    ctx->r2 = ADD32(ctx->r13, 0X20);
    // 0x80055B14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055B18: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055B1C: addiu       $v0, $t5, 0x28
    ctx->r2 = ADD32(ctx->r13, 0X28);
    // 0x80055B20: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055B24: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055B28: addiu       $v0, $t5, 0x30
    ctx->r2 = ADD32(ctx->r13, 0X30);
    // 0x80055B2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055B30: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055B34: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80055B38: sw          $v0, 0x2C($t5)
    MEM_W(0X2C, ctx->r13) = ctx->r2;
    // 0x80055B3C: addiu       $v0, $t5, 0x38
    ctx->r2 = ADD32(ctx->r13, 0X38);
    // 0x80055B40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055B44: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055B48: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x80055B4C: sw          $v0, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r2;
    // 0x80055B50: sll         $v0, $s1, 5
    ctx->r2 = S32(ctx->r17 << 5);
    // 0x80055B54: sw          $v1, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r3;
    // 0x80055B58: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80055B5C: addiu       $v1, $v1, 0x5980
    ctx->r3 = ADD32(ctx->r3, 0X5980);
    // 0x80055B60: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80055B64: sw          $v0, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r2;
    // 0x80055B68: addiu       $v0, $t5, 0x40
    ctx->r2 = ADD32(ctx->r13, 0X40);
    // 0x80055B6C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055B70: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055B74: lui         $v0, 0xE800
    ctx->r2 = S32(0XE800 << 16);
    // 0x80055B78: sw          $v0, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->r2;
    // 0x80055B7C: addiu       $v0, $t5, 0x48
    ctx->r2 = ADD32(ctx->r13, 0X48);
    // 0x80055B80: sw          $a2, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r6;
    // 0x80055B84: lui         $a2, 0x700
    ctx->r6 = S32(0X700 << 16);
    // 0x80055B88: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055B8C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055B90: addiu       $v0, $t5, 0x50
    ctx->r2 = ADD32(ctx->r13, 0X50);
    // 0x80055B94: sw          $a0, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r4;
    // 0x80055B98: lui         $a0, 0xE600
    ctx->r4 = S32(0XE600 << 16);
    // 0x80055B9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055BA0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055BA4: addiu       $v0, $t5, 0x58
    ctx->r2 = ADD32(ctx->r13, 0X58);
    // 0x80055BA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055BAC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055BB0: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x80055BB4: sw          $v0, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->r2;
    // 0x80055BB8: lui         $v0, 0xFD50
    ctx->r2 = S32(0XFD50 << 16);
    // 0x80055BBC: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x80055BC0: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80055BC4: sw          $zero, 0xC($t5)
    MEM_W(0XC, ctx->r13) = 0;
    // 0x80055BC8: sw          $a1, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r5;
    // 0x80055BCC: sw          $zero, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = 0;
    // 0x80055BD0: sw          $t0, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->r8;
    // 0x80055BD4: sw          $a3, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->r7;
    // 0x80055BD8: sw          $t1, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->r9;
    // 0x80055BDC: sw          $zero, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = 0;
    // 0x80055BE0: sw          $t3, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->r11;
    // 0x80055BE4: sw          $a2, 0x44($t5)
    MEM_W(0X44, ctx->r13) = ctx->r6;
    // 0x80055BE8: sw          $a0, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->r4;
    // 0x80055BEC: sw          $zero, 0x4C($t5)
    MEM_W(0X4C, ctx->r13) = 0;
    // 0x80055BF0: sw          $t4, 0x54($t5)
    MEM_W(0X54, ctx->r13) = ctx->r12;
    // 0x80055BF4: sw          $v0, 0x60($t5)
    MEM_W(0X60, ctx->r13) = ctx->r2;
    // 0x80055BF8: sll         $v0, $t7, 2
    ctx->r2 = S32(ctx->r15 << 2);
    // 0x80055BFC: sw          $t2, 0x58($t5)
    MEM_W(0X58, ctx->r13) = ctx->r10;
    // 0x80055C00: sw          $zero, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = 0;
    // 0x80055C04: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80055C08: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80055C0C: lw          $v1, 0x56F0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X56F0);
    // 0x80055C10: addu        $a1, $t6, $zero
    ctx->r5 = ADD32(ctx->r14, 0);
    // 0x80055C14: addiu       $v0, $t5, 0x60
    ctx->r2 = ADD32(ctx->r13, 0X60);
    // 0x80055C18: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055C1C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055C20: addiu       $v0, $t5, 0x68
    ctx->r2 = ADD32(ctx->r13, 0X68);
    // 0x80055C24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055C28: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055C2C: addiu       $v0, $t5, 0x70
    ctx->r2 = ADD32(ctx->r13, 0X70);
    // 0x80055C30: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055C34: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055C38: lui         $v0, 0xF550
    ctx->r2 = S32(0XF550 << 16);
    // 0x80055C3C: sw          $v0, 0x68($t5)
    MEM_W(0X68, ctx->r13) = ctx->r2;
    // 0x80055C40: addiu       $v0, $t5, 0x78
    ctx->r2 = ADD32(ctx->r13, 0X78);
    // 0x80055C44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055C48: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055C4C: addiu       $v0, $t5, 0x80
    ctx->r2 = ADD32(ctx->r13, 0X80);
    // 0x80055C50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055C54: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055C58: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x80055C5C: sw          $v0, 0x78($t5)
    MEM_W(0X78, ctx->r13) = ctx->r2;
    // 0x80055C60: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80055C64: addiu       $v0, $v0, 0x3A40
    ctx->r2 = ADD32(ctx->r2, 0X3A40);
    // 0x80055C68: sw          $a2, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = ctx->r6;
    // 0x80055C6C: sw          $a0, 0x70($t5)
    MEM_W(0X70, ctx->r13) = ctx->r4;
    // 0x80055C70: sw          $zero, 0x74($t5)
    MEM_W(0X74, ctx->r13) = 0;
    // 0x80055C74: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80055C78: bgez        $t6, L_80055C84
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80055C7C: sw          $v1, 0x64($t5)
        MEM_W(0X64, ctx->r13) = ctx->r3;
            goto L_80055C84;
    }
    // 0x80055C7C: sw          $v1, 0x64($t5)
    MEM_W(0X64, ctx->r13) = ctx->r3;
    // 0x80055C80: addiu       $a1, $t6, 0xF
    ctx->r5 = ADD32(ctx->r14, 0XF);
L_80055C84:
    // 0x80055C84: sra         $a1, $a1, 4
    ctx->r5 = S32(SIGNED(ctx->r5) >> 4);
    // 0x80055C88: blez        $a1, L_80055C94
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80055C8C: addiu       $v1, $zero, 0x800
        ctx->r3 = ADD32(0, 0X800);
            goto L_80055C94;
    }
    // 0x80055C8C: addiu       $v1, $zero, 0x800
    ctx->r3 = ADD32(0, 0X800);
    // 0x80055C90: addiu       $v1, $a1, 0x7FF
    ctx->r3 = ADD32(ctx->r5, 0X7FF);
L_80055C94:
    // 0x80055C94: nop

    // 0x80055C98: mult        $t6, $t8
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80055C9C: mflo        $v0
    ctx->r2 = lo;
    // 0x80055CA0: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x80055CA4: sra         $v0, $v0, 2
    ctx->r2 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80055CA8: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x80055CAC: slti        $v0, $a0, 0x800
    ctx->r2 = SIGNED(ctx->r4) < 0X800 ? 1 : 0;
    // 0x80055CB0: beql        $v0, $zero, L_80055CB8
    if (ctx->r2 == 0) {
        // 0x80055CB4: addiu       $a0, $zero, 0x7FF
        ctx->r4 = ADD32(0, 0X7FF);
            goto L_80055CB8;
    }
    goto skip_0;
    // 0x80055CB4: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    skip_0:
L_80055CB8:
    // 0x80055CB8: andi        $v0, $a0, 0xFFF
    ctx->r2 = ctx->r4 & 0XFFF;
    // 0x80055CBC: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x80055CC0: blez        $a1, L_80055D04
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80055CC4: or          $a0, $v0, $a2
        ctx->r4 = ctx->r2 | ctx->r6;
            goto L_80055D04;
    }
    // 0x80055CC4: or          $a0, $v0, $a2
    ctx->r4 = ctx->r2 | ctx->r6;
    // 0x80055CC8: div         $zero, $v1, $a1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r5)));
    // 0x80055CCC: bne         $a1, $zero, L_80055CD8
    if (ctx->r5 != 0) {
        // 0x80055CD0: nop
    
            goto L_80055CD8;
    }
    // 0x80055CD0: nop

    // 0x80055CD4: break       7
    do_break(2147835092);
L_80055CD8:
    // 0x80055CD8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80055CDC: bne         $a1, $at, L_80055CF0
    if (ctx->r5 != ctx->r1) {
        // 0x80055CE0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80055CF0;
    }
    // 0x80055CE0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80055CE4: bne         $v1, $at, L_80055CF0
    if (ctx->r3 != ctx->r1) {
        // 0x80055CE8: nop
    
            goto L_80055CF0;
    }
    // 0x80055CE8: nop

    // 0x80055CEC: break       6
    do_break(2147835116);
L_80055CF0:
    // 0x80055CF0: mflo        $v0
    ctx->r2 = lo;
    // 0x80055CF4: nop

    // 0x80055CF8: nop

    // 0x80055CFC: j           L_80055D08
    // 0x80055D00: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
        goto L_80055D08;
    // 0x80055D00: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
L_80055D04:
    // 0x80055D04: andi        $v0, $v1, 0xFFF
    ctx->r2 = ctx->r3 & 0XFFF;
L_80055D08:
    // 0x80055D08: or          $v0, $a0, $v0
    ctx->r2 = ctx->r4 | ctx->r2;
    // 0x80055D0C: sw          $v0, 0x7C($t5)
    MEM_W(0X7C, ctx->r13) = ctx->r2;
    // 0x80055D10: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80055D14: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x80055D18: lui         $v1, 0xF540
    ctx->r3 = S32(0XF540 << 16);
    // 0x80055D1C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80055D20: addu        $a2, $t6, $zero
    ctx->r6 = ADD32(ctx->r14, 0);
    // 0x80055D24: addu        $a3, $t8, $zero
    ctx->r7 = ADD32(ctx->r24, 0);
    // 0x80055D28: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80055D2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055D30: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055D34: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x80055D38: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80055D3C: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x80055D40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055D44: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055D48: sra         $v0, $t6, 1
    ctx->r2 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80055D4C: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x80055D50: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80055D54: andi        $v0, $v0, 0x1FF
    ctx->r2 = ctx->r2 & 0X1FF;
    // 0x80055D58: sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2 << 9);
    // 0x80055D5C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80055D60: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x80055D64: addiu       $v0, $a0, 0x18
    ctx->r2 = ADD32(ctx->r4, 0X18);
    // 0x80055D68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055D6C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055D70: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x80055D74: addiu       $v1, $t6, -0x1
    ctx->r3 = ADD32(ctx->r14, -0X1);
    // 0x80055D78: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80055D7C: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80055D80: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x80055D84: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x80055D88: addiu       $v0, $t8, -0x1
    ctx->r2 = ADD32(ctx->r24, -0X1);
    // 0x80055D8C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80055D90: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80055D94: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80055D98: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80055D9C: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80055DA0: sw          $v1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r3;
    // 0x80055DA4: jal         0x80056148
    // 0x80055DA8: addu        $a0, $t9, $zero
    ctx->r4 = ADD32(ctx->r25, 0);
    func_80056148(rdram, ctx);
        goto after_0;
    // 0x80055DA8: addu        $a0, $t9, $zero
    ctx->r4 = ADD32(ctx->r25, 0);
    after_0:
L_80055DAC:
    // 0x80055DAC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80055DB0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80055DB4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80055DB8: jr          $ra
    // 0x80055DBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80055DBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80055DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055DC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80055DC4: addu        $t7, $a0, $zero
    ctx->r15 = ADD32(ctx->r4, 0);
    // 0x80055DC8: addu        $t9, $a1, $zero
    ctx->r25 = ADD32(ctx->r5, 0);
    // 0x80055DCC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80055DD0: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x80055DD4: sll         $v0, $t7, 1
    ctx->r2 = S32(ctx->r15 << 1);
    // 0x80055DD8: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80055DDC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80055DE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80055DE4: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80055DE8: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80055DEC: lw          $t6, 0x57D4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X57D4);
    // 0x80055DF0: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80055DF4: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x80055DF8: lw          $t8, 0x57D8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X57D8);
    // 0x80055DFC: slti        $v0, $t9, 0x140
    ctx->r2 = SIGNED(ctx->r25) < 0X140 ? 1 : 0;
    // 0x80055E00: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80055E04: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x80055E08: slti        $a0, $a0, 0x1
    ctx->r4 = SIGNED(ctx->r4) < 0X1 ? 1 : 0;
    // 0x80055E0C: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80055E10: addu        $v1, $s0, $t8
    ctx->r3 = ADD32(ctx->r16, ctx->r24);
    // 0x80055E14: slti        $v1, $v1, 0x1
    ctx->r3 = SIGNED(ctx->r3) < 0X1 ? 1 : 0;
    // 0x80055E18: slti        $v0, $s0, 0xF0
    ctx->r2 = SIGNED(ctx->r16) < 0XF0 ? 1 : 0;
    // 0x80055E1C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80055E20: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80055E24: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x80055E28: bne         $a0, $zero, L_80056138
    if (ctx->r4 != 0) {
        // 0x80055E2C: lui         $v1, 0xBA00
        ctx->r3 = S32(0XBA00 << 16);
            goto L_80056138;
    }
    // 0x80055E2C: lui         $v1, 0xBA00
    ctx->r3 = S32(0XBA00 << 16);
    // 0x80055E30: ori         $v1, $v1, 0x1402
    ctx->r3 = ctx->r3 | 0X1402;
    // 0x80055E34: lui         $a1, 0xFCFF
    ctx->r5 = S32(0XFCFF << 16);
    // 0x80055E38: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80055E3C: lui         $a0, 0xFFFC
    ctx->r4 = S32(0XFFFC << 16);
    // 0x80055E40: ori         $a0, $a0, 0xF279
    ctx->r4 = ctx->r4 | 0XF279;
    // 0x80055E44: lui         $a2, 0xBA00
    ctx->r6 = S32(0XBA00 << 16);
    // 0x80055E48: ori         $a2, $a2, 0x1301
    ctx->r6 = ctx->r6 | 0X1301;
    // 0x80055E4C: lui         $t0, 0xB900
    ctx->r8 = S32(0XB900 << 16);
    // 0x80055E50: ori         $t0, $t0, 0x31D
    ctx->r8 = ctx->r8 | 0X31D;
    // 0x80055E54: lui         $a3, 0xF0A
    ctx->r7 = S32(0XF0A << 16);
    // 0x80055E58: ori         $a3, $a3, 0x7008
    ctx->r7 = ctx->r7 | 0X7008;
    // 0x80055E5C: lui         $t1, 0xBA00
    ctx->r9 = S32(0XBA00 << 16);
    // 0x80055E60: ori         $t1, $t1, 0xE02
    ctx->r9 = ctx->r9 | 0XE02;
    // 0x80055E64: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x80055E68: ori         $t3, $t3, 0x100
    ctx->r11 = ctx->r11 | 0X100;
    // 0x80055E6C: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80055E70: lw          $t5, 0x2FE4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2FE4);
    // 0x80055E74: lui         $t4, 0x703
    ctx->r12 = S32(0X703 << 16);
    // 0x80055E78: ori         $t4, $t4, 0xC000
    ctx->r12 = ctx->r12 | 0XC000;
    // 0x80055E7C: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x80055E80: addiu       $v0, $t5, 0x8
    ctx->r2 = ADD32(ctx->r13, 0X8);
    // 0x80055E84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055E88: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055E8C: addiu       $v0, $t5, 0x10
    ctx->r2 = ADD32(ctx->r13, 0X10);
    // 0x80055E90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055E94: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055E98: addiu       $v0, $t5, 0x18
    ctx->r2 = ADD32(ctx->r13, 0X18);
    // 0x80055E9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055EA0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055EA4: addiu       $v0, $t5, 0x20
    ctx->r2 = ADD32(ctx->r13, 0X20);
    // 0x80055EA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055EAC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055EB0: addiu       $v0, $t5, 0x28
    ctx->r2 = ADD32(ctx->r13, 0X28);
    // 0x80055EB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055EB8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055EBC: addiu       $v0, $t5, 0x30
    ctx->r2 = ADD32(ctx->r13, 0X30);
    // 0x80055EC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055EC4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055EC8: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80055ECC: sw          $v0, 0x2C($t5)
    MEM_W(0X2C, ctx->r13) = ctx->r2;
    // 0x80055ED0: addiu       $v0, $t5, 0x38
    ctx->r2 = ADD32(ctx->r13, 0X38);
    // 0x80055ED4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055ED8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055EDC: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x80055EE0: sw          $v0, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r2;
    // 0x80055EE4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80055EE8: addiu       $v0, $v0, 0x5A40
    ctx->r2 = ADD32(ctx->r2, 0X5A40);
    // 0x80055EEC: sw          $v0, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r2;
    // 0x80055EF0: addiu       $v0, $t5, 0x40
    ctx->r2 = ADD32(ctx->r13, 0X40);
    // 0x80055EF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055EF8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055EFC: lui         $v0, 0xE800
    ctx->r2 = S32(0XE800 << 16);
    // 0x80055F00: sw          $v0, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->r2;
    // 0x80055F04: addiu       $v0, $t5, 0x48
    ctx->r2 = ADD32(ctx->r13, 0X48);
    // 0x80055F08: sw          $a2, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r6;
    // 0x80055F0C: lui         $a2, 0x700
    ctx->r6 = S32(0X700 << 16);
    // 0x80055F10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055F14: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055F18: addiu       $v0, $t5, 0x50
    ctx->r2 = ADD32(ctx->r13, 0X50);
    // 0x80055F1C: sw          $a0, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r4;
    // 0x80055F20: lui         $a0, 0xE600
    ctx->r4 = S32(0XE600 << 16);
    // 0x80055F24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055F28: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055F2C: addiu       $v0, $t5, 0x58
    ctx->r2 = ADD32(ctx->r13, 0X58);
    // 0x80055F30: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055F34: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055F38: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x80055F3C: sw          $v0, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->r2;
    // 0x80055F40: lui         $v0, 0xFD50
    ctx->r2 = S32(0XFD50 << 16);
    // 0x80055F44: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x80055F48: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80055F4C: sw          $v1, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r3;
    // 0x80055F50: sw          $zero, 0xC($t5)
    MEM_W(0XC, ctx->r13) = 0;
    // 0x80055F54: sw          $a1, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r5;
    // 0x80055F58: sw          $zero, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = 0;
    // 0x80055F5C: sw          $t0, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->r8;
    // 0x80055F60: sw          $a3, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->r7;
    // 0x80055F64: sw          $t1, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->r9;
    // 0x80055F68: sw          $zero, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = 0;
    // 0x80055F6C: sw          $t3, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->r11;
    // 0x80055F70: sw          $a2, 0x44($t5)
    MEM_W(0X44, ctx->r13) = ctx->r6;
    // 0x80055F74: sw          $a0, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->r4;
    // 0x80055F78: sw          $zero, 0x4C($t5)
    MEM_W(0X4C, ctx->r13) = 0;
    // 0x80055F7C: sw          $t4, 0x54($t5)
    MEM_W(0X54, ctx->r13) = ctx->r12;
    // 0x80055F80: sw          $v0, 0x60($t5)
    MEM_W(0X60, ctx->r13) = ctx->r2;
    // 0x80055F84: sll         $v0, $t7, 2
    ctx->r2 = S32(ctx->r15 << 2);
    // 0x80055F88: sw          $t2, 0x58($t5)
    MEM_W(0X58, ctx->r13) = ctx->r10;
    // 0x80055F8C: sw          $zero, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = 0;
    // 0x80055F90: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80055F94: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80055F98: lw          $v1, 0x56F0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X56F0);
    // 0x80055F9C: addu        $a1, $t6, $zero
    ctx->r5 = ADD32(ctx->r14, 0);
    // 0x80055FA0: addiu       $v0, $t5, 0x60
    ctx->r2 = ADD32(ctx->r13, 0X60);
    // 0x80055FA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055FA8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055FAC: addiu       $v0, $t5, 0x68
    ctx->r2 = ADD32(ctx->r13, 0X68);
    // 0x80055FB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055FB4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055FB8: addiu       $v0, $t5, 0x70
    ctx->r2 = ADD32(ctx->r13, 0X70);
    // 0x80055FBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055FC0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055FC4: lui         $v0, 0xF550
    ctx->r2 = S32(0XF550 << 16);
    // 0x80055FC8: sw          $v0, 0x68($t5)
    MEM_W(0X68, ctx->r13) = ctx->r2;
    // 0x80055FCC: addiu       $v0, $t5, 0x78
    ctx->r2 = ADD32(ctx->r13, 0X78);
    // 0x80055FD0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055FD4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055FD8: addiu       $v0, $t5, 0x80
    ctx->r2 = ADD32(ctx->r13, 0X80);
    // 0x80055FDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055FE0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80055FE4: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x80055FE8: sw          $v0, 0x78($t5)
    MEM_W(0X78, ctx->r13) = ctx->r2;
    // 0x80055FEC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80055FF0: addiu       $v0, $v0, 0x3A40
    ctx->r2 = ADD32(ctx->r2, 0X3A40);
    // 0x80055FF4: sw          $a2, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = ctx->r6;
    // 0x80055FF8: sw          $a0, 0x70($t5)
    MEM_W(0X70, ctx->r13) = ctx->r4;
    // 0x80055FFC: sw          $zero, 0x74($t5)
    MEM_W(0X74, ctx->r13) = 0;
    // 0x80056000: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80056004: bgez        $t6, L_80056010
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80056008: sw          $v1, 0x64($t5)
        MEM_W(0X64, ctx->r13) = ctx->r3;
            goto L_80056010;
    }
    // 0x80056008: sw          $v1, 0x64($t5)
    MEM_W(0X64, ctx->r13) = ctx->r3;
    // 0x8005600C: addiu       $a1, $t6, 0xF
    ctx->r5 = ADD32(ctx->r14, 0XF);
L_80056010:
    // 0x80056010: sra         $a1, $a1, 4
    ctx->r5 = S32(SIGNED(ctx->r5) >> 4);
    // 0x80056014: blez        $a1, L_80056020
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80056018: addiu       $v1, $zero, 0x800
        ctx->r3 = ADD32(0, 0X800);
            goto L_80056020;
    }
    // 0x80056018: addiu       $v1, $zero, 0x800
    ctx->r3 = ADD32(0, 0X800);
    // 0x8005601C: addiu       $v1, $a1, 0x7FF
    ctx->r3 = ADD32(ctx->r5, 0X7FF);
L_80056020:
    // 0x80056020: nop

    // 0x80056024: mult        $t6, $t8
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80056028: mflo        $v0
    ctx->r2 = lo;
    // 0x8005602C: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x80056030: sra         $v0, $v0, 2
    ctx->r2 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80056034: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x80056038: slti        $v0, $a0, 0x800
    ctx->r2 = SIGNED(ctx->r4) < 0X800 ? 1 : 0;
    // 0x8005603C: beql        $v0, $zero, L_80056044
    if (ctx->r2 == 0) {
        // 0x80056040: addiu       $a0, $zero, 0x7FF
        ctx->r4 = ADD32(0, 0X7FF);
            goto L_80056044;
    }
    goto skip_0;
    // 0x80056040: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    skip_0:
L_80056044:
    // 0x80056044: andi        $v0, $a0, 0xFFF
    ctx->r2 = ctx->r4 & 0XFFF;
    // 0x80056048: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8005604C: blez        $a1, L_80056090
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80056050: or          $a0, $v0, $a2
        ctx->r4 = ctx->r2 | ctx->r6;
            goto L_80056090;
    }
    // 0x80056050: or          $a0, $v0, $a2
    ctx->r4 = ctx->r2 | ctx->r6;
    // 0x80056054: div         $zero, $v1, $a1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r5)));
    // 0x80056058: bne         $a1, $zero, L_80056064
    if (ctx->r5 != 0) {
        // 0x8005605C: nop
    
            goto L_80056064;
    }
    // 0x8005605C: nop

    // 0x80056060: break       7
    do_break(2147836000);
L_80056064:
    // 0x80056064: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056068: bne         $a1, $at, L_8005607C
    if (ctx->r5 != ctx->r1) {
        // 0x8005606C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005607C;
    }
    // 0x8005606C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80056070: bne         $v1, $at, L_8005607C
    if (ctx->r3 != ctx->r1) {
        // 0x80056074: nop
    
            goto L_8005607C;
    }
    // 0x80056074: nop

    // 0x80056078: break       6
    do_break(2147836024);
L_8005607C:
    // 0x8005607C: mflo        $v0
    ctx->r2 = lo;
    // 0x80056080: nop

    // 0x80056084: nop

    // 0x80056088: j           L_80056094
    // 0x8005608C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
        goto L_80056094;
    // 0x8005608C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
L_80056090:
    // 0x80056090: andi        $v0, $v1, 0xFFF
    ctx->r2 = ctx->r3 & 0XFFF;
L_80056094:
    // 0x80056094: or          $v0, $a0, $v0
    ctx->r2 = ctx->r4 | ctx->r2;
    // 0x80056098: sw          $v0, 0x7C($t5)
    MEM_W(0X7C, ctx->r13) = ctx->r2;
    // 0x8005609C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800560A0: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x800560A4: lui         $v1, 0xF540
    ctx->r3 = S32(0XF540 << 16);
    // 0x800560A8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800560AC: addu        $a2, $t6, $zero
    ctx->r6 = ADD32(ctx->r14, 0);
    // 0x800560B0: addu        $a3, $t8, $zero
    ctx->r7 = ADD32(ctx->r24, 0);
    // 0x800560B4: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x800560B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800560BC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800560C0: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x800560C4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800560C8: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x800560CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800560D0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800560D4: sra         $v0, $t6, 1
    ctx->r2 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800560D8: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x800560DC: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800560E0: andi        $v0, $v0, 0x1FF
    ctx->r2 = ctx->r2 & 0X1FF;
    // 0x800560E4: sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2 << 9);
    // 0x800560E8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800560EC: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x800560F0: addiu       $v0, $a0, 0x18
    ctx->r2 = ADD32(ctx->r4, 0X18);
    // 0x800560F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800560F8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800560FC: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x80056100: addiu       $v1, $t6, -0x1
    ctx->r3 = ADD32(ctx->r14, -0X1);
    // 0x80056104: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80056108: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8005610C: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x80056110: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x80056114: addiu       $v0, $t8, -0x1
    ctx->r2 = ADD32(ctx->r24, -0X1);
    // 0x80056118: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005611C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80056120: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80056124: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80056128: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8005612C: sw          $v1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r3;
    // 0x80056130: jal         0x80056148
    // 0x80056134: addu        $a0, $t9, $zero
    ctx->r4 = ADD32(ctx->r25, 0);
    func_80056148(rdram, ctx);
        goto after_0;
    // 0x80056134: addu        $a0, $t9, $zero
    ctx->r4 = ADD32(ctx->r25, 0);
    after_0:
L_80056138:
    // 0x80056138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005613C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80056140: jr          $ra
    // 0x80056144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80056144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80056148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056148: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x8005614C: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // 0x80056150: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // 0x80056154: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x80056158: bgez        $t0, L_80056178
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8005615C: addu        $t3, $zero, $zero
        ctx->r11 = ADD32(0, 0);
            goto L_80056178;
    }
    // 0x8005615C: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // 0x80056160: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80056164: bgez        $t0, L_80056170
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80056168: addu        $t2, $t0, $zero
        ctx->r10 = ADD32(ctx->r8, 0);
            goto L_80056170;
    }
    // 0x80056168: addu        $t2, $t0, $zero
    ctx->r10 = ADD32(ctx->r8, 0);
    // 0x8005616C: negu        $t2, $t2
    ctx->r10 = SUB32(0, ctx->r10);
L_80056170:
    // 0x80056170: j           L_8005618C
    // 0x80056174: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
        goto L_8005618C;
    // 0x80056174: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
L_80056178:
    // 0x80056178: addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
    // 0x8005617C: slti        $v0, $v0, 0x140
    ctx->r2 = SIGNED(ctx->r2) < 0X140 ? 1 : 0;
    // 0x80056180: bne         $v0, $zero, L_8005618C
    if (ctx->r2 != 0) {
        // 0x80056184: addiu       $v0, $zero, 0x140
        ctx->r2 = ADD32(0, 0X140);
            goto L_8005618C;
    }
    // 0x80056184: addiu       $v0, $zero, 0x140
    ctx->r2 = ADD32(0, 0X140);
    // 0x80056188: subu        $v1, $v0, $t0
    ctx->r3 = SUB32(ctx->r2, ctx->r8);
L_8005618C:
    // 0x8005618C: bgez        $t1, L_800561AC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80056190: addu        $v0, $t1, $a3
        ctx->r2 = ADD32(ctx->r9, ctx->r7);
            goto L_800561AC;
    }
    // 0x80056190: addu        $v0, $t1, $a3
    ctx->r2 = ADD32(ctx->r9, ctx->r7);
    // 0x80056194: addu        $a3, $a3, $t1
    ctx->r7 = ADD32(ctx->r7, ctx->r9);
    // 0x80056198: bgez        $t1, L_800561A4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8005619C: addu        $t3, $t1, $zero
        ctx->r11 = ADD32(ctx->r9, 0);
            goto L_800561A4;
    }
    // 0x8005619C: addu        $t3, $t1, $zero
    ctx->r11 = ADD32(ctx->r9, 0);
    // 0x800561A0: negu        $t3, $t3
    ctx->r11 = SUB32(0, ctx->r11);
L_800561A4:
    // 0x800561A4: j           L_800561BC
    // 0x800561A8: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
        goto L_800561BC;
    // 0x800561A8: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
L_800561AC:
    // 0x800561AC: slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // 0x800561B0: bne         $v0, $zero, L_800561BC
    if (ctx->r2 != 0) {
        // 0x800561B4: addiu       $v0, $zero, 0xF0
        ctx->r2 = ADD32(0, 0XF0);
            goto L_800561BC;
    }
    // 0x800561B4: addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // 0x800561B8: subu        $a3, $v0, $t1
    ctx->r7 = SUB32(ctx->r2, ctx->r9);
L_800561BC:
    // 0x800561BC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800561C0: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x800561C4: lui         $a2, 0x400
    ctx->r6 = S32(0X400 << 16);
    // 0x800561C8: ori         $a2, $a2, 0x400
    ctx->r6 = ctx->r6 | 0X400;
    // 0x800561CC: addu        $v1, $t0, $v1
    ctx->r3 = ADD32(ctx->r8, ctx->r3);
    // 0x800561D0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800561D4: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x800561D8: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x800561DC: lui         $a0, 0xE400
    ctx->r4 = S32(0XE400 << 16);
    // 0x800561E0: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x800561E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800561E8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800561EC: addu        $v0, $t1, $a3
    ctx->r2 = ADD32(ctx->r9, ctx->r7);
    // 0x800561F0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800561F4: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x800561F8: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x800561FC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80056200: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x80056204: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80056208: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8005620C: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80056210: sll         $v1, $t1, 2
    ctx->r3 = S32(ctx->r9 << 2);
    // 0x80056214: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80056218: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005621C: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80056220: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x80056224: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056228: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8005622C: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x80056230: sll         $v1, $t2, 21
    ctx->r3 = S32(ctx->r10 << 21);
    // 0x80056234: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x80056238: sll         $v0, $t3, 5
    ctx->r2 = S32(ctx->r11 << 5);
    // 0x8005623C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80056240: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80056244: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x80056248: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005624C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056250: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x80056254: sw          $v1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r3;
    // 0x80056258: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x8005625C: jr          $ra
    // 0x80056260: sw          $a2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r6;
    return;
    // 0x80056260: sw          $a2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r6;
;}
RECOMP_FUNC void func_80056270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056270: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80056274: lw          $v1, 0x5158($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5158);
    // 0x80056278: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8005627C: addiu       $a0, $a0, -0x5E10
    ctx->r4 = ADD32(ctx->r4, -0X5E10);
    // 0x80056280: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80056284: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80056288: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005628C: sb          $zero, -0x5E0F($at)
    MEM_B(-0X5E0F, ctx->r1) = 0;
    // 0x80056290: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056294: sb          $zero, -0x5E0E($at)
    MEM_B(-0X5E0E, ctx->r1) = 0;
    // 0x80056298: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005629C: sb          $zero, -0x5E0D($at)
    MEM_B(-0X5E0D, ctx->r1) = 0;
    // 0x800562A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800562A4: sb          $zero, -0x5E0C($at)
    MEM_B(-0X5E0C, ctx->r1) = 0;
    // 0x800562A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800562AC: sb          $zero, -0x5E0B($at)
    MEM_B(-0X5E0B, ctx->r1) = 0;
    // 0x800562B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800562B4: sw          $zero, -0x5E00($at)
    MEM_W(-0X5E00, ctx->r1) = 0;
    // 0x800562B8: bne         $v1, $v0, L_800562D0
    if (ctx->r3 != ctx->r2) {
        // 0x800562BC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800562D0;
    }
    // 0x800562BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800562C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800562C4: sw          $zero, 0x5158($at)
    MEM_W(0X5158, ctx->r1) = 0;
    // 0x800562C8: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800562CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800562D0:
    // 0x800562D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800562D4: jr          $ra
    // 0x800562D8: sb          $v0, 0x7BA3($at)
    MEM_B(0X7BA3, ctx->r1) = ctx->r2;
    return;
    // 0x800562D8: sb          $v0, 0x7BA3($at)
    MEM_B(0X7BA3, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_800562DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800562DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800562E0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800562E4: addiu       $a0, $a0, -0x5E10
    ctx->r4 = ADD32(ctx->r4, -0X5E10);
    // 0x800562E8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800562EC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800562F0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800562F4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800562F8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800562FC: lw          $v0, 0x5D48($at)
    ctx->r2 = MEM_W(ctx->r1, 0X5D48);
    // 0x80056300: jalr        $v0
    // 0x80056304: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80056304: nop

    after_0:
    // 0x80056308: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005630C: jr          $ra
    // 0x80056310: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80056310: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80056314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056314: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80056318: addiu       $a0, $a0, 0x5581
    ctx->r4 = ADD32(ctx->r4, 0X5581);
    // 0x8005631C: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80056320: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x80056324: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80056328: sb          $zero, 0x5582($at)
    MEM_B(0X5582, ctx->r1) = 0;
    // 0x8005632C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80056330: sh          $v0, 0x5588($at)
    MEM_H(0X5588, ctx->r1) = ctx->r2;
    // 0x80056334: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80056338: sb          $zero, 0x7BA3($at)
    MEM_B(0X7BA3, ctx->r1) = 0;
    // 0x8005633C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80056340: jr          $ra
    // 0x80056344: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    return;
    // 0x80056344: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void func_80056348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005634C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80056350: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80056354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056358: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x8005635C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80056360: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80056364: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80056368: lw          $v0, 0x5D58($at)
    ctx->r2 = MEM_W(ctx->r1, 0X5D58);
    // 0x8005636C: jalr        $v0
    // 0x80056370: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80056370: nop

    after_0:
    // 0x80056374: jal         0x80056E30
    // 0x80056378: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80056E30(rdram, ctx);
        goto after_1;
    // 0x80056378: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8005637C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80056380: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80056384: jr          $ra
    // 0x80056388: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80056388: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005638C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005638C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80056390: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80056394: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x80056398: addiu       $v1, $zero, 0x78
    ctx->r3 = ADD32(0, 0X78);
    // 0x8005639C: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    // 0x800563A0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800563A4: jal         0x80056870
    // 0x800563A8: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    func_80056870(rdram, ctx);
        goto after_0;
    // 0x800563A8: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    after_0:
    // 0x800563AC: jal         0x80000E94
    // 0x800563B0: nop

    func_80000E94(rdram, ctx);
        goto after_1;
    // 0x800563B0: nop

    after_1:
    // 0x800563B4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800563B8: jr          $ra
    // 0x800563BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800563BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800563C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800563C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800563C4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800563C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800563CC: jal         0x8005688C
    // 0x800563D0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_8005688C(rdram, ctx);
        goto after_0;
    // 0x800563D0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x800563D4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800563D8: bne         $v0, $v1, L_800563F0
    if (ctx->r2 != ctx->r3) {
        // 0x800563DC: addiu       $v1, $zero, 0x78
        ctx->r3 = ADD32(0, 0X78);
            goto L_800563F0;
    }
    // 0x800563DC: addiu       $v1, $zero, 0x78
    ctx->r3 = ADD32(0, 0X78);
    // 0x800563E0: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x800563E4: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // 0x800563E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800563EC: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
L_800563F0:
    // 0x800563F0: jal         0x80000E94
    // 0x800563F4: nop

    func_80000E94(rdram, ctx);
        goto after_1;
    // 0x800563F4: nop

    after_1:
    // 0x800563F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800563FC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80056400: jr          $ra
    // 0x80056404: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80056404: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80056408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056408: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005640C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80056410: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80056414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056418: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8005641C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80056420: jal         0x80000E94
    // 0x80056424: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    func_80000E94(rdram, ctx);
        goto after_0;
    // 0x80056424: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    after_0:
    // 0x80056428: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8005642C: bne         $v0, $zero, L_80056444
    if (ctx->r2 != 0) {
        // 0x80056430: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80056444;
    }
    // 0x80056430: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80056434: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x80056438: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005643C: jal         0x80056858
    // 0x80056440: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    func_80056858(rdram, ctx);
        goto after_1;
    // 0x80056440: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    after_1:
L_80056444:
    // 0x80056444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80056448: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005644C: jr          $ra
    // 0x80056450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80056450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80056454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056454: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80056458: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005645C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056460: jal         0x8005688C
    // 0x80056464: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_8005688C(rdram, ctx);
        goto after_0;
    // 0x80056464: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80056468: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005646C: bne         $v0, $v1, L_80056484
    if (ctx->r2 != ctx->r3) {
        // 0x80056470: nop
    
            goto L_80056484;
    }
    // 0x80056470: nop

    // 0x80056474: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80056478: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x8005647C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80056480: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_80056484:
    // 0x80056484: jal         0x80000E94
    // 0x80056488: nop

    func_80000E94(rdram, ctx);
        goto after_1;
    // 0x80056488: nop

    after_1:
    // 0x8005648C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80056490: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80056494: jr          $ra
    // 0x80056498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80056498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005649C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005649C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800564A0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800564A4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800564A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800564AC: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x800564B0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800564B4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800564B8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800564BC: lw          $v0, 0x5D68($at)
    ctx->r2 = MEM_W(ctx->r1, 0X5D68);
    // 0x800564C0: jalr        $v0
    // 0x800564C4: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800564C4: nop

    after_0:
    // 0x800564C8: jal         0x80056E30
    // 0x800564CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80056E30(rdram, ctx);
        goto after_1;
    // 0x800564CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800564D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800564D4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800564D8: jr          $ra
    // 0x800564DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800564DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800564E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800564E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800564E4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800564E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800564EC: jal         0x80056870
    // 0x800564F0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_80056870(rdram, ctx);
        goto after_0;
    // 0x800564F0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x800564F4: jal         0x80056618
    // 0x800564F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80056618(rdram, ctx);
        goto after_1;
    // 0x800564F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800564FC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80056500: addiu       $v1, $v1, -0x5E0F
    ctx->r3 = ADD32(ctx->r3, -0X5E0F);
    // 0x80056504: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80056508: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005650C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80056510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80056514: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80056518: jr          $ra
    // 0x8005651C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005651C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80056520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056520: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80056524: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80056528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005652C: jal         0x8005688C
    // 0x80056530: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_8005688C(rdram, ctx);
        goto after_0;
    // 0x80056530: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80056534: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80056538: bne         $v0, $v1, L_8005655C
    if (ctx->r2 != ctx->r3) {
        // 0x8005653C: nop
    
            goto L_8005655C;
    }
    // 0x8005653C: nop

    // 0x80056540: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80056544: addiu       $v0, $v0, -0x5E0F
    ctx->r2 = ADD32(ctx->r2, -0X5E0F);
    // 0x80056548: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8005654C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80056550: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x80056554: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x80056558: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
L_8005655C:
    // 0x8005655C: jal         0x80056618
    // 0x80056560: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80056618(rdram, ctx);
        goto after_1;
    // 0x80056560: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80056564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80056568: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005656C: jr          $ra
    // 0x80056570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80056570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80056574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056574: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80056578: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005657C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80056580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056584: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80056588: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8005658C: bne         $v0, $zero, L_800565AC
    if (ctx->r2 != 0) {
        // 0x80056590: sw          $v0, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->r2;
            goto L_800565AC;
    }
    // 0x80056590: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80056594: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80056598: addiu       $v1, $v1, -0x5E0F
    ctx->r3 = ADD32(ctx->r3, -0X5E0F);
    // 0x8005659C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800565A0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800565A4: jal         0x80056858
    // 0x800565A8: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    func_80056858(rdram, ctx);
        goto after_0;
    // 0x800565A8: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    after_0:
L_800565AC:
    // 0x800565AC: jal         0x80056618
    // 0x800565B0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80056618(rdram, ctx);
        goto after_1;
    // 0x800565B0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800565B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800565B8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800565BC: jr          $ra
    // 0x800565C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800565C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800565C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800565C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800565C8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800565CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800565D0: jal         0x8005688C
    // 0x800565D4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_8005688C(rdram, ctx);
        goto after_0;
    // 0x800565D4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x800565D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800565DC: bne         $v0, $v1, L_80056600
    if (ctx->r2 != ctx->r3) {
        // 0x800565E0: nop
    
            goto L_80056600;
    }
    // 0x800565E0: nop

    // 0x800565E4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800565E8: lbu         $v0, -0x5E10($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5E10);
    // 0x800565EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800565F0: sb          $zero, -0x5E0F($at)
    MEM_B(-0X5E0F, ctx->r1) = 0;
    // 0x800565F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800565F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800565FC: sb          $v0, -0x5E10($at)
    MEM_B(-0X5E10, ctx->r1) = ctx->r2;
L_80056600:
    // 0x80056600: jal         0x80056618
    // 0x80056604: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80056618(rdram, ctx);
        goto after_1;
    // 0x80056604: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80056608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005660C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80056610: jr          $ra
    // 0x80056614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80056614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80056618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056618: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005661C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80056620: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80056624: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80056628: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8005662C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
L_80056630:
    // 0x80056630: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80056634: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x80056638: lw          $a0, 0x5D80($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5D80);
    // 0x8005663C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80056640: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // 0x80056644: lw          $a1, 0x5D78($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5D78);
    // 0x80056648: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8005664C: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x80056650: lw          $a2, 0x5D7C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5D7C);
    // 0x80056654: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80056658: jal         0x80056970
    // 0x8005665C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    func_80056970(rdram, ctx);
        goto after_0;
    // 0x8005665C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_0:
    // 0x80056660: slti        $v0, $s1, 0x18
    ctx->r2 = SIGNED(ctx->r17) < 0X18 ? 1 : 0;
    // 0x80056664: bne         $v0, $zero, L_80056630
    if (ctx->r2 != 0) {
        // 0x80056668: nop
    
            goto L_80056630;
    }
    // 0x80056668: nop

    // 0x8005666C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80056670: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80056674: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80056678: jr          $ra
    // 0x8005667C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005667C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80056680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056680: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80056684: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80056688: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8005668C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056690: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x80056694: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80056698: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8005669C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800566A0: lw          $v0, 0x5E98($at)
    ctx->r2 = MEM_W(ctx->r1, 0X5E98);
    // 0x800566A4: jalr        $v0
    // 0x800566A8: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800566A8: nop

    after_0:
    // 0x800566AC: jal         0x80056E30
    // 0x800566B0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80056E30(rdram, ctx);
        goto after_1;
    // 0x800566B0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800566B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800566B8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800566BC: jr          $ra
    // 0x800566C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800566C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
