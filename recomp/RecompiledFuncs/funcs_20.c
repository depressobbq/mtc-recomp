#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8005DEE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DEE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005DEE8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005DEEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005DEF0: jal         0x8006553C
    // 0x8005DEF4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_8006553C(rdram, ctx);
        goto after_0;
    // 0x8005DEF4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8005DEF8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8005DEFC: lw          $a1, 0x60B4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X60B4);
    // 0x8005DF00: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005DF04: jal         0x8006551C
    // 0x8005DF08: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    func_8006551C(rdram, ctx);
        goto after_1;
    // 0x8005DF08: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_1:
    // 0x8005DF0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005DF10: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005DF14: jr          $ra
    // 0x8005DF18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005DF18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005DF1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DF1C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005DF20: lw          $v0, 0x60B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60B4);
    // 0x8005DF24: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x8005DF28: nop

    // 0x8005DF2C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005DF30: lwc1        $f2, 0x4C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8005DF34: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8005DF38: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005DF3C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005DF40: ldc1        $f2, -0x11F0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X11F0);
    // 0x8005DF44: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8005DF48: div.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x8005DF4C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005DF50: ldc1        $f2, -0x11E8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X11E8);
    // 0x8005DF54: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8005DF58: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8005DF5C: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005DF60: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8005DF64: jr          $ra
    // 0x8005DF68: nop

    return;
    // 0x8005DF68: nop

;}
RECOMP_FUNC void func_8005DF6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DF6C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005DF70: lw          $v0, 0x60B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60B4);
    // 0x8005DF74: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x8005DF78: nop

    // 0x8005DF7C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005DF80: lwc1        $f2, 0x4C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8005DF84: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8005DF88: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005DF8C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005DF90: ldc1        $f2, -0x11E0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X11E0);
    // 0x8005DF94: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8005DF98: div.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x8005DF9C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005DFA0: ldc1        $f2, -0x11D8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X11D8);
    // 0x8005DFA4: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8005DFA8: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8005DFAC: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005DFB0: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8005DFB4: addiu       $v0, $zero, -0x10
    ctx->r2 = ADD32(0, -0X10);
    // 0x8005DFB8: jr          $ra
    // 0x8005DFBC: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    return;
    // 0x8005DFBC: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
;}
RECOMP_FUNC void func_8005DFC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DFC0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005DFC4: lw          $v0, 0x60B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60B4);
    // 0x8005DFC8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005DFCC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8005DFD0: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8005DFD4: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8005DFD8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8005DFDC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8005DFE0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005DFE4: lw          $s2, 0x40($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X40);
    // 0x8005DFE8: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x8005DFEC: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x8005DFF0: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // 0x8005DFF4: lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C);
    // 0x8005DFF8: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x8005DFFC: ori         $v0, $v0, 0x7C0
    ctx->r2 = ctx->r2 | 0X7C0;
    // 0x8005E000: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8005E004: addiu       $v0, $zero, 0x2E0
    ctx->r2 = ADD32(0, 0X2E0);
    // 0x8005E008: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8005E00C: lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14);
    // 0x8005E010: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x8005E014: blez        $v0, L_8005E04C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005E018: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8005E04C;
    }
    // 0x8005E018: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8005E01C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
L_8005E020:
    // 0x8005E020: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x8005E024: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005E028: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8005E02C: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // 0x8005E030: jal         0x8005E590
    // 0x8005E034: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    func_8005E590(rdram, ctx);
        goto after_0;
    // 0x8005E034: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    after_0:
    // 0x8005E038: lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X14);
    // 0x8005E03C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005E040: slt         $v1, $s0, $v1
    ctx->r3 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005E044: bne         $v1, $zero, L_8005E020
    if (ctx->r3 != 0) {
        // 0x8005E048: addu        $a2, $v0, $zero
        ctx->r6 = ADD32(ctx->r2, 0);
            goto L_8005E020;
    }
    // 0x8005E048: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
L_8005E04C:
    // 0x8005E04C: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x8005E050: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8005E054: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8005E058: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8005E05C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8005E060: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005E064: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005E068: jr          $ra
    // 0x8005E06C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005E06C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8005E070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E070: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005E074: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005E078: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8005E07C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8005E080: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x8005E084: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8005E088: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x8005E08C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005E090: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005E094: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005E098: addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
    // 0x8005E09C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8005E0A0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8005E0A4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8005E0A8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005E0AC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005E0B0: jal         0x800655B0
    // 0x8005E0B4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800655B0(rdram, ctx);
        goto after_0;
    // 0x8005E0B4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x8005E0B8: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8005E0BC: sw          $s3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r19;
    // 0x8005E0C0: lbu         $v0, 0x1C($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1C);
    // 0x8005E0C4: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8005E0C8: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x8005E0CC: beq         $v0, $zero, L_8005E12C
    if (ctx->r2 == 0) {
        // 0x8005E0D0: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8005E12C;
    }
    // 0x8005E0D0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005E0D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005E0D8: addu        $at, $at, $v0
    gpr jr_addend_8005E0E0 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005E0DC: lw          $v0, -0x11D0($at)
    ctx->r2 = ADD32(ctx->r1, -0X11D0);
    // 0x8005E0E0: jr          $v0
    // 0x8005E0E4: nop

    switch (jr_addend_8005E0E0 >> 2) {
        case 0: goto L_8005E0E8; break;
        case 1: goto L_8005E0F4; break;
        case 2: goto L_8005E10C; break;
        case 3: goto L_8005E118; break;
        case 4: goto L_8005E100; break;
        case 5: goto L_8005E124; break;
        default: switch_error(__func__, 0x8005E0E0, 0x800AEE30);
    }
    // 0x8005E0E4: nop

L_8005E0E8:
    // 0x8005E0E8: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x8005E0EC: j           L_8005E134
    // 0x8005E0F0: addiu       $s2, $s2, 0x60C0
    ctx->r18 = ADD32(ctx->r18, 0X60C0);
        goto L_8005E134;
    // 0x8005E0F0: addiu       $s2, $s2, 0x60C0
    ctx->r18 = ADD32(ctx->r18, 0X60C0);
L_8005E0F4:
    // 0x8005E0F4: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x8005E0F8: j           L_8005E134
    // 0x8005E0FC: addiu       $s2, $s2, 0x6128
    ctx->r18 = ADD32(ctx->r18, 0X6128);
        goto L_8005E134;
    // 0x8005E0FC: addiu       $s2, $s2, 0x6128
    ctx->r18 = ADD32(ctx->r18, 0X6128);
L_8005E100:
    // 0x8005E100: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x8005E104: j           L_8005E134
    // 0x8005E108: addiu       $s2, $s2, 0x61B0
    ctx->r18 = ADD32(ctx->r18, 0X61B0);
        goto L_8005E134;
    // 0x8005E108: addiu       $s2, $s2, 0x61B0
    ctx->r18 = ADD32(ctx->r18, 0X61B0);
L_8005E10C:
    // 0x8005E10C: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x8005E110: j           L_8005E134
    // 0x8005E114: addiu       $s2, $s2, 0x61D8
    ctx->r18 = ADD32(ctx->r18, 0X61D8);
        goto L_8005E134;
    // 0x8005E114: addiu       $s2, $s2, 0x61D8
    ctx->r18 = ADD32(ctx->r18, 0X61D8);
L_8005E118:
    // 0x8005E118: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x8005E11C: j           L_8005E134
    // 0x8005E120: addiu       $s2, $s2, 0x6200
    ctx->r18 = ADD32(ctx->r18, 0X6200);
        goto L_8005E134;
    // 0x8005E120: addiu       $s2, $s2, 0x6200
    ctx->r18 = ADD32(ctx->r18, 0X6200);
L_8005E124:
    // 0x8005E124: j           L_8005E134
    // 0x8005E128: lw          $s2, 0x20($s6)
    ctx->r18 = MEM_W(ctx->r22, 0X20);
        goto L_8005E134;
    // 0x8005E128: lw          $s2, 0x20($s6)
    ctx->r18 = MEM_W(ctx->r22, 0X20);
L_8005E12C:
    // 0x8005E12C: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x8005E130: addiu       $s2, $s2, 0x6228
    ctx->r18 = ADD32(ctx->r18, 0X6228);
L_8005E134:
    // 0x8005E134: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8005E138: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005E13C: sb          $v0, 0x24($s3)
    MEM_B(0X24, ctx->r19) = ctx->r2;
    // 0x8005E140: lbu         $a3, 0x24($s3)
    ctx->r7 = MEM_BU(ctx->r19, 0X24);
    // 0x8005E144: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x8005E148: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005E14C: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x8005E150: sw          $v0, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->r2;
    // 0x8005E154: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x8005E158: jal         0x800655B0
    // 0x8005E15C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800655B0(rdram, ctx);
        goto after_1;
    // 0x8005E15C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x8005E160: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005E164: sw          $v0, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->r2;
    // 0x8005E168: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8005E16C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005E170: lw          $a3, 0x1C($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X1C);
    // 0x8005E174: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005E178: jal         0x800655B0
    // 0x8005E17C: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    func_800655B0(rdram, ctx);
        goto after_2;
    // 0x8005E17C: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    after_2:
    // 0x8005E180: lw          $v1, 0x1C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1C);
    // 0x8005E184: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x8005E188: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005E18C: sw          $v0, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r2;
    // 0x8005E190: beq         $v1, $zero, L_8005E1C4
    if (ctx->r3 == 0) {
        // 0x8005E194: sw          $v0, 0x18($s3)
        MEM_W(0X18, ctx->r19) = ctx->r2;
            goto L_8005E1C4;
    }
    // 0x8005E194: sw          $v0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r2;
L_8005E198:
    // 0x8005E198: lw          $v1, 0x14($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X14);
    // 0x8005E19C: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8005E1A0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005E1A4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005E1A8: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8005E1AC: lw          $v1, 0x1C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1C);
    // 0x8005E1B0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005E1B4: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8005E1B8: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8005E1BC: bne         $v0, $zero, L_8005E198
    if (ctx->r2 != 0) {
        // 0x8005E1C0: nop
    
            goto L_8005E198;
    }
    // 0x8005E1C0: nop

L_8005E1C4:
    // 0x8005E1C4: lbu         $v0, 0x24($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X24);
    // 0x8005E1C8: beq         $v0, $zero, L_8005E434
    if (ctx->r2 == 0) {
        // 0x8005E1CC: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_8005E434;
    }
    // 0x8005E1CC: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8005E1D0: andi        $v0, $s4, 0xFFFF
    ctx->r2 = ctx->r20 & 0XFFFF;
L_8005E1D4:
    // 0x8005E1D4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8005E1D8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005E1DC: lw          $a1, 0x20($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X20);
    // 0x8005E1E0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005E1E4: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8005E1E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005E1EC: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8005E1F0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8005E1F4: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8005E1F8: addu        $s0, $a1, $v1
    ctx->r16 = ADD32(ctx->r5, ctx->r3);
    // 0x8005E1FC: addiu       $a1, $a0, 0x1
    ctx->r5 = ADD32(ctx->r4, 0X1);
    // 0x8005E200: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8005E204: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x8005E208: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005E20C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8005E210: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005E214: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x8005E218: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005E21C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005E220: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8005E224: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x8005E228: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005E22C: addiu       $v0, $a1, 0x2
    ctx->r2 = ADD32(ctx->r5, 0X2);
    // 0x8005E230: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005E234: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005E238: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8005E23C: sh          $v1, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r3;
    // 0x8005E240: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005E244: addiu       $v0, $a1, 0x3
    ctx->r2 = ADD32(ctx->r5, 0X3);
    // 0x8005E248: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005E24C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005E250: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8005E254: sh          $v1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r3;
    // 0x8005E258: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8005E25C: addiu       $s1, $a1, 0x4
    ctx->r17 = ADD32(ctx->r5, 0X4);
    // 0x8005E260: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // 0x8005E264: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x8005E268: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005E26C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8005E270: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8005E274: beq         $v0, $zero, L_8005E384
    if (ctx->r2 == 0) {
        // 0x8005E278: addu        $v0, $s1, $zero
        ctx->r2 = ADD32(ctx->r17, 0);
            goto L_8005E384;
    }
    // 0x8005E278: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x8005E27C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005E280: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005E284: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8005E288: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005E28C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8005E290: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8005E294: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005E298: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005E29C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8005E2A0: add.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
    // 0x8005E2A4: lwc1        $f2, 0x18($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X18);
    // 0x8005E2A8: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x8005E2AC: div.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x8005E2B0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8005E2B4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8005E2B8: addiu       $v0, $a1, 0x5
    ctx->r2 = ADD32(ctx->r5, 0X5);
    // 0x8005E2BC: addiu       $s1, $a1, 0x6
    ctx->r17 = ADD32(ctx->r5, 0X6);
    // 0x8005E2C0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005E2C4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005E2C8: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8005E2CC: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x8005E2D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005E2D4: ldc1        $f2, -0x11B8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X11B8);
    // 0x8005E2D8: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x8005E2DC: nop

    // 0x8005E2E0: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8005E2E4: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8005E2E8: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8005E2EC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8005E2F0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005E2F4: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8005E2F8: bgez        $a0, L_8005E30C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8005E2FC: div.d       $f2, $f0, $f2
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = DIV_D(ctx->f0.d, ctx->f2.d);
            goto L_8005E30C;
    }
    // 0x8005E2FC: div.d       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x8005E300: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005E304: ldc1        $f0, -0x11B0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X11B0);
    // 0x8005E308: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_8005E30C:
    // 0x8005E30C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005E310: mul.d       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x8005E314: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005E318: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005E31C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005E320: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x8005E324: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005E328: addiu       $v0, $zero, 0x34
    ctx->r2 = ADD32(0, 0X34);
    // 0x8005E32C: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x8005E330: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x8005E334: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8005E338: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x8005E33C: jal         0x800655B0
    // 0x8005E340: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800655B0(rdram, ctx);
        goto after_3;
    // 0x8005E340: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x8005E344: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005E348: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005E34C: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x8005E350: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005E354: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x8005E358: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x8005E35C: jal         0x800655B0
    // 0x8005E360: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800655B0(rdram, ctx);
        goto after_4;
    // 0x8005E360: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_4:
    // 0x8005E364: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x8005E368: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x8005E36C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8005E370: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x8005E374: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x8005E378: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005E37C: j           L_8005E38C
    // 0x8005E380: sw          $v0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r2;
        goto L_8005E38C;
    // 0x8005E380: sw          $v0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r2;
L_8005E384:
    // 0x8005E384: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x8005E388: addiu       $s1, $a1, 0x6
    ctx->r17 = ADD32(ctx->r5, 0X6);
L_8005E38C:
    // 0x8005E38C: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x8005E390: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005E394: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8005E398: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8005E39C: beq         $v0, $zero, L_8005E414
    if (ctx->r2 == 0) {
        // 0x8005E3A0: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8005E414;
    }
    // 0x8005E3A0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005E3A4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005E3A8: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x8005E3AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005E3B0: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x8005E3B4: jal         0x800655B0
    // 0x8005E3B8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800655B0(rdram, ctx);
        goto after_5;
    // 0x8005E3B8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_5:
    // 0x8005E3BC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005E3C0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005E3C4: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x8005E3C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005E3CC: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x8005E3D0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8005E3D4: jal         0x800655B0
    // 0x8005E3D8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800655B0(rdram, ctx);
        goto after_6;
    // 0x8005E3D8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_6:
    // 0x8005E3DC: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x8005E3E0: sw          $v0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r2;
    // 0x8005E3E4: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x8005E3E8: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x8005E3EC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005E3F0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005E3F4: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8005E3F8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8005E3FC: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8005E400: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x8005E404: jal         0x800621F0
    // 0x8005E408: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    func_800621F0(rdram, ctx);
        goto after_7;
    // 0x8005E408: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_7:
    // 0x8005E40C: j           L_8005E41C
    // 0x8005E410: nop

        goto L_8005E41C;
    // 0x8005E410: nop

L_8005E414:
    // 0x8005E414: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x8005E418: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8005E41C:
    // 0x8005E41C: lbu         $v1, 0x24($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X24);
    // 0x8005E420: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8005E424: andi        $v0, $s4, 0xFFFF
    ctx->r2 = ctx->r20 & 0XFFFF;
    // 0x8005E428: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8005E42C: bne         $v0, $zero, L_8005E1D4
    if (ctx->r2 != 0) {
        // 0x8005E430: andi        $v0, $s4, 0xFFFF
        ctx->r2 = ctx->r20 & 0XFFFF;
            goto L_8005E1D4;
    }
    // 0x8005E430: andi        $v0, $s4, 0xFFFF
    ctx->r2 = ctx->r20 & 0XFFFF;
L_8005E434:
    // 0x8005E434: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8005E438: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8005E43C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8005E440: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8005E444: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8005E448: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005E44C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E450: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005E454: jr          $ra
    // 0x8005E458: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005E458: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8005E45C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E45C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005E460: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005E464: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8005E468: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005E46C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8005E470: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8005E474: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8005E478: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005E47C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005E480: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005E484: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005E488: addiu       $s2, $zero, 0x20
    ctx->r18 = ADD32(0, 0X20);
    // 0x8005E48C: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8005E490: jal         0x800655B0
    // 0x8005E494: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_800655B0(rdram, ctx);
        goto after_0;
    // 0x8005E494: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_0:
    // 0x8005E498: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005E49C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005E4A0: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8005E4A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005E4A8: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x8005E4AC: jal         0x800655B0
    // 0x8005E4B0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_800655B0(rdram, ctx);
        goto after_1;
    // 0x8005E4B0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_1:
    // 0x8005E4B4: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x8005E4B8: jalr        $s1
    // 0x8005E4BC: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    LOOKUP_FUNC(ctx->r17)(rdram, ctx);
        goto after_2;
    // 0x8005E4BC: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    after_2:
    // 0x8005E4C0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005E4C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005E4C8: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8005E4CC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005E4D0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8005E4D4: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x8005E4D8: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x8005E4DC: sw          $s1, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r17;
    // 0x8005E4E0: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x8005E4E4: jal         0x800655B0
    // 0x8005E4E8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_800655B0(rdram, ctx);
        goto after_3;
    // 0x8005E4E8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_3:
    // 0x8005E4EC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005E4F0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005E4F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005E4F8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005E4FC: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8005E500: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8005E504: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x8005E508: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x8005E50C: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
    // 0x8005E510: sw          $s1, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r17;
    // 0x8005E514: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
    // 0x8005E518: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x8005E51C: jal         0x800655B0
    // 0x8005E520: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800655B0(rdram, ctx);
        goto after_4;
    // 0x8005E520: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_4:
    // 0x8005E524: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x8005E528: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005E52C: sw          $s1, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r17;
    // 0x8005E530: sw          $zero, 0x84($s0)
    MEM_W(0X84, ctx->r16) = 0;
    // 0x8005E534: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x8005E538: sh          $v0, 0x68($s0)
    MEM_H(0X68, ctx->r16) = ctx->r2;
    // 0x8005E53C: sh          $v0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r2;
    // 0x8005E540: sh          $v0, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r2;
    // 0x8005E544: sh          $v0, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r2;
    // 0x8005E548: sh          $zero, 0x60($s0)
    MEM_H(0X60, ctx->r16) = 0;
    // 0x8005E54C: sh          $zero, 0x62($s0)
    MEM_H(0X62, ctx->r16) = 0;
    // 0x8005E550: sh          $v0, 0x66($s0)
    MEM_H(0X66, ctx->r16) = ctx->r2;
    // 0x8005E554: sh          $zero, 0x64($s0)
    MEM_H(0X64, ctx->r16) = 0;
    // 0x8005E558: sh          $v0, 0x66($s0)
    MEM_H(0X66, ctx->r16) = ctx->r2;
    // 0x8005E55C: sh          $zero, 0x64($s0)
    MEM_H(0X64, ctx->r16) = 0;
    // 0x8005E560: sw          $zero, 0x70($s0)
    MEM_W(0X70, ctx->r16) = 0;
    // 0x8005E564: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x8005E568: sh          $zero, 0x58($s0)
    MEM_H(0X58, ctx->r16) = 0;
    // 0x8005E56C: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x8005E570: sw          $zero, 0x80($s0)
    MEM_W(0X80, ctx->r16) = 0;
    // 0x8005E574: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8005E578: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8005E57C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005E580: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E584: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005E588: jr          $ra
    // 0x8005E58C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005E58C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8005E590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E590: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005E594: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8005E598: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x8005E59C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005E5A0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8005E5A4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8005E5A8: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8005E5AC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8005E5B0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8005E5B4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8005E5B8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8005E5BC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8005E5C0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8005E5C4: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x8005E5C8: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x8005E5CC: addu        $s7, $a3, $zero
    ctx->r23 = ADD32(ctx->r7, 0);
    // 0x8005E5D0: addiu       $fp, $zero, 0xB8
    ctx->r30 = ADD32(0, 0XB8);
    // 0x8005E5D4: sh          $zero, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = 0;
    // 0x8005E5D8: beq         $v0, $zero, L_8005EB3C
    if (ctx->r2 == 0) {
        // 0x8005E5DC: sh          $zero, 0x18($sp)
        MEM_H(0X18, ctx->r29) = 0;
            goto L_8005EB3C;
    }
    // 0x8005E5DC: sh          $zero, 0x18($sp)
    MEM_H(0X18, ctx->r29) = 0;
    // 0x8005E5E0: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8005E5E4: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x8005E5E8: addiu       $s5, $s5, 0x6250
    ctx->r21 = ADD32(ctx->r21, 0X6250);
L_8005E5EC:
    // 0x8005E5EC: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x8005E5F0: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x8005E5F4: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x8005E5F8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8005E5FC: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    // 0x8005E600: addiu       $a1, $a1, 0x5C
    ctx->r5 = ADD32(ctx->r5, 0X5C);
    // 0x8005E604: sltiu       $v0, $a1, 0x5C
    ctx->r2 = ctx->r5 < 0X5C ? 1 : 0;
    // 0x8005E608: jal         0x8006D2D0
    // 0x8005E60C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    __divdi3_recomp(rdram, ctx);
        goto after_0;
    // 0x8005E60C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_0:
    // 0x8005E610: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    // 0x8005E614: addu        $a3, $s7, $zero
    ctx->r7 = ADD32(ctx->r23, 0);
    // 0x8005E618: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x8005E61C: srl         $t0, $v1, 31
    ctx->r8 = S32(U32(ctx->r3) >> 31);
    // 0x8005E620: or          $a0, $a0, $t0
    ctx->r4 = ctx->r4 | ctx->r8;
    // 0x8005E624: sll         $a1, $v1, 1
    ctx->r5 = S32(ctx->r3 << 1);
    // 0x8005E628: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x8005E62C: sltu        $t0, $a1, $v1
    ctx->r8 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x8005E630: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8005E634: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8005E638: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8005E63C: srl         $t0, $a1, 29
    ctx->r8 = S32(U32(ctx->r5) >> 29);
    // 0x8005E640: or          $a0, $a0, $t0
    ctx->r4 = ctx->r4 | ctx->r8;
    // 0x8005E644: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x8005E648: sltu        $t0, $a1, $v1
    ctx->r8 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x8005E64C: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x8005E650: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8005E654: subu        $a0, $a0, $t0
    ctx->r4 = SUB32(ctx->r4, ctx->r8);
    // 0x8005E658: sll         $s6, $a0, 3
    ctx->r22 = S32(ctx->r4 << 3);
    // 0x8005E65C: srl         $v0, $a1, 29
    ctx->r2 = S32(U32(ctx->r5) >> 29);
    // 0x8005E660: or          $s6, $s6, $v0
    ctx->r22 = ctx->r22 | ctx->r2;
    // 0x8005E664: sll         $s7, $a1, 3
    ctx->r23 = S32(ctx->r5 << 3);
    // 0x8005E668: subu        $s2, $s7, $a3
    ctx->r18 = SUB32(ctx->r23, ctx->r7);
    // 0x8005E66C: slt         $v0, $fp, $s2
    ctx->r2 = SIGNED(ctx->r30) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8005E670: bnel        $v0, $zero, L_8005EB40
    if (ctx->r2 != 0) {
        // 0x8005E674: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8005EB40;
    }
    goto skip_0;
    // 0x8005E674: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    skip_0:
    // 0x8005E678: bgez        $s2, L_8005E69C
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8005E67C: slti        $v0, $s2, 0xB9
        ctx->r2 = SIGNED(ctx->r18) < 0XB9 ? 1 : 0;
            goto L_8005E69C;
    }
    // 0x8005E67C: slti        $v0, $s2, 0xB9
    ctx->r2 = SIGNED(ctx->r18) < 0XB9 ? 1 : 0;
    // 0x8005E680: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005E684: addiu       $a0, $a0, -0x11A0
    ctx->r4 = ADD32(ctx->r4, -0X11A0);
    // 0x8005E688: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8005E68C: addiu       $a1, $a1, -0x1190
    ctx->r5 = ADD32(ctx->r5, -0X1190);
    // 0x8005E690: jal         0x800621E0
    // 0x8005E694: addiu       $a2, $zero, 0x86
    ctx->r6 = ADD32(0, 0X86);
    func_800621E0(rdram, ctx);
        goto after_1;
    // 0x8005E694: addiu       $a2, $zero, 0x86
    ctx->r6 = ADD32(0, 0X86);
    after_1:
    // 0x8005E698: slti        $v0, $s2, 0xB9
    ctx->r2 = SIGNED(ctx->r18) < 0XB9 ? 1 : 0;
L_8005E69C:
    // 0x8005E69C: bne         $v0, $zero, L_8005E6BC
    if (ctx->r2 != 0) {
        // 0x8005E6A0: nop
    
            goto L_8005E6BC;
    }
    // 0x8005E6A0: nop

    // 0x8005E6A4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005E6A8: addiu       $a0, $a0, -0x1188
    ctx->r4 = ADD32(ctx->r4, -0X1188);
    // 0x8005E6AC: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8005E6B0: addiu       $a1, $a1, -0x1190
    ctx->r5 = ADD32(ctx->r5, -0X1190);
    // 0x8005E6B4: jal         0x800621E0
    // 0x8005E6B8: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    func_800621E0(rdram, ctx);
        goto after_2;
    // 0x8005E6B8: addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    after_2:
L_8005E6BC:
    // 0x8005E6BC: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x8005E6C0: lh          $v1, 0x10($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X10);
    // 0x8005E6C4: sltiu       $v0, $v1, 0x11
    ctx->r2 = ctx->r3 < 0X11 ? 1 : 0;
    // 0x8005E6C8: beq         $v0, $zero, L_8005EACC
    if (ctx->r2 == 0) {
        // 0x8005E6CC: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8005EACC;
    }
    // 0x8005E6CC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005E6D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005E6D4: addu        $at, $at, $v0
    gpr jr_addend_8005E6DC = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005E6D8: lw          $v0, -0x1170($at)
    ctx->r2 = ADD32(ctx->r1, -0X1170);
    // 0x8005E6DC: jr          $v0
    // 0x8005E6E0: nop

    switch (jr_addend_8005E6DC >> 2) {
        case 0: goto L_8005EA28; break;
        case 1: goto L_8005EACC; break;
        case 2: goto L_8005EACC; break;
        case 3: goto L_8005EACC; break;
        case 4: goto L_8005EACC; break;
        case 5: goto L_8005EA94; break;
        case 6: goto L_8005EACC; break;
        case 7: goto L_8005EA44; break;
        case 8: goto L_8005EA70; break;
        case 9: goto L_8005EACC; break;
        case 10: goto L_8005EACC; break;
        case 11: goto L_8005E80C; break;
        case 12: goto L_8005E80C; break;
        case 13: goto L_8005E6E4; break;
        case 14: goto L_8005E9D4; break;
        case 15: goto L_8005E9FC; break;
        case 16: goto L_8005E80C; break;
        default: switch_error(__func__, 0x8005E6DC, 0x800AEE90);
    }
    // 0x8005E6E0: nop

L_8005E6E4:
    // 0x8005E6E4: lw          $s1, 0x7C($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X7C);
    // 0x8005E6E8: lh          $v0, 0x12($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X12);
    // 0x8005E6EC: bnel        $v0, $zero, L_8005E6F4
    if (ctx->r2 != 0) {
        // 0x8005E6F0: sw          $s4, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->r20;
            goto L_8005E6F4;
    }
    goto skip_1;
    // 0x8005E6F0: sw          $s4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r20;
    skip_1:
L_8005E6F4:
    // 0x8005E6F4: lw          $a2, 0x20($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X20);
    // 0x8005E6F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005E6FC: jal         0x8005F438
    // 0x8005E700: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8005F438(rdram, ctx);
        goto after_3;
    // 0x8005E700: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_3:
    // 0x8005E704: sw          $s4, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r20;
    // 0x8005E708: sw          $s4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r20;
    // 0x8005E70C: sw          $zero, 0x70($s0)
    MEM_W(0X70, ctx->r16) = 0;
    // 0x8005E710: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    // 0x8005E714: lui         $v1, 0xB216
    ctx->r3 = S32(0XB216 << 16);
    // 0x8005E718: ori         $v1, $v1, 0x42C9
    ctx->r3 = ctx->r3 | 0X42C9;
    // 0x8005E71C: addiu       $v0, $v0, 0x5C
    ctx->r2 = ADD32(ctx->r2, 0X5C);
    // 0x8005E720: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E724: mfhi        $t1
    ctx->r9 = hi;
    // 0x8005E728: addu        $v1, $t1, $v0
    ctx->r3 = ADD32(ctx->r9, ctx->r2);
    // 0x8005E72C: sra         $v1, $v1, 7
    ctx->r3 = S32(SIGNED(ctx->r3) >> 7);
    // 0x8005E730: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8005E734: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005E738: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8005E73C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005E740: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005E744: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8005E748: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005E74C: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
    // 0x8005E750: lh          $v0, 0x18($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X18);
    // 0x8005E754: mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E758: mflo        $v0
    ctx->r2 = lo;
    // 0x8005E75C: sra         $v0, $v0, 15
    ctx->r2 = S32(SIGNED(ctx->r2) >> 15);
    // 0x8005E760: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x8005E764: lbu         $v0, 0x1A($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1A);
    // 0x8005E768: sh          $v0, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r2;
    // 0x8005E76C: lbu         $v0, 0x1B($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1B);
    // 0x8005E770: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005E774: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x8005E778: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8005E77C: sh          $v0, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r2;
    // 0x8005E780: lbu         $v0, 0x1B($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1B);
    // 0x8005E784: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
    // 0x8005E788: subu        $v0, $t1, $v0
    ctx->r2 = SUB32(ctx->r9, ctx->r2);
    // 0x8005E78C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005E790: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x8005E794: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8005E798: sh          $v0, 0x62($s0)
    MEM_H(0X62, ctx->r16) = ctx->r2;
    // 0x8005E79C: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    // 0x8005E7A0: beq         $v0, $zero, L_8005E7B4
    if (ctx->r2 == 0) {
        // 0x8005E7A4: nop
    
            goto L_8005E7B4;
    }
    // 0x8005E7A4: nop

    // 0x8005E7A8: sh          $s4, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r20;
    // 0x8005E7AC: j           L_8005E800
    // 0x8005E7B0: sh          $s4, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r20;
        goto L_8005E800;
    // 0x8005E7B0: sh          $s4, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r20;
L_8005E7B4:
    // 0x8005E7B4: lh          $v0, 0x58($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X58);
    // 0x8005E7B8: lh          $v1, 0x5A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X5A);
    // 0x8005E7BC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005E7C0: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x8005E7C4: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x8005E7C8: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E7CC: mflo        $v1
    ctx->r3 = lo;
    // 0x8005E7D0: lh          $v0, 0x58($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X58);
    // 0x8005E7D4: subu        $v0, $t1, $v0
    ctx->r2 = SUB32(ctx->r9, ctx->r2);
    // 0x8005E7D8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005E7DC: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x8005E7E0: sra         $v1, $v1, 15
    ctx->r3 = S32(SIGNED(ctx->r3) >> 15);
    // 0x8005E7E4: sh          $v1, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r3;
    // 0x8005E7E8: lh          $v1, 0x5A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X5A);
    // 0x8005E7EC: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x8005E7F0: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E7F4: mflo        $v1
    ctx->r3 = lo;
    // 0x8005E7F8: sra         $v1, $v1, 15
    ctx->r3 = S32(SIGNED(ctx->r3) >> 15);
    // 0x8005E7FC: sh          $v1, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r3;
L_8005E800:
    // 0x8005E800: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005E804: j           L_8005EB00
    // 0x8005E808: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
        goto L_8005EB00;
    // 0x8005E808: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
L_8005E80C:
    // 0x8005E80C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005E810: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8005E814: addiu       $a2, $sp, 0x1A
    ctx->r6 = ADD32(ctx->r29, 0X1A);
    // 0x8005E818: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x8005E81C: jal         0x8005EC40
    // 0x8005E820: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_8005EC40(rdram, ctx);
        goto after_4;
    // 0x8005E820: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_4:
    // 0x8005E824: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x8005E828: lw          $v1, 0x74($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X74);
    // 0x8005E82C: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8005E830: sltiu       $v0, $s2, 0x1
    ctx->r2 = ctx->r18 < 0X1 ? 1 : 0;
    // 0x8005E834: slt         $v1, $a1, $v1
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005E838: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x8005E83C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8005E840: beq         $v1, $zero, L_8005E8B0
    if (ctx->r3 == 0) {
        // 0x8005E844: addiu       $t1, $zero, 0x7F
        ctx->r9 = ADD32(0, 0X7F);
            goto L_8005E8B0;
    }
    // 0x8005E844: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
    // 0x8005E848: lh          $v0, 0x58($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X58);
    // 0x8005E84C: lh          $v1, 0x5A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X5A);
    // 0x8005E850: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005E854: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x8005E858: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x8005E85C: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E860: mflo        $v1
    ctx->r3 = lo;
    // 0x8005E864: lh          $v0, 0x58($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X58);
    // 0x8005E868: subu        $v0, $t1, $v0
    ctx->r2 = SUB32(ctx->r9, ctx->r2);
    // 0x8005E86C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005E870: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x8005E874: sra         $v1, $v1, 15
    ctx->r3 = S32(SIGNED(ctx->r3) >> 15);
    // 0x8005E878: sh          $v1, 0x68($s0)
    MEM_H(0X68, ctx->r16) = ctx->r3;
    // 0x8005E87C: lh          $v1, 0x5A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X5A);
    // 0x8005E880: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x8005E884: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E888: mflo        $v1
    ctx->r3 = lo;
    // 0x8005E88C: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x8005E890: sra         $v1, $v1, 15
    ctx->r3 = S32(SIGNED(ctx->r3) >> 15);
    // 0x8005E894: sh          $v1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r3;
    // 0x8005E898: lhu         $v1, 0x68($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X68);
    // 0x8005E89C: lhu         $a0, 0x6E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X6E);
    // 0x8005E8A0: sw          $v0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r2;
    // 0x8005E8A4: sh          $v1, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r3;
    // 0x8005E8A8: j           L_8005E8DC
    // 0x8005E8AC: sh          $a0, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r4;
        goto L_8005E8DC;
    // 0x8005E8AC: sh          $a0, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r4;
L_8005E8B0:
    // 0x8005E8B0: lh          $a0, 0x5C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X5C);
    // 0x8005E8B4: lh          $a2, 0x66($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X66);
    // 0x8005E8B8: jal         0x8005EFA0
    // 0x8005E8BC: lhu         $a3, 0x64($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X64);
    func_8005EFA0(rdram, ctx);
        goto after_5;
    // 0x8005E8BC: lhu         $a3, 0x64($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X64);
    after_5:
    // 0x8005E8C0: lh          $a0, 0x5E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X5E);
    // 0x8005E8C4: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x8005E8C8: lh          $a2, 0x6C($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X6C);
    // 0x8005E8CC: lhu         $a3, 0x6A($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X6A);
    // 0x8005E8D0: jal         0x8005EFA0
    // 0x8005E8D4: sh          $v0, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r2;
    func_8005EFA0(rdram, ctx);
        goto after_6;
    // 0x8005E8D4: sh          $v0, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r2;
    after_6:
    // 0x8005E8D8: sh          $v0, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r2;
L_8005E8DC:
    // 0x8005E8DC: lh          $v0, 0x5C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X5C);
    // 0x8005E8E0: beql        $v0, $zero, L_8005E8E8
    if (ctx->r2 == 0) {
        // 0x8005E8E4: sh          $s4, 0x5C($s0)
        MEM_H(0X5C, ctx->r16) = ctx->r20;
            goto L_8005E8E8;
    }
    goto skip_2;
    // 0x8005E8E4: sh          $s4, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r20;
    skip_2:
L_8005E8E8:
    // 0x8005E8E8: lh          $v0, 0x5E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X5E);
    // 0x8005E8EC: beql        $v0, $zero, L_8005E8F4
    if (ctx->r2 == 0) {
        // 0x8005E8F0: sh          $s4, 0x5E($s0)
        MEM_H(0X5E, ctx->r16) = ctx->r20;
            goto L_8005E8F4;
    }
    goto skip_3;
    // 0x8005E8F0: sh          $s4, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r20;
    skip_3:
L_8005E8F4:
    // 0x8005E8F4: lw          $a0, 0x7C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7C);
    // 0x8005E8F8: lh          $v1, 0x10($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X10);
    // 0x8005E8FC: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8005E900: bne         $v1, $v0, L_8005E910
    if (ctx->r3 != ctx->r2) {
        // 0x8005E904: nop
    
            goto L_8005E910;
    }
    // 0x8005E904: nop

    // 0x8005E908: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x8005E90C: sh          $v0, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r2;
L_8005E910:
    // 0x8005E910: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x8005E914: lh          $v1, 0x10($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X10);
    // 0x8005E918: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8005E91C: bne         $v1, $v0, L_8005E984
    if (ctx->r3 != ctx->r2) {
        // 0x8005E920: nop
    
            goto L_8005E984;
    }
    // 0x8005E920: nop

    // 0x8005E924: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x8005E928: sw          $zero, 0x70($s0)
    MEM_W(0X70, ctx->r16) = 0;
    // 0x8005E92C: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x8005E930: mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E934: mflo        $v0
    ctx->r2 = lo;
    // 0x8005E938: lw          $v1, 0x7C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X7C);
    // 0x8005E93C: sra         $v0, $v0, 15
    ctx->r2 = S32(SIGNED(ctx->r2) >> 15);
    // 0x8005E940: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x8005E944: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x8005E948: lui         $v1, 0xB216
    ctx->r3 = S32(0XB216 << 16);
    // 0x8005E94C: ori         $v1, $v1, 0x42C9
    ctx->r3 = ctx->r3 | 0X42C9;
    // 0x8005E950: addiu       $v0, $v0, 0x5C
    ctx->r2 = ADD32(ctx->r2, 0X5C);
    // 0x8005E954: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E958: mfhi        $t1
    ctx->r9 = hi;
    // 0x8005E95C: addu        $v1, $t1, $v0
    ctx->r3 = ADD32(ctx->r9, ctx->r2);
    // 0x8005E960: sra         $v1, $v1, 7
    ctx->r3 = S32(SIGNED(ctx->r3) >> 7);
    // 0x8005E964: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8005E968: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005E96C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8005E970: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005E974: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005E978: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8005E97C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005E980: sw          $v0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r2;
L_8005E984:
    // 0x8005E984: lw          $a0, 0x7C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7C);
    // 0x8005E988: lh          $v1, 0x10($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X10);
    // 0x8005E98C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8005E990: bnel        $v1, $v0, L_8005EB00
    if (ctx->r3 != ctx->r2) {
        // 0x8005E994: sw          $s4, 0x78($s0)
        MEM_W(0X78, ctx->r16) = ctx->r20;
            goto L_8005EB00;
    }
    goto skip_4;
    // 0x8005E994: sw          $s4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r20;
    skip_4:
    // 0x8005E998: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x8005E99C: lw          $v1, 0x7C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X7C);
    // 0x8005E9A0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005E9A4: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x8005E9A8: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8005E9AC: sh          $v0, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r2;
    // 0x8005E9B0: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x8005E9B4: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
    // 0x8005E9B8: subu        $v0, $t1, $v0
    ctx->r2 = SUB32(ctx->r9, ctx->r2);
    // 0x8005E9BC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005E9C0: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x8005E9C4: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8005E9C8: sh          $v0, 0x62($s0)
    MEM_H(0X62, ctx->r16) = ctx->r2;
    // 0x8005E9CC: j           L_8005EB00
    // 0x8005E9D0: sw          $s4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r20;
        goto L_8005EB00;
    // 0x8005E9D0: sw          $s4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r20;
L_8005E9D4:
    // 0x8005E9D4: lw          $v1, 0x7C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X7C);
    // 0x8005E9D8: lh          $v0, 0x12($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X12);
    // 0x8005E9DC: bnel        $v0, $zero, L_8005E9E4
    if (ctx->r2 != 0) {
        // 0x8005E9E0: sw          $s4, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->r20;
            goto L_8005E9E4;
    }
    goto skip_5;
    // 0x8005E9E0: sw          $s4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r20;
    skip_5:
L_8005E9E4:
    // 0x8005E9E4: lw          $a2, 0x14($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X14);
    // 0x8005E9E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005E9EC: jal         0x8005F438
    // 0x8005E9F0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8005F438(rdram, ctx);
        goto after_7;
    // 0x8005E9F0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_7:
    // 0x8005E9F4: j           L_8005EB00
    // 0x8005E9F8: sw          $s4, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r20;
        goto L_8005EB00;
    // 0x8005E9F8: sw          $s4, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r20;
L_8005E9FC:
    // 0x8005E9FC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8005EA00: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005EA04: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8005EA08: addiu       $a2, $sp, 0x1A
    ctx->r6 = ADD32(ctx->r29, 0X1A);
    // 0x8005EA0C: jal         0x8005EC40
    // 0x8005EA10: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    func_8005EC40(rdram, ctx);
        goto after_8;
    // 0x8005EA10: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_8:
    // 0x8005EA14: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8005EA18: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005EA1C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8005EA20: j           L_8005EAF8
    // 0x8005EA24: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
        goto L_8005EAF8;
    // 0x8005EA24: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8005EA28:
    // 0x8005EA28: lw          $v1, 0x7C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X7C);
    // 0x8005EA2C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8005EA30: sw          $zero, 0x88($v0)
    MEM_W(0X88, ctx->r2) = 0;
    // 0x8005EA34: jal         0x8005DEE4
    // 0x8005EA38: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    func_8005DEE4(rdram, ctx);
        goto after_9;
    // 0x8005EA38: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    after_9:
    // 0x8005EA3C: j           L_8005EB00
    // 0x8005EA40: nop

        goto L_8005EB00;
    // 0x8005EA40: nop

L_8005EA44:
    // 0x8005EA44: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005EA48: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8005EA4C: addiu       $a2, $sp, 0x1A
    ctx->r6 = ADD32(ctx->r29, 0X1A);
    // 0x8005EA50: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x8005EA54: jal         0x8005EC40
    // 0x8005EA58: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_8005EC40(rdram, ctx);
        goto after_10;
    // 0x8005EA58: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_10:
    // 0x8005EA5C: lw          $v1, 0x7C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X7C);
    // 0x8005EA60: lwc1        $f0, 0x14($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8005EA64: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8005EA68: j           L_8005EB00
    // 0x8005EA6C: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
        goto L_8005EB00;
    // 0x8005EA6C: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
L_8005EA70:
    // 0x8005EA70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005EA74: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8005EA78: addiu       $a2, $sp, 0x1A
    ctx->r6 = ADD32(ctx->r29, 0X1A);
    // 0x8005EA7C: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x8005EA80: jal         0x8005EC40
    // 0x8005EA84: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_8005EC40(rdram, ctx);
        goto after_11;
    // 0x8005EA84: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_11:
    // 0x8005EA88: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8005EA8C: j           L_8005EB00
    // 0x8005EA90: sw          $s4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r20;
        goto L_8005EB00;
    // 0x8005EA90: sw          $s4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r20;
L_8005EA94:
    // 0x8005EA94: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005EA98: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8005EA9C: addiu       $a2, $sp, 0x1A
    ctx->r6 = ADD32(ctx->r29, 0X1A);
    // 0x8005EAA0: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x8005EAA4: jal         0x8005EC40
    // 0x8005EAA8: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_8005EC40(rdram, ctx);
        goto after_12;
    // 0x8005EAA8: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_12:
    // 0x8005EAAC: lw          $v1, 0x7C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X7C);
    // 0x8005EAB0: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8005EAB4: lw          $a2, 0x14($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X14);
    // 0x8005EAB8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005EABC: jal         0x8005F438
    // 0x8005EAC0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8005F438(rdram, ctx);
        goto after_13;
    // 0x8005EAC0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_13:
    // 0x8005EAC4: j           L_8005EB00
    // 0x8005EAC8: nop

        goto L_8005EB00;
    // 0x8005EAC8: nop

L_8005EACC:
    // 0x8005EACC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005EAD0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8005EAD4: addiu       $a2, $sp, 0x1A
    ctx->r6 = ADD32(ctx->r29, 0X1A);
    // 0x8005EAD8: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x8005EADC: jal         0x8005EC40
    // 0x8005EAE0: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_8005EC40(rdram, ctx);
        goto after_14;
    // 0x8005EAE0: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_14:
    // 0x8005EAE4: lw          $v1, 0x7C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X7C);
    // 0x8005EAE8: lh          $a1, 0x10($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X10);
    // 0x8005EAEC: lw          $a2, 0x14($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X14);
    // 0x8005EAF0: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8005EAF4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8005EAF8:
    // 0x8005EAF8: jal         0x8005EBA0
    // 0x8005EAFC: nop

    func_8005EBA0(rdram, ctx);
        goto after_15;
    // 0x8005EAFC: nop

    after_15:
L_8005EB00:
    // 0x8005EB00: lw          $a1, 0x7C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X7C);
    // 0x8005EB04: subu        $fp, $fp, $s2
    ctx->r30 = SUB32(ctx->r30, ctx->r18);
    // 0x8005EB08: lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1A);
    // 0x8005EB0C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8005EB10: sll         $v1, $s2, 1
    ctx->r3 = S32(ctx->r18 << 1);
    // 0x8005EB14: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005EB18: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x8005EB1C: bne         $a0, $zero, L_8005EB28
    if (ctx->r4 != 0) {
        // 0x8005EB20: sw          $a0, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->r4;
            goto L_8005EB28;
    }
    // 0x8005EB20: sw          $a0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r4;
    // 0x8005EB24: sw          $zero, 0x80($s0)
    MEM_W(0X80, ctx->r16) = 0;
L_8005EB28:
    // 0x8005EB28: jal         0x8005DE6C
    // 0x8005EB2C: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    func_8005DE6C(rdram, ctx);
        goto after_16;
    // 0x8005EB2C: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    after_16:
    // 0x8005EB30: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x8005EB34: bne         $v0, $zero, L_8005E5EC
    if (ctx->r2 != 0) {
        // 0x8005EB38: nop
    
            goto L_8005E5EC;
    }
    // 0x8005EB38: nop

L_8005EB3C:
    // 0x8005EB3C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8005EB40:
    // 0x8005EB40: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8005EB44: addiu       $a2, $sp, 0x1A
    ctx->r6 = ADD32(ctx->r29, 0X1A);
    // 0x8005EB48: addu        $a3, $fp, $zero
    ctx->r7 = ADD32(ctx->r30, 0);
    // 0x8005EB4C: jal         0x8005EC40
    // 0x8005EB50: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_8005EC40(rdram, ctx);
        goto after_17;
    // 0x8005EB50: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_17:
    // 0x8005EB54: lw          $v1, 0x70($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X70);
    // 0x8005EB58: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x8005EB5C: slt         $v1, $a0, $v1
    ctx->r3 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005EB60: beq         $v1, $zero, L_8005EB6C
    if (ctx->r3 == 0) {
        // 0x8005EB64: addu        $s3, $v0, $zero
        ctx->r19 = ADD32(ctx->r2, 0);
            goto L_8005EB6C;
    }
    // 0x8005EB64: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8005EB68: sw          $a0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r4;
L_8005EB6C:
    // 0x8005EB6C: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x8005EB70: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8005EB74: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8005EB78: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8005EB7C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8005EB80: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8005EB84: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8005EB88: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8005EB8C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8005EB90: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005EB94: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005EB98: jr          $ra
    // 0x8005EB9C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8005EB9C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8005EBA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EBA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005EBA4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8005EBA8: beq         $a1, $v0, L_8005EBF8
    if (ctx->r5 == ctx->r2) {
        // 0x8005EBAC: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8005EBF8;
    }
    // 0x8005EBAC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005EBB0: slti        $v0, $a1, 0x5
    ctx->r2 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x8005EBB4: beq         $v0, $zero, L_8005EBCC
    if (ctx->r2 == 0) {
        // 0x8005EBB8: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8005EBCC;
    }
    // 0x8005EBB8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8005EBBC: beq         $a1, $v0, L_8005EBE0
    if (ctx->r5 == ctx->r2) {
        // 0x8005EBC0: nop
    
            goto L_8005EBE0;
    }
    // 0x8005EBC0: nop

    // 0x8005EBC4: j           L_8005EC28
    // 0x8005EBC8: nop

        goto L_8005EC28;
    // 0x8005EBC8: nop

L_8005EBCC:
    // 0x8005EBCC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8005EBD0: beql        $a1, $v0, L_8005EC20
    if (ctx->r5 == ctx->r2) {
        // 0x8005EBD4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005EC20;
    }
    goto skip_0;
    // 0x8005EBD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8005EBD8: j           L_8005EC28
    // 0x8005EBDC: nop

        goto L_8005EC28;
    // 0x8005EBDC: nop

L_8005EBE0:
    // 0x8005EBE0: lw          $v0, 0x80($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X80);
    // 0x8005EBE4: beql        $v0, $zero, L_8005EBF0
    if (ctx->r2 == 0) {
        // 0x8005EBE8: sw          $a2, 0x7C($a0)
        MEM_W(0X7C, ctx->r4) = ctx->r6;
            goto L_8005EBF0;
    }
    goto skip_1;
    // 0x8005EBE8: sw          $a2, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r6;
    skip_1:
    // 0x8005EBEC: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
L_8005EBF0:
    // 0x8005EBF0: j           L_8005EC30
    // 0x8005EBF4: sw          $a2, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->r6;
        goto L_8005EC30;
    // 0x8005EBF4: sw          $a2, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->r6;
L_8005EBF8:
    // 0x8005EBF8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8005EBFC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005EC00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005EC04: sw          $v1, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r3;
    // 0x8005EC08: sw          $zero, 0x84($a0)
    MEM_W(0X84, ctx->r4) = 0;
    // 0x8005EC0C: sh          $v0, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r2;
    // 0x8005EC10: sw          $zero, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = 0;
    // 0x8005EC14: sw          $v1, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r3;
    // 0x8005EC18: j           L_8005EC28
    // 0x8005EC1C: sw          $zero, 0x48($a0)
    MEM_W(0X48, ctx->r4) = 0;
        goto L_8005EC28;
    // 0x8005EC1C: sw          $zero, 0x48($a0)
    MEM_W(0X48, ctx->r4) = 0;
L_8005EC20:
    // 0x8005EC20: j           L_8005EC30
    // 0x8005EC24: sw          $v0, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r2;
        goto L_8005EC30;
    // 0x8005EC24: sw          $v0, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r2;
L_8005EC28:
    // 0x8005EC28: jal         0x8005F438
    // 0x8005EC2C: nop

    func_8005F438(rdram, ctx);
        goto after_0;
    // 0x8005EC2C: nop

    after_0:
L_8005EC30:
    // 0x8005EC30: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005EC34: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8005EC38: jr          $ra
    // 0x8005EC3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005EC3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005EC40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EC40: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005EC44: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8005EC48: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8005EC4C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8005EC50: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8005EC54: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8005EC58: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005EC5C: lw          $v0, 0x84($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X84);
    // 0x8005EC60: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8005EC64: sltiu       $a3, $a3, 0x1
    ctx->r7 = ctx->r7 < 0X1 ? 1 : 0;
    // 0x8005EC68: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8005EC6C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8005EC70: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
    // 0x8005EC74: beq         $v0, $zero, L_8005EC84
    if (ctx->r2 == 0) {
        // 0x8005EC78: addu        $s3, $a1, $zero
        ctx->r19 = ADD32(ctx->r5, 0);
            goto L_8005EC84;
    }
    // 0x8005EC78: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x8005EC7C: j           L_8005EE44
    // 0x8005EC80: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
        goto L_8005EE44;
    // 0x8005EC80: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_8005EC84:
    // 0x8005EC84: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005EC88: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8005EC8C: jal         0x8005F710
    // 0x8005EC90: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_8005F710(rdram, ctx);
        goto after_0;
    // 0x8005EC90: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_0:
    // 0x8005EC94: lw          $v1, 0x78($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X78);
    // 0x8005EC98: beq         $v1, $zero, L_8005EE0C
    if (ctx->r3 == 0) {
        // 0x8005EC9C: addu        $s2, $v0, $zero
        ctx->r18 = ADD32(ctx->r2, 0);
            goto L_8005EE0C;
    }
    // 0x8005EC9C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8005ECA0: lh          $v0, 0x58($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X58);
    // 0x8005ECA4: lh          $v1, 0x5A($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X5A);
    // 0x8005ECA8: sw          $zero, 0x78($s1)
    MEM_W(0X78, ctx->r17) = 0;
    // 0x8005ECAC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005ECB0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8005ECB4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005ECB8: lh          $v0, 0x6250($at)
    ctx->r2 = MEM_H(ctx->r1, 0X6250);
    // 0x8005ECBC: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005ECC0: mflo        $v1
    ctx->r3 = lo;
    // 0x8005ECC4: lh          $v0, 0x5C($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X5C);
    // 0x8005ECC8: lw          $a0, 0x74($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X74);
    // 0x8005ECCC: mtc1        $v0, $f12
    ctx->f12.u32l = ctx->r2;
    // 0x8005ECD0: nop

    // 0x8005ECD4: cvt.d.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.d = CVT_D_W(ctx->f12.u32l);
    // 0x8005ECD8: sra         $v1, $v1, 15
    ctx->r3 = S32(SIGNED(ctx->r3) >> 15);
    // 0x8005ECDC: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8005ECE0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005ECE4: mtc1        $v0, $f14
    ctx->f14.u32l = ctx->r2;
    // 0x8005ECE8: nop

    // 0x8005ECEC: cvt.d.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.d = CVT_D_W(ctx->f14.u32l);
    // 0x8005ECF0: addiu       $v0, $s1, 0x64
    ctx->r2 = ADD32(ctx->r17, 0X64);
    // 0x8005ECF4: sh          $v1, 0x68($s1)
    MEM_H(0X68, ctx->r17) = ctx->r3;
    // 0x8005ECF8: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x8005ECFC: jal         0x8005EE60
    // 0x8005ED00: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_8005EE60(rdram, ctx);
        goto after_1;
    // 0x8005ED00: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_1:
    // 0x8005ED04: lh          $a0, 0x58($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X58);
    // 0x8005ED08: lh          $v1, 0x5A($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X5A);
    // 0x8005ED0C: sh          $v0, 0x66($s1)
    MEM_H(0X66, ctx->r17) = ctx->r2;
    // 0x8005ED10: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8005ED14: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8005ED18: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005ED1C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8005ED20: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005ED24: lh          $v0, 0x6250($at)
    ctx->r2 = MEM_H(ctx->r1, 0X6250);
    // 0x8005ED28: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005ED2C: mflo        $v1
    ctx->r3 = lo;
    // 0x8005ED30: lh          $v0, 0x5E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X5E);
    // 0x8005ED34: lw          $a0, 0x74($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X74);
    // 0x8005ED38: mtc1        $v0, $f12
    ctx->f12.u32l = ctx->r2;
    // 0x8005ED3C: nop

    // 0x8005ED40: cvt.d.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.d = CVT_D_W(ctx->f12.u32l);
    // 0x8005ED44: sra         $v1, $v1, 15
    ctx->r3 = S32(SIGNED(ctx->r3) >> 15);
    // 0x8005ED48: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8005ED4C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005ED50: mtc1        $v0, $f14
    ctx->f14.u32l = ctx->r2;
    // 0x8005ED54: nop

    // 0x8005ED58: cvt.d.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.d = CVT_D_W(ctx->f14.u32l);
    // 0x8005ED5C: addiu       $v0, $s1, 0x6A
    ctx->r2 = ADD32(ctx->r17, 0X6A);
    // 0x8005ED60: sh          $v1, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r3;
    // 0x8005ED64: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x8005ED68: jal         0x8005EE60
    // 0x8005ED6C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_8005EE60(rdram, ctx);
        goto after_2;
    // 0x8005ED6C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_2:
    // 0x8005ED70: sh          $v0, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r2;
    // 0x8005ED74: lhu         $v0, 0x68($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X68);
    // 0x8005ED78: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8005ED7C: lui         $v1, 0x900
    ctx->r3 = S32(0X900 << 16);
    // 0x8005ED80: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005ED84: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8005ED88: lhu         $v0, 0x66($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X66);
    // 0x8005ED8C: lhu         $v1, 0x64($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X64);
    // 0x8005ED90: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8005ED94: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8005ED98: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005ED9C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8005EDA0: lhu         $v0, 0x5C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X5C);
    // 0x8005EDA4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8005EDA8: lui         $v1, 0x906
    ctx->r3 = S32(0X906 << 16);
    // 0x8005EDAC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005EDB0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8005EDB4: lhu         $v0, 0x60($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X60);
    // 0x8005EDB8: lhu         $v1, 0x62($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X62);
    // 0x8005EDBC: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8005EDC0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8005EDC4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005EDC8: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8005EDCC: lhu         $v0, 0x6E($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X6E);
    // 0x8005EDD0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8005EDD4: lui         $v1, 0x904
    ctx->r3 = S32(0X904 << 16);
    // 0x8005EDD8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005EDDC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8005EDE0: lhu         $v0, 0x6C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X6C);
    // 0x8005EDE4: lhu         $v1, 0x6A($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X6A);
    // 0x8005EDE8: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8005EDEC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8005EDF0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005EDF4: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8005EDF8: lhu         $v0, 0x5E($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X5E);
    // 0x8005EDFC: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
    // 0x8005EE00: lui         $v1, 0x301
    ctx->r3 = S32(0X301 << 16);
    // 0x8005EE04: j           L_8005EE14
    // 0x8005EE08: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
        goto L_8005EE14;
    // 0x8005EE08: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
L_8005EE0C:
    // 0x8005EE0C: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
    // 0x8005EE10: lui         $v0, 0x300
    ctx->r2 = S32(0X300 << 16);
L_8005EE14:
    // 0x8005EE14: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8005EE18: lw          $a0, 0x54($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X54);
    // 0x8005EE1C: jal         0x80062180
    // 0x8005EE20: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x8005EE20: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    after_3:
    // 0x8005EE24: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8005EE28: lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X0);
    // 0x8005EE2C: addiu       $v0, $v0, 0x170
    ctx->r2 = ADD32(ctx->r2, 0X170);
    // 0x8005EE30: sh          $v0, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r2;
    // 0x8005EE34: lw          $v1, 0x70($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X70);
    // 0x8005EE38: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x8005EE3C: addiu       $v1, $v1, 0xB8
    ctx->r3 = ADD32(ctx->r3, 0XB8);
    // 0x8005EE40: sw          $v1, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->r3;
L_8005EE44:
    // 0x8005EE44: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8005EE48: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8005EE4C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8005EE50: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005EE54: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005EE58: jr          $ra
    // 0x8005EE5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005EE5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8005EE60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EE60: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x8005EE64: bne         $v0, $zero, L_8005EE98
    if (ctx->r2 != 0) {
        // 0x8005EE68: lw          $a1, 0x14($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X14);
            goto L_8005EE98;
    }
    // 0x8005EE68: lw          $a1, 0x14($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14);
    // 0x8005EE6C: c.le.d      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.d <= ctx->f14.d;
    // 0x8005EE70: nop

    // 0x8005EE74: nop

    // 0x8005EE78: bc1f        L_8005EE8C
    if (!c1cs) {
        // 0x8005EE7C: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_8005EE8C;
    }
    // 0x8005EE7C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005EE80: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8005EE84: j           L_8005EF98
    // 0x8005EE88: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
        goto L_8005EF98;
    // 0x8005EE88: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
L_8005EE8C:
    // 0x8005EE8C: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x8005EE90: j           L_8005EF98
    // 0x8005EE94: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8005EF98;
    // 0x8005EE94: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005EE98:
    // 0x8005EE98: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005EE9C: ldc1        $f4, -0x1128($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X1128);
    // 0x8005EEA0: c.lt.d      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.d < ctx->f4.d;
    // 0x8005EEA4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8005EEA8: nop

    // 0x8005EEAC: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x8005EEB0: bc1f        L_8005EEBC
    if (!c1cs) {
        // 0x8005EEB4: div.d       $f2, $f4, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = DIV_D(ctx->f4.d, ctx->f0.d);
            goto L_8005EEBC;
    }
    // 0x8005EEB4: div.d       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x8005EEB8: mov.d       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.d = ctx->f4.d;
L_8005EEBC:
    // 0x8005EEBC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005EEC0: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x8005EEC4: nop

    // 0x8005EEC8: c.le.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d <= ctx->f0.d;
    // 0x8005EECC: nop

    // 0x8005EED0: nop

    // 0x8005EED4: bc1tl       L_8005EEDC
    if (c1cs) {
        // 0x8005EED8: mov.d       $f12, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.d = ctx->f4.d;
            goto L_8005EEDC;
    }
    goto skip_0;
    // 0x8005EED8: mov.d       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.d = ctx->f4.d;
    skip_0:
L_8005EEDC:
    // 0x8005EEDC: sub.d       $f0, $f14, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = ctx->f14.d - ctx->f12.d;
    // 0x8005EEE0: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8005EEE4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005EEE8: ldc1        $f2, -0x1120($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1120);
    // 0x8005EEEC: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8005EEF0: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8005EEF4: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8005EEF8: nop

    // 0x8005EEFC: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8005EF00: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005EF04: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8005EF08: nop

    // 0x8005EF0C: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x8005EF10: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8005EF14: add.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f0.d + ctx->f4.d;
    // 0x8005EF18: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8005EF1C: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8005EF20: nop

    // 0x8005EF24: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x8005EF28: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005EF2C: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8005EF30: nop

    // 0x8005EF34: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x8005EF38: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8005EF3C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005EF40: ldc1        $f2, -0x1118($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1118);
    // 0x8005EF44: mul.d       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8005EF48: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005EF4C: ldc1        $f0, -0x1110($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1110);
    // 0x8005EF50: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x8005EF54: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8005EF58: nop

    // 0x8005EF5C: bc1t        L_8005EF78
    if (c1cs) {
        // 0x8005EF60: addu        $v1, $v1, $a0
        ctx->r3 = ADD32(ctx->r3, ctx->r4);
            goto L_8005EF78;
    }
    // 0x8005EF60: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8005EF64: trunc.w.d   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x8005EF68: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x8005EF6C: nop

    // 0x8005EF70: j           L_8005EF90
    // 0x8005EF74: sh          $a0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r4;
        goto L_8005EF90;
    // 0x8005EF74: sh          $a0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r4;
L_8005EF78:
    // 0x8005EF78: sub.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
    // 0x8005EF7C: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8005EF80: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8005EF84: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8005EF88: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x8005EF8C: sh          $a0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r4;
L_8005EF90:
    // 0x8005EF90: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8005EF94: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_8005EF98:
    // 0x8005EF98: jr          $ra
    // 0x8005EF9C: nop

    return;
    // 0x8005EF9C: nop

;}
RECOMP_FUNC void func_8005EFA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EFA0: sra         $a1, $a1, 3
    ctx->r5 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8005EFA4: beq         $a1, $zero, L_8005EFDC
    if (ctx->r5 == 0) {
        // 0x8005EFA8: sll         $v1, $a2, 16
        ctx->r3 = S32(ctx->r6 << 16);
            goto L_8005EFDC;
    }
    // 0x8005EFA8: sll         $v1, $a2, 16
    ctx->r3 = S32(ctx->r6 << 16);
    // 0x8005EFAC: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8005EFB0: mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005EFB4: mflo        $v0
    ctx->r2 = lo;
    // 0x8005EFB8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8005EFBC: nop

    // 0x8005EFC0: mult        $v1, $a1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005EFC4: mflo        $v1
    ctx->r3 = lo;
    // 0x8005EFC8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005EFCC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005EFD0: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x8005EFD4: j           L_8005EFE0
    // 0x8005EFD8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
        goto L_8005EFE0;
    // 0x8005EFD8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
L_8005EFDC:
    // 0x8005EFDC: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
L_8005EFE0:
    // 0x8005EFE0: jr          $ra
    // 0x8005EFE4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x8005EFE4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
;}
RECOMP_FUNC void func_8005EFF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EFF0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8005EFF4: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8005EFF8: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x8005EFFC: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8005F000: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x8005F004: addu        $t0, $a3, $zero
    ctx->r8 = ADD32(ctx->r7, 0);
    // 0x8005F008: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8005F00C: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // 0x8005F010: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x8005F014: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8005F018: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8005F01C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8005F020: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8005F024: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8005F028: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8005F02C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8005F030: beq         $s4, $zero, L_8005F404
    if (ctx->r20 == 0) {
        // 0x8005F034: sw          $s1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r17;
            goto L_8005F404;
    }
    // 0x8005F034: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8005F038: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8005F03C: lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // 0x8005F040: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x8005F044: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8005F048: lui         $v1, 0xB00
    ctx->r3 = S32(0XB00 << 16);
    // 0x8005F04C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005F050: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8005F054: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x8005F058: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8005F05C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005F060: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x8005F064: lui         $v1, 0x1FFF
    ctx->r3 = S32(0X1FFF << 16);
    // 0x8005F068: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x8005F06C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8005F070: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8005F074: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8005F078: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x8005F07C: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
    // 0x8005F080: addu        $v0, $s4, $a1
    ctx->r2 = ADD32(ctx->r20, ctx->r5);
    // 0x8005F084: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8005F088: beq         $v0, $zero, L_8005F098
    if (ctx->r2 == 0) {
        // 0x8005F08C: addu        $s7, $zero, $zero
        ctx->r23 = ADD32(0, 0);
            goto L_8005F098;
    }
    // 0x8005F08C: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // 0x8005F090: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x8005F094: sltu        $a0, $zero, $v0
    ctx->r4 = 0 < ctx->r2 ? 1 : 0;
L_8005F098:
    // 0x8005F098: beq         $a0, $zero, L_8005F0A4
    if (ctx->r4 == 0) {
        // 0x8005F09C: addu        $s1, $s4, $zero
        ctx->r17 = ADD32(ctx->r20, 0);
            goto L_8005F0A4;
    }
    // 0x8005F09C: addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
    // 0x8005F0A0: subu        $s1, $v1, $a1
    ctx->r17 = SUB32(ctx->r3, ctx->r5);
L_8005F0A4:
    // 0x8005F0A4: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x8005F0A8: beq         $v1, $zero, L_8005F0B8
    if (ctx->r3 == 0) {
        // 0x8005F0AC: addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
            goto L_8005F0B8;
    }
    // 0x8005F0AC: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8005F0B0: j           L_8005F0BC
    // 0x8005F0B4: subu        $s6, $v0, $v1
    ctx->r22 = SUB32(ctx->r2, ctx->r3);
        goto L_8005F0BC;
    // 0x8005F0B4: subu        $s6, $v0, $v1
    ctx->r22 = SUB32(ctx->r2, ctx->r3);
L_8005F0B8:
    // 0x8005F0B8: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
L_8005F0BC:
    // 0x8005F0BC: subu        $a2, $s1, $s6
    ctx->r6 = SUB32(ctx->r17, ctx->r22);
    // 0x8005F0C0: nor         $v0, $zero, $a2
    ctx->r2 = ~(0 | ctx->r6);
    // 0x8005F0C4: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8005F0C8: and         $a2, $a2, $v0
    ctx->r6 = ctx->r6 & ctx->r2;
    // 0x8005F0CC: addiu       $v0, $a2, 0xF
    ctx->r2 = ADD32(ctx->r6, 0XF);
    // 0x8005F0D0: sra         $s2, $v0, 4
    ctx->r18 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8005F0D4: sll         $t1, $s2, 3
    ctx->r9 = S32(ctx->r18 << 3);
    // 0x8005F0D8: beq         $a0, $zero, L_8005F2A8
    if (ctx->r4 == 0) {
        // 0x8005F0DC: addu        $a3, $t1, $s2
        ctx->r7 = ADD32(ctx->r9, ctx->r18);
            goto L_8005F2A8;
    }
    // 0x8005F0DC: addu        $a3, $t1, $s2
    ctx->r7 = ADD32(ctx->r9, ctx->r18);
    // 0x8005F0E0: lh          $v0, 0x0($s5)
    ctx->r2 = MEM_H(ctx->r21, 0X0);
    // 0x8005F0E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8005F0E8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005F0EC: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x8005F0F0: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x8005F0F4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8005F0F8: jal         0x8005F5C4
    // 0x8005F0FC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_8005F5C4(rdram, ctx);
        goto after_0;
    // 0x8005F0FC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x8005F100: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x8005F104: beq         $v1, $zero, L_8005F11C
    if (ctx->r3 == 0) {
        // 0x8005F108: addu        $t0, $v0, $zero
        ctx->r8 = ADD32(ctx->r2, 0);
            goto L_8005F11C;
    }
    // 0x8005F108: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8005F10C: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x8005F110: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8005F114: j           L_8005F124
    // 0x8005F118: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
        goto L_8005F124;
    // 0x8005F118: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8005F11C:
    // 0x8005F11C: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x8005F120: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
L_8005F124:
    // 0x8005F124: sh          $v0, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r2;
    // 0x8005F128: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x8005F12C: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x8005F130: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x8005F134: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8005F138: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x8005F13C: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x8005F140: srl         $v1, $v1, 4
    ctx->r3 = S32(U32(ctx->r3) >> 4);
    // 0x8005F144: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005F148: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8005F14C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x8005F150: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005F154: sw          $a1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r5;
    // 0x8005F158: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8005F15C: sw          $a0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r4;
    // 0x8005F160: lh          $s3, 0x0($s5)
    ctx->r19 = MEM_H(ctx->r21, 0X0);
    // 0x8005F164: slt         $v0, $s1, $s4
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8005F168: beq         $v0, $zero, L_8005F270
    if (ctx->r2 == 0) {
        // 0x8005F16C: sll         $v0, $s7, 16
        ctx->r2 = S32(ctx->r23 << 16);
            goto L_8005F270;
    }
    // 0x8005F16C: sll         $v0, $s7, 16
    ctx->r2 = S32(ctx->r23 << 16);
    // 0x8005F170: sra         $s6, $v0, 16
    ctx->r22 = S32(SIGNED(ctx->r2) >> 16);
L_8005F174:
    // 0x8005F174: addiu       $v0, $s2, 0x1
    ctx->r2 = ADD32(ctx->r18, 0X1);
    // 0x8005F178: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8005F17C: addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // 0x8005F180: sll         $v1, $s1, 1
    ctx->r3 = S32(ctx->r17 << 1);
    // 0x8005F184: addu        $s3, $s3, $v1
    ctx->r19 = ADD32(ctx->r19, ctx->r3);
    // 0x8005F188: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8005F18C: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x8005F190: addiu       $v1, $zero, -0x20
    ctx->r3 = ADD32(0, -0X20);
    // 0x8005F194: and         $s5, $v0, $v1
    ctx->r21 = ctx->r2 & ctx->r3;
    // 0x8005F198: nor         $v0, $zero, $a0
    ctx->r2 = ~(0 | ctx->r4);
    // 0x8005F19C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8005F1A0: sltu        $v1, $zero, $a0
    ctx->r3 = 0 < ctx->r4 ? 1 : 0;
    // 0x8005F1A4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8005F1A8: beq         $v0, $zero, L_8005F1B8
    if (ctx->r2 == 0) {
        // 0x8005F1AC: subu        $s4, $s4, $s1
        ctx->r20 = SUB32(ctx->r20, ctx->r17);
            goto L_8005F1B8;
    }
    // 0x8005F1AC: subu        $s4, $s4, $s1
    ctx->r20 = SUB32(ctx->r20, ctx->r17);
    // 0x8005F1B0: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x8005F1B4: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
L_8005F1B8:
    // 0x8005F1B8: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
    // 0x8005F1BC: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x8005F1C0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005F1C4: sltu        $v0, $s4, $v1
    ctx->r2 = ctx->r20 < ctx->r3 ? 1 : 0;
    // 0x8005F1C8: bne         $v0, $zero, L_8005F1D4
    if (ctx->r2 != 0) {
        // 0x8005F1CC: addu        $s1, $s4, $zero
        ctx->r17 = ADD32(ctx->r20, 0);
            goto L_8005F1D4;
    }
    // 0x8005F1CC: addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
    // 0x8005F1D0: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
L_8005F1D4:
    // 0x8005F1D4: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x8005F1D8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8005F1DC: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x8005F1E0: sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21 << 16);
    // 0x8005F1E4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005F1E8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005F1EC: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x8005F1F0: addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // 0x8005F1F4: addu        $a2, $s1, $v1
    ctx->r6 = ADD32(ctx->r17, ctx->r3);
    // 0x8005F1F8: nor         $v0, $zero, $a2
    ctx->r2 = ~(0 | ctx->r6);
    // 0x8005F1FC: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8005F200: and         $a2, $a2, $v0
    ctx->r6 = ctx->r6 & ctx->r2;
    // 0x8005F204: addiu       $v0, $a2, 0xF
    ctx->r2 = ADD32(ctx->r6, 0XF);
    // 0x8005F208: sra         $s2, $v0, 4
    ctx->r18 = S32(SIGNED(ctx->r2) >> 4);
    // 0x8005F20C: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x8005F210: sll         $a3, $s2, 3
    ctx->r7 = S32(ctx->r18 << 3);
    // 0x8005F214: addu        $a3, $a3, $s2
    ctx->r7 = ADD32(ctx->r7, ctx->r18);
    // 0x8005F218: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x8005F21C: jal         0x8005F5C4
    // 0x8005F220: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_8005F5C4(rdram, ctx);
        goto after_1;
    // 0x8005F220: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x8005F224: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8005F228: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x8005F22C: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8005F230: lui         $a2, 0xFF
    ctx->r6 = S32(0XFF << 16);
    // 0x8005F234: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x8005F238: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x8005F23C: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x8005F240: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x8005F244: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005F248: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x8005F24C: lui         $v0, 0xA00
    ctx->r2 = S32(0XA00 << 16);
    // 0x8005F250: sw          $a0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r4;
    // 0x8005F254: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8005F258: addu        $v1, $s5, $v1
    ctx->r3 = ADD32(ctx->r21, ctx->r3);
    // 0x8005F25C: and         $v1, $v1, $a2
    ctx->r3 = ctx->r3 & ctx->r6;
    // 0x8005F260: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8005F264: slt         $v0, $s1, $s4
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8005F268: bne         $v0, $zero, L_8005F174
    if (ctx->r2 != 0) {
        // 0x8005F26C: sw          $v1, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r3;
            goto L_8005F174;
    }
    // 0x8005F26C: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
L_8005F270:
    // 0x8005F270: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x8005F274: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x8005F278: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    // 0x8005F27C: addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
    // 0x8005F280: sw          $a0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r4;
    // 0x8005F284: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8005F288: addu        $v1, $s4, $v1
    ctx->r3 = ADD32(ctx->r20, ctx->r3);
    // 0x8005F28C: andi        $v1, $v1, 0xF
    ctx->r3 = ctx->r3 & 0XF;
    // 0x8005F290: sw          $v1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r3;
    // 0x8005F294: sll         $v1, $s2, 3
    ctx->r3 = S32(ctx->r18 << 3);
    // 0x8005F298: addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // 0x8005F29C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8005F2A0: j           L_8005F408
    // 0x8005F2A4: sw          $a0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r4;
        goto L_8005F408;
    // 0x8005F2A4: sw          $a0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r4;
L_8005F2A8:
    // 0x8005F2A8: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x8005F2AC: lui         $a1, 0x38E3
    ctx->r5 = S32(0X38E3 << 16);
    // 0x8005F2B0: lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X3C);
    // 0x8005F2B4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005F2B8: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    // 0x8005F2BC: ori         $a1, $a1, 0x8E39
    ctx->r5 = ctx->r5 | 0X8E39;
    // 0x8005F2C0: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x8005F2C4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8005F2C8: subu        $a0, $v1, $v0
    ctx->r4 = SUB32(ctx->r3, ctx->r2);
    // 0x8005F2CC: nor         $v0, $zero, $a0
    ctx->r2 = ~(0 | ctx->r4);
    // 0x8005F2D0: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8005F2D4: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // 0x8005F2D8: mult        $a0, $a1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005F2DC: sll         $s1, $s2, 4
    ctx->r17 = S32(ctx->r18 << 4);
    // 0x8005F2E0: sra         $v1, $a0, 31
    ctx->r3 = S32(SIGNED(ctx->r4) >> 31);
    // 0x8005F2E4: mfhi        $t2
    ctx->r10 = hi;
    // 0x8005F2E8: sra         $v0, $t2, 1
    ctx->r2 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8005F2EC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8005F2F0: sll         $s3, $v0, 4
    ctx->r19 = S32(ctx->r2 << 4);
    // 0x8005F2F4: addu        $v1, $s1, $s6
    ctx->r3 = ADD32(ctx->r17, ctx->r22);
    // 0x8005F2F8: slt         $v0, $v1, $s3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8005F2FC: bnel        $v0, $zero, L_8005F304
    if (ctx->r2 != 0) {
        // 0x8005F300: addu        $s3, $v1, $zero
        ctx->r19 = ADD32(ctx->r3, 0);
            goto L_8005F304;
    }
    goto skip_0;
    // 0x8005F300: addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    skip_0:
L_8005F304:
    // 0x8005F304: andi        $v0, $s3, 0xF
    ctx->r2 = ctx->r19 & 0XF;
    // 0x8005F308: subu        $v0, $s3, $v0
    ctx->r2 = SUB32(ctx->r19, ctx->r2);
    // 0x8005F30C: slt         $v0, $v0, $s4
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8005F310: beq         $v0, $zero, L_8005F39C
    if (ctx->r2 == 0) {
        // 0x8005F314: subu        $a3, $a3, $a0
        ctx->r7 = SUB32(ctx->r7, ctx->r4);
            goto L_8005F39C;
    }
    // 0x8005F314: subu        $a3, $a3, $a0
    ctx->r7 = SUB32(ctx->r7, ctx->r4);
    // 0x8005F318: lh          $v0, 0x0($s5)
    ctx->r2 = MEM_H(ctx->r21, 0X0);
    // 0x8005F31C: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x8005F320: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8005F324: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8005F328: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x8005F32C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8005F330: subu        $a2, $s1, $s3
    ctx->r6 = SUB32(ctx->r17, ctx->r19);
    // 0x8005F334: jal         0x8005F5C4
    // 0x8005F338: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_8005F5C4(rdram, ctx);
        goto after_2;
    // 0x8005F338: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x8005F33C: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x8005F340: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8005F344: beq         $v1, $zero, L_8005F35C
    if (ctx->r3 == 0) {
        // 0x8005F348: addu        $t0, $v0, $zero
        ctx->r8 = ADD32(ctx->r2, 0);
            goto L_8005F35C;
    }
    // 0x8005F348: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8005F34C: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x8005F350: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8005F354: j           L_8005F364
    // 0x8005F358: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
        goto L_8005F364;
    // 0x8005F358: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8005F35C:
    // 0x8005F35C: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x8005F360: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
L_8005F364:
    // 0x8005F364: sh          $v0, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r2;
    // 0x8005F368: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x8005F36C: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x8005F370: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x8005F374: sw          $v1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r3;
    // 0x8005F378: lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X3C);
    // 0x8005F37C: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x8005F380: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8005F384: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x8005F388: sll         $v0, $s2, 3
    ctx->r2 = S32(ctx->r18 << 3);
    // 0x8005F38C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8005F390: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005F394: j           L_8005F3B0
    // 0x8005F398: sw          $v1, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r3;
        goto L_8005F3B0;
    // 0x8005F398: sw          $v1, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r3;
L_8005F39C:
    // 0x8005F39C: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x8005F3A0: addu        $v1, $t1, $s2
    ctx->r3 = ADD32(ctx->r9, ctx->r18);
    // 0x8005F3A4: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x8005F3A8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005F3AC: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
L_8005F3B0:
    // 0x8005F3B0: beq         $s3, $zero, L_8005F408
    if (ctx->r19 == 0) {
        // 0x8005F3B4: addu        $v0, $t0, $zero
        ctx->r2 = ADD32(ctx->r8, 0);
            goto L_8005F408;
    }
    // 0x8005F3B4: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    // 0x8005F3B8: beq         $fp, $zero, L_8005F3D0
    if (ctx->r30 == 0) {
        // 0x8005F3BC: sw          $zero, 0x34($s0)
        MEM_W(0X34, ctx->r16) = 0;
            goto L_8005F3D0;
    }
    // 0x8005F3BC: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x8005F3C0: addu        $v0, $s6, $s1
    ctx->r2 = ADD32(ctx->r22, ctx->r17);
    // 0x8005F3C4: subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // 0x8005F3C8: j           L_8005F3D4
    // 0x8005F3CC: sll         $a2, $v0, 1
    ctx->r6 = S32(ctx->r2 << 1);
        goto L_8005F3D4;
    // 0x8005F3CC: sll         $a2, $v0, 1
    ctx->r6 = S32(ctx->r2 << 1);
L_8005F3D0:
    // 0x8005F3D0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8005F3D4:
    // 0x8005F3D4: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x8005F3D8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8005F3DC: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x8005F3E0: lh          $v0, 0x0($s5)
    ctx->r2 = MEM_H(ctx->r21, 0X0);
    // 0x8005F3E4: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x8005F3E8: sll         $v1, $s3, 1
    ctx->r3 = S32(ctx->r19 << 1);
    // 0x8005F3EC: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // 0x8005F3F0: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x8005F3F4: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x8005F3F8: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x8005F3FC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005F400: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_8005F404:
    // 0x8005F404: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
L_8005F408:
    // 0x8005F408: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8005F40C: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8005F410: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8005F414: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8005F418: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8005F41C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8005F420: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8005F424: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8005F428: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8005F42C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8005F430: jr          $ra
    // 0x8005F434: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8005F434: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8005F438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F438: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F43C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005F440: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8005F444: beq         $a1, $v0, L_8005F56C
    if (ctx->r5 == ctx->r2) {
        // 0x8005F448: addu        $a3, $a0, $zero
        ctx->r7 = ADD32(ctx->r4, 0);
            goto L_8005F56C;
    }
    // 0x8005F448: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x8005F44C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8005F450: bne         $a1, $v0, L_8005F5B8
    if (ctx->r5 != ctx->r2) {
        // 0x8005F454: nop
    
            goto L_8005F5B8;
    }
    // 0x8005F454: nop

    // 0x8005F458: sw          $a2, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r6;
    // 0x8005F45C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8005F460: lw          $a0, 0x20($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X20);
    // 0x8005F464: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
    // 0x8005F468: sw          $v0, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r2;
    // 0x8005F46C: lbu         $v1, 0x8($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X8);
    // 0x8005F470: beq         $v1, $zero, L_8005F488
    if (ctx->r3 == 0) {
        // 0x8005F474: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005F488;
    }
    // 0x8005F474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005F478: beq         $v1, $v0, L_8005F52C
    if (ctx->r3 == ctx->r2) {
        // 0x8005F47C: nop
    
            goto L_8005F52C;
    }
    // 0x8005F47C: nop

    // 0x8005F480: j           L_8005F5B8
    // 0x8005F484: nop

        goto L_8005F5B8;
    // 0x8005F484: nop

L_8005F488:
    // 0x8005F488: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8005F48C: lui         $v1, 0x38E3
    ctx->r3 = S32(0X38E3 << 16);
    // 0x8005F490: ori         $v1, $v1, 0x8E39
    ctx->r3 = ctx->r3 | 0X8E39;
    // 0x8005F494: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005F498: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8005F49C: mfhi        $t0
    ctx->r8 = hi;
    // 0x8005F4A0: sra         $v1, $t0, 1
    ctx->r3 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8005F4A4: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005F4A8: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x8005F4AC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005F4B0: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8005F4B4: lw          $v0, 0x20($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X20);
    // 0x8005F4B8: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x8005F4BC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8005F4C0: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8005F4C4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005F4C8: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005F4CC: mflo        $v1
    ctx->r3 = lo;
    // 0x8005F4D0: lw          $v0, 0x20($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X20);
    // 0x8005F4D4: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8005F4D8: sw          $v1, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r3;
    // 0x8005F4DC: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x8005F4E0: beq         $v0, $zero, L_8005F55C
    if (ctx->r2 == 0) {
        // 0x8005F4E4: addiu       $a2, $zero, 0x20
        ctx->r6 = ADD32(0, 0X20);
            goto L_8005F55C;
    }
    // 0x8005F4E4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8005F4E8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8005F4EC: lw          $v1, 0x20($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X20);
    // 0x8005F4F0: sw          $v0, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r2;
    // 0x8005F4F4: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8005F4F8: lw          $v1, 0x20($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X20);
    // 0x8005F4FC: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x8005F500: sw          $v0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r2;
    // 0x8005F504: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8005F508: lw          $v1, 0x20($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X20);
    // 0x8005F50C: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x8005F510: sw          $v0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r2;
    // 0x8005F514: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x8005F518: lw          $a1, 0x10($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X10);
    // 0x8005F51C: jal         0x80065600
    // 0x8005F520: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_80065600(rdram, ctx);
        goto after_0;
    // 0x8005F520: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x8005F524: j           L_8005F5B8
    // 0x8005F528: nop

        goto L_8005F5B8;
    // 0x8005F528: nop

L_8005F52C:
    // 0x8005F52C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8005F530: beql        $v0, $zero, L_8005F560
    if (ctx->r2 == 0) {
        // 0x8005F534: sw          $zero, 0x1C($a3)
        MEM_W(0X1C, ctx->r7) = 0;
            goto L_8005F560;
    }
    goto skip_0;
    // 0x8005F534: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    skip_0:
    // 0x8005F538: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8005F53C: lw          $v1, 0x20($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X20);
    // 0x8005F540: sw          $v0, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r2;
    // 0x8005F544: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8005F548: lw          $v1, 0x20($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X20);
    // 0x8005F54C: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x8005F550: sw          $v0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r2;
    // 0x8005F554: j           L_8005F5B0
    // 0x8005F558: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
        goto L_8005F5B0;
    // 0x8005F558: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
L_8005F55C:
    // 0x8005F55C: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_8005F560:
    // 0x8005F560: sw          $zero, 0x18($a3)
    MEM_W(0X18, ctx->r7) = 0;
    // 0x8005F564: j           L_8005F5B8
    // 0x8005F568: sw          $zero, 0x14($a3)
    MEM_W(0X14, ctx->r7) = 0;
        goto L_8005F5B8;
    // 0x8005F568: sw          $zero, 0x14($a3)
    MEM_W(0X14, ctx->r7) = 0;
L_8005F56C:
    // 0x8005F56C: lw          $v0, 0x20($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X20);
    // 0x8005F570: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005F574: sw          $zero, 0x34($a3)
    MEM_W(0X34, ctx->r7) = 0;
    // 0x8005F578: sw          $a0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r4;
    // 0x8005F57C: beq         $v0, $zero, L_8005F5B8
    if (ctx->r2 == 0) {
        // 0x8005F580: sw          $zero, 0x30($a3)
        MEM_W(0X30, ctx->r7) = 0;
            goto L_8005F5B8;
    }
    // 0x8005F580: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
    // 0x8005F584: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8005F588: lw          $v1, 0x20($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X20);
    // 0x8005F58C: sw          $v0, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r2;
    // 0x8005F590: lbu         $v0, 0x8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X8);
    // 0x8005F594: beq         $v0, $zero, L_8005F5A4
    if (ctx->r2 == 0) {
        // 0x8005F598: nop
    
            goto L_8005F5A4;
    }
    // 0x8005F598: nop

    // 0x8005F59C: bne         $v0, $a0, L_8005F5B8
    if (ctx->r2 != ctx->r4) {
        // 0x8005F5A0: nop
    
            goto L_8005F5B8;
    }
    // 0x8005F5A0: nop

L_8005F5A4:
    // 0x8005F5A4: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8005F5A8: beq         $v0, $zero, L_8005F5B8
    if (ctx->r2 == 0) {
        // 0x8005F5AC: nop
    
            goto L_8005F5B8;
    }
    // 0x8005F5AC: nop

L_8005F5B0:
    // 0x8005F5B0: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x8005F5B4: sw          $v0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r2;
L_8005F5B8:
    // 0x8005F5B8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005F5BC: jr          $ra
    // 0x8005F5C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005F5C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005F5C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F5C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005F5C8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8005F5CC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8005F5D0: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8005F5D4: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8005F5D8: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8005F5DC: lhu         $s5, 0x42($sp)
    ctx->r21 = MEM_HU(ctx->r29, 0X42);
    // 0x8005F5E0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005F5E4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8005F5E8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8005F5EC: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8005F5F0: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8005F5F4: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x8005F5F8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005F5FC: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x8005F600: blez        $s0, L_8005F660
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8005F604: sw          $ra, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r31;
            goto L_8005F660;
    }
    // 0x8005F604: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005F608: lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X28);
    // 0x8005F60C: lw          $a0, 0x3C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X3C);
    // 0x8005F610: lw          $a2, 0x2C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X2C);
    // 0x8005F614: jalr        $v0
    // 0x8005F618: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8005F618: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8005F61C: andi        $t0, $v0, 0x7
    ctx->r8 = ctx->r2 & 0X7;
    // 0x8005F620: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
    // 0x8005F624: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8005F628: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8005F62C: andi        $v1, $s0, 0x7
    ctx->r3 = ctx->r16 & 0X7;
    // 0x8005F630: addiu       $v1, $v1, -0x8
    ctx->r3 = ADD32(ctx->r3, -0X8);
    // 0x8005F634: subu        $v1, $s0, $v1
    ctx->r3 = SUB32(ctx->r16, ctx->r3);
    // 0x8005F638: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8005F63C: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x8005F640: andi        $a0, $s3, 0xFFF
    ctx->r4 = ctx->r19 & 0XFFF;
    // 0x8005F644: lui         $a1, 0x400
    ctx->r5 = S32(0X400 << 16);
    // 0x8005F648: or          $a0, $a0, $a1
    ctx->r4 = ctx->r4 | ctx->r5;
    // 0x8005F64C: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x8005F650: subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // 0x8005F654: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x8005F658: j           L_8005F664
    // 0x8005F65C: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
        goto L_8005F664;
    // 0x8005F65C: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
L_8005F660:
    // 0x8005F660: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
L_8005F664:
    // 0x8005F664: andi        $v0, $s6, 0x2
    ctx->r2 = ctx->r22 & 0X2;
    // 0x8005F668: beq         $v0, $zero, L_8005F690
    if (ctx->r2 == 0) {
        // 0x8005F66C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8005F690;
    }
    // 0x8005F66C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005F670: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8005F674: lui         $v0, 0xF00
    ctx->r2 = S32(0XF00 << 16);
    // 0x8005F678: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8005F67C: lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X10);
    // 0x8005F680: lui         $v1, 0x1FFF
    ctx->r3 = S32(0X1FFF << 16);
    // 0x8005F684: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x8005F688: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8005F68C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8005F690:
    // 0x8005F690: lui         $a3, 0xFF
    ctx->r7 = S32(0XFF << 16);
    // 0x8005F694: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x8005F698: addiu       $v0, $s1, 0x8
    ctx->r2 = ADD32(ctx->r17, 0X8);
    // 0x8005F69C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8005F6A0: lw          $a1, 0xC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XC);
    // 0x8005F6A4: sll         $a0, $s6, 28
    ctx->r4 = S32(ctx->r22 << 28);
    // 0x8005F6A8: sll         $v1, $s4, 1
    ctx->r3 = S32(ctx->r20 << 1);
    // 0x8005F6AC: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8005F6B0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8005F6B4: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x8005F6B8: sll         $v1, $t0, 12
    ctx->r3 = S32(ctx->r8 << 12);
    // 0x8005F6BC: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x8005F6C0: andi        $v1, $s5, 0xFFF
    ctx->r3 = ctx->r21 & 0XFFF;
    // 0x8005F6C4: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x8005F6C8: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x8005F6CC: sw          $a0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r4;
    // 0x8005F6D0: and         $a1, $a1, $a3
    ctx->r5 = ctx->r5 & ctx->r7;
    // 0x8005F6D4: or          $a1, $a1, $v1
    ctx->r5 = ctx->r5 | ctx->r3;
    // 0x8005F6D8: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    // 0x8005F6DC: sw          $zero, 0x38($s2)
    MEM_W(0X38, ctx->r18) = 0;
    // 0x8005F6E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005F6E4: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x8005F6E8: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8005F6EC: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8005F6F0: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F6F4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8005F6F8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005F6FC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005F700: jr          $ra
    // 0x8005F704: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005F704: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8005F710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F710: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005F714: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005F718: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8005F71C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005F720: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8005F724: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005F728: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005F72C: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8005F730: lw          $v1, 0x48($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X48);
    // 0x8005F734: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x8005F738: addiu       $v0, $zero, 0x170
    ctx->r2 = ADD32(0, 0X170);
    // 0x8005F73C: beq         $v1, $zero, L_8005F790
    if (ctx->r3 == 0) {
        // 0x8005F740: sh          $v0, 0x10($sp)
        MEM_H(0X10, ctx->r29) = ctx->r2;
            goto L_8005F790;
    }
    // 0x8005F740: sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // 0x8005F744: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8005F748: addiu       $a2, $zero, 0xB8
    ctx->r6 = ADD32(0, 0XB8);
    // 0x8005F74C: jal         0x8005EFF0
    // 0x8005F750: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    func_8005EFF0(rdram, ctx);
        goto after_0;
    // 0x8005F750: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_0:
    // 0x8005F754: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8005F758: lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // 0x8005F75C: lh          $v0, 0x10($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X10);
    // 0x8005F760: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x8005F764: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8005F768: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8005F76C: lui         $v1, 0xA00
    ctx->r3 = S32(0XA00 << 16);
    // 0x8005F770: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005F774: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8005F778: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x8005F77C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8005F780: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8005F784: ori         $v0, $v0, 0x170
    ctx->r2 = ctx->r2 | 0X170;
    // 0x8005F788: j           L_8005F8AC
    // 0x8005F78C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
        goto L_8005F8AC;
    // 0x8005F78C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8005F790:
    // 0x8005F790: lwc1        $f0, 0x44($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X44);
    // 0x8005F794: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005F798: ldc1        $f2, -0x1100($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1100);
    // 0x8005F79C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8005F7A0: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x8005F7A4: nop

    // 0x8005F7A8: bc1f        L_8005F7C4
    if (!c1cs) {
        // 0x8005F7AC: nop
    
            goto L_8005F7C4;
    }
    // 0x8005F7AC: nop

    // 0x8005F7B0: lui         $at, 0x3FFF
    ctx->r1 = S32(0X3FFF << 16);
    // 0x8005F7B4: ori         $at, $at, 0xFEB0
    ctx->r1 = ctx->r1 | 0XFEB0;
    // 0x8005F7B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005F7BC: nop

    // 0x8005F7C0: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
L_8005F7C4:
    // 0x8005F7C4: lwc1        $f0, 0x44($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X44);
    // 0x8005F7C8: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x8005F7CC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8005F7D0: nop

    // 0x8005F7D4: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8005F7D8: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005F7DC: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8005F7E0: nop

    // 0x8005F7E4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8005F7E8: nop

    // 0x8005F7EC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005F7F0: div.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8005F7F4: lui         $at, 0x4338
    ctx->r1 = S32(0X4338 << 16);
    // 0x8005F7F8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005F7FC: nop

    // 0x8005F800: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8005F804: lwc1        $f2, 0x4C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x8005F808: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8005F80C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005F810: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8005F814: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005F818: nop

    // 0x8005F81C: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x8005F820: nop

    // 0x8005F824: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005F828: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8005F82C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8005F830: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x8005F834: swc1        $f4, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f4.u32l;
    // 0x8005F838: jal         0x8005EFF0
    // 0x8005F83C: swc1        $f2, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f2.u32l;
    func_8005EFF0(rdram, ctx);
        goto after_1;
    // 0x8005F83C: swc1        $f2, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f2.u32l;
    after_1:
    // 0x8005F840: lwc1        $f0, 0x44($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X44);
    // 0x8005F844: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8005F848: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
    // 0x8005F84C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8005F850: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005F854: mfc1        $s0, $f2
    ctx->r16 = (int32_t)ctx->f2.u32l;
    // 0x8005F858: nop

    // 0x8005F85C: jal         0x80062180
    // 0x8005F860: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x8005F860: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    after_2:
    // 0x8005F864: lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // 0x8005F868: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x8005F86C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8005F870: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8005F874: lui         $v1, 0x500
    ctx->r3 = S32(0X500 << 16);
    // 0x8005F878: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005F87C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8005F880: lw          $v0, 0x50($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X50);
    // 0x8005F884: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8005F888: lhu         $v1, 0x10($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X10);
    // 0x8005F88C: sll         $s0, $s0, 14
    ctx->r16 = S32(ctx->r16 << 14);
    // 0x8005F890: sll         $v0, $v0, 30
    ctx->r2 = S32(ctx->r2 << 30);
    // 0x8005F894: or          $v0, $v0, $s0
    ctx->r2 = ctx->r2 | ctx->r16;
    // 0x8005F898: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8005F89C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8005F8A0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005F8A4: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8005F8A8: sw          $zero, 0x50($s1)
    MEM_W(0X50, ctx->r17) = 0;
L_8005F8AC:
    // 0x8005F8AC: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x8005F8B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005F8B4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005F8B8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F8BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005F8C0: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8005F8C4: jr          $ra
    // 0x8005F8C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005F8C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8005F8CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F8CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F8D0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005F8D4: jal         0x8005F438
    // 0x8005F8D8: nop

    func_8005F438(rdram, ctx);
        goto after_0;
    // 0x8005F8D8: nop

    after_0:
    // 0x8005F8DC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005F8E0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8005F8E4: jr          $ra
    // 0x8005F8E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005F8E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005F8F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F8F0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005F8F4: lw          $v0, 0x60B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60B4);
    // 0x8005F8F8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8005F8FC: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8005F900: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x8005F904: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8005F908: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8005F90C: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8005F910: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8005F914: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8005F918: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8005F91C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8005F920: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8005F924: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8005F928: lw          $v0, 0x40($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X40);
    // 0x8005F92C: addiu       $s4, $zero, 0x170
    ctx->r20 = ADD32(0, 0X170);
    // 0x8005F930: lw          $s2, 0x20($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X20);
    // 0x8005F934: jal         0x8005DFC0
    // 0x8005F938: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    func_8005DFC0(rdram, ctx);
        goto after_0;
    // 0x8005F938: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    after_0:
    // 0x8005F93C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8005F940: addu        $v1, $t0, $zero
    ctx->r3 = ADD32(ctx->r8, 0);
    // 0x8005F944: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8005F948: lui         $a3, 0xC00
    ctx->r7 = S32(0XC00 << 16);
    // 0x8005F94C: ori         $a3, $a3, 0xDA83
    ctx->r7 = ctx->r7 | 0XDA83;
    // 0x8005F950: lui         $a0, 0x7C0
    ctx->r4 = S32(0X7C0 << 16);
    // 0x8005F954: ori         $a0, $a0, 0x7C0
    ctx->r4 = ctx->r4 | 0X7C0;
    // 0x8005F958: lui         $a1, 0xC00
    ctx->r5 = S32(0XC00 << 16);
    // 0x8005F95C: ori         $a1, $a1, 0x5A82
    ctx->r5 = ctx->r5 | 0X5A82;
    // 0x8005F960: lui         $v0, 0x930
    ctx->r2 = S32(0X930 << 16);
    // 0x8005F964: ori         $v0, $v0, 0x7C0
    ctx->r2 = ctx->r2 | 0X7C0;
    // 0x8005F968: addiu       $a2, $zero, 0x7C0
    ctx->r6 = ADD32(0, 0X7C0);
    // 0x8005F96C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x8005F970: addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
    // 0x8005F974: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x8005F978: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
    // 0x8005F97C: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x8005F980: lw          $a1, 0x18($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X18);
    // 0x8005F984: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8005F988: jal         0x80060128
    // 0x8005F98C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80060128(rdram, ctx);
        goto after_1;
    // 0x8005F98C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_1:
    // 0x8005F990: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8005F994: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x8005F998: ori         $v0, $v0, 0x930
    ctx->r2 = ctx->r2 | 0X930;
    // 0x8005F99C: addu        $v1, $t0, $zero
    ctx->r3 = ADD32(ctx->r8, 0);
    // 0x8005F9A0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8005F9A4: addiu       $v0, $zero, 0x170
    ctx->r2 = ADD32(0, 0X170);
    // 0x8005F9A8: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8005F9AC: lbu         $v0, 0x24($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X24);
    // 0x8005F9B0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8005F9B4: blez        $v0, L_8005FB84
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005F9B8: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_8005FB84;
    }
    // 0x8005F9B8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8005F9BC: lui         $fp, 0xC00
    ctx->r30 = S32(0XC00 << 16);
    // 0x8005F9C0: sll         $v1, $s7, 16
    ctx->r3 = S32(ctx->r23 << 16);
L_8005F9C4:
    // 0x8005F9C4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8005F9C8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005F9CC: lw          $a0, 0x20($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X20);
    // 0x8005F9D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005F9D4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005F9D8: addu        $s1, $a0, $v0
    ctx->r17 = ADD32(ctx->r4, ctx->r2);
    // 0x8005F9DC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8005F9E0: lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X18);
    // 0x8005F9E4: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x8005F9E8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005F9EC: subu        $s3, $a0, $v0
    ctx->r19 = SUB32(ctx->r4, ctx->r2);
    // 0x8005F9F0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8005F9F4: bne         $s3, $s0, L_8005FA0C
    if (ctx->r19 != ctx->r16) {
        // 0x8005F9F8: subu        $s6, $a0, $v1
        ctx->r22 = SUB32(ctx->r4, ctx->r3);
            goto L_8005FA0C;
    }
    // 0x8005F9F8: subu        $s6, $a0, $v1
    ctx->r22 = SUB32(ctx->r4, ctx->r3);
    // 0x8005F9FC: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // 0x8005FA00: addu        $s4, $s5, $zero
    ctx->r20 = ADD32(ctx->r21, 0);
    // 0x8005FA04: j           L_8005FA2C
    // 0x8005FA08: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
        goto L_8005FA2C;
    // 0x8005FA08: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
L_8005FA0C:
    // 0x8005FA0C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8005FA10: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8005FA14: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8005FA18: sll         $a2, $s5, 16
    ctx->r6 = S32(ctx->r21 << 16);
    // 0x8005FA1C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8005FA20: jal         0x80060000
    // 0x8005FA24: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    func_80060000(rdram, ctx);
        goto after_2;
    // 0x8005FA24: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    after_2:
    // 0x8005FA28: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_8005FA2C:
    // 0x8005FA2C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8005FA30: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8005FA34: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8005FA38: sra         $s0, $v0, 16
    ctx->r16 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005FA3C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8005FA40: jal         0x8005FDF0
    // 0x8005FA44: addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
    func_8005FDF0(rdram, ctx);
        goto after_3;
    // 0x8005FA44: addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
    after_3:
    // 0x8005FA48: lh          $v1, 0x8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X8);
    // 0x8005FA4C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8005FA50: beq         $v1, $zero, L_8005FAA4
    if (ctx->r3 == 0) {
        // 0x8005FA54: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8005FAA4;
    }
    // 0x8005FA54: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8005FA58: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x8005FA5C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005FA60: or          $v0, $v0, $fp
    ctx->r2 = ctx->r2 | ctx->r30;
    // 0x8005FA64: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8005FA68: sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21 << 16);
    // 0x8005FA6C: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x8005FA70: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005FA74: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8005FA78: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8005FA7C: bne         $v0, $zero, L_8005FAA4
    if (ctx->r2 != 0) {
        // 0x8005FA80: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_8005FAA4;
    }
    // 0x8005FA80: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8005FA84: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x8005FA88: bne         $v0, $zero, L_8005FAA4
    if (ctx->r2 != 0) {
        // 0x8005FA8C: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_8005FAA4;
    }
    // 0x8005FA8C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8005FA90: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x8005FA94: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8005FA98: jal         0x80060128
    // 0x8005FA9C: addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
    func_80060128(rdram, ctx);
        goto after_4;
    // 0x8005FA9C: addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
    after_4:
    // 0x8005FAA0: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_8005FAA4:
    // 0x8005FAA4: lh          $v0, 0xA($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XA);
    // 0x8005FAA8: beq         $v0, $zero, L_8005FAE8
    if (ctx->r2 == 0) {
        // 0x8005FAAC: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8005FAE8;
    }
    // 0x8005FAAC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005FAB0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8005FAB4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8005FAB8: sll         $a2, $s5, 16
    ctx->r6 = S32(ctx->r21 << 16);
    // 0x8005FABC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8005FAC0: addiu       $a3, $t0, 0x8
    ctx->r7 = ADD32(ctx->r8, 0X8);
    // 0x8005FAC4: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x8005FAC8: or          $v0, $v0, $fp
    ctx->r2 = ctx->r2 | ctx->r30;
    // 0x8005FACC: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8005FAD0: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8005FAD4: andi        $v1, $a2, 0xFFFF
    ctx->r3 = ctx->r6 & 0XFFFF;
    // 0x8005FAD8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005FADC: jal         0x80060128
    // 0x8005FAE0: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    func_80060128(rdram, ctx);
        goto after_5;
    // 0x8005FAE0: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    after_5:
    // 0x8005FAE4: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_8005FAE8:
    // 0x8005FAE8: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x8005FAEC: beq         $a0, $zero, L_8005FB04
    if (ctx->r4 == 0) {
        // 0x8005FAF0: sll         $a1, $s4, 16
        ctx->r5 = S32(ctx->r20 << 16);
            goto L_8005FB04;
    }
    // 0x8005FAF0: sll         $a1, $s4, 16
    ctx->r5 = S32(ctx->r20 << 16);
    // 0x8005FAF4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8005FAF8: jal         0x80060240
    // 0x8005FAFC: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    func_80060240(rdram, ctx);
        goto after_6;
    // 0x8005FAFC: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    after_6:
    // 0x8005FB00: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_8005FB04:
    // 0x8005FB04: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x8005FB08: bne         $v0, $zero, L_8005FB28
    if (ctx->r2 != 0) {
        // 0x8005FB0C: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_8005FB28;
    }
    // 0x8005FB0C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8005FB10: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x8005FB14: sll         $a2, $s4, 16
    ctx->r6 = S32(ctx->r20 << 16);
    // 0x8005FB18: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8005FB1C: jal         0x80060128
    // 0x8005FB20: addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
    func_80060128(rdram, ctx);
        goto after_7;
    // 0x8005FB20: addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
    after_7:
    // 0x8005FB24: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_8005FB28:
    // 0x8005FB28: lh          $v0, 0xC($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XC);
    // 0x8005FB2C: beq         $v0, $zero, L_8005FB54
    if (ctx->r2 == 0) {
        // 0x8005FB30: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8005FB54;
    }
    // 0x8005FB30: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005FB34: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    // 0x8005FB38: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8005FB3C: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8005FB40: or          $v1, $v1, $fp
    ctx->r3 = ctx->r3 | ctx->r30;
    // 0x8005FB44: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8005FB48: sll         $v1, $s4, 16
    ctx->r3 = S32(ctx->r20 << 16);
    // 0x8005FB4C: ori         $v1, $v1, 0x930
    ctx->r3 = ctx->r3 | 0X930;
    // 0x8005FB50: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_8005FB54:
    // 0x8005FB54: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x8005FB58: lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X18);
    // 0x8005FB5C: addiu       $v0, $s7, 0x1
    ctx->r2 = ADD32(ctx->r23, 0X1);
    // 0x8005FB60: addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
    // 0x8005FB64: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8005FB68: addu        $s0, $a0, $v1
    ctx->r16 = ADD32(ctx->r4, ctx->r3);
    // 0x8005FB6C: lbu         $v1, 0x24($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X24);
    // 0x8005FB70: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8005FB74: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8005FB78: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005FB7C: bne         $v0, $zero, L_8005F9C4
    if (ctx->r2 != 0) {
        // 0x8005FB80: sll         $v1, $s7, 16
        ctx->r3 = S32(ctx->r23 << 16);
            goto L_8005F9C4;
    }
    // 0x8005FB80: sll         $v1, $s7, 16
    ctx->r3 = S32(ctx->r23 << 16);
L_8005FB84:
    // 0x8005FB84: lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X18);
    // 0x8005FB88: lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C);
    // 0x8005FB8C: lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X14);
    // 0x8005FB90: addiu       $v0, $v0, 0x170
    ctx->r2 = ADD32(ctx->r2, 0X170);
    // 0x8005FB94: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x8005FB98: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8005FB9C: sltu        $v1, $v1, $v0
    ctx->r3 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8005FBA0: beq         $v1, $zero, L_8005FBB0
    if (ctx->r3 == 0) {
        // 0x8005FBA4: sw          $v0, 0x18($s2)
        MEM_W(0X18, ctx->r18) = ctx->r2;
            goto L_8005FBB0;
    }
    // 0x8005FBA4: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // 0x8005FBA8: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8005FBAC: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
L_8005FBB0:
    // 0x8005FBB0: lui         $a1, 0x7C0
    ctx->r5 = S32(0X7C0 << 16);
    // 0x8005FBB4: ori         $a1, $a1, 0x170
    ctx->r5 = ctx->r5 | 0X170;
    // 0x8005FBB8: addiu       $v0, $t0, 0x8
    ctx->r2 = ADD32(ctx->r8, 0X8);
    // 0x8005FBBC: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x8005FBC0: lui         $v1, 0xA00
    ctx->r3 = S32(0XA00 << 16);
    // 0x8005FBC4: ori         $v1, $v1, 0x930
    ctx->r3 = ctx->r3 | 0X930;
    // 0x8005FBC8: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8005FBCC: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x8005FBD0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8005FBD4: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8005FBD8: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8005FBDC: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8005FBE0: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8005FBE4: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8005FBE8: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8005FBEC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8005FBF0: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8005FBF4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8005FBF8: jr          $ra
    // 0x8005FBFC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8005FBFC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_8005FC00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FC00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005FC04: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005FC08: addiu       $v1, $a1, -0x2
    ctx->r3 = ADD32(ctx->r5, -0X2);
    // 0x8005FC0C: bgez        $v1, L_8005FC18
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8005FC10: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8005FC18;
    }
    // 0x8005FC10: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8005FC14: addiu       $v0, $a1, 0x5
    ctx->r2 = ADD32(ctx->r5, 0X5);
L_8005FC18:
    // 0x8005FC18: sra         $a3, $v0, 3
    ctx->r7 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8005FC1C: addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    // 0x8005FC20: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x8005FC24: subu        $a3, $v1, $v0
    ctx->r7 = SUB32(ctx->r3, ctx->r2);
    // 0x8005FC28: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
    // 0x8005FC2C: sltiu       $v0, $a3, 0x8
    ctx->r2 = ctx->r7 < 0X8 ? 1 : 0;
    // 0x8005FC30: beq         $v0, $zero, L_8005FDE0
    if (ctx->r2 == 0) {
        // 0x8005FC34: nop
    
            goto L_8005FDE0;
    }
    // 0x8005FC34: nop

    // 0x8005FC38: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x8005FC3C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005FC40: addu        $at, $at, $v0
    gpr jr_addend_8005FC48 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005FC44: lw          $v0, -0x10F0($at)
    ctx->r2 = ADD32(ctx->r1, -0X10F0);
    // 0x8005FC48: jr          $v0
    // 0x8005FC4C: nop

    switch (jr_addend_8005FC48 >> 2) {
        case 0: goto L_8005FC50; break;
        case 1: goto L_8005FC74; break;
        case 2: goto L_8005FCB4; break;
        case 3: goto L_8005FC98; break;
        case 4: goto L_8005FCD0; break;
        case 5: goto L_8005FCEC; break;
        case 6: goto L_8005FD40; break;
        case 7: goto L_8005FDAC; break;
        default: switch_error(__func__, 0x8005FC48, 0x800AEF10);
    }
    // 0x8005FC4C: nop

L_8005FC50:
    // 0x8005FC50: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x8005FC54: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8005FC58: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8005FC5C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8005FC60: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005FC64: addiu       $v0, $zero, -0x8
    ctx->r2 = ADD32(0, -0X8);
    // 0x8005FC68: and         $v0, $a2, $v0
    ctx->r2 = ctx->r6 & ctx->r2;
    // 0x8005FC6C: j           L_8005FDE0
    // 0x8005FC70: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_8005FDE0;
    // 0x8005FC70: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8005FC74:
    // 0x8005FC74: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x8005FC78: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8005FC7C: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8005FC80: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8005FC84: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005FC88: addiu       $v0, $zero, -0x8
    ctx->r2 = ADD32(0, -0X8);
    // 0x8005FC8C: and         $v0, $a2, $v0
    ctx->r2 = ctx->r6 & ctx->r2;
    // 0x8005FC90: j           L_8005FDE0
    // 0x8005FC94: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
        goto L_8005FDE0;
    // 0x8005FC94: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_8005FC98:
    // 0x8005FC98: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
    // 0x8005FC9C: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8005FCA0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8005FCA4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005FCA8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005FCAC: j           L_8005FDE0
    // 0x8005FCB0: sh          $a2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r6;
        goto L_8005FDE0;
    // 0x8005FCB0: sh          $a2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r6;
L_8005FCB4:
    // 0x8005FCB4: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
    // 0x8005FCB8: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8005FCBC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8005FCC0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005FCC4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005FCC8: j           L_8005FDE0
    // 0x8005FCCC: sh          $a2, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r6;
        goto L_8005FDE0;
    // 0x8005FCCC: sh          $a2, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r6;
L_8005FCD0:
    // 0x8005FCD0: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
    // 0x8005FCD4: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8005FCD8: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8005FCDC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005FCE0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005FCE4: j           L_8005FDE0
    // 0x8005FCE8: sh          $a2, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r6;
        goto L_8005FDE0;
    // 0x8005FCE8: sh          $a2, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r6;
L_8005FCEC:
    // 0x8005FCEC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8005FCF0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005FCF4: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x8005FCF8: nop

    // 0x8005FCFC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005FD00: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005FD04: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005FD08: lw          $v0, 0x60B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60B4);
    // 0x8005FD0C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8005FD10: add.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
    // 0x8005FD14: lwc1        $f2, 0x4C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8005FD18: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x8005FD1C: div.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x8005FD20: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
    // 0x8005FD24: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8005FD28: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8005FD2C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005FD30: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005FD34: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8005FD38: j           L_8005FDE0
    // 0x8005FD3C: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
        goto L_8005FDE0;
    // 0x8005FD3C: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
L_8005FD40:
    // 0x8005FD40: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
    // 0x8005FD44: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8005FD48: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8005FD4C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005FD50: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005FD54: ldc1        $f2, -0x10D0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X10D0);
    // 0x8005FD58: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x8005FD5C: nop

    // 0x8005FD60: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005FD64: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x8005FD68: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8005FD6C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005FD70: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8005FD74: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8005FD78: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8005FD7C: nop

    // 0x8005FD80: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8005FD84: bgez        $v1, L_8005FD98
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8005FD88: div.d       $f2, $f0, $f2
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = DIV_D(ctx->f0.d, ctx->f2.d);
            goto L_8005FD98;
    }
    // 0x8005FD88: div.d       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x8005FD8C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005FD90: ldc1        $f0, -0x10C8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X10C8);
    // 0x8005FD94: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_8005FD98:
    // 0x8005FD98: nop

    // 0x8005FD9C: mul.d       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x8005FDA0: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8005FDA4: j           L_8005FDE0
    // 0x8005FDA8: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
        goto L_8005FDE0;
    // 0x8005FDA8: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
L_8005FDAC:
    // 0x8005FDAC: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
    // 0x8005FDB0: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8005FDB4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8005FDB8: sll         $a1, $v0, 3
    ctx->r5 = S32(ctx->r2 << 3);
    // 0x8005FDBC: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x8005FDC0: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x8005FDC4: beq         $v0, $zero, L_8005FDE0
    if (ctx->r2 == 0) {
        // 0x8005FDC8: nop
    
            goto L_8005FDE0;
    }
    // 0x8005FDC8: nop

    // 0x8005FDCC: sh          $a2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r6;
    // 0x8005FDD0: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x8005FDD4: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x8005FDD8: jal         0x800621F0
    // 0x8005FDDC: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    func_800621F0(rdram, ctx);
        goto after_0;
    // 0x8005FDDC: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    after_0:
L_8005FDE0:
    // 0x8005FDE0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8005FDE4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8005FDE8: jr          $ra
    // 0x8005FDEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005FDEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005FDF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FDF0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005FDF4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005FDF8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8005FDFC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8005FE00: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x8005FE04: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8005FE08: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x8005FE0C: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8005FE10: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8005FE14: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005FE18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005FE1C: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x8005FE20: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x8005FE24: lw          $v0, 0x24($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X24);
    // 0x8005FE28: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x8005FE2C: beq         $v0, $zero, L_8005FFA8
    if (ctx->r2 == 0) {
        // 0x8005FE30: addiu       $s2, $zero, 0xB8
        ctx->r18 = ADD32(0, 0XB8);
            goto L_8005FFA8;
    }
    // 0x8005FE30: addiu       $s2, $zero, 0xB8
    ctx->r18 = ADD32(0, 0XB8);
    // 0x8005FE34: lw          $s0, 0x4($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X4);
    // 0x8005FE38: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8005FE3C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8005FE40: addiu       $a1, $zero, 0xB8
    ctx->r5 = ADD32(0, 0XB8);
    // 0x8005FE44: jal         0x800652F8
    // 0x8005FE48: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    func_800652F8(rdram, ctx);
        goto after_0;
    // 0x8005FE48: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    after_0:
    // 0x8005FE4C: mtc1        $s0, $f2
    ctx->f2.u32l = ctx->r16;
    // 0x8005FE50: nop

    // 0x8005FE54: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8005FE58: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005FE5C: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x8005FE60: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8005FE64: nop

    // 0x8005FE68: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8005FE6C: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005FE70: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8005FE74: nop

    // 0x8005FE78: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8005FE7C: nop

    // 0x8005FE80: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8005FE84: div.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8005FE88: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005FE8C: ldc1        $f20, -0x10C0($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0X10C0);
    // 0x8005FE90: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8005FE94: sub.d       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f20.d = ctx->f20.d - ctx->f0.d;
    // 0x8005FE98: mtc1        $s2, $f2
    ctx->f2.u32l = ctx->r18;
    // 0x8005FE9C: nop

    // 0x8005FEA0: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8005FEA4: cvt.s.d     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.fl = CVT_S_D(ctx->f20.d);
    // 0x8005FEA8: mul.s       $f2, $f20, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8005FEAC: lw          $v0, 0x24($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X24);
    // 0x8005FEB0: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8005FEB4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8005FEB8: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005FEBC: mfc1        $s2, $f2
    ctx->r18 = (int32_t)ctx->f2.u32l;
    // 0x8005FEC0: nop

    // 0x8005FEC4: mtc1        $s2, $f2
    ctx->f2.u32l = ctx->r18;
    // 0x8005FEC8: nop

    // 0x8005FECC: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8005FED0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8005FED4: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x8005FED8: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
    // 0x8005FEDC: lw          $v1, 0x4($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X4);
    // 0x8005FEE0: lw          $a1, 0x18($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X18);
    // 0x8005FEE4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005FEE8: addiu       $a2, $zero, 0x2E0
    ctx->r6 = ADD32(0, 0X2E0);
    // 0x8005FEEC: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8005FEF0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8005FEF4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005FEF8: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8005FEFC: andi        $a3, $a1, 0x7
    ctx->r7 = ctx->r5 & 0X7;
    // 0x8005FF00: sra         $a3, $a3, 1
    ctx->r7 = S32(SIGNED(ctx->r7) >> 1);
    // 0x8005FF04: sll         $s1, $a3, 1
    ctx->r17 = S32(ctx->r7 << 1);
    // 0x8005FF08: subu        $a1, $a1, $s1
    ctx->r5 = SUB32(ctx->r5, ctx->r17);
    // 0x8005FF0C: jal         0x80060000
    // 0x8005FF10: addu        $a3, $s2, $a3
    ctx->r7 = ADD32(ctx->r18, ctx->r7);
    func_80060000(rdram, ctx);
        goto after_1;
    // 0x8005FF10: addu        $a3, $s2, $a3
    ctx->r7 = ADD32(ctx->r18, ctx->r7);
    after_1:
    // 0x8005FF14: nop

    // 0x8005FF18: mul.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x8005FF1C: lw          $v1, 0x24($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X24);
    // 0x8005FF20: lw          $a0, 0x14($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X14);
    // 0x8005FF24: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x8005FF28: trunc.w.s   $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x8005FF2C: mfc1        $s0, $f0
    ctx->r16 = (int32_t)ctx->f0.u32l;
    // 0x8005FF30: nop

    // 0x8005FF34: jal         0x80062180
    // 0x8005FF38: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x8005FF38: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    after_2:
    // 0x8005FF3C: lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // 0x8005FF40: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x8005FF44: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8005FF48: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8005FF4C: lui         $v1, 0x500
    ctx->r3 = S32(0X500 << 16);
    // 0x8005FF50: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005FF54: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8005FF58: lw          $v0, 0x24($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X24);
    // 0x8005FF5C: sra         $v1, $s5, 8
    ctx->r3 = S32(SIGNED(ctx->r21) >> 8);
    // 0x8005FF60: sll         $s0, $s0, 14
    ctx->r16 = S32(ctx->r16 << 14);
    // 0x8005FF64: ori         $s1, $s1, 0x2E0
    ctx->r17 = ctx->r17 | 0X2E0;
    // 0x8005FF68: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
    // 0x8005FF6C: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x8005FF70: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x8005FF74: sll         $v0, $v0, 30
    ctx->r2 = S32(ctx->r2 << 30);
    // 0x8005FF78: or          $v0, $v0, $s0
    ctx->r2 = ctx->r2 | ctx->r16;
    // 0x8005FF7C: or          $v0, $v0, $s1
    ctx->r2 = ctx->r2 | ctx->r17;
    // 0x8005FF80: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8005FF84: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8005FF88: lw          $v0, 0x24($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X24);
    // 0x8005FF8C: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x8005FF90: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
    // 0x8005FF94: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x8005FF98: addiu       $s2, $s2, -0xB8
    ctx->r18 = ADD32(ctx->r18, -0XB8);
    // 0x8005FF9C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8005FFA0: j           L_8005FFD0
    // 0x8005FFA4: sw          $v0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r2;
        goto L_8005FFD0;
    // 0x8005FFA4: sw          $v0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r2;
L_8005FFA8:
    // 0x8005FFA8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005FFAC: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    // 0x8005FFB0: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x8005FFB4: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x8005FFB8: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    // 0x8005FFBC: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8005FFC0: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x8005FFC4: jal         0x80060000
    // 0x8005FFC8: subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    func_80060000(rdram, ctx);
        goto after_3;
    // 0x8005FFC8: subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_3:
    // 0x8005FFCC: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
L_8005FFD0:
    // 0x8005FFD0: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // 0x8005FFD4: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8005FFD8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8005FFDC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8005FFE0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8005FFE4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005FFE8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FFEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005FFF0: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x8005FFF4: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x8005FFF8: jr          $ra
    // 0x8005FFFC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8005FFFC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80060000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80060004: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80060008: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8006000C: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80060010: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x80060014: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x80060018: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8006001C: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x80060020: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80060024: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80060028: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8006002C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80060030: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80060034: lw          $v1, 0x1C($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X1C);
    // 0x80060038: lw          $v0, 0x14($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X14);
    // 0x8006003C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80060040: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // 0x80060044: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80060048: beq         $v0, $zero, L_80060054
    if (ctx->r2 == 0) {
        // 0x8006004C: addu        $s2, $s4, $zero
        ctx->r18 = ADD32(ctx->r20, 0);
            goto L_80060054;
    }
    // 0x8006004C: addu        $s2, $s4, $zero
    ctx->r18 = ADD32(ctx->r20, 0);
    // 0x80060050: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_80060054:
    // 0x80060054: sll         $a3, $a3, 1
    ctx->r7 = S32(ctx->r7 << 1);
    // 0x80060058: addu        $s0, $a0, $a3
    ctx->r16 = ADD32(ctx->r4, ctx->r7);
    // 0x8006005C: sltu        $v0, $a1, $s0
    ctx->r2 = ctx->r5 < ctx->r16 ? 1 : 0;
    // 0x80060060: beq         $v0, $zero, L_800600D0
    if (ctx->r2 == 0) {
        // 0x80060064: subu        $s1, $a1, $a0
        ctx->r17 = SUB32(ctx->r5, ctx->r4);
            goto L_800600D0;
    }
    // 0x80060064: subu        $s1, $a1, $a0
    ctx->r17 = SUB32(ctx->r5, ctx->r4);
    // 0x80060068: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x8006006C: sra         $s1, $s1, 1
    ctx->r17 = S32(SIGNED(ctx->r17) >> 1);
    // 0x80060070: sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17 << 1);
    // 0x80060074: andi        $v1, $s1, 0xFFF
    ctx->r3 = ctx->r17 & 0XFFF;
    // 0x80060078: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x8006007C: andi        $v0, $s6, 0xFFF
    ctx->r2 = ctx->r22 & 0XFFF;
    // 0x80060080: lui         $s3, 0x400
    ctx->r19 = S32(0X400 << 16);
    // 0x80060084: or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
    // 0x80060088: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8006008C: subu        $s0, $s0, $a1
    ctx->r16 = SUB32(ctx->r16, ctx->r5);
    // 0x80060090: sra         $s0, $s0, 1
    ctx->r16 = S32(SIGNED(ctx->r16) >> 1);
    // 0x80060094: jal         0x80062180
    // 0x80060098: sw          $v1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80060098: sw          $v1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r3;
    after_0:
    // 0x8006009C: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // 0x800600A0: addu        $s2, $s4, $zero
    ctx->r18 = ADD32(ctx->r20, 0);
    // 0x800600A4: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x800600A8: andi        $s0, $s0, 0xFFF
    ctx->r16 = ctx->r16 & 0XFFF;
    // 0x800600AC: sll         $s0, $s0, 12
    ctx->r16 = S32(ctx->r16 << 12);
    // 0x800600B0: addu        $s1, $s6, $s1
    ctx->r17 = ADD32(ctx->r22, ctx->r17);
    // 0x800600B4: andi        $s1, $s1, 0xFFF
    ctx->r17 = ctx->r17 & 0XFFF;
    // 0x800600B8: or          $s1, $s1, $s3
    ctx->r17 = ctx->r17 | ctx->r19;
    // 0x800600BC: or          $s0, $s0, $s1
    ctx->r16 = ctx->r16 | ctx->r17;
    // 0x800600C0: sw          $s0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r16;
    // 0x800600C4: lw          $a0, 0x14($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X14);
    // 0x800600C8: j           L_800600F0
    // 0x800600CC: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
        goto L_800600F0;
    // 0x800600CC: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
L_800600D0:
    // 0x800600D0: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800600D4: andi        $v0, $a3, 0xFFF
    ctx->r2 = ctx->r7 & 0XFFF;
    // 0x800600D8: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x800600DC: andi        $v1, $s6, 0xFFF
    ctx->r3 = ctx->r22 & 0XFFF;
    // 0x800600E0: lui         $a1, 0x400
    ctx->r5 = S32(0X400 << 16);
    // 0x800600E4: or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
    // 0x800600E8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800600EC: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
L_800600F0:
    // 0x800600F0: jal         0x80062180
    // 0x800600F4: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800600F4: nop

    after_1:
    // 0x800600F8: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // 0x800600FC: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // 0x80060100: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80060104: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80060108: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8006010C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80060110: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80060114: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80060118: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8006011C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80060120: jr          $ra
    // 0x80060124: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80060124: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80060128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060128: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006012C: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80060130: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x80060134: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x80060138: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8006013C: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x80060140: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80060144: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x80060148: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006014C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80060150: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80060154: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80060158: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006015C: lw          $v1, 0x1C($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X1C);
    // 0x80060160: lw          $v0, 0x14($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X14);
    // 0x80060164: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80060168: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // 0x8006016C: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80060170: beq         $v0, $zero, L_8006017C
    if (ctx->r2 == 0) {
        // 0x80060174: addu        $s2, $s4, $zero
        ctx->r18 = ADD32(ctx->r20, 0);
            goto L_8006017C;
    }
    // 0x80060174: addu        $s2, $s4, $zero
    ctx->r18 = ADD32(ctx->r20, 0);
    // 0x80060178: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_8006017C:
    // 0x8006017C: addiu       $s0, $a0, 0x170
    ctx->r16 = ADD32(ctx->r4, 0X170);
    // 0x80060180: sltu        $v0, $a1, $s0
    ctx->r2 = ctx->r5 < ctx->r16 ? 1 : 0;
    // 0x80060184: beq         $v0, $zero, L_800601F4
    if (ctx->r2 == 0) {
        // 0x80060188: subu        $s1, $a1, $a0
        ctx->r17 = SUB32(ctx->r5, ctx->r4);
            goto L_800601F4;
    }
    // 0x80060188: subu        $s1, $a1, $a0
    ctx->r17 = SUB32(ctx->r5, ctx->r4);
    // 0x8006018C: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x80060190: sra         $s1, $s1, 1
    ctx->r17 = S32(SIGNED(ctx->r17) >> 1);
    // 0x80060194: sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17 << 1);
    // 0x80060198: andi        $v1, $s1, 0xFFF
    ctx->r3 = ctx->r17 & 0XFFF;
    // 0x8006019C: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x800601A0: andi        $v0, $s5, 0xFFF
    ctx->r2 = ctx->r21 & 0XFFF;
    // 0x800601A4: lui         $s3, 0x600
    ctx->r19 = S32(0X600 << 16);
    // 0x800601A8: or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
    // 0x800601AC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800601B0: subu        $s0, $s0, $a1
    ctx->r16 = SUB32(ctx->r16, ctx->r5);
    // 0x800601B4: sra         $s0, $s0, 1
    ctx->r16 = S32(SIGNED(ctx->r16) >> 1);
    // 0x800601B8: jal         0x80062180
    // 0x800601BC: sw          $v1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800601BC: sw          $v1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r3;
    after_0:
    // 0x800601C0: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // 0x800601C4: addu        $s2, $s4, $zero
    ctx->r18 = ADD32(ctx->r20, 0);
    // 0x800601C8: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x800601CC: andi        $s0, $s0, 0xFFF
    ctx->r16 = ctx->r16 & 0XFFF;
    // 0x800601D0: sll         $s0, $s0, 12
    ctx->r16 = S32(ctx->r16 << 12);
    // 0x800601D4: addu        $s1, $s5, $s1
    ctx->r17 = ADD32(ctx->r21, ctx->r17);
    // 0x800601D8: andi        $s1, $s1, 0xFFF
    ctx->r17 = ctx->r17 & 0XFFF;
    // 0x800601DC: or          $s1, $s1, $s3
    ctx->r17 = ctx->r17 | ctx->r19;
    // 0x800601E0: or          $s0, $s0, $s1
    ctx->r16 = ctx->r16 | ctx->r17;
    // 0x800601E4: sw          $s0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r16;
    // 0x800601E8: lw          $a0, 0x14($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X14);
    // 0x800601EC: j           L_80060208
    // 0x800601F0: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
        goto L_80060208;
    // 0x800601F0: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
L_800601F4:
    // 0x800601F4: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800601F8: andi        $v0, $s5, 0xFFF
    ctx->r2 = ctx->r21 & 0XFFF;
    // 0x800601FC: lui         $v1, 0x617
    ctx->r3 = S32(0X617 << 16);
    // 0x80060200: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80060204: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
L_80060208:
    // 0x80060208: jal         0x80062180
    // 0x8006020C: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x8006020C: nop

    after_1:
    // 0x80060210: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // 0x80060214: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // 0x80060218: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006021C: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80060220: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80060224: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80060228: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8006022C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80060230: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80060234: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80060238: jr          $ra
    // 0x8006023C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8006023C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80060240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060240: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80060244: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80060248: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8006024C: lui         $v0, 0xB00
    ctx->r2 = S32(0XB00 << 16);
    // 0x80060250: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x80060254: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x80060258: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8006025C: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x80060260: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80060264: sra         $s0, $a1, 8
    ctx->r16 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80060268: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006026C: jal         0x80062180
    // 0x80060270: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80060270: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    after_0:
    // 0x80060274: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x80060278: lbu         $v0, 0x2F($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X2F);
    // 0x8006027C: lhu         $v1, 0x2($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X2);
    // 0x80060280: lui         $a0, 0xE00
    ctx->r4 = S32(0XE00 << 16);
    // 0x80060284: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80060288: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x8006028C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80060290: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    // 0x80060294: lw          $a0, 0x28($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X28);
    // 0x80060298: jal         0x80062180
    // 0x8006029C: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x8006029C: sll         $s0, $s0, 24
    ctx->r16 = S32(ctx->r16 << 24);
    after_1:
    // 0x800602A0: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x800602A4: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x800602A8: addiu       $v1, $s1, 0x10
    ctx->r3 = ADD32(ctx->r17, 0X10);
    // 0x800602AC: and         $a0, $v0, $a0
    ctx->r4 = ctx->r2 & ctx->r4;
    // 0x800602B0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x800602B4: or          $s0, $s0, $a0
    ctx->r16 = ctx->r16 | ctx->r4;
    // 0x800602B8: sw          $s0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r16;
    // 0x800602BC: sw          $zero, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = 0;
    // 0x800602C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800602C4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800602C8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800602CC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800602D0: jr          $ra
    // 0x800602D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800602D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800602E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800602E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800602E4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800602E8: jal         0x80060380
    // 0x800602EC: nop

    func_80060380(rdram, ctx);
        goto after_0;
    // 0x800602EC: nop

    after_0:
    // 0x800602F0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800602F4: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x800602F8: lui         $v0, 0xD00
    ctx->r2 = S32(0XD00 << 16);
    // 0x800602FC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80060300: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80060304: lw          $a0, 0x60B4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60B4);
    // 0x80060308: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8006030C: lui         $v0, 0x62E
    ctx->r2 = S32(0X62E << 16);
    // 0x80060310: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80060314: lw          $a0, 0x54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54);
    // 0x80060318: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8006031C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80060320: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x80060324: jr          $ra
    // 0x80060328: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80060328: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80060330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060330: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80060334: lw          $v0, 0x60B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60B4);
    // 0x80060338: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006033C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80060340: sll         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4 << 16);
    // 0x80060344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80060348: lw          $v0, 0x40($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X40);
    // 0x8006034C: sra         $s0, $s0, 14
    ctx->r16 = S32(SIGNED(ctx->r16) >> 14);
    // 0x80060350: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    // 0x80060354: jal         0x8005E070
    // 0x80060358: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_8005E070(rdram, ctx);
        goto after_0;
    // 0x80060358: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_0:
    // 0x8006035C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80060360: lw          $v0, 0x60B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X60B4);
    // 0x80060364: lw          $v0, 0x40($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X40);
    // 0x80060368: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8006036C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80060370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060374: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80060378: jr          $ra
    // 0x8006037C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006037C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80060380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060380: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060384: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80060388: lw          $v1, 0x60B4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X60B4);
    // 0x8006038C: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x80060390: ori         $v0, $v0, 0x4E0
    ctx->r2 = ctx->r2 | 0X4E0;
    // 0x80060394: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80060398: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8006039C: addiu       $v0, $zero, 0x2E0
    ctx->r2 = ADD32(0, 0X2E0);
    // 0x800603A0: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x800603A4: lw          $v0, 0x3C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X3C);
    // 0x800603A8: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800603AC: jalr        $v0
    // 0x800603B0: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800603B0: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    after_0:
    // 0x800603B4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800603B8: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x800603BC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800603C0: lui         $a2, 0xC00
    ctx->r6 = S32(0XC00 << 16);
    // 0x800603C4: ori         $a2, $a2, 0x7FFF
    ctx->r6 = ctx->r6 | 0X7FFF;
    // 0x800603C8: lui         $a0, 0x7C0
    ctx->r4 = S32(0X7C0 << 16);
    // 0x800603CC: ori         $a0, $a0, 0x4E0
    ctx->r4 = ctx->r4 | 0X4E0;
    // 0x800603D0: lui         $a3, 0x930
    ctx->r7 = S32(0X930 << 16);
    // 0x800603D4: ori         $a3, $a3, 0x650
    ctx->r7 = ctx->r7 | 0X650;
    // 0x800603D8: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x800603DC: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x800603E0: sw          $a0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r4;
    // 0x800603E4: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x800603E8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800603EC: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x800603F0: jr          $ra
    // 0x800603F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800603F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void cosf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060400: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x80060404: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80060408: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8006040C: andi        $v0, $v0, 0x1FF
    ctx->r2 = ctx->r2 & 0X1FF;
    // 0x80060410: slti        $v0, $v0, 0x136
    ctx->r2 = SIGNED(ctx->r2) < 0X136 ? 1 : 0;
    // 0x80060414: beq         $v0, $zero, L_80060524
    if (ctx->r2 == 0) {
        // 0x80060418: nop
    
            goto L_80060524;
    }
    // 0x80060418: nop

    // 0x8006041C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80060420: nop

    // 0x80060424: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80060428: nop

    // 0x8006042C: nop

    // 0x80060430: bc1t        L_8006043C
    if (c1cs) {
        // 0x80060434: mov.s       $f4, $f12
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.fl = ctx->f12.fl;
            goto L_8006043C;
    }
    // 0x80060434: mov.s       $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.fl = ctx->f12.fl;
    // 0x80060438: neg.s       $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = -ctx->f12.fl;
L_8006043C:
    // 0x8006043C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80060440: ldc1        $f0, -0x1088($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1088);
    // 0x80060444: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80060448: mul.d       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x8006044C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80060450: ldc1        $f2, -0x1068($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1068);
    // 0x80060454: add.d       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f0.d + ctx->f2.d;
    // 0x80060458: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006045C: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x80060460: nop

    // 0x80060464: c.le.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d <= ctx->f4.d;
    // 0x80060468: nop

    // 0x8006046C: nop

    // 0x80060470: bc1fl       L_8006047C
    if (!c1cs) {
        // 0x80060474: sub.d       $f0, $f4, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f4.d - ctx->f2.d;
            goto L_8006047C;
    }
    goto skip_0;
    // 0x80060474: sub.d       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f4.d - ctx->f2.d;
    skip_0:
    // 0x80060478: add.d       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f4.d + ctx->f2.d;
L_8006047C:
    // 0x8006047C: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80060480: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x80060484: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80060488: ldc1        $f0, -0x1060($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1060);
    // 0x8006048C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80060490: nop

    // 0x80060494: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x80060498: sub.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d - ctx->f0.d;
    // 0x8006049C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800604A0: ldc1        $f2, -0x1080($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1080);
    // 0x800604A4: mul.d       $f2, $f4, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x800604A8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800604AC: ldc1        $f0, -0x1078($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1078);
    // 0x800604B0: mul.d       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800604B4: sub.d       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f6.d - ctx->f2.d;
    // 0x800604B8: sub.d       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f6.d - ctx->f0.d;
    // 0x800604BC: mul.d       $f4, $f6, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f6.d);
    // 0x800604C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800604C4: ldc1        $f0, -0x1090($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1090);
    // 0x800604C8: mul.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x800604CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800604D0: ldc1        $f2, -0x1098($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1098);
    // 0x800604D4: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x800604D8: mul.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x800604DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800604E0: ldc1        $f2, -0x10A0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X10A0);
    // 0x800604E4: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x800604E8: mul.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x800604EC: nop

    // 0x800604F0: mul.d       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x800604F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800604F8: ldc1        $f2, -0x10A8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X10A8);
    // 0x800604FC: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x80060500: mul.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80060504: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x80060508: bne         $v0, $zero, L_80060518
    if (ctx->r2 != 0) {
        // 0x8006050C: add.d       $f0, $f6, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f6.d + ctx->f4.d;
            goto L_80060518;
    }
    // 0x8006050C: add.d       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f6.d + ctx->f4.d;
    // 0x80060510: j           L_80060548
    // 0x80060514: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
        goto L_80060548;
    // 0x80060514: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
L_80060518:
    // 0x80060518: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8006051C: j           L_80060548
    // 0x80060520: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_80060548;
    // 0x80060520: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_80060524:
    // 0x80060524: c.eq.s      $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f12.fl == ctx->f12.fl;
    // 0x80060528: nop

    // 0x8006052C: bc1f        L_80060540
    if (!c1cs) {
        // 0x80060530: nop
    
            goto L_80060540;
    }
    // 0x80060530: nop

    // 0x80060534: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80060538: j           L_80060548
    // 0x8006053C: lwc1        $f0, -0x1070($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1070);
        goto L_80060548;
    // 0x8006053C: lwc1        $f0, -0x1070($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1070);
L_80060540:
    // 0x80060540: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80060544: lwc1        $f0, -0xC80($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XC80);
L_80060548:
    // 0x80060548: jr          $ra
    // 0x8006054C: nop

    return;
    // 0x8006054C: nop

;}
RECOMP_FUNC void func_80060550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80060554: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80060558: addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
    // 0x8006055C: jal         0x80061430
    // 0x80060560: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    func_80061430(rdram, ctx);
        goto after_0;
    // 0x80060560: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x80060564: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80060568: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8006056C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80060570: jr          $ra
    // 0x80060574: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80060574: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void guLookAtF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060580: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80060584: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80060588: lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X8C);
    // 0x8006058C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80060590: lw          $s2, 0x90($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X90);
    // 0x80060594: sdc1        $f26, 0x58($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X58, ctx->r29);
    // 0x80060598: lwc1        $f26, 0x94($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8006059C: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x800605A0: lwc1        $f20, 0x80($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800605A4: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x800605A8: lwc1        $f22, 0x84($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800605AC: sdc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X50, ctx->r29);
    // 0x800605B0: lwc1        $f24, 0x88($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800605B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800605B8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800605BC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800605C0: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x800605C4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800605C8: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x800605CC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800605D0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800605D4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800605D8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800605DC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800605E0: sdc1        $f30, 0x68($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X68, ctx->r29);
    // 0x800605E4: sdc1        $f28, 0x60($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X60, ctx->r29);
    // 0x800605E8: jal         0x80060DD0
    // 0x800605EC: addu        $fp, $a3, $zero
    ctx->r30 = ADD32(ctx->r7, 0);
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x800605EC: addu        $fp, $a3, $zero
    ctx->r30 = ADD32(ctx->r7, 0);
    after_0:
    // 0x800605F0: mtc1        $s4, $f14
    ctx->f14.u32l = ctx->r20;
    // 0x800605F4: nop

    // 0x800605F8: sub.s       $f28, $f20, $f14
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f28.fl = ctx->f20.fl - ctx->f14.fl;
    // 0x800605FC: mtc1        $s5, $f18
    ctx->f18.u32l = ctx->r21;
    // 0x80060600: mul.s       $f0, $f28, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x80060604: sub.s       $f30, $f22, $f18
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f30.fl = ctx->f22.fl - ctx->f18.fl;
    // 0x80060608: mtc1        $fp, $f14
    ctx->f14.u32l = ctx->r30;
    // 0x8006060C: nop

    // 0x80060610: sub.s       $f14, $f24, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f24.fl - ctx->f14.fl;
    // 0x80060614: mul.s       $f4, $f30, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x80060618: mfc1        $s1, $f14
    ctx->r17 = (int32_t)ctx->f14.u32l;
    // 0x8006061C: nop

    // 0x80060620: mtc1        $s1, $f18
    ctx->f18.u32l = ctx->r17;
    // 0x80060624: nop

    // 0x80060628: mul.s       $f2, $f14, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x8006062C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80060630: add.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80060634: sqrt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = sqrtf(ctx->f12.fl);
    // 0x80060638: c.eq.s      $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f2.fl == ctx->f2.fl;
    // 0x8006063C: nop

    // 0x80060640: bc1t        L_80060654
    if (c1cs) {
        // 0x80060644: nop
    
            goto L_80060654;
    }
    // 0x80060644: nop

    // 0x80060648: jal         0x80068AB0
    // 0x8006064C: nop

    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8006064C: nop

    after_1:
    // 0x80060650: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80060654:
    // 0x80060654: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80060658: ldc1        $f0, -0x1050($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1050);
    // 0x8006065C: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x80060660: div.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x80060664: cvt.s.d     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f16.fl = CVT_S_D(ctx->f0.d);
    // 0x80060668: mul.s       $f28, $f28, $f16
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f28.fl = MUL_S(ctx->f28.fl, ctx->f16.fl);
    // 0x8006066C: mtc1        $s1, $f14
    ctx->f14.u32l = ctx->r17;
    // 0x80060670: nop

    // 0x80060674: mul.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80060678: nop

    // 0x8006067C: mul.s       $f30, $f30, $f16
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f30.fl = MUL_S(ctx->f30.fl, ctx->f16.fl);
    // 0x80060680: mtc1        $s2, $f18
    ctx->f18.u32l = ctx->r18;
    // 0x80060684: nop

    // 0x80060688: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x8006068C: nop

    // 0x80060690: mul.s       $f0, $f26, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f30.fl);
    // 0x80060694: nop

    // 0x80060698: mul.s       $f8, $f26, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f28.fl);
    // 0x8006069C: mtc1        $s3, $f18
    ctx->f18.u32l = ctx->r19;
    // 0x800606A0: nop

    // 0x800606A4: mul.s       $f2, $f18, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x800606A8: nop

    // 0x800606AC: mul.s       $f10, $f18, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f30.fl);
    // 0x800606B0: mfc1        $s1, $f14
    ctx->r17 = (int32_t)ctx->f14.u32l;
    // 0x800606B4: mtc1        $s2, $f14
    ctx->f14.u32l = ctx->r18;
    // 0x800606B8: nop

    // 0x800606BC: mul.s       $f6, $f14, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f28.fl);
    // 0x800606C0: sub.s       $f24, $f4, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800606C4: mul.s       $f0, $f24, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x800606C8: sub.s       $f22, $f8, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800606CC: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800606D0: sub.s       $f20, $f10, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800606D4: mul.s       $f2, $f20, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800606D8: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800606DC: add.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800606E0: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    // 0x800606E4: c.eq.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f0.fl == ctx->f0.fl;
    // 0x800606E8: nop

    // 0x800606EC: bc1t        L_800606FC
    if (c1cs) {
        // 0x800606F0: nop
    
            goto L_800606FC;
    }
    // 0x800606F0: nop

    // 0x800606F4: jal         0x80068AB0
    // 0x800606F8: nop

    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800606F8: nop

    after_2:
L_800606FC:
    // 0x800606FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80060700: lw          $s6, -0x1048($at)
    ctx->r22 = MEM_W(ctx->r1, -0X1048);
    // 0x80060704: lw          $s7, -0x1044($at)
    ctx->r23 = MEM_W(ctx->r1, -0X1044);
    // 0x80060708: mtc1        $s7, $f18
    ctx->f18.u32l = ctx->r23;
    // 0x8006070C: mtc1        $s6, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r22;
    // 0x80060710: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80060714: div.d       $f0, $f18, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x80060718: cvt.s.d     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f16.fl = CVT_S_D(ctx->f0.d);
    // 0x8006071C: mul.s       $f24, $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f16.fl);
    // 0x80060720: nop

    // 0x80060724: mul.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x80060728: nop

    // 0x8006072C: mul.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f16.fl);
    // 0x80060730: nop

    // 0x80060734: mul.s       $f4, $f30, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f30.fl, ctx->f20.fl);
    // 0x80060738: mtc1        $s1, $f14
    ctx->f14.u32l = ctx->r17;
    // 0x8006073C: nop

    // 0x80060740: mul.s       $f0, $f14, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f22.fl);
    // 0x80060744: nop

    // 0x80060748: mul.s       $f8, $f14, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f24.fl);
    // 0x8006074C: nop

    // 0x80060750: mul.s       $f2, $f28, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f28.fl, ctx->f20.fl);
    // 0x80060754: nop

    // 0x80060758: mul.s       $f10, $f28, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f22.fl);
    // 0x8006075C: nop

    // 0x80060760: mul.s       $f6, $f30, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f30.fl, ctx->f24.fl);
    // 0x80060764: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80060768: mul.s       $f0, $f4, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8006076C: sub.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80060770: mfc1        $s3, $f4
    ctx->r19 = (int32_t)ctx->f4.u32l;
    // 0x80060774: mul.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80060778: sub.s       $f26, $f10, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8006077C: mul.s       $f2, $f26, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x80060780: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80060784: add.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80060788: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    // 0x8006078C: c.eq.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f0.fl == ctx->f0.fl;
    // 0x80060790: mfc1        $s2, $f8
    ctx->r18 = (int32_t)ctx->f8.u32l;
    // 0x80060794: nop

    // 0x80060798: bc1tl       L_800607B4
    if (c1cs) {
        // 0x8006079C: cvt.d.s     $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
            goto L_800607B4;
    }
    goto skip_0;
    // 0x8006079C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    skip_0:
    // 0x800607A0: jal         0x80068AB0
    // 0x800607A4: nop

    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800607A4: nop

    after_3:
    // 0x800607A8: mtc1        $s7, $f18
    ctx->f18.u32l = ctx->r23;
    // 0x800607AC: mtc1        $s6, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r22;
    // 0x800607B0: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
L_800607B4:
    // 0x800607B4: div.d       $f0, $f18, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x800607B8: mtc1        $s3, $f14
    ctx->f14.u32l = ctx->r19;
    // 0x800607BC: cvt.s.d     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f16.fl = CVT_S_D(ctx->f0.d);
    // 0x800607C0: mul.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800607C4: mtc1        $s2, $f18
    ctx->f18.u32l = ctx->r18;
    // 0x800607C8: nop

    // 0x800607CC: mul.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800607D0: nop

    // 0x800607D4: mul.s       $f26, $f26, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f16.fl);
    // 0x800607D8: mfc1        $s3, $f14
    ctx->r19 = (int32_t)ctx->f14.u32l;
    // 0x800607DC: mtc1        $s4, $f14
    ctx->f14.u32l = ctx->r20;
    // 0x800607E0: nop

    // 0x800607E4: mul.s       $f2, $f14, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f24.fl);
    // 0x800607E8: mfc1        $s2, $f18
    ctx->r18 = (int32_t)ctx->f18.u32l;
    // 0x800607EC: mtc1        $s5, $f18
    ctx->f18.u32l = ctx->r21;
    // 0x800607F0: nop

    // 0x800607F4: mul.s       $f6, $f18, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x800607F8: mtc1        $fp, $f14
    ctx->f14.u32l = ctx->r30;
    // 0x800607FC: nop

    // 0x80060800: mul.s       $f8, $f14, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80060804: mtc1        $s4, $f18
    ctx->f18.u32l = ctx->r20;
    // 0x80060808: mtc1        $s3, $f14
    ctx->f14.u32l = ctx->r19;
    // 0x8006080C: nop

    // 0x80060810: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x80060814: mtc1        $s5, $f18
    ctx->f18.u32l = ctx->r21;
    // 0x80060818: mtc1        $s2, $f14
    ctx->f14.u32l = ctx->r18;
    // 0x8006081C: nop

    // 0x80060820: mul.s       $f10, $f18, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x80060824: mtc1        $s4, $f18
    ctx->f18.u32l = ctx->r20;
    // 0x80060828: nop

    // 0x8006082C: mul.s       $f0, $f18, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x80060830: mtc1        $s5, $f14
    ctx->f14.u32l = ctx->r21;
    // 0x80060834: nop

    // 0x80060838: mul.s       $f12, $f14, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x8006083C: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80060840: mtc1        $s1, $f14
    ctx->f14.u32l = ctx->r17;
    // 0x80060844: mtc1        $fp, $f18
    ctx->f18.u32l = ctx->r30;
    // 0x80060848: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8006084C: swc1        $f24, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f24.u32l;
    // 0x80060850: mul.s       $f14, $f18, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x80060854: swc1        $f22, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f22.u32l;
    // 0x80060858: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8006085C: swc1        $f20, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f20.u32l;
    // 0x80060860: swc1        $f28, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f28.u32l;
    // 0x80060864: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80060868: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006086C: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80060870: mul.s       $f8, $f18, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f26.fl);
    // 0x80060874: swc1        $f30, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f30.u32l;
    // 0x80060878: sw          $s1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r17;
    // 0x8006087C: add.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80060880: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x80060884: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80060888: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x8006088C: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80060890: swc1        $f26, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f26.u32l;
    // 0x80060894: sw          $s3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r19;
    // 0x80060898: sw          $s2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r18;
    // 0x8006089C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800608A0: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x800608A4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800608A8: swc1        $f2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f2.u32l;
    // 0x800608AC: neg.s       $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = -ctx->f4.fl;
    // 0x800608B0: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x800608B4: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x800608B8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800608BC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800608C0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800608C4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800608C8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800608CC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800608D0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800608D4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800608D8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800608DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800608E0: ldc1        $f30, 0x68($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X68);
    // 0x800608E4: ldc1        $f28, 0x60($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X60);
    // 0x800608E8: ldc1        $f26, 0x58($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X58);
    // 0x800608EC: ldc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X50);
    // 0x800608F0: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x800608F4: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x800608F8: jr          $ra
    // 0x800608FC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800608FC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void guLookAt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060900: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80060904: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x80060908: lw          $s2, 0xD4($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XD4);
    // 0x8006090C: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x80060910: lw          $s1, 0xD8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XD8);
    // 0x80060914: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x80060918: lw          $s0, 0xDC($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XDC);
    // 0x8006091C: sdc1        $f20, 0x88($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X88, ctx->r29);
    // 0x80060920: lwc1        $f20, 0xC8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80060924: sdc1        $f22, 0x90($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X90, ctx->r29);
    // 0x80060928: lwc1        $f22, 0xCC($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8006092C: sdc1        $f24, 0x98($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X98, ctx->r29);
    // 0x80060930: lwc1        $f24, 0xD0($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x80060934: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x80060938: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x8006093C: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x80060940: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x80060944: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x80060948: addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // 0x8006094C: sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
    // 0x80060950: addiu       $fp, $sp, 0x10
    ctx->r30 = ADD32(ctx->r29, 0X10);
    // 0x80060954: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    // 0x80060958: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x8006095C: sw          $s7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r23;
    // 0x80060960: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x80060964: sdc1        $f30, 0xB0($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0XB0, ctx->r29);
    // 0x80060968: sdc1        $f28, 0xA8($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0XA8, ctx->r29);
    // 0x8006096C: sdc1        $f26, 0xA0($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0XA0, ctx->r29);
    // 0x80060970: jal         0x80060DD0
    // 0x80060974: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x80060974: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    after_0:
    // 0x80060978: mtc1        $s3, $f14
    ctx->f14.u32l = ctx->r19;
    // 0x8006097C: nop

    // 0x80060980: sub.s       $f26, $f20, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f26.fl = ctx->f20.fl - ctx->f14.fl;
    // 0x80060984: mul.s       $f0, $f26, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x80060988: mtc1        $s4, $f18
    ctx->f18.u32l = ctx->r20;
    // 0x8006098C: nop

    // 0x80060990: sub.s       $f28, $f22, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f28.fl = ctx->f22.fl - ctx->f18.fl;
    // 0x80060994: mul.s       $f4, $f28, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x80060998: mtc1        $s5, $f14
    ctx->f14.u32l = ctx->r21;
    // 0x8006099C: nop

    // 0x800609A0: sub.s       $f30, $f24, $f14
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f30.fl = ctx->f24.fl - ctx->f14.fl;
    // 0x800609A4: mul.s       $f2, $f30, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x800609A8: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800609AC: add.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800609B0: sqrt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = sqrtf(ctx->f12.fl);
    // 0x800609B4: c.eq.s      $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f2.fl == ctx->f2.fl;
    // 0x800609B8: nop

    // 0x800609BC: bc1t        L_800609D0
    if (c1cs) {
        // 0x800609C0: nop
    
            goto L_800609D0;
    }
    // 0x800609C0: nop

    // 0x800609C4: jal         0x80068AB0
    // 0x800609C8: nop

    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800609C8: nop

    after_1:
    // 0x800609CC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800609D0:
    // 0x800609D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800609D4: ldc1        $f0, -0x1040($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1040);
    // 0x800609D8: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x800609DC: div.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x800609E0: cvt.s.d     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f16.fl = CVT_S_D(ctx->f0.d);
    // 0x800609E4: mul.s       $f26, $f26, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f16.fl);
    // 0x800609E8: nop

    // 0x800609EC: mul.s       $f30, $f30, $f16
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f30.fl = MUL_S(ctx->f30.fl, ctx->f16.fl);
    // 0x800609F0: nop

    // 0x800609F4: mul.s       $f28, $f28, $f16
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f28.fl = MUL_S(ctx->f28.fl, ctx->f16.fl);
    // 0x800609F8: mtc1        $s1, $f18
    ctx->f18.u32l = ctx->r17;
    // 0x800609FC: nop

    // 0x80060A00: mul.s       $f4, $f18, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f30.fl);
    // 0x80060A04: mtc1        $s0, $f14
    ctx->f14.u32l = ctx->r16;
    // 0x80060A08: nop

    // 0x80060A0C: mul.s       $f0, $f14, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f28.fl);
    // 0x80060A10: nop

    // 0x80060A14: mul.s       $f8, $f14, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f26.fl);
    // 0x80060A18: mtc1        $s2, $f18
    ctx->f18.u32l = ctx->r18;
    // 0x80060A1C: nop

    // 0x80060A20: mul.s       $f2, $f18, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f30.fl);
    // 0x80060A24: nop

    // 0x80060A28: mul.s       $f10, $f18, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x80060A2C: mtc1        $s1, $f14
    ctx->f14.u32l = ctx->r17;
    // 0x80060A30: nop

    // 0x80060A34: mul.s       $f6, $f14, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f26.fl);
    // 0x80060A38: sub.s       $f24, $f4, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80060A3C: mul.s       $f0, $f24, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x80060A40: sub.s       $f22, $f8, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80060A44: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80060A48: sub.s       $f20, $f10, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80060A4C: mul.s       $f2, $f20, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80060A50: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80060A54: add.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80060A58: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    // 0x80060A5C: c.eq.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f0.fl == ctx->f0.fl;
    // 0x80060A60: nop

    // 0x80060A64: bc1t        L_80060A74
    if (c1cs) {
        // 0x80060A68: nop
    
            goto L_80060A74;
    }
    // 0x80060A68: nop

    // 0x80060A6C: jal         0x80068AB0
    // 0x80060A70: nop

    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80060A70: nop

    after_2:
L_80060A74:
    // 0x80060A74: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80060A78: lw          $s6, -0x1038($at)
    ctx->r22 = MEM_W(ctx->r1, -0X1038);
    // 0x80060A7C: lw          $s7, -0x1034($at)
    ctx->r23 = MEM_W(ctx->r1, -0X1034);
    // 0x80060A80: mtc1        $s7, $f18
    ctx->f18.u32l = ctx->r23;
    // 0x80060A84: mtc1        $s6, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r22;
    // 0x80060A88: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80060A8C: div.d       $f0, $f18, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = DIV_D(ctx->f18.d, ctx->f0.d);
    // 0x80060A90: cvt.s.d     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f16.fl = CVT_S_D(ctx->f0.d);
    // 0x80060A94: mul.s       $f24, $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f16.fl);
    // 0x80060A98: nop

    // 0x80060A9C: mul.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x80060AA0: nop

    // 0x80060AA4: mul.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f16.fl);
    // 0x80060AA8: nop

    // 0x80060AAC: mul.s       $f4, $f28, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f20.fl);
    // 0x80060AB0: nop

    // 0x80060AB4: mul.s       $f0, $f30, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f30.fl, ctx->f22.fl);
    // 0x80060AB8: nop

    // 0x80060ABC: mul.s       $f8, $f30, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f30.fl, ctx->f24.fl);
    // 0x80060AC0: nop

    // 0x80060AC4: mul.s       $f2, $f26, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x80060AC8: nop

    // 0x80060ACC: mul.s       $f10, $f26, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f22.fl);
    // 0x80060AD0: nop

    // 0x80060AD4: mul.s       $f6, $f28, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f24.fl);
    // 0x80060AD8: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80060ADC: mul.s       $f0, $f4, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80060AE0: sub.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80060AE4: mfc1        $s2, $f4
    ctx->r18 = (int32_t)ctx->f4.u32l;
    // 0x80060AE8: mul.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80060AEC: sub.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80060AF0: mul.s       $f2, $f10, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80060AF4: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80060AF8: add.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80060AFC: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    // 0x80060B00: c.eq.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f0.fl == ctx->f0.fl;
    // 0x80060B04: mfc1        $s1, $f8
    ctx->r17 = (int32_t)ctx->f8.u32l;
    // 0x80060B08: mfc1        $s0, $f10
    ctx->r16 = (int32_t)ctx->f10.u32l;
    // 0x80060B0C: bc1t        L_80060B1C
    if (c1cs) {
        // 0x80060B10: nop
    
            goto L_80060B1C;
    }
    // 0x80060B10: nop

    // 0x80060B14: jal         0x80068AB0
    // 0x80060B18: nop

    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x80060B18: nop

    after_3:
L_80060B1C:
    // 0x80060B1C: mtc1        $s7, $f14
    ctx->f14.u32l = ctx->r23;
    // 0x80060B20: mtc1        $s6, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r22;
    // 0x80060B24: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80060B28: div.d       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = DIV_D(ctx->f14.d, ctx->f0.d);
    // 0x80060B2C: mtc1        $s2, $f18
    ctx->f18.u32l = ctx->r18;
    // 0x80060B30: cvt.s.d     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f16.fl = CVT_S_D(ctx->f0.d);
    // 0x80060B34: mul.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80060B38: mtc1        $s1, $f14
    ctx->f14.u32l = ctx->r17;
    // 0x80060B3C: nop

    // 0x80060B40: mul.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80060B44: mfc1        $s2, $f18
    ctx->r18 = (int32_t)ctx->f18.u32l;
    // 0x80060B48: mtc1        $s3, $f18
    ctx->f18.u32l = ctx->r19;
    // 0x80060B4C: nop

    // 0x80060B50: mul.s       $f2, $f18, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x80060B54: mfc1        $s1, $f14
    ctx->r17 = (int32_t)ctx->f14.u32l;
    // 0x80060B58: mtc1        $s4, $f14
    ctx->f14.u32l = ctx->r20;
    // 0x80060B5C: nop

    // 0x80060B60: mul.s       $f6, $f14, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f22.fl);
    // 0x80060B64: mtc1        $s5, $f18
    ctx->f18.u32l = ctx->r21;
    // 0x80060B68: nop

    // 0x80060B6C: mul.s       $f8, $f18, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80060B70: mtc1        $s3, $f14
    ctx->f14.u32l = ctx->r19;
    // 0x80060B74: mtc1        $s2, $f18
    ctx->f18.u32l = ctx->r18;
    // 0x80060B78: nop

    // 0x80060B7C: mul.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x80060B80: mtc1        $s4, $f14
    ctx->f14.u32l = ctx->r20;
    // 0x80060B84: mtc1        $s1, $f18
    ctx->f18.u32l = ctx->r17;
    // 0x80060B88: nop

    // 0x80060B8C: mul.s       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x80060B90: mtc1        $s3, $f14
    ctx->f14.u32l = ctx->r19;
    // 0x80060B94: nop

    // 0x80060B98: mul.s       $f0, $f14, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f26.fl);
    // 0x80060B9C: mtc1        $s4, $f18
    ctx->f18.u32l = ctx->r20;
    // 0x80060BA0: nop

    // 0x80060BA4: mul.s       $f12, $f18, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x80060BA8: mtc1        $s5, $f14
    ctx->f14.u32l = ctx->r21;
    // 0x80060BAC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80060BB0: mul.s       $f14, $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x80060BB4: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80060BB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80060BBC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80060BC0: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // 0x80060BC4: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x80060BC8: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
    // 0x80060BCC: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80060BD0: swc1        $f22, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f22.u32l;
    // 0x80060BD4: mul.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80060BD8: swc1        $f20, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f20.u32l;
    // 0x80060BDC: add.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80060BE0: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x80060BE4: swc1        $f28, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f28.u32l;
    // 0x80060BE8: mtc1        $s5, $f14
    ctx->f14.u32l = ctx->r21;
    // 0x80060BEC: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80060BF0: mul.s       $f8, $f14, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x80060BF4: swc1        $f30, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f30.u32l;
    // 0x80060BF8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80060BFC: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80060C00: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80060C04: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80060C08: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x80060C0C: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80060C10: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80060C14: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x80060C18: mfc1        $s0, $f18
    ctx->r16 = (int32_t)ctx->f18.u32l;
    // 0x80060C1C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80060C20: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80060C24: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80060C28: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x80060C2C: neg.s       $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = -ctx->f4.fl;
    // 0x80060C30: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80060C34: jal         0x80060C90
    // 0x80060C38: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    guMtxF2L(rdram, ctx);
        goto after_4;
    // 0x80060C38: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80060C3C: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x80060C40: lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X80);
    // 0x80060C44: lw          $s7, 0x7C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X7C);
    // 0x80060C48: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x80060C4C: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x80060C50: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x80060C54: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x80060C58: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x80060C5C: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x80060C60: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x80060C64: ldc1        $f30, 0xB0($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0XB0);
    // 0x80060C68: ldc1        $f28, 0xA8($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0XA8);
    // 0x80060C6C: ldc1        $f26, 0xA0($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0XA0);
    // 0x80060C70: ldc1        $f24, 0x98($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X98);
    // 0x80060C74: ldc1        $f22, 0x90($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X90);
    // 0x80060C78: ldc1        $f20, 0x88($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X88);
    // 0x80060C7C: jr          $ra
    // 0x80060C80: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80060C80: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void guMtxF2L(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060C90: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x80060C94: addiu       $t1, $t0, 0x20
    ctx->r9 = ADD32(ctx->r8, 0X20);
    // 0x80060C98: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // 0x80060C9C: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80060CA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80060CA4: lui         $t4, 0xFFFF
    ctx->r12 = S32(0XFFFF << 16);
    // 0x80060CA8: addu        $t2, $a0, $zero
    ctx->r10 = ADD32(ctx->r4, 0);
L_80060CAC:
    // 0x80060CAC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80060CB0: addu        $a2, $t2, $zero
    ctx->r6 = ADD32(ctx->r10, 0);
L_80060CB4:
    // 0x80060CB4: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80060CB8: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80060CBC: lwc1        $f0, 0x4($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80060CC0: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80060CC4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80060CC8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80060CCC: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80060CD0: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80060CD4: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80060CD8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80060CDC: and         $v0, $a0, $t4
    ctx->r2 = ctx->r4 & ctx->r12;
    // 0x80060CE0: srl         $v1, $a1, 16
    ctx->r3 = S32(U32(ctx->r5) >> 16);
    // 0x80060CE4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80060CE8: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80060CEC: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80060CF0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80060CF4: and         $a0, $a0, $t4
    ctx->r4 = ctx->r4 & ctx->r12;
    // 0x80060CF8: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80060CFC: or          $a0, $a0, $a1
    ctx->r4 = ctx->r4 | ctx->r5;
    // 0x80060D00: sw          $a0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r4;
    // 0x80060D04: slti        $v0, $a3, 0x2
    ctx->r2 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x80060D08: bne         $v0, $zero, L_80060CB4
    if (ctx->r2 != 0) {
        // 0x80060D0C: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_80060CB4;
    }
    // 0x80060D0C: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80060D10: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80060D14: slti        $v0, $t3, 0x4
    ctx->r2 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x80060D18: bne         $v0, $zero, L_80060CAC
    if (ctx->r2 != 0) {
        // 0x80060D1C: addiu       $t2, $t2, 0x10
        ctx->r10 = ADD32(ctx->r10, 0X10);
            goto L_80060CAC;
    }
    // 0x80060D1C: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
    // 0x80060D20: jr          $ra
    // 0x80060D24: nop

    return;
    // 0x80060D24: nop

;}
RECOMP_FUNC void func_80060D28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060D28: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80060D2C: addiu       $t0, $a1, 0x20
    ctx->r8 = ADD32(ctx->r5, 0X20);
    // 0x80060D30: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x80060D34: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
    // 0x80060D38: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x80060D3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80060D40:
    // 0x80060D40: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80060D44: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
L_80060D48:
    // 0x80060D48: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80060D4C: lhu         $v1, 0x0($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X0);
    // 0x80060D50: and         $v0, $v0, $t2
    ctx->r2 = ctx->r2 & ctx->r10;
    // 0x80060D54: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80060D58: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x80060D5C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80060D60: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x80060D64: nop

    // 0x80060D68: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80060D6C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80060D70: lhu         $v0, 0x2($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X2);
    // 0x80060D74: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80060D78: and         $v1, $v1, $t2
    ctx->r3 = ctx->r3 & ctx->r10;
    // 0x80060D7C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80060D80: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x80060D84: nop

    // 0x80060D88: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80060D8C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80060D90: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80060D94: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80060D98: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80060D9C: slti        $v0, $a3, 0x2
    ctx->r2 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x80060DA0: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x80060DA4: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x80060DA8: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
    // 0x80060DAC: bne         $v0, $zero, L_80060D48
    if (ctx->r2 != 0) {
        // 0x80060DB0: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_80060D48;
    }
    // 0x80060DB0: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80060DB4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80060DB8: slti        $v0, $t1, 0x4
    ctx->r2 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x80060DBC: bne         $v0, $zero, L_80060D40
    if (ctx->r2 != 0) {
        // 0x80060DC0: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_80060D40;
    }
    // 0x80060DC0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80060DC4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80060DC8: jr          $ra
    // 0x80060DCC: nop

    return;
    // 0x80060DCC: nop

;}
RECOMP_FUNC void guMtxIdentF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060DD0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80060DD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80060DD8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80060DDC: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
L_80060DE0:
    // 0x80060DE0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80060DE4: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_80060DE8:
    // 0x80060DE8: bnel        $a2, $v1, L_80060DF4
    if (ctx->r6 != ctx->r3) {
        // 0x80060DEC: sw          $zero, 0x0($a1)
        MEM_W(0X0, ctx->r5) = 0;
            goto L_80060DF4;
    }
    goto skip_0;
    // 0x80060DEC: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    skip_0:
    // 0x80060DF0: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
L_80060DF4:
    // 0x80060DF4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80060DF8: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80060DFC: bne         $v0, $zero, L_80060DE8
    if (ctx->r2 != 0) {
        // 0x80060E00: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80060DE8;
    }
    // 0x80060E00: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80060E04: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    // 0x80060E08: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80060E0C: slti        $v0, $a2, 0x4
    ctx->r2 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80060E10: bne         $v0, $zero, L_80060DE0
    if (ctx->r2 != 0) {
        // 0x80060E14: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_80060DE0;
    }
    // 0x80060E14: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80060E18: jr          $ra
    // 0x80060E1C: nop

    return;
    // 0x80060E1C: nop

;}
RECOMP_FUNC void guMtxIdent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060E20: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80060E24: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80060E28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80060E2C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80060E30: addu        $t1, $sp, $zero
    ctx->r9 = ADD32(ctx->r29, 0);
    // 0x80060E34: addu        $t0, $sp, $zero
    ctx->r8 = ADD32(ctx->r29, 0);
L_80060E38:
    // 0x80060E38: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80060E3C: addu        $a3, $t1, $zero
    ctx->r7 = ADD32(ctx->r9, 0);
    // 0x80060E40: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
L_80060E44:
    // 0x80060E44: bnel        $a2, $v1, L_80060E50
    if (ctx->r6 != ctx->r3) {
        // 0x80060E48: sw          $zero, 0x0($a1)
        MEM_W(0X0, ctx->r5) = 0;
            goto L_80060E50;
    }
    goto skip_0;
    // 0x80060E48: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    skip_0:
    // 0x80060E4C: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
L_80060E50:
    // 0x80060E50: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80060E54: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80060E58: bne         $v0, $zero, L_80060E44
    if (ctx->r2 != 0) {
        // 0x80060E5C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80060E44;
    }
    // 0x80060E5C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80060E60: addiu       $t1, $t1, 0x14
    ctx->r9 = ADD32(ctx->r9, 0X14);
    // 0x80060E64: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80060E68: slti        $v0, $a2, 0x4
    ctx->r2 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80060E6C: bne         $v0, $zero, L_80060E38
    if (ctx->r2 != 0) {
        // 0x80060E70: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_80060E38;
    }
    // 0x80060E70: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80060E74: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x80060E78: addiu       $t1, $t0, 0x20
    ctx->r9 = ADD32(ctx->r8, 0X20);
    // 0x80060E7C: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // 0x80060E80: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80060E84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80060E88: lui         $t4, 0xFFFF
    ctx->r12 = S32(0XFFFF << 16);
    // 0x80060E8C: addu        $t2, $sp, $zero
    ctx->r10 = ADD32(ctx->r29, 0);
L_80060E90:
    // 0x80060E90: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80060E94: addu        $a2, $t2, $zero
    ctx->r6 = ADD32(ctx->r10, 0);
L_80060E98:
    // 0x80060E98: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80060E9C: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80060EA0: lwc1        $f0, 0x4($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80060EA4: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80060EA8: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80060EAC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80060EB0: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80060EB4: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80060EB8: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80060EBC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80060EC0: and         $v0, $a0, $t4
    ctx->r2 = ctx->r4 & ctx->r12;
    // 0x80060EC4: srl         $v1, $a1, 16
    ctx->r3 = S32(U32(ctx->r5) >> 16);
    // 0x80060EC8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80060ECC: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80060ED0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80060ED4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80060ED8: and         $a0, $a0, $t4
    ctx->r4 = ctx->r4 & ctx->r12;
    // 0x80060EDC: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80060EE0: or          $a0, $a0, $a1
    ctx->r4 = ctx->r4 | ctx->r5;
    // 0x80060EE4: sw          $a0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r4;
    // 0x80060EE8: slti        $v0, $a3, 0x2
    ctx->r2 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x80060EEC: bne         $v0, $zero, L_80060E98
    if (ctx->r2 != 0) {
        // 0x80060EF0: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_80060E98;
    }
    // 0x80060EF0: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80060EF4: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80060EF8: slti        $v0, $t3, 0x4
    ctx->r2 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x80060EFC: bne         $v0, $zero, L_80060E90
    if (ctx->r2 != 0) {
        // 0x80060F00: addiu       $t2, $t2, 0x10
        ctx->r10 = ADD32(ctx->r10, 0X10);
            goto L_80060E90;
    }
    // 0x80060F00: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
    // 0x80060F04: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80060F08: jr          $ra
    // 0x80060F0C: nop

    return;
    // 0x80060F0C: nop

;}
RECOMP_FUNC void guPerspectiveF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060F10: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80060F14: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80060F18: lwc1        $f26, 0x60($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80060F1C: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80060F20: lwc1        $f28, 0x64($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80060F24: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80060F28: lwc1        $f30, 0x68($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80060F2C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80060F30: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x80060F34: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80060F38: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80060F3C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80060F40: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80060F44: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x80060F48: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80060F4C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80060F50: jal         0x80060DD0
    // 0x80060F54: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x80060F54: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    after_0:
    // 0x80060F58: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80060F5C: ldc1        $f2, -0x1030($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1030);
    // 0x80060F60: cvt.d.s     $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f0.d = CVT_D_S(ctx->f24.fl);
    // 0x80060F64: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x80060F68: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80060F6C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80060F70: cvt.s.d     $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f24.fl = CVT_S_D(ctx->f0.d);
    // 0x80060F74: div.s       $f20, $f24, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = DIV_S(ctx->f24.fl, ctx->f20.fl);
    // 0x80060F78: jal         0x80060400
    // 0x80060F7C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x80060F7C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x80060F80: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80060F84: jal         0x80061290
    // 0x80060F88: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x80060F88: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_2:
    // 0x80060F8C: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80060F90: add.s       $f4, $f26, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f26.fl + ctx->f28.fl;
    // 0x80060F94: sub.s       $f2, $f26, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = ctx->f26.fl - ctx->f28.fl;
    // 0x80060F98: div.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80060F9C: add.s       $f0, $f26, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f26.fl + ctx->f26.fl;
    // 0x80060FA0: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x80060FA4: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80060FA8: div.s       $f22, $f20, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = DIV_S(ctx->f20.fl, ctx->f22.fl);
    // 0x80060FAC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80060FB0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80060FB4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80060FB8: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80060FBC: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x80060FC0: swc1        $f20, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f20.u32l;
    // 0x80060FC4: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x80060FC8: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80060FCC: swc1        $f22, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f22.u32l;
L_80060FD0:
    // 0x80060FD0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80060FD4: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
L_80060FD8:
    // 0x80060FD8: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80060FDC: mul.s       $f0, $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x80060FE0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80060FE4: slti        $v0, $a0, 0x4
    ctx->r2 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x80060FE8: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80060FEC: bne         $v0, $zero, L_80060FD8
    if (ctx->r2 != 0) {
        // 0x80060FF0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80060FD8;
    }
    // 0x80060FF0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80060FF4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80060FF8: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80060FFC: bne         $v0, $zero, L_80060FD0
    if (ctx->r2 != 0) {
        // 0x80061000: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_80060FD0;
    }
    // 0x80061000: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80061004: beq         $s1, $zero, L_80061094
    if (ctx->r17 == 0) {
        // 0x80061008: nop
    
            goto L_80061094;
    }
    // 0x80061008: nop

    // 0x8006100C: add.s       $f2, $f26, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = ctx->f26.fl + ctx->f28.fl;
    // 0x80061010: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80061014: ldc1        $f0, -0x1028($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1028);
    // 0x80061018: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8006101C: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x80061020: nop

    // 0x80061024: nop

    // 0x80061028: bc1t        L_80061090
    if (c1cs) {
        // 0x8006102C: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_80061090;
    }
    // 0x8006102C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80061030: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80061034: ldc1        $f0, -0x1020($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1020);
    // 0x80061038: div.d       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x8006103C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80061040: ldc1        $f0, -0x1018($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1018);
    // 0x80061044: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x80061048: nop

    // 0x8006104C: nop

    // 0x80061050: bc1tl       L_8006106C
    if (c1cs) {
        // 0x80061054: sub.d       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
            goto L_8006106C;
    }
    goto skip_0;
    // 0x80061054: sub.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
    skip_0:
    // 0x80061058: trunc.w.d   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x8006105C: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x80061060: nop

    // 0x80061064: j           L_80061080
    // 0x80061068: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80061080;
    // 0x80061068: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8006106C:
    // 0x8006106C: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80061070: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x80061074: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80061078: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8006107C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80061080:
    // 0x80061080: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x80061084: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80061088: bne         $v0, $zero, L_80061094
    if (ctx->r2 != 0) {
        // 0x8006108C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80061094;
    }
    // 0x8006108C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80061090:
    // 0x80061090: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
L_80061094:
    // 0x80061094: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80061098: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8006109C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800610A0: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x800610A4: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x800610A8: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800610AC: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800610B0: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800610B4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800610B8: jr          $ra
    // 0x800610BC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800610BC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void guPerspective(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800610C0: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800610C4: sdc1        $f24, 0x70($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X70, ctx->r29);
    // 0x800610C8: lwc1        $f24, 0x98($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800610CC: sdc1        $f26, 0x78($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X78, ctx->r29);
    // 0x800610D0: lwc1        $f26, 0x9C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800610D4: sdc1        $f28, 0x80($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X80, ctx->r29);
    // 0x800610D8: lwc1        $f28, 0xA0($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800610DC: sdc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X60, ctx->r29);
    // 0x800610E0: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800610E4: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x800610E8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800610EC: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800610F0: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800610F4: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x800610F8: addiu       $s0, $sp, 0x10
    ctx->r16 = ADD32(ctx->r29, 0X10);
    // 0x800610FC: sdc1        $f22, 0x68($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X68, ctx->r29);
    // 0x80061100: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x80061104: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80061108: jal         0x80060DD0
    // 0x8006110C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x8006110C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80061110: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80061114: ldc1        $f0, -0x1010($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1010);
    // 0x80061118: cvt.d.s     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.d = CVT_D_S(ctx->f20.fl);
    // 0x8006111C: mul.d       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f20.d = MUL_D(ctx->f20.d, ctx->f0.d);
    // 0x80061120: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80061124: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80061128: cvt.s.d     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.fl = CVT_S_D(ctx->f20.d);
    // 0x8006112C: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80061130: jal         0x80060400
    // 0x80061134: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x80061134: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x80061138: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8006113C: jal         0x80061290
    // 0x80061140: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x80061140: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_2:
    // 0x80061144: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80061148: add.s       $f4, $f24, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f24.fl + ctx->f26.fl;
    // 0x8006114C: sub.s       $f2, $f24, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = ctx->f24.fl - ctx->f26.fl;
    // 0x80061150: div.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80061154: add.s       $f0, $f24, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f24.fl + ctx->f24.fl;
    // 0x80061158: mul.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8006115C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80061160: div.s       $f22, $f20, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = DIV_S(ctx->f20.fl, ctx->f22.fl);
    // 0x80061164: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80061168: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8006116C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80061170: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80061174: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x80061178: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8006117C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80061180: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80061184: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
L_80061188:
    // 0x80061188: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8006118C: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
L_80061190:
    // 0x80061190: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80061194: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x80061198: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006119C: slti        $v0, $a0, 0x4
    ctx->r2 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x800611A0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800611A4: bne         $v0, $zero, L_80061190
    if (ctx->r2 != 0) {
        // 0x800611A8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80061190;
    }
    // 0x800611A8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800611AC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800611B0: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x800611B4: bne         $v0, $zero, L_80061188
    if (ctx->r2 != 0) {
        // 0x800611B8: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_80061188;
    }
    // 0x800611B8: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800611BC: beql        $s1, $zero, L_80061254
    if (ctx->r17 == 0) {
        // 0x800611C0: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_80061254;
    }
    goto skip_0;
    // 0x800611C0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    skip_0:
    // 0x800611C4: add.s       $f2, $f24, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = ctx->f24.fl + ctx->f26.fl;
    // 0x800611C8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800611CC: ldc1        $f0, -0x1008($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1008);
    // 0x800611D0: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x800611D4: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x800611D8: nop

    // 0x800611DC: nop

    // 0x800611E0: bc1t        L_8006124C
    if (c1cs) {
        // 0x800611E4: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_8006124C;
    }
    // 0x800611E4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800611E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800611EC: ldc1        $f0, -0x1000($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1000);
    // 0x800611F0: div.d       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x800611F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800611F8: ldc1        $f0, -0xFF8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0XFF8);
    // 0x800611FC: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x80061200: nop

    // 0x80061204: nop

    // 0x80061208: bc1tl       L_80061224
    if (c1cs) {
        // 0x8006120C: sub.d       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
            goto L_80061224;
    }
    goto skip_1;
    // 0x8006120C: sub.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
    skip_1:
    // 0x80061210: trunc.w.d   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x80061214: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x80061218: nop

    // 0x8006121C: j           L_80061238
    // 0x80061220: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80061238;
    // 0x80061220: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80061224:
    // 0x80061224: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80061228: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8006122C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80061230: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80061234: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80061238:
    // 0x80061238: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x8006123C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80061240: bne         $v0, $zero, L_80061254
    if (ctx->r2 != 0) {
        // 0x80061244: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_80061254;
    }
    // 0x80061244: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80061248: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006124C:
    // 0x8006124C: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x80061250: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80061254:
    // 0x80061254: jal         0x80060C90
    // 0x80061258: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    guMtxF2L(rdram, ctx);
        goto after_3;
    // 0x80061258: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_3:
    // 0x8006125C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80061260: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80061264: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80061268: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8006126C: ldc1        $f28, 0x80($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X80);
    // 0x80061270: ldc1        $f26, 0x78($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X78);
    // 0x80061274: ldc1        $f24, 0x70($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X70);
    // 0x80061278: ldc1        $f22, 0x68($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X68);
    // 0x8006127C: ldc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X60);
    // 0x80061280: jr          $ra
    // 0x80061284: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80061284: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void sinf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061290: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x80061294: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80061298: sra         $v1, $v0, 22
    ctx->r3 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8006129C: andi        $v1, $v1, 0x1FF
    ctx->r3 = ctx->r3 & 0X1FF;
    // 0x800612A0: slti        $v0, $v1, 0xFF
    ctx->r2 = SIGNED(ctx->r3) < 0XFF ? 1 : 0;
    // 0x800612A4: beq         $v0, $zero, L_80061314
    if (ctx->r2 == 0) {
        // 0x800612A8: slti        $v0, $v1, 0xE6
        ctx->r2 = SIGNED(ctx->r3) < 0XE6 ? 1 : 0;
            goto L_80061314;
    }
    // 0x800612A8: slti        $v0, $v1, 0xE6
    ctx->r2 = SIGNED(ctx->r3) < 0XE6 ? 1 : 0;
    // 0x800612AC: bne         $v0, $zero, L_8006130C
    if (ctx->r2 != 0) {
        // 0x800612B0: cvt.d.s     $f6, $f12
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
            goto L_8006130C;
    }
    // 0x800612B0: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x800612B4: nop

    // 0x800612B8: mul.d       $f4, $f6, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f6.d);
    // 0x800612BC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800612C0: ldc1        $f0, -0xFD0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0XFD0);
    // 0x800612C4: mul.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x800612C8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800612CC: ldc1        $f2, -0xFD8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0XFD8);
    // 0x800612D0: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x800612D4: mul.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x800612D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800612DC: ldc1        $f2, -0xFE0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0XFE0);
    // 0x800612E0: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x800612E4: mul.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x800612E8: nop

    // 0x800612EC: mul.d       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x800612F0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800612F4: ldc1        $f4, -0xFE8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0XFE8);
    // 0x800612F8: add.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f0.d + ctx->f4.d;
    // 0x800612FC: mul.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f0.d);
    // 0x80061300: add.d       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f6.d + ctx->f2.d;
    // 0x80061304: j           L_80061428
    // 0x80061308: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
        goto L_80061428;
    // 0x80061308: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
L_8006130C:
    // 0x8006130C: j           L_80061428
    // 0x80061310: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80061428;
    // 0x80061310: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80061314:
    // 0x80061314: slti        $v0, $v1, 0x136
    ctx->r2 = SIGNED(ctx->r3) < 0X136 ? 1 : 0;
    // 0x80061318: beq         $v0, $zero, L_80061404
    if (ctx->r2 == 0) {
        // 0x8006131C: nop
    
            goto L_80061404;
    }
    // 0x8006131C: nop

    // 0x80061320: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80061324: ldc1        $f0, -0xFC8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0XFC8);
    // 0x80061328: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x8006132C: mul.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x80061330: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80061334: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x80061338: nop

    // 0x8006133C: c.le.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d <= ctx->f4.d;
    // 0x80061340: nop

    // 0x80061344: bc1f        L_8006135C
    if (!c1cs) {
        // 0x80061348: nop
    
            goto L_8006135C;
    }
    // 0x80061348: nop

    // 0x8006134C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80061350: ldc1        $f0, -0xFA8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0XFA8);
    // 0x80061354: j           L_80061368
    // 0x80061358: add.d       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f4.d + ctx->f0.d;
        goto L_80061368;
    // 0x80061358: add.d       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f4.d + ctx->f0.d;
L_8006135C:
    // 0x8006135C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80061360: ldc1        $f0, -0xFA0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0XFA0);
    // 0x80061364: sub.d       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f4.d - ctx->f0.d;
L_80061368:
    // 0x80061368: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8006136C: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x80061370: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80061374: ldc1        $f2, -0xFC0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0XFC0);
    // 0x80061378: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8006137C: nop

    // 0x80061380: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x80061384: mul.d       $f2, $f4, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x80061388: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006138C: ldc1        $f0, -0xFB8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0XFB8);
    // 0x80061390: mul.d       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80061394: sub.d       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f6.d - ctx->f2.d;
    // 0x80061398: sub.d       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f6.d - ctx->f0.d;
    // 0x8006139C: mul.d       $f4, $f6, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f6.d);
    // 0x800613A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800613A4: ldc1        $f0, -0xFD0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0XFD0);
    // 0x800613A8: mul.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x800613AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800613B0: ldc1        $f2, -0xFD8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0XFD8);
    // 0x800613B4: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x800613B8: mul.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x800613BC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800613C0: ldc1        $f2, -0xFE0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0XFE0);
    // 0x800613C4: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x800613C8: mul.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x800613CC: nop

    // 0x800613D0: mul.d       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x800613D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800613D8: ldc1        $f4, -0xFE8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0XFE8);
    // 0x800613DC: add.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f0.d + ctx->f4.d;
    // 0x800613E0: mul.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f0.d);
    // 0x800613E4: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x800613E8: bne         $v0, $zero, L_800613F8
    if (ctx->r2 != 0) {
        // 0x800613EC: add.d       $f0, $f6, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f6.d + ctx->f2.d;
            goto L_800613F8;
    }
    // 0x800613EC: add.d       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f6.d + ctx->f2.d;
    // 0x800613F0: j           L_80061428
    // 0x800613F4: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
        goto L_80061428;
    // 0x800613F4: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
L_800613F8:
    // 0x800613F8: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x800613FC: j           L_80061428
    // 0x80061400: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_80061428;
    // 0x80061400: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_80061404:
    // 0x80061404: c.eq.s      $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f12.fl == ctx->f12.fl;
    // 0x80061408: nop

    // 0x8006140C: bc1f        L_80061420
    if (!c1cs) {
        // 0x80061410: nop
    
            goto L_80061420;
    }
    // 0x80061410: nop

    // 0x80061414: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80061418: j           L_80061428
    // 0x8006141C: lwc1        $f0, -0xFB0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XFB0);
        goto L_80061428;
    // 0x8006141C: lwc1        $f0, -0xFB0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XFB0);
L_80061420:
    // 0x80061420: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80061424: lwc1        $f0, -0xC80($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XC80);
L_80061428:
    // 0x80061428: jr          $ra
    // 0x8006142C: nop

    return;
    // 0x8006142C: nop

;}
RECOMP_FUNC void func_80061430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061430: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80061434: srl         $a0, $a0, 4
    ctx->r4 = S32(U32(ctx->r4) >> 4);
    // 0x80061438: andi        $v0, $a0, 0x400
    ctx->r2 = ctx->r4 & 0X400;
    // 0x8006143C: beq         $v0, $zero, L_80061450
    if (ctx->r2 == 0) {
        // 0x80061440: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_80061450;
    }
    // 0x80061440: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80061444: nor         $v0, $zero, $a0
    ctx->r2 = ~(0 | ctx->r4);
    // 0x80061448: j           L_80061454
    // 0x8006144C: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
        goto L_80061454;
    // 0x8006144C: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
L_80061450:
    // 0x80061450: andi        $v0, $a0, 0x3FF
    ctx->r2 = ctx->r4 & 0X3FF;
L_80061454:
    // 0x80061454: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80061458: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8006145C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80061460: lhu         $v1, 0x6360($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X6360);
    // 0x80061464: andi        $v0, $a1, 0x800
    ctx->r2 = ctx->r5 & 0X800;
    // 0x80061468: bne         $v0, $zero, L_80061478
    if (ctx->r2 != 0) {
        // 0x8006146C: negu        $v0, $v1
        ctx->r2 = SUB32(0, ctx->r3);
            goto L_80061478;
    }
    // 0x8006146C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x80061470: j           L_8006147C
    // 0x80061474: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
        goto L_8006147C;
    // 0x80061474: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
L_80061478:
    // 0x80061478: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
L_8006147C:
    // 0x8006147C: jr          $ra
    // 0x80061480: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x80061480: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
;}
RECOMP_FUNC void func_80061540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800616C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80061710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80061E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061E40: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80061E44: beq         $v0, $zero, L_80061E6C
    if (ctx->r2 == 0) {
        // 0x80061E48: nop
    
            goto L_80061E6C;
    }
    // 0x80061E48: nop

L_80061E4C:
    // 0x80061E4C: bnel        $v0, $a1, L_80061E60
    if (ctx->r2 != ctx->r5) {
        // 0x80061E50: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_80061E60;
    }
    goto skip_0;
    // 0x80061E50: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    skip_0:
    // 0x80061E54: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80061E58: j           L_80061E6C
    // 0x80061E5C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_80061E6C;
    // 0x80061E5C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_80061E60:
    // 0x80061E60: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80061E64: bne         $v0, $zero, L_80061E4C
    if (ctx->r2 != 0) {
        // 0x80061E68: nop
    
            goto L_80061E4C;
    }
    // 0x80061E68: nop

L_80061E6C:
    // 0x80061E6C: jr          $ra
    // 0x80061E70: nop

    return;
    // 0x80061E70: nop

;}
RECOMP_FUNC void func_80061E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061E80: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80061E84: lw          $v0, 0x6B80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6B80);
    // 0x80061E88: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80061E8C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80061E90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80061E94: sw          $a0, -0x4328($at)
    MEM_W(-0X4328, ctx->r1) = ctx->r4;
    // 0x80061E98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80061E9C: sw          $a1, -0x4324($at)
    MEM_W(-0X4324, ctx->r1) = ctx->r5;
    // 0x80061EA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80061EA4: sw          $zero, -0x33D4($at)
    MEM_W(-0X33D4, ctx->r1) = 0;
    // 0x80061EA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80061EAC: sw          $zero, 0x2A88($at)
    MEM_W(0X2A88, ctx->r1) = 0;
    // 0x80061EB0: sw          $a0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r4;
    // 0x80061EB4: sw          $a1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r5;
    // 0x80061EB8: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x80061EBC: sw          $a1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r5;
    // 0x80061EC0: sw          $v0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r2;
    // 0x80061EC4: sw          $v0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r2;
    // 0x80061EC8: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x80061ECC: jr          $ra
    // 0x80061ED0: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    return;
    // 0x80061ED0: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80061ED4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061ED4: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80061ED8: lw          $v1, 0x6B80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6B80);
    // 0x80061EDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80061EE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80061EE4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80061EE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80061EEC: beq         $v0, $v1, L_80062000
    if (ctx->r2 == ctx->r3) {
        // 0x80061EF0: nop
    
            goto L_80062000;
    }
    // 0x80061EF0: nop

L_80061EF4:
    // 0x80061EF4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80061EF8: lw          $v0, 0x6B80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6B80);
    // 0x80061EFC: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x80061F00: bne         $s0, $v0, L_80061F1C
    if (ctx->r16 != ctx->r2) {
        // 0x80061F04: nop
    
            goto L_80061F1C;
    }
    // 0x80061F04: nop

    // 0x80061F08: jal         0x80068BE0
    // 0x80061F0C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80068BE0(rdram, ctx);
        goto after_0;
    // 0x80061F0C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // 0x80061F10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80061F14: j           L_80062000
    // 0x80061F18: sw          $zero, 0x4940($at)
    MEM_W(0X4940, ctx->r1) = 0;
        goto L_80062000;
    // 0x80061F18: sw          $zero, 0x4940($at)
    MEM_W(0X4940, ctx->r1) = 0;
L_80061F1C:
    // 0x80061F1C: jal         0x80068AC0
    // 0x80061F20: nop

    osGetCount_recomp(rdram, ctx);
        goto after_1;
    // 0x80061F20: nop

    after_1:
    // 0x80061F24: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80061F28: lw          $v1, 0x4940($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4940);
    // 0x80061F2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80061F30: sw          $v0, 0x4940($at)
    MEM_W(0X4940, ctx->r1) = ctx->r2;
    // 0x80061F34: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80061F38: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x80061F3C: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80061F40: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80061F44: sltu        $v0, $a2, $v1
    ctx->r2 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x80061F48: bne         $v0, $zero, L_80061F68
    if (ctx->r2 != 0) {
        // 0x80061F4C: nop
    
            goto L_80061F68;
    }
    // 0x80061F4C: nop

    // 0x80061F50: bne         $v1, $a2, L_80061F94
    if (ctx->r3 != ctx->r6) {
        // 0x80061F54: nop
    
            goto L_80061F94;
    }
    // 0x80061F54: nop

    // 0x80061F58: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80061F5C: sltu        $v0, $a3, $v0
    ctx->r2 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x80061F60: beq         $v0, $zero, L_80061F94
    if (ctx->r2 == 0) {
        // 0x80061F64: nop
    
            goto L_80061F94;
    }
    // 0x80061F64: nop

L_80061F68:
    // 0x80061F68: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x80061F6C: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x80061F70: sltu        $v0, $a1, $a3
    ctx->r2 = ctx->r5 < ctx->r7 ? 1 : 0;
    // 0x80061F74: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x80061F78: subu        $a0, $a0, $a2
    ctx->r4 = SUB32(ctx->r4, ctx->r6);
    // 0x80061F7C: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x80061F80: sw          $a0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r4;
    // 0x80061F84: jal         0x80062010
    // 0x80061F88: sw          $a1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r5;
    func_80062010(rdram, ctx);
        goto after_2;
    // 0x80061F88: sw          $a1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r5;
    after_2:
    // 0x80061F8C: j           L_80062000
    // 0x80061F90: nop

        goto L_80062000;
    // 0x80061F90: nop

L_80061F94:
    // 0x80061F94: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80061F98: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80061F9C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80061FA0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80061FA4: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80061FA8: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80061FAC: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x80061FB0: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80061FB4: beq         $a0, $zero, L_80061FC8
    if (ctx->r4 == 0) {
        // 0x80061FB8: sw          $zero, 0x4($s0)
        MEM_W(0X4, ctx->r16) = 0;
            goto L_80061FC8;
    }
    // 0x80061FB8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80061FBC: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80061FC0: jal         0x80061AD0
    // 0x80061FC4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80061FC4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_3:
L_80061FC8:
    // 0x80061FC8: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80061FCC: bne         $v0, $zero, L_80061FE0
    if (ctx->r2 != 0) {
        // 0x80061FD0: nop
    
            goto L_80061FE0;
    }
    // 0x80061FD0: nop

    // 0x80061FD4: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x80061FD8: beq         $v0, $zero, L_80061EF4
    if (ctx->r2 == 0) {
        // 0x80061FDC: nop
    
            goto L_80061EF4;
    }
    // 0x80061FDC: nop

L_80061FE0:
    // 0x80061FE0: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80061FE4: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x80061FE8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80061FEC: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x80061FF0: jal         0x80062070
    // 0x80061FF4: sw          $v1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r3;
    func_80062070(rdram, ctx);
        goto after_4;
    // 0x80061FF4: sw          $v1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r3;
    after_4:
    // 0x80061FF8: j           L_80061EF4
    // 0x80061FFC: nop

        goto L_80061EF4;
    // 0x80061FFC: nop

L_80062000:
    // 0x80062000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062004: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80062008: jr          $ra
    // 0x8006200C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006200C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80062010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062010: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80062014: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80062018: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006201C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80062020: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80062024: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80062028: jal         0x80068AE0
    // 0x8006202C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x8006202C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    after_0:
    // 0x80062030: jal         0x80068AC0
    // 0x80062034: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    osGetCount_recomp(rdram, ctx);
        goto after_1;
    // 0x80062034: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80062038: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8006203C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80062040: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80062044: sw          $v0, 0x4940($at)
    MEM_W(0X4940, ctx->r1) = ctx->r2;
    // 0x80062048: jal         0x80068BE0
    // 0x8006204C: addu        $a0, $s1, $a1
    ctx->r4 = ADD32(ctx->r17, ctx->r5);
    func_80068BE0(rdram, ctx);
        goto after_2;
    // 0x8006204C: addu        $a0, $s1, $a1
    ctx->r4 = ADD32(ctx->r17, ctx->r5);
    after_2:
    // 0x80062050: jal         0x80068B00
    // 0x80062054: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    __osRestoreInt_recomp(rdram, ctx);
        goto after_3;
    // 0x80062054: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_3:
    // 0x80062058: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006205C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80062060: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80062064: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80062068: jr          $ra
    // 0x8006206C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006206C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80062070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062070: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80062074: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80062078: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8006207C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80062080: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80062084: jal         0x80068AE0
    // 0x80062088: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x80062088: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8006208C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80062090: lw          $v1, 0x6B80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6B80);
    // 0x80062094: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x80062098: lw          $s0, 0x10($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X10);
    // 0x8006209C: lw          $s1, 0x14($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X14);
    // 0x800620A0: beq         $a2, $v1, L_80062100
    if (ctx->r6 == ctx->r3) {
        // 0x800620A4: addu        $a3, $v0, $zero
        ctx->r7 = ADD32(ctx->r2, 0);
            goto L_80062100;
    }
    // 0x800620A4: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x800620A8: j           L_800620D8
    // 0x800620AC: nop

        goto L_800620D8;
    // 0x800620AC: nop

L_800620B0:
    // 0x800620B0: lw          $v0, 0x10($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X10);
    // 0x800620B4: lw          $v1, 0x14($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X14);
    // 0x800620B8: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
    // 0x800620BC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800620C0: lw          $a0, 0x6B80($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6B80);
    // 0x800620C4: sltu        $a1, $s1, $v1
    ctx->r5 = ctx->r17 < ctx->r3 ? 1 : 0;
    // 0x800620C8: subu        $s1, $s1, $v1
    ctx->r17 = SUB32(ctx->r17, ctx->r3);
    // 0x800620CC: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x800620D0: beq         $a2, $a0, L_80062100
    if (ctx->r6 == ctx->r4) {
        // 0x800620D4: subu        $s0, $s0, $a1
        ctx->r16 = SUB32(ctx->r16, ctx->r5);
            goto L_80062100;
    }
    // 0x800620D4: subu        $s0, $s0, $a1
    ctx->r16 = SUB32(ctx->r16, ctx->r5);
L_800620D8:
    // 0x800620D8: lw          $v1, 0x10($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X10);
    // 0x800620DC: sltu        $v0, $v1, $s0
    ctx->r2 = ctx->r3 < ctx->r16 ? 1 : 0;
    // 0x800620E0: bne         $v0, $zero, L_800620B0
    if (ctx->r2 != 0) {
        // 0x800620E4: nop
    
            goto L_800620B0;
    }
    // 0x800620E4: nop

    // 0x800620E8: bne         $s0, $v1, L_80062100
    if (ctx->r16 != ctx->r3) {
        // 0x800620EC: nop
    
            goto L_80062100;
    }
    // 0x800620EC: nop

    // 0x800620F0: lw          $v0, 0x14($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X14);
    // 0x800620F4: sltu        $v0, $v0, $s1
    ctx->r2 = ctx->r2 < ctx->r17 ? 1 : 0;
    // 0x800620F8: bne         $v0, $zero, L_800620B0
    if (ctx->r2 != 0) {
        // 0x800620FC: nop
    
            goto L_800620B0;
    }
    // 0x800620FC: nop

L_80062100:
    // 0x80062100: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80062104: lw          $v0, 0x6B80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6B80);
    // 0x80062108: sw          $s0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r16;
    // 0x8006210C: sw          $s1, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r17;
    // 0x80062110: beql        $a2, $v0, L_8006213C
    if (ctx->r6 == ctx->r2) {
        // 0x80062114: sw          $a2, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r6;
            goto L_8006213C;
    }
    goto skip_0;
    // 0x80062114: sw          $a2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r6;
    skip_0:
    // 0x80062118: lw          $v0, 0x10($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X10);
    // 0x8006211C: lw          $v1, 0x14($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X14);
    // 0x80062120: sltu        $a0, $v1, $s1
    ctx->r4 = ctx->r3 < ctx->r17 ? 1 : 0;
    // 0x80062124: subu        $v1, $v1, $s1
    ctx->r3 = SUB32(ctx->r3, ctx->r17);
    // 0x80062128: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x8006212C: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80062130: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // 0x80062134: sw          $v1, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r3;
    // 0x80062138: sw          $a2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r6;
L_8006213C:
    // 0x8006213C: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x80062140: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // 0x80062144: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x80062148: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    // 0x8006214C: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80062150: jal         0x80068B00
    // 0x80062154: sw          $s2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r18;
    __osRestoreInt_recomp(rdram, ctx);
        goto after_1;
    // 0x80062154: sw          $s2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r18;
    after_1:
    // 0x80062158: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8006215C: addu        $v1, $s1, $zero
    ctx->r3 = ADD32(ctx->r17, 0);
    // 0x80062160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80062164: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80062168: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8006216C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80062170: jr          $ra
    // 0x80062174: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80062174: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800621E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800621E0: jr          $ra
    // 0x800621E4: nop

    return;
    // 0x800621E4: nop

;}
RECOMP_FUNC void func_800621F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800621F0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800621F4: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x800621F8: addiu       $a2, $a0, 0xE
    ctx->r6 = ADD32(ctx->r4, 0XE);
    // 0x800621FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80062200: sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
    // 0x80062204: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // 0x80062208: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8006220C: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // 0x80062210: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80062214: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
L_80062218:
    // 0x80062218: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x8006221C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80062220: bgez        $a1, L_80062218
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80062224: addiu       $a2, $a2, -0x2
        ctx->r6 = ADD32(ctx->r6, -0X2);
            goto L_80062218;
    }
    // 0x80062224: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x80062228: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x8006222C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80062230: ldc1        $f2, -0xF10($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0XF10);
    // 0x80062234: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80062238: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8006223C: nop

    // 0x80062240: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x80062244: div.d       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x80062248: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8006224C: addiu       $a2, $a0, 0x12
    ctx->r6 = ADD32(ctx->r4, 0X12);
    // 0x80062250: sh          $a3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r7;
    // 0x80062254: mov.d       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.d = ctx->f2.d;
    // 0x80062258: mov.d       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = ctx->f4.d;
L_8006225C:
    // 0x8006225C: nop

    // 0x80062260: mul.d       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80062264: nop

    // 0x80062268: mul.d       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f0.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x8006226C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80062270: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80062274: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80062278: nop

    // 0x8006227C: sh          $v0, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r2;
    // 0x80062280: slti        $v0, $a1, 0x10
    ctx->r2 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x80062284: bne         $v0, $zero, L_8006225C
    if (ctx->r2 != 0) {
        // 0x80062288: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_8006225C;
    }
    // 0x80062288: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x8006228C: jr          $ra
    // 0x80062290: nop

    return;
    // 0x80062290: nop

;}
RECOMP_FUNC void func_80062294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062294: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80062298: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006229C: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800622A0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800622A4: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x800622A8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800622AC: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x800622B0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800622B4: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x800622B8: addiu       $a2, $a2, 0x4B60
    ctx->r6 = ADD32(ctx->r6, 0X4B60);
    // 0x800622BC: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x800622C0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800622C4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800622C8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800622CC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800622D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800622D4: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x800622D8: jal         0x80064370
    // 0x800622DC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_80064370(rdram, ctx);
        goto after_0;
    // 0x800622DC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_0:
    // 0x800622E0: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x800622E4: addiu       $v0, $v0, 0x47B0
    ctx->r2 = ADD32(ctx->r2, 0X47B0);
    // 0x800622E8: sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
    // 0x800622EC: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x800622F0: addiu       $v0, $v0, 0x4B74
    ctx->r2 = ADD32(ctx->r2, 0X4B74);
    // 0x800622F4: sw          $v0, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->r2;
    // 0x800622F8: lbu         $v0, 0x1C($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1C);
    // 0x800622FC: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x80062300: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x80062304: beq         $v0, $zero, L_80062364
    if (ctx->r2 == 0) {
        // 0x80062308: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80062364;
    }
    // 0x80062308: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8006230C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80062310: addu        $at, $at, $v0
    gpr jr_addend_80062318 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80062314: lw          $v0, -0xF08($at)
    ctx->r2 = ADD32(ctx->r1, -0XF08);
    // 0x80062318: jr          $v0
    // 0x8006231C: nop

    switch (jr_addend_80062318 >> 2) {
        case 0: goto L_80062320; break;
        case 1: goto L_8006232C; break;
        case 2: goto L_80062344; break;
        case 3: goto L_80062350; break;
        case 4: goto L_80062338; break;
        case 5: goto L_8006235C; break;
        default: switch_error(__func__, 0x80062318, 0x800AF0F8);
    }
    // 0x8006231C: nop

L_80062320:
    // 0x80062320: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x80062324: j           L_8006236C
    // 0x80062328: addiu       $s2, $s2, 0x6B90
    ctx->r18 = ADD32(ctx->r18, 0X6B90);
        goto L_8006236C;
    // 0x80062328: addiu       $s2, $s2, 0x6B90
    ctx->r18 = ADD32(ctx->r18, 0X6B90);
L_8006232C:
    // 0x8006232C: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x80062330: j           L_8006236C
    // 0x80062334: addiu       $s2, $s2, 0x6BF8
    ctx->r18 = ADD32(ctx->r18, 0X6BF8);
        goto L_8006236C;
    // 0x80062334: addiu       $s2, $s2, 0x6BF8
    ctx->r18 = ADD32(ctx->r18, 0X6BF8);
L_80062338:
    // 0x80062338: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x8006233C: j           L_8006236C
    // 0x80062340: addiu       $s2, $s2, 0x6C80
    ctx->r18 = ADD32(ctx->r18, 0X6C80);
        goto L_8006236C;
    // 0x80062340: addiu       $s2, $s2, 0x6C80
    ctx->r18 = ADD32(ctx->r18, 0X6C80);
L_80062344:
    // 0x80062344: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x80062348: j           L_8006236C
    // 0x8006234C: addiu       $s2, $s2, 0x6CA8
    ctx->r18 = ADD32(ctx->r18, 0X6CA8);
        goto L_8006236C;
    // 0x8006234C: addiu       $s2, $s2, 0x6CA8
    ctx->r18 = ADD32(ctx->r18, 0X6CA8);
L_80062350:
    // 0x80062350: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x80062354: j           L_8006236C
    // 0x80062358: addiu       $s2, $s2, 0x6CD0
    ctx->r18 = ADD32(ctx->r18, 0X6CD0);
        goto L_8006236C;
    // 0x80062358: addiu       $s2, $s2, 0x6CD0
    ctx->r18 = ADD32(ctx->r18, 0X6CD0);
L_8006235C:
    // 0x8006235C: j           L_8006236C
    // 0x80062360: lw          $s2, 0x20($s6)
    ctx->r18 = MEM_W(ctx->r22, 0X20);
        goto L_8006236C;
    // 0x80062360: lw          $s2, 0x20($s6)
    ctx->r18 = MEM_W(ctx->r22, 0X20);
L_80062364:
    // 0x80062364: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x80062368: addiu       $s2, $s2, 0x6CF8
    ctx->r18 = ADD32(ctx->r18, 0X6CF8);
L_8006236C:
    // 0x8006236C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80062370: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80062374: sb          $v0, 0x24($s3)
    MEM_B(0X24, ctx->r19) = ctx->r2;
    // 0x80062378: lbu         $a3, 0x24($s3)
    ctx->r7 = MEM_BU(ctx->r19, 0X24);
    // 0x8006237C: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x80062380: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80062384: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x80062388: sw          $v0, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->r2;
    // 0x8006238C: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x80062390: jal         0x800655B0
    // 0x80062394: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800655B0(rdram, ctx);
        goto after_1;
    // 0x80062394: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x80062398: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8006239C: sw          $v0, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->r2;
    // 0x800623A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800623A4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800623A8: lw          $a3, 0x1C($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X1C);
    // 0x800623AC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800623B0: jal         0x800655B0
    // 0x800623B4: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    func_800655B0(rdram, ctx);
        goto after_2;
    // 0x800623B4: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    after_2:
    // 0x800623B8: lw          $v1, 0x1C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1C);
    // 0x800623BC: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x800623C0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800623C4: sw          $v0, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r2;
    // 0x800623C8: beq         $v1, $zero, L_800623FC
    if (ctx->r3 == 0) {
        // 0x800623CC: sw          $v0, 0x18($s3)
        MEM_W(0X18, ctx->r19) = ctx->r2;
            goto L_800623FC;
    }
    // 0x800623CC: sw          $v0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r2;
L_800623D0:
    // 0x800623D0: lw          $v1, 0x14($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X14);
    // 0x800623D4: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800623D8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800623DC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800623E0: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x800623E4: lw          $v1, 0x1C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1C);
    // 0x800623E8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800623EC: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800623F0: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800623F4: bne         $v0, $zero, L_800623D0
    if (ctx->r2 != 0) {
        // 0x800623F8: nop
    
            goto L_800623D0;
    }
    // 0x800623F8: nop

L_800623FC:
    // 0x800623FC: lbu         $v0, 0x24($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X24);
    // 0x80062400: beq         $v0, $zero, L_800626FC
    if (ctx->r2 == 0) {
        // 0x80062404: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_800626FC;
    }
    // 0x80062404: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x80062408: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x8006240C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80062410: ldc1        $f20, -0xEF0($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0XEF0);
    // 0x80062414: andi        $v0, $s4, 0xFFFF
    ctx->r2 = ctx->r20 & 0XFFFF;
L_80062418:
    // 0x80062418: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8006241C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80062420: lw          $a1, 0x20($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X20);
    // 0x80062424: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80062428: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8006242C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80062430: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80062434: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80062438: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8006243C: addu        $s0, $a1, $v1
    ctx->r16 = ADD32(ctx->r5, ctx->r3);
    // 0x80062440: addiu       $a1, $a0, 0x1
    ctx->r5 = ADD32(ctx->r4, 0X1);
    // 0x80062444: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80062448: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x8006244C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80062450: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80062454: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80062458: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x8006245C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80062460: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80062464: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80062468: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x8006246C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80062470: addiu       $v0, $a1, 0x2
    ctx->r2 = ADD32(ctx->r5, 0X2);
    // 0x80062474: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80062478: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006247C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80062480: sh          $v1, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r3;
    // 0x80062484: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80062488: addiu       $v0, $a1, 0x3
    ctx->r2 = ADD32(ctx->r5, 0X3);
    // 0x8006248C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80062490: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80062494: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80062498: sh          $v1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r3;
    // 0x8006249C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800624A0: addiu       $s1, $a1, 0x4
    ctx->r17 = ADD32(ctx->r5, 0X4);
    // 0x800624A4: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // 0x800624A8: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x800624AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800624B0: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800624B4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800624B8: beq         $v0, $zero, L_800625C4
    if (ctx->r2 == 0) {
        // 0x800624BC: addu        $v0, $s1, $zero
        ctx->r2 = ADD32(ctx->r17, 0);
            goto L_800625C4;
    }
    // 0x800624BC: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x800624C0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800624C4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800624C8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800624CC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800624D0: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800624D4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800624D8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800624DC: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800624E0: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x800624E4: add.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
    // 0x800624E8: lwc1        $f2, 0x18($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X18);
    // 0x800624EC: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x800624F0: div.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x800624F4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800624F8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800624FC: addiu       $v0, $a1, 0x5
    ctx->r2 = ADD32(ctx->r5, 0X5);
    // 0x80062500: addiu       $s1, $a1, 0x6
    ctx->r17 = ADD32(ctx->r5, 0X6);
    // 0x80062504: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80062508: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006250C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80062510: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x80062514: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80062518: ldc1        $f2, -0xEE8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0XEE8);
    // 0x8006251C: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80062520: nop

    // 0x80062524: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x80062528: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8006252C: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80062530: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80062534: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80062538: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8006253C: bgez        $a0, L_80062550
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80062540: div.d       $f2, $f0, $f2
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = DIV_D(ctx->f0.d, ctx->f2.d);
            goto L_80062550;
    }
    // 0x80062540: div.d       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x80062544: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80062548: ldc1        $f0, -0xEE0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0XEE0);
    // 0x8006254C: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_80062550:
    // 0x80062550: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80062554: mul.d       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x80062558: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006255C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80062560: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80062564: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x80062568: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8006256C: addiu       $v0, $zero, 0x34
    ctx->r2 = ADD32(0, 0X34);
    // 0x80062570: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80062574: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x80062578: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8006257C: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80062580: jal         0x800655B0
    // 0x80062584: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800655B0(rdram, ctx);
        goto after_3;
    // 0x80062584: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x80062588: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8006258C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80062590: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x80062594: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80062598: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x8006259C: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x800625A0: jal         0x800655B0
    // 0x800625A4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800655B0(rdram, ctx);
        goto after_4;
    // 0x800625A4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_4:
    // 0x800625A8: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x800625AC: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x800625B0: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800625B4: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x800625B8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800625BC: j           L_800625CC
    // 0x800625C0: sw          $s7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r23;
        goto L_800625CC;
    // 0x800625C0: sw          $s7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r23;
L_800625C4:
    // 0x800625C4: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x800625C8: addiu       $s1, $a1, 0x6
    ctx->r17 = ADD32(ctx->r5, 0X6);
L_800625CC:
    // 0x800625CC: andi        $v0, $s1, 0xFFFF
    ctx->r2 = ctx->r17 & 0XFFFF;
    // 0x800625D0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800625D4: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800625D8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800625DC: beq         $v0, $zero, L_800626DC
    if (ctx->r2 == 0) {
        // 0x800625E0: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800626DC;
    }
    // 0x800625E0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800625E4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800625E8: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x800625EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800625F0: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800625F4: jal         0x800655B0
    // 0x800625F8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800655B0(rdram, ctx);
        goto after_5;
    // 0x800625F8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_5:
    // 0x800625FC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80062600: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80062604: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x80062608: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8006260C: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x80062610: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80062614: jal         0x800655B0
    // 0x80062618: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800655B0(rdram, ctx);
        goto after_6;
    // 0x80062618: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_6:
    // 0x8006261C: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x80062620: sw          $v0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r2;
    // 0x80062624: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x80062628: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x8006262C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80062630: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80062634: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80062638: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8006263C: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80062640: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x80062644: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80062648: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006264C: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x80062650: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // 0x80062654: addiu       $a2, $a1, 0xE
    ctx->r6 = ADD32(ctx->r5, 0XE);
    // 0x80062658: sw          $s7, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r23;
    // 0x8006265C: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80062660: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // 0x80062664: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80062668: sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
L_8006266C:
    // 0x8006266C: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x80062670: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80062674: bgez        $a0, L_8006266C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80062678: addiu       $a2, $a2, -0x2
        ctx->r6 = ADD32(ctx->r6, -0X2);
            goto L_8006266C;
    }
    // 0x80062678: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x8006267C: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x80062680: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80062684: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80062688: nop

    // 0x8006268C: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x80062690: div.d       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f0.d, ctx->f20.d);
    // 0x80062694: sh          $a3, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r7;
    // 0x80062698: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8006269C: addiu       $a1, $a1, 0x12
    ctx->r5 = ADD32(ctx->r5, 0X12);
    // 0x800626A0: mov.d       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = ctx->f4.d;
L_800626A4:
    // 0x800626A4: nop

    // 0x800626A8: mul.d       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800626AC: nop

    // 0x800626B0: mul.d       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f0.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x800626B4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800626B8: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x800626BC: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x800626C0: nop

    // 0x800626C4: sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // 0x800626C8: slti        $v0, $a0, 0x10
    ctx->r2 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // 0x800626CC: bne         $v0, $zero, L_800626A4
    if (ctx->r2 != 0) {
        // 0x800626D0: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_800626A4;
    }
    // 0x800626D0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800626D4: j           L_800626E4
    // 0x800626D8: nop

        goto L_800626E4;
    // 0x800626D8: nop

L_800626DC:
    // 0x800626DC: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x800626E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800626E4:
    // 0x800626E4: lbu         $v1, 0x24($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X24);
    // 0x800626E8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800626EC: andi        $v0, $s4, 0xFFFF
    ctx->r2 = ctx->r20 & 0XFFFF;
    // 0x800626F0: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800626F4: bne         $v0, $zero, L_80062418
    if (ctx->r2 != 0) {
        // 0x800626F8: andi        $v0, $s4, 0xFFFF
        ctx->r2 = ctx->r20 & 0XFFFF;
            goto L_80062418;
    }
    // 0x800626F8: andi        $v0, $s4, 0xFFFF
    ctx->r2 = ctx->r20 & 0XFFFF;
L_800626FC:
    // 0x800626FC: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x80062700: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80062704: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80062708: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8006270C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80062710: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80062714: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80062718: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006271C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80062720: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x80062724: jr          $ra
    // 0x80062728: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80062728: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8006272C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006272C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80062730: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80062734: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80062738: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006273C: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80062740: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x80062744: addiu       $a1, $a1, 0x3640
    ctx->r5 = ADD32(ctx->r5, 0X3640);
    // 0x80062748: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8006274C: addiu       $a2, $a2, 0x3B8C
    ctx->r6 = ADD32(ctx->r6, 0X3B8C);
    // 0x80062750: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80062754: jal         0x80064370
    // 0x80062758: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_80064370(rdram, ctx);
        goto after_0;
    // 0x80062758: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x8006275C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80062760: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80062764: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80062768: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8006276C: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x80062770: jal         0x800655B0
    // 0x80062774: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800655B0(rdram, ctx);
        goto after_1;
    // 0x80062774: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x80062778: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x8006277C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80062780: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x80062784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80062788: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
    // 0x8006278C: sh          $v0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r2;
    // 0x80062790: sh          $v0, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r2;
    // 0x80062794: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // 0x80062798: sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    // 0x8006279C: sh          $v0, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r2;
    // 0x800627A0: sh          $zero, 0x20($s0)
    MEM_H(0X20, ctx->r16) = 0;
    // 0x800627A4: sh          $zero, 0x22($s0)
    MEM_H(0X22, ctx->r16) = 0;
    // 0x800627A8: sh          $v0, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r2;
    // 0x800627AC: sh          $zero, 0x24($s0)
    MEM_H(0X24, ctx->r16) = 0;
    // 0x800627B0: sh          $v0, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r2;
    // 0x800627B4: sh          $zero, 0x24($s0)
    MEM_H(0X24, ctx->r16) = 0;
    // 0x800627B8: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x800627BC: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x800627C0: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x800627C4: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x800627C8: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x800627CC: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x800627D0: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800627D4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800627D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800627DC: jr          $ra
    // 0x800627E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800627E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800627E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800627E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800627E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800627EC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800627F0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800627F4: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x800627F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800627FC: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80062800: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x80062804: addiu       $a1, $a1, 0x2A20
    ctx->r5 = ADD32(ctx->r5, 0X2A20);
    // 0x80062808: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8006280C: addiu       $a2, $a2, 0x3200
    ctx->r6 = ADD32(ctx->r6, 0X3200);
    // 0x80062810: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80062814: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80062818: jal         0x80064370
    // 0x8006281C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    func_80064370(rdram, ctx);
        goto after_0;
    // 0x8006281C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_0:
    // 0x80062820: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80062824: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80062828: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8006282C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80062830: addiu       $s1, $zero, 0x20
    ctx->r17 = ADD32(0, 0X20);
    // 0x80062834: jal         0x800655B0
    // 0x80062838: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_800655B0(rdram, ctx);
        goto after_1;
    // 0x80062838: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_1:
    // 0x8006283C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80062840: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80062844: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x80062848: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8006284C: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80062850: jal         0x800655B0
    // 0x80062854: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_800655B0(rdram, ctx);
        goto after_2;
    // 0x80062854: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_2:
    // 0x80062858: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x8006285C: jalr        $s3
    // 0x80062860: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    LOOKUP_FUNC(ctx->r19)(rdram, ctx);
        goto after_3;
    // 0x80062860: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    after_3:
    // 0x80062864: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x80062868: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006286C: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80062870: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x80062874: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x80062878: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8006287C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80062880: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80062884: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80062888: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006288C: jr          $ra
    // 0x80062890: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80062890: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
