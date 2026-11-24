#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80062894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062894: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80062898: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006289C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800628A0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800628A4: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800628A8: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x800628AC: addiu       $a1, $a1, 0x4500
    ctx->r5 = ADD32(ctx->r5, 0X4500);
    // 0x800628B0: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x800628B4: addiu       $a2, $a2, 0x46EC
    ctx->r6 = ADD32(ctx->r6, 0X46EC);
    // 0x800628B8: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800628BC: jal         0x80064370
    // 0x800628C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80064370(rdram, ctx);
        goto after_0;
    // 0x800628C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x800628C4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800628C8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800628CC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800628D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800628D4: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x800628D8: jal         0x800655B0
    // 0x800628DC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800655B0(rdram, ctx);
        goto after_1;
    // 0x800628DC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x800628E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800628E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800628E8: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800628EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800628F0: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x800628F4: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x800628F8: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x800628FC: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80062900: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x80062904: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x80062908: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x8006290C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80062910: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80062914: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80062918: jr          $ra
    // 0x8006291C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006291C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80062920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062920: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80062924: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80062928: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8006292C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80062930: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80062934: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80062938: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x8006293C: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x80062940: addiu       $a1, $a1, 0x3530
    ctx->r5 = ADD32(ctx->r5, 0X3530);
    // 0x80062944: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80062948: addiu       $a2, $a2, 0x360C
    ctx->r6 = ADD32(ctx->r6, 0X360C);
    // 0x8006294C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80062950: jal         0x80064370
    // 0x80062954: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_80064370(rdram, ctx);
        goto after_0;
    // 0x80062954: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_0:
    // 0x80062958: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x8006295C: sw          $s1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r17;
    // 0x80062960: sw          $s2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r18;
    // 0x80062964: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80062968: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8006296C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80062970: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80062974: jr          $ra
    // 0x80062978: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80062978: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8006297C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006297C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80062980: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80062984: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80062988: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8006298C: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80062990: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80062994: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x80062998: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x8006299C: addiu       $a1, $a1, 0x4390
    ctx->r5 = ADD32(ctx->r5, 0X4390);
    // 0x800629A0: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x800629A4: addiu       $a2, $a2, 0x44D0
    ctx->r6 = ADD32(ctx->r6, 0X44D0);
    // 0x800629A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800629AC: jal         0x80064370
    // 0x800629B0: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    func_80064370(rdram, ctx);
        goto after_0;
    // 0x800629B0: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_0:
    // 0x800629B4: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x800629B8: sw          $s1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r17;
    // 0x800629BC: sw          $s2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r18;
    // 0x800629C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800629C4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800629C8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800629CC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800629D0: jr          $ra
    // 0x800629D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800629D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800629D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800629D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800629DC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800629E0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800629E4: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x800629E8: addiu       $a1, $a1, 0x5390
    ctx->r5 = ADD32(ctx->r5, 0X5390);
    // 0x800629EC: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x800629F0: addiu       $a2, $a2, 0x5490
    ctx->r6 = ADD32(ctx->r6, 0X5490);
    // 0x800629F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800629F8: jal         0x80064370
    // 0x800629FC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_80064370(rdram, ctx);
        goto after_0;
    // 0x800629FC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x80062A00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80062A04: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80062A08: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x80062A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062A10: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80062A14: jr          $ra
    // 0x80062A18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80062A18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80062A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062A20: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80062A24: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80062A28: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80062A2C: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x80062A30: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80062A34: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x80062A38: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80062A3C: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // 0x80062A40: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80062A44: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80062A48: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80062A4C: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80062A50: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80062A54: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80062A58: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80062A5C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80062A60: beq         $s4, $zero, L_80062E30
    if (ctx->r20 == 0) {
        // 0x80062A64: addu        $a1, $t0, $zero
        ctx->r5 = ADD32(ctx->r8, 0);
            goto L_80062E30;
    }
    // 0x80062A64: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x80062A68: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
    // 0x80062A6C: lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // 0x80062A70: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x80062A74: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80062A78: lui         $v1, 0xB00
    ctx->r3 = S32(0XB00 << 16);
    // 0x80062A7C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80062A80: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80062A84: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80062A88: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80062A8C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80062A90: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x80062A94: lui         $v1, 0x1FFF
    ctx->r3 = S32(0X1FFF << 16);
    // 0x80062A98: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x80062A9C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80062AA0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80062AA4: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80062AA8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x80062AAC: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x80062AB0: addu        $v0, $s4, $a1
    ctx->r2 = ADD32(ctx->r20, ctx->r5);
    // 0x80062AB4: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80062AB8: beq         $v0, $zero, L_80062AC8
    if (ctx->r2 == 0) {
        // 0x80062ABC: addu        $s7, $zero, $zero
        ctx->r23 = ADD32(0, 0);
            goto L_80062AC8;
    }
    // 0x80062ABC: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // 0x80062AC0: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80062AC4: sltu        $a0, $zero, $v0
    ctx->r4 = 0 < ctx->r2 ? 1 : 0;
L_80062AC8:
    // 0x80062AC8: beq         $a0, $zero, L_80062AD4
    if (ctx->r4 == 0) {
        // 0x80062ACC: addu        $s1, $s4, $zero
        ctx->r17 = ADD32(ctx->r20, 0);
            goto L_80062AD4;
    }
    // 0x80062ACC: addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
    // 0x80062AD0: subu        $s1, $v1, $a1
    ctx->r17 = SUB32(ctx->r3, ctx->r5);
L_80062AD4:
    // 0x80062AD4: lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X3C);
    // 0x80062AD8: beq         $v1, $zero, L_80062AE8
    if (ctx->r3 == 0) {
        // 0x80062ADC: addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
            goto L_80062AE8;
    }
    // 0x80062ADC: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80062AE0: j           L_80062AEC
    // 0x80062AE4: subu        $s6, $v0, $v1
    ctx->r22 = SUB32(ctx->r2, ctx->r3);
        goto L_80062AEC;
    // 0x80062AE4: subu        $s6, $v0, $v1
    ctx->r22 = SUB32(ctx->r2, ctx->r3);
L_80062AE8:
    // 0x80062AE8: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
L_80062AEC:
    // 0x80062AEC: subu        $a2, $s1, $s6
    ctx->r6 = SUB32(ctx->r17, ctx->r22);
    // 0x80062AF0: nor         $v0, $zero, $a2
    ctx->r2 = ~(0 | ctx->r6);
    // 0x80062AF4: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80062AF8: and         $a2, $a2, $v0
    ctx->r6 = ctx->r6 & ctx->r2;
    // 0x80062AFC: addiu       $v0, $a2, 0xF
    ctx->r2 = ADD32(ctx->r6, 0XF);
    // 0x80062B00: sra         $s2, $v0, 4
    ctx->r18 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80062B04: sll         $t1, $s2, 3
    ctx->r9 = S32(ctx->r18 << 3);
    // 0x80062B08: beq         $a0, $zero, L_80062CD4
    if (ctx->r4 == 0) {
        // 0x80062B0C: addu        $a3, $t1, $s2
        ctx->r7 = ADD32(ctx->r9, ctx->r18);
            goto L_80062CD4;
    }
    // 0x80062B0C: addu        $a3, $t1, $s2
    ctx->r7 = ADD32(ctx->r9, ctx->r18);
    // 0x80062B10: lh          $v0, 0x0($s5)
    ctx->r2 = MEM_H(ctx->r21, 0X0);
    // 0x80062B14: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80062B18: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80062B1C: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x80062B20: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80062B24: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80062B28: jal         0x800633AC
    // 0x80062B2C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800633AC(rdram, ctx);
        goto after_0;
    // 0x80062B2C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x80062B30: lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X3C);
    // 0x80062B34: beq         $v1, $zero, L_80062B4C
    if (ctx->r3 == 0) {
        // 0x80062B38: addu        $t0, $v0, $zero
        ctx->r8 = ADD32(ctx->r2, 0);
            goto L_80062B4C;
    }
    // 0x80062B38: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80062B3C: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80062B40: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80062B44: j           L_80062B54
    // 0x80062B48: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
        goto L_80062B54;
    // 0x80062B48: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_80062B4C:
    // 0x80062B4C: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80062B50: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
L_80062B54:
    // 0x80062B54: sh          $v0, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r2;
    // 0x80062B58: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80062B5C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80062B60: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x80062B64: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x80062B68: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x80062B6C: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80062B70: srl         $v1, $v1, 4
    ctx->r3 = S32(U32(ctx->r3) >> 4);
    // 0x80062B74: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80062B78: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80062B7C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80062B80: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062B84: sw          $a1, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r5;
    // 0x80062B88: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80062B8C: sw          $a0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r4;
    // 0x80062B90: lh          $s3, 0x0($s5)
    ctx->r19 = MEM_H(ctx->r21, 0X0);
    // 0x80062B94: slt         $v0, $s1, $s4
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80062B98: beq         $v0, $zero, L_80062C9C
    if (ctx->r2 == 0) {
        // 0x80062B9C: sll         $v0, $s7, 16
        ctx->r2 = S32(ctx->r23 << 16);
            goto L_80062C9C;
    }
    // 0x80062B9C: sll         $v0, $s7, 16
    ctx->r2 = S32(ctx->r23 << 16);
    // 0x80062BA0: sra         $s6, $v0, 16
    ctx->r22 = S32(SIGNED(ctx->r2) >> 16);
L_80062BA4:
    // 0x80062BA4: addiu       $v1, $s2, 0x1
    ctx->r3 = ADD32(ctx->r18, 0X1);
    // 0x80062BA8: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80062BAC: addu        $v1, $s3, $v1
    ctx->r3 = ADD32(ctx->r19, ctx->r3);
    // 0x80062BB0: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x80062BB4: addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // 0x80062BB8: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80062BBC: addiu       $v0, $zero, -0x20
    ctx->r2 = ADD32(0, -0X20);
    // 0x80062BC0: and         $s5, $v1, $v0
    ctx->r21 = ctx->r3 & ctx->r2;
    // 0x80062BC4: nor         $v0, $zero, $a0
    ctx->r2 = ~(0 | ctx->r4);
    // 0x80062BC8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80062BCC: sltu        $v1, $zero, $a0
    ctx->r3 = 0 < ctx->r4 ? 1 : 0;
    // 0x80062BD0: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80062BD4: beq         $v0, $zero, L_80062BE4
    if (ctx->r2 == 0) {
        // 0x80062BD8: subu        $s4, $s4, $s1
        ctx->r20 = SUB32(ctx->r20, ctx->r17);
            goto L_80062BE4;
    }
    // 0x80062BD8: subu        $s4, $s4, $s1
    ctx->r20 = SUB32(ctx->r20, ctx->r17);
    // 0x80062BDC: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x80062BE0: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
L_80062BE4:
    // 0x80062BE4: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x80062BE8: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80062BEC: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80062BF0: sltu        $v0, $s4, $v1
    ctx->r2 = ctx->r20 < ctx->r3 ? 1 : 0;
    // 0x80062BF4: bne         $v0, $zero, L_80062C00
    if (ctx->r2 != 0) {
        // 0x80062BF8: addu        $s1, $s4, $zero
        ctx->r17 = ADD32(ctx->r20, 0);
            goto L_80062C00;
    }
    // 0x80062BF8: addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
    // 0x80062BFC: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
L_80062C00:
    // 0x80062C00: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80062C04: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80062C08: lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X3C);
    // 0x80062C0C: sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21 << 16);
    // 0x80062C10: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80062C14: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80062C18: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x80062C1C: addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // 0x80062C20: addu        $a2, $s1, $v1
    ctx->r6 = ADD32(ctx->r17, ctx->r3);
    // 0x80062C24: nor         $v0, $zero, $a2
    ctx->r2 = ~(0 | ctx->r6);
    // 0x80062C28: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80062C2C: and         $a2, $a2, $v0
    ctx->r6 = ctx->r6 & ctx->r2;
    // 0x80062C30: addiu       $v0, $a2, 0xF
    ctx->r2 = ADD32(ctx->r6, 0XF);
    // 0x80062C34: sra         $s2, $v0, 4
    ctx->r18 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80062C38: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x80062C3C: sll         $a3, $s2, 3
    ctx->r7 = S32(ctx->r18 << 3);
    // 0x80062C40: addu        $a3, $a3, $s2
    ctx->r7 = ADD32(ctx->r7, ctx->r18);
    // 0x80062C44: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x80062C48: jal         0x800633AC
    // 0x80062C4C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800633AC(rdram, ctx);
        goto after_1;
    // 0x80062C4C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80062C50: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80062C54: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x80062C58: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80062C5C: lui         $a2, 0xFF
    ctx->r6 = S32(0XFF << 16);
    // 0x80062C60: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80062C64: lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X3C);
    // 0x80062C68: sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19 << 16);
    // 0x80062C6C: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x80062C70: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80062C74: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80062C78: lui         $v0, 0xA00
    ctx->r2 = S32(0XA00 << 16);
    // 0x80062C7C: sw          $a0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r4;
    // 0x80062C80: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80062C84: addu        $v1, $s5, $v1
    ctx->r3 = ADD32(ctx->r21, ctx->r3);
    // 0x80062C88: and         $v1, $v1, $a2
    ctx->r3 = ctx->r3 & ctx->r6;
    // 0x80062C8C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80062C90: slt         $v0, $s1, $s4
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80062C94: bne         $v0, $zero, L_80062BA4
    if (ctx->r2 != 0) {
        // 0x80062C98: sw          $v1, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r3;
            goto L_80062BA4;
    }
    // 0x80062C98: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
L_80062C9C:
    // 0x80062C9C: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x80062CA0: lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X3C);
    // 0x80062CA4: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    // 0x80062CA8: addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
    // 0x80062CAC: sw          $a0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r4;
    // 0x80062CB0: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x80062CB4: addu        $v1, $s4, $v1
    ctx->r3 = ADD32(ctx->r20, ctx->r3);
    // 0x80062CB8: andi        $v1, $v1, 0xF
    ctx->r3 = ctx->r3 & 0XF;
    // 0x80062CBC: sw          $v1, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r3;
    // 0x80062CC0: sll         $v1, $s2, 3
    ctx->r3 = S32(ctx->r18 << 3);
    // 0x80062CC4: addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // 0x80062CC8: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80062CCC: j           L_80062E34
    // 0x80062CD0: sw          $a0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r4;
        goto L_80062E34;
    // 0x80062CD0: sw          $a0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r4;
L_80062CD4:
    // 0x80062CD4: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80062CD8: lui         $a1, 0x38E3
    ctx->r5 = S32(0X38E3 << 16);
    // 0x80062CDC: lw          $v1, 0x44($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X44);
    // 0x80062CE0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80062CE4: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    // 0x80062CE8: ori         $a1, $a1, 0x8E39
    ctx->r5 = ctx->r5 | 0X8E39;
    // 0x80062CEC: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80062CF0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80062CF4: subu        $a0, $v1, $v0
    ctx->r4 = SUB32(ctx->r3, ctx->r2);
    // 0x80062CF8: nor         $v0, $zero, $a0
    ctx->r2 = ~(0 | ctx->r4);
    // 0x80062CFC: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80062D00: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // 0x80062D04: mult        $a0, $a1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062D08: sll         $s1, $s2, 4
    ctx->r17 = S32(ctx->r18 << 4);
    // 0x80062D0C: sra         $v1, $a0, 31
    ctx->r3 = S32(SIGNED(ctx->r4) >> 31);
    // 0x80062D10: mfhi        $t2
    ctx->r10 = hi;
    // 0x80062D14: sra         $v0, $t2, 1
    ctx->r2 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80062D18: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80062D1C: sll         $s3, $v0, 4
    ctx->r19 = S32(ctx->r2 << 4);
    // 0x80062D20: addu        $v1, $s1, $s6
    ctx->r3 = ADD32(ctx->r17, ctx->r22);
    // 0x80062D24: slt         $v0, $v1, $s3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80062D28: bnel        $v0, $zero, L_80062D30
    if (ctx->r2 != 0) {
        // 0x80062D2C: addu        $s3, $v1, $zero
        ctx->r19 = ADD32(ctx->r3, 0);
            goto L_80062D30;
    }
    goto skip_0;
    // 0x80062D2C: addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    skip_0:
L_80062D30:
    // 0x80062D30: andi        $v0, $s3, 0xF
    ctx->r2 = ctx->r19 & 0XF;
    // 0x80062D34: subu        $v0, $s3, $v0
    ctx->r2 = SUB32(ctx->r19, ctx->r2);
    // 0x80062D38: slt         $v0, $v0, $s4
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80062D3C: beq         $v0, $zero, L_80062DC8
    if (ctx->r2 == 0) {
        // 0x80062D40: subu        $a3, $a3, $a0
        ctx->r7 = SUB32(ctx->r7, ctx->r4);
            goto L_80062DC8;
    }
    // 0x80062D40: subu        $a3, $a3, $a0
    ctx->r7 = SUB32(ctx->r7, ctx->r4);
    // 0x80062D44: lh          $v0, 0x0($s5)
    ctx->r2 = MEM_H(ctx->r21, 0X0);
    // 0x80062D48: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80062D4C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80062D50: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80062D54: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x80062D58: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80062D5C: subu        $a2, $s1, $s3
    ctx->r6 = SUB32(ctx->r17, ctx->r19);
    // 0x80062D60: jal         0x800633AC
    // 0x80062D64: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800633AC(rdram, ctx);
        goto after_2;
    // 0x80062D64: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x80062D68: lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X3C);
    // 0x80062D6C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80062D70: beq         $v1, $zero, L_80062D88
    if (ctx->r3 == 0) {
        // 0x80062D74: addu        $t0, $v0, $zero
        ctx->r8 = ADD32(ctx->r2, 0);
            goto L_80062D88;
    }
    // 0x80062D74: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80062D78: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80062D7C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80062D80: j           L_80062D90
    // 0x80062D84: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
        goto L_80062D90;
    // 0x80062D84: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_80062D88:
    // 0x80062D88: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80062D8C: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
L_80062D90:
    // 0x80062D90: sh          $v0, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r2;
    // 0x80062D94: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x80062D98: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x80062D9C: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x80062DA0: sw          $v1, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r3;
    // 0x80062DA4: lw          $v1, 0x44($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X44);
    // 0x80062DA8: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x80062DAC: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x80062DB0: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x80062DB4: sll         $v0, $s2, 3
    ctx->r2 = S32(ctx->r18 << 3);
    // 0x80062DB8: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80062DBC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80062DC0: j           L_80062DDC
    // 0x80062DC4: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
        goto L_80062DDC;
    // 0x80062DC4: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
L_80062DC8:
    // 0x80062DC8: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x80062DCC: addu        $v1, $t1, $s2
    ctx->r3 = ADD32(ctx->r9, ctx->r18);
    // 0x80062DD0: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80062DD4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80062DD8: sw          $v0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r2;
L_80062DDC:
    // 0x80062DDC: beq         $s3, $zero, L_80062E34
    if (ctx->r19 == 0) {
        // 0x80062DE0: addu        $v0, $t0, $zero
        ctx->r2 = ADD32(ctx->r8, 0);
            goto L_80062E34;
    }
    // 0x80062DE0: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    // 0x80062DE4: beq         $fp, $zero, L_80062DFC
    if (ctx->r30 == 0) {
        // 0x80062DE8: sw          $zero, 0x3C($s0)
        MEM_W(0X3C, ctx->r16) = 0;
            goto L_80062DFC;
    }
    // 0x80062DE8: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80062DEC: addu        $v0, $s6, $s1
    ctx->r2 = ADD32(ctx->r22, ctx->r17);
    // 0x80062DF0: subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // 0x80062DF4: j           L_80062E00
    // 0x80062DF8: sll         $a2, $v0, 1
    ctx->r6 = S32(ctx->r2 << 1);
        goto L_80062E00;
    // 0x80062DF8: sll         $a2, $v0, 1
    ctx->r6 = S32(ctx->r2 << 1);
L_80062DFC:
    // 0x80062DFC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80062E00:
    // 0x80062E00: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x80062E04: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x80062E08: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x80062E0C: lh          $v0, 0x0($s5)
    ctx->r2 = MEM_H(ctx->r21, 0X0);
    // 0x80062E10: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x80062E14: sll         $v1, $s3, 1
    ctx->r3 = S32(ctx->r19 << 1);
    // 0x80062E18: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // 0x80062E1C: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80062E20: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80062E24: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x80062E28: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80062E2C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_80062E30:
    // 0x80062E30: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
L_80062E34:
    // 0x80062E34: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80062E38: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80062E3C: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80062E40: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80062E44: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80062E48: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80062E4C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80062E50: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80062E54: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80062E58: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80062E5C: jr          $ra
    // 0x80062E60: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80062E60: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80062E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062E64: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80062E68: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80062E6C: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x80062E70: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80062E74: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x80062E78: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80062E7C: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x80062E80: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80062E84: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80062E88: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80062E8C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80062E90: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80062E94: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80062E98: beq         $s6, $zero, L_800631D4
    if (ctx->r22 == 0) {
        // 0x80062E9C: addu        $s1, $s3, $zero
        ctx->r17 = ADD32(ctx->r19, 0);
            goto L_800631D4;
    }
    // 0x80062E9C: addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
    // 0x80062EA0: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x80062EA4: lw          $v1, 0x20($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X20);
    // 0x80062EA8: addu        $v0, $s6, $a0
    ctx->r2 = ADD32(ctx->r22, ctx->r4);
    // 0x80062EAC: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80062EB0: beq         $v0, $zero, L_800630B4
    if (ctx->r2 == 0) {
        // 0x80062EB4: nop
    
            goto L_800630B4;
    }
    // 0x80062EB4: nop

    // 0x80062EB8: lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X24);
    // 0x80062EBC: beq         $v0, $zero, L_800630B4
    if (ctx->r2 == 0) {
        // 0x80062EC0: subu        $s4, $v1, $a0
        ctx->r20 = SUB32(ctx->r3, ctx->r4);
            goto L_800630B4;
    }
    // 0x80062EC0: subu        $s4, $v1, $a0
    ctx->r20 = SUB32(ctx->r3, ctx->r4);
    // 0x80062EC4: blez        $s4, L_80062F30
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80062EC8: sll         $s0, $s4, 1
        ctx->r16 = S32(ctx->r20 << 1);
            goto L_80062F30;
    }
    // 0x80062EC8: sll         $s0, $s4, 1
    ctx->r16 = S32(ctx->r20 << 1);
    // 0x80062ECC: lw          $a0, 0x44($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X44);
    // 0x80062ED0: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    // 0x80062ED4: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x80062ED8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80062EDC: jalr        $v0
    // 0x80062EE0: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80062EE0: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    after_0:
    // 0x80062EE4: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80062EE8: andi        $a2, $a3, 0x7
    ctx->r6 = ctx->r7 & 0X7;
    // 0x80062EEC: addu        $s0, $s0, $a2
    ctx->r16 = ADD32(ctx->r16, ctx->r6);
    // 0x80062EF0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80062EF4: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x80062EF8: lhu         $v1, 0x0($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X0);
    // 0x80062EFC: andi        $v0, $s0, 0x7
    ctx->r2 = ctx->r16 & 0X7;
    // 0x80062F00: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x80062F04: subu        $v0, $s0, $v0
    ctx->r2 = SUB32(ctx->r16, ctx->r2);
    // 0x80062F08: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80062F0C: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x80062F10: lui         $v0, 0x800
    ctx->r2 = S32(0X800 << 16);
    // 0x80062F14: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80062F18: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x80062F1C: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // 0x80062F20: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80062F24: subu        $v0, $a3, $a2
    ctx->r2 = SUB32(ctx->r7, ctx->r6);
    // 0x80062F28: j           L_80062F34
    // 0x80062F2C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
        goto L_80062F34;
    // 0x80062F2C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_80062F30:
    // 0x80062F30: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80062F34:
    // 0x80062F34: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80062F38: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80062F3C: sh          $v0, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r2;
    // 0x80062F40: lw          $v1, 0x28($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X28);
    // 0x80062F44: lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C);
    // 0x80062F48: lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1C);
    // 0x80062F4C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80062F50: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80062F54: sw          $a0, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->r4;
    // 0x80062F58: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80062F5C: sw          $v1, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r3;
    // 0x80062F60: lh          $s5, 0x0($s5)
    ctx->r21 = MEM_H(ctx->r21, 0X0);
    // 0x80062F64: slt         $v0, $s4, $s6
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80062F68: beq         $v0, $zero, L_80063090
    if (ctx->r2 == 0) {
        // 0x80062F6C: addiu       $s1, $s3, -0x4
        ctx->r17 = ADD32(ctx->r19, -0X4);
            goto L_80063090;
    }
    // 0x80062F6C: addiu       $s1, $s3, -0x4
    ctx->r17 = ADD32(ctx->r19, -0X4);
    // 0x80062F70: sll         $v0, $s4, 1
    ctx->r2 = S32(ctx->r20 << 1);
L_80062F74:
    // 0x80062F74: lw          $a0, 0x24($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X24);
    // 0x80062F78: addu        $s5, $s5, $v0
    ctx->r21 = ADD32(ctx->r21, ctx->r2);
    // 0x80062F7C: nor         $v0, $zero, $a0
    ctx->r2 = ~(0 | ctx->r4);
    // 0x80062F80: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80062F84: sltu        $v1, $zero, $a0
    ctx->r3 = 0 < ctx->r4 ? 1 : 0;
    // 0x80062F88: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80062F8C: beq         $v0, $zero, L_80062F9C
    if (ctx->r2 == 0) {
        // 0x80062F90: subu        $s6, $s6, $s4
        ctx->r22 = SUB32(ctx->r22, ctx->r20);
            goto L_80062F9C;
    }
    // 0x80062F90: subu        $s6, $s6, $s4
    ctx->r22 = SUB32(ctx->r22, ctx->r20);
    // 0x80062F94: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x80062F98: sw          $v0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r2;
L_80062F9C:
    // 0x80062F9C: lw          $v1, 0x20($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X20);
    // 0x80062FA0: lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1C);
    // 0x80062FA4: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80062FA8: sltu        $v0, $s6, $v1
    ctx->r2 = ctx->r22 < ctx->r3 ? 1 : 0;
    // 0x80062FAC: bne         $v0, $zero, L_80062FB8
    if (ctx->r2 != 0) {
        // 0x80062FB0: addu        $s4, $s6, $zero
        ctx->r20 = ADD32(ctx->r22, 0);
            goto L_80062FB8;
    }
    // 0x80062FB0: addu        $s4, $s6, $zero
    ctx->r20 = ADD32(ctx->r22, 0);
    // 0x80062FB4: addu        $s4, $v1, $zero
    ctx->r20 = ADD32(ctx->r3, 0);
L_80062FB8:
    // 0x80062FB8: lw          $a0, 0x44($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X44);
    // 0x80062FBC: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    // 0x80062FC0: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x80062FC4: sll         $s0, $s4, 1
    ctx->r16 = S32(ctx->r20 << 1);
    // 0x80062FC8: jalr        $v0
    // 0x80062FCC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x80062FCC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80062FD0: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80062FD4: andi        $a2, $a3, 0x7
    ctx->r6 = ctx->r7 & 0X7;
    // 0x80062FD8: andi        $v1, $s5, 0x7
    ctx->r3 = ctx->r21 & 0X7;
    // 0x80062FDC: beq         $v1, $zero, L_80062FF0
    if (ctx->r3 == 0) {
        // 0x80062FE0: addu        $s0, $s0, $a2
        ctx->r16 = ADD32(ctx->r16, ctx->r6);
            goto L_80062FF0;
    }
    // 0x80062FE0: addu        $s0, $s0, $a2
    ctx->r16 = ADD32(ctx->r16, ctx->r6);
    // 0x80062FE4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80062FE8: j           L_80062FF4
    // 0x80062FEC: subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
        goto L_80062FF4;
    // 0x80062FEC: subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
L_80062FF0:
    // 0x80062FF0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80062FF4:
    // 0x80062FF4: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80062FF8: addu        $v0, $s5, $a0
    ctx->r2 = ADD32(ctx->r21, ctx->r4);
    // 0x80062FFC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80063000: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x80063004: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80063008: sw          $v0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r2;
    // 0x8006300C: andi        $v0, $s0, 0x7
    ctx->r2 = ctx->r16 & 0X7;
    // 0x80063010: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x80063014: subu        $v0, $s0, $v0
    ctx->r2 = SUB32(ctx->r16, ctx->r2);
    // 0x80063018: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8006301C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80063020: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80063024: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x80063028: sw          $v0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r2;
    // 0x8006302C: subu        $v0, $a3, $a2
    ctx->r2 = SUB32(ctx->r7, ctx->r6);
    // 0x80063030: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80063034: sltu        $v0, $zero, $a2
    ctx->r2 = 0 < ctx->r6 ? 1 : 0;
    // 0x80063038: sltu        $v1, $zero, $a0
    ctx->r3 = 0 < ctx->r4 ? 1 : 0;
    // 0x8006303C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80063040: beq         $v0, $zero, L_80063084
    if (ctx->r2 == 0) {
        // 0x80063044: addiu       $s3, $s3, 0x10
        ctx->r19 = ADD32(ctx->r19, 0X10);
            goto L_80063084;
    }
    // 0x80063044: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x80063048: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8006304C: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x80063050: lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // 0x80063054: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x80063058: addu        $v0, $s5, $a2
    ctx->r2 = ADD32(ctx->r21, ctx->r6);
    // 0x8006305C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80063060: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80063064: lui         $v1, 0xA00
    ctx->r3 = S32(0XA00 << 16);
    // 0x80063068: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8006306C: sll         $v1, $s5, 16
    ctx->r3 = S32(ctx->r21 << 16);
    // 0x80063070: sw          $v0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r2;
    // 0x80063074: sll         $v0, $s4, 1
    ctx->r2 = S32(ctx->r20 << 1);
    // 0x80063078: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8006307C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80063080: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
L_80063084:
    // 0x80063084: slt         $v0, $s4, $s6
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80063088: bne         $v0, $zero, L_80062F74
    if (ctx->r2 != 0) {
        // 0x8006308C: sll         $v0, $s4, 1
        ctx->r2 = S32(ctx->r20 << 1);
            goto L_80062F74;
    }
    // 0x8006308C: sll         $v0, $s4, 1
    ctx->r2 = S32(ctx->r20 << 1);
L_80063090:
    // 0x80063090: lw          $v1, 0x38($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X38);
    // 0x80063094: lw          $a0, 0x44($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X44);
    // 0x80063098: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x8006309C: addu        $v1, $v1, $s6
    ctx->r3 = ADD32(ctx->r3, ctx->r22);
    // 0x800630A0: sw          $v1, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->r3;
    // 0x800630A4: sll         $v1, $s6, 1
    ctx->r3 = S32(ctx->r22 << 1);
    // 0x800630A8: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800630AC: j           L_800631D8
    // 0x800630B0: sw          $a0, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r4;
        goto L_800631D8;
    // 0x800630B0: sw          $a0, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r4;
L_800630B4:
    // 0x800630B4: lw          $v1, 0x28($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X28);
    // 0x800630B8: lw          $a0, 0x44($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X44);
    // 0x800630BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800630C0: lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4);
    // 0x800630C4: sll         $s0, $s6, 1
    ctx->r16 = S32(ctx->r22 << 1);
    // 0x800630C8: addu        $a1, $a0, $s0
    ctx->r5 = ADD32(ctx->r4, ctx->r16);
    // 0x800630CC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800630D0: subu        $s1, $a1, $v0
    ctx->r17 = SUB32(ctx->r5, ctx->r2);
    // 0x800630D4: nor         $v0, $zero, $s1
    ctx->r2 = ~(0 | ctx->r17);
    // 0x800630D8: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x800630DC: and         $s1, $s1, $v0
    ctx->r17 = ctx->r17 & ctx->r2;
    // 0x800630E0: slt         $v0, $s0, $s1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800630E4: bnel        $v0, $zero, L_800630EC
    if (ctx->r2 != 0) {
        // 0x800630E8: addu        $s1, $s0, $zero
        ctx->r17 = ADD32(ctx->r16, 0);
            goto L_800630EC;
    }
    goto skip_0;
    // 0x800630E8: addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    skip_0:
L_800630EC:
    // 0x800630EC: slt         $v0, $s1, $s0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800630F0: beql        $v0, $zero, L_80063190
    if (ctx->r2 == 0) {
        // 0x800630F4: sw          $a1, 0x44($s2)
        MEM_W(0X44, ctx->r18) = ctx->r5;
            goto L_80063190;
    }
    goto skip_1;
    // 0x800630F4: sw          $a1, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r5;
    skip_1:
    // 0x800630F8: blez        $s6, L_80063164
    if (SIGNED(ctx->r22) <= 0) {
        // 0x800630FC: subu        $s0, $s0, $s1
        ctx->r16 = SUB32(ctx->r16, ctx->r17);
            goto L_80063164;
    }
    // 0x800630FC: subu        $s0, $s0, $s1
    ctx->r16 = SUB32(ctx->r16, ctx->r17);
    // 0x80063100: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    // 0x80063104: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x80063108: jalr        $v0
    // 0x8006310C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x8006310C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80063110: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80063114: andi        $a2, $a3, 0x7
    ctx->r6 = ctx->r7 & 0X7;
    // 0x80063118: addu        $s0, $s0, $a2
    ctx->r16 = ADD32(ctx->r16, ctx->r6);
    // 0x8006311C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80063120: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x80063124: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80063128: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x8006312C: lhu         $v1, 0x0($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X0);
    // 0x80063130: andi        $v0, $s0, 0x7
    ctx->r2 = ctx->r16 & 0X7;
    // 0x80063134: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x80063138: subu        $v0, $s0, $v0
    ctx->r2 = SUB32(ctx->r16, ctx->r2);
    // 0x8006313C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80063140: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x80063144: lui         $v0, 0x800
    ctx->r2 = S32(0X800 << 16);
    // 0x80063148: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8006314C: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x80063150: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80063154: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80063158: subu        $v0, $a3, $a2
    ctx->r2 = SUB32(ctx->r7, ctx->r6);
    // 0x8006315C: j           L_80063168
    // 0x80063160: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
        goto L_80063168;
    // 0x80063160: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
L_80063164:
    // 0x80063164: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80063168:
    // 0x80063168: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x8006316C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80063170: sh          $v0, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r2;
    // 0x80063174: lw          $v0, 0x38($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X38);
    // 0x80063178: lw          $v1, 0x44($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X44);
    // 0x8006317C: addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // 0x80063180: sw          $v0, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->r2;
    // 0x80063184: sll         $v0, $s6, 1
    ctx->r2 = S32(ctx->r22 << 1);
    // 0x80063188: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006318C: sw          $v1, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r3;
L_80063190:
    // 0x80063190: beq         $s1, $zero, L_800631D4
    if (ctx->r17 == 0) {
        // 0x80063194: sll         $v0, $s6, 1
        ctx->r2 = S32(ctx->r22 << 1);
            goto L_800631D4;
    }
    // 0x80063194: sll         $v0, $s6, 1
    ctx->r2 = S32(ctx->r22 << 1);
    // 0x80063198: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x8006319C: nor         $v1, $zero, $v0
    ctx->r3 = ~(0 | ctx->r2);
    // 0x800631A0: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x800631A4: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x800631A8: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800631AC: lh          $a0, 0x0($s5)
    ctx->r4 = MEM_H(ctx->r21, 0X0);
    // 0x800631B0: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800631B4: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800631B8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800631BC: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x800631C0: sw          $s1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r17;
    // 0x800631C4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800631C8: and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // 0x800631CC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800631D0: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_800631D4:
    // 0x800631D4: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
L_800631D8:
    // 0x800631D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800631DC: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800631E0: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800631E4: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800631E8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800631EC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800631F0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800631F4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800631F8: jr          $ra
    // 0x800631FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800631FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80063200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063204: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80063208: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8006320C: beq         $a1, $v0, L_80063354
    if (ctx->r5 == ctx->r2) {
        // 0x80063210: addu        $a3, $a0, $zero
        ctx->r7 = ADD32(ctx->r4, 0);
            goto L_80063354;
    }
    // 0x80063210: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80063214: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80063218: bne         $a1, $v0, L_800633A0
    if (ctx->r5 != ctx->r2) {
        // 0x8006321C: nop
    
            goto L_800633A0;
    }
    // 0x8006321C: nop

    // 0x80063220: sw          $a2, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r6;
    // 0x80063224: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80063228: lw          $v1, 0x28($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X28);
    // 0x8006322C: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x80063230: sw          $v0, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r2;
    // 0x80063234: lbu         $v1, 0x8($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X8);
    // 0x80063238: beq         $v1, $zero, L_80063250
    if (ctx->r3 == 0) {
        // 0x8006323C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80063250;
    }
    // 0x8006323C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80063240: beq         $v1, $v0, L_80063304
    if (ctx->r3 == ctx->r2) {
        // 0x80063244: nop
    
            goto L_80063304;
    }
    // 0x80063244: nop

    // 0x80063248: j           L_800633A0
    // 0x8006324C: nop

        goto L_800633A0;
    // 0x8006324C: nop

L_80063250:
    // 0x80063250: lw          $a0, 0x28($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X28);
    // 0x80063254: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x80063258: addiu       $v0, $v0, 0x2A20
    ctx->r2 = ADD32(ctx->r2, 0X2A20);
    // 0x8006325C: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x80063260: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80063264: lui         $v1, 0x38E3
    ctx->r3 = S32(0X38E3 << 16);
    // 0x80063268: ori         $v1, $v1, 0x8E39
    ctx->r3 = ctx->r3 | 0X8E39;
    // 0x8006326C: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063270: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80063274: mfhi        $t0
    ctx->r8 = hi;
    // 0x80063278: sra         $v1, $t0, 1
    ctx->r3 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8006327C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80063280: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80063284: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80063288: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8006328C: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x80063290: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x80063294: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80063298: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8006329C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800632A0: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800632A4: mflo        $v1
    ctx->r3 = lo;
    // 0x800632A8: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x800632AC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800632B0: sw          $v1, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r3;
    // 0x800632B4: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800632B8: beq         $v0, $zero, L_80063344
    if (ctx->r2 == 0) {
        // 0x800632BC: addiu       $a2, $zero, 0x20
        ctx->r6 = ADD32(0, 0X20);
            goto L_80063344;
    }
    // 0x800632BC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800632C0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800632C4: lw          $v1, 0x28($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X28);
    // 0x800632C8: sw          $v0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r2;
    // 0x800632CC: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800632D0: lw          $v1, 0x28($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X28);
    // 0x800632D4: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800632D8: sw          $v0, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r2;
    // 0x800632DC: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800632E0: lw          $v1, 0x28($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X28);
    // 0x800632E4: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x800632E8: sw          $v0, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r2;
    // 0x800632EC: lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XC);
    // 0x800632F0: lw          $a1, 0x18($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X18);
    // 0x800632F4: jal         0x80065600
    // 0x800632F8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_80065600(rdram, ctx);
        goto after_0;
    // 0x800632F8: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x800632FC: j           L_800633A0
    // 0x80063300: nop

        goto L_800633A0;
    // 0x80063300: nop

L_80063304:
    // 0x80063304: lw          $v1, 0x28($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X28);
    // 0x80063308: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x8006330C: addiu       $v0, $v0, 0x2E64
    ctx->r2 = ADD32(ctx->r2, 0X2E64);
    // 0x80063310: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x80063314: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80063318: beql        $v0, $zero, L_80063348
    if (ctx->r2 == 0) {
        // 0x8006331C: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_80063348;
    }
    goto skip_0;
    // 0x8006331C: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_0:
    // 0x80063320: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80063324: lw          $v1, 0x28($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X28);
    // 0x80063328: sw          $v0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r2;
    // 0x8006332C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80063330: lw          $v1, 0x28($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X28);
    // 0x80063334: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80063338: sw          $v0, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r2;
    // 0x8006333C: j           L_80063398
    // 0x80063340: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
        goto L_80063398;
    // 0x80063340: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
L_80063344:
    // 0x80063344: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_80063348:
    // 0x80063348: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x8006334C: j           L_800633A0
    // 0x80063350: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_800633A0;
    // 0x80063350: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_80063354:
    // 0x80063354: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x80063358: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006335C: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x80063360: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x80063364: beq         $v0, $zero, L_800633A0
    if (ctx->r2 == 0) {
        // 0x80063368: sw          $zero, 0x38($a3)
        MEM_W(0X38, ctx->r7) = 0;
            goto L_800633A0;
    }
    // 0x80063368: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x8006336C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80063370: lw          $v1, 0x28($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X28);
    // 0x80063374: sw          $v0, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r2;
    // 0x80063378: lbu         $v0, 0x8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X8);
    // 0x8006337C: beq         $v0, $zero, L_8006338C
    if (ctx->r2 == 0) {
        // 0x80063380: nop
    
            goto L_8006338C;
    }
    // 0x80063380: nop

    // 0x80063384: bne         $v0, $a0, L_800633A0
    if (ctx->r2 != ctx->r4) {
        // 0x80063388: nop
    
            goto L_800633A0;
    }
    // 0x80063388: nop

L_8006338C:
    // 0x8006338C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80063390: beq         $v0, $zero, L_800633A0
    if (ctx->r2 == 0) {
        // 0x80063394: nop
    
            goto L_800633A0;
    }
    // 0x80063394: nop

L_80063398:
    // 0x80063398: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x8006339C: sw          $v0, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r2;
L_800633A0:
    // 0x800633A0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800633A4: jr          $ra
    // 0x800633A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800633A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800633AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800633AC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800633B0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800633B4: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800633B8: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x800633BC: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x800633C0: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800633C4: lhu         $s5, 0x4A($sp)
    ctx->r21 = MEM_HU(ctx->r29, 0X4A);
    // 0x800633C8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800633CC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800633D0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800633D4: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800633D8: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x800633DC: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x800633E0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800633E4: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x800633E8: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800633EC: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800633F0: blez        $s1, L_8006345C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800633F4: addu        $s4, $s3, $zero
        ctx->r20 = ADD32(ctx->r19, 0);
            goto L_8006345C;
    }
    // 0x800633F4: addu        $s4, $s3, $zero
    ctx->r20 = ADD32(ctx->r19, 0);
    // 0x800633F8: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x800633FC: lw          $a0, 0x44($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X44);
    // 0x80063400: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    // 0x80063404: jalr        $v0
    // 0x80063408: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80063408: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_0:
    // 0x8006340C: andi        $a3, $v0, 0x7
    ctx->r7 = ctx->r2 & 0X7;
    // 0x80063410: addu        $s1, $s1, $a3
    ctx->r17 = ADD32(ctx->r17, ctx->r7);
    // 0x80063414: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80063418: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8006341C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80063420: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80063424: andi        $v1, $s3, 0xFFFF
    ctx->r3 = ctx->r19 & 0XFFFF;
    // 0x80063428: lui         $a0, 0x800
    ctx->r4 = S32(0X800 << 16);
    // 0x8006342C: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x80063430: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80063434: andi        $v1, $s1, 0x7
    ctx->r3 = ctx->r17 & 0X7;
    // 0x80063438: addiu       $v1, $v1, -0x8
    ctx->r3 = ADD32(ctx->r3, -0X8);
    // 0x8006343C: subu        $v1, $s1, $v1
    ctx->r3 = SUB32(ctx->r17, ctx->r3);
    // 0x80063440: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80063444: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // 0x80063448: lui         $v1, 0x400
    ctx->r3 = S32(0X400 << 16);
    // 0x8006344C: subu        $v0, $v0, $a3
    ctx->r2 = SUB32(ctx->r2, ctx->r7);
    // 0x80063450: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x80063454: j           L_80063460
    // 0x80063458: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
        goto L_80063460;
    // 0x80063458: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
L_8006345C:
    // 0x8006345C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_80063460:
    // 0x80063460: andi        $v0, $s7, 0x2
    ctx->r2 = ctx->r23 & 0X2;
    // 0x80063464: beq         $v0, $zero, L_8006348C
    if (ctx->r2 == 0) {
        // 0x80063468: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8006348C;
    }
    // 0x80063468: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006346C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80063470: lui         $v0, 0xF00
    ctx->r2 = S32(0XF00 << 16);
    // 0x80063474: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80063478: lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X18);
    // 0x8006347C: lui         $v1, 0x1FFF
    ctx->r3 = S32(0X1FFF << 16);
    // 0x80063480: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x80063484: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80063488: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8006348C:
    // 0x8006348C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80063490: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80063494: lui         $a1, 0x1FFF
    ctx->r5 = S32(0X1FFF << 16);
    // 0x80063498: sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20 << 16);
    // 0x8006349C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800634A0: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800634A4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800634A8: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x800634AC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800634B0: sll         $v1, $s5, 16
    ctx->r3 = S32(ctx->r21 << 16);
    // 0x800634B4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800634B8: sll         $v0, $s6, 1
    ctx->r2 = S32(ctx->r22 << 1);
    // 0x800634BC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800634C0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800634C4: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x800634C8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800634CC: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x800634D0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800634D4: lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // 0x800634D8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800634DC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800634E0: lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X14);
    // 0x800634E4: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800634E8: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x800634EC: and         $v1, $v1, $a1
    ctx->r3 = ctx->r3 & ctx->r5;
    // 0x800634F0: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x800634F4: sw          $zero, 0x40($s2)
    MEM_W(0X40, ctx->r18) = 0;
    // 0x800634F8: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800634FC: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x80063500: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80063504: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80063508: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8006350C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80063510: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80063514: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80063518: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006351C: jr          $ra
    // 0x80063520: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80063520: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80063530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063530: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80063534: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80063538: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x8006353C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80063540: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80063544: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80063548: addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // 0x8006354C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80063550: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80063554: ori         $v1, $v1, 0x6C0
    ctx->r3 = ctx->r3 | 0X6C0;
    // 0x80063558: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    // 0x8006355C: ori         $a1, $a1, 0x800
    ctx->r5 = ctx->r5 | 0X800;
    // 0x80063560: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80063564: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80063568: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x8006356C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80063570: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80063574: lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C);
    // 0x80063578: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x8006357C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80063580: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80063584: sll         $v1, $s3, 1
    ctx->r3 = S32(ctx->r19 << 1);
    // 0x80063588: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x8006358C: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x80063590: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80063594: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x80063598: lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14);
    // 0x8006359C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800635A0: blez        $v0, L_800635E4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800635A4: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_800635E4;
    }
    // 0x800635A4: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800635A8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
L_800635AC:
    // 0x800635AC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800635B0: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x800635B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800635B8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800635BC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800635C0: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800635C4: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x800635C8: jalr        $v0
    // 0x800635CC: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800635CC: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    after_0:
    // 0x800635D0: lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X14);
    // 0x800635D4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800635D8: slt         $v1, $s1, $v1
    ctx->r3 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800635DC: bne         $v1, $zero, L_800635AC
    if (ctx->r3 != 0) {
        // 0x800635E0: addu        $a2, $v0, $zero
        ctx->r6 = ADD32(ctx->r2, 0);
            goto L_800635AC;
    }
    // 0x800635E0: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
L_800635E4:
    // 0x800635E4: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x800635E8: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x800635EC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800635F0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800635F4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800635F8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800635FC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80063600: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80063604: jr          $ra
    // 0x80063608: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80063608: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8006360C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006360C: lw          $a3, 0x1C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1C);
    // 0x80063610: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80063614: bne         $a1, $v0, L_80063634
    if (ctx->r5 != ctx->r2) {
        // 0x80063618: nop
    
            goto L_80063634;
    }
    // 0x80063618: nop

    // 0x8006361C: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80063620: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80063624: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80063628: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8006362C: sw          $v1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r3;
    // 0x80063630: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
L_80063634:
    // 0x80063634: jr          $ra
    // 0x80063638: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80063638: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80063640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063640: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80063644: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80063648: lw          $s3, 0x60($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X60);
    // 0x8006364C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80063650: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80063654: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80063658: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8006365C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80063660: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80063664: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80063668: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8006366C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80063670: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80063674: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x80063678: addu        $s7, $a2, $zero
    ctx->r23 = ADD32(ctx->r6, 0);
    // 0x8006367C: addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // 0x80063680: sw          $s6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r22;
    // 0x80063684: sh          $zero, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = 0;
    // 0x80063688: beq         $v0, $zero, L_80063B24
    if (ctx->r2 == 0) {
        // 0x8006368C: sh          $zero, 0x18($sp)
        MEM_H(0X18, ctx->r29) = 0;
            goto L_80063B24;
    }
    // 0x8006368C: sh          $zero, 0x18($sp)
    MEM_H(0X18, ctx->r29) = 0;
    // 0x80063690: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80063694: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x80063698: addiu       $s5, $s5, 0x6D20
    ctx->r21 = ADD32(ctx->r21, 0X6D20);
L_8006369C:
    // 0x8006369C: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x800636A0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800636A4: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800636A8: subu        $s2, $v0, $v1
    ctx->r18 = SUB32(ctx->r2, ctx->r3);
    // 0x800636AC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800636B0: slt         $v0, $s7, $s2
    ctx->r2 = SIGNED(ctx->r23) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800636B4: bne         $v0, $zero, L_80063B28
    if (ctx->r2 != 0) {
        // 0x800636B8: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80063B28;
    }
    // 0x800636B8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800636BC: bgez        $s2, L_800636E0
    if (SIGNED(ctx->r18) >= 0) {
        // 0x800636C0: slti        $v0, $s2, 0xA1
        ctx->r2 = SIGNED(ctx->r18) < 0XA1 ? 1 : 0;
            goto L_800636E0;
    }
    // 0x800636C0: slti        $v0, $s2, 0xA1
    ctx->r2 = SIGNED(ctx->r18) < 0XA1 ? 1 : 0;
    // 0x800636C4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800636C8: addiu       $a0, $a0, -0xED0
    ctx->r4 = ADD32(ctx->r4, -0XED0);
    // 0x800636CC: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800636D0: addiu       $a1, $a1, -0xECC
    ctx->r5 = ADD32(ctx->r5, -0XECC);
    // 0x800636D4: jal         0x800621E0
    // 0x800636D8: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    func_800621E0(rdram, ctx);
        goto after_0;
    // 0x800636D8: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    after_0:
    // 0x800636DC: slti        $v0, $s2, 0xA1
    ctx->r2 = SIGNED(ctx->r18) < 0XA1 ? 1 : 0;
L_800636E0:
    // 0x800636E0: bne         $v0, $zero, L_80063700
    if (ctx->r2 != 0) {
        // 0x800636E4: nop
    
            goto L_80063700;
    }
    // 0x800636E4: nop

    // 0x800636E8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800636EC: addiu       $a0, $a0, -0xED0
    ctx->r4 = ADD32(ctx->r4, -0XED0);
    // 0x800636F0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800636F4: addiu       $a1, $a1, -0xECC
    ctx->r5 = ADD32(ctx->r5, -0XECC);
    // 0x800636F8: jal         0x800621E0
    // 0x800636FC: addiu       $a2, $zero, 0x69
    ctx->r6 = ADD32(0, 0X69);
    func_800621E0(rdram, ctx);
        goto after_1;
    // 0x800636FC: addiu       $a2, $zero, 0x69
    ctx->r6 = ADD32(0, 0X69);
    after_1:
L_80063700:
    // 0x80063700: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x80063704: lh          $v1, 0x8($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X8);
    // 0x80063708: sltiu       $v0, $v1, 0x11
    ctx->r2 = ctx->r3 < 0X11 ? 1 : 0;
    // 0x8006370C: beq         $v0, $zero, L_80063AB0
    if (ctx->r2 == 0) {
        // 0x80063710: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80063AB0;
    }
    // 0x80063710: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80063714: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80063718: addu        $at, $at, $v0
    gpr jr_addend_80063720 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8006371C: lw          $v0, -0xEC0($at)
    ctx->r2 = ADD32(ctx->r1, -0XEC0);
    // 0x80063720: jr          $v0
    // 0x80063724: nop

    switch (jr_addend_80063720 >> 2) {
        case 0: goto L_80063A8C; break;
        case 1: goto L_80063AB0; break;
        case 2: goto L_80063AB0; break;
        case 3: goto L_80063AB0; break;
        case 4: goto L_80063AB0; break;
        case 5: goto L_80063AB0; break;
        case 6: goto L_80063AB0; break;
        case 7: goto L_80063AB0; break;
        case 8: goto L_80063AB0; break;
        case 9: goto L_80063AB0; break;
        case 10: goto L_80063AB0; break;
        case 11: goto L_80063858; break;
        case 12: goto L_80063858; break;
        case 13: goto L_80063728; break;
        case 14: goto L_80063A0C; break;
        case 15: goto L_80063A50; break;
        case 16: goto L_80063858; break;
        default: switch_error(__func__, 0x80063720, 0x800AF140);
    }
    // 0x80063724: nop

L_80063728:
    // 0x80063728: lw          $s1, 0x3C($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X3C);
    // 0x8006372C: lh          $v0, 0xA($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XA);
    // 0x80063730: beq         $v0, $zero, L_8006374C
    if (ctx->r2 == 0) {
        // 0x80063734: addu        $s4, $s0, $zero
        ctx->r20 = ADD32(ctx->r16, 0);
            goto L_8006374C;
    }
    // 0x80063734: addu        $s4, $s0, $zero
    ctx->r20 = ADD32(ctx->r16, 0);
    // 0x80063738: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006373C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80063740: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80063744: jalr        $v0
    // 0x80063748: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x80063748: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_2:
L_8006374C:
    // 0x8006374C: lw          $a2, 0x18($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X18);
    // 0x80063750: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80063754: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80063758: jalr        $v0
    // 0x8006375C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x8006375C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_3:
    // 0x80063760: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80063764: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80063768: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8006376C: jalr        $v0
    // 0x80063770: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x80063770: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_4:
    // 0x80063774: sw          $fp, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r30;
    // 0x80063778: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x8006377C: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x80063780: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x80063784: lh          $v0, 0x10($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X10);
    // 0x80063788: mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006378C: mflo        $v0
    ctx->r2 = lo;
    // 0x80063790: sra         $v0, $v0, 15
    ctx->r2 = S32(SIGNED(ctx->r2) >> 15);
    // 0x80063794: sh          $v0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r2;
    // 0x80063798: lbu         $v0, 0x12($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X12);
    // 0x8006379C: sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    // 0x800637A0: lbu         $v0, 0x13($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X13);
    // 0x800637A4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800637A8: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x800637AC: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800637B0: sh          $v0, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r2;
    // 0x800637B4: lbu         $v0, 0x13($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X13);
    // 0x800637B8: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // 0x800637BC: subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // 0x800637C0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800637C4: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x800637C8: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800637CC: sh          $v0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r2;
    // 0x800637D0: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x800637D4: beq         $v0, $zero, L_800637E8
    if (ctx->r2 == 0) {
        // 0x800637D8: nop
    
            goto L_800637E8;
    }
    // 0x800637D8: nop

    // 0x800637DC: sh          $fp, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r30;
    // 0x800637E0: j           L_80063834
    // 0x800637E4: sh          $fp, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r30;
        goto L_80063834;
    // 0x800637E4: sh          $fp, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r30;
L_800637E8:
    // 0x800637E8: lh          $v0, 0x18($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18);
    // 0x800637EC: lh          $v1, 0x1A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A);
    // 0x800637F0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800637F4: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x800637F8: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x800637FC: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063800: mflo        $v1
    ctx->r3 = lo;
    // 0x80063804: lh          $v0, 0x18($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18);
    // 0x80063808: subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // 0x8006380C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80063810: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x80063814: sra         $v1, $v1, 15
    ctx->r3 = S32(SIGNED(ctx->r3) >> 15);
    // 0x80063818: sh          $v1, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r3;
    // 0x8006381C: lh          $v1, 0x1A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A);
    // 0x80063820: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x80063824: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063828: mflo        $v1
    ctx->r3 = lo;
    // 0x8006382C: sra         $v1, $v1, 15
    ctx->r3 = S32(SIGNED(ctx->r3) >> 15);
    // 0x80063830: sh          $v1, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r3;
L_80063834:
    // 0x80063834: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80063838: beq         $a0, $zero, L_80063AE8
    if (ctx->r4 == 0) {
        // 0x8006383C: nop
    
            goto L_80063AE8;
    }
    // 0x8006383C: nop

    // 0x80063840: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80063844: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80063848: jalr        $v0
    // 0x8006384C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_5;
    // 0x8006384C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_5:
    // 0x80063850: j           L_80063AE8
    // 0x80063854: nop

        goto L_80063AE8;
    // 0x80063854: nop

L_80063858:
    // 0x80063858: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006385C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80063860: addiu       $a2, $sp, 0x1A
    ctx->r6 = ADD32(ctx->r29, 0X1A);
    // 0x80063864: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x80063868: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x8006386C: jal         0x80063C60
    // 0x80063870: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80063C60(rdram, ctx);
        goto after_6;
    // 0x80063870: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_6:
    // 0x80063874: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x80063878: lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X34);
    // 0x8006387C: slt         $v1, $a1, $v1
    ctx->r3 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80063880: bne         $v1, $zero, L_800638F4
    if (ctx->r3 != 0) {
        // 0x80063884: addu        $s3, $v0, $zero
        ctx->r19 = ADD32(ctx->r2, 0);
            goto L_800638F4;
    }
    // 0x80063884: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80063888: lh          $v0, 0x18($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18);
    // 0x8006388C: lh          $v1, 0x1A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A);
    // 0x80063890: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80063894: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x80063898: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x8006389C: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800638A0: mflo        $v1
    ctx->r3 = lo;
    // 0x800638A4: lh          $v0, 0x18($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18);
    // 0x800638A8: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // 0x800638AC: subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // 0x800638B0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800638B4: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x800638B8: sra         $v1, $v1, 15
    ctx->r3 = S32(SIGNED(ctx->r3) >> 15);
    // 0x800638BC: sh          $v1, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r3;
    // 0x800638C0: lh          $v1, 0x1A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1A);
    // 0x800638C4: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x800638C8: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800638CC: mflo        $v1
    ctx->r3 = lo;
    // 0x800638D0: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x800638D4: sra         $v1, $v1, 15
    ctx->r3 = S32(SIGNED(ctx->r3) >> 15);
    // 0x800638D8: sh          $v1, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r3;
    // 0x800638DC: lhu         $v1, 0x28($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X28);
    // 0x800638E0: lhu         $a0, 0x2E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2E);
    // 0x800638E4: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x800638E8: sh          $v1, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r3;
    // 0x800638EC: j           L_8006394C
    // 0x800638F0: sh          $a0, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r4;
        goto L_8006394C;
    // 0x800638F0: sh          $a0, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r4;
L_800638F4:
    // 0x800638F4: lh          $a2, 0x26($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X26);
    // 0x800638F8: lh          $v0, 0x1C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1C);
    // 0x800638FC: lhu         $a3, 0x24($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X24);
    // 0x80063900: mtc1        $v0, $f12
    ctx->f12.u32l = ctx->r2;
    // 0x80063904: nop

    // 0x80063908: jal         0x800642E4
    // 0x8006390C: cvt.s.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.fl = CVT_S_W(ctx->f12.u32l);
    func_800642E4(rdram, ctx);
        goto after_7;
    // 0x8006390C: cvt.s.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.fl = CVT_S_W(ctx->f12.u32l);
    after_7:
    // 0x80063910: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x80063914: lh          $a2, 0x2C($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X2C);
    // 0x80063918: lhu         $a3, 0x2A($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X2A);
    // 0x8006391C: lh          $v1, 0x1E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X1E);
    // 0x80063920: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80063924: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80063928: mtc1        $v1, $f12
    ctx->f12.u32l = ctx->r3;
    // 0x8006392C: nop

    // 0x80063930: cvt.s.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.fl = CVT_S_W(ctx->f12.u32l);
    // 0x80063934: jal         0x800642E4
    // 0x80063938: sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    func_800642E4(rdram, ctx);
        goto after_8;
    // 0x80063938: sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    after_8:
    // 0x8006393C: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80063940: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80063944: nop

    // 0x80063948: sh          $v0, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r2;
L_8006394C:
    // 0x8006394C: lh          $v0, 0x1C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1C);
    // 0x80063950: beql        $v0, $zero, L_80063958
    if (ctx->r2 == 0) {
        // 0x80063954: sh          $fp, 0x1C($s0)
        MEM_H(0X1C, ctx->r16) = ctx->r30;
            goto L_80063958;
    }
    goto skip_0;
    // 0x80063954: sh          $fp, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r30;
    skip_0:
L_80063958:
    // 0x80063958: lh          $v0, 0x1E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1E);
    // 0x8006395C: beql        $v0, $zero, L_80063964
    if (ctx->r2 == 0) {
        // 0x80063960: sh          $fp, 0x1E($s0)
        MEM_H(0X1E, ctx->r16) = ctx->r30;
            goto L_80063964;
    }
    goto skip_1;
    // 0x80063960: sh          $fp, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r30;
    skip_1:
L_80063964:
    // 0x80063964: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80063968: lh          $v1, 0x8($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X8);
    // 0x8006396C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x80063970: bne         $v1, $v0, L_80063980
    if (ctx->r3 != ctx->r2) {
        // 0x80063974: nop
    
            goto L_80063980;
    }
    // 0x80063974: nop

    // 0x80063978: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8006397C: sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
L_80063980:
    // 0x80063980: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x80063984: lh          $v1, 0x8($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X8);
    // 0x80063988: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8006398C: bne         $v1, $v0, L_800639BC
    if (ctx->r3 != ctx->r2) {
        // 0x80063990: nop
    
            goto L_800639BC;
    }
    // 0x80063990: nop

    // 0x80063994: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x80063998: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x8006399C: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x800639A0: mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800639A4: mflo        $v0
    ctx->r2 = lo;
    // 0x800639A8: lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X3C);
    // 0x800639AC: sra         $v0, $v0, 15
    ctx->r2 = S32(SIGNED(ctx->r2) >> 15);
    // 0x800639B0: sh          $v0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r2;
    // 0x800639B4: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x800639B8: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
L_800639BC:
    // 0x800639BC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x800639C0: lh          $v1, 0x8($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X8);
    // 0x800639C4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x800639C8: bnel        $v1, $v0, L_80063AE8
    if (ctx->r3 != ctx->r2) {
        // 0x800639CC: sw          $fp, 0x38($s0)
        MEM_W(0X38, ctx->r16) = ctx->r30;
            goto L_80063AE8;
    }
    goto skip_2;
    // 0x800639CC: sw          $fp, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r30;
    skip_2:
    // 0x800639D0: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800639D4: lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X3C);
    // 0x800639D8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800639DC: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x800639E0: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800639E4: sh          $v0, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r2;
    // 0x800639E8: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800639EC: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // 0x800639F0: subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // 0x800639F4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800639F8: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x800639FC: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80063A00: sh          $v0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r2;
    // 0x80063A04: j           L_80063AE8
    // 0x80063A08: sw          $fp, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r30;
        goto L_80063AE8;
    // 0x80063A08: sw          $fp, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r30;
L_80063A0C:
    // 0x80063A0C: lw          $s1, 0x3C($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X3C);
    // 0x80063A10: lh          $v0, 0xA($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XA);
    // 0x80063A14: beq         $v0, $zero, L_80063A2C
    if (ctx->r2 == 0) {
        // 0x80063A18: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80063A2C;
    }
    // 0x80063A18: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80063A1C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80063A20: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80063A24: jalr        $v0
    // 0x80063A28: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_9;
    // 0x80063A28: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_9:
L_80063A2C:
    // 0x80063A2C: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80063A30: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80063A34: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80063A38: jalr        $v0
    // 0x80063A3C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_10;
    // 0x80063A3C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_10:
    // 0x80063A40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80063A44: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80063A48: j           L_80063A7C
    // 0x80063A4C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
        goto L_80063A7C;
    // 0x80063A4C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
L_80063A50:
    // 0x80063A50: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80063A54: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80063A58: addiu       $a2, $sp, 0x1A
    ctx->r6 = ADD32(ctx->r29, 0X1A);
    // 0x80063A5C: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x80063A60: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x80063A64: jal         0x80063C60
    // 0x80063A68: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80063C60(rdram, ctx);
        goto after_11;
    // 0x80063A68: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_11:
    // 0x80063A6C: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80063A70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80063A74: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80063A78: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_80063A7C:
    // 0x80063A7C: jalr        $v0
    // 0x80063A80: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_12;
    // 0x80063A80: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_12:
    // 0x80063A84: j           L_80063AE8
    // 0x80063A88: nop

        goto L_80063AE8;
    // 0x80063A88: nop

L_80063A8C:
    // 0x80063A8C: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x80063A90: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80063A94: lw          $a0, 0x6E40($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6E40);
    // 0x80063A98: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80063A9C: sw          $zero, 0xD8($v1)
    MEM_W(0XD8, ctx->r3) = 0;
    // 0x80063AA0: jal         0x80065B54
    // 0x80063AA4: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    func_80065B54(rdram, ctx);
        goto after_13;
    // 0x80063AA4: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    after_13:
    // 0x80063AA8: j           L_80063AE8
    // 0x80063AAC: nop

        goto L_80063AE8;
    // 0x80063AAC: nop

L_80063AB0:
    // 0x80063AB0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80063AB4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80063AB8: addiu       $a2, $sp, 0x1A
    ctx->r6 = ADD32(ctx->r29, 0X1A);
    // 0x80063ABC: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x80063AC0: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x80063AC4: jal         0x80063C60
    // 0x80063AC8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80063C60(rdram, ctx);
        goto after_14;
    // 0x80063AC8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_14:
    // 0x80063ACC: lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X3C);
    // 0x80063AD0: lh          $a1, 0x8($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X8);
    // 0x80063AD4: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    // 0x80063AD8: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80063ADC: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80063AE0: jalr        $v1
    // 0x80063AE4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_15;
    // 0x80063AE4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_15:
L_80063AE8:
    // 0x80063AE8: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x80063AEC: subu        $s7, $s7, $s2
    ctx->r23 = SUB32(ctx->r23, ctx->r18);
    // 0x80063AF0: lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1A);
    // 0x80063AF4: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80063AF8: sll         $v1, $s2, 1
    ctx->r3 = S32(ctx->r18 << 1);
    // 0x80063AFC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80063B00: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x80063B04: bne         $a0, $zero, L_80063B10
    if (ctx->r4 != 0) {
        // 0x80063B08: sw          $a0, 0x3C($s0)
        MEM_W(0X3C, ctx->r16) = ctx->r4;
            goto L_80063B10;
    }
    // 0x80063B08: sw          $a0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r4;
    // 0x80063B0C: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
L_80063B10:
    // 0x80063B10: jal         0x80065AE8
    // 0x80063B14: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    func_80065AE8(rdram, ctx);
        goto after_16;
    // 0x80063B14: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    after_16:
    // 0x80063B18: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x80063B1C: bne         $v0, $zero, L_8006369C
    if (ctx->r2 != 0) {
        // 0x80063B20: nop
    
            goto L_8006369C;
    }
    // 0x80063B20: nop

L_80063B24:
    // 0x80063B24: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80063B28:
    // 0x80063B28: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80063B2C: addiu       $a2, $sp, 0x1A
    ctx->r6 = ADD32(ctx->r29, 0X1A);
    // 0x80063B30: addu        $a3, $s7, $zero
    ctx->r7 = ADD32(ctx->r23, 0);
    // 0x80063B34: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x80063B38: jal         0x80063C60
    // 0x80063B3C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80063C60(rdram, ctx);
        goto after_17;
    // 0x80063B3C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_17:
    // 0x80063B40: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x80063B44: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80063B48: slt         $v1, $a0, $v1
    ctx->r3 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80063B4C: beq         $v1, $zero, L_80063B58
    if (ctx->r3 == 0) {
        // 0x80063B50: addu        $s3, $v0, $zero
        ctx->r19 = ADD32(ctx->r2, 0);
            goto L_80063B58;
    }
    // 0x80063B50: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80063B54: sw          $a0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r4;
L_80063B58:
    // 0x80063B58: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x80063B5C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80063B60: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80063B64: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80063B68: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80063B6C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80063B70: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80063B74: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80063B78: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80063B7C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80063B80: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80063B84: jr          $ra
    // 0x80063B88: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80063B88: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80063B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063B8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063B90: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80063B94: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80063B98: beq         $a1, $v0, L_80063BD8
    if (ctx->r5 == ctx->r2) {
        // 0x80063B9C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80063BD8;
    }
    // 0x80063B9C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80063BA0: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80063BA4: beq         $v0, $zero, L_80063BBC
    if (ctx->r2 == 0) {
        // 0x80063BA8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80063BBC;
    }
    // 0x80063BA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80063BAC: beql        $a1, $v0, L_80063C50
    if (ctx->r5 == ctx->r2) {
        // 0x80063BB0: sw          $a2, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r6;
            goto L_80063C50;
    }
    goto skip_0;
    // 0x80063BB0: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    skip_0:
    // 0x80063BB4: j           L_80063C38
    // 0x80063BB8: nop

        goto L_80063C38;
    // 0x80063BB8: nop

L_80063BBC:
    // 0x80063BBC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80063BC0: beq         $a1, $v0, L_80063BF0
    if (ctx->r5 == ctx->r2) {
        // 0x80063BC4: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_80063BF0;
    }
    // 0x80063BC4: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80063BC8: beq         $a1, $v0, L_80063C1C
    if (ctx->r5 == ctx->r2) {
        // 0x80063BCC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80063C1C;
    }
    // 0x80063BCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80063BD0: j           L_80063C38
    // 0x80063BD4: nop

        goto L_80063C38;
    // 0x80063BD4: nop

L_80063BD8:
    // 0x80063BD8: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80063BDC: beql        $v0, $zero, L_80063BE8
    if (ctx->r2 == 0) {
        // 0x80063BE0: sw          $a2, 0x3C($a0)
        MEM_W(0X3C, ctx->r4) = ctx->r6;
            goto L_80063BE8;
    }
    goto skip_1;
    // 0x80063BE0: sw          $a2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r6;
    skip_1:
    // 0x80063BE4: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
L_80063BE8:
    // 0x80063BE8: j           L_80063C50
    // 0x80063BEC: sw          $a2, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r6;
        goto L_80063C50;
    // 0x80063BEC: sw          $a2, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r6;
L_80063BF0:
    // 0x80063BF0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80063BF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80063BF8: sw          $v0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r2;
    // 0x80063BFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80063C00: sw          $zero, 0x48($a0)
    MEM_W(0X48, ctx->r4) = 0;
    // 0x80063C04: beq         $v1, $zero, L_80063C50
    if (ctx->r3 == 0) {
        // 0x80063C08: sh          $v0, 0x1A($a0)
        MEM_H(0X1A, ctx->r4) = ctx->r2;
            goto L_80063C50;
    }
    // 0x80063C08: sh          $v0, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r2;
    // 0x80063C0C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80063C10: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80063C14: j           L_80063C48
    // 0x80063C18: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
        goto L_80063C48;
    // 0x80063C18: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_80063C1C:
    // 0x80063C1C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80063C20: beq         $v1, $zero, L_80063C50
    if (ctx->r3 == 0) {
        // 0x80063C24: sw          $v0, 0x48($a0)
        MEM_W(0X48, ctx->r4) = ctx->r2;
            goto L_80063C50;
    }
    // 0x80063C24: sw          $v0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r2;
    // 0x80063C28: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80063C2C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80063C30: j           L_80063C48
    // 0x80063C34: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
        goto L_80063C48;
    // 0x80063C34: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
L_80063C38:
    // 0x80063C38: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80063C3C: beq         $a0, $zero, L_80063C50
    if (ctx->r4 == 0) {
        // 0x80063C40: nop
    
            goto L_80063C50;
    }
    // 0x80063C40: nop

    // 0x80063C44: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
L_80063C48:
    // 0x80063C48: jalr        $v0
    // 0x80063C4C: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80063C4C: nop

    after_0:
L_80063C50:
    // 0x80063C50: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80063C54: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80063C58: jr          $ra
    // 0x80063C5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80063C5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80063C60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063C60: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80063C64: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80063C68: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x80063C6C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80063C70: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x80063C74: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80063C78: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80063C7C: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x80063C80: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80063C84: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80063C88: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x80063C8C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80063C90: lw          $v0, 0x48($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X48);
    // 0x80063C94: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80063C98: sltiu       $v1, $s4, 0x1
    ctx->r3 = ctx->r20 < 0X1 ? 1 : 0;
    // 0x80063C9C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80063CA0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80063CA4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80063CA8: beq         $v0, $zero, L_80063CB8
    if (ctx->r2 == 0) {
        // 0x80063CAC: addu        $s3, $a2, $zero
        ctx->r19 = ADD32(ctx->r6, 0);
            goto L_80063CB8;
    }
    // 0x80063CAC: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80063CB0: j           L_80063F3C
    // 0x80063CB4: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
        goto L_80063F3C;
    // 0x80063CB4: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_80063CB8:
    // 0x80063CB8: bne         $s0, $zero, L_80063CDC
    if (ctx->r16 != 0) {
        // 0x80063CBC: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80063CDC;
    }
    // 0x80063CBC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80063CC0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80063CC4: addiu       $a0, $a0, -0xED0
    ctx->r4 = ADD32(ctx->r4, -0XED0);
    // 0x80063CC8: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80063CCC: addiu       $a1, $a1, -0xECC
    ctx->r5 = ADD32(ctx->r5, -0XECC);
    // 0x80063CD0: jal         0x800621E0
    // 0x80063CD4: addiu       $a2, $zero, 0x16F
    ctx->r6 = ADD32(0, 0X16F);
    func_800621E0(rdram, ctx);
        goto after_0;
    // 0x80063CD4: addiu       $a2, $zero, 0x16F
    ctx->r6 = ADD32(0, 0X16F);
    after_0:
    // 0x80063CD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80063CDC:
    // 0x80063CDC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80063CE0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80063CE4: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80063CE8: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x80063CEC: jalr        $v0
    // 0x80063CF0: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x80063CF0: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_1:
    // 0x80063CF4: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80063CF8: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80063CFC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80063D00: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x80063D04: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80063D08: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80063D0C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80063D10: lh          $v0, 0x0($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X0);
    // 0x80063D14: sll         $v1, $s4, 1
    ctx->r3 = S32(ctx->r20 << 1);
    // 0x80063D18: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80063D1C: addiu       $v0, $v0, 0x440
    ctx->r2 = ADD32(ctx->r2, 0X440);
    // 0x80063D20: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80063D24: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80063D28: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x80063D2C: lh          $v0, 0x0($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X0);
    // 0x80063D30: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80063D34: lui         $v1, 0x808
    ctx->r3 = S32(0X808 << 16);
    // 0x80063D38: addiu       $v0, $v0, 0x580
    ctx->r2 = ADD32(ctx->r2, 0X580);
    // 0x80063D3C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80063D40: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80063D44: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80063D48: lh          $v0, 0x0($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X0);
    // 0x80063D4C: addiu       $v1, $v0, 0x6C0
    ctx->r3 = ADD32(ctx->r2, 0X6C0);
    // 0x80063D50: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80063D54: addiu       $v0, $v0, 0x800
    ctx->r2 = ADD32(ctx->r2, 0X800);
    // 0x80063D58: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80063D5C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80063D60: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80063D64: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x80063D68: beq         $v0, $zero, L_80063F00
    if (ctx->r2 == 0) {
        // 0x80063D6C: addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
            goto L_80063F00;
    }
    // 0x80063D6C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80063D70: lh          $v0, 0x18($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X18);
    // 0x80063D74: lh          $v1, 0x1A($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X1A);
    // 0x80063D78: sw          $zero, 0x38($s1)
    MEM_W(0X38, ctx->r17) = 0;
    // 0x80063D7C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80063D80: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80063D84: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80063D88: lh          $v0, 0x6D20($at)
    ctx->r2 = MEM_H(ctx->r1, 0X6D20);
    // 0x80063D8C: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063D90: mflo        $v1
    ctx->r3 = lo;
    // 0x80063D94: lh          $v0, 0x1C($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X1C);
    // 0x80063D98: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x80063D9C: mtc1        $v0, $f12
    ctx->f12.u32l = ctx->r2;
    // 0x80063DA0: nop

    // 0x80063DA4: cvt.d.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.d = CVT_D_W(ctx->f12.u32l);
    // 0x80063DA8: sra         $v1, $v1, 15
    ctx->r3 = S32(SIGNED(ctx->r3) >> 15);
    // 0x80063DAC: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80063DB0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80063DB4: mtc1        $v0, $f14
    ctx->f14.u32l = ctx->r2;
    // 0x80063DB8: nop

    // 0x80063DBC: cvt.d.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.d = CVT_D_W(ctx->f14.u32l);
    // 0x80063DC0: addiu       $v0, $s1, 0x24
    ctx->r2 = ADD32(ctx->r17, 0X24);
    // 0x80063DC4: sh          $v1, 0x28($s1)
    MEM_H(0X28, ctx->r17) = ctx->r3;
    // 0x80063DC8: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80063DCC: jal         0x80064064
    // 0x80063DD0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_80064064(rdram, ctx);
        goto after_2;
    // 0x80063DD0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_2:
    // 0x80063DD4: lh          $a0, 0x18($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X18);
    // 0x80063DD8: lh          $v1, 0x1A($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X1A);
    // 0x80063DDC: sh          $v0, 0x26($s1)
    MEM_H(0X26, ctx->r17) = ctx->r2;
    // 0x80063DE0: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x80063DE4: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80063DE8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80063DEC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80063DF0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80063DF4: lh          $v0, 0x6D20($at)
    ctx->r2 = MEM_H(ctx->r1, 0X6D20);
    // 0x80063DF8: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80063DFC: mflo        $v1
    ctx->r3 = lo;
    // 0x80063E00: lh          $v0, 0x1E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X1E);
    // 0x80063E04: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x80063E08: mtc1        $v0, $f12
    ctx->f12.u32l = ctx->r2;
    // 0x80063E0C: nop

    // 0x80063E10: cvt.d.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.d = CVT_D_W(ctx->f12.u32l);
    // 0x80063E14: sra         $v1, $v1, 15
    ctx->r3 = S32(SIGNED(ctx->r3) >> 15);
    // 0x80063E18: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80063E1C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80063E20: mtc1        $v0, $f14
    ctx->f14.u32l = ctx->r2;
    // 0x80063E24: nop

    // 0x80063E28: cvt.d.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.d = CVT_D_W(ctx->f14.u32l);
    // 0x80063E2C: addiu       $v0, $s1, 0x2A
    ctx->r2 = ADD32(ctx->r17, 0X2A);
    // 0x80063E30: sh          $v1, 0x2E($s1)
    MEM_H(0X2E, ctx->r17) = ctx->r3;
    // 0x80063E34: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80063E38: jal         0x80064064
    // 0x80063E3C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_80064064(rdram, ctx);
        goto after_3;
    // 0x80063E3C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_3:
    // 0x80063E40: lhu         $v1, 0x1C($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X1C);
    // 0x80063E44: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80063E48: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80063E4C: sh          $v0, 0x2C($s1)
    MEM_H(0X2C, ctx->r17) = ctx->r2;
    // 0x80063E50: lui         $v0, 0x906
    ctx->r2 = S32(0X906 << 16);
    // 0x80063E54: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80063E58: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80063E5C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80063E60: lhu         $v1, 0x1E($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X1E);
    // 0x80063E64: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80063E68: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80063E6C: lui         $v0, 0x904
    ctx->r2 = S32(0X904 << 16);
    // 0x80063E70: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80063E74: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80063E78: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80063E7C: lhu         $v0, 0x28($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X28);
    // 0x80063E80: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80063E84: lui         $v1, 0x902
    ctx->r3 = S32(0X902 << 16);
    // 0x80063E88: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80063E8C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80063E90: lhu         $v0, 0x26($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X26);
    // 0x80063E94: lhu         $v1, 0x24($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X24);
    // 0x80063E98: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80063E9C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80063EA0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80063EA4: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x80063EA8: lhu         $v0, 0x2E($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2E);
    // 0x80063EAC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80063EB0: lui         $v1, 0x900
    ctx->r3 = S32(0X900 << 16);
    // 0x80063EB4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80063EB8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80063EBC: lhu         $v0, 0x2C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2C);
    // 0x80063EC0: lhu         $v1, 0x2A($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2A);
    // 0x80063EC4: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80063EC8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80063ECC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80063ED0: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x80063ED4: lhu         $v0, 0x20($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X20);
    // 0x80063ED8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80063EDC: lui         $v1, 0x908
    ctx->r3 = S32(0X908 << 16);
    // 0x80063EE0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80063EE4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80063EE8: lhu         $v0, 0x22($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X22);
    // 0x80063EEC: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80063EF0: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
    // 0x80063EF4: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x80063EF8: j           L_80063F08
    // 0x80063EFC: lui         $v0, 0x309
    ctx->r2 = S32(0X309 << 16);
        goto L_80063F08;
    // 0x80063EFC: lui         $v0, 0x309
    ctx->r2 = S32(0X309 << 16);
L_80063F00:
    // 0x80063F00: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
    // 0x80063F04: lui         $v0, 0x308
    ctx->r2 = S32(0X308 << 16);
L_80063F08:
    // 0x80063F08: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80063F0C: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80063F10: jal         0x80062180
    // 0x80063F14: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x80063F14: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    after_4:
    // 0x80063F18: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80063F1C: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80063F20: sll         $v1, $s4, 1
    ctx->r3 = S32(ctx->r20 << 1);
    // 0x80063F24: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80063F28: sh          $v0, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r2;
    // 0x80063F2C: lw          $v1, 0x30($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X30);
    // 0x80063F30: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x80063F34: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x80063F38: sw          $v1, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r3;
L_80063F3C:
    // 0x80063F3C: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x80063F40: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80063F44: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80063F48: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80063F4C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80063F50: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80063F54: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80063F58: jr          $ra
    // 0x80063F5C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80063F5C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80063F60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063F60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80063F64: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x80063F68: nop

    // 0x80063F6C: c.eq.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d == ctx->f0.d;
    // 0x80063F70: nop

    // 0x80063F74: nop

    // 0x80063F78: bc1f        L_80063F88
    if (!c1cs) {
        // 0x80063F7C: sw          $zero, 0x0($a2)
        MEM_W(0X0, ctx->r6) = 0;
            goto L_80063F88;
    }
    // 0x80063F7C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80063F80: j           L_80064038
    // 0x80063F84: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_80064038;
    // 0x80063F84: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
L_80063F88:
    // 0x80063F88: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x80063F8C: nop

    // 0x80063F90: nop

    // 0x80063F94: bc1t        L_80063FA0
    if (c1cs) {
        // 0x80063F98: mov.d       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.d = ctx->f12.d;
            goto L_80063FA0;
    }
    // 0x80063F98: mov.d       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.d = ctx->f12.d;
    // 0x80063F9C: neg.d       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = -ctx->f12.d;
L_80063FA0:
    // 0x80063FA0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80063FA4: ldc1        $f0, -0xE78($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0XE78);
    // 0x80063FA8: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x80063FAC: nop

    // 0x80063FB0: bc1f        L_80063FE0
    if (!c1cs) {
        // 0x80063FB4: nop
    
            goto L_80063FE0;
    }
    // 0x80063FB4: nop

    // 0x80063FB8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80063FBC: ldc1        $f4, -0xE70($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0XE70);
L_80063FC0:
    // 0x80063FC0: nop

    // 0x80063FC4: mul.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x80063FC8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80063FCC: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x80063FD0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80063FD4: nop

    // 0x80063FD8: bc1t        L_80063FC0
    if (c1cs) {
        // 0x80063FDC: sw          $v0, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r2;
            goto L_80063FC0;
    }
    // 0x80063FDC: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80063FE0:
    // 0x80063FE0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80063FE4: ldc1        $f0, -0xE68($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0XE68);
    // 0x80063FE8: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x80063FEC: nop

    // 0x80063FF0: bc1f        L_80064014
    if (!c1cs) {
        // 0x80063FF4: nop
    
            goto L_80064014;
    }
    // 0x80063FF4: nop

L_80063FF8:
    // 0x80063FF8: add.d       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = ctx->f2.d + ctx->f2.d;
    // 0x80063FFC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80064000: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x80064004: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80064008: nop

    // 0x8006400C: bc1t        L_80063FF8
    if (c1cs) {
        // 0x80064010: sw          $v0, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r2;
            goto L_80063FF8;
    }
    // 0x80064010: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80064014:
    // 0x80064014: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80064018: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x8006401C: nop

    // 0x80064020: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x80064024: nop

    // 0x80064028: nop

    // 0x8006402C: bc1t        L_80064038
    if (c1cs) {
        // 0x80064030: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_80064038;
    }
    // 0x80064030: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    // 0x80064034: neg.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = -ctx->f0.d;
L_80064038:
    // 0x80064038: jr          $ra
    // 0x8006403C: nop

    return;
    // 0x8006403C: nop

;}
RECOMP_FUNC void func_80064040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064040: beq         $a2, $zero, L_8006405C
    if (ctx->r6 == 0) {
        // 0x80064044: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006405C;
    }
    // 0x80064044: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80064048: sllv        $v0, $v0, $a2
    ctx->r2 = S32(ctx->r2 << (ctx->r6 & 31));
    // 0x8006404C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80064050: nop

    // 0x80064054: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x80064058: mul.d       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f0.d);
L_8006405C:
    // 0x8006405C: jr          $ra
    // 0x80064060: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    return;
    // 0x80064060: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
;}
RECOMP_FUNC void func_80064064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064064: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80064068: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x8006406C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80064070: ldc1        $f2, -0xE20($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0XE20);
    // 0x80064074: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80064078: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8006407C: nop

    // 0x80064080: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x80064084: bne         $v0, $zero, L_800640B8
    if (ctx->r2 != 0) {
        // 0x80064088: div.d       $f4, $f2, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f2.d, ctx->f0.d);
            goto L_800640B8;
    }
    // 0x80064088: div.d       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f2.d, ctx->f0.d);
    // 0x8006408C: c.le.d      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.d <= ctx->f14.d;
    // 0x80064090: nop

    // 0x80064094: nop

    // 0x80064098: bc1f        L_800640AC
    if (!c1cs) {
        // 0x8006409C: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_800640AC;
    }
    // 0x8006409C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800640A0: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    // 0x800640A4: j           L_800642DC
    // 0x800640A8: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
        goto L_800642DC;
    // 0x800640A8: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
L_800640AC:
    // 0x800640AC: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
    // 0x800640B0: j           L_800642DC
    // 0x800640B4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800642DC;
    // 0x800640B4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800640B8:
    // 0x800640B8: c.lt.d      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.d < ctx->f2.d;
    // 0x800640BC: nop

    // 0x800640C0: nop

    // 0x800640C4: bc1tl       L_800640CC
    if (c1cs) {
        // 0x800640C8: mov.d       $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.d = ctx->f2.d;
            goto L_800640CC;
    }
    goto skip_0;
    // 0x800640C8: mov.d       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.d = ctx->f2.d;
    skip_0:
L_800640CC:
    // 0x800640CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800640D0: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x800640D4: nop

    // 0x800640D8: c.le.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d <= ctx->f0.d;
    // 0x800640DC: nop

    // 0x800640E0: nop

    // 0x800640E4: bc1tl       L_800640EC
    if (c1cs) {
        // 0x800640E8: mov.d       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.d = ctx->f2.d;
            goto L_800640EC;
    }
    goto skip_1;
    // 0x800640E8: mov.d       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.d = ctx->f2.d;
    skip_1:
L_800640EC:
    // 0x800640EC: addu        $a3, $sp, $zero
    ctx->r7 = ADD32(ctx->r29, 0);
    // 0x800640F0: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x800640F4: addiu       $a2, $a2, -0xE60
    ctx->r6 = ADD32(ctx->r6, -0XE60);
    // 0x800640F8: addiu       $t0, $a2, 0x40
    ctx->r8 = ADD32(ctx->r6, 0X40);
L_800640FC:
    // 0x800640FC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80064100: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x80064104: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x80064108: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x8006410C: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80064110: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x80064114: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x80064118: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x8006411C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80064120: bne         $a2, $t0, L_800640FC
    if (ctx->r6 != ctx->r8) {
        // 0x80064124: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_800640FC;
    }
    // 0x80064124: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80064128: div.d       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f12.d); 
    ctx->f12.d = DIV_D(ctx->f14.d, ctx->f12.d);
    // 0x8006412C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80064130: ldc1        $f0, -0xE18($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0XE18);
    // 0x80064134: mul.d       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80064138: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8006413C: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80064140: nop

    // 0x80064144: c.eq.d      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.d == ctx->f4.d;
    // 0x80064148: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8006414C: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x80064150: nop

    // 0x80064154: bc1t        L_80064210
    if (c1cs) {
        // 0x80064158: sw          $zero, 0x40($sp)
        MEM_W(0X40, ctx->r29) = 0;
            goto L_80064210;
    }
    // 0x80064158: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8006415C: c.lt.d      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.d < ctx->f12.d;
    // 0x80064160: nop

    // 0x80064164: nop

    // 0x80064168: bc1t        L_80064174
    if (c1cs) {
        // 0x8006416C: mov.d       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.d = ctx->f12.d;
            goto L_80064174;
    }
    // 0x8006416C: mov.d       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.d = ctx->f12.d;
    // 0x80064170: neg.d       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = -ctx->f12.d;
L_80064174:
    // 0x80064174: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80064178: ldc1        $f0, -0xE10($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0XE10);
    // 0x8006417C: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x80064180: nop

    // 0x80064184: bc1f        L_800641B4
    if (!c1cs) {
        // 0x80064188: nop
    
            goto L_800641B4;
    }
    // 0x80064188: nop

    // 0x8006418C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80064190: ldc1        $f4, -0xE08($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0XE08);
L_80064194:
    // 0x80064194: nop

    // 0x80064198: mul.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x8006419C: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x800641A0: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x800641A4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800641A8: nop

    // 0x800641AC: bc1t        L_80064194
    if (c1cs) {
        // 0x800641B0: sw          $v0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r2;
            goto L_80064194;
    }
    // 0x800641B0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
L_800641B4:
    // 0x800641B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800641B8: ldc1        $f0, -0xE00($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0XE00);
    // 0x800641BC: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x800641C0: nop

    // 0x800641C4: bc1f        L_800641E8
    if (!c1cs) {
        // 0x800641C8: nop
    
            goto L_800641E8;
    }
    // 0x800641C8: nop

L_800641CC:
    // 0x800641CC: add.d       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = ctx->f2.d + ctx->f2.d;
    // 0x800641D0: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x800641D4: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x800641D8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800641DC: nop

    // 0x800641E0: bc1t        L_800641CC
    if (c1cs) {
        // 0x800641E4: sw          $v0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r2;
            goto L_800641CC;
    }
    // 0x800641E4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
L_800641E8:
    // 0x800641E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800641EC: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x800641F0: nop

    // 0x800641F4: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x800641F8: nop

    // 0x800641FC: nop

    // 0x80064200: bc1t        L_8006420C
    if (c1cs) {
        // 0x80064204: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_8006420C;
    }
    // 0x80064204: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    // 0x80064208: neg.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = -ctx->f0.d;
L_8006420C:
    // 0x8006420C: mov.d       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.d = ctx->f0.d;
L_80064210:
    // 0x80064210: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80064214: ldc1        $f0, -0xDF8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0XDF8);
    // 0x80064218: mul.d       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = MUL_D(ctx->f12.d, ctx->f0.d);
    // 0x8006421C: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80064220: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80064224: nop

    // 0x80064228: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8006422C: addu        $v0, $v0, $sp
    ctx->r2 = ADD32(ctx->r2, ctx->r29);
    // 0x80064230: ldc1        $f0, -0x40($v0)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r2, -0X40);
    // 0x80064234: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80064238: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x8006423C: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x80064240: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80064244: ldc1        $f2, -0xDF0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0XDF0);
    // 0x80064248: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8006424C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80064250: ldc1        $f2, -0xDE8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0XDE8);
    // 0x80064254: div.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x80064258: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006425C: ldc1        $f2, -0xDE0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0XDE0);
    // 0x80064260: beq         $a0, $zero, L_80064280
    if (ctx->r4 == 0) {
        // 0x80064264: add.d       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
            goto L_80064280;
    }
    // 0x80064264: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
L_80064268:
    // 0x80064268: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x8006426C: bnel        $v0, $zero, L_80064274
    if (ctx->r2 != 0) {
        // 0x80064270: mul.d       $f2, $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f0.d);
            goto L_80064274;
    }
    goto skip_2;
    // 0x80064270: mul.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f0.d);
    skip_2:
L_80064274:
    // 0x80064274: sra         $a0, $a0, 1
    ctx->r4 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80064278: bne         $a0, $zero, L_80064268
    if (ctx->r4 != 0) {
        // 0x8006427C: mul.d       $f0, $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f0.d);
            goto L_80064268;
    }
    // 0x8006427C: mul.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f0.d);
L_80064280:
    // 0x80064280: nop

    // 0x80064284: mul.d       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x80064288: nop

    // 0x8006428C: mul.d       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x80064290: nop

    // 0x80064294: mul.d       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x80064298: trunc.w.d   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x8006429C: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x800642A0: nop

    // 0x800642A4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800642A8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800642AC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800642B0: nop

    // 0x800642B4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800642B8: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x800642BC: sub.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
    // 0x800642C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800642C4: ldc1        $f2, -0xDD8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0XDD8);
    // 0x800642C8: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x800642CC: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x800642D0: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x800642D4: nop

    // 0x800642D8: sh          $v1, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r3;
L_800642DC:
    // 0x800642DC: jr          $ra
    // 0x800642E0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800642E0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800642E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800642E4: sra         $a1, $a1, 3
    ctx->r5 = S32(SIGNED(ctx->r5) >> 3);
    // 0x800642E8: bne         $a1, $zero, L_800642F8
    if (ctx->r5 != 0) {
        // 0x800642EC: sll         $v0, $a2, 16
        ctx->r2 = S32(ctx->r6 << 16);
            goto L_800642F8;
    }
    // 0x800642EC: sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6 << 16);
    // 0x800642F0: j           L_80064360
    // 0x800642F4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80064360;
    // 0x800642F4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800642F8:
    // 0x800642F8: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800642FC: nop

    // 0x80064300: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80064304: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x80064308: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8006430C: nop

    // 0x80064310: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80064314: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80064318: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8006431C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80064320: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80064324: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80064328: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8006432C: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
L_80064330:
    // 0x80064330: andi        $v0, $a1, 0x1
    ctx->r2 = ctx->r5 & 0X1;
    // 0x80064334: bnel        $v0, $zero, L_8006433C
    if (ctx->r2 != 0) {
        // 0x80064338: mul.s       $f4, $f4, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
            goto L_8006433C;
    }
    goto skip_0;
    // 0x80064338: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    skip_0:
L_8006433C:
    // 0x8006433C: sra         $a1, $a1, 1
    ctx->r5 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80064340: beql        $a1, $zero, L_80064360
    if (ctx->r5 == 0) {
        // 0x80064344: mul.s       $f0, $f12, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
            goto L_80064360;
    }
    goto skip_1;
    // 0x80064344: mul.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    skip_1:
    // 0x80064348: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006434C: slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x80064350: bne         $v0, $zero, L_80064330
    if (ctx->r2 != 0) {
        // 0x80064354: mul.s       $f2, $f2, $f2
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
            goto L_80064330;
    }
    // 0x80064354: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80064358: nop

    // 0x8006435C: mul.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
L_80064360:
    // 0x80064360: jr          $ra
    // 0x80064364: nop

    return;
    // 0x80064364: nop

;}
RECOMP_FUNC void func_80064370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064370: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80064374: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80064378: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x8006437C: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x80064380: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x80064384: jr          $ra
    // 0x80064388: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
    return;
    // 0x80064388: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void func_80064390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064390: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80064394: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80064398: addu        $fp, $a1, $zero
    ctx->r30 = ADD32(ctx->r5, 0);
    // 0x8006439C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800643A0: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x800643A4: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800643A8: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x800643AC: ori         $v1, $v1, 0x440
    ctx->r3 = ctx->r3 | 0X440;
    // 0x800643B0: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    // 0x800643B4: ori         $a1, $a1, 0x580
    ctx->r5 = ctx->r5 | 0X580;
    // 0x800643B8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800643BC: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800643C0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800643C4: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800643C8: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800643CC: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800643D0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800643D4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800643D8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800643DC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x800643E0: lw          $a0, 0x1C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X1C);
    // 0x800643E4: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x800643E8: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800643EC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800643F0: sll         $v1, $s4, 1
    ctx->r3 = S32(ctx->r20 << 1);
    // 0x800643F4: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x800643F8: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x800643FC: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80064400: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x80064404: lw          $v0, 0x14($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X14);
    // 0x80064408: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8006440C: blez        $v0, L_8006449C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80064410: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_8006449C;
    }
    // 0x80064410: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80064414: andi        $s7, $v1, 0xFFFF
    ctx->r23 = ctx->r3 & 0XFFFF;
    // 0x80064418: lui         $s2, 0xC00
    ctx->r18 = S32(0XC00 << 16);
    // 0x8006441C: ori         $s2, $s2, 0x7FFF
    ctx->r18 = ctx->r18 | 0X7FFF;
    // 0x80064420: lui         $s6, 0x6C0
    ctx->r22 = S32(0X6C0 << 16);
    // 0x80064424: ori         $s6, $s6, 0x440
    ctx->r22 = ctx->r22 | 0X440;
    // 0x80064428: lui         $s5, 0x800
    ctx->r21 = S32(0X800 << 16);
    // 0x8006442C: ori         $s5, $s5, 0x580
    ctx->r21 = ctx->r21 | 0X580;
    // 0x80064430: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
L_80064434:
    // 0x80064434: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80064438: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x8006443C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80064440: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80064444: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80064448: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x8006444C: addu        $a1, $fp, $zero
    ctx->r5 = ADD32(ctx->r30, 0);
    // 0x80064450: jalr        $v0
    // 0x80064454: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80064454: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_0:
    // 0x80064458: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8006445C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80064460: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // 0x80064464: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80064468: lui         $t0, 0x800
    ctx->r8 = S32(0X800 << 16);
    // 0x8006446C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80064470: sw          $s7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r23;
    // 0x80064474: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x80064478: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x8006447C: sw          $s6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r22;
    // 0x80064480: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80064484: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x80064488: lw          $v0, 0x14($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X14);
    // 0x8006448C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80064490: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80064494: bne         $v0, $zero, L_80064434
    if (ctx->r2 != 0) {
        // 0x80064498: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_80064434;
    }
    // 0x80064498: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_8006449C:
    // 0x8006449C: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x800644A0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800644A4: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800644A8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800644AC: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800644B0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800644B4: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800644B8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800644BC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800644C0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800644C4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800644C8: jr          $ra
    // 0x800644CC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800644CC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800644D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800644D0: lw          $a3, 0x1C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1C);
    // 0x800644D4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800644D8: bne         $a1, $v0, L_800644F8
    if (ctx->r5 != ctx->r2) {
        // 0x800644DC: nop
    
            goto L_800644F8;
    }
    // 0x800644DC: nop

    // 0x800644E0: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x800644E4: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800644E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800644EC: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800644F0: sw          $v1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r3;
    // 0x800644F4: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
L_800644F8:
    // 0x800644F8: jr          $ra
    // 0x800644FC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800644FC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80064500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064500: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80064504: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80064508: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x8006450C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80064510: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80064514: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80064518: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006451C: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x80064520: addiu       $v0, $zero, 0x140
    ctx->r2 = ADD32(0, 0X140);
    // 0x80064524: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80064528: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x8006452C: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // 0x80064530: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80064534: beq         $s0, $zero, L_800646C8
    if (ctx->r16 == 0) {
        // 0x80064538: addu        $s3, $a1, $zero
        ctx->r19 = ADD32(ctx->r5, 0);
            goto L_800646C8;
    }
    // 0x80064538: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x8006453C: lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1C);
    // 0x80064540: beq         $v0, $zero, L_8006459C
    if (ctx->r2 == 0) {
        // 0x80064544: addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
            goto L_8006459C;
    }
    // 0x80064544: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80064548: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x8006454C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80064550: jalr        $v0
    // 0x80064554: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80064554: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80064558: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8006455C: lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // 0x80064560: lh          $v0, 0x18($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X18);
    // 0x80064564: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x80064568: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8006456C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80064570: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80064574: lui         $v1, 0xA00
    ctx->r3 = S32(0XA00 << 16);
    // 0x80064578: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8006457C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80064580: lhu         $v1, 0x0($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X0);
    // 0x80064584: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x80064588: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8006458C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80064590: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80064594: j           L_800646C8
    // 0x80064598: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
        goto L_800646C8;
    // 0x80064598: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
L_8006459C:
    // 0x8006459C: lwc1        $f0, 0x18($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X18);
    // 0x800645A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800645A4: ldc1        $f2, -0xDD0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0XDD0);
    // 0x800645A8: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x800645AC: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x800645B0: nop

    // 0x800645B4: bc1f        L_800645D0
    if (!c1cs) {
        // 0x800645B8: nop
    
            goto L_800645D0;
    }
    // 0x800645B8: nop

    // 0x800645BC: lui         $at, 0x3FFF
    ctx->r1 = S32(0X3FFF << 16);
    // 0x800645C0: ori         $at, $at, 0xFEB0
    ctx->r1 = ctx->r1 | 0XFEB0;
    // 0x800645C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800645C8: nop

    // 0x800645CC: swc1        $f0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f0.u32l;
L_800645D0:
    // 0x800645D0: lwc1        $f0, 0x18($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X18);
    // 0x800645D4: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800645D8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800645DC: nop

    // 0x800645E0: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800645E4: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800645E8: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x800645EC: nop

    // 0x800645F0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800645F4: nop

    // 0x800645F8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800645FC: div.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80064600: mtc1        $s0, $f0
    ctx->f0.u32l = ctx->r16;
    // 0x80064604: nop

    // 0x80064608: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006460C: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80064610: lwc1        $f2, 0x20($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X20);
    // 0x80064614: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80064618: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8006461C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80064620: nop

    // 0x80064624: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x80064628: nop

    // 0x8006462C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80064630: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80064634: swc1        $f4, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f4.u32l;
    // 0x80064638: swc1        $f2, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f2.u32l;
    // 0x8006463C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80064640: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80064644: jalr        $v0
    // 0x80064648: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x80064648: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x8006464C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80064650: lwc1        $f0, 0x18($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X18);
    // 0x80064654: lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X18);
    // 0x80064658: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8006465C: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x80064660: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80064664: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80064668: lhu         $v1, 0x0($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X0);
    // 0x8006466C: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x80064670: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80064674: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80064678: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8006467C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80064680: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80064684: lbu         $a0, 0x27($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X27);
    // 0x80064688: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8006468C: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    // 0x80064690: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80064694: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80064698: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8006469C: nop

    // 0x800646A0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800646A4: lui         $v1, 0x500
    ctx->r3 = S32(0X500 << 16);
    // 0x800646A8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800646AC: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x800646B0: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
    // 0x800646B4: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800646B8: jal         0x80062180
    // 0x800646BC: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800646BC: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    after_2:
    // 0x800646C0: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800646C4: sw          $zero, 0x24($s2)
    MEM_W(0X24, ctx->r18) = 0;
L_800646C8:
    // 0x800646C8: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x800646CC: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800646D0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800646D4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800646D8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800646DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800646E0: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x800646E4: jr          $ra
    // 0x800646E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800646E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800646EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800646EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800646F0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800646F4: addiu       $a3, $a1, -0x1
    ctx->r7 = ADD32(ctx->r5, -0X1);
    // 0x800646F8: sltiu       $v0, $a3, 0x9
    ctx->r2 = ctx->r7 < 0X9 ? 1 : 0;
    // 0x800646FC: beq         $v0, $zero, L_80064784
    if (ctx->r2 == 0) {
        // 0x80064700: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80064784;
    }
    // 0x80064700: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80064704: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x80064708: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8006470C: addu        $at, $at, $v0
    gpr jr_addend_80064714 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80064710: lw          $v0, -0xDC8($at)
    ctx->r2 = ADD32(ctx->r1, -0XDC8);
    // 0x80064714: jr          $v0
    // 0x80064718: nop

    switch (jr_addend_80064714 >> 2) {
        case 0: goto L_8006471C; break;
        case 1: goto L_80064784; break;
        case 2: goto L_80064784; break;
        case 3: goto L_80064724; break;
        case 4: goto L_80064784; break;
        case 5: goto L_80064784; break;
        case 6: goto L_80064770; break;
        case 7: goto L_80064778; break;
        case 8: goto L_80064750; break;
        default: switch_error(__func__, 0x80064714, 0x800AF238);
    }
    // 0x80064718: nop

L_8006471C:
    // 0x8006471C: j           L_8006479C
    // 0x80064720: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
        goto L_8006479C;
    // 0x80064720: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
L_80064724:
    // 0x80064724: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80064728: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // 0x8006472C: sw          $v0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r2;
    // 0x80064730: sw          $zero, 0x30($v1)
    MEM_W(0X30, ctx->r3) = 0;
    // 0x80064734: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x80064738: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8006473C: beq         $a0, $zero, L_8006479C
    if (ctx->r4 == 0) {
        // 0x80064740: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_8006479C;
    }
    // 0x80064740: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80064744: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80064748: j           L_80064794
    // 0x8006474C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
        goto L_80064794;
    // 0x8006474C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80064750:
    // 0x80064750: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80064754: sw          $v0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r2;
    // 0x80064758: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8006475C: beq         $a0, $zero, L_8006479C
    if (ctx->r4 == 0) {
        // 0x80064760: addiu       $a1, $zero, 0x9
        ctx->r5 = ADD32(0, 0X9);
            goto L_8006479C;
    }
    // 0x80064760: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80064764: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80064768: j           L_80064794
    // 0x8006476C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
        goto L_80064794;
    // 0x8006476C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80064770:
    // 0x80064770: j           L_8006479C
    // 0x80064774: sw          $a2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r6;
        goto L_8006479C;
    // 0x80064774: sw          $a2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r6;
L_80064778:
    // 0x80064778: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006477C: j           L_8006479C
    // 0x80064780: sw          $v0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r2;
        goto L_8006479C;
    // 0x80064780: sw          $v0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r2;
L_80064784:
    // 0x80064784: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80064788: beq         $a0, $zero, L_8006479C
    if (ctx->r4 == 0) {
        // 0x8006478C: nop
    
            goto L_8006479C;
    }
    // 0x8006478C: nop

    // 0x80064790: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
L_80064794:
    // 0x80064794: jalr        $v0
    // 0x80064798: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80064798: nop

    after_0:
L_8006479C:
    // 0x8006479C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800647A0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800647A4: jr          $ra
    // 0x800647A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800647A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800647B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800647B0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800647B4: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800647B8: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800647BC: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800647C0: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x800647C4: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800647C8: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x800647CC: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800647D0: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800647D4: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800647D8: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800647DC: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800647E0: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800647E4: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800647E8: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800647EC: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x800647F0: lw          $s1, 0x78($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X78);
    // 0x800647F4: bne         $s0, $zero, L_80064814
    if (ctx->r16 != 0) {
        // 0x800647F8: addu        $fp, $zero, $zero
        ctx->r30 = ADD32(0, 0);
            goto L_80064814;
    }
    // 0x800647F8: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // 0x800647FC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80064800: addiu       $a0, $a0, -0xDA0
    ctx->r4 = ADD32(ctx->r4, -0XDA0);
    // 0x80064804: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80064808: addiu       $a1, $a1, -0xD9C
    ctx->r5 = ADD32(ctx->r5, -0XD9C);
    // 0x8006480C: jal         0x800621E0
    // 0x80064810: addiu       $a2, $zero, 0x4B
    ctx->r6 = ADD32(0, 0X4B);
    func_800621E0(rdram, ctx);
        goto after_0;
    // 0x80064810: addiu       $a2, $zero, 0x4B
    ctx->r6 = ADD32(0, 0X4B);
    after_0:
L_80064814:
    // 0x80064814: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80064818: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8006481C: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x80064820: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80064824: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80064828: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // 0x8006482C: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // 0x80064830: jalr        $v0
    // 0x80064834: sh          $zero, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x80064834: sh          $zero, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = 0;
    after_1:
    // 0x80064838: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8006483C: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x80064840: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80064844: addu        $t0, $s1, $zero
    ctx->r8 = ADD32(ctx->r17, 0);
    // 0x80064848: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8006484C: lui         $t2, 0xC00
    ctx->r10 = S32(0XC00 << 16);
    // 0x80064850: ori         $t2, $t2, 0xDA83
    ctx->r10 = ctx->r10 | 0XDA83;
    // 0x80064854: lui         $t1, 0x6C0
    ctx->r9 = S32(0X6C0 << 16);
    // 0x80064858: ori         $t1, $t1, 0x6C0
    ctx->r9 = ctx->r9 | 0X6C0;
    // 0x8006485C: addu        $v1, $s1, $zero
    ctx->r3 = ADD32(ctx->r17, 0);
    // 0x80064860: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80064864: lui         $a2, 0xC00
    ctx->r6 = S32(0XC00 << 16);
    // 0x80064868: ori         $a2, $a2, 0x5A82
    ctx->r6 = ctx->r6 | 0X5A82;
    // 0x8006486C: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x80064870: ori         $a1, $a1, 0x6C0
    ctx->r5 = ctx->r5 | 0X6C0;
    // 0x80064874: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80064878: lui         $v0, 0x800
    ctx->r2 = S32(0X800 << 16);
    // 0x8006487C: sll         $s0, $s5, 1
    ctx->r16 = S32(ctx->r21 << 1);
    // 0x80064880: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80064884: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x80064888: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x8006488C: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80064890: sw          $t1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r9;
    // 0x80064894: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x80064898: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8006489C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x800648A0: lw          $a1, 0x18($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X18);
    // 0x800648A4: addiu       $a2, $zero, 0x6C0
    ctx->r6 = ADD32(0, 0X6C0);
    // 0x800648A8: jal         0x800650EC
    // 0x800648AC: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    func_800650EC(rdram, ctx);
        goto after_2;
    // 0x800648AC: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    after_2:
    // 0x800648B0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800648B4: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x800648B8: ori         $v1, $v1, 0x800
    ctx->r3 = ctx->r3 | 0X800;
    // 0x800648BC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800648C0: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x800648C4: lbu         $v0, 0x24($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X24);
    // 0x800648C8: addiu       $s6, $zero, 0x140
    ctx->r22 = ADD32(0, 0X140);
    // 0x800648CC: slt         $v0, $fp, $v0
    ctx->r2 = SIGNED(ctx->r30) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800648D0: beq         $v0, $zero, L_80064AD0
    if (ctx->r2 == 0) {
        // 0x800648D4: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80064AD0;
    }
    // 0x800648D4: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_800648D8:
    // 0x800648D8: lhu         $t3, 0x1E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X1E);
    // 0x800648DC: lw          $a0, 0x20($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X20);
    // 0x800648E0: sll         $v1, $t3, 16
    ctx->r3 = S32(ctx->r11 << 16);
    // 0x800648E4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800648E8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800648EC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800648F0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800648F4: addu        $s2, $a0, $v0
    ctx->r18 = ADD32(ctx->r4, ctx->r2);
    // 0x800648F8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800648FC: lw          $a0, 0x18($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X18);
    // 0x80064900: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x80064904: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80064908: subu        $s4, $a0, $v0
    ctx->r20 = SUB32(ctx->r4, ctx->r2);
    // 0x8006490C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80064910: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x80064914: bne         $s4, $fp, L_8006492C
    if (ctx->r20 != ctx->r30) {
        // 0x80064918: sw          $a0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r4;
            goto L_8006492C;
    }
    // 0x80064918: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x8006491C: addu        $v0, $s6, $zero
    ctx->r2 = ADD32(ctx->r22, 0);
    // 0x80064920: addu        $s6, $s7, $zero
    ctx->r22 = ADD32(ctx->r23, 0);
    // 0x80064924: j           L_8006494C
    // 0x80064928: addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
        goto L_8006494C;
    // 0x80064928: addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
L_8006492C:
    // 0x8006492C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80064930: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80064934: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80064938: sll         $a2, $s7, 16
    ctx->r6 = S32(ctx->r23 << 16);
    // 0x8006493C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80064940: jal         0x80064F7C
    // 0x80064944: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    func_80064F7C(rdram, ctx);
        goto after_3;
    // 0x80064944: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    after_3:
    // 0x80064948: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_8006494C:
    // 0x8006494C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80064950: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80064954: sll         $v0, $s6, 16
    ctx->r2 = S32(ctx->r22 << 16);
    // 0x80064958: sra         $s0, $v0, 16
    ctx->r16 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006495C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80064960: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // 0x80064964: jal         0x80064D64
    // 0x80064968: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80064D64(rdram, ctx);
        goto after_4;
    // 0x80064968: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_4:
    // 0x8006496C: lh          $v1, 0x8($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X8);
    // 0x80064970: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80064974: beq         $v1, $zero, L_800649D0
    if (ctx->r3 == 0) {
        // 0x80064978: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_800649D0;
    }
    // 0x80064978: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8006497C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80064980: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80064984: lui         $t3, 0xC00
    ctx->r11 = S32(0XC00 << 16);
    // 0x80064988: or          $v0, $v0, $t3
    ctx->r2 = ctx->r2 | ctx->r11;
    // 0x8006498C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80064990: sll         $v0, $s7, 16
    ctx->r2 = S32(ctx->r23 << 16);
    // 0x80064994: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x80064998: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8006499C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x800649A0: lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X24);
    // 0x800649A4: bne         $v0, $zero, L_800649D0
    if (ctx->r2 != 0) {
        // 0x800649A8: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_800649D0;
    }
    // 0x800649A8: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800649AC: lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X20);
    // 0x800649B0: bne         $v0, $zero, L_800649D0
    if (ctx->r2 != 0) {
        // 0x800649B4: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_800649D0;
    }
    // 0x800649B4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800649B8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800649BC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800649C0: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // 0x800649C4: jal         0x800650EC
    // 0x800649C8: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_800650EC(rdram, ctx);
        goto after_5;
    // 0x800649C8: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_5:
    // 0x800649CC: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_800649D0:
    // 0x800649D0: lh          $v0, 0xA($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XA);
    // 0x800649D4: beq         $v0, $zero, L_80064A24
    if (ctx->r2 == 0) {
        // 0x800649D8: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80064A24;
    }
    // 0x800649D8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800649DC: addu        $t0, $s1, $zero
    ctx->r8 = ADD32(ctx->r17, 0);
    // 0x800649E0: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800649E4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800649E8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800649EC: sll         $a2, $s7, 16
    ctx->r6 = S32(ctx->r23 << 16);
    // 0x800649F0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800649F4: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // 0x800649F8: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x800649FC: lui         $t3, 0xC00
    ctx->r11 = S32(0XC00 << 16);
    // 0x80064A00: or          $v0, $v0, $t3
    ctx->r2 = ctx->r2 | ctx->r11;
    // 0x80064A04: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80064A08: sll         $v0, $s6, 16
    ctx->r2 = S32(ctx->r22 << 16);
    // 0x80064A0C: andi        $v1, $a2, 0xFFFF
    ctx->r3 = ctx->r6 & 0XFFFF;
    // 0x80064A10: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80064A14: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x80064A18: jal         0x800650EC
    // 0x80064A1C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_800650EC(rdram, ctx);
        goto after_6;
    // 0x80064A1C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_6:
    // 0x80064A20: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_80064A24:
    // 0x80064A24: lw          $a0, 0x20($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X20);
    // 0x80064A28: beq         $a0, $zero, L_80064A44
    if (ctx->r4 == 0) {
        // 0x80064A2C: sll         $a1, $s6, 16
        ctx->r5 = S32(ctx->r22 << 16);
            goto L_80064A44;
    }
    // 0x80064A2C: sll         $a1, $s6, 16
    ctx->r5 = S32(ctx->r22 << 16);
    // 0x80064A30: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80064A34: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x80064A38: jal         0x8006525C
    // 0x80064A3C: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    func_8006525C(rdram, ctx);
        goto after_7;
    // 0x80064A3C: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_7:
    // 0x80064A40: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_80064A44:
    // 0x80064A44: lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X24);
    // 0x80064A48: bne         $v0, $zero, L_80064A6C
    if (ctx->r2 != 0) {
        // 0x80064A4C: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_80064A6C;
    }
    // 0x80064A4C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80064A50: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80064A54: sll         $a2, $s6, 16
    ctx->r6 = S32(ctx->r22 << 16);
    // 0x80064A58: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80064A5C: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // 0x80064A60: jal         0x800650EC
    // 0x80064A64: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_800650EC(rdram, ctx);
        goto after_8;
    // 0x80064A64: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_8:
    // 0x80064A68: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_80064A6C:
    // 0x80064A6C: lh          $v0, 0xC($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XC);
    // 0x80064A70: beq         $v0, $zero, L_80064A9C
    if (ctx->r2 == 0) {
        // 0x80064A74: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80064A9C;
    }
    // 0x80064A74: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80064A78: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x80064A7C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80064A80: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80064A84: lui         $t3, 0xC00
    ctx->r11 = S32(0XC00 << 16);
    // 0x80064A88: or          $v1, $v1, $t3
    ctx->r3 = ctx->r3 | ctx->r11;
    // 0x80064A8C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80064A90: sll         $v1, $s6, 16
    ctx->r3 = S32(ctx->r22 << 16);
    // 0x80064A94: ori         $v1, $v1, 0x800
    ctx->r3 = ctx->r3 | 0X800;
    // 0x80064A98: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80064A9C:
    // 0x80064A9C: lhu         $t3, 0x1E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X1E);
    // 0x80064AA0: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x80064AA4: lw          $a0, 0x18($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X18);
    // 0x80064AA8: addiu       $v0, $t3, 0x1
    ctx->r2 = ADD32(ctx->r11, 0X1);
    // 0x80064AAC: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80064AB0: addu        $fp, $a0, $v1
    ctx->r30 = ADD32(ctx->r4, ctx->r3);
    // 0x80064AB4: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x80064AB8: lbu         $v1, 0x24($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X24);
    // 0x80064ABC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80064AC0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80064AC4: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80064AC8: bne         $v0, $zero, L_800648D8
    if (ctx->r2 != 0) {
        // 0x80064ACC: nop
    
            goto L_800648D8;
    }
    // 0x80064ACC: nop

L_80064AD0:
    // 0x80064AD0: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
    // 0x80064AD4: lw          $a0, 0x1C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X1C);
    // 0x80064AD8: lw          $v1, 0x14($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X14);
    // 0x80064ADC: sll         $a2, $s5, 1
    ctx->r6 = S32(ctx->r21 << 1);
    // 0x80064AE0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80064AE4: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x80064AE8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80064AEC: sltu        $v1, $v1, $v0
    ctx->r3 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80064AF0: beq         $v1, $zero, L_80064B00
    if (ctx->r3 == 0) {
        // 0x80064AF4: sw          $v0, 0x18($s3)
        MEM_W(0X18, ctx->r19) = ctx->r2;
            goto L_80064B00;
    }
    // 0x80064AF4: sw          $v0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r2;
    // 0x80064AF8: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80064AFC: sw          $v0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r2;
L_80064B00:
    // 0x80064B00: addiu       $v0, $s1, 0x8
    ctx->r2 = ADD32(ctx->r17, 0X8);
    // 0x80064B04: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80064B08: addiu       $t3, $zero, 0x800
    ctx->r11 = ADD32(0, 0X800);
    // 0x80064B0C: sll         $v1, $t3, 16
    ctx->r3 = S32(ctx->r11 << 16);
    // 0x80064B10: srl         $v1, $v1, 16
    ctx->r3 = S32(U32(ctx->r3) >> 16);
    // 0x80064B14: lui         $a0, 0xA00
    ctx->r4 = S32(0XA00 << 16);
    // 0x80064B18: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x80064B1C: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80064B20: andi        $v1, $a2, 0xFFFF
    ctx->r3 = ctx->r6 & 0XFFFF;
    // 0x80064B24: lui         $a0, 0x6C0
    ctx->r4 = S32(0X6C0 << 16);
    // 0x80064B28: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x80064B2C: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // 0x80064B30: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80064B34: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80064B38: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80064B3C: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80064B40: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80064B44: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80064B48: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80064B4C: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80064B50: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80064B54: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80064B58: jr          $ra
    // 0x80064B5C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80064B5C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80064B60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064B60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80064B64: beql        $a1, $v0, L_80064B6C
    if (ctx->r5 == ctx->r2) {
        // 0x80064B68: sw          $a2, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r6;
            goto L_80064B6C;
    }
    goto skip_0;
    // 0x80064B68: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    skip_0:
L_80064B6C:
    // 0x80064B6C: jr          $ra
    // 0x80064B70: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80064B70: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_80064B74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064B74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064B78: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80064B7C: addiu       $v1, $a1, -0x2
    ctx->r3 = ADD32(ctx->r5, -0X2);
    // 0x80064B80: bgez        $v1, L_80064B8C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80064B84: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80064B8C;
    }
    // 0x80064B84: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80064B88: addiu       $v0, $a1, 0x5
    ctx->r2 = ADD32(ctx->r5, 0X5);
L_80064B8C:
    // 0x80064B8C: sra         $a3, $v0, 3
    ctx->r7 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80064B90: addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
    // 0x80064B94: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x80064B98: subu        $a3, $v1, $v0
    ctx->r7 = SUB32(ctx->r3, ctx->r2);
    // 0x80064B9C: lw          $a2, 0x0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X0);
    // 0x80064BA0: sltiu       $v0, $a3, 0x8
    ctx->r2 = ctx->r7 < 0X8 ? 1 : 0;
    // 0x80064BA4: beq         $v0, $zero, L_80064D54
    if (ctx->r2 == 0) {
        // 0x80064BA8: nop
    
            goto L_80064D54;
    }
    // 0x80064BA8: nop

    // 0x80064BAC: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x80064BB0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80064BB4: addu        $at, $at, $v0
    gpr jr_addend_80064BBC = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80064BB8: lw          $v0, -0xD90($at)
    ctx->r2 = ADD32(ctx->r1, -0XD90);
    // 0x80064BBC: jr          $v0
    // 0x80064BC0: nop

    switch (jr_addend_80064BBC >> 2) {
        case 0: goto L_80064BC4; break;
        case 1: goto L_80064BE8; break;
        case 2: goto L_80064C28; break;
        case 3: goto L_80064C0C; break;
        case 4: goto L_80064C44; break;
        case 5: goto L_80064C60; break;
        case 6: goto L_80064CB4; break;
        case 7: goto L_80064D20; break;
        default: switch_error(__func__, 0x80064BBC, 0x800AF270);
    }
    // 0x80064BC0: nop

L_80064BC4:
    // 0x80064BC4: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x80064BC8: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x80064BCC: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80064BD0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80064BD4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80064BD8: addiu       $v0, $zero, -0x8
    ctx->r2 = ADD32(0, -0X8);
    // 0x80064BDC: and         $v0, $a2, $v0
    ctx->r2 = ctx->r6 & ctx->r2;
    // 0x80064BE0: j           L_80064D54
    // 0x80064BE4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_80064D54;
    // 0x80064BE4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80064BE8:
    // 0x80064BE8: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x80064BEC: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x80064BF0: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80064BF4: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80064BF8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80064BFC: addiu       $v0, $zero, -0x8
    ctx->r2 = ADD32(0, -0X8);
    // 0x80064C00: and         $v0, $a2, $v0
    ctx->r2 = ctx->r6 & ctx->r2;
    // 0x80064C04: j           L_80064D54
    // 0x80064C08: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
        goto L_80064D54;
    // 0x80064C08: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80064C0C:
    // 0x80064C0C: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
    // 0x80064C10: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80064C14: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80064C18: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80064C1C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80064C20: j           L_80064D54
    // 0x80064C24: sh          $a2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r6;
        goto L_80064D54;
    // 0x80064C24: sh          $a2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r6;
L_80064C28:
    // 0x80064C28: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
    // 0x80064C2C: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80064C30: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80064C34: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80064C38: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80064C3C: j           L_80064D54
    // 0x80064C40: sh          $a2, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r6;
        goto L_80064D54;
    // 0x80064C40: sh          $a2, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r6;
L_80064C44:
    // 0x80064C44: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
    // 0x80064C48: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80064C4C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80064C50: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80064C54: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80064C58: j           L_80064D54
    // 0x80064C5C: sh          $a2, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r6;
        goto L_80064D54;
    // 0x80064C5C: sh          $a2, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r6;
L_80064C60:
    // 0x80064C60: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80064C64: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80064C68: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x80064C6C: nop

    // 0x80064C70: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80064C74: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80064C78: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80064C7C: lw          $v0, 0x6E40($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E40);
    // 0x80064C80: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80064C84: add.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
    // 0x80064C88: lwc1        $f2, 0x44($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80064C8C: cvt.d.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.d = CVT_D_W(ctx->f2.u32l);
    // 0x80064C90: div.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x80064C94: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
    // 0x80064C98: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80064C9C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80064CA0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80064CA4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80064CA8: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x80064CAC: j           L_80064D54
    // 0x80064CB0: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
        goto L_80064D54;
    // 0x80064CB0: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
L_80064CB4:
    // 0x80064CB4: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
    // 0x80064CB8: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80064CBC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80064CC0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80064CC4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80064CC8: ldc1        $f2, -0xD70($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0XD70);
    // 0x80064CCC: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x80064CD0: nop

    // 0x80064CD4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80064CD8: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x80064CDC: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80064CE0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80064CE4: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80064CE8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80064CEC: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80064CF0: nop

    // 0x80064CF4: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x80064CF8: bgez        $v1, L_80064D0C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80064CFC: div.d       $f2, $f0, $f2
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = DIV_D(ctx->f0.d, ctx->f2.d);
            goto L_80064D0C;
    }
    // 0x80064CFC: div.d       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x80064D00: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80064D04: ldc1        $f0, -0xD68($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0XD68);
    // 0x80064D08: add.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f4.d + ctx->f0.d;
L_80064D0C:
    // 0x80064D0C: nop

    // 0x80064D10: mul.d       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x80064D14: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x80064D18: j           L_80064D54
    // 0x80064D1C: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
        goto L_80064D54;
    // 0x80064D1C: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
L_80064D20:
    // 0x80064D20: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
    // 0x80064D24: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80064D28: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80064D2C: sll         $a1, $v0, 3
    ctx->r5 = S32(ctx->r2 << 3);
    // 0x80064D30: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x80064D34: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x80064D38: beq         $v0, $zero, L_80064D54
    if (ctx->r2 == 0) {
        // 0x80064D3C: nop
    
            goto L_80064D54;
    }
    // 0x80064D3C: nop

    // 0x80064D40: sh          $a2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r6;
    // 0x80064D44: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x80064D48: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80064D4C: jal         0x800621F0
    // 0x80064D50: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    func_800621F0(rdram, ctx);
        goto after_0;
    // 0x80064D50: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    after_0:
L_80064D54:
    // 0x80064D54: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80064D58: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80064D5C: jr          $ra
    // 0x80064D60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80064D60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80064D64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064D64: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80064D68: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80064D6C: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x80064D70: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80064D74: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80064D78: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80064D7C: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x80064D80: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80064D84: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80064D88: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80064D8C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80064D90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80064D94: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x80064D98: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80064D9C: lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X24);
    // 0x80064DA0: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x80064DA4: beq         $v0, $zero, L_80064F20
    if (ctx->r2 == 0) {
        // 0x80064DA8: addu        $s5, $a3, $zero
        ctx->r21 = ADD32(ctx->r7, 0);
            goto L_80064F20;
    }
    // 0x80064DA8: addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // 0x80064DAC: lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4);
    // 0x80064DB0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80064DB4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80064DB8: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x80064DBC: jal         0x800652F8
    // 0x80064DC0: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    func_800652F8(rdram, ctx);
        goto after_0;
    // 0x80064DC0: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    after_0:
    // 0x80064DC4: mtc1        $s0, $f2
    ctx->f2.u32l = ctx->r16;
    // 0x80064DC8: nop

    // 0x80064DCC: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80064DD0: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80064DD4: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x80064DD8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80064DDC: nop

    // 0x80064DE0: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80064DE4: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80064DE8: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80064DEC: nop

    // 0x80064DF0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80064DF4: nop

    // 0x80064DF8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80064DFC: div.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80064E00: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80064E04: ldc1        $f20, -0xD60($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0XD60);
    // 0x80064E08: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80064E0C: sub.d       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f20.d = ctx->f20.d - ctx->f0.d;
    // 0x80064E10: mtc1        $s5, $f2
    ctx->f2.u32l = ctx->r21;
    // 0x80064E14: nop

    // 0x80064E18: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80064E1C: cvt.s.d     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.fl = CVT_S_D(ctx->f20.d);
    // 0x80064E20: mul.s       $f2, $f20, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80064E24: lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X24);
    // 0x80064E28: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80064E2C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80064E30: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80064E34: mfc1        $s1, $f2
    ctx->r17 = (int32_t)ctx->f2.u32l;
    // 0x80064E38: nop

    // 0x80064E3C: mtc1        $s1, $f2
    ctx->f2.u32l = ctx->r17;
    // 0x80064E40: nop

    // 0x80064E44: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80064E48: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80064E4C: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80064E50: lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X18);
    // 0x80064E54: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x80064E58: lw          $a1, 0x18($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X18);
    // 0x80064E5C: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80064E60: addiu       $a2, $zero, 0x280
    ctx->r6 = ADD32(0, 0X280);
    // 0x80064E64: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80064E68: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80064E6C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80064E70: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80064E74: andi        $a3, $a1, 0x7
    ctx->r7 = ctx->r5 & 0X7;
    // 0x80064E78: sra         $a3, $a3, 1
    ctx->r7 = S32(SIGNED(ctx->r7) >> 1);
    // 0x80064E7C: sll         $s0, $a3, 1
    ctx->r16 = S32(ctx->r7 << 1);
    // 0x80064E80: subu        $a1, $a1, $s0
    ctx->r5 = SUB32(ctx->r5, ctx->r16);
    // 0x80064E84: jal         0x80064F7C
    // 0x80064E88: addu        $a3, $s1, $a3
    ctx->r7 = ADD32(ctx->r17, ctx->r7);
    func_80064F7C(rdram, ctx);
        goto after_1;
    // 0x80064E88: addu        $a3, $s1, $a3
    ctx->r7 = ADD32(ctx->r17, ctx->r7);
    after_1:
    // 0x80064E8C: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80064E90: lui         $v0, 0x800
    ctx->r2 = S32(0X800 << 16);
    // 0x80064E94: ori         $v0, $v0, 0x280
    ctx->r2 = ctx->r2 | 0X280;
    // 0x80064E98: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80064E9C: or          $s0, $s0, $v0
    ctx->r16 = ctx->r16 | ctx->r2;
    // 0x80064EA0: sll         $v1, $s6, 16
    ctx->r3 = S32(ctx->r22 << 16);
    // 0x80064EA4: sll         $v0, $s5, 1
    ctx->r2 = S32(ctx->r21 << 1);
    // 0x80064EA8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80064EAC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80064EB0: sw          $s0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r16;
    // 0x80064EB4: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80064EB8: lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X24);
    // 0x80064EBC: mul.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x80064EC0: lbu         $a0, 0x27($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X27);
    // 0x80064EC4: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x80064EC8: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    // 0x80064ECC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80064ED0: trunc.w.s   $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x80064ED4: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x80064ED8: nop

    // 0x80064EDC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80064EE0: lui         $v1, 0x500
    ctx->r3 = S32(0X500 << 16);
    // 0x80064EE4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80064EE8: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80064EEC: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
    // 0x80064EF0: lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X24);
    // 0x80064EF4: lw          $a0, 0x14($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X14);
    // 0x80064EF8: jal         0x80062180
    // 0x80064EFC: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x80064EFC: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    after_2:
    // 0x80064F00: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80064F04: lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X24);
    // 0x80064F08: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80064F0C: lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X18);
    // 0x80064F10: subu        $s1, $s1, $s5
    ctx->r17 = SUB32(ctx->r17, ctx->r21);
    // 0x80064F14: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80064F18: j           L_80064F48
    // 0x80064F1C: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
        goto L_80064F48;
    // 0x80064F1C: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
L_80064F20:
    // 0x80064F20: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80064F24: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x80064F28: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80064F2C: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    // 0x80064F30: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // 0x80064F34: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80064F38: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x80064F3C: jal         0x80064F7C
    // 0x80064F40: subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    func_80064F7C(rdram, ctx);
        goto after_3;
    // 0x80064F40: subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_3:
    // 0x80064F44: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
L_80064F48:
    // 0x80064F48: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x80064F4C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80064F50: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80064F54: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80064F58: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80064F5C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80064F60: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80064F64: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80064F68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80064F6C: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x80064F70: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80064F74: jr          $ra
    // 0x80064F78: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80064F78: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80064F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064F7C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80064F80: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80064F84: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x80064F88: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x80064F8C: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x80064F90: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x80064F94: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80064F98: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x80064F9C: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x80064FA0: addu        $fp, $a3, $zero
    ctx->r30 = ADD32(ctx->r7, 0);
    // 0x80064FA4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80064FA8: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80064FAC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80064FB0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80064FB4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80064FB8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80064FBC: lw          $v1, 0x1C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X1C);
    // 0x80064FC0: lw          $v0, 0x14($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X14);
    // 0x80064FC4: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80064FC8: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // 0x80064FCC: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80064FD0: beq         $v0, $zero, L_80064FDC
    if (ctx->r2 == 0) {
        // 0x80064FD4: addu        $a2, $s5, $zero
        ctx->r6 = ADD32(ctx->r21, 0);
            goto L_80064FDC;
    }
    // 0x80064FD4: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x80064FD8: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_80064FDC:
    // 0x80064FDC: sll         $a3, $fp, 1
    ctx->r7 = S32(ctx->r30 << 1);
    // 0x80064FE0: addu        $s1, $a0, $a3
    ctx->r17 = ADD32(ctx->r4, ctx->r7);
    // 0x80064FE4: sltu        $v0, $a1, $s1
    ctx->r2 = ctx->r5 < ctx->r17 ? 1 : 0;
    // 0x80064FE8: beq         $v0, $zero, L_8006506C
    if (ctx->r2 == 0) {
        // 0x80064FEC: andi        $v0, $s6, 0xFFFF
        ctx->r2 = ctx->r22 & 0XFFFF;
            goto L_8006506C;
    }
    // 0x80064FEC: andi        $v0, $s6, 0xFFFF
    ctx->r2 = ctx->r22 & 0XFFFF;
    // 0x80064FF0: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80064FF4: addu        $s4, $s5, $zero
    ctx->r20 = ADD32(ctx->r21, 0);
    // 0x80064FF8: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80064FFC: lui         $s3, 0x800
    ctx->r19 = S32(0X800 << 16);
    // 0x80065000: or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
    // 0x80065004: subu        $s0, $a1, $a0
    ctx->r16 = SUB32(ctx->r5, ctx->r4);
    // 0x80065008: sra         $s0, $s0, 1
    ctx->r16 = S32(SIGNED(ctx->r16) >> 1);
    // 0x8006500C: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x80065010: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80065014: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x80065018: lui         $s2, 0x400
    ctx->r18 = S32(0X400 << 16);
    // 0x8006501C: subu        $s1, $s1, $a1
    ctx->r17 = SUB32(ctx->r17, ctx->r5);
    // 0x80065020: sra         $s1, $s1, 1
    ctx->r17 = S32(SIGNED(ctx->r17) >> 1);
    // 0x80065024: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x80065028: jal         0x80062180
    // 0x8006502C: sw          $s2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r18;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x8006502C: sw          $s2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r18;
    after_0:
    // 0x80065030: addu        $v1, $s5, $zero
    ctx->r3 = ADD32(ctx->r21, 0);
    // 0x80065034: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80065038: addu        $s0, $s6, $s0
    ctx->r16 = ADD32(ctx->r22, ctx->r16);
    // 0x8006503C: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x80065040: or          $s0, $s0, $s3
    ctx->r16 = ctx->r16 | ctx->r19;
    // 0x80065044: sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17 << 1);
    // 0x80065048: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x8006504C: sw          $v0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r2;
    // 0x80065050: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    // 0x80065054: addu        $s0, $s5, $zero
    ctx->r16 = ADD32(ctx->r21, 0);
    // 0x80065058: sw          $s1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r17;
    // 0x8006505C: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
    // 0x80065060: lw          $a0, 0x14($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X14);
    // 0x80065064: j           L_80065094
    // 0x80065068: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
        goto L_80065094;
    // 0x80065068: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
L_8006506C:
    // 0x8006506C: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80065070: addu        $s0, $s5, $zero
    ctx->r16 = ADD32(ctx->r21, 0);
    // 0x80065074: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80065078: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x8006507C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80065080: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80065084: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x80065088: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x8006508C: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x80065090: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_80065094:
    // 0x80065094: jal         0x80062180
    // 0x80065098: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80065098: nop

    after_1:
    // 0x8006509C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800650A0: addiu       $v0, $s5, 0x8
    ctx->r2 = ADD32(ctx->r21, 0X8);
    // 0x800650A4: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800650A8: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x800650AC: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800650B0: sll         $v1, $fp, 1
    ctx->r3 = S32(ctx->r30 << 1);
    // 0x800650B4: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800650B8: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x800650BC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800650C0: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x800650C4: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x800650C8: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800650CC: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800650D0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800650D4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800650D8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800650DC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800650E0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800650E4: jr          $ra
    // 0x800650E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800650E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800650EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800650EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800650F0: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800650F4: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x800650F8: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x800650FC: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x80065100: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x80065104: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80065108: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x8006510C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80065110: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x80065114: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80065118: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8006511C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80065120: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80065124: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80065128: lw          $v1, 0x1C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X1C);
    // 0x8006512C: lw          $v0, 0x14($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X14);
    // 0x80065130: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80065134: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // 0x80065138: sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8006513C: beq         $v0, $zero, L_80065148
    if (ctx->r2 == 0) {
        // 0x80065140: addu        $a2, $s5, $zero
        ctx->r6 = ADD32(ctx->r21, 0);
            goto L_80065148;
    }
    // 0x80065140: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x80065144: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_80065148:
    // 0x80065148: sll         $fp, $a3, 1
    ctx->r30 = S32(ctx->r7 << 1);
    // 0x8006514C: addu        $s0, $a0, $fp
    ctx->r16 = ADD32(ctx->r4, ctx->r30);
    // 0x80065150: sltu        $v0, $a1, $s0
    ctx->r2 = ctx->r5 < ctx->r16 ? 1 : 0;
    // 0x80065154: beq         $v0, $zero, L_800651F4
    if (ctx->r2 == 0) {
        // 0x80065158: lui         $s2, 0x800
        ctx->r18 = S32(0X800 << 16);
            goto L_800651F4;
    }
    // 0x80065158: lui         $s2, 0x800
    ctx->r18 = S32(0X800 << 16);
    // 0x8006515C: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80065160: addu        $s4, $s5, $zero
    ctx->r20 = ADD32(ctx->r21, 0);
    // 0x80065164: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80065168: subu        $s1, $a1, $a0
    ctx->r17 = SUB32(ctx->r5, ctx->r4);
    // 0x8006516C: sra         $s1, $s1, 1
    ctx->r17 = S32(SIGNED(ctx->r17) >> 1);
    // 0x80065170: sll         $v0, $s6, 16
    ctx->r2 = S32(ctx->r22 << 16);
    // 0x80065174: sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17 << 1);
    // 0x80065178: andi        $v1, $s1, 0xFFFF
    ctx->r3 = ctx->r17 & 0XFFFF;
    // 0x8006517C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80065180: lui         $s3, 0x600
    ctx->r19 = S32(0X600 << 16);
    // 0x80065184: subu        $s0, $s0, $a1
    ctx->r16 = SUB32(ctx->r16, ctx->r5);
    // 0x80065188: sra         $s0, $s0, 1
    ctx->r16 = S32(SIGNED(ctx->r16) >> 1);
    // 0x8006518C: sw          $s2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r18;
    // 0x80065190: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x80065194: jal         0x80062180
    // 0x80065198: sw          $s3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r19;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x80065198: sw          $s3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r19;
    after_0:
    // 0x8006519C: addu        $v1, $s5, $zero
    ctx->r3 = ADD32(ctx->r21, 0);
    // 0x800651A0: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x800651A4: addu        $s1, $s6, $s1
    ctx->r17 = ADD32(ctx->r22, ctx->r17);
    // 0x800651A8: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x800651AC: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x800651B0: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x800651B4: or          $s1, $s1, $s0
    ctx->r17 = ctx->r17 | ctx->r16;
    // 0x800651B8: addu        $s0, $s5, $zero
    ctx->r16 = ADD32(ctx->r21, 0);
    // 0x800651BC: sw          $v0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r2;
    // 0x800651C0: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x800651C4: sw          $s1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r17;
    // 0x800651C8: sw          $s3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r19;
    // 0x800651CC: lw          $a0, 0x14($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X14);
    // 0x800651D0: jal         0x80062180
    // 0x800651D4: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800651D4: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    after_1:
    // 0x800651D8: addu        $v1, $s5, $zero
    ctx->r3 = ADD32(ctx->r21, 0);
    // 0x800651DC: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x800651E0: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800651E4: andi        $v0, $fp, 0xFFFF
    ctx->r2 = ctx->r30 & 0XFFFF;
    // 0x800651E8: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x800651EC: j           L_80065228
    // 0x800651F0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
        goto L_80065228;
    // 0x800651F0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800651F4:
    // 0x800651F4: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x800651F8: addu        $s0, $s5, $zero
    ctx->r16 = ADD32(ctx->r21, 0);
    // 0x800651FC: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80065200: lui         $v0, 0x800
    ctx->r2 = S32(0X800 << 16);
    // 0x80065204: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80065208: sll         $v0, $s6, 16
    ctx->r2 = S32(ctx->r22 << 16);
    // 0x8006520C: andi        $v1, $fp, 0xFFFF
    ctx->r3 = ctx->r30 & 0XFFFF;
    // 0x80065210: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80065214: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x80065218: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x8006521C: jal         0x80062180
    // 0x80065220: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x80065220: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    after_2:
    // 0x80065224: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_80065228:
    // 0x80065228: addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // 0x8006522C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80065230: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x80065234: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x80065238: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x8006523C: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80065240: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80065244: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80065248: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8006524C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80065250: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80065254: jr          $ra
    // 0x80065258: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80065258: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8006525C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006525C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065260: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80065264: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80065268: lui         $v1, 0xB00
    ctx->r3 = S32(0XB00 << 16);
    // 0x8006526C: ori         $v1, $v1, 0x20
    ctx->r3 = ctx->r3 | 0X20;
    // 0x80065270: addiu       $a0, $s1, 0x8
    ctx->r4 = ADD32(ctx->r17, 0X8);
    // 0x80065274: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80065278: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x8006527C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80065280: lui         $v0, 0x800
    ctx->r2 = S32(0X800 << 16);
    // 0x80065284: or          $v0, $a1, $v0
    ctx->r2 = ctx->r5 | ctx->r2;
    // 0x80065288: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8006528C: sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6 << 1);
    // 0x80065290: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80065294: or          $a1, $a1, $a2
    ctx->r5 = ctx->r5 | ctx->r6;
    // 0x80065298: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8006529C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800652A0: sw          $a1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r5;
    // 0x800652A4: jal         0x80062180
    // 0x800652A8: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800652A8: sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    after_0:
    // 0x800652AC: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x800652B0: lbu         $v0, 0x2F($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2F);
    // 0x800652B4: lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2);
    // 0x800652B8: lui         $a0, 0xE00
    ctx->r4 = S32(0XE00 << 16);
    // 0x800652BC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800652C0: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x800652C4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800652C8: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x800652CC: jal         0x80062180
    // 0x800652D0: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800652D0: lw          $a0, 0x28($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X28);
    after_1:
    // 0x800652D4: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800652D8: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x800652DC: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x800652E0: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x800652E4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800652E8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800652EC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800652F0: jr          $ra
    // 0x800652F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800652F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800652F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800652F8: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800652FC: mtc1        $a1, $f2
    ctx->f2.u32l = ctx->r5;
    // 0x80065300: nop

    // 0x80065304: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80065308: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006530C: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80065310: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80065314: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80065318: ldc1        $f0, -0xD58($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0XD58);
    // 0x8006531C: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80065320: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x80065324: nop

    // 0x80065328: nop

    // 0x8006532C: bc1f        L_80065344
    if (!c1cs) {
        // 0x80065330: swc1        $f2, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
            goto L_80065344;
    }
    // 0x80065330: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
    // 0x80065334: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80065338: ldc1        $f0, -0xD50($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0XD50);
    // 0x8006533C: sub.d       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f4.d - ctx->f0.d;
    // 0x80065340: cvt.s.d     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.fl = CVT_S_D(ctx->f0.d);
L_80065344:
    // 0x80065344: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80065348: nop

    // 0x8006534C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80065350: mov.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.fl = ctx->f2.fl;
    // 0x80065354: nop

    // 0x80065358: bc1f        L_80065364
    if (!c1cs) {
        // 0x8006535C: swc1        $f2, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
            goto L_80065364;
    }
    // 0x8006535C: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
    // 0x80065360: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
L_80065364:
    // 0x80065364: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80065368: ldc1        $f0, -0xD48($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0XD48);
    // 0x8006536C: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x80065370: sub.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d - ctx->f0.d;
    // 0x80065374: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80065378: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8006537C: jr          $ra
    // 0x80065380: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    return;
    // 0x80065380: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
;}
RECOMP_FUNC void func_80065390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065390: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80065394: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80065398: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x8006539C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800653A0: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x800653A4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800653A8: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x800653AC: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800653B0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800653B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800653B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800653BC: lw          $s1, 0x0($s5)
    ctx->r17 = MEM_W(ctx->r21, 0X0);
    // 0x800653C0: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800653C4: bne         $s1, $zero, L_800653E4
    if (ctx->r17 != 0) {
        // 0x800653C8: addu        $s4, $a3, $zero
        ctx->r20 = ADD32(ctx->r7, 0);
            goto L_800653E4;
    }
    // 0x800653C8: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x800653CC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800653D0: addiu       $a0, $a0, -0xD40
    ctx->r4 = ADD32(ctx->r4, -0XD40);
    // 0x800653D4: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800653D8: addiu       $a1, $a1, -0xD3C
    ctx->r5 = ADD32(ctx->r5, -0XD3C);
    // 0x800653DC: jal         0x800621E0
    // 0x800653E0: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    func_800621E0(rdram, ctx);
        goto after_0;
    // 0x800653E0: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    after_0:
L_800653E4:
    // 0x800653E4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800653E8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800653EC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800653F0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x800653F4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x800653F8: jalr        $v0
    // 0x800653FC: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x800653FC: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_1:
    // 0x80065400: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80065404: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80065408: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8006540C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80065410: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80065414: lui         $a3, 0x440
    ctx->r7 = S32(0X440 << 16);
    // 0x80065418: ori         $a3, $a3, 0x580
    ctx->r7 = ctx->r7 | 0X580;
    // 0x8006541C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80065420: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80065424: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x80065428: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x8006542C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80065430: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x80065434: lui         $v0, 0xD00
    ctx->r2 = S32(0XD00 << 16);
    // 0x80065438: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8006543C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80065440: sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18 << 2);
    // 0x80065444: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80065448: sw          $a3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r7;
    // 0x8006544C: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x80065450: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x80065454: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x80065458: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x8006545C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80065460: lw          $a0, 0x14($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X14);
    // 0x80065464: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80065468: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x8006546C: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80065470: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80065474: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80065478: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006547C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80065480: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80065484: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80065488: jr          $ra
    // 0x8006548C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006548C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80065490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065490: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80065494: beq         $a1, $v0, L_800654AC
    if (ctx->r5 == ctx->r2) {
        // 0x80065498: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_800654AC;
    }
    // 0x80065498: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8006549C: beql        $a1, $v0, L_800654B0
    if (ctx->r5 == ctx->r2) {
        // 0x800654A0: sw          $a2, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r6;
            goto L_800654B0;
    }
    goto skip_0;
    // 0x800654A0: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
    skip_0:
    // 0x800654A4: j           L_800654B0
    // 0x800654A8: nop

        goto L_800654B0;
    // 0x800654A8: nop

L_800654AC:
    // 0x800654AC: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
L_800654B0:
    // 0x800654B0: jr          $ra
    // 0x800654B4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800654B4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_800654C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800654C0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800654C4: lw          $v0, 0x6E40($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E40);
    // 0x800654C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800654CC: bne         $v0, $zero, L_800654E0
    if (ctx->r2 != 0) {
        // 0x800654D0: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_800654E0;
    }
    // 0x800654D0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800654D4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800654D8: jal         0x80065640
    // 0x800654DC: sw          $a0, 0x6E40($at)
    MEM_W(0X6E40, ctx->r1) = ctx->r4;
    func_80065640(rdram, ctx);
        goto after_0;
    // 0x800654DC: sw          $a0, 0x6E40($at)
    MEM_W(0X6E40, ctx->r1) = ctx->r4;
    after_0:
L_800654E0:
    // 0x800654E0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800654E4: jr          $ra
    // 0x800654E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800654E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800654EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800654EC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800654F0: lw          $v0, 0x6E40($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E40);
    // 0x800654F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800654F8: beq         $v0, $zero, L_80065510
    if (ctx->r2 == 0) {
        // 0x800654FC: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80065510;
    }
    // 0x800654FC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80065500: jal         0x80065CD0
    // 0x80065504: nop

    func_80065CD0(rdram, ctx);
        goto after_0;
    // 0x80065504: nop

    after_0:
    // 0x80065508: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8006550C: sw          $zero, 0x6E40($at)
    MEM_W(0X6E40, ctx->r1) = 0;
L_80065510:
    // 0x80065510: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80065514: jr          $ra
    // 0x80065518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80065518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8006551C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006551C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80065520: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x80065524: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80065528: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8006552C: bnel        $v0, $zero, L_80065534
    if (ctx->r2 != 0) {
        // 0x80065530: sw          $a0, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r4;
            goto L_80065534;
    }
    goto skip_0;
    // 0x80065530: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    skip_0:
L_80065534:
    // 0x80065534: jr          $ra
    // 0x80065538: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    return;
    // 0x80065538: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
;}
RECOMP_FUNC void func_8006553C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006553C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80065540: beq         $v1, $zero, L_80065550
    if (ctx->r3 == 0) {
        // 0x80065544: nop
    
            goto L_80065550;
    }
    // 0x80065544: nop

    // 0x80065548: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8006554C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80065550:
    // 0x80065550: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80065554: beq         $v1, $zero, L_80065564
    if (ctx->r3 == 0) {
        // 0x80065558: nop
    
            goto L_80065564;
    }
    // 0x80065558: nop

    // 0x8006555C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80065560: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80065564:
    // 0x80065564: jr          $ra
    // 0x80065568: nop

    return;
    // 0x80065568: nop

;}
RECOMP_FUNC void func_80065570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065570: andi        $v1, $a1, 0xF
    ctx->r3 = ctx->r5 & 0XF;
    // 0x80065574: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80065578: subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
    // 0x8006557C: beq         $v1, $v0, L_8006558C
    if (ctx->r3 == ctx->r2) {
        // 0x80065580: addu        $v0, $a1, $v1
        ctx->r2 = ADD32(ctx->r5, ctx->r3);
            goto L_8006558C;
    }
    // 0x80065580: addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
    // 0x80065584: j           L_80065590
    // 0x80065588: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_80065590;
    // 0x80065588: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_8006558C:
    // 0x8006558C: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_80065590:
    // 0x80065590: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80065594: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x80065598: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8006559C: jr          $ra
    // 0x800655A0: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    return;
    // 0x800655A0: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_800655B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800655B0: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x800655B4: mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800655B8: mflo        $a3
    ctx->r7 = lo;
    // 0x800655BC: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x800655C0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800655C4: addiu       $a0, $zero, -0x10
    ctx->r4 = ADD32(0, -0X10);
    // 0x800655C8: lw          $a1, 0x4($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X4);
    // 0x800655CC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800655D0: addiu       $a3, $a3, 0xF
    ctx->r7 = ADD32(ctx->r7, 0XF);
    // 0x800655D4: and         $a3, $a3, $a0
    ctx->r7 = ctx->r7 & ctx->r4;
    // 0x800655D8: addu        $a0, $a1, $a3
    ctx->r4 = ADD32(ctx->r5, ctx->r7);
    // 0x800655DC: sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x800655E0: bne         $v0, $zero, L_800655F0
    if (ctx->r2 != 0) {
        // 0x800655E4: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_800655F0;
    }
    // 0x800655E4: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x800655E8: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x800655EC: sw          $a0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r4;
L_800655F0:
    // 0x800655F0: jr          $ra
    // 0x800655F4: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    return;
    // 0x800655F4: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
;}
RECOMP_FUNC void func_80065600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065600: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80065604: blez        $a2, L_80065628
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80065608: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80065628;
    }
    // 0x80065608: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8006560C:
    // 0x8006560C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80065610: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80065614: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80065618: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x8006561C: slt         $v0, $v1, $a2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80065620: bne         $v0, $zero, L_8006560C
    if (ctx->r2 != 0) {
        // 0x80065624: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8006560C;
    }
    // 0x80065624: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80065628:
    // 0x80065628: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8006562C: jr          $ra
    // 0x80065630: nop

    return;
    // 0x80065630: nop

;}
RECOMP_FUNC void func_80065640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065640: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80065644: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80065648: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x8006564C: sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // 0x80065650: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80065654: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80065658: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8006565C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80065660: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80065664: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80065668: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8006566C: lw          $s6, 0x14($s5)
    ctx->r22 = MEM_W(ctx->r21, 0X14);
    // 0x80065670: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x80065674: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
    // 0x80065678: lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X4);
    // 0x8006567C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80065680: sw          $zero, 0x20($s4)
    MEM_W(0X20, ctx->r20) = 0;
    // 0x80065684: sw          $zero, 0x1C($s4)
    MEM_W(0X1C, ctx->r20) = 0;
    // 0x80065688: sw          $v0, 0x3C($s4)
    MEM_W(0X3C, ctx->r20) = ctx->r2;
    // 0x8006568C: lw          $v1, 0x18($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X18);
    // 0x80065690: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80065694: addiu       $v0, $zero, 0xA0
    ctx->r2 = ADD32(0, 0XA0);
    // 0x80065698: sw          $v0, 0x48($s4)
    MEM_W(0X48, ctx->r20) = ctx->r2;
    // 0x8006569C: sw          $v1, 0x44($s4)
    MEM_W(0X44, ctx->r20) = ctx->r3;
    // 0x800656A0: lw          $v0, 0x10($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X10);
    // 0x800656A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800656A8: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    // 0x800656AC: sw          $v0, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->r2;
    // 0x800656B0: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // 0x800656B4: jal         0x800655B0
    // 0x800656B8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800655B0(rdram, ctx);
        goto after_0;
    // 0x800656B8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x800656BC: addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
    // 0x800656C0: jal         0x800629D8
    // 0x800656C4: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    func_800629D8(rdram, ctx);
        goto after_1;
    // 0x800656C4: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    after_1:
    // 0x800656C8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800656CC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800656D0: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    // 0x800656D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800656D8: addiu       $v0, $zero, 0x4C
    ctx->r2 = ADD32(0, 0X4C);
    // 0x800656DC: sw          $s7, 0x38($s4)
    MEM_W(0X38, ctx->r20) = ctx->r23;
    // 0x800656E0: jal         0x800655B0
    // 0x800656E4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800655B0(rdram, ctx);
        goto after_2;
    // 0x800656E4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x800656E8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800656EC: sw          $v0, 0x34($s4)
    MEM_W(0X34, ctx->r20) = ctx->r2;
    // 0x800656F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800656F4: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x800656F8: sw          $v0, 0x40($s4)
    MEM_W(0X40, ctx->r20) = ctx->r2;
    // 0x800656FC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80065700: lw          $a3, 0x4($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X4);
    // 0x80065704: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80065708: jal         0x800655B0
    // 0x8006570C: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    func_800655B0(rdram, ctx);
        goto after_3;
    // 0x8006570C: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    after_3:
    // 0x80065710: lw          $a0, 0x34($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X34);
    // 0x80065714: lw          $a2, 0x4($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X4);
    // 0x80065718: jal         0x80062920
    // 0x8006571C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_80062920(rdram, ctx);
        goto after_4;
    // 0x8006571C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_4:
    // 0x80065720: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80065724: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80065728: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    // 0x8006572C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80065730: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x80065734: jal         0x800655B0
    // 0x80065738: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800655B0(rdram, ctx);
        goto after_5;
    // 0x80065738: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_5:
    // 0x8006573C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80065740: sw          $v0, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->r2;
    // 0x80065744: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80065748: lw          $a3, 0x4($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X4);
    // 0x8006574C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80065750: jal         0x800655B0
    // 0x80065754: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    func_800655B0(rdram, ctx);
        goto after_6;
    // 0x80065754: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    after_6:
    // 0x80065758: lw          $a0, 0x30($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X30);
    // 0x8006575C: lw          $a2, 0x4($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X4);
    // 0x80065760: jal         0x8006297C
    // 0x80065764: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_8006297C(rdram, ctx);
        goto after_7;
    // 0x80065764: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_7:
    // 0x80065768: lbu         $v0, 0x1C($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X1C);
    // 0x8006576C: beq         $v0, $zero, L_8006578C
    if (ctx->r2 == 0) {
        // 0x80065770: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_8006578C;
    }
    // 0x80065770: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80065774: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80065778: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x8006577C: jal         0x80065CE0
    // 0x80065780: addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    func_80065CE0(rdram, ctx);
        goto after_8;
    // 0x80065780: addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    after_8:
    // 0x80065784: j           L_800657A0
    // 0x80065788: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
        goto L_800657A0;
    // 0x80065788: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8006578C:
    // 0x8006578C: lw          $a0, 0x30($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X30);
    // 0x80065790: lw          $a2, 0x34($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X34);
    // 0x80065794: jal         0x800644D0
    // 0x80065798: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800644D0(rdram, ctx);
        goto after_9;
    // 0x80065798: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x8006579C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800657A0:
    // 0x800657A0: addiu       $v0, $zero, 0xDC
    ctx->r2 = ADD32(0, 0XDC);
    // 0x800657A4: sw          $zero, 0x4($s4)
    MEM_W(0X4, ctx->r20) = 0;
    // 0x800657A8: sw          $zero, 0x8($s4)
    MEM_W(0X8, ctx->r20) = 0;
    // 0x800657AC: sw          $zero, 0x14($s4)
    MEM_W(0X14, ctx->r20) = 0;
    // 0x800657B0: sw          $zero, 0x18($s4)
    MEM_W(0X18, ctx->r20) = 0;
    // 0x800657B4: sw          $zero, 0xC($s4)
    MEM_W(0XC, ctx->r20) = 0;
    // 0x800657B8: sw          $zero, 0x10($s4)
    MEM_W(0X10, ctx->r20) = 0;
    // 0x800657BC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800657C0: lw          $a3, 0x4($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X4);
    // 0x800657C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800657C8: jal         0x800655B0
    // 0x800657CC: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    func_800655B0(rdram, ctx);
        goto after_10;
    // 0x800657CC: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    after_10:
    // 0x800657D0: lw          $v1, 0x4($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X4);
    // 0x800657D4: blez        $v1, L_8006587C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800657D8: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_8006587C;
    }
    // 0x800657D8: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800657DC: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
L_800657E0:
    // 0x800657E0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800657E4: jal         0x8006551C
    // 0x800657E8: addiu       $a1, $s4, 0x4
    ctx->r5 = ADD32(ctx->r20, 0X4);
    func_8006551C(rdram, ctx);
        goto after_11;
    // 0x800657E8: addiu       $a1, $s4, 0x4
    ctx->r5 = ADD32(ctx->r20, 0X4);
    after_11:
    // 0x800657EC: sw          $zero, 0x8($s2)
    MEM_W(0X8, ctx->r18) = 0;
    // 0x800657F0: lw          $a1, 0x24($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X24);
    // 0x800657F4: addiu       $s0, $s2, 0x10
    ctx->r16 = ADD32(ctx->r18, 0X10);
    // 0x800657F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800657FC: jal         0x800627E4
    // 0x80065800: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    func_800627E4(rdram, ctx);
        goto after_12;
    // 0x80065800: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    after_12:
    // 0x80065804: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80065808: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8006580C: jal         0x80063200
    // 0x80065810: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80063200(rdram, ctx);
        goto after_13;
    // 0x80065810: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_13:
    // 0x80065814: addiu       $s1, $s2, 0x58
    ctx->r17 = ADD32(ctx->r18, 0X58);
    // 0x80065818: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8006581C: jal         0x80062894
    // 0x80065820: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    func_80062894(rdram, ctx);
        goto after_14;
    // 0x80065820: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_14:
    // 0x80065824: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80065828: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8006582C: jal         0x800646EC
    // 0x80065830: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_800646EC(rdram, ctx);
        goto after_15;
    // 0x80065830: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_15:
    // 0x80065834: addiu       $s0, $s2, 0x8C
    ctx->r16 = ADD32(ctx->r18, 0X8C);
    // 0x80065838: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006583C: jal         0x8006272C
    // 0x80065840: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    func_8006272C(rdram, ctx);
        goto after_16;
    // 0x80065840: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_16:
    // 0x80065844: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80065848: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8006584C: jal         0x80063B8C
    // 0x80065850: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_80063B8C(rdram, ctx);
        goto after_17;
    // 0x80065850: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_17:
    // 0x80065854: lw          $a0, 0x34($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X34);
    // 0x80065858: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8006585C: jal         0x8006360C
    // 0x80065860: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_8006360C(rdram, ctx);
        goto after_18;
    // 0x80065860: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_18:
    // 0x80065864: sw          $s0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r16;
    // 0x80065868: lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X4);
    // 0x8006586C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80065870: slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80065874: bne         $v0, $zero, L_800657E0
    if (ctx->r2 != 0) {
        // 0x80065878: addiu       $s2, $s2, 0xDC
        ctx->r18 = ADD32(ctx->r18, 0XDC);
            goto L_800657E0;
    }
    // 0x80065878: addiu       $s2, $s2, 0xDC
    ctx->r18 = ADD32(ctx->r18, 0XDC);
L_8006587C:
    // 0x8006587C: lw          $a2, 0x30($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X30);
    // 0x80065880: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x80065884: jal         0x80065490
    // 0x80065888: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80065490(rdram, ctx);
        goto after_19;
    // 0x80065888: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x8006588C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80065890: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // 0x80065894: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80065898: lw          $a3, 0x8($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X8);
    // 0x8006589C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800658A0: jal         0x800655B0
    // 0x800658A4: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    func_800655B0(rdram, ctx);
        goto after_20;
    // 0x800658A4: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    after_20:
    // 0x800658A8: sw          $zero, 0x2C($s4)
    MEM_W(0X2C, ctx->r20) = 0;
    // 0x800658AC: lw          $v1, 0x8($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X8);
    // 0x800658B0: blez        $v1, L_800658DC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800658B4: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_800658DC;
    }
    // 0x800658B4: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800658B8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_800658BC:
    // 0x800658BC: lw          $v0, 0x2C($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X2C);
    // 0x800658C0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800658C4: sw          $v1, 0x2C($s4)
    MEM_W(0X2C, ctx->r20) = ctx->r3;
    // 0x800658C8: lw          $v0, 0x8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X8);
    // 0x800658CC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800658D0: slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800658D4: bne         $v0, $zero, L_800658BC
    if (ctx->r2 != 0) {
        // 0x800658D8: addiu       $v1, $v1, 0x1C
        ctx->r3 = ADD32(ctx->r3, 0X1C);
            goto L_800658BC;
    }
    // 0x800658D8: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
L_800658DC:
    // 0x800658DC: sw          $s6, 0x28($s4)
    MEM_W(0X28, ctx->r20) = ctx->r22;
    // 0x800658E0: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x800658E4: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800658E8: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800658EC: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800658F0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800658F4: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800658F8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800658FC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80065900: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80065904: jr          $ra
    // 0x80065908: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80065908: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8006590C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006590C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80065910: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80065914: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x80065918: lw          $s2, 0x6E40($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X6E40);
    // 0x8006591C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80065920: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x80065924: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80065928: addu        $fp, $a1, $zero
    ctx->r30 = ADD32(ctx->r5, 0);
    // 0x8006592C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80065930: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // 0x80065934: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80065938: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8006593C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80065940: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80065944: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80065948: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006594C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80065950: addu        $s4, $s7, $zero
    ctx->r20 = ADD32(ctx->r23, 0);
    // 0x80065954: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x80065958: bne         $v0, $zero, L_80065968
    if (ctx->r2 != 0) {
        // 0x8006595C: sh          $zero, 0x1C($sp)
        MEM_H(0X1C, ctx->r29) = 0;
            goto L_80065968;
    }
    // 0x8006595C: sh          $zero, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = 0;
    // 0x80065960: j           L_80065A88
    // 0x80065964: sw          $zero, 0x0($fp)
    MEM_W(0X0, ctx->r30) = 0;
        goto L_80065A88;
    // 0x80065964: sw          $zero, 0x0($fp)
    MEM_W(0X0, ctx->r30) = 0;
L_80065968:
    // 0x80065968: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8006596C: jal         0x80065C28
    // 0x80065970: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_80065C28(rdram, ctx);
        goto after_0;
    // 0x80065970: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80065974: lw          $v1, 0x20($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X20);
    // 0x80065978: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x8006597C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80065980: slt         $v0, $v0, $s3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80065984: beq         $v0, $zero, L_800659EC
    if (ctx->r2 == 0) {
        // 0x80065988: nop
    
            goto L_800659EC;
    }
    // 0x80065988: nop

    // 0x8006598C: addiu       $s0, $zero, -0x10
    ctx->r16 = ADD32(0, -0X10);
L_80065990:
    // 0x80065990: lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1C);
    // 0x80065994: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80065998: and         $v0, $v0, $s0
    ctx->r2 = ctx->r2 & ctx->r16;
    // 0x8006599C: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x800659A0: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x800659A4: jalr        $v0
    // 0x800659A8: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x800659A8: nop

    after_1:
    // 0x800659AC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800659B0: jal         0x80065B94
    // 0x800659B4: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_80065B94(rdram, ctx);
        goto after_2;
    // 0x800659B4: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_2:
    // 0x800659B8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800659BC: lw          $v1, 0x10($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X10);
    // 0x800659C0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800659C4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800659C8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800659CC: jal         0x80065C28
    // 0x800659D0: sw          $v1, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r3;
    func_80065C28(rdram, ctx);
        goto after_3;
    // 0x800659D0: sw          $v1, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r3;
    after_3:
    // 0x800659D4: lw          $v1, 0x20($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X20);
    // 0x800659D8: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x800659DC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800659E0: slt         $v0, $v0, $s3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800659E4: bne         $v0, $zero, L_80065990
    if (ctx->r2 != 0) {
        // 0x800659E8: nop
    
            goto L_80065990;
    }
    // 0x800659E8: nop

L_800659EC:
    // 0x800659EC: lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1C);
    // 0x800659F0: addiu       $v1, $zero, -0x10
    ctx->r3 = ADD32(0, -0X10);
    // 0x800659F4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800659F8: blez        $s3, L_80065A74
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800659FC: sw          $v0, 0x1C($s2)
        MEM_W(0X1C, ctx->r18) = ctx->r2;
            goto L_80065A74;
    }
    // 0x800659FC: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x80065A00: lui         $s6, 0x700
    ctx->r22 = S32(0X700 << 16);
L_80065A04:
    // 0x80065A04: lw          $s1, 0x48($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X48);
    // 0x80065A08: slt         $v0, $s3, $s1
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80065A0C: bnel        $v0, $zero, L_80065A14
    if (ctx->r2 != 0) {
        // 0x80065A10: addu        $s1, $s3, $zero
        ctx->r17 = ADD32(ctx->r19, 0);
            goto L_80065A14;
    }
    goto skip_0;
    // 0x80065A10: addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
    skip_0:
L_80065A14:
    // 0x80065A14: sw          $s6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r22;
    // 0x80065A18: sw          $zero, 0x4($s4)
    MEM_W(0X4, ctx->r20) = 0;
    // 0x80065A1C: lw          $s0, 0x38($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X38);
    // 0x80065A20: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80065A24: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x80065A28: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80065A2C: subu        $s3, $s3, $s1
    ctx->r19 = SUB32(ctx->r19, ctx->r17);
    // 0x80065A30: jalr        $v0
    // 0x80065A34: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x80065A34: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x80065A38: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80065A3C: addiu       $v0, $s4, 0x8
    ctx->r2 = ADD32(ctx->r20, 0X8);
    // 0x80065A40: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80065A44: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80065A48: lw          $a3, 0x20($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X20);
    // 0x80065A4C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80065A50: jalr        $v0
    // 0x80065A54: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_5;
    // 0x80065A54: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_5:
    // 0x80065A58: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x80065A5C: lw          $v1, 0x20($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X20);
    // 0x80065A60: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x80065A64: addu        $s5, $s5, $v0
    ctx->r21 = ADD32(ctx->r21, ctx->r2);
    // 0x80065A68: addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // 0x80065A6C: bgtz        $s3, L_80065A04
    if (SIGNED(ctx->r19) > 0) {
        // 0x80065A70: sw          $v1, 0x20($s2)
        MEM_W(0X20, ctx->r18) = ctx->r3;
            goto L_80065A04;
    }
    // 0x80065A70: sw          $v1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r3;
L_80065A74:
    // 0x80065A74: subu        $v0, $s4, $s7
    ctx->r2 = SUB32(ctx->r20, ctx->r23);
    // 0x80065A78: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80065A7C: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x80065A80: jal         0x80065B00
    // 0x80065A84: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80065B00(rdram, ctx);
        goto after_6;
    // 0x80065A84: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_6:
L_80065A88:
    // 0x80065A88: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // 0x80065A8C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80065A90: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80065A94: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80065A98: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80065A9C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80065AA0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80065AA4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80065AA8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80065AAC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80065AB0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80065AB4: jr          $ra
    // 0x80065AB8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80065AB8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80065ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065ABC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80065AC0: lw          $a0, 0x6E40($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6E40);
    // 0x80065AC4: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x80065AC8: beq         $v0, $zero, L_80065AE0
    if (ctx->r2 == 0) {
        // 0x80065ACC: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80065AE0;
    }
    // 0x80065ACC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80065AD0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80065AD4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80065AD8: sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
    // 0x80065ADC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80065AE0:
    // 0x80065AE0: jr          $ra
    // 0x80065AE4: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    return;
    // 0x80065AE4: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
;}
RECOMP_FUNC void func_80065AE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065AE8: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80065AEC: lw          $v1, 0x6E40($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6E40);
    // 0x80065AF0: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x80065AF4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80065AF8: jr          $ra
    // 0x80065AFC: sw          $a0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r4;
    return;
    // 0x80065AFC: sw          $a0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r4;
;}
RECOMP_FUNC void func_80065B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065B00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065B04: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80065B08: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80065B0C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80065B10: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80065B14: lw          $s0, 0x14($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X14);
    // 0x80065B18: beq         $s0, $zero, L_80065B40
    if (ctx->r16 == 0) {
        // 0x80065B1C: nop
    
            goto L_80065B40;
    }
    // 0x80065B1C: nop

L_80065B20:
    // 0x80065B20: jal         0x8006553C
    // 0x80065B24: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8006553C(rdram, ctx);
        goto after_0;
    // 0x80065B24: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80065B28: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80065B2C: jal         0x8006551C
    // 0x80065B30: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    func_8006551C(rdram, ctx);
        goto after_1;
    // 0x80065B30: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    after_1:
    // 0x80065B34: lw          $s0, 0x14($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X14);
    // 0x80065B38: bne         $s0, $zero, L_80065B20
    if (ctx->r16 != 0) {
        // 0x80065B3C: nop
    
            goto L_80065B20;
    }
    // 0x80065B3C: nop

L_80065B40:
    // 0x80065B40: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80065B44: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80065B48: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80065B4C: jr          $ra
    // 0x80065B50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80065B50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80065B54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065B54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065B58: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80065B5C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80065B60: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80065B64: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80065B68: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80065B6C: jal         0x8006553C
    // 0x80065B70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8006553C(rdram, ctx);
        goto after_0;
    // 0x80065B70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80065B74: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80065B78: jal         0x8006551C
    // 0x80065B7C: addiu       $a1, $s1, 0x14
    ctx->r5 = ADD32(ctx->r17, 0X14);
    func_8006551C(rdram, ctx);
        goto after_1;
    // 0x80065B7C: addiu       $a1, $s1, 0x14
    ctx->r5 = ADD32(ctx->r17, 0X14);
    after_1:
    // 0x80065B80: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80065B84: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80065B88: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80065B8C: jr          $ra
    // 0x80065B90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80065B90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80065B94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065B94: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x80065B98: nop

    // 0x80065B9C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80065BA0: lwc1        $f2, 0x44($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80065BA4: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80065BA8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80065BAC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80065BB0: ldc1        $f2, -0xD30($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0XD30);
    // 0x80065BB4: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80065BB8: div.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x80065BBC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80065BC0: ldc1        $f2, -0xD28($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0XD28);
    // 0x80065BC4: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x80065BC8: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x80065BCC: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80065BD0: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80065BD4: jr          $ra
    // 0x80065BD8: nop

    return;
    // 0x80065BD8: nop

;}
RECOMP_FUNC void func_80065BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065BDC: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x80065BE0: nop

    // 0x80065BE4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80065BE8: lwc1        $f2, 0x44($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80065BEC: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80065BF0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80065BF4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80065BF8: ldc1        $f2, -0xD20($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0XD20);
    // 0x80065BFC: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80065C00: div.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f2.d);
    // 0x80065C04: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80065C08: ldc1        $f2, -0xD18($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0XD18);
    // 0x80065C0C: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x80065C10: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x80065C14: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80065C18: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x80065C1C: addiu       $v0, $zero, -0x10
    ctx->r2 = ADD32(0, -0X10);
    // 0x80065C20: jr          $ra
    // 0x80065C24: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    return;
    // 0x80065C24: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
;}
RECOMP_FUNC void func_80065C28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065C28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065C2C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80065C30: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80065C34: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80065C38: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80065C3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80065C40: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80065C44: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80065C48: lui         $s1, 0x7FFF
    ctx->r17 = S32(0X7FFF << 16);
    // 0x80065C4C: bne         $v0, $zero, L_80065C6C
    if (ctx->r2 != 0) {
        // 0x80065C50: ori         $s1, $s1, 0xFFFF
        ctx->r17 = ctx->r17 | 0XFFFF;
            goto L_80065C6C;
    }
    // 0x80065C50: ori         $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 | 0XFFFF;
    // 0x80065C54: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80065C58: addiu       $a0, $a0, -0xD10
    ctx->r4 = ADD32(ctx->r4, -0XD10);
    // 0x80065C5C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80065C60: addiu       $a1, $a1, -0xD0C
    ctx->r5 = ADD32(ctx->r5, -0XD0C);
    // 0x80065C64: jal         0x800621E0
    // 0x80065C68: addiu       $a2, $zero, 0x133
    ctx->r6 = ADD32(0, 0X133);
    func_800621E0(rdram, ctx);
        goto after_0;
    // 0x80065C68: addiu       $a2, $zero, 0x133
    ctx->r6 = ADD32(0, 0X133);
    after_0:
L_80065C6C:
    // 0x80065C6C: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x80065C70: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80065C74: beq         $a0, $zero, L_80065CB0
    if (ctx->r4 == 0) {
        // 0x80065C78: nop
    
            goto L_80065CB0;
    }
    // 0x80065C78: nop

L_80065C7C:
    // 0x80065C7C: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80065C80: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x80065C84: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80065C88: slt         $v0, $v0, $s1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80065C8C: beq         $v0, $zero, L_80065CA4
    if (ctx->r2 == 0) {
        // 0x80065C90: nop
    
            goto L_80065CA4;
    }
    // 0x80065C90: nop

    // 0x80065C94: sw          $a0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r4;
    // 0x80065C98: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80065C9C: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x80065CA0: subu        $s1, $v1, $v0
    ctx->r17 = SUB32(ctx->r3, ctx->r2);
L_80065CA4:
    // 0x80065CA4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80065CA8: bne         $a0, $zero, L_80065C7C
    if (ctx->r4 != 0) {
        // 0x80065CAC: nop
    
            goto L_80065C7C;
    }
    // 0x80065CAC: nop

L_80065CB0:
    // 0x80065CB0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80065CB4: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x80065CB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80065CBC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80065CC0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80065CC4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80065CC8: jr          $ra
    // 0x80065CCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80065CCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80065CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065CD0: jr          $ra
    // 0x80065CD4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    return;
    // 0x80065CD4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80065CE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065CE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065CE4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80065CE8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80065CEC: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x80065CF0: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x80065CF4: addu        $a2, $a3, $zero
    ctx->r6 = ADD32(ctx->r7, 0);
    // 0x80065CF8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80065CFC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80065D00: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x80065D04: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80065D08: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x80065D0C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80065D10: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x80065D14: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x80065D18: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x80065D1C: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x80065D20: jal         0x80062294
    // 0x80065D24: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    func_80062294(rdram, ctx);
        goto after_0;
    // 0x80065D24: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_0:
    // 0x80065D28: lw          $a2, 0x34($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X34);
    // 0x80065D2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80065D30: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x80065D34: jal         0x80064B60
    // 0x80065D38: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    func_80064B60(rdram, ctx);
        goto after_1;
    // 0x80065D38: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    after_1:
    // 0x80065D3C: lw          $a2, 0x34($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X34);
    // 0x80065D40: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x80065D44: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80065D48: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x80065D4C: jal         0x800644D0
    // 0x80065D50: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    func_800644D0(rdram, ctx);
        goto after_2;
    // 0x80065D50: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    after_2:
    // 0x80065D54: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x80065D58: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80065D5C: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80065D60: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80065D64: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80065D68: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80065D6C: jr          $ra
    // 0x80065D70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80065D70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
