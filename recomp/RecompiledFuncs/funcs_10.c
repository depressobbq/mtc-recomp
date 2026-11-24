#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8002AD80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AD80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002AD84: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002AD88: jal         0x80012DD4
    // 0x8002AD8C: nop

    func_80012DD4(rdram, ctx);
        goto after_0;
    // 0x8002AD8C: nop

    after_0:
    // 0x8002AD90: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002AD94: jr          $ra
    // 0x8002AD98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002AD98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002AD9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AD9C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8002ADA0: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8002ADA4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8002ADA8: sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // 0x8002ADAC: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8002ADB0: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x8002ADB4: lb          $a2, 0x5($s1)
    ctx->r6 = MEM_B(ctx->r17, 0X5);
    // 0x8002ADB8: bne         $a2, $zero, L_8002AE04
    if (ctx->r6 != 0) {
        // 0x8002ADBC: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_8002AE04;
    }
    // 0x8002ADBC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8002ADC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002ADC4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002ADC8: lwc1        $f2, 0xC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8002ADCC: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8002ADD0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8002ADD4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8002ADD8: lbu         $v0, 0x1B($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1B);
    // 0x8002ADDC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8002ADE0: addiu       $a0, $a0, -0x2970
    ctx->r4 = ADD32(ctx->r4, -0X2970);
    // 0x8002ADE4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8002ADE8: lw          $a3, 0x1C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X1C);
    // 0x8002ADEC: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8002ADF0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8002ADF4: trunc.w.s   $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8002ADF8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8002ADFC: j           L_8002AF00
    // 0x8002AE00: nop

        goto L_8002AF00;
    // 0x8002AE00: nop

L_8002AE04:
    // 0x8002AE04: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x8002AE08: bne         $a2, $v0, L_8002AE44
    if (ctx->r6 != ctx->r2) {
        // 0x8002AE0C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002AE44;
    }
    // 0x8002AE0C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002AE10: lb          $v1, 0x2($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X2);
    // 0x8002AE14: bne         $v1, $v0, L_8002AE2C
    if (ctx->r3 != ctx->r2) {
        // 0x8002AE18: nop
    
            goto L_8002AE2C;
    }
    // 0x8002AE18: nop

    // 0x8002AE1C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002AE20: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8002AE24: j           L_8002AE44
    // 0x8002AE28: lbu         $a2, 0x73($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X73);
        goto L_8002AE44;
    // 0x8002AE28: lbu         $a2, 0x73($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X73);
L_8002AE2C:
    // 0x8002AE2C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8002AE30: addiu       $a1, $a1, -0x2964
    ctx->r5 = ADD32(ctx->r5, -0X2964);
    // 0x8002AE34: jal         0x80066CA0
    // 0x8002AE38: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_80066CA0(rdram, ctx);
        goto after_0;
    // 0x8002AE38: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x8002AE3C: j           L_8002AE54
    // 0x8002AE40: nop

        goto L_8002AE54;
    // 0x8002AE40: nop

L_8002AE44:
    // 0x8002AE44: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8002AE48: addiu       $a1, $a1, -0x2978
    ctx->r5 = ADD32(ctx->r5, -0X2978);
    // 0x8002AE4C: jal         0x80066CA0
    // 0x8002AE50: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_80066CA0(rdram, ctx);
        goto after_1;
    // 0x8002AE50: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_1:
L_8002AE54:
    // 0x8002AE54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002AE58: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8002AE5C: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8002AE60: lwc1        $f2, 0x10($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8002AE64: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8002AE68: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8002AE6C: lbu         $v0, 0x1B($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1B);
    // 0x8002AE70: addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // 0x8002AE74: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8002AE78: lw          $a3, 0x1C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X1C);
    // 0x8002AE7C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002AE80: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8002AE84: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8002AE88: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8002AE8C: nop

    // 0x8002AE90: jal         0x8004E008
    // 0x8002AE94: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8004E008(rdram, ctx);
        goto after_2;
    // 0x8002AE94: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8002AE98: lb          $v0, 0x5($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X5);
    // 0x8002AE9C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8002AEA0: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8002AEA4: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8002AEA8: lhu         $a2, -0x3FE2($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X3FE2);
    // 0x8002AEAC: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8002AEB0: addiu       $a1, $a1, -0x2974
    ctx->r5 = ADD32(ctx->r5, -0X2974);
    // 0x8002AEB4: jal         0x80066CA0
    // 0x8002AEB8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066CA0(rdram, ctx);
        goto after_3;
    // 0x8002AEB8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8002AEBC: jal         0x8002AF20
    // 0x8002AEC0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8002AF20(rdram, ctx);
        goto after_4;
    // 0x8002AEC0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8002AEC4: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8002AEC8: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8002AECC: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8002AED0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002AED4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8002AED8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8002AEDC: lbu         $v0, 0x1B($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1B);
    // 0x8002AEE0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8002AEE4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8002AEE8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8002AEEC: lw          $a3, 0x1C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X1C);
    // 0x8002AEF0: trunc.w.s   $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8002AEF4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8002AEF8: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002AEFC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_8002AF00:
    // 0x8002AF00: jal         0x8004E008
    // 0x8002AF04: nop

    func_8004E008(rdram, ctx);
        goto after_5;
    // 0x8002AF04: nop

    after_5:
    // 0x8002AF08: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x8002AF0C: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8002AF10: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8002AF14: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x8002AF18: jr          $ra
    // 0x8002AF1C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8002AF1C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8002AF20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AF20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002AF24: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002AF28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002AF2C: jal         0x80066C48
    // 0x8002AF30: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    strlen_recomp(rdram, ctx);
        goto after_0;
    // 0x8002AF30: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8002AF34: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8002AF38: addu        $a1, $s0, $a0
    ctx->r5 = ADD32(ctx->r16, ctx->r4);
    // 0x8002AF3C: lb          $v1, 0x0($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X0);
    // 0x8002AF40: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x8002AF44: beq         $v1, $v0, L_8002AF60
    if (ctx->r3 == ctx->r2) {
        // 0x8002AF48: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_8002AF60;
    }
    // 0x8002AF48: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x8002AF4C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
L_8002AF50:
    // 0x8002AF50: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8002AF54: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8002AF58: bne         $v0, $a2, L_8002AF50
    if (ctx->r2 != ctx->r6) {
        // 0x8002AF5C: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8002AF50;
    }
    // 0x8002AF5C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_8002AF60:
    // 0x8002AF60: addu        $v1, $s0, $a0
    ctx->r3 = ADD32(ctx->r16, ctx->r4);
    // 0x8002AF64: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x8002AF68: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8002AF6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002AF70: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002AF74: jr          $ra
    // 0x8002AF78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002AF78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002AF80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AF80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002AF84: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002AF88: lb          $v0, 0x5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5);
    // 0x8002AF8C: bne         $v0, $zero, L_8002AFA4
    if (ctx->r2 != 0) {
        // 0x8002AF90: nop
    
            goto L_8002AFA4;
    }
    // 0x8002AF90: nop

    // 0x8002AF94: jal         0x8002AFB8
    // 0x8002AF98: nop

    func_8002AFB8(rdram, ctx);
        goto after_0;
    // 0x8002AF98: nop

    after_0:
    // 0x8002AF9C: j           L_8002AFAC
    // 0x8002AFA0: nop

        goto L_8002AFAC;
    // 0x8002AFA0: nop

L_8002AFA4:
    // 0x8002AFA4: jal         0x8002B0E0
    // 0x8002AFA8: nop

    func_8002B0E0(rdram, ctx);
        goto after_1;
    // 0x8002AFA8: nop

    after_1:
L_8002AFAC:
    // 0x8002AFAC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002AFB0: jr          $ra
    // 0x8002AFB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002AFB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002AFB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AFB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002AFBC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002AFC0: lb          $v0, 0x2($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X2);
    // 0x8002AFC4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002AFC8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002AFCC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002AFD0: lw          $v0, 0x2BE0($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2BE0);
    // 0x8002AFD4: jalr        $v0
    // 0x8002AFD8: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8002AFD8: nop

    after_0:
    // 0x8002AFDC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002AFE0: jr          $ra
    // 0x8002AFE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002AFE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002AFE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AFE8: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8002AFEC: lbu         $a0, 0x2($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X2);
    // 0x8002AFF0: lwc1        $f0, 0xC($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8002AFF4: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    // 0x8002AFF8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002AFFC: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002B000: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8002B004: nop

    // 0x8002B008: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8002B00C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002B010: bgez        $v0, L_8002B01C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002B014: sb          $a0, 0x2($a2)
        MEM_B(0X2, ctx->r6) = ctx->r4;
            goto L_8002B01C;
    }
    // 0x8002B014: sb          $a0, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r4;
    // 0x8002B018: addiu       $v0, $v0, 0x1F
    ctx->r2 = ADD32(ctx->r2, 0X1F);
L_8002B01C:
    // 0x8002B01C: lwc1        $f0, 0x10($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X10);
    // 0x8002B020: lw          $v1, 0x28($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X28);
    // 0x8002B024: sra         $v0, $v0, 5
    ctx->r2 = S32(SIGNED(ctx->r2) >> 5);
    // 0x8002B028: sw          $v0, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r2;
    // 0x8002B02C: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002B030: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002B034: nop

    // 0x8002B038: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8002B03C: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8002B040: bltzl       $v0, L_8002B048
    if (SIGNED(ctx->r2) < 0) {
        // 0x8002B044: addiu       $v0, $v0, 0x1F
        ctx->r2 = ADD32(ctx->r2, 0X1F);
            goto L_8002B048;
    }
    goto skip_0;
    // 0x8002B044: addiu       $v0, $v0, 0x1F
    ctx->r2 = ADD32(ctx->r2, 0X1F);
    skip_0:
L_8002B048:
    // 0x8002B048: sra         $v0, $v0, 5
    ctx->r2 = S32(SIGNED(ctx->r2) >> 5);
    // 0x8002B04C: sw          $v0, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->r2;
    // 0x8002B050: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x8002B054: sw          $v0, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r2;
    // 0x8002B058: jr          $ra
    // 0x8002B05C: sb          $zero, 0x8($a2)
    MEM_B(0X8, ctx->r6) = 0;
    return;
    // 0x8002B05C: sb          $zero, 0x8($a2)
    MEM_B(0X8, ctx->r6) = 0;
;}
RECOMP_FUNC void func_8002B060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B060: lui         $at, 0x477F
    ctx->r1 = S32(0X477F << 16);
    // 0x8002B064: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x8002B068: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002B06C: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8002B070: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002B074: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8002B078: lwc1        $f2, 0x30($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8002B07C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8002B080: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8002B084: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8002B088: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8002B08C: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002B090: lw          $v0, 0x34($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X34);
    // 0x8002B094: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8002B098: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8002B09C: sw          $v0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r2;
    // 0x8002B0A0: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x8002B0A4: bne         $v0, $zero, L_8002B0D0
    if (ctx->r2 != 0) {
        // 0x8002B0A8: swc1        $f0, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
            goto L_8002B0D0;
    }
    // 0x8002B0A8: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x8002B0AC: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x8002B0B0: lwc1        $f0, 0x24($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8002B0B4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002B0B8: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x8002B0BC: lwc1        $f0, 0x28($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8002B0C0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002B0C4: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x8002B0C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002B0CC: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
L_8002B0D0:
    // 0x8002B0D0: jr          $ra
    // 0x8002B0D4: nop

    return;
    // 0x8002B0D4: nop

;}
RECOMP_FUNC void func_8002B0D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B0D8: jr          $ra
    // 0x8002B0DC: nop

    return;
    // 0x8002B0DC: nop

;}
RECOMP_FUNC void func_8002B0E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B0E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002B0E4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002B0E8: lb          $v0, 0x2($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X2);
    // 0x8002B0EC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002B0F0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002B0F4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002B0F8: lw          $v0, 0x2BEC($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2BEC);
    // 0x8002B0FC: jalr        $v0
    // 0x8002B100: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8002B100: nop

    after_0:
    // 0x8002B104: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002B108: jr          $ra
    // 0x8002B10C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002B10C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002B110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B110: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8002B114: lui         $at, 0x4338
    ctx->r1 = S32(0X4338 << 16);
    // 0x8002B118: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002B11C: lwc1        $f2, 0x10($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8002B120: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8002B124: nop

    // 0x8002B128: nop

    // 0x8002B12C: bc1f        L_8002B150
    if (!c1cs) {
        // 0x8002B130: addiu       $v1, $zero, 0x40
        ctx->r3 = ADD32(0, 0X40);
            goto L_8002B150;
    }
    // 0x8002B130: addiu       $v1, $zero, 0x40
    ctx->r3 = ADD32(0, 0X40);
    // 0x8002B134: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x8002B138: sw          $v1, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r3;
    // 0x8002B13C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002B140: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
    // 0x8002B144: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002B148: sb          $zero, 0x7B96($at)
    MEM_B(0X7B96, ctx->r1) = 0;
    // 0x8002B14C: sb          $zero, 0x8($a0)
    MEM_B(0X8, ctx->r4) = 0;
L_8002B150:
    // 0x8002B150: jr          $ra
    // 0x8002B154: nop

    return;
    // 0x8002B154: nop

;}
RECOMP_FUNC void func_8002B158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B158: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002B15C: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8002B160: lw          $v0, 0xB8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB8);
    // 0x8002B164: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8002B168: andi        $v0, $v1, 0x30
    ctx->r2 = ctx->r3 & 0X30;
    // 0x8002B16C: beq         $v0, $zero, L_8002B17C
    if (ctx->r2 == 0) {
        // 0x8002B170: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_8002B17C;
    }
    // 0x8002B170: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8002B174: j           L_8002B190
    // 0x8002B178: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
        goto L_8002B190;
    // 0x8002B178: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_8002B17C:
    // 0x8002B17C: andi        $v0, $v1, 0xC000
    ctx->r2 = ctx->r3 & 0XC000;
    // 0x8002B180: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8002B184: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8002B188: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8002B18C: ori         $a2, $v0, 0x2
    ctx->r6 = ctx->r2 | 0X2;
L_8002B190:
    // 0x8002B190: lw          $v0, 0x34($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X34);
    // 0x8002B194: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x8002B198: div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // 0x8002B19C: bne         $a2, $zero, L_8002B1A8
    if (ctx->r6 != 0) {
        // 0x8002B1A0: nop
    
            goto L_8002B1A8;
    }
    // 0x8002B1A0: nop

    // 0x8002B1A4: break       7
    do_break(2147660196);
L_8002B1A8:
    // 0x8002B1A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002B1AC: bne         $a2, $at, L_8002B1C0
    if (ctx->r6 != ctx->r1) {
        // 0x8002B1B0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8002B1C0;
    }
    // 0x8002B1B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002B1B4: bne         $v0, $at, L_8002B1C0
    if (ctx->r2 != ctx->r1) {
        // 0x8002B1B8: nop
    
            goto L_8002B1C0;
    }
    // 0x8002B1B8: nop

    // 0x8002B1BC: break       6
    do_break(2147660220);
L_8002B1C0:
    // 0x8002B1C0: mflo        $a2
    ctx->r6 = lo;
    // 0x8002B1C4: nop

    // 0x8002B1C8: nop

    // 0x8002B1CC: bgtz        $a2, L_8002B1D8
    if (SIGNED(ctx->r6) > 0) {
        // 0x8002B1D0: sw          $v0, 0x34($a1)
        MEM_W(0X34, ctx->r5) = ctx->r2;
            goto L_8002B1D8;
    }
    // 0x8002B1D0: sw          $v0, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r2;
    // 0x8002B1D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8002B1D8:
    // 0x8002B1D8: lw          $a3, 0x24($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X24);
    // 0x8002B1DC: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8002B1E0: lwc1        $f2, 0xC($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8002B1E4: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002B1E8: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8002B1EC: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8002B1F0: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8002B1F4: nop

    // 0x8002B1F8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8002B1FC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002B200: div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // 0x8002B204: bne         $a2, $zero, L_8002B210
    if (ctx->r6 != 0) {
        // 0x8002B208: nop
    
            goto L_8002B210;
    }
    // 0x8002B208: nop

    // 0x8002B20C: break       7
    do_break(2147660300);
L_8002B210:
    // 0x8002B210: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002B214: bne         $a2, $at, L_8002B228
    if (ctx->r6 != ctx->r1) {
        // 0x8002B218: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8002B228;
    }
    // 0x8002B218: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002B21C: bne         $v0, $at, L_8002B228
    if (ctx->r2 != ctx->r1) {
        // 0x8002B220: nop
    
            goto L_8002B228;
    }
    // 0x8002B220: nop

    // 0x8002B224: break       6
    do_break(2147660324);
L_8002B228:
    // 0x8002B228: mflo        $v0
    ctx->r2 = lo;
    // 0x8002B22C: sw          $v0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r2;
    // 0x8002B230: lwc1        $f0, 0x10($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8002B234: lwc1        $f2, 0x10($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8002B238: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002B23C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8002B240: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8002B244: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8002B248: nop

    // 0x8002B24C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8002B250: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002B254: div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // 0x8002B258: bne         $a2, $zero, L_8002B264
    if (ctx->r6 != 0) {
        // 0x8002B25C: nop
    
            goto L_8002B264;
    }
    // 0x8002B25C: nop

    // 0x8002B260: break       7
    do_break(2147660384);
L_8002B264:
    // 0x8002B264: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002B268: bne         $a2, $at, L_8002B27C
    if (ctx->r6 != ctx->r1) {
        // 0x8002B26C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8002B27C;
    }
    // 0x8002B26C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002B270: bne         $v0, $at, L_8002B27C
    if (ctx->r2 != ctx->r1) {
        // 0x8002B274: nop
    
            goto L_8002B27C;
    }
    // 0x8002B274: nop

    // 0x8002B278: break       6
    do_break(2147660408);
L_8002B27C:
    // 0x8002B27C: mflo        $v0
    ctx->r2 = lo;
    // 0x8002B280: lui         $at, 0x477F
    ctx->r1 = S32(0X477F << 16);
    // 0x8002B284: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x8002B288: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002B28C: lwc1        $f0, 0x2C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8002B290: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002B294: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8002B298: sw          $v0, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r2;
    // 0x8002B29C: lwc1        $f4, 0x30($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X30);
    // 0x8002B2A0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002B2A4: div.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8002B2A8: lwc1        $f2, 0xC($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8002B2AC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8002B2B0: lwc1        $f0, 0x10($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8002B2B4: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8002B2B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002B2BC: swc1        $f2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f2.u32l;
    // 0x8002B2C0: bne         $a2, $v0, L_8002B31C
    if (ctx->r6 != ctx->r2) {
        // 0x8002B2C4: swc1        $f0, 0x10($a1)
        MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
            goto L_8002B31C;
    }
    // 0x8002B2C4: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x8002B2C8: lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2);
    // 0x8002B2CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002B2D0: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    // 0x8002B2D4: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8002B2D8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8002B2DC: sw          $v0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r2;
    // 0x8002B2E0: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002B2E4: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002B2E8: nop

    // 0x8002B2EC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8002B2F0: nop

    // 0x8002B2F4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002B2F8: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x8002B2FC: lwc1        $f0, 0x10($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8002B300: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002B304: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002B308: nop

    // 0x8002B30C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8002B310: nop

    // 0x8002B314: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002B318: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
L_8002B31C:
    // 0x8002B31C: jr          $ra
    // 0x8002B320: nop

    return;
    // 0x8002B320: nop

;}
RECOMP_FUNC void func_8002B324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B324: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002B328: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002B32C: jal         0x80012DD4
    // 0x8002B330: nop

    func_80012DD4(rdram, ctx);
        goto after_0;
    // 0x8002B330: nop

    after_0:
    // 0x8002B334: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002B338: jr          $ra
    // 0x8002B33C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002B33C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002B340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B340: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002B344: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002B348: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002B34C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x8002B350: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8002B354: lwc1        $f2, 0xC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8002B358: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8002B35C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8002B360: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8002B364: lbu         $v0, 0x1B($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1B);
    // 0x8002B368: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8002B36C: lw          $a0, 0x20($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X20);
    // 0x8002B370: lw          $a3, 0x1C($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X1C);
    // 0x8002B374: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8002B378: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8002B37C: trunc.w.s   $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8002B380: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8002B384: jal         0x8004E008
    // 0x8002B388: nop

    func_8004E008(rdram, ctx);
        goto after_0;
    // 0x8002B388: nop

    after_0:
    // 0x8002B38C: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8002B390: jr          $ra
    // 0x8002B394: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8002B394: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8002B3A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B3A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002B3A4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002B3A8: lb          $v0, 0x2($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X2);
    // 0x8002B3AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002B3B0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002B3B4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002B3B8: lw          $v0, 0x2C00($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2C00);
    // 0x8002B3BC: jalr        $v0
    // 0x8002B3C0: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8002B3C0: nop

    after_0:
    // 0x8002B3C4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002B3C8: jr          $ra
    // 0x8002B3CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002B3CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002B3D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B3D0: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8002B3D4: lui         $at, 0x4376
    ctx->r1 = S32(0X4376 << 16);
    // 0x8002B3D8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002B3DC: lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X2);
    // 0x8002B3E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002B3E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002B3E8: lw          $a0, 0x18($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X18);
    // 0x8002B3EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002B3F0: sb          $zero, 0x7($a1)
    MEM_B(0X7, ctx->r5) = 0;
    // 0x8002B3F4: sh          $zero, 0xA($a1)
    MEM_H(0XA, ctx->r5) = 0;
    // 0x8002B3F8: sb          $v0, 0x8($a1)
    MEM_B(0X8, ctx->r5) = ctx->r2;
    // 0x8002B3FC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002B400: sb          $v1, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r3;
    // 0x8002B404: bne         $a0, $zero, L_8002B414
    if (ctx->r4 != 0) {
        // 0x8002B408: swc1        $f0, 0x14($a1)
        MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
            goto L_8002B414;
    }
    // 0x8002B408: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x8002B40C: lui         $at, 0x4294
    ctx->r1 = S32(0X4294 << 16);
    // 0x8002B410: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_8002B414:
    // 0x8002B414: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
    // 0x8002B418: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002B41C: lb          $v0, 0x5($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X5);
    // 0x8002B420: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x8002B424: swc1        $f2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f2.u32l;
    // 0x8002B428: bne         $v0, $zero, L_8002B434
    if (ctx->r2 != 0) {
        // 0x8002B42C: swc1        $f0, 0x10($a1)
        MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
            goto L_8002B434;
    }
    // 0x8002B42C: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x8002B430: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_8002B434:
    // 0x8002B434: sb          $v1, 0x6($a1)
    MEM_B(0X6, ctx->r5) = ctx->r3;
    // 0x8002B438: jr          $ra
    // 0x8002B43C: sw          $zero, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = 0;
    return;
    // 0x8002B43C: sw          $zero, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = 0;
;}
RECOMP_FUNC void func_8002B440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B440: lhu         $v0, 0xA($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XA);
    // 0x8002B444: lbu         $v1, 0x7($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X7);
    // 0x8002B448: addiu       $v0, $v0, 0x7FF
    ctx->r2 = ADD32(ctx->r2, 0X7FF);
    // 0x8002B44C: sh          $v0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r2;
    // 0x8002B450: sltiu       $v0, $v1, 0xF1
    ctx->r2 = ctx->r3 < 0XF1 ? 1 : 0;
    // 0x8002B454: bne         $v0, $zero, L_8002B460
    if (ctx->r2 != 0) {
        // 0x8002B458: addiu       $v0, $v1, 0x8
        ctx->r2 = ADD32(ctx->r3, 0X8);
            goto L_8002B460;
    }
    // 0x8002B458: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8002B45C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8002B460:
    // 0x8002B460: lwc1        $f0, 0x14($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8002B464: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002B468: ldc1        $f2, -0x2960($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2960);
    // 0x8002B46C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8002B470: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8002B474: sb          $v0, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r2;
    // 0x8002B478: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8002B47C: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x8002B480: lwc1        $f0, 0x14($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8002B484: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002B488: ldc1        $f2, -0x2958($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2958);
    // 0x8002B48C: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x8002B490: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8002B494: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x8002B498: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002B49C: nop

    // 0x8002B4A0: bc1f        L_8002B4D4
    if (!c1cs) {
        // 0x8002B4A4: sw          $v0, 0x1C($a0)
        MEM_W(0X1C, ctx->r4) = ctx->r2;
            goto L_8002B4D4;
    }
    // 0x8002B4A4: sw          $v0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r2;
    // 0x8002B4A8: lbu         $v1, 0x2($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X2);
    // 0x8002B4AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002B4B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002B4B4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8002B4B8: sw          $v0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r2;
    // 0x8002B4BC: sw          $v0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r2;
    // 0x8002B4C0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8002B4C4: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
    // 0x8002B4C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002B4CC: sb          $v1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r3;
    // 0x8002B4D0: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
L_8002B4D4:
    // 0x8002B4D4: jr          $ra
    // 0x8002B4D8: nop

    return;
    // 0x8002B4D8: nop

;}
RECOMP_FUNC void func_8002B4DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B4DC: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8002B4E0: lw          $v1, 0x20($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X20);
    // 0x8002B4E4: lui         $a0, 0xB60B
    ctx->r4 = S32(0XB60B << 16);
    // 0x8002B4E8: ori         $a0, $a0, 0x60B7
    ctx->r4 = ctx->r4 | 0X60B7;
    // 0x8002B4EC: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x8002B4F0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8002B4F4: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002B4F8: lw          $a1, 0x28($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X28);
    // 0x8002B4FC: lhu         $a0, 0xA($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0XA);
    // 0x8002B500: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8002B504: sw          $a1, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r5;
    // 0x8002B508: mfhi        $a3
    ctx->r7 = hi;
    // 0x8002B50C: addu        $v1, $a3, $v0
    ctx->r3 = ADD32(ctx->r7, ctx->r2);
    // 0x8002B510: sra         $v1, $v1, 8
    ctx->r3 = S32(SIGNED(ctx->r3) >> 8);
    // 0x8002B514: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8002B518: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8002B51C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8002B520: bne         $a1, $zero, L_8002B56C
    if (ctx->r5 != 0) {
        // 0x8002B524: sh          $a0, 0xA($a2)
        MEM_H(0XA, ctx->r6) = ctx->r4;
            goto L_8002B56C;
    }
    // 0x8002B524: sh          $a0, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r4;
    // 0x8002B528: lw          $v1, 0x20($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X20);
    // 0x8002B52C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8002B530: bltz        $v1, L_8002B540
    if (SIGNED(ctx->r3) < 0) {
        // 0x8002B534: sw          $v0, 0x28($a2)
        MEM_W(0X28, ctx->r6) = ctx->r2;
            goto L_8002B540;
    }
    // 0x8002B534: sw          $v0, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r2;
    // 0x8002B538: j           L_8002B548
    // 0x8002B53C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_8002B548;
    // 0x8002B53C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_8002B540:
    // 0x8002B540: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    // 0x8002B544: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8002B548:
    // 0x8002B548: sw          $v0, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r2;
    // 0x8002B54C: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    // 0x8002B550: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8002B554: bne         $v0, $zero, L_8002B56C
    if (ctx->r2 != 0) {
        // 0x8002B558: sw          $v0, 0x24($a2)
        MEM_W(0X24, ctx->r6) = ctx->r2;
            goto L_8002B56C;
    }
    // 0x8002B558: sw          $v0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r2;
    // 0x8002B55C: lbu         $v0, 0x2($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X2);
    // 0x8002B560: sh          $zero, 0xA($a2)
    MEM_H(0XA, ctx->r6) = 0;
    // 0x8002B564: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002B568: sb          $v0, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r2;
L_8002B56C:
    // 0x8002B56C: jr          $ra
    // 0x8002B570: nop

    return;
    // 0x8002B570: nop

;}
RECOMP_FUNC void func_8002B574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B574: lb          $v0, 0x5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5);
    // 0x8002B578: bne         $v0, $zero, L_8002B598
    if (ctx->r2 != 0) {
        // 0x8002B57C: nop
    
            goto L_8002B598;
    }
    // 0x8002B57C: nop

    // 0x8002B580: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002B584: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002B588: ldc1        $f2, -0x2950($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2950);
    // 0x8002B58C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8002B590: j           L_8002B5AC
    // 0x8002B594: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
        goto L_8002B5AC;
    // 0x8002B594: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
L_8002B598:
    // 0x8002B598: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002B59C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002B5A0: ldc1        $f2, -0x2948($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2948);
    // 0x8002B5A4: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8002B5A8: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
L_8002B5AC:
    // 0x8002B5AC: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8002B5B0: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x8002B5B4: lbu         $v0, 0x7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X7);
    // 0x8002B5B8: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8002B5BC: sb          $v0, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r2;
    // 0x8002B5C0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8002B5C4: sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // 0x8002B5C8: beq         $v0, $zero, L_8002B5E0
    if (ctx->r2 == 0) {
        // 0x8002B5CC: nop
    
            goto L_8002B5E0;
    }
    // 0x8002B5CC: nop

    // 0x8002B5D0: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x8002B5D4: sb          $zero, 0x7($a0)
    MEM_B(0X7, ctx->r4) = 0;
    // 0x8002B5D8: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8002B5DC: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
L_8002B5E0:
    // 0x8002B5E0: jr          $ra
    // 0x8002B5E4: nop

    return;
    // 0x8002B5E4: nop

;}
RECOMP_FUNC void func_8002B5E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B5E8: lb          $v0, 0x5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5);
    // 0x8002B5EC: bne         $v0, $zero, L_8002B60C
    if (ctx->r2 != 0) {
        // 0x8002B5F0: nop
    
            goto L_8002B60C;
    }
    // 0x8002B5F0: nop

    // 0x8002B5F4: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002B5F8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002B5FC: ldc1        $f2, -0x2940($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2940);
    // 0x8002B600: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8002B604: j           L_8002B620
    // 0x8002B608: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
        goto L_8002B620;
    // 0x8002B608: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
L_8002B60C:
    // 0x8002B60C: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002B610: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002B614: ldc1        $f2, -0x2938($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2938);
    // 0x8002B618: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8002B61C: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
L_8002B620:
    // 0x8002B620: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8002B624: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x8002B628: lwc1        $f0, 0x14($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8002B62C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002B630: ldc1        $f2, -0x2930($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2930);
    // 0x8002B634: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8002B638: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8002B63C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002B640: ldc1        $f4, -0x2928($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2928);
    // 0x8002B644: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8002B648: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x8002B64C: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x8002B650: nop

    // 0x8002B654: nop

    // 0x8002B658: bc1f        L_8002B66C
    if (!c1cs) {
        // 0x8002B65C: swc1        $f0, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
            goto L_8002B66C;
    }
    // 0x8002B65C: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x8002B660: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x8002B664: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002B668: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
L_8002B66C:
    // 0x8002B66C: jr          $ra
    // 0x8002B670: nop

    return;
    // 0x8002B670: nop

;}
RECOMP_FUNC void func_8002B674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B674: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002B678: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002B67C: jal         0x80012DD4
    // 0x8002B680: nop

    func_80012DD4(rdram, ctx);
        goto after_0;
    // 0x8002B680: nop

    after_0:
    // 0x8002B684: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002B688: jr          $ra
    // 0x8002B68C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002B68C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002B690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B690: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8002B694: lw          $v0, -0x34C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34C0);
    // 0x8002B698: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8002B69C: lw          $a1, 0x4470($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4470);
    // 0x8002B6A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002B6A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002B6A8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8002B6AC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002B6B0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002B6B4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002B6B8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002B6BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002B6C0: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    // 0x8002B6C4: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8002B6C8: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8002B6CC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8002B6D0: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x8002B6D4: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x8002B6D8: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8002B6DC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8002B6E0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002B6E4: addiu       $v0, $v0, 0x4580
    ctx->r2 = ADD32(ctx->r2, 0X4580);
    // 0x8002B6E8: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8002B6EC: addu        $s1, $a0, $v0
    ctx->r17 = ADD32(ctx->r4, ctx->r2);
    // 0x8002B6F0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002B6F4: addiu       $v0, $v0, 0x1230
    ctx->r2 = ADD32(ctx->r2, 0X1230);
    // 0x8002B6F8: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8002B6FC: addu        $s2, $a0, $v0
    ctx->r18 = ADD32(ctx->r4, ctx->r2);
    // 0x8002B700: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x8002B704: addiu       $v0, $v0, -0x7540
    ctx->r2 = ADD32(ctx->r2, -0X7540);
    // 0x8002B708: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8002B70C: addu        $s4, $a0, $v0
    ctx->r20 = ADD32(ctx->r4, ctx->r2);
    // 0x8002B710: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002B714: addiu       $v0, $v0, 0x26E0
    ctx->r2 = ADD32(ctx->r2, 0X26E0);
    // 0x8002B718: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002B71C: slti        $a1, $a1, 0x4C
    ctx->r5 = SIGNED(ctx->r5) < 0X4C ? 1 : 0;
    // 0x8002B720: beq         $a1, $zero, L_8002B9BC
    if (ctx->r5 == 0) {
        // 0x8002B724: addu        $s3, $a0, $v1
        ctx->r19 = ADD32(ctx->r4, ctx->r3);
            goto L_8002B9BC;
    }
    // 0x8002B724: addu        $s3, $a0, $v1
    ctx->r19 = ADD32(ctx->r4, ctx->r3);
    // 0x8002B728: lbu         $a0, 0x6($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X6);
    // 0x8002B72C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8002B730: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8002B734: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // 0x8002B738: jal         0x800178E0
    // 0x8002B73C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_800178E0(rdram, ctx);
        goto after_0;
    // 0x8002B73C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_0:
    // 0x8002B740: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x8002B744: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8002B748: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8002B74C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8002B750: nop

    // 0x8002B754: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002B758: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8002B75C: lhu         $v1, 0xC($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XC);
    // 0x8002B760: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002B764: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002B768: nop

    // 0x8002B76C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002B770: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x8002B774: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8002B778: srl         $v1, $v1, 5
    ctx->r3 = S32(U32(ctx->r3) >> 5);
    // 0x8002B77C: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8002B780: nop

    // 0x8002B784: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002B788: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8002B78C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002B790: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002B794: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8002B798: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8002B79C: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002B7A0: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002B7A4: nop

    // 0x8002B7A8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002B7AC: sh          $v0, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r2;
    // 0x8002B7B0: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8002B7B4: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8002B7B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002B7BC: nop

    // 0x8002B7C0: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8002B7C4: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002B7C8: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002B7CC: nop

    // 0x8002B7D0: sh          $v0, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r2;
    // 0x8002B7D4: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // 0x8002B7D8: lhu         $a1, 0xA($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XA);
    // 0x8002B7DC: jal         0x80018514
    // 0x8002B7E0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80018514(rdram, ctx);
        goto after_1;
    // 0x8002B7E0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_1:
    // 0x8002B7E4: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x8002B7E8: ori         $a0, $a0, 0x1402
    ctx->r4 = ctx->r4 | 0X1402;
    // 0x8002B7EC: lui         $t0, 0xFC11
    ctx->r8 = S32(0XFC11 << 16);
    // 0x8002B7F0: ori         $t0, $t0, 0x9623
    ctx->r8 = ctx->r8 | 0X9623;
    // 0x8002B7F4: lui         $a3, 0xFF2F
    ctx->r7 = S32(0XFF2F << 16);
    // 0x8002B7F8: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x8002B7FC: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x8002B800: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x8002B804: lui         $t1, 0x40
    ctx->r9 = S32(0X40 << 16);
    // 0x8002B808: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8002B80C: ori         $t1, $t1, 0x4240
    ctx->r9 = ctx->r9 | 0X4240;
    // 0x8002B810: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x8002B814: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002B818: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002B81C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002B820: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8002B824: ori         $t3, $t3, 0xE02
    ctx->r11 = ctx->r11 | 0XE02;
    // 0x8002B828: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002B82C: sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // 0x8002B830: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8002B834: lui         $a2, 0xC100
    ctx->r6 = S32(0XC100 << 16);
    // 0x8002B838: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8002B83C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002B840: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002B844: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8002B848: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002B84C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002B850: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8002B854: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002B858: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002B85C: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x8002B860: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002B864: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002B868: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x8002B86C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002B870: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002B874: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002B878: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002B87C: nop

    // 0x8002B880: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002B884: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x8002B888: sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // 0x8002B88C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002B890: addiu       $v0, $v0, -0x6790
    ctx->r2 = ADD32(ctx->r2, -0X6790);
    // 0x8002B894: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8002B898: lui         $v0, 0xB100
    ctx->r2 = S32(0XB100 << 16);
    // 0x8002B89C: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x8002B8A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002B8A4: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x8002B8A8: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x8002B8AC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8002B8B0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8002B8B4: sw          $a1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r5;
    // 0x8002B8B8: sw          $t0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r8;
    // 0x8002B8BC: sw          $a3, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r7;
    // 0x8002B8C0: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // 0x8002B8C4: lbu         $a0, 0x7($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X7);
    // 0x8002B8C8: ori         $a2, $a2, 0x17
    ctx->r6 = ctx->r6 | 0X17;
    // 0x8002B8CC: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x8002B8D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002B8D4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002B8D8: addiu       $v0, $v1, 0x38
    ctx->r2 = ADD32(ctx->r3, 0X38);
    // 0x8002B8DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002B8E0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002B8E4: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x8002B8E8: sw          $v0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r2;
    // 0x8002B8EC: addiu       $v0, $v1, 0x40
    ctx->r2 = ADD32(ctx->r3, 0X40);
    // 0x8002B8F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002B8F4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002B8F8: addiu       $v0, $v1, 0x48
    ctx->r2 = ADD32(ctx->r3, 0X48);
    // 0x8002B8FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002B900: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002B904: addiu       $v0, $zero, -0x100
    ctx->r2 = ADD32(0, -0X100);
    // 0x8002B908: sw          $t2, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r10;
    // 0x8002B90C: sw          $t1, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r9;
    // 0x8002B910: sw          $t3, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r11;
    // 0x8002B914: sw          $a2, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r6;
    // 0x8002B918: sw          $s3, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r19;
    // 0x8002B91C: sw          $a2, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r6;
    // 0x8002B920: sw          $s4, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r20;
    // 0x8002B924: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x8002B928: addiu       $v0, $v1, 0x50
    ctx->r2 = ADD32(ctx->r3, 0X50);
    // 0x8002B92C: sw          $a0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r4;
    // 0x8002B930: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002B934: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002B938: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8002B93C: lw          $a0, 0x4470($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4470);
    // 0x8002B940: lui         $v0, 0x517
    ctx->r2 = S32(0X517 << 16);
    // 0x8002B944: sw          $v0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r2;
    // 0x8002B948: addiu       $v0, $v1, 0x58
    ctx->r2 = ADD32(ctx->r3, 0X58);
    // 0x8002B94C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002B950: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002B954: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x8002B958: sw          $v0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r2;
    // 0x8002B95C: addiu       $v0, $v1, 0x60
    ctx->r2 = ADD32(ctx->r3, 0X60);
    // 0x8002B960: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002B964: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002B968: addiu       $v0, $v1, 0x68
    ctx->r2 = ADD32(ctx->r3, 0X68);
    // 0x8002B96C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002B970: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002B974: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002B978: addiu       $v0, $v0, -0x6850
    ctx->r2 = ADD32(ctx->r2, -0X6850);
    // 0x8002B97C: sw          $v0, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r2;
    // 0x8002B980: addiu       $v0, $v1, 0x70
    ctx->r2 = ADD32(ctx->r3, 0X70);
    // 0x8002B984: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002B988: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002B98C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002B990: addiu       $v0, $v0, -0x6858
    ctx->r2 = ADD32(ctx->r2, -0X6858);
    // 0x8002B994: sw          $s2, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r18;
    // 0x8002B998: sw          $s1, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r17;
    // 0x8002B99C: sw          $t3, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r11;
    // 0x8002B9A0: sw          $zero, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = 0;
    // 0x8002B9A4: sw          $a1, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r5;
    // 0x8002B9A8: sw          $a1, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->r5;
    // 0x8002B9AC: sw          $v0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r2;
    // 0x8002B9B0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002B9B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002B9B8: sw          $a0, 0x4470($at)
    MEM_W(0X4470, ctx->r1) = ctx->r4;
L_8002B9BC:
    // 0x8002B9BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002B9C0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002B9C4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002B9C8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002B9CC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002B9D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002B9D4: jr          $ra
    // 0x8002B9D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002B9D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8002B9DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B9DC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8002B9E0: lw          $v0, -0x34C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34C0);
    // 0x8002B9E4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8002B9E8: lw          $a1, 0x4470($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4470);
    // 0x8002B9EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002B9F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002B9F4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8002B9F8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002B9FC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002BA00: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002BA04: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002BA08: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002BA0C: sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2 << 3);
    // 0x8002BA10: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8002BA14: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8002BA18: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8002BA1C: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x8002BA20: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x8002BA24: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8002BA28: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8002BA2C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002BA30: addiu       $v0, $v0, 0x4580
    ctx->r2 = ADD32(ctx->r2, 0X4580);
    // 0x8002BA34: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8002BA38: addu        $s1, $a0, $v0
    ctx->r17 = ADD32(ctx->r4, ctx->r2);
    // 0x8002BA3C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002BA40: addiu       $v0, $v0, 0x1230
    ctx->r2 = ADD32(ctx->r2, 0X1230);
    // 0x8002BA44: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8002BA48: addu        $s2, $a0, $v0
    ctx->r18 = ADD32(ctx->r4, ctx->r2);
    // 0x8002BA4C: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x8002BA50: addiu       $v0, $v0, -0x7540
    ctx->r2 = ADD32(ctx->r2, -0X7540);
    // 0x8002BA54: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8002BA58: addu        $s4, $a0, $v0
    ctx->r20 = ADD32(ctx->r4, ctx->r2);
    // 0x8002BA5C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002BA60: addiu       $v0, $v0, 0x26E0
    ctx->r2 = ADD32(ctx->r2, 0X26E0);
    // 0x8002BA64: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002BA68: slti        $a1, $a1, 0x4C
    ctx->r5 = SIGNED(ctx->r5) < 0X4C ? 1 : 0;
    // 0x8002BA6C: beq         $a1, $zero, L_8002BD10
    if (ctx->r5 == 0) {
        // 0x8002BA70: addu        $s3, $a0, $v1
        ctx->r19 = ADD32(ctx->r4, ctx->r3);
            goto L_8002BD10;
    }
    // 0x8002BA70: addu        $s3, $a0, $v1
    ctx->r19 = ADD32(ctx->r4, ctx->r3);
    // 0x8002BA74: lbu         $a0, 0x6($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X6);
    // 0x8002BA78: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8002BA7C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8002BA80: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // 0x8002BA84: jal         0x800178E0
    // 0x8002BA88: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    func_800178E0(rdram, ctx);
        goto after_0;
    // 0x8002BA88: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_0:
    // 0x8002BA8C: lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X4);
    // 0x8002BA90: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8002BA94: srl         $v0, $v0, 5
    ctx->r2 = S32(U32(ctx->r2) >> 5);
    // 0x8002BA98: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8002BA9C: nop

    // 0x8002BAA0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002BAA4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8002BAA8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002BAAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002BAB0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8002BAB4: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8002BAB8: lhu         $v1, 0xC($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XC);
    // 0x8002BABC: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002BAC0: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002BAC4: nop

    // 0x8002BAC8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002BACC: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x8002BAD0: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8002BAD4: srl         $v1, $v1, 5
    ctx->r3 = S32(U32(ctx->r3) >> 5);
    // 0x8002BAD8: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8002BADC: nop

    // 0x8002BAE0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002BAE4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8002BAE8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8002BAEC: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8002BAF0: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002BAF4: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002BAF8: nop

    // 0x8002BAFC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002BB00: sh          $v0, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r2;
    // 0x8002BB04: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8002BB08: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8002BB0C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002BB10: nop

    // 0x8002BB14: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8002BB18: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002BB1C: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002BB20: nop

    // 0x8002BB24: sh          $v0, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r2;
    // 0x8002BB28: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // 0x8002BB2C: lhu         $a1, 0xA($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XA);
    // 0x8002BB30: jal         0x80018514
    // 0x8002BB34: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80018514(rdram, ctx);
        goto after_1;
    // 0x8002BB34: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_1:
    // 0x8002BB38: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x8002BB3C: ori         $a0, $a0, 0x1402
    ctx->r4 = ctx->r4 | 0X1402;
    // 0x8002BB40: lui         $t0, 0xFC11
    ctx->r8 = S32(0XFC11 << 16);
    // 0x8002BB44: ori         $t0, $t0, 0x9623
    ctx->r8 = ctx->r8 | 0X9623;
    // 0x8002BB48: lui         $a3, 0xFF2F
    ctx->r7 = S32(0XFF2F << 16);
    // 0x8002BB4C: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x8002BB50: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x8002BB54: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x8002BB58: lui         $t1, 0x40
    ctx->r9 = S32(0X40 << 16);
    // 0x8002BB5C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8002BB60: ori         $t1, $t1, 0x4240
    ctx->r9 = ctx->r9 | 0X4240;
    // 0x8002BB64: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x8002BB68: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002BB6C: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002BB70: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002BB74: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8002BB78: ori         $t3, $t3, 0xE02
    ctx->r11 = ctx->r11 | 0XE02;
    // 0x8002BB7C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002BB80: sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // 0x8002BB84: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8002BB88: lui         $a2, 0xC100
    ctx->r6 = S32(0XC100 << 16);
    // 0x8002BB8C: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8002BB90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002BB94: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002BB98: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8002BB9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002BBA0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002BBA4: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8002BBA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002BBAC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002BBB0: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x8002BBB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002BBB8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002BBBC: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x8002BBC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002BBC4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002BBC8: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8002BBCC: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8002BBD0: nop

    // 0x8002BBD4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002BBD8: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x8002BBDC: sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // 0x8002BBE0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002BBE4: addiu       $v0, $v0, -0x6790
    ctx->r2 = ADD32(ctx->r2, -0X6790);
    // 0x8002BBE8: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8002BBEC: lui         $v0, 0xB100
    ctx->r2 = S32(0XB100 << 16);
    // 0x8002BBF0: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x8002BBF4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002BBF8: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x8002BBFC: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x8002BC00: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8002BC04: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8002BC08: sw          $a1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r5;
    // 0x8002BC0C: sw          $t0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r8;
    // 0x8002BC10: sw          $a3, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r7;
    // 0x8002BC14: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // 0x8002BC18: lbu         $a0, 0x7($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X7);
    // 0x8002BC1C: ori         $a2, $a2, 0x17
    ctx->r6 = ctx->r6 | 0X17;
    // 0x8002BC20: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x8002BC24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002BC28: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002BC2C: addiu       $v0, $v1, 0x38
    ctx->r2 = ADD32(ctx->r3, 0X38);
    // 0x8002BC30: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002BC34: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002BC38: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x8002BC3C: sw          $v0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r2;
    // 0x8002BC40: addiu       $v0, $v1, 0x40
    ctx->r2 = ADD32(ctx->r3, 0X40);
    // 0x8002BC44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002BC48: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002BC4C: addiu       $v0, $v1, 0x48
    ctx->r2 = ADD32(ctx->r3, 0X48);
    // 0x8002BC50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002BC54: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002BC58: addiu       $v0, $zero, -0x100
    ctx->r2 = ADD32(0, -0X100);
    // 0x8002BC5C: sw          $t2, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r10;
    // 0x8002BC60: sw          $t1, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r9;
    // 0x8002BC64: sw          $t3, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r11;
    // 0x8002BC68: sw          $a2, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r6;
    // 0x8002BC6C: sw          $s3, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r19;
    // 0x8002BC70: sw          $a2, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r6;
    // 0x8002BC74: sw          $s4, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r20;
    // 0x8002BC78: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x8002BC7C: addiu       $v0, $v1, 0x50
    ctx->r2 = ADD32(ctx->r3, 0X50);
    // 0x8002BC80: sw          $a0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r4;
    // 0x8002BC84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002BC88: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002BC8C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8002BC90: lw          $a0, 0x4470($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4470);
    // 0x8002BC94: lui         $v0, 0x517
    ctx->r2 = S32(0X517 << 16);
    // 0x8002BC98: sw          $v0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r2;
    // 0x8002BC9C: addiu       $v0, $v1, 0x58
    ctx->r2 = ADD32(ctx->r3, 0X58);
    // 0x8002BCA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002BCA4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002BCA8: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x8002BCAC: sw          $v0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r2;
    // 0x8002BCB0: addiu       $v0, $v1, 0x60
    ctx->r2 = ADD32(ctx->r3, 0X60);
    // 0x8002BCB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002BCB8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002BCBC: addiu       $v0, $v1, 0x68
    ctx->r2 = ADD32(ctx->r3, 0X68);
    // 0x8002BCC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002BCC4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002BCC8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002BCCC: addiu       $v0, $v0, -0x6850
    ctx->r2 = ADD32(ctx->r2, -0X6850);
    // 0x8002BCD0: sw          $v0, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r2;
    // 0x8002BCD4: addiu       $v0, $v1, 0x70
    ctx->r2 = ADD32(ctx->r3, 0X70);
    // 0x8002BCD8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002BCDC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002BCE0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002BCE4: addiu       $v0, $v0, -0x6858
    ctx->r2 = ADD32(ctx->r2, -0X6858);
    // 0x8002BCE8: sw          $s2, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r18;
    // 0x8002BCEC: sw          $s1, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r17;
    // 0x8002BCF0: sw          $t3, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r11;
    // 0x8002BCF4: sw          $zero, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = 0;
    // 0x8002BCF8: sw          $a1, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r5;
    // 0x8002BCFC: sw          $a1, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->r5;
    // 0x8002BD00: sw          $v0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->r2;
    // 0x8002BD04: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002BD08: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002BD0C: sw          $a0, 0x4470($at)
    MEM_W(0X4470, ctx->r1) = ctx->r4;
L_8002BD10:
    // 0x8002BD10: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002BD14: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002BD18: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002BD1C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002BD20: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002BD24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002BD28: jr          $ra
    // 0x8002BD2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002BD2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8002BD30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BD30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002BD34: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002BD38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002BD3C: jal         0x80012D8C
    // 0x8002BD40: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_80012D8C(rdram, ctx);
        goto after_0;
    // 0x8002BD40: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8002BD44: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8002BD48: beq         $a0, $zero, L_8002BD6C
    if (ctx->r4 == 0) {
        // 0x8002BD4C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8002BD6C;
    }
    // 0x8002BD4C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002BD50: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8002BD54: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8002BD58: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x8002BD5C: sb          $v1, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r3;
    // 0x8002BD60: lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5);
    // 0x8002BD64: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8002BD68: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
L_8002BD6C:
    // 0x8002BD6C: jal         0x80012D8C
    // 0x8002BD70: nop

    func_80012D8C(rdram, ctx);
        goto after_1;
    // 0x8002BD70: nop

    after_1:
    // 0x8002BD74: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8002BD78: beq         $a0, $zero, L_8002BDA0
    if (ctx->r4 == 0) {
        // 0x8002BD7C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002BDA0;
    }
    // 0x8002BD7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002BD80: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x8002BD84: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8002BD88: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x8002BD8C: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
    // 0x8002BD90: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x8002BD94: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x8002BD98: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8002BD9C: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
L_8002BDA0:
    // 0x8002BDA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002BDA4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002BDA8: jr          $ra
    // 0x8002BDAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002BDAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002BDB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BDB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002BDB4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002BDB8: lb          $v0, 0x2($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X2);
    // 0x8002BDBC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002BDC0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002BDC4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002BDC8: lw          $v0, 0x2C20($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2C20);
    // 0x8002BDCC: jalr        $v0
    // 0x8002BDD0: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8002BDD0: nop

    after_0:
    // 0x8002BDD4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002BDD8: jr          $ra
    // 0x8002BDDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002BDDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002BDE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BDE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002BDE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002BDE8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8002BDEC: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8002BDF0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002BDF4: lb          $v1, 0x3($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X3);
    // 0x8002BDF8: beq         $v1, $zero, L_8002BE14
    if (ctx->r3 == 0) {
        // 0x8002BDFC: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8002BE14;
    }
    // 0x8002BDFC: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8002BE00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002BE04: beq         $v1, $v0, L_8002BE38
    if (ctx->r3 == ctx->r2) {
        // 0x8002BE08: nop
    
            goto L_8002BE38;
    }
    // 0x8002BE08: nop

    // 0x8002BE0C: j           L_8002BFA0
    // 0x8002BE10: nop

        goto L_8002BFA0;
    // 0x8002BE10: nop

L_8002BE14:
    // 0x8002BE14: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8002BE18: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002BE1C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002BE20: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // 0x8002BE24: sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    // 0x8002BE28: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // 0x8002BE2C: sb          $zero, 0x7($s0)
    MEM_B(0X7, ctx->r16) = 0;
    // 0x8002BE30: j           L_8002BFA0
    // 0x8002BE34: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
        goto L_8002BFA0;
    // 0x8002BE34: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
L_8002BE38:
    // 0x8002BE38: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002BE3C: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8002BE40: lw          $v0, 0xB8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB8);
    // 0x8002BE44: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8002BE48: lui         $at, 0x3F19
    ctx->r1 = S32(0X3F19 << 16);
    // 0x8002BE4C: ori         $at, $at, 0x999A
    ctx->r1 = ctx->r1 | 0X999A;
    // 0x8002BE50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002BE54: andi        $v0, $v0, 0xC000
    ctx->r2 = ctx->r2 & 0XC000;
    // 0x8002BE58: beq         $v0, $zero, L_8002BE70
    if (ctx->r2 == 0) {
        // 0x8002BE5C: addiu       $s1, $zero, 0x2A
        ctx->r17 = ADD32(0, 0X2A);
            goto L_8002BE70;
    }
    // 0x8002BE5C: addiu       $s1, $zero, 0x2A
    ctx->r17 = ADD32(0, 0X2A);
    // 0x8002BE60: lui         $at, 0x3FE6
    ctx->r1 = S32(0X3FE6 << 16);
    // 0x8002BE64: ori         $at, $at, 0x6667
    ctx->r1 = ctx->r1 | 0X6667;
    // 0x8002BE68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002BE6C: addiu       $s1, $zero, 0x7E
    ctx->r17 = ADD32(0, 0X7E);
L_8002BE70:
    // 0x8002BE70: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8002BE74: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002BE78: ldc1        $f4, -0x2920($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2920);
    // 0x8002BE7C: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8002BE80: c.eq.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d == ctx->f4.d;
    // 0x8002BE84: nop

    // 0x8002BE88: bc1t        L_8002BEE4
    if (c1cs) {
        // 0x8002BE8C: nop
    
            goto L_8002BEE4;
    }
    // 0x8002BE8C: nop

    // 0x8002BE90: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8002BE94: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8002BE98: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x8002BE9C: nop

    // 0x8002BEA0: nop

    // 0x8002BEA4: bc1f        L_8002BEE4
    if (!c1cs) {
        // 0x8002BEA8: swc1        $f2, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
            goto L_8002BEE4;
    }
    // 0x8002BEA8: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x8002BEAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002BEB0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002BEB4: nop

    // 0x8002BEB8: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x8002BEBC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8002BEC0: lw          $v1, 0x7BB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7BB4);
    // 0x8002BEC4: lw          $v0, 0xB8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XB8);
    // 0x8002BEC8: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8002BECC: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x8002BED0: bne         $v0, $zero, L_8002BEE4
    if (ctx->r2 != 0) {
        // 0x8002BED4: addiu       $a0, $zero, 0x29
        ctx->r4 = ADD32(0, 0X29);
            goto L_8002BEE4;
    }
    // 0x8002BED4: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    // 0x8002BED8: lbu         $a1, 0x5($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X5);
    // 0x8002BEDC: jal         0x8000637C
    // 0x8002BEE0: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_0;
    // 0x8002BEE0: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_0:
L_8002BEE4:
    // 0x8002BEE4: lbu         $v1, 0x7($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X7);
    // 0x8002BEE8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002BEEC: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x8002BEF0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002BEF4: bne         $v0, $zero, L_8002BF00
    if (ctx->r2 != 0) {
        // 0x8002BEF8: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8002BF00;
    }
    // 0x8002BEF8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002BEFC: addu        $v0, $v1, $s1
    ctx->r2 = ADD32(ctx->r3, ctx->r17);
L_8002BF00:
    // 0x8002BF00: sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
    // 0x8002BF04: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002BF08: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8002BF0C: lw          $v0, 0xB8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB8);
    // 0x8002BF10: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8002BF14: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x8002BF18: beq         $v0, $zero, L_8002BF30
    if (ctx->r2 == 0) {
        // 0x8002BF1C: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8002BF30;
    }
    // 0x8002BF1C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002BF20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002BF24: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002BF28: sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
    // 0x8002BF2C: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
L_8002BF30:
    // 0x8002BF30: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8002BF34: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002BF38: ldc1        $f2, -0x2918($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2918);
    // 0x8002BF3C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8002BF40: c.eq.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d == ctx->f2.d;
    // 0x8002BF44: nop

    // 0x8002BF48: nop

    // 0x8002BF4C: bc1f        L_8002BFA0
    if (!c1cs) {
        // 0x8002BF50: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8002BFA0;
    }
    // 0x8002BF50: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002BF54: lbu         $v1, 0x7($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X7);
    // 0x8002BF58: bne         $v1, $v0, L_8002BFA0
    if (ctx->r3 != ctx->r2) {
        // 0x8002BF5C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8002BFA0;
    }
    // 0x8002BF5C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002BF60: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x8002BF64: sb          $v1, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r3;
    // 0x8002BF68: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // 0x8002BF6C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8002BF70: lw          $a0, 0x7BB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7BB4);
    // 0x8002BF74: lw          $v0, 0xB8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB8);
    // 0x8002BF78: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8002BF7C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002BF80: sb          $v1, 0x2000($at)
    MEM_B(0X2000, ctx->r1) = ctx->r3;
    // 0x8002BF84: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x8002BF88: beq         $v0, $zero, L_8002BFA0
    if (ctx->r2 == 0) {
        // 0x8002BF8C: nop
    
            goto L_8002BFA0;
    }
    // 0x8002BF8C: nop

    // 0x8002BF90: lbu         $a1, 0x5($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X5);
    // 0x8002BF94: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    // 0x8002BF98: jal         0x8000637C
    // 0x8002BF9C: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_1;
    // 0x8002BF9C: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_1:
L_8002BFA0:
    // 0x8002BFA0: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8002BFA4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002BFA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002BFAC: jr          $ra
    // 0x8002BFB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8002BFB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8002BFB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BFB4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8002BFB8: lbu         $v1, 0x7B93($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B93);
    // 0x8002BFBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002BFC0: bne         $v1, $v0, L_8002BFD0
    if (ctx->r3 != ctx->r2) {
        // 0x8002BFC4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8002BFD0;
    }
    // 0x8002BFC4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002BFC8: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
    // 0x8002BFCC: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
L_8002BFD0:
    // 0x8002BFD0: jr          $ra
    // 0x8002BFD4: nop

    return;
    // 0x8002BFD4: nop

;}
RECOMP_FUNC void func_8002BFD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BFD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002BFDC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8002BFE0: lb          $v1, 0x3($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X3);
    // 0x8002BFE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002BFE8: beq         $v1, $v0, L_8002C024
    if (ctx->r3 == ctx->r2) {
        // 0x8002BFEC: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_8002C024;
    }
    // 0x8002BFEC: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x8002BFF0: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8002BFF4: beql        $v0, $zero, L_8002C00C
    if (ctx->r2 == 0) {
        // 0x8002BFF8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8002C00C;
    }
    goto skip_0;
    // 0x8002BFF8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8002BFFC: beq         $v1, $zero, L_8002C01C
    if (ctx->r3 == 0) {
        // 0x8002C000: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_8002C01C;
    }
    // 0x8002C000: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x8002C004: j           L_8002C09C
    // 0x8002C008: nop

        goto L_8002C09C;
    // 0x8002C008: nop

L_8002C00C:
    // 0x8002C00C: beq         $v1, $v0, L_8002C090
    if (ctx->r3 == ctx->r2) {
        // 0x8002C010: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8002C090;
    }
    // 0x8002C010: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002C014: j           L_8002C09C
    // 0x8002C018: nop

        goto L_8002C09C;
    // 0x8002C018: nop

L_8002C01C:
    // 0x8002C01C: j           L_8002C09C
    // 0x8002C020: sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
        goto L_8002C09C;
    // 0x8002C020: sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
L_8002C024:
    // 0x8002C024: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002C028: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x8002C02C: lw          $v0, 0xB8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB8);
    // 0x8002C030: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8002C034: addiu       $a1, $zero, 0xF5C
    ctx->r5 = ADD32(0, 0XF5C);
    // 0x8002C038: andi        $v0, $v0, 0xC000
    ctx->r2 = ctx->r2 & 0XC000;
    // 0x8002C03C: beq         $v0, $zero, L_8002C04C
    if (ctx->r2 == 0) {
        // 0x8002C040: addiu       $v1, $zero, 0x2A
        ctx->r3 = ADD32(0, 0X2A);
            goto L_8002C04C;
    }
    // 0x8002C040: addiu       $v1, $zero, 0x2A
    ctx->r3 = ADD32(0, 0X2A);
    // 0x8002C044: addiu       $a1, $zero, 0x2E14
    ctx->r5 = ADD32(0, 0X2E14);
    // 0x8002C048: addiu       $v1, $zero, 0x7E
    ctx->r3 = ADD32(0, 0X7E);
L_8002C04C:
    // 0x8002C04C: lbu         $v0, 0x7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X7);
    // 0x8002C050: lwc1        $f0, 0x14($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8002C054: mtc1        $a1, $f2
    ctx->f2.u32l = ctx->r5;
    // 0x8002C058: nop

    // 0x8002C05C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8002C060: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8002C064: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8002C068: sb          $v0, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r2;
    // 0x8002C06C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8002C070: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002C074: beq         $v0, $zero, L_8002C09C
    if (ctx->r2 == 0) {
        // 0x8002C078: swc1        $f0, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
            goto L_8002C09C;
    }
    // 0x8002C078: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x8002C07C: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x8002C080: sb          $zero, 0x7($a0)
    MEM_B(0X7, ctx->r4) = 0;
    // 0x8002C084: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002C088: j           L_8002C09C
    // 0x8002C08C: sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
        goto L_8002C09C;
    // 0x8002C08C: sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
L_8002C090:
    // 0x8002C090: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C094: jal         0x80012DD4
    // 0x8002C098: sb          $v0, 0x7B93($at)
    MEM_B(0X7B93, ctx->r1) = ctx->r2;
    func_80012DD4(rdram, ctx);
        goto after_0;
    // 0x8002C098: sb          $v0, 0x7B93($at)
    MEM_B(0X7B93, ctx->r1) = ctx->r2;
    after_0:
L_8002C09C:
    // 0x8002C09C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8002C0A0: jr          $ra
    // 0x8002C0A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8002C0A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8002C0A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C0A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C0AC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002C0B0: jal         0x8002B9DC
    // 0x8002C0B4: nop

    func_8002B9DC(rdram, ctx);
        goto after_0;
    // 0x8002C0B4: nop

    after_0:
    // 0x8002C0B8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002C0BC: jr          $ra
    // 0x8002C0C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002C0C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002C0C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C0C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002C0C8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8002C0CC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8002C0D0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8002C0D4: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8002C0D8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002C0DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002C0E0: jal         0x80012D8C
    // 0x8002C0E4: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    func_80012D8C(rdram, ctx);
        goto after_0;
    // 0x8002C0E4: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    after_0:
    // 0x8002C0E8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8002C0EC: beq         $v1, $zero, L_8002C134
    if (ctx->r3 == 0) {
        // 0x8002C0F0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002C134;
    }
    // 0x8002C0F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002C0F4: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8002C0F8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8002C0FC: mtc1        $s1, $f0
    ctx->f0.u32l = ctx->r17;
    // 0x8002C100: nop

    // 0x8002C104: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002C108: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x8002C10C: mtc1        $s2, $f0
    ctx->f0.u32l = ctx->r18;
    // 0x8002C110: nop

    // 0x8002C114: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8002C118: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x8002C11C: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x8002C120: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x8002C124: sb          $s0, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r16;
    // 0x8002C128: swc1        $f0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f0.u32l;
    // 0x8002C12C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002C130: sb          $zero, 0x2000($at)
    MEM_B(0X2000, ctx->r1) = 0;
L_8002C134:
    // 0x8002C134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C138: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8002C13C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8002C140: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002C144: jr          $ra
    // 0x8002C148: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8002C148: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8002C150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C150: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C154: addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
    // 0x8002C158: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8002C15C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8002C160: lui         $s4, 0xFD10
    ctx->r20 = S32(0XFD10 << 16);
    // 0x8002C164: sw          $s3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r19;
    // 0x8002C168: lui         $s3, 0xF510
    ctx->r19 = S32(0XF510 << 16);
    // 0x8002C16C: sw          $s2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r18;
    // 0x8002C170: lui         $s2, 0x700
    ctx->r18 = S32(0X700 << 16);
    // 0x8002C174: sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // 0x8002C178: lui         $s1, 0xE600
    ctx->r17 = S32(0XE600 << 16);
    // 0x8002C17C: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x8002C180: lui         $s0, 0xF300
    ctx->r16 = S32(0XF300 << 16);
    // 0x8002C184: lui         $t7, 0x70F
    ctx->r15 = S32(0X70F << 16);
    // 0x8002C188: ori         $t7, $t7, 0xF200
    ctx->r15 = ctx->r15 | 0XF200;
    // 0x8002C18C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8002C190: lui         $t6, 0xF510
    ctx->r14 = S32(0XF510 << 16);
    // 0x8002C194: ori         $t6, $t6, 0x800
    ctx->r14 = ctx->r14 | 0X800;
    // 0x8002C198: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8002C19C: lui         $t5, 0x3
    ctx->r13 = S32(0X3 << 16);
    // 0x8002C1A0: ori         $t5, $t5, 0xC03C
    ctx->r13 = ctx->r13 | 0XC03C;
    // 0x8002C1A4: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x8002C1A8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002C1AC: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8002C1B0: lui         $v1, 0xE400
    ctx->r3 = S32(0XE400 << 16);
    // 0x8002C1B4: or          $t4, $v0, $v1
    ctx->r12 = ctx->r2 | ctx->r3;
    // 0x8002C1B8: sll         $a2, $a2, 24
    ctx->r6 = S32(ctx->r6 << 24);
    // 0x8002C1BC: sra         $a2, $a2, 22
    ctx->r6 = S32(SIGNED(ctx->r6) >> 22);
    // 0x8002C1C0: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8002C1C4: addu        $t3, $t3, $a2
    ctx->r11 = ADD32(ctx->r11, ctx->r6);
    // 0x8002C1C8: lw          $t3, 0x5D30($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X5D30);
    // 0x8002C1CC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002C1D0: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8002C1D4: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x8002C1D8: andi        $t2, $a1, 0xFFF
    ctx->r10 = ctx->r5 & 0XFFF;
    // 0x8002C1DC: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8002C1E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002C1E4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002C1E8: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x8002C1EC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8002C1F0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002C1F4: addiu       $v0, $v0, -0x67D0
    ctx->r2 = ADD32(ctx->r2, -0X67D0);
    // 0x8002C1F8: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_8002C1FC:
    // 0x8002C1FC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002C200: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8002C204: lui         $a3, 0x400
    ctx->r7 = S32(0X400 << 16);
    // 0x8002C208: ori         $a3, $a3, 0x400
    ctx->r7 = ctx->r7 | 0X400;
    // 0x8002C20C: sll         $a0, $t0, 24
    ctx->r4 = S32(ctx->r8 << 24);
    // 0x8002C210: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8002C214: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8002C218: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x8002C21C: addiu       $a1, $t0, 0x1
    ctx->r5 = ADD32(ctx->r8, 0X1);
    // 0x8002C220: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x8002C224: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x8002C228: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x8002C22C: sw          $s4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r20;
    // 0x8002C230: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8002C234: slti        $a1, $a1, 0x4
    ctx->r5 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8002C238: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8002C23C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002C240: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002C244: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8002C248: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002C24C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002C250: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8002C254: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002C258: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002C25C: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x8002C260: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002C264: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002C268: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x8002C26C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002C270: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002C274: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x8002C278: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002C27C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002C280: addiu       $v0, $v1, 0x38
    ctx->r2 = ADD32(ctx->r3, 0X38);
    // 0x8002C284: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002C288: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002C28C: addiu       $v0, $v1, 0x40
    ctx->r2 = ADD32(ctx->r3, 0X40);
    // 0x8002C290: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002C294: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002C298: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8002C29C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8002C2A0: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x8002C2A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002C2A8: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8002C2AC: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8002C2B0: or          $v0, $v0, $t4
    ctx->r2 = ctx->r2 | ctx->r12;
    // 0x8002C2B4: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x8002C2B8: addu        $a0, $t1, $a0
    ctx->r4 = ADD32(ctx->r9, ctx->r4);
    // 0x8002C2BC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8002C2C0: andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // 0x8002C2C4: sll         $a0, $a0, 12
    ctx->r4 = S32(ctx->r4 << 12);
    // 0x8002C2C8: or          $a0, $a0, $t2
    ctx->r4 = ctx->r4 | ctx->r10;
    // 0x8002C2CC: sw          $v0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r2;
    // 0x8002C2D0: addiu       $v0, $v1, 0x48
    ctx->r2 = ADD32(ctx->r3, 0X48);
    // 0x8002C2D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002C2D8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002C2DC: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x8002C2E0: sw          $v0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r2;
    // 0x8002C2E4: addiu       $v0, $v1, 0x50
    ctx->r2 = ADD32(ctx->r3, 0X50);
    // 0x8002C2E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002C2EC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002C2F0: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x8002C2F4: sw          $s3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r19;
    // 0x8002C2F8: sw          $s2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r18;
    // 0x8002C2FC: sw          $s1, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r17;
    // 0x8002C300: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x8002C304: sw          $s0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r16;
    // 0x8002C308: sw          $t7, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r15;
    // 0x8002C30C: sw          $t9, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r25;
    // 0x8002C310: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x8002C314: sw          $t6, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r14;
    // 0x8002C318: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x8002C31C: sw          $t8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r24;
    // 0x8002C320: sw          $t5, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r13;
    // 0x8002C324: sw          $a0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r4;
    // 0x8002C328: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
    // 0x8002C32C: sw          $v0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r2;
    // 0x8002C330: sw          $a3, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r7;
    // 0x8002C334: bne         $a1, $zero, L_8002C1FC
    if (ctx->r5 != 0) {
        // 0x8002C338: sw          $a2, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r6;
            goto L_8002C1FC;
    }
    // 0x8002C338: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x8002C33C: lw          $s4, 0x10($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X10);
    // 0x8002C340: lw          $s3, 0xC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XC);
    // 0x8002C344: lw          $s2, 0x8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X8);
    // 0x8002C348: lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4);
    // 0x8002C34C: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x8002C350: jr          $ra
    // 0x8002C354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002C354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002C358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C358: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002C35C: lbu         $v0, 0x7B4B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B4B);
    // 0x8002C360: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8002C364: lbu         $v1, 0x2070($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2070);
    // 0x8002C368: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8002C36C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8002C370: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8002C374: bne         $v1, $zero, L_8002C4D0
    if (ctx->r3 != 0) {
        // 0x8002C378: sltu        $s0, $zero, $v0
        ctx->r16 = 0 < ctx->r2 ? 1 : 0;
            goto L_8002C4D0;
    }
    // 0x8002C378: sltu        $s0, $zero, $v0
    ctx->r16 = 0 < ctx->r2 ? 1 : 0;
    // 0x8002C37C: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x8002C380: lbu         $t1, 0x7B38($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7B38);
    // 0x8002C384: sltiu       $v0, $t1, 0x2
    ctx->r2 = ctx->r9 < 0X2 ? 1 : 0;
    // 0x8002C388: beq         $v0, $zero, L_8002C394
    if (ctx->r2 == 0) {
        // 0x8002C38C: addiu       $a3, $zero, 0x53
        ctx->r7 = ADD32(0, 0X53);
            goto L_8002C394;
    }
    // 0x8002C38C: addiu       $a3, $zero, 0x53
    ctx->r7 = ADD32(0, 0X53);
    // 0x8002C390: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
L_8002C394:
    // 0x8002C394: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8002C398: lbu         $v1, 0x7B40($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B40);
    // 0x8002C39C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002C3A0: bne         $v1, $v0, L_8002C3D0
    if (ctx->r3 != ctx->r2) {
        // 0x8002C3A4: addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
            goto L_8002C3D0;
    }
    // 0x8002C3A4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8002C3A8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8002C3AC: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8002C3B0: addiu       $a1, $a1, -0x28F8
    ctx->r5 = ADD32(ctx->r5, -0X28F8);
    // 0x8002C3B4: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x8002C3B8: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8002C3BC: addiu       $a2, $a2, -0x3DD4
    ctx->r6 = ADD32(ctx->r6, -0X3DD4);
    // 0x8002C3C0: jal         0x80066CA0
    // 0x8002C3C4: addu        $a2, $v0, $a2
    ctx->r6 = ADD32(ctx->r2, ctx->r6);
    func_80066CA0(rdram, ctx);
        goto after_0;
    // 0x8002C3C4: addu        $a2, $v0, $a2
    ctx->r6 = ADD32(ctx->r2, ctx->r6);
    after_0:
    // 0x8002C3C8: j           L_8002C40C
    // 0x8002C3CC: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
        goto L_8002C40C;
    // 0x8002C3CC: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
L_8002C3D0:
    // 0x8002C3D0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8002C3D4: addiu       $a1, $a1, -0x28F0
    ctx->r5 = ADD32(ctx->r5, -0X28F0);
    // 0x8002C3D8: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x8002C3DC: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8002C3E0: addiu       $a2, $a2, -0x3DD4
    ctx->r6 = ADD32(ctx->r6, -0X3DD4);
    // 0x8002C3E4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8002C3E8: lbu         $v1, 0x7B3A($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B3A);
    // 0x8002C3EC: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x8002C3F0: lbu         $t0, 0x7B40($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X7B40);
    // 0x8002C3F4: addu        $a2, $v0, $a2
    ctx->r6 = ADD32(ctx->r2, ctx->r6);
    // 0x8002C3F8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8002C3FC: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x8002C400: jal         0x80066CA0
    // 0x8002C404: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    func_80066CA0(rdram, ctx);
        goto after_1;
    // 0x8002C404: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_1:
    // 0x8002C408: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
L_8002C40C:
    // 0x8002C40C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x8002C410: addiu       $a2, $zero, 0xD8
    ctx->r6 = ADD32(0, 0XD8);
    // 0x8002C414: jal         0x8004DAB8
    // 0x8002C418: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_2;
    // 0x8002C418: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // 0x8002C41C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8002C420: lbu         $v1, 0x7B4A($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B4A);
    // 0x8002C424: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002C428: bne         $v1, $v0, L_8002C4D0
    if (ctx->r3 != ctx->r2) {
        // 0x8002C42C: nop
    
            goto L_8002C4D0;
    }
    // 0x8002C42C: nop

    // 0x8002C430: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x8002C434: lbu         $t1, 0x7B3C($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7B3C);
    // 0x8002C438: sltiu       $v0, $t1, 0x2
    ctx->r2 = ctx->r9 < 0X2 ? 1 : 0;
    // 0x8002C43C: beq         $v0, $zero, L_8002C448
    if (ctx->r2 == 0) {
        // 0x8002C440: addiu       $a3, $zero, 0x53
        ctx->r7 = ADD32(0, 0X53);
            goto L_8002C448;
    }
    // 0x8002C440: addiu       $a3, $zero, 0x53
    ctx->r7 = ADD32(0, 0X53);
    // 0x8002C444: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
L_8002C448:
    // 0x8002C448: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002C44C: lbu         $v0, 0x7B40($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B40);
    // 0x8002C450: bne         $v0, $v1, L_8002C484
    if (ctx->r2 != ctx->r3) {
        // 0x8002C454: addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
            goto L_8002C484;
    }
    // 0x8002C454: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8002C458: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8002C45C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8002C460: addiu       $a1, $a1, -0x28F8
    ctx->r5 = ADD32(ctx->r5, -0X28F8);
    // 0x8002C464: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x8002C468: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8002C46C: addiu       $a2, $a2, -0x3DD4
    ctx->r6 = ADD32(ctx->r6, -0X3DD4);
    // 0x8002C470: jal         0x80066CA0
    // 0x8002C474: addu        $a2, $v0, $a2
    ctx->r6 = ADD32(ctx->r2, ctx->r6);
    func_80066CA0(rdram, ctx);
        goto after_3;
    // 0x8002C474: addu        $a2, $v0, $a2
    ctx->r6 = ADD32(ctx->r2, ctx->r6);
    after_3:
    // 0x8002C478: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8002C47C: j           L_8002C4C4
    // 0x8002C480: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
        goto L_8002C4C4;
    // 0x8002C480: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
L_8002C484:
    // 0x8002C484: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8002C488: addiu       $a1, $a1, -0x28F0
    ctx->r5 = ADD32(ctx->r5, -0X28F0);
    // 0x8002C48C: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x8002C490: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8002C494: addiu       $a2, $a2, -0x3DD4
    ctx->r6 = ADD32(ctx->r6, -0X3DD4);
    // 0x8002C498: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8002C49C: lbu         $v1, 0x7B3E($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B3E);
    // 0x8002C4A0: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x8002C4A4: lbu         $t0, 0x7B40($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X7B40);
    // 0x8002C4A8: addu        $a2, $v0, $a2
    ctx->r6 = ADD32(ctx->r2, ctx->r6);
    // 0x8002C4AC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8002C4B0: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x8002C4B4: jal         0x80066CA0
    // 0x8002C4B8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    func_80066CA0(rdram, ctx);
        goto after_4;
    // 0x8002C4B8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_4:
    // 0x8002C4BC: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8002C4C0: addiu       $a1, $zero, 0xC2
    ctx->r5 = ADD32(0, 0XC2);
L_8002C4C4:
    // 0x8002C4C4: addiu       $a2, $zero, 0xD8
    ctx->r6 = ADD32(0, 0XD8);
    // 0x8002C4C8: jal         0x8004DAB8
    // 0x8002C4CC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_5;
    // 0x8002C4CC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_5:
L_8002C4D0:
    // 0x8002C4D0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8002C4D4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8002C4D8: jr          $ra
    // 0x8002C4DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8002C4DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8002C4E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C4E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C4E4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8002C4E8: addiu       $a0, $a0, -0x28E0
    ctx->r4 = ADD32(ctx->r4, -0X28E0);
    // 0x8002C4EC: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
    // 0x8002C4F0: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x8002C4F4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002C4F8: jal         0x8004DAB8
    // 0x8002C4FC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_0;
    // 0x8002C4FC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x8002C500: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8002C504: lw          $a0, 0x2C30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C30);
    // 0x8002C508: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x8002C50C: addiu       $a2, $zero, 0xAA
    ctx->r6 = ADD32(0, 0XAA);
    // 0x8002C510: jal         0x8004DAB8
    // 0x8002C514: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_1;
    // 0x8002C514: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
    // 0x8002C518: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002C51C: jr          $ra
    // 0x8002C520: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002C520: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002C524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C524: jr          $ra
    // 0x8002C528: nop

    return;
    // 0x8002C528: nop

;}
RECOMP_FUNC void func_8002C52C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C52C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002C530: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x8002C534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C538: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x8002C53C: beq         $v0, $zero, L_8002C55C
    if (ctx->r2 == 0) {
        // 0x8002C540: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8002C55C;
    }
    // 0x8002C540: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002C544: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8002C548: addiu       $a0, $a0, -0x28D8
    ctx->r4 = ADD32(ctx->r4, -0X28D8);
    // 0x8002C54C: addiu       $a1, $zero, 0x7C
    ctx->r5 = ADD32(0, 0X7C);
    // 0x8002C550: addiu       $a2, $zero, 0x98
    ctx->r6 = ADD32(0, 0X98);
    // 0x8002C554: jal         0x8004DAB8
    // 0x8002C558: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_0;
    // 0x8002C558: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
L_8002C55C:
    // 0x8002C55C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002C560: jr          $ra
    // 0x8002C564: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002C564: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002C568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C568: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C56C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8002C570: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8002C574: lui         $a0, 0x600
    ctx->r4 = S32(0X600 << 16);
    // 0x8002C578: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002C57C: addiu       $v0, $v0, -0x6850
    ctx->r2 = ADD32(ctx->r2, -0X6850);
    // 0x8002C580: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002C584: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8002C588: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002C58C: addiu       $v0, $v0, -0x6858
    ctx->r2 = ADD32(ctx->r2, -0X6858);
    // 0x8002C590: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8002C594: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8002C598: addiu       $v0, $v0, 0x54E0
    ctx->r2 = ADD32(ctx->r2, 0X54E0);
    // 0x8002C59C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8002C5A0: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // 0x8002C5A4: sw          $a0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r4;
    // 0x8002C5A8: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x8002C5AC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002C5B0: lb          $v0, 0x5581($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5581);
    // 0x8002C5B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8002C5B8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8002C5BC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8002C5C0: lw          $a0, 0x6108($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6108);
    // 0x8002C5C4: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8002C5C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002C5CC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002C5D0: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8002C5D4: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x8002C5D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002C5DC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002C5E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002C5E4: jalr        $a0
    // 0x8002C5E8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    LOOKUP_FUNC(ctx->r4)(rdram, ctx);
        goto after_0;
    // 0x8002C5E8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    after_0:
    // 0x8002C5EC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002C5F0: jr          $ra
    // 0x8002C5F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002C5F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002C5F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C5F8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8002C5FC: addiu       $a0, $a0, 0x5581
    ctx->r4 = ADD32(ctx->r4, 0X5581);
    // 0x8002C600: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8002C604: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8002C608: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002C60C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C610: sb          $v0, 0x7BA0($at)
    MEM_B(0X7BA0, ctx->r1) = ctx->r2;
    // 0x8002C614: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x8002C618: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C61C: sb          $zero, 0x2074($at)
    MEM_B(0X2074, ctx->r1) = 0;
    // 0x8002C620: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C624: sb          $zero, 0x7B98($at)
    MEM_B(0X7B98, ctx->r1) = 0;
    // 0x8002C628: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C62C: sb          $zero, 0x7A4A($at)
    MEM_B(0X7A4A, ctx->r1) = 0;
    // 0x8002C630: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C634: sb          $zero, 0x25FA($at)
    MEM_B(0X25FA, ctx->r1) = 0;
    // 0x8002C638: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C63C: sb          $zero, 0x5582($at)
    MEM_B(0X5582, ctx->r1) = 0;
    // 0x8002C640: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C644: sh          $v0, 0x5588($at)
    MEM_H(0X5588, ctx->r1) = ctx->r2;
    // 0x8002C648: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002C64C: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8002C650: jr          $ra
    // 0x8002C654: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8002C654: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8002C658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C658: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C65C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002C660: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8002C664: addiu       $s0, $s0, 0x5582
    ctx->r16 = ADD32(ctx->r16, 0X5582);
    // 0x8002C668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C66C: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x8002C670: beq         $v1, $zero, L_8002C688
    if (ctx->r3 == 0) {
        // 0x8002C674: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002C688;
    }
    // 0x8002C674: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002C678: beq         $v1, $v0, L_8002C69C
    if (ctx->r3 == ctx->r2) {
        // 0x8002C67C: nop
    
            goto L_8002C69C;
    }
    // 0x8002C67C: nop

    // 0x8002C680: j           L_8002C6A4
    // 0x8002C684: nop

        goto L_8002C6A4;
    // 0x8002C684: nop

L_8002C688:
    // 0x8002C688: jal         0x80056270
    // 0x8002C68C: nop

    func_80056270(rdram, ctx);
        goto after_0;
    // 0x8002C68C: nop

    after_0:
    // 0x8002C690: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8002C694: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002C698: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_8002C69C:
    // 0x8002C69C: jal         0x800562DC
    // 0x8002C6A0: nop

    func_800562DC(rdram, ctx);
        goto after_1;
    // 0x8002C6A0: nop

    after_1:
L_8002C6A4:
    // 0x8002C6A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C6A8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002C6AC: jr          $ra
    // 0x8002C6B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002C6B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002C6B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C6B4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8002C6B8: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x8002C6BC: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8002C6C0: addiu       $s0, $s0, 0x5582
    ctx->r16 = ADD32(ctx->r16, 0X5582);
    // 0x8002C6C4: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8002C6C8: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x8002C6CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002C6D0: beq         $v1, $v0, L_8002C704
    if (ctx->r3 == ctx->r2) {
        // 0x8002C6D4: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_8002C704;
    }
    // 0x8002C6D4: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x8002C6D8: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8002C6DC: beql        $v0, $zero, L_8002C6F4
    if (ctx->r2 == 0) {
        // 0x8002C6E0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8002C6F4;
    }
    goto skip_0;
    // 0x8002C6E0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8002C6E4: beq         $v1, $zero, L_8002C72C
    if (ctx->r3 == 0) {
        // 0x8002C6E8: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8002C72C;
    }
    // 0x8002C6E8: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8002C6EC: j           L_8002C7AC
    // 0x8002C6F0: nop

        goto L_8002C7AC;
    // 0x8002C6F0: nop

L_8002C6F4:
    // 0x8002C6F4: beq         $v1, $v0, L_8002C73C
    if (ctx->r3 == ctx->r2) {
        // 0x8002C6F8: nop
    
            goto L_8002C73C;
    }
    // 0x8002C6F8: nop

    // 0x8002C6FC: j           L_8002C7AC
    // 0x8002C700: nop

        goto L_8002C7AC;
    // 0x8002C700: nop

L_8002C704:
    // 0x8002C704: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002C708: lhu         $v0, 0x558C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X558C);
    // 0x8002C70C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8002C710: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002C714: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C718: sh          $v0, 0x558C($at)
    MEM_H(0X558C, ctx->r1) = ctx->r2;
    // 0x8002C71C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002C720: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002C724: bne         $v0, $v1, L_8002C7AC
    if (ctx->r2 != ctx->r3) {
        // 0x8002C728: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8002C7AC;
    }
    // 0x8002C728: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
L_8002C72C:
    // 0x8002C72C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C730: sh          $zero, 0x558C($at)
    MEM_H(0X558C, ctx->r1) = 0;
    // 0x8002C734: j           L_8002C7AC
    // 0x8002C738: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
        goto L_8002C7AC;
    // 0x8002C738: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_8002C73C:
    // 0x8002C73C: jal         0x800572E0
    // 0x8002C740: nop

    func_800572E0(rdram, ctx);
        goto after_0;
    // 0x8002C740: nop

    after_0:
    // 0x8002C744: jal         0x800067C8
    // 0x8002C748: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800067C8(rdram, ctx);
        goto after_1;
    // 0x8002C748: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_1:
    // 0x8002C74C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002C750: lbu         $v0, 0x5581($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5581);
    // 0x8002C754: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002C758: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C75C: sb          $v1, 0x7B85($at)
    MEM_B(0X7B85, ctx->r1) = ctx->r3;
    // 0x8002C760: addiu       $v1, $zero, 0x708
    ctx->r3 = ADD32(0, 0X708);
    // 0x8002C764: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C768: sb          $zero, 0x7B8B($at)
    MEM_B(0X7B8B, ctx->r1) = 0;
    // 0x8002C76C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C770: sb          $zero, 0x7B73($at)
    MEM_B(0X7B73, ctx->r1) = 0;
    // 0x8002C774: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C778: sb          $zero, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = 0;
    // 0x8002C77C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C780: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x8002C784: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C788: sb          $zero, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = 0;
    // 0x8002C78C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C790: sb          $zero, 0x7B7D($at)
    MEM_B(0X7B7D, ctx->r1) = 0;
    // 0x8002C794: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C798: sh          $v1, 0x5588($at)
    MEM_H(0X5588, ctx->r1) = ctx->r3;
    // 0x8002C79C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8002C7A0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002C7A4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C7A8: sb          $v0, 0x5581($at)
    MEM_B(0X5581, ctx->r1) = ctx->r2;
L_8002C7AC:
    // 0x8002C7AC: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8002C7B0: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x8002C7B4: jr          $ra
    // 0x8002C7B8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8002C7B8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8002C7BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C7BC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8002C7C0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8002C7C4: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x8002C7C8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8002C7CC: lw          $v1, -0x3824($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3824);
    // 0x8002C7D0: lui         $v0, 0xBC00
    ctx->r2 = S32(0XBC00 << 16);
    // 0x8002C7D4: ori         $v0, $v0, 0x1806
    ctx->r2 = ctx->r2 | 0X1806;
    // 0x8002C7D8: sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // 0x8002C7DC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8002C7E0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8002C7E4: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8002C7E8: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x8002C7EC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8002C7F0: lb          $v1, 0x5582($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X5582);
    // 0x8002C7F4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8002C7F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002C7FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002C800: sw          $a0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r4;
    // 0x8002C804: beq         $v1, $v0, L_8002C83C
    if (ctx->r3 == ctx->r2) {
        // 0x8002C808: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8002C83C;
    }
    // 0x8002C808: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8002C80C: beql        $v0, $zero, L_8002C824
    if (ctx->r2 == 0) {
        // 0x8002C810: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8002C824;
    }
    goto skip_0;
    // 0x8002C810: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8002C814: beq         $v1, $zero, L_8002C834
    if (ctx->r3 == 0) {
        // 0x8002C818: nop
    
            goto L_8002C834;
    }
    // 0x8002C818: nop

    // 0x8002C81C: j           L_8002C854
    // 0x8002C820: nop

        goto L_8002C854;
    // 0x8002C820: nop

L_8002C824:
    // 0x8002C824: beq         $v1, $v0, L_8002C84C
    if (ctx->r3 == ctx->r2) {
        // 0x8002C828: nop
    
            goto L_8002C84C;
    }
    // 0x8002C828: nop

    // 0x8002C82C: j           L_8002C854
    // 0x8002C830: nop

        goto L_8002C854;
    // 0x8002C830: nop

L_8002C834:
    // 0x8002C834: jal         0x8005702C
    // 0x8002C838: nop

    func_8005702C(rdram, ctx);
        goto after_0;
    // 0x8002C838: nop

    after_0:
L_8002C83C:
    // 0x8002C83C: jal         0x80057098
    // 0x8002C840: nop

    func_80057098(rdram, ctx);
        goto after_1;
    // 0x8002C840: nop

    after_1:
    // 0x8002C844: j           L_8002C854
    // 0x8002C848: nop

        goto L_8002C854;
    // 0x8002C848: nop

L_8002C84C:
    // 0x8002C84C: jal         0x80056FF0
    // 0x8002C850: nop

    func_80056FF0(rdram, ctx);
        goto after_2;
    // 0x8002C850: nop

    after_2:
L_8002C854:
    // 0x8002C854: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8002C858: addiu       $v1, $v1, 0x5588
    ctx->r3 = ADD32(ctx->r3, 0X5588);
    // 0x8002C85C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C860: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8002C864: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8002C868: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002C86C: bne         $v0, $zero, L_8002C8BC
    if (ctx->r2 != 0) {
        // 0x8002C870: nop
    
            goto L_8002C8BC;
    }
    // 0x8002C870: nop

    // 0x8002C874: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002C878: lbu         $v0, 0x2080($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2080);
    // 0x8002C87C: beq         $v0, $zero, L_8002C894
    if (ctx->r2 == 0) {
        // 0x8002C880: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_8002C894;
    }
    // 0x8002C880: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8002C884: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002C888: lbu         $v0, 0x2070($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2070);
    // 0x8002C88C: beq         $v0, $zero, L_8002C8B0
    if (ctx->r2 == 0) {
        // 0x8002C890: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_8002C8B0;
    }
    // 0x8002C890: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_8002C894:
    // 0x8002C894: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C898: sb          $v0, 0x5581($at)
    MEM_B(0X5581, ctx->r1) = ctx->r2;
    // 0x8002C89C: jal         0x8002CFB8
    // 0x8002C8A0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002CFB8(rdram, ctx);
        goto after_3;
    // 0x8002C8A0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x8002C8A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002C8A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C8AC: sb          $v0, 0x7B4D($at)
    MEM_B(0X7B4D, ctx->r1) = ctx->r2;
L_8002C8B0:
    // 0x8002C8B0: addiu       $v0, $zero, 0xBB8
    ctx->r2 = ADD32(0, 0XBB8);
    // 0x8002C8B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C8B8: sh          $v0, 0x5588($at)
    MEM_H(0X5588, ctx->r1) = ctx->r2;
L_8002C8BC:
    // 0x8002C8BC: lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X60);
    // 0x8002C8C0: jr          $ra
    // 0x8002C8C4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8002C8C4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8002C8C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C8C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C8CC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8002C8D0: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x8002C8D4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8002C8D8: lw          $v1, -0x3824($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3824);
    // 0x8002C8DC: lui         $a1, 0xBC00
    ctx->r5 = S32(0XBC00 << 16);
    // 0x8002C8E0: ori         $a1, $a1, 0x1806
    ctx->r5 = ctx->r5 | 0X1806;
    // 0x8002C8E4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002C8E8: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8002C8EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002C8F0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8002C8F4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8002C8F8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8002C8FC: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x8002C900: jal         0x80056FF0
    // 0x8002C904: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    func_80056FF0(rdram, ctx);
        goto after_0;
    // 0x8002C904: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    after_0:
    // 0x8002C908: jal         0x8002D634
    // 0x8002C90C: nop

    func_8002D634(rdram, ctx);
        goto after_1;
    // 0x8002C90C: nop

    after_1:
    // 0x8002C910: jal         0x8002CFB8
    // 0x8002C914: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_2;
    // 0x8002C914: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // 0x8002C918: beq         $v0, $zero, L_8002C930
    if (ctx->r2 == 0) {
        // 0x8002C91C: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_8002C930;
    }
    // 0x8002C91C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8002C920: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C924: sb          $v0, 0x5581($at)
    MEM_B(0X5581, ctx->r1) = ctx->r2;
    // 0x8002C928: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C92C: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
L_8002C930:
    // 0x8002C930: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002C934: jr          $ra
    // 0x8002C938: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002C938: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002C93C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C93C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C940: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002C944: jal         0x8004A950
    // 0x8002C948: nop

    func_8004A950(rdram, ctx);
        goto after_0;
    // 0x8002C948: nop

    after_0:
    // 0x8002C94C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002C950: jr          $ra
    // 0x8002C954: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002C954: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002C958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C958: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8002C95C: sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // 0x8002C960: jal         0x8000705C
    // 0x8002C964: nop

    func_8000705C(rdram, ctx);
        goto after_0;
    // 0x8002C964: nop

    after_0:
    // 0x8002C968: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002C96C: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x8002C970: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x8002C974: beq         $v0, $zero, L_8002C990
    if (ctx->r2 == 0) {
        // 0x8002C978: addiu       $a1, $zero, 0x7C
        ctx->r5 = ADD32(0, 0X7C);
            goto L_8002C990;
    }
    // 0x8002C978: addiu       $a1, $zero, 0x7C
    ctx->r5 = ADD32(0, 0X7C);
    // 0x8002C97C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8002C980: addiu       $a0, $a0, -0x28D8
    ctx->r4 = ADD32(ctx->r4, -0X28D8);
    // 0x8002C984: addiu       $a2, $zero, 0x98
    ctx->r6 = ADD32(0, 0X98);
    // 0x8002C988: jal         0x8004DAB8
    // 0x8002C98C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_1;
    // 0x8002C98C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
L_8002C990:
    // 0x8002C990: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8002C994: addiu       $v1, $v1, 0x5588
    ctx->r3 = ADD32(ctx->r3, 0X5588);
    // 0x8002C998: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8002C99C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8002C9A0: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8002C9A4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002C9A8: beq         $v0, $zero, L_8002C9C0
    if (ctx->r2 == 0) {
        // 0x8002C9AC: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_8002C9C0;
    }
    // 0x8002C9AC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8002C9B0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002C9B4: lbu         $v0, 0x7B7F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B7F);
    // 0x8002C9B8: beq         $v0, $zero, L_8002C9D8
    if (ctx->r2 == 0) {
        // 0x8002C9BC: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_8002C9D8;
    }
    // 0x8002C9BC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_8002C9C0:
    // 0x8002C9C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C9C4: sb          $v0, 0x5581($at)
    MEM_B(0X5581, ctx->r1) = ctx->r2;
    // 0x8002C9C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C9CC: sb          $zero, 0x7A59($at)
    MEM_B(0X7A59, ctx->r1) = 0;
    // 0x8002C9D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002C9D4: sb          $zero, 0x2609($at)
    MEM_B(0X2609, ctx->r1) = 0;
L_8002C9D8:
    // 0x8002C9D8: lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X60);
    // 0x8002C9DC: jr          $ra
    // 0x8002C9E0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8002C9E0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8002C9E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C9E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C9E8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002C9EC: jal         0x8000705C
    // 0x8002C9F0: nop

    func_8000705C(rdram, ctx);
        goto after_0;
    // 0x8002C9F0: nop

    after_0:
    // 0x8002C9F4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002C9F8: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x8002C9FC: andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // 0x8002CA00: beq         $v0, $zero, L_8002CA1C
    if (ctx->r2 == 0) {
        // 0x8002CA04: addiu       $a1, $zero, 0x7C
        ctx->r5 = ADD32(0, 0X7C);
            goto L_8002CA1C;
    }
    // 0x8002CA04: addiu       $a1, $zero, 0x7C
    ctx->r5 = ADD32(0, 0X7C);
    // 0x8002CA08: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8002CA0C: addiu       $a0, $a0, -0x28D8
    ctx->r4 = ADD32(ctx->r4, -0X28D8);
    // 0x8002CA10: addiu       $a2, $zero, 0x98
    ctx->r6 = ADD32(0, 0X98);
    // 0x8002CA14: jal         0x8004DAB8
    // 0x8002CA18: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_1;
    // 0x8002CA18: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
L_8002CA1C:
    // 0x8002CA1C: jal         0x8002D378
    // 0x8002CA20: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_2;
    // 0x8002CA20: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x8002CA24: jal         0x8002D0D4
    // 0x8002CA28: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_3;
    // 0x8002CA28: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x8002CA2C: jal         0x8002CFB8
    // 0x8002CA30: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_4;
    // 0x8002CA30: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
    // 0x8002CA34: beq         $v0, $zero, L_8002CA44
    if (ctx->r2 == 0) {
        // 0x8002CA38: nop
    
            goto L_8002CA44;
    }
    // 0x8002CA38: nop

    // 0x8002CA3C: jal         0x8002CAB4
    // 0x8002CA40: nop

    func_8002CAB4(rdram, ctx);
        goto after_5;
    // 0x8002CA40: nop

    after_5:
L_8002CA44:
    // 0x8002CA44: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002CA48: jr          $ra
    // 0x8002CA4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002CA4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002CA50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CA50: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8002CA54: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8002CA58: addiu       $a0, $a0, 0x5581
    ctx->r4 = ADD32(ctx->r4, 0X5581);
    // 0x8002CA5C: sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // 0x8002CA60: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8002CA64: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x8002CA68: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CA6C: sb          $zero, 0x5582($at)
    MEM_B(0X5582, ctx->r1) = 0;
    // 0x8002CA70: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CA74: sh          $v0, 0x5588($at)
    MEM_H(0X5588, ctx->r1) = ctx->r2;
    // 0x8002CA78: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CA7C: sb          $zero, 0x2074($at)
    MEM_B(0X2074, ctx->r1) = 0;
    // 0x8002CA80: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002CA84: jal         0x80006708
    // 0x8002CA88: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    func_80006708(rdram, ctx);
        goto after_0;
    // 0x8002CA88: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    after_0:
    // 0x8002CA8C: lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X60);
    // 0x8002CA90: jr          $ra
    // 0x8002CA94: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8002CA94: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8002CA98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CA98: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8002CA9C: sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // 0x8002CAA0: jal         0x800541A0
    // 0x8002CAA4: nop

    func_800541A0(rdram, ctx);
        goto after_0;
    // 0x8002CAA4: nop

    after_0:
    // 0x8002CAA8: lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X60);
    // 0x8002CAAC: jr          $ra
    // 0x8002CAB0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8002CAB0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8002CAB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CAB4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002CAB8: lbu         $v0, 0x2074($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2074);
    // 0x8002CABC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002CAC0: bne         $v0, $zero, L_8002CB10
    if (ctx->r2 != 0) {
        // 0x8002CAC4: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8002CB10;
    }
    // 0x8002CAC4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8002CAC8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8002CACC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CAD0: sb          $v0, 0x5581($at)
    MEM_B(0X5581, ctx->r1) = ctx->r2;
    // 0x8002CAD4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CAD8: sh          $zero, 0x558A($at)
    MEM_H(0X558A, ctx->r1) = 0;
    // 0x8002CADC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CAE0: sh          $zero, 0x558C($at)
    MEM_H(0X558C, ctx->r1) = 0;
    // 0x8002CAE4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CAE8: sb          $zero, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = 0;
    // 0x8002CAEC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CAF0: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x8002CAF4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CAF8: sb          $zero, 0x79F0($at)
    MEM_B(0X79F0, ctx->r1) = 0;
    // 0x8002CAFC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CB00: sb          $zero, 0x25A0($at)
    MEM_B(0X25A0, ctx->r1) = 0;
    // 0x8002CB04: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CB08: j           L_8002CB3C
    // 0x8002CB0C: sb          $zero, 0x7B8B($at)
    MEM_B(0X7B8B, ctx->r1) = 0;
        goto L_8002CB3C;
    // 0x8002CB0C: sb          $zero, 0x7B8B($at)
    MEM_B(0X7B8B, ctx->r1) = 0;
L_8002CB10:
    // 0x8002CB10: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8002CB14: lbu         $v1, 0x7B8B($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B8B);
    // 0x8002CB18: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002CB1C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CB20: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x8002CB24: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CB28: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x8002CB2C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CB30: sb          $zero, 0x7B8B($at)
    MEM_B(0X7B8B, ctx->r1) = 0;
    // 0x8002CB34: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CB38: sb          $v1, 0x7B9D($at)
    MEM_B(0X7B9D, ctx->r1) = ctx->r3;
L_8002CB3C:
    // 0x8002CB3C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8002CB40: addiu       $v1, $v1, 0x5584
    ctx->r3 = ADD32(ctx->r3, 0X5584);
    // 0x8002CB44: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8002CB48: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CB4C: sb          $zero, 0x7B98($at)
    MEM_B(0X7B98, ctx->r1) = 0;
    // 0x8002CB50: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CB54: sb          $zero, 0x7A4A($at)
    MEM_B(0X7A4A, ctx->r1) = 0;
    // 0x8002CB58: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CB5C: sb          $zero, 0x25FA($at)
    MEM_B(0X25FA, ctx->r1) = 0;
    // 0x8002CB60: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CB64: sb          $v0, 0x7B13($at)
    MEM_B(0X7B13, ctx->r1) = ctx->r2;
    // 0x8002CB68: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CB6C: sb          $v0, 0x26C3($at)
    MEM_B(0X26C3, ctx->r1) = ctx->r2;
    // 0x8002CB70: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002CB74: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8002CB78: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8002CB7C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8002CB80: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8002CB84: beql        $v0, $zero, L_8002CB8C
    if (ctx->r2 == 0) {
        // 0x8002CB88: sb          $zero, 0x0($v1)
        MEM_B(0X0, ctx->r3) = 0;
            goto L_8002CB8C;
    }
    goto skip_0;
    // 0x8002CB88: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    skip_0:
L_8002CB8C:
    // 0x8002CB8C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8002CB90: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CB94: sb          $v0, 0x7B85($at)
    MEM_B(0X7B85, ctx->r1) = ctx->r2;
    // 0x8002CB98: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CB9C: sb          $v0, 0x7A3E($at)
    MEM_B(0X7A3E, ctx->r1) = ctx->r2;
    // 0x8002CBA0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CBA4: sb          $v0, 0x25EE($at)
    MEM_B(0X25EE, ctx->r1) = ctx->r2;
    // 0x8002CBA8: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8002CBAC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CBB0: sb          $v0, 0x7A4C($at)
    MEM_B(0X7A4C, ctx->r1) = ctx->r2;
    // 0x8002CBB4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CBB8: sb          $v0, 0x25FC($at)
    MEM_B(0X25FC, ctx->r1) = ctx->r2;
    // 0x8002CBBC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002CBC0: lbu         $v0, 0x25A5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X25A5);
    // 0x8002CBC4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8002CBC8: lbu         $v1, 0x79F5($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X79F5);
    // 0x8002CBCC: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    // 0x8002CBD0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CBD4: sb          $zero, 0x7B0D($at)
    MEM_B(0X7B0D, ctx->r1) = 0;
    // 0x8002CBD8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CBDC: sb          $zero, 0x26BD($at)
    MEM_B(0X26BD, ctx->r1) = 0;
    // 0x8002CBE0: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8002CBE4: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x8002CBE8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CBEC: sb          $v0, 0x25A5($at)
    MEM_B(0X25A5, ctx->r1) = ctx->r2;
    // 0x8002CBF0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CBF4: jal         0x80053390
    // 0x8002CBF8: sb          $v1, 0x79F5($at)
    MEM_B(0X79F5, ctx->r1) = ctx->r3;
    func_80053390(rdram, ctx);
        goto after_0;
    // 0x8002CBF8: sb          $v1, 0x79F5($at)
    MEM_B(0X79F5, ctx->r1) = ctx->r3;
    after_0:
    // 0x8002CBFC: jal         0x80006708
    // 0x8002CC00: nop

    func_80006708(rdram, ctx);
        goto after_1;
    // 0x8002CC00: nop

    after_1:
    // 0x8002CC04: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8002CC08: jr          $ra
    // 0x8002CC0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002CC0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002CC10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CC10: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8002CC14: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x8002CC18: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8002CC1C: addiu       $s0, $s0, 0x2076
    ctx->r16 = ADD32(ctx->r16, 0X2076);
    // 0x8002CC20: sw          $ra, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r31;
    // 0x8002CC24: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x8002CC28: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x8002CC2C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002CC30: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x8002CC34: addiu       $s1, $s1, 0x5586
    ctx->r17 = ADD32(ctx->r17, 0X5586);
    // 0x8002CC38: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x8002CC3C: jal         0x8000705C
    // 0x8002CC40: sb          $v1, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r3;
    func_8000705C(rdram, ctx);
        goto after_0;
    // 0x8002CC40: sb          $v1, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r3;
    after_0:
    // 0x8002CC44: jal         0x800533F0
    // 0x8002CC48: nop

    func_800533F0(rdram, ctx);
        goto after_1;
    // 0x8002CC48: nop

    after_1:
    // 0x8002CC4C: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x8002CC50: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8002CC54: lb          $v1, 0x26BE($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X26BE);
    // 0x8002CC58: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8002CC5C: beq         $v1, $a0, L_8002CC74
    if (ctx->r3 == ctx->r4) {
        // 0x8002CC60: sb          $v0, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r2;
            goto L_8002CC74;
    }
    // 0x8002CC60: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x8002CC64: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002CC68: lb          $v0, 0x7B0E($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7B0E);
    // 0x8002CC6C: bne         $v0, $a0, L_8002CC90
    if (ctx->r2 != ctx->r4) {
        // 0x8002CC70: nop
    
            goto L_8002CC90;
    }
    // 0x8002CC70: nop

L_8002CC74:
    // 0x8002CC74: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8002CC78: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CC7C: sb          $v0, 0x5581($at)
    MEM_B(0X5581, ctx->r1) = ctx->r2;
    // 0x8002CC80: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CC84: sb          $zero, 0x5582($at)
    MEM_B(0X5582, ctx->r1) = 0;
    // 0x8002CC88: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CC8C: sb          $zero, 0x2074($at)
    MEM_B(0X2074, ctx->r1) = 0;
L_8002CC90:
    // 0x8002CC90: lw          $ra, 0x68($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X68);
    // 0x8002CC94: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x8002CC98: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x8002CC9C: jr          $ra
    // 0x8002CCA0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8002CCA0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8002CCB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CCB0: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x8002CCB4: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8002CCB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002CCBC: beq         $a0, $v0, L_8002CDF8
    if (ctx->r4 == ctx->r2) {
        // 0x8002CCC0: slti        $v0, $a0, 0x2
        ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
            goto L_8002CDF8;
    }
    // 0x8002CCC0: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8002CCC4: beql        $v0, $zero, L_8002CCDC
    if (ctx->r2 == 0) {
        // 0x8002CCC8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8002CCDC;
    }
    goto skip_0;
    // 0x8002CCC8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8002CCCC: beq         $a0, $zero, L_8002CCF4
    if (ctx->r4 == 0) {
        // 0x8002CCD0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8002CCF4;
    }
    // 0x8002CCD0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8002CCD4: j           L_8002CFB0
    // 0x8002CCD8: nop

        goto L_8002CFB0;
    // 0x8002CCD8: nop

L_8002CCDC:
    // 0x8002CCDC: beq         $a0, $v0, L_8002CF20
    if (ctx->r4 == ctx->r2) {
        // 0x8002CCE0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002CF20;
    }
    // 0x8002CCE0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002CCE4: beq         $a0, $v0, L_8002CF64
    if (ctx->r4 == ctx->r2) {
        // 0x8002CCE8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8002CF64;
    }
    // 0x8002CCE8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8002CCEC: j           L_8002CFB0
    // 0x8002CCF0: nop

        goto L_8002CFB0;
    // 0x8002CCF0: nop

L_8002CCF4:
    // 0x8002CCF4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CCF8: lwc1        $f4, 0x6D60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6D60);
    // 0x8002CCFC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8002CD00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002CD04: nop

    // 0x8002CD08: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8002CD0C: nop

    // 0x8002CD10: nop

    // 0x8002CD14: bc1t        L_8002CFB0
    if (c1cs) {
        // 0x8002CD18: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002CFB0;
    }
    // 0x8002CD18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002CD1C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CD20: lwc1        $f0, 0x6D58($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6D58);
    // 0x8002CD24: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8002CD28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002CD2C: nop

    // 0x8002CD30: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8002CD34: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002CD38: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CD3C: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8002CD40: bc1f        L_8002CD64
    if (!c1cs) {
        // 0x8002CD44: nop
    
            goto L_8002CD64;
    }
    // 0x8002CD44: nop

    // 0x8002CD48: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002CD4C: ldc1        $f2, -0x28C0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X28C0);
    // 0x8002CD50: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8002CD54: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8002CD58: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8002CD5C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CD60: swc1        $f0, 0x6D58($at)
    MEM_W(0X6D58, ctx->r1) = ctx->f0.u32l;
L_8002CD64:
    // 0x8002CD64: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8002CD68: nop

    // 0x8002CD6C: bc1f        L_8002CD8C
    if (!c1cs) {
        // 0x8002CD70: nop
    
            goto L_8002CD8C;
    }
    // 0x8002CD70: nop

    // 0x8002CD74: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8002CD78: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002CD7C: nop

    // 0x8002CD80: add.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8002CD84: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CD88: swc1        $f0, 0x6D60($at)
    MEM_W(0X6D60, ctx->r1) = ctx->f0.u32l;
L_8002CD8C:
    // 0x8002CD8C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CD90: lwc1        $f0, 0x6D5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6D5C);
    // 0x8002CD94: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8002CD98: nop

    // 0x8002CD9C: bc1f        L_8002CDC0
    if (!c1cs) {
        // 0x8002CDA0: nop
    
            goto L_8002CDC0;
    }
    // 0x8002CDA0: nop

    // 0x8002CDA4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002CDA8: ldc1        $f2, -0x28B8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X28B8);
    // 0x8002CDAC: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8002CDB0: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8002CDB4: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8002CDB8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CDBC: swc1        $f0, 0x6D5C($at)
    MEM_W(0X6D5C, ctx->r1) = ctx->f0.u32l;
L_8002CDC0:
    // 0x8002CDC0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CDC4: lwc1        $f2, 0x6D64($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6D64);
    // 0x8002CDC8: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8002CDCC: nop

    // 0x8002CDD0: nop

    // 0x8002CDD4: bc1f        L_8002CFB0
    if (!c1cs) {
        // 0x8002CDD8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8002CFB0;
    }
    // 0x8002CDD8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8002CDDC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8002CDE0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002CDE4: nop

    // 0x8002CDE8: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8002CDEC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CDF0: j           L_8002CFB0
    // 0x8002CDF4: swc1        $f0, 0x6D64($at)
    MEM_W(0X6D64, ctx->r1) = ctx->f0.u32l;
        goto L_8002CFB0;
    // 0x8002CDF4: swc1        $f0, 0x6D64($at)
    MEM_W(0X6D64, ctx->r1) = ctx->f0.u32l;
L_8002CDF8:
    // 0x8002CDF8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CDFC: lwc1        $f4, 0x6D60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6D60);
    // 0x8002CE00: lui         $at, 0xC340
    ctx->r1 = S32(0XC340 << 16);
    // 0x8002CE04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002CE08: nop

    // 0x8002CE0C: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x8002CE10: nop

    // 0x8002CE14: nop

    // 0x8002CE18: bc1f        L_8002CE2C
    if (!c1cs) {
        // 0x8002CE1C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002CE2C;
    }
    // 0x8002CE1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002CE20: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CE24: j           L_8002CFB0
    // 0x8002CE28: sb          $zero, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = 0;
        goto L_8002CFB0;
    // 0x8002CE28: sb          $zero, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = 0;
L_8002CE2C:
    // 0x8002CE2C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CE30: lwc1        $f6, 0x6D58($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6D58);
    // 0x8002CE34: lui         $at, 0xC380
    ctx->r1 = S32(0XC380 << 16);
    // 0x8002CE38: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002CE3C: nop

    // 0x8002CE40: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8002CE44: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002CE48: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CE4C: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8002CE50: bc1f        L_8002CE74
    if (!c1cs) {
        // 0x8002CE54: nop
    
            goto L_8002CE74;
    }
    // 0x8002CE54: nop

    // 0x8002CE58: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002CE5C: ldc1        $f2, -0x28B0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X28B0);
    // 0x8002CE60: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8002CE64: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8002CE68: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8002CE6C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CE70: swc1        $f0, 0x6D58($at)
    MEM_W(0X6D58, ctx->r1) = ctx->f0.u32l;
L_8002CE74:
    // 0x8002CE74: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x8002CE78: nop

    // 0x8002CE7C: bc1f        L_8002CE9C
    if (!c1cs) {
        // 0x8002CE80: nop
    
            goto L_8002CE9C;
    }
    // 0x8002CE80: nop

    // 0x8002CE84: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8002CE88: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002CE8C: nop

    // 0x8002CE90: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8002CE94: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CE98: swc1        $f0, 0x6D60($at)
    MEM_W(0X6D60, ctx->r1) = ctx->f0.u32l;
L_8002CE9C:
    // 0x8002CE9C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CEA0: lwc1        $f4, 0x6D5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6D5C);
    // 0x8002CEA4: lui         $at, 0x4410
    ctx->r1 = S32(0X4410 << 16);
    // 0x8002CEA8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002CEAC: nop

    // 0x8002CEB0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8002CEB4: nop

    // 0x8002CEB8: bc1f        L_8002CEDC
    if (!c1cs) {
        // 0x8002CEBC: nop
    
            goto L_8002CEDC;
    }
    // 0x8002CEBC: nop

    // 0x8002CEC0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002CEC4: ldc1        $f2, -0x28A8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X28A8);
    // 0x8002CEC8: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8002CECC: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8002CED0: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8002CED4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CED8: swc1        $f0, 0x6D5C($at)
    MEM_W(0X6D5C, ctx->r1) = ctx->f0.u32l;
L_8002CEDC:
    // 0x8002CEDC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CEE0: lwc1        $f2, 0x6D64($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6D64);
    // 0x8002CEE4: lui         $at, 0x43D8
    ctx->r1 = S32(0X43D8 << 16);
    // 0x8002CEE8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002CEEC: nop

    // 0x8002CEF0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8002CEF4: nop

    // 0x8002CEF8: nop

    // 0x8002CEFC: bc1f        L_8002CFB0
    if (!c1cs) {
        // 0x8002CF00: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8002CFB0;
    }
    // 0x8002CF00: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8002CF04: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8002CF08: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002CF0C: nop

    // 0x8002CF10: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8002CF14: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CF18: j           L_8002CFB0
    // 0x8002CF1C: swc1        $f0, 0x6D64($at)
    MEM_W(0X6D64, ctx->r1) = ctx->f0.u32l;
        goto L_8002CFB0;
    // 0x8002CF1C: swc1        $f0, 0x6D64($at)
    MEM_W(0X6D64, ctx->r1) = ctx->f0.u32l;
L_8002CF20:
    // 0x8002CF20: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8002CF24: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002CF28: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8002CF2C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002CF30: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8002CF34: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CF38: sb          $v1, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r3;
    // 0x8002CF3C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CF40: swc1        $f0, 0x6D5C($at)
    MEM_W(0X6D5C, ctx->r1) = ctx->f0.u32l;
    // 0x8002CF44: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CF48: swc1        $f0, 0x6D58($at)
    MEM_W(0X6D58, ctx->r1) = ctx->f0.u32l;
    // 0x8002CF4C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CF50: swc1        $f2, 0x6D64($at)
    MEM_W(0X6D64, ctx->r1) = ctx->f2.u32l;
    // 0x8002CF54: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CF58: swc1        $f2, 0x6D60($at)
    MEM_W(0X6D60, ctx->r1) = ctx->f2.u32l;
    // 0x8002CF5C: j           L_8002CFB0
    // 0x8002CF60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002CFB0;
    // 0x8002CF60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002CF64:
    // 0x8002CF64: lui         $at, 0xC380
    ctx->r1 = S32(0XC380 << 16);
    // 0x8002CF68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002CF6C: lui         $at, 0x4410
    ctx->r1 = S32(0X4410 << 16);
    // 0x8002CF70: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8002CF74: lui         $at, 0xC340
    ctx->r1 = S32(0XC340 << 16);
    // 0x8002CF78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002CF7C: lui         $at, 0x43D8
    ctx->r1 = S32(0X43D8 << 16);
    // 0x8002CF80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002CF84: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002CF88: sb          $zero, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = 0;
    // 0x8002CF8C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CF90: swc1        $f0, 0x6D58($at)
    MEM_W(0X6D58, ctx->r1) = ctx->f0.u32l;
    // 0x8002CF94: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CF98: swc1        $f2, 0x6D5C($at)
    MEM_W(0X6D5C, ctx->r1) = ctx->f2.u32l;
    // 0x8002CF9C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CFA0: swc1        $f4, 0x6D60($at)
    MEM_W(0X6D60, ctx->r1) = ctx->f4.u32l;
    // 0x8002CFA4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002CFA8: swc1        $f6, 0x6D64($at)
    MEM_W(0X6D64, ctx->r1) = ctx->f6.u32l;
    // 0x8002CFAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002CFB0:
    // 0x8002CFB0: jr          $ra
    // 0x8002CFB4: nop

    return;
    // 0x8002CFB4: nop

;}
RECOMP_FUNC void func_8002CFB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CFB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002CFBC: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x8002CFC0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002CFC4: sra         $s0, $a0, 24
    ctx->r16 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8002CFC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002CFCC: jal         0x8002CCB0
    // 0x8002CFD0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8002CCB0(rdram, ctx);
        goto after_0;
    // 0x8002CFD0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8002CFD4: bne         $v0, $zero, L_8002CFE4
    if (ctx->r2 != 0) {
        // 0x8002CFD8: nop
    
            goto L_8002CFE4;
    }
    // 0x8002CFD8: nop

    // 0x8002CFDC: jal         0x8002CCB0
    // 0x8002CFE0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8002CCB0(rdram, ctx);
        goto after_1;
    // 0x8002CFE0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
L_8002CFE4:
    // 0x8002CFE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002CFE8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002CFEC: jr          $ra
    // 0x8002CFF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002CFF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002CFF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CFF4: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x8002CFF8: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8002CFFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002D000: beq         $a0, $v0, L_8002D068
    if (ctx->r4 == ctx->r2) {
        // 0x8002D004: slti        $v0, $a0, 0x2
        ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
            goto L_8002D068;
    }
    // 0x8002D004: slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8002D008: beql        $v0, $zero, L_8002D020
    if (ctx->r2 == 0) {
        // 0x8002D00C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8002D020;
    }
    goto skip_0;
    // 0x8002D00C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8002D010: beq         $a0, $zero, L_8002D038
    if (ctx->r4 == 0) {
        // 0x8002D014: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8002D038;
    }
    // 0x8002D014: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8002D018: j           L_8002D0CC
    // 0x8002D01C: nop

        goto L_8002D0CC;
    // 0x8002D01C: nop

L_8002D020:
    // 0x8002D020: beq         $a0, $v0, L_8002D0A4
    if (ctx->r4 == ctx->r2) {
        // 0x8002D024: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002D0A4;
    }
    // 0x8002D024: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D028: beq         $a0, $v0, L_8002D0C4
    if (ctx->r4 == ctx->r2) {
        // 0x8002D02C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002D0C4;
    }
    // 0x8002D02C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002D030: j           L_8002D0CC
    // 0x8002D034: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8002D0CC;
    // 0x8002D034: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8002D038:
    // 0x8002D038: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002D03C: lbu         $v1, 0x6D68($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D68);
    // 0x8002D040: sltiu       $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 < 0XFF ? 1 : 0;
    // 0x8002D044: beq         $v0, $zero, L_8002D09C
    if (ctx->r2 == 0) {
        // 0x8002D048: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002D09C;
    }
    // 0x8002D048: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D04C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D050: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8002D054: addiu       $v0, $v1, 0x5
    ctx->r2 = ADD32(ctx->r3, 0X5);
    // 0x8002D058: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D05C: sb          $v0, 0x6D68($at)
    MEM_B(0X6D68, ctx->r1) = ctx->r2;
    // 0x8002D060: j           L_8002D0CC
    // 0x8002D064: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8002D0CC;
    // 0x8002D064: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8002D068:
    // 0x8002D068: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8002D06C: lbu         $v1, 0x6D68($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D68);
    // 0x8002D070: beq         $v1, $zero, L_8002D094
    if (ctx->r3 == 0) {
        // 0x8002D074: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8002D094;
    }
    // 0x8002D074: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8002D078: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D07C: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
    // 0x8002D080: addiu       $v0, $v1, -0x5
    ctx->r2 = ADD32(ctx->r3, -0X5);
    // 0x8002D084: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D088: sb          $v0, 0x6D68($at)
    MEM_B(0X6D68, ctx->r1) = ctx->r2;
    // 0x8002D08C: j           L_8002D0CC
    // 0x8002D090: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8002D0CC;
    // 0x8002D090: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8002D094:
    // 0x8002D094: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D098: sb          $zero, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = 0;
L_8002D09C:
    // 0x8002D09C: j           L_8002D0CC
    // 0x8002D0A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002D0CC;
    // 0x8002D0A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002D0A4:
    // 0x8002D0A4: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8002D0A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002D0AC: sb          $v1, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r3;
    // 0x8002D0B0: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8002D0B4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D0B8: sb          $v1, 0x6D68($at)
    MEM_B(0X6D68, ctx->r1) = ctx->r3;
    // 0x8002D0BC: j           L_8002D0CC
    // 0x8002D0C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002D0CC;
    // 0x8002D0C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002D0C4:
    // 0x8002D0C4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8002D0C8: sb          $zero, 0x6D68($at)
    MEM_B(0X6D68, ctx->r1) = 0;
L_8002D0CC:
    // 0x8002D0CC: jr          $ra
    // 0x8002D0D0: nop

    return;
    // 0x8002D0D0: nop

;}
