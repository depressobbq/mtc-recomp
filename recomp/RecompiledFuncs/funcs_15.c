#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8004FCA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FCA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004FCA4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8004FCA8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8004FCAC: jal         0x8004F6F0
    // 0x8004FCB0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_8004F6F0(rdram, ctx);
        goto after_0;
    // 0x8004FCB0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8004FCB4: lui         $s1, 0x800B
    ctx->r17 = S32(0X800B << 16);
    // 0x8004FCB8: addiu       $s1, $s1, -0x1558
    ctx->r17 = ADD32(ctx->r17, -0X1558);
    // 0x8004FCBC: addiu       $s0, $zero, 0xB4
    ctx->r16 = ADD32(0, 0XB4);
    // 0x8004FCC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FCC4: sw          $zero, -0x6AB4($at)
    MEM_W(-0X6AB4, ctx->r1) = 0;
    // 0x8004FCC8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FCCC: sw          $zero, -0x6AB8($at)
    MEM_W(-0X6AB8, ctx->r1) = 0;
    // 0x8004FCD0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FCD4: sw          $zero, -0x6ABC($at)
    MEM_W(-0X6ABC, ctx->r1) = 0;
    // 0x8004FCD8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FCDC: sw          $zero, -0x6AC0($at)
    MEM_W(-0X6AC0, ctx->r1) = 0;
L_8004FCE0:
    // 0x8004FCE0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004FCE4: lw          $v1, -0x6AC0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6AC0);
    // 0x8004FCE8: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x8004FCEC: beq         $v0, $zero, L_8004FDAC
    if (ctx->r2 == 0) {
        // 0x8004FCF0: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8004FDAC;
    }
    // 0x8004FCF0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8004FCF4: addu        $v0, $v0, $s1
    gpr jr_addend_8004FCFC = ctx->r2;
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8004FCF8: lw          $v0, 0x0($v0)
    ctx->r2 = ADD32(ctx->r2, 0X0);
    // 0x8004FCFC: jr          $v0
    // 0x8004FD00: nop

    switch (jr_addend_8004FCFC >> 2) {
        case 0: goto L_8004FD04; break;
        case 1: goto L_8004FD24; break;
        case 2: goto L_8004FD68; break;
        case 3: goto L_8004FD24; break;
        case 4: goto L_8004FD9C; break;
        default: switch_error(__func__, 0x8004FCFC, 0x800AEAA8);
    }
    // 0x8004FD00: nop

L_8004FD04:
    // 0x8004FD04: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004FD08: lw          $v0, -0x6AC0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6AC0);
    // 0x8004FD0C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004FD10: addiu       $a0, $a0, 0x4D20
    ctx->r4 = ADD32(ctx->r4, 0X4D20);
    // 0x8004FD14: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004FD18: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FD1C: j           L_8004FD88
    // 0x8004FD20: sw          $v0, -0x6AC0($at)
    MEM_W(-0X6AC0, ctx->r1) = ctx->r2;
        goto L_8004FD88;
    // 0x8004FD20: sw          $v0, -0x6AC0($at)
    MEM_W(-0X6AC0, ctx->r1) = ctx->r2;
L_8004FD24:
    // 0x8004FD24: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004FD28: lw          $v0, -0x6AB8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6AB8);
    // 0x8004FD2C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8004FD30: lhu         $v1, -0x33C8($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X33C8);
    // 0x8004FD34: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8004FD38: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FD3C: sw          $v0, -0x6AB8($at)
    MEM_W(-0X6AB8, ctx->r1) = ctx->r2;
    // 0x8004FD40: beq         $v0, $zero, L_8004FD50
    if (ctx->r2 == 0) {
        // 0x8004FD44: andi        $v1, $v1, 0x4000
        ctx->r3 = ctx->r3 & 0X4000;
            goto L_8004FD50;
    }
    // 0x8004FD44: andi        $v1, $v1, 0x4000
    ctx->r3 = ctx->r3 & 0X4000;
    // 0x8004FD48: beq         $v1, $zero, L_8004FDAC
    if (ctx->r3 == 0) {
        // 0x8004FD4C: nop
    
            goto L_8004FDAC;
    }
    // 0x8004FD4C: nop

L_8004FD50:
    // 0x8004FD50: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004FD54: lw          $v0, -0x6AC0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6AC0);
    // 0x8004FD58: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004FD5C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FD60: j           L_8004FDAC
    // 0x8004FD64: sw          $v0, -0x6AC0($at)
    MEM_W(-0X6AC0, ctx->r1) = ctx->r2;
        goto L_8004FDAC;
    // 0x8004FD64: sw          $v0, -0x6AC0($at)
    MEM_W(-0X6AC0, ctx->r1) = ctx->r2;
L_8004FD68:
    // 0x8004FD68: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004FD6C: lw          $v0, -0x6AC0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6AC0);
    // 0x8004FD70: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004FD74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FD78: jal         0x8004F738
    // 0x8004FD7C: sw          $v0, -0x6AC0($at)
    MEM_W(-0X6AC0, ctx->r1) = ctx->r2;
    func_8004F738(rdram, ctx);
        goto after_1;
    // 0x8004FD7C: sw          $v0, -0x6AC0($at)
    MEM_W(-0X6AC0, ctx->r1) = ctx->r2;
    after_1:
    // 0x8004FD80: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8004FD84: addiu       $a0, $a0, 0x4D60
    ctx->r4 = ADD32(ctx->r4, 0X4D60);
L_8004FD88:
    // 0x8004FD88: jal         0x8004FDD8
    // 0x8004FD8C: nop

    func_8004FDD8(rdram, ctx);
        goto after_2;
    // 0x8004FD8C: nop

    after_2:
    // 0x8004FD90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FD94: j           L_8004FDAC
    // 0x8004FD98: sw          $s0, -0x6AB8($at)
    MEM_W(-0X6AB8, ctx->r1) = ctx->r16;
        goto L_8004FDAC;
    // 0x8004FD98: sw          $s0, -0x6AB8($at)
    MEM_W(-0X6AB8, ctx->r1) = ctx->r16;
L_8004FD9C:
    // 0x8004FD9C: jal         0x8004F738
    // 0x8004FDA0: nop

    func_8004F738(rdram, ctx);
        goto after_3;
    // 0x8004FDA0: nop

    after_3:
    // 0x8004FDA4: j           L_8004FDC4
    // 0x8004FDA8: nop

        goto L_8004FDC4;
    // 0x8004FDA8: nop

L_8004FDAC:
    // 0x8004FDAC: jal         0x8004F760
    // 0x8004FDB0: nop

    func_8004F760(rdram, ctx);
        goto after_4;
    // 0x8004FDB0: nop

    after_4:
    // 0x8004FDB4: jal         0x80004644
    // 0x8004FDB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80004644(rdram, ctx);
        goto after_5;
    // 0x8004FDB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x8004FDBC: j           L_8004FCE0
    // 0x8004FDC0: nop

        goto L_8004FCE0;
    // 0x8004FDC0: nop

L_8004FDC4:
    // 0x8004FDC4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8004FDC8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8004FDCC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004FDD0: jr          $ra
    // 0x8004FDD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8004FDD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8004FDD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FDD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004FDDC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8004FDE0: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8004FDE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004FDE8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8004FDEC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8004FDF0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8004FDF4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8004FDF8: beq         $v1, $v0, L_8004FE28
    if (ctx->r3 == ctx->r2) {
        // 0x8004FDFC: addiu       $s2, $zero, -0x1
        ctx->r18 = ADD32(0, -0X1);
            goto L_8004FE28;
    }
    // 0x8004FDFC: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8004FE00: addiu       $s0, $a0, 0x8
    ctx->r16 = ADD32(ctx->r4, 0X8);
L_8004FE04:
    // 0x8004FE04: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8004FE08: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8004FE0C: lw          $a2, -0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, -0X4);
    // 0x8004FE10: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x8004FE14: jal         0x8004FC28
    // 0x8004FE18: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    func_8004FC28(rdram, ctx);
        goto after_0;
    // 0x8004FE18: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    after_0:
    // 0x8004FE1C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8004FE20: bne         $v0, $s2, L_8004FE04
    if (ctx->r2 != ctx->r18) {
        // 0x8004FE24: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_8004FE04;
    }
    // 0x8004FE24: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_8004FE28:
    // 0x8004FE28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004FE2C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8004FE30: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8004FE34: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8004FE38: jr          $ra
    // 0x8004FE3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8004FE3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8004FE40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FE40: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x8004FE44: ori         $v0, $v0, 0xD
    ctx->r2 = ctx->r2 | 0XD;
    // 0x8004FE48: lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // 0x8004FE4C: ori         $a0, $a0, 0x70
    ctx->r4 = ctx->r4 | 0X70;
    // 0x8004FE50: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x8004FE54: ori         $v1, $v1, 0xF
    ctx->r3 = ctx->r3 | 0XF;
    // 0x8004FE58: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8004FE5C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8004FE60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8004FE64: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8004FE68: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_8004FE6C:
    // 0x8004FE6C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004FE70: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x8004FE74: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8004FE78: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004FE7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FE80: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x8004FE84: slti        $v0, $a1, 0x100
    ctx->r2 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x8004FE88: bne         $v0, $zero, L_8004FE6C
    if (ctx->r2 != 0) {
        // 0x8004FE8C: lui         $v1, 0x200
        ctx->r3 = S32(0X200 << 16);
            goto L_8004FE6C;
    }
    // 0x8004FE8C: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x8004FE90: ori         $v1, $v1, 0x70
    ctx->r3 = ctx->r3 | 0X70;
    // 0x8004FE94: lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // 0x8004FE98: ori         $a0, $a0, 0xF
    ctx->r4 = ctx->r4 | 0XF;
    // 0x8004FE9C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8004FEA0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8004FEA4: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8004FEA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004FEAC: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_8004FEB0:
    // 0x8004FEB0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004FEB4: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x8004FEB8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8004FEBC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004FEC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FEC4: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x8004FEC8: slti        $v0, $a1, 0x100
    ctx->r2 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x8004FECC: bne         $v0, $zero, L_8004FEB0
    if (ctx->r2 != 0) {
        // 0x8004FED0: lui         $v1, 0x200
        ctx->r3 = S32(0X200 << 16);
            goto L_8004FEB0;
    }
    // 0x8004FED0: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x8004FED4: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x8004FED8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004FEDC: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8004FEE0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8004FEE4:
    // 0x8004FEE4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004FEE8: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x8004FEEC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004FEF0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004FEF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FEF8: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x8004FEFC: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x8004FF00: bne         $v0, $zero, L_8004FEE4
    if (ctx->r2 != 0) {
        // 0x8004FF04: lui         $a0, 0x200
        ctx->r4 = S32(0X200 << 16);
            goto L_8004FEE4;
    }
    // 0x8004FF04: lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // 0x8004FF08: ori         $a0, $a0, 0x70
    ctx->r4 = ctx->r4 | 0X70;
    // 0x8004FF0C: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x8004FF10: ori         $v1, $v1, 0xF
    ctx->r3 = ctx->r3 | 0XF;
    // 0x8004FF14: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8004FF18: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8004FF1C: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8004FF20: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_8004FF24:
    // 0x8004FF24: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004FF28: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x8004FF2C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8004FF30: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004FF34: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FF38: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x8004FF3C: slti        $v0, $a1, 0x100
    ctx->r2 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x8004FF40: bne         $v0, $zero, L_8004FF24
    if (ctx->r2 != 0) {
        // 0x8004FF44: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_8004FF24;
    }
    // 0x8004FF44: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x8004FF48: ori         $v0, $v0, 0xD
    ctx->r2 = ctx->r2 | 0XD;
    // 0x8004FF4C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8004FF50: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8004FF54:
    // 0x8004FF54: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004FF58: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x8004FF5C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004FF60: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004FF64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FF68: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x8004FF6C: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x8004FF70: bne         $v0, $zero, L_8004FF54
    if (ctx->r2 != 0) {
        // 0x8004FF74: nop
    
            goto L_8004FF54;
    }
    // 0x8004FF74: nop

    // 0x8004FF78: jr          $ra
    // 0x8004FF7C: nop

    return;
    // 0x8004FF7C: nop

;}
RECOMP_FUNC void func_8004FF80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FF80: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8004FF84: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8004FF88: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8004FF8C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8004FF90: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x8004FF94: jal         0x8004FE40
    // 0x8004FF98: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    func_8004FE40(rdram, ctx);
        goto after_0;
    // 0x8004FF98: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    after_0:
    // 0x8004FF9C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8004FFA0:
    // 0x8004FFA0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004FFA4: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x8004FFA8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8004FFAC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004FFB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004FFB4: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x8004FFB8: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x8004FFBC: bne         $v0, $zero, L_8004FFA0
    if (ctx->r2 != 0) {
        // 0x8004FFC0: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_8004FFA0;
    }
    // 0x8004FFC0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8004FFC4: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x8004FFC8: lui         $a3, 0x200
    ctx->r7 = S32(0X200 << 16);
    // 0x8004FFCC: ori         $a3, $a3, 0x70
    ctx->r7 = ctx->r7 | 0X70;
    // 0x8004FFD0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8004FFD4: lui         $a2, 0x200
    ctx->r6 = S32(0X200 << 16);
    // 0x8004FFD8: ori         $a2, $a2, 0xF
    ctx->r6 = ctx->r6 | 0XF;
    // 0x8004FFDC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8004FFE0: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    // 0x8004FFE4: ori         $a1, $a1, 0xD
    ctx->r5 = ctx->r5 | 0XD;
    // 0x8004FFE8: andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
L_8004FFEC:
    // 0x8004FFEC: beq         $v0, $zero, L_80050004
    if (ctx->r2 == 0) {
        // 0x8004FFF0: nop
    
            goto L_80050004;
    }
    // 0x8004FFF0: nop

    // 0x8004FFF4: sh          $t1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r9;
    // 0x8004FFF8: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
    // 0x8004FFFC: j           L_80050010
    // 0x80050000: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_80050010;
    // 0x80050000: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050004:
    // 0x80050004: sh          $t1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r9;
    // 0x80050008: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x8005000C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050010:
    // 0x80050010: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050014: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050018: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005001C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050020: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050024: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050028: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x8005002C: bne         $v0, $zero, L_80050010
    if (ctx->r2 != 0) {
        // 0x80050030: nop
    
            goto L_80050010;
    }
    // 0x80050030: nop

    // 0x80050034: sb          $t0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r8;
    // 0x80050038: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8005003C:
    // 0x8005003C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050040: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050044: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050048: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005004C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050050: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050054: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050058: bne         $v0, $zero, L_8005003C
    if (ctx->r2 != 0) {
        // 0x8005005C: nop
    
            goto L_8005003C;
    }
    // 0x8005005C: nop

    // 0x80050060: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80050064: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x80050068: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8005006C:
    // 0x8005006C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050070: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050074: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050078: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005007C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050080: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050084: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050088: bne         $v0, $zero, L_8005006C
    if (ctx->r2 != 0) {
        // 0x8005008C: nop
    
            goto L_8005006C;
    }
    // 0x8005008C: nop

    // 0x80050090: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80050094: slti        $v0, $a0, 0x7
    ctx->r2 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // 0x80050098: bne         $v0, $zero, L_8004FFEC
    if (ctx->r2 != 0) {
        // 0x8005009C: andi        $v0, $s0, 0x80
        ctx->r2 = ctx->r16 & 0X80;
            goto L_8004FFEC;
    }
    // 0x8005009C: andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
    // 0x800500A0: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x800500A4: ori         $v1, $v1, 0x70
    ctx->r3 = ctx->r3 | 0X70;
    // 0x800500A8: lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // 0x800500AC: ori         $a0, $a0, 0xF
    ctx->r4 = ctx->r4 | 0XF;
    // 0x800500B0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800500B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800500B8: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800500BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800500C0: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_800500C4:
    // 0x800500C4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800500C8: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800500CC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800500D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800500D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800500D8: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x800500DC: slti        $v0, $a1, 0x100
    ctx->r2 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x800500E0: bne         $v0, $zero, L_800500C4
    if (ctx->r2 != 0) {
        // 0x800500E4: lui         $v1, 0x200
        ctx->r3 = S32(0X200 << 16);
            goto L_800500C4;
    }
    // 0x800500E4: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x800500E8: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x800500EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800500F0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800500F4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800500F8:
    // 0x800500F8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800500FC: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050100: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050104: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050108: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005010C: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050110: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050114: bne         $v0, $zero, L_800500F8
    if (ctx->r2 != 0) {
        // 0x80050118: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_800500F8;
    }
    // 0x80050118: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x8005011C: ori         $v0, $v0, 0xD
    ctx->r2 = ctx->r2 | 0XD;
    // 0x80050120: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80050124: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050128:
    // 0x80050128: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005012C: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050130: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050134: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050138: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005013C: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050140: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050144: bne         $v0, $zero, L_80050128
    if (ctx->r2 != 0) {
        // 0x80050148: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_80050128;
    }
    // 0x80050148: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x8005014C: ori         $v0, $v0, 0x70
    ctx->r2 = ctx->r2 | 0X70;
    // 0x80050150: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80050154: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050158:
    // 0x80050158: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005015C: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050160: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050164: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050168: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005016C: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050170: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050174: bne         $v0, $zero, L_80050158
    if (ctx->r2 != 0) {
        // 0x80050178: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80050158;
    }
    // 0x80050178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005017C: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80050180: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x80050184: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80050188: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8005018C:
    // 0x8005018C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050190: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050194: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050198: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005019C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800501A0: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x800501A4: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800501A8: bne         $v0, $zero, L_8005018C
    if (ctx->r2 != 0) {
        // 0x800501AC: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_8005018C;
    }
    // 0x800501AC: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x800501B0: ori         $v0, $v0, 0x9
    ctx->r2 = ctx->r2 | 0X9;
    // 0x800501B4: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x800501B8: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800501BC: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x800501C0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800501C4: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800501C8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800501CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800501D0: sw          $v0, -0x68A8($at)
    MEM_W(-0X68A8, ctx->r1) = ctx->r2;
L_800501D4:
    // 0x800501D4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800501D8: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800501DC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800501E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800501E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800501E8: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x800501EC: slti        $v0, $a0, 0x100
    ctx->r2 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x800501F0: bne         $v0, $zero, L_800501D4
    if (ctx->r2 != 0) {
        // 0x800501F4: nop
    
            goto L_800501D4;
    }
    // 0x800501F4: nop

    // 0x800501F8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800501FC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80050200: lui         $t0, 0x200
    ctx->r8 = S32(0X200 << 16);
    // 0x80050204: ori         $t0, $t0, 0x70
    ctx->r8 = ctx->r8 | 0X70;
    // 0x80050208: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    // 0x8005020C: ori         $a1, $a1, 0xD
    ctx->r5 = ctx->r5 | 0XD;
    // 0x80050210: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80050214: lui         $a3, 0x200
    ctx->r7 = S32(0X200 << 16);
    // 0x80050218: ori         $a3, $a3, 0x9
    ctx->r7 = ctx->r7 | 0X9;
    // 0x8005021C: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
L_80050220:
    // 0x80050220: srl         $a2, $v0, 1
    ctx->r6 = S32(U32(ctx->r2) >> 1);
    // 0x80050224: sh          $zero, 0x0($t0)
    MEM_H(0X0, ctx->r8) = 0;
    // 0x80050228: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8005022C:
    // 0x8005022C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050230: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050234: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050238: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005023C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050240: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050244: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050248: bne         $v0, $zero, L_8005022C
    if (ctx->r2 != 0) {
        // 0x8005024C: nop
    
            goto L_8005022C;
    }
    // 0x8005024C: nop

    // 0x80050250: sb          $t1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r9;
    // 0x80050254: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050258:
    // 0x80050258: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005025C: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050260: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050264: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050268: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005026C: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050270: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050274: bne         $v0, $zero, L_80050258
    if (ctx->r2 != 0) {
        // 0x80050278: nop
    
            goto L_80050258;
    }
    // 0x80050278: nop

    // 0x8005027C: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x80050280: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80050284: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80050288: bne         $v0, $zero, L_80050294
    if (ctx->r2 != 0) {
        // 0x8005028C: addiu       $v0, $zero, 0x80
        ctx->r2 = ADD32(0, 0X80);
            goto L_80050294;
    }
    // 0x8005028C: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x80050290: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80050294:
    // 0x80050294: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // 0x80050298: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8005029C:
    // 0x8005029C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800502A0: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800502A4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800502A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800502AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800502B0: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x800502B4: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800502B8: bne         $v0, $zero, L_8005029C
    if (ctx->r2 != 0) {
        // 0x800502BC: nop
    
            goto L_8005029C;
    }
    // 0x800502BC: nop

    // 0x800502C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800502C4: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800502C8: bne         $v0, $zero, L_80050220
    if (ctx->r2 != 0) {
        // 0x800502CC: andi        $v0, $a2, 0xFF
        ctx->r2 = ctx->r6 & 0XFF;
            goto L_80050220;
    }
    // 0x800502CC: andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // 0x800502D0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800502D4:
    // 0x800502D4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800502D8: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800502DC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800502E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800502E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800502E8: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x800502EC: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800502F0: bne         $v0, $zero, L_800502D4
    if (ctx->r2 != 0) {
        // 0x800502F4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800502D4;
    }
    // 0x800502F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800502F8: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x800502FC: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x80050300: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80050304: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050308:
    // 0x80050308: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005030C: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050310: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050314: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050318: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005031C: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050320: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050324: bne         $v0, $zero, L_80050308
    if (ctx->r2 != 0) {
        // 0x80050328: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_80050308;
    }
    // 0x80050328: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x8005032C: ori         $v0, $v0, 0xD
    ctx->r2 = ctx->r2 | 0XD;
    // 0x80050330: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80050334: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050338:
    // 0x80050338: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005033C: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050340: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050344: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050348: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005034C: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050350: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050354: bne         $v0, $zero, L_80050338
    if (ctx->r2 != 0) {
        // 0x80050358: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80050338;
    }
    // 0x80050358: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8005035C: lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // 0x80050360: ori         $a0, $a0, 0x70
    ctx->r4 = ctx->r4 | 0X70;
    // 0x80050364: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80050368: ori         $v1, $v1, 0xF
    ctx->r3 = ctx->r3 | 0XF;
    // 0x8005036C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80050370: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x80050374: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_80050378:
    // 0x80050378: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005037C: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050380: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80050384: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050388: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005038C: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050390: slti        $v0, $a1, 0x100
    ctx->r2 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x80050394: bne         $v0, $zero, L_80050378
    if (ctx->r2 != 0) {
        // 0x80050398: lui         $v1, 0x200
        ctx->r3 = S32(0X200 << 16);
            goto L_80050378;
    }
    // 0x80050398: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x8005039C: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x800503A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800503A4: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800503A8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800503AC:
    // 0x800503AC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800503B0: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800503B4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800503B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800503BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800503C0: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x800503C4: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800503C8: bne         $v0, $zero, L_800503AC
    if (ctx->r2 != 0) {
        // 0x800503CC: lui         $a0, 0x200
        ctx->r4 = S32(0X200 << 16);
            goto L_800503AC;
    }
    // 0x800503CC: lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // 0x800503D0: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x800503D4: ori         $v1, $v1, 0x70
    ctx->r3 = ctx->r3 | 0X70;
    // 0x800503D8: ori         $a0, $a0, 0xF
    ctx->r4 = ctx->r4 | 0XF;
    // 0x800503DC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800503E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800503E4: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800503E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800503EC: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_800503F0:
    // 0x800503F0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800503F4: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800503F8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800503FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050400: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050404: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050408: slti        $v0, $a1, 0x100
    ctx->r2 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x8005040C: bne         $v0, $zero, L_800503F0
    if (ctx->r2 != 0) {
        // 0x80050410: nop
    
            goto L_800503F0;
    }
    // 0x80050410: nop

    // 0x80050414: sb          $a2, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r6;
    // 0x80050418: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x8005041C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80050420: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80050424: jr          $ra
    // 0x80050428: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80050428: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8005042C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005042C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80050430: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80050434: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80050438: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005043C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80050440: jal         0x8004FE40
    // 0x80050444: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    func_8004FE40(rdram, ctx);
        goto after_0;
    // 0x80050444: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    after_0:
    // 0x80050448: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8005044C:
    // 0x8005044C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050450: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050454: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050458: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005045C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050460: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050464: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050468: bne         $v0, $zero, L_8005044C
    if (ctx->r2 != 0) {
        // 0x8005046C: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8005044C;
    }
    // 0x8005046C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80050470: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x80050474: lui         $a3, 0x200
    ctx->r7 = S32(0X200 << 16);
    // 0x80050478: ori         $a3, $a3, 0x70
    ctx->r7 = ctx->r7 | 0X70;
    // 0x8005047C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80050480: lui         $a2, 0x200
    ctx->r6 = S32(0X200 << 16);
    // 0x80050484: ori         $a2, $a2, 0xF
    ctx->r6 = ctx->r6 | 0XF;
    // 0x80050488: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005048C: lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // 0x80050490: ori         $a0, $a0, 0xD
    ctx->r4 = ctx->r4 | 0XD;
    // 0x80050494: andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
L_80050498:
    // 0x80050498: beq         $v0, $zero, L_800504B0
    if (ctx->r2 == 0) {
        // 0x8005049C: nop
    
            goto L_800504B0;
    }
    // 0x8005049C: nop

    // 0x800504A0: sh          $t1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r9;
    // 0x800504A4: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
    // 0x800504A8: j           L_800504BC
    // 0x800504AC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_800504BC;
    // 0x800504AC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800504B0:
    // 0x800504B0: sh          $t1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r9;
    // 0x800504B4: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x800504B8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800504BC:
    // 0x800504BC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800504C0: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800504C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800504C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800504CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800504D0: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x800504D4: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800504D8: bne         $v0, $zero, L_800504BC
    if (ctx->r2 != 0) {
        // 0x800504DC: nop
    
            goto L_800504BC;
    }
    // 0x800504DC: nop

    // 0x800504E0: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
    // 0x800504E4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800504E8:
    // 0x800504E8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800504EC: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800504F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800504F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800504F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800504FC: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050500: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050504: bne         $v0, $zero, L_800504E8
    if (ctx->r2 != 0) {
        // 0x80050508: nop
    
            goto L_800504E8;
    }
    // 0x80050508: nop

    // 0x8005050C: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80050510: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x80050514: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050518:
    // 0x80050518: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005051C: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050520: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050524: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050528: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005052C: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050530: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050534: bne         $v0, $zero, L_80050518
    if (ctx->r2 != 0) {
        // 0x80050538: nop
    
            goto L_80050518;
    }
    // 0x80050538: nop

    // 0x8005053C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80050540: slti        $v0, $a1, 0x7
    ctx->r2 = SIGNED(ctx->r5) < 0X7 ? 1 : 0;
    // 0x80050544: bne         $v0, $zero, L_80050498
    if (ctx->r2 != 0) {
        // 0x80050548: andi        $v0, $s0, 0x80
        ctx->r2 = ctx->r16 & 0X80;
            goto L_80050498;
    }
    // 0x80050548: andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
    // 0x8005054C: lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // 0x80050550: ori         $a0, $a0, 0x70
    ctx->r4 = ctx->r4 | 0X70;
    // 0x80050554: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80050558: ori         $v1, $v1, 0xF
    ctx->r3 = ctx->r3 | 0XF;
    // 0x8005055C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80050560: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80050564: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x80050568: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_8005056C:
    // 0x8005056C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050570: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050574: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80050578: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005057C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050580: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050584: slti        $v0, $a1, 0x100
    ctx->r2 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x80050588: bne         $v0, $zero, L_8005056C
    if (ctx->r2 != 0) {
        // 0x8005058C: lui         $v1, 0x200
        ctx->r3 = S32(0X200 << 16);
            goto L_8005056C;
    }
    // 0x8005058C: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80050590: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x80050594: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80050598: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8005059C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800505A0:
    // 0x800505A0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800505A4: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800505A8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800505AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800505B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800505B4: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x800505B8: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800505BC: bne         $v0, $zero, L_800505A0
    if (ctx->r2 != 0) {
        // 0x800505C0: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_800505A0;
    }
    // 0x800505C0: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x800505C4: ori         $v0, $v0, 0xD
    ctx->r2 = ctx->r2 | 0XD;
    // 0x800505C8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x800505CC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800505D0:
    // 0x800505D0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800505D4: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800505D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800505DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800505E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800505E4: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x800505E8: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800505EC: bne         $v0, $zero, L_800505D0
    if (ctx->r2 != 0) {
        // 0x800505F0: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_800505D0;
    }
    // 0x800505F0: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x800505F4: ori         $v0, $v0, 0x70
    ctx->r2 = ctx->r2 | 0X70;
    // 0x800505F8: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x800505FC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050600:
    // 0x80050600: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050604: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050608: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005060C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050610: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050614: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050618: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x8005061C: bne         $v0, $zero, L_80050600
    if (ctx->r2 != 0) {
        // 0x80050620: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80050600;
    }
    // 0x80050620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80050624: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80050628: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x8005062C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80050630: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050634:
    // 0x80050634: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050638: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x8005063C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050640: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050644: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050648: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x8005064C: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050650: bne         $v0, $zero, L_80050634
    if (ctx->r2 != 0) {
        // 0x80050654: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_80050634;
    }
    // 0x80050654: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x80050658: ori         $v0, $v0, 0x9
    ctx->r2 = ctx->r2 | 0X9;
    // 0x8005065C: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80050660: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80050664: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x80050668: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005066C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80050670: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80050674: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050678: sw          $v0, -0x68A8($at)
    MEM_W(-0X68A8, ctx->r1) = ctx->r2;
L_8005067C:
    // 0x8005067C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050680: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050684: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80050688: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005068C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050690: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050694: slti        $v0, $a0, 0x100
    ctx->r2 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x80050698: bne         $v0, $zero, L_8005067C
    if (ctx->r2 != 0) {
        // 0x8005069C: addiu       $t2, $zero, -0x1
        ctx->r10 = ADD32(0, -0X1);
            goto L_8005067C;
    }
    // 0x8005069C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800506A0: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x800506A4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800506A8: lui         $t0, 0x200
    ctx->r8 = S32(0X200 << 16);
    // 0x800506AC: ori         $t0, $t0, 0x70
    ctx->r8 = ctx->r8 | 0X70;
    // 0x800506B0: lui         $a3, 0x200
    ctx->r7 = S32(0X200 << 16);
    // 0x800506B4: ori         $a3, $a3, 0xF
    ctx->r7 = ctx->r7 | 0XF;
    // 0x800506B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800506BC: lui         $a2, 0x200
    ctx->r6 = S32(0X200 << 16);
    // 0x800506C0: ori         $a2, $a2, 0xD
    ctx->r6 = ctx->r6 | 0XD;
    // 0x800506C4: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
L_800506C8:
    // 0x800506C8: beq         $v0, $zero, L_800506E0
    if (ctx->r2 == 0) {
        // 0x800506CC: nop
    
            goto L_800506E0;
    }
    // 0x800506CC: nop

    // 0x800506D0: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
    // 0x800506D4: sb          $t1, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r9;
    // 0x800506D8: j           L_800506EC
    // 0x800506DC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_800506EC;
    // 0x800506DC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800506E0:
    // 0x800506E0: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
    // 0x800506E4: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
    // 0x800506E8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800506EC:
    // 0x800506EC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800506F0: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800506F4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800506F8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800506FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050700: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050704: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050708: bne         $v0, $zero, L_800506EC
    if (ctx->r2 != 0) {
        // 0x8005070C: nop
    
            goto L_800506EC;
    }
    // 0x8005070C: nop

    // 0x80050710: sb          $t1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r9;
    // 0x80050714: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050718:
    // 0x80050718: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005071C: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050720: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050724: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050728: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005072C: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050730: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050734: bne         $v0, $zero, L_80050718
    if (ctx->r2 != 0) {
        // 0x80050738: nop
    
            goto L_80050718;
    }
    // 0x80050738: nop

    // 0x8005073C: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x80050740: srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // 0x80050744: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050748:
    // 0x80050748: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005074C: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050750: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050754: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050758: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005075C: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050760: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050764: bne         $v0, $zero, L_80050748
    if (ctx->r2 != 0) {
        // 0x80050768: nop
    
            goto L_80050748;
    }
    // 0x80050768: nop

    // 0x8005076C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80050770: slti        $v0, $a1, 0x8
    ctx->r2 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x80050774: bne         $v0, $zero, L_800506C8
    if (ctx->r2 != 0) {
        // 0x80050778: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_800506C8;
    }
    // 0x80050778: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x8005077C: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x80050780: ori         $v0, $v0, 0x70
    ctx->r2 = ctx->r2 | 0X70;
    // 0x80050784: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80050788: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8005078C:
    // 0x8005078C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050790: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050794: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050798: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005079C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800507A0: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x800507A4: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800507A8: bne         $v0, $zero, L_8005078C
    if (ctx->r2 != 0) {
        // 0x800507AC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005078C;
    }
    // 0x800507AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800507B0: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x800507B4: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x800507B8: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800507BC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800507C0:
    // 0x800507C0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800507C4: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800507C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800507CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800507D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800507D4: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x800507D8: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800507DC: bne         $v0, $zero, L_800507C0
    if (ctx->r2 != 0) {
        // 0x800507E0: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_800507C0;
    }
    // 0x800507E0: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x800507E4: ori         $v0, $v0, 0x9
    ctx->r2 = ctx->r2 | 0X9;
    // 0x800507E8: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x800507EC: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800507F0: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x800507F4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800507F8: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800507FC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80050800: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050804: sw          $v0, -0x68A4($at)
    MEM_W(-0X68A4, ctx->r1) = ctx->r2;
L_80050808:
    // 0x80050808: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005080C: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050810: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80050814: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050818: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005081C: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050820: slti        $v0, $a0, 0x100
    ctx->r2 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x80050824: bne         $v0, $zero, L_80050808
    if (ctx->r2 != 0) {
        // 0x80050828: lui         $v1, 0x200
        ctx->r3 = S32(0X200 << 16);
            goto L_80050808;
    }
    // 0x80050828: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x8005082C: lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // 0x80050830: ori         $a0, $a0, 0x70
    ctx->r4 = ctx->r4 | 0X70;
    // 0x80050834: ori         $v1, $v1, 0xF
    ctx->r3 = ctx->r3 | 0XF;
    // 0x80050838: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005083C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80050840: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x80050844: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_80050848:
    // 0x80050848: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005084C: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050850: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80050854: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050858: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005085C: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050860: slti        $v0, $a1, 0x100
    ctx->r2 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x80050864: bne         $v0, $zero, L_80050848
    if (ctx->r2 != 0) {
        // 0x80050868: lui         $v1, 0x200
        ctx->r3 = S32(0X200 << 16);
            goto L_80050848;
    }
    // 0x80050868: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x8005086C: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x80050870: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80050874: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80050878: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8005087C:
    // 0x8005087C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050880: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050884: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050888: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005088C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050890: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050894: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050898: bne         $v0, $zero, L_8005087C
    if (ctx->r2 != 0) {
        // 0x8005089C: lui         $a0, 0x200
        ctx->r4 = S32(0X200 << 16);
            goto L_8005087C;
    }
    // 0x8005089C: lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // 0x800508A0: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x800508A4: ori         $v1, $v1, 0x70
    ctx->r3 = ctx->r3 | 0X70;
    // 0x800508A8: ori         $a0, $a0, 0xF
    ctx->r4 = ctx->r4 | 0XF;
    // 0x800508AC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800508B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800508B4: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800508B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800508BC: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_800508C0:
    // 0x800508C0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800508C4: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800508C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800508CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800508D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800508D4: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x800508D8: slti        $v0, $a1, 0x100
    ctx->r2 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x800508DC: bne         $v0, $zero, L_800508C0
    if (ctx->r2 != 0) {
        // 0x800508E0: ori         $a0, $zero, 0xA000
        ctx->r4 = 0 | 0XA000;
            goto L_800508C0;
    }
    // 0x800508E0: ori         $a0, $zero, 0xA000
    ctx->r4 = 0 | 0XA000;
    // 0x800508E4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800508E8:
    // 0x800508E8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800508EC: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800508F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800508F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800508F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800508FC: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050900: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80050904: bne         $v0, $zero, L_800508E8
    if (ctx->r2 != 0) {
        // 0x80050908: nop
    
            goto L_800508E8;
    }
    // 0x80050908: nop

    // 0x8005090C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80050910: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80050914: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80050918: jr          $ra
    // 0x8005091C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005091C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80050920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050920: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80050924: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80050928: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8005092C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80050930: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80050934: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80050938: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005093C: jal         0x8004FE40
    // 0x80050940: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    func_8004FE40(rdram, ctx);
        goto after_0;
    // 0x80050940: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    after_0:
    // 0x80050944: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050948:
    // 0x80050948: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005094C: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050950: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050954: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050958: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005095C: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050960: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050964: bne         $v0, $zero, L_80050948
    if (ctx->r2 != 0) {
        // 0x80050968: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80050948;
    }
    // 0x80050968: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005096C: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x80050970: lui         $a3, 0x200
    ctx->r7 = S32(0X200 << 16);
    // 0x80050974: ori         $a3, $a3, 0x70
    ctx->r7 = ctx->r7 | 0X70;
    // 0x80050978: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8005097C: lui         $a2, 0x200
    ctx->r6 = S32(0X200 << 16);
    // 0x80050980: ori         $a2, $a2, 0xF
    ctx->r6 = ctx->r6 | 0XF;
    // 0x80050984: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80050988: lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // 0x8005098C: ori         $a0, $a0, 0xD
    ctx->r4 = ctx->r4 | 0XD;
    // 0x80050990: andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
L_80050994:
    // 0x80050994: beq         $v0, $zero, L_800509AC
    if (ctx->r2 == 0) {
        // 0x80050998: nop
    
            goto L_800509AC;
    }
    // 0x80050998: nop

    // 0x8005099C: sh          $t1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r9;
    // 0x800509A0: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
    // 0x800509A4: j           L_800509B8
    // 0x800509A8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_800509B8;
    // 0x800509A8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800509AC:
    // 0x800509AC: sh          $t1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r9;
    // 0x800509B0: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x800509B4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800509B8:
    // 0x800509B8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800509BC: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800509C0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800509C4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800509C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800509CC: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x800509D0: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800509D4: bne         $v0, $zero, L_800509B8
    if (ctx->r2 != 0) {
        // 0x800509D8: nop
    
            goto L_800509B8;
    }
    // 0x800509D8: nop

    // 0x800509DC: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
    // 0x800509E0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800509E4:
    // 0x800509E4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800509E8: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800509EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800509F0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800509F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800509F8: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x800509FC: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050A00: bne         $v0, $zero, L_800509E4
    if (ctx->r2 != 0) {
        // 0x80050A04: nop
    
            goto L_800509E4;
    }
    // 0x80050A04: nop

    // 0x80050A08: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80050A0C: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x80050A10: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050A14:
    // 0x80050A14: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050A18: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050A1C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050A20: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050A24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050A28: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050A2C: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050A30: bne         $v0, $zero, L_80050A14
    if (ctx->r2 != 0) {
        // 0x80050A34: nop
    
            goto L_80050A14;
    }
    // 0x80050A34: nop

    // 0x80050A38: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80050A3C: slti        $v0, $a1, 0x7
    ctx->r2 = SIGNED(ctx->r5) < 0X7 ? 1 : 0;
    // 0x80050A40: bne         $v0, $zero, L_80050994
    if (ctx->r2 != 0) {
        // 0x80050A44: andi        $v0, $s0, 0x80
        ctx->r2 = ctx->r16 & 0X80;
            goto L_80050994;
    }
    // 0x80050A44: andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
    // 0x80050A48: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80050A4C: ori         $v1, $v1, 0x70
    ctx->r3 = ctx->r3 | 0X70;
    // 0x80050A50: lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // 0x80050A54: ori         $a0, $a0, 0xF
    ctx->r4 = ctx->r4 | 0XF;
    // 0x80050A58: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80050A5C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80050A60: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80050A64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80050A68: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_80050A6C:
    // 0x80050A6C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050A70: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050A74: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80050A78: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050A7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050A80: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050A84: slti        $v0, $a1, 0x100
    ctx->r2 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x80050A88: bne         $v0, $zero, L_80050A6C
    if (ctx->r2 != 0) {
        // 0x80050A8C: lui         $v1, 0x200
        ctx->r3 = S32(0X200 << 16);
            goto L_80050A6C;
    }
    // 0x80050A8C: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80050A90: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x80050A94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80050A98: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80050A9C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050AA0:
    // 0x80050AA0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050AA4: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050AA8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050AAC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050AB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050AB4: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050AB8: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050ABC: bne         $v0, $zero, L_80050AA0
    if (ctx->r2 != 0) {
        // 0x80050AC0: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_80050AA0;
    }
    // 0x80050AC0: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x80050AC4: ori         $v0, $v0, 0xD
    ctx->r2 = ctx->r2 | 0XD;
    // 0x80050AC8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80050ACC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050AD0:
    // 0x80050AD0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050AD4: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050AD8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050ADC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050AE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050AE4: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050AE8: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050AEC: bne         $v0, $zero, L_80050AD0
    if (ctx->r2 != 0) {
        // 0x80050AF0: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_80050AD0;
    }
    // 0x80050AF0: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x80050AF4: ori         $v0, $v0, 0x70
    ctx->r2 = ctx->r2 | 0X70;
    // 0x80050AF8: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80050AFC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050B00:
    // 0x80050B00: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050B04: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050B08: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050B0C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050B10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050B14: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050B18: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050B1C: bne         $v0, $zero, L_80050B00
    if (ctx->r2 != 0) {
        // 0x80050B20: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80050B00;
    }
    // 0x80050B20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80050B24: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80050B28: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x80050B2C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80050B30: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050B34:
    // 0x80050B34: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050B38: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050B3C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050B40: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050B44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050B48: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050B4C: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050B50: bne         $v0, $zero, L_80050B34
    if (ctx->r2 != 0) {
        // 0x80050B54: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_80050B34;
    }
    // 0x80050B54: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x80050B58: ori         $v0, $v0, 0x9
    ctx->r2 = ctx->r2 | 0X9;
    // 0x80050B5C: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80050B60: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80050B64: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x80050B68: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80050B6C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80050B70: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80050B74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050B78: sw          $v0, -0x68A8($at)
    MEM_W(-0X68A8, ctx->r1) = ctx->r2;
L_80050B7C:
    // 0x80050B7C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050B80: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050B84: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80050B88: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050B8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050B90: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050B94: slti        $v0, $a0, 0x100
    ctx->r2 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x80050B98: bne         $v0, $zero, L_80050B7C
    if (ctx->r2 != 0) {
        // 0x80050B9C: nop
    
            goto L_80050B7C;
    }
    // 0x80050B9C: nop

    // 0x80050BA0: blez        $s2, L_80050DF4
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80050BA4: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_80050DF4;
    }
    // 0x80050BA4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80050BA8: lui         $t2, 0x200
    ctx->r10 = S32(0X200 << 16);
    // 0x80050BAC: ori         $t2, $t2, 0x70
    ctx->r10 = ctx->r10 | 0X70;
    // 0x80050BB0: lui         $a2, 0x200
    ctx->r6 = S32(0X200 << 16);
    // 0x80050BB4: ori         $a2, $a2, 0xD
    ctx->r6 = ctx->r6 | 0XD;
    // 0x80050BB8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80050BBC: lui         $t0, 0x200
    ctx->r8 = S32(0X200 << 16);
    // 0x80050BC0: ori         $t0, $t0, 0x9
    ctx->r8 = ctx->r8 | 0X9;
L_80050BC4:
    // 0x80050BC4: sb          $zero, 0x10($sp)
    MEM_B(0X10, ctx->r29) = 0;
    // 0x80050BC8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80050BCC:
    // 0x80050BCC: lbu         $v0, 0x10($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X10);
    // 0x80050BD0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80050BD4: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x80050BD8: sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    // 0x80050BDC: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
L_80050BE0:
    // 0x80050BE0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050BE4: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050BE8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050BEC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050BF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050BF4: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050BF8: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050BFC: bne         $v0, $zero, L_80050BE0
    if (ctx->r2 != 0) {
        // 0x80050C00: nop
    
            goto L_80050BE0;
    }
    // 0x80050C00: nop

    // 0x80050C04: sb          $t1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r9;
    // 0x80050C08: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050C0C:
    // 0x80050C0C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050C10: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050C14: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050C18: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050C1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050C20: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050C24: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050C28: bne         $v0, $zero, L_80050C0C
    if (ctx->r2 != 0) {
        // 0x80050C2C: nop
    
            goto L_80050C0C;
    }
    // 0x80050C2C: nop

    // 0x80050C30: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x80050C34: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x80050C38: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80050C3C: bne         $v0, $zero, L_80050C48
    if (ctx->r2 != 0) {
        // 0x80050C40: addiu       $a0, $zero, 0x80
        ctx->r4 = ADD32(0, 0X80);
            goto L_80050C48;
    }
    // 0x80050C40: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x80050C44: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80050C48:
    // 0x80050C48: lbu         $v0, 0x10($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X10);
    // 0x80050C4C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80050C50: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x80050C54: sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
L_80050C58:
    // 0x80050C58: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050C5C: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050C60: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050C64: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050C68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050C6C: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050C70: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050C74: bne         $v0, $zero, L_80050C58
    if (ctx->r2 != 0) {
        // 0x80050C78: nop
    
            goto L_80050C58;
    }
    // 0x80050C78: nop

    // 0x80050C7C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80050C80: slti        $v0, $a1, 0x8
    ctx->r2 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x80050C84: bne         $v0, $zero, L_80050BCC
    if (ctx->r2 != 0) {
        // 0x80050C88: nop
    
            goto L_80050BCC;
    }
    // 0x80050C88: nop

    // 0x80050C8C: lbu         $v0, 0x10($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X10);
    // 0x80050C90: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x80050C94: addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // 0x80050C98: slt         $v0, $a3, $v0
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80050C9C: beq         $v0, $zero, L_80050D64
    if (ctx->r2 == 0) {
        // 0x80050CA0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80050D64;
    }
    // 0x80050CA0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80050CA4: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x80050CA8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050CAC:
    // 0x80050CAC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050CB0: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050CB4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050CB8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050CBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050CC0: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050CC4: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050CC8: bne         $v0, $zero, L_80050CAC
    if (ctx->r2 != 0) {
        // 0x80050CCC: nop
    
            goto L_80050CAC;
    }
    // 0x80050CCC: nop

    // 0x80050CD0: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x80050CD4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050CD8:
    // 0x80050CD8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050CDC: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050CE0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050CE4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050CE8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050CEC: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050CF0: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050CF4: bne         $v0, $zero, L_80050CD8
    if (ctx->r2 != 0) {
        // 0x80050CF8: nop
    
            goto L_80050CD8;
    }
    // 0x80050CF8: nop

    // 0x80050CFC: sb          $t1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r9;
    // 0x80050D00: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050D04:
    // 0x80050D04: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050D08: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050D0C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050D10: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050D14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050D18: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050D1C: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050D20: bne         $v0, $zero, L_80050D04
    if (ctx->r2 != 0) {
        // 0x80050D24: nop
    
            goto L_80050D04;
    }
    // 0x80050D24: nop

    // 0x80050D28: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80050D2C: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x80050D30: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050D34: sw          $zero, -0x68A8($at)
    MEM_W(-0X68A8, ctx->r1) = 0;
L_80050D38:
    // 0x80050D38: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050D3C: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050D40: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050D44: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050D48: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050D4C: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050D50: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050D54: bne         $v0, $zero, L_80050D38
    if (ctx->r2 != 0) {
        // 0x80050D58: nop
    
            goto L_80050D38;
    }
    // 0x80050D58: nop

    // 0x80050D5C: j           L_80050DE8
    // 0x80050D60: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
        goto L_80050DE8;
    // 0x80050D60: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_80050D64:
    // 0x80050D64: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050D68:
    // 0x80050D68: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050D6C: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050D70: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050D74: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050D78: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050D7C: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050D80: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050D84: bne         $v0, $zero, L_80050D68
    if (ctx->r2 != 0) {
        // 0x80050D88: nop
    
            goto L_80050D68;
    }
    // 0x80050D88: nop

    // 0x80050D8C: sb          $t1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r9;
    // 0x80050D90: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050D94:
    // 0x80050D94: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050D98: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050D9C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050DA0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050DA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050DA8: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050DAC: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050DB0: bne         $v0, $zero, L_80050D94
    if (ctx->r2 != 0) {
        // 0x80050DB4: nop
    
            goto L_80050D94;
    }
    // 0x80050DB4: nop

    // 0x80050DB8: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x80050DBC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050DC0:
    // 0x80050DC0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050DC4: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050DC8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050DCC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050DD0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050DD4: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050DD8: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050DDC: bne         $v0, $zero, L_80050DC0
    if (ctx->r2 != 0) {
        // 0x80050DE0: nop
    
            goto L_80050DC0;
    }
    // 0x80050DE0: nop

    // 0x80050DE4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_80050DE8:
    // 0x80050DE8: slt         $v0, $a3, $s2
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80050DEC: bne         $v0, $zero, L_80050BC4
    if (ctx->r2 != 0) {
        // 0x80050DF0: nop
    
            goto L_80050BC4;
    }
    // 0x80050DF0: nop

L_80050DF4:
    // 0x80050DF4: lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // 0x80050DF8: ori         $a0, $a0, 0x70
    ctx->r4 = ctx->r4 | 0X70;
    // 0x80050DFC: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80050E00: ori         $v1, $v1, 0xF
    ctx->r3 = ctx->r3 | 0XF;
    // 0x80050E04: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80050E08: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80050E0C: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x80050E10: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_80050E14:
    // 0x80050E14: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050E18: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050E1C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80050E20: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050E24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050E28: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050E2C: slti        $v0, $a1, 0x100
    ctx->r2 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x80050E30: bne         $v0, $zero, L_80050E14
    if (ctx->r2 != 0) {
        // 0x80050E34: lui         $v1, 0x200
        ctx->r3 = S32(0X200 << 16);
            goto L_80050E14;
    }
    // 0x80050E34: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80050E38: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x80050E3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80050E40: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80050E44: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050E48:
    // 0x80050E48: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050E4C: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050E50: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050E54: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050E58: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050E5C: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050E60: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80050E64: bne         $v0, $zero, L_80050E48
    if (ctx->r2 != 0) {
        // 0x80050E68: lui         $a0, 0x200
        ctx->r4 = S32(0X200 << 16);
            goto L_80050E48;
    }
    // 0x80050E68: lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // 0x80050E6C: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80050E70: ori         $v1, $v1, 0x70
    ctx->r3 = ctx->r3 | 0X70;
    // 0x80050E74: ori         $a0, $a0, 0xF
    ctx->r4 = ctx->r4 | 0XF;
    // 0x80050E78: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80050E7C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80050E80: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80050E84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80050E88: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_80050E8C:
    // 0x80050E8C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050E90: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050E94: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80050E98: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050E9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050EA0: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050EA4: slti        $v0, $a1, 0x100
    ctx->r2 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x80050EA8: bne         $v0, $zero, L_80050E8C
    if (ctx->r2 != 0) {
        // 0x80050EAC: nop
    
            goto L_80050E8C;
    }
    // 0x80050EAC: nop

    // 0x80050EB0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80050EB4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80050EB8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80050EBC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80050EC0: jr          $ra
    // 0x80050EC4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80050EC4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80050EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050EC8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80050ECC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80050ED0: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80050ED4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80050ED8: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x80050EDC: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x80050EE0: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x80050EE4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80050EE8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80050EEC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80050EF0: bgez        $a1, L_80050EFC
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80050EF4: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_80050EFC;
    }
    // 0x80050EF4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80050EF8: addiu       $v0, $a1, 0x3
    ctx->r2 = ADD32(ctx->r5, 0X3);
L_80050EFC:
    // 0x80050EFC: sra         $s4, $v0, 2
    ctx->r20 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80050F00: addu        $s3, $s4, $zero
    ctx->r19 = ADD32(ctx->r20, 0);
    // 0x80050F04: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
    // 0x80050F08: subu        $s4, $a1, $v0
    ctx->r20 = SUB32(ctx->r5, ctx->r2);
    // 0x80050F0C: blez        $s3, L_80050F64
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80050F10: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80050F64;
    }
    // 0x80050F10: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80050F14: ori         $s5, $zero, 0xA000
    ctx->r21 = 0 | 0XA000;
    // 0x80050F18: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_80050F1C:
    // 0x80050F1C: jal         0x80050FE0
    // 0x80050F20: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_80050FE0(rdram, ctx);
        goto after_0;
    // 0x80050F20: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_0:
    // 0x80050F24: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80050F28: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80050F2C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050F30:
    // 0x80050F30: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050F34: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050F38: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050F3C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050F40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050F44: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050F48: slt         $v0, $v1, $s5
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80050F4C: bne         $v0, $zero, L_80050F30
    if (ctx->r2 != 0) {
        // 0x80050F50: nop
    
            goto L_80050F30;
    }
    // 0x80050F50: nop

    // 0x80050F54: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80050F58: slt         $v0, $s0, $s3
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80050F5C: bne         $v0, $zero, L_80050F1C
    if (ctx->r2 != 0) {
        // 0x80050F60: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80050F1C;
    }
    // 0x80050F60: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_80050F64:
    // 0x80050F64: blez        $s4, L_80050FBC
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80050F68: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80050FBC;
    }
    // 0x80050F68: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80050F6C: ori         $s3, $zero, 0xA000
    ctx->r19 = 0 | 0XA000;
    // 0x80050F70: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_80050F74:
    // 0x80050F74: jal         0x8005042C
    // 0x80050F78: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_8005042C(rdram, ctx);
        goto after_1;
    // 0x80050F78: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_1:
    // 0x80050F7C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80050F80: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80050F84: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80050F88:
    // 0x80050F88: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80050F8C: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80050F90: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80050F94: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050F98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80050F9C: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80050FA0: slt         $v0, $v1, $s3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80050FA4: bne         $v0, $zero, L_80050F88
    if (ctx->r2 != 0) {
        // 0x80050FA8: nop
    
            goto L_80050F88;
    }
    // 0x80050FA8: nop

    // 0x80050FAC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80050FB0: slt         $v0, $s0, $s4
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80050FB4: bne         $v0, $zero, L_80050F74
    if (ctx->r2 != 0) {
        // 0x80050FB8: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80050F74;
    }
    // 0x80050FB8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_80050FBC:
    // 0x80050FBC: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x80050FC0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80050FC4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80050FC8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80050FCC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80050FD0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80050FD4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80050FD8: jr          $ra
    // 0x80050FDC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80050FDC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80050FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050FE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80050FE4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80050FE8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80050FEC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80050FF0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80050FF4: jal         0x8004FE40
    // 0x80050FF8: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    func_8004FE40(rdram, ctx);
        goto after_0;
    // 0x80050FF8: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    after_0:
    // 0x80050FFC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80051000:
    // 0x80051000: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051004: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80051008: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005100C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80051010: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051014: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80051018: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x8005101C: bne         $v0, $zero, L_80051000
    if (ctx->r2 != 0) {
        // 0x80051020: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80051000;
    }
    // 0x80051020: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80051024: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x80051028: lui         $a3, 0x200
    ctx->r7 = S32(0X200 << 16);
    // 0x8005102C: ori         $a3, $a3, 0x70
    ctx->r7 = ctx->r7 | 0X70;
    // 0x80051030: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80051034: lui         $a2, 0x200
    ctx->r6 = S32(0X200 << 16);
    // 0x80051038: ori         $a2, $a2, 0xF
    ctx->r6 = ctx->r6 | 0XF;
    // 0x8005103C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80051040: lui         $a1, 0x200
    ctx->r5 = S32(0X200 << 16);
    // 0x80051044: ori         $a1, $a1, 0xD
    ctx->r5 = ctx->r5 | 0XD;
    // 0x80051048: andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
L_8005104C:
    // 0x8005104C: beq         $v0, $zero, L_80051064
    if (ctx->r2 == 0) {
        // 0x80051050: nop
    
            goto L_80051064;
    }
    // 0x80051050: nop

    // 0x80051054: sh          $t1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r9;
    // 0x80051058: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
    // 0x8005105C: j           L_80051070
    // 0x80051060: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_80051070;
    // 0x80051060: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80051064:
    // 0x80051064: sh          $t1, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r9;
    // 0x80051068: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x8005106C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80051070:
    // 0x80051070: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051074: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80051078: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005107C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80051080: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051084: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80051088: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x8005108C: bne         $v0, $zero, L_80051070
    if (ctx->r2 != 0) {
        // 0x80051090: nop
    
            goto L_80051070;
    }
    // 0x80051090: nop

    // 0x80051094: sb          $t0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r8;
    // 0x80051098: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8005109C:
    // 0x8005109C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800510A0: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800510A4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800510A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800510AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800510B0: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x800510B4: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800510B8: bne         $v0, $zero, L_8005109C
    if (ctx->r2 != 0) {
        // 0x800510BC: nop
    
            goto L_8005109C;
    }
    // 0x800510BC: nop

    // 0x800510C0: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x800510C4: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x800510C8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800510CC:
    // 0x800510CC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800510D0: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800510D4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800510D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800510DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800510E0: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x800510E4: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800510E8: bne         $v0, $zero, L_800510CC
    if (ctx->r2 != 0) {
        // 0x800510EC: nop
    
            goto L_800510CC;
    }
    // 0x800510EC: nop

    // 0x800510F0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800510F4: slti        $v0, $a0, 0x7
    ctx->r2 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // 0x800510F8: bne         $v0, $zero, L_8005104C
    if (ctx->r2 != 0) {
        // 0x800510FC: andi        $v0, $s0, 0x80
        ctx->r2 = ctx->r16 & 0X80;
            goto L_8005104C;
    }
    // 0x800510FC: andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
    // 0x80051100: lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // 0x80051104: ori         $a0, $a0, 0x70
    ctx->r4 = ctx->r4 | 0X70;
    // 0x80051108: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x8005110C: ori         $v1, $v1, 0xF
    ctx->r3 = ctx->r3 | 0XF;
    // 0x80051110: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80051114: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80051118: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8005111C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_80051120:
    // 0x80051120: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051124: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80051128: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8005112C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80051130: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051134: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80051138: slti        $v0, $a1, 0x100
    ctx->r2 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x8005113C: bne         $v0, $zero, L_80051120
    if (ctx->r2 != 0) {
        // 0x80051140: lui         $v1, 0x200
        ctx->r3 = S32(0X200 << 16);
            goto L_80051120;
    }
    // 0x80051140: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80051144: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x80051148: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005114C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80051150: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80051154:
    // 0x80051154: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051158: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x8005115C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80051160: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80051164: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051168: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x8005116C: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80051170: bne         $v0, $zero, L_80051154
    if (ctx->r2 != 0) {
        // 0x80051174: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_80051154;
    }
    // 0x80051174: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x80051178: ori         $v0, $v0, 0xD
    ctx->r2 = ctx->r2 | 0XD;
    // 0x8005117C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80051180: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80051184:
    // 0x80051184: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051188: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x8005118C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80051190: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80051194: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051198: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x8005119C: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800511A0: bne         $v0, $zero, L_80051184
    if (ctx->r2 != 0) {
        // 0x800511A4: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_80051184;
    }
    // 0x800511A4: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x800511A8: ori         $v0, $v0, 0x70
    ctx->r2 = ctx->r2 | 0X70;
    // 0x800511AC: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x800511B0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800511B4:
    // 0x800511B4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800511B8: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800511BC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800511C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800511C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800511C8: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x800511CC: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800511D0: bne         $v0, $zero, L_800511B4
    if (ctx->r2 != 0) {
        // 0x800511D4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800511B4;
    }
    // 0x800511D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800511D8: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x800511DC: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x800511E0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800511E4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800511E8:
    // 0x800511E8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800511EC: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800511F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800511F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800511F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800511FC: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80051200: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80051204: bne         $v0, $zero, L_800511E8
    if (ctx->r2 != 0) {
        // 0x80051208: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_800511E8;
    }
    // 0x80051208: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x8005120C: ori         $v0, $v0, 0x9
    ctx->r2 = ctx->r2 | 0X9;
    // 0x80051210: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80051214: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80051218: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x8005121C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80051220: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80051224: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80051228: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005122C: sw          $v0, -0x68A8($at)
    MEM_W(-0X68A8, ctx->r1) = ctx->r2;
L_80051230:
    // 0x80051230: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051234: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80051238: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005123C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80051240: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051244: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80051248: slti        $v0, $a0, 0x100
    ctx->r2 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x8005124C: bne         $v0, $zero, L_80051230
    if (ctx->r2 != 0) {
        // 0x80051250: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_80051230;
    }
    // 0x80051250: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x80051254: lui         $a3, 0x200
    ctx->r7 = S32(0X200 << 16);
    // 0x80051258: ori         $a3, $a3, 0x70
    ctx->r7 = ctx->r7 | 0X70;
    // 0x8005125C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80051260: lui         $t0, 0x200
    ctx->r8 = S32(0X200 << 16);
    // 0x80051264: ori         $t0, $t0, 0xF
    ctx->r8 = ctx->r8 | 0XF;
    // 0x80051268: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005126C: lui         $a2, 0x200
    ctx->r6 = S32(0X200 << 16);
    // 0x80051270: ori         $a2, $a2, 0xD
    ctx->r6 = ctx->r6 | 0XD;
L_80051274:
    // 0x80051274: lbu         $a1, 0x0($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X0);
    // 0x80051278: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005127C: andi        $v0, $a1, 0x1
    ctx->r2 = ctx->r5 & 0X1;
L_80051280:
    // 0x80051280: beq         $v0, $zero, L_80051298
    if (ctx->r2 == 0) {
        // 0x80051284: nop
    
            goto L_80051298;
    }
    // 0x80051284: nop

    // 0x80051288: sh          $t3, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r11;
    // 0x8005128C: sb          $t1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r9;
    // 0x80051290: j           L_800512A4
    // 0x80051294: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
        goto L_800512A4;
    // 0x80051294: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80051298:
    // 0x80051298: sh          $t3, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r11;
    // 0x8005129C: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x800512A0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800512A4:
    // 0x800512A4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800512A8: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800512AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800512B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800512B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800512B8: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x800512BC: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800512C0: bne         $v0, $zero, L_800512A4
    if (ctx->r2 != 0) {
        // 0x800512C4: nop
    
            goto L_800512A4;
    }
    // 0x800512C4: nop

    // 0x800512C8: sb          $t1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r9;
    // 0x800512CC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800512D0:
    // 0x800512D0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800512D4: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800512D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800512DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800512E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800512E4: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x800512E8: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800512EC: bne         $v0, $zero, L_800512D0
    if (ctx->r2 != 0) {
        // 0x800512F0: nop
    
            goto L_800512D0;
    }
    // 0x800512F0: nop

    // 0x800512F4: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x800512F8: srl         $a1, $a1, 1
    ctx->r5 = S32(U32(ctx->r5) >> 1);
    // 0x800512FC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80051300:
    // 0x80051300: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051304: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80051308: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005130C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80051310: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051314: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80051318: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x8005131C: bne         $v0, $zero, L_80051300
    if (ctx->r2 != 0) {
        // 0x80051320: nop
    
            goto L_80051300;
    }
    // 0x80051320: nop

    // 0x80051324: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80051328: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x8005132C: bne         $v0, $zero, L_80051280
    if (ctx->r2 != 0) {
        // 0x80051330: andi        $v0, $a1, 0x1
        ctx->r2 = ctx->r5 & 0X1;
            goto L_80051280;
    }
    // 0x80051330: andi        $v0, $a1, 0x1
    ctx->r2 = ctx->r5 & 0X1;
    // 0x80051334: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    // 0x80051338: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8005133C:
    // 0x8005133C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051340: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80051344: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80051348: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005134C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051350: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80051354: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80051358: bne         $v0, $zero, L_8005133C
    if (ctx->r2 != 0) {
        // 0x8005135C: nop
    
            goto L_8005133C;
    }
    // 0x8005135C: nop

    // 0x80051360: sb          $t1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r9;
    // 0x80051364: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80051368:
    // 0x80051368: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8005136C: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80051370: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80051374: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80051378: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005137C: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80051380: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80051384: bne         $v0, $zero, L_80051368
    if (ctx->r2 != 0) {
        // 0x80051388: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_80051368;
    }
    // 0x80051388: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x8005138C: ori         $v0, $v0, 0x9
    ctx->r2 = ctx->r2 | 0X9;
    // 0x80051390: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80051394: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80051398: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x8005139C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800513A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800513A4: sw          $v0, -0x68A4($at)
    MEM_W(-0X68A4, ctx->r1) = ctx->r2;
L_800513A8:
    // 0x800513A8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800513AC: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x800513B0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800513B4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800513B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800513BC: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x800513C0: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x800513C4: bne         $v0, $zero, L_800513A8
    if (ctx->r2 != 0) {
        // 0x800513C8: nop
    
            goto L_800513A8;
    }
    // 0x800513C8: nop

    // 0x800513CC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800513D0: slti        $v0, $t2, 0x4
    ctx->r2 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x800513D4: bne         $v0, $zero, L_80051274
    if (ctx->r2 != 0) {
        // 0x800513D8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80051274;
    }
    // 0x800513D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800513DC: lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // 0x800513E0: ori         $a0, $a0, 0x70
    ctx->r4 = ctx->r4 | 0X70;
    // 0x800513E4: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x800513E8: ori         $v1, $v1, 0xF
    ctx->r3 = ctx->r3 | 0XF;
    // 0x800513EC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800513F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800513F4: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x800513F8: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_800513FC:
    // 0x800513FC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051400: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80051404: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80051408: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005140C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051410: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80051414: slti        $v0, $a1, 0x100
    ctx->r2 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x80051418: bne         $v0, $zero, L_800513FC
    if (ctx->r2 != 0) {
        // 0x8005141C: lui         $v1, 0x200
        ctx->r3 = S32(0X200 << 16);
            goto L_800513FC;
    }
    // 0x8005141C: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80051420: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x80051424: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80051428: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8005142C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80051430:
    // 0x80051430: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051434: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80051438: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005143C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80051440: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051444: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80051448: slti        $v0, $v1, 0x100
    ctx->r2 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x8005144C: bne         $v0, $zero, L_80051430
    if (ctx->r2 != 0) {
        // 0x80051450: lui         $a0, 0x200
        ctx->r4 = S32(0X200 << 16);
            goto L_80051430;
    }
    // 0x80051450: lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // 0x80051454: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x80051458: ori         $v1, $v1, 0x70
    ctx->r3 = ctx->r3 | 0X70;
    // 0x8005145C: ori         $a0, $a0, 0xF
    ctx->r4 = ctx->r4 | 0XF;
    // 0x80051460: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80051464: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80051468: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8005146C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80051470: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_80051474:
    // 0x80051474: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051478: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x8005147C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80051480: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80051484: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051488: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x8005148C: slti        $v0, $a1, 0x100
    ctx->r2 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x80051490: bne         $v0, $zero, L_80051474
    if (ctx->r2 != 0) {
        // 0x80051494: nop
    
            goto L_80051474;
    }
    // 0x80051494: nop

    // 0x80051498: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8005149C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800514A0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800514A4: jr          $ra
    // 0x800514A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800514A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800514AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800514AC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800514B0: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x800514B4: ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // 0x800514B8: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x800514BC: ori         $v0, $v0, 0xF
    ctx->r2 = ctx->r2 | 0XF;
    // 0x800514C0: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800514C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800514C8: sw          $zero, -0x68AC($at)
    MEM_W(-0X68AC, ctx->r1) = 0;
    // 0x800514CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800514D0: sw          $zero, -0x68B0($at)
    MEM_W(-0X68B0, ctx->r1) = 0;
    // 0x800514D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800514D8: sw          $zero, -0x68B4($at)
    MEM_W(-0X68B4, ctx->r1) = 0;
    // 0x800514DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800514E0: sw          $zero, -0x68B8($at)
    MEM_W(-0X68B8, ctx->r1) = 0;
    // 0x800514E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800514E8: sw          $zero, -0x6900($at)
    MEM_W(-0X6900, ctx->r1) = 0;
    // 0x800514EC: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800514F0: sb          $zero, 0x4E10($at)
    MEM_B(0X4E10, ctx->r1) = 0;
    // 0x800514F4: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x800514F8: sb          $zero, 0x4E11($at)
    MEM_B(0X4E11, ctx->r1) = 0;
    // 0x800514FC: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80051500: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_80051504:
    // 0x80051504: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051508: lhu         $v0, -0x33C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X33C8);
    // 0x8005150C: andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // 0x80051510: beq         $v0, $zero, L_80051520
    if (ctx->r2 == 0) {
        // 0x80051514: nop
    
            goto L_80051520;
    }
    // 0x80051514: nop

    // 0x80051518: jal         0x80051BDC
    // 0x8005151C: nop

    func_80051BDC(rdram, ctx);
        goto after_0;
    // 0x8005151C: nop

    after_0:
L_80051520:
    // 0x80051520: jal         0x80004644
    // 0x80051524: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80004644(rdram, ctx);
        goto after_1;
    // 0x80051524: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80051528: j           L_80051504
    // 0x8005152C: nop

        goto L_80051504;
    // 0x8005152C: nop

    // 0x80051530: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80051534: jr          $ra
    // 0x80051538: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80051538: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8005153C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005153C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051540: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80051544: jal         0x80051BDC
    // 0x80051548: nop

    func_80051BDC(rdram, ctx);
        goto after_0;
    // 0x80051548: nop

    after_0:
    // 0x8005154C: jal         0x80004644
    // 0x80051550: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80004644(rdram, ctx);
        goto after_1;
    // 0x80051550: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80051554: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80051558: jr          $ra
    // 0x8005155C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005155C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80051560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051560: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80051564: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80051568: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x8005156C: addiu       $s1, $s1, -0x6AB0
    ctx->r17 = ADD32(ctx->r17, -0X6AB0);
    // 0x80051570: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80051574: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80051578: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
L_8005157C:
    // 0x8005157C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80051580: jal         0x8004FF80
    // 0x80051584: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8004FF80(rdram, ctx);
        goto after_0;
    // 0x80051584: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80051588: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005158C: sltiu       $v0, $s0, 0x30
    ctx->r2 = ctx->r16 < 0X30 ? 1 : 0;
    // 0x80051590: bne         $v0, $zero, L_8005157C
    if (ctx->r2 != 0) {
        // 0x80051594: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8005157C;
    }
    // 0x80051594: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80051598: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8005159C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800515A0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800515A4: jr          $ra
    // 0x800515A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800515A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800515AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800515AC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800515B0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800515B4: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x800515B8: addiu       $s2, $s2, -0x6AB0
    ctx->r18 = ADD32(ctx->r18, -0X6AB0);
    // 0x800515BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800515C0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800515C4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800515C8: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
    // 0x800515CC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800515D0: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x800515D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800515D8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800515DC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800515E0: ori         $s3, $zero, 0xA000
    ctx->r19 = 0 | 0XA000;
    // 0x800515E4: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800515E8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_800515EC:
    // 0x800515EC: jal         0x80050FE0
    // 0x800515F0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80050FE0(rdram, ctx);
        goto after_0;
    // 0x800515F0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_0:
    // 0x800515F4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800515F8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800515FC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80051600:
    // 0x80051600: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051604: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80051608: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005160C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80051610: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051614: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80051618: slt         $v0, $v1, $s3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8005161C: bne         $v0, $zero, L_80051600
    if (ctx->r2 != 0) {
        // 0x80051620: nop
    
            goto L_80051600;
    }
    // 0x80051620: nop

    // 0x80051624: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80051628: slt         $v0, $s0, $s5
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x8005162C: bne         $v0, $zero, L_800515EC
    if (ctx->r2 != 0) {
        // 0x80051630: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800515EC;
    }
    // 0x80051630: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80051634: j           L_80051684
    // 0x80051638: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
        goto L_80051684;
    // 0x80051638: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8005163C:
    // 0x8005163C: jal         0x8005042C
    // 0x80051640: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8005042C(rdram, ctx);
        goto after_1;
    // 0x80051640: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // 0x80051644: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80051648: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005164C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80051650:
    // 0x80051650: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051654: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80051658: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005165C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80051660: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051664: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80051668: slt         $v0, $v1, $s3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8005166C: bne         $v0, $zero, L_80051650
    if (ctx->r2 != 0) {
        // 0x80051670: nop
    
            goto L_80051650;
    }
    // 0x80051670: nop

    // 0x80051674: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80051678: slt         $v0, $s0, $s4
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8005167C: bne         $v0, $zero, L_8005163C
    if (ctx->r2 != 0) {
        // 0x80051680: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_8005163C;
    }
    // 0x80051680: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80051684:
    // 0x80051684: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80051688: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8005168C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80051690: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80051694: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80051698: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005169C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800516A0: jr          $ra
    // 0x800516A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800516A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800516A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800516A8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800516AC: lbu         $v0, 0xB60($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB60);
    // 0x800516B0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800516B4: lbu         $v1, 0xB61($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XB61);
    // 0x800516B8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800516BC: lbu         $a0, 0xB62($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XB62);
    // 0x800516C0: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800516C4: lbu         $a1, 0xB63($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0XB63);
    // 0x800516C8: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x800516CC: lbu         $a2, 0xB7A($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XB7A);
    // 0x800516D0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x800516D4: lbu         $a3, 0xB7B($a3)
    ctx->r7 = MEM_BU(ctx->r7, 0XB7B);
    // 0x800516D8: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x800516DC: lbu         $t0, 0xB7C($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0XB7C);
    // 0x800516E0: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x800516E4: lbu         $t1, 0xB7D($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0XB7D);
    // 0x800516E8: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x800516EC: lbu         $t2, 0xB7E($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0XB7E);
    // 0x800516F0: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x800516F4: lbu         $t3, 0xB7F($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0XB7F);
    // 0x800516F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800516FC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80051700: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051704: sb          $v0, -0x6AB0($at)
    MEM_B(-0X6AB0, ctx->r1) = ctx->r2;
    // 0x80051708: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005170C: sb          $v1, -0x6AAF($at)
    MEM_B(-0X6AAF, ctx->r1) = ctx->r3;
    // 0x80051710: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051714: sb          $a0, -0x6AAE($at)
    MEM_B(-0X6AAE, ctx->r1) = ctx->r4;
    // 0x80051718: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005171C: sb          $a1, -0x6AAD($at)
    MEM_B(-0X6AAD, ctx->r1) = ctx->r5;
    // 0x80051720: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051724: sb          $a2, -0x6AA8($at)
    MEM_B(-0X6AA8, ctx->r1) = ctx->r6;
    // 0x80051728: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005172C: sb          $a3, -0x6AA7($at)
    MEM_B(-0X6AA7, ctx->r1) = ctx->r7;
    // 0x80051730: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051734: sb          $t0, -0x6AA6($at)
    MEM_B(-0X6AA6, ctx->r1) = ctx->r8;
    // 0x80051738: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005173C: sb          $t1, -0x6AA5($at)
    MEM_B(-0X6AA5, ctx->r1) = ctx->r9;
    // 0x80051740: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051744: sb          $t2, -0x6AA4($at)
    MEM_B(-0X6AA4, ctx->r1) = ctx->r10;
    // 0x80051748: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005174C: jal         0x800515AC
    // 0x80051750: sb          $t3, -0x6AA3($at)
    MEM_B(-0X6AA3, ctx->r1) = ctx->r11;
    func_800515AC(rdram, ctx);
        goto after_0;
    // 0x80051750: sb          $t3, -0x6AA3($at)
    MEM_B(-0X6AA3, ctx->r1) = ctx->r11;
    after_0:
    // 0x80051754: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80051758: jr          $ra
    // 0x8005175C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005175C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80051760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051764: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80051768: addiu       $a3, $a3, -0x6AB0
    ctx->r7 = ADD32(ctx->r7, -0X6AB0);
    // 0x8005176C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80051770: addiu       $a2, $a2, -0x1540
    ctx->r6 = ADD32(ctx->r6, -0X1540);
    // 0x80051774: or          $v0, $a2, $a3
    ctx->r2 = ctx->r6 | ctx->r7;
    // 0x80051778: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8005177C: beq         $v0, $zero, L_800517DC
    if (ctx->r2 == 0) {
        // 0x80051780: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_800517DC;
    }
    // 0x80051780: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80051784: addiu       $t0, $a2, 0x30
    ctx->r8 = ADD32(ctx->r6, 0X30);
L_80051788:
    // 0x80051788: lwl         $v0, 0x0($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r6, 0X0);
    // 0x8005178C: lwr         $v0, 0x3($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r6, 0X3);
    // 0x80051790: lwl         $v1, 0x4($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r6, 0X4);
    // 0x80051794: lwr         $v1, 0x7($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r6, 0X7);
    // 0x80051798: lwl         $a0, 0x8($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r6, 0X8);
    // 0x8005179C: lwr         $a0, 0xB($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r6, 0XB);
    // 0x800517A0: lwl         $a1, 0xC($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, ctx->r6, 0XC);
    // 0x800517A4: lwr         $a1, 0xF($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, ctx->r6, 0XF);
    // 0x800517A8: swl         $v0, 0x0($a3)
    do_swl(rdram, 0X0, ctx->r7, ctx->r2);
    // 0x800517AC: swr         $v0, 0x3($a3)
    do_swr(rdram, 0X3, ctx->r7, ctx->r2);
    // 0x800517B0: swl         $v1, 0x4($a3)
    do_swl(rdram, 0X4, ctx->r7, ctx->r3);
    // 0x800517B4: swr         $v1, 0x7($a3)
    do_swr(rdram, 0X7, ctx->r7, ctx->r3);
    // 0x800517B8: swl         $a0, 0x8($a3)
    do_swl(rdram, 0X8, ctx->r7, ctx->r4);
    // 0x800517BC: swr         $a0, 0xB($a3)
    do_swr(rdram, 0XB, ctx->r7, ctx->r4);
    // 0x800517C0: swl         $a1, 0xC($a3)
    do_swl(rdram, 0XC, ctx->r7, ctx->r5);
    // 0x800517C4: swr         $a1, 0xF($a3)
    do_swr(rdram, 0XF, ctx->r7, ctx->r5);
    // 0x800517C8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800517CC: bne         $a2, $t0, L_80051788
    if (ctx->r6 != ctx->r8) {
        // 0x800517D0: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_80051788;
    }
    // 0x800517D0: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x800517D4: j           L_8005180C
    // 0x800517D8: nop

        goto L_8005180C;
    // 0x800517D8: nop

L_800517DC:
    // 0x800517DC: addiu       $t0, $a2, 0x30
    ctx->r8 = ADD32(ctx->r6, 0X30);
L_800517E0:
    // 0x800517E0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800517E4: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x800517E8: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x800517EC: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x800517F0: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x800517F4: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x800517F8: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x800517FC: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x80051800: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80051804: bne         $a2, $t0, L_800517E0
    if (ctx->r6 != ctx->r8) {
        // 0x80051808: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_800517E0;
    }
    // 0x80051808: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_8005180C:
    // 0x8005180C: jal         0x800515AC
    // 0x80051810: nop

    func_800515AC(rdram, ctx);
        goto after_0;
    // 0x80051810: nop

    after_0:
    // 0x80051814: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80051818: jr          $ra
    // 0x8005181C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005181C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80051820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051820: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80051824: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80051828: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x8005182C: addiu       $s1, $s1, -0x6AB0
    ctx->r17 = ADD32(ctx->r17, -0X6AB0);
    // 0x80051830: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80051834: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80051838: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
L_8005183C:
    // 0x8005183C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80051840: jal         0x8004FF80
    // 0x80051844: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8004FF80(rdram, ctx);
        goto after_0;
    // 0x80051844: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80051848: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005184C: sltiu       $v0, $s0, 0x30
    ctx->r2 = ctx->r16 < 0X30 ? 1 : 0;
    // 0x80051850: bne         $v0, $zero, L_8005183C
    if (ctx->r2 != 0) {
        // 0x80051854: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8005183C;
    }
    // 0x80051854: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80051858: jal         0x800519C8
    // 0x8005185C: nop

    func_800519C8(rdram, ctx);
        goto after_1;
    // 0x8005185C: nop

    after_1:
    // 0x80051860: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80051864: bne         $v0, $v1, L_80051914
    if (ctx->r2 != ctx->r3) {
        // 0x80051868: nop
    
            goto L_80051914;
    }
    // 0x80051868: nop

    // 0x8005186C: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80051870: addiu       $a3, $a3, -0x6AB0
    ctx->r7 = ADD32(ctx->r7, -0X6AB0);
    // 0x80051874: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80051878: addiu       $a2, $a2, -0x1540
    ctx->r6 = ADD32(ctx->r6, -0X1540);
    // 0x8005187C: or          $v0, $a2, $a3
    ctx->r2 = ctx->r6 | ctx->r7;
    // 0x80051880: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x80051884: beq         $v0, $zero, L_800518E0
    if (ctx->r2 == 0) {
        // 0x80051888: addiu       $t0, $a2, 0x30
        ctx->r8 = ADD32(ctx->r6, 0X30);
            goto L_800518E0;
    }
    // 0x80051888: addiu       $t0, $a2, 0x30
    ctx->r8 = ADD32(ctx->r6, 0X30);
L_8005188C:
    // 0x8005188C: lwl         $v0, 0x0($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r6, 0X0);
    // 0x80051890: lwr         $v0, 0x3($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r6, 0X3);
    // 0x80051894: lwl         $v1, 0x4($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r6, 0X4);
    // 0x80051898: lwr         $v1, 0x7($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r6, 0X7);
    // 0x8005189C: lwl         $a0, 0x8($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r6, 0X8);
    // 0x800518A0: lwr         $a0, 0xB($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r6, 0XB);
    // 0x800518A4: lwl         $a1, 0xC($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, ctx->r6, 0XC);
    // 0x800518A8: lwr         $a1, 0xF($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, ctx->r6, 0XF);
    // 0x800518AC: swl         $v0, 0x0($a3)
    do_swl(rdram, 0X0, ctx->r7, ctx->r2);
    // 0x800518B0: swr         $v0, 0x3($a3)
    do_swr(rdram, 0X3, ctx->r7, ctx->r2);
    // 0x800518B4: swl         $v1, 0x4($a3)
    do_swl(rdram, 0X4, ctx->r7, ctx->r3);
    // 0x800518B8: swr         $v1, 0x7($a3)
    do_swr(rdram, 0X7, ctx->r7, ctx->r3);
    // 0x800518BC: swl         $a0, 0x8($a3)
    do_swl(rdram, 0X8, ctx->r7, ctx->r4);
    // 0x800518C0: swr         $a0, 0xB($a3)
    do_swr(rdram, 0XB, ctx->r7, ctx->r4);
    // 0x800518C4: swl         $a1, 0xC($a3)
    do_swl(rdram, 0XC, ctx->r7, ctx->r5);
    // 0x800518C8: swr         $a1, 0xF($a3)
    do_swr(rdram, 0XF, ctx->r7, ctx->r5);
    // 0x800518CC: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800518D0: bne         $a2, $t0, L_8005188C
    if (ctx->r6 != ctx->r8) {
        // 0x800518D4: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8005188C;
    }
    // 0x800518D4: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x800518D8: j           L_8005190C
    // 0x800518DC: nop

        goto L_8005190C;
    // 0x800518DC: nop

L_800518E0:
    // 0x800518E0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800518E4: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x800518E8: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x800518EC: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x800518F0: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x800518F4: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x800518F8: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x800518FC: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x80051900: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80051904: bne         $a2, $t0, L_800518E0
    if (ctx->r6 != ctx->r8) {
        // 0x80051908: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_800518E0;
    }
    // 0x80051908: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_8005190C:
    // 0x8005190C: jal         0x800515AC
    // 0x80051910: nop

    func_800515AC(rdram, ctx);
        goto after_2;
    // 0x80051910: nop

    after_2:
L_80051914:
    // 0x80051914: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051918: lbu         $v0, -0x6AB0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6AB0);
    // 0x8005191C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80051920: lbu         $v1, -0x6AAF($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X6AAF);
    // 0x80051924: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80051928: lbu         $a0, -0x6AAE($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X6AAE);
    // 0x8005192C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80051930: lbu         $a1, -0x6AAD($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X6AAD);
    // 0x80051934: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80051938: lbu         $a2, -0x6AA8($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X6AA8);
    // 0x8005193C: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80051940: lbu         $a3, -0x6AA7($a3)
    ctx->r7 = MEM_BU(ctx->r7, -0X6AA7);
    // 0x80051944: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80051948: lbu         $t0, -0x6AA6($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X6AA6);
    // 0x8005194C: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80051950: lbu         $t1, -0x6AA5($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X6AA5);
    // 0x80051954: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80051958: lbu         $t2, -0x6AA4($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X6AA4);
    // 0x8005195C: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80051960: lbu         $t3, -0x6AA3($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X6AA3);
    // 0x80051964: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051968: sb          $v0, 0xB60($at)
    MEM_B(0XB60, ctx->r1) = ctx->r2;
    // 0x8005196C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051970: sb          $v1, 0xB61($at)
    MEM_B(0XB61, ctx->r1) = ctx->r3;
    // 0x80051974: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051978: sb          $a0, 0xB62($at)
    MEM_B(0XB62, ctx->r1) = ctx->r4;
    // 0x8005197C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051980: sb          $a1, 0xB63($at)
    MEM_B(0XB63, ctx->r1) = ctx->r5;
    // 0x80051984: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051988: sb          $a2, 0xB7A($at)
    MEM_B(0XB7A, ctx->r1) = ctx->r6;
    // 0x8005198C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051990: sb          $a3, 0xB7B($at)
    MEM_B(0XB7B, ctx->r1) = ctx->r7;
    // 0x80051994: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051998: sb          $t0, 0xB7C($at)
    MEM_B(0XB7C, ctx->r1) = ctx->r8;
    // 0x8005199C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800519A0: sb          $t1, 0xB7D($at)
    MEM_B(0XB7D, ctx->r1) = ctx->r9;
    // 0x800519A4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800519A8: sb          $t2, 0xB7E($at)
    MEM_B(0XB7E, ctx->r1) = ctx->r10;
    // 0x800519AC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800519B0: sb          $t3, 0xB7F($at)
    MEM_B(0XB7F, ctx->r1) = ctx->r11;
    // 0x800519B4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800519B8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800519BC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800519C0: jr          $ra
    // 0x800519C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800519C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800519C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800519C8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800519CC:
    // 0x800519CC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800519D0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800519D4: lbu         $v1, -0x6A90($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X6A90);
    // 0x800519D8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800519DC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800519E0: lbu         $v0, -0x1520($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1520);
    // 0x800519E4: beql        $v1, $v0, L_800519F4
    if (ctx->r3 == ctx->r2) {
        // 0x800519E8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800519F4;
    }
    goto skip_0;
    // 0x800519E8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x800519EC: j           L_80051A00
    // 0x800519F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80051A00;
    // 0x800519F0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800519F4:
    // 0x800519F4: sltiu       $v0, $a0, 0x10
    ctx->r2 = ctx->r4 < 0X10 ? 1 : 0;
    // 0x800519F8: bne         $v0, $zero, L_800519CC
    if (ctx->r2 != 0) {
        // 0x800519FC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800519CC;
    }
    // 0x800519FC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80051A00:
    // 0x80051A00: jr          $ra
    // 0x80051A04: nop

    return;
    // 0x80051A04: nop

;}
RECOMP_FUNC void func_80051A08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051A08: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80051A0C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051A10: sb          $v0, 0xB60($at)
    MEM_B(0XB60, ctx->r1) = ctx->r2;
    // 0x80051A14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80051A18: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051A1C: sb          $v0, 0xB61($at)
    MEM_B(0XB61, ctx->r1) = ctx->r2;
    // 0x80051A20: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051A24: sb          $zero, 0xB62($at)
    MEM_B(0XB62, ctx->r1) = 0;
    // 0x80051A28: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051A2C: sb          $v0, 0xB63($at)
    MEM_B(0XB63, ctx->r1) = ctx->r2;
    // 0x80051A30: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051A34: sb          $zero, 0xB7A($at)
    MEM_B(0XB7A, ctx->r1) = 0;
    // 0x80051A38: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051A3C: sb          $zero, 0xB7B($at)
    MEM_B(0XB7B, ctx->r1) = 0;
    // 0x80051A40: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051A44: sb          $v0, 0xB7C($at)
    MEM_B(0XB7C, ctx->r1) = ctx->r2;
    // 0x80051A48: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051A4C: sb          $v0, 0xB7D($at)
    MEM_B(0XB7D, ctx->r1) = ctx->r2;
    // 0x80051A50: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051A54: sb          $zero, 0xB7E($at)
    MEM_B(0XB7E, ctx->r1) = 0;
    // 0x80051A58: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051A5C: jr          $ra
    // 0x80051A60: sb          $v0, 0xB7F($at)
    MEM_B(0XB7F, ctx->r1) = ctx->r2;
    return;
    // 0x80051A60: sb          $v0, 0xB7F($at)
    MEM_B(0XB7F, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_80051A64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051A64: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80051A68: lhu         $v0, -0x38A0($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X38A0);
    // 0x80051A6C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80051A70: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80051A74: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80051A78: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80051A7C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80051A80: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80051A84: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80051A88: andi        $v1, $v0, 0xC010
    ctx->r3 = ctx->r2 & 0XC010;
    // 0x80051A8C: ori         $v0, $zero, 0xC010
    ctx->r2 = 0 | 0XC010;
    // 0x80051A90: bne         $v1, $v0, L_80051BB0
    if (ctx->r3 != ctx->r2) {
        // 0x80051A94: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80051BB0;
    }
    // 0x80051A94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80051A98: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80051A9C: lhu         $v0, -0x389A($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X389A);
    // 0x80051AA0: andi        $v0, $v0, 0xC010
    ctx->r2 = ctx->r2 & 0XC010;
    // 0x80051AA4: bne         $v0, $v1, L_80051BB0
    if (ctx->r2 != ctx->r3) {
        // 0x80051AA8: nop
    
            goto L_80051BB0;
    }
    // 0x80051AA8: nop

    // 0x80051AAC: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80051AB0: lw          $v0, 0x4E1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4E1C);
    // 0x80051AB4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80051AB8: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80051ABC: sw          $v0, 0x4E1C($at)
    MEM_W(0X4E1C, ctx->r1) = ctx->r2;
    // 0x80051AC0: slti        $v0, $v0, 0x3C
    ctx->r2 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // 0x80051AC4: bne         $v0, $zero, L_80051BB8
    if (ctx->r2 != 0) {
        // 0x80051AC8: addiu       $a1, $zero, 0x40
        ctx->r5 = ADD32(0, 0X40);
            goto L_80051BB8;
    }
    // 0x80051AC8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x80051ACC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80051AD0: addiu       $a0, $a0, -0x1510
    ctx->r4 = ADD32(ctx->r4, -0X1510);
    // 0x80051AD4: addiu       $a2, $zero, 0x82
    ctx->r6 = ADD32(0, 0X82);
    // 0x80051AD8: jal         0x8004DAB8
    // 0x80051ADC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_8004DAB8(rdram, ctx);
        goto after_0;
    // 0x80051ADC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x80051AE0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80051AE4: addiu       $v0, $v0, 0x2094
    ctx->r2 = ADD32(ctx->r2, 0X2094);
    // 0x80051AE8: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80051AEC: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // 0x80051AF0: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x80051AF4: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x80051AF8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80051AFC: ori         $s3, $zero, 0xA000
    ctx->r19 = 0 | 0XA000;
    // 0x80051B00: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x80051B04: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051B08: sw          $zero, 0x2098($at)
    MEM_W(0X2098, ctx->r1) = 0;
    // 0x80051B0C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80051B10: sw          $zero, 0x209C($at)
    MEM_W(0X209C, ctx->r1) = 0;
    // 0x80051B14: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_80051B18:
    // 0x80051B18: jal         0x80050FE0
    // 0x80051B1C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_80050FE0(rdram, ctx);
        goto after_1;
    // 0x80051B1C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_1:
    // 0x80051B20: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80051B24: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80051B28: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80051B2C:
    // 0x80051B2C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051B30: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80051B34: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80051B38: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80051B3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051B40: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80051B44: slt         $v0, $v1, $s3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80051B48: bne         $v0, $zero, L_80051B2C
    if (ctx->r2 != 0) {
        // 0x80051B4C: nop
    
            goto L_80051B2C;
    }
    // 0x80051B4C: nop

    // 0x80051B50: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80051B54: slt         $v0, $s0, $s5
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80051B58: bne         $v0, $zero, L_80051B18
    if (ctx->r2 != 0) {
        // 0x80051B5C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80051B18;
    }
    // 0x80051B5C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80051B60: j           L_80051BB0
    // 0x80051B64: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
        goto L_80051BB0;
    // 0x80051B64: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80051B68:
    // 0x80051B68: jal         0x8005042C
    // 0x80051B6C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_8005042C(rdram, ctx);
        goto after_2;
    // 0x80051B6C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_2:
    // 0x80051B70: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80051B74: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80051B78: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80051B7C:
    // 0x80051B7C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051B80: lw          $v0, -0x68FC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X68FC);
    // 0x80051B84: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80051B88: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80051B8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051B90: sw          $v0, -0x68FC($at)
    MEM_W(-0X68FC, ctx->r1) = ctx->r2;
    // 0x80051B94: slt         $v0, $v1, $s3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80051B98: bne         $v0, $zero, L_80051B7C
    if (ctx->r2 != 0) {
        // 0x80051B9C: nop
    
            goto L_80051B7C;
    }
    // 0x80051B9C: nop

    // 0x80051BA0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80051BA4: slt         $v0, $s0, $s4
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80051BA8: bne         $v0, $zero, L_80051B68
    if (ctx->r2 != 0) {
        // 0x80051BAC: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80051B68;
    }
    // 0x80051BAC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_80051BB0:
    // 0x80051BB0: lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // 0x80051BB4: sw          $zero, 0x4E1C($at)
    MEM_W(0X4E1C, ctx->r1) = 0;
L_80051BB8:
    // 0x80051BB8: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80051BBC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80051BC0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80051BC4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80051BC8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80051BCC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80051BD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80051BD4: jr          $ra
    // 0x80051BD8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80051BD8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80051BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051BDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80051BE0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80051BE4: lui         $s1, 0x800D
    ctx->r17 = S32(0X800D << 16);
    // 0x80051BE8: addiu       $s1, $s1, -0x6AB0
    ctx->r17 = ADD32(ctx->r17, -0X6AB0);
    // 0x80051BEC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80051BF0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80051BF4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
L_80051BF8:
    // 0x80051BF8: jal         0x8006CEB0
    // 0x80051BFC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_8006CEB0(rdram, ctx);
        goto after_0;
    // 0x80051BFC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_0:
    // 0x80051C00: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x80051C04: sltiu       $v0, $s0, 0x30
    ctx->r2 = ctx->r16 < 0X30 ? 1 : 0;
    // 0x80051C08: bne         $v0, $zero, L_80051BF8
    if (ctx->r2 != 0) {
        // 0x80051C0C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80051BF8;
    }
    // 0x80051C0C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80051C10: jal         0x800515AC
    // 0x80051C14: nop

    func_800515AC(rdram, ctx);
        goto after_1;
    // 0x80051C14: nop

    after_1:
    // 0x80051C18: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80051C1C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80051C20: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80051C24: jr          $ra
    // 0x80051C28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80051C28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80051C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051C30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051C34: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051C38: addiu       $v0, $v0, -0x5E64
    ctx->r2 = ADD32(ctx->r2, -0X5E64);
    // 0x80051C3C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80051C40: addiu       $a0, $a0, -0x5E58
    ctx->r4 = ADD32(ctx->r4, -0X5E58);
    // 0x80051C44: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80051C48: addiu       $a1, $a1, -0x5E28
    ctx->r5 = ADD32(ctx->r5, -0X5E28);
    // 0x80051C4C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80051C50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051C54: sw          $v0, -0x5E64($at)
    MEM_W(-0X5E64, ctx->r1) = ctx->r2;
    // 0x80051C58: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051C5C: sw          $zero, -0x5E60($at)
    MEM_W(-0X5E60, ctx->r1) = 0;
    // 0x80051C60: jal         0x80061740
    // 0x80051C64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80051C64: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80051C68: jal         0x800532D0
    // 0x80051C6C: nop

    func_800532D0(rdram, ctx);
        goto after_1;
    // 0x80051C6C: nop

    after_1:
    // 0x80051C70: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80051C74: jr          $ra
    // 0x80051C78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80051C78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80051C7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051C7C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80051C80: lw          $v1, -0x5E60($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5E60);
    // 0x80051C84: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051C88: lw          $v0, -0x5E5C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E5C);
    // 0x80051C8C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80051C90: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x80051C94: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80051C98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051C9C: sw          $v0, -0x5E5C($at)
    MEM_W(-0X5E5C, ctx->r1) = ctx->r2;
    // 0x80051CA0: slti        $v0, $a0, 0x20
    ctx->r2 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // 0x80051CA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051CA8: bne         $v0, $zero, L_80051CBC
    if (ctx->r2 != 0) {
        // 0x80051CAC: sw          $a0, -0x5E60($at)
        MEM_W(-0X5E60, ctx->r1) = ctx->r4;
            goto L_80051CBC;
    }
    // 0x80051CAC: sw          $a0, -0x5E60($at)
    MEM_W(-0X5E60, ctx->r1) = ctx->r4;
    // 0x80051CB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051CB4: j           L_80051D64
    // 0x80051CB8: sw          $v1, -0x5E60($at)
    MEM_W(-0X5E60, ctx->r1) = ctx->r3;
        goto L_80051D64;
    // 0x80051CB8: sw          $v1, -0x5E60($at)
    MEM_W(-0X5E60, ctx->r1) = ctx->r3;
L_80051CBC:
    // 0x80051CBC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80051CC0: lw          $v1, -0x34C0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X34C0);
    // 0x80051CC4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80051CC8: lw          $a1, -0x5E64($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5E64);
    // 0x80051CCC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80051CD0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80051CD4: sll         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2 << 5);
    // 0x80051CD8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80051CDC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80051CE0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051CE4: addiu       $v0, $v0, -0x68B8
    ctx->r2 = ADD32(ctx->r2, -0X68B8);
    // 0x80051CE8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80051CEC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80051CF0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80051CF4: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80051CF8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80051CFC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80051D00: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x80051D04: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    // 0x80051D08: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x80051D0C: lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XC);
    // 0x80051D10: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x80051D14: lwc1        $f0, 0x10($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80051D18: swc1        $f0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f0.u32l;
    // 0x80051D1C: lwc1        $f0, 0x14($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80051D20: swc1        $f0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f0.u32l;
    // 0x80051D24: lhu         $v0, 0x4($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X4);
    // 0x80051D28: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // 0x80051D2C: lhu         $v0, 0x6($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X6);
    // 0x80051D30: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
    // 0x80051D34: lw          $v0, 0x18($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X18);
    // 0x80051D38: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x80051D3C: lw          $v0, 0x1C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1C);
    // 0x80051D40: sw          $v0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r2;
    // 0x80051D44: lw          $v0, 0x20($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X20);
    // 0x80051D48: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // 0x80051D4C: lw          $a0, 0x24($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X24);
    // 0x80051D50: addiu       $v0, $a1, -0x4
    ctx->r2 = ADD32(ctx->r5, -0X4);
    // 0x80051D54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051D58: sw          $v0, -0x5E64($at)
    MEM_W(-0X5E64, ctx->r1) = ctx->r2;
    // 0x80051D5C: sw          $a0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r4;
    // 0x80051D60: sw          $v1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r3;
L_80051D64:
    // 0x80051D64: jr          $ra
    // 0x80051D68: nop

    return;
    // 0x80051D68: nop

;}
RECOMP_FUNC void func_80051D6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051D6C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051D70: lw          $v0, -0x5E60($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E60);
    // 0x80051D74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051D78: beq         $v0, $zero, L_80051F00
    if (ctx->r2 == 0) {
        // 0x80051D7C: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80051F00;
    }
    // 0x80051D7C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80051D80: lui         $a1, 0xBA00
    ctx->r5 = S32(0XBA00 << 16);
    // 0x80051D84: ori         $a1, $a1, 0x1402
    ctx->r5 = ctx->r5 | 0X1402;
    // 0x80051D88: lui         $a2, 0xBA00
    ctx->r6 = S32(0XBA00 << 16);
    // 0x80051D8C: ori         $a2, $a2, 0x1301
    ctx->r6 = ctx->r6 | 0X1301;
    // 0x80051D90: lui         $a3, 0xBA00
    ctx->r7 = S32(0XBA00 << 16);
    // 0x80051D94: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80051D98: lw          $v1, -0x34C0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X34C0);
    // 0x80051D9C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80051DA0: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x80051DA4: ori         $a3, $a3, 0xE02
    ctx->r7 = ctx->r7 | 0XE02;
    // 0x80051DA8: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    // 0x80051DAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051DB0: sw          $v0, -0x38BC($at)
    MEM_W(-0X38BC, ctx->r1) = ctx->r2;
    // 0x80051DB4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80051DB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051DBC: sw          $v0, -0x3820($at)
    MEM_W(-0X3820, ctx->r1) = ctx->r2;
    // 0x80051DC0: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x80051DC4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80051DC8: sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2 << 7);
    // 0x80051DCC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80051DD0: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80051DD4: lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // 0x80051DD8: addiu       $v1, $v1, -0x2900
    ctx->r3 = ADD32(ctx->r3, -0X2900);
    // 0x80051DDC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80051DE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051DE4: sw          $v0, 0x7CC4($at)
    MEM_W(0X7CC4, ctx->r1) = ctx->r2;
    // 0x80051DE8: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80051DEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051DF0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80051DF4: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x80051DF8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80051DFC: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x80051E00: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051E04: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80051E08: addiu       $v0, $a0, 0x18
    ctx->r2 = ADD32(ctx->r4, 0X18);
    // 0x80051E0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051E10: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80051E14: addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
    // 0x80051E18: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051E1C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80051E20: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80051E24: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80051E28: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    // 0x80051E2C: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80051E30: sw          $a2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r6;
    // 0x80051E34: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x80051E38: sw          $a3, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r7;
    // 0x80051E3C: sw          $v0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r2;
L_80051E40:
    // 0x80051E40: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80051E44: lw          $v1, -0x5E64($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5E64);
    // 0x80051E48: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    // 0x80051E4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051E50: sw          $v0, -0x5E64($at)
    MEM_W(-0X5E64, ctx->r1) = ctx->r2;
    // 0x80051E54: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80051E58: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051E5C: lw          $v0, -0x5E60($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E60);
    // 0x80051E60: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
    // 0x80051E64: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80051E68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051E6C: bne         $v1, $zero, L_80051E84
    if (ctx->r3 != 0) {
        // 0x80051E70: sw          $v0, -0x5E60($at)
        MEM_W(-0X5E60, ctx->r1) = ctx->r2;
            goto L_80051E84;
    }
    // 0x80051E70: sw          $v0, -0x5E60($at)
    MEM_W(-0X5E60, ctx->r1) = ctx->r2;
    // 0x80051E74: jal         0x80051F0C
    // 0x80051E78: nop

    func_80051F0C(rdram, ctx);
        goto after_0;
    // 0x80051E78: nop

    after_0:
    // 0x80051E7C: j           L_80051E8C
    // 0x80051E80: nop

        goto L_80051E8C;
    // 0x80051E80: nop

L_80051E84:
    // 0x80051E84: jal         0x80052048
    // 0x80051E88: nop

    func_80052048(rdram, ctx);
        goto after_1;
    // 0x80051E88: nop

    after_1:
L_80051E8C:
    // 0x80051E8C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051E90: lw          $v0, -0x5E60($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E60);
    // 0x80051E94: bne         $v0, $zero, L_80051E40
    if (ctx->r2 != 0) {
        // 0x80051E98: lui         $a2, 0xFCFF
        ctx->r6 = S32(0XFCFF << 16);
            goto L_80051E40;
    }
    // 0x80051E98: lui         $a2, 0xFCFF
    ctx->r6 = S32(0XFCFF << 16);
    // 0x80051E9C: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80051EA0: lui         $a0, 0xFFFC
    ctx->r4 = S32(0XFFFC << 16);
    // 0x80051EA4: ori         $a0, $a0, 0xF279
    ctx->r4 = ctx->r4 | 0XF279;
    // 0x80051EA8: lui         $a3, 0xB900
    ctx->r7 = S32(0XB900 << 16);
    // 0x80051EAC: ori         $a3, $a3, 0x31D
    ctx->r7 = ctx->r7 | 0X31D;
    // 0x80051EB0: lui         $a1, 0xF0A
    ctx->r5 = S32(0XF0A << 16);
    // 0x80051EB4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80051EB8: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80051EBC: ori         $a1, $a1, 0x7008
    ctx->r5 = ctx->r5 | 0X7008;
    // 0x80051EC0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051EC4: addiu       $v0, $v0, -0x5E64
    ctx->r2 = ADD32(ctx->r2, -0X5E64);
    // 0x80051EC8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051ECC: sw          $v0, -0x5E64($at)
    MEM_W(-0X5E64, ctx->r1) = ctx->r2;
    // 0x80051ED0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051ED4: sw          $zero, -0x5E60($at)
    MEM_W(-0X5E60, ctx->r1) = 0;
    // 0x80051ED8: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80051EDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051EE0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80051EE4: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80051EE8: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x80051EEC: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x80051EF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051EF4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80051EF8: sw          $a3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r7;
    // 0x80051EFC: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
L_80051F00:
    // 0x80051F00: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80051F04: jr          $ra
    // 0x80051F08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80051F08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80051F0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051F0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80051F10: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80051F14: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80051F18: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80051F1C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80051F20: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80051F24: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80051F28: lbu         $v0, 0x7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7);
    // 0x80051F2C: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    // 0x80051F30: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x80051F34: addu        $s0, $s0, $a0
    ctx->r16 = ADD32(ctx->r16, ctx->r4);
    // 0x80051F38: lw          $s0, -0x1994($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X1994);
    // 0x80051F3C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80051F40: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // 0x80051F44: lw          $a1, -0x1998($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X1998);
    // 0x80051F48: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80051F4C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80051F50: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x80051F54: addu        $a2, $a2, $a0
    ctx->r6 = ADD32(ctx->r6, ctx->r4);
    // 0x80051F58: lw          $a2, -0x199C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X199C);
    // 0x80051F5C: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x80051F60: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80051F64: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x80051F68: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80051F6C: lw          $v1, -0x38BC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X38BC);
    // 0x80051F70: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80051F74: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80051F78: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80051F7C: addu        $t0, $a2, $a1
    ctx->r8 = ADD32(ctx->r6, ctx->r5);
    // 0x80051F80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051F84: sw          $v1, -0x38BC($at)
    MEM_W(-0X38BC, ctx->r1) = ctx->r3;
    // 0x80051F88: bgez        $v1, L_80051FA4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80051F8C: subu        $a3, $v0, $a1
        ctx->r7 = SUB32(ctx->r2, ctx->r5);
            goto L_80051FA4;
    }
    // 0x80051F8C: subu        $a3, $v0, $a1
    ctx->r7 = SUB32(ctx->r2, ctx->r5);
    // 0x80051F90: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80051F94: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80051F98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051F9C: j           L_80052034
    // 0x80051FA0: sw          $v0, -0x38BC($at)
    MEM_W(-0X38BC, ctx->r1) = ctx->r2;
        goto L_80052034;
    // 0x80051FA0: sw          $v0, -0x38BC($at)
    MEM_W(-0X38BC, ctx->r1) = ctx->r2;
L_80051FA4:
    // 0x80051FA4: lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X3);
    // 0x80051FA8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80051FAC: lw          $a0, 0x7CC4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7CC4);
    // 0x80051FB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80051FB4: sw          $v0, -0x38C0($at)
    MEM_W(-0X38C0, ctx->r1) = ctx->r2;
    // 0x80051FB8: lbu         $a2, 0x0($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X0);
    // 0x80051FBC: jal         0x800530F4
    // 0x80051FC0: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    func_800530F4(rdram, ctx);
        goto after_0;
    // 0x80051FC0: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    after_0:
    // 0x80051FC4: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80051FC8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80051FCC: ldc1        $f2, -0x14F0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X14F0);
    // 0x80051FD0: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80051FD4: c.eq.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d == ctx->f2.d;
    // 0x80051FD8: nop

    // 0x80051FDC: nop

    // 0x80051FE0: bc1f        L_80052010
    if (!c1cs) {
        // 0x80051FE4: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80052010;
    }
    // 0x80051FE4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80051FE8: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80051FEC: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80051FF0: c.eq.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d == ctx->f2.d;
    // 0x80051FF4: nop

    // 0x80051FF8: bc1f        L_80052010
    if (!c1cs) {
        // 0x80051FFC: nop
    
            goto L_80052010;
    }
    // 0x80051FFC: nop

    // 0x80052000: jal         0x80052100
    // 0x80052004: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80052100(rdram, ctx);
        goto after_1;
    // 0x80052004: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80052008: j           L_80052018
    // 0x8005200C: nop

        goto L_80052018;
    // 0x8005200C: nop

L_80052010:
    // 0x80052010: jal         0x8005222C
    // 0x80052014: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8005222C(rdram, ctx);
        goto after_2;
    // 0x80052014: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
L_80052018:
    // 0x80052018: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8005201C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80052020: lw          $v1, 0x7CC4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7CC4);
    // 0x80052024: sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2 << 11);
    // 0x80052028: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005202C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80052030: sw          $v1, 0x7CC4($at)
    MEM_W(0X7CC4, ctx->r1) = ctx->r3;
L_80052034:
    // 0x80052034: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80052038: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005203C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80052040: jr          $ra
    // 0x80052044: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80052044: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80052048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052048: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005204C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80052050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052054: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80052058: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8005205C: lw          $v1, 0x1C($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1C);
    // 0x80052060: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80052064: lw          $s0, 0x7CC4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X7CC4);
    // 0x80052068: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005206C: lwc1        $f0, 0x10($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80052070: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052074: ldc1        $f2, -0x14E8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X14E8);
    // 0x80052078: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8005207C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80052080: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80052084: lw          $a1, -0x1994($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X1994);
    // 0x80052088: lbu         $v0, 0x7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X7);
    // 0x8005208C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80052090: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80052094: sw          $v1, 0x7CC4($at)
    MEM_W(0X7CC4, ctx->r1) = ctx->r3;
    // 0x80052098: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005209C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800520A0: lbu         $v0, 0x3($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X3);
    // 0x800520A4: c.eq.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d == ctx->f2.d;
    // 0x800520A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800520AC: sw          $v0, -0x38C0($at)
    MEM_W(-0X38C0, ctx->r1) = ctx->r2;
    // 0x800520B0: bc1f        L_800520E0
    if (!c1cs) {
        // 0x800520B4: nop
    
            goto L_800520E0;
    }
    // 0x800520B4: nop

    // 0x800520B8: lwc1        $f0, 0x14($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800520BC: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x800520C0: c.eq.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d == ctx->f2.d;
    // 0x800520C4: nop

    // 0x800520C8: bc1f        L_800520E0
    if (!c1cs) {
        // 0x800520CC: nop
    
            goto L_800520E0;
    }
    // 0x800520CC: nop

    // 0x800520D0: jal         0x80052100
    // 0x800520D4: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    func_80052100(rdram, ctx);
        goto after_0;
    // 0x800520D4: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    after_0:
    // 0x800520D8: j           L_800520E8
    // 0x800520DC: nop

        goto L_800520E8;
    // 0x800520DC: nop

L_800520E0:
    // 0x800520E0: jal         0x8005222C
    // 0x800520E4: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    func_8005222C(rdram, ctx);
        goto after_1;
    // 0x800520E4: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    after_1:
L_800520E8:
    // 0x800520E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800520EC: sw          $s0, 0x7CC4($at)
    MEM_W(0X7CC4, ctx->r1) = ctx->r16;
    // 0x800520F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800520F4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800520F8: jr          $ra
    // 0x800520FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800520FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80052100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052100: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80052104: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80052108: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x8005210C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80052110: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80052114: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80052118: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8005211C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80052120: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80052124: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80052128: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8005212C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80052130: lh          $v0, 0x4($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X4);
    // 0x80052134: bne         $v0, $zero, L_80052150
    if (ctx->r2 != 0) {
        // 0x80052138: addu        $s5, $a1, $zero
        ctx->r21 = ADD32(ctx->r5, 0);
            goto L_80052150;
    }
    // 0x80052138: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x8005213C: lh          $v1, 0x4($s5)
    ctx->r3 = MEM_H(ctx->r21, 0X4);
    // 0x80052140: lw          $v0, 0x8($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X8);
    // 0x80052144: addiu       $fp, $zero, 0x40
    ctx->r30 = ADD32(0, 0X40);
    // 0x80052148: j           L_80052164
    // 0x8005214C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
        goto L_80052164;
    // 0x8005214C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_80052150:
    // 0x80052150: lh          $v1, 0x4($s5)
    ctx->r3 = MEM_H(ctx->r21, 0X4);
    // 0x80052154: lw          $v0, 0x8($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X8);
    // 0x80052158: addiu       $fp, $zero, -0x40
    ctx->r30 = ADD32(0, -0X40);
    // 0x8005215C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80052160: addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
L_80052164:
    // 0x80052164: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80052168: lh          $v0, 0x6($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X6);
    // 0x8005216C: bne         $v0, $zero, L_80052188
    if (ctx->r2 != 0) {
        // 0x80052170: addiu       $s7, $zero, -0x40
        ctx->r23 = ADD32(0, -0X40);
            goto L_80052188;
    }
    // 0x80052170: addiu       $s7, $zero, -0x40
    ctx->r23 = ADD32(0, -0X40);
    // 0x80052174: lh          $v1, 0x6($s5)
    ctx->r3 = MEM_H(ctx->r21, 0X6);
    // 0x80052178: lw          $v0, 0xC($s6)
    ctx->r2 = MEM_W(ctx->r22, 0XC);
    // 0x8005217C: addiu       $s7, $zero, 0x40
    ctx->r23 = ADD32(0, 0X40);
    // 0x80052180: j           L_80052198
    // 0x80052184: subu        $s4, $v0, $v1
    ctx->r20 = SUB32(ctx->r2, ctx->r3);
        goto L_80052198;
    // 0x80052184: subu        $s4, $v0, $v1
    ctx->r20 = SUB32(ctx->r2, ctx->r3);
L_80052188:
    // 0x80052188: lh          $v1, 0x6($s5)
    ctx->r3 = MEM_H(ctx->r21, 0X6);
    // 0x8005218C: lw          $v0, 0xC($s6)
    ctx->r2 = MEM_W(ctx->r22, 0XC);
    // 0x80052190: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80052194: addiu       $s4, $v0, -0x40
    ctx->r20 = ADD32(ctx->r2, -0X40);
L_80052198:
    // 0x80052198: lbu         $v0, 0x2($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X2);
    // 0x8005219C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800521A0: lw          $s2, 0x7CC4($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X7CC4);
    // 0x800521A4: blez        $v0, L_800521FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800521A8: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_800521FC;
    }
    // 0x800521A8: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_800521AC:
    // 0x800521AC: lbu         $v0, 0x1($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X1);
    // 0x800521B0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800521B4: blez        $v0, L_800521E8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800521B8: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_800521E8;
    }
    // 0x800521B8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_800521BC:
    // 0x800521BC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800521C0: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800521C4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x800521C8: jal         0x800523DC
    // 0x800521CC: addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    func_800523DC(rdram, ctx);
        goto after_0;
    // 0x800521CC: addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    after_0:
    // 0x800521D0: addiu       $s2, $s2, 0x800
    ctx->r18 = ADD32(ctx->r18, 0X800);
    // 0x800521D4: lbu         $v0, 0x1($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X1);
    // 0x800521D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800521DC: slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800521E0: bne         $v0, $zero, L_800521BC
    if (ctx->r2 != 0) {
        // 0x800521E4: addu        $s1, $s1, $fp
        ctx->r17 = ADD32(ctx->r17, ctx->r30);
            goto L_800521BC;
    }
    // 0x800521E4: addu        $s1, $s1, $fp
    ctx->r17 = ADD32(ctx->r17, ctx->r30);
L_800521E8:
    // 0x800521E8: lbu         $v0, 0x2($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0X2);
    // 0x800521EC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800521F0: slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800521F4: bne         $v0, $zero, L_800521AC
    if (ctx->r2 != 0) {
        // 0x800521F8: addu        $s4, $s4, $s7
        ctx->r20 = ADD32(ctx->r20, ctx->r23);
            goto L_800521AC;
    }
    // 0x800521F8: addu        $s4, $s4, $s7
    ctx->r20 = ADD32(ctx->r20, ctx->r23);
L_800521FC:
    // 0x800521FC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80052200: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80052204: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80052208: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8005220C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80052210: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80052214: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80052218: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8005221C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80052220: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80052224: jr          $ra
    // 0x80052228: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80052228: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8005222C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005222C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80052230: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80052234: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80052238: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8005223C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80052240: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80052244: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80052248: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005224C: sdc1        $f28, 0x58($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X58, ctx->r29);
    // 0x80052250: sdc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X50, ctx->r29);
    // 0x80052254: sdc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X48, ctx->r29);
    // 0x80052258: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x8005225C: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80052260: lwc1        $f6, 0x10($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X10);
    // 0x80052264: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052268: ldc1        $f4, -0x14E0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X14E0);
    // 0x8005226C: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x80052270: mul.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f4.d);
    // 0x80052274: lwc1        $f0, 0x14($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X14);
    // 0x80052278: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8005227C: mul.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x80052280: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x80052284: lh          $v0, 0x4($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X4);
    // 0x80052288: cvt.s.d     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f4.fl = CVT_S_D(ctx->f2.d);
    // 0x8005228C: bne         $v0, $zero, L_800522BC
    if (ctx->r2 != 0) {
        // 0x80052290: cvt.s.d     $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f14.fl = CVT_S_D(ctx->f0.d);
            goto L_800522BC;
    }
    // 0x80052290: cvt.s.d     $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f14.fl = CVT_S_D(ctx->f0.d);
    // 0x80052294: lh          $v0, 0x4($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X4);
    // 0x80052298: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8005229C: nop

    // 0x800522A0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800522A4: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800522A8: mov.s       $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    ctx->f26.fl = ctx->f4.fl;
    // 0x800522AC: lwc1        $f2, 0x8($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800522B0: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800522B4: j           L_800522E4
    // 0x800522B8: sub.s       $f28, $f2, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = ctx->f2.fl - ctx->f0.fl;
        goto L_800522E4;
    // 0x800522B8: sub.s       $f28, $f2, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = ctx->f2.fl - ctx->f0.fl;
L_800522BC:
    // 0x800522BC: lh          $v0, 0x4($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X4);
    // 0x800522C0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800522C4: nop

    // 0x800522C8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800522CC: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800522D0: lwc1        $f2, 0x8($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800522D4: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800522D8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800522DC: neg.s       $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = -ctx->f4.fl;
    // 0x800522E0: sub.s       $f28, $f2, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f28.fl = ctx->f2.fl - ctx->f4.fl;
L_800522E4:
    // 0x800522E4: lh          $v0, 0x6($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X6);
    // 0x800522E8: bnel        $v0, $zero, L_8005231C
    if (ctx->r2 != 0) {
        // 0x800522EC: neg.s       $f24, $f14
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f24.fl = -ctx->f14.fl;
            goto L_8005231C;
    }
    goto skip_0;
    // 0x800522EC: neg.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f24.fl = -ctx->f14.fl;
    skip_0:
    // 0x800522F0: lh          $v0, 0x6($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X6);
    // 0x800522F4: lwc1        $f2, 0x14($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800522F8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800522FC: nop

    // 0x80052300: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80052304: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80052308: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x8005230C: lwc1        $f2, 0xC($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80052310: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80052314: j           L_80052344
    // 0x80052318: sub.s       $f22, $f2, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f2.fl - ctx->f0.fl;
        goto L_80052344;
    // 0x80052318: sub.s       $f22, $f2, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f2.fl - ctx->f0.fl;
L_8005231C:
    // 0x8005231C: lh          $v0, 0x6($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X6);
    // 0x80052320: lwc1        $f2, 0x14($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X14);
    // 0x80052324: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80052328: nop

    // 0x8005232C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80052330: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80052334: lwc1        $f2, 0xC($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80052338: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8005233C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80052340: sub.s       $f22, $f2, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f22.fl = ctx->f2.fl - ctx->f14.fl;
L_80052344:
    // 0x80052344: lbu         $v0, 0x2($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X2);
    // 0x80052348: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8005234C: lw          $s1, 0x7CC4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X7CC4);
    // 0x80052350: blez        $v0, L_800523A8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80052354: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800523A8;
    }
    // 0x80052354: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_80052358:
    // 0x80052358: lbu         $v0, 0x1($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X1);
    // 0x8005235C: mov.s       $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    ctx->f20.fl = ctx->f28.fl;
    // 0x80052360: blez        $v0, L_80052394
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80052364: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80052394;
    }
    // 0x80052364: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80052368:
    // 0x80052368: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8005236C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x80052370: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80052374: jal         0x80052750
    // 0x80052378: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    func_80052750(rdram, ctx);
        goto after_0;
    // 0x80052378: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_0:
    // 0x8005237C: addiu       $s1, $s1, 0x800
    ctx->r17 = ADD32(ctx->r17, 0X800);
    // 0x80052380: lbu         $v0, 0x1($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X1);
    // 0x80052384: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80052388: slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005238C: bne         $v0, $zero, L_80052368
    if (ctx->r2 != 0) {
        // 0x80052390: add.s       $f20, $f20, $f26
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
            goto L_80052368;
    }
    // 0x80052390: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
L_80052394:
    // 0x80052394: lbu         $v0, 0x2($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X2);
    // 0x80052398: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8005239C: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800523A0: bne         $v0, $zero, L_80052358
    if (ctx->r2 != 0) {
        // 0x800523A4: add.s       $f22, $f22, $f24
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f24.fl;
            goto L_80052358;
    }
    // 0x800523A4: add.s       $f22, $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f24.fl;
L_800523A8:
    // 0x800523A8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800523AC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800523B0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800523B4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800523B8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800523BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800523C0: ldc1        $f28, 0x58($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X58);
    // 0x800523C4: ldc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X50);
    // 0x800523C8: ldc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X48);
    // 0x800523CC: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x800523D0: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x800523D4: jr          $ra
    // 0x800523D8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800523D8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800523DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800523DC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800523E0: addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // 0x800523E4: addiu       $a2, $a0, 0x40
    ctx->r6 = ADD32(ctx->r4, 0X40);
    // 0x800523E8: sltiu       $v1, $a2, 0x180
    ctx->r3 = ctx->r6 < 0X180 ? 1 : 0;
    // 0x800523EC: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x800523F0: addiu       $v0, $a1, 0x40
    ctx->r2 = ADD32(ctx->r5, 0X40);
    // 0x800523F4: sltiu       $v0, $v0, 0x130
    ctx->r2 = ctx->r2 < 0X130 ? 1 : 0;
    // 0x800523F8: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800523FC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80052400: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x80052404: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80052408: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8005240C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80052410: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80052414: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80052418: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8005241C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80052420: bne         $v1, $zero, L_80052724
    if (ctx->r3 != 0) {
        // 0x80052424: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_80052724;
    }
    // 0x80052424: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80052428: bgez        $a0, L_80052440
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8005242C: slti        $v0, $a2, 0x140
        ctx->r2 = SIGNED(ctx->r6) < 0X140 ? 1 : 0;
            goto L_80052440;
    }
    // 0x8005242C: slti        $v0, $a2, 0x140
    ctx->r2 = SIGNED(ctx->r6) < 0X140 ? 1 : 0;
    // 0x80052430: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80052434: negu        $s2, $a0
    ctx->r18 = SUB32(0, ctx->r4);
    // 0x80052438: j           L_80052460
    // 0x8005243C: addiu       $s5, $a0, 0x40
    ctx->r21 = ADD32(ctx->r4, 0X40);
        goto L_80052460;
    // 0x8005243C: addiu       $s5, $a0, 0x40
    ctx->r21 = ADD32(ctx->r4, 0X40);
L_80052440:
    // 0x80052440: bne         $v0, $zero, L_80052458
    if (ctx->r2 != 0) {
        // 0x80052444: addu        $s3, $a0, $zero
        ctx->r19 = ADD32(ctx->r4, 0);
            goto L_80052458;
    }
    // 0x80052444: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80052448: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8005244C: addiu       $v0, $zero, 0x140
    ctx->r2 = ADD32(0, 0X140);
    // 0x80052450: j           L_80052460
    // 0x80052454: subu        $s5, $v0, $s3
    ctx->r21 = SUB32(ctx->r2, ctx->r19);
        goto L_80052460;
    // 0x80052454: subu        $s5, $v0, $s3
    ctx->r21 = SUB32(ctx->r2, ctx->r19);
L_80052458:
    // 0x80052458: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8005245C: addiu       $s5, $zero, 0x40
    ctx->r21 = ADD32(0, 0X40);
L_80052460:
    // 0x80052460: bgez        $a1, L_80052478
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80052464: addiu       $v0, $a1, 0x40
        ctx->r2 = ADD32(ctx->r5, 0X40);
            goto L_80052478;
    }
    // 0x80052464: addiu       $v0, $a1, 0x40
    ctx->r2 = ADD32(ctx->r5, 0X40);
    // 0x80052468: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8005246C: negu        $s0, $a1
    ctx->r16 = SUB32(0, ctx->r5);
    // 0x80052470: j           L_8005249C
    // 0x80052474: addiu       $s4, $a1, 0x40
    ctx->r20 = ADD32(ctx->r5, 0X40);
        goto L_8005249C;
    // 0x80052474: addiu       $s4, $a1, 0x40
    ctx->r20 = ADD32(ctx->r5, 0X40);
L_80052478:
    // 0x80052478: slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // 0x8005247C: bne         $v0, $zero, L_80052494
    if (ctx->r2 != 0) {
        // 0x80052480: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_80052494;
    }
    // 0x80052480: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80052484: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80052488: addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // 0x8005248C: j           L_8005249C
    // 0x80052490: subu        $s4, $v0, $s1
    ctx->r20 = SUB32(ctx->r2, ctx->r17);
        goto L_8005249C;
    // 0x80052490: subu        $s4, $v0, $s1
    ctx->r20 = SUB32(ctx->r2, ctx->r17);
L_80052494:
    // 0x80052494: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80052498: addiu       $s4, $zero, 0x40
    ctx->r20 = ADD32(0, 0X40);
L_8005249C:
    // 0x8005249C: lh          $v0, 0x4($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X4);
    // 0x800524A0: lhu         $v1, 0x6($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X6);
    // 0x800524A4: bne         $v0, $zero, L_800524B4
    if (ctx->r2 != 0) {
        // 0x800524A8: addiu       $s7, $zero, -0x1
        ctx->r23 = ADD32(0, -0X1);
            goto L_800524B4;
    }
    // 0x800524A8: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // 0x800524AC: j           L_800524BC
    // 0x800524B0: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
        goto L_800524BC;
    // 0x800524B0: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_800524B4:
    // 0x800524B4: addiu       $v0, $zero, 0x3F
    ctx->r2 = ADD32(0, 0X3F);
    // 0x800524B8: subu        $s2, $v0, $s2
    ctx->r18 = SUB32(ctx->r2, ctx->r18);
L_800524BC:
    // 0x800524BC: bne         $v1, $zero, L_800524CC
    if (ctx->r3 != 0) {
        // 0x800524C0: addiu       $s6, $zero, -0x1
        ctx->r22 = ADD32(0, -0X1);
            goto L_800524CC;
    }
    // 0x800524C0: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x800524C4: j           L_800524D4
    // 0x800524C8: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
        goto L_800524D4;
    // 0x800524C8: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_800524CC:
    // 0x800524CC: addiu       $v0, $zero, 0x3F
    ctx->r2 = ADD32(0, 0X3F);
    // 0x800524D0: subu        $s0, $v0, $s0
    ctx->r16 = SUB32(ctx->r2, ctx->r16);
L_800524D4:
    // 0x800524D4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800524D8: lw          $a0, -0x38C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X38C0);
    // 0x800524DC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800524E0: lw          $v0, -0x3820($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3820);
    // 0x800524E4: beq         $a0, $v0, L_800525A8
    if (ctx->r4 == ctx->r2) {
        // 0x800524E8: lui         $a1, 0xF500
        ctx->r5 = S32(0XF500 << 16);
            goto L_800525A8;
    }
    // 0x800524E8: lui         $a1, 0xF500
    ctx->r5 = S32(0XF500 << 16);
    // 0x800524EC: ori         $a1, $a1, 0x100
    ctx->r5 = ctx->r5 | 0X100;
    // 0x800524F0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800524F4: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x800524F8: lui         $a2, 0x703
    ctx->r6 = S32(0X703 << 16);
    // 0x800524FC: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x80052500: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80052504: sw          $a0, -0x3820($at)
    MEM_W(-0X3820, ctx->r1) = ctx->r4;
    // 0x80052508: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8005250C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052510: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052514: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x80052518: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8005251C: sll         $v0, $a0, 5
    ctx->r2 = S32(ctx->r4 << 5);
    // 0x80052520: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80052524: addiu       $a0, $a0, -0x3250
    ctx->r4 = ADD32(ctx->r4, -0X3250);
    // 0x80052528: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8005252C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80052530: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80052534: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052538: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8005253C: lui         $v0, 0xE800
    ctx->r2 = S32(0XE800 << 16);
    // 0x80052540: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x80052544: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x80052548: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005254C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052550: lui         $v0, 0x700
    ctx->r2 = S32(0X700 << 16);
    // 0x80052554: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x80052558: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x8005255C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052560: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052564: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x80052568: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x8005256C: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x80052570: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052574: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052578: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x8005257C: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // 0x80052580: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x80052584: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052588: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8005258C: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x80052590: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x80052594: sw          $a1, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r5;
    // 0x80052598: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x8005259C: sw          $a2, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r6;
    // 0x800525A0: sw          $v0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r2;
    // 0x800525A4: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
L_800525A8:
    // 0x800525A8: lui         $a0, 0x73F
    ctx->r4 = S32(0X73F << 16);
    // 0x800525AC: ori         $a0, $a0, 0xF200
    ctx->r4 = ctx->r4 | 0XF200;
    // 0x800525B0: lui         $a1, 0xF540
    ctx->r5 = S32(0XF540 << 16);
    // 0x800525B4: ori         $a1, $a1, 0x800
    ctx->r5 = ctx->r5 | 0X800;
    // 0x800525B8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800525BC: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x800525C0: lui         $a2, 0xF
    ctx->r6 = S32(0XF << 16);
    // 0x800525C4: ori         $a2, $a2, 0xC0FC
    ctx->r6 = ctx->r6 | 0XC0FC;
    // 0x800525C8: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x800525CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800525D0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800525D4: lui         $v1, 0xFD50
    ctx->r3 = S32(0XFD50 << 16);
    // 0x800525D8: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800525DC: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x800525E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800525E4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800525E8: lui         $v1, 0xF550
    ctx->r3 = S32(0XF550 << 16);
    // 0x800525EC: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x800525F0: lui         $v1, 0x700
    ctx->r3 = S32(0X700 << 16);
    // 0x800525F4: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x800525F8: addiu       $v1, $v0, 0x18
    ctx->r3 = ADD32(ctx->r2, 0X18);
    // 0x800525FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052600: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80052604: lui         $v1, 0xE600
    ctx->r3 = S32(0XE600 << 16);
    // 0x80052608: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x8005260C: addiu       $v1, $v0, 0x20
    ctx->r3 = ADD32(ctx->r2, 0X20);
    // 0x80052610: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052614: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80052618: lui         $v1, 0xF300
    ctx->r3 = S32(0XF300 << 16);
    // 0x8005261C: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
    // 0x80052620: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x80052624: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052628: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8005262C: lui         $v1, 0xE700
    ctx->r3 = S32(0XE700 << 16);
    // 0x80052630: sw          $v1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r3;
    // 0x80052634: addiu       $v1, $v0, 0x30
    ctx->r3 = ADD32(ctx->r2, 0X30);
    // 0x80052638: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005263C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80052640: addiu       $v1, $v0, 0x38
    ctx->r3 = ADD32(ctx->r2, 0X38);
    // 0x80052644: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052648: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8005264C: lui         $v1, 0xF200
    ctx->r3 = S32(0XF200 << 16);
    // 0x80052650: sw          $a0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r4;
    // 0x80052654: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    // 0x80052658: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8005265C: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x80052660: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80052664: sw          $a1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r5;
    // 0x80052668: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x8005266C: sw          $v1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r3;
    // 0x80052670: jal         0x80052F1C
    // 0x80052674: sw          $a2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r6;
    func_80052F1C(rdram, ctx);
        goto after_0;
    // 0x80052674: sw          $a2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r6;
    after_0:
    // 0x80052678: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8005267C: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x80052680: addu        $v1, $s3, $s5
    ctx->r3 = ADD32(ctx->r19, ctx->r21);
    // 0x80052684: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80052688: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8005268C: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x80052690: lui         $a0, 0xE400
    ctx->r4 = S32(0XE400 << 16);
    // 0x80052694: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80052698: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005269C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800526A0: addu        $v0, $s1, $s4
    ctx->r2 = ADD32(ctx->r17, ctx->r20);
    // 0x800526A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800526A8: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x800526AC: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x800526B0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800526B4: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
    // 0x800526B8: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x800526BC: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x800526C0: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x800526C4: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
    // 0x800526C8: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x800526CC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800526D0: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800526D4: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x800526D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800526DC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800526E0: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x800526E4: sll         $v1, $s2, 21
    ctx->r3 = S32(ctx->r18 << 21);
    // 0x800526E8: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x800526EC: sll         $v0, $s0, 5
    ctx->r2 = S32(ctx->r16 << 5);
    // 0x800526F0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800526F4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800526F8: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x800526FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052700: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052704: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x80052708: sw          $v1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r3;
    // 0x8005270C: sll         $v1, $s7, 26
    ctx->r3 = S32(ctx->r23 << 26);
    // 0x80052710: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80052714: sll         $v0, $s6, 10
    ctx->r2 = S32(ctx->r22 << 10);
    // 0x80052718: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8005271C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80052720: sw          $v1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r3;
L_80052724:
    // 0x80052724: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x80052728: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8005272C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80052730: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80052734: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80052738: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8005273C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80052740: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80052744: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80052748: jr          $ra
    // 0x8005274C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8005274C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80052750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052750: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80052754: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80052758: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005275C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80052760: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80052764: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80052768: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8005276C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80052770: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80052774: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80052778: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8005277C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052780: ldc1        $f0, -0x14D8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X14D8);
    // 0x80052784: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x80052788: c.le.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d <= ctx->f4.d;
    // 0x8005278C: nop

    // 0x80052790: nop

    // 0x80052794: bc1f        L_8005280C
    if (!c1cs) {
        // 0x80052798: addu        $t0, $a2, $zero
        ctx->r8 = ADD32(ctx->r6, 0);
            goto L_8005280C;
    }
    // 0x80052798: addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // 0x8005279C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800527A0: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x800527A4: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x800527A8: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x800527AC: nop

    // 0x800527B0: nop

    // 0x800527B4: bc1tl       L_8005282C
    if (c1cs) {
        // 0x800527B8: div.s       $f0, $f12, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f6.fl);
            goto L_8005282C;
    }
    goto skip_0;
    // 0x800527B8: div.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f6.fl);
    skip_0:
    // 0x800527BC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800527C0: ldc1        $f0, -0x14D0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X14D0);
    // 0x800527C4: add.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d + ctx->f0.d;
    // 0x800527C8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800527CC: ldc1        $f4, -0x14C8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X14C8);
    // 0x800527D0: c.le.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d <= ctx->f0.d;
    // 0x800527D4: nop

    // 0x800527D8: bc1f        L_800528BC
    if (!c1cs) {
        // 0x800527DC: nop
    
            goto L_800528BC;
    }
    // 0x800527DC: nop

    // 0x800527E0: sub.d       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f4.d - ctx->f2.d;
    // 0x800527E4: trunc.w.s   $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x800527E8: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x800527EC: nop

    // 0x800527F0: mtc1        $v0, $f28
    ctx->f28.u32l = ctx->r2;
    // 0x800527F4: nop

    // 0x800527F8: cvt.s.w     $f28, $f28
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    ctx->f28.fl = CVT_S_W(ctx->f28.u32l);
    // 0x800527FC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80052800: nop

    // 0x80052804: j           L_800528E0
    // 0x80052808: cvt.s.d     $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f30.fl = CVT_S_D(ctx->f0.d);
        goto L_800528E0;
    // 0x80052808: cvt.s.d     $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f30.fl = CVT_S_D(ctx->f0.d);
L_8005280C:
    // 0x8005280C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80052810: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x80052814: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80052818: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x8005281C: nop

    // 0x80052820: bc1f        L_80052850
    if (!c1cs) {
        // 0x80052824: nop
    
            goto L_80052850;
    }
    // 0x80052824: nop

    // 0x80052828: div.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f6.fl);
L_8005282C:
    // 0x8005282C: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
    // 0x80052830: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052834: ldc1        $f0, -0x14C0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X14C0);
    // 0x80052838: cvt.d.s     $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f2.d = CVT_D_S(ctx->f22.fl);
    // 0x8005283C: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x80052840: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80052844: nop

    // 0x80052848: j           L_800528E0
    // 0x8005284C: cvt.s.d     $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f30.fl = CVT_S_D(ctx->f0.d);
        goto L_800528E0;
    // 0x8005284C: cvt.s.d     $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f30.fl = CVT_S_D(ctx->f0.d);
L_80052850:
    // 0x80052850: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052854: ldc1        $f0, -0x14B8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X14B8);
    // 0x80052858: mul.d       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8005285C: add.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d + ctx->f0.d;
    // 0x80052860: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052864: ldc1        $f2, -0x14B0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X14B0);
    // 0x80052868: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x8005286C: nop

    // 0x80052870: bc1f        L_800528BC
    if (!c1cs) {
        // 0x80052874: nop
    
            goto L_800528BC;
    }
    // 0x80052874: nop

    // 0x80052878: mul.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8005287C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80052880: sub.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
    // 0x80052884: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80052888: trunc.w.s   $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8005288C: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80052890: nop

    // 0x80052894: mtc1        $v0, $f28
    ctx->f28.u32l = ctx->r2;
    // 0x80052898: nop

    // 0x8005289C: cvt.s.w     $f28, $f28
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    ctx->f28.fl = CVT_S_W(ctx->f28.u32l);
    // 0x800528A0: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x800528A4: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x800528A8: nop

    // 0x800528AC: mtc1        $v0, $f30
    ctx->f30.u32l = ctx->r2;
    // 0x800528B0: nop

    // 0x800528B4: j           L_800528E0
    // 0x800528B8: cvt.s.w     $f30, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    ctx->f30.fl = CVT_S_W(ctx->f30.u32l);
        goto L_800528E0;
    // 0x800528B8: cvt.s.w     $f30, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    ctx->f30.fl = CVT_S_W(ctx->f30.u32l);
L_800528BC:
    // 0x800528BC: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800528C0: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x800528C4: trunc.w.s   $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x800528C8: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x800528CC: nop

    // 0x800528D0: mtc1        $v0, $f28
    ctx->f28.u32l = ctx->r2;
    // 0x800528D4: nop

    // 0x800528D8: cvt.s.w     $f28, $f28
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    ctx->f28.fl = CVT_S_W(ctx->f28.u32l);
    // 0x800528DC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
L_800528E0:
    // 0x800528E0: lwc1        $f6, 0x14($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800528E4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800528E8: ldc1        $f0, -0x14A8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X14A8);
    // 0x800528EC: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x800528F0: c.le.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d <= ctx->f4.d;
    // 0x800528F4: nop

    // 0x800528F8: nop

    // 0x800528FC: bc1f        L_80052970
    if (!c1cs) {
        // 0x80052900: cvt.d.s     $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.d = CVT_D_S(ctx->f14.fl);
            goto L_80052970;
    }
    // 0x80052900: cvt.d.s     $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.d = CVT_D_S(ctx->f14.fl);
    // 0x80052904: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80052908: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x8005290C: nop

    // 0x80052910: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x80052914: nop

    // 0x80052918: nop

    // 0x8005291C: bc1tl       L_80052990
    if (c1cs) {
        // 0x80052920: div.s       $f0, $f14, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f6.fl);
            goto L_80052990;
    }
    goto skip_1;
    // 0x80052920: div.s       $f0, $f14, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f6.fl);
    skip_1:
    // 0x80052924: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052928: ldc1        $f0, -0x14A0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X14A0);
    // 0x8005292C: add.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d + ctx->f0.d;
    // 0x80052930: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052934: ldc1        $f4, -0x1498($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X1498);
    // 0x80052938: c.le.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d <= ctx->f0.d;
    // 0x8005293C: nop

    // 0x80052940: bc1f        L_80052A34
    if (!c1cs) {
        // 0x80052944: nop
    
            goto L_80052A34;
    }
    // 0x80052944: nop

    // 0x80052948: sub.d       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f4.d - ctx->f2.d;
    // 0x8005294C: trunc.w.s   $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x80052950: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80052954: nop

    // 0x80052958: mtc1        $v0, $f24
    ctx->f24.u32l = ctx->r2;
    // 0x8005295C: nop

    // 0x80052960: cvt.s.w     $f24, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    ctx->f24.fl = CVT_S_W(ctx->f24.u32l);
    // 0x80052964: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80052968: j           L_80052A18
    // 0x8005296C: nop

        goto L_80052A18;
    // 0x8005296C: nop

L_80052970:
    // 0x80052970: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80052974: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x80052978: nop

    // 0x8005297C: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x80052980: nop

    // 0x80052984: bc1f        L_800529C8
    if (!c1cs) {
        // 0x80052988: nop
    
            goto L_800529C8;
    }
    // 0x80052988: nop

    // 0x8005298C: div.s       $f0, $f14, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f6.fl);
L_80052990:
    // 0x80052990: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
    // 0x80052994: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052998: ldc1        $f2, -0x1490($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1490);
    // 0x8005299C: trunc.w.s   $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x800529A0: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x800529A4: nop

    // 0x800529A8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800529AC: nop

    // 0x800529B0: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x800529B4: sub.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = ctx->f2.d - ctx->f0.d;
    // 0x800529B8: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800529BC: nop

    // 0x800529C0: j           L_80052A58
    // 0x800529C4: cvt.s.d     $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f26.fl = CVT_S_D(ctx->f2.d);
        goto L_80052A58;
    // 0x800529C4: cvt.s.d     $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f26.fl = CVT_S_D(ctx->f2.d);
L_800529C8:
    // 0x800529C8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800529CC: ldc1        $f0, -0x1488($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1488);
    // 0x800529D0: mul.d       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800529D4: add.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d + ctx->f0.d;
    // 0x800529D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800529DC: ldc1        $f2, -0x1480($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1480);
    // 0x800529E0: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x800529E4: nop

    // 0x800529E8: bc1f        L_80052A34
    if (!c1cs) {
        // 0x800529EC: nop
    
            goto L_80052A34;
    }
    // 0x800529EC: nop

    // 0x800529F0: mul.s       $f0, $f14, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x800529F4: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x800529F8: sub.d       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f2.d - ctx->f0.d;
    // 0x800529FC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80052A00: trunc.w.s   $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x80052A04: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80052A08: nop

    // 0x80052A0C: mtc1        $v0, $f24
    ctx->f24.u32l = ctx->r2;
    // 0x80052A10: nop

    // 0x80052A14: cvt.s.w     $f24, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    ctx->f24.fl = CVT_S_W(ctx->f24.u32l);
L_80052A18:
    // 0x80052A18: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80052A1C: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80052A20: nop

    // 0x80052A24: mtc1        $v0, $f26
    ctx->f26.u32l = ctx->r2;
    // 0x80052A28: nop

    // 0x80052A2C: j           L_80052A58
    // 0x80052A30: cvt.s.w     $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    ctx->f26.fl = CVT_S_W(ctx->f26.u32l);
        goto L_80052A58;
    // 0x80052A30: cvt.s.w     $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    ctx->f26.fl = CVT_S_W(ctx->f26.u32l);
L_80052A34:
    // 0x80052A34: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80052A38: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80052A3C: trunc.w.s   $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x80052A40: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x80052A44: nop

    // 0x80052A48: mtc1        $v0, $f24
    ctx->f24.u32l = ctx->r2;
    // 0x80052A4C: nop

    // 0x80052A50: cvt.s.w     $f24, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    ctx->f24.fl = CVT_S_W(ctx->f24.u32l);
    // 0x80052A54: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
L_80052A58:
    // 0x80052A58: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052A5C: ldc1        $f2, -0x1478($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1478);
    // 0x80052A60: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x80052A64: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x80052A68: nop

    // 0x80052A6C: nop

    // 0x80052A70: bc1t        L_80052A7C
    if (c1cs) {
        // 0x80052A74: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80052A7C;
    }
    // 0x80052A74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80052A78: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80052A7C:
    // 0x80052A7C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052A80: ldc1        $f2, -0x1470($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1470);
    // 0x80052A84: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x80052A88: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x80052A8C: nop

    // 0x80052A90: nop

    // 0x80052A94: bc1t        L_80052AA0
    if (c1cs) {
        // 0x80052A98: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80052AA0;
    }
    // 0x80052A98: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80052A9C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80052AA0:
    // 0x80052AA0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80052AA4: bne         $v0, $zero, L_80052EF0
    if (ctx->r2 != 0) {
        // 0x80052AA8: nop
    
            goto L_80052EF0;
    }
    // 0x80052AA8: nop

    // 0x80052AAC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80052AB0: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x80052AB4: cvt.d.s     $f10, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f10.d = CVT_D_S(ctx->f30.fl);
    // 0x80052AB8: c.le.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d <= ctx->f0.d;
    // 0x80052ABC: nop

    // 0x80052AC0: nop

    // 0x80052AC4: bc1t        L_80052AD0
    if (c1cs) {
        // 0x80052AC8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80052AD0;
    }
    // 0x80052AC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80052ACC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80052AD0:
    // 0x80052AD0: cvt.d.s     $f8, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f8.d = CVT_D_S(ctx->f26.fl);
    // 0x80052AD4: c.le.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d <= ctx->f0.d;
    // 0x80052AD8: nop

    // 0x80052ADC: nop

    // 0x80052AE0: bc1t        L_80052AEC
    if (c1cs) {
        // 0x80052AE4: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80052AEC;
    }
    // 0x80052AE4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80052AE8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80052AEC:
    // 0x80052AEC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80052AF0: bne         $v0, $zero, L_80052EF0
    if (ctx->r2 != 0) {
        // 0x80052AF4: nop
    
            goto L_80052EF0;
    }
    // 0x80052AF4: nop

    // 0x80052AF8: lwc1        $f0, 0x10($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80052AFC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052B00: ldc1        $f4, -0x1468($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X1468);
    // 0x80052B04: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80052B08: mul.d       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x80052B0C: lwc1        $f0, 0x14($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80052B10: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80052B14: mul.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x80052B18: nop

    // 0x80052B1C: mul.d       $f2, $f10, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x80052B20: nop

    // 0x80052B24: mul.d       $f0, $f8, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80052B28: trunc.w.d   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x80052B2C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80052B30: nop

    // 0x80052B34: mtc1        $v0, $f30
    ctx->f30.u32l = ctx->r2;
    // 0x80052B38: nop

    // 0x80052B3C: cvt.s.w     $f30, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    ctx->f30.fl = CVT_S_W(ctx->f30.u32l);
    // 0x80052B40: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80052B44: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80052B48: lh          $v1, 0x4($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X4);
    // 0x80052B4C: lhu         $a0, 0x6($a3)
    ctx->r4 = MEM_HU(ctx->r7, 0X6);
    // 0x80052B50: mtc1        $v0, $f26
    ctx->f26.u32l = ctx->r2;
    // 0x80052B54: nop

    // 0x80052B58: bne         $v1, $zero, L_80052B88
    if (ctx->r3 != 0) {
        // 0x80052B5C: cvt.s.w     $f26, $f26
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    ctx->f26.fl = CVT_S_W(ctx->f26.u32l);
            goto L_80052B88;
    }
    // 0x80052B5C: cvt.s.w     $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    ctx->f26.fl = CVT_S_W(ctx->f26.u32l);
    // 0x80052B60: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052B64: ldc1        $f0, -0x1460($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1460);
    // 0x80052B68: div.d       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = DIV_D(ctx->f0.d, ctx->f6.d);
    // 0x80052B6C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052B70: ldc1        $f2, -0x1458($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1458);
    // 0x80052B74: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x80052B78: trunc.w.d   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_D(ctx->f0.d);
    // 0x80052B7C: mfc1        $s1, $f2
    ctx->r17 = (int32_t)ctx->f2.u32l;
    // 0x80052B80: j           L_80052BBC
    // 0x80052B84: nop

        goto L_80052BBC;
    // 0x80052B84: nop

L_80052B88:
    // 0x80052B88: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052B8C: ldc1        $f4, -0x1450($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X1450);
    // 0x80052B90: div.d       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x80052B94: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052B98: ldc1        $f2, -0x1448($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1448);
    // 0x80052B9C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052BA0: ldc1        $f0, -0x1440($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1440);
    // 0x80052BA4: mul.d       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x80052BA8: cvt.d.s     $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f2.d = CVT_D_S(ctx->f22.fl);
    // 0x80052BAC: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x80052BB0: cvt.s.d     $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f22.fl = CVT_S_D(ctx->f0.d);
    // 0x80052BB4: trunc.w.d   $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x80052BB8: mfc1        $s1, $f0
    ctx->r17 = (int32_t)ctx->f0.u32l;
L_80052BBC:
    // 0x80052BBC: bne         $a0, $zero, L_80052BF4
    if (ctx->r4 != 0) {
        // 0x80052BC0: nop
    
            goto L_80052BF4;
    }
    // 0x80052BC0: nop

    // 0x80052BC4: lwc1        $f0, 0x14($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80052BC8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052BCC: ldc1        $f2, -0x1438($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1438);
    // 0x80052BD0: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80052BD4: div.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = DIV_D(ctx->f2.d, ctx->f0.d);
    // 0x80052BD8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052BDC: ldc1        $f0, -0x1430($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1430);
    // 0x80052BE0: mul.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f0.d);
    // 0x80052BE4: trunc.w.d   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x80052BE8: mfc1        $s0, $f0
    ctx->r16 = (int32_t)ctx->f0.u32l;
    // 0x80052BEC: j           L_80052C30
    // 0x80052BF0: nop

        goto L_80052C30;
    // 0x80052BF0: nop

L_80052BF4:
    // 0x80052BF4: lwc1        $f0, 0x14($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80052BF8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052BFC: ldc1        $f4, -0x1428($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X1428);
    // 0x80052C00: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80052C04: div.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f4.d, ctx->f0.d);
    // 0x80052C08: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052C0C: ldc1        $f2, -0x1420($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1420);
    // 0x80052C10: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052C14: ldc1        $f0, -0x1418($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1418);
    // 0x80052C18: mul.d       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x80052C1C: cvt.d.s     $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f2.d = CVT_D_S(ctx->f20.fl);
    // 0x80052C20: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x80052C24: cvt.s.d     $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f20.fl = CVT_S_D(ctx->f0.d);
    // 0x80052C28: trunc.w.d   $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x80052C2C: mfc1        $s0, $f0
    ctx->r16 = (int32_t)ctx->f0.u32l;
L_80052C30:
    // 0x80052C30: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80052C34: lw          $a0, -0x38C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X38C0);
    // 0x80052C38: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80052C3C: lw          $v0, -0x3820($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3820);
    // 0x80052C40: beq         $a0, $v0, L_80052D04
    if (ctx->r4 == ctx->r2) {
        // 0x80052C44: lui         $a1, 0xF500
        ctx->r5 = S32(0XF500 << 16);
            goto L_80052D04;
    }
    // 0x80052C44: lui         $a1, 0xF500
    ctx->r5 = S32(0XF500 << 16);
    // 0x80052C48: ori         $a1, $a1, 0x100
    ctx->r5 = ctx->r5 | 0X100;
    // 0x80052C4C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80052C50: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80052C54: lui         $a2, 0x703
    ctx->r6 = S32(0X703 << 16);
    // 0x80052C58: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x80052C5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80052C60: sw          $a0, -0x3820($at)
    MEM_W(-0X3820, ctx->r1) = ctx->r4;
    // 0x80052C64: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80052C68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052C6C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052C70: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x80052C74: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80052C78: sll         $v0, $a0, 5
    ctx->r2 = S32(ctx->r4 << 5);
    // 0x80052C7C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80052C80: addiu       $a0, $a0, -0x3250
    ctx->r4 = ADD32(ctx->r4, -0X3250);
    // 0x80052C84: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80052C88: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80052C8C: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80052C90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052C94: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052C98: lui         $v0, 0xE800
    ctx->r2 = S32(0XE800 << 16);
    // 0x80052C9C: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x80052CA0: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x80052CA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052CA8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052CAC: lui         $v0, 0x700
    ctx->r2 = S32(0X700 << 16);
    // 0x80052CB0: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x80052CB4: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x80052CB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052CBC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052CC0: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x80052CC4: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x80052CC8: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x80052CCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052CD0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052CD4: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x80052CD8: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // 0x80052CDC: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x80052CE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052CE4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052CE8: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x80052CEC: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x80052CF0: sw          $a1, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r5;
    // 0x80052CF4: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x80052CF8: sw          $a2, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r6;
    // 0x80052CFC: sw          $v0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r2;
    // 0x80052D00: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
L_80052D04:
    // 0x80052D04: lui         $a0, 0x73F
    ctx->r4 = S32(0X73F << 16);
    // 0x80052D08: ori         $a0, $a0, 0xF200
    ctx->r4 = ctx->r4 | 0XF200;
    // 0x80052D0C: lui         $a1, 0xF540
    ctx->r5 = S32(0XF540 << 16);
    // 0x80052D10: ori         $a1, $a1, 0x800
    ctx->r5 = ctx->r5 | 0X800;
    // 0x80052D14: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80052D18: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80052D1C: lui         $a2, 0xF
    ctx->r6 = S32(0XF << 16);
    // 0x80052D20: ori         $a2, $a2, 0xC0FC
    ctx->r6 = ctx->r6 | 0XC0FC;
    // 0x80052D24: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052D28: ldc1        $f0, -0x1410($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1410);
    // 0x80052D2C: cvt.d.s     $f6, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); 
    ctx->f6.d = CVT_D_S(ctx->f28.fl);
    // 0x80052D30: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80052D34: ldc1        $f8, -0x1408($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X1408);
    // 0x80052D38: cvt.d.s     $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f4.d = CVT_D_S(ctx->f24.fl);
    // 0x80052D3C: cvt.d.s     $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f2.d = CVT_D_S(ctx->f22.fl);
    // 0x80052D40: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80052D44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052D48: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052D4C: lui         $v0, 0xFD50
    ctx->r2 = S32(0XFD50 << 16);
    // 0x80052D50: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80052D54: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80052D58: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052D5C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052D60: lui         $v0, 0xF550
    ctx->r2 = S32(0XF550 << 16);
    // 0x80052D64: mul.d       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x80052D68: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x80052D6C: lui         $v0, 0x700
    ctx->r2 = S32(0X700 << 16);
    // 0x80052D70: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x80052D74: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x80052D78: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052D7C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052D80: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x80052D84: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x80052D88: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x80052D8C: mul.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80052D90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052D94: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052D98: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x80052D9C: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x80052DA0: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x80052DA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052DA8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052DAC: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x80052DB0: sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // 0x80052DB4: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x80052DB8: mul.d       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x80052DBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052DC0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052DC4: addiu       $v0, $v1, 0x38
    ctx->r2 = ADD32(ctx->r3, 0X38);
    // 0x80052DC8: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x80052DCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052DD0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052DD4: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x80052DD8: sw          $a0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r4;
    // 0x80052DDC: addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    // 0x80052DE0: mul.d       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f8.d);
    // 0x80052DE4: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80052DE8: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x80052DEC: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x80052DF0: sw          $a1, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r5;
    // 0x80052DF4: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x80052DF8: sw          $v0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r2;
    // 0x80052DFC: sw          $a2, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r6;
    // 0x80052E00: cvt.s.d     $f28, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f28.fl = CVT_S_D(ctx->f6.d);
    // 0x80052E04: cvt.s.d     $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f24.fl = CVT_S_D(ctx->f4.d);
    // 0x80052E08: cvt.s.d     $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f22.fl = CVT_S_D(ctx->f2.d);
    // 0x80052E0C: jal         0x80052F1C
    // 0x80052E10: cvt.s.d     $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f20.fl = CVT_S_D(ctx->f0.d);
    func_80052F1C(rdram, ctx);
        goto after_0;
    // 0x80052E10: cvt.s.d     $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f20.fl = CVT_S_D(ctx->f0.d);
    after_0:
    // 0x80052E14: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80052E18: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x80052E1C: add.s       $f2, $f28, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = ctx->f28.fl + ctx->f30.fl;
    // 0x80052E20: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80052E24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052E28: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052E2C: trunc.w.s   $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.u32l = TRUNC_W_S(ctx->f28.fl);
    // 0x80052E30: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x80052E34: nop

    // 0x80052E38: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80052E3C: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x80052E40: trunc.w.s   $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    ctx->f0.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x80052E44: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x80052E48: nop

    // 0x80052E4C: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80052E50: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80052E54: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80052E58: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x80052E5C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052E60: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052E64: lui         $v0, 0xB400
    ctx->r2 = S32(0XB400 << 16);
    // 0x80052E68: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x80052E6C: trunc.w.s   $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.u32l = TRUNC_W_S(ctx->f22.fl);
    // 0x80052E70: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x80052E74: nop

    // 0x80052E78: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80052E7C: trunc.w.s   $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x80052E80: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x80052E84: nop

    // 0x80052E88: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80052E8C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80052E90: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x80052E94: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052E98: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052E9C: lui         $v0, 0xB300
    ctx->r2 = S32(0XB300 << 16);
    // 0x80052EA0: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80052EA4: sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17 << 16);
    // 0x80052EA8: sw          $v1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r3;
    // 0x80052EAC: andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // 0x80052EB0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80052EB4: add.s       $f0, $f24, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f24.fl + ctx->f26.fl;
    // 0x80052EB8: sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
    // 0x80052EBC: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80052EC0: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80052EC4: nop

    // 0x80052EC8: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80052ECC: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x80052ED0: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80052ED4: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x80052ED8: nop

    // 0x80052EDC: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80052EE0: lui         $a0, 0xE400
    ctx->r4 = S32(0XE400 << 16);
    // 0x80052EE4: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x80052EE8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80052EEC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_80052EF0:
    // 0x80052EF0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80052EF4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80052EF8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80052EFC: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80052F00: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80052F04: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80052F08: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80052F0C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80052F10: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80052F14: jr          $ra
    // 0x80052F18: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80052F18: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80052F1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052F1C: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x80052F20: bne         $v0, $zero, L_80052F7C
    if (ctx->r2 != 0) {
        // 0x80052F24: lui         $t0, 0xFC11
        ctx->r8 = S32(0XFC11 << 16);
            goto L_80052F7C;
    }
    // 0x80052F24: lui         $t0, 0xFC11
    ctx->r8 = S32(0XFC11 << 16);
    // 0x80052F28: lui         $a2, 0xFCFF
    ctx->r6 = S32(0XFCFF << 16);
    // 0x80052F2C: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80052F30: lui         $a1, 0xFFFC
    ctx->r5 = S32(0XFFFC << 16);
    // 0x80052F34: ori         $a1, $a1, 0xF279
    ctx->r5 = ctx->r5 | 0XF279;
    // 0x80052F38: lui         $a3, 0xB900
    ctx->r7 = S32(0XB900 << 16);
    // 0x80052F3C: ori         $a3, $a3, 0x31D
    ctx->r7 = ctx->r7 | 0X31D;
    // 0x80052F40: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80052F44: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80052F48: lui         $a0, 0xF0A
    ctx->r4 = S32(0XF0A << 16);
    // 0x80052F4C: ori         $a0, $a0, 0x7008
    ctx->r4 = ctx->r4 | 0X7008;
    // 0x80052F50: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80052F54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052F58: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052F5C: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80052F60: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x80052F64: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x80052F68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052F6C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052F70: sw          $a3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r7;
    // 0x80052F74: j           L_80053008
    // 0x80052F78: sw          $a0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r4;
        goto L_80053008;
    // 0x80052F78: sw          $a0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r4;
L_80052F7C:
    // 0x80052F7C: ori         $t0, $t0, 0x9623
    ctx->r8 = ctx->r8 | 0X9623;
    // 0x80052F80: lui         $a3, 0xFF2F
    ctx->r7 = S32(0XFF2F << 16);
    // 0x80052F84: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x80052F88: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x80052F8C: ori         $t1, $t1, 0x31D
    ctx->r9 = ctx->r9 | 0X31D;
    // 0x80052F90: lw          $a0, 0x24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24);
    // 0x80052F94: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80052F98: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x80052F9C: lui         $a2, 0x40
    ctx->r6 = S32(0X40 << 16);
    // 0x80052FA0: ori         $a2, $a2, 0x4240
    ctx->r6 = ctx->r6 | 0X4240;
    // 0x80052FA4: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80052FA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052FAC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052FB0: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x80052FB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052FB8: sw          $a0, -0x68A0($at)
    MEM_W(-0X68A0, ctx->r1) = ctx->r4;
    // 0x80052FBC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80052FC0: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80052FC4: sll         $v0, $a0, 24
    ctx->r2 = S32(ctx->r4 << 24);
    // 0x80052FC8: sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4 << 16);
    // 0x80052FCC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80052FD0: sll         $v1, $a0, 8
    ctx->r3 = S32(ctx->r4 << 8);
    // 0x80052FD4: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80052FD8: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x80052FDC: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80052FE0: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x80052FE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052FE8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80052FEC: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x80052FF0: sw          $t0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r8;
    // 0x80052FF4: sw          $a3, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r7;
    // 0x80052FF8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052FFC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80053000: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
    // 0x80053004: sw          $a2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r6;
L_80053008:
    // 0x80053008: jr          $ra
    // 0x8005300C: nop

    return;
    // 0x8005300C: nop

;}
RECOMP_FUNC void func_80053010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80053014: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x80053018: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8005301C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80053020: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x80053024: lw          $v1, -0x1994($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1994);
    // 0x80053028: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x8005302C: addu        $a3, $a3, $a2
    ctx->r7 = ADD32(ctx->r7, ctx->r6);
    // 0x80053030: lw          $a3, -0x1998($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X1998);
    // 0x80053034: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x80053038: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8005303C: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x80053040: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x80053044: lw          $t0, -0x199C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X199C);
    // 0x80053048: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005304C: addu        $a0, $a0, $a3
    ctx->r4 = ADD32(ctx->r4, ctx->r7);
    // 0x80053050: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80053054: lw          $a3, 0x4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X4);
    // 0x80053058: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x8005305C: lbu         $a2, 0x0($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X0);
    // 0x80053060: addu        $a1, $t0, $v0
    ctx->r5 = ADD32(ctx->r8, ctx->r2);
    // 0x80053064: jal         0x800530F4
    // 0x80053068: subu        $a3, $a3, $v0
    ctx->r7 = SUB32(ctx->r7, ctx->r2);
    func_800530F4(rdram, ctx);
        goto after_0;
    // 0x80053068: subu        $a3, $a3, $v0
    ctx->r7 = SUB32(ctx->r7, ctx->r2);
    after_0:
    // 0x8005306C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80053070: jr          $ra
    // 0x80053074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80053074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80053078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053078: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005307C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80053080: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80053084: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80053088: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8005308C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80053090: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x80053094: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    // 0x80053098: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005309C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800530A0: jal         0x80006D98
    // 0x800530A4: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    func_80006D98(rdram, ctx);
        goto after_0;
    // 0x800530A4: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    after_0:
    // 0x800530A8: addiu       $a0, $s2, 0x200
    ctx->r4 = ADD32(ctx->r18, 0X200);
    // 0x800530AC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800530B0: subu        $s0, $s0, $a2
    ctx->r16 = SUB32(ctx->r16, ctx->r6);
    // 0x800530B4: addu        $s0, $s3, $s0
    ctx->r16 = ADD32(ctx->r19, ctx->r16);
    // 0x800530B8: addiu       $s0, $s0, 0x200
    ctx->r16 = ADD32(ctx->r16, 0X200);
    // 0x800530BC: jal         0x80006D98
    // 0x800530C0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80006D98(rdram, ctx);
        goto after_1;
    // 0x800530C0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800530C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800530C8: jal         0x8005319C
    // 0x800530CC: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8005319C(rdram, ctx);
        goto after_2;
    // 0x800530CC: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_2:
    // 0x800530D0: jal         0x80061710
    // 0x800530D4: nop

    func_80061710(rdram, ctx);
        goto after_3;
    // 0x800530D4: nop

    after_3:
    // 0x800530D8: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800530DC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800530E0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800530E4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800530E8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800530EC: jr          $ra
    // 0x800530F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800530F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800530F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800530F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800530F8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800530FC: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80053100: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80053104: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x80053108: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005310C: sll         $s0, $a2, 11
    ctx->r16 = S32(ctx->r6 << 11);
    // 0x80053110: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80053114: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80053118: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8005311C: jal         0x80061490
    // 0x80053120: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80053120: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    after_0:
    // 0x80053124: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80053128: addiu       $a0, $a0, -0x5E40
    ctx->r4 = ADD32(ctx->r4, -0X5E40);
    // 0x8005312C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80053130: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80053134: subu        $s0, $s0, $s1
    ctx->r16 = SUB32(ctx->r16, ctx->r17);
    // 0x80053138: addu        $s0, $s2, $s0
    ctx->r16 = ADD32(ctx->r18, ctx->r16);
    // 0x8005313C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80053140: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80053144: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80053148: addiu       $s1, $s1, 0x4800
    ctx->r17 = ADD32(ctx->r17, 0X4800);
    // 0x8005314C: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // 0x80053150: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80053154: jal         0x800667A0
    // 0x80053158: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    osPiStartDma_recomp(rdram, ctx);
        goto after_1;
    // 0x80053158: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_1:
    // 0x8005315C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80053160: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80053164: jal         0x800619A0
    // 0x80053168: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80053168: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8005316C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80053170: jal         0x8005319C
    // 0x80053174: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_8005319C(rdram, ctx);
        goto after_3;
    // 0x80053174: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_3:
    // 0x80053178: jal         0x80061710
    // 0x8005317C: nop

    func_80061710(rdram, ctx);
        goto after_4;
    // 0x8005317C: nop

    after_4:
    // 0x80053180: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80053184: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80053188: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8005318C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80053190: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80053194: jr          $ra
    // 0x80053198: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80053198: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8005319C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_8005319C:
    // 0x8005319C: lhu         $t1, 0x0($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X0);
    // 0x800531A0: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800531A4: ori         $t0, $zero, 0x8000
    ctx->r8 = 0 | 0X8000;
    // 0x800531A8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
L_800531AC:
    // 0x800531AC: and         $v0, $t0, $t1
    ctx->r2 = ctx->r8 & ctx->r9;
    // 0x800531B0: bne         $v0, $zero, L_800531CC
    if (ctx->r2 != 0) {
        // 0x800531B4: nop
    
            goto L_800531CC;
    }
    // 0x800531B4: nop

    // 0x800531B8: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800531BC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800531C0: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x800531C4: j           L_80053218
    // 0x800531C8: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
        goto L_80053218;
    // 0x800531C8: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_800531CC:
    // 0x800531CC: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x800531D0: andi        $v0, $v1, 0xF800
    ctx->r2 = ctx->r3 & 0XF800;
    // 0x800531D4: beq         $v0, $zero, L_800531E8
    if (ctx->r2 == 0) {
        // 0x800531D8: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_800531E8;
    }
    // 0x800531D8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800531DC: srl         $a2, $v0, 11
    ctx->r6 = S32(U32(ctx->r2) >> 11);
    // 0x800531E0: j           L_800531F0
    // 0x800531E4: andi        $v1, $v1, 0x7FF
    ctx->r3 = ctx->r3 & 0X7FF;
        goto L_800531F0;
    // 0x800531E4: andi        $v1, $v1, 0x7FF
    ctx->r3 = ctx->r3 & 0X7FF;
L_800531E8:
    // 0x800531E8: lhu         $a2, 0x0($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X0);
    // 0x800531EC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_800531F0:
    // 0x800531F0: or          $v0, $a2, $v1
    ctx->r2 = ctx->r6 | ctx->r3;
    // 0x800531F4: beq         $v0, $zero, L_8005322C
    if (ctx->r2 == 0) {
        // 0x800531F8: sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3 << 1);
            goto L_8005322C;
    }
    // 0x800531F8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800531FC: subu        $v1, $a1, $v0
    ctx->r3 = SUB32(ctx->r5, ctx->r2);
L_80053200:
    // 0x80053200: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80053204: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80053208: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8005320C: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x80053210: bne         $a2, $zero, L_80053200
    if (ctx->r6 != 0) {
        // 0x80053214: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_80053200;
    }
    // 0x80053214: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_80053218:
    // 0x80053218: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8005321C: bne         $a3, $zero, L_800531AC
    if (ctx->r7 != 0) {
        // 0x80053220: srl         $t0, $t0, 1
        ctx->r8 = S32(U32(ctx->r8) >> 1);
            goto L_800531AC;
    }
    // 0x80053220: srl         $t0, $t0, 1
    ctx->r8 = S32(U32(ctx->r8) >> 1);
    // 0x80053224: j           L_8005319C
    // 0x80053228: nop

        goto L_8005319C;
    // 0x80053228: nop

L_8005322C:
    // 0x8005322C: jr          $ra
    // 0x80053230: nop

    return;
    // 0x80053230: nop

;}
RECOMP_FUNC void func_80053234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053234: sll         $a1, $a1, 4
    ctx->r5 = S32(ctx->r5 << 4);
    // 0x80053238: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8005323C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80053240: lw          $v0, -0x1990($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1990);
    // 0x80053244: sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6 << 3);
    // 0x80053248: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8005324C: jr          $ra
    // 0x80053250: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    return;
    // 0x80053250: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_80053254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80053258: sll         $a1, $a1, 4
    ctx->r5 = S32(ctx->r5 << 4);
    // 0x8005325C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80053260: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80053264: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80053268: lw          $v0, -0x1990($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1990);
    // 0x8005326C: sll         $a3, $a2, 3
    ctx->r7 = S32(ctx->r6 << 3);
    // 0x80053270: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80053274: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80053278: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8005327C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80053280: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80053284: lw          $v0, -0x1994($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1994);
    // 0x80053288: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8005328C: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80053290: lw          $v1, -0x1998($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1998);
    // 0x80053294: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80053298: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x8005329C: lw          $a1, -0x199C($at)
    ctx->r5 = MEM_W(ctx->r1, -0X199C);
    // 0x800532A0: lw          $a0, 0x1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1C);
    // 0x800532A4: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800532A8: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x800532AC: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800532B0: lw          $a3, 0x4($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X4);
    // 0x800532B4: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
    // 0x800532B8: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x800532BC: jal         0x800530F4
    // 0x800532C0: subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
    func_800530F4(rdram, ctx);
        goto after_0;
    // 0x800532C0: subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
    after_0:
    // 0x800532C4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800532C8: jr          $ra
    // 0x800532CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800532CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800532D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800532D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800532D4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800532D8: jal         0x800532F4
    // 0x800532DC: nop

    func_800532F4(rdram, ctx);
        goto after_0;
    // 0x800532DC: nop

    after_0:
    // 0x800532E0: jal         0x80053320
    // 0x800532E4: nop

    func_80053320(rdram, ctx);
        goto after_1;
    // 0x800532E4: nop

    after_1:
    // 0x800532E8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800532EC: jr          $ra
    // 0x800532F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800532F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800532F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800532F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800532F8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800532FC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80053300: addiu       $a0, $a0, 0x4D90
    ctx->r4 = ADD32(ctx->r4, 0X4D90);
    // 0x80053304: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80053308: addiu       $a1, $a1, -0x3250
    ctx->r5 = ADD32(ctx->r5, -0X3250);
    // 0x8005330C: jal         0x8005334C
    // 0x80053310: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    func_8005334C(rdram, ctx);
        goto after_0;
    // 0x80053310: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_0:
    // 0x80053314: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80053318: jr          $ra
    // 0x8005331C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005331C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80053320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053320: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80053324: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80053328: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8005332C: addiu       $a0, $a0, 0x5090
    ctx->r4 = ADD32(ctx->r4, 0X5090);
    // 0x80053330: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80053334: addiu       $a1, $a1, -0x2F50
    ctx->r5 = ADD32(ctx->r5, -0X2F50);
    // 0x80053338: jal         0x8005334C
    // 0x8005333C: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    func_8005334C(rdram, ctx);
        goto after_0;
    // 0x8005333C: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_0:
    // 0x80053340: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80053344: jr          $ra
    // 0x80053348: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80053348: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8005334C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005334C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80053350: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x80053354: blez        $a2, L_80053378
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80053358: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80053378;
    }
    // 0x80053358: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8005335C:
    // 0x8005335C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80053360: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80053364: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80053368: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8005336C: slt         $v0, $v1, $a2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80053370: bne         $v0, $zero, L_8005335C
    if (ctx->r2 != 0) {
        // 0x80053374: addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
            goto L_8005335C;
    }
    // 0x80053374: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
L_80053378:
    // 0x80053378: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8005337C: jr          $ra
    // 0x80053380: nop

    return;
    // 0x80053380: nop

;}
RECOMP_FUNC void func_80053390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053390: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80053394: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80053398: addiu       $v1, $v1, -0x42A0
    ctx->r3 = ADD32(ctx->r3, -0X42A0);
    // 0x8005339C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800533A0: addiu       $a0, $a0, 0x3A40
    ctx->r4 = ADD32(ctx->r4, 0X3A40);
    // 0x800533A4: addiu       $a3, $zero, 0x880
    ctx->r7 = ADD32(0, 0X880);
    // 0x800533A8: addiu       $a2, $zero, 0x1100
    ctx->r6 = ADD32(0, 0X1100);
    // 0x800533AC: addiu       $v0, $v1, 0x44
    ctx->r2 = ADD32(ctx->r3, 0X44);
L_800533B0:
    // 0x800533B0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800533B4: sw          $zero, -0x40($v0)
    MEM_W(-0X40, ctx->r2) = 0;
    // 0x800533B8: sw          $a0, -0x34($v0)
    MEM_W(-0X34, ctx->r2) = ctx->r4;
    // 0x800533BC: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x800533C0: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x800533C4: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x800533C8: sw          $a3, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r7;
    // 0x800533CC: sw          $a2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r6;
    // 0x800533D0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800533D4: addiu       $v0, $v0, 0x13C
    ctx->r2 = ADD32(ctx->r2, 0X13C);
    // 0x800533D8: addiu       $v1, $v1, 0x13C
    ctx->r3 = ADD32(ctx->r3, 0X13C);
    // 0x800533DC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800533E0: bne         $a1, $zero, L_800533B0
    if (ctx->r5 != 0) {
        // 0x800533E4: addiu       $a0, $a0, 0x1980
        ctx->r4 = ADD32(ctx->r4, 0X1980);
            goto L_800533B0;
    }
    // 0x800533E4: addiu       $a0, $a0, 0x1980
    ctx->r4 = ADD32(ctx->r4, 0X1980);
    // 0x800533E8: jr          $ra
    // 0x800533EC: nop

    return;
    // 0x800533EC: nop

;}
RECOMP_FUNC void func_800533F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800533F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800533F4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800533F8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800533FC: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x80053400: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80053404: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80053408: addiu       $s0, $s0, -0x42A0
    ctx->r16 = ADD32(ctx->r16, -0X42A0);
    // 0x8005340C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
L_80053410:
    // 0x80053410: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x80053414: bnel        $v0, $zero, L_8005341C
    if (ctx->r2 != 0) {
        // 0x80053418: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8005341C;
    }
    goto skip_0;
    // 0x80053418: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_0:
L_8005341C:
    // 0x8005341C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80053420: bne         $s1, $zero, L_80053410
    if (ctx->r17 != 0) {
        // 0x80053424: addiu       $s0, $s0, 0x13C
        ctx->r16 = ADD32(ctx->r16, 0X13C);
            goto L_80053410;
    }
    // 0x80053424: addiu       $s0, $s0, 0x13C
    ctx->r16 = ADD32(ctx->r16, 0X13C);
    // 0x80053428: beq         $v1, $zero, L_80053568
    if (ctx->r3 == 0) {
        // 0x8005342C: lui         $a0, 0xBA00
        ctx->r4 = S32(0XBA00 << 16);
            goto L_80053568;
    }
    // 0x8005342C: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x80053430: ori         $a0, $a0, 0x1402
    ctx->r4 = ctx->r4 | 0X1402;
    // 0x80053434: lui         $a2, 0xFCFF
    ctx->r6 = S32(0XFCFF << 16);
    // 0x80053438: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x8005343C: lui         $a1, 0xFFFC
    ctx->r5 = S32(0XFFFC << 16);
    // 0x80053440: ori         $a1, $a1, 0xF279
    ctx->r5 = ctx->r5 | 0XF279;
    // 0x80053444: lui         $a3, 0xBA00
    ctx->r7 = S32(0XBA00 << 16);
    // 0x80053448: ori         $a3, $a3, 0x1301
    ctx->r7 = ctx->r7 | 0X1301;
    // 0x8005344C: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x80053450: ori         $t1, $t1, 0x31D
    ctx->r9 = ctx->r9 | 0X31D;
    // 0x80053454: lui         $t0, 0xF0A
    ctx->r8 = S32(0XF0A << 16);
    // 0x80053458: ori         $t0, $t0, 0x7008
    ctx->r8 = ctx->r8 | 0X7008;
    // 0x8005345C: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x80053460: ori         $t2, $t2, 0xE02
    ctx->r10 = ctx->r10 | 0XE02;
    // 0x80053464: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80053468: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x8005346C: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x80053470: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80053474: addiu       $s0, $s0, -0x42A0
    ctx->r16 = ADD32(ctx->r16, -0X42A0);
    // 0x80053478: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8005347C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053480: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80053484: lui         $v1, 0xE700
    ctx->r3 = S32(0XE700 << 16);
    // 0x80053488: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8005348C: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x80053490: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053494: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80053498: addiu       $v1, $v0, 0x18
    ctx->r3 = ADD32(ctx->r2, 0X18);
    // 0x8005349C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800534A0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800534A4: addiu       $v1, $v0, 0x20
    ctx->r3 = ADD32(ctx->r2, 0X20);
    // 0x800534A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800534AC: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800534B0: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x800534B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800534B8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800534BC: addiu       $v1, $v0, 0x30
    ctx->r3 = ADD32(ctx->r2, 0X30);
    // 0x800534C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800534C4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800534C8: ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // 0x800534CC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800534D0: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x800534D4: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800534D8: sw          $a2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r6;
    // 0x800534DC: sw          $a1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r5;
    // 0x800534E0: sw          $a3, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r7;
    // 0x800534E4: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x800534E8: sw          $t1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r9;
    // 0x800534EC: sw          $t0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r8;
    // 0x800534F0: sw          $t2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r10;
    // 0x800534F4: sw          $v1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r3;
L_800534F8:
    // 0x800534F8: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x800534FC: beql        $v0, $zero, L_80053510
    if (ctx->r2 == 0) {
        // 0x80053500: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80053510;
    }
    goto skip_1;
    // 0x80053500: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_1:
    // 0x80053504: jal         0x800535DC
    // 0x80053508: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800535DC(rdram, ctx);
        goto after_0;
    // 0x80053508: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8005350C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80053510:
    // 0x80053510: bne         $s1, $zero, L_800534F8
    if (ctx->r17 != 0) {
        // 0x80053514: addiu       $s0, $s0, 0x13C
        ctx->r16 = ADD32(ctx->r16, 0X13C);
            goto L_800534F8;
    }
    // 0x80053514: addiu       $s0, $s0, 0x13C
    ctx->r16 = ADD32(ctx->r16, 0X13C);
    // 0x80053518: lui         $a2, 0xFCFF
    ctx->r6 = S32(0XFCFF << 16);
    // 0x8005351C: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80053520: lui         $a1, 0xFFFC
    ctx->r5 = S32(0XFFFC << 16);
    // 0x80053524: ori         $a1, $a1, 0xF279
    ctx->r5 = ctx->r5 | 0XF279;
    // 0x80053528: lui         $a3, 0xB900
    ctx->r7 = S32(0XB900 << 16);
    // 0x8005352C: ori         $a3, $a3, 0x31D
    ctx->r7 = ctx->r7 | 0X31D;
    // 0x80053530: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80053534: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80053538: lui         $a0, 0xF0A
    ctx->r4 = S32(0XF0A << 16);
    // 0x8005353C: ori         $a0, $a0, 0x7008
    ctx->r4 = ctx->r4 | 0X7008;
    // 0x80053540: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80053544: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053548: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8005354C: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80053550: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x80053554: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x80053558: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005355C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80053560: sw          $a3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r7;
    // 0x80053564: sw          $a0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r4;
L_80053568:
    // 0x80053568: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8005356C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80053570: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80053574: jr          $ra
    // 0x80053578: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80053578: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8005357C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005357C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80053580: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80053584: addiu       $v1, $v1, -0x42A0
    ctx->r3 = ADD32(ctx->r3, -0X42A0);
L_80053588:
    // 0x80053588: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8005358C: beq         $v0, $zero, L_800535A4
    if (ctx->r2 == 0) {
        // 0x80053590: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_800535A4;
    }
    // 0x80053590: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80053594: bne         $a0, $zero, L_80053588
    if (ctx->r4 != 0) {
        // 0x80053598: addiu       $v1, $v1, 0x13C
        ctx->r3 = ADD32(ctx->r3, 0X13C);
            goto L_80053588;
    }
    // 0x80053598: addiu       $v1, $v1, 0x13C
    ctx->r3 = ADD32(ctx->r3, 0X13C);
    // 0x8005359C: j           L_800535A8
    // 0x800535A0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800535A8;
    // 0x800535A0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800535A4:
    // 0x800535A4: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_800535A8:
    // 0x800535A8: jr          $ra
    // 0x800535AC: nop

    return;
    // 0x800535AC: nop

;}
RECOMP_FUNC void func_800535B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800535B0: addiu       $v0, $zero, 0x880
    ctx->r2 = ADD32(0, 0X880);
    // 0x800535B4: sw          $v0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r2;
    // 0x800535B8: addiu       $v0, $zero, 0x1100
    ctx->r2 = ADD32(0, 0X1100);
    // 0x800535BC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800535C0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800535C4: sw          $zero, 0x68($a0)
    MEM_W(0X68, ctx->r4) = 0;
    // 0x800535C8: sw          $zero, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = 0;
    // 0x800535CC: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // 0x800535D0: sw          $v0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r2;
    // 0x800535D4: jr          $ra
    // 0x800535D8: sw          $zero, 0x44($a0)
    MEM_W(0X44, ctx->r4) = 0;
    return;
    // 0x800535D8: sw          $zero, 0x44($a0)
    MEM_W(0X44, ctx->r4) = 0;
;}
RECOMP_FUNC void func_800535DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800535DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800535E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800535E4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800535E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800535EC: lb          $v1, 0x4($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X4);
    // 0x800535F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800535F4: beq         $v1, $a0, L_80053640
    if (ctx->r3 == ctx->r4) {
        // 0x800535F8: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_80053640;
    }
    // 0x800535F8: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x800535FC: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80053600: beql        $v0, $zero, L_80053618
    if (ctx->r2 == 0) {
        // 0x80053604: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80053618;
    }
    goto skip_0;
    // 0x80053604: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x80053608: beq         $v1, $zero, L_80053630
    if (ctx->r3 == 0) {
        // 0x8005360C: nop
    
            goto L_80053630;
    }
    // 0x8005360C: nop

    // 0x80053610: j           L_800536D4
    // 0x80053614: nop

        goto L_800536D4;
    // 0x80053614: nop

L_80053618:
    // 0x80053618: beq         $v1, $v0, L_80053650
    if (ctx->r3 == ctx->r2) {
        // 0x8005361C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80053650;
    }
    // 0x8005361C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80053620: beq         $v1, $v0, L_800536CC
    if (ctx->r3 == ctx->r2) {
        // 0x80053624: nop
    
            goto L_800536CC;
    }
    // 0x80053624: nop

    // 0x80053628: j           L_800536D4
    // 0x8005362C: nop

        goto L_800536D4;
    // 0x8005362C: nop

L_80053630:
    // 0x80053630: jal         0x800536E4
    // 0x80053634: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800536E4(rdram, ctx);
        goto after_0;
    // 0x80053634: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80053638: j           L_800536D4
    // 0x8005363C: nop

        goto L_800536D4;
    // 0x8005363C: nop

L_80053640:
    // 0x80053640: jal         0x80053774
    // 0x80053644: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80053774(rdram, ctx);
        goto after_1;
    // 0x80053644: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80053648: j           L_800536D4
    // 0x8005364C: nop

        goto L_800536D4;
    // 0x8005364C: nop

L_80053650:
    // 0x80053650: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80053654: lbu         $v1, 0x2074($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2074);
    // 0x80053658: lh          $v0, 0x66($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X66);
    // 0x8005365C: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80053660: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80053664: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80053668: beq         $v1, $zero, L_800536A0
    if (ctx->r3 == 0) {
        // 0x8005366C: nop
    
            goto L_800536A0;
    }
    // 0x8005366C: nop

    // 0x80053670: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x80053674: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80053678: beq         $v0, $zero, L_8005368C
    if (ctx->r2 == 0) {
        // 0x8005367C: sw          $v0, 0x54($s0)
        MEM_W(0X54, ctx->r16) = ctx->r2;
            goto L_8005368C;
    }
    // 0x8005367C: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x80053680: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x80053684: bne         $v0, $a0, L_800536CC
    if (ctx->r2 != ctx->r4) {
        // 0x80053688: nop
    
            goto L_800536CC;
    }
    // 0x80053688: nop

L_8005368C:
    // 0x8005368C: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x80053690: sw          $a0, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r4;
    // 0x80053694: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80053698: j           L_800536CC
    // 0x8005369C: sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
        goto L_800536CC;
    // 0x8005369C: sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
L_800536A0:
    // 0x800536A0: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
    // 0x800536A4: bne         $v1, $a0, L_800536B4
    if (ctx->r3 != ctx->r4) {
        // 0x800536A8: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_800536B4;
    }
    // 0x800536A8: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800536AC: sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // 0x800536B0: sw          $v1, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r3;
L_800536B4:
    // 0x800536B4: jal         0x80053CC0
    // 0x800536B8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80053CC0(rdram, ctx);
        goto after_2;
    // 0x800536B8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800536BC: jal         0x80054128
    // 0x800536C0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80054128(rdram, ctx);
        goto after_3;
    // 0x800536C0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x800536C4: j           L_800536D4
    // 0x800536C8: nop

        goto L_800536D4;
    // 0x800536C8: nop

L_800536CC:
    // 0x800536CC: jal         0x80053CC0
    // 0x800536D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80053CC0(rdram, ctx);
        goto after_4;
    // 0x800536D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
L_800536D4:
    // 0x800536D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800536D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800536DC: jr          $ra
    // 0x800536E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800536E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800536E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800536E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800536E8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800536EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800536F0: jal         0x80053754
    // 0x800536F4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_80053754(rdram, ctx);
        goto after_0;
    // 0x800536F4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x800536F8: lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4);
    // 0x800536FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80053700: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x80053704: addiu       $v0, $zero, 0x110
    ctx->r2 = ADD32(0, 0X110);
    // 0x80053708: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x8005370C: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x80053710: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x80053714: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80053718: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
    // 0x8005371C: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x80053720: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80053724: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80053728: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x8005372C: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    // 0x80053730: sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
    // 0x80053734: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x80053738: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
    // 0x8005373C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80053740: sb          $v1, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r3;
    // 0x80053744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053748: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005374C: jr          $ra
    // 0x80053750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80053750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80053754(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053754: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // 0x80053758: addiu       $a0, $a0, 0xC8
    ctx->r4 = ADD32(ctx->r4, 0XC8);
L_8005375C:
    // 0x8005375C: sw          $zero, 0x70($a0)
    MEM_W(0X70, ctx->r4) = 0;
    // 0x80053760: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80053764: bgez        $v0, L_8005375C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80053768: addiu       $a0, $a0, -0x4
        ctx->r4 = ADD32(ctx->r4, -0X4);
            goto L_8005375C;
    }
    // 0x80053768: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x8005376C: jr          $ra
    // 0x80053770: nop

    return;
    // 0x80053770: nop

;}
RECOMP_FUNC void func_80053774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80053778: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8005377C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80053780: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80053784: lb          $v1, 0x5($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X5);
    // 0x80053788: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005378C: beq         $v1, $v0, L_800537D8
    if (ctx->r3 == ctx->r2) {
        // 0x80053790: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800537D8;
    }
    // 0x80053790: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80053794: beq         $v0, $zero, L_800537E0
    if (ctx->r2 == 0) {
        // 0x80053798: nop
    
            goto L_800537E0;
    }
    // 0x80053798: nop

    // 0x8005379C: bne         $v1, $zero, L_800537E0
    if (ctx->r3 != 0) {
        // 0x800537A0: nop
    
            goto L_800537E0;
    }
    // 0x800537A0: nop

    // 0x800537A4: jal         0x800537F0
    // 0x800537A8: nop

    func_800537F0(rdram, ctx);
        goto after_0;
    // 0x800537A8: nop

    after_0:
    // 0x800537AC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800537B0: bne         $v0, $v1, L_800537C8
    if (ctx->r2 != ctx->r3) {
        // 0x800537B4: addiu       $v1, $zero, 0x5A
        ctx->r3 = ADD32(0, 0X5A);
            goto L_800537C8;
    }
    // 0x800537B4: addiu       $v1, $zero, 0x5A
    ctx->r3 = ADD32(0, 0X5A);
    // 0x800537B8: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x800537BC: sw          $v1, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r3;
    // 0x800537C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800537C4: sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
L_800537C8:
    // 0x800537C8: jal         0x80053CC0
    // 0x800537CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80053CC0(rdram, ctx);
        goto after_1;
    // 0x800537CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800537D0: j           L_800537E0
    // 0x800537D4: nop

        goto L_800537E0;
    // 0x800537D4: nop

L_800537D8:
    // 0x800537D8: jal         0x80053B10
    // 0x800537DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80053B10(rdram, ctx);
        goto after_2;
    // 0x800537DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
L_800537E0:
    // 0x800537E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800537E4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800537E8: jr          $ra
    // 0x800537EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800537EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800537F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800537F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800537F4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800537F8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800537FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80053800: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80053804: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80053808: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8005380C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80053810: lw          $v1, 0x68($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X68);
    // 0x80053814: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80053818: bne         $v1, $v0, L_80053824
    if (ctx->r3 != ctx->r2) {
        // 0x8005381C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80053824;
    }
    // 0x8005381C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80053820: sw          $v1, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r3;
L_80053824:
    // 0x80053824: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x80053828: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8005382C: blez        $v0, L_8005383C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80053830: sw          $v0, 0x54($s0)
        MEM_W(0X54, ctx->r16) = ctx->r2;
            goto L_8005383C;
    }
    // 0x80053830: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x80053834: j           L_80053AF0
    // 0x80053838: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80053AF0;
    // 0x80053838: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005383C:
    // 0x8005383C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80053840: lui         $s4, 0x8000
    ctx->r20 = S32(0X8000 << 16);
    // 0x80053844: addiu       $s3, $zero, 0x1E
    ctx->r19 = ADD32(0, 0X1E);
L_80053848:
    // 0x80053848: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x8005384C: lw          $t0, 0x5C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X5C);
    // 0x80053850: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x80053854: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x80053858: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x8005385C: sll         $a0, $t0, 7
    ctx->r4 = S32(ctx->r8 << 7);
    // 0x80053860: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80053864: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x80053868: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8005386C: lw          $v0, 0x38($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X38);
    // 0x80053870: lbu         $a3, 0x0($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X0);
    // 0x80053874: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80053878: addu        $a1, $v1, $v0
    ctx->r5 = ADD32(ctx->r3, ctx->r2);
    // 0x8005387C: sltiu       $v0, $a3, 0x10
    ctx->r2 = ctx->r7 < 0X10 ? 1 : 0;
    // 0x80053880: beq         $v0, $zero, L_80053A44
    if (ctx->r2 == 0) {
        // 0x80053884: sll         $v0, $a3, 2
        ctx->r2 = S32(ctx->r7 << 2);
            goto L_80053A44;
    }
    // 0x80053884: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x80053888: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005388C: addu        $at, $at, $v0
    gpr jr_addend_80053894 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80053890: lw          $v0, -0x1400($at)
    ctx->r2 = ADD32(ctx->r1, -0X1400);
    // 0x80053894: jr          $v0
    // 0x80053898: nop

    switch (jr_addend_80053894 >> 2) {
        case 0: goto L_8005389C; break;
        case 1: goto L_800538A8; break;
        case 2: goto L_800538C0; break;
        case 3: goto L_80053AE4; break;
        case 4: goto L_800538C8; break;
        case 5: goto L_800538FC; break;
        case 6: goto L_80053904; break;
        case 7: goto L_80053AE4; break;
        case 8: goto L_80053914; break;
        case 9: goto L_80053AE4; break;
        case 10: goto L_80053958; break;
        case 11: goto L_80053AE4; break;
        case 12: goto L_8005397C; break;
        case 13: goto L_80053994; break;
        case 14: goto L_800539A4; break;
        case 15: goto L_80053AE4; break;
        default: switch_error(__func__, 0x80053894, 0x800AEC00);
    }
    // 0x80053898: nop

L_8005389C:
    // 0x8005389C: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x800538A0: j           L_80053AE4
    // 0x800538A4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_80053AE4;
    // 0x800538A4: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_800538A8:
    // 0x800538A8: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x800538AC: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800538B0: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // 0x800538B4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800538B8: j           L_80053AE4
    // 0x800538BC: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
        goto L_80053AE4;
    // 0x800538BC: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
L_800538C0:
    // 0x800538C0: j           L_80053AE4
    // 0x800538C4: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
        goto L_80053AE4;
    // 0x800538C4: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
L_800538C8:
    // 0x800538C8: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x800538CC: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x800538D0: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x800538D4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800538D8: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800538DC: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x800538E0: lw          $v0, 0x58($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X58);
    // 0x800538E4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800538E8: sb          $s2, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r18;
    // 0x800538EC: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x800538F0: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x800538F4: j           L_80053AE4
    // 0x800538F8: sw          $v1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r3;
        goto L_80053AE4;
    // 0x800538F8: sw          $v1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r3;
L_800538FC:
    // 0x800538FC: j           L_80053AE4
    // 0x80053900: sw          $s2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r18;
        goto L_80053AE4;
    // 0x80053900: sw          $s2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r18;
L_80053904:
    // 0x80053904: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x80053908: lw          $v1, 0x58($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X58);
    // 0x8005390C: j           L_80053AD8
    // 0x80053910: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
        goto L_80053AD8;
    // 0x80053910: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
L_80053914:
    // 0x80053914: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x80053918: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // 0x8005391C: lw          $a0, 0x5C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X5C);
    // 0x80053920: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80053924: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80053928: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8005392C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80053930: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x80053934: sw          $zero, 0x70($v1)
    MEM_W(0X70, ctx->r3) = 0;
L_80053938:
    // 0x80053938: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x8005393C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80053940: bgez        $a2, L_80053938
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80053944: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80053938;
    }
    // 0x80053944: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80053948: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x8005394C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80053950: j           L_80053AE4
    // 0x80053954: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
        goto L_80053AE4;
    // 0x80053954: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
L_80053958:
    // 0x80053958: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x8005395C: bne         $v0, $zero, L_80053970
    if (ctx->r2 != 0) {
        // 0x80053960: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80053970;
    }
    // 0x80053960: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80053964: sw          $s2, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r18;
    // 0x80053968: j           L_80053AE4
    // 0x8005396C: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
        goto L_80053AE4;
    // 0x8005396C: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
L_80053970:
    // 0x80053970: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x80053974: j           L_80053AE4
    // 0x80053978: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
        goto L_80053AE4;
    // 0x80053978: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
L_8005397C:
    // 0x8005397C: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80053980: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80053984: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // 0x80053988: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8005398C: j           L_80053AE4
    // 0x80053990: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
        goto L_80053AE4;
    // 0x80053990: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
L_80053994:
    // 0x80053994: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80053998: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8005399C: j           L_80053AE4
    // 0x800539A0: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
        goto L_80053AE4;
    // 0x800539A0: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
L_800539A4:
    // 0x800539A4: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x800539A8: lw          $a0, 0x60($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X60);
    // 0x800539AC: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800539B0: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800539B4: lbu         $a3, 0x0($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X0);
    // 0x800539B8: lw          $v1, 0x5C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X5C);
    // 0x800539BC: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x800539C0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800539C4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800539C8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800539CC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800539D0: sw          $s4, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r20;
    // 0x800539D4: lw          $v1, 0x60($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X60);
    // 0x800539D8: lw          $a0, 0x5C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X5C);
    // 0x800539DC: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x800539E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800539E4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800539E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800539EC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800539F0: lw          $v1, 0x70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X70);
    // 0x800539F4: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x800539F8: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x800539FC: sw          $v1, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r3;
    // 0x80053A00: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x80053A04: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80053A08: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80053A0C: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
    // 0x80053A10: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80053A14: lw          $v0, 0x5684($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5684);
    // 0x80053A18: lui         $v1, 0x6C
    ctx->r3 = S32(0X6C << 16);
    // 0x80053A1C: addiu       $v1, $v1, 0x43B0
    ctx->r3 = ADD32(ctx->r3, 0X43B0);
    // 0x80053A20: sll         $a0, $a3, 7
    ctx->r4 = S32(ctx->r7 << 7);
    // 0x80053A24: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x80053A28: jal         0x80006D98
    // 0x80053A2C: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    func_80006D98(rdram, ctx);
        goto after_0;
    // 0x80053A2C: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_0:
    // 0x80053A30: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80053A34: beql        $v0, $s2, L_80053AE4
    if (ctx->r2 == ctx->r18) {
        // 0x80053A38: sw          $s3, 0x54($s0)
        MEM_W(0X54, ctx->r16) = ctx->r19;
            goto L_80053AE4;
    }
    goto skip_0;
    // 0x80053A38: sw          $s3, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r19;
    skip_0:
    // 0x80053A3C: j           L_80053AD0
    // 0x80053A40: nop

        goto L_80053AD0;
    // 0x80053A40: nop

L_80053A44:
    // 0x80053A44: sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6 << 4);
    // 0x80053A48: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80053A4C: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80053A50: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80053A54: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80053A58: sw          $s4, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r20;
    // 0x80053A5C: lw          $v1, 0x60($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X60);
    // 0x80053A60: lw          $a0, 0x5C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X5C);
    // 0x80053A64: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80053A68: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80053A6C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80053A70: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80053A74: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80053A78: lw          $v1, 0x70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X70);
    // 0x80053A7C: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x80053A80: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x80053A84: sw          $v1, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r3;
    // 0x80053A88: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x80053A8C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80053A90: lui         $v1, 0x6C
    ctx->r3 = S32(0X6C << 16);
    // 0x80053A94: addiu       $v1, $v1, 0x43B0
    ctx->r3 = ADD32(ctx->r3, 0X43B0);
    // 0x80053A98: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80053A9C: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
    // 0x80053AA0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80053AA4: lw          $v0, 0x5680($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5680);
    // 0x80053AA8: addiu       $a0, $a3, -0x10
    ctx->r4 = ADD32(ctx->r7, -0X10);
    // 0x80053AAC: sll         $a0, $a0, 7
    ctx->r4 = S32(ctx->r4 << 7);
    // 0x80053AB0: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x80053AB4: jal         0x80006D98
    // 0x80053AB8: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    func_80006D98(rdram, ctx);
        goto after_1;
    // 0x80053AB8: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_1:
    // 0x80053ABC: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80053AC0: bne         $v0, $s2, L_80053AD0
    if (ctx->r2 != ctx->r18) {
        // 0x80053AC4: nop
    
            goto L_80053AD0;
    }
    // 0x80053AC4: nop

    // 0x80053AC8: j           L_80053AE4
    // 0x80053ACC: sw          $s3, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r19;
        goto L_80053AE4;
    // 0x80053ACC: sw          $s3, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r19;
L_80053AD0:
    // 0x80053AD0: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x80053AD4: lw          $v1, 0x58($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X58);
L_80053AD8:
    // 0x80053AD8: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80053ADC: sltu        $s1, $zero, $v0
    ctx->r17 = 0 < ctx->r2 ? 1 : 0;
    // 0x80053AE0: sw          $v1, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r3;
L_80053AE4:
    // 0x80053AE4: beq         $s1, $zero, L_80053848
    if (ctx->r17 == 0) {
        // 0x80053AE8: addu        $v0, $s1, $zero
        ctx->r2 = ADD32(ctx->r17, 0);
            goto L_80053848;
    }
    // 0x80053AE8: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x80053AEC: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
L_80053AF0:
    // 0x80053AF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80053AF4: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80053AF8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80053AFC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80053B00: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80053B04: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80053B08: jr          $ra
    // 0x80053B0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80053B0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80053B10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053B10: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80053B14: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80053B18: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80053B1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80053B20: lb          $v1, 0x6($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X6);
    // 0x80053B24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80053B28: beq         $v1, $a0, L_80053BFC
    if (ctx->r3 == ctx->r4) {
        // 0x80053B2C: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_80053BFC;
    }
    // 0x80053B2C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x80053B30: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80053B34: beql        $v0, $zero, L_80053B4C
    if (ctx->r2 == 0) {
        // 0x80053B38: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80053B4C;
    }
    goto skip_0;
    // 0x80053B38: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x80053B3C: beq         $v1, $zero, L_80053B5C
    if (ctx->r3 == 0) {
        // 0x80053B40: nop
    
            goto L_80053B5C;
    }
    // 0x80053B40: nop

    // 0x80053B44: j           L_80053CB0
    // 0x80053B48: nop

        goto L_80053CB0;
    // 0x80053B48: nop

L_80053B4C:
    // 0x80053B4C: beq         $v1, $v0, L_80053C28
    if (ctx->r3 == ctx->r2) {
        // 0x80053B50: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_80053C28;
    }
    // 0x80053B50: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80053B54: j           L_80053CB0
    // 0x80053B58: nop

        goto L_80053CB0;
    // 0x80053B58: nop

L_80053B5C:
    // 0x80053B5C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80053B60: lbu         $v1, 0x2074($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2074);
    // 0x80053B64: lh          $v0, 0x66($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X66);
    // 0x80053B68: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80053B6C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80053B70: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80053B74: beq         $v1, $zero, L_80053BC8
    if (ctx->r3 == 0) {
        // 0x80053B78: nop
    
            goto L_80053BC8;
    }
    // 0x80053B78: nop

    // 0x80053B7C: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x80053B80: bne         $v0, $a0, L_80053B94
    if (ctx->r2 != ctx->r4) {
        // 0x80053B84: nop
    
            goto L_80053B94;
    }
    // 0x80053B84: nop

    // 0x80053B88: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80053B8C: j           L_80053B9C
    // 0x80053B90: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
        goto L_80053B9C;
    // 0x80053B90: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
L_80053B94:
    // 0x80053B94: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80053B98: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80053B9C:
    // 0x80053B9C: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x80053BA0: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80053BA4: bgtz        $v0, L_80053CA8
    if (SIGNED(ctx->r2) > 0) {
        // 0x80053BA8: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80053CA8;
    }
    // 0x80053BA8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80053BAC: lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6);
    // 0x80053BB0: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x80053BB4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80053BB8: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80053BBC: sb          $v0, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r2;
    // 0x80053BC0: j           L_80053CA8
    // 0x80053BC4: sw          $v1, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r3;
        goto L_80053CA8;
    // 0x80053BC4: sw          $v1, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r3;
L_80053BC8:
    // 0x80053BC8: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x80053BCC: bne         $v0, $a0, L_80053BE4
    if (ctx->r2 != ctx->r4) {
        // 0x80053BD0: addiu       $v1, $a1, 0x1
        ctx->r3 = ADD32(ctx->r5, 0X1);
            goto L_80053BE4;
    }
    // 0x80053BD0: addiu       $v1, $a1, 0x1
    ctx->r3 = ADD32(ctx->r5, 0X1);
    // 0x80053BD4: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x80053BD8: sb          $v1, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r3;
    // 0x80053BDC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80053BE0: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
L_80053BE4:
    // 0x80053BE4: jal         0x80053CC0
    // 0x80053BE8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80053CC0(rdram, ctx);
        goto after_0;
    // 0x80053BE8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80053BEC: jal         0x80054128
    // 0x80053BF0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80054128(rdram, ctx);
        goto after_1;
    // 0x80053BF0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80053BF4: j           L_80053CB0
    // 0x80053BF8: nop

        goto L_80053CB0;
    // 0x80053BF8: nop

L_80053BFC:
    // 0x80053BFC: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80053C00: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x80053C04: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x80053C08: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x80053C0C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80053C10: bne         $v0, $zero, L_80053CA8
    if (ctx->r2 != 0) {
        // 0x80053C14: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80053CA8;
    }
    // 0x80053C14: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80053C18: lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6);
    // 0x80053C1C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80053C20: j           L_80053CA8
    // 0x80053C24: sb          $v0, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r2;
        goto L_80053CA8;
    // 0x80053C24: sb          $v0, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r2;
L_80053C28:
    // 0x80053C28: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x80053C2C: blez        $v0, L_80053C98
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80053C30: sw          $zero, 0x28($s0)
        MEM_W(0X28, ctx->r16) = 0;
            goto L_80053C98;
    }
    // 0x80053C30: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
L_80053C34:
    // 0x80053C34: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80053C38: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80053C3C:
    // 0x80053C3C: lw          $v0, 0xB4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB4);
    // 0x80053C40: lw          $v1, 0xF8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XF8);
    // 0x80053C44: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80053C48: sw          $zero, 0xF8($a0)
    MEM_W(0XF8, ctx->r4) = 0;
    // 0x80053C4C: sw          $v0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r2;
    // 0x80053C50: sw          $v1, 0xB4($a0)
    MEM_W(0XB4, ctx->r4) = ctx->r3;
    // 0x80053C54: slti        $v0, $a1, 0x11
    ctx->r2 = SIGNED(ctx->r5) < 0X11 ? 1 : 0;
    // 0x80053C58: bne         $v0, $zero, L_80053C3C
    if (ctx->r2 != 0) {
        // 0x80053C5C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80053C3C;
    }
    // 0x80053C5C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80053C60: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80053C64: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80053C68: lw          $a1, 0x40($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X40);
    // 0x80053C6C: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x80053C70: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x80053C74: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80053C78: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    // 0x80053C7C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80053C80: slt         $v1, $a3, $v1
    ctx->r3 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80053C84: sw          $a0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r4;
    // 0x80053C88: sw          $a1, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r5;
    // 0x80053C8C: sw          $a2, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r6;
    // 0x80053C90: bne         $v1, $zero, L_80053C34
    if (ctx->r3 != 0) {
        // 0x80053C94: sw          $v0, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->r2;
            goto L_80053C34;
    }
    // 0x80053C94: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
L_80053C98:
    // 0x80053C98: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80053C9C: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
    // 0x80053CA0: sb          $zero, 0x6($a0)
    MEM_B(0X6, ctx->r4) = 0;
    // 0x80053CA4: sw          $zero, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = 0;
L_80053CA8:
    // 0x80053CA8: jal         0x80053CC0
    // 0x80053CAC: nop

    func_80053CC0(rdram, ctx);
        goto after_2;
    // 0x80053CAC: nop

    after_2:
L_80053CB0:
    // 0x80053CB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80053CB4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80053CB8: jr          $ra
    // 0x80053CBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80053CBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80053CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053CC0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80053CC4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80053CC8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80053CCC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80053CD0: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x80053CD4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80053CD8: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80053CDC: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80053CE0: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80053CE4: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80053CE8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80053CEC: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80053CF0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80053CF4: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x80053CF8: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80053CFC: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x80053D00: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x80053D04: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x80053D08: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x80053D0C: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x80053D10: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // 0x80053D14: addu        $s5, $s1, $zero
    ctx->r21 = ADD32(ctx->r17, 0);
    // 0x80053D18: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x80053D1C: lw          $a0, 0x24($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24);
    // 0x80053D20: addu        $t1, $a1, $v0
    ctx->r9 = ADD32(ctx->r5, ctx->r2);
    // 0x80053D24: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x80053D28: addu        $fp, $a2, $v1
    ctx->r30 = ADD32(ctx->r6, ctx->r3);
    // 0x80053D2C: addu        $a0, $fp, $a0
    ctx->r4 = ADD32(ctx->r30, ctx->r4);
    // 0x80053D30: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80053D34: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80053D38: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
L_80053D3C:
    // 0x80053D3C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80053D40: sll         $s7, $s4, 4
    ctx->r23 = S32(ctx->r20 << 4);
    // 0x80053D44: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
L_80053D48:
    // 0x80053D48: andi        $v0, $s0, 0x3
    ctx->r2 = ctx->r16 & 0X3;
    // 0x80053D4C: bne         $v0, $zero, L_80053E28
    if (ctx->r2 != 0) {
        // 0x80053D50: addu        $v0, $s6, $s0
        ctx->r2 = ADD32(ctx->r22, ctx->r16);
            goto L_80053E28;
    }
    // 0x80053D50: addu        $v0, $s6, $s0
    ctx->r2 = ADD32(ctx->r22, ctx->r16);
    // 0x80053D54: lui         $a2, 0x70F
    ctx->r6 = S32(0X70F << 16);
    // 0x80053D58: ori         $a2, $a2, 0xF800
    ctx->r6 = ctx->r6 | 0XF800;
    // 0x80053D5C: lui         $a3, 0xF540
    ctx->r7 = S32(0XF540 << 16);
    // 0x80053D60: ori         $a3, $a3, 0x200
    ctx->r7 = ctx->r7 | 0X200;
    // 0x80053D64: lui         $t0, 0x3
    ctx->r8 = S32(0X3 << 16);
    // 0x80053D68: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    // 0x80053D6C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80053D70: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80053D74: lw          $a1, 0x38($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X38);
    // 0x80053D78: ori         $t0, $t0, 0xC0FC
    ctx->r8 = ctx->r8 | 0XC0FC;
    // 0x80053D7C: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80053D80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053D84: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80053D88: lui         $v0, 0xFD50
    ctx->r2 = S32(0XFD50 << 16);
    // 0x80053D8C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80053D90: sll         $v0, $s0, 7
    ctx->r2 = S32(ctx->r16 << 7);
    // 0x80053D94: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80053D98: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x80053D9C: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80053DA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053DA4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80053DA8: lui         $v0, 0xF550
    ctx->r2 = S32(0XF550 << 16);
    // 0x80053DAC: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x80053DB0: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x80053DB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053DB8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80053DBC: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x80053DC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053DC4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80053DC8: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x80053DCC: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x80053DD0: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x80053DD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053DD8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80053DDC: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x80053DE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053DE4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80053DE8: addiu       $v0, $v1, 0x38
    ctx->r2 = ADD32(ctx->r3, 0X38);
    // 0x80053DEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053DF0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80053DF4: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x80053DF8: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x80053DFC: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
    // 0x80053E00: sw          $t3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r11;
    // 0x80053E04: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x80053E08: sw          $a2, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r6;
    // 0x80053E0C: sw          $t2, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r10;
    // 0x80053E10: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x80053E14: sw          $a3, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r7;
    // 0x80053E18: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x80053E1C: sw          $v0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r2;
    // 0x80053E20: sw          $t0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r8;
    // 0x80053E24: addu        $v0, $s6, $s0
    ctx->r2 = ADD32(ctx->r22, ctx->r16);
L_80053E28:
    // 0x80053E28: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80053E2C: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80053E30: lw          $v0, 0x70($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X70);
    // 0x80053E34: bgezl       $v0, L_80053F8C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80053E38: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80053F8C;
    }
    goto skip_0;
    // 0x80053E38: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80053E3C: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x80053E40: beq         $s3, $v0, L_80053EF4
    if (ctx->r19 == ctx->r2) {
        // 0x80053E44: lui         $a1, 0xF500
        ctx->r5 = S32(0XF500 << 16);
            goto L_80053EF4;
    }
    // 0x80053E44: lui         $a1, 0xF500
    ctx->r5 = S32(0XF500 << 16);
    // 0x80053E48: ori         $a1, $a1, 0x100
    ctx->r5 = ctx->r5 | 0X100;
    // 0x80053E4C: lui         $a2, 0x703
    ctx->r6 = S32(0X703 << 16);
    // 0x80053E50: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80053E54: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x80053E58: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x80053E5C: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80053E60: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80053E64: addiu       $v1, $v1, 0x5440
    ctx->r3 = ADD32(ctx->r3, 0X5440);
    // 0x80053E68: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80053E6C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053E70: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80053E74: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x80053E78: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80053E7C: sll         $v0, $s3, 5
    ctx->r2 = S32(ctx->r19 << 5);
    // 0x80053E80: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80053E84: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x80053E88: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x80053E8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053E90: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80053E94: lui         $v0, 0xE800
    ctx->r2 = S32(0XE800 << 16);
    // 0x80053E98: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x80053E9C: addiu       $v0, $a0, 0x18
    ctx->r2 = ADD32(ctx->r4, 0X18);
    // 0x80053EA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053EA4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80053EA8: addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
    // 0x80053EAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053EB0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80053EB4: addiu       $v0, $a0, 0x28
    ctx->r2 = ADD32(ctx->r4, 0X28);
    // 0x80053EB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053EBC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80053EC0: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x80053EC4: sw          $v0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r2;
    // 0x80053EC8: addiu       $v0, $a0, 0x30
    ctx->r2 = ADD32(ctx->r4, 0X30);
    // 0x80053ECC: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80053ED0: sw          $a1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r5;
    // 0x80053ED4: sw          $t4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r12;
    // 0x80053ED8: sw          $t3, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r11;
    // 0x80053EDC: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x80053EE0: sw          $a2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r6;
    // 0x80053EE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80053EE8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80053EEC: sw          $t2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r10;
    // 0x80053EF0: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
L_80053EF4:
    // 0x80053EF4: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x80053EF8: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80053EFC: lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X28);
    // 0x80053F00: addu        $a1, $a1, $s2
    ctx->r5 = ADD32(ctx->r5, ctx->r18);
    // 0x80053F04: addu        $a2, $a2, $s7
    ctx->r6 = ADD32(ctx->r6, ctx->r23);
    // 0x80053F08: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x80053F0C: addiu       $v1, $a1, 0x10
    ctx->r3 = ADD32(ctx->r5, 0X10);
    // 0x80053F10: sltiu       $v1, $v1, 0x150
    ctx->r3 = ctx->r3 < 0X150 ? 1 : 0;
    // 0x80053F14: addiu       $v0, $a2, 0x10
    ctx->r2 = ADD32(ctx->r6, 0X10);
    // 0x80053F18: sltiu       $v0, $v0, 0x100
    ctx->r2 = ctx->r2 < 0X100 ? 1 : 0;
    // 0x80053F1C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80053F20: beq         $v1, $zero, L_80053F88
    if (ctx->r3 == 0) {
        // 0x80053F24: addiu       $a0, $t1, -0x10
        ctx->r4 = ADD32(ctx->r9, -0X10);
            goto L_80053F88;
    }
    // 0x80053F24: addiu       $a0, $t1, -0x10
    ctx->r4 = ADD32(ctx->r9, -0X10);
    // 0x80053F28: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x80053F2C: slt         $a0, $a1, $a0
    ctx->r4 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80053F30: xori        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 ^ 0X1;
    // 0x80053F34: slt         $v0, $a1, $t5
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80053F38: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // 0x80053F3C: addiu       $v0, $fp, -0x10
    ctx->r2 = ADD32(ctx->r30, -0X10);
    // 0x80053F40: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80053F44: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80053F48: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80053F4C: slt         $v1, $a2, $t5
    ctx->r3 = SIGNED(ctx->r6) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80053F50: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80053F54: and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // 0x80053F58: beq         $a0, $zero, L_80053F88
    if (ctx->r4 == 0) {
        // 0x80053F5C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80053F88;
    }
    // 0x80053F5C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80053F60: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x80053F64: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80053F68: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80053F6C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80053F70: jal         0x80053FDC
    // 0x80053F74: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    func_80053FDC(rdram, ctx);
        goto after_0;
    // 0x80053F74: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    after_0:
    // 0x80053F78: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80053F7C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80053F80: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80053F84: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
L_80053F88:
    // 0x80053F88: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80053F8C:
    // 0x80053F8C: slti        $v0, $s0, 0x11
    ctx->r2 = SIGNED(ctx->r16) < 0X11 ? 1 : 0;
    // 0x80053F90: bne         $v0, $zero, L_80053D48
    if (ctx->r2 != 0) {
        // 0x80053F94: addiu       $s2, $s2, 0xB
        ctx->r18 = ADD32(ctx->r18, 0XB);
            goto L_80053D48;
    }
    // 0x80053F94: addiu       $s2, $s2, 0xB
    ctx->r18 = ADD32(ctx->r18, 0XB);
    // 0x80053F98: addiu       $s6, $s6, 0x11
    ctx->r22 = ADD32(ctx->r22, 0X11);
    // 0x80053F9C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80053FA0: slti        $v0, $s4, 0x3
    ctx->r2 = SIGNED(ctx->r20) < 0X3 ? 1 : 0;
    // 0x80053FA4: bne         $v0, $zero, L_80053D3C
    if (ctx->r2 != 0) {
        // 0x80053FA8: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_80053D3C;
    }
    // 0x80053FA8: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80053FAC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80053FB0: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80053FB4: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80053FB8: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80053FBC: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80053FC0: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80053FC4: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80053FC8: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80053FCC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80053FD0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80053FD4: jr          $ra
    // 0x80053FD8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80053FD8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
