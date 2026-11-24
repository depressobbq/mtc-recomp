#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8001D520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D520: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001D524: addiu       $v1, $v1, 0x6DB0
    ctx->r3 = ADD32(ctx->r3, 0X6DB0);
    // 0x8001D528: beq         $a0, $zero, L_8001D538
    if (ctx->r4 == 0) {
        // 0x8001D52C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8001D538;
    }
    // 0x8001D52C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8001D530: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001D534: addiu       $v1, $v1, 0x3830
    ctx->r3 = ADD32(ctx->r3, 0X3830);
L_8001D538:
    // 0x8001D538: lbu         $v0, 0x28($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X28);
    // 0x8001D53C: bnel        $v0, $zero, L_8001D54C
    if (ctx->r2 != 0) {
        // 0x8001D540: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8001D54C;
    }
    goto skip_0;
    // 0x8001D540: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x8001D544: j           L_8001D55C
    // 0x8001D548: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8001D55C;
    // 0x8001D548: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8001D54C:
    // 0x8001D54C: slti        $v0, $a0, 0x1C
    ctx->r2 = SIGNED(ctx->r4) < 0X1C ? 1 : 0;
    // 0x8001D550: bne         $v0, $zero, L_8001D538
    if (ctx->r2 != 0) {
        // 0x8001D554: addiu       $v1, $v1, 0x70
        ctx->r3 = ADD32(ctx->r3, 0X70);
            goto L_8001D538;
    }
    // 0x8001D554: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
    // 0x8001D558: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8001D55C:
    // 0x8001D55C: jr          $ra
    // 0x8001D560: nop

    return;
    // 0x8001D560: nop

;}
RECOMP_FUNC void func_8001D564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D564: sb          $zero, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = 0;
    // 0x8001D568: sb          $zero, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = 0;
    // 0x8001D56C: sb          $zero, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = 0;
    // 0x8001D570: jr          $ra
    // 0x8001D574: sb          $zero, 0x28($a0)
    MEM_B(0X28, ctx->r4) = 0;
    return;
    // 0x8001D574: sb          $zero, 0x28($a0)
    MEM_B(0X28, ctx->r4) = 0;
;}
RECOMP_FUNC void func_8001D578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D578: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D57C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001D580: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001D584: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001D588: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001D58C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D590: lbu         $a0, 0x2A($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X2A);
    // 0x8001D594: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8001D598: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001D59C: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x8001D5A0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001D5A4: addiu       $v0, $v0, 0x1018
    ctx->r2 = ADD32(ctx->r2, 0X1018);
    // 0x8001D5A8: sb          $v1, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r3;
    // 0x8001D5AC: sb          $v1, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r3;
    // 0x8001D5B0: addiu       $v1, $zero, 0x500
    ctx->r3 = ADD32(0, 0X500);
    // 0x8001D5B4: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x8001D5B8: addiu       $v0, $zero, 0x3C0
    ctx->r2 = ADD32(0, 0X3C0);
    // 0x8001D5BC: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x8001D5C0: sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // 0x8001D5C4: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8001D5C8: addiu       $v0, $v0, 0x3040
    ctx->r2 = ADD32(ctx->r2, 0X3040);
    // 0x8001D5CC: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x8001D5D0: ori         $v0, $zero, 0xFFF4
    ctx->r2 = 0 | 0XFFF4;
    // 0x8001D5D4: sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
    // 0x8001D5D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001D5DC: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
    // 0x8001D5E0: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x8001D5E4: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x8001D5E8: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x8001D5EC: sh          $v1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r3;
    // 0x8001D5F0: sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // 0x8001D5F4: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x8001D5F8: sh          $v1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r3;
    // 0x8001D5FC: sb          $zero, 0x16($s0)
    MEM_B(0X16, ctx->r16) = 0;
    // 0x8001D600: sb          $v0, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r2;
    // 0x8001D604: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x8001D608: sh          $zero, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = 0;
    // 0x8001D60C: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x8001D610: beq         $a0, $zero, L_8001D62C
    if (ctx->r4 == 0) {
        // 0x8001D614: swc1        $f0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
            goto L_8001D62C;
    }
    // 0x8001D614: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x8001D618: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x8001D61C: sh          $v0, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r2;
    // 0x8001D620: sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    // 0x8001D624: j           L_8001D634
    // 0x8001D628: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
        goto L_8001D634;
    // 0x8001D628: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
L_8001D62C:
    // 0x8001D62C: jal         0x80066D30
    // 0x8001D630: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066D30(rdram, ctx);
        goto after_0;
    // 0x8001D630: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
L_8001D634:
    // 0x8001D634: lw          $v1, 0x44($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X44);
    // 0x8001D638: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8001D63C: addiu       $v0, $v0, 0x3A40
    ctx->r2 = ADD32(ctx->r2, 0X3A40);
    // 0x8001D640: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x8001D644: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001D648: sb          $v0, 0x16($s0)
    MEM_B(0X16, ctx->r16) = ctx->r2;
    // 0x8001D64C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001D650: sb          $v0, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r2;
    // 0x8001D654: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x8001D658: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8001D65C: sh          $v1, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r3;
    // 0x8001D660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D664: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001D668: jr          $ra
    // 0x8001D66C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001D66C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001D670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D670: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x8001D674: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8001D678: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
L_8001D67C:
    // 0x8001D67C: lhu         $a1, 0x0($a3)
    ctx->r5 = MEM_HU(ctx->r7, 0X0);
    // 0x8001D680: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x8001D684: srl         $v0, $v1, 27
    ctx->r2 = S32(U32(ctx->r3) >> 27);
    // 0x8001D688: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8001D68C: nop

    // 0x8001D690: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001D694: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8001D698: sra         $v0, $v1, 22
    ctx->r2 = S32(SIGNED(ctx->r3) >> 22);
    // 0x8001D69C: andi        $v0, $v0, 0x1F
    ctx->r2 = ctx->r2 & 0X1F;
    // 0x8001D6A0: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8001D6A4: nop

    // 0x8001D6A8: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8001D6AC: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8001D6B0: sra         $v1, $v1, 17
    ctx->r3 = S32(SIGNED(ctx->r3) >> 17);
    // 0x8001D6B4: andi        $v1, $v1, 0x1F
    ctx->r3 = ctx->r3 & 0X1F;
    // 0x8001D6B8: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8001D6BC: nop

    // 0x8001D6C0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001D6C4: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8001D6C8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001D6CC: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    // 0x8001D6D0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8001D6D4: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8001D6D8: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001D6DC: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8001D6E0: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001D6E4: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x8001D6E8: sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2 << 11);
    // 0x8001D6EC: sll         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3 << 6);
    // 0x8001D6F0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8001D6F4: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x8001D6F8: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8001D6FC: or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // 0x8001D700: sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    // 0x8001D704: sltiu       $v0, $t0, 0x100
    ctx->r2 = ctx->r8 < 0X100 ? 1 : 0;
    // 0x8001D708: bne         $v0, $zero, L_8001D67C
    if (ctx->r2 != 0) {
        // 0x8001D70C: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_8001D67C;
    }
    // 0x8001D70C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8001D710: jr          $ra
    // 0x8001D714: nop

    return;
    // 0x8001D714: nop

;}
RECOMP_FUNC void func_8001D718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D718: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001D71C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001D720: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001D724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D728: lw          $v1, 0x44($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X44);
    // 0x8001D72C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001D730: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x8001D734: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x8001D738: srav        $v0, $v0, $v1
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r3 & 31));
    // 0x8001D73C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8001D740: beq         $v0, $zero, L_8001D750
    if (ctx->r2 == 0) {
        // 0x8001D744: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8001D750;
    }
    // 0x8001D744: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001D748: j           L_8001D864
    // 0x8001D74C: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
        goto L_8001D864;
    // 0x8001D74C: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
L_8001D750:
    // 0x8001D750: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001D754: sb          $v1, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r3;
    // 0x8001D758: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001D75C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001D760: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001D764: lw          $v0, 0x17D8($at)
    ctx->r2 = MEM_W(ctx->r1, 0X17D8);
    // 0x8001D768: jalr        $v0
    // 0x8001D76C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8001D76C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8001D770: lwc1        $f12, 0x34($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8001D774: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8001D778: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001D77C: nop

    // 0x8001D780: div.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8001D784: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8001D788: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8001D78C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001D790: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001D794: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001D798: div.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001D79C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001D7A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001D7A4: nop

    // 0x8001D7A8: div.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8001D7AC: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001D7B0: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8001D7B4: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001D7B8: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001D7BC: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8001D7C0: lwc1        $f2, 0x4C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8001D7C4: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8001D7C8: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001D7CC: div.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8001D7D0: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001D7D4: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8001D7D8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001D7DC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8001D7E0: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001D7E4: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001D7E8: nop

    // 0x8001D7EC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001D7F0: sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // 0x8001D7F4: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001D7F8: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8001D7FC: nop

    // 0x8001D800: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001D804: lwc1        $f2, 0x44($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8001D808: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8001D80C: sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // 0x8001D810: trunc.w.s   $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8001D814: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8001D818: nop

    // 0x8001D81C: sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    // 0x8001D820: sub.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x8001D824: trunc.w.s   $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8001D828: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8001D82C: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8001D830: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001D834: sh          $v0, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r2;
    // 0x8001D838: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8001D83C: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001D840: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001D844: nop

    // 0x8001D848: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001D84C: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x8001D850: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001D854: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8001D858: nop

    // 0x8001D85C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001D860: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
L_8001D864:
    // 0x8001D864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D868: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001D86C: jr          $ra
    // 0x8001D870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001D870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001D874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D874: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x8001D878: lbu         $v1, 0x2C($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X2C);
    // 0x8001D87C: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x8001D880: beq         $v0, $zero, L_8001DC3C
    if (ctx->r2 == 0) {
        // 0x8001D884: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8001DC3C;
    }
    // 0x8001D884: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001D888: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001D88C: addu        $at, $at, $v0
    gpr jr_addend_8001D894 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001D890: lw          $v0, -0x2D50($at)
    ctx->r2 = ADD32(ctx->r1, -0X2D50);
    // 0x8001D894: jr          $v0
    // 0x8001D898: nop

    switch (jr_addend_8001D894 >> 2) {
        case 0: goto L_8001D89C; break;
        case 1: goto L_8001DA90; break;
        case 2: goto L_8001DAD8; break;
        case 3: goto L_8001DB48; break;
        case 4: goto L_8001DBE4; break;
        default: switch_error(__func__, 0x8001D894, 0x800AD2B0);
    }
    // 0x8001D898: nop

L_8001D89C:
    // 0x8001D89C: lbu         $v0, 0x2C($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X2C);
    // 0x8001D8A0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001D8A4: sb          $v0, 0x2C($a3)
    MEM_B(0X2C, ctx->r7) = ctx->r2;
    // 0x8001D8A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001D8AC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001D8B0: sb          $v0, 0x7B88($at)
    MEM_B(0X7B88, ctx->r1) = ctx->r2;
    // 0x8001D8B4: lw          $v0, 0x54($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X54);
    // 0x8001D8B8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001D8BC: lbu         $v1, 0x7B9B($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B9B);
    // 0x8001D8C0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001D8C4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8001D8C8: lb          $a0, -0x391C($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X391C);
    // 0x8001D8CC: beq         $v1, $zero, L_8001D90C
    if (ctx->r3 == 0) {
        // 0x8001D8D0: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_8001D90C;
    }
    // 0x8001D8D0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8001D8D4: bne         $a0, $v0, L_8001D8E4
    if (ctx->r4 != ctx->r2) {
        // 0x8001D8D8: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_8001D8E4;
    }
    // 0x8001D8D8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8001D8DC: j           L_8001D90C
    // 0x8001D8E0: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
        goto L_8001D90C;
    // 0x8001D8E0: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
L_8001D8E4:
    // 0x8001D8E4: bne         $a0, $v0, L_8001D8F4
    if (ctx->r4 != ctx->r2) {
        // 0x8001D8E8: addiu       $v0, $zero, 0x13
        ctx->r2 = ADD32(0, 0X13);
            goto L_8001D8F4;
    }
    // 0x8001D8E8: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x8001D8EC: j           L_8001D90C
    // 0x8001D8F0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
        goto L_8001D90C;
    // 0x8001D8F0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_8001D8F4:
    // 0x8001D8F4: bne         $a0, $v0, L_8001D904
    if (ctx->r4 != ctx->r2) {
        // 0x8001D8F8: addiu       $v0, $zero, 0x15
        ctx->r2 = ADD32(0, 0X15);
            goto L_8001D904;
    }
    // 0x8001D8F8: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    // 0x8001D8FC: j           L_8001D90C
    // 0x8001D900: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
        goto L_8001D90C;
    // 0x8001D900: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
L_8001D904:
    // 0x8001D904: beql        $a0, $v0, L_8001D90C
    if (ctx->r4 == ctx->r2) {
        // 0x8001D908: addiu       $a0, $zero, 0x13
        ctx->r4 = ADD32(0, 0X13);
            goto L_8001D90C;
    }
    goto skip_0;
    // 0x8001D908: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    skip_0:
L_8001D90C:
    // 0x8001D90C: addu        $t0, $a3, $zero
    ctx->r8 = ADD32(ctx->r7, 0);
    // 0x8001D910: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8001D914: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001D918: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8001D91C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001D920: addiu       $v1, $v1, 0x18B0
    ctx->r3 = ADD32(ctx->r3, 0X18B0);
    // 0x8001D924: addu        $a2, $v0, $v1
    ctx->r6 = ADD32(ctx->r2, ctx->r3);
    // 0x8001D928: or          $v1, $a2, $a3
    ctx->r3 = ctx->r6 | ctx->r7;
    // 0x8001D92C: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x8001D930: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001D934: sb          $v0, 0x2E($a3)
    MEM_B(0X2E, ctx->r7) = ctx->r2;
    // 0x8001D938: sb          $v0, 0x2A($a3)
    MEM_B(0X2A, ctx->r7) = ctx->r2;
    // 0x8001D93C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001D940: addiu       $v0, $v0, -0x2338
    ctx->r2 = ADD32(ctx->r2, -0X2338);
    // 0x8001D944: beq         $v1, $zero, L_8001D9A4
    if (ctx->r3 == 0) {
        // 0x8001D948: sw          $v0, 0x30($a3)
        MEM_W(0X30, ctx->r7) = ctx->r2;
            goto L_8001D9A4;
    }
    // 0x8001D948: sw          $v0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r2;
    // 0x8001D94C: addiu       $t1, $a2, 0x20
    ctx->r9 = ADD32(ctx->r6, 0X20);
L_8001D950:
    // 0x8001D950: lwl         $v0, 0x0($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r6, 0X0);
    // 0x8001D954: lwr         $v0, 0x3($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r6, 0X3);
    // 0x8001D958: lwl         $v1, 0x4($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r6, 0X4);
    // 0x8001D95C: lwr         $v1, 0x7($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r6, 0X7);
    // 0x8001D960: lwl         $a0, 0x8($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r6, 0X8);
    // 0x8001D964: lwr         $a0, 0xB($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r6, 0XB);
    // 0x8001D968: lwl         $a1, 0xC($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, ctx->r6, 0XC);
    // 0x8001D96C: lwr         $a1, 0xF($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, ctx->r6, 0XF);
    // 0x8001D970: swl         $v0, 0x0($t0)
    do_swl(rdram, 0X0, ctx->r8, ctx->r2);
    // 0x8001D974: swr         $v0, 0x3($t0)
    do_swr(rdram, 0X3, ctx->r8, ctx->r2);
    // 0x8001D978: swl         $v1, 0x4($t0)
    do_swl(rdram, 0X4, ctx->r8, ctx->r3);
    // 0x8001D97C: swr         $v1, 0x7($t0)
    do_swr(rdram, 0X7, ctx->r8, ctx->r3);
    // 0x8001D980: swl         $a0, 0x8($t0)
    do_swl(rdram, 0X8, ctx->r8, ctx->r4);
    // 0x8001D984: swr         $a0, 0xB($t0)
    do_swr(rdram, 0XB, ctx->r8, ctx->r4);
    // 0x8001D988: swl         $a1, 0xC($t0)
    do_swl(rdram, 0XC, ctx->r8, ctx->r5);
    // 0x8001D98C: swr         $a1, 0xF($t0)
    do_swr(rdram, 0XF, ctx->r8, ctx->r5);
    // 0x8001D990: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001D994: bne         $a2, $t1, L_8001D950
    if (ctx->r6 != ctx->r9) {
        // 0x8001D998: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_8001D950;
    }
    // 0x8001D998: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8001D99C: j           L_8001D9D4
    // 0x8001D9A0: nop

        goto L_8001D9D4;
    // 0x8001D9A0: nop

L_8001D9A4:
    // 0x8001D9A4: addiu       $t1, $a2, 0x20
    ctx->r9 = ADD32(ctx->r6, 0X20);
L_8001D9A8:
    // 0x8001D9A8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001D9AC: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001D9B0: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001D9B4: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001D9B8: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8001D9BC: sw          $v1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r3;
    // 0x8001D9C0: sw          $a0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r4;
    // 0x8001D9C4: sw          $a1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r5;
    // 0x8001D9C8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001D9CC: bne         $a2, $t1, L_8001D9A8
    if (ctx->r6 != ctx->r9) {
        // 0x8001D9D0: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_8001D9A8;
    }
    // 0x8001D9D0: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
L_8001D9D4:
    // 0x8001D9D4: lwl         $v0, 0x0($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r6, 0X0);
    // 0x8001D9D8: lwr         $v0, 0x3($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r6, 0X3);
    // 0x8001D9DC: lwl         $v1, 0x4($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r6, 0X4);
    // 0x8001D9E0: lwr         $v1, 0x7($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r6, 0X7);
    // 0x8001D9E4: swl         $v0, 0x0($t0)
    do_swl(rdram, 0X0, ctx->r8, ctx->r2);
    // 0x8001D9E8: swr         $v0, 0x3($t0)
    do_swr(rdram, 0X3, ctx->r8, ctx->r2);
    // 0x8001D9EC: swl         $v1, 0x4($t0)
    do_swl(rdram, 0X4, ctx->r8, ctx->r3);
    // 0x8001D9F0: swr         $v1, 0x7($t0)
    do_swr(rdram, 0X7, ctx->r8, ctx->r3);
    // 0x8001D9F4: lhu         $v1, 0x2($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X2);
    // 0x8001D9F8: lhu         $a1, 0xA($a3)
    ctx->r5 = MEM_HU(ctx->r7, 0XA);
    // 0x8001D9FC: lhu         $a0, 0x4($a3)
    ctx->r4 = MEM_HU(ctx->r7, 0X4);
    // 0x8001DA00: lui         $at, 0x3DCC
    ctx->r1 = S32(0X3DCC << 16);
    // 0x8001DA04: ori         $at, $at, 0xCCCD
    ctx->r1 = ctx->r1 | 0XCCCD;
    // 0x8001DA08: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001DA0C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001DA10: sb          $v0, 0x2A($a3)
    MEM_B(0X2A, ctx->r7) = ctx->r2;
    // 0x8001DA14: addiu       $v0, $zero, 0xE6
    ctx->r2 = ADD32(0, 0XE6);
    // 0x8001DA18: sb          $v0, 0x2F($a3)
    MEM_B(0X2F, ctx->r7) = ctx->r2;
    // 0x8001DA1C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001DA20: sb          $v0, 0x2D($a3)
    MEM_B(0X2D, ctx->r7) = ctx->r2;
    // 0x8001DA24: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8001DA28: addiu       $v0, $v0, -0x5300
    ctx->r2 = ADD32(ctx->r2, -0X5300);
    // 0x8001DA2C: sw          $v0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r2;
    // 0x8001DA30: srl         $v1, $v1, 2
    ctx->r3 = S32(U32(ctx->r3) >> 2);
    // 0x8001DA34: srl         $a1, $a1, 2
    ctx->r5 = S32(U32(ctx->r5) >> 2);
    // 0x8001DA38: sw          $v1, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r3;
    // 0x8001DA3C: lw          $v0, 0x4C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X4C);
    // 0x8001DA40: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8001DA44: sra         $a0, $a0, 18
    ctx->r4 = S32(SIGNED(ctx->r4) >> 18);
    // 0x8001DA48: sw          $a1, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r5;
    // 0x8001DA4C: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x8001DA50: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001DA54: lhu         $v1, 0xC($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0XC);
    // 0x8001DA58: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8001DA5C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8001DA60: lw          $v0, 0x50($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X50);
    // 0x8001DA64: swc1        $f0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f0.u32l;
    // 0x8001DA68: swc1        $f0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f0.u32l;
    // 0x8001DA6C: sw          $a0, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r4;
    // 0x8001DA70: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8001DA74: sra         $v1, $v1, 18
    ctx->r3 = S32(SIGNED(ctx->r3) >> 18);
    // 0x8001DA78: srl         $a0, $v0, 31
    ctx->r4 = S32(U32(ctx->r2) >> 31);
    // 0x8001DA7C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001DA80: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8001DA84: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001DA88: j           L_8001DC3C
    // 0x8001DA8C: sw          $v1, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r3;
        goto L_8001DC3C;
    // 0x8001DA8C: sw          $v1, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r3;
L_8001DA90:
    // 0x8001DA90: lwc1        $f0, 0x34($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X34);
    // 0x8001DA94: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001DA98: ldc1        $f2, -0x2D38($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2D38);
    // 0x8001DA9C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001DAA0: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8001DAA4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001DAA8: ldc1        $f4, -0x2D30($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2D30);
    // 0x8001DAAC: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001DAB0: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8001DAB4: c.le.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d <= ctx->f2.d;
    // 0x8001DAB8: nop

    // 0x8001DABC: nop

    // 0x8001DAC0: bc1f        L_8001DC3C
    if (!c1cs) {
        // 0x8001DAC4: swc1        $f0, 0x34($a3)
        MEM_W(0X34, ctx->r7) = ctx->f0.u32l;
            goto L_8001DC3C;
    }
    // 0x8001DAC4: swc1        $f0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f0.u32l;
    // 0x8001DAC8: lbu         $v0, 0x2C($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X2C);
    // 0x8001DACC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001DAD0: j           L_8001DC3C
    // 0x8001DAD4: sb          $v0, 0x2C($a3)
    MEM_B(0X2C, ctx->r7) = ctx->r2;
        goto L_8001DC3C;
    // 0x8001DAD4: sb          $v0, 0x2C($a3)
    MEM_B(0X2C, ctx->r7) = ctx->r2;
L_8001DAD8:
    // 0x8001DAD8: lwc1        $f0, 0x34($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X34);
    // 0x8001DADC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001DAE0: ldc1        $f2, -0x2D28($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2D28);
    // 0x8001DAE4: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001DAE8: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8001DAEC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001DAF0: ldc1        $f4, -0x2D20($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2D20);
    // 0x8001DAF4: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001DAF8: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8001DAFC: c.le.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d <= ctx->f2.d;
    // 0x8001DB00: nop

    // 0x8001DB04: nop

    // 0x8001DB08: bc1f        L_8001DB28
    if (!c1cs) {
        // 0x8001DB0C: swc1        $f0, 0x34($a3)
        MEM_W(0X34, ctx->r7) = ctx->f0.u32l;
            goto L_8001DB28;
    }
    // 0x8001DB0C: swc1        $f0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f0.u32l;
    // 0x8001DB10: lbu         $v0, 0x2C($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X2C);
    // 0x8001DB14: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8001DB18: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001DB1C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001DB20: sb          $v0, 0x2C($a3)
    MEM_B(0X2C, ctx->r7) = ctx->r2;
    // 0x8001DB24: swc1        $f0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f0.u32l;
L_8001DB28:
    // 0x8001DB28: lwc1        $f0, 0x38($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X38);
    // 0x8001DB2C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001DB30: ldc1        $f2, -0x2D18($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2D18);
    // 0x8001DB34: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001DB38: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8001DB3C: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001DB40: j           L_8001DC3C
    // 0x8001DB44: swc1        $f0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f0.u32l;
        goto L_8001DC3C;
    // 0x8001DB44: swc1        $f0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f0.u32l;
L_8001DB48:
    // 0x8001DB48: lwc1        $f0, 0x38($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X38);
    // 0x8001DB4C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001DB50: ldc1        $f2, -0x2D10($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2D10);
    // 0x8001DB54: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001DB58: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8001DB5C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001DB60: ldc1        $f4, -0x2D08($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2D08);
    // 0x8001DB64: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001DB68: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8001DB6C: c.le.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d <= ctx->f2.d;
    // 0x8001DB70: nop

    // 0x8001DB74: nop

    // 0x8001DB78: bc1f        L_8001DB98
    if (!c1cs) {
        // 0x8001DB7C: swc1        $f0, 0x38($a3)
        MEM_W(0X38, ctx->r7) = ctx->f0.u32l;
            goto L_8001DB98;
    }
    // 0x8001DB7C: swc1        $f0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f0.u32l;
    // 0x8001DB80: lbu         $v0, 0x2C($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X2C);
    // 0x8001DB84: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8001DB88: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001DB8C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001DB90: sb          $v0, 0x2C($a3)
    MEM_B(0X2C, ctx->r7) = ctx->r2;
    // 0x8001DB94: swc1        $f0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f0.u32l;
L_8001DB98:
    // 0x8001DB98: lwc1        $f0, 0x34($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X34);
    // 0x8001DB9C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001DBA0: ldc1        $f2, -0x2D00($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2D00);
    // 0x8001DBA4: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001DBA8: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8001DBAC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001DBB0: ldc1        $f4, -0x2CF8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2CF8);
    // 0x8001DBB4: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001DBB8: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8001DBBC: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x8001DBC0: nop

    // 0x8001DBC4: nop

    // 0x8001DBC8: bc1f        L_8001DC3C
    if (!c1cs) {
        // 0x8001DBCC: swc1        $f0, 0x34($a3)
        MEM_W(0X34, ctx->r7) = ctx->f0.u32l;
            goto L_8001DC3C;
    }
    // 0x8001DBCC: swc1        $f0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f0.u32l;
    // 0x8001DBD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001DBD4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001DBD8: nop

    // 0x8001DBDC: j           L_8001DC3C
    // 0x8001DBE0: swc1        $f0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f0.u32l;
        goto L_8001DC3C;
    // 0x8001DBE0: swc1        $f0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f0.u32l;
L_8001DBE4:
    // 0x8001DBE4: lwc1        $f0, 0x38($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X38);
    // 0x8001DBE8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001DBEC: ldc1        $f2, -0x2CF0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2CF0);
    // 0x8001DBF0: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001DBF4: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8001DBF8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001DBFC: ldc1        $f4, -0x2CE8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2CE8);
    // 0x8001DC00: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001DC04: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8001DC08: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x8001DC0C: nop

    // 0x8001DC10: nop

    // 0x8001DC14: bc1f        L_8001DC3C
    if (!c1cs) {
        // 0x8001DC18: swc1        $f0, 0x38($a3)
        MEM_W(0X38, ctx->r7) = ctx->f0.u32l;
            goto L_8001DC3C;
    }
    // 0x8001DC18: swc1        $f0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f0.u32l;
    // 0x8001DC1C: lbu         $v0, 0x2B($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X2B);
    // 0x8001DC20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001DC24: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001DC28: sb          $zero, 0x2C($a3)
    MEM_B(0X2C, ctx->r7) = 0;
    // 0x8001DC2C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001DC30: sb          $v0, 0x2B($a3)
    MEM_B(0X2B, ctx->r7) = ctx->r2;
    // 0x8001DC34: j           L_8001DC94
    // 0x8001DC38: swc1        $f0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f0.u32l;
        goto L_8001DC94;
    // 0x8001DC38: swc1        $f0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f0.u32l;
L_8001DC3C:
    // 0x8001DC3C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001DC40: lbu         $v0, 0x7B9C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9C);
    // 0x8001DC44: beq         $v0, $zero, L_8001DC94
    if (ctx->r2 == 0) {
        // 0x8001DC48: nop
    
            goto L_8001DC94;
    }
    // 0x8001DC48: nop

    // 0x8001DC4C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001DC50: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8001DC54: sltiu       $a0, $v0, 0x1
    ctx->r4 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8001DC58: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8001DC5C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001DC60: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001DC64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001DC68: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001DC6C: lhu         $v0, -0x33C8($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X33C8);
    // 0x8001DC70: andi        $v0, $v0, 0xC030
    ctx->r2 = ctx->r2 & 0XC030;
    // 0x8001DC74: beq         $v0, $zero, L_8001DC94
    if (ctx->r2 == 0) {
        // 0x8001DC78: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001DC94;
    }
    // 0x8001DC78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001DC7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001DC80: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001DC84: sb          $v0, 0x2B($a3)
    MEM_B(0X2B, ctx->r7) = ctx->r2;
    // 0x8001DC88: sb          $zero, 0x2C($a3)
    MEM_B(0X2C, ctx->r7) = 0;
    // 0x8001DC8C: swc1        $f0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f0.u32l;
    // 0x8001DC90: swc1        $f0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f0.u32l;
L_8001DC94:
    // 0x8001DC94: jr          $ra
    // 0x8001DC98: nop

    return;
    // 0x8001DC98: nop

;}
RECOMP_FUNC void func_8001DC9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DC9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001DCA0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001DCA4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001DCA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001DCAC: lbu         $v0, 0x2C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2C);
    // 0x8001DCB0: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8001DCB4: beq         $v1, $zero, L_8001DCD0
    if (ctx->r3 == 0) {
        // 0x8001DCB8: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001DCD0;
    }
    // 0x8001DCB8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001DCBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001DCC0: beq         $v1, $v0, L_8001DDA4
    if (ctx->r3 == ctx->r2) {
        // 0x8001DCC4: nop
    
            goto L_8001DDA4;
    }
    // 0x8001DCC4: nop

    // 0x8001DCC8: j           L_8001DE2C
    // 0x8001DCCC: nop

        goto L_8001DE2C;
    // 0x8001DCCC: nop

L_8001DCD0:
    // 0x8001DCD0: jal         0x80053390
    // 0x8001DCD4: sb          $v0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r2;
    func_80053390(rdram, ctx);
        goto after_0;
    // 0x8001DCD4: sb          $v0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r2;
    after_0:
    // 0x8001DCD8: jal         0x8005357C
    // 0x8001DCDC: nop

    func_8005357C(rdram, ctx);
        goto after_1;
    // 0x8001DCDC: nop

    after_1:
    // 0x8001DCE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001DCE4: beq         $v0, $zero, L_8001DE2C
    if (ctx->r2 == 0) {
        // 0x8001DCE8: sw          $v0, 0x5030($at)
        MEM_W(0X5030, ctx->r1) = ctx->r2;
            goto L_8001DE2C;
    }
    // 0x8001DCE8: sw          $v0, 0x5030($at)
    MEM_W(0X5030, ctx->r1) = ctx->r2;
    // 0x8001DCEC: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x8001DCF0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001DCF4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001DCF8: lb          $v0, -0x391C($at)
    ctx->r2 = MEM_B(ctx->r1, -0X391C);
    // 0x8001DCFC: slti        $v0, $v0, 0x13
    ctx->r2 = SIGNED(ctx->r2) < 0X13 ? 1 : 0;
    // 0x8001DD00: bne         $v0, $zero, L_8001DD0C
    if (ctx->r2 != 0) {
        // 0x8001DD04: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_8001DD0C;
    }
    // 0x8001DD04: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8001DD08: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_8001DD0C:
    // 0x8001DD0C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8001DD10: lw          $v1, 0x5030($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5030);
    // 0x8001DD14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001DD18: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8001DD1C: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x8001DD20: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8001DD24: lw          $v1, 0x5030($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5030);
    // 0x8001DD28: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001DD2C: sra         $v0, $v0, 18
    ctx->r2 = S32(SIGNED(ctx->r2) >> 18);
    // 0x8001DD30: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8001DD34: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8001DD38: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x8001DD3C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8001DD40: lw          $v1, 0x5030($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5030);
    // 0x8001DD44: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001DD48: sra         $v0, $v0, 18
    ctx->r2 = S32(SIGNED(ctx->r2) >> 18);
    // 0x8001DD4C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001DD50: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8001DD54: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8001DD58: lw          $v0, 0x5030($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5030);
    // 0x8001DD5C: sw          $zero, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = 0;
    // 0x8001DD60: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x8001DD64: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8001DD68: lw          $v1, 0x5030($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5030);
    // 0x8001DD6C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001DD70: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8001DD74: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001DD78: lw          $v0, 0x540($at)
    ctx->r2 = MEM_W(ctx->r1, 0X540);
    // 0x8001DD7C: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x8001DD80: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8001DD84: lw          $v0, 0x5030($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5030);
    // 0x8001DD88: sh          $zero, 0x66($v0)
    MEM_H(0X66, ctx->r2) = 0;
    // 0x8001DD8C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8001DD90: lw          $v0, 0x5030($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5030);
    // 0x8001DD94: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x8001DD98: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x8001DD9C: j           L_8001DE2C
    // 0x8001DDA0: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
        goto L_8001DE2C;
    // 0x8001DDA0: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
L_8001DDA4:
    // 0x8001DDA4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001DDA8: lbu         $v0, 0x7B9C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9C);
    // 0x8001DDAC: beq         $v0, $zero, L_8001DDF0
    if (ctx->r2 == 0) {
        // 0x8001DDB0: nop
    
            goto L_8001DDF0;
    }
    // 0x8001DDB0: nop

    // 0x8001DDB4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001DDB8: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8001DDBC: sltiu       $a0, $v0, 0x1
    ctx->r4 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8001DDC0: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8001DDC4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001DDC8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001DDCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001DDD0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001DDD4: lhu         $v0, -0x33C8($at)
    ctx->r2 = MEM_HU(ctx->r1, -0X33C8);
    // 0x8001DDD8: andi        $v0, $v0, 0xC030
    ctx->r2 = ctx->r2 & 0XC030;
    // 0x8001DDDC: beq         $v0, $zero, L_8001DDF0
    if (ctx->r2 == 0) {
        // 0x8001DDE0: nop
    
            goto L_8001DDF0;
    }
    // 0x8001DDE0: nop

    // 0x8001DDE4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8001DDE8: lw          $v0, 0x5030($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5030);
    // 0x8001DDEC: sw          $v1, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r3;
L_8001DDF0:
    // 0x8001DDF0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8001DDF4: lw          $v0, 0x5030($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5030);
    // 0x8001DDF8: lw          $v0, 0x68($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X68);
    // 0x8001DDFC: beq         $v0, $zero, L_8001DE2C
    if (ctx->r2 == 0) {
        // 0x8001DE00: nop
    
            goto L_8001DE2C;
    }
    // 0x8001DE00: nop

    // 0x8001DE04: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001DE08: sb          $zero, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = 0;
    // 0x8001DE0C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001DE10: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x8001DE14: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8001DE18: lw          $a0, 0x5030($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5030);
    // 0x8001DE1C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001DE20: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001DE24: jal         0x800535B0
    // 0x8001DE28: sb          $v0, 0x7B88($at)
    MEM_B(0X7B88, ctx->r1) = ctx->r2;
    func_800535B0(rdram, ctx);
        goto after_2;
    // 0x8001DE28: sb          $v0, 0x7B88($at)
    MEM_B(0X7B88, ctx->r1) = ctx->r2;
    after_2:
L_8001DE2C:
    // 0x8001DE2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001DE30: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001DE34: jr          $ra
    // 0x8001DE38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001DE38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001DE3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DE3C: lbu         $a1, 0x2C($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X2C);
    // 0x8001DE40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001DE44: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x8001DE48: beq         $v1, $v0, L_8001DE98
    if (ctx->r3 == ctx->r2) {
        // 0x8001DE4C: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8001DE98;
    }
    // 0x8001DE4C: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8001DE50: beql        $v0, $zero, L_8001DE68
    if (ctx->r2 == 0) {
        // 0x8001DE54: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8001DE68;
    }
    goto skip_0;
    // 0x8001DE54: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8001DE58: beq         $v1, $zero, L_8001DE80
    if (ctx->r3 == 0) {
        // 0x8001DE5C: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_8001DE80;
    }
    // 0x8001DE5C: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x8001DE60: j           L_8001DF3C
    // 0x8001DE64: nop

        goto L_8001DF3C;
    // 0x8001DE64: nop

L_8001DE68:
    // 0x8001DE68: beq         $v1, $v0, L_8001DED8
    if (ctx->r3 == ctx->r2) {
        // 0x8001DE6C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8001DED8;
    }
    // 0x8001DE6C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001DE70: beq         $v1, $v0, L_8001DF20
    if (ctx->r3 == ctx->r2) {
        // 0x8001DE74: nop
    
            goto L_8001DF20;
    }
    // 0x8001DE74: nop

    // 0x8001DE78: j           L_8001DF3C
    // 0x8001DE7C: nop

        goto L_8001DF3C;
    // 0x8001DE7C: nop

L_8001DE80:
    // 0x8001DE80: sb          $v0, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r2;
    // 0x8001DE84: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001DE88: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    // 0x8001DE8C: addiu       $v0, $zero, 0xE6
    ctx->r2 = ADD32(0, 0XE6);
    // 0x8001DE90: j           L_8001DF3C
    // 0x8001DE94: sb          $v0, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r2;
        goto L_8001DF3C;
    // 0x8001DE94: sb          $v0, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r2;
L_8001DE98:
    // 0x8001DE98: lwc1        $f0, 0x38($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8001DE9C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001DEA0: ldc1        $f2, -0x2CE0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2CE0);
    // 0x8001DEA4: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001DEA8: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8001DEAC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001DEB0: ldc1        $f4, -0x2CD8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2CD8);
    // 0x8001DEB4: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001DEB8: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8001DEBC: c.le.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d <= ctx->f2.d;
    // 0x8001DEC0: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x8001DEC4: nop

    // 0x8001DEC8: bc1f        L_8001DF3C
    if (!c1cs) {
        // 0x8001DECC: swc1        $f0, 0x34($a0)
        MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
            goto L_8001DF3C;
    }
    // 0x8001DECC: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x8001DED0: j           L_8001DF10
    // 0x8001DED4: nop

        goto L_8001DF10;
    // 0x8001DED4: nop

L_8001DED8:
    // 0x8001DED8: lwc1        $f0, 0x38($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8001DEDC: lbu         $v0, 0x2F($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2F);
    // 0x8001DEE0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001DEE4: ldc1        $f2, -0x2CD0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2CD0);
    // 0x8001DEE8: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001DEEC: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x8001DEF0: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8001DEF4: sb          $v0, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r2;
    // 0x8001DEF8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001DEFC: sltiu       $v0, $v0, 0x33
    ctx->r2 = ctx->r2 < 0X33 ? 1 : 0;
    // 0x8001DF00: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001DF04: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x8001DF08: beq         $v0, $zero, L_8001DF3C
    if (ctx->r2 == 0) {
        // 0x8001DF0C: swc1        $f0, 0x34($a0)
        MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
            goto L_8001DF3C;
    }
    // 0x8001DF0C: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
L_8001DF10:
    // 0x8001DF10: lbu         $v0, 0x2C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2C);
    // 0x8001DF14: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001DF18: j           L_8001DF3C
    // 0x8001DF1C: sb          $v0, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r2;
        goto L_8001DF3C;
    // 0x8001DF1C: sb          $v0, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r2;
L_8001DF20:
    // 0x8001DF20: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001DF24: sb          $zero, 0x7B88($at)
    MEM_B(0X7B88, ctx->r1) = 0;
    // 0x8001DF28: sb          $zero, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = 0;
    // 0x8001DF2C: sb          $zero, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = 0;
    // 0x8001DF30: sb          $zero, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = 0;
    // 0x8001DF34: j           L_8001DF80
    // 0x8001DF38: sb          $zero, 0x28($a0)
    MEM_B(0X28, ctx->r4) = 0;
        goto L_8001DF80;
    // 0x8001DF38: sb          $zero, 0x28($a0)
    MEM_B(0X28, ctx->r4) = 0;
L_8001DF3C:
    // 0x8001DF3C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001DF40: lbu         $v0, 0x7B9C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9C);
    // 0x8001DF44: beq         $v0, $zero, L_8001DF80
    if (ctx->r2 == 0) {
        // 0x8001DF48: nop
    
            goto L_8001DF80;
    }
    // 0x8001DF48: nop

    // 0x8001DF4C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001DF50: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8001DF54: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8001DF58: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8001DF5C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001DF60: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8001DF64: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8001DF68: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001DF6C: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x8001DF70: andi        $v0, $v0, 0xC030
    ctx->r2 = ctx->r2 & 0XC030;
    // 0x8001DF74: beq         $v0, $zero, L_8001DF80
    if (ctx->r2 == 0) {
        // 0x8001DF78: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8001DF80;
    }
    // 0x8001DF78: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001DF7C: sb          $v0, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r2;
L_8001DF80:
    // 0x8001DF80: jr          $ra
    // 0x8001DF84: nop

    return;
    // 0x8001DF84: nop

;}
RECOMP_FUNC void func_8001DF88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DF88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001DF8C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8001DF90: lbu         $v0, 0x2B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2B);
    // 0x8001DF94: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001DF98: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001DF9C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001DFA0: lw          $v0, 0x17E4($at)
    ctx->r2 = MEM_W(ctx->r1, 0X17E4);
    // 0x8001DFA4: jalr        $v0
    // 0x8001DFA8: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8001DFA8: nop

    after_0:
    // 0x8001DFAC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8001DFB0: jr          $ra
    // 0x8001DFB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001DFB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001DFB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DFB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001DFBC: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x8001DFC0: addu        $t0, $a3, $zero
    ctx->r8 = ADD32(ctx->r7, 0);
    // 0x8001DFC4: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8001DFC8: addiu       $a2, $a2, 0x19F0
    ctx->r6 = ADD32(ctx->r6, 0X19F0);
    // 0x8001DFCC: or          $a0, $a3, $a2
    ctx->r4 = ctx->r7 | ctx->r6;
    // 0x8001DFD0: lbu         $v1, 0x2B($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X2B);
    // 0x8001DFD4: andi        $a0, $a0, 0x3
    ctx->r4 = ctx->r4 & 0X3;
    // 0x8001DFD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001DFDC: sb          $v0, 0x2E($a3)
    MEM_B(0X2E, ctx->r7) = ctx->r2;
    // 0x8001DFE0: sb          $v0, 0x2A($a3)
    MEM_B(0X2A, ctx->r7) = ctx->r2;
    // 0x8001DFE4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001DFE8: addiu       $v0, $v0, -0x2338
    ctx->r2 = ADD32(ctx->r2, -0X2338);
    // 0x8001DFEC: sw          $v0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r2;
    // 0x8001DFF0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001DFF4: beq         $a0, $zero, L_8001E054
    if (ctx->r4 == 0) {
        // 0x8001DFF8: sb          $v1, 0x2B($a3)
        MEM_B(0X2B, ctx->r7) = ctx->r3;
            goto L_8001E054;
    }
    // 0x8001DFF8: sb          $v1, 0x2B($a3)
    MEM_B(0X2B, ctx->r7) = ctx->r3;
    // 0x8001DFFC: addiu       $t1, $a2, 0x20
    ctx->r9 = ADD32(ctx->r6, 0X20);
L_8001E000:
    // 0x8001E000: lwl         $v0, 0x0($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r6, 0X0);
    // 0x8001E004: lwr         $v0, 0x3($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r6, 0X3);
    // 0x8001E008: lwl         $v1, 0x4($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r6, 0X4);
    // 0x8001E00C: lwr         $v1, 0x7($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r6, 0X7);
    // 0x8001E010: lwl         $a0, 0x8($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r6, 0X8);
    // 0x8001E014: lwr         $a0, 0xB($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r6, 0XB);
    // 0x8001E018: lwl         $a1, 0xC($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, ctx->r6, 0XC);
    // 0x8001E01C: lwr         $a1, 0xF($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, ctx->r6, 0XF);
    // 0x8001E020: swl         $v0, 0x0($t0)
    do_swl(rdram, 0X0, ctx->r8, ctx->r2);
    // 0x8001E024: swr         $v0, 0x3($t0)
    do_swr(rdram, 0X3, ctx->r8, ctx->r2);
    // 0x8001E028: swl         $v1, 0x4($t0)
    do_swl(rdram, 0X4, ctx->r8, ctx->r3);
    // 0x8001E02C: swr         $v1, 0x7($t0)
    do_swr(rdram, 0X7, ctx->r8, ctx->r3);
    // 0x8001E030: swl         $a0, 0x8($t0)
    do_swl(rdram, 0X8, ctx->r8, ctx->r4);
    // 0x8001E034: swr         $a0, 0xB($t0)
    do_swr(rdram, 0XB, ctx->r8, ctx->r4);
    // 0x8001E038: swl         $a1, 0xC($t0)
    do_swl(rdram, 0XC, ctx->r8, ctx->r5);
    // 0x8001E03C: swr         $a1, 0xF($t0)
    do_swr(rdram, 0XF, ctx->r8, ctx->r5);
    // 0x8001E040: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001E044: bne         $a2, $t1, L_8001E000
    if (ctx->r6 != ctx->r9) {
        // 0x8001E048: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_8001E000;
    }
    // 0x8001E048: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8001E04C: j           L_8001E084
    // 0x8001E050: nop

        goto L_8001E084;
    // 0x8001E050: nop

L_8001E054:
    // 0x8001E054: addiu       $t1, $a2, 0x20
    ctx->r9 = ADD32(ctx->r6, 0X20);
L_8001E058:
    // 0x8001E058: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001E05C: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001E060: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001E064: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001E068: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8001E06C: sw          $v1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r3;
    // 0x8001E070: sw          $a0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r4;
    // 0x8001E074: sw          $a1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r5;
    // 0x8001E078: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001E07C: bne         $a2, $t1, L_8001E058
    if (ctx->r6 != ctx->r9) {
        // 0x8001E080: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_8001E058;
    }
    // 0x8001E080: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
L_8001E084:
    // 0x8001E084: lwl         $v0, 0x0($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r6, 0X0);
    // 0x8001E088: lwr         $v0, 0x3($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r6, 0X3);
    // 0x8001E08C: lwl         $v1, 0x4($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r6, 0X4);
    // 0x8001E090: lwr         $v1, 0x7($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r6, 0X7);
    // 0x8001E094: swl         $v0, 0x0($t0)
    do_swl(rdram, 0X0, ctx->r8, ctx->r2);
    // 0x8001E098: swr         $v0, 0x3($t0)
    do_swr(rdram, 0X3, ctx->r8, ctx->r2);
    // 0x8001E09C: swl         $v1, 0x4($t0)
    do_swl(rdram, 0X4, ctx->r8, ctx->r3);
    // 0x8001E0A0: swr         $v1, 0x7($t0)
    do_swr(rdram, 0X7, ctx->r8, ctx->r3);
    // 0x8001E0A4: lw          $v1, 0x44($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X44);
    // 0x8001E0A8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001E0AC: sb          $v0, 0x2A($a3)
    MEM_B(0X2A, ctx->r7) = ctx->r2;
    // 0x8001E0B0: sb          $zero, 0x2F($a3)
    MEM_B(0X2F, ctx->r7) = 0;
    // 0x8001E0B4: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8001E0B8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E0BC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001E0C0: lbu         $v0, 0x17F4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X17F4);
    // 0x8001E0C4: lw          $v1, 0x44($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X44);
    // 0x8001E0C8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001E0CC: addiu       $a0, $a0, 0x17F4
    ctx->r4 = ADD32(ctx->r4, 0X17F4);
    // 0x8001E0D0: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8001E0D4: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8001E0D8: sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    // 0x8001E0DC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E0E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001E0E4: lbu         $v0, 0x17F5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X17F5);
    // 0x8001E0E8: lw          $v1, 0x44($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X44);
    // 0x8001E0EC: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8001E0F0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8001E0F4: sh          $v0, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r2;
    // 0x8001E0F8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E0FC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001E100: lbu         $v0, 0x17F6($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X17F6);
    // 0x8001E104: lw          $v1, 0x44($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X44);
    // 0x8001E108: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001E10C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8001E110: sh          $v0, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r2;
    // 0x8001E114: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E118: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001E11C: lbu         $v0, 0x17F7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X17F7);
    // 0x8001E120: lw          $v1, 0x44($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X44);
    // 0x8001E124: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001E128: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8001E12C: sh          $v0, 0xE($a3)
    MEM_H(0XE, ctx->r7) = ctx->r2;
    // 0x8001E130: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E134: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001E138: lhu         $v0, 0x17F8($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X17F8);
    // 0x8001E13C: lw          $v1, 0x50($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X50);
    // 0x8001E140: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x8001E144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001E148: bne         $v1, $v0, L_8001E158
    if (ctx->r3 != ctx->r2) {
        // 0x8001E14C: sh          $a1, 0x4($a3)
        MEM_H(0X4, ctx->r7) = ctx->r5;
            goto L_8001E158;
    }
    // 0x8001E14C: sh          $a1, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r5;
    // 0x8001E150: addiu       $v0, $a1, 0x2B0
    ctx->r2 = ADD32(ctx->r5, 0X2B0);
    // 0x8001E154: sh          $v0, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r2;
L_8001E158:
    // 0x8001E158: lw          $v0, 0x44($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X44);
    // 0x8001E15C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8001E160: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001E164: lhu         $v1, 0x6($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X6);
    // 0x8001E168: lw          $a0, 0x44($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X44);
    // 0x8001E16C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001E170: sb          $v0, 0x2D($a3)
    MEM_B(0X2D, ctx->r7) = ctx->r2;
    // 0x8001E174: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8001E178: sh          $v1, 0xC($a3)
    MEM_H(0XC, ctx->r7) = ctx->r3;
    // 0x8001E17C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E180: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001E184: lb          $v0, 0x181C($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X181C);
    // 0x8001E188: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8001E18C: addiu       $v1, $v1, -0x36E0
    ctx->r3 = ADD32(ctx->r3, -0X36E0);
    // 0x8001E190: sw          $zero, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = 0;
    // 0x8001E194: sw          $zero, 0x48($a3)
    MEM_W(0X48, ctx->r7) = 0;
    // 0x8001E198: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8001E19C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001E1A0: sw          $v0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r2;
    // 0x8001E1A4: jr          $ra
    // 0x8001E1A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001E1A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8001E1AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E1AC: lbu         $v0, 0x2F($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2F);
    // 0x8001E1B0: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x8001E1B4: sb          $v0, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r2;
    // 0x8001E1B8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001E1BC: sltiu       $v0, $v0, 0xF1
    ctx->r2 = ctx->r2 < 0XF1 ? 1 : 0;
    // 0x8001E1C0: bne         $v0, $zero, L_8001E1D8
    if (ctx->r2 != 0) {
        // 0x8001E1C4: addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
            goto L_8001E1D8;
    }
    // 0x8001E1C4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8001E1C8: lbu         $v0, 0x2B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2B);
    // 0x8001E1CC: sb          $v1, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r3;
    // 0x8001E1D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E1D4: sb          $v0, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r2;
L_8001E1D8:
    // 0x8001E1D8: jr          $ra
    // 0x8001E1DC: nop

    return;
    // 0x8001E1DC: nop

;}
RECOMP_FUNC void func_8001E1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E1E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E1E4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001E1E8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001E1EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E1F0: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x8001E1F4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001E1F8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001E1FC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001E200: lw          $v0, 0x1824($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1824);
    // 0x8001E204: jalr        $v0
    // 0x8001E208: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8001E208: nop

    after_0:
    // 0x8001E20C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001E210: lh          $v1, 0x558C($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X558C);
    // 0x8001E214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001E218: bne         $v1, $v0, L_8001E224
    if (ctx->r3 != ctx->r2) {
        // 0x8001E21C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8001E224;
    }
    // 0x8001E21C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001E220: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_8001E224:
    // 0x8001E224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E228: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001E22C: jr          $ra
    // 0x8001E230: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001E230: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001E234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E234: jr          $ra
    // 0x8001E238: nop

    return;
    // 0x8001E238: nop

;}
RECOMP_FUNC void func_8001E23C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E23C: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x8001E240: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8001E244: bne         $v0, $zero, L_8001E254
    if (ctx->r2 != 0) {
        // 0x8001E248: addiu       $a1, $a1, 0x25A0
        ctx->r5 = ADD32(ctx->r5, 0X25A0);
            goto L_8001E254;
    }
    // 0x8001E248: addiu       $a1, $a1, 0x25A0
    ctx->r5 = ADD32(ctx->r5, 0X25A0);
    // 0x8001E24C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8001E250: addiu       $a1, $a1, 0x79F0
    ctx->r5 = ADD32(ctx->r5, 0X79F0);
L_8001E254:
    // 0x8001E254: lw          $v0, 0xB8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XB8);
    // 0x8001E258: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8001E25C: andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // 0x8001E260: bne         $v0, $zero, L_8001E28C
    if (ctx->r2 != 0) {
        // 0x8001E264: addiu       $v0, $zero, 0x800
        ctx->r2 = ADD32(0, 0X800);
            goto L_8001E28C;
    }
    // 0x8001E264: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // 0x8001E268: andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // 0x8001E26C: bne         $v0, $zero, L_8001E28C
    if (ctx->r2 != 0) {
        // 0x8001E270: addiu       $v0, $zero, 0x400
        ctx->r2 = ADD32(0, 0X400);
            goto L_8001E28C;
    }
    // 0x8001E270: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x8001E274: andi        $v0, $v1, 0x200
    ctx->r2 = ctx->r3 & 0X200;
    // 0x8001E278: bne         $v0, $zero, L_8001E28C
    if (ctx->r2 != 0) {
        // 0x8001E27C: addiu       $v0, $zero, 0x200
        ctx->r2 = ADD32(0, 0X200);
            goto L_8001E28C;
    }
    // 0x8001E27C: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x8001E280: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8001E284: beq         $v0, $zero, L_8001E290
    if (ctx->r2 == 0) {
        // 0x8001E288: addiu       $v0, $zero, 0x100
        ctx->r2 = ADD32(0, 0X100);
            goto L_8001E290;
    }
    // 0x8001E288: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_8001E28C:
    // 0x8001E28C: sw          $v0, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->r2;
L_8001E290:
    // 0x8001E290: lw          $v0, 0xB8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XB8);
    // 0x8001E294: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8001E298: andi        $v0, $v0, 0xF00
    ctx->r2 = ctx->r2 & 0XF00;
    // 0x8001E29C: beq         $v0, $zero, L_8001E2A8
    if (ctx->r2 == 0) {
        // 0x8001E2A0: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_8001E2A8;
    }
    // 0x8001E2A0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8001E2A4: sw          $v0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r2;
L_8001E2A8:
    // 0x8001E2A8: lw          $v0, 0x48($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X48);
    // 0x8001E2AC: beq         $v0, $zero, L_8001E2C0
    if (ctx->r2 == 0) {
        // 0x8001E2B0: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8001E2C0;
    }
    // 0x8001E2B0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001E2B4: bne         $v0, $zero, L_8001E2C0
    if (ctx->r2 != 0) {
        // 0x8001E2B8: sw          $v0, 0x48($a0)
        MEM_W(0X48, ctx->r4) = ctx->r2;
            goto L_8001E2C0;
    }
    // 0x8001E2B8: sw          $v0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r2;
    // 0x8001E2BC: sw          $zero, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = 0;
L_8001E2C0:
    // 0x8001E2C0: lw          $v1, 0x4C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4C);
    // 0x8001E2C4: andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // 0x8001E2C8: bne         $v0, $zero, L_8001E2F0
    if (ctx->r2 != 0) {
        // 0x8001E2CC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001E2F0;
    }
    // 0x8001E2CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001E2D0: andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // 0x8001E2D4: bne         $v0, $zero, L_8001E2F0
    if (ctx->r2 != 0) {
        // 0x8001E2D8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8001E2F0;
    }
    // 0x8001E2D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001E2DC: andi        $v0, $v1, 0x200
    ctx->r2 = ctx->r3 & 0X200;
    // 0x8001E2E0: bne         $v0, $zero, L_8001E2F0
    if (ctx->r2 != 0) {
        // 0x8001E2E4: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8001E2F0;
    }
    // 0x8001E2E4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001E2E8: srl         $v0, $v1, 6
    ctx->r2 = S32(U32(ctx->r3) >> 6);
    // 0x8001E2EC: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
L_8001E2F0:
    // 0x8001E2F0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001E2F4: addiu       $v1, $v1, 0x1838
    ctx->r3 = ADD32(ctx->r3, 0X1838);
    // 0x8001E2F8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8001E2FC: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // 0x8001E300: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8001E304: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8001E308: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8001E30C: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
    // 0x8001E310: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8001E314: sh          $v0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r2;
    // 0x8001E318: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x8001E31C: lw          $v1, 0x50($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X50);
    // 0x8001E320: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x8001E324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001E328: bne         $v1, $v0, L_8001E338
    if (ctx->r3 != ctx->r2) {
        // 0x8001E32C: sh          $a2, 0x4($a0)
        MEM_H(0X4, ctx->r4) = ctx->r6;
            goto L_8001E338;
    }
    // 0x8001E32C: sh          $a2, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r6;
    // 0x8001E330: addiu       $v0, $a2, 0x2B0
    ctx->r2 = ADD32(ctx->r6, 0X2B0);
    // 0x8001E334: sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
L_8001E338:
    // 0x8001E338: lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X6);
    // 0x8001E33C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001E340: jr          $ra
    // 0x8001E344: sh          $v0, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r2;
    return;
    // 0x8001E344: sh          $v0, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_8001E348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E348: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x8001E34C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001E350: bne         $v0, $zero, L_8001E360
    if (ctx->r2 != 0) {
        // 0x8001E354: addiu       $v1, $v1, 0x25A0
        ctx->r3 = ADD32(ctx->r3, 0X25A0);
            goto L_8001E360;
    }
    // 0x8001E354: addiu       $v1, $v1, 0x25A0
    ctx->r3 = ADD32(ctx->r3, 0X25A0);
    // 0x8001E358: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001E35C: addiu       $v1, $v1, 0x79F0
    ctx->r3 = ADD32(ctx->r3, 0X79F0);
L_8001E360:
    // 0x8001E360: lw          $v0, 0xB8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XB8);
    // 0x8001E364: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8001E368: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x8001E36C: beq         $v0, $zero, L_8001E378
    if (ctx->r2 == 0) {
        // 0x8001E370: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_8001E378;
    }
    // 0x8001E370: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8001E374: sw          $v0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r2;
L_8001E378:
    // 0x8001E378: lw          $v0, 0x48($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X48);
    // 0x8001E37C: beq         $v0, $zero, L_8001E388
    if (ctx->r2 == 0) {
        // 0x8001E380: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8001E388;
    }
    // 0x8001E380: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001E384: sw          $v0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r2;
L_8001E388:
    // 0x8001E388: lw          $v1, 0x48($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X48);
    // 0x8001E38C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E390: addiu       $v0, $v0, 0x1860
    ctx->r2 = ADD32(ctx->r2, 0X1860);
    // 0x8001E394: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x8001E398: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8001E39C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001E3A0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8001E3A4: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8001E3A8: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8001E3AC: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x8001E3B0: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8001E3B4: jr          $ra
    // 0x8001E3B8: sh          $v0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r2;
    return;
    // 0x8001E3B8: sh          $v0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_8001E3BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E3BC: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x8001E3C0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001E3C4: bne         $v0, $zero, L_8001E3D4
    if (ctx->r2 != 0) {
        // 0x8001E3C8: addiu       $v1, $v1, 0x25A0
        ctx->r3 = ADD32(ctx->r3, 0X25A0);
            goto L_8001E3D4;
    }
    // 0x8001E3C8: addiu       $v1, $v1, 0x25A0
    ctx->r3 = ADD32(ctx->r3, 0X25A0);
    // 0x8001E3CC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001E3D0: addiu       $v1, $v1, 0x79F0
    ctx->r3 = ADD32(ctx->r3, 0X79F0);
L_8001E3D4:
    // 0x8001E3D4: lw          $v0, 0xB8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XB8);
    // 0x8001E3D8: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8001E3DC: andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // 0x8001E3E0: beq         $v0, $zero, L_8001E3EC
    if (ctx->r2 == 0) {
        // 0x8001E3E4: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_8001E3EC;
    }
    // 0x8001E3E4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8001E3E8: sw          $v0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r2;
L_8001E3EC:
    // 0x8001E3EC: lw          $v0, 0x48($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X48);
    // 0x8001E3F0: beq         $v0, $zero, L_8001E3FC
    if (ctx->r2 == 0) {
        // 0x8001E3F4: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8001E3FC;
    }
    // 0x8001E3F4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001E3F8: sw          $v0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r2;
L_8001E3FC:
    // 0x8001E3FC: lw          $v1, 0x48($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X48);
    // 0x8001E400: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001E404: addiu       $v0, $v0, 0x1870
    ctx->r2 = ADD32(ctx->r2, 0X1870);
    // 0x8001E408: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x8001E40C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8001E410: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001E414: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8001E418: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8001E41C: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8001E420: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x8001E424: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8001E428: jr          $ra
    // 0x8001E42C: sh          $v0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r2;
    return;
    // 0x8001E42C: sh          $v0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_8001E430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E430: jr          $ra
    // 0x8001E434: nop

    return;
    // 0x8001E434: nop

;}
RECOMP_FUNC void func_8001E438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E438: lbu         $v0, 0x2F($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2F);
    // 0x8001E43C: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x8001E440: sb          $v0, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r2;
    // 0x8001E444: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001E448: sltiu       $v0, $v0, 0x14
    ctx->r2 = ctx->r2 < 0X14 ? 1 : 0;
    // 0x8001E44C: beq         $v0, $zero, L_8001E464
    if (ctx->r2 == 0) {
        // 0x8001E450: nop
    
            goto L_8001E464;
    }
    // 0x8001E450: nop

    // 0x8001E454: sb          $zero, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = 0;
    // 0x8001E458: sb          $zero, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = 0;
    // 0x8001E45C: sb          $zero, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = 0;
    // 0x8001E460: sb          $zero, 0x28($a0)
    MEM_B(0X28, ctx->r4) = 0;
L_8001E464:
    // 0x8001E464: jr          $ra
    // 0x8001E468: nop

    return;
    // 0x8001E468: nop

;}
RECOMP_FUNC void func_8001E46C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E46C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E470: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001E474: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001E478: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E47C: lw          $v1, 0x44($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X44);
    // 0x8001E480: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001E484: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x8001E488: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x8001E48C: srav        $v0, $v0, $v1
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r3 & 31));
    // 0x8001E490: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8001E494: beq         $v0, $zero, L_8001E4A4
    if (ctx->r2 == 0) {
        // 0x8001E498: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8001E4A4;
    }
    // 0x8001E498: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001E49C: j           L_8001E5AC
    // 0x8001E4A0: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
        goto L_8001E5AC;
    // 0x8001E4A0: sb          $zero, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = 0;
L_8001E4A4:
    // 0x8001E4A4: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001E4A8: sb          $v1, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r3;
    // 0x8001E4AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001E4B0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001E4B4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001E4B8: lw          $v0, 0x1880($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1880);
    // 0x8001E4BC: jalr        $v0
    // 0x8001E4C0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8001E4C0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8001E4C4: lwc1        $f12, 0x34($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8001E4C8: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8001E4CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001E4D0: nop

    // 0x8001E4D4: div.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8001E4D8: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8001E4DC: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8001E4E0: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001E4E4: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001E4E8: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001E4EC: div.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001E4F0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001E4F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001E4F8: nop

    // 0x8001E4FC: div.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8001E500: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001E504: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8001E508: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001E50C: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001E510: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8001E514: lwc1        $f2, 0x4C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8001E518: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8001E51C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001E520: div.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8001E524: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001E528: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8001E52C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001E530: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8001E534: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001E538: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001E53C: nop

    // 0x8001E540: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001E544: sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // 0x8001E548: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001E54C: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8001E550: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8001E554: lwc1        $f2, 0x40($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8001E558: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001E55C: sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // 0x8001E560: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8001E564: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001E568: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8001E56C: sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    // 0x8001E570: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8001E574: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001E578: nop

    // 0x8001E57C: sh          $v0, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r2;
    // 0x8001E580: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8001E584: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001E588: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001E58C: nop

    // 0x8001E590: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001E594: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x8001E598: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001E59C: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8001E5A0: nop

    // 0x8001E5A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001E5A8: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
L_8001E5AC:
    // 0x8001E5AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E5B0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001E5B4: jr          $ra
    // 0x8001E5B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001E5B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001E5BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E5BC: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8001E5C0: addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // 0x8001E5C4: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8001E5C8: addiu       $a3, $a3, 0x1A40
    ctx->r7 = ADD32(ctx->r7, 0X1A40);
    // 0x8001E5CC: lbu         $v1, 0x2B($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X2B);
    // 0x8001E5D0: or          $a0, $a2, $a3
    ctx->r4 = ctx->r6 | ctx->r7;
    // 0x8001E5D4: andi        $a0, $a0, 0x3
    ctx->r4 = ctx->r4 & 0X3;
    // 0x8001E5D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001E5DC: sb          $v0, 0x2E($a2)
    MEM_B(0X2E, ctx->r6) = ctx->r2;
    // 0x8001E5E0: sb          $v0, 0x2A($a2)
    MEM_B(0X2A, ctx->r6) = ctx->r2;
    // 0x8001E5E4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001E5E8: addiu       $v0, $v0, -0x2338
    ctx->r2 = ADD32(ctx->r2, -0X2338);
    // 0x8001E5EC: sb          $zero, 0x2C($a2)
    MEM_B(0X2C, ctx->r6) = 0;
    // 0x8001E5F0: sw          $v0, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->r2;
    // 0x8001E5F4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001E5F8: beq         $a0, $zero, L_8001E658
    if (ctx->r4 == 0) {
        // 0x8001E5FC: sb          $v1, 0x2B($a2)
        MEM_B(0X2B, ctx->r6) = ctx->r3;
            goto L_8001E658;
    }
    // 0x8001E5FC: sb          $v1, 0x2B($a2)
    MEM_B(0X2B, ctx->r6) = ctx->r3;
    // 0x8001E600: addiu       $t1, $a3, 0x20
    ctx->r9 = ADD32(ctx->r7, 0X20);
L_8001E604:
    // 0x8001E604: lwl         $v0, 0x0($a3)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r7, 0X0);
    // 0x8001E608: lwr         $v0, 0x3($a3)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r7, 0X3);
    // 0x8001E60C: lwl         $v1, 0x4($a3)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r7, 0X4);
    // 0x8001E610: lwr         $v1, 0x7($a3)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r7, 0X7);
    // 0x8001E614: lwl         $a0, 0x8($a3)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r7, 0X8);
    // 0x8001E618: lwr         $a0, 0xB($a3)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r7, 0XB);
    // 0x8001E61C: lwl         $a1, 0xC($a3)
    ctx->r5 = do_lwl(rdram, ctx->r5, ctx->r7, 0XC);
    // 0x8001E620: lwr         $a1, 0xF($a3)
    ctx->r5 = do_lwr(rdram, ctx->r5, ctx->r7, 0XF);
    // 0x8001E624: swl         $v0, 0x0($t0)
    do_swl(rdram, 0X0, ctx->r8, ctx->r2);
    // 0x8001E628: swr         $v0, 0x3($t0)
    do_swr(rdram, 0X3, ctx->r8, ctx->r2);
    // 0x8001E62C: swl         $v1, 0x4($t0)
    do_swl(rdram, 0X4, ctx->r8, ctx->r3);
    // 0x8001E630: swr         $v1, 0x7($t0)
    do_swr(rdram, 0X7, ctx->r8, ctx->r3);
    // 0x8001E634: swl         $a0, 0x8($t0)
    do_swl(rdram, 0X8, ctx->r8, ctx->r4);
    // 0x8001E638: swr         $a0, 0xB($t0)
    do_swr(rdram, 0XB, ctx->r8, ctx->r4);
    // 0x8001E63C: swl         $a1, 0xC($t0)
    do_swl(rdram, 0XC, ctx->r8, ctx->r5);
    // 0x8001E640: swr         $a1, 0xF($t0)
    do_swr(rdram, 0XF, ctx->r8, ctx->r5);
    // 0x8001E644: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001E648: bne         $a3, $t1, L_8001E604
    if (ctx->r7 != ctx->r9) {
        // 0x8001E64C: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_8001E604;
    }
    // 0x8001E64C: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8001E650: j           L_8001E688
    // 0x8001E654: nop

        goto L_8001E688;
    // 0x8001E654: nop

L_8001E658:
    // 0x8001E658: addiu       $t1, $a3, 0x20
    ctx->r9 = ADD32(ctx->r7, 0X20);
L_8001E65C:
    // 0x8001E65C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8001E660: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x8001E664: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    // 0x8001E668: lw          $a1, 0xC($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC);
    // 0x8001E66C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8001E670: sw          $v1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r3;
    // 0x8001E674: sw          $a0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r4;
    // 0x8001E678: sw          $a1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r5;
    // 0x8001E67C: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001E680: bne         $a3, $t1, L_8001E65C
    if (ctx->r7 != ctx->r9) {
        // 0x8001E684: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_8001E65C;
    }
    // 0x8001E684: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
L_8001E688:
    // 0x8001E688: lwl         $v0, 0x0($a3)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r7, 0X0);
    // 0x8001E68C: lwr         $v0, 0x3($a3)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r7, 0X3);
    // 0x8001E690: lwl         $v1, 0x4($a3)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r7, 0X4);
    // 0x8001E694: lwr         $v1, 0x7($a3)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r7, 0X7);
    // 0x8001E698: swl         $v0, 0x0($t0)
    do_swl(rdram, 0X0, ctx->r8, ctx->r2);
    // 0x8001E69C: swr         $v0, 0x3($t0)
    do_swr(rdram, 0X3, ctx->r8, ctx->r2);
    // 0x8001E6A0: swl         $v1, 0x4($t0)
    do_swl(rdram, 0X4, ctx->r8, ctx->r3);
    // 0x8001E6A4: swr         $v1, 0x7($t0)
    do_swr(rdram, 0X7, ctx->r8, ctx->r3);
    // 0x8001E6A8: lw          $v1, 0x44($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X44);
    // 0x8001E6AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001E6B0: bne         $v1, $v0, L_8001E6C4
    if (ctx->r3 != ctx->r2) {
        // 0x8001E6B4: nop
    
            goto L_8001E6C4;
    }
    // 0x8001E6B4: nop

    // 0x8001E6B8: lhu         $v0, 0x4($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X4);
    // 0x8001E6BC: addiu       $v0, $v0, 0x2B0
    ctx->r2 = ADD32(ctx->r2, 0X2B0);
    // 0x8001E6C0: sh          $v0, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r2;
L_8001E6C4:
    // 0x8001E6C4: lhu         $v1, 0x2($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X2);
    // 0x8001E6C8: lhu         $a1, 0xA($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0XA);
    // 0x8001E6CC: lhu         $a0, 0x4($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X4);
    // 0x8001E6D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001E6D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001E6D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001E6DC: sb          $v0, 0x2A($a2)
    MEM_B(0X2A, ctx->r6) = ctx->r2;
    // 0x8001E6E0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001E6E4: sb          $v0, 0x2D($a2)
    MEM_B(0X2D, ctx->r6) = ctx->r2;
    // 0x8001E6E8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8001E6EC: addiu       $v0, $v0, 0x2010
    ctx->r2 = ADD32(ctx->r2, 0X2010);
    // 0x8001E6F0: sw          $v0, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->r2;
    // 0x8001E6F4: srl         $v1, $v1, 2
    ctx->r3 = S32(U32(ctx->r3) >> 2);
    // 0x8001E6F8: srl         $a1, $a1, 2
    ctx->r5 = S32(U32(ctx->r5) >> 2);
    // 0x8001E6FC: sw          $v1, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->r3;
    // 0x8001E700: lw          $v1, 0x4C($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4C);
    // 0x8001E704: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8001E708: sra         $a0, $a0, 18
    ctx->r4 = S32(SIGNED(ctx->r4) >> 18);
    // 0x8001E70C: sw          $a1, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->r5;
    // 0x8001E710: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // 0x8001E714: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001E718: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8001E71C: lhu         $v0, 0xC($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0XC);
    // 0x8001E720: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8001E724: lw          $v1, 0x50($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X50);
    // 0x8001E728: sb          $zero, 0x2F($a2)
    MEM_B(0X2F, ctx->r6) = 0;
    // 0x8001E72C: swc1        $f0, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->f0.u32l;
    // 0x8001E730: swc1        $f0, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->f0.u32l;
    // 0x8001E734: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x8001E738: nop

    // 0x8001E73C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001E740: swc1        $f0, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f0.u32l;
    // 0x8001E744: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001E748: sra         $v0, $v0, 18
    ctx->r2 = S32(SIGNED(ctx->r2) >> 18);
    // 0x8001E74C: srl         $a0, $v1, 31
    ctx->r4 = S32(U32(ctx->r3) >> 31);
    // 0x8001E750: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8001E754: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8001E758: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001E75C: addiu       $v0, $v0, -0x50
    ctx->r2 = ADD32(ctx->r2, -0X50);
    // 0x8001E760: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8001E764: nop

    // 0x8001E768: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001E76C: jr          $ra
    // 0x8001E770: swc1        $f0, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f0.u32l;
    return;
    // 0x8001E770: swc1        $f0, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_8001E774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E774: lwc1        $f0, 0x40($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8001E778: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001E77C: ldc1        $f2, -0x2CC8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2CC8);
    // 0x8001E780: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001E784: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8001E788: lui         $at, 0x4318
    ctx->r1 = S32(0X4318 << 16);
    // 0x8001E78C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001E790: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001E794: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8001E798: nop

    // 0x8001E79C: nop

    // 0x8001E7A0: bc1f        L_8001E7B8
    if (!c1cs) {
        // 0x8001E7A4: swc1        $f0, 0x40($a0)
        MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
            goto L_8001E7B8;
    }
    // 0x8001E7A4: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x8001E7A8: lbu         $v0, 0x2B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2B);
    // 0x8001E7AC: swc1        $f2, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f2.u32l;
    // 0x8001E7B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E7B4: sb          $v0, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r2;
L_8001E7B8:
    // 0x8001E7B8: lbu         $v1, 0x2F($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X2F);
    // 0x8001E7BC: sltiu       $v0, $v1, 0xF0
    ctx->r2 = ctx->r3 < 0XF0 ? 1 : 0;
    // 0x8001E7C0: bne         $v0, $zero, L_8001E7CC
    if (ctx->r2 != 0) {
        // 0x8001E7C4: addiu       $v0, $v1, 0x28
        ctx->r2 = ADD32(ctx->r3, 0X28);
            goto L_8001E7CC;
    }
    // 0x8001E7C4: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x8001E7C8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8001E7CC:
    // 0x8001E7CC: jr          $ra
    // 0x8001E7D0: sb          $v0, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r2;
    return;
    // 0x8001E7D0: sb          $v0, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_8001E7D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E7D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001E7D8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001E7DC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001E7E0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8001E7E4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8001E7E8: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x8001E7EC: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x8001E7F0: bne         $v0, $zero, L_8001E800
    if (ctx->r2 != 0) {
        // 0x8001E7F4: addiu       $s1, $s1, 0x79F0
        ctx->r17 = ADD32(ctx->r17, 0X79F0);
            goto L_8001E800;
    }
    // 0x8001E7F4: addiu       $s1, $s1, 0x79F0
    ctx->r17 = ADD32(ctx->r17, 0X79F0);
    // 0x8001E7F8: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x8001E7FC: addiu       $s1, $s1, 0x25A0
    ctx->r17 = ADD32(ctx->r17, 0X25A0);
L_8001E800:
    // 0x8001E800: lbu         $a0, 0x2C($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X2C);
    // 0x8001E804: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8001E808: beq         $v1, $zero, L_8001E820
    if (ctx->r3 == 0) {
        // 0x8001E80C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001E820;
    }
    // 0x8001E80C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001E810: beq         $v1, $v0, L_8001E840
    if (ctx->r3 == ctx->r2) {
        // 0x8001E814: nop
    
            goto L_8001E840;
    }
    // 0x8001E814: nop

    // 0x8001E818: j           L_8001E87C
    // 0x8001E81C: nop

        goto L_8001E87C;
    // 0x8001E81C: nop

L_8001E820:
    // 0x8001E820: lb          $v0, 0x49($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X49);
    // 0x8001E824: bne         $v0, $zero, L_8001E838
    if (ctx->r2 != 0) {
        // 0x8001E828: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8001E838;
    }
    // 0x8001E828: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8001E82C: lb          $v0, 0x1($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X1);
    // 0x8001E830: bne         $v0, $zero, L_8001E87C
    if (ctx->r2 != 0) {
        // 0x8001E834: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8001E87C;
    }
    // 0x8001E834: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
L_8001E838:
    // 0x8001E838: j           L_8001E87C
    // 0x8001E83C: sb          $v0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r2;
        goto L_8001E87C;
    // 0x8001E83C: sb          $v0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r2;
L_8001E840:
    // 0x8001E840: jal         0x800152D4
    // 0x8001E844: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800152D4(rdram, ctx);
        goto after_0;
    // 0x8001E844: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x8001E848: slti        $v0, $v0, 0x7
    ctx->r2 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x8001E84C: beq         $v0, $zero, L_8001E860
    if (ctx->r2 == 0) {
        // 0x8001E850: nop
    
            goto L_8001E860;
    }
    // 0x8001E850: nop

    // 0x8001E854: lb          $v0, 0x1($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X1);
    // 0x8001E858: bne         $v0, $zero, L_8001E87C
    if (ctx->r2 != 0) {
        // 0x8001E85C: nop
    
            goto L_8001E87C;
    }
    // 0x8001E85C: nop

L_8001E860:
    // 0x8001E860: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001E864: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x8001E868: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001E86C: sb          $zero, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = 0;
    // 0x8001E870: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E874: jal         0x8000637C
    // 0x8001E878: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    func_8000637C(rdram, ctx);
        goto after_1;
    // 0x8001E878: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    after_1:
L_8001E87C:
    // 0x8001E87C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8001E880: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8001E884: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001E888: jr          $ra
    // 0x8001E88C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001E88C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8001E890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E894: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8001E898: lbu         $v1, 0x2C($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X2C);
    // 0x8001E89C: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x8001E8A0: beq         $v0, $zero, L_8001EB00
    if (ctx->r2 == 0) {
        // 0x8001E8A4: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8001EB00;
    }
    // 0x8001E8A4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001E8A8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001E8AC: addu        $at, $at, $v0
    gpr jr_addend_8001E8B4 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001E8B0: lw          $v0, -0x2CC0($at)
    ctx->r2 = ADD32(ctx->r1, -0X2CC0);
    // 0x8001E8B4: jr          $v0
    // 0x8001E8B8: nop

    switch (jr_addend_8001E8B4 >> 2) {
        case 0: goto L_8001E8BC; break;
        case 1: goto L_8001E8D0; break;
        case 2: goto L_8001E968; break;
        case 3: goto L_8001E9F4; break;
        case 4: goto L_8001EA94; break;
        default: switch_error(__func__, 0x8001E8B4, 0x800AD340);
    }
    // 0x8001E8B8: nop

L_8001E8BC:
    // 0x8001E8BC: lbu         $v0, 0x2C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2C);
    // 0x8001E8C0: sw          $zero, 0x44($a0)
    MEM_W(0X44, ctx->r4) = 0;
    // 0x8001E8C4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E8C8: j           L_8001EB00
    // 0x8001E8CC: sb          $v0, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r2;
        goto L_8001EB00;
    // 0x8001E8CC: sb          $v0, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r2;
L_8001E8D0:
    // 0x8001E8D0: lwc1        $f0, 0x44($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8001E8D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001E8D8: ldc1        $f2, -0x2CA8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2CA8);
    // 0x8001E8DC: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001E8E0: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8001E8E4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001E8E8: ldc1        $f4, -0x2CA0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2CA0);
    // 0x8001E8EC: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001E8F0: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8001E8F4: c.le.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d <= ctx->f2.d;
    // 0x8001E8F8: nop

    // 0x8001E8FC: nop

    // 0x8001E900: bc1f        L_8001E918
    if (!c1cs) {
        // 0x8001E904: swc1        $f0, 0x44($a0)
        MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
            goto L_8001E918;
    }
    // 0x8001E904: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x8001E908: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001E90C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001E910: nop

    // 0x8001E914: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
L_8001E918:
    // 0x8001E918: lwc1        $f0, 0x40($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8001E91C: lwc1        $f2, 0x44($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8001E920: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001E924: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8001E928: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001E92C: nop

    // 0x8001E930: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8001E934: nop

    // 0x8001E938: nop

    // 0x8001E93C: bc1f        L_8001EB00
    if (!c1cs) {
        // 0x8001E940: swc1        $f0, 0x40($a0)
        MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
            goto L_8001EB00;
    }
    // 0x8001E940: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x8001E944: lbu         $v0, 0x2C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2C);
    // 0x8001E948: lw          $a1, 0x44($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X44);
    // 0x8001E94C: swc1        $f2, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f2.u32l;
    // 0x8001E950: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E954: sb          $v0, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r2;
    // 0x8001E958: jal         0x8000637C
    // 0x8001E95C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8000637C(rdram, ctx);
        goto after_0;
    // 0x8001E95C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8001E960: j           L_8001EB00
    // 0x8001E964: nop

        goto L_8001EB00;
    // 0x8001E964: nop

L_8001E968:
    // 0x8001E968: lwc1        $f0, 0x38($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8001E96C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001E970: ldc1        $f2, -0x2C98($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2C98);
    // 0x8001E974: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001E978: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8001E97C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001E980: ldc1        $f4, -0x2C90($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2C90);
    // 0x8001E984: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001E988: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8001E98C: c.le.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d <= ctx->f4.d;
    // 0x8001E990: nop

    // 0x8001E994: nop

    // 0x8001E998: bc1f        L_8001E9B8
    if (!c1cs) {
        // 0x8001E99C: swc1        $f0, 0x38($a0)
        MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
            goto L_8001E9B8;
    }
    // 0x8001E99C: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x8001E9A0: lbu         $v0, 0x2C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2C);
    // 0x8001E9A4: lwc1        $f0, 0x44($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8001E9A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E9AC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8001E9B0: sb          $v0, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r2;
    // 0x8001E9B4: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
L_8001E9B8:
    // 0x8001E9B8: lwc1        $f2, 0x38($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8001E9BC: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8001E9C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001E9C4: nop

    // 0x8001E9C8: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001E9CC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001E9D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001E9D4: nop

    // 0x8001E9D8: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001E9DC: lui         $at, 0x4358
    ctx->r1 = S32(0X4358 << 16);
    // 0x8001E9E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001E9E4: nop

    // 0x8001E9E8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8001E9EC: j           L_8001EB00
    // 0x8001E9F0: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
        goto L_8001EB00;
    // 0x8001E9F0: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
L_8001E9F4:
    // 0x8001E9F4: lwc1        $f0, 0x38($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8001E9F8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001E9FC: ldc1        $f2, -0x2C88($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2C88);
    // 0x8001EA00: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001EA04: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8001EA08: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001EA0C: ldc1        $f4, -0x2C80($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2C80);
    // 0x8001EA10: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001EA14: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8001EA18: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x8001EA1C: nop

    // 0x8001EA20: nop

    // 0x8001EA24: bc1f        L_8001EA3C
    if (!c1cs) {
        // 0x8001EA28: swc1        $f0, 0x38($a0)
        MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
            goto L_8001EA3C;
    }
    // 0x8001EA28: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x8001EA2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001EA30: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001EA34: nop

    // 0x8001EA38: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
L_8001EA3C:
    // 0x8001EA3C: lwc1        $f0, 0x44($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8001EA40: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001EA44: ldc1        $f2, -0x2C78($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2C78);
    // 0x8001EA48: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001EA4C: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8001EA50: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001EA54: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8001EA58: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001EA5C: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8001EA60: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x8001EA64: nop

    // 0x8001EA68: nop

    // 0x8001EA6C: bc1f        L_8001EA80
    if (!c1cs) {
        // 0x8001EA70: swc1        $f0, 0x44($a0)
        MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
            goto L_8001EA80;
    }
    // 0x8001EA70: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x8001EA74: lbu         $v0, 0x2C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2C);
    // 0x8001EA78: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001EA7C: sb          $v0, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r2;
L_8001EA80:
    // 0x8001EA80: lwc1        $f0, 0x40($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8001EA84: lwc1        $f2, 0x44($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8001EA88: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001EA8C: j           L_8001EB00
    // 0x8001EA90: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
        goto L_8001EB00;
    // 0x8001EA90: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
L_8001EA94:
    // 0x8001EA94: lwc1        $f0, 0x44($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8001EA98: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001EA9C: ldc1        $f2, -0x2C70($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2C70);
    // 0x8001EAA0: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001EAA4: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8001EAA8: lwc1        $f2, 0x40($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8001EAAC: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001EAB0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8001EAB4: lbu         $v0, 0x2F($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2F);
    // 0x8001EAB8: swc1        $f2, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f2.u32l;
    // 0x8001EABC: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8001EAC0: lui         $at, 0x4350
    ctx->r1 = S32(0X4350 << 16);
    // 0x8001EAC4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001EAC8: addiu       $v0, $v0, -0x14
    ctx->r2 = ADD32(ctx->r2, -0X14);
    // 0x8001EACC: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x8001EAD0: sb          $v0, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r2;
    // 0x8001EAD4: nop

    // 0x8001EAD8: bc1t        L_8001EAF0
    if (c1cs) {
        // 0x8001EADC: swc1        $f0, 0x44($a0)
        MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
            goto L_8001EAF0;
    }
    // 0x8001EADC: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
    // 0x8001EAE0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001EAE4: sltiu       $v0, $v0, 0x1E
    ctx->r2 = ctx->r2 < 0X1E ? 1 : 0;
    // 0x8001EAE8: beq         $v0, $zero, L_8001EB00
    if (ctx->r2 == 0) {
        // 0x8001EAEC: nop
    
            goto L_8001EB00;
    }
    // 0x8001EAEC: nop

L_8001EAF0:
    // 0x8001EAF0: sb          $zero, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = 0;
    // 0x8001EAF4: sb          $zero, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = 0;
    // 0x8001EAF8: sb          $zero, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = 0;
    // 0x8001EAFC: sb          $zero, 0x28($a0)
    MEM_B(0X28, ctx->r4) = 0;
L_8001EB00:
    // 0x8001EB00: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8001EB04: jr          $ra
    // 0x8001EB08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001EB08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001EB0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EB0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001EB10: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001EB14: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001EB18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001EB1C: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001EB20: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001EB24: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001EB28: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001EB2C: lw          $v0, 0x1890($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1890);
    // 0x8001EB30: jalr        $v0
    // 0x8001EB34: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8001EB34: nop

    after_0:
    // 0x8001EB38: lwc1        $f12, 0x34($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8001EB3C: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8001EB40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001EB44: nop

    // 0x8001EB48: div.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8001EB4C: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8001EB50: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8001EB54: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001EB58: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001EB5C: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001EB60: div.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001EB64: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001EB68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001EB6C: nop

    // 0x8001EB70: div.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8001EB74: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001EB78: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8001EB7C: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001EB80: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8001EB84: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8001EB88: lwc1        $f2, 0x4C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8001EB8C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8001EB90: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001EB94: div.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8001EB98: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001EB9C: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8001EBA0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001EBA4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8001EBA8: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001EBAC: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001EBB0: nop

    // 0x8001EBB4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001EBB8: sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // 0x8001EBBC: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001EBC0: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8001EBC4: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8001EBC8: lwc1        $f2, 0x40($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8001EBCC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001EBD0: sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // 0x8001EBD4: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8001EBD8: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001EBDC: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8001EBE0: sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    // 0x8001EBE4: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8001EBE8: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001EBEC: nop

    // 0x8001EBF0: sh          $v0, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r2;
    // 0x8001EBF4: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8001EBF8: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001EBFC: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001EC00: nop

    // 0x8001EC04: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001EC08: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x8001EC0C: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001EC10: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8001EC14: nop

    // 0x8001EC18: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001EC1C: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // 0x8001EC20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001EC24: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001EC28: jr          $ra
    // 0x8001EC2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001EC2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001EC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EC30: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8001EC34: addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // 0x8001EC38: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8001EC3C: addiu       $a3, $a3, 0x1A68
    ctx->r7 = ADD32(ctx->r7, 0X1A68);
    // 0x8001EC40: lbu         $v1, 0x2B($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X2B);
    // 0x8001EC44: or          $a0, $a2, $a3
    ctx->r4 = ctx->r6 | ctx->r7;
    // 0x8001EC48: andi        $a0, $a0, 0x3
    ctx->r4 = ctx->r4 & 0X3;
    // 0x8001EC4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001EC50: sb          $v0, 0x2E($a2)
    MEM_B(0X2E, ctx->r6) = ctx->r2;
    // 0x8001EC54: sb          $v0, 0x2A($a2)
    MEM_B(0X2A, ctx->r6) = ctx->r2;
    // 0x8001EC58: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001EC5C: addiu       $v0, $v0, -0x2338
    ctx->r2 = ADD32(ctx->r2, -0X2338);
    // 0x8001EC60: sb          $zero, 0x2C($a2)
    MEM_B(0X2C, ctx->r6) = 0;
    // 0x8001EC64: sw          $v0, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->r2;
    // 0x8001EC68: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001EC6C: beq         $a0, $zero, L_8001ECCC
    if (ctx->r4 == 0) {
        // 0x8001EC70: sb          $v1, 0x2B($a2)
        MEM_B(0X2B, ctx->r6) = ctx->r3;
            goto L_8001ECCC;
    }
    // 0x8001EC70: sb          $v1, 0x2B($a2)
    MEM_B(0X2B, ctx->r6) = ctx->r3;
    // 0x8001EC74: addiu       $t1, $a3, 0x20
    ctx->r9 = ADD32(ctx->r7, 0X20);
L_8001EC78:
    // 0x8001EC78: lwl         $v0, 0x0($a3)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r7, 0X0);
    // 0x8001EC7C: lwr         $v0, 0x3($a3)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r7, 0X3);
    // 0x8001EC80: lwl         $v1, 0x4($a3)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r7, 0X4);
    // 0x8001EC84: lwr         $v1, 0x7($a3)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r7, 0X7);
    // 0x8001EC88: lwl         $a0, 0x8($a3)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r7, 0X8);
    // 0x8001EC8C: lwr         $a0, 0xB($a3)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r7, 0XB);
    // 0x8001EC90: lwl         $a1, 0xC($a3)
    ctx->r5 = do_lwl(rdram, ctx->r5, ctx->r7, 0XC);
    // 0x8001EC94: lwr         $a1, 0xF($a3)
    ctx->r5 = do_lwr(rdram, ctx->r5, ctx->r7, 0XF);
    // 0x8001EC98: swl         $v0, 0x0($t0)
    do_swl(rdram, 0X0, ctx->r8, ctx->r2);
    // 0x8001EC9C: swr         $v0, 0x3($t0)
    do_swr(rdram, 0X3, ctx->r8, ctx->r2);
    // 0x8001ECA0: swl         $v1, 0x4($t0)
    do_swl(rdram, 0X4, ctx->r8, ctx->r3);
    // 0x8001ECA4: swr         $v1, 0x7($t0)
    do_swr(rdram, 0X7, ctx->r8, ctx->r3);
    // 0x8001ECA8: swl         $a0, 0x8($t0)
    do_swl(rdram, 0X8, ctx->r8, ctx->r4);
    // 0x8001ECAC: swr         $a0, 0xB($t0)
    do_swr(rdram, 0XB, ctx->r8, ctx->r4);
    // 0x8001ECB0: swl         $a1, 0xC($t0)
    do_swl(rdram, 0XC, ctx->r8, ctx->r5);
    // 0x8001ECB4: swr         $a1, 0xF($t0)
    do_swr(rdram, 0XF, ctx->r8, ctx->r5);
    // 0x8001ECB8: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001ECBC: bne         $a3, $t1, L_8001EC78
    if (ctx->r7 != ctx->r9) {
        // 0x8001ECC0: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_8001EC78;
    }
    // 0x8001ECC0: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8001ECC4: j           L_8001ECFC
    // 0x8001ECC8: nop

        goto L_8001ECFC;
    // 0x8001ECC8: nop

L_8001ECCC:
    // 0x8001ECCC: addiu       $t1, $a3, 0x20
    ctx->r9 = ADD32(ctx->r7, 0X20);
L_8001ECD0:
    // 0x8001ECD0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8001ECD4: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x8001ECD8: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    // 0x8001ECDC: lw          $a1, 0xC($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC);
    // 0x8001ECE0: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8001ECE4: sw          $v1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r3;
    // 0x8001ECE8: sw          $a0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r4;
    // 0x8001ECEC: sw          $a1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r5;
    // 0x8001ECF0: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8001ECF4: bne         $a3, $t1, L_8001ECD0
    if (ctx->r7 != ctx->r9) {
        // 0x8001ECF8: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_8001ECD0;
    }
    // 0x8001ECF8: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
L_8001ECFC:
    // 0x8001ECFC: lwl         $v0, 0x0($a3)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r7, 0X0);
    // 0x8001ED00: lwr         $v0, 0x3($a3)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r7, 0X3);
    // 0x8001ED04: lwl         $v1, 0x4($a3)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r7, 0X4);
    // 0x8001ED08: lwr         $v1, 0x7($a3)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r7, 0X7);
    // 0x8001ED0C: swl         $v0, 0x0($t0)
    do_swl(rdram, 0X0, ctx->r8, ctx->r2);
    // 0x8001ED10: swr         $v0, 0x3($t0)
    do_swr(rdram, 0X3, ctx->r8, ctx->r2);
    // 0x8001ED14: swl         $v1, 0x4($t0)
    do_swl(rdram, 0X4, ctx->r8, ctx->r3);
    // 0x8001ED18: swr         $v1, 0x7($t0)
    do_swr(rdram, 0X7, ctx->r8, ctx->r3);
    // 0x8001ED1C: lw          $a1, 0x44($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X44);
    // 0x8001ED20: lhu         $v1, 0xA($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0XA);
    // 0x8001ED24: lhu         $a0, 0x4($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X4);
    // 0x8001ED28: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8001ED2C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001ED30: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001ED34: sb          $v0, 0x2A($a2)
    MEM_B(0X2A, ctx->r6) = ctx->r2;
    // 0x8001ED38: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001ED3C: sb          $v0, 0x2D($a2)
    MEM_B(0X2D, ctx->r6) = ctx->r2;
    // 0x8001ED40: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8001ED44: addiu       $v0, $v0, -0xCA0
    ctx->r2 = ADD32(ctx->r2, -0XCA0);
    // 0x8001ED48: sw          $v0, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->r2;
    // 0x8001ED4C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8001ED50: sb          $zero, 0x2F($a2)
    MEM_B(0X2F, ctx->r6) = 0;
    // 0x8001ED54: sw          $v0, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->r2;
    // 0x8001ED58: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x8001ED5C: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8001ED60: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8001ED64: srl         $v1, $v1, 2
    ctx->r3 = S32(U32(ctx->r3) >> 2);
    // 0x8001ED68: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x8001ED6C: lw          $v0, 0x4C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4C);
    // 0x8001ED70: lw          $a1, 0x44($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X44);
    // 0x8001ED74: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8001ED78: sra         $a0, $a0, 18
    ctx->r4 = S32(SIGNED(ctx->r4) >> 18);
    // 0x8001ED7C: sw          $v1, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->r3;
    // 0x8001ED80: swc1        $f2, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->f2.u32l;
    // 0x8001ED84: swc1        $f2, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->f2.u32l;
    // 0x8001ED88: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x8001ED8C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001ED90: lw          $v1, 0x44($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X44);
    // 0x8001ED94: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8001ED98: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8001ED9C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x8001EDA0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8001EDA4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8001EDA8: lhu         $v1, 0xC($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0XC);
    // 0x8001EDAC: lw          $v0, 0x50($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X50);
    // 0x8001EDB0: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x8001EDB4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001EDB8: sw          $a1, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->r5;
    // 0x8001EDBC: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x8001EDC0: nop

    // 0x8001EDC4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001EDC8: swc1        $f0, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f0.u32l;
    // 0x8001EDCC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8001EDD0: sra         $v1, $v1, 18
    ctx->r3 = S32(SIGNED(ctx->r3) >> 18);
    // 0x8001EDD4: srl         $a0, $v0, 31
    ctx->r4 = S32(U32(ctx->r2) >> 31);
    // 0x8001EDD8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001EDDC: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8001EDE0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001EDE4: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8001EDE8: nop

    // 0x8001EDEC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001EDF0: jr          $ra
    // 0x8001EDF4: swc1        $f0, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f0.u32l;
    return;
    // 0x8001EDF4: swc1        $f0, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_8001EDF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EDF8: lbu         $v1, 0x2C($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X2C);
    // 0x8001EDFC: beq         $v1, $zero, L_8001EE14
    if (ctx->r3 == 0) {
        // 0x8001EE00: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001EE14;
    }
    // 0x8001EE00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001EE04: beq         $v1, $v0, L_8001EE34
    if (ctx->r3 == ctx->r2) {
        // 0x8001EE08: nop
    
            goto L_8001EE34;
    }
    // 0x8001EE08: nop

    // 0x8001EE0C: j           L_8001EEA4
    // 0x8001EE10: nop

        goto L_8001EEA4;
    // 0x8001EE10: nop

L_8001EE14:
    // 0x8001EE14: lw          $v0, 0x54($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X54);
    // 0x8001EE18: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001EE1C: bne         $v0, $zero, L_8001EEA4
    if (ctx->r2 != 0) {
        // 0x8001EE20: sw          $v0, 0x54($a0)
        MEM_W(0X54, ctx->r4) = ctx->r2;
            goto L_8001EEA4;
    }
    // 0x8001EE20: sw          $v0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r2;
    // 0x8001EE24: lbu         $v0, 0x2C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2C);
    // 0x8001EE28: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001EE2C: j           L_8001EEA4
    // 0x8001EE30: sb          $v0, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r2;
        goto L_8001EEA4;
    // 0x8001EE30: sb          $v0, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r2;
L_8001EE34:
    // 0x8001EE34: lbu         $v1, 0x2F($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X2F);
    // 0x8001EE38: sltiu       $v0, $v1, 0xB4
    ctx->r2 = ctx->r3 < 0XB4 ? 1 : 0;
    // 0x8001EE3C: bne         $v0, $zero, L_8001EE48
    if (ctx->r2 != 0) {
        // 0x8001EE40: addiu       $v0, $v1, 0xA
        ctx->r2 = ADD32(ctx->r3, 0XA);
            goto L_8001EE48;
    }
    // 0x8001EE40: addiu       $v0, $v1, 0xA
    ctx->r2 = ADD32(ctx->r3, 0XA);
    // 0x8001EE44: addiu       $v0, $zero, 0xB4
    ctx->r2 = ADD32(0, 0XB4);
L_8001EE48:
    // 0x8001EE48: sb          $v0, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r2;
    // 0x8001EE4C: lwc1        $f0, 0x38($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8001EE50: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001EE54: ldc1        $f2, -0x2C68($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2C68);
    // 0x8001EE58: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001EE5C: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8001EE60: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001EE64: ldc1        $f4, -0x2C60($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2C60);
    // 0x8001EE68: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001EE6C: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8001EE70: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x8001EE74: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x8001EE78: nop

    // 0x8001EE7C: bc1f        L_8001EEA4
    if (!c1cs) {
        // 0x8001EE80: swc1        $f0, 0x34($a0)
        MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
            goto L_8001EEA4;
    }
    // 0x8001EE80: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x8001EE84: lbu         $v0, 0x2B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2B);
    // 0x8001EE88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001EE8C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001EE90: sb          $zero, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = 0;
    // 0x8001EE94: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001EE98: sb          $v0, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r2;
    // 0x8001EE9C: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x8001EEA0: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
L_8001EEA4:
    // 0x8001EEA4: jr          $ra
    // 0x8001EEA8: nop

    return;
    // 0x8001EEA8: nop

;}
RECOMP_FUNC void func_8001EEAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EEAC: lwc1        $f0, 0x38($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8001EEB0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001EEB4: ldc1        $f2, -0x2C58($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2C58);
    // 0x8001EEB8: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001EEBC: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8001EEC0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001EEC4: ldc1        $f4, -0x2C50($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2C50);
    // 0x8001EEC8: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001EECC: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8001EED0: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x8001EED4: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x8001EED8: nop

    // 0x8001EEDC: bc1f        L_8001EF00
    if (!c1cs) {
        // 0x8001EEE0: swc1        $f0, 0x34($a0)
        MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
            goto L_8001EF00;
    }
    // 0x8001EEE0: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x8001EEE4: lbu         $v0, 0x2B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2B);
    // 0x8001EEE8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001EEEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001EEF0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001EEF4: sb          $v0, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r2;
    // 0x8001EEF8: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x8001EEFC: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
L_8001EF00:
    // 0x8001EF00: jr          $ra
    // 0x8001EF04: nop

    return;
    // 0x8001EF04: nop

;}
RECOMP_FUNC void func_8001EF08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EF08: lwc1        $f0, 0x38($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8001EF0C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001EF10: ldc1        $f2, -0x2C48($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2C48);
    // 0x8001EF14: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001EF18: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8001EF1C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001EF20: ldc1        $f4, -0x2C40($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2C40);
    // 0x8001EF24: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001EF28: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8001EF2C: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x8001EF30: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x8001EF34: nop

    // 0x8001EF38: bc1f        L_8001EF9C
    if (!c1cs) {
        // 0x8001EF3C: swc1        $f0, 0x34($a0)
        MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
            goto L_8001EF9C;
    }
    // 0x8001EF3C: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x8001EF40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001EF44: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001EF48: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x8001EF4C: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x8001EF50: bne         $v0, $zero, L_8001EF70
    if (ctx->r2 != 0) {
        // 0x8001EF54: swc1        $f0, 0x34($a0)
        MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
            goto L_8001EF70;
    }
    // 0x8001EF54: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x8001EF58: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001EF5C: lbu         $v0, 0x7B87($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B87);
    // 0x8001EF60: bne         $v0, $zero, L_8001EF70
    if (ctx->r2 != 0) {
        // 0x8001EF64: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001EF70;
    }
    // 0x8001EF64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001EF68: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001EF6C: sb          $v0, 0x7B95($at)
    MEM_B(0X7B95, ctx->r1) = ctx->r2;
L_8001EF70:
    // 0x8001EF70: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001EF74: lbu         $v1, 0x7B95($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B95);
    // 0x8001EF78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001EF7C: bne         $v1, $v0, L_8001EF90
    if (ctx->r3 != ctx->r2) {
        // 0x8001EF80: nop
    
            goto L_8001EF90;
    }
    // 0x8001EF80: nop

    // 0x8001EF84: lbu         $v0, 0x2B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2B);
    // 0x8001EF88: j           L_8001EF98
    // 0x8001EF8C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8001EF98;
    // 0x8001EF8C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001EF90:
    // 0x8001EF90: lbu         $v0, 0x2B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2B);
    // 0x8001EF94: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8001EF98:
    // 0x8001EF98: sb          $v0, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r2;
L_8001EF9C:
    // 0x8001EF9C: jr          $ra
    // 0x8001EFA0: nop

    return;
    // 0x8001EFA0: nop

;}
RECOMP_FUNC void func_8001EFA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EFA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001EFA8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8001EFAC: lwc1        $f0, 0x38($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8001EFB0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001EFB4: ldc1        $f2, -0x2C38($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2C38);
    // 0x8001EFB8: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8001EFBC: lbu         $v1, 0x2F($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X2F);
    // 0x8001EFC0: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001EFC4: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8001EFC8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001EFCC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001EFD0: sltiu       $v0, $v1, 0x1F
    ctx->r2 = ctx->r3 < 0X1F ? 1 : 0;
    // 0x8001EFD4: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8001EFD8: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001EFDC: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x8001EFE0: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x8001EFE4: bne         $v0, $zero, L_8001EFF8
    if (ctx->r2 != 0) {
        // 0x8001EFE8: swc1        $f4, 0x3C($a0)
        MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
            goto L_8001EFF8;
    }
    // 0x8001EFE8: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x8001EFEC: addiu       $v0, $v1, -0xA
    ctx->r2 = ADD32(ctx->r3, -0XA);
    // 0x8001EFF0: j           L_8001F07C
    // 0x8001EFF4: sb          $v0, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r2;
        goto L_8001F07C;
    // 0x8001EFF4: sb          $v0, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r2;
L_8001EFF8:
    // 0x8001EFF8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001EFFC: ldc1        $f0, -0x2C30($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2C30);
    // 0x8001F000: lwc1        $f2, 0x44($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8001F004: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x8001F008: mul.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f0.d);
    // 0x8001F00C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001F010: ldc1        $f4, -0x2C28($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2C28);
    // 0x8001F014: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x8001F018: sw          $v0, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r2;
    // 0x8001F01C: lbu         $v0, 0x2B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2B);
    // 0x8001F020: lwc1        $f0, 0x58($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8001F024: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x8001F028: mul.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x8001F02C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001F030: ldc1        $f4, -0x2C20($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2C20);
    // 0x8001F034: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001F038: ldc1        $f8, -0x2C18($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2C18);
    // 0x8001F03C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001F040: ldc1        $f6, -0x2C10($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2C10);
    // 0x8001F044: add.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d + ctx->f4.d;
    // 0x8001F048: sb          $zero, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = 0;
    // 0x8001F04C: add.d       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = ctx->f0.d + ctx->f6.d;
    // 0x8001F050: sb          $zero, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = 0;
    // 0x8001F054: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001F058: sb          $v0, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r2;
    // 0x8001F05C: sub.d       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = ctx->f2.d - ctx->f8.d;
    // 0x8001F060: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001F064: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x8001F068: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x8001F06C: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8001F070: swc1        $f2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f2.u32l;
    // 0x8001F074: jal         0x8001F45C
    // 0x8001F078: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_8001F45C(rdram, ctx);
        goto after_0;
    // 0x8001F078: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
L_8001F07C:
    // 0x8001F07C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8001F080: jr          $ra
    // 0x8001F084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001F084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001F088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001F08C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001F090: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001F094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001F098: lbu         $v1, 0x2C($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2C);
    // 0x8001F09C: beq         $v1, $zero, L_8001F0B4
    if (ctx->r3 == 0) {
        // 0x8001F0A0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001F0B4;
    }
    // 0x8001F0A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001F0A4: beq         $v1, $v0, L_8001F15C
    if (ctx->r3 == ctx->r2) {
        // 0x8001F0A8: nop
    
            goto L_8001F15C;
    }
    // 0x8001F0A8: nop

    // 0x8001F0AC: j           L_8001F1A8
    // 0x8001F0B0: nop

        goto L_8001F1A8;
    // 0x8001F0B0: nop

L_8001F0B4:
    // 0x8001F0B4: lbu         $v1, 0x2F($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2F);
    // 0x8001F0B8: sltiu       $v0, $v1, 0xB4
    ctx->r2 = ctx->r3 < 0XB4 ? 1 : 0;
    // 0x8001F0BC: bne         $v0, $zero, L_8001F0C8
    if (ctx->r2 != 0) {
        // 0x8001F0C0: addiu       $v0, $v1, 0x28
        ctx->r2 = ADD32(ctx->r3, 0X28);
            goto L_8001F0C8;
    }
    // 0x8001F0C0: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x8001F0C4: addiu       $v0, $zero, 0xB4
    ctx->r2 = ADD32(0, 0XB4);
L_8001F0C8:
    // 0x8001F0C8: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x8001F0CC: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001F0D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001F0D4: ldc1        $f2, -0x2C08($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2C08);
    // 0x8001F0D8: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001F0DC: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8001F0E0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001F0E4: ldc1        $f4, -0x2C00($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2C00);
    // 0x8001F0E8: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001F0EC: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8001F0F0: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x8001F0F4: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x8001F0F8: nop

    // 0x8001F0FC: bc1f        L_8001F128
    if (!c1cs) {
        // 0x8001F100: swc1        $f0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
            goto L_8001F128;
    }
    // 0x8001F100: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x8001F104: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001F108: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001F10C: lw          $v1, 0x44($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X44);
    // 0x8001F110: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8001F114: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x8001F118: bne         $v1, $v0, L_8001F128
    if (ctx->r3 != ctx->r2) {
        // 0x8001F11C: swc1        $f0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
            goto L_8001F128;
    }
    // 0x8001F11C: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x8001F120: jal         0x800064C0
    // 0x8001F124: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    func_800064C0(rdram, ctx);
        goto after_0;
    // 0x8001F124: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    after_0:
L_8001F128:
    // 0x8001F128: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8001F12C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001F130: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001F134: lw          $v0, 0x58($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X58);
    // 0x8001F138: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001F13C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001F140: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x8001F144: bne         $v0, $zero, L_8001F1A8
    if (ctx->r2 != 0) {
        // 0x8001F148: swc1        $f0, 0x3C($s0)
        MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
            goto L_8001F1A8;
    }
    // 0x8001F148: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x8001F14C: lbu         $v0, 0x2C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2C);
    // 0x8001F150: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001F154: j           L_8001F1A8
    // 0x8001F158: sb          $v0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r2;
        goto L_8001F1A8;
    // 0x8001F158: sb          $v0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r2;
L_8001F15C:
    // 0x8001F15C: lbu         $v0, 0x2F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2F);
    // 0x8001F160: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // 0x8001F164: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x8001F168: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001F16C: sltiu       $v0, $v0, 0xF0
    ctx->r2 = ctx->r2 < 0XF0 ? 1 : 0;
    // 0x8001F170: bne         $v0, $zero, L_8001F1A8
    if (ctx->r2 != 0) {
        // 0x8001F174: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8001F1A8;
    }
    // 0x8001F174: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8001F178: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001F17C: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x8001F180: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x8001F184: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8001F188: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x8001F18C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8001F190: sb          $zero, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = 0;
    // 0x8001F194: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001F198: bne         $a0, $v0, L_8001F1A8
    if (ctx->r4 != ctx->r2) {
        // 0x8001F19C: sb          $v1, 0x2B($s0)
        MEM_B(0X2B, ctx->r16) = ctx->r3;
            goto L_8001F1A8;
    }
    // 0x8001F19C: sb          $v1, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r3;
    // 0x8001F1A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001F1A4: sb          $zero, 0x7B95($at)
    MEM_B(0X7B95, ctx->r1) = 0;
L_8001F1A8:
    // 0x8001F1A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F1AC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001F1B0: jr          $ra
    // 0x8001F1B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001F1B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001F1B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F1B8: lw          $v0, 0x58($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X58);
    // 0x8001F1BC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001F1C0: bne         $v0, $zero, L_8001F1D4
    if (ctx->r2 != 0) {
        // 0x8001F1C4: sw          $v0, 0x58($a0)
        MEM_W(0X58, ctx->r4) = ctx->r2;
            goto L_8001F1D4;
    }
    // 0x8001F1C4: sw          $v0, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r2;
    // 0x8001F1C8: lbu         $v0, 0x2B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2B);
    // 0x8001F1CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001F1D0: sb          $v0, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r2;
L_8001F1D4:
    // 0x8001F1D4: jr          $ra
    // 0x8001F1D8: nop

    return;
    // 0x8001F1D8: nop

;}
RECOMP_FUNC void func_8001F1DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F1DC: lbu         $v0, 0x2F($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2F);
    // 0x8001F1E0: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x8001F1E4: sb          $v0, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r2;
    // 0x8001F1E8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001F1EC: sltiu       $v0, $v0, 0xB
    ctx->r2 = ctx->r2 < 0XB ? 1 : 0;
    // 0x8001F1F0: beq         $v0, $zero, L_8001F208
    if (ctx->r2 == 0) {
        // 0x8001F1F4: nop
    
            goto L_8001F208;
    }
    // 0x8001F1F4: nop

    // 0x8001F1F8: sb          $zero, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = 0;
    // 0x8001F1FC: sb          $zero, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = 0;
    // 0x8001F200: sb          $zero, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = 0;
    // 0x8001F204: sb          $zero, 0x28($a0)
    MEM_B(0X28, ctx->r4) = 0;
L_8001F208:
    // 0x8001F208: jr          $ra
    // 0x8001F20C: nop

    return;
    // 0x8001F20C: nop

;}
RECOMP_FUNC void func_8001F210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F210: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x8001F214: lbu         $a0, 0x2B($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X2B);
    // 0x8001F218: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001F21C: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8001F220: beq         $v1, $v0, L_8001F454
    if (ctx->r3 == ctx->r2) {
        // 0x8001F224: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8001F454;
    }
    // 0x8001F224: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8001F228: beql        $v0, $zero, L_8001F240
    if (ctx->r2 == 0) {
        // 0x8001F22C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8001F240;
    }
    goto skip_0;
    // 0x8001F22C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8001F230: beq         $v1, $zero, L_8001F250
    if (ctx->r3 == 0) {
        // 0x8001F234: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8001F250;
    }
    // 0x8001F234: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8001F238: j           L_8001F454
    // 0x8001F23C: nop

        goto L_8001F454;
    // 0x8001F23C: nop

L_8001F240:
    // 0x8001F240: beql        $v1, $v0, L_8001F448
    if (ctx->r3 == ctx->r2) {
        // 0x8001F244: sb          $zero, 0x2C($a3)
        MEM_B(0X2C, ctx->r7) = 0;
            goto L_8001F448;
    }
    goto skip_1;
    // 0x8001F244: sb          $zero, 0x2C($a3)
    MEM_B(0X2C, ctx->r7) = 0;
    skip_1:
    // 0x8001F248: j           L_8001F454
    // 0x8001F24C: nop

        goto L_8001F454;
    // 0x8001F24C: nop

L_8001F250:
    // 0x8001F250: addu        $t0, $a3, $zero
    ctx->r8 = ADD32(ctx->r7, 0);
    // 0x8001F254: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8001F258: addiu       $a2, $a2, 0x1B30
    ctx->r6 = ADD32(ctx->r6, 0X1B30);
    // 0x8001F25C: or          $v1, $a3, $a2
    ctx->r3 = ctx->r7 | ctx->r6;
    // 0x8001F260: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x8001F264: sb          $v0, 0x2B($a3)
    MEM_B(0X2B, ctx->r7) = ctx->r2;
    // 0x8001F268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001F26C: sb          $v0, 0x2E($a3)
    MEM_B(0X2E, ctx->r7) = ctx->r2;
    // 0x8001F270: sb          $v0, 0x2A($a3)
    MEM_B(0X2A, ctx->r7) = ctx->r2;
    // 0x8001F274: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001F278: addiu       $v0, $v0, -0x2338
    ctx->r2 = ADD32(ctx->r2, -0X2338);
    // 0x8001F27C: beq         $v1, $zero, L_8001F2DC
    if (ctx->r3 == 0) {
        // 0x8001F280: sw          $v0, 0x30($a3)
        MEM_W(0X30, ctx->r7) = ctx->r2;
            goto L_8001F2DC;
    }
    // 0x8001F280: sw          $v0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r2;
    // 0x8001F284: addiu       $t1, $a2, 0x20
    ctx->r9 = ADD32(ctx->r6, 0X20);
L_8001F288:
    // 0x8001F288: lwl         $v0, 0x0($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r6, 0X0);
    // 0x8001F28C: lwr         $v0, 0x3($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r6, 0X3);
    // 0x8001F290: lwl         $v1, 0x4($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r6, 0X4);
    // 0x8001F294: lwr         $v1, 0x7($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r6, 0X7);
    // 0x8001F298: lwl         $a0, 0x8($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r6, 0X8);
    // 0x8001F29C: lwr         $a0, 0xB($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r6, 0XB);
    // 0x8001F2A0: lwl         $a1, 0xC($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, ctx->r6, 0XC);
    // 0x8001F2A4: lwr         $a1, 0xF($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, ctx->r6, 0XF);
    // 0x8001F2A8: swl         $v0, 0x0($t0)
    do_swl(rdram, 0X0, ctx->r8, ctx->r2);
    // 0x8001F2AC: swr         $v0, 0x3($t0)
    do_swr(rdram, 0X3, ctx->r8, ctx->r2);
    // 0x8001F2B0: swl         $v1, 0x4($t0)
    do_swl(rdram, 0X4, ctx->r8, ctx->r3);
    // 0x8001F2B4: swr         $v1, 0x7($t0)
    do_swr(rdram, 0X7, ctx->r8, ctx->r3);
    // 0x8001F2B8: swl         $a0, 0x8($t0)
    do_swl(rdram, 0X8, ctx->r8, ctx->r4);
    // 0x8001F2BC: swr         $a0, 0xB($t0)
    do_swr(rdram, 0XB, ctx->r8, ctx->r4);
    // 0x8001F2C0: swl         $a1, 0xC($t0)
    do_swl(rdram, 0XC, ctx->r8, ctx->r5);
    // 0x8001F2C4: swr         $a1, 0xF($t0)
    do_swr(rdram, 0XF, ctx->r8, ctx->r5);
    // 0x8001F2C8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001F2CC: bne         $a2, $t1, L_8001F288
    if (ctx->r6 != ctx->r9) {
        // 0x8001F2D0: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_8001F288;
    }
    // 0x8001F2D0: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8001F2D4: j           L_8001F30C
    // 0x8001F2D8: nop

        goto L_8001F30C;
    // 0x8001F2D8: nop

L_8001F2DC:
    // 0x8001F2DC: addiu       $t1, $a2, 0x20
    ctx->r9 = ADD32(ctx->r6, 0X20);
L_8001F2E0:
    // 0x8001F2E0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001F2E4: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x8001F2E8: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001F2EC: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8001F2F0: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8001F2F4: sw          $v1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r3;
    // 0x8001F2F8: sw          $a0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r4;
    // 0x8001F2FC: sw          $a1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r5;
    // 0x8001F300: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001F304: bne         $a2, $t1, L_8001F2E0
    if (ctx->r6 != ctx->r9) {
        // 0x8001F308: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_8001F2E0;
    }
    // 0x8001F308: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
L_8001F30C:
    // 0x8001F30C: lwl         $v0, 0x0($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r6, 0X0);
    // 0x8001F310: lwr         $v0, 0x3($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r6, 0X3);
    // 0x8001F314: lwl         $v1, 0x4($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r6, 0X4);
    // 0x8001F318: lwr         $v1, 0x7($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r6, 0X7);
    // 0x8001F31C: swl         $v0, 0x0($t0)
    do_swl(rdram, 0X0, ctx->r8, ctx->r2);
    // 0x8001F320: swr         $v0, 0x3($t0)
    do_swr(rdram, 0X3, ctx->r8, ctx->r2);
    // 0x8001F324: swl         $v1, 0x4($t0)
    do_swl(rdram, 0X4, ctx->r8, ctx->r3);
    // 0x8001F328: swr         $v1, 0x7($t0)
    do_swr(rdram, 0X7, ctx->r8, ctx->r3);
    // 0x8001F32C: lw          $v1, 0x44($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X44);
    // 0x8001F330: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001F334: addiu       $v0, $zero, 0xB9
    ctx->r2 = ADD32(0, 0XB9);
    // 0x8001F338: sb          $v0, 0x2F($a3)
    MEM_B(0X2F, ctx->r7) = ctx->r2;
    // 0x8001F33C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8001F340: addiu       $v0, $v0, 0x2440
    ctx->r2 = ADD32(ctx->r2, 0X2440);
    // 0x8001F344: sb          $a0, 0x2A($a3)
    MEM_B(0X2A, ctx->r7) = ctx->r4;
    // 0x8001F348: sb          $zero, 0x2D($a3)
    MEM_B(0X2D, ctx->r7) = 0;
    // 0x8001F34C: bne         $v1, $zero, L_8001F390
    if (ctx->r3 != 0) {
        // 0x8001F350: sw          $v0, 0x30($a3)
        MEM_W(0X30, ctx->r7) = ctx->r2;
            goto L_8001F390;
    }
    // 0x8001F350: sw          $v0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r2;
    // 0x8001F354: addiu       $v0, $v0, -0x800
    ctx->r2 = ADD32(ctx->r2, -0X800);
    // 0x8001F358: sw          $v0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r2;
    // 0x8001F35C: addiu       $v0, $zero, 0x248
    ctx->r2 = ADD32(0, 0X248);
    // 0x8001F360: sh          $v0, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r2;
    // 0x8001F364: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001F368: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x8001F36C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001F370: lb          $v1, 0x25FA($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X25FA);
    // 0x8001F374: srl         $a1, $v0, 4
    ctx->r5 = S32(U32(ctx->r2) >> 4);
    // 0x8001F378: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001F37C: bne         $v1, $v0, L_8001F3D4
    if (ctx->r3 != ctx->r2) {
        // 0x8001F380: addiu       $v0, $zero, 0x370
        ctx->r2 = ADD32(0, 0X370);
            goto L_8001F3D4;
    }
    // 0x8001F380: addiu       $v0, $zero, 0x370
    ctx->r2 = ADD32(0, 0X370);
    // 0x8001F384: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001F388: j           L_8001F3C8
    // 0x8001F38C: lb          $v0, 0x25A5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A5);
        goto L_8001F3C8;
    // 0x8001F38C: lb          $v0, 0x25A5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A5);
L_8001F390:
    // 0x8001F390: addiu       $v0, $v0, -0x400
    ctx->r2 = ADD32(ctx->r2, -0X400);
    // 0x8001F394: sw          $v0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r2;
    // 0x8001F398: addiu       $v0, $zero, 0x2B8
    ctx->r2 = ADD32(0, 0X2B8);
    // 0x8001F39C: sh          $v0, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r2;
    // 0x8001F3A0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001F3A4: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x8001F3A8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001F3AC: lb          $v1, 0x7A4A($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X7A4A);
    // 0x8001F3B0: andi        $a1, $v0, 0xF
    ctx->r5 = ctx->r2 & 0XF;
    // 0x8001F3B4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001F3B8: bne         $v1, $v0, L_8001F3D4
    if (ctx->r3 != ctx->r2) {
        // 0x8001F3BC: addiu       $v0, $zero, 0x370
        ctx->r2 = ADD32(0, 0X370);
            goto L_8001F3D4;
    }
    // 0x8001F3BC: addiu       $v0, $zero, 0x370
    ctx->r2 = ADD32(0, 0X370);
    // 0x8001F3C0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001F3C4: lb          $v0, 0x79F5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F5);
L_8001F3C8:
    // 0x8001F3C8: bltzl       $v0, L_8001F3D0
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001F3CC: sb          $a0, 0x2B($a3)
        MEM_B(0X2B, ctx->r7) = ctx->r4;
            goto L_8001F3D0;
    }
    goto skip_2;
    // 0x8001F3CC: sb          $a0, 0x2B($a3)
    MEM_B(0X2B, ctx->r7) = ctx->r4;
    skip_2:
L_8001F3D0:
    // 0x8001F3D0: addiu       $v0, $zero, 0x370
    ctx->r2 = ADD32(0, 0X370);
L_8001F3D4:
    // 0x8001F3D4: sh          $v0, 0xC($a3)
    MEM_H(0XC, ctx->r7) = ctx->r2;
    // 0x8001F3D8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001F3DC: addiu       $v0, $v0, -0x38CC
    ctx->r2 = ADD32(ctx->r2, -0X38CC);
    // 0x8001F3E0: sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5 << 1);
    // 0x8001F3E4: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x8001F3E8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8001F3EC: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8001F3F0: lhu         $v1, 0x4($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X4);
    // 0x8001F3F4: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8001F3F8: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8001F3FC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001F400: sh          $v1, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r3;
    // 0x8001F404: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x8001F408: lhu         $v1, 0xC($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0XC);
    // 0x8001F40C: lhu         $a0, 0xE($a3)
    ctx->r4 = MEM_HU(ctx->r7, 0XE);
    // 0x8001F410: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8001F414: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8001F418: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001F41C: lhu         $v0, 0x6($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X6);
    // 0x8001F420: sh          $v1, 0xC($a3)
    MEM_H(0XC, ctx->r7) = ctx->r3;
    // 0x8001F424: lhu         $v1, 0x4($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X4);
    // 0x8001F428: lhu         $a1, 0xC($a3)
    ctx->r5 = MEM_HU(ctx->r7, 0XC);
    // 0x8001F42C: srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // 0x8001F430: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x8001F434: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8001F438: subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    // 0x8001F43C: sh          $v1, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r3;
    // 0x8001F440: j           L_8001F454
    // 0x8001F444: sh          $a1, 0xC($a3)
    MEM_H(0XC, ctx->r7) = ctx->r5;
        goto L_8001F454;
    // 0x8001F444: sh          $a1, 0xC($a3)
    MEM_H(0XC, ctx->r7) = ctx->r5;
L_8001F448:
    // 0x8001F448: sb          $zero, 0x2B($a3)
    MEM_B(0X2B, ctx->r7) = 0;
    // 0x8001F44C: sb          $zero, 0x2E($a3)
    MEM_B(0X2E, ctx->r7) = 0;
    // 0x8001F450: sb          $zero, 0x28($a3)
    MEM_B(0X28, ctx->r7) = 0;
L_8001F454:
    // 0x8001F454: jr          $ra
    // 0x8001F458: nop

    return;
    // 0x8001F458: nop

;}
RECOMP_FUNC void func_8001F45C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F45C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001F460: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001F464: sll         $s0, $a0, 1
    ctx->r16 = S32(ctx->r4 << 1);
    // 0x8001F468: addu        $s0, $s0, $a0
    ctx->r16 = ADD32(ctx->r16, ctx->r4);
    // 0x8001F46C: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x8001F470: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001F474: addiu       $v0, $v0, -0x45B0
    ctx->r2 = ADD32(ctx->r2, -0X45B0);
    // 0x8001F478: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8001F47C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001F480: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8001F484: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x8001F488: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001F48C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001F490: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001F494: lw          $v0, -0x6740($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6740);
    // 0x8001F498: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8001F49C: lui         $a0, 0x12
    ctx->r4 = S32(0X12 << 16);
    // 0x8001F4A0: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    // 0x8001F4A4: jal         0x80006D98
    // 0x8001F4A8: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_80006D98(rdram, ctx);
        goto after_0;
    // 0x8001F4A8: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_0:
    // 0x8001F4AC: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x8001F4B0: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x8001F4B4: lbu         $a2, 0x2($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X2);
    // 0x8001F4B8: lui         $a0, 0x13
    ctx->r4 = S32(0X13 << 16);
    // 0x8001F4BC: addiu       $a0, $a0, -0x380
    ctx->r4 = ADD32(ctx->r4, -0X380);
    // 0x8001F4C0: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8001F4C4: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x8001F4C8: jal         0x80006D98
    // 0x8001F4CC: sll         $a2, $a2, 5
    ctx->r6 = S32(ctx->r6 << 5);
    func_80006D98(rdram, ctx);
        goto after_1;
    // 0x8001F4CC: sll         $a2, $a2, 5
    ctx->r6 = S32(ctx->r6 << 5);
    after_1:
    // 0x8001F4D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F4D4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001F4D8: jr          $ra
    // 0x8001F4DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001F4DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001F4E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F4E0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8001F4E4: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x8001F4E8: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8001F4EC: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x8001F4F0: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x8001F4F4: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x8001F4F8: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x8001F4FC: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x8001F500: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x8001F504: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x8001F508: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x8001F50C: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8001F510: lb          $v0, 0x122($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X122);
    // 0x8001F514: bne         $v0, $zero, L_8001F5FC
    if (ctx->r2 != 0) {
        // 0x8001F518: addu        $s7, $zero, $zero
        ctx->r23 = ADD32(0, 0);
            goto L_8001F5FC;
    }
    // 0x8001F518: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // 0x8001F51C: lbu         $s7, 0x4C($s2)
    ctx->r23 = MEM_BU(ctx->r18, 0X4C);
    // 0x8001F520: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // 0x8001F524: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x8001F528: addiu       $fp, $zero, 0xB
    ctx->r30 = ADD32(0, 0XB);
    // 0x8001F52C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001F530: sb          $v0, 0x122($s2)
    MEM_B(0X122, ctx->r18) = ctx->r2;
    // 0x8001F534: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8001F538: sb          $v0, 0x11F($s2)
    MEM_B(0X11F, ctx->r18) = ctx->r2;
L_8001F53C:
    // 0x8001F53C: jal         0x8001F9A8
    // 0x8001F540: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001F9A8(rdram, ctx);
        goto after_0;
    // 0x8001F540: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_0:
    // 0x8001F544: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8001F548: jal         0x8001FA18
    // 0x8001F54C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001FA18(rdram, ctx);
        goto after_1;
    // 0x8001F54C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_1:
    // 0x8001F550: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8001F554: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8001F558: jal         0x8001F810
    // 0x8001F55C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_8001F810(rdram, ctx);
        goto after_2;
    // 0x8001F55C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x8001F560: subu        $v0, $fp, $s3
    ctx->r2 = SUB32(ctx->r30, ctx->r19);
    // 0x8001F564: blez        $v0, L_8001F5D8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F568: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8001F5D8;
    }
    // 0x8001F568: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8001F56C: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8001F570: subu        $s4, $v0, $s3
    ctx->r20 = SUB32(ctx->r2, ctx->r19);
    // 0x8001F574: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_8001F578:
    // 0x8001F578: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8001F57C: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8001F580: jal         0x8001F8B4
    // 0x8001F584: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    func_8001F8B4(rdram, ctx);
        goto after_3;
    // 0x8001F584: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x8001F588: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8001F58C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8001F590: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8001F594: lui         $a3, 0x8002
    ctx->r7 = S32(0X8002 << 16);
    // 0x8001F598: addiu       $a3, $a3, -0x804
    ctx->r7 = ADD32(ctx->r7, -0X804);
    // 0x8001F59C: jal         0x8001F778
    // 0x8001F5A0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_8001F778(rdram, ctx);
        goto after_4;
    // 0x8001F5A0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_4:
    // 0x8001F5A4: beql        $v0, $zero, L_8001F5CC
    if (ctx->r2 == 0) {
        // 0x8001F5A8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8001F5CC;
    }
    goto skip_0;
    // 0x8001F5A8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8001F5AC: slt         $v0, $s0, $s6
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8001F5B0: bnel        $v0, $zero, L_8001F5CC
    if (ctx->r2 != 0) {
        // 0x8001F5B4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8001F5CC;
    }
    goto skip_1;
    // 0x8001F5B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x8001F5B8: lbu         $v0, 0x4C($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X4C);
    // 0x8001F5BC: addu        $s6, $s0, $zero
    ctx->r22 = ADD32(ctx->r16, 0);
    // 0x8001F5C0: sb          $s1, 0x120($s2)
    MEM_B(0X120, ctx->r18) = ctx->r17;
    // 0x8001F5C4: sb          $v0, 0x11F($s2)
    MEM_B(0X11F, ctx->r18) = ctx->r2;
    // 0x8001F5C8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8001F5CC:
    // 0x8001F5CC: slt         $v0, $s1, $s4
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8001F5D0: bne         $v0, $zero, L_8001F578
    if (ctx->r2 != 0) {
        // 0x8001F5D4: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_8001F578;
    }
    // 0x8001F5D4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_8001F5D8:
    // 0x8001F5D8: lbu         $v0, 0x4C($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X4C);
    // 0x8001F5DC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8001F5E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001F5E4: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8001F5E8: sb          $v0, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = ctx->r2;
    // 0x8001F5EC: slti        $v0, $s5, 0x4
    ctx->r2 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x8001F5F0: bne         $v0, $zero, L_8001F53C
    if (ctx->r2 != 0) {
        // 0x8001F5F4: nop
    
            goto L_8001F53C;
    }
    // 0x8001F5F4: nop

    // 0x8001F5F8: sb          $s7, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = ctx->r23;
L_8001F5FC:
    // 0x8001F5FC: lb          $a0, 0x11F($s2)
    ctx->r4 = MEM_B(ctx->r18, 0X11F);
    // 0x8001F600: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8001F604: beq         $a0, $v0, L_8001F6B0
    if (ctx->r4 == ctx->r2) {
        // 0x8001F608: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_8001F6B0;
    }
    // 0x8001F608: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8001F60C: lb          $v0, 0x4C($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X4C);
    // 0x8001F610: beq         $a0, $v0, L_8001F624
    if (ctx->r4 == ctx->r2) {
        // 0x8001F614: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8001F624;
    }
    // 0x8001F614: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8001F618: lhu         $v0, 0x82($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X82);
    // 0x8001F61C: j           L_8001F730
    // 0x8001F620: sw          $v0, 0x114($s2)
    MEM_W(0X114, ctx->r18) = ctx->r2;
        goto L_8001F730;
    // 0x8001F620: sw          $v0, 0x114($s2)
    MEM_W(0X114, ctx->r18) = ctx->r2;
L_8001F624:
    // 0x8001F624: addu        $s7, $v1, $zero
    ctx->r23 = ADD32(ctx->r3, 0);
    // 0x8001F628: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8001F62C: jal         0x8001F9A8
    // 0x8001F630: sb          $a1, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = ctx->r5;
    func_8001F9A8(rdram, ctx);
        goto after_5;
    // 0x8001F630: sb          $a1, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = ctx->r5;
    after_5:
    // 0x8001F634: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8001F638: jal         0x8001FA18
    // 0x8001F63C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001FA18(rdram, ctx);
        goto after_6;
    // 0x8001F63C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_6:
    // 0x8001F640: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8001F644: lb          $v1, 0x120($s2)
    ctx->r3 = MEM_B(ctx->r18, 0X120);
    // 0x8001F648: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8001F64C: subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // 0x8001F650: bne         $v1, $v0, L_8001F65C
    if (ctx->r3 != ctx->r2) {
        // 0x8001F654: addiu       $v0, $a0, 0x2
        ctx->r2 = ADD32(ctx->r4, 0X2);
            goto L_8001F65C;
    }
    // 0x8001F654: addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    // 0x8001F658: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
L_8001F65C:
    // 0x8001F65C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001F660: lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X18);
    // 0x8001F664: bne         $v1, $a0, L_8001F674
    if (ctx->r3 != ctx->r4) {
        // 0x8001F668: slt         $v0, $v1, $a0
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8001F674;
    }
    // 0x8001F668: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001F66C: j           L_8001F688
    // 0x8001F670: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
        goto L_8001F688;
    // 0x8001F670: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
L_8001F674:
    // 0x8001F674: bne         $v0, $zero, L_8001F688
    if (ctx->r2 != 0) {
        // 0x8001F678: addiu       $v0, $zero, 0x200
        ctx->r2 = ADD32(0, 0X200);
            goto L_8001F688;
    }
    // 0x8001F678: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x8001F67C: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F680: beq         $v0, $zero, L_8001F68C
    if (ctx->r2 == 0) {
        // 0x8001F684: addiu       $v0, $zero, 0x100
        ctx->r2 = ADD32(0, 0X100);
            goto L_8001F68C;
    }
    // 0x8001F684: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_8001F688:
    // 0x8001F688: sw          $v0, 0x114($s2)
    MEM_W(0X114, ctx->r18) = ctx->r2;
L_8001F68C:
    // 0x8001F68C: lw          $v0, 0x118($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X118);
    // 0x8001F690: andi        $v0, $v0, 0x300
    ctx->r2 = ctx->r2 & 0X300;
    // 0x8001F694: beql        $v0, $zero, L_8001F730
    if (ctx->r2 == 0) {
        // 0x8001F698: sb          $s7, 0x4C($s2)
        MEM_B(0X4C, ctx->r18) = ctx->r23;
            goto L_8001F730;
    }
    goto skip_2;
    // 0x8001F698: sb          $s7, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = ctx->r23;
    skip_2:
    // 0x8001F69C: lw          $v0, 0x114($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X114);
    // 0x8001F6A0: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
    // 0x8001F6A4: sw          $v0, 0x114($s2)
    MEM_W(0X114, ctx->r18) = ctx->r2;
    // 0x8001F6A8: j           L_8001F730
    // 0x8001F6AC: sb          $s7, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = ctx->r23;
        goto L_8001F730;
    // 0x8001F6AC: sb          $s7, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = ctx->r23;
L_8001F6B0:
    // 0x8001F6B0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8001F6B4: jal         0x8001F9A8
    // 0x8001F6B8: sb          $s7, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = ctx->r23;
    func_8001F9A8(rdram, ctx);
        goto after_7;
    // 0x8001F6B8: sb          $s7, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = ctx->r23;
    after_7:
    // 0x8001F6BC: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8001F6C0: jal         0x8001FA18
    // 0x8001F6C4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001FA18(rdram, ctx);
        goto after_8;
    // 0x8001F6C4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_8:
    // 0x8001F6C8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8001F6CC: lb          $v1, 0x120($s2)
    ctx->r3 = MEM_B(ctx->r18, 0X120);
    // 0x8001F6D0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8001F6D4: subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // 0x8001F6D8: bne         $v1, $v0, L_8001F6E4
    if (ctx->r3 != ctx->r2) {
        // 0x8001F6DC: addiu       $v0, $a0, 0x2
        ctx->r2 = ADD32(ctx->r4, 0X2);
            goto L_8001F6E4;
    }
    // 0x8001F6DC: addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    // 0x8001F6E0: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
L_8001F6E4:
    // 0x8001F6E4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001F6E8: lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X18);
    // 0x8001F6EC: bne         $v1, $a0, L_8001F6FC
    if (ctx->r3 != ctx->r4) {
        // 0x8001F6F0: slt         $v0, $v1, $a0
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8001F6FC;
    }
    // 0x8001F6F0: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001F6F4: j           L_8001F710
    // 0x8001F6F8: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
        goto L_8001F710;
    // 0x8001F6F8: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
L_8001F6FC:
    // 0x8001F6FC: bne         $v0, $zero, L_8001F710
    if (ctx->r2 != 0) {
        // 0x8001F700: addiu       $v0, $zero, 0x200
        ctx->r2 = ADD32(0, 0X200);
            goto L_8001F710;
    }
    // 0x8001F700: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x8001F704: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F708: beq         $v0, $zero, L_8001F714
    if (ctx->r2 == 0) {
        // 0x8001F70C: addiu       $v0, $zero, 0x100
        ctx->r2 = ADD32(0, 0X100);
            goto L_8001F714;
    }
    // 0x8001F70C: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_8001F710:
    // 0x8001F710: sw          $v0, 0x114($s2)
    MEM_W(0X114, ctx->r18) = ctx->r2;
L_8001F714:
    // 0x8001F714: lw          $v0, 0x118($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X118);
    // 0x8001F718: andi        $v0, $v0, 0x300
    ctx->r2 = ctx->r2 & 0X300;
    // 0x8001F71C: beq         $v0, $zero, L_8001F730
    if (ctx->r2 == 0) {
        // 0x8001F720: nop
    
            goto L_8001F730;
    }
    // 0x8001F720: nop

    // 0x8001F724: lw          $v0, 0x114($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X114);
    // 0x8001F728: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
    // 0x8001F72C: sw          $v0, 0x114($s2)
    MEM_W(0X114, ctx->r18) = ctx->r2;
L_8001F730:
    // 0x8001F730: lw          $v1, 0xB4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XB4);
    // 0x8001F734: lw          $v0, 0x114($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X114);
    // 0x8001F738: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8001F73C: lw          $v1, 0xB8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XB8);
    // 0x8001F740: lw          $v0, 0x114($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X114);
    // 0x8001F744: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8001F748: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x8001F74C: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x8001F750: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x8001F754: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x8001F758: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x8001F75C: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x8001F760: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x8001F764: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x8001F768: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x8001F76C: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8001F770: jr          $ra
    // 0x8001F774: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8001F774: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_8001F778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F778: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001F77C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001F780: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8001F784: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001F788: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x8001F78C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001F790: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8001F794: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001F798: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001F79C: blez        $s3, L_8001F7D8
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8001F7A0: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_8001F7D8;
    }
    // 0x8001F7A0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001F7A4: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8001F7A8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
L_8001F7AC:
    // 0x8001F7AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8001F7B0: jalr        $s4
    // 0x8001F7B4: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_0;
    // 0x8001F7B4: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    after_0:
    // 0x8001F7B8: beq         $v0, $zero, L_8001F7C8
    if (ctx->r2 == 0) {
        // 0x8001F7BC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8001F7C8;
    }
    // 0x8001F7BC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8001F7C0: j           L_8001F7DC
    // 0x8001F7C4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8001F7DC;
    // 0x8001F7C4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8001F7C8:
    // 0x8001F7C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001F7CC: slt         $v0, $s0, $s3
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8001F7D0: bne         $v0, $zero, L_8001F7AC
    if (ctx->r2 != 0) {
        // 0x8001F7D4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8001F7AC;
    }
    // 0x8001F7D4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8001F7D8:
    // 0x8001F7D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001F7DC:
    // 0x8001F7DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001F7E0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001F7E4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001F7E8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001F7EC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F7F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001F7F4: jr          $ra
    // 0x8001F7F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001F7F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8001F7FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F7FC: xor         $v0, $a0, $a1
    ctx->r2 = ctx->r4 ^ ctx->r5;
    // 0x8001F800: jr          $ra
    // 0x8001F804: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x8001F804: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
;}
RECOMP_FUNC void func_8001F808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F808: jr          $ra
    // 0x8001F80C: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    return;
    // 0x8001F80C: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
;}
RECOMP_FUNC void func_8001F810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F810: lb          $v1, 0x54($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X54);
    // 0x8001F814: lw          $v0, 0xDC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XDC);
    // 0x8001F818: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8001F81C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8001F820: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001F824: lb          $v0, 0x4C($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X4C);
    // 0x8001F828: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8001F82C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001F830: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001F834: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001F838: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8001F83C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_8001F840:
    // 0x8001F840: addiu       $a0, $t1, 0x14
    ctx->r4 = ADD32(ctx->r9, 0X14);
    // 0x8001F844: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x8001F848: addu        $a3, $v0, $a2
    ctx->r7 = ADD32(ctx->r2, ctx->r6);
L_8001F84C:
    // 0x8001F84C: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x8001F850: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x8001F854: beql        $v0, $zero, L_8001F868
    if (ctx->r2 == 0) {
        // 0x8001F858: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_8001F868;
    }
    goto skip_0;
    // 0x8001F858: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    skip_0:
    // 0x8001F85C: sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // 0x8001F860: j           L_8001F870
    // 0x8001F864: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
        goto L_8001F870;
    // 0x8001F864: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_8001F868:
    // 0x8001F868: bgez        $v1, L_8001F84C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8001F86C: addiu       $a0, $a0, -0x5
        ctx->r4 = ADD32(ctx->r4, -0X5);
            goto L_8001F84C;
    }
    // 0x8001F86C: addiu       $a0, $a0, -0x5
    ctx->r4 = ADD32(ctx->r4, -0X5);
L_8001F870:
    // 0x8001F870: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001F874: slti        $v0, $a1, 0x5
    ctx->r2 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x8001F878: bnel        $v0, $zero, L_8001F840
    if (ctx->r2 != 0) {
        // 0x8001F87C: addiu       $v1, $zero, 0x4
        ctx->r3 = ADD32(0, 0X4);
            goto L_8001F840;
    }
    goto skip_1;
    // 0x8001F87C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    skip_1:
    // 0x8001F880: addiu       $a1, $t0, -0x1
    ctx->r5 = ADD32(ctx->r8, -0X1);
    // 0x8001F884: blez        $a1, L_8001F8AC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8001F888: sll         $v0, $a1, 2
        ctx->r2 = S32(ctx->r5 << 2);
            goto L_8001F8AC;
    }
    // 0x8001F888: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8001F88C: addu        $a0, $v0, $a2
    ctx->r4 = ADD32(ctx->r2, ctx->r6);
L_8001F890:
    // 0x8001F890: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001F894: lw          $v1, -0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X4);
    // 0x8001F898: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8001F89C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8001F8A0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8001F8A4: bgtz        $a1, L_8001F890
    if (SIGNED(ctx->r5) > 0) {
        // 0x8001F8A8: addiu       $a0, $a0, -0x4
        ctx->r4 = ADD32(ctx->r4, -0X4);
            goto L_8001F890;
    }
    // 0x8001F8A8: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
L_8001F8AC:
    // 0x8001F8AC: jr          $ra
    // 0x8001F8B0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    return;
    // 0x8001F8B0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
;}
RECOMP_FUNC void func_8001F8B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F8B4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8001F8B8: addu        $v1, $a1, $a2
    ctx->r3 = ADD32(ctx->r5, ctx->r6);
    // 0x8001F8BC: slt         $v0, $a1, $v1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001F8C0: beq         $v0, $zero, L_8001F928
    if (ctx->r2 == 0) {
        // 0x8001F8C4: addu        $t1, $a1, $zero
        ctx->r9 = ADD32(ctx->r5, 0);
            goto L_8001F928;
    }
    // 0x8001F8C4: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // 0x8001F8C8: addiu       $t4, $zero, 0x12
    ctx->r12 = ADD32(0, 0X12);
    // 0x8001F8CC: addu        $t3, $v1, $zero
    ctx->r11 = ADD32(ctx->r3, 0);
    // 0x8001F8D0: subu        $v0, $t1, $a1
    ctx->r2 = SUB32(ctx->r9, ctx->r5);
L_8001F8D4:
    // 0x8001F8D4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001F8D8: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8001F8DC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8001F8E0: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8001F8E4: addu        $t2, $v0, $zero
    ctx->r10 = ADD32(ctx->r2, 0);
    // 0x8001F8E8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8001F8EC:
    // 0x8001F8EC: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x8001F8F0: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x8001F8F4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001F8F8: lb          $v0, 0x70($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X70);
    // 0x8001F8FC: blezl       $v0, L_8001F90C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001F900: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8001F90C;
    }
    goto skip_0;
    // 0x8001F900: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_0:
    // 0x8001F904: j           L_8001F918
    // 0x8001F908: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
        goto L_8001F918;
    // 0x8001F908: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
L_8001F90C:
    // 0x8001F90C: slti        $v0, $t0, 0x12
    ctx->r2 = SIGNED(ctx->r8) < 0X12 ? 1 : 0;
    // 0x8001F910: bne         $v0, $zero, L_8001F8EC
    if (ctx->r2 != 0) {
        // 0x8001F914: addiu       $v1, $v1, 0x12
        ctx->r3 = ADD32(ctx->r3, 0X12);
            goto L_8001F8EC;
    }
    // 0x8001F914: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
L_8001F918:
    // 0x8001F918: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001F91C: slt         $v0, $t1, $t3
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001F920: bne         $v0, $zero, L_8001F8D4
    if (ctx->r2 != 0) {
        // 0x8001F924: subu        $v0, $t1, $a1
        ctx->r2 = SUB32(ctx->r9, ctx->r5);
            goto L_8001F8D4;
    }
    // 0x8001F924: subu        $v0, $t1, $a1
    ctx->r2 = SUB32(ctx->r9, ctx->r5);
L_8001F928:
    // 0x8001F928: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8001F92C: blez        $a2, L_8001F958
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8001F930: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_8001F958;
    }
    // 0x8001F930: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8001F934: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
L_8001F938:
    // 0x8001F938: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8001F93C: slt         $v0, $v1, $t0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001F940: beql        $v0, $zero, L_8001F948
    if (ctx->r2 == 0) {
        // 0x8001F944: addu        $t0, $v1, $zero
        ctx->r8 = ADD32(ctx->r3, 0);
            goto L_8001F948;
    }
    goto skip_1;
    // 0x8001F944: addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
    skip_1:
L_8001F948:
    // 0x8001F948: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8001F94C: slt         $v0, $t1, $a2
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001F950: bne         $v0, $zero, L_8001F938
    if (ctx->r2 != 0) {
        // 0x8001F954: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8001F938;
    }
    // 0x8001F954: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_8001F958:
    // 0x8001F958: addu        $v0, $a1, $a2
    ctx->r2 = ADD32(ctx->r5, ctx->r6);
    // 0x8001F95C: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x8001F960: slt         $v0, $a1, $t1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001F964: beql        $v0, $zero, L_8001F99C
    if (ctx->r2 == 0) {
        // 0x8001F968: sw          $zero, 0x0($a3)
        MEM_W(0X0, ctx->r7) = 0;
            goto L_8001F99C;
    }
    goto skip_2;
    // 0x8001F968: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    skip_2:
    // 0x8001F96C: subu        $v0, $t1, $a1
    ctx->r2 = SUB32(ctx->r9, ctx->r5);
L_8001F970:
    // 0x8001F970: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001F974: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8001F978: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8001F97C: lw          $a0, -0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X4);
    // 0x8001F980: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x8001F984: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8001F988: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8001F98C: slt         $v0, $a1, $t1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001F990: bne         $v0, $zero, L_8001F970
    if (ctx->r2 != 0) {
        // 0x8001F994: subu        $v0, $t1, $a1
        ctx->r2 = SUB32(ctx->r9, ctx->r5);
            goto L_8001F970;
    }
    // 0x8001F994: subu        $v0, $t1, $a1
    ctx->r2 = SUB32(ctx->r9, ctx->r5);
    // 0x8001F998: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_8001F99C:
    // 0x8001F99C: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    // 0x8001F9A0: jr          $ra
    // 0x8001F9A4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8001F9A4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8001F9A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F9A8: lb          $v1, 0x54($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X54);
    // 0x8001F9AC: lw          $v0, 0xDC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XDC);
    // 0x8001F9B0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8001F9B4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8001F9B8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001F9BC: lb          $v0, 0x4C($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X4C);
    // 0x8001F9C0: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8001F9C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001F9C8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001F9CC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001F9D0: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x8001F9D4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8001F9D8:
    // 0x8001F9D8: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
L_8001F9DC:
    // 0x8001F9DC: addu        $v0, $v1, $a1
    ctx->r2 = ADD32(ctx->r3, ctx->r5);
    // 0x8001F9E0: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x8001F9E4: beql        $v0, $zero, L_8001F9F4
    if (ctx->r2 == 0) {
        // 0x8001F9E8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8001F9F4;
    }
    goto skip_0;
    // 0x8001F9E8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x8001F9EC: j           L_8001FA00
    // 0x8001F9F0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8001FA00;
    // 0x8001F9F0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001F9F4:
    // 0x8001F9F4: slti        $v0, $a0, 0x5
    ctx->r2 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // 0x8001F9F8: bne         $v0, $zero, L_8001F9DC
    if (ctx->r2 != 0) {
        // 0x8001F9FC: addiu       $v1, $v1, 0x5
        ctx->r3 = ADD32(ctx->r3, 0X5);
            goto L_8001F9DC;
    }
    // 0x8001F9FC: addiu       $v1, $v1, 0x5
    ctx->r3 = ADD32(ctx->r3, 0X5);
L_8001FA00:
    // 0x8001FA00: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001FA04: slti        $v0, $a1, 0x5
    ctx->r2 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x8001FA08: bnel        $v0, $zero, L_8001F9D8
    if (ctx->r2 != 0) {
        // 0x8001FA0C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8001F9D8;
    }
    goto skip_1;
    // 0x8001FA0C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_1:
    // 0x8001FA10: jr          $ra
    // 0x8001FA14: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    return;
    // 0x8001FA14: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
;}
RECOMP_FUNC void func_8001FA18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FA18: lb          $v0, 0x54($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X54);
    // 0x8001FA1C: lw          $v1, 0xDC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XDC);
    // 0x8001FA20: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001FA24: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001FA28: lb          $v1, 0x4C($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X4C);
    // 0x8001FA2C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8001FA30: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8001FA34: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8001FA38: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001FA3C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8001FA40: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8001FA44:
    // 0x8001FA44: negu        $a3, $a2
    ctx->r7 = SUB32(0, ctx->r6);
    // 0x8001FA48: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
L_8001FA4C:
    // 0x8001FA4C: addu        $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // 0x8001FA50: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x8001FA54: bne         $v0, $zero, L_8001FA80
    if (ctx->r2 != 0) {
        // 0x8001FA58: addu        $v0, $a3, $zero
        ctx->r2 = ADD32(ctx->r7, 0);
            goto L_8001FA80;
    }
    // 0x8001FA58: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // 0x8001FA5C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001FA60: slti        $v0, $a1, 0x5
    ctx->r2 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x8001FA64: bne         $v0, $zero, L_8001FA4C
    if (ctx->r2 != 0) {
        // 0x8001FA68: addiu       $a0, $a0, 0x5
        ctx->r4 = ADD32(ctx->r4, 0X5);
            goto L_8001FA4C;
    }
    // 0x8001FA68: addiu       $a0, $a0, 0x5
    ctx->r4 = ADD32(ctx->r4, 0X5);
    // 0x8001FA6C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001FA70: slti        $v0, $a2, 0x5
    ctx->r2 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
    // 0x8001FA74: bnel        $v0, $zero, L_8001FA44
    if (ctx->r2 != 0) {
        // 0x8001FA78: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8001FA44;
    }
    goto skip_0;
    // 0x8001FA78: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    skip_0:
    // 0x8001FA7C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8001FA80:
    // 0x8001FA80: jr          $ra
    // 0x8001FA84: nop

    return;
    // 0x8001FA84: nop

;}
RECOMP_FUNC void func_8001FA88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FA88: addiu       $a2, $zero, -0x6
    ctx->r6 = ADD32(0, -0X6);
    // 0x8001FA8C: addiu       $a1, $zero, -0x6C
    ctx->r5 = ADD32(0, -0X6C);
L_8001FA90:
    // 0x8001FA90: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8001FA94:
    // 0x8001FA94: lw          $v0, 0x110($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X110);
    // 0x8001FA98: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8001FA9C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001FAA0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8001FAA4: sb          $zero, 0x70($v0)
    MEM_B(0X70, ctx->r2) = 0;
    // 0x8001FAA8: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x8001FAAC: bne         $v0, $zero, L_8001FA94
    if (ctx->r2 != 0) {
        // 0x8001FAB0: nop
    
            goto L_8001FA94;
    }
    // 0x8001FAB0: nop

    // 0x8001FAB4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001FAB8: slti        $v0, $a2, 0x12
    ctx->r2 = SIGNED(ctx->r6) < 0X12 ? 1 : 0;
    // 0x8001FABC: bne         $v0, $zero, L_8001FA90
    if (ctx->r2 != 0) {
        // 0x8001FAC0: addiu       $a1, $a1, 0x12
        ctx->r5 = ADD32(ctx->r5, 0X12);
            goto L_8001FA90;
    }
    // 0x8001FAC0: addiu       $a1, $a1, 0x12
    ctx->r5 = ADD32(ctx->r5, 0X12);
    // 0x8001FAC4: jr          $ra
    // 0x8001FAC8: nop

    return;
    // 0x8001FAC8: nop

;}
RECOMP_FUNC void func_8001FAD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FAD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001FAD4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001FAD8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001FADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001FAE0: lb          $v1, 0x2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X2);
    // 0x8001FAE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001FAE8: bne         $v1, $v0, L_8001FB24
    if (ctx->r3 != ctx->r2) {
        // 0x8001FAEC: nop
    
            goto L_8001FB24;
    }
    // 0x8001FAEC: nop

    // 0x8001FAF0: lb          $v0, 0x11F($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X11F);
    // 0x8001FAF4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001FAF8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001FAFC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001FB00: lw          $v0, 0x22F0($at)
    ctx->r2 = MEM_W(ctx->r1, 0X22F0);
    // 0x8001FB04: jalr        $v0
    // 0x8001FB08: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8001FB08: nop

    after_0:
    // 0x8001FB0C: lw          $v1, 0xB4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB4);
    // 0x8001FB10: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x8001FB14: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8001FB18: lw          $v1, 0xB8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB8);
    // 0x8001FB1C: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x8001FB20: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8001FB24:
    // 0x8001FB24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001FB28: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001FB2C: jr          $ra
    // 0x8001FB30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001FB30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001FB34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FB34: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8001FB38: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8001FB3C: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x8001FB40: addiu       $t2, $t2, -0x212C
    ctx->r10 = ADD32(ctx->r10, -0X212C);
    // 0x8001FB44: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x8001FB48: addiu       $t3, $t3, -0x2120
    ctx->r11 = ADD32(ctx->r11, -0X2120);
    // 0x8001FB4C: lbu         $v1, 0x5($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X5);
    // 0x8001FB50: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8001FB54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001FB58: sb          $v0, 0x11F($a2)
    MEM_B(0X11F, ctx->r6) = ctx->r2;
    // 0x8001FB5C: andi        $t0, $v1, 0x1
    ctx->r8 = ctx->r3 & 0X1;
    // 0x8001FB60: sll         $a1, $t0, 2
    ctx->r5 = S32(ctx->r8 << 2);
    // 0x8001FB64: sll         $t1, $t0, 9
    ctx->r9 = S32(ctx->r8 << 9);
    // 0x8001FB68: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001FB6C: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x8001FB70: sw          $zero, -0x212C($at)
    MEM_W(-0X212C, ctx->r1) = 0;
    // 0x8001FB74: addu        $a0, $a1, $t2
    ctx->r4 = ADD32(ctx->r5, ctx->r10);
L_8001FB78:
    // 0x8001FB78: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8001FB7C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8001FB80: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x8001FB84: addu        $v0, $v1, $t3
    ctx->r2 = ADD32(ctx->r3, ctx->r11);
    // 0x8001FB88: sb          $a3, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r7;
    // 0x8001FB8C: sb          $a3, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r7;
    // 0x8001FB90: sb          $a3, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r7;
    // 0x8001FB94: sb          $a3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r7;
    // 0x8001FB98: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001FB9C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8001FBA0: sb          $a3, -0x2120($at)
    MEM_B(-0X2120, ctx->r1) = ctx->r7;
    // 0x8001FBA4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001FBA8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001FBAC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8001FBB0: slti        $v0, $v0, 0x40
    ctx->r2 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x8001FBB4: bne         $v0, $zero, L_8001FB78
    if (ctx->r2 != 0) {
        // 0x8001FBB8: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_8001FB78;
    }
    // 0x8001FBB8: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x8001FBBC: addu        $a0, $v1, $t2
    ctx->r4 = ADD32(ctx->r3, ctx->r10);
    // 0x8001FBC0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8001FBC4: sll         $v0, $t0, 9
    ctx->r2 = S32(ctx->r8 << 9);
    // 0x8001FBC8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8001FBCC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001FBD0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001FBD4: addiu       $v0, $v0, -0x2120
    ctx->r2 = ADD32(ctx->r2, -0X2120);
    // 0x8001FBD8: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8001FBDC: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x8001FBE0: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x8001FBE4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001FBE8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8001FBEC: sb          $zero, -0x2119($at)
    MEM_B(-0X2119, ctx->r1) = 0;
    // 0x8001FBF0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8001FBF4: lw          $a0, 0xB4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XB4);
    // 0x8001FBF8: lw          $v1, 0xB8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XB8);
    // 0x8001FBFC: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x8001FC00: sb          $v0, 0x125($a2)
    MEM_B(0X125, ctx->r6) = ctx->r2;
    // 0x8001FC04: sb          $v0, 0x124($a2)
    MEM_B(0X124, ctx->r6) = ctx->r2;
    // 0x8001FC08: sb          $v0, 0x123($a2)
    MEM_B(0X123, ctx->r6) = ctx->r2;
    // 0x8001FC0C: sb          $zero, 0x129($a2)
    MEM_B(0X129, ctx->r6) = 0;
    // 0x8001FC10: sb          $zero, 0x128($a2)
    MEM_B(0X128, ctx->r6) = 0;
    // 0x8001FC14: sb          $zero, 0x127($a2)
    MEM_B(0X127, ctx->r6) = 0;
    // 0x8001FC18: sb          $zero, 0x126($a2)
    MEM_B(0X126, ctx->r6) = 0;
    // 0x8001FC1C: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x8001FC20: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x8001FC24: sw          $zero, 0x114($a2)
    MEM_W(0X114, ctx->r6) = 0;
    // 0x8001FC28: jr          $ra
    // 0x8001FC2C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8001FC2C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8001FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FC30: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8001FC34: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x8001FC38: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8001FC3C: sw          $ra, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r31;
    // 0x8001FC40: sw          $fp, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r30;
    // 0x8001FC44: sw          $s7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r23;
    // 0x8001FC48: sw          $s6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r22;
    // 0x8001FC4C: sw          $s5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r21;
    // 0x8001FC50: sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // 0x8001FC54: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x8001FC58: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x8001FC5C: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x8001FC60: lw          $a3, 0x18($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X18);
    // 0x8001FC64: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8001FC68: lw          $a3, 0x1C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X1C);
    // 0x8001FC6C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8001FC70: lbu         $a3, 0x4C($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X4C);
    // 0x8001FC74: sb          $a3, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r7;
    // 0x8001FC78: lw          $a3, 0xB0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XB0);
    // 0x8001FC7C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8001FC80: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x8001FC84: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8001FC88: addiu       $a0, $a0, -0x212C
    ctx->r4 = ADD32(ctx->r4, -0X212C);
    // 0x8001FC8C: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8001FC90: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8001FC94: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8001FC98: sw          $zero, 0x114($s1)
    MEM_W(0X114, ctx->r17) = 0;
    // 0x8001FC9C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8001FCA0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8001FCA4: addu        $s3, $v1, $a0
    ctx->r19 = ADD32(ctx->r3, ctx->r4);
    // 0x8001FCA8: sll         $s5, $v0, 9
    ctx->r21 = S32(ctx->r2 << 9);
L_8001FCAC:
    // 0x8001FCAC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8001FCB0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001FCB4: jal         0x80020DDC
    // 0x8001FCB8: sw          $a3, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = ctx->r7;
    func_80020DDC(rdram, ctx);
        goto after_0;
    // 0x8001FCB8: sw          $a3, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = ctx->r7;
    after_0:
    // 0x8001FCBC: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x8001FCC0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001FCC4: jal         0x80020A38
    // 0x8001FCC8: sw          $v0, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = ctx->r2;
    func_80020A38(rdram, ctx);
        goto after_1;
    // 0x8001FCC8: sw          $v0, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = ctx->r2;
    after_1:
    // 0x8001FCCC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001FCD0: jal         0x80020818
    // 0x8001FCD4: addu        $fp, $v0, $zero
    ctx->r30 = ADD32(ctx->r2, 0);
    func_80020818(rdram, ctx);
        goto after_2;
    // 0x8001FCD4: addu        $fp, $v0, $zero
    ctx->r30 = ADD32(ctx->r2, 0);
    after_2:
    // 0x8001FCD8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001FCDC: jal         0x80020A8C
    // 0x8001FCE0: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    func_80020A8C(rdram, ctx);
        goto after_3;
    // 0x8001FCE0: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    after_3:
    // 0x8001FCE4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001FCE8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8001FCEC: jal         0x80016980
    // 0x8001FCF0: sb          $zero, 0x4C($s1)
    MEM_B(0X4C, ctx->r17) = 0;
    func_80016980(rdram, ctx);
        goto after_4;
    // 0x8001FCF0: sb          $zero, 0x4C($s1)
    MEM_B(0X4C, ctx->r17) = 0;
    after_4:
    // 0x8001FCF4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001FCF8: jal         0x800169C8
    // 0x8001FCFC: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    func_800169C8(rdram, ctx);
        goto after_5;
    // 0x8001FCFC: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    after_5:
    // 0x8001FD00: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001FD04: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001FD08: jal         0x80020D90
    // 0x8001FD0C: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    func_80020D90(rdram, ctx);
        goto after_6;
    // 0x8001FD0C: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    after_6:
    // 0x8001FD10: lbu         $v1, 0x11F($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X11F);
    // 0x8001FD14: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001FD18: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // 0x8001FD1C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8001FD20: jal         0x80020D90
    // 0x8001FD24: sb          $v1, 0x4C($s1)
    MEM_B(0X4C, ctx->r17) = ctx->r3;
    func_80020D90(rdram, ctx);
        goto after_7;
    // 0x8001FD24: sb          $v1, 0x4C($s1)
    MEM_B(0X4C, ctx->r17) = ctx->r3;
    after_7:
    // 0x8001FD28: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001FD2C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8001FD30: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8001FD34: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    // 0x8001FD38: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8001FD3C: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // 0x8001FD40: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001FD44: jal         0x800151FC
    // 0x8001FD48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800151FC(rdram, ctx);
        goto after_8;
    // 0x8001FD48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x8001FD4C: beq         $v0, $zero, L_8001FE88
    if (ctx->r2 == 0) {
        // 0x8001FD50: addiu       $v0, $zero, -0x3
        ctx->r2 = ADD32(0, -0X3);
            goto L_8001FE88;
    }
    // 0x8001FD50: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
    // 0x8001FD54: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x8001FD58: bne         $v1, $v0, L_8001FD78
    if (ctx->r3 != ctx->r2) {
        // 0x8001FD5C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8001FD78;
    }
    // 0x8001FD5C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001FD60: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x8001FD64: bnel        $v0, $zero, L_8001FD78
    if (ctx->r2 != 0) {
        // 0x8001FD68: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8001FD78;
    }
    goto skip_0;
    // 0x8001FD68: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_0:
    // 0x8001FD6C: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x8001FD70: j           L_8001FE6C
    // 0x8001FD74: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
        goto L_8001FE6C;
    // 0x8001FD74: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_8001FD78:
    // 0x8001FD78: bne         $v1, $v0, L_8001FD98
    if (ctx->r3 != ctx->r2) {
        // 0x8001FD7C: nop
    
            goto L_8001FD98;
    }
    // 0x8001FD7C: nop

    // 0x8001FD80: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x8001FD84: bne         $v0, $zero, L_8001FD98
    if (ctx->r2 != 0) {
        // 0x8001FD88: nop
    
            goto L_8001FD98;
    }
    // 0x8001FD88: nop

    // 0x8001FD8C: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x8001FD90: j           L_8001FE6C
    // 0x8001FD94: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
        goto L_8001FE6C;
    // 0x8001FD94: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
L_8001FD98:
    // 0x8001FD98: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x8001FD9C: bne         $v0, $zero, L_8001FDC0
    if (ctx->r2 != 0) {
        // 0x8001FDA0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8001FDC0;
    }
    // 0x8001FDA0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001FDA4: lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X14);
    // 0x8001FDA8: bne         $v1, $v0, L_8001FDC0
    if (ctx->r3 != ctx->r2) {
        // 0x8001FDAC: nop
    
            goto L_8001FDC0;
    }
    // 0x8001FDAC: nop

    // 0x8001FDB0: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    // 0x8001FDB4: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8001FDB8: j           L_8001FE70
    // 0x8001FDBC: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
        goto L_8001FE70;
    // 0x8001FDBC: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
L_8001FDC0:
    // 0x8001FDC0: lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10);
    // 0x8001FDC4: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x8001FDC8: bgez        $a0, L_8001FDD4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8001FDCC: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8001FDD4;
    }
    // 0x8001FDCC: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x8001FDD0: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_8001FDD4:
    // 0x8001FDD4: bltzl       $v0, L_8001FDDC
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001FDD8: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_8001FDDC;
    }
    goto skip_1;
    // 0x8001FDD8: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_1:
L_8001FDDC:
    // 0x8001FDDC: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001FDE0: beq         $v0, $zero, L_8001FE04
    if (ctx->r2 == 0) {
        // 0x8001FDE4: nop
    
            goto L_8001FE04;
    }
    // 0x8001FDE4: nop

    // 0x8001FDE8: blez        $a0, L_8001FDFC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8001FDEC: nop
    
            goto L_8001FDFC;
    }
    // 0x8001FDEC: nop

    // 0x8001FDF0: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x8001FDF4: j           L_8001FE6C
    // 0x8001FDF8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_8001FE6C;
    // 0x8001FDF8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8001FDFC:
    // 0x8001FDFC: bltz        $a0, L_8001FE64
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001FE00: nop
    
            goto L_8001FE64;
    }
    // 0x8001FE00: nop

L_8001FE04:
    // 0x8001FE04: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x8001FE08: lw          $a0, 0x14($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X14);
    // 0x8001FE0C: bltzl       $v1, L_8001FE14
    if (SIGNED(ctx->r3) < 0) {
        // 0x8001FE10: negu        $v1, $v1
        ctx->r3 = SUB32(0, ctx->r3);
            goto L_8001FE14;
    }
    goto skip_2;
    // 0x8001FE10: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    skip_2:
L_8001FE14:
    // 0x8001FE14: bgez        $a0, L_8001FE20
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8001FE18: addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
            goto L_8001FE20;
    }
    // 0x8001FE18: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x8001FE1C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8001FE20:
    // 0x8001FE20: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001FE24: beq         $v1, $zero, L_8001FE44
    if (ctx->r3 == 0) {
        // 0x8001FE28: nop
    
            goto L_8001FE44;
    }
    // 0x8001FE28: nop

    // 0x8001FE2C: blez        $a0, L_8001FE44
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8001FE30: nop
    
            goto L_8001FE44;
    }
    // 0x8001FE30: nop

    // 0x8001FE34: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    // 0x8001FE38: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001FE3C: j           L_8001FE70
    // 0x8001FE40: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
        goto L_8001FE70;
    // 0x8001FE40: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
L_8001FE44:
    // 0x8001FE44: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x8001FE48: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x8001FE4C: bltzl       $v1, L_8001FE54
    if (SIGNED(ctx->r3) < 0) {
        // 0x8001FE50: negu        $v1, $v1
        ctx->r3 = SUB32(0, ctx->r3);
            goto L_8001FE54;
    }
    goto skip_3;
    // 0x8001FE50: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    skip_3:
L_8001FE54:
    // 0x8001FE54: bltzl       $v0, L_8001FE5C
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001FE58: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_8001FE5C;
    }
    goto skip_4;
    // 0x8001FE58: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_4:
L_8001FE5C:
    // 0x8001FE5C: bne         $v1, $v0, L_8001FE70
    if (ctx->r3 != ctx->r2) {
        // 0x8001FE60: nop
    
            goto L_8001FE70;
    }
    // 0x8001FE60: nop

L_8001FE64:
    // 0x8001FE64: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x8001FE68: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001FE6C:
    // 0x8001FE6C: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
L_8001FE70:
    // 0x8001FE70: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8001FE74: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8001FE78: jal         0x800151FC
    // 0x8001FE7C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800151FC(rdram, ctx);
        goto after_9;
    // 0x8001FE7C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_9:
    // 0x8001FE80: bne         $v0, $zero, L_80020150
    if (ctx->r2 != 0) {
        // 0x8001FE84: nop
    
            goto L_80020150;
    }
    // 0x8001FE84: nop

L_8001FE88:
    // 0x8001FE88: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8001FE8C: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8001FE90: jal         0x800151FC
    // 0x8001FE94: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800151FC(rdram, ctx);
        goto after_10;
    // 0x8001FE94: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_10:
    // 0x8001FE98: bne         $v0, $zero, L_8001FEB0
    if (ctx->r2 != 0) {
        // 0x8001FE9C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8001FEB0;
    }
    // 0x8001FE9C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001FEA0: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    // 0x8001FEA4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001FEA8: j           L_8001FE88
    // 0x8001FEAC: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
        goto L_8001FE88;
    // 0x8001FEAC: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
L_8001FEB0:
    // 0x8001FEB0: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    // 0x8001FEB4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001FEB8: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // 0x8001FEBC: jal         0x80020874
    // 0x8001FEC0: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    func_80020874(rdram, ctx);
        goto after_11;
    // 0x8001FEC0: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    after_11:
    // 0x8001FEC4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001FEC8: jal         0x80015490
    // 0x8001FECC: addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
    func_80015490(rdram, ctx);
        goto after_12;
    // 0x8001FECC: addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
    after_12:
    // 0x8001FED0: jal         0x80020BDC
    // 0x8001FED4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80020BDC(rdram, ctx);
        goto after_13;
    // 0x8001FED4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_13:
    // 0x8001FED8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001FEDC: jal         0x80020954
    // 0x8001FEE0: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    func_80020954(rdram, ctx);
        goto after_14;
    // 0x8001FEE0: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    after_14:
    // 0x8001FEE4: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8001FEE8: slti        $v0, $fp, 0xB
    ctx->r2 = SIGNED(ctx->r30) < 0XB ? 1 : 0;
    // 0x8001FEEC: bne         $v0, $zero, L_8001FF0C
    if (ctx->r2 != 0) {
        // 0x8001FEF0: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8001FF0C;
    }
    // 0x8001FEF0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001FEF4: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x8001FEF8: slti        $v1, $s0, 0x32
    ctx->r3 = SIGNED(ctx->r16) < 0X32 ? 1 : 0;
    // 0x8001FEFC: slti        $v0, $v0, 0x7
    ctx->r2 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x8001FF00: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8001FF04: bnel        $v0, $zero, L_8001FF34
    if (ctx->r2 != 0) {
        // 0x8001FF08: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8001FF34;
    }
    goto skip_5;
    // 0x8001FF08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_5:
L_8001FF0C:
    // 0x8001FF0C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8001FF10: beq         $a3, $zero, L_8001FF34
    if (ctx->r7 == 0) {
        // 0x8001FF14: slti        $v0, $fp, 0x8
        ctx->r2 = SIGNED(ctx->r30) < 0X8 ? 1 : 0;
            goto L_8001FF34;
    }
    // 0x8001FF14: slti        $v0, $fp, 0x8
    ctx->r2 = SIGNED(ctx->r30) < 0X8 ? 1 : 0;
    // 0x8001FF18: bne         $v0, $zero, L_8001FF34
    if (ctx->r2 != 0) {
        // 0x8001FF1C: slti        $v1, $s0, 0x46
        ctx->r3 = SIGNED(ctx->r16) < 0X46 ? 1 : 0;
            goto L_8001FF34;
    }
    // 0x8001FF1C: slti        $v1, $s0, 0x46
    ctx->r3 = SIGNED(ctx->r16) < 0X46 ? 1 : 0;
    // 0x8001FF20: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x8001FF24: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8001FF28: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8001FF2C: bnel        $v0, $zero, L_8001FF34
    if (ctx->r2 != 0) {
        // 0x8001FF30: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8001FF34;
    }
    goto skip_6;
    // 0x8001FF30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_6:
L_8001FF34:
    // 0x8001FF34: jal         0x80020B20
    // 0x8001FF38: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80020B20(rdram, ctx);
        goto after_15;
    // 0x8001FF38: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_15:
    // 0x8001FF3C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001FF40: jal         0x80020A8C
    // 0x8001FF44: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    func_80020A8C(rdram, ctx);
        goto after_16;
    // 0x8001FF44: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    after_16:
    // 0x8001FF48: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8001FF4C: slti        $v0, $fp, 0xB
    ctx->r2 = SIGNED(ctx->r30) < 0XB ? 1 : 0;
    // 0x8001FF50: bne         $v0, $zero, L_8001FF6C
    if (ctx->r2 != 0) {
        // 0x8001FF54: slti        $v1, $s0, 0x32
        ctx->r3 = SIGNED(ctx->r16) < 0X32 ? 1 : 0;
            goto L_8001FF6C;
    }
    // 0x8001FF54: slti        $v1, $s0, 0x32
    ctx->r3 = SIGNED(ctx->r16) < 0X32 ? 1 : 0;
    // 0x8001FF58: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x8001FF5C: slti        $v0, $v0, 0x7
    ctx->r2 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x8001FF60: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8001FF64: bne         $v0, $zero, L_8001FF94
    if (ctx->r2 != 0) {
        // 0x8001FF68: nop
    
            goto L_8001FF94;
    }
    // 0x8001FF68: nop

L_8001FF6C:
    // 0x8001FF6C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8001FF70: beq         $a3, $zero, L_8001FFB0
    if (ctx->r7 == 0) {
        // 0x8001FF74: slti        $v0, $fp, 0x8
        ctx->r2 = SIGNED(ctx->r30) < 0X8 ? 1 : 0;
            goto L_8001FFB0;
    }
    // 0x8001FF74: slti        $v0, $fp, 0x8
    ctx->r2 = SIGNED(ctx->r30) < 0X8 ? 1 : 0;
    // 0x8001FF78: bne         $v0, $zero, L_8001FFB0
    if (ctx->r2 != 0) {
        // 0x8001FF7C: slti        $v1, $s0, 0x46
        ctx->r3 = SIGNED(ctx->r16) < 0X46 ? 1 : 0;
            goto L_8001FFB0;
    }
    // 0x8001FF7C: slti        $v1, $s0, 0x46
    ctx->r3 = SIGNED(ctx->r16) < 0X46 ? 1 : 0;
    // 0x8001FF80: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x8001FF84: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8001FF88: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8001FF8C: beq         $v0, $zero, L_8001FFB0
    if (ctx->r2 == 0) {
        // 0x8001FF90: nop
    
            goto L_8001FFB0;
    }
    // 0x8001FF90: nop

L_8001FF94:
    // 0x8001FF94: lb          $v0, 0x54($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X54);
    // 0x8001FF98: slti        $v0, $v0, 0xF
    ctx->r2 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x8001FF9C: beq         $v0, $zero, L_8001FFB0
    if (ctx->r2 == 0) {
        // 0x8001FFA0: nop
    
            goto L_8001FFB0;
    }
    // 0x8001FFA0: nop

    // 0x8001FFA4: lb          $v0, 0x123($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X123);
    // 0x8001FFA8: j           L_80020020
    // 0x8001FFAC: slt         $v0, $v0, $s2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
        goto L_80020020;
    // 0x8001FFAC: slt         $v0, $v0, $s2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
L_8001FFB0:
    // 0x8001FFB0: beq         $s4, $zero, L_8001FFC4
    if (ctx->r20 == 0) {
        // 0x8001FFB4: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8001FFC4;
    }
    // 0x8001FFB4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001FFB8: lb          $v0, 0x126($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X126);
    // 0x8001FFBC: j           L_80020024
    // 0x8001FFC0: slt         $v0, $v0, $s4
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
        goto L_80020024;
    // 0x8001FFC0: slt         $v0, $v0, $s4
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
L_8001FFC4:
    // 0x8001FFC4: lb          $s0, 0x127($s1)
    ctx->r16 = MEM_B(ctx->r17, 0X127);
    // 0x8001FFC8: jal         0x80020EB4
    // 0x8001FFCC: sw          $a1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r5;
    func_80020EB4(rdram, ctx);
        goto after_17;
    // 0x8001FFCC: sw          $a1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r5;
    after_17:
    // 0x8001FFD0: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8001FFD4: slt         $s0, $s0, $v0
    ctx->r16 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001FFD8: beq         $s0, $zero, L_8001FFEC
    if (ctx->r16 == 0) {
        // 0x8001FFDC: nop
    
            goto L_8001FFEC;
    }
    // 0x8001FFDC: nop

    // 0x8001FFE0: lb          $v0, 0x129($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X129);
    // 0x8001FFE4: j           L_80020024
    // 0x8001FFE8: slt         $v0, $v0, $s7
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r23) ? 1 : 0;
        goto L_80020024;
    // 0x8001FFE8: slt         $v0, $v0, $s7
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r23) ? 1 : 0;
L_8001FFEC:
    // 0x8001FFEC: lb          $v0, 0x127($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X127);
    // 0x8001FFF0: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8001FFF4: beq         $v0, $zero, L_80020018
    if (ctx->r2 == 0) {
        // 0x8001FFF8: nop
    
            goto L_80020018;
    }
    // 0x8001FFF8: nop

    // 0x8001FFFC: lb          $v0, 0x54($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X54);
    // 0x80020000: slti        $v0, $v0, 0x11
    ctx->r2 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x80020004: beq         $v0, $zero, L_80020018
    if (ctx->r2 == 0) {
        // 0x80020008: nop
    
            goto L_80020018;
    }
    // 0x80020008: nop

    // 0x8002000C: lb          $v0, 0x125($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X125);
    // 0x80020010: j           L_80020020
    // 0x80020014: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
        goto L_80020020;
    // 0x80020014: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
L_80020018:
    // 0x80020018: lb          $v0, 0x127($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X127);
    // 0x8002001C: slt         $v0, $s6, $v0
    ctx->r2 = SIGNED(ctx->r22) < SIGNED(ctx->r2) ? 1 : 0;
L_80020020:
    // 0x80020020: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
L_80020024:
    // 0x80020024: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80020028: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8002002C: beq         $v0, $zero, L_80020150
    if (ctx->r2 == 0) {
        // 0x80020030: nop
    
            goto L_80020150;
    }
    // 0x80020030: nop

    // 0x80020034: lb          $v0, 0x123($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X123);
    // 0x80020038: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002003C: bnel        $v0, $zero, L_80020044
    if (ctx->r2 != 0) {
        // 0x80020040: sb          $s2, 0x123($s1)
        MEM_B(0X123, ctx->r17) = ctx->r18;
            goto L_80020044;
    }
    goto skip_7;
    // 0x80020040: sb          $s2, 0x123($s1)
    MEM_B(0X123, ctx->r17) = ctx->r18;
    skip_7:
L_80020044:
    // 0x80020044: lb          $v0, 0x126($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X126);
    // 0x80020048: slt         $v0, $v0, $s4
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8002004C: bnel        $v0, $zero, L_80020054
    if (ctx->r2 != 0) {
        // 0x80020050: sb          $s4, 0x126($s1)
        MEM_B(0X126, ctx->r17) = ctx->r20;
            goto L_80020054;
    }
    goto skip_8;
    // 0x80020050: sb          $s4, 0x126($s1)
    MEM_B(0X126, ctx->r17) = ctx->r20;
    skip_8:
L_80020054:
    // 0x80020054: lb          $v0, 0x127($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X127);
    // 0x80020058: slt         $v0, $v0, $s6
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8002005C: bnel        $v0, $zero, L_80020064
    if (ctx->r2 != 0) {
        // 0x80020060: sb          $s6, 0x127($s1)
        MEM_B(0X127, ctx->r17) = ctx->r22;
            goto L_80020064;
    }
    goto skip_9;
    // 0x80020060: sb          $s6, 0x127($s1)
    MEM_B(0X127, ctx->r17) = ctx->r22;
    skip_9:
L_80020064:
    // 0x80020064: lb          $v0, 0x129($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X129);
    // 0x80020068: slt         $v0, $v0, $s7
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x8002006C: bnel        $v0, $zero, L_80020074
    if (ctx->r2 != 0) {
        // 0x80020070: sb          $s7, 0x129($s1)
        MEM_B(0X129, ctx->r17) = ctx->r23;
            goto L_80020074;
    }
    goto skip_10;
    // 0x80020070: sb          $s7, 0x129($s1)
    MEM_B(0X129, ctx->r17) = ctx->r23;
    skip_10:
L_80020074:
    // 0x80020074: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80020078: lbu         $v1, 0x4C($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X4C);
    // 0x8002007C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80020080: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x80020084: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80020088: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002008C: sb          $v1, -0x2120($at)
    MEM_B(-0X2120, ctx->r1) = ctx->r3;
    // 0x80020090: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80020094: lw          $v1, 0x18($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X18);
    // 0x80020098: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8002009C: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x800200A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800200A4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800200A8: sb          $v1, -0x211F($at)
    MEM_B(-0X211F, ctx->r1) = ctx->r3;
    // 0x800200AC: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800200B0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800200B4: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x800200B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800200BC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800200C0: sb          $s2, -0x211C($at)
    MEM_B(-0X211C, ctx->r1) = ctx->r18;
    // 0x800200C4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800200C8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800200CC: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x800200D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800200D4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800200D8: sb          $a1, -0x211E($at)
    MEM_B(-0X211E, ctx->r1) = ctx->r5;
    // 0x800200DC: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800200E0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800200E4: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x800200E8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800200EC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800200F0: sb          $s4, -0x211D($at)
    MEM_B(-0X211D, ctx->r1) = ctx->r20;
    // 0x800200F4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800200F8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800200FC: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x80020100: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80020104: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80020108: sb          $s6, -0x211B($at)
    MEM_B(-0X211B, ctx->r1) = ctx->r22;
    // 0x8002010C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80020110: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80020114: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x80020118: lbu         $a3, 0x57($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X57);
    // 0x8002011C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80020120: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80020124: sb          $a3, -0x211A($at)
    MEM_B(-0X211A, ctx->r1) = ctx->r7;
    // 0x80020128: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8002012C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80020130: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x80020134: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80020138: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002013C: sb          $s7, -0x2119($at)
    MEM_B(-0X2119, ctx->r1) = ctx->r23;
    // 0x80020140: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80020144: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80020148: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x8002014C: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
L_80020150:
    // 0x80020150: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80020154: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80020158: slti        $v0, $a3, 0xA
    ctx->r2 = SIGNED(ctx->r7) < 0XA ? 1 : 0;
    // 0x8002015C: bne         $v0, $zero, L_8001FCAC
    if (ctx->r2 != 0) {
        // 0x80020160: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_8001FCAC;
    }
    // 0x80020160: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80020164: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80020168: sw          $a3, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r7;
    // 0x8002016C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80020170: sw          $a3, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r7;
    // 0x80020174: lbu         $a3, 0x3F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3F);
    // 0x80020178: sb          $a3, 0x4C($s1)
    MEM_B(0X4C, ctx->r17) = ctx->r7;
    // 0x8002017C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80020180: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80020184: jal         0x80020DDC
    // 0x80020188: sw          $a3, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = ctx->r7;
    func_80020DDC(rdram, ctx);
        goto after_18;
    // 0x80020188: sw          $a3, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = ctx->r7;
    after_18:
    // 0x8002018C: lbu         $v0, 0x11F($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X11F);
    // 0x80020190: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80020194: sb          $v0, 0x11F($s1)
    MEM_B(0X11F, ctx->r17) = ctx->r2;
    // 0x80020198: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    // 0x8002019C: lw          $fp, 0x88($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X88);
    // 0x800201A0: lw          $s7, 0x84($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X84);
    // 0x800201A4: lw          $s6, 0x80($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X80);
    // 0x800201A8: lw          $s5, 0x7C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X7C);
    // 0x800201AC: lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X78);
    // 0x800201B0: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x800201B4: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x800201B8: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x800201BC: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x800201C0: jr          $ra
    // 0x800201C4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800201C4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_800201C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800201C8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800201CC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800201D0: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800201D4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800201D8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800201DC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800201E0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800201E4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800201E8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800201EC: jal         0x80020A38
    // 0x800201F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80020A38(rdram, ctx);
        goto after_0;
    // 0x800201F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800201F4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800201F8: jal         0x80020A8C
    // 0x800201FC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_80020A8C(rdram, ctx);
        goto after_1;
    // 0x800201FC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80020200: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80020204: jal         0x80020818
    // 0x80020208: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    func_80020818(rdram, ctx);
        goto after_2;
    // 0x80020208: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    after_2:
    // 0x8002020C: lbu         $a0, 0x5($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X5);
    // 0x80020210: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x80020214: sb          $v1, 0x11F($s1)
    MEM_B(0X11F, ctx->r17) = ctx->r3;
    // 0x80020218: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8002021C: sb          $v1, 0x11D($s1)
    MEM_B(0X11D, ctx->r17) = ctx->r3;
    // 0x80020220: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
    // 0x80020224: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80020228: slti        $v0, $s0, 0xB
    ctx->r2 = SIGNED(ctx->r16) < 0XB ? 1 : 0;
    // 0x8002022C: sw          $zero, 0x114($s1)
    MEM_W(0X114, ctx->r17) = 0;
    // 0x80020230: sb          $zero, 0x128($s1)
    MEM_B(0X128, ctx->r17) = 0;
    // 0x80020234: sb          $zero, 0x126($s1)
    MEM_B(0X126, ctx->r17) = 0;
    // 0x80020238: sb          $zero, 0x129($s1)
    MEM_B(0X129, ctx->r17) = 0;
    // 0x8002023C: sb          $v1, 0x125($s1)
    MEM_B(0X125, ctx->r17) = ctx->r3;
    // 0x80020240: sb          $v1, 0x124($s1)
    MEM_B(0X124, ctx->r17) = ctx->r3;
    // 0x80020244: bne         $v0, $zero, L_80020264
    if (ctx->r2 != 0) {
        // 0x80020248: andi        $a0, $a0, 0x1
        ctx->r4 = ctx->r4 & 0X1;
            goto L_80020264;
    }
    // 0x80020248: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    // 0x8002024C: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x80020250: slti        $v1, $s2, 0x32
    ctx->r3 = SIGNED(ctx->r18) < 0X32 ? 1 : 0;
    // 0x80020254: slti        $v0, $v0, 0x7
    ctx->r2 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80020258: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8002025C: bne         $v0, $zero, L_80020288
    if (ctx->r2 != 0) {
        // 0x80020260: nop
    
            goto L_80020288;
    }
    // 0x80020260: nop

L_80020264:
    // 0x80020264: beq         $a1, $zero, L_80020390
    if (ctx->r5 == 0) {
        // 0x80020268: slti        $v0, $s0, 0x8
        ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
            goto L_80020390;
    }
    // 0x80020268: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x8002026C: bne         $v0, $zero, L_80020390
    if (ctx->r2 != 0) {
        // 0x80020270: slti        $v1, $s2, 0x46
        ctx->r3 = SIGNED(ctx->r18) < 0X46 ? 1 : 0;
            goto L_80020390;
    }
    // 0x80020270: slti        $v1, $s2, 0x46
    ctx->r3 = SIGNED(ctx->r18) < 0X46 ? 1 : 0;
    // 0x80020274: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x80020278: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8002027C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80020280: beq         $v0, $zero, L_80020390
    if (ctx->r2 == 0) {
        // 0x80020284: nop
    
            goto L_80020390;
    }
    // 0x80020284: nop

L_80020288:
    // 0x80020288: lb          $v0, 0x54($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X54);
    // 0x8002028C: slti        $v0, $v0, 0xF
    ctx->r2 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x80020290: beq         $v0, $zero, L_80020390
    if (ctx->r2 == 0) {
        // 0x80020294: sll         $a1, $a0, 2
        ctx->r5 = S32(ctx->r4 << 2);
            goto L_80020390;
    }
    // 0x80020294: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x80020298: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002029C: addiu       $v0, $v0, -0x212C
    ctx->r2 = ADD32(ctx->r2, -0X212C);
    // 0x800202A0: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x800202A4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800202A8: addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
    // 0x800202AC: sll         $a0, $a0, 9
    ctx->r4 = S32(ctx->r4 << 9);
    // 0x800202B0: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x800202B4: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
L_800202B8:
    // 0x800202B8: addu        $a2, $a1, $t1
    ctx->r6 = ADD32(ctx->r5, ctx->r9);
    // 0x800202BC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800202C0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800202C4: addu        $a1, $v0, $a0
    ctx->r5 = ADD32(ctx->r2, ctx->r4);
    // 0x800202C8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800202CC: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800202D0: lbu         $v1, -0x211C($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X211C);
    // 0x800202D4: lb          $v0, 0x123($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X123);
    // 0x800202D8: bne         $v1, $v0, L_80020370
    if (ctx->r3 != ctx->r2) {
        // 0x800202DC: nop
    
            goto L_80020370;
    }
    // 0x800202DC: nop

    // 0x800202E0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800202E4: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800202E8: lbu         $v1, -0x211E($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X211E);
    // 0x800202EC: lb          $v0, 0x125($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X125);
    // 0x800202F0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800202F4: bne         $v0, $zero, L_80020370
    if (ctx->r2 != 0) {
        // 0x800202F8: nop
    
            goto L_80020370;
    }
    // 0x800202F8: nop

    // 0x800202FC: sb          $v1, 0x125($s1)
    MEM_B(0X125, ctx->r17) = ctx->r3;
    // 0x80020300: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80020304: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80020308: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8002030C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80020310: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80020314: lbu         $v0, -0x211F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211F);
    // 0x80020318: sb          $v0, 0x122($s1)
    MEM_B(0X122, ctx->r17) = ctx->r2;
    // 0x8002031C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80020320: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80020324: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80020328: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002032C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80020330: lbu         $v0, -0x2120($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X2120);
    // 0x80020334: sb          $v0, 0x11D($s1)
    MEM_B(0X11D, ctx->r17) = ctx->r2;
    // 0x80020338: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8002033C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80020340: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80020344: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80020348: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002034C: lbu         $v0, -0x211A($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211A);
    // 0x80020350: sb          $v0, 0x120($s1)
    MEM_B(0X120, ctx->r17) = ctx->r2;
    // 0x80020354: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80020358: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8002035C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80020360: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80020364: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80020368: lbu         $v0, -0x211D($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211D);
    // 0x8002036C: sb          $v0, 0x121($s1)
    MEM_B(0X121, ctx->r17) = ctx->r2;
L_80020370:
    // 0x80020370: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80020374: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80020378: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8002037C: slti        $v0, $v0, 0x40
    ctx->r2 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x80020380: bne         $v0, $zero, L_800202B8
    if (ctx->r2 != 0) {
        // 0x80020384: addu        $a1, $t0, $zero
        ctx->r5 = ADD32(ctx->r8, 0);
            goto L_800202B8;
    }
    // 0x80020384: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x80020388: j           L_8002065C
    // 0x8002038C: nop

        goto L_8002065C;
    // 0x8002038C: nop

L_80020390:
    // 0x80020390: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80020394: addiu       $a1, $a1, -0x212C
    ctx->r5 = ADD32(ctx->r5, -0X212C);
    // 0x80020398: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8002039C: addu        $v0, $v1, $a1
    ctx->r2 = ADD32(ctx->r3, ctx->r5);
    // 0x800203A0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800203A4: sll         $s3, $a0, 9
    ctx->r19 = S32(ctx->r4 << 9);
    // 0x800203A8: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x800203AC: addu        $s5, $v1, $zero
    ctx->r21 = ADD32(ctx->r3, 0);
    // 0x800203B0: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
L_800203B4:
    // 0x800203B4: addu        $s2, $v1, $a1
    ctx->r18 = ADD32(ctx->r3, ctx->r5);
    // 0x800203B8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800203BC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800203C0: addu        $a0, $v0, $s3
    ctx->r4 = ADD32(ctx->r2, ctx->r19);
    // 0x800203C4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800203C8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800203CC: lbu         $v1, -0x211C($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X211C);
    // 0x800203D0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800203D4: beq         $v1, $v0, L_80020640
    if (ctx->r3 == ctx->r2) {
        // 0x800203D8: nop
    
            goto L_80020640;
    }
    // 0x800203D8: nop

    // 0x800203DC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800203E0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800203E4: lbu         $v1, -0x211D($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X211D);
    // 0x800203E8: lb          $a0, 0x126($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X126);
    // 0x800203EC: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800203F0: beq         $v0, $zero, L_80020444
    if (ctx->r2 == 0) {
        // 0x800203F4: nop
    
            goto L_80020444;
    }
    // 0x800203F4: nop

    // 0x800203F8: sb          $v1, 0x126($s1)
    MEM_B(0X126, ctx->r17) = ctx->r3;
    // 0x800203FC: sb          $v1, 0x121($s1)
    MEM_B(0X121, ctx->r17) = ctx->r3;
    // 0x80020400: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80020404: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80020408: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x8002040C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80020410: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80020414: lbu         $v0, -0x211F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211F);
    // 0x80020418: sb          $v0, 0x122($s1)
    MEM_B(0X122, ctx->r17) = ctx->r2;
    // 0x8002041C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80020420: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80020424: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80020428: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002042C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80020430: lbu         $v0, -0x2120($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X2120);
    // 0x80020434: sb          $v0, 0x11D($s1)
    MEM_B(0X11D, ctx->r17) = ctx->r2;
    // 0x80020438: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8002043C: j           L_8002062C
    // 0x80020440: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
        goto L_8002062C;
    // 0x80020440: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
L_80020444:
    // 0x80020444: bne         $a0, $zero, L_80020640
    if (ctx->r4 != 0) {
        // 0x80020448: nop
    
            goto L_80020640;
    }
    // 0x80020448: nop

    // 0x8002044C: lb          $s0, 0x127($s1)
    ctx->r16 = MEM_B(ctx->r17, 0X127);
    // 0x80020450: jal         0x80020EB4
    // 0x80020454: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80020EB4(rdram, ctx);
        goto after_3;
    // 0x80020454: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
    // 0x80020458: slt         $s0, $s0, $v0
    ctx->r16 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002045C: beq         $s0, $zero, L_800204D4
    if (ctx->r16 == 0) {
        // 0x80020460: nop
    
            goto L_800204D4;
    }
    // 0x80020460: nop

    // 0x80020464: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80020468: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8002046C: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80020470: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80020474: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80020478: lb          $v1, -0x2119($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X2119);
    // 0x8002047C: lb          $v0, 0x129($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X129);
    // 0x80020480: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80020484: beq         $v0, $zero, L_80020640
    if (ctx->r2 == 0) {
        // 0x80020488: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_80020640;
    }
    // 0x80020488: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8002048C: sb          $a0, 0x129($s1)
    MEM_B(0X129, ctx->r17) = ctx->r4;
    // 0x80020490: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80020494: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80020498: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x8002049C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800204A0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800204A4: lbu         $v0, -0x211F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211F);
    // 0x800204A8: sb          $v0, 0x122($s1)
    MEM_B(0X122, ctx->r17) = ctx->r2;
    // 0x800204AC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800204B0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800204B4: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800204B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800204BC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800204C0: lbu         $v0, -0x2120($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X2120);
    // 0x800204C4: sb          $v0, 0x11D($s1)
    MEM_B(0X11D, ctx->r17) = ctx->r2;
    // 0x800204C8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800204CC: j           L_8002062C
    // 0x800204D0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
        goto L_8002062C;
    // 0x800204D0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
L_800204D4:
    // 0x800204D4: lb          $v0, 0x127($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X127);
    // 0x800204D8: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800204DC: beq         $v0, $zero, L_8002057C
    if (ctx->r2 == 0) {
        // 0x800204E0: nop
    
            goto L_8002057C;
    }
    // 0x800204E0: nop

    // 0x800204E4: lb          $v0, 0x54($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X54);
    // 0x800204E8: slti        $v0, $v0, 0x11
    ctx->r2 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x800204EC: beq         $v0, $zero, L_8002057C
    if (ctx->r2 == 0) {
        // 0x800204F0: nop
    
            goto L_8002057C;
    }
    // 0x800204F0: nop

    // 0x800204F4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800204F8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800204FC: addu        $a0, $v0, $s3
    ctx->r4 = ADD32(ctx->r2, ctx->r19);
    // 0x80020500: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80020504: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80020508: lbu         $v1, -0x211C($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X211C);
    // 0x8002050C: lb          $v0, 0x123($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X123);
    // 0x80020510: bne         $v1, $v0, L_80020640
    if (ctx->r3 != ctx->r2) {
        // 0x80020514: nop
    
            goto L_80020640;
    }
    // 0x80020514: nop

    // 0x80020518: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8002051C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80020520: lbu         $v1, -0x211E($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X211E);
    // 0x80020524: lb          $v0, 0x125($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X125);
    // 0x80020528: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002052C: bne         $v0, $zero, L_80020640
    if (ctx->r2 != 0) {
        // 0x80020530: nop
    
            goto L_80020640;
    }
    // 0x80020530: nop

    // 0x80020534: sb          $v1, 0x125($s1)
    MEM_B(0X125, ctx->r17) = ctx->r3;
    // 0x80020538: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8002053C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80020540: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80020544: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80020548: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002054C: lbu         $v0, -0x211F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211F);
    // 0x80020550: sb          $v0, 0x122($s1)
    MEM_B(0X122, ctx->r17) = ctx->r2;
    // 0x80020554: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80020558: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8002055C: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80020560: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80020564: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80020568: lbu         $v0, -0x2120($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X2120);
    // 0x8002056C: sb          $v0, 0x11D($s1)
    MEM_B(0X11D, ctx->r17) = ctx->r2;
    // 0x80020570: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80020574: j           L_8002062C
    // 0x80020578: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
        goto L_8002062C;
    // 0x80020578: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
L_8002057C:
    // 0x8002057C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80020580: lb          $a0, 0x124($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X124);
    // 0x80020584: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80020588: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x8002058C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80020590: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80020594: lbu         $v1, -0x211B($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X211B);
    // 0x80020598: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8002059C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800205A0: lbu         $a1, -0x211C($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X211C);
    // 0x800205A4: lb          $v0, 0x128($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X128);
    // 0x800205A8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800205AC: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x800205B0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800205B4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800205B8: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800205BC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800205C0: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800205C4: bne         $v1, $zero, L_80020640
    if (ctx->r3 != 0) {
        // 0x800205C8: nop
    
            goto L_80020640;
    }
    // 0x800205C8: nop

    // 0x800205CC: sb          $a1, 0x124($s1)
    MEM_B(0X124, ctx->r17) = ctx->r5;
    // 0x800205D0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800205D4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800205D8: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800205DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800205E0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800205E4: lbu         $v0, -0x211B($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211B);
    // 0x800205E8: sb          $v0, 0x128($s1)
    MEM_B(0X128, ctx->r17) = ctx->r2;
    // 0x800205EC: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800205F0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800205F4: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800205F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800205FC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80020600: lbu         $v0, -0x211F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211F);
    // 0x80020604: sb          $v0, 0x122($s1)
    MEM_B(0X122, ctx->r17) = ctx->r2;
    // 0x80020608: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8002060C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80020610: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80020614: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80020618: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002061C: lbu         $v0, -0x2120($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X2120);
    // 0x80020620: sb          $v0, 0x11D($s1)
    MEM_B(0X11D, ctx->r17) = ctx->r2;
    // 0x80020624: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80020628: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
L_8002062C:
    // 0x8002062C: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80020630: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80020634: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80020638: lbu         $v0, -0x211A($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211A);
    // 0x8002063C: sb          $v0, 0x120($s1)
    MEM_B(0X120, ctx->r17) = ctx->r2;
L_80020640:
    // 0x80020640: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80020644: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x80020648: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002064C: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x80020650: slti        $v0, $v0, 0x40
    ctx->r2 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x80020654: bne         $v0, $zero, L_800203B4
    if (ctx->r2 != 0) {
        // 0x80020658: addu        $v1, $s5, $zero
        ctx->r3 = ADD32(ctx->r21, 0);
            goto L_800203B4;
    }
    // 0x80020658: addu        $v1, $s5, $zero
    ctx->r3 = ADD32(ctx->r21, 0);
L_8002065C:
    // 0x8002065C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80020660: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80020664: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80020668: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002066C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80020670: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80020674: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80020678: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002067C: jr          $ra
    // 0x80020680: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80020680: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80020684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020688: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002068C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80020690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020694: lb          $v1, 0x11D($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X11D);
    // 0x80020698: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8002069C: beq         $v1, $v0, L_80020808
    if (ctx->r3 == ctx->r2) {
        // 0x800206A0: nop
    
            goto L_80020808;
    }
    // 0x800206A0: nop

    // 0x800206A4: lb          $a0, 0x122($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X122);
    // 0x800206A8: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
    // 0x800206AC: bne         $a0, $v1, L_8002078C
    if (ctx->r4 != ctx->r3) {
        // 0x800206B0: sw          $zero, 0x114($s0)
        MEM_W(0X114, ctx->r16) = 0;
            goto L_8002078C;
    }
    // 0x800206B0: sw          $zero, 0x114($s0)
    MEM_W(0X114, ctx->r16) = 0;
    // 0x800206B4: lb          $v1, 0x11D($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X11D);
    // 0x800206B8: lb          $v0, 0x4C($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X4C);
    // 0x800206BC: beq         $v1, $v0, L_800206CC
    if (ctx->r3 == ctx->r2) {
        // 0x800206C0: nop
    
            goto L_800206CC;
    }
    // 0x800206C0: nop

    // 0x800206C4: lhu         $v0, 0x82($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X82);
    // 0x800206C8: sw          $v0, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->r2;
L_800206CC:
    // 0x800206CC: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x800206D0: lb          $v0, 0x2($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2);
    // 0x800206D4: beq         $v0, $zero, L_80020780
    if (ctx->r2 == 0) {
        // 0x800206D8: nop
    
            goto L_80020780;
    }
    // 0x800206D8: nop

    // 0x800206DC: jal         0x80020E30
    // 0x800206E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80020E30(rdram, ctx);
        goto after_0;
    // 0x800206E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800206E4: beq         $v0, $zero, L_800206F8
    if (ctx->r2 == 0) {
        // 0x800206E8: nop
    
            goto L_800206F8;
    }
    // 0x800206E8: nop

    // 0x800206EC: lb          $v0, 0x121($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X121);
    // 0x800206F0: bne         $v0, $zero, L_80020808
    if (ctx->r2 != 0) {
        // 0x800206F4: nop
    
            goto L_80020808;
    }
    // 0x800206F4: nop

L_800206F8:
    // 0x800206F8: lb          $v0, 0x120($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X120);
    // 0x800206FC: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80020700: bne         $v0, $zero, L_80020734
    if (ctx->r2 != 0) {
        // 0x80020704: nop
    
            goto L_80020734;
    }
    // 0x80020704: nop

    // 0x80020708: lbu         $v0, 0x55($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X55);
    // 0x8002070C: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80020710: beq         $v0, $zero, L_80020734
    if (ctx->r2 == 0) {
        // 0x80020714: nop
    
            goto L_80020734;
    }
    // 0x80020714: nop

    // 0x80020718: lb          $v0, 0x54($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X54);
    // 0x8002071C: beq         $v0, $zero, L_80020734
    if (ctx->r2 == 0) {
        // 0x80020720: nop
    
            goto L_80020734;
    }
    // 0x80020720: nop

    // 0x80020724: lb          $v1, 0xCC($s0)
    ctx->r3 = MEM_B(ctx->r16, 0XCC);
    // 0x80020728: lb          $v0, 0xCD($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XCD);
    // 0x8002072C: beq         $v1, $v0, L_80020740
    if (ctx->r3 == ctx->r2) {
        // 0x80020730: nop
    
            goto L_80020740;
    }
    // 0x80020730: nop

L_80020734:
    // 0x80020734: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x80020738: j           L_80020804
    // 0x8002073C: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
        goto L_80020804;
    // 0x8002073C: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
L_80020740:
    // 0x80020740: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80020744: lbu         $v0, 0x7B7C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B7C);
    // 0x80020748: bne         $v0, $zero, L_80020770
    if (ctx->r2 != 0) {
        // 0x8002074C: nop
    
            goto L_80020770;
    }
    // 0x8002074C: nop

    // 0x80020750: lb          $v1, 0x11D($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X11D);
    // 0x80020754: lb          $v0, 0x4C($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X4C);
    // 0x80020758: bne         $v1, $v0, L_80020770
    if (ctx->r3 != ctx->r2) {
        // 0x8002075C: nop
    
            goto L_80020770;
    }
    // 0x8002075C: nop

    // 0x80020760: lhu         $v1, 0x80($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X80);
    // 0x80020764: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x80020768: j           L_80020804
    // 0x8002076C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
        goto L_80020804;
    // 0x8002076C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
L_80020770:
    // 0x80020770: lw          $v1, 0xD0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XD0);
    // 0x80020774: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80020778: j           L_80020808
    // 0x8002077C: sb          $v0, 0x11C($v1)
    MEM_B(0X11C, ctx->r3) = ctx->r2;
        goto L_80020808;
    // 0x8002077C: sb          $v0, 0x11C($v1)
    MEM_B(0X11C, ctx->r3) = ctx->r2;
L_80020780:
    // 0x80020780: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x80020784: j           L_80020804
    // 0x80020788: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
        goto L_80020804;
    // 0x80020788: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
L_8002078C:
    // 0x8002078C: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80020790: beq         $v0, $zero, L_800207CC
    if (ctx->r2 == 0) {
        // 0x80020794: slt         $v0, $v1, $a0
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800207CC;
    }
    // 0x80020794: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80020798: lw          $v0, 0x118($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X118);
    // 0x8002079C: beq         $v0, $zero, L_800207C0
    if (ctx->r2 == 0) {
        // 0x800207A0: nop
    
            goto L_800207C0;
    }
    // 0x800207A0: nop

    // 0x800207A4: lb          $v1, 0x11D($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X11D);
    // 0x800207A8: lb          $v0, 0x4C($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X4C);
    // 0x800207AC: beq         $v1, $v0, L_800207C0
    if (ctx->r3 == ctx->r2) {
        // 0x800207B0: nop
    
            goto L_800207C0;
    }
    // 0x800207B0: nop

    // 0x800207B4: lhu         $v0, 0x82($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X82);
    // 0x800207B8: j           L_80020804
    // 0x800207BC: sw          $zero, 0x118($s0)
    MEM_W(0X118, ctx->r16) = 0;
        goto L_80020804;
    // 0x800207BC: sw          $zero, 0x118($s0)
    MEM_W(0X118, ctx->r16) = 0;
L_800207C0:
    // 0x800207C0: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x800207C4: j           L_80020804
    // 0x800207C8: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
        goto L_80020804;
    // 0x800207C8: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
L_800207CC:
    // 0x800207CC: beq         $v0, $zero, L_80020808
    if (ctx->r2 == 0) {
        // 0x800207D0: nop
    
            goto L_80020808;
    }
    // 0x800207D0: nop

    // 0x800207D4: lw          $v0, 0x118($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X118);
    // 0x800207D8: beq         $v0, $zero, L_800207FC
    if (ctx->r2 == 0) {
        // 0x800207DC: nop
    
            goto L_800207FC;
    }
    // 0x800207DC: nop

    // 0x800207E0: lb          $v1, 0x11D($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X11D);
    // 0x800207E4: lb          $v0, 0x4C($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X4C);
    // 0x800207E8: beq         $v1, $v0, L_800207FC
    if (ctx->r3 == ctx->r2) {
        // 0x800207EC: nop
    
            goto L_800207FC;
    }
    // 0x800207EC: nop

    // 0x800207F0: lhu         $v0, 0x82($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X82);
    // 0x800207F4: j           L_80020804
    // 0x800207F8: sw          $zero, 0x118($s0)
    MEM_W(0X118, ctx->r16) = 0;
        goto L_80020804;
    // 0x800207F8: sw          $zero, 0x118($s0)
    MEM_W(0X118, ctx->r16) = 0;
L_800207FC:
    // 0x800207FC: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x80020800: ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
L_80020804:
    // 0x80020804: sw          $v0, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->r2;
L_80020808:
    // 0x80020808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002080C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80020810: jr          $ra
    // 0x80020814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80020814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80020818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020818: lbu         $v0, 0x55($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X55);
    // 0x8002081C: lb          $v1, 0xCC($a0)
    ctx->r3 = MEM_B(ctx->r4, 0XCC);
    // 0x80020820: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80020824: bne         $v0, $zero, L_80020834
    if (ctx->r2 != 0) {
        // 0x80020828: nop
    
            goto L_80020834;
    }
    // 0x80020828: nop

L_8002082C:
    // 0x8002082C: j           L_8002086C
    // 0x80020830: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002086C;
    // 0x80020830: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80020834:
    // 0x80020834: lb          $v0, 0xCD($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XCD);
    // 0x80020838: beql        $v1, $v0, L_8002086C
    if (ctx->r3 == ctx->r2) {
        // 0x8002083C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8002086C;
    }
    goto skip_0;
    // 0x8002083C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_0:
    // 0x80020840: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80020844: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80020848: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
L_8002084C:
    // 0x8002084C: lbu         $v0, 0xBC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XBC);
    // 0x80020850: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80020854: beq         $v0, $a2, L_8002082C
    if (ctx->r2 == ctx->r6) {
        // 0x80020858: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8002082C;
    }
    // 0x80020858: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8002085C: andi        $v1, $v0, 0xF
    ctx->r3 = ctx->r2 & 0XF;
    // 0x80020860: bne         $v1, $a1, L_8002084C
    if (ctx->r3 != ctx->r5) {
        // 0x80020864: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_8002084C;
    }
    // 0x80020864: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x80020868: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8002086C:
    // 0x8002086C: jr          $ra
    // 0x80020870: nop

    return;
    // 0x80020870: nop

;}
RECOMP_FUNC void func_80020874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020874: lb          $v1, 0x54($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X54);
    // 0x80020878: lw          $v0, 0xDC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XDC);
    // 0x8002087C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80020880: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80020884: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80020888: lb          $v0, 0x4C($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X4C);
    // 0x8002088C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80020890: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x80020894: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80020898: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002089C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
L_800208A0:
    // 0x800208A0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800208A4: addu        $t0, $t2, $zero
    ctx->r8 = ADD32(ctx->r10, 0);
L_800208A8:
    // 0x800208A8: lb          $v0, 0x0($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X0);
    // 0x800208AC: beql        $v0, $zero, L_80020930
    if (ctx->r2 == 0) {
        // 0x800208B0: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80020930;
    }
    goto skip_0;
    // 0x800208B0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_0:
    // 0x800208B4: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x800208B8: addu        $a1, $v0, $t1
    ctx->r5 = ADD32(ctx->r2, ctx->r9);
    // 0x800208BC: addiu       $v0, $a1, -0x2
    ctx->r2 = ADD32(ctx->r5, -0X2);
    // 0x800208C0: blez        $v0, L_80020900
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800208C4: nop
    
            goto L_80020900;
    }
    // 0x800208C4: nop

    // 0x800208C8: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
    // 0x800208CC: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x800208D0: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x800208D4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800208D8: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x800208DC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800208E0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800208E4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800208E8: lbu         $v0, 0x49($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X49);
    // 0x800208EC: lbu         $v1, 0x4B($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4B);
    // 0x800208F0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800208F4: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x800208F8: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x800208FC: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
L_80020900:
    // 0x80020900: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
    // 0x80020904: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x80020908: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8002090C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80020910: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x80020914: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80020918: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8002091C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80020920: lbu         $v0, 0x5C($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5C);
    // 0x80020924: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80020928: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x8002092C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80020930:
    // 0x80020930: slti        $v0, $a2, 0x5
    ctx->r2 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
    // 0x80020934: bne         $v0, $zero, L_800208A8
    if (ctx->r2 != 0) {
        // 0x80020938: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800208A8;
    }
    // 0x80020938: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8002093C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80020940: slti        $v0, $t1, 0x5
    ctx->r2 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x80020944: bne         $v0, $zero, L_800208A0
    if (ctx->r2 != 0) {
        // 0x80020948: addiu       $t2, $t2, 0x5
        ctx->r10 = ADD32(ctx->r10, 0X5);
            goto L_800208A0;
    }
    // 0x80020948: addiu       $t2, $t2, 0x5
    ctx->r10 = ADD32(ctx->r10, 0X5);
    // 0x8002094C: jr          $ra
    // 0x80020950: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    return;
    // 0x80020950: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
;}
