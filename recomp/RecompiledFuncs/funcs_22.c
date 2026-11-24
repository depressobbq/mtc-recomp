#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80066130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066138: jal         0x80068AE0
    // 0x8006613C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x8006613C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80066140: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80066144: lw          $v1, -0x7F0C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7F0C);
    // 0x80066148: lw          $s0, 0x4($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X4);
    // 0x8006614C: jal         0x80068B00
    // 0x80066150: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    __osRestoreInt_recomp(rdram, ctx);
        goto after_1;
    // 0x80066150: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80066154: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80066158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006615C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80066160: jr          $ra
    // 0x80066164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80066164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8006662C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006662C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80066630: addu        $t3, $a0, $zero
    ctx->r11 = ADD32(ctx->r4, 0);
    // 0x80066634: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // 0x80066638: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8006663C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80066640: lbu         $v0, -0x442C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X442C);
    // 0x80066644: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80066648: addiu       $t0, $t0, -0x2B30
    ctx->r8 = ADD32(ctx->r8, -0X2B30);
    // 0x8006664C: blez        $v0, L_800666D4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80066650: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_800666D4;
    }
    // 0x80066650: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80066654: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80066658: addiu       $a2, $a1, 0x2
    ctx->r6 = ADD32(ctx->r5, 0X2);
L_8006665C:
    // 0x8006665C: lwl         $v0, 0x0($t0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r8, 0X0);
    // 0x80066660: lwr         $v0, 0x3($t0)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r8, 0X3);
    // 0x80066664: lwl         $v1, 0x4($t0)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r8, 0X4);
    // 0x80066668: lwr         $v1, 0x7($t0)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r8, 0X7);
    // 0x8006666C: swl         $v0, 0x0($sp)
    do_swl(rdram, 0X0, ctx->r29, ctx->r2);
    // 0x80066670: swr         $v0, 0x3($sp)
    do_swr(rdram, 0X3, ctx->r29, ctx->r2);
    // 0x80066674: swl         $v1, 0x4($sp)
    do_swl(rdram, 0X4, ctx->r29, ctx->r3);
    // 0x80066678: swr         $v1, 0x7($sp)
    do_swr(rdram, 0X7, ctx->r29, ctx->r3);
    // 0x8006667C: lbu         $v0, 0x2($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2);
    // 0x80066680: andi        $v0, $v0, 0xC0
    ctx->r2 = ctx->r2 & 0XC0;
    // 0x80066684: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x80066688: bne         $v0, $zero, L_800666B4
    if (ctx->r2 != 0) {
        // 0x8006668C: sb          $v0, 0x1($a2)
        MEM_B(0X1, ctx->r6) = ctx->r2;
            goto L_800666B4;
    }
    // 0x8006668C: sb          $v0, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r2;
    // 0x80066690: lbu         $v0, 0x5($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X5);
    // 0x80066694: lbu         $v1, 0x4($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X4);
    // 0x80066698: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8006669C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800666A0: sh          $v1, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r3;
    // 0x800666A4: lbu         $v1, 0x6($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X6);
    // 0x800666A8: sllv        $v0, $t4, $a3
    ctx->r2 = S32(ctx->r12 << (ctx->r7 & 31));
    // 0x800666AC: or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
    // 0x800666B0: sb          $v1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r3;
L_800666B4:
    // 0x800666B4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800666B8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800666BC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800666C0: lbu         $v0, -0x442C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X442C);
    // 0x800666C4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800666C8: slt         $v0, $a3, $v0
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800666CC: bne         $v0, $zero, L_8006665C
    if (ctx->r2 != 0) {
        // 0x800666D0: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_8006665C;
    }
    // 0x800666D0: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
L_800666D4:
    // 0x800666D4: sb          $t2, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r10;
    // 0x800666D8: jr          $ra
    // 0x800666DC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800666DC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800666E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800666E0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800666E4: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800666E8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x800666EC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800666F0: addiu       $v0, $v0, -0x2AF8
    ctx->r2 = ADD32(ctx->r2, -0X2AF8);
L_800666F4:
    // 0x800666F4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800666F8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800666FC: bgez        $a2, L_800666F4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80066700: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_800666F4;
    }
    // 0x80066700: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80066704: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80066708: addiu       $v1, $v1, -0x2AF4
    ctx->r3 = ADD32(ctx->r3, -0X2AF4);
    // 0x8006670C: addiu       $a3, $v1, -0x3C
    ctx->r7 = ADD32(ctx->r3, -0X3C);
    // 0x80066710: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80066714: lbu         $a0, -0x442C($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X442C);
    // 0x80066718: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8006671C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80066720: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80066724: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80066728: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006672C: sb          $v0, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r2;
    // 0x80066730: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80066734: sb          $v1, 0x0($sp)
    MEM_B(0X0, ctx->r29) = ctx->r3;
    // 0x80066738: sb          $v0, 0x2($sp)
    MEM_B(0X2, ctx->r29) = ctx->r2;
    // 0x8006673C: sb          $a1, 0x3($sp)
    MEM_B(0X3, ctx->r29) = ctx->r5;
    // 0x80066740: sb          $v1, 0x4($sp)
    MEM_B(0X4, ctx->r29) = ctx->r3;
    // 0x80066744: sb          $v1, 0x5($sp)
    MEM_B(0X5, ctx->r29) = ctx->r3;
    // 0x80066748: sb          $v1, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r3;
    // 0x8006674C: blez        $a0, L_8006678C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80066750: sb          $v1, 0x7($sp)
        MEM_B(0X7, ctx->r29) = ctx->r3;
            goto L_8006678C;
    }
    // 0x80066750: sb          $v1, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r3;
L_80066754:
    // 0x80066754: lwl         $v0, 0x0($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r29, 0X0);
    // 0x80066758: lwr         $v0, 0x3($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r29, 0X3);
    // 0x8006675C: lwl         $v1, 0x4($sp)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r29, 0X4);
    // 0x80066760: lwr         $v1, 0x7($sp)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r29, 0X7);
    // 0x80066764: swl         $v0, 0x0($a3)
    do_swl(rdram, 0X0, ctx->r7, ctx->r2);
    // 0x80066768: swr         $v0, 0x3($a3)
    do_swr(rdram, 0X3, ctx->r7, ctx->r2);
    // 0x8006676C: swl         $v1, 0x4($a3)
    do_swl(rdram, 0X4, ctx->r7, ctx->r3);
    // 0x80066770: swr         $v1, 0x7($a3)
    do_swr(rdram, 0X7, ctx->r7, ctx->r3);
    // 0x80066774: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80066778: lbu         $v0, -0x442C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X442C);
    // 0x8006677C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80066780: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80066784: bne         $v0, $zero, L_80066754
    if (ctx->r2 != 0) {
        // 0x80066788: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_80066754;
    }
    // 0x80066788: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_8006678C:
    // 0x8006678C: addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // 0x80066790: sb          $v0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r2;
    // 0x80066794: jr          $ra
    // 0x80066798: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80066798: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void bcopy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066850: beq         $a2, $zero, L_800668C0
    if (ctx->r6 == 0) {
        // 0x80066854: addu        $a3, $a1, $zero
        ctx->r7 = ADD32(ctx->r5, 0);
            goto L_800668C0;
    }
    // 0x80066854: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x80066858: beq         $a0, $a1, L_800668C0
    if (ctx->r4 == ctx->r5) {
        // 0x8006685C: nop
    
            goto L_800668C0;
    }
    // 0x8006685C: nop

    // 0x80066860: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80066864: bne         $at, $zero, L_80066884
    if (ctx->r1 != 0) {
        // 0x80066868: nop
    
            goto L_80066884;
    }
    // 0x80066868: nop

    // 0x8006686C: add         $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // 0x80066870: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80066874: beq         $at, $zero, L_80066884
    if (ctx->r1 == 0) {
        // 0x80066878: nop
    
            goto L_80066884;
    }
    // 0x80066878: nop

    // 0x8006687C: b           L_800669F0
    // 0x80066880: nop

        goto L_800669F0;
    // 0x80066880: nop

L_80066884:
    // 0x80066884: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x80066888: bne         $at, $zero, L_800668A0
    if (ctx->r1 != 0) {
        // 0x8006688C: nop
    
            goto L_800668A0;
    }
    // 0x8006688C: nop

    // 0x80066890: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x80066894: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x80066898: beq         $v0, $v1, L_800668C8
    if (ctx->r2 == ctx->r3) {
        // 0x8006689C: nop
    
            goto L_800668C8;
    }
    // 0x8006689C: nop

L_800668A0:
    // 0x800668A0: beq         $a2, $zero, L_800668C0
    if (ctx->r6 == 0) {
        // 0x800668A4: nop
    
            goto L_800668C0;
    }
    // 0x800668A4: nop

    // 0x800668A8: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
L_800668AC:
    // 0x800668AC: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800668B0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800668B4: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800668B8: bne         $a0, $v1, L_800668AC
    if (ctx->r4 != ctx->r3) {
        // 0x800668BC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800668AC;
    }
    // 0x800668BC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800668C0:
    // 0x800668C0: jr          $ra
    // 0x800668C4: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    return;
    // 0x800668C4: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
L_800668C8:
    // 0x800668C8: beq         $v0, $zero, L_80066934
    if (ctx->r2 == 0) {
        // 0x800668CC: nop
    
            goto L_80066934;
    }
    // 0x800668CC: nop

    // 0x800668D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800668D4: beq         $v0, $at, L_80066918
    if (ctx->r2 == ctx->r1) {
        // 0x800668D8: nop
    
            goto L_80066918;
    }
    // 0x800668D8: nop

    // 0x800668DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800668E0: beq         $v0, $at, L_80066900
    if (ctx->r2 == ctx->r1) {
        // 0x800668E4: nop
    
            goto L_80066900;
    }
    // 0x800668E4: nop

    // 0x800668E8: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800668EC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800668F0: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800668F4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800668F8: b           L_80066934
    // 0x800668FC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
        goto L_80066934;
    // 0x800668FC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_80066900:
    // 0x80066900: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80066904: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80066908: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8006690C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80066910: b           L_80066934
    // 0x80066914: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
        goto L_80066934;
    // 0x80066914: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
L_80066918:
    // 0x80066918: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8006691C: lh          $v1, 0x1($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1);
    // 0x80066920: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x80066924: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80066928: sh          $v1, 0x1($a1)
    MEM_H(0X1, ctx->r5) = ctx->r3;
    // 0x8006692C: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x80066930: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
L_80066934:
    // 0x80066934: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x80066938: bne         $at, $zero, L_80066990
    if (ctx->r1 != 0) {
        // 0x8006693C: nop
    
            goto L_80066990;
    }
    // 0x8006693C: nop

    // 0x80066940: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80066944: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80066948: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x8006694C: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x80066950: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    // 0x80066954: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x80066958: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x8006695C: lw          $t5, 0x1C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C);
    // 0x80066960: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80066964: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80066968: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // 0x8006696C: sw          $t0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r8;
    // 0x80066970: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
    // 0x80066974: sw          $t2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r10;
    // 0x80066978: sw          $t3, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r11;
    // 0x8006697C: sw          $t4, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r12;
    // 0x80066980: sw          $t5, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r13;
    // 0x80066984: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x80066988: b           L_80066934
    // 0x8006698C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
        goto L_80066934;
    // 0x8006698C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
L_80066990:
    // 0x80066990: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x80066994: bne         $at, $zero, L_800669CC
    if (ctx->r1 != 0) {
        // 0x80066998: nop
    
            goto L_800669CC;
    }
    // 0x80066998: nop

    // 0x8006699C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800669A0: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800669A4: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800669A8: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800669AC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800669B0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800669B4: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // 0x800669B8: sw          $t0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r8;
    // 0x800669BC: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
    // 0x800669C0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800669C4: b           L_80066990
    // 0x800669C8: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
        goto L_80066990;
    // 0x800669C8: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
L_800669CC:
    // 0x800669CC: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x800669D0: bne         $at, $zero, L_800668A0
    if (ctx->r1 != 0) {
        // 0x800669D4: nop
    
            goto L_800668A0;
    }
    // 0x800669D4: nop

    // 0x800669D8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800669DC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800669E0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800669E4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800669E8: b           L_800669CC
    // 0x800669EC: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
        goto L_800669CC;
    // 0x800669EC: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
L_800669F0:
    // 0x800669F0: add         $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x800669F4: add         $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x800669F8: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x800669FC: bne         $at, $zero, L_80066A14
    if (ctx->r1 != 0) {
        // 0x80066A00: nop
    
            goto L_80066A14;
    }
    // 0x80066A00: nop

    // 0x80066A04: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x80066A08: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x80066A0C: beq         $v0, $v1, L_80066A44
    if (ctx->r2 == ctx->r3) {
        // 0x80066A10: nop
    
            goto L_80066A44;
    }
    // 0x80066A10: nop

L_80066A14:
    // 0x80066A14: beq         $a2, $zero, L_800668C0
    if (ctx->r6 == 0) {
        // 0x80066A18: nop
    
            goto L_800668C0;
    }
    // 0x80066A18: nop

    // 0x80066A1C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80066A20: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80066A24: subu        $v1, $a0, $a2
    ctx->r3 = SUB32(ctx->r4, ctx->r6);
L_80066A28:
    // 0x80066A28: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80066A2C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80066A30: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80066A34: bne         $a0, $v1, L_80066A28
    if (ctx->r4 != ctx->r3) {
        // 0x80066A38: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_80066A28;
    }
    // 0x80066A38: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80066A3C: jr          $ra
    // 0x80066A40: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    return;
    // 0x80066A40: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
L_80066A44:
    // 0x80066A44: beq         $v0, $zero, L_80066AB0
    if (ctx->r2 == 0) {
        // 0x80066A48: nop
    
            goto L_80066AB0;
    }
    // 0x80066A48: nop

    // 0x80066A4C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80066A50: beq         $v0, $at, L_80066A94
    if (ctx->r2 == ctx->r1) {
        // 0x80066A54: nop
    
            goto L_80066A94;
    }
    // 0x80066A54: nop

    // 0x80066A58: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80066A5C: beq         $v0, $at, L_80066A7C
    if (ctx->r2 == ctx->r1) {
        // 0x80066A60: nop
    
            goto L_80066A7C;
    }
    // 0x80066A60: nop

    // 0x80066A64: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x80066A68: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80066A6C: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
    // 0x80066A70: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80066A74: b           L_80066AB0
    // 0x80066A78: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
        goto L_80066AB0;
    // 0x80066A78: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_80066A7C:
    // 0x80066A7C: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
    // 0x80066A80: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x80066A84: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
    // 0x80066A88: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x80066A8C: b           L_80066AB0
    // 0x80066A90: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
        goto L_80066AB0;
    // 0x80066A90: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
L_80066A94:
    // 0x80066A94: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x80066A98: lh          $v1, -0x3($a0)
    ctx->r3 = MEM_H(ctx->r4, -0X3);
    // 0x80066A9C: addiu       $a0, $a0, -0x3
    ctx->r4 = ADD32(ctx->r4, -0X3);
    // 0x80066AA0: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
    // 0x80066AA4: sh          $v1, -0x3($a1)
    MEM_H(-0X3, ctx->r5) = ctx->r3;
    // 0x80066AA8: addiu       $a1, $a1, -0x3
    ctx->r5 = ADD32(ctx->r5, -0X3);
    // 0x80066AAC: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
L_80066AB0:
    // 0x80066AB0: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x80066AB4: bne         $at, $zero, L_80066B0C
    if (ctx->r1 != 0) {
        // 0x80066AB8: nop
    
            goto L_80066B0C;
    }
    // 0x80066AB8: nop

    // 0x80066ABC: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x80066AC0: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x80066AC4: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x80066AC8: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x80066ACC: lw          $t2, -0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, -0X14);
    // 0x80066AD0: lw          $t3, -0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, -0X18);
    // 0x80066AD4: lw          $t4, -0x1C($a0)
    ctx->r12 = MEM_W(ctx->r4, -0X1C);
    // 0x80066AD8: lw          $t5, -0x20($a0)
    ctx->r13 = MEM_W(ctx->r4, -0X20);
    // 0x80066ADC: addiu       $a0, $a0, -0x20
    ctx->r4 = ADD32(ctx->r4, -0X20);
    // 0x80066AE0: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
    // 0x80066AE4: sw          $v1, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r3;
    // 0x80066AE8: sw          $t0, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r8;
    // 0x80066AEC: sw          $t1, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r9;
    // 0x80066AF0: sw          $t2, -0x14($a1)
    MEM_W(-0X14, ctx->r5) = ctx->r10;
    // 0x80066AF4: sw          $t3, -0x18($a1)
    MEM_W(-0X18, ctx->r5) = ctx->r11;
    // 0x80066AF8: sw          $t4, -0x1C($a1)
    MEM_W(-0X1C, ctx->r5) = ctx->r12;
    // 0x80066AFC: sw          $t5, -0x20($a1)
    MEM_W(-0X20, ctx->r5) = ctx->r13;
    // 0x80066B00: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    // 0x80066B04: b           L_80066AB0
    // 0x80066B08: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
        goto L_80066AB0;
    // 0x80066B08: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
L_80066B0C:
    // 0x80066B0C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x80066B10: bne         $at, $zero, L_80066B48
    if (ctx->r1 != 0) {
        // 0x80066B14: nop
    
            goto L_80066B48;
    }
    // 0x80066B14: nop

    // 0x80066B18: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x80066B1C: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x80066B20: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x80066B24: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x80066B28: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x80066B2C: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
    // 0x80066B30: sw          $v1, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r3;
    // 0x80066B34: sw          $t0, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r8;
    // 0x80066B38: sw          $t1, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r9;
    // 0x80066B3C: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x80066B40: b           L_80066B0C
    // 0x80066B44: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
        goto L_80066B0C;
    // 0x80066B44: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
L_80066B48:
    // 0x80066B48: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80066B4C: bne         $at, $zero, L_80066A14
    if (ctx->r1 != 0) {
        // 0x80066B50: nop
    
            goto L_80066A14;
    }
    // 0x80066B50: nop

    // 0x80066B54: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x80066B58: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x80066B5C: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
    // 0x80066B60: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x80066B64: b           L_80066B48
    // 0x80066B68: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
        goto L_80066B48;
    // 0x80066B68: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
;}
RECOMP_FUNC void bzero_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066B70: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x80066B74: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x80066B78: bne         $at, $zero, L_80066BF0
    if (ctx->r1 != 0) {
        // 0x80066B7C: nop
    
            goto L_80066BF0;
    }
    // 0x80066B7C: nop

    // 0x80066B80: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x80066B84: beq         $v1, $zero, L_80066B94
    if (ctx->r3 == 0) {
        // 0x80066B88: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_80066B94;
    }
    // 0x80066B88: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x80066B8C: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x80066B90: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_80066B94:
    // 0x80066B94: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x80066B98: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x80066B9C: beq         $a3, $zero, L_80066BD0
    if (ctx->r7 == 0) {
        // 0x80066BA0: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_80066BD0;
    }
    // 0x80066BA0: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x80066BA4: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_80066BA8:
    // 0x80066BA8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80066BAC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80066BB0: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x80066BB4: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80066BB8: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80066BBC: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x80066BC0: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x80066BC4: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x80066BC8: bne         $a0, $a3, L_80066BA8
    if (ctx->r4 != ctx->r7) {
        // 0x80066BCC: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_80066BA8;
    }
    // 0x80066BCC: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_80066BD0:
    // 0x80066BD0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80066BD4: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x80066BD8: beq         $a3, $zero, L_80066BF0
    if (ctx->r7 == 0) {
        // 0x80066BDC: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_80066BF0;
    }
    // 0x80066BDC: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x80066BE0: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_80066BE4:
    // 0x80066BE4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80066BE8: bne         $a0, $a3, L_80066BE4
    if (ctx->r4 != ctx->r7) {
        // 0x80066BEC: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_80066BE4;
    }
    // 0x80066BEC: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_80066BF0:
    // 0x80066BF0: blez        $a1, L_80066C08
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80066BF4: nop
    
            goto L_80066C08;
    }
    // 0x80066BF4: nop

    // 0x80066BF8: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_80066BFC:
    // 0x80066BFC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80066C00: bne         $a0, $a1, L_80066BFC
    if (ctx->r4 != ctx->r5) {
        // 0x80066C04: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_80066BFC;
    }
    // 0x80066C04: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_80066C08:
    // 0x80066C08: jr          $ra
    // 0x80066C0C: nop

    return;
    // 0x80066C0C: nop

;}
RECOMP_FUNC void strchr_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066C10: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80066C14: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80066C18: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x80066C1C: beq         $v0, $a1, L_80066C40
    if (ctx->r2 == ctx->r5) {
        // 0x80066C20: addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
            goto L_80066C40;
    }
    // 0x80066C20: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_80066C24:
    // 0x80066C24: bne         $v1, $zero, L_80066C34
    if (ctx->r3 != 0) {
        // 0x80066C28: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80066C34;
    }
    // 0x80066C28: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80066C2C: j           L_80066C40
    // 0x80066C30: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80066C40;
    // 0x80066C30: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80066C34:
    // 0x80066C34: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80066C38: bne         $v1, $a1, L_80066C24
    if (ctx->r3 != ctx->r5) {
        // 0x80066C3C: addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
            goto L_80066C24;
    }
    // 0x80066C3C: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_80066C40:
    // 0x80066C40: jr          $ra
    // 0x80066C44: nop

    return;
    // 0x80066C44: nop

;}
RECOMP_FUNC void strlen_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066C48: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80066C4C: beq         $v0, $zero, L_80066C64
    if (ctx->r2 == 0) {
        // 0x80066C50: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80066C64;
    }
    // 0x80066C50: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80066C54: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80066C58:
    // 0x80066C58: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80066C5C: bnel        $v0, $zero, L_80066C58
    if (ctx->r2 != 0) {
        // 0x80066C60: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80066C58;
    }
    goto skip_0;
    // 0x80066C60: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
L_80066C64:
    // 0x80066C64: jr          $ra
    // 0x80066C68: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    return;
    // 0x80066C68: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
;}
RECOMP_FUNC void memcpy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066C6C: beq         $a2, $zero, L_80066C8C
    if (ctx->r6 == 0) {
        // 0x80066C70: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80066C8C;
    }
    // 0x80066C70: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80066C74:
    // 0x80066C74: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80066C78: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80066C7C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80066C80: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80066C84: bne         $a2, $zero, L_80066C74
    if (ctx->r6 != 0) {
        // 0x80066C88: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80066C74;
    }
    // 0x80066C88: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80066C8C:
    // 0x80066C8C: jr          $ra
    // 0x80066C90: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    return;
    // 0x80066C90: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
;}
RECOMP_FUNC void func_80066CA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066CA0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80066CA4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80066CA8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80066CAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066CB0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80066CB4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80066CB8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80066CBC: lui         $a0, 0x8006
    ctx->r4 = S32(0X8006 << 16);
    // 0x80066CC0: addiu       $a0, $a0, 0x6CF8
    ctx->r4 = ADD32(ctx->r4, 0X6CF8);
    // 0x80066CC4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80066CC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066CCC: jal         0x80069C70
    // 0x80066CD0: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    func_80069C70(rdram, ctx);
        goto after_0;
    // 0x80066CD0: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80066CD4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80066CD8: bltz        $v1, L_80066CE4
    if (SIGNED(ctx->r3) < 0) {
        // 0x80066CDC: addu        $v0, $s0, $v1
        ctx->r2 = ADD32(ctx->r16, ctx->r3);
            goto L_80066CE4;
    }
    // 0x80066CDC: addu        $v0, $s0, $v1
    ctx->r2 = ADD32(ctx->r16, ctx->r3);
    // 0x80066CE0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_80066CE4:
    // 0x80066CE4: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80066CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066CEC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80066CF0: jr          $ra
    // 0x80066CF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80066CF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80066CF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066CF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80066CFC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80066D00: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80066D04: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80066D08: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80066D0C: jal         0x80066C6C
    // 0x80066D10: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x80066D10: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    after_0:
    // 0x80066D14: addu        $v0, $s1, $s0
    ctx->r2 = ADD32(ctx->r17, ctx->r16);
    // 0x80066D18: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80066D1C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80066D20: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80066D24: jr          $ra
    // 0x80066D28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80066D28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80066D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066D30: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80066D34: lbu         $v1, 0x16($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X16);
    // 0x80066D38: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80066D3C: bne         $v1, $v0, L_80066D48
    if (ctx->r3 != ctx->r2) {
        // 0x80066D40: addiu       $a3, $zero, 0x200
        ctx->r7 = ADD32(0, 0X200);
            goto L_80066D48;
    }
    // 0x80066D40: addiu       $a3, $zero, 0x200
    ctx->r7 = ADD32(0, 0X200);
    // 0x80066D44: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
L_80066D48:
    // 0x80066D48: lbu         $v1, 0x17($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X17);
    // 0x80066D4C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80066D50: lhu         $a0, 0x14($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X14);
    // 0x80066D54: subu        $a1, $v0, $v1
    ctx->r5 = SUB32(ctx->r2, ctx->r3);
    // 0x80066D58: addiu       $v0, $zero, 0x33
    ctx->r2 = ADD32(0, 0X33);
    // 0x80066D5C: bnel        $a0, $v0, L_80066DFC
    if (ctx->r4 != ctx->r2) {
        // 0x80066D60: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_80066DFC;
    }
    goto skip_0;
    // 0x80066D60: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    skip_0:
    // 0x80066D64: lhu         $v0, 0x2($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2);
    // 0x80066D68: srav        $v0, $v0, $a1
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r5 & 31));
    // 0x80066D6C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80066D70: divu        $zero, $a3, $v1
    lo = S32(U32(ctx->r7) / U32(ctx->r3)); hi = S32(U32(ctx->r7) % U32(ctx->r3));
    // 0x80066D74: bne         $v1, $zero, L_80066D80
    if (ctx->r3 != 0) {
        // 0x80066D78: nop
    
            goto L_80066D80;
    }
    // 0x80066D78: nop

    // 0x80066D7C: break       7
    do_break(2147904892);
L_80066D80:
    // 0x80066D80: mflo        $v1
    ctx->r3 = lo;
    // 0x80066D84: sh          $v0, 0x1C($a2)
    MEM_H(0X1C, ctx->r6) = ctx->r2;
    // 0x80066D88: lhu         $v0, 0x1C($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X1C);
    // 0x80066D8C: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    // 0x80066D90: div         $zero, $a0, $v0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r2)));
    // 0x80066D94: bne         $v0, $zero, L_80066DA0
    if (ctx->r2 != 0) {
        // 0x80066D98: nop
    
            goto L_80066DA0;
    }
    // 0x80066D98: nop

    // 0x80066D9C: break       7
    do_break(2147904924);
L_80066DA0:
    // 0x80066DA0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80066DA4: bne         $v0, $at, L_80066DB8
    if (ctx->r2 != ctx->r1) {
        // 0x80066DA8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80066DB8;
    }
    // 0x80066DA8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80066DAC: bne         $a0, $at, L_80066DB8
    if (ctx->r4 != ctx->r1) {
        // 0x80066DB0: nop
    
            goto L_80066DB8;
    }
    // 0x80066DB0: nop

    // 0x80066DB4: break       6
    do_break(2147904948);
L_80066DB8:
    // 0x80066DB8: mflo        $a0
    ctx->r4 = lo;
    // 0x80066DBC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80066DC0: sh          $v1, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = ctx->r3;
    // 0x80066DC4: lhu         $v1, 0x1C($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X1C);
    // 0x80066DC8: lhu         $v0, 0x1E($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X1E);
    // 0x80066DCC: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80066DD0: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066DD4: mflo        $v0
    ctx->r2 = lo;
    // 0x80066DD8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80066DDC: sh          $v1, 0x24($a2)
    MEM_H(0X24, ctx->r6) = ctx->r3;
    // 0x80066DE0: sh          $a0, 0x22($a2)
    MEM_H(0X22, ctx->r6) = ctx->r4;
    // 0x80066DE4: sh          $v0, 0x26($a2)
    MEM_H(0X26, ctx->r6) = ctx->r2;
    // 0x80066DE8: andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
    // 0x80066DEC: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x80066DF0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80066DF4: j           L_80066E64
    // 0x80066DF8: sh          $v0, 0x20($a2)
    MEM_H(0X20, ctx->r6) = ctx->r2;
        goto L_80066E64;
    // 0x80066DF8: sh          $v0, 0x20($a2)
    MEM_H(0X20, ctx->r6) = ctx->r2;
L_80066DFC:
    // 0x80066DFC: lhu         $a0, 0x6($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X6);
    // 0x80066E00: srav        $a0, $a0, $a1
    ctx->r4 = S32(SIGNED(ctx->r4) >> (ctx->r5 & 31));
    // 0x80066E04: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x80066E08: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x80066E0C: divu        $zero, $a3, $v0
    lo = S32(U32(ctx->r7) / U32(ctx->r2)); hi = S32(U32(ctx->r7) % U32(ctx->r2));
    // 0x80066E10: bne         $v0, $zero, L_80066E1C
    if (ctx->r2 != 0) {
        // 0x80066E14: nop
    
            goto L_80066E1C;
    }
    // 0x80066E14: nop

    // 0x80066E18: break       7
    do_break(2147905048);
L_80066E1C:
    // 0x80066E1C: mflo        $v0
    ctx->r2 = lo;
    // 0x80066E20: lhu         $v1, 0x2($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X2);
    // 0x80066E24: srav        $v1, $v1, $a1
    ctx->r3 = S32(SIGNED(ctx->r3) >> (ctx->r5 & 31));
    // 0x80066E28: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80066E2C: sh          $v0, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = ctx->r2;
    // 0x80066E30: lhu         $a1, 0x1E($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X1E);
    // 0x80066E34: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80066E38: andi        $v0, $v1, 0xFFFE
    ctx->r2 = ctx->r3 & 0XFFFE;
    // 0x80066E3C: mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066E40: mflo        $a1
    ctx->r5 = lo;
    // 0x80066E44: lhu         $v0, 0x1E($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X1E);
    // 0x80066E48: sh          $a0, 0x1C($a2)
    MEM_H(0X1C, ctx->r6) = ctx->r4;
    // 0x80066E4C: sh          $v1, 0x24($a2)
    MEM_H(0X24, ctx->r6) = ctx->r3;
    // 0x80066E50: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80066E54: sh          $v0, 0x22($a2)
    MEM_H(0X22, ctx->r6) = ctx->r2;
    // 0x80066E58: srl         $v0, $a1, 16
    ctx->r2 = S32(U32(ctx->r5) >> 16);
    // 0x80066E5C: sh          $v0, 0x26($a2)
    MEM_H(0X26, ctx->r6) = ctx->r2;
    // 0x80066E60: sh          $a1, 0x20($a2)
    MEM_H(0X20, ctx->r6) = ctx->r5;
L_80066E64:
    // 0x80066E64: jr          $ra
    // 0x80066E68: nop

    return;
    // 0x80066E68: nop

;}
RECOMP_FUNC void func_800670B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800670B4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800670B8: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800670BC: addiu       $a3, $a3, -0x2B30
    ctx->r7 = ADD32(ctx->r7, -0X2B30);
    // 0x800670C0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x800670C4: addiu       $v0, $a3, 0x38
    ctx->r2 = ADD32(ctx->r7, 0X38);
L_800670C8:
    // 0x800670C8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800670CC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800670D0: bgez        $a2, L_800670C8
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800670D4: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_800670C8;
    }
    // 0x800670D4: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800670D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800670DC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800670E0: lbu         $a0, -0x442C($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X442C);
    // 0x800670E4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800670E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800670EC: sw          $v0, -0x2AF4($at)
    MEM_W(-0X2AF4, ctx->r1) = ctx->r2;
    // 0x800670F0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800670F4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800670F8: sb          $v0, 0x0($sp)
    MEM_B(0X0, ctx->r29) = ctx->r2;
    // 0x800670FC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80067100: sb          $v0, 0x2($sp)
    MEM_B(0X2, ctx->r29) = ctx->r2;
    // 0x80067104: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80067108: sh          $v0, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r2;
    // 0x8006710C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80067110: sb          $v1, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r3;
    // 0x80067114: sb          $v1, 0x3($sp)
    MEM_B(0X3, ctx->r29) = ctx->r3;
    // 0x80067118: sb          $v0, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r2;
    // 0x8006711C: blez        $a0, L_8006715C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80067120: sb          $v0, 0x7($sp)
        MEM_B(0X7, ctx->r29) = ctx->r2;
            goto L_8006715C;
    }
    // 0x80067120: sb          $v0, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r2;
L_80067124:
    // 0x80067124: lwl         $v0, 0x0($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r29, 0X0);
    // 0x80067128: lwr         $v0, 0x3($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r29, 0X3);
    // 0x8006712C: lwl         $v1, 0x4($sp)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r29, 0X4);
    // 0x80067130: lwr         $v1, 0x7($sp)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r29, 0X7);
    // 0x80067134: swl         $v0, 0x0($a3)
    do_swl(rdram, 0X0, ctx->r7, ctx->r2);
    // 0x80067138: swr         $v0, 0x3($a3)
    do_swr(rdram, 0X3, ctx->r7, ctx->r2);
    // 0x8006713C: swl         $v1, 0x4($a3)
    do_swl(rdram, 0X4, ctx->r7, ctx->r3);
    // 0x80067140: swr         $v1, 0x7($a3)
    do_swr(rdram, 0X7, ctx->r7, ctx->r3);
    // 0x80067144: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80067148: lbu         $v0, -0x442C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X442C);
    // 0x8006714C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80067150: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80067154: bne         $v0, $zero, L_80067124
    if (ctx->r2 != 0) {
        // 0x80067158: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_80067124;
    }
    // 0x80067158: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_8006715C:
    // 0x8006715C: addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // 0x80067160: sb          $v0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r2;
    // 0x80067164: jr          $ra
    // 0x80067168: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80067168: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80067500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067500: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80067504: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80067508: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8006750C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80067510: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80067514: addiu       $v1, $zero, 0x1F
    ctx->r3 = ADD32(0, 0X1F);
    // 0x80067518: addiu       $v0, $sp, 0x37
    ctx->r2 = ADD32(ctx->r29, 0X37);
    // 0x8006751C: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
L_80067520:
    // 0x80067520: sb          $s1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r17;
    // 0x80067524: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80067528: bgez        $v1, L_80067520
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8006752C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80067520;
    }
    // 0x8006752C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80067530: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80067534: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80067538: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x8006753C: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // 0x80067540: jal         0x8006A8A0
    // 0x80067544: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    func_8006A8A0(rdram, ctx);
        goto after_0;
    // 0x80067544: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80067548: beql        $v0, $zero, L_80067550
    if (ctx->r2 == 0) {
        // 0x8006754C: sb          $s1, 0x65($s0)
        MEM_B(0X65, ctx->r16) = ctx->r17;
            goto L_80067550;
    }
    goto skip_0;
    // 0x8006754C: sb          $s1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r17;
    skip_0:
L_80067550:
    // 0x80067550: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x80067554: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80067558: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8006755C: jr          $ra
    // 0x80067560: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80067560: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80067710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800677D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80067A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067A20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80067A24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80067A28: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80067A2C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80067A30: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80067A34: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80067A38: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80067A3C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80067A40: jal         0x80069260
    // 0x80067A44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80069260(rdram, ctx);
        goto after_0;
    // 0x80067A44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80067A48: lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2);
    // 0x80067A4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80067A50: sh          $v0, -0x4710($at)
    MEM_H(-0X4710, ctx->r1) = ctx->r2;
    // 0x80067A54: bne         $v0, $zero, L_80067A68
    if (ctx->r2 != 0) {
        // 0x80067A58: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80067A68;
    }
    // 0x80067A58: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80067A5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80067A60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80067A64: sh          $v0, -0x4710($at)
    MEM_H(-0X4710, ctx->r1) = ctx->r2;
L_80067A68:
    // 0x80067A68: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    // 0x80067A6C: addiu       $s4, $zero, 0xD
    ctx->r20 = ADD32(0, 0XD);
    // 0x80067A70: addiu       $s3, $zero, 0xE
    ctx->r19 = ADD32(0, 0XE);
L_80067A74:
    // 0x80067A74: lw          $a0, 0xC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XC);
    // 0x80067A78: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80067A7C: jal         0x800619A0
    // 0x80067A80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80067A80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80067A84: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80067A88: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80067A8C: beq         $v0, $s4, L_80067AA4
    if (ctx->r2 == ctx->r20) {
        // 0x80067A90: nop
    
            goto L_80067AA4;
    }
    // 0x80067A90: nop

    // 0x80067A94: beq         $v0, $s3, L_80067B88
    if (ctx->r2 == ctx->r19) {
        // 0x80067A98: nop
    
            goto L_80067B88;
    }
    // 0x80067A98: nop

    // 0x80067A9C: j           L_80067A74
    // 0x80067AA0: nop

        goto L_80067A74;
    // 0x80067AA0: nop

L_80067AA4:
    // 0x80067AA4: jal         0x80067BC0
    // 0x80067AA8: nop

    func_80067BC0(rdram, ctx);
        goto after_2;
    // 0x80067AA8: nop

    after_2:
    // 0x80067AAC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80067AB0: lhu         $v0, -0x4710($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4710);
    // 0x80067AB4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80067AB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80067ABC: sh          $v0, -0x4710($at)
    MEM_H(-0X4710, ctx->r1) = ctx->r2;
    // 0x80067AC0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80067AC4: bne         $v0, $zero, L_80067AF8
    if (ctx->r2 != 0) {
        // 0x80067AC8: nop
    
            goto L_80067AF8;
    }
    // 0x80067AC8: nop

    // 0x80067ACC: jal         0x80069260
    // 0x80067AD0: nop

    func_80069260(rdram, ctx);
        goto after_3;
    // 0x80067AD0: nop

    after_3:
    // 0x80067AD4: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x80067AD8: beq         $a0, $zero, L_80067AEC
    if (ctx->r4 == 0) {
        // 0x80067ADC: addu        $s0, $v0, $zero
        ctx->r16 = ADD32(ctx->r2, 0);
            goto L_80067AEC;
    }
    // 0x80067ADC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80067AE0: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x80067AE4: jal         0x80061AD0
    // 0x80067AE8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80067AE8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_4:
L_80067AEC:
    // 0x80067AEC: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x80067AF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80067AF4: sh          $v0, -0x4710($at)
    MEM_H(-0X4710, ctx->r1) = ctx->r2;
L_80067AF8:
    // 0x80067AF8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80067AFC: lw          $v0, 0x2A88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2A88);
    // 0x80067B00: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80067B04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80067B08: beq         $s1, $zero, L_80067B34
    if (ctx->r17 == 0) {
        // 0x80067B0C: sw          $v0, 0x2A88($at)
        MEM_W(0X2A88, ctx->r1) = ctx->r2;
            goto L_80067B34;
    }
    // 0x80067B0C: sw          $v0, 0x2A88($at)
    MEM_W(0X2A88, ctx->r1) = ctx->r2;
    // 0x80067B10: jal         0x80068AC0
    // 0x80067B14: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    osGetCount_recomp(rdram, ctx);
        goto after_5;
    // 0x80067B14: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    after_5:
    // 0x80067B18: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80067B1C: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x80067B20: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80067B24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80067B28: sw          $v0, -0x4328($at)
    MEM_W(-0X4328, ctx->r1) = ctx->r2;
    // 0x80067B2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80067B30: sw          $v1, -0x4324($at)
    MEM_W(-0X4324, ctx->r1) = ctx->r3;
L_80067B34:
    // 0x80067B34: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x80067B38: jal         0x80068AC0
    // 0x80067B3C: lw          $s0, -0x33D4($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X33D4);
    osGetCount_recomp(rdram, ctx);
        goto after_6;
    // 0x80067B3C: lw          $s0, -0x33D4($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X33D4);
    after_6:
    // 0x80067B40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80067B44: sw          $v0, -0x33D4($at)
    MEM_W(-0X33D4, ctx->r1) = ctx->r2;
    // 0x80067B48: subu        $s0, $v0, $s0
    ctx->r16 = SUB32(ctx->r2, ctx->r16);
    // 0x80067B4C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80067B50: lw          $v0, -0x4328($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4328);
    // 0x80067B54: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80067B58: lw          $v1, -0x4324($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4324);
    // 0x80067B5C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80067B60: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80067B64: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80067B68: sltu        $a2, $v1, $a1
    ctx->r6 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x80067B6C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80067B70: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80067B74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80067B78: sw          $v0, -0x4328($at)
    MEM_W(-0X4328, ctx->r1) = ctx->r2;
    // 0x80067B7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80067B80: j           L_80067A74
    // 0x80067B84: sw          $v1, -0x4324($at)
    MEM_W(-0X4324, ctx->r1) = ctx->r3;
        goto L_80067A74;
    // 0x80067B84: sw          $v1, -0x4324($at)
    MEM_W(-0X4324, ctx->r1) = ctx->r3;
L_80067B88:
    // 0x80067B88: jal         0x80061ED4
    // 0x80067B8C: nop

    func_80061ED4(rdram, ctx);
        goto after_7;
    // 0x80067B8C: nop

    after_7:
    // 0x80067B90: j           L_80067A74
    // 0x80067B94: nop

        goto L_80067A74;
    // 0x80067B94: nop

    // 0x80067B98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80067B9C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80067BA0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80067BA4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80067BA8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80067BAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80067BB0: jr          $ra
    // 0x80067BB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80067BB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80067BC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80067ED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067ED0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067ED4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80067ED8: jal         0x80069020
    // 0x80067EDC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    __osSpSetPc_recomp(rdram, ctx);
        goto after_0;
    // 0x80067EDC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // 0x80067EE0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80067EE4: jr          $ra
    // 0x80067EE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80067EE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80067EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8006847C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8006856C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80068674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068674: addu        $t9, $a0, $zero
    ctx->r25 = ADD32(ctx->r4, 0);
    // 0x80068678: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8006867C: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80068680: lw          $t6, 0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X4);
    // 0x80068684: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80068688: bne         $at, $zero, L_800686A8
    if (ctx->r1 != 0) {
        // 0x8006868C: nop
    
            goto L_800686A8;
    }
    // 0x8006868C: nop

L_80068690:
    // 0x80068690: addu        $t9, $t8, $zero
    ctx->r25 = ADD32(ctx->r24, 0);
    // 0x80068694: lw          $t8, 0x0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X0);
    // 0x80068698: lw          $t6, 0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X4);
    // 0x8006869C: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800686A0: beq         $at, $zero, L_80068690
    if (ctx->r1 == 0) {
        // 0x800686A4: nop
    
            goto L_80068690;
    }
    // 0x800686A4: nop

L_800686A8:
    // 0x800686A8: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800686AC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800686B0: sw          $a1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r5;
    // 0x800686B4: jr          $ra
    // 0x800686B8: sw          $a0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r4;
    return;
    // 0x800686B8: sw          $a0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r4;
;}
RECOMP_FUNC void func_800686BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800686BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800686C0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800686C4: jr          $ra
    // 0x800686C8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    return;
    // 0x800686C8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_800686CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void sqrtf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068AB0: jr          $ra
    // 0x80068AB4: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    return;
    // 0x80068AB4: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
;}
RECOMP_FUNC void func_80068B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80068BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80068BF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068BF0: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80068BF4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x80068BF8: jr          $ra
    // 0x80068BFC: nop

    return;
    // 0x80068BFC: nop

;}
RECOMP_FUNC void func_80068C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068C00: mtc0        $a0, Status
    cop0_status_write(ctx, ctx->r4);    // 0x80068C04: nop

    // 0x80068C08: jr          $ra
    // 0x80068C0C: nop

    return;
    // 0x80068C0C: nop

;}
RECOMP_FUNC void func_80068C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80068FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80068FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80069000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80069010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80069050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80069150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80069260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069260: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80069264: jr          $ra
    // 0x80069268: lw          $v0, -0x7F10($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7F10);
    return;
    // 0x80069268: lw          $v0, -0x7F10($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7F10);
;}
RECOMP_FUNC void func_80069270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069270: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80069274: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80069278: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8006927C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80069280: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80069284: andi        $v0, $s0, 0x3
    ctx->r2 = ctx->r16 & 0X3;
    // 0x80069288: beq         $v0, $zero, L_800692A8
    if (ctx->r2 == 0) {
        // 0x8006928C: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_800692A8;
    }
    // 0x8006928C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80069290: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80069294: addiu       $a0, $a0, -0xC60
    ctx->r4 = ADD32(ctx->r4, -0XC60);
    // 0x80069298: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8006929C: addiu       $a1, $a1, -0xC5C
    ctx->r5 = ADD32(ctx->r5, -0XC5C);
    // 0x800692A0: jal         0x800621E0
    // 0x800692A4: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    func_800621E0(rdram, ctx);
        goto after_0;
    // 0x800692A4: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    after_0:
L_800692A8:
    // 0x800692A8: bne         $s1, $zero, L_800692C8
    if (ctx->r17 != 0) {
        // 0x800692AC: nop
    
            goto L_800692C8;
    }
    // 0x800692AC: nop

    // 0x800692B0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800692B4: addiu       $a0, $a0, -0xC60
    ctx->r4 = ADD32(ctx->r4, -0XC60);
    // 0x800692B8: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800692BC: addiu       $a1, $a1, -0xC5C
    ctx->r5 = ADD32(ctx->r5, -0XC5C);
    // 0x800692C0: jal         0x800621E0
    // 0x800692C4: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    func_800621E0(rdram, ctx);
        goto after_1;
    // 0x800692C4: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    after_1:
L_800692C8:
    // 0x800692C8: jal         0x8006AEA0
    // 0x800692CC: nop

    func_8006AEA0(rdram, ctx);
        goto after_2;
    // 0x800692CC: nop

    after_2:
    // 0x800692D0: bne         $v0, $zero, L_800692EC
    if (ctx->r2 != 0) {
        // 0x800692D4: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800692EC;
    }
    // 0x800692D4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800692D8: lui         $v0, 0xA000
    ctx->r2 = S32(0XA000 << 16);
    // 0x800692DC: or          $v0, $s0, $v0
    ctx->r2 = ctx->r16 | ctx->r2;
    // 0x800692E0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800692E4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800692E8: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
L_800692EC:
    // 0x800692EC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800692F0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800692F4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800692F8: jr          $ra
    // 0x800692FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800692FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80069300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069300: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80069304: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80069308: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8006930C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80069310: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80069314: andi        $v0, $s0, 0x3
    ctx->r2 = ctx->r16 & 0X3;
    // 0x80069318: beq         $v0, $zero, L_80069338
    if (ctx->r2 == 0) {
        // 0x8006931C: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_80069338;
    }
    // 0x8006931C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80069320: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80069324: addiu       $a0, $a0, -0xC50
    ctx->r4 = ADD32(ctx->r4, -0XC50);
    // 0x80069328: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8006932C: addiu       $a1, $a1, -0xC4C
    ctx->r5 = ADD32(ctx->r5, -0XC4C);
    // 0x80069330: jal         0x800621E0
    // 0x80069334: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    func_800621E0(rdram, ctx);
        goto after_0;
    // 0x80069334: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    after_0:
L_80069338:
    // 0x80069338: jal         0x8006AEA0
    // 0x8006933C: nop

    func_8006AEA0(rdram, ctx);
        goto after_1;
    // 0x8006933C: nop

    after_1:
    // 0x80069340: bnel        $v0, $zero, L_80069358
    if (ctx->r2 != 0) {
        // 0x80069344: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80069358;
    }
    goto skip_0;
    // 0x80069344: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
    // 0x80069348: lui         $v0, 0xA000
    ctx->r2 = S32(0XA000 << 16);
    // 0x8006934C: or          $v0, $s0, $v0
    ctx->r2 = ctx->r16 | ctx->r2;
    // 0x80069350: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x80069354: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80069358:
    // 0x80069358: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8006935C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80069360: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80069364: jr          $ra
    // 0x80069368: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80069368: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80069370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80069378: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006937C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80069380: addiu       $s0, $s0, 0x7CC8
    ctx->r16 = ADD32(ctx->r16, 0X7CC8);
    // 0x80069384: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80069388: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8006938C: addiu       $a1, $a1, -0x34F0
    ctx->r5 = ADD32(ctx->r5, -0X34F0);
    // 0x80069390: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069394: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80069398: sw          $v0, -0x7F00($at)
    MEM_W(-0X7F00, ctx->r1) = ctx->r2;
    // 0x8006939C: jal         0x80061740
    // 0x800693A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800693A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800693A4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800693A8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800693AC: jal         0x80061AD0
    // 0x800693B0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800693B0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x800693B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800693B8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800693BC: jr          $ra
    // 0x800693C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800693C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800693C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800693C4: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800693C8: lw          $v0, -0x7F00($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7F00);
    // 0x800693CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800693D0: bne         $v0, $zero, L_80069410
    if (ctx->r2 != 0) {
        // 0x800693D4: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_80069410;
    }
    // 0x800693D4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800693D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800693DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800693E0: sw          $v0, -0x7F00($at)
    MEM_W(-0X7F00, ctx->r1) = ctx->r2;
    // 0x800693E4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800693E8: addiu       $a0, $a0, 0x7CC8
    ctx->r4 = ADD32(ctx->r4, 0X7CC8);
    // 0x800693EC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800693F0: addiu       $a1, $a1, -0x34F0
    ctx->r5 = ADD32(ctx->r5, -0X34F0);
    // 0x800693F4: jal         0x80061740
    // 0x800693F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800693F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800693FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80069400: addiu       $a0, $a0, 0x7CC8
    ctx->r4 = ADD32(ctx->r4, 0X7CC8);
    // 0x80069404: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80069408: jal         0x80061AD0
    // 0x8006940C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8006940C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
L_80069410:
    // 0x80069410: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80069414: addiu       $a0, $a0, 0x7CC8
    ctx->r4 = ADD32(ctx->r4, 0X7CC8);
    // 0x80069418: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8006941C: jal         0x800619A0
    // 0x80069420: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80069420: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80069424: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80069428: jr          $ra
    // 0x8006942C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006942C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80069430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069430: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069434: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80069438: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006943C: addiu       $a0, $a0, 0x7CC8
    ctx->r4 = ADD32(ctx->r4, 0X7CC8);
    // 0x80069440: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80069444: jal         0x80061AD0
    // 0x80069448: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80069448: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x8006944C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80069450: jr          $ra
    // 0x80069454: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80069454: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80069460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80069500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800695D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800695D0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800695D4: lw          $v1, 0x6E70($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6E70);
    // 0x800695D8: beq         $v1, $zero, L_800695E8
    if (ctx->r3 == 0) {
        // 0x800695DC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800695E8;
    }
    // 0x800695DC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800695E0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800695E4: lw          $v0, 0x6E78($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E78);
L_800695E8:
    // 0x800695E8: jr          $ra
    // 0x800695EC: nop

    return;
    // 0x800695EC: nop

;}
RECOMP_FUNC void func_800697C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80069B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069B80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069B84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80069B88: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80069B8C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80069B90: addiu       $s0, $s0, -0x42B8
    ctx->r16 = ADD32(ctx->r16, -0X42B8);
    // 0x80069B94: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80069B98: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80069B9C: addiu       $a1, $a1, -0x34E0
    ctx->r5 = ADD32(ctx->r5, -0X34E0);
    // 0x80069BA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069BA4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80069BA8: sw          $v0, -0x7E00($at)
    MEM_W(-0X7E00, ctx->r1) = ctx->r2;
    // 0x80069BAC: jal         0x80061740
    // 0x80069BB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80069BB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80069BB4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80069BB8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80069BBC: jal         0x80061AD0
    // 0x80069BC0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80069BC0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x80069BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069BC8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80069BCC: jr          $ra
    // 0x80069BD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80069BD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80069BD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069BD4: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80069BD8: lw          $v0, -0x7E00($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7E00);
    // 0x80069BDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80069BE0: bne         $v0, $zero, L_80069C20
    if (ctx->r2 != 0) {
        // 0x80069BE4: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_80069C20;
    }
    // 0x80069BE4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80069BE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80069BEC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80069BF0: sw          $v0, -0x7E00($at)
    MEM_W(-0X7E00, ctx->r1) = ctx->r2;
    // 0x80069BF4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80069BF8: addiu       $a0, $a0, -0x42B8
    ctx->r4 = ADD32(ctx->r4, -0X42B8);
    // 0x80069BFC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80069C00: addiu       $a1, $a1, -0x34E0
    ctx->r5 = ADD32(ctx->r5, -0X34E0);
    // 0x80069C04: jal         0x80061740
    // 0x80069C08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80069C08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80069C0C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80069C10: addiu       $a0, $a0, -0x42B8
    ctx->r4 = ADD32(ctx->r4, -0X42B8);
    // 0x80069C14: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80069C18: jal         0x80061AD0
    // 0x80069C1C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80069C1C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
L_80069C20:
    // 0x80069C20: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80069C24: addiu       $a0, $a0, -0x42B8
    ctx->r4 = ADD32(ctx->r4, -0X42B8);
    // 0x80069C28: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80069C2C: jal         0x800619A0
    // 0x80069C30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80069C30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80069C34: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80069C38: jr          $ra
    // 0x80069C3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80069C3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80069C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069C40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069C44: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80069C48: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80069C4C: addiu       $a0, $a0, -0x42B8
    ctx->r4 = ADD32(ctx->r4, -0X42B8);
    // 0x80069C50: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80069C54: jal         0x80061AD0
    // 0x80069C58: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80069C58: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x80069C5C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80069C60: jr          $ra
    // 0x80069C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80069C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80069C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069C70: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80069C74: sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // 0x80069C78: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x80069C7C: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x80069C80: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x80069C84: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x80069C88: sw          $s5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r21;
    // 0x80069C8C: lui         $s5, 0x800B
    ctx->r21 = S32(0X800B << 16);
    // 0x80069C90: addiu       $s5, $s5, -0xC08
    ctx->r21 = ADD32(ctx->r21, -0XC08);
    // 0x80069C94: sw          $ra, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r31;
    // 0x80069C98: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x80069C9C: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x80069CA0: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x80069CA4: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x80069CA8: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_80069CAC:
    // 0x80069CAC: lbu         $s1, 0x0($a1)
    ctx->r17 = MEM_BU(ctx->r5, 0X0);
    // 0x80069CB0: j           L_80069CBC
    // 0x80069CB4: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
        goto L_80069CBC;
    // 0x80069CB4: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
L_80069CB8:
    // 0x80069CB8: lbu         $s1, 0x0($s2)
    ctx->r17 = MEM_BU(ctx->r18, 0X0);
L_80069CBC:
    // 0x80069CBC: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x80069CC0: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x80069CC4: xori        $v0, $v0, 0x25
    ctx->r2 = ctx->r2 ^ 0X25;
    // 0x80069CC8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80069CCC: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80069CD0: bnel        $v1, $zero, L_80069CB8
    if (ctx->r3 != 0) {
        // 0x80069CD4: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80069CB8;
    }
    goto skip_0;
    // 0x80069CD4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80069CD8: subu        $s0, $s2, $a1
    ctx->r16 = SUB32(ctx->r18, ctx->r5);
    // 0x80069CDC: blez        $s0, L_80069D04
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80069CE0: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_80069D04;
    }
    // 0x80069CE0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80069CE4: jalr        $s4
    // 0x80069CE8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_0;
    // 0x80069CE8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80069CEC: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80069CF0: beq         $s3, $zero, L_8006A1B8
    if (ctx->r19 == 0) {
        // 0x80069CF4: nop
    
            goto L_8006A1B8;
    }
    // 0x80069CF4: nop

    // 0x80069CF8: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80069CFC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80069D00: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_80069D04:
    // 0x80069D04: beq         $s1, $zero, L_8006A1B8
    if (ctx->r17 == 0) {
        // 0x80069D08: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8006A1B8;
    }
    // 0x80069D08: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80069D0C: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80069D10: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x80069D14: addiu       $s0, $s0, -0xC00
    ctx->r16 = ADD32(ctx->r16, -0XC00);
L_80069D18:
    // 0x80069D18: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x80069D1C: jal         0x80066C10
    // 0x80069D20: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    strchr_recomp(rdram, ctx);
        goto after_1;
    // 0x80069D20: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_1:
    // 0x80069D24: beq         $v0, $zero, L_80069D4C
    if (ctx->r2 == 0) {
        // 0x80069D28: subu        $v0, $v0, $s5
        ctx->r2 = SUB32(ctx->r2, ctx->r21);
            goto L_80069D4C;
    }
    // 0x80069D28: subu        $v0, $v0, $s5
    ctx->r2 = SUB32(ctx->r2, ctx->r21);
    // 0x80069D2C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80069D30: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80069D34: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80069D38: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80069D3C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80069D40: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80069D44: j           L_80069D18
    // 0x80069D48: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
        goto L_80069D18;
    // 0x80069D48: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
L_80069D4C:
    // 0x80069D4C: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
    // 0x80069D50: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x80069D54: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x80069D58: bne         $v1, $v0, L_80069DA0
    if (ctx->r3 != ctx->r2) {
        // 0x80069D5C: addiu       $v0, $a0, -0x30
        ctx->r2 = ADD32(ctx->r4, -0X30);
            goto L_80069DA0;
    }
    // 0x80069D5C: addiu       $v0, $a0, -0x30
    ctx->r2 = ADD32(ctx->r4, -0X30);
    // 0x80069D60: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x80069D64: addiu       $v1, $zero, -0x4
    ctx->r3 = ADD32(0, -0X4);
    // 0x80069D68: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x80069D6C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80069D70: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x80069D74: sw          $v1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r3;
    // 0x80069D78: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80069D7C: bgez        $v0, L_80069D98
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80069D80: sw          $v0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r2;
            goto L_80069D98;
    }
    // 0x80069D80: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80069D84: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80069D88: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80069D8C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80069D90: ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
    // 0x80069D94: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
L_80069D98:
    // 0x80069D98: j           L_80069DF0
    // 0x80069D9C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80069DF0;
    // 0x80069D9C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80069DA0:
    // 0x80069DA0: sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // 0x80069DA4: beq         $v0, $zero, L_80069DF0
    if (ctx->r2 == 0) {
        // 0x80069DA8: sw          $zero, 0x38($sp)
        MEM_W(0X38, ctx->r29) = 0;
            goto L_80069DF0;
    }
    // 0x80069DA8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_80069DAC:
    // 0x80069DAC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80069DB0: slti        $v0, $a0, 0x3E7
    ctx->r2 = SIGNED(ctx->r4) < 0X3E7 ? 1 : 0;
    // 0x80069DB4: beql        $v0, $zero, L_80069DDC
    if (ctx->r2 == 0) {
        // 0x80069DB8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80069DDC;
    }
    goto skip_1;
    // 0x80069DB8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x80069DBC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80069DC0: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x80069DC4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80069DC8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80069DCC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80069DD0: addiu       $v0, $v0, -0x30
    ctx->r2 = ADD32(ctx->r2, -0X30);
    // 0x80069DD4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80069DD8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80069DDC:
    // 0x80069DDC: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x80069DE0: addiu       $v0, $v0, -0x30
    ctx->r2 = ADD32(ctx->r2, -0X30);
    // 0x80069DE4: sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // 0x80069DE8: bne         $v0, $zero, L_80069DAC
    if (ctx->r2 != 0) {
        // 0x80069DEC: nop
    
            goto L_80069DAC;
    }
    // 0x80069DEC: nop

L_80069DF0:
    // 0x80069DF0: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x80069DF4: addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
    // 0x80069DF8: beq         $v1, $v0, L_80069E08
    if (ctx->r3 == ctx->r2) {
        // 0x80069DFC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80069E08;
    }
    // 0x80069DFC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80069E00: j           L_80069E98
    // 0x80069E04: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
        goto L_80069E98;
    // 0x80069E04: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_80069E08:
    // 0x80069E08: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80069E0C: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
    // 0x80069E10: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x80069E14: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x80069E18: bne         $v1, $v0, L_80069E48
    if (ctx->r3 != ctx->r2) {
        // 0x80069E1C: addiu       $v0, $a0, -0x30
        ctx->r2 = ADD32(ctx->r4, -0X30);
            goto L_80069E48;
    }
    // 0x80069E1C: addiu       $v0, $a0, -0x30
    ctx->r2 = ADD32(ctx->r4, -0X30);
    // 0x80069E20: lw          $v1, 0x94($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X94);
    // 0x80069E24: addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
    // 0x80069E28: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // 0x80069E2C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80069E30: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    // 0x80069E34: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x80069E38: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80069E3C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80069E40: j           L_80069E98
    // 0x80069E44: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
        goto L_80069E98;
    // 0x80069E44: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_80069E48:
    // 0x80069E48: sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // 0x80069E4C: beq         $v0, $zero, L_80069E98
    if (ctx->r2 == 0) {
        // 0x80069E50: sw          $zero, 0x34($sp)
        MEM_W(0X34, ctx->r29) = 0;
            goto L_80069E98;
    }
    // 0x80069E50: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80069E54:
    // 0x80069E54: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80069E58: slti        $v0, $a0, 0x3E7
    ctx->r2 = SIGNED(ctx->r4) < 0X3E7 ? 1 : 0;
    // 0x80069E5C: beql        $v0, $zero, L_80069E84
    if (ctx->r2 == 0) {
        // 0x80069E60: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80069E84;
    }
    goto skip_2;
    // 0x80069E60: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
    // 0x80069E64: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80069E68: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x80069E6C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80069E70: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80069E74: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80069E78: addiu       $v0, $v0, -0x30
    ctx->r2 = ADD32(ctx->r2, -0X30);
    // 0x80069E7C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80069E80: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80069E84:
    // 0x80069E84: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x80069E88: addiu       $v0, $v0, -0x30
    ctx->r2 = ADD32(ctx->r2, -0X30);
    // 0x80069E8C: sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // 0x80069E90: bne         $v0, $zero, L_80069E54
    if (ctx->r2 != 0) {
        // 0x80069E94: nop
    
            goto L_80069E54;
    }
    // 0x80069E94: nop

L_80069E98:
    // 0x80069E98: lbu         $s0, 0x0($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X0);
    // 0x80069E9C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80069EA0: addiu       $a0, $a0, -0xBE8
    ctx->r4 = ADD32(ctx->r4, -0XBE8);
    // 0x80069EA4: jal         0x80066C10
    // 0x80069EA8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    strchr_recomp(rdram, ctx);
        goto after_2;
    // 0x80069EA8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80069EAC: beq         $v0, $zero, L_80069EBC
    if (ctx->r2 == 0) {
        // 0x80069EB0: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_80069EBC;
    }
    // 0x80069EB0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80069EB4: j           L_80069EC0
    // 0x80069EB8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80069EC0;
    // 0x80069EB8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80069EBC:
    // 0x80069EBC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80069EC0:
    // 0x80069EC0: sb          $a1, 0x44($sp)
    MEM_B(0X44, ctx->r29) = ctx->r5;
    // 0x80069EC4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80069EC8: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    // 0x80069ECC: bne         $a1, $v0, L_80069EEC
    if (ctx->r5 != ctx->r2) {
        // 0x80069ED0: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_80069EEC;
    }
    // 0x80069ED0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x80069ED4: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x80069ED8: bne         $v0, $a1, L_80069EEC
    if (ctx->r2 != ctx->r5) {
        // 0x80069EDC: addiu       $v0, $zero, 0x4C
        ctx->r2 = ADD32(0, 0X4C);
            goto L_80069EEC;
    }
    // 0x80069EDC: addiu       $v0, $zero, 0x4C
    ctx->r2 = ADD32(0, 0X4C);
    // 0x80069EE0: sb          $v0, 0x44($sp)
    MEM_B(0X44, ctx->r29) = ctx->r2;
    // 0x80069EE4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80069EE8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80069EEC:
    // 0x80069EEC: lbu         $a2, 0x0($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X0);
    // 0x80069EF0: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x80069EF4: jal         0x8006A1E0
    // 0x80069EF8: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    func_8006A1E0(rdram, ctx);
        goto after_3;
    // 0x80069EF8: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    after_3:
    // 0x80069EFC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80069F00: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80069F04: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80069F08: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80069F0C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80069F10: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80069F14: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80069F18: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80069F1C: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80069F20: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80069F24: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80069F28: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80069F2C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80069F30: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x80069F34: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80069F38: bne         $v0, $zero, L_80069F98
    if (ctx->r2 != 0) {
        // 0x80069F3C: sw          $a1, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r5;
            goto L_80069F98;
    }
    // 0x80069F3C: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x80069F40: blez        $a1, L_80069F98
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80069F44: nop
    
            goto L_80069F98;
    }
    // 0x80069F44: nop

    // 0x80069F48: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80069F4C: sltiu       $v0, $s1, 0x21
    ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
L_80069F50:
    // 0x80069F50: beq         $v0, $zero, L_80069F5C
    if (ctx->r2 == 0) {
        // 0x80069F54: addiu       $s0, $zero, 0x20
        ctx->r16 = ADD32(0, 0X20);
            goto L_80069F5C;
    }
    // 0x80069F54: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
    // 0x80069F58: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_80069F5C:
    // 0x80069F5C: blezl       $s0, L_80069F90
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80069F60: subu        $s1, $s1, $s0
        ctx->r17 = SUB32(ctx->r17, ctx->r16);
            goto L_80069F90;
    }
    goto skip_3;
    // 0x80069F60: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    skip_3:
    // 0x80069F64: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80069F68: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80069F6C: addiu       $a1, $a1, -0x7DF0
    ctx->r5 = ADD32(ctx->r5, -0X7DF0);
    // 0x80069F70: jalr        $s4
    // 0x80069F74: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_4;
    // 0x80069F74: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_4:
    // 0x80069F78: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80069F7C: beq         $s3, $zero, L_8006A1B8
    if (ctx->r19 == 0) {
        // 0x80069F80: subu        $s1, $s1, $s0
        ctx->r17 = SUB32(ctx->r17, ctx->r16);
            goto L_8006A1B8;
    }
    // 0x80069F80: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80069F84: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80069F88: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80069F8C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_80069F90:
    // 0x80069F90: bgtz        $s1, L_80069F50
    if (SIGNED(ctx->r17) > 0) {
        // 0x80069F94: sltiu       $v0, $s1, 0x21
        ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80069F50;
    }
    // 0x80069F94: sltiu       $v0, $s1, 0x21
    ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
L_80069F98:
    // 0x80069F98: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80069F9C: blez        $a2, L_80069FC8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80069FA0: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_80069FC8;
    }
    // 0x80069FA0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80069FA4: jalr        $s4
    // 0x80069FA8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_5;
    // 0x80069FA8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_5:
    // 0x80069FAC: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80069FB0: beq         $s3, $zero, L_8006A1B8
    if (ctx->r19 == 0) {
        // 0x80069FB4: nop
    
            goto L_8006A1B8;
    }
    // 0x80069FB4: nop

    // 0x80069FB8: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80069FBC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80069FC0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80069FC4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_80069FC8:
    // 0x80069FC8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80069FCC: blez        $v0, L_8006A024
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80069FD0: nop
    
            goto L_8006A024;
    }
    // 0x80069FD0: nop

    // 0x80069FD4: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80069FD8: sltiu       $v0, $s1, 0x21
    ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
L_80069FDC:
    // 0x80069FDC: beq         $v0, $zero, L_80069FE8
    if (ctx->r2 == 0) {
        // 0x80069FE0: addiu       $s0, $zero, 0x20
        ctx->r16 = ADD32(0, 0X20);
            goto L_80069FE8;
    }
    // 0x80069FE0: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
    // 0x80069FE4: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_80069FE8:
    // 0x80069FE8: blezl       $s0, L_8006A01C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80069FEC: subu        $s1, $s1, $s0
        ctx->r17 = SUB32(ctx->r17, ctx->r16);
            goto L_8006A01C;
    }
    goto skip_4;
    // 0x80069FEC: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    skip_4:
    // 0x80069FF0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80069FF4: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80069FF8: addiu       $a1, $a1, -0x7DCC
    ctx->r5 = ADD32(ctx->r5, -0X7DCC);
    // 0x80069FFC: jalr        $s4
    // 0x8006A000: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_6;
    // 0x8006A000: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_6:
    // 0x8006A004: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8006A008: beq         $s3, $zero, L_8006A1B8
    if (ctx->r19 == 0) {
        // 0x8006A00C: subu        $s1, $s1, $s0
        ctx->r17 = SUB32(ctx->r17, ctx->r16);
            goto L_8006A1B8;
    }
    // 0x8006A00C: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8006A010: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8006A014: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8006A018: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_8006A01C:
    // 0x8006A01C: bgtz        $s1, L_80069FDC
    if (SIGNED(ctx->r17) > 0) {
        // 0x8006A020: sltiu       $v0, $s1, 0x21
        ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80069FDC;
    }
    // 0x8006A020: sltiu       $v0, $s1, 0x21
    ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
L_8006A024:
    // 0x8006A024: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8006A028: blez        $a2, L_8006A058
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8006A02C: nop
    
            goto L_8006A058;
    }
    // 0x8006A02C: nop

    // 0x8006A030: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006A034: jalr        $s4
    // 0x8006A038: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_7;
    // 0x8006A038: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_7:
    // 0x8006A03C: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8006A040: beq         $s3, $zero, L_8006A1B8
    if (ctx->r19 == 0) {
        // 0x8006A044: nop
    
            goto L_8006A1B8;
    }
    // 0x8006A044: nop

    // 0x8006A048: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8006A04C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8006A050: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006A054: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_8006A058:
    // 0x8006A058: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8006A05C: blez        $v0, L_8006A0B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8006A060: nop
    
            goto L_8006A0B4;
    }
    // 0x8006A060: nop

    // 0x8006A064: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8006A068: sltiu       $v0, $s1, 0x21
    ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
L_8006A06C:
    // 0x8006A06C: beq         $v0, $zero, L_8006A078
    if (ctx->r2 == 0) {
        // 0x8006A070: addiu       $s0, $zero, 0x20
        ctx->r16 = ADD32(0, 0X20);
            goto L_8006A078;
    }
    // 0x8006A070: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
    // 0x8006A074: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_8006A078:
    // 0x8006A078: blezl       $s0, L_8006A0AC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8006A07C: subu        $s1, $s1, $s0
        ctx->r17 = SUB32(ctx->r17, ctx->r16);
            goto L_8006A0AC;
    }
    goto skip_5;
    // 0x8006A07C: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    skip_5:
    // 0x8006A080: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8006A084: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8006A088: addiu       $a1, $a1, -0x7DCC
    ctx->r5 = ADD32(ctx->r5, -0X7DCC);
    // 0x8006A08C: jalr        $s4
    // 0x8006A090: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_8;
    // 0x8006A090: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_8:
    // 0x8006A094: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8006A098: beq         $s3, $zero, L_8006A1B8
    if (ctx->r19 == 0) {
        // 0x8006A09C: subu        $s1, $s1, $s0
        ctx->r17 = SUB32(ctx->r17, ctx->r16);
            goto L_8006A1B8;
    }
    // 0x8006A09C: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8006A0A0: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8006A0A4: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8006A0A8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_8006A0AC:
    // 0x8006A0AC: bgtz        $s1, L_8006A06C
    if (SIGNED(ctx->r17) > 0) {
        // 0x8006A0B0: sltiu       $v0, $s1, 0x21
        ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_8006A06C;
    }
    // 0x8006A0B0: sltiu       $v0, $s1, 0x21
    ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
L_8006A0B4:
    // 0x8006A0B4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8006A0B8: blez        $a2, L_8006A0EC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8006A0BC: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_8006A0EC;
    }
    // 0x8006A0BC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8006A0C0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8006A0C4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8006A0C8: jalr        $s4
    // 0x8006A0CC: addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_9;
    // 0x8006A0CC: addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    after_9:
    // 0x8006A0D0: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8006A0D4: beq         $s3, $zero, L_8006A1B8
    if (ctx->r19 == 0) {
        // 0x8006A0D8: nop
    
            goto L_8006A1B8;
    }
    // 0x8006A0D8: nop

    // 0x8006A0DC: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8006A0E0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8006A0E4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006A0E8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_8006A0EC:
    // 0x8006A0EC: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8006A0F0: blez        $v0, L_8006A148
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8006A0F4: nop
    
            goto L_8006A148;
    }
    // 0x8006A0F4: nop

    // 0x8006A0F8: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8006A0FC: sltiu       $v0, $s1, 0x21
    ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
L_8006A100:
    // 0x8006A100: beq         $v0, $zero, L_8006A10C
    if (ctx->r2 == 0) {
        // 0x8006A104: addiu       $s0, $zero, 0x20
        ctx->r16 = ADD32(0, 0X20);
            goto L_8006A10C;
    }
    // 0x8006A104: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
    // 0x8006A108: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_8006A10C:
    // 0x8006A10C: blezl       $s0, L_8006A140
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8006A110: subu        $s1, $s1, $s0
        ctx->r17 = SUB32(ctx->r17, ctx->r16);
            goto L_8006A140;
    }
    goto skip_6;
    // 0x8006A110: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    skip_6:
    // 0x8006A114: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8006A118: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8006A11C: addiu       $a1, $a1, -0x7DCC
    ctx->r5 = ADD32(ctx->r5, -0X7DCC);
    // 0x8006A120: jalr        $s4
    // 0x8006A124: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_10;
    // 0x8006A124: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_10:
    // 0x8006A128: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8006A12C: beq         $s3, $zero, L_8006A1B8
    if (ctx->r19 == 0) {
        // 0x8006A130: subu        $s1, $s1, $s0
        ctx->r17 = SUB32(ctx->r17, ctx->r16);
            goto L_8006A1B8;
    }
    // 0x8006A130: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8006A134: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8006A138: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8006A13C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_8006A140:
    // 0x8006A140: bgtz        $s1, L_8006A100
    if (SIGNED(ctx->r17) > 0) {
        // 0x8006A144: sltiu       $v0, $s1, 0x21
        ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_8006A100;
    }
    // 0x8006A144: sltiu       $v0, $s1, 0x21
    ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
L_8006A148:
    // 0x8006A148: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8006A14C: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x8006A150: beq         $v0, $zero, L_80069CAC
    if (ctx->r2 == 0) {
        // 0x8006A154: addiu       $a1, $s2, 0x1
        ctx->r5 = ADD32(ctx->r18, 0X1);
            goto L_80069CAC;
    }
    // 0x8006A154: addiu       $a1, $s2, 0x1
    ctx->r5 = ADD32(ctx->r18, 0X1);
    // 0x8006A158: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8006A15C: blez        $v0, L_80069CAC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8006A160: addu        $s1, $v0, $zero
        ctx->r17 = ADD32(ctx->r2, 0);
            goto L_80069CAC;
    }
    // 0x8006A160: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8006A164: sltiu       $v0, $s1, 0x21
    ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
L_8006A168:
    // 0x8006A168: beq         $v0, $zero, L_8006A174
    if (ctx->r2 == 0) {
        // 0x8006A16C: addiu       $s0, $zero, 0x20
        ctx->r16 = ADD32(0, 0X20);
            goto L_8006A174;
    }
    // 0x8006A16C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
    // 0x8006A170: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_8006A174:
    // 0x8006A174: blezl       $s0, L_8006A1A8
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8006A178: subu        $s1, $s1, $s0
        ctx->r17 = SUB32(ctx->r17, ctx->r16);
            goto L_8006A1A8;
    }
    goto skip_7;
    // 0x8006A178: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    skip_7:
    // 0x8006A17C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8006A180: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8006A184: addiu       $a1, $a1, -0x7DF0
    ctx->r5 = ADD32(ctx->r5, -0X7DF0);
    // 0x8006A188: jalr        $s4
    // 0x8006A18C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_11;
    // 0x8006A18C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_11:
    // 0x8006A190: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8006A194: beq         $s3, $zero, L_8006A1B8
    if (ctx->r19 == 0) {
        // 0x8006A198: subu        $s1, $s1, $s0
        ctx->r17 = SUB32(ctx->r17, ctx->r16);
            goto L_8006A1B8;
    }
    // 0x8006A198: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8006A19C: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8006A1A0: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8006A1A4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_8006A1A8:
    // 0x8006A1A8: bgtz        $s1, L_8006A168
    if (SIGNED(ctx->r17) > 0) {
        // 0x8006A1AC: sltiu       $v0, $s1, 0x21
        ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_8006A168;
    }
    // 0x8006A1AC: sltiu       $v0, $s1, 0x21
    ctx->r2 = ctx->r17 < 0X21 ? 1 : 0;
    // 0x8006A1B0: j           L_80069CAC
    // 0x8006A1B4: addiu       $a1, $s2, 0x1
    ctx->r5 = ADD32(ctx->r18, 0X1);
        goto L_80069CAC;
    // 0x8006A1B4: addiu       $a1, $s2, 0x1
    ctx->r5 = ADD32(ctx->r18, 0X1);
L_8006A1B8:
    // 0x8006A1B8: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8006A1BC: lw          $ra, 0x80($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X80);
    // 0x8006A1C0: lw          $s5, 0x7C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X7C);
    // 0x8006A1C4: lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X78);
    // 0x8006A1C8: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x8006A1CC: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x8006A1D0: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x8006A1D4: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x8006A1D8: jr          $ra
    // 0x8006A1DC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8006A1DC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
