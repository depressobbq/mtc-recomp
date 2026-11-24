#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800494E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800494E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800494E4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800494E8: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x800494EC: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x800494F0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800494F4: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x800494F8: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800494FC: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80049500: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80049504: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80049508: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8004950C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80049510: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80049514: lb          $v0, 0x968($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X968);
    // 0x80049518: sll         $a2, $a1, 2
    ctx->r6 = S32(ctx->r5 << 2);
    // 0x8004951C: lui         $s6, 0x8009
    ctx->r22 = S32(0X8009 << 16);
    // 0x80049520: addu        $s6, $s6, $a2
    ctx->r22 = ADD32(ctx->r22, ctx->r6);
    // 0x80049524: lw          $s6, 0xFCC($s6)
    ctx->r22 = MEM_W(ctx->r22, 0XFCC);
    // 0x80049528: blez        $v0, L_8004963C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004952C: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8004963C;
    }
    // 0x8004952C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80049530: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80049534: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80049538: addiu       $v0, $v0, -0x1E18
    ctx->r2 = ADD32(ctx->r2, -0X1E18);
    // 0x8004953C: addu        $s5, $a2, $v0
    gpr jr_addend_80049594 = ctx->r6;
    ctx->r21 = ADD32(ctx->r6, ctx->r2);
    // 0x80049540: sll         $v1, $a0, 24
    ctx->r3 = S32(ctx->r4 << 24);
    // 0x80049544: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80049548: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8004954C: addiu       $a0, $a0, 0x4A68
    ctx->r4 = ADD32(ctx->r4, 0X4A68);
    // 0x80049550: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80049554: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049558: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8004955C: addu        $s4, $v0, $a0
    ctx->r20 = ADD32(ctx->r2, ctx->r4);
    // 0x80049560: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80049564: addiu       $v1, $v1, 0x4A38
    ctx->r3 = ADD32(ctx->r3, 0X4A38);
    // 0x80049568: addu        $s3, $v0, $v1
    ctx->r19 = ADD32(ctx->r2, ctx->r3);
    // 0x8004956C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80049570: addiu       $v1, $v1, 0x4A98
    ctx->r3 = ADD32(ctx->r3, 0X4A98);
    // 0x80049574: addu        $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
    // 0x80049578: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_8004957C:
    // 0x8004957C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80049580: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x80049584: sltiu       $v0, $s1, 0x1A
    ctx->r2 = ctx->r17 < 0X1A ? 1 : 0;
    // 0x80049588: beq         $v0, $zero, L_800495E8
    if (ctx->r2 == 0) {
        // 0x8004958C: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_800495E8;
    }
    // 0x8004958C: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x80049590: lw          $v0, 0x0($s5)
    ctx->r2 = ADD32(ctx->r21, 0X0);
    // 0x80049594: jr          $v0
    // 0x80049598: nop

    switch (jr_addend_80049594 >> 2) {
        case 0: goto L_8004959C; break;
        case 1: goto L_800495E4; break;
        case 2: goto L_800495E4; break;
        case 3: goto L_800495E4; break;
        case 4: goto L_800495E4; break;
        case 5: goto L_800495E4; break;
        case 6: goto L_800495E4; break;
        case 7: goto L_800495E4; break;
        case 8: goto L_800495E4; break;
        case 9: goto L_800495E4; break;
        case 10: goto L_800495E4; break;
        case 11: goto L_800495E4; break;
        case 12: goto L_800495E4; break;
        case 13: goto L_800495E4; break;
        case 14: goto L_800495E4; break;
        case 15: goto L_800495E4; break;
        case 16: goto L_800495E4; break;
        case 17: goto L_800495E4; break;
        case 18: goto L_800495E4; break;
        case 19: goto L_800495AC; break;
        case 20: goto L_800495E4; break;
        case 21: goto L_800495E4; break;
        case 22: goto L_8004959C; break;
        case 23: goto L_8004959C; break;
        case 24: goto L_8004959C; break;
        case 25: goto L_800495E0; break;
        default: switch_error(__func__, 0x80049594, 0x800AE1E8);
    }
    // 0x80049598: nop

L_8004959C:
    // 0x8004959C: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800495A0: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800495A4: j           L_800495E4
    // 0x800495A8: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
        goto L_800495E4;
    // 0x800495A8: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
L_800495AC:
    // 0x800495AC: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x800495B0: sra         $a0, $v0, 24
    ctx->r4 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800495B4: sltiu       $v1, $a0, 0x1
    ctx->r3 = ctx->r4 < 0X1 ? 1 : 0;
    // 0x800495B8: xori        $v0, $a0, 0x2
    ctx->r2 = ctx->r4 ^ 0X2;
    // 0x800495BC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800495C0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800495C4: bne         $v1, $zero, L_800495E4
    if (ctx->r3 != 0) {
        // 0x800495C8: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_800495E4;
    }
    // 0x800495C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800495CC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800495D0: bne         $a0, $v0, L_800495E4
    if (ctx->r4 != ctx->r2) {
        // 0x800495D4: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_800495E4;
    }
    // 0x800495D4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800495D8: j           L_800495E4
    // 0x800495DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800495E4;
    // 0x800495DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800495E0:
    // 0x800495E0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_800495E4:
    // 0x800495E4: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_800495E8:
    // 0x800495E8: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x800495EC: addu        $a2, $v0, $s6
    ctx->r6 = ADD32(ctx->r2, ctx->r22);
    // 0x800495F0: addu        $v1, $v0, $s4
    ctx->r3 = ADD32(ctx->r2, ctx->r20);
    // 0x800495F4: addu        $a0, $v0, $s3
    ctx->r4 = ADD32(ctx->r2, ctx->r19);
    // 0x800495F8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800495FC: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80049600: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80049604: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80049608: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8004960C: jal         0x8004EC44
    // 0x80049610: addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
    func_8004EC44(rdram, ctx);
        goto after_0;
    // 0x80049610: addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
    after_0:
    // 0x80049614: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x80049618: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8004961C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80049620: addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // 0x80049624: lb          $v1, 0x968($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X968);
    // 0x80049628: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004962C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80049630: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80049634: bne         $v0, $zero, L_8004957C
    if (ctx->r2 != 0) {
        // 0x80049638: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_8004957C;
    }
    // 0x80049638: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_8004963C:
    // 0x8004963C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80049640: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80049644: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80049648: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8004964C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80049650: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80049654: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80049658: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004965C: jr          $ra
    // 0x80049660: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80049660: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80049664(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049664: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x80049668: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x8004966C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80049670: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80049674: lb          $v0, 0x968($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X968);
    // 0x80049678: blez        $v0, L_80049724
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004967C: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80049724;
    }
    // 0x8004967C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80049680: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
    // 0x80049684: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80049688: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8004968C: addiu       $a0, $a0, 0x4A38
    ctx->r4 = ADD32(ctx->r4, 0X4A38);
    // 0x80049690: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80049694: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80049698: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8004969C: addu        $a3, $v1, $a0
    ctx->r7 = ADD32(ctx->r3, ctx->r4);
    // 0x800496A0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800496A4: sll         $v0, $a2, 24
    ctx->r2 = S32(ctx->r6 << 24);
L_800496A8:
    // 0x800496A8: sra         $a0, $v0, 24
    ctx->r4 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800496AC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800496B0: addu        $v1, $v0, $a3
    ctx->r3 = ADD32(ctx->r2, ctx->r7);
    // 0x800496B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800496B8: blez        $v0, L_800496CC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800496BC: nop
    
            goto L_800496CC;
    }
    // 0x800496BC: nop

    // 0x800496C0: addiu       $v0, $v0, -0x5
    ctx->r2 = ADD32(ctx->r2, -0X5);
    // 0x800496C4: j           L_800496FC
    // 0x800496C8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_800496FC;
    // 0x800496C8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800496CC:
    // 0x800496CC: bgez        $v0, L_800496DC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800496D0: addiu       $v0, $v0, 0x5
        ctx->r2 = ADD32(ctx->r2, 0X5);
            goto L_800496DC;
    }
    // 0x800496D0: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // 0x800496D4: j           L_800496FC
    // 0x800496D8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_800496FC;
    // 0x800496D8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800496DC:
    // 0x800496DC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x800496E0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800496E4: lb          $v0, 0x968($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X968);
    // 0x800496E8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800496EC: bne         $a0, $v0, L_80049700
    if (ctx->r4 != ctx->r2) {
        // 0x800496F0: addiu       $v0, $a2, 0x1
        ctx->r2 = ADD32(ctx->r6, 0X1);
            goto L_80049700;
    }
    // 0x800496F0: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x800496F4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800496F8: sb          $t0, 0x4A34($at)
    MEM_B(0X4A34, ctx->r1) = ctx->r8;
L_800496FC:
    // 0x800496FC: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
L_80049700:
    // 0x80049700: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80049704: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80049708: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8004970C: lb          $v1, 0x968($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X968);
    // 0x80049710: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80049714: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80049718: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004971C: bne         $v0, $zero, L_800496A8
    if (ctx->r2 != 0) {
        // 0x80049720: sll         $v0, $a2, 24
        ctx->r2 = S32(ctx->r6 << 24);
            goto L_800496A8;
    }
    // 0x80049720: sll         $v0, $a2, 24
    ctx->r2 = S32(ctx->r6 << 24);
L_80049724:
    // 0x80049724: jr          $ra
    // 0x80049728: nop

    return;
    // 0x80049728: nop

;}
RECOMP_FUNC void func_8004972C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004972C: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80049730: beq         $a1, $zero, L_80049794
    if (ctx->r5 == 0) {
        // 0x80049734: lui         $a0, 0xF650
        ctx->r4 = S32(0XF650 << 16);
            goto L_80049794;
    }
    // 0x80049734: lui         $a0, 0xF650
    ctx->r4 = S32(0XF650 << 16);
    // 0x80049738: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004973C: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80049740: ori         $a0, $a0, 0x330
    ctx->r4 = ctx->r4 | 0X330;
    // 0x80049744: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80049748: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004974C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80049750: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x80049754: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80049758: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8004975C: addiu       $v0, $v0, 0x6D70
    ctx->r2 = ADD32(ctx->r2, 0X6D70);
    // 0x80049760: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80049764: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80049768: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004976C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80049770: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x80049774: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x80049778: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8004977C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049780: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80049784: addiu       $v0, $zero, 0x90
    ctx->r2 = ADD32(0, 0X90);
    // 0x80049788: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x8004978C: sw          $a0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r4;
    // 0x80049790: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
L_80049794:
    // 0x80049794: jr          $ra
    // 0x80049798: nop

    return;
    // 0x80049798: nop

;}
RECOMP_FUNC void func_8004979C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004979C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800497A0: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x800497A4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800497A8: sll         $s1, $v0, 24
    ctx->r17 = S32(ctx->r2 << 24);
    // 0x800497AC: sra         $s1, $s1, 24
    ctx->r17 = S32(SIGNED(ctx->r17) >> 24);
    // 0x800497B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800497B4: sll         $s0, $s1, 3
    ctx->r16 = S32(ctx->r17 << 3);
    // 0x800497B8: subu        $s0, $s0, $s1
    ctx->r16 = SUB32(ctx->r16, ctx->r17);
    // 0x800497BC: sll         $s0, $s0, 4
    ctx->r16 = S32(ctx->r16 << 4);
    // 0x800497C0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800497C4: addiu       $a0, $a0, 0x6AA0
    ctx->r4 = ADD32(ctx->r4, 0X6AA0);
    // 0x800497C8: addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    // 0x800497CC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800497D0: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800497D4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800497D8: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800497DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800497E0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800497E4: sb          $zero, 0x6ACA($at)
    MEM_B(0X6ACA, ctx->r1) = 0;
    // 0x800497E8: jal         0x80017760
    // 0x800497EC: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    func_80017760(rdram, ctx);
        goto after_0;
    // 0x800497EC: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    after_0:
    // 0x800497F0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800497F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800497F8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800497FC: sb          $v0, 0x6AB6($at)
    MEM_B(0X6AB6, ctx->r1) = ctx->r2;
    // 0x80049800: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80049804: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049808: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8004980C: sb          $v0, 0x6AB7($at)
    MEM_B(0X6AB7, ctx->r1) = ctx->r2;
    // 0x80049810: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049814: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80049818: sh          $zero, 0x6AB8($at)
    MEM_H(0X6AB8, ctx->r1) = 0;
    // 0x8004981C: bne         $s1, $zero, L_80049848
    if (ctx->r17 != 0) {
        // 0x80049820: sll         $v1, $s2, 24
        ctx->r3 = S32(ctx->r18 << 24);
            goto L_80049848;
    }
    // 0x80049820: sll         $v1, $s2, 24
    ctx->r3 = S32(ctx->r18 << 24);
    // 0x80049824: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80049828: addiu       $v0, $v0, -0x75C0
    ctx->r2 = ADD32(ctx->r2, -0X75C0);
    // 0x8004982C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049830: sw          $v0, 0x6AB0($at)
    MEM_W(0X6AB0, ctx->r1) = ctx->r2;
    // 0x80049834: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80049838: addiu       $v0, $v0, -0x2338
    ctx->r2 = ADD32(ctx->r2, -0X2338);
    // 0x8004983C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049840: j           L_80049868
    // 0x80049844: sw          $v0, 0x6AD0($at)
    MEM_W(0X6AD0, ctx->r1) = ctx->r2;
        goto L_80049868;
    // 0x80049844: sw          $v0, 0x6AD0($at)
    MEM_W(0X6AD0, ctx->r1) = ctx->r2;
L_80049848:
    // 0x80049848: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8004984C: addiu       $v0, $v0, -0x1DC0
    ctx->r2 = ADD32(ctx->r2, -0X1DC0);
    // 0x80049850: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049854: sw          $v0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r2;
    // 0x80049858: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004985C: addiu       $v0, $v0, -0x2538
    ctx->r2 = ADD32(ctx->r2, -0X2538);
    // 0x80049860: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049864: sw          $v0, 0x6B40($at)
    MEM_W(0X6B40, ctx->r1) = ctx->r2;
L_80049868:
    // 0x80049868: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8004986C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80049870: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80049874: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x80049878: sll         $v0, $s3, 24
    ctx->r2 = S32(ctx->r19 << 24);
    // 0x8004987C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80049880: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80049884: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049888: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8004988C: sw          $zero, 0x6AE4($at)
    MEM_W(0X6AE4, ctx->r1) = 0;
    // 0x80049890: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049894: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80049898: sw          $zero, 0x6AE8($at)
    MEM_W(0X6AE8, ctx->r1) = 0;
    // 0x8004989C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x800498A0: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x800498A4: lw          $a2, 0x87C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X87C);
    // 0x800498A8: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x800498AC: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x800498B0: lw          $a1, 0x880($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X880);
    // 0x800498B4: bne         $v0, $zero, L_800498D0
    if (ctx->r2 != 0) {
        // 0x800498B8: addiu       $v0, $zero, 0x500
        ctx->r2 = ADD32(0, 0X500);
            goto L_800498D0;
    }
    // 0x800498B8: addiu       $v0, $zero, 0x500
    ctx->r2 = ADD32(0, 0X500);
    // 0x800498BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800498C0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800498C4: sh          $zero, 0x6AA4($at)
    MEM_H(0X6AA4, ctx->r1) = 0;
    // 0x800498C8: j           L_800498E0
    // 0x800498CC: sll         $v0, $s3, 24
    ctx->r2 = S32(ctx->r19 << 24);
        goto L_800498E0;
    // 0x800498CC: sll         $v0, $s3, 24
    ctx->r2 = S32(ctx->r19 << 24);
L_800498D0:
    // 0x800498D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800498D4: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x800498D8: sh          $v0, 0x6AA4($at)
    MEM_H(0X6AA4, ctx->r1) = ctx->r2;
    // 0x800498DC: sll         $v0, $s3, 24
    ctx->r2 = S32(ctx->r19 << 24);
L_800498E0:
    // 0x800498E0: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800498E4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800498E8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800498EC: lb          $v0, 0x860($at)
    ctx->r2 = MEM_B(ctx->r1, 0X860);
    // 0x800498F0: slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x800498F4: bne         $v0, $zero, L_80049914
    if (ctx->r2 != 0) {
        // 0x800498F8: sll         $v0, $s2, 24
        ctx->r2 = S32(ctx->r18 << 24);
            goto L_80049914;
    }
    // 0x800498F8: sll         $v0, $s2, 24
    ctx->r2 = S32(ctx->r18 << 24);
    // 0x800498FC: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80049900: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80049904: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80049908: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x8004990C: j           L_80049928
    // 0x80049910: addiu       $v0, $zero, 0x90
    ctx->r2 = ADD32(0, 0X90);
        goto L_80049928;
    // 0x80049910: addiu       $v0, $zero, 0x90
    ctx->r2 = ADD32(0, 0X90);
L_80049914:
    // 0x80049914: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80049918: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x8004991C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80049920: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80049924: addiu       $v0, $zero, -0x90
    ctx->r2 = ADD32(0, -0X90);
L_80049928:
    // 0x80049928: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004992C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80049930: sh          $v0, 0x6AAC($at)
    MEM_H(0X6AAC, ctx->r1) = ctx->r2;
    // 0x80049934: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x80049938: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x8004993C: sll         $s0, $s2, 24
    ctx->r16 = S32(ctx->r18 << 24);
    // 0x80049940: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x80049944: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x80049948: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x8004994C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80049950: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80049954: addiu       $a0, $a0, 0x6AA0
    ctx->r4 = ADD32(ctx->r4, 0X6AA0);
    // 0x80049958: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x8004995C: sh          $v1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r3;
    // 0x80049960: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049964: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80049968: sh          $v1, 0x6AA2($at)
    MEM_H(0X6AA2, ctx->r1) = ctx->r3;
    // 0x8004996C: sh          $a1, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r5;
    // 0x80049970: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049974: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80049978: jal         0x80066D30
    // 0x8004997C: sh          $a1, 0x6AAA($at)
    MEM_H(0X6AAA, ctx->r1) = ctx->r5;
    func_80066D30(rdram, ctx);
        goto after_1;
    // 0x8004997C: sh          $a1, 0x6AAA($at)
    MEM_H(0X6AAA, ctx->r1) = ctx->r5;
    after_1:
    // 0x80049980: bne         $s0, $zero, L_800499D4
    if (ctx->r16 != 0) {
        // 0x80049984: sll         $v0, $s3, 24
        ctx->r2 = S32(ctx->r19 << 24);
            goto L_800499D4;
    }
    // 0x80049984: sll         $v0, $s3, 24
    ctx->r2 = S32(ctx->r19 << 24);
    // 0x80049988: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004998C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80049990: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80049994: lb          $v1, 0x860($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X860);
    // 0x80049998: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8004999C: addiu       $a0, $a0, -0x65D0
    ctx->r4 = ADD32(ctx->r4, -0X65D0);
    // 0x800499A0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800499A4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800499A8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800499AC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800499B0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x800499B4: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x800499B8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800499BC: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x800499C0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800499C4: addiu       $a1, $a1, -0x2338
    ctx->r5 = ADD32(ctx->r5, -0X2338);
    // 0x800499C8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800499CC: j           L_80049A1C
    // 0x800499D0: addiu       $a2, $a2, -0x75C0
    ctx->r6 = ADD32(ctx->r6, -0X75C0);
        goto L_80049A1C;
    // 0x800499D0: addiu       $a2, $a2, -0x75C0
    ctx->r6 = ADD32(ctx->r6, -0X75C0);
L_800499D4:
    // 0x800499D4: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800499D8: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x800499DC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800499E0: lb          $v1, 0x860($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X860);
    // 0x800499E4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800499E8: addiu       $a0, $a0, -0x65D0
    ctx->r4 = ADD32(ctx->r4, -0X65D0);
    // 0x800499EC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800499F0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800499F4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800499F8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800499FC: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80049A00: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80049A04: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80049A08: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x80049A0C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80049A10: addiu       $a1, $a1, -0x2538
    ctx->r5 = ADD32(ctx->r5, -0X2538);
    // 0x80049A14: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x80049A18: addiu       $a2, $a2, -0x1DC0
    ctx->r6 = ADD32(ctx->r6, -0X1DC0);
L_80049A1C:
    // 0x80049A1C: jal         0x80053078
    // 0x80049A20: nop

    func_80053078(rdram, ctx);
        goto after_2;
    // 0x80049A20: nop

    after_2:
    // 0x80049A24: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80049A28: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80049A2C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80049A30: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80049A34: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80049A38: jr          $ra
    // 0x80049A3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80049A3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80049A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049A40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80049A44: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80049A48: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80049A4C: addiu       $s0, $s0, 0x354A
    ctx->r16 = ADD32(ctx->r16, 0X354A);
    // 0x80049A50: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80049A54: addiu       $s1, $s0, -0x2A
    ctx->r17 = ADD32(ctx->r16, -0X2A);
    // 0x80049A58: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80049A5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80049A60: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80049A64: jal         0x80017760
    // 0x80049A68: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    func_80017760(rdram, ctx);
        goto after_0;
    // 0x80049A68: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    after_0:
    // 0x80049A6C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80049A70: addiu       $s1, $zero, 0x90
    ctx->r17 = ADD32(0, 0X90);
    // 0x80049A74: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80049A78: addiu       $v0, $v0, -0x39C0
    ctx->r2 = ADD32(ctx->r2, -0X39C0);
    // 0x80049A7C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049A80: sh          $s1, 0x352A($at)
    MEM_H(0X352A, ctx->r1) = ctx->r17;
    // 0x80049A84: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049A88: sh          $s1, 0x352E($at)
    MEM_H(0X352E, ctx->r1) = ctx->r17;
    // 0x80049A8C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049A90: sw          $v0, 0x3530($at)
    MEM_W(0X3530, ctx->r1) = ctx->r2;
    // 0x80049A94: jal         0x80066D30
    // 0x80049A98: addiu       $s2, $s0, 0x46
    ctx->r18 = ADD32(ctx->r16, 0X46);
    func_80066D30(rdram, ctx);
        goto after_1;
    // 0x80049A98: addiu       $s2, $s0, 0x46
    ctx->r18 = ADD32(ctx->r16, 0X46);
    after_1:
    // 0x80049A9C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80049AA0: jal         0x80017760
    // 0x80049AA4: sb          $zero, 0x70($s0)
    MEM_B(0X70, ctx->r16) = 0;
    func_80017760(rdram, ctx);
        goto after_2;
    // 0x80049AA4: sb          $zero, 0x70($s0)
    MEM_B(0X70, ctx->r16) = 0;
    after_2:
    // 0x80049AA8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80049AAC: sh          $s1, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r17;
    // 0x80049AB0: sh          $s1, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r17;
    // 0x80049AB4: lui         $s1, 0x8010
    ctx->r17 = S32(0X8010 << 16);
    // 0x80049AB8: addiu       $s1, $s1, 0x3040
    ctx->r17 = ADD32(ctx->r17, 0X3040);
    // 0x80049ABC: addiu       $v0, $zero, 0x330
    ctx->r2 = ADD32(0, 0X330);
    // 0x80049AC0: sw          $s1, 0x56($s0)
    MEM_W(0X56, ctx->r16) = ctx->r17;
    // 0x80049AC4: jal         0x80066D30
    // 0x80049AC8: sh          $v0, 0x52($s0)
    MEM_H(0X52, ctx->r16) = ctx->r2;
    func_80066D30(rdram, ctx);
        goto after_3;
    // 0x80049AC8: sh          $v0, 0x52($s0)
    MEM_H(0X52, ctx->r16) = ctx->r2;
    after_3:
    // 0x80049ACC: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x80049AD0: addiu       $a0, $a0, -0x1EC0
    ctx->r4 = ADD32(ctx->r4, -0X1EC0);
    // 0x80049AD4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80049AD8: jal         0x80006D98
    // 0x80049ADC: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    func_80006D98(rdram, ctx);
        goto after_4;
    // 0x80049ADC: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    after_4:
    // 0x80049AE0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80049AE4: jal         0x8004979C
    // 0x80049AE8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8004979C(rdram, ctx);
        goto after_5;
    // 0x80049AE8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_5:
    // 0x80049AEC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80049AF0: jal         0x8004979C
    // 0x80049AF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004979C(rdram, ctx);
        goto after_6;
    // 0x80049AF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80049AF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80049AFC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80049B00: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80049B04: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80049B08: jr          $ra
    // 0x80049B0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80049B0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80049B10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049B10: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80049B14: lb          $v0, 0x25A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A0);
    // 0x80049B18: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80049B1C: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x80049B20: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80049B24: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x80049B28: sw          $s2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r18;
    // 0x80049B2C: sw          $s1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r17;
    // 0x80049B30: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80049B34: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80049B38: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x80049B3C: beq         $v0, $zero, L_80049F78
    if (ctx->r2 == 0) {
        // 0x80049B40: sw          $s0, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r16;
            goto L_80049F78;
    }
    // 0x80049B40: sw          $s0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r16;
    // 0x80049B44: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80049B48: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80049B4C: addu        $at, $at, $v0
    gpr jr_addend_80049B54 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80049B50: lw          $v0, -0x1DB0($at)
    ctx->r2 = ADD32(ctx->r1, -0X1DB0);
    // 0x80049B54: jr          $v0
    // 0x80049B58: nop

    switch (jr_addend_80049B54 >> 2) {
        case 0: goto L_80049B5C; break;
        case 1: goto L_80049CE0; break;
        case 2: goto L_80049D08; break;
        case 3: goto L_80049DD0; break;
        case 4: goto L_80049F30; break;
        default: switch_error(__func__, 0x80049B54, 0x800AE250);
    }
    // 0x80049B58: nop

L_80049B5C:
    // 0x80049B5C: jal         0x8000BB3C
    // 0x80049B60: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    func_8000BB3C(rdram, ctx);
        goto after_0;
    // 0x80049B60: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    after_0:
    // 0x80049B64: jal         0x8002D378
    // 0x80049B68: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_1;
    // 0x80049B68: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x80049B6C: jal         0x8002D0D4
    // 0x80049B70: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_2;
    // 0x80049B70: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x80049B74: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80049B78: sb          $zero, 0x4A32($at)
    MEM_B(0X4A32, ctx->r1) = 0;
    // 0x80049B7C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80049B80: sb          $zero, 0x4A31($at)
    MEM_B(0X4A31, ctx->r1) = 0;
    // 0x80049B84: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80049B88: sb          $s2, 0x4A34($at)
    MEM_B(0X4A34, ctx->r1) = ctx->r18;
    // 0x80049B8C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80049B90: sb          $s2, 0x4A33($at)
    MEM_B(0X4A33, ctx->r1) = ctx->r18;
    // 0x80049B94: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80049B98: sb          $zero, 0x4A35($at)
    MEM_B(0X4A35, ctx->r1) = 0;
    // 0x80049B9C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80049BA0: sb          $zero, 0x4A36($at)
    MEM_B(0X4A36, ctx->r1) = 0;
    // 0x80049BA4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80049BA8: sb          $zero, 0x4AC9($at)
    MEM_B(0X4AC9, ctx->r1) = 0;
    // 0x80049BAC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80049BB0: sb          $zero, 0x4AC8($at)
    MEM_B(0X4AC8, ctx->r1) = 0;
    // 0x80049BB4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80049BB8: jal         0x80031BEC
    // 0x80049BBC: sb          $zero, 0x4A30($at)
    MEM_B(0X4A30, ctx->r1) = 0;
    func_80031BEC(rdram, ctx);
        goto after_3;
    // 0x80049BBC: sb          $zero, 0x4A30($at)
    MEM_B(0X4A30, ctx->r1) = 0;
    after_3:
    // 0x80049BC0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80049BC4: lb          $v0, 0x4A32($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A32);
    // 0x80049BC8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80049BCC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80049BD0: lb          $v0, 0x94C($at)
    ctx->r2 = MEM_B(ctx->r1, 0X94C);
    // 0x80049BD4: beq         $v0, $zero, L_80049BEC
    if (ctx->r2 == 0) {
        // 0x80049BD8: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_80049BEC;
    }
    // 0x80049BD8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80049BDC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80049BE0: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x80049BE4: jal         0x80040CDC
    // 0x80049BE8: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    func_80040CDC(rdram, ctx);
        goto after_4;
    // 0x80049BE8: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    after_4:
L_80049BEC:
    // 0x80049BEC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80049BF0: addiu       $a0, $a0, 0x3520
    ctx->r4 = ADD32(ctx->r4, 0X3520);
    // 0x80049BF4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049BF8: sb          $zero, 0x354A($at)
    MEM_B(0X354A, ctx->r1) = 0;
    // 0x80049BFC: jal         0x80017760
    // 0x80049C00: addiu       $s1, $zero, 0x90
    ctx->r17 = ADD32(0, 0X90);
    func_80017760(rdram, ctx);
        goto after_5;
    // 0x80049C00: addiu       $s1, $zero, 0x90
    ctx->r17 = ADD32(0, 0X90);
    after_5:
    // 0x80049C04: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80049C08: addiu       $s0, $s0, 0x352A
    ctx->r16 = ADD32(ctx->r16, 0X352A);
    // 0x80049C0C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80049C10: addiu       $v0, $v0, -0x39C0
    ctx->r2 = ADD32(ctx->r2, -0X39C0);
    // 0x80049C14: sh          $s1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r17;
    // 0x80049C18: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049C1C: sh          $s1, 0x352E($at)
    MEM_H(0X352E, ctx->r1) = ctx->r17;
    // 0x80049C20: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049C24: sw          $v0, 0x3530($at)
    MEM_W(0X3530, ctx->r1) = ctx->r2;
    // 0x80049C28: jal         0x80066D30
    // 0x80049C2C: addiu       $a0, $s0, -0xA
    ctx->r4 = ADD32(ctx->r16, -0XA);
    func_80066D30(rdram, ctx);
        goto after_6;
    // 0x80049C2C: addiu       $a0, $s0, -0xA
    ctx->r4 = ADD32(ctx->r16, -0XA);
    after_6:
    // 0x80049C30: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049C34: sb          $zero, 0x35BA($at)
    MEM_B(0X35BA, ctx->r1) = 0;
    // 0x80049C38: jal         0x80017760
    // 0x80049C3C: addiu       $a0, $s0, 0x66
    ctx->r4 = ADD32(ctx->r16, 0X66);
    func_80017760(rdram, ctx);
        goto after_7;
    // 0x80049C3C: addiu       $a0, $s0, 0x66
    ctx->r4 = ADD32(ctx->r16, 0X66);
    after_7:
    // 0x80049C40: addiu       $a0, $s0, 0x66
    ctx->r4 = ADD32(ctx->r16, 0X66);
    // 0x80049C44: sh          $s1, 0x70($s0)
    MEM_H(0X70, ctx->r16) = ctx->r17;
    // 0x80049C48: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x80049C4C: addiu       $s0, $s0, 0x3040
    ctx->r16 = ADD32(ctx->r16, 0X3040);
    // 0x80049C50: addiu       $v0, $zero, 0x330
    ctx->r2 = ADD32(0, 0X330);
    // 0x80049C54: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049C58: sh          $s1, 0x359E($at)
    MEM_H(0X359E, ctx->r1) = ctx->r17;
    // 0x80049C5C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049C60: sw          $s0, 0x35A0($at)
    MEM_W(0X35A0, ctx->r1) = ctx->r16;
    // 0x80049C64: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049C68: jal         0x80066D30
    // 0x80049C6C: sh          $v0, 0x359C($at)
    MEM_H(0X359C, ctx->r1) = ctx->r2;
    func_80066D30(rdram, ctx);
        goto after_8;
    // 0x80049C6C: sh          $v0, 0x359C($at)
    MEM_H(0X359C, ctx->r1) = ctx->r2;
    after_8:
    // 0x80049C70: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x80049C74: addiu       $a0, $a0, -0x1EC0
    ctx->r4 = ADD32(ctx->r4, -0X1EC0);
    // 0x80049C78: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80049C7C: jal         0x80006D98
    // 0x80049C80: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    func_80006D98(rdram, ctx);
        goto after_9;
    // 0x80049C80: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    after_9:
    // 0x80049C84: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80049C88: jal         0x8004979C
    // 0x80049C8C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8004979C(rdram, ctx);
        goto after_10;
    // 0x80049C8C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_10:
    // 0x80049C90: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80049C94: jal         0x8004979C
    // 0x80049C98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004979C(rdram, ctx);
        goto after_11;
    // 0x80049C98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80049C9C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80049CA0: lbu         $v1, 0x4A32($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4A32);
    // 0x80049CA4: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80049CA8: lbu         $a0, 0x4A31($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X4A31);
    // 0x80049CAC: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x80049CB0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049CB4: sh          $v0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r2;
    // 0x80049CB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80049CBC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049CC0: sb          $s2, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r18;
    // 0x80049CC4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80049CC8: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80049CCC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80049CD0: sb          $v0, 0x4A31($at)
    MEM_B(0X4A31, ctx->r1) = ctx->r2;
    // 0x80049CD4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80049CD8: j           L_80049F78
    // 0x80049CDC: sb          $v1, 0x4A32($at)
    MEM_B(0X4A32, ctx->r1) = ctx->r3;
        goto L_80049F78;
    // 0x80049CDC: sb          $v1, 0x4A32($at)
    MEM_B(0X4A32, ctx->r1) = ctx->r3;
L_80049CE0:
    // 0x80049CE0: jal         0x8002CFB8
    // 0x80049CE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_12;
    // 0x80049CE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x80049CE8: beq         $v0, $zero, L_80049F78
    if (ctx->r2 == 0) {
        // 0x80049CEC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80049F78;
    }
    // 0x80049CEC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80049CF0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049CF4: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x80049CF8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80049CFC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049D00: j           L_80049F78
    // 0x80049D04: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
        goto L_80049F78;
    // 0x80049D04: sb          $v0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r2;
L_80049D08:
    // 0x80049D08: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80049D0C: lb          $v0, 0x4A33($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A33);
    // 0x80049D10: beq         $v0, $zero, L_80049D30
    if (ctx->r2 == 0) {
        // 0x80049D14: andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
            goto L_80049D30;
    }
    // 0x80049D14: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80049D18: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80049D1C: addiu       $v1, $v1, 0x7B74
    ctx->r3 = ADD32(ctx->r3, 0X7B74);
    // 0x80049D20: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80049D24: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80049D28: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80049D2C: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
L_80049D30:
    // 0x80049D30: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80049D34: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80049D38: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80049D3C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80049D40: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049D44: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x80049D48: andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // 0x80049D4C: beq         $v0, $zero, L_80049D6C
    if (ctx->r2 == 0) {
        // 0x80049D50: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80049D6C;
    }
    // 0x80049D50: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80049D54: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049D58: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x80049D5C: jal         0x80006A78
    // 0x80049D60: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80006A78(rdram, ctx);
        goto after_13;
    // 0x80049D60: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_13:
    // 0x80049D64: j           L_80049F78
    // 0x80049D68: nop

        goto L_80049F78;
    // 0x80049D68: nop

L_80049D6C:
    // 0x80049D6C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80049D70: addiu       $a0, $a0, 0x7B74
    ctx->r4 = ADD32(ctx->r4, 0X7B74);
    // 0x80049D74: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80049D78: bne         $v0, $zero, L_80049F78
    if (ctx->r2 != 0) {
        // 0x80049D7C: addiu       $v0, $zero, 0xB4
        ctx->r2 = ADD32(0, 0XB4);
            goto L_80049F78;
    }
    // 0x80049D7C: addiu       $v0, $zero, 0xB4
    ctx->r2 = ADD32(0, 0XB4);
    // 0x80049D80: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80049D84: lbu         $v1, 0x4A31($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4A31);
    // 0x80049D88: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x80049D8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80049D90: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80049D94: lbu         $a1, 0x4A32($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X4A32);
    // 0x80049D98: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x80049D9C: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x80049DA0: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80049DA4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80049DA8: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x80049DAC: jal         0x800493C0
    // 0x80049DB0: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    func_800493C0(rdram, ctx);
        goto after_14;
    // 0x80049DB0: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    after_14:
    // 0x80049DB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80049DB8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80049DBC: sb          $v0, 0x4A30($at)
    MEM_B(0X4A30, ctx->r1) = ctx->r2;
    // 0x80049DC0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80049DC4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049DC8: j           L_80049F78
    // 0x80049DCC: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
        goto L_80049F78;
    // 0x80049DCC: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
L_80049DD0:
    // 0x80049DD0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80049DD4: lb          $v0, 0x4A34($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A34);
    // 0x80049DD8: beq         $v0, $zero, L_80049DF8
    if (ctx->r2 == 0) {
        // 0x80049DDC: andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
            goto L_80049DF8;
    }
    // 0x80049DDC: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80049DE0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80049DE4: addiu       $v1, $v1, 0x7B74
    ctx->r3 = ADD32(ctx->r3, 0X7B74);
    // 0x80049DE8: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80049DEC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80049DF0: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80049DF4: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
L_80049DF8:
    // 0x80049DF8: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80049DFC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80049E00: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80049E04: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80049E08: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049E0C: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x80049E10: andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // 0x80049E14: beq         $v0, $zero, L_80049E38
    if (ctx->r2 == 0) {
        // 0x80049E18: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80049E38;
    }
    // 0x80049E18: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80049E1C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049E20: jal         0x800069C0
    // 0x80049E24: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    func_800069C0(rdram, ctx);
        goto after_15;
    // 0x80049E24: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    after_15:
    // 0x80049E28: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x80049E2C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049E30: j           L_80049F78
    // 0x80049E34: sh          $v0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r2;
        goto L_80049F78;
    // 0x80049E34: sh          $v0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r2;
L_80049E38:
    // 0x80049E38: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80049E3C: addiu       $s0, $s0, 0x7B74
    ctx->r16 = ADD32(ctx->r16, 0X7B74);
    // 0x80049E40: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x80049E44: bne         $v0, $zero, L_80049F78
    if (ctx->r2 != 0) {
        // 0x80049E48: nop
    
            goto L_80049F78;
    }
    // 0x80049E48: nop

    // 0x80049E4C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80049E50: lb          $v1, 0x4A32($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X4A32);
    // 0x80049E54: slti        $v0, $v1, 0x1A
    ctx->r2 = SIGNED(ctx->r3) < 0X1A ? 1 : 0;
    // 0x80049E58: bne         $v0, $zero, L_80049E7C
    if (ctx->r2 != 0) {
        // 0x80049E5C: addiu       $v0, $zero, 0xB4
        ctx->r2 = ADD32(0, 0XB4);
            goto L_80049E7C;
    }
    // 0x80049E5C: addiu       $v0, $zero, 0xB4
    ctx->r2 = ADD32(0, 0XB4);
    // 0x80049E60: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80049E64: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049E68: jal         0x800069C0
    // 0x80049E6C: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    func_800069C0(rdram, ctx);
        goto after_16;
    // 0x80049E6C: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    after_16:
    // 0x80049E70: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x80049E74: j           L_80049F78
    // 0x80049E78: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
        goto L_80049F78;
    // 0x80049E78: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_80049E7C:
    // 0x80049E7C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80049E80: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80049E84: sb          $zero, 0x4A33($at)
    MEM_B(0X4A33, ctx->r1) = 0;
    // 0x80049E88: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80049E8C: sb          $zero, 0x4A35($at)
    MEM_B(0X4A35, ctx->r1) = 0;
    // 0x80049E90: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80049E94: sb          $zero, 0x4A36($at)
    MEM_B(0X4A36, ctx->r1) = 0;
    // 0x80049E98: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80049E9C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049EA0: lb          $v0, 0x94C($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X94C);
    // 0x80049EA4: beq         $v0, $zero, L_80049ED8
    if (ctx->r2 == 0) {
        // 0x80049EA8: nop
    
            goto L_80049ED8;
    }
    // 0x80049EA8: nop

    // 0x80049EAC: jal         0x80031BEC
    // 0x80049EB0: nop

    func_80031BEC(rdram, ctx);
        goto after_17;
    // 0x80049EB0: nop

    after_17:
    // 0x80049EB4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80049EB8: lb          $v0, 0x4A32($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A32);
    // 0x80049EBC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80049EC0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80049EC4: lbu         $a0, 0x94C($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X94C);
    // 0x80049EC8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80049ECC: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x80049ED0: jal         0x80040CDC
    // 0x80049ED4: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    func_80040CDC(rdram, ctx);
        goto after_18;
    // 0x80049ED4: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    after_18:
L_80049ED8:
    // 0x80049ED8: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80049EDC: lb          $a0, 0x4A31($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X4A31);
    // 0x80049EE0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80049EE4: jal         0x800493C0
    // 0x80049EE8: lb          $a1, 0x4A32($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X4A32);
    func_800493C0(rdram, ctx);
        goto after_19;
    // 0x80049EE8: lb          $a1, 0x4A32($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X4A32);
    after_19:
    // 0x80049EEC: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80049EF0: lb          $a0, 0x4A31($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X4A31);
    // 0x80049EF4: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80049EF8: jal         0x8004979C
    // 0x80049EFC: lb          $a1, 0x4A32($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X4A32);
    func_8004979C(rdram, ctx);
        goto after_20;
    // 0x80049EFC: lb          $a1, 0x4A32($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X4A32);
    after_20:
    // 0x80049F00: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80049F04: lbu         $v0, 0x4A32($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4A32);
    // 0x80049F08: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80049F0C: lbu         $a0, 0x4A31($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X4A31);
    // 0x80049F10: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80049F14: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80049F18: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80049F1C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80049F20: sb          $v1, 0x4A31($at)
    MEM_B(0X4A31, ctx->r1) = ctx->r3;
    // 0x80049F24: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80049F28: j           L_80049F78
    // 0x80049F2C: sb          $v0, 0x4A32($at)
    MEM_B(0X4A32, ctx->r1) = ctx->r2;
        goto L_80049F78;
    // 0x80049F2C: sb          $v0, 0x4A32($at)
    MEM_B(0X4A32, ctx->r1) = ctx->r2;
L_80049F30:
    // 0x80049F30: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80049F34: addiu       $a0, $a0, 0x7B74
    ctx->r4 = ADD32(ctx->r4, 0X7B74);
    // 0x80049F38: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80049F3C: blez        $v0, L_80049F50
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80049F40: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80049F50;
    }
    // 0x80049F40: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80049F44: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x80049F48: j           L_80049F78
    // 0x80049F4C: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
        goto L_80049F78;
    // 0x80049F4C: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
L_80049F50:
    // 0x80049F50: jal         0x8002CFB8
    // 0x80049F54: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_21;
    // 0x80049F54: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_21:
    // 0x80049F58: beq         $v0, $zero, L_80049F78
    if (ctx->r2 == 0) {
        // 0x80049F5C: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_80049F78;
    }
    // 0x80049F5C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80049F60: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049F64: sb          $v0, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = ctx->r2;
    // 0x80049F68: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049F6C: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x80049F70: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80049F74: sb          $zero, 0x7BA1($at)
    MEM_B(0X7BA1, ctx->r1) = 0;
L_80049F78:
    // 0x80049F78: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80049F7C: lb          $v1, 0x4A32($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X4A32);
    // 0x80049F80: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80049F84: bne         $v0, $zero, L_80049FCC
    if (ctx->r2 != 0) {
        // 0x80049F88: nop
    
            goto L_80049FCC;
    }
    // 0x80049F88: nop

    // 0x80049F8C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80049F90: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049F94: lb          $v0, 0x94B($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X94B);
    // 0x80049F98: bne         $v0, $zero, L_80049FE0
    if (ctx->r2 != 0) {
        // 0x80049F9C: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_80049FE0;
    }
    // 0x80049F9C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80049FA0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80049FA4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049FA8: lb          $v0, 0x94A($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X94A);
    // 0x80049FAC: beq         $v0, $zero, L_80049FF8
    if (ctx->r2 == 0) {
        // 0x80049FB0: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_80049FF8;
    }
    // 0x80049FB0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80049FB4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80049FB8: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x80049FBC: jal         0x800410A8
    // 0x80049FC0: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    func_800410A8(rdram, ctx);
        goto after_22;
    // 0x80049FC0: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    after_22:
    // 0x80049FC4: j           L_80049FFC
    // 0x80049FC8: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
        goto L_80049FFC;
    // 0x80049FC8: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_80049FCC:
    // 0x80049FCC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80049FD0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80049FD4: lb          $v0, 0x94B($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X94B);
    // 0x80049FD8: beq         $v0, $zero, L_80049FF8
    if (ctx->r2 == 0) {
        // 0x80049FDC: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_80049FF8;
    }
    // 0x80049FDC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_80049FE0:
    // 0x80049FE0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80049FE4: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x80049FE8: jal         0x800410A8
    // 0x80049FEC: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    func_800410A8(rdram, ctx);
        goto after_23;
    // 0x80049FEC: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    after_23:
    // 0x80049FF0: j           L_80049FFC
    // 0x80049FF4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80049FFC;
    // 0x80049FF4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80049FF8:
    // 0x80049FF8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80049FFC:
    // 0x80049FFC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A000: lb          $v0, 0x4A31($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A31);
    // 0x8004A004: beq         $v0, $zero, L_8004A2D8
    if (ctx->r2 == 0) {
        // 0x8004A008: nop
    
            goto L_8004A2D8;
    }
    // 0x8004A008: nop

    // 0x8004A00C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004A010: jal         0x80017D38
    // 0x8004A014: addiu       $a0, $a0, 0x6B10
    ctx->r4 = ADD32(ctx->r4, 0X6B10);
    func_80017D38(rdram, ctx);
        goto after_24;
    // 0x8004A014: addiu       $a0, $a0, 0x6B10
    ctx->r4 = ADD32(ctx->r4, 0X6B10);
    after_24:
    // 0x8004A018: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x8004A01C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004A020: bne         $v1, $v0, L_8004A040
    if (ctx->r3 != ctx->r2) {
        // 0x8004A024: nop
    
            goto L_8004A040;
    }
    // 0x8004A024: nop

    // 0x8004A028: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A02C: lb          $v0, 0x4A33($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A33);
    // 0x8004A030: bne         $v0, $zero, L_8004A040
    if (ctx->r2 != 0) {
        // 0x8004A034: nop
    
            goto L_8004A040;
    }
    // 0x8004A034: nop

    // 0x8004A038: jal         0x80051D6C
    // 0x8004A03C: nop

    func_80051D6C(rdram, ctx);
        goto after_25;
    // 0x8004A03C: nop

    after_25:
L_8004A040:
    // 0x8004A040: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8004A044: lbu         $a1, 0x4AC9($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X4AC9);
    // 0x8004A048: beq         $a1, $zero, L_8004A0AC
    if (ctx->r5 == 0) {
        // 0x8004A04C: lui         $a0, 0xF650
        ctx->r4 = S32(0XF650 << 16);
            goto L_8004A0AC;
    }
    // 0x8004A04C: lui         $a0, 0xF650
    ctx->r4 = S32(0XF650 << 16);
    // 0x8004A050: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004A054: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8004A058: ori         $a0, $a0, 0x330
    ctx->r4 = ctx->r4 | 0X330;
    // 0x8004A05C: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8004A060: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A064: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004A068: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x8004A06C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004A070: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8004A074: addiu       $v0, $v0, 0x6D70
    ctx->r2 = ADD32(ctx->r2, 0X6D70);
    // 0x8004A078: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8004A07C: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8004A080: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A084: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004A088: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x8004A08C: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8004A090: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8004A094: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A098: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004A09C: addiu       $v0, $zero, 0x90
    ctx->r2 = ADD32(0, 0X90);
    // 0x8004A0A0: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x8004A0A4: sw          $a0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r4;
    // 0x8004A0A8: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
L_8004A0AC:
    // 0x8004A0AC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A0B0: lb          $v0, 0x4A32($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A32);
    // 0x8004A0B4: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8004A0B8: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8004A0BC: bne         $v0, $zero, L_8004A0FC
    if (ctx->r2 != 0) {
        // 0x8004A0C0: nop
    
            goto L_8004A0FC;
    }
    // 0x8004A0C0: nop

    // 0x8004A0C4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A0C8: lb          $v0, 0x4A33($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A33);
    // 0x8004A0CC: bne         $v0, $zero, L_8004A0FC
    if (ctx->r2 != 0) {
        // 0x8004A0D0: nop
    
            goto L_8004A0FC;
    }
    // 0x8004A0D0: nop

    // 0x8004A0D4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004A0D8: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x8004A0DC: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x8004A0E0: bne         $v0, $zero, L_8004A0FC
    if (ctx->r2 != 0) {
        // 0x8004A0E4: addiu       $a1, $a1, -0x2
        ctx->r5 = ADD32(ctx->r5, -0X2);
            goto L_8004A0FC;
    }
    // 0x8004A0E4: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x8004A0E8: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8004A0EC: lb          $a0, 0x4A31($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X4A31);
    // 0x8004A0F0: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x8004A0F4: jal         0x800494E0
    // 0x8004A0F8: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    func_800494E0(rdram, ctx);
        goto after_26;
    // 0x8004A0F8: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    after_26:
L_8004A0FC:
    // 0x8004A0FC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004A100: addiu       $a0, $a0, 0x6AA0
    ctx->r4 = ADD32(ctx->r4, 0X6AA0);
    // 0x8004A104: jal         0x80017D38
    // 0x8004A108: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    func_80017D38(rdram, ctx);
        goto after_27;
    // 0x8004A108: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    after_27:
    // 0x8004A10C: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8004A110: bne         $v0, $s1, L_8004A120
    if (ctx->r2 != ctx->r17) {
        // 0x8004A114: nop
    
            goto L_8004A120;
    }
    // 0x8004A114: nop

    // 0x8004A118: jal         0x80051D6C
    // 0x8004A11C: nop

    func_80051D6C(rdram, ctx);
        goto after_28;
    // 0x8004A11C: nop

    after_28:
L_8004A120:
    // 0x8004A120: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8004A124: lbu         $a1, 0x4AC8($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X4AC8);
    // 0x8004A128: beq         $a1, $zero, L_8004A18C
    if (ctx->r5 == 0) {
        // 0x8004A12C: lui         $a0, 0xF650
        ctx->r4 = S32(0XF650 << 16);
            goto L_8004A18C;
    }
    // 0x8004A12C: lui         $a0, 0xF650
    ctx->r4 = S32(0XF650 << 16);
    // 0x8004A130: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004A134: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8004A138: ori         $a0, $a0, 0x330
    ctx->r4 = ctx->r4 | 0X330;
    // 0x8004A13C: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8004A140: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A144: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004A148: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x8004A14C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004A150: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8004A154: addiu       $v0, $v0, 0x6D70
    ctx->r2 = ADD32(ctx->r2, 0X6D70);
    // 0x8004A158: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8004A15C: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8004A160: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A164: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004A168: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x8004A16C: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8004A170: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8004A174: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A178: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004A17C: addiu       $v0, $zero, 0x90
    ctx->r2 = ADD32(0, 0X90);
    // 0x8004A180: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x8004A184: sw          $a0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r4;
    // 0x8004A188: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
L_8004A18C:
    // 0x8004A18C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A190: lbu         $v0, 0x4A30($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4A30);
    // 0x8004A194: beq         $v0, $zero, L_8004A1DC
    if (ctx->r2 == 0) {
        // 0x8004A198: nop
    
            goto L_8004A1DC;
    }
    // 0x8004A198: nop

    // 0x8004A19C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004A1A0: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x8004A1A4: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x8004A1A8: bne         $v0, $zero, L_8004A1DC
    if (ctx->r2 != 0) {
        // 0x8004A1AC: nop
    
            goto L_8004A1DC;
    }
    // 0x8004A1AC: nop

    // 0x8004A1B0: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8004A1B4: lbu         $a0, 0x4A31($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X4A31);
    // 0x8004A1B8: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8004A1BC: lbu         $a1, 0x4A32($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X4A32);
    // 0x8004A1C0: subu        $a0, $s1, $a0
    ctx->r4 = SUB32(ctx->r17, ctx->r4);
    // 0x8004A1C4: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x8004A1C8: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8004A1CC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8004A1D0: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x8004A1D4: jal         0x800494E0
    // 0x8004A1D8: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    func_800494E0(rdram, ctx);
        goto after_29;
    // 0x8004A1D8: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    after_29:
L_8004A1DC:
    // 0x8004A1DC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A1E0: lb          $v0, 0x4A33($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A33);
    // 0x8004A1E4: bne         $v0, $zero, L_8004A278
    if (ctx->r2 != 0) {
        // 0x8004A1E8: nop
    
            goto L_8004A278;
    }
    // 0x8004A1E8: nop

    // 0x8004A1EC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004A1F0: addiu       $a0, $a0, 0x6AA4
    ctx->r4 = ADD32(ctx->r4, 0X6AA4);
    // 0x8004A1F4: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x8004A1F8: bgtz        $v0, L_8004A4CC
    if (SIGNED(ctx->r2) > 0) {
        // 0x8004A1FC: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8004A4CC;
    }
    // 0x8004A1FC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004A200: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A204: lb          $v0, 0x4A35($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A35);
    // 0x8004A208: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004A20C: slti        $v0, $v0, 0x1E
    ctx->r2 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x8004A210: bne         $v0, $zero, L_8004A4F0
    if (ctx->r2 != 0) {
        // 0x8004A214: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8004A4F0;
    }
    // 0x8004A214: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8004A218: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004A21C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004A220: sb          $v0, 0x4A33($at)
    MEM_B(0X4A33, ctx->r1) = ctx->r2;
    // 0x8004A224: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x8004A228: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004A22C: bne         $v1, $v0, L_8004A26C
    if (ctx->r3 != ctx->r2) {
        // 0x8004A230: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8004A26C;
    }
    // 0x8004A230: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8004A234: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
L_8004A238:
    // 0x8004A238: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8004A23C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004A240: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004A244: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004A248: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004A24C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8004A250: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8004A254: sb          $zero, -0x7A70($at)
    MEM_B(-0X7A70, ctx->r1) = 0;
    // 0x8004A258: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8004A25C: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8004A260: sltiu       $v0, $v0, 0x5
    ctx->r2 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x8004A264: bne         $v0, $zero, L_8004A238
    if (ctx->r2 != 0) {
        // 0x8004A268: andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
            goto L_8004A238;
    }
    // 0x8004A268: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
L_8004A26C:
    // 0x8004A26C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004A270: j           L_8004A5D0
    // 0x8004A274: sb          $zero, 0x4AC9($at)
    MEM_B(0X4AC9, ctx->r1) = 0;
        goto L_8004A5D0;
    // 0x8004A274: sb          $zero, 0x4AC9($at)
    MEM_B(0X4AC9, ctx->r1) = 0;
L_8004A278:
    // 0x8004A278: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A27C: lb          $v0, 0x4A34($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A34);
    // 0x8004A280: bne         $v0, $zero, L_8004A5D0
    if (ctx->r2 != 0) {
        // 0x8004A284: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8004A5D0;
    }
    // 0x8004A284: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8004A288: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A28C: lbu         $v0, 0x4A31($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4A31);
    // 0x8004A290: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8004A294: lbu         $a1, 0x4A32($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X4A32);
    // 0x8004A298: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8004A29C: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x8004A2A0: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8004A2A4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8004A2A8: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x8004A2AC: jal         0x80049664
    // 0x8004A2B0: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    func_80049664(rdram, ctx);
        goto after_30;
    // 0x8004A2B0: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    after_30:
    // 0x8004A2B4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A2B8: lb          $v0, 0x4A36($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A36);
    // 0x8004A2BC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8004A2C0: slti        $v0, $v0, 0x8
    ctx->r2 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8004A2C4: beq         $v0, $zero, L_8004A5D0
    if (ctx->r2 == 0) {
        // 0x8004A2C8: nop
    
            goto L_8004A5D0;
    }
    // 0x8004A2C8: nop

    // 0x8004A2CC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A2D0: j           L_8004A5B8
    // 0x8004A2D4: addiu       $v0, $v0, 0x4AC8
    ctx->r2 = ADD32(ctx->r2, 0X4AC8);
        goto L_8004A5B8;
    // 0x8004A2D4: addiu       $v0, $v0, 0x4AC8
    ctx->r2 = ADD32(ctx->r2, 0X4AC8);
L_8004A2D8:
    // 0x8004A2D8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004A2DC: jal         0x80017D38
    // 0x8004A2E0: addiu       $a0, $a0, 0x6AA0
    ctx->r4 = ADD32(ctx->r4, 0X6AA0);
    func_80017D38(rdram, ctx);
        goto after_31;
    // 0x8004A2E0: addiu       $a0, $a0, 0x6AA0
    ctx->r4 = ADD32(ctx->r4, 0X6AA0);
    after_31:
    // 0x8004A2E4: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x8004A2E8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004A2EC: bne         $v1, $v0, L_8004A30C
    if (ctx->r3 != ctx->r2) {
        // 0x8004A2F0: nop
    
            goto L_8004A30C;
    }
    // 0x8004A2F0: nop

    // 0x8004A2F4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A2F8: lb          $v0, 0x4A33($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A33);
    // 0x8004A2FC: bne         $v0, $zero, L_8004A30C
    if (ctx->r2 != 0) {
        // 0x8004A300: nop
    
            goto L_8004A30C;
    }
    // 0x8004A300: nop

    // 0x8004A304: jal         0x80051D6C
    // 0x8004A308: nop

    func_80051D6C(rdram, ctx);
        goto after_32;
    // 0x8004A308: nop

    after_32:
L_8004A30C:
    // 0x8004A30C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8004A310: lbu         $a1, 0x4AC8($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X4AC8);
    // 0x8004A314: beq         $a1, $zero, L_8004A378
    if (ctx->r5 == 0) {
        // 0x8004A318: lui         $a0, 0xF650
        ctx->r4 = S32(0XF650 << 16);
            goto L_8004A378;
    }
    // 0x8004A318: lui         $a0, 0xF650
    ctx->r4 = S32(0XF650 << 16);
    // 0x8004A31C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004A320: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8004A324: ori         $a0, $a0, 0x330
    ctx->r4 = ctx->r4 | 0X330;
    // 0x8004A328: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8004A32C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A330: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004A334: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x8004A338: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004A33C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8004A340: addiu       $v0, $v0, 0x6D70
    ctx->r2 = ADD32(ctx->r2, 0X6D70);
    // 0x8004A344: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8004A348: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8004A34C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A350: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004A354: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x8004A358: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8004A35C: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8004A360: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A364: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004A368: addiu       $v0, $zero, 0x90
    ctx->r2 = ADD32(0, 0X90);
    // 0x8004A36C: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x8004A370: sw          $a0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r4;
    // 0x8004A374: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
L_8004A378:
    // 0x8004A378: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A37C: lb          $v0, 0x4A32($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A32);
    // 0x8004A380: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8004A384: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8004A388: bne         $v0, $zero, L_8004A3C8
    if (ctx->r2 != 0) {
        // 0x8004A38C: nop
    
            goto L_8004A3C8;
    }
    // 0x8004A38C: nop

    // 0x8004A390: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A394: lb          $v0, 0x4A33($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A33);
    // 0x8004A398: bne         $v0, $zero, L_8004A3C8
    if (ctx->r2 != 0) {
        // 0x8004A39C: nop
    
            goto L_8004A3C8;
    }
    // 0x8004A39C: nop

    // 0x8004A3A0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004A3A4: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x8004A3A8: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x8004A3AC: bne         $v0, $zero, L_8004A3C8
    if (ctx->r2 != 0) {
        // 0x8004A3B0: addiu       $a1, $a1, -0x2
        ctx->r5 = ADD32(ctx->r5, -0X2);
            goto L_8004A3C8;
    }
    // 0x8004A3B0: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x8004A3B4: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8004A3B8: lb          $a0, 0x4A31($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X4A31);
    // 0x8004A3BC: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x8004A3C0: jal         0x800494E0
    // 0x8004A3C4: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    func_800494E0(rdram, ctx);
        goto after_33;
    // 0x8004A3C4: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    after_33:
L_8004A3C8:
    // 0x8004A3C8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004A3CC: addiu       $a0, $a0, 0x6B10
    ctx->r4 = ADD32(ctx->r4, 0X6B10);
    // 0x8004A3D0: jal         0x80017D38
    // 0x8004A3D4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    func_80017D38(rdram, ctx);
        goto after_34;
    // 0x8004A3D4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    after_34:
    // 0x8004A3D8: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8004A3DC: bne         $v0, $s1, L_8004A3EC
    if (ctx->r2 != ctx->r17) {
        // 0x8004A3E0: nop
    
            goto L_8004A3EC;
    }
    // 0x8004A3E0: nop

    // 0x8004A3E4: jal         0x80051D6C
    // 0x8004A3E8: nop

    func_80051D6C(rdram, ctx);
        goto after_35;
    // 0x8004A3E8: nop

    after_35:
L_8004A3EC:
    // 0x8004A3EC: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8004A3F0: lbu         $a1, 0x4AC9($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X4AC9);
    // 0x8004A3F4: beq         $a1, $zero, L_8004A458
    if (ctx->r5 == 0) {
        // 0x8004A3F8: lui         $a0, 0xF650
        ctx->r4 = S32(0XF650 << 16);
            goto L_8004A458;
    }
    // 0x8004A3F8: lui         $a0, 0xF650
    ctx->r4 = S32(0XF650 << 16);
    // 0x8004A3FC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004A400: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8004A404: ori         $a0, $a0, 0x330
    ctx->r4 = ctx->r4 | 0X330;
    // 0x8004A408: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8004A40C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A410: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004A414: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x8004A418: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004A41C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8004A420: addiu       $v0, $v0, 0x6D70
    ctx->r2 = ADD32(ctx->r2, 0X6D70);
    // 0x8004A424: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8004A428: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8004A42C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A430: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004A434: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x8004A438: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8004A43C: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8004A440: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A444: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004A448: addiu       $v0, $zero, 0x90
    ctx->r2 = ADD32(0, 0X90);
    // 0x8004A44C: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x8004A450: sw          $a0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r4;
    // 0x8004A454: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
L_8004A458:
    // 0x8004A458: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A45C: lbu         $v0, 0x4A30($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4A30);
    // 0x8004A460: beq         $v0, $zero, L_8004A4A8
    if (ctx->r2 == 0) {
        // 0x8004A464: nop
    
            goto L_8004A4A8;
    }
    // 0x8004A464: nop

    // 0x8004A468: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004A46C: lbu         $v0, 0x7B71($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B71);
    // 0x8004A470: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x8004A474: bne         $v0, $zero, L_8004A4A8
    if (ctx->r2 != 0) {
        // 0x8004A478: nop
    
            goto L_8004A4A8;
    }
    // 0x8004A478: nop

    // 0x8004A47C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8004A480: lbu         $a0, 0x4A31($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X4A31);
    // 0x8004A484: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8004A488: lbu         $a1, 0x4A32($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X4A32);
    // 0x8004A48C: subu        $a0, $s1, $a0
    ctx->r4 = SUB32(ctx->r17, ctx->r4);
    // 0x8004A490: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x8004A494: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8004A498: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8004A49C: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x8004A4A0: jal         0x800494E0
    // 0x8004A4A4: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    func_800494E0(rdram, ctx);
        goto after_36;
    // 0x8004A4A4: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    after_36:
L_8004A4A8:
    // 0x8004A4A8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A4AC: lb          $v0, 0x4A33($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A33);
    // 0x8004A4B0: bne         $v0, $zero, L_8004A55C
    if (ctx->r2 != 0) {
        // 0x8004A4B4: nop
    
            goto L_8004A55C;
    }
    // 0x8004A4B4: nop

    // 0x8004A4B8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004A4BC: addiu       $a0, $a0, 0x6B14
    ctx->r4 = ADD32(ctx->r4, 0X6B14);
    // 0x8004A4C0: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x8004A4C4: blez        $v0, L_8004A4D8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004A4C8: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8004A4D8;
    }
    // 0x8004A4C8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8004A4CC:
    // 0x8004A4CC: addiu       $v0, $v1, -0x14
    ctx->r2 = ADD32(ctx->r3, -0X14);
    // 0x8004A4D0: j           L_8004A5D0
    // 0x8004A4D4: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
        goto L_8004A5D0;
    // 0x8004A4D4: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
L_8004A4D8:
    // 0x8004A4D8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A4DC: lb          $v0, 0x4A35($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A35);
    // 0x8004A4E0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004A4E4: slti        $v0, $v0, 0x1E
    ctx->r2 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x8004A4E8: beq         $v0, $zero, L_8004A4FC
    if (ctx->r2 == 0) {
        // 0x8004A4EC: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8004A4FC;
    }
    // 0x8004A4EC: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_8004A4F0:
    // 0x8004A4F0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004A4F4: j           L_8004A5D0
    // 0x8004A4F8: sb          $v0, 0x4A35($at)
    MEM_B(0X4A35, ctx->r1) = ctx->r2;
        goto L_8004A5D0;
    // 0x8004A4F8: sb          $v0, 0x4A35($at)
    MEM_B(0X4A35, ctx->r1) = ctx->r2;
L_8004A4FC:
    // 0x8004A4FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004A500: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004A504: sb          $v0, 0x4A33($at)
    MEM_B(0X4A33, ctx->r1) = ctx->r2;
    // 0x8004A508: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x8004A50C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004A510: bne         $v1, $v0, L_8004A550
    if (ctx->r3 != ctx->r2) {
        // 0x8004A514: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8004A550;
    }
    // 0x8004A514: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8004A518: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
L_8004A51C:
    // 0x8004A51C: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8004A520: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004A524: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004A528: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004A52C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004A530: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8004A534: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8004A538: sb          $zero, -0x7A70($at)
    MEM_B(-0X7A70, ctx->r1) = 0;
    // 0x8004A53C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8004A540: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8004A544: sltiu       $v0, $v0, 0x5
    ctx->r2 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x8004A548: bne         $v0, $zero, L_8004A51C
    if (ctx->r2 != 0) {
        // 0x8004A54C: andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
            goto L_8004A51C;
    }
    // 0x8004A54C: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
L_8004A550:
    // 0x8004A550: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004A554: j           L_8004A5D0
    // 0x8004A558: sb          $zero, 0x4AC8($at)
    MEM_B(0X4AC8, ctx->r1) = 0;
        goto L_8004A5D0;
    // 0x8004A558: sb          $zero, 0x4AC8($at)
    MEM_B(0X4AC8, ctx->r1) = 0;
L_8004A55C:
    // 0x8004A55C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A560: lb          $v0, 0x4A34($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A34);
    // 0x8004A564: bne         $v0, $zero, L_8004A5D0
    if (ctx->r2 != 0) {
        // 0x8004A568: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8004A5D0;
    }
    // 0x8004A568: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8004A56C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A570: lbu         $v0, 0x4A31($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4A31);
    // 0x8004A574: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8004A578: lbu         $a1, 0x4A32($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X4A32);
    // 0x8004A57C: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8004A580: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x8004A584: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8004A588: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8004A58C: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x8004A590: jal         0x80049664
    // 0x8004A594: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    func_80049664(rdram, ctx);
        goto after_37;
    // 0x8004A594: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    after_37:
    // 0x8004A598: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A59C: lb          $v0, 0x4A36($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4A36);
    // 0x8004A5A0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8004A5A4: slti        $v0, $v0, 0x8
    ctx->r2 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8004A5A8: beq         $v0, $zero, L_8004A5D0
    if (ctx->r2 == 0) {
        // 0x8004A5AC: nop
    
            goto L_8004A5D0;
    }
    // 0x8004A5AC: nop

    // 0x8004A5B0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004A5B4: addiu       $v0, $v0, 0x4AC9
    ctx->r2 = ADD32(ctx->r2, 0X4AC9);
L_8004A5B8:
    // 0x8004A5B8: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8004A5BC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8004A5C0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004A5C4: sb          $a0, 0x4A36($at)
    MEM_B(0X4A36, ctx->r1) = ctx->r4;
    // 0x8004A5C8: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    // 0x8004A5CC: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_8004A5D0:
    // 0x8004A5D0: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8004A5D4: addiu       $s0, $s0, 0x3520
    ctx->r16 = ADD32(ctx->r16, 0X3520);
    // 0x8004A5D8: jal         0x80017D38
    // 0x8004A5DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80017D38(rdram, ctx);
        goto after_38;
    // 0x8004A5DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_38:
    // 0x8004A5E0: jal         0x80017D38
    // 0x8004A5E4: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    func_80017D38(rdram, ctx);
        goto after_39;
    // 0x8004A5E4: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    after_39:
    // 0x8004A5E8: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x8004A5EC: lw          $s2, 0x80($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X80);
    // 0x8004A5F0: lw          $s1, 0x7C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X7C);
    // 0x8004A5F4: lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X78);
    // 0x8004A5F8: jr          $ra
    // 0x8004A5FC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8004A5FC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_8004A600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A600: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004A604: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x8004A608: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8004A60C: sll         $s1, $v0, 24
    ctx->r17 = S32(ctx->r2 << 24);
    // 0x8004A610: sra         $s1, $s1, 24
    ctx->r17 = S32(SIGNED(ctx->r17) >> 24);
    // 0x8004A614: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004A618: sll         $s0, $s1, 3
    ctx->r16 = S32(ctx->r17 << 3);
    // 0x8004A61C: subu        $s0, $s0, $s1
    ctx->r16 = SUB32(ctx->r16, ctx->r17);
    // 0x8004A620: sll         $s0, $s0, 4
    ctx->r16 = S32(ctx->r16 << 4);
    // 0x8004A624: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004A628: addiu       $a0, $a0, 0x6AA0
    ctx->r4 = ADD32(ctx->r4, 0X6AA0);
    // 0x8004A62C: addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    // 0x8004A630: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8004A634: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8004A638: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8004A63C: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8004A640: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8004A644: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8004A648: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004A64C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8004A650: sb          $zero, 0x6ACA($at)
    MEM_B(0X6ACA, ctx->r1) = 0;
    // 0x8004A654: jal         0x80017760
    // 0x8004A658: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    func_80017760(rdram, ctx);
        goto after_0;
    // 0x8004A658: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    after_0:
    // 0x8004A65C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004A660: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004A664: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8004A668: sb          $v0, 0x6AB6($at)
    MEM_B(0X6AB6, ctx->r1) = ctx->r2;
    // 0x8004A66C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004A670: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004A674: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8004A678: sb          $v0, 0x6AB7($at)
    MEM_B(0X6AB7, ctx->r1) = ctx->r2;
    // 0x8004A67C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004A680: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8004A684: sh          $zero, 0x6AB8($at)
    MEM_H(0X6AB8, ctx->r1) = 0;
    // 0x8004A688: bne         $s1, $zero, L_8004A6B4
    if (ctx->r17 != 0) {
        // 0x8004A68C: sll         $v1, $s3, 24
        ctx->r3 = S32(ctx->r19 << 24);
            goto L_8004A6B4;
    }
    // 0x8004A68C: sll         $v1, $s3, 24
    ctx->r3 = S32(ctx->r19 << 24);
    // 0x8004A690: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8004A694: addiu       $v0, $v0, -0x75C0
    ctx->r2 = ADD32(ctx->r2, -0X75C0);
    // 0x8004A698: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004A69C: sw          $v0, 0x6AB0($at)
    MEM_W(0X6AB0, ctx->r1) = ctx->r2;
    // 0x8004A6A0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004A6A4: addiu       $v0, $v0, -0x2338
    ctx->r2 = ADD32(ctx->r2, -0X2338);
    // 0x8004A6A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004A6AC: j           L_8004A6D4
    // 0x8004A6B0: sw          $v0, 0x6AD0($at)
    MEM_W(0X6AD0, ctx->r1) = ctx->r2;
        goto L_8004A6D4;
    // 0x8004A6B0: sw          $v0, 0x6AD0($at)
    MEM_W(0X6AD0, ctx->r1) = ctx->r2;
L_8004A6B4:
    // 0x8004A6B4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8004A6B8: addiu       $v0, $v0, -0x1DC0
    ctx->r2 = ADD32(ctx->r2, -0X1DC0);
    // 0x8004A6BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004A6C0: sw          $v0, 0x6B20($at)
    MEM_W(0X6B20, ctx->r1) = ctx->r2;
    // 0x8004A6C4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004A6C8: addiu       $v0, $v0, -0x2538
    ctx->r2 = ADD32(ctx->r2, -0X2538);
    // 0x8004A6CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004A6D0: sw          $v0, 0x6B40($at)
    MEM_W(0X6B40, ctx->r1) = ctx->r2;
L_8004A6D4:
    // 0x8004A6D4: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8004A6D8: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x8004A6DC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8004A6E0: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x8004A6E4: sll         $v0, $s2, 24
    ctx->r2 = S32(ctx->r18 << 24);
    // 0x8004A6E8: sra         $v0, $v0, 21
    ctx->r2 = S32(SIGNED(ctx->r2) >> 21);
    // 0x8004A6EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004A6F0: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8004A6F4: sw          $zero, 0x6AE4($at)
    MEM_W(0X6AE4, ctx->r1) = 0;
    // 0x8004A6F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004A6FC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8004A700: sw          $zero, 0x6AE8($at)
    MEM_W(0X6AE8, ctx->r1) = 0;
    // 0x8004A704: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004A708: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004A70C: lw          $v1, 0x1050($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1050);
    // 0x8004A710: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8004A714: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8004A718: lw          $a1, 0x1054($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1054);
    // 0x8004A71C: sll         $v0, $s4, 24
    ctx->r2 = S32(ctx->r20 << 24);
    // 0x8004A720: beq         $v0, $zero, L_8004A73C
    if (ctx->r2 == 0) {
        // 0x8004A724: addiu       $v0, $zero, 0x500
        ctx->r2 = ADD32(0, 0X500);
            goto L_8004A73C;
    }
    // 0x8004A724: addiu       $v0, $zero, 0x500
    ctx->r2 = ADD32(0, 0X500);
    // 0x8004A728: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004A72C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8004A730: sh          $zero, 0x6AA4($at)
    MEM_H(0X6AA4, ctx->r1) = 0;
    // 0x8004A734: j           L_8004A74C
    // 0x8004A738: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
        goto L_8004A74C;
    // 0x8004A738: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
L_8004A73C:
    // 0x8004A73C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004A740: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8004A744: sh          $v0, 0x6AA4($at)
    MEM_H(0X6AA4, ctx->r1) = ctx->r2;
    // 0x8004A748: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
L_8004A74C:
    // 0x8004A74C: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x8004A750: sll         $s0, $s3, 24
    ctx->r16 = S32(ctx->r19 << 24);
    // 0x8004A754: sra         $s0, $s0, 24
    ctx->r16 = S32(SIGNED(ctx->r16) >> 24);
    // 0x8004A758: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x8004A75C: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x8004A760: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8004A764: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004A768: addiu       $a0, $a0, 0x6AA0
    ctx->r4 = ADD32(ctx->r4, 0X6AA0);
    // 0x8004A76C: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x8004A770: sh          $v1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r3;
    // 0x8004A774: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004A778: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004A77C: sh          $v1, 0x6AA2($at)
    MEM_H(0X6AA2, ctx->r1) = ctx->r3;
    // 0x8004A780: sh          $a1, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r5;
    // 0x8004A784: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004A788: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004A78C: jal         0x80066D30
    // 0x8004A790: sh          $a1, 0x6AAA($at)
    MEM_H(0X6AAA, ctx->r1) = ctx->r5;
    func_80066D30(rdram, ctx);
        goto after_1;
    // 0x8004A790: sh          $a1, 0x6AAA($at)
    MEM_H(0X6AAA, ctx->r1) = ctx->r5;
    after_1:
    // 0x8004A794: bne         $s0, $zero, L_8004A7E8
    if (ctx->r16 != 0) {
        // 0x8004A798: sll         $v0, $s2, 24
        ctx->r2 = S32(ctx->r18 << 24);
            goto L_8004A7E8;
    }
    // 0x8004A798: sll         $v0, $s2, 24
    ctx->r2 = S32(ctx->r18 << 24);
    // 0x8004A79C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004A7A0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004A7A4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004A7A8: lb          $v1, 0x1044($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X1044);
    // 0x8004A7AC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8004A7B0: addiu       $a0, $a0, -0x65D0
    ctx->r4 = ADD32(ctx->r4, -0X65D0);
    // 0x8004A7B4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004A7B8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A7BC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004A7C0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004A7C4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8004A7C8: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8004A7CC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8004A7D0: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x8004A7D4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8004A7D8: addiu       $a1, $a1, -0x2338
    ctx->r5 = ADD32(ctx->r5, -0X2338);
    // 0x8004A7DC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8004A7E0: j           L_8004A830
    // 0x8004A7E4: addiu       $a2, $a2, -0x75C0
    ctx->r6 = ADD32(ctx->r6, -0X75C0);
        goto L_8004A830;
    // 0x8004A7E4: addiu       $a2, $a2, -0x75C0
    ctx->r6 = ADD32(ctx->r6, -0X75C0);
L_8004A7E8:
    // 0x8004A7E8: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004A7EC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004A7F0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004A7F4: lb          $v1, 0x1044($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X1044);
    // 0x8004A7F8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8004A7FC: addiu       $a0, $a0, -0x65D0
    ctx->r4 = ADD32(ctx->r4, -0X65D0);
    // 0x8004A800: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004A804: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004A808: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004A80C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004A810: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8004A814: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8004A818: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8004A81C: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x8004A820: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8004A824: addiu       $a1, $a1, -0x2538
    ctx->r5 = ADD32(ctx->r5, -0X2538);
    // 0x8004A828: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8004A82C: addiu       $a2, $a2, -0x1DC0
    ctx->r6 = ADD32(ctx->r6, -0X1DC0);
L_8004A830:
    // 0x8004A830: jal         0x80053078
    // 0x8004A834: nop

    func_80053078(rdram, ctx);
        goto after_2;
    // 0x8004A834: nop

    after_2:
    // 0x8004A838: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8004A83C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8004A840: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8004A844: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8004A848: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8004A84C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004A850: jr          $ra
    // 0x8004A854: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8004A854: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8004A858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A858: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004A85C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004A860: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8004A864: addiu       $s0, $s0, 0x354A
    ctx->r16 = ADD32(ctx->r16, 0X354A);
    // 0x8004A868: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8004A86C: addiu       $s1, $s0, -0x2A
    ctx->r17 = ADD32(ctx->r16, -0X2A);
    // 0x8004A870: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004A874: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004A878: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8004A87C: jal         0x80017760
    // 0x8004A880: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    func_80017760(rdram, ctx);
        goto after_0;
    // 0x8004A880: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    after_0:
    // 0x8004A884: addiu       $v0, $zero, 0xC0
    ctx->r2 = ADD32(0, 0XC0);
    // 0x8004A888: lui         $s2, 0x8010
    ctx->r18 = S32(0X8010 << 16);
    // 0x8004A88C: addiu       $s2, $s2, 0x3040
    ctx->r18 = ADD32(ctx->r18, 0X3040);
    // 0x8004A890: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004A894: sh          $v0, 0x352A($at)
    MEM_H(0X352A, ctx->r1) = ctx->r2;
    // 0x8004A898: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004A89C: sh          $v0, 0x352E($at)
    MEM_H(0X352E, ctx->r1) = ctx->r2;
    // 0x8004A8A0: addiu       $v0, $zero, 0x2A0
    ctx->r2 = ADD32(0, 0X2A0);
    // 0x8004A8A4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004A8A8: sw          $s2, 0x3530($at)
    MEM_W(0X3530, ctx->r1) = ctx->r18;
    // 0x8004A8AC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004A8B0: sh          $v0, 0x352C($at)
    MEM_H(0X352C, ctx->r1) = ctx->r2;
    // 0x8004A8B4: jal         0x80066D30
    // 0x8004A8B8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80066D30(rdram, ctx);
        goto after_1;
    // 0x8004A8B8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x8004A8BC: addiu       $s1, $s0, 0x46
    ctx->r17 = ADD32(ctx->r16, 0X46);
    // 0x8004A8C0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004A8C4: jal         0x80017760
    // 0x8004A8C8: sb          $zero, 0x70($s0)
    MEM_B(0X70, ctx->r16) = 0;
    func_80017760(rdram, ctx);
        goto after_2;
    // 0x8004A8C8: sb          $zero, 0x70($s0)
    MEM_B(0X70, ctx->r16) = 0;
    after_2:
    // 0x8004A8CC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004A8D0: addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // 0x8004A8D4: sh          $v0, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r2;
    // 0x8004A8D8: sh          $v0, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r2;
    // 0x8004A8DC: addiu       $v0, $s2, 0x7800
    ctx->r2 = ADD32(ctx->r18, 0X7800);
    // 0x8004A8E0: sw          $v0, 0x56($s0)
    MEM_W(0X56, ctx->r16) = ctx->r2;
    // 0x8004A8E4: addiu       $v0, $zero, 0x360
    ctx->r2 = ADD32(0, 0X360);
    // 0x8004A8E8: jal         0x80066D30
    // 0x8004A8EC: sh          $v0, 0x52($s0)
    MEM_H(0X52, ctx->r16) = ctx->r2;
    func_80066D30(rdram, ctx);
        goto after_3;
    // 0x8004A8EC: sh          $v0, 0x52($s0)
    MEM_H(0X52, ctx->r16) = ctx->r2;
    after_3:
    // 0x8004A8F0: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x8004A8F4: addiu       $a0, $a0, -0x1EC0
    ctx->r4 = ADD32(ctx->r4, -0X1EC0);
    // 0x8004A8F8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8004A8FC: jal         0x80006D98
    // 0x8004A900: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    func_80006D98(rdram, ctx);
        goto after_4;
    // 0x8004A900: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    after_4:
    // 0x8004A904: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004A908: lb          $v0, 0x1040($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X1040);
    // 0x8004A90C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8004A910: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004A914: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x8004A918: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8004A91C: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x8004A920: jal         0x8004A600
    // 0x8004A924: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    func_8004A600(rdram, ctx);
        goto after_5;
    // 0x8004A924: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    after_5:
    // 0x8004A928: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8004A92C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8004A930: jal         0x8004A600
    // 0x8004A934: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_8004A600(rdram, ctx);
        goto after_6;
    // 0x8004A934: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_6:
    // 0x8004A938: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004A93C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8004A940: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8004A944: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004A948: jr          $ra
    // 0x8004A94C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8004A94C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8004A950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A950: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8004A954: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8004A958: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x8004A95C: addiu       $s2, $s2, 0x7B71
    ctx->r18 = ADD32(ctx->r18, 0X7B71);
    // 0x8004A960: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8004A964: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8004A968: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8004A96C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8004A970: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
    // 0x8004A974: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8004A978: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8004A97C: beq         $v1, $s3, L_8004AB24
    if (ctx->r3 == ctx->r19) {
        // 0x8004A980: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8004AB24;
    }
    // 0x8004A980: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8004A984: beql        $v0, $zero, L_8004A99C
    if (ctx->r2 == 0) {
        // 0x8004A988: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8004A99C;
    }
    goto skip_0;
    // 0x8004A988: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8004A98C: beq         $v1, $zero, L_8004A9B4
    if (ctx->r3 == 0) {
        // 0x8004A990: nop
    
            goto L_8004A9B4;
    }
    // 0x8004A990: nop

    // 0x8004A994: j           L_8004ACC0
    // 0x8004A998: nop

        goto L_8004ACC0;
    // 0x8004A998: nop

L_8004A99C:
    // 0x8004A99C: beq         $v1, $v0, L_8004AB44
    if (ctx->r3 == ctx->r2) {
        // 0x8004A9A0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8004AB44;
    }
    // 0x8004A9A0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004A9A4: beq         $v1, $v0, L_8004ABE8
    if (ctx->r3 == ctx->r2) {
        // 0x8004A9A8: nop
    
            goto L_8004ABE8;
    }
    // 0x8004A9A8: nop

    // 0x8004A9AC: j           L_8004ACC0
    // 0x8004A9B0: nop

        goto L_8004ACC0;
    // 0x8004A9B0: nop

L_8004A9B4:
    // 0x8004A9B4: jal         0x8000BB3C
    // 0x8004A9B8: nop

    func_8000BB3C(rdram, ctx);
        goto after_0;
    // 0x8004A9B8: nop

    after_0:
    // 0x8004A9BC: jal         0x80057720
    // 0x8004A9C0: nop

    func_80057720(rdram, ctx);
        goto after_1;
    // 0x8004A9C0: nop

    after_1:
    // 0x8004A9C4: jal         0x8002D378
    // 0x8004A9C8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D378(rdram, ctx);
        goto after_2;
    // 0x8004A9C8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x8004A9CC: jal         0x8002D0D4
    // 0x8004A9D0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8002D0D4(rdram, ctx);
        goto after_3;
    // 0x8004A9D0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x8004A9D4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004A9D8: lb          $v1, 0x1040($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X1040);
    // 0x8004A9DC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004A9E0: addiu       $a0, $a0, 0x3520
    ctx->r4 = ADD32(ctx->r4, 0X3520);
    // 0x8004A9E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004A9E8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004A9EC: sb          $zero, 0x4AD0($at)
    MEM_B(0X4AD0, ctx->r1) = 0;
    // 0x8004A9F0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004A9F4: sb          $v0, 0x4AD2($at)
    MEM_B(0X4AD2, ctx->r1) = ctx->r2;
    // 0x8004A9F8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004A9FC: sb          $zero, 0x4AD3($at)
    MEM_B(0X4AD3, ctx->r1) = 0;
    // 0x8004AA00: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AA04: sb          $zero, 0x354A($at)
    MEM_B(0X354A, ctx->r1) = 0;
    // 0x8004AA08: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004AA0C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004AA10: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004AA14: jal         0x80017760
    // 0x8004AA18: sb          $v0, 0x4AD1($at)
    MEM_B(0X4AD1, ctx->r1) = ctx->r2;
    func_80017760(rdram, ctx);
        goto after_4;
    // 0x8004AA18: sb          $v0, 0x4AD1($at)
    MEM_B(0X4AD1, ctx->r1) = ctx->r2;
    after_4:
    // 0x8004AA1C: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8004AA20: addiu       $s0, $s0, 0x352A
    ctx->r16 = ADD32(ctx->r16, 0X352A);
    // 0x8004AA24: addiu       $v0, $zero, 0xC0
    ctx->r2 = ADD32(0, 0XC0);
    // 0x8004AA28: lui         $s1, 0x8010
    ctx->r17 = S32(0X8010 << 16);
    // 0x8004AA2C: addiu       $s1, $s1, 0x3040
    ctx->r17 = ADD32(ctx->r17, 0X3040);
    // 0x8004AA30: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x8004AA34: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AA38: sh          $v0, 0x352E($at)
    MEM_H(0X352E, ctx->r1) = ctx->r2;
    // 0x8004AA3C: addiu       $v0, $zero, 0x2A0
    ctx->r2 = ADD32(0, 0X2A0);
    // 0x8004AA40: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AA44: sw          $s1, 0x3530($at)
    MEM_W(0X3530, ctx->r1) = ctx->r17;
    // 0x8004AA48: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AA4C: sh          $v0, 0x352C($at)
    MEM_H(0X352C, ctx->r1) = ctx->r2;
    // 0x8004AA50: jal         0x80066D30
    // 0x8004AA54: addiu       $a0, $s0, -0xA
    ctx->r4 = ADD32(ctx->r16, -0XA);
    func_80066D30(rdram, ctx);
        goto after_5;
    // 0x8004AA54: addiu       $a0, $s0, -0xA
    ctx->r4 = ADD32(ctx->r16, -0XA);
    after_5:
    // 0x8004AA58: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AA5C: sb          $zero, 0x35BA($at)
    MEM_B(0X35BA, ctx->r1) = 0;
    // 0x8004AA60: jal         0x80017760
    // 0x8004AA64: addiu       $a0, $s0, 0x66
    ctx->r4 = ADD32(ctx->r16, 0X66);
    func_80017760(rdram, ctx);
        goto after_6;
    // 0x8004AA64: addiu       $a0, $s0, 0x66
    ctx->r4 = ADD32(ctx->r16, 0X66);
    after_6:
    // 0x8004AA68: addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // 0x8004AA6C: sh          $v0, 0x70($s0)
    MEM_H(0X70, ctx->r16) = ctx->r2;
    // 0x8004AA70: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AA74: sh          $v0, 0x359E($at)
    MEM_H(0X359E, ctx->r1) = ctx->r2;
    // 0x8004AA78: addiu       $v0, $s1, 0x7800
    ctx->r2 = ADD32(ctx->r17, 0X7800);
    // 0x8004AA7C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AA80: sw          $v0, 0x35A0($at)
    MEM_W(0X35A0, ctx->r1) = ctx->r2;
    // 0x8004AA84: addiu       $v0, $zero, 0x360
    ctx->r2 = ADD32(0, 0X360);
    // 0x8004AA88: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AA8C: sh          $v0, 0x359C($at)
    MEM_H(0X359C, ctx->r1) = ctx->r2;
    // 0x8004AA90: jal         0x80066D30
    // 0x8004AA94: addiu       $a0, $s0, 0x66
    ctx->r4 = ADD32(ctx->r16, 0X66);
    func_80066D30(rdram, ctx);
        goto after_7;
    // 0x8004AA94: addiu       $a0, $s0, 0x66
    ctx->r4 = ADD32(ctx->r16, 0X66);
    after_7:
    // 0x8004AA98: lui         $a0, 0x10
    ctx->r4 = S32(0X10 << 16);
    // 0x8004AA9C: addiu       $a0, $a0, -0x1EC0
    ctx->r4 = ADD32(ctx->r4, -0X1EC0);
    // 0x8004AAA0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8004AAA4: jal         0x80006D98
    // 0x8004AAA8: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    func_80006D98(rdram, ctx);
        goto after_8;
    // 0x8004AAA8: ori         $a2, $zero, 0xF000
    ctx->r6 = 0 | 0XF000;
    after_8:
    // 0x8004AAAC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004AAB0: lb          $v0, 0x1040($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X1040);
    // 0x8004AAB4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8004AAB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004AABC: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x8004AAC0: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8004AAC4: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x8004AAC8: jal         0x8004A600
    // 0x8004AACC: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    func_8004A600(rdram, ctx);
        goto after_9;
    // 0x8004AACC: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    after_9:
    // 0x8004AAD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8004AAD4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8004AAD8: jal         0x8004A600
    // 0x8004AADC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_8004A600(rdram, ctx);
        goto after_10;
    // 0x8004AADC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_10:
    // 0x8004AAE0: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8004AAE4: lbu         $v1, 0x4AD1($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4AD1);
    // 0x8004AAE8: addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // 0x8004AAEC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AAF0: sh          $v0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r2;
    // 0x8004AAF4: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
    // 0x8004AAF8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004AAFC: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
    // 0x8004AB00: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004AB04: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8004AB08: subu        $v0, $s3, $v0
    ctx->r2 = SUB32(ctx->r19, ctx->r2);
    // 0x8004AB0C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004AB10: sb          $v0, 0x4AD0($at)
    MEM_B(0X4AD0, ctx->r1) = ctx->r2;
    // 0x8004AB14: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004AB18: sb          $v1, 0x4AD1($at)
    MEM_B(0X4AD1, ctx->r1) = ctx->r3;
    // 0x8004AB1C: j           L_8004ACC0
    // 0x8004AB20: sb          $a0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r4;
        goto L_8004ACC0;
    // 0x8004AB20: sb          $a0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r4;
L_8004AB24:
    // 0x8004AB24: jal         0x8002CFB8
    // 0x8004AB28: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8002CFB8(rdram, ctx);
        goto after_11;
    // 0x8004AB28: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x8004AB2C: beq         $v0, $zero, L_8004ACC0
    if (ctx->r2 == 0) {
        // 0x8004AB30: nop
    
            goto L_8004ACC0;
    }
    // 0x8004AB30: nop

    // 0x8004AB34: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8004AB38: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004AB3C: j           L_8004ACC0
    // 0x8004AB40: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
        goto L_8004ACC0;
    // 0x8004AB40: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_8004AB44:
    // 0x8004AB44: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004AB48: lh          $v0, 0x7B74($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7B74);
    // 0x8004AB4C: bne         $v0, $zero, L_8004ACC0
    if (ctx->r2 != 0) {
        // 0x8004AB50: nop
    
            goto L_8004ACC0;
    }
    // 0x8004AB50: nop

    // 0x8004AB54: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004AB58: lb          $v1, 0x1040($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X1040);
    // 0x8004AB5C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8004AB60: lb          $a1, 0x4AD1($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X4AD1);
    // 0x8004AB64: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004AB68: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004AB6C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004AB70: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004AB74: beq         $v0, $zero, L_8004ABD0
    if (ctx->r2 == 0) {
        // 0x8004AB78: addiu       $v0, $zero, 0xF0
        ctx->r2 = ADD32(0, 0XF0);
            goto L_8004ABD0;
    }
    // 0x8004AB78: addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // 0x8004AB7C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8004AB80: lb          $a0, 0x4AD0($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X4AD0);
    // 0x8004AB84: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AB88: sh          $v0, 0x7B74($at)
    MEM_H(0X7B74, ctx->r1) = ctx->r2;
    // 0x8004AB8C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004AB90: sb          $zero, 0x4AD2($at)
    MEM_B(0X4AD2, ctx->r1) = 0;
    // 0x8004AB94: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004AB98: sb          $zero, 0x4AD3($at)
    MEM_B(0X4AD3, ctx->r1) = 0;
    // 0x8004AB9C: jal         0x8004A600
    // 0x8004ABA0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_8004A600(rdram, ctx);
        goto after_12;
    // 0x8004ABA0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_12:
    // 0x8004ABA4: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8004ABA8: lbu         $v1, 0x4AD1($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4AD1);
    // 0x8004ABAC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004ABB0: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
    // 0x8004ABB4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004ABB8: subu        $v0, $s3, $v0
    ctx->r2 = SUB32(ctx->r19, ctx->r2);
    // 0x8004ABBC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004ABC0: sb          $v0, 0x4AD0($at)
    MEM_B(0X4AD0, ctx->r1) = ctx->r2;
    // 0x8004ABC4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004ABC8: j           L_8004ACC0
    // 0x8004ABCC: sb          $v1, 0x4AD1($at)
    MEM_B(0X4AD1, ctx->r1) = ctx->r3;
        goto L_8004ACC0;
    // 0x8004ABCC: sb          $v1, 0x4AD1($at)
    MEM_B(0X4AD1, ctx->r1) = ctx->r3;
L_8004ABD0:
    // 0x8004ABD0: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8004ABD4: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // 0x8004ABD8: jal         0x800067B0
    // 0x8004ABDC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800067B0(rdram, ctx);
        goto after_13;
    // 0x8004ABDC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_13:
    // 0x8004ABE0: j           L_8004ACC0
    // 0x8004ABE4: nop

        goto L_8004ACC0;
    // 0x8004ABE4: nop

L_8004ABE8:
    // 0x8004ABE8: jal         0x8002CFB8
    // 0x8004ABEC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8002CFB8(rdram, ctx);
        goto after_14;
    // 0x8004ABEC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_14:
    // 0x8004ABF0: beq         $v0, $zero, L_8004ACC0
    if (ctx->r2 == 0) {
        // 0x8004ABF4: addiu       $s0, $zero, 0x4
        ctx->r16 = ADD32(0, 0X4);
            goto L_8004ACC0;
    }
    // 0x8004ABF4: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x8004ABF8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004ABFC: lbu         $v0, 0x1040($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1040);
    // 0x8004AC00: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AC04: sb          $zero, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = 0;
    // 0x8004AC08: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x8004AC0C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AC10: sb          $s0, 0x5581($at)
    MEM_B(0X5581, ctx->r1) = ctx->r16;
    // 0x8004AC14: subu        $v0, $s3, $v0
    ctx->r2 = SUB32(ctx->r19, ctx->r2);
    // 0x8004AC18: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004AC1C: jal         0x80006998
    // 0x8004AC20: sb          $v0, 0x1040($at)
    MEM_B(0X1040, ctx->r1) = ctx->r2;
    func_80006998(rdram, ctx);
        goto after_15;
    // 0x8004AC20: sb          $v0, 0x1040($at)
    MEM_B(0X1040, ctx->r1) = ctx->r2;
    after_15:
    // 0x8004AC24: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004AC28: lbu         $v1, 0x5584($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X5584);
    // 0x8004AC2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004AC30: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AC34: sb          $v0, 0x7B85($at)
    MEM_B(0X7B85, ctx->r1) = ctx->r2;
    // 0x8004AC38: addiu       $v0, $zero, 0xBB8
    ctx->r2 = ADD32(0, 0XBB8);
    // 0x8004AC3C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AC40: sh          $v0, 0x5588($at)
    MEM_H(0X5588, ctx->r1) = ctx->r2;
    // 0x8004AC44: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004AC48: lbu         $v0, 0x25A5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X25A5);
    // 0x8004AC4C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AC50: sb          $v1, 0x7B8B($at)
    MEM_B(0X7B8B, ctx->r1) = ctx->r3;
    // 0x8004AC54: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004AC58: lbu         $v1, 0x79F5($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X79F5);
    // 0x8004AC5C: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    // 0x8004AC60: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AC64: sb          $zero, 0x5582($at)
    MEM_B(0X5582, ctx->r1) = 0;
    // 0x8004AC68: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AC6C: sb          $zero, 0x5583($at)
    MEM_B(0X5583, ctx->r1) = 0;
    // 0x8004AC70: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AC74: sb          $zero, 0x7B98($at)
    MEM_B(0X7B98, ctx->r1) = 0;
    // 0x8004AC78: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AC7C: sb          $zero, 0x7A4A($at)
    MEM_B(0X7A4A, ctx->r1) = 0;
    // 0x8004AC80: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AC84: sb          $zero, 0x25FA($at)
    MEM_B(0X25FA, ctx->r1) = 0;
    // 0x8004AC88: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AC8C: sb          $zero, 0x79F0($at)
    MEM_B(0X79F0, ctx->r1) = 0;
    // 0x8004AC90: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AC94: sb          $zero, 0x25A0($at)
    MEM_B(0X25A0, ctx->r1) = 0;
    // 0x8004AC98: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AC9C: sb          $s0, 0x25FC($at)
    MEM_B(0X25FC, ctx->r1) = ctx->r16;
    // 0x8004ACA0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004ACA4: sb          $s0, 0x7A4C($at)
    MEM_B(0X7A4C, ctx->r1) = ctx->r16;
    // 0x8004ACA8: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8004ACAC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004ACB0: sb          $v0, 0x25A5($at)
    MEM_B(0X25A5, ctx->r1) = ctx->r2;
    // 0x8004ACB4: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x8004ACB8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004ACBC: sb          $v1, 0x79F5($at)
    MEM_B(0X79F5, ctx->r1) = ctx->r3;
L_8004ACC0:
    // 0x8004ACC0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004ACC4: lb          $v0, 0x4AD0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4AD0);
    // 0x8004ACC8: beq         $v0, $zero, L_8004AD28
    if (ctx->r2 == 0) {
        // 0x8004ACCC: nop
    
            goto L_8004AD28;
    }
    // 0x8004ACCC: nop

    // 0x8004ACD0: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8004ACD4: addiu       $s0, $s0, 0x6B10
    ctx->r16 = ADD32(ctx->r16, 0X6B10);
    // 0x8004ACD8: jal         0x80017D38
    // 0x8004ACDC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80017D38(rdram, ctx);
        goto after_16;
    // 0x8004ACDC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_16:
    // 0x8004ACE0: jal         0x80017D38
    // 0x8004ACE4: addiu       $a0, $s0, -0x70
    ctx->r4 = ADD32(ctx->r16, -0X70);
    func_80017D38(rdram, ctx);
        goto after_17;
    // 0x8004ACE4: addiu       $a0, $s0, -0x70
    ctx->r4 = ADD32(ctx->r16, -0X70);
    after_17:
    // 0x8004ACE8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004ACEC: lb          $v0, 0x4AD2($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4AD2);
    // 0x8004ACF0: bne         $v0, $zero, L_8004AD18
    if (ctx->r2 != 0) {
        // 0x8004ACF4: nop
    
            goto L_8004AD18;
    }
    // 0x8004ACF4: nop

    // 0x8004ACF8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004ACFC: lh          $v0, 0x6AA4($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6AA4);
    // 0x8004AD00: blez        $v0, L_8004AD70
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004AD04: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8004AD70;
    }
    // 0x8004AD04: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004AD08: addiu       $v0, $v1, -0x14
    ctx->r2 = ADD32(ctx->r3, -0X14);
    // 0x8004AD0C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AD10: j           L_8004AD9C
    // 0x8004AD14: sh          $v0, 0x6AA4($at)
    MEM_H(0X6AA4, ctx->r1) = ctx->r2;
        goto L_8004AD9C;
    // 0x8004AD14: sh          $v0, 0x6AA4($at)
    MEM_H(0X6AA4, ctx->r1) = ctx->r2;
L_8004AD18:
    // 0x8004AD18: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004AD1C: addiu       $a0, $a0, 0x7B74
    ctx->r4 = ADD32(ctx->r4, 0X7B74);
    // 0x8004AD20: j           L_8004AD8C
    // 0x8004AD24: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
        goto L_8004AD8C;
    // 0x8004AD24: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
L_8004AD28:
    // 0x8004AD28: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8004AD2C: addiu       $s0, $s0, 0x6AA0
    ctx->r16 = ADD32(ctx->r16, 0X6AA0);
    // 0x8004AD30: jal         0x80017D38
    // 0x8004AD34: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80017D38(rdram, ctx);
        goto after_18;
    // 0x8004AD34: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_18:
    // 0x8004AD38: jal         0x80017D38
    // 0x8004AD3C: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    func_80017D38(rdram, ctx);
        goto after_19;
    // 0x8004AD3C: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    after_19:
    // 0x8004AD40: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004AD44: lb          $v0, 0x4AD2($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4AD2);
    // 0x8004AD48: bne         $v0, $zero, L_8004AD80
    if (ctx->r2 != 0) {
        // 0x8004AD4C: nop
    
            goto L_8004AD80;
    }
    // 0x8004AD4C: nop

    // 0x8004AD50: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004AD54: lh          $v0, 0x6B14($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6B14);
    // 0x8004AD58: blez        $v0, L_8004AD70
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004AD5C: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8004AD70;
    }
    // 0x8004AD5C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004AD60: addiu       $v0, $v1, -0x14
    ctx->r2 = ADD32(ctx->r3, -0X14);
    // 0x8004AD64: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004AD68: j           L_8004AD9C
    // 0x8004AD6C: sh          $v0, 0x6B14($at)
    MEM_H(0X6B14, ctx->r1) = ctx->r2;
        goto L_8004AD9C;
    // 0x8004AD6C: sh          $v0, 0x6B14($at)
    MEM_H(0X6B14, ctx->r1) = ctx->r2;
L_8004AD70:
    // 0x8004AD70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004AD74: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004AD78: j           L_8004AD9C
    // 0x8004AD7C: sb          $v0, 0x4AD2($at)
    MEM_B(0X4AD2, ctx->r1) = ctx->r2;
        goto L_8004AD9C;
    // 0x8004AD7C: sb          $v0, 0x4AD2($at)
    MEM_B(0X4AD2, ctx->r1) = ctx->r2;
L_8004AD80:
    // 0x8004AD80: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004AD84: addiu       $a0, $a0, 0x7B74
    ctx->r4 = ADD32(ctx->r4, 0X7B74);
    // 0x8004AD88: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
L_8004AD8C:
    // 0x8004AD8C: blez        $v0, L_8004AD9C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004AD90: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8004AD9C;
    }
    // 0x8004AD90: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004AD94: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8004AD98: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
L_8004AD9C:
    // 0x8004AD9C: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8004ADA0: addiu       $s0, $s0, 0x3520
    ctx->r16 = ADD32(ctx->r16, 0X3520);
    // 0x8004ADA4: jal         0x80017D38
    // 0x8004ADA8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80017D38(rdram, ctx);
        goto after_20;
    // 0x8004ADA8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_20:
    // 0x8004ADAC: jal         0x80017D38
    // 0x8004ADB0: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    func_80017D38(rdram, ctx);
        goto after_21;
    // 0x8004ADB0: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    after_21:
    // 0x8004ADB4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004ADB8: lw          $v0, -0x33D0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X33D0);
    // 0x8004ADBC: bne         $v0, $zero, L_8004ADCC
    if (ctx->r2 != 0) {
        // 0x8004ADC0: nop
    
            goto L_8004ADCC;
    }
    // 0x8004ADC0: nop

    // 0x8004ADC4: jal         0x800577B4
    // 0x8004ADC8: nop

    func_800577B4(rdram, ctx);
        goto after_22;
    // 0x8004ADC8: nop

    after_22:
L_8004ADCC:
    // 0x8004ADCC: jal         0x8002D634
    // 0x8004ADD0: nop

    func_8002D634(rdram, ctx);
        goto after_23;
    // 0x8004ADD0: nop

    after_23:
    // 0x8004ADD4: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x8004ADD8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8004ADDC: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8004ADE0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8004ADE4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8004ADE8: jr          $ra
    // 0x8004ADEC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8004ADEC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8004ADF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004ADF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004ADF4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004ADF8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004ADFC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8004AE00: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x8004AE04: addiu       $s3, $s3, 0x10A4
    ctx->r19 = ADD32(ctx->r19, 0X10A4);
    // 0x8004AE08: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8004AE0C: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x8004AE10: addiu       $s1, $s1, 0x12B8
    ctx->r17 = ADD32(ctx->r17, 0X12B8);
    // 0x8004AE14: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8004AE18: addiu       $s2, $s1, 0x2
    ctx->r18 = ADD32(ctx->r17, 0X2);
    // 0x8004AE1C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8004AE20: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_8004AE24:
    // 0x8004AE24: sra         $v1, $v0, 24
    ctx->r3 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004AE28: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8004AE2C: bne         $v1, $v0, L_8004AEFC
    if (ctx->r3 != ctx->r2) {
        // 0x8004AE30: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8004AEFC;
    }
    // 0x8004AE30: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004AE34: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8004AE38: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8004AE3C: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
L_8004AE40:
    // 0x8004AE40: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004AE44: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004AE48: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004AE4C: lb          $v1, 0xB60($v1)
    ctx->r3 = MEM_B(ctx->r3, 0XB60);
    // 0x8004AE50: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004AE54: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004AE58: lb          $v0, -0x1D98($at)
    ctx->r2 = MEM_B(ctx->r1, -0X1D98);
    // 0x8004AE5C: bnel        $v1, $v0, L_8004AE64
    if (ctx->r3 != ctx->r2) {
        // 0x8004AE60: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8004AE64;
    }
    goto skip_0;
    // 0x8004AE60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_0:
L_8004AE64:
    // 0x8004AE64: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8004AE68: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8004AE6C: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004AE70: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004AE74: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8004AE78: bne         $v0, $zero, L_8004AE40
    if (ctx->r2 != 0) {
        // 0x8004AE7C: sll         $v0, $a0, 24
        ctx->r2 = S32(ctx->r4 << 24);
            goto L_8004AE40;
    }
    // 0x8004AE7C: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
    // 0x8004AE80: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8004AE84: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
L_8004AE88:
    // 0x8004AE88: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004AE8C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004AE90: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004AE94: lb          $v1, 0xB7A($v1)
    ctx->r3 = MEM_B(ctx->r3, 0XB7A);
    // 0x8004AE98: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004AE9C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004AEA0: lb          $v0, -0x1D94($at)
    ctx->r2 = MEM_B(ctx->r1, -0X1D94);
    // 0x8004AEA4: bnel        $v1, $v0, L_8004AEAC
    if (ctx->r3 != ctx->r2) {
        // 0x8004AEA8: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8004AEAC;
    }
    goto skip_1;
    // 0x8004AEA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_1:
L_8004AEAC:
    // 0x8004AEAC: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8004AEB0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8004AEB4: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004AEB8: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004AEBC: slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8004AEC0: bne         $v0, $zero, L_8004AE88
    if (ctx->r2 != 0) {
        // 0x8004AEC4: sll         $v0, $a0, 24
        ctx->r2 = S32(ctx->r4 << 24);
            goto L_8004AE88;
    }
    // 0x8004AEC4: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
    // 0x8004AEC8: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x8004AECC: beq         $v0, $zero, L_8004AEF8
    if (ctx->r2 == 0) {
        // 0x8004AED0: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_8004AEF8;
    }
    // 0x8004AED0: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x8004AED4: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8004AED8: addu        $v1, $v0, $s3
    ctx->r3 = ADD32(ctx->r2, ctx->r19);
    // 0x8004AEDC: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8004AEE0: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
    // 0x8004AEE4: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x8004AEE8: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8004AEEC: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8004AEF0: j           L_8004AF18
    // 0x8004AEF4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8004AF18;
    // 0x8004AEF4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8004AEF8:
    // 0x8004AEF8: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
L_8004AEFC:
    // 0x8004AEFC: addu        $v1, $v0, $s3
    ctx->r3 = ADD32(ctx->r2, ctx->r19);
    // 0x8004AF00: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8004AF04: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
    // 0x8004AF08: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x8004AF0C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8004AF10: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8004AF14: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8004AF18:
    // 0x8004AF18: jal         0x8004DAB8
    // 0x8004AF1C: nop

    func_8004DAB8(rdram, ctx);
        goto after_0;
    // 0x8004AF1C: nop

    after_0:
    // 0x8004AF20: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x8004AF24: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8004AF28: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004AF2C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004AF30: slti        $v0, $v0, 0xC
    ctx->r2 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
    // 0x8004AF34: bne         $v0, $zero, L_8004AE24
    if (ctx->r2 != 0) {
        // 0x8004AF38: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_8004AE24;
    }
    // 0x8004AF38: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x8004AF3C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004AF40: addiu       $a0, $a0, -0x1874
    ctx->r4 = ADD32(ctx->r4, -0X1874);
    // 0x8004AF44: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004AF48: lb          $v0, 0x10A3($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X10A3);
    // 0x8004AF4C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x8004AF50: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8004AF54: sll         $a2, $v0, 4
    ctx->r6 = S32(ctx->r2 << 4);
    // 0x8004AF58: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x8004AF5C: jal         0x8004DAB8
    // 0x8004AF60: addiu       $a2, $a2, 0x32
    ctx->r6 = ADD32(ctx->r6, 0X32);
    func_8004DAB8(rdram, ctx);
        goto after_1;
    // 0x8004AF60: addiu       $a2, $a2, 0x32
    ctx->r6 = ADD32(ctx->r6, 0X32);
    after_1:
    // 0x8004AF64: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8004AF68: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8004AF6C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8004AF70: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8004AF74: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004AF78: jr          $ra
    // 0x8004AF7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004AF7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8004AF80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004AF80: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8004AF84: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8004AF88: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004AF8C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8004AF90: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x8004AF94: addiu       $s3, $s3, 0x10F0
    ctx->r19 = ADD32(ctx->r19, 0X10F0);
    // 0x8004AF98: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8004AF9C: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x8004AFA0: addiu       $s1, $s1, 0x12E8
    ctx->r17 = ADD32(ctx->r17, 0X12E8);
    // 0x8004AFA4: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8004AFA8: addiu       $s2, $s1, 0x2
    ctx->r18 = ADD32(ctx->r17, 0X2);
    // 0x8004AFAC: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8004AFB0: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_8004AFB4:
    // 0x8004AFB4: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8004AFB8: addu        $v1, $v0, $s3
    ctx->r3 = ADD32(ctx->r2, ctx->r19);
    // 0x8004AFBC: addu        $a1, $v0, $s1
    ctx->r5 = ADD32(ctx->r2, ctx->r17);
    // 0x8004AFC0: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8004AFC4: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8004AFC8: lh          $a1, 0x0($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X0);
    // 0x8004AFCC: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8004AFD0: jal         0x8004DAB8
    // 0x8004AFD4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_0;
    // 0x8004AFD4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x8004AFD8: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x8004AFDC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8004AFE0: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004AFE4: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004AFE8: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8004AFEC: bne         $v0, $zero, L_8004AFB4
    if (ctx->r2 != 0) {
        // 0x8004AFF0: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_8004AFB4;
    }
    // 0x8004AFF0: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x8004AFF4: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x8004AFF8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8004AFFC: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8004B000: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8004B004: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8004B008: jr          $ra
    // 0x8004B00C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8004B00C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8004B010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B010: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004B014: lb          $v1, 0x5583($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X5583);
    // 0x8004B018: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004B01C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8004B020: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8004B024: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8004B028: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8004B02C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8004B030: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x8004B034: beq         $v0, $zero, L_8004B0F4
    if (ctx->r2 == 0) {
        // 0x8004B038: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_8004B0F4;
    }
    // 0x8004B038: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004B03C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004B040: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004B044: addu        $at, $at, $v0
    gpr jr_addend_8004B04C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004B048: lw          $v0, -0x1870($at)
    ctx->r2 = ADD32(ctx->r1, -0X1870);
    // 0x8004B04C: jr          $v0
    // 0x8004B050: nop

    switch (jr_addend_8004B04C >> 2) {
        case 0: goto L_8004B054; break;
        case 1: goto L_8004B074; break;
        case 2: goto L_8004B084; break;
        case 3: goto L_8004B094; break;
        case 4: goto L_8004B0A4; break;
        case 5: goto L_8004B0C4; break;
        default: switch_error(__func__, 0x8004B04C, 0x800AE790);
    }
    // 0x8004B050: nop

L_8004B054:
    // 0x8004B054: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004B058: addiu       $v0, $v0, 0x5583
    ctx->r2 = ADD32(ctx->r2, 0X5583);
    // 0x8004B05C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8004B060: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x8004B064: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004B068: sw          $a0, 0x4AEC($at)
    MEM_W(0X4AEC, ctx->r1) = ctx->r4;
    // 0x8004B06C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004B070: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
L_8004B074:
    // 0x8004B074: jal         0x8004B210
    // 0x8004B078: nop

    func_8004B210(rdram, ctx);
        goto after_0;
    // 0x8004B078: nop

    after_0:
    // 0x8004B07C: j           L_8004B0AC
    // 0x8004B080: nop

        goto L_8004B0AC;
    // 0x8004B080: nop

L_8004B084:
    // 0x8004B084: jal         0x8004B2EC
    // 0x8004B088: nop

    func_8004B2EC(rdram, ctx);
        goto after_1;
    // 0x8004B088: nop

    after_1:
    // 0x8004B08C: j           L_8004B0AC
    // 0x8004B090: nop

        goto L_8004B0AC;
    // 0x8004B090: nop

L_8004B094:
    // 0x8004B094: jal         0x8004B384
    // 0x8004B098: nop

    func_8004B384(rdram, ctx);
        goto after_2;
    // 0x8004B098: nop

    after_2:
    // 0x8004B09C: j           L_8004B0AC
    // 0x8004B0A0: nop

        goto L_8004B0AC;
    // 0x8004B0A0: nop

L_8004B0A4:
    // 0x8004B0A4: jal         0x8004B38C
    // 0x8004B0A8: nop

    func_8004B38C(rdram, ctx);
        goto after_3;
    // 0x8004B0A8: nop

    after_3:
L_8004B0AC:
    // 0x8004B0AC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004B0B0: addiu       $v1, $v1, 0x5583
    ctx->r3 = ADD32(ctx->r3, 0X5583);
    // 0x8004B0B4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8004B0B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004B0BC: j           L_8004B0F4
    // 0x8004B0C0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
        goto L_8004B0F4;
    // 0x8004B0C0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8004B0C4:
    // 0x8004B0C4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004B0C8: lw          $v0, 0x4AEC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4AEC);
    // 0x8004B0CC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8004B0D0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004B0D4: sw          $v0, 0x4AEC($at)
    MEM_W(0X4AEC, ctx->r1) = ctx->r2;
    // 0x8004B0D8: bnel        $v0, $zero, L_8004B0F8
    if (ctx->r2 != 0) {
        // 0x8004B0DC: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8004B0F8;
    }
    goto skip_0;
    // 0x8004B0DC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    skip_0:
    // 0x8004B0E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004B0E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004B0E8: sb          $v0, 0x5582($at)
    MEM_B(0X5582, ctx->r1) = ctx->r2;
    // 0x8004B0EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004B0F0: sb          $zero, 0x5583($at)
    MEM_B(0X5583, ctx->r1) = 0;
L_8004B0F4:
    // 0x8004B0F4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8004B0F8:
    // 0x8004B0F8: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x8004B0FC: addiu       $s3, $s3, 0x10D4
    ctx->r19 = ADD32(ctx->r19, 0X10D4);
    // 0x8004B100: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004B104: addiu       $v0, $v0, 0x12FC
    ctx->r2 = ADD32(ctx->r2, 0X12FC);
    // 0x8004B108: addiu       $s2, $v0, 0x2
    ctx->r18 = ADD32(ctx->r2, 0X2);
    // 0x8004B10C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_8004B110:
    // 0x8004B110: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8004B114: lh          $a1, 0x0($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X0);
    // 0x8004B118: lh          $a2, 0x0($s2)
    ctx->r6 = MEM_H(ctx->r18, 0X0);
    // 0x8004B11C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8004B120: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8004B124: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8004B128: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8004B12C: jal         0x8004DAB8
    // 0x8004B130: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_8004DAB8(rdram, ctx);
        goto after_4;
    // 0x8004B130: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_4:
    // 0x8004B134: slti        $v0, $s0, 0x5
    ctx->r2 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8004B138: bne         $v0, $zero, L_8004B110
    if (ctx->r2 != 0) {
        // 0x8004B13C: nop
    
            goto L_8004B110;
    }
    // 0x8004B13C: nop

    // 0x8004B140: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004B144: lb          $v0, 0x5583($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5583);
    // 0x8004B148: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004B14C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004B150: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004B154: lw          $v0, 0x1330($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1330);
    // 0x8004B158: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004B15C: addiu       $v1, $v1, 0x1330
    ctx->r3 = ADD32(ctx->r3, 0X1330);
    // 0x8004B160: blez        $v0, L_8004B1F0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004B164: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8004B1F0;
    }
    // 0x8004B164: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004B168: lui         $s4, 0x8009
    ctx->r20 = S32(0X8009 << 16);
    // 0x8004B16C: addiu       $s4, $s4, 0x10E8
    ctx->r20 = ADD32(ctx->r20, 0X10E8);
    // 0x8004B170: addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    // 0x8004B174: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004B178: addiu       $v0, $v0, 0x1310
    ctx->r2 = ADD32(ctx->r2, 0X1310);
    // 0x8004B17C: addiu       $s2, $v0, 0x2
    ctx->r18 = ADD32(ctx->r2, 0X2);
    // 0x8004B180: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_8004B184:
    // 0x8004B184: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004B188: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8004B18C: lb          $v0, 0x4AE8($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4AE8);
    // 0x8004B190: beq         $v0, $zero, L_8004B1B0
    if (ctx->r2 == 0) {
        // 0x8004B194: sll         $v0, $v0, 2
        ctx->r2 = S32(ctx->r2 << 2);
            goto L_8004B1B0;
    }
    // 0x8004B194: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004B198: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x8004B19C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8004B1A0: lh          $a1, 0x0($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X0);
    // 0x8004B1A4: lh          $a2, 0x0($s2)
    ctx->r6 = MEM_H(ctx->r18, 0X0);
    // 0x8004B1A8: j           L_8004B1C4
    // 0x8004B1AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8004B1C4;
    // 0x8004B1AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8004B1B0:
    // 0x8004B1B0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004B1B4: lw          $a0, 0x10E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10E8);
    // 0x8004B1B8: lh          $a1, 0x0($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X0);
    // 0x8004B1BC: lh          $a2, 0x0($s2)
    ctx->r6 = MEM_H(ctx->r18, 0X0);
    // 0x8004B1C0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8004B1C4:
    // 0x8004B1C4: jal         0x8004DAB8
    // 0x8004B1C8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    func_8004DAB8(rdram, ctx);
        goto after_5;
    // 0x8004B1C8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    after_5:
    // 0x8004B1CC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004B1D0: lb          $v0, 0x5583($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5583);
    // 0x8004B1D4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004B1D8: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x8004B1DC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8004B1E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8004B1E4: slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004B1E8: bne         $v0, $zero, L_8004B184
    if (ctx->r2 != 0) {
        // 0x8004B1EC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8004B184;
    }
    // 0x8004B1EC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8004B1F0:
    // 0x8004B1F0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8004B1F4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8004B1F8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8004B1FC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8004B200: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8004B204: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004B208: jr          $ra
    // 0x8004B20C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8004B20C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8004B210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B210: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8004B214: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004B218: addiu       $v0, $v0, 0x4AEB
    ctx->r2 = ADD32(ctx->r2, 0X4AEB);
L_8004B21C:
    // 0x8004B21C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8004B220: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8004B224: bgez        $a1, L_8004B21C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8004B228: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8004B21C;
    }
    // 0x8004B228: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8004B22C: lui         $a2, 0x801F
    ctx->r6 = S32(0X801F << 16);
    // 0x8004B230: ori         $a2, $a2, 0xFFF8
    ctx->r6 = ctx->r6 | 0XFFF8;
    // 0x8004B234: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x8004B238: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8004B23C: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x8004B240: addiu       $t0, $t0, 0x5583
    ctx->r8 = ADD32(ctx->r8, 0X5583);
    // 0x8004B244: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8004B248: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004B24C: addiu       $a0, $a0, 0x1320
    ctx->r4 = ADD32(ctx->r4, 0X1320);
L_8004B250:
    // 0x8004B250: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8004B254: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x8004B258: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8004B25C: bne         $v0, $v1, L_8004B2B0
    if (ctx->r2 != ctx->r3) {
        // 0x8004B260: nop
    
            goto L_8004B2B0;
    }
    // 0x8004B260: nop

    // 0x8004B264: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8004B268: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8004B26C: bne         $v0, $zero, L_8004B250
    if (ctx->r2 != 0) {
        // 0x8004B270: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8004B250;
    }
    // 0x8004B270: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8004B274: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x8004B278: lui         $a2, 0x803F
    ctx->r6 = S32(0X803F << 16);
    // 0x8004B27C: ori         $a2, $a2, 0xFFF8
    ctx->r6 = ctx->r6 | 0XFFF8;
    // 0x8004B280: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x8004B284: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8004B288: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x8004B28C: addiu       $t0, $t0, 0x5583
    ctx->r8 = ADD32(ctx->r8, 0X5583);
    // 0x8004B290: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8004B294: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004B298: addiu       $a0, $a0, 0x1320
    ctx->r4 = ADD32(ctx->r4, 0X1320);
L_8004B29C:
    // 0x8004B29C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8004B2A0: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x8004B2A4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8004B2A8: beql        $v0, $v1, L_8004B2D4
    if (ctx->r2 == ctx->r3) {
        // 0x8004B2AC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8004B2D4;
    }
    goto skip_0;
    // 0x8004B2AC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
L_8004B2B0:
    // 0x8004B2B0: lb          $v0, 0x0($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X0);
    // 0x8004B2B4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004B2B8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004B2BC: sb          $t1, 0x4AE8($at)
    MEM_B(0X4AE8, ctx->r1) = ctx->r9;
    // 0x8004B2C0: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x8004B2C4: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x8004B2C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004B2CC: j           L_8004B2E4
    // 0x8004B2D0: sb          $v0, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r2;
        goto L_8004B2E4;
    // 0x8004B2D0: sb          $v0, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r2;
L_8004B2D4:
    // 0x8004B2D4: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8004B2D8: bne         $v0, $zero, L_8004B29C
    if (ctx->r2 != 0) {
        // 0x8004B2DC: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8004B29C;
    }
    // 0x8004B2DC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8004B2E0: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
L_8004B2E4:
    // 0x8004B2E4: jr          $ra
    // 0x8004B2E8: nop

    return;
    // 0x8004B2E8: nop

;}
RECOMP_FUNC void func_8004B2EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B2EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004B2F0: lui         $a0, 0x6F
    ctx->r4 = S32(0X6F << 16);
    // 0x8004B2F4: addiu       $a0, $a0, -0x3710
    ctx->r4 = ADD32(ctx->r4, -0X3710);
    // 0x8004B2F8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004B2FC: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8004B300: addiu       $s0, $s0, 0x4AF0
    ctx->r16 = ADD32(ctx->r16, 0X4AF0);
    // 0x8004B304: lui         $a2, 0x6F
    ctx->r6 = S32(0X6F << 16);
    // 0x8004B308: addiu       $a2, $a2, -0x3700
    ctx->r6 = ADD32(ctx->r6, -0X3700);
    // 0x8004B30C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8004B310: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004B314: jal         0x80006D98
    // 0x8004B318: subu        $a2, $a2, $a0
    ctx->r6 = SUB32(ctx->r6, ctx->r4);
    func_80006D98(rdram, ctx);
        goto after_0;
    // 0x8004B318: subu        $a2, $a2, $a0
    ctx->r6 = SUB32(ctx->r6, ctx->r4);
    after_0:
    // 0x8004B31C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8004B320: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x8004B324: addiu       $a2, $a2, 0x5583
    ctx->r6 = ADD32(ctx->r6, 0X5583);
    // 0x8004B328: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8004B32C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004B330: addiu       $a0, $a0, 0x1320
    ctx->r4 = ADD32(ctx->r4, 0X1320);
L_8004B334:
    // 0x8004B334: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8004B338: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8004B33C: beq         $v0, $v1, L_8004B364
    if (ctx->r2 == ctx->r3) {
        // 0x8004B340: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8004B364;
    }
    // 0x8004B340: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8004B344: lb          $v0, 0x0($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X0);
    // 0x8004B348: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004B34C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004B350: sb          $a3, 0x4AE8($at)
    MEM_B(0X4AE8, ctx->r1) = ctx->r7;
    // 0x8004B354: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x8004B358: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004B35C: j           L_8004B374
    // 0x8004B360: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
        goto L_8004B374;
    // 0x8004B360: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
L_8004B364:
    // 0x8004B364: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8004B368: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8004B36C: bne         $v0, $zero, L_8004B334
    if (ctx->r2 != 0) {
        // 0x8004B370: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8004B334;
    }
    // 0x8004B370: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8004B374:
    // 0x8004B374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004B378: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004B37C: jr          $ra
    // 0x8004B380: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8004B380: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8004B384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B384: jr          $ra
    // 0x8004B388: nop

    return;
    // 0x8004B388: nop

;}
RECOMP_FUNC void func_8004B38C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B38C: jr          $ra
    // 0x8004B390: nop

    return;
    // 0x8004B390: nop

;}
RECOMP_FUNC void func_8004B394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B394: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8004B398: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004B39C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004B3A0: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x8004B3A4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8004B3A8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8004B3AC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8004B3B0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8004B3B4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8004B3B8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8004B3BC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8004B3C0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8004B3C4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8004B3C8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
L_8004B3CC:
    // 0x8004B3CC: sll         $a0, $s0, 24
    ctx->r4 = S32(ctx->r16 << 24);
    // 0x8004B3D0: addiu       $v1, $s0, 0x1
    ctx->r3 = ADD32(ctx->r16, 0X1);
    // 0x8004B3D4: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    // 0x8004B3D8: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8004B3DC: addu        $v0, $a1, $a0
    ctx->r2 = ADD32(ctx->r5, ctx->r4);
    // 0x8004B3E0: addu        $a0, $a2, $a0
    ctx->r4 = ADD32(ctx->r6, ctx->r4);
    // 0x8004B3E4: sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3 << 24);
    // 0x8004B3E8: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8004B3EC: slti        $v1, $v1, 0x8
    ctx->r3 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8004B3F0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8004B3F4: bne         $v1, $zero, L_8004B3CC
    if (ctx->r3 != 0) {
        // 0x8004B3F8: sb          $zero, 0x0($a0)
        MEM_B(0X0, ctx->r4) = 0;
            goto L_8004B3CC;
    }
    // 0x8004B3F8: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x8004B3FC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004B400: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x8004B404: addiu       $s3, $s3, 0x1124
    ctx->r19 = ADD32(ctx->r19, 0X1124);
    // 0x8004B408: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x8004B40C: addiu       $s1, $s1, 0x13A8
    ctx->r17 = ADD32(ctx->r17, 0X13A8);
    // 0x8004B410: addiu       $s2, $s1, 0x2
    ctx->r18 = ADD32(ctx->r17, 0X2);
    // 0x8004B414: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_8004B418:
    // 0x8004B418: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8004B41C: addu        $v1, $v0, $s3
    ctx->r3 = ADD32(ctx->r2, ctx->r19);
    // 0x8004B420: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8004B424: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
    // 0x8004B428: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x8004B42C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8004B430: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8004B434: jal         0x8004DAB8
    // 0x8004B438: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_0;
    // 0x8004B438: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x8004B43C: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x8004B440: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8004B444: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004B448: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004B44C: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8004B450: bne         $v0, $zero, L_8004B418
    if (ctx->r2 != 0) {
        // 0x8004B454: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_8004B418;
    }
    // 0x8004B454: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x8004B458: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8004B45C: lhu         $v0, -0x38A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X38A0);
    // 0x8004B460: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8004B464: beq         $v0, $zero, L_8004B488
    if (ctx->r2 == 0) {
        // 0x8004B468: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_8004B488;
    }
    // 0x8004B468: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8004B46C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8004B470: lh          $a1, 0x1398($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X1398);
    // 0x8004B474: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8004B478: lh          $a2, 0x139A($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X139A);
    // 0x8004B47C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004B480: j           L_8004B4A4
    // 0x8004B484: addiu       $a0, $a0, -0x1858
    ctx->r4 = ADD32(ctx->r4, -0X1858);
        goto L_8004B4A4;
    // 0x8004B484: addiu       $a0, $a0, -0x1858
    ctx->r4 = ADD32(ctx->r4, -0X1858);
L_8004B488:
    // 0x8004B488: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8004B48C: lh          $a1, 0x1398($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X1398);
    // 0x8004B490: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8004B494: lh          $a2, 0x139A($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X139A);
    // 0x8004B498: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004B49C: addiu       $a0, $a0, -0x1854
    ctx->r4 = ADD32(ctx->r4, -0X1854);
    // 0x8004B4A0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8004B4A4:
    // 0x8004B4A4: jal         0x8004DAB8
    // 0x8004B4A8: nop

    func_8004DAB8(rdram, ctx);
        goto after_1;
    // 0x8004B4A8: nop

    after_1:
    // 0x8004B4AC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8004B4B0: lhu         $v0, -0x389A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X389A);
    // 0x8004B4B4: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8004B4B8: beql        $v0, $zero, L_8004B4E0
    if (ctx->r2 == 0) {
        // 0x8004B4BC: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_8004B4E0;
    }
    goto skip_0;
    // 0x8004B4BC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    skip_0:
    // 0x8004B4C0: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8004B4C4: lh          $a1, 0x139C($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X139C);
    // 0x8004B4C8: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8004B4CC: lh          $a2, 0x139E($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X139E);
    // 0x8004B4D0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004B4D4: addiu       $a0, $a0, -0x1858
    ctx->r4 = ADD32(ctx->r4, -0X1858);
    // 0x8004B4D8: j           L_8004B4F8
    // 0x8004B4DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8004B4F8;
    // 0x8004B4DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8004B4E0:
    // 0x8004B4E0: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8004B4E4: lh          $a1, 0x139C($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X139C);
    // 0x8004B4E8: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8004B4EC: lh          $a2, 0x139E($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X139E);
    // 0x8004B4F0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004B4F4: addiu       $a0, $a0, -0x1854
    ctx->r4 = ADD32(ctx->r4, -0X1854);
L_8004B4F8:
    // 0x8004B4F8: jal         0x8004DAB8
    // 0x8004B4FC: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_2;
    // 0x8004B4FC: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    after_2:
    // 0x8004B500: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x8004B504: addiu       $s0, $s0, -0x1854
    ctx->r16 = ADD32(ctx->r16, -0X1854);
    // 0x8004B508: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004B50C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8004B510: lh          $a1, 0x13A0($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X13A0);
    // 0x8004B514: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8004B518: lh          $a2, 0x13A2($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X13A2);
    // 0x8004B51C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8004B520: lui         $fp, 0x8009
    ctx->r30 = S32(0X8009 << 16);
    // 0x8004B524: addiu       $fp, $fp, 0x136C
    ctx->r30 = ADD32(ctx->r30, 0X136C);
    // 0x8004B528: addiu       $s1, $sp, 0x10
    ctx->r17 = ADD32(ctx->r29, 0X10);
    // 0x8004B52C: jal         0x8004DAB8
    // 0x8004B530: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    func_8004DAB8(rdram, ctx);
        goto after_3;
    // 0x8004B530: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    after_3:
    // 0x8004B534: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8004B538: lh          $a1, 0x13A4($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X13A4);
    // 0x8004B53C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8004B540: lh          $a2, 0x13A6($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X13A6);
    // 0x8004B544: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004B548: jal         0x8004DAB8
    // 0x8004B54C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_4;
    // 0x8004B54C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_4:
    // 0x8004B550: sll         $v0, $s7, 24
    ctx->r2 = S32(ctx->r23 << 24);
L_8004B554:
    // 0x8004B554: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004B558: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x8004B55C: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x8004B560: andi        $s4, $v1, 0x72
    ctx->r20 = ctx->r3 & 0X72;
    // 0x8004B564: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004B568: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x8004B56C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004B570: sll         $s2, $v1, 1
    ctx->r18 = S32(ctx->r3 << 1);
L_8004B574:
    // 0x8004B574: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8004B578: addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // 0x8004B57C: lhu         $v1, -0x38A0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X38A0);
    // 0x8004B580: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x8004B584: sra         $a2, $v0, 22
    ctx->r6 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8004B588: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8004B58C: addiu       $t0, $t0, 0x1350
    ctx->r8 = ADD32(ctx->r8, 0X1350);
    // 0x8004B590: addu        $v0, $a2, $t0
    ctx->r2 = ADD32(ctx->r6, ctx->r8);
    // 0x8004B594: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8004B598: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8004B59C: beq         $v1, $zero, L_8004B5C8
    if (ctx->r3 == 0) {
        // 0x8004B5A0: addu        $v0, $a2, $fp
        ctx->r2 = ADD32(ctx->r6, ctx->r30);
            goto L_8004B5C8;
    }
    // 0x8004B5A0: addu        $v0, $a2, $fp
    ctx->r2 = ADD32(ctx->r6, ctx->r30);
    // 0x8004B5A4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004B5A8: addiu       $a0, $a0, -0x1858
    ctx->r4 = ADD32(ctx->r4, -0X1858);
    // 0x8004B5AC: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x8004B5B0: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8004B5B4: addiu       $t0, $t0, 0x136E
    ctx->r8 = ADD32(ctx->r8, 0X136E);
    // 0x8004B5B8: addu        $v0, $a2, $t0
    ctx->r2 = ADD32(ctx->r6, ctx->r8);
    // 0x8004B5BC: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8004B5C0: j           L_8004B5E8
    // 0x8004B5C4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8004B5E8;
    // 0x8004B5C4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8004B5C8:
    // 0x8004B5C8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004B5CC: addiu       $a0, $a0, -0x1854
    ctx->r4 = ADD32(ctx->r4, -0X1854);
    // 0x8004B5D0: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x8004B5D4: lui         $t0, 0x8009
    ctx->r8 = S32(0X8009 << 16);
    // 0x8004B5D8: addiu       $t0, $t0, 0x136E
    ctx->r8 = ADD32(ctx->r8, 0X136E);
    // 0x8004B5DC: addu        $v0, $a2, $t0
    ctx->r2 = ADD32(ctx->r6, ctx->r8);
    // 0x8004B5E0: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8004B5E4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8004B5E8:
    // 0x8004B5E8: jal         0x8004DAB8
    // 0x8004B5EC: addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    func_8004DAB8(rdram, ctx);
        goto after_5;
    // 0x8004B5EC: addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    after_5:
    // 0x8004B5F0: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x8004B5F4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8004B5F8: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004B5FC: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004B600: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8004B604: bne         $v0, $zero, L_8004B574
    if (ctx->r2 != 0) {
        // 0x8004B608: sll         $v0, $s7, 24
        ctx->r2 = S32(ctx->r23 << 24);
            goto L_8004B574;
    }
    // 0x8004B608: sll         $v0, $s7, 24
    ctx->r2 = S32(ctx->r23 << 24);
    // 0x8004B60C: sra         $a0, $v0, 24
    ctx->r4 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004B610: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8004B614: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004B618: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004B61C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8004B620: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004B624: lhu         $v1, -0x38A0($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X38A0);
    // 0x8004B628: andi        $v0, $v1, 0x200
    ctx->r2 = ctx->r3 & 0X200;
    // 0x8004B62C: beq         $v0, $zero, L_8004B66C
    if (ctx->r2 == 0) {
        // 0x8004B630: andi        $v0, $v1, 0x800
        ctx->r2 = ctx->r3 & 0X800;
            goto L_8004B66C;
    }
    // 0x8004B630: andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // 0x8004B634: beq         $v0, $zero, L_8004B648
    if (ctx->r2 == 0) {
        // 0x8004B638: sll         $v0, $a0, 3
        ctx->r2 = S32(ctx->r4 << 3);
            goto L_8004B648;
    }
    // 0x8004B638: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x8004B63C: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x8004B640: j           L_8004B6D8
    // 0x8004B644: sb          $s6, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r22;
        goto L_8004B6D8;
    // 0x8004B644: sb          $s6, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r22;
L_8004B648:
    // 0x8004B648: andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // 0x8004B64C: beq         $v0, $zero, L_8004B660
    if (ctx->r2 == 0) {
        // 0x8004B650: sll         $v0, $a0, 3
        ctx->r2 = S32(ctx->r4 << 3);
            goto L_8004B660;
    }
    // 0x8004B650: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x8004B654: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x8004B658: j           L_8004B6D8
    // 0x8004B65C: sb          $s6, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r22;
        goto L_8004B6D8;
    // 0x8004B65C: sb          $s6, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r22;
L_8004B660:
    // 0x8004B660: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x8004B664: j           L_8004B6D8
    // 0x8004B668: sb          $s6, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r22;
        goto L_8004B6D8;
    // 0x8004B668: sb          $s6, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r22;
L_8004B66C:
    // 0x8004B66C: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8004B670: beq         $v0, $zero, L_8004B6B0
    if (ctx->r2 == 0) {
        // 0x8004B674: andi        $v0, $v1, 0x800
        ctx->r2 = ctx->r3 & 0X800;
            goto L_8004B6B0;
    }
    // 0x8004B674: andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // 0x8004B678: beq         $v0, $zero, L_8004B68C
    if (ctx->r2 == 0) {
        // 0x8004B67C: sll         $v0, $a0, 3
        ctx->r2 = S32(ctx->r4 << 3);
            goto L_8004B68C;
    }
    // 0x8004B67C: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x8004B680: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x8004B684: j           L_8004B6D8
    // 0x8004B688: sb          $s6, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r22;
        goto L_8004B6D8;
    // 0x8004B688: sb          $s6, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r22;
L_8004B68C:
    // 0x8004B68C: andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // 0x8004B690: beq         $v0, $zero, L_8004B6A4
    if (ctx->r2 == 0) {
        // 0x8004B694: sll         $v0, $a0, 3
        ctx->r2 = S32(ctx->r4 << 3);
            goto L_8004B6A4;
    }
    // 0x8004B694: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x8004B698: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x8004B69C: j           L_8004B6D8
    // 0x8004B6A0: sb          $s6, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r22;
        goto L_8004B6D8;
    // 0x8004B6A0: sb          $s6, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r22;
L_8004B6A4:
    // 0x8004B6A4: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x8004B6A8: j           L_8004B6D8
    // 0x8004B6AC: sb          $s6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r22;
        goto L_8004B6D8;
    // 0x8004B6AC: sb          $s6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r22;
L_8004B6B0:
    // 0x8004B6B0: beq         $v0, $zero, L_8004B6C4
    if (ctx->r2 == 0) {
        // 0x8004B6B4: sll         $v0, $a0, 3
        ctx->r2 = S32(ctx->r4 << 3);
            goto L_8004B6C4;
    }
    // 0x8004B6B4: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x8004B6B8: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x8004B6BC: j           L_8004B6D8
    // 0x8004B6C0: sb          $s6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r22;
        goto L_8004B6D8;
    // 0x8004B6C0: sb          $s6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r22;
L_8004B6C4:
    // 0x8004B6C4: andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // 0x8004B6C8: beq         $v0, $zero, L_8004B6D8
    if (ctx->r2 == 0) {
        // 0x8004B6CC: sll         $v0, $a0, 3
        ctx->r2 = S32(ctx->r4 << 3);
            goto L_8004B6D8;
    }
    // 0x8004B6CC: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x8004B6D0: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x8004B6D4: sb          $s6, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r22;
L_8004B6D8:
    // 0x8004B6D8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004B6DC: sll         $v0, $s7, 24
    ctx->r2 = S32(ctx->r23 << 24);
    // 0x8004B6E0: sra         $v0, $v0, 21
    ctx->r2 = S32(SIGNED(ctx->r2) >> 21);
    // 0x8004B6E4: addu        $s5, $v0, $s1
    ctx->r21 = ADD32(ctx->r2, ctx->r17);
    // 0x8004B6E8: lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // 0x8004B6EC: addiu       $s2, $s2, 0x1378
    ctx->r18 = ADD32(ctx->r18, 0X1378);
    // 0x8004B6F0: addiu       $s3, $s2, 0x2
    ctx->r19 = ADD32(ctx->r18, 0X2);
    // 0x8004B6F4: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_8004B6F8:
    // 0x8004B6F8: sra         $v1, $v0, 24
    ctx->r3 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004B6FC: addu        $v0, $s5, $v1
    ctx->r2 = ADD32(ctx->r21, ctx->r3);
    // 0x8004B700: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x8004B704: beq         $v0, $zero, L_8004B72C
    if (ctx->r2 == 0) {
        // 0x8004B708: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8004B72C;
    }
    // 0x8004B708: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004B70C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004B710: addiu       $a0, $a0, -0x1858
    ctx->r4 = ADD32(ctx->r4, -0X1858);
    // 0x8004B714: addu        $v1, $v0, $s2
    ctx->r3 = ADD32(ctx->r2, ctx->r18);
    // 0x8004B718: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x8004B71C: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x8004B720: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8004B724: j           L_8004B748
    // 0x8004B728: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8004B748;
    // 0x8004B728: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8004B72C:
    // 0x8004B72C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004B730: addiu       $a0, $a0, -0x1854
    ctx->r4 = ADD32(ctx->r4, -0X1854);
    // 0x8004B734: addu        $v1, $v0, $s2
    ctx->r3 = ADD32(ctx->r2, ctx->r18);
    // 0x8004B738: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x8004B73C: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x8004B740: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8004B744: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8004B748:
    // 0x8004B748: jal         0x8004DAB8
    // 0x8004B74C: addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    func_8004DAB8(rdram, ctx);
        goto after_6;
    // 0x8004B74C: addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    after_6:
    // 0x8004B750: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x8004B754: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8004B758: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004B75C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004B760: slti        $v0, $v0, 0x8
    ctx->r2 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8004B764: bne         $v0, $zero, L_8004B6F8
    if (ctx->r2 != 0) {
        // 0x8004B768: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_8004B6F8;
    }
    // 0x8004B768: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x8004B76C: addiu       $v0, $s7, 0x1
    ctx->r2 = ADD32(ctx->r23, 0X1);
    // 0x8004B770: addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
    // 0x8004B774: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004B778: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004B77C: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8004B780: bne         $v0, $zero, L_8004B554
    if (ctx->r2 != 0) {
        // 0x8004B784: sll         $v0, $s7, 24
        ctx->r2 = S32(ctx->r23 << 24);
            goto L_8004B554;
    }
    // 0x8004B784: sll         $v0, $s7, 24
    ctx->r2 = S32(ctx->r23 << 24);
    // 0x8004B788: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8004B78C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8004B790: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8004B794: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8004B798: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8004B79C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8004B7A0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8004B7A4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8004B7A8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8004B7AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004B7B0: jr          $ra
    // 0x8004B7B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8004B7B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8004B7B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B7B8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8004B7BC: lhu         $a0, -0x38A0($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X38A0);
    // 0x8004B7C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004B7C4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004B7C8: addiu       $v1, $v1, 0x7B42
    ctx->r3 = ADD32(ctx->r3, 0X7B42);
    // 0x8004B7CC: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8004B7D0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8004B7D4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8004B7D8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8004B7DC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004B7E0: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8004B7E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004B7E8: sb          $zero, 0x7B43($at)
    MEM_B(0X7B43, ctx->r1) = 0;
    // 0x8004B7EC: andi        $v0, $a0, 0x8000
    ctx->r2 = ctx->r4 & 0X8000;
    // 0x8004B7F0: beq         $v0, $zero, L_8004B7FC
    if (ctx->r2 == 0) {
        // 0x8004B7F4: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8004B7FC;
    }
    // 0x8004B7F4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8004B7F8: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8004B7FC:
    // 0x8004B7FC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8004B800: lhu         $v0, -0x389A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X389A);
    // 0x8004B804: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x8004B808: beq         $v0, $zero, L_8004B820
    if (ctx->r2 == 0) {
        // 0x8004B80C: andi        $v0, $a0, 0x4000
        ctx->r2 = ctx->r4 & 0X4000;
            goto L_8004B820;
    }
    // 0x8004B80C: andi        $v0, $a0, 0x4000
    ctx->r2 = ctx->r4 & 0X4000;
    // 0x8004B810: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8004B814: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x8004B818: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8004B81C: andi        $v0, $a0, 0x4000
    ctx->r2 = ctx->r4 & 0X4000;
L_8004B820:
    // 0x8004B820: beq         $v0, $zero, L_8004B830
    if (ctx->r2 == 0) {
        // 0x8004B824: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004B830;
    }
    // 0x8004B824: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004B828: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004B82C: sb          $v0, 0x7B43($at)
    MEM_B(0X7B43, ctx->r1) = ctx->r2;
L_8004B830:
    // 0x8004B830: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004B834: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x8004B838: addiu       $s3, $s3, 0x114C
    ctx->r19 = ADD32(ctx->r19, 0X114C);
    // 0x8004B83C: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x8004B840: addiu       $s1, $s1, 0x13D0
    ctx->r17 = ADD32(ctx->r17, 0X13D0);
    // 0x8004B844: addiu       $s2, $s1, 0x2
    ctx->r18 = ADD32(ctx->r17, 0X2);
    // 0x8004B848: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_8004B84C:
    // 0x8004B84C: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8004B850: addu        $v1, $v0, $s3
    ctx->r3 = ADD32(ctx->r2, ctx->r19);
    // 0x8004B854: addu        $a1, $v0, $s1
    ctx->r5 = ADD32(ctx->r2, ctx->r17);
    // 0x8004B858: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8004B85C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8004B860: lh          $a1, 0x0($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X0);
    // 0x8004B864: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8004B868: jal         0x8004DAB8
    // 0x8004B86C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_0;
    // 0x8004B86C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x8004B870: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x8004B874: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8004B878: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004B87C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004B880: slti        $v0, $v0, 0x8
    ctx->r2 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8004B884: bne         $v0, $zero, L_8004B84C
    if (ctx->r2 != 0) {
        // 0x8004B888: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_8004B84C;
    }
    // 0x8004B888: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x8004B88C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8004B890: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8004B894: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8004B898: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8004B89C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004B8A0: jr          $ra
    // 0x8004B8A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004B8A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8004B8A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B8A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004B8AC: lui         $a1, 0xFCFF
    ctx->r5 = S32(0XFCFF << 16);
    // 0x8004B8B0: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8004B8B4: lui         $a0, 0xFFFC
    ctx->r4 = S32(0XFFFC << 16);
    // 0x8004B8B8: ori         $a0, $a0, 0xF279
    ctx->r4 = ctx->r4 | 0XF279;
    // 0x8004B8BC: lui         $a2, 0x70F
    ctx->r6 = S32(0X70F << 16);
    // 0x8004B8C0: ori         $a2, $a2, 0xF200
    ctx->r6 = ctx->r6 | 0XF200;
    // 0x8004B8C4: lui         $a3, 0xF510
    ctx->r7 = S32(0XF510 << 16);
    // 0x8004B8C8: ori         $a3, $a3, 0x800
    ctx->r7 = ctx->r7 | 0X800;
    // 0x8004B8CC: lui         $t0, 0x3
    ctx->r8 = S32(0X3 << 16);
    // 0x8004B8D0: ori         $t0, $t0, 0xC03C
    ctx->r8 = ctx->r8 | 0XC03C;
    // 0x8004B8D4: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8004B8D8: lui         $t5, 0xE400
    ctx->r13 = S32(0XE400 << 16);
    // 0x8004B8DC: lui         $t4, 0xB400
    ctx->r12 = S32(0XB400 << 16);
    // 0x8004B8E0: lui         $t3, 0xB300
    ctx->r11 = S32(0XB300 << 16);
    // 0x8004B8E4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004B8E8: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x8004B8EC: lui         $t2, 0x400
    ctx->r10 = S32(0X400 << 16);
    // 0x8004B8F0: ori         $t2, $t2, 0x400
    ctx->r10 = ctx->r10 | 0X400;
    // 0x8004B8F4: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8004B8F8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8004B8FC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8004B900: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8004B904: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004B908: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8004B90C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B910: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004B914: lui         $v1, 0x600
    ctx->r3 = S32(0X600 << 16);
    // 0x8004B918: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8004B91C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004B920: addiu       $v1, $v1, 0x1278
    ctx->r3 = ADD32(ctx->r3, 0X1278);
    // 0x8004B924: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x8004B928: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x8004B92C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B930: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004B934: addiu       $v1, $v0, 0x18
    ctx->r3 = ADD32(ctx->r2, 0X18);
    // 0x8004B938: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B93C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004B940: lui         $v1, 0xFD10
    ctx->r3 = S32(0XFD10 << 16);
    // 0x8004B944: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x8004B948: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004B94C: addiu       $v1, $v1, 0x13F8
    ctx->r3 = ADD32(ctx->r3, 0X13F8);
    // 0x8004B950: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // 0x8004B954: addiu       $v1, $v0, 0x20
    ctx->r3 = ADD32(ctx->r2, 0X20);
    // 0x8004B958: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B95C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004B960: lui         $v1, 0xF510
    ctx->r3 = S32(0XF510 << 16);
    // 0x8004B964: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
    // 0x8004B968: lui         $v1, 0x700
    ctx->r3 = S32(0X700 << 16);
    // 0x8004B96C: sw          $v1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r3;
    // 0x8004B970: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x8004B974: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B978: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004B97C: lui         $v1, 0xE600
    ctx->r3 = S32(0XE600 << 16);
    // 0x8004B980: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x8004B984: addiu       $v1, $v0, 0x30
    ctx->r3 = ADD32(ctx->r2, 0X30);
    // 0x8004B988: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B98C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004B990: lui         $v1, 0xF300
    ctx->r3 = S32(0XF300 << 16);
    // 0x8004B994: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // 0x8004B998: addiu       $v1, $v0, 0x38
    ctx->r3 = ADD32(ctx->r2, 0X38);
    // 0x8004B99C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B9A0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004B9A4: lui         $v1, 0xE700
    ctx->r3 = S32(0XE700 << 16);
    // 0x8004B9A8: sw          $v1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r3;
    // 0x8004B9AC: addiu       $v1, $v0, 0x40
    ctx->r3 = ADD32(ctx->r2, 0X40);
    // 0x8004B9B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B9B4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004B9B8: addiu       $v1, $v0, 0x48
    ctx->r3 = ADD32(ctx->r2, 0X48);
    // 0x8004B9BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004B9C0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004B9C4: lui         $v1, 0xF200
    ctx->r3 = S32(0XF200 << 16);
    // 0x8004B9C8: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
    // 0x8004B9CC: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
    // 0x8004B9D0: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x8004B9D4: sw          $a2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r6;
    // 0x8004B9D8: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x8004B9DC: sw          $a3, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r7;
    // 0x8004B9E0: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8004B9E4: sw          $v1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r3;
    // 0x8004B9E8: sw          $t0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r8;
    // 0x8004B9EC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8004B9F0:
    // 0x8004B9F0: sll         $v1, $t1, 24
    ctx->r3 = S32(ctx->r9 << 24);
    // 0x8004B9F4: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8004B9F8: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8004B9FC: sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2 << 6);
    // 0x8004BA00: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8004BA04: or          $a3, $v0, $t5
    ctx->r7 = ctx->r2 | ctx->r13;
    // 0x8004BA08: sll         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3 << 6);
    // 0x8004BA0C: andi        $a1, $v1, 0xFFF
    ctx->r5 = ctx->r3 & 0XFFF;
L_8004BA10:
    // 0x8004BA10: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8004BA14: lw          $a2, 0x2FE4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2FE4);
    // 0x8004BA18: sll         $v1, $s0, 24
    ctx->r3 = S32(ctx->r16 << 24);
    // 0x8004BA1C: addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // 0x8004BA20: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8004BA24: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8004BA28: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x8004BA2C: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x8004BA30: slti        $a0, $a0, 0x14
    ctx->r4 = SIGNED(ctx->r4) < 0X14 ? 1 : 0;
    // 0x8004BA34: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
    // 0x8004BA38: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BA3C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004BA40: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8004BA44: sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2 << 6);
    // 0x8004BA48: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8004BA4C: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8004BA50: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
    // 0x8004BA54: sll         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3 << 6);
    // 0x8004BA58: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8004BA5C: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x8004BA60: or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
    // 0x8004BA64: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8004BA68: addiu       $v0, $a2, 0x10
    ctx->r2 = ADD32(ctx->r6, 0X10);
    // 0x8004BA6C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BA70: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004BA74: addiu       $v0, $a2, 0x18
    ctx->r2 = ADD32(ctx->r6, 0X18);
    // 0x8004BA78: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x8004BA7C: sw          $t4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r12;
    // 0x8004BA80: sw          $zero, 0xC($a2)
    MEM_W(0XC, ctx->r6) = 0;
    // 0x8004BA84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BA88: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004BA8C: sw          $t3, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r11;
    // 0x8004BA90: bne         $a0, $zero, L_8004BA10
    if (ctx->r4 != 0) {
        // 0x8004BA94: sw          $t2, 0x14($a2)
        MEM_W(0X14, ctx->r6) = ctx->r10;
            goto L_8004BA10;
    }
    // 0x8004BA94: sw          $t2, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r10;
    // 0x8004BA98: addiu       $v0, $t1, 0x1
    ctx->r2 = ADD32(ctx->r9, 0X1);
    // 0x8004BA9C: addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
    // 0x8004BAA0: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004BAA4: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004BAA8: slti        $v0, $v0, 0xF
    ctx->r2 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x8004BAAC: bne         $v0, $zero, L_8004B9F0
    if (ctx->r2 != 0) {
        // 0x8004BAB0: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8004B9F0;
    }
    // 0x8004BAB0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004BAB4: lui         $v1, 0x70F
    ctx->r3 = S32(0X70F << 16);
    // 0x8004BAB8: ori         $v1, $v1, 0xF200
    ctx->r3 = ctx->r3 | 0XF200;
    // 0x8004BABC: lui         $a0, 0xF510
    ctx->r4 = S32(0XF510 << 16);
    // 0x8004BAC0: ori         $a0, $a0, 0x800
    ctx->r4 = ctx->r4 | 0X800;
    // 0x8004BAC4: lui         $a1, 0x3
    ctx->r5 = S32(0X3 << 16);
    // 0x8004BAC8: ori         $a1, $a1, 0xC03C
    ctx->r5 = ctx->r5 | 0XC03C;
    // 0x8004BACC: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8004BAD0: lui         $t4, 0xE400
    ctx->r12 = S32(0XE400 << 16);
    // 0x8004BAD4: lui         $t3, 0xB400
    ctx->r11 = S32(0XB400 << 16);
    // 0x8004BAD8: lui         $t2, 0xB300
    ctx->r10 = S32(0XB300 << 16);
    // 0x8004BADC: lui         $t0, 0x400
    ctx->r8 = S32(0X400 << 16);
    // 0x8004BAE0: ori         $t0, $t0, 0x400
    ctx->r8 = ctx->r8 | 0X400;
    // 0x8004BAE4: addiu       $v0, $a2, 0x20
    ctx->r2 = ADD32(ctx->r6, 0X20);
    // 0x8004BAE8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BAEC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004BAF0: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x8004BAF4: sw          $v0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r2;
    // 0x8004BAF8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004BAFC: addiu       $v0, $v0, 0x1600
    ctx->r2 = ADD32(ctx->r2, 0X1600);
    // 0x8004BB00: sw          $v0, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r2;
    // 0x8004BB04: addiu       $v0, $a2, 0x28
    ctx->r2 = ADD32(ctx->r6, 0X28);
    // 0x8004BB08: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BB0C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004BB10: lui         $v0, 0xF510
    ctx->r2 = S32(0XF510 << 16);
    // 0x8004BB14: sw          $v0, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r2;
    // 0x8004BB18: lui         $v0, 0x700
    ctx->r2 = S32(0X700 << 16);
    // 0x8004BB1C: sw          $v0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r2;
    // 0x8004BB20: addiu       $v0, $a2, 0x30
    ctx->r2 = ADD32(ctx->r6, 0X30);
    // 0x8004BB24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BB28: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004BB2C: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x8004BB30: sw          $v0, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r2;
    // 0x8004BB34: addiu       $v0, $a2, 0x38
    ctx->r2 = ADD32(ctx->r6, 0X38);
    // 0x8004BB38: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BB3C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004BB40: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x8004BB44: sw          $v0, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->r2;
    // 0x8004BB48: addiu       $v0, $a2, 0x40
    ctx->r2 = ADD32(ctx->r6, 0X40);
    // 0x8004BB4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BB50: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004BB54: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x8004BB58: sw          $v0, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->r2;
    // 0x8004BB5C: addiu       $v0, $a2, 0x48
    ctx->r2 = ADD32(ctx->r6, 0X48);
    // 0x8004BB60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BB64: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004BB68: addiu       $v0, $a2, 0x50
    ctx->r2 = ADD32(ctx->r6, 0X50);
    // 0x8004BB6C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BB70: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004BB74: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x8004BB78: sw          $zero, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = 0;
    // 0x8004BB7C: sw          $v1, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r3;
    // 0x8004BB80: sw          $zero, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = 0;
    // 0x8004BB84: sw          $a0, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->r4;
    // 0x8004BB88: sw          $zero, 0x44($a2)
    MEM_W(0X44, ctx->r6) = 0;
    // 0x8004BB8C: sw          $v0, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->r2;
    // 0x8004BB90: sw          $a1, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->r5;
L_8004BB94:
    // 0x8004BB94: sll         $v1, $t1, 24
    ctx->r3 = S32(ctx->r9 << 24);
    // 0x8004BB98: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8004BB9C: sltiu       $a0, $v1, 0x1
    ctx->r4 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8004BBA0: xori        $v0, $v1, 0xE
    ctx->r2 = ctx->r3 ^ 0XE;
    // 0x8004BBA4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8004BBA8: or          $a3, $a0, $v0
    ctx->r7 = ctx->r4 | ctx->r2;
    // 0x8004BBAC: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8004BBB0: sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2 << 6);
    // 0x8004BBB4: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8004BBB8: or          $a2, $v0, $t4
    ctx->r6 = ctx->r2 | ctx->r12;
    // 0x8004BBBC: sll         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3 << 6);
    // 0x8004BBC0: andi        $a1, $v1, 0xFFF
    ctx->r5 = ctx->r3 & 0XFFF;
L_8004BBC4:
    // 0x8004BBC4: bne         $a3, $zero, L_8004BBE8
    if (ctx->r7 != 0) {
        // 0x8004BBC8: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_8004BBE8;
    }
    // 0x8004BBC8: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x8004BBCC: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004BBD0: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8004BBD4: xori        $v0, $v0, 0x13
    ctx->r2 = ctx->r2 ^ 0X13;
    // 0x8004BBD8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8004BBDC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8004BBE0: beq         $v1, $zero, L_8004BC5C
    if (ctx->r3 == 0) {
        // 0x8004BBE4: addiu       $v0, $s0, 0x1
        ctx->r2 = ADD32(ctx->r16, 0X1);
            goto L_8004BC5C;
    }
    // 0x8004BBE4: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_8004BBE8:
    // 0x8004BBE8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8004BBEC: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x8004BBF0: sll         $v1, $s0, 24
    ctx->r3 = S32(ctx->r16 << 24);
    // 0x8004BBF4: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8004BBF8: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8004BBFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BC00: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004BC04: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8004BC08: sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2 << 6);
    // 0x8004BC0C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8004BC10: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8004BC14: or          $v0, $v0, $a2
    ctx->r2 = ctx->r2 | ctx->r6;
    // 0x8004BC18: sll         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3 << 6);
    // 0x8004BC1C: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8004BC20: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x8004BC24: or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
    // 0x8004BC28: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8004BC2C: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x8004BC30: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BC34: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004BC38: addiu       $v0, $a0, 0x18
    ctx->r2 = ADD32(ctx->r4, 0X18);
    // 0x8004BC3C: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x8004BC40: sw          $t3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r11;
    // 0x8004BC44: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8004BC48: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004BC4C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004BC50: sw          $t2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r10;
    // 0x8004BC54: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
    // 0x8004BC58: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_8004BC5C:
    // 0x8004BC5C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8004BC60: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004BC64: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004BC68: slti        $v0, $v0, 0x14
    ctx->r2 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8004BC6C: bne         $v0, $zero, L_8004BBC4
    if (ctx->r2 != 0) {
        // 0x8004BC70: addiu       $v0, $t1, 0x1
        ctx->r2 = ADD32(ctx->r9, 0X1);
            goto L_8004BBC4;
    }
    // 0x8004BC70: addiu       $v0, $t1, 0x1
    ctx->r2 = ADD32(ctx->r9, 0X1);
    // 0x8004BC74: addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
    // 0x8004BC78: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004BC7C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004BC80: slti        $v0, $v0, 0xF
    ctx->r2 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x8004BC84: bne         $v0, $zero, L_8004BB94
    if (ctx->r2 != 0) {
        // 0x8004BC88: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8004BB94;
    }
    // 0x8004BC88: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004BC8C: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x8004BC90: addiu       $s3, $s3, 0x116C
    ctx->r19 = ADD32(ctx->r19, 0X116C);
    // 0x8004BC94: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x8004BC98: addiu       $s1, $s1, 0x1800
    ctx->r17 = ADD32(ctx->r17, 0X1800);
    // 0x8004BC9C: addiu       $s2, $s1, 0x2
    ctx->r18 = ADD32(ctx->r17, 0X2);
    // 0x8004BCA0: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_8004BCA4:
    // 0x8004BCA4: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8004BCA8: addu        $v1, $v0, $s3
    ctx->r3 = ADD32(ctx->r2, ctx->r19);
    // 0x8004BCAC: addu        $a1, $v0, $s1
    ctx->r5 = ADD32(ctx->r2, ctx->r17);
    // 0x8004BCB0: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8004BCB4: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8004BCB8: lh          $a1, 0x0($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X0);
    // 0x8004BCBC: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8004BCC0: jal         0x8004DAB8
    // 0x8004BCC4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_0;
    // 0x8004BCC4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x8004BCC8: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x8004BCCC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8004BCD0: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004BCD4: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004BCD8: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8004BCDC: bne         $v0, $zero, L_8004BCA4
    if (ctx->r2 != 0) {
        // 0x8004BCE0: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_8004BCA4;
    }
    // 0x8004BCE0: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x8004BCE4: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8004BCE8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8004BCEC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8004BCF0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8004BCF4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004BCF8: jr          $ra
    // 0x8004BCFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004BCFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8004BD00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004BD00: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8004BD04: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004BD08: addiu       $a0, $a0, 0x5583
    ctx->r4 = ADD32(ctx->r4, 0X5583);
    // 0x8004BD0C: sw          $ra, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r31;
    // 0x8004BD10: sw          $s3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r19;
    // 0x8004BD14: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x8004BD18: sw          $s1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r17;
    // 0x8004BD1C: sw          $s0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r16;
    // 0x8004BD20: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8004BD24: bne         $v0, $zero, L_8004BD44
    if (ctx->r2 != 0) {
        // 0x8004BD28: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8004BD44;
    }
    // 0x8004BD28: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004BD2C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8004BD30: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004BD34: sb          $zero, 0x188D($at)
    MEM_B(0X188D, ctx->r1) = 0;
    // 0x8004BD38: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004BD3C: sb          $zero, 0x188C($at)
    MEM_B(0X188C, ctx->r1) = 0;
    // 0x8004BD40: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_8004BD44:
    // 0x8004BD44: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004BD48: lb          $v1, 0x188C($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X188C);
    // 0x8004BD4C: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x8004BD50: beq         $v0, $zero, L_8004C38C
    if (ctx->r2 == 0) {
        // 0x8004BD54: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8004C38C;
    }
    // 0x8004BD54: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004BD58: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004BD5C: addu        $at, $at, $v0
    gpr jr_addend_8004BD64 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004BD60: lw          $v0, -0x1818($at)
    ctx->r2 = ADD32(ctx->r1, -0X1818);
    // 0x8004BD64: jr          $v0
    // 0x8004BD68: nop

    switch (jr_addend_8004BD64 >> 2) {
        case 0: goto L_8004BD6C; break;
        case 1: goto L_8004BEC8; break;
        case 2: goto L_8004C080; break;
        case 3: goto L_8004C2AC; break;
        case 4: goto L_8004C310; break;
        default: switch_error(__func__, 0x8004BD64, 0x800AE7E8);
    }
    // 0x8004BD68: nop

L_8004BD6C:
    // 0x8004BD6C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004BD70: lhu         $v1, -0x33C8($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X33C8);
    // 0x8004BD74: andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // 0x8004BD78: beq         $v0, $zero, L_8004BDB0
    if (ctx->r2 == 0) {
        // 0x8004BD7C: andi        $v0, $v1, 0x400
        ctx->r2 = ctx->r3 & 0X400;
            goto L_8004BDB0;
    }
    // 0x8004BD7C: andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // 0x8004BD80: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004BD84: lb          $v0, 0x188D($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X188D);
    // 0x8004BD88: blez        $v0, L_8004BDA0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004BD8C: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8004BDA0;
    }
    // 0x8004BD8C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004BD90: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8004BD94: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004BD98: j           L_8004BE8C
    // 0x8004BD9C: sb          $v0, 0x188D($at)
    MEM_B(0X188D, ctx->r1) = ctx->r2;
        goto L_8004BE8C;
    // 0x8004BD9C: sb          $v0, 0x188D($at)
    MEM_B(0X188D, ctx->r1) = ctx->r2;
L_8004BDA0:
    // 0x8004BDA0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004BDA4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004BDA8: j           L_8004BE8C
    // 0x8004BDAC: sb          $v0, 0x188D($at)
    MEM_B(0X188D, ctx->r1) = ctx->r2;
        goto L_8004BE8C;
    // 0x8004BDAC: sb          $v0, 0x188D($at)
    MEM_B(0X188D, ctx->r1) = ctx->r2;
L_8004BDB0:
    // 0x8004BDB0: beq         $v0, $zero, L_8004BDE8
    if (ctx->r2 == 0) {
        // 0x8004BDB4: andi        $v0, $v1, 0x8000
        ctx->r2 = ctx->r3 & 0X8000;
            goto L_8004BDE8;
    }
    // 0x8004BDB4: andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // 0x8004BDB8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004BDBC: lb          $v0, 0x188D($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X188D);
    // 0x8004BDC0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004BDC4: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8004BDC8: beq         $v0, $zero, L_8004BDDC
    if (ctx->r2 == 0) {
        // 0x8004BDCC: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8004BDDC;
    }
    // 0x8004BDCC: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8004BDD0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004BDD4: j           L_8004BE8C
    // 0x8004BDD8: sb          $v0, 0x188D($at)
    MEM_B(0X188D, ctx->r1) = ctx->r2;
        goto L_8004BE8C;
    // 0x8004BDD8: sb          $v0, 0x188D($at)
    MEM_B(0X188D, ctx->r1) = ctx->r2;
L_8004BDDC:
    // 0x8004BDDC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004BDE0: j           L_8004BE8C
    // 0x8004BDE4: sb          $zero, 0x188D($at)
    MEM_B(0X188D, ctx->r1) = 0;
        goto L_8004BE8C;
    // 0x8004BDE4: sb          $zero, 0x188D($at)
    MEM_B(0X188D, ctx->r1) = 0;
L_8004BDE8:
    // 0x8004BDE8: beq         $v0, $zero, L_8004BE8C
    if (ctx->r2 == 0) {
        // 0x8004BDEC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004BE8C;
    }
    // 0x8004BDEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004BDF0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004BDF4: lb          $v1, 0x188D($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X188D);
    // 0x8004BDF8: beq         $v1, $v0, L_8004BE5C
    if (ctx->r3 == ctx->r2) {
        // 0x8004BDFC: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8004BE5C;
    }
    // 0x8004BDFC: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8004BE00: beql        $v0, $zero, L_8004BE18
    if (ctx->r2 == 0) {
        // 0x8004BE04: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8004BE18;
    }
    goto skip_0;
    // 0x8004BE04: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_0:
    // 0x8004BE08: beq         $v1, $zero, L_8004BE28
    if (ctx->r3 == 0) {
        // 0x8004BE0C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8004BE28;
    }
    // 0x8004BE0C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8004BE10: j           L_8004BE8C
    // 0x8004BE14: nop

        goto L_8004BE8C;
    // 0x8004BE14: nop

L_8004BE18:
    // 0x8004BE18: beq         $v1, $v0, L_8004BE74
    if (ctx->r3 == ctx->r2) {
        // 0x8004BE1C: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8004BE74;
    }
    // 0x8004BE1C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8004BE20: j           L_8004BE8C
    // 0x8004BE24: nop

        goto L_8004BE8C;
    // 0x8004BE24: nop

L_8004BE28:
    // 0x8004BE28: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004BE2C: lbu         $v0, 0x2738($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2738);
    // 0x8004BE30: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8004BE34: lbu         $a0, 0x273A($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X273A);
    // 0x8004BE38: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004BE3C: sb          $v1, 0x188C($at)
    MEM_B(0X188C, ctx->r1) = ctx->r3;
    // 0x8004BE40: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004BE44: sb          $zero, 0x188E($at)
    MEM_B(0X188E, ctx->r1) = 0;
    // 0x8004BE48: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004BE4C: sb          $v0, 0x2083($at)
    MEM_B(0X2083, ctx->r1) = ctx->r2;
    // 0x8004BE50: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004BE54: j           L_8004BE8C
    // 0x8004BE58: sb          $a0, 0x2082($at)
    MEM_B(0X2082, ctx->r1) = ctx->r4;
        goto L_8004BE8C;
    // 0x8004BE58: sb          $a0, 0x2082($at)
    MEM_B(0X2082, ctx->r1) = ctx->r4;
L_8004BE5C:
    // 0x8004BE5C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004BE60: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004BE64: sb          $v0, 0x188C($at)
    MEM_B(0X188C, ctx->r1) = ctx->r2;
    // 0x8004BE68: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004BE6C: j           L_8004BE8C
    // 0x8004BE70: sb          $zero, 0x188E($at)
    MEM_B(0X188E, ctx->r1) = 0;
        goto L_8004BE8C;
    // 0x8004BE70: sb          $zero, 0x188E($at)
    MEM_B(0X188E, ctx->r1) = 0;
L_8004BE74:
    // 0x8004BE74: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004BE78: sb          $v0, 0x188C($at)
    MEM_B(0X188C, ctx->r1) = ctx->r2;
    // 0x8004BE7C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004BE80: sb          $zero, 0x188E($at)
    MEM_B(0X188E, ctx->r1) = 0;
    // 0x8004BE84: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004BE88: sb          $zero, 0x188F($at)
    MEM_B(0X188F, ctx->r1) = 0;
L_8004BE8C:
    // 0x8004BE8C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004BE90: lb          $v1, 0x188D($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X188D);
    // 0x8004BE94: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004BE98: bne         $v1, $v0, L_8004C384
    if (ctx->r3 != ctx->r2) {
        // 0x8004BE9C: ori         $v1, $zero, 0xC000
        ctx->r3 = 0 | 0XC000;
            goto L_8004C384;
    }
    // 0x8004BE9C: ori         $v1, $zero, 0xC000
    ctx->r3 = 0 | 0XC000;
    // 0x8004BEA0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8004BEA4: lhu         $v0, -0x38A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X38A0);
    // 0x8004BEA8: andi        $v0, $v0, 0xC000
    ctx->r2 = ctx->r2 & 0XC000;
    // 0x8004BEAC: bne         $v0, $v1, L_8004C384
    if (ctx->r2 != ctx->r3) {
        // 0x8004BEB0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8004C384;
    }
    // 0x8004BEB0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004BEB4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004BEB8: sb          $v0, 0x188C($at)
    MEM_B(0X188C, ctx->r1) = ctx->r2;
    // 0x8004BEBC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004BEC0: j           L_8004C384
    // 0x8004BEC4: sb          $zero, 0x188E($at)
    MEM_B(0X188E, ctx->r1) = 0;
        goto L_8004C384;
    // 0x8004BEC4: sb          $zero, 0x188E($at)
    MEM_B(0X188E, ctx->r1) = 0;
L_8004BEC8:
    // 0x8004BEC8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004BECC: lhu         $v1, -0x33C8($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X33C8);
    // 0x8004BED0: andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // 0x8004BED4: beq         $v0, $zero, L_8004BF0C
    if (ctx->r2 == 0) {
        // 0x8004BED8: andi        $v0, $v1, 0x400
        ctx->r2 = ctx->r3 & 0X400;
            goto L_8004BF0C;
    }
    // 0x8004BED8: andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // 0x8004BEDC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004BEE0: lb          $v0, 0x188E($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X188E);
    // 0x8004BEE4: blez        $v0, L_8004BEFC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004BEE8: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8004BEFC;
    }
    // 0x8004BEE8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004BEEC: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8004BEF0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004BEF4: j           L_8004C00C
    // 0x8004BEF8: sb          $v0, 0x188E($at)
    MEM_B(0X188E, ctx->r1) = ctx->r2;
        goto L_8004C00C;
    // 0x8004BEF8: sb          $v0, 0x188E($at)
    MEM_B(0X188E, ctx->r1) = ctx->r2;
L_8004BEFC:
    // 0x8004BEFC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8004BF00: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004BF04: j           L_8004C00C
    // 0x8004BF08: sb          $v0, 0x188E($at)
    MEM_B(0X188E, ctx->r1) = ctx->r2;
        goto L_8004C00C;
    // 0x8004BF08: sb          $v0, 0x188E($at)
    MEM_B(0X188E, ctx->r1) = ctx->r2;
L_8004BF0C:
    // 0x8004BF0C: beq         $v0, $zero, L_8004BF38
    if (ctx->r2 == 0) {
        // 0x8004BF10: andi        $v0, $v1, 0x100
        ctx->r2 = ctx->r3 & 0X100;
            goto L_8004BF38;
    }
    // 0x8004BF10: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8004BF14: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004BF18: lb          $v0, 0x188E($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X188E);
    // 0x8004BF1C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004BF20: slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8004BF24: beq         $v0, $zero, L_8004C004
    if (ctx->r2 == 0) {
        // 0x8004BF28: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8004C004;
    }
    // 0x8004BF28: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8004BF2C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004BF30: j           L_8004C00C
    // 0x8004BF34: sb          $v0, 0x188E($at)
    MEM_B(0X188E, ctx->r1) = ctx->r2;
        goto L_8004C00C;
    // 0x8004BF34: sb          $v0, 0x188E($at)
    MEM_B(0X188E, ctx->r1) = ctx->r2;
L_8004BF38:
    // 0x8004BF38: beq         $v0, $zero, L_8004BF90
    if (ctx->r2 == 0) {
        // 0x8004BF3C: andi        $v0, $v1, 0x200
        ctx->r2 = ctx->r3 & 0X200;
            goto L_8004BF90;
    }
    // 0x8004BF3C: andi        $v0, $v1, 0x200
    ctx->r2 = ctx->r3 & 0X200;
    // 0x8004BF40: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004BF44: lb          $a0, 0x188E($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X188E);
    // 0x8004BF48: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004BF4C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004BF50: lb          $v0, 0xB7A($v0)
    ctx->r2 = MEM_B(ctx->r2, 0XB7A);
    // 0x8004BF54: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004BF58: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8004BF5C: lb          $v1, 0x1880($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X1880);
    // 0x8004BF60: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8004BF64: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004BF68: beq         $v0, $zero, L_8004BF80
    if (ctx->r2 == 0) {
        // 0x8004BF6C: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_8004BF80;
    }
    // 0x8004BF6C: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x8004BF70: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004BF74: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8004BF78: j           L_8004C00C
    // 0x8004BF7C: sb          $v0, 0xB7A($at)
    MEM_B(0XB7A, ctx->r1) = ctx->r2;
        goto L_8004C00C;
    // 0x8004BF7C: sb          $v0, 0xB7A($at)
    MEM_B(0XB7A, ctx->r1) = ctx->r2;
L_8004BF80:
    // 0x8004BF80: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004BF84: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8004BF88: j           L_8004C00C
    // 0x8004BF8C: sb          $zero, 0xB7A($at)
    MEM_B(0XB7A, ctx->r1) = 0;
        goto L_8004C00C;
    // 0x8004BF8C: sb          $zero, 0xB7A($at)
    MEM_B(0XB7A, ctx->r1) = 0;
L_8004BF90:
    // 0x8004BF90: beq         $v0, $zero, L_8004BFE4
    if (ctx->r2 == 0) {
        // 0x8004BF94: andi        $v0, $v1, 0x8000
        ctx->r2 = ctx->r3 & 0X8000;
            goto L_8004BFE4;
    }
    // 0x8004BF94: andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // 0x8004BF98: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004BF9C: lb          $v1, 0x188E($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X188E);
    // 0x8004BFA0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004BFA4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004BFA8: lb          $v0, 0xB7A($v0)
    ctx->r2 = MEM_B(ctx->r2, 0XB7A);
    // 0x8004BFAC: blez        $v0, L_8004BFC8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004BFB0: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_8004BFC8;
    }
    // 0x8004BFB0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8004BFB4: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x8004BFB8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004BFBC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8004BFC0: j           L_8004C00C
    // 0x8004BFC4: sb          $v0, 0xB7A($at)
    MEM_B(0XB7A, ctx->r1) = ctx->r2;
        goto L_8004C00C;
    // 0x8004BFC4: sb          $v0, 0xB7A($at)
    MEM_B(0XB7A, ctx->r1) = ctx->r2;
L_8004BFC8:
    // 0x8004BFC8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004BFCC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004BFD0: lbu         $v0, 0x1880($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1880);
    // 0x8004BFD4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004BFD8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8004BFDC: j           L_8004C00C
    // 0x8004BFE0: sb          $v0, 0xB7A($at)
    MEM_B(0XB7A, ctx->r1) = ctx->r2;
        goto L_8004C00C;
    // 0x8004BFE0: sb          $v0, 0xB7A($at)
    MEM_B(0XB7A, ctx->r1) = ctx->r2;
L_8004BFE4:
    // 0x8004BFE4: beq         $v0, $zero, L_8004C00C
    if (ctx->r2 == 0) {
        // 0x8004BFE8: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_8004C00C;
    }
    // 0x8004BFE8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8004BFEC: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004BFF0: lb          $v1, 0x188E($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X188E);
    // 0x8004BFF4: bne         $v1, $v0, L_8004C00C
    if (ctx->r3 != ctx->r2) {
        // 0x8004BFF8: nop
    
            goto L_8004C00C;
    }
    // 0x8004BFF8: nop

    // 0x8004BFFC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004C000: sb          $zero, 0x188C($at)
    MEM_B(0X188C, ctx->r1) = 0;
L_8004C004:
    // 0x8004C004: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004C008: sb          $zero, 0x188E($at)
    MEM_B(0X188E, ctx->r1) = 0;
L_8004C00C:
    // 0x8004C00C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004C010: lb          $v0, 0xB7A($v0)
    ctx->r2 = MEM_B(ctx->r2, 0XB7A);
    // 0x8004C014: addiu       $v1, $zero, 0x11
    ctx->r3 = ADD32(0, 0X11);
    // 0x8004C018: bne         $v0, $v1, L_8004C02C
    if (ctx->r2 != ctx->r3) {
        // 0x8004C01C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004C02C;
    }
    // 0x8004C01C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004C020: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C024: j           L_8004C05C
    // 0x8004C028: sb          $v0, 0xB7C($at)
    MEM_B(0XB7C, ctx->r1) = ctx->r2;
        goto L_8004C05C;
    // 0x8004C028: sb          $v0, 0xB7C($at)
    MEM_B(0XB7C, ctx->r1) = ctx->r2;
L_8004C02C:
    // 0x8004C02C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004C030: lbu         $v0, 0x2083($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2083);
    // 0x8004C034: bne         $v0, $v1, L_8004C04C
    if (ctx->r2 != ctx->r3) {
        // 0x8004C038: nop
    
            goto L_8004C04C;
    }
    // 0x8004C038: nop

    // 0x8004C03C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004C040: lbu         $v0, 0x2082($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2082);
    // 0x8004C044: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C048: sb          $v0, 0xB7C($at)
    MEM_B(0XB7C, ctx->r1) = ctx->r2;
L_8004C04C:
    // 0x8004C04C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004C050: lbu         $v0, 0xB7C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB7C);
    // 0x8004C054: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C058: sb          $v0, 0x2082($at)
    MEM_B(0X2082, ctx->r1) = ctx->r2;
L_8004C05C:
    // 0x8004C05C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004C060: lbu         $v0, 0xB7A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB7A);
    // 0x8004C064: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004C068: lbu         $v1, 0xB7F($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XB7F);
    // 0x8004C06C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C070: sb          $v0, 0x2083($at)
    MEM_B(0X2083, ctx->r1) = ctx->r2;
    // 0x8004C074: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C078: j           L_8004C384
    // 0x8004C07C: sb          $v1, 0x2086($at)
    MEM_B(0X2086, ctx->r1) = ctx->r3;
        goto L_8004C384;
    // 0x8004C07C: sb          $v1, 0x2086($at)
    MEM_B(0X2086, ctx->r1) = ctx->r3;
L_8004C080:
    // 0x8004C080: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004C084: lhu         $v1, -0x33C8($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X33C8);
    // 0x8004C088: andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // 0x8004C08C: beq         $v0, $zero, L_8004C0C4
    if (ctx->r2 == 0) {
        // 0x8004C090: andi        $v0, $v1, 0x400
        ctx->r2 = ctx->r3 & 0X400;
            goto L_8004C0C4;
    }
    // 0x8004C090: andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // 0x8004C094: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004C098: lb          $v0, 0x188E($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X188E);
    // 0x8004C09C: blez        $v0, L_8004C0B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004C0A0: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8004C0B4;
    }
    // 0x8004C0A0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004C0A4: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8004C0A8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004C0AC: j           L_8004C250
    // 0x8004C0B0: sb          $v0, 0x188E($at)
    MEM_B(0X188E, ctx->r1) = ctx->r2;
        goto L_8004C250;
    // 0x8004C0B0: sb          $v0, 0x188E($at)
    MEM_B(0X188E, ctx->r1) = ctx->r2;
L_8004C0B4:
    // 0x8004C0B4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8004C0B8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004C0BC: j           L_8004C250
    // 0x8004C0C0: sb          $v0, 0x188E($at)
    MEM_B(0X188E, ctx->r1) = ctx->r2;
        goto L_8004C250;
    // 0x8004C0C0: sb          $v0, 0x188E($at)
    MEM_B(0X188E, ctx->r1) = ctx->r2;
L_8004C0C4:
    // 0x8004C0C4: beq         $v0, $zero, L_8004C0F0
    if (ctx->r2 == 0) {
        // 0x8004C0C8: andi        $v0, $v1, 0x100
        ctx->r2 = ctx->r3 & 0X100;
            goto L_8004C0F0;
    }
    // 0x8004C0C8: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8004C0CC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004C0D0: lb          $v0, 0x188E($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X188E);
    // 0x8004C0D4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004C0D8: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8004C0DC: beq         $v0, $zero, L_8004C248
    if (ctx->r2 == 0) {
        // 0x8004C0E0: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8004C248;
    }
    // 0x8004C0E0: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8004C0E4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004C0E8: j           L_8004C250
    // 0x8004C0EC: sb          $v0, 0x188E($at)
    MEM_B(0X188E, ctx->r1) = ctx->r2;
        goto L_8004C250;
    // 0x8004C0EC: sb          $v0, 0x188E($at)
    MEM_B(0X188E, ctx->r1) = ctx->r2;
L_8004C0F0:
    // 0x8004C0F0: beq         $v0, $zero, L_8004C18C
    if (ctx->r2 == 0) {
        // 0x8004C0F4: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8004C18C;
    }
    // 0x8004C0F4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004C0F8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C0FC: lb          $a0, 0x188E($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X188E);
    // 0x8004C100: beq         $a0, $v0, L_8004C150
    if (ctx->r4 == ctx->r2) {
        // 0x8004C104: nop
    
            goto L_8004C150;
    }
    // 0x8004C104: nop

    // 0x8004C108: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004C10C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004C110: lb          $v0, 0xB60($v0)
    ctx->r2 = MEM_B(ctx->r2, 0XB60);
    // 0x8004C114: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004C118: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8004C11C: lb          $v1, 0x1888($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X1888);
    // 0x8004C120: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8004C124: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004C128: beq         $v0, $zero, L_8004C140
    if (ctx->r2 == 0) {
        // 0x8004C12C: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_8004C140;
    }
    // 0x8004C12C: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x8004C130: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C134: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8004C138: j           L_8004C250
    // 0x8004C13C: sb          $v0, 0xB60($at)
    MEM_B(0XB60, ctx->r1) = ctx->r2;
        goto L_8004C250;
    // 0x8004C13C: sb          $v0, 0xB60($at)
    MEM_B(0XB60, ctx->r1) = ctx->r2;
L_8004C140:
    // 0x8004C140: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C144: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8004C148: j           L_8004C250
    // 0x8004C14C: sb          $zero, 0xB60($at)
    MEM_B(0XB60, ctx->r1) = 0;
        goto L_8004C250;
    // 0x8004C14C: sb          $zero, 0xB60($at)
    MEM_B(0XB60, ctx->r1) = 0;
L_8004C150:
    // 0x8004C150: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004C154: lb          $v0, 0xB63($v0)
    ctx->r2 = MEM_B(ctx->r2, 0XB63);
    // 0x8004C158: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004C15C: lb          $v1, 0x188B($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X188B);
    // 0x8004C160: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8004C164: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004C168: beq         $v0, $zero, L_8004C17C
    if (ctx->r2 == 0) {
        // 0x8004C16C: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8004C17C;
    }
    // 0x8004C16C: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8004C170: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C174: j           L_8004C250
    // 0x8004C178: sb          $v0, 0xB63($at)
    MEM_B(0XB63, ctx->r1) = ctx->r2;
        goto L_8004C250;
    // 0x8004C178: sb          $v0, 0xB63($at)
    MEM_B(0XB63, ctx->r1) = ctx->r2;
L_8004C17C:
    // 0x8004C17C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004C180: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C184: j           L_8004C250
    // 0x8004C188: sb          $v0, 0xB63($at)
    MEM_B(0XB63, ctx->r1) = ctx->r2;
        goto L_8004C250;
    // 0x8004C188: sb          $v0, 0xB63($at)
    MEM_B(0XB63, ctx->r1) = ctx->r2;
L_8004C18C:
    // 0x8004C18C: andi        $v0, $v1, 0x200
    ctx->r2 = ctx->r3 & 0X200;
    // 0x8004C190: beq         $v0, $zero, L_8004C224
    if (ctx->r2 == 0) {
        // 0x8004C194: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8004C224;
    }
    // 0x8004C194: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004C198: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004C19C: lb          $v1, 0x188E($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X188E);
    // 0x8004C1A0: beq         $v1, $v0, L_8004C1EC
    if (ctx->r3 == ctx->r2) {
        // 0x8004C1A4: nop
    
            goto L_8004C1EC;
    }
    // 0x8004C1A4: nop

    // 0x8004C1A8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004C1AC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004C1B0: lb          $v0, 0xB60($v0)
    ctx->r2 = MEM_B(ctx->r2, 0XB60);
    // 0x8004C1B4: blez        $v0, L_8004C1D0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004C1B8: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_8004C1D0;
    }
    // 0x8004C1B8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8004C1BC: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x8004C1C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C1C4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8004C1C8: j           L_8004C250
    // 0x8004C1CC: sb          $v0, 0xB60($at)
    MEM_B(0XB60, ctx->r1) = ctx->r2;
        goto L_8004C250;
    // 0x8004C1CC: sb          $v0, 0xB60($at)
    MEM_B(0XB60, ctx->r1) = ctx->r2;
L_8004C1D0:
    // 0x8004C1D0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004C1D4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004C1D8: lbu         $v0, 0x1888($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1888);
    // 0x8004C1DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C1E0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8004C1E4: j           L_8004C250
    // 0x8004C1E8: sb          $v0, 0xB60($at)
    MEM_B(0XB60, ctx->r1) = ctx->r2;
        goto L_8004C250;
    // 0x8004C1E8: sb          $v0, 0xB60($at)
    MEM_B(0XB60, ctx->r1) = ctx->r2;
L_8004C1EC:
    // 0x8004C1EC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004C1F0: lb          $v0, 0xB63($v0)
    ctx->r2 = MEM_B(ctx->r2, 0XB63);
    // 0x8004C1F4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004C1F8: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8004C1FC: bne         $v0, $zero, L_8004C210
    if (ctx->r2 != 0) {
        // 0x8004C200: addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
            goto L_8004C210;
    }
    // 0x8004C200: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8004C204: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C208: j           L_8004C250
    // 0x8004C20C: sb          $v0, 0xB63($at)
    MEM_B(0XB63, ctx->r1) = ctx->r2;
        goto L_8004C250;
    // 0x8004C20C: sb          $v0, 0xB63($at)
    MEM_B(0XB63, ctx->r1) = ctx->r2;
L_8004C210:
    // 0x8004C210: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004C214: lbu         $v0, 0x188B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X188B);
    // 0x8004C218: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C21C: j           L_8004C250
    // 0x8004C220: sb          $v0, 0xB63($at)
    MEM_B(0XB63, ctx->r1) = ctx->r2;
        goto L_8004C250;
    // 0x8004C220: sb          $v0, 0xB63($at)
    MEM_B(0XB63, ctx->r1) = ctx->r2;
L_8004C224:
    // 0x8004C224: andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // 0x8004C228: beq         $v0, $zero, L_8004C250
    if (ctx->r2 == 0) {
        // 0x8004C22C: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8004C250;
    }
    // 0x8004C22C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8004C230: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004C234: lb          $v1, 0x188E($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X188E);
    // 0x8004C238: bne         $v1, $v0, L_8004C25C
    if (ctx->r3 != ctx->r2) {
        // 0x8004C23C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8004C25C;
    }
    // 0x8004C23C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004C240: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004C244: sb          $zero, 0x188C($at)
    MEM_B(0X188C, ctx->r1) = 0;
L_8004C248:
    // 0x8004C248: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004C24C: sb          $zero, 0x188E($at)
    MEM_B(0X188E, ctx->r1) = 0;
L_8004C250:
    // 0x8004C250: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004C254: lb          $v1, 0x188E($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X188E);
    // 0x8004C258: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8004C25C:
    // 0x8004C25C: bne         $v1, $v0, L_8004C27C
    if (ctx->r3 != ctx->r2) {
        // 0x8004C260: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004C27C;
    }
    // 0x8004C260: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004C264: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004C268: lb          $v1, 0xB62($v1)
    ctx->r3 = MEM_B(ctx->r3, 0XB62);
    // 0x8004C26C: bne         $v1, $v0, L_8004C27C
    if (ctx->r3 != ctx->r2) {
        // 0x8004C270: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004C27C;
    }
    // 0x8004C270: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004C274: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C278: sb          $v0, 0xB61($at)
    MEM_B(0XB61, ctx->r1) = ctx->r2;
L_8004C27C:
    // 0x8004C27C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004C280: lb          $v1, 0x188E($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X188E);
    // 0x8004C284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004C288: bne         $v1, $v0, L_8004C384
    if (ctx->r3 != ctx->r2) {
        // 0x8004C28C: nop
    
            goto L_8004C384;
    }
    // 0x8004C28C: nop

    // 0x8004C290: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004C294: lb          $v0, 0xB61($v0)
    ctx->r2 = MEM_B(ctx->r2, 0XB61);
    // 0x8004C298: bne         $v0, $zero, L_8004C384
    if (ctx->r2 != 0) {
        // 0x8004C29C: nop
    
            goto L_8004C384;
    }
    // 0x8004C29C: nop

    // 0x8004C2A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C2A4: j           L_8004C384
    // 0x8004C2A8: sb          $zero, 0xB62($at)
    MEM_B(0XB62, ctx->r1) = 0;
        goto L_8004C384;
    // 0x8004C2A8: sb          $zero, 0xB62($at)
    MEM_B(0XB62, ctx->r1) = 0;
L_8004C2AC:
    // 0x8004C2AC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004C2B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C2B4: sb          $v0, 0xB60($at)
    MEM_B(0XB60, ctx->r1) = ctx->r2;
    // 0x8004C2B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004C2BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C2C0: sb          $v0, 0xB61($at)
    MEM_B(0XB61, ctx->r1) = ctx->r2;
    // 0x8004C2C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C2C8: sb          $zero, 0xB62($at)
    MEM_B(0XB62, ctx->r1) = 0;
    // 0x8004C2CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C2D0: sb          $v0, 0xB63($at)
    MEM_B(0XB63, ctx->r1) = ctx->r2;
    // 0x8004C2D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C2D8: sb          $zero, 0xB7A($at)
    MEM_B(0XB7A, ctx->r1) = 0;
    // 0x8004C2DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C2E0: sb          $zero, 0xB7B($at)
    MEM_B(0XB7B, ctx->r1) = 0;
    // 0x8004C2E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C2E8: sb          $v0, 0xB7C($at)
    MEM_B(0XB7C, ctx->r1) = ctx->r2;
    // 0x8004C2EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C2F0: sb          $v0, 0xB7D($at)
    MEM_B(0XB7D, ctx->r1) = ctx->r2;
    // 0x8004C2F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C2F8: sb          $zero, 0xB7E($at)
    MEM_B(0XB7E, ctx->r1) = 0;
    // 0x8004C2FC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C300: sb          $v0, 0xB7F($at)
    MEM_B(0XB7F, ctx->r1) = ctx->r2;
    // 0x8004C304: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004C308: j           L_8004C384
    // 0x8004C30C: sb          $zero, 0x188C($at)
    MEM_B(0X188C, ctx->r1) = 0;
        goto L_8004C384;
    // 0x8004C30C: sb          $zero, 0x188C($at)
    MEM_B(0X188C, ctx->r1) = 0;
L_8004C310:
    // 0x8004C310: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004C314: addiu       $a0, $a0, -0x1850
    ctx->r4 = ADD32(ctx->r4, -0X1850);
    // 0x8004C318: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8004C31C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8004C320: jal         0x8004DAB8
    // 0x8004C324: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_0;
    // 0x8004C324: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x8004C328: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004C32C: addiu       $a0, $a0, -0x1830
    ctx->r4 = ADD32(ctx->r4, -0X1830);
    // 0x8004C330: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    // 0x8004C334: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x8004C338: jal         0x8004DAB8
    // 0x8004C33C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_1;
    // 0x8004C33C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
    // 0x8004C340: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004C344: lbu         $v1, 0x188F($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X188F);
    // 0x8004C348: sltiu       $v0, $v1, 0x3C
    ctx->r2 = ctx->r3 < 0X3C ? 1 : 0;
    // 0x8004C34C: beq         $v0, $zero, L_8004C360
    if (ctx->r2 == 0) {
        // 0x8004C350: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8004C360;
    }
    // 0x8004C350: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8004C354: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004C358: j           L_8004C384
    // 0x8004C35C: sb          $v0, 0x188F($at)
    MEM_B(0X188F, ctx->r1) = ctx->r2;
        goto L_8004C384;
    // 0x8004C35C: sb          $v0, 0x188F($at)
    MEM_B(0X188F, ctx->r1) = ctx->r2;
L_8004C360:
    // 0x8004C360: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004C364: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C368: sb          $v0, 0x5582($at)
    MEM_B(0X5582, ctx->r1) = ctx->r2;
    // 0x8004C36C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004C370: sb          $zero, 0x5583($at)
    MEM_B(0X5583, ctx->r1) = 0;
    // 0x8004C374: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004C378: sb          $zero, 0x188D($at)
    MEM_B(0X188D, ctx->r1) = 0;
    // 0x8004C37C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004C380: sb          $zero, 0x188F($at)
    MEM_B(0X188F, ctx->r1) = 0;
L_8004C384:
    // 0x8004C384: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004C388: lb          $v1, 0x188C($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X188C);
L_8004C38C:
    // 0x8004C38C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004C390: beq         $v1, $v0, L_8004C55C
    if (ctx->r3 == ctx->r2) {
        // 0x8004C394: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8004C55C;
    }
    // 0x8004C394: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8004C398: beql        $v0, $zero, L_8004C3B0
    if (ctx->r2 == 0) {
        // 0x8004C39C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8004C3B0;
    }
    goto skip_1;
    // 0x8004C39C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_1:
    // 0x8004C3A0: beq         $v1, $zero, L_8004C3C0
    if (ctx->r3 == 0) {
        // 0x8004C3A4: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8004C3C0;
    }
    // 0x8004C3A4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004C3A8: j           L_8004CC80
    // 0x8004C3AC: nop

        goto L_8004CC80;
    // 0x8004C3AC: nop

L_8004C3B0:
    // 0x8004C3B0: beq         $v1, $v0, L_8004C94C
    if (ctx->r3 == ctx->r2) {
        // 0x8004C3B4: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8004C94C;
    }
    // 0x8004C3B4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004C3B8: bne         $v1, $v0, L_8004CC80
    if (ctx->r3 != ctx->r2) {
        // 0x8004C3BC: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8004CC80;
    }
    // 0x8004C3BC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8004C3C0:
    // 0x8004C3C0: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x8004C3C4: addiu       $s3, $s3, 0x1174
    ctx->r19 = ADD32(ctx->r19, 0X1174);
    // 0x8004C3C8: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x8004C3CC: addiu       $s1, $s1, 0x1808
    ctx->r17 = ADD32(ctx->r17, 0X1808);
    // 0x8004C3D0: addiu       $s2, $s1, 0x2
    ctx->r18 = ADD32(ctx->r17, 0X2);
    // 0x8004C3D4: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_8004C3D8:
    // 0x8004C3D8: sra         $v1, $v0, 24
    ctx->r3 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004C3DC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8004C3E0: bne         $v1, $v0, L_8004C4B0
    if (ctx->r3 != ctx->r2) {
        // 0x8004C3E4: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8004C4B0;
    }
    // 0x8004C3E4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004C3E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8004C3EC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8004C3F0: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
L_8004C3F4:
    // 0x8004C3F4: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004C3F8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004C3FC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004C400: lb          $v1, 0xB60($v1)
    ctx->r3 = MEM_B(ctx->r3, 0XB60);
    // 0x8004C404: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004C408: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004C40C: lb          $v0, -0x1D98($at)
    ctx->r2 = MEM_B(ctx->r1, -0X1D98);
    // 0x8004C410: bnel        $v1, $v0, L_8004C418
    if (ctx->r3 != ctx->r2) {
        // 0x8004C414: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8004C418;
    }
    goto skip_2;
    // 0x8004C414: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_2:
L_8004C418:
    // 0x8004C418: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8004C41C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8004C420: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004C424: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004C428: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8004C42C: bne         $v0, $zero, L_8004C3F4
    if (ctx->r2 != 0) {
        // 0x8004C430: sll         $v0, $a0, 24
        ctx->r2 = S32(ctx->r4 << 24);
            goto L_8004C3F4;
    }
    // 0x8004C430: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
    // 0x8004C434: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8004C438: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
L_8004C43C:
    // 0x8004C43C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004C440: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004C444: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004C448: lb          $v1, 0xB7A($v1)
    ctx->r3 = MEM_B(ctx->r3, 0XB7A);
    // 0x8004C44C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004C450: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004C454: lb          $v0, -0x1D94($at)
    ctx->r2 = MEM_B(ctx->r1, -0X1D94);
    // 0x8004C458: bnel        $v1, $v0, L_8004C460
    if (ctx->r3 != ctx->r2) {
        // 0x8004C45C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8004C460;
    }
    goto skip_3;
    // 0x8004C45C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_3:
L_8004C460:
    // 0x8004C460: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8004C464: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8004C468: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004C46C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004C470: slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8004C474: bne         $v0, $zero, L_8004C43C
    if (ctx->r2 != 0) {
        // 0x8004C478: sll         $v0, $a0, 24
        ctx->r2 = S32(ctx->r4 << 24);
            goto L_8004C43C;
    }
    // 0x8004C478: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
    // 0x8004C47C: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x8004C480: beq         $v0, $zero, L_8004C4AC
    if (ctx->r2 == 0) {
        // 0x8004C484: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_8004C4AC;
    }
    // 0x8004C484: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x8004C488: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8004C48C: addu        $v1, $v0, $s3
    ctx->r3 = ADD32(ctx->r2, ctx->r19);
    // 0x8004C490: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8004C494: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
    // 0x8004C498: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x8004C49C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8004C4A0: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8004C4A4: j           L_8004C4CC
    // 0x8004C4A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8004C4CC;
    // 0x8004C4A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8004C4AC:
    // 0x8004C4AC: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
L_8004C4B0:
    // 0x8004C4B0: addu        $v1, $v0, $s3
    ctx->r3 = ADD32(ctx->r2, ctx->r19);
    // 0x8004C4B4: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8004C4B8: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
    // 0x8004C4BC: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x8004C4C0: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8004C4C4: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8004C4C8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8004C4CC:
    // 0x8004C4CC: jal         0x8004DAB8
    // 0x8004C4D0: nop

    func_8004DAB8(rdram, ctx);
        goto after_2;
    // 0x8004C4D0: nop

    after_2:
    // 0x8004C4D4: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x8004C4D8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8004C4DC: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004C4E0: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004C4E4: slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8004C4E8: bne         $v0, $zero, L_8004C3D8
    if (ctx->r2 != 0) {
        // 0x8004C4EC: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_8004C3D8;
    }
    // 0x8004C4EC: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x8004C4F0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004C4F4: lb          $v1, 0x188D($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X188D);
    // 0x8004C4F8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8004C4FC: beq         $v1, $v0, L_8004C510
    if (ctx->r3 == ctx->r2) {
        // 0x8004C500: nop
    
            goto L_8004C510;
    }
    // 0x8004C500: nop

    // 0x8004C504: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C508: j           L_8004C518
    // 0x8004C50C: lw          $a0, 0x118C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X118C);
        goto L_8004C518;
    // 0x8004C50C: lw          $a0, 0x118C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X118C);
L_8004C510:
    // 0x8004C510: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C514: lw          $a0, 0x1190($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1190);
L_8004C518:
    // 0x8004C518: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8004C51C: lh          $a1, 0x1820($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X1820);
    // 0x8004C520: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8004C524: lh          $a2, 0x1822($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X1822);
    // 0x8004C528: jal         0x8004DAB8
    // 0x8004C52C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_3;
    // 0x8004C52C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_3:
    // 0x8004C530: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004C534: addiu       $a0, $a0, -0x1874
    ctx->r4 = ADD32(ctx->r4, -0X1874);
    // 0x8004C538: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004C53C: lb          $v0, 0x188D($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X188D);
    // 0x8004C540: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x8004C544: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8004C548: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x8004C54C: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8004C550: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8004C554: j           L_8004CC78
    // 0x8004C558: addiu       $a2, $a2, 0x3C
    ctx->r6 = ADD32(ctx->r6, 0X3C);
        goto L_8004CC78;
    // 0x8004C558: addiu       $a2, $a2, 0x3C
    ctx->r6 = ADD32(ctx->r6, 0X3C);
L_8004C55C:
    // 0x8004C55C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004C560: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x8004C564: addiu       $s3, $s3, 0x1194
    ctx->r19 = ADD32(ctx->r19, 0X1194);
    // 0x8004C568: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x8004C56C: addiu       $s1, $s1, 0x1844
    ctx->r17 = ADD32(ctx->r17, 0X1844);
    // 0x8004C570: addiu       $s2, $s1, 0x2
    ctx->r18 = ADD32(ctx->r17, 0X2);
    // 0x8004C574: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_8004C578:
    // 0x8004C578: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8004C57C: addu        $v1, $v0, $s3
    ctx->r3 = ADD32(ctx->r2, ctx->r19);
    // 0x8004C580: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8004C584: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
    // 0x8004C588: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x8004C58C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8004C590: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8004C594: jal         0x8004DAB8
    // 0x8004C598: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_4;
    // 0x8004C598: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_4:
    // 0x8004C59C: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x8004C5A0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8004C5A4: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004C5A8: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004C5AC: slti        $v0, $v0, 0x9
    ctx->r2 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x8004C5B0: bne         $v0, $zero, L_8004C578
    if (ctx->r2 != 0) {
        // 0x8004C5B4: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_8004C578;
    }
    // 0x8004C5B4: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x8004C5B8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004C5BC: addiu       $a0, $a0, -0x1874
    ctx->r4 = ADD32(ctx->r4, -0X1874);
    // 0x8004C5C0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004C5C4: lb          $v0, 0x188E($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X188E);
    // 0x8004C5C8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8004C5CC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8004C5D0: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x8004C5D4: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8004C5D8: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8004C5DC: jal         0x8004DAB8
    // 0x8004C5E0: addiu       $a2, $a2, 0x32
    ctx->r6 = ADD32(ctx->r6, 0X32);
    func_8004DAB8(rdram, ctx);
        goto after_5;
    // 0x8004C5E0: addiu       $a2, $a2, 0x32
    ctx->r6 = ADD32(ctx->r6, 0X32);
    after_5:
    // 0x8004C5E4: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004C5E8: lb          $v1, 0x188E($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X188E);
    // 0x8004C5EC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8004C5F0: beq         $v1, $v0, L_8004C604
    if (ctx->r3 == ctx->r2) {
        // 0x8004C5F4: nop
    
            goto L_8004C604;
    }
    // 0x8004C5F4: nop

    // 0x8004C5F8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C5FC: j           L_8004C60C
    // 0x8004C600: lw          $a0, 0x11B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11B8);
        goto L_8004C60C;
    // 0x8004C600: lw          $a0, 0x11B8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11B8);
L_8004C604:
    // 0x8004C604: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C608: lw          $a0, 0x11BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11BC);
L_8004C60C:
    // 0x8004C60C: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8004C610: lh          $a1, 0x1868($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X1868);
    // 0x8004C614: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8004C618: lh          $a2, 0x186A($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X186A);
    // 0x8004C61C: jal         0x8004DAB8
    // 0x8004C620: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_6;
    // 0x8004C620: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_6:
    // 0x8004C624: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004C628: lb          $v1, 0xB7A($v1)
    ctx->r3 = MEM_B(ctx->r3, 0XB7A);
    // 0x8004C62C: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x8004C630: bne         $v1, $v0, L_8004C66C
    if (ctx->r3 != ctx->r2) {
        // 0x8004C634: addiu       $v0, $zero, 0x11
        ctx->r2 = ADD32(0, 0X11);
            goto L_8004C66C;
    }
    // 0x8004C634: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x8004C638: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004C63C: lb          $v0, 0x2738($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2738);
    // 0x8004C640: bne         $v0, $v1, L_8004C65C
    if (ctx->r2 != ctx->r3) {
        // 0x8004C644: addiu       $a1, $zero, 0x8C
        ctx->r5 = ADD32(0, 0X8C);
            goto L_8004C65C;
    }
    // 0x8004C644: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x8004C648: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C64C: lw          $a0, 0x120C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X120C);
    // 0x8004C650: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x8004C654: j           L_8004C71C
    // 0x8004C658: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_8004C71C;
    // 0x8004C658: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8004C65C:
    // 0x8004C65C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C660: lw          $a0, 0x120C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X120C);
    // 0x8004C664: j           L_8004C718
    // 0x8004C668: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
        goto L_8004C718;
    // 0x8004C668: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
L_8004C66C:
    // 0x8004C66C: bne         $v1, $v0, L_8004C6D8
    if (ctx->r3 != ctx->r2) {
        // 0x8004C670: nop
    
            goto L_8004C6D8;
    }
    // 0x8004C670: nop

    // 0x8004C674: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004C678: lb          $v0, 0x2738($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2738);
    // 0x8004C67C: bne         $v0, $v1, L_8004C6B0
    if (ctx->r2 != ctx->r3) {
        // 0x8004C680: addiu       $a1, $zero, 0x8C
        ctx->r5 = ADD32(0, 0X8C);
            goto L_8004C6B0;
    }
    // 0x8004C680: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x8004C684: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C688: lw          $a0, 0x1204($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1204);
    // 0x8004C68C: addiu       $a2, $zero, 0x2D
    ctx->r6 = ADD32(0, 0X2D);
    // 0x8004C690: jal         0x8004DAB8
    // 0x8004C694: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_7;
    // 0x8004C694: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_7:
    // 0x8004C698: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C69C: lw          $a0, 0x1208($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1208);
    // 0x8004C6A0: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x8004C6A4: addiu       $a2, $zero, 0x37
    ctx->r6 = ADD32(0, 0X37);
    // 0x8004C6A8: j           L_8004C71C
    // 0x8004C6AC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_8004C71C;
    // 0x8004C6AC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8004C6B0:
    // 0x8004C6B0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C6B4: lw          $a0, 0x1204($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1204);
    // 0x8004C6B8: addiu       $a2, $zero, 0x2D
    ctx->r6 = ADD32(0, 0X2D);
    // 0x8004C6BC: jal         0x8004DAB8
    // 0x8004C6C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8004DAB8(rdram, ctx);
        goto after_8;
    // 0x8004C6C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x8004C6C4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C6C8: lw          $a0, 0x1208($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1208);
    // 0x8004C6CC: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x8004C6D0: j           L_8004C718
    // 0x8004C6D4: addiu       $a2, $zero, 0x37
    ctx->r6 = ADD32(0, 0X37);
        goto L_8004C718;
    // 0x8004C6D4: addiu       $a2, $zero, 0x37
    ctx->r6 = ADD32(0, 0X37);
L_8004C6D8:
    // 0x8004C6D8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004C6DC: lb          $v0, 0x2738($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2738);
    // 0x8004C6E0: bne         $v1, $v0, L_8004C704
    if (ctx->r3 != ctx->r2) {
        // 0x8004C6E4: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8004C704;
    }
    // 0x8004C6E4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004C6E8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C6EC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004C6F0: lw          $a0, 0x11C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11C0);
    // 0x8004C6F4: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x8004C6F8: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x8004C6FC: j           L_8004C71C
    // 0x8004C700: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_8004C71C;
    // 0x8004C700: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8004C704:
    // 0x8004C704: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C708: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004C70C: lw          $a0, 0x11C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11C0);
    // 0x8004C710: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x8004C714: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
L_8004C718:
    // 0x8004C718: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8004C71C:
    // 0x8004C71C: jal         0x8004DAB8
    // 0x8004C720: nop

    func_8004DAB8(rdram, ctx);
        goto after_9;
    // 0x8004C720: nop

    after_9:
    // 0x8004C724: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8004C728: addiu       $s0, $s0, 0xB7B
    ctx->r16 = ADD32(ctx->r16, 0XB7B);
    // 0x8004C72C: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x8004C730: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004C734: lb          $v0, 0x2739($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2739);
    // 0x8004C738: bne         $v1, $v0, L_8004C7A0
    if (ctx->r3 != ctx->r2) {
        // 0x8004C73C: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_8004C7A0;
    }
    // 0x8004C73C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004C740: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004C744: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004C748: lb          $v0, -0x1900($at)
    ctx->r2 = MEM_B(ctx->r1, -0X1900);
    // 0x8004C74C: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x8004C750: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C754: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C758: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004C75C: lw          $a0, 0x1210($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1210);
    // 0x8004C760: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x8004C764: jal         0x8004DAB8
    // 0x8004C768: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_10;
    // 0x8004C768: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_10:
    // 0x8004C76C: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x8004C770: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004C774: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004C778: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004C77C: lb          $v0, -0x18FF($at)
    ctx->r2 = MEM_B(ctx->r1, -0X18FF);
    // 0x8004C780: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    // 0x8004C784: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C788: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C78C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004C790: lw          $a0, 0x1210($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1210);
    // 0x8004C794: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x8004C798: j           L_8004C7FC
    // 0x8004C79C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_8004C7FC;
    // 0x8004C79C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8004C7A0:
    // 0x8004C7A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004C7A4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004C7A8: lb          $v0, -0x1900($at)
    ctx->r2 = MEM_B(ctx->r1, -0X1900);
    // 0x8004C7AC: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x8004C7B0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C7B4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C7B8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004C7BC: lw          $a0, 0x1210($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1210);
    // 0x8004C7C0: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x8004C7C4: jal         0x8004DAB8
    // 0x8004C7C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8004DAB8(rdram, ctx);
        goto after_11;
    // 0x8004C7C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_11:
    // 0x8004C7CC: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x8004C7D0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004C7D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004C7D8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004C7DC: lb          $v0, -0x18FF($at)
    ctx->r2 = MEM_B(ctx->r1, -0X18FF);
    // 0x8004C7E0: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    // 0x8004C7E4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004C7E8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C7EC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004C7F0: lw          $a0, 0x1210($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1210);
    // 0x8004C7F4: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x8004C7F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8004C7FC:
    // 0x8004C7FC: jal         0x8004DAB8
    // 0x8004C800: nop

    func_8004DAB8(rdram, ctx);
        goto after_12;
    // 0x8004C800: nop

    after_12:
    // 0x8004C804: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004C808: lb          $v1, 0xB7C($v1)
    ctx->r3 = MEM_B(ctx->r3, 0XB7C);
    // 0x8004C80C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004C810: lb          $v0, 0x273A($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X273A);
    // 0x8004C814: bne         $v1, $v0, L_8004C838
    if (ctx->r3 != ctx->r2) {
        // 0x8004C818: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8004C838;
    }
    // 0x8004C818: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004C81C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C820: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004C824: lw          $a0, 0x1220($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1220);
    // 0x8004C828: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x8004C82C: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x8004C830: j           L_8004C850
    // 0x8004C834: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_8004C850;
    // 0x8004C834: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8004C838:
    // 0x8004C838: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C83C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004C840: lw          $a0, 0x1220($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1220);
    // 0x8004C844: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x8004C848: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    // 0x8004C84C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8004C850:
    // 0x8004C850: jal         0x8004DAB8
    // 0x8004C854: nop

    func_8004DAB8(rdram, ctx);
        goto after_13;
    // 0x8004C854: nop

    after_13:
    // 0x8004C858: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004C85C: lb          $v1, 0xB7D($v1)
    ctx->r3 = MEM_B(ctx->r3, 0XB7D);
    // 0x8004C860: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004C864: lb          $v0, 0x273B($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X273B);
    // 0x8004C868: bne         $v1, $v0, L_8004C88C
    if (ctx->r3 != ctx->r2) {
        // 0x8004C86C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8004C88C;
    }
    // 0x8004C86C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004C870: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C874: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004C878: lw          $a0, 0x1220($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1220);
    // 0x8004C87C: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x8004C880: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    // 0x8004C884: j           L_8004C8A4
    // 0x8004C888: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_8004C8A4;
    // 0x8004C888: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8004C88C:
    // 0x8004C88C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C890: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004C894: lw          $a0, 0x1220($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1220);
    // 0x8004C898: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x8004C89C: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    // 0x8004C8A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8004C8A4:
    // 0x8004C8A4: jal         0x8004DAB8
    // 0x8004C8A8: nop

    func_8004DAB8(rdram, ctx);
        goto after_14;
    // 0x8004C8A8: nop

    after_14:
    // 0x8004C8AC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004C8B0: lb          $v1, 0xB7E($v1)
    ctx->r3 = MEM_B(ctx->r3, 0XB7E);
    // 0x8004C8B4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004C8B8: lb          $v0, 0x273C($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X273C);
    // 0x8004C8BC: bne         $v1, $v0, L_8004C8E0
    if (ctx->r3 != ctx->r2) {
        // 0x8004C8C0: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8004C8E0;
    }
    // 0x8004C8C0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004C8C4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C8C8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004C8CC: lw          $a0, 0x1228($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1228);
    // 0x8004C8D0: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x8004C8D4: addiu       $a2, $zero, 0x82
    ctx->r6 = ADD32(0, 0X82);
    // 0x8004C8D8: j           L_8004C8F8
    // 0x8004C8DC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_8004C8F8;
    // 0x8004C8DC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8004C8E0:
    // 0x8004C8E0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C8E4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004C8E8: lw          $a0, 0x1228($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1228);
    // 0x8004C8EC: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x8004C8F0: addiu       $a2, $zero, 0x82
    ctx->r6 = ADD32(0, 0X82);
    // 0x8004C8F4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8004C8F8:
    // 0x8004C8F8: jal         0x8004DAB8
    // 0x8004C8FC: nop

    func_8004DAB8(rdram, ctx);
        goto after_15;
    // 0x8004C8FC: nop

    after_15:
    // 0x8004C900: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004C904: lb          $v1, 0xB7F($v1)
    ctx->r3 = MEM_B(ctx->r3, 0XB7F);
    // 0x8004C908: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004C90C: lb          $v0, 0x273D($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X273D);
    // 0x8004C910: bne         $v1, $v0, L_8004C930
    if (ctx->r3 != ctx->r2) {
        // 0x8004C914: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8004C930;
    }
    // 0x8004C914: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004C918: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C91C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004C920: lw          $a0, 0x1230($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1230);
    // 0x8004C924: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x8004C928: j           L_8004CC74
    // 0x8004C92C: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
        goto L_8004CC74;
    // 0x8004C92C: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
L_8004C930:
    // 0x8004C930: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004C934: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004C938: lw          $a0, 0x1230($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1230);
    // 0x8004C93C: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x8004C940: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x8004C944: j           L_8004CC78
    // 0x8004C948: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8004CC78;
    // 0x8004C948: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8004C94C:
    // 0x8004C94C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004C950: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x8004C954: addiu       $s3, $s3, 0x1238
    ctx->r19 = ADD32(ctx->r19, 0X1238);
    // 0x8004C958: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x8004C95C: addiu       $s1, $s1, 0x1824
    ctx->r17 = ADD32(ctx->r17, 0X1824);
    // 0x8004C960: addiu       $s2, $s1, 0x2
    ctx->r18 = ADD32(ctx->r17, 0X2);
    // 0x8004C964: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_8004C968:
    // 0x8004C968: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8004C96C: addu        $v1, $v0, $s3
    ctx->r3 = ADD32(ctx->r2, ctx->r19);
    // 0x8004C970: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8004C974: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
    // 0x8004C978: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x8004C97C: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8004C980: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8004C984: jal         0x8004DAB8
    // 0x8004C988: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_16;
    // 0x8004C988: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_16:
    // 0x8004C98C: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x8004C990: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8004C994: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004C998: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004C99C: slti        $v0, $v0, 0x7
    ctx->r2 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x8004C9A0: bne         $v0, $zero, L_8004C968
    if (ctx->r2 != 0) {
        // 0x8004C9A4: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_8004C968;
    }
    // 0x8004C9A4: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x8004C9A8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004C9AC: addiu       $a0, $a0, -0x1874
    ctx->r4 = ADD32(ctx->r4, -0X1874);
    // 0x8004C9B0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8004C9B4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8004C9B8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004C9BC: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x8004C9C0: addiu       $s3, $s3, 0x125C
    ctx->r19 = ADD32(ctx->r19, 0X125C);
    // 0x8004C9C4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004C9C8: lb          $v0, 0x188E($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X188E);
    // 0x8004C9CC: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x8004C9D0: addiu       $s1, $s1, 0x186C
    ctx->r17 = ADD32(ctx->r17, 0X186C);
    // 0x8004C9D4: addiu       $s2, $s1, 0x2
    ctx->r18 = ADD32(ctx->r17, 0X2);
    // 0x8004C9D8: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x8004C9DC: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8004C9E0: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8004C9E4: jal         0x8004DAB8
    // 0x8004C9E8: addiu       $a2, $a2, 0x3C
    ctx->r6 = ADD32(ctx->r6, 0X3C);
    func_8004DAB8(rdram, ctx);
        goto after_17;
    // 0x8004C9E8: addiu       $a2, $a2, 0x3C
    ctx->r6 = ADD32(ctx->r6, 0X3C);
    after_17:
    // 0x8004C9EC: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_8004C9F0:
    // 0x8004C9F0: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8004C9F4: addu        $v1, $v0, $s3
    ctx->r3 = ADD32(ctx->r2, ctx->r19);
    // 0x8004C9F8: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8004C9FC: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
    // 0x8004CA00: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x8004CA04: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8004CA08: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8004CA0C: jal         0x8004DAB8
    // 0x8004CA10: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_18;
    // 0x8004CA10: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_18:
    // 0x8004CA14: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x8004CA18: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8004CA1C: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004CA20: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004CA24: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8004CA28: bne         $v0, $zero, L_8004C9F0
    if (ctx->r2 != 0) {
        // 0x8004CA2C: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_8004C9F0;
    }
    // 0x8004CA2C: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x8004CA30: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8004CA34:
    // 0x8004CA34: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004CA38: lb          $v1, 0xB60($v1)
    ctx->r3 = MEM_B(ctx->r3, 0XB60);
    // 0x8004CA3C: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x8004CA40: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004CA44: beql        $v1, $v0, L_8004CA74
    if (ctx->r3 == ctx->r2) {
        // 0x8004CA48: addiu       $v0, $s0, 0x1
        ctx->r2 = ADD32(ctx->r16, 0X1);
            goto L_8004CA74;
    }
    goto skip_4;
    // 0x8004CA48: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    skip_4:
    // 0x8004CA4C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004CA50: addiu       $a0, $a0, -0x1824
    ctx->r4 = ADD32(ctx->r4, -0X1824);
    // 0x8004CA54: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x8004CA58: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8004CA5C: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x8004CA60: addiu       $a1, $a1, 0xBE
    ctx->r5 = ADD32(ctx->r5, 0XBE);
    // 0x8004CA64: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x8004CA68: jal         0x8004DAB8
    // 0x8004CA6C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_19;
    // 0x8004CA6C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_19:
    // 0x8004CA70: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
L_8004CA74:
    // 0x8004CA74: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8004CA78: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004CA7C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004CA80: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8004CA84: bne         $v0, $zero, L_8004CA34
    if (ctx->r2 != 0) {
        // 0x8004CA88: nop
    
            goto L_8004CA34;
    }
    // 0x8004CA88: nop

    // 0x8004CA8C: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8004CA90: addiu       $s0, $s0, 0xB60
    ctx->r16 = ADD32(ctx->r16, 0XB60);
    // 0x8004CA94: lb          $a2, 0x0($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X0);
    // 0x8004CA98: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8004CA9C: addiu       $s1, $s1, 0x7458
    ctx->r17 = ADD32(ctx->r17, 0X7458);
    // 0x8004CAA0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8004CAA4: addiu       $a1, $a1, -0x1820
    ctx->r5 = ADD32(ctx->r5, -0X1820);
    // 0x8004CAA8: jal         0x80066CA0
    // 0x8004CAAC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80066CA0(rdram, ctx);
        goto after_20;
    // 0x8004CAAC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_20:
    // 0x8004CAB0: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x8004CAB4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004CAB8: lb          $v0, -0x2AEC($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2AEC);
    // 0x8004CABC: bne         $v1, $v0, L_8004CAE0
    if (ctx->r3 != ctx->r2) {
        // 0x8004CAC0: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8004CAE0;
    }
    // 0x8004CAC0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004CAC4: sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3 << 2);
    // 0x8004CAC8: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x8004CACC: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x8004CAD0: addiu       $a1, $a1, 0xBE
    ctx->r5 = ADD32(ctx->r5, 0XBE);
    // 0x8004CAD4: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x8004CAD8: j           L_8004CAF8
    // 0x8004CADC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_8004CAF8;
    // 0x8004CADC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8004CAE0:
    // 0x8004CAE0: sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3 << 2);
    // 0x8004CAE4: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x8004CAE8: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x8004CAEC: addiu       $a1, $a1, 0xBE
    ctx->r5 = ADD32(ctx->r5, 0XBE);
    // 0x8004CAF0: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x8004CAF4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8004CAF8:
    // 0x8004CAF8: jal         0x8004DAB8
    // 0x8004CAFC: nop

    func_8004DAB8(rdram, ctx);
        goto after_21;
    // 0x8004CAFC: nop

    after_21:
    // 0x8004CB00: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004CB04: lb          $v1, 0xB61($v1)
    ctx->r3 = MEM_B(ctx->r3, 0XB61);
    // 0x8004CB08: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004CB0C: lb          $v0, -0x2AEB($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2AEB);
    // 0x8004CB10: bne         $v1, $v0, L_8004CB3C
    if (ctx->r3 != ctx->r2) {
        // 0x8004CB14: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8004CB3C;
    }
    // 0x8004CB14: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004CB18: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004CB1C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004CB20: lw          $a0, 0x126C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X126C);
    // 0x8004CB24: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8004CB28: lh          $a1, 0x1874($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X1874);
    // 0x8004CB2C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8004CB30: lh          $a2, 0x1876($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X1876);
    // 0x8004CB34: j           L_8004CB5C
    // 0x8004CB38: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_8004CB5C;
    // 0x8004CB38: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8004CB3C:
    // 0x8004CB3C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004CB40: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004CB44: lw          $a0, 0x126C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X126C);
    // 0x8004CB48: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8004CB4C: lh          $a1, 0x1874($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X1874);
    // 0x8004CB50: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8004CB54: lh          $a2, 0x1876($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X1876);
    // 0x8004CB58: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8004CB5C:
    // 0x8004CB5C: jal         0x8004DAB8
    // 0x8004CB60: nop

    func_8004DAB8(rdram, ctx);
        goto after_22;
    // 0x8004CB60: nop

    after_22:
    // 0x8004CB64: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004CB68: lb          $v1, 0xB62($v1)
    ctx->r3 = MEM_B(ctx->r3, 0XB62);
    // 0x8004CB6C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004CB70: lb          $v0, -0x2AEA($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2AEA);
    // 0x8004CB74: bne         $v1, $v0, L_8004CBA0
    if (ctx->r3 != ctx->r2) {
        // 0x8004CB78: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8004CBA0;
    }
    // 0x8004CB78: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004CB7C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004CB80: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004CB84: lw          $a0, 0x126C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X126C);
    // 0x8004CB88: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8004CB8C: lh          $a1, 0x1878($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X1878);
    // 0x8004CB90: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8004CB94: lh          $a2, 0x187A($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X187A);
    // 0x8004CB98: j           L_8004CBC0
    // 0x8004CB9C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_8004CBC0;
    // 0x8004CB9C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8004CBA0:
    // 0x8004CBA0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004CBA4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004CBA8: lw          $a0, 0x126C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X126C);
    // 0x8004CBAC: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8004CBB0: lh          $a1, 0x1878($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X1878);
    // 0x8004CBB4: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8004CBB8: lh          $a2, 0x187A($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X187A);
    // 0x8004CBBC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8004CBC0:
    // 0x8004CBC0: jal         0x8004DAB8
    // 0x8004CBC4: nop

    func_8004DAB8(rdram, ctx);
        goto after_23;
    // 0x8004CBC4: nop

    after_23:
    // 0x8004CBC8: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8004CBCC: addiu       $s1, $s1, 0x7458
    ctx->r17 = ADD32(ctx->r17, 0X7458);
    // 0x8004CBD0: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8004CBD4: addiu       $s0, $s0, 0xB63
    ctx->r16 = ADD32(ctx->r16, 0XB63);
    // 0x8004CBD8: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x8004CBDC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004CBE0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8004CBE4: addiu       $a1, $a1, -0x1820
    ctx->r5 = ADD32(ctx->r5, -0X1820);
    // 0x8004CBE8: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
    // 0x8004CBEC: jal         0x80066CA0
    // 0x8004CBF0: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    func_80066CA0(rdram, ctx);
        goto after_24;
    // 0x8004CBF0: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    after_24:
    // 0x8004CBF4: lb          $v1, 0x0($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X0);
    // 0x8004CBF8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004CBFC: lb          $v0, -0x2AE9($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2AE9);
    // 0x8004CC00: bne         $v1, $v0, L_8004CC20
    if (ctx->r3 != ctx->r2) {
        // 0x8004CC04: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8004CC20;
    }
    // 0x8004CC04: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8004CC08: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8004CC0C: lh          $a1, 0x187C($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X187C);
    // 0x8004CC10: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8004CC14: lh          $a2, 0x187E($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X187E);
    // 0x8004CC18: j           L_8004CC34
    // 0x8004CC1C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_8004CC34;
    // 0x8004CC1C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8004CC20:
    // 0x8004CC20: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8004CC24: lh          $a1, 0x187C($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X187C);
    // 0x8004CC28: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8004CC2C: lh          $a2, 0x187E($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X187E);
    // 0x8004CC30: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8004CC34:
    // 0x8004CC34: jal         0x8004DAB8
    // 0x8004CC38: nop

    func_8004DAB8(rdram, ctx);
        goto after_25;
    // 0x8004CC38: nop

    after_25:
    // 0x8004CC3C: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004CC40: lb          $v1, 0x188E($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X188E);
    // 0x8004CC44: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8004CC48: beq         $v1, $v0, L_8004CC5C
    if (ctx->r3 == ctx->r2) {
        // 0x8004CC4C: nop
    
            goto L_8004CC5C;
    }
    // 0x8004CC4C: nop

    // 0x8004CC50: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004CC54: j           L_8004CC64
    // 0x8004CC58: lw          $a0, 0x1254($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1254);
        goto L_8004CC64;
    // 0x8004CC58: lw          $a0, 0x1254($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1254);
L_8004CC5C:
    // 0x8004CC5C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004CC60: lw          $a0, 0x1258($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1258);
L_8004CC64:
    // 0x8004CC64: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x8004CC68: lh          $a1, 0x1840($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X1840);
    // 0x8004CC6C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8004CC70: lh          $a2, 0x1842($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X1842);
L_8004CC74:
    // 0x8004CC74: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8004CC78:
    // 0x8004CC78: jal         0x8004DAB8
    // 0x8004CC7C: nop

    func_8004DAB8(rdram, ctx);
        goto after_26;
    // 0x8004CC7C: nop

    after_26:
L_8004CC80:
    // 0x8004CC80: lw          $ra, 0xA8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA8);
    // 0x8004CC84: lw          $s3, 0xA4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XA4);
    // 0x8004CC88: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x8004CC8C: lw          $s1, 0x9C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X9C);
    // 0x8004CC90: lw          $s0, 0x98($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X98);
    // 0x8004CC94: jr          $ra
    // 0x8004CC98: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8004CC98: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_8004CC9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CC9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004CCA0: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8004CCA4: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x8004CCA8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004CCAC: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8004CCB0: lui         $a3, 0xF600
    ctx->r7 = S32(0XF600 << 16);
    // 0x8004CCB4: ori         $a3, $a3, 0x168
    ctx->r7 = ctx->r7 | 0X168;
    // 0x8004CCB8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8004CCBC: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8004CCC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CCC4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004CCC8: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x8004CCCC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004CCD0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004CCD4: addiu       $v0, $v0, 0x1278
    ctx->r2 = ADD32(ctx->r2, 0X1278);
    // 0x8004CCD8: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_8004CCDC:
    // 0x8004CCDC: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8004CCE0: lw          $a2, 0x2FE4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2FE4);
    // 0x8004CCE4: sll         $v1, $t1, 24
    ctx->r3 = S32(ctx->r9 << 24);
    // 0x8004CCE8: addiu       $a1, $t1, 0x1
    ctx->r5 = ADD32(ctx->r9, 0X1);
    // 0x8004CCEC: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // 0x8004CCF0: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8004CCF4: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
    // 0x8004CCF8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8004CCFC: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x8004CD00: andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
    // 0x8004CD04: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x8004CD08: or          $v1, $v1, $a3
    ctx->r3 = ctx->r3 | ctx->r7;
    // 0x8004CD0C: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x8004CD10: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x8004CD14: slti        $a1, $a1, 0x20
    ctx->r5 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // 0x8004CD18: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
    // 0x8004CD1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CD20: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004CD24: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
    // 0x8004CD28: ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
    // 0x8004CD2C: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x8004CD30: addiu       $v0, $a2, 0x10
    ctx->r2 = ADD32(ctx->r6, 0X10);
    // 0x8004CD34: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x8004CD38: andi        $a0, $a0, 0x3FF
    ctx->r4 = ctx->r4 & 0X3FF;
    // 0x8004CD3C: sll         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4 << 14);
    // 0x8004CD40: ori         $a0, $a0, 0xC8
    ctx->r4 = ctx->r4 | 0XC8;
    // 0x8004CD44: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x8004CD48: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CD4C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004CD50: sw          $v1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r3;
    // 0x8004CD54: bne         $a1, $zero, L_8004CCDC
    if (ctx->r5 != 0) {
        // 0x8004CD58: sw          $a0, 0xC($a2)
        MEM_W(0XC, ctx->r6) = ctx->r4;
            goto L_8004CCDC;
    }
    // 0x8004CD58: sw          $a0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r4;
    // 0x8004CD5C: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8004CD60: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x8004CD64: lui         $a3, 0xF600
    ctx->r7 = S32(0XF600 << 16);
    // 0x8004CD68: ori         $a3, $a3, 0x208
    ctx->r7 = ctx->r7 | 0X208;
L_8004CD6C:
    // 0x8004CD6C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8004CD70: lw          $a2, 0x2FE4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2FE4);
    // 0x8004CD74: sll         $v1, $t1, 24
    ctx->r3 = S32(ctx->r9 << 24);
    // 0x8004CD78: addiu       $a1, $t1, 0x1
    ctx->r5 = ADD32(ctx->r9, 0X1);
    // 0x8004CD7C: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // 0x8004CD80: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8004CD84: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
    // 0x8004CD88: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8004CD8C: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x8004CD90: andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
    // 0x8004CD94: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x8004CD98: or          $v1, $v1, $a3
    ctx->r3 = ctx->r3 | ctx->r7;
    // 0x8004CD9C: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x8004CDA0: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x8004CDA4: slti        $a1, $a1, 0x20
    ctx->r5 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // 0x8004CDA8: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
    // 0x8004CDAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CDB0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004CDB4: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8004CDB8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8004CDBC: ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
    // 0x8004CDC0: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x8004CDC4: addiu       $v0, $a2, 0x10
    ctx->r2 = ADD32(ctx->r6, 0X10);
    // 0x8004CDC8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x8004CDCC: andi        $a0, $a0, 0x3FF
    ctx->r4 = ctx->r4 & 0X3FF;
    // 0x8004CDD0: sll         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4 << 14);
    // 0x8004CDD4: ori         $a0, $a0, 0x168
    ctx->r4 = ctx->r4 | 0X168;
    // 0x8004CDD8: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x8004CDDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CDE0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004CDE4: sw          $v1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r3;
    // 0x8004CDE8: bne         $a1, $zero, L_8004CD6C
    if (ctx->r5 != 0) {
        // 0x8004CDEC: sw          $a0, 0xC($a2)
        MEM_W(0XC, ctx->r6) = ctx->r4;
            goto L_8004CD6C;
    }
    // 0x8004CDEC: sw          $a0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r4;
    // 0x8004CDF0: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8004CDF4: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x8004CDF8: lui         $a3, 0xF600
    ctx->r7 = S32(0XF600 << 16);
    // 0x8004CDFC: ori         $a3, $a3, 0x2A8
    ctx->r7 = ctx->r7 | 0X2A8;
L_8004CE00:
    // 0x8004CE00: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8004CE04: lw          $a2, 0x2FE4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2FE4);
    // 0x8004CE08: sll         $v1, $t1, 24
    ctx->r3 = S32(ctx->r9 << 24);
    // 0x8004CE0C: addiu       $a1, $t1, 0x1
    ctx->r5 = ADD32(ctx->r9, 0X1);
    // 0x8004CE10: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // 0x8004CE14: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8004CE18: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
    // 0x8004CE1C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8004CE20: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x8004CE24: andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
    // 0x8004CE28: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x8004CE2C: or          $v1, $v1, $a3
    ctx->r3 = ctx->r3 | ctx->r7;
    // 0x8004CE30: sll         $a1, $a1, 24
    ctx->r5 = S32(ctx->r5 << 24);
    // 0x8004CE34: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x8004CE38: slti        $a1, $a1, 0x20
    ctx->r5 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // 0x8004CE3C: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
    // 0x8004CE40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CE44: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004CE48: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8004CE4C: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8004CE50: ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
    // 0x8004CE54: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x8004CE58: addiu       $v0, $a2, 0x10
    ctx->r2 = ADD32(ctx->r6, 0X10);
    // 0x8004CE5C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x8004CE60: andi        $a0, $a0, 0x3FF
    ctx->r4 = ctx->r4 & 0X3FF;
    // 0x8004CE64: sll         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4 << 14);
    // 0x8004CE68: ori         $a0, $a0, 0x208
    ctx->r4 = ctx->r4 | 0X208;
    // 0x8004CE6C: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x8004CE70: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CE74: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004CE78: sw          $v1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r3;
    // 0x8004CE7C: bne         $a1, $zero, L_8004CE00
    if (ctx->r5 != 0) {
        // 0x8004CE80: sw          $a0, 0xC($a2)
        MEM_W(0XC, ctx->r6) = ctx->r4;
            goto L_8004CE00;
    }
    // 0x8004CE80: sw          $a0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r4;
    // 0x8004CE84: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8004CE88: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x8004CE8C: lui         $t2, 0xF600
    ctx->r10 = S32(0XF600 << 16);
    // 0x8004CE90: ori         $t2, $t2, 0x348
    ctx->r10 = ctx->r10 | 0X348;
L_8004CE94:
    // 0x8004CE94: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8004CE98: lw          $t0, 0x2FE4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2FE4);
    // 0x8004CE9C: sll         $a1, $t1, 24
    ctx->r5 = S32(ctx->r9 << 24);
    // 0x8004CEA0: addiu       $a3, $t1, 0x1
    ctx->r7 = ADD32(ctx->r9, 0X1);
    // 0x8004CEA4: addu        $t1, $a3, $zero
    ctx->r9 = ADD32(ctx->r7, 0);
    // 0x8004CEA8: sra         $a1, $a1, 24
    ctx->r5 = S32(SIGNED(ctx->r5) >> 24);
    // 0x8004CEAC: sll         $a2, $a1, 3
    ctx->r6 = S32(ctx->r5 << 3);
    // 0x8004CEB0: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x8004CEB4: sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4 << 16);
    // 0x8004CEB8: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x8004CEBC: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    // 0x8004CEC0: andi        $a1, $a1, 0x3FF
    ctx->r5 = ctx->r5 & 0X3FF;
    // 0x8004CEC4: sll         $a1, $a1, 14
    ctx->r5 = S32(ctx->r5 << 14);
    // 0x8004CEC8: or          $a1, $a1, $t2
    ctx->r5 = ctx->r5 | ctx->r10;
    // 0x8004CECC: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    // 0x8004CED0: andi        $a2, $a2, 0x3FF
    ctx->r6 = ctx->r6 & 0X3FF;
    // 0x8004CED4: sll         $a2, $a2, 14
    ctx->r6 = S32(ctx->r6 << 14);
    // 0x8004CED8: ori         $a2, $a2, 0x2A8
    ctx->r6 = ctx->r6 | 0X2A8;
    // 0x8004CEDC: sll         $a3, $a3, 24
    ctx->r7 = S32(ctx->r7 << 24);
    // 0x8004CEE0: sra         $a3, $a3, 24
    ctx->r7 = S32(SIGNED(ctx->r7) >> 24);
    // 0x8004CEE4: slti        $a3, $a3, 0x20
    ctx->r7 = SIGNED(ctx->r7) < 0X20 ? 1 : 0;
    // 0x8004CEE8: addiu       $v0, $t0, 0x8
    ctx->r2 = ADD32(ctx->r8, 0X8);
    // 0x8004CEEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CEF0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004CEF4: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
    // 0x8004CEF8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8004CEFC: sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4 << 8);
    // 0x8004CF00: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8004CF04: ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
    // 0x8004CF08: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x8004CF0C: addiu       $v0, $t0, 0x10
    ctx->r2 = ADD32(ctx->r8, 0X10);
    // 0x8004CF10: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8004CF14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004CF18: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004CF1C: sw          $a1, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r5;
    // 0x8004CF20: bne         $a3, $zero, L_8004CE94
    if (ctx->r7 != 0) {
        // 0x8004CF24: sw          $a2, 0xC($t0)
        MEM_W(0XC, ctx->r8) = ctx->r6;
            goto L_8004CE94;
    }
    // 0x8004CF24: sw          $a2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r6;
    // 0x8004CF28: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004CF2C: addiu       $a0, $a0, -0x1D1C
    ctx->r4 = ADD32(ctx->r4, -0X1D1C);
    // 0x8004CF30: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    // 0x8004CF34: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x8004CF38: jal         0x8004DAB8
    // 0x8004CF3C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_0;
    // 0x8004CF3C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x8004CF40: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004CF44: addiu       $a0, $a0, -0x1854
    ctx->r4 = ADD32(ctx->r4, -0X1854);
    // 0x8004CF48: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8004CF4C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x8004CF50: jal         0x8004DAB8
    // 0x8004CF54: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_1;
    // 0x8004CF54: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
    // 0x8004CF58: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004CF5C: addiu       $a0, $a0, -0x1804
    ctx->r4 = ADD32(ctx->r4, -0X1804);
    // 0x8004CF60: addiu       $a1, $zero, 0x120
    ctx->r5 = ADD32(0, 0X120);
    // 0x8004CF64: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x8004CF68: jal         0x8004DAB8
    // 0x8004CF6C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_2;
    // 0x8004CF6C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // 0x8004CF70: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004CF74: addiu       $a0, $a0, -0x1800
    ctx->r4 = ADD32(ctx->r4, -0X1800);
    // 0x8004CF78: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8004CF7C: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x8004CF80: jal         0x8004DAB8
    // 0x8004CF84: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_3;
    // 0x8004CF84: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_3:
    // 0x8004CF88: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004CF8C: addiu       $a0, $a0, -0x17FC
    ctx->r4 = ADD32(ctx->r4, -0X17FC);
    // 0x8004CF90: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8004CF94: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    // 0x8004CF98: jal         0x8004DAB8
    // 0x8004CF9C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_4;
    // 0x8004CF9C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_4:
    // 0x8004CFA0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004CFA4: addiu       $a0, $a0, -0x17F8
    ctx->r4 = ADD32(ctx->r4, -0X17F8);
    // 0x8004CFA8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8004CFAC: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x8004CFB0: jal         0x8004DAB8
    // 0x8004CFB4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_5;
    // 0x8004CFB4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_5:
    // 0x8004CFB8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004CFBC: addiu       $a0, $a0, -0x17F4
    ctx->r4 = ADD32(ctx->r4, -0X17F4);
    // 0x8004CFC0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8004CFC4: addiu       $a2, $zero, 0xBE
    ctx->r6 = ADD32(0, 0XBE);
    // 0x8004CFC8: jal         0x8004DAB8
    // 0x8004CFCC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_6;
    // 0x8004CFCC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_6:
    // 0x8004CFD0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004CFD4: addiu       $a0, $a0, -0x1C98
    ctx->r4 = ADD32(ctx->r4, -0X1C98);
    // 0x8004CFD8: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x8004CFDC: addiu       $a2, $zero, 0xD2
    ctx->r6 = ADD32(0, 0XD2);
    // 0x8004CFE0: jal         0x8004DAB8
    // 0x8004CFE4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_7;
    // 0x8004CFE4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_7:
    // 0x8004CFE8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8004CFEC: jr          $ra
    // 0x8004CFF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8004CFF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8004CFF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CFF4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004CFF8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004CFFC: addiu       $a0, $a0, 0x5583
    ctx->r4 = ADD32(ctx->r4, 0X5583);
    // 0x8004D000: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8004D004: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8004D008: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8004D00C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004D010: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004D014: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8004D018: bne         $v0, $zero, L_8004D050
    if (ctx->r2 != 0) {
        // 0x8004D01C: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8004D050;
    }
    // 0x8004D01C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004D020: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8004D024: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D028: sb          $zero, 0x18B0($at)
    MEM_B(0X18B0, ctx->r1) = 0;
    // 0x8004D02C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D030: sb          $zero, 0x18B2($at)
    MEM_B(0X18B2, ctx->r1) = 0;
    // 0x8004D034: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D038: sb          $zero, 0x18B1($at)
    MEM_B(0X18B1, ctx->r1) = 0;
    // 0x8004D03C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x8004D040: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004D044: sw          $zero, 0x4AE4($at)
    MEM_W(0X4AE4, ctx->r1) = 0;
    // 0x8004D048: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004D04C: sw          $zero, 0x4AE0($at)
    MEM_W(0X4AE0, ctx->r1) = 0;
L_8004D050:
    // 0x8004D050: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004D054: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x8004D058: andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // 0x8004D05C: beq         $v0, $zero, L_8004D08C
    if (ctx->r2 == 0) {
        // 0x8004D060: nop
    
            goto L_8004D08C;
    }
    // 0x8004D060: nop

    // 0x8004D064: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004D068: lbu         $v0, 0x18B0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X18B0);
    // 0x8004D06C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8004D070: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D074: sb          $v0, 0x18B0($at)
    MEM_B(0X18B0, ctx->r1) = ctx->r2;
    // 0x8004D078: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004D07C: bgez        $v0, L_8004D08C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004D080: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004D08C;
    }
    // 0x8004D080: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004D084: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D088: sb          $v0, 0x18B0($at)
    MEM_B(0X18B0, ctx->r1) = ctx->r2;
L_8004D08C:
    // 0x8004D08C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004D090: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x8004D094: andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // 0x8004D098: beq         $v0, $zero, L_8004D0D0
    if (ctx->r2 == 0) {
        // 0x8004D09C: nop
    
            goto L_8004D0D0;
    }
    // 0x8004D09C: nop

    // 0x8004D0A0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004D0A4: lbu         $v0, 0x18B0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X18B0);
    // 0x8004D0A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004D0AC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D0B0: sb          $v0, 0x18B0($at)
    MEM_B(0X18B0, ctx->r1) = ctx->r2;
    // 0x8004D0B4: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004D0B8: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004D0BC: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8004D0C0: bne         $v0, $zero, L_8004D0D0
    if (ctx->r2 != 0) {
        // 0x8004D0C4: nop
    
            goto L_8004D0D0;
    }
    // 0x8004D0C4: nop

    // 0x8004D0C8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D0CC: sb          $zero, 0x18B0($at)
    MEM_B(0X18B0, ctx->r1) = 0;
L_8004D0D0:
    // 0x8004D0D0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004D0D4: lb          $v0, 0x18B0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X18B0);
    // 0x8004D0D8: bne         $v0, $zero, L_8004D248
    if (ctx->r2 != 0) {
        // 0x8004D0DC: nop
    
            goto L_8004D248;
    }
    // 0x8004D0DC: nop

    // 0x8004D0E0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8004D0E4: lhu         $v0, -0x38A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X38A0);
    // 0x8004D0E8: andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // 0x8004D0EC: beq         $v0, $zero, L_8004D140
    if (ctx->r2 == 0) {
        // 0x8004D0F0: nop
    
            goto L_8004D140;
    }
    // 0x8004D0F0: nop

    // 0x8004D0F4: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8004D0F8: lw          $v1, 0x4AE0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4AE0);
    // 0x8004D0FC: slti        $v0, $v1, 0x1E
    ctx->r2 = SIGNED(ctx->r3) < 0X1E ? 1 : 0;
    // 0x8004D100: beq         $v0, $zero, L_8004D114
    if (ctx->r2 == 0) {
        // 0x8004D104: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8004D114;
    }
    // 0x8004D104: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8004D108: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004D10C: j           L_8004D148
    // 0x8004D110: sw          $v0, 0x4AE0($at)
    MEM_W(0X4AE0, ctx->r1) = ctx->r2;
        goto L_8004D148;
    // 0x8004D110: sw          $v0, 0x4AE0($at)
    MEM_W(0X4AE0, ctx->r1) = ctx->r2;
L_8004D114:
    // 0x8004D114: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004D118: lbu         $v0, 0x18B1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X18B1);
    // 0x8004D11C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8004D120: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D124: sb          $v0, 0x18B1($at)
    MEM_B(0X18B1, ctx->r1) = ctx->r2;
    // 0x8004D128: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004D12C: bgez        $v0, L_8004D148
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004D130: addiu       $v0, $zero, 0x1F
        ctx->r2 = ADD32(0, 0X1F);
            goto L_8004D148;
    }
    // 0x8004D130: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    // 0x8004D134: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D138: j           L_8004D148
    // 0x8004D13C: sb          $v0, 0x18B1($at)
    MEM_B(0X18B1, ctx->r1) = ctx->r2;
        goto L_8004D148;
    // 0x8004D13C: sb          $v0, 0x18B1($at)
    MEM_B(0X18B1, ctx->r1) = ctx->r2;
L_8004D140:
    // 0x8004D140: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004D144: sw          $zero, 0x4AE0($at)
    MEM_W(0X4AE0, ctx->r1) = 0;
L_8004D148:
    // 0x8004D148: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004D14C: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x8004D150: andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // 0x8004D154: beq         $v0, $zero, L_8004D18C
    if (ctx->r2 == 0) {
        // 0x8004D158: nop
    
            goto L_8004D18C;
    }
    // 0x8004D158: nop

    // 0x8004D15C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004D160: lbu         $v0, 0x18B1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X18B1);
    // 0x8004D164: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8004D168: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D16C: sb          $v0, 0x18B1($at)
    MEM_B(0X18B1, ctx->r1) = ctx->r2;
    // 0x8004D170: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004D174: bgez        $v0, L_8004D184
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004D178: addiu       $v0, $zero, 0x1F
        ctx->r2 = ADD32(0, 0X1F);
            goto L_8004D184;
    }
    // 0x8004D178: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    // 0x8004D17C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D180: sb          $v0, 0x18B1($at)
    MEM_B(0X18B1, ctx->r1) = ctx->r2;
L_8004D184:
    // 0x8004D184: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004D188: sw          $zero, 0x4AE0($at)
    MEM_W(0X4AE0, ctx->r1) = 0;
L_8004D18C:
    // 0x8004D18C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8004D190: lhu         $v0, -0x38A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X38A0);
    // 0x8004D194: andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // 0x8004D198: beq         $v0, $zero, L_8004D1F4
    if (ctx->r2 == 0) {
        // 0x8004D19C: nop
    
            goto L_8004D1F4;
    }
    // 0x8004D19C: nop

    // 0x8004D1A0: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8004D1A4: lw          $v1, 0x4AE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4AE4);
    // 0x8004D1A8: slti        $v0, $v1, 0x1E
    ctx->r2 = SIGNED(ctx->r3) < 0X1E ? 1 : 0;
    // 0x8004D1AC: beq         $v0, $zero, L_8004D1C0
    if (ctx->r2 == 0) {
        // 0x8004D1B0: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8004D1C0;
    }
    // 0x8004D1B0: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8004D1B4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004D1B8: j           L_8004D1FC
    // 0x8004D1BC: sw          $v0, 0x4AE4($at)
    MEM_W(0X4AE4, ctx->r1) = ctx->r2;
        goto L_8004D1FC;
    // 0x8004D1BC: sw          $v0, 0x4AE4($at)
    MEM_W(0X4AE4, ctx->r1) = ctx->r2;
L_8004D1C0:
    // 0x8004D1C0: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004D1C4: lbu         $v0, 0x18B1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X18B1);
    // 0x8004D1C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004D1CC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D1D0: sb          $v0, 0x18B1($at)
    MEM_B(0X18B1, ctx->r1) = ctx->r2;
    // 0x8004D1D4: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004D1D8: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004D1DC: slti        $v0, $v0, 0x20
    ctx->r2 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x8004D1E0: bne         $v0, $zero, L_8004D1FC
    if (ctx->r2 != 0) {
        // 0x8004D1E4: nop
    
            goto L_8004D1FC;
    }
    // 0x8004D1E4: nop

    // 0x8004D1E8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D1EC: j           L_8004D1FC
    // 0x8004D1F0: sb          $zero, 0x18B1($at)
    MEM_B(0X18B1, ctx->r1) = 0;
        goto L_8004D1FC;
    // 0x8004D1F0: sb          $zero, 0x18B1($at)
    MEM_B(0X18B1, ctx->r1) = 0;
L_8004D1F4:
    // 0x8004D1F4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004D1F8: sw          $zero, 0x4AE4($at)
    MEM_W(0X4AE4, ctx->r1) = 0;
L_8004D1FC:
    // 0x8004D1FC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004D200: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x8004D204: andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // 0x8004D208: beq         $v0, $zero, L_8004D248
    if (ctx->r2 == 0) {
        // 0x8004D20C: nop
    
            goto L_8004D248;
    }
    // 0x8004D20C: nop

    // 0x8004D210: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004D214: lbu         $v0, 0x18B1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X18B1);
    // 0x8004D218: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004D21C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D220: sb          $v0, 0x18B1($at)
    MEM_B(0X18B1, ctx->r1) = ctx->r2;
    // 0x8004D224: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004D228: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004D22C: slti        $v0, $v0, 0x20
    ctx->r2 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x8004D230: bne         $v0, $zero, L_8004D240
    if (ctx->r2 != 0) {
        // 0x8004D234: nop
    
            goto L_8004D240;
    }
    // 0x8004D234: nop

    // 0x8004D238: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D23C: sb          $zero, 0x18B1($at)
    MEM_B(0X18B1, ctx->r1) = 0;
L_8004D240:
    // 0x8004D240: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004D244: sw          $zero, 0x4AE4($at)
    MEM_W(0X4AE4, ctx->r1) = 0;
L_8004D248:
    // 0x8004D248: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004D24C: lb          $v1, 0x18B0($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X18B0);
    // 0x8004D250: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004D254: bne         $v1, $v0, L_8004D3BC
    if (ctx->r3 != ctx->r2) {
        // 0x8004D258: nop
    
            goto L_8004D3BC;
    }
    // 0x8004D258: nop

    // 0x8004D25C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8004D260: lhu         $v0, -0x38A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X38A0);
    // 0x8004D264: andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // 0x8004D268: beq         $v0, $zero, L_8004D2BC
    if (ctx->r2 == 0) {
        // 0x8004D26C: nop
    
            goto L_8004D2BC;
    }
    // 0x8004D26C: nop

    // 0x8004D270: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8004D274: lw          $v1, 0x4AE0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4AE0);
    // 0x8004D278: slti        $v0, $v1, 0x1E
    ctx->r2 = SIGNED(ctx->r3) < 0X1E ? 1 : 0;
    // 0x8004D27C: beq         $v0, $zero, L_8004D290
    if (ctx->r2 == 0) {
        // 0x8004D280: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8004D290;
    }
    // 0x8004D280: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8004D284: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004D288: j           L_8004D2C4
    // 0x8004D28C: sw          $v0, 0x4AE0($at)
    MEM_W(0X4AE0, ctx->r1) = ctx->r2;
        goto L_8004D2C4;
    // 0x8004D28C: sw          $v0, 0x4AE0($at)
    MEM_W(0X4AE0, ctx->r1) = ctx->r2;
L_8004D290:
    // 0x8004D290: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004D294: lbu         $v0, 0x18B2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X18B2);
    // 0x8004D298: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8004D29C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D2A0: sb          $v0, 0x18B2($at)
    MEM_B(0X18B2, ctx->r1) = ctx->r2;
    // 0x8004D2A4: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004D2A8: bgez        $v0, L_8004D2C4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004D2AC: addiu       $v0, $zero, 0x4F
        ctx->r2 = ADD32(0, 0X4F);
            goto L_8004D2C4;
    }
    // 0x8004D2AC: addiu       $v0, $zero, 0x4F
    ctx->r2 = ADD32(0, 0X4F);
    // 0x8004D2B0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D2B4: j           L_8004D2C4
    // 0x8004D2B8: sb          $v0, 0x18B2($at)
    MEM_B(0X18B2, ctx->r1) = ctx->r2;
        goto L_8004D2C4;
    // 0x8004D2B8: sb          $v0, 0x18B2($at)
    MEM_B(0X18B2, ctx->r1) = ctx->r2;
L_8004D2BC:
    // 0x8004D2BC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004D2C0: sw          $zero, 0x4AE0($at)
    MEM_W(0X4AE0, ctx->r1) = 0;
L_8004D2C4:
    // 0x8004D2C4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004D2C8: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x8004D2CC: andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // 0x8004D2D0: beq         $v0, $zero, L_8004D308
    if (ctx->r2 == 0) {
        // 0x8004D2D4: nop
    
            goto L_8004D308;
    }
    // 0x8004D2D4: nop

    // 0x8004D2D8: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004D2DC: lbu         $v0, 0x18B2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X18B2);
    // 0x8004D2E0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8004D2E4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D2E8: sb          $v0, 0x18B2($at)
    MEM_B(0X18B2, ctx->r1) = ctx->r2;
    // 0x8004D2EC: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004D2F0: bgez        $v0, L_8004D300
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004D2F4: addiu       $v0, $zero, 0x4F
        ctx->r2 = ADD32(0, 0X4F);
            goto L_8004D300;
    }
    // 0x8004D2F4: addiu       $v0, $zero, 0x4F
    ctx->r2 = ADD32(0, 0X4F);
    // 0x8004D2F8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D2FC: sb          $v0, 0x18B2($at)
    MEM_B(0X18B2, ctx->r1) = ctx->r2;
L_8004D300:
    // 0x8004D300: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004D304: sw          $zero, 0x4AE0($at)
    MEM_W(0X4AE0, ctx->r1) = 0;
L_8004D308:
    // 0x8004D308: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8004D30C: lhu         $v0, -0x38A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X38A0);
    // 0x8004D310: andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // 0x8004D314: beq         $v0, $zero, L_8004D368
    if (ctx->r2 == 0) {
        // 0x8004D318: nop
    
            goto L_8004D368;
    }
    // 0x8004D318: nop

    // 0x8004D31C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8004D320: lw          $v1, 0x4AE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4AE4);
    // 0x8004D324: slti        $v0, $v1, 0x1E
    ctx->r2 = SIGNED(ctx->r3) < 0X1E ? 1 : 0;
    // 0x8004D328: beq         $v0, $zero, L_8004D33C
    if (ctx->r2 == 0) {
        // 0x8004D32C: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8004D33C;
    }
    // 0x8004D32C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8004D330: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004D334: j           L_8004D370
    // 0x8004D338: sw          $v0, 0x4AE4($at)
    MEM_W(0X4AE4, ctx->r1) = ctx->r2;
        goto L_8004D370;
    // 0x8004D338: sw          $v0, 0x4AE4($at)
    MEM_W(0X4AE4, ctx->r1) = ctx->r2;
L_8004D33C:
    // 0x8004D33C: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004D340: lbu         $v0, 0x18B2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X18B2);
    // 0x8004D344: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8004D348: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D34C: sb          $v0, 0x18B2($at)
    MEM_B(0X18B2, ctx->r1) = ctx->r2;
    // 0x8004D350: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004D354: bgez        $v0, L_8004D370
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004D358: addiu       $v0, $zero, 0x4F
        ctx->r2 = ADD32(0, 0X4F);
            goto L_8004D370;
    }
    // 0x8004D358: addiu       $v0, $zero, 0x4F
    ctx->r2 = ADD32(0, 0X4F);
    // 0x8004D35C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D360: j           L_8004D370
    // 0x8004D364: sb          $v0, 0x18B2($at)
    MEM_B(0X18B2, ctx->r1) = ctx->r2;
        goto L_8004D370;
    // 0x8004D364: sb          $v0, 0x18B2($at)
    MEM_B(0X18B2, ctx->r1) = ctx->r2;
L_8004D368:
    // 0x8004D368: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004D36C: sw          $zero, 0x4AE4($at)
    MEM_W(0X4AE4, ctx->r1) = 0;
L_8004D370:
    // 0x8004D370: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004D374: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x8004D378: andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // 0x8004D37C: beq         $v0, $zero, L_8004D3BC
    if (ctx->r2 == 0) {
        // 0x8004D380: nop
    
            goto L_8004D3BC;
    }
    // 0x8004D380: nop

    // 0x8004D384: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004D388: lbu         $v0, 0x18B2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X18B2);
    // 0x8004D38C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004D390: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D394: sb          $v0, 0x18B2($at)
    MEM_B(0X18B2, ctx->r1) = ctx->r2;
    // 0x8004D398: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004D39C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004D3A0: slti        $v0, $v0, 0x50
    ctx->r2 = SIGNED(ctx->r2) < 0X50 ? 1 : 0;
    // 0x8004D3A4: bne         $v0, $zero, L_8004D3B4
    if (ctx->r2 != 0) {
        // 0x8004D3A8: nop
    
            goto L_8004D3B4;
    }
    // 0x8004D3A8: nop

    // 0x8004D3AC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D3B0: sb          $zero, 0x18B2($at)
    MEM_B(0X18B2, ctx->r1) = 0;
L_8004D3B4:
    // 0x8004D3B4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8004D3B8: sw          $zero, 0x4AE4($at)
    MEM_W(0X4AE4, ctx->r1) = 0;
L_8004D3BC:
    // 0x8004D3BC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004D3C0: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x8004D3C4: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x8004D3C8: beq         $v0, $zero, L_8004D410
    if (ctx->r2 == 0) {
        // 0x8004D3CC: nop
    
            goto L_8004D410;
    }
    // 0x8004D3CC: nop

    // 0x8004D3D0: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004D3D4: lb          $v1, 0x18B0($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X18B0);
    // 0x8004D3D8: beq         $v1, $zero, L_8004D3F0
    if (ctx->r3 == 0) {
        // 0x8004D3DC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004D3F0;
    }
    // 0x8004D3DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004D3E0: beq         $v1, $v0, L_8004D404
    if (ctx->r3 == ctx->r2) {
        // 0x8004D3E4: nop
    
            goto L_8004D404;
    }
    // 0x8004D3E4: nop

    // 0x8004D3E8: j           L_8004D410
    // 0x8004D3EC: nop

        goto L_8004D410;
    // 0x8004D3EC: nop

L_8004D3F0:
    // 0x8004D3F0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004D3F4: jal         0x800067C8
    // 0x8004D3F8: lb          $a0, 0x18B1($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X18B1);
    func_800067C8(rdram, ctx);
        goto after_0;
    // 0x8004D3F8: lb          $a0, 0x18B1($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X18B1);
    after_0:
    // 0x8004D3FC: j           L_8004D410
    // 0x8004D400: nop

        goto L_8004D410;
    // 0x8004D400: nop

L_8004D404:
    // 0x8004D404: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004D408: jal         0x800064C0
    // 0x8004D40C: lb          $a0, 0x18B2($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X18B2);
    func_800064C0(rdram, ctx);
        goto after_1;
    // 0x8004D40C: lb          $a0, 0x18B2($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X18B2);
    after_1:
L_8004D410:
    // 0x8004D410: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004D414: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x8004D418: andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // 0x8004D41C: beq         $v0, $zero, L_8004D434
    if (ctx->r2 == 0) {
        // 0x8004D420: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8004D434;
    }
    // 0x8004D420: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004D424: jal         0x80006944
    // 0x8004D428: nop

    func_80006944(rdram, ctx);
        goto after_2;
    // 0x8004D428: nop

    after_2:
    // 0x8004D42C: jal         0x80006708
    // 0x8004D430: nop

    func_80006708(rdram, ctx);
        goto after_3;
    // 0x8004D430: nop

    after_3:
L_8004D434:
    // 0x8004D434: lui         $s3, 0x8009
    ctx->r19 = S32(0X8009 << 16);
    // 0x8004D438: addiu       $s3, $s3, 0x1104
    ctx->r19 = ADD32(ctx->r19, 0X1104);
    // 0x8004D43C: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x8004D440: addiu       $s1, $s1, 0x1890
    ctx->r17 = ADD32(ctx->r17, 0X1890);
    // 0x8004D444: addiu       $s2, $s1, 0x2
    ctx->r18 = ADD32(ctx->r17, 0X2);
    // 0x8004D448: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_8004D44C:
    // 0x8004D44C: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8004D450: addu        $v1, $v0, $s3
    ctx->r3 = ADD32(ctx->r2, ctx->r19);
    // 0x8004D454: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8004D458: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
    // 0x8004D45C: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x8004D460: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8004D464: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8004D468: jal         0x8004DAB8
    // 0x8004D46C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_4;
    // 0x8004D46C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_4:
    // 0x8004D470: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x8004D474: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8004D478: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004D47C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004D480: slti        $v0, $v0, 0x8
    ctx->r2 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8004D484: bne         $v0, $zero, L_8004D44C
    if (ctx->r2 != 0) {
        // 0x8004D488: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_8004D44C;
    }
    // 0x8004D488: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
    // 0x8004D48C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8004D490: addiu       $s0, $s0, 0x7458
    ctx->r16 = ADD32(ctx->r16, 0X7458);
    // 0x8004D494: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004D498: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8004D49C: lb          $a2, 0x18B1($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X18B1);
    // 0x8004D4A0: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x8004D4A4: addiu       $s1, $s1, -0x17F0
    ctx->r17 = ADD32(ctx->r17, -0X17F0);
    // 0x8004D4A8: jal         0x80066CA0
    // 0x8004D4AC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80066CA0(rdram, ctx);
        goto after_5;
    // 0x8004D4AC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_5:
    // 0x8004D4B0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004D4B4: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    // 0x8004D4B8: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x8004D4BC: jal         0x8004DAB8
    // 0x8004D4C0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_6;
    // 0x8004D4C0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_6:
    // 0x8004D4C4: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8004D4C8: lb          $a2, 0x18B2($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X18B2);
    // 0x8004D4CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004D4D0: jal         0x80066CA0
    // 0x8004D4D4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80066CA0(rdram, ctx);
        goto after_7;
    // 0x8004D4D4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_7:
    // 0x8004D4D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8004D4DC: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    // 0x8004D4E0: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x8004D4E4: jal         0x8004DAB8
    // 0x8004D4E8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_8;
    // 0x8004D4E8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_8:
    // 0x8004D4EC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004D4F0: addiu       $a0, $a0, -0x1874
    ctx->r4 = ADD32(ctx->r4, -0X1874);
    // 0x8004D4F4: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004D4F8: lb          $v0, 0x18B0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X18B0);
    // 0x8004D4FC: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    // 0x8004D500: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8004D504: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x8004D508: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8004D50C: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8004D510: jal         0x8004DAB8
    // 0x8004D514: addiu       $a2, $a2, 0x3C
    ctx->r6 = ADD32(ctx->r6, 0X3C);
    func_8004DAB8(rdram, ctx);
        goto after_9;
    // 0x8004D514: addiu       $a2, $a2, 0x3C
    ctx->r6 = ADD32(ctx->r6, 0X3C);
    after_9:
    // 0x8004D518: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8004D51C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8004D520: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8004D524: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004D528: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004D52C: jr          $ra
    // 0x8004D530: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8004D530: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8004D534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D534: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8004D538: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8004D53C: lui         $s6, 0x600
    ctx->r22 = S32(0X600 << 16);
    // 0x8004D540: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8004D544: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8004D548: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8004D54C: lui         $s5, 0x801D
    ctx->r21 = S32(0X801D << 16);
    // 0x8004D550: addiu       $s5, $s5, 0x7B4C
    ctx->r21 = ADD32(ctx->r21, 0X7B4C);
    // 0x8004D554: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8004D558: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x8004D55C: addiu       $s2, $s2, 0x5582
    ctx->r18 = ADD32(ctx->r18, 0X5582);
    // 0x8004D560: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8004D564: ori         $s4, $zero, 0x9000
    ctx->r20 = 0 | 0X9000;
    // 0x8004D568: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8004D56C: lui         $fp, 0x8009
    ctx->r30 = S32(0X8009 << 16);
    // 0x8004D570: addiu       $fp, $fp, 0x10F0
    ctx->r30 = ADD32(ctx->r30, 0X10F0);
    // 0x8004D574: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8004D578: lui         $s7, 0x8009
    ctx->r23 = S32(0X8009 << 16);
    // 0x8004D57C: addiu       $s7, $s7, 0x12E8
    ctx->r23 = ADD32(ctx->r23, 0X12E8);
    // 0x8004D580: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8004D584: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8004D588: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
L_8004D58C:
    // 0x8004D58C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004D590: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8004D594: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8004D598: addiu       $v0, $v0, -0x6850
    ctx->r2 = ADD32(ctx->r2, -0X6850);
    // 0x8004D59C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8004D5A0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8004D5A4: addiu       $v0, $v0, -0x6858
    ctx->r2 = ADD32(ctx->r2, -0X6858);
    // 0x8004D5A8: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8004D5AC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8004D5B0: addiu       $v0, $v0, 0x54E0
    ctx->r2 = ADD32(ctx->r2, 0X54E0);
    // 0x8004D5B4: sw          $s6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r22;
    // 0x8004D5B8: sw          $s6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r22;
    // 0x8004D5BC: sw          $s6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r22;
    // 0x8004D5C0: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x8004D5C4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004D5C8: lb          $a0, 0x5582($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X5582);
    // 0x8004D5CC: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8004D5D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004D5D4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004D5D8: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8004D5DC: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x8004D5E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004D5E4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004D5E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004D5EC: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004D5F0: sltiu       $v0, $a0, 0xB
    ctx->r2 = ctx->r4 < 0XB ? 1 : 0;
    // 0x8004D5F4: beq         $v0, $zero, L_8004D918
    if (ctx->r2 == 0) {
        // 0x8004D5F8: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_8004D918;
    }
    // 0x8004D5F8: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8004D5FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004D600: addu        $at, $at, $v0
    gpr jr_addend_8004D608 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004D604: lw          $v0, -0x17E8($at)
    ctx->r2 = ADD32(ctx->r1, -0X17E8);
    // 0x8004D608: jr          $v0
    // 0x8004D60C: nop

    switch (jr_addend_8004D608 >> 2) {
        case 0: goto L_8004D610; break;
        case 1: goto L_8004D6E4; break;
        case 2: goto L_8004D788; break;
        case 3: goto L_8004D798; break;
        case 4: goto L_8004D7D0; break;
        case 5: goto L_8004D804; break;
        case 6: goto L_8004D814; break;
        case 7: goto L_8004D824; break;
        case 8: goto L_8004D894; break;
        case 9: goto L_8004D8A4; break;
        case 10: goto L_8004D8B4; break;
        default: switch_error(__func__, 0x8004D608, 0x800AE818);
    }
    // 0x8004D60C: nop

L_8004D610:
    // 0x8004D610: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004D614: sb          $s3, 0x2075($at)
    MEM_B(0X2075, ctx->r1) = ctx->r19;
    // 0x8004D618: sb          $s3, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r19;
    // 0x8004D61C: sb          $zero, -0xA($s5)
    MEM_B(-0XA, ctx->r21) = 0;
    // 0x8004D620: sb          $zero, -0xE($s5)
    MEM_B(-0XE, ctx->r21) = 0;
    // 0x8004D624: sb          $zero, -0x10($s5)
    MEM_B(-0X10, ctx->r21) = 0;
    // 0x8004D628: sb          $zero, -0x12($s5)
    MEM_B(-0X12, ctx->r21) = 0;
    // 0x8004D62C: sb          $zero, -0x14($s5)
    MEM_B(-0X14, ctx->r21) = 0;
    // 0x8004D630: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D634: sb          $zero, 0x10A3($at)
    MEM_B(0X10A3, ctx->r1) = 0;
    // 0x8004D638: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004D63C: jal         0x80051A08
    // 0x8004D640: sb          $zero, 0x5583($at)
    MEM_B(0X5583, ctx->r1) = 0;
    func_80051A08(rdram, ctx);
        goto after_0;
    // 0x8004D640: sb          $zero, 0x5583($at)
    MEM_B(0X5583, ctx->r1) = 0;
    after_0:
    // 0x8004D644: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8004D648: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_8004D64C:
    // 0x8004D64C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8004D650: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004D654: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004D658: lbu         $a0, 0xB60($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XB60);
    // 0x8004D65C: addiu       $v1, $a1, 0x1
    ctx->r3 = ADD32(ctx->r5, 0X1);
    // 0x8004D660: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x8004D664: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8004D668: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8004D66C: slti        $v1, $v1, 0x4
    ctx->r3 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8004D670: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004D674: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004D678: sb          $a0, -0x2AEC($at)
    MEM_B(-0X2AEC, ctx->r1) = ctx->r4;
    // 0x8004D67C: bne         $v1, $zero, L_8004D64C
    if (ctx->r3 != 0) {
        // 0x8004D680: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_8004D64C;
    }
    // 0x8004D680: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x8004D684: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8004D688: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
L_8004D68C:
    // 0x8004D68C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8004D690: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004D694: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004D698: lbu         $a0, 0xB7A($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XB7A);
    // 0x8004D69C: addiu       $v1, $a1, 0x1
    ctx->r3 = ADD32(ctx->r5, 0X1);
    // 0x8004D6A0: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x8004D6A4: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8004D6A8: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8004D6AC: slti        $v1, $v1, 0x6
    ctx->r3 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x8004D6B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004D6B4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004D6B8: sb          $a0, 0x2738($at)
    MEM_B(0X2738, ctx->r1) = ctx->r4;
    // 0x8004D6BC: bne         $v1, $zero, L_8004D68C
    if (ctx->r3 != 0) {
        // 0x8004D6C0: sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5 << 16);
            goto L_8004D68C;
    }
    // 0x8004D6C0: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x8004D6C4: jal         0x80006944
    // 0x8004D6C8: nop

    func_80006944(rdram, ctx);
        goto after_1;
    // 0x8004D6C8: nop

    after_1:
    // 0x8004D6CC: jal         0x80006708
    // 0x8004D6D0: nop

    func_80006708(rdram, ctx);
        goto after_2;
    // 0x8004D6D0: nop

    after_2:
    // 0x8004D6D4: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8004D6D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004D6DC: j           L_8004D918
    // 0x8004D6E0: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
        goto L_8004D918;
    // 0x8004D6E0: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_8004D6E4:
    // 0x8004D6E4: jal         0x8004ADF0
    // 0x8004D6E8: nop

    func_8004ADF0(rdram, ctx);
        goto after_3;
    // 0x8004D6E8: nop

    after_3:
    // 0x8004D6EC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004D6F0: lhu         $v1, -0x33C8($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X33C8);
    // 0x8004D6F4: andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // 0x8004D6F8: beq         $v0, $zero, L_8004D730
    if (ctx->r2 == 0) {
        // 0x8004D6FC: andi        $v0, $v1, 0x400
        ctx->r2 = ctx->r3 & 0X400;
            goto L_8004D730;
    }
    // 0x8004D6FC: andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // 0x8004D700: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004D704: lb          $v0, 0x10A3($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X10A3);
    // 0x8004D708: blez        $v0, L_8004D720
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004D70C: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8004D720;
    }
    // 0x8004D70C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004D710: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8004D714: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D718: j           L_8004D918
    // 0x8004D71C: sb          $v0, 0x10A3($at)
    MEM_B(0X10A3, ctx->r1) = ctx->r2;
        goto L_8004D918;
    // 0x8004D71C: sb          $v0, 0x10A3($at)
    MEM_B(0X10A3, ctx->r1) = ctx->r2;
L_8004D720:
    // 0x8004D720: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8004D724: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D728: j           L_8004D918
    // 0x8004D72C: sb          $v0, 0x10A3($at)
    MEM_B(0X10A3, ctx->r1) = ctx->r2;
        goto L_8004D918;
    // 0x8004D72C: sb          $v0, 0x10A3($at)
    MEM_B(0X10A3, ctx->r1) = ctx->r2;
L_8004D730:
    // 0x8004D730: beq         $v0, $zero, L_8004D768
    if (ctx->r2 == 0) {
        // 0x8004D734: andi        $v0, $v1, 0x8000
        ctx->r2 = ctx->r3 & 0X8000;
            goto L_8004D768;
    }
    // 0x8004D734: andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // 0x8004D738: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004D73C: lb          $v0, 0x10A3($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X10A3);
    // 0x8004D740: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004D744: slti        $v0, $v0, 0x8
    ctx->r2 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8004D748: beq         $v0, $zero, L_8004D75C
    if (ctx->r2 == 0) {
        // 0x8004D74C: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8004D75C;
    }
    // 0x8004D74C: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8004D750: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D754: j           L_8004D918
    // 0x8004D758: sb          $v0, 0x10A3($at)
    MEM_B(0X10A3, ctx->r1) = ctx->r2;
        goto L_8004D918;
    // 0x8004D758: sb          $v0, 0x10A3($at)
    MEM_B(0X10A3, ctx->r1) = ctx->r2;
L_8004D75C:
    // 0x8004D75C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004D760: j           L_8004D918
    // 0x8004D764: sb          $zero, 0x10A3($at)
    MEM_B(0X10A3, ctx->r1) = 0;
        goto L_8004D918;
    // 0x8004D764: sb          $zero, 0x10A3($at)
    MEM_B(0X10A3, ctx->r1) = 0;
L_8004D768:
    // 0x8004D768: beq         $v0, $zero, L_8004D918
    if (ctx->r2 == 0) {
        // 0x8004D76C: nop
    
            goto L_8004D918;
    }
    // 0x8004D76C: nop

    // 0x8004D770: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004D774: lbu         $v0, 0x10A3($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X10A3);
    // 0x8004D778: sb          $zero, 0x1($s2)
    MEM_B(0X1, ctx->r18) = 0;
    // 0x8004D77C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8004D780: j           L_8004D918
    // 0x8004D784: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
        goto L_8004D918;
    // 0x8004D784: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_8004D788:
    // 0x8004D788: jal         0x8004B394
    // 0x8004D78C: nop

    func_8004B394(rdram, ctx);
        goto after_4;
    // 0x8004D78C: nop

    after_4:
    // 0x8004D790: j           L_8004D874
    // 0x8004D794: nop

        goto L_8004D874;
    // 0x8004D794: nop

L_8004D798:
    // 0x8004D798: jal         0x8004B7B8
    // 0x8004D79C: nop

    func_8004B7B8(rdram, ctx);
        goto after_5;
    // 0x8004D79C: nop

    after_5:
    // 0x8004D7A0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8004D7A4: lhu         $v0, -0x38A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X38A0);
    // 0x8004D7A8: andi        $v0, $v0, 0x9000
    ctx->r2 = ctx->r2 & 0X9000;
    // 0x8004D7AC: bne         $v0, $s4, L_8004D918
    if (ctx->r2 != ctx->r20) {
        // 0x8004D7B0: nop
    
            goto L_8004D918;
    }
    // 0x8004D7B0: nop

    // 0x8004D7B4: sb          $s3, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r19;
    // 0x8004D7B8: sb          $zero, 0x1($s2)
    MEM_B(0X1, ctx->r18) = 0;
    // 0x8004D7BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004D7C0: sb          $zero, 0x7B43($at)
    MEM_B(0X7B43, ctx->r1) = 0;
    // 0x8004D7C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004D7C8: j           L_8004D918
    // 0x8004D7CC: sb          $zero, 0x7B42($at)
    MEM_B(0X7B42, ctx->r1) = 0;
        goto L_8004D918;
    // 0x8004D7CC: sb          $zero, 0x7B42($at)
    MEM_B(0X7B42, ctx->r1) = 0;
L_8004D7D0:
    // 0x8004D7D0: jal         0x8004CFF4
    // 0x8004D7D4: nop

    func_8004CFF4(rdram, ctx);
        goto after_6;
    // 0x8004D7D4: nop

    after_6:
    // 0x8004D7D8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8004D7DC: lhu         $v0, -0x38A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X38A0);
    // 0x8004D7E0: andi        $v0, $v0, 0x9000
    ctx->r2 = ctx->r2 & 0X9000;
    // 0x8004D7E4: bne         $v0, $s4, L_8004D918
    if (ctx->r2 != ctx->r20) {
        // 0x8004D7E8: nop
    
            goto L_8004D918;
    }
    // 0x8004D7E8: nop

    // 0x8004D7EC: jal         0x80006944
    // 0x8004D7F0: nop

    func_80006944(rdram, ctx);
        goto after_7;
    // 0x8004D7F0: nop

    after_7:
    // 0x8004D7F4: jal         0x80006708
    // 0x8004D7F8: nop

    func_80006708(rdram, ctx);
        goto after_8;
    // 0x8004D7F8: nop

    after_8:
    // 0x8004D7FC: j           L_8004D88C
    // 0x8004D800: sb          $s3, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r19;
        goto L_8004D88C;
    // 0x8004D800: sb          $s3, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r19;
L_8004D804:
    // 0x8004D804: jal         0x8004CC9C
    // 0x8004D808: nop

    func_8004CC9C(rdram, ctx);
        goto after_9;
    // 0x8004D808: nop

    after_9:
    // 0x8004D80C: j           L_8004D874
    // 0x8004D810: nop

        goto L_8004D874;
    // 0x8004D810: nop

L_8004D814:
    // 0x8004D814: jal         0x8004B8A8
    // 0x8004D818: nop

    func_8004B8A8(rdram, ctx);
        goto after_10;
    // 0x8004D818: nop

    after_10:
    // 0x8004D81C: j           L_8004D874
    // 0x8004D820: nop

        goto L_8004D874;
    // 0x8004D820: nop

L_8004D824:
    // 0x8004D824: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004D828: lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // 0x8004D82C: addiu       $s1, $s1, 0x12EA
    ctx->r17 = ADD32(ctx->r17, 0X12EA);
    // 0x8004D830: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_8004D834:
    // 0x8004D834: sra         $v0, $v0, 22
    ctx->r2 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8004D838: addu        $v1, $v0, $fp
    ctx->r3 = ADD32(ctx->r2, ctx->r30);
    // 0x8004D83C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8004D840: addu        $v1, $v0, $s7
    ctx->r3 = ADD32(ctx->r2, ctx->r23);
    // 0x8004D844: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8004D848: lh          $a1, 0x0($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X0);
    // 0x8004D84C: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8004D850: jal         0x8004DAB8
    // 0x8004D854: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_11;
    // 0x8004D854: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_11:
    // 0x8004D858: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x8004D85C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8004D860: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8004D864: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8004D868: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8004D86C: bne         $v0, $zero, L_8004D834
    if (ctx->r2 != 0) {
        // 0x8004D870: sll         $v0, $s0, 24
        ctx->r2 = S32(ctx->r16 << 24);
            goto L_8004D834;
    }
    // 0x8004D870: sll         $v0, $s0, 24
    ctx->r2 = S32(ctx->r16 << 24);
L_8004D874:
    // 0x8004D874: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8004D878: lhu         $v0, -0x38A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X38A0);
    // 0x8004D87C: andi        $v0, $v0, 0x9000
    ctx->r2 = ctx->r2 & 0X9000;
    // 0x8004D880: bne         $v0, $s4, L_8004D918
    if (ctx->r2 != ctx->r20) {
        // 0x8004D884: nop
    
            goto L_8004D918;
    }
    // 0x8004D884: nop

    // 0x8004D888: sb          $s3, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r19;
L_8004D88C:
    // 0x8004D88C: j           L_8004D918
    // 0x8004D890: sb          $zero, 0x1($s2)
    MEM_B(0X1, ctx->r18) = 0;
        goto L_8004D918;
    // 0x8004D890: sb          $zero, 0x1($s2)
    MEM_B(0X1, ctx->r18) = 0;
L_8004D894:
    // 0x8004D894: jal         0x8004BD00
    // 0x8004D898: nop

    func_8004BD00(rdram, ctx);
        goto after_12;
    // 0x8004D898: nop

    after_12:
    // 0x8004D89C: j           L_8004D918
    // 0x8004D8A0: nop

        goto L_8004D918;
    // 0x8004D8A0: nop

L_8004D8A4:
    // 0x8004D8A4: jal         0x8004B010
    // 0x8004D8A8: nop

    func_8004B010(rdram, ctx);
        goto after_13;
    // 0x8004D8A8: nop

    after_13:
    // 0x8004D8AC: j           L_8004D918
    // 0x8004D8B0: nop

        goto L_8004D918;
    // 0x8004D8B0: nop

L_8004D8B4:
    // 0x8004D8B4: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8004D8B8: addiu       $s0, $s0, 0x2087
    ctx->r16 = ADD32(ctx->r16, 0X2087);
    // 0x8004D8BC: jal         0x8000B87C
    // 0x8004D8C0: lbu         $s1, 0x0($s0)
    ctx->r17 = MEM_BU(ctx->r16, 0X0);
    func_8000B87C(rdram, ctx);
        goto after_14;
    // 0x8004D8C0: lbu         $s1, 0x0($s0)
    ctx->r17 = MEM_BU(ctx->r16, 0X0);
    after_14:
    // 0x8004D8C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004D8C8: sb          $zero, 0x7B70($at)
    MEM_B(0X7B70, ctx->r1) = 0;
    // 0x8004D8CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004D8D0: sb          $zero, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = 0;
    // 0x8004D8D4: jal         0x8004D958
    // 0x8004D8D8: sb          $s1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r17;
    func_8004D958(rdram, ctx);
        goto after_15;
    // 0x8004D8D8: sb          $s1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r17;
    after_15:
    // 0x8004D8DC: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x8004D8E0: addiu       $a0, $a0, 0xC50
    ctx->r4 = ADD32(ctx->r4, 0XC50);
    // 0x8004D8E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004D8E8: sb          $zero, 0x5583($at)
    MEM_B(0X5583, ctx->r1) = 0;
    // 0x8004D8EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004D8F0: sb          $zero, 0x5582($at)
    MEM_B(0X5582, ctx->r1) = 0;
    // 0x8004D8F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004D8F8: sb          $zero, 0x5581($at)
    MEM_B(0X5581, ctx->r1) = 0;
    // 0x8004D8FC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004D900: sb          $zero, 0x5580($at)
    MEM_B(0X5580, ctx->r1) = 0;
    // 0x8004D904: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004D908: sb          $zero, 0x2075($at)
    MEM_B(0X2075, ctx->r1) = 0;
    // 0x8004D90C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004D910: jal         0x80004780
    // 0x8004D914: sb          $zero, 0x7B4C($at)
    MEM_B(0X7B4C, ctx->r1) = 0;
    func_80004780(rdram, ctx);
        goto after_16;
    // 0x8004D914: sb          $zero, 0x7B4C($at)
    MEM_B(0X7B4C, ctx->r1) = 0;
    after_16:
L_8004D918:
    // 0x8004D918: jal         0x80004644
    // 0x8004D91C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80004644(rdram, ctx);
        goto after_17;
    // 0x8004D91C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_17:
    // 0x8004D920: j           L_8004D58C
    // 0x8004D924: nop

        goto L_8004D58C;
    // 0x8004D924: nop

    // 0x8004D928: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8004D92C: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x8004D930: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x8004D934: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8004D938: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8004D93C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8004D940: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8004D944: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8004D948: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8004D94C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8004D950: jr          $ra
    // 0x8004D954: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8004D954: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8004D958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D958: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004D95C: lb          $v0, 0xB7A($v0)
    ctx->r2 = MEM_B(ctx->r2, 0XB7A);
    // 0x8004D960: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8004D964: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x8004D968: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004D96C: lbu         $v1, -0x1948($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1948);
    // 0x8004D970: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004D974: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8004D978: lbu         $v0, -0x1947($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X1947);
    // 0x8004D97C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8004D980: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8004D984: addiu       $a1, $a1, 0x7B40
    ctx->r5 = ADD32(ctx->r5, 0X7B40);
    // 0x8004D988: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004D98C: sb          $a0, 0x2070($at)
    MEM_B(0X2070, ctx->r1) = ctx->r4;
    // 0x8004D990: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
    // 0x8004D994: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8004D998: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004D99C: sb          $v0, 0x7B41($at)
    MEM_B(0X7B41, ctx->r1) = ctx->r2;
    // 0x8004D9A0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8004D9A4: bne         $v1, $v0, L_8004D9C4
    if (ctx->r3 != ctx->r2) {
        // 0x8004D9A8: nop
    
            goto L_8004D9C4;
    }
    // 0x8004D9A8: nop

    // 0x8004D9AC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004D9B0: sb          $a0, 0x7B41($at)
    MEM_B(0X7B41, ctx->r1) = ctx->r4;
    // 0x8004D9B4: sb          $a0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r4;
    // 0x8004D9B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004D9BC: j           L_8004D9CC
    // 0x8004D9C0: sb          $a0, 0x7B4B($at)
    MEM_B(0X7B4B, ctx->r1) = ctx->r4;
        goto L_8004D9CC;
    // 0x8004D9C0: sb          $a0, 0x7B4B($at)
    MEM_B(0X7B4B, ctx->r1) = ctx->r4;
L_8004D9C4:
    // 0x8004D9C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004D9C8: sb          $zero, 0x7B4B($at)
    MEM_B(0X7B4B, ctx->r1) = 0;
L_8004D9CC:
    // 0x8004D9CC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8004D9D0: lbu         $v0, 0x7B40($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B40);
    // 0x8004D9D4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8004D9D8: lbu         $v1, 0x7B4B($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B4B);
    // 0x8004D9DC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8004D9E0: lbu         $a0, 0xB7B($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XB7B);
    // 0x8004D9E4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8004D9E8: lbu         $a1, 0xB7C($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0XB7C);
    // 0x8004D9EC: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x8004D9F0: lbu         $a2, 0xB7D($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XB7D);
    // 0x8004D9F4: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x8004D9F8: lbu         $a3, 0xB7E($a3)
    ctx->r7 = MEM_BU(ctx->r7, 0XB7E);
    // 0x8004D9FC: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x8004DA00: lbu         $t0, 0xB7F($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0XB7F);
    // 0x8004DA04: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x8004DA08: lbu         $t1, 0xB60($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0XB60);
    // 0x8004DA0C: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x8004DA10: lbu         $t2, 0xB61($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0XB61);
    // 0x8004DA14: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x8004DA18: lbu         $t3, 0xB62($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0XB62);
    // 0x8004DA1C: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x8004DA20: lbu         $t4, 0xB63($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0XB63);
    // 0x8004DA24: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8004DA28: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004DA2C: sb          $v0, 0x207F($at)
    MEM_B(0X207F, ctx->r1) = ctx->r2;
    // 0x8004DA30: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004DA34: sb          $v1, 0x207B($at)
    MEM_B(0X207B, ctx->r1) = ctx->r3;
    // 0x8004DA38: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004DA3C: sb          $a0, 0x7B4A($at)
    MEM_B(0X7B4A, ctx->r1) = ctx->r4;
    // 0x8004DA40: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004DA44: sb          $a1, 0x207A($at)
    MEM_B(0X207A, ctx->r1) = ctx->r5;
    // 0x8004DA48: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004DA4C: sb          $a2, 0x2079($at)
    MEM_B(0X2079, ctx->r1) = ctx->r6;
    // 0x8004DA50: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004DA54: sb          $a3, 0x2085($at)
    MEM_B(0X2085, ctx->r1) = ctx->r7;
    // 0x8004DA58: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004DA5C: sb          $t0, 0x2086($at)
    MEM_B(0X2086, ctx->r1) = ctx->r8;
    // 0x8004DA60: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004DA64: sb          $t1, 0x2076($at)
    MEM_B(0X2076, ctx->r1) = ctx->r9;
    // 0x8004DA68: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004DA6C: sb          $t2, 0x207E($at)
    MEM_B(0X207E, ctx->r1) = ctx->r10;
    // 0x8004DA70: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004DA74: sb          $t3, 0x2081($at)
    MEM_B(0X2081, ctx->r1) = ctx->r11;
    // 0x8004DA78: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8004DA7C: jr          $ra
    // 0x8004DA80: sb          $t4, 0x2077($at)
    MEM_B(0X2077, ctx->r1) = ctx->r12;
    return;
    // 0x8004DA80: sb          $t4, 0x2077($at)
    MEM_B(0X2077, ctx->r1) = ctx->r12;
;}
RECOMP_FUNC void func_8004DA90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DA90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004DA94: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8004DA98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DA9C: sw          $zero, -0x7500($at)
    MEM_W(-0X7500, ctx->r1) = 0;
    // 0x8004DAA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DAA4: jal         0x8004EBE0
    // 0x8004DAA8: sw          $zero, -0x74F4($at)
    MEM_W(-0X74F4, ctx->r1) = 0;
    func_8004EBE0(rdram, ctx);
        goto after_0;
    // 0x8004DAA8: sw          $zero, -0x74F4($at)
    MEM_W(-0X74F4, ctx->r1) = 0;
    after_0:
    // 0x8004DAAC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8004DAB0: jr          $ra
    // 0x8004DAB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8004DAB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8004DAB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DAB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004DABC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004DAC0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8004DAC4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8004DAC8: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8004DACC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004DAD0: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8004DAD4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8004DAD8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8004DADC: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8004DAE0: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8004DAE4: beq         $v0, $zero, L_8004DB58
    if (ctx->r2 == 0) {
        // 0x8004DAE8: addu        $s4, $a3, $zero
        ctx->r20 = ADD32(ctx->r7, 0);
            goto L_8004DB58;
    }
    // 0x8004DAE8: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x8004DAEC: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x8004DAF0: lw          $s1, -0x7500($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X7500);
    // 0x8004DAF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DAF8: sw          $s1, -0x74FC($at)
    MEM_W(-0X74FC, ctx->r1) = ctx->r17;
L_8004DAFC:
    // 0x8004DAFC: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x8004DB00: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8004DB04: lw          $a1, -0x7500($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7500);
    // 0x8004DB08: jal         0x8004DF90
    // 0x8004DB0C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_8004DF90(rdram, ctx);
        goto after_0;
    // 0x8004DB0C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_0:
    // 0x8004DB10: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004DB14: lw          $v0, -0x7500($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7500);
    // 0x8004DB18: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // 0x8004DB1C: slti        $v0, $a0, 0x100
    ctx->r2 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x8004DB20: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DB24: bne         $v0, $zero, L_8004DB38
    if (ctx->r2 != 0) {
        // 0x8004DB28: sw          $a0, -0x7500($at)
        MEM_W(-0X7500, ctx->r1) = ctx->r4;
            goto L_8004DB38;
    }
    // 0x8004DB28: sw          $a0, -0x7500($at)
    MEM_W(-0X7500, ctx->r1) = ctx->r4;
    // 0x8004DB2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DB30: j           L_8004DB58
    // 0x8004DB34: sw          $s1, -0x7500($at)
    MEM_W(-0X7500, ctx->r1) = ctx->r17;
        goto L_8004DB58;
    // 0x8004DB34: sw          $s1, -0x7500($at)
    MEM_W(-0X7500, ctx->r1) = ctx->r17;
L_8004DB38:
    // 0x8004DB38: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8004DB3C: bne         $v0, $zero, L_8004DAFC
    if (ctx->r2 != 0) {
        // 0x8004DB40: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_8004DAFC;
    }
    // 0x8004DB40: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8004DB44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DB48: sw          $a0, -0x74F8($at)
    MEM_W(-0X74F8, ctx->r1) = ctx->r4;
    // 0x8004DB4C: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8004DB50: jal         0x8004DB78
    // 0x8004DB54: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    func_8004DB78(rdram, ctx);
        goto after_1;
    // 0x8004DB54: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_1:
L_8004DB58:
    // 0x8004DB58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004DB5C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8004DB60: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8004DB64: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8004DB68: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8004DB6C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004DB70: jr          $ra
    // 0x8004DB74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004DB74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8004DB78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DB78: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004DB7C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8004DB80: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8004DB84: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8004DB88: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x8004DB8C: addu        $t8, $a3, $zero
    ctx->r24 = ADD32(ctx->r7, 0);
    // 0x8004DB90: lui         $v1, 0xBA00
    ctx->r3 = S32(0XBA00 << 16);
    // 0x8004DB94: ori         $v1, $v1, 0x1402
    ctx->r3 = ctx->r3 | 0X1402;
    // 0x8004DB98: lui         $a2, 0xFCFF
    ctx->r6 = S32(0XFCFF << 16);
    // 0x8004DB9C: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x8004DBA0: lui         $a1, 0xFFFC
    ctx->r5 = S32(0XFFFC << 16);
    // 0x8004DBA4: ori         $a1, $a1, 0xF279
    ctx->r5 = ctx->r5 | 0XF279;
    // 0x8004DBA8: lui         $a3, 0xBA00
    ctx->r7 = S32(0XBA00 << 16);
    // 0x8004DBAC: ori         $a3, $a3, 0x1301
    ctx->r7 = ctx->r7 | 0X1301;
    // 0x8004DBB0: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x8004DBB4: ori         $t1, $t1, 0x31D
    ctx->r9 = ctx->r9 | 0X31D;
    // 0x8004DBB8: lui         $t0, 0xF0A
    ctx->r8 = S32(0XF0A << 16);
    // 0x8004DBBC: ori         $t0, $t0, 0x7008
    ctx->r8 = ctx->r8 | 0X7008;
    // 0x8004DBC0: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x8004DBC4: ori         $t2, $t2, 0xE02
    ctx->r10 = ctx->r10 | 0XE02;
    // 0x8004DBC8: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x8004DBCC: ori         $t3, $t3, 0x100
    ctx->r11 = ctx->r11 | 0X100;
    // 0x8004DBD0: lui         $t4, 0x73F
    ctx->r12 = S32(0X73F << 16);
    // 0x8004DBD4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8004DBD8: lw          $a0, -0x74F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X74F8);
    // 0x8004DBDC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8004DBE0: lw          $t6, -0x74FC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X74FC);
    // 0x8004DBE4: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8004DBE8: lw          $t5, 0x2FE4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2FE4);
    // 0x8004DBEC: ori         $t4, $t4, 0xC000
    ctx->r12 = ctx->r12 | 0XC000;
    // 0x8004DBF0: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8004DBF4: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8004DBF8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8004DBFC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8004DC00: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004DC04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004DC08: subu        $s3, $a0, $t6
    ctx->r19 = SUB32(ctx->r4, ctx->r14);
    // 0x8004DC0C: addiu       $v0, $t5, 0x8
    ctx->r2 = ADD32(ctx->r13, 0X8);
    // 0x8004DC10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DC14: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DC18: addiu       $v0, $t5, 0x10
    ctx->r2 = ADD32(ctx->r13, 0X10);
    // 0x8004DC1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DC20: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DC24: addiu       $v0, $t5, 0x18
    ctx->r2 = ADD32(ctx->r13, 0X18);
    // 0x8004DC28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DC2C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DC30: addiu       $v0, $t5, 0x20
    ctx->r2 = ADD32(ctx->r13, 0X20);
    // 0x8004DC34: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DC38: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DC3C: addiu       $v0, $t5, 0x28
    ctx->r2 = ADD32(ctx->r13, 0X28);
    // 0x8004DC40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DC44: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DC48: addiu       $v0, $t5, 0x30
    ctx->r2 = ADD32(ctx->r13, 0X30);
    // 0x8004DC4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DC50: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DC54: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x8004DC58: sw          $v0, 0x2C($t5)
    MEM_W(0X2C, ctx->r13) = ctx->r2;
    // 0x8004DC5C: addiu       $v0, $t5, 0x38
    ctx->r2 = ADD32(ctx->r13, 0X38);
    // 0x8004DC60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DC64: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DC68: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x8004DC6C: sw          $v0, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r2;
    // 0x8004DC70: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004DC74: addiu       $v0, $v0, 0x38E0
    ctx->r2 = ADD32(ctx->r2, 0X38E0);
    // 0x8004DC78: sw          $v0, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r2;
    // 0x8004DC7C: addiu       $v0, $t5, 0x40
    ctx->r2 = ADD32(ctx->r13, 0X40);
    // 0x8004DC80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DC84: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DC88: lui         $v0, 0xE800
    ctx->r2 = S32(0XE800 << 16);
    // 0x8004DC8C: sw          $v0, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->r2;
    // 0x8004DC90: addiu       $v0, $t5, 0x48
    ctx->r2 = ADD32(ctx->r13, 0X48);
    // 0x8004DC94: sw          $a2, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r6;
    // 0x8004DC98: lui         $a2, 0x700
    ctx->r6 = S32(0X700 << 16);
    // 0x8004DC9C: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x8004DCA0: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8004DCA4: sw          $v1, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r3;
    // 0x8004DCA8: sw          $zero, 0xC($t5)
    MEM_W(0XC, ctx->r13) = 0;
    // 0x8004DCAC: sw          $a1, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r5;
    // 0x8004DCB0: sw          $a3, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r7;
    // 0x8004DCB4: sw          $zero, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = 0;
    // 0x8004DCB8: sw          $t1, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->r9;
    // 0x8004DCBC: sw          $t0, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->r8;
    // 0x8004DCC0: sw          $t2, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->r10;
    // 0x8004DCC4: sw          $zero, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = 0;
    // 0x8004DCC8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DCCC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DCD0: addiu       $v0, $t5, 0x50
    ctx->r2 = ADD32(ctx->r13, 0X50);
    // 0x8004DCD4: lui         $a1, 0xE600
    ctx->r5 = S32(0XE600 << 16);
    // 0x8004DCD8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DCDC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DCE0: addiu       $v0, $t5, 0x58
    ctx->r2 = ADD32(ctx->r13, 0X58);
    // 0x8004DCE4: andi        $v1, $t6, 0xFFF8
    ctx->r3 = ctx->r14 & 0XFFF8;
    // 0x8004DCE8: sra         $v1, $v1, 3
    ctx->r3 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8004DCEC: andi        $a0, $a0, 0xFFF8
    ctx->r4 = ctx->r4 & 0XFFF8;
    // 0x8004DCF0: sra         $a0, $a0, 3
    ctx->r4 = S32(SIGNED(ctx->r4) >> 3);
    // 0x8004DCF4: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x8004DCF8: addiu       $t1, $a0, 0x1
    ctx->r9 = ADD32(ctx->r4, 0X1);
    // 0x8004DCFC: sw          $t3, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->r11;
    // 0x8004DD00: sw          $a2, 0x44($t5)
    MEM_W(0X44, ctx->r13) = ctx->r6;
    // 0x8004DD04: sw          $a1, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->r5;
    // 0x8004DD08: sw          $zero, 0x4C($t5)
    MEM_W(0X4C, ctx->r13) = 0;
    // 0x8004DD0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DD10: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DD14: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8004DD18: lw          $a0, -0x34C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X34C0);
    // 0x8004DD1C: sll         $v0, $t1, 9
    ctx->r2 = S32(ctx->r9 << 9);
    // 0x8004DD20: sra         $v0, $v0, 2
    ctx->r2 = S32(SIGNED(ctx->r2) >> 2);
    // 0x8004DD24: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8004DD28: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x8004DD2C: sw          $v0, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->r2;
    // 0x8004DD30: addiu       $v0, $t5, 0x60
    ctx->r2 = ADD32(ctx->r13, 0X60);
    // 0x8004DD34: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DD38: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DD3C: addiu       $v0, $t5, 0x68
    ctx->r2 = ADD32(ctx->r13, 0X68);
    // 0x8004DD40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DD44: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DD48: lui         $v0, 0xFD50
    ctx->r2 = S32(0XFD50 << 16);
    // 0x8004DD4C: sw          $v0, 0x60($t5)
    MEM_W(0X60, ctx->r13) = ctx->r2;
    // 0x8004DD50: addiu       $v0, $t5, 0x70
    ctx->r2 = ADD32(ctx->r13, 0X70);
    // 0x8004DD54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DD58: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DD5C: lui         $v0, 0xF550
    ctx->r2 = S32(0XF550 << 16);
    // 0x8004DD60: sw          $v0, 0x68($t5)
    MEM_W(0X68, ctx->r13) = ctx->r2;
    // 0x8004DD64: addiu       $v0, $t5, 0x78
    ctx->r2 = ADD32(ctx->r13, 0X78);
    // 0x8004DD68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DD6C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DD70: addiu       $v0, $t5, 0x80
    ctx->r2 = ADD32(ctx->r13, 0X80);
    // 0x8004DD74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DD78: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DD7C: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x8004DD80: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x8004DD84: sw          $v0, 0x78($t5)
    MEM_W(0X78, ctx->r13) = ctx->r2;
    // 0x8004DD88: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004DD8C: addiu       $v0, $v0, 0x4B00
    ctx->r2 = ADD32(ctx->r2, 0X4B00);
    // 0x8004DD90: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004DD94: slti        $v0, $t0, 0x800
    ctx->r2 = SIGNED(ctx->r8) < 0X800 ? 1 : 0;
    // 0x8004DD98: sw          $t4, 0x54($t5)
    MEM_W(0X54, ctx->r13) = ctx->r12;
    // 0x8004DD9C: sw          $t7, 0x58($t5)
    MEM_W(0X58, ctx->r13) = ctx->r15;
    // 0x8004DDA0: sw          $zero, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = 0;
    // 0x8004DDA4: sw          $a2, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = ctx->r6;
    // 0x8004DDA8: sw          $a1, 0x70($t5)
    MEM_W(0X70, ctx->r13) = ctx->r5;
    // 0x8004DDAC: sw          $zero, 0x74($t5)
    MEM_W(0X74, ctx->r13) = 0;
    // 0x8004DDB0: sll         $a0, $a0, 13
    ctx->r4 = S32(ctx->r4 << 13);
    // 0x8004DDB4: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8004DDB8: bne         $v0, $zero, L_8004DDC4
    if (ctx->r2 != 0) {
        // 0x8004DDBC: sw          $a0, 0x64($t5)
        MEM_W(0X64, ctx->r13) = ctx->r4;
            goto L_8004DDC4;
    }
    // 0x8004DDBC: sw          $a0, 0x64($t5)
    MEM_W(0X64, ctx->r13) = ctx->r4;
    // 0x8004DDC0: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
L_8004DDC4:
    // 0x8004DDC4: lui         $v1, 0x700
    ctx->r3 = S32(0X700 << 16);
    // 0x8004DDC8: ori         $v1, $v1, 0x200
    ctx->r3 = ctx->r3 | 0X200;
    // 0x8004DDCC: lui         $a0, 0xF540
    ctx->r4 = S32(0XF540 << 16);
    // 0x8004DDD0: ori         $a0, $a0, 0x800
    ctx->r4 = ctx->r4 | 0X800;
    // 0x8004DDD4: lui         $a1, 0xF
    ctx->r5 = S32(0XF << 16);
    // 0x8004DDD8: ori         $a1, $a1, 0xC000
    ctx->r5 = ctx->r5 | 0XC000;
    // 0x8004DDDC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004DDE0: andi        $a3, $t6, 0x7
    ctx->r7 = ctx->r14 & 0X7;
    // 0x8004DDE4: addu        $a2, $a3, $zero
    ctx->r6 = ADD32(ctx->r7, 0);
    // 0x8004DDE8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8004DDEC: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
    // 0x8004DDF0: andi        $v0, $t0, 0xFFF
    ctx->r2 = ctx->r8 & 0XFFF;
    // 0x8004DDF4: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8004DDF8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8004DDFC: sw          $v0, 0x7C($t5)
    MEM_W(0X7C, ctx->r13) = ctx->r2;
    // 0x8004DE00: addiu       $v0, $t5, 0x88
    ctx->r2 = ADD32(ctx->r13, 0X88);
    // 0x8004DE04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DE08: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DE0C: addiu       $v0, $t5, 0x90
    ctx->r2 = ADD32(ctx->r13, 0X90);
    // 0x8004DE10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DE14: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DE18: andi        $v0, $t8, 0xF
    ctx->r2 = ctx->r24 & 0XF;
    // 0x8004DE1C: sll         $v0, $v0, 20
    ctx->r2 = S32(ctx->r2 << 20);
    // 0x8004DE20: sw          $v0, 0x8C($t5)
    MEM_W(0X8C, ctx->r13) = ctx->r2;
    // 0x8004DE24: addiu       $v0, $t5, 0x98
    ctx->r2 = ADD32(ctx->r13, 0X98);
    // 0x8004DE28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DE2C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DE30: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x8004DE34: sw          $v0, 0x90($t5)
    MEM_W(0X90, ctx->r13) = ctx->r2;
    // 0x8004DE38: sll         $v0, $t1, 5
    ctx->r2 = S32(ctx->r9 << 5);
    // 0x8004DE3C: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8004DE40: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8004DE44: or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // 0x8004DE48: sw          $t7, 0x80($t5)
    MEM_W(0X80, ctx->r13) = ctx->r15;
    // 0x8004DE4C: sw          $zero, 0x84($t5)
    MEM_W(0X84, ctx->r13) = 0;
    // 0x8004DE50: sw          $a0, 0x88($t5)
    MEM_W(0X88, ctx->r13) = ctx->r4;
    // 0x8004DE54: sw          $v0, 0x94($t5)
    MEM_W(0X94, ctx->r13) = ctx->r2;
    // 0x8004DE58: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8004DE5C:
    // 0x8004DE5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8004DE60: bne         $a2, $s5, L_8004DE98
    if (ctx->r6 != ctx->r21) {
        // 0x8004DE64: addiu       $s3, $s3, -0x1
        ctx->r19 = ADD32(ctx->r19, -0X1);
            goto L_8004DE98;
    }
    // 0x8004DE64: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x8004DE68: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004DE6C: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    // 0x8004DE70: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8004DE74: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004DE78: jal         0x8004DEE0
    // 0x8004DE7C: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    func_8004DEE0(rdram, ctx);
        goto after_0;
    // 0x8004DE7C: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_0:
    // 0x8004DE80: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x8004DE84: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x8004DE88: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004DE8C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8004DE90: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8004DE94: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8004DE98:
    // 0x8004DE98: bnel        $s3, $zero, L_8004DE5C
    if (ctx->r19 != 0) {
        // 0x8004DE9C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8004DE5C;
    }
    goto skip_0;
    // 0x8004DE9C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_0:
    // 0x8004DEA0: beq         $s0, $zero, L_8004DEBC
    if (ctx->r16 == 0) {
        // 0x8004DEA4: addu        $a0, $a3, $zero
        ctx->r4 = ADD32(ctx->r7, 0);
            goto L_8004DEBC;
    }
    // 0x8004DEA4: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    // 0x8004DEA8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004DEAC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8004DEB0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8004DEB4: jal         0x8004DEE0
    // 0x8004DEB8: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    func_8004DEE0(rdram, ctx);
        goto after_1;
    // 0x8004DEB8: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_1:
L_8004DEBC:
    // 0x8004DEBC: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8004DEC0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8004DEC4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8004DEC8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8004DECC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8004DED0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004DED4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004DED8: jr          $ra
    // 0x8004DEDC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8004DEDC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8004DEE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DEE0: lui         $t2, 0x400
    ctx->r10 = S32(0X400 << 16);
    // 0x8004DEE4: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8004DEE8: lw          $t1, 0x2FE4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2FE4);
    // 0x8004DEEC: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x8004DEF0: ori         $t2, $t2, 0x400
    ctx->r10 = ctx->r10 | 0X400;
    // 0x8004DEF4: lui         $t0, 0xE400
    ctx->r8 = S32(0XE400 << 16);
    // 0x8004DEF8: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x8004DEFC: sll         $a1, $a1, 8
    ctx->r5 = S32(ctx->r5 << 8);
    // 0x8004DF00: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8004DF04: or          $a0, $a0, $a1
    ctx->r4 = ctx->r4 | ctx->r5;
    // 0x8004DF08: addiu       $v0, $t1, 0x8
    ctx->r2 = ADD32(ctx->r9, 0X8);
    // 0x8004DF0C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8004DF10: addu        $v1, $a2, $v1
    ctx->r3 = ADD32(ctx->r6, ctx->r3);
    // 0x8004DF14: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004DF18: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8004DF1C: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x8004DF20: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DF24: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DF28: addiu       $v0, $a3, 0x8
    ctx->r2 = ADD32(ctx->r7, 0X8);
    // 0x8004DF2C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004DF30: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8004DF34: or          $v0, $v0, $t0
    ctx->r2 = ctx->r2 | ctx->r8;
    // 0x8004DF38: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8004DF3C: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8004DF40: andi        $a2, $a2, 0xFFF
    ctx->r6 = ctx->r6 & 0XFFF;
    // 0x8004DF44: sll         $a2, $a2, 12
    ctx->r6 = S32(ctx->r6 << 12);
    // 0x8004DF48: sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7 << 2);
    // 0x8004DF4C: andi        $a3, $a3, 0xFFF
    ctx->r7 = ctx->r7 & 0XFFF;
    // 0x8004DF50: or          $a2, $a2, $a3
    ctx->r6 = ctx->r6 | ctx->r7;
    // 0x8004DF54: addiu       $v0, $t1, 0x10
    ctx->r2 = ADD32(ctx->r9, 0X10);
    // 0x8004DF58: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DF5C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DF60: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x8004DF64: sw          $v0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r2;
    // 0x8004DF68: addiu       $v0, $t1, 0x18
    ctx->r2 = ADD32(ctx->r9, 0X18);
    // 0x8004DF6C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004DF70: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004DF74: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x8004DF78: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x8004DF7C: sw          $a2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r6;
    // 0x8004DF80: sw          $a0, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r4;
    // 0x8004DF84: sw          $v0, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r2;
    // 0x8004DF88: jr          $ra
    // 0x8004DF8C: sw          $t2, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r10;
    return;
    // 0x8004DF8C: sw          $t2, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r10;
;}
RECOMP_FUNC void func_8004DF90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DF90: andi        $v0, $a1, 0x7
    ctx->r2 = ctx->r5 & 0X7;
    // 0x8004DF94: andi        $a1, $a1, 0xFFF8
    ctx->r5 = ctx->r5 & 0XFFF8;
    // 0x8004DF98: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x8004DF9C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8004DFA0: andi        $v0, $a0, 0xF
    ctx->r2 = ctx->r4 & 0XF;
    // 0x8004DFA4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004DFA8: lw          $v1, -0x34C0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X34C0);
    // 0x8004DFAC: andi        $a0, $a0, 0xF0
    ctx->r4 = ctx->r4 & 0XF0;
    // 0x8004DFB0: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x8004DFB4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004DFB8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004DFBC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004DFC0: addiu       $v0, $v0, 0x18D8
    ctx->r2 = ADD32(ctx->r2, 0X18D8);
    // 0x8004DFC4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004DFC8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8004DFCC: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x8004DFD0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004DFD4: addiu       $v0, $v0, 0x4B00
    ctx->r2 = ADD32(ctx->r2, 0X4B00);
    // 0x8004DFD8: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8004DFDC: sll         $v1, $v1, 13
    ctx->r3 = S32(ctx->r3 << 13);
    // 0x8004DFE0: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
L_8004DFE4:
    // 0x8004DFE4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8004DFE8: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x8004DFEC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8004DFF0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004DFF4: sltiu       $v0, $a2, 0x8
    ctx->r2 = ctx->r6 < 0X8 ? 1 : 0;
    // 0x8004DFF8: bne         $v0, $zero, L_8004DFE4
    if (ctx->r2 != 0) {
        // 0x8004DFFC: addiu       $v1, $v1, 0x20
        ctx->r3 = ADD32(ctx->r3, 0X20);
            goto L_8004DFE4;
    }
    // 0x8004DFFC: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8004E000: jr          $ra
    // 0x8004E004: nop

    return;
    // 0x8004E004: nop

;}
RECOMP_FUNC void func_8004E008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004E00C: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8004E010: addu        $t2, $a0, $zero
    ctx->r10 = ADD32(ctx->r4, 0);
    // 0x8004E014: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8004E018: lbu         $v0, 0x0($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X0);
    // 0x8004E01C: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8004E020: beq         $v0, $zero, L_8004E110
    if (ctx->r2 == 0) {
        // 0x8004E024: lbu         $t4, 0x33($sp)
        ctx->r12 = MEM_BU(ctx->r29, 0X33);
            goto L_8004E110;
    }
    // 0x8004E024: lbu         $t4, 0x33($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X33);
    // 0x8004E028: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8004E02C: lw          $t3, -0x7500($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7500);
    // 0x8004E030: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8004E034: addiu       $t6, $t6, 0x4B00
    ctx->r14 = ADD32(ctx->r14, 0X4B00);
    // 0x8004E038: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8004E03C: addiu       $t5, $t5, 0x18D8
    ctx->r13 = ADD32(ctx->r13, 0X18D8);
    // 0x8004E040: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E044: sw          $t3, -0x74FC($at)
    MEM_W(-0X74FC, ctx->r1) = ctx->r11;
L_8004E048:
    // 0x8004E048: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004E04C: lw          $v0, -0x7500($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7500);
    // 0x8004E050: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8004E054: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8004E058: lw          $a0, -0x34C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X34C0);
    // 0x8004E05C: lbu         $v1, 0x0($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X0);
    // 0x8004E060: andi        $t0, $v0, 0x7
    ctx->r8 = ctx->r2 & 0X7;
    // 0x8004E064: andi        $v0, $v0, 0xFFF8
    ctx->r2 = ctx->r2 & 0XFFF8;
    // 0x8004E068: sll         $a0, $a0, 13
    ctx->r4 = S32(ctx->r4 << 13);
    // 0x8004E06C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8004E070: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8004E074: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004E078: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8004E07C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004E080: andi        $t0, $v1, 0xF
    ctx->r8 = ctx->r3 & 0XF;
    // 0x8004E084: srl         $v1, $v1, 4
    ctx->r3 = S32(U32(ctx->r3) >> 4);
    // 0x8004E088: sll         $v1, $v1, 9
    ctx->r3 = S32(ctx->r3 << 9);
    // 0x8004E08C: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x8004E090: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004E094: addu        $v1, $v1, $t5
    ctx->r3 = ADD32(ctx->r3, ctx->r13);
L_8004E098:
    // 0x8004E098: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8004E09C: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x8004E0A0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8004E0A4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8004E0A8: sltiu       $v0, $t1, 0x8
    ctx->r2 = ctx->r9 < 0X8 ? 1 : 0;
    // 0x8004E0AC: bne         $v0, $zero, L_8004E098
    if (ctx->r2 != 0) {
        // 0x8004E0B0: addiu       $a0, $a0, 0x20
        ctx->r4 = ADD32(ctx->r4, 0X20);
            goto L_8004E098;
    }
    // 0x8004E0B0: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8004E0B4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004E0B8: lw          $v0, -0x7500($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7500);
    // 0x8004E0BC: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // 0x8004E0C0: slti        $v0, $a0, 0x100
    ctx->r2 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x8004E0C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E0C8: sw          $a0, -0x7500($at)
    MEM_W(-0X7500, ctx->r1) = ctx->r4;
    // 0x8004E0CC: bne         $v0, $zero, L_8004E0E0
    if (ctx->r2 != 0) {
        // 0x8004E0D0: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_8004E0E0;
    }
    // 0x8004E0D0: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8004E0D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E0D8: j           L_8004E110
    // 0x8004E0DC: sw          $t3, -0x7500($at)
    MEM_W(-0X7500, ctx->r1) = ctx->r11;
        goto L_8004E110;
    // 0x8004E0DC: sw          $t3, -0x7500($at)
    MEM_W(-0X7500, ctx->r1) = ctx->r11;
L_8004E0E0:
    // 0x8004E0E0: lbu         $v0, 0x0($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X0);
    // 0x8004E0E4: bne         $v0, $zero, L_8004E048
    if (ctx->r2 != 0) {
        // 0x8004E0E8: nop
    
            goto L_8004E048;
    }
    // 0x8004E0E8: nop

    // 0x8004E0EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E0F0: sw          $a0, -0x74F8($at)
    MEM_W(-0X74F8, ctx->r1) = ctx->r4;
    // 0x8004E0F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E0F8: swc1        $f2, -0x74E8($at)
    MEM_W(-0X74E8, ctx->r1) = ctx->f2.u32l;
    // 0x8004E0FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E100: swc1        $f0, -0x74E4($at)
    MEM_W(-0X74E4, ctx->r1) = ctx->f0.u32l;
    // 0x8004E104: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E108: jal         0x8004E11C
    // 0x8004E10C: sb          $t4, -0x74E0($at)
    MEM_B(-0X74E0, ctx->r1) = ctx->r12;
    func_8004E11C(rdram, ctx);
        goto after_0;
    // 0x8004E10C: sb          $t4, -0x74E0($at)
    MEM_B(-0X74E0, ctx->r1) = ctx->r12;
    after_0:
L_8004E110:
    // 0x8004E110: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8004E114: jr          $ra
    // 0x8004E118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8004E118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8004E11C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E11C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004E120: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8004E124: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8004E128: addu        $t9, $a3, $zero
    ctx->r25 = ADD32(ctx->r7, 0);
    // 0x8004E12C: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x8004E130: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8004E134: nop

    // 0x8004E138: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x8004E13C: lui         $v1, 0xBA00
    ctx->r3 = S32(0XBA00 << 16);
    // 0x8004E140: ori         $v1, $v1, 0x1402
    ctx->r3 = ctx->r3 | 0X1402;
    // 0x8004E144: lui         $a2, 0xBA00
    ctx->r6 = S32(0XBA00 << 16);
    // 0x8004E148: ori         $a2, $a2, 0x1301
    ctx->r6 = ctx->r6 | 0X1301;
    // 0x8004E14C: lui         $t1, 0xFC11
    ctx->r9 = S32(0XFC11 << 16);
    // 0x8004E150: ori         $t1, $t1, 0x9623
    ctx->r9 = ctx->r9 | 0X9623;
    // 0x8004E154: lui         $a3, 0xFF2F
    ctx->r7 = S32(0XFF2F << 16);
    // 0x8004E158: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x8004E15C: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x8004E160: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x8004E164: lui         $t0, 0x40
    ctx->r8 = S32(0X40 << 16);
    // 0x8004E168: ori         $t0, $t0, 0x4240
    ctx->r8 = ctx->r8 | 0X4240;
    // 0x8004E16C: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x8004E170: ori         $t3, $t3, 0xE02
    ctx->r11 = ctx->r11 | 0XE02;
    // 0x8004E174: lui         $t4, 0xF500
    ctx->r12 = S32(0XF500 << 16);
    // 0x8004E178: ori         $t4, $t4, 0x100
    ctx->r12 = ctx->r12 | 0X100;
    // 0x8004E17C: lui         $t5, 0x73F
    ctx->r13 = S32(0X73F << 16);
    // 0x8004E180: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8004E184: lw          $a0, -0x74F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X74F8);
    // 0x8004E188: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8004E18C: lw          $t7, -0x74FC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X74FC);
    // 0x8004E190: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8004E194: lw          $t6, 0x2FE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2FE4);
    // 0x8004E198: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8004E19C: lbu         $a1, -0x74E0($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X74E0);
    // 0x8004E1A0: ori         $t5, $t5, 0xC000
    ctx->r13 = ctx->r13 | 0XC000;
    // 0x8004E1A4: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8004E1A8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004E1AC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8004E1B0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8004E1B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004E1B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004E1BC: subu        $s2, $a0, $t7
    ctx->r18 = SUB32(ctx->r4, ctx->r15);
    // 0x8004E1C0: addiu       $v0, $t6, 0x8
    ctx->r2 = ADD32(ctx->r14, 0X8);
    // 0x8004E1C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E1C8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E1CC: addiu       $v0, $t6, 0x10
    ctx->r2 = ADD32(ctx->r14, 0X10);
    // 0x8004E1D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E1D4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E1D8: addiu       $v0, $t6, 0x18
    ctx->r2 = ADD32(ctx->r14, 0X18);
    // 0x8004E1DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E1E0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E1E4: addiu       $v0, $t6, 0x20
    ctx->r2 = ADD32(ctx->r14, 0X20);
    // 0x8004E1E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E1EC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E1F0: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x8004E1F4: sw          $v0, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r2;
    // 0x8004E1F8: sll         $v0, $a1, 24
    ctx->r2 = S32(ctx->r5 << 24);
    // 0x8004E1FC: sw          $v1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r3;
    // 0x8004E200: sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5 << 16);
    // 0x8004E204: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8004E208: sll         $v1, $a1, 8
    ctx->r3 = S32(ctx->r5 << 8);
    // 0x8004E20C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8004E210: or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // 0x8004E214: sw          $v0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r2;
    // 0x8004E218: addiu       $v0, $t6, 0x28
    ctx->r2 = ADD32(ctx->r14, 0X28);
    // 0x8004E21C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E220: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E224: addiu       $v0, $t6, 0x30
    ctx->r2 = ADD32(ctx->r14, 0X30);
    // 0x8004E228: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E22C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E230: addiu       $v0, $t6, 0x38
    ctx->r2 = ADD32(ctx->r14, 0X38);
    // 0x8004E234: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E238: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E23C: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x8004E240: sw          $v0, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->r2;
    // 0x8004E244: addiu       $v0, $t6, 0x40
    ctx->r2 = ADD32(ctx->r14, 0X40);
    // 0x8004E248: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E24C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E250: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x8004E254: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8004E258: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x8004E25C: sw          $zero, 0xC($t6)
    MEM_W(0XC, ctx->r14) = 0;
    // 0x8004E260: sw          $a2, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r6;
    // 0x8004E264: sw          $zero, 0x14($t6)
    MEM_W(0X14, ctx->r14) = 0;
    // 0x8004E268: sw          $t1, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r9;
    // 0x8004E26C: sw          $a3, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->r7;
    // 0x8004E270: sw          $t2, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r10;
    // 0x8004E274: sw          $t0, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->r8;
    // 0x8004E278: sw          $t3, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r11;
    // 0x8004E27C: sw          $v0, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->r2;
    // 0x8004E280: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004E284: addiu       $v0, $v0, 0x38E0
    ctx->r2 = ADD32(ctx->r2, 0X38E0);
    // 0x8004E288: sw          $v0, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->r2;
    // 0x8004E28C: addiu       $v0, $t6, 0x48
    ctx->r2 = ADD32(ctx->r14, 0X48);
    // 0x8004E290: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E294: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E298: lui         $v0, 0xE800
    ctx->r2 = S32(0XE800 << 16);
    // 0x8004E29C: sw          $v0, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->r2;
    // 0x8004E2A0: addiu       $v0, $t6, 0x50
    ctx->r2 = ADD32(ctx->r14, 0X50);
    // 0x8004E2A4: lui         $a2, 0x700
    ctx->r6 = S32(0X700 << 16);
    // 0x8004E2A8: andi        $v1, $t7, 0xFFF8
    ctx->r3 = ctx->r15 & 0XFFF8;
    // 0x8004E2AC: sra         $v1, $v1, 3
    ctx->r3 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8004E2B0: andi        $a0, $a0, 0xFFF8
    ctx->r4 = ctx->r4 & 0XFFF8;
    // 0x8004E2B4: sra         $a0, $a0, 3
    ctx->r4 = S32(SIGNED(ctx->r4) >> 3);
    // 0x8004E2B8: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x8004E2BC: addiu       $t1, $a0, 0x1
    ctx->r9 = ADD32(ctx->r4, 0X1);
    // 0x8004E2C0: sw          $zero, 0x44($t6)
    MEM_W(0X44, ctx->r14) = 0;
    // 0x8004E2C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E2C8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E2CC: sw          $t4, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->r12;
    // 0x8004E2D0: sw          $a2, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->r6;
    // 0x8004E2D4: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8004E2D8: lw          $a0, -0x34C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X34C0);
    // 0x8004E2DC: sll         $v0, $t1, 9
    ctx->r2 = S32(ctx->r9 << 9);
    // 0x8004E2E0: sra         $v0, $v0, 2
    ctx->r2 = S32(SIGNED(ctx->r2) >> 2);
    // 0x8004E2E4: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8004E2E8: addiu       $v0, $t6, 0x58
    ctx->r2 = ADD32(ctx->r14, 0X58);
    // 0x8004E2EC: lui         $a1, 0xE600
    ctx->r5 = S32(0XE600 << 16);
    // 0x8004E2F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E2F4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E2F8: addiu       $v0, $t6, 0x60
    ctx->r2 = ADD32(ctx->r14, 0X60);
    // 0x8004E2FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E300: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E304: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x8004E308: sw          $v0, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->r2;
    // 0x8004E30C: addiu       $v0, $t6, 0x68
    ctx->r2 = ADD32(ctx->r14, 0X68);
    // 0x8004E310: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E314: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E318: addiu       $v0, $t6, 0x70
    ctx->r2 = ADD32(ctx->r14, 0X70);
    // 0x8004E31C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E320: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E324: lui         $v0, 0xFD50
    ctx->r2 = S32(0XFD50 << 16);
    // 0x8004E328: sw          $v0, 0x68($t6)
    MEM_W(0X68, ctx->r14) = ctx->r2;
    // 0x8004E32C: addiu       $v0, $t6, 0x78
    ctx->r2 = ADD32(ctx->r14, 0X78);
    // 0x8004E330: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E334: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E338: lui         $v0, 0xF550
    ctx->r2 = S32(0XF550 << 16);
    // 0x8004E33C: sw          $v0, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->r2;
    // 0x8004E340: addiu       $v0, $t6, 0x80
    ctx->r2 = ADD32(ctx->r14, 0X80);
    // 0x8004E344: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E348: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E34C: addiu       $v0, $t6, 0x88
    ctx->r2 = ADD32(ctx->r14, 0X88);
    // 0x8004E350: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E354: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E358: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x8004E35C: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x8004E360: sw          $v0, 0x80($t6)
    MEM_W(0X80, ctx->r14) = ctx->r2;
    // 0x8004E364: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8004E368: addiu       $v0, $v0, 0x4B00
    ctx->r2 = ADD32(ctx->r2, 0X4B00);
    // 0x8004E36C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004E370: slti        $v0, $t0, 0x800
    ctx->r2 = SIGNED(ctx->r8) < 0X800 ? 1 : 0;
    // 0x8004E374: sw          $a1, 0x50($t6)
    MEM_W(0X50, ctx->r14) = ctx->r5;
    // 0x8004E378: sw          $zero, 0x54($t6)
    MEM_W(0X54, ctx->r14) = 0;
    // 0x8004E37C: sw          $t5, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = ctx->r13;
    // 0x8004E380: sw          $t8, 0x60($t6)
    MEM_W(0X60, ctx->r14) = ctx->r24;
    // 0x8004E384: sw          $zero, 0x64($t6)
    MEM_W(0X64, ctx->r14) = 0;
    // 0x8004E388: sw          $a2, 0x74($t6)
    MEM_W(0X74, ctx->r14) = ctx->r6;
    // 0x8004E38C: sw          $a1, 0x78($t6)
    MEM_W(0X78, ctx->r14) = ctx->r5;
    // 0x8004E390: sw          $zero, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = 0;
    // 0x8004E394: sll         $a0, $a0, 13
    ctx->r4 = S32(ctx->r4 << 13);
    // 0x8004E398: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8004E39C: bne         $v0, $zero, L_8004E3A8
    if (ctx->r2 != 0) {
        // 0x8004E3A0: sw          $a0, 0x6C($t6)
        MEM_W(0X6C, ctx->r14) = ctx->r4;
            goto L_8004E3A8;
    }
    // 0x8004E3A0: sw          $a0, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->r4;
    // 0x8004E3A4: addiu       $t0, $zero, 0x7FF
    ctx->r8 = ADD32(0, 0X7FF);
L_8004E3A8:
    // 0x8004E3A8: lui         $v1, 0x700
    ctx->r3 = S32(0X700 << 16);
    // 0x8004E3AC: ori         $v1, $v1, 0x200
    ctx->r3 = ctx->r3 | 0X200;
    // 0x8004E3B0: lui         $a0, 0xF540
    ctx->r4 = S32(0XF540 << 16);
    // 0x8004E3B4: ori         $a0, $a0, 0x800
    ctx->r4 = ctx->r4 | 0X800;
    // 0x8004E3B8: lui         $a1, 0xF
    ctx->r5 = S32(0XF << 16);
    // 0x8004E3BC: ori         $a1, $a1, 0xC000
    ctx->r5 = ctx->r5 | 0XC000;
    // 0x8004E3C0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004E3C4: andi        $a3, $t7, 0x7
    ctx->r7 = ctx->r15 & 0X7;
    // 0x8004E3C8: addu        $a2, $a3, $zero
    ctx->r6 = ADD32(ctx->r7, 0);
    // 0x8004E3CC: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8004E3D0: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
    // 0x8004E3D4: andi        $v0, $t0, 0xFFF
    ctx->r2 = ctx->r8 & 0XFFF;
    // 0x8004E3D8: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8004E3DC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8004E3E0: sw          $v0, 0x84($t6)
    MEM_W(0X84, ctx->r14) = ctx->r2;
    // 0x8004E3E4: addiu       $v0, $t6, 0x90
    ctx->r2 = ADD32(ctx->r14, 0X90);
    // 0x8004E3E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E3EC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E3F0: addiu       $v0, $t6, 0x98
    ctx->r2 = ADD32(ctx->r14, 0X98);
    // 0x8004E3F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E3F8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E3FC: andi        $v0, $t9, 0xF
    ctx->r2 = ctx->r25 & 0XF;
    // 0x8004E400: sll         $v0, $v0, 20
    ctx->r2 = S32(ctx->r2 << 20);
    // 0x8004E404: sw          $v0, 0x94($t6)
    MEM_W(0X94, ctx->r14) = ctx->r2;
    // 0x8004E408: addiu       $v0, $t6, 0xA0
    ctx->r2 = ADD32(ctx->r14, 0XA0);
    // 0x8004E40C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E410: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E414: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x8004E418: sw          $v0, 0x98($t6)
    MEM_W(0X98, ctx->r14) = ctx->r2;
    // 0x8004E41C: sll         $v0, $t1, 5
    ctx->r2 = S32(ctx->r9 << 5);
    // 0x8004E420: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8004E424: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8004E428: or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // 0x8004E42C: sw          $t8, 0x88($t6)
    MEM_W(0X88, ctx->r14) = ctx->r24;
    // 0x8004E430: sw          $zero, 0x8C($t6)
    MEM_W(0X8C, ctx->r14) = 0;
    // 0x8004E434: sw          $a0, 0x90($t6)
    MEM_W(0X90, ctx->r14) = ctx->r4;
    // 0x8004E438: sw          $v0, 0x9C($t6)
    MEM_W(0X9C, ctx->r14) = ctx->r2;
    // 0x8004E43C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8004E440:
    // 0x8004E440: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8004E444: bne         $a2, $s4, L_8004E498
    if (ctx->r6 != ctx->r20) {
        // 0x8004E448: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_8004E498;
    }
    // 0x8004E448: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8004E44C: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    // 0x8004E450: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8004E454: trunc.w.s   $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x8004E458: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8004E45C: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // 0x8004E460: jal         0x8004E4E8
    // 0x8004E464: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_8004E4E8(rdram, ctx);
        goto after_0;
    // 0x8004E464: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8004E468: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E46C: lwc1        $f2, -0x74E8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X74E8);
    // 0x8004E470: sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16 << 3);
    // 0x8004E474: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8004E478: nop

    // 0x8004E47C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8004E480: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004E484: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8004E488: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8004E48C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8004E490: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8004E494: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
L_8004E498:
    // 0x8004E498: bnel        $s2, $zero, L_8004E440
    if (ctx->r18 != 0) {
        // 0x8004E49C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8004E440;
    }
    goto skip_0;
    // 0x8004E49C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_0:
    // 0x8004E4A0: beq         $s0, $zero, L_8004E4C4
    if (ctx->r16 == 0) {
        // 0x8004E4A4: addu        $a0, $a3, $zero
        ctx->r4 = ADD32(ctx->r7, 0);
            goto L_8004E4C4;
    }
    // 0x8004E4A4: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    // 0x8004E4A8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004E4AC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8004E4B0: trunc.w.s   $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x8004E4B4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8004E4B8: nop

    // 0x8004E4BC: jal         0x8004E4E8
    // 0x8004E4C0: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    func_8004E4E8(rdram, ctx);
        goto after_1;
    // 0x8004E4C0: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_1:
L_8004E4C4:
    // 0x8004E4C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004E4C8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8004E4CC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8004E4D0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8004E4D4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004E4D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004E4DC: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x8004E4E0: jr          $ra
    // 0x8004E4E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8004E4E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8004E4E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E4E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E4EC: lwc1        $f10, -0x74E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X74E8);
    // 0x8004E4F0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004E4F4: ldc1        $f4, -0x17B0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X17B0);
    // 0x8004E4F8: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8004E4FC: div.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x8004E500: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E504: lwc1        $f0, -0x74E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X74E4);
    // 0x8004E508: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8004E50C: lw          $t0, 0x2FE4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2FE4);
    // 0x8004E510: lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10);
    // 0x8004E514: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004E518: ldc1        $f2, -0x17A8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X17A8);
    // 0x8004E51C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8004E520: div.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x8004E524: sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7 << 2);
    // 0x8004E528: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8004E52C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004E530: ldc1        $f8, -0x17A0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X17A0);
    // 0x8004E534: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x8004E538: sll         $a1, $a1, 8
    ctx->r5 = S32(ctx->r5 << 8);
    // 0x8004E53C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8004E540: or          $a0, $a0, $a1
    ctx->r4 = ctx->r4 | ctx->r5;
    // 0x8004E544: addiu       $v0, $t0, 0x8
    ctx->r2 = ADD32(ctx->r8, 0X8);
    // 0x8004E548: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E54C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E550: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8004E554: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8004E558: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8004E55C: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8004E560: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8004E564: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x8004E568: addiu       $v0, $t0, 0x10
    ctx->r2 = ADD32(ctx->r8, 0X10);
    // 0x8004E56C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E570: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E574: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x8004E578: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8004E57C: mtc1        $t1, $f2
    ctx->f2.u32l = ctx->r9;
    // 0x8004E580: nop

    // 0x8004E584: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8004E588: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8004E58C: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    // 0x8004E590: addiu       $v0, $t0, 0x18
    ctx->r2 = ADD32(ctx->r8, 0X18);
    // 0x8004E594: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E598: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E59C: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x8004E5A0: sw          $a0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r4;
    // 0x8004E5A4: sw          $v0, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r2;
    // 0x8004E5A8: mul.d       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8004E5AC: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8004E5B0: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8004E5B4: nop

    // 0x8004E5B8: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8004E5BC: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8004E5C0: andi        $a2, $a2, 0xFFF
    ctx->r6 = ctx->r6 & 0XFFF;
    // 0x8004E5C4: sll         $a2, $a2, 12
    ctx->r6 = S32(ctx->r6 << 12);
    // 0x8004E5C8: lui         $v0, 0xE400
    ctx->r2 = S32(0XE400 << 16);
    // 0x8004E5CC: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x8004E5D0: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8004E5D4: mul.d       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x8004E5D8: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x8004E5DC: sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7 << 2);
    // 0x8004E5E0: andi        $a3, $a3, 0xFFF
    ctx->r7 = ctx->r7 & 0XFFF;
    // 0x8004E5E4: or          $a3, $a3, $v0
    ctx->r7 = ctx->r7 | ctx->r2;
    // 0x8004E5E8: or          $a2, $a2, $a3
    ctx->r6 = ctx->r6 | ctx->r7;
    // 0x8004E5EC: sw          $a2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r6;
    // 0x8004E5F0: trunc.w.d   $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x8004E5F4: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8004E5F8: trunc.w.d   $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x8004E5FC: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8004E600: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8004E604: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8004E608: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8004E60C: jr          $ra
    // 0x8004E610: sw          $v1, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r3;
    return;
    // 0x8004E610: sw          $v1, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r3;
;}
RECOMP_FUNC void func_8004E614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E614: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004E618: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004E61C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8004E620: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8004E624: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8004E628: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004E62C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8004E630: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8004E634: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8004E638: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8004E63C: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8004E640: beq         $v0, $zero, L_8004E6B4
    if (ctx->r2 == 0) {
        // 0x8004E644: addu        $s4, $a3, $zero
        ctx->r20 = ADD32(ctx->r7, 0);
            goto L_8004E6B4;
    }
    // 0x8004E644: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x8004E648: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x8004E64C: lw          $s1, -0x74F4($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X74F4);
    // 0x8004E650: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E654: sw          $s1, -0x74F0($at)
    MEM_W(-0X74F0, ctx->r1) = ctx->r17;
L_8004E658:
    // 0x8004E658: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x8004E65C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8004E660: lw          $a1, -0x74F4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X74F4);
    // 0x8004E664: jal         0x8004E6D4
    // 0x8004E668: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_8004E6D4(rdram, ctx);
        goto after_0;
    // 0x8004E668: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_0:
    // 0x8004E66C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004E670: lw          $v0, -0x74F4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X74F4);
    // 0x8004E674: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // 0x8004E678: slti        $v0, $a0, 0x4B0
    ctx->r2 = SIGNED(ctx->r4) < 0X4B0 ? 1 : 0;
    // 0x8004E67C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E680: bne         $v0, $zero, L_8004E694
    if (ctx->r2 != 0) {
        // 0x8004E684: sw          $a0, -0x74F4($at)
        MEM_W(-0X74F4, ctx->r1) = ctx->r4;
            goto L_8004E694;
    }
    // 0x8004E684: sw          $a0, -0x74F4($at)
    MEM_W(-0X74F4, ctx->r1) = ctx->r4;
    // 0x8004E688: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E68C: j           L_8004E6B4
    // 0x8004E690: sw          $s1, -0x74F4($at)
    MEM_W(-0X74F4, ctx->r1) = ctx->r17;
        goto L_8004E6B4;
    // 0x8004E690: sw          $s1, -0x74F4($at)
    MEM_W(-0X74F4, ctx->r1) = ctx->r17;
L_8004E694:
    // 0x8004E694: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8004E698: bne         $v0, $zero, L_8004E658
    if (ctx->r2 != 0) {
        // 0x8004E69C: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_8004E658;
    }
    // 0x8004E69C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8004E6A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E6A4: sw          $a0, -0x74EC($at)
    MEM_W(-0X74EC, ctx->r1) = ctx->r4;
    // 0x8004E6A8: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8004E6AC: jal         0x8004E754
    // 0x8004E6B0: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    func_8004E754(rdram, ctx);
        goto after_1;
    // 0x8004E6B0: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_1:
L_8004E6B4:
    // 0x8004E6B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004E6B8: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8004E6BC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8004E6C0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8004E6C4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8004E6C8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004E6CC: jr          $ra
    // 0x8004E6D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004E6D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8004E6D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E6D4: andi        $v1, $a1, 0x7
    ctx->r3 = ctx->r5 & 0X7;
    // 0x8004E6D8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8004E6DC: addiu       $a2, $a2, 0x3A40
    ctx->r6 = ADD32(ctx->r6, 0X3A40);
    // 0x8004E6E0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004E6E4: lw          $v0, -0x34C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34C0);
    // 0x8004E6E8: andi        $a1, $a1, 0xFFF8
    ctx->r5 = ctx->r5 & 0XFFF8;
    // 0x8004E6EC: beq         $v0, $zero, L_8004E6FC
    if (ctx->r2 == 0) {
        // 0x8004E6F0: sra         $a1, $a1, 3
        ctx->r5 = S32(SIGNED(ctx->r5) >> 3);
            goto L_8004E6FC;
    }
    // 0x8004E6F0: sra         $a1, $a1, 3
    ctx->r5 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8004E6F4: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8004E6F8: addiu       $a2, $a2, -0x2FC0
    ctx->r6 = ADD32(ctx->r6, -0X2FC0);
L_8004E6FC:
    // 0x8004E6FC: sll         $v0, $a1, 8
    ctx->r2 = S32(ctx->r5 << 8);
    // 0x8004E700: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x8004E704: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004E708: addu        $a2, $v0, $v1
    ctx->r6 = ADD32(ctx->r2, ctx->r3);
    // 0x8004E70C: andi        $v1, $a0, 0xF
    ctx->r3 = ctx->r4 & 0XF;
    // 0x8004E710: andi        $v0, $a0, 0xF0
    ctx->r2 = ctx->r4 & 0XF0;
    // 0x8004E714: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8004E718: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004E71C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004E720: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x8004E724: addiu       $v1, $v1, 0x18D8
    ctx->r3 = ADD32(ctx->r3, 0X18D8);
    // 0x8004E728: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x8004E72C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8004E730:
    // 0x8004E730: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8004E734: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x8004E738: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004E73C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8004E740: sltiu       $v0, $v1, 0x8
    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
    // 0x8004E744: bne         $v0, $zero, L_8004E730
    if (ctx->r2 != 0) {
        // 0x8004E748: addiu       $a2, $a2, 0x20
        ctx->r6 = ADD32(ctx->r6, 0X20);
            goto L_8004E730;
    }
    // 0x8004E748: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    // 0x8004E74C: jr          $ra
    // 0x8004E750: nop

    return;
    // 0x8004E750: nop

;}
RECOMP_FUNC void func_8004E754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E754: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004E758: addu        $t6, $a1, $zero
    ctx->r14 = ADD32(ctx->r5, 0);
    // 0x8004E75C: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x8004E760: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x8004E764: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // 0x8004E768: addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // 0x8004E76C: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x8004E770: ori         $a0, $a0, 0x1402
    ctx->r4 = ctx->r4 | 0X1402;
    // 0x8004E774: lui         $a2, 0xFCFF
    ctx->r6 = S32(0XFCFF << 16);
    // 0x8004E778: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x8004E77C: lui         $a1, 0xFFFC
    ctx->r5 = S32(0XFFFC << 16);
    // 0x8004E780: ori         $a1, $a1, 0xF279
    ctx->r5 = ctx->r5 | 0XF279;
    // 0x8004E784: lui         $a3, 0xBA00
    ctx->r7 = S32(0XBA00 << 16);
    // 0x8004E788: ori         $a3, $a3, 0x1301
    ctx->r7 = ctx->r7 | 0X1301;
    // 0x8004E78C: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x8004E790: ori         $t1, $t1, 0x31D
    ctx->r9 = ctx->r9 | 0X31D;
    // 0x8004E794: lui         $t0, 0xF0A
    ctx->r8 = S32(0XF0A << 16);
    // 0x8004E798: ori         $t0, $t0, 0x7008
    ctx->r8 = ctx->r8 | 0X7008;
    // 0x8004E79C: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x8004E7A0: ori         $t2, $t2, 0xE02
    ctx->r10 = ctx->r10 | 0XE02;
    // 0x8004E7A4: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x8004E7A8: ori         $t3, $t3, 0x100
    ctx->r11 = ctx->r11 | 0X100;
    // 0x8004E7AC: lui         $t4, 0x73F
    ctx->r12 = S32(0X73F << 16);
    // 0x8004E7B0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004E7B4: lw          $v1, -0x74EC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X74EC);
    // 0x8004E7B8: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x8004E7BC: lw          $t9, -0x74F0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X74F0);
    // 0x8004E7C0: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x8004E7C4: lw          $t5, 0x2FE4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2FE4);
    // 0x8004E7C8: ori         $t4, $t4, 0xC000
    ctx->r12 = ctx->r12 | 0XC000;
    // 0x8004E7CC: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8004E7D0: addiu       $t7, $t7, 0x3A40
    ctx->r15 = ADD32(ctx->r15, 0X3A40);
    // 0x8004E7D4: sw          $s2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r18;
    // 0x8004E7D8: lui         $s2, 0xE700
    ctx->r18 = S32(0XE700 << 16);
    // 0x8004E7DC: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x8004E7E0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x8004E7E4: sw          $s3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r19;
    // 0x8004E7E8: sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // 0x8004E7EC: subu        $t8, $v1, $t9
    ctx->r24 = SUB32(ctx->r3, ctx->r25);
    // 0x8004E7F0: addiu       $v0, $t5, 0x8
    ctx->r2 = ADD32(ctx->r13, 0X8);
    // 0x8004E7F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E7F8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E7FC: addiu       $v0, $t5, 0x10
    ctx->r2 = ADD32(ctx->r13, 0X10);
    // 0x8004E800: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E804: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E808: addiu       $v0, $t5, 0x18
    ctx->r2 = ADD32(ctx->r13, 0X18);
    // 0x8004E80C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E810: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E814: addiu       $v0, $t5, 0x20
    ctx->r2 = ADD32(ctx->r13, 0X20);
    // 0x8004E818: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E81C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E820: addiu       $v0, $t5, 0x28
    ctx->r2 = ADD32(ctx->r13, 0X28);
    // 0x8004E824: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E828: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E82C: addiu       $v0, $t5, 0x30
    ctx->r2 = ADD32(ctx->r13, 0X30);
    // 0x8004E830: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E834: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E838: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x8004E83C: sw          $v0, 0x2C($t5)
    MEM_W(0X2C, ctx->r13) = ctx->r2;
    // 0x8004E840: addiu       $v0, $t5, 0x38
    ctx->r2 = ADD32(ctx->r13, 0X38);
    // 0x8004E844: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E848: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E84C: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x8004E850: sw          $v0, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r2;
    // 0x8004E854: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x8004E858: addiu       $v0, $v0, 0x38E0
    ctx->r2 = ADD32(ctx->r2, 0X38E0);
    // 0x8004E85C: sw          $v0, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r2;
    // 0x8004E860: addiu       $v0, $t5, 0x40
    ctx->r2 = ADD32(ctx->r13, 0X40);
    // 0x8004E864: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E868: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E86C: lui         $v0, 0xE800
    ctx->r2 = S32(0XE800 << 16);
    // 0x8004E870: sw          $v0, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->r2;
    // 0x8004E874: addiu       $v0, $t5, 0x48
    ctx->r2 = ADD32(ctx->r13, 0X48);
    // 0x8004E878: sw          $a2, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r6;
    // 0x8004E87C: lui         $a2, 0x700
    ctx->r6 = S32(0X700 << 16);
    // 0x8004E880: sw          $s2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r18;
    // 0x8004E884: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8004E888: sw          $a0, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r4;
    // 0x8004E88C: sw          $zero, 0xC($t5)
    MEM_W(0XC, ctx->r13) = 0;
    // 0x8004E890: sw          $a1, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r5;
    // 0x8004E894: sw          $a3, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r7;
    // 0x8004E898: sw          $zero, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = 0;
    // 0x8004E89C: sw          $t1, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->r9;
    // 0x8004E8A0: sw          $t0, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->r8;
    // 0x8004E8A4: sw          $t2, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->r10;
    // 0x8004E8A8: sw          $zero, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = 0;
    // 0x8004E8AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E8B0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E8B4: addiu       $v0, $t5, 0x50
    ctx->r2 = ADD32(ctx->r13, 0X50);
    // 0x8004E8B8: lui         $a1, 0xE600
    ctx->r5 = S32(0XE600 << 16);
    // 0x8004E8BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E8C0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E8C4: addiu       $v0, $t5, 0x58
    ctx->r2 = ADD32(ctx->r13, 0X58);
    // 0x8004E8C8: sw          $t3, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->r11;
    // 0x8004E8CC: sw          $a2, 0x44($t5)
    MEM_W(0X44, ctx->r13) = ctx->r6;
    // 0x8004E8D0: sw          $a1, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->r5;
    // 0x8004E8D4: sw          $zero, 0x4C($t5)
    MEM_W(0X4C, ctx->r13) = 0;
    // 0x8004E8D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E8DC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E8E0: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x8004E8E4: sw          $v0, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->r2;
    // 0x8004E8E8: addiu       $v0, $t5, 0x60
    ctx->r2 = ADD32(ctx->r13, 0X60);
    // 0x8004E8EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E8F0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E8F4: andi        $v0, $t9, 0xFFF8
    ctx->r2 = ctx->r25 & 0XFFF8;
    // 0x8004E8F8: sra         $a0, $v0, 3
    ctx->r4 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8004E8FC: andi        $v1, $v1, 0xFFF8
    ctx->r3 = ctx->r3 & 0XFFF8;
    // 0x8004E900: sra         $v1, $v1, 3
    ctx->r3 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8004E904: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004E908: lw          $v0, -0x34C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34C0);
    // 0x8004E90C: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8004E910: addiu       $s1, $v1, 0x1
    ctx->r17 = ADD32(ctx->r3, 0X1);
    // 0x8004E914: sw          $t4, 0x54($t5)
    MEM_W(0X54, ctx->r13) = ctx->r12;
    // 0x8004E918: sw          $s2, 0x58($t5)
    MEM_W(0X58, ctx->r13) = ctx->r18;
    // 0x8004E91C: beq         $v0, $zero, L_8004E92C
    if (ctx->r2 == 0) {
        // 0x8004E920: sw          $zero, 0x5C($t5)
        MEM_W(0X5C, ctx->r13) = 0;
            goto L_8004E92C;
    }
    // 0x8004E920: sw          $zero, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = 0;
    // 0x8004E924: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004E928: addiu       $t7, $t7, -0x2FC0
    ctx->r15 = ADD32(ctx->r15, -0X2FC0);
L_8004E92C:
    // 0x8004E92C: sll         $v0, $a0, 8
    ctx->r2 = S32(ctx->r4 << 8);
    // 0x8004E930: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x8004E934: sll         $v0, $s1, 9
    ctx->r2 = S32(ctx->r17 << 9);
    // 0x8004E938: sra         $v0, $v0, 2
    ctx->r2 = S32(SIGNED(ctx->r2) >> 2);
    // 0x8004E93C: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x8004E940: addiu       $v0, $t5, 0x68
    ctx->r2 = ADD32(ctx->r13, 0X68);
    // 0x8004E944: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E948: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E94C: lui         $v0, 0xFD50
    ctx->r2 = S32(0XFD50 << 16);
    // 0x8004E950: sw          $v0, 0x60($t5)
    MEM_W(0X60, ctx->r13) = ctx->r2;
    // 0x8004E954: addiu       $v0, $t5, 0x70
    ctx->r2 = ADD32(ctx->r13, 0X70);
    // 0x8004E958: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E95C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E960: lui         $v0, 0xF550
    ctx->r2 = S32(0XF550 << 16);
    // 0x8004E964: sw          $v0, 0x68($t5)
    MEM_W(0X68, ctx->r13) = ctx->r2;
    // 0x8004E968: addiu       $v0, $t5, 0x78
    ctx->r2 = ADD32(ctx->r13, 0X78);
    // 0x8004E96C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E970: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E974: addiu       $v0, $t5, 0x80
    ctx->r2 = ADD32(ctx->r13, 0X80);
    // 0x8004E978: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004E97C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004E980: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x8004E984: sw          $v0, 0x78($t5)
    MEM_W(0X78, ctx->r13) = ctx->r2;
    // 0x8004E988: slti        $v0, $t2, 0x800
    ctx->r2 = SIGNED(ctx->r10) < 0X800 ? 1 : 0;
    // 0x8004E98C: sw          $t7, 0x64($t5)
    MEM_W(0X64, ctx->r13) = ctx->r15;
    // 0x8004E990: sw          $a2, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = ctx->r6;
    // 0x8004E994: sw          $a1, 0x70($t5)
    MEM_W(0X70, ctx->r13) = ctx->r5;
    // 0x8004E998: bne         $v0, $zero, L_8004E9A4
    if (ctx->r2 != 0) {
        // 0x8004E99C: sw          $zero, 0x74($t5)
        MEM_W(0X74, ctx->r13) = 0;
            goto L_8004E9A4;
    }
    // 0x8004E99C: sw          $zero, 0x74($t5)
    MEM_W(0X74, ctx->r13) = 0;
    // 0x8004E9A0: addiu       $t2, $zero, 0x7FF
    ctx->r10 = ADD32(0, 0X7FF);
L_8004E9A4:
    // 0x8004E9A4: lui         $a0, 0x700
    ctx->r4 = S32(0X700 << 16);
    // 0x8004E9A8: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x8004E9AC: lui         $a1, 0xF540
    ctx->r5 = S32(0XF540 << 16);
    // 0x8004E9B0: ori         $a1, $a1, 0x800
    ctx->r5 = ctx->r5 | 0X800;
    // 0x8004E9B4: lui         $a2, 0xF
    ctx->r6 = S32(0XF << 16);
    // 0x8004E9B8: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x8004E9BC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8004E9C0: andi        $t3, $t9, 0x7
    ctx->r11 = ctx->r25 & 0X7;
    // 0x8004E9C4: addu        $t0, $t3, $zero
    ctx->r8 = ADD32(ctx->r11, 0);
    // 0x8004E9C8: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8004E9CC: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
    // 0x8004E9D0: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x8004E9D4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004E9D8: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8004E9DC: lui         $v1, 0xE400
    ctx->r3 = S32(0XE400 << 16);
    // 0x8004E9E0: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8004E9E4: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x8004E9E8: andi        $t7, $v0, 0xFFF
    ctx->r15 = ctx->r2 & 0XFFF;
    // 0x8004E9EC: lui         $s4, 0xB400
    ctx->r20 = S32(0XB400 << 16);
    // 0x8004E9F0: lui         $s3, 0xB300
    ctx->r19 = S32(0XB300 << 16);
    // 0x8004E9F4: lui         $t4, 0x400
    ctx->r12 = S32(0X400 << 16);
    // 0x8004E9F8: ori         $t4, $t4, 0x400
    ctx->r12 = ctx->r12 | 0X400;
    // 0x8004E9FC: andi        $v0, $t2, 0xFFF
    ctx->r2 = ctx->r10 & 0XFFF;
    // 0x8004EA00: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8004EA04: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8004EA08: sw          $v0, 0x7C($t5)
    MEM_W(0X7C, ctx->r13) = ctx->r2;
    // 0x8004EA0C: addiu       $v0, $t5, 0x88
    ctx->r2 = ADD32(ctx->r13, 0X88);
    // 0x8004EA10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EA14: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004EA18: addiu       $v0, $t5, 0x90
    ctx->r2 = ADD32(ctx->r13, 0X90);
    // 0x8004EA1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EA20: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004EA24: andi        $v0, $s6, 0xF
    ctx->r2 = ctx->r22 & 0XF;
    // 0x8004EA28: sll         $v0, $v0, 20
    ctx->r2 = S32(ctx->r2 << 20);
    // 0x8004EA2C: sw          $v0, 0x8C($t5)
    MEM_W(0X8C, ctx->r13) = ctx->r2;
    // 0x8004EA30: addiu       $v0, $t5, 0x98
    ctx->r2 = ADD32(ctx->r13, 0X98);
    // 0x8004EA34: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EA38: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004EA3C: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x8004EA40: sw          $v0, 0x90($t5)
    MEM_W(0X90, ctx->r13) = ctx->r2;
    // 0x8004EA44: sll         $v0, $s1, 5
    ctx->r2 = S32(ctx->r17 << 5);
    // 0x8004EA48: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8004EA4C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8004EA50: or          $v0, $v0, $a2
    ctx->r2 = ctx->r2 | ctx->r6;
    // 0x8004EA54: sw          $s2, 0x80($t5)
    MEM_W(0X80, ctx->r13) = ctx->r18;
    // 0x8004EA58: sw          $zero, 0x84($t5)
    MEM_W(0X84, ctx->r13) = 0;
    // 0x8004EA5C: sw          $a1, 0x88($t5)
    MEM_W(0X88, ctx->r13) = ctx->r5;
    // 0x8004EA60: sw          $v0, 0x94($t5)
    MEM_W(0X94, ctx->r13) = ctx->r2;
    // 0x8004EA64: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_8004EA68:
    // 0x8004EA68: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8004EA6C: bne         $t0, $s5, L_8004EB04
    if (ctx->r8 != ctx->r21) {
        // 0x8004EA70: addiu       $t8, $t8, -0x1
        ctx->r24 = ADD32(ctx->r24, -0X1);
            goto L_8004EB04;
    }
    // 0x8004EA70: addiu       $t8, $t8, -0x1
    ctx->r24 = ADD32(ctx->r24, -0X1);
    // 0x8004EA74: sll         $v0, $a3, 3
    ctx->r2 = S32(ctx->r7 << 3);
    // 0x8004EA78: addu        $v0, $t6, $v0
    ctx->r2 = ADD32(ctx->r14, ctx->r2);
    // 0x8004EA7C: sll         $a0, $t6, 2
    ctx->r4 = S32(ctx->r14 << 2);
    // 0x8004EA80: addu        $t6, $v0, $zero
    ctx->r14 = ADD32(ctx->r2, 0);
    // 0x8004EA84: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8004EA88: sll         $a2, $t1, 8
    ctx->r6 = S32(ctx->r9 << 8);
    // 0x8004EA8C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8004EA90: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x8004EA94: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004EA98: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8004EA9C: sll         $a1, $t3, 24
    ctx->r5 = S32(ctx->r11 << 24);
    // 0x8004EAA0: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // 0x8004EAA4: andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // 0x8004EAA8: sll         $a0, $a0, 12
    ctx->r4 = S32(ctx->r4 << 12);
    // 0x8004EAAC: or          $a0, $a0, $t7
    ctx->r4 = ctx->r4 | ctx->r15;
    // 0x8004EAB0: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8004EAB4: or          $a1, $a1, $a2
    ctx->r5 = ctx->r5 | ctx->r6;
    // 0x8004EAB8: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8004EABC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EAC0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004EAC4: sll         $v0, $t6, 2
    ctx->r2 = S32(ctx->r14 << 2);
    // 0x8004EAC8: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8004EACC: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8004EAD0: or          $v0, $v0, $t9
    ctx->r2 = ctx->r2 | ctx->r25;
    // 0x8004EAD4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004EAD8: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8004EADC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EAE0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004EAE4: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8004EAE8: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x8004EAEC: sw          $s4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r20;
    // 0x8004EAF0: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x8004EAF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EAF8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004EAFC: sw          $s3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r19;
    // 0x8004EB00: sw          $t4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r12;
L_8004EB04:
    // 0x8004EB04: bnel        $t8, $zero, L_8004EA68
    if (ctx->r24 != 0) {
        // 0x8004EB08: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8004EA68;
    }
    goto skip_0;
    // 0x8004EB08: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_0:
    // 0x8004EB0C: beq         $a3, $zero, L_8004EBB8
    if (ctx->r7 == 0) {
        // 0x8004EB10: lui         $a2, 0x400
        ctx->r6 = S32(0X400 << 16);
            goto L_8004EBB8;
    }
    // 0x8004EB10: lui         $a2, 0x400
    ctx->r6 = S32(0X400 << 16);
    // 0x8004EB14: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8004EB18: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x8004EB1C: ori         $a2, $a2, 0x400
    ctx->r6 = ctx->r6 | 0X400;
    // 0x8004EB20: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    // 0x8004EB24: addu        $v1, $t6, $v1
    ctx->r3 = ADD32(ctx->r14, ctx->r3);
    // 0x8004EB28: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004EB2C: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8004EB30: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x8004EB34: lui         $a0, 0xE400
    ctx->r4 = S32(0XE400 << 16);
    // 0x8004EB38: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x8004EB3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EB40: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004EB44: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x8004EB48: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004EB4C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8004EB50: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8004EB54: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8004EB58: sll         $v0, $t6, 2
    ctx->r2 = S32(ctx->r14 << 2);
    // 0x8004EB5C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8004EB60: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8004EB64: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x8004EB68: sll         $v1, $s0, 2
    ctx->r3 = S32(ctx->r16 << 2);
    // 0x8004EB6C: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8004EB70: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8004EB74: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8004EB78: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x8004EB7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EB80: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004EB84: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x8004EB88: sll         $v1, $t3, 24
    ctx->r3 = S32(ctx->r11 << 24);
    // 0x8004EB8C: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x8004EB90: sll         $v0, $t1, 8
    ctx->r2 = S32(ctx->r9 << 8);
    // 0x8004EB94: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8004EB98: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8004EB9C: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x8004EBA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EBA4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004EBA8: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x8004EBAC: sw          $v1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r3;
    // 0x8004EBB0: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x8004EBB4: sw          $a2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r6;
L_8004EBB8:
    // 0x8004EBB8: lw          $s6, 0x18($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X18);
    // 0x8004EBBC: lw          $s5, 0x14($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X14);
    // 0x8004EBC0: lw          $s4, 0x10($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X10);
    // 0x8004EBC4: lw          $s3, 0xC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XC);
    // 0x8004EBC8: lw          $s2, 0x8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X8);
    // 0x8004EBCC: lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4);
    // 0x8004EBD0: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x8004EBD4: jr          $ra
    // 0x8004EBD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8004EBD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8004EBE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004EBE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EBE4: sw          $zero, -0x74D0($at)
    MEM_W(-0X74D0, ctx->r1) = 0;
    // 0x8004EBE8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EBEC: jr          $ra
    // 0x8004EBF0: sw          $zero, -0x74C4($at)
    MEM_W(-0X74C4, ctx->r1) = 0;
    return;
    // 0x8004EBF0: sw          $zero, -0x74C4($at)
    MEM_W(-0X74C4, ctx->r1) = 0;
;}
RECOMP_FUNC void func_8004EBF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004EBF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004EBF8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8004EBFC: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8004EC00: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004EC04: addiu       $a0, $a0, 0x3AE0
    ctx->r4 = ADD32(ctx->r4, 0X3AE0);
    // 0x8004EC08: jal         0x8004EC44
    // 0x8004EC0C: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_8004EC44(rdram, ctx);
        goto after_0;
    // 0x8004EC0C: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_0:
    // 0x8004EC10: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8004EC14: jr          $ra
    // 0x8004EC18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8004EC18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8004EC1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004EC1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004EC20: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8004EC24: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8004EC28: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004EC2C: addiu       $a0, $a0, 0x3AE0
    ctx->r4 = ADD32(ctx->r4, 0X3AE0);
    // 0x8004EC30: jal         0x8004F1A4
    // 0x8004EC34: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_8004F1A4(rdram, ctx);
        goto after_0;
    // 0x8004EC34: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_0:
    // 0x8004EC38: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8004EC3C: jr          $ra
    // 0x8004EC40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8004EC40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8004EC44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004EC44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004EC48: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004EC4C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8004EC50: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8004EC54: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8004EC58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004EC5C: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8004EC60: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8004EC64: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8004EC68: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8004EC6C: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8004EC70: beq         $v0, $zero, L_8004ECE4
    if (ctx->r2 == 0) {
        // 0x8004EC74: addu        $s4, $a3, $zero
        ctx->r20 = ADD32(ctx->r7, 0);
            goto L_8004ECE4;
    }
    // 0x8004EC74: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x8004EC78: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x8004EC7C: lw          $s1, -0x74D0($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X74D0);
    // 0x8004EC80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EC84: sw          $s1, -0x74CC($at)
    MEM_W(-0X74CC, ctx->r1) = ctx->r17;
L_8004EC88:
    // 0x8004EC88: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x8004EC8C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8004EC90: lw          $a1, -0x74D0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X74D0);
    // 0x8004EC94: jal         0x8004F148
    // 0x8004EC98: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_8004F148(rdram, ctx);
        goto after_0;
    // 0x8004EC98: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_0:
    // 0x8004EC9C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004ECA0: lw          $v0, -0x74D0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X74D0);
    // 0x8004ECA4: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // 0x8004ECA8: slti        $v0, $a0, 0x60
    ctx->r2 = SIGNED(ctx->r4) < 0X60 ? 1 : 0;
    // 0x8004ECAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004ECB0: bne         $v0, $zero, L_8004ECC4
    if (ctx->r2 != 0) {
        // 0x8004ECB4: sw          $a0, -0x74D0($at)
        MEM_W(-0X74D0, ctx->r1) = ctx->r4;
            goto L_8004ECC4;
    }
    // 0x8004ECB4: sw          $a0, -0x74D0($at)
    MEM_W(-0X74D0, ctx->r1) = ctx->r4;
    // 0x8004ECB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004ECBC: j           L_8004ECE4
    // 0x8004ECC0: sw          $s1, -0x74D0($at)
    MEM_W(-0X74D0, ctx->r1) = ctx->r17;
        goto L_8004ECE4;
    // 0x8004ECC0: sw          $s1, -0x74D0($at)
    MEM_W(-0X74D0, ctx->r1) = ctx->r17;
L_8004ECC4:
    // 0x8004ECC4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8004ECC8: bne         $v0, $zero, L_8004EC88
    if (ctx->r2 != 0) {
        // 0x8004ECCC: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_8004EC88;
    }
    // 0x8004ECCC: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8004ECD0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004ECD4: sw          $a0, -0x74C8($at)
    MEM_W(-0X74C8, ctx->r1) = ctx->r4;
    // 0x8004ECD8: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8004ECDC: jal         0x8004ED04
    // 0x8004ECE0: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    func_8004ED04(rdram, ctx);
        goto after_1;
    // 0x8004ECE0: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_1:
L_8004ECE4:
    // 0x8004ECE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004ECE8: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8004ECEC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8004ECF0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8004ECF4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8004ECF8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004ECFC: jr          $ra
    // 0x8004ED00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004ED00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8004ED04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004ED04: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004ED08: addu        $t7, $a1, $zero
    ctx->r15 = ADD32(ctx->r5, 0);
    // 0x8004ED0C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8004ED10: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8004ED14: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x8004ED18: ori         $a0, $a0, 0x1402
    ctx->r4 = ctx->r4 | 0X1402;
    // 0x8004ED1C: lui         $a2, 0xFCFF
    ctx->r6 = S32(0XFCFF << 16);
    // 0x8004ED20: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x8004ED24: lui         $a1, 0xFFFC
    ctx->r5 = S32(0XFFFC << 16);
    // 0x8004ED28: ori         $a1, $a1, 0xF279
    ctx->r5 = ctx->r5 | 0XF279;
    // 0x8004ED2C: lui         $t0, 0xBA00
    ctx->r8 = S32(0XBA00 << 16);
    // 0x8004ED30: ori         $t0, $t0, 0x1301
    ctx->r8 = ctx->r8 | 0X1301;
    // 0x8004ED34: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x8004ED38: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x8004ED3C: lui         $t1, 0xF0A
    ctx->r9 = S32(0XF0A << 16);
    // 0x8004ED40: ori         $t1, $t1, 0x7008
    ctx->r9 = ctx->r9 | 0X7008;
    // 0x8004ED44: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x8004ED48: ori         $t3, $t3, 0xE02
    ctx->r11 = ctx->r11 | 0XE02;
    // 0x8004ED4C: lui         $t5, 0xF500
    ctx->r13 = S32(0XF500 << 16);
    // 0x8004ED50: ori         $t5, $t5, 0x100
    ctx->r13 = ctx->r13 | 0X100;
    // 0x8004ED54: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004ED58: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x8004ED5C: lui         $t6, 0x703
    ctx->r14 = S32(0X703 << 16);
    // 0x8004ED60: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x8004ED64: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004ED68: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8004ED6C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8004ED70: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004ED74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004ED78: sw          $a1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r5;
    // 0x8004ED7C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8004ED80: lw          $a1, -0x74C8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X74C8);
    // 0x8004ED84: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8004ED88: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8004ED8C: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x8004ED90: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8004ED94: lw          $a0, -0x74CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X74CC);
    // 0x8004ED98: sll         $a3, $a3, 5
    ctx->r7 = S32(ctx->r7 << 5);
    // 0x8004ED9C: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8004EDA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EDA4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004EDA8: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x8004EDAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EDB0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004EDB4: addiu       $v1, $v0, 0x18
    ctx->r3 = ADD32(ctx->r2, 0X18);
    // 0x8004EDB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EDBC: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004EDC0: addiu       $v1, $v0, 0x20
    ctx->r3 = ADD32(ctx->r2, 0X20);
    // 0x8004EDC4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EDC8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004EDCC: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x8004EDD0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EDD4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004EDD8: addiu       $v1, $v0, 0x30
    ctx->r3 = ADD32(ctx->r2, 0X30);
    // 0x8004EDDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EDE0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004EDE4: ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // 0x8004EDE8: sw          $v1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r3;
    // 0x8004EDEC: addiu       $v1, $v0, 0x38
    ctx->r3 = ADD32(ctx->r2, 0X38);
    // 0x8004EDF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EDF4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004EDF8: lui         $v1, 0xFD10
    ctx->r3 = S32(0XFD10 << 16);
    // 0x8004EDFC: sw          $v1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r3;
    // 0x8004EE00: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8004EE04: addiu       $v1, $v1, 0x5198
    ctx->r3 = ADD32(ctx->r3, 0X5198);
    // 0x8004EE08: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x8004EE0C: addiu       $v1, $v0, 0x40
    ctx->r3 = ADD32(ctx->r2, 0X40);
    // 0x8004EE10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EE14: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004EE18: lui         $v1, 0xE800
    ctx->r3 = S32(0XE800 << 16);
    // 0x8004EE1C: sw          $v1, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r3;
    // 0x8004EE20: addiu       $v1, $v0, 0x48
    ctx->r3 = ADD32(ctx->r2, 0X48);
    // 0x8004EE24: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8004EE28: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8004EE2C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8004EE30: sw          $a2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r6;
    // 0x8004EE34: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
    // 0x8004EE38: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x8004EE3C: sw          $t2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r10;
    // 0x8004EE40: sw          $t1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r9;
    // 0x8004EE44: sw          $t3, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r11;
    // 0x8004EE48: sw          $a3, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r7;
    // 0x8004EE4C: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8004EE50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EE54: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004EE58: lui         $v1, 0x700
    ctx->r3 = S32(0X700 << 16);
    // 0x8004EE5C: sw          $v1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r3;
    // 0x8004EE60: addiu       $v1, $v0, 0x50
    ctx->r3 = ADD32(ctx->r2, 0X50);
    // 0x8004EE64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EE68: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004EE6C: lui         $v1, 0xE600
    ctx->r3 = S32(0XE600 << 16);
    // 0x8004EE70: sw          $v1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r3;
    // 0x8004EE74: addiu       $v1, $v0, 0x58
    ctx->r3 = ADD32(ctx->r2, 0X58);
    // 0x8004EE78: sw          $t5, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r13;
    // 0x8004EE7C: sw          $zero, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = 0;
    // 0x8004EE80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EE84: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004EE88: lui         $v1, 0xF000
    ctx->r3 = S32(0XF000 << 16);
    // 0x8004EE8C: sw          $v1, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r3;
    // 0x8004EE90: addiu       $v1, $v0, 0x60
    ctx->r3 = ADD32(ctx->r2, 0X60);
    // 0x8004EE94: sw          $t6, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r14;
    // 0x8004EE98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EE9C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004EEA0: sw          $t4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r12;
    // 0x8004EEA4: subu        $s2, $a1, $a0
    ctx->r18 = SUB32(ctx->r5, ctx->r4);
    // 0x8004EEA8: blez        $s2, L_8004F008
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8004EEAC: sw          $zero, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = 0;
            goto L_8004F008;
    }
    // 0x8004EEAC: sw          $zero, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = 0;
    // 0x8004EEB0: addiu       $v1, $s3, 0x10
    ctx->r3 = ADD32(ctx->r19, 0X10);
    // 0x8004EEB4: slti        $v1, $v1, 0x1
    ctx->r3 = SIGNED(ctx->r3) < 0X1 ? 1 : 0;
    // 0x8004EEB8: slti        $v0, $s3, 0xF0
    ctx->r2 = SIGNED(ctx->r19) < 0XF0 ? 1 : 0;
    // 0x8004EEBC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8004EEC0: or          $s4, $v1, $v0
    ctx->r20 = ctx->r3 | ctx->r2;
L_8004EEC4:
    // 0x8004EEC4: addiu       $s0, $t7, 0x10
    ctx->r16 = ADD32(ctx->r15, 0X10);
    // 0x8004EEC8: slti        $v1, $s0, 0x1
    ctx->r3 = SIGNED(ctx->r16) < 0X1 ? 1 : 0;
    // 0x8004EECC: slti        $v0, $t7, 0x140
    ctx->r2 = SIGNED(ctx->r15) < 0X140 ? 1 : 0;
    // 0x8004EED0: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8004EED4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8004EED8: or          $v1, $v1, $s4
    ctx->r3 = ctx->r3 | ctx->r20;
    // 0x8004EEDC: bne         $v1, $zero, L_8004EFE4
    if (ctx->r3 != 0) {
        // 0x8004EEE0: lui         $a2, 0x703
        ctx->r6 = S32(0X703 << 16);
            goto L_8004EFE4;
    }
    // 0x8004EEE0: lui         $a2, 0x703
    ctx->r6 = S32(0X703 << 16);
    // 0x8004EEE4: ori         $a2, $a2, 0xF800
    ctx->r6 = ctx->r6 | 0XF800;
    // 0x8004EEE8: lui         $a3, 0xF540
    ctx->r7 = S32(0XF540 << 16);
    // 0x8004EEEC: ori         $a3, $a3, 0x200
    ctx->r7 = ctx->r7 | 0X200;
    // 0x8004EEF0: lui         $t0, 0x3
    ctx->r8 = S32(0X3 << 16);
    // 0x8004EEF4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8004EEF8: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x8004EEFC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004EF00: lw          $v1, -0x34C0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X34C0);
    // 0x8004EF04: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8004EF08: lw          $a0, -0x74CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X74CC);
    // 0x8004EF0C: ori         $t0, $t0, 0xC03C
    ctx->r8 = ctx->r8 | 0XC03C;
    // 0x8004EF10: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x8004EF14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EF18: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004EF1C: lui         $v0, 0xFD50
    ctx->r2 = S32(0XFD50 << 16);
    // 0x8004EF20: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8004EF24: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004EF28: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004EF2C: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8004EF30: sll         $a0, $a0, 7
    ctx->r4 = S32(ctx->r4 << 7);
    // 0x8004EF34: lui         $v1, 0x8028
    ctx->r3 = S32(0X8028 << 16);
    // 0x8004EF38: addiu       $v1, $v1, 0x1800
    ctx->r3 = ADD32(ctx->r3, 0X1800);
    // 0x8004EF3C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8004EF40: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004EF44: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8004EF48: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x8004EF4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EF50: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004EF54: lui         $v0, 0xF550
    ctx->r2 = S32(0XF550 << 16);
    // 0x8004EF58: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x8004EF5C: lui         $v0, 0x700
    ctx->r2 = S32(0X700 << 16);
    // 0x8004EF60: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x8004EF64: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x8004EF68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EF6C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004EF70: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x8004EF74: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x8004EF78: addiu       $v0, $a1, 0x20
    ctx->r2 = ADD32(ctx->r5, 0X20);
    // 0x8004EF7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EF80: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004EF84: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x8004EF88: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    // 0x8004EF8C: addiu       $v0, $a1, 0x28
    ctx->r2 = ADD32(ctx->r5, 0X28);
    // 0x8004EF90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EF94: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004EF98: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x8004EF9C: sw          $v0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r2;
    // 0x8004EFA0: addiu       $v0, $a1, 0x30
    ctx->r2 = ADD32(ctx->r5, 0X30);
    // 0x8004EFA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EFA8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004EFAC: addiu       $v0, $a1, 0x38
    ctx->r2 = ADD32(ctx->r5, 0X38);
    // 0x8004EFB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EFB4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004EFB8: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x8004EFBC: addu        $a0, $t7, $zero
    ctx->r4 = ADD32(ctx->r15, 0);
    // 0x8004EFC0: sw          $zero, 0x14($a1)
    MEM_W(0X14, ctx->r5) = 0;
    // 0x8004EFC4: sw          $a2, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r6;
    // 0x8004EFC8: sw          $zero, 0x24($a1)
    MEM_W(0X24, ctx->r5) = 0;
    // 0x8004EFCC: sw          $a3, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r7;
    // 0x8004EFD0: sw          $zero, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = 0;
    // 0x8004EFD4: sw          $v0, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r2;
    // 0x8004EFD8: sw          $t0, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r8;
    // 0x8004EFDC: jal         0x8004F028
    // 0x8004EFE0: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8004F028(rdram, ctx);
        goto after_0;
    // 0x8004EFE0: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_0:
L_8004EFE4:
    // 0x8004EFE4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004EFE8: lw          $v0, -0x74CC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X74CC);
    // 0x8004EFEC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8004EFF0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004EFF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004EFF8: sw          $v0, -0x74CC($at)
    MEM_W(-0X74CC, ctx->r1) = ctx->r2;
    // 0x8004EFFC: slt         $v0, $s1, $s2
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8004F000: bne         $v0, $zero, L_8004EEC4
    if (ctx->r2 != 0) {
        // 0x8004F004: addu        $t7, $s0, $zero
        ctx->r15 = ADD32(ctx->r16, 0);
            goto L_8004EEC4;
    }
    // 0x8004F004: addu        $t7, $s0, $zero
    ctx->r15 = ADD32(ctx->r16, 0);
L_8004F008:
    // 0x8004F008: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004F00C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8004F010: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8004F014: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8004F018: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8004F01C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004F020: jr          $ra
    // 0x8004F024: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8004F024: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8004F028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F028: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x8004F02C: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x8004F030: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x8004F034: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8004F038: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8004F03C: bgez        $a3, L_8004F05C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8004F040: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8004F05C;
    }
    // 0x8004F040: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8004F044: addiu       $v1, $a3, 0x10
    ctx->r3 = ADD32(ctx->r7, 0X10);
    // 0x8004F048: bgez        $a3, L_8004F054
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8004F04C: addu        $t1, $a3, $zero
        ctx->r9 = ADD32(ctx->r7, 0);
            goto L_8004F054;
    }
    // 0x8004F04C: addu        $t1, $a3, $zero
    ctx->r9 = ADD32(ctx->r7, 0);
    // 0x8004F050: negu        $t1, $t1
    ctx->r9 = SUB32(0, ctx->r9);
L_8004F054:
    // 0x8004F054: j           L_8004F070
    // 0x8004F058: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_8004F070;
    // 0x8004F058: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8004F05C:
    // 0x8004F05C: addiu       $v0, $a3, 0x10
    ctx->r2 = ADD32(ctx->r7, 0X10);
    // 0x8004F060: slti        $v0, $v0, 0x140
    ctx->r2 = SIGNED(ctx->r2) < 0X140 ? 1 : 0;
    // 0x8004F064: bne         $v0, $zero, L_8004F070
    if (ctx->r2 != 0) {
        // 0x8004F068: addiu       $v0, $zero, 0x140
        ctx->r2 = ADD32(0, 0X140);
            goto L_8004F070;
    }
    // 0x8004F068: addiu       $v0, $zero, 0x140
    ctx->r2 = ADD32(0, 0X140);
    // 0x8004F06C: subu        $v1, $v0, $a3
    ctx->r3 = SUB32(ctx->r2, ctx->r7);
L_8004F070:
    // 0x8004F070: bgez        $t0, L_8004F090
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8004F074: addiu       $v0, $t0, 0x10
        ctx->r2 = ADD32(ctx->r8, 0X10);
            goto L_8004F090;
    }
    // 0x8004F074: addiu       $v0, $t0, 0x10
    ctx->r2 = ADD32(ctx->r8, 0X10);
    // 0x8004F078: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8004F07C: bgez        $t0, L_8004F088
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8004F080: addu        $t2, $t0, $zero
        ctx->r10 = ADD32(ctx->r8, 0);
            goto L_8004F088;
    }
    // 0x8004F080: addu        $t2, $t0, $zero
    ctx->r10 = ADD32(ctx->r8, 0);
    // 0x8004F084: negu        $t2, $t2
    ctx->r10 = SUB32(0, ctx->r10);
L_8004F088:
    // 0x8004F088: j           L_8004F0A0
    // 0x8004F08C: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
        goto L_8004F0A0;
    // 0x8004F08C: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
L_8004F090:
    // 0x8004F090: slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // 0x8004F094: bne         $v0, $zero, L_8004F0A0
    if (ctx->r2 != 0) {
        // 0x8004F098: addiu       $v0, $zero, 0xF0
        ctx->r2 = ADD32(0, 0XF0);
            goto L_8004F0A0;
    }
    // 0x8004F098: addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // 0x8004F09C: subu        $a0, $v0, $t0
    ctx->r4 = SUB32(ctx->r2, ctx->r8);
L_8004F0A0:
    // 0x8004F0A0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8004F0A4: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x8004F0A8: lui         $a2, 0x400
    ctx->r6 = S32(0X400 << 16);
    // 0x8004F0AC: ori         $a2, $a2, 0x400
    ctx->r6 = ctx->r6 | 0X400;
    // 0x8004F0B0: addu        $v1, $a3, $v1
    ctx->r3 = ADD32(ctx->r7, ctx->r3);
    // 0x8004F0B4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004F0B8: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8004F0BC: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x8004F0C0: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x8004F0C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F0C8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004F0CC: addu        $v0, $t0, $a0
    ctx->r2 = ADD32(ctx->r8, ctx->r4);
    // 0x8004F0D0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004F0D4: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8004F0D8: lui         $a0, 0xE400
    ctx->r4 = S32(0XE400 << 16);
    // 0x8004F0DC: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8004F0E0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8004F0E4: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x8004F0E8: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8004F0EC: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8004F0F0: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x8004F0F4: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8004F0F8: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8004F0FC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8004F100: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8004F104: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x8004F108: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F10C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004F110: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x8004F114: sll         $v1, $t1, 21
    ctx->r3 = S32(ctx->r9 << 21);
    // 0x8004F118: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x8004F11C: sll         $v0, $t2, 5
    ctx->r2 = S32(ctx->r10 << 5);
    // 0x8004F120: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8004F124: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8004F128: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x8004F12C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F130: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004F134: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x8004F138: sw          $v1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r3;
    // 0x8004F13C: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x8004F140: jr          $ra
    // 0x8004F144: sw          $a2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r6;
    return;
    // 0x8004F144: sw          $a2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r6;
;}
RECOMP_FUNC void func_8004F148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004F14C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004F150: lw          $v1, -0x34C0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X34C0);
    // 0x8004F154: lui         $a2, 0x6D
    ctx->r6 = S32(0X6D << 16);
    // 0x8004F158: addiu       $a2, $a2, -0x4450
    ctx->r6 = ADD32(ctx->r6, -0X4450);
    // 0x8004F15C: sll         $a1, $a1, 7
    ctx->r5 = S32(ctx->r5 << 7);
    // 0x8004F160: addiu       $a0, $a0, -0x20
    ctx->r4 = ADD32(ctx->r4, -0X20);
    // 0x8004F164: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8004F168: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8004F16C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8004F170: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8004F174: lui         $v1, 0x8028
    ctx->r3 = S32(0X8028 << 16);
    // 0x8004F178: addiu       $v1, $v1, 0x1800
    ctx->r3 = ADD32(ctx->r3, 0X1800);
    // 0x8004F17C: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x8004F180: bltz        $a0, L_8004F198
    if (SIGNED(ctx->r4) < 0) {
        // 0x8004F184: addu        $a1, $v0, $a1
        ctx->r5 = ADD32(ctx->r2, ctx->r5);
            goto L_8004F198;
    }
    // 0x8004F184: addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    // 0x8004F188: sll         $a0, $a0, 7
    ctx->r4 = S32(ctx->r4 << 7);
    // 0x8004F18C: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x8004F190: jal         0x80006D98
    // 0x8004F194: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_80006D98(rdram, ctx);
        goto after_0;
    // 0x8004F194: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_0:
L_8004F198:
    // 0x8004F198: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8004F19C: jr          $ra
    // 0x8004F1A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8004F1A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8004F1A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F1A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004F1A8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004F1AC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8004F1B0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8004F1B4: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x8004F1B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004F1BC: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8004F1C0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8004F1C4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8004F1C8: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8004F1CC: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8004F1D0: beq         $v0, $zero, L_8004F24C
    if (ctx->r2 == 0) {
        // 0x8004F1D4: addu        $s4, $a3, $zero
        ctx->r20 = ADD32(ctx->r7, 0);
            goto L_8004F24C;
    }
    // 0x8004F1D4: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x8004F1D8: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x8004F1DC: lw          $s1, -0x74C4($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X74C4);
    // 0x8004F1E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F1E4: sw          $s1, -0x74C0($at)
    MEM_W(-0X74C0, ctx->r1) = ctx->r17;
L_8004F1E8:
    // 0x8004F1E8: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x8004F1EC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8004F1F0: lw          $a1, -0x74C4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X74C4);
    // 0x8004F1F4: jal         0x8004F26C
    // 0x8004F1F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_8004F26C(rdram, ctx);
        goto after_0;
    // 0x8004F1F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_0:
    // 0x8004F1FC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004F200: lw          $v0, -0x74C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X74C4);
    // 0x8004F204: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8004F208: slti        $v0, $v1, 0x80
    ctx->r2 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x8004F20C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F210: bne         $v0, $zero, L_8004F224
    if (ctx->r2 != 0) {
        // 0x8004F214: sw          $v1, -0x74C4($at)
        MEM_W(-0X74C4, ctx->r1) = ctx->r3;
            goto L_8004F224;
    }
    // 0x8004F214: sw          $v1, -0x74C4($at)
    MEM_W(-0X74C4, ctx->r1) = ctx->r3;
    // 0x8004F218: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F21C: j           L_8004F24C
    // 0x8004F220: sw          $s1, -0x74C4($at)
    MEM_W(-0X74C4, ctx->r1) = ctx->r17;
        goto L_8004F24C;
    // 0x8004F220: sw          $s1, -0x74C4($at)
    MEM_W(-0X74C4, ctx->r1) = ctx->r17;
L_8004F224:
    // 0x8004F224: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8004F228: bne         $v0, $zero, L_8004F1E8
    if (ctx->r2 != 0) {
        // 0x8004F22C: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_8004F1E8;
    }
    // 0x8004F22C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8004F230: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8004F234: lw          $a0, -0x74D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X74D0);
    // 0x8004F238: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8004F23C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F240: sw          $v1, -0x74BC($at)
    MEM_W(-0X74BC, ctx->r1) = ctx->r3;
    // 0x8004F244: jal         0x8004F2D4
    // 0x8004F248: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    func_8004F2D4(rdram, ctx);
        goto after_1;
    // 0x8004F248: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_1:
L_8004F24C:
    // 0x8004F24C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004F250: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8004F254: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8004F258: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8004F25C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8004F260: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004F264: jr          $ra
    // 0x8004F268: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004F268: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8004F26C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F26C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004F270: lw          $v0, -0x34C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34C0);
    // 0x8004F274: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004F278: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x8004F27C: bne         $v0, $zero, L_8004F294
    if (ctx->r2 != 0) {
        // 0x8004F280: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8004F294;
    }
    // 0x8004F280: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8004F284: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8004F288: lw          $a1, 0x491C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X491C);
    // 0x8004F28C: j           L_8004F2A4
    // 0x8004F290: sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3 << 7);
        goto L_8004F2A4;
    // 0x8004F290: sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3 << 7);
L_8004F294:
    // 0x8004F294: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8004F298: lw          $v0, 0x491C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X491C);
    // 0x8004F29C: addiu       $a1, $v0, 0x4000
    ctx->r5 = ADD32(ctx->r2, 0X4000);
    // 0x8004F2A0: sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3 << 7);
L_8004F2A4:
    // 0x8004F2A4: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8004F2A8: lui         $v0, 0x6D
    ctx->r2 = S32(0X6D << 16);
    // 0x8004F2AC: addiu       $v0, $v0, -0x4450
    ctx->r2 = ADD32(ctx->r2, -0X4450);
    // 0x8004F2B0: addiu       $a0, $a0, -0x20
    ctx->r4 = ADD32(ctx->r4, -0X20);
    // 0x8004F2B4: bltz        $a0, L_8004F2C8
    if (SIGNED(ctx->r4) < 0) {
        // 0x8004F2B8: sll         $a0, $a0, 7
        ctx->r4 = S32(ctx->r4 << 7);
            goto L_8004F2C8;
    }
    // 0x8004F2B8: sll         $a0, $a0, 7
    ctx->r4 = S32(ctx->r4 << 7);
    // 0x8004F2BC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8004F2C0: jal         0x80006D98
    // 0x8004F2C4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_80006D98(rdram, ctx);
        goto after_0;
    // 0x8004F2C4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_0:
L_8004F2C8:
    // 0x8004F2C8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8004F2CC: jr          $ra
    // 0x8004F2D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8004F2D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8004F2D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F2D4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8004F2D8: addu        $t8, $a1, $zero
    ctx->r24 = ADD32(ctx->r5, 0);
    // 0x8004F2DC: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8004F2E0: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x8004F2E4: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x8004F2E8: ori         $a0, $a0, 0x1402
    ctx->r4 = ctx->r4 | 0X1402;
    // 0x8004F2EC: lui         $t0, 0xFCFF
    ctx->r8 = S32(0XFCFF << 16);
    // 0x8004F2F0: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x8004F2F4: lui         $a2, 0xFFFC
    ctx->r6 = S32(0XFFFC << 16);
    // 0x8004F2F8: ori         $a2, $a2, 0xF279
    ctx->r6 = ctx->r6 | 0XF279;
    // 0x8004F2FC: lui         $t1, 0xBA00
    ctx->r9 = S32(0XBA00 << 16);
    // 0x8004F300: ori         $t1, $t1, 0x1301
    ctx->r9 = ctx->r9 | 0X1301;
    // 0x8004F304: lui         $t3, 0xB900
    ctx->r11 = S32(0XB900 << 16);
    // 0x8004F308: ori         $t3, $t3, 0x31D
    ctx->r11 = ctx->r11 | 0X31D;
    // 0x8004F30C: lui         $t2, 0xF0A
    ctx->r10 = S32(0XF0A << 16);
    // 0x8004F310: ori         $t2, $t2, 0x7008
    ctx->r10 = ctx->r10 | 0X7008;
    // 0x8004F314: lui         $t4, 0xBA00
    ctx->r12 = S32(0XBA00 << 16);
    // 0x8004F318: ori         $t4, $t4, 0xE02
    ctx->r12 = ctx->r12 | 0XE02;
    // 0x8004F31C: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x8004F320: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x8004F324: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004F328: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x8004F32C: lui         $t7, 0x703
    ctx->r15 = S32(0X703 << 16);
    // 0x8004F330: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x8004F334: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8004F338: sw          $a2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r6;
    // 0x8004F33C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8004F340: lw          $a2, -0x74BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X74BC);
    // 0x8004F344: addu        $t9, $zero, $zero
    ctx->r25 = ADD32(0, 0);
    // 0x8004F348: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x8004F34C: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x8004F350: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8004F354: lw          $a0, -0x74C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X74C0);
    // 0x8004F358: sll         $a3, $a3, 5
    ctx->r7 = S32(ctx->r7 << 5);
    // 0x8004F35C: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8004F360: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F364: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004F368: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x8004F36C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F370: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004F374: addiu       $v1, $v0, 0x18
    ctx->r3 = ADD32(ctx->r2, 0X18);
    // 0x8004F378: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F37C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004F380: addiu       $v1, $v0, 0x20
    ctx->r3 = ADD32(ctx->r2, 0X20);
    // 0x8004F384: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F388: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004F38C: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x8004F390: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F394: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004F398: addiu       $v1, $v0, 0x30
    ctx->r3 = ADD32(ctx->r2, 0X30);
    // 0x8004F39C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F3A0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004F3A4: ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // 0x8004F3A8: sw          $v1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r3;
    // 0x8004F3AC: addiu       $v1, $v0, 0x38
    ctx->r3 = ADD32(ctx->r2, 0X38);
    // 0x8004F3B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F3B4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004F3B8: lui         $v1, 0xFD10
    ctx->r3 = S32(0XFD10 << 16);
    // 0x8004F3BC: sw          $v1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r3;
    // 0x8004F3C0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8004F3C4: addiu       $v1, $v1, 0x5198
    ctx->r3 = ADD32(ctx->r3, 0X5198);
    // 0x8004F3C8: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x8004F3CC: addiu       $v1, $v0, 0x40
    ctx->r3 = ADD32(ctx->r2, 0X40);
    // 0x8004F3D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F3D4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004F3D8: lui         $v1, 0xE800
    ctx->r3 = S32(0XE800 << 16);
    // 0x8004F3DC: sw          $v1, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r3;
    // 0x8004F3E0: addiu       $v1, $v0, 0x48
    ctx->r3 = ADD32(ctx->r2, 0X48);
    // 0x8004F3E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F3E8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004F3EC: lui         $v1, 0x700
    ctx->r3 = S32(0X700 << 16);
    // 0x8004F3F0: sw          $v1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r3;
    // 0x8004F3F4: addiu       $v1, $v0, 0x50
    ctx->r3 = ADD32(ctx->r2, 0X50);
    // 0x8004F3F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F3FC: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004F400: lui         $v1, 0xE600
    ctx->r3 = S32(0XE600 << 16);
    // 0x8004F404: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8004F408: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8004F40C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8004F410: sw          $t0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r8;
    // 0x8004F414: sw          $t1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r9;
    // 0x8004F418: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x8004F41C: sw          $t3, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r11;
    // 0x8004F420: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x8004F424: sw          $t4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r12;
    // 0x8004F428: sw          $a3, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r7;
    // 0x8004F42C: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8004F430: sw          $t6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r14;
    // 0x8004F434: sw          $v1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r3;
    // 0x8004F438: addiu       $v1, $v0, 0x58
    ctx->r3 = ADD32(ctx->r2, 0X58);
    // 0x8004F43C: sw          $zero, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = 0;
    // 0x8004F440: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F444: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004F448: lui         $v1, 0xF000
    ctx->r3 = S32(0XF000 << 16);
    // 0x8004F44C: sw          $v1, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r3;
    // 0x8004F450: addiu       $v1, $v0, 0x60
    ctx->r3 = ADD32(ctx->r2, 0X60);
    // 0x8004F454: sw          $t7, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r15;
    // 0x8004F458: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F45C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004F460: sw          $t5, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r13;
    // 0x8004F464: subu        $t7, $a2, $a0
    ctx->r15 = SUB32(ctx->r6, ctx->r4);
    // 0x8004F468: blez        $t7, L_8004F6E0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8004F46C: sw          $zero, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = 0;
            goto L_8004F6E0;
    }
    // 0x8004F46C: sw          $zero, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = 0;
    // 0x8004F470: addiu       $v1, $s0, 0x10
    ctx->r3 = ADD32(ctx->r16, 0X10);
    // 0x8004F474: slti        $v1, $v1, 0x1
    ctx->r3 = SIGNED(ctx->r3) < 0X1 ? 1 : 0;
    // 0x8004F478: slti        $v0, $s0, 0xF0
    ctx->r2 = SIGNED(ctx->r16) < 0XF0 ? 1 : 0;
    // 0x8004F47C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8004F480: or          $s1, $v1, $v0
    ctx->r17 = ctx->r3 | ctx->r2;
    // 0x8004F484: addiu       $t4, $a1, 0x10
    ctx->r12 = ADD32(ctx->r5, 0X10);
L_8004F488:
    // 0x8004F488: slti        $v1, $t4, 0x1
    ctx->r3 = SIGNED(ctx->r12) < 0X1 ? 1 : 0;
    // 0x8004F48C: slti        $v0, $t8, 0x140
    ctx->r2 = SIGNED(ctx->r24) < 0X140 ? 1 : 0;
    // 0x8004F490: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x8004F494: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8004F498: or          $v1, $v1, $s1
    ctx->r3 = ctx->r3 | ctx->r17;
    // 0x8004F49C: bnel        $v1, $zero, L_8004F6BC
    if (ctx->r3 != 0) {
        // 0x8004F4A0: addiu       $t4, $t4, 0x10
        ctx->r12 = ADD32(ctx->r12, 0X10);
            goto L_8004F6BC;
    }
    goto skip_0;
    // 0x8004F4A0: addiu       $t4, $t4, 0x10
    ctx->r12 = ADD32(ctx->r12, 0X10);
    skip_0:
    // 0x8004F4A4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004F4A8: lw          $v0, -0x34C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34C0);
    // 0x8004F4AC: bne         $v0, $zero, L_8004F4C0
    if (ctx->r2 != 0) {
        // 0x8004F4B0: lui         $a0, 0x703
        ctx->r4 = S32(0X703 << 16);
            goto L_8004F4C0;
    }
    // 0x8004F4B0: lui         $a0, 0x703
    ctx->r4 = S32(0X703 << 16);
    // 0x8004F4B4: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8004F4B8: j           L_8004F4CC
    // 0x8004F4BC: lw          $a3, 0x491C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X491C);
        goto L_8004F4CC;
    // 0x8004F4BC: lw          $a3, 0x491C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X491C);
L_8004F4C0:
    // 0x8004F4C0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8004F4C4: lw          $v0, 0x491C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X491C);
    // 0x8004F4C8: addiu       $a3, $v0, 0x4000
    ctx->r7 = ADD32(ctx->r2, 0X4000);
L_8004F4CC:
    // 0x8004F4CC: ori         $a0, $a0, 0xF800
    ctx->r4 = ctx->r4 | 0XF800;
    // 0x8004F4D0: lui         $a1, 0xF540
    ctx->r5 = S32(0XF540 << 16);
    // 0x8004F4D4: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x8004F4D8: lui         $a2, 0x3
    ctx->r6 = S32(0X3 << 16);
    // 0x8004F4DC: ori         $a2, $a2, 0xC03C
    ctx->r6 = ctx->r6 | 0XC03C;
    // 0x8004F4E0: addu        $t3, $t8, $zero
    ctx->r11 = ADD32(ctx->r24, 0);
    // 0x8004F4E4: addu        $t0, $s0, $zero
    ctx->r8 = ADD32(ctx->r16, 0);
    // 0x8004F4E8: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8004F4EC: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x8004F4F0: addu        $t6, $zero, $zero
    ctx->r14 = ADD32(0, 0);
    // 0x8004F4F4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004F4F8: lw          $v0, -0x74C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X74C0);
    // 0x8004F4FC: addu        $t5, $zero, $zero
    ctx->r13 = ADD32(0, 0);
    // 0x8004F500: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004F504: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8004F508: sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2 << 7);
    // 0x8004F50C: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x8004F510: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8004F514: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F518: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004F51C: lui         $v0, 0xFD50
    ctx->r2 = S32(0XFD50 << 16);
    // 0x8004F520: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004F524: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8004F528: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F52C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004F530: lui         $v0, 0xF550
    ctx->r2 = S32(0XF550 << 16);
    // 0x8004F534: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8004F538: lui         $v0, 0x700
    ctx->r2 = S32(0X700 << 16);
    // 0x8004F53C: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8004F540: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8004F544: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F548: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004F54C: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x8004F550: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x8004F554: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x8004F558: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F55C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004F560: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x8004F564: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x8004F568: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x8004F56C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F570: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004F574: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x8004F578: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // 0x8004F57C: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x8004F580: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F584: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004F588: addiu       $v0, $v1, 0x38
    ctx->r2 = ADD32(ctx->r3, 0X38);
    // 0x8004F58C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F590: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004F594: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x8004F598: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x8004F59C: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x8004F5A0: sw          $a0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r4;
    // 0x8004F5A4: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x8004F5A8: sw          $a1, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r5;
    // 0x8004F5AC: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x8004F5B0: sw          $v0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r2;
    // 0x8004F5B4: bgez        $t8, L_8004F5D4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8004F5B8: sw          $a2, 0x34($v1)
        MEM_W(0X34, ctx->r3) = ctx->r6;
            goto L_8004F5D4;
    }
    // 0x8004F5B8: sw          $a2, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r6;
    // 0x8004F5BC: addiu       $t2, $t8, 0x10
    ctx->r10 = ADD32(ctx->r24, 0X10);
    // 0x8004F5C0: bgez        $t8, L_8004F5CC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8004F5C4: addu        $t6, $t8, $zero
        ctx->r14 = ADD32(ctx->r24, 0);
            goto L_8004F5CC;
    }
    // 0x8004F5C4: addu        $t6, $t8, $zero
    ctx->r14 = ADD32(ctx->r24, 0);
    // 0x8004F5C8: negu        $t6, $t6
    ctx->r14 = SUB32(0, ctx->r14);
L_8004F5CC:
    // 0x8004F5CC: j           L_8004F5E4
    // 0x8004F5D0: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
        goto L_8004F5E4;
    // 0x8004F5D0: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
L_8004F5D4:
    // 0x8004F5D4: slti        $v0, $t4, 0x140
    ctx->r2 = SIGNED(ctx->r12) < 0X140 ? 1 : 0;
    // 0x8004F5D8: bne         $v0, $zero, L_8004F5E4
    if (ctx->r2 != 0) {
        // 0x8004F5DC: addiu       $v0, $zero, 0x140
        ctx->r2 = ADD32(0, 0X140);
            goto L_8004F5E4;
    }
    // 0x8004F5DC: addiu       $v0, $zero, 0x140
    ctx->r2 = ADD32(0, 0X140);
    // 0x8004F5E0: subu        $t2, $v0, $t8
    ctx->r10 = SUB32(ctx->r2, ctx->r24);
L_8004F5E4:
    // 0x8004F5E4: bgez        $t0, L_8004F604
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8004F5E8: addiu       $v0, $t0, 0x10
        ctx->r2 = ADD32(ctx->r8, 0X10);
            goto L_8004F604;
    }
    // 0x8004F5E8: addiu       $v0, $t0, 0x10
    ctx->r2 = ADD32(ctx->r8, 0X10);
    // 0x8004F5EC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8004F5F0: bgez        $t0, L_8004F5FC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8004F5F4: addu        $t5, $t0, $zero
        ctx->r13 = ADD32(ctx->r8, 0);
            goto L_8004F5FC;
    }
    // 0x8004F5F4: addu        $t5, $t0, $zero
    ctx->r13 = ADD32(ctx->r8, 0);
    // 0x8004F5F8: negu        $t5, $t5
    ctx->r13 = SUB32(0, ctx->r13);
L_8004F5FC:
    // 0x8004F5FC: j           L_8004F614
    // 0x8004F600: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
        goto L_8004F614;
    // 0x8004F600: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
L_8004F604:
    // 0x8004F604: slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // 0x8004F608: bne         $v0, $zero, L_8004F614
    if (ctx->r2 != 0) {
        // 0x8004F60C: addiu       $v0, $zero, 0xF0
        ctx->r2 = ADD32(0, 0XF0);
            goto L_8004F614;
    }
    // 0x8004F60C: addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // 0x8004F610: subu        $t1, $v0, $t0
    ctx->r9 = SUB32(ctx->r2, ctx->r8);
L_8004F614:
    // 0x8004F614: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8004F618: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x8004F61C: lui         $a2, 0x400
    ctx->r6 = S32(0X400 << 16);
    // 0x8004F620: ori         $a2, $a2, 0x400
    ctx->r6 = ctx->r6 | 0X400;
    // 0x8004F624: addu        $v1, $t3, $t2
    ctx->r3 = ADD32(ctx->r11, ctx->r10);
    // 0x8004F628: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004F62C: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8004F630: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x8004F634: lui         $a0, 0xE400
    ctx->r4 = S32(0XE400 << 16);
    // 0x8004F638: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x8004F63C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F640: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004F644: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8004F648: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004F64C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8004F650: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8004F654: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8004F658: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x8004F65C: sll         $v1, $t3, 2
    ctx->r3 = S32(ctx->r11 << 2);
    // 0x8004F660: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8004F664: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x8004F668: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x8004F66C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8004F670: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8004F674: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x8004F678: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F67C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004F680: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x8004F684: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // 0x8004F688: sll         $v1, $t6, 21
    ctx->r3 = S32(ctx->r14 << 21);
    // 0x8004F68C: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x8004F690: sll         $v0, $t5, 5
    ctx->r2 = S32(ctx->r13 << 5);
    // 0x8004F694: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8004F698: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8004F69C: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x8004F6A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F6A4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004F6A8: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x8004F6AC: sw          $v1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r3;
    // 0x8004F6B0: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x8004F6B4: sw          $a2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r6;
    // 0x8004F6B8: addiu       $t4, $t4, 0x10
    ctx->r12 = ADD32(ctx->r12, 0X10);
L_8004F6BC:
    // 0x8004F6BC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004F6C0: lw          $v0, -0x74C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X74C0);
    // 0x8004F6C4: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x8004F6C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004F6CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F6D0: sw          $v0, -0x74C0($at)
    MEM_W(-0X74C0, ctx->r1) = ctx->r2;
    // 0x8004F6D4: slt         $v0, $t9, $t7
    ctx->r2 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8004F6D8: bne         $v0, $zero, L_8004F488
    if (ctx->r2 != 0) {
        // 0x8004F6DC: addiu       $t8, $t8, 0x10
        ctx->r24 = ADD32(ctx->r24, 0X10);
            goto L_8004F488;
    }
    // 0x8004F6DC: addiu       $t8, $t8, 0x10
    ctx->r24 = ADD32(ctx->r24, 0X10);
L_8004F6E0:
    // 0x8004F6E0: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8004F6E4: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8004F6E8: jr          $ra
    // 0x8004F6EC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8004F6EC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8004F6F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F6F0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8004F6F4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8004F6F8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8004F6FC:
    // 0x8004F6FC: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
L_8004F700:
    // 0x8004F700: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F704: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8004F708: sh          $zero, -0x74B0($at)
    MEM_H(-0X74B0, ctx->r1) = 0;
    // 0x8004F70C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8004F710: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8004F714: sltiu       $v0, $a0, 0x28
    ctx->r2 = ctx->r4 < 0X28 ? 1 : 0;
    // 0x8004F718: bne         $v0, $zero, L_8004F700
    if (ctx->r2 != 0) {
        // 0x8004F71C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8004F700;
    }
    // 0x8004F71C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8004F720: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8004F724: sltiu       $v0, $a2, 0x1E
    ctx->r2 = ctx->r6 < 0X1E ? 1 : 0;
    // 0x8004F728: bnel        $v0, $zero, L_8004F6FC
    if (ctx->r2 != 0) {
        // 0x8004F72C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8004F6FC;
    }
    goto skip_0;
    // 0x8004F72C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_0:
    // 0x8004F730: jr          $ra
    // 0x8004F734: nop

    return;
    // 0x8004F734: nop

;}
RECOMP_FUNC void func_8004F738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F738: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8004F73C:
    // 0x8004F73C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F740: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8004F744: sh          $zero, -0x74B0($at)
    MEM_H(-0X74B0, ctx->r1) = 0;
    // 0x8004F748: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8004F74C: sltiu       $v0, $v1, 0x960
    ctx->r2 = ctx->r3 < 0X960 ? 1 : 0;
    // 0x8004F750: bne         $v0, $zero, L_8004F73C
    if (ctx->r2 != 0) {
        // 0x8004F754: nop
    
            goto L_8004F73C;
    }
    // 0x8004F754: nop

    // 0x8004F758: jr          $ra
    // 0x8004F75C: nop

    return;
    // 0x8004F75C: nop

;}
RECOMP_FUNC void func_8004F760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F760: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8004F764: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8004F768: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8004F76C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004F770: addiu       $v1, $v1, -0x6B48
    ctx->r3 = ADD32(ctx->r3, -0X6B48);
    // 0x8004F774: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8004F778: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8004F77C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8004F780: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8004F784: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8004F788: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8004F78C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8004F790: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
L_8004F794:
    // 0x8004F794: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8004F798: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8004F79C: sltiu       $v0, $s2, 0x20
    ctx->r2 = ctx->r18 < 0X20 ? 1 : 0;
    // 0x8004F7A0: bne         $v0, $zero, L_8004F794
    if (ctx->r2 != 0) {
        // 0x8004F7A4: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8004F794;
    }
    // 0x8004F7A4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8004F7A8: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x8004F7AC: addiu       $s3, $s3, -0x74B0
    ctx->r19 = ADD32(ctx->r19, -0X74B0);
    // 0x8004F7B0: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x8004F7B4: ori         $a0, $a0, 0x1402
    ctx->r4 = ctx->r4 | 0X1402;
    // 0x8004F7B8: lui         $a2, 0xFCFF
    ctx->r6 = S32(0XFCFF << 16);
    // 0x8004F7BC: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x8004F7C0: lui         $a1, 0xFFFC
    ctx->r5 = S32(0XFFFC << 16);
    // 0x8004F7C4: ori         $a1, $a1, 0xF279
    ctx->r5 = ctx->r5 | 0XF279;
    // 0x8004F7C8: lui         $a3, 0xBA00
    ctx->r7 = S32(0XBA00 << 16);
    // 0x8004F7CC: ori         $a3, $a3, 0x1301
    ctx->r7 = ctx->r7 | 0X1301;
    // 0x8004F7D0: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x8004F7D4: ori         $t1, $t1, 0x31D
    ctx->r9 = ctx->r9 | 0X31D;
    // 0x8004F7D8: lui         $t0, 0xF0A
    ctx->r8 = S32(0XF0A << 16);
    // 0x8004F7DC: ori         $t0, $t0, 0x7008
    ctx->r8 = ctx->r8 | 0X7008;
    // 0x8004F7E0: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x8004F7E4: ori         $t2, $t2, 0xE02
    ctx->r10 = ctx->r10 | 0XE02;
    // 0x8004F7E8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004F7EC: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x8004F7F0: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8004F7F4: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8004F7F8: addiu       $t3, $t3, -0x6B48
    ctx->r11 = ADD32(ctx->r11, -0X6B48);
    // 0x8004F7FC: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8004F800: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F804: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004F808: lui         $v1, 0xE700
    ctx->r3 = S32(0XE700 << 16);
    // 0x8004F80C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8004F810: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x8004F814: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F818: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004F81C: addiu       $v1, $v0, 0x18
    ctx->r3 = ADD32(ctx->r2, 0X18);
    // 0x8004F820: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F824: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004F828: addiu       $v1, $v0, 0x20
    ctx->r3 = ADD32(ctx->r2, 0X20);
    // 0x8004F82C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F830: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004F834: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x8004F838: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F83C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004F840: addiu       $v1, $v0, 0x30
    ctx->r3 = ADD32(ctx->r2, 0X30);
    // 0x8004F844: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F848: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8004F84C: ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // 0x8004F850: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8004F854: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x8004F858: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8004F85C: sw          $a2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r6;
    // 0x8004F860: sw          $a1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r5;
    // 0x8004F864: sw          $a3, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r7;
    // 0x8004F868: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x8004F86C: sw          $t1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r9;
    // 0x8004F870: sw          $t0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r8;
    // 0x8004F874: sw          $t2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r10;
    // 0x8004F878: sw          $v1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r3;
    // 0x8004F87C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8004F880:
    // 0x8004F880: lh          $v0, 0x0($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X0);
    // 0x8004F884: bgez        $v0, L_8004F8BC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004F888: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8004F8BC;
    }
    // 0x8004F888: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004F88C: andi        $v0, $v1, 0x7FF
    ctx->r2 = ctx->r3 & 0X7FF;
    // 0x8004F890: beq         $v0, $zero, L_8004F8B0
    if (ctx->r2 == 0) {
        // 0x8004F894: srl         $v1, $v0, 6
        ctx->r3 = S32(U32(ctx->r2) >> 6);
            goto L_8004F8B0;
    }
    // 0x8004F894: srl         $v1, $v0, 6
    ctx->r3 = S32(U32(ctx->r2) >> 6);
    // 0x8004F898: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004F89C: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x8004F8A0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8004F8A4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004F8A8: j           L_8004F8BC
    // 0x8004F8AC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_8004F8BC;
    // 0x8004F8AC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8004F8B0:
    // 0x8004F8B0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8004F8B4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004F8B8: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
L_8004F8BC:
    // 0x8004F8BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8004F8C0: sltiu       $v0, $s0, 0x28
    ctx->r2 = ctx->r16 < 0X28 ? 1 : 0;
    // 0x8004F8C4: bne         $v0, $zero, L_8004F880
    if (ctx->r2 != 0) {
        // 0x8004F8C8: addiu       $s3, $s3, 0x2
        ctx->r19 = ADD32(ctx->r19, 0X2);
            goto L_8004F880;
    }
    // 0x8004F8C8: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x8004F8CC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8004F8D0: sltiu       $v0, $s4, 0x1E
    ctx->r2 = ctx->r20 < 0X1E ? 1 : 0;
    // 0x8004F8D4: bnel        $v0, $zero, L_8004F880
    if (ctx->r2 != 0) {
        // 0x8004F8D8: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8004F880;
    }
    goto skip_0;
    // 0x8004F8D8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    skip_0:
    // 0x8004F8DC: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8004F8E0: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // 0x8004F8E4: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x8004F8E8: addiu       $s6, $s6, -0x6B48
    ctx->r22 = ADD32(ctx->r22, -0X6B48);
L_8004F8EC:
    // 0x8004F8EC: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8004F8F0: beq         $v0, $zero, L_8004FA5C
    if (ctx->r2 == 0) {
        // 0x8004F8F4: sll         $a1, $s2, 2
        ctx->r5 = S32(ctx->r18 << 2);
            goto L_8004FA5C;
    }
    // 0x8004F8F4: sll         $a1, $s2, 2
    ctx->r5 = S32(ctx->r18 << 2);
    // 0x8004F8F8: lui         $a0, 0x73F
    ctx->r4 = S32(0X73F << 16);
    // 0x8004F8FC: ori         $a0, $a0, 0xF200
    ctx->r4 = ctx->r4 | 0XF200;
    // 0x8004F900: lui         $a2, 0xF540
    ctx->r6 = S32(0XF540 << 16);
    // 0x8004F904: ori         $a2, $a2, 0x800
    ctx->r6 = ctx->r6 | 0X800;
    // 0x8004F908: lui         $a3, 0xF
    ctx->r7 = S32(0XF << 16);
    // 0x8004F90C: ori         $a3, $a3, 0xC0FC
    ctx->r7 = ctx->r7 | 0XC0FC;
    // 0x8004F910: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x8004F914: addiu       $s3, $s3, -0x74B0
    ctx->r19 = ADD32(ctx->r19, -0X74B0);
    // 0x8004F918: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004F91C: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8004F920: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8004F924: lui         $v0, 0xFD50
    ctx->r2 = S32(0XFD50 << 16);
    // 0x8004F928: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004F92C: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x8004F930: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x8004F934: lw          $a1, 0x4D18($at)
    ctx->r5 = MEM_W(ctx->r1, 0X4D18);
    // 0x8004F938: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x8004F93C: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x8004F940: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F944: sw          $s7, -0x6B50($at)
    MEM_W(-0X6B50, ctx->r1) = ctx->r23;
    // 0x8004F948: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F94C: sw          $s7, -0x6B4C($at)
    MEM_W(-0X6B4C, ctx->r1) = ctx->r23;
    // 0x8004F950: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8004F954: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F958: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004F95C: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8004F960: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F964: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004F968: lui         $v0, 0xF550
    ctx->r2 = S32(0XF550 << 16);
    // 0x8004F96C: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8004F970: lui         $v0, 0x700
    ctx->r2 = S32(0X700 << 16);
    // 0x8004F974: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8004F978: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8004F97C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F980: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004F984: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x8004F988: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x8004F98C: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x8004F990: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F994: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004F998: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x8004F99C: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x8004F9A0: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x8004F9A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F9A8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004F9AC: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x8004F9B0: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // 0x8004F9B4: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x8004F9B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F9BC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004F9C0: addiu       $v0, $v1, 0x38
    ctx->r2 = ADD32(ctx->r3, 0X38);
    // 0x8004F9C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004F9C8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004F9CC: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x8004F9D0: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x8004F9D4: sw          $a0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r4;
    // 0x8004F9D8: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x8004F9DC: sw          $a2, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r6;
    // 0x8004F9E0: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x8004F9E4: sw          $v0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r2;
    // 0x8004F9E8: sw          $a3, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r7;
    // 0x8004F9EC: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
L_8004F9F0:
    // 0x8004F9F0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8004F9F4:
    // 0x8004F9F4: lh          $v0, 0x0($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X0);
    // 0x8004F9F8: bgez        $v0, L_8004FA34
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004F9FC: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8004FA34;
    }
    // 0x8004F9FC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8004FA00: andi        $a0, $v1, 0x7FF
    ctx->r4 = ctx->r3 & 0X7FF;
    // 0x8004FA04: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8004FA08: bne         $v0, $zero, L_8004FA14
    if (ctx->r2 != 0) {
        // 0x8004FA0C: srl         $v0, $v0, 6
        ctx->r2 = S32(U32(ctx->r2) >> 6);
            goto L_8004FA14;
    }
    // 0x8004FA0C: srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // 0x8004FA10: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004FA14:
    // 0x8004FA14: bnel        $v0, $s2, L_8004FA38
    if (ctx->r2 != ctx->r18) {
        // 0x8004FA18: addiu       $s3, $s3, 0x2
        ctx->r19 = ADD32(ctx->r19, 0X2);
            goto L_8004FA38;
    }
    goto skip_1;
    // 0x8004FA18: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    skip_1:
    // 0x8004FA1C: lhu         $a1, 0x0($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0X0);
    // 0x8004FA20: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8004FA24: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // 0x8004FA28: andi        $a1, $a1, 0x7800
    ctx->r5 = ctx->r5 & 0X7800;
    // 0x8004FA2C: jal         0x8004FA98
    // 0x8004FA30: srl         $a1, $a1, 11
    ctx->r5 = S32(U32(ctx->r5) >> 11);
    func_8004FA98(rdram, ctx);
        goto after_0;
    // 0x8004FA30: srl         $a1, $a1, 11
    ctx->r5 = S32(U32(ctx->r5) >> 11);
    after_0:
L_8004FA34:
    // 0x8004FA34: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
L_8004FA38:
    // 0x8004FA38: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8004FA3C: sltiu       $v0, $s0, 0x28
    ctx->r2 = ctx->r16 < 0X28 ? 1 : 0;
    // 0x8004FA40: bne         $v0, $zero, L_8004F9F4
    if (ctx->r2 != 0) {
        // 0x8004FA44: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_8004F9F4;
    }
    // 0x8004FA44: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8004FA48: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8004FA4C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8004FA50: sltiu       $v0, $s4, 0x1E
    ctx->r2 = ctx->r20 < 0X1E ? 1 : 0;
    // 0x8004FA54: bne         $v0, $zero, L_8004F9F0
    if (ctx->r2 != 0) {
        // 0x8004FA58: addiu       $s5, $s5, 0x8
        ctx->r21 = ADD32(ctx->r21, 0X8);
            goto L_8004F9F0;
    }
    // 0x8004FA58: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
L_8004FA5C:
    // 0x8004FA5C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8004FA60: sltiu       $v0, $s2, 0x20
    ctx->r2 = ctx->r18 < 0X20 ? 1 : 0;
    // 0x8004FA64: bne         $v0, $zero, L_8004F8EC
    if (ctx->r2 != 0) {
        // 0x8004FA68: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_8004F8EC;
    }
    // 0x8004FA68: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8004FA6C: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x8004FA70: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8004FA74: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8004FA78: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8004FA7C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8004FA80: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8004FA84: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8004FA88: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8004FA8C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004FA90: jr          $ra
    // 0x8004FA94: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8004FA94: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8004FA98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FA98: addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // 0x8004FA9C: addu        $t1, $a2, $zero
    ctx->r9 = ADD32(ctx->r6, 0);
    // 0x8004FAA0: andi        $v1, $a0, 0x3F
    ctx->r3 = ctx->r4 & 0X3F;
    // 0x8004FAA4: andi        $v0, $v1, 0x7
    ctx->r2 = ctx->r3 & 0X7;
    // 0x8004FAA8: sll         $t3, $v0, 3
    ctx->r11 = S32(ctx->r2 << 3);
    // 0x8004FAAC: beq         $v1, $zero, L_8004FAB8
    if (ctx->r3 == 0) {
        // 0x8004FAB0: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8004FAB8;
    }
    // 0x8004FAB0: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8004FAB4: andi        $t2, $v1, 0x38
    ctx->r10 = ctx->r3 & 0X38;
L_8004FAB8:
    // 0x8004FAB8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004FABC: lw          $v0, -0x6B4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6B4C);
    // 0x8004FAC0: beq         $t0, $v0, L_8004FB84
    if (ctx->r8 == ctx->r2) {
        // 0x8004FAC4: lui         $a1, 0xF500
        ctx->r5 = S32(0XF500 << 16);
            goto L_8004FB84;
    }
    // 0x8004FAC4: lui         $a1, 0xF500
    ctx->r5 = S32(0XF500 << 16);
    // 0x8004FAC8: ori         $a1, $a1, 0x100
    ctx->r5 = ctx->r5 | 0X100;
    // 0x8004FACC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004FAD0: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8004FAD4: lui         $a2, 0x703
    ctx->r6 = S32(0X703 << 16);
    // 0x8004FAD8: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x8004FADC: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004FAE0: addiu       $a0, $a0, 0x4B18
    ctx->r4 = ADD32(ctx->r4, 0X4B18);
    // 0x8004FAE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FAE8: sw          $t0, -0x6B4C($at)
    MEM_W(-0X6B4C, ctx->r1) = ctx->r8;
    // 0x8004FAEC: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8004FAF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FAF4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004FAF8: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x8004FAFC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004FB00: sll         $v0, $t0, 5
    ctx->r2 = S32(ctx->r8 << 5);
    // 0x8004FB04: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8004FB08: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8004FB0C: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8004FB10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FB14: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004FB18: lui         $v0, 0xE800
    ctx->r2 = S32(0XE800 << 16);
    // 0x8004FB1C: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x8004FB20: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8004FB24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FB28: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004FB2C: lui         $v0, 0x700
    ctx->r2 = S32(0X700 << 16);
    // 0x8004FB30: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x8004FB34: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x8004FB38: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FB3C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004FB40: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x8004FB44: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x8004FB48: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x8004FB4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FB50: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004FB54: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x8004FB58: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // 0x8004FB5C: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x8004FB60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FB64: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004FB68: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x8004FB6C: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x8004FB70: sw          $a1, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r5;
    // 0x8004FB74: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x8004FB78: sw          $a2, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r6;
    // 0x8004FB7C: sw          $v0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r2;
    // 0x8004FB80: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
L_8004FB84:
    // 0x8004FB84: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8004FB88: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x8004FB8C: lui         $a2, 0x400
    ctx->r6 = S32(0X400 << 16);
    // 0x8004FB90: ori         $a2, $a2, 0x400
    ctx->r6 = ctx->r6 | 0X400;
    // 0x8004FB94: addiu       $v1, $t1, 0x8
    ctx->r3 = ADD32(ctx->r9, 0X8);
    // 0x8004FB98: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8004FB9C: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8004FBA0: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x8004FBA4: lui         $a0, 0xE400
    ctx->r4 = S32(0XE400 << 16);
    // 0x8004FBA8: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x8004FBAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FBB0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004FBB4: addiu       $v0, $a3, 0x8
    ctx->r2 = ADD32(ctx->r7, 0X8);
    // 0x8004FBB8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8004FBBC: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8004FBC0: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x8004FBC4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8004FBC8: sll         $v0, $t1, 2
    ctx->r2 = S32(ctx->r9 << 2);
    // 0x8004FBCC: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8004FBD0: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x8004FBD4: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x8004FBD8: sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7 << 2);
    // 0x8004FBDC: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8004FBE0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8004FBE4: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8004FBE8: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x8004FBEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FBF0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004FBF4: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x8004FBF8: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x8004FBFC: sll         $v0, $t3, 21
    ctx->r2 = S32(ctx->r11 << 21);
    // 0x8004FC00: sll         $v1, $t2, 5
    ctx->r3 = S32(ctx->r10 << 5);
    // 0x8004FC04: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8004FC08: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x8004FC0C: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x8004FC10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FC14: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8004FC18: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x8004FC1C: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x8004FC20: jr          $ra
    // 0x8004FC24: sw          $a2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r6;
    return;
    // 0x8004FC24: sw          $a2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r6;
;}
RECOMP_FUNC void func_8004FC28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FC28: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x8004FC2C: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8004FC30: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8004FC34: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8004FC38: beq         $t0, $zero, L_8004FC98
    if (ctx->r8 == 0) {
        // 0x8004FC3C: addu        $v1, $a1, $v0
        ctx->r3 = ADD32(ctx->r5, ctx->r2);
            goto L_8004FC98;
    }
    // 0x8004FC3C: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x8004FC40: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x8004FC44: sll         $a3, $a3, 11
    ctx->r7 = S32(ctx->r7 << 11);
    // 0x8004FC48: addiu       $a2, $zero, -0x8000
    ctx->r6 = ADD32(0, -0X8000);
    // 0x8004FC4C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8004FC50: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004FC54: addiu       $v0, $v0, -0x74B0
    ctx->r2 = ADD32(ctx->r2, -0X74B0);
    // 0x8004FC58: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004FC5C: addiu       $a1, $v0, 0x960
    ctx->r5 = ADD32(ctx->r2, 0X960);
    // 0x8004FC60: sltu        $v0, $v1, $a1
    ctx->r2 = ctx->r3 < ctx->r5 ? 1 : 0;
L_8004FC64:
    // 0x8004FC64: beq         $v0, $zero, L_8004FC8C
    if (ctx->r2 == 0) {
        // 0x8004FC68: nop
    
            goto L_8004FC8C;
    }
    // 0x8004FC68: nop

    // 0x8004FC6C: beq         $t0, $t1, L_8004FC80
    if (ctx->r8 == ctx->r9) {
        // 0x8004FC70: or          $v0, $t0, $a3
        ctx->r2 = ctx->r8 | ctx->r7;
            goto L_8004FC80;
    }
    // 0x8004FC70: or          $v0, $t0, $a3
    ctx->r2 = ctx->r8 | ctx->r7;
    // 0x8004FC74: or          $v0, $v0, $a2
    ctx->r2 = ctx->r2 | ctx->r6;
    // 0x8004FC78: j           L_8004FC84
    // 0x8004FC7C: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
        goto L_8004FC84;
    // 0x8004FC7C: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8004FC80:
    // 0x8004FC80: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_8004FC84:
    // 0x8004FC84: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8004FC88: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8004FC8C:
    // 0x8004FC8C: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x8004FC90: bne         $t0, $zero, L_8004FC64
    if (ctx->r8 != 0) {
        // 0x8004FC94: sltu        $v0, $v1, $a1
        ctx->r2 = ctx->r3 < ctx->r5 ? 1 : 0;
            goto L_8004FC64;
    }
    // 0x8004FC94: sltu        $v0, $v1, $a1
    ctx->r2 = ctx->r3 < ctx->r5 ? 1 : 0;
L_8004FC98:
    // 0x8004FC98: jr          $ra
    // 0x8004FC9C: nop

    return;
    // 0x8004FC9C: nop

;}
