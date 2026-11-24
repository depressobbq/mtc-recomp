#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800566C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800566C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800566C8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800566CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800566D0: jal         0x800568F4
    // 0x800566D4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_800568F4(rdram, ctx);
        goto after_0;
    // 0x800566D4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x800566D8: jal         0x80056870
    // 0x800566DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80056870(rdram, ctx);
        goto after_1;
    // 0x800566DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800566E0: jal         0x80056804
    // 0x800566E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80056804(rdram, ctx);
        goto after_2;
    // 0x800566E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800566E8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800566EC: addiu       $v1, $v1, -0x5E0F
    ctx->r3 = ADD32(ctx->r3, -0X5E0F);
    // 0x800566F0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800566F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800566F8: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800566FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80056700: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80056704: jr          $ra
    // 0x80056708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80056708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005670C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005670C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80056710: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80056714: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056718: jal         0x8005688C
    // 0x8005671C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_8005688C(rdram, ctx);
        goto after_0;
    // 0x8005671C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80056720: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80056724: bne         $v0, $v1, L_80056748
    if (ctx->r2 != ctx->r3) {
        // 0x80056728: nop
    
            goto L_80056748;
    }
    // 0x80056728: nop

    // 0x8005672C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80056730: addiu       $v0, $v0, -0x5E0F
    ctx->r2 = ADD32(ctx->r2, -0X5E0F);
    // 0x80056734: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80056738: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005673C: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x80056740: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x80056744: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
L_80056748:
    // 0x80056748: jal         0x80056804
    // 0x8005674C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80056804(rdram, ctx);
        goto after_1;
    // 0x8005674C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80056750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80056754: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80056758: jr          $ra
    // 0x8005675C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005675C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80056760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80056764: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80056768: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8005676C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056770: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80056774: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80056778: bne         $v0, $zero, L_80056798
    if (ctx->r2 != 0) {
        // 0x8005677C: sw          $v0, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->r2;
            goto L_80056798;
    }
    // 0x8005677C: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80056780: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80056784: addiu       $v1, $v1, -0x5E0F
    ctx->r3 = ADD32(ctx->r3, -0X5E0F);
    // 0x80056788: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8005678C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80056790: jal         0x80056858
    // 0x80056794: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    func_80056858(rdram, ctx);
        goto after_0;
    // 0x80056794: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    after_0:
L_80056798:
    // 0x80056798: jal         0x80056804
    // 0x8005679C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80056804(rdram, ctx);
        goto after_1;
    // 0x8005679C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800567A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800567A4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800567A8: jr          $ra
    // 0x800567AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800567AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800567B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800567B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800567B4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800567B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800567BC: jal         0x8005688C
    // 0x800567C0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_8005688C(rdram, ctx);
        goto after_0;
    // 0x800567C0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x800567C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800567C8: bne         $v0, $v1, L_800567EC
    if (ctx->r2 != ctx->r3) {
        // 0x800567CC: nop
    
            goto L_800567EC;
    }
    // 0x800567CC: nop

    // 0x800567D0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800567D4: lbu         $v0, -0x5E10($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5E10);
    // 0x800567D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800567DC: sb          $zero, -0x5E0F($at)
    MEM_B(-0X5E0F, ctx->r1) = 0;
    // 0x800567E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800567E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800567E8: sb          $v0, -0x5E10($at)
    MEM_B(-0X5E10, ctx->r1) = ctx->r2;
L_800567EC:
    // 0x800567EC: jal         0x80056804
    // 0x800567F0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80056804(rdram, ctx);
        goto after_1;
    // 0x800567F0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800567F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800567F8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800567FC: jr          $ra
    // 0x80056800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80056800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80056804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056804: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80056808: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005680C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80056810: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80056814: jal         0x80056970
    // 0x80056818: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    func_80056970(rdram, ctx);
        goto after_0;
    // 0x80056818: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    after_0:
    // 0x8005681C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80056820: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    // 0x80056824: jal         0x80056970
    // 0x80056828: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    func_80056970(rdram, ctx);
        goto after_1;
    // 0x80056828: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    after_1:
    // 0x8005682C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80056830: addiu       $a1, $zero, 0xA8
    ctx->r5 = ADD32(0, 0XA8);
    // 0x80056834: jal         0x80056970
    // 0x80056838: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    func_80056970(rdram, ctx);
        goto after_2;
    // 0x80056838: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    after_2:
    // 0x8005683C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80056840: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x80056844: jal         0x80056970
    // 0x80056848: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    func_80056970(rdram, ctx);
        goto after_3;
    // 0x80056848: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    after_3:
    // 0x8005684C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80056850: jr          $ra
    // 0x80056854: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80056854: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80056858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056858: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005685C: sb          $v0, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r2;
    // 0x80056860: sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
    // 0x80056864: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80056868: jr          $ra
    // 0x8005686C: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    return;
    // 0x8005686C: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_80056870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056870: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80056874: sb          $v0, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r2;
    // 0x80056878: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8005687C: sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
    // 0x80056880: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80056884: jr          $ra
    // 0x80056888: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    return;
    // 0x80056888: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_8005688C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005688C: lbu         $v1, 0x5($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X5);
    // 0x80056890: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80056894: bne         $v1, $v0, L_800568BC
    if (ctx->r3 != ctx->r2) {
        // 0x80056898: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800568BC;
    }
    // 0x80056898: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005689C: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800568A0: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x800568A4: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x800568A8: slti        $v0, $v0, 0xFF
    ctx->r2 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x800568AC: bne         $v0, $zero, L_800568EC
    if (ctx->r2 != 0) {
        // 0x800568B0: nop
    
            goto L_800568EC;
    }
    // 0x800568B0: nop

    // 0x800568B4: j           L_800568E4
    // 0x800568B8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_800568E4;
    // 0x800568B8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_800568BC:
    // 0x800568BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800568C0: bne         $v1, $v0, L_800568EC
    if (ctx->r3 != ctx->r2) {
        // 0x800568C4: nop
    
            goto L_800568EC;
    }
    // 0x800568C4: nop

    // 0x800568C8: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800568CC: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x800568D0: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x800568D4: slti        $v0, $v0, 0xB
    ctx->r2 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x800568D8: beq         $v0, $zero, L_800568EC
    if (ctx->r2 == 0) {
        // 0x800568DC: nop
    
            goto L_800568EC;
    }
    // 0x800568DC: nop

    // 0x800568E0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800568E4:
    // 0x800568E4: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x800568E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800568EC:
    // 0x800568EC: jr          $ra
    // 0x800568F0: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    return;
    // 0x800568F0: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
;}
RECOMP_FUNC void func_800568F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800568F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800568F8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800568FC: lui         $s3, 0x8017
    ctx->r19 = S32(0X8017 << 16);
    // 0x80056900: addiu       $s3, $s3, 0x3A40
    ctx->r19 = ADD32(ctx->r19, 0X3A40);
    // 0x80056904: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80056908: lui         $s2, 0x6D
    ctx->r18 = S32(0X6D << 16);
    // 0x8005690C: addiu       $s2, $s2, 0x6CB0
    ctx->r18 = ADD32(ctx->r18, 0X6CB0);
    // 0x80056910: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80056914: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80056918: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005691C: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x80056920: addiu       $s0, $s0, 0x5C78
    ctx->r16 = ADD32(ctx->r16, 0X5C78);
    // 0x80056924: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
L_80056928:
    // 0x80056928: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x8005692C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80056930: jal         0x80006D98
    // 0x80056934: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_80006D98(rdram, ctx);
        goto after_0;
    // 0x80056934: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_0:
    // 0x80056938: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005693C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80056940: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80056944: addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // 0x80056948: slti        $v0, $s1, 0xE
    ctx->r2 = SIGNED(ctx->r17) < 0XE ? 1 : 0;
    // 0x8005694C: bne         $v0, $zero, L_80056928
    if (ctx->r2 != 0) {
        // 0x80056950: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80056928;
    }
    // 0x80056950: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80056954: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80056958: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8005695C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80056960: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80056964: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80056968: jr          $ra
    // 0x8005696C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005696C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80056970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056970: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80056974: addu        $t7, $a0, $zero
    ctx->r15 = ADD32(ctx->r4, 0);
    // 0x80056978: addu        $t9, $a1, $zero
    ctx->r25 = ADD32(ctx->r5, 0);
    // 0x8005697C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80056980: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x80056984: sll         $v0, $t7, 1
    ctx->r2 = S32(ctx->r15 << 1);
    // 0x80056988: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8005698C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80056990: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80056994: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80056998: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8005699C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x800569A0: lw          $t6, 0x5CAC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5CAC);
    // 0x800569A4: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x800569A8: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x800569AC: lw          $t8, 0x5CB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5CB0);
    // 0x800569B0: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x800569B4: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x800569B8: lw          $s1, 0x5CB4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X5CB4);
    // 0x800569BC: slti        $v0, $t9, 0x140
    ctx->r2 = SIGNED(ctx->r25) < 0X140 ? 1 : 0;
    // 0x800569C0: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800569C4: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x800569C8: slti        $a0, $a0, 0x1
    ctx->r4 = SIGNED(ctx->r4) < 0X1 ? 1 : 0;
    // 0x800569CC: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x800569D0: addu        $v1, $s0, $t8
    ctx->r3 = ADD32(ctx->r16, ctx->r24);
    // 0x800569D4: slti        $v1, $v1, 0x1
    ctx->r3 = SIGNED(ctx->r3) < 0X1 ? 1 : 0;
    // 0x800569D8: slti        $v0, $s0, 0xF0
    ctx->r2 = SIGNED(ctx->r16) < 0XF0 ? 1 : 0;
    // 0x800569DC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800569E0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800569E4: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x800569E8: bne         $a0, $zero, L_80056D00
    if (ctx->r4 != 0) {
        // 0x800569EC: lui         $v1, 0xBA00
        ctx->r3 = S32(0XBA00 << 16);
            goto L_80056D00;
    }
    // 0x800569EC: lui         $v1, 0xBA00
    ctx->r3 = S32(0XBA00 << 16);
    // 0x800569F0: ori         $v1, $v1, 0x1402
    ctx->r3 = ctx->r3 | 0X1402;
    // 0x800569F4: lui         $a1, 0xFCFF
    ctx->r5 = S32(0XFCFF << 16);
    // 0x800569F8: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800569FC: lui         $a0, 0xFFFC
    ctx->r4 = S32(0XFFFC << 16);
    // 0x80056A00: ori         $a0, $a0, 0xF279
    ctx->r4 = ctx->r4 | 0XF279;
    // 0x80056A04: lui         $a2, 0xBA00
    ctx->r6 = S32(0XBA00 << 16);
    // 0x80056A08: ori         $a2, $a2, 0x1301
    ctx->r6 = ctx->r6 | 0X1301;
    // 0x80056A0C: lui         $t0, 0xB900
    ctx->r8 = S32(0XB900 << 16);
    // 0x80056A10: ori         $t0, $t0, 0x31D
    ctx->r8 = ctx->r8 | 0X31D;
    // 0x80056A14: lui         $a3, 0xF0A
    ctx->r7 = S32(0XF0A << 16);
    // 0x80056A18: ori         $a3, $a3, 0x7008
    ctx->r7 = ctx->r7 | 0X7008;
    // 0x80056A1C: lui         $t1, 0xBA00
    ctx->r9 = S32(0XBA00 << 16);
    // 0x80056A20: ori         $t1, $t1, 0xE02
    ctx->r9 = ctx->r9 | 0XE02;
    // 0x80056A24: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x80056A28: ori         $t3, $t3, 0x100
    ctx->r11 = ctx->r11 | 0X100;
    // 0x80056A2C: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80056A30: lw          $t5, 0x2FE4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2FE4);
    // 0x80056A34: lui         $t4, 0x703
    ctx->r12 = S32(0X703 << 16);
    // 0x80056A38: ori         $t4, $t4, 0xC000
    ctx->r12 = ctx->r12 | 0XC000;
    // 0x80056A3C: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x80056A40: addiu       $v0, $t5, 0x8
    ctx->r2 = ADD32(ctx->r13, 0X8);
    // 0x80056A44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056A48: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056A4C: addiu       $v0, $t5, 0x10
    ctx->r2 = ADD32(ctx->r13, 0X10);
    // 0x80056A50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056A54: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056A58: addiu       $v0, $t5, 0x18
    ctx->r2 = ADD32(ctx->r13, 0X18);
    // 0x80056A5C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056A60: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056A64: addiu       $v0, $t5, 0x20
    ctx->r2 = ADD32(ctx->r13, 0X20);
    // 0x80056A68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056A6C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056A70: addiu       $v0, $t5, 0x28
    ctx->r2 = ADD32(ctx->r13, 0X28);
    // 0x80056A74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056A78: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056A7C: addiu       $v0, $t5, 0x30
    ctx->r2 = ADD32(ctx->r13, 0X30);
    // 0x80056A80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056A84: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056A88: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80056A8C: sw          $v0, 0x2C($t5)
    MEM_W(0X2C, ctx->r13) = ctx->r2;
    // 0x80056A90: addiu       $v0, $t5, 0x38
    ctx->r2 = ADD32(ctx->r13, 0X38);
    // 0x80056A94: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056A98: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056A9C: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x80056AA0: sw          $v0, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r2;
    // 0x80056AA4: sll         $v0, $s1, 5
    ctx->r2 = S32(ctx->r17 << 5);
    // 0x80056AA8: sw          $v1, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r3;
    // 0x80056AAC: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80056AB0: addiu       $v1, $v1, 0x5C00
    ctx->r3 = ADD32(ctx->r3, 0X5C00);
    // 0x80056AB4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80056AB8: sw          $v0, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r2;
    // 0x80056ABC: addiu       $v0, $t5, 0x40
    ctx->r2 = ADD32(ctx->r13, 0X40);
    // 0x80056AC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056AC4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056AC8: lui         $v0, 0xE800
    ctx->r2 = S32(0XE800 << 16);
    // 0x80056ACC: sw          $v0, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->r2;
    // 0x80056AD0: addiu       $v0, $t5, 0x48
    ctx->r2 = ADD32(ctx->r13, 0X48);
    // 0x80056AD4: sw          $a2, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r6;
    // 0x80056AD8: lui         $a2, 0x700
    ctx->r6 = S32(0X700 << 16);
    // 0x80056ADC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056AE0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056AE4: addiu       $v0, $t5, 0x50
    ctx->r2 = ADD32(ctx->r13, 0X50);
    // 0x80056AE8: sw          $a0, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r4;
    // 0x80056AEC: lui         $a0, 0xE600
    ctx->r4 = S32(0XE600 << 16);
    // 0x80056AF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056AF4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056AF8: addiu       $v0, $t5, 0x58
    ctx->r2 = ADD32(ctx->r13, 0X58);
    // 0x80056AFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056B00: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056B04: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x80056B08: sw          $v0, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->r2;
    // 0x80056B0C: lui         $v0, 0xFD50
    ctx->r2 = S32(0XFD50 << 16);
    // 0x80056B10: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x80056B14: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80056B18: sw          $zero, 0xC($t5)
    MEM_W(0XC, ctx->r13) = 0;
    // 0x80056B1C: sw          $a1, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r5;
    // 0x80056B20: sw          $zero, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = 0;
    // 0x80056B24: sw          $t0, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->r8;
    // 0x80056B28: sw          $a3, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->r7;
    // 0x80056B2C: sw          $t1, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->r9;
    // 0x80056B30: sw          $zero, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = 0;
    // 0x80056B34: sw          $t3, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->r11;
    // 0x80056B38: sw          $a2, 0x44($t5)
    MEM_W(0X44, ctx->r13) = ctx->r6;
    // 0x80056B3C: sw          $a0, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->r4;
    // 0x80056B40: sw          $zero, 0x4C($t5)
    MEM_W(0X4C, ctx->r13) = 0;
    // 0x80056B44: sw          $t4, 0x54($t5)
    MEM_W(0X54, ctx->r13) = ctx->r12;
    // 0x80056B48: sw          $v0, 0x60($t5)
    MEM_W(0X60, ctx->r13) = ctx->r2;
    // 0x80056B4C: sll         $v0, $t7, 2
    ctx->r2 = S32(ctx->r15 << 2);
    // 0x80056B50: sw          $t2, 0x58($t5)
    MEM_W(0X58, ctx->r13) = ctx->r10;
    // 0x80056B54: sw          $zero, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = 0;
    // 0x80056B58: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80056B5C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80056B60: lw          $v1, 0x5C40($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5C40);
    // 0x80056B64: addu        $a1, $t6, $zero
    ctx->r5 = ADD32(ctx->r14, 0);
    // 0x80056B68: addiu       $v0, $t5, 0x60
    ctx->r2 = ADD32(ctx->r13, 0X60);
    // 0x80056B6C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056B70: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056B74: addiu       $v0, $t5, 0x68
    ctx->r2 = ADD32(ctx->r13, 0X68);
    // 0x80056B78: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056B7C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056B80: addiu       $v0, $t5, 0x70
    ctx->r2 = ADD32(ctx->r13, 0X70);
    // 0x80056B84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056B88: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056B8C: lui         $v0, 0xF550
    ctx->r2 = S32(0XF550 << 16);
    // 0x80056B90: sw          $v0, 0x68($t5)
    MEM_W(0X68, ctx->r13) = ctx->r2;
    // 0x80056B94: addiu       $v0, $t5, 0x78
    ctx->r2 = ADD32(ctx->r13, 0X78);
    // 0x80056B98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056B9C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056BA0: addiu       $v0, $t5, 0x80
    ctx->r2 = ADD32(ctx->r13, 0X80);
    // 0x80056BA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056BA8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056BAC: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x80056BB0: sw          $v0, 0x78($t5)
    MEM_W(0X78, ctx->r13) = ctx->r2;
    // 0x80056BB4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80056BB8: addiu       $v0, $v0, 0x3A40
    ctx->r2 = ADD32(ctx->r2, 0X3A40);
    // 0x80056BBC: sw          $a2, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = ctx->r6;
    // 0x80056BC0: sw          $a0, 0x70($t5)
    MEM_W(0X70, ctx->r13) = ctx->r4;
    // 0x80056BC4: sw          $zero, 0x74($t5)
    MEM_W(0X74, ctx->r13) = 0;
    // 0x80056BC8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80056BCC: bgez        $t6, L_80056BD8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80056BD0: sw          $v1, 0x64($t5)
        MEM_W(0X64, ctx->r13) = ctx->r3;
            goto L_80056BD8;
    }
    // 0x80056BD0: sw          $v1, 0x64($t5)
    MEM_W(0X64, ctx->r13) = ctx->r3;
    // 0x80056BD4: addiu       $a1, $t6, 0xF
    ctx->r5 = ADD32(ctx->r14, 0XF);
L_80056BD8:
    // 0x80056BD8: sra         $a1, $a1, 4
    ctx->r5 = S32(SIGNED(ctx->r5) >> 4);
    // 0x80056BDC: blez        $a1, L_80056BE8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80056BE0: addiu       $v1, $zero, 0x800
        ctx->r3 = ADD32(0, 0X800);
            goto L_80056BE8;
    }
    // 0x80056BE0: addiu       $v1, $zero, 0x800
    ctx->r3 = ADD32(0, 0X800);
    // 0x80056BE4: addiu       $v1, $a1, 0x7FF
    ctx->r3 = ADD32(ctx->r5, 0X7FF);
L_80056BE8:
    // 0x80056BE8: nop

    // 0x80056BEC: mult        $t6, $t8
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80056BF0: mflo        $v0
    ctx->r2 = lo;
    // 0x80056BF4: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x80056BF8: sra         $v0, $v0, 2
    ctx->r2 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80056BFC: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x80056C00: slti        $v0, $a0, 0x800
    ctx->r2 = SIGNED(ctx->r4) < 0X800 ? 1 : 0;
    // 0x80056C04: beql        $v0, $zero, L_80056C0C
    if (ctx->r2 == 0) {
        // 0x80056C08: addiu       $a0, $zero, 0x7FF
        ctx->r4 = ADD32(0, 0X7FF);
            goto L_80056C0C;
    }
    goto skip_0;
    // 0x80056C08: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    skip_0:
L_80056C0C:
    // 0x80056C0C: andi        $v0, $a0, 0xFFF
    ctx->r2 = ctx->r4 & 0XFFF;
    // 0x80056C10: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x80056C14: blez        $a1, L_80056C58
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80056C18: or          $a0, $v0, $a2
        ctx->r4 = ctx->r2 | ctx->r6;
            goto L_80056C58;
    }
    // 0x80056C18: or          $a0, $v0, $a2
    ctx->r4 = ctx->r2 | ctx->r6;
    // 0x80056C1C: div         $zero, $v1, $a1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r5)));
    // 0x80056C20: bne         $a1, $zero, L_80056C2C
    if (ctx->r5 != 0) {
        // 0x80056C24: nop
    
            goto L_80056C2C;
    }
    // 0x80056C24: nop

    // 0x80056C28: break       7
    do_break(2147839016);
L_80056C2C:
    // 0x80056C2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056C30: bne         $a1, $at, L_80056C44
    if (ctx->r5 != ctx->r1) {
        // 0x80056C34: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80056C44;
    }
    // 0x80056C34: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80056C38: bne         $v1, $at, L_80056C44
    if (ctx->r3 != ctx->r1) {
        // 0x80056C3C: nop
    
            goto L_80056C44;
    }
    // 0x80056C3C: nop

    // 0x80056C40: break       6
    do_break(2147839040);
L_80056C44:
    // 0x80056C44: mflo        $v0
    ctx->r2 = lo;
    // 0x80056C48: nop

    // 0x80056C4C: nop

    // 0x80056C50: j           L_80056C5C
    // 0x80056C54: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
        goto L_80056C5C;
    // 0x80056C54: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
L_80056C58:
    // 0x80056C58: andi        $v0, $v1, 0xFFF
    ctx->r2 = ctx->r3 & 0XFFF;
L_80056C5C:
    // 0x80056C5C: or          $v0, $a0, $v0
    ctx->r2 = ctx->r4 | ctx->r2;
    // 0x80056C60: sw          $v0, 0x7C($t5)
    MEM_W(0X7C, ctx->r13) = ctx->r2;
    // 0x80056C64: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80056C68: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x80056C6C: lui         $v1, 0xF540
    ctx->r3 = S32(0XF540 << 16);
    // 0x80056C70: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80056C74: addu        $a2, $t6, $zero
    ctx->r6 = ADD32(ctx->r14, 0);
    // 0x80056C78: addu        $a3, $t8, $zero
    ctx->r7 = ADD32(ctx->r24, 0);
    // 0x80056C7C: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80056C80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056C84: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056C88: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x80056C8C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80056C90: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x80056C94: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056C98: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056C9C: sra         $v0, $t6, 1
    ctx->r2 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80056CA0: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x80056CA4: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80056CA8: andi        $v0, $v0, 0x1FF
    ctx->r2 = ctx->r2 & 0X1FF;
    // 0x80056CAC: sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2 << 9);
    // 0x80056CB0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80056CB4: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x80056CB8: addiu       $v0, $a0, 0x18
    ctx->r2 = ADD32(ctx->r4, 0X18);
    // 0x80056CBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056CC0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056CC4: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x80056CC8: addiu       $v1, $t6, -0x1
    ctx->r3 = ADD32(ctx->r14, -0X1);
    // 0x80056CCC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80056CD0: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80056CD4: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x80056CD8: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x80056CDC: addiu       $v0, $t8, -0x1
    ctx->r2 = ADD32(ctx->r24, -0X1);
    // 0x80056CE0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80056CE4: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80056CE8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80056CEC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80056CF0: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80056CF4: sw          $v1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r3;
    // 0x80056CF8: jal         0x80056D14
    // 0x80056CFC: addu        $a0, $t9, $zero
    ctx->r4 = ADD32(ctx->r25, 0);
    func_80056D14(rdram, ctx);
        goto after_0;
    // 0x80056CFC: addu        $a0, $t9, $zero
    ctx->r4 = ADD32(ctx->r25, 0);
    after_0:
L_80056D00:
    // 0x80056D00: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80056D04: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80056D08: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80056D0C: jr          $ra
    // 0x80056D10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80056D10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80056D14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056D14: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x80056D18: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // 0x80056D1C: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // 0x80056D20: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x80056D24: bgez        $t0, L_80056D44
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80056D28: addu        $t3, $zero, $zero
        ctx->r11 = ADD32(0, 0);
            goto L_80056D44;
    }
    // 0x80056D28: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // 0x80056D2C: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80056D30: bgez        $t0, L_80056D3C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80056D34: addu        $t2, $t0, $zero
        ctx->r10 = ADD32(ctx->r8, 0);
            goto L_80056D3C;
    }
    // 0x80056D34: addu        $t2, $t0, $zero
    ctx->r10 = ADD32(ctx->r8, 0);
    // 0x80056D38: negu        $t2, $t2
    ctx->r10 = SUB32(0, ctx->r10);
L_80056D3C:
    // 0x80056D3C: j           L_80056D58
    // 0x80056D40: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
        goto L_80056D58;
    // 0x80056D40: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
L_80056D44:
    // 0x80056D44: addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
    // 0x80056D48: slti        $v0, $v0, 0x140
    ctx->r2 = SIGNED(ctx->r2) < 0X140 ? 1 : 0;
    // 0x80056D4C: bne         $v0, $zero, L_80056D58
    if (ctx->r2 != 0) {
        // 0x80056D50: addiu       $v0, $zero, 0x140
        ctx->r2 = ADD32(0, 0X140);
            goto L_80056D58;
    }
    // 0x80056D50: addiu       $v0, $zero, 0x140
    ctx->r2 = ADD32(0, 0X140);
    // 0x80056D54: subu        $v1, $v0, $t0
    ctx->r3 = SUB32(ctx->r2, ctx->r8);
L_80056D58:
    // 0x80056D58: bgez        $t1, L_80056D78
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80056D5C: addu        $v0, $t1, $a3
        ctx->r2 = ADD32(ctx->r9, ctx->r7);
            goto L_80056D78;
    }
    // 0x80056D5C: addu        $v0, $t1, $a3
    ctx->r2 = ADD32(ctx->r9, ctx->r7);
    // 0x80056D60: addu        $a3, $a3, $t1
    ctx->r7 = ADD32(ctx->r7, ctx->r9);
    // 0x80056D64: bgez        $t1, L_80056D70
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80056D68: addu        $t3, $t1, $zero
        ctx->r11 = ADD32(ctx->r9, 0);
            goto L_80056D70;
    }
    // 0x80056D68: addu        $t3, $t1, $zero
    ctx->r11 = ADD32(ctx->r9, 0);
    // 0x80056D6C: negu        $t3, $t3
    ctx->r11 = SUB32(0, ctx->r11);
L_80056D70:
    // 0x80056D70: j           L_80056D88
    // 0x80056D74: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
        goto L_80056D88;
    // 0x80056D74: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
L_80056D78:
    // 0x80056D78: slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // 0x80056D7C: bne         $v0, $zero, L_80056D88
    if (ctx->r2 != 0) {
        // 0x80056D80: addiu       $v0, $zero, 0xF0
        ctx->r2 = ADD32(0, 0XF0);
            goto L_80056D88;
    }
    // 0x80056D80: addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // 0x80056D84: subu        $a3, $v0, $t1
    ctx->r7 = SUB32(ctx->r2, ctx->r9);
L_80056D88:
    // 0x80056D88: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80056D8C: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x80056D90: lui         $a2, 0x400
    ctx->r6 = S32(0X400 << 16);
    // 0x80056D94: ori         $a2, $a2, 0x400
    ctx->r6 = ctx->r6 | 0X400;
    // 0x80056D98: addu        $v1, $t0, $v1
    ctx->r3 = ADD32(ctx->r8, ctx->r3);
    // 0x80056D9C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80056DA0: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80056DA4: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x80056DA8: lui         $a0, 0xE400
    ctx->r4 = S32(0XE400 << 16);
    // 0x80056DAC: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80056DB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056DB4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056DB8: addu        $v0, $t1, $a3
    ctx->r2 = ADD32(ctx->r9, ctx->r7);
    // 0x80056DBC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80056DC0: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80056DC4: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x80056DC8: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80056DCC: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x80056DD0: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80056DD4: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x80056DD8: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80056DDC: sll         $v1, $t1, 2
    ctx->r3 = S32(ctx->r9 << 2);
    // 0x80056DE0: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80056DE4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80056DE8: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80056DEC: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x80056DF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056DF4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056DF8: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x80056DFC: sll         $v1, $t2, 21
    ctx->r3 = S32(ctx->r10 << 21);
    // 0x80056E00: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x80056E04: sll         $v0, $t3, 5
    ctx->r2 = S32(ctx->r11 << 5);
    // 0x80056E08: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80056E0C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80056E10: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x80056E14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056E18: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056E1C: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x80056E20: sw          $v1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r3;
    // 0x80056E24: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80056E28: jr          $ra
    // 0x80056E2C: sw          $a2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r6;
    return;
    // 0x80056E2C: sw          $a2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r6;
;}
RECOMP_FUNC void func_80056E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056E30: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80056E34: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80056E38: lui         $a1, 0xF650
    ctx->r5 = S32(0XF650 << 16);
    // 0x80056E3C: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80056E40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056E44: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056E48: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x80056E4C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80056E50: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80056E54: addiu       $v0, $v0, 0x5EA8
    ctx->r2 = ADD32(ctx->r2, 0X5EA8);
    // 0x80056E58: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80056E5C: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80056E60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056E64: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056E68: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x80056E6C: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x80056E70: lbu         $a0, 0x13($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X13);
    // 0x80056E74: ori         $a1, $a1, 0x3C0
    ctx->r5 = ctx->r5 | 0X3C0;
    // 0x80056E78: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x80056E7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056E80: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056E84: sw          $a1, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r5;
    // 0x80056E88: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x80056E8C: jr          $ra
    // 0x80056E90: sw          $a0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r4;
    return;
    // 0x80056E90: sw          $a0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r4;
;}
RECOMP_FUNC void func_80056E94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056E94: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056E98: sb          $zero, -0x5E0C($at)
    MEM_B(-0X5E0C, ctx->r1) = 0;
    // 0x80056E9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056EA0: sb          $zero, -0x5E0B($at)
    MEM_B(-0X5E0B, ctx->r1) = 0;
    // 0x80056EA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056EA8: jr          $ra
    // 0x80056EAC: sw          $zero, -0x5E00($at)
    MEM_W(-0X5E00, ctx->r1) = 0;
    return;
    // 0x80056EAC: sw          $zero, -0x5E00($at)
    MEM_W(-0X5E00, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80056EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056EB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80056EB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056EB8: sb          $v0, -0x5E0C($at)
    MEM_B(-0X5E0C, ctx->r1) = ctx->r2;
    // 0x80056EBC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80056EC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056EC4: sb          $v0, -0x5E0B($at)
    MEM_B(-0X5E0B, ctx->r1) = ctx->r2;
    // 0x80056EC8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80056ECC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056ED0: jr          $ra
    // 0x80056ED4: sw          $v0, -0x5E00($at)
    MEM_W(-0X5E00, ctx->r1) = ctx->r2;
    return;
    // 0x80056ED4: sw          $v0, -0x5E00($at)
    MEM_W(-0X5E00, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_80056ED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056ED8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80056EDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056EE0: sb          $v0, -0x5E0C($at)
    MEM_B(-0X5E0C, ctx->r1) = ctx->r2;
    // 0x80056EE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056EE8: sb          $v0, -0x5E0B($at)
    MEM_B(-0X5E0B, ctx->r1) = ctx->r2;
    // 0x80056EEC: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80056EF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056EF4: jr          $ra
    // 0x80056EF8: sw          $v0, -0x5E00($at)
    MEM_W(-0X5E00, ctx->r1) = ctx->r2;
    return;
    // 0x80056EF8: sw          $v0, -0x5E00($at)
    MEM_W(-0X5E00, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_80056EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056EFC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80056F00: lbu         $v1, -0x5E0B($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X5E0B);
    // 0x80056F04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80056F08: bne         $v1, $v0, L_80056F38
    if (ctx->r3 != ctx->r2) {
        // 0x80056F0C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80056F38;
    }
    // 0x80056F0C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80056F10: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80056F14: lw          $v0, -0x5E00($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E00);
    // 0x80056F18: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80056F1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056F20: sw          $v0, -0x5E00($at)
    MEM_W(-0X5E00, ctx->r1) = ctx->r2;
    // 0x80056F24: slti        $v0, $v0, 0xFF
    ctx->r2 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80056F28: bne         $v0, $zero, L_80056F74
    if (ctx->r2 != 0) {
        // 0x80056F2C: nop
    
            goto L_80056F74;
    }
    // 0x80056F2C: nop

    // 0x80056F30: j           L_80056F68
    // 0x80056F34: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_80056F68;
    // 0x80056F34: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80056F38:
    // 0x80056F38: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80056F3C: bne         $v1, $v0, L_80056F74
    if (ctx->r3 != ctx->r2) {
        // 0x80056F40: nop
    
            goto L_80056F74;
    }
    // 0x80056F40: nop

    // 0x80056F44: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80056F48: lw          $v0, -0x5E00($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E00);
    // 0x80056F4C: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x80056F50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056F54: sw          $v0, -0x5E00($at)
    MEM_W(-0X5E00, ctx->r1) = ctx->r2;
    // 0x80056F58: slti        $v0, $v0, 0xB
    ctx->r2 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80056F5C: beq         $v0, $zero, L_80056F74
    if (ctx->r2 == 0) {
        // 0x80056F60: nop
    
            goto L_80056F74;
    }
    // 0x80056F60: nop

    // 0x80056F64: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80056F68:
    // 0x80056F68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056F6C: sw          $v0, -0x5E00($at)
    MEM_W(-0X5E00, ctx->r1) = ctx->r2;
    // 0x80056F70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80056F74:
    // 0x80056F74: jr          $ra
    // 0x80056F78: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    return;
    // 0x80056F78: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
;}
RECOMP_FUNC void func_80056F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056F7C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80056F80: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80056F84: lui         $a1, 0xF650
    ctx->r5 = S32(0XF650 << 16);
    // 0x80056F88: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x80056F8C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80056F90: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80056F94: addiu       $v0, $v0, 0x5EA8
    ctx->r2 = ADD32(ctx->r2, 0X5EA8);
    // 0x80056F98: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80056F9C: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x80056FA0: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x80056FA4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80056FA8: lbu         $a0, -0x5DFD($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X5DFD);
    // 0x80056FAC: ori         $a1, $a1, 0x3C0
    ctx->r5 = ctx->r5 | 0X3C0;
    // 0x80056FB0: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80056FB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056FB8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056FBC: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80056FC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056FC4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056FC8: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x80056FCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056FD0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80056FD4: sw          $a1, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r5;
    // 0x80056FD8: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x80056FDC: jr          $ra
    // 0x80056FE0: sw          $a0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r4;
    return;
    // 0x80056FE0: sw          $a0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r4;
;}
RECOMP_FUNC void func_80056FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056FF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80056FF4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80056FF8: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80056FFC: addiu       $s0, $s0, 0x6AA0
    ctx->r16 = ADD32(ctx->r16, 0X6AA0);
    // 0x80057000: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057004: jal         0x80017D38
    // 0x80057008: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80017D38(rdram, ctx);
        goto after_0;
    // 0x80057008: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8005700C: jal         0x80017D38
    // 0x80057010: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    func_80017D38(rdram, ctx);
        goto after_1;
    // 0x80057010: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    after_1:
    // 0x80057014: jal         0x80017D38
    // 0x80057018: addiu       $a0, $s0, 0xE0
    ctx->r4 = ADD32(ctx->r16, 0XE0);
    func_80017D38(rdram, ctx);
        goto after_2;
    // 0x80057018: addiu       $a0, $s0, 0xE0
    ctx->r4 = ADD32(ctx->r16, 0XE0);
    after_2:
    // 0x8005701C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80057020: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80057024: jr          $ra
    // 0x80057028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80057028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005702C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005702C: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80057030: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x80057034: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80057038: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x8005703C: addiu       $a3, $a3, -0x5DC0
    ctx->r7 = ADD32(ctx->r7, -0X5DC0);
    // 0x80057040: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80057044: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80057048: addiu       $v1, $v1, 0x5582
    ctx->r3 = ADD32(ctx->r3, 0X5582);
    // 0x8005704C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80057050: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80057054: addiu       $a1, $a1, -0x5DD8
    ctx->r5 = ADD32(ctx->r5, -0X5DD8);
    // 0x80057058: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8005705C: addiu       $a0, $a0, -0x5DF0
    ctx->r4 = ADD32(ctx->r4, -0X5DF0);
    // 0x80057060: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80057064: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_80057068:
    // 0x80057068: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x8005706C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80057070: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x80057074: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80057078: addiu       $a2, $a2, 0x5
    ctx->r6 = ADD32(ctx->r6, 0X5);
    // 0x8005707C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80057080: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80057084: slti        $v0, $t0, 0x5
    ctx->r2 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x80057088: bne         $v0, $zero, L_80057068
    if (ctx->r2 != 0) {
        // 0x8005708C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80057068;
    }
    // 0x8005708C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80057090: jr          $ra
    // 0x80057094: nop

    return;
    // 0x80057094: nop

;}
RECOMP_FUNC void func_80057098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057098: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005709C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800570A0: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x800570A4: addiu       $s0, $s0, 0x6AA0
    ctx->r16 = ADD32(ctx->r16, 0X6AA0);
    // 0x800570A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800570AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800570B0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800570B4: jal         0x80017D38
    // 0x800570B8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    func_80017D38(rdram, ctx);
        goto after_0;
    // 0x800570B8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // 0x800570BC: jal         0x80017D38
    // 0x800570C0: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    func_80017D38(rdram, ctx);
        goto after_1;
    // 0x800570C0: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    after_1:
    // 0x800570C4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_800570C8:
    // 0x800570C8: jal         0x80057130
    // 0x800570CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80057130(rdram, ctx);
        goto after_2;
    // 0x800570CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800570D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800570D4: slti        $v0, $s0, 0x5
    ctx->r2 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x800570D8: bne         $v0, $zero, L_800570C8
    if (ctx->r2 != 0) {
        // 0x800570DC: nop
    
            goto L_800570C8;
    }
    // 0x800570DC: nop

    // 0x800570E0: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x800570E4: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x800570E8: addiu       $s2, $s2, 0x6D40
    ctx->r18 = ADD32(ctx->r18, 0X6D40);
    // 0x800570EC: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800570F0: addiu       $s1, $s1, -0x5DB0
    ctx->r17 = ADD32(ctx->r17, -0X5DB0);
L_800570F4:
    // 0x800570F4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800570F8: bnel        $v0, $zero, L_8005710C
    if (ctx->r2 != 0) {
        // 0x800570FC: addiu       $s2, $s2, -0x70
        ctx->r18 = ADD32(ctx->r18, -0X70);
            goto L_8005710C;
    }
    goto skip_0;
    // 0x800570FC: addiu       $s2, $s2, -0x70
    ctx->r18 = ADD32(ctx->r18, -0X70);
    skip_0:
    // 0x80057100: jal         0x80017D38
    // 0x80057104: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80017D38(rdram, ctx);
        goto after_3;
    // 0x80057104: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_3:
    // 0x80057108: addiu       $s2, $s2, -0x70
    ctx->r18 = ADD32(ctx->r18, -0X70);
L_8005710C:
    // 0x8005710C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80057110: bgez        $s0, L_800570F4
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80057114: addiu       $s1, $s1, -0x4
        ctx->r17 = ADD32(ctx->r17, -0X4);
            goto L_800570F4;
    }
    // 0x80057114: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
    // 0x80057118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005711C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80057120: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80057124: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80057128: jr          $ra
    // 0x8005712C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005712C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80057130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057130: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80057134: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80057138: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8005713C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80057140: addiu       $v0, $v0, -0x5DC0
    ctx->r2 = ADD32(ctx->r2, -0X5DC0);
    // 0x80057144: sll         $a0, $s2, 2
    ctx->r4 = S32(ctx->r18 << 2);
    // 0x80057148: addu        $v1, $a0, $v0
    ctx->r3 = ADD32(ctx->r4, ctx->r2);
    // 0x8005714C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80057150: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80057154: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80057158: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8005715C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80057160: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80057164: bgtz        $v0, L_800572C4
    if (SIGNED(ctx->r2) > 0) {
        // 0x80057168: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800572C4;
    }
    // 0x80057168: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8005716C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80057170: addiu       $v0, $v0, -0x5DF0
    ctx->r2 = ADD32(ctx->r2, -0X5DF0);
    // 0x80057174: addu        $s1, $a0, $v0
    ctx->r17 = ADD32(ctx->r4, ctx->r2);
    // 0x80057178: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8005717C: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80057180: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80057184: ldc1        $f2, -0x1310($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1310);
    // 0x80057188: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8005718C: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x80057190: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80057194: addiu       $s0, $s0, -0x5DD8
    ctx->r16 = ADD32(ctx->r16, -0X5DD8);
    // 0x80057198: addu        $s0, $a0, $s0
    ctx->r16 = ADD32(ctx->r4, ctx->r16);
    // 0x8005719C: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x800571A0: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x800571A4: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800571A8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800571AC: ldc1        $f2, -0x1308($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1308);
    // 0x800571B0: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x800571B4: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x800571B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800571BC: ldc1        $f20, -0x1300($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0X1300);
    // 0x800571C0: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x800571C4: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x800571C8: mul.d       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f20.d); 
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f20.d);
    // 0x800571CC: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x800571D0: jal         0x80060400
    // 0x800571D4: cvt.s.d     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
    cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x800571D4: cvt.s.d     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
    after_0:
    // 0x800571D8: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800571DC: cvt.d.s     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.d = CVT_D_S(ctx->f12.fl);
    // 0x800571E0: mul.d       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f20.d); 
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f20.d);
    // 0x800571E4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800571E8: jal         0x80061290
    // 0x800571EC: cvt.s.d     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x800571EC: cvt.s.d     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
    after_1:
    // 0x800571F0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800571F4: ldc1        $f2, -0x12F8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X12F8);
    // 0x800571F8: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x800571FC: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x80057200: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80057204: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80057208: nop

    // 0x8005720C: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80057210: nop

    // 0x80057214: nop

    // 0x80057218: bc1f        L_8005727C
    if (!c1cs) {
        // 0x8005721C: cvt.s.d     $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f4.fl = CVT_S_D(ctx->f0.d);
            goto L_8005727C;
    }
    // 0x8005721C: cvt.s.d     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f4.fl = CVT_S_D(ctx->f0.d);
    // 0x80057220: nop

    // 0x80057224: mul.s       $f0, $f20, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80057228: addiu       $v0, $s2, 0x2
    ctx->r2 = ADD32(ctx->r18, 0X2);
    // 0x8005722C: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80057230: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80057234: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80057238: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8005723C: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80057240: nop

    // 0x80057244: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80057248: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8005724C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80057250: sh          $v0, 0x6AA4($at)
    MEM_H(0X6AA4, ctx->r1) = ctx->r2;
    // 0x80057254: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80057258: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8005725C: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80057260: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80057264: nop

    // 0x80057268: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005726C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80057270: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80057274: j           L_800572C4
    // 0x80057278: sh          $v0, 0x6AAC($at)
    MEM_H(0X6AAC, ctx->r1) = ctx->r2;
        goto L_800572C4;
    // 0x80057278: sh          $v0, 0x6AAC($at)
    MEM_H(0X6AAC, ctx->r1) = ctx->r2;
L_8005727C:
    // 0x8005727C: addiu       $v0, $s2, 0x2
    ctx->r2 = ADD32(ctx->r18, 0X2);
    // 0x80057280: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80057284: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80057288: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x8005728C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80057290: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x80057294: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80057298: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8005729C: sh          $zero, 0x6AA4($at)
    MEM_H(0X6AA4, ctx->r1) = 0;
    // 0x800572A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800572A4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800572A8: bne         $s2, $v0, L_800572C4
    if (ctx->r18 != ctx->r2) {
        // 0x800572AC: sh          $zero, 0x6AAC($at)
        MEM_H(0X6AAC, ctx->r1) = 0;
            goto L_800572C4;
    }
    // 0x800572AC: sh          $zero, 0x6AAC($at)
    MEM_H(0X6AAC, ctx->r1) = 0;
    // 0x800572B0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800572B4: addiu       $v1, $v1, 0x5582
    ctx->r3 = ADD32(ctx->r3, 0X5582);
    // 0x800572B8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800572BC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800572C0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_800572C4:
    // 0x800572C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800572C8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800572CC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800572D0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800572D4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800572D8: jr          $ra
    // 0x800572DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800572DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800572E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800572E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800572E4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800572E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800572EC: jal         0x80057388
    // 0x800572F0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80057388(rdram, ctx);
        goto after_0;
    // 0x800572F0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x800572F4: jal         0x80057388
    // 0x800572F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80057388(rdram, ctx);
        goto after_1;
    // 0x800572F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800572FC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80057300:
    // 0x80057300: jal         0x80057388
    // 0x80057304: addiu       $a0, $s0, 0x2
    ctx->r4 = ADD32(ctx->r16, 0X2);
    func_80057388(rdram, ctx);
        goto after_2;
    // 0x80057304: addiu       $a0, $s0, 0x2
    ctx->r4 = ADD32(ctx->r16, 0X2);
    after_2:
    // 0x80057308: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005730C: slti        $v0, $s0, 0x5
    ctx->r2 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x80057310: bne         $v0, $zero, L_80057300
    if (ctx->r2 != 0) {
        // 0x80057314: nop
    
            goto L_80057300;
    }
    // 0x80057314: nop

    // 0x80057318: jal         0x80057678
    // 0x8005731C: nop

    func_80057678(rdram, ctx);
        goto after_3;
    // 0x8005731C: nop

    after_3:
    // 0x80057320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80057324: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80057328: jr          $ra
    // 0x8005732C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005732C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80057330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057330: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80057334: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80057338: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8005733C: jal         0x80017D38
    // 0x80057340: addiu       $a0, $a0, 0x6AA0
    ctx->r4 = ADD32(ctx->r4, 0X6AA0);
    func_80017D38(rdram, ctx);
        goto after_0;
    // 0x80057340: addiu       $a0, $a0, 0x6AA0
    ctx->r4 = ADD32(ctx->r4, 0X6AA0);
    after_0:
    // 0x80057344: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80057348: jr          $ra
    // 0x8005734C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005734C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80057350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80057354: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80057358: jal         0x80057388
    // 0x8005735C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80057388(rdram, ctx);
        goto after_0;
    // 0x8005735C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // 0x80057360: jal         0x80057634
    // 0x80057364: nop

    func_80057634(rdram, ctx);
        goto after_1;
    // 0x80057364: nop

    after_1:
    // 0x80057368: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x8005736C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80057370: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80057374: jal         0x8001D670
    // 0x80057378: addiu       $a0, $a0, -0x2338
    ctx->r4 = ADD32(ctx->r4, -0X2338);
    func_8001D670(rdram, ctx);
        goto after_2;
    // 0x80057378: addiu       $a0, $a0, -0x2338
    ctx->r4 = ADD32(ctx->r4, -0X2338);
    after_2:
    // 0x8005737C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80057380: jr          $ra
    // 0x80057384: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80057384: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80057388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057388: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005738C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80057390: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80057394: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80057398: sll         $s0, $s1, 3
    ctx->r16 = S32(ctx->r17 << 3);
    // 0x8005739C: subu        $s0, $s0, $s1
    ctx->r16 = SUB32(ctx->r16, ctx->r17);
    // 0x800573A0: sll         $s0, $s0, 4
    ctx->r16 = S32(ctx->r16 << 4);
    // 0x800573A4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800573A8: addiu       $a0, $a0, 0x6AA0
    ctx->r4 = ADD32(ctx->r4, 0X6AA0);
    // 0x800573AC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800573B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800573B4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800573B8: sb          $zero, 0x6ACA($at)
    MEM_B(0X6ACA, ctx->r1) = 0;
    // 0x800573BC: jal         0x80017760
    // 0x800573C0: addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    func_80017760(rdram, ctx);
        goto after_0;
    // 0x800573C0: addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    after_0:
    // 0x800573C4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800573C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800573CC: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800573D0: sb          $v0, 0x6AB6($at)
    MEM_B(0X6AB6, ctx->r1) = ctx->r2;
    // 0x800573D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800573D8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800573DC: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800573E0: sb          $v0, 0x6AB7($at)
    MEM_B(0X6AB7, ctx->r1) = ctx->r2;
    // 0x800573E4: sltiu       $v0, $s1, 0x7
    ctx->r2 = ctx->r17 < 0X7 ? 1 : 0;
    // 0x800573E8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800573EC: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800573F0: sh          $zero, 0x6AB8($at)
    MEM_H(0X6AB8, ctx->r1) = 0;
    // 0x800573F4: beq         $v0, $zero, L_80057504
    if (ctx->r2 == 0) {
        // 0x800573F8: sll         $v0, $s1, 2
        ctx->r2 = S32(ctx->r17 << 2);
            goto L_80057504;
    }
    // 0x800573F8: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x800573FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80057400: addu        $at, $at, $v0
    gpr jr_addend_80057408 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80057404: lw          $v0, -0x12F0($at)
    ctx->r2 = ADD32(ctx->r1, -0X12F0);
    // 0x80057408: jr          $v0
    // 0x8005740C: nop

    switch (jr_addend_80057408 >> 2) {
        case 0: goto L_80057410; break;
        case 1: goto L_80057438; break;
        case 2: goto L_80057460; break;
        case 3: goto L_8005749C; break;
        case 4: goto L_8005749C; break;
        case 5: goto L_8005749C; break;
        case 6: goto L_8005749C; break;
        default: switch_error(__func__, 0x80057408, 0x800AED10);
    }
    // 0x8005740C: nop

L_80057410:
    // 0x80057410: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80057414: addiu       $v0, $v0, -0x75C0
    ctx->r2 = ADD32(ctx->r2, -0X75C0);
    // 0x80057418: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8005741C: sw          $v0, 0x6AB0($at)
    MEM_W(0X6AB0, ctx->r1) = ctx->r2;
    // 0x80057420: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80057424: addiu       $v0, $v0, -0x2338
    ctx->r2 = ADD32(ctx->r2, -0X2338);
    // 0x80057428: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8005742C: sw          $v0, 0x6AD0($at)
    MEM_W(0X6AD0, ctx->r1) = ctx->r2;
    // 0x80057430: j           L_80057508
    // 0x80057434: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
        goto L_80057508;
    // 0x80057434: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
L_80057438:
    // 0x80057438: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8005743C: addiu       $v0, $v0, -0x1DC0
    ctx->r2 = ADD32(ctx->r2, -0X1DC0);
    // 0x80057440: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80057444: sw          $v0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r2;
    // 0x80057448: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8005744C: addiu       $v0, $v0, -0x2538
    ctx->r2 = ADD32(ctx->r2, -0X2538);
    // 0x80057450: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80057454: sw          $v0, 0x6B40($at)
    MEM_W(0X6B40, ctx->r1) = ctx->r2;
    // 0x80057458: j           L_80057508
    // 0x8005745C: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
        goto L_80057508;
    // 0x8005745C: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
L_80057460:
    // 0x80057460: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
    // 0x80057464: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x80057468: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8005746C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80057470: addiu       $v1, $v1, 0x3A40
    ctx->r3 = ADD32(ctx->r3, 0X3A40);
    // 0x80057474: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80057478: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8005747C: sw          $v1, 0x6AB0($at)
    MEM_W(0X6AB0, ctx->r1) = ctx->r3;
    // 0x80057480: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80057484: addiu       $v1, $v1, 0x1018
    ctx->r3 = ADD32(ctx->r3, 0X1018);
    // 0x80057488: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8005748C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80057490: sw          $v1, 0x6AD0($at)
    MEM_W(0X6AD0, ctx->r1) = ctx->r3;
    // 0x80057494: j           L_80057508
    // 0x80057498: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
        goto L_80057508;
    // 0x80057498: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
L_8005749C:
    // 0x8005749C: sll         $a0, $s1, 3
    ctx->r4 = S32(ctx->r17 << 3);
    // 0x800574A0: subu        $a0, $a0, $s1
    ctx->r4 = SUB32(ctx->r4, ctx->r17);
    // 0x800574A4: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x800574A8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800574AC: addiu       $v0, $v0, 0x3A40
    ctx->r2 = ADD32(ctx->r2, 0X3A40);
    // 0x800574B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800574B4: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800574B8: sw          $v0, 0x6AB0($at)
    MEM_W(0X6AB0, ctx->r1) = ctx->r2;
    // 0x800574BC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800574C0: addiu       $v0, $v0, 0x1018
    ctx->r2 = ADD32(ctx->r2, 0X1018);
    // 0x800574C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800574C8: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800574CC: sw          $v0, 0x6AD0($at)
    MEM_W(0X6AD0, ctx->r1) = ctx->r2;
    // 0x800574D0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800574D4: addiu       $v1, $s1, -0x2
    ctx->r3 = ADD32(ctx->r17, -0X2);
    // 0x800574D8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800574DC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800574E0: sb          $v0, 0x6ACA($at)
    MEM_B(0X6ACA, ctx->r1) = ctx->r2;
    // 0x800574E4: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800574E8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800574EC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800574F0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800574F4: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x800574F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800574FC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80057500: sb          $v0, 0x6ACF($at)
    MEM_B(0X6ACF, ctx->r1) = ctx->r2;
L_80057504:
    // 0x80057504: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
L_80057508:
    // 0x80057508: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x8005750C: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x80057510: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80057514: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80057518: sw          $zero, 0x6AE4($at)
    MEM_W(0X6AE4, ctx->r1) = 0;
    // 0x8005751C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80057520: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80057524: sw          $zero, 0x6AE8($at)
    MEM_W(0X6AE8, ctx->r1) = 0;
    // 0x80057528: bltz        $s1, L_800575C8
    if (SIGNED(ctx->r17) < 0) {
        // 0x8005752C: slti        $v0, $s1, 0x2
        ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
            goto L_800575C8;
    }
    // 0x8005752C: slti        $v0, $s1, 0x2
    ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x80057530: beq         $v0, $zero, L_80057574
    if (ctx->r2 == 0) {
        // 0x80057534: addiu       $v1, $zero, 0x500
        ctx->r3 = ADD32(0, 0X500);
            goto L_80057574;
    }
    // 0x80057534: addiu       $v1, $zero, 0x500
    ctx->r3 = ADD32(0, 0X500);
    // 0x80057538: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8005753C: addiu       $v0, $v0, 0x6AA0
    ctx->r2 = ADD32(ctx->r2, 0X6AA0);
    // 0x80057540: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80057544: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80057548: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8005754C: sh          $zero, 0x6AA4($at)
    MEM_H(0X6AA4, ctx->r1) = 0;
    // 0x80057550: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80057554: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80057558: sh          $zero, 0x6AAC($at)
    MEM_H(0X6AAC, ctx->r1) = 0;
    // 0x8005755C: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
    // 0x80057560: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80057564: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80057568: sh          $v1, 0x6AA2($at)
    MEM_H(0X6AA2, ctx->r1) = ctx->r3;
    // 0x8005756C: j           L_800575B8
    // 0x80057570: addiu       $v1, $zero, 0x3C0
    ctx->r3 = ADD32(0, 0X3C0);
        goto L_800575B8;
    // 0x80057570: addiu       $v1, $zero, 0x3C0
    ctx->r3 = ADD32(0, 0X3C0);
L_80057574:
    // 0x80057574: slti        $v0, $s1, 0x7
    ctx->r2 = SIGNED(ctx->r17) < 0X7 ? 1 : 0;
    // 0x80057578: beq         $v0, $zero, L_800575CC
    if (ctx->r2 == 0) {
        // 0x8005757C: sll         $v0, $s1, 3
        ctx->r2 = S32(ctx->r17 << 3);
            goto L_800575CC;
    }
    // 0x8005757C: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
    // 0x80057580: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80057584: addiu       $v0, $v0, 0x6AA0
    ctx->r2 = ADD32(ctx->r2, 0X6AA0);
    // 0x80057588: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x8005758C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80057590: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80057594: sh          $zero, 0x6AA4($at)
    MEM_H(0X6AA4, ctx->r1) = 0;
    // 0x80057598: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8005759C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800575A0: sh          $zero, 0x6AAC($at)
    MEM_H(0X6AAC, ctx->r1) = 0;
    // 0x800575A4: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
    // 0x800575A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800575AC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800575B0: sh          $v1, 0x6AA2($at)
    MEM_H(0X6AA2, ctx->r1) = ctx->r3;
    // 0x800575B4: addiu       $v1, $zero, 0x280
    ctx->r3 = ADD32(0, 0X280);
L_800575B8:
    // 0x800575B8: sh          $v1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r3;
    // 0x800575BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800575C0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800575C4: sh          $v1, 0x6AAA($at)
    MEM_H(0X6AAA, ctx->r1) = ctx->r3;
L_800575C8:
    // 0x800575C8: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
L_800575CC:
    // 0x800575CC: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x800575D0: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x800575D4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800575D8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800575DC: lbu         $v0, 0x6ACA($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6ACA);
    // 0x800575E0: beq         $v0, $zero, L_80057610
    if (ctx->r2 == 0) {
        // 0x800575E4: addiu       $v0, $zero, 0x400
        ctx->r2 = ADD32(0, 0X400);
            goto L_80057610;
    }
    // 0x800575E4: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x800575E8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800575EC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800575F0: sh          $v0, 0x6ABE($at)
    MEM_H(0X6ABE, ctx->r1) = ctx->r2;
    // 0x800575F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800575F8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800575FC: sh          $v0, 0x6ABC($at)
    MEM_H(0X6ABC, ctx->r1) = ctx->r2;
    // 0x80057600: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80057604: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80057608: j           L_80057620
    // 0x8005760C: sw          $zero, 0x6AC0($at)
    MEM_W(0X6AC0, ctx->r1) = 0;
        goto L_80057620;
    // 0x8005760C: sw          $zero, 0x6AC0($at)
    MEM_W(0X6AC0, ctx->r1) = 0;
L_80057610:
    // 0x80057610: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80057614: addiu       $a0, $a0, 0x6AA0
    ctx->r4 = ADD32(ctx->r4, 0X6AA0);
    // 0x80057618: jal         0x80066D30
    // 0x8005761C: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    func_80066D30(rdram, ctx);
        goto after_1;
    // 0x8005761C: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_1:
L_80057620:
    // 0x80057620: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80057624: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80057628: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005762C: jr          $ra
    // 0x80057630: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80057630: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80057634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057634: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80057638: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005763C: lw          $v0, 0x5EF4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5EF4);
    // 0x80057640: lui         $a0, 0x6E
    ctx->r4 = S32(0X6E << 16);
    // 0x80057644: addiu       $a0, $a0, -0x3DD0
    ctx->r4 = ADD32(ctx->r4, -0X3DD0);
    // 0x80057648: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x8005764C: lw          $a3, 0x5EF0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X5EF0);
    // 0x80057650: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80057654: addiu       $a1, $a1, -0x2338
    ctx->r5 = ADD32(ctx->r5, -0X2338);
    // 0x80057658: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8005765C: addiu       $a2, $a2, -0x75C0
    ctx->r6 = ADD32(ctx->r6, -0X75C0);
    // 0x80057660: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80057664: jal         0x80053078
    // 0x80057668: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80053078(rdram, ctx);
        goto after_0;
    // 0x80057668: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x8005766C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80057670: jr          $ra
    // 0x80057674: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80057674: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80057678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057678: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005767C: lui         $a0, 0x6E
    ctx->r4 = S32(0X6E << 16);
    // 0x80057680: addiu       $a0, $a0, -0x3DD0
    ctx->r4 = ADD32(ctx->r4, -0X3DD0);
    // 0x80057684: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x80057688: lw          $a3, 0x5EF0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X5EF0);
    // 0x8005768C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80057690: lw          $v0, 0x5EF4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5EF4);
    // 0x80057694: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80057698: addiu       $a1, $a1, -0x2338
    ctx->r5 = ADD32(ctx->r5, -0X2338);
    // 0x8005769C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800576A0: addiu       $a2, $a2, -0x75C0
    ctx->r6 = ADD32(ctx->r6, -0X75C0);
    // 0x800576A4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800576A8: jal         0x80053078
    // 0x800576AC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80053078(rdram, ctx);
        goto after_0;
    // 0x800576AC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x800576B0: lui         $a0, 0x6F
    ctx->r4 = S32(0X6F << 16);
    // 0x800576B4: addiu       $a0, $a0, -0x6C20
    ctx->r4 = ADD32(ctx->r4, -0X6C20);
    // 0x800576B8: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x800576BC: lw          $a3, 0x5F08($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X5F08);
    // 0x800576C0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800576C4: lw          $v0, 0x5F0C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5F0C);
    // 0x800576C8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800576CC: addiu       $a1, $a1, -0x2538
    ctx->r5 = ADD32(ctx->r5, -0X2538);
    // 0x800576D0: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x800576D4: addiu       $a2, $a2, -0x1DC0
    ctx->r6 = ADD32(ctx->r6, -0X1DC0);
    // 0x800576D8: jal         0x80053078
    // 0x800576DC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80053078(rdram, ctx);
        goto after_1;
    // 0x800576DC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x800576E0: lui         $a0, 0x6E
    ctx->r4 = S32(0X6E << 16);
    // 0x800576E4: addiu       $a0, $a0, 0x77A0
    ctx->r4 = ADD32(ctx->r4, 0X77A0);
    // 0x800576E8: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x800576EC: lw          $a3, 0x5F00($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X5F00);
    // 0x800576F0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800576F4: lw          $v0, 0x5F04($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5F04);
    // 0x800576F8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800576FC: addiu       $a1, $a1, 0x1018
    ctx->r5 = ADD32(ctx->r5, 0X1018);
    // 0x80057700: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80057704: addiu       $a2, $a2, 0x3A40
    ctx->r6 = ADD32(ctx->r6, 0X3A40);
    // 0x80057708: jal         0x80053078
    // 0x8005770C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80053078(rdram, ctx);
        goto after_2;
    // 0x8005770C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x80057710: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80057714: jr          $ra
    // 0x80057718: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80057718: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80057720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057720: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80057724: addiu       $a1, $a1, 0x3A40
    ctx->r5 = ADD32(ctx->r5, 0X3A40);
    // 0x80057728: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005772C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80057730:
    // 0x80057730: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057734: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80057738: sw          $a1, -0x5D88($at)
    MEM_W(-0X5D88, ctx->r1) = ctx->r5;
    // 0x8005773C: addiu       $a1, $a1, 0x200
    ctx->r5 = ADD32(ctx->r5, 0X200);
    // 0x80057740: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057744: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80057748: sb          $zero, -0x5DA0($at)
    MEM_B(-0X5DA0, ctx->r1) = 0;
    // 0x8005774C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057750: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80057754: sb          $zero, -0x5D9C($at)
    MEM_B(-0X5D9C, ctx->r1) = 0;
    // 0x80057758: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005775C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80057760: sb          $zero, -0x5D9B($at)
    MEM_B(-0X5D9B, ctx->r1) = 0;
    // 0x80057764: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057768: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8005776C: sb          $zero, -0x5D9A($at)
    MEM_B(-0X5D9A, ctx->r1) = 0;
    // 0x80057770: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057774: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80057778: sb          $zero, -0x5D99($at)
    MEM_B(-0X5D99, ctx->r1) = 0;
    // 0x8005777C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80057780: slti        $v0, $a0, 0xD
    ctx->r2 = SIGNED(ctx->r4) < 0XD ? 1 : 0;
    // 0x80057784: bne         $v0, $zero, L_80057730
    if (ctx->r2 != 0) {
        // 0x80057788: addiu       $v1, $v1, 0x44
        ctx->r3 = ADD32(ctx->r3, 0X44);
            goto L_80057730;
    }
    // 0x80057788: addiu       $v1, $v1, 0x44
    ctx->r3 = ADD32(ctx->r3, 0X44);
    // 0x8005778C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80057790: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057794: sw          $zero, -0x5A2C($at)
    MEM_W(-0X5A2C, ctx->r1) = 0;
    // 0x80057798: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005779C: sw          $v0, -0x5A28($at)
    MEM_W(-0X5A28, ctx->r1) = ctx->r2;
    // 0x800577A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800577A4: sw          $zero, -0x5A24($at)
    MEM_W(-0X5A24, ctx->r1) = 0;
    // 0x800577A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800577AC: jr          $ra
    // 0x800577B0: sw          $zero, -0x33D0($at)
    MEM_W(-0X33D0, ctx->r1) = 0;
    return;
    // 0x800577B0: sw          $zero, -0x33D0($at)
    MEM_W(-0X33D0, ctx->r1) = 0;
;}
RECOMP_FUNC void func_800577B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800577B4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800577B8: lw          $v0, -0x5A24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5A24);
    // 0x800577BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800577C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800577C4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800577C8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800577CC: bne         $v0, $zero, L_800577E4
    if (ctx->r2 != 0) {
        // 0x800577D0: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800577E4;
    }
    // 0x800577D0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800577D4: jal         0x8005783C
    // 0x800577D8: nop

    func_8005783C(rdram, ctx);
        goto after_0;
    // 0x800577D8: nop

    after_0:
    // 0x800577DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800577E0: sw          $v0, -0x5A24($at)
    MEM_W(-0X5A24, ctx->r1) = ctx->r2;
L_800577E4:
    // 0x800577E4: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800577E8: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800577EC: addiu       $s1, $s1, -0x5DA0
    ctx->r17 = ADD32(ctx->r17, -0X5DA0);
    // 0x800577F0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_800577F4:
    // 0x800577F4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800577F8: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800577FC: lbu         $v0, -0x5DA0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5DA0);
    // 0x80057800: beql        $v0, $zero, L_80057814
    if (ctx->r2 == 0) {
        // 0x80057804: addiu       $s1, $s1, 0x44
        ctx->r17 = ADD32(ctx->r17, 0X44);
            goto L_80057814;
    }
    goto skip_0;
    // 0x80057804: addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
    skip_0:
    // 0x80057808: jal         0x8005795C
    // 0x8005780C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8005795C(rdram, ctx);
        goto after_1;
    // 0x8005780C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x80057810: addiu       $s1, $s1, 0x44
    ctx->r17 = ADD32(ctx->r17, 0X44);
L_80057814:
    // 0x80057814: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80057818: slti        $v0, $s2, 0xD
    ctx->r2 = SIGNED(ctx->r18) < 0XD ? 1 : 0;
    // 0x8005781C: bne         $v0, $zero, L_800577F4
    if (ctx->r2 != 0) {
        // 0x80057820: addiu       $s0, $s0, 0x44
        ctx->r16 = ADD32(ctx->r16, 0X44);
            goto L_800577F4;
    }
    // 0x80057820: addiu       $s0, $s0, 0x44
    ctx->r16 = ADD32(ctx->r16, 0X44);
    // 0x80057824: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80057828: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8005782C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80057830: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80057834: jr          $ra
    // 0x80057838: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80057838: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8005783C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005783C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80057840: lw          $v0, -0x5A28($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5A28);
    // 0x80057844: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80057848: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005784C: sw          $v0, -0x5A28($at)
    MEM_W(-0X5A28, ctx->r1) = ctx->r2;
    // 0x80057850: bgtz        $v0, L_80057950
    if (SIGNED(ctx->r2) > 0) {
        // 0x80057854: addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
            goto L_80057950;
    }
    // 0x80057854: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80057858: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8005785C: lw          $a0, -0x5A2C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5A2C);
    // 0x80057860: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x80057864: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x80057868: lbu         $a3, 0x5F10($a3)
    ctx->r7 = MEM_BU(ctx->r7, 0X5F10);
    // 0x8005786C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80057870: addiu       $v1, $v1, 0x5F10
    ctx->r3 = ADD32(ctx->r3, 0X5F10);
    // 0x80057874: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80057878: beq         $a3, $v0, L_80057954
    if (ctx->r7 == ctx->r2) {
        // 0x8005787C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80057954;
    }
    // 0x8005787C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80057880: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057884: sw          $v0, -0x5A28($at)
    MEM_W(-0X5A28, ctx->r1) = ctx->r2;
    // 0x80057888: addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // 0x8005788C: bne         $a3, $v0, L_800578B4
    if (ctx->r7 != ctx->r2) {
        // 0x80057890: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800578B4;
    }
    // 0x80057890: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80057894: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80057898: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005789C: sw          $v0, -0x5A2C($at)
    MEM_W(-0X5A2C, ctx->r1) = ctx->r2;
    // 0x800578A0: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x800578A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800578A8: sw          $v0, -0x5A28($at)
    MEM_W(-0X5A28, ctx->r1) = ctx->r2;
    // 0x800578AC: j           L_80057954
    // 0x800578B0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80057954;
    // 0x800578B0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800578B4:
    // 0x800578B4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800578B8: addu        $t3, $v1, $zero
    ctx->r11 = ADD32(ctx->r3, 0);
    // 0x800578BC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800578C0: addiu       $t1, $zero, 0xD
    ctx->r9 = ADD32(0, 0XD);
    // 0x800578C4: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800578C8: addiu       $a2, $a2, -0x5D9E
    ctx->r6 = ADD32(ctx->r6, -0X5D9E);
    // 0x800578CC: addiu       $v1, $a2, -0x2
    ctx->r3 = ADD32(ctx->r6, -0X2);
    // 0x800578D0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800578D4:
    // 0x800578D4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800578D8: bnel        $v0, $zero, L_8005793C
    if (ctx->r2 != 0) {
        // 0x800578DC: addiu       $a2, $a2, 0x44
        ctx->r6 = ADD32(ctx->r6, 0X44);
            goto L_8005793C;
    }
    goto skip_0;
    // 0x800578DC: addiu       $a2, $a2, 0x44
    ctx->r6 = ADD32(ctx->r6, 0X44);
    skip_0:
    // 0x800578E0: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
    // 0x800578E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800578E8: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800578EC: sw          $a3, -0x5D94($at)
    MEM_W(-0X5D94, ctx->r1) = ctx->r7;
    // 0x800578F0: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x800578F4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800578F8: lw          $v0, -0x5A2C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5A2C);
    // 0x800578FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80057900: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057904: sw          $v0, -0x5A2C($at)
    MEM_W(-0X5A2C, ctx->r1) = ctx->r2;
    // 0x80057908: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x8005790C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80057910: beql        $v0, $t2, L_80057918
    if (ctx->r2 == ctx->r10) {
        // 0x80057914: sb          $t0, 0x0($a2)
        MEM_B(0X0, ctx->r6) = ctx->r8;
            goto L_80057918;
    }
    goto skip_1;
    // 0x80057914: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
    skip_1:
L_80057918:
    // 0x80057918: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005791C: sw          $t1, -0x5A28($at)
    MEM_W(-0X5A28, ctx->r1) = ctx->r9;
    // 0x80057920: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80057924: addiu       $v0, $v0, -0x5D9E
    ctx->r2 = ADD32(ctx->r2, -0X5D9E);
    // 0x80057928: addiu       $a2, $v0, 0x374
    ctx->r6 = ADD32(ctx->r2, 0X374);
    // 0x8005792C: addiu       $v1, $v0, 0x372
    ctx->r3 = ADD32(ctx->r2, 0X372);
    // 0x80057930: addiu       $a0, $zero, 0x374
    ctx->r4 = ADD32(0, 0X374);
    // 0x80057934: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80057938: addiu       $a2, $a2, 0x44
    ctx->r6 = ADD32(ctx->r6, 0X44);
L_8005793C:
    // 0x8005793C: addiu       $v1, $v1, 0x44
    ctx->r3 = ADD32(ctx->r3, 0X44);
    // 0x80057940: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80057944: slti        $v0, $a1, 0xD
    ctx->r2 = SIGNED(ctx->r5) < 0XD ? 1 : 0;
    // 0x80057948: bne         $v0, $zero, L_800578D4
    if (ctx->r2 != 0) {
        // 0x8005794C: addiu       $a0, $a0, 0x44
        ctx->r4 = ADD32(ctx->r4, 0X44);
            goto L_800578D4;
    }
    // 0x8005794C: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
L_80057950:
    // 0x80057950: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80057954:
    // 0x80057954: jr          $ra
    // 0x80057958: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80057958: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8005795C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005795C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80057960: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80057964: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x80057968: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005796C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80057970: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80057974: lw          $v0, 0x5F70($at)
    ctx->r2 = MEM_W(ctx->r1, 0X5F70);
    // 0x80057978: jalr        $v0
    // 0x8005797C: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8005797C: nop

    after_0:
    // 0x80057980: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80057984: jr          $ra
    // 0x80057988: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80057988: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005798C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005798C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80057990: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80057994: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80057998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005799C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x800579A0: lui         $v0, 0x6F
    ctx->r2 = S32(0X6F << 16);
    // 0x800579A4: addiu       $v0, $v0, -0x3700
    ctx->r2 = ADD32(ctx->r2, -0X3700);
    // 0x800579A8: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x800579AC: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    // 0x800579B0: sll         $a0, $a0, 9
    ctx->r4 = S32(ctx->r4 << 9);
    // 0x800579B4: jal         0x80006D98
    // 0x800579B8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    func_80006D98(rdram, ctx);
        goto after_0;
    // 0x800579B8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_0:
    // 0x800579BC: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x800579C0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800579C4: addiu       $v0, $zero, 0x140
    ctx->r2 = ADD32(0, 0X140);
    // 0x800579C8: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x800579CC: addiu       $v0, $zero, 0xB8
    ctx->r2 = ADD32(0, 0XB8);
    // 0x800579D0: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x800579D4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800579D8: jal         0x800579F0
    // 0x800579DC: sb          $v1, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r3;
    func_800579F0(rdram, ctx);
        goto after_1;
    // 0x800579DC: sb          $v1, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r3;
    after_1:
    // 0x800579E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800579E4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800579E8: jr          $ra
    // 0x800579EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800579EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800579F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800579F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800579F4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800579F8: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800579FC: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x80057A00: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x80057A04: slti        $v0, $v0, -0x1B
    ctx->r2 = SIGNED(ctx->r2) < -0X1B ? 1 : 0;
    // 0x80057A08: beq         $v0, $zero, L_80057A1C
    if (ctx->r2 == 0) {
        // 0x80057A0C: nop
    
            goto L_80057A1C;
    }
    // 0x80057A0C: nop

    // 0x80057A10: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x80057A14: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80057A18: sb          $v0, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r2;
L_80057A1C:
    // 0x80057A1C: lw          $a1, 0x10($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X10);
    // 0x80057A20: lw          $a2, 0x14($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X14);
    // 0x80057A24: jal         0x80057A68
    // 0x80057A28: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80057A68(rdram, ctx);
        goto after_0;
    // 0x80057A28: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x80057A2C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80057A30: jr          $ra
    // 0x80057A34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80057A34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80057A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057A38: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x80057A3C: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80057A40: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    // 0x80057A44: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
    // 0x80057A48: sb          $zero, 0x6($a0)
    MEM_B(0X6, ctx->r4) = 0;
    // 0x80057A4C: beq         $v0, $zero, L_80057A60
    if (ctx->r2 == 0) {
        // 0x80057A50: sb          $zero, 0x7($a0)
        MEM_B(0X7, ctx->r4) = 0;
            goto L_80057A60;
    }
    // 0x80057A50: sb          $zero, 0x7($a0)
    MEM_B(0X7, ctx->r4) = 0;
    // 0x80057A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80057A58: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057A5C: sw          $v0, -0x33D0($at)
    MEM_W(-0X33D0, ctx->r1) = ctx->r2;
L_80057A60:
    // 0x80057A60: jr          $ra
    // 0x80057A64: nop

    return;
    // 0x80057A64: nop

;}
RECOMP_FUNC void func_80057A68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057A68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80057A6C: addu        $t8, $a0, $zero
    ctx->r24 = ADD32(ctx->r4, 0);
    // 0x80057A70: addu        $t5, $a1, $zero
    ctx->r13 = ADD32(ctx->r5, 0);
    // 0x80057A74: addu        $t6, $a2, $zero
    ctx->r14 = ADD32(ctx->r6, 0);
    // 0x80057A78: lui         $v1, 0xBA00
    ctx->r3 = S32(0XBA00 << 16);
    // 0x80057A7C: ori         $v1, $v1, 0x1402
    ctx->r3 = ctx->r3 | 0X1402;
    // 0x80057A80: lui         $a1, 0xFCFF
    ctx->r5 = S32(0XFCFF << 16);
    // 0x80057A84: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80057A88: lui         $a0, 0xFFFC
    ctx->r4 = S32(0XFFFC << 16);
    // 0x80057A8C: ori         $a0, $a0, 0xF279
    ctx->r4 = ctx->r4 | 0XF279;
    // 0x80057A90: lui         $a2, 0xBA00
    ctx->r6 = S32(0XBA00 << 16);
    // 0x80057A94: ori         $a2, $a2, 0x1301
    ctx->r6 = ctx->r6 | 0X1301;
    // 0x80057A98: lui         $t0, 0xB900
    ctx->r8 = S32(0XB900 << 16);
    // 0x80057A9C: ori         $t0, $t0, 0x31D
    ctx->r8 = ctx->r8 | 0X31D;
    // 0x80057AA0: lui         $a3, 0xF0A
    ctx->r7 = S32(0XF0A << 16);
    // 0x80057AA4: ori         $a3, $a3, 0x7008
    ctx->r7 = ctx->r7 | 0X7008;
    // 0x80057AA8: lui         $t1, 0xBA00
    ctx->r9 = S32(0XBA00 << 16);
    // 0x80057AAC: ori         $t1, $t1, 0xE02
    ctx->r9 = ctx->r9 | 0XE02;
    // 0x80057AB0: lui         $t2, 0xF500
    ctx->r10 = S32(0XF500 << 16);
    // 0x80057AB4: ori         $t2, $t2, 0x100
    ctx->r10 = ctx->r10 | 0X100;
    // 0x80057AB8: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80057ABC: lw          $t4, 0x2FE4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2FE4);
    // 0x80057AC0: lui         $t3, 0x703
    ctx->r11 = S32(0X703 << 16);
    // 0x80057AC4: ori         $t3, $t3, 0xC000
    ctx->r11 = ctx->r11 | 0XC000;
    // 0x80057AC8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80057ACC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80057AD0: addiu       $v0, $t4, 0x8
    ctx->r2 = ADD32(ctx->r12, 0X8);
    // 0x80057AD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057AD8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057ADC: addiu       $v0, $t4, 0x10
    ctx->r2 = ADD32(ctx->r12, 0X10);
    // 0x80057AE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057AE4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057AE8: addiu       $v0, $t4, 0x18
    ctx->r2 = ADD32(ctx->r12, 0X18);
    // 0x80057AEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057AF0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057AF4: addiu       $v0, $t4, 0x20
    ctx->r2 = ADD32(ctx->r12, 0X20);
    // 0x80057AF8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057AFC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057B00: addiu       $v0, $t4, 0x28
    ctx->r2 = ADD32(ctx->r12, 0X28);
    // 0x80057B04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057B08: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057B0C: addiu       $v0, $t4, 0x30
    ctx->r2 = ADD32(ctx->r12, 0X30);
    // 0x80057B10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057B14: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057B18: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80057B1C: sw          $v0, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->r2;
    // 0x80057B20: addiu       $v0, $t4, 0x38
    ctx->r2 = ADD32(ctx->r12, 0X38);
    // 0x80057B24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057B28: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057B2C: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x80057B30: sw          $v0, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r2;
    // 0x80057B34: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80057B38: addiu       $v0, $v0, 0x5F7C
    ctx->r2 = ADD32(ctx->r2, 0X5F7C);
    // 0x80057B3C: sw          $v0, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->r2;
    // 0x80057B40: addiu       $v0, $t4, 0x40
    ctx->r2 = ADD32(ctx->r12, 0X40);
    // 0x80057B44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057B48: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057B4C: lui         $v0, 0xE800
    ctx->r2 = S32(0XE800 << 16);
    // 0x80057B50: sw          $v0, 0x38($t4)
    MEM_W(0X38, ctx->r12) = ctx->r2;
    // 0x80057B54: addiu       $v0, $t4, 0x48
    ctx->r2 = ADD32(ctx->r12, 0X48);
    // 0x80057B58: sw          $t0, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->r8;
    // 0x80057B5C: lui         $t0, 0x700
    ctx->r8 = S32(0X700 << 16);
    // 0x80057B60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057B64: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057B68: addiu       $v0, $t4, 0x50
    ctx->r2 = ADD32(ctx->r12, 0X50);
    // 0x80057B6C: sw          $a3, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r7;
    // 0x80057B70: lui         $a3, 0xE600
    ctx->r7 = S32(0XE600 << 16);
    // 0x80057B74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057B78: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057B7C: addiu       $v0, $t4, 0x58
    ctx->r2 = ADD32(ctx->r12, 0X58);
    // 0x80057B80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057B84: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057B88: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x80057B8C: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x80057B90: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x80057B94: sw          $v1, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r3;
    // 0x80057B98: sw          $zero, 0xC($t4)
    MEM_W(0XC, ctx->r12) = 0;
    // 0x80057B9C: sw          $a1, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r5;
    // 0x80057BA0: sw          $a0, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r4;
    // 0x80057BA4: sw          $a2, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r6;
    // 0x80057BA8: sw          $zero, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = 0;
    // 0x80057BAC: sw          $t1, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->r9;
    // 0x80057BB0: sw          $zero, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = 0;
    // 0x80057BB4: sw          $t2, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->r10;
    // 0x80057BB8: sw          $t0, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->r8;
    // 0x80057BBC: sw          $a3, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->r7;
    // 0x80057BC0: sw          $zero, 0x4C($t4)
    MEM_W(0X4C, ctx->r12) = 0;
    // 0x80057BC4: sw          $v0, 0x50($t4)
    MEM_W(0X50, ctx->r12) = ctx->r2;
    // 0x80057BC8: addiu       $v0, $t4, 0x60
    ctx->r2 = ADD32(ctx->r12, 0X60);
    // 0x80057BCC: addiu       $a0, $t5, 0x1B
    ctx->r4 = ADD32(ctx->r13, 0X1B);
    // 0x80057BD0: srl         $a0, $a0, 31
    ctx->r4 = S32(U32(ctx->r4) >> 31);
    // 0x80057BD4: sw          $t3, 0x54($t4)
    MEM_W(0X54, ctx->r12) = ctx->r11;
    // 0x80057BD8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057BDC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057BE0: slti        $v0, $t5, 0x140
    ctx->r2 = SIGNED(ctx->r13) < 0X140 ? 1 : 0;
    // 0x80057BE4: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80057BE8: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80057BEC: addiu       $v1, $t6, 0x20
    ctx->r3 = ADD32(ctx->r14, 0X20);
    // 0x80057BF0: slti        $v1, $v1, 0x1
    ctx->r3 = SIGNED(ctx->r3) < 0X1 ? 1 : 0;
    // 0x80057BF4: slti        $v0, $t6, 0xF0
    ctx->r2 = SIGNED(ctx->r14) < 0XF0 ? 1 : 0;
    // 0x80057BF8: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80057BFC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80057C00: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x80057C04: sw          $t7, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->r15;
    // 0x80057C08: bne         $a0, $zero, L_80057CD4
    if (ctx->r4 != 0) {
        // 0x80057C0C: sw          $zero, 0x5C($t4)
        MEM_W(0X5C, ctx->r12) = 0;
            goto L_80057CD4;
    }
    // 0x80057C0C: sw          $zero, 0x5C($t4)
    MEM_W(0X5C, ctx->r12) = 0;
    // 0x80057C10: lui         $v1, 0x70F
    ctx->r3 = S32(0X70F << 16);
    // 0x80057C14: ori         $v1, $v1, 0xF400
    ctx->r3 = ctx->r3 | 0XF400;
    // 0x80057C18: lui         $a0, 0xF540
    ctx->r4 = S32(0XF540 << 16);
    // 0x80057C1C: ori         $a0, $a0, 0x400
    ctx->r4 = ctx->r4 | 0X400;
    // 0x80057C20: lui         $a2, 0x7
    ctx->r6 = S32(0X7 << 16);
    // 0x80057C24: lui         $v0, 0xFD50
    ctx->r2 = S32(0XFD50 << 16);
    // 0x80057C28: sw          $v0, 0x60($t4)
    MEM_W(0X60, ctx->r12) = ctx->r2;
    // 0x80057C2C: lw          $a1, 0x18($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X18);
    // 0x80057C30: ori         $a2, $a2, 0xC07C
    ctx->r6 = ctx->r6 | 0XC07C;
    // 0x80057C34: addiu       $v0, $t4, 0x68
    ctx->r2 = ADD32(ctx->r12, 0X68);
    // 0x80057C38: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057C3C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057C40: addiu       $v0, $t4, 0x70
    ctx->r2 = ADD32(ctx->r12, 0X70);
    // 0x80057C44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057C48: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057C4C: lui         $v0, 0xF550
    ctx->r2 = S32(0XF550 << 16);
    // 0x80057C50: sw          $v0, 0x68($t4)
    MEM_W(0X68, ctx->r12) = ctx->r2;
    // 0x80057C54: addiu       $v0, $t4, 0x78
    ctx->r2 = ADD32(ctx->r12, 0X78);
    // 0x80057C58: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057C5C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057C60: addiu       $v0, $t4, 0x80
    ctx->r2 = ADD32(ctx->r12, 0X80);
    // 0x80057C64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057C68: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057C6C: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x80057C70: sw          $v0, 0x78($t4)
    MEM_W(0X78, ctx->r12) = ctx->r2;
    // 0x80057C74: addiu       $v0, $t4, 0x88
    ctx->r2 = ADD32(ctx->r12, 0X88);
    // 0x80057C78: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057C7C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057C80: addiu       $v0, $t4, 0x90
    ctx->r2 = ADD32(ctx->r12, 0X90);
    // 0x80057C84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057C88: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057C8C: addiu       $v0, $t4, 0x98
    ctx->r2 = ADD32(ctx->r12, 0X98);
    // 0x80057C90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057C94: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057C98: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x80057C9C: sw          $a0, 0x88($t4)
    MEM_W(0X88, ctx->r12) = ctx->r4;
    // 0x80057CA0: addu        $a0, $t5, $zero
    ctx->r4 = ADD32(ctx->r13, 0);
    // 0x80057CA4: sw          $t0, 0x6C($t4)
    MEM_W(0X6C, ctx->r12) = ctx->r8;
    // 0x80057CA8: sw          $a3, 0x70($t4)
    MEM_W(0X70, ctx->r12) = ctx->r7;
    // 0x80057CAC: sw          $zero, 0x74($t4)
    MEM_W(0X74, ctx->r12) = 0;
    // 0x80057CB0: sw          $v1, 0x7C($t4)
    MEM_W(0X7C, ctx->r12) = ctx->r3;
    // 0x80057CB4: sw          $t7, 0x80($t4)
    MEM_W(0X80, ctx->r12) = ctx->r15;
    // 0x80057CB8: sw          $zero, 0x84($t4)
    MEM_W(0X84, ctx->r12) = 0;
    // 0x80057CBC: sw          $zero, 0x8C($t4)
    MEM_W(0X8C, ctx->r12) = 0;
    // 0x80057CC0: sw          $v0, 0x90($t4)
    MEM_W(0X90, ctx->r12) = ctx->r2;
    // 0x80057CC4: sw          $a2, 0x94($t4)
    MEM_W(0X94, ctx->r12) = ctx->r6;
    // 0x80057CC8: sw          $a1, 0x64($t4)
    MEM_W(0X64, ctx->r12) = ctx->r5;
    // 0x80057CCC: jal         0x80057CE0
    // 0x80057CD0: addu        $a1, $t6, $zero
    ctx->r5 = ADD32(ctx->r14, 0);
    func_80057CE0(rdram, ctx);
        goto after_0;
    // 0x80057CD0: addu        $a1, $t6, $zero
    ctx->r5 = ADD32(ctx->r14, 0);
    after_0:
L_80057CD4:
    // 0x80057CD4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80057CD8: jr          $ra
    // 0x80057CDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80057CDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80057CE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057CE0: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80057CE4: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x80057CE8: addiu       $v1, $zero, 0x1B
    ctx->r3 = ADD32(0, 0X1B);
    // 0x80057CEC: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80057CF0: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x80057CF4: bgez        $a3, L_80057D14
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80057CF8: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_80057D14;
    }
    // 0x80057CF8: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x80057CFC: addiu       $v1, $a3, 0x1B
    ctx->r3 = ADD32(ctx->r7, 0X1B);
    // 0x80057D00: bgez        $a3, L_80057D0C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80057D04: addu        $t1, $a3, $zero
        ctx->r9 = ADD32(ctx->r7, 0);
            goto L_80057D0C;
    }
    // 0x80057D04: addu        $t1, $a3, $zero
    ctx->r9 = ADD32(ctx->r7, 0);
    // 0x80057D08: negu        $t1, $t1
    ctx->r9 = SUB32(0, ctx->r9);
L_80057D0C:
    // 0x80057D0C: j           L_80057D28
    // 0x80057D10: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_80057D28;
    // 0x80057D10: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_80057D14:
    // 0x80057D14: addiu       $v0, $a3, 0x1B
    ctx->r2 = ADD32(ctx->r7, 0X1B);
    // 0x80057D18: slti        $v0, $v0, 0x140
    ctx->r2 = SIGNED(ctx->r2) < 0X140 ? 1 : 0;
    // 0x80057D1C: bne         $v0, $zero, L_80057D28
    if (ctx->r2 != 0) {
        // 0x80057D20: addiu       $v0, $zero, 0x140
        ctx->r2 = ADD32(0, 0X140);
            goto L_80057D28;
    }
    // 0x80057D20: addiu       $v0, $zero, 0x140
    ctx->r2 = ADD32(0, 0X140);
    // 0x80057D24: subu        $v1, $v0, $a3
    ctx->r3 = SUB32(ctx->r2, ctx->r7);
L_80057D28:
    // 0x80057D28: bgez        $t0, L_80057D48
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80057D2C: addiu       $v0, $t0, 0x20
        ctx->r2 = ADD32(ctx->r8, 0X20);
            goto L_80057D48;
    }
    // 0x80057D2C: addiu       $v0, $t0, 0x20
    ctx->r2 = ADD32(ctx->r8, 0X20);
    // 0x80057D30: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x80057D34: bgez        $t0, L_80057D40
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80057D38: addu        $t2, $t0, $zero
        ctx->r10 = ADD32(ctx->r8, 0);
            goto L_80057D40;
    }
    // 0x80057D38: addu        $t2, $t0, $zero
    ctx->r10 = ADD32(ctx->r8, 0);
    // 0x80057D3C: negu        $t2, $t2
    ctx->r10 = SUB32(0, ctx->r10);
L_80057D40:
    // 0x80057D40: j           L_80057D58
    // 0x80057D44: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
        goto L_80057D58;
    // 0x80057D44: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
L_80057D48:
    // 0x80057D48: slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // 0x80057D4C: bne         $v0, $zero, L_80057D58
    if (ctx->r2 != 0) {
        // 0x80057D50: addiu       $v0, $zero, 0xF0
        ctx->r2 = ADD32(0, 0XF0);
            goto L_80057D58;
    }
    // 0x80057D50: addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // 0x80057D54: subu        $a0, $v0, $t0
    ctx->r4 = SUB32(ctx->r2, ctx->r8);
L_80057D58:
    // 0x80057D58: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80057D5C: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x80057D60: lui         $a2, 0x400
    ctx->r6 = S32(0X400 << 16);
    // 0x80057D64: ori         $a2, $a2, 0x400
    ctx->r6 = ctx->r6 | 0X400;
    // 0x80057D68: addu        $v1, $a3, $v1
    ctx->r3 = ADD32(ctx->r7, ctx->r3);
    // 0x80057D6C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80057D70: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80057D74: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x80057D78: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80057D7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057D80: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057D84: addu        $v0, $t0, $a0
    ctx->r2 = ADD32(ctx->r8, ctx->r4);
    // 0x80057D88: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80057D8C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80057D90: lui         $a0, 0xE400
    ctx->r4 = S32(0XE400 << 16);
    // 0x80057D94: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x80057D98: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80057D9C: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x80057DA0: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80057DA4: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x80057DA8: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80057DAC: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x80057DB0: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80057DB4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80057DB8: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80057DBC: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x80057DC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057DC4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057DC8: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x80057DCC: sll         $v1, $t1, 21
    ctx->r3 = S32(ctx->r9 << 21);
    // 0x80057DD0: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x80057DD4: sll         $v0, $t2, 5
    ctx->r2 = S32(ctx->r10 << 5);
    // 0x80057DD8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80057DDC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80057DE0: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x80057DE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057DE8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80057DEC: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x80057DF0: sw          $v1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r3;
    // 0x80057DF4: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80057DF8: jr          $ra
    // 0x80057DFC: sw          $a2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r6;
    return;
    // 0x80057DFC: sw          $a2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r6;
;}
RECOMP_FUNC void func_80057E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80057E74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80057EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057EF0: andi        $a2, $a2, 0xFFFE
    ctx->r6 = ctx->r6 & 0XFFFE;
    // 0x80057EF4: beq         $a2, $zero, L_80057F14
    if (ctx->r6 == 0) {
        // 0x80057EF8: addiu       $a2, $a2, -0x2
        ctx->r6 = ADD32(ctx->r6, -0X2);
            goto L_80057F14;
    }
L_80057EF8:
    // 0x80057EF8: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x80057EFC: lhu         $t0, 0x0($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X0);
    // 0x80057F00: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80057F04: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80057F08: sh          $t0, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r8;
    // 0x80057F0C: bne         $a2, $zero, L_80057EF8
    if (ctx->r6 != 0) {
        // 0x80057F10: sh          $t0, -0x2($a0)
        MEM_H(-0X2, ctx->r4) = ctx->r8;
            goto L_80057EF8;
    }
    // 0x80057F10: sh          $t0, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r8;
L_80057F14:
    // 0x80057F14: jr          $ra
    // 0x80057F18: nop

    return;
    // 0x80057F18: nop

;}
RECOMP_FUNC void func_80057F1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057F1C: andi        $a2, $a2, 0xFFFE
    ctx->r6 = ctx->r6 & 0XFFFE;
    // 0x80057F20: beq         $a2, $zero, L_80057F68
    if (ctx->r6 == 0) {
        // 0x80057F24: addiu       $a2, $a2, -0x2
        ctx->r6 = ADD32(ctx->r6, -0X2);
            goto L_80057F68;
    }
L_80057F24:
    // 0x80057F24: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x80057F28: addi        $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
L_80057F2C:
    // 0x80057F2C: bne         $t1, $zero, L_80057F2C
    if (ctx->r9 != 0) {
        // 0x80057F30: addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
            goto L_80057F2C;
    }
    // 0x80057F30: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80057F34: lhu         $t0, 0x0($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X0);
    // 0x80057F38: addi        $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
L_80057F3C:
    // 0x80057F3C: bne         $t1, $zero, L_80057F3C
    if (ctx->r9 != 0) {
        // 0x80057F40: addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
            goto L_80057F3C;
    }
    // 0x80057F40: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80057F44: lhu         $t0, 0x0($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X0);
    // 0x80057F48: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80057F4C: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x80057F50: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80057F54: addi        $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
L_80057F58:
    // 0x80057F58: bne         $t1, $zero, L_80057F58
    if (ctx->r9 != 0) {
        // 0x80057F5C: addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
            goto L_80057F58;
    }
    // 0x80057F5C: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80057F60: bne         $a2, $zero, L_80057F24
    if (ctx->r6 != 0) {
        // 0x80057F64: nop
    
            goto L_80057F24;
    }
    // 0x80057F64: nop

L_80057F68:
    // 0x80057F68: jr          $ra
    // 0x80057F6C: nop

    return;
    // 0x80057F6C: nop

;}
RECOMP_FUNC void func_80057F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057F70: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
    // 0x80057F74: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x80057F78: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
L_80057F7C:
    // 0x80057F7C: bne         $t0, $zero, L_80057F7C
    if (ctx->r8 != 0) {
        // 0x80057F80: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80057F7C;
    }
    // 0x80057F80: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80057F84: jr          $ra
    // 0x80057F88: nop

    return;
    // 0x80057F88: nop

;}
RECOMP_FUNC void func_80057F8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057F8C: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
L_80057F90:
    // 0x80057F90: bne         $t0, $zero, L_80057F90
    if (ctx->r8 != 0) {
        // 0x80057F94: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80057F90;
    }
    // 0x80057F94: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80057F98: lhu         $v0, 0x0($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X0);
    // 0x80057F9C: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
L_80057FA0:
    // 0x80057FA0: bne         $t0, $zero, L_80057FA0
    if (ctx->r8 != 0) {
        // 0x80057FA4: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80057FA0;
    }
    // 0x80057FA4: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80057FA8: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80057FAC: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
L_80057FB0:
    // 0x80057FB0: bne         $t0, $zero, L_80057FB0
    if (ctx->r8 != 0) {
        // 0x80057FB4: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80057FB0;
    }
    // 0x80057FB4: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80057FB8: jr          $ra
    // 0x80057FBC: nop

    return;
    // 0x80057FBC: nop

;}
RECOMP_FUNC void func_80057FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057FC0: andi        $a2, $a2, 0xFFFE
    ctx->r6 = ctx->r6 & 0XFFFE;
    // 0x80057FC4: beq         $a2, $zero, L_80057FE0
    if (ctx->r6 == 0) {
        // 0x80057FC8: lhu         $t0, 0x0($sp)
        ctx->r8 = MEM_HU(ctx->r29, 0X0);
            goto L_80057FE0;
    }
L_80057FC8:
    // 0x80057FC8: lhu         $t0, 0x0($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X0);
    // 0x80057FCC: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x80057FD0: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80057FD4: sh          $a1, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r5;
    // 0x80057FD8: bne         $a2, $zero, L_80057FC8
    if (ctx->r6 != 0) {
        // 0x80057FDC: sh          $a1, -0x2($a0)
        MEM_H(-0X2, ctx->r4) = ctx->r5;
            goto L_80057FC8;
    }
    // 0x80057FDC: sh          $a1, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r5;
L_80057FE0:
    // 0x80057FE0: jr          $ra
    // 0x80057FE4: nop

    return;
    // 0x80057FE4: nop

;}
RECOMP_FUNC void func_80057FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057FF0: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80057FF4: addi        $at, $zero, 0xB0B
    ctx->r1 = ADD32(0, 0XB0B);
    // 0x80057FF8: sh          $at, 0x44($v1)
    MEM_H(0X44, ctx->r3) = ctx->r1;
    // 0x80057FFC: addi        $at, $zero, 0x780
    ctx->r1 = ADD32(0, 0X780);
L_80058000:
    // 0x80058000: addiu       $at, $at, -0x1
    ctx->r1 = ADD32(ctx->r1, -0X1);
    // 0x80058004: bne         $at, $zero, L_80058000
    if (ctx->r1 != 0) {
        // 0x80058008: nop
    
            goto L_80058000;
    }
    // 0x80058008: nop

    // 0x8005800C: sh          $zero, 0x42($v1)
    MEM_H(0X42, ctx->r3) = 0;
    // 0x80058010: addi        $at, $zero, 0x780
    ctx->r1 = ADD32(0, 0X780);
L_80058014:
    // 0x80058014: addiu       $at, $at, -0x1
    ctx->r1 = ADD32(ctx->r1, -0X1);
    // 0x80058018: bne         $at, $zero, L_80058014
    if (ctx->r1 != 0) {
        // 0x8005801C: nop
    
            goto L_80058014;
    }
    // 0x8005801C: nop

    // 0x80058020: sh          $zero, 0x42($v1)
    MEM_H(0X42, ctx->r3) = 0;
    // 0x80058024: addi        $at, $zero, 0x780
    ctx->r1 = ADD32(0, 0X780);
L_80058028:
    // 0x80058028: addiu       $at, $at, -0x1
    ctx->r1 = ADD32(ctx->r1, -0X1);
    // 0x8005802C: bne         $at, $zero, L_80058028
    if (ctx->r1 != 0) {
        // 0x80058030: nop
    
            goto L_80058028;
    }
    // 0x80058030: nop

    // 0x80058034: sh          $zero, 0x42($v1)
    MEM_H(0X42, ctx->r3) = 0;
    // 0x80058038: addi        $at, $zero, 0x780
    ctx->r1 = ADD32(0, 0X780);
L_8005803C:
    // 0x8005803C: addiu       $at, $at, -0x1
    ctx->r1 = ADD32(ctx->r1, -0X1);
    // 0x80058040: bne         $at, $zero, L_8005803C
    if (ctx->r1 != 0) {
        // 0x80058044: nop
    
            goto L_8005803C;
    }
    // 0x80058044: nop

    // 0x80058048: addi        $at, $zero, 0x4040
    ctx->r1 = ADD32(0, 0X4040);
    // 0x8005804C: sh          $at, 0x42($v1)
    MEM_H(0X42, ctx->r3) = ctx->r1;
    // 0x80058050: addi        $at, $zero, 0x780
    ctx->r1 = ADD32(0, 0X780);
L_80058054:
    // 0x80058054: addiu       $at, $at, -0x1
    ctx->r1 = ADD32(ctx->r1, -0X1);
    // 0x80058058: bne         $at, $zero, L_80058054
    if (ctx->r1 != 0) {
        // 0x8005805C: nop
    
            goto L_80058054;
    }
    // 0x8005805C: nop

    // 0x80058060: addi        $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x80058064: sh          $at, 0x42($v1)
    MEM_H(0X42, ctx->r3) = ctx->r1;
    // 0x80058068: addi        $at, $zero, 0x780
    ctx->r1 = ADD32(0, 0X780);
L_8005806C:
    // 0x8005806C: addiu       $at, $at, -0x1
    ctx->r1 = ADD32(ctx->r1, -0X1);
    // 0x80058070: bne         $at, $zero, L_8005806C
    if (ctx->r1 != 0) {
        // 0x80058074: nop
    
            goto L_8005806C;
    }
    // 0x80058074: nop

    // 0x80058078: addi        $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x8005807C: sh          $at, 0x42($v1)
    MEM_H(0X42, ctx->r3) = ctx->r1;
    // 0x80058080: addi        $at, $zero, 0xF04
    ctx->r1 = ADD32(0, 0XF04);
    // 0x80058084: sh          $at, 0x44($v1)
    MEM_H(0X44, ctx->r3) = ctx->r1;
    // 0x80058088: addi        $at, $zero, 0x780
    ctx->r1 = ADD32(0, 0X780);
L_8005808C:
    // 0x8005808C: addiu       $at, $at, -0x1
    ctx->r1 = ADD32(ctx->r1, -0X1);
    // 0x80058090: bne         $at, $zero, L_8005808C
    if (ctx->r1 != 0) {
        // 0x80058094: nop
    
            goto L_8005808C;
    }
    // 0x80058094: nop

    // 0x80058098: jr          $ra
    // 0x8005809C: nop

    return;
    // 0x8005809C: nop

;}
RECOMP_FUNC void func_800580A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800580A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800580A4: sw          $at, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r1;
    // 0x800580A8: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800580AC: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x800580B0: lui         $s1, 0x200
    ctx->r17 = S32(0X200 << 16);
    // 0x800580B4: addi        $s0, $zero, 0x3E8
    ctx->r16 = ADD32(0, 0X3E8);
L_800580B8:
    // 0x800580B8: lhu         $v0, 0x42($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X42);
    // 0x800580BC: nop

    // 0x800580C0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800580C4: beq         $v0, $zero, L_800580E4
    if (ctx->r2 == 0) {
        // 0x800580C8: addi        $at, $zero, 0xF0
        ctx->r1 = ADD32(0, 0XF0);
            goto L_800580E4;
    }
    // 0x800580C8: addi        $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
L_800580CC:
    // 0x800580CC: addiu       $at, $at, -0x1
    ctx->r1 = ADD32(ctx->r1, -0X1);
    // 0x800580D0: bne         $at, $zero, L_800580CC
    if (ctx->r1 != 0) {
        // 0x800580D4: nop
    
            goto L_800580CC;
    }
    // 0x800580D4: nop

    // 0x800580D8: addi        $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    // 0x800580DC: b           L_80058100
    // 0x800580E0: sh          $a0, 0x40($s1)
    MEM_H(0X40, ctx->r17) = ctx->r4;
        goto L_80058100;
    // 0x800580E0: sh          $a0, 0x40($s1)
    MEM_H(0X40, ctx->r17) = ctx->r4;
L_800580E4:
    // 0x800580E4: addi        $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
L_800580E8:
    // 0x800580E8: addiu       $at, $at, -0x1
    ctx->r1 = ADD32(ctx->r1, -0X1);
    // 0x800580EC: bne         $at, $zero, L_800580E8
    if (ctx->r1 != 0) {
        // 0x800580F0: nop
    
            goto L_800580E8;
    }
    // 0x800580F0: nop

    // 0x800580F4: bne         $s0, $zero, L_800580B8
    if (ctx->r16 != 0) {
        // 0x800580F8: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_800580B8;
    }
    // 0x800580F8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800580FC: addi        $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80058100:
    // 0x80058100: addi        $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
L_80058104:
    // 0x80058104: addiu       $at, $at, -0x1
    ctx->r1 = ADD32(ctx->r1, -0X1);
    // 0x80058108: bne         $at, $zero, L_80058104
    if (ctx->r1 != 0) {
        // 0x8005810C: nop
    
            goto L_80058104;
    }
    // 0x8005810C: nop

    // 0x80058110: lw          $at, 0x0($sp)
    ctx->r1 = MEM_W(ctx->r29, 0X0);
    // 0x80058114: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80058118: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x8005811C: jr          $ra
    // 0x80058120: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80058120: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80058124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058124: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80058128: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
    // 0x8005812C: lui         $t0, 0x200
    ctx->r8 = S32(0X200 << 16);
    // 0x80058130: addi        $v1, $zero, 0x3E8
    ctx->r3 = ADD32(0, 0X3E8);
L_80058134:
    // 0x80058134: lhu         $v0, 0x42($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X42);
    // 0x80058138: nop

    // 0x8005813C: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80058140: beq         $v0, $zero, L_80058160
    if (ctx->r2 == 0) {
        // 0x80058144: addi        $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_80058160;
    }
    // 0x80058144: addi        $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
L_80058148:
    // 0x80058148: addiu       $at, $at, -0x1
    ctx->r1 = ADD32(ctx->r1, -0X1);
    // 0x8005814C: bne         $at, $zero, L_80058148
    if (ctx->r1 != 0) {
        // 0x80058150: nop
    
            goto L_80058148;
    }
    // 0x80058150: nop

    // 0x80058154: lhu         $v0, 0x40($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X40);
    // 0x80058158: b           L_8005817C
    // 0x8005815C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_8005817C;
    // 0x8005815C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_80058160:
    // 0x80058160: addi        $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
L_80058164:
    // 0x80058164: addiu       $at, $at, -0x1
    ctx->r1 = ADD32(ctx->r1, -0X1);
    // 0x80058168: bne         $at, $zero, L_80058164
    if (ctx->r1 != 0) {
        // 0x8005816C: nop
    
            goto L_80058164;
    }
    // 0x8005816C: nop

    // 0x80058170: bne         $v1, $zero, L_80058134
    if (ctx->r3 != 0) {
        // 0x80058174: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_80058134;
    }
    // 0x80058174: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80058178: addi        $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8005817C:
    // 0x8005817C: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x80058180: jr          $ra
    // 0x80058184: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80058184: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80058188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058188: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x8005818C: lhu         $v0, 0x40($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X40);
    // 0x80058190: jr          $ra
    // 0x80058194: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    return;
    // 0x80058194: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
;}
RECOMP_FUNC void func_80058198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058198: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x8005819C: jr          $ra
    // 0x800581A0: lhu         $v0, 0x42($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X42);
    return;
    // 0x800581A0: lhu         $v0, 0x42($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X42);
;}
RECOMP_FUNC void func_800581A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_800581A4:
    // 0x800581A4: addi        $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
L_800581A8:
    // 0x800581A8: addiu       $at, $at, -0x1
    ctx->r1 = ADD32(ctx->r1, -0X1);
    // 0x800581AC: bne         $at, $zero, L_800581A8
    if (ctx->r1 != 0) {
        // 0x800581B0: nop
    
            goto L_800581A8;
    }
    // 0x800581B0: nop

    // 0x800581B4: bne         $a0, $zero, L_800581A4
    if (ctx->r4 != 0) {
        // 0x800581B8: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_800581A4;
    }
    // 0x800581B8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800581BC: jr          $ra
    // 0x800581C0: nop

    return;
    // 0x800581C0: nop

;}
RECOMP_FUNC void func_800581D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800581D0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800581D4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800581D8: lui         $s1, 0x8
    ctx->r17 = S32(0X8 << 16);
    // 0x800581DC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800581E0: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800581E4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800581E8: addiu       $s2, $zero, 0x20
    ctx->r18 = ADD32(0, 0X20);
    // 0x800581EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800581F0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800581F4: addiu       $v0, $zero, 0x2000
    ctx->r2 = ADD32(0, 0X2000);
    // 0x800581F8: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800581FC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80058200: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80058204: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80058208:
    // 0x80058208: srl         $v0, $s1, 31
    ctx->r2 = S32(U32(ctx->r17) >> 31);
    // 0x8005820C: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x80058210: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80058214: sll         $v0, $v0, 13
    ctx->r2 = S32(ctx->r2 << 13);
    // 0x80058218: or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
    // 0x8005821C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80058220: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80058224: jal         0x80057E74
    // 0x80058228: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_80057E74(rdram, ctx);
        goto after_0;
    // 0x80058228: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x8005822C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80058230: slt         $v0, $s0, $s2
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80058234: bne         $v0, $zero, L_80058208
    if (ctx->r2 != 0) {
        // 0x80058238: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80058208;
    }
    // 0x80058238: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005823C: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80058240: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80058244: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80058248: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005824C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80058250: jr          $ra
    // 0x80058254: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80058254: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
