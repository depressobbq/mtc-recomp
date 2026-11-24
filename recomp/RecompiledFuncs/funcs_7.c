#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80020954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020954: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80020958: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8002095C: lw          $t1, 0x110($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X110);
    // 0x80020960: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80020964:
    // 0x80020964: addu        $v1, $a3, $t1
    ctx->r3 = ADD32(ctx->r7, ctx->r9);
    // 0x80020968: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
L_8002096C:
    // 0x8002096C: lbu         $v0, 0x6F($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X6F);
    // 0x80020970: beq         $v0, $zero, L_80020990
    if (ctx->r2 == 0) {
        // 0x80020974: nop
    
            goto L_80020990;
    }
    // 0x80020974: nop

    // 0x80020978: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x8002097C: bnel        $v0, $zero, L_800209A0
    if (ctx->r2 != 0) {
        // 0x80020980: addiu       $v1, $a2, 0x144
        ctx->r3 = ADD32(ctx->r6, 0X144);
            goto L_800209A0;
    }
    goto skip_0;
    // 0x80020980: addiu       $v1, $a2, 0x144
    ctx->r3 = ADD32(ctx->r6, 0X144);
    skip_0:
    // 0x80020984: lbu         $v0, 0x71($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X71);
    // 0x80020988: bne         $v0, $zero, L_800209B8
    if (ctx->r2 != 0) {
        // 0x8002098C: addiu       $v0, $zero, 0x12
        ctx->r2 = ADD32(0, 0X12);
            goto L_800209B8;
    }
    // 0x8002098C: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80020990:
    // 0x80020990: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x80020994: beq         $v0, $zero, L_800209A8
    if (ctx->r2 == 0) {
        // 0x80020998: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800209A8;
    }
    // 0x80020998: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002099C: addiu       $v1, $a2, 0x144
    ctx->r3 = ADD32(ctx->r6, 0X144);
L_800209A0:
    // 0x800209A0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x800209A4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800209A8:
    // 0x800209A8: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x800209AC: bne         $v0, $zero, L_8002096C
    if (ctx->r2 != 0) {
        // 0x800209B0: addiu       $v1, $v1, 0x12
        ctx->r3 = ADD32(ctx->r3, 0X12);
            goto L_8002096C;
    }
    // 0x800209B0: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x800209B4: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_800209B8:
    // 0x800209B8: beql        $a1, $v0, L_80020A24
    if (ctx->r5 == ctx->r2) {
        // 0x800209BC: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80020A24;
    }
    goto skip_1;
    // 0x800209BC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_1:
    // 0x800209C0: lw          $v0, 0x110($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X110);
    // 0x800209C4: sll         $v1, $a1, 3
    ctx->r3 = S32(ctx->r5 << 3);
    // 0x800209C8: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800209CC: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800209D0: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x800209D4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800209D8: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x800209DC: lbu         $v0, 0x6F($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X6F);
    // 0x800209E0: j           L_80020A04
    // 0x800209E4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
        goto L_80020A04;
    // 0x800209E4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_800209E8:
    // 0x800209E8: lbu         $v0, 0x71($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X71);
    // 0x800209EC: beq         $v0, $zero, L_80020A18
    if (ctx->r2 == 0) {
        // 0x800209F0: slt         $v0, $t0, $a2
        ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80020A18;
    }
    // 0x800209F0: slt         $v0, $t0, $a2
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800209F4: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x800209F8: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x800209FC: lbu         $v0, 0x6F($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X6F);
    // 0x80020A00: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80020A04:
    // 0x80020A04: beq         $v0, $zero, L_80020A18
    if (ctx->r2 == 0) {
        // 0x80020A08: slt         $v0, $t0, $a2
        ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80020A18;
    }
    // 0x80020A08: slt         $v0, $t0, $a2
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80020A0C: lbu         $v0, 0x70($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X70);
    // 0x80020A10: beq         $v0, $zero, L_800209E8
    if (ctx->r2 == 0) {
        // 0x80020A14: slt         $v0, $t0, $a2
        ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800209E8;
    }
    // 0x80020A14: slt         $v0, $t0, $a2
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
L_80020A18:
    // 0x80020A18: bnel        $v0, $zero, L_80020A20
    if (ctx->r2 != 0) {
        // 0x80020A1C: addu        $t0, $a2, $zero
        ctx->r8 = ADD32(ctx->r6, 0);
            goto L_80020A20;
    }
    goto skip_2;
    // 0x80020A1C: addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    skip_2:
L_80020A20:
    // 0x80020A20: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_80020A24:
    // 0x80020A24: slti        $v0, $a3, 0xA
    ctx->r2 = SIGNED(ctx->r7) < 0XA ? 1 : 0;
    // 0x80020A28: bnel        $v0, $zero, L_80020964
    if (ctx->r2 != 0) {
        // 0x80020A2C: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80020964;
    }
    goto skip_3;
    // 0x80020A2C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    skip_3:
    // 0x80020A30: jr          $ra
    // 0x80020A34: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    return;
    // 0x80020A34: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
;}
RECOMP_FUNC void func_80020A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020A38: lw          $v0, 0x110($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X110);
    // 0x80020A3C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80020A40: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80020A44: addiu       $a3, $a1, 0xA
    ctx->r7 = ADD32(ctx->r5, 0XA);
L_80020A48:
    // 0x80020A48: lbu         $v0, 0x28($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X28);
    // 0x80020A4C: bne         $v0, $zero, L_80020A68
    if (ctx->r2 != 0) {
        // 0x80020A50: addiu       $a0, $zero, -0x4
        ctx->r4 = ADD32(0, -0X4);
            goto L_80020A68;
    }
    // 0x80020A50: addiu       $a0, $zero, -0x4
    ctx->r4 = ADD32(0, -0X4);
    // 0x80020A54: addiu       $v1, $a1, -0x48
    ctx->r3 = ADD32(ctx->r5, -0X48);
L_80020A58:
    // 0x80020A58: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80020A5C: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x80020A60: beq         $v0, $zero, L_80020A58
    if (ctx->r2 == 0) {
        // 0x80020A64: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80020A58;
    }
    // 0x80020A64: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80020A68:
    // 0x80020A68: slt         $v0, $a0, $a2
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80020A6C: bnel        $v0, $zero, L_80020A74
    if (ctx->r2 != 0) {
        // 0x80020A70: addu        $a2, $a0, $zero
        ctx->r6 = ADD32(ctx->r4, 0);
            goto L_80020A74;
    }
    goto skip_0;
    // 0x80020A70: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    skip_0:
L_80020A74:
    // 0x80020A74: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80020A78: slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80020A7C: bne         $v0, $zero, L_80020A48
    if (ctx->r2 != 0) {
        // 0x80020A80: nop
    
            goto L_80020A48;
    }
    // 0x80020A80: nop

    // 0x80020A84: jr          $ra
    // 0x80020A88: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    return;
    // 0x80020A88: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
;}
RECOMP_FUNC void func_80020A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020A8C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80020A90: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80020A94: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80020A98: addu        $a3, $sp, $zero
    ctx->r7 = ADD32(ctx->r29, 0);
L_80020A9C:
    // 0x80020A9C: lw          $v0, 0x110($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X110);
    // 0x80020AA0: addu        $v1, $a2, $v0
    ctx->r3 = ADD32(ctx->r6, ctx->r2);
    // 0x80020AA4: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x80020AA8: bne         $v0, $zero, L_80020AC0
    if (ctx->r2 != 0) {
        // 0x80020AAC: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80020AC0;
    }
    // 0x80020AAC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80020AB0:
    // 0x80020AB0: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80020AB4: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x80020AB8: beq         $v0, $zero, L_80020AB0
    if (ctx->r2 == 0) {
        // 0x80020ABC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80020AB0;
    }
    // 0x80020ABC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80020AC0:
    // 0x80020AC0: sb          $a1, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r5;
    // 0x80020AC4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80020AC8: slti        $v0, $a2, 0xA
    ctx->r2 = SIGNED(ctx->r6) < 0XA ? 1 : 0;
    // 0x80020ACC: bne         $v0, $zero, L_80020A9C
    if (ctx->r2 != 0) {
        // 0x80020AD0: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80020A9C;
    }
    // 0x80020AD0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80020AD4: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80020AD8: addiu       $a0, $sp, 0x9
    ctx->r4 = ADD32(ctx->r29, 0X9);
    // 0x80020ADC: addiu       $a1, $sp, 0x8
    ctx->r5 = ADD32(ctx->r29, 0X8);
L_80020AE0:
    // 0x80020AE0: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80020AE4: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80020AE8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80020AEC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80020AF0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80020AF4: sll         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2 << 24);
    // 0x80020AF8: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80020AFC: bltzl       $v1, L_80020B04
    if (SIGNED(ctx->r3) < 0) {
        // 0x80020B00: negu        $v1, $v1
        ctx->r3 = SUB32(0, ctx->r3);
            goto L_80020B04;
    }
    goto skip_0;
    // 0x80020B00: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    skip_0:
L_80020B04:
    // 0x80020B04: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x80020B08: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x80020B0C: bgtz        $a2, L_80020AE0
    if (SIGNED(ctx->r6) > 0) {
        // 0x80020B10: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_80020AE0;
    }
    // 0x80020B10: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80020B14: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    // 0x80020B18: jr          $ra
    // 0x80020B1C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80020B1C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80020B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020B20: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80020B24: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // 0x80020B28: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x80020B2C: lw          $t2, 0x110($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X110);
L_80020B30:
    // 0x80020B30: lbu         $v0, 0x70($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X70);
    // 0x80020B34: bne         $v0, $zero, L_80020B50
    if (ctx->r2 != 0) {
        // 0x80020B38: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80020B50;
    }
    // 0x80020B38: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80020B3C: addu        $v1, $t2, $zero
    ctx->r3 = ADD32(ctx->r10, 0);
L_80020B40:
    // 0x80020B40: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80020B44: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x80020B48: beq         $v0, $zero, L_80020B40
    if (ctx->r2 == 0) {
        // 0x80020B4C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80020B40;
    }
    // 0x80020B4C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80020B50:
    // 0x80020B50: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80020B54: slti        $v0, $a2, 0x12
    ctx->r2 = SIGNED(ctx->r6) < 0X12 ? 1 : 0;
    // 0x80020B58: beql        $v0, $zero, L_80020BC8
    if (ctx->r2 == 0) {
        // 0x80020B5C: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_80020BC8;
    }
    goto skip_0;
    // 0x80020B5C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    skip_0:
    // 0x80020B60: sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6 << 3);
    // 0x80020B64: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80020B68: sll         $a3, $v0, 1
    ctx->r7 = S32(ctx->r2 << 1);
L_80020B6C:
    // 0x80020B6C: beq         $a1, $zero, L_80020B90
    if (ctx->r5 == 0) {
        // 0x80020B70: nop
    
            goto L_80020B90;
    }
    // 0x80020B70: nop

    // 0x80020B74: lw          $v0, 0x110($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X110);
    // 0x80020B78: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80020B7C: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80020B80: lbu         $v0, 0x70($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X70);
    // 0x80020B84: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80020B88: j           L_80020BB4
    // 0x80020B8C: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
        goto L_80020BB4;
    // 0x80020B8C: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
L_80020B90:
    // 0x80020B90: lw          $v0, 0x110($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X110);
    // 0x80020B94: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80020B98: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80020B9C: lbu         $v1, 0x70($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X70);
    // 0x80020BA0: bnel        $v1, $zero, L_80020BB4
    if (ctx->r3 != 0) {
        // 0x80020BA4: addu        $t3, $v1, $zero
        ctx->r11 = ADD32(ctx->r3, 0);
            goto L_80020BB4;
    }
    goto skip_1;
    // 0x80020BA4: addu        $t3, $v1, $zero
    ctx->r11 = ADD32(ctx->r3, 0);
    skip_1:
    // 0x80020BA8: sltu        $v0, $zero, $t3
    ctx->r2 = 0 < ctx->r11 ? 1 : 0;
    // 0x80020BAC: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x80020BB0: addu        $t3, $v1, $zero
    ctx->r11 = ADD32(ctx->r3, 0);
L_80020BB4:
    // 0x80020BB4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80020BB8: slti        $v0, $a2, 0x12
    ctx->r2 = SIGNED(ctx->r6) < 0X12 ? 1 : 0;
    // 0x80020BBC: bne         $v0, $zero, L_80020B6C
    if (ctx->r2 != 0) {
        // 0x80020BC0: addiu       $a3, $a3, 0x12
        ctx->r7 = ADD32(ctx->r7, 0X12);
            goto L_80020B6C;
    }
    // 0x80020BC0: addiu       $a3, $a3, 0x12
    ctx->r7 = ADD32(ctx->r7, 0X12);
    // 0x80020BC4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_80020BC8:
    // 0x80020BC8: slti        $v0, $t1, 0xA
    ctx->r2 = SIGNED(ctx->r9) < 0XA ? 1 : 0;
    // 0x80020BCC: bne         $v0, $zero, L_80020B30
    if (ctx->r2 != 0) {
        // 0x80020BD0: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_80020B30;
    }
    // 0x80020BD0: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80020BD4: jr          $ra
    // 0x80020BD8: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    return;
    // 0x80020BD8: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
;}
RECOMP_FUNC void func_80020BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020BDC: addu        $t4, $zero, $zero
    ctx->r12 = ADD32(0, 0);
    // 0x80020BE0: addiu       $a2, $zero, 0x132
    ctx->r6 = ADD32(0, 0X132);
    // 0x80020BE4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80020BE8:
    // 0x80020BE8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80020BEC: lw          $a3, 0xB0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0XB0);
    // 0x80020BF0: addu        $v0, $a1, $a3
    ctx->r2 = ADD32(ctx->r5, ctx->r7);
L_80020BF4:
    // 0x80020BF4: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80020BF8: lbu         $v0, 0x70($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X70);
    // 0x80020BFC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80020C00: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80020C04: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80020C08: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80020C0C: slti        $v0, $a1, 0xA
    ctx->r2 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    // 0x80020C10: bnel        $v0, $zero, L_80020BF4
    if (ctx->r2 != 0) {
        // 0x80020C14: addu        $v0, $a1, $a3
        ctx->r2 = ADD32(ctx->r5, ctx->r7);
            goto L_80020BF4;
    }
    goto skip_0;
    // 0x80020C14: addu        $v0, $a1, $a3
    ctx->r2 = ADD32(ctx->r5, ctx->r7);
    skip_0:
    // 0x80020C18: beql        $v1, $zero, L_80020C58
    if (ctx->r3 == 0) {
        // 0x80020C1C: addiu       $a2, $a2, -0x12
        ctx->r6 = ADD32(ctx->r6, -0X12);
            goto L_80020C58;
    }
    goto skip_1;
    // 0x80020C1C: addiu       $a2, $a2, -0x12
    ctx->r6 = ADD32(ctx->r6, -0X12);
    skip_1:
    // 0x80020C20: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x80020C24: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80020C28: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
L_80020C2C:
    // 0x80020C2C: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x80020C30: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80020C34: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80020C38: lbu         $v1, 0x70($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X70);
    // 0x80020C3C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80020C40: ori         $v1, $v1, 0x80
    ctx->r3 = ctx->r3 | 0X80;
    // 0x80020C44: sb          $v1, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r3;
    // 0x80020C48: slti        $v0, $a1, 0xA
    ctx->r2 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    // 0x80020C4C: bne         $v0, $zero, L_80020C2C
    if (ctx->r2 != 0) {
        // 0x80020C50: nop
    
            goto L_80020C2C;
    }
    // 0x80020C50: nop

    // 0x80020C54: addiu       $a2, $a2, -0x12
    ctx->r6 = ADD32(ctx->r6, -0X12);
L_80020C58:
    // 0x80020C58: bgez        $a2, L_80020BE8
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80020C5C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80020BE8;
    }
    // 0x80020C5C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80020C60: beq         $t4, $zero, L_80020D88
    if (ctx->r12 == 0) {
        // 0x80020C64: nop
    
            goto L_80020D88;
    }
    // 0x80020C64: nop

    // 0x80020C68: lw          $v1, 0xB0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XB0);
    // 0x80020C6C: lbu         $v0, 0x1A2($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1A2);
    // 0x80020C70: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80020C74: bne         $v0, $zero, L_80020C94
    if (ctx->r2 != 0) {
        // 0x80020C78: addiu       $t0, $zero, 0x17
        ctx->r8 = ADD32(0, 0X17);
            goto L_80020C94;
    }
    // 0x80020C78: addiu       $t0, $zero, 0x17
    ctx->r8 = ADD32(0, 0X17);
    // 0x80020C7C: addiu       $v1, $v1, 0x19E
    ctx->r3 = ADD32(ctx->r3, 0X19E);
L_80020C80:
    // 0x80020C80: addiu       $v1, $v1, -0x12
    ctx->r3 = ADD32(ctx->r3, -0X12);
    // 0x80020C84: lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4);
    // 0x80020C88: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80020C8C: beq         $v0, $zero, L_80020C80
    if (ctx->r2 == 0) {
        // 0x80020C90: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80020C80;
    }
    // 0x80020C90: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_80020C94:
    // 0x80020C94: addiu       $a3, $t0, -0x1
    ctx->r7 = ADD32(ctx->r8, -0X1);
    // 0x80020C98: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x80020C9C: sll         $v1, $a3, 3
    ctx->r3 = S32(ctx->r7 << 3);
    // 0x80020CA0: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80020CA4: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80020CA8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80020CAC: lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4);
    // 0x80020CB0: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80020CB4: beq         $v0, $zero, L_80020CD0
    if (ctx->r2 == 0) {
        // 0x80020CB8: nop
    
            goto L_80020CD0;
    }
    // 0x80020CB8: nop

L_80020CBC:
    // 0x80020CBC: addiu       $v1, $v1, -0x12
    ctx->r3 = ADD32(ctx->r3, -0X12);
    // 0x80020CC0: lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4);
    // 0x80020CC4: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80020CC8: bne         $v0, $zero, L_80020CBC
    if (ctx->r2 != 0) {
        // 0x80020CCC: addiu       $a3, $a3, -0x1
        ctx->r7 = ADD32(ctx->r7, -0X1);
            goto L_80020CBC;
    }
    // 0x80020CCC: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
L_80020CD0:
    // 0x80020CD0: bltz        $a3, L_80020D44
    if (SIGNED(ctx->r7) < 0) {
        // 0x80020CD4: sll         $v0, $t0, 3
        ctx->r2 = S32(ctx->r8 << 3);
            goto L_80020D44;
    }
    // 0x80020CD4: sll         $v0, $t0, 3
    ctx->r2 = S32(ctx->r8 << 3);
    // 0x80020CD8: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80020CDC: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x80020CE0: sll         $v0, $a3, 3
    ctx->r2 = S32(ctx->r7 << 3);
    // 0x80020CE4: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80020CE8: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
L_80020CEC:
    // 0x80020CEC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80020CF0: addu        $t1, $t3, $zero
    ctx->r9 = ADD32(ctx->r11, 0);
    // 0x80020CF4: addu        $a2, $t2, $zero
    ctx->r6 = ADD32(ctx->r10, 0);
L_80020CF8:
    // 0x80020CF8: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x80020CFC: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80020D00: addu        $v1, $a2, $v0
    ctx->r3 = ADD32(ctx->r6, ctx->r2);
    // 0x80020D04: lbu         $v1, 0x4($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4);
    // 0x80020D08: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80020D0C: sb          $v1, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r3;
    // 0x80020D10: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x80020D14: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80020D18: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80020D1C: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80020D20: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // 0x80020D24: slti        $v0, $a1, 0xA
    ctx->r2 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    // 0x80020D28: bne         $v0, $zero, L_80020CF8
    if (ctx->r2 != 0) {
        // 0x80020D2C: nop
    
            goto L_80020CF8;
    }
    // 0x80020D2C: nop

    // 0x80020D30: addiu       $t2, $t2, -0x12
    ctx->r10 = ADD32(ctx->r10, -0X12);
    // 0x80020D34: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80020D38: addiu       $t3, $t3, -0x12
    ctx->r11 = ADD32(ctx->r11, -0X12);
    // 0x80020D3C: bgez        $a3, L_80020CEC
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80020D40: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80020CEC;
    }
    // 0x80020D40: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_80020D44:
    // 0x80020D44: bltz        $t0, L_80020D88
    if (SIGNED(ctx->r8) < 0) {
        // 0x80020D48: nop
    
            goto L_80020D88;
    }
    // 0x80020D48: nop

    // 0x80020D4C: sll         $v0, $t0, 3
    ctx->r2 = S32(ctx->r8 << 3);
    // 0x80020D50: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80020D54: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
L_80020D58:
    // 0x80020D58: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80020D5C:
    // 0x80020D5C: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x80020D60: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80020D64: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80020D68: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80020D6C: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // 0x80020D70: slti        $v0, $a1, 0xA
    ctx->r2 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    // 0x80020D74: bne         $v0, $zero, L_80020D5C
    if (ctx->r2 != 0) {
        // 0x80020D78: nop
    
            goto L_80020D5C;
    }
    // 0x80020D78: nop

    // 0x80020D7C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80020D80: bgez        $t0, L_80020D58
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80020D84: addiu       $v1, $v1, -0x12
        ctx->r3 = ADD32(ctx->r3, -0X12);
            goto L_80020D58;
    }
    // 0x80020D84: addiu       $v1, $v1, -0x12
    ctx->r3 = ADD32(ctx->r3, -0X12);
L_80020D88:
    // 0x80020D88: jr          $ra
    // 0x80020D8C: addu        $v0, $t4, $zero
    ctx->r2 = ADD32(ctx->r12, 0);
    return;
    // 0x80020D8C: addu        $v0, $t4, $zero
    ctx->r2 = ADD32(ctx->r12, 0);
;}
RECOMP_FUNC void func_80020D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020D90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80020D94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80020D98: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80020D9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
L_80020DA0:
    // 0x80020DA0: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80020DA4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80020DA8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80020DAC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80020DB0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80020DB4: jal         0x800151FC
    // 0x80020DB8: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    func_800151FC(rdram, ctx);
        goto after_0;
    // 0x80020DB8: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    after_0:
    // 0x80020DBC: beq         $v0, $zero, L_80020DA0
    if (ctx->r2 == 0) {
        // 0x80020DC0: nop
    
            goto L_80020DA0;
    }
    // 0x80020DC0: nop

    // 0x80020DC4: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80020DC8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80020DCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80020DD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80020DD4: jr          $ra
    // 0x80020DD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80020DD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80020DDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020DDC: addiu       $a3, $zero, -0x6
    ctx->r7 = ADD32(0, -0X6);
    // 0x80020DE0: addiu       $a2, $zero, -0x6C
    ctx->r6 = ADD32(0, -0X6C);
L_80020DE4:
    // 0x80020DE4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80020DE8:
    // 0x80020DE8: lw          $v1, 0x110($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X110);
    // 0x80020DEC: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x80020DF0: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x80020DF4: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80020DF8: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80020DFC: lbu         $v0, 0x70($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X70);
    // 0x80020E00: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80020E04: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x80020E08: sb          $v0, 0x70($v1)
    MEM_B(0X70, ctx->r3) = ctx->r2;
    // 0x80020E0C: slti        $v0, $a1, 0xA
    ctx->r2 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    // 0x80020E10: bne         $v0, $zero, L_80020DE8
    if (ctx->r2 != 0) {
        // 0x80020E14: nop
    
            goto L_80020DE8;
    }
    // 0x80020E14: nop

    // 0x80020E18: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80020E1C: slti        $v0, $a3, 0x12
    ctx->r2 = SIGNED(ctx->r7) < 0X12 ? 1 : 0;
    // 0x80020E20: bne         $v0, $zero, L_80020DE4
    if (ctx->r2 != 0) {
        // 0x80020E24: addiu       $a2, $a2, 0x12
        ctx->r6 = ADD32(ctx->r6, 0X12);
            goto L_80020DE4;
    }
    // 0x80020E24: addiu       $a2, $a2, 0x12
    ctx->r6 = ADD32(ctx->r6, 0X12);
    // 0x80020E28: jr          $ra
    // 0x80020E2C: nop

    return;
    // 0x80020E2C: nop

;}
RECOMP_FUNC void func_80020E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020E30: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80020E34: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80020E38:
    // 0x80020E38: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80020E3C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80020E40: lb          $v0, 0x7BD0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7BD0);
    // 0x80020E44: beql        $v0, $zero, L_80020E9C
    if (ctx->r2 == 0) {
        // 0x80020E48: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80020E9C;
    }
    goto skip_0;
    // 0x80020E48: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_0:
    // 0x80020E4C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80020E50: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80020E54: lw          $v0, 0x7C04($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7C04);
    // 0x80020E58: bnel        $v0, $a0, L_80020E9C
    if (ctx->r2 != ctx->r4) {
        // 0x80020E5C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80020E9C;
    }
    goto skip_1;
    // 0x80020E5C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_1:
    // 0x80020E60: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80020E64: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80020E68: lbu         $v0, 0x7BD1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7BD1);
    // 0x80020E6C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80020E70: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80020E74: beql        $v0, $zero, L_80020E9C
    if (ctx->r2 == 0) {
        // 0x80020E78: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80020E9C;
    }
    goto skip_2;
    // 0x80020E78: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_2:
    // 0x80020E7C: lb          $v0, 0xCD($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XCD);
    // 0x80020E80: lb          $v1, 0xCC($a0)
    ctx->r3 = MEM_B(ctx->r4, 0XCC);
    // 0x80020E84: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80020E88: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x80020E8C: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80020E90: bne         $v0, $zero, L_80020EAC
    if (ctx->r2 != 0) {
        // 0x80020E94: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80020EAC;
    }
    // 0x80020E94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80020E98: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80020E9C:
    // 0x80020E9C: slti        $v0, $a2, 0x18
    ctx->r2 = SIGNED(ctx->r6) < 0X18 ? 1 : 0;
    // 0x80020EA0: bne         $v0, $zero, L_80020E38
    if (ctx->r2 != 0) {
        // 0x80020EA4: addiu       $a1, $a1, 0x68
        ctx->r5 = ADD32(ctx->r5, 0X68);
            goto L_80020E38;
    }
    // 0x80020EA4: addiu       $a1, $a1, 0x68
    ctx->r5 = ADD32(ctx->r5, 0X68);
    // 0x80020EA8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80020EAC:
    // 0x80020EAC: jr          $ra
    // 0x80020EB0: nop

    return;
    // 0x80020EB0: nop

;}
RECOMP_FUNC void func_80020EB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020EB4: lw          $v1, 0xDC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XDC);
    // 0x80020EB8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80020EBC: addiu       $v0, $v0, -0x33F4
    ctx->r2 = ADD32(ctx->r2, -0X33F4);
    // 0x80020EC0: bne         $v1, $v0, L_80020EDC
    if (ctx->r3 != ctx->r2) {
        // 0x80020EC4: nop
    
            goto L_80020EDC;
    }
    // 0x80020EC4: nop

    // 0x80020EC8: lb          $v0, 0x54($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X54);
    // 0x80020ECC: bne         $v0, $zero, L_80020F24
    if (ctx->r2 != 0) {
        // 0x80020ED0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80020F24;
    }
    // 0x80020ED0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80020ED4:
    // 0x80020ED4: j           L_80020F24
    // 0x80020ED8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80020F24;
    // 0x80020ED8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80020EDC:
    // 0x80020EDC: lb          $a0, 0x54($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X54);
    // 0x80020EE0: beq         $a0, $zero, L_80020ED4
    if (ctx->r4 == 0) {
        // 0x80020EE4: addiu       $v0, $zero, 0x1E
        ctx->r2 = ADD32(0, 0X1E);
            goto L_80020ED4;
    }
    // 0x80020EE4: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x80020EE8: bne         $a0, $v0, L_80020EF8
    if (ctx->r4 != ctx->r2) {
        // 0x80020EEC: addiu       $v0, $zero, 0x1F
        ctx->r2 = ADD32(0, 0X1F);
            goto L_80020EF8;
    }
    // 0x80020EEC: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    // 0x80020EF0: j           L_80020F24
    // 0x80020EF4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80020F24;
    // 0x80020EF4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80020EF8:
    // 0x80020EF8: bne         $a0, $v0, L_80020F08
    if (ctx->r4 != ctx->r2) {
        // 0x80020EFC: addiu       $v0, $zero, 0x20
        ctx->r2 = ADD32(0, 0X20);
            goto L_80020F08;
    }
    // 0x80020EFC: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x80020F00: j           L_80020F24
    // 0x80020F04: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80020F24;
    // 0x80020F04: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80020F08:
    // 0x80020F08: bne         $a0, $v0, L_80020F18
    if (ctx->r4 != ctx->r2) {
        // 0x80020F0C: addiu       $v0, $zero, 0x21
        ctx->r2 = ADD32(0, 0X21);
            goto L_80020F18;
    }
    // 0x80020F0C: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
    // 0x80020F10: j           L_80020F24
    // 0x80020F14: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80020F24;
    // 0x80020F14: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80020F18:
    // 0x80020F18: bne         $a0, $v0, L_80020F24
    if (ctx->r4 != ctx->r2) {
        // 0x80020F1C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80020F24;
    }
    // 0x80020F1C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80020F20: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80020F24:
    // 0x80020F24: jr          $ra
    // 0x80020F28: nop

    return;
    // 0x80020F28: nop

;}
RECOMP_FUNC void func_80020F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020F34: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80020F38: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80020F3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020F40: lb          $v1, 0x2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X2);
    // 0x80020F44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80020F48: bne         $v1, $v0, L_80020F84
    if (ctx->r3 != ctx->r2) {
        // 0x80020F4C: nop
    
            goto L_80020F84;
    }
    // 0x80020F4C: nop

    // 0x80020F50: lb          $v0, 0x11F($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X11F);
    // 0x80020F54: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80020F58: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80020F5C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80020F60: lw          $v0, 0x2310($at)
    ctx->r2 = MEM_W(ctx->r1, 0X2310);
    // 0x80020F64: jalr        $v0
    // 0x80020F68: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80020F68: nop

    after_0:
    // 0x80020F6C: lw          $v1, 0xB4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB4);
    // 0x80020F70: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x80020F74: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80020F78: lw          $v1, 0xB8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB8);
    // 0x80020F7C: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x80020F80: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_80020F84:
    // 0x80020F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020F88: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80020F8C: jr          $ra
    // 0x80020F90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80020F90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80020F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020F94: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80020F98: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80020F9C: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x80020FA0: addiu       $t2, $t2, -0x212C
    ctx->r10 = ADD32(ctx->r10, -0X212C);
    // 0x80020FA4: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x80020FA8: addiu       $t1, $t1, -0x2120
    ctx->r9 = ADD32(ctx->r9, -0X2120);
    // 0x80020FAC: lbu         $v1, 0x5($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X5);
    // 0x80020FB0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80020FB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80020FB8: sb          $v0, 0x11F($a2)
    MEM_B(0X11F, ctx->r6) = ctx->r2;
    // 0x80020FBC: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x80020FC0: sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3 << 2);
    // 0x80020FC4: sll         $t0, $v1, 9
    ctx->r8 = S32(ctx->r3 << 9);
    // 0x80020FC8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80020FCC: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80020FD0: sw          $zero, -0x212C($at)
    MEM_W(-0X212C, ctx->r1) = 0;
    // 0x80020FD4: addu        $a0, $a1, $t2
    ctx->r4 = ADD32(ctx->r5, ctx->r10);
L_80020FD8:
    // 0x80020FD8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80020FDC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80020FE0: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80020FE4: addu        $v0, $v1, $t1
    ctx->r2 = ADD32(ctx->r3, ctx->r9);
    // 0x80020FE8: sb          $a3, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r7;
    // 0x80020FEC: sb          $a3, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r7;
    // 0x80020FF0: sb          $a3, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r7;
    // 0x80020FF4: sb          $a3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r7;
    // 0x80020FF8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80020FFC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80021000: sb          $a3, -0x2120($at)
    MEM_B(-0X2120, ctx->r1) = ctx->r7;
    // 0x80021004: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80021008: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8002100C: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80021010: addu        $v1, $v0, $t1
    ctx->r3 = ADD32(ctx->r2, ctx->r9);
    // 0x80021014: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80021018: sb          $zero, 0x6($v1)
    MEM_B(0X6, ctx->r3) = 0;
    // 0x8002101C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021020: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021024: sb          $zero, -0x2119($at)
    MEM_B(-0X2119, ctx->r1) = 0;
    // 0x80021028: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8002102C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80021030: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80021034: slti        $v0, $v0, 0x40
    ctx->r2 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x80021038: bne         $v0, $zero, L_80020FD8
    if (ctx->r2 != 0) {
        // 0x8002103C: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_80020FD8;
    }
    // 0x8002103C: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x80021040: addu        $v0, $v1, $t2
    ctx->r2 = ADD32(ctx->r3, ctx->r10);
    // 0x80021044: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80021048: lw          $a0, 0xB4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XB4);
    // 0x8002104C: lw          $v1, 0xB8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XB8);
    // 0x80021050: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x80021054: sb          $v0, 0x125($a2)
    MEM_B(0X125, ctx->r6) = ctx->r2;
    // 0x80021058: sb          $v0, 0x124($a2)
    MEM_B(0X124, ctx->r6) = ctx->r2;
    // 0x8002105C: sb          $v0, 0x123($a2)
    MEM_B(0X123, ctx->r6) = ctx->r2;
    // 0x80021060: sb          $zero, 0x129($a2)
    MEM_B(0X129, ctx->r6) = 0;
    // 0x80021064: sb          $zero, 0x128($a2)
    MEM_B(0X128, ctx->r6) = 0;
    // 0x80021068: sb          $zero, 0x127($a2)
    MEM_B(0X127, ctx->r6) = 0;
    // 0x8002106C: sb          $zero, 0x126($a2)
    MEM_B(0X126, ctx->r6) = 0;
    // 0x80021070: sb          $zero, 0x12A($a2)
    MEM_B(0X12A, ctx->r6) = 0;
    // 0x80021074: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x80021078: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x8002107C: sw          $zero, 0x114($a2)
    MEM_W(0X114, ctx->r6) = 0;
    // 0x80021080: jr          $ra
    // 0x80021084: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80021084: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80021088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021088: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8002108C: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x80021090: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80021094: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x80021098: sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
    // 0x8002109C: sw          $s7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r23;
    // 0x800210A0: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x800210A4: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x800210A8: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x800210AC: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x800210B0: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x800210B4: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x800210B8: lw          $a3, 0x18($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X18);
    // 0x800210BC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800210C0: lw          $a3, 0x1C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X1C);
    // 0x800210C4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800210C8: lbu         $a3, 0x4C($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X4C);
    // 0x800210CC: sb          $a3, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r7;
    // 0x800210D0: lw          $a3, 0xB0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XB0);
    // 0x800210D4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800210D8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800210DC: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x800210E0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800210E4: addiu       $a0, $a0, -0x212C
    ctx->r4 = ADD32(ctx->r4, -0X212C);
    // 0x800210E8: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x800210EC: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800210F0: sw          $zero, 0x114($s1)
    MEM_W(0X114, ctx->r17) = 0;
    // 0x800210F4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800210F8: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800210FC: addu        $s4, $v1, $a0
    ctx->r20 = ADD32(ctx->r3, ctx->r4);
    // 0x80021100: sll         $s7, $v0, 9
    ctx->r23 = S32(ctx->r2 << 9);
L_80021104:
    // 0x80021104: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80021108: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8002110C: jal         0x80020DDC
    // 0x80021110: sw          $a3, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = ctx->r7;
    func_80020DDC(rdram, ctx);
        goto after_0;
    // 0x80021110: sw          $a3, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = ctx->r7;
    after_0:
    // 0x80021114: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80021118: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8002111C: jal         0x80020A8C
    // 0x80021120: sw          $v0, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = ctx->r2;
    func_80020A8C(rdram, ctx);
        goto after_1;
    // 0x80021120: sw          $v0, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = ctx->r2;
    after_1:
    // 0x80021124: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80021128: jal         0x80016980
    // 0x8002112C: sb          $zero, 0x4C($s1)
    MEM_B(0X4C, ctx->r17) = 0;
    func_80016980(rdram, ctx);
        goto after_2;
    // 0x8002112C: sb          $zero, 0x4C($s1)
    MEM_B(0X4C, ctx->r17) = 0;
    after_2:
    // 0x80021130: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80021134: jal         0x800169C8
    // 0x80021138: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    func_800169C8(rdram, ctx);
        goto after_3;
    // 0x80021138: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    after_3:
    // 0x8002113C: lbu         $v1, 0x11F($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X11F);
    // 0x80021140: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80021144: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80021148: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // 0x8002114C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80021150: jal         0x80021F00
    // 0x80021154: sb          $v1, 0x4C($s1)
    MEM_B(0X4C, ctx->r17) = ctx->r3;
    func_80021F00(rdram, ctx);
        goto after_4;
    // 0x80021154: sb          $v1, 0x4C($s1)
    MEM_B(0X4C, ctx->r17) = ctx->r3;
    after_4:
    // 0x80021158: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8002115C: lbu         $v1, 0x2076($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2076);
    // 0x80021160: beq         $v1, $zero, L_8002117C
    if (ctx->r3 == 0) {
        // 0x80021164: addu        $s0, $v0, $zero
        ctx->r16 = ADD32(ctx->r2, 0);
            goto L_8002117C;
    }
    // 0x80021164: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80021168: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002116C: lbu         $v0, 0x7B9A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9A);
    // 0x80021170: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80021174: beq         $v0, $a3, L_8002119C
    if (ctx->r2 == ctx->r7) {
        // 0x80021178: nop
    
            goto L_8002119C;
    }
    // 0x80021178: nop

L_8002117C:
    // 0x8002117C: beq         $s0, $zero, L_8002119C
    if (ctx->r16 == 0) {
        // 0x80021180: nop
    
            goto L_8002119C;
    }
    // 0x80021180: nop

    // 0x80021184: jal         0x80020D90
    // 0x80021188: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80020D90(rdram, ctx);
        goto after_5;
    // 0x80021188: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
    // 0x8002118C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80021190: addiu       $v1, $a3, 0x1
    ctx->r3 = ADD32(ctx->r7, 0X1);
    // 0x80021194: j           L_800211AC
    // 0x80021198: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
        goto L_800211AC;
    // 0x80021198: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8002119C:
    // 0x8002119C: jal         0x80020D90
    // 0x800211A0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80020D90(rdram, ctx);
        goto after_6;
    // 0x800211A0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_6:
    // 0x800211A4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800211A8: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
L_800211AC:
    // 0x800211AC: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // 0x800211B0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800211B4: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800211B8: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    // 0x800211BC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800211C0: jal         0x800151FC
    // 0x800211C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800151FC(rdram, ctx);
        goto after_7;
    // 0x800211C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x800211C8: beq         $v0, $zero, L_8002130C
    if (ctx->r2 == 0) {
        // 0x800211CC: addiu       $v0, $zero, -0x3
        ctx->r2 = ADD32(0, -0X3);
            goto L_8002130C;
    }
    // 0x800211CC: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
    // 0x800211D0: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x800211D4: bne         $v1, $v0, L_800211F4
    if (ctx->r3 != ctx->r2) {
        // 0x800211D8: nop
    
            goto L_800211F4;
    }
    // 0x800211D8: nop

    // 0x800211DC: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x800211E0: bne         $v0, $zero, L_800211F4
    if (ctx->r2 != 0) {
        // 0x800211E4: nop
    
            goto L_800211F4;
    }
    // 0x800211E4: nop

    // 0x800211E8: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x800211EC: j           L_800212F0
    // 0x800211F0: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
        goto L_800212F0;
    // 0x800211F0: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_800211F4:
    // 0x800211F4: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x800211F8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800211FC: bne         $v0, $a3, L_80021220
    if (ctx->r2 != ctx->r7) {
        // 0x80021200: nop
    
            goto L_80021220;
    }
    // 0x80021200: nop

    // 0x80021204: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x80021208: bne         $v0, $zero, L_8002121C
    if (ctx->r2 != 0) {
        // 0x8002120C: nop
    
            goto L_8002121C;
    }
    // 0x8002120C: nop

    // 0x80021210: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x80021214: j           L_800212F0
    // 0x80021218: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
        goto L_800212F0;
    // 0x80021218: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
L_8002121C:
    // 0x8002121C: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
L_80021220:
    // 0x80021220: bne         $v0, $zero, L_80021244
    if (ctx->r2 != 0) {
        // 0x80021224: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_80021244;
    }
    // 0x80021224: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80021228: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x8002122C: bne         $v0, $a3, L_80021244
    if (ctx->r2 != ctx->r7) {
        // 0x80021230: nop
    
            goto L_80021244;
    }
    // 0x80021230: nop

    // 0x80021234: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    // 0x80021238: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8002123C: j           L_800212F4
    // 0x80021240: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
        goto L_800212F4;
    // 0x80021240: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
L_80021244:
    // 0x80021244: lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10);
    // 0x80021248: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x8002124C: bgez        $a0, L_80021258
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80021250: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80021258;
    }
    // 0x80021250: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80021254: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_80021258:
    // 0x80021258: bltzl       $v0, L_80021260
    if (SIGNED(ctx->r2) < 0) {
        // 0x8002125C: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_80021260;
    }
    goto skip_0;
    // 0x8002125C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_0:
L_80021260:
    // 0x80021260: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80021264: beq         $v0, $zero, L_80021288
    if (ctx->r2 == 0) {
        // 0x80021268: nop
    
            goto L_80021288;
    }
    // 0x80021268: nop

    // 0x8002126C: blez        $a0, L_80021280
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80021270: nop
    
            goto L_80021280;
    }
    // 0x80021270: nop

    // 0x80021274: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x80021278: j           L_800212F0
    // 0x8002127C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_800212F0;
    // 0x8002127C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80021280:
    // 0x80021280: bltz        $a0, L_800212E8
    if (SIGNED(ctx->r4) < 0) {
        // 0x80021284: nop
    
            goto L_800212E8;
    }
    // 0x80021284: nop

L_80021288:
    // 0x80021288: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x8002128C: lw          $a0, 0x14($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X14);
    // 0x80021290: bltzl       $v1, L_80021298
    if (SIGNED(ctx->r3) < 0) {
        // 0x80021294: negu        $v1, $v1
        ctx->r3 = SUB32(0, ctx->r3);
            goto L_80021298;
    }
    goto skip_1;
    // 0x80021294: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    skip_1:
L_80021298:
    // 0x80021298: bgez        $a0, L_800212A4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8002129C: addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
            goto L_800212A4;
    }
    // 0x8002129C: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x800212A0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_800212A4:
    // 0x800212A4: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800212A8: beq         $v1, $zero, L_800212C8
    if (ctx->r3 == 0) {
        // 0x800212AC: nop
    
            goto L_800212C8;
    }
    // 0x800212AC: nop

    // 0x800212B0: blez        $a0, L_800212C8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800212B4: nop
    
            goto L_800212C8;
    }
    // 0x800212B4: nop

    // 0x800212B8: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    // 0x800212BC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800212C0: j           L_800212F4
    // 0x800212C4: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
        goto L_800212F4;
    // 0x800212C4: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
L_800212C8:
    // 0x800212C8: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x800212CC: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x800212D0: bltzl       $v1, L_800212D8
    if (SIGNED(ctx->r3) < 0) {
        // 0x800212D4: negu        $v1, $v1
        ctx->r3 = SUB32(0, ctx->r3);
            goto L_800212D8;
    }
    goto skip_2;
    // 0x800212D4: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    skip_2:
L_800212D8:
    // 0x800212D8: bltzl       $v0, L_800212E0
    if (SIGNED(ctx->r2) < 0) {
        // 0x800212DC: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_800212E0;
    }
    goto skip_3;
    // 0x800212DC: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_3:
L_800212E0:
    // 0x800212E0: bne         $v1, $v0, L_800212F4
    if (ctx->r3 != ctx->r2) {
        // 0x800212E4: nop
    
            goto L_800212F4;
    }
    // 0x800212E4: nop

L_800212E8:
    // 0x800212E8: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x800212EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800212F0:
    // 0x800212F0: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
L_800212F4:
    // 0x800212F4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x800212F8: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x800212FC: jal         0x800151FC
    // 0x80021300: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800151FC(rdram, ctx);
        goto after_8;
    // 0x80021300: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_8:
    // 0x80021304: bne         $v0, $zero, L_8002152C
    if (ctx->r2 != 0) {
        // 0x80021308: nop
    
            goto L_8002152C;
    }
    // 0x80021308: nop

L_8002130C:
    // 0x8002130C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80021310: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80021314: jal         0x800151FC
    // 0x80021318: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800151FC(rdram, ctx);
        goto after_9;
    // 0x80021318: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_9:
    // 0x8002131C: bne         $v0, $zero, L_80021334
    if (ctx->r2 != 0) {
        // 0x80021320: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80021334;
    }
    // 0x80021320: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80021324: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    // 0x80021328: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002132C: j           L_8002130C
    // 0x80021330: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
        goto L_8002130C;
    // 0x80021330: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
L_80021334:
    // 0x80021334: lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1C);
    // 0x80021338: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8002133C: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x80021340: jal         0x80020874
    // 0x80021344: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    func_80020874(rdram, ctx);
        goto after_10;
    // 0x80021344: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    after_10:
    // 0x80021348: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8002134C: jal         0x80015490
    // 0x80021350: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    func_80015490(rdram, ctx);
        goto after_11;
    // 0x80021350: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    after_11:
    // 0x80021354: jal         0x80020BDC
    // 0x80021358: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80020BDC(rdram, ctx);
        goto after_12;
    // 0x80021358: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_12:
    // 0x8002135C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80021360: jal         0x800220C4
    // 0x80021364: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    func_800220C4(rdram, ctx);
        goto after_13;
    // 0x80021364: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    after_13:
    // 0x80021368: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8002136C: jal         0x80021FFC
    // 0x80021370: addu        $fp, $v0, $zero
    ctx->r30 = ADD32(ctx->r2, 0);
    func_80021FFC(rdram, ctx);
        goto after_14;
    // 0x80021370: addu        $fp, $v0, $zero
    ctx->r30 = ADD32(ctx->r2, 0);
    after_14:
    // 0x80021374: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80021378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002137C: jal         0x80020B20
    // 0x80021380: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    func_80020B20(rdram, ctx);
        goto after_15;
    // 0x80021380: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    after_15:
    // 0x80021384: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80021388: jal         0x80020A8C
    // 0x8002138C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    func_80020A8C(rdram, ctx);
        goto after_16;
    // 0x8002138C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    after_16:
    // 0x80021390: beq         $s0, $zero, L_800213A4
    if (ctx->r16 == 0) {
        // 0x80021394: sw          $v0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r2;
            goto L_800213A4;
    }
    // 0x80021394: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80021398: lb          $v0, 0x123($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X123);
    // 0x8002139C: j           L_800213EC
    // 0x800213A0: slt         $v0, $v0, $s2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
        goto L_800213EC;
    // 0x800213A0: slt         $v0, $v0, $s2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
L_800213A4:
    // 0x800213A4: beq         $s3, $zero, L_800213B8
    if (ctx->r19 == 0) {
        // 0x800213A8: nop
    
            goto L_800213B8;
    }
    // 0x800213A8: nop

    // 0x800213AC: lb          $v0, 0x126($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X126);
    // 0x800213B0: j           L_800213F0
    // 0x800213B4: slt         $v0, $v0, $s3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
        goto L_800213F0;
    // 0x800213B4: slt         $v0, $v0, $s3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
L_800213B8:
    // 0x800213B8: lb          $s0, 0x127($s1)
    ctx->r16 = MEM_B(ctx->r17, 0X127);
    // 0x800213BC: jal         0x80020EB4
    // 0x800213C0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80020EB4(rdram, ctx);
        goto after_17;
    // 0x800213C0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_17:
    // 0x800213C4: slt         $s0, $s0, $v0
    ctx->r16 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800213C8: beq         $s0, $zero, L_800213E0
    if (ctx->r16 == 0) {
        // 0x800213CC: nop
    
            goto L_800213E0;
    }
    // 0x800213CC: nop

    // 0x800213D0: lb          $v0, 0x129($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X129);
    // 0x800213D4: addiu       $v0, $v0, -0x3
    ctx->r2 = ADD32(ctx->r2, -0X3);
    // 0x800213D8: j           L_800213F0
    // 0x800213DC: slt         $v0, $v0, $s6
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r22) ? 1 : 0;
        goto L_800213F0;
    // 0x800213DC: slt         $v0, $v0, $s6
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r22) ? 1 : 0;
L_800213E0:
    // 0x800213E0: lb          $v0, 0x127($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X127);
    // 0x800213E4: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x800213E8: slt         $v0, $s5, $v0
    ctx->r2 = SIGNED(ctx->r21) < SIGNED(ctx->r2) ? 1 : 0;
L_800213EC:
    // 0x800213EC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
L_800213F0:
    // 0x800213F0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800213F4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800213F8: sltiu       $v1, $fp, 0x1
    ctx->r3 = ctx->r30 < 0X1 ? 1 : 0;
    // 0x800213FC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80021400: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80021404: beq         $v0, $zero, L_8002152C
    if (ctx->r2 == 0) {
        // 0x80021408: nop
    
            goto L_8002152C;
    }
    // 0x80021408: nop

    // 0x8002140C: lb          $v0, 0x123($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X123);
    // 0x80021410: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80021414: bnel        $v0, $zero, L_8002141C
    if (ctx->r2 != 0) {
        // 0x80021418: sb          $s2, 0x123($s1)
        MEM_B(0X123, ctx->r17) = ctx->r18;
            goto L_8002141C;
    }
    goto skip_4;
    // 0x80021418: sb          $s2, 0x123($s1)
    MEM_B(0X123, ctx->r17) = ctx->r18;
    skip_4:
L_8002141C:
    // 0x8002141C: lb          $v0, 0x126($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X126);
    // 0x80021420: slt         $v0, $v0, $s3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80021424: bnel        $v0, $zero, L_8002142C
    if (ctx->r2 != 0) {
        // 0x80021428: sb          $s3, 0x126($s1)
        MEM_B(0X126, ctx->r17) = ctx->r19;
            goto L_8002142C;
    }
    goto skip_5;
    // 0x80021428: sb          $s3, 0x126($s1)
    MEM_B(0X126, ctx->r17) = ctx->r19;
    skip_5:
L_8002142C:
    // 0x8002142C: lb          $v0, 0x127($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X127);
    // 0x80021430: slt         $v0, $v0, $s5
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80021434: bnel        $v0, $zero, L_8002143C
    if (ctx->r2 != 0) {
        // 0x80021438: sb          $s5, 0x127($s1)
        MEM_B(0X127, ctx->r17) = ctx->r21;
            goto L_8002143C;
    }
    goto skip_6;
    // 0x80021438: sb          $s5, 0x127($s1)
    MEM_B(0X127, ctx->r17) = ctx->r21;
    skip_6:
L_8002143C:
    // 0x8002143C: lb          $v0, 0x129($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X129);
    // 0x80021440: slt         $v0, $v0, $s6
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80021444: bnel        $v0, $zero, L_8002144C
    if (ctx->r2 != 0) {
        // 0x80021448: sb          $s6, 0x129($s1)
        MEM_B(0X129, ctx->r17) = ctx->r22;
            goto L_8002144C;
    }
    goto skip_7;
    // 0x80021448: sb          $s6, 0x129($s1)
    MEM_B(0X129, ctx->r17) = ctx->r22;
    skip_7:
L_8002144C:
    // 0x8002144C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80021450: lbu         $v1, 0x4C($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X4C);
    // 0x80021454: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021458: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x8002145C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021460: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021464: sb          $v1, -0x2120($at)
    MEM_B(-0X2120, ctx->r1) = ctx->r3;
    // 0x80021468: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8002146C: lw          $v1, 0x18($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X18);
    // 0x80021470: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021474: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x80021478: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002147C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021480: sb          $v1, -0x211F($at)
    MEM_B(-0X211F, ctx->r1) = ctx->r3;
    // 0x80021484: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80021488: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8002148C: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x80021490: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021494: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021498: sb          $s2, -0x211C($at)
    MEM_B(-0X211C, ctx->r1) = ctx->r18;
    // 0x8002149C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800214A0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800214A4: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x800214A8: lbu         $a3, 0x4F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X4F);
    // 0x800214AC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800214B0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800214B4: sb          $a3, -0x211E($at)
    MEM_B(-0X211E, ctx->r1) = ctx->r7;
    // 0x800214B8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800214BC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800214C0: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x800214C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800214C8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800214CC: sb          $s3, -0x211D($at)
    MEM_B(-0X211D, ctx->r1) = ctx->r19;
    // 0x800214D0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800214D4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800214D8: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x800214DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800214E0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800214E4: sb          $s5, -0x211B($at)
    MEM_B(-0X211B, ctx->r1) = ctx->r21;
    // 0x800214E8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800214EC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800214F0: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x800214F4: lbu         $a3, 0x57($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X57);
    // 0x800214F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800214FC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021500: sb          $a3, -0x211A($at)
    MEM_B(-0X211A, ctx->r1) = ctx->r7;
    // 0x80021504: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80021508: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8002150C: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x80021510: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021514: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021518: sb          $s6, -0x2119($at)
    MEM_B(-0X2119, ctx->r1) = ctx->r22;
    // 0x8002151C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80021520: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80021524: andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // 0x80021528: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
L_8002152C:
    // 0x8002152C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80021530: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80021534: slti        $v0, $a3, 0xA
    ctx->r2 = SIGNED(ctx->r7) < 0XA ? 1 : 0;
    // 0x80021538: bne         $v0, $zero, L_80021104
    if (ctx->r2 != 0) {
        // 0x8002153C: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_80021104;
    }
    // 0x8002153C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80021540: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80021544: sw          $a3, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r7;
    // 0x80021548: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8002154C: sw          $a3, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r7;
    // 0x80021550: lbu         $a3, 0x3F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3F);
    // 0x80021554: sb          $a3, 0x4C($s1)
    MEM_B(0X4C, ctx->r17) = ctx->r7;
    // 0x80021558: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8002155C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80021560: jal         0x80020DDC
    // 0x80021564: sw          $a3, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = ctx->r7;
    func_80020DDC(rdram, ctx);
        goto after_18;
    // 0x80021564: sw          $a3, 0xB0($s1)
    MEM_W(0XB0, ctx->r17) = ctx->r7;
    after_18:
    // 0x80021568: lbu         $v0, 0x11F($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X11F);
    // 0x8002156C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80021570: sb          $v0, 0x11F($s1)
    MEM_B(0X11F, ctx->r17) = ctx->r2;
    // 0x80021574: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x80021578: lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X80);
    // 0x8002157C: lw          $s7, 0x7C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X7C);
    // 0x80021580: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x80021584: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x80021588: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x8002158C: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x80021590: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x80021594: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x80021598: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x8002159C: jr          $ra
    // 0x800215A0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800215A0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_800215A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800215A4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800215A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800215AC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800215B0: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x800215B4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800215B8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800215BC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800215C0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800215C4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800215C8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800215CC: jal         0x80020A8C
    // 0x800215D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80020A8C(rdram, ctx);
        goto after_0;
    // 0x800215D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800215D4: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800215D8: lbu         $v1, 0x5($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X5);
    // 0x800215DC: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x800215E0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800215E4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800215E8: sb          $v0, 0x11F($s1)
    MEM_B(0X11F, ctx->r17) = ctx->r2;
    // 0x800215EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800215F0: sb          $v0, 0x11D($s1)
    MEM_B(0X11D, ctx->r17) = ctx->r2;
    // 0x800215F4: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x800215F8: sw          $zero, 0x114($s1)
    MEM_W(0X114, ctx->r17) = 0;
    // 0x800215FC: sb          $zero, 0x128($s1)
    MEM_B(0X128, ctx->r17) = 0;
    // 0x80021600: sb          $zero, 0x126($s1)
    MEM_B(0X126, ctx->r17) = 0;
    // 0x80021604: sb          $zero, 0x129($s1)
    MEM_B(0X129, ctx->r17) = 0;
    // 0x80021608: sb          $v0, 0x125($s1)
    MEM_B(0X125, ctx->r17) = ctx->r2;
    // 0x8002160C: sb          $v0, 0x124($s1)
    MEM_B(0X124, ctx->r17) = ctx->r2;
    // 0x80021610: sb          $zero, 0x12A($s1)
    MEM_B(0X12A, ctx->r17) = 0;
    // 0x80021614: jal         0x80021F00
    // 0x80021618: andi        $s0, $v1, 0x1
    ctx->r16 = ctx->r3 & 0X1;
    func_80021F00(rdram, ctx);
        goto after_1;
    // 0x80021618: andi        $s0, $v1, 0x1
    ctx->r16 = ctx->r3 & 0X1;
    after_1:
    // 0x8002161C: beq         $v0, $zero, L_800217F8
    if (ctx->r2 == 0) {
        // 0x80021620: sll         $a0, $s0, 2
        ctx->r4 = S32(ctx->r16 << 2);
            goto L_800217F8;
    }
    // 0x80021620: sll         $a0, $s0, 2
    ctx->r4 = S32(ctx->r16 << 2);
    // 0x80021624: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80021628: addiu       $v0, $v0, -0x212C
    ctx->r2 = ADD32(ctx->r2, -0X212C);
    // 0x8002162C: addu        $v1, $a0, $v0
    ctx->r3 = ADD32(ctx->r4, ctx->r2);
    // 0x80021630: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80021634: addu        $t3, $v0, $zero
    ctx->r11 = ADD32(ctx->r2, 0);
    // 0x80021638: sll         $a2, $s0, 9
    ctx->r6 = S32(ctx->r16 << 9);
    // 0x8002163C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80021640: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80021644: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x80021648: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
L_8002164C:
    // 0x8002164C: addu        $a1, $a0, $t3
    ctx->r5 = ADD32(ctx->r4, ctx->r11);
    // 0x80021650: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80021654: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021658: addu        $a0, $v0, $a2
    ctx->r4 = ADD32(ctx->r2, ctx->r6);
    // 0x8002165C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80021660: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80021664: lbu         $v0, -0x211D($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X211D);
    // 0x80021668: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8002166C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80021670: beq         $v0, $zero, L_8002170C
    if (ctx->r2 == 0) {
        // 0x80021674: nop
    
            goto L_8002170C;
    }
    // 0x80021674: nop

    // 0x80021678: sw          $t2, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->r10;
    // 0x8002167C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80021680: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021684: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80021688: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002168C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021690: lbu         $v0, -0x211E($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211E);
    // 0x80021694: sb          $v0, 0x125($s1)
    MEM_B(0X125, ctx->r17) = ctx->r2;
    // 0x80021698: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8002169C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800216A0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800216A4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800216A8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800216AC: lbu         $v0, -0x211F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211F);
    // 0x800216B0: sb          $v0, 0x122($s1)
    MEM_B(0X122, ctx->r17) = ctx->r2;
    // 0x800216B4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800216B8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800216BC: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800216C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800216C4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800216C8: lbu         $v0, -0x2120($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X2120);
    // 0x800216CC: sb          $v0, 0x11D($s1)
    MEM_B(0X11D, ctx->r17) = ctx->r2;
    // 0x800216D0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800216D4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800216D8: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800216DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800216E0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800216E4: lbu         $v0, -0x211A($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211A);
    // 0x800216E8: sb          $v0, 0x120($s1)
    MEM_B(0X120, ctx->r17) = ctx->r2;
    // 0x800216EC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800216F0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800216F4: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800216F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800216FC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021700: lbu         $v0, -0x211D($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211D);
    // 0x80021704: j           L_800217D4
    // 0x80021708: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_800217D4;
    // 0x80021708: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8002170C:
    // 0x8002170C: bne         $s2, $zero, L_800217D8
    if (ctx->r18 != 0) {
        // 0x80021710: nop
    
            goto L_800217D8;
    }
    // 0x80021710: nop

    // 0x80021714: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80021718: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8002171C: lbu         $v1, -0x211C($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X211C);
    // 0x80021720: lb          $v0, 0x123($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X123);
    // 0x80021724: bne         $v1, $v0, L_800217D8
    if (ctx->r3 != ctx->r2) {
        // 0x80021728: nop
    
            goto L_800217D8;
    }
    // 0x80021728: nop

    // 0x8002172C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80021730: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80021734: lbu         $v1, -0x211E($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X211E);
    // 0x80021738: lb          $v0, 0x125($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X125);
    // 0x8002173C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80021740: bne         $v0, $zero, L_800217D8
    if (ctx->r2 != 0) {
        // 0x80021744: nop
    
            goto L_800217D8;
    }
    // 0x80021744: nop

    // 0x80021748: sw          $t1, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->r9;
    // 0x8002174C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80021750: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021754: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80021758: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002175C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021760: lbu         $v0, -0x211E($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211E);
    // 0x80021764: sb          $v0, 0x125($s1)
    MEM_B(0X125, ctx->r17) = ctx->r2;
    // 0x80021768: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8002176C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021770: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80021774: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021778: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002177C: lbu         $v0, -0x211F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211F);
    // 0x80021780: sb          $v0, 0x122($s1)
    MEM_B(0X122, ctx->r17) = ctx->r2;
    // 0x80021784: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80021788: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8002178C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80021790: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021794: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021798: lbu         $v0, -0x2120($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X2120);
    // 0x8002179C: sb          $v0, 0x11D($s1)
    MEM_B(0X11D, ctx->r17) = ctx->r2;
    // 0x800217A0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800217A4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800217A8: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800217AC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800217B0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800217B4: lbu         $v0, -0x211A($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211A);
    // 0x800217B8: sb          $v0, 0x120($s1)
    MEM_B(0X120, ctx->r17) = ctx->r2;
    // 0x800217BC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800217C0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800217C4: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800217C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800217CC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800217D0: lbu         $v0, -0x211D($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211D);
L_800217D4:
    // 0x800217D4: sb          $v0, 0x121($s1)
    MEM_B(0X121, ctx->r17) = ctx->r2;
L_800217D8:
    // 0x800217D8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800217DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800217E0: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x800217E4: slti        $v0, $v0, 0x40
    ctx->r2 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x800217E8: bne         $v0, $zero, L_8002164C
    if (ctx->r2 != 0) {
        // 0x800217EC: addu        $a0, $t0, $zero
        ctx->r4 = ADD32(ctx->r8, 0);
            goto L_8002164C;
    }
    // 0x800217EC: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800217F0: j           L_80021CF4
    // 0x800217F4: nop

        goto L_80021CF4;
    // 0x800217F4: nop

L_800217F8:
    // 0x800217F8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800217FC: addiu       $a0, $a0, -0x212C
    ctx->r4 = ADD32(ctx->r4, -0X212C);
    // 0x80021800: sll         $v1, $s0, 2
    ctx->r3 = S32(ctx->r16 << 2);
    // 0x80021804: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x80021808: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8002180C: sll         $s3, $s0, 9
    ctx->r19 = S32(ctx->r16 << 9);
    // 0x80021810: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x80021814: addu        $s6, $v1, $zero
    ctx->r22 = ADD32(ctx->r3, 0);
    // 0x80021818: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
L_8002181C:
    // 0x8002181C: addu        $s2, $v1, $a0
    ctx->r18 = ADD32(ctx->r3, ctx->r4);
    // 0x80021820: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80021824: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021828: addu        $a1, $v0, $s3
    ctx->r5 = ADD32(ctx->r2, ctx->r19);
    // 0x8002182C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80021830: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80021834: lbu         $v1, -0x211C($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X211C);
    // 0x80021838: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002183C: beq         $v1, $v0, L_80021CD8
    if (ctx->r3 == ctx->r2) {
        // 0x80021840: nop
    
            goto L_80021CD8;
    }
    // 0x80021840: nop

    // 0x80021844: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80021848: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x8002184C: lbu         $a0, -0x211D($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X211D);
    // 0x80021850: lb          $v1, 0x126($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X126);
    // 0x80021854: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80021858: beq         $v0, $zero, L_80021938
    if (ctx->r2 == 0) {
        // 0x8002185C: nop
    
            goto L_80021938;
    }
    // 0x8002185C: nop

    // 0x80021860: bne         $a0, $v1, L_80021910
    if (ctx->r4 != ctx->r3) {
        // 0x80021864: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80021910;
    }
    // 0x80021864: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80021868: beql        $v1, $zero, L_80021914
    if (ctx->r3 == 0) {
        // 0x8002186C: sw          $v0, 0x12C($s1)
        MEM_W(0X12C, ctx->r17) = ctx->r2;
            goto L_80021914;
    }
    goto skip_0;
    // 0x8002186C: sw          $v0, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->r2;
    skip_0:
    // 0x80021870: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80021874: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80021878: lbu         $v1, -0x211E($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X211E);
    // 0x8002187C: lb          $v0, 0x125($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X125);
    // 0x80021880: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80021884: bne         $v0, $zero, L_80021CD8
    if (ctx->r2 != 0) {
        // 0x80021888: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_80021CD8;
    }
    // 0x80021888: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8002188C: sw          $v0, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->r2;
    // 0x80021890: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80021894: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021898: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x8002189C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800218A0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800218A4: lbu         $v0, -0x211E($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211E);
    // 0x800218A8: sb          $v0, 0x125($s1)
    MEM_B(0X125, ctx->r17) = ctx->r2;
    // 0x800218AC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800218B0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800218B4: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800218B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800218BC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800218C0: lbu         $v0, -0x211D($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211D);
    // 0x800218C4: sb          $v0, 0x126($s1)
    MEM_B(0X126, ctx->r17) = ctx->r2;
    // 0x800218C8: sb          $v0, 0x121($s1)
    MEM_B(0X121, ctx->r17) = ctx->r2;
    // 0x800218CC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800218D0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800218D4: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800218D8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800218DC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800218E0: lbu         $v0, -0x211F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211F);
    // 0x800218E4: sb          $v0, 0x122($s1)
    MEM_B(0X122, ctx->r17) = ctx->r2;
    // 0x800218E8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800218EC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800218F0: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800218F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800218F8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800218FC: lbu         $v0, -0x2120($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X2120);
    // 0x80021900: sb          $v0, 0x11D($s1)
    MEM_B(0X11D, ctx->r17) = ctx->r2;
    // 0x80021904: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80021908: j           L_80021CC4
    // 0x8002190C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
        goto L_80021CC4;
    // 0x8002190C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
L_80021910:
    // 0x80021910: sw          $v0, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->r2;
L_80021914:
    // 0x80021914: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80021918: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8002191C: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80021920: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021924: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021928: lbu         $v0, -0x211D($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211D);
    // 0x8002192C: sb          $v0, 0x126($s1)
    MEM_B(0X126, ctx->r17) = ctx->r2;
    // 0x80021930: j           L_80021C84
    // 0x80021934: sb          $v0, 0x121($s1)
    MEM_B(0X121, ctx->r17) = ctx->r2;
        goto L_80021C84;
    // 0x80021934: sb          $v0, 0x121($s1)
    MEM_B(0X121, ctx->r17) = ctx->r2;
L_80021938:
    // 0x80021938: bne         $v1, $zero, L_80021CD8
    if (ctx->r3 != 0) {
        // 0x8002193C: nop
    
            goto L_80021CD8;
    }
    // 0x8002193C: nop

    // 0x80021940: lb          $s0, 0x127($s1)
    ctx->r16 = MEM_B(ctx->r17, 0X127);
    // 0x80021944: jal         0x80020EB4
    // 0x80021948: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80020EB4(rdram, ctx);
        goto after_2;
    // 0x80021948: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x8002194C: slt         $s0, $s0, $v0
    ctx->r16 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80021950: beq         $s0, $zero, L_80021AC0
    if (ctx->r16 == 0) {
        // 0x80021954: nop
    
            goto L_80021AC0;
    }
    // 0x80021954: nop

    // 0x80021958: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8002195C: lb          $a2, 0x129($s1)
    ctx->r6 = MEM_B(ctx->r17, 0X129);
    // 0x80021960: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021964: addu        $v1, $v0, $s3
    ctx->r3 = ADD32(ctx->r2, ctx->r19);
    // 0x80021968: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8002196C: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x80021970: lb          $a1, -0x2119($a1)
    ctx->r5 = MEM_B(ctx->r5, -0X2119);
    // 0x80021974: addiu       $v0, $a2, -0x3
    ctx->r2 = ADD32(ctx->r6, -0X3);
    // 0x80021978: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002197C: beq         $v0, $zero, L_80021CD8
    if (ctx->r2 == 0) {
        // 0x80021980: nop
    
            goto L_80021CD8;
    }
    // 0x80021980: nop

    // 0x80021984: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80021988: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8002198C: lbu         $a0, -0x211B($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X211B);
    // 0x80021990: lb          $v1, 0x128($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X128);
    // 0x80021994: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80021998: beq         $v0, $zero, L_80021A30
    if (ctx->r2 == 0) {
        // 0x8002199C: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80021A30;
    }
    // 0x8002199C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800219A0: sw          $v0, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->r2;
    // 0x800219A4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800219A8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800219AC: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800219B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800219B4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800219B8: lbu         $v0, -0x211B($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211B);
    // 0x800219BC: sb          $v0, 0x128($s1)
    MEM_B(0X128, ctx->r17) = ctx->r2;
    // 0x800219C0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800219C4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800219C8: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800219CC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800219D0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800219D4: lb          $v1, -0x2119($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X2119);
    // 0x800219D8: lb          $v0, 0x129($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X129);
    // 0x800219DC: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800219E0: beq         $v0, $zero, L_800219EC
    if (ctx->r2 == 0) {
        // 0x800219E4: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_800219EC;
    }
    // 0x800219E4: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x800219E8: sb          $a0, 0x129($s1)
    MEM_B(0X129, ctx->r17) = ctx->r4;
L_800219EC:
    // 0x800219EC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800219F0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800219F4: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800219F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800219FC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021A00: lbu         $v0, -0x211F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211F);
    // 0x80021A04: sb          $v0, 0x122($s1)
    MEM_B(0X122, ctx->r17) = ctx->r2;
    // 0x80021A08: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80021A0C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021A10: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80021A14: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021A18: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021A1C: lbu         $v0, -0x2120($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X2120);
    // 0x80021A20: sb          $v0, 0x11D($s1)
    MEM_B(0X11D, ctx->r17) = ctx->r2;
    // 0x80021A24: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80021A28: j           L_80021CC4
    // 0x80021A2C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
        goto L_80021CC4;
    // 0x80021A2C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
L_80021A30:
    // 0x80021A30: bne         $a0, $v1, L_80021CD8
    if (ctx->r4 != ctx->r3) {
        // 0x80021A34: slt         $v0, $a2, $a1
        ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80021CD8;
    }
    // 0x80021A34: slt         $v0, $a2, $a1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80021A38: beq         $v0, $zero, L_80021CD8
    if (ctx->r2 == 0) {
        // 0x80021A3C: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_80021CD8;
    }
    // 0x80021A3C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80021A40: sw          $v0, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->r2;
    // 0x80021A44: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80021A48: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021A4C: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80021A50: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021A54: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021A58: lbu         $v0, -0x211B($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211B);
    // 0x80021A5C: sb          $v0, 0x128($s1)
    MEM_B(0X128, ctx->r17) = ctx->r2;
    // 0x80021A60: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80021A64: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021A68: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80021A6C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021A70: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021A74: lbu         $v0, -0x2119($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X2119);
    // 0x80021A78: sb          $v0, 0x129($s1)
    MEM_B(0X129, ctx->r17) = ctx->r2;
    // 0x80021A7C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80021A80: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021A84: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80021A88: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021A8C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021A90: lbu         $v0, -0x211F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211F);
    // 0x80021A94: sb          $v0, 0x122($s1)
    MEM_B(0X122, ctx->r17) = ctx->r2;
    // 0x80021A98: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80021A9C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021AA0: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80021AA4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021AA8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021AAC: lbu         $v0, -0x2120($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X2120);
    // 0x80021AB0: sb          $v0, 0x11D($s1)
    MEM_B(0X11D, ctx->r17) = ctx->r2;
    // 0x80021AB4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80021AB8: j           L_80021CC4
    // 0x80021ABC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
        goto L_80021CC4;
    // 0x80021ABC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
L_80021AC0:
    // 0x80021AC0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80021AC4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021AC8: addu        $v1, $v0, $s3
    ctx->r3 = ADD32(ctx->r2, ctx->r19);
    // 0x80021ACC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80021AD0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80021AD4: lbu         $v0, -0x211B($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X211B);
    // 0x80021AD8: addiu       $v0, $v0, -0xB
    ctx->r2 = ADD32(ctx->r2, -0XB);
    // 0x80021ADC: sltiu       $v0, $v0, 0x7
    ctx->r2 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x80021AE0: beq         $v0, $zero, L_80021B98
    if (ctx->r2 == 0) {
        // 0x80021AE4: nop
    
            goto L_80021B98;
    }
    // 0x80021AE4: nop

    // 0x80021AE8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021AEC: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80021AF0: lbu         $v1, -0x211C($at)
    ctx->r3 = MEM_BU(ctx->r1, -0X211C);
    // 0x80021AF4: lb          $v0, 0x124($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X124);
    // 0x80021AF8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80021AFC: bne         $v0, $zero, L_80021B98
    if (ctx->r2 != 0) {
        // 0x80021B00: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_80021B98;
    }
    // 0x80021B00: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80021B04: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80021B08: sw          $v0, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->r2;
    // 0x80021B0C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80021B10: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021B14: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80021B18: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021B1C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021B20: lbu         $v0, -0x211C($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211C);
    // 0x80021B24: sb          $v0, 0x124($s1)
    MEM_B(0X124, ctx->r17) = ctx->r2;
    // 0x80021B28: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80021B2C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021B30: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80021B34: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021B38: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021B3C: lbu         $v0, -0x211E($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211E);
    // 0x80021B40: sb          $v0, 0x125($s1)
    MEM_B(0X125, ctx->r17) = ctx->r2;
    // 0x80021B44: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80021B48: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021B4C: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80021B50: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021B54: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021B58: lbu         $v0, -0x211F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211F);
    // 0x80021B5C: sb          $v0, 0x122($s1)
    MEM_B(0X122, ctx->r17) = ctx->r2;
    // 0x80021B60: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80021B64: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021B68: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80021B6C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021B70: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021B74: lbu         $v0, -0x2120($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X2120);
    // 0x80021B78: sb          $v0, 0x11D($s1)
    MEM_B(0X11D, ctx->r17) = ctx->r2;
    // 0x80021B7C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80021B80: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021B84: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80021B88: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021B8C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021B90: lbu         $v0, -0x211A($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211A);
    // 0x80021B94: sb          $v0, 0x120($s1)
    MEM_B(0X120, ctx->r17) = ctx->r2;
L_80021B98:
    // 0x80021B98: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80021B9C: lbu         $v1, 0x54($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X54);
    // 0x80021BA0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021BA4: addu        $a2, $v0, $s3
    ctx->r6 = ADD32(ctx->r2, ctx->r19);
    // 0x80021BA8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80021BAC: addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x80021BB0: lbu         $a1, -0x211B($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X211B);
    // 0x80021BB4: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80021BB8: sltiu       $v1, $v1, 0x2
    ctx->r3 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x80021BBC: sltiu       $v0, $a1, 0x4
    ctx->r2 = ctx->r5 < 0X4 ? 1 : 0;
    // 0x80021BC0: beq         $v1, $zero, L_80021BCC
    if (ctx->r3 == 0) {
        // 0x80021BC4: xori        $v0, $v0, 0x1
        ctx->r2 = ctx->r2 ^ 0X1;
            goto L_80021BCC;
    }
    // 0x80021BC4: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80021BC8: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_80021BCC:
    // 0x80021BCC: bne         $s5, $zero, L_80021CD8
    if (ctx->r21 != 0) {
        // 0x80021BD0: nop
    
            goto L_80021CD8;
    }
    // 0x80021BD0: nop

    // 0x80021BD4: lb          $a3, 0x127($s1)
    ctx->r7 = MEM_B(ctx->r17, 0X127);
    // 0x80021BD8: subu        $v0, $a3, $v0
    ctx->r2 = SUB32(ctx->r7, ctx->r2);
    // 0x80021BDC: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80021BE0: bne         $v0, $zero, L_80021CD8
    if (ctx->r2 != 0) {
        // 0x80021BE4: sltiu       $v0, $a1, 0x12
        ctx->r2 = ctx->r5 < 0X12 ? 1 : 0;
            goto L_80021CD8;
    }
    // 0x80021BE4: sltiu       $v0, $a1, 0x12
    ctx->r2 = ctx->r5 < 0X12 ? 1 : 0;
    // 0x80021BE8: beq         $v0, $zero, L_80021CD8
    if (ctx->r2 == 0) {
        // 0x80021BEC: nop
    
            goto L_80021CD8;
    }
    // 0x80021BEC: nop

    // 0x80021BF0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80021BF4: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x80021BF8: lbu         $a0, -0x211C($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X211C);
    // 0x80021BFC: lb          $v1, 0x124($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X124);
    // 0x80021C00: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80021C04: bnel        $v0, $zero, L_80021C3C
    if (ctx->r2 != 0) {
        // 0x80021C08: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_80021C3C;
    }
    goto skip_1;
    // 0x80021C08: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    skip_1:
    // 0x80021C0C: bne         $a0, $v1, L_80021CD8
    if (ctx->r4 != ctx->r3) {
        // 0x80021C10: nop
    
            goto L_80021CD8;
    }
    // 0x80021C10: nop

    // 0x80021C14: lb          $v0, 0x125($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X125);
    // 0x80021C18: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80021C1C: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x80021C20: lbu         $v1, -0x211E($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X211E);
    // 0x80021C24: addiu       $v0, $v0, -0x3
    ctx->r2 = ADD32(ctx->r2, -0X3);
    // 0x80021C28: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80021C2C: beq         $v1, $zero, L_80021CD8
    if (ctx->r3 == 0) {
        // 0x80021C30: slt         $v0, $a1, $a3
        ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80021CD8;
    }
    // 0x80021C30: slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80021C34: bne         $v0, $zero, L_80021CD8
    if (ctx->r2 != 0) {
        // 0x80021C38: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_80021CD8;
    }
    // 0x80021C38: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80021C3C:
    // 0x80021C3C: sw          $v0, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->r2;
    // 0x80021C40: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80021C44: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021C48: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80021C4C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021C50: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021C54: lbu         $v0, -0x211C($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211C);
    // 0x80021C58: sb          $v0, 0x124($s1)
    MEM_B(0X124, ctx->r17) = ctx->r2;
    // 0x80021C5C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80021C60: lb          $v1, 0x125($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X125);
    // 0x80021C64: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021C68: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80021C6C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021C70: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021C74: lbu         $v0, -0x211E($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211E);
    // 0x80021C78: slt         $v1, $v0, $v1
    ctx->r3 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80021C7C: bnel        $v1, $zero, L_80021C84
    if (ctx->r3 != 0) {
        // 0x80021C80: sb          $v0, 0x125($s1)
        MEM_B(0X125, ctx->r17) = ctx->r2;
            goto L_80021C84;
    }
    goto skip_2;
    // 0x80021C80: sb          $v0, 0x125($s1)
    MEM_B(0X125, ctx->r17) = ctx->r2;
    skip_2:
L_80021C84:
    // 0x80021C84: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80021C88: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021C8C: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80021C90: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021C94: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021C98: lbu         $v0, -0x211F($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211F);
    // 0x80021C9C: sb          $v0, 0x122($s1)
    MEM_B(0X122, ctx->r17) = ctx->r2;
    // 0x80021CA0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80021CA4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80021CA8: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80021CAC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021CB0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021CB4: lbu         $v0, -0x2120($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X2120);
    // 0x80021CB8: sb          $v0, 0x11D($s1)
    MEM_B(0X11D, ctx->r17) = ctx->r2;
    // 0x80021CBC: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80021CC0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
L_80021CC4:
    // 0x80021CC4: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80021CC8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80021CCC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80021CD0: lbu         $v0, -0x211A($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X211A);
    // 0x80021CD4: sb          $v0, 0x120($s1)
    MEM_B(0X120, ctx->r17) = ctx->r2;
L_80021CD8:
    // 0x80021CD8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80021CDC: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x80021CE0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80021CE4: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x80021CE8: slti        $v0, $v0, 0x40
    ctx->r2 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x80021CEC: bne         $v0, $zero, L_8002181C
    if (ctx->r2 != 0) {
        // 0x80021CF0: addu        $v1, $s6, $zero
        ctx->r3 = ADD32(ctx->r22, 0);
            goto L_8002181C;
    }
    // 0x80021CF0: addu        $v1, $s6, $zero
    ctx->r3 = ADD32(ctx->r22, 0);
L_80021CF4:
    // 0x80021CF4: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x80021CF8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80021CFC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80021D00: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80021D04: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80021D08: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80021D0C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80021D10: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80021D14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80021D18: jr          $ra
    // 0x80021D1C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80021D1C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80021D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021D20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021D24: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80021D28: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80021D2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021D30: lb          $v1, 0x11D($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X11D);
    // 0x80021D34: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80021D38: beq         $v1, $v0, L_80021EF0
    if (ctx->r3 == ctx->r2) {
        // 0x80021D3C: nop
    
            goto L_80021EF0;
    }
    // 0x80021D3C: nop

    // 0x80021D40: lb          $a0, 0x122($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X122);
    // 0x80021D44: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
    // 0x80021D48: bne         $a0, $v1, L_80021E74
    if (ctx->r4 != ctx->r3) {
        // 0x80021D4C: sw          $zero, 0x114($s0)
        MEM_W(0X114, ctx->r16) = 0;
            goto L_80021E74;
    }
    // 0x80021D4C: sw          $zero, 0x114($s0)
    MEM_W(0X114, ctx->r16) = 0;
    // 0x80021D50: lb          $v1, 0x11D($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X11D);
    // 0x80021D54: lb          $v0, 0x4C($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X4C);
    // 0x80021D58: beq         $v1, $v0, L_80021D68
    if (ctx->r3 == ctx->r2) {
        // 0x80021D5C: nop
    
            goto L_80021D68;
    }
    // 0x80021D5C: nop

    // 0x80021D60: lhu         $v0, 0x82($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X82);
    // 0x80021D64: sw          $v0, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->r2;
L_80021D68:
    // 0x80021D68: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80021D6C: lb          $v0, 0x2($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2);
    // 0x80021D70: beq         $v0, $zero, L_80021E68
    if (ctx->r2 == 0) {
        // 0x80021D74: nop
    
            goto L_80021E68;
    }
    // 0x80021D74: nop

    // 0x80021D78: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80021D7C: lbu         $v0, 0x2076($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2076);
    // 0x80021D80: beq         $v0, $zero, L_80021DB4
    if (ctx->r2 == 0) {
        // 0x80021D84: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80021DB4;
    }
    // 0x80021D84: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80021D88: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80021D8C: lbu         $v1, 0x7B9A($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B9A);
    // 0x80021D90: bne         $v1, $v0, L_80021DB4
    if (ctx->r3 != ctx->r2) {
        // 0x80021D94: nop
    
            goto L_80021DB4;
    }
    // 0x80021D94: nop

    // 0x80021D98: jal         0x80020E30
    // 0x80021D9C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80020E30(rdram, ctx);
        goto after_0;
    // 0x80021D9C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80021DA0: beq         $v0, $zero, L_80021DB4
    if (ctx->r2 == 0) {
        // 0x80021DA4: nop
    
            goto L_80021DB4;
    }
    // 0x80021DA4: nop

    // 0x80021DA8: lb          $v0, 0x121($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X121);
    // 0x80021DAC: bne         $v0, $zero, L_80021EF0
    if (ctx->r2 != 0) {
        // 0x80021DB0: nop
    
            goto L_80021EF0;
    }
    // 0x80021DB0: nop

L_80021DB4:
    // 0x80021DB4: lb          $v0, 0x120($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X120);
    // 0x80021DB8: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80021DBC: bne         $v0, $zero, L_80021DF0
    if (ctx->r2 != 0) {
        // 0x80021DC0: nop
    
            goto L_80021DF0;
    }
    // 0x80021DC0: nop

    // 0x80021DC4: lbu         $v0, 0x55($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X55);
    // 0x80021DC8: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80021DCC: beq         $v0, $zero, L_80021DF0
    if (ctx->r2 == 0) {
        // 0x80021DD0: nop
    
            goto L_80021DF0;
    }
    // 0x80021DD0: nop

    // 0x80021DD4: lb          $v0, 0x54($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X54);
    // 0x80021DD8: beq         $v0, $zero, L_80021DF0
    if (ctx->r2 == 0) {
        // 0x80021DDC: nop
    
            goto L_80021DF0;
    }
    // 0x80021DDC: nop

    // 0x80021DE0: lb          $v1, 0xCC($s0)
    ctx->r3 = MEM_B(ctx->r16, 0XCC);
    // 0x80021DE4: lb          $v0, 0xCD($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XCD);
    // 0x80021DE8: beq         $v1, $v0, L_80021DFC
    if (ctx->r3 == ctx->r2) {
        // 0x80021DEC: nop
    
            goto L_80021DFC;
    }
    // 0x80021DEC: nop

L_80021DF0:
    // 0x80021DF0: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x80021DF4: j           L_80021EEC
    // 0x80021DF8: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
        goto L_80021EEC;
    // 0x80021DF8: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
L_80021DFC:
    // 0x80021DFC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80021E00: lbu         $v0, 0x7B7C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B7C);
    // 0x80021E04: bne         $v0, $zero, L_80021E2C
    if (ctx->r2 != 0) {
        // 0x80021E08: nop
    
            goto L_80021E2C;
    }
    // 0x80021E08: nop

    // 0x80021E0C: lb          $v1, 0x11D($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X11D);
    // 0x80021E10: lb          $v0, 0x4C($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X4C);
    // 0x80021E14: bne         $v1, $v0, L_80021E2C
    if (ctx->r3 != ctx->r2) {
        // 0x80021E18: nop
    
            goto L_80021E2C;
    }
    // 0x80021E18: nop

    // 0x80021E1C: lhu         $v1, 0x80($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X80);
    // 0x80021E20: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x80021E24: j           L_80021EEC
    // 0x80021E28: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
        goto L_80021EEC;
    // 0x80021E28: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
L_80021E2C:
    // 0x80021E2C: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80021E30: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80021E34: sb          $v1, 0x11C($v0)
    MEM_B(0X11C, ctx->r2) = ctx->r3;
    // 0x80021E38: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80021E3C: lbu         $v0, 0x2076($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2076);
    // 0x80021E40: beq         $v0, $zero, L_80021E5C
    if (ctx->r2 == 0) {
        // 0x80021E44: nop
    
            goto L_80021E5C;
    }
    // 0x80021E44: nop

    // 0x80021E48: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80021E4C: lbu         $v1, 0x7B9A($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B9A);
    // 0x80021E50: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80021E54: beq         $v1, $v0, L_80021EF0
    if (ctx->r3 == ctx->r2) {
        // 0x80021E58: nop
    
            goto L_80021EF0;
    }
    // 0x80021E58: nop

L_80021E5C:
    // 0x80021E5C: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x80021E60: j           L_80021EEC
    // 0x80021E64: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
        goto L_80021EEC;
    // 0x80021E64: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
L_80021E68:
    // 0x80021E68: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x80021E6C: j           L_80021EEC
    // 0x80021E70: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
        goto L_80021EEC;
    // 0x80021E70: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
L_80021E74:
    // 0x80021E74: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80021E78: beq         $v0, $zero, L_80021EB4
    if (ctx->r2 == 0) {
        // 0x80021E7C: slt         $v0, $v1, $a0
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80021EB4;
    }
    // 0x80021E7C: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80021E80: lw          $v0, 0x118($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X118);
    // 0x80021E84: beq         $v0, $zero, L_80021EA8
    if (ctx->r2 == 0) {
        // 0x80021E88: nop
    
            goto L_80021EA8;
    }
    // 0x80021E88: nop

    // 0x80021E8C: lb          $v1, 0x11D($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X11D);
    // 0x80021E90: lb          $v0, 0x4C($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X4C);
    // 0x80021E94: beq         $v1, $v0, L_80021EA8
    if (ctx->r3 == ctx->r2) {
        // 0x80021E98: nop
    
            goto L_80021EA8;
    }
    // 0x80021E98: nop

    // 0x80021E9C: lhu         $v0, 0x82($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X82);
    // 0x80021EA0: j           L_80021EEC
    // 0x80021EA4: sw          $zero, 0x118($s0)
    MEM_W(0X118, ctx->r16) = 0;
        goto L_80021EEC;
    // 0x80021EA4: sw          $zero, 0x118($s0)
    MEM_W(0X118, ctx->r16) = 0;
L_80021EA8:
    // 0x80021EA8: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x80021EAC: j           L_80021EEC
    // 0x80021EB0: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
        goto L_80021EEC;
    // 0x80021EB0: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
L_80021EB4:
    // 0x80021EB4: beq         $v0, $zero, L_80021EF0
    if (ctx->r2 == 0) {
        // 0x80021EB8: nop
    
            goto L_80021EF0;
    }
    // 0x80021EB8: nop

    // 0x80021EBC: lw          $v0, 0x118($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X118);
    // 0x80021EC0: beq         $v0, $zero, L_80021EE4
    if (ctx->r2 == 0) {
        // 0x80021EC4: nop
    
            goto L_80021EE4;
    }
    // 0x80021EC4: nop

    // 0x80021EC8: lb          $v1, 0x11D($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X11D);
    // 0x80021ECC: lb          $v0, 0x4C($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X4C);
    // 0x80021ED0: beq         $v1, $v0, L_80021EE4
    if (ctx->r3 == ctx->r2) {
        // 0x80021ED4: nop
    
            goto L_80021EE4;
    }
    // 0x80021ED4: nop

    // 0x80021ED8: lhu         $v0, 0x82($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X82);
    // 0x80021EDC: j           L_80021EEC
    // 0x80021EE0: sw          $zero, 0x118($s0)
    MEM_W(0X118, ctx->r16) = 0;
        goto L_80021EEC;
    // 0x80021EE0: sw          $zero, 0x118($s0)
    MEM_W(0X118, ctx->r16) = 0;
L_80021EE4:
    // 0x80021EE4: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x80021EE8: ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
L_80021EEC:
    // 0x80021EEC: sw          $v0, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->r2;
L_80021EF0:
    // 0x80021EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021EF4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80021EF8: jr          $ra
    // 0x80021EFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80021EFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80021F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021F00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80021F04: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80021F08: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80021F0C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80021F10: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80021F14: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80021F18: jal         0x80020A38
    // 0x80021F1C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    func_80020A38(rdram, ctx);
        goto after_0;
    // 0x80021F1C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // 0x80021F20: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80021F24: jal         0x80020818
    // 0x80021F28: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    func_80020818(rdram, ctx);
        goto after_1;
    // 0x80021F28: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80021F2C: lb          $v1, 0x54($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X54);
    // 0x80021F30: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80021F34: slti        $v0, $v1, 0x1F
    ctx->r2 = SIGNED(ctx->r3) < 0X1F ? 1 : 0;
    // 0x80021F38: bne         $v0, $zero, L_80021F48
    if (ctx->r2 != 0) {
        // 0x80021F3C: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_80021F48;
    }
    // 0x80021F3C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80021F40: j           L_80021F4C
    // 0x80021F44: slti        $v0, $s1, 0xC
    ctx->r2 = SIGNED(ctx->r17) < 0XC ? 1 : 0;
        goto L_80021F4C;
    // 0x80021F44: slti        $v0, $s1, 0xC
    ctx->r2 = SIGNED(ctx->r17) < 0XC ? 1 : 0;
L_80021F48:
    // 0x80021F48: slti        $v0, $s1, 0x5
    ctx->r2 = SIGNED(ctx->r17) < 0X5 ? 1 : 0;
L_80021F4C:
    // 0x80021F4C: bne         $v0, $zero, L_80021F8C
    if (ctx->r2 != 0) {
        // 0x80021F50: slti        $v0, $v1, 0x21
        ctx->r2 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
            goto L_80021F8C;
    }
    // 0x80021F50: slti        $v0, $v1, 0x21
    ctx->r2 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
    // 0x80021F54: beq         $v0, $zero, L_80021F8C
    if (ctx->r2 == 0) {
        // 0x80021F58: nop
    
            goto L_80021F8C;
    }
    // 0x80021F58: nop

    // 0x80021F5C: jal         0x800176CC
    // 0x80021F60: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800176CC(rdram, ctx);
        goto after_2;
    // 0x80021F60: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80021F64: bne         $v0, $zero, L_80021F8C
    if (ctx->r2 != 0) {
        // 0x80021F68: nop
    
            goto L_80021F8C;
    }
    // 0x80021F68: nop

    // 0x80021F6C: jal         0x80021FFC
    // 0x80021F70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80021FFC(rdram, ctx);
        goto after_3;
    // 0x80021F70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80021F74: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80021F78: bnel        $v0, $zero, L_80021FDC
    if (ctx->r2 != 0) {
        // 0x80021F7C: addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
            goto L_80021FDC;
    }
    goto skip_0;
    // 0x80021F7C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    skip_0:
    // 0x80021F80: lb          $v0, 0x54($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X54);
    // 0x80021F84: bnel        $v0, $zero, L_80021FDC
    if (ctx->r2 != 0) {
        // 0x80021F88: addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
            goto L_80021FDC;
    }
    goto skip_1;
    // 0x80021F88: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    skip_1:
L_80021F8C:
    // 0x80021F8C: jal         0x80021FFC
    // 0x80021F90: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80021FFC(rdram, ctx);
        goto after_4;
    // 0x80021F90: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x80021F94: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80021F98: bne         $v0, $zero, L_80021FE0
    if (ctx->r2 != 0) {
        // 0x80021F9C: addu        $v0, $s2, $zero
        ctx->r2 = ADD32(ctx->r18, 0);
            goto L_80021FE0;
    }
    // 0x80021F9C: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x80021FA0: lb          $v0, 0x54($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X54);
    // 0x80021FA4: sltu        $v1, $zero, $s3
    ctx->r3 = 0 < ctx->r19 ? 1 : 0;
    // 0x80021FA8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80021FAC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80021FB0: beq         $v0, $zero, L_80021FDC
    if (ctx->r2 == 0) {
        // 0x80021FB4: slti        $v0, $s1, 0x7
        ctx->r2 = SIGNED(ctx->r17) < 0X7 ? 1 : 0;
            goto L_80021FDC;
    }
    // 0x80021FB4: slti        $v0, $s1, 0x7
    ctx->r2 = SIGNED(ctx->r17) < 0X7 ? 1 : 0;
    // 0x80021FB8: bne         $v0, $zero, L_80021FE0
    if (ctx->r2 != 0) {
        // 0x80021FBC: addu        $v0, $s2, $zero
        ctx->r2 = ADD32(ctx->r18, 0);
            goto L_80021FE0;
    }
    // 0x80021FBC: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x80021FC0: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x80021FC4: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x80021FC8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80021FCC: lui         $v1, 0x2121
    ctx->r3 = S32(0X2121 << 16);
    // 0x80021FD0: beq         $v0, $v1, L_80021FE0
    if (ctx->r2 == ctx->r3) {
        // 0x80021FD4: addu        $v0, $s2, $zero
        ctx->r2 = ADD32(ctx->r18, 0);
            goto L_80021FE0;
    }
    // 0x80021FD4: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x80021FD8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80021FDC:
    // 0x80021FDC: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_80021FE0:
    // 0x80021FE0: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80021FE4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80021FE8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80021FEC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80021FF0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80021FF4: jr          $ra
    // 0x80021FF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80021FF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80021FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021FFC: lw          $a2, 0x110($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X110);
    // 0x80022000: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80022004: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80022008: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
L_8002200C:
    // 0x8002200C: lbu         $v0, 0x6F($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X6F);
    // 0x80022010: beq         $v0, $zero, L_80022030
    if (ctx->r2 == 0) {
        // 0x80022014: nop
    
            goto L_80022030;
    }
    // 0x80022014: nop

    // 0x80022018: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x8002201C: bnel        $v0, $zero, L_80022040
    if (ctx->r2 != 0) {
        // 0x80022020: addiu       $v1, $a2, 0x144
        ctx->r3 = ADD32(ctx->r6, 0X144);
            goto L_80022040;
    }
    goto skip_0;
    // 0x80022020: addiu       $v1, $a2, 0x144
    ctx->r3 = ADD32(ctx->r6, 0X144);
    skip_0:
    // 0x80022024: lbu         $v0, 0x71($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X71);
    // 0x80022028: bne         $v0, $zero, L_80022058
    if (ctx->r2 != 0) {
        // 0x8002202C: addiu       $v0, $zero, 0x12
        ctx->r2 = ADD32(0, 0X12);
            goto L_80022058;
    }
    // 0x8002202C: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80022030:
    // 0x80022030: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x80022034: beq         $v0, $zero, L_80022048
    if (ctx->r2 == 0) {
        // 0x80022038: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80022048;
    }
    // 0x80022038: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002203C: addiu       $v1, $a2, 0x144
    ctx->r3 = ADD32(ctx->r6, 0X144);
L_80022040:
    // 0x80022040: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80022044: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80022048:
    // 0x80022048: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x8002204C: bne         $v0, $zero, L_8002200C
    if (ctx->r2 != 0) {
        // 0x80022050: addiu       $v1, $v1, 0x12
        ctx->r3 = ADD32(ctx->r3, 0X12);
            goto L_8002200C;
    }
    // 0x80022050: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80022054: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80022058:
    // 0x80022058: beq         $a1, $v0, L_800220BC
    if (ctx->r5 == ctx->r2) {
        // 0x8002205C: nop
    
            goto L_800220BC;
    }
    // 0x8002205C: nop

    // 0x80022060: lw          $v0, 0x110($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X110);
    // 0x80022064: sll         $v1, $a1, 3
    ctx->r3 = S32(ctx->r5 << 3);
    // 0x80022068: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8002206C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80022070: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80022074: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80022078: lbu         $v0, 0x6F($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X6F);
    // 0x8002207C: j           L_800220A0
    // 0x80022080: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
        goto L_800220A0;
    // 0x80022080: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80022084:
    // 0x80022084: lbu         $v0, 0x71($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X71);
    // 0x80022088: beq         $v0, $zero, L_800220B4
    if (ctx->r2 == 0) {
        // 0x8002208C: slt         $v0, $a3, $a1
        ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_800220B4;
    }
    // 0x8002208C: slt         $v0, $a3, $a1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80022090: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80022094: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80022098: lbu         $v0, 0x6F($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X6F);
    // 0x8002209C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800220A0:
    // 0x800220A0: beq         $v0, $zero, L_800220B4
    if (ctx->r2 == 0) {
        // 0x800220A4: slt         $v0, $a3, $a1
        ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_800220B4;
    }
    // 0x800220A4: slt         $v0, $a3, $a1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800220A8: lbu         $v0, 0x70($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X70);
    // 0x800220AC: beq         $v0, $zero, L_80022084
    if (ctx->r2 == 0) {
        // 0x800220B0: slt         $v0, $a3, $a1
        ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80022084;
    }
    // 0x800220B0: slt         $v0, $a3, $a1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
L_800220B4:
    // 0x800220B4: bnel        $v0, $zero, L_800220BC
    if (ctx->r2 != 0) {
        // 0x800220B8: addu        $a3, $a1, $zero
        ctx->r7 = ADD32(ctx->r5, 0);
            goto L_800220BC;
    }
    goto skip_1;
    // 0x800220B8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    skip_1:
L_800220BC:
    // 0x800220BC: jr          $ra
    // 0x800220C0: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    return;
    // 0x800220C0: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
;}
RECOMP_FUNC void func_800220C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800220C4: lb          $v1, 0x54($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X54);
    // 0x800220C8: lw          $v0, 0xDC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XDC);
    // 0x800220CC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800220D0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800220D4: lb          $v0, 0x4C($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X4C);
    // 0x800220D8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800220DC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800220E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800220E4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800220E8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800220EC: addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
L_800220F0:
    // 0x800220F0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800220F4: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
L_800220F8:
    // 0x800220F8: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x800220FC: beq         $v0, $zero, L_8002210C
    if (ctx->r2 == 0) {
        // 0x80022100: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8002210C;
    }
    // 0x80022100: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80022104: j           L_8002213C
    // 0x80022108: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
        goto L_8002213C;
    // 0x80022108: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
L_8002210C:
    // 0x8002210C: slti        $v0, $a1, 0x5
    ctx->r2 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x80022110: bne         $v0, $zero, L_800220F8
    if (ctx->r2 != 0) {
        // 0x80022114: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800220F8;
    }
    // 0x80022114: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80022118: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8002211C: slti        $v0, $a2, 0x5
    ctx->r2 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
    // 0x80022120: bne         $v0, $zero, L_800220F0
    if (ctx->r2 != 0) {
        // 0x80022124: addiu       $a3, $a3, 0x5
        ctx->r7 = ADD32(ctx->r7, 0X5);
            goto L_800220F0;
    }
    // 0x80022124: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    // 0x80022128: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8002212C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80022130: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80022134: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80022138: lb          $a2, 0x0($v0)
    ctx->r6 = MEM_B(ctx->r2, 0X0);
L_8002213C:
    // 0x8002213C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80022140: lb          $t0, 0x54($a0)
    ctx->r8 = MEM_B(ctx->r4, 0X54);
    // 0x80022144: addiu       $t1, $zero, 0x21
    ctx->r9 = ADD32(0, 0X21);
    // 0x80022148: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8002214C:
    // 0x8002214C: bne         $t0, $t1, L_80022164
    if (ctx->r8 != ctx->r9) {
        // 0x80022150: nop
    
            goto L_80022164;
    }
    // 0x80022150: nop

    // 0x80022154: lw          $v0, 0x110($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X110);
    // 0x80022158: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x8002215C: j           L_8002217C
    // 0x80022160: lbu         $v0, 0x74($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X74);
        goto L_8002217C;
    // 0x80022160: lbu         $v0, 0x74($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X74);
L_80022164:
    // 0x80022164: lw          $v0, 0x110($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X110);
    // 0x80022168: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x8002216C: lbu         $v0, 0x74($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X74);
    // 0x80022170: beq         $v0, $a2, L_8002219C
    if (ctx->r2 == ctx->r6) {
        // 0x80022174: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002219C;
    }
    // 0x80022174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80022178: lbu         $v0, 0x75($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X75);
L_8002217C:
    // 0x8002217C: bnel        $v0, $a2, L_8002218C
    if (ctx->r2 != ctx->r6) {
        // 0x80022180: addiu       $a3, $a3, -0x1
        ctx->r7 = ADD32(ctx->r7, -0X1);
            goto L_8002218C;
    }
    goto skip_0;
    // 0x80022180: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    skip_0:
    // 0x80022184: j           L_8002219C
    // 0x80022188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002219C;
    // 0x80022188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002218C:
    // 0x8002218C: slti        $v0, $a3, -0x5
    ctx->r2 = SIGNED(ctx->r7) < -0X5 ? 1 : 0;
    // 0x80022190: beq         $v0, $zero, L_8002214C
    if (ctx->r2 == 0) {
        // 0x80022194: addiu       $a1, $a1, -0x12
        ctx->r5 = ADD32(ctx->r5, -0X12);
            goto L_8002214C;
    }
    // 0x80022194: addiu       $a1, $a1, -0x12
    ctx->r5 = ADD32(ctx->r5, -0X12);
    // 0x80022198: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8002219C:
    // 0x8002219C: jr          $ra
    // 0x800221A0: nop

    return;
    // 0x800221A0: nop

;}
RECOMP_FUNC void func_800221B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800221B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800221B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800221B8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800221BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800221C0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800221C4: addiu       $a1, $a1, -0x2BF0
    ctx->r5 = ADD32(ctx->r5, -0X2BF0);
    // 0x800221C8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800221CC: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x800221D0: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    // 0x800221D4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800221D8: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800221DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800221E0: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x800221E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800221E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800221EC: lhu         $v0, 0x82($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X82);
    // 0x800221F0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800221F4: lhu         $v0, 0x82($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X82);
    // 0x800221F8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800221FC: lhu         $v0, 0x84($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X84);
    // 0x80022200: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80022204: lb          $v0, 0x11D($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X11D);
    // 0x80022208: bne         $v0, $zero, L_80022250
    if (ctx->r2 != 0) {
        // 0x8002220C: nop
    
            goto L_80022250;
    }
    // 0x8002220C: nop

    // 0x80022210: lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5);
    // 0x80022214: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80022218: addiu       $v1, $v1, -0x1D20
    ctx->r3 = ADD32(ctx->r3, -0X1D20);
    // 0x8002221C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80022220: beq         $v0, $zero, L_80022230
    if (ctx->r2 == 0) {
        // 0x80022224: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80022230;
    }
    // 0x80022224: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80022228: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8002222C: addiu       $v1, $v1, -0x2740
    ctx->r3 = ADD32(ctx->r3, -0X2740);
L_80022230:
    // 0x80022230: jal         0x80014614
    // 0x80022234: sw          $v1, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r3;
    func_80014614(rdram, ctx);
        goto after_0;
    // 0x80022234: sw          $v1, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r3;
    after_0:
    // 0x80022238: lbu         $v1, 0x11D($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X11D);
    // 0x8002223C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80022240: sb          $v0, 0x128($s0)
    MEM_B(0X128, ctx->r16) = ctx->r2;
    // 0x80022244: sb          $zero, 0x129($s0)
    MEM_B(0X129, ctx->r16) = 0;
    // 0x80022248: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002224C: sb          $v1, 0x11D($s0)
    MEM_B(0X11D, ctx->r16) = ctx->r3;
L_80022250:
    // 0x80022250: lb          $v1, 0x11F($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X11F);
    // 0x80022254: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x80022258: beq         $v0, $zero, L_8002256C
    if (ctx->r2 == 0) {
        // 0x8002225C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8002256C;
    }
    // 0x8002225C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80022260: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022264: addu        $at, $at, $v0
    gpr jr_addend_8002226C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80022268: lw          $v0, -0x2BE0($at)
    ctx->r2 = ADD32(ctx->r1, -0X2BE0);
    // 0x8002226C: jr          $v0
    // 0x80022270: nop

    switch (jr_addend_8002226C >> 2) {
        case 0: goto L_80022274; break;
        case 1: goto L_8002252C; break;
        case 2: goto L_8002253C; break;
        case 3: goto L_8002254C; break;
        case 4: goto L_80022564; break;
        case 5: goto L_8002256C; break;
        default: switch_error(__func__, 0x8002226C, 0x800AD420);
    }
    // 0x80022270: nop

L_80022274:
    // 0x80022274: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80022278: lbu         $v0, 0x2330($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2330);
    // 0x8002227C: beq         $v0, $zero, L_80022320
    if (ctx->r2 == 0) {
        // 0x80022280: nop
    
            goto L_80022320;
    }
    // 0x80022280: nop

    // 0x80022284: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80022288: sb          $zero, 0x2330($at)
    MEM_B(0X2330, ctx->r1) = 0;
    // 0x8002228C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80022290: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80022294: addiu       $t2, $t2, 0x43C0
    ctx->r10 = ADD32(ctx->r10, 0X43C0);
    // 0x80022298: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8002229C: addiu       $t1, $t1, 0x45B8
    ctx->r9 = ADD32(ctx->r9, 0X45B8);
    // 0x800222A0: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x800222A4: addiu       $t0, $t0, 0x47B0
    ctx->r8 = ADD32(ctx->r8, 0X47B0);
    // 0x800222A8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_800222AC:
    // 0x800222AC: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x800222B0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800222B4:
    // 0x800222B4: lw          $v0, 0xB0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB0);
    // 0x800222B8: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800222BC: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800222C0: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800222C4: addu        $v0, $a1, $t2
    ctx->r2 = ADD32(ctx->r5, ctx->r10);
    // 0x800222C8: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x800222CC: lw          $v0, 0xB0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB0);
    // 0x800222D0: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800222D4: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800222D8: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800222DC: addu        $v0, $a1, $t1
    ctx->r2 = ADD32(ctx->r5, ctx->r9);
    // 0x800222E0: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x800222E4: lw          $v0, 0xB0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB0);
    // 0x800222E8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800222EC: addu        $v1, $a1, $t0
    ctx->r3 = ADD32(ctx->r5, ctx->r8);
    // 0x800222F0: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800222F4: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800222F8: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800222FC: addiu       $a1, $a1, 0x12
    ctx->r5 = ADD32(ctx->r5, 0X12);
    // 0x80022300: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80022304: slti        $v0, $a3, 0x1C
    ctx->r2 = SIGNED(ctx->r7) < 0X1C ? 1 : 0;
    // 0x80022308: bne         $v0, $zero, L_800222B4
    if (ctx->r2 != 0) {
        // 0x8002230C: addiu       $a0, $a0, 0x12
        ctx->r4 = ADD32(ctx->r4, 0X12);
            goto L_800222B4;
    }
    // 0x8002230C: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    // 0x80022310: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80022314: slti        $v0, $a2, 0x12
    ctx->r2 = SIGNED(ctx->r6) < 0X12 ? 1 : 0;
    // 0x80022318: bnel        $v0, $zero, L_800222AC
    if (ctx->r2 != 0) {
        // 0x8002231C: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_800222AC;
    }
    goto skip_0;
    // 0x8002231C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    skip_0:
L_80022320:
    // 0x80022320: lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5);
    // 0x80022324: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80022328: beq         $v0, $zero, L_8002234C
    if (ctx->r2 == 0) {
        // 0x8002232C: nop
    
            goto L_8002234C;
    }
    // 0x8002232C: nop

    // 0x80022330: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80022334: addiu       $v0, $v0, -0x2740
    ctx->r2 = ADD32(ctx->r2, -0X2740);
    // 0x80022338: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002233C: sw          $v0, 0x43A8($at)
    MEM_W(0X43A8, ctx->r1) = ctx->r2;
    // 0x80022340: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80022344: j           L_80022364
    // 0x80022348: addiu       $v0, $v0, 0xE10
    ctx->r2 = ADD32(ctx->r2, 0XE10);
        goto L_80022364;
    // 0x80022348: addiu       $v0, $v0, 0xE10
    ctx->r2 = ADD32(ctx->r2, 0XE10);
L_8002234C:
    // 0x8002234C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80022350: addiu       $v0, $v0, -0x1D20
    ctx->r2 = ADD32(ctx->r2, -0X1D20);
    // 0x80022354: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80022358: sw          $v0, 0x43A8($at)
    MEM_W(0X43A8, ctx->r1) = ctx->r2;
    // 0x8002235C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80022360: addiu       $v0, $v0, -0x34C8
    ctx->r2 = ADD32(ctx->r2, -0X34C8);
L_80022364:
    // 0x80022364: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80022368: sw          $v0, 0x43AC($at)
    MEM_W(0X43AC, ctx->r1) = ctx->r2;
    // 0x8002236C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80022370: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022374: addiu       $v0, $v0, 0x43C0
    ctx->r2 = ADD32(ctx->r2, 0X43C0);
    // 0x80022378: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002237C: sw          $v0, 0x43B0($at)
    MEM_W(0X43B0, ctx->r1) = ctx->r2;
    // 0x80022380: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022384: addiu       $v0, $v0, 0x45B8
    ctx->r2 = ADD32(ctx->r2, 0X45B8);
    // 0x80022388: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002238C: sw          $v0, 0x43B4($at)
    MEM_W(0X43B4, ctx->r1) = ctx->r2;
    // 0x80022390: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022394: addiu       $v0, $v0, 0x47B0
    ctx->r2 = ADD32(ctx->r2, 0X47B0);
    // 0x80022398: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002239C: sw          $v0, 0x43B8($at)
    MEM_W(0X43B8, ctx->r1) = ctx->r2;
    // 0x800223A0: jal         0x800254E4
    // 0x800223A4: sb          $zero, 0x122($s0)
    MEM_B(0X122, ctx->r16) = 0;
    func_800254E4(rdram, ctx);
        goto after_1;
    // 0x800223A4: sb          $zero, 0x122($s0)
    MEM_B(0X122, ctx->r16) = 0;
    after_1:
    // 0x800223A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800223AC: jal         0x80023A14
    // 0x800223B0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80023A14(rdram, ctx);
        goto after_2;
    // 0x800223B0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x800223B4: lb          $v0, 0x125($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X125);
    // 0x800223B8: slti        $v0, $v0, 0xF
    ctx->r2 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x800223BC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800223C0: bne         $v0, $zero, L_800224E4
    if (ctx->r2 != 0) {
        // 0x800223C4: sb          $v0, 0x12A($s0)
        MEM_B(0X12A, ctx->r16) = ctx->r2;
            goto L_800224E4;
    }
    // 0x800223C4: sb          $v0, 0x12A($s0)
    MEM_B(0X12A, ctx->r16) = ctx->r2;
    // 0x800223C8: lw          $v0, 0x138($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X138);
    // 0x800223CC: lb          $v1, 0x123($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X123);
    // 0x800223D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800223D4: beq         $v1, $zero, L_800224E4
    if (ctx->r3 == 0) {
        // 0x800223D8: sw          $v0, 0x138($s0)
        MEM_W(0X138, ctx->r16) = ctx->r2;
            goto L_800224E4;
    }
    // 0x800223D8: sw          $v0, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r2;
    // 0x800223DC: lbu         $v0, 0x54($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X54);
    // 0x800223E0: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800223E4: lb          $v1, 0x4354($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X4354);
    // 0x800223E8: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800223EC: bne         $v0, $v1, L_800224E8
    if (ctx->r2 != ctx->r3) {
        // 0x800223F0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800224E8;
    }
    // 0x800223F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800223F4: lw          $v1, 0xDC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XDC);
    // 0x800223F8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800223FC: lw          $v0, 0x4350($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4350);
    // 0x80022400: bnel        $v1, $v0, L_800224EC
    if (ctx->r3 != ctx->r2) {
        // 0x80022404: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800224EC;
    }
    goto skip_1;
    // 0x80022404: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    skip_1:
    // 0x80022408: lbu         $v0, 0x55($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X55);
    // 0x8002240C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80022410: lb          $v1, 0x435C($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X435C);
    // 0x80022414: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80022418: bnel        $v0, $v1, L_800224EC
    if (ctx->r2 != ctx->r3) {
        // 0x8002241C: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800224EC;
    }
    goto skip_2;
    // 0x8002241C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    skip_2:
    // 0x80022420: lw          $v1, 0xE0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XE0);
    // 0x80022424: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022428: lw          $v0, 0x4358($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4358);
    // 0x8002242C: bnel        $v1, $v0, L_800224EC
    if (ctx->r3 != ctx->r2) {
        // 0x80022430: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800224EC;
    }
    goto skip_3;
    // 0x80022430: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    skip_3:
    // 0x80022434: lbu         $v0, 0x63($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X63);
    // 0x80022438: lb          $v1, 0x124($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X124);
    // 0x8002243C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80022440: bnel        $v0, $zero, L_800224EC
    if (ctx->r2 != 0) {
        // 0x80022444: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800224EC;
    }
    goto skip_4;
    // 0x80022444: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    skip_4:
    // 0x80022448: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002244C: lb          $v0, 0x436D($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X436D);
    // 0x80022450: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80022454: bne         $v0, $a2, L_8002246C
    if (ctx->r2 != ctx->r6) {
        // 0x80022458: nop
    
            goto L_8002246C;
    }
    // 0x80022458: nop

    // 0x8002245C: lb          $v1, 0xCC($s0)
    ctx->r3 = MEM_B(ctx->r16, 0XCC);
    // 0x80022460: lb          $v0, 0xCD($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XCD);
    // 0x80022464: beql        $v1, $v0, L_800224EC
    if (ctx->r3 == ctx->r2) {
        // 0x80022468: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800224EC;
    }
    goto skip_5;
    // 0x80022468: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    skip_5:
L_8002246C:
    // 0x8002246C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022470: lw          $v0, 0x40CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X40CC);
    // 0x80022474: bne         $v0, $zero, L_800224E8
    if (ctx->r2 != 0) {
        // 0x80022478: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800224E8;
    }
    // 0x80022478: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8002247C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80022480: addiu       $a1, $a1, 0x4366
    ctx->r5 = ADD32(ctx->r5, 0X4366);
    // 0x80022484: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80022488: addiu       $a0, $a0, 0x435E
    ctx->r4 = ADD32(ctx->r4, 0X435E);
    // 0x8002248C: lwl         $v0, 0x0($a1)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r5, 0X0);
    // 0x80022490: lwr         $v0, 0x3($a1)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r5, 0X3);
    // 0x80022494: lwl         $v1, 0x4($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r5, 0X4);
    // 0x80022498: lwr         $v1, 0x7($a1)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r5, 0X7);
    // 0x8002249C: swl         $v0, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, ctx->r2);
    // 0x800224A0: swr         $v0, 0x3($a0)
    do_swr(rdram, 0X3, ctx->r4, ctx->r2);
    // 0x800224A4: swl         $v1, 0x4($a0)
    do_swl(rdram, 0X4, ctx->r4, ctx->r3);
    // 0x800224A8: swr         $v1, 0x7($a0)
    do_swr(rdram, 0X7, ctx->r4, ctx->r3);
    // 0x800224AC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800224B0: lbu         $v0, 0x4362($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4362);
    // 0x800224B4: sb          $v0, 0x121($s0)
    MEM_B(0X121, ctx->r16) = ctx->r2;
    // 0x800224B8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800224BC: lbu         $v0, 0x4363($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4363);
    // 0x800224C0: sb          $v0, 0x120($s0)
    MEM_B(0X120, ctx->r16) = ctx->r2;
    // 0x800224C4: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800224C8: lbu         $v1, 0x4364($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X4364);
    // 0x800224CC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800224D0: sb          $v0, 0x11F($s0)
    MEM_B(0X11F, ctx->r16) = ctx->r2;
    // 0x800224D4: sb          $v1, 0x122($s0)
    MEM_B(0X122, ctx->r16) = ctx->r3;
    // 0x800224D8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800224DC: j           L_8002251C
    // 0x800224E0: sw          $a2, 0x40CC($at)
    MEM_W(0X40CC, ctx->r1) = ctx->r6;
        goto L_8002251C;
    // 0x800224E0: sw          $a2, 0x40CC($at)
    MEM_W(0X40CC, ctx->r1) = ctx->r6;
L_800224E4:
    // 0x800224E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800224E8:
    // 0x800224E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_800224EC:
    // 0x800224EC: addiu       $a2, $zero, -0x6
    ctx->r6 = ADD32(0, -0X6);
    // 0x800224F0: jal         0x80023C74
    // 0x800224F4: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    func_80023C74(rdram, ctx);
        goto after_3;
    // 0x800224F4: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    after_3:
    // 0x800224F8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800224FC: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80022500: addiu       $a1, $a1, 0x40D0
    ctx->r5 = ADD32(ctx->r5, 0X40D0);
    // 0x80022504: jal         0x80024014
    // 0x80022508: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80024014(rdram, ctx);
        goto after_4;
    // 0x80022508: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x8002250C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80022510: sb          $v0, 0x120($s0)
    MEM_B(0X120, ctx->r16) = ctx->r2;
    // 0x80022514: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80022518: sb          $v0, 0x11F($s0)
    MEM_B(0X11F, ctx->r16) = ctx->r2;
L_8002251C:
    // 0x8002251C: lbu         $v0, 0x63($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X63);
    // 0x80022520: sb          $zero, 0x123($s0)
    MEM_B(0X123, ctx->r16) = 0;
    // 0x80022524: j           L_8002256C
    // 0x80022528: sb          $v0, 0x124($s0)
    MEM_B(0X124, ctx->r16) = ctx->r2;
        goto L_8002256C;
    // 0x80022528: sb          $v0, 0x124($s0)
    MEM_B(0X124, ctx->r16) = ctx->r2;
L_8002252C:
    // 0x8002252C: jal         0x80022894
    // 0x80022530: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80022894(rdram, ctx);
        goto after_5;
    // 0x80022530: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x80022534: j           L_80022554
    // 0x80022538: nop

        goto L_80022554;
    // 0x80022538: nop

L_8002253C:
    // 0x8002253C: jal         0x80022BE4
    // 0x80022540: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80022BE4(rdram, ctx);
        goto after_6;
    // 0x80022540: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x80022544: j           L_8002256C
    // 0x80022548: nop

        goto L_8002256C;
    // 0x80022548: nop

L_8002254C:
    // 0x8002254C: jal         0x8002306C
    // 0x80022550: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8002306C(rdram, ctx);
        goto after_7;
    // 0x80022550: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
L_80022554:
    // 0x80022554: lbu         $v0, 0x11F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X11F);
    // 0x80022558: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002255C: j           L_8002256C
    // 0x80022560: sb          $v0, 0x11F($s0)
    MEM_B(0X11F, ctx->r16) = ctx->r2;
        goto L_8002256C;
    // 0x80022560: sb          $v0, 0x11F($s0)
    MEM_B(0X11F, ctx->r16) = ctx->r2;
L_80022564:
    // 0x80022564: jal         0x80023480
    // 0x80022568: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80023480(rdram, ctx);
        goto after_8;
    // 0x80022568: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
L_8002256C:
    // 0x8002256C: lb          $v1, 0x120($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X120);
    // 0x80022570: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80022574: beq         $v1, $v0, L_800227F8
    if (ctx->r3 == ctx->r2) {
        // 0x80022578: nop
    
            goto L_800227F8;
    }
    // 0x80022578: nop

    // 0x8002257C: lb          $a0, 0x121($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X121);
    // 0x80022580: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
    // 0x80022584: bne         $a0, $v1, L_8002277C
    if (ctx->r4 != ctx->r3) {
        // 0x80022588: sw          $zero, 0x114($s0)
        MEM_W(0X114, ctx->r16) = 0;
            goto L_8002277C;
    }
    // 0x80022588: sw          $zero, 0x114($s0)
    MEM_W(0X114, ctx->r16) = 0;
    // 0x8002258C: lb          $v1, 0x120($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X120);
    // 0x80022590: lb          $v0, 0x4C($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X4C);
    // 0x80022594: beq         $v1, $v0, L_800225AC
    if (ctx->r3 == ctx->r2) {
        // 0x80022598: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800225AC;
    }
    // 0x80022598: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8002259C: addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // 0x800225A0: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x800225A4: j           L_800227F8
    // 0x800225A8: sw          $v0, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->r2;
        goto L_800227F8;
    // 0x800225A8: sw          $v0, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->r2;
L_800225AC:
    // 0x800225AC: lb          $v0, 0x11F($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X11F);
    // 0x800225B0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800225B4: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x800225B8: bne         $v0, $zero, L_800225C8
    if (ctx->r2 != 0) {
        // 0x800225BC: sb          $v1, 0x123($s0)
        MEM_B(0X123, ctx->r16) = ctx->r3;
            goto L_800225C8;
    }
    // 0x800225BC: sb          $v1, 0x123($s0)
    MEM_B(0X123, ctx->r16) = ctx->r3;
    // 0x800225C0: jal         0x80024414
    // 0x800225C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80024414(rdram, ctx);
        goto after_9;
    // 0x800225C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_9:
L_800225C8:
    // 0x800225C8: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x800225CC: lb          $v0, 0x2($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2);
    // 0x800225D0: beq         $v0, $zero, L_80022760
    if (ctx->r2 == 0) {
        // 0x800225D4: nop
    
            goto L_80022760;
    }
    // 0x800225D4: nop

    // 0x800225D8: jal         0x80025694
    // 0x800225DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80025694(rdram, ctx);
        goto after_10;
    // 0x800225DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_10:
    // 0x800225E0: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800225E4: beq         $v0, $zero, L_80022608
    if (ctx->r2 == 0) {
        // 0x800225E8: nop
    
            goto L_80022608;
    }
    // 0x800225E8: nop

    // 0x800225EC: lb          $v0, 0x122($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X122);
    // 0x800225F0: beq         $v0, $zero, L_80022608
    if (ctx->r2 == 0) {
        // 0x800225F4: nop
    
            goto L_80022608;
    }
    // 0x800225F4: nop

    // 0x800225F8: lhu         $v1, 0x80($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X80);
    // 0x800225FC: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x80022600: j           L_800227F4
    // 0x80022604: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
        goto L_800227F4;
    // 0x80022604: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
L_80022608:
    // 0x80022608: lb          $v0, 0xCD($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XCD);
    // 0x8002260C: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x80022610: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x80022614: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x80022618: lbu         $v0, 0xBC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XBC);
    // 0x8002261C: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80022620: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x80022624: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // 0x80022628: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8002262C: bne         $v0, $zero, L_80022640
    if (ctx->r2 != 0) {
        // 0x80022630: nop
    
            goto L_80022640;
    }
    // 0x80022630: nop

    // 0x80022634: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
    // 0x80022638: bne         $v1, $v0, L_8002264C
    if (ctx->r3 != ctx->r2) {
        // 0x8002263C: nop
    
            goto L_8002264C;
    }
    // 0x8002263C: nop

L_80022640:
    // 0x80022640: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x80022644: j           L_800227F4
    // 0x80022648: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
        goto L_800227F4;
    // 0x80022648: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
L_8002264C:
    // 0x8002264C: jal         0x80020E30
    // 0x80022650: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80020E30(rdram, ctx);
        goto after_11;
    // 0x80022650: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_11:
    // 0x80022654: beq         $v0, $zero, L_80022688
    if (ctx->r2 == 0) {
        // 0x80022658: nop
    
            goto L_80022688;
    }
    // 0x80022658: nop

    // 0x8002265C: lb          $v0, 0x122($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X122);
    // 0x80022660: beq         $v0, $zero, L_80022688
    if (ctx->r2 == 0) {
        // 0x80022664: nop
    
            goto L_80022688;
    }
    // 0x80022664: nop

    // 0x80022668: lb          $a0, 0xCC($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XCC);
    // 0x8002266C: lb          $v1, 0xCD($s0)
    ctx->r3 = MEM_B(ctx->r16, 0XCD);
    // 0x80022670: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // 0x80022674: bltzl       $v0, L_8002267C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80022678: subu        $v0, $v1, $a0
        ctx->r2 = SUB32(ctx->r3, ctx->r4);
            goto L_8002267C;
    }
    goto skip_6;
    // 0x80022678: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    skip_6:
L_8002267C:
    // 0x8002267C: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80022680: bnel        $v0, $zero, L_800227F8
    if (ctx->r2 != 0) {
        // 0x80022684: sb          $zero, 0x11C($s0)
        MEM_B(0X11C, ctx->r16) = 0;
            goto L_800227F8;
    }
    goto skip_7;
    // 0x80022684: sb          $zero, 0x11C($s0)
    MEM_B(0X11C, ctx->r16) = 0;
    skip_7:
L_80022688:
    // 0x80022688: lb          $a0, 0xCC($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XCC);
    // 0x8002268C: lb          $v1, 0xCD($s0)
    ctx->r3 = MEM_B(ctx->r16, 0XCD);
    // 0x80022690: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // 0x80022694: bltz        $v0, L_800226AC
    if (SIGNED(ctx->r2) < 0) {
        // 0x80022698: slti        $v0, $v0, 0x5
        ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
            goto L_800226AC;
    }
    // 0x80022698: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8002269C: beq         $v0, $zero, L_800226BC
    if (ctx->r2 == 0) {
        // 0x800226A0: nop
    
            goto L_800226BC;
    }
    // 0x800226A0: nop

    // 0x800226A4: j           L_800226C8
    // 0x800226A8: nop

        goto L_800226C8;
    // 0x800226A8: nop

L_800226AC:
    // 0x800226AC: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // 0x800226B0: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x800226B4: bne         $v0, $zero, L_800226C8
    if (ctx->r2 != 0) {
        // 0x800226B8: nop
    
            goto L_800226C8;
    }
    // 0x800226B8: nop

L_800226BC:
    // 0x800226BC: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x800226C0: j           L_800227F4
    // 0x800226C4: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
        goto L_800227F4;
    // 0x800226C4: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
L_800226C8:
    // 0x800226C8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800226CC: lbu         $v0, 0x7B7C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B7C);
    // 0x800226D0: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800226D4: bne         $v0, $zero, L_80022728
    if (ctx->r2 != 0) {
        // 0x800226D8: nop
    
            goto L_80022728;
    }
    // 0x800226D8: nop

    // 0x800226DC: lb          $v1, 0xCC($s0)
    ctx->r3 = MEM_B(ctx->r16, 0XCC);
    // 0x800226E0: lb          $v0, 0xCD($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XCD);
    // 0x800226E4: bne         $v1, $v0, L_80022728
    if (ctx->r3 != ctx->r2) {
        // 0x800226E8: nop
    
            goto L_80022728;
    }
    // 0x800226E8: nop

    // 0x800226EC: jal         0x8006CEB0
    // 0x800226F0: nop

    func_8006CEB0(rdram, ctx);
        goto after_12;
    // 0x800226F0: nop

    after_12:
    // 0x800226F4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800226F8: bltzl       $v1, L_80022700
    if (SIGNED(ctx->r3) < 0) {
        // 0x800226FC: addiu       $v0, $v1, 0x1F
        ctx->r2 = ADD32(ctx->r3, 0X1F);
            goto L_80022700;
    }
    goto skip_8;
    // 0x800226FC: addiu       $v0, $v1, 0x1F
    ctx->r2 = ADD32(ctx->r3, 0X1F);
    skip_8:
L_80022700:
    // 0x80022700: sra         $v0, $v0, 5
    ctx->r2 = S32(SIGNED(ctx->r2) >> 5);
    // 0x80022704: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80022708: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x8002270C: slti        $v0, $v0, 0x14
    ctx->r2 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80022710: beq         $v0, $zero, L_800227F8
    if (ctx->r2 == 0) {
        // 0x80022714: nop
    
            goto L_800227F8;
    }
    // 0x80022714: nop

    // 0x80022718: lhu         $v1, 0x80($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X80);
    // 0x8002271C: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x80022720: j           L_800227F4
    // 0x80022724: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
        goto L_800227F4;
    // 0x80022724: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
L_80022728:
    // 0x80022728: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x8002272C: lb          $v1, 0xCC($v0)
    ctx->r3 = MEM_B(ctx->r2, 0XCC);
    // 0x80022730: lb          $v0, 0xCD($v0)
    ctx->r2 = MEM_B(ctx->r2, 0XCD);
    // 0x80022734: beq         $v1, $v0, L_80022754
    if (ctx->r3 == ctx->r2) {
        // 0x80022738: nop
    
            goto L_80022754;
    }
    // 0x80022738: nop

    // 0x8002273C: lb          $v1, 0x122($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X122);
    // 0x80022740: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80022744: bne         $v1, $v0, L_80022754
    if (ctx->r3 != ctx->r2) {
        // 0x80022748: nop
    
            goto L_80022754;
    }
    // 0x80022748: nop

    // 0x8002274C: j           L_800227F8
    // 0x80022750: sb          $zero, 0x11C($s0)
    MEM_B(0X11C, ctx->r16) = 0;
        goto L_800227F8;
    // 0x80022750: sb          $zero, 0x11C($s0)
    MEM_B(0X11C, ctx->r16) = 0;
L_80022754:
    // 0x80022754: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x80022758: j           L_800227F4
    // 0x8002275C: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
        goto L_800227F4;
    // 0x8002275C: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
L_80022760:
    // 0x80022760: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022764: lw          $v0, 0x40C8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X40C8);
    // 0x80022768: bne         $v0, $zero, L_800227F8
    if (ctx->r2 != 0) {
        // 0x8002276C: nop
    
            goto L_800227F8;
    }
    // 0x8002276C: nop

    // 0x80022770: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x80022774: j           L_800227F4
    // 0x80022778: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
        goto L_800227F4;
    // 0x80022778: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
L_8002277C:
    // 0x8002277C: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80022780: beq         $v0, $zero, L_800227BC
    if (ctx->r2 == 0) {
        // 0x80022784: slt         $v0, $v1, $a0
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800227BC;
    }
    // 0x80022784: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80022788: lw          $v0, 0x118($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X118);
    // 0x8002278C: beq         $v0, $zero, L_800227B0
    if (ctx->r2 == 0) {
        // 0x80022790: nop
    
            goto L_800227B0;
    }
    // 0x80022790: nop

    // 0x80022794: lb          $v1, 0x120($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X120);
    // 0x80022798: lb          $v0, 0x4C($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X4C);
    // 0x8002279C: beq         $v1, $v0, L_800227B0
    if (ctx->r3 == ctx->r2) {
        // 0x800227A0: nop
    
            goto L_800227B0;
    }
    // 0x800227A0: nop

    // 0x800227A4: lhu         $v0, 0x82($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X82);
    // 0x800227A8: sw          $zero, 0x118($s0)
    MEM_W(0X118, ctx->r16) = 0;
    // 0x800227AC: sw          $v0, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->r2;
L_800227B0:
    // 0x800227B0: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x800227B4: j           L_800227F4
    // 0x800227B8: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
        goto L_800227F4;
    // 0x800227B8: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
L_800227BC:
    // 0x800227BC: beq         $v0, $zero, L_800227F8
    if (ctx->r2 == 0) {
        // 0x800227C0: nop
    
            goto L_800227F8;
    }
    // 0x800227C0: nop

    // 0x800227C4: lw          $v0, 0x118($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X118);
    // 0x800227C8: beq         $v0, $zero, L_800227EC
    if (ctx->r2 == 0) {
        // 0x800227CC: nop
    
            goto L_800227EC;
    }
    // 0x800227CC: nop

    // 0x800227D0: lb          $v1, 0x120($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X120);
    // 0x800227D4: lb          $v0, 0x4C($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X4C);
    // 0x800227D8: beq         $v1, $v0, L_800227EC
    if (ctx->r3 == ctx->r2) {
        // 0x800227DC: nop
    
            goto L_800227EC;
    }
    // 0x800227DC: nop

    // 0x800227E0: lhu         $v0, 0x82($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X82);
    // 0x800227E4: sw          $zero, 0x118($s0)
    MEM_W(0X118, ctx->r16) = 0;
    // 0x800227E8: sw          $v0, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->r2;
L_800227EC:
    // 0x800227EC: lw          $v0, 0x114($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X114);
    // 0x800227F0: ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
L_800227F4:
    // 0x800227F4: sw          $v0, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->r2;
L_800227F8:
    // 0x800227F8: lw          $a0, 0xB8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB8);
    // 0x800227FC: lhu         $v0, 0x116($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X116);
    // 0x80022800: lw          $v1, 0xB4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB4);
    // 0x80022804: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x80022808: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8002280C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80022810: lbu         $v0, 0x7B85($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B85);
    // 0x80022814: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x80022818: beq         $v0, $zero, L_8002286C
    if (ctx->r2 == 0) {
        // 0x8002281C: nop
    
            goto L_8002286C;
    }
    // 0x8002281C: nop

    // 0x80022820: lw          $a0, 0xB4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB4);
    // 0x80022824: lhu         $v1, 0x80($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X80);
    // 0x80022828: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8002282C: bne         $v0, $v1, L_8002286C
    if (ctx->r2 != ctx->r3) {
        // 0x80022830: xor         $v0, $v0, $v1
        ctx->r2 = ctx->r2 ^ ctx->r3;
            goto L_8002286C;
    }
    // 0x80022830: xor         $v0, $v0, $v1
    ctx->r2 = ctx->r2 ^ ctx->r3;
    // 0x80022834: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x80022838: lw          $a0, 0xB8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB8);
    // 0x8002283C: lhu         $v1, 0x80($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X80);
    // 0x80022840: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80022844: xor         $v0, $v0, $v1
    ctx->r2 = ctx->r2 ^ ctx->r3;
    // 0x80022848: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8002284C: lw          $v1, 0xB4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB4);
    // 0x80022850: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80022854: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
    // 0x80022858: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8002285C: lw          $v1, 0xB8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB8);
    // 0x80022860: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80022864: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
    // 0x80022868: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8002286C:
    // 0x8002286C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022870: lw          $v0, 0x43A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43A8);
    // 0x80022874: sw          $v0, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r2;
    // 0x80022878: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002287C: lw          $v0, 0x43AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43AC);
    // 0x80022880: sw          $v0, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->r2;
    // 0x80022884: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80022888: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002288C: jr          $ra
    // 0x80022890: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80022890: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80022894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022894: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80022898: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002289C: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800228A0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800228A4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800228A8: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800228AC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800228B0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800228B4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800228B8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800228BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800228C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800228C4: lb          $fp, 0x4C($s2)
    ctx->r30 = MEM_B(ctx->r18, 0X4C);
    // 0x800228C8: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800228CC: lw          $v1, 0x43A0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X43A0);
    // 0x800228D0: lw          $s7, 0x18($s2)
    ctx->r23 = MEM_W(ctx->r18, 0X18);
    // 0x800228D4: lw          $s6, 0x1C($s2)
    ctx->r22 = MEM_W(ctx->r18, 0X1C);
    // 0x800228D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800228DC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800228E0: sw          $zero, 0x40C4($at)
    MEM_W(0X40C4, ctx->r1) = 0;
    // 0x800228E4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800228E8: sw          $v0, 0x40C8($at)
    MEM_W(0X40C8, ctx->r1) = ctx->r2;
    // 0x800228EC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800228F0: sw          $v1, 0x40C0($at)
    MEM_W(0X40C0, ctx->r1) = ctx->r3;
    // 0x800228F4: blez        $v1, L_80022A9C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800228F8: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_80022A9C;
    }
    // 0x800228F8: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x800228FC: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80022900: lui         $s5, 0x800C
    ctx->r21 = S32(0X800C << 16);
    // 0x80022904: addiu       $s5, $s5, 0x40D0
    ctx->r21 = ADD32(ctx->r21, 0X40D0);
L_80022908:
    // 0x80022908: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002290C: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80022910: lb          $v0, 0x40D4($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X40D4);
    // 0x80022914: sw          $s6, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r22;
    // 0x80022918: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // 0x8002291C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022920: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80022924: lbu         $v0, 0x40D5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X40D5);
    // 0x80022928: sb          $v0, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = ctx->r2;
    // 0x8002292C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022930: lw          $v0, 0x43AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43AC);
    // 0x80022934: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80022938: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002293C: jal         0x80024C30
    // 0x80022940: sw          $v0, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->r2;
    func_80024C30(rdram, ctx);
        goto after_0;
    // 0x80022940: sw          $v0, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->r2;
    after_0:
    // 0x80022944: lw          $a2, 0x1C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X1C);
    // 0x80022948: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8002294C: addiu       $a1, $a2, -0x2
    ctx->r5 = ADD32(ctx->r6, -0X2);
    // 0x80022950: jal         0x80023E94
    // 0x80022954: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    func_80023E94(rdram, ctx);
        goto after_1;
    // 0x80022954: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    after_1:
    // 0x80022958: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8002295C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80022960: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x80022964: sb          $s1, 0x40D6($at)
    MEM_B(0X40D6, ctx->r1) = ctx->r17;
    // 0x80022968: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002296C: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x80022970: sb          $zero, 0x40D7($at)
    MEM_B(0X40D7, ctx->r1) = 0;
    // 0x80022974: beq         $s1, $zero, L_80022A14
    if (ctx->r17 == 0) {
        // 0x80022978: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80022A14;
    }
    // 0x80022978: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002297C: jal         0x80023F50
    // 0x80022980: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80023F50(rdram, ctx);
        goto after_2;
    // 0x80022980: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80022984: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80022988: jal         0x80023A14
    // 0x8002298C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80023A14(rdram, ctx);
        goto after_3;
    // 0x8002298C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80022990: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80022994: sra         $s0, $v0, 16
    ctx->r16 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80022998: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8002299C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x800229A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800229A4: jal         0x80024974
    // 0x800229A8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80024974(rdram, ctx);
        goto after_4;
    // 0x800229A8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_4:
    // 0x800229AC: slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x800229B0: bne         $v0, $zero, L_800229D8
    if (ctx->r2 != 0) {
        // 0x800229B4: addiu       $v1, $s0, 0xBB8
        ctx->r3 = ADD32(ctx->r16, 0XBB8);
            goto L_800229D8;
    }
    // 0x800229B4: addiu       $v1, $s0, 0xBB8
    ctx->r3 = ADD32(ctx->r16, 0XBB8);
    // 0x800229B8: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x800229BC: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800229C0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800229C4: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800229C8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800229CC: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x800229D0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800229D4: sw          $zero, 0x40C8($at)
    MEM_W(0X40C8, ctx->r1) = 0;
L_800229D8:
    // 0x800229D8: lb          $v1, 0xCC($s2)
    ctx->r3 = MEM_B(ctx->r18, 0XCC);
    // 0x800229DC: lb          $v0, 0xCD($s2)
    ctx->r2 = MEM_B(ctx->r18, 0XCD);
    // 0x800229E0: beq         $v1, $v0, L_80022A3C
    if (ctx->r3 == ctx->r2) {
        // 0x800229E4: addiu       $v0, $s0, 0x64
        ctx->r2 = ADD32(ctx->r16, 0X64);
            goto L_80022A3C;
    }
    // 0x800229E4: addiu       $v0, $s0, 0x64
    ctx->r2 = ADD32(ctx->r16, 0X64);
    // 0x800229E8: sll         $v1, $s1, 1
    ctx->r3 = S32(ctx->r17 << 1);
    // 0x800229EC: addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // 0x800229F0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800229F4: addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // 0x800229F8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800229FC: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x80022A00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80022A04: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80022A08: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x80022A0C: j           L_80022A3C
    // 0x80022A10: sb          $v0, 0x40D7($at)
    MEM_B(0X40D7, ctx->r1) = ctx->r2;
        goto L_80022A3C;
    // 0x80022A10: sb          $v0, 0x40D7($at)
    MEM_B(0X40D7, ctx->r1) = ctx->r2;
L_80022A14:
    // 0x80022A14: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80022A18: jal         0x80023A14
    // 0x80022A1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80023A14(rdram, ctx);
        goto after_5;
    // 0x80022A1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80022A20: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80022A24: sra         $s0, $v0, 16
    ctx->r16 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80022A28: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80022A2C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x80022A30: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80022A34: jal         0x80024974
    // 0x80022A38: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80024974(rdram, ctx);
        goto after_6;
    // 0x80022A38: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
L_80022A3C:
    // 0x80022A3C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022A40: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80022A44: lh          $v0, 0x40D0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X40D0);
    // 0x80022A48: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80022A4C: slti        $v0, $s0, 0x7531
    ctx->r2 = SIGNED(ctx->r16) < 0X7531 ? 1 : 0;
    // 0x80022A50: beql        $v0, $zero, L_80022A58
    if (ctx->r2 == 0) {
        // 0x80022A54: addiu       $s0, $zero, 0x7530
        ctx->r16 = ADD32(0, 0X7530);
            goto L_80022A58;
    }
    goto skip_0;
    // 0x80022A54: addiu       $s0, $zero, 0x7530
    ctx->r16 = ADD32(0, 0X7530);
    skip_0:
L_80022A58:
    // 0x80022A58: slti        $v0, $s0, -0x7530
    ctx->r2 = SIGNED(ctx->r16) < -0X7530 ? 1 : 0;
    // 0x80022A5C: bnel        $v0, $zero, L_80022A64
    if (ctx->r2 != 0) {
        // 0x80022A60: addiu       $s0, $zero, -0x7530
        ctx->r16 = ADD32(0, -0X7530);
            goto L_80022A64;
    }
    goto skip_1;
    // 0x80022A60: addiu       $s0, $zero, -0x7530
    ctx->r16 = ADD32(0, -0X7530);
    skip_1:
L_80022A64:
    // 0x80022A64: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80022A68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80022A6C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80022A70: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x80022A74: sh          $s0, 0x40D0($at)
    MEM_H(0X40D0, ctx->r1) = ctx->r16;
    // 0x80022A78: jal         0x80023D54
    // 0x80022A7C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80023D54(rdram, ctx);
        goto after_7;
    // 0x80022A7C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_7:
    // 0x80022A80: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x80022A84: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022A88: lw          $v0, 0x43A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43A0);
    // 0x80022A8C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80022A90: slt         $v0, $s4, $v0
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80022A94: bne         $v0, $zero, L_80022908
    if (ctx->r2 != 0) {
        // 0x80022A98: addiu       $s5, $s5, 0x8
        ctx->r21 = ADD32(ctx->r21, 0X8);
            goto L_80022908;
    }
    // 0x80022A98: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
L_80022A9C:
    // 0x80022A9C: sw          $s7, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r23;
    // 0x80022AA0: sw          $s6, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r22;
    // 0x80022AA4: sb          $fp, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = ctx->r30;
    // 0x80022AA8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022AAC: lw          $v0, 0x43A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43A8);
    // 0x80022AB0: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80022AB4: lw          $v1, 0x40C8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X40C8);
    // 0x80022AB8: sw          $v0, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->r2;
    // 0x80022ABC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022AC0: lw          $v0, 0x43AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43AC);
    // 0x80022AC4: beq         $v1, $zero, L_80022AD8
    if (ctx->r3 == 0) {
        // 0x80022AC8: sw          $v0, 0x110($s2)
        MEM_W(0X110, ctx->r18) = ctx->r2;
            goto L_80022AD8;
    }
    // 0x80022AC8: sw          $v0, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->r2;
    // 0x80022ACC: lb          $v0, 0x12A($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X12A);
    // 0x80022AD0: beq         $v0, $zero, L_80022BB4
    if (ctx->r2 == 0) {
        // 0x80022AD4: nop
    
            goto L_80022BB4;
    }
    // 0x80022AD4: nop

L_80022AD8:
    // 0x80022AD8: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80022ADC: lw          $v1, 0x43A0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X43A0);
    // 0x80022AE0: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80022AE4: slt         $v0, $s4, $v1
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80022AE8: beq         $v0, $zero, L_80022B30
    if (ctx->r2 == 0) {
        // 0x80022AEC: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80022B30;
    }
    // 0x80022AEC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80022AF0: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x80022AF4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_80022AF8:
    // 0x80022AF8: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x80022AFC: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80022B00: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80022B04: lh          $v1, 0x40D0($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X40D0);
    // 0x80022B08: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80022B0C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80022B10: lh          $v0, 0x40D0($at)
    ctx->r2 = MEM_H(ctx->r1, 0X40D0);
    // 0x80022B14: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80022B18: bnel        $v0, $zero, L_80022B20
    if (ctx->r2 != 0) {
        // 0x80022B1C: addu        $a1, $s4, $zero
        ctx->r5 = ADD32(ctx->r20, 0);
            goto L_80022B20;
    }
    goto skip_2;
    // 0x80022B1C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    skip_2:
L_80022B20:
    // 0x80022B20: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80022B24: slt         $v0, $s4, $a2
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80022B28: bne         $v0, $zero, L_80022AF8
    if (ctx->r2 != 0) {
        // 0x80022B2C: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_80022AF8;
    }
    // 0x80022B2C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_80022B30:
    // 0x80022B30: sll         $v1, $a1, 3
    ctx->r3 = S32(ctx->r5 << 3);
    // 0x80022B34: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022B38: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80022B3C: lbu         $v0, 0x40D5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X40D5);
    // 0x80022B40: sb          $v0, 0x120($s2)
    MEM_B(0X120, ctx->r18) = ctx->r2;
    // 0x80022B44: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022B48: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80022B4C: lbu         $v0, 0x40D4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X40D4);
    // 0x80022B50: sb          $v0, 0x121($s2)
    MEM_B(0X121, ctx->r18) = ctx->r2;
    // 0x80022B54: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022B58: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80022B5C: lbu         $v0, 0x40D6($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X40D6);
    // 0x80022B60: sb          $v0, 0x122($s2)
    MEM_B(0X122, ctx->r18) = ctx->r2;
    // 0x80022B64: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x80022B68: addiu       $a2, $a2, 0x435E
    ctx->r6 = ADD32(ctx->r6, 0X435E);
    // 0x80022B6C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80022B70: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80022B74: lwl         $v0, 0x40D0($at)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r1, 0X40D0);
    // 0x80022B78: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80022B7C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80022B80: lwr         $v0, 0x40D3($at)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r1, 0X40D3);
    // 0x80022B84: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80022B88: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80022B8C: lwl         $a0, 0x40D4($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r1, 0X40D4);
    // 0x80022B90: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80022B94: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80022B98: lwr         $a0, 0x40D7($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r1, 0X40D7);
    // 0x80022B9C: swl         $v0, 0x0($a2)
    do_swl(rdram, 0X0, ctx->r6, ctx->r2);
    // 0x80022BA0: swr         $v0, 0x3($a2)
    do_swr(rdram, 0X3, ctx->r6, ctx->r2);
    // 0x80022BA4: swl         $a0, 0x4($a2)
    do_swl(rdram, 0X4, ctx->r6, ctx->r4);
    // 0x80022BA8: swr         $a0, 0x7($a2)
    do_swr(rdram, 0X7, ctx->r6, ctx->r4);
    // 0x80022BAC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80022BB0: sb          $v0, 0x11F($s2)
    MEM_B(0X11F, ctx->r18) = ctx->r2;
L_80022BB4:
    // 0x80022BB4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80022BB8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80022BBC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80022BC0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80022BC4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80022BC8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80022BCC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80022BD0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80022BD4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80022BD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80022BDC: jr          $ra
    // 0x80022BE0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80022BE0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80022BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022BE4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022BE8: lw          $v0, 0x40C8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X40C8);
    // 0x80022BEC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80022BF0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80022BF4: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80022BF8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80022BFC: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80022C00: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80022C04: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80022C08: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80022C0C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80022C10: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80022C14: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80022C18: beq         $v0, $zero, L_80022F24
    if (ctx->r2 == 0) {
        // 0x80022C1C: sw          $s0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r16;
            goto L_80022F24;
    }
    // 0x80022C1C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80022C20: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80022C24: lw          $v1, 0x40C4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X40C4);
    // 0x80022C28: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022C2C: lw          $v0, 0x40C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X40C0);
    // 0x80022C30: beq         $v1, $v0, L_80022F14
    if (ctx->r3 == ctx->r2) {
        // 0x80022C34: sll         $v0, $v1, 3
        ctx->r2 = S32(ctx->r3 << 3);
            goto L_80022F14;
    }
    // 0x80022C34: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80022C38: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80022C3C: addiu       $a1, $a1, 0x40D0
    ctx->r5 = ADD32(ctx->r5, 0X40D0);
    // 0x80022C40: addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    // 0x80022C44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80022C48: jal         0x80024588
    // 0x80022C4C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80024588(rdram, ctx);
        goto after_0;
    // 0x80022C4C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
    // 0x80022C50: lbu         $t0, 0x54($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X54);
    // 0x80022C54: sb          $t0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r8;
    // 0x80022C58: lw          $t0, 0xDC($s2)
    ctx->r8 = MEM_W(ctx->r18, 0XDC);
    // 0x80022C5C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80022C60: lbu         $v0, 0x55($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X55);
    // 0x80022C64: lw          $v1, 0xE0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XE0);
    // 0x80022C68: lw          $s6, 0x18($s2)
    ctx->r22 = MEM_W(ctx->r18, 0X18);
    // 0x80022C6C: lw          $s7, 0x1C($s2)
    ctx->r23 = MEM_W(ctx->r18, 0X1C);
    // 0x80022C70: lbu         $fp, 0x4C($s2)
    ctx->r30 = MEM_BU(ctx->r18, 0X4C);
    // 0x80022C74: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80022C78: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80022C7C: sb          $v0, 0x54($s2)
    MEM_B(0X54, ctx->r18) = ctx->r2;
    // 0x80022C80: jal         0x800169C8
    // 0x80022C84: sw          $v1, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = ctx->r3;
    func_800169C8(rdram, ctx);
        goto after_1;
    // 0x80022C84: sw          $v1, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = ctx->r3;
    after_1:
    // 0x80022C88: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80022C8C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80022C90: jal         0x80016980
    // 0x80022C94: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_2;
    // 0x80022C94: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    after_2:
    // 0x80022C98: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80022C9C: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80022CA0: addiu       $s0, $s0, 0x4210
    ctx->r16 = ADD32(ctx->r16, 0X4210);
    // 0x80022CA4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80022CA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80022CAC: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x80022CB0: jal         0x80024014
    // 0x80022CB4: sb          $zero, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = 0;
    func_80024014(rdram, ctx);
        goto after_3;
    // 0x80022CB4: sb          $zero, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = 0;
    after_3:
    // 0x80022CB8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022CBC: lw          $v0, 0x43A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43A0);
    // 0x80022CC0: blez        $v0, L_80022E20
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80022CC4: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_80022E20;
    }
    // 0x80022CC4: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80022CC8: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x80022CCC: addu        $s5, $s0, $zero
    ctx->r21 = ADD32(ctx->r16, 0);
L_80022CD0:
    // 0x80022CD0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022CD4: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80022CD8: lb          $v0, 0x4214($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4214);
    // 0x80022CDC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80022CE0: jal         0x80016980
    // 0x80022CE4: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_4;
    // 0x80022CE4: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    after_4:
    // 0x80022CE8: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x80022CEC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022CF0: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80022CF4: lbu         $v0, 0x4215($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4215);
    // 0x80022CF8: sb          $v0, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = ctx->r2;
    // 0x80022CFC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022D00: lw          $v0, 0x43AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43AC);
    // 0x80022D04: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80022D08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80022D0C: jal         0x80024C30
    // 0x80022D10: sw          $v0, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->r2;
    func_80024C30(rdram, ctx);
        goto after_5;
    // 0x80022D10: sw          $v0, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->r2;
    after_5:
    // 0x80022D14: lw          $a2, 0x1C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X1C);
    // 0x80022D18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80022D1C: addiu       $a1, $a2, -0x2
    ctx->r5 = ADD32(ctx->r6, -0X2);
    // 0x80022D20: jal         0x80023E94
    // 0x80022D24: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    func_80023E94(rdram, ctx);
        goto after_6;
    // 0x80022D24: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    after_6:
    // 0x80022D28: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80022D2C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80022D30: addu        $at, $at, $s4
    ctx->r1 = ADD32(ctx->r1, ctx->r20);
    // 0x80022D34: sb          $s1, 0x4216($at)
    MEM_B(0X4216, ctx->r1) = ctx->r17;
    // 0x80022D38: beq         $s1, $zero, L_80022D94
    if (ctx->r17 == 0) {
        // 0x80022D3C: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80022D94;
    }
    // 0x80022D3C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80022D40: jal         0x80023F50
    // 0x80022D44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80023F50(rdram, ctx);
        goto after_7;
    // 0x80022D44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80022D48: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80022D4C: jal         0x80023A14
    // 0x80022D50: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80023A14(rdram, ctx);
        goto after_8;
    // 0x80022D50: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80022D54: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80022D58: sra         $s0, $v0, 16
    ctx->r16 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80022D5C: slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80022D60: bne         $v0, $zero, L_80022D84
    if (ctx->r2 != 0) {
        // 0x80022D64: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_80022D84;
    }
    // 0x80022D64: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80022D68: addiu       $v1, $s0, 0x2710
    ctx->r3 = ADD32(ctx->r16, 0X2710);
    // 0x80022D6C: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x80022D70: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80022D74: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80022D78: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80022D7C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80022D80: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
L_80022D84:
    // 0x80022D84: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x80022D88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80022D8C: j           L_80022DB8
    // 0x80022D90: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
        goto L_80022DB8;
    // 0x80022D90: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_80022D94:
    // 0x80022D94: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80022D98: jal         0x80023A14
    // 0x80022D9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80023A14(rdram, ctx);
        goto after_9;
    // 0x80022D9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80022DA0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80022DA4: sra         $s0, $v0, 16
    ctx->r16 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80022DA8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80022DAC: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x80022DB0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80022DB4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80022DB8:
    // 0x80022DB8: jal         0x80024974
    // 0x80022DBC: nop

    func_80024974(rdram, ctx);
        goto after_10;
    // 0x80022DBC: nop

    after_10:
    // 0x80022DC0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022DC4: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80022DC8: lh          $v0, 0x4210($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X4210);
    // 0x80022DCC: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80022DD0: slti        $v0, $s0, 0x7531
    ctx->r2 = SIGNED(ctx->r16) < 0X7531 ? 1 : 0;
    // 0x80022DD4: beql        $v0, $zero, L_80022DDC
    if (ctx->r2 == 0) {
        // 0x80022DD8: addiu       $s0, $zero, 0x7530
        ctx->r16 = ADD32(0, 0X7530);
            goto L_80022DDC;
    }
    goto skip_0;
    // 0x80022DD8: addiu       $s0, $zero, 0x7530
    ctx->r16 = ADD32(0, 0X7530);
    skip_0:
L_80022DDC:
    // 0x80022DDC: slti        $v0, $s0, -0x7530
    ctx->r2 = SIGNED(ctx->r16) < -0X7530 ? 1 : 0;
    // 0x80022DE0: bnel        $v0, $zero, L_80022DE8
    if (ctx->r2 != 0) {
        // 0x80022DE4: addiu       $s0, $zero, -0x7530
        ctx->r16 = ADD32(0, -0X7530);
            goto L_80022DE8;
    }
    goto skip_1;
    // 0x80022DE4: addiu       $s0, $zero, -0x7530
    ctx->r16 = ADD32(0, -0X7530);
    skip_1:
L_80022DE8:
    // 0x80022DE8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80022DEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80022DF0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80022DF4: addu        $at, $at, $s4
    ctx->r1 = ADD32(ctx->r1, ctx->r20);
    // 0x80022DF8: sh          $s0, 0x4210($at)
    MEM_H(0X4210, ctx->r1) = ctx->r16;
    // 0x80022DFC: jal         0x80023D54
    // 0x80022E00: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80023D54(rdram, ctx);
        goto after_11;
    // 0x80022E00: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_11:
    // 0x80022E04: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x80022E08: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022E0C: lw          $v0, 0x43A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43A0);
    // 0x80022E10: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80022E14: slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80022E18: bne         $v0, $zero, L_80022CD0
    if (ctx->r2 != 0) {
        // 0x80022E1C: addiu       $s5, $s5, 0x8
        ctx->r21 = ADD32(ctx->r21, 0X8);
            goto L_80022CD0;
    }
    // 0x80022E1C: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
L_80022E20:
    // 0x80022E20: sw          $s6, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r22;
    // 0x80022E24: sw          $s7, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r23;
    // 0x80022E28: sb          $fp, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = ctx->r30;
    // 0x80022E2C: lbu         $t0, 0x1F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1F);
    // 0x80022E30: sb          $t0, 0x54($s2)
    MEM_B(0X54, ctx->r18) = ctx->r8;
    // 0x80022E34: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x80022E38: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80022E3C: lw          $v1, 0x43A0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X43A0);
    // 0x80022E40: sw          $t0, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = ctx->r8;
    // 0x80022E44: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022E48: lw          $v0, 0x43A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43A8);
    // 0x80022E4C: sw          $v0, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->r2;
    // 0x80022E50: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022E54: lw          $v0, 0x43AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43AC);
    // 0x80022E58: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80022E5C: sw          $v0, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->r2;
    // 0x80022E60: slt         $v0, $s3, $v1
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80022E64: beq         $v0, $zero, L_80022EAC
    if (ctx->r2 == 0) {
        // 0x80022E68: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80022EAC;
    }
    // 0x80022E68: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80022E6C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x80022E70: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_80022E74:
    // 0x80022E74: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
    // 0x80022E78: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80022E7C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80022E80: lh          $v1, 0x4210($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X4210);
    // 0x80022E84: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80022E88: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80022E8C: lh          $v0, 0x4210($at)
    ctx->r2 = MEM_H(ctx->r1, 0X4210);
    // 0x80022E90: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80022E94: bnel        $v0, $zero, L_80022E9C
    if (ctx->r2 != 0) {
        // 0x80022E98: addu        $s1, $s3, $zero
        ctx->r17 = ADD32(ctx->r19, 0);
            goto L_80022E9C;
    }
    goto skip_2;
    // 0x80022E98: addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
    skip_2:
L_80022E9C:
    // 0x80022E9C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80022EA0: slt         $v0, $s3, $a1
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80022EA4: bne         $v0, $zero, L_80022E74
    if (ctx->r2 != 0) {
        // 0x80022EA8: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_80022E74;
    }
    // 0x80022EA8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_80022EAC:
    // 0x80022EAC: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80022EB0: lw          $a0, 0x40C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X40C4);
    // 0x80022EB4: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
    // 0x80022EB8: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80022EBC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80022EC0: lhu         $v1, 0x4210($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X4210);
    // 0x80022EC4: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80022EC8: lw          $a1, 0x40C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X40C0);
    // 0x80022ECC: sll         $a2, $a0, 3
    ctx->r6 = S32(ctx->r4 << 3);
    // 0x80022ED0: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80022ED4: sra         $v0, $v1, 16
    ctx->r2 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80022ED8: srl         $v1, $v1, 31
    ctx->r3 = S32(U32(ctx->r3) >> 31);
    // 0x80022EDC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80022EE0: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80022EE4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80022EE8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80022EEC: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x80022EF0: sh          $v0, 0x40D2($at)
    MEM_H(0X40D2, ctx->r1) = ctx->r2;
    // 0x80022EF4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80022EF8: bne         $a0, $a1, L_80022F14
    if (ctx->r4 != ctx->r5) {
        // 0x80022EFC: sw          $a0, 0x40C4($at)
        MEM_W(0X40C4, ctx->r1) = ctx->r4;
            goto L_80022F14;
    }
    // 0x80022EFC: sw          $a0, 0x40C4($at)
    MEM_W(0X40C4, ctx->r1) = ctx->r4;
    // 0x80022F00: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80022F04: sw          $zero, 0x40C8($at)
    MEM_W(0X40C8, ctx->r1) = 0;
    // 0x80022F08: lbu         $v0, 0x11F($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X11F);
    // 0x80022F0C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80022F10: sb          $v0, 0x11F($s2)
    MEM_B(0X11F, ctx->r18) = ctx->r2;
L_80022F14:
    // 0x80022F14: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022F18: lw          $v0, 0x40C8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X40C8);
    // 0x80022F1C: bne         $v0, $zero, L_8002303C
    if (ctx->r2 != 0) {
        // 0x80022F20: nop
    
            goto L_8002303C;
    }
    // 0x80022F20: nop

L_80022F24:
    // 0x80022F24: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80022F28: addiu       $s0, $s0, 0x40D0
    ctx->r16 = ADD32(ctx->r16, 0X40D0);
    // 0x80022F2C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80022F30: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80022F34: lh          $a1, 0x40D2($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X40D2);
    // 0x80022F38: jal         0x80025750
    // 0x80022F3C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    func_80025750(rdram, ctx);
        goto after_12;
    // 0x80022F3C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    after_12:
    // 0x80022F40: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80022F44: lw          $v1, 0x40C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X40C0);
    // 0x80022F48: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80022F4C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80022F50: sh          $v0, 0x40D2($at)
    MEM_H(0X40D2, ctx->r1) = ctx->r2;
    // 0x80022F54: slt         $v1, $s3, $v1
    ctx->r3 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80022F58: beq         $v1, $zero, L_80022FC4
    if (ctx->r3 == 0) {
        // 0x80022F5C: sll         $v1, $s1, 3
        ctx->r3 = S32(ctx->r17 << 3);
            goto L_80022FC4;
    }
    // 0x80022F5C: sll         $v1, $s1, 3
    ctx->r3 = S32(ctx->r17 << 3);
    // 0x80022F60: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x80022F64: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
L_80022F68:
    // 0x80022F68: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80022F6C: addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
    // 0x80022F70: lh          $a0, 0x40D0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X40D0);
    // 0x80022F74: jal         0x80025750
    // 0x80022F78: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    func_80025750(rdram, ctx);
        goto after_13;
    // 0x80022F78: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    after_13:
    // 0x80022F7C: sll         $v1, $s1, 3
    ctx->r3 = S32(ctx->r17 << 3);
    // 0x80022F80: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80022F84: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80022F88: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80022F8C: lh          $v1, 0x40D2($at)
    ctx->r3 = MEM_H(ctx->r1, 0X40D2);
    // 0x80022F90: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80022F94: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80022F98: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80022F9C: bnel        $v1, $zero, L_80022FA4
    if (ctx->r3 != 0) {
        // 0x80022FA0: addu        $s1, $s3, $zero
        ctx->r17 = ADD32(ctx->r19, 0);
            goto L_80022FA4;
    }
    goto skip_3;
    // 0x80022FA0: addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
    skip_3:
L_80022FA4:
    // 0x80022FA4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80022FA8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022FAC: lw          $v0, 0x40C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X40C0);
    // 0x80022FB0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80022FB4: slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80022FB8: bne         $v0, $zero, L_80022F68
    if (ctx->r2 != 0) {
        // 0x80022FBC: addiu       $s4, $s4, 0x8
        ctx->r20 = ADD32(ctx->r20, 0X8);
            goto L_80022F68;
    }
    // 0x80022FBC: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x80022FC0: sll         $v1, $s1, 3
    ctx->r3 = S32(ctx->r17 << 3);
L_80022FC4:
    // 0x80022FC4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022FC8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80022FCC: lbu         $v0, 0x40D5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X40D5);
    // 0x80022FD0: sb          $v0, 0x120($s2)
    MEM_B(0X120, ctx->r18) = ctx->r2;
    // 0x80022FD4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022FD8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80022FDC: lbu         $v0, 0x40D4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X40D4);
    // 0x80022FE0: sb          $v0, 0x121($s2)
    MEM_B(0X121, ctx->r18) = ctx->r2;
    // 0x80022FE4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80022FE8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80022FEC: lbu         $v0, 0x40D6($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X40D6);
    // 0x80022FF0: sb          $v0, 0x122($s2)
    MEM_B(0X122, ctx->r18) = ctx->r2;
    // 0x80022FF4: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x80022FF8: addiu       $a2, $a2, 0x435E
    ctx->r6 = ADD32(ctx->r6, 0X435E);
    // 0x80022FFC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023000: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80023004: lwl         $v0, 0x40D0($at)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r1, 0X40D0);
    // 0x80023008: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002300C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80023010: lwr         $v0, 0x40D3($at)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r1, 0X40D3);
    // 0x80023014: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023018: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8002301C: lwl         $a0, 0x40D4($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r1, 0X40D4);
    // 0x80023020: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023024: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80023028: lwr         $a0, 0x40D7($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r1, 0X40D7);
    // 0x8002302C: swl         $v0, 0x0($a2)
    do_swl(rdram, 0X0, ctx->r6, ctx->r2);
    // 0x80023030: swr         $v0, 0x3($a2)
    do_swr(rdram, 0X3, ctx->r6, ctx->r2);
    // 0x80023034: swl         $a0, 0x4($a2)
    do_swl(rdram, 0X4, ctx->r6, ctx->r4);
    // 0x80023038: swr         $a0, 0x7($a2)
    do_swr(rdram, 0X7, ctx->r6, ctx->r4);
L_8002303C:
    // 0x8002303C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80023040: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80023044: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80023048: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8002304C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80023050: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80023054: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80023058: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8002305C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80023060: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80023064: jr          $ra
    // 0x80023068: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80023068: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8002306C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002306C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80023070: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80023074: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80023078: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8002307C: addiu       $a1, $a1, 0x435E
    ctx->r5 = ADD32(ctx->r5, 0X435E);
    // 0x80023080: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80023084: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80023088: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8002308C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80023090: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80023094: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80023098: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8002309C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800230A0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800230A4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800230A8: jal         0x80024588
    // 0x800230AC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    func_80024588(rdram, ctx);
        goto after_0;
    // 0x800230AC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    after_0:
    // 0x800230B0: lbu         $t0, 0x54($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X54);
    // 0x800230B4: sb          $t0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r8;
    // 0x800230B8: lw          $t0, 0xDC($s2)
    ctx->r8 = MEM_W(ctx->r18, 0XDC);
    // 0x800230BC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800230C0: lbu         $v0, 0x55($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X55);
    // 0x800230C4: lw          $v1, 0xE0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XE0);
    // 0x800230C8: lw          $s6, 0x18($s2)
    ctx->r22 = MEM_W(ctx->r18, 0X18);
    // 0x800230CC: lw          $s7, 0x1C($s2)
    ctx->r23 = MEM_W(ctx->r18, 0X1C);
    // 0x800230D0: lbu         $fp, 0x4C($s2)
    ctx->r30 = MEM_BU(ctx->r18, 0X4C);
    // 0x800230D4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800230D8: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800230DC: sb          $v0, 0x54($s2)
    MEM_B(0X54, ctx->r18) = ctx->r2;
    // 0x800230E0: jal         0x800169C8
    // 0x800230E4: sw          $v1, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = ctx->r3;
    func_800169C8(rdram, ctx);
        goto after_1;
    // 0x800230E4: sw          $v1, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = ctx->r3;
    after_1:
    // 0x800230E8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800230EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800230F0: jal         0x80016980
    // 0x800230F4: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_2;
    // 0x800230F4: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    after_2:
    // 0x800230F8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800230FC: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80023100: addiu       $a1, $a1, 0x40D0
    ctx->r5 = ADD32(ctx->r5, 0X40D0);
    // 0x80023104: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80023108: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x8002310C: jal         0x80024014
    // 0x80023110: sb          $zero, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = 0;
    func_80024014(rdram, ctx);
        goto after_3;
    // 0x80023110: sb          $zero, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = 0;
    after_3:
    // 0x80023114: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80023118: lw          $v1, 0x43A0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X43A0);
    // 0x8002311C: lw          $a0, 0xE0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XE0);
    // 0x80023120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80023124: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023128: sw          $zero, 0x40C4($at)
    MEM_W(0X40C4, ctx->r1) = 0;
    // 0x8002312C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023130: sw          $v0, 0x40CC($at)
    MEM_W(0X40CC, ctx->r1) = ctx->r2;
    // 0x80023134: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023138: sw          $v1, 0x40C0($at)
    MEM_W(0X40C0, ctx->r1) = ctx->r3;
    // 0x8002313C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023140: sw          $a0, 0x4350($at)
    MEM_W(0X4350, ctx->r1) = ctx->r4;
    // 0x80023144: lbu         $v0, 0x54($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X54);
    // 0x80023148: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002314C: sb          $v0, 0x4354($at)
    MEM_B(0X4354, ctx->r1) = ctx->r2;
    // 0x80023150: lb          $v1, 0xCC($s2)
    ctx->r3 = MEM_B(ctx->r18, 0XCC);
    // 0x80023154: lb          $v0, 0xCD($s2)
    ctx->r2 = MEM_B(ctx->r18, 0XCD);
    // 0x80023158: beq         $v1, $v0, L_80023188
    if (ctx->r3 == ctx->r2) {
        // 0x8002315C: nop
    
            goto L_80023188;
    }
    // 0x8002315C: nop

    // 0x80023160: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80023164: addiu       $v0, $v0, -0x24E0
    ctx->r2 = ADD32(ctx->r2, -0X24E0);
    // 0x80023168: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002316C: sw          $v0, 0x4358($at)
    MEM_W(0X4358, ctx->r1) = ctx->r2;
    // 0x80023170: lb          $v0, 0xCC($s2)
    ctx->r2 = MEM_B(ctx->r18, 0XCC);
    // 0x80023174: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x80023178: lbu         $v0, 0xBC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XBC);
    // 0x8002317C: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80023180: j           L_800231A4
    // 0x80023184: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_800231A4;
    // 0x80023184: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80023188:
    // 0x80023188: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002318C: lbu         $v0, 0x7B7C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B7C);
    // 0x80023190: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80023194: addiu       $v1, $v1, -0x33F4
    ctx->r3 = ADD32(ctx->r3, -0X33F4);
    // 0x80023198: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002319C: sw          $v1, 0x4358($at)
    MEM_W(0X4358, ctx->r1) = ctx->r3;
    // 0x800231A0: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
L_800231A4:
    // 0x800231A4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800231A8: sb          $v0, 0x435C($at)
    MEM_B(0X435C, ctx->r1) = ctx->r2;
    // 0x800231AC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800231B0: lw          $v0, 0x43A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43A0);
    // 0x800231B4: blez        $v0, L_80023364
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800231B8: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_80023364;
    }
    // 0x800231B8: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x800231BC: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800231C0: lui         $s5, 0x800C
    ctx->r21 = S32(0X800C << 16);
    // 0x800231C4: addiu       $s5, $s5, 0x40D0
    ctx->r21 = ADD32(ctx->r21, 0X40D0);
L_800231C8:
    // 0x800231C8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800231CC: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800231D0: lb          $v0, 0x40D4($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X40D4);
    // 0x800231D4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800231D8: jal         0x80016980
    // 0x800231DC: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_4;
    // 0x800231DC: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    after_4:
    // 0x800231E0: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x800231E4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800231E8: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800231EC: lbu         $v0, 0x40D5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X40D5);
    // 0x800231F0: sb          $v0, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = ctx->r2;
    // 0x800231F4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800231F8: lw          $v0, 0x43AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43AC);
    // 0x800231FC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80023200: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80023204: jal         0x80024C30
    // 0x80023208: sw          $v0, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->r2;
    func_80024C30(rdram, ctx);
        goto after_5;
    // 0x80023208: sw          $v0, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->r2;
    after_5:
    // 0x8002320C: lw          $a2, 0x1C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X1C);
    // 0x80023210: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80023214: addiu       $a1, $a2, -0x2
    ctx->r5 = ADD32(ctx->r6, -0X2);
    // 0x80023218: jal         0x80023E94
    // 0x8002321C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    func_80023E94(rdram, ctx);
        goto after_6;
    // 0x8002321C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    after_6:
    // 0x80023220: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80023224: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023228: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x8002322C: sb          $s1, 0x40D6($at)
    MEM_B(0X40D6, ctx->r1) = ctx->r17;
    // 0x80023230: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023234: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x80023238: sb          $zero, 0x40D7($at)
    MEM_B(0X40D7, ctx->r1) = 0;
    // 0x8002323C: beq         $s1, $zero, L_800232DC
    if (ctx->r17 == 0) {
        // 0x80023240: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_800232DC;
    }
    // 0x80023240: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80023244: jal         0x80023F50
    // 0x80023248: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80023F50(rdram, ctx);
        goto after_7;
    // 0x80023248: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8002324C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80023250: jal         0x80023A14
    // 0x80023254: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80023A14(rdram, ctx);
        goto after_8;
    // 0x80023254: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80023258: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002325C: sra         $s0, $v0, 16
    ctx->r16 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80023260: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80023264: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x80023268: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8002326C: jal         0x80024974
    // 0x80023270: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80024974(rdram, ctx);
        goto after_9;
    // 0x80023270: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_9:
    // 0x80023274: slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80023278: bne         $v0, $zero, L_800232A0
    if (ctx->r2 != 0) {
        // 0x8002327C: addiu       $v1, $s0, 0xBB8
        ctx->r3 = ADD32(ctx->r16, 0XBB8);
            goto L_800232A0;
    }
    // 0x8002327C: addiu       $v1, $s0, 0xBB8
    ctx->r3 = ADD32(ctx->r16, 0XBB8);
    // 0x80023280: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x80023284: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80023288: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8002328C: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80023290: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80023294: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // 0x80023298: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002329C: sw          $zero, 0x40CC($at)
    MEM_W(0X40CC, ctx->r1) = 0;
L_800232A0:
    // 0x800232A0: lb          $v1, 0xCC($s2)
    ctx->r3 = MEM_B(ctx->r18, 0XCC);
    // 0x800232A4: lb          $v0, 0xCD($s2)
    ctx->r2 = MEM_B(ctx->r18, 0XCD);
    // 0x800232A8: beq         $v1, $v0, L_80023304
    if (ctx->r3 == ctx->r2) {
        // 0x800232AC: addiu       $v0, $s0, 0x64
        ctx->r2 = ADD32(ctx->r16, 0X64);
            goto L_80023304;
    }
    // 0x800232AC: addiu       $v0, $s0, 0x64
    ctx->r2 = ADD32(ctx->r16, 0X64);
    // 0x800232B0: sll         $v1, $s1, 1
    ctx->r3 = S32(ctx->r17 << 1);
    // 0x800232B4: addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // 0x800232B8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800232BC: addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // 0x800232C0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800232C4: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x800232C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800232CC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800232D0: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x800232D4: j           L_80023304
    // 0x800232D8: sb          $v0, 0x40D7($at)
    MEM_B(0X40D7, ctx->r1) = ctx->r2;
        goto L_80023304;
    // 0x800232D8: sb          $v0, 0x40D7($at)
    MEM_B(0X40D7, ctx->r1) = ctx->r2;
L_800232DC:
    // 0x800232DC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800232E0: jal         0x80023A14
    // 0x800232E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80023A14(rdram, ctx);
        goto after_10;
    // 0x800232E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x800232E8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800232EC: sra         $s0, $v0, 16
    ctx->r16 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800232F0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800232F4: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x800232F8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800232FC: jal         0x80024974
    // 0x80023300: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80024974(rdram, ctx);
        goto after_11;
    // 0x80023300: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_11:
L_80023304:
    // 0x80023304: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80023308: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x8002330C: lh          $v0, 0x40D0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X40D0);
    // 0x80023310: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80023314: slti        $v0, $s0, 0x7531
    ctx->r2 = SIGNED(ctx->r16) < 0X7531 ? 1 : 0;
    // 0x80023318: beql        $v0, $zero, L_80023320
    if (ctx->r2 == 0) {
        // 0x8002331C: addiu       $s0, $zero, 0x7530
        ctx->r16 = ADD32(0, 0X7530);
            goto L_80023320;
    }
    goto skip_0;
    // 0x8002331C: addiu       $s0, $zero, 0x7530
    ctx->r16 = ADD32(0, 0X7530);
    skip_0:
L_80023320:
    // 0x80023320: slti        $v0, $s0, -0x7530
    ctx->r2 = SIGNED(ctx->r16) < -0X7530 ? 1 : 0;
    // 0x80023324: bnel        $v0, $zero, L_8002332C
    if (ctx->r2 != 0) {
        // 0x80023328: addiu       $s0, $zero, -0x7530
        ctx->r16 = ADD32(0, -0X7530);
            goto L_8002332C;
    }
    goto skip_1;
    // 0x80023328: addiu       $s0, $zero, -0x7530
    ctx->r16 = ADD32(0, -0X7530);
    skip_1:
L_8002332C:
    // 0x8002332C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80023330: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80023334: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023338: addu        $at, $at, $s3
    ctx->r1 = ADD32(ctx->r1, ctx->r19);
    // 0x8002333C: sh          $s0, 0x40D0($at)
    MEM_H(0X40D0, ctx->r1) = ctx->r16;
    // 0x80023340: jal         0x80023D54
    // 0x80023344: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80023D54(rdram, ctx);
        goto after_12;
    // 0x80023344: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_12:
    // 0x80023348: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x8002334C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80023350: lw          $v0, 0x43A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43A0);
    // 0x80023354: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80023358: slt         $v0, $s4, $v0
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002335C: bne         $v0, $zero, L_800231C8
    if (ctx->r2 != 0) {
        // 0x80023360: addiu       $s5, $s5, 0x8
        ctx->r21 = ADD32(ctx->r21, 0X8);
            goto L_800231C8;
    }
    // 0x80023360: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
L_80023364:
    // 0x80023364: sw          $s6, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r22;
    // 0x80023368: sw          $s7, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r23;
    // 0x8002336C: sb          $fp, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = ctx->r30;
    // 0x80023370: lbu         $t0, 0x1F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1F);
    // 0x80023374: sb          $t0, 0x54($s2)
    MEM_B(0X54, ctx->r18) = ctx->r8;
    // 0x80023378: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x8002337C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80023380: lw          $v1, 0x40CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X40CC);
    // 0x80023384: sw          $t0, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = ctx->r8;
    // 0x80023388: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002338C: lw          $v0, 0x43A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43A8);
    // 0x80023390: sw          $v0, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->r2;
    // 0x80023394: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80023398: lw          $v0, 0x43AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43AC);
    // 0x8002339C: bne         $v1, $zero, L_80023450
    if (ctx->r3 != 0) {
        // 0x800233A0: sw          $v0, 0x110($s2)
        MEM_W(0X110, ctx->r18) = ctx->r2;
            goto L_80023450;
    }
    // 0x800233A0: sw          $v0, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->r2;
    // 0x800233A4: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800233A8: lw          $v1, 0x43A0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X43A0);
    // 0x800233AC: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800233B0: slt         $v0, $s4, $v1
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800233B4: beq         $v0, $zero, L_800233FC
    if (ctx->r2 == 0) {
        // 0x800233B8: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800233FC;
    }
    // 0x800233B8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800233BC: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x800233C0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_800233C4:
    // 0x800233C4: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x800233C8: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800233CC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800233D0: lh          $v1, 0x40D0($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X40D0);
    // 0x800233D4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800233D8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800233DC: lh          $v0, 0x40D0($at)
    ctx->r2 = MEM_H(ctx->r1, 0X40D0);
    // 0x800233E0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800233E4: bnel        $v0, $zero, L_800233EC
    if (ctx->r2 != 0) {
        // 0x800233E8: addu        $a1, $s4, $zero
        ctx->r5 = ADD32(ctx->r20, 0);
            goto L_800233EC;
    }
    goto skip_2;
    // 0x800233E8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    skip_2:
L_800233EC:
    // 0x800233EC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800233F0: slt         $v0, $s4, $a2
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800233F4: bne         $v0, $zero, L_800233C4
    if (ctx->r2 != 0) {
        // 0x800233F8: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_800233C4;
    }
    // 0x800233F8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_800233FC:
    // 0x800233FC: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x80023400: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x80023404: addiu       $a2, $a2, 0x4366
    ctx->r6 = ADD32(ctx->r6, 0X4366);
    // 0x80023408: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002340C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80023410: lwl         $v1, 0x40D0($at)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r1, 0X40D0);
    // 0x80023414: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023418: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8002341C: lwr         $v1, 0x40D3($at)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r1, 0X40D3);
    // 0x80023420: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023424: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80023428: lwl         $a0, 0x40D4($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r1, 0X40D4);
    // 0x8002342C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023430: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80023434: lwr         $a0, 0x40D7($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r1, 0X40D7);
    // 0x80023438: swl         $v1, 0x0($a2)
    do_swl(rdram, 0X0, ctx->r6, ctx->r3);
    // 0x8002343C: swr         $v1, 0x3($a2)
    do_swr(rdram, 0X3, ctx->r6, ctx->r3);
    // 0x80023440: swl         $a0, 0x4($a2)
    do_swl(rdram, 0X4, ctx->r6, ctx->r4);
    // 0x80023444: swr         $a0, 0x7($a2)
    do_swr(rdram, 0X7, ctx->r6, ctx->r4);
    // 0x80023448: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8002344C: sb          $v0, 0x11F($s2)
    MEM_B(0X11F, ctx->r18) = ctx->r2;
L_80023450:
    // 0x80023450: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80023454: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80023458: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8002345C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80023460: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80023464: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80023468: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8002346C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80023470: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80023474: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80023478: jr          $ra
    // 0x8002347C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8002347C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80023480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023480: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80023484: lw          $v0, 0x4358($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4358);
    // 0x80023488: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8002348C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80023490: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80023494: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80023498: addiu       $a0, $a0, -0x33F4
    ctx->r4 = ADD32(ctx->r4, -0X33F4);
    // 0x8002349C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800234A0: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800234A4: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800234A8: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800234AC: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800234B0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800234B4: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800234B8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800234BC: bne         $v0, $a0, L_80023534
    if (ctx->r2 != ctx->r4) {
        // 0x800234C0: sw          $s0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r16;
            goto L_80023534;
    }
    // 0x800234C0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800234C4: lb          $v1, 0xCC($s2)
    ctx->r3 = MEM_B(ctx->r18, 0XCC);
    // 0x800234C8: lb          $v0, 0xCD($s2)
    ctx->r2 = MEM_B(ctx->r18, 0XCD);
    // 0x800234CC: beq         $v1, $v0, L_80023504
    if (ctx->r3 == ctx->r2) {
        // 0x800234D0: nop
    
            goto L_80023504;
    }
    // 0x800234D0: nop

    // 0x800234D4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800234D8: addiu       $v0, $v0, -0x24E0
    ctx->r2 = ADD32(ctx->r2, -0X24E0);
    // 0x800234DC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800234E0: sw          $v0, 0x4358($at)
    MEM_W(0X4358, ctx->r1) = ctx->r2;
    // 0x800234E4: lb          $v0, 0xCC($s2)
    ctx->r2 = MEM_B(ctx->r18, 0XCC);
    // 0x800234E8: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x800234EC: lbu         $v0, 0xBC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XBC);
    // 0x800234F0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800234F4: sw          $zero, 0x40C4($at)
    MEM_W(0X40C4, ctx->r1) = 0;
    // 0x800234F8: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800234FC: j           L_8002358C
    // 0x80023500: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_8002358C;
    // 0x80023500: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80023504:
    // 0x80023504: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80023508: lbu         $a0, 0x7B7C($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B7C);
    // 0x8002350C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80023510: lb          $v1, 0x435C($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X435C);
    // 0x80023514: andi        $v0, $a0, 0x7F
    ctx->r2 = ctx->r4 & 0X7F;
    // 0x80023518: beq         $v1, $v0, L_80023594
    if (ctx->r3 == ctx->r2) {
        // 0x8002351C: nop
    
            goto L_80023594;
    }
    // 0x8002351C: nop

    // 0x80023520: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023524: sb          $a0, 0x435C($at)
    MEM_B(0X435C, ctx->r1) = ctx->r4;
    // 0x80023528: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002352C: j           L_80023594
    // 0x80023530: sw          $zero, 0x40C4($at)
    MEM_W(0X40C4, ctx->r1) = 0;
        goto L_80023594;
    // 0x80023530: sw          $zero, 0x40C4($at)
    MEM_W(0X40C4, ctx->r1) = 0;
L_80023534:
    // 0x80023534: lb          $v1, 0xCC($s2)
    ctx->r3 = MEM_B(ctx->r18, 0XCC);
    // 0x80023538: lb          $v0, 0xCD($s2)
    ctx->r2 = MEM_B(ctx->r18, 0XCD);
    // 0x8002353C: beq         $v1, $v0, L_80023574
    if (ctx->r3 == ctx->r2) {
        // 0x80023540: addu        $v0, $s2, $v1
        ctx->r2 = ADD32(ctx->r18, ctx->r3);
            goto L_80023574;
    }
    // 0x80023540: addu        $v0, $s2, $v1
    ctx->r2 = ADD32(ctx->r18, ctx->r3);
    // 0x80023544: lbu         $v0, 0xBC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XBC);
    // 0x80023548: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8002354C: lb          $v1, 0x435C($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X435C);
    // 0x80023550: andi        $a0, $v0, 0x7F
    ctx->r4 = ctx->r2 & 0X7F;
    // 0x80023554: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x80023558: beq         $v1, $v0, L_80023594
    if (ctx->r3 == ctx->r2) {
        // 0x8002355C: nop
    
            goto L_80023594;
    }
    // 0x8002355C: nop

    // 0x80023560: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023564: sb          $v0, 0x435C($at)
    MEM_B(0X435C, ctx->r1) = ctx->r2;
    // 0x80023568: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002356C: j           L_80023594
    // 0x80023570: sw          $zero, 0x40C4($at)
    MEM_W(0X40C4, ctx->r1) = 0;
        goto L_80023594;
    // 0x80023570: sw          $zero, 0x40C4($at)
    MEM_W(0X40C4, ctx->r1) = 0;
L_80023574:
    // 0x80023574: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80023578: lbu         $v0, 0x7B7C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B7C);
    // 0x8002357C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023580: sw          $a0, 0x4358($at)
    MEM_W(0X4358, ctx->r1) = ctx->r4;
    // 0x80023584: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023588: sw          $zero, 0x40C4($at)
    MEM_W(0X40C4, ctx->r1) = 0;
L_8002358C:
    // 0x8002358C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023590: sb          $v0, 0x435C($at)
    MEM_B(0X435C, ctx->r1) = ctx->r2;
L_80023594:
    // 0x80023594: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80023598: lbu         $v0, 0x435C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X435C);
    // 0x8002359C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800235A0: lw          $v1, 0x40CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X40CC);
    // 0x800235A4: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800235A8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800235AC: beq         $v1, $zero, L_800238FC
    if (ctx->r3 == 0) {
        // 0x800235B0: sb          $v0, 0x435C($at)
        MEM_B(0X435C, ctx->r1) = ctx->r2;
            goto L_800238FC;
    }
    // 0x800235B0: sb          $v0, 0x435C($at)
    MEM_B(0X435C, ctx->r1) = ctx->r2;
    // 0x800235B4: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800235B8: lw          $v1, 0x40C4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X40C4);
    // 0x800235BC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800235C0: lw          $v0, 0x40C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X40C0);
    // 0x800235C4: beq         $v1, $v0, L_800238EC
    if (ctx->r3 == ctx->r2) {
        // 0x800235C8: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800238EC;
    }
    // 0x800235C8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800235CC: lbu         $t0, 0x54($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X54);
    // 0x800235D0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800235D4: lbu         $v0, 0x4354($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4354);
    // 0x800235D8: sb          $t0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r8;
    // 0x800235DC: lw          $t0, 0xDC($s2)
    ctx->r8 = MEM_W(ctx->r18, 0XDC);
    // 0x800235E0: sb          $v0, 0x54($s2)
    MEM_B(0X54, ctx->r18) = ctx->r2;
    // 0x800235E4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800235E8: lw          $v0, 0x4350($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4350);
    // 0x800235EC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800235F0: lw          $s6, 0x18($s2)
    ctx->r22 = MEM_W(ctx->r18, 0X18);
    // 0x800235F4: lw          $s7, 0x1C($s2)
    ctx->r23 = MEM_W(ctx->r18, 0X1C);
    // 0x800235F8: lbu         $fp, 0x4C($s2)
    ctx->r30 = MEM_BU(ctx->r18, 0X4C);
    // 0x800235FC: jal         0x800169C8
    // 0x80023600: sw          $v0, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = ctx->r2;
    func_800169C8(rdram, ctx);
        goto after_0;
    // 0x80023600: sw          $v0, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = ctx->r2;
    after_0:
    // 0x80023604: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80023608: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8002360C: jal         0x80016980
    // 0x80023610: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_1;
    // 0x80023610: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    after_1:
    // 0x80023614: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80023618: sb          $zero, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = 0;
    // 0x8002361C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80023620: lw          $v1, 0x40C4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X40C4);
    // 0x80023624: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80023628: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8002362C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80023630: addiu       $a1, $a1, 0x40D0
    ctx->r5 = ADD32(ctx->r5, 0X40D0);
    // 0x80023634: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x80023638: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8002363C: jal         0x80024588
    // 0x80023640: addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
    func_80024588(rdram, ctx);
        goto after_2;
    // 0x80023640: addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
    after_2:
    // 0x80023644: jal         0x800169C8
    // 0x80023648: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_800169C8(rdram, ctx);
        goto after_3;
    // 0x80023648: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_3:
    // 0x8002364C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80023650: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80023654: jal         0x80016980
    // 0x80023658: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_4;
    // 0x80023658: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    after_4:
    // 0x8002365C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80023660: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80023664: addiu       $s0, $s0, 0x4210
    ctx->r16 = ADD32(ctx->r16, 0X4210);
    // 0x80023668: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8002366C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80023670: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x80023674: jal         0x80024014
    // 0x80023678: sb          $zero, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = 0;
    func_80024014(rdram, ctx);
        goto after_5;
    // 0x80023678: sb          $zero, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = 0;
    after_5:
    // 0x8002367C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80023680: lw          $v0, 0x43A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43A0);
    // 0x80023684: blez        $v0, L_800237FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80023688: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_800237FC;
    }
    // 0x80023688: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x8002368C: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x80023690: addu        $s5, $s0, $zero
    ctx->r21 = ADD32(ctx->r16, 0);
L_80023694:
    // 0x80023694: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80023698: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x8002369C: lb          $v0, 0x4214($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X4214);
    // 0x800236A0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800236A4: jal         0x80016980
    // 0x800236A8: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_6;
    // 0x800236A8: sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    after_6:
    // 0x800236AC: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x800236B0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800236B4: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x800236B8: lbu         $v0, 0x4215($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4215);
    // 0x800236BC: sb          $v0, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = ctx->r2;
    // 0x800236C0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800236C4: lw          $v0, 0x43B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43B0);
    // 0x800236C8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800236CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800236D0: jal         0x80024C30
    // 0x800236D4: sw          $v0, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->r2;
    func_80024C30(rdram, ctx);
        goto after_7;
    // 0x800236D4: sw          $v0, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->r2;
    after_7:
    // 0x800236D8: lw          $a2, 0x1C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X1C);
    // 0x800236DC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800236E0: addiu       $a1, $a2, -0x2
    ctx->r5 = ADD32(ctx->r6, -0X2);
    // 0x800236E4: jal         0x80023E94
    // 0x800236E8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    func_80023E94(rdram, ctx);
        goto after_8;
    // 0x800236E8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    after_8:
    // 0x800236EC: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800236F0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800236F4: addu        $at, $at, $s4
    ctx->r1 = ADD32(ctx->r1, ctx->r20);
    // 0x800236F8: sb          $s1, 0x4216($at)
    MEM_B(0X4216, ctx->r1) = ctx->r17;
    // 0x800236FC: beq         $s1, $zero, L_80023758
    if (ctx->r17 == 0) {
        // 0x80023700: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80023758;
    }
    // 0x80023700: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80023704: jal         0x80023F50
    // 0x80023708: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80023F50(rdram, ctx);
        goto after_9;
    // 0x80023708: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x8002370C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80023710: jal         0x80023A14
    // 0x80023714: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80023A14(rdram, ctx);
        goto after_10;
    // 0x80023714: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80023718: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002371C: sra         $s0, $v0, 16
    ctx->r16 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80023720: slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80023724: bne         $v0, $zero, L_80023748
    if (ctx->r2 != 0) {
        // 0x80023728: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_80023748;
    }
    // 0x80023728: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8002372C: addiu       $v1, $s0, 0x2710
    ctx->r3 = ADD32(ctx->r16, 0X2710);
    // 0x80023730: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x80023734: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80023738: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8002373C: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80023740: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80023744: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
L_80023748:
    // 0x80023748: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x8002374C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80023750: j           L_8002377C
    // 0x80023754: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
        goto L_8002377C;
    // 0x80023754: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_80023758:
    // 0x80023758: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8002375C: jal         0x80023A14
    // 0x80023760: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80023A14(rdram, ctx);
        goto after_11;
    // 0x80023760: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x80023764: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80023768: sra         $s0, $v0, 16
    ctx->r16 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8002376C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80023770: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x80023774: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80023778: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_8002377C:
    // 0x8002377C: jal         0x80024974
    // 0x80023780: nop

    func_80024974(rdram, ctx);
        goto after_12;
    // 0x80023780: nop

    after_12:
    // 0x80023784: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80023788: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x8002378C: lh          $v0, 0x4210($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X4210);
    // 0x80023790: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80023794: slti        $v0, $s0, 0x7531
    ctx->r2 = SIGNED(ctx->r16) < 0X7531 ? 1 : 0;
    // 0x80023798: beql        $v0, $zero, L_800237A0
    if (ctx->r2 == 0) {
        // 0x8002379C: addiu       $s0, $zero, 0x7530
        ctx->r16 = ADD32(0, 0X7530);
            goto L_800237A0;
    }
    goto skip_0;
    // 0x8002379C: addiu       $s0, $zero, 0x7530
    ctx->r16 = ADD32(0, 0X7530);
    skip_0:
L_800237A0:
    // 0x800237A0: slti        $v0, $s0, -0x7530
    ctx->r2 = SIGNED(ctx->r16) < -0X7530 ? 1 : 0;
    // 0x800237A4: bnel        $v0, $zero, L_800237AC
    if (ctx->r2 != 0) {
        // 0x800237A8: addiu       $s0, $zero, -0x7530
        ctx->r16 = ADD32(0, -0X7530);
            goto L_800237AC;
    }
    goto skip_1;
    // 0x800237A8: addiu       $s0, $zero, -0x7530
    ctx->r16 = ADD32(0, -0X7530);
    skip_1:
L_800237AC:
    // 0x800237AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800237B0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800237B4: addu        $at, $at, $s4
    ctx->r1 = ADD32(ctx->r1, ctx->r20);
    // 0x800237B8: sh          $s0, 0x4210($at)
    MEM_H(0X4210, ctx->r1) = ctx->r16;
    // 0x800237BC: lw          $a3, 0x1C($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X1C);
    // 0x800237C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800237C4: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800237C8: addiu       $a2, $a3, -0x2
    ctx->r6 = ADD32(ctx->r7, -0X2);
    // 0x800237CC: jal         0x80023C74
    // 0x800237D0: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    func_80023C74(rdram, ctx);
        goto after_13;
    // 0x800237D0: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    after_13:
    // 0x800237D4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800237D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800237DC: jal         0x80023D54
    // 0x800237E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80023D54(rdram, ctx);
        goto after_14;
    // 0x800237E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_14:
    // 0x800237E4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800237E8: lw          $v0, 0x43A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43A0);
    // 0x800237EC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800237F0: slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800237F4: bne         $v0, $zero, L_80023694
    if (ctx->r2 != 0) {
        // 0x800237F8: addiu       $s5, $s5, 0x8
        ctx->r21 = ADD32(ctx->r21, 0X8);
            goto L_80023694;
    }
    // 0x800237F8: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
L_800237FC:
    // 0x800237FC: sw          $s6, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r22;
    // 0x80023800: sw          $s7, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r23;
    // 0x80023804: sb          $fp, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = ctx->r30;
    // 0x80023808: lbu         $t0, 0x1F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1F);
    // 0x8002380C: sb          $t0, 0x54($s2)
    MEM_B(0X54, ctx->r18) = ctx->r8;
    // 0x80023810: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x80023814: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80023818: lw          $v1, 0x43A0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X43A0);
    // 0x8002381C: sw          $t0, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = ctx->r8;
    // 0x80023820: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80023824: lw          $v0, 0x43A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43A8);
    // 0x80023828: sw          $v0, 0xB0($s2)
    MEM_W(0XB0, ctx->r18) = ctx->r2;
    // 0x8002382C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80023830: lw          $v0, 0x43AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43AC);
    // 0x80023834: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80023838: sw          $v0, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->r2;
    // 0x8002383C: slt         $v0, $s3, $v1
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80023840: beq         $v0, $zero, L_80023888
    if (ctx->r2 == 0) {
        // 0x80023844: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80023888;
    }
    // 0x80023844: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80023848: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x8002384C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_80023850:
    // 0x80023850: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
    // 0x80023854: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80023858: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8002385C: lh          $v1, 0x4210($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X4210);
    // 0x80023860: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023864: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80023868: lh          $v0, 0x4210($at)
    ctx->r2 = MEM_H(ctx->r1, 0X4210);
    // 0x8002386C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80023870: bnel        $v0, $zero, L_80023878
    if (ctx->r2 != 0) {
        // 0x80023874: addu        $s1, $s3, $zero
        ctx->r17 = ADD32(ctx->r19, 0);
            goto L_80023878;
    }
    goto skip_2;
    // 0x80023874: addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
    skip_2:
L_80023878:
    // 0x80023878: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8002387C: slt         $v0, $s3, $a1
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80023880: bne         $v0, $zero, L_80023850
    if (ctx->r2 != 0) {
        // 0x80023884: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_80023850;
    }
    // 0x80023884: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_80023888:
    // 0x80023888: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8002388C: lw          $a0, 0x40C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X40C4);
    // 0x80023890: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
    // 0x80023894: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80023898: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8002389C: lhu         $v1, 0x4210($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X4210);
    // 0x800238A0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800238A4: lw          $a1, 0x40C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X40C0);
    // 0x800238A8: sll         $a2, $a0, 3
    ctx->r6 = S32(ctx->r4 << 3);
    // 0x800238AC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800238B0: sra         $v0, $v1, 16
    ctx->r2 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800238B4: srl         $v1, $v1, 31
    ctx->r3 = S32(U32(ctx->r3) >> 31);
    // 0x800238B8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800238BC: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800238C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800238C4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800238C8: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x800238CC: sh          $v0, 0x40D2($at)
    MEM_H(0X40D2, ctx->r1) = ctx->r2;
    // 0x800238D0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800238D4: sw          $a0, 0x40C4($at)
    MEM_W(0X40C4, ctx->r1) = ctx->r4;
    // 0x800238D8: bne         $a0, $a1, L_800238EC
    if (ctx->r4 != ctx->r5) {
        // 0x800238DC: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_800238EC;
    }
    // 0x800238DC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800238E0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800238E4: sw          $zero, 0x40CC($at)
    MEM_W(0X40CC, ctx->r1) = 0;
    // 0x800238E8: sb          $v0, 0x11F($s2)
    MEM_B(0X11F, ctx->r18) = ctx->r2;
L_800238EC:
    // 0x800238EC: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800238F0: lw          $v0, 0x40CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X40CC);
    // 0x800238F4: bne         $v0, $zero, L_800239E4
    if (ctx->r2 != 0) {
        // 0x800238F8: nop
    
            goto L_800239E4;
    }
    // 0x800238F8: nop

L_800238FC:
    // 0x800238FC: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80023900: addiu       $s0, $s0, 0x40D0
    ctx->r16 = ADD32(ctx->r16, 0X40D0);
    // 0x80023904: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80023908: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8002390C: lh          $a1, 0x40D2($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X40D2);
    // 0x80023910: jal         0x80025750
    // 0x80023914: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    func_80025750(rdram, ctx);
        goto after_15;
    // 0x80023914: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    after_15:
    // 0x80023918: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8002391C: lw          $v1, 0x40C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X40C0);
    // 0x80023920: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80023924: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023928: sh          $v0, 0x40D2($at)
    MEM_H(0X40D2, ctx->r1) = ctx->r2;
    // 0x8002392C: slt         $v1, $s3, $v1
    ctx->r3 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80023930: beq         $v1, $zero, L_8002399C
    if (ctx->r3 == 0) {
        // 0x80023934: sll         $v0, $s1, 3
        ctx->r2 = S32(ctx->r17 << 3);
            goto L_8002399C;
    }
    // 0x80023934: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
    // 0x80023938: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x8002393C: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
L_80023940:
    // 0x80023940: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80023944: addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    // 0x80023948: lh          $a0, 0x40D0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X40D0);
    // 0x8002394C: jal         0x80025750
    // 0x80023950: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    func_80025750(rdram, ctx);
        goto after_16;
    // 0x80023950: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    after_16:
    // 0x80023954: sll         $v1, $s1, 3
    ctx->r3 = S32(ctx->r17 << 3);
    // 0x80023958: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x8002395C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023960: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80023964: lh          $v1, 0x40D2($at)
    ctx->r3 = MEM_H(ctx->r1, 0X40D2);
    // 0x80023968: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8002396C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80023970: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80023974: bnel        $v1, $zero, L_8002397C
    if (ctx->r3 != 0) {
        // 0x80023978: addu        $s1, $s3, $zero
        ctx->r17 = ADD32(ctx->r19, 0);
            goto L_8002397C;
    }
    goto skip_3;
    // 0x80023978: addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
    skip_3:
L_8002397C:
    // 0x8002397C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80023980: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80023984: lw          $v0, 0x40C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X40C0);
    // 0x80023988: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8002398C: slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80023990: bne         $v0, $zero, L_80023940
    if (ctx->r2 != 0) {
        // 0x80023994: addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
            goto L_80023940;
    }
    // 0x80023994: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80023998: sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17 << 3);
L_8002399C:
    // 0x8002399C: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x800239A0: addiu       $a2, $a2, 0x4366
    ctx->r6 = ADD32(ctx->r6, 0X4366);
    // 0x800239A4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800239A8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800239AC: lwl         $v1, 0x40D0($at)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r1, 0X40D0);
    // 0x800239B0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800239B4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800239B8: lwr         $v1, 0x40D3($at)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r1, 0X40D3);
    // 0x800239BC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800239C0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800239C4: lwl         $a0, 0x40D4($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r1, 0X40D4);
    // 0x800239C8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800239CC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800239D0: lwr         $a0, 0x40D7($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r1, 0X40D7);
    // 0x800239D4: swl         $v1, 0x0($a2)
    do_swl(rdram, 0X0, ctx->r6, ctx->r3);
    // 0x800239D8: swr         $v1, 0x3($a2)
    do_swr(rdram, 0X3, ctx->r6, ctx->r3);
    // 0x800239DC: swl         $a0, 0x4($a2)
    do_swl(rdram, 0X4, ctx->r6, ctx->r4);
    // 0x800239E0: swr         $a0, 0x7($a2)
    do_swr(rdram, 0X7, ctx->r6, ctx->r4);
L_800239E4:
    // 0x800239E4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800239E8: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800239EC: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800239F0: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800239F4: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800239F8: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800239FC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80023A00: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80023A04: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80023A08: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80023A0C: jr          $ra
    // 0x80023A10: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80023A10: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80023A14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023A14: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80023A18: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x80023A1C: addu        $t2, $a1, $zero
    ctx->r10 = ADD32(ctx->r5, 0);
    // 0x80023A20: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80023A24: addiu       $a2, $a2, -0x2BC8
    ctx->r6 = ADD32(ctx->r6, -0X2BC8);
    // 0x80023A28: or          $v0, $sp, $a2
    ctx->r2 = ctx->r29 | ctx->r6;
    // 0x80023A2C: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x80023A30: beq         $v0, $zero, L_80023A90
    if (ctx->r2 == 0) {
        // 0x80023A34: addu        $a3, $sp, $zero
        ctx->r7 = ADD32(ctx->r29, 0);
            goto L_80023A90;
    }
    // 0x80023A34: addu        $a3, $sp, $zero
    ctx->r7 = ADD32(ctx->r29, 0);
    // 0x80023A38: addiu       $t1, $a2, 0x40
    ctx->r9 = ADD32(ctx->r6, 0X40);
L_80023A3C:
    // 0x80023A3C: lwl         $v0, 0x0($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r6, 0X0);
    // 0x80023A40: lwr         $v0, 0x3($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r6, 0X3);
    // 0x80023A44: lwl         $v1, 0x4($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r6, 0X4);
    // 0x80023A48: lwr         $v1, 0x7($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r6, 0X7);
    // 0x80023A4C: lwl         $a0, 0x8($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r6, 0X8);
    // 0x80023A50: lwr         $a0, 0xB($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r6, 0XB);
    // 0x80023A54: lwl         $a1, 0xC($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, ctx->r6, 0XC);
    // 0x80023A58: lwr         $a1, 0xF($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, ctx->r6, 0XF);
    // 0x80023A5C: swl         $v0, 0x0($a3)
    do_swl(rdram, 0X0, ctx->r7, ctx->r2);
    // 0x80023A60: swr         $v0, 0x3($a3)
    do_swr(rdram, 0X3, ctx->r7, ctx->r2);
    // 0x80023A64: swl         $v1, 0x4($a3)
    do_swl(rdram, 0X4, ctx->r7, ctx->r3);
    // 0x80023A68: swr         $v1, 0x7($a3)
    do_swr(rdram, 0X7, ctx->r7, ctx->r3);
    // 0x80023A6C: swl         $a0, 0x8($a3)
    do_swl(rdram, 0X8, ctx->r7, ctx->r4);
    // 0x80023A70: swr         $a0, 0xB($a3)
    do_swr(rdram, 0XB, ctx->r7, ctx->r4);
    // 0x80023A74: swl         $a1, 0xC($a3)
    do_swl(rdram, 0XC, ctx->r7, ctx->r5);
    // 0x80023A78: swr         $a1, 0xF($a3)
    do_swr(rdram, 0XF, ctx->r7, ctx->r5);
    // 0x80023A7C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80023A80: bne         $a2, $t1, L_80023A3C
    if (ctx->r6 != ctx->r9) {
        // 0x80023A84: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_80023A3C;
    }
    // 0x80023A84: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80023A88: j           L_80023AC4
    // 0x80023A8C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
        goto L_80023AC4;
    // 0x80023A8C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80023A90:
    // 0x80023A90: addiu       $t1, $a2, 0x40
    ctx->r9 = ADD32(ctx->r6, 0X40);
L_80023A94:
    // 0x80023A94: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80023A98: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x80023A9C: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x80023AA0: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x80023AA4: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80023AA8: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x80023AAC: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x80023AB0: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x80023AB4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80023AB8: bne         $a2, $t1, L_80023A94
    if (ctx->r6 != ctx->r9) {
        // 0x80023ABC: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_80023A94;
    }
    // 0x80023ABC: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80023AC0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80023AC4:
    // 0x80023AC4: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80023AC8: addiu       $v1, $v1, 0x43A8
    ctx->r3 = ADD32(ctx->r3, 0X43A8);
    // 0x80023ACC: sll         $v0, $t2, 2
    ctx->r2 = S32(ctx->r10 << 2);
    // 0x80023AD0: addu        $t1, $v0, $v1
    ctx->r9 = ADD32(ctx->r2, ctx->r3);
    // 0x80023AD4: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    // 0x80023AD8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80023ADC: sb          $zero, 0x125($t0)
    MEM_B(0X125, ctx->r8) = 0;
    // 0x80023AE0: sw          $zero, 0x130($t0)
    MEM_W(0X130, ctx->r8) = 0;
L_80023AE4:
    // 0x80023AE4: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x80023AE8: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80023AEC: addiu       $a0, $zero, -0x6
    ctx->r4 = ADD32(0, -0X6);
    // 0x80023AF0: addiu       $v0, $a2, 0x4
    ctx->r2 = ADD32(ctx->r6, 0X4);
    // 0x80023AF4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_80023AF8:
    // 0x80023AF8: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80023AFC: beql        $v0, $zero, L_80023B40
    if (ctx->r2 == 0) {
        // 0x80023B00: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80023B40;
    }
    goto skip_0;
    // 0x80023B00: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x80023B04: subu        $v0, $a3, $a0
    ctx->r2 = SUB32(ctx->r7, ctx->r4);
    // 0x80023B08: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80023B0C: slti        $v0, $a0, 0x12
    ctx->r2 = SIGNED(ctx->r4) < 0X12 ? 1 : 0;
    // 0x80023B10: beql        $v0, $zero, L_80023B40
    if (ctx->r2 == 0) {
        // 0x80023B14: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80023B40;
    }
    goto skip_1;
    // 0x80023B14: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_1:
L_80023B18:
    // 0x80023B18: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80023B1C: bne         $v0, $zero, L_80023B30
    if (ctx->r2 != 0) {
        // 0x80023B20: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80023B30;
    }
    // 0x80023B20: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80023B24: lw          $v0, 0x130($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X130);
    // 0x80023B28: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80023B2C: sw          $v0, 0x130($t0)
    MEM_W(0X130, ctx->r8) = ctx->r2;
L_80023B30:
    // 0x80023B30: slti        $v0, $a0, 0x12
    ctx->r2 = SIGNED(ctx->r4) < 0X12 ? 1 : 0;
    // 0x80023B34: bne         $v0, $zero, L_80023B18
    if (ctx->r2 != 0) {
        // 0x80023B38: addiu       $v1, $v1, 0x12
        ctx->r3 = ADD32(ctx->r3, 0X12);
            goto L_80023B18;
    }
    // 0x80023B38: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80023B3C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80023B40:
    // 0x80023B40: slti        $v0, $a0, 0x12
    ctx->r2 = SIGNED(ctx->r4) < 0X12 ? 1 : 0;
    // 0x80023B44: bne         $v0, $zero, L_80023AF8
    if (ctx->r2 != 0) {
        // 0x80023B48: addiu       $v1, $v1, 0x12
        ctx->r3 = ADD32(ctx->r3, 0X12);
            goto L_80023AF8;
    }
    // 0x80023B48: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80023B4C: lb          $v0, 0x125($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X125);
    // 0x80023B50: lb          $v1, 0x0($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X0);
    // 0x80023B54: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80023B58: beq         $v0, $zero, L_80023B64
    if (ctx->r2 == 0) {
        // 0x80023B5C: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_80023B64;
    }
    // 0x80023B5C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80023B60: sb          $a0, 0x125($t0)
    MEM_B(0X125, ctx->r8) = ctx->r4;
L_80023B64:
    // 0x80023B64: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80023B68: slti        $v0, $a2, 0xA
    ctx->r2 = SIGNED(ctx->r6) < 0XA ? 1 : 0;
    // 0x80023B6C: bne         $v0, $zero, L_80023AE4
    if (ctx->r2 != 0) {
        // 0x80023B70: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80023AE4;
    }
    // 0x80023B70: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80023B74: lw          $v0, 0x130($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X130);
    // 0x80023B78: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80023B7C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80023B80: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80023B84: subu        $a3, $v1, $v0
    ctx->r7 = SUB32(ctx->r3, ctx->r2);
    // 0x80023B88: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80023B8C: addiu       $a2, $sp, 0x41
    ctx->r6 = ADD32(ctx->r29, 0X41);
    // 0x80023B90: addiu       $t1, $sp, 0x49
    ctx->r9 = ADD32(ctx->r29, 0X49);
L_80023B94:
    // 0x80023B94: lb          $a0, 0x0($a2)
    ctx->r4 = MEM_B(ctx->r6, 0X0);
    // 0x80023B98: lb          $v1, 0x0($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X0);
    // 0x80023B9C: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // 0x80023BA0: bltzl       $v0, L_80023BA8
    if (SIGNED(ctx->r2) < 0) {
        // 0x80023BA4: subu        $v0, $v1, $a0
        ctx->r2 = SUB32(ctx->r3, ctx->r4);
            goto L_80023BA8;
    }
    goto skip_2;
    // 0x80023BA4: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    skip_2:
L_80023BA8:
    // 0x80023BA8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80023BAC: addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // 0x80023BB0: lh          $v0, 0x0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X0);
    // 0x80023BB4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80023BB8: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x80023BBC: slt         $v0, $a1, $t1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80023BC0: bne         $v0, $zero, L_80023B94
    if (ctx->r2 != 0) {
        // 0x80023BC4: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80023B94;
    }
    // 0x80023BC4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80023BC8: sll         $v0, $t2, 2
    ctx->r2 = S32(ctx->r10 << 2);
    // 0x80023BCC: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80023BD0: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80023BD4: lw          $a1, 0x43A8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X43A8);
    // 0x80023BD8: lb          $v0, 0x73($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X73);
    // 0x80023BDC: addiu       $v1, $zero, -0x3E8
    ctx->r3 = ADD32(0, -0X3E8);
    // 0x80023BE0: lb          $a0, 0x74($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X74);
    // 0x80023BE4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80023BE8: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80023BEC: beq         $a0, $zero, L_80023BF8
    if (ctx->r4 == 0) {
        // 0x80023BF0: and         $v1, $v0, $v1
        ctx->r3 = ctx->r2 & ctx->r3;
            goto L_80023BF8;
    }
    // 0x80023BF0: and         $v1, $v0, $v1
    ctx->r3 = ctx->r2 & ctx->r3;
    // 0x80023BF4: addiu       $v1, $v1, -0x9C4
    ctx->r3 = ADD32(ctx->r3, -0X9C4);
L_80023BF8:
    // 0x80023BF8: lb          $v0, 0x75($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X75);
    // 0x80023BFC: bnel        $v0, $zero, L_80023C04
    if (ctx->r2 != 0) {
        // 0x80023C00: addiu       $v1, $v1, -0x7D0
        ctx->r3 = ADD32(ctx->r3, -0X7D0);
            goto L_80023C04;
    }
    goto skip_3;
    // 0x80023C00: addiu       $v1, $v1, -0x7D0
    ctx->r3 = ADD32(ctx->r3, -0X7D0);
    skip_3:
L_80023C04:
    // 0x80023C04: lb          $v0, 0x76($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X76);
    // 0x80023C08: bnel        $v0, $zero, L_80023C10
    if (ctx->r2 != 0) {
        // 0x80023C0C: addiu       $v1, $v1, -0x3E8
        ctx->r3 = ADD32(ctx->r3, -0X3E8);
            goto L_80023C10;
    }
    goto skip_4;
    // 0x80023C0C: addiu       $v1, $v1, -0x3E8
    ctx->r3 = ADD32(ctx->r3, -0X3E8);
    skip_4:
L_80023C10:
    // 0x80023C10: lb          $v0, 0x85($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X85);
    // 0x80023C14: bnel        $v0, $zero, L_80023C1C
    if (ctx->r2 != 0) {
        // 0x80023C18: addiu       $v1, $v1, -0x64
        ctx->r3 = ADD32(ctx->r3, -0X64);
            goto L_80023C1C;
    }
    goto skip_5;
    // 0x80023C18: addiu       $v1, $v1, -0x64
    ctx->r3 = ADD32(ctx->r3, -0X64);
    skip_5:
L_80023C1C:
    // 0x80023C1C: lb          $v0, 0x86($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X86);
    // 0x80023C20: bnel        $v0, $zero, L_80023C28
    if (ctx->r2 != 0) {
        // 0x80023C24: addiu       $v1, $v1, -0xFA
        ctx->r3 = ADD32(ctx->r3, -0XFA);
            goto L_80023C28;
    }
    goto skip_6;
    // 0x80023C24: addiu       $v1, $v1, -0xFA
    ctx->r3 = ADD32(ctx->r3, -0XFA);
    skip_6:
L_80023C28:
    // 0x80023C28: lb          $v0, 0x87($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X87);
    // 0x80023C2C: bnel        $v0, $zero, L_80023C34
    if (ctx->r2 != 0) {
        // 0x80023C30: addiu       $v1, $v1, -0xC8
        ctx->r3 = ADD32(ctx->r3, -0XC8);
            goto L_80023C34;
    }
    goto skip_7;
    // 0x80023C30: addiu       $v1, $v1, -0xC8
    ctx->r3 = ADD32(ctx->r3, -0XC8);
    skip_7:
L_80023C34:
    // 0x80023C34: lb          $v0, 0x88($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X88);
    // 0x80023C38: bnel        $v0, $zero, L_80023C40
    if (ctx->r2 != 0) {
        // 0x80023C3C: addiu       $v1, $v1, -0x64
        ctx->r3 = ADD32(ctx->r3, -0X64);
            goto L_80023C40;
    }
    goto skip_8;
    // 0x80023C3C: addiu       $v1, $v1, -0x64
    ctx->r3 = ADD32(ctx->r3, -0X64);
    skip_8:
L_80023C40:
    // 0x80023C40: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x80023C44: sltu        $v0, $zero, $v1
    ctx->r2 = 0 < ctx->r3 ? 1 : 0;
    // 0x80023C48: sb          $v0, 0x126($t0)
    MEM_B(0X126, ctx->r8) = ctx->r2;
    // 0x80023C4C: slti        $v0, $a3, 0x7531
    ctx->r2 = SIGNED(ctx->r7) < 0X7531 ? 1 : 0;
    // 0x80023C50: beql        $v0, $zero, L_80023C58
    if (ctx->r2 == 0) {
        // 0x80023C54: addiu       $a3, $zero, 0x7530
        ctx->r7 = ADD32(0, 0X7530);
            goto L_80023C58;
    }
    goto skip_9;
    // 0x80023C54: addiu       $a3, $zero, 0x7530
    ctx->r7 = ADD32(0, 0X7530);
    skip_9:
L_80023C58:
    // 0x80023C58: slti        $v0, $a3, -0x7530
    ctx->r2 = SIGNED(ctx->r7) < -0X7530 ? 1 : 0;
    // 0x80023C5C: bnel        $v0, $zero, L_80023C64
    if (ctx->r2 != 0) {
        // 0x80023C60: addiu       $a3, $zero, -0x7530
        ctx->r7 = ADD32(0, -0X7530);
            goto L_80023C64;
    }
    goto skip_10;
    // 0x80023C60: addiu       $a3, $zero, -0x7530
    ctx->r7 = ADD32(0, -0X7530);
    skip_10:
L_80023C64:
    // 0x80023C64: sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7 << 16);
    // 0x80023C68: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80023C6C: jr          $ra
    // 0x80023C70: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80023C70: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80023C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023C74: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80023C78: addiu       $v1, $a2, 0x6
    ctx->r3 = ADD32(ctx->r6, 0X6);
    // 0x80023C7C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80023C80: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80023C84: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80023C88: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80023C8C: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80023C90: lw          $a0, 0x43A8($at)
    ctx->r4 = MEM_W(ctx->r1, 0X43A8);
    // 0x80023C94: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80023C98: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80023C9C: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80023CA0: lw          $v1, 0x43A8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X43A8);
    // 0x80023CA4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80023CA8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80023CAC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80023CB0: slti        $v0, $a2, -0x6
    ctx->r2 = SIGNED(ctx->r6) < -0X6 ? 1 : 0;
    // 0x80023CB4: beq         $v0, $zero, L_80023CC0
    if (ctx->r2 == 0) {
        // 0x80023CB8: addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
            goto L_80023CC0;
    }
    // 0x80023CB8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80023CBC: addiu       $a2, $zero, -0x6
    ctx->r6 = ADD32(0, -0X6);
L_80023CC0:
    // 0x80023CC0: slti        $v0, $a3, 0x12
    ctx->r2 = SIGNED(ctx->r7) < 0X12 ? 1 : 0;
    // 0x80023CC4: beql        $v0, $zero, L_80023CCC
    if (ctx->r2 == 0) {
        // 0x80023CC8: addiu       $a3, $zero, 0x11
        ctx->r7 = ADD32(0, 0X11);
            goto L_80023CCC;
    }
    goto skip_0;
    // 0x80023CC8: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    skip_0:
L_80023CCC:
    // 0x80023CCC: slt         $v0, $a3, $a2
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80023CD0: bne         $v0, $zero, L_80023D48
    if (ctx->r2 != 0) {
        // 0x80023CD4: addiu       $t0, $v1, 0x9
        ctx->r8 = ADD32(ctx->r3, 0X9);
            goto L_80023D48;
    }
    // 0x80023CD4: addiu       $t0, $v1, 0x9
    ctx->r8 = ADD32(ctx->r3, 0X9);
    // 0x80023CD8: addiu       $a1, $a0, 0x9
    ctx->r5 = ADD32(ctx->r4, 0X9);
L_80023CDC:
    // 0x80023CDC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80023CE0: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x80023CE4: lbu         $v0, -0x8($t0)
    ctx->r2 = MEM_BU(ctx->r8, -0X8);
    // 0x80023CE8: sb          $v0, -0x8($a1)
    MEM_B(-0X8, ctx->r5) = ctx->r2;
    // 0x80023CEC: lbu         $v0, -0x7($t0)
    ctx->r2 = MEM_BU(ctx->r8, -0X7);
    // 0x80023CF0: sb          $v0, -0x7($a1)
    MEM_B(-0X7, ctx->r5) = ctx->r2;
    // 0x80023CF4: lbu         $v0, -0x6($t0)
    ctx->r2 = MEM_BU(ctx->r8, -0X6);
    // 0x80023CF8: sb          $v0, -0x6($a1)
    MEM_B(-0X6, ctx->r5) = ctx->r2;
    // 0x80023CFC: lbu         $v0, -0x5($t0)
    ctx->r2 = MEM_BU(ctx->r8, -0X5);
    // 0x80023D00: sb          $v0, -0x5($a1)
    MEM_B(-0X5, ctx->r5) = ctx->r2;
    // 0x80023D04: lbu         $v0, -0x4($t0)
    ctx->r2 = MEM_BU(ctx->r8, -0X4);
    // 0x80023D08: sb          $v0, -0x4($a1)
    MEM_B(-0X4, ctx->r5) = ctx->r2;
    // 0x80023D0C: lbu         $v0, -0x3($t0)
    ctx->r2 = MEM_BU(ctx->r8, -0X3);
    // 0x80023D10: sb          $v0, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r2;
    // 0x80023D14: lbu         $v0, -0x2($t0)
    ctx->r2 = MEM_BU(ctx->r8, -0X2);
    // 0x80023D18: sb          $v0, -0x2($a1)
    MEM_B(-0X2, ctx->r5) = ctx->r2;
    // 0x80023D1C: lbu         $v0, -0x1($t0)
    ctx->r2 = MEM_BU(ctx->r8, -0X1);
    // 0x80023D20: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80023D24: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80023D28: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
    // 0x80023D2C: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x80023D30: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    // 0x80023D34: addiu       $t0, $t0, 0x12
    ctx->r8 = ADD32(ctx->r8, 0X12);
    // 0x80023D38: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80023D3C: slt         $v0, $a3, $a2
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80023D40: beq         $v0, $zero, L_80023CDC
    if (ctx->r2 == 0) {
        // 0x80023D44: addiu       $a1, $a1, 0x12
        ctx->r5 = ADD32(ctx->r5, 0X12);
            goto L_80023CDC;
    }
    // 0x80023D44: addiu       $a1, $a1, 0x12
    ctx->r5 = ADD32(ctx->r5, 0X12);
L_80023D48:
    // 0x80023D48: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80023D4C: jr          $ra
    // 0x80023D50: nop

    return;
    // 0x80023D50: nop

;}
RECOMP_FUNC void func_80023D54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023D54: lw          $t0, 0x18($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X18);
    // 0x80023D58: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80023D5C: lw          $a3, 0x1C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1C);
    // 0x80023D60: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80023D64: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80023D68: lw          $v1, 0x43A8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X43A8);
    // 0x80023D6C: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80023D70: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80023D74: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80023D78: lw          $v0, 0x43A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43A8);
    // 0x80023D7C: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x80023D80: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80023D84: sll         $a0, $a3, 3
    ctx->r4 = S32(ctx->r7 << 3);
    // 0x80023D88: addu        $a0, $a0, $a3
    ctx->r4 = ADD32(ctx->r4, ctx->r7);
    // 0x80023D8C: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x80023D90: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80023D94: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80023D98: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x80023D9C: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80023DA0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80023DA4: sb          $a1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r5;
    // 0x80023DA8: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x80023DAC: sb          $a0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r4;
    // 0x80023DB0: lbu         $a0, 0x2($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X2);
    // 0x80023DB4: sb          $a0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r4;
    // 0x80023DB8: lbu         $a0, 0x3($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X3);
    // 0x80023DBC: sb          $a0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r4;
    // 0x80023DC0: lbu         $a0, 0x4($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X4);
    // 0x80023DC4: addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // 0x80023DC8: sb          $a0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r4;
    // 0x80023DCC: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80023DD0: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80023DD4: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x80023DD8: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x80023DDC: sb          $a0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r4;
    // 0x80023DE0: lbu         $a0, 0x2($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X2);
    // 0x80023DE4: sb          $a0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r4;
    // 0x80023DE8: lbu         $a0, 0x3($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X3);
    // 0x80023DEC: sb          $a0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r4;
    // 0x80023DF0: lbu         $a0, 0x4($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X4);
    // 0x80023DF4: addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // 0x80023DF8: sb          $a0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r4;
    // 0x80023DFC: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80023E00: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80023E04: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x80023E08: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x80023E0C: sb          $a0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r4;
    // 0x80023E10: lbu         $a0, 0x2($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X2);
    // 0x80023E14: sb          $a0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r4;
    // 0x80023E18: lbu         $a0, 0x3($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X3);
    // 0x80023E1C: sb          $a0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r4;
    // 0x80023E20: lbu         $a0, 0x4($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X4);
    // 0x80023E24: addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // 0x80023E28: sb          $a0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r4;
    // 0x80023E2C: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80023E30: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80023E34: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x80023E38: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x80023E3C: sb          $a0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r4;
    // 0x80023E40: lbu         $a0, 0x2($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X2);
    // 0x80023E44: sb          $a0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r4;
    // 0x80023E48: lbu         $a0, 0x3($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X3);
    // 0x80023E4C: sb          $a0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r4;
    // 0x80023E50: lbu         $a0, 0x4($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X4);
    // 0x80023E54: addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // 0x80023E58: sb          $a0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r4;
    // 0x80023E5C: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80023E60: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80023E64: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x80023E68: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x80023E6C: sb          $a0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r4;
    // 0x80023E70: lbu         $a0, 0x2($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X2);
    // 0x80023E74: sb          $a0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r4;
    // 0x80023E78: lbu         $a0, 0x3($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X3);
    // 0x80023E7C: sb          $a0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r4;
    // 0x80023E80: lbu         $v0, 0x4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4);
    // 0x80023E84: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80023E88: sb          $v0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r2;
    // 0x80023E8C: jr          $ra
    // 0x80023E90: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80023E90: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80023E94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023E94: slti        $v0, $a1, -0x6
    ctx->r2 = SIGNED(ctx->r5) < -0X6 ? 1 : 0;
    // 0x80023E98: beq         $v0, $zero, L_80023EA4
    if (ctx->r2 == 0) {
        // 0x80023E9C: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_80023EA4;
    }
    // 0x80023E9C: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x80023EA0: addiu       $a1, $zero, -0x6
    ctx->r5 = ADD32(0, -0X6);
L_80023EA4:
    // 0x80023EA4: slti        $v0, $a2, 0x12
    ctx->r2 = SIGNED(ctx->r6) < 0X12 ? 1 : 0;
    // 0x80023EA8: beql        $v0, $zero, L_80023EB0
    if (ctx->r2 == 0) {
        // 0x80023EAC: addiu       $a2, $zero, 0x11
        ctx->r6 = ADD32(0, 0X11);
            goto L_80023EB0;
    }
    goto skip_0;
    // 0x80023EAC: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    skip_0:
L_80023EB0:
    // 0x80023EB0: slt         $v0, $a2, $a1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80023EB4: bne         $v0, $zero, L_80023F48
    if (ctx->r2 != 0) {
        // 0x80023EB8: nop
    
            goto L_80023F48;
    }
    // 0x80023EB8: nop

    // 0x80023EBC: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80023EC0: addiu       $v1, $v1, 0x43A8
    ctx->r3 = ADD32(ctx->r3, 0X43A8);
    // 0x80023EC4: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80023EC8: addu        $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
    // 0x80023ECC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80023ED0: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80023ED4: addiu       $v1, $v1, 0x437C
    ctx->r3 = ADD32(ctx->r3, 0X437C);
    // 0x80023ED8: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x80023EDC: addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // 0x80023EE0: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x80023EE4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80023EE8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80023EEC: addiu       $t1, $v0, 0x70
    ctx->r9 = ADD32(ctx->r2, 0X70);
L_80023EF0:
    // 0x80023EF0: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80023EF4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80023EF8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80023EFC: addu        $v1, $v0, $t1
    ctx->r3 = ADD32(ctx->r2, ctx->r9);
L_80023F00:
    // 0x80023F00: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80023F04: beq         $v0, $zero, L_80023F2C
    if (ctx->r2 == 0) {
        // 0x80023F08: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80023F2C;
    }
    // 0x80023F08: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80023F0C: slti        $v0, $a0, 0xA
    ctx->r2 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x80023F10: bne         $v0, $zero, L_80023F00
    if (ctx->r2 != 0) {
        // 0x80023F14: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80023F00;
    }
    // 0x80023F14: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80023F18:
    // 0x80023F18: beql        $a3, $zero, L_80023F34
    if (ctx->r7 == 0) {
        // 0x80023F1C: sh          $zero, 0x0($t0)
        MEM_H(0X0, ctx->r8) = 0;
            goto L_80023F34;
    }
    goto skip_1;
    // 0x80023F1C: sh          $zero, 0x0($t0)
    MEM_H(0X0, ctx->r8) = 0;
    skip_1:
    // 0x80023F20: sh          $t4, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r12;
    // 0x80023F24: j           L_80023F34
    // 0x80023F28: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
        goto L_80023F34;
    // 0x80023F28: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_80023F2C:
    // 0x80023F2C: j           L_80023F18
    // 0x80023F30: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
        goto L_80023F18;
    // 0x80023F30: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_80023F34:
    // 0x80023F34: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x80023F38: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80023F3C: slt         $v0, $a2, $a1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80023F40: beq         $v0, $zero, L_80023EF0
    if (ctx->r2 == 0) {
        // 0x80023F44: addiu       $t1, $t1, 0x12
        ctx->r9 = ADD32(ctx->r9, 0X12);
            goto L_80023EF0;
    }
    // 0x80023F44: addiu       $t1, $t1, 0x12
    ctx->r9 = ADD32(ctx->r9, 0X12);
L_80023F48:
    // 0x80023F48: jr          $ra
    // 0x80023F4C: addu        $v0, $t2, $zero
    ctx->r2 = ADD32(ctx->r10, 0);
    return;
    // 0x80023F4C: addu        $v0, $t2, $zero
    ctx->r2 = ADD32(ctx->r10, 0);
;}
RECOMP_FUNC void func_80023F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023F50: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80023F54: addiu       $t0, $zero, 0x11
    ctx->r8 = ADD32(0, 0X11);
    // 0x80023F58: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80023F5C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80023F60: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80023F64: lw          $v1, 0x43A8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X43A8);
    // 0x80023F68: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80023F6C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80023F70: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80023F74: lw          $v0, 0x43A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43A8);
    // 0x80023F78: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80023F7C: addiu       $a3, $a3, 0x439E
    ctx->r7 = ADD32(ctx->r7, 0X439E);
    // 0x80023F80: addiu       $a2, $v1, 0x1A2
    ctx->r6 = ADD32(ctx->r3, 0X1A2);
    // 0x80023F84: addiu       $a1, $v0, 0x1A2
    ctx->r5 = ADD32(ctx->r2, 0X1A2);
    // 0x80023F88: addiu       $a0, $v0, 0x1AB
    ctx->r4 = ADD32(ctx->r2, 0X1AB);
    // 0x80023F8C: addiu       $v1, $v1, 0x1AB
    ctx->r3 = ADD32(ctx->r3, 0X1AB);
L_80023F90:
    // 0x80023F90: lh          $v0, 0x0($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X0);
    // 0x80023F94: bne         $v0, $zero, L_80023FF4
    if (ctx->r2 != 0) {
        // 0x80023F98: addiu       $a3, $a3, -0x2
        ctx->r7 = ADD32(ctx->r7, -0X2);
            goto L_80023FF4;
    }
    // 0x80023F98: addiu       $a3, $a3, -0x2
    ctx->r7 = ADD32(ctx->r7, -0X2);
    // 0x80023F9C: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80023FA0: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x80023FA4: lbu         $v0, -0x8($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X8);
    // 0x80023FA8: sb          $v0, -0x8($v1)
    MEM_B(-0X8, ctx->r3) = ctx->r2;
    // 0x80023FAC: lbu         $v0, -0x7($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X7);
    // 0x80023FB0: sb          $v0, -0x7($v1)
    MEM_B(-0X7, ctx->r3) = ctx->r2;
    // 0x80023FB4: lbu         $v0, -0x6($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X6);
    // 0x80023FB8: sb          $v0, -0x6($v1)
    MEM_B(-0X6, ctx->r3) = ctx->r2;
    // 0x80023FBC: lbu         $v0, -0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X5);
    // 0x80023FC0: sb          $v0, -0x5($v1)
    MEM_B(-0X5, ctx->r3) = ctx->r2;
    // 0x80023FC4: lbu         $v0, -0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X4);
    // 0x80023FC8: sb          $v0, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r2;
    // 0x80023FCC: lbu         $v0, -0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X3);
    // 0x80023FD0: sb          $v0, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r2;
    // 0x80023FD4: lbu         $v0, -0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X2);
    // 0x80023FD8: sb          $v0, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r2;
    // 0x80023FDC: lbu         $v0, -0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X1);
    // 0x80023FE0: sb          $v0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r2;
    // 0x80023FE4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80023FE8: addiu       $a2, $a2, -0x12
    ctx->r6 = ADD32(ctx->r6, -0X12);
    // 0x80023FEC: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80023FF0: addiu       $v1, $v1, -0x12
    ctx->r3 = ADD32(ctx->r3, -0X12);
L_80023FF4:
    // 0x80023FF4: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80023FF8: addiu       $a0, $a0, -0x12
    ctx->r4 = ADD32(ctx->r4, -0X12);
    // 0x80023FFC: slti        $v0, $t0, -0x6
    ctx->r2 = SIGNED(ctx->r8) < -0X6 ? 1 : 0;
    // 0x80024000: beq         $v0, $zero, L_80023F90
    if (ctx->r2 == 0) {
        // 0x80024004: addiu       $a1, $a1, -0x12
        ctx->r5 = ADD32(ctx->r5, -0X12);
            goto L_80023F90;
    }
    // 0x80024004: addiu       $a1, $a1, -0x12
    ctx->r5 = ADD32(ctx->r5, -0X12);
    // 0x80024008: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8002400C: jr          $ra
    // 0x80024010: nop

    return;
    // 0x80024010: nop

;}
RECOMP_FUNC void func_80024014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024014: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80024018: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8002401C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80024020: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80024024: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x80024028: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8002402C: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80024030: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80024034: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80024038: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8002403C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80024040: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80024044: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80024048: lb          $v0, 0x54($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X54);
    // 0x8002404C: lw          $v1, 0xDC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XDC);
    // 0x80024050: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x80024054: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80024058: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002405C: lw          $s3, 0x0($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X0);
    // 0x80024060: sll         $v0, $s4, 2
    ctx->r2 = S32(ctx->r20 << 2);
    // 0x80024064: lbu         $v1, 0x54($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X54);
    // 0x80024068: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002406C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80024070: lw          $v0, 0x43A8($at)
    ctx->r2 = MEM_W(ctx->r1, 0X43A8);
    // 0x80024074: andi        $v1, $v1, 0x7F
    ctx->r3 = ctx->r3 & 0X7F;
    // 0x80024078: sw          $v0, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r2;
    // 0x8002407C: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
    // 0x80024080: bne         $v1, $v0, L_800240C4
    if (ctx->r3 != ctx->r2) {
        // 0x80024084: addu        $s5, $zero, $zero
        ctx->r21 = ADD32(0, 0);
            goto L_800240C4;
    }
    // 0x80024084: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x80024088: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002408C: sb          $v0, 0x4($s6)
    MEM_B(0X4, ctx->r22) = ctx->r2;
    // 0x80024090: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80024094: sb          $v0, 0xC($s6)
    MEM_B(0XC, ctx->r22) = ctx->r2;
    // 0x80024098: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002409C: sh          $zero, 0x8($s6)
    MEM_H(0X8, ctx->r22) = 0;
    // 0x800240A0: sh          $zero, 0x0($s6)
    MEM_H(0X0, ctx->r22) = 0;
    // 0x800240A4: sb          $zero, 0xD($s6)
    MEM_B(0XD, ctx->r22) = 0;
    // 0x800240A8: sb          $zero, 0x5($s6)
    MEM_B(0X5, ctx->r22) = 0;
    // 0x800240AC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800240B0: j           L_800243E4
    // 0x800240B4: sw          $v0, 0x43A0($at)
    MEM_W(0X43A0, ctx->r1) = ctx->r2;
        goto L_800243E4;
    // 0x800240B4: sw          $v0, 0x43A0($at)
    MEM_W(0X43A0, ctx->r1) = ctx->r2;
L_800240B8:
    // 0x800240B8: addiu       $v0, $zero, -0x3E8
    ctx->r2 = ADD32(0, -0X3E8);
    // 0x800240BC: j           L_800243BC
    // 0x800240C0: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
        goto L_800243BC;
    // 0x800240C0: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_800240C4:
    // 0x800240C4: lw          $t0, 0x1C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1C);
    // 0x800240C8: lw          $fp, 0x18($s0)
    ctx->r30 = MEM_W(ctx->r16, 0X18);
    // 0x800240CC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800240D0: lb          $t0, 0x4C($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X4C);
    // 0x800240D4: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800240D8: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x800240DC: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800240E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800240E4:
    // 0x800240E4: bne         $s2, $v0, L_80024100
    if (ctx->r18 != ctx->r2) {
        // 0x800240E8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80024100;
    }
    // 0x800240E8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800240EC: lw          $v1, 0x4($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X4);
    // 0x800240F0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800240F4: beql        $v1, $v0, L_80024374
    if (ctx->r3 == ctx->r2) {
        // 0x800240F8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80024374;
    }
    goto skip_0;
    // 0x800240F8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x800240FC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80024100:
    // 0x80024100: bne         $s2, $v0, L_80024124
    if (ctx->r18 != ctx->r2) {
        // 0x80024104: nop
    
            goto L_80024124;
    }
    // 0x80024104: nop

    // 0x80024108: lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X8);
    // 0x8002410C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80024110: beql        $v1, $v0, L_80024374
    if (ctx->r3 == ctx->r2) {
        // 0x80024114: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80024374;
    }
    goto skip_1;
    // 0x80024114: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x80024118: lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4);
    // 0x8002411C: beql        $v1, $v0, L_80024374
    if (ctx->r3 == ctx->r2) {
        // 0x80024120: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80024374;
    }
    goto skip_2;
    // 0x80024120: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
L_80024124:
    // 0x80024124: bne         $s2, $s7, L_80024158
    if (ctx->r18 != ctx->r23) {
        // 0x80024128: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80024158;
    }
    // 0x80024128: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8002412C: lw          $v1, 0xC($s3)
    ctx->r3 = MEM_W(ctx->r19, 0XC);
    // 0x80024130: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80024134: beql        $v1, $v0, L_80024374
    if (ctx->r3 == ctx->r2) {
        // 0x80024138: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80024374;
    }
    goto skip_3;
    // 0x80024138: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_3:
    // 0x8002413C: lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4);
    // 0x80024140: beql        $v1, $v0, L_80024374
    if (ctx->r3 == ctx->r2) {
        // 0x80024144: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80024374;
    }
    goto skip_4;
    // 0x80024144: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_4:
    // 0x80024148: lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X8);
    // 0x8002414C: beql        $v1, $v0, L_80024374
    if (ctx->r3 == ctx->r2) {
        // 0x80024150: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80024374;
    }
    goto skip_5;
    // 0x80024150: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_5:
    // 0x80024154: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80024158:
    // 0x80024158: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8002415C: sw          $fp, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r30;
    // 0x80024160: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80024164: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    // 0x80024168: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // 0x8002416C: sb          $s2, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r18;
    // 0x80024170: sw          $t0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r8;
    // 0x80024174: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80024178: jal         0x80025410
    // 0x8002417C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80025410(rdram, ctx);
        goto after_0;
    // 0x8002417C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80024180: beq         $v0, $zero, L_800242BC
    if (ctx->r2 == 0) {
        // 0x80024184: addiu       $v0, $zero, -0x3
        ctx->r2 = ADD32(0, -0X3);
            goto L_800242BC;
    }
    // 0x80024184: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
    // 0x80024188: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x8002418C: bne         $v1, $v0, L_800241AC
    if (ctx->r3 != ctx->r2) {
        // 0x80024190: nop
    
            goto L_800241AC;
    }
    // 0x80024190: nop

    // 0x80024194: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x80024198: bne         $v0, $zero, L_800241AC
    if (ctx->r2 != 0) {
        // 0x8002419C: nop
    
            goto L_800241AC;
    }
    // 0x8002419C: nop

    // 0x800241A0: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x800241A4: j           L_800242A4
    // 0x800241A8: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
        goto L_800242A4;
    // 0x800241A8: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_800241AC:
    // 0x800241AC: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x800241B0: bne         $v0, $s7, L_800241D4
    if (ctx->r2 != ctx->r23) {
        // 0x800241B4: nop
    
            goto L_800241D4;
    }
    // 0x800241B4: nop

    // 0x800241B8: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x800241BC: bne         $v0, $zero, L_800241D0
    if (ctx->r2 != 0) {
        // 0x800241C0: nop
    
            goto L_800241D0;
    }
    // 0x800241C0: nop

    // 0x800241C4: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x800241C8: j           L_800242A4
    // 0x800241CC: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
        goto L_800242A4;
    // 0x800241CC: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
L_800241D0:
    // 0x800241D0: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
L_800241D4:
    // 0x800241D4: bne         $v0, $zero, L_800241F8
    if (ctx->r2 != 0) {
        // 0x800241D8: nop
    
            goto L_800241F8;
    }
    // 0x800241D8: nop

    // 0x800241DC: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x800241E0: bne         $v0, $s7, L_800241F8
    if (ctx->r2 != ctx->r23) {
        // 0x800241E4: nop
    
            goto L_800241F8;
    }
    // 0x800241E4: nop

    // 0x800241E8: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x800241EC: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x800241F0: j           L_800242A8
    // 0x800241F4: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
        goto L_800242A8;
    // 0x800241F4: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
L_800241F8:
    // 0x800241F8: lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10);
    // 0x800241FC: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x80024200: bgez        $a0, L_8002420C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80024204: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8002420C;
    }
    // 0x80024204: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80024208: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_8002420C:
    // 0x8002420C: bltzl       $v0, L_80024214
    if (SIGNED(ctx->r2) < 0) {
        // 0x80024210: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_80024214;
    }
    goto skip_6;
    // 0x80024210: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_6:
L_80024214:
    // 0x80024214: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80024218: beq         $v0, $zero, L_8002423C
    if (ctx->r2 == 0) {
        // 0x8002421C: nop
    
            goto L_8002423C;
    }
    // 0x8002421C: nop

    // 0x80024220: blez        $a0, L_80024234
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80024224: nop
    
            goto L_80024234;
    }
    // 0x80024224: nop

    // 0x80024228: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x8002422C: j           L_800242A4
    // 0x80024230: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_800242A4;
    // 0x80024230: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80024234:
    // 0x80024234: bltz        $a0, L_8002429C
    if (SIGNED(ctx->r4) < 0) {
        // 0x80024238: nop
    
            goto L_8002429C;
    }
    // 0x80024238: nop

L_8002423C:
    // 0x8002423C: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80024240: lw          $a0, 0x14($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X14);
    // 0x80024244: bltzl       $v1, L_8002424C
    if (SIGNED(ctx->r3) < 0) {
        // 0x80024248: negu        $v1, $v1
        ctx->r3 = SUB32(0, ctx->r3);
            goto L_8002424C;
    }
    goto skip_7;
    // 0x80024248: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    skip_7:
L_8002424C:
    // 0x8002424C: bgez        $a0, L_80024258
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80024250: addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
            goto L_80024258;
    }
    // 0x80024250: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x80024254: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_80024258:
    // 0x80024258: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002425C: beq         $v1, $zero, L_8002427C
    if (ctx->r3 == 0) {
        // 0x80024260: nop
    
            goto L_8002427C;
    }
    // 0x80024260: nop

    // 0x80024264: blez        $a0, L_8002427C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80024268: nop
    
            goto L_8002427C;
    }
    // 0x80024268: nop

    // 0x8002426C: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80024270: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80024274: j           L_800242A8
    // 0x80024278: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
        goto L_800242A8;
    // 0x80024278: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
L_8002427C:
    // 0x8002427C: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80024280: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x80024284: bltzl       $v1, L_8002428C
    if (SIGNED(ctx->r3) < 0) {
        // 0x80024288: negu        $v1, $v1
        ctx->r3 = SUB32(0, ctx->r3);
            goto L_8002428C;
    }
    goto skip_8;
    // 0x80024288: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    skip_8:
L_8002428C:
    // 0x8002428C: bltzl       $v0, L_80024294
    if (SIGNED(ctx->r2) < 0) {
        // 0x80024290: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_80024294;
    }
    goto skip_9;
    // 0x80024290: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_9:
L_80024294:
    // 0x80024294: bne         $v1, $v0, L_800242AC
    if (ctx->r3 != ctx->r2) {
        // 0x80024298: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800242AC;
    }
    // 0x80024298: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8002429C:
    // 0x8002429C: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x800242A0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800242A4:
    // 0x800242A4: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
L_800242A8:
    // 0x800242A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800242AC:
    // 0x800242AC: jal         0x80025364
    // 0x800242B0: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_80025364(rdram, ctx);
        goto after_1;
    // 0x800242B0: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_1:
    // 0x800242B4: bnel        $v0, $zero, L_80024374
    if (ctx->r2 != 0) {
        // 0x800242B8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80024374;
    }
    goto skip_10;
    // 0x800242B8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_10:
L_800242BC:
    // 0x800242BC: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x800242C0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_800242C4:
    // 0x800242C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800242C8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800242CC: jal         0x80024DCC
    // 0x800242D0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80024DCC(rdram, ctx);
        goto after_2;
    // 0x800242D0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_2:
    // 0x800242D4: bne         $v0, $zero, L_800242EC
    if (ctx->r2 != 0) {
        // 0x800242D8: nop
    
            goto L_800242EC;
    }
    // 0x800242D8: nop

    // 0x800242DC: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x800242E0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800242E4: j           L_800242C4
    // 0x800242E8: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
        goto L_800242C4;
    // 0x800242E8: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
L_800242EC:
    // 0x800242EC: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x800242F0: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x800242F4: addiu       $s1, $v0, 0x1
    ctx->r17 = ADD32(ctx->r2, 0X1);
    // 0x800242F8: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
L_800242FC:
    // 0x800242FC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80024300: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80024304: jal         0x80024DCC
    // 0x80024308: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80024DCC(rdram, ctx);
        goto after_3;
    // 0x80024308: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8002430C: bne         $v0, $zero, L_80024324
    if (ctx->r2 != 0) {
        // 0x80024310: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80024324;
    }
    // 0x80024310: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80024314: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80024318: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002431C: j           L_800242FC
    // 0x80024320: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
        goto L_800242FC;
    // 0x80024320: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
L_80024324:
    // 0x80024324: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x80024328: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002432C: beql        $v0, $zero, L_80024374
    if (ctx->r2 == 0) {
        // 0x80024330: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80024374;
    }
    goto skip_11;
    // 0x80024330: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_11:
    // 0x80024334: sll         $v0, $s5, 3
    ctx->r2 = S32(ctx->r21 << 3);
    // 0x80024338: addu        $v1, $v0, $s6
    ctx->r3 = ADD32(ctx->r2, ctx->r22);
L_8002433C:
    // 0x8002433C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80024340: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80024344: lbu         $v0, 0x2334($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2334);
    // 0x80024348: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8002434C: sb          $a0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r4;
    // 0x80024350: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80024354: sb          $s2, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r18;
    // 0x80024358: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8002435C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80024360: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80024364: slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80024368: bne         $v0, $zero, L_8002433C
    if (ctx->r2 != 0) {
        // 0x8002436C: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_8002433C;
    }
    // 0x8002436C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80024370: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80024374:
    // 0x80024374: slti        $v0, $s2, 0x4
    ctx->r2 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x80024378: bne         $v0, $zero, L_800240E4
    if (ctx->r2 != 0) {
        // 0x8002437C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800240E4;
    }
    // 0x8002437C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80024380: lbu         $v0, 0x54($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X54);
    // 0x80024384: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x80024388: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8002438C: bnel        $v0, $v1, L_800243C0
    if (ctx->r2 != ctx->r3) {
        // 0x80024390: sw          $fp, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r30;
            goto L_800243C0;
    }
    goto skip_12;
    // 0x80024390: sw          $fp, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r30;
    skip_12:
    // 0x80024394: blez        $s5, L_800243BC
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80024398: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800243BC;
    }
    // 0x80024398: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8002439C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800243A0: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
L_800243A4:
    // 0x800243A4: lb          $v0, 0x4($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X4);
    // 0x800243A8: beq         $v0, $v1, L_800240B8
    if (ctx->r2 == ctx->r3) {
        // 0x800243AC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800240B8;
    }
    // 0x800243AC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800243B0: slt         $v0, $a0, $s5
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x800243B4: bne         $v0, $zero, L_800243A4
    if (ctx->r2 != 0) {
        // 0x800243B8: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_800243A4;
    }
    // 0x800243B8: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
L_800243BC:
    // 0x800243BC: sw          $fp, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r30;
L_800243C0:
    // 0x800243C0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800243C4: sw          $t0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r8;
    // 0x800243C8: lbu         $t0, 0x27($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X27);
    // 0x800243CC: sb          $t0, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r8;
    // 0x800243D0: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800243D4: lw          $v0, 0x43A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43A8);
    // 0x800243D8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800243DC: sw          $s5, 0x43A0($at)
    MEM_W(0X43A0, ctx->r1) = ctx->r21;
    // 0x800243E0: sw          $v0, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r2;
L_800243E4:
    // 0x800243E4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800243E8: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x800243EC: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800243F0: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800243F4: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800243F8: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800243FC: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80024400: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80024404: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80024408: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8002440C: jr          $ra
    // 0x80024410: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80024410: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80024414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024414: lb          $v0, 0x11C($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X11C);
    // 0x80024418: bne         $v0, $zero, L_80024580
    if (ctx->r2 != 0) {
        // 0x8002441C: addiu       $sp, $sp, -0x10
        ctx->r29 = ADD32(ctx->r29, -0X10);
            goto L_80024580;
    }
    // 0x8002441C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80024420: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80024424: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80024428: addiu       $t1, $t1, 0x43A8
    ctx->r9 = ADD32(ctx->r9, 0X43A8);
    // 0x8002442C: addiu       $t0, $zero, 0x12
    ctx->r8 = ADD32(0, 0X12);
    // 0x80024430: addu        $a2, $sp, $zero
    ctx->r6 = ADD32(ctx->r29, 0);
L_80024434:
    // 0x80024434: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x80024438: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8002443C: addiu       $a1, $zero, -0x6
    ctx->r5 = ADD32(0, -0X6);
    // 0x80024440: addiu       $v0, $a3, 0x4
    ctx->r2 = ADD32(ctx->r7, 0X4);
    // 0x80024444: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_80024448:
    // 0x80024448: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8002444C: beql        $v0, $zero, L_80024460
    if (ctx->r2 == 0) {
        // 0x80024450: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80024460;
    }
    goto skip_0;
    // 0x80024450: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x80024454: subu        $v0, $t0, $a1
    ctx->r2 = SUB32(ctx->r8, ctx->r5);
    // 0x80024458: j           L_8002446C
    // 0x8002445C: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
        goto L_8002446C;
    // 0x8002445C: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
L_80024460:
    // 0x80024460: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x80024464: bne         $v0, $zero, L_80024448
    if (ctx->r2 != 0) {
        // 0x80024468: addiu       $v1, $v1, 0x12
        ctx->r3 = ADD32(ctx->r3, 0X12);
            goto L_80024448;
    }
    // 0x80024468: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
L_8002446C:
    // 0x8002446C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80024470: slti        $v0, $a3, 0xA
    ctx->r2 = SIGNED(ctx->r7) < 0XA ? 1 : 0;
    // 0x80024474: bne         $v0, $zero, L_80024434
    if (ctx->r2 != 0) {
        // 0x80024478: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80024434;
    }
    // 0x80024478: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8002447C: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x80024480: addiu       $a3, $sp, 0x2
    ctx->r7 = ADD32(ctx->r29, 0X2);
    // 0x80024484: addiu       $a2, $sp, 0x1
    ctx->r6 = ADD32(ctx->r29, 0X1);
    // 0x80024488: addu        $t0, $sp, $zero
    ctx->r8 = ADD32(ctx->r29, 0);
    // 0x8002448C: addiu       $t2, $sp, 0xA
    ctx->r10 = ADD32(ctx->r29, 0XA);
L_80024490:
    // 0x80024490: lb          $a1, 0x0($a2)
    ctx->r5 = MEM_B(ctx->r6, 0X0);
    // 0x80024494: lb          $v1, 0x0($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X0);
    // 0x80024498: subu        $v0, $a1, $v1
    ctx->r2 = SUB32(ctx->r5, ctx->r3);
    // 0x8002449C: bltz        $v0, L_800244B4
    if (SIGNED(ctx->r2) < 0) {
        // 0x800244A0: slti        $v0, $v0, 0x6
        ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
            goto L_800244B4;
    }
    // 0x800244A0: slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x800244A4: beq         $v0, $zero, L_800244C8
    if (ctx->r2 == 0) {
        // 0x800244A8: nop
    
            goto L_800244C8;
    }
    // 0x800244A8: nop

    // 0x800244AC: j           L_80024500
    // 0x800244B0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
        goto L_80024500;
    // 0x800244B0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_800244B4:
    // 0x800244B4: subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
    // 0x800244B8: slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x800244BC: bnel        $v0, $zero, L_80024500
    if (ctx->r2 != 0) {
        // 0x800244C0: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80024500;
    }
    goto skip_1;
    // 0x800244C0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_1:
    // 0x800244C4: lb          $a1, 0x0($a2)
    ctx->r5 = MEM_B(ctx->r6, 0X0);
L_800244C8:
    // 0x800244C8: lb          $v1, 0x0($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X0);
    // 0x800244CC: subu        $v0, $a1, $v1
    ctx->r2 = SUB32(ctx->r5, ctx->r3);
    // 0x800244D0: bltz        $v0, L_800244E8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800244D4: slti        $v0, $v0, 0x6
        ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
            goto L_800244E8;
    }
    // 0x800244D4: slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x800244D8: beql        $v0, $zero, L_800244FC
    if (ctx->r2 == 0) {
        // 0x800244DC: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_800244FC;
    }
    goto skip_2;
    // 0x800244DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    skip_2:
    // 0x800244E0: j           L_80024500
    // 0x800244E4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
        goto L_80024500;
    // 0x800244E4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_800244E8:
    // 0x800244E8: subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
    // 0x800244EC: slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x800244F0: bnel        $v0, $zero, L_80024500
    if (ctx->r2 != 0) {
        // 0x800244F4: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80024500;
    }
    goto skip_3;
    // 0x800244F4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_3:
    // 0x800244F8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800244FC:
    // 0x800244FC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_80024500:
    // 0x80024500: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80024504: slt         $v0, $a3, $t2
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80024508: bne         $v0, $zero, L_80024490
    if (ctx->r2 != 0) {
        // 0x8002450C: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80024490;
    }
    // 0x8002450C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80024510: lb          $a1, 0x0($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X0);
    // 0x80024514: lb          $v1, 0x1($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X1);
    // 0x80024518: subu        $v0, $a1, $v1
    ctx->r2 = SUB32(ctx->r5, ctx->r3);
    // 0x8002451C: bltzl       $v0, L_80024524
    if (SIGNED(ctx->r2) < 0) {
        // 0x80024520: subu        $v0, $v1, $a1
        ctx->r2 = SUB32(ctx->r3, ctx->r5);
            goto L_80024524;
    }
    goto skip_4;
    // 0x80024520: subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
    skip_4:
L_80024524:
    // 0x80024524: slti        $v0, $v0, 0x8
    ctx->r2 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80024528: beql        $v0, $zero, L_80024564
    if (ctx->r2 == 0) {
        // 0x8002452C: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80024564;
    }
    goto skip_5;
    // 0x8002452C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    skip_5:
    // 0x80024530: lb          $a1, 0x8($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X8);
    // 0x80024534: lb          $v1, 0x9($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X9);
    // 0x80024538: subu        $v0, $a1, $v1
    ctx->r2 = SUB32(ctx->r5, ctx->r3);
    // 0x8002453C: bltz        $v0, L_80024554
    if (SIGNED(ctx->r2) < 0) {
        // 0x80024540: slti        $v0, $v0, 0x8
        ctx->r2 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
            goto L_80024554;
    }
    // 0x80024540: slti        $v0, $v0, 0x8
    ctx->r2 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80024544: beql        $v0, $zero, L_80024564
    if (ctx->r2 == 0) {
        // 0x80024548: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80024564;
    }
    goto skip_6;
    // 0x80024548: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    skip_6:
    // 0x8002454C: j           L_80024564
    // 0x80024550: nop

        goto L_80024564;
    // 0x80024550: nop

L_80024554:
    // 0x80024554: subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
    // 0x80024558: slti        $v0, $v0, 0x8
    ctx->r2 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8002455C: beql        $v0, $zero, L_80024564
    if (ctx->r2 == 0) {
        // 0x80024560: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80024564;
    }
    goto skip_7;
    // 0x80024560: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    skip_7:
L_80024564:
    // 0x80024564: beq         $t1, $zero, L_80024580
    if (ctx->r9 == 0) {
        // 0x80024568: nop
    
            goto L_80024580;
    }
    // 0x80024568: nop

    // 0x8002456C: lb          $v1, 0xCC($a0)
    ctx->r3 = MEM_B(ctx->r4, 0XCC);
    // 0x80024570: lb          $v0, 0xCD($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XCD);
    // 0x80024574: bne         $v1, $v0, L_80024580
    if (ctx->r3 != ctx->r2) {
        // 0x80024578: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80024580;
    }
    // 0x80024578: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002457C: sb          $v0, 0x11C($a0)
    MEM_B(0X11C, ctx->r4) = ctx->r2;
L_80024580:
    // 0x80024580: jr          $ra
    // 0x80024584: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80024584: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80024588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024588: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002458C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80024590: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80024594: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80024598: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x8002459C: addiu       $t1, $zero, 0x11
    ctx->r9 = ADD32(0, 0X11);
    // 0x800245A0: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x800245A4: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800245A8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800245AC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800245B0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800245B4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800245B8: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800245BC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800245C0: lw          $v1, 0x43A8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X43A8);
    // 0x800245C4: sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7 << 2);
    // 0x800245C8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800245CC: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800245D0: lw          $v0, 0x43A8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43A8);
    // 0x800245D4: addiu       $t0, $zero, -0x6
    ctx->r8 = ADD32(0, -0X6);
    // 0x800245D8: addiu       $a3, $v1, 0x4
    ctx->r7 = ADD32(ctx->r3, 0X4);
    // 0x800245DC: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x800245E0: addiu       $a0, $v0, 0xD
    ctx->r4 = ADD32(ctx->r2, 0XD);
    // 0x800245E4: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
L_800245E8:
    // 0x800245E8: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x800245EC: sb          $v0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r2;
    // 0x800245F0: lbu         $v0, -0x8($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X8);
    // 0x800245F4: sb          $v0, -0x8($v1)
    MEM_B(-0X8, ctx->r3) = ctx->r2;
    // 0x800245F8: lbu         $v0, -0x7($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X7);
    // 0x800245FC: sb          $v0, -0x7($v1)
    MEM_B(-0X7, ctx->r3) = ctx->r2;
    // 0x80024600: lbu         $v0, -0x6($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X6);
    // 0x80024604: sb          $v0, -0x6($v1)
    MEM_B(-0X6, ctx->r3) = ctx->r2;
    // 0x80024608: lbu         $v0, -0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X5);
    // 0x8002460C: sb          $v0, -0x5($v1)
    MEM_B(-0X5, ctx->r3) = ctx->r2;
    // 0x80024610: lbu         $v0, -0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X4);
    // 0x80024614: sb          $v0, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r2;
    // 0x80024618: lbu         $v0, -0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X3);
    // 0x8002461C: sb          $v0, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r2;
    // 0x80024620: lbu         $v0, -0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X2);
    // 0x80024624: sb          $v0, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r2;
    // 0x80024628: lbu         $v0, -0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X1);
    // 0x8002462C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80024630: addiu       $a2, $a2, 0x12
    ctx->r6 = ADD32(ctx->r6, 0X12);
    // 0x80024634: sb          $v0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r2;
    // 0x80024638: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8002463C: addiu       $a3, $a3, 0x12
    ctx->r7 = ADD32(ctx->r7, 0X12);
    // 0x80024640: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    // 0x80024644: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80024648: slt         $v0, $t1, $t0
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002464C: beq         $v0, $zero, L_800245E8
    if (ctx->r2 == 0) {
        // 0x80024650: addiu       $v1, $v1, 0x12
        ctx->r3 = ADD32(ctx->r3, 0X12);
            goto L_800245E8;
    }
    // 0x80024650: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80024654: lb          $v0, 0x4($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X4);
    // 0x80024658: lw          $s5, 0x18($s0)
    ctx->r21 = MEM_W(ctx->r16, 0X18);
    // 0x8002465C: lb          $s4, 0x4C($s0)
    ctx->r20 = MEM_B(ctx->r16, 0X4C);
    // 0x80024660: lw          $s3, 0xB0($s0)
    ctx->r19 = MEM_W(ctx->r16, 0XB0);
    // 0x80024664: lw          $s2, 0x1C($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X1C);
    // 0x80024668: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x8002466C: lbu         $v0, 0x5($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X5);
    // 0x80024670: sb          $v0, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r2;
    // 0x80024674: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x80024678: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002467C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80024680: lw          $v0, 0x43A8($at)
    ctx->r2 = MEM_W(ctx->r1, 0X43A8);
    // 0x80024684: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80024688: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8002468C: jal         0x80024C30
    // 0x80024690: sw          $v0, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r2;
    func_80024C30(rdram, ctx);
        goto after_0;
    // 0x80024690: sw          $v0, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r2;
    after_0:
    // 0x80024694: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80024698: addiu       $v1, $v0, -0x2
    ctx->r3 = ADD32(ctx->r2, -0X2);
    // 0x8002469C: addiu       $t1, $v0, 0x2
    ctx->r9 = ADD32(ctx->r2, 0X2);
    // 0x800246A0: slti        $v0, $v1, -0x6
    ctx->r2 = SIGNED(ctx->r3) < -0X6 ? 1 : 0;
    // 0x800246A4: beq         $v0, $zero, L_800246B0
    if (ctx->r2 == 0) {
        // 0x800246A8: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_800246B0;
    }
    // 0x800246A8: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x800246AC: addiu       $v1, $zero, -0x6
    ctx->r3 = ADD32(0, -0X6);
L_800246B0:
    // 0x800246B0: slti        $v0, $t1, 0x12
    ctx->r2 = SIGNED(ctx->r9) < 0X12 ? 1 : 0;
    // 0x800246B4: beql        $v0, $zero, L_800246BC
    if (ctx->r2 == 0) {
        // 0x800246B8: addiu       $t1, $zero, 0x11
        ctx->r9 = ADD32(0, 0X11);
            goto L_800246BC;
    }
    goto skip_0;
    // 0x800246B8: addiu       $t1, $zero, 0x11
    ctx->r9 = ADD32(0, 0X11);
    skip_0:
L_800246BC:
    // 0x800246BC: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // 0x800246C0: slt         $v0, $t1, $a3
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800246C4: bne         $v0, $zero, L_80024754
    if (ctx->r2 != 0) {
        // 0x800246C8: sll         $v0, $s1, 2
        ctx->r2 = S32(ctx->r17 << 2);
            goto L_80024754;
    }
    // 0x800246C8: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x800246CC: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800246D0: addiu       $v1, $v1, 0x43A8
    ctx->r3 = ADD32(ctx->r3, 0X43A8);
    // 0x800246D4: addu        $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
    // 0x800246D8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800246DC: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800246E0: addiu       $v1, $v1, 0x437C
    ctx->r3 = ADD32(ctx->r3, 0X437C);
    // 0x800246E4: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x800246E8: addu        $a2, $v0, $v1
    ctx->r6 = ADD32(ctx->r2, ctx->r3);
    // 0x800246EC: sll         $v0, $a3, 3
    ctx->r2 = S32(ctx->r7 << 3);
    // 0x800246F0: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800246F4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800246F8: addiu       $t0, $v0, 0x70
    ctx->r8 = ADD32(ctx->r2, 0X70);
L_800246FC:
    // 0x800246FC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80024700: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80024704: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80024708: addu        $v1, $v0, $t0
    ctx->r3 = ADD32(ctx->r2, ctx->r8);
L_8002470C:
    // 0x8002470C: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80024710: beq         $v0, $zero, L_80024738
    if (ctx->r2 == 0) {
        // 0x80024714: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80024738;
    }
    // 0x80024714: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80024718: slti        $v0, $a0, 0xA
    ctx->r2 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x8002471C: bne         $v0, $zero, L_8002470C
    if (ctx->r2 != 0) {
        // 0x80024720: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8002470C;
    }
    // 0x80024720: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80024724:
    // 0x80024724: beql        $a1, $zero, L_80024740
    if (ctx->r5 == 0) {
        // 0x80024728: sh          $zero, 0x0($a2)
        MEM_H(0X0, ctx->r6) = 0;
            goto L_80024740;
    }
    goto skip_1;
    // 0x80024728: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    skip_1:
    // 0x8002472C: sh          $t4, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r12;
    // 0x80024730: j           L_80024740
    // 0x80024734: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
        goto L_80024740;
    // 0x80024734: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_80024738:
    // 0x80024738: j           L_80024724
    // 0x8002473C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
        goto L_80024724;
    // 0x8002473C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80024740:
    // 0x80024740: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80024744: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80024748: slt         $v0, $t1, $a3
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8002474C: beq         $v0, $zero, L_800246FC
    if (ctx->r2 == 0) {
        // 0x80024750: addiu       $t0, $t0, 0x12
        ctx->r8 = ADD32(ctx->r8, 0X12);
            goto L_800246FC;
    }
    // 0x80024750: addiu       $t0, $t0, 0x12
    ctx->r8 = ADD32(ctx->r8, 0X12);
L_80024754:
    // 0x80024754: beq         $t2, $zero, L_800248A8
    if (ctx->r10 == 0) {
        // 0x80024758: addiu       $t0, $zero, 0x11
        ctx->r8 = ADD32(0, 0X11);
            goto L_800248A8;
    }
    // 0x80024758: addiu       $t0, $zero, 0x11
    ctx->r8 = ADD32(0, 0X11);
    // 0x8002475C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80024760: lw          $v0, 0x43B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43B8);
    // 0x80024764: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
    // 0x80024768: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8002476C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80024770: lw          $v1, 0x43A8($at)
    ctx->r3 = MEM_W(ctx->r1, 0X43A8);
    // 0x80024774: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80024778: addiu       $a3, $a3, 0x439E
    ctx->r7 = ADD32(ctx->r7, 0X439E);
    // 0x8002477C: addiu       $a2, $v0, 0x1A2
    ctx->r6 = ADD32(ctx->r2, 0X1A2);
    // 0x80024780: addiu       $a1, $v1, 0x1A2
    ctx->r5 = ADD32(ctx->r3, 0X1A2);
    // 0x80024784: addiu       $v1, $v1, 0x1AB
    ctx->r3 = ADD32(ctx->r3, 0X1AB);
    // 0x80024788: addiu       $a0, $v0, 0x1AB
    ctx->r4 = ADD32(ctx->r2, 0X1AB);
L_8002478C:
    // 0x8002478C: lh          $v0, 0x0($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X0);
    // 0x80024790: bne         $v0, $zero, L_800247F0
    if (ctx->r2 != 0) {
        // 0x80024794: addiu       $a3, $a3, -0x2
        ctx->r7 = ADD32(ctx->r7, -0X2);
            goto L_800247F0;
    }
    // 0x80024794: addiu       $a3, $a3, -0x2
    ctx->r7 = ADD32(ctx->r7, -0X2);
    // 0x80024798: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8002479C: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x800247A0: lbu         $v0, -0x8($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X8);
    // 0x800247A4: sb          $v0, -0x8($a0)
    MEM_B(-0X8, ctx->r4) = ctx->r2;
    // 0x800247A8: lbu         $v0, -0x7($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X7);
    // 0x800247AC: sb          $v0, -0x7($a0)
    MEM_B(-0X7, ctx->r4) = ctx->r2;
    // 0x800247B0: lbu         $v0, -0x6($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X6);
    // 0x800247B4: sb          $v0, -0x6($a0)
    MEM_B(-0X6, ctx->r4) = ctx->r2;
    // 0x800247B8: lbu         $v0, -0x5($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X5);
    // 0x800247BC: sb          $v0, -0x5($a0)
    MEM_B(-0X5, ctx->r4) = ctx->r2;
    // 0x800247C0: lbu         $v0, -0x4($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X4);
    // 0x800247C4: sb          $v0, -0x4($a0)
    MEM_B(-0X4, ctx->r4) = ctx->r2;
    // 0x800247C8: lbu         $v0, -0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X3);
    // 0x800247CC: sb          $v0, -0x3($a0)
    MEM_B(-0X3, ctx->r4) = ctx->r2;
    // 0x800247D0: lbu         $v0, -0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X2);
    // 0x800247D4: sb          $v0, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r2;
    // 0x800247D8: lbu         $v0, -0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X1);
    // 0x800247DC: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
    // 0x800247E0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800247E4: addiu       $a2, $a2, -0x12
    ctx->r6 = ADD32(ctx->r6, -0X12);
    // 0x800247E8: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800247EC: addiu       $a0, $a0, -0x12
    ctx->r4 = ADD32(ctx->r4, -0X12);
L_800247F0:
    // 0x800247F0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800247F4: addiu       $v1, $v1, -0x12
    ctx->r3 = ADD32(ctx->r3, -0X12);
    // 0x800247F8: slti        $v0, $t0, -0x6
    ctx->r2 = SIGNED(ctx->r8) < -0X6 ? 1 : 0;
    // 0x800247FC: beq         $v0, $zero, L_8002478C
    if (ctx->r2 == 0) {
        // 0x80024800: addiu       $a1, $a1, -0x12
        ctx->r5 = ADD32(ctx->r5, -0X12);
            goto L_8002478C;
    }
    // 0x80024800: addiu       $a1, $a1, -0x12
    ctx->r5 = ADD32(ctx->r5, -0X12);
    // 0x80024804: addiu       $t0, $zero, 0x11
    ctx->r8 = ADD32(0, 0X11);
    // 0x80024808: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x8002480C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80024810: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80024814: lw          $v1, 0x43A8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X43A8);
    // 0x80024818: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8002481C: lw          $v0, 0x43B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43B8);
    // 0x80024820: addiu       $a3, $zero, -0x6
    ctx->r7 = ADD32(0, -0X6);
    // 0x80024824: addiu       $a2, $v1, 0x4
    ctx->r6 = ADD32(ctx->r3, 0X4);
    // 0x80024828: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x8002482C: addiu       $a0, $v0, 0xD
    ctx->r4 = ADD32(ctx->r2, 0XD);
    // 0x80024830: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
L_80024834:
    // 0x80024834: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80024838: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x8002483C: lbu         $v0, -0x8($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X8);
    // 0x80024840: sb          $v0, -0x8($v1)
    MEM_B(-0X8, ctx->r3) = ctx->r2;
    // 0x80024844: lbu         $v0, -0x7($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X7);
    // 0x80024848: sb          $v0, -0x7($v1)
    MEM_B(-0X7, ctx->r3) = ctx->r2;
    // 0x8002484C: lbu         $v0, -0x6($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X6);
    // 0x80024850: sb          $v0, -0x6($v1)
    MEM_B(-0X6, ctx->r3) = ctx->r2;
    // 0x80024854: lbu         $v0, -0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X5);
    // 0x80024858: sb          $v0, -0x5($v1)
    MEM_B(-0X5, ctx->r3) = ctx->r2;
    // 0x8002485C: lbu         $v0, -0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X4);
    // 0x80024860: sb          $v0, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r2;
    // 0x80024864: lbu         $v0, -0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X3);
    // 0x80024868: sb          $v0, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r2;
    // 0x8002486C: lbu         $v0, -0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X2);
    // 0x80024870: sb          $v0, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r2;
    // 0x80024874: lbu         $v0, -0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X1);
    // 0x80024878: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8002487C: addiu       $a1, $a1, 0x12
    ctx->r5 = ADD32(ctx->r5, 0X12);
    // 0x80024880: sb          $v0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r2;
    // 0x80024884: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80024888: addiu       $a2, $a2, 0x12
    ctx->r6 = ADD32(ctx->r6, 0X12);
    // 0x8002488C: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    // 0x80024890: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80024894: slt         $v0, $t0, $a3
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80024898: beq         $v0, $zero, L_80024834
    if (ctx->r2 == 0) {
        // 0x8002489C: addiu       $v1, $v1, 0x12
        ctx->r3 = ADD32(ctx->r3, 0X12);
            goto L_80024834;
    }
    // 0x8002489C: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x800248A0: j           L_80024944
    // 0x800248A4: sw          $s5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r21;
        goto L_80024944;
    // 0x800248A4: sw          $s5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r21;
L_800248A8:
    // 0x800248A8: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x800248AC: lw          $v0, 0x43B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X43B8);
    // 0x800248B0: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
    // 0x800248B4: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800248B8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800248BC: lw          $v1, 0x43A8($at)
    ctx->r3 = MEM_W(ctx->r1, 0X43A8);
    // 0x800248C0: addiu       $a3, $zero, -0x6
    ctx->r7 = ADD32(0, -0X6);
    // 0x800248C4: addiu       $a2, $v0, 0x4
    ctx->r6 = ADD32(ctx->r2, 0X4);
    // 0x800248C8: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    // 0x800248CC: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x800248D0: addiu       $a0, $v0, 0xD
    ctx->r4 = ADD32(ctx->r2, 0XD);
L_800248D4:
    // 0x800248D4: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800248D8: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // 0x800248DC: lbu         $v0, -0x8($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X8);
    // 0x800248E0: sb          $v0, -0x8($a0)
    MEM_B(-0X8, ctx->r4) = ctx->r2;
    // 0x800248E4: lbu         $v0, -0x7($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X7);
    // 0x800248E8: sb          $v0, -0x7($a0)
    MEM_B(-0X7, ctx->r4) = ctx->r2;
    // 0x800248EC: lbu         $v0, -0x6($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X6);
    // 0x800248F0: sb          $v0, -0x6($a0)
    MEM_B(-0X6, ctx->r4) = ctx->r2;
    // 0x800248F4: lbu         $v0, -0x5($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X5);
    // 0x800248F8: sb          $v0, -0x5($a0)
    MEM_B(-0X5, ctx->r4) = ctx->r2;
    // 0x800248FC: lbu         $v0, -0x4($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X4);
    // 0x80024900: sb          $v0, -0x4($a0)
    MEM_B(-0X4, ctx->r4) = ctx->r2;
    // 0x80024904: lbu         $v0, -0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X3);
    // 0x80024908: sb          $v0, -0x3($a0)
    MEM_B(-0X3, ctx->r4) = ctx->r2;
    // 0x8002490C: lbu         $v0, -0x2($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X2);
    // 0x80024910: sb          $v0, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r2;
    // 0x80024914: lbu         $v0, -0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X1);
    // 0x80024918: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8002491C: addiu       $a1, $a1, 0x12
    ctx->r5 = ADD32(ctx->r5, 0X12);
    // 0x80024920: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
    // 0x80024924: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80024928: addiu       $a2, $a2, 0x12
    ctx->r6 = ADD32(ctx->r6, 0X12);
    // 0x8002492C: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80024930: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x80024934: slt         $v0, $t0, $a3
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80024938: beq         $v0, $zero, L_800248D4
    if (ctx->r2 == 0) {
        // 0x8002493C: addiu       $a0, $a0, 0x12
        ctx->r4 = ADD32(ctx->r4, 0X12);
            goto L_800248D4;
    }
    // 0x8002493C: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    // 0x80024940: sw          $s5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r21;
L_80024944:
    // 0x80024944: sw          $s2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r18;
    // 0x80024948: sb          $s4, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r20;
    // 0x8002494C: sw          $s3, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r19;
    // 0x80024950: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80024954: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80024958: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002495C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80024960: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80024964: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80024968: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002496C: jr          $ra
    // 0x80024970: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80024970: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80024974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024974: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80024978: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002497C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80024980: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80024984: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x80024988: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8002498C: addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // 0x80024990: beq         $a2, $zero, L_80024AEC
    if (ctx->r6 == 0) {
        // 0x80024994: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80024AEC;
    }
    // 0x80024994: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80024998: lbu         $v0, 0x54($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X54);
    // 0x8002499C: andi        $v1, $v0, 0x7F
    ctx->r3 = ctx->r2 & 0X7F;
    // 0x800249A0: addiu       $v0, $v1, -0x1F
    ctx->r2 = ADD32(ctx->r3, -0X1F);
    // 0x800249A4: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800249A8: bne         $v0, $zero, L_800249CC
    if (ctx->r2 != 0) {
        // 0x800249AC: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_800249CC;
    }
    // 0x800249AC: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x800249B0: xori        $v1, $v0, 0x21
    ctx->r3 = ctx->r2 ^ 0X21;
    // 0x800249B4: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800249B8: xori        $v0, $v0, 0x1E
    ctx->r2 = ctx->r2 ^ 0X1E;
    // 0x800249BC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800249C0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800249C4: beq         $v1, $zero, L_80024A28
    if (ctx->r3 == 0) {
        // 0x800249C8: nop
    
            goto L_80024A28;
    }
    // 0x800249C8: nop

L_800249CC:
    // 0x800249CC: lbu         $v0, 0x55($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X55);
    // 0x800249D0: andi        $v1, $v0, 0x7F
    ctx->r3 = ctx->r2 & 0X7F;
    // 0x800249D4: addiu       $v0, $v1, -0x1F
    ctx->r2 = ADD32(ctx->r3, -0X1F);
    // 0x800249D8: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800249DC: bne         $v0, $zero, L_80024A00
    if (ctx->r2 != 0) {
        // 0x800249E0: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80024A00;
    }
    // 0x800249E0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x800249E4: xori        $v1, $v0, 0x21
    ctx->r3 = ctx->r2 ^ 0X21;
    // 0x800249E8: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800249EC: xori        $v0, $v0, 0x1E
    ctx->r2 = ctx->r2 ^ 0X1E;
    // 0x800249F0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800249F4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800249F8: beq         $v1, $zero, L_80024A28
    if (ctx->r3 == 0) {
        // 0x800249FC: nop
    
            goto L_80024A28;
    }
    // 0x800249FC: nop

L_80024A00:
    // 0x80024A00: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x80024A04: lb          $v1, 0x6($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X6);
    // 0x80024A08: addiu       $a0, $a0, 0xBB8
    ctx->r4 = ADD32(ctx->r4, 0XBB8);
    // 0x80024A0C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80024A10: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80024A14: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80024A18: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80024A1C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80024A20: j           L_80024B78
    // 0x80024A24: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
        goto L_80024B78;
    // 0x80024A24: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
L_80024A28:
    // 0x80024A28: lb          $v0, 0x125($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X125);
    // 0x80024A2C: slti        $v0, $v0, 0xB
    ctx->r2 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80024A30: bne         $v0, $zero, L_80024AA0
    if (ctx->r2 != 0) {
        // 0x80024A34: nop
    
            goto L_80024AA0;
    }
    // 0x80024A34: nop

    // 0x80024A38: lbu         $v0, 0x54($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X54);
    // 0x80024A3C: andi        $v1, $v0, 0x7F
    ctx->r3 = ctx->r2 & 0X7F;
    // 0x80024A40: addiu       $v0, $v1, -0x1F
    ctx->r2 = ADD32(ctx->r3, -0X1F);
    // 0x80024A44: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80024A48: bne         $v0, $zero, L_80024A6C
    if (ctx->r2 != 0) {
        // 0x80024A4C: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80024A6C;
    }
    // 0x80024A4C: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80024A50: xori        $v1, $v0, 0x21
    ctx->r3 = ctx->r2 ^ 0X21;
    // 0x80024A54: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80024A58: xori        $v0, $v0, 0x1E
    ctx->r2 = ctx->r2 ^ 0X1E;
    // 0x80024A5C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80024A60: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80024A64: beq         $v1, $zero, L_80024AA0
    if (ctx->r3 == 0) {
        // 0x80024A68: nop
    
            goto L_80024AA0;
    }
    // 0x80024A68: nop

L_80024A6C:
    // 0x80024A6C: lbu         $v0, 0x55($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X55);
    // 0x80024A70: andi        $v1, $v0, 0x7F
    ctx->r3 = ctx->r2 & 0X7F;
    // 0x80024A74: addiu       $v0, $v1, -0x1F
    ctx->r2 = ADD32(ctx->r3, -0X1F);
    // 0x80024A78: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80024A7C: bne         $v0, $zero, L_80024AB0
    if (ctx->r2 != 0) {
        // 0x80024A80: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80024AB0;
    }
    // 0x80024A80: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80024A84: xori        $v1, $v0, 0x21
    ctx->r3 = ctx->r2 ^ 0X21;
    // 0x80024A88: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80024A8C: xori        $v0, $v0, 0x1E
    ctx->r2 = ctx->r2 ^ 0X1E;
    // 0x80024A90: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80024A94: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80024A98: bne         $v1, $zero, L_80024AB0
    if (ctx->r3 != 0) {
        // 0x80024A9C: nop
    
            goto L_80024AB0;
    }
    // 0x80024A9C: nop

L_80024AA0:
    // 0x80024AA0: lb          $v0, 0x125($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X125);
    // 0x80024AA4: slti        $v0, $v0, 0x12
    ctx->r2 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x80024AA8: bne         $v0, $zero, L_80024B7C
    if (ctx->r2 != 0) {
        // 0x80024AAC: nop
    
            goto L_80024B7C;
    }
    // 0x80024AAC: nop

L_80024AB0:
    // 0x80024AB0: lb          $v0, 0x6($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X6);
    // 0x80024AB4: lb          $a0, 0x125($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X125);
    // 0x80024AB8: sll         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2 << 5);
    // 0x80024ABC: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80024AC0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80024AC4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80024AC8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80024ACC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80024AD0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80024AD4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80024AD8: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x80024ADC: addiu       $v0, $v0, -0xBB8
    ctx->r2 = ADD32(ctx->r2, -0XBB8);
    // 0x80024AE0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80024AE4: j           L_80024B78
    // 0x80024AE8: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
        goto L_80024B78;
    // 0x80024AE8: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_80024AEC:
    // 0x80024AEC: lbu         $v0, 0x54($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X54);
    // 0x80024AF0: andi        $v1, $v0, 0x7F
    ctx->r3 = ctx->r2 & 0X7F;
    // 0x80024AF4: addiu       $v0, $v1, -0x1F
    ctx->r2 = ADD32(ctx->r3, -0X1F);
    // 0x80024AF8: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80024AFC: bne         $v0, $zero, L_80024B20
    if (ctx->r2 != 0) {
        // 0x80024B00: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80024B20;
    }
    // 0x80024B00: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80024B04: xori        $v1, $v0, 0x21
    ctx->r3 = ctx->r2 ^ 0X21;
    // 0x80024B08: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80024B0C: xori        $v0, $v0, 0x1E
    ctx->r2 = ctx->r2 ^ 0X1E;
    // 0x80024B10: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80024B14: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80024B18: beq         $v1, $zero, L_80024B7C
    if (ctx->r3 == 0) {
        // 0x80024B1C: nop
    
            goto L_80024B7C;
    }
    // 0x80024B1C: nop

L_80024B20:
    // 0x80024B20: lbu         $v0, 0x55($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X55);
    // 0x80024B24: andi        $v1, $v0, 0x7F
    ctx->r3 = ctx->r2 & 0X7F;
    // 0x80024B28: addiu       $v0, $v1, -0x1F
    ctx->r2 = ADD32(ctx->r3, -0X1F);
    // 0x80024B2C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80024B30: bne         $v0, $zero, L_80024B54
    if (ctx->r2 != 0) {
        // 0x80024B34: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80024B54;
    }
    // 0x80024B34: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80024B38: xori        $v1, $v0, 0x21
    ctx->r3 = ctx->r2 ^ 0X21;
    // 0x80024B3C: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80024B40: xori        $v0, $v0, 0x1E
    ctx->r2 = ctx->r2 ^ 0X1E;
    // 0x80024B44: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80024B48: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80024B4C: beq         $v1, $zero, L_80024B7C
    if (ctx->r3 == 0) {
        // 0x80024B50: nop
    
            goto L_80024B7C;
    }
    // 0x80024B50: nop

L_80024B54:
    // 0x80024B54: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x80024B58: lb          $v1, 0x125($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X125);
    // 0x80024B5C: addiu       $a0, $a0, -0x3E8
    ctx->r4 = ADD32(ctx->r4, -0X3E8);
    // 0x80024B60: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80024B64: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80024B68: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80024B6C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80024B70: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80024B74: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
L_80024B78:
    // 0x80024B78: sh          $a0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r4;
L_80024B7C:
    // 0x80024B7C: lb          $v0, 0x126($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X126);
    // 0x80024B80: bne         $v0, $zero, L_80024C18
    if (ctx->r2 != 0) {
        // 0x80024B84: nop
    
            goto L_80024C18;
    }
    // 0x80024B84: nop

    // 0x80024B88: lbu         $v0, 0x54($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X54);
    // 0x80024B8C: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80024B90: slti        $v0, $v0, 0x1F
    ctx->r2 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x80024B94: beq         $v0, $zero, L_80024C18
    if (ctx->r2 == 0) {
        // 0x80024B98: nop
    
            goto L_80024C18;
    }
    // 0x80024B98: nop

    // 0x80024B9C: lbu         $v0, 0x55($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X55);
    // 0x80024BA0: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80024BA4: slti        $v0, $v0, 0x1F
    ctx->r2 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x80024BA8: beq         $v0, $zero, L_80024C18
    if (ctx->r2 == 0) {
        // 0x80024BAC: nop
    
            goto L_80024C18;
    }
    // 0x80024BAC: nop

    // 0x80024BB0: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x80024BB4: slti        $v0, $v0, 0x7
    ctx->r2 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80024BB8: beq         $v0, $zero, L_80024BD0
    if (ctx->r2 == 0) {
        // 0x80024BBC: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80024BD0;
    }
    // 0x80024BBC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80024BC0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80024BC4: lbu         $v1, 0x7B9A($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B9A);
    // 0x80024BC8: beq         $v1, $v0, L_80024BE4
    if (ctx->r3 == ctx->r2) {
        // 0x80024BCC: nop
    
            goto L_80024BE4;
    }
    // 0x80024BCC: nop

L_80024BD0:
    // 0x80024BD0: jal         0x8002564C
    // 0x80024BD4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8002564C(rdram, ctx);
        goto after_0;
    // 0x80024BD4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80024BD8: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80024BDC: beq         $v0, $zero, L_80024C18
    if (ctx->r2 == 0) {
        // 0x80024BE0: nop
    
            goto L_80024C18;
    }
    // 0x80024BE0: nop

L_80024BE4:
    // 0x80024BE4: lb          $v0, 0x6($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X6);
    // 0x80024BE8: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80024BEC: beq         $v0, $zero, L_80024C18
    if (ctx->r2 == 0) {
        // 0x80024BF0: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80024C18;
    }
    // 0x80024BF0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80024BF4: jal         0x800255E0
    // 0x80024BF8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_800255E0(rdram, ctx);
        goto after_1;
    // 0x80024BF8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_1:
    // 0x80024BFC: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80024C00: beq         $v0, $zero, L_80024C18
    if (ctx->r2 == 0) {
        // 0x80024C04: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80024C18;
    }
    // 0x80024C04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80024C08: sb          $v0, 0x127($s0)
    MEM_B(0X127, ctx->r16) = ctx->r2;
    // 0x80024C0C: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x80024C10: addiu       $v0, $v0, -0x2710
    ctx->r2 = ADD32(ctx->r2, -0X2710);
    // 0x80024C14: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
L_80024C18:
    // 0x80024C18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80024C1C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80024C20: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80024C24: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80024C28: jr          $ra
    // 0x80024C2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80024C2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80024C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024C30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80024C34: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x80024C38: addu        $t6, $a1, $zero
    ctx->r14 = ADD32(ctx->r5, 0);
    // 0x80024C3C: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x80024C40: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80024C44: lb          $v1, 0x54($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X54);
    // 0x80024C48: lw          $v0, 0xDC($t0)
    ctx->r2 = MEM_W(ctx->r8, 0XDC);
    // 0x80024C4C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80024C50: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80024C54: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80024C58: lb          $v0, 0x4C($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X4C);
    // 0x80024C5C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80024C60: addu        $a0, $sp, $zero
    ctx->r4 = ADD32(ctx->r29, 0);
    // 0x80024C64: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80024C68: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80024C6C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
L_80024C70:
    // 0x80024C70: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80024C74: addiu       $v1, $t1, 0x14
    ctx->r3 = ADD32(ctx->r9, 0X14);
L_80024C78:
    // 0x80024C78: addu        $v0, $v1, $a3
    ctx->r2 = ADD32(ctx->r3, ctx->r7);
    // 0x80024C7C: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x80024C80: bne         $v0, $zero, L_80024C94
    if (ctx->r2 != 0) {
        // 0x80024C84: nop
    
            goto L_80024C94;
    }
    // 0x80024C84: nop

    // 0x80024C88: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80024C8C: bgez        $a2, L_80024C78
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80024C90: addiu       $v1, $v1, -0x5
        ctx->r3 = ADD32(ctx->r3, -0X5);
            goto L_80024C78;
    }
    // 0x80024C90: addiu       $v1, $v1, -0x5
    ctx->r3 = ADD32(ctx->r3, -0X5);
L_80024C94:
    // 0x80024C94: bltz        $a2, L_80024CB0
    if (SIGNED(ctx->r6) < 0) {
        // 0x80024C98: sll         $v0, $a2, 3
        ctx->r2 = S32(ctx->r6 << 3);
            goto L_80024CB0;
    }
    // 0x80024C98: sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6 << 3);
    // 0x80024C9C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80024CA0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80024CA4: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80024CA8: j           L_80024CB4
    // 0x80024CAC: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
        goto L_80024CB4;
    // 0x80024CAC: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
L_80024CB0:
    // 0x80024CB0: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
L_80024CB4:
    // 0x80024CB4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80024CB8: slti        $v0, $a3, 0x5
    ctx->r2 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
    // 0x80024CBC: bne         $v0, $zero, L_80024C70
    if (ctx->r2 != 0) {
        // 0x80024CC0: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_80024C70;
    }
    // 0x80024CC0: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80024CC4: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80024CC8: addiu       $v0, $v0, 0x43A8
    ctx->r2 = ADD32(ctx->r2, 0X43A8);
    // 0x80024CCC: sll         $v1, $t6, 2
    ctx->r3 = S32(ctx->r14 << 2);
    // 0x80024CD0: lw          $a0, 0x18($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X18);
    // 0x80024CD4: addu        $t5, $v1, $v0
    ctx->r13 = ADD32(ctx->r3, ctx->r2);
    // 0x80024CD8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80024CDC: addiu       $t4, $a0, 0x2
    ctx->r12 = ADD32(ctx->r4, 0X2);
    // 0x80024CE0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_80024CE4:
    // 0x80024CE4: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    // 0x80024CE8: lw          $a0, 0x1C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X1C);
    // 0x80024CEC: addu        $a2, $sp, $zero
    ctx->r6 = ADD32(ctx->r29, 0);
    // 0x80024CF0: addu        $a1, $a1, $t4
    ctx->r5 = ADD32(ctx->r5, ctx->r12);
    // 0x80024CF4: addiu       $v1, $a0, 0x4
    ctx->r3 = ADD32(ctx->r4, 0X4);
    // 0x80024CF8: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80024CFC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80024D00: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80024D04: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80024D08: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80024D0C: sw          $a0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r4;
L_80024D10:
    // 0x80024D10: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x80024D14: beql        $v0, $t3, L_80024D34
    if (ctx->r2 == ctx->r11) {
        // 0x80024D18: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80024D34;
    }
    goto skip_0;
    // 0x80024D18: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_0:
    // 0x80024D1C: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80024D20: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x80024D24: beql        $v0, $zero, L_80024D34
    if (ctx->r2 == 0) {
        // 0x80024D28: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80024D34;
    }
    goto skip_1;
    // 0x80024D28: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_1:
    // 0x80024D2C: j           L_80024D40
    // 0x80024D30: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80024D40;
    // 0x80024D30: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80024D34:
    // 0x80024D34: slti        $v0, $a3, 0x5
    ctx->r2 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
    // 0x80024D38: bne         $v0, $zero, L_80024D10
    if (ctx->r2 != 0) {
        // 0x80024D3C: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_80024D10;
    }
    // 0x80024D3C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_80024D40:
    // 0x80024D40: beq         $t2, $zero, L_80024CE4
    if (ctx->r10 == 0) {
        // 0x80024D44: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_80024CE4;
    }
    // 0x80024D44: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80024D48: lw          $v1, 0x1C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X1C);
    // 0x80024D4C: sll         $a0, $t6, 2
    ctx->r4 = S32(ctx->r14 << 2);
    // 0x80024D50: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80024D54: addiu       $v0, $v1, -0x2
    ctx->r2 = ADD32(ctx->r3, -0X2);
    // 0x80024D58: sw          $v0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r2;
    // 0x80024D5C: lw          $v0, 0x18($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X18);
    // 0x80024D60: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80024D64: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80024D68: lw          $a0, 0x43A8($at)
    ctx->r4 = MEM_W(ctx->r1, 0X43A8);
    // 0x80024D6C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80024D70: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80024D74: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80024D78: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80024D7C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80024D80: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80024D84: addu        $a1, $a0, $v0
    ctx->r5 = ADD32(ctx->r4, ctx->r2);
L_80024D88:
    // 0x80024D88: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_80024D8C:
    // 0x80024D8C: lb          $v0, 0x0($t1)
    ctx->r2 = MEM_B(ctx->r9, 0X0);
    // 0x80024D90: beq         $v0, $zero, L_80024D9C
    if (ctx->r2 == 0) {
        // 0x80024D94: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80024D9C;
    }
    // 0x80024D94: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80024D98: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
L_80024D9C:
    // 0x80024D9C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80024DA0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80024DA4: slti        $v0, $a3, 0x5
    ctx->r2 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
    // 0x80024DA8: bne         $v0, $zero, L_80024D8C
    if (ctx->r2 != 0) {
        // 0x80024DAC: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_80024D8C;
    }
    // 0x80024DAC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80024DB0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80024DB4: slti        $v0, $a2, 0x5
    ctx->r2 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
    // 0x80024DB8: bne         $v0, $zero, L_80024D88
    if (ctx->r2 != 0) {
        // 0x80024DBC: addiu       $a1, $a1, 0xD
        ctx->r5 = ADD32(ctx->r5, 0XD);
            goto L_80024D88;
    }
    // 0x80024DBC: addiu       $a1, $a1, 0xD
    ctx->r5 = ADD32(ctx->r5, 0XD);
    // 0x80024DC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80024DC4: jr          $ra
    // 0x80024DC8: nop

    return;
    // 0x80024DC8: nop

;}
RECOMP_FUNC void func_80024DCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024DCC: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80024DD0: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80024DD4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80024DD8: addu        $a3, $a3, $a1
    ctx->r7 = ADD32(ctx->r7, ctx->r5);
    // 0x80024DDC: lw          $a3, 0x43A8($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X43A8);
    // 0x80024DE0: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x80024DE4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80024DE8: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x80024DEC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80024DF0: sll         $a1, $v1, 3
    ctx->r5 = S32(ctx->r3 << 3);
    // 0x80024DF4: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x80024DF8: lb          $v1, 0x54($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X54);
    // 0x80024DFC: lw          $v0, 0xDC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XDC);
    // 0x80024E00: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x80024E04: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80024E08: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80024E0C: lb          $v0, 0x4C($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X4C);
    // 0x80024E10: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80024E14: addu        $a3, $a3, $a1
    ctx->r7 = ADD32(ctx->r7, ctx->r5);
    // 0x80024E18: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80024E1C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80024E20: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80024E24: bne         $a2, $zero, L_800250B4
    if (ctx->r6 != 0) {
        // 0x80024E28: addiu       $v1, $a3, 0x1
        ctx->r3 = ADD32(ctx->r7, 0X1);
            goto L_800250B4;
    }
    // 0x80024E28: addiu       $v1, $a3, 0x1
    ctx->r3 = ADD32(ctx->r7, 0X1);
    // 0x80024E2C: lb          $v0, 0x27($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X27);
    // 0x80024E30: addiu       $v1, $a3, 0x3
    ctx->r3 = ADD32(ctx->r7, 0X3);
    // 0x80024E34: beq         $v0, $zero, L_80024E48
    if (ctx->r2 == 0) {
        // 0x80024E38: addiu       $a0, $a1, 0x3
        ctx->r4 = ADD32(ctx->r5, 0X3);
            goto L_80024E48;
    }
    // 0x80024E38: addiu       $a0, $a1, 0x3
    ctx->r4 = ADD32(ctx->r5, 0X3);
    // 0x80024E3C: lb          $v0, 0xD($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XD);
    // 0x80024E40: bnel        $v0, $zero, L_80024EAC
    if (ctx->r2 != 0) {
        // 0x80024E44: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80024EAC;
    }
    goto skip_0;
    // 0x80024E44: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_0:
L_80024E48:
    // 0x80024E48: lb          $v0, 0x12($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X12);
    // 0x80024E4C: beq         $v0, $zero, L_80024E60
    if (ctx->r2 == 0) {
        // 0x80024E50: nop
    
            goto L_80024E60;
    }
    // 0x80024E50: nop

    // 0x80024E54: lb          $v0, 0x5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5);
    // 0x80024E58: bnel        $v0, $zero, L_80024EAC
    if (ctx->r2 != 0) {
        // 0x80024E5C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80024EAC;
    }
    goto skip_1;
    // 0x80024E5C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_1:
L_80024E60:
    // 0x80024E60: lb          $v0, 0x36($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X36);
    // 0x80024E64: beq         $v0, $zero, L_80024E78
    if (ctx->r2 == 0) {
        // 0x80024E68: nop
    
            goto L_80024E78;
    }
    // 0x80024E68: nop

    // 0x80024E6C: lb          $v0, 0xF($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XF);
    // 0x80024E70: bnel        $v0, $zero, L_80024EAC
    if (ctx->r2 != 0) {
        // 0x80024E74: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80024EAC;
    }
    goto skip_2;
    // 0x80024E74: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_2:
L_80024E78:
    // 0x80024E78: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80024E7C: beq         $v0, $zero, L_80024E98
    if (ctx->r2 == 0) {
        // 0x80024E80: nop
    
            goto L_80024E98;
    }
    // 0x80024E80: nop

    // 0x80024E84: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80024E88: beq         $v0, $zero, L_80024E98
    if (ctx->r2 == 0) {
        // 0x80024E8C: nop
    
            goto L_80024E98;
    }
    // 0x80024E8C: nop

    // 0x80024E90: j           L_80024EAC
    // 0x80024E94: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80024EAC;
    // 0x80024E94: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80024E98:
    // 0x80024E98: lb          $v0, 0x48($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X48);
    // 0x80024E9C: beq         $v0, $zero, L_80024EAC
    if (ctx->r2 == 0) {
        // 0x80024EA0: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80024EAC;
    }
    // 0x80024EA0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80024EA4: lb          $v0, 0x14($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X14);
    // 0x80024EA8: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_80024EAC:
    // 0x80024EAC: bne         $v1, $zero, L_8002535C
    if (ctx->r3 != 0) {
        // 0x80024EB0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002535C;
    }
    // 0x80024EB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80024EB4: lb          $v0, 0x28($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X28);
    // 0x80024EB8: addiu       $v1, $a3, 0x4
    ctx->r3 = ADD32(ctx->r7, 0X4);
    // 0x80024EBC: beq         $v0, $zero, L_80024ED0
    if (ctx->r2 == 0) {
        // 0x80024EC0: addiu       $a0, $a1, 0x4
        ctx->r4 = ADD32(ctx->r5, 0X4);
            goto L_80024ED0;
    }
    // 0x80024EC0: addiu       $a0, $a1, 0x4
    ctx->r4 = ADD32(ctx->r5, 0X4);
    // 0x80024EC4: lb          $v0, 0xE($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XE);
    // 0x80024EC8: bnel        $v0, $zero, L_80024F34
    if (ctx->r2 != 0) {
        // 0x80024ECC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80024F34;
    }
    goto skip_3;
    // 0x80024ECC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_3:
L_80024ED0:
    // 0x80024ED0: lb          $v0, 0x12($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X12);
    // 0x80024ED4: beq         $v0, $zero, L_80024EE8
    if (ctx->r2 == 0) {
        // 0x80024ED8: nop
    
            goto L_80024EE8;
    }
    // 0x80024ED8: nop

    // 0x80024EDC: lb          $v0, 0x5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5);
    // 0x80024EE0: bnel        $v0, $zero, L_80024F34
    if (ctx->r2 != 0) {
        // 0x80024EE4: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80024F34;
    }
    goto skip_4;
    // 0x80024EE4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_4:
L_80024EE8:
    // 0x80024EE8: lb          $v0, 0x36($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X36);
    // 0x80024EEC: beq         $v0, $zero, L_80024F00
    if (ctx->r2 == 0) {
        // 0x80024EF0: nop
    
            goto L_80024F00;
    }
    // 0x80024EF0: nop

    // 0x80024EF4: lb          $v0, 0xF($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XF);
    // 0x80024EF8: bnel        $v0, $zero, L_80024F34
    if (ctx->r2 != 0) {
        // 0x80024EFC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80024F34;
    }
    goto skip_5;
    // 0x80024EFC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_5:
L_80024F00:
    // 0x80024F00: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80024F04: beq         $v0, $zero, L_80024F20
    if (ctx->r2 == 0) {
        // 0x80024F08: nop
    
            goto L_80024F20;
    }
    // 0x80024F08: nop

    // 0x80024F0C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80024F10: beq         $v0, $zero, L_80024F20
    if (ctx->r2 == 0) {
        // 0x80024F14: nop
    
            goto L_80024F20;
    }
    // 0x80024F14: nop

    // 0x80024F18: j           L_80024F34
    // 0x80024F1C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80024F34;
    // 0x80024F1C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80024F20:
    // 0x80024F20: lb          $v0, 0x48($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X48);
    // 0x80024F24: beq         $v0, $zero, L_80024F34
    if (ctx->r2 == 0) {
        // 0x80024F28: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80024F34;
    }
    // 0x80024F28: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80024F2C: lb          $v0, 0x14($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X14);
    // 0x80024F30: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_80024F34:
    // 0x80024F34: bne         $v1, $zero, L_8002535C
    if (ctx->r3 != 0) {
        // 0x80024F38: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002535C;
    }
    // 0x80024F38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80024F3C: lb          $v0, 0x26($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X26);
    // 0x80024F40: addiu       $v1, $a3, 0x2
    ctx->r3 = ADD32(ctx->r7, 0X2);
    // 0x80024F44: beq         $v0, $zero, L_80024F58
    if (ctx->r2 == 0) {
        // 0x80024F48: addiu       $a0, $a1, 0x2
        ctx->r4 = ADD32(ctx->r5, 0X2);
            goto L_80024F58;
    }
    // 0x80024F48: addiu       $a0, $a1, 0x2
    ctx->r4 = ADD32(ctx->r5, 0X2);
    // 0x80024F4C: lb          $v0, 0xC($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XC);
    // 0x80024F50: bnel        $v0, $zero, L_80024FBC
    if (ctx->r2 != 0) {
        // 0x80024F54: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80024FBC;
    }
    goto skip_6;
    // 0x80024F54: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_6:
L_80024F58:
    // 0x80024F58: lb          $v0, 0x12($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X12);
    // 0x80024F5C: beq         $v0, $zero, L_80024F70
    if (ctx->r2 == 0) {
        // 0x80024F60: nop
    
            goto L_80024F70;
    }
    // 0x80024F60: nop

    // 0x80024F64: lb          $v0, 0x5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5);
    // 0x80024F68: bnel        $v0, $zero, L_80024FBC
    if (ctx->r2 != 0) {
        // 0x80024F6C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80024FBC;
    }
    goto skip_7;
    // 0x80024F6C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_7:
L_80024F70:
    // 0x80024F70: lb          $v0, 0x36($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X36);
    // 0x80024F74: beq         $v0, $zero, L_80024F88
    if (ctx->r2 == 0) {
        // 0x80024F78: nop
    
            goto L_80024F88;
    }
    // 0x80024F78: nop

    // 0x80024F7C: lb          $v0, 0xF($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XF);
    // 0x80024F80: bnel        $v0, $zero, L_80024FBC
    if (ctx->r2 != 0) {
        // 0x80024F84: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80024FBC;
    }
    goto skip_8;
    // 0x80024F84: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_8:
L_80024F88:
    // 0x80024F88: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80024F8C: beq         $v0, $zero, L_80024FA8
    if (ctx->r2 == 0) {
        // 0x80024F90: nop
    
            goto L_80024FA8;
    }
    // 0x80024F90: nop

    // 0x80024F94: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80024F98: beq         $v0, $zero, L_80024FA8
    if (ctx->r2 == 0) {
        // 0x80024F9C: nop
    
            goto L_80024FA8;
    }
    // 0x80024F9C: nop

    // 0x80024FA0: j           L_80024FBC
    // 0x80024FA4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80024FBC;
    // 0x80024FA4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80024FA8:
    // 0x80024FA8: lb          $v0, 0x48($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X48);
    // 0x80024FAC: beq         $v0, $zero, L_80024FBC
    if (ctx->r2 == 0) {
        // 0x80024FB0: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80024FBC;
    }
    // 0x80024FB0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80024FB4: lb          $v0, 0x14($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X14);
    // 0x80024FB8: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_80024FBC:
    // 0x80024FBC: bne         $v1, $zero, L_8002535C
    if (ctx->r3 != 0) {
        // 0x80024FC0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002535C;
    }
    // 0x80024FC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80024FC4: lb          $v0, 0x25($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X25);
    // 0x80024FC8: addiu       $v1, $a3, 0x1
    ctx->r3 = ADD32(ctx->r7, 0X1);
    // 0x80024FCC: beq         $v0, $zero, L_80024FE0
    if (ctx->r2 == 0) {
        // 0x80024FD0: addiu       $a0, $a1, 0x1
        ctx->r4 = ADD32(ctx->r5, 0X1);
            goto L_80024FE0;
    }
    // 0x80024FD0: addiu       $a0, $a1, 0x1
    ctx->r4 = ADD32(ctx->r5, 0X1);
    // 0x80024FD4: lb          $v0, 0xB($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XB);
    // 0x80024FD8: bnel        $v0, $zero, L_80025044
    if (ctx->r2 != 0) {
        // 0x80024FDC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80025044;
    }
    goto skip_9;
    // 0x80024FDC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_9:
L_80024FE0:
    // 0x80024FE0: lb          $v0, 0x12($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X12);
    // 0x80024FE4: beq         $v0, $zero, L_80024FF8
    if (ctx->r2 == 0) {
        // 0x80024FE8: nop
    
            goto L_80024FF8;
    }
    // 0x80024FE8: nop

    // 0x80024FEC: lb          $v0, 0x5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5);
    // 0x80024FF0: bnel        $v0, $zero, L_80025044
    if (ctx->r2 != 0) {
        // 0x80024FF4: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80025044;
    }
    goto skip_10;
    // 0x80024FF4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_10:
L_80024FF8:
    // 0x80024FF8: lb          $v0, 0x36($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X36);
    // 0x80024FFC: beq         $v0, $zero, L_80025010
    if (ctx->r2 == 0) {
        // 0x80025000: nop
    
            goto L_80025010;
    }
    // 0x80025000: nop

    // 0x80025004: lb          $v0, 0xF($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XF);
    // 0x80025008: bnel        $v0, $zero, L_80025044
    if (ctx->r2 != 0) {
        // 0x8002500C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80025044;
    }
    goto skip_11;
    // 0x8002500C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_11:
L_80025010:
    // 0x80025010: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80025014: beq         $v0, $zero, L_80025030
    if (ctx->r2 == 0) {
        // 0x80025018: nop
    
            goto L_80025030;
    }
    // 0x80025018: nop

    // 0x8002501C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80025020: beq         $v0, $zero, L_80025030
    if (ctx->r2 == 0) {
        // 0x80025024: nop
    
            goto L_80025030;
    }
    // 0x80025024: nop

    // 0x80025028: j           L_80025044
    // 0x8002502C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80025044;
    // 0x8002502C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80025030:
    // 0x80025030: lb          $v0, 0x48($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X48);
    // 0x80025034: beq         $v0, $zero, L_80025044
    if (ctx->r2 == 0) {
        // 0x80025038: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80025044;
    }
    // 0x80025038: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8002503C: lb          $v0, 0x14($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X14);
    // 0x80025040: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_80025044:
    // 0x80025044: bne         $v1, $zero, L_8002535C
    if (ctx->r3 != 0) {
        // 0x80025048: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002535C;
    }
    // 0x80025048: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002504C: lb          $v0, 0x24($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X24);
    // 0x80025050: beq         $v0, $zero, L_80025064
    if (ctx->r2 == 0) {
        // 0x80025054: addu        $a0, $a1, $zero
        ctx->r4 = ADD32(ctx->r5, 0);
            goto L_80025064;
    }
    // 0x80025054: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x80025058: lb          $v0, 0xA($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XA);
    // 0x8002505C: bne         $v0, $zero, L_80025350
    if (ctx->r2 != 0) {
        // 0x80025060: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80025350;
    }
    // 0x80025060: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80025064:
    // 0x80025064: lb          $v0, 0x12($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X12);
    // 0x80025068: beq         $v0, $zero, L_8002507C
    if (ctx->r2 == 0) {
        // 0x8002506C: nop
    
            goto L_8002507C;
    }
    // 0x8002506C: nop

    // 0x80025070: lb          $v0, 0x5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5);
    // 0x80025074: bne         $v0, $zero, L_80025350
    if (ctx->r2 != 0) {
        // 0x80025078: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80025350;
    }
    // 0x80025078: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002507C:
    // 0x8002507C: lb          $v0, 0x36($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X36);
    // 0x80025080: beq         $v0, $zero, L_80025094
    if (ctx->r2 == 0) {
        // 0x80025084: nop
    
            goto L_80025094;
    }
    // 0x80025084: nop

    // 0x80025088: lb          $v0, 0xF($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XF);
    // 0x8002508C: bne         $v0, $zero, L_80025350
    if (ctx->r2 != 0) {
        // 0x80025090: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80025350;
    }
    // 0x80025090: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80025094:
    // 0x80025094: lb          $v0, 0x0($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X0);
    // 0x80025098: beq         $v0, $zero, L_8002533C
    if (ctx->r2 == 0) {
        // 0x8002509C: nop
    
            goto L_8002533C;
    }
    // 0x8002509C: nop

    // 0x800250A0: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800250A4: bnel        $v0, $zero, L_80025350
    if (ctx->r2 != 0) {
        // 0x800250A8: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80025350;
    }
    goto skip_12;
    // 0x800250A8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_12:
    // 0x800250AC: j           L_8002533C
    // 0x800250B0: nop

        goto L_8002533C;
    // 0x800250B0: nop

L_800250B4:
    // 0x800250B4: lb          $v0, 0x25($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X25);
    // 0x800250B8: beq         $v0, $zero, L_800250CC
    if (ctx->r2 == 0) {
        // 0x800250BC: addiu       $a0, $a1, 0x1
        ctx->r4 = ADD32(ctx->r5, 0X1);
            goto L_800250CC;
    }
    // 0x800250BC: addiu       $a0, $a1, 0x1
    ctx->r4 = ADD32(ctx->r5, 0X1);
    // 0x800250C0: lb          $v0, 0xB($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XB);
    // 0x800250C4: bnel        $v0, $zero, L_80025130
    if (ctx->r2 != 0) {
        // 0x800250C8: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80025130;
    }
    goto skip_13;
    // 0x800250C8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_13:
L_800250CC:
    // 0x800250CC: lb          $v0, 0x12($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X12);
    // 0x800250D0: beq         $v0, $zero, L_800250E4
    if (ctx->r2 == 0) {
        // 0x800250D4: nop
    
            goto L_800250E4;
    }
    // 0x800250D4: nop

    // 0x800250D8: lb          $v0, 0x5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5);
    // 0x800250DC: bnel        $v0, $zero, L_80025130
    if (ctx->r2 != 0) {
        // 0x800250E0: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80025130;
    }
    goto skip_14;
    // 0x800250E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_14:
L_800250E4:
    // 0x800250E4: lb          $v0, 0x36($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X36);
    // 0x800250E8: beq         $v0, $zero, L_800250FC
    if (ctx->r2 == 0) {
        // 0x800250EC: nop
    
            goto L_800250FC;
    }
    // 0x800250EC: nop

    // 0x800250F0: lb          $v0, 0xF($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XF);
    // 0x800250F4: bnel        $v0, $zero, L_80025130
    if (ctx->r2 != 0) {
        // 0x800250F8: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80025130;
    }
    goto skip_15;
    // 0x800250F8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_15:
L_800250FC:
    // 0x800250FC: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80025100: beq         $v0, $zero, L_8002511C
    if (ctx->r2 == 0) {
        // 0x80025104: nop
    
            goto L_8002511C;
    }
    // 0x80025104: nop

    // 0x80025108: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8002510C: beq         $v0, $zero, L_8002511C
    if (ctx->r2 == 0) {
        // 0x80025110: nop
    
            goto L_8002511C;
    }
    // 0x80025110: nop

    // 0x80025114: j           L_80025130
    // 0x80025118: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80025130;
    // 0x80025118: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002511C:
    // 0x8002511C: lb          $v0, 0x48($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X48);
    // 0x80025120: beq         $v0, $zero, L_80025130
    if (ctx->r2 == 0) {
        // 0x80025124: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80025130;
    }
    // 0x80025124: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80025128: lb          $v0, 0x14($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X14);
    // 0x8002512C: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_80025130:
    // 0x80025130: bne         $v1, $zero, L_8002535C
    if (ctx->r3 != 0) {
        // 0x80025134: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002535C;
    }
    // 0x80025134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80025138: lb          $v0, 0x24($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X24);
    // 0x8002513C: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x80025140: beq         $v0, $zero, L_80025154
    if (ctx->r2 == 0) {
        // 0x80025144: addu        $a0, $a1, $zero
        ctx->r4 = ADD32(ctx->r5, 0);
            goto L_80025154;
    }
    // 0x80025144: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x80025148: lb          $v0, 0xA($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XA);
    // 0x8002514C: bnel        $v0, $zero, L_800251B8
    if (ctx->r2 != 0) {
        // 0x80025150: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800251B8;
    }
    goto skip_16;
    // 0x80025150: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_16:
L_80025154:
    // 0x80025154: lb          $v0, 0x12($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X12);
    // 0x80025158: beq         $v0, $zero, L_8002516C
    if (ctx->r2 == 0) {
        // 0x8002515C: nop
    
            goto L_8002516C;
    }
    // 0x8002515C: nop

    // 0x80025160: lb          $v0, 0x5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5);
    // 0x80025164: bnel        $v0, $zero, L_800251B8
    if (ctx->r2 != 0) {
        // 0x80025168: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800251B8;
    }
    goto skip_17;
    // 0x80025168: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_17:
L_8002516C:
    // 0x8002516C: lb          $v0, 0x36($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X36);
    // 0x80025170: beq         $v0, $zero, L_80025184
    if (ctx->r2 == 0) {
        // 0x80025174: nop
    
            goto L_80025184;
    }
    // 0x80025174: nop

    // 0x80025178: lb          $v0, 0xF($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XF);
    // 0x8002517C: bnel        $v0, $zero, L_800251B8
    if (ctx->r2 != 0) {
        // 0x80025180: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800251B8;
    }
    goto skip_18;
    // 0x80025180: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_18:
L_80025184:
    // 0x80025184: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80025188: beq         $v0, $zero, L_800251A4
    if (ctx->r2 == 0) {
        // 0x8002518C: nop
    
            goto L_800251A4;
    }
    // 0x8002518C: nop

    // 0x80025190: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80025194: beq         $v0, $zero, L_800251A4
    if (ctx->r2 == 0) {
        // 0x80025198: nop
    
            goto L_800251A4;
    }
    // 0x80025198: nop

    // 0x8002519C: j           L_800251B8
    // 0x800251A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800251B8;
    // 0x800251A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800251A4:
    // 0x800251A4: lb          $v0, 0x48($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X48);
    // 0x800251A8: beq         $v0, $zero, L_800251B8
    if (ctx->r2 == 0) {
        // 0x800251AC: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800251B8;
    }
    // 0x800251AC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800251B0: lb          $v0, 0x14($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X14);
    // 0x800251B4: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_800251B8:
    // 0x800251B8: bne         $v1, $zero, L_8002535C
    if (ctx->r3 != 0) {
        // 0x800251BC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002535C;
    }
    // 0x800251BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800251C0: lb          $v0, 0x26($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X26);
    // 0x800251C4: addiu       $v1, $a3, 0x2
    ctx->r3 = ADD32(ctx->r7, 0X2);
    // 0x800251C8: beq         $v0, $zero, L_800251DC
    if (ctx->r2 == 0) {
        // 0x800251CC: addiu       $a0, $a1, 0x2
        ctx->r4 = ADD32(ctx->r5, 0X2);
            goto L_800251DC;
    }
    // 0x800251CC: addiu       $a0, $a1, 0x2
    ctx->r4 = ADD32(ctx->r5, 0X2);
    // 0x800251D0: lb          $v0, 0xC($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XC);
    // 0x800251D4: bnel        $v0, $zero, L_80025240
    if (ctx->r2 != 0) {
        // 0x800251D8: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80025240;
    }
    goto skip_19;
    // 0x800251D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_19:
L_800251DC:
    // 0x800251DC: lb          $v0, 0x12($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X12);
    // 0x800251E0: beq         $v0, $zero, L_800251F4
    if (ctx->r2 == 0) {
        // 0x800251E4: nop
    
            goto L_800251F4;
    }
    // 0x800251E4: nop

    // 0x800251E8: lb          $v0, 0x5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5);
    // 0x800251EC: bnel        $v0, $zero, L_80025240
    if (ctx->r2 != 0) {
        // 0x800251F0: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80025240;
    }
    goto skip_20;
    // 0x800251F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_20:
L_800251F4:
    // 0x800251F4: lb          $v0, 0x36($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X36);
    // 0x800251F8: beq         $v0, $zero, L_8002520C
    if (ctx->r2 == 0) {
        // 0x800251FC: nop
    
            goto L_8002520C;
    }
    // 0x800251FC: nop

    // 0x80025200: lb          $v0, 0xF($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XF);
    // 0x80025204: bnel        $v0, $zero, L_80025240
    if (ctx->r2 != 0) {
        // 0x80025208: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80025240;
    }
    goto skip_21;
    // 0x80025208: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_21:
L_8002520C:
    // 0x8002520C: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80025210: beq         $v0, $zero, L_8002522C
    if (ctx->r2 == 0) {
        // 0x80025214: nop
    
            goto L_8002522C;
    }
    // 0x80025214: nop

    // 0x80025218: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8002521C: beq         $v0, $zero, L_8002522C
    if (ctx->r2 == 0) {
        // 0x80025220: nop
    
            goto L_8002522C;
    }
    // 0x80025220: nop

    // 0x80025224: j           L_80025240
    // 0x80025228: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80025240;
    // 0x80025228: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002522C:
    // 0x8002522C: lb          $v0, 0x48($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X48);
    // 0x80025230: beq         $v0, $zero, L_80025240
    if (ctx->r2 == 0) {
        // 0x80025234: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80025240;
    }
    // 0x80025234: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80025238: lb          $v0, 0x14($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X14);
    // 0x8002523C: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_80025240:
    // 0x80025240: bne         $v1, $zero, L_8002535C
    if (ctx->r3 != 0) {
        // 0x80025244: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002535C;
    }
    // 0x80025244: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80025248: lb          $v0, 0x27($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X27);
    // 0x8002524C: addiu       $v1, $a3, 0x3
    ctx->r3 = ADD32(ctx->r7, 0X3);
    // 0x80025250: beq         $v0, $zero, L_80025264
    if (ctx->r2 == 0) {
        // 0x80025254: addiu       $a0, $a1, 0x3
        ctx->r4 = ADD32(ctx->r5, 0X3);
            goto L_80025264;
    }
    // 0x80025254: addiu       $a0, $a1, 0x3
    ctx->r4 = ADD32(ctx->r5, 0X3);
    // 0x80025258: lb          $v0, 0xD($a1)
    ctx->r2 = MEM_B(ctx->r5, 0XD);
    // 0x8002525C: bnel        $v0, $zero, L_800252C8
    if (ctx->r2 != 0) {
        // 0x80025260: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800252C8;
    }
    goto skip_22;
    // 0x80025260: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_22:
L_80025264:
    // 0x80025264: lb          $v0, 0x12($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X12);
    // 0x80025268: beq         $v0, $zero, L_8002527C
    if (ctx->r2 == 0) {
        // 0x8002526C: nop
    
            goto L_8002527C;
    }
    // 0x8002526C: nop

    // 0x80025270: lb          $v0, 0x5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5);
    // 0x80025274: bnel        $v0, $zero, L_800252C8
    if (ctx->r2 != 0) {
        // 0x80025278: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800252C8;
    }
    goto skip_23;
    // 0x80025278: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_23:
L_8002527C:
    // 0x8002527C: lb          $v0, 0x36($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X36);
    // 0x80025280: beq         $v0, $zero, L_80025294
    if (ctx->r2 == 0) {
        // 0x80025284: nop
    
            goto L_80025294;
    }
    // 0x80025284: nop

    // 0x80025288: lb          $v0, 0xF($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XF);
    // 0x8002528C: bnel        $v0, $zero, L_800252C8
    if (ctx->r2 != 0) {
        // 0x80025290: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800252C8;
    }
    goto skip_24;
    // 0x80025290: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_24:
L_80025294:
    // 0x80025294: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80025298: beq         $v0, $zero, L_800252B4
    if (ctx->r2 == 0) {
        // 0x8002529C: nop
    
            goto L_800252B4;
    }
    // 0x8002529C: nop

    // 0x800252A0: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800252A4: beq         $v0, $zero, L_800252B4
    if (ctx->r2 == 0) {
        // 0x800252A8: nop
    
            goto L_800252B4;
    }
    // 0x800252A8: nop

    // 0x800252AC: j           L_800252C8
    // 0x800252B0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800252C8;
    // 0x800252B0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800252B4:
    // 0x800252B4: lb          $v0, 0x48($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X48);
    // 0x800252B8: beq         $v0, $zero, L_800252C8
    if (ctx->r2 == 0) {
        // 0x800252BC: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800252C8;
    }
    // 0x800252BC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800252C0: lb          $v0, 0x14($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X14);
    // 0x800252C4: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_800252C8:
    // 0x800252C8: bne         $v1, $zero, L_8002535C
    if (ctx->r3 != 0) {
        // 0x800252CC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002535C;
    }
    // 0x800252CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800252D0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800252D4: lb          $v0, 0x24($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X24);
    // 0x800252D8: beq         $v0, $zero, L_800252EC
    if (ctx->r2 == 0) {
        // 0x800252DC: addiu       $a0, $a1, 0x4
        ctx->r4 = ADD32(ctx->r5, 0X4);
            goto L_800252EC;
    }
    // 0x800252DC: addiu       $a0, $a1, 0x4
    ctx->r4 = ADD32(ctx->r5, 0X4);
    // 0x800252E0: lb          $v0, 0xA($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XA);
    // 0x800252E4: bne         $v0, $zero, L_80025350
    if (ctx->r2 != 0) {
        // 0x800252E8: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80025350;
    }
    // 0x800252E8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800252EC:
    // 0x800252EC: lb          $v0, 0x12($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X12);
    // 0x800252F0: beq         $v0, $zero, L_80025304
    if (ctx->r2 == 0) {
        // 0x800252F4: nop
    
            goto L_80025304;
    }
    // 0x800252F4: nop

    // 0x800252F8: lb          $v0, 0x5($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5);
    // 0x800252FC: bne         $v0, $zero, L_80025350
    if (ctx->r2 != 0) {
        // 0x80025300: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80025350;
    }
    // 0x80025300: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80025304:
    // 0x80025304: lb          $v0, 0x36($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X36);
    // 0x80025308: beq         $v0, $zero, L_8002531C
    if (ctx->r2 == 0) {
        // 0x8002530C: nop
    
            goto L_8002531C;
    }
    // 0x8002530C: nop

    // 0x80025310: lb          $v0, 0xF($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XF);
    // 0x80025314: bne         $v0, $zero, L_80025350
    if (ctx->r2 != 0) {
        // 0x80025318: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80025350;
    }
    // 0x80025318: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002531C:
    // 0x8002531C: lb          $v0, 0x0($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X0);
    // 0x80025320: beq         $v0, $zero, L_8002533C
    if (ctx->r2 == 0) {
        // 0x80025324: nop
    
            goto L_8002533C;
    }
    // 0x80025324: nop

    // 0x80025328: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8002532C: beq         $v0, $zero, L_8002533C
    if (ctx->r2 == 0) {
        // 0x80025330: nop
    
            goto L_8002533C;
    }
    // 0x80025330: nop

    // 0x80025334: j           L_80025350
    // 0x80025338: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80025350;
    // 0x80025338: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002533C:
    // 0x8002533C: lb          $v0, 0x48($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X48);
    // 0x80025340: beq         $v0, $zero, L_80025350
    if (ctx->r2 == 0) {
        // 0x80025344: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80025350;
    }
    // 0x80025344: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80025348: lb          $v0, 0x14($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X14);
    // 0x8002534C: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_80025350:
    // 0x80025350: bne         $v1, $zero, L_8002535C
    if (ctx->r3 != 0) {
        // 0x80025354: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002535C;
    }
    // 0x80025354: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80025358: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8002535C:
    // 0x8002535C: jr          $ra
    // 0x80025360: nop

    return;
    // 0x80025360: nop

;}
RECOMP_FUNC void func_80025364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025364: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80025368: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x8002536C: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80025370: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x80025374: addu        $a2, $a2, $a1
    ctx->r6 = ADD32(ctx->r6, ctx->r5);
    // 0x80025378: lw          $a2, 0x43A8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X43A8);
    // 0x8002537C: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x80025380: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80025384: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x80025388: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002538C: sll         $a1, $v1, 3
    ctx->r5 = S32(ctx->r3 << 3);
    // 0x80025390: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x80025394: lb          $v1, 0x54($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X54);
    // 0x80025398: lw          $v0, 0xDC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XDC);
    // 0x8002539C: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x800253A0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800253A4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800253A8: lb          $v0, 0x4C($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X4C);
    // 0x800253AC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800253B0: addu        $a2, $a2, $a1
    ctx->r6 = ADD32(ctx->r6, ctx->r5);
    // 0x800253B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800253B8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800253BC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
L_800253C0:
    // 0x800253C0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800253C4:
    // 0x800253C4: lb          $v0, 0x0($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X0);
    // 0x800253C8: beql        $v0, $zero, L_800253E4
    if (ctx->r2 == 0) {
        // 0x800253CC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800253E4;
    }
    goto skip_0;
    // 0x800253CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x800253D0: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800253D4: beql        $v0, $zero, L_800253E4
    if (ctx->r2 == 0) {
        // 0x800253D8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800253E4;
    }
    goto skip_1;
    // 0x800253D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x800253DC: j           L_80025408
    // 0x800253E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80025408;
    // 0x800253E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800253E4:
    // 0x800253E4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800253E8: slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x800253EC: bne         $v0, $zero, L_800253C4
    if (ctx->r2 != 0) {
        // 0x800253F0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800253C4;
    }
    // 0x800253F0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800253F4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800253F8: slti        $v0, $a3, 0x5
    ctx->r2 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
    // 0x800253FC: bne         $v0, $zero, L_800253C0
    if (ctx->r2 != 0) {
        // 0x80025400: addiu       $a2, $a2, 0xD
        ctx->r6 = ADD32(ctx->r6, 0XD);
            goto L_800253C0;
    }
    // 0x80025400: addiu       $a2, $a2, 0xD
    ctx->r6 = ADD32(ctx->r6, 0XD);
    // 0x80025404: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80025408:
    // 0x80025408: jr          $ra
    // 0x8002540C: nop

    return;
    // 0x8002540C: nop

;}
RECOMP_FUNC void func_80025410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025410: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // 0x80025414: addu        $t2, $a2, $zero
    ctx->r10 = ADD32(ctx->r6, 0);
    // 0x80025418: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // 0x8002541C: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80025420: sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7 << 2);
    // 0x80025424: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80025428: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8002542C: addu        $a2, $a2, $a3
    ctx->r6 = ADD32(ctx->r6, ctx->r7);
    // 0x80025430: lw          $a2, 0x43A8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X43A8);
    // 0x80025434: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x80025438: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8002543C: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x80025440: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80025444: sll         $a1, $v1, 3
    ctx->r5 = S32(ctx->r3 << 3);
    // 0x80025448: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x8002544C: lb          $v1, 0x54($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X54);
    // 0x80025450: lw          $v0, 0xDC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XDC);
    // 0x80025454: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x80025458: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8002545C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80025460: lb          $v0, 0x4C($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X4C);
    // 0x80025464: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80025468: addu        $a2, $a2, $a1
    ctx->r6 = ADD32(ctx->r6, ctx->r5);
    // 0x8002546C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80025470: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80025474: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
L_80025478:
    // 0x80025478: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8002547C:
    // 0x8002547C: lb          $v0, 0x0($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X0);
    // 0x80025480: beql        $v0, $zero, L_800254BC
    if (ctx->r2 == 0) {
        // 0x80025484: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800254BC;
    }
    goto skip_0;
    // 0x80025484: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x80025488: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8002548C: beql        $v0, $zero, L_800254BC
    if (ctx->r2 == 0) {
        // 0x80025490: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800254BC;
    }
    goto skip_1;
    // 0x80025490: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x80025494: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80025498: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8002549C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800254A0: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x800254A4: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800254A8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800254AC: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x800254B0: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800254B4: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x800254B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800254BC:
    // 0x800254BC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800254C0: slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x800254C4: bne         $v0, $zero, L_8002547C
    if (ctx->r2 != 0) {
        // 0x800254C8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8002547C;
    }
    // 0x800254C8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800254CC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800254D0: slti        $v0, $t0, 0x5
    ctx->r2 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x800254D4: bne         $v0, $zero, L_80025478
    if (ctx->r2 != 0) {
        // 0x800254D8: addiu       $a2, $a2, 0xD
        ctx->r6 = ADD32(ctx->r6, 0XD);
            goto L_80025478;
    }
    // 0x800254D8: addiu       $a2, $a2, 0xD
    ctx->r6 = ADD32(ctx->r6, 0XD);
    // 0x800254DC: jr          $ra
    // 0x800254E0: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
    return;
    // 0x800254E0: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
;}
RECOMP_FUNC void func_800254E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800254E4: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x800254E8: lb          $v1, 0x128($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X128);
    // 0x800254EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800254F0: bne         $v1, $v0, L_80025504
    if (ctx->r3 != ctx->r2) {
        // 0x800254F4: addiu       $sp, $sp, -0x10
        ctx->r29 = ADD32(ctx->r29, -0X10);
            goto L_80025504;
    }
    // 0x800254F4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800254F8: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x800254FC: j           L_800255D4
    // 0x80025500: sb          $zero, 0x128($a3)
    MEM_B(0X128, ctx->r7) = 0;
        goto L_800255D4;
    // 0x80025500: sb          $zero, 0x128($a3)
    MEM_B(0X128, ctx->r7) = 0;
L_80025504:
    // 0x80025504: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80025508: addiu       $t1, $zero, 0x12
    ctx->r9 = ADD32(0, 0X12);
    // 0x8002550C: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80025510: addiu       $t0, $t0, 0x43A8
    ctx->r8 = ADD32(ctx->r8, 0X43A8);
    // 0x80025514: sll         $v0, $a2, 24
    ctx->r2 = S32(ctx->r6 << 24);
L_80025518:
    // 0x80025518: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8002551C: addu        $v1, $sp, $v0
    ctx->r3 = ADD32(ctx->r29, ctx->r2);
    // 0x80025520: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x80025524: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80025528: addiu       $a1, $zero, -0x6
    ctx->r5 = ADD32(0, -0X6);
    // 0x8002552C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80025530: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
L_80025534:
    // 0x80025534: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80025538: beq         $v0, $zero, L_80025548
    if (ctx->r2 == 0) {
        // 0x8002553C: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_80025548;
    }
    // 0x8002553C: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x80025540: j           L_80025560
    // 0x80025544: sb          $a1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r5;
        goto L_80025560;
    // 0x80025544: sb          $a1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r5;
L_80025548:
    // 0x80025548: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8002554C: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80025550: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80025554: slti        $v0, $v0, 0x12
    ctx->r2 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x80025558: bne         $v0, $zero, L_80025534
    if (ctx->r2 != 0) {
        // 0x8002555C: addiu       $a0, $a0, 0x12
        ctx->r4 = ADD32(ctx->r4, 0X12);
            goto L_80025534;
    }
    // 0x8002555C: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
L_80025560:
    // 0x80025560: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x80025564: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80025568: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8002556C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80025570: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80025574: bne         $v0, $zero, L_80025518
    if (ctx->r2 != 0) {
        // 0x80025578: sll         $v0, $a2, 24
        ctx->r2 = S32(ctx->r6 << 24);
            goto L_80025518;
    }
    // 0x80025578: sll         $v0, $a2, 24
    ctx->r2 = S32(ctx->r6 << 24);
    // 0x8002557C: sb          $zero, 0x128($a3)
    MEM_B(0X128, ctx->r7) = 0;
    // 0x80025580: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80025584:
    // 0x80025584: lb          $v0, 0x128($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X128);
    // 0x80025588: addu        $a0, $sp, $v0
    ctx->r4 = ADD32(ctx->r29, ctx->r2);
    // 0x8002558C: sll         $v0, $a2, 24
    ctx->r2 = S32(ctx->r6 << 24);
    // 0x80025590: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80025594: addu        $v1, $sp, $v0
    ctx->r3 = ADD32(ctx->r29, ctx->r2);
    // 0x80025598: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8002559C: lb          $v1, 0x0($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X0);
    // 0x800255A0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800255A4: bnel        $v0, $zero, L_800255AC
    if (ctx->r2 != 0) {
        // 0x800255A8: sb          $a2, 0x128($a3)
        MEM_B(0X128, ctx->r7) = ctx->r6;
            goto L_800255AC;
    }
    goto skip_0;
    // 0x800255A8: sb          $a2, 0x128($a3)
    MEM_B(0X128, ctx->r7) = ctx->r6;
    skip_0:
L_800255AC:
    // 0x800255AC: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x800255B0: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x800255B4: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800255B8: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800255BC: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x800255C0: bne         $v0, $zero, L_80025584
    if (ctx->r2 != 0) {
        // 0x800255C4: nop
    
            goto L_80025584;
    }
    // 0x800255C4: nop

    // 0x800255C8: lb          $v0, 0x128($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X128);
    // 0x800255CC: addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // 0x800255D0: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
L_800255D4:
    // 0x800255D4: sb          $v0, 0x129($a3)
    MEM_B(0X129, ctx->r7) = ctx->r2;
    // 0x800255D8: jr          $ra
    // 0x800255DC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800255DC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800255E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800255E0: lb          $a3, 0x128($a0)
    ctx->r7 = MEM_B(ctx->r4, 0X128);
    // 0x800255E4: bltz        $a3, L_80025644
    if (SIGNED(ctx->r7) < 0) {
        // 0x800255E8: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_80025644;
    }
    // 0x800255E8: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x800255EC: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800255F0: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800255F4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800255F8: lw          $v1, 0x43A8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X43A8);
    // 0x800255FC: addiu       $v0, $a3, 0x4
    ctx->r2 = ADD32(ctx->r7, 0X4);
    // 0x80025600: lb          $a0, 0x129($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X129);
    // 0x80025604: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80025608: addiu       $v0, $zero, -0x6
    ctx->r2 = ADD32(0, -0X6);
    // 0x8002560C: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80025610: beq         $v0, $zero, L_80025644
    if (ctx->r2 == 0) {
        // 0x80025614: addiu       $a2, $zero, -0x6
        ctx->r6 = ADD32(0, -0X6);
            goto L_80025644;
    }
    // 0x80025614: addiu       $a2, $zero, -0x6
    ctx->r6 = ADD32(0, -0X6);
L_80025618:
    // 0x80025618: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8002561C: beql        $v0, $zero, L_8002562C
    if (ctx->r2 == 0) {
        // 0x80025620: addiu       $v0, $a2, 0x1
        ctx->r2 = ADD32(ctx->r6, 0X1);
            goto L_8002562C;
    }
    goto skip_0;
    // 0x80025620: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    skip_0:
    // 0x80025624: j           L_80025644
    // 0x80025628: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80025644;
    // 0x80025628: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8002562C:
    // 0x8002562C: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80025630: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80025634: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80025638: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002563C: bne         $v0, $zero, L_80025618
    if (ctx->r2 != 0) {
        // 0x80025640: addiu       $v1, $v1, 0x12
        ctx->r3 = ADD32(ctx->r3, 0X12);
            goto L_80025618;
    }
    // 0x80025640: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
L_80025644:
    // 0x80025644: jr          $ra
    // 0x80025648: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    return;
    // 0x80025648: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
;}
RECOMP_FUNC void func_8002564C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002564C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80025650: lb          $v0, 0xCC($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XCC);
    // 0x80025654: lb          $a1, 0xCD($a0)
    ctx->r5 = MEM_B(ctx->r4, 0XCD);
    // 0x80025658: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8002565C: beq         $v0, $a1, L_80025688
    if (ctx->r2 == ctx->r5) {
        // 0x80025660: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80025688;
    }
    // 0x80025660: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80025664: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80025668: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8002566C: beq         $v0, $a1, L_80025688
    if (ctx->r2 == ctx->r5) {
        // 0x80025670: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80025688;
    }
    // 0x80025670: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_80025674:
    // 0x80025674: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80025678: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x8002567C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80025680: bne         $v0, $a1, L_80025674
    if (ctx->r2 != ctx->r5) {
        // 0x80025684: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80025674;
    }
    // 0x80025684: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80025688:
    // 0x80025688: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8002568C: jr          $ra
    // 0x80025690: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80025690: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80025694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025694: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80025698: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x8002569C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800256A0: lui         $at, 0x434E
    ctx->r1 = S32(0X434E << 16);
    // 0x800256A4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800256A8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x800256AC: addiu       $a1, $a1, 0x7BE0
    ctx->r5 = ADD32(ctx->r5, 0X7BE0);
    // 0x800256B0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800256B4:
    // 0x800256B4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800256B8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800256BC: lb          $v0, 0x7BD0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7BD0);
    // 0x800256C0: beql        $v0, $zero, L_80025734
    if (ctx->r2 == 0) {
        // 0x800256C4: addiu       $a1, $a1, 0x68
        ctx->r5 = ADD32(ctx->r5, 0X68);
            goto L_80025734;
    }
    goto skip_0;
    // 0x800256C4: addiu       $a1, $a1, 0x68
    ctx->r5 = ADD32(ctx->r5, 0X68);
    skip_0:
    // 0x800256C8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800256CC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800256D0: lw          $v0, 0x7C04($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7C04);
    // 0x800256D4: bnel        $v0, $a0, L_80025734
    if (ctx->r2 != ctx->r4) {
        // 0x800256D8: addiu       $a1, $a1, 0x68
        ctx->r5 = ADD32(ctx->r5, 0X68);
            goto L_80025734;
    }
    goto skip_1;
    // 0x800256D8: addiu       $a1, $a1, 0x68
    ctx->r5 = ADD32(ctx->r5, 0X68);
    skip_1:
    // 0x800256DC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800256E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800256E4: lbu         $v0, 0x7BD1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7BD1);
    // 0x800256E8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800256EC: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800256F0: beql        $v0, $zero, L_80025734
    if (ctx->r2 == 0) {
        // 0x800256F4: addiu       $a1, $a1, 0x68
        ctx->r5 = ADD32(ctx->r5, 0X68);
            goto L_80025734;
    }
    goto skip_2;
    // 0x800256F4: addiu       $a1, $a1, 0x68
    ctx->r5 = ADD32(ctx->r5, 0X68);
    skip_2:
    // 0x800256F8: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x800256FC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80025700: beq         $v0, $zero, L_80025718
    if (ctx->r2 == 0) {
        // 0x80025704: nop
    
            goto L_80025718;
    }
    // 0x80025704: nop

    // 0x80025708: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002570C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80025710: j           L_80025728
    // 0x80025714: nop

        goto L_80025728;
    // 0x80025714: nop

L_80025718:
    // 0x80025718: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002571C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80025720: nop

    // 0x80025724: nop

L_80025728:
    // 0x80025728: bc1t        L_80025748
    if (c1cs) {
        // 0x8002572C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80025748;
    }
    // 0x8002572C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80025730: addiu       $a1, $a1, 0x68
    ctx->r5 = ADD32(ctx->r5, 0X68);
L_80025734:
    // 0x80025734: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80025738: slti        $v0, $a2, 0x18
    ctx->r2 = SIGNED(ctx->r6) < 0X18 ? 1 : 0;
    // 0x8002573C: bne         $v0, $zero, L_800256B4
    if (ctx->r2 != 0) {
        // 0x80025740: addiu       $v1, $v1, 0x68
        ctx->r3 = ADD32(ctx->r3, 0X68);
            goto L_800256B4;
    }
    // 0x80025740: addiu       $v1, $v1, 0x68
    ctx->r3 = ADD32(ctx->r3, 0X68);
    // 0x80025744: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80025748:
    // 0x80025748: jr          $ra
    // 0x8002574C: nop

    return;
    // 0x8002574C: nop

;}
RECOMP_FUNC void func_80025750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025750: addu        $v1, $a0, $a1
    ctx->r3 = ADD32(ctx->r4, ctx->r5);
    // 0x80025754: slti        $v0, $v1, 0x7531
    ctx->r2 = SIGNED(ctx->r3) < 0X7531 ? 1 : 0;
    // 0x80025758: bne         $v0, $zero, L_80025788
    if (ctx->r2 != 0) {
        // 0x8002575C: slti        $v0, $v1, -0x7530
        ctx->r2 = SIGNED(ctx->r3) < -0X7530 ? 1 : 0;
            goto L_80025788;
    }
    // 0x8002575C: slti        $v0, $v1, -0x7530
    ctx->r2 = SIGNED(ctx->r3) < -0X7530 ? 1 : 0;
    // 0x80025760: slti        $v0, $a0, 0x7531
    ctx->r2 = SIGNED(ctx->r4) < 0X7531 ? 1 : 0;
    // 0x80025764: beql        $v0, $zero, L_8002576C
    if (ctx->r2 == 0) {
        // 0x80025768: addiu       $a0, $zero, 0x4E20
        ctx->r4 = ADD32(0, 0X4E20);
            goto L_8002576C;
    }
    goto skip_0;
    // 0x80025768: addiu       $a0, $zero, 0x4E20
    ctx->r4 = ADD32(0, 0X4E20);
    skip_0:
L_8002576C:
    // 0x8002576C: sra         $a1, $a1, 1
    ctx->r5 = S32(SIGNED(ctx->r5) >> 1);
L_80025770:
    // 0x80025770: addu        $v1, $a0, $a1
    ctx->r3 = ADD32(ctx->r4, ctx->r5);
    // 0x80025774: slti        $v0, $v1, 0x7531
    ctx->r2 = SIGNED(ctx->r3) < 0X7531 ? 1 : 0;
    // 0x80025778: beql        $v0, $zero, L_80025770
    if (ctx->r2 == 0) {
        // 0x8002577C: sra         $a1, $a1, 1
        ctx->r5 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80025770;
    }
    goto skip_1;
    // 0x8002577C: sra         $a1, $a1, 1
    ctx->r5 = S32(SIGNED(ctx->r5) >> 1);
    skip_1:
    // 0x80025780: j           L_800257B4
    // 0x80025784: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
        goto L_800257B4;
    // 0x80025784: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
L_80025788:
    // 0x80025788: beq         $v0, $zero, L_800257B4
    if (ctx->r2 == 0) {
        // 0x8002578C: sll         $v0, $v1, 16
        ctx->r2 = S32(ctx->r3 << 16);
            goto L_800257B4;
    }
    // 0x8002578C: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80025790: slti        $v0, $a0, -0x7530
    ctx->r2 = SIGNED(ctx->r4) < -0X7530 ? 1 : 0;
    // 0x80025794: bnel        $v0, $zero, L_8002579C
    if (ctx->r2 != 0) {
        // 0x80025798: addiu       $a0, $zero, -0x4E20
        ctx->r4 = ADD32(0, -0X4E20);
            goto L_8002579C;
    }
    goto skip_2;
    // 0x80025798: addiu       $a0, $zero, -0x4E20
    ctx->r4 = ADD32(0, -0X4E20);
    skip_2:
L_8002579C:
    // 0x8002579C: sra         $a1, $a1, 1
    ctx->r5 = S32(SIGNED(ctx->r5) >> 1);
L_800257A0:
    // 0x800257A0: addu        $v1, $a0, $a1
    ctx->r3 = ADD32(ctx->r4, ctx->r5);
    // 0x800257A4: slti        $v0, $v1, -0x7530
    ctx->r2 = SIGNED(ctx->r3) < -0X7530 ? 1 : 0;
    // 0x800257A8: bnel        $v0, $zero, L_800257A0
    if (ctx->r2 != 0) {
        // 0x800257AC: sra         $a1, $a1, 1
        ctx->r5 = S32(SIGNED(ctx->r5) >> 1);
            goto L_800257A0;
    }
    goto skip_3;
    // 0x800257AC: sra         $a1, $a1, 1
    ctx->r5 = S32(SIGNED(ctx->r5) >> 1);
    skip_3:
    // 0x800257B0: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
L_800257B4:
    // 0x800257B4: jr          $ra
    // 0x800257B8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x800257B8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
;}
RECOMP_FUNC void func_800257C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800257C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800257C4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800257C8: lb          $v0, 0x11D($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X11D);
    // 0x800257CC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800257D0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800257D4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800257D8: lw          $v0, 0x28B8($at)
    ctx->r2 = MEM_W(ctx->r1, 0X28B8);
    // 0x800257DC: jalr        $v0
    // 0x800257E0: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800257E0: nop

    after_0:
    // 0x800257E4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800257E8: jr          $ra
    // 0x800257EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800257EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800257F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800257F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800257F4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800257F8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800257FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025800: lb          $v1, 0x123($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X123);
    // 0x80025804: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80025808: bne         $v1, $v0, L_80025820
    if (ctx->r3 != ctx->r2) {
        // 0x8002580C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80025820;
    }
    // 0x8002580C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80025810: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80025814: sb          $v0, 0x7B9B($at)
    MEM_B(0X7B9B, ctx->r1) = ctx->r2;
    // 0x80025818: j           L_8002582C
    // 0x8002581C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8002582C;
    // 0x8002581C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80025820:
    // 0x80025820: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80025824: sb          $zero, 0x7B9B($at)
    MEM_B(0X7B9B, ctx->r1) = 0;
    // 0x80025828: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8002582C:
    // 0x8002582C: sb          $zero, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = 0;
    // 0x80025830: jal         0x80014614
    // 0x80025834: sb          $zero, 0x49($s0)
    MEM_B(0X49, ctx->r16) = 0;
    func_80014614(rdram, ctx);
        goto after_0;
    // 0x80025834: sb          $zero, 0x49($s0)
    MEM_B(0X49, ctx->r16) = 0;
    after_0:
    // 0x80025838: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002583C: sb          $v0, 0x11D($s0)
    MEM_B(0X11D, ctx->r16) = ctx->r2;
    // 0x80025840: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // 0x80025844: sh          $v0, 0x80($s0)
    MEM_H(0X80, ctx->r16) = ctx->r2;
    // 0x80025848: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x8002584C: sh          $v0, 0x82($s0)
    MEM_H(0X82, ctx->r16) = ctx->r2;
    // 0x80025850: addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // 0x80025854: sb          $zero, 0x11E($s0)
    MEM_B(0X11E, ctx->r16) = 0;
    // 0x80025858: sw          $zero, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = 0;
    // 0x8002585C: sb          $zero, 0x128($s0)
    MEM_B(0X128, ctx->r16) = 0;
    // 0x80025860: sh          $v0, 0x84($s0)
    MEM_H(0X84, ctx->r16) = ctx->r2;
    // 0x80025864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025868: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002586C: jr          $ra
    // 0x80025870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80025870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80025874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025874: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025878: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8002587C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80025880: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025884: lb          $v0, 0x128($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X128);
    // 0x80025888: bne         $v0, $zero, L_800258A0
    if (ctx->r2 != 0) {
        // 0x8002588C: nop
    
            goto L_800258A0;
    }
    // 0x8002588C: nop

    // 0x80025890: lw          $v0, 0xB8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB8);
    // 0x80025894: lw          $v1, 0xB4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB4);
    // 0x80025898: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8002589C: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_800258A0:
    // 0x800258A0: lb          $v0, 0x11E($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X11E);
    // 0x800258A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800258A8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800258AC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800258B0: lw          $v0, 0x28C0($at)
    ctx->r2 = MEM_W(ctx->r1, 0X28C0);
    // 0x800258B4: jalr        $v0
    // 0x800258B8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800258B8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800258BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800258C0: sw          $v0, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->r2;
    // 0x800258C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800258C8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800258CC: jr          $ra
    // 0x800258D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800258D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800258D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800258D4: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x800258D8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800258DC: bne         $v0, $zero, L_800258FC
    if (ctx->r2 != 0) {
        // 0x800258E0: nop
    
            goto L_800258FC;
    }
    // 0x800258E0: nop

    // 0x800258E4: lb          $v0, 0x123($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X123);
    // 0x800258E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800258EC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800258F0: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800258F4: j           L_80025910
    // 0x800258F8: lw          $a1, 0x2870($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2870);
        goto L_80025910;
    // 0x800258F8: lw          $a1, 0x2870($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2870);
L_800258FC:
    // 0x800258FC: lb          $v0, 0x123($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X123);
    // 0x80025900: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80025904: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80025908: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8002590C: lw          $a1, 0x2884($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2884);
L_80025910:
    // 0x80025910: lw          $v0, 0x12C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X12C);
    // 0x80025914: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80025918: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x8002591C: sw          $v1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r3;
    // 0x80025920: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80025924: sb          $v0, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = ctx->r2;
    // 0x80025928: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8002592C: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80025930: sra         $v1, $v0, 24
    ctx->r3 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80025934: sltiu       $v0, $v1, 0x45
    ctx->r2 = ctx->r3 < 0X45 ? 1 : 0;
    // 0x80025938: beq         $v0, $zero, L_80025A54
    if (ctx->r2 == 0) {
        // 0x8002593C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80025A54;
    }
    // 0x8002593C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80025940: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80025944: addu        $at, $at, $v0
    gpr jr_addend_8002594C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80025948: lw          $v0, -0x2B88($at)
    ctx->r2 = ADD32(ctx->r1, -0X2B88);
    // 0x8002594C: jr          $v0
    // 0x80025950: nop

    switch (jr_addend_8002594C >> 2) {
        case 0: goto L_800259B8; break;
        case 1: goto L_80025A3C; break;
        case 2: goto L_80025A3C; break;
        case 3: goto L_80025A3C; break;
        case 4: goto L_80025A54; break;
        case 5: goto L_80025A3C; break;
        case 6: goto L_80025A54; break;
        case 7: goto L_80025A54; break;
        case 8: goto L_80025A54; break;
        case 9: goto L_80025A54; break;
        case 10: goto L_80025A54; break;
        case 11: goto L_80025A54; break;
        case 12: goto L_80025A54; break;
        case 13: goto L_80025A54; break;
        case 14: goto L_80025A54; break;
        case 15: goto L_80025A54; break;
        case 16: goto L_80025A54; break;
        case 17: goto L_80025A54; break;
        case 18: goto L_80025A54; break;
        case 19: goto L_80025A54; break;
        case 20: goto L_80025A54; break;
        case 21: goto L_80025A54; break;
        case 22: goto L_80025A54; break;
        case 23: goto L_80025A54; break;
        case 24: goto L_80025A54; break;
        case 25: goto L_80025A54; break;
        case 26: goto L_80025A54; break;
        case 27: goto L_80025A54; break;
        case 28: goto L_80025A54; break;
        case 29: goto L_80025A08; break;
        case 30: goto L_80025A54; break;
        case 31: goto L_80025A54; break;
        case 32: goto L_80025A54; break;
        case 33: goto L_80025A54; break;
        case 34: goto L_80025A54; break;
        case 35: goto L_80025A54; break;
        case 36: goto L_80025A54; break;
        case 37: goto L_80025A54; break;
        case 38: goto L_80025A54; break;
        case 39: goto L_80025954; break;
        case 40: goto L_80025A54; break;
        case 41: goto L_80025A54; break;
        case 42: goto L_80025A54; break;
        case 43: goto L_80025A54; break;
        case 44: goto L_80025A3C; break;
        case 45: goto L_80025A54; break;
        case 46: goto L_80025A3C; break;
        case 47: goto L_80025A54; break;
        case 48: goto L_800259B8; break;
        case 49: goto L_80025A3C; break;
        case 50: goto L_80025A3C; break;
        case 51: goto L_80025A54; break;
        case 52: goto L_80025A08; break;
        case 53: goto L_80025A54; break;
        case 54: goto L_80025A54; break;
        case 55: goto L_80025A54; break;
        case 56: goto L_80025A54; break;
        case 57: goto L_80025A54; break;
        case 58: goto L_80025A3C; break;
        case 59: goto L_80025A3C; break;
        case 60: goto L_80025A54; break;
        case 61: goto L_80025A54; break;
        case 62: goto L_80025A54; break;
        case 63: goto L_80025A54; break;
        case 64: goto L_80025A54; break;
        case 65: goto L_80025A3C; break;
        case 66: goto L_80025A3C; break;
        case 67: goto L_80025954; break;
        case 68: goto L_80025A54; break;
        default: switch_error(__func__, 0x8002594C, 0x800AD478);
    }
    // 0x80025950: nop

L_80025954:
    // 0x80025954: lw          $v0, 0x12C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X12C);
    // 0x80025958: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8002595C: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80025960: sw          $v1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r3;
    // 0x80025964: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80025968: lw          $v0, 0x12C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X12C);
    // 0x8002596C: sb          $v1, 0x124($a0)
    MEM_B(0X124, ctx->r4) = ctx->r3;
    // 0x80025970: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80025974: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80025978: sw          $v1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r3;
    // 0x8002597C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80025980: lw          $v0, 0x12C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X12C);
    // 0x80025984: sb          $v1, 0x125($a0)
    MEM_B(0X125, ctx->r4) = ctx->r3;
    // 0x80025988: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8002598C: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80025990: sw          $v1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r3;
    // 0x80025994: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80025998: lw          $v0, 0x12C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X12C);
    // 0x8002599C: sb          $v1, 0x126($a0)
    MEM_B(0X126, ctx->r4) = ctx->r3;
    // 0x800259A0: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800259A4: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800259A8: sw          $v1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r3;
    // 0x800259AC: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800259B0: j           L_80025A54
    // 0x800259B4: sb          $v0, 0x127($a0)
    MEM_B(0X127, ctx->r4) = ctx->r2;
        goto L_80025A54;
    // 0x800259B4: sb          $v0, 0x127($a0)
    MEM_B(0X127, ctx->r4) = ctx->r2;
L_800259B8:
    // 0x800259B8: lw          $v0, 0x12C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X12C);
    // 0x800259BC: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800259C0: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800259C4: sw          $v1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r3;
    // 0x800259C8: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800259CC: lw          $v0, 0x12C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X12C);
    // 0x800259D0: sb          $v1, 0x124($a0)
    MEM_B(0X124, ctx->r4) = ctx->r3;
    // 0x800259D4: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800259D8: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800259DC: sw          $v1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r3;
    // 0x800259E0: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800259E4: lw          $v0, 0x12C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X12C);
    // 0x800259E8: sb          $v1, 0x125($a0)
    MEM_B(0X125, ctx->r4) = ctx->r3;
    // 0x800259EC: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800259F0: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800259F4: sw          $v1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r3;
    // 0x800259F8: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800259FC: sb          $v0, 0x127($a0)
    MEM_B(0X127, ctx->r4) = ctx->r2;
    // 0x80025A00: j           L_80025A54
    // 0x80025A04: sb          $v0, 0x126($a0)
    MEM_B(0X126, ctx->r4) = ctx->r2;
        goto L_80025A54;
    // 0x80025A04: sb          $v0, 0x126($a0)
    MEM_B(0X126, ctx->r4) = ctx->r2;
L_80025A08:
    // 0x80025A08: lw          $v0, 0x12C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X12C);
    // 0x80025A0C: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80025A10: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80025A14: sw          $v1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r3;
    // 0x80025A18: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80025A1C: lw          $v0, 0x12C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X12C);
    // 0x80025A20: sb          $v1, 0x124($a0)
    MEM_B(0X124, ctx->r4) = ctx->r3;
    // 0x80025A24: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80025A28: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80025A2C: sw          $v1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r3;
    // 0x80025A30: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80025A34: j           L_80025A54
    // 0x80025A38: sb          $v0, 0x125($a0)
    MEM_B(0X125, ctx->r4) = ctx->r2;
        goto L_80025A54;
    // 0x80025A38: sb          $v0, 0x125($a0)
    MEM_B(0X125, ctx->r4) = ctx->r2;
L_80025A3C:
    // 0x80025A3C: lw          $v0, 0x12C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X12C);
    // 0x80025A40: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80025A44: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80025A48: sw          $v1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r3;
    // 0x80025A4C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80025A50: sb          $v0, 0x124($a0)
    MEM_B(0X124, ctx->r4) = ctx->r2;
L_80025A54:
    // 0x80025A54: jr          $ra
    // 0x80025A58: nop

    return;
    // 0x80025A58: nop

;}
RECOMP_FUNC void func_80025A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025A5C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80025A60: lbu         $v0, 0x7B7D($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B7D);
    // 0x80025A64: bne         $v0, $zero, L_80025AF8
    if (ctx->r2 != 0) {
        // 0x80025A68: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_80025AF8;
    }
    // 0x80025A68: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80025A6C: lbu         $v0, 0x127($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X127);
    // 0x80025A70: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80025A74: sb          $v0, 0x127($a1)
    MEM_B(0X127, ctx->r5) = ctx->r2;
    // 0x80025A78: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80025A7C: bne         $v0, $zero, L_80025AF8
    if (ctx->r2 != 0) {
        // 0x80025A80: nop
    
            goto L_80025AF8;
    }
    // 0x80025A80: nop

    // 0x80025A84: lbu         $v0, 0x5($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X5);
    // 0x80025A88: lbu         $v1, 0x126($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X126);
    // 0x80025A8C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80025A90: bne         $v0, $zero, L_80025ABC
    if (ctx->r2 != 0) {
        // 0x80025A94: sb          $v1, 0x127($a1)
        MEM_B(0X127, ctx->r5) = ctx->r3;
            goto L_80025ABC;
    }
    // 0x80025A94: sb          $v1, 0x127($a1)
    MEM_B(0X127, ctx->r5) = ctx->r3;
    // 0x80025A98: lb          $v0, 0x124($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X124);
    // 0x80025A9C: lw          $a0, 0xB8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XB8);
    // 0x80025AA0: lw          $v1, 0xB4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XB4);
    // 0x80025AA4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80025AA8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80025AAC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80025AB0: lhu         $v0, 0x2898($at)
    ctx->r2 = MEM_HU(ctx->r1, 0X2898);
    // 0x80025AB4: j           L_80025ADC
    // 0x80025AB8: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
        goto L_80025ADC;
    // 0x80025AB8: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
L_80025ABC:
    // 0x80025ABC: lb          $v0, 0x124($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X124);
    // 0x80025AC0: lw          $a0, 0xB8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XB8);
    // 0x80025AC4: lw          $v1, 0xB4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XB4);
    // 0x80025AC8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80025ACC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80025AD0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80025AD4: lhu         $v0, 0x28A8($at)
    ctx->r2 = MEM_HU(ctx->r1, 0X28A8);
    // 0x80025AD8: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
L_80025ADC:
    // 0x80025ADC: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80025AE0: lbu         $v0, 0x125($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X125);
    // 0x80025AE4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80025AE8: sb          $v0, 0x125($a1)
    MEM_B(0X125, ctx->r5) = ctx->r2;
    // 0x80025AEC: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80025AF0: beql        $v0, $zero, L_80025AF8
    if (ctx->r2 == 0) {
        // 0x80025AF4: sb          $zero, 0x11E($a1)
        MEM_B(0X11E, ctx->r5) = 0;
            goto L_80025AF8;
    }
    goto skip_0;
    // 0x80025AF4: sb          $zero, 0x11E($a1)
    MEM_B(0X11E, ctx->r5) = 0;
    skip_0:
L_80025AF8:
    // 0x80025AF8: jr          $ra
    // 0x80025AFC: nop

    return;
    // 0x80025AFC: nop

;}
RECOMP_FUNC void func_80025B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025B00: lbu         $v0, 0x124($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X124);
    // 0x80025B04: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    // 0x80025B08: jr          $ra
    // 0x80025B0C: sb          $v0, 0x11C($a0)
    MEM_B(0X11C, ctx->r4) = ctx->r2;
    return;
    // 0x80025B0C: sb          $v0, 0x11C($a0)
    MEM_B(0X11C, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_80025B10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025B10: jr          $ra
    // 0x80025B14: nop

    return;
    // 0x80025B14: nop

;}
RECOMP_FUNC void func_80025B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025B18: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80025B1C: addiu       $v1, $v1, 0x7B7D
    ctx->r3 = ADD32(ctx->r3, 0X7B7D);
    // 0x80025B20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80025B24: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80025B28: lbu         $v0, 0x124($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X124);
    // 0x80025B2C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80025B30: sb          $v0, 0x124($a0)
    MEM_B(0X124, ctx->r4) = ctx->r2;
    // 0x80025B34: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80025B38: bne         $v0, $zero, L_80025B48
    if (ctx->r2 != 0) {
        // 0x80025B3C: nop
    
            goto L_80025B48;
    }
    // 0x80025B3C: nop

    // 0x80025B40: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    // 0x80025B44: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_80025B48:
    // 0x80025B48: jr          $ra
    // 0x80025B4C: nop

    return;
    // 0x80025B4C: nop

;}
RECOMP_FUNC void func_80025B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025B50: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80025B54: lbu         $v0, 0x7B88($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B88);
    // 0x80025B58: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80025B5C: addiu       $a1, $a1, 0x7B7D
    ctx->r5 = ADD32(ctx->r5, 0X7B7D);
    // 0x80025B60: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80025B64: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
    // 0x80025B68: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80025B6C: bne         $v0, $v1, L_80025B7C
    if (ctx->r2 != ctx->r3) {
        // 0x80025B70: nop
    
            goto L_80025B7C;
    }
    // 0x80025B70: nop

    // 0x80025B74: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    // 0x80025B78: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
L_80025B7C:
    // 0x80025B7C: jr          $ra
    // 0x80025B80: nop

    return;
    // 0x80025B80: nop

;}
RECOMP_FUNC void func_80025B84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025B84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80025B88: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80025B8C: sb          $v0, 0x7B7D($at)
    MEM_B(0X7B7D, ctx->r1) = ctx->r2;
    // 0x80025B90: jr          $ra
    // 0x80025B94: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    return;
    // 0x80025B94: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
;}
