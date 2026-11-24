#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80005680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005680: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80005684: lbu         $v0, 0x38D0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X38D0);
    // 0x80005688: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000568C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80005690: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x80005694: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80005698: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000569C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800056A0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800056A4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800056A8: bne         $v0, $zero, L_80005780
    if (ctx->r2 != 0) {
        // 0x800056AC: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80005780;
    }
    // 0x800056AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800056B0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800056B4: addiu       $s4, $zero, 0x400
    ctx->r20 = ADD32(0, 0X400);
    // 0x800056B8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800056BC: addiu       $v0, $v0, 0x38E0
    ctx->r2 = ADD32(ctx->r2, 0X38E0);
    // 0x800056C0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800056C4: addiu       $s3, $s0, 0x14
    ctx->r19 = ADD32(ctx->r16, 0X14);
    // 0x800056C8: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800056CC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800056D0: sw          $s0, 0x38D8($at)
    MEM_W(0X38D8, ctx->r1) = ctx->r16;
    // 0x800056D4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800056D8: sw          $zero, 0x38D4($at)
    MEM_W(0X38D4, ctx->r1) = 0;
    // 0x800056DC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800056E0: sw          $zero, 0x38E4($at)
    MEM_W(0X38E4, ctx->r1) = 0;
    // 0x800056E4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_800056E8:
    // 0x800056E8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800056EC: jal         0x8006551C
    // 0x800056F0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8006551C(rdram, ctx);
        goto after_0;
    // 0x800056F0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800056F4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800056F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800056FC: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80005700: addiu       $a2, $a2, -0x3470
    ctx->r6 = ADD32(ctx->r6, -0X3470);
    // 0x80005704: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80005708: jal         0x800655B0
    // 0x8000570C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    func_800655B0(rdram, ctx);
        goto after_1;
    // 0x8000570C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_1:
    // 0x80005710: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80005714: addiu       $s3, $s3, 0x14
    ctx->r19 = ADD32(ctx->r19, 0X14);
    // 0x80005718: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000571C: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x80005720: sw          $v0, 0x38F0($at)
    MEM_W(0X38F0, ctx->r1) = ctx->r2;
    // 0x80005724: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80005728: slti        $v0, $s1, 0x3F
    ctx->r2 = SIGNED(ctx->r17) < 0X3F ? 1 : 0;
    // 0x8000572C: bne         $v0, $zero, L_800056E8
    if (ctx->r2 != 0) {
        // 0x80005730: addiu       $s2, $s2, 0x14
        ctx->r18 = ADD32(ctx->r18, 0X14);
            goto L_800056E8;
    }
    // 0x80005730: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
    // 0x80005734: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80005738: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000573C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80005740: addiu       $a2, $a2, -0x3470
    ctx->r6 = ADD32(ctx->r6, -0X3470);
    // 0x80005744: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80005748: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x8000574C: jal         0x800655B0
    // 0x80005750: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800655B0(rdram, ctx);
        goto after_2;
    // 0x80005750: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x80005754: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
    // 0x80005758: addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // 0x8000575C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80005760: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005764: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80005768: sw          $v0, 0x38F0($at)
    MEM_W(0X38F0, ctx->r1) = ctx->r2;
    // 0x8000576C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80005770: addiu       $v1, $v1, 0x38D0
    ctx->r3 = ADD32(ctx->r3, 0X38D0);
    // 0x80005774: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80005778: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000577C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_80005780:
    // 0x80005780: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80005784: addiu       $v0, $v0, 0x54E0
    ctx->r2 = ADD32(ctx->r2, 0X54E0);
    // 0x80005788: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8000578C: addiu       $v1, $v1, 0x38D0
    ctx->r3 = ADD32(ctx->r3, 0X38D0);
    // 0x80005790: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005794: sw          $zero, 0x3DE0($at)
    MEM_W(0X3DE0, ctx->r1) = 0;
    // 0x80005798: sw          $v1, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r3;
    // 0x8000579C: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800057A0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800057A4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800057A8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800057AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800057B0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800057B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800057B8: jr          $ra
    // 0x800057BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800057BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800057C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800057C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800057C4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800057C8: addiu       $v0, $v0, 0x38D4
    ctx->r2 = ADD32(ctx->r2, 0X38D4);
    // 0x800057CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800057D0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800057D4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800057D8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800057DC: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x800057E0: beq         $s0, $zero, L_80005850
    if (ctx->r16 == 0) {
        // 0x800057E4: nop
    
            goto L_80005850;
    }
    // 0x800057E4: nop

    // 0x800057E8: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
L_800057EC:
    // 0x800057EC: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x800057F0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800057F4: lw          $v1, -0x20C0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X20C0);
    // 0x800057F8: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800057FC: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80005800: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80005804: beql        $v0, $zero, L_80005848
    if (ctx->r2 == 0) {
        // 0x80005808: addu        $s0, $s1, $zero
        ctx->r16 = ADD32(ctx->r17, 0);
            goto L_80005848;
    }
    goto skip_0;
    // 0x80005808: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    skip_0:
    // 0x8000580C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80005810: beql        $v0, $s0, L_80005818
    if (ctx->r2 == ctx->r16) {
        // 0x80005814: sw          $s1, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r17;
            goto L_80005818;
    }
    goto skip_1;
    // 0x80005814: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
    skip_1:
L_80005818:
    // 0x80005818: jal         0x8006553C
    // 0x8000581C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8006553C(rdram, ctx);
        goto after_0;
    // 0x8000581C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80005820: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x80005824: beql        $a1, $zero, L_8000583C
    if (ctx->r5 == 0) {
        // 0x80005828: sw          $s0, 0x4($s2)
        MEM_W(0X4, ctx->r18) = ctx->r16;
            goto L_8000583C;
    }
    goto skip_2;
    // 0x80005828: sw          $s0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r16;
    skip_2:
    // 0x8000582C: jal         0x8006551C
    // 0x80005830: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8006551C(rdram, ctx);
        goto after_1;
    // 0x80005830: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80005834: j           L_80005848
    // 0x80005838: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
        goto L_80005848;
    // 0x80005838: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_8000583C:
    // 0x8000583C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80005840: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80005844: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_80005848:
    // 0x80005848: bne         $s0, $zero, L_800057EC
    if (ctx->r16 != 0) {
        // 0x8000584C: nop
    
            goto L_800057EC;
    }
    // 0x8000584C: nop

L_80005850:
    // 0x80005850: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80005854: lw          $v0, -0x20C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X20C0);
    // 0x80005858: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000585C: sw          $zero, 0x3DE0($at)
    MEM_W(0X3DE0, ctx->r1) = 0;
    // 0x80005860: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80005864: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80005868: sw          $v0, -0x20C0($at)
    MEM_W(-0X20C0, ctx->r1) = ctx->r2;
    // 0x8000586C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80005870: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80005874: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80005878: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000587C: jr          $ra
    // 0x80005880: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80005880: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80005884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005884: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80005888: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x8000588C: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x80005890: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80005894: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80005898: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000589C: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x800058A0: addiu       $s1, $s1, -0x3470
    ctx->r17 = ADD32(ctx->r17, -0X3470);
    // 0x800058A4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800058A8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800058AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800058B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800058B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800058B8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800058BC: sb          $v0, -0x20B4($at)
    MEM_B(-0X20B4, ctx->r1) = ctx->r2;
    // 0x800058C0: jal         0x80065570
    // 0x800058C4: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    func_80065570(rdram, ctx);
        goto after_0;
    // 0x800058C4: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    after_0:
    // 0x800058C8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800058CC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800058D0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800058D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800058D8: addiu       $s0, $zero, 0x2000
    ctx->r16 = ADD32(0, 0X2000);
    // 0x800058DC: jal         0x800655B0
    // 0x800058E0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_800655B0(rdram, ctx);
        goto after_1;
    // 0x800058E0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_1:
    // 0x800058E4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800058E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800058EC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800058F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800058F4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800058F8: sw          $v0, 0x30F0($at)
    MEM_W(0X30F0, ctx->r1) = ctx->r2;
    // 0x800058FC: jal         0x800655B0
    // 0x80005900: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_800655B0(rdram, ctx);
        goto after_2;
    // 0x80005900: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_2:
    // 0x80005904: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80005908: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000590C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80005910: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80005914: ori         $s0, $zero, 0x8000
    ctx->r16 = 0 | 0X8000;
    // 0x80005918: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000591C: sw          $v0, 0x30F4($at)
    MEM_W(0X30F4, ctx->r1) = ctx->r2;
    // 0x80005920: jal         0x800655B0
    // 0x80005924: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_800655B0(rdram, ctx);
        goto after_3;
    // 0x80005924: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_3:
    // 0x80005928: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8000592C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80005930: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80005934: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80005938: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000593C: sw          $v0, 0x31A8($at)
    MEM_W(0X31A8, ctx->r1) = ctx->r2;
    // 0x80005940: jal         0x800655B0
    // 0x80005944: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_800655B0(rdram, ctx);
        goto after_4;
    // 0x80005944: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_4:
    // 0x80005948: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8000594C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80005950: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80005954: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80005958: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000595C: sw          $v0, 0x31AC($at)
    MEM_W(0X31AC, ctx->r1) = ctx->r2;
    // 0x80005960: jal         0x800655B0
    // 0x80005964: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_800655B0(rdram, ctx);
        goto after_5;
    // 0x80005964: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_5:
    // 0x80005968: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8000596C: addiu       $a0, $a0, 0x31B8
    ctx->r4 = ADD32(ctx->r4, 0X31B8);
    // 0x80005970: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80005974: addiu       $a1, $a1, 0x31D0
    ctx->r5 = ADD32(ctx->r5, 0X31D0);
    // 0x80005978: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000597C: sw          $v0, 0x31B0($at)
    MEM_W(0X31B0, ctx->r1) = ctx->r2;
    // 0x80005980: jal         0x80061740
    // 0x80005984: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_6;
    // 0x80005984: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_6:
    // 0x80005988: lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X18);
    // 0x8000598C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80005990: addiu       $v0, $v0, 0x5680
    ctx->r2 = ADD32(ctx->r2, 0X5680);
    // 0x80005994: sw          $v0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r2;
    // 0x80005998: jal         0x80066E70
    // 0x8000599C: sw          $s1, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r17;
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_7;
    // 0x8000599C: sw          $s1, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r17;
    after_7:
    // 0x800059A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800059A4: addiu       $a0, $a0, -0x3888
    ctx->r4 = ADD32(ctx->r4, -0X3888);
    // 0x800059A8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800059AC: jal         0x8005D2F0
    // 0x800059B0: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    func_8005D2F0(rdram, ctx);
        goto after_8;
    // 0x800059B0: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    after_8:
    // 0x800059B4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800059B8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800059BC: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x800059C0: addiu       $a2, $a2, -0x2B60
    ctx->r6 = ADD32(ctx->r6, -0X2B60);
    // 0x800059C4: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x800059C8: addiu       $v0, $v0, -0x2A90
    ctx->r2 = ADD32(ctx->r2, -0X2A90);
    // 0x800059CC: subu        $a3, $v0, $a2
    ctx->r7 = SUB32(ctx->r2, ctx->r6);
    // 0x800059D0: lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // 0x800059D4: addiu       $t2, $t2, -0x2A90
    ctx->r10 = ADD32(ctx->r10, -0X2A90);
    // 0x800059D8: lui         $t1, 0x800B
    ctx->r9 = S32(0X800B << 16);
    // 0x800059DC: addiu       $t1, $t1, -0x7D50
    ctx->r9 = ADD32(ctx->r9, -0X7D50);
    // 0x800059E0: addiu       $t0, $zero, 0x800
    ctx->r8 = ADD32(0, 0X800);
    // 0x800059E4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800059E8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800059EC:
    // 0x800059EC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800059F0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800059F4: sw          $zero, 0x314C($at)
    MEM_W(0X314C, ctx->r1) = 0;
    // 0x800059F8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800059FC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80005A00: sw          $t3, 0x3108($at)
    MEM_W(0X3108, ctx->r1) = ctx->r11;
    // 0x80005A04: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005A08: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80005A0C: sw          $a2, 0x3110($at)
    MEM_W(0X3110, ctx->r1) = ctx->r6;
    // 0x80005A10: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005A14: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80005A18: sw          $a3, 0x3114($at)
    MEM_W(0X3114, ctx->r1) = ctx->r7;
    // 0x80005A1C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005A20: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80005A24: sw          $t2, 0x3118($at)
    MEM_W(0X3118, ctx->r1) = ctx->r10;
    // 0x80005A28: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005A2C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80005A30: sw          $t1, 0x3120($at)
    MEM_W(0X3120, ctx->r1) = ctx->r9;
    // 0x80005A34: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005A38: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80005A3C: sw          $t0, 0x3124($at)
    MEM_W(0X3124, ctx->r1) = ctx->r8;
    // 0x80005A40: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005A44: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80005A48: sw          $zero, 0x3128($at)
    MEM_W(0X3128, ctx->r1) = 0;
    // 0x80005A4C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005A50: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80005A54: sw          $zero, 0x312C($at)
    MEM_W(0X312C, ctx->r1) = 0;
    // 0x80005A58: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005A5C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80005A60: sw          $zero, 0x3130($at)
    MEM_W(0X3130, ctx->r1) = 0;
    // 0x80005A64: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005A68: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80005A6C: sw          $zero, 0x3134($at)
    MEM_W(0X3134, ctx->r1) = 0;
    // 0x80005A70: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005A74: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80005A78: sw          $zero, 0x3140($at)
    MEM_W(0X3140, ctx->r1) = 0;
    // 0x80005A7C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005A80: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80005A84: sw          $zero, 0x3144($at)
    MEM_W(0X3144, ctx->r1) = 0;
    // 0x80005A88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005A8C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80005A90: sw          $zero, -0x4DC4($at)
    MEM_W(-0X4DC4, ctx->r1) = 0;
    // 0x80005A94: addiu       $a0, $a0, 0x184
    ctx->r4 = ADD32(ctx->r4, 0X184);
    // 0x80005A98: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80005A9C: sltiu       $v0, $a1, 0x2
    ctx->r2 = ctx->r5 < 0X2 ? 1 : 0;
    // 0x80005AA0: bne         $v0, $zero, L_800059EC
    if (ctx->r2 != 0) {
        // 0x80005AA4: addiu       $v1, $v1, 0x58
        ctx->r3 = ADD32(ctx->r3, 0X58);
            goto L_800059EC;
    }
    // 0x80005AA4: addiu       $v1, $v1, 0x58
    ctx->r3 = ADD32(ctx->r3, 0X58);
    // 0x80005AA8: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80005AAC: addiu       $s0, $s0, -0x50C0
    ctx->r16 = ADD32(ctx->r16, -0X50C0);
    // 0x80005AB0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80005AB4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80005AB8: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80005ABC: addiu       $a2, $a2, 0x5B00
    ctx->r6 = ADD32(ctx->r6, 0X5B00);
    // 0x80005AC0: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80005AC4: addiu       $a3, $a3, -0x31D0
    ctx->r7 = ADD32(ctx->r7, -0X31D0);
    // 0x80005AC8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80005ACC: addiu       $v0, $v0, -0x3F10
    ctx->r2 = ADD32(ctx->r2, -0X3F10);
    // 0x80005AD0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80005AD4: addiu       $v0, $zero, 0x46
    ctx->r2 = ADD32(0, 0X46);
    // 0x80005AD8: jal         0x80061770
    // 0x80005ADC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    osCreateThread_recomp(rdram, ctx);
        goto after_9;
    // 0x80005ADC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_9:
    // 0x80005AE0: jal         0x80061C60
    // 0x80005AE4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    osStartThread_recomp(rdram, ctx);
        goto after_10;
    // 0x80005AE4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_10:
    // 0x80005AE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80005AEC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80005AF0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80005AF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80005AF8: jr          $ra
    // 0x80005AFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80005AFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80005B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005B00: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80005B04: sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // 0x80005B08: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80005B0C: sw          $s6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r22;
    // 0x80005B10: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // 0x80005B14: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // 0x80005B18: addiu       $s0, $sp, 0x18
    ctx->r16 = ADD32(ctx->r29, 0X18);
    // 0x80005B1C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80005B20: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80005B24: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80005B28: sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // 0x80005B2C: sw          $fp, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r30;
    // 0x80005B30: sw          $s7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r23;
    // 0x80005B34: sw          $s5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r21;
    // 0x80005B38: sw          $s4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r20;
    // 0x80005B3C: sw          $s3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r19;
    // 0x80005B40: jal         0x80061740
    // 0x80005B44: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80005B44: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    after_0:
    // 0x80005B48: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80005B4C: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x80005B50: jal         0x80061740
    // 0x80005B54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80005B54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80005B58: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80005B5C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80005B60: jal         0x80000708
    // 0x80005B64: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80000708(rdram, ctx);
        goto after_2;
    // 0x80005B64: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80005B68: jal         0x8000065C
    // 0x80005B6C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8000065C(rdram, ctx);
        goto after_3;
    // 0x80005B6C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
    // 0x80005B70: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80005B74: lui         $s5, 0x800C
    ctx->r21 = S32(0X800C << 16);
    // 0x80005B78: lw          $s5, 0x30F0($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X30F0);
    // 0x80005B7C: lui         $fp, 0x800C
    ctx->r30 = S32(0X800C << 16);
    // 0x80005B80: lw          $fp, 0x31A8($fp)
    ctx->r30 = MEM_W(ctx->r30, 0X31A8);
    // 0x80005B84: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80005B88: lui         $s4, 0x800C
    ctx->r20 = S32(0X800C << 16);
    // 0x80005B8C: addiu       $s4, $s4, 0x30F8
    ctx->r20 = ADD32(ctx->r20, 0X30F8);
    // 0x80005B90: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x80005B94: jal         0x80005EC0
    // 0x80005B98: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    func_80005EC0(rdram, ctx);
        goto after_4;
    // 0x80005B98: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    after_4:
L_80005B9C:
    // 0x80005B9C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
L_80005BA0:
    // 0x80005BA0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
L_80005BA4:
    // 0x80005BA4: jal         0x800619A0
    // 0x80005BA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80005BA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80005BAC: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x80005BB0: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x80005BB4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80005BB8: beq         $v1, $t0, L_80005BD0
    if (ctx->r3 == ctx->r8) {
        // 0x80005BBC: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80005BD0;
    }
    // 0x80005BBC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80005BC0: beq         $v1, $v0, L_80005DE8
    if (ctx->r3 == ctx->r2) {
        // 0x80005BC4: addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
            goto L_80005DE8;
    }
    // 0x80005BC4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80005BC8: j           L_80005BA0
    // 0x80005BCC: nop

        goto L_80005BA0;
    // 0x80005BCC: nop

L_80005BD0:
    // 0x80005BD0: jal         0x80065D90
    // 0x80005BD4: nop

    osAiGetStatus_recomp(rdram, ctx);
        goto after_6;
    // 0x80005BD4: nop

    after_6:
    // 0x80005BD8: bgez        $v0, L_80005BE8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80005BDC: nop
    
            goto L_80005BE8;
    }
    // 0x80005BDC: nop

    // 0x80005BE0: j           L_80005B9C
    // 0x80005BE4: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
        goto L_80005B9C;
    // 0x80005BE4: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
L_80005BE8:
    // 0x80005BE8: jal         0x80065D80
    // 0x80005BEC: nop

    osAiGetLength_recomp(rdram, ctx);
        goto after_7;
    // 0x80005BEC: nop

    after_7:
    // 0x80005BF0: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x80005BF4: beq         $v1, $zero, L_80005C5C
    if (ctx->r3 == 0) {
        // 0x80005BF8: srl         $s0, $v0, 2
        ctx->r16 = S32(U32(ctx->r2) >> 2);
            goto L_80005C5C;
    }
    // 0x80005BF8: srl         $s0, $v0, 2
    ctx->r16 = S32(U32(ctx->r2) >> 2);
    // 0x80005BFC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80005C00: lbu         $v0, -0x20B4($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X20B4);
    // 0x80005C04: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80005C08: bne         $v0, $t0, L_80005C60
    if (ctx->r2 != ctx->r8) {
        // 0x80005C0C: slti        $v0, $s0, 0xB8
        ctx->r2 = SIGNED(ctx->r16) < 0XB8 ? 1 : 0;
            goto L_80005C60;
    }
    // 0x80005C0C: slti        $v0, $s0, 0xB8
    ctx->r2 = SIGNED(ctx->r16) < 0XB8 ? 1 : 0;
    // 0x80005C10: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // 0x80005C14: jal         0x80065DA0
    // 0x80005C18: sll         $a1, $s6, 2
    ctx->r5 = S32(ctx->r22 << 2);
    osAiSetNextBuffer_recomp(rdram, ctx);
        goto after_8;
    // 0x80005C18: sll         $a1, $s6, 2
    ctx->r5 = S32(ctx->r22 << 2);
    after_8:
    // 0x80005C1C: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
    // 0x80005C20: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80005C24: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80005C28: subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // 0x80005C2C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80005C30: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80005C34: addiu       $v1, $v1, 0x30F8
    ctx->r3 = ADD32(ctx->r3, 0X30F8);
    // 0x80005C38: addu        $s4, $v0, $v1
    ctx->r20 = ADD32(ctx->r2, ctx->r3);
    // 0x80005C3C: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
    // 0x80005C40: lui         $s5, 0x800C
    ctx->r21 = S32(0X800C << 16);
    // 0x80005C44: addu        $s5, $s5, $v0
    ctx->r21 = ADD32(ctx->r21, ctx->r2);
    // 0x80005C48: lw          $s5, 0x30F0($s5)
    ctx->r21 = MEM_W(ctx->r21, 0X30F0);
    // 0x80005C4C: sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18 << 2);
    // 0x80005C50: lui         $fp, 0x800C
    ctx->r30 = S32(0X800C << 16);
    // 0x80005C54: addu        $fp, $fp, $v0
    ctx->r30 = ADD32(ctx->r30, ctx->r2);
    // 0x80005C58: lw          $fp, 0x31A8($fp)
    ctx->r30 = MEM_W(ctx->r30, 0X31A8);
L_80005C5C:
    // 0x80005C5C: slti        $v0, $s0, 0xB8
    ctx->r2 = SIGNED(ctx->r16) < 0XB8 ? 1 : 0;
L_80005C60:
    // 0x80005C60: sltu        $v1, $zero, $s7
    ctx->r3 = 0 < ctx->r23 ? 1 : 0;
    // 0x80005C64: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80005C68: beq         $v0, $zero, L_80005C78
    if (ctx->r2 == 0) {
        // 0x80005C6C: addiu       $s6, $zero, 0x2E0
        ctx->r22 = ADD32(0, 0X2E0);
            goto L_80005C78;
    }
    // 0x80005C6C: addiu       $s6, $zero, 0x2E0
    ctx->r22 = ADD32(0, 0X2E0);
    // 0x80005C70: j           L_80005C80
    // 0x80005C74: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
        goto L_80005C80;
    // 0x80005C74: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
L_80005C78:
    // 0x80005C78: addiu       $s6, $zero, 0x228
    ctx->r22 = ADD32(0, 0X228);
    // 0x80005C7C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_80005C80:
    // 0x80005C80: jal         0x80062180
    // 0x80005C84: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_9;
    // 0x80005C84: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    after_9:
    // 0x80005C88: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x80005C8C: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x80005C90: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80005C94: jal         0x8005DC60
    // 0x80005C98: addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    func_8005DC60(rdram, ctx);
        goto after_10;
    // 0x80005C98: addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    after_10:
    // 0x80005C9C: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x80005CA0: beq         $v1, $zero, L_80005DC0
    if (ctx->r3 == 0) {
        // 0x80005CA4: addu        $a3, $v0, $zero
        ctx->r7 = ADD32(ctx->r2, 0);
            goto L_80005DC0;
    }
    // 0x80005CA4: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80005CA8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80005CAC: lbu         $v0, -0x20B4($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X20B4);
    // 0x80005CB0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80005CB4: bne         $v0, $t0, L_80005DC0
    if (ctx->r2 != ctx->r8) {
        // 0x80005CB8: addu        $a1, $s4, $zero
        ctx->r5 = ADD32(ctx->r20, 0);
            goto L_80005DC0;
    }
    // 0x80005CB8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80005CBC: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80005CC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80005CC4: subu        $v0, $a3, $s5
    ctx->r2 = SUB32(ctx->r7, ctx->r21);
    // 0x80005CC8: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80005CCC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80005CD0: sw          $v0, 0x44($s4)
    MEM_W(0X44, ctx->r20) = ctx->r2;
    // 0x80005CD4: addiu       $v0, $sp, 0x50
    ctx->r2 = ADD32(ctx->r29, 0X50);
    // 0x80005CD8: sw          $s5, 0x40($s4)
    MEM_W(0X40, ctx->r20) = ctx->r21;
    // 0x80005CDC: jal         0x80061AD0
    // 0x80005CE0: sw          $v0, 0x50($s4)
    MEM_W(0X50, ctx->r20) = ctx->r2;
    osSendMesg_recomp(rdram, ctx);
        goto after_11;
    // 0x80005CE0: sw          $v0, 0x50($s4)
    MEM_W(0X50, ctx->r20) = ctx->r2;
    after_11:
    // 0x80005CE4: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80005CE8: lw          $s0, 0x38D4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X38D4);
    // 0x80005CEC: beq         $s0, $zero, L_80005D70
    if (ctx->r16 == 0) {
        // 0x80005CF0: addiu       $a0, $sp, 0x50
        ctx->r4 = ADD32(ctx->r29, 0X50);
            goto L_80005D70;
    }
    // 0x80005CF0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
L_80005CF4:
    // 0x80005CF4: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x80005CF8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80005CFC: lw          $v1, -0x20C0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X20C0);
    // 0x80005D00: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80005D04: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80005D08: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80005D0C: beql        $v0, $zero, L_80005D68
    if (ctx->r2 == 0) {
        // 0x80005D10: addu        $s0, $s1, $zero
        ctx->r16 = ADD32(ctx->r17, 0);
            goto L_80005D68;
    }
    goto skip_0;
    // 0x80005D10: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    skip_0:
    // 0x80005D14: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80005D18: lw          $v0, 0x38D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X38D4);
    // 0x80005D1C: bne         $v0, $s0, L_80005D2C
    if (ctx->r2 != ctx->r16) {
        // 0x80005D20: nop
    
            goto L_80005D2C;
    }
    // 0x80005D20: nop

    // 0x80005D24: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005D28: sw          $s1, 0x38D4($at)
    MEM_W(0X38D4, ctx->r1) = ctx->r17;
L_80005D2C:
    // 0x80005D2C: jal         0x8006553C
    // 0x80005D30: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8006553C(rdram, ctx);
        goto after_12;
    // 0x80005D30: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_12:
    // 0x80005D34: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80005D38: lw          $a1, 0x38D8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X38D8);
    // 0x80005D3C: beq         $a1, $zero, L_80005D54
    if (ctx->r5 == 0) {
        // 0x80005D40: nop
    
            goto L_80005D54;
    }
    // 0x80005D40: nop

    // 0x80005D44: jal         0x8006551C
    // 0x80005D48: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8006551C(rdram, ctx);
        goto after_13;
    // 0x80005D48: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_13:
    // 0x80005D4C: j           L_80005D68
    // 0x80005D50: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
        goto L_80005D68;
    // 0x80005D50: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_80005D54:
    // 0x80005D54: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005D58: sw          $s0, 0x38D8($at)
    MEM_W(0X38D8, ctx->r1) = ctx->r16;
    // 0x80005D5C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80005D60: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80005D64: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_80005D68:
    // 0x80005D68: bne         $s0, $zero, L_80005CF4
    if (ctx->r16 != 0) {
        // 0x80005D6C: addiu       $a0, $sp, 0x50
        ctx->r4 = ADD32(ctx->r29, 0X50);
            goto L_80005CF4;
    }
    // 0x80005D6C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
L_80005D70:
    // 0x80005D70: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80005D74: lw          $v0, -0x20C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X20C0);
    // 0x80005D78: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80005D7C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005D80: sw          $zero, 0x3DE0($at)
    MEM_W(0X3DE0, ctx->r1) = 0;
    // 0x80005D84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80005D88: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80005D8C: sw          $v0, -0x20C0($at)
    MEM_W(-0X20C0, ctx->r1) = ctx->r2;
    // 0x80005D90: jal         0x800619A0
    // 0x80005D94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_14;
    // 0x80005D94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x80005D98: addiu       $v1, $s2, 0x1
    ctx->r3 = ADD32(ctx->r18, 0X1);
    // 0x80005D9C: lui         $v0, 0xAAAA
    ctx->r2 = S32(0XAAAA << 16);
    // 0x80005DA0: ori         $v0, $v0, 0xAAAB
    ctx->r2 = ctx->r2 | 0XAAAB;
    // 0x80005DA4: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80005DA8: xori        $s3, $s3, 0x1
    ctx->r19 = ctx->r19 ^ 0X1;
    // 0x80005DAC: mfhi        $t0
    ctx->r8 = hi;
    // 0x80005DB0: srl         $s2, $t0, 1
    ctx->r18 = S32(U32(ctx->r8) >> 1);
    // 0x80005DB4: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x80005DB8: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80005DBC: subu        $s2, $v1, $v0
    ctx->r18 = SUB32(ctx->r3, ctx->r2);
L_80005DC0:
    // 0x80005DC0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80005DC4: lw          $v0, -0x20B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X20B0);
    // 0x80005DC8: beq         $v0, $zero, L_80005BA0
    if (ctx->r2 == 0) {
        // 0x80005DCC: addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
            goto L_80005BA0;
    }
    // 0x80005DCC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80005DD0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80005DD4: lbu         $a1, -0x20B3($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X20B3);
    // 0x80005DD8: beql        $a1, $zero, L_80005BA4
    if (ctx->r5 == 0) {
        // 0x80005DDC: addiu       $a1, $sp, 0x6C
        ctx->r5 = ADD32(ctx->r29, 0X6C);
            goto L_80005BA4;
    }
    goto skip_1;
    // 0x80005DDC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    skip_1:
    // 0x80005DE0: j           L_80005E00
    // 0x80005DE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80005E00;
    // 0x80005DE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80005DE8:
    // 0x80005DE8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80005DEC: lw          $v0, -0x20B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X20B0);
    // 0x80005DF0: beq         $v0, $zero, L_80005E08
    if (ctx->r2 == 0) {
        // 0x80005DF4: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80005E08;
    }
    // 0x80005DF4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80005DF8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80005DFC: lbu         $a1, -0x20B3($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X20B3);
L_80005E00:
    // 0x80005E00: jalr        $v0
    // 0x80005E04: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_15;
    // 0x80005E04: nop

    after_15:
L_80005E08:
    // 0x80005E08: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80005E0C: lbu         $v0, -0x20B3($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X20B3);
    // 0x80005E10: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80005E14: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80005E18: sb          $v0, -0x20B3($at)
    MEM_B(-0X20B3, ctx->r1) = ctx->r2;
    // 0x80005E1C: j           L_80005BA0
    // 0x80005E20: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_80005BA0;
    // 0x80005E20: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80005E24: lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA4);
    // 0x80005E28: lw          $fp, 0xA0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XA0);
    // 0x80005E2C: lw          $s7, 0x9C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X9C);
    // 0x80005E30: lw          $s6, 0x98($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X98);
    // 0x80005E34: lw          $s5, 0x94($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X94);
    // 0x80005E38: lw          $s4, 0x90($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X90);
    // 0x80005E3C: lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X8C);
    // 0x80005E40: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x80005E44: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x80005E48: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x80005E4C: jr          $ra
    // 0x80005E50: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80005E50: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_80005E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005E54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005E58: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80005E5C: addiu       $a0, $a0, 0x2A48
    ctx->r4 = ADD32(ctx->r4, 0X2A48);
    // 0x80005E60: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80005E64: addiu       $v0, $v0, -0x12B0
    ctx->r2 = ADD32(ctx->r2, -0X12B0);
    // 0x80005E68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80005E6C: sw          $v0, 0x2A68($at)
    MEM_W(0X2A68, ctx->r1) = ctx->r2;
    // 0x80005E70: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80005E74: addiu       $v0, $v0, -0x10F0
    ctx->r2 = ADD32(ctx->r2, -0X10F0);
    // 0x80005E78: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80005E7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80005E80: jal         0x80005280
    // 0x80005E84: sw          $v0, 0x2A6C($at)
    MEM_W(0X2A6C, ctx->r1) = ctx->r2;
    func_80005280(rdram, ctx);
        goto after_0;
    // 0x80005E84: sw          $v0, 0x2A6C($at)
    MEM_W(0X2A6C, ctx->r1) = ctx->r2;
    after_0:
    // 0x80005E88: jal         0x80006AE0
    // 0x80005E8C: nop

    func_80006AE0(rdram, ctx);
        goto after_1;
    // 0x80005E8C: nop

    after_1:
    // 0x80005E90: lui         $a0, 0x6F
    ctx->r4 = S32(0X6F << 16);
    // 0x80005E94: addiu       $a0, $a0, -0x100
    ctx->r4 = ADD32(ctx->r4, -0X100);
    // 0x80005E98: lui         $a1, 0x6F
    ctx->r5 = S32(0X6F << 16);
    // 0x80005E9C: addiu       $a1, $a1, 0x2D00
    ctx->r5 = ADD32(ctx->r5, 0X2D00);
    // 0x80005EA0: lui         $a2, 0x6F
    ctx->r6 = S32(0X6F << 16);
    // 0x80005EA4: addiu       $a2, $a2, 0x2D00
    ctx->r6 = ADD32(ctx->r6, 0X2D00);
    // 0x80005EA8: jal         0x80005374
    // 0x80005EAC: subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    func_80005374(rdram, ctx);
        goto after_2;
    // 0x80005EAC: subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    after_2:
    // 0x80005EB0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80005EB4: jr          $ra
    // 0x80005EB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80005EB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80005EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005EC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005EC4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80005EC8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80005ECC:
    // 0x80005ECC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005ED0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80005ED4: sw          $zero, 0x3DF0($at)
    MEM_W(0X3DF0, ctx->r1) = 0;
    // 0x80005ED8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80005EDC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80005EE0: sw          $zero, 0x3E0C($at)
    MEM_W(0X3E0C, ctx->r1) = 0;
    // 0x80005EE4: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80005EE8: slti        $v0, $v1, 0x140
    ctx->r2 = SIGNED(ctx->r3) < 0X140 ? 1 : 0;
    // 0x80005EEC: bne         $v0, $zero, L_80005ECC
    if (ctx->r2 != 0) {
        // 0x80005EF0: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80005ECC;
    }
    // 0x80005EF0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80005EF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005EF8: sw          $zero, 0x7C9C($at)
    MEM_W(0X7C9C, ctx->r1) = 0;
    // 0x80005EFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005F00: sw          $zero, 0x7CA0($at)
    MEM_W(0X7CA0, ctx->r1) = 0;
    // 0x80005F04: jal         0x80059C48
    // 0x80005F08: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    func_80059C48(rdram, ctx);
        goto after_0;
    // 0x80005F08: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_0:
    // 0x80005F0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80005F10: jal         0x80059C48
    // 0x80005F14: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    func_80059C48(rdram, ctx);
        goto after_1;
    // 0x80005F14: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_1:
    // 0x80005F18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005F1C: sw          $zero, 0x7760($at)
    MEM_W(0X7760, ctx->r1) = 0;
    // 0x80005F20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005F24: sw          $zero, 0x7764($at)
    MEM_W(0X7764, ctx->r1) = 0;
    // 0x80005F28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005F2C: sw          $zero, 0x7768($at)
    MEM_W(0X7768, ctx->r1) = 0;
    // 0x80005F30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005F34: sw          $zero, 0x776C($at)
    MEM_W(0X776C, ctx->r1) = 0;
    // 0x80005F38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005F3C: sw          $zero, 0x7770($at)
    MEM_W(0X7770, ctx->r1) = 0;
    // 0x80005F40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005F44: sw          $zero, 0x7774($at)
    MEM_W(0X7774, ctx->r1) = 0;
    // 0x80005F48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005F4C: sw          $zero, 0x7778($at)
    MEM_W(0X7778, ctx->r1) = 0;
    // 0x80005F50: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005F54: sw          $zero, 0x7784($at)
    MEM_W(0X7784, ctx->r1) = 0;
    // 0x80005F58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005F5C: sw          $zero, 0x7788($at)
    MEM_W(0X7788, ctx->r1) = 0;
    // 0x80005F60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005F64: sw          $zero, 0x778C($at)
    MEM_W(0X778C, ctx->r1) = 0;
    // 0x80005F68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005F6C: sw          $zero, 0x7790($at)
    MEM_W(0X7790, ctx->r1) = 0;
    // 0x80005F70: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80005F74: jr          $ra
    // 0x80005F78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80005F78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80005F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005F7C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80005F80: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80005F84: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80005F88: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80005F8C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80005F90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80005F94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80005F98: jal         0x80061710
    // 0x80005F9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80061710(rdram, ctx);
        goto after_0;
    // 0x80005F9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80005FA0: lui         $s1, 0x800C
    ctx->r17 = S32(0X800C << 16);
    // 0x80005FA4: addiu       $s1, $s1, 0x3DF0
    ctx->r17 = ADD32(ctx->r17, 0X3DF0);
    // 0x80005FA8: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80005FAC: lui         $s5, 0x800B
    ctx->r21 = S32(0X800B << 16);
    // 0x80005FB0: addiu       $s5, $s5, -0x3648
    ctx->r21 = ADD32(ctx->r21, -0X3648);
    // 0x80005FB4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80005FB8: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x80005FBC: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_80005FC0:
    // 0x80005FC0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80005FC4: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x80005FC8: beq         $v0, $zero, L_800060C0
    if (ctx->r2 == 0) {
        // 0x80005FCC: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800060C0;
    }
    // 0x80005FCC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80005FD0: addu        $v0, $v0, $s5
    gpr jr_addend_80005FD8 = ctx->r2;
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x80005FD4: lw          $v0, 0x0($v0)
    ctx->r2 = ADD32(ctx->r2, 0X0);
    // 0x80005FD8: jr          $v0
    // 0x80005FDC: nop

    switch (jr_addend_80005FD8 >> 2) {
        case 0: goto L_800060C0; break;
        case 1: goto L_80005FE0; break;
        case 2: goto L_80006030; break;
        case 3: goto L_80006048; break;
        case 4: goto L_80006080; break;
        case 5: goto L_800060A8; break;
        default: switch_error(__func__, 0x80005FD8, 0x800AC9B8);
    }
    // 0x80005FDC: nop

L_80005FE0:
    // 0x80005FE0: jal         0x8005A4E4
    // 0x80005FE4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8005A4E4(rdram, ctx);
        goto after_1;
    // 0x80005FE4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x80005FE8: beql        $v0, $zero, L_800060C0
    if (ctx->r2 == 0) {
        // 0x80005FEC: sw          $zero, 0x0($s1)
        MEM_W(0X0, ctx->r17) = 0;
            goto L_800060C0;
    }
    goto skip_0;
    // 0x80005FEC: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    skip_0:
    // 0x80005FF0: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80005FF4: bnel        $v0, $s3, L_800060C4
    if (ctx->r2 != ctx->r19) {
        // 0x80005FF8: addiu       $s0, $s0, 0x20
        ctx->r16 = ADD32(ctx->r16, 0X20);
            goto L_800060C4;
    }
    goto skip_1;
    // 0x80005FF8: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    skip_1:
    // 0x80005FFC: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80006000: addiu       $a1, $v0, -0x4
    ctx->r5 = ADD32(ctx->r2, -0X4);
    // 0x80006004: bgtz        $a1, L_8000601C
    if (SIGNED(ctx->r5) > 0) {
        // 0x80006008: sw          $a1, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r5;
            goto L_8000601C;
    }
    // 0x80006008: sw          $a1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r5;
    // 0x8000600C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80006010: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006014: j           L_80006038
    // 0x80006018: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
        goto L_80006038;
    // 0x80006018: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
L_8000601C:
    // 0x8000601C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80006020: jal         0x8005A5A0
    // 0x80006024: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    func_8005A5A0(rdram, ctx);
        goto after_2;
    // 0x80006024: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    after_2:
    // 0x80006028: j           L_800060C8
    // 0x8000602C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_800060C8;
    // 0x8000602C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80006030:
    // 0x80006030: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80006034: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80006038:
    // 0x80006038: jal         0x8005A3F8
    // 0x8000603C: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    func_8005A3F8(rdram, ctx);
        goto after_3;
    // 0x8000603C: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    after_3:
    // 0x80006040: j           L_800060C4
    // 0x80006044: sw          $s4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r20;
        goto L_800060C4;
    // 0x80006044: sw          $s4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r20;
L_80006048:
    // 0x80006048: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8000604C: jal         0x8005A4E4
    // 0x80006050: nop

    func_8005A4E4(rdram, ctx);
        goto after_4;
    // 0x80006050: nop

    after_4:
    // 0x80006054: bnel        $v0, $zero, L_800060C4
    if (ctx->r2 != 0) {
        // 0x80006058: addiu       $s0, $s0, 0x20
        ctx->r16 = ADD32(ctx->r16, 0X20);
            goto L_800060C4;
    }
    goto skip_2;
    // 0x80006058: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    skip_2:
    // 0x8000605C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80006060: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80006064: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x80006068: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8000606C: jal         0x80059FF8
    // 0x80006070: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80059FF8(rdram, ctx);
        goto after_5;
    // 0x80006070: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_5:
    // 0x80006074: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80006078: j           L_800060C0
    // 0x8000607C: sw          $s3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r19;
        goto L_800060C0;
    // 0x8000607C: sw          $s3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r19;
L_80006080:
    // 0x80006080: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80006084: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80006088: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x8000608C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80006090: jal         0x80059FF8
    // 0x80006094: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80059FF8(rdram, ctx);
        goto after_6;
    // 0x80006094: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_6:
    // 0x80006098: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000609C: sw          $s3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r19;
    // 0x800060A0: j           L_800060C0
    // 0x800060A4: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
        goto L_800060C0;
    // 0x800060A4: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
L_800060A8:
    // 0x800060A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800060AC: jal         0x8005A4E4
    // 0x800060B0: nop

    func_8005A4E4(rdram, ctx);
        goto after_7;
    // 0x800060B0: nop

    after_7:
    // 0x800060B4: bnel        $v0, $zero, L_800060C4
    if (ctx->r2 != 0) {
        // 0x800060B8: addiu       $s0, $s0, 0x20
        ctx->r16 = ADD32(ctx->r16, 0X20);
            goto L_800060C4;
    }
    goto skip_3;
    // 0x800060B8: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    skip_3:
    // 0x800060BC: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_800060C0:
    // 0x800060C0: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
L_800060C4:
    // 0x800060C4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800060C8:
    // 0x800060C8: slti        $v0, $s2, 0xA
    ctx->r2 = SIGNED(ctx->r18) < 0XA ? 1 : 0;
    // 0x800060CC: bne         $v0, $zero, L_80005FC0
    if (ctx->r2 != 0) {
        // 0x800060D0: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_80005FC0;
    }
    // 0x800060D0: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x800060D4: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800060D8: addiu       $s1, $s1, 0x7760
    ctx->r17 = ADD32(ctx->r17, 0X7760);
    // 0x800060DC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800060E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800060E4: beq         $s0, $v0, L_80006104
    if (ctx->r16 == ctx->r2) {
        // 0x800060E8: slti        $v0, $s0, 0x2
        ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
            goto L_80006104;
    }
    // 0x800060E8: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x800060EC: bne         $v0, $zero, L_800061AC
    if (ctx->r2 != 0) {
        // 0x800060F0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800061AC;
    }
    // 0x800060F0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800060F4: beq         $s0, $v0, L_8000615C
    if (ctx->r16 == ctx->r2) {
        // 0x800060F8: nop
    
            goto L_8000615C;
    }
    // 0x800060F8: nop

    // 0x800060FC: j           L_800061AC
    // 0x80006100: nop

        goto L_800061AC;
    // 0x80006100: nop

L_80006104:
    // 0x80006104: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80006108: lw          $a0, 0x776C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X776C);
    // 0x8000610C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80006110: lw          $a1, 0x7774($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7774);
    // 0x80006114: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80006118: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8000611C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80006120: jal         0x80059FF8
    // 0x80006124: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80059FF8(rdram, ctx);
        goto after_8;
    // 0x80006124: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_8:
    // 0x80006128: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8000612C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80006130: lbu         $v1, 0x2085($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2085);
    // 0x80006134: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006138: sw          $v0, 0x7764($at)
    MEM_W(0X7764, ctx->r1) = ctx->r2;
    // 0x8000613C: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80006140: bne         $v1, $s0, L_800061AC
    if (ctx->r3 != ctx->r16) {
        // 0x80006144: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_800061AC;
    }
    // 0x80006144: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80006148: addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    // 0x8000614C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80006150: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006154: j           L_800061AC
    // 0x80006158: sw          $zero, 0x7778($at)
    MEM_W(0X7778, ctx->r1) = 0;
        goto L_800061AC;
    // 0x80006158: sw          $zero, 0x7778($at)
    MEM_W(0X7778, ctx->r1) = 0;
L_8000615C:
    // 0x8000615C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80006160: lw          $v0, 0x7778($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7778);
    // 0x80006164: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80006168: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000616C: sw          $v0, 0x7778($at)
    MEM_W(0X7778, ctx->r1) = ctx->r2;
    // 0x80006170: bne         $v0, $zero, L_800061AC
    if (ctx->r2 != 0) {
        // 0x80006174: addiu       $a2, $zero, 0x80
        ctx->r6 = ADD32(0, 0X80);
            goto L_800061AC;
    }
    // 0x80006174: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80006178: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000617C: lw          $a0, 0x7770($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7770);
    // 0x80006180: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80006184: lw          $a1, 0x7774($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7774);
    // 0x80006188: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8000618C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80006190: jal         0x80059FF8
    // 0x80006194: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80059FF8(rdram, ctx);
        goto after_9;
    // 0x80006194: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_9:
    // 0x80006198: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000619C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800061A0: sw          $v0, 0x7768($at)
    MEM_W(0X7768, ctx->r1) = ctx->r2;
    // 0x800061A4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800061A8: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
L_800061AC:
    // 0x800061AC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800061B0: addiu       $s0, $s0, 0x777C
    ctx->r16 = ADD32(ctx->r16, 0X777C);
    // 0x800061B4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800061B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800061BC: bne         $v1, $v0, L_8000624C
    if (ctx->r3 != ctx->r2) {
        // 0x800061C0: nop
    
            goto L_8000624C;
    }
    // 0x800061C0: nop

    // 0x800061C4: lw          $v1, -0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, -0X8);
    // 0x800061C8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800061CC: lw          $v0, 0x7780($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7780);
    // 0x800061D0: subu        $a1, $v1, $v0
    ctx->r5 = SUB32(ctx->r3, ctx->r2);
    // 0x800061D4: bgez        $a1, L_80006220
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800061D8: sw          $a1, -0x8($s0)
        MEM_W(-0X8, ctx->r16) = ctx->r5;
            goto L_80006220;
    }
    // 0x800061D8: sw          $a1, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->r5;
    // 0x800061DC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800061E0: lw          $a0, 0x7764($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7764);
    // 0x800061E4: jal         0x8005A3F8
    // 0x800061E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8005A3F8(rdram, ctx);
        goto after_10;
    // 0x800061E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_10:
    // 0x800061EC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800061F0: lbu         $v0, 0x2085($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2085);
    // 0x800061F4: bnel        $v0, $zero, L_80006210
    if (ctx->r2 != 0) {
        // 0x800061F8: sw          $zero, 0x0($s0)
        MEM_W(0X0, ctx->r16) = 0;
            goto L_80006210;
    }
    goto skip_4;
    // 0x800061F8: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    skip_4:
    // 0x800061FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80006200: lw          $a0, 0x7768($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7768);
    // 0x80006204: jal         0x8005A3F8
    // 0x80006208: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8005A3F8(rdram, ctx);
        goto after_11;
    // 0x80006208: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_11:
    // 0x8000620C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_80006210:
    // 0x80006210: sw          $zero, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = 0;
    // 0x80006214: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006218: j           L_8000624C
    // 0x8000621C: sw          $zero, 0x7760($at)
    MEM_W(0X7760, ctx->r1) = 0;
        goto L_8000624C;
    // 0x8000621C: sw          $zero, 0x7760($at)
    MEM_W(0X7760, ctx->r1) = 0;
L_80006220:
    // 0x80006220: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80006224: jal         0x8005A5A0
    // 0x80006228: lw          $a0, 0x7764($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7764);
    func_8005A5A0(rdram, ctx);
        goto after_12;
    // 0x80006228: lw          $a0, 0x7764($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7764);
    after_12:
    // 0x8000622C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80006230: lbu         $v0, 0x2085($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2085);
    // 0x80006234: bne         $v0, $zero, L_8000624C
    if (ctx->r2 != 0) {
        // 0x80006238: nop
    
            goto L_8000624C;
    }
    // 0x80006238: nop

    // 0x8000623C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80006240: lw          $a0, 0x7768($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7768);
    // 0x80006244: jal         0x8005A5A0
    // 0x80006248: lw          $a1, -0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, -0X8);
    func_8005A5A0(rdram, ctx);
        goto after_13;
    // 0x80006248: lw          $a1, -0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, -0X8);
    after_13:
L_8000624C:
    // 0x8000624C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80006250: addiu       $a0, $a0, 0x7784
    ctx->r4 = ADD32(ctx->r4, 0X7784);
    // 0x80006254: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80006258: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000625C: beq         $v1, $v0, L_8000627C
    if (ctx->r3 == ctx->r2) {
        // 0x80006260: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8000627C;
    }
    // 0x80006260: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80006264: bne         $v0, $zero, L_800062E0
    if (ctx->r2 != 0) {
        // 0x80006268: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800062E0;
    }
    // 0x80006268: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000626C: beq         $v1, $v0, L_800062A4
    if (ctx->r3 == ctx->r2) {
        // 0x80006270: nop
    
            goto L_800062A4;
    }
    // 0x80006270: nop

    // 0x80006274: j           L_800062E0
    // 0x80006278: nop

        goto L_800062E0;
    // 0x80006278: nop

L_8000627C:
    // 0x8000627C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006280: lwc1        $f0, 0x778C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X778C);
    // 0x80006284: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006288: lwc1        $f2, 0x7788($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7788);
    // 0x8000628C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80006290: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006294: lwc1        $f2, 0x7790($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7790);
    // 0x80006298: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8000629C: j           L_800062C4
    // 0x800062A0: nop

        goto L_800062C4;
    // 0x800062A0: nop

L_800062A4:
    // 0x800062A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800062A8: lwc1        $f0, 0x778C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X778C);
    // 0x800062AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800062B0: lwc1        $f2, 0x7788($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7788);
    // 0x800062B4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800062B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800062BC: lwc1        $f2, 0x7790($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7790);
    // 0x800062C0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
L_800062C4:
    // 0x800062C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800062C8: swc1        $f0, 0x778C($at)
    MEM_W(0X778C, ctx->r1) = ctx->f0.u32l;
    // 0x800062CC: bc1f        L_800062E0
    if (!c1cs) {
        // 0x800062D0: nop
    
            goto L_800062E0;
    }
    // 0x800062D0: nop

    // 0x800062D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800062D8: swc1        $f2, 0x778C($at)
    MEM_W(0X778C, ctx->r1) = ctx->f2.u32l;
    // 0x800062DC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_800062E0:
    // 0x800062E0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800062E4: lw          $v1, 0x7760($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7760);
    // 0x800062E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800062EC: beq         $v1, $v0, L_80006358
    if (ctx->r3 == ctx->r2) {
        // 0x800062F0: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80006358;
    }
    // 0x800062F0: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800062F4: bne         $v0, $zero, L_80006358
    if (ctx->r2 != 0) {
        // 0x800062F8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80006358;
    }
    // 0x800062F8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800062FC: beq         $v1, $v0, L_80006314
    if (ctx->r3 == ctx->r2) {
        // 0x80006300: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80006314;
    }
    // 0x80006300: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80006304: beq         $v1, $v0, L_80006320
    if (ctx->r3 == ctx->r2) {
        // 0x80006308: nop
    
            goto L_80006320;
    }
    // 0x80006308: nop

    // 0x8000630C: j           L_80006358
    // 0x80006310: nop

        goto L_80006358;
    // 0x80006310: nop

L_80006314:
    // 0x80006314: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80006318: j           L_8000634C
    // 0x8000631C: lw          $a0, 0x7764($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7764);
        goto L_8000634C;
    // 0x8000631C: lw          $a0, 0x7764($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7764);
L_80006320:
    // 0x80006320: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80006324: lw          $a0, 0x7764($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7764);
    // 0x80006328: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000632C: jal         0x8005A744
    // 0x80006330: lw          $a1, 0x778C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X778C);
    func_8005A744(rdram, ctx);
        goto after_14;
    // 0x80006330: lw          $a1, 0x778C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X778C);
    after_14:
    // 0x80006334: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80006338: lbu         $v0, 0x2085($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2085);
    // 0x8000633C: bne         $v0, $zero, L_80006358
    if (ctx->r2 != 0) {
        // 0x80006340: nop
    
            goto L_80006358;
    }
    // 0x80006340: nop

    // 0x80006344: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80006348: lw          $a0, 0x7768($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7768);
L_8000634C:
    // 0x8000634C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80006350: jal         0x8005A744
    // 0x80006354: lw          $a1, 0x778C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X778C);
    func_8005A744(rdram, ctx);
        goto after_15;
    // 0x80006354: lw          $a1, 0x778C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X778C);
    after_15:
L_80006358:
    // 0x80006358: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8000635C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80006360: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80006364: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80006368: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000636C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80006370: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80006374: jr          $ra
    // 0x80006378: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80006378: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8000637C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000637C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80006380: lbu         $v0, 0x2074($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2074);
    // 0x80006384: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80006388: bne         $v0, $zero, L_800063A8
    if (ctx->r2 != 0) {
        // 0x8000638C: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_800063A8;
    }
    // 0x8000638C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80006390: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80006394: lbu         $v0, 0x2079($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2079);
    // 0x80006398: bne         $v0, $zero, L_800063AC
    if (ctx->r2 != 0) {
        // 0x8000639C: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_800063AC;
    }
    // 0x8000639C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800063A0: j           L_80006424
    // 0x800063A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80006424;
    // 0x800063A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800063A8:
    // 0x800063A8: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
L_800063AC:
    // 0x800063AC: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x800063B0: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x800063B4: lw          $t1, -0x1CC0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X1CC0);
    // 0x800063B8: bne         $a1, $zero, L_800063E4
    if (ctx->r5 != 0) {
        // 0x800063BC: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_800063E4;
    }
    // 0x800063BC: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x800063C0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800063C4: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800063C8: lbu         $a1, -0x1E00($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X1E00);
    // 0x800063CC: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x800063D0: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x800063D4: lbu         $a2, -0x1DFF($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X1DFF);
    // 0x800063D8: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x800063DC: j           L_80006404
    // 0x800063E0: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
        goto L_80006404;
    // 0x800063E0: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
L_800063E4:
    // 0x800063E4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800063E8: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800063EC: lbu         $a1, -0x1D60($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X1D60);
    // 0x800063F0: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x800063F4: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x800063F8: lbu         $a2, -0x1D5F($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X1D5F);
    // 0x800063FC: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x80006400: addiu       $t0, $zero, 0xC0
    ctx->r8 = ADD32(0, 0XC0);
L_80006404:
    // 0x80006404: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80006408: lbu         $v1, 0x2085($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2085);
    // 0x8000640C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80006410: beql        $v1, $v0, L_80006418
    if (ctx->r3 == ctx->r2) {
        // 0x80006414: addiu       $t0, $zero, 0x80
        ctx->r8 = ADD32(0, 0X80);
            goto L_80006418;
    }
    goto skip_0;
    // 0x80006414: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    skip_0:
L_80006418:
    // 0x80006418: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8000641C: jal         0x8000658C
    // 0x80006420: addu        $a0, $t1, $zero
    ctx->r4 = ADD32(ctx->r9, 0);
    func_8000658C(rdram, ctx);
        goto after_0;
    // 0x80006420: addu        $a0, $t1, $zero
    ctx->r4 = ADD32(ctx->r9, 0);
    after_0:
L_80006424:
    // 0x80006424: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80006428: jr          $ra
    // 0x8000642C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8000642C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80006430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006430: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80006434: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80006438: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8000643C: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80006440: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80006444: lw          $t1, -0x1CC0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X1CC0);
    // 0x80006448: bne         $a1, $zero, L_80006474
    if (ctx->r5 != 0) {
        // 0x8000644C: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_80006474;
    }
    // 0x8000644C: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80006450: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80006454: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80006458: lbu         $a1, -0x1E00($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X1E00);
    // 0x8000645C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80006460: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x80006464: lbu         $a2, -0x1DFF($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X1DFF);
    // 0x80006468: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x8000646C: j           L_80006494
    // 0x80006470: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
        goto L_80006494;
    // 0x80006470: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
L_80006474:
    // 0x80006474: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80006478: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8000647C: lbu         $a1, -0x1D60($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X1D60);
    // 0x80006480: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80006484: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x80006488: lbu         $a2, -0x1D5F($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X1D5F);
    // 0x8000648C: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x80006490: addiu       $t0, $zero, 0xC0
    ctx->r8 = ADD32(0, 0XC0);
L_80006494:
    // 0x80006494: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80006498: lbu         $v1, 0x2085($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2085);
    // 0x8000649C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800064A0: beql        $v1, $v0, L_800064A8
    if (ctx->r3 == ctx->r2) {
        // 0x800064A4: addiu       $t0, $zero, 0x80
        ctx->r8 = ADD32(0, 0X80);
            goto L_800064A8;
    }
    goto skip_0;
    // 0x800064A4: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    skip_0:
L_800064A8:
    // 0x800064A8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800064AC: jal         0x8000658C
    // 0x800064B0: addu        $a0, $t1, $zero
    ctx->r4 = ADD32(ctx->r9, 0);
    func_8000658C(rdram, ctx);
        goto after_0;
    // 0x800064B0: addu        $a0, $t1, $zero
    ctx->r4 = ADD32(ctx->r9, 0);
    after_0:
    // 0x800064B4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800064B8: jr          $ra
    // 0x800064BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800064BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800064C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800064C0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800064C4: lbu         $v0, 0x2074($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2074);
    // 0x800064C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800064CC: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x800064D0: bne         $v0, $zero, L_800064F0
    if (ctx->r2 != 0) {
        // 0x800064D4: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_800064F0;
    }
    // 0x800064D4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800064D8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800064DC: lbu         $v0, 0x2079($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2079);
    // 0x800064E0: bne         $v0, $zero, L_800064F4
    if (ctx->r2 != 0) {
        // 0x800064E4: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800064F4;
    }
    // 0x800064E4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800064E8: j           L_8000652C
    // 0x800064EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000652C;
    // 0x800064EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800064F0:
    // 0x800064F0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_800064F4:
    // 0x800064F4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800064F8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800064FC: lw          $a0, -0x1CC0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1CC0);
    // 0x80006500: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80006504: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80006508: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8000650C: lbu         $a1, -0x1EA0($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X1EA0);
    // 0x80006510: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80006514: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x80006518: lbu         $a2, -0x1E9F($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X1E9F);
    // 0x8000651C: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x80006520: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x80006524: jal         0x8000658C
    // 0x80006528: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_8000658C(rdram, ctx);
        goto after_0;
    // 0x80006528: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
L_8000652C:
    // 0x8000652C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80006530: jr          $ra
    // 0x80006534: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80006534: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80006538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006538: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000653C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80006540: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80006544: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80006548: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8000654C: lw          $v1, -0x1CC0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1CC0);
    // 0x80006550: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x80006554: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80006558: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // 0x8000655C: lbu         $a1, -0x1EA0($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X1EA0);
    // 0x80006560: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80006564: addu        $a2, $a2, $a0
    ctx->r6 = ADD32(ctx->r6, ctx->r4);
    // 0x80006568: lbu         $a2, -0x1E9F($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X1E9F);
    // 0x8000656C: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x80006570: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x80006574: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80006578: jal         0x8000658C
    // 0x8000657C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8000658C(rdram, ctx);
        goto after_0;
    // 0x8000657C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_0:
    // 0x80006580: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80006584: jr          $ra
    // 0x80006588: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80006588: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8000658C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000658C: sll         $v0, $a1, 5
    ctx->r2 = S32(ctx->r5 << 5);
    // 0x80006590: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80006594: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80006598: lw          $v1, 0x3DF0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3DF0);
    // 0x8000659C: lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10);
    // 0x800065A0: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x800065A4: beq         $v0, $zero, L_80006700
    if (ctx->r2 == 0) {
        // 0x800065A8: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_80006700;
    }
    // 0x800065A8: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x800065AC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800065B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800065B4: addu        $at, $at, $v0
    gpr jr_addend_800065BC = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800065B8: lw          $v0, -0x3630($at)
    ctx->r2 = ADD32(ctx->r1, -0X3630);
    // 0x800065BC: jr          $v0
    // 0x800065C0: nop

    switch (jr_addend_800065BC >> 2) {
        case 0: goto L_800065C4; break;
        case 1: goto L_8000661C; break;
        case 2: goto L_80006644; break;
        case 3: goto L_80006694; break;
        case 4: goto L_8000666C; break;
        case 5: goto L_80006694; break;
        default: switch_error(__func__, 0x800065BC, 0x800AC9D0);
    }
    // 0x800065C0: nop

L_800065C4:
    // 0x800065C4: sll         $v0, $a1, 5
    ctx->r2 = S32(ctx->r5 << 5);
    // 0x800065C8: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800065CC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800065D0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800065D4: sw          $v1, 0x3DF0($at)
    MEM_W(0X3DF0, ctx->r1) = ctx->r3;
    // 0x800065D8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800065DC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800065E0: sw          $a0, 0x3DF8($at)
    MEM_W(0X3DF8, ctx->r1) = ctx->r4;
    // 0x800065E4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800065E8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800065EC: sw          $a2, 0x3DFC($at)
    MEM_W(0X3DFC, ctx->r1) = ctx->r6;
    // 0x800065F0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800065F4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800065F8: sw          $a1, 0x3E00($at)
    MEM_W(0X3E00, ctx->r1) = ctx->r5;
    // 0x800065FC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80006600: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80006604: sw          $t1, 0x3E04($at)
    MEM_W(0X3E04, ctx->r1) = ctx->r9;
    // 0x80006608: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000660C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80006610: sw          $a3, 0x3E08($at)
    MEM_W(0X3E08, ctx->r1) = ctx->r7;
    // 0x80006614: j           L_80006700
    // 0x80006618: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80006700;
    // 0x80006618: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8000661C:
    // 0x8000661C: sll         $v1, $a1, 5
    ctx->r3 = S32(ctx->r5 << 5);
    // 0x80006620: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80006624: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80006628: lw          $v0, 0x3DFC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3DFC);
    // 0x8000662C: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80006630: bne         $v0, $zero, L_80006700
    if (ctx->r2 != 0) {
        // 0x80006634: nop
    
            goto L_80006700;
    }
    // 0x80006634: nop

    // 0x80006638: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000663C: j           L_800066B8
    // 0x80006640: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800066B8;
    // 0x80006640: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80006644:
    // 0x80006644: sll         $v1, $a1, 5
    ctx->r3 = S32(ctx->r5 << 5);
    // 0x80006648: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000664C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80006650: lw          $v0, 0x3DFC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3DFC);
    // 0x80006654: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80006658: bne         $v0, $zero, L_80006700
    if (ctx->r2 != 0) {
        // 0x8000665C: nop
    
            goto L_80006700;
    }
    // 0x8000665C: nop

    // 0x80006660: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80006664: j           L_800066B8
    // 0x80006668: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800066B8;
    // 0x80006668: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8000666C:
    // 0x8000666C: sll         $v1, $a1, 5
    ctx->r3 = S32(ctx->r5 << 5);
    // 0x80006670: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80006674: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80006678: lw          $v0, 0x3DFC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3DFC);
    // 0x8000667C: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80006680: bne         $v0, $zero, L_80006700
    if (ctx->r2 != 0) {
        // 0x80006684: nop
    
            goto L_80006700;
    }
    // 0x80006684: nop

    // 0x80006688: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000668C: j           L_800066B8
    // 0x80006690: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_800066B8;
    // 0x80006690: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80006694:
    // 0x80006694: sll         $v1, $a1, 5
    ctx->r3 = S32(ctx->r5 << 5);
    // 0x80006698: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8000669C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800066A0: lw          $v0, 0x3DFC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3DFC);
    // 0x800066A4: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800066A8: bne         $v0, $zero, L_80006700
    if (ctx->r2 != 0) {
        // 0x800066AC: nop
    
            goto L_80006700;
    }
    // 0x800066AC: nop

    // 0x800066B0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800066B4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800066B8:
    // 0x800066B8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800066BC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800066C0: sw          $v0, 0x3DF0($at)
    MEM_W(0X3DF0, ctx->r1) = ctx->r2;
    // 0x800066C4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800066C8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800066CC: sw          $a0, 0x3DF8($at)
    MEM_W(0X3DF8, ctx->r1) = ctx->r4;
    // 0x800066D0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800066D4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800066D8: sw          $a2, 0x3DFC($at)
    MEM_W(0X3DFC, ctx->r1) = ctx->r6;
    // 0x800066DC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800066E0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800066E4: sw          $a1, 0x3E00($at)
    MEM_W(0X3E00, ctx->r1) = ctx->r5;
    // 0x800066E8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800066EC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800066F0: sw          $t1, 0x3E04($at)
    MEM_W(0X3E04, ctx->r1) = ctx->r9;
    // 0x800066F4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800066F8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800066FC: sw          $a3, 0x3E08($at)
    MEM_W(0X3E08, ctx->r1) = ctx->r7;
L_80006700:
    // 0x80006700: jr          $ra
    // 0x80006704: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    return;
    // 0x80006704: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
;}
RECOMP_FUNC void func_80006708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006708: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000670C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80006710: lui         $s4, 0x800B
    ctx->r20 = S32(0X800B << 16);
    // 0x80006714: addiu       $s4, $s4, -0x3618
    ctx->r20 = ADD32(ctx->r20, -0X3618);
    // 0x80006718: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8000671C: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
    // 0x80006720: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80006724: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80006728: addiu       $s0, $s0, 0x3DF0
    ctx->r16 = ADD32(ctx->r16, 0X3DF0);
    // 0x8000672C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80006730: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80006734: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80006738: addiu       $s3, $s0, 0x120
    ctx->r19 = ADD32(ctx->r16, 0X120);
    // 0x8000673C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_80006740:
    // 0x80006740: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80006744: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x80006748: beq         $v0, $zero, L_80006780
    if (ctx->r2 == 0) {
        // 0x8000674C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80006780;
    }
    // 0x8000674C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80006750: addu        $v0, $v0, $s4
    gpr jr_addend_80006758 = ctx->r2;
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80006754: lw          $v0, 0x0($v0)
    ctx->r2 = ADD32(ctx->r2, 0X0);
    // 0x80006758: jr          $v0
    // 0x8000675C: nop

    switch (jr_addend_80006758 >> 2) {
        case 0: goto L_80006774; break;
        case 1: goto L_80006760; break;
        case 2: goto L_80006760; break;
        case 3: goto L_80006774; break;
        case 4: goto L_8000677C; break;
        case 5: goto L_80006780; break;
        default: switch_error(__func__, 0x80006758, 0x800AC9E8);
    }
    // 0x8000675C: nop

L_80006760:
    // 0x80006760: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80006764: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    // 0x80006768: lw          $a0, 0x3DF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3DF4);
    // 0x8000676C: jal         0x8005A3F8
    // 0x80006770: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8005A3F8(rdram, ctx);
        goto after_0;
    // 0x80006770: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
L_80006774:
    // 0x80006774: j           L_80006780
    // 0x80006778: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
        goto L_80006780;
    // 0x80006778: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
L_8000677C:
    // 0x8000677C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_80006780:
    // 0x80006780: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x80006784: slt         $v0, $s0, $s3
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80006788: bne         $v0, $zero, L_80006740
    if (ctx->r2 != 0) {
        // 0x8000678C: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_80006740;
    }
    // 0x8000678C: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x80006790: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80006794: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80006798: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8000679C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800067A0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800067A4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800067A8: jr          $ra
    // 0x800067AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800067AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800067B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800067B0: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x800067B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800067B8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800067BC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800067C0: jr          $ra
    // 0x800067C4: sw          $v0, 0x3E0C($at)
    MEM_W(0X3E0C, ctx->r1) = ctx->r2;
    return;
    // 0x800067C4: sw          $v0, 0x3E0C($at)
    MEM_W(0X3E0C, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_800067C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800067C8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800067CC: lbu         $v0, 0x2074($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2074);
    // 0x800067D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800067D4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800067D8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800067DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800067E0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800067E4: bne         $v0, $zero, L_800067FC
    if (ctx->r2 != 0) {
        // 0x800067E8: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_800067FC;
    }
    // 0x800067E8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800067EC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800067F0: lbu         $v0, 0x2079($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2079);
    // 0x800067F4: beq         $v0, $zero, L_8000692C
    if (ctx->r2 == 0) {
        // 0x800067F8: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8000692C;
    }
    // 0x800067F8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800067FC:
    // 0x800067FC: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80006800: addiu       $s1, $s1, 0x7760
    ctx->r17 = ADD32(ctx->r17, 0X7760);
    // 0x80006804: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80006808: bne         $v0, $zero, L_8000685C
    if (ctx->r2 != 0) {
        // 0x8000680C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8000685C;
    }
    // 0x8000680C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80006810: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x80006814: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80006818: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x8000681C: sw          $a0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r4;
    // 0x80006820: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006824: sw          $zero, 0x7764($at)
    MEM_W(0X7764, ctx->r1) = 0;
    // 0x80006828: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000682C: sw          $zero, 0x7768($at)
    MEM_W(0X7768, ctx->r1) = 0;
    // 0x80006830: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80006834: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80006838: lw          $v0, -0x20A0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X20A0);
    // 0x8000683C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80006840: lbu         $v1, 0x2085($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2085);
    // 0x80006844: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006848: sw          $v0, 0x776C($at)
    MEM_W(0X776C, ctx->r1) = ctx->r2;
    // 0x8000684C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80006850: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80006854: j           L_800068C8
    // 0x80006858: lw          $v0, -0x209C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X209C);
        goto L_800068C8;
    // 0x80006858: lw          $v0, -0x209C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X209C);
L_8000685C:
    // 0x8000685C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80006860: lw          $a0, 0x7764($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7764);
    // 0x80006864: jal         0x8005A3F8
    // 0x80006868: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8005A3F8(rdram, ctx);
        goto after_0;
    // 0x80006868: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8000686C: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x80006870: addiu       $s2, $s2, 0x2085
    ctx->r18 = ADD32(ctx->r18, 0X2085);
    // 0x80006874: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x80006878: bne         $v0, $zero, L_80006894
    if (ctx->r2 != 0) {
        // 0x8000687C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80006894;
    }
    // 0x8000687C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80006880: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80006884: lw          $a0, 0x7768($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7768);
    // 0x80006888: jal         0x8005A3F8
    // 0x8000688C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8005A3F8(rdram, ctx);
        goto after_1;
    // 0x8000688C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x80006890: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80006894:
    // 0x80006894: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x80006898: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8000689C: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x800068A0: sw          $a0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r4;
    // 0x800068A4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800068A8: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800068AC: lw          $v0, -0x20A0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X20A0);
    // 0x800068B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800068B4: sw          $v0, 0x776C($at)
    MEM_W(0X776C, ctx->r1) = ctx->r2;
    // 0x800068B8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800068BC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800068C0: lw          $v0, -0x209C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X209C);
    // 0x800068C4: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
L_800068C8:
    // 0x800068C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800068CC: sw          $v0, 0x7770($at)
    MEM_W(0X7770, ctx->r1) = ctx->r2;
    // 0x800068D0: bne         $v1, $a0, L_800068F4
    if (ctx->r3 != ctx->r4) {
        // 0x800068D4: addiu       $v0, $zero, 0x80
        ctx->r2 = ADD32(0, 0X80);
            goto L_800068F4;
    }
    // 0x800068D4: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x800068D8: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x800068DC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800068E0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800068E4: lw          $v0, -0x1F20($at)
    ctx->r2 = MEM_W(ctx->r1, -0X1F20);
    // 0x800068E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800068EC: sw          $v0, 0x776C($at)
    MEM_W(0X776C, ctx->r1) = ctx->r2;
    // 0x800068F0: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
L_800068F4:
    // 0x800068F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800068F8: sw          $v0, 0x7774($at)
    MEM_W(0X7774, ctx->r1) = ctx->r2;
    // 0x800068FC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80006900: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80006904: lw          $v0, -0x2098($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2098);
    // 0x80006908: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000690C: sw          $zero, 0x777C($at)
    MEM_W(0X777C, ctx->r1) = 0;
    // 0x80006910: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006914: sw          $zero, 0x7784($at)
    MEM_W(0X7784, ctx->r1) = 0;
    // 0x80006918: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000691C: sw          $zero, 0x778C($at)
    MEM_W(0X778C, ctx->r1) = 0;
    // 0x80006920: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006924: sw          $v0, 0x7778($at)
    MEM_W(0X7778, ctx->r1) = ctx->r2;
    // 0x80006928: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000692C:
    // 0x8000692C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80006930: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80006934: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80006938: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000693C: jr          $ra
    // 0x80006940: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80006940: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80006944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006944: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80006948: lw          $a0, 0x7764($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7764);
    // 0x8000694C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006950: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80006954: jal         0x8005A3F8
    // 0x80006958: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8005A3F8(rdram, ctx);
        goto after_0;
    // 0x80006958: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8000695C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80006960: lbu         $v0, 0x2085($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2085);
    // 0x80006964: bne         $v0, $zero, L_8000697C
    if (ctx->r2 != 0) {
        // 0x80006968: nop
    
            goto L_8000697C;
    }
    // 0x80006968: nop

    // 0x8000696C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80006970: lw          $a0, 0x7768($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7768);
    // 0x80006974: jal         0x8005A3F8
    // 0x80006978: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8005A3F8(rdram, ctx);
        goto after_1;
    // 0x80006978: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
L_8000697C:
    // 0x8000697C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006980: sw          $zero, 0x7760($at)
    MEM_W(0X7760, ctx->r1) = 0;
    // 0x80006984: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006988: sw          $zero, 0x777C($at)
    MEM_W(0X777C, ctx->r1) = 0;
    // 0x8000698C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80006990: jr          $ra
    // 0x80006994: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80006994: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80006998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006998: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000699C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800069A0: sw          $v0, 0x777C($at)
    MEM_W(0X777C, ctx->r1) = ctx->r2;
    // 0x800069A4: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x800069A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800069AC: sw          $v0, 0x7774($at)
    MEM_W(0X7774, ctx->r1) = ctx->r2;
    // 0x800069B0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800069B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800069B8: jr          $ra
    // 0x800069BC: sw          $v0, 0x7780($at)
    MEM_W(0X7780, ctx->r1) = ctx->r2;
    return;
    // 0x800069BC: sw          $v0, 0x7780($at)
    MEM_W(0X7780, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_800069C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800069C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800069C4: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x800069C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800069CC: sw          $v1, 0x777C($at)
    MEM_W(0X777C, ctx->r1) = ctx->r3;
    // 0x800069D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800069D4: sw          $v0, 0x7774($at)
    MEM_W(0X7774, ctx->r1) = ctx->r2;
    // 0x800069D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800069DC: jr          $ra
    // 0x800069E0: sw          $v1, 0x7780($at)
    MEM_W(0X7780, ctx->r1) = ctx->r3;
    return;
    // 0x800069E0: sw          $v1, 0x7780($at)
    MEM_W(0X7780, ctx->r1) = ctx->r3;
;}
RECOMP_FUNC void func_800069E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800069E4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800069E8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800069EC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800069F0: lwc1        $f2, -0x1B80($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X1B80);
    // 0x800069F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800069F8: lwc1        $f0, 0x778C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X778C);
    // 0x800069FC: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x80006A00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006A04: swc1        $f2, 0x7790($at)
    MEM_W(0X7790, ctx->r1) = ctx->f2.u32l;
    // 0x80006A08: bc1fl       L_80006A1C
    if (!c1cs) {
        // 0x80006A0C: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80006A1C;
    }
    goto skip_0;
    // 0x80006A0C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_0:
    // 0x80006A10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006A14: j           L_80006A70
    // 0x80006A18: sw          $zero, 0x7784($at)
    MEM_W(0X7784, ctx->r1) = 0;
        goto L_80006A70;
    // 0x80006A18: sw          $zero, 0x7784($at)
    MEM_W(0X7784, ctx->r1) = 0;
L_80006A1C:
    // 0x80006A1C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80006A20: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x80006A24: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80006A28: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x80006A2C: nop

    // 0x80006A30: nop

    // 0x80006A34: bc1f        L_80006A50
    if (!c1cs) {
        // 0x80006A38: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80006A50;
    }
    // 0x80006A38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80006A3C: lui         $at, 0x3D75
    ctx->r1 = S32(0X3D75 << 16);
    // 0x80006A40: ori         $at, $at, 0xC28F
    ctx->r1 = ctx->r1 | 0XC28F;
    // 0x80006A44: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80006A48: j           L_80006A60
    // 0x80006A4C: nop

        goto L_80006A60;
    // 0x80006A4C: nop

L_80006A50:
    // 0x80006A50: lui         $at, 0x3DF5
    ctx->r1 = S32(0X3DF5 << 16);
    // 0x80006A54: ori         $at, $at, 0xC28F
    ctx->r1 = ctx->r1 | 0XC28F;
    // 0x80006A58: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80006A5C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80006A60:
    // 0x80006A60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006A64: sw          $v0, 0x7784($at)
    MEM_W(0X7784, ctx->r1) = ctx->r2;
    // 0x80006A68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006A6C: swc1        $f0, 0x7788($at)
    MEM_W(0X7788, ctx->r1) = ctx->f0.u32l;
L_80006A70:
    // 0x80006A70: jr          $ra
    // 0x80006A74: nop

    return;
    // 0x80006A74: nop

;}
RECOMP_FUNC void func_80006A78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006A78: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80006A7C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80006A80: lw          $a0, 0x7764($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7764);
    // 0x80006A84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006A88: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80006A8C: addiu       $v1, $v1, -0x1B74
    ctx->r3 = ADD32(ctx->r3, -0X1B74);
    // 0x80006A90: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80006A94: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x80006A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006A9C: jal         0x8005A5A0
    // 0x80006AA0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_8005A5A0(rdram, ctx);
        goto after_0;
    // 0x80006AA0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x80006AA4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80006AA8: lbu         $v0, 0x2085($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2085);
    // 0x80006AAC: bne         $v0, $zero, L_80006AC4
    if (ctx->r2 != 0) {
        // 0x80006AB0: nop
    
            goto L_80006AC4;
    }
    // 0x80006AB0: nop

    // 0x80006AB4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80006AB8: lw          $a0, 0x7768($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7768);
    // 0x80006ABC: jal         0x8005A5A0
    // 0x80006AC0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_8005A5A0(rdram, ctx);
        goto after_1;
    // 0x80006AC0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_1:
L_80006AC4:
    // 0x80006AC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006AC8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80006ACC: jr          $ra
    // 0x80006AD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80006AD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80006AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006AE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80006AE4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80006AE8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80006AEC: addiu       $a0, $a0, 0x4800
    ctx->r4 = ADD32(ctx->r4, 0X4800);
    // 0x80006AF0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80006AF4: addiu       $a1, $a1, 0x7758
    ctx->r5 = ADD32(ctx->r5, 0X7758);
    // 0x80006AF8: jal         0x80061740
    // 0x80006AFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80006AFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80006B00: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80006B04: jr          $ra
    // 0x80006B08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80006B08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80006B0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006B0C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80006B10: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80006B14: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80006B18: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80006B1C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80006B20: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80006B24: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x80006B28: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80006B2C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80006B30: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80006B34: addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // 0x80006B38: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x80006B3C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80006B40: jal         0x80061490
    // 0x80006B44: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80006B44: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    after_0:
    // 0x80006B48: sltiu       $v0, $s1, 0x1001
    ctx->r2 = ctx->r17 < 0X1001 ? 1 : 0;
    // 0x80006B4C: bne         $v0, $zero, L_80006BA8
    if (ctx->r2 != 0) {
        // 0x80006B50: nop
    
            goto L_80006BA8;
    }
    // 0x80006B50: nop

    // 0x80006B54: addiu       $s5, $zero, 0x1000
    ctx->r21 = ADD32(0, 0X1000);
    // 0x80006B58: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x80006B5C: addiu       $s4, $s4, 0x4800
    ctx->r20 = ADD32(ctx->r20, 0X4800);
L_80006B60:
    // 0x80006B60: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80006B64: addiu       $a0, $a0, 0x2720
    ctx->r4 = ADD32(ctx->r4, 0X2720);
    // 0x80006B68: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006B6C: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    // 0x80006B70: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x80006B74: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80006B78: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x80006B7C: jal         0x800667A0
    // 0x80006B80: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    osPiStartDma_recomp(rdram, ctx);
        goto after_1;
    // 0x80006B80: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    after_1:
    // 0x80006B84: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80006B88: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006B8C: jal         0x800619A0
    // 0x80006B90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80006B90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80006B94: addiu       $s2, $s2, 0x1000
    ctx->r18 = ADD32(ctx->r18, 0X1000);
    // 0x80006B98: addiu       $s1, $s1, -0x1000
    ctx->r17 = ADD32(ctx->r17, -0X1000);
    // 0x80006B9C: sltiu       $v0, $s1, 0x1001
    ctx->r2 = ctx->r17 < 0X1001 ? 1 : 0;
    // 0x80006BA0: beq         $v0, $zero, L_80006B60
    if (ctx->r2 == 0) {
        // 0x80006BA4: addiu       $s0, $s0, 0x1000
        ctx->r16 = ADD32(ctx->r16, 0X1000);
            goto L_80006B60;
    }
    // 0x80006BA4: addiu       $s0, $s0, 0x1000
    ctx->r16 = ADD32(ctx->r16, 0X1000);
L_80006BA8:
    // 0x80006BA8: beq         $s1, $zero, L_80006BE8
    if (ctx->r17 == 0) {
        // 0x80006BAC: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80006BE8;
    }
    // 0x80006BAC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006BB0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80006BB4: addiu       $a0, $a0, 0x2720
    ctx->r4 = ADD32(ctx->r4, 0X2720);
    // 0x80006BB8: andi        $a2, $s3, 0xFF
    ctx->r6 = ctx->r19 & 0XFF;
    // 0x80006BBC: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x80006BC0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80006BC4: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80006BC8: addiu       $s0, $s0, 0x4800
    ctx->r16 = ADD32(ctx->r16, 0X4800);
    // 0x80006BCC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80006BD0: jal         0x800667A0
    // 0x80006BD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    osPiStartDma_recomp(rdram, ctx);
        goto after_3;
    // 0x80006BD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_3:
    // 0x80006BD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80006BDC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006BE0: jal         0x800619A0
    // 0x80006BE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80006BE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
L_80006BE8:
    // 0x80006BE8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80006BEC: addiu       $v1, $v1, 0x2090
    ctx->r3 = ADD32(ctx->r3, 0X2090);
    // 0x80006BF0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80006BF4: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80006BF8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80006BFC: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x80006C00: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80006C04: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80006C08: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80006C0C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80006C10: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80006C14: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80006C18: jr          $ra
    // 0x80006C1C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80006C1C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80006C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006C20: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80006C24: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80006C28: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80006C2C: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x80006C30: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80006C34: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80006C38: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80006C3C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80006C40: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80006C44: lw          $a1, 0x10($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X10);
    // 0x80006C48: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
    // 0x80006C4C: beq         $a1, $a0, L_80006C6C
    if (ctx->r5 == ctx->r4) {
        // 0x80006C50: nop
    
            goto L_80006C6C;
    }
    // 0x80006C50: nop

    // 0x80006C54: jal         0x80061540
    // 0x80006C58: subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    func_80061540(rdram, ctx);
        goto after_0;
    // 0x80006C58: subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    after_0:
    // 0x80006C5C: lw          $a0, 0xC($s3)
    ctx->r4 = MEM_W(ctx->r19, 0XC);
    // 0x80006C60: lw          $a1, 0x10($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X10);
    // 0x80006C64: jal         0x80061490
    // 0x80006C68: subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    osInvalDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x80006C68: subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    after_1:
L_80006C6C:
    // 0x80006C6C: lw          $a1, 0x18($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X18);
    // 0x80006C70: lw          $a0, 0x14($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X14);
    // 0x80006C74: beq         $a1, $a0, L_80006C84
    if (ctx->r5 == ctx->r4) {
        // 0x80006C78: nop
    
            goto L_80006C84;
    }
    // 0x80006C78: nop

    // 0x80006C7C: jal         0x80061490
    // 0x80006C80: subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    osInvalDCache_recomp(rdram, ctx);
        goto after_2;
    // 0x80006C80: subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    after_2:
L_80006C84:
    // 0x80006C84: lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4);
    // 0x80006C88: lw          $a3, 0x0($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X0);
    // 0x80006C8C: beq         $v0, $a3, L_80006D5C
    if (ctx->r2 == ctx->r7) {
        // 0x80006C90: addu        $s0, $a3, $zero
        ctx->r16 = ADD32(ctx->r7, 0);
            goto L_80006D5C;
    }
    // 0x80006C90: addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // 0x80006C94: lw          $s2, 0x8($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X8);
    // 0x80006C98: subu        $s1, $v0, $s0
    ctx->r17 = SUB32(ctx->r2, ctx->r16);
    // 0x80006C9C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80006CA0: jal         0x80061490
    // 0x80006CA4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    osInvalDCache_recomp(rdram, ctx);
        goto after_3;
    // 0x80006CA4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_3:
    // 0x80006CA8: sltiu       $v0, $s1, 0x1001
    ctx->r2 = ctx->r17 < 0X1001 ? 1 : 0;
    // 0x80006CAC: bne         $v0, $zero, L_80006D08
    if (ctx->r2 != 0) {
        // 0x80006CB0: nop
    
            goto L_80006D08;
    }
    // 0x80006CB0: nop

    // 0x80006CB4: addiu       $s5, $zero, 0x1000
    ctx->r21 = ADD32(0, 0X1000);
    // 0x80006CB8: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x80006CBC: addiu       $s4, $s4, 0x4800
    ctx->r20 = ADD32(ctx->r20, 0X4800);
L_80006CC0:
    // 0x80006CC0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80006CC4: addiu       $a0, $a0, 0x2720
    ctx->r4 = ADD32(ctx->r4, 0X2720);
    // 0x80006CC8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006CCC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80006CD0: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x80006CD4: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80006CD8: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x80006CDC: jal         0x800667A0
    // 0x80006CE0: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    osPiStartDma_recomp(rdram, ctx);
        goto after_4;
    // 0x80006CE0: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    after_4:
    // 0x80006CE4: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80006CE8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006CEC: jal         0x800619A0
    // 0x80006CF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80006CF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80006CF4: addiu       $s0, $s0, 0x1000
    ctx->r16 = ADD32(ctx->r16, 0X1000);
    // 0x80006CF8: addiu       $s1, $s1, -0x1000
    ctx->r17 = ADD32(ctx->r17, -0X1000);
    // 0x80006CFC: sltiu       $v0, $s1, 0x1001
    ctx->r2 = ctx->r17 < 0X1001 ? 1 : 0;
    // 0x80006D00: beq         $v0, $zero, L_80006CC0
    if (ctx->r2 == 0) {
        // 0x80006D04: addiu       $s2, $s2, 0x1000
        ctx->r18 = ADD32(ctx->r18, 0X1000);
            goto L_80006CC0;
    }
    // 0x80006D04: addiu       $s2, $s2, 0x1000
    ctx->r18 = ADD32(ctx->r18, 0X1000);
L_80006D08:
    // 0x80006D08: beq         $s1, $zero, L_80006D48
    if (ctx->r17 == 0) {
        // 0x80006D0C: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80006D48;
    }
    // 0x80006D0C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006D10: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80006D14: addiu       $a0, $a0, 0x2720
    ctx->r4 = ADD32(ctx->r4, 0X2720);
    // 0x80006D18: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80006D1C: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x80006D20: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80006D24: addiu       $s0, $s0, 0x4800
    ctx->r16 = ADD32(ctx->r16, 0X4800);
    // 0x80006D28: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80006D2C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80006D30: jal         0x800667A0
    // 0x80006D34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    osPiStartDma_recomp(rdram, ctx);
        goto after_6;
    // 0x80006D34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_6:
    // 0x80006D38: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80006D3C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006D40: jal         0x800619A0
    // 0x80006D44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80006D44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
L_80006D48:
    // 0x80006D48: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80006D4C: lw          $v0, 0x2090($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2090);
    // 0x80006D50: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80006D54: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80006D58: sw          $v0, 0x2090($at)
    MEM_W(0X2090, ctx->r1) = ctx->r2;
L_80006D5C:
    // 0x80006D5C: lw          $a1, 0x20($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X20);
    // 0x80006D60: lw          $a0, 0x1C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X1C);
    // 0x80006D64: beq         $a1, $a0, L_80006D74
    if (ctx->r5 == ctx->r4) {
        // 0x80006D68: nop
    
            goto L_80006D74;
    }
    // 0x80006D68: nop

    // 0x80006D6C: jal         0x80066B70
    // 0x80006D70: subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    bzero_recomp(rdram, ctx);
        goto after_8;
    // 0x80006D70: subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    after_8:
L_80006D74:
    // 0x80006D74: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x80006D78: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80006D7C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80006D80: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80006D84: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80006D88: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80006D8C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80006D90: jr          $ra
    // 0x80006D94: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80006D94: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80006D98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006D98: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80006D9C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80006DA0: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80006DA4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80006DA8: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80006DAC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80006DB0: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x80006DB4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80006DB8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80006DBC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80006DC0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80006DC4: jal         0x80061490
    // 0x80006DC8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80006DC8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    after_0:
    // 0x80006DCC: sltiu       $v0, $s1, 0x1001
    ctx->r2 = ctx->r17 < 0X1001 ? 1 : 0;
    // 0x80006DD0: bne         $v0, $zero, L_80006E2C
    if (ctx->r2 != 0) {
        // 0x80006DD4: nop
    
            goto L_80006E2C;
    }
    // 0x80006DD4: nop

    // 0x80006DD8: addiu       $s4, $zero, 0x1000
    ctx->r20 = ADD32(0, 0X1000);
    // 0x80006DDC: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80006DE0: addiu       $s3, $s3, 0x4800
    ctx->r19 = ADD32(ctx->r19, 0X4800);
L_80006DE4:
    // 0x80006DE4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80006DE8: addiu       $a0, $a0, 0x2720
    ctx->r4 = ADD32(ctx->r4, 0X2720);
    // 0x80006DEC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006DF0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80006DF4: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x80006DF8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80006DFC: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x80006E00: jal         0x800667A0
    // 0x80006E04: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    osPiStartDma_recomp(rdram, ctx);
        goto after_1;
    // 0x80006E04: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    after_1:
    // 0x80006E08: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80006E0C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006E10: jal         0x800619A0
    // 0x80006E14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80006E14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80006E18: addiu       $s2, $s2, 0x1000
    ctx->r18 = ADD32(ctx->r18, 0X1000);
    // 0x80006E1C: addiu       $s1, $s1, -0x1000
    ctx->r17 = ADD32(ctx->r17, -0X1000);
    // 0x80006E20: sltiu       $v0, $s1, 0x1001
    ctx->r2 = ctx->r17 < 0X1001 ? 1 : 0;
    // 0x80006E24: beq         $v0, $zero, L_80006DE4
    if (ctx->r2 == 0) {
        // 0x80006E28: addiu       $s0, $s0, 0x1000
        ctx->r16 = ADD32(ctx->r16, 0X1000);
            goto L_80006DE4;
    }
    // 0x80006E28: addiu       $s0, $s0, 0x1000
    ctx->r16 = ADD32(ctx->r16, 0X1000);
L_80006E2C:
    // 0x80006E2C: beq         $s1, $zero, L_80006E6C
    if (ctx->r17 == 0) {
        // 0x80006E30: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80006E6C;
    }
    // 0x80006E30: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006E34: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80006E38: addiu       $a0, $a0, 0x2720
    ctx->r4 = ADD32(ctx->r4, 0X2720);
    // 0x80006E3C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80006E40: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x80006E44: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80006E48: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80006E4C: addiu       $s0, $s0, 0x4800
    ctx->r16 = ADD32(ctx->r16, 0X4800);
    // 0x80006E50: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80006E54: jal         0x800667A0
    // 0x80006E58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    osPiStartDma_recomp(rdram, ctx);
        goto after_3;
    // 0x80006E58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_3:
    // 0x80006E5C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80006E60: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006E64: jal         0x800619A0
    // 0x80006E68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80006E68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
L_80006E6C:
    // 0x80006E6C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80006E70: lw          $v0, 0x2090($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2090);
    // 0x80006E74: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80006E78: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80006E7C: sw          $v0, 0x2090($at)
    MEM_W(0X2090, ctx->r1) = ctx->r2;
    // 0x80006E80: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80006E84: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80006E88: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80006E8C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80006E90: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80006E94: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80006E98: jr          $ra
    // 0x80006E9C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80006E9C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80006EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006EA0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80006EA4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80006EA8: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80006EAC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80006EB0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80006EB4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80006EB8: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x80006EBC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80006EC0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80006EC4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80006EC8: jal         0x80061490
    // 0x80006ECC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80006ECC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    after_0:
    // 0x80006ED0: sltiu       $v0, $s1, 0x1001
    ctx->r2 = ctx->r17 < 0X1001 ? 1 : 0;
    // 0x80006ED4: bne         $v0, $zero, L_80006F30
    if (ctx->r2 != 0) {
        // 0x80006ED8: nop
    
            goto L_80006F30;
    }
    // 0x80006ED8: nop

    // 0x80006EDC: addiu       $s4, $zero, 0x1000
    ctx->r20 = ADD32(0, 0X1000);
    // 0x80006EE0: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80006EE4: addiu       $s3, $s3, 0x4800
    ctx->r19 = ADD32(ctx->r19, 0X4800);
L_80006EE8:
    // 0x80006EE8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80006EEC: addiu       $a0, $a0, 0x2720
    ctx->r4 = ADD32(ctx->r4, 0X2720);
    // 0x80006EF0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006EF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80006EF8: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x80006EFC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80006F00: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x80006F04: jal         0x800667A0
    // 0x80006F08: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    osPiStartDma_recomp(rdram, ctx);
        goto after_1;
    // 0x80006F08: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    after_1:
    // 0x80006F0C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80006F10: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006F14: jal         0x800619A0
    // 0x80006F18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80006F18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80006F1C: addiu       $s2, $s2, 0x1000
    ctx->r18 = ADD32(ctx->r18, 0X1000);
    // 0x80006F20: addiu       $s1, $s1, -0x1000
    ctx->r17 = ADD32(ctx->r17, -0X1000);
    // 0x80006F24: sltiu       $v0, $s1, 0x1001
    ctx->r2 = ctx->r17 < 0X1001 ? 1 : 0;
    // 0x80006F28: beq         $v0, $zero, L_80006EE8
    if (ctx->r2 == 0) {
        // 0x80006F2C: addiu       $s0, $s0, 0x1000
        ctx->r16 = ADD32(ctx->r16, 0X1000);
            goto L_80006EE8;
    }
    // 0x80006F2C: addiu       $s0, $s0, 0x1000
    ctx->r16 = ADD32(ctx->r16, 0X1000);
L_80006F30:
    // 0x80006F30: beq         $s1, $zero, L_80006F70
    if (ctx->r17 == 0) {
        // 0x80006F34: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80006F70;
    }
    // 0x80006F34: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006F38: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80006F3C: addiu       $a0, $a0, 0x2720
    ctx->r4 = ADD32(ctx->r4, 0X2720);
    // 0x80006F40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80006F44: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x80006F48: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80006F4C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80006F50: addiu       $s0, $s0, 0x4800
    ctx->r16 = ADD32(ctx->r16, 0X4800);
    // 0x80006F54: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80006F58: jal         0x800667A0
    // 0x80006F5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    osPiStartDma_recomp(rdram, ctx);
        goto after_3;
    // 0x80006F5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_3:
    // 0x80006F60: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80006F64: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80006F68: jal         0x800619A0
    // 0x80006F6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80006F6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
L_80006F70:
    // 0x80006F70: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80006F74: lw          $v0, 0x2090($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2090);
    // 0x80006F78: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80006F7C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80006F80: sw          $v0, 0x2090($at)
    MEM_W(0X2090, ctx->r1) = ctx->r2;
    // 0x80006F84: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80006F88: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80006F8C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80006F90: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80006F94: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80006F98: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80006F9C: jr          $ra
    // 0x80006FA0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80006FA0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80006FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006FB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80006FB4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80006FB8: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80006FBC: addiu       $s0, $s0, 0x7BC0
    ctx->r16 = ADD32(ctx->r16, 0X7BC0);
    // 0x80006FC0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80006FC4: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x80006FC8: addiu       $s1, $s1, -0x35E0
    ctx->r17 = ADD32(ctx->r17, -0X35E0);
    // 0x80006FCC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
L_80006FD0:
    // 0x80006FD0: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80006FD4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80006FD8: lb          $v1, 0x5580($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X5580);
    // 0x80006FDC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80006FE0: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80006FE4: sltiu       $v0, $v1, 0xA
    ctx->r2 = ctx->r3 < 0XA ? 1 : 0;
    // 0x80006FE8: beq         $v0, $zero, L_80007038
    if (ctx->r2 == 0) {
        // 0x80006FEC: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80007038;
    }
    // 0x80006FEC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80006FF0: addu        $v0, $v0, $s1
    gpr jr_addend_80006FF8 = ctx->r2;
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80006FF4: lw          $v0, 0x0($v0)
    ctx->r2 = ADD32(ctx->r2, 0X0);
    // 0x80006FF8: jr          $v0
    // 0x80006FFC: nop

    switch (jr_addend_80006FF8 >> 2) {
        case 0: goto L_80007000; break;
        case 1: goto L_80007020; break;
        case 2: goto L_80007038; break;
        case 3: goto L_80007038; break;
        case 4: goto L_80007038; break;
        case 5: goto L_80007038; break;
        case 6: goto L_80007038; break;
        case 7: goto L_80007038; break;
        case 8: goto L_80007038; break;
        case 9: goto L_80007038; break;
        default: switch_error(__func__, 0x80006FF8, 0x800ACA20);
    }
    // 0x80006FFC: nop

L_80007000:
    // 0x80007000: jal         0x8002C568
    // 0x80007004: nop

    func_8002C568(rdram, ctx);
        goto after_0;
    // 0x80007004: nop

    after_0:
    // 0x80007008: jal         0x80003AA8
    // 0x8000700C: nop

    func_80003AA8(rdram, ctx);
        goto after_1;
    // 0x8000700C: nop

    after_1:
    // 0x80007010: jal         0x800070F4
    // 0x80007014: nop

    func_800070F4(rdram, ctx);
        goto after_2;
    // 0x80007014: nop

    after_2:
    // 0x80007018: j           L_80007038
    // 0x8000701C: nop

        goto L_80007038;
    // 0x8000701C: nop

L_80007020:
    // 0x80007020: jal         0x8000705C
    // 0x80007024: nop

    func_8000705C(rdram, ctx);
        goto after_3;
    // 0x80007024: nop

    after_3:
    // 0x80007028: jal         0x800070F4
    // 0x8000702C: nop

    func_800070F4(rdram, ctx);
        goto after_4;
    // 0x8000702C: nop

    after_4:
    // 0x80007030: jal         0x80003AA8
    // 0x80007034: nop

    func_80003AA8(rdram, ctx);
        goto after_5;
    // 0x80007034: nop

    after_5:
L_80007038:
    // 0x80007038: jal         0x80004644
    // 0x8000703C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80004644(rdram, ctx);
        goto after_6;
    // 0x8000703C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80007040: j           L_80006FD0
    // 0x80007044: nop

        goto L_80006FD0;
    // 0x80007044: nop

    // 0x80007048: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8000704C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80007050: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80007054: jr          $ra
    // 0x80007058: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80007058: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8000705C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000705C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007060: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80007064: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80007068: addiu       $s0, $s0, 0x7B70
    ctx->r16 = ADD32(ctx->r16, 0X7B70);
    // 0x8000706C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007070: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80007074: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80007078: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000707C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80007080: lw          $v0, -0xF0C($at)
    ctx->r2 = MEM_W(ctx->r1, -0XF0C);
    // 0x80007084: jalr        $v0
    // 0x80007088: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80007088: nop

    after_0:
    // 0x8000708C: jal         0x8002D634
    // 0x80007090: nop

    func_8002D634(rdram, ctx);
        goto after_1;
    // 0x80007090: nop

    after_1:
    // 0x80007094: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80007098: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000709C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800070A0: lb          $v0, -0xF2C($at)
    ctx->r2 = MEM_B(ctx->r1, -0XF2C);
    // 0x800070A4: beq         $v0, $zero, L_800070B4
    if (ctx->r2 == 0) {
        // 0x800070A8: nop
    
            goto L_800070B4;
    }
    // 0x800070A8: nop

    // 0x800070AC: jal         0x8002D5AC
    // 0x800070B0: nop

    func_8002D5AC(rdram, ctx);
        goto after_2;
    // 0x800070B0: nop

    after_2:
L_800070B4:
    // 0x800070B4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800070B8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800070BC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800070C0: lb          $v0, -0xF1C($at)
    ctx->r2 = MEM_B(ctx->r1, -0XF1C);
    // 0x800070C4: beq         $v0, $zero, L_800070D4
    if (ctx->r2 == 0) {
        // 0x800070C8: nop
    
            goto L_800070D4;
    }
    // 0x800070C8: nop

    // 0x800070CC: jal         0x8002D53C
    // 0x800070D0: nop

    func_8002D53C(rdram, ctx);
        goto after_3;
    // 0x800070D0: nop

    after_3:
L_800070D4:
    // 0x800070D4: jal         0x80011360
    // 0x800070D8: nop

    func_80011360(rdram, ctx);
        goto after_4;
    // 0x800070D8: nop

    after_4:
    // 0x800070DC: jal         0x800070FC
    // 0x800070E0: nop

    func_800070FC(rdram, ctx);
        goto after_5;
    // 0x800070E0: nop

    after_5:
    // 0x800070E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800070E8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800070EC: jr          $ra
    // 0x800070F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800070F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800070F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800070F4: jr          $ra
    // 0x800070F8: nop

    return;
    // 0x800070F8: nop

;}
RECOMP_FUNC void func_800070FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800070FC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80007100: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80007104: bne         $v0, $zero, L_80007330
    if (ctx->r2 != 0) {
        // 0x80007108: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_80007330;
    }
    // 0x80007108: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8000710C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80007110: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x80007114: beq         $v1, $v0, L_80007330
    if (ctx->r3 == ctx->r2) {
        // 0x80007118: nop
    
            goto L_80007330;
    }
    // 0x80007118: nop

    // 0x8000711C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80007120: lb          $v1, 0x25A1($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X25A1);
    // 0x80007124: blez        $v1, L_8000713C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80007128: nop
    
            goto L_8000713C;
    }
    // 0x80007128: nop

    // 0x8000712C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80007130: lb          $v0, 0x79F1($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F1);
    // 0x80007134: bgtz        $v0, L_80007178
    if (SIGNED(ctx->r2) > 0) {
        // 0x80007138: nop
    
            goto L_80007178;
    }
    // 0x80007138: nop

L_8000713C:
    // 0x8000713C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80007140: lb          $v0, 0x25FA($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25FA);
    // 0x80007144: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80007148: bne         $v0, $a0, L_80007158
    if (ctx->r2 != ctx->r4) {
        // 0x8000714C: nop
    
            goto L_80007158;
    }
    // 0x8000714C: nop

    // 0x80007150: bgtz        $v1, L_80007178
    if (SIGNED(ctx->r3) > 0) {
        // 0x80007154: nop
    
            goto L_80007178;
    }
    // 0x80007154: nop

L_80007158:
    // 0x80007158: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000715C: lb          $v0, 0x7A4A($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7A4A);
    // 0x80007160: bne         $v0, $a0, L_80007330
    if (ctx->r2 != ctx->r4) {
        // 0x80007164: nop
    
            goto L_80007330;
    }
    // 0x80007164: nop

    // 0x80007168: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000716C: lb          $v0, 0x79F1($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F1);
    // 0x80007170: blez        $v0, L_80007330
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80007174: nop
    
            goto L_80007330;
    }
    // 0x80007174: nop

L_80007178:
    // 0x80007178: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000717C: addiu       $a0, $a0, 0x7BA8
    ctx->r4 = ADD32(ctx->r4, 0X7BA8);
    // 0x80007180: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80007184: sltiu       $v0, $v1, 0x4
    ctx->r2 = ctx->r3 < 0X4 ? 1 : 0;
    // 0x80007188: beq         $v0, $zero, L_80007194
    if (ctx->r2 == 0) {
        // 0x8000718C: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80007194;
    }
    // 0x8000718C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80007190: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
L_80007194:
    // 0x80007194: lbu         $v0, -0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X2);
    // 0x80007198: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8000719C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800071A0: sb          $v0, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r2;
    // 0x800071A4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800071A8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800071AC: lw          $v1, -0xEC4($at)
    ctx->r3 = MEM_W(ctx->r1, -0XEC4);
    // 0x800071B0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800071B4: bne         $v0, $v1, L_80007258
    if (ctx->r2 != ctx->r3) {
        // 0x800071B8: addiu       $v1, $zero, 0x3C
        ctx->r3 = ADD32(0, 0X3C);
            goto L_80007258;
    }
    // 0x800071B8: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x800071BC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800071C0: lbu         $v0, 0x7BA7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7BA7);
    // 0x800071C4: sb          $zero, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = 0;
    // 0x800071C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800071CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800071D0: sb          $v0, 0x7BA7($at)
    MEM_B(0X7BA7, ctx->r1) = ctx->r2;
    // 0x800071D4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800071D8: bne         $v0, $v1, L_80007258
    if (ctx->r2 != ctx->r3) {
        // 0x800071DC: lui         $v1, 0xFFFF
        ctx->r3 = S32(0XFFFF << 16);
            goto L_80007258;
    }
    // 0x800071DC: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x800071E0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800071E4: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800071E8: lui         $v1, 0x3B63
    ctx->r3 = S32(0X3B63 << 16);
    // 0x800071EC: bnel        $v0, $v1, L_800071FC
    if (ctx->r2 != ctx->r3) {
        // 0x800071F0: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_800071FC;
    }
    goto skip_0;
    // 0x800071F0: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
    skip_0:
    // 0x800071F4: addiu       $v0, $zero, 0x3B
    ctx->r2 = ADD32(0, 0X3B);
    // 0x800071F8: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
L_800071FC:
    // 0x800071FC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80007200: addiu       $a0, $a0, 0x7BA8
    ctx->r4 = ADD32(ctx->r4, 0X7BA8);
    // 0x80007204: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80007208: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x8000720C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80007210: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x80007214: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80007218: bne         $v0, $v1, L_80007258
    if (ctx->r2 != ctx->r3) {
        // 0x8000721C: addiu       $v0, $zero, 0x63
        ctx->r2 = ADD32(0, 0X63);
            goto L_80007258;
    }
    // 0x8000721C: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x80007220: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80007224: lbu         $v1, 0x7BA9($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7BA9);
    // 0x80007228: bnel        $v1, $v0, L_80007238
    if (ctx->r3 != ctx->r2) {
        // 0x8000722C: sb          $zero, 0x0($a0)
        MEM_B(0X0, ctx->r4) = 0;
            goto L_80007238;
    }
    goto skip_1;
    // 0x8000722C: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    skip_1:
    // 0x80007230: addiu       $v0, $zero, 0x3B
    ctx->r2 = ADD32(0, 0X3B);
    // 0x80007234: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_80007238:
    // 0x80007238: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000723C: addiu       $a1, $a1, 0x7BA9
    ctx->r5 = ADD32(ctx->r5, 0X7BA9);
    // 0x80007240: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x80007244: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x80007248: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8000724C: beq         $v1, $v0, L_80007258
    if (ctx->r3 == ctx->r2) {
        // 0x80007250: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_80007258;
    }
    // 0x80007250: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80007254: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
L_80007258:
    // 0x80007258: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000725C: addiu       $v1, $v1, 0x7B80
    ctx->r3 = ADD32(ctx->r3, 0X7B80);
    // 0x80007260: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80007264: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80007268: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8000726C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80007270: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x80007274: bne         $a0, $v0, L_80007330
    if (ctx->r4 != ctx->r2) {
        // 0x80007278: nop
    
            goto L_80007330;
    }
    // 0x80007278: nop

    // 0x8000727C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80007280: lbu         $v0, 0x7B81($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B81);
    // 0x80007284: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80007288: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000728C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007290: sb          $v0, 0x7B81($at)
    MEM_B(0X7B81, ctx->r1) = ctx->r2;
    // 0x80007294: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80007298: bne         $v0, $a0, L_80007330
    if (ctx->r2 != ctx->r4) {
        // 0x8000729C: addiu       $v0, $zero, 0x63
        ctx->r2 = ADD32(0, 0X63);
            goto L_80007330;
    }
    // 0x8000729C: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x800072A0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800072A4: lbu         $v1, 0x7BA5($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7BA5);
    // 0x800072A8: bne         $v1, $v0, L_800072CC
    if (ctx->r3 != ctx->r2) {
        // 0x800072AC: addiu       $v0, $zero, 0x3B
        ctx->r2 = ADD32(0, 0X3B);
            goto L_800072CC;
    }
    // 0x800072AC: addiu       $v0, $zero, 0x3B
    ctx->r2 = ADD32(0, 0X3B);
    // 0x800072B0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800072B4: lbu         $v1, 0x7B82($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B82);
    // 0x800072B8: bne         $v1, $v0, L_800072CC
    if (ctx->r3 != ctx->r2) {
        // 0x800072BC: addiu       $v0, $zero, 0x3B
        ctx->r2 = ADD32(0, 0X3B);
            goto L_800072CC;
    }
    // 0x800072BC: addiu       $v0, $zero, 0x3B
    ctx->r2 = ADD32(0, 0X3B);
    // 0x800072C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800072C4: j           L_800072D4
    // 0x800072C8: sb          $v0, 0x7B81($at)
    MEM_B(0X7B81, ctx->r1) = ctx->r2;
        goto L_800072D4;
    // 0x800072C8: sb          $v0, 0x7B81($at)
    MEM_B(0X7B81, ctx->r1) = ctx->r2;
L_800072CC:
    // 0x800072CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800072D0: sb          $zero, 0x7B81($at)
    MEM_B(0X7B81, ctx->r1) = 0;
L_800072D4:
    // 0x800072D4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800072D8: addiu       $a0, $a0, 0x7B82
    ctx->r4 = ADD32(ctx->r4, 0X7B82);
    // 0x800072DC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800072E0: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x800072E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800072E8: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800072EC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800072F0: bne         $v0, $v1, L_80007330
    if (ctx->r2 != ctx->r3) {
        // 0x800072F4: addiu       $v0, $zero, 0x63
        ctx->r2 = ADD32(0, 0X63);
            goto L_80007330;
    }
    // 0x800072F4: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x800072F8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800072FC: lbu         $v1, 0x7BA5($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7BA5);
    // 0x80007300: bnel        $v1, $v0, L_80007310
    if (ctx->r3 != ctx->r2) {
        // 0x80007304: sb          $zero, 0x0($a0)
        MEM_B(0X0, ctx->r4) = 0;
            goto L_80007310;
    }
    goto skip_2;
    // 0x80007304: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    skip_2:
    // 0x80007308: addiu       $v0, $zero, 0x3B
    ctx->r2 = ADD32(0, 0X3B);
    // 0x8000730C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_80007310:
    // 0x80007310: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80007314: addiu       $a1, $a1, 0x7BA5
    ctx->r5 = ADD32(ctx->r5, 0X7BA5);
    // 0x80007318: lbu         $a0, 0x0($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X0);
    // 0x8000731C: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x80007320: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x80007324: beq         $v1, $v0, L_80007330
    if (ctx->r3 == ctx->r2) {
        // 0x80007328: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_80007330;
    }
    // 0x80007328: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8000732C: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
L_80007330:
    // 0x80007330: jr          $ra
    // 0x80007334: nop

    return;
    // 0x80007334: nop

;}
RECOMP_FUNC void func_80007338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007338: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000733C: lbu         $v1, 0x2614($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2614);
    // 0x80007340: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80007344: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80007348: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000734C: sb          $v0, 0x7BA0($at)
    MEM_B(0X7BA0, ctx->r1) = ctx->r2;
    // 0x80007350: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007354: sb          $v0, 0x7BAF($at)
    MEM_B(0X7BAF, ctx->r1) = ctx->r2;
    // 0x80007358: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000735C: sb          $v0, 0x7BAE($at)
    MEM_B(0X7BAE, ctx->r1) = ctx->r2;
    // 0x80007360: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007364: sb          $v0, 0x7BAD($at)
    MEM_B(0X7BAD, ctx->r1) = ctx->r2;
    // 0x80007368: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000736C: sb          $v0, 0x7BAC($at)
    MEM_B(0X7BAC, ctx->r1) = ctx->r2;
    // 0x80007370: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80007374: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80007378: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000737C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80007380: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80007384: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80007388: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000738C: sb          $zero, 0x7BB0($at)
    MEM_B(0X7BB0, ctx->r1) = 0;
    // 0x80007390: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007394: sb          $zero, 0x7B84($at)
    MEM_B(0X7B84, ctx->r1) = 0;
    // 0x80007398: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000739C: sw          $zero, 0x3F38($at)
    MEM_W(0X3F38, ctx->r1) = 0;
    // 0x800073A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800073A4: sw          $zero, 0x7BB8($at)
    MEM_W(0X7BB8, ctx->r1) = 0;
    // 0x800073A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800073AC: sw          $zero, 0x7BB4($at)
    MEM_W(0X7BB4, ctx->r1) = 0;
    // 0x800073B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800073B4: sb          $v0, 0x7B9E($at)
    MEM_B(0X7B9E, ctx->r1) = ctx->r2;
    // 0x800073B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800073BC: sb          $zero, 0x7B9F($at)
    MEM_B(0X7B9F, ctx->r1) = 0;
    // 0x800073C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800073C4: sb          $zero, 0x260D($at)
    MEM_B(0X260D, ctx->r1) = 0;
    // 0x800073C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800073CC: sb          $zero, 0x25F6($at)
    MEM_B(0X25F6, ctx->r1) = 0;
    // 0x800073D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800073D4: sb          $zero, 0x25F3($at)
    MEM_B(0X25F3, ctx->r1) = 0;
    // 0x800073D8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800073DC: sb          $zero, 0x25E8($at)
    MEM_B(0X25E8, ctx->r1) = 0;
    // 0x800073E0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800073E4: sb          $a0, 0x2609($at)
    MEM_B(0X2609, ctx->r1) = ctx->r4;
    // 0x800073E8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800073EC: sw          $zero, 0x264C($at)
    MEM_W(0X264C, ctx->r1) = 0;
    // 0x800073F0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800073F4: sw          $zero, 0x2648($at)
    MEM_W(0X2648, ctx->r1) = 0;
    // 0x800073F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800073FC: sw          $zero, 0x2644($at)
    MEM_W(0X2644, ctx->r1) = 0;
    // 0x80007400: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007404: sw          $zero, 0x2640($at)
    MEM_W(0X2640, ctx->r1) = 0;
    // 0x80007408: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000740C: sh          $zero, 0x263E($at)
    MEM_H(0X263E, ctx->r1) = 0;
    // 0x80007410: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007414: sh          $zero, 0x263C($at)
    MEM_H(0X263C, ctx->r1) = 0;
    // 0x80007418: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000741C: sh          $zero, 0x263A($at)
    MEM_H(0X263A, ctx->r1) = 0;
    // 0x80007420: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007424: sh          $zero, 0x2638($at)
    MEM_H(0X2638, ctx->r1) = 0;
    // 0x80007428: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000742C: sh          $zero, 0x2636($at)
    MEM_H(0X2636, ctx->r1) = 0;
    // 0x80007430: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007434: sb          $s1, 0x2605($at)
    MEM_B(0X2605, ctx->r1) = ctx->r17;
    // 0x80007438: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000743C: sb          $s1, 0x2604($at)
    MEM_B(0X2604, ctx->r1) = ctx->r17;
    // 0x80007440: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80007444: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80007448: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000744C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80007450: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80007454: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80007458: lbu         $v0, -0x3996($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X3996);
    // 0x8000745C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007460: sb          $zero, 0x7A5D($at)
    MEM_B(0X7A5D, ctx->r1) = 0;
    // 0x80007464: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007468: sb          $zero, 0x7A46($at)
    MEM_B(0X7A46, ctx->r1) = 0;
    // 0x8000746C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007470: sb          $v0, 0x2606($at)
    MEM_B(0X2606, ctx->r1) = ctx->r2;
    // 0x80007474: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007478: sb          $zero, 0x7A43($at)
    MEM_B(0X7A43, ctx->r1) = 0;
    // 0x8000747C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80007480: lbu         $v1, 0x7A64($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7A64);
    // 0x80007484: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007488: sb          $zero, 0x7A38($at)
    MEM_B(0X7A38, ctx->r1) = 0;
    // 0x8000748C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007490: sb          $a0, 0x7A59($at)
    MEM_B(0X7A59, ctx->r1) = ctx->r4;
    // 0x80007494: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007498: sw          $zero, 0x7A9C($at)
    MEM_W(0X7A9C, ctx->r1) = 0;
    // 0x8000749C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800074A0: sw          $zero, 0x7A98($at)
    MEM_W(0X7A98, ctx->r1) = 0;
    // 0x800074A4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800074A8: sw          $zero, 0x7A94($at)
    MEM_W(0X7A94, ctx->r1) = 0;
    // 0x800074AC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800074B0: sw          $zero, 0x7A90($at)
    MEM_W(0X7A90, ctx->r1) = 0;
    // 0x800074B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800074B8: sh          $zero, 0x7A8E($at)
    MEM_H(0X7A8E, ctx->r1) = 0;
    // 0x800074BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800074C0: sh          $zero, 0x7A8C($at)
    MEM_H(0X7A8C, ctx->r1) = 0;
    // 0x800074C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800074C8: sh          $zero, 0x7A8A($at)
    MEM_H(0X7A8A, ctx->r1) = 0;
    // 0x800074CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800074D0: sh          $zero, 0x7A88($at)
    MEM_H(0X7A88, ctx->r1) = 0;
    // 0x800074D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800074D8: sh          $zero, 0x7A86($at)
    MEM_H(0X7A86, ctx->r1) = 0;
    // 0x800074DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800074E0: sb          $s1, 0x7A55($at)
    MEM_B(0X7A55, ctx->r1) = ctx->r17;
    // 0x800074E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800074E8: sb          $s1, 0x7A54($at)
    MEM_B(0X7A54, ctx->r1) = ctx->r17;
    // 0x800074EC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800074F0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800074F4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800074F8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800074FC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80007500: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80007504: lbu         $v0, -0x3996($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X3996);
    // 0x80007508: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000750C: jal         0x8000BA44
    // 0x80007510: sb          $v0, 0x7A56($at)
    MEM_B(0X7A56, ctx->r1) = ctx->r2;
    func_8000BA44(rdram, ctx);
        goto after_0;
    // 0x80007510: sb          $v0, 0x7A56($at)
    MEM_B(0X7A56, ctx->r1) = ctx->r2;
    after_0:
    // 0x80007514: lui         $a0, 0x13
    ctx->r4 = S32(0X13 << 16);
    // 0x80007518: addiu       $a0, $a0, 0x1230
    ctx->r4 = ADD32(ctx->r4, 0X1230);
    // 0x8000751C: lui         $a1, 0x8028
    ctx->r5 = S32(0X8028 << 16);
    // 0x80007520: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
    // 0x80007524: jal         0x80006D98
    // 0x80007528: addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
    func_80006D98(rdram, ctx);
        goto after_1;
    // 0x80007528: addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
    after_1:
    // 0x8000752C: lui         $a0, 0x13
    ctx->r4 = S32(0X13 << 16);
    // 0x80007530: addiu       $a0, $a0, 0x2230
    ctx->r4 = ADD32(ctx->r4, 0X2230);
    // 0x80007534: lui         $a1, 0x8028
    ctx->r5 = S32(0X8028 << 16);
    // 0x80007538: addiu       $a1, $a1, 0x7800
    ctx->r5 = ADD32(ctx->r5, 0X7800);
    // 0x8000753C: jal         0x80006D98
    // 0x80007540: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    func_80006D98(rdram, ctx);
        goto after_2;
    // 0x80007540: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    after_2:
    // 0x80007544: lui         $a0, 0x13
    ctx->r4 = S32(0X13 << 16);
    // 0x80007548: addiu       $a0, $a0, 0x2A30
    ctx->r4 = ADD32(ctx->r4, 0X2A30);
    // 0x8000754C: lui         $a1, 0x8028
    ctx->r5 = S32(0X8028 << 16);
    // 0x80007550: addiu       $a1, $a1, 0x1000
    ctx->r5 = ADD32(ctx->r5, 0X1000);
    // 0x80007554: jal         0x80006D98
    // 0x80007558: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    func_80006D98(rdram, ctx);
        goto after_3;
    // 0x80007558: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    after_3:
    // 0x8000755C: lui         $s0, 0x12
    ctx->r16 = S32(0X12 << 16);
    // 0x80007560: addiu       $s0, $s0, -0x54C0
    ctx->r16 = ADD32(ctx->r16, -0X54C0);
    // 0x80007564: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80007568: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8000756C: addiu       $a1, $a1, -0x1B20
    ctx->r5 = ADD32(ctx->r5, -0X1B20);
    // 0x80007570: jal         0x80006D98
    // 0x80007574: addiu       $a2, $zero, 0x2680
    ctx->r6 = ADD32(0, 0X2680);
    func_80006D98(rdram, ctx);
        goto after_4;
    // 0x80007574: addiu       $a2, $zero, 0x2680
    ctx->r6 = ADD32(0, 0X2680);
    after_4:
    // 0x80007578: addiu       $a0, $s0, 0x2680
    ctx->r4 = ADD32(ctx->r16, 0X2680);
    // 0x8000757C: lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // 0x80007580: addiu       $s0, $s0, -0x2FC0
    ctx->r16 = ADD32(ctx->r16, -0X2FC0);
    // 0x80007584: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80007588: jal         0x80006D98
    // 0x8000758C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80006D98(rdram, ctx);
        goto after_5;
    // 0x8000758C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_5:
    // 0x80007590: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x80007594: addiu       $a0, $a0, -0x75F0
    ctx->r4 = ADD32(ctx->r4, -0X75F0);
    // 0x80007598: jal         0x800177F4
    // 0x8000759C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800177F4(rdram, ctx);
        goto after_6;
    // 0x8000759C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x800075A0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800075A4: lbu         $v1, 0x2074($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2074);
    // 0x800075A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800075AC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800075B0: sb          $s1, -0x75C6($at)
    MEM_B(-0X75C6, ctx->r1) = ctx->r17;
    // 0x800075B4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800075B8: sw          $s0, -0x75C0($at)
    MEM_W(-0X75C0, ctx->r1) = ctx->r16;
    // 0x800075BC: bne         $v1, $v0, L_800075D0
    if (ctx->r3 != ctx->r2) {
        // 0x800075C0: addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
            goto L_800075D0;
    }
    // 0x800075C0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x800075C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800075C8: j           L_800075D8
    // 0x800075CC: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
        goto L_800075D8;
    // 0x800075CC: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
L_800075D0:
    // 0x800075D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800075D4: sb          $s1, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r17;
L_800075D8:
    // 0x800075D8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800075DC: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x800075E0: jal         0x8002CFB8
    // 0x800075E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8002CFB8(rdram, ctx);
        goto after_7;
    // 0x800075E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // 0x800075E8: jal         0x8002D378
    // 0x800075EC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_8;
    // 0x800075EC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_8:
    // 0x800075F0: jal         0x8002D0D4
    // 0x800075F4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_9;
    // 0x800075F4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_9:
    // 0x800075F8: jal         0x8002EA40
    // 0x800075FC: nop

    func_8002EA40(rdram, ctx);
        goto after_10;
    // 0x800075FC: nop

    after_10:
    // 0x80007600: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80007604: addiu       $a0, $a0, 0x7B85
    ctx->r4 = ADD32(ctx->r4, 0X7B85);
    // 0x80007608: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x8000760C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80007610: beq         $v1, $v0, L_8000762C
    if (ctx->r3 == ctx->r2) {
        // 0x80007614: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000762C;
    }
    // 0x80007614: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007618: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000761C: sb          $v0, 0x7A3E($at)
    MEM_B(0X7A3E, ctx->r1) = ctx->r2;
    // 0x80007620: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007624: sb          $v0, 0x25EE($at)
    MEM_B(0X25EE, ctx->r1) = ctx->r2;
    // 0x80007628: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_8000762C:
    // 0x8000762C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80007630: addiu       $v1, $v1, 0x7B50
    ctx->r3 = ADD32(ctx->r3, 0X7B50);
    // 0x80007634: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80007638:
    // 0x80007638: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x8000763C: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x80007640: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x80007644: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007648: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8000764C: sb          $zero, 0x7B50($at)
    MEM_B(0X7B50, ctx->r1) = 0;
    // 0x80007650: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80007654: slti        $v0, $a0, 0x18
    ctx->r2 = SIGNED(ctx->r4) < 0X18 ? 1 : 0;
    // 0x80007658: bne         $v0, $zero, L_80007638
    if (ctx->r2 != 0) {
        // 0x8000765C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80007638;
    }
    // 0x8000765C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80007660: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80007664: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80007668: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000766C: jr          $ra
    // 0x80007670: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80007670: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80007674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007674: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007678: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000767C: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    // 0x80007680: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80007684: jal         0x8000C520
    // 0x80007688: nop

    func_8000C520(rdram, ctx);
        goto after_0;
    // 0x80007688: nop

    after_0:
    // 0x8000768C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80007690: jal         0x8000C520
    // 0x80007694: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    func_8000C520(rdram, ctx);
        goto after_1;
    // 0x80007694: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    after_1:
    // 0x80007698: jal         0x8000BA44
    // 0x8000769C: nop

    func_8000BA44(rdram, ctx);
        goto after_2;
    // 0x8000769C: nop

    after_2:
    // 0x800076A0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800076A4: lbu         $v1, 0x7B89($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B89);
    // 0x800076A8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800076AC: addiu       $a0, $a0, 0x7B70
    ctx->r4 = ADD32(ctx->r4, 0X7B70);
    // 0x800076B0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800076B4: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800076B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800076BC: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x800076C0: beq         $v1, $zero, L_800076E0
    if (ctx->r3 == 0) {
        // 0x800076C4: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_800076E0;
    }
    // 0x800076C4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800076C8: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800076CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800076D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800076D4: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x800076D8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800076DC: sb          $v0, 0x7BA4($at)
    MEM_B(0X7BA4, ctx->r1) = ctx->r2;
L_800076E0:
    // 0x800076E0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800076E4: jr          $ra
    // 0x800076E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800076E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800076EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800076EC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800076F0: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x800076F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800076F8: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800076FC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80007700: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x80007704: beq         $v0, $zero, L_800079C0
    if (ctx->r2 == 0) {
        // 0x80007708: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800079C0;
    }
    // 0x80007708: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000770C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80007710: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80007714: addu        $at, $at, $v0
    gpr jr_addend_8000771C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80007718: lw          $v0, -0x35A8($at)
    ctx->r2 = ADD32(ctx->r1, -0X35A8);
    // 0x8000771C: jr          $v0
    // 0x80007720: nop

    switch (jr_addend_8000771C >> 2) {
        case 0: goto L_80007724; break;
        case 1: goto L_800077BC; break;
        case 2: goto L_800077E8; break;
        case 3: goto L_80007870; break;
        case 4: goto L_800079C0; break;
        default: switch_error(__func__, 0x8000771C, 0x800ACA58);
    }
    // 0x80007720: nop

L_80007724:
    // 0x80007724: lui         $a0, 0x12
    ctx->r4 = S32(0X12 << 16);
    // 0x80007728: addiu       $a0, $a0, -0x9A0
    ctx->r4 = ADD32(ctx->r4, -0X9A0);
    // 0x8000772C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80007730: addiu       $s0, $s0, -0x5140
    ctx->r16 = ADD32(ctx->r16, -0X5140);
    // 0x80007734: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80007738: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000773C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007740: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x80007744: jal         0x80006D98
    // 0x80007748: addiu       $a2, $zero, 0xA20
    ctx->r6 = ADD32(0, 0XA20);
    func_80006D98(rdram, ctx);
        goto after_0;
    // 0x80007748: addiu       $a2, $zero, 0xA20
    ctx->r6 = ADD32(0, 0XA20);
    after_0:
    // 0x8000774C: jal         0x800067C8
    // 0x80007750: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800067C8(rdram, ctx);
        goto after_1;
    // 0x80007750: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_1:
    // 0x80007754: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x80007758: addiu       $s1, $s1, 0x6AA0
    ctx->r17 = ADD32(ctx->r17, 0X6AA0);
    // 0x8000775C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80007760: jal         0x800177F4
    // 0x80007764: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800177F4(rdram, ctx);
        goto after_2;
    // 0x80007764: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80007768: addiu       $a0, $s1, 0x70
    ctx->r4 = ADD32(ctx->r17, 0X70);
    // 0x8000776C: addiu       $s0, $s0, 0xA00
    ctx->r16 = ADD32(ctx->r16, 0XA00);
    // 0x80007770: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007774: sw          $s0, 0x6AD0($at)
    MEM_W(0X6AD0, ctx->r1) = ctx->r16;
    // 0x80007778: jal         0x800177F4
    // 0x8000777C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800177F4(rdram, ctx);
        goto after_3;
    // 0x8000777C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80007780: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007784: jal         0x8001C1F0
    // 0x80007788: sw          $s0, 0x6B40($at)
    MEM_W(0X6B40, ctx->r1) = ctx->r16;
    func_8001C1F0(rdram, ctx);
        goto after_4;
    // 0x80007788: sw          $s0, 0x6B40($at)
    MEM_W(0X6B40, ctx->r1) = ctx->r16;
    after_4:
    // 0x8000778C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80007790: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80007794: jal         0x8001D670
    // 0x80007798: addiu       $a0, $a0, -0x2338
    ctx->r4 = ADD32(ctx->r4, -0X2338);
    func_8001D670(rdram, ctx);
        goto after_5;
    // 0x80007798: addiu       $a0, $a0, -0x2338
    ctx->r4 = ADD32(ctx->r4, -0X2338);
    after_5:
    // 0x8000779C: jal         0x8002CFB8
    // 0x800077A0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8002CFB8(rdram, ctx);
        goto after_6;
    // 0x800077A0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // 0x800077A4: jal         0x8002D378
    // 0x800077A8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_7;
    // 0x800077A8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_7:
    // 0x800077AC: jal         0x8002D0D4
    // 0x800077B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_8;
    // 0x800077B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_8:
    // 0x800077B4: j           L_800079C0
    // 0x800077B8: nop

        goto L_800079C0;
    // 0x800077B8: nop

L_800077BC:
    // 0x800077BC: jal         0x8002CFB8
    // 0x800077C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_9;
    // 0x800077C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x800077C4: beq         $v0, $zero, L_800079C0
    if (ctx->r2 == 0) {
        // 0x800077C8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800079C0;
    }
    // 0x800077C8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800077CC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800077D0: lbu         $v1, 0x7B8E($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B8E);
    // 0x800077D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800077D8: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x800077DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800077E0: j           L_800079C0
    // 0x800077E4: sb          $v1, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r3;
        goto L_800079C0;
    // 0x800077E4: sb          $v1, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r3;
L_800077E8:
    // 0x800077E8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800077EC: lbu         $v0, 0x2071($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2071);
    // 0x800077F0: beq         $v0, $zero, L_8000781C
    if (ctx->r2 == 0) {
        // 0x800077F4: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8000781C;
    }
    // 0x800077F4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800077F8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800077FC: lbu         $v1, 0x7B89($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B89);
    // 0x80007800: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007804: bne         $v1, $zero, L_800079B8
    if (ctx->r3 != 0) {
        // 0x80007808: sb          $v0, 0x7B71($at)
        MEM_B(0X7B71, ctx->r1) = ctx->r2;
            goto L_800079B8;
    }
    // 0x80007808: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8000780C: jal         0x80003A14
    // 0x80007810: nop

    func_80003A14(rdram, ctx);
        goto after_10;
    // 0x80007810: nop

    after_10:
    // 0x80007814: j           L_800079B8
    // 0x80007818: nop

        goto L_800079B8;
    // 0x80007818: nop

L_8000781C:
    // 0x8000781C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80007820: lbu         $v0, 0x2084($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2084);
    // 0x80007824: beq         $v0, $zero, L_800079C0
    if (ctx->r2 == 0) {
        // 0x80007828: addiu       $v1, $zero, 0xE
        ctx->r3 = ADD32(0, 0XE);
            goto L_800079C0;
    }
    // 0x80007828: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
    // 0x8000782C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80007830: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x80007834: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007838: sb          $v1, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r3;
    // 0x8000783C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007840: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x80007844: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007848: sb          $zero, 0x7B84($at)
    MEM_B(0X7B84, ctx->r1) = 0;
    // 0x8000784C: lw          $v0, 0xD0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XD0);
    // 0x80007850: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80007854: sw          $zero, 0x3F38($at)
    MEM_W(0X3F38, ctx->r1) = 0;
    // 0x80007858: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8000785C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007860: sb          $zero, 0x7A67($at)
    MEM_B(0X7A67, ctx->r1) = 0;
    // 0x80007864: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007868: j           L_800079C0
    // 0x8000786C: sb          $zero, 0x2617($at)
    MEM_B(0X2617, ctx->r1) = 0;
        goto L_800079C0;
    // 0x8000786C: sb          $zero, 0x2617($at)
    MEM_B(0X2617, ctx->r1) = 0;
L_80007870:
    // 0x80007870: jal         0x8002CFB8
    // 0x80007874: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_11;
    // 0x80007874: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_11:
    // 0x80007878: beq         $v0, $zero, L_800079C0
    if (ctx->r2 == 0) {
        // 0x8000787C: addiu       $v1, $zero, 0xD
        ctx->r3 = ADD32(0, 0XD);
            goto L_800079C0;
    }
    // 0x8000787C: addiu       $v1, $zero, 0xD
    ctx->r3 = ADD32(0, 0XD);
    // 0x80007880: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80007884: lbu         $v0, 0x7B85($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B85);
    // 0x80007888: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000788C: sb          $v1, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r3;
    // 0x80007890: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x80007894: bne         $v0, $v1, L_80007940
    if (ctx->r2 != ctx->r3) {
        // 0x80007898: nop
    
            goto L_80007940;
    }
    // 0x80007898: nop

    // 0x8000789C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800078A0: lw          $v1, 0x3F38($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3F38);
    // 0x800078A4: bne         $v1, $zero, L_800078D4
    if (ctx->r3 != 0) {
        // 0x800078A8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800078D4;
    }
    // 0x800078A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800078AC: jal         0x8006CEB0
    // 0x800078B0: nop

    func_8006CEB0(rdram, ctx);
        goto after_12;
    // 0x800078B0: nop

    after_12:
    // 0x800078B4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800078B8: bltzl       $v1, L_800078C0
    if (SIGNED(ctx->r3) < 0) {
        // 0x800078BC: addiu       $v0, $v1, 0x1F
        ctx->r2 = ADD32(ctx->r3, 0X1F);
            goto L_800078C0;
    }
    goto skip_0;
    // 0x800078BC: addiu       $v0, $v1, 0x1F
    ctx->r2 = ADD32(ctx->r3, 0X1F);
    skip_0:
L_800078C0:
    // 0x800078C0: sra         $v0, $v0, 5
    ctx->r2 = S32(SIGNED(ctx->r2) >> 5);
    // 0x800078C4: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800078C8: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x800078CC: j           L_80007908
    // 0x800078D0: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
        goto L_80007908;
    // 0x800078D0: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
L_800078D4:
    // 0x800078D4: bne         $v1, $v0, L_80007904
    if (ctx->r3 != ctx->r2) {
        // 0x800078D8: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80007904;
    }
    // 0x800078D8: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800078DC: jal         0x8006CEB0
    // 0x800078E0: nop

    func_8006CEB0(rdram, ctx);
        goto after_13;
    // 0x800078E0: nop

    after_13:
    // 0x800078E4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800078E8: bltzl       $v1, L_800078F0
    if (SIGNED(ctx->r3) < 0) {
        // 0x800078EC: addiu       $v0, $v1, 0x1F
        ctx->r2 = ADD32(ctx->r3, 0X1F);
            goto L_800078F0;
    }
    goto skip_1;
    // 0x800078EC: addiu       $v0, $v1, 0x1F
    ctx->r2 = ADD32(ctx->r3, 0X1F);
    skip_1:
L_800078F0:
    // 0x800078F0: sra         $v0, $v0, 5
    ctx->r2 = S32(SIGNED(ctx->r2) >> 5);
    // 0x800078F4: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800078F8: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x800078FC: j           L_80007908
    // 0x80007900: slti        $v0, $v0, 0x10
    ctx->r2 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
        goto L_80007908;
    // 0x80007900: slti        $v0, $v0, 0x10
    ctx->r2 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
L_80007904:
    // 0x80007904: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
L_80007908:
    // 0x80007908: beq         $v0, $zero, L_80007970
    if (ctx->r2 == 0) {
        // 0x8000790C: nop
    
            goto L_80007970;
    }
    // 0x8000790C: nop

    // 0x80007910: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80007914: addiu       $v1, $v1, 0x7BB0
    ctx->r3 = ADD32(ctx->r3, 0X7BB0);
    // 0x80007918: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000791C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80007920: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80007924: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80007928: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8000792C: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80007930: bne         $v0, $zero, L_80007970
    if (ctx->r2 != 0) {
        // 0x80007934: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80007970;
    }
    // 0x80007934: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80007938: j           L_80007970
    // 0x8000793C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
        goto L_80007970;
    // 0x8000793C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_80007940:
    // 0x80007940: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80007944: lbu         $v0, 0x7BB0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7BB0);
    // 0x80007948: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000794C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007950: sb          $v0, 0x7BB0($at)
    MEM_B(0X7BB0, ctx->r1) = ctx->r2;
    // 0x80007954: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80007958: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8000795C: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80007960: bne         $v0, $zero, L_80007970
    if (ctx->r2 != 0) {
        // 0x80007964: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80007970;
    }
    // 0x80007964: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80007968: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000796C: sb          $v0, 0x7BB0($at)
    MEM_B(0X7BB0, ctx->r1) = ctx->r2;
L_80007970:
    // 0x80007970: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80007974: addiu       $v1, $v1, 0x7B84
    ctx->r3 = ADD32(ctx->r3, 0X7B84);
    // 0x80007978: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000797C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80007980: lbu         $a0, 0x7B85($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B85);
    // 0x80007984: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80007988: ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // 0x8000798C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80007990: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80007994: bne         $a0, $v0, L_800079B0
    if (ctx->r4 != ctx->r2) {
        // 0x80007998: nop
    
            goto L_800079B0;
    }
    // 0x80007998: nop

    // 0x8000799C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800079A0: lw          $v0, 0x3F38($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3F38);
    // 0x800079A4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800079A8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800079AC: sw          $v0, 0x3F38($at)
    MEM_W(0X3F38, ctx->r1) = ctx->r2;
L_800079B0:
    // 0x800079B0: jal         0x8000C494
    // 0x800079B4: nop

    func_8000C494(rdram, ctx);
        goto after_14;
    // 0x800079B4: nop

    after_14:
L_800079B8:
    // 0x800079B8: jal         0x80006998
    // 0x800079BC: nop

    func_80006998(rdram, ctx);
        goto after_15;
    // 0x800079BC: nop

    after_15:
L_800079C0:
    // 0x800079C0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x800079C4: jal         0x80017D38
    // 0x800079C8: addiu       $a0, $a0, -0x7660
    ctx->r4 = ADD32(ctx->r4, -0X7660);
    func_80017D38(rdram, ctx);
        goto after_16;
    // 0x800079C8: addiu       $a0, $a0, -0x7660
    ctx->r4 = ADD32(ctx->r4, -0X7660);
    after_16:
    // 0x800079CC: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x800079D0: addiu       $s0, $s0, 0x6AA0
    ctx->r16 = ADD32(ctx->r16, 0X6AA0);
    // 0x800079D4: jal         0x80017D38
    // 0x800079D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80017D38(rdram, ctx);
        goto after_17;
    // 0x800079D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_17:
    // 0x800079DC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800079E0: lbu         $v1, 0x7B8C($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B8C);
    // 0x800079E4: lui         $v0, 0xCCCC
    ctx->r2 = S32(0XCCCC << 16);
    // 0x800079E8: ori         $v0, $v0, 0xCCCD
    ctx->r2 = ctx->r2 | 0XCCCD;
    // 0x800079EC: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800079F0: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x800079F4: mfhi        $t0
    ctx->r8 = hi;
    // 0x800079F8: srl         $a1, $t0, 3
    ctx->r5 = S32(U32(ctx->r8) >> 3);
    // 0x800079FC: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80007A00: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80007A04: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80007A08: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80007A0C: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80007A10: sll         $v1, $v1, 9
    ctx->r3 = S32(ctx->r3 << 9);
    // 0x80007A14: jal         0x80017D38
    // 0x80007A18: sh          $v1, 0x70($s0)
    MEM_H(0X70, ctx->r16) = ctx->r3;
    func_80017D38(rdram, ctx);
        goto after_18;
    // 0x80007A18: sh          $v1, 0x70($s0)
    MEM_H(0X70, ctx->r16) = ctx->r3;
    after_18:
    // 0x80007A1C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80007A20: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x80007A24: beq         $v0, $zero, L_80007AE4
    if (ctx->r2 == 0) {
        // 0x80007A28: nop
    
            goto L_80007AE4;
    }
    // 0x80007A28: nop

    // 0x80007A2C: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80007A30: addiu       $s0, $s0, 0x2617
    ctx->r16 = ADD32(ctx->r16, 0X2617);
    // 0x80007A34: lbu         $a2, 0x0($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X0);
    // 0x80007A38: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80007A3C: addiu       $a1, $a1, -0x35B8
    ctx->r5 = ADD32(ctx->r5, -0X35B8);
    // 0x80007A40: jal         0x80066CA0
    // 0x80007A44: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_19;
    // 0x80007A44: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_19:
    // 0x80007A48: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80007A4C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x80007A50: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80007A54: jal         0x8004EC44
    // 0x80007A58: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_8004EC44(rdram, ctx);
        goto after_20;
    // 0x80007A58: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_20:
    // 0x80007A5C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80007A60: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80007A64: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80007A68: addiu       $a0, $a0, -0x35B0
    ctx->r4 = ADD32(ctx->r4, -0X35B0);
    // 0x80007A6C: beq         $v0, $zero, L_80007A7C
    if (ctx->r2 == 0) {
        // 0x80007A70: addiu       $a1, $zero, 0x36
        ctx->r5 = ADD32(0, 0X36);
            goto L_80007A7C;
    }
    // 0x80007A70: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x80007A74: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80007A78: addiu       $a0, $a0, -0x35B4
    ctx->r4 = ADD32(ctx->r4, -0X35B4);
L_80007A7C:
    // 0x80007A7C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80007A80: jal         0x8004EC44
    // 0x80007A84: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_21;
    // 0x80007A84: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_21:
    // 0x80007A88: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80007A8C: addiu       $s0, $s0, 0x7A67
    ctx->r16 = ADD32(ctx->r16, 0X7A67);
    // 0x80007A90: lbu         $a2, 0x0($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X0);
    // 0x80007A94: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80007A98: addiu       $a1, $a1, -0x35B8
    ctx->r5 = ADD32(ctx->r5, -0X35B8);
    // 0x80007A9C: jal         0x80066CA0
    // 0x80007AA0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_80066CA0(rdram, ctx);
        goto after_22;
    // 0x80007AA0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_22:
    // 0x80007AA4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80007AA8: addiu       $a1, $zero, 0xCA
    ctx->r5 = ADD32(0, 0XCA);
    // 0x80007AAC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80007AB0: jal         0x8004EC44
    // 0x80007AB4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_8004EC44(rdram, ctx);
        goto after_23;
    // 0x80007AB4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_23:
    // 0x80007AB8: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80007ABC: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80007AC0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80007AC4: addiu       $a0, $a0, -0x35B0
    ctx->r4 = ADD32(ctx->r4, -0X35B0);
    // 0x80007AC8: beq         $v0, $zero, L_80007AD8
    if (ctx->r2 == 0) {
        // 0x80007ACC: addiu       $a1, $zero, 0xEA
        ctx->r5 = ADD32(0, 0XEA);
            goto L_80007AD8;
    }
    // 0x80007ACC: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    // 0x80007AD0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80007AD4: addiu       $a0, $a0, -0x35B4
    ctx->r4 = ADD32(ctx->r4, -0X35B4);
L_80007AD8:
    // 0x80007AD8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80007ADC: jal         0x8004EC44
    // 0x80007AE0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004EC44(rdram, ctx);
        goto after_24;
    // 0x80007AE0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_24:
L_80007AE4:
    // 0x80007AE4: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80007AE8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80007AEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80007AF0: jr          $ra
    // 0x80007AF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80007AF4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80007AF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007AF8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80007AFC: lui         $a0, 0x12
    ctx->r4 = S32(0X12 << 16);
    // 0x80007B00: addiu       $a0, $a0, -0x2E20
    ctx->r4 = ADD32(ctx->r4, -0X2E20);
    // 0x80007B04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80007B08: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80007B0C: addiu       $s0, $s0, -0x75C0
    ctx->r16 = ADD32(ctx->r16, -0X75C0);
    // 0x80007B10: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80007B14: addiu       $a2, $zero, 0x2480
    ctx->r6 = ADD32(0, 0X2480);
    // 0x80007B18: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80007B1C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80007B20: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80007B24: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80007B28: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80007B2C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80007B30: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80007B34: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80007B38: jal         0x80006D98
    // 0x80007B3C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    func_80006D98(rdram, ctx);
        goto after_0;
    // 0x80007B3C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_0:
    // 0x80007B40: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x80007B44: addiu       $s1, $s1, 0x2120
    ctx->r17 = ADD32(ctx->r17, 0X2120);
    // 0x80007B48: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80007B4C: addiu       $fp, $zero, 0x5
    ctx->r30 = ADD32(0, 0X5);
    // 0x80007B50: addiu       $s7, $zero, 0x400
    ctx->r23 = ADD32(0, 0X400);
    // 0x80007B54: addiu       $s6, $zero, 0x7
    ctx->r22 = ADD32(0, 0X7);
    // 0x80007B58: addu        $s4, $s0, $zero
    ctx->r20 = ADD32(ctx->r16, 0);
    // 0x80007B5C: addiu       $s5, $s4, 0x480
    ctx->r21 = ADD32(ctx->r20, 0X480);
    // 0x80007B60: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x80007B64: addiu       $s3, $s3, -0xEAC
    ctx->r19 = ADD32(ctx->r19, -0XEAC);
    // 0x80007B68: addiu       $s0, $s1, 0x78
    ctx->r16 = ADD32(ctx->r17, 0X78);
L_80007B6C:
    // 0x80007B6C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80007B70: sb          $zero, -0x18($s0)
    MEM_B(-0X18, ctx->r16) = 0;
    // 0x80007B74: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80007B78: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80007B7C: lb          $v0, -0xEA4($v0)
    ctx->r2 = MEM_B(ctx->r2, -0XEA4);
    // 0x80007B80: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80007B84: addiu       $a2, $s1, 0x18
    ctx->r6 = ADD32(ctx->r17, 0X18);
    // 0x80007B88: addiu       $a3, $s1, 0x30
    ctx->r7 = ADD32(ctx->r17, 0X30);
    // 0x80007B8C: sw          $fp, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r30;
    // 0x80007B90: sw          $s7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r23;
    // 0x80007B94: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80007B98: addiu       $v0, $s1, 0x48
    ctx->r2 = ADD32(ctx->r17, 0X48);
    // 0x80007B9C: jal         0x800178E0
    // 0x80007BA0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800178E0(rdram, ctx);
        goto after_1;
    // 0x80007BA0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x80007BA4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80007BA8: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80007BAC: lbu         $v0, -0xEB4($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0XEB4);
    // 0x80007BB0: addiu       $s1, $s1, 0x90
    ctx->r17 = ADD32(ctx->r17, 0X90);
    // 0x80007BB4: subu        $v1, $s6, $s2
    ctx->r3 = SUB32(ctx->r22, ctx->r18);
    // 0x80007BB8: addiu       $v0, $v0, 0x48
    ctx->r2 = ADD32(ctx->r2, 0X48);
    // 0x80007BBC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80007BC0: sh          $v0, -0x50($s0)
    MEM_H(-0X50, ctx->r16) = ctx->r2;
    // 0x80007BC4: lbu         $a0, 0x0($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0X0);
    // 0x80007BC8: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80007BCC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80007BD0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80007BD4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80007BD8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80007BDC: addu        $v1, $v0, $s4
    ctx->r3 = ADD32(ctx->r2, ctx->r20);
    // 0x80007BE0: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x80007BE4: sw          $v1, -0x44($s0)
    MEM_W(-0X44, ctx->r16) = ctx->r3;
    // 0x80007BE8: sw          $v0, -0x2C($s0)
    MEM_W(-0X2C, ctx->r16) = ctx->r2;
    // 0x80007BEC: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x80007BF0: sra         $a0, $a0, 22
    ctx->r4 = S32(SIGNED(ctx->r4) >> 22);
    // 0x80007BF4: addiu       $a0, $a0, 0x200
    ctx->r4 = ADD32(ctx->r4, 0X200);
    // 0x80007BF8: sh          $a0, -0x4E($s0)
    MEM_H(-0X4E, ctx->r16) = ctx->r4;
    // 0x80007BFC: lb          $v0, 0x0($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X0);
    // 0x80007C00: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80007C04: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80007C08: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80007C0C: slti        $v0, $s2, 0x8
    ctx->r2 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
    // 0x80007C10: bne         $v0, $zero, L_80007B6C
    if (ctx->r2 != 0) {
        // 0x80007C14: addiu       $s0, $s0, 0x90
        ctx->r16 = ADD32(ctx->r16, 0X90);
            goto L_80007B6C;
    }
    // 0x80007C14: addiu       $s0, $s0, 0x90
    ctx->r16 = ADD32(ctx->r16, 0X90);
    // 0x80007C18: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80007C1C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80007C20: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80007C24: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80007C28: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80007C2C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80007C30: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80007C34: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80007C38: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80007C3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80007C40: jr          $ra
    // 0x80007C44: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80007C44: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80007C48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007C48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80007C4C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80007C50: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80007C54: jal         0x80005074
    // 0x80007C58: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80005074(rdram, ctx);
        goto after_0;
    // 0x80007C58: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80007C5C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80007C60: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x80007C64: sltiu       $v0, $v1, 0x8
    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
    // 0x80007C68: beq         $v0, $zero, L_80007EC8
    if (ctx->r2 == 0) {
        // 0x80007C6C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80007EC8;
    }
    // 0x80007C6C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80007C70: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80007C74: addu        $at, $at, $v0
    gpr jr_addend_80007C7C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80007C78: lw          $v0, -0x3590($at)
    ctx->r2 = ADD32(ctx->r1, -0X3590);
    // 0x80007C7C: jr          $v0
    // 0x80007C80: nop

    switch (jr_addend_80007C7C >> 2) {
        case 0: goto L_80007C84; break;
        case 1: goto L_80007CC8; break;
        case 2: goto L_80007CD8; break;
        case 3: goto L_80007CFC; break;
        case 4: goto L_80007D24; break;
        case 5: goto L_80007E6C; break;
        case 6: goto L_80007E78; break;
        case 7: goto L_80007EB0; break;
        default: switch_error(__func__, 0x80007C7C, 0x800ACA70);
    }
    // 0x80007C80: nop

L_80007C84:
    // 0x80007C84: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80007C88: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x80007C8C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80007C90: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80007C94: jal         0x80007AF8
    // 0x80007C98: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    func_80007AF8(rdram, ctx);
        goto after_1;
    // 0x80007C98: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    after_1:
    // 0x80007C9C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007CA0: sh          $zero, 0x558C($at)
    MEM_H(0X558C, ctx->r1) = 0;
    // 0x80007CA4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007CA8: jal         0x80006708
    // 0x80007CAC: sb          $zero, 0x7B7E($at)
    MEM_B(0X7B7E, ctx->r1) = 0;
    func_80006708(rdram, ctx);
        goto after_2;
    // 0x80007CAC: sb          $zero, 0x7B7E($at)
    MEM_B(0X7B7E, ctx->r1) = 0;
    after_2:
    // 0x80007CB0: jal         0x800067C8
    // 0x80007CB4: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_800067C8(rdram, ctx);
        goto after_3;
    // 0x80007CB4: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_3:
    // 0x80007CB8: jal         0x8002D378
    // 0x80007CBC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_4;
    // 0x80007CBC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_4:
    // 0x80007CC0: jal         0x8002D0D4
    // 0x80007CC4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_5;
    // 0x80007CC4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_5:
L_80007CC8:
    // 0x80007CC8: jal         0x8002CFB8
    // 0x80007CCC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_6;
    // 0x80007CCC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80007CD0: j           L_80007D04
    // 0x80007CD4: nop

        goto L_80007D04;
    // 0x80007CD4: nop

L_80007CD8:
    // 0x80007CD8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80007CDC: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x80007CE0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80007CE4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007CE8: sw          $zero, 0x6AD4($at)
    MEM_W(0X6AD4, ctx->r1) = 0;
    // 0x80007CEC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007CF0: sh          $zero, 0x558E($at)
    MEM_H(0X558E, ctx->r1) = 0;
    // 0x80007CF4: j           L_80007D1C
    // 0x80007CF8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_80007D1C;
    // 0x80007CF8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80007CFC:
    // 0x80007CFC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80007D00: lh          $v0, 0x558E($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X558E);
L_80007D04:
    // 0x80007D04: beq         $v0, $zero, L_80007ECC
    if (ctx->r2 == 0) {
        // 0x80007D08: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80007ECC;
    }
    // 0x80007D08: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80007D0C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80007D10: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x80007D14: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80007D18: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80007D1C:
    // 0x80007D1C: j           L_80007EC8
    // 0x80007D20: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
        goto L_80007EC8;
    // 0x80007D20: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_80007D24:
    // 0x80007D24: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80007D28: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x80007D2C: lw          $v0, 0xD0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XD0);
    // 0x80007D30: lw          $v0, 0xB8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB8);
    // 0x80007D34: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80007D38: andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // 0x80007D3C: beq         $v0, $zero, L_80007D60
    if (ctx->r2 == 0) {
        // 0x80007D40: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_80007D60;
    }
    // 0x80007D40: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80007D44: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007D48: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x80007D4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007D50: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007D54: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x80007D58: j           L_80007ECC
    // 0x80007D5C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
        goto L_80007ECC;
    // 0x80007D5C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80007D60:
    // 0x80007D60: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80007D64: lh          $v0, 0x558C($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X558C);
    // 0x80007D68: beq         $v0, $zero, L_80007D8C
    if (ctx->r2 == 0) {
        // 0x80007D6C: addiu       $a0, $zero, 0x78
        ctx->r4 = ADD32(0, 0X78);
            goto L_80007D8C;
    }
    // 0x80007D6C: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x80007D70: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80007D74: addiu       $v0, $v0, 0x7B71
    ctx->r2 = ADD32(ctx->r2, 0X7B71);
    // 0x80007D78: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80007D7C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007D80: sh          $a0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r4;
    // 0x80007D84: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80007D88: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_80007D8C:
    // 0x80007D8C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80007D90: addiu       $v1, $v1, 0x6AD4
    ctx->r3 = ADD32(ctx->r3, 0X6AD4);
    // 0x80007D94: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80007D98: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80007D9C: ldc1        $f2, -0x3570($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X3570);
    // 0x80007DA0: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80007DA4: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x80007DA8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80007DAC: ldc1        $f4, -0x3568($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3568);
    // 0x80007DB0: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x80007DB4: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x80007DB8: c.le.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d <= ctx->f2.d;
    // 0x80007DBC: nop

    // 0x80007DC0: nop

    // 0x80007DC4: bc1f        L_80007DDC
    if (!c1cs) {
        // 0x80007DC8: swc1        $f0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
            goto L_80007DDC;
    }
    // 0x80007DC8: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80007DCC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80007DD0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80007DD4: nop

    // 0x80007DD8: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
L_80007DDC:
    // 0x80007DDC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80007DE0: lhu         $v0, 0x6AAC($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6AAC);
    // 0x80007DE4: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80007DE8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80007DEC: sra         $v0, $v0, 18
    ctx->r2 = S32(SIGNED(ctx->r2) >> 18);
    // 0x80007DF0: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80007DF4: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x80007DF8: nop

    // 0x80007DFC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80007E00: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80007E04: sll         $v0, $v0, 18
    ctx->r2 = S32(ctx->r2 << 18);
    // 0x80007E08: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80007E0C: slti        $v0, $v0, 0x3C1
    ctx->r2 = SIGNED(ctx->r2) < 0X3C1 ? 1 : 0;
    // 0x80007E10: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007E14: sh          $v1, 0x6AAC($at)
    MEM_H(0X6AAC, ctx->r1) = ctx->r3;
    // 0x80007E18: bne         $v0, $zero, L_80007E28
    if (ctx->r2 != 0) {
        // 0x80007E1C: addiu       $v0, $zero, 0x3C0
        ctx->r2 = ADD32(0, 0X3C0);
            goto L_80007E28;
    }
    // 0x80007E1C: addiu       $v0, $zero, 0x3C0
    ctx->r2 = ADD32(0, 0X3C0);
    // 0x80007E20: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007E24: sh          $v0, 0x6AAC($at)
    MEM_H(0X6AAC, ctx->r1) = ctx->r2;
L_80007E28:
    // 0x80007E28: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80007E2C: lhu         $v0, 0x6B1C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6B1C);
    // 0x80007E30: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80007E34: sra         $v0, $v0, 18
    ctx->r2 = S32(SIGNED(ctx->r2) >> 18);
    // 0x80007E38: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80007E3C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80007E40: sll         $v0, $v0, 18
    ctx->r2 = S32(ctx->r2 << 18);
    // 0x80007E44: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80007E48: slti        $v0, $v0, 0x3C1
    ctx->r2 = SIGNED(ctx->r2) < 0X3C1 ? 1 : 0;
    // 0x80007E4C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007E50: sh          $v1, 0x6B1C($at)
    MEM_H(0X6B1C, ctx->r1) = ctx->r3;
    // 0x80007E54: bne         $v0, $zero, L_80007ECC
    if (ctx->r2 != 0) {
        // 0x80007E58: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80007ECC;
    }
    // 0x80007E58: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80007E5C: addiu       $v0, $zero, 0x3C0
    ctx->r2 = ADD32(0, 0X3C0);
    // 0x80007E60: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007E64: j           L_80007EC8
    // 0x80007E68: sh          $v0, 0x6B1C($at)
    MEM_H(0X6B1C, ctx->r1) = ctx->r2;
        goto L_80007EC8;
    // 0x80007E68: sh          $v0, 0x6B1C($at)
    MEM_H(0X6B1C, ctx->r1) = ctx->r2;
L_80007E6C:
    // 0x80007E6C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80007E70: j           L_80007E90
    // 0x80007E74: lbu         $v0, 0x7B94($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B94);
        goto L_80007E90;
    // 0x80007E74: lbu         $v0, 0x7B94($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B94);
L_80007E78:
    // 0x80007E78: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80007E7C: addiu       $v1, $v1, 0x7B74
    ctx->r3 = ADD32(ctx->r3, 0X7B74);
    // 0x80007E80: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80007E84: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80007E88: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80007E8C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
L_80007E90:
    // 0x80007E90: bne         $v0, $zero, L_80007ECC
    if (ctx->r2 != 0) {
        // 0x80007E94: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80007ECC;
    }
    // 0x80007E94: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80007E98: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80007E9C: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x80007EA0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80007EA4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007EA8: j           L_80007EC8
    // 0x80007EAC: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
        goto L_80007EC8;
    // 0x80007EAC: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
L_80007EB0:
    // 0x80007EB0: jal         0x8002CFB8
    // 0x80007EB4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_7;
    // 0x80007EB4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_7:
    // 0x80007EB8: beq         $v0, $zero, L_80007ECC
    if (ctx->r2 == 0) {
        // 0x80007EBC: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80007ECC;
    }
    // 0x80007EBC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80007EC0: jal         0x80007F48
    // 0x80007EC4: nop

    func_80007F48(rdram, ctx);
        goto after_8;
    // 0x80007EC4: nop

    after_8:
L_80007EC8:
    // 0x80007EC8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80007ECC:
    // 0x80007ECC: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x80007ED0: addiu       $s1, $s1, 0x2120
    ctx->r17 = ADD32(ctx->r17, 0X2120);
L_80007ED4:
    // 0x80007ED4: jal         0x8000BD60
    // 0x80007ED8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8000BD60(rdram, ctx);
        goto after_9;
    // 0x80007ED8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_9:
    // 0x80007EDC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80007EE0: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x80007EE4: bne         $v0, $zero, L_80007ED4
    if (ctx->r2 != 0) {
        // 0x80007EE8: addiu       $s1, $s1, 0x90
        ctx->r17 = ADD32(ctx->r17, 0X90);
            goto L_80007ED4;
    }
    // 0x80007EE8: addiu       $s1, $s1, 0x90
    ctx->r17 = ADD32(ctx->r17, 0X90);
    // 0x80007EEC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x80007EF0: jal         0x80017D38
    // 0x80007EF4: addiu       $a0, $a0, -0x7660
    ctx->r4 = ADD32(ctx->r4, -0X7660);
    func_80017D38(rdram, ctx);
        goto after_10;
    // 0x80007EF4: addiu       $a0, $a0, -0x7660
    ctx->r4 = ADD32(ctx->r4, -0X7660);
    after_10:
    // 0x80007EF8: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80007EFC: addiu       $s0, $s0, 0x6AA0
    ctx->r16 = ADD32(ctx->r16, 0X6AA0);
    // 0x80007F00: jal         0x80017D38
    // 0x80007F04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80017D38(rdram, ctx);
        goto after_11;
    // 0x80007F04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_11:
    // 0x80007F08: jal         0x80017D38
    // 0x80007F0C: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    func_80017D38(rdram, ctx);
        goto after_12;
    // 0x80007F0C: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    after_12:
    // 0x80007F10: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80007F14: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x80007F18: addiu       $s1, $s1, 0x2120
    ctx->r17 = ADD32(ctx->r17, 0X2120);
L_80007F1C:
    // 0x80007F1C: jal         0x8001817C
    // 0x80007F20: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001817C(rdram, ctx);
        goto after_13;
    // 0x80007F20: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_13:
    // 0x80007F24: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80007F28: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x80007F2C: bne         $v0, $zero, L_80007F1C
    if (ctx->r2 != 0) {
        // 0x80007F30: addiu       $s1, $s1, 0x90
        ctx->r17 = ADD32(ctx->r17, 0X90);
            goto L_80007F1C;
    }
    // 0x80007F30: addiu       $s1, $s1, 0x90
    ctx->r17 = ADD32(ctx->r17, 0X90);
    // 0x80007F34: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80007F38: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80007F3C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80007F40: jr          $ra
    // 0x80007F44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80007F44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80007F48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007F48: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80007F4C: lbu         $v1, 0x7B98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B98);
    // 0x80007F50: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80007F54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80007F58: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007F5C: sb          $zero, 0x5580($at)
    MEM_B(0X5580, ctx->r1) = 0;
    // 0x80007F60: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007F64: sb          $v0, 0x5581($at)
    MEM_B(0X5581, ctx->r1) = ctx->r2;
    // 0x80007F68: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007F6C: sb          $zero, 0x5582($at)
    MEM_B(0X5582, ctx->r1) = 0;
    // 0x80007F70: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007F74: sb          $a0, 0x7B4D($at)
    MEM_B(0X7B4D, ctx->r1) = ctx->r4;
    // 0x80007F78: bne         $v1, $zero, L_80007FB4
    if (ctx->r3 != 0) {
        // 0x80007F7C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80007FB4;
    }
    // 0x80007F7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007F80: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80007F84: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x80007F88: lb          $v1, 0x5A($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X5A);
    // 0x80007F8C: bne         $v1, $zero, L_80007FA0
    if (ctx->r3 != 0) {
        // 0x80007F90: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80007FA0;
    }
    // 0x80007F90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007F94: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007F98: j           L_80007FE8
    // 0x80007F9C: sb          $zero, 0x5587($at)
    MEM_B(0X5587, ctx->r1) = 0;
        goto L_80007FE8;
    // 0x80007F9C: sb          $zero, 0x5587($at)
    MEM_B(0X5587, ctx->r1) = 0;
L_80007FA0:
    // 0x80007FA0: bne         $v1, $v0, L_80007FE8
    if (ctx->r3 != ctx->r2) {
        // 0x80007FA4: nop
    
            goto L_80007FE8;
    }
    // 0x80007FA4: nop

    // 0x80007FA8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007FAC: j           L_80007FE8
    // 0x80007FB0: sb          $a0, 0x5587($at)
    MEM_B(0X5587, ctx->r1) = ctx->r4;
        goto L_80007FE8;
    // 0x80007FB0: sb          $a0, 0x5587($at)
    MEM_B(0X5587, ctx->r1) = ctx->r4;
L_80007FB4:
    // 0x80007FB4: bne         $v1, $v0, L_80007FE8
    if (ctx->r3 != ctx->r2) {
        // 0x80007FB8: nop
    
            goto L_80007FE8;
    }
    // 0x80007FB8: nop

    // 0x80007FBC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80007FC0: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x80007FC4: lb          $v1, 0x5A($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X5A);
    // 0x80007FC8: bne         $v1, $zero, L_80007FD8
    if (ctx->r3 != 0) {
        // 0x80007FCC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80007FD8;
    }
    // 0x80007FCC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80007FD0: j           L_80007FE0
    // 0x80007FD4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80007FE0;
    // 0x80007FD4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80007FD8:
    // 0x80007FD8: bne         $v1, $v0, L_80007FE8
    if (ctx->r3 != ctx->r2) {
        // 0x80007FDC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80007FE8;
    }
    // 0x80007FDC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80007FE0:
    // 0x80007FE0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007FE4: sb          $v0, 0x5587($at)
    MEM_B(0X5587, ctx->r1) = ctx->r2;
L_80007FE8:
    // 0x80007FE8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007FEC: sb          $zero, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = 0;
    // 0x80007FF0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007FF4: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x80007FF8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80007FFC: sb          $zero, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = 0;
    // 0x80008000: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008004: sb          $zero, 0x7B98($at)
    MEM_B(0X7B98, ctx->r1) = 0;
    // 0x80008008: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000800C: sb          $zero, 0x7B89($at)
    MEM_B(0X7B89, ctx->r1) = 0;
    // 0x80008010: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008014: sw          $zero, 0x7BBC($at)
    MEM_W(0X7BBC, ctx->r1) = 0;
    // 0x80008018: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000801C: sb          $zero, 0x7A4A($at)
    MEM_B(0X7A4A, ctx->r1) = 0;
    // 0x80008020: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008024: sb          $zero, 0x25FA($at)
    MEM_B(0X25FA, ctx->r1) = 0;
    // 0x80008028: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000802C: jr          $ra
    // 0x80008030: sb          $zero, 0x2074($at)
    MEM_B(0X2074, ctx->r1) = 0;
    return;
    // 0x80008030: sb          $zero, 0x2074($at)
    MEM_B(0X2074, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80008034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008034: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80008038: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x8000803C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80008040: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80008044: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80008048: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x8000804C: beq         $v0, $zero, L_800081B4
    if (ctx->r2 == 0) {
        // 0x80008050: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800081B4;
    }
    // 0x80008050: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80008054: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80008058: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000805C: addu        $at, $at, $v0
    gpr jr_addend_80008064 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80008060: lw          $v0, -0x3560($at)
    ctx->r2 = ADD32(ctx->r1, -0X3560);
    // 0x80008064: jr          $v0
    // 0x80008068: nop

    switch (jr_addend_80008064 >> 2) {
        case 0: goto L_8000806C; break;
        case 1: goto L_800080C8; break;
        case 2: goto L_800080F0; break;
        case 3: goto L_80008158; break;
        case 4: goto L_80008164; break;
        case 5: goto L_8000819C; break;
        default: switch_error(__func__, 0x80008064, 0x800ACAA0);
    }
    // 0x80008068: nop

L_8000806C:
    // 0x8000806C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80008070: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x80008074: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80008078: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000807C: jal         0x80007AF8
    // 0x80008080: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    func_80007AF8(rdram, ctx);
        goto after_0;
    // 0x80008080: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    after_0:
    // 0x80008084: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008088: sh          $zero, 0x558C($at)
    MEM_H(0X558C, ctx->r1) = 0;
    // 0x8000808C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008090: jal         0x8001C1F0
    // 0x80008094: sb          $zero, 0x7B7E($at)
    MEM_B(0X7B7E, ctx->r1) = 0;
    func_8001C1F0(rdram, ctx);
        goto after_1;
    // 0x80008094: sb          $zero, 0x7B7E($at)
    MEM_B(0X7B7E, ctx->r1) = 0;
    after_1:
    // 0x80008098: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x8000809C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800080A0: jal         0x8001D670
    // 0x800080A4: addiu       $a0, $a0, -0x2338
    ctx->r4 = ADD32(ctx->r4, -0X2338);
    func_8001D670(rdram, ctx);
        goto after_2;
    // 0x800080A4: addiu       $a0, $a0, -0x2338
    ctx->r4 = ADD32(ctx->r4, -0X2338);
    after_2:
    // 0x800080A8: jal         0x80006708
    // 0x800080AC: nop

    func_80006708(rdram, ctx);
        goto after_3;
    // 0x800080AC: nop

    after_3:
    // 0x800080B0: jal         0x800067C8
    // 0x800080B4: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_800067C8(rdram, ctx);
        goto after_4;
    // 0x800080B4: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_4:
    // 0x800080B8: jal         0x8002D378
    // 0x800080BC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_5;
    // 0x800080BC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_5:
    // 0x800080C0: jal         0x8002D0D4
    // 0x800080C4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_6;
    // 0x800080C4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
L_800080C8:
    // 0x800080C8: jal         0x8002CFB8
    // 0x800080CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_7;
    // 0x800080CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x800080D0: beq         $v0, $zero, L_800081B8
    if (ctx->r2 == 0) {
        // 0x800080D4: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_800081B8;
    }
    // 0x800080D4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800080D8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800080DC: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x800080E0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800080E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800080E8: j           L_800081B8
    // 0x800080EC: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
        goto L_800081B8;
    // 0x800080EC: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_800080F0:
    // 0x800080F0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800080F4: lhu         $v0, -0x38A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X38A0);
    // 0x800080F8: bne         $v0, $zero, L_80008110
    if (ctx->r2 != 0) {
        // 0x800080FC: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_80008110;
    }
    // 0x800080FC: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80008100: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80008104: lhu         $v0, -0x389A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X389A);
    // 0x80008108: beq         $v0, $zero, L_80008128
    if (ctx->r2 == 0) {
        // 0x8000810C: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_80008128;
    }
    // 0x8000810C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_80008110:
    // 0x80008110: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008114: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x80008118: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000811C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008120: j           L_80008208
    // 0x80008124: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
        goto L_80008208;
    // 0x80008124: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
L_80008128:
    // 0x80008128: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000812C: lh          $v0, 0x558C($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X558C);
    // 0x80008130: beq         $v0, $zero, L_800081B4
    if (ctx->r2 == 0) {
        // 0x80008134: addiu       $a0, $zero, 0x78
        ctx->r4 = ADD32(0, 0X78);
            goto L_800081B4;
    }
    // 0x80008134: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x80008138: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000813C: addiu       $v0, $v0, 0x7B71
    ctx->r2 = ADD32(ctx->r2, 0X7B71);
    // 0x80008140: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80008144: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008148: sh          $a0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r4;
    // 0x8000814C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80008150: j           L_800081B4
    // 0x80008154: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
        goto L_800081B4;
    // 0x80008154: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_80008158:
    // 0x80008158: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000815C: j           L_8000817C
    // 0x80008160: lbu         $v0, 0x7B94($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B94);
        goto L_8000817C;
    // 0x80008160: lbu         $v0, 0x7B94($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B94);
L_80008164:
    // 0x80008164: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80008168: addiu       $v1, $v1, 0x7B74
    ctx->r3 = ADD32(ctx->r3, 0X7B74);
    // 0x8000816C: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80008170: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80008174: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80008178: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
L_8000817C:
    // 0x8000817C: bne         $v0, $zero, L_800081B8
    if (ctx->r2 != 0) {
        // 0x80008180: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_800081B8;
    }
    // 0x80008180: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80008184: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008188: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x8000818C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80008190: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008194: j           L_800081B4
    // 0x80008198: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
        goto L_800081B4;
    // 0x80008198: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
L_8000819C:
    // 0x8000819C: jal         0x8002CFB8
    // 0x800081A0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_8;
    // 0x800081A0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_8:
    // 0x800081A4: beq         $v0, $zero, L_800081B8
    if (ctx->r2 == 0) {
        // 0x800081A8: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_800081B8;
    }
    // 0x800081A8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800081AC: jal         0x80007F48
    // 0x800081B0: nop

    func_80007F48(rdram, ctx);
        goto after_9;
    // 0x800081B0: nop

    after_9:
L_800081B4:
    // 0x800081B4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_800081B8:
    // 0x800081B8: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x800081BC: addiu       $s1, $s1, 0x2120
    ctx->r17 = ADD32(ctx->r17, 0X2120);
L_800081C0:
    // 0x800081C0: jal         0x8000BD60
    // 0x800081C4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8000BD60(rdram, ctx);
        goto after_10;
    // 0x800081C4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_10:
    // 0x800081C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800081CC: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x800081D0: bne         $v0, $zero, L_800081C0
    if (ctx->r2 != 0) {
        // 0x800081D4: addiu       $s1, $s1, 0x90
        ctx->r17 = ADD32(ctx->r17, 0X90);
            goto L_800081C0;
    }
    // 0x800081D4: addiu       $s1, $s1, 0x90
    ctx->r17 = ADD32(ctx->r17, 0X90);
    // 0x800081D8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x800081DC: addiu       $a0, $a0, -0x7660
    ctx->r4 = ADD32(ctx->r4, -0X7660);
    // 0x800081E0: jal         0x80017D38
    // 0x800081E4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    func_80017D38(rdram, ctx);
        goto after_11;
    // 0x800081E4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    after_11:
    // 0x800081E8: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x800081EC: addiu       $s1, $s1, 0x2120
    ctx->r17 = ADD32(ctx->r17, 0X2120);
L_800081F0:
    // 0x800081F0: jal         0x8001817C
    // 0x800081F4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001817C(rdram, ctx);
        goto after_12;
    // 0x800081F4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_12:
    // 0x800081F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800081FC: slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // 0x80008200: bne         $v0, $zero, L_800081F0
    if (ctx->r2 != 0) {
        // 0x80008204: addiu       $s1, $s1, 0x90
        ctx->r17 = ADD32(ctx->r17, 0X90);
            goto L_800081F0;
    }
    // 0x80008204: addiu       $s1, $s1, 0x90
    ctx->r17 = ADD32(ctx->r17, 0X90);
L_80008208:
    // 0x80008208: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8000820C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80008210: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80008214: jr          $ra
    // 0x80008218: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80008218: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8000821C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000821C: jr          $ra
    // 0x80008220: nop

    return;
    // 0x80008220: nop

;}
RECOMP_FUNC void func_80008224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008224: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80008228: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000822C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80008230: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80008234: jal         0x80005074
    // 0x80008238: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    func_80005074(rdram, ctx);
        goto after_0;
    // 0x80008238: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    after_0:
    // 0x8000823C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008240: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x80008244: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80008248: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x8000824C: lw          $s2, 0xD0($v0)
    ctx->r18 = MEM_W(ctx->r2, 0XD0);
    // 0x80008250: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x80008254: beq         $v0, $zero, L_8000834C
    if (ctx->r2 == 0) {
        // 0x80008258: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8000834C;
    }
    // 0x80008258: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8000825C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80008260: addu        $at, $at, $v0
    gpr jr_addend_80008268 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80008264: lw          $v0, -0x34B8($at)
    ctx->r2 = ADD32(ctx->r1, -0X34B8);
    // 0x80008268: jr          $v0
    // 0x8000826C: nop

    switch (jr_addend_80008268 >> 2) {
        case 0: goto L_80008270; break;
        case 1: goto L_800082A8; break;
        case 2: goto L_800082B8; break;
        case 3: goto L_800082E8; break;
        case 4: goto L_8000832C; break;
        default: switch_error(__func__, 0x80008268, 0x800ACB48);
    }
    // 0x8000826C: nop

L_80008270:
    // 0x80008270: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80008274: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x80008278: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000827C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80008280: jal         0x8005433C
    // 0x80008284: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    func_8005433C(rdram, ctx);
        goto after_1;
    // 0x80008284: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    after_1:
    // 0x80008288: jal         0x8001C1F0
    // 0x8000828C: nop

    func_8001C1F0(rdram, ctx);
        goto after_2;
    // 0x8000828C: nop

    after_2:
    // 0x80008290: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80008294: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80008298: jal         0x8001D670
    // 0x8000829C: addiu       $a0, $a0, -0x2338
    ctx->r4 = ADD32(ctx->r4, -0X2338);
    func_8001D670(rdram, ctx);
        goto after_3;
    // 0x8000829C: addiu       $a0, $a0, -0x2338
    ctx->r4 = ADD32(ctx->r4, -0X2338);
    after_3:
    // 0x800082A0: jal         0x80011288
    // 0x800082A4: nop

    func_80011288(rdram, ctx);
        goto after_4;
    // 0x800082A4: nop

    after_4:
L_800082A8:
    // 0x800082A8: jal         0x8002D378
    // 0x800082AC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_5;
    // 0x800082AC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_5:
    // 0x800082B0: jal         0x8002D0D4
    // 0x800082B4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_6;
    // 0x800082B4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
L_800082B8:
    // 0x800082B8: jal         0x8002CFB8
    // 0x800082BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_7;
    // 0x800082BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x800082C0: beq         $v0, $zero, L_8000834C
    if (ctx->r2 == 0) {
        // 0x800082C4: addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
            goto L_8000834C;
    }
    // 0x800082C4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x800082C8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800082CC: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x800082D0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800082D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800082D8: jal         0x800064C0
    // 0x800082DC: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    func_800064C0(rdram, ctx);
        goto after_8;
    // 0x800082DC: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    after_8:
    // 0x800082E0: j           L_8000834C
    // 0x800082E4: nop

        goto L_8000834C;
    // 0x800082E4: nop

L_800082E8:
    // 0x800082E8: lw          $v0, 0xB4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XB4);
    // 0x800082EC: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800082F0: andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // 0x800082F4: bne         $v0, $zero, L_80008314
    if (ctx->r2 != 0) {
        // 0x800082F8: nop
    
            goto L_80008314;
    }
    // 0x800082F8: nop

    // 0x800082FC: lw          $v0, 0xD0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XD0);
    // 0x80008300: lw          $v0, 0xB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB4);
    // 0x80008304: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80008308: andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // 0x8000830C: beq         $v0, $zero, L_8000834C
    if (ctx->r2 == 0) {
        // 0x80008310: nop
    
            goto L_8000834C;
    }
    // 0x80008310: nop

L_80008314:
    // 0x80008314: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80008318: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x8000831C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80008320: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80008324: j           L_8000834C
    // 0x80008328: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
        goto L_8000834C;
    // 0x80008328: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8000832C:
    // 0x8000832C: jal         0x8002CFB8
    // 0x80008330: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_9;
    // 0x80008330: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_9:
    // 0x80008334: beq         $v0, $zero, L_8000834C
    if (ctx->r2 == 0) {
        // 0x80008338: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_8000834C;
    }
    // 0x80008338: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x8000833C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008340: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x80008344: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008348: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
L_8000834C:
    // 0x8000834C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x80008350: jal         0x80017D38
    // 0x80008354: addiu       $a0, $a0, -0x7660
    ctx->r4 = ADD32(ctx->r4, -0X7660);
    func_80017D38(rdram, ctx);
        goto after_10;
    // 0x80008354: addiu       $a0, $a0, -0x7660
    ctx->r4 = ADD32(ctx->r4, -0X7660);
    after_10:
    // 0x80008358: lb          $v0, 0x5A($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X5A);
    // 0x8000835C: bne         $v0, $zero, L_80008594
    if (ctx->r2 != 0) {
        // 0x80008360: addiu       $a1, $zero, 0x28
        ctx->r5 = ADD32(0, 0X28);
            goto L_80008594;
    }
    // 0x80008360: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80008364: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80008368: addiu       $a0, $a0, -0x3548
    ctx->r4 = ADD32(ctx->r4, -0X3548);
    // 0x8000836C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80008370: jal         0x8004F1A4
    // 0x80008374: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8004F1A4(rdram, ctx);
        goto after_11;
    // 0x80008374: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_11:
    // 0x80008378: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000837C: addiu       $a0, $a0, -0x3540
    ctx->r4 = ADD32(ctx->r4, -0X3540);
    // 0x80008380: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    // 0x80008384: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x80008388: jal         0x8004DAB8
    // 0x8000838C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8004DAB8(rdram, ctx);
        goto after_12;
    // 0x8000838C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_12:
    // 0x80008390: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80008394: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x80008398: addiu       $s1, $s1, -0x35B8
    ctx->r17 = ADD32(ctx->r17, -0X35B8);
    // 0x8000839C: lbu         $v0, 0x74($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X74);
    // 0x800083A0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800083A4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x800083A8: jal         0x80066CA0
    // 0x800083AC: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    func_80066CA0(rdram, ctx);
        goto after_13;
    // 0x800083AC: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    after_13:
    // 0x800083B0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800083B4: addiu       $a1, $zero, 0x108
    ctx->r5 = ADD32(0, 0X108);
    // 0x800083B8: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x800083BC: jal         0x8004DAB8
    // 0x800083C0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_14;
    // 0x800083C0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_14:
    // 0x800083C4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800083C8: addiu       $a0, $a0, -0x3534
    ctx->r4 = ADD32(ctx->r4, -0X3534);
    // 0x800083CC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x800083D0: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x800083D4: jal         0x8004F1A4
    // 0x800083D8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_15;
    // 0x800083D8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_15:
    // 0x800083DC: lw          $a2, 0x104($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X104);
    // 0x800083E0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800083E4: addiu       $a1, $a1, -0x352C
    ctx->r5 = ADD32(ctx->r5, -0X352C);
    // 0x800083E8: jal         0x80066CA0
    // 0x800083EC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80066CA0(rdram, ctx);
        goto after_16;
    // 0x800083EC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_16:
    // 0x800083F0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800083F4: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    // 0x800083F8: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x800083FC: jal         0x8004F1A4
    // 0x80008400: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_8004F1A4(rdram, ctx);
        goto after_17;
    // 0x80008400: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_17:
    // 0x80008404: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80008408: addiu       $a0, $a0, -0x3528
    ctx->r4 = ADD32(ctx->r4, -0X3528);
    // 0x8000840C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80008410: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    // 0x80008414: jal         0x8004F1A4
    // 0x80008418: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_18;
    // 0x80008418: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_18:
    // 0x8000841C: lw          $a2, 0xA0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XA0);
    // 0x80008420: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80008424: addiu       $a1, $a1, -0x3520
    ctx->r5 = ADD32(ctx->r5, -0X3520);
    // 0x80008428: jal         0x80066CA0
    // 0x8000842C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80066CA0(rdram, ctx);
        goto after_19;
    // 0x8000842C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_19:
    // 0x80008430: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80008434: addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // 0x80008438: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    // 0x8000843C: jal         0x8004F1A4
    // 0x80008440: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_8004F1A4(rdram, ctx);
        goto after_20;
    // 0x80008440: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_20:
    // 0x80008444: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80008448: addiu       $a0, $a0, -0x351C
    ctx->r4 = ADD32(ctx->r4, -0X351C);
    // 0x8000844C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80008450: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // 0x80008454: jal         0x8004F1A4
    // 0x80008458: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_21;
    // 0x80008458: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_21:
    // 0x8000845C: lw          $a2, 0xA4($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XA4);
    // 0x80008460: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80008464: addiu       $a1, $a1, -0x3514
    ctx->r5 = ADD32(ctx->r5, -0X3514);
    // 0x80008468: jal         0x80066CA0
    // 0x8000846C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80066CA0(rdram, ctx);
        goto after_22;
    // 0x8000846C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_22:
    // 0x80008470: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80008474: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80008478: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // 0x8000847C: jal         0x8004F1A4
    // 0x80008480: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_8004F1A4(rdram, ctx);
        goto after_23;
    // 0x80008480: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_23:
    // 0x80008484: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80008488: addiu       $a0, $a0, -0x3510
    ctx->r4 = ADD32(ctx->r4, -0X3510);
    // 0x8000848C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80008490: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // 0x80008494: jal         0x8004F1A4
    // 0x80008498: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_24;
    // 0x80008498: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_24:
    // 0x8000849C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800084A0: lhu         $a2, 0x9C($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X9C);
    // 0x800084A4: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x800084A8: addiu       $s0, $s0, -0x3508
    ctx->r16 = ADD32(ctx->r16, -0X3508);
    // 0x800084AC: jal         0x80066CA0
    // 0x800084B0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80066CA0(rdram, ctx);
        goto after_25;
    // 0x800084B0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_25:
    // 0x800084B4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800084B8: addiu       $a1, $zero, 0xD8
    ctx->r5 = ADD32(0, 0XD8);
    // 0x800084BC: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // 0x800084C0: jal         0x8004F1A4
    // 0x800084C4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_8004F1A4(rdram, ctx);
        goto after_26;
    // 0x800084C4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_26:
    // 0x800084C8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800084CC: addiu       $a0, $a0, -0x3504
    ctx->r4 = ADD32(ctx->r4, -0X3504);
    // 0x800084D0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x800084D4: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x800084D8: jal         0x8004F1A4
    // 0x800084DC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_27;
    // 0x800084DC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_27:
    // 0x800084E0: lhu         $a2, 0x9E($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X9E);
    // 0x800084E4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800084E8: jal         0x80066CA0
    // 0x800084EC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80066CA0(rdram, ctx);
        goto after_28;
    // 0x800084EC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_28:
    // 0x800084F0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800084F4: addiu       $a1, $zero, 0xD8
    ctx->r5 = ADD32(0, 0XD8);
    // 0x800084F8: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x800084FC: jal         0x8004F1A4
    // 0x80008500: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_8004F1A4(rdram, ctx);
        goto after_29;
    // 0x80008500: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_29:
    // 0x80008504: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80008508: addiu       $a0, $a0, -0x34FC
    ctx->r4 = ADD32(ctx->r4, -0X34FC);
    // 0x8000850C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80008510: addiu       $a2, $zero, 0xB8
    ctx->r6 = ADD32(0, 0XB8);
    // 0x80008514: jal         0x8004F1A4
    // 0x80008518: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_30;
    // 0x80008518: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_30:
    // 0x8000851C: lw          $a2, 0xA8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XA8);
    // 0x80008520: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80008524: jal         0x80066CA0
    // 0x80008528: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80066CA0(rdram, ctx);
        goto after_31;
    // 0x80008528: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_31:
    // 0x8000852C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80008530: addiu       $a1, $zero, 0xF8
    ctx->r5 = ADD32(0, 0XF8);
    // 0x80008534: addiu       $a2, $zero, 0xB8
    ctx->r6 = ADD32(0, 0XB8);
    // 0x80008538: jal         0x8004F1A4
    // 0x8000853C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_8004F1A4(rdram, ctx);
        goto after_32;
    // 0x8000853C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_32:
    // 0x80008540: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80008544: addiu       $a0, $a0, -0x34F0
    ctx->r4 = ADD32(ctx->r4, -0X34F0);
    // 0x80008548: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8000854C: addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    // 0x80008550: jal         0x8004F1A4
    // 0x80008554: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_33;
    // 0x80008554: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_33:
    // 0x80008558: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x8000855C: lbu         $a2, 0x7B68($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X7B68);
    // 0x80008560: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80008564: lbu         $a3, 0x7B69($a3)
    ctx->r7 = MEM_BU(ctx->r7, 0X7B69);
    // 0x80008568: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000856C: lbu         $v0, 0x7B6A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B6A);
    // 0x80008570: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80008574: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80008578: addiu       $a1, $a1, -0x34E8
    ctx->r5 = ADD32(ctx->r5, -0X34E8);
    // 0x8000857C: jal         0x80066CA0
    // 0x80008580: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80066CA0(rdram, ctx);
        goto after_34;
    // 0x80008580: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_34:
    // 0x80008584: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80008588: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    // 0x8000858C: j           L_80008868
    // 0x80008590: addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
        goto L_80008868;
    // 0x80008590: addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
L_80008594:
    // 0x80008594: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80008598: addiu       $a0, $a0, -0x3548
    ctx->r4 = ADD32(ctx->r4, -0X3548);
    // 0x8000859C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800085A0: jal         0x8004F1A4
    // 0x800085A4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8004F1A4(rdram, ctx);
        goto after_35;
    // 0x800085A4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_35:
    // 0x800085A8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800085AC: addiu       $a0, $a0, -0x3540
    ctx->r4 = ADD32(ctx->r4, -0X3540);
    // 0x800085B0: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    // 0x800085B4: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x800085B8: jal         0x8004DAB8
    // 0x800085BC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8004DAB8(rdram, ctx);
        goto after_36;
    // 0x800085BC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_36:
    // 0x800085C0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800085C4: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x800085C8: addiu       $s1, $s1, -0x35B8
    ctx->r17 = ADD32(ctx->r17, -0X35B8);
    // 0x800085CC: lbu         $a2, 0x74($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X74);
    // 0x800085D0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800085D4: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x800085D8: jal         0x80066CA0
    // 0x800085DC: subu        $a2, $s0, $a2
    ctx->r6 = SUB32(ctx->r16, ctx->r6);
    func_80066CA0(rdram, ctx);
        goto after_37;
    // 0x800085DC: subu        $a2, $s0, $a2
    ctx->r6 = SUB32(ctx->r16, ctx->r6);
    after_37:
    // 0x800085E0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800085E4: addiu       $a1, $zero, 0x108
    ctx->r5 = ADD32(0, 0X108);
    // 0x800085E8: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x800085EC: jal         0x8004DAB8
    // 0x800085F0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_38;
    // 0x800085F0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_38:
    // 0x800085F4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800085F8: addiu       $a0, $a0, -0x3534
    ctx->r4 = ADD32(ctx->r4, -0X3534);
    // 0x800085FC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80008600: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    // 0x80008604: jal         0x8004F1A4
    // 0x80008608: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_39;
    // 0x80008608: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_39:
    // 0x8000860C: lw          $a2, 0x104($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X104);
    // 0x80008610: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80008614: addiu       $a1, $a1, -0x352C
    ctx->r5 = ADD32(ctx->r5, -0X352C);
    // 0x80008618: jal         0x80066CA0
    // 0x8000861C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80066CA0(rdram, ctx);
        goto after_40;
    // 0x8000861C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_40:
    // 0x80008620: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80008624: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    // 0x80008628: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    // 0x8000862C: jal         0x8004F1A4
    // 0x80008630: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_8004F1A4(rdram, ctx);
        goto after_41;
    // 0x80008630: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_41:
    // 0x80008634: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80008638: addiu       $a0, $a0, -0x34D8
    ctx->r4 = ADD32(ctx->r4, -0X34D8);
    // 0x8000863C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80008640: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    // 0x80008644: jal         0x8004F1A4
    // 0x80008648: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_42;
    // 0x80008648: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_42:
    // 0x8000864C: lw          $v1, 0xA4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XA4);
    // 0x80008650: lui         $v0, 0xCCCC
    ctx->r2 = S32(0XCCCC << 16);
    // 0x80008654: ori         $v0, $v0, 0xCCCD
    ctx->r2 = ctx->r2 | 0XCCCD;
    // 0x80008658: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000865C: lbu         $v0, 0x74($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X74);
    // 0x80008660: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x80008664: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x80008668: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8000866C: mfhi        $t0
    ctx->r8 = hi;
    // 0x80008670: srl         $v1, $t0, 3
    ctx->r3 = S32(U32(ctx->r8) >> 3);
    // 0x80008674: addu        $a2, $v1, $v0
    ctx->r6 = ADD32(ctx->r3, ctx->r2);
    // 0x80008678: slti        $v0, $a2, 0x64
    ctx->r2 = SIGNED(ctx->r6) < 0X64 ? 1 : 0;
    // 0x8000867C: beql        $v0, $zero, L_80008684
    if (ctx->r2 == 0) {
        // 0x80008680: addiu       $a2, $zero, 0x63
        ctx->r6 = ADD32(0, 0X63);
            goto L_80008684;
    }
    goto skip_0;
    // 0x80008680: addiu       $a2, $zero, 0x63
    ctx->r6 = ADD32(0, 0X63);
    skip_0:
L_80008684:
    // 0x80008684: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80008688: jal         0x80066CA0
    // 0x8000868C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80066CA0(rdram, ctx);
        goto after_43;
    // 0x8000868C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_43:
    // 0x80008690: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80008694: addiu       $a1, $zero, 0xF8
    ctx->r5 = ADD32(0, 0XF8);
    // 0x80008698: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    // 0x8000869C: jal         0x8004F1A4
    // 0x800086A0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_8004F1A4(rdram, ctx);
        goto after_44;
    // 0x800086A0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_44:
    // 0x800086A4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800086A8: addiu       $a0, $a0, -0x351C
    ctx->r4 = ADD32(ctx->r4, -0X351C);
    // 0x800086AC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x800086B0: addiu       $a2, $zero, 0x5C
    ctx->r6 = ADD32(0, 0X5C);
    // 0x800086B4: jal         0x8004F1A4
    // 0x800086B8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_45;
    // 0x800086B8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_45:
    // 0x800086BC: lw          $a2, 0xA4($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XA4);
    // 0x800086C0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800086C4: addiu       $a1, $a1, -0x3514
    ctx->r5 = ADD32(ctx->r5, -0X3514);
    // 0x800086C8: jal         0x80066CA0
    // 0x800086CC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80066CA0(rdram, ctx);
        goto after_46;
    // 0x800086CC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_46:
    // 0x800086D0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800086D4: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x800086D8: addiu       $a2, $zero, 0x5C
    ctx->r6 = ADD32(0, 0X5C);
    // 0x800086DC: jal         0x8004F1A4
    // 0x800086E0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_8004F1A4(rdram, ctx);
        goto after_47;
    // 0x800086E0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_47:
    // 0x800086E4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800086E8: addiu       $a0, $a0, -0x34D0
    ctx->r4 = ADD32(ctx->r4, -0X34D0);
    // 0x800086EC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x800086F0: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // 0x800086F4: jal         0x8004F1A4
    // 0x800086F8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_48;
    // 0x800086F8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_48:
    // 0x800086FC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80008700: lhu         $a2, 0x96($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X96);
    // 0x80008704: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x80008708: addiu       $s0, $s0, -0x3508
    ctx->r16 = ADD32(ctx->r16, -0X3508);
    // 0x8000870C: jal         0x80066CA0
    // 0x80008710: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80066CA0(rdram, ctx);
        goto after_49;
    // 0x80008710: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_49:
    // 0x80008714: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80008718: addiu       $a1, $zero, 0xD8
    ctx->r5 = ADD32(0, 0XD8);
    // 0x8000871C: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // 0x80008720: jal         0x8004F1A4
    // 0x80008724: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_8004F1A4(rdram, ctx);
        goto after_50;
    // 0x80008724: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_50:
    // 0x80008728: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000872C: addiu       $a0, $a0, -0x34C8
    ctx->r4 = ADD32(ctx->r4, -0X34C8);
    // 0x80008730: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80008734: addiu       $a2, $zero, 0x84
    ctx->r6 = ADD32(0, 0X84);
    // 0x80008738: jal         0x8004F1A4
    // 0x8000873C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_51;
    // 0x8000873C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_51:
    // 0x80008740: lhu         $a2, 0x98($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X98);
    // 0x80008744: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80008748: jal         0x80066CA0
    // 0x8000874C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80066CA0(rdram, ctx);
        goto after_52;
    // 0x8000874C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_52:
    // 0x80008750: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80008754: addiu       $a1, $zero, 0xD8
    ctx->r5 = ADD32(0, 0XD8);
    // 0x80008758: addiu       $a2, $zero, 0x84
    ctx->r6 = ADD32(0, 0X84);
    // 0x8000875C: jal         0x8004F1A4
    // 0x80008760: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_8004F1A4(rdram, ctx);
        goto after_53;
    // 0x80008760: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_53:
    // 0x80008764: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80008768: addiu       $a0, $a0, -0x34C0
    ctx->r4 = ADD32(ctx->r4, -0X34C0);
    // 0x8000876C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80008770: addiu       $a2, $zero, 0x98
    ctx->r6 = ADD32(0, 0X98);
    // 0x80008774: jal         0x8004F1A4
    // 0x80008778: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_54;
    // 0x80008778: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_54:
    // 0x8000877C: lhu         $a2, 0x9A($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X9A);
    // 0x80008780: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80008784: jal         0x80066CA0
    // 0x80008788: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80066CA0(rdram, ctx);
        goto after_55;
    // 0x80008788: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_55:
    // 0x8000878C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80008790: addiu       $a1, $zero, 0xD8
    ctx->r5 = ADD32(0, 0XD8);
    // 0x80008794: addiu       $a2, $zero, 0x98
    ctx->r6 = ADD32(0, 0X98);
    // 0x80008798: jal         0x8004F1A4
    // 0x8000879C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_8004F1A4(rdram, ctx);
        goto after_56;
    // 0x8000879C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_56:
    // 0x800087A0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800087A4: addiu       $a0, $a0, -0x3510
    ctx->r4 = ADD32(ctx->r4, -0X3510);
    // 0x800087A8: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x800087AC: addiu       $a2, $zero, 0xAC
    ctx->r6 = ADD32(0, 0XAC);
    // 0x800087B0: jal         0x8004F1A4
    // 0x800087B4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_57;
    // 0x800087B4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_57:
    // 0x800087B8: lhu         $a2, 0x9C($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X9C);
    // 0x800087BC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800087C0: jal         0x80066CA0
    // 0x800087C4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80066CA0(rdram, ctx);
        goto after_58;
    // 0x800087C4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_58:
    // 0x800087C8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800087CC: addiu       $a1, $zero, 0xD8
    ctx->r5 = ADD32(0, 0XD8);
    // 0x800087D0: addiu       $a2, $zero, 0xAC
    ctx->r6 = ADD32(0, 0XAC);
    // 0x800087D4: jal         0x8004F1A4
    // 0x800087D8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_8004F1A4(rdram, ctx);
        goto after_59;
    // 0x800087D8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_59:
    // 0x800087DC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800087E0: addiu       $a0, $a0, -0x34FC
    ctx->r4 = ADD32(ctx->r4, -0X34FC);
    // 0x800087E4: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x800087E8: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x800087EC: jal         0x8004F1A4
    // 0x800087F0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_60;
    // 0x800087F0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_60:
    // 0x800087F4: lw          $a2, 0xA8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XA8);
    // 0x800087F8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800087FC: jal         0x80066CA0
    // 0x80008800: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80066CA0(rdram, ctx);
        goto after_61;
    // 0x80008800: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_61:
    // 0x80008804: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80008808: addiu       $a1, $zero, 0xF8
    ctx->r5 = ADD32(0, 0XF8);
    // 0x8000880C: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x80008810: jal         0x8004F1A4
    // 0x80008814: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_8004F1A4(rdram, ctx);
        goto after_62;
    // 0x80008814: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_62:
    // 0x80008818: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000881C: addiu       $a0, $a0, -0x34F0
    ctx->r4 = ADD32(ctx->r4, -0X34F0);
    // 0x80008820: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80008824: addiu       $a2, $zero, 0xD4
    ctx->r6 = ADD32(0, 0XD4);
    // 0x80008828: jal         0x8004F1A4
    // 0x8000882C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004F1A4(rdram, ctx);
        goto after_63;
    // 0x8000882C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_63:
    // 0x80008830: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80008834: lbu         $a2, 0x7B68($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X7B68);
    // 0x80008838: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x8000883C: lbu         $a3, 0x7B69($a3)
    ctx->r7 = MEM_BU(ctx->r7, 0X7B69);
    // 0x80008840: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008844: lbu         $v0, 0x7B6A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B6A);
    // 0x80008848: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8000884C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80008850: addiu       $a1, $a1, -0x34E8
    ctx->r5 = ADD32(ctx->r5, -0X34E8);
    // 0x80008854: jal         0x80066CA0
    // 0x80008858: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80066CA0(rdram, ctx);
        goto after_64;
    // 0x80008858: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_64:
    // 0x8000885C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80008860: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    // 0x80008864: addiu       $a2, $zero, 0xD4
    ctx->r6 = ADD32(0, 0XD4);
L_80008868:
    // 0x80008868: jal         0x8004F1A4
    // 0x8000886C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_8004F1A4(rdram, ctx);
        goto after_65;
    // 0x8000886C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_65:
    // 0x80008870: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80008874: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80008878: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8000887C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80008880: jr          $ra
    // 0x80008884: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80008884: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80008888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008888: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000888C: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x80008890: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80008894: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80008898: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8000889C: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x800088A0: beq         $v0, $zero, L_800089D0
    if (ctx->r2 == 0) {
        // 0x800088A4: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800089D0;
    }
    // 0x800088A4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800088A8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800088AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800088B0: addu        $at, $at, $v0
    gpr jr_addend_800088B8 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800088B4: lw          $v0, -0x34A0($at)
    ctx->r2 = ADD32(ctx->r1, -0X34A0);
    // 0x800088B8: jr          $v0
    // 0x800088BC: nop

    switch (jr_addend_800088B8 >> 2) {
        case 0: goto L_800088C0; break;
        case 1: goto L_80008910; break;
        case 2: goto L_8000894C; break;
        case 3: goto L_80008974; break;
        case 4: goto L_80008980; break;
        case 5: goto L_800089B8; break;
        default: switch_error(__func__, 0x800088B8, 0x800ACB60);
    }
    // 0x800088BC: nop

L_800088C0:
    // 0x800088C0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800088C4: addiu       $v0, $v0, 0x7B71
    ctx->r2 = ADD32(ctx->r2, 0X7B71);
    // 0x800088C8: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800088CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800088D0: jal         0x80006708
    // 0x800088D4: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    func_80006708(rdram, ctx);
        goto after_0;
    // 0x800088D4: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    after_0:
    // 0x800088D8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800088DC: lbu         $v0, 0x7B7E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B7E);
    // 0x800088E0: bne         $v0, $zero, L_800088EC
    if (ctx->r2 != 0) {
        // 0x800088E4: addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
            goto L_800088EC;
    }
    // 0x800088E4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x800088E8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
L_800088EC:
    // 0x800088EC: jal         0x800067C8
    // 0x800088F0: nop

    func_800067C8(rdram, ctx);
        goto after_1;
    // 0x800088F0: nop

    after_1:
    // 0x800088F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800088F8: jal         0x8001C1F0
    // 0x800088FC: sb          $zero, 0x7B7E($at)
    MEM_B(0X7B7E, ctx->r1) = 0;
    func_8001C1F0(rdram, ctx);
        goto after_2;
    // 0x800088FC: sb          $zero, 0x7B7E($at)
    MEM_B(0X7B7E, ctx->r1) = 0;
    after_2:
    // 0x80008900: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80008904: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80008908: jal         0x8001D670
    // 0x8000890C: addiu       $a0, $a0, -0x2338
    ctx->r4 = ADD32(ctx->r4, -0X2338);
    func_8001D670(rdram, ctx);
        goto after_3;
    // 0x8000890C: addiu       $a0, $a0, -0x2338
    ctx->r4 = ADD32(ctx->r4, -0X2338);
    after_3:
L_80008910:
    // 0x80008910: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008914: addiu       $v0, $v0, 0x7B71
    ctx->r2 = ADD32(ctx->r2, 0X7B71);
    // 0x80008918: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8000891C: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x80008920: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008924: sh          $a0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r4;
    // 0x80008928: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000892C: jal         0x80007AF8
    // 0x80008930: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    func_80007AF8(rdram, ctx);
        goto after_4;
    // 0x80008930: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    after_4:
    // 0x80008934: jal         0x8000BC4C
    // 0x80008938: nop

    func_8000BC4C(rdram, ctx);
        goto after_5;
    // 0x80008938: nop

    after_5:
    // 0x8000893C: jal         0x8002D378
    // 0x80008940: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_6;
    // 0x80008940: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
    // 0x80008944: jal         0x8002D0D4
    // 0x80008948: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_7;
    // 0x80008948: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_7:
L_8000894C:
    // 0x8000894C: jal         0x8002CFB8
    // 0x80008950: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_8;
    // 0x80008950: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x80008954: beq         $v0, $zero, L_800089D0
    if (ctx->r2 == 0) {
        // 0x80008958: nop
    
            goto L_800089D0;
    }
    // 0x80008958: nop

    // 0x8000895C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80008960: addiu       $v1, $v1, 0x7B71
    ctx->r3 = ADD32(ctx->r3, 0X7B71);
    // 0x80008964: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80008968: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000896C: j           L_800089D0
    // 0x80008970: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
        goto L_800089D0;
    // 0x80008970: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_80008974:
    // 0x80008974: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008978: j           L_80008998
    // 0x8000897C: lbu         $v0, 0x7B94($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B94);
        goto L_80008998;
    // 0x8000897C: lbu         $v0, 0x7B94($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B94);
L_80008980:
    // 0x80008980: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80008984: addiu       $v1, $v1, 0x7B74
    ctx->r3 = ADD32(ctx->r3, 0X7B74);
    // 0x80008988: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8000898C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80008990: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80008994: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
L_80008998:
    // 0x80008998: bne         $v0, $zero, L_800089D0
    if (ctx->r2 != 0) {
        // 0x8000899C: nop
    
            goto L_800089D0;
    }
    // 0x8000899C: nop

    // 0x800089A0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800089A4: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x800089A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800089AC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800089B0: j           L_800089D0
    // 0x800089B4: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
        goto L_800089D0;
    // 0x800089B4: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
L_800089B8:
    // 0x800089B8: jal         0x8002CFB8
    // 0x800089BC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_9;
    // 0x800089BC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_9:
    // 0x800089C0: beq         $v0, $zero, L_800089D0
    if (ctx->r2 == 0) {
        // 0x800089C4: nop
    
            goto L_800089D0;
    }
    // 0x800089C4: nop

    // 0x800089C8: jal         0x80007F48
    // 0x800089CC: nop

    func_80007F48(rdram, ctx);
        goto after_10;
    // 0x800089CC: nop

    after_10:
L_800089D0:
    // 0x800089D0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x800089D4: addiu       $a0, $a0, -0x7660
    ctx->r4 = ADD32(ctx->r4, -0X7660);
    // 0x800089D8: jal         0x80017D38
    // 0x800089DC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    func_80017D38(rdram, ctx);
        goto after_11;
    // 0x800089DC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    after_11:
    // 0x800089E0: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x800089E4: addiu       $s0, $s0, 0x2120
    ctx->r16 = ADD32(ctx->r16, 0X2120);
L_800089E8:
    // 0x800089E8: jal         0x8000BD10
    // 0x800089EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8000BD10(rdram, ctx);
        goto after_12;
    // 0x800089EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_12:
    // 0x800089F0: jal         0x8001817C
    // 0x800089F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001817C(rdram, ctx);
        goto after_13;
    // 0x800089F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_13:
    // 0x800089F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800089FC: slti        $v0, $s1, 0x8
    ctx->r2 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x80008A00: bne         $v0, $zero, L_800089E8
    if (ctx->r2 != 0) {
        // 0x80008A04: addiu       $s0, $s0, 0x90
        ctx->r16 = ADD32(ctx->r16, 0X90);
            goto L_800089E8;
    }
    // 0x80008A04: addiu       $s0, $s0, 0x90
    ctx->r16 = ADD32(ctx->r16, 0X90);
    // 0x80008A08: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80008A0C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80008A10: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80008A14: jr          $ra
    // 0x80008A18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80008A18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80008A1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008A1C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008A20: lbu         $v0, 0x7B84($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B84);
    // 0x80008A24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008A28: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80008A2C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008A30: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
    // 0x80008A34: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80008A38: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008A3C: jal         0x8000C494
    // 0x80008A40: sb          $v0, 0x7B84($at)
    MEM_B(0X7B84, ctx->r1) = ctx->r2;
    func_8000C494(rdram, ctx);
        goto after_0;
    // 0x80008A40: sb          $v0, 0x7B84($at)
    MEM_B(0X7B84, ctx->r1) = ctx->r2;
    after_0:
    // 0x80008A44: jal         0x8000C1F4
    // 0x80008A48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8000C1F4(rdram, ctx);
        goto after_1;
    // 0x80008A48: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80008A4C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008A50: lb          $v0, 0x25A5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A5);
    // 0x80008A54: bltz        $v0, L_80008AA0
    if (SIGNED(ctx->r2) < 0) {
        // 0x80008A58: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80008AA0;
    }
    // 0x80008A58: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80008A5C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80008A60: lbu         $a0, 0x2604($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X2604);
    // 0x80008A64: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80008A68: lw          $a1, 0x26A4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X26A4);
    // 0x80008A6C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80008A70: lbu         $v1, 0x2614($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2614);
    // 0x80008A74: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008A78: sb          $v0, 0x2604($at)
    MEM_B(0X2604, ctx->r1) = ctx->r2;
    // 0x80008A7C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80008A80: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80008A84: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80008A88: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008A8C: sb          $a0, 0x2605($at)
    MEM_B(0X2605, ctx->r1) = ctx->r4;
    // 0x80008A90: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008A94: sw          $a1, 0x26A8($at)
    MEM_W(0X26A8, ctx->r1) = ctx->r5;
    // 0x80008A98: j           L_80008AC8
    // 0x80008A9C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
        goto L_80008AC8;
    // 0x80008A9C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_80008AA0:
    // 0x80008AA0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80008AA4: lbu         $v1, 0x2614($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2614);
    // 0x80008AA8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008AAC: sb          $v0, 0x2604($at)
    MEM_B(0X2604, ctx->r1) = ctx->r2;
    // 0x80008AB0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008AB4: sb          $v0, 0x2605($at)
    MEM_B(0X2605, ctx->r1) = ctx->r2;
    // 0x80008AB8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80008ABC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80008AC0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80008AC4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_80008AC8:
    // 0x80008AC8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80008ACC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80008AD0: lbu         $v0, -0x3996($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X3996);
    // 0x80008AD4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008AD8: sb          $v0, 0x2606($at)
    MEM_B(0X2606, ctx->r1) = ctx->r2;
    // 0x80008ADC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80008AE0: lbu         $a1, 0x25A5($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X25A5);
    // 0x80008AE4: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x80008AE8: jal         0x8000637C
    // 0x80008AEC: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_2;
    // 0x80008AEC: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_2:
    // 0x80008AF0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80008AF4: lbu         $v1, 0x25A5($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X25A5);
    // 0x80008AF8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80008AFC: lb          $a0, 0x79F5($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X79F5);
    // 0x80008B00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80008B04: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008B08: sb          $v0, 0x25A0($at)
    MEM_B(0X25A0, ctx->r1) = ctx->r2;
    // 0x80008B0C: andi        $v1, $v1, 0x7F
    ctx->r3 = ctx->r3 & 0X7F;
    // 0x80008B10: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008B14: sb          $v1, 0x25A5($at)
    MEM_B(0X25A5, ctx->r1) = ctx->r3;
    // 0x80008B18: bltz        $a0, L_80008B64
    if (SIGNED(ctx->r4) < 0) {
        // 0x80008B1C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80008B64;
    }
    // 0x80008B1C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80008B20: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80008B24: lbu         $a0, 0x7A54($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7A54);
    // 0x80008B28: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80008B2C: lw          $a1, 0x7AF4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7AF4);
    // 0x80008B30: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80008B34: lbu         $v1, 0x7A64($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7A64);
    // 0x80008B38: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008B3C: sb          $v0, 0x7A54($at)
    MEM_B(0X7A54, ctx->r1) = ctx->r2;
    // 0x80008B40: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80008B44: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80008B48: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80008B4C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008B50: sb          $a0, 0x7A55($at)
    MEM_B(0X7A55, ctx->r1) = ctx->r4;
    // 0x80008B54: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008B58: sw          $a1, 0x7AF8($at)
    MEM_W(0X7AF8, ctx->r1) = ctx->r5;
    // 0x80008B5C: j           L_80008B8C
    // 0x80008B60: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
        goto L_80008B8C;
    // 0x80008B60: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_80008B64:
    // 0x80008B64: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80008B68: lbu         $v1, 0x7A64($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7A64);
    // 0x80008B6C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008B70: sb          $v0, 0x7A54($at)
    MEM_B(0X7A54, ctx->r1) = ctx->r2;
    // 0x80008B74: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008B78: sb          $v0, 0x7A55($at)
    MEM_B(0X7A55, ctx->r1) = ctx->r2;
    // 0x80008B7C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80008B80: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80008B84: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80008B88: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_80008B8C:
    // 0x80008B8C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80008B90: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80008B94: lbu         $v0, -0x3996($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X3996);
    // 0x80008B98: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008B9C: sb          $v0, 0x7A56($at)
    MEM_B(0X7A56, ctx->r1) = ctx->r2;
    // 0x80008BA0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80008BA4: lbu         $a1, 0x79F5($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X79F5);
    // 0x80008BA8: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x80008BAC: jal         0x8000637C
    // 0x80008BB0: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_3;
    // 0x80008BB0: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_3:
    // 0x80008BB4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008BB8: lbu         $v0, 0x79F5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X79F5);
    // 0x80008BBC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80008BC0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008BC4: sb          $v1, 0x79F0($at)
    MEM_B(0X79F0, ctx->r1) = ctx->r3;
    // 0x80008BC8: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80008BCC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008BD0: sb          $v0, 0x79F5($at)
    MEM_B(0X79F5, ctx->r1) = ctx->r2;
    // 0x80008BD4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80008BD8: jr          $ra
    // 0x80008BDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80008BDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80008BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008BE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008BE4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80008BE8: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80008BEC: addiu       $s0, $s0, 0x7B71
    ctx->r16 = ADD32(ctx->r16, 0X7B71);
    // 0x80008BF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008BF4: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x80008BF8: beq         $v1, $zero, L_80008C10
    if (ctx->r3 == 0) {
        // 0x80008BFC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80008C10;
    }
    // 0x80008BFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80008C00: beq         $v1, $v0, L_80008C70
    if (ctx->r3 == ctx->r2) {
        // 0x80008C04: nop
    
            goto L_80008C70;
    }
    // 0x80008C04: nop

    // 0x80008C08: j           L_80008CB4
    // 0x80008C0C: nop

        goto L_80008CB4;
    // 0x80008C0C: nop

L_80008C10:
    // 0x80008C10: jal         0x8002D378
    // 0x80008C14: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_0;
    // 0x80008C14: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80008C18: jal         0x8002D0D4
    // 0x80008C1C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_1;
    // 0x80008C1C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x80008C20: jal         0x8002CFB8
    // 0x80008C24: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_2;
    // 0x80008C24: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // 0x80008C28: beq         $v0, $zero, L_80008CB4
    if (ctx->r2 == 0) {
        // 0x80008C2C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80008CB4;
    }
    // 0x80008C2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80008C30: jal         0x80006998
    // 0x80008C34: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    func_80006998(rdram, ctx);
        goto after_3;
    // 0x80008C34: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    after_3:
    // 0x80008C38: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008C3C: lbu         $v0, 0x2081($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2081);
    // 0x80008C40: bne         $v0, $zero, L_80008C5C
    if (ctx->r2 != 0) {
        // 0x80008C44: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80008C5C;
    }
    // 0x80008C44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80008C48: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008C4C: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x80008C50: bne         $v0, $zero, L_80008C5C
    if (ctx->r2 != 0) {
        // 0x80008C54: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80008C5C;
    }
    // 0x80008C54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80008C58: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_80008C5C:
    // 0x80008C5C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008C60: jal         0x80008A1C
    // 0x80008C64: sh          $v0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r2;
    func_80008A1C(rdram, ctx);
        goto after_4;
    // 0x80008C64: sh          $v0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r2;
    after_4:
    // 0x80008C68: j           L_80008CB4
    // 0x80008C6C: nop

        goto L_80008CB4;
    // 0x80008C6C: nop

L_80008C70:
    // 0x80008C70: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008C74: lhu         $v0, 0x7B74($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7B74);
    // 0x80008C78: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80008C7C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008C80: sh          $v0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r2;
    // 0x80008C84: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80008C88: bne         $v0, $zero, L_80008CB4
    if (ctx->r2 != 0) {
        // 0x80008C8C: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_80008CB4;
    }
    // 0x80008C8C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80008C90: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80008C94: lw          $v1, 0x7BB8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7BB8);
    // 0x80008C98: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008C9C: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x80008CA0: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80008CA4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008CA8: sb          $zero, 0x7B83($at)
    MEM_B(0X7B83, ctx->r1) = 0;
    // 0x80008CAC: sb          $zero, 0x53($v1)
    MEM_B(0X53, ctx->r3) = 0;
    // 0x80008CB0: sb          $zero, 0x48($v1)
    MEM_B(0X48, ctx->r3) = 0;
L_80008CB4:
    // 0x80008CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008CB8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80008CBC: jr          $ra
    // 0x80008CC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80008CC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80008CC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008CC4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x80008CC8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008CCC: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x80008CD0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008CD4: jr          $ra
    // 0x80008CD8: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    return;
    // 0x80008CD8: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80008CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008CDC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008CE0: lbu         $v0, 0x7B83($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B83);
    // 0x80008CE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008CE8: beq         $v0, $zero, L_80008D28
    if (ctx->r2 == 0) {
        // 0x80008CEC: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80008D28;
    }
    // 0x80008CEC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80008CF0: jal         0x8002D378
    // 0x80008CF4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_0;
    // 0x80008CF4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80008CF8: jal         0x8002D0D4
    // 0x80008CFC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_1;
    // 0x80008CFC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x80008D00: jal         0x8002CFB8
    // 0x80008D04: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_2;
    // 0x80008D04: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // 0x80008D08: beq         $v0, $zero, L_80008D20
    if (ctx->r2 == 0) {
        // 0x80008D0C: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_80008D20;
    }
    // 0x80008D0C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80008D10: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008D14: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x80008D18: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008D1C: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
L_80008D20:
    // 0x80008D20: j           L_80008D2C
    // 0x80008D24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80008D2C;
    // 0x80008D24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80008D28:
    // 0x80008D28: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80008D2C:
    // 0x80008D2C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80008D30: jr          $ra
    // 0x80008D34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80008D34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80008D38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008D38: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008D3C: lbu         $v0, 0x2074($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2074);
    // 0x80008D40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008D44: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80008D48: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80008D4C: beq         $v0, $zero, L_80008E9C
    if (ctx->r2 == 0) {
        // 0x80008D50: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80008E9C;
    }
    // 0x80008D50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008D54: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008D58: lbu         $v0, 0x7B83($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B83);
    // 0x80008D5C: bne         $v0, $zero, L_80008E9C
    if (ctx->r2 != 0) {
        // 0x80008D60: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80008E9C;
    }
    // 0x80008D60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80008D64: lb          $a0, 0x1($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1);
    // 0x80008D68: bne         $a0, $v0, L_80008E9C
    if (ctx->r4 != ctx->r2) {
        // 0x80008D6C: nop
    
            goto L_80008E9C;
    }
    // 0x80008D6C: nop

    // 0x80008D70: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x80008D74: beq         $v0, $zero, L_80008E9C
    if (ctx->r2 == 0) {
        // 0x80008D78: nop
    
            goto L_80008E9C;
    }
    // 0x80008D78: nop

    // 0x80008D7C: lw          $v0, 0xB4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB4);
    // 0x80008D80: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80008D84: andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // 0x80008D88: beq         $v0, $zero, L_80008E9C
    if (ctx->r2 == 0) {
        // 0x80008D8C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80008E9C;
    }
    // 0x80008D8C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80008D90: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80008D94: lb          $v1, 0x25FA($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X25FA);
    // 0x80008D98: bne         $v1, $v0, L_80008DF4
    if (ctx->r3 != ctx->r2) {
        // 0x80008D9C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80008DF4;
    }
    // 0x80008D9C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80008DA0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008DA4: lb          $v0, 0x7A4A($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7A4A);
    // 0x80008DA8: bne         $v0, $v1, L_80008DF4
    if (ctx->r2 != ctx->r3) {
        // 0x80008DAC: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80008DF4;
    }
    // 0x80008DAC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80008DB0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008DB4: lb          $v0, 0x25A5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A5);
    // 0x80008DB8: bltz        $v0, L_80008DF4
    if (SIGNED(ctx->r2) < 0) {
        // 0x80008DBC: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80008DF4;
    }
    // 0x80008DBC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80008DC0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008DC4: lb          $v0, 0x79F5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F5);
    // 0x80008DC8: bltz        $v0, L_80008DF4
    if (SIGNED(ctx->r2) < 0) {
        // 0x80008DCC: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80008DF4;
    }
    // 0x80008DCC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80008DD0: lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5);
    // 0x80008DD4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80008DD8: lbu         $v1, 0x7B8F($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B8F);
    // 0x80008DDC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80008DE0: sllv        $v0, $a0, $v0
    ctx->r2 = S32(ctx->r4 << (ctx->r2 & 31));
    // 0x80008DE4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80008DE8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008DEC: j           L_80008DFC
    // 0x80008DF0: sb          $v1, 0x7B8F($at)
    MEM_B(0X7B8F, ctx->r1) = ctx->r3;
        goto L_80008DFC;
    // 0x80008DF0: sb          $v1, 0x7B8F($at)
    MEM_B(0X7B8F, ctx->r1) = ctx->r3;
L_80008DF4:
    // 0x80008DF4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008DF8: sb          $v0, 0x7B8F($at)
    MEM_B(0X7B8F, ctx->r1) = ctx->r2;
L_80008DFC:
    // 0x80008DFC: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    // 0x80008E00: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80008E04: addiu       $a2, $a2, 0x7B99
    ctx->r6 = ADD32(ctx->r6, 0X7B99);
    // 0x80008E08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80008E0C: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x80008E10: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80008E14: lbu         $a1, 0x7B9C($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X7B9C);
    // 0x80008E18: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    // 0x80008E1C: sllv        $v0, $v0, $a0
    ctx->r2 = S32(ctx->r2 << (ctx->r4 & 31));
    // 0x80008E20: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80008E24: bne         $a1, $zero, L_80008E38
    if (ctx->r5 != 0) {
        // 0x80008E28: sb          $v1, 0x0($a2)
        MEM_B(0X0, ctx->r6) = ctx->r3;
            goto L_80008E38;
    }
    // 0x80008E28: sb          $v1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r3;
    // 0x80008E2C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80008E30: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008E34: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
L_80008E38:
    // 0x80008E38: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80008E3C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008E40: sb          $v0, 0x2089($at)
    MEM_B(0X2089, ctx->r1) = ctx->r2;
    // 0x80008E44: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008E48: lbu         $v0, 0x2089($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2089);
    // 0x80008E4C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80008E50: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008E54: jal         0x80006A78
    // 0x80008E58: sb          $v0, 0x2088($at)
    MEM_B(0X2088, ctx->r1) = ctx->r2;
    func_80006A78(rdram, ctx);
        goto after_0;
    // 0x80008E58: sb          $v0, 0x2088($at)
    MEM_B(0X2088, ctx->r1) = ctx->r2;
    after_0:
    // 0x80008E5C: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x80008E60: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x80008E64: jal         0x8000637C
    // 0x80008E68: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_1;
    // 0x80008E68: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_1:
    // 0x80008E6C: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x80008E70: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x80008E74: jal         0x8000637C
    // 0x80008E78: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_2;
    // 0x80008E78: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_2:
    // 0x80008E7C: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80008E80: lbu         $a1, 0x5($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X5);
    // 0x80008E84: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x80008E88: jal         0x8000637C
    // 0x80008E8C: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_3;
    // 0x80008E8C: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_3:
    // 0x80008E90: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80008E94: sb          $zero, 0x6A($v0)
    MEM_B(0X6A, ctx->r2) = 0;
    // 0x80008E98: sb          $zero, 0x6A($s0)
    MEM_B(0X6A, ctx->r16) = 0;
L_80008E9C:
    // 0x80008E9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008EA0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80008EA4: jr          $ra
    // 0x80008EA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80008EA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80008EAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008EAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008EB0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80008EB4: lbu         $v1, 0x5($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X5);
    // 0x80008EB8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008EBC: lbu         $v0, 0x7B99($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B99);
    // 0x80008EC0: andi        $a1, $v1, 0x1
    ctx->r5 = ctx->r3 & 0X1;
    // 0x80008EC4: srav        $v0, $v0, $a1
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r5 & 31));
    // 0x80008EC8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80008ECC: beq         $v0, $zero, L_80008F94
    if (ctx->r2 == 0) {
        // 0x80008ED0: nop
    
            goto L_80008F94;
    }
    // 0x80008ED0: nop

    // 0x80008ED4: lw          $v0, 0xB4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB4);
    // 0x80008ED8: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80008EDC: andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // 0x80008EE0: beq         $v0, $zero, L_80008F94
    if (ctx->r2 == 0) {
        // 0x80008EE4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80008F94;
    }
    // 0x80008EE4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80008EE8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80008EEC: lb          $v1, 0x25FA($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X25FA);
    // 0x80008EF0: bne         $v1, $v0, L_80008F48
    if (ctx->r3 != ctx->r2) {
        // 0x80008EF4: nop
    
            goto L_80008F48;
    }
    // 0x80008EF4: nop

    // 0x80008EF8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008EFC: lb          $v0, 0x7A4A($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7A4A);
    // 0x80008F00: bne         $v0, $v1, L_80008F48
    if (ctx->r2 != ctx->r3) {
        // 0x80008F04: nop
    
            goto L_80008F48;
    }
    // 0x80008F04: nop

    // 0x80008F08: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008F0C: lb          $v0, 0x25A5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A5);
    // 0x80008F10: bltz        $v0, L_80008F48
    if (SIGNED(ctx->r2) < 0) {
        // 0x80008F14: nop
    
            goto L_80008F48;
    }
    // 0x80008F14: nop

    // 0x80008F18: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008F1C: lb          $v0, 0x79F5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F5);
    // 0x80008F20: bltz        $v0, L_80008F48
    if (SIGNED(ctx->r2) < 0) {
        // 0x80008F24: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80008F48;
    }
    // 0x80008F24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80008F28: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80008F2C: lbu         $v1, 0x7B8F($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B8F);
    // 0x80008F30: sllv        $v0, $v0, $a1
    ctx->r2 = S32(ctx->r2 << (ctx->r5 & 31));
    // 0x80008F34: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x80008F38: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80008F3C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008F40: j           L_80008F50
    // 0x80008F44: sb          $v1, 0x7B8F($at)
    MEM_B(0X7B8F, ctx->r1) = ctx->r3;
        goto L_80008F50;
    // 0x80008F44: sb          $v1, 0x7B8F($at)
    MEM_B(0X7B8F, ctx->r1) = ctx->r3;
L_80008F48:
    // 0x80008F48: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008F4C: sb          $zero, 0x7B8F($at)
    MEM_B(0X7B8F, ctx->r1) = 0;
L_80008F50:
    // 0x80008F50: lbu         $v1, 0x5($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X5);
    // 0x80008F54: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80008F58: addiu       $a1, $a1, 0x7B99
    ctx->r5 = ADD32(ctx->r5, 0X7B99);
    // 0x80008F5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80008F60: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x80008F64: sllv        $v0, $v0, $v1
    ctx->r2 = S32(ctx->r2 << (ctx->r3 & 31));
    // 0x80008F68: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80008F6C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80008F70: lbu         $a0, 0x7B9C($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B9C);
    // 0x80008F74: nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // 0x80008F78: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80008F7C: bne         $a0, $zero, L_80008F8C
    if (ctx->r4 != 0) {
        // 0x80008F80: sb          $v1, 0x0($a1)
        MEM_B(0X0, ctx->r5) = ctx->r3;
            goto L_80008F8C;
    }
    // 0x80008F80: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
    // 0x80008F84: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80008F88: sb          $zero, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = 0;
L_80008F8C:
    // 0x80008F8C: jal         0x80006A78
    // 0x80008F90: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80006A78(rdram, ctx);
        goto after_0;
    // 0x80008F90: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
L_80008F94:
    // 0x80008F94: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80008F98: jr          $ra
    // 0x80008F9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80008F9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80008FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008FA0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008FA4: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x80008FA8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80008FAC: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x80008FB0: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80008FB4: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80008FB8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80008FBC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80008FC0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80008FC4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80008FC8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80008FCC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80008FD0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80008FD4: lw          $v0, -0xE9C($at)
    ctx->r2 = MEM_W(ctx->r1, -0XE9C);
    // 0x80008FD8: jalr        $v0
    // 0x80008FDC: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80008FDC: nop

    after_0:
    // 0x80008FE0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80008FE4: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80008FE8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80008FEC: bne         $v0, $zero, L_80009008
    if (ctx->r2 != 0) {
        // 0x80008FF0: nop
    
            goto L_80009008;
    }
    // 0x80008FF0: nop

    // 0x80008FF4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80008FF8: jal         0x80008D38
    // 0x80008FFC: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    func_80008D38(rdram, ctx);
        goto after_1;
    // 0x80008FFC: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    after_1:
    // 0x80009000: j           L_80009014
    // 0x80009004: nop

        goto L_80009014;
    // 0x80009004: nop

L_80009008:
    // 0x80009008: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000900C: jal         0x80008EAC
    // 0x80009010: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    func_80008EAC(rdram, ctx);
        goto after_2;
    // 0x80009010: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    after_2:
L_80009014:
    // 0x80009014: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009018: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x8000901C: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80009020: bne         $v0, $zero, L_8000903C
    if (ctx->r2 != 0) {
        // 0x80009024: nop
    
            goto L_8000903C;
    }
    // 0x80009024: nop

    // 0x80009028: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000902C: jal         0x80008D38
    // 0x80009030: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    func_80008D38(rdram, ctx);
        goto after_3;
    // 0x80009030: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    after_3:
    // 0x80009034: j           L_80009048
    // 0x80009038: nop

        goto L_80009048;
    // 0x80009038: nop

L_8000903C:
    // 0x8000903C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80009040: jal         0x80008EAC
    // 0x80009044: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    func_80008EAC(rdram, ctx);
        goto after_4;
    // 0x80009044: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    after_4:
L_80009048:
    // 0x80009048: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8000904C: addiu       $s0, $s0, 0x7B8F
    ctx->r16 = ADD32(ctx->r16, 0X7B8F);
    // 0x80009050: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80009054: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80009058: bne         $v0, $zero, L_8000906C
    if (ctx->r2 != 0) {
        // 0x8000905C: nop
    
            goto L_8000906C;
    }
    // 0x8000905C: nop

    // 0x80009060: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80009064: jal         0x80012DF0
    // 0x80009068: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    func_80012DF0(rdram, ctx);
        goto after_5;
    // 0x80009068: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    after_5:
L_8000906C:
    // 0x8000906C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80009070: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80009074: bne         $v0, $zero, L_80009088
    if (ctx->r2 != 0) {
        // 0x80009078: nop
    
            goto L_80009088;
    }
    // 0x80009078: nop

    // 0x8000907C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80009080: jal         0x80012DF0
    // 0x80009084: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    func_80012DF0(rdram, ctx);
        goto after_6;
    // 0x80009084: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    after_6:
L_80009088:
    // 0x80009088: jal         0x800333E8
    // 0x8000908C: nop

    func_800333E8(rdram, ctx);
        goto after_7;
    // 0x8000908C: nop

    after_7:
    // 0x80009090: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009094: lbu         $v0, 0x7B7D($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B7D);
    // 0x80009098: bne         $v0, $zero, L_800090F4
    if (ctx->r2 != 0) {
        // 0x8000909C: nop
    
            goto L_800090F4;
    }
    // 0x8000909C: nop

    // 0x800090A0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800090A4: bne         $v0, $zero, L_800090F4
    if (ctx->r2 != 0) {
        // 0x800090A8: nop
    
            goto L_800090F4;
    }
    // 0x800090A8: nop

    // 0x800090AC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800090B0: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x800090B4: addiu       $s2, $s2, 0x7BD0
    ctx->r18 = ADD32(ctx->r18, 0X7BD0);
    // 0x800090B8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_800090BC:
    // 0x800090BC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800090C0: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800090C4: lb          $v0, 0x7BD0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7BD0);
    // 0x800090C8: beql        $v0, $zero, L_800090DC
    if (ctx->r2 == 0) {
        // 0x800090CC: addiu       $s2, $s2, 0x68
        ctx->r18 = ADD32(ctx->r18, 0X68);
            goto L_800090DC;
    }
    goto skip_0;
    // 0x800090CC: addiu       $s2, $s2, 0x68
    ctx->r18 = ADD32(ctx->r18, 0X68);
    skip_0:
    // 0x800090D0: jal         0x80027FC4
    // 0x800090D4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80027FC4(rdram, ctx);
        goto after_8;
    // 0x800090D4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_8:
    // 0x800090D8: addiu       $s2, $s2, 0x68
    ctx->r18 = ADD32(ctx->r18, 0X68);
L_800090DC:
    // 0x800090DC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800090E0: slti        $v0, $s1, 0x18
    ctx->r2 = SIGNED(ctx->r17) < 0X18 ? 1 : 0;
    // 0x800090E4: bne         $v0, $zero, L_800090BC
    if (ctx->r2 != 0) {
        // 0x800090E8: addiu       $s0, $s0, 0x68
        ctx->r16 = ADD32(ctx->r16, 0X68);
            goto L_800090BC;
    }
    // 0x800090E8: addiu       $s0, $s0, 0x68
    ctx->r16 = ADD32(ctx->r16, 0X68);
    // 0x800090EC: jal         0x800114F8
    // 0x800090F0: nop

    func_800114F8(rdram, ctx);
        goto after_9;
    // 0x800090F0: nop

    after_9:
L_800090F4:
    // 0x800090F4: jal         0x800185A8
    // 0x800090F8: nop

    func_800185A8(rdram, ctx);
        goto after_10;
    // 0x800090F8: nop

    after_10:
    // 0x800090FC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009100: lb          $v0, 0x25FA($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25FA);
    // 0x80009104: beq         $v0, $zero, L_8000911C
    if (ctx->r2 == 0) {
        // 0x80009108: nop
    
            goto L_8000911C;
    }
    // 0x80009108: nop

    // 0x8000910C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009110: lb          $v0, 0x7A4A($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7A4A);
    // 0x80009114: bne         $v0, $zero, L_80009128
    if (ctx->r2 != 0) {
        // 0x80009118: nop
    
            goto L_80009128;
    }
    // 0x80009118: nop

L_8000911C:
    // 0x8000911C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80009120: jal         0x8000FF40
    // 0x80009124: addiu       $a0, $a0, 0x5510
    ctx->r4 = ADD32(ctx->r4, 0X5510);
    func_8000FF40(rdram, ctx);
        goto after_11;
    // 0x80009124: addiu       $a0, $a0, 0x5510
    ctx->r4 = ADD32(ctx->r4, 0X5510);
    after_11:
L_80009128:
    // 0x80009128: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x8000912C: jal         0x80017D38
    // 0x80009130: addiu       $a0, $a0, -0x7660
    ctx->r4 = ADD32(ctx->r4, -0X7660);
    func_80017D38(rdram, ctx);
        goto after_12;
    // 0x80009130: addiu       $a0, $a0, -0x7660
    ctx->r4 = ADD32(ctx->r4, -0X7660);
    after_12:
    // 0x80009134: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80009138: addiu       $a0, $a0, 0x20D0
    ctx->r4 = ADD32(ctx->r4, 0X20D0);
    // 0x8000913C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80009140: beq         $v0, $zero, L_80009168
    if (ctx->r2 == 0) {
        // 0x80009144: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80009168;
    }
    // 0x80009144: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80009148: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000914C: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80009150: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80009154: beq         $v0, $zero, L_80009168
    if (ctx->r2 == 0) {
        // 0x80009158: nop
    
            goto L_80009168;
    }
    // 0x80009158: nop

    // 0x8000915C: jal         0x80017D38
    // 0x80009160: addiu       $a0, $a0, -0x28
    ctx->r4 = ADD32(ctx->r4, -0X28);
    func_80017D38(rdram, ctx);
        goto after_13;
    // 0x80009160: addiu       $a0, $a0, -0x28
    ctx->r4 = ADD32(ctx->r4, -0X28);
    after_13:
    // 0x80009164: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80009168:
    // 0x80009168: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x8000916C: addiu       $s3, $s3, 0x3520
    ctx->r19 = ADD32(ctx->r19, 0X3520);
    // 0x80009170: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80009174: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x80009178: addiu       $s2, $s2, 0x6AA0
    ctx->r18 = ADD32(ctx->r18, 0X6AA0);
L_8000917C:
    // 0x8000917C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009180: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80009184: lbu         $v0, 0x6AC8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC8);
    // 0x80009188: beq         $v0, $zero, L_800091AC
    if (ctx->r2 == 0) {
        // 0x8000918C: nop
    
            goto L_800091AC;
    }
    // 0x8000918C: nop

    // 0x80009190: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009194: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80009198: lbu         $v0, 0x6ACD($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6ACD);
    // 0x8000919C: bne         $v0, $zero, L_800091AC
    if (ctx->r2 != 0) {
        // 0x800091A0: nop
    
            goto L_800091AC;
    }
    // 0x800091A0: nop

    // 0x800091A4: jal         0x80017D38
    // 0x800091A8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80017D38(rdram, ctx);
        goto after_14;
    // 0x800091A8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_14:
L_800091AC:
    // 0x800091AC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800091B0: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800091B4: lbu         $v0, 0x3548($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3548);
    // 0x800091B8: beql        $v0, $zero, L_800091E0
    if (ctx->r2 == 0) {
        // 0x800091BC: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_800091E0;
    }
    goto skip_1;
    // 0x800091BC: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    skip_1:
    // 0x800091C0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800091C4: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800091C8: lbu         $v0, 0x354D($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X354D);
    // 0x800091CC: bnel        $v0, $zero, L_800091E0
    if (ctx->r2 != 0) {
        // 0x800091D0: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_800091E0;
    }
    goto skip_2;
    // 0x800091D0: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    skip_2:
    // 0x800091D4: jal         0x80017D38
    // 0x800091D8: addu        $a0, $s0, $s3
    ctx->r4 = ADD32(ctx->r16, ctx->r19);
    func_80017D38(rdram, ctx);
        goto after_15;
    // 0x800091D8: addu        $a0, $s0, $s3
    ctx->r4 = ADD32(ctx->r16, ctx->r19);
    after_15:
    // 0x800091DC: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
L_800091E0:
    // 0x800091E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800091E4: slti        $v0, $s1, 0x23
    ctx->r2 = SIGNED(ctx->r17) < 0X23 ? 1 : 0;
    // 0x800091E8: bne         $v0, $zero, L_8000917C
    if (ctx->r2 != 0) {
        // 0x800091EC: addiu       $s2, $s2, 0x70
        ctx->r18 = ADD32(ctx->r18, 0X70);
            goto L_8000917C;
    }
    // 0x800091EC: addiu       $s2, $s2, 0x70
    ctx->r18 = ADD32(ctx->r18, 0X70);
    // 0x800091F0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800091F4: lbu         $v1, 0x7B87($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B87);
    // 0x800091F8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800091FC: beql        $v1, $v0, L_80009508
    if (ctx->r3 == ctx->r2) {
        // 0x80009200: addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
            goto L_80009508;
    }
    goto skip_3;
    // 0x80009200: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    skip_3:
    // 0x80009204: jal         0x8001CA78
    // 0x80009208: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    func_8001CA78(rdram, ctx);
        goto after_16;
    // 0x80009208: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    after_16:
    // 0x8000920C: lui         $a0, 0xB900
    ctx->r4 = S32(0XB900 << 16);
    // 0x80009210: ori         $a0, $a0, 0x31D
    ctx->r4 = ctx->r4 | 0X31D;
    // 0x80009214: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80009218: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8000921C: lui         $v0, 0xF0A
    ctx->r2 = S32(0XF0A << 16);
    // 0x80009220: ori         $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 | 0X4000;
    // 0x80009224: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80009228: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8000922C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009230: lbu         $v0, 0x25A5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X25A5);
    // 0x80009234: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80009238: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000923C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80009240: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80009244: beql        $v0, $zero, L_8000924C
    if (ctx->r2 == 0) {
        // 0x80009248: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_8000924C;
    }
    goto skip_4;
    // 0x80009248: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    skip_4:
L_8000924C:
    // 0x8000924C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009250: lbu         $v0, 0x25F0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X25F0);
    // 0x80009254: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80009258: beq         $v0, $zero, L_80009274
    if (ctx->r2 == 0) {
        // 0x8000925C: nop
    
            goto L_80009274;
    }
    // 0x8000925C: nop

    // 0x80009260: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009264: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80009268: and         $v0, $v0, $s0
    ctx->r2 = ctx->r2 & ctx->r16;
    // 0x8000926C: beq         $v0, $zero, L_80009280
    if (ctx->r2 == 0) {
        // 0x80009270: nop
    
            goto L_80009280;
    }
    // 0x80009270: nop

L_80009274:
    // 0x80009274: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80009278: jal         0x800116CC
    // 0x8000927C: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    func_800116CC(rdram, ctx);
        goto after_17;
    // 0x8000927C: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    after_17:
L_80009280:
    // 0x80009280: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009284: lb          $v0, 0x25EA($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25EA);
    // 0x80009288: beq         $v0, $zero, L_80009314
    if (ctx->r2 == 0) {
        // 0x8000928C: lui         $a0, 0xB900
        ctx->r4 = S32(0XB900 << 16);
            goto L_80009314;
    }
    // 0x8000928C: lui         $a0, 0xB900
    ctx->r4 = S32(0XB900 << 16);
    // 0x80009290: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009294: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80009298: and         $v0, $v0, $s0
    ctx->r2 = ctx->r2 & ctx->r16;
    // 0x8000929C: bne         $v0, $zero, L_80009318
    if (ctx->r2 != 0) {
        // 0x800092A0: ori         $a0, $a0, 0x31D
        ctx->r4 = ctx->r4 | 0X31D;
            goto L_80009318;
    }
    // 0x800092A0: ori         $a0, $a0, 0x31D
    ctx->r4 = ctx->r4 | 0X31D;
    // 0x800092A4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800092A8: lbu         $v0, 0x25F0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X25F0);
    // 0x800092AC: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800092B0: beq         $v0, $zero, L_800092CC
    if (ctx->r2 == 0) {
        // 0x800092B4: nop
    
            goto L_800092CC;
    }
    // 0x800092B4: nop

    // 0x800092B8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800092BC: jal         0x8001212C
    // 0x800092C0: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    func_8001212C(rdram, ctx);
        goto after_18;
    // 0x800092C0: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    after_18:
    // 0x800092C4: j           L_800092D8
    // 0x800092C8: nop

        goto L_800092D8;
    // 0x800092C8: nop

L_800092CC:
    // 0x800092CC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800092D0: jal         0x800123FC
    // 0x800092D4: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    func_800123FC(rdram, ctx);
        goto after_19;
    // 0x800092D4: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    after_19:
L_800092D8:
    // 0x800092D8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800092DC: lb          $v0, 0x25E9($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25E9);
    // 0x800092E0: beq         $v0, $zero, L_80009314
    if (ctx->r2 == 0) {
        // 0x800092E4: lui         $a0, 0xB900
        ctx->r4 = S32(0XB900 << 16);
            goto L_80009314;
    }
    // 0x800092E4: lui         $a0, 0xB900
    ctx->r4 = S32(0XB900 << 16);
    // 0x800092E8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800092EC: lbu         $v0, 0x2609($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2609);
    // 0x800092F0: beq         $v0, $zero, L_80009304
    if (ctx->r2 == 0) {
        // 0x800092F4: nop
    
            goto L_80009304;
    }
    // 0x800092F4: nop

    // 0x800092F8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800092FC: jal         0x80011CD8
    // 0x80009300: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    func_80011CD8(rdram, ctx);
        goto after_20;
    // 0x80009300: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    after_20:
L_80009304:
    // 0x80009304: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80009308: jal         0x80011914
    // 0x8000930C: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    func_80011914(rdram, ctx);
        goto after_21;
    // 0x8000930C: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    after_21:
    // 0x80009310: lui         $a0, 0xB900
    ctx->r4 = S32(0XB900 << 16);
L_80009314:
    // 0x80009314: ori         $a0, $a0, 0x31D
    ctx->r4 = ctx->r4 | 0X31D;
L_80009318:
    // 0x80009318: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8000931C: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80009320: lui         $v0, 0xF0A
    ctx->r2 = S32(0XF0A << 16);
    // 0x80009324: ori         $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 | 0X4000;
    // 0x80009328: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000932C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80009330: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009334: lbu         $v0, 0x79F5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X79F5);
    // 0x80009338: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8000933C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80009340: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80009344: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80009348: bne         $v0, $zero, L_80009354
    if (ctx->r2 != 0) {
        // 0x8000934C: addiu       $s0, $zero, 0x2
        ctx->r16 = ADD32(0, 0X2);
            goto L_80009354;
    }
    // 0x8000934C: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x80009350: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80009354:
    // 0x80009354: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009358: lbu         $v0, 0x7A40($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7A40);
    // 0x8000935C: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80009360: beq         $v0, $zero, L_8000937C
    if (ctx->r2 == 0) {
        // 0x80009364: nop
    
            goto L_8000937C;
    }
    // 0x80009364: nop

    // 0x80009368: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000936C: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80009370: and         $v0, $v0, $s0
    ctx->r2 = ctx->r2 & ctx->r16;
    // 0x80009374: beq         $v0, $zero, L_80009388
    if (ctx->r2 == 0) {
        // 0x80009378: nop
    
            goto L_80009388;
    }
    // 0x80009378: nop

L_8000937C:
    // 0x8000937C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80009380: jal         0x800116CC
    // 0x80009384: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    func_800116CC(rdram, ctx);
        goto after_22;
    // 0x80009384: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    after_22:
L_80009388:
    // 0x80009388: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000938C: lb          $v0, 0x7A3A($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7A3A);
    // 0x80009390: beq         $v0, $zero, L_80009418
    if (ctx->r2 == 0) {
        // 0x80009394: nop
    
            goto L_80009418;
    }
    // 0x80009394: nop

    // 0x80009398: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000939C: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x800093A0: and         $v0, $v0, $s0
    ctx->r2 = ctx->r2 & ctx->r16;
    // 0x800093A4: bne         $v0, $zero, L_80009418
    if (ctx->r2 != 0) {
        // 0x800093A8: nop
    
            goto L_80009418;
    }
    // 0x800093A8: nop

    // 0x800093AC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800093B0: lbu         $v0, 0x7A40($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7A40);
    // 0x800093B4: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800093B8: beq         $v0, $zero, L_800093D4
    if (ctx->r2 == 0) {
        // 0x800093BC: nop
    
            goto L_800093D4;
    }
    // 0x800093BC: nop

    // 0x800093C0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800093C4: jal         0x8001212C
    // 0x800093C8: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    func_8001212C(rdram, ctx);
        goto after_23;
    // 0x800093C8: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    after_23:
    // 0x800093CC: j           L_800093E0
    // 0x800093D0: nop

        goto L_800093E0;
    // 0x800093D0: nop

L_800093D4:
    // 0x800093D4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800093D8: jal         0x800123FC
    // 0x800093DC: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    func_800123FC(rdram, ctx);
        goto after_24;
    // 0x800093DC: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    after_24:
L_800093E0:
    // 0x800093E0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800093E4: lb          $v0, 0x7A39($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7A39);
    // 0x800093E8: beq         $v0, $zero, L_80009418
    if (ctx->r2 == 0) {
        // 0x800093EC: nop
    
            goto L_80009418;
    }
    // 0x800093EC: nop

    // 0x800093F0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800093F4: lbu         $v0, 0x7A59($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7A59);
    // 0x800093F8: beq         $v0, $zero, L_8000940C
    if (ctx->r2 == 0) {
        // 0x800093FC: nop
    
            goto L_8000940C;
    }
    // 0x800093FC: nop

    // 0x80009400: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80009404: jal         0x80011CD8
    // 0x80009408: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    func_80011CD8(rdram, ctx);
        goto after_25;
    // 0x80009408: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    after_25:
L_8000940C:
    // 0x8000940C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80009410: jal         0x80011914
    // 0x80009414: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    func_80011914(rdram, ctx);
        goto after_26;
    // 0x80009414: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    after_26:
L_80009418:
    // 0x80009418: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000941C: addiu       $a0, $a0, 0x25FA
    ctx->r4 = ADD32(ctx->r4, 0X25FA);
    // 0x80009420: lb          $v1, 0x0($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X0);
    // 0x80009424: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80009428: bne         $v1, $v0, L_8000946C
    if (ctx->r3 != ctx->r2) {
        // 0x8000942C: nop
    
            goto L_8000946C;
    }
    // 0x8000942C: nop

    // 0x80009430: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009434: lb          $v0, 0x79F5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F5);
    // 0x80009438: bgez        $v0, L_8000946C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000943C: nop
    
            goto L_8000946C;
    }
    // 0x8000943C: nop

    // 0x80009440: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009444: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80009448: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8000944C: bne         $v0, $zero, L_8000946C
    if (ctx->r2 != 0) {
        // 0x80009450: nop
    
            goto L_8000946C;
    }
    // 0x80009450: nop

    // 0x80009454: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009458: lb          $v0, 0x2602($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2602);
    // 0x8000945C: beq         $v0, $zero, L_8000946C
    if (ctx->r2 == 0) {
        // 0x80009460: nop
    
            goto L_8000946C;
    }
    // 0x80009460: nop

    // 0x80009464: jal         0x80011010
    // 0x80009468: addiu       $a0, $a0, -0x5A
    ctx->r4 = ADD32(ctx->r4, -0X5A);
    func_80011010(rdram, ctx);
        goto after_27;
    // 0x80009468: addiu       $a0, $a0, -0x5A
    ctx->r4 = ADD32(ctx->r4, -0X5A);
    after_27:
L_8000946C:
    // 0x8000946C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80009470: addiu       $a0, $a0, 0x7A4A
    ctx->r4 = ADD32(ctx->r4, 0X7A4A);
    // 0x80009474: lb          $v1, 0x0($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X0);
    // 0x80009478: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8000947C: bne         $v1, $v0, L_800094C0
    if (ctx->r3 != ctx->r2) {
        // 0x80009480: nop
    
            goto L_800094C0;
    }
    // 0x80009480: nop

    // 0x80009484: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009488: lb          $v0, 0x25A5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A5);
    // 0x8000948C: bgez        $v0, L_800094C0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80009490: nop
    
            goto L_800094C0;
    }
    // 0x80009490: nop

    // 0x80009494: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009498: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x8000949C: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800094A0: bne         $v0, $zero, L_800094C0
    if (ctx->r2 != 0) {
        // 0x800094A4: nop
    
            goto L_800094C0;
    }
    // 0x800094A4: nop

    // 0x800094A8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800094AC: lb          $v0, 0x7A52($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7A52);
    // 0x800094B0: beq         $v0, $zero, L_800094C0
    if (ctx->r2 == 0) {
        // 0x800094B4: nop
    
            goto L_800094C0;
    }
    // 0x800094B4: nop

    // 0x800094B8: jal         0x80011010
    // 0x800094BC: addiu       $a0, $a0, -0x5A
    ctx->r4 = ADD32(ctx->r4, -0X5A);
    func_80011010(rdram, ctx);
        goto after_28;
    // 0x800094BC: addiu       $a0, $a0, -0x5A
    ctx->r4 = ADD32(ctx->r4, -0X5A);
    after_28:
L_800094C0:
    // 0x800094C0: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x800094C4: addiu       $s0, $s0, 0x7B8F
    ctx->r16 = ADD32(ctx->r16, 0X7B8F);
    // 0x800094C8: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800094CC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800094D0: beq         $v0, $zero, L_800094E4
    if (ctx->r2 == 0) {
        // 0x800094D4: nop
    
            goto L_800094E4;
    }
    // 0x800094D4: nop

    // 0x800094D8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800094DC: jal         0x80012A44
    // 0x800094E0: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    func_80012A44(rdram, ctx);
        goto after_29;
    // 0x800094E0: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    after_29:
L_800094E4:
    // 0x800094E4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800094E8: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800094EC: beq         $v0, $zero, L_80009500
    if (ctx->r2 == 0) {
        // 0x800094F0: nop
    
            goto L_80009500;
    }
    // 0x800094F0: nop

    // 0x800094F4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800094F8: jal         0x80012A44
    // 0x800094FC: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    func_80012A44(rdram, ctx);
        goto after_30;
    // 0x800094FC: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    after_30:
L_80009500:
    // 0x80009500: jal         0x8001C87C
    // 0x80009504: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    func_8001C87C(rdram, ctx);
        goto after_31;
    // 0x80009504: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    after_31:
L_80009508:
    // 0x80009508: lui         $s5, 0x801D
    ctx->r21 = S32(0X801D << 16);
    // 0x8000950C: addiu       $s5, $s5, 0x6AA0
    ctx->r21 = ADD32(ctx->r21, 0X6AA0);
    // 0x80009510: lui         $s4, 0x801D
    ctx->r20 = S32(0X801D << 16);
    // 0x80009514: addiu       $s4, $s4, 0x3520
    ctx->r20 = ADD32(ctx->r20, 0X3520);
    // 0x80009518: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8000951C:
    // 0x8000951C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80009520: addu        $s2, $s5, $zero
    ctx->r18 = ADD32(ctx->r21, 0);
L_80009524:
    // 0x80009524: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009528: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8000952C: lbu         $v0, 0x6AC8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC8);
    // 0x80009530: beq         $v0, $zero, L_80009554
    if (ctx->r2 == 0) {
        // 0x80009534: nop
    
            goto L_80009554;
    }
    // 0x80009534: nop

    // 0x80009538: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000953C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80009540: lbu         $v0, 0x6ACD($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6ACD);
    // 0x80009544: bne         $v0, $s3, L_80009554
    if (ctx->r2 != ctx->r19) {
        // 0x80009548: nop
    
            goto L_80009554;
    }
    // 0x80009548: nop

    // 0x8000954C: jal         0x80017D38
    // 0x80009550: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80017D38(rdram, ctx);
        goto after_32;
    // 0x80009550: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_32:
L_80009554:
    // 0x80009554: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009558: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8000955C: lbu         $v0, 0x3548($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3548);
    // 0x80009560: beql        $v0, $zero, L_80009588
    if (ctx->r2 == 0) {
        // 0x80009564: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_80009588;
    }
    goto skip_5;
    // 0x80009564: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    skip_5:
    // 0x80009568: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000956C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80009570: lbu         $v0, 0x354D($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X354D);
    // 0x80009574: bnel        $v0, $s3, L_80009588
    if (ctx->r2 != ctx->r19) {
        // 0x80009578: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_80009588;
    }
    goto skip_6;
    // 0x80009578: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    skip_6:
    // 0x8000957C: jal         0x80017D38
    // 0x80009580: addu        $a0, $s0, $s4
    ctx->r4 = ADD32(ctx->r16, ctx->r20);
    func_80017D38(rdram, ctx);
        goto after_33;
    // 0x80009580: addu        $a0, $s0, $s4
    ctx->r4 = ADD32(ctx->r16, ctx->r20);
    after_33:
    // 0x80009584: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
L_80009588:
    // 0x80009588: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000958C: slti        $v0, $s1, 0x23
    ctx->r2 = SIGNED(ctx->r17) < 0X23 ? 1 : 0;
    // 0x80009590: bne         $v0, $zero, L_80009524
    if (ctx->r2 != 0) {
        // 0x80009594: addiu       $s2, $s2, 0x70
        ctx->r18 = ADD32(ctx->r18, 0X70);
            goto L_80009524;
    }
    // 0x80009594: addiu       $s2, $s2, 0x70
    ctx->r18 = ADD32(ctx->r18, 0X70);
    // 0x80009598: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8000959C: slti        $v0, $s3, 0x3
    ctx->r2 = SIGNED(ctx->r19) < 0X3 ? 1 : 0;
    // 0x800095A0: bnel        $v0, $zero, L_8000951C
    if (ctx->r2 != 0) {
        // 0x800095A4: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8000951C;
    }
    goto skip_7;
    // 0x800095A4: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    skip_7:
    // 0x800095A8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800095AC: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x800095B0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800095B4: bne         $v0, $zero, L_800095D8
    if (ctx->r2 != 0) {
        // 0x800095B8: nop
    
            goto L_800095D8;
    }
    // 0x800095B8: nop

    // 0x800095BC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x800095C0: addiu       $a0, $a0, -0x66CD
    ctx->r4 = ADD32(ctx->r4, -0X66CD);
    // 0x800095C4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800095C8: beq         $v0, $zero, L_800095D8
    if (ctx->r2 == 0) {
        // 0x800095CC: nop
    
            goto L_800095D8;
    }
    // 0x800095CC: nop

    // 0x800095D0: jal         0x80017D38
    // 0x800095D4: addiu       $a0, $a0, -0x2B
    ctx->r4 = ADD32(ctx->r4, -0X2B);
    func_80017D38(rdram, ctx);
        goto after_34;
    // 0x800095D4: addiu       $a0, $a0, -0x2B
    ctx->r4 = ADD32(ctx->r4, -0X2B);
    after_34:
L_800095D8:
    // 0x800095D8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800095DC: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x800095E0: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800095E4: bne         $v0, $zero, L_80009608
    if (ctx->r2 != 0) {
        // 0x800095E8: nop
    
            goto L_80009608;
    }
    // 0x800095E8: nop

    // 0x800095EC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x800095F0: addiu       $a0, $a0, -0x665D
    ctx->r4 = ADD32(ctx->r4, -0X665D);
    // 0x800095F4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800095F8: beq         $v0, $zero, L_80009608
    if (ctx->r2 == 0) {
        // 0x800095FC: nop
    
            goto L_80009608;
    }
    // 0x800095FC: nop

    // 0x80009600: jal         0x80017D38
    // 0x80009604: addiu       $a0, $a0, -0x2B
    ctx->r4 = ADD32(ctx->r4, -0X2B);
    func_80017D38(rdram, ctx);
        goto after_35;
    // 0x80009604: addiu       $a0, $a0, -0x2B
    ctx->r4 = ADD32(ctx->r4, -0X2B);
    after_35:
L_80009608:
    // 0x80009608: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000960C: lb          $v1, 0x25FA($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X25FA);
    // 0x80009610: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80009614: bne         $v1, $v0, L_8000962C
    if (ctx->r3 != ctx->r2) {
        // 0x80009618: nop
    
            goto L_8000962C;
    }
    // 0x80009618: nop

    // 0x8000961C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009620: lb          $v0, 0x7A4A($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7A4A);
    // 0x80009624: beq         $v0, $v1, L_80009634
    if (ctx->r2 == ctx->r3) {
        // 0x80009628: nop
    
            goto L_80009634;
    }
    // 0x80009628: nop

L_8000962C:
    // 0x8000962C: jal         0x80010014
    // 0x80009630: nop

    func_80010014(rdram, ctx);
        goto after_36;
    // 0x80009630: nop

    after_36:
L_80009634:
    // 0x80009634: jal         0x80051D6C
    // 0x80009638: nop

    func_80051D6C(rdram, ctx);
        goto after_37;
    // 0x80009638: nop

    after_37:
    // 0x8000963C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80009640: lb          $v1, 0x25FA($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X25FA);
    // 0x80009644: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80009648: bne         $v1, $v0, L_80009660
    if (ctx->r3 != ctx->r2) {
        // 0x8000964C: nop
    
            goto L_80009660;
    }
    // 0x8000964C: nop

    // 0x80009650: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009654: lb          $v0, 0x7A4A($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7A4A);
    // 0x80009658: beq         $v0, $v1, L_80009670
    if (ctx->r2 == ctx->r3) {
        // 0x8000965C: nop
    
            goto L_80009670;
    }
    // 0x8000965C: nop

L_80009660:
    // 0x80009660: jal         0x80010D10
    // 0x80009664: nop

    func_80010D10(rdram, ctx);
        goto after_38;
    // 0x80009664: nop

    after_38:
    // 0x80009668: j           L_80009678
    // 0x8000966C: nop

        goto L_80009678;
    // 0x8000966C: nop

L_80009670:
    // 0x80009670: jal         0x80010FE4
    // 0x80009674: nop

    func_80010FE4(rdram, ctx);
        goto after_39;
    // 0x80009674: nop

    after_39:
L_80009678:
    // 0x80009678: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x8000967C: addiu       $s1, $s1, 0x7B8F
    ctx->r17 = ADD32(ctx->r17, 0X7B8F);
    // 0x80009680: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80009684: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80009688: bne         $v0, $zero, L_800096B0
    if (ctx->r2 != 0) {
        // 0x8000968C: nop
    
            goto L_800096B0;
    }
    // 0x8000968C: nop

    // 0x80009690: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80009694: addiu       $s0, $s0, 0x25A0
    ctx->r16 = ADD32(ctx->r16, 0X25A0);
    // 0x80009698: jal         0x80015540
    // 0x8000969C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80015540(rdram, ctx);
        goto after_40;
    // 0x8000969C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_40:
    // 0x800096A0: jal         0x80015C90
    // 0x800096A4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80015C90(rdram, ctx);
        goto after_41;
    // 0x800096A4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_41:
    // 0x800096A8: jal         0x800158AC
    // 0x800096AC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800158AC(rdram, ctx);
        goto after_42;
    // 0x800096AC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_42:
L_800096B0:
    // 0x800096B0: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x800096B4: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800096B8: bne         $v0, $zero, L_800096E4
    if (ctx->r2 != 0) {
        // 0x800096BC: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800096E4;
    }
    // 0x800096BC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800096C0: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x800096C4: addiu       $s0, $s0, 0x79F0
    ctx->r16 = ADD32(ctx->r16, 0X79F0);
    // 0x800096C8: jal         0x80015540
    // 0x800096CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80015540(rdram, ctx);
        goto after_43;
    // 0x800096CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_43:
    // 0x800096D0: jal         0x80015C90
    // 0x800096D4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80015C90(rdram, ctx);
        goto after_44;
    // 0x800096D4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_44:
    // 0x800096D8: jal         0x800158AC
    // 0x800096DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800158AC(rdram, ctx);
        goto after_45;
    // 0x800096DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_45:
    // 0x800096E0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_800096E4:
    // 0x800096E4: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x800096E8: lui         $s4, 0x801D
    ctx->r20 = S32(0X801D << 16);
    // 0x800096EC: addiu       $s4, $s4, 0x3520
    ctx->r20 = ADD32(ctx->r20, 0X3520);
    // 0x800096F0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800096F4: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x800096F8: addiu       $s2, $s2, 0x6AA0
    ctx->r18 = ADD32(ctx->r18, 0X6AA0);
L_800096FC:
    // 0x800096FC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009700: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80009704: lbu         $v0, 0x6AC8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC8);
    // 0x80009708: beq         $v0, $zero, L_8000972C
    if (ctx->r2 == 0) {
        // 0x8000970C: nop
    
            goto L_8000972C;
    }
    // 0x8000970C: nop

    // 0x80009710: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009714: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80009718: lbu         $v0, 0x6ACD($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6ACD);
    // 0x8000971C: bne         $v0, $s3, L_8000972C
    if (ctx->r2 != ctx->r19) {
        // 0x80009720: nop
    
            goto L_8000972C;
    }
    // 0x80009720: nop

    // 0x80009724: jal         0x80017D38
    // 0x80009728: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80017D38(rdram, ctx);
        goto after_46;
    // 0x80009728: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_46:
L_8000972C:
    // 0x8000972C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009730: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80009734: lbu         $v0, 0x3548($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3548);
    // 0x80009738: beql        $v0, $zero, L_80009760
    if (ctx->r2 == 0) {
        // 0x8000973C: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_80009760;
    }
    goto skip_8;
    // 0x8000973C: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    skip_8:
    // 0x80009740: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009744: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80009748: lbu         $v0, 0x354D($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X354D);
    // 0x8000974C: bnel        $v0, $s3, L_80009760
    if (ctx->r2 != ctx->r19) {
        // 0x80009750: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_80009760;
    }
    goto skip_9;
    // 0x80009750: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    skip_9:
    // 0x80009754: jal         0x80017D38
    // 0x80009758: addu        $a0, $s0, $s4
    ctx->r4 = ADD32(ctx->r16, ctx->r20);
    func_80017D38(rdram, ctx);
        goto after_47;
    // 0x80009758: addu        $a0, $s0, $s4
    ctx->r4 = ADD32(ctx->r16, ctx->r20);
    after_47:
    // 0x8000975C: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
L_80009760:
    // 0x80009760: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80009764: slti        $v0, $s1, 0x23
    ctx->r2 = SIGNED(ctx->r17) < 0X23 ? 1 : 0;
    // 0x80009768: bne         $v0, $zero, L_800096FC
    if (ctx->r2 != 0) {
        // 0x8000976C: addiu       $s2, $s2, 0x70
        ctx->r18 = ADD32(ctx->r18, 0X70);
            goto L_800096FC;
    }
    // 0x8000976C: addiu       $s2, $s2, 0x70
    ctx->r18 = ADD32(ctx->r18, 0X70);
    // 0x80009770: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009774: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x80009778: bne         $v0, $zero, L_800097CC
    if (ctx->r2 != 0) {
        // 0x8000977C: nop
    
            goto L_800097CC;
    }
    // 0x8000977C: nop

    // 0x80009780: jal         0x800115BC
    // 0x80009784: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    func_800115BC(rdram, ctx);
        goto after_48;
    // 0x80009784: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    after_48:
    // 0x80009788: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x8000978C: addiu       $s2, $s2, 0x7BD0
    ctx->r18 = ADD32(ctx->r18, 0X7BD0);
    // 0x80009790: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80009794:
    // 0x80009794: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009798: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8000979C: lb          $v0, 0x7BD0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7BD0);
    // 0x800097A0: beql        $v0, $zero, L_800097B4
    if (ctx->r2 == 0) {
        // 0x800097A4: addiu       $s2, $s2, 0x68
        ctx->r18 = ADD32(ctx->r18, 0X68);
            goto L_800097B4;
    }
    goto skip_10;
    // 0x800097A4: addiu       $s2, $s2, 0x68
    ctx->r18 = ADD32(ctx->r18, 0X68);
    skip_10:
    // 0x800097A8: jal         0x80027820
    // 0x800097AC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80027820(rdram, ctx);
        goto after_49;
    // 0x800097AC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_49:
    // 0x800097B0: addiu       $s2, $s2, 0x68
    ctx->r18 = ADD32(ctx->r18, 0X68);
L_800097B4:
    // 0x800097B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800097B8: slti        $v0, $s1, 0x18
    ctx->r2 = SIGNED(ctx->r17) < 0X18 ? 1 : 0;
    // 0x800097BC: bne         $v0, $zero, L_80009794
    if (ctx->r2 != 0) {
        // 0x800097C0: addiu       $s0, $s0, 0x68
        ctx->r16 = ADD32(ctx->r16, 0X68);
            goto L_80009794;
    }
    // 0x800097C0: addiu       $s0, $s0, 0x68
    ctx->r16 = ADD32(ctx->r16, 0X68);
    // 0x800097C4: jal         0x8002F878
    // 0x800097C8: nop

    func_8002F878(rdram, ctx);
        goto after_50;
    // 0x800097C8: nop

    after_50:
L_800097CC:
    // 0x800097CC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800097D0: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x800097D4: lui         $a0, 0x600
    ctx->r4 = S32(0X600 << 16);
    // 0x800097D8: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x800097DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800097E0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800097E4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800097E8: addiu       $v0, $v0, -0x6850
    ctx->r2 = ADD32(ctx->r2, -0X6850);
    // 0x800097EC: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x800097F0: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x800097F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800097F8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800097FC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80009800: addiu       $v0, $v0, -0x6858
    ctx->r2 = ADD32(ctx->r2, -0X6858);
    // 0x80009804: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80009808: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // 0x8000980C: jal         0x8002DC24
    // 0x80009810: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    func_8002DC24(rdram, ctx);
        goto after_51;
    // 0x80009810: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    after_51:
    // 0x80009814: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009818: lbu         $v0, 0x7B9C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9C);
    // 0x8000981C: beq         $v0, $zero, L_8000983C
    if (ctx->r2 == 0) {
        // 0x80009820: nop
    
            goto L_8000983C;
    }
    // 0x80009820: nop

    // 0x80009824: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009828: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x8000982C: bne         $v0, $zero, L_8000983C
    if (ctx->r2 != 0) {
        // 0x80009830: nop
    
            goto L_8000983C;
    }
    // 0x80009830: nop

    // 0x80009834: jal         0x800533F0
    // 0x80009838: nop

    func_800533F0(rdram, ctx);
        goto after_52;
    // 0x80009838: nop

    after_52:
L_8000983C:
    // 0x8000983C: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80009840: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80009844: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80009848: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8000984C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80009850: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80009854: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80009858: jr          $ra
    // 0x8000985C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000985C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80009860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009860: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80009864: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x80009868: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8000986C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80009870: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009874: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x80009878: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x8000987C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009880: sb          $v0, 0x7A56($at)
    MEM_B(0X7A56, ctx->r1) = ctx->r2;
    // 0x80009884: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009888: sb          $v0, 0x2606($at)
    MEM_B(0X2606, ctx->r1) = ctx->r2;
    // 0x8000988C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80009890: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80009894: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80009898: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8000989C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800098A0: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800098A4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800098A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800098AC: sb          $zero, 0x7B97($at)
    MEM_B(0X7B97, ctx->r1) = 0;
    // 0x800098B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800098B4: sb          $zero, 0x7A68($at)
    MEM_B(0X7A68, ctx->r1) = 0;
    // 0x800098B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800098BC: beq         $v1, $v0, L_80009934
    if (ctx->r3 == ctx->r2) {
        // 0x800098C0: sb          $zero, 0x2618($at)
        MEM_B(0X2618, ctx->r1) = 0;
            goto L_80009934;
    }
    // 0x800098C0: sb          $zero, 0x2618($at)
    MEM_B(0X2618, ctx->r1) = 0;
    // 0x800098C4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800098C8: lbu         $v0, 0x7B9C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9C);
    // 0x800098CC: bne         $v0, $zero, L_80009934
    if (ctx->r2 != 0) {
        // 0x800098D0: nop
    
            goto L_80009934;
    }
    // 0x800098D0: nop

    // 0x800098D4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800098D8: lhu         $v0, -0x3260($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3260);
    // 0x800098DC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800098E0: lhu         $v1, -0x325A($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X325A);
    // 0x800098E4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800098E8: lhu         $a0, -0x325E($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X325E);
    // 0x800098EC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800098F0: lhu         $a1, -0x3258($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X3258);
    // 0x800098F4: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x800098F8: lhu         $a2, -0x325C($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X325C);
    // 0x800098FC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80009900: lhu         $a3, -0x3256($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X3256);
    // 0x80009904: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009908: sh          $v0, 0x2620($at)
    MEM_H(0X2620, ctx->r1) = ctx->r2;
    // 0x8000990C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009910: sh          $v1, 0x7A70($at)
    MEM_H(0X7A70, ctx->r1) = ctx->r3;
    // 0x80009914: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009918: sh          $a0, 0x2622($at)
    MEM_H(0X2622, ctx->r1) = ctx->r4;
    // 0x8000991C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009920: sh          $a1, 0x7A72($at)
    MEM_H(0X7A72, ctx->r1) = ctx->r5;
    // 0x80009924: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009928: sh          $a2, 0x2624($at)
    MEM_H(0X2624, ctx->r1) = ctx->r6;
    // 0x8000992C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009930: sh          $a3, 0x7A74($at)
    MEM_H(0X7A74, ctx->r1) = ctx->r7;
L_80009934:
    // 0x80009934: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009938: jal         0x8000BFD8
    // 0x8000993C: sb          $zero, 0x5585($at)
    MEM_B(0X5585, ctx->r1) = 0;
    func_8000BFD8(rdram, ctx);
        goto after_0;
    // 0x8000993C: sb          $zero, 0x5585($at)
    MEM_B(0X5585, ctx->r1) = 0;
    after_0:
    // 0x80009940: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009944: lbu         $v0, 0x2074($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2074);
    // 0x80009948: beq         $v0, $zero, L_8000997C
    if (ctx->r2 == 0) {
        // 0x8000994C: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_8000997C;
    }
    // 0x8000994C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80009950: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80009954: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x80009958: beq         $v1, $v0, L_80009974
    if (ctx->r3 == ctx->r2) {
        // 0x8000995C: addiu       $a0, $zero, 0xF
        ctx->r4 = ADD32(0, 0XF);
            goto L_80009974;
    }
    // 0x8000995C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80009960: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009964: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x80009968: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8000996C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80009970: lb          $a0, -0x4040($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X4040);
L_80009974:
    // 0x80009974: jal         0x800067C8
    // 0x80009978: nop

    func_800067C8(rdram, ctx);
        goto after_1;
    // 0x80009978: nop

    after_1:
L_8000997C:
    // 0x8000997C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80009980: addiu       $v1, $v1, 0x7B84
    ctx->r3 = ADD32(ctx->r3, 0X7B84);
    // 0x80009984: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80009988: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000998C: sw          $zero, 0x7BB4($at)
    MEM_W(0X7BB4, ctx->r1) = 0;
    // 0x80009990: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80009994: jal         0x8000BB3C
    // 0x80009998: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    func_8000BB3C(rdram, ctx);
        goto after_2;
    // 0x80009998: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    after_2:
    // 0x8000999C: jal         0x8001C1F0
    // 0x800099A0: nop

    func_8001C1F0(rdram, ctx);
        goto after_3;
    // 0x800099A0: nop

    after_3:
    // 0x800099A4: jal         0x80051C30
    // 0x800099A8: nop

    func_80051C30(rdram, ctx);
        goto after_4;
    // 0x800099A8: nop

    after_4:
    // 0x800099AC: jal         0x8002EA40
    // 0x800099B0: nop

    func_8002EA40(rdram, ctx);
        goto after_5;
    // 0x800099B0: nop

    after_5:
    // 0x800099B4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800099B8: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x800099BC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800099C0: bne         $v1, $v0, L_80009A0C
    if (ctx->r3 != ctx->r2) {
        // 0x800099C4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80009A0C;
    }
    // 0x800099C4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800099C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800099CC: jal         0x8001C36C
    // 0x800099D0: sb          $zero, 0x7B87($at)
    MEM_B(0X7B87, ctx->r1) = 0;
    func_8001C36C(rdram, ctx);
        goto after_6;
    // 0x800099D0: sb          $zero, 0x7B87($at)
    MEM_B(0X7B87, ctx->r1) = 0;
    after_6:
    // 0x800099D4: jal         0x8001F45C
    // 0x800099D8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8001F45C(rdram, ctx);
        goto after_7;
    // 0x800099D8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_7:
    // 0x800099DC: jal         0x8001F45C
    // 0x800099E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001F45C(rdram, ctx);
        goto after_8;
    // 0x800099E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x800099E4: jal         0x8001F45C
    // 0x800099E8: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    func_8001F45C(rdram, ctx);
        goto after_9;
    // 0x800099E8: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    after_9:
    // 0x800099EC: jal         0x8001F45C
    // 0x800099F0: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    func_8001F45C(rdram, ctx);
        goto after_10;
    // 0x800099F0: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    after_10:
    // 0x800099F4: jal         0x80053390
    // 0x800099F8: nop

    func_80053390(rdram, ctx);
        goto after_11;
    // 0x800099F8: nop

    after_11:
    // 0x800099FC: jal         0x80031BEC
    // 0x80009A00: nop

    func_80031BEC(rdram, ctx);
        goto after_12;
    // 0x80009A00: nop

    after_12:
    // 0x80009A04: j           L_80009A28
    // 0x80009A08: nop

        goto L_80009A28;
    // 0x80009A08: nop

L_80009A0C:
    // 0x80009A0C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009A10: jal         0x8001CFB4
    // 0x80009A14: sb          $v0, 0x7B87($at)
    MEM_B(0X7B87, ctx->r1) = ctx->r2;
    func_8001CFB4(rdram, ctx);
        goto after_13;
    // 0x80009A14: sb          $v0, 0x7B87($at)
    MEM_B(0X7B87, ctx->r1) = ctx->r2;
    after_13:
    // 0x80009A18: jal         0x80031BEC
    // 0x80009A1C: nop

    func_80031BEC(rdram, ctx);
        goto after_14;
    // 0x80009A1C: nop

    after_14:
    // 0x80009A20: jal         0x800330AC
    // 0x80009A24: nop

    func_800330AC(rdram, ctx);
        goto after_15;
    // 0x80009A24: nop

    after_15:
L_80009A28:
    // 0x80009A28: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009A2C: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x80009A30: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80009A34: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80009A38: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80009A3C: lw          $s0, -0x46D0($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X46D0);
    // 0x80009A40: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x80009A44: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80009A48: beq         $v1, $v0, L_80009AA0
    if (ctx->r3 == ctx->r2) {
        // 0x80009A4C: lbu         $a0, 0x0($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X0);
            goto L_80009AA0;
    }
    // 0x80009A4C: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x80009A50: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x80009A54: addiu       $s4, $s4, -0x662C
    ctx->r20 = ADD32(ctx->r20, -0X662C);
    // 0x80009A58: lui         $s3, 0x13
    ctx->r19 = S32(0X13 << 16);
    // 0x80009A5C: addiu       $s3, $s3, 0x440
    ctx->r19 = ADD32(ctx->r19, 0X440);
    // 0x80009A60: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80009A64: lui         $s1, 0x8015
    ctx->r17 = S32(0X8015 << 16);
    // 0x80009A68: addiu       $s1, $s1, -0x9E0
    ctx->r17 = ADD32(ctx->r17, -0X9E0);
L_80009A6C:
    // 0x80009A6C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80009A70: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
    // 0x80009A74: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x80009A78: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80009A7C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80009A80: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80009A84: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80009A88: jal         0x80006D98
    // 0x80009A8C: addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    func_80006D98(rdram, ctx);
        goto after_16;
    // 0x80009A8C: addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    after_16:
    // 0x80009A90: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x80009A94: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x80009A98: bne         $v0, $s2, L_80009A6C
    if (ctx->r2 != ctx->r18) {
        // 0x80009A9C: addiu       $s1, $s1, 0x80
        ctx->r17 = ADD32(ctx->r17, 0X80);
            goto L_80009A6C;
    }
    // 0x80009A9C: addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
L_80009AA0:
    // 0x80009AA0: lui         $s0, 0x13
    ctx->r16 = S32(0X13 << 16);
    // 0x80009AA4: addiu       $s0, $s0, 0x1020
    ctx->r16 = ADD32(ctx->r16, 0X1020);
    // 0x80009AA8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80009AAC: lui         $s1, 0x8015
    ctx->r17 = S32(0X8015 << 16);
    // 0x80009AB0: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x80009AB4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80009AB8: jal         0x80006D98
    // 0x80009ABC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80006D98(rdram, ctx);
        goto after_17;
    // 0x80009ABC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_17:
    // 0x80009AC0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80009AC4: lbu         $a0, 0x7B86($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B86);
    // 0x80009AC8: addiu       $a1, $s1, 0x20
    ctx->r5 = ADD32(ctx->r17, 0X20);
    // 0x80009ACC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80009AD0: addiu       $s0, $s0, -0xE0
    ctx->r16 = ADD32(ctx->r16, -0XE0);
    // 0x80009AD4: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x80009AD8: jal         0x80006D98
    // 0x80009ADC: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    func_80006D98(rdram, ctx);
        goto after_18;
    // 0x80009ADC: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    after_18:
    // 0x80009AE0: lui         $s0, 0x13
    ctx->r16 = S32(0X13 << 16);
    // 0x80009AE4: addiu       $s0, $s0, 0x1040
    ctx->r16 = ADD32(ctx->r16, 0X1040);
    // 0x80009AE8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80009AEC: addiu       $a1, $s1, 0x40
    ctx->r5 = ADD32(ctx->r17, 0X40);
    // 0x80009AF0: jal         0x80006D98
    // 0x80009AF4: addiu       $a2, $zero, 0x1E0
    ctx->r6 = ADD32(0, 0X1E0);
    func_80006D98(rdram, ctx);
        goto after_19;
    // 0x80009AF4: addiu       $a2, $zero, 0x1E0
    ctx->r6 = ADD32(0, 0X1E0);
    after_19:
    // 0x80009AF8: addiu       $a0, $s0, 0x1E0
    ctx->r4 = ADD32(ctx->r16, 0X1E0);
    // 0x80009AFC: addiu       $a1, $s1, 0x220
    ctx->r5 = ADD32(ctx->r17, 0X220);
    // 0x80009B00: jal         0x80006D98
    // 0x80009B04: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80006D98(rdram, ctx);
        goto after_20;
    // 0x80009B04: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_20:
    // 0x80009B08: jal         0x8001F45C
    // 0x80009B0C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_8001F45C(rdram, ctx);
        goto after_21;
    // 0x80009B0C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_21:
    // 0x80009B10: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80009B14: lb          $v1, 0x25FA($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X25FA);
    // 0x80009B18: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80009B1C: bne         $v1, $v0, L_80009B34
    if (ctx->r3 != ctx->r2) {
        // 0x80009B20: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_80009B34;
    }
    // 0x80009B20: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80009B24: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009B28: lb          $v0, 0x7A4A($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7A4A);
    // 0x80009B2C: beq         $v0, $v1, L_80009BAC
    if (ctx->r2 == ctx->r3) {
        // 0x80009B30: nop
    
            goto L_80009BAC;
    }
    // 0x80009B30: nop

L_80009B34:
    // 0x80009B34: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x80009B38: addiu       $s4, $s4, -0x45B0
    ctx->r20 = ADD32(ctx->r20, -0X45B0);
    // 0x80009B3C: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x80009B40: addiu       $s1, $s1, 0x53C0
    ctx->r17 = ADD32(ctx->r17, 0X53C0);
    // 0x80009B44: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_80009B48:
    // 0x80009B48: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80009B4C: addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    // 0x80009B50: lb          $a0, -0xE74($a0)
    ctx->r4 = MEM_B(ctx->r4, -0XE74);
    // 0x80009B54: sll         $s0, $a0, 1
    ctx->r16 = S32(ctx->r4 << 1);
    // 0x80009B58: addu        $s0, $s0, $a0
    ctx->r16 = ADD32(ctx->r16, ctx->r4);
    // 0x80009B5C: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x80009B60: jal         0x8001F45C
    // 0x80009B64: addu        $s0, $s0, $s4
    ctx->r16 = ADD32(ctx->r16, ctx->r20);
    func_8001F45C(rdram, ctx);
        goto after_22;
    // 0x80009B64: addu        $s0, $s0, $s4
    ctx->r16 = ADD32(ctx->r16, ctx->r20);
    after_22:
    // 0x80009B68: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80009B6C: addu        $a1, $a1, $s3
    ctx->r5 = ADD32(ctx->r5, ctx->r19);
    // 0x80009B70: lb          $a1, -0xE73($a1)
    ctx->r5 = MEM_B(ctx->r5, -0XE73);
    // 0x80009B74: jal         0x800177F4
    // 0x80009B78: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800177F4(rdram, ctx);
        goto after_23;
    // 0x80009B78: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_23:
    // 0x80009B7C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80009B80: jal         0x80066D30
    // 0x80009B84: sb          $zero, 0x2A($s1)
    MEM_B(0X2A, ctx->r17) = 0;
    func_80066D30(rdram, ctx);
        goto after_24;
    // 0x80009B84: sb          $zero, 0x2A($s1)
    MEM_B(0X2A, ctx->r17) = 0;
    after_24:
    // 0x80009B88: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80009B8C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80009B90: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x80009B94: sw          $v0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r2;
    // 0x80009B98: slti        $v0, $s2, 0x4
    ctx->r2 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x80009B9C: bne         $v0, $zero, L_80009B48
    if (ctx->r2 != 0) {
        // 0x80009BA0: addiu       $s1, $s1, 0x70
        ctx->r17 = ADD32(ctx->r17, 0X70);
            goto L_80009B48;
    }
    // 0x80009BA0: addiu       $s1, $s1, 0x70
    ctx->r17 = ADD32(ctx->r17, 0X70);
    // 0x80009BA4: j           L_80009C18
    // 0x80009BA8: nop

        goto L_80009C18;
    // 0x80009BA8: nop

L_80009BAC:
    // 0x80009BAC: jal         0x8001F45C
    // 0x80009BB0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    func_8001F45C(rdram, ctx);
        goto after_25;
    // 0x80009BB0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_25:
    // 0x80009BB4: jal         0x8001F45C
    // 0x80009BB8: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    func_8001F45C(rdram, ctx);
        goto after_26;
    // 0x80009BB8: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_26:
    // 0x80009BBC: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80009BC0: addiu       $s1, $s1, 0xD60
    ctx->r17 = ADD32(ctx->r17, 0XD60);
    // 0x80009BC4: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80009BC8: addiu       $s0, $s0, 0x53C0
    ctx->r16 = ADD32(ctx->r16, 0X53C0);
L_80009BCC:
    // 0x80009BCC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80009BD0: jal         0x800177F4
    // 0x80009BD4: addiu       $a1, $s2, 0x11
    ctx->r5 = ADD32(ctx->r18, 0X11);
    func_800177F4(rdram, ctx);
        goto after_27;
    // 0x80009BD4: addiu       $a1, $s2, 0x11
    ctx->r5 = ADD32(ctx->r18, 0X11);
    after_27:
    // 0x80009BD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80009BDC: jal         0x80066D30
    // 0x80009BE0: sb          $zero, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = 0;
    func_80066D30(rdram, ctx);
        goto after_28;
    // 0x80009BE0: sb          $zero, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = 0;
    after_28:
    // 0x80009BE4: sw          $s1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r17;
    // 0x80009BE8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80009BEC: slti        $v0, $s2, 0x2
    ctx->r2 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x80009BF0: bne         $v0, $zero, L_80009BCC
    if (ctx->r2 != 0) {
        // 0x80009BF4: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_80009BCC;
    }
    // 0x80009BF4: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x80009BF8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009BFC: sb          $zero, 0x2604($at)
    MEM_B(0X2604, ctx->r1) = 0;
    // 0x80009C00: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009C04: sb          $zero, 0x2605($at)
    MEM_B(0X2605, ctx->r1) = 0;
    // 0x80009C08: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009C0C: sb          $zero, 0x7A54($at)
    MEM_B(0X7A54, ctx->r1) = 0;
    // 0x80009C10: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009C14: sb          $zero, 0x7A55($at)
    MEM_B(0X7A55, ctx->r1) = 0;
L_80009C18:
    // 0x80009C18: jal         0x8001F45C
    // 0x80009C1C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_8001F45C(rdram, ctx);
        goto after_29;
    // 0x80009C1C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_29:
    // 0x80009C20: jal         0x8001F45C
    // 0x80009C24: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_8001F45C(rdram, ctx);
        goto after_30;
    // 0x80009C24: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_30:
    // 0x80009C28: jal         0x8001F45C
    // 0x80009C2C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_8001F45C(rdram, ctx);
        goto after_31;
    // 0x80009C2C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_31:
    // 0x80009C30: jal         0x8001F45C
    // 0x80009C34: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_8001F45C(rdram, ctx);
        goto after_32;
    // 0x80009C34: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_32:
    // 0x80009C38: jal         0x8001F45C
    // 0x80009C3C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_8001F45C(rdram, ctx);
        goto after_33;
    // 0x80009C3C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_33:
    // 0x80009C40: addiu       $s2, $zero, 0x15
    ctx->r18 = ADD32(0, 0X15);
L_80009C44:
    // 0x80009C44: jal         0x8001F45C
    // 0x80009C48: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001F45C(rdram, ctx);
        goto after_34;
    // 0x80009C48: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_34:
    // 0x80009C4C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80009C50: slti        $v0, $s2, 0x21
    ctx->r2 = SIGNED(ctx->r18) < 0X21 ? 1 : 0;
    // 0x80009C54: bne         $v0, $zero, L_80009C44
    if (ctx->r2 != 0) {
        // 0x80009C58: nop
    
            goto L_80009C44;
    }
    // 0x80009C58: nop

    // 0x80009C5C: addiu       $s2, $zero, 0x23
    ctx->r18 = ADD32(0, 0X23);
L_80009C60:
    // 0x80009C60: jal         0x8001F45C
    // 0x80009C64: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001F45C(rdram, ctx);
        goto after_35;
    // 0x80009C64: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_35:
    // 0x80009C68: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80009C6C: slti        $v0, $s2, 0x33
    ctx->r2 = SIGNED(ctx->r18) < 0X33 ? 1 : 0;
    // 0x80009C70: bne         $v0, $zero, L_80009C60
    if (ctx->r2 != 0) {
        // 0x80009C74: nop
    
            goto L_80009C60;
    }
    // 0x80009C74: nop

    // 0x80009C78: jal         0x8001F45C
    // 0x80009C7C: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    func_8001F45C(rdram, ctx);
        goto after_36;
    // 0x80009C7C: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_36:
    // 0x80009C80: jal         0x8001F45C
    // 0x80009C84: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    func_8001F45C(rdram, ctx);
        goto after_37;
    // 0x80009C84: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    after_37:
    // 0x80009C88: addiu       $s2, $zero, 0x35
    ctx->r18 = ADD32(0, 0X35);
L_80009C8C:
    // 0x80009C8C: jal         0x8001F45C
    // 0x80009C90: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001F45C(rdram, ctx);
        goto after_38;
    // 0x80009C90: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_38:
    // 0x80009C94: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80009C98: slti        $v0, $s2, 0x3A
    ctx->r2 = SIGNED(ctx->r18) < 0X3A ? 1 : 0;
    // 0x80009C9C: bne         $v0, $zero, L_80009C8C
    if (ctx->r2 != 0) {
        // 0x80009CA0: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_80009C8C;
    }
    // 0x80009CA0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80009CA4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80009CA8: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x80009CAC: beq         $v1, $v0, L_80009DA0
    if (ctx->r3 == ctx->r2) {
        // 0x80009CB0: addiu       $a2, $zero, 0x400
        ctx->r6 = ADD32(0, 0X400);
            goto L_80009DA0;
    }
    // 0x80009CB0: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // 0x80009CB4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009CB8: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x80009CBC: srl         $s2, $v0, 4
    ctx->r18 = S32(U32(ctx->r2) >> 4);
    // 0x80009CC0: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x80009CC4: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80009CC8: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80009CCC: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80009CD0: lbu         $s2, -0x38CC($s2)
    ctx->r18 = MEM_BU(ctx->r18, -0X38CC);
    // 0x80009CD4: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x80009CD8: addiu       $s0, $s0, 0x1C40
    ctx->r16 = ADD32(ctx->r16, 0X1C40);
    // 0x80009CDC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80009CE0: sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18 << 2);
    // 0x80009CE4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80009CE8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80009CEC: lw          $a0, -0x6740($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6740);
    // 0x80009CF0: lui         $s1, 0x12
    ctx->r17 = S32(0X12 << 16);
    // 0x80009CF4: addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
    // 0x80009CF8: jal         0x80006D98
    // 0x80009CFC: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    func_80006D98(rdram, ctx);
        goto after_39;
    // 0x80009CFC: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_39:
    // 0x80009D00: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009D04: lbu         $v0, 0x7B8B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8B);
    // 0x80009D08: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80009D0C: andi        $s2, $v0, 0xF
    ctx->r18 = ctx->r2 & 0XF;
    // 0x80009D10: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x80009D14: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80009D18: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80009D1C: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80009D20: lbu         $s2, -0x38CC($s2)
    ctx->r18 = MEM_BU(ctx->r18, -0X38CC);
    // 0x80009D24: addiu       $s3, $zero, 0x2C
    ctx->r19 = ADD32(0, 0X2C);
    // 0x80009D28: addiu       $a1, $s0, 0x400
    ctx->r5 = ADD32(ctx->r16, 0X400);
    // 0x80009D2C: sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18 << 2);
    // 0x80009D30: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80009D34: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80009D38: lw          $a0, -0x6740($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6740);
    // 0x80009D3C: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // 0x80009D40: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80009D44: jal         0x80006D98
    // 0x80009D48: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    func_80006D98(rdram, ctx);
        goto after_40;
    // 0x80009D48: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_40:
    // 0x80009D4C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80009D50: lbu         $a0, 0x7B86($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B86);
    // 0x80009D54: addiu       $a1, $s0, 0x800
    ctx->r5 = ADD32(ctx->r16, 0X800);
    // 0x80009D58: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80009D5C: lui         $v0, 0x13
    ctx->r2 = S32(0X13 << 16);
    // 0x80009D60: addiu       $v0, $v0, -0x380
    ctx->r2 = ADD32(ctx->r2, -0X380);
    // 0x80009D64: addiu       $a0, $a0, 0x1A
    ctx->r4 = ADD32(ctx->r4, 0X1A);
    // 0x80009D68: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x80009D6C: jal         0x80006D98
    // 0x80009D70: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    func_80006D98(rdram, ctx);
        goto after_41;
    // 0x80009D70: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_41:
L_80009D74:
    // 0x80009D74: jal         0x8001D520
    // 0x80009D78: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001D520(rdram, ctx);
        goto after_42;
    // 0x80009D78: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_42:
    // 0x80009D7C: beql        $v0, $zero, L_80009D94
    if (ctx->r2 == 0) {
        // 0x80009D80: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80009D94;
    }
    goto skip_0;
    // 0x80009D80: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80009D84: sb          $s4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r20;
    // 0x80009D88: sb          $s3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r19;
    // 0x80009D8C: sw          $s2, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r18;
    // 0x80009D90: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80009D94:
    // 0x80009D94: slti        $v0, $s2, 0x2
    ctx->r2 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x80009D98: bne         $v0, $zero, L_80009D74
    if (ctx->r2 != 0) {
        // 0x80009D9C: nop
    
            goto L_80009D74;
    }
    // 0x80009D9C: nop

L_80009DA0:
    // 0x80009DA0: jal         0x8000C494
    // 0x80009DA4: nop

    func_8000C494(rdram, ctx);
        goto after_43;
    // 0x80009DA4: nop

    after_43:
    // 0x80009DA8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80009DAC: lbu         $a0, 0x2074($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X2074);
    // 0x80009DB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80009DB4: bne         $a0, $v0, L_80009DE0
    if (ctx->r4 != ctx->r2) {
        // 0x80009DB8: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_80009DE0;
    }
    // 0x80009DB8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80009DBC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80009DC0: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x80009DC4: sltiu       $v0, $v1, 0x4
    ctx->r2 = ctx->r3 < 0X4 ? 1 : 0;
    // 0x80009DC8: beql        $v0, $zero, L_80009DE8
    if (ctx->r2 == 0) {
        // 0x80009DCC: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_80009DE8;
    }
    goto skip_1;
    // 0x80009DCC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    skip_1:
    // 0x80009DD0: bne         $v1, $a0, L_80009E00
    if (ctx->r3 != ctx->r4) {
        // 0x80009DD4: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80009E00;
    }
    // 0x80009DD4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80009DD8: j           L_80009E00
    // 0x80009DDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80009E00;
    // 0x80009DDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80009DE0:
    // 0x80009DE0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80009DE4: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
L_80009DE8:
    // 0x80009DE8: beq         $v1, $v0, L_80009E00
    if (ctx->r3 == ctx->r2) {
        // 0x80009DEC: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_80009E00;
    }
    // 0x80009DEC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80009DF0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009DF4: lbu         $v0, 0x2074($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2074);
    // 0x80009DF8: bne         $v0, $zero, L_80009E24
    if (ctx->r2 != 0) {
        // 0x80009DFC: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_80009E24;
    }
    // 0x80009DFC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_80009E00:
    // 0x80009E00: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009E04: sb          $v0, 0x7A50($at)
    MEM_B(0X7A50, ctx->r1) = ctx->r2;
    // 0x80009E08: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009E0C: sb          $v0, 0x7A4C($at)
    MEM_B(0X7A4C, ctx->r1) = ctx->r2;
    // 0x80009E10: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009E14: sb          $v0, 0x2600($at)
    MEM_B(0X2600, ctx->r1) = ctx->r2;
    // 0x80009E18: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009E1C: j           L_80009E44
    // 0x80009E20: sb          $v0, 0x25FC($at)
    MEM_B(0X25FC, ctx->r1) = ctx->r2;
        goto L_80009E44;
    // 0x80009E20: sb          $v0, 0x25FC($at)
    MEM_B(0X25FC, ctx->r1) = ctx->r2;
L_80009E24:
    // 0x80009E24: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009E28: lbu         $v0, 0x2600($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2600);
    // 0x80009E2C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80009E30: lbu         $v1, 0x7A50($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7A50);
    // 0x80009E34: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009E38: sb          $v0, 0x25FC($at)
    MEM_B(0X25FC, ctx->r1) = ctx->r2;
    // 0x80009E3C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009E40: sb          $v1, 0x7A4C($at)
    MEM_B(0X7A4C, ctx->r1) = ctx->r3;
L_80009E44:
    // 0x80009E44: jal         0x80009E6C
    // 0x80009E48: nop

    func_80009E6C(rdram, ctx);
        goto after_44;
    // 0x80009E48: nop

    after_44:
    // 0x80009E4C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80009E50: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80009E54: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80009E58: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80009E5C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80009E60: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80009E64: jr          $ra
    // 0x80009E68: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80009E68: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80009E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009E6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80009E70: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80009E74: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009E78: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x80009E7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80009E80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80009E84: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80009E88: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009E8C: sb          $zero, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = 0;
    // 0x80009E90: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009E94: sb          $zero, 0x7B99($at)
    MEM_B(0X7B99, ctx->r1) = 0;
    // 0x80009E98: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009E9C: sb          $zero, 0x7B8F($at)
    MEM_B(0X7B8F, ctx->r1) = 0;
    // 0x80009EA0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009EA4: jal         0x8006CEB0
    // 0x80009EA8: sb          $v0, 0x7B96($at)
    MEM_B(0X7B96, ctx->r1) = ctx->r2;
    func_8006CEB0(rdram, ctx);
        goto after_0;
    // 0x80009EA8: sb          $v0, 0x7B96($at)
    MEM_B(0X7B96, ctx->r1) = ctx->r2;
    after_0:
    // 0x80009EAC: lui         $v1, 0x9249
    ctx->r3 = S32(0X9249 << 16);
    // 0x80009EB0: ori         $v1, $v1, 0x2493
    ctx->r3 = ctx->r3 | 0X2493;
    // 0x80009EB4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80009EB8: lbu         $a1, 0x7BAA($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X7BAA);
    // 0x80009EBC: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80009EC0: sra         $v1, $v0, 31
    ctx->r3 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80009EC4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009EC8: sb          $zero, 0x7BA5($at)
    MEM_B(0X7BA5, ctx->r1) = 0;
    // 0x80009ECC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009ED0: sb          $zero, 0x7B82($at)
    MEM_B(0X7B82, ctx->r1) = 0;
    // 0x80009ED4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009ED8: sb          $zero, 0x7B81($at)
    MEM_B(0X7B81, ctx->r1) = 0;
    // 0x80009EDC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009EE0: sb          $zero, 0x7B80($at)
    MEM_B(0X7B80, ctx->r1) = 0;
    // 0x80009EE4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009EE8: sb          $zero, 0x7BA9($at)
    MEM_B(0X7BA9, ctx->r1) = 0;
    // 0x80009EEC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009EF0: sb          $zero, 0x7BA8($at)
    MEM_B(0X7BA8, ctx->r1) = 0;
    // 0x80009EF4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009EF8: sb          $zero, 0x7BA7($at)
    MEM_B(0X7BA7, ctx->r1) = 0;
    // 0x80009EFC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009F00: sb          $zero, 0x7BA6($at)
    MEM_B(0X7BA6, ctx->r1) = 0;
    // 0x80009F04: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009F08: sb          $zero, 0x7B8A($at)
    MEM_B(0X7B8A, ctx->r1) = 0;
    // 0x80009F0C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009F10: sb          $zero, 0x7B92($at)
    MEM_B(0X7B92, ctx->r1) = 0;
    // 0x80009F14: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009F18: sb          $zero, 0x7B91($at)
    MEM_B(0X7B91, ctx->r1) = 0;
    // 0x80009F1C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009F20: sb          $zero, 0x7B90($at)
    MEM_B(0X7B90, ctx->r1) = 0;
    // 0x80009F24: mfhi        $t0
    ctx->r8 = hi;
    // 0x80009F28: addu        $a0, $t0, $v0
    ctx->r4 = ADD32(ctx->r8, ctx->r2);
    // 0x80009F2C: sra         $a0, $a0, 2
    ctx->r4 = S32(SIGNED(ctx->r4) >> 2);
    // 0x80009F30: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x80009F34: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x80009F38: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80009F3C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80009F40: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009F44: bne         $a1, $zero, L_80009F7C
    if (ctx->r5 != 0) {
        // 0x80009F48: sb          $v0, 0x7B7C($at)
        MEM_B(0X7B7C, ctx->r1) = ctx->r2;
            goto L_80009F7C;
    }
    // 0x80009F48: sb          $v0, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = ctx->r2;
    // 0x80009F4C: jal         0x8006CEB0
    // 0x80009F50: nop

    func_8006CEB0(rdram, ctx);
        goto after_1;
    // 0x80009F50: nop

    after_1:
    // 0x80009F54: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80009F58: bltzl       $a0, L_80009F60
    if (SIGNED(ctx->r4) < 0) {
        // 0x80009F5C: addiu       $v0, $a0, 0x1F
        ctx->r2 = ADD32(ctx->r4, 0X1F);
            goto L_80009F60;
    }
    goto skip_0;
    // 0x80009F5C: addiu       $v0, $a0, 0x1F
    ctx->r2 = ADD32(ctx->r4, 0X1F);
    skip_0:
L_80009F60:
    // 0x80009F60: sra         $v1, $v0, 5
    ctx->r3 = S32(SIGNED(ctx->r2) >> 5);
    // 0x80009F64: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x80009F68: subu        $v1, $a0, $v0
    ctx->r3 = SUB32(ctx->r4, ctx->r2);
    // 0x80009F6C: sltiu       $v0, $v1, 0x1
    ctx->r2 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80009F70: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009F74: j           L_80009F84
    // 0x80009F78: sb          $v0, 0x7BAA($at)
    MEM_B(0X7BAA, ctx->r1) = ctx->r2;
        goto L_80009F84;
    // 0x80009F78: sb          $v0, 0x7BAA($at)
    MEM_B(0X7BAA, ctx->r1) = ctx->r2;
L_80009F7C:
    // 0x80009F7C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009F80: sb          $zero, 0x7BAA($at)
    MEM_B(0X7BAA, ctx->r1) = 0;
L_80009F84:
    // 0x80009F84: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009F88: addiu       $v0, $v0, 0x25A2
    ctx->r2 = ADD32(ctx->r2, 0X25A2);
    // 0x80009F8C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80009F90: lw          $a3, 0x2654($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X2654);
    // 0x80009F94: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80009F98: lw          $a2, 0x2658($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2658);
    // 0x80009F9C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80009FA0: lw          $a1, 0x7AA4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7AA4);
    // 0x80009FA4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80009FA8: lw          $v1, 0x7AA8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7AA8);
    // 0x80009FAC: addiu       $a0, $v0, -0x2
    ctx->r4 = ADD32(ctx->r2, -0X2);
    // 0x80009FB0: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80009FB4: addiu       $s0, $s0, 0x79F2
    ctx->r16 = ADD32(ctx->r16, 0X79F2);
    // 0x80009FB8: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80009FBC: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80009FC0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009FC4: addiu       $v0, $v0, -0x1D20
    ctx->r2 = ADD32(ctx->r2, -0X1D20);
    // 0x80009FC8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009FCC: sw          $v0, 0x2650($at)
    MEM_W(0X2650, ctx->r1) = ctx->r2;
    // 0x80009FD0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009FD4: addiu       $v0, $v0, -0x2740
    ctx->r2 = ADD32(ctx->r2, -0X2740);
    // 0x80009FD8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009FDC: sw          $v0, 0x7AA0($at)
    MEM_W(0X7AA0, ctx->r1) = ctx->r2;
    // 0x80009FE0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80009FE4: addiu       $v0, $v0, -0x34C8
    ctx->r2 = ADD32(ctx->r2, -0X34C8);
    // 0x80009FE8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009FEC: sw          $v0, 0x26B0($at)
    MEM_W(0X26B0, ctx->r1) = ctx->r2;
    // 0x80009FF0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80009FF4: addiu       $v0, $v0, 0xE10
    ctx->r2 = ADD32(ctx->r2, 0XE10);
    // 0x80009FF8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80009FFC: sb          $zero, 0x79F3($at)
    MEM_B(0X79F3, ctx->r1) = 0;
    // 0x8000A000: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A004: sb          $zero, 0x25A3($at)
    MEM_B(0X25A3, ctx->r1) = 0;
    // 0x8000A008: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A00C: sb          $zero, 0x79F1($at)
    MEM_B(0X79F1, ctx->r1) = 0;
    // 0x8000A010: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A014: sb          $zero, 0x25A1($at)
    MEM_B(0X25A1, ctx->r1) = 0;
    // 0x8000A018: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A01C: sb          $zero, 0x7B0D($at)
    MEM_B(0X7B0D, ctx->r1) = 0;
    // 0x8000A020: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A024: sb          $zero, 0x26BD($at)
    MEM_B(0X26BD, ctx->r1) = 0;
    // 0x8000A028: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A02C: sb          $zero, 0x7B0E($at)
    MEM_B(0X7B0E, ctx->r1) = 0;
    // 0x8000A030: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A034: sb          $zero, 0x26BE($at)
    MEM_B(0X26BE, ctx->r1) = 0;
    // 0x8000A038: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A03C: sw          $v0, 0x7B00($at)
    MEM_W(0X7B00, ctx->r1) = ctx->r2;
    // 0x8000A040: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x8000A044: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x8000A048: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x8000A04C: jal         0x80014614
    // 0x8000A050: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    func_80014614(rdram, ctx);
        goto after_2;
    // 0x8000A050: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    after_2:
    // 0x8000A054: jal         0x80014614
    // 0x8000A058: addiu       $a0, $s0, -0x2
    ctx->r4 = ADD32(ctx->r16, -0X2);
    func_80014614(rdram, ctx);
        goto after_3;
    // 0x8000A058: addiu       $a0, $s0, -0x2
    ctx->r4 = ADD32(ctx->r16, -0X2);
    after_3:
    // 0x8000A05C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8000A060: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000A064: addiu       $a0, $a0, 0x7BD0
    ctx->r4 = ADD32(ctx->r4, 0X7BD0);
    // 0x8000A068: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8000A06C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A070: sb          $zero, 0x7A3A($at)
    MEM_B(0X7A3A, ctx->r1) = 0;
    // 0x8000A074: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A078: sb          $zero, 0x25EA($at)
    MEM_B(0X25EA, ctx->r1) = 0;
    // 0x8000A07C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A080: sb          $zero, 0x7A39($at)
    MEM_B(0X7A39, ctx->r1) = 0;
    // 0x8000A084: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A088: sb          $zero, 0x25E9($at)
    MEM_B(0X25E9, ctx->r1) = 0;
L_8000A08C:
    // 0x8000A08C: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // 0x8000A090: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x8000A094: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x8000A098: addiu       $a0, $a0, 0x68
    ctx->r4 = ADD32(ctx->r4, 0X68);
    // 0x8000A09C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A0A0: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x8000A0A4: sb          $zero, 0x7BD0($at)
    MEM_B(0X7BD0, ctx->r1) = 0;
    // 0x8000A0A8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000A0AC: slti        $v0, $v1, 0x18
    ctx->r2 = SIGNED(ctx->r3) < 0X18 ? 1 : 0;
    // 0x8000A0B0: bne         $v0, $zero, L_8000A08C
    if (ctx->r2 != 0) {
        // 0x8000A0B4: addiu       $a1, $a1, 0x68
        ctx->r5 = ADD32(ctx->r5, 0X68);
            goto L_8000A08C;
    }
    // 0x8000A0B4: addiu       $a1, $a1, 0x68
    ctx->r5 = ADD32(ctx->r5, 0X68);
    // 0x8000A0B8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8000A0BC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8000A0C0: addiu       $a0, $a0, 0x55A0
    ctx->r4 = ADD32(ctx->r4, 0X55A0);
    // 0x8000A0C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8000A0C8:
    // 0x8000A0C8: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // 0x8000A0CC: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x8000A0D0: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    // 0x8000A0D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A0D8: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x8000A0DC: sb          $zero, 0x55A0($at)
    MEM_B(0X55A0, ctx->r1) = 0;
    // 0x8000A0E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000A0E4: slti        $v0, $v1, 0x60
    ctx->r2 = SIGNED(ctx->r3) < 0X60 ? 1 : 0;
    // 0x8000A0E8: bne         $v0, $zero, L_8000A0C8
    if (ctx->r2 != 0) {
        // 0x8000A0EC: addiu       $a1, $a1, 0x38
        ctx->r5 = ADD32(ctx->r5, 0X38);
            goto L_8000A0C8;
    }
    // 0x8000A0EC: addiu       $a1, $a1, 0x38
    ctx->r5 = ADD32(ctx->r5, 0X38);
    // 0x8000A0F0: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x8000A0F4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A0F8: addiu       $v0, $v0, -0x27E2
    ctx->r2 = ADD32(ctx->r2, -0X27E2);
L_8000A0FC:
    // 0x8000A0FC: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8000A100: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8000A104: bgez        $v1, L_8000A0FC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8000A108: addiu       $v0, $v0, -0xA2
        ctx->r2 = ADD32(ctx->r2, -0XA2);
            goto L_8000A0FC;
    }
    // 0x8000A108: addiu       $v0, $v0, -0xA2
    ctx->r2 = ADD32(ctx->r2, -0XA2);
    // 0x8000A10C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A110: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8000A114: beq         $v0, $zero, L_8000A12C
    if (ctx->r2 == 0) {
        // 0x8000A118: nop
    
            goto L_8000A12C;
    }
    // 0x8000A118: nop

    // 0x8000A11C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A120: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x8000A124: bne         $v0, $zero, L_8000A160
    if (ctx->r2 != 0) {
        // 0x8000A128: nop
    
            goto L_8000A160;
    }
    // 0x8000A128: nop

L_8000A12C:
    // 0x8000A12C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000A130: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x8000A134: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8000A138: bne         $v1, $v0, L_8000A160
    if (ctx->r3 != ctx->r2) {
        // 0x8000A13C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000A160;
    }
    // 0x8000A13C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A140: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000A144: lbu         $v1, 0x7B98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B98);
    // 0x8000A148: beq         $v1, $v0, L_8000A160
    if (ctx->r3 == ctx->r2) {
        // 0x8000A14C: nop
    
            goto L_8000A160;
    }
    // 0x8000A14C: nop

    // 0x8000A150: jal         0x8002CFB8
    // 0x8000A154: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002CFB8(rdram, ctx);
        goto after_4;
    // 0x8000A154: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_4:
    // 0x8000A158: j           L_8000A16C
    // 0x8000A15C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_8000A16C;
    // 0x8000A15C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8000A160:
    // 0x8000A160: jal         0x8002CFB8
    // 0x8000A164: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8002CFB8(rdram, ctx);
        goto after_5;
    // 0x8000A164: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x8000A168: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_8000A16C:
    // 0x8000A16C: jal         0x8002D378
    // 0x8000A170: nop

    func_8002D378(rdram, ctx);
        goto after_6;
    // 0x8000A170: nop

    after_6:
    // 0x8000A174: jal         0x8002D0D4
    // 0x8000A178: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_7;
    // 0x8000A178: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_7:
    // 0x8000A17C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A180: lbu         $v0, 0x7B97($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B97);
    // 0x8000A184: beq         $v0, $zero, L_8000A194
    if (ctx->r2 == 0) {
        // 0x8000A188: nop
    
            goto L_8000A194;
    }
    // 0x8000A188: nop

    // 0x8000A18C: jal         0x8001C36C
    // 0x8000A190: nop

    func_8001C36C(rdram, ctx);
        goto after_8;
    // 0x8000A190: nop

    after_8:
L_8000A194:
    // 0x8000A194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A198: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000A19C: jr          $ra
    // 0x8000A1A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000A1A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000A1A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A1A4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A1A8: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x8000A1AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A1B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A1B4: beq         $v0, $zero, L_8000A1F4
    if (ctx->r2 == 0) {
        // 0x8000A1B8: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8000A1F4;
    }
    // 0x8000A1B8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8000A1BC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A1C0: lb          $v0, 0x79F0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F0);
    // 0x8000A1C4: beq         $v0, $zero, L_8000A1F4
    if (ctx->r2 == 0) {
        // 0x8000A1C8: nop
    
            goto L_8000A1F4;
    }
    // 0x8000A1C8: nop

    // 0x8000A1CC: jal         0x8002CFB8
    // 0x8000A1D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_0;
    // 0x8000A1D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8000A1D4: beq         $v0, $zero, L_8000A2A8
    if (ctx->r2 == 0) {
        // 0x8000A1D8: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_8000A2A8;
    }
    // 0x8000A1D8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8000A1DC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000A1E0: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
L_8000A1E4:
    // 0x8000A1E4: bne         $v1, $v0, L_8000A288
    if (ctx->r3 != ctx->r2) {
        // 0x8000A1E8: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8000A288;
    }
    // 0x8000A1E8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000A1EC: j           L_8000A2A0
    // 0x8000A1F0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8000A2A0;
    // 0x8000A1F0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8000A1F4:
    // 0x8000A1F4: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8000A1F8: addiu       $s0, $s0, 0x7B85
    ctx->r16 = ADD32(ctx->r16, 0X7B85);
    // 0x8000A1FC: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x8000A200: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8000A204: beq         $v1, $v0, L_8000A240
    if (ctx->r3 == ctx->r2) {
        // 0x8000A208: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000A240;
    }
    // 0x8000A208: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A20C: jal         0x8002CFB8
    // 0x8000A210: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_1;
    // 0x8000A210: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8000A214: beq         $v0, $zero, L_8000A2A8
    if (ctx->r2 == 0) {
        // 0x8000A218: nop
    
            goto L_8000A2A8;
    }
    // 0x8000A218: nop

    // 0x8000A21C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A220: lbu         $v0, 0x7B9C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9C);
    // 0x8000A224: beq         $v0, $zero, L_8000A234
    if (ctx->r2 == 0) {
        // 0x8000A228: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8000A234;
    }
    // 0x8000A228: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000A22C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A230: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
L_8000A234:
    // 0x8000A234: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x8000A238: j           L_8000A1E4
    // 0x8000A23C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_8000A1E4;
    // 0x8000A23C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_8000A240:
    // 0x8000A240: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8000A244: lbu         $v1, 0x7B98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B98);
    // 0x8000A248: beq         $v1, $v0, L_8000A26C
    if (ctx->r3 == ctx->r2) {
        // 0x8000A24C: nop
    
            goto L_8000A26C;
    }
    // 0x8000A24C: nop

    // 0x8000A250: jal         0x8002D378
    // 0x8000A254: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002D378(rdram, ctx);
        goto after_2;
    // 0x8000A254: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x8000A258: beq         $v0, $zero, L_8000A2A8
    if (ctx->r2 == 0) {
        // 0x8000A25C: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_8000A2A8;
    }
    // 0x8000A25C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8000A260: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x8000A264: j           L_8000A1E4
    // 0x8000A268: nop

        goto L_8000A1E4;
    // 0x8000A268: nop

L_8000A26C:
    // 0x8000A26C: jal         0x8002CFB8
    // 0x8000A270: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_3;
    // 0x8000A270: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8000A274: beq         $v0, $zero, L_8000A2A8
    if (ctx->r2 == 0) {
        // 0x8000A278: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_8000A2A8;
    }
    // 0x8000A278: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8000A27C: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x8000A280: beq         $v1, $v0, L_8000A29C
    if (ctx->r3 == ctx->r2) {
        // 0x8000A284: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8000A29C;
    }
    // 0x8000A284: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8000A288:
    // 0x8000A288: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A28C: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x8000A290: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A294: j           L_8000A2A8
    // 0x8000A298: sb          $zero, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = 0;
        goto L_8000A2A8;
    // 0x8000A298: sb          $zero, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = 0;
L_8000A29C:
    // 0x8000A29C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8000A2A0:
    // 0x8000A2A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8000A2A4: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
L_8000A2A8:
    // 0x8000A2A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A2AC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8000A2B0: jr          $ra
    // 0x8000A2B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000A2B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8000A2B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A2B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A2BC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8000A2C0: jal         0x8000B80C
    // 0x8000A2C4: nop

    func_8000B80C(rdram, ctx);
        goto after_0;
    // 0x8000A2C4: nop

    after_0:
    // 0x8000A2C8: bne         $v0, $zero, L_8000A2F0
    if (ctx->r2 != 0) {
        // 0x8000A2CC: nop
    
            goto L_8000A2F0;
    }
    // 0x8000A2CC: nop

    // 0x8000A2D0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8000A2D4: lbu         $v0, 0x7B72($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B72);
    // 0x8000A2D8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000A2DC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8000A2E0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8000A2E4: lw          $v0, -0xE6C($at)
    ctx->r2 = MEM_W(ctx->r1, -0XE6C);
    // 0x8000A2E8: jalr        $v0
    // 0x8000A2EC: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8000A2EC: nop

    after_1:
L_8000A2F0:
    // 0x8000A2F0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8000A2F4: jr          $ra
    // 0x8000A2F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000A2F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
