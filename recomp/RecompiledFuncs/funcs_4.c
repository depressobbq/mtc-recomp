#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80012D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012D78: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // 0x80012D7C: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x80012D80: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x80012D84: jr          $ra
    // 0x80012D88: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    return;
    // 0x80012D88: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80012D8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012D8C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80012D90: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80012D94: addiu       $a1, $a1, 0x55A0
    ctx->r5 = ADD32(ctx->r5, 0X55A0);
    // 0x80012D98: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80012D9C:
    // 0x80012D9C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80012DA0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80012DA4: lb          $v0, 0x55A0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X55A0);
    // 0x80012DA8: bnel        $v0, $zero, L_80012DB8
    if (ctx->r2 != 0) {
        // 0x80012DAC: addiu       $a1, $a1, 0x38
        ctx->r5 = ADD32(ctx->r5, 0X38);
            goto L_80012DB8;
    }
    goto skip_0;
    // 0x80012DAC: addiu       $a1, $a1, 0x38
    ctx->r5 = ADD32(ctx->r5, 0X38);
    skip_0:
    // 0x80012DB0: j           L_80012DCC
    // 0x80012DB4: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
        goto L_80012DCC;
    // 0x80012DB4: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
L_80012DB8:
    // 0x80012DB8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80012DBC: slti        $v0, $a0, 0x60
    ctx->r2 = SIGNED(ctx->r4) < 0X60 ? 1 : 0;
    // 0x80012DC0: bne         $v0, $zero, L_80012D9C
    if (ctx->r2 != 0) {
        // 0x80012DC4: addiu       $v1, $v1, 0x38
        ctx->r3 = ADD32(ctx->r3, 0X38);
            goto L_80012D9C;
    }
    // 0x80012DC4: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x80012DC8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80012DCC:
    // 0x80012DCC: jr          $ra
    // 0x80012DD0: nop

    return;
    // 0x80012DD0: nop

;}
RECOMP_FUNC void func_80012DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012DD4: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // 0x80012DD8: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x80012DDC: jr          $ra
    // 0x80012DE0: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    return;
    // 0x80012DE0: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80012DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012DF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80012DF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80012DF8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80012DFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80012E00: lb          $v0, 0x50($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X50);
    // 0x80012E04: beq         $v0, $zero, L_80012E14
    if (ctx->r2 == 0) {
        // 0x80012E08: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80012E14;
    }
    // 0x80012E08: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80012E0C: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x80012E10: sb          $v0, 0x50($s0)
    MEM_B(0X50, ctx->r16) = ctx->r2;
L_80012E14:
    // 0x80012E14: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80012E18: lbu         $v0, 0x7B83($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B83);
    // 0x80012E1C: bne         $v0, $zero, L_8001316C
    if (ctx->r2 != 0) {
        // 0x80012E20: nop
    
            goto L_8001316C;
    }
    // 0x80012E20: nop

    // 0x80012E24: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80012E28: lbu         $v0, 0x7B7F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B7F);
    // 0x80012E2C: bne         $v0, $zero, L_8001316C
    if (ctx->r2 != 0) {
        // 0x80012E30: nop
    
            goto L_8001316C;
    }
    // 0x80012E30: nop

    // 0x80012E34: lb          $v0, 0x5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5);
    // 0x80012E38: bgez        $v0, L_80012F7C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80012E3C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80012F7C;
    }
    // 0x80012E3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80012E40: lb          $v1, 0x1($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1);
    // 0x80012E44: bne         $v1, $v0, L_80012F7C
    if (ctx->r3 != ctx->r2) {
        // 0x80012E48: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_80012F7C;
    }
    // 0x80012E48: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80012E4C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80012E50: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x80012E54: beq         $v1, $v0, L_80012E74
    if (ctx->r3 == ctx->r2) {
        // 0x80012E58: nop
    
            goto L_80012E74;
    }
    // 0x80012E58: nop

    // 0x80012E5C: lw          $v0, 0xB4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB4);
    // 0x80012E60: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80012E64: lw          $v0, 0xB8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB8);
    // 0x80012E68: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80012E6C: jal         0x80017064
    // 0x80012E70: lw          $a0, 0xD0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XD0);
    func_80017064(rdram, ctx);
        goto after_0;
    // 0x80012E70: lw          $a0, 0xD0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XD0);
    after_0:
L_80012E74:
    // 0x80012E74: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80012E78: lbu         $v0, 0x2074($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2074);
    // 0x80012E7C: beq         $v0, $zero, L_80012F0C
    if (ctx->r2 == 0) {
        // 0x80012E80: nop
    
            goto L_80012F0C;
    }
    // 0x80012E80: nop

    // 0x80012E84: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80012E88: lbu         $v1, 0x75($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X75);
    // 0x80012E8C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80012E90: bne         $v1, $v0, L_80012EB4
    if (ctx->r3 != ctx->r2) {
        // 0x80012E94: nop
    
            goto L_80012EB4;
    }
    // 0x80012E94: nop

    // 0x80012E98: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80012E9C: lbu         $v0, 0x7B9A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9A);
    // 0x80012EA0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80012EA4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012EA8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80012EAC: j           L_80012F24
    // 0x80012EB0: lw          $v0, 0x1590($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1590);
        goto L_80012F24;
    // 0x80012EB0: lw          $v0, 0x1590($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1590);
L_80012EB4:
    // 0x80012EB4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80012EB8: lbu         $v0, 0x2076($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2076);
    // 0x80012EBC: bne         $v0, $zero, L_80012EE0
    if (ctx->r2 != 0) {
        // 0x80012EC0: nop
    
            goto L_80012EE0;
    }
    // 0x80012EC0: nop

    // 0x80012EC4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80012EC8: lbu         $v0, 0x7B9A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9A);
    // 0x80012ECC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80012ED0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012ED4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80012ED8: j           L_80012F24
    // 0x80012EDC: lw          $v0, 0x15AC($at)
    ctx->r2 = MEM_W(ctx->r1, 0X15AC);
        goto L_80012F24;
    // 0x80012EDC: lw          $v0, 0x15AC($at)
    ctx->r2 = MEM_W(ctx->r1, 0X15AC);
L_80012EE0:
    // 0x80012EE0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80012EE4: lbu         $v0, 0x7BAA($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7BAA);
    // 0x80012EE8: beq         $v0, $zero, L_80012F0C
    if (ctx->r2 == 0) {
        // 0x80012EEC: nop
    
            goto L_80012F0C;
    }
    // 0x80012EEC: nop

    // 0x80012EF0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80012EF4: lbu         $v0, 0x7B9A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9A);
    // 0x80012EF8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80012EFC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012F00: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80012F04: j           L_80012F24
    // 0x80012F08: lw          $v0, 0x1590($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1590);
        goto L_80012F24;
    // 0x80012F08: lw          $v0, 0x1590($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1590);
L_80012F0C:
    // 0x80012F0C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80012F10: lbu         $v0, 0x7B9A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9A);
    // 0x80012F14: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80012F18: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80012F1C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80012F20: lw          $v0, 0x1574($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1574);
L_80012F24:
    // 0x80012F24: jalr        $v0
    // 0x80012F28: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x80012F28: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80012F2C: lb          $v0, 0x5C($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5C);
    // 0x80012F30: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80012F34: addiu       $a0, $a0, -0x3F2C
    ctx->r4 = ADD32(ctx->r4, -0X3F2C);
    // 0x80012F38: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80012F3C: lhu         $v1, 0x7BC0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X7BC0);
    // 0x80012F40: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80012F44: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80012F48: andi        $v1, $v1, 0x1F
    ctx->r3 = ctx->r3 & 0X1F;
    // 0x80012F4C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80012F50: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x80012F54: bne         $v0, $zero, L_80012F7C
    if (ctx->r2 != 0) {
        // 0x80012F58: addiu       $a0, $zero, 0x400
        ctx->r4 = ADD32(0, 0X400);
            goto L_80012F7C;
    }
    // 0x80012F58: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x80012F5C: lw          $v1, 0xB4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB4);
    // 0x80012F60: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80012F64: beql        $v0, $a0, L_80012F6C
    if (ctx->r2 == ctx->r4) {
        // 0x80012F68: sh          $zero, 0x0($v1)
        MEM_H(0X0, ctx->r3) = 0;
            goto L_80012F6C;
    }
    goto skip_0;
    // 0x80012F68: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    skip_0:
L_80012F6C:
    // 0x80012F6C: lw          $v1, 0xB8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB8);
    // 0x80012F70: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80012F74: beql        $v0, $a0, L_80012F7C
    if (ctx->r2 == ctx->r4) {
        // 0x80012F78: sh          $zero, 0x0($v1)
        MEM_H(0X0, ctx->r3) = 0;
            goto L_80012F7C;
    }
    goto skip_1;
    // 0x80012F78: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    skip_1:
L_80012F7C:
    // 0x80012F7C: lb          $v1, 0x5A($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X5A);
    // 0x80012F80: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80012F84: beq         $v1, $v0, L_80012F94
    if (ctx->r3 == ctx->r2) {
        // 0x80012F88: nop
    
            goto L_80012F94;
    }
    // 0x80012F88: nop

    // 0x80012F8C: jal         0x80016A10
    // 0x80012F90: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80016A10(rdram, ctx);
        goto after_2;
    // 0x80012F90: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
L_80012F94:
    // 0x80012F94: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80012F98: lbu         $v0, 0x7B7D($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B7D);
    // 0x80012F9C: bne         $v0, $zero, L_8001316C
    if (ctx->r2 != 0) {
        // 0x80012FA0: nop
    
            goto L_8001316C;
    }
    // 0x80012FA0: nop

    // 0x80012FA4: lw          $v0, 0xB8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB8);
    // 0x80012FA8: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80012FAC: andi        $v0, $v0, 0x300
    ctx->r2 = ctx->r2 & 0X300;
    // 0x80012FB0: beql        $v0, $zero, L_80012FC4
    if (ctx->r2 == 0) {
        // 0x80012FB4: sw          $zero, 0x30($s0)
        MEM_W(0X30, ctx->r16) = 0;
            goto L_80012FC4;
    }
    goto skip_2;
    // 0x80012FB4: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    skip_2:
    // 0x80012FB8: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x80012FBC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80012FC0: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
L_80012FC4:
    // 0x80012FC4: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x80012FC8: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80012FCC: bne         $v0, $zero, L_80012FDC
    if (ctx->r2 != 0) {
        // 0x80012FD0: nop
    
            goto L_80012FDC;
    }
    // 0x80012FD0: nop

    // 0x80012FD4: j           L_80012FE0
    // 0x80012FD8: lw          $v0, 0xB8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB8);
        goto L_80012FE0;
    // 0x80012FD8: lw          $v0, 0xB8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB8);
L_80012FDC:
    // 0x80012FDC: lw          $v0, 0xB4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB4);
L_80012FE0:
    // 0x80012FE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80012FE4: sw          $v0, 0x47FC($at)
    MEM_W(0X47FC, ctx->r1) = ctx->r2;
    // 0x80012FE8: lb          $v0, 0x5A($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5A);
    // 0x80012FEC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80012FF0: beq         $v0, $a0, L_8001300C
    if (ctx->r2 == ctx->r4) {
        // 0x80012FF4: nop
    
            goto L_8001300C;
    }
    // 0x80012FF4: nop

    // 0x80012FF8: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80012FFC: lb          $v1, 0x2($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X2);
    // 0x80013000: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80013004: beq         $v1, $v0, L_8001316C
    if (ctx->r3 == ctx->r2) {
        // 0x80013008: nop
    
            goto L_8001316C;
    }
    // 0x80013008: nop

L_8001300C:
    // 0x8001300C: lw          $v0, 0xB4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB4);
    // 0x80013010: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80013014: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x80013018: beq         $v0, $zero, L_8001302C
    if (ctx->r2 == 0) {
        // 0x8001301C: nop
    
            goto L_8001302C;
    }
    // 0x8001301C: nop

    // 0x80013020: lbu         $v0, 0x69($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X69);
    // 0x80013024: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80013028: sb          $v0, 0x69($s0)
    MEM_B(0X69, ctx->r16) = ctx->r2;
L_8001302C:
    // 0x8001302C: lb          $v0, 0x5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5);
    // 0x80013030: bltz        $v0, L_80013074
    if (SIGNED(ctx->r2) < 0) {
        // 0x80013034: nop
    
            goto L_80013074;
    }
    // 0x80013034: nop

    // 0x80013038: lb          $v0, 0x5A($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5A);
    // 0x8001303C: bne         $v0, $a0, L_80013074
    if (ctx->r2 != ctx->r4) {
        // 0x80013040: ori         $v1, $zero, 0xC000
        ctx->r3 = 0 | 0XC000;
            goto L_80013074;
    }
    // 0x80013040: ori         $v1, $zero, 0xC000
    ctx->r3 = 0 | 0XC000;
    // 0x80013044: lw          $v0, 0xB4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB4);
    // 0x80013048: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8001304C: andi        $v0, $v0, 0xC000
    ctx->r2 = ctx->r2 & 0XC000;
    // 0x80013050: bne         $v0, $v1, L_80013074
    if (ctx->r2 != ctx->r3) {
        // 0x80013054: nop
    
            goto L_80013074;
    }
    // 0x80013054: nop

    // 0x80013058: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x8001305C: lb          $v1, 0x4A($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X4A);
    // 0x80013060: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80013064: sb          $v1, 0x4A($v0)
    MEM_B(0X4A, ctx->r2) = ctx->r3;
    // 0x80013068: lb          $v0, 0x62($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X62);
    // 0x8001306C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80013070: sb          $v0, 0x62($s0)
    MEM_B(0X62, ctx->r16) = ctx->r2;
L_80013074:
    // 0x80013074: jal         0x80016E1C
    // 0x80013078: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80016E1C(rdram, ctx);
        goto after_3;
    // 0x80013078: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8001307C: lb          $v0, 0x5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5);
    // 0x80013080: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80013084: bne         $v0, $zero, L_80013150
    if (ctx->r2 != 0) {
        // 0x80013088: lui         $a1, 0x8888
        ctx->r5 = S32(0X8888 << 16);
            goto L_80013150;
    }
    // 0x80013088: lui         $a1, 0x8888
    ctx->r5 = S32(0X8888 << 16);
    // 0x8001308C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80013090: lbu         $a0, 0x7B82($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B82);
    // 0x80013094: ori         $a1, $a1, 0x8889
    ctx->r5 = ctx->r5 | 0X8889;
    // 0x80013098: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001309C: lbu         $v1, 0x7B81($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B81);
    // 0x800130A0: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x800130A4: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800130A8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800130AC: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x800130B0: mult        $a0, $a1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800130B4: sra         $a1, $a0, 31
    ctx->r5 = S32(SIGNED(ctx->r4) >> 31);
    // 0x800130B8: mfhi        $a2
    ctx->r6 = hi;
    // 0x800130BC: addu        $v0, $a2, $a0
    ctx->r2 = ADD32(ctx->r6, ctx->r4);
    // 0x800130C0: sra         $v0, $v0, 5
    ctx->r2 = S32(SIGNED(ctx->r2) >> 5);
    // 0x800130C4: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x800130C8: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800130CC: bne         $v0, $zero, L_80013150
    if (ctx->r2 != 0) {
        // 0x800130D0: lui         $v0, 0x6666
        ctx->r2 = S32(0X6666 << 16);
            goto L_80013150;
    }
    // 0x800130D0: lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // 0x800130D4: ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // 0x800130D8: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800130DC: mfhi        $a2
    ctx->r6 = hi;
    // 0x800130E0: sra         $v1, $a2, 3
    ctx->r3 = S32(SIGNED(ctx->r6) >> 3);
    // 0x800130E4: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x800130E8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800130EC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800130F0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800130F4: bne         $a0, $v0, L_80013150
    if (ctx->r4 != ctx->r2) {
        // 0x800130F8: nop
    
            goto L_80013150;
    }
    // 0x800130F8: nop

    // 0x800130FC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80013100: lbu         $v0, 0x7B80($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B80);
    // 0x80013104: bne         $v0, $zero, L_80013150
    if (ctx->r2 != 0) {
        // 0x80013108: nop
    
            goto L_80013150;
    }
    // 0x80013108: nop

    // 0x8001310C: jal         0x80016068
    // 0x80013110: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80016068(rdram, ctx);
        goto after_4;
    // 0x80013110: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x80013114: lbu         $a0, 0x74($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X74);
    // 0x80013118: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001311C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80013120: lb          $v1, -0x39F4($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X39F4);
    // 0x80013124: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80013128: beq         $v0, $zero, L_80013150
    if (ctx->r2 == 0) {
        // 0x8001312C: nop
    
            goto L_80013150;
    }
    // 0x8001312C: nop

    // 0x80013130: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80013134: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80013138: lbu         $v0, -0x3AC8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3AC8);
    // 0x8001313C: lhu         $v1, 0x7C($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X7C);
    // 0x80013140: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80013144: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80013148: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001314C: sh          $v1, 0x7C($s0)
    MEM_H(0X7C, ctx->r16) = ctx->r3;
L_80013150:
    // 0x80013150: lb          $v0, 0x2($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X2);
    // 0x80013154: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80013158: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001315C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80013160: lw          $v0, 0x1554($at)
    ctx->r2 = MEM_W(ctx->r1, 0X1554);
    // 0x80013164: jalr        $v0
    // 0x80013168: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_5;
    // 0x80013168: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
L_8001316C:
    // 0x8001316C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80013170: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80013174: jr          $ra
    // 0x80013178: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80013178: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8001317C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001317C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80013180: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80013184: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80013188: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001318C: lb          $v0, 0x3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X3);
    // 0x80013190: bne         $v0, $zero, L_800131D8
    if (ctx->r2 != 0) {
        // 0x80013194: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800131D8;
    }
    // 0x80013194: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80013198: jal         0x80016AB4
    // 0x8001319C: nop

    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x8001319C: nop

    after_0:
    // 0x800131A0: lb          $v1, 0x5A($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X5A);
    // 0x800131A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800131A8: bne         $v1, $v0, L_80013214
    if (ctx->r3 != ctx->r2) {
        // 0x800131AC: nop
    
            goto L_80013214;
    }
    // 0x800131AC: nop

    // 0x800131B0: lb          $v0, 0x5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5);
    // 0x800131B4: bgez        $v0, L_80013214
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800131B8: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80013214;
    }
    // 0x800131B8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800131BC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800131C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800131C4: jal         0x8001770C
    // 0x800131C8: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    func_8001770C(rdram, ctx);
        goto after_1;
    // 0x800131C8: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    after_1:
    // 0x800131CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800131D0: j           L_80013214
    // 0x800131D4: sb          $v0, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = ctx->r2;
        goto L_80013214;
    // 0x800131D4: sb          $v0, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = ctx->r2;
L_800131D8:
    // 0x800131D8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800131DC: lbu         $v1, 0x7B71($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B71);
    // 0x800131E0: bne         $v1, $v0, L_80013214
    if (ctx->r3 != ctx->r2) {
        // 0x800131E4: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_80013214;
    }
    // 0x800131E4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800131E8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800131EC: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x800131F0: beq         $v1, $v0, L_80013200
    if (ctx->r3 == ctx->r2) {
        // 0x800131F4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80013200;
    }
    // 0x800131F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800131F8: sb          $v0, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = ctx->r2;
    // 0x800131FC: sb          $v0, 0x49($s0)
    MEM_B(0X49, ctx->r16) = ctx->r2;
L_80013200:
    // 0x80013200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80013204: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x80013208: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x8001320C: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x80013210: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
L_80013214:
    // 0x80013214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013218: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001321C: jr          $ra
    // 0x80013220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80013220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80013224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013224: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80013228: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001322C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80013230: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80013234: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80013238: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x8001323C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80013240: lw          $a0, 0x47FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X47FC);
    // 0x80013244: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x80013248: sw          $v1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r3;
    // 0x8001324C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80013250: andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // 0x80013254: beq         $v0, $zero, L_80013268
    if (ctx->r2 == 0) {
        // 0x80013258: nop
    
            goto L_80013268;
    }
    // 0x80013258: nop

    // 0x8001325C: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80013260: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80013264: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
L_80013268:
    // 0x80013268: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8001326C: lw          $v0, 0x47FC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X47FC);
    // 0x80013270: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80013274: andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // 0x80013278: beq         $v0, $zero, L_8001328C
    if (ctx->r2 == 0) {
        // 0x8001327C: nop
    
            goto L_8001328C;
    }
    // 0x8001327C: nop

    // 0x80013280: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80013284: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80013288: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
L_8001328C:
    // 0x8001328C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80013290: lw          $v0, 0x47FC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X47FC);
    // 0x80013294: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80013298: andi        $v0, $v0, 0x300
    ctx->r2 = ctx->r2 & 0X300;
    // 0x8001329C: beq         $v0, $zero, L_800132DC
    if (ctx->r2 == 0) {
        // 0x800132A0: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800132DC;
    }
    // 0x800132A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800132A4: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800132A8: jal         0x800151FC
    // 0x800132AC: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    func_800151FC(rdram, ctx);
        goto after_0;
    // 0x800132AC: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    after_0:
    // 0x800132B0: beq         $v0, $zero, L_800132DC
    if (ctx->r2 == 0) {
        // 0x800132B4: nop
    
            goto L_800132DC;
    }
    // 0x800132B4: nop

    // 0x800132B8: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x800132BC: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x800132C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800132C4: lw          $a0, 0x47FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X47FC);
    // 0x800132C8: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x800132CC: sw          $v1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r3;
    // 0x800132D0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800132D4: andi        $v0, $v0, 0x300
    ctx->r2 = ctx->r2 & 0X300;
    // 0x800132D8: sw          $v0, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->r2;
L_800132DC:
    // 0x800132DC: lw          $v0, 0xB8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB8);
    // 0x800132E0: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800132E4: andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // 0x800132E8: beq         $v0, $zero, L_80013330
    if (ctx->r2 == 0) {
        // 0x800132EC: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80013330;
    }
    // 0x800132EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800132F0: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x800132F4: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800132F8: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    // 0x800132FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80013300: jal         0x800151FC
    // 0x80013304: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    func_800151FC(rdram, ctx);
        goto after_1;
    // 0x80013304: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    after_1:
    // 0x80013308: beq         $v0, $zero, L_80013324
    if (ctx->r2 == 0) {
        // 0x8001330C: nop
    
            goto L_80013324;
    }
    // 0x8001330C: nop

    // 0x80013310: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x80013314: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x80013318: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x8001331C: j           L_80013330
    // 0x80013320: sw          $v1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r3;
        goto L_80013330;
    // 0x80013320: sw          $v1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r3;
L_80013324:
    // 0x80013324: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80013328: sb          $zero, 0x52($s0)
    MEM_B(0X52, ctx->r16) = 0;
    // 0x8001332C: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
L_80013330:
    // 0x80013330: jal         0x80013818
    // 0x80013334: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80013818(rdram, ctx);
        goto after_2;
    // 0x80013334: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80013338: beq         $v0, $zero, L_80013384
    if (ctx->r2 == 0) {
        // 0x8001333C: nop
    
            goto L_80013384;
    }
    // 0x8001333C: nop

L_80013340:
    // 0x80013340: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80013344: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80013348: jal         0x800151FC
    // 0x8001334C: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    func_800151FC(rdram, ctx);
        goto after_3;
    // 0x8001334C: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    after_3:
    // 0x80013350: bne         $v0, $zero, L_80013368
    if (ctx->r2 != 0) {
        // 0x80013354: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80013368;
    }
    // 0x80013354: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80013358: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x8001335C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80013360: j           L_80013340
    // 0x80013364: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
        goto L_80013340;
    // 0x80013364: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
L_80013368:
    // 0x80013368: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x8001336C: sw          $v1, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r3;
    // 0x80013370: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80013374: sb          $zero, 0x52($s0)
    MEM_B(0X52, ctx->r16) = 0;
    // 0x80013378: sb          $v1, 0x76($s0)
    MEM_B(0X76, ctx->r16) = ctx->r3;
    // 0x8001337C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80013380: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
L_80013384:
    // 0x80013384: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80013388: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x8001338C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80013390: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x80013394: jal         0x80015450
    // 0x80013398: sw          $v1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r3;
    func_80015450(rdram, ctx);
        goto after_4;
    // 0x80013398: sw          $v1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r3;
    after_4:
    // 0x8001339C: beq         $v0, $zero, L_800133C8
    if (ctx->r2 == 0) {
        // 0x800133A0: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800133C8;
    }
    // 0x800133A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800133A4: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800133A8: jal         0x800151FC
    // 0x800133AC: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    func_800151FC(rdram, ctx);
        goto after_5;
    // 0x800133AC: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    after_5:
    // 0x800133B0: beq         $v0, $zero, L_800133C8
    if (ctx->r2 == 0) {
        // 0x800133B4: nop
    
            goto L_800133C8;
    }
    // 0x800133B4: nop

    // 0x800133B8: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x800133BC: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x800133C0: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x800133C4: sw          $v1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r3;
L_800133C8:
    // 0x800133C8: lbu         $v0, 0x4C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4C);
    // 0x800133CC: lw          $a1, 0xB8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB8);
    // 0x800133D0: lw          $v1, 0xB4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB4);
    // 0x800133D4: lhu         $a0, 0x84($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X84);
    // 0x800133D8: sb          $v0, 0x4D($s0)
    MEM_B(0X4D, ctx->r16) = ctx->r2;
    // 0x800133DC: lhu         $v0, 0x82($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X82);
    // 0x800133E0: lhu         $a1, 0x0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X0);
    // 0x800133E4: lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X0);
    // 0x800133E8: or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    // 0x800133EC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800133F0: beq         $v0, $zero, L_80013410
    if (ctx->r2 == 0) {
        // 0x800133F4: and         $a1, $a1, $a0
        ctx->r5 = ctx->r5 & ctx->r4;
            goto L_80013410;
    }
    // 0x800133F4: and         $a1, $a1, $a0
    ctx->r5 = ctx->r5 & ctx->r4;
    // 0x800133F8: beq         $a1, $a0, L_80013410
    if (ctx->r5 == ctx->r4) {
        // 0x800133FC: nop
    
            goto L_80013410;
    }
    // 0x800133FC: nop

    // 0x80013400: lbu         $v0, 0x4C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4C);
    // 0x80013404: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80013408: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8001340C: sb          $v0, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r2;
L_80013410:
    // 0x80013410: lw          $v0, 0xB4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB4);
    // 0x80013414: lhu         $v1, 0x84($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X84);
    // 0x80013418: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x8001341C: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x80013420: beq         $v0, $zero, L_80013448
    if (ctx->r2 == 0) {
        // 0x80013424: nop
    
            goto L_80013448;
    }
    // 0x80013424: nop

    // 0x80013428: lhu         $v0, 0x82($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X82);
    // 0x8001342C: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80013430: beq         $a1, $v0, L_80013448
    if (ctx->r5 == ctx->r2) {
        // 0x80013434: nop
    
            goto L_80013448;
    }
    // 0x80013434: nop

    // 0x80013438: lbu         $v0, 0x4C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4C);
    // 0x8001343C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80013440: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x80013444: sb          $v0, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r2;
L_80013448:
    // 0x80013448: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x8001344C: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x80013450: lhu         $a0, 0x82($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X82);
    // 0x80013454: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x80013458: lw          $v0, 0xB4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB4);
    // 0x8001345C: sw          $v1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r3;
    // 0x80013460: lhu         $v1, 0x84($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X84);
    // 0x80013464: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80013468: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x8001346C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80013470: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x80013474: beq         $v0, $zero, L_800136A4
    if (ctx->r2 == 0) {
        // 0x80013478: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_800136A4;
    }
    // 0x80013478: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001347C: beq         $a1, $a0, L_800136A4
    if (ctx->r5 == ctx->r4) {
        // 0x80013480: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800136A4;
    }
    // 0x80013480: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80013484: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x80013488: jal         0x8000637C
    // 0x8001348C: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_6;
    // 0x8001348C: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_6:
    // 0x80013490: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80013494: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80013498: jal         0x800151FC
    // 0x8001349C: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    func_800151FC(rdram, ctx);
        goto after_7;
    // 0x8001349C: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    after_7:
    // 0x800134A0: beq         $v0, $zero, L_800136A4
    if (ctx->r2 == 0) {
        // 0x800134A4: addiu       $v0, $zero, -0x3
        ctx->r2 = ADD32(0, -0X3);
            goto L_800136A4;
    }
    // 0x800134A4: addiu       $v0, $zero, -0x3
    ctx->r2 = ADD32(0, -0X3);
    // 0x800134A8: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x800134AC: bne         $v1, $v0, L_800134CC
    if (ctx->r3 != ctx->r2) {
        // 0x800134B0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800134CC;
    }
    // 0x800134B0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800134B4: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x800134B8: bnel        $v0, $zero, L_800134CC
    if (ctx->r2 != 0) {
        // 0x800134BC: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800134CC;
    }
    goto skip_0;
    // 0x800134BC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_0:
    // 0x800134C0: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x800134C4: j           L_80013668
    // 0x800134C8: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
        goto L_80013668;
    // 0x800134C8: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_800134CC:
    // 0x800134CC: bne         $v1, $v0, L_800134EC
    if (ctx->r3 != ctx->r2) {
        // 0x800134D0: nop
    
            goto L_800134EC;
    }
    // 0x800134D0: nop

    // 0x800134D4: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x800134D8: bne         $v0, $zero, L_800134EC
    if (ctx->r2 != 0) {
        // 0x800134DC: nop
    
            goto L_800134EC;
    }
    // 0x800134DC: nop

    // 0x800134E0: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x800134E4: j           L_80013668
    // 0x800134E8: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
        goto L_80013668;
    // 0x800134E8: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
L_800134EC:
    // 0x800134EC: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x800134F0: bne         $v0, $zero, L_80013514
    if (ctx->r2 != 0) {
        // 0x800134F4: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80013514;
    }
    // 0x800134F4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800134F8: lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X14);
    // 0x800134FC: bne         $v1, $v0, L_80013514
    if (ctx->r3 != ctx->r2) {
        // 0x80013500: nop
    
            goto L_80013514;
    }
    // 0x80013500: nop

    // 0x80013504: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x80013508: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8001350C: j           L_8001366C
    // 0x80013510: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
        goto L_8001366C;
    // 0x80013510: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
L_80013514:
    // 0x80013514: lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10);
    // 0x80013518: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x8001351C: bgez        $a0, L_80013528
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80013520: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80013528;
    }
    // 0x80013520: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80013524: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_80013528:
    // 0x80013528: bltzl       $v0, L_80013530
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001352C: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_80013530;
    }
    goto skip_1;
    // 0x8001352C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_1:
L_80013530:
    // 0x80013530: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80013534: beq         $v0, $zero, L_80013558
    if (ctx->r2 == 0) {
        // 0x80013538: nop
    
            goto L_80013558;
    }
    // 0x80013538: nop

    // 0x8001353C: blez        $a0, L_80013550
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80013540: nop
    
            goto L_80013550;
    }
    // 0x80013540: nop

    // 0x80013544: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80013548: j           L_80013668
    // 0x8001354C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80013668;
    // 0x8001354C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80013550:
    // 0x80013550: bltz        $a0, L_80013660
    if (SIGNED(ctx->r4) < 0) {
        // 0x80013554: nop
    
            goto L_80013660;
    }
    // 0x80013554: nop

L_80013558:
    // 0x80013558: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x8001355C: lw          $a0, 0x14($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X14);
    // 0x80013560: bltzl       $v0, L_80013568
    if (SIGNED(ctx->r2) < 0) {
        // 0x80013564: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_80013568;
    }
    goto skip_2;
    // 0x80013564: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_2:
L_80013568:
    // 0x80013568: bgez        $a0, L_80013574
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8001356C: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_80013574;
    }
    // 0x8001356C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80013570: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_80013574:
    // 0x80013574: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80013578: beq         $v0, $zero, L_800135B0
    if (ctx->r2 == 0) {
        // 0x8001357C: nop
    
            goto L_800135B0;
    }
    // 0x8001357C: nop

    // 0x80013580: blez        $a0, L_80013598
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80013584: nop
    
            goto L_80013598;
    }
    // 0x80013584: nop

    // 0x80013588: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x8001358C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80013590: j           L_8001366C
    // 0x80013594: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
        goto L_8001366C;
    // 0x80013594: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
L_80013598:
    // 0x80013598: bgez        $a0, L_800135B0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8001359C: nop
    
            goto L_800135B0;
    }
    // 0x8001359C: nop

    // 0x800135A0: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x800135A4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800135A8: j           L_8001366C
    // 0x800135AC: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
        goto L_8001366C;
    // 0x800135AC: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
L_800135B0:
    // 0x800135B0: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x800135B4: lw          $a0, 0x14($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X14);
    // 0x800135B8: bltzl       $v0, L_800135C0
    if (SIGNED(ctx->r2) < 0) {
        // 0x800135BC: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_800135C0;
    }
    goto skip_3;
    // 0x800135BC: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_3:
L_800135C0:
    // 0x800135C0: bgez        $a0, L_800135CC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800135C4: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_800135CC;
    }
    // 0x800135C4: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x800135C8: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_800135CC:
    // 0x800135CC: bnel        $v0, $v1, L_80013670
    if (ctx->r2 != ctx->r3) {
        // 0x800135D0: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80013670;
    }
    goto skip_4;
    // 0x800135D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    skip_4:
    // 0x800135D4: bltz        $a0, L_80013624
    if (SIGNED(ctx->r4) < 0) {
        // 0x800135D8: nop
    
            goto L_80013624;
    }
    // 0x800135D8: nop

    // 0x800135DC: lw          $v0, 0xB4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB4);
    // 0x800135E0: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800135E4: lhu         $v0, 0x82($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X82);
    // 0x800135E8: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x800135EC: beq         $v0, $zero, L_80013600
    if (ctx->r2 == 0) {
        // 0x800135F0: nop
    
            goto L_80013600;
    }
    // 0x800135F0: nop

    // 0x800135F4: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x800135F8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800135FC: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
L_80013600:
    // 0x80013600: lw          $v0, 0xB4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB4);
    // 0x80013604: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x80013608: lhu         $v0, 0x84($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X84);
    // 0x8001360C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80013610: beq         $v0, $zero, L_80013670
    if (ctx->r2 == 0) {
        // 0x80013614: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80013670;
    }
    // 0x80013614: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80013618: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x8001361C: j           L_80013668
    // 0x80013620: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80013668;
    // 0x80013620: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80013624:
    // 0x80013624: lw          $v0, 0xB4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB4);
    // 0x80013628: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8001362C: lhu         $v0, 0x82($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X82);
    // 0x80013630: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80013634: beq         $v0, $zero, L_80013648
    if (ctx->r2 == 0) {
        // 0x80013638: nop
    
            goto L_80013648;
    }
    // 0x80013638: nop

    // 0x8001363C: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80013640: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80013644: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
L_80013648:
    // 0x80013648: lw          $v0, 0xB4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB4);
    // 0x8001364C: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x80013650: lhu         $v0, 0x84($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X84);
    // 0x80013654: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80013658: beq         $v0, $zero, L_80013670
    if (ctx->r2 == 0) {
        // 0x8001365C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80013670;
    }
    // 0x8001365C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80013660:
    // 0x80013660: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80013664: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80013668:
    // 0x80013668: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
L_8001366C:
    // 0x8001366C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80013670:
    // 0x80013670: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80013674: addiu       $a2, $sp, 0x14
    ctx->r6 = ADD32(ctx->r29, 0X14);
    // 0x80013678: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8001367C: jal         0x800151FC
    // 0x80013680: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800151FC(rdram, ctx);
        goto after_8;
    // 0x80013680: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x80013684: beq         $v0, $zero, L_800136A4
    if (ctx->r2 == 0) {
        // 0x80013688: nop
    
            goto L_800136A4;
    }
    // 0x80013688: nop

    // 0x8001368C: lbu         $v0, 0x4D($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4D);
    // 0x80013690: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x80013694: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80013698: sb          $v0, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r2;
    // 0x8001369C: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // 0x800136A0: sw          $a0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r4;
L_800136A4:
    // 0x800136A4: lb          $v0, 0x52($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X52);
    // 0x800136A8: bnel        $v0, $zero, L_80013808
    if (ctx->r2 != 0) {
        // 0x800136AC: sw          $zero, 0x44($s0)
        MEM_W(0X44, ctx->r16) = 0;
            goto L_80013808;
    }
    goto skip_5;
    // 0x800136AC: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    skip_5:
    // 0x800136B0: jal         0x80015354
    // 0x800136B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80015354(rdram, ctx);
        goto after_9;
    // 0x800136B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_9:
    // 0x800136B8: beql        $v0, $zero, L_80013808
    if (ctx->r2 == 0) {
        // 0x800136BC: sw          $zero, 0x44($s0)
        MEM_W(0X44, ctx->r16) = 0;
            goto L_80013808;
    }
    goto skip_6;
    // 0x800136BC: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    skip_6:
    // 0x800136C0: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x800136C4: bne         $v0, $zero, L_800136FC
    if (ctx->r2 != 0) {
        // 0x800136C8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800136FC;
    }
    // 0x800136C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800136CC: lw          $v1, 0xDC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XDC);
    // 0x800136D0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800136D4: addiu       $v0, $v0, -0x33F4
    ctx->r2 = ADD32(ctx->r2, -0X33F4);
    // 0x800136D8: bne         $v1, $v0, L_800136EC
    if (ctx->r3 != ctx->r2) {
        // 0x800136DC: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_800136EC;
    }
    // 0x800136DC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800136E0: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x800136E4: j           L_800136F0
    // 0x800136E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800136F0;
    // 0x800136E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800136EC:
    // 0x800136EC: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
L_800136F0:
    // 0x800136F0: jal         0x8000637C
    // 0x800136F4: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_10;
    // 0x800136F4: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_10:
    // 0x800136F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800136FC:
    // 0x800136FC: sw          $v0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r2;
    // 0x80013700: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x80013704: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x80013708: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x8001370C: lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X40);
    // 0x80013710: bgtz        $v0, L_80013808
    if (SIGNED(ctx->r2) > 0) {
        // 0x80013714: addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
            goto L_80013808;
    }
    // 0x80013714: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80013718: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x8001371C: jal         0x8000637C
    // 0x80013720: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_11;
    // 0x80013720: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_11:
    // 0x80013724: jal         0x80015490
    // 0x80013728: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80015490(rdram, ctx);
        goto after_12;
    // 0x80013728: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_12:
    // 0x8001372C: lbu         $v1, 0x74($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X74);
    // 0x80013730: lb          $v0, 0x4F($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X4F);
    // 0x80013734: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80013738: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8001373C: lb          $v1, -0x3AC8($at)
    ctx->r3 = MEM_B(ctx->r1, -0X3AC8);
    // 0x80013740: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80013744: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80013748: mflo        $v1
    ctx->r3 = lo;
    // 0x8001374C: lhu         $v0, 0x7C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7C);
    // 0x80013750: slt         $v1, $v0, $v1
    ctx->r3 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80013754: beq         $v1, $zero, L_80013760
    if (ctx->r3 == 0) {
        // 0x80013758: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80013760;
    }
    // 0x80013758: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001375C: sh          $v0, 0x7C($s0)
    MEM_H(0X7C, ctx->r16) = ctx->r2;
L_80013760:
    // 0x80013760: lhu         $v0, 0x90($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X90);
    // 0x80013764: lbu         $v1, 0x76($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X76);
    // 0x80013768: sb          $zero, 0x49($s0)
    MEM_B(0X49, ctx->r16) = 0;
    // 0x8001376C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80013770: bne         $v1, $zero, L_8001379C
    if (ctx->r3 != 0) {
        // 0x80013774: sh          $v0, 0x90($s0)
        MEM_H(0X90, ctx->r16) = ctx->r2;
            goto L_8001379C;
    }
    // 0x80013774: sh          $v0, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r2;
    // 0x80013778: lhu         $v0, 0x8C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8C);
    // 0x8001377C: addiu       $v0, $v0, -0x3
    ctx->r2 = ADD32(ctx->r2, -0X3);
    // 0x80013780: sh          $v0, 0x8C($s0)
    MEM_H(0X8C, ctx->r16) = ctx->r2;
    // 0x80013784: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80013788: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001378C: slti        $v0, $v0, -0x2710
    ctx->r2 = SIGNED(ctx->r2) < -0X2710 ? 1 : 0;
    // 0x80013790: beq         $v0, $zero, L_8001379C
    if (ctx->r2 == 0) {
        // 0x80013794: addiu       $v0, $zero, -0x2710
        ctx->r2 = ADD32(0, -0X2710);
            goto L_8001379C;
    }
    // 0x80013794: addiu       $v0, $zero, -0x2710
    ctx->r2 = ADD32(0, -0X2710);
    // 0x80013798: sh          $v0, 0x8C($s0)
    MEM_H(0X8C, ctx->r16) = ctx->r2;
L_8001379C:
    // 0x8001379C: sb          $zero, 0x76($s0)
    MEM_B(0X76, ctx->r16) = 0;
    // 0x800137A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800137A4: jal         0x80014774
    // 0x800137A8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80014774(rdram, ctx);
        goto after_13;
    // 0x800137A8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_13:
    // 0x800137AC: bne         $v0, $zero, L_80013808
    if (ctx->r2 != 0) {
        // 0x800137B0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80013808;
    }
    // 0x800137B0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800137B4: lb          $v1, 0x5A($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X5A);
    // 0x800137B8: beq         $v1, $v0, L_80013800
    if (ctx->r3 == ctx->r2) {
        // 0x800137BC: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80013800;
    }
    // 0x800137BC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800137C0: lbu         $v1, 0x74($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X74);
    // 0x800137C4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800137C8: addiu       $a1, $a1, -0x3998
    ctx->r5 = ADD32(ctx->r5, -0X3998);
    // 0x800137CC: lbu         $a0, 0x64($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X64);
    // 0x800137D0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800137D4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800137D8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800137DC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800137E0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800137E4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800137E8: lbu         $v1, 0x63($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X63);
    // 0x800137EC: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800137F0: sltu        $v1, $v1, $v0
    ctx->r3 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800137F4: bne         $v1, $zero, L_80013800
    if (ctx->r3 != 0) {
        // 0x800137F8: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80013800;
    }
    // 0x800137F8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800137FC: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_80013800:
    // 0x80013800: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x80013804: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
L_80013808:
    // 0x80013808: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001380C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80013810: jr          $ra
    // 0x80013814: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80013814: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80013818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013818: lhu         $v1, 0x80($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X80);
    // 0x8001381C: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // 0x80013820: andi        $a1, $v1, 0xFFFF
    ctx->r5 = ctx->r3 & 0XFFFF;
    // 0x80013824: bne         $a1, $v0, L_8001385C
    if (ctx->r5 != ctx->r2) {
        // 0x80013828: nop
    
            goto L_8001385C;
    }
    // 0x80013828: nop

    // 0x8001382C: lw          $v0, 0xB4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB4);
    // 0x80013830: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80013834: andi        $v1, $v0, 0xF00
    ctx->r3 = ctx->r2 & 0XF00;
    // 0x80013838: bne         $v1, $a1, L_80013868
    if (ctx->r3 != ctx->r5) {
        // 0x8001383C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80013868;
    }
    // 0x8001383C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80013840: lw          $v0, 0xB8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB8);
    // 0x80013844: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80013848: andi        $v0, $v0, 0xF00
    ctx->r2 = ctx->r2 & 0XF00;
    // 0x8001384C: bne         $v0, $v1, L_80013868
    if (ctx->r2 != ctx->r3) {
        // 0x80013850: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80013868;
    }
    // 0x80013850: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80013854: j           L_80013868
    // 0x80013858: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80013868;
    // 0x80013858: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001385C:
    // 0x8001385C: lw          $v0, 0xB4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB4);
    // 0x80013860: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80013864: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
L_80013868:
    // 0x80013868: jr          $ra
    // 0x8001386C: nop

    return;
    // 0x8001386C: nop

;}
RECOMP_FUNC void func_80013870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80013874: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80013878: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001387C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013880: lb          $v1, 0x3($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X3);
    // 0x80013884: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x80013888: beq         $v0, $zero, L_80013B04
    if (ctx->r2 == 0) {
        // 0x8001388C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80013B04;
    }
    // 0x8001388C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80013890: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80013894: addu        $at, $at, $v0
    gpr jr_addend_8001389C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80013898: lw          $v0, -0x3170($at)
    ctx->r2 = ADD32(ctx->r1, -0X3170);
    // 0x8001389C: jr          $v0
    // 0x800138A0: nop

    switch (jr_addend_8001389C >> 2) {
        case 0: goto L_800138A4; break;
        case 1: goto L_800138B0; break;
        case 2: goto L_800138E8; break;
        case 3: goto L_80013928; break;
        case 4: goto L_80013A3C; break;
        case 5: goto L_80013A98; break;
        default: switch_error(__func__, 0x8001389C, 0x800ACE90);
    }
    // 0x800138A0: nop

L_800138A4:
    // 0x800138A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800138A8: j           L_80013B04
    // 0x800138AC: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
        goto L_80013B04;
    // 0x800138AC: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
L_800138B0:
    // 0x800138B0: lbu         $v0, 0x6B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6B);
    // 0x800138B4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800138B8: sb          $v0, 0x6B($s0)
    MEM_B(0X6B, ctx->r16) = ctx->r2;
    // 0x800138BC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800138C0: sltiu       $v0, $v0, 0xD
    ctx->r2 = ctx->r2 < 0XD ? 1 : 0;
    // 0x800138C4: bne         $v0, $zero, L_80013B04
    if (ctx->r2 != 0) {
        // 0x800138C8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80013B04;
    }
    // 0x800138C8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800138CC: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // 0x800138D0: jal         0x8001519C
    // 0x800138D4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001519C(rdram, ctx);
        goto after_0;
    // 0x800138D4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800138D8: jal         0x800150F4
    // 0x800138DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800150F4(rdram, ctx);
        goto after_1;
    // 0x800138DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800138E0: j           L_80013B04
    // 0x800138E4: nop

        goto L_80013B04;
    // 0x800138E4: nop

L_800138E8:
    // 0x800138E8: jal         0x800150F4
    // 0x800138EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800150F4(rdram, ctx);
        goto after_2;
    // 0x800138EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800138F0: bne         $v0, $zero, L_80013B04
    if (ctx->r2 != 0) {
        // 0x800138F4: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80013B04;
    }
    // 0x800138F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800138F8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800138FC: jal         0x8001504C
    // 0x80013900: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    func_8001504C(rdram, ctx);
        goto after_3;
    // 0x80013900: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    after_3:
    // 0x80013904: jal         0x80016F44
    // 0x80013908: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80016F44(rdram, ctx);
        goto after_4;
    // 0x80013908: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8001390C: lb          $v0, 0x5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5);
    // 0x80013910: bltz        $v0, L_80013B04
    if (SIGNED(ctx->r2) < 0) {
        // 0x80013914: nop
    
            goto L_80013B04;
    }
    // 0x80013914: nop

    // 0x80013918: jal         0x80017618
    // 0x8001391C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80017618(rdram, ctx);
        goto after_5;
    // 0x8001391C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x80013920: j           L_80013B04
    // 0x80013924: nop

        goto L_80013B04;
    // 0x80013924: nop

L_80013928:
    // 0x80013928: jal         0x80016DC0
    // 0x8001392C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80016DC0(rdram, ctx);
        goto after_6;
    // 0x8001392C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x80013930: addiu       $v1, $zero, 0x12
    ctx->r3 = ADD32(0, 0X12);
    // 0x80013934: bne         $v0, $v1, L_80013A20
    if (ctx->r2 != ctx->r3) {
        // 0x80013938: addiu       $a0, $zero, 0x2B
        ctx->r4 = ADD32(0, 0X2B);
            goto L_80013A20;
    }
    // 0x80013938: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x8001393C: lw          $v1, 0xD4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XD4);
    // 0x80013940: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x80013944: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // 0x80013948: lbu         $a0, 0x71($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X71);
    // 0x8001394C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80013950: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // 0x80013954: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80013958: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8001395C: beq         $v1, $v0, L_80013968
    if (ctx->r3 == ctx->r2) {
        // 0x80013960: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_80013968;
    }
    // 0x80013960: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80013964: sb          $v0, 0x71($s0)
    MEM_B(0X71, ctx->r16) = ctx->r2;
L_80013968:
    // 0x80013968: lw          $v1, 0xAC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XAC);
    // 0x8001396C: addiu       $v0, $zero, 0x3E7
    ctx->r2 = ADD32(0, 0X3E7);
    // 0x80013970: beq         $v1, $v0, L_8001397C
    if (ctx->r3 == ctx->r2) {
        // 0x80013974: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_8001397C;
    }
    // 0x80013974: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80013978: sw          $v0, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->r2;
L_8001397C:
    // 0x8001397C: lbu         $v1, 0x64($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X64);
    // 0x80013980: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x80013984: bne         $v0, $zero, L_80013990
    if (ctx->r2 != 0) {
        // 0x80013988: addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
            goto L_80013990;
    }
    // 0x80013988: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8001398C: sb          $v0, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r2;
L_80013990:
    // 0x80013990: lbu         $v1, 0x74($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X74);
    // 0x80013994: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80013998: addiu       $a1, $a1, -0x3998
    ctx->r5 = ADD32(ctx->r5, -0X3998);
    // 0x8001399C: lbu         $a0, 0x64($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X64);
    // 0x800139A0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800139A4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800139A8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800139AC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800139B0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800139B4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800139B8: lbu         $v1, 0x66($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X66);
    // 0x800139BC: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800139C0: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800139C4: beql        $v0, $zero, L_800139E0
    if (ctx->r2 == 0) {
        // 0x800139C8: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_800139E0;
    }
    goto skip_0;
    // 0x800139C8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    skip_0:
    // 0x800139CC: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x800139D0: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x800139D4: jal         0x8000637C
    // 0x800139D8: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_7;
    // 0x800139D8: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_7:
    // 0x800139DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800139E0:
    // 0x800139E0: jal         0x80016FCC
    // 0x800139E4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_80016FCC(rdram, ctx);
        goto after_8;
    // 0x800139E4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_8:
    // 0x800139E8: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    // 0x800139EC: jal         0x8001D520
    // 0x800139F0: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    func_8001D520(rdram, ctx);
        goto after_9;
    // 0x800139F0: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    after_9:
    // 0x800139F4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800139F8: beq         $v1, $zero, L_80013B04
    if (ctx->r3 == 0) {
        // 0x800139FC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80013B04;
    }
    // 0x800139FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80013A00: sb          $v0, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r2;
    // 0x80013A04: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x80013A08: sb          $v0, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r2;
    // 0x80013A0C: sb          $zero, 0x2B($v1)
    MEM_B(0X2B, ctx->r3) = 0;
    // 0x80013A10: lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5);
    // 0x80013A14: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80013A18: j           L_80013B04
    // 0x80013A1C: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
        goto L_80013B04;
    // 0x80013A1C: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
L_80013A20:
    // 0x80013A20: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x80013A24: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80013A28: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // 0x80013A2C: jal         0x8000637C
    // 0x80013A30: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_10;
    // 0x80013A30: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_10:
    // 0x80013A34: j           L_80013B04
    // 0x80013A38: nop

        goto L_80013B04;
    // 0x80013A38: nop

L_80013A3C:
    // 0x80013A3C: lbu         $v1, 0x74($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X74);
    // 0x80013A40: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80013A44: addiu       $a1, $a1, -0x3998
    ctx->r5 = ADD32(ctx->r5, -0X3998);
    // 0x80013A48: lbu         $a0, 0x64($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X64);
    // 0x80013A4C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80013A50: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80013A54: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80013A58: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80013A5C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80013A60: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80013A64: lbu         $v1, 0x66($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X66);
    // 0x80013A68: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80013A6C: bne         $v1, $v0, L_80013A80
    if (ctx->r3 != ctx->r2) {
        // 0x80013A70: addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
            goto L_80013A80;
    }
    // 0x80013A70: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x80013A74: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80013A78: j           L_80013B04
    // 0x80013A7C: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
        goto L_80013B04;
    // 0x80013A7C: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
L_80013A80:
    // 0x80013A80: lbu         $a0, 0x63($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X63);
    // 0x80013A84: beq         $a0, $zero, L_80013B04
    if (ctx->r4 == 0) {
        // 0x80013A88: sb          $v0, 0x66($s0)
        MEM_B(0X66, ctx->r16) = ctx->r2;
            goto L_80013B04;
    }
    // 0x80013A88: sb          $v0, 0x66($s0)
    MEM_B(0X66, ctx->r16) = ctx->r2;
    // 0x80013A8C: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x80013A90: j           L_80013B04
    // 0x80013A94: sb          $v0, 0x63($s0)
    MEM_B(0X63, ctx->r16) = ctx->r2;
        goto L_80013B04;
    // 0x80013A94: sb          $v0, 0x63($s0)
    MEM_B(0X63, ctx->r16) = ctx->r2;
L_80013A98:
    // 0x80013A98: lb          $v1, 0x5A($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X5A);
    // 0x80013A9C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80013AA0: beq         $v1, $v0, L_80013AF4
    if (ctx->r3 == ctx->r2) {
        // 0x80013AA4: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80013AF4;
    }
    // 0x80013AA4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80013AA8: lbu         $v1, 0x74($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X74);
    // 0x80013AAC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80013AB0: addiu       $a1, $a1, -0x3998
    ctx->r5 = ADD32(ctx->r5, -0X3998);
    // 0x80013AB4: lbu         $a0, 0x64($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X64);
    // 0x80013AB8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80013ABC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80013AC0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80013AC4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80013AC8: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80013ACC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80013AD0: lbu         $v1, 0x63($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X63);
    // 0x80013AD4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80013AD8: sltu        $v1, $v1, $v0
    ctx->r3 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80013ADC: bne         $v1, $zero, L_80013AF4
    if (ctx->r3 != 0) {
        // 0x80013AE0: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80013AF4;
    }
    // 0x80013AE0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80013AE4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80013AE8: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x80013AEC: j           L_80013B04
    // 0x80013AF0: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
        goto L_80013B04;
    // 0x80013AF0: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
L_80013AF4:
    // 0x80013AF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80013AF8: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
    // 0x80013AFC: jal         0x800163F4
    // 0x80013B00: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    func_800163F4(rdram, ctx);
        goto after_11;
    // 0x80013B00: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    after_11:
L_80013B04:
    // 0x80013B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013B08: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80013B0C: jr          $ra
    // 0x80013B10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80013B10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80013B14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013B14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80013B18: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80013B1C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80013B20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013B24: lb          $v1, 0x3($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X3);
    // 0x80013B28: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x80013B2C: beq         $v0, $zero, L_80013FA0
    if (ctx->r2 == 0) {
        // 0x80013B30: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80013FA0;
    }
    // 0x80013B30: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80013B34: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80013B38: addu        $at, $at, $v0
    gpr jr_addend_80013B40 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80013B3C: lw          $v0, -0x3158($at)
    ctx->r2 = ADD32(ctx->r1, -0X3158);
    // 0x80013B40: jr          $v0
    // 0x80013B44: nop

    switch (jr_addend_80013B40 >> 2) {
        case 0: goto L_80013B48; break;
        case 1: goto L_80013C18; break;
        case 2: goto L_80013FA0; break;
        case 3: goto L_80013D10; break;
        case 4: goto L_80013F84; break;
        default: switch_error(__func__, 0x80013B40, 0x800ACEA8);
    }
    // 0x80013B44: nop

L_80013B48:
    // 0x80013B48: lw          $v1, 0xD0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XD0);
    // 0x80013B4C: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x80013B50: sw          $v0, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->r2;
    // 0x80013B54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80013B58: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // 0x80013B5C: sb          $zero, 0x58($v1)
    MEM_B(0X58, ctx->r3) = 0;
    // 0x80013B60: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80013B64: sb          $zero, 0x58($s0)
    MEM_B(0X58, ctx->r16) = 0;
    // 0x80013B68: lbu         $a1, 0x5($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X5);
    // 0x80013B6C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x80013B70: jal         0x8000637C
    // 0x80013B74: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_0;
    // 0x80013B74: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_0:
    // 0x80013B78: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x80013B7C: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x80013B80: jal         0x8000637C
    // 0x80013B84: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_1;
    // 0x80013B84: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_1:
    // 0x80013B88: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80013B8C: lbu         $a1, 0x5($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X5);
    // 0x80013B90: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x80013B94: jal         0x8000637C
    // 0x80013B98: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_2;
    // 0x80013B98: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_2:
    // 0x80013B9C: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80013BA0: sb          $zero, 0x72($v0)
    MEM_B(0X72, ctx->r2) = 0;
    // 0x80013BA4: lw          $v1, 0xD4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XD4);
    // 0x80013BA8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80013BAC: sb          $zero, 0x72($s0)
    MEM_B(0X72, ctx->r16) = 0;
    // 0x80013BB0: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // 0x80013BB4: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    // 0x80013BB8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80013BBC: xori        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 ^ 0X1;
    // 0x80013BC0: jal         0x8001C0D0
    // 0x80013BC4: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    func_8001C0D0(rdram, ctx);
        goto after_3;
    // 0x80013BC4: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    after_3:
    // 0x80013BC8: lb          $v1, 0x5A($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X5A);
    // 0x80013BCC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80013BD0: beq         $v1, $v0, L_80013C18
    if (ctx->r3 == ctx->r2) {
        // 0x80013BD4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80013C18;
    }
    // 0x80013BD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80013BD8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80013BDC: lbu         $v1, 0x2074($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2074);
    // 0x80013BE0: bne         $v1, $v0, L_80013BF0
    if (ctx->r3 != ctx->r2) {
        // 0x80013BE4: nop
    
            goto L_80013BF0;
    }
    // 0x80013BE4: nop

    // 0x80013BE8: jal         0x8002BD30
    // 0x80013BEC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8002BD30(rdram, ctx);
        goto after_4;
    // 0x80013BEC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
L_80013BF0:
    // 0x80013BF0: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80013BF4: lw          $v1, 0xD4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XD4);
    // 0x80013BF8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80013BFC: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // 0x80013C00: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80013C04: lbu         $a0, 0x5($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X5);
    // 0x80013C08: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80013C0C: xori        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 ^ 0X1;
    // 0x80013C10: jal         0x8001C0D0
    // 0x80013C14: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    func_8001C0D0(rdram, ctx);
        goto after_5;
    // 0x80013C14: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    after_5:
L_80013C18:
    // 0x80013C18: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80013C1C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
L_80013C20:
    // 0x80013C20: lw          $v1, 0xB0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB0);
    // 0x80013C24: lw          $a0, 0xE4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XE4);
    // 0x80013C28: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x80013C2C: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x80013C30: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80013C34: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80013C38: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80013C3C: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x80013C40: bnel        $v0, $zero, L_80013C48
    if (ctx->r2 != 0) {
        // 0x80013C44: sb          $a2, 0x70($v1)
        MEM_B(0X70, ctx->r3) = ctx->r6;
            goto L_80013C48;
    }
    goto skip_0;
    // 0x80013C44: sb          $a2, 0x70($v1)
    MEM_B(0X70, ctx->r3) = ctx->r6;
    skip_0:
L_80013C48:
    // 0x80013C48: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80013C4C: slti        $v0, $a1, 0xA
    ctx->r2 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    // 0x80013C50: bne         $v0, $zero, L_80013C20
    if (ctx->r2 != 0) {
        // 0x80013C54: nop
    
            goto L_80013C20;
    }
    // 0x80013C54: nop

    // 0x80013C58: lw          $v0, 0xE4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XE4);
    // 0x80013C5C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80013C60: bgez        $v0, L_80013FA0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80013C64: sw          $v0, 0xE4($s0)
        MEM_W(0XE4, ctx->r16) = ctx->r2;
            goto L_80013FA0;
    }
    // 0x80013C64: sw          $v0, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->r2;
    // 0x80013C68: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80013C6C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013C70: sb          $v0, 0x2089($at)
    MEM_B(0X2089, ctx->r1) = ctx->r2;
    // 0x80013C74: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80013C78: lbu         $v0, 0x2089($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2089);
    // 0x80013C7C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80013C80: addiu       $a1, $a1, 0x7B85
    ctx->r5 = ADD32(ctx->r5, 0X7B85);
    // 0x80013C84: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80013C88: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80013C8C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013C90: sb          $v0, 0x2088($at)
    MEM_B(0X2088, ctx->r1) = ctx->r2;
    // 0x80013C94: beq         $v1, $a0, L_80013CAC
    if (ctx->r3 == ctx->r4) {
        // 0x80013C98: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80013CAC;
    }
    // 0x80013C98: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80013C9C: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // 0x80013CA0: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80013CA4: bne         $v0, $a0, L_80013CB4
    if (ctx->r2 != ctx->r4) {
        // 0x80013CA8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80013CB4;
    }
    // 0x80013CA8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80013CAC:
    // 0x80013CAC: j           L_80013F9C
    // 0x80013CB0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80013F9C;
    // 0x80013CB0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80013CB4:
    // 0x80013CB4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80013CB8: lb          $v1, 0x25FA($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X25FA);
    // 0x80013CBC: bne         $v1, $v0, L_80013F9C
    if (ctx->r3 != ctx->r2) {
        // 0x80013CC0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80013F9C;
    }
    // 0x80013CC0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80013CC4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80013CC8: lb          $v0, 0x7A4A($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X7A4A);
    // 0x80013CCC: bne         $v0, $v1, L_80013F9C
    if (ctx->r2 != ctx->r3) {
        // 0x80013CD0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80013F9C;
    }
    // 0x80013CD0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80013CD4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80013CD8: lb          $v0, 0x25A5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X25A5);
    // 0x80013CDC: bltz        $v0, L_80013F9C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80013CE0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80013F9C;
    }
    // 0x80013CE0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80013CE4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80013CE8: lb          $v0, 0x79F5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X79F5);
    // 0x80013CEC: bltz        $v0, L_80013F9C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80013CF0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80013F9C;
    }
    // 0x80013CF0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80013CF4: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80013CF8: lb          $v1, 0x2($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X2);
    // 0x80013CFC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80013D00: beq         $v1, $v0, L_80013F98
    if (ctx->r3 == ctx->r2) {
        // 0x80013D04: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80013F98;
    }
    // 0x80013D04: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80013D08: j           L_80013FA0
    // 0x80013D0C: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
        goto L_80013FA0;
    // 0x80013D0C: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
L_80013D10:
    // 0x80013D10: lb          $v0, 0x5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5);
    // 0x80013D14: bgez        $v0, L_80013D88
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80013D18: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80013D88;
    }
    // 0x80013D18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80013D1C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013D20: sb          $v0, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = ctx->r2;
    // 0x80013D24: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80013D28: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013D2C: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x80013D30: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013D34: sb          $zero, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = 0;
    // 0x80013D38: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80013D3C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013D40: sw          $v0, 0x7BB4($at)
    MEM_W(0X7BB4, ctx->r1) = ctx->r2;
    // 0x80013D44: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013D48: sw          $v0, 0x7BBC($at)
    MEM_W(0X7BBC, ctx->r1) = ctx->r2;
    // 0x80013D4C: sb          $zero, 0x68($s0)
    MEM_B(0X68, ctx->r16) = 0;
    // 0x80013D50: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80013D54: lbu         $v0, 0x2081($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2081);
    // 0x80013D58: bne         $v0, $zero, L_80013E1C
    if (ctx->r2 != 0) {
        // 0x80013D5C: nop
    
            goto L_80013E1C;
    }
    // 0x80013D5C: nop

    // 0x80013D60: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80013D64: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x80013D68: bne         $v0, $zero, L_80013E1C
    if (ctx->r2 != 0) {
        // 0x80013D6C: nop
    
            goto L_80013E1C;
    }
    // 0x80013D6C: nop

    // 0x80013D70: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80013D74: lbu         $v0, 0x7B9C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9C);
    // 0x80013D78: beq         $v0, $zero, L_80013E28
    if (ctx->r2 == 0) {
        // 0x80013D7C: nop
    
            goto L_80013E28;
    }
    // 0x80013D7C: nop

    // 0x80013D80: j           L_80013E1C
    // 0x80013D84: nop

        goto L_80013E1C;
    // 0x80013D84: nop

L_80013D88:
    // 0x80013D88: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80013D8C: lb          $v0, 0x5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5);
    // 0x80013D90: bgez        $v0, L_80013E54
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80013D94: addiu       $v0, $zero, 0x81
        ctx->r2 = ADD32(0, 0X81);
            goto L_80013E54;
    }
    // 0x80013D94: addiu       $v0, $zero, 0x81
    ctx->r2 = ADD32(0, 0X81);
    // 0x80013D98: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80013D9C: lbu         $v1, 0x7B98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B98);
    // 0x80013DA0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013DA4: sb          $v0, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = ctx->r2;
    // 0x80013DA8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80013DAC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013DB0: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x80013DB4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80013DB8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013DBC: sb          $v0, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = ctx->r2;
    // 0x80013DC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80013DC4: bne         $v1, $v0, L_80013DD4
    if (ctx->r3 != ctx->r2) {
        // 0x80013DC8: nop
    
            goto L_80013DD4;
    }
    // 0x80013DC8: nop

    // 0x80013DCC: jal         0x8000C554
    // 0x80013DD0: nop

    func_8000C554(rdram, ctx);
        goto after_6;
    // 0x80013DD0: nop

    after_6:
L_80013DD4:
    // 0x80013DD4: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80013DD8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013DDC: sw          $v0, 0x7BB4($at)
    MEM_W(0X7BB4, ctx->r1) = ctx->r2;
    // 0x80013DE0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013DE4: sw          $v0, 0x7BBC($at)
    MEM_W(0X7BBC, ctx->r1) = ctx->r2;
    // 0x80013DE8: sb          $zero, 0x68($s0)
    MEM_B(0X68, ctx->r16) = 0;
    // 0x80013DEC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80013DF0: lbu         $v0, 0x2081($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2081);
    // 0x80013DF4: bne         $v0, $zero, L_80013E1C
    if (ctx->r2 != 0) {
        // 0x80013DF8: nop
    
            goto L_80013E1C;
    }
    // 0x80013DF8: nop

    // 0x80013DFC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80013E00: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x80013E04: bne         $v0, $zero, L_80013E1C
    if (ctx->r2 != 0) {
        // 0x80013E08: nop
    
            goto L_80013E1C;
    }
    // 0x80013E08: nop

    // 0x80013E0C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80013E10: lbu         $v0, 0x7B9C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9C);
    // 0x80013E14: beq         $v0, $zero, L_80013E28
    if (ctx->r2 == 0) {
        // 0x80013E18: nop
    
            goto L_80013E28;
    }
    // 0x80013E18: nop

L_80013E1C:
    // 0x80013E1C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013E20: j           L_80013FA0
    // 0x80013E24: sb          $zero, 0x2071($at)
    MEM_B(0X2071, ctx->r1) = 0;
        goto L_80013FA0;
    // 0x80013E24: sb          $zero, 0x2071($at)
    MEM_B(0X2071, ctx->r1) = 0;
L_80013E28:
    // 0x80013E28: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80013E2C: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x80013E30: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x80013E34: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80013E38: lbu         $v1, 0x2071($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2071);
    // 0x80013E3C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80013E40: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80013E44: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80013E48: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013E4C: j           L_80013FA0
    // 0x80013E50: sb          $v1, 0x2071($at)
    MEM_B(0X2071, ctx->r1) = ctx->r3;
        goto L_80013FA0;
    // 0x80013E50: sb          $v1, 0x2071($at)
    MEM_B(0X2071, ctx->r1) = ctx->r3;
L_80013E54:
    // 0x80013E54: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013E58: sb          $v0, 0x7B7F($at)
    MEM_B(0X7B7F, ctx->r1) = ctx->r2;
    // 0x80013E5C: lw          $v1, 0xD0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XD0);
    // 0x80013E60: lbu         $v0, 0x78($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X78);
    // 0x80013E64: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80013E68: sb          $v0, 0x78($v1)
    MEM_B(0X78, ctx->r3) = ctx->r2;
    // 0x80013E6C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80013E70: lbu         $v1, 0x2077($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2077);
    // 0x80013E74: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80013E78: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80013E7C: bne         $v0, $zero, L_80013F5C
    if (ctx->r2 != 0) {
        // 0x80013E80: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_80013F5C;
    }
    // 0x80013E80: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80013E84: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80013E88: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013E8C: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x80013E90: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80013E94: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013E98: sb          $v0, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = ctx->r2;
    // 0x80013E9C: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80013EA0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013EA4: sw          $v0, 0x7BB4($at)
    MEM_W(0X7BB4, ctx->r1) = ctx->r2;
    // 0x80013EA8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013EAC: sw          $v0, 0x7BBC($at)
    MEM_W(0X7BBC, ctx->r1) = ctx->r2;
    // 0x80013EB0: sb          $zero, 0x68($s0)
    MEM_B(0X68, ctx->r16) = 0;
    // 0x80013EB4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80013EB8: lbu         $v0, 0x2081($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2081);
    // 0x80013EBC: bne         $v0, $zero, L_80013EE4
    if (ctx->r2 != 0) {
        // 0x80013EC0: nop
    
            goto L_80013EE4;
    }
    // 0x80013EC0: nop

    // 0x80013EC4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80013EC8: lbu         $v0, 0x7B89($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B89);
    // 0x80013ECC: bne         $v0, $zero, L_80013EE4
    if (ctx->r2 != 0) {
        // 0x80013ED0: nop
    
            goto L_80013EE4;
    }
    // 0x80013ED0: nop

    // 0x80013ED4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80013ED8: lbu         $v0, 0x7B9C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9C);
    // 0x80013EDC: beq         $v0, $zero, L_80013EF0
    if (ctx->r2 == 0) {
        // 0x80013EE0: nop
    
            goto L_80013EF0;
    }
    // 0x80013EE0: nop

L_80013EE4:
    // 0x80013EE4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013EE8: j           L_80013F18
    // 0x80013EEC: sb          $zero, 0x2071($at)
    MEM_B(0X2071, ctx->r1) = 0;
        goto L_80013F18;
    // 0x80013EEC: sb          $zero, 0x2071($at)
    MEM_B(0X2071, ctx->r1) = 0;
L_80013EF0:
    // 0x80013EF0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80013EF4: lw          $v0, 0x7BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BB4);
    // 0x80013EF8: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x80013EFC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80013F00: lbu         $v1, 0x2071($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2071);
    // 0x80013F04: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80013F08: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80013F0C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80013F10: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013F14: sb          $v1, 0x2071($at)
    MEM_B(0X2071, ctx->r1) = ctx->r3;
L_80013F18:
    // 0x80013F18: lw          $a1, 0xD0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XD0);
    // 0x80013F1C: lbu         $a0, 0x68($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X68);
    // 0x80013F20: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x80013F24: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x80013F28: bne         $v1, $v0, L_80013F34
    if (ctx->r3 != ctx->r2) {
        // 0x80013F2C: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_80013F34;
    }
    // 0x80013F2C: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80013F30: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
L_80013F34:
    // 0x80013F34: sb          $v0, 0x68($a1)
    MEM_B(0X68, ctx->r5) = ctx->r2;
    // 0x80013F38: lw          $a0, 0xD0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XD0);
    // 0x80013F3C: lbu         $a1, 0x77($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X77);
    // 0x80013F40: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x80013F44: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x80013F48: bne         $v1, $v0, L_80013F54
    if (ctx->r3 != ctx->r2) {
        // 0x80013F4C: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_80013F54;
    }
    // 0x80013F4C: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x80013F50: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
L_80013F54:
    // 0x80013F54: j           L_80013FA0
    // 0x80013F58: sb          $v0, 0x77($a0)
    MEM_B(0X77, ctx->r4) = ctx->r2;
        goto L_80013FA0;
    // 0x80013F58: sb          $v0, 0x77($a0)
    MEM_B(0X77, ctx->r4) = ctx->r2;
L_80013F5C:
    // 0x80013F5C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80013F60: lbu         $v1, 0x7B97($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B97);
    // 0x80013F64: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013F68: sb          $v0, 0x7B71($at)
    MEM_B(0X7B71, ctx->r1) = ctx->r2;
    // 0x80013F6C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013F70: sb          $zero, 0x7B72($at)
    MEM_B(0X7B72, ctx->r1) = 0;
    // 0x80013F74: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80013F78: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80013F7C: j           L_80013FA0
    // 0x80013F80: sb          $v1, 0x7B97($at)
    MEM_B(0X7B97, ctx->r1) = ctx->r3;
        goto L_80013FA0;
    // 0x80013F80: sb          $v1, 0x7B97($at)
    MEM_B(0X7B97, ctx->r1) = ctx->r3;
L_80013F84:
    // 0x80013F84: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80013F88: lb          $v1, 0x2($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X2);
    // 0x80013F8C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80013F90: bne         $v1, $v0, L_80013FA0
    if (ctx->r3 != ctx->r2) {
        // 0x80013F94: nop
    
            goto L_80013FA0;
    }
    // 0x80013F94: nop

L_80013F98:
    // 0x80013F98: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80013F9C:
    // 0x80013F9C: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
L_80013FA0:
    // 0x80013FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013FA4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80013FA8: jr          $ra
    // 0x80013FAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80013FAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80013FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013FB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80013FB4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80013FB8: lb          $v1, 0x3($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X3);
    // 0x80013FBC: beq         $v1, $zero, L_80013FD4
    if (ctx->r3 == 0) {
        // 0x80013FC0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80013FD4;
    }
    // 0x80013FC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80013FC4: beq         $v1, $v0, L_80013FE8
    if (ctx->r3 == ctx->r2) {
        // 0x80013FC8: nop
    
            goto L_80013FE8;
    }
    // 0x80013FC8: nop

    // 0x80013FCC: j           L_80014028
    // 0x80013FD0: nop

        goto L_80014028;
    // 0x80013FD0: nop

L_80013FD4:
    // 0x80013FD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80013FD8: sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
    // 0x80013FDC: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x80013FE0: j           L_80014028
    // 0x80013FE4: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
        goto L_80014028;
    // 0x80013FE4: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
L_80013FE8:
    // 0x80013FE8: lw          $v0, 0xB8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB8);
    // 0x80013FEC: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80013FF0: andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // 0x80013FF4: beq         $v0, $zero, L_80014008
    if (ctx->r2 == 0) {
        // 0x80013FF8: nop
    
            goto L_80014008;
    }
    // 0x80013FF8: nop

    // 0x80013FFC: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x80014000: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80014004: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
L_80014008:
    // 0x80014008: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x8001400C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80014010: bgtz        $v0, L_80014028
    if (SIGNED(ctx->r2) > 0) {
        // 0x80014014: sw          $v0, 0x28($a0)
        MEM_W(0X28, ctx->r4) = ctx->r2;
            goto L_80014028;
    }
    // 0x80014014: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
    // 0x80014018: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001401C: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
    // 0x80014020: jal         0x800163F4
    // 0x80014024: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    func_800163F4(rdram, ctx);
        goto after_0;
    // 0x80014024: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    after_0:
L_80014028:
    // 0x80014028: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8001402C: jr          $ra
    // 0x80014030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80014030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80014034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014034: jr          $ra
    // 0x80014038: nop

    return;
    // 0x80014038: nop

;}
RECOMP_FUNC void func_8001403C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001403C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80014040: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80014044: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80014048: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001404C: lb          $v1, 0x3($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X3);
    // 0x80014050: sltiu       $v0, $v1, 0xB
    ctx->r2 = ctx->r3 < 0XB ? 1 : 0;
    // 0x80014054: beq         $v0, $zero, L_800144B0
    if (ctx->r2 == 0) {
        // 0x80014058: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800144B0;
    }
    // 0x80014058: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8001405C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80014060: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80014064: addu        $at, $at, $v0
    gpr jr_addend_8001406C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80014068: lw          $v0, -0x3140($at)
    ctx->r2 = ADD32(ctx->r1, -0X3140);
    // 0x8001406C: jr          $v0
    // 0x80014070: nop

    switch (jr_addend_8001406C >> 2) {
        case 0: goto L_80014074; break;
        case 1: goto L_800140FC; break;
        case 2: goto L_800141E4; break;
        case 3: goto L_80014228; break;
        case 4: goto L_8001429C; break;
        case 5: goto L_800142E8; break;
        case 6: goto L_80014378; break;
        case 7: goto L_80014398; break;
        case 8: goto L_800143BC; break;
        case 9: goto L_8001443C; break;
        case 10: goto L_800144B0; break;
        default: switch_error(__func__, 0x8001406C, 0x800ACEC0);
    }
    // 0x80014070: nop

L_80014074:
    // 0x80014074: lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X3);
    // 0x80014078: lb          $v1, 0x57($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X57);
    // 0x8001407C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80014080: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80014084: beq         $v1, $zero, L_8001409C
    if (ctx->r3 == 0) {
        // 0x80014088: sb          $v0, 0x3($s0)
        MEM_B(0X3, ctx->r16) = ctx->r2;
            goto L_8001409C;
    }
    // 0x80014088: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // 0x8001408C: lbu         $v0, 0x57($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X57);
    // 0x80014090: sb          $a0, 0x4F($s0)
    MEM_B(0X4F, ctx->r16) = ctx->r4;
    // 0x80014094: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80014098: sb          $v0, 0x57($s0)
    MEM_B(0X57, ctx->r16) = ctx->r2;
L_8001409C:
    // 0x8001409C: lw          $v0, 0xD4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD4);
    // 0x800140A0: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
    // 0x800140A4: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
    // 0x800140A8: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x800140AC: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    // 0x800140B0: jal         0x8000637C
    // 0x800140B4: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_0;
    // 0x800140B4: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_0:
    // 0x800140B8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800140BC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800140C0:
    // 0x800140C0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_800140C4:
    // 0x800140C4: lw          $v0, 0xB0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB0);
    // 0x800140C8: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x800140CC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800140D0: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800140D4: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // 0x800140D8: slti        $v0, $a2, 0xA
    ctx->r2 = SIGNED(ctx->r6) < 0XA ? 1 : 0;
    // 0x800140DC: bne         $v0, $zero, L_800140C4
    if (ctx->r2 != 0) {
        // 0x800140E0: nop
    
            goto L_800140C4;
    }
    // 0x800140E0: nop

    // 0x800140E4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800140E8: slti        $v0, $a0, 0x6
    ctx->r2 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
    // 0x800140EC: bne         $v0, $zero, L_800140C0
    if (ctx->r2 != 0) {
        // 0x800140F0: addiu       $v1, $v1, 0x12
        ctx->r3 = ADD32(ctx->r3, 0X12);
            goto L_800140C0;
    }
    // 0x800140F0: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x800140F4: j           L_800144B0
    // 0x800140F8: nop

        goto L_800144B0;
    // 0x800140F8: nop

L_800140FC:
    // 0x800140FC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80014100: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80014104: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
L_80014108:
    // 0x80014108: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8001410C: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
L_80014110:
    // 0x80014110: lw          $v0, 0xB0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB0);
    // 0x80014114: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80014118: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x8001411C: lbu         $v0, 0x70($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X70);
    // 0x80014120: beq         $v0, $zero, L_80014130
    if (ctx->r2 == 0) {
        // 0x80014124: sll         $v1, $a0, 3
        ctx->r3 = S32(ctx->r4 << 3);
            goto L_80014130;
    }
    // 0x80014124: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x80014128: j           L_80014180
    // 0x8001412C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80014180;
    // 0x8001412C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80014130:
    // 0x80014130: beql        $t1, $zero, L_80014184
    if (ctx->r9 == 0) {
        // 0x80014134: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80014184;
    }
    goto skip_0;
    // 0x80014134: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x80014138: bltz        $a0, L_80014168
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001413C: addu        $a3, $a0, $zero
        ctx->r7 = ADD32(ctx->r4, 0);
            goto L_80014168;
    }
    // 0x8001413C: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80014140: addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // 0x80014144: sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2 << 1);
L_80014148:
    // 0x80014148: lw          $v0, 0xB0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB0);
    // 0x8001414C: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80014150: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80014154: lbu         $v1, 0x5E($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X5E);
    // 0x80014158: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8001415C: addiu       $a1, $a1, -0x12
    ctx->r5 = ADD32(ctx->r5, -0X12);
    // 0x80014160: bgez        $a3, L_80014148
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80014164: sb          $v1, 0x70($v0)
        MEM_B(0X70, ctx->r2) = ctx->r3;
            goto L_80014148;
    }
    // 0x80014164: sb          $v1, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r3;
L_80014168:
    // 0x80014168: lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X3);
    // 0x8001416C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80014170: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80014174: sw          $t2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r10;
    // 0x80014178: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001417C: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
L_80014180:
    // 0x80014180: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80014184:
    // 0x80014184: slti        $v0, $a0, 0x12
    ctx->r2 = SIGNED(ctx->r4) < 0X12 ? 1 : 0;
    // 0x80014188: bne         $v0, $zero, L_80014110
    if (ctx->r2 != 0) {
        // 0x8001418C: addiu       $t0, $t0, 0x12
        ctx->r8 = ADD32(ctx->r8, 0X12);
            goto L_80014110;
    }
    // 0x8001418C: addiu       $t0, $t0, 0x12
    ctx->r8 = ADD32(ctx->r8, 0X12);
    // 0x80014190: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80014194: slti        $v0, $a2, 0xA
    ctx->r2 = SIGNED(ctx->r6) < 0XA ? 1 : 0;
    // 0x80014198: bnel        $v0, $zero, L_80014108
    if (ctx->r2 != 0) {
        // 0x8001419C: addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
            goto L_80014108;
    }
    goto skip_1;
    // 0x8001419C: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    skip_1:
    // 0x800141A0: lbu         $v0, 0x63($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X63);
    // 0x800141A4: beq         $v0, $zero, L_800141B0
    if (ctx->r2 == 0) {
        // 0x800141A8: addiu       $v0, $v0, -0x2
        ctx->r2 = ADD32(ctx->r2, -0X2);
            goto L_800141B0;
    }
    // 0x800141A8: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x800141AC: sb          $v0, 0x63($s0)
    MEM_B(0X63, ctx->r16) = ctx->r2;
L_800141B0:
    // 0x800141B0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800141B4: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x800141B8: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800141BC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800141C0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800141C4: bne         $a1, $zero, L_800144B0
    if (ctx->r5 != 0) {
        // 0x800141C8: sb          $v0, 0x58($s0)
        MEM_B(0X58, ctx->r16) = ctx->r2;
            goto L_800144B0;
    }
    // 0x800141C8: sb          $v0, 0x58($s0)
    MEM_B(0X58, ctx->r16) = ctx->r2;
    // 0x800141CC: lbu         $v0, 0x63($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X63);
    // 0x800141D0: bne         $v0, $zero, L_800144B0
    if (ctx->r2 != 0) {
        // 0x800141D4: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800144B0;
    }
    // 0x800141D4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800141D8: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // 0x800141DC: j           L_800144B0
    // 0x800141E0: sb          $zero, 0x58($s0)
    MEM_B(0X58, ctx->r16) = 0;
        goto L_800144B0;
    // 0x800141E0: sb          $zero, 0x58($s0)
    MEM_B(0X58, ctx->r16) = 0;
L_800141E4:
    // 0x800141E4: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x800141E8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800141EC: bne         $v0, $zero, L_800141FC
    if (ctx->r2 != 0) {
        // 0x800141F0: sw          $v0, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->r2;
            goto L_800141FC;
    }
    // 0x800141F0: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x800141F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800141F8: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
L_800141FC:
    // 0x800141FC: lbu         $v0, 0x63($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X63);
    // 0x80014200: beq         $v0, $zero, L_8001420C
    if (ctx->r2 == 0) {
        // 0x80014204: addiu       $v0, $v0, -0x2
        ctx->r2 = ADD32(ctx->r2, -0X2);
            goto L_8001420C;
    }
    // 0x80014204: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x80014208: sb          $v0, 0x63($s0)
    MEM_B(0X63, ctx->r16) = ctx->r2;
L_8001420C:
    // 0x8001420C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80014210: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80014214: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80014218: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001421C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80014220: j           L_800144B0
    // 0x80014224: sb          $v0, 0x58($s0)
    MEM_B(0X58, ctx->r16) = ctx->r2;
        goto L_800144B0;
    // 0x80014224: sb          $v0, 0x58($s0)
    MEM_B(0X58, ctx->r16) = ctx->r2;
L_80014228:
    // 0x80014228: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8001422C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80014230: lw          $a1, 0xB0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB0);
    // 0x80014234: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80014238:
    // 0x80014238: addu        $v1, $a2, $a1
    ctx->r3 = ADD32(ctx->r6, ctx->r5);
L_8001423C:
    // 0x8001423C: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x80014240: beq         $v0, $zero, L_8001425C
    if (ctx->r2 == 0) {
        // 0x80014244: slt         $v0, $a0, $a3
        ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_8001425C;
    }
    // 0x80014244: slt         $v0, $a0, $a3
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80014248: bnel        $v0, $zero, L_80014270
    if (ctx->r2 != 0) {
        // 0x8001424C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80014270;
    }
    goto skip_2;
    // 0x8001424C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_2:
    // 0x80014250: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x80014254: j           L_8001426C
    // 0x80014258: sw          $a2, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->r6;
        goto L_8001426C;
    // 0x80014258: sw          $a2, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->r6;
L_8001425C:
    // 0x8001425C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014260: slti        $v0, $a0, 0x13
    ctx->r2 = SIGNED(ctx->r4) < 0X13 ? 1 : 0;
    // 0x80014264: bne         $v0, $zero, L_8001423C
    if (ctx->r2 != 0) {
        // 0x80014268: addiu       $v1, $v1, 0x12
        ctx->r3 = ADD32(ctx->r3, 0X12);
            goto L_8001423C;
    }
    // 0x80014268: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
L_8001426C:
    // 0x8001426C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80014270:
    // 0x80014270: slti        $v0, $a2, 0xA
    ctx->r2 = SIGNED(ctx->r6) < 0XA ? 1 : 0;
    // 0x80014274: bne         $v0, $zero, L_80014238
    if (ctx->r2 != 0) {
        // 0x80014278: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80014238;
    }
    // 0x80014278: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8001427C: lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X3);
    // 0x80014280: lw          $v1, 0xE4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XE4);
    // 0x80014284: lw          $a0, 0xB0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB0);
    // 0x80014288: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001428C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80014290: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // 0x80014294: j           L_800144B0
    // 0x80014298: sb          $zero, 0x70($v1)
    MEM_B(0X70, ctx->r3) = 0;
        goto L_800144B0;
    // 0x80014298: sb          $zero, 0x70($v1)
    MEM_B(0X70, ctx->r3) = 0;
L_8001429C:
    // 0x8001429C: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x800142A0: addiu       $a1, $zero, 0x132
    ctx->r5 = ADD32(0, 0X132);
L_800142A4:
    // 0x800142A4: lw          $v0, 0xE4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XE4);
    // 0x800142A8: lw          $v1, 0xB0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB0);
    // 0x800142AC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800142B0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800142B4: lbu         $v1, 0x5E($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X5E);
    // 0x800142B8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800142BC: addiu       $a1, $a1, -0x12
    ctx->r5 = ADD32(ctx->r5, -0X12);
    // 0x800142C0: bgtz        $a0, L_800142A4
    if (SIGNED(ctx->r4) > 0) {
        // 0x800142C4: sb          $v1, 0x70($v0)
        MEM_B(0X70, ctx->r2) = ctx->r3;
            goto L_800142A4;
    }
    // 0x800142C4: sb          $v1, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r3;
    // 0x800142C8: lw          $v0, 0xE4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XE4);
    // 0x800142CC: lw          $v1, 0xB0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB0);
    // 0x800142D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800142D4: lbu         $v0, 0x1A2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1A2);
    // 0x800142D8: beq         $v0, $zero, L_80014388
    if (ctx->r2 == 0) {
        // 0x800142DC: nop
    
            goto L_80014388;
    }
    // 0x800142DC: nop

    // 0x800142E0: j           L_800144B0
    // 0x800142E4: nop

        goto L_800144B0;
    // 0x800142E4: nop

L_800142E8:
    // 0x800142E8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x800142EC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800142F0: lw          $a3, 0xB0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XB0);
    // 0x800142F4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800142F8:
    // 0x800142F8: addu        $v1, $a2, $a3
    ctx->r3 = ADD32(ctx->r6, ctx->r7);
L_800142FC:
    // 0x800142FC: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x80014300: beq         $v0, $zero, L_80014318
    if (ctx->r2 == 0) {
        // 0x80014304: slt         $v0, $a1, $a0
        ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80014318;
    }
    // 0x80014304: slt         $v0, $a1, $a0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80014308: beql        $v0, $zero, L_80014328
    if (ctx->r2 == 0) {
        // 0x8001430C: addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
            goto L_80014328;
    }
    goto skip_3;
    // 0x8001430C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    skip_3:
    // 0x80014310: j           L_8001432C
    // 0x80014314: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8001432C;
    // 0x80014314: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80014318:
    // 0x80014318: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001431C: slti        $v0, $a0, 0x12
    ctx->r2 = SIGNED(ctx->r4) < 0X12 ? 1 : 0;
    // 0x80014320: bne         $v0, $zero, L_800142FC
    if (ctx->r2 != 0) {
        // 0x80014324: addiu       $v1, $v1, 0x12
        ctx->r3 = ADD32(ctx->r3, 0X12);
            goto L_800142FC;
    }
    // 0x80014324: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
L_80014328:
    // 0x80014328: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8001432C:
    // 0x8001432C: slti        $v0, $a2, 0xA
    ctx->r2 = SIGNED(ctx->r6) < 0XA ? 1 : 0;
    // 0x80014330: bne         $v0, $zero, L_800142F8
    if (ctx->r2 != 0) {
        // 0x80014334: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800142F8;
    }
    // 0x80014334: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80014338: lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X3);
    // 0x8001433C: sb          $zero, 0x6B($s0)
    MEM_B(0X6B, ctx->r16) = 0;
    // 0x80014340: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80014344: jal         0x80012D8C
    // 0x80014348: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    func_80012D8C(rdram, ctx);
        goto after_1;
    // 0x80014348: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    after_1:
    // 0x8001434C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80014350: beq         $a0, $zero, L_800144B0
    if (ctx->r4 == 0) {
        // 0x80014354: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800144B0;
    }
    // 0x80014354: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80014358: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8001435C: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x80014360: sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
    // 0x80014364: lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5);
    // 0x80014368: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8001436C: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // 0x80014370: j           L_800144B0
    // 0x80014374: sb          $v1, 0x59($s0)
    MEM_B(0X59, ctx->r16) = ctx->r3;
        goto L_800144B0;
    // 0x80014374: sb          $v1, 0x59($s0)
    MEM_B(0X59, ctx->r16) = ctx->r3;
L_80014378:
    // 0x80014378: lb          $v1, 0x59($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X59);
    // 0x8001437C: addiu       $v0, $zero, 0x29
    ctx->r2 = ADD32(0, 0X29);
    // 0x80014380: bne         $v1, $v0, L_800144B0
    if (ctx->r3 != ctx->r2) {
        // 0x80014384: nop
    
            goto L_800144B0;
    }
    // 0x80014384: nop

L_80014388:
    // 0x80014388: lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X3);
    // 0x8001438C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80014390: j           L_800144B0
    // 0x80014394: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
        goto L_800144B0;
    // 0x80014394: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
L_80014398:
    // 0x80014398: lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X3);
    // 0x8001439C: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x800143A0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800143A4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800143A8: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    // 0x800143AC: jal         0x8000637C
    // 0x800143B0: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    func_8000637C(rdram, ctx);
        goto after_2;
    // 0x800143B0: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    after_2:
    // 0x800143B4: j           L_800144B0
    // 0x800143B8: nop

        goto L_800144B0;
    // 0x800143B8: nop

L_800143BC:
    // 0x800143BC: lb          $v1, 0x59($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X59);
    // 0x800143C0: addiu       $v0, $zero, 0x65
    ctx->r2 = ADD32(0, 0X65);
    // 0x800143C4: bne         $v1, $v0, L_800144B0
    if (ctx->r3 != ctx->r2) {
        // 0x800143C8: nop
    
            goto L_800144B0;
    }
    // 0x800143C8: nop

    // 0x800143CC: lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X3);
    // 0x800143D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800143D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800143D8: lbu         $v1, 0x74($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X74);
    // 0x800143DC: lbu         $a2, 0x64($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X64);
    // 0x800143E0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800143E4: addiu       $a0, $a0, -0x3998
    ctx->r4 = ADD32(ctx->r4, -0X3998);
    // 0x800143E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800143EC: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // 0x800143F0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800143F4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800143F8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800143FC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80014400: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80014404: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80014408: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8001440C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80014410: lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1);
    // 0x80014414: sltu        $v1, $v1, $v0
    ctx->r3 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80014418: beq         $v1, $zero, L_800144B0
    if (ctx->r3 == 0) {
        // 0x8001441C: addiu       $v0, $a2, 0x1
        ctx->r2 = ADD32(ctx->r6, 0X1);
            goto L_800144B0;
    }
    // 0x8001441C: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x80014420: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x80014424: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x80014428: sb          $v0, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r2;
    // 0x8001442C: jal         0x8000637C
    // 0x80014430: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_3;
    // 0x80014430: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_3:
    // 0x80014434: j           L_800144B0
    // 0x80014438: nop

        goto L_800144B0;
    // 0x80014438: nop

L_8001443C:
    // 0x8001443C: lbu         $v1, 0x74($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X74);
    // 0x80014440: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80014444: addiu       $a1, $a1, -0x3998
    ctx->r5 = ADD32(ctx->r5, -0X3998);
    // 0x80014448: lbu         $a0, 0x64($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X64);
    // 0x8001444C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80014450: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80014454: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80014458: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8001445C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80014460: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80014464: lbu         $v1, 0x66($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X66);
    // 0x80014468: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8001446C: bne         $v1, $v0, L_800144AC
    if (ctx->r3 != ctx->r2) {
        // 0x80014470: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_800144AC;
    }
    // 0x80014470: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80014474: lhu         $v0, 0x7C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7C);
    // 0x80014478: sltiu       $v0, $v0, 0x28
    ctx->r2 = ctx->r2 < 0X28 ? 1 : 0;
    // 0x8001447C: beq         $v0, $zero, L_80014488
    if (ctx->r2 == 0) {
        // 0x80014480: addiu       $v0, $zero, 0x28
        ctx->r2 = ADD32(0, 0X28);
            goto L_80014488;
    }
    // 0x80014480: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x80014484: sh          $v0, 0x7C($s0)
    MEM_H(0X7C, ctx->r16) = ctx->r2;
L_80014488:
    // 0x80014488: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001448C: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x80014490: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80014494: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x80014498: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x8001449C: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x800144A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800144A4: j           L_800144B0
    // 0x800144A8: sb          $v0, 0x7B8A($at)
    MEM_B(0X7B8A, ctx->r1) = ctx->r2;
        goto L_800144B0;
    // 0x800144A8: sb          $v0, 0x7B8A($at)
    MEM_B(0X7B8A, ctx->r1) = ctx->r2;
L_800144AC:
    // 0x800144AC: sb          $v0, 0x66($s0)
    MEM_B(0X66, ctx->r16) = ctx->r2;
L_800144B0:
    // 0x800144B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800144B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800144B8: jr          $ra
    // 0x800144BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800144BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800144C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800144C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800144C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800144C8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800144CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800144D0: lb          $v1, 0x3($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X3);
    // 0x800144D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800144D8: beq         $v1, $v0, L_8001450C
    if (ctx->r3 == ctx->r2) {
        // 0x800144DC: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_8001450C;
    }
    // 0x800144DC: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x800144E0: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800144E4: beql        $v0, $zero, L_800144FC
    if (ctx->r2 == 0) {
        // 0x800144E8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800144FC;
    }
    goto skip_0;
    // 0x800144E8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x800144EC: beq         $v1, $zero, L_80014600
    if (ctx->r3 == 0) {
        // 0x800144F0: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_80014600;
    }
    // 0x800144F0: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800144F4: j           L_80014604
    // 0x800144F8: nop

        goto L_80014604;
    // 0x800144F8: nop

L_800144FC:
    // 0x800144FC: beq         $v1, $v0, L_800145E8
    if (ctx->r3 == ctx->r2) {
        // 0x80014500: nop
    
            goto L_800145E8;
    }
    // 0x80014500: nop

    // 0x80014504: j           L_80014604
    // 0x80014508: nop

        goto L_80014604;
    // 0x80014508: nop

L_8001450C:
    // 0x8001450C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80014510: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
L_80014514:
    // 0x80014514: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80014518: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
L_8001451C:
    // 0x8001451C: lw          $v0, 0xB0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB0);
    // 0x80014520: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80014524: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80014528: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8001452C: bne         $v1, $zero, L_80014538
    if (ctx->r3 != 0) {
        // 0x80014530: sb          $v1, -0x12($v0)
        MEM_B(-0X12, ctx->r2) = ctx->r3;
            goto L_80014538;
    }
    // 0x80014530: sb          $v1, -0x12($v0)
    MEM_B(-0X12, ctx->r2) = ctx->r3;
    // 0x80014534: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
L_80014538:
    // 0x80014538: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001453C: slti        $v0, $a0, 0xE
    ctx->r2 = SIGNED(ctx->r4) < 0XE ? 1 : 0;
    // 0x80014540: bne         $v0, $zero, L_8001451C
    if (ctx->r2 != 0) {
        // 0x80014544: nop
    
            goto L_8001451C;
    }
    // 0x80014544: nop

    // 0x80014548: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8001454C: slti        $v0, $a3, 0x18
    ctx->r2 = SIGNED(ctx->r7) < 0X18 ? 1 : 0;
    // 0x80014550: bne         $v0, $zero, L_80014514
    if (ctx->r2 != 0) {
        // 0x80014554: addiu       $a2, $a2, 0x12
        ctx->r6 = ADD32(ctx->r6, 0X12);
            goto L_80014514;
    }
    // 0x80014554: addiu       $a2, $a2, 0x12
    ctx->r6 = ADD32(ctx->r6, 0X12);
    // 0x80014558: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8001455C: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_80014560:
    // 0x80014560: lw          $v0, 0xB0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB0);
    // 0x80014564: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80014568: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001456C: sb          $v1, 0x19E($v0)
    MEM_B(0X19E, ctx->r2) = ctx->r3;
    // 0x80014570: slti        $v0, $a0, 0xE
    ctx->r2 = SIGNED(ctx->r4) < 0XE ? 1 : 0;
    // 0x80014574: bne         $v0, $zero, L_80014560
    if (ctx->r2 != 0) {
        // 0x80014578: nop
    
            goto L_80014560;
    }
    // 0x80014578: nop

    // 0x8001457C: lw          $v0, 0xB0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB0);
    // 0x80014580: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80014584: sb          $zero, 0x19E($v0)
    MEM_B(0X19E, ctx->r2) = 0;
    // 0x80014588: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x8001458C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    // 0x80014590: jal         0x8000637C
    // 0x80014594: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_0;
    // 0x80014594: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_0:
    // 0x80014598: lbu         $v0, 0x5B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5B);
    // 0x8001459C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800145A0: sb          $v0, 0x5B($s0)
    MEM_B(0X5B, ctx->r16) = ctx->r2;
    // 0x800145A4: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800145A8: bne         $v0, $zero, L_800145D8
    if (ctx->r2 != 0) {
        // 0x800145AC: addiu       $v1, $zero, 0x5
        ctx->r3 = ADD32(0, 0X5);
            goto L_800145D8;
    }
    // 0x800145AC: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x800145B0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800145B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800145B8: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x800145BC: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x800145C0: jal         0x80016F44
    // 0x800145C4: sb          $v0, 0x49($s0)
    MEM_B(0X49, ctx->r16) = ctx->r2;
    func_80016F44(rdram, ctx);
        goto after_1;
    // 0x800145C4: sb          $v0, 0x49($s0)
    MEM_B(0X49, ctx->r16) = ctx->r2;
    after_1:
    // 0x800145C8: jal         0x8001628C
    // 0x800145CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001628C(rdram, ctx);
        goto after_2;
    // 0x800145CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800145D0: j           L_80014604
    // 0x800145D4: nop

        goto L_80014604;
    // 0x800145D4: nop

L_800145D8:
    // 0x800145D8: lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X3);
    // 0x800145DC: sw          $v1, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->r3;
    // 0x800145E0: j           L_80014600
    // 0x800145E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_80014600;
    // 0x800145E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800145E8:
    // 0x800145E8: lw          $v0, 0xE4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XE4);
    // 0x800145EC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800145F0: bne         $v0, $zero, L_80014604
    if (ctx->r2 != 0) {
        // 0x800145F4: sw          $v0, 0xE4($s0)
        MEM_W(0XE4, ctx->r16) = ctx->r2;
            goto L_80014604;
    }
    // 0x800145F4: sw          $v0, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->r2;
    // 0x800145F8: lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X3);
    // 0x800145FC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80014600:
    // 0x80014600: sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
L_80014604:
    // 0x80014604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80014608: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001460C: jr          $ra
    // 0x80014610: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80014610: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80014614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014614: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80014618: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x8001461C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_80014620:
    // 0x80014620: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80014624: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
L_80014628:
    // 0x80014628: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x8001462C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80014630: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80014634: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80014638: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x8001463C: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x80014640: bne         $v0, $zero, L_80014628
    if (ctx->r2 != 0) {
        // 0x80014644: nop
    
            goto L_80014628;
    }
    // 0x80014644: nop

    // 0x80014648: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001464C: slti        $v0, $a2, 0x1C
    ctx->r2 = SIGNED(ctx->r6) < 0X1C ? 1 : 0;
    // 0x80014650: bne         $v0, $zero, L_80014620
    if (ctx->r2 != 0) {
        // 0x80014654: addiu       $a3, $a3, 0x12
        ctx->r7 = ADD32(ctx->r7, 0X12);
            goto L_80014620;
    }
    // 0x80014654: addiu       $a3, $a3, 0x12
    ctx->r7 = ADD32(ctx->r7, 0X12);
    // 0x80014658: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8001465C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_80014660:
    // 0x80014660: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80014664: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
L_80014668:
    // 0x80014668: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x8001466C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80014670: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80014674: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80014678: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8001467C: slti        $v0, $a1, 0xE
    ctx->r2 = SIGNED(ctx->r5) < 0XE ? 1 : 0;
    // 0x80014680: bne         $v0, $zero, L_80014668
    if (ctx->r2 != 0) {
        // 0x80014684: nop
    
            goto L_80014668;
    }
    // 0x80014684: nop

    // 0x80014688: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001468C: slti        $v0, $a2, 0x18
    ctx->r2 = SIGNED(ctx->r6) < 0X18 ? 1 : 0;
    // 0x80014690: bne         $v0, $zero, L_80014660
    if (ctx->r2 != 0) {
        // 0x80014694: addiu       $a3, $a3, 0x12
        ctx->r7 = ADD32(ctx->r7, 0X12);
            goto L_80014660;
    }
    // 0x80014694: addiu       $a3, $a3, 0x12
    ctx->r7 = ADD32(ctx->r7, 0X12);
    // 0x80014698: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x8001469C: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x800146A0: addiu       $a3, $zero, 0x1B0
    ctx->r7 = ADD32(0, 0X1B0);
L_800146A4:
    // 0x800146A4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800146A8: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
L_800146AC:
    // 0x800146AC: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x800146B0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800146B4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800146B8: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800146BC: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x800146C0: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x800146C4: bne         $v0, $zero, L_800146AC
    if (ctx->r2 != 0) {
        // 0x800146C8: nop
    
            goto L_800146AC;
    }
    // 0x800146C8: nop

    // 0x800146CC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800146D0: slti        $v0, $a2, 0x1C
    ctx->r2 = SIGNED(ctx->r6) < 0X1C ? 1 : 0;
    // 0x800146D4: bne         $v0, $zero, L_800146A4
    if (ctx->r2 != 0) {
        // 0x800146D8: addiu       $a3, $a3, 0x12
        ctx->r7 = ADD32(ctx->r7, 0X12);
            goto L_800146A4;
    }
    // 0x800146D8: addiu       $a3, $a3, 0x12
    ctx->r7 = ADD32(ctx->r7, 0X12);
    // 0x800146DC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800146E0: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x800146E4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_800146E8:
    // 0x800146E8: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x800146EC: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
L_800146F0:
    // 0x800146F0: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x800146F4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800146F8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800146FC: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80014700: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x80014704: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x80014708: bne         $v0, $zero, L_800146F0
    if (ctx->r2 != 0) {
        // 0x8001470C: nop
    
            goto L_800146F0;
    }
    // 0x8001470C: nop

    // 0x80014710: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80014714: slti        $v0, $a2, 0x18
    ctx->r2 = SIGNED(ctx->r6) < 0X18 ? 1 : 0;
    // 0x80014718: bne         $v0, $zero, L_800146E8
    if (ctx->r2 != 0) {
        // 0x8001471C: addiu       $a3, $a3, 0x12
        ctx->r7 = ADD32(ctx->r7, 0X12);
            goto L_800146E8;
    }
    // 0x8001471C: addiu       $a3, $a3, 0x12
    ctx->r7 = ADD32(ctx->r7, 0X12);
    // 0x80014720: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80014724: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_80014728:
    // 0x80014728: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8001472C:
    // 0x8001472C: lw          $v1, 0x110($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X110);
    // 0x80014730: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x80014734: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80014738: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8001473C: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x80014740: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80014744: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80014748: addu        $v1, $a3, $v1
    ctx->r3 = ADD32(ctx->r7, ctx->r3);
    // 0x8001474C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80014750: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x80014754: bne         $v0, $zero, L_8001472C
    if (ctx->r2 != 0) {
        // 0x80014758: nop
    
            goto L_8001472C;
    }
    // 0x80014758: nop

    // 0x8001475C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80014760: slti        $v0, $a2, 0x1C
    ctx->r2 = SIGNED(ctx->r6) < 0X1C ? 1 : 0;
    // 0x80014764: bne         $v0, $zero, L_80014728
    if (ctx->r2 != 0) {
        // 0x80014768: addiu       $a3, $a3, 0x12
        ctx->r7 = ADD32(ctx->r7, 0X12);
            goto L_80014728;
    }
    // 0x80014768: addiu       $a3, $a3, 0x12
    ctx->r7 = ADD32(ctx->r7, 0X12);
    // 0x8001476C: jr          $ra
    // 0x80014770: nop

    return;
    // 0x80014770: nop

;}
RECOMP_FUNC void func_80014774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014774: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80014778: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001477C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80014780: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80014784: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80014788: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8001478C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80014790: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80014794: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80014798: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8001479C: addiu       $a3, $zero, 0x132
    ctx->r7 = ADD32(0, 0X132);
    // 0x800147A0: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800147A4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
L_800147A8:
    // 0x800147A8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800147AC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800147B0: lw          $a1, 0xB0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB0);
    // 0x800147B4: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
L_800147B8:
    // 0x800147B8: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800147BC: lbu         $v0, 0x70($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X70);
    // 0x800147C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800147C4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800147C8: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800147CC: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x800147D0: slti        $v0, $a0, 0xA
    ctx->r2 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x800147D4: bnel        $v0, $zero, L_800147B8
    if (ctx->r2 != 0) {
        // 0x800147D8: addu        $v0, $a0, $a1
        ctx->r2 = ADD32(ctx->r4, ctx->r5);
            goto L_800147B8;
    }
    goto skip_0;
    // 0x800147D8: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    skip_0:
    // 0x800147DC: beql        $v1, $zero, L_80014838
    if (ctx->r3 == 0) {
        // 0x800147E0: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_80014838;
    }
    goto skip_1;
    // 0x800147E0: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    skip_1:
    // 0x800147E4: bne         $s1, $t1, L_800147F0
    if (ctx->r17 != ctx->r9) {
        // 0x800147E8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800147F0;
    }
    // 0x800147E8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800147EC: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
L_800147F0:
    // 0x800147F0: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x800147F4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800147F8: addu        $a1, $a3, $zero
    ctx->r5 = ADD32(ctx->r7, 0);
L_800147FC:
    // 0x800147FC: lw          $v0, 0xB0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB0);
    // 0x80014800: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80014804: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80014808: lbu         $v1, 0x70($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X70);
    // 0x8001480C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80014810: ori         $v1, $v1, 0x80
    ctx->r3 = ctx->r3 | 0X80;
    // 0x80014814: sb          $v1, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r3;
    // 0x80014818: slti        $v0, $a0, 0xA
    ctx->r2 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x8001481C: bne         $v0, $zero, L_800147FC
    if (ctx->r2 != 0) {
        // 0x80014820: nop
    
            goto L_800147FC;
    }
    // 0x80014820: nop

    // 0x80014824: sb          $t0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r8;
    // 0x80014828: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x8001482C: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x80014830: sb          $zero, 0x6B($s0)
    MEM_B(0X6B, ctx->r16) = 0;
    // 0x80014834: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_80014838:
    // 0x80014838: slti        $v0, $a2, -0x5
    ctx->r2 = SIGNED(ctx->r6) < -0X5 ? 1 : 0;
    // 0x8001483C: beq         $v0, $zero, L_800147A8
    if (ctx->r2 == 0) {
        // 0x80014840: addiu       $a3, $a3, -0x12
        ctx->r7 = ADD32(ctx->r7, -0X12);
            goto L_800147A8;
    }
    // 0x80014840: addiu       $a3, $a3, -0x12
    ctx->r7 = ADD32(ctx->r7, -0X12);
    // 0x80014844: jal         0x8001504C
    // 0x80014848: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001504C(rdram, ctx);
        goto after_0;
    // 0x80014848: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8001484C: jal         0x80016F44
    // 0x80014850: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80016F44(rdram, ctx);
        goto after_1;
    // 0x80014850: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80014854: beq         $s2, $zero, L_80015018
    if (ctx->r18 == 0) {
        // 0x80014858: lui         $a1, 0x8888
        ctx->r5 = S32(0X8888 << 16);
            goto L_80015018;
    }
    // 0x80014858: lui         $a1, 0x8888
    ctx->r5 = S32(0X8888 << 16);
    // 0x8001485C: sw          $s2, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r18;
    // 0x80014860: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80014864: lbu         $a0, 0x7BA8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7BA8);
    // 0x80014868: ori         $a1, $a1, 0x8889
    ctx->r5 = ctx->r5 | 0X8889;
    // 0x8001486C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80014870: lbu         $v0, 0x7BA7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7BA7);
    // 0x80014874: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x80014878: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8001487C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80014880: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80014884: mult        $v1, $a1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80014888: mfhi        $t2
    ctx->r10 = hi;
    // 0x8001488C: addu        $v0, $t2, $v1
    ctx->r2 = ADD32(ctx->r10, ctx->r3);
    // 0x80014890: sra         $v0, $v0, 5
    ctx->r2 = S32(SIGNED(ctx->r2) >> 5);
    // 0x80014894: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x80014898: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8001489C: sb          $v0, 0x67($s0)
    MEM_B(0X67, ctx->r16) = ctx->r2;
    // 0x800148A0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800148A4: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x800148A8: bne         $v0, $zero, L_800148B8
    if (ctx->r2 != 0) {
        // 0x800148AC: addiu       $v1, $s2, -0x1
        ctx->r3 = ADD32(ctx->r18, -0X1);
            goto L_800148B8;
    }
    // 0x800148AC: addiu       $v1, $s2, -0x1
    ctx->r3 = ADD32(ctx->r18, -0X1);
    // 0x800148B0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800148B4: sb          $v0, 0x67($s0)
    MEM_B(0X67, ctx->r16) = ctx->r2;
L_800148B8:
    // 0x800148B8: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x800148BC: beq         $v0, $zero, L_80014BD4
    if (ctx->r2 == 0) {
        // 0x800148C0: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80014BD4;
    }
    // 0x800148C0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800148C4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800148C8: addu        $at, $at, $v0
    gpr jr_addend_800148D0 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800148CC: lw          $v0, -0x3110($at)
    ctx->r2 = ADD32(ctx->r1, -0X3110);
    // 0x800148D0: jr          $v0
    // 0x800148D4: nop

    switch (jr_addend_800148D0 >> 2) {
        case 0: goto L_800148D8; break;
        case 1: goto L_80014934; break;
        case 2: goto L_80014990; break;
        case 3: goto L_80014A18; break;
        case 4: goto L_80014B04; break;
        default: switch_error(__func__, 0x800148D0, 0x800ACEF0);
    }
    // 0x800148D4: nop

L_800148D8:
    // 0x800148D8: lhu         $v0, 0x7E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7E);
    // 0x800148DC: lw          $v1, 0xA4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA4);
    // 0x800148E0: lhu         $a0, 0x96($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X96);
    // 0x800148E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800148E8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800148EC: sh          $v0, 0x7E($s0)
    MEM_H(0X7E, ctx->r16) = ctx->r2;
    // 0x800148F0: sltiu       $v0, $a0, 0x270F
    ctx->r2 = ctx->r4 < 0X270F ? 1 : 0;
    // 0x800148F4: beq         $v0, $zero, L_80014904
    if (ctx->r2 == 0) {
        // 0x800148F8: sw          $v1, 0xA4($s0)
        MEM_W(0XA4, ctx->r16) = ctx->r3;
            goto L_80014904;
    }
    // 0x800148F8: sw          $v1, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->r3;
    // 0x800148FC: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80014900: sh          $v0, 0x96($s0)
    MEM_H(0X96, ctx->r16) = ctx->r2;
L_80014904:
    // 0x80014904: lw          $v1, 0x10C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10C);
    // 0x80014908: lhu         $a0, 0x86($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X86);
    // 0x8001490C: lbu         $a2, 0x6E($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X6E);
    // 0x80014910: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x80014914: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80014918: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001491C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80014920: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80014924: lw          $v1, 0x104($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X104);
    // 0x80014928: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001492C: j           L_800149F0
    // 0x80014930: addiu       $a0, $a0, 0x5
    ctx->r4 = ADD32(ctx->r4, 0X5);
        goto L_800149F0;
    // 0x80014930: addiu       $a0, $a0, 0x5
    ctx->r4 = ADD32(ctx->r4, 0X5);
L_80014934:
    // 0x80014934: lhu         $v0, 0x7E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7E);
    // 0x80014938: lw          $v1, 0xA4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA4);
    // 0x8001493C: lhu         $a0, 0x98($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X98);
    // 0x80014940: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80014944: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80014948: sh          $v0, 0x7E($s0)
    MEM_H(0X7E, ctx->r16) = ctx->r2;
    // 0x8001494C: sltiu       $v0, $a0, 0x270F
    ctx->r2 = ctx->r4 < 0X270F ? 1 : 0;
    // 0x80014950: beq         $v0, $zero, L_80014960
    if (ctx->r2 == 0) {
        // 0x80014954: sw          $v1, 0xA4($s0)
        MEM_W(0XA4, ctx->r16) = ctx->r3;
            goto L_80014960;
    }
    // 0x80014954: sw          $v1, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->r3;
    // 0x80014958: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8001495C: sh          $v0, 0x98($s0)
    MEM_H(0X98, ctx->r16) = ctx->r2;
L_80014960:
    // 0x80014960: lw          $v1, 0x10C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10C);
    // 0x80014964: lhu         $a0, 0x86($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X86);
    // 0x80014968: lbu         $a2, 0x6E($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X6E);
    // 0x8001496C: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x80014970: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x80014974: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80014978: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001497C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80014980: lw          $v1, 0x104($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X104);
    // 0x80014984: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80014988: j           L_800149F0
    // 0x8001498C: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
        goto L_800149F0;
    // 0x8001498C: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
L_80014990:
    // 0x80014990: lhu         $v0, 0x7E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7E);
    // 0x80014994: lw          $v1, 0xA4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA4);
    // 0x80014998: lhu         $a0, 0x9A($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X9A);
    // 0x8001499C: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x800149A0: addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // 0x800149A4: sh          $v0, 0x7E($s0)
    MEM_H(0X7E, ctx->r16) = ctx->r2;
    // 0x800149A8: sltiu       $v0, $a0, 0x270F
    ctx->r2 = ctx->r4 < 0X270F ? 1 : 0;
    // 0x800149AC: beq         $v0, $zero, L_800149BC
    if (ctx->r2 == 0) {
        // 0x800149B0: sw          $v1, 0xA4($s0)
        MEM_W(0XA4, ctx->r16) = ctx->r3;
            goto L_800149BC;
    }
    // 0x800149B0: sw          $v1, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->r3;
    // 0x800149B4: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800149B8: sh          $v0, 0x9A($s0)
    MEM_H(0X9A, ctx->r16) = ctx->r2;
L_800149BC:
    // 0x800149BC: lw          $v1, 0x10C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10C);
    // 0x800149C0: lhu         $a0, 0x86($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X86);
    // 0x800149C4: lbu         $a2, 0x6E($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X6E);
    // 0x800149C8: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x800149CC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800149D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800149D4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800149D8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800149DC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800149E0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800149E4: lw          $v1, 0x104($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X104);
    // 0x800149E8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800149EC: addiu       $a0, $a0, 0xF
    ctx->r4 = ADD32(ctx->r4, 0XF);
L_800149F0:
    // 0x800149F0: sh          $a0, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r4;
    // 0x800149F4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800149F8: sw          $v1, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->r3;
    // 0x800149FC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80014A00: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x80014A04: lb          $a0, 0x15C8($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X15C8);
    // 0x80014A08: jal         0x8000637C
    // 0x80014A0C: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_2;
    // 0x80014A0C: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_2:
    // 0x80014A10: j           L_80014BD4
    // 0x80014A14: nop

        goto L_80014BD4;
    // 0x80014A14: nop

L_80014A18:
    // 0x80014A18: lb          $v1, 0x5A($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X5A);
    // 0x80014A1C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80014A20: beq         $v1, $v0, L_80014A30
    if (ctx->r3 == ctx->r2) {
        // 0x80014A24: addiu       $v0, $zero, 0x1E
        ctx->r2 = ADD32(0, 0X1E);
            goto L_80014A30;
    }
    // 0x80014A24: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x80014A28: lw          $v1, 0xD0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XD0);
    // 0x80014A2C: sb          $v0, 0x50($v1)
    MEM_B(0X50, ctx->r3) = ctx->r2;
L_80014A30:
    // 0x80014A30: lw          $a0, 0x10C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10C);
    // 0x80014A34: lw          $v1, 0x104($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X104);
    // 0x80014A38: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80014A3C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80014A40: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80014A44: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80014A48: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80014A4C: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80014A50: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80014A54: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80014A58: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x80014A5C: sw          $v1, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->r3;
    // 0x80014A60: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80014A64: sw          $v0, -0x761C($at)
    MEM_W(-0X761C, ctx->r1) = ctx->r2;
    // 0x80014A68: lhu         $v0, 0x86($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X86);
    // 0x80014A6C: addiu       $v0, $v0, 0x64
    ctx->r2 = ADD32(ctx->r2, 0X64);
    // 0x80014A70: sh          $v0, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r2;
    // 0x80014A74: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80014A78: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80014A7C: slti        $v0, $v0, 0x2711
    ctx->r2 = SIGNED(ctx->r2) < 0X2711 ? 1 : 0;
    // 0x80014A80: bne         $v0, $zero, L_80014A8C
    if (ctx->r2 != 0) {
        // 0x80014A84: addiu       $v0, $zero, 0x2710
        ctx->r2 = ADD32(0, 0X2710);
            goto L_80014A8C;
    }
    // 0x80014A84: addiu       $v0, $zero, 0x2710
    ctx->r2 = ADD32(0, 0X2710);
    // 0x80014A88: sh          $v0, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r2;
L_80014A8C:
    // 0x80014A8C: lw          $a0, 0xD0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XD0);
    // 0x80014A90: jal         0x80016FCC
    // 0x80014A94: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_80016FCC(rdram, ctx);
        goto after_3;
    // 0x80014A94: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_3:
    // 0x80014A98: lhu         $v0, 0x7E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7E);
    // 0x80014A9C: lw          $v1, 0xA4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA4);
    // 0x80014AA0: lhu         $a0, 0x9C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X9C);
    // 0x80014AA4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80014AA8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80014AAC: sh          $v0, 0x7E($s0)
    MEM_H(0X7E, ctx->r16) = ctx->r2;
    // 0x80014AB0: sltiu       $v0, $a0, 0x270F
    ctx->r2 = ctx->r4 < 0X270F ? 1 : 0;
    // 0x80014AB4: beq         $v0, $zero, L_80014AC4
    if (ctx->r2 == 0) {
        // 0x80014AB8: sw          $v1, 0xA4($s0)
        MEM_W(0XA4, ctx->r16) = ctx->r3;
            goto L_80014AC4;
    }
    // 0x80014AB8: sw          $v1, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->r3;
    // 0x80014ABC: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80014AC0: sh          $v0, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r2;
L_80014AC4:
    // 0x80014AC4: lbu         $v0, 0x6F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6F);
    // 0x80014AC8: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x80014ACC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80014AD0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80014AD4: lb          $a0, 0x15CC($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X15CC);
    // 0x80014AD8: jal         0x8000637C
    // 0x80014ADC: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_4;
    // 0x80014ADC: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_4:
    // 0x80014AE0: lbu         $v0, 0x6F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6F);
    // 0x80014AE4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80014AE8: sb          $v0, 0x6F($s0)
    MEM_B(0X6F, ctx->r16) = ctx->r2;
    // 0x80014AEC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80014AF0: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x80014AF4: beql        $v0, $zero, L_80014BC0
    if (ctx->r2 == 0) {
        // 0x80014AF8: sb          $zero, 0x6F($s0)
        MEM_B(0X6F, ctx->r16) = 0;
            goto L_80014BC0;
    }
    goto skip_2;
    // 0x80014AF8: sb          $zero, 0x6F($s0)
    MEM_B(0X6F, ctx->r16) = 0;
    skip_2:
    // 0x80014AFC: j           L_80014BC4
    // 0x80014B00: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80014BC4;
    // 0x80014B00: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80014B04:
    // 0x80014B04: lb          $v1, 0x5A($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X5A);
    // 0x80014B08: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80014B0C: beq         $v1, $v0, L_80014B1C
    if (ctx->r3 == ctx->r2) {
        // 0x80014B10: addiu       $v0, $zero, 0x3C
        ctx->r2 = ADD32(0, 0X3C);
            goto L_80014B1C;
    }
    // 0x80014B10: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x80014B14: lw          $v1, 0xD0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XD0);
    // 0x80014B18: sb          $v0, 0x50($v1)
    MEM_B(0X50, ctx->r3) = ctx->r2;
L_80014B1C:
    // 0x80014B1C: lw          $a0, 0x10C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10C);
    // 0x80014B20: lw          $v1, 0x104($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X104);
    // 0x80014B24: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80014B28: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80014B2C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80014B30: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80014B34: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80014B38: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80014B3C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80014B40: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80014B44: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x80014B48: sw          $v1, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->r3;
    // 0x80014B4C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80014B50: sw          $v0, -0x761C($at)
    MEM_W(-0X761C, ctx->r1) = ctx->r2;
    // 0x80014B54: lhu         $v0, 0x86($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X86);
    // 0x80014B58: addiu       $v0, $v0, 0x96
    ctx->r2 = ADD32(ctx->r2, 0X96);
    // 0x80014B5C: sh          $v0, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r2;
    // 0x80014B60: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80014B64: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80014B68: slti        $v0, $v0, 0x2711
    ctx->r2 = SIGNED(ctx->r2) < 0X2711 ? 1 : 0;
    // 0x80014B6C: bne         $v0, $zero, L_80014B78
    if (ctx->r2 != 0) {
        // 0x80014B70: addiu       $v0, $zero, 0x2710
        ctx->r2 = ADD32(0, 0X2710);
            goto L_80014B78;
    }
    // 0x80014B70: addiu       $v0, $zero, 0x2710
    ctx->r2 = ADD32(0, 0X2710);
    // 0x80014B74: sh          $v0, 0x86($s0)
    MEM_H(0X86, ctx->r16) = ctx->r2;
L_80014B78:
    // 0x80014B78: lw          $a0, 0xD0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XD0);
    // 0x80014B7C: jal         0x80016FCC
    // 0x80014B80: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    func_80016FCC(rdram, ctx);
        goto after_5;
    // 0x80014B80: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    after_5:
    // 0x80014B84: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x80014B88: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80014B8C: jal         0x8000637C
    // 0x80014B90: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_6;
    // 0x80014B90: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_6:
    // 0x80014B94: lhu         $v0, 0x7E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7E);
    // 0x80014B98: lw          $v1, 0xA4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA4);
    // 0x80014B9C: lhu         $a0, 0x9E($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X9E);
    // 0x80014BA0: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // 0x80014BA4: addiu       $v1, $v1, 0x5
    ctx->r3 = ADD32(ctx->r3, 0X5);
    // 0x80014BA8: sh          $v0, 0x7E($s0)
    MEM_H(0X7E, ctx->r16) = ctx->r2;
    // 0x80014BAC: sltiu       $v0, $a0, 0x270F
    ctx->r2 = ctx->r4 < 0X270F ? 1 : 0;
    // 0x80014BB0: beq         $v0, $zero, L_80014BC0
    if (ctx->r2 == 0) {
        // 0x80014BB4: sw          $v1, 0xA4($s0)
        MEM_W(0XA4, ctx->r16) = ctx->r3;
            goto L_80014BC0;
    }
    // 0x80014BB4: sw          $v1, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->r3;
    // 0x80014BB8: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80014BBC: sh          $v0, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = ctx->r2;
L_80014BC0:
    // 0x80014BC0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80014BC4:
    // 0x80014BC4: sll         $a1, $s3, 3
    ctx->r5 = S32(ctx->r19 << 3);
    // 0x80014BC8: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    // 0x80014BCC: jal         0x8002EAE0
    // 0x80014BD0: andi        $a1, $a1, 0xF8
    ctx->r5 = ctx->r5 & 0XF8;
    func_8002EAE0(rdram, ctx);
        goto after_7;
    // 0x80014BD0: andi        $a1, $a1, 0xF8
    ctx->r5 = ctx->r5 & 0XF8;
    after_7:
L_80014BD4:
    // 0x80014BD4: lw          $v0, 0x104($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X104);
    // 0x80014BD8: lui         $v1, 0x3B9A
    ctx->r3 = S32(0X3B9A << 16);
    // 0x80014BDC: ori         $v1, $v1, 0xC9FF
    ctx->r3 = ctx->r3 | 0XC9FF;
    // 0x80014BE0: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80014BE4: bnel        $v0, $zero, L_80014BEC
    if (ctx->r2 != 0) {
        // 0x80014BE8: sw          $v1, 0x104($s0)
        MEM_W(0X104, ctx->r16) = ctx->r3;
            goto L_80014BEC;
    }
    goto skip_3;
    // 0x80014BE8: sw          $v1, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->r3;
    skip_3:
L_80014BEC:
    // 0x80014BEC: lw          $v0, 0x10C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10C);
    // 0x80014BF0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80014BF4: sw          $v0, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->r2;
    // 0x80014BF8: lbu         $v0, 0x72($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X72);
    // 0x80014BFC: lw          $v1, 0x10C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10C);
    // 0x80014C00: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80014C04: sb          $v0, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r2;
    // 0x80014C08: lui         $v0, 0x10
    ctx->r2 = S32(0X10 << 16);
    // 0x80014C0C: sltu        $v1, $v0, $v1
    ctx->r3 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80014C10: bnel        $v1, $zero, L_80014C18
    if (ctx->r3 != 0) {
        // 0x80014C14: sw          $v0, 0x10C($s0)
        MEM_W(0X10C, ctx->r16) = ctx->r2;
            goto L_80014C18;
    }
    goto skip_4;
    // 0x80014C14: sw          $v0, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->r2;
    skip_4:
L_80014C18:
    // 0x80014C18: lbu         $v0, 0x72($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X72);
    // 0x80014C1C: sltiu       $v0, $v0, 0x64
    ctx->r2 = ctx->r2 < 0X64 ? 1 : 0;
    // 0x80014C20: bne         $v0, $zero, L_80014C2C
    if (ctx->r2 != 0) {
        // 0x80014C24: addiu       $v0, $zero, 0x63
        ctx->r2 = ADD32(0, 0X63);
            goto L_80014C2C;
    }
    // 0x80014C24: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x80014C28: sb          $v0, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r2;
L_80014C2C:
    // 0x80014C2C: lbu         $v1, 0x72($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X72);
    // 0x80014C30: lbu         $v0, 0x73($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X73);
    // 0x80014C34: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80014C38: bnel        $v0, $zero, L_80014C40
    if (ctx->r2 != 0) {
        // 0x80014C3C: sb          $v1, 0x73($s0)
        MEM_B(0X73, ctx->r16) = ctx->r3;
            goto L_80014C40;
    }
    goto skip_5;
    // 0x80014C3C: sb          $v1, 0x73($s0)
    MEM_B(0X73, ctx->r16) = ctx->r3;
    skip_5:
L_80014C40:
    // 0x80014C40: lbu         $v1, 0x72($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X72);
    // 0x80014C44: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80014C48: bnel        $v1, $v0, L_80014C5C
    if (ctx->r3 != ctx->r2) {
        // 0x80014C4C: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_80014C5C;
    }
    goto skip_6;
    // 0x80014C4C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    skip_6:
    // 0x80014C50: lhu         $v0, 0x88($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X88);
    // 0x80014C54: j           L_80014C94
    // 0x80014C58: addiu       $v0, $v0, 0xC8
    ctx->r2 = ADD32(ctx->r2, 0XC8);
        goto L_80014C94;
    // 0x80014C58: addiu       $v0, $v0, 0xC8
    ctx->r2 = ADD32(ctx->r2, 0XC8);
L_80014C5C:
    // 0x80014C5C: bnel        $v1, $v0, L_80014C70
    if (ctx->r3 != ctx->r2) {
        // 0x80014C60: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_80014C70;
    }
    goto skip_7;
    // 0x80014C60: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    skip_7:
    // 0x80014C64: lhu         $v0, 0x88($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X88);
    // 0x80014C68: j           L_80014C94
    // 0x80014C6C: addiu       $v0, $v0, 0x12C
    ctx->r2 = ADD32(ctx->r2, 0X12C);
        goto L_80014C94;
    // 0x80014C6C: addiu       $v0, $v0, 0x12C
    ctx->r2 = ADD32(ctx->r2, 0X12C);
L_80014C70:
    // 0x80014C70: bnel        $v1, $v0, L_80014C84
    if (ctx->r3 != ctx->r2) {
        // 0x80014C74: sltiu       $v0, $v1, 0x7
        ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
            goto L_80014C84;
    }
    goto skip_8;
    // 0x80014C74: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    skip_8:
    // 0x80014C78: lhu         $v0, 0x88($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X88);
    // 0x80014C7C: j           L_80014C94
    // 0x80014C80: addiu       $v0, $v0, 0x190
    ctx->r2 = ADD32(ctx->r2, 0X190);
        goto L_80014C94;
    // 0x80014C80: addiu       $v0, $v0, 0x190
    ctx->r2 = ADD32(ctx->r2, 0X190);
L_80014C84:
    // 0x80014C84: bne         $v0, $zero, L_80014C98
    if (ctx->r2 != 0) {
        // 0x80014C88: nop
    
            goto L_80014C98;
    }
    // 0x80014C88: nop

    // 0x80014C8C: lhu         $v0, 0x88($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X88);
    // 0x80014C90: addiu       $v0, $v0, 0x258
    ctx->r2 = ADD32(ctx->r2, 0X258);
L_80014C94:
    // 0x80014C94: sh          $v0, 0x88($s0)
    MEM_H(0X88, ctx->r16) = ctx->r2;
L_80014C98:
    // 0x80014C98: lh          $v0, 0x88($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X88);
    // 0x80014C9C: slti        $v0, $v0, 0x2711
    ctx->r2 = SIGNED(ctx->r2) < 0X2711 ? 1 : 0;
    // 0x80014CA0: bne         $v0, $zero, L_80014CAC
    if (ctx->r2 != 0) {
        // 0x80014CA4: addiu       $v0, $zero, 0x2710
        ctx->r2 = ADD32(0, 0X2710);
            goto L_80014CAC;
    }
    // 0x80014CA4: addiu       $v0, $zero, 0x2710
    ctx->r2 = ADD32(0, 0X2710);
    // 0x80014CA8: sh          $v0, 0x88($s0)
    MEM_H(0X88, ctx->r16) = ctx->r2;
L_80014CAC:
    // 0x80014CAC: lbu         $v0, 0x72($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X72);
    // 0x80014CB0: sltiu       $v0, $v0, 0x5
    ctx->r2 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x80014CB4: bne         $v0, $zero, L_80014CC4
    if (ctx->r2 != 0) {
        // 0x80014CB8: addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
            goto L_80014CC4;
    }
    // 0x80014CB8: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x80014CBC: lw          $v1, 0xD4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XD4);
    // 0x80014CC0: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
L_80014CC4:
    // 0x80014CC4: lbu         $v0, 0x6E($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6E);
    // 0x80014CC8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80014CCC: sb          $v0, 0x6E($s0)
    MEM_B(0X6E, ctx->r16) = ctx->r2;
    // 0x80014CD0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80014CD4: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x80014CD8: beql        $v0, $zero, L_80014CE0
    if (ctx->r2 == 0) {
        // 0x80014CDC: sb          $zero, 0x6E($s0)
        MEM_B(0X6E, ctx->r16) = 0;
            goto L_80014CE0;
    }
    goto skip_9;
    // 0x80014CDC: sb          $zero, 0x6E($s0)
    MEM_B(0X6E, ctx->r16) = 0;
    skip_9:
L_80014CE0:
    // 0x80014CE0: lhu         $v0, 0x7E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7E);
    // 0x80014CE4: sltiu       $v0, $v0, 0x2710
    ctx->r2 = ctx->r2 < 0X2710 ? 1 : 0;
    // 0x80014CE8: bne         $v0, $zero, L_80014CF4
    if (ctx->r2 != 0) {
        // 0x80014CEC: addiu       $v0, $zero, 0x270F
        ctx->r2 = ADD32(0, 0X270F);
            goto L_80014CF4;
    }
    // 0x80014CEC: addiu       $v0, $zero, 0x270F
    ctx->r2 = ADD32(0, 0X270F);
    // 0x80014CF0: sh          $v0, 0x7E($s0)
    MEM_H(0X7E, ctx->r16) = ctx->r2;
L_80014CF4:
    // 0x80014CF4: lw          $v0, 0xA4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA4);
    // 0x80014CF8: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80014CFC: ori         $v1, $v1, 0x869F
    ctx->r3 = ctx->r3 | 0X869F;
    // 0x80014D00: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80014D04: bnel        $v0, $zero, L_80014D0C
    if (ctx->r2 != 0) {
        // 0x80014D08: sw          $v1, 0xA4($s0)
        MEM_W(0XA4, ctx->r16) = ctx->r3;
            goto L_80014D0C;
    }
    goto skip_10;
    // 0x80014D08: sw          $v1, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->r3;
    skip_10:
L_80014D0C:
    // 0x80014D0C: slti        $v0, $s2, 0x4
    ctx->r2 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x80014D10: bne         $v0, $zero, L_80014D64
    if (ctx->r2 != 0) {
        // 0x80014D14: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80014D64;
    }
    // 0x80014D14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80014D18: lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5);
    // 0x80014D1C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80014D20: andi        $a0, $v0, 0x1
    ctx->r4 = ctx->r2 & 0X1;
    // 0x80014D24: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x80014D28: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80014D2C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80014D30: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80014D34: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80014D38: sb          $v1, -0x66CD($at)
    MEM_B(-0X66CD, ctx->r1) = ctx->r3;
    // 0x80014D3C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80014D40: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80014D44: sw          $a0, -0x66B4($at)
    MEM_W(-0X66B4, ctx->r1) = ctx->r4;
    // 0x80014D48: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80014D4C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80014D50: sw          $s2, -0x66B0($at)
    MEM_W(-0X66B0, ctx->r1) = ctx->r18;
    // 0x80014D54: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80014D58: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80014D5C: sw          $s1, -0x66AC($at)
    MEM_W(-0X66AC, ctx->r1) = ctx->r17;
    // 0x80014D60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80014D64:
    // 0x80014D64: bne         $s2, $v0, L_80014D7C
    if (ctx->r18 != ctx->r2) {
        // 0x80014D68: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_80014D7C;
    }
    // 0x80014D68: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80014D6C: lb          $v1, 0xCC($s0)
    ctx->r3 = MEM_B(ctx->r16, 0XCC);
    // 0x80014D70: lb          $v0, 0xCD($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XCD);
    // 0x80014D74: beq         $v1, $v0, L_80014E04
    if (ctx->r3 == ctx->r2) {
        // 0x80014D78: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_80014E04;
    }
    // 0x80014D78: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80014D7C:
    // 0x80014D7C: bne         $s2, $v0, L_80014D8C
    if (ctx->r18 != ctx->r2) {
        // 0x80014D80: xori        $v0, $s2, 0x4
        ctx->r2 = ctx->r18 ^ 0X4;
            goto L_80014D8C;
    }
    // 0x80014D80: xori        $v0, $s2, 0x4
    ctx->r2 = ctx->r18 ^ 0X4;
    // 0x80014D84: j           L_80014D90
    // 0x80014D88: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_80014D90;
    // 0x80014D88: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_80014D8C:
    // 0x80014D8C: sltiu       $a0, $v0, 0x1
    ctx->r4 = ctx->r2 < 0X1 ? 1 : 0;
L_80014D90:
    // 0x80014D90: lw          $v1, 0xD4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XD4);
    // 0x80014D94: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80014D98: addu        $s1, $v0, $a0
    ctx->r17 = ADD32(ctx->r2, ctx->r4);
    // 0x80014D9C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80014DA0: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80014DA4: lbu         $v0, 0x15D0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X15D0);
    // 0x80014DA8: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // 0x80014DAC: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    // 0x80014DB0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80014DB4: addu        $a1, $a1, $s1
    ctx->r5 = ADD32(ctx->r5, ctx->r17);
    // 0x80014DB8: lb          $a1, 0x15D2($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X15D2);
    // 0x80014DBC: xori        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 ^ 0X1;
    // 0x80014DC0: jal         0x8001C0D0
    // 0x80014DC4: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    func_8001C0D0(rdram, ctx);
        goto after_8;
    // 0x80014DC4: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    after_8:
    // 0x80014DC8: lb          $v1, 0x5A($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X5A);
    // 0x80014DCC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80014DD0: beq         $v1, $v0, L_8001502C
    if (ctx->r3 == ctx->r2) {
        // 0x80014DD4: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_8001502C;
    }
    // 0x80014DD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80014DD8: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80014DDC: lw          $v1, 0xD4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XD4);
    // 0x80014DE0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80014DE4: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80014DE8: lbu         $v0, 0x15D1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X15D1);
    // 0x80014DEC: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // 0x80014DF0: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80014DF4: lbu         $a0, 0x5($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X5);
    // 0x80014DF8: xori        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 ^ 0X1;
    // 0x80014DFC: jal         0x8001C0D0
    // 0x80014E00: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    func_8001C0D0(rdram, ctx);
        goto after_9;
    // 0x80014E00: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    after_9:
L_80014E04:
    // 0x80014E04: lb          $v0, 0x5A($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5A);
    // 0x80014E08: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80014E0C: beq         $v0, $s1, L_80015030
    if (ctx->r2 == ctx->r17) {
        // 0x80014E10: addu        $v0, $s2, $zero
        ctx->r2 = ADD32(ctx->r18, 0);
            goto L_80015030;
    }
    // 0x80014E10: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x80014E14: jal         0x80012D30
    // 0x80014E18: nop

    func_80012D30(rdram, ctx);
        goto after_10;
    // 0x80014E18: nop

    after_10:
    // 0x80014E1C: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80014E20: beq         $a2, $zero, L_8001502C
    if (ctx->r6 == 0) {
        // 0x80014E24: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8001502C;
    }
    // 0x80014E24: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80014E28: sb          $v1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r3;
    // 0x80014E2C: sb          $zero, 0x3($a2)
    MEM_B(0X3, ctx->r6) = 0;
    // 0x80014E30: sb          $zero, 0x2($a2)
    MEM_B(0X2, ctx->r6) = 0;
    // 0x80014E34: sb          $zero, 0x1($a2)
    MEM_B(0X1, ctx->r6) = 0;
    // 0x80014E38: lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5);
    // 0x80014E3C: lui         $at, 0x4294
    ctx->r1 = S32(0X4294 << 16);
    // 0x80014E40: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80014E44: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80014E48: beq         $v0, $zero, L_80014E58
    if (ctx->r2 == 0) {
        // 0x80014E4C: sll         $v0, $s3, 3
        ctx->r2 = S32(ctx->r19 << 3);
            goto L_80014E58;
    }
    // 0x80014E4C: sll         $v0, $s3, 3
    ctx->r2 = S32(ctx->r19 << 3);
    // 0x80014E50: lui         $at, 0x4376
    ctx->r1 = S32(0X4376 << 16);
    // 0x80014E54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80014E58:
    // 0x80014E58: addiu       $v0, $v0, 0x48
    ctx->r2 = ADD32(ctx->r2, 0X48);
    // 0x80014E5C: swc1        $f0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f0.u32l;
    // 0x80014E60: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80014E64: nop

    // 0x80014E68: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80014E6C: swc1        $f0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f0.u32l;
    // 0x80014E70: sb          $zero, 0x5($a2)
    MEM_B(0X5, ctx->r6) = 0;
    // 0x80014E74: lbu         $v0, 0x5A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5A);
    // 0x80014E78: sb          $v0, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r2;
    // 0x80014E7C: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80014E80: sb          $s2, 0x8($a2)
    MEM_B(0X8, ctx->r6) = ctx->r18;
    // 0x80014E84: sw          $v0, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r2;
    // 0x80014E88: lbu         $v0, 0x67($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X67);
    // 0x80014E8C: sb          $v0, 0x7($a2)
    MEM_B(0X7, ctx->r6) = ctx->r2;
    // 0x80014E90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80014E94: bne         $s2, $v0, L_80014F7C
    if (ctx->r18 != ctx->r2) {
        // 0x80014E98: nop
    
            goto L_80014F7C;
    }
    // 0x80014E98: nop

    // 0x80014E9C: lb          $v0, 0x5A($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5A);
    // 0x80014EA0: bnel        $v0, $zero, L_80014EE0
    if (ctx->r2 != 0) {
        // 0x80014EA4: sb          $zero, 0xC($a2)
        MEM_B(0XC, ctx->r6) = 0;
            goto L_80014EE0;
    }
    goto skip_11;
    // 0x80014EA4: sb          $zero, 0xC($a2)
    MEM_B(0XC, ctx->r6) = 0;
    skip_11:
    // 0x80014EA8: lbu         $v0, 0x67($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X67);
    // 0x80014EAC: beql        $v0, $zero, L_80014EB4
    if (ctx->r2 == 0) {
        // 0x80014EB0: sb          $zero, 0xC($a2)
        MEM_B(0XC, ctx->r6) = 0;
            goto L_80014EB4;
    }
    goto skip_12;
    // 0x80014EB0: sb          $zero, 0xC($a2)
    MEM_B(0XC, ctx->r6) = 0;
    skip_12:
L_80014EB4:
    // 0x80014EB4: lbu         $v0, 0x67($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X67);
    // 0x80014EB8: beql        $v0, $s2, L_80014EC0
    if (ctx->r2 == ctx->r18) {
        // 0x80014EBC: sb          $v1, 0xC($a2)
        MEM_B(0XC, ctx->r6) = ctx->r3;
            goto L_80014EC0;
    }
    goto skip_13;
    // 0x80014EBC: sb          $v1, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r3;
    skip_13:
L_80014EC0:
    // 0x80014EC0: lbu         $v0, 0x67($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X67);
    // 0x80014EC4: beql        $v0, $s1, L_80014ECC
    if (ctx->r2 == ctx->r17) {
        // 0x80014EC8: sb          $v1, 0xC($a2)
        MEM_B(0XC, ctx->r6) = ctx->r3;
            goto L_80014ECC;
    }
    goto skip_14;
    // 0x80014EC8: sb          $v1, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r3;
    skip_14:
L_80014ECC:
    // 0x80014ECC: lbu         $v1, 0x67($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X67);
    // 0x80014ED0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80014ED4: bne         $v1, $v0, L_80014EE0
    if (ctx->r3 != ctx->r2) {
        // 0x80014ED8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80014EE0;
    }
    // 0x80014ED8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80014EDC: sb          $v0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r2;
L_80014EE0:
    // 0x80014EE0: lbu         $v0, 0x72($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X72);
    // 0x80014EE4: lbu         $v1, 0xC($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0XC);
    // 0x80014EE8: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80014EEC: bne         $v0, $zero, L_80014EF8
    if (ctx->r2 != 0) {
        // 0x80014EF0: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_80014EF8;
    }
    // 0x80014EF0: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80014EF4: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_80014EF8:
    // 0x80014EF8: sb          $v0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r2;
    // 0x80014EFC: lb          $v0, 0x5A($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5A);
    // 0x80014F00: bne         $v0, $zero, L_80014F18
    if (ctx->r2 != 0) {
        // 0x80014F04: nop
    
            goto L_80014F18;
    }
    // 0x80014F04: nop

    // 0x80014F08: lbu         $v0, 0x74($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X74);
    // 0x80014F0C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80014F10: j           L_80014F48
    // 0x80014F14: addiu       $a1, $a1, -0x3D5C
    ctx->r5 = ADD32(ctx->r5, -0X3D5C);
        goto L_80014F48;
    // 0x80014F14: addiu       $a1, $a1, -0x3D5C
    ctx->r5 = ADD32(ctx->r5, -0X3D5C);
L_80014F18:
    // 0x80014F18: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80014F1C: lb          $v0, 0x5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5);
    // 0x80014F20: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80014F24: beq         $v0, $zero, L_80014F3C
    if (ctx->r2 == 0) {
        // 0x80014F28: nop
    
            goto L_80014F3C;
    }
    // 0x80014F28: nop

    // 0x80014F2C: lbu         $v0, 0x74($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X74);
    // 0x80014F30: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80014F34: j           L_80014F48
    // 0x80014F38: addiu       $a1, $a1, -0x3BA4
    ctx->r5 = ADD32(ctx->r5, -0X3BA4);
        goto L_80014F48;
    // 0x80014F38: addiu       $a1, $a1, -0x3BA4
    ctx->r5 = ADD32(ctx->r5, -0X3BA4);
L_80014F3C:
    // 0x80014F3C: lbu         $v0, 0x74($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X74);
    // 0x80014F40: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80014F44: addiu       $a1, $a1, -0x3C80
    ctx->r5 = ADD32(ctx->r5, -0X3C80);
L_80014F48:
    // 0x80014F48: lbu         $a0, 0x67($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X67);
    // 0x80014F4C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80014F50: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80014F54: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80014F58: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80014F5C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80014F60: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80014F64: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80014F68: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80014F6C: lbu         $v0, -0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1);
    // 0x80014F70: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80014F74: j           L_8001502C
    // 0x80014F78: sb          $v0, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r2;
        goto L_8001502C;
    // 0x80014F78: sb          $v0, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r2;
L_80014F7C:
    // 0x80014F7C: lb          $v0, 0x5A($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5A);
    // 0x80014F80: bne         $v0, $zero, L_80014F98
    if (ctx->r2 != 0) {
        // 0x80014F84: nop
    
            goto L_80014F98;
    }
    // 0x80014F84: nop

    // 0x80014F88: lbu         $v0, 0x74($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X74);
    // 0x80014F8C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80014F90: j           L_80014FC8
    // 0x80014F94: addiu       $a1, $a1, -0x3D5C
    ctx->r5 = ADD32(ctx->r5, -0X3D5C);
        goto L_80014FC8;
    // 0x80014F94: addiu       $a1, $a1, -0x3D5C
    ctx->r5 = ADD32(ctx->r5, -0X3D5C);
L_80014F98:
    // 0x80014F98: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80014F9C: lb          $v0, 0x5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5);
    // 0x80014FA0: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x80014FA4: beq         $v0, $zero, L_80014FBC
    if (ctx->r2 == 0) {
        // 0x80014FA8: nop
    
            goto L_80014FBC;
    }
    // 0x80014FA8: nop

    // 0x80014FAC: lbu         $v0, 0x74($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X74);
    // 0x80014FB0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80014FB4: j           L_80014FC8
    // 0x80014FB8: addiu       $a1, $a1, -0x3BA4
    ctx->r5 = ADD32(ctx->r5, -0X3BA4);
        goto L_80014FC8;
    // 0x80014FB8: addiu       $a1, $a1, -0x3BA4
    ctx->r5 = ADD32(ctx->r5, -0X3BA4);
L_80014FBC:
    // 0x80014FBC: lbu         $v0, 0x74($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X74);
    // 0x80014FC0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80014FC4: addiu       $a1, $a1, -0x3C80
    ctx->r5 = ADD32(ctx->r5, -0X3C80);
L_80014FC8:
    // 0x80014FC8: lbu         $a0, 0x67($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X67);
    // 0x80014FCC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80014FD0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80014FD4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80014FD8: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80014FDC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80014FE0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80014FE4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80014FE8: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80014FEC: lbu         $v0, -0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1);
    // 0x80014FF0: sb          $v0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r2;
    // 0x80014FF4: lbu         $v0, 0x72($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X72);
    // 0x80014FF8: lbu         $v1, 0xC($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0XC);
    // 0x80014FFC: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80015000: bne         $v0, $zero, L_8001500C
    if (ctx->r2 != 0) {
        // 0x80015004: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8001500C;
    }
    // 0x80015004: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x80015008: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_8001500C:
    // 0x8001500C: sb          $v0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r2;
    // 0x80015010: j           L_8001502C
    // 0x80015014: sb          $zero, 0xD($a2)
    MEM_B(0XD, ctx->r6) = 0;
        goto L_8001502C;
    // 0x80015014: sb          $zero, 0xD($a2)
    MEM_B(0XD, ctx->r6) = 0;
L_80015018:
    // 0x80015018: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001501C: sw          $v0, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->r2;
    // 0x80015020: sb          $zero, 0x72($s0)
    MEM_B(0X72, ctx->r16) = 0;
    // 0x80015024: sb          $zero, 0x6F($s0)
    MEM_B(0X6F, ctx->r16) = 0;
    // 0x80015028: sb          $zero, 0x6E($s0)
    MEM_B(0X6E, ctx->r16) = 0;
L_8001502C:
    // 0x8001502C: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_80015030:
    // 0x80015030: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80015034: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80015038: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8001503C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80015040: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80015044: jr          $ra
    // 0x80015048: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80015048: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8001504C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001504C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80015050: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80015054: addiu       $t0, $zero, 0x12
    ctx->r8 = ADD32(0, 0X12);
    // 0x80015058: addu        $a3, $sp, $zero
    ctx->r7 = ADD32(ctx->r29, 0);
L_8001505C:
    // 0x8001505C: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80015060: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80015064: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80015068:
    // 0x80015068: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x8001506C: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80015070: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80015074: lbu         $v0, 0x70($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X70);
    // 0x80015078: beq         $v0, $zero, L_80015088
    if (ctx->r2 == 0) {
        // 0x8001507C: subu        $v0, $t0, $v1
        ctx->r2 = SUB32(ctx->r8, ctx->r3);
            goto L_80015088;
    }
    // 0x8001507C: subu        $v0, $t0, $v1
    ctx->r2 = SUB32(ctx->r8, ctx->r3);
    // 0x80015080: j           L_80015098
    // 0x80015084: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
        goto L_80015098;
    // 0x80015084: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
L_80015088:
    // 0x80015088: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001508C: slti        $v0, $v1, 0x12
    ctx->r2 = SIGNED(ctx->r3) < 0X12 ? 1 : 0;
    // 0x80015090: bne         $v0, $zero, L_80015068
    if (ctx->r2 != 0) {
        // 0x80015094: addiu       $a1, $a1, 0x12
        ctx->r5 = ADD32(ctx->r5, 0X12);
            goto L_80015068;
    }
    // 0x80015094: addiu       $a1, $a1, 0x12
    ctx->r5 = ADD32(ctx->r5, 0X12);
L_80015098:
    // 0x80015098: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001509C: slti        $v0, $a2, 0xA
    ctx->r2 = SIGNED(ctx->r6) < 0XA ? 1 : 0;
    // 0x800150A0: bne         $v0, $zero, L_8001505C
    if (ctx->r2 != 0) {
        // 0x800150A4: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_8001505C;
    }
    // 0x800150A4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800150A8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800150AC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800150B0: addu        $a1, $sp, $zero
    ctx->r5 = ADD32(ctx->r29, 0);
L_800150B4:
    // 0x800150B4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800150B8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800150BC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800150C0: slti        $v0, $a2, 0xA
    ctx->r2 = SIGNED(ctx->r6) < 0XA ? 1 : 0;
    // 0x800150C4: bne         $v0, $zero, L_800150B4
    if (ctx->r2 != 0) {
        // 0x800150C8: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800150B4;
    }
    // 0x800150C8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800150CC: lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // 0x800150D0: ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // 0x800150D4: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800150D8: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x800150DC: mfhi        $t1
    ctx->r9 = hi;
    // 0x800150E0: sra         $v0, $t1, 2
    ctx->r2 = S32(SIGNED(ctx->r9) >> 2);
    // 0x800150E4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800150E8: sw          $v0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r2;
    // 0x800150EC: jr          $ra
    // 0x800150F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800150F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800150F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800150F4: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x800150F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800150FC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80015100:
    // 0x80015100: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x80015104: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80015108: lbu         $v0, 0x4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4);
    // 0x8001510C: sltu        $v1, $zero, $a1
    ctx->r3 = 0 < ctx->r5 ? 1 : 0;
    // 0x80015110: srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // 0x80015114: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80015118: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8001511C: beq         $v0, $zero, L_80015184
    if (ctx->r2 == 0) {
        // 0x80015120: addiu       $a3, $a1, -0x1
        ctx->r7 = ADD32(ctx->r5, -0X1);
            goto L_80015184;
    }
    // 0x80015120: addiu       $a3, $a1, -0x1
    ctx->r7 = ADD32(ctx->r5, -0X1);
    // 0x80015124: bltz        $a3, L_80015194
    if (SIGNED(ctx->r7) < 0) {
        // 0x80015128: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80015194;
    }
    // 0x80015128: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001512C: sll         $v0, $a3, 3
    ctx->r2 = S32(ctx->r7 << 3);
    // 0x80015130: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80015134: sll         $a2, $v0, 1
    ctx->r6 = S32(ctx->r2 << 1);
L_80015138:
    // 0x80015138: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8001513C:
    // 0x8001513C: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x80015140: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80015144: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80015148: lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4);
    // 0x8001514C: sb          $v1, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r3;
    // 0x80015150: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x80015154: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x80015158: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001515C: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80015160: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // 0x80015164: slti        $v0, $a1, 0xA
    ctx->r2 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    // 0x80015168: bne         $v0, $zero, L_8001513C
    if (ctx->r2 != 0) {
        // 0x8001516C: nop
    
            goto L_8001513C;
    }
    // 0x8001516C: nop

    // 0x80015170: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80015174: bgez        $a3, L_80015138
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80015178: addiu       $a2, $a2, -0x12
        ctx->r6 = ADD32(ctx->r6, -0X12);
            goto L_80015138;
    }
    // 0x80015178: addiu       $a2, $a2, -0x12
    ctx->r6 = ADD32(ctx->r6, -0X12);
    // 0x8001517C: j           L_80015194
    // 0x80015180: nop

        goto L_80015194;
    // 0x80015180: nop

L_80015184:
    // 0x80015184: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80015188: slti        $v0, $a1, 0x18
    ctx->r2 = SIGNED(ctx->r5) < 0X18 ? 1 : 0;
    // 0x8001518C: bne         $v0, $zero, L_80015100
    if (ctx->r2 != 0) {
        // 0x80015190: addiu       $a2, $a2, 0x12
        ctx->r6 = ADD32(ctx->r6, 0X12);
            goto L_80015100;
    }
    // 0x80015190: addiu       $a2, $a2, 0x12
    ctx->r6 = ADD32(ctx->r6, 0X12);
L_80015194:
    // 0x80015194: jr          $ra
    // 0x80015198: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    return;
    // 0x80015198: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
;}
RECOMP_FUNC void func_8001519C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001519C: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x800151A0: addiu       $a1, $zero, 0x132
    ctx->r5 = ADD32(0, 0X132);
L_800151A4:
    // 0x800151A4: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x800151A8: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800151AC: lbu         $v0, 0x70($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X70);
    // 0x800151B0: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800151B4: beql        $v0, $zero, L_800151E8
    if (ctx->r2 == 0) {
        // 0x800151B8: addiu       $a1, $a1, -0x12
        ctx->r5 = ADD32(ctx->r5, -0X12);
            goto L_800151E8;
    }
    goto skip_0;
    // 0x800151B8: addiu       $a1, $a1, -0x12
    ctx->r5 = ADD32(ctx->r5, -0X12);
    skip_0:
    // 0x800151BC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800151C0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
L_800151C4:
    // 0x800151C4: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x800151C8: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800151CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800151D0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800151D4: sb          $a3, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r7;
    // 0x800151D8: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x800151DC: bne         $v0, $zero, L_800151C4
    if (ctx->r2 != 0) {
        // 0x800151E0: nop
    
            goto L_800151C4;
    }
    // 0x800151E0: nop

    // 0x800151E4: addiu       $a1, $a1, -0x12
    ctx->r5 = ADD32(ctx->r5, -0X12);
L_800151E8:
    // 0x800151E8: slti        $v0, $a1, -0x5A
    ctx->r2 = SIGNED(ctx->r5) < -0X5A ? 1 : 0;
    // 0x800151EC: beq         $v0, $zero, L_800151A4
    if (ctx->r2 == 0) {
        // 0x800151F0: nop
    
            goto L_800151A4;
    }
    // 0x800151F0: nop

    // 0x800151F4: jr          $ra
    // 0x800151F8: nop

    return;
    // 0x800151F8: nop

;}
RECOMP_FUNC void func_800151FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800151FC: addu        $t2, $a0, $zero
    ctx->r10 = ADD32(ctx->r4, 0);
    // 0x80015200: lb          $v1, 0x54($t2)
    ctx->r3 = MEM_B(ctx->r10, 0X54);
    // 0x80015204: lw          $v0, 0xDC($t2)
    ctx->r2 = MEM_W(ctx->r10, 0XDC);
    // 0x80015208: addu        $t5, $zero, $zero
    ctx->r13 = ADD32(0, 0);
    // 0x8001520C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80015210: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80015214: lb          $v0, 0x4C($t2)
    ctx->r2 = MEM_B(ctx->r10, 0X4C);
    // 0x80015218: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8001521C: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80015220: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80015224: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80015228: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
L_8001522C:
    // 0x8001522C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80015230: addiu       $t4, $t0, -0x2
    ctx->r12 = ADD32(ctx->r8, -0X2);
    // 0x80015234: addu        $t1, $t3, $zero
    ctx->r9 = ADD32(ctx->r11, 0);
L_80015238:
    // 0x80015238: lw          $v1, 0x1C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X1C);
    // 0x8001523C: addu        $v0, $v1, $t4
    ctx->r2 = ADD32(ctx->r3, ctx->r12);
    // 0x80015240: slti        $v0, $v0, -0x5
    ctx->r2 = SIGNED(ctx->r2) < -0X5 ? 1 : 0;
    // 0x80015244: bnel        $v0, $zero, L_800152B0
    if (ctx->r2 != 0) {
        // 0x80015248: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800152B0;
    }
    goto skip_0;
    // 0x80015248: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_0:
    // 0x8001524C: lw          $a0, 0x18($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X18);
    // 0x80015250: lw          $v0, 0xB0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0XB0);
    // 0x80015254: addu        $v1, $t0, $v1
    ctx->r3 = ADD32(ctx->r8, ctx->r3);
    // 0x80015258: addu        $a0, $a3, $a0
    ctx->r4 = ADD32(ctx->r7, ctx->r4);
    // 0x8001525C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80015260: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80015264: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80015268: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001526C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80015270: lbu         $v0, 0x4A($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4A);
    // 0x80015274: beql        $v0, $zero, L_800152B0
    if (ctx->r2 == 0) {
        // 0x80015278: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800152B0;
    }
    goto skip_1;
    // 0x80015278: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_1:
    // 0x8001527C: lb          $v0, 0x0($t1)
    ctx->r2 = MEM_B(ctx->r9, 0X0);
    // 0x80015280: beql        $v0, $zero, L_800152B0
    if (ctx->r2 == 0) {
        // 0x80015284: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800152B0;
    }
    goto skip_2;
    // 0x80015284: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_2:
    // 0x80015288: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8001528C: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x80015290: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80015294: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80015298: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8001529C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800152A0: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x800152A4: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800152A8: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x800152AC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_800152B0:
    // 0x800152B0: slti        $v0, $a3, 0x5
    ctx->r2 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
    // 0x800152B4: bne         $v0, $zero, L_80015238
    if (ctx->r2 != 0) {
        // 0x800152B8: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_80015238;
    }
    // 0x800152B8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800152BC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800152C0: slti        $v0, $t0, 0x5
    ctx->r2 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x800152C4: bne         $v0, $zero, L_8001522C
    if (ctx->r2 != 0) {
        // 0x800152C8: addiu       $t3, $t3, 0x5
        ctx->r11 = ADD32(ctx->r11, 0X5);
            goto L_8001522C;
    }
    // 0x800152C8: addiu       $t3, $t3, 0x5
    ctx->r11 = ADD32(ctx->r11, 0X5);
    // 0x800152CC: jr          $ra
    // 0x800152D0: addu        $v0, $t5, $zero
    ctx->r2 = ADD32(ctx->r13, 0);
    return;
    // 0x800152D0: addu        $v0, $t5, $zero
    ctx->r2 = ADD32(ctx->r13, 0);
;}
RECOMP_FUNC void func_800152D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800152D4: lb          $v1, 0x54($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X54);
    // 0x800152D8: lw          $v0, 0xDC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XDC);
    // 0x800152DC: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x800152E0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800152E4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800152E8: lb          $v0, 0x4C($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X4C);
    // 0x800152EC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800152F0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800152F4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800152F8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800152FC: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
L_80015300:
    // 0x80015300: addiu       $t2, $a3, -0x2
    ctx->r10 = ADD32(ctx->r7, -0X2);
    // 0x80015304: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x80015308: addiu       $t0, $a2, 0x5
    ctx->r8 = ADD32(ctx->r6, 0X5);
L_8001530C:
    // 0x8001530C: lb          $v0, 0x0($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X0);
    // 0x80015310: beql        $v0, $zero, L_80015330
    if (ctx->r2 == 0) {
        // 0x80015314: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80015330;
    }
    goto skip_0;
    // 0x80015314: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x80015318: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x8001531C: addu        $v1, $v0, $t2
    ctx->r3 = ADD32(ctx->r2, ctx->r10);
    // 0x80015320: slt         $v0, $v1, $t1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80015324: beql        $v0, $zero, L_8001532C
    if (ctx->r2 == 0) {
        // 0x80015328: addu        $t1, $v1, $zero
        ctx->r9 = ADD32(ctx->r3, 0);
            goto L_8001532C;
    }
    goto skip_1;
    // 0x80015328: addu        $t1, $v1, $zero
    ctx->r9 = ADD32(ctx->r3, 0);
    skip_1:
L_8001532C:
    // 0x8001532C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80015330:
    // 0x80015330: slt         $v0, $a1, $t0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80015334: bne         $v0, $zero, L_8001530C
    if (ctx->r2 != 0) {
        // 0x80015338: nop
    
            goto L_8001530C;
    }
    // 0x80015338: nop

    // 0x8001533C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80015340: slti        $v0, $a3, 0x5
    ctx->r2 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
    // 0x80015344: bne         $v0, $zero, L_80015300
    if (ctx->r2 != 0) {
        // 0x80015348: addiu       $a2, $a2, 0x5
        ctx->r6 = ADD32(ctx->r6, 0X5);
            goto L_80015300;
    }
    // 0x80015348: addiu       $a2, $a2, 0x5
    ctx->r6 = ADD32(ctx->r6, 0X5);
    // 0x8001534C: jr          $ra
    // 0x80015350: addu        $v0, $t1, $zero
    ctx->r2 = ADD32(ctx->r9, 0);
    return;
    // 0x80015350: addu        $v0, $t1, $zero
    ctx->r2 = ADD32(ctx->r9, 0);
;}
RECOMP_FUNC void func_80015354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015354: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80015358: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8001535C: addu        $t4, $sp, $zero
    ctx->r12 = ADD32(ctx->r29, 0);
    // 0x80015360: addu        $t3, $sp, $zero
    ctx->r11 = ADD32(ctx->r29, 0);
    // 0x80015364: lw          $t6, 0x1C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X1C);
    // 0x80015368: lb          $v1, 0x54($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X54);
    // 0x8001536C: lw          $a0, 0xDC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XDC);
    // 0x80015370: addu        $t5, $zero, $zero
    ctx->r13 = ADD32(0, 0);
    // 0x80015374: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80015378: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8001537C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80015380: sw          $v0, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r2;
    // 0x80015384: lb          $v0, 0x4C($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X4C);
    // 0x80015388: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8001538C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80015390: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80015394: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80015398: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
L_8001539C:
    // 0x8001539C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800153A0: addiu       $t2, $a3, -0x2
    ctx->r10 = ADD32(ctx->r7, -0X2);
    // 0x800153A4: addu        $t0, $t1, $zero
    ctx->r8 = ADD32(ctx->r9, 0);
L_800153A8:
    // 0x800153A8: lw          $v1, 0x1C($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1C);
    // 0x800153AC: addu        $v0, $v1, $t2
    ctx->r2 = ADD32(ctx->r3, ctx->r10);
    // 0x800153B0: slti        $v0, $v0, -0x5
    ctx->r2 = SIGNED(ctx->r2) < -0X5 ? 1 : 0;
    // 0x800153B4: bnel        $v0, $zero, L_80015420
    if (ctx->r2 != 0) {
        // 0x800153B8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80015420;
    }
    goto skip_0;
    // 0x800153B8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x800153BC: lw          $a0, 0x18($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X18);
    // 0x800153C0: lw          $v0, 0xB0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XB0);
    // 0x800153C4: addu        $v1, $a3, $v1
    ctx->r3 = ADD32(ctx->r7, ctx->r3);
    // 0x800153C8: addu        $a0, $a1, $a0
    ctx->r4 = ADD32(ctx->r5, ctx->r4);
    // 0x800153CC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800153D0: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800153D4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800153D8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800153DC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800153E0: lbu         $v0, 0x4A($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4A);
    // 0x800153E4: beql        $v0, $zero, L_80015420
    if (ctx->r2 == 0) {
        // 0x800153E8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80015420;
    }
    goto skip_1;
    // 0x800153E8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_1:
    // 0x800153EC: lb          $v0, 0x0($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X0);
    // 0x800153F0: beql        $v0, $zero, L_80015420
    if (ctx->r2 == 0) {
        // 0x800153F4: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80015420;
    }
    goto skip_2;
    // 0x800153F4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_2:
    // 0x800153F8: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x800153FC: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x80015400: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80015404: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
    // 0x80015408: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8001540C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80015410: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x80015414: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80015418: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x8001541C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80015420:
    // 0x80015420: slti        $v0, $a1, 0x5
    ctx->r2 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x80015424: bne         $v0, $zero, L_800153A8
    if (ctx->r2 != 0) {
        // 0x80015428: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800153A8;
    }
    // 0x80015428: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001542C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80015430: slti        $v0, $a3, 0x5
    ctx->r2 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
    // 0x80015434: bne         $v0, $zero, L_8001539C
    if (ctx->r2 != 0) {
        // 0x80015438: addiu       $t1, $t1, 0x5
        ctx->r9 = ADD32(ctx->r9, 0X5);
            goto L_8001539C;
    }
    // 0x80015438: addiu       $t1, $t1, 0x5
    ctx->r9 = ADD32(ctx->r9, 0X5);
    // 0x8001543C: addu        $v0, $t5, $zero
    ctx->r2 = ADD32(ctx->r13, 0);
    // 0x80015440: sw          $t5, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r13;
    // 0x80015444: sw          $t6, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r14;
    // 0x80015448: jr          $ra
    // 0x8001544C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8001544C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80015450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015450: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80015454: lw          $v0, 0x2C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X2C);
    // 0x80015458: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001545C: bltz        $v0, L_8001546C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80015460: sw          $v0, 0x2C($a1)
        MEM_W(0X2C, ctx->r5) = ctx->r2;
            goto L_8001546C;
    }
    // 0x80015460: sw          $v0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r2;
    // 0x80015464: j           L_80015488
    // 0x80015468: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80015488;
    // 0x80015468: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8001546C:
    // 0x8001546C: lw          $a0, 0x34($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X34);
    // 0x80015470: lw          $v1, 0x1C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1C);
    // 0x80015474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80015478: sb          $zero, 0x52($a1)
    MEM_B(0X52, ctx->r5) = 0;
    // 0x8001547C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80015480: sw          $a0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r4;
    // 0x80015484: sw          $v1, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r3;
L_80015488:
    // 0x80015488: jr          $ra
    // 0x8001548C: nop

    return;
    // 0x8001548C: nop

;}
RECOMP_FUNC void func_80015490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015490: addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
    // 0x80015494: lb          $v0, 0x54($t1)
    ctx->r2 = MEM_B(ctx->r9, 0X54);
    // 0x80015498: lw          $v1, 0xDC($t1)
    ctx->r3 = MEM_W(ctx->r9, 0XDC);
    // 0x8001549C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800154A0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800154A4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800154A8: lb          $v1, 0x4C($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X4C);
    // 0x800154AC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800154B0: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x800154B4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800154B8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800154BC: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
L_800154C0:
    // 0x800154C0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800154C4: addiu       $t3, $t0, -0x2
    ctx->r11 = ADD32(ctx->r8, -0X2);
    // 0x800154C8: addu        $a3, $t2, $zero
    ctx->r7 = ADD32(ctx->r10, 0);
L_800154CC:
    // 0x800154CC: lb          $v0, 0x0($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X0);
    // 0x800154D0: beq         $v0, $zero, L_80015514
    if (ctx->r2 == 0) {
        // 0x800154D4: addu        $a1, $v0, $zero
        ctx->r5 = ADD32(ctx->r2, 0);
            goto L_80015514;
    }
    // 0x800154D4: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800154D8: lw          $v1, 0x1C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X1C);
    // 0x800154DC: addu        $v0, $v1, $t3
    ctx->r2 = ADD32(ctx->r3, ctx->r11);
    // 0x800154E0: slti        $v0, $v0, -0x5
    ctx->r2 = SIGNED(ctx->r2) < -0X5 ? 1 : 0;
    // 0x800154E4: bnel        $v0, $zero, L_80015518
    if (ctx->r2 != 0) {
        // 0x800154E8: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80015518;
    }
    goto skip_0;
    // 0x800154E8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_0:
    // 0x800154EC: lw          $a0, 0x18($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X18);
    // 0x800154F0: lw          $v0, 0xB0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0XB0);
    // 0x800154F4: addu        $v1, $t0, $v1
    ctx->r3 = ADD32(ctx->r8, ctx->r3);
    // 0x800154F8: addu        $a0, $a2, $a0
    ctx->r4 = ADD32(ctx->r6, ctx->r4);
    // 0x800154FC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80015500: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80015504: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80015508: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001550C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80015510: sb          $a1, 0x4A($a0)
    MEM_B(0X4A, ctx->r4) = ctx->r5;
L_80015514:
    // 0x80015514: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80015518:
    // 0x80015518: slti        $v0, $a2, 0x5
    ctx->r2 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
    // 0x8001551C: bne         $v0, $zero, L_800154CC
    if (ctx->r2 != 0) {
        // 0x80015520: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800154CC;
    }
    // 0x80015520: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80015524: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80015528: slti        $v0, $t0, 0x5
    ctx->r2 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x8001552C: bne         $v0, $zero, L_800154C0
    if (ctx->r2 != 0) {
        // 0x80015530: addiu       $t2, $t2, 0x5
        ctx->r10 = ADD32(ctx->r10, 0X5);
            goto L_800154C0;
    }
    // 0x80015530: addiu       $t2, $t2, 0x5
    ctx->r10 = ADD32(ctx->r10, 0X5);
    // 0x80015534: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80015538: jr          $ra
    // 0x8001553C: nop

    return;
    // 0x8001553C: nop

;}
RECOMP_FUNC void func_80015540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015540: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80015544: addu        $t5, $a0, $zero
    ctx->r13 = ADD32(ctx->r4, 0);
    // 0x80015548: sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // 0x8001554C: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x80015550: lbu         $v0, 0x55($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X55);
    // 0x80015554: lw          $v1, 0xE0($t5)
    ctx->r3 = MEM_W(ctx->r13, 0XE0);
    // 0x80015558: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8001555C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80015560: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80015564: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80015568: lb          $v1, 0x4A($t5)
    ctx->r3 = MEM_B(ctx->r13, 0X4A);
    // 0x8001556C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80015570: beq         $v1, $zero, L_8001589C
    if (ctx->r3 == 0) {
        // 0x80015574: addu        $t8, $zero, $zero
        ctx->r24 = ADD32(0, 0);
            goto L_8001589C;
    }
    // 0x80015574: addu        $t8, $zero, $zero
    ctx->r24 = ADD32(0, 0);
    // 0x80015578: lb          $v1, 0x5A($t5)
    ctx->r3 = MEM_B(ctx->r13, 0X5A);
    // 0x8001557C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80015580: bne         $v1, $v0, L_80015594
    if (ctx->r3 != ctx->r2) {
        // 0x80015584: lui         $a0, 0xBA00
        ctx->r4 = S32(0XBA00 << 16);
            goto L_80015594;
    }
    // 0x80015584: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x80015588: lb          $v0, 0x5($t5)
    ctx->r2 = MEM_B(ctx->r13, 0X5);
    // 0x8001558C: bltz        $v0, L_8001589C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80015590: nop
    
            goto L_8001589C;
    }
    // 0x80015590: nop

L_80015594:
    // 0x80015594: ori         $a0, $a0, 0xE02
    ctx->r4 = ctx->r4 | 0XE02;
    // 0x80015598: lui         $a3, 0x71F
    ctx->r7 = S32(0X71F << 16);
    // 0x8001559C: ori         $a3, $a3, 0xF200
    ctx->r7 = ctx->r7 | 0XF200;
    // 0x800155A0: lui         $t0, 0xF548
    ctx->r8 = S32(0XF548 << 16);
    // 0x800155A4: ori         $t0, $t0, 0x800
    ctx->r8 = ctx->r8 | 0X800;
    // 0x800155A8: lui         $t1, 0x7
    ctx->r9 = S32(0X7 << 16);
    // 0x800155AC: ori         $t1, $t1, 0xC07C
    ctx->r9 = ctx->r9 | 0XC07C;
    // 0x800155B0: lui         $t2, 0xF500
    ctx->r10 = S32(0XF500 << 16);
    // 0x800155B4: ori         $t2, $t2, 0x100
    ctx->r10 = ctx->r10 | 0X100;
    // 0x800155B8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800155BC: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x800155C0: lui         $t3, 0x73F
    ctx->r11 = S32(0X73F << 16);
    // 0x800155C4: ori         $t3, $t3, 0xC000
    ctx->r11 = ctx->r11 | 0XC000;
    // 0x800155C8: lui         $a2, 0x700
    ctx->r6 = S32(0X700 << 16);
    // 0x800155CC: lui         $a1, 0xE600
    ctx->r5 = S32(0XE600 << 16);
    // 0x800155D0: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x800155D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800155D8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800155DC: lui         $v1, 0x600
    ctx->r3 = S32(0X600 << 16);
    // 0x800155E0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800155E4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800155E8: addiu       $v1, $v1, -0x67D0
    ctx->r3 = ADD32(ctx->r3, -0X67D0);
    // 0x800155EC: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x800155F0: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x800155F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800155F8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800155FC: ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // 0x80015600: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x80015604: addiu       $v1, $v0, 0x18
    ctx->r3 = ADD32(ctx->r2, 0X18);
    // 0x80015608: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001560C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80015610: lui         $v1, 0xFD50
    ctx->r3 = S32(0XFD50 << 16);
    // 0x80015614: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x80015618: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001561C: addiu       $v1, $v1, -0xA98
    ctx->r3 = ADD32(ctx->r3, -0XA98);
    // 0x80015620: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // 0x80015624: addiu       $v1, $v0, 0x20
    ctx->r3 = ADD32(ctx->r2, 0X20);
    // 0x80015628: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001562C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80015630: lui         $v1, 0xF550
    ctx->r3 = S32(0XF550 << 16);
    // 0x80015634: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
    // 0x80015638: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x8001563C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015640: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80015644: addiu       $v1, $v0, 0x30
    ctx->r3 = ADD32(ctx->r2, 0X30);
    // 0x80015648: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001564C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80015650: lui         $v1, 0xF300
    ctx->r3 = S32(0XF300 << 16);
    // 0x80015654: sw          $v1, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r3;
    // 0x80015658: addiu       $v1, $v0, 0x38
    ctx->r3 = ADD32(ctx->r2, 0X38);
    // 0x8001565C: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x80015660: lui         $a0, 0xE700
    ctx->r4 = S32(0XE700 << 16);
    // 0x80015664: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015668: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001566C: addiu       $v1, $v0, 0x40
    ctx->r3 = ADD32(ctx->r2, 0X40);
    // 0x80015670: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015674: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80015678: addiu       $v1, $v0, 0x48
    ctx->r3 = ADD32(ctx->r2, 0X48);
    // 0x8001567C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015680: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80015684: lui         $v1, 0xF200
    ctx->r3 = S32(0XF200 << 16);
    // 0x80015688: sw          $v1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r3;
    // 0x8001568C: addiu       $v1, $v0, 0x50
    ctx->r3 = ADD32(ctx->r2, 0X50);
    // 0x80015690: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015694: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80015698: lui         $v1, 0xFD10
    ctx->r3 = S32(0XFD10 << 16);
    // 0x8001569C: sw          $v1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r3;
    // 0x800156A0: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800156A4: addiu       $v1, $v1, -0x690
    ctx->r3 = ADD32(ctx->r3, -0X690);
    // 0x800156A8: sw          $v1, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r3;
    // 0x800156AC: addiu       $v1, $v0, 0x58
    ctx->r3 = ADD32(ctx->r2, 0X58);
    // 0x800156B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800156B4: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800156B8: lui         $v1, 0xE800
    ctx->r3 = S32(0XE800 << 16);
    // 0x800156BC: sw          $v1, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r3;
    // 0x800156C0: addiu       $v1, $v0, 0x60
    ctx->r3 = ADD32(ctx->r2, 0X60);
    // 0x800156C4: sw          $a2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r6;
    // 0x800156C8: sw          $a1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r5;
    // 0x800156CC: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x800156D0: sw          $a3, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r7;
    // 0x800156D4: sw          $a0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r4;
    // 0x800156D8: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x800156DC: sw          $t0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r8;
    // 0x800156E0: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x800156E4: sw          $t1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r9;
    // 0x800156E8: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
    // 0x800156EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800156F0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x800156F4: addiu       $v1, $v0, 0x68
    ctx->r3 = ADD32(ctx->r2, 0X68);
    // 0x800156F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800156FC: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80015700: addiu       $v1, $v0, 0x70
    ctx->r3 = ADD32(ctx->r2, 0X70);
    // 0x80015704: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015708: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001570C: lui         $v1, 0xF000
    ctx->r3 = S32(0XF000 << 16);
    // 0x80015710: sw          $v1, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r3;
    // 0x80015714: addiu       $v1, $v0, 0x78
    ctx->r3 = ADD32(ctx->r2, 0X78);
    // 0x80015718: sw          $t2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r10;
    // 0x8001571C: sw          $a2, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r6;
    // 0x80015720: sw          $a1, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->r5;
    // 0x80015724: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    // 0x80015728: sw          $t3, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r11;
    // 0x8001572C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015730: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80015734: sw          $a0, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r4;
    // 0x80015738: sw          $zero, 0x74($v0)
    MEM_W(0X74, ctx->r2) = 0;
    // 0x8001573C: lbu         $v0, 0x5($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X5);
    // 0x80015740: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80015744: bne         $v0, $zero, L_80015750
    if (ctx->r2 != 0) {
        // 0x80015748: addiu       $t6, $zero, 0xCE
        ctx->r14 = ADD32(0, 0XCE);
            goto L_80015750;
    }
    // 0x80015748: addiu       $t6, $zero, 0xCE
    ctx->r14 = ADD32(0, 0XCE);
    // 0x8001574C: addiu       $t6, $zero, 0x59
    ctx->r14 = ADD32(0, 0X59);
L_80015750:
    // 0x80015750: lui         $s1, 0xE400
    ctx->r17 = S32(0XE400 << 16);
    // 0x80015754: lui         $s0, 0xB400
    ctx->r16 = S32(0XB400 << 16);
    // 0x80015758: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x8001575C: lui         $t7, 0x666
    ctx->r15 = S32(0X666 << 16);
    // 0x80015760: ori         $t7, $t7, 0x666
    ctx->r15 = ctx->r15 | 0X666;
    // 0x80015764: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x80015768: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
L_8001576C:
    // 0x8001576C: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x80015770: addu        $t0, $t6, $zero
    ctx->r8 = ADD32(ctx->r14, 0);
    // 0x80015774: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80015778: addu        $a2, $t4, $zero
    ctx->r6 = ADD32(ctx->r12, 0);
L_8001577C:
    // 0x8001577C: lb          $a0, 0x0($a2)
    ctx->r4 = MEM_B(ctx->r6, 0X0);
    // 0x80015780: beq         $a0, $zero, L_80015848
    if (ctx->r4 == 0) {
        // 0x80015784: addu        $v1, $t6, $a3
        ctx->r3 = ADD32(ctx->r14, ctx->r7);
            goto L_80015848;
    }
    // 0x80015784: addu        $v1, $t6, $a3
    ctx->r3 = ADD32(ctx->r14, ctx->r7);
    // 0x80015788: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8001578C: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x80015790: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80015794: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80015798: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001579C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800157A0: lb          $v0, 0x58($t5)
    ctx->r2 = MEM_B(ctx->r13, 0X58);
    // 0x800157A4: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x800157A8: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x800157AC: addiu       $v0, $v0, 0x33
    ctx->r2 = ADD32(ctx->r2, 0X33);
    // 0x800157B0: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x800157B4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800157B8: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x800157BC: or          $v0, $v0, $s1
    ctx->r2 = ctx->r2 | ctx->r17;
    // 0x800157C0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800157C4: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x800157C8: lb          $v1, 0x58($t5)
    ctx->r3 = MEM_B(ctx->r13, 0X58);
    // 0x800157CC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800157D0: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x800157D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800157D8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800157DC: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x800157E0: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x800157E4: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x800157E8: sw          $s0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r16;
    // 0x800157EC: addiu       $v1, $v1, 0x33
    ctx->r3 = ADD32(ctx->r3, 0X33);
    // 0x800157F0: addu        $v1, $t2, $v1
    ctx->r3 = ADD32(ctx->r10, ctx->r3);
    // 0x800157F4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800157F8: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x800157FC: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80015800: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80015804: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80015808: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001580C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80015810: lb          $a0, -0x3DF4($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X3DF4);
    // 0x80015814: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80015818: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001581C: lb          $v1, -0x3DF3($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X3DF3);
    // 0x80015820: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x80015824: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015828: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001582C: sw          $t9, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r25;
    // 0x80015830: sw          $t7, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r15;
    // 0x80015834: sll         $a0, $a0, 21
    ctx->r4 = S32(ctx->r4 << 21);
    // 0x80015838: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x8001583C: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80015840: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x80015844: sw          $a0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r4;
L_80015848:
    // 0x80015848: addiu       $t0, $t0, 0x5
    ctx->r8 = ADD32(ctx->r8, 0X5);
    // 0x8001584C: addiu       $a3, $a3, 0x5
    ctx->r7 = ADD32(ctx->r7, 0X5);
    // 0x80015850: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80015854: slti        $v0, $t1, 0x5
    ctx->r2 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x80015858: bne         $v0, $zero, L_8001577C
    if (ctx->r2 != 0) {
        // 0x8001585C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8001577C;
    }
    // 0x8001585C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80015860: addiu       $t3, $t3, 0x5
    ctx->r11 = ADD32(ctx->r11, 0X5);
    // 0x80015864: addiu       $t4, $t4, 0x5
    ctx->r12 = ADD32(ctx->r12, 0X5);
    // 0x80015868: addiu       $t8, $t8, 0x1
    ctx->r24 = ADD32(ctx->r24, 0X1);
    // 0x8001586C: slti        $v0, $t8, 0x5
    ctx->r2 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x80015870: bne         $v0, $zero, L_8001576C
    if (ctx->r2 != 0) {
        // 0x80015874: addiu       $t2, $t2, 0x5
        ctx->r10 = ADD32(ctx->r10, 0X5);
            goto L_8001576C;
    }
    // 0x80015874: addiu       $t2, $t2, 0x5
    ctx->r10 = ADD32(ctx->r10, 0X5);
    // 0x80015878: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8001587C: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x80015880: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x80015884: ori         $a0, $a0, 0xE02
    ctx->r4 = ctx->r4 | 0XE02;
    // 0x80015888: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8001588C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015890: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80015894: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80015898: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
L_8001589C:
    // 0x8001589C: lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4);
    // 0x800158A0: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x800158A4: jr          $ra
    // 0x800158A8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800158A8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800158AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800158AC: addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
    // 0x800158B0: lbu         $t3, 0xCC($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0XCC);
    // 0x800158B4: lui         $v1, 0xBA00
    ctx->r3 = S32(0XBA00 << 16);
    // 0x800158B8: ori         $v1, $v1, 0x1402
    ctx->r3 = ctx->r3 | 0X1402;
    // 0x800158BC: lui         $a1, 0xFCFF
    ctx->r5 = S32(0XFCFF << 16);
    // 0x800158C0: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800158C4: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800158C8: lw          $t0, 0x2FE4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2FE4);
    // 0x800158CC: lui         $a0, 0xFFFC
    ctx->r4 = S32(0XFFFC << 16);
    // 0x800158D0: ori         $a0, $a0, 0xF279
    ctx->r4 = ctx->r4 | 0XF279;
    // 0x800158D4: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800158D8: addiu       $v0, $t0, 0x8
    ctx->r2 = ADD32(ctx->r8, 0X8);
    // 0x800158DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800158E0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800158E4: addiu       $v0, $t0, 0x10
    ctx->r2 = ADD32(ctx->r8, 0X10);
    // 0x800158E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800158EC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800158F0: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x800158F4: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    // 0x800158F8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800158FC: addiu       $v0, $v0, -0x67D0
    ctx->r2 = ADD32(ctx->r2, -0X67D0);
    // 0x80015900: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x80015904: addiu       $v0, $t0, 0x18
    ctx->r2 = ADD32(ctx->r8, 0X18);
    // 0x80015908: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001590C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80015910: addiu       $v0, $t0, 0x20
    ctx->r2 = ADD32(ctx->r8, 0X20);
    // 0x80015914: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x80015918: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8001591C: sw          $v1, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r3;
    // 0x80015920: sw          $zero, 0x14($t0)
    MEM_W(0X14, ctx->r8) = 0;
    // 0x80015924: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015928: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001592C: sw          $a1, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r5;
    // 0x80015930: sw          $a0, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r4;
    // 0x80015934: lb          $v0, 0x5A($t1)
    ctx->r2 = MEM_B(ctx->r9, 0X5A);
    // 0x80015938: bne         $v0, $zero, L_80015990
    if (ctx->r2 != 0) {
        // 0x8001593C: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_80015990;
    }
    // 0x8001593C: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x80015940: lui         $v1, 0x701
    ctx->r3 = S32(0X701 << 16);
    // 0x80015944: ori         $v1, $v1, 0x4060
    ctx->r3 = ctx->r3 | 0X4060;
    // 0x80015948: lui         $a0, 0x77F
    ctx->r4 = S32(0X77F << 16);
    // 0x8001594C: ori         $a0, $a0, 0xF080
    ctx->r4 = ctx->r4 | 0XF080;
    // 0x80015950: lui         $a2, 0xF510
    ctx->r6 = S32(0XF510 << 16);
    // 0x80015954: ori         $a2, $a2, 0x2000
    ctx->r6 = ctx->r6 | 0X2000;
    // 0x80015958: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8001595C: ori         $a1, $a1, 0x4060
    ctx->r5 = ctx->r5 | 0X4060;
    // 0x80015960: lui         $a3, 0xF
    ctx->r7 = S32(0XF << 16);
    // 0x80015964: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x80015968: addiu       $t4, $t4, 0x15DC
    ctx->r12 = ADD32(ctx->r12, 0X15DC);
    // 0x8001596C: addiu       $v0, $t0, 0x28
    ctx->r2 = ADD32(ctx->r8, 0X28);
    // 0x80015970: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015974: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80015978: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x8001597C: sw          $v0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r2;
    // 0x80015980: lui         $v0, 0x8028
    ctx->r2 = S32(0X8028 << 16);
    // 0x80015984: addiu       $v0, $v0, 0x0
    ctx->r2 = ADD32(ctx->r2, 0X0);
    // 0x80015988: j           L_800159DC
    // 0x8001598C: ori         $a3, $a3, 0xC07C
    ctx->r7 = ctx->r7 | 0XC07C;
        goto L_800159DC;
    // 0x8001598C: ori         $a3, $a3, 0xC07C
    ctx->r7 = ctx->r7 | 0XC07C;
L_80015990:
    // 0x80015990: lui         $v1, 0x701
    ctx->r3 = S32(0X701 << 16);
    // 0x80015994: ori         $v1, $v1, 0x4050
    ctx->r3 = ctx->r3 | 0X4050;
    // 0x80015998: lui         $a0, 0x73F
    ctx->r4 = S32(0X73F << 16);
    // 0x8001599C: ori         $a0, $a0, 0xF100
    ctx->r4 = ctx->r4 | 0XF100;
    // 0x800159A0: lui         $a2, 0xF510
    ctx->r6 = S32(0XF510 << 16);
    // 0x800159A4: ori         $a2, $a2, 0x1000
    ctx->r6 = ctx->r6 | 0X1000;
    // 0x800159A8: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x800159AC: ori         $a1, $a1, 0x4050
    ctx->r5 = ctx->r5 | 0X4050;
    // 0x800159B0: lui         $a3, 0x7
    ctx->r7 = S32(0X7 << 16);
    // 0x800159B4: ori         $a3, $a3, 0xC07C
    ctx->r7 = ctx->r7 | 0XC07C;
    // 0x800159B8: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x800159BC: addiu       $t4, $t4, 0x1628
    ctx->r12 = ADD32(ctx->r12, 0X1628);
    // 0x800159C0: addiu       $v0, $t0, 0x28
    ctx->r2 = ADD32(ctx->r8, 0X28);
    // 0x800159C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800159C8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800159CC: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x800159D0: sw          $v0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r2;
    // 0x800159D4: lui         $v0, 0x8028
    ctx->r2 = S32(0X8028 << 16);
    // 0x800159D8: addiu       $v0, $v0, 0x7800
    ctx->r2 = ADD32(ctx->r2, 0X7800);
L_800159DC:
    // 0x800159DC: sw          $v0, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r2;
    // 0x800159E0: addiu       $v0, $t0, 0x30
    ctx->r2 = ADD32(ctx->r8, 0X30);
    // 0x800159E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800159E8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800159EC: lui         $v0, 0xF510
    ctx->r2 = S32(0XF510 << 16);
    // 0x800159F0: sw          $v0, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r2;
    // 0x800159F4: addiu       $v0, $t0, 0x38
    ctx->r2 = ADD32(ctx->r8, 0X38);
    // 0x800159F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800159FC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80015A00: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x80015A04: sw          $v0, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r2;
    // 0x80015A08: addiu       $v0, $t0, 0x40
    ctx->r2 = ADD32(ctx->r8, 0X40);
    // 0x80015A0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015A10: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80015A14: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x80015A18: sw          $v0, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r2;
    // 0x80015A1C: addiu       $v0, $t0, 0x48
    ctx->r2 = ADD32(ctx->r8, 0X48);
    // 0x80015A20: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015A24: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80015A28: addiu       $v0, $t0, 0x50
    ctx->r2 = ADD32(ctx->r8, 0X50);
    // 0x80015A2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015A30: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80015A34: addiu       $v0, $t0, 0x58
    ctx->r2 = ADD32(ctx->r8, 0X58);
    // 0x80015A38: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015A3C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80015A40: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x80015A44: sw          $v1, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->r3;
    // 0x80015A48: sw          $zero, 0x34($t0)
    MEM_W(0X34, ctx->r8) = 0;
    // 0x80015A4C: sw          $a0, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->r4;
    // 0x80015A50: sw          $t5, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->r13;
    // 0x80015A54: sw          $zero, 0x44($t0)
    MEM_W(0X44, ctx->r8) = 0;
    // 0x80015A58: sw          $a2, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->r6;
    // 0x80015A5C: sw          $a1, 0x4C($t0)
    MEM_W(0X4C, ctx->r8) = ctx->r5;
    // 0x80015A60: sw          $v0, 0x50($t0)
    MEM_W(0X50, ctx->r8) = ctx->r2;
    // 0x80015A64: sw          $a3, 0x54($t0)
    MEM_W(0X54, ctx->r8) = ctx->r7;
    // 0x80015A68: lui         $a1, 0xB900
    ctx->r5 = S32(0XB900 << 16);
    // 0x80015A6C: ori         $a1, $a1, 0x31D
    ctx->r5 = ctx->r5 | 0X31D;
    // 0x80015A70: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80015A74: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80015A78: lui         $a0, 0xF0A
    ctx->r4 = S32(0XF0A << 16);
    // 0x80015A7C: ori         $a0, $a0, 0x7008
    ctx->r4 = ctx->r4 | 0X7008;
    // 0x80015A80: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80015A84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015A88: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80015A8C: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x80015A90: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x80015A94: lb          $v1, 0xCD($t1)
    ctx->r3 = MEM_B(ctx->r9, 0XCD);
    // 0x80015A98: sll         $v0, $t3, 24
    ctx->r2 = S32(ctx->r11 << 24);
    // 0x80015A9C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80015AA0: beq         $v0, $v1, L_80015C80
    if (ctx->r2 == ctx->r3) {
        // 0x80015AA4: nop
    
            goto L_80015C80;
    }
    // 0x80015AA4: nop

    // 0x80015AA8: addiu       $t8, $zero, 0x58
    ctx->r24 = ADD32(0, 0X58);
    // 0x80015AAC: lui         $t7, 0xE400
    ctx->r15 = S32(0XE400 << 16);
    // 0x80015AB0: lui         $t6, 0xB400
    ctx->r14 = S32(0XB400 << 16);
    // 0x80015AB4: lui         $t5, 0xB300
    ctx->r13 = S32(0XB300 << 16);
    // 0x80015AB8: lui         $t0, 0x400
    ctx->r8 = S32(0X400 << 16);
    // 0x80015ABC: ori         $t0, $t0, 0x400
    ctx->r8 = ctx->r8 | 0X400;
L_80015AC0:
    // 0x80015AC0: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
    // 0x80015AC4: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80015AC8: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80015ACC: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80015AD0: lbu         $v0, 0xBC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XBC);
    // 0x80015AD4: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80015AD8: andi        $v1, $v0, 0x7F
    ctx->r3 = ctx->r2 & 0X7F;
    // 0x80015ADC: beq         $v1, $zero, L_80015C6C
    if (ctx->r3 == 0) {
        // 0x80015AE0: addu        $a3, $v1, $zero
        ctx->r7 = ADD32(ctx->r3, 0);
            goto L_80015C6C;
    }
    // 0x80015AE0: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // 0x80015AE4: lb          $v0, 0x5A($t1)
    ctx->r2 = MEM_B(ctx->r9, 0X5A);
    // 0x80015AE8: beql        $v0, $zero, L_80015AF0
    if (ctx->r2 == 0) {
        // 0x80015AEC: addiu       $a3, $v1, -0x1
        ctx->r7 = ADD32(ctx->r3, -0X1);
            goto L_80015AF0;
    }
    goto skip_0;
    // 0x80015AEC: addiu       $a3, $v1, -0x1
    ctx->r7 = ADD32(ctx->r3, -0X1);
    skip_0:
L_80015AF0:
    // 0x80015AF0: sll         $v0, $t2, 24
    ctx->r2 = S32(ctx->r10 << 24);
    // 0x80015AF4: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80015AF8: slti        $v0, $v0, 0x7
    ctx->r2 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80015AFC: bne         $v0, $zero, L_80015B08
    if (ctx->r2 != 0) {
        // 0x80015B00: addu        $a0, $t2, $zero
        ctx->r4 = ADD32(ctx->r10, 0);
            goto L_80015B08;
    }
    // 0x80015B00: addu        $a0, $t2, $zero
    ctx->r4 = ADD32(ctx->r10, 0);
    // 0x80015B04: addiu       $a0, $t2, -0x7
    ctx->r4 = ADD32(ctx->r10, -0X7);
L_80015B08:
    // 0x80015B08: lbu         $v1, 0x5($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X5);
    // 0x80015B0C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80015B10: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x80015B14: bne         $v1, $zero, L_80015B94
    if (ctx->r3 != 0) {
        // 0x80015B18: andi        $a2, $v0, 0x7
        ctx->r6 = ctx->r2 & 0X7;
            goto L_80015B94;
    }
    // 0x80015B18: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x80015B1C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80015B20: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x80015B24: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x80015B28: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80015B2C: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x80015B30: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80015B34: subu        $v1, $t8, $v1
    ctx->r3 = SUB32(ctx->r24, ctx->r3);
    // 0x80015B38: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80015B3C: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80015B40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015B44: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80015B48: lb          $v0, 0x58($t1)
    ctx->r2 = MEM_B(ctx->r9, 0X58);
    // 0x80015B4C: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80015B50: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x80015B54: addiu       $v0, $v0, 0x48
    ctx->r2 = ADD32(ctx->r2, 0X48);
    // 0x80015B58: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80015B5C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80015B60: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80015B64: or          $v0, $v0, $t7
    ctx->r2 = ctx->r2 | ctx->r15;
    // 0x80015B68: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80015B6C: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80015B70: lb          $v1, 0x58($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X58);
    // 0x80015B74: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80015B78: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x80015B7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015B80: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80015B84: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x80015B88: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80015B8C: j           L_80015C08
    // 0x80015B90: subu        $v0, $t8, $v0
    ctx->r2 = SUB32(ctx->r24, ctx->r2);
        goto L_80015C08;
    // 0x80015B90: subu        $v0, $t8, $v0
    ctx->r2 = SUB32(ctx->r24, ctx->r2);
L_80015B94:
    // 0x80015B94: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80015B98: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x80015B9C: sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4 << 24);
    // 0x80015BA0: sra         $a0, $a0, 24
    ctx->r4 = S32(SIGNED(ctx->r4) >> 24);
    // 0x80015BA4: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x80015BA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015BAC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80015BB0: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80015BB4: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80015BB8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80015BBC: addiu       $v1, $v1, 0xE8
    ctx->r3 = ADD32(ctx->r3, 0XE8);
    // 0x80015BC0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80015BC4: lb          $v0, 0x58($t1)
    ctx->r2 = MEM_B(ctx->r9, 0X58);
    // 0x80015BC8: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80015BCC: sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3 << 12);
    // 0x80015BD0: addiu       $v0, $v0, 0x48
    ctx->r2 = ADD32(ctx->r2, 0X48);
    // 0x80015BD4: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x80015BD8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80015BDC: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80015BE0: or          $v0, $v0, $t7
    ctx->r2 = ctx->r2 | ctx->r15;
    // 0x80015BE4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80015BE8: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80015BEC: lb          $v1, 0x58($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X58);
    // 0x80015BF0: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x80015BF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015BF8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80015BFC: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x80015C00: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80015C04: addiu       $v0, $v0, 0xE8
    ctx->r2 = ADD32(ctx->r2, 0XE8);
L_80015C08:
    // 0x80015C08: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80015C0C: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80015C10: sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2 << 12);
    // 0x80015C14: sw          $t6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r14;
    // 0x80015C18: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x80015C1C: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x80015C20: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80015C24: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x80015C28: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80015C2C: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80015C30: sll         $v0, $a3, 24
    ctx->r2 = S32(ctx->r7 << 24);
    // 0x80015C34: sra         $v0, $v0, 23
    ctx->r2 = S32(SIGNED(ctx->r2) >> 23);
    // 0x80015C38: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x80015C3C: lb          $a0, 0x0($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X0);
    // 0x80015C40: lb          $v1, 0x1($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1);
    // 0x80015C44: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x80015C48: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015C4C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80015C50: sw          $t5, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r13;
    // 0x80015C54: sw          $t0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r8;
    // 0x80015C58: sll         $a0, $a0, 21
    ctx->r4 = S32(ctx->r4 << 21);
    // 0x80015C5C: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x80015C60: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80015C64: or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // 0x80015C68: sw          $a0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r4;
L_80015C6C:
    // 0x80015C6C: andi        $v0, $t3, 0xF
    ctx->r2 = ctx->r11 & 0XF;
    // 0x80015C70: lb          $v1, 0xCD($t1)
    ctx->r3 = MEM_B(ctx->r9, 0XCD);
    // 0x80015C74: addu        $t3, $v0, $zero
    ctx->r11 = ADD32(ctx->r2, 0);
    // 0x80015C78: bne         $v0, $v1, L_80015AC0
    if (ctx->r2 != ctx->r3) {
        // 0x80015C7C: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_80015AC0;
    }
    // 0x80015C7C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_80015C80:
    // 0x80015C80: jr          $ra
    // 0x80015C84: nop

    return;
    // 0x80015C84: nop

;}
RECOMP_FUNC void func_80015C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015C88: jr          $ra
    // 0x80015C8C: nop

    return;
    // 0x80015C8C: nop

;}
RECOMP_FUNC void func_80015C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015C90: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80015C94: lb          $v1, 0x5A($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X5A);
    // 0x80015C98: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80015C9C: beq         $v1, $v0, L_80016060
    if (ctx->r3 == ctx->r2) {
        // 0x80015CA0: nop
    
            goto L_80016060;
    }
    // 0x80015CA0: nop

    // 0x80015CA4: lbu         $v0, 0x63($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X63);
    // 0x80015CA8: beq         $v0, $zero, L_80016060
    if (ctx->r2 == 0) {
        // 0x80015CAC: lui         $v1, 0xBA00
        ctx->r3 = S32(0XBA00 << 16);
            goto L_80016060;
    }
    // 0x80015CAC: lui         $v1, 0xBA00
    ctx->r3 = S32(0XBA00 << 16);
    // 0x80015CB0: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80015CB4: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x80015CB8: ori         $v1, $v1, 0x1402
    ctx->r3 = ctx->r3 | 0X1402;
    // 0x80015CBC: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80015CC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015CC4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80015CC8: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x80015CCC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80015CD0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80015CD4: addiu       $v0, $v0, -0x67D0
    ctx->r2 = ADD32(ctx->r2, -0X67D0);
    // 0x80015CD8: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x80015CDC: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x80015CE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015CE4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80015CE8: lui         $v0, 0x30
    ctx->r2 = S32(0X30 << 16);
    // 0x80015CEC: sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    // 0x80015CF0: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x80015CF4: lb          $v0, 0x51($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X51);
    // 0x80015CF8: bne         $v0, $zero, L_80015D74
    if (ctx->r2 != 0) {
        // 0x80015CFC: addiu       $v0, $a0, 0x18
        ctx->r2 = ADD32(ctx->r4, 0X18);
            goto L_80015D74;
    }
    // 0x80015CFC: addiu       $v0, $a0, 0x18
    ctx->r2 = ADD32(ctx->r4, 0X18);
    // 0x80015D00: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80015D04: lhu         $v1, 0x7BC0($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X7BC0);
    // 0x80015D08: andi        $v0, $v1, 0x40
    ctx->r2 = ctx->r3 & 0X40;
    // 0x80015D0C: beq         $v0, $zero, L_80015D1C
    if (ctx->r2 == 0) {
        // 0x80015D10: andi        $v0, $v1, 0x3F
        ctx->r2 = ctx->r3 & 0X3F;
            goto L_80015D1C;
    }
    // 0x80015D10: andi        $v0, $v1, 0x3F
    ctx->r2 = ctx->r3 & 0X3F;
    // 0x80015D14: j           L_80015D28
    // 0x80015D18: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
        goto L_80015D28;
    // 0x80015D18: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
L_80015D1C:
    // 0x80015D1C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80015D20: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80015D24: subu        $a1, $v1, $v0
    ctx->r5 = SUB32(ctx->r3, ctx->r2);
L_80015D28:
    // 0x80015D28: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80015D2C: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x80015D30: sll         $v1, $a1, 8
    ctx->r3 = S32(ctx->r5 << 8);
    // 0x80015D34: andi        $v1, $v1, 0xF800
    ctx->r3 = ctx->r3 & 0XF800;
    // 0x80015D38: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80015D3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015D40: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80015D44: lui         $v0, 0xF700
    ctx->r2 = S32(0XF700 << 16);
    // 0x80015D48: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80015D4C: sra         $v0, $a1, 2
    ctx->r2 = S32(SIGNED(ctx->r5) >> 2);
    // 0x80015D50: andi        $v0, $v0, 0x3E
    ctx->r2 = ctx->r2 & 0X3E;
    // 0x80015D54: ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
    // 0x80015D58: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80015D5C: ori         $v0, $v1, 0x1
    ctx->r2 = ctx->r3 | 0X1;
    // 0x80015D60: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80015D64: ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // 0x80015D68: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80015D6C: j           L_80015DAC
    // 0x80015D70: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
        goto L_80015DAC;
    // 0x80015D70: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_80015D74:
    // 0x80015D74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015D78: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80015D7C: lui         $v0, 0xF700
    ctx->r2 = S32(0XF700 << 16);
    // 0x80015D80: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x80015D84: lbu         $v0, 0x51($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X51);
    // 0x80015D88: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x80015D8C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80015D90: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80015D94: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80015D98: lw          $v0, -0x4038($at)
    ctx->r2 = MEM_W(ctx->r1, -0X4038);
    // 0x80015D9C: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // 0x80015DA0: lbu         $v0, 0x51($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X51);
    // 0x80015DA4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80015DA8: sb          $v0, 0x51($a2)
    MEM_B(0X51, ctx->r6) = ctx->r2;
L_80015DAC:
    // 0x80015DAC: lbu         $v0, 0x5($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X5);
    // 0x80015DB0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80015DB4: bne         $v0, $zero, L_80015EF4
    if (ctx->r2 != 0) {
        // 0x80015DB8: nop
    
            goto L_80015EF4;
    }
    // 0x80015DB8: nop

    // 0x80015DBC: lbu         $v0, 0x63($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X63);
    // 0x80015DC0: lwc1        $f0, 0xC($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80015DC4: lwc1        $f6, 0xC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80015DC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80015DCC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80015DD0: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x80015DD4: nop

    // 0x80015DD8: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80015DDC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80015DE0: sub.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80015DE4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80015DE8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80015DEC: lui         $at, 0x4358
    ctx->r1 = S32(0X4358 << 16);
    // 0x80015DF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80015DF4: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80015DF8: sub.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80015DFC: lui         $at, 0x41F8
    ctx->r1 = S32(0X41F8 << 16);
    // 0x80015E00: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80015E04: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80015E08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80015E0C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80015E10: mul.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80015E14: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80015E18: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80015E1C: sub.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80015E20: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80015E24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015E28: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80015E2C: trunc.w.s   $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80015E30: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80015E34: add.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80015E38: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80015E3C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80015E40: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // 0x80015E44: nor         $v0, $zero, $a1
    ctx->r2 = ~(0 | ctx->r5);
    // 0x80015E48: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80015E4C: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80015E50: nop

    // 0x80015E54: bc1t        L_80015E70
    if (c1cs) {
        // 0x80015E58: and         $a1, $a1, $v0
        ctx->r5 = ctx->r5 & ctx->r2;
            goto L_80015E70;
    }
    // 0x80015E58: and         $a1, $a1, $v0
    ctx->r5 = ctx->r5 & ctx->r2;
    // 0x80015E5C: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80015E60: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x80015E64: nop

    // 0x80015E68: j           L_80015E88
    // 0x80015E6C: lui         $v1, 0xF600
    ctx->r3 = S32(0XF600 << 16);
        goto L_80015E88;
    // 0x80015E6C: lui         $v1, 0xF600
    ctx->r3 = S32(0XF600 << 16);
L_80015E70:
    // 0x80015E70: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80015E74: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80015E78: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x80015E7C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80015E80: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80015E84: lui         $v1, 0xF600
    ctx->r3 = S32(0XF600 << 16);
L_80015E88:
    // 0x80015E88: ori         $v1, $v1, 0x35C
    ctx->r3 = ctx->r3 | 0X35C;
    // 0x80015E8C: andi        $v0, $a0, 0x3FF
    ctx->r2 = ctx->r4 & 0X3FF;
    // 0x80015E90: sll         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2 << 14);
    // 0x80015E94: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80015E98: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80015E9C: lwc1        $f0, 0xC($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80015EA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80015EA4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80015EA8: nop

    // 0x80015EAC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80015EB0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80015EB4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80015EB8: nop

    // 0x80015EBC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80015EC0: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80015EC4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80015EC8: nop

    // 0x80015ECC: add.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80015ED0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80015ED4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80015ED8: nop

    // 0x80015EDC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80015EE0: nop

    // 0x80015EE4: bc1f        L_80016024
    if (!c1cs) {
        // 0x80015EE8: nop
    
            goto L_80016024;
    }
    // 0x80015EE8: nop

    // 0x80015EEC: j           L_80016038
    // 0x80015EF0: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
        goto L_80016038;
    // 0x80015EF0: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
L_80015EF4:
    // 0x80015EF4: lbu         $v0, 0x63($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X63);
    // 0x80015EF8: lwc1        $f6, 0xC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80015EFC: lwc1        $f2, 0xC($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80015F00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80015F04: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80015F08: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80015F0C: nop

    // 0x80015F10: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80015F14: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80015F18: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80015F1C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80015F20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80015F24: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80015F28: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80015F2C: lui         $at, 0x4358
    ctx->r1 = S32(0X4358 << 16);
    // 0x80015F30: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80015F34: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80015F38: lui         $at, 0x4393
    ctx->r1 = S32(0X4393 << 16);
    // 0x80015F3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80015F40: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80015F44: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80015F48: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015F4C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80015F50: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80015F54: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80015F58: sub.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80015F5C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80015F60: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80015F64: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // 0x80015F68: nor         $v0, $zero, $a1
    ctx->r2 = ~(0 | ctx->r5);
    // 0x80015F6C: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80015F70: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80015F74: nop

    // 0x80015F78: bc1t        L_80015F94
    if (c1cs) {
        // 0x80015F7C: and         $a1, $a1, $v0
        ctx->r5 = ctx->r5 & ctx->r2;
            goto L_80015F94;
    }
    // 0x80015F7C: and         $a1, $a1, $v0
    ctx->r5 = ctx->r5 & ctx->r2;
    // 0x80015F80: trunc.w.s   $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80015F84: mfc1        $a0, $f0
    ctx->r4 = (int32_t)ctx->f0.u32l;
    // 0x80015F88: nop

    // 0x80015F8C: j           L_80015FAC
    // 0x80015F90: lui         $v1, 0xF600
    ctx->r3 = S32(0XF600 << 16);
        goto L_80015FAC;
    // 0x80015F90: lui         $v1, 0xF600
    ctx->r3 = S32(0XF600 << 16);
L_80015F94:
    // 0x80015F94: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80015F98: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80015F9C: mfc1        $a0, $f2
    ctx->r4 = (int32_t)ctx->f2.u32l;
    // 0x80015FA0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80015FA4: or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // 0x80015FA8: lui         $v1, 0xF600
    ctx->r3 = S32(0XF600 << 16);
L_80015FAC:
    // 0x80015FAC: ori         $v1, $v1, 0x35C
    ctx->r3 = ctx->r3 | 0X35C;
    // 0x80015FB0: andi        $v0, $a0, 0x3FF
    ctx->r2 = ctx->r4 & 0X3FF;
    // 0x80015FB4: sll         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2 << 14);
    // 0x80015FB8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x80015FBC: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80015FC0: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80015FC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80015FC8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80015FCC: nop

    // 0x80015FD0: sub.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80015FD4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80015FD8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80015FDC: nop

    // 0x80015FE0: mul.s       $f2, $f4, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80015FE4: lui         $at, 0x4390
    ctx->r1 = S32(0X4390 << 16);
    // 0x80015FE8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80015FEC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80015FF0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80015FF4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80015FF8: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80015FFC: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80016000: sub.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80016004: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80016008: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001600C: nop

    // 0x80016010: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80016014: nop

    // 0x80016018: nop

    // 0x8001601C: bc1tl       L_80016038
    if (c1cs) {
        // 0x80016020: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_80016038;
    }
    goto skip_0;
    // 0x80016020: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_0:
L_80016024:
    // 0x80016024: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80016028: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8001602C: nop

    // 0x80016030: j           L_8001604C
    // 0x80016034: andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
        goto L_8001604C;
    // 0x80016034: andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
L_80016038:
    // 0x80016038: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001603C: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x80016040: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x80016044: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80016048: andi        $v1, $v1, 0x3FF
    ctx->r3 = ctx->r3 & 0X3FF;
L_8001604C:
    // 0x8001604C: sll         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3 << 14);
    // 0x80016050: andi        $v0, $a1, 0x3FF
    ctx->r2 = ctx->r5 & 0X3FF;
    // 0x80016054: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80016058: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8001605C: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
L_80016060:
    // 0x80016060: jr          $ra
    // 0x80016064: nop

    return;
    // 0x80016064: nop

;}
RECOMP_FUNC void func_80016068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016068: lbu         $v0, 0x74($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X74);
    // 0x8001606C: lb          $a1, 0x4F($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X4F);
    // 0x80016070: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80016074: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x80016078: lb          $t0, -0x3AC8($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X3AC8);
    // 0x8001607C: mult        $a1, $t0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016080: mflo        $a1
    ctx->r5 = lo;
    // 0x80016084: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80016088: lbu         $a2, 0x7B82($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X7B82);
    // 0x8001608C: lui         $a3, 0x8888
    ctx->r7 = S32(0X8888 << 16);
    // 0x80016090: ori         $a3, $a3, 0x8889
    ctx->r7 = ctx->r7 | 0X8889;
    // 0x80016094: sll         $v1, $a2, 4
    ctx->r3 = S32(ctx->r6 << 4);
    // 0x80016098: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001609C: lbu         $v0, 0x7B81($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B81);
    // 0x800160A0: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x800160A4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800160A8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800160AC: mult        $v1, $a3
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800160B0: lhu         $v0, 0x7C($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X7C);
    // 0x800160B4: mfhi        $a2
    ctx->r6 = hi;
    // 0x800160B8: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x800160BC: nop

    // 0x800160C0: div         $zero, $v0, $t0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r8)));
    // 0x800160C4: bne         $t0, $zero, L_800160D0
    if (ctx->r8 != 0) {
        // 0x800160C8: nop
    
            goto L_800160D0;
    }
    // 0x800160C8: nop

    // 0x800160CC: break       7
    do_break(2147573964);
L_800160D0:
    // 0x800160D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800160D4: bne         $t0, $at, L_800160E8
    if (ctx->r8 != ctx->r1) {
        // 0x800160D8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800160E8;
    }
    // 0x800160D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800160DC: bne         $v0, $at, L_800160E8
    if (ctx->r2 != ctx->r1) {
        // 0x800160E0: nop
    
            goto L_800160E8;
    }
    // 0x800160E0: nop

    // 0x800160E4: break       6
    do_break(2147573988);
L_800160E8:
    // 0x800160E8: mflo        $t0
    ctx->r8 = lo;
    // 0x800160EC: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x800160F0: sra         $v0, $v0, 5
    ctx->r2 = S32(SIGNED(ctx->r2) >> 5);
    // 0x800160F4: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x800160F8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800160FC: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80016100: bne         $v0, $zero, L_8001611C
    if (ctx->r2 != 0) {
        // 0x80016104: slti        $v0, $t0, 0xA
        ctx->r2 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
            goto L_8001611C;
    }
    // 0x80016104: slti        $v0, $t0, 0xA
    ctx->r2 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x80016108: slti        $v0, $t0, 0x12
    ctx->r2 = SIGNED(ctx->r8) < 0X12 ? 1 : 0;
    // 0x8001610C: beql        $v0, $zero, L_80016124
    if (ctx->r2 == 0) {
        // 0x80016110: addiu       $t0, $zero, 0x11
        ctx->r8 = ADD32(0, 0X11);
            goto L_80016124;
    }
    goto skip_0;
    // 0x80016110: addiu       $t0, $zero, 0x11
    ctx->r8 = ADD32(0, 0X11);
    skip_0:
    // 0x80016114: j           L_80016128
    // 0x80016118: nor         $v0, $zero, $t0
    ctx->r2 = ~(0 | ctx->r8);
        goto L_80016128;
    // 0x80016118: nor         $v0, $zero, $t0
    ctx->r2 = ~(0 | ctx->r8);
L_8001611C:
    // 0x8001611C: beql        $v0, $zero, L_80016124
    if (ctx->r2 == 0) {
        // 0x80016120: addiu       $t0, $zero, 0x9
        ctx->r8 = ADD32(0, 0X9);
            goto L_80016124;
    }
    goto skip_1;
    // 0x80016120: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    skip_1:
L_80016124:
    // 0x80016124: nor         $v0, $zero, $t0
    ctx->r2 = ~(0 | ctx->r8);
L_80016128:
    // 0x80016128: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8001612C: and         $t0, $t0, $v0
    ctx->r8 = ctx->r8 & ctx->r2;
    // 0x80016130: jr          $ra
    // 0x80016134: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    return;
    // 0x80016134: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
;}
RECOMP_FUNC void func_80016138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016138: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x8001613C: lb          $v1, 0x5A($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X5A);
    // 0x80016140: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80016144: beq         $v1, $v0, L_80016238
    if (ctx->r3 == ctx->r2) {
        // 0x80016148: lui         $a2, 0x8888
        ctx->r6 = S32(0X8888 << 16);
            goto L_80016238;
    }
    // 0x80016148: lui         $a2, 0x8888
    ctx->r6 = S32(0X8888 << 16);
    // 0x8001614C: lbu         $v0, 0x74($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X74);
    // 0x80016150: lb          $a0, 0x4F($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X4F);
    // 0x80016154: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80016158: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x8001615C: lb          $a3, -0x3AC8($a3)
    ctx->r7 = MEM_B(ctx->r7, -0X3AC8);
    // 0x80016160: mult        $a0, $a3
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016164: mflo        $a0
    ctx->r4 = lo;
    // 0x80016168: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8001616C: lbu         $a1, 0x7B82($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X7B82);
    // 0x80016170: ori         $a2, $a2, 0x8889
    ctx->r6 = ctx->r6 | 0X8889;
    // 0x80016174: sll         $v1, $a1, 4
    ctx->r3 = S32(ctx->r5 << 4);
    // 0x80016178: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001617C: lbu         $v0, 0x7B81($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B81);
    // 0x80016180: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x80016184: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80016188: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001618C: mult        $v1, $a2
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016190: lhu         $v0, 0x7C($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X7C);
    // 0x80016194: mfhi        $a1
    ctx->r5 = hi;
    // 0x80016198: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8001619C: nop

    // 0x800161A0: div         $zero, $v0, $a3
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r7)));
    // 0x800161A4: bne         $a3, $zero, L_800161B0
    if (ctx->r7 != 0) {
        // 0x800161A8: nop
    
            goto L_800161B0;
    }
    // 0x800161A8: nop

    // 0x800161AC: break       7
    do_break(2147574188);
L_800161B0:
    // 0x800161B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800161B4: bne         $a3, $at, L_800161C8
    if (ctx->r7 != ctx->r1) {
        // 0x800161B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800161C8;
    }
    // 0x800161B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800161BC: bne         $v0, $at, L_800161C8
    if (ctx->r2 != ctx->r1) {
        // 0x800161C0: nop
    
            goto L_800161C8;
    }
    // 0x800161C0: nop

    // 0x800161C4: break       6
    do_break(2147574212);
L_800161C8:
    // 0x800161C8: mflo        $a3
    ctx->r7 = lo;
    // 0x800161CC: addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
    // 0x800161D0: sra         $v0, $v0, 5
    ctx->r2 = S32(SIGNED(ctx->r2) >> 5);
    // 0x800161D4: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x800161D8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800161DC: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800161E0: bne         $v0, $zero, L_800161FC
    if (ctx->r2 != 0) {
        // 0x800161E4: slti        $v0, $a3, 0xA
        ctx->r2 = SIGNED(ctx->r7) < 0XA ? 1 : 0;
            goto L_800161FC;
    }
    // 0x800161E4: slti        $v0, $a3, 0xA
    ctx->r2 = SIGNED(ctx->r7) < 0XA ? 1 : 0;
    // 0x800161E8: slti        $v0, $a3, 0x12
    ctx->r2 = SIGNED(ctx->r7) < 0X12 ? 1 : 0;
    // 0x800161EC: beql        $v0, $zero, L_80016204
    if (ctx->r2 == 0) {
        // 0x800161F0: addiu       $a3, $zero, 0x11
        ctx->r7 = ADD32(0, 0X11);
            goto L_80016204;
    }
    goto skip_0;
    // 0x800161F0: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    skip_0:
    // 0x800161F4: j           L_80016208
    // 0x800161F8: nor         $v0, $zero, $a3
    ctx->r2 = ~(0 | ctx->r7);
        goto L_80016208;
    // 0x800161F8: nor         $v0, $zero, $a3
    ctx->r2 = ~(0 | ctx->r7);
L_800161FC:
    // 0x800161FC: beql        $v0, $zero, L_80016204
    if (ctx->r2 == 0) {
        // 0x80016200: addiu       $a3, $zero, 0x9
        ctx->r7 = ADD32(0, 0X9);
            goto L_80016204;
    }
    goto skip_1;
    // 0x80016200: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    skip_1:
L_80016204:
    // 0x80016204: nor         $v0, $zero, $a3
    ctx->r2 = ~(0 | ctx->r7);
L_80016208:
    // 0x80016208: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8001620C: and         $a3, $a3, $v0
    ctx->r7 = ctx->r7 & ctx->r2;
    // 0x80016210: lbu         $v0, 0x74($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X74);
    // 0x80016214: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80016218: addiu       $a0, $a0, -0x3ABC
    ctx->r4 = ADD32(ctx->r4, -0X3ABC);
    // 0x8001621C: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80016220: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80016224: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80016228: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8001622C: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80016230: j           L_80016284
    // 0x80016234: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
        goto L_80016284;
    // 0x80016234: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
L_80016238:
    // 0x80016238: lhu         $v1, 0x7E($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X7E);
    // 0x8001623C: lui         $v0, 0xCCCC
    ctx->r2 = S32(0XCCCC << 16);
    // 0x80016240: ori         $v0, $v0, 0xCCCD
    ctx->r2 = ctx->r2 | 0XCCCD;
    // 0x80016244: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016248: lbu         $v0, 0x74($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X74);
    // 0x8001624C: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x80016250: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80016254: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80016258: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001625C: mfhi        $t1
    ctx->r9 = hi;
    // 0x80016260: srl         $a0, $t1, 3
    ctx->r4 = S32(U32(ctx->r9) >> 3);
    // 0x80016264: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80016268: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8001626C: slti        $v0, $a0, 0x38
    ctx->r2 = SIGNED(ctx->r4) < 0X38 ? 1 : 0;
    // 0x80016270: beq         $v0, $zero, L_80016284
    if (ctx->r2 == 0) {
        // 0x80016274: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80016284;
    }
    // 0x80016274: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80016278: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001627C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80016280: lb          $v0, -0x39E8($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X39E8);
L_80016284:
    // 0x80016284: jr          $ra
    // 0x80016288: nop

    return;
    // 0x80016288: nop

;}
RECOMP_FUNC void func_8001628C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001628C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80016290: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80016294: addu        $t4, $sp, $zero
    ctx->r12 = ADD32(ctx->r29, 0);
    // 0x80016298: addu        $t3, $sp, $zero
    ctx->r11 = ADD32(ctx->r29, 0);
    // 0x8001629C: lb          $v1, 0x54($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X54);
    // 0x800162A0: lw          $v0, 0xDC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XDC);
    // 0x800162A4: addu        $t5, $zero, $zero
    ctx->r13 = ADD32(0, 0);
    // 0x800162A8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800162AC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800162B0: lb          $v0, 0x4C($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X4C);
    // 0x800162B4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800162B8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800162BC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800162C0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800162C4: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
L_800162C8:
    // 0x800162C8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800162CC: addiu       $t2, $a3, -0x2
    ctx->r10 = ADD32(ctx->r7, -0X2);
    // 0x800162D0: addu        $t0, $t1, $zero
    ctx->r8 = ADD32(ctx->r9, 0);
L_800162D4:
    // 0x800162D4: lw          $v1, 0x1C($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1C);
    // 0x800162D8: addu        $v0, $v1, $t2
    ctx->r2 = ADD32(ctx->r3, ctx->r10);
    // 0x800162DC: slti        $v0, $v0, -0x5
    ctx->r2 = SIGNED(ctx->r2) < -0X5 ? 1 : 0;
    // 0x800162E0: bnel        $v0, $zero, L_8001634C
    if (ctx->r2 != 0) {
        // 0x800162E4: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8001634C;
    }
    goto skip_0;
    // 0x800162E4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x800162E8: lw          $a0, 0x18($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X18);
    // 0x800162EC: lw          $v0, 0xB0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XB0);
    // 0x800162F0: addu        $v1, $a3, $v1
    ctx->r3 = ADD32(ctx->r7, ctx->r3);
    // 0x800162F4: addu        $a0, $a1, $a0
    ctx->r4 = ADD32(ctx->r5, ctx->r4);
    // 0x800162F8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800162FC: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80016300: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80016304: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80016308: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8001630C: lbu         $v0, 0x4A($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4A);
    // 0x80016310: beql        $v0, $zero, L_8001634C
    if (ctx->r2 == 0) {
        // 0x80016314: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8001634C;
    }
    goto skip_1;
    // 0x80016314: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_1:
    // 0x80016318: lb          $v0, 0x0($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X0);
    // 0x8001631C: beql        $v0, $zero, L_8001634C
    if (ctx->r2 == 0) {
        // 0x80016320: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8001634C;
    }
    goto skip_2;
    // 0x80016320: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_2:
    // 0x80016324: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x80016328: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8001632C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80016330: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
    // 0x80016334: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x80016338: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8001633C: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x80016340: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80016344: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x80016348: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8001634C:
    // 0x8001634C: slti        $v0, $a1, 0x5
    ctx->r2 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x80016350: bne         $v0, $zero, L_800162D4
    if (ctx->r2 != 0) {
        // 0x80016354: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800162D4;
    }
    // 0x80016354: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80016358: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8001635C: slti        $v0, $a3, 0x5
    ctx->r2 = SIGNED(ctx->r7) < 0X5 ? 1 : 0;
    // 0x80016360: bne         $v0, $zero, L_800162C8
    if (ctx->r2 != 0) {
        // 0x80016364: addiu       $t1, $t1, 0x5
        ctx->r9 = ADD32(ctx->r9, 0X5);
            goto L_800162C8;
    }
    // 0x80016364: addiu       $t1, $t1, 0x5
    ctx->r9 = ADD32(ctx->r9, 0X5);
    // 0x80016368: beq         $t5, $zero, L_800163EC
    if (ctx->r13 == 0) {
        // 0x8001636C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800163EC;
    }
    // 0x8001636C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80016370: lb          $v1, 0x5A($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X5A);
    // 0x80016374: beq         $v1, $v0, L_800163C0
    if (ctx->r3 == ctx->r2) {
        // 0x80016378: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_800163C0;
    }
    // 0x80016378: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8001637C: lw          $v0, 0xD0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XD0);
    // 0x80016380: lb          $v1, 0x2($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X2);
    // 0x80016384: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80016388: beq         $v1, $v0, L_800163EC
    if (ctx->r3 == ctx->r2) {
        // 0x8001638C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800163EC;
    }
    // 0x8001638C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80016390: sb          $a0, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r4;
    // 0x80016394: sb          $zero, 0x3($a2)
    MEM_B(0X3, ctx->r6) = 0;
    // 0x80016398: sb          $v0, 0x49($a2)
    MEM_B(0X49, ctx->r6) = ctx->r2;
    // 0x8001639C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800163A0: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x800163A4: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800163A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800163AC: beq         $v1, $v0, L_800163EC
    if (ctx->r3 == ctx->r2) {
        // 0x800163B0: sb          $a0, 0x7B8D($at)
        MEM_B(0X7B8D, ctx->r1) = ctx->r4;
            goto L_800163EC;
    }
    // 0x800163B0: sb          $a0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r4;
    // 0x800163B4: lw          $v0, 0xD0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XD0);
    // 0x800163B8: j           L_800163E8
    // 0x800163BC: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
        goto L_800163E8;
    // 0x800163BC: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
L_800163C0:
    // 0x800163C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800163C4: sb          $a0, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r4;
    // 0x800163C8: sb          $zero, 0x3($a2)
    MEM_B(0X3, ctx->r6) = 0;
    // 0x800163CC: sb          $v0, 0x49($a2)
    MEM_B(0X49, ctx->r6) = ctx->r2;
    // 0x800163D0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800163D4: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x800163D8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800163DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800163E0: beq         $v1, $v0, L_800163EC
    if (ctx->r3 == ctx->r2) {
        // 0x800163E4: sb          $a0, 0x7B8D($at)
        MEM_B(0X7B8D, ctx->r1) = ctx->r4;
            goto L_800163EC;
    }
    // 0x800163E4: sb          $a0, 0x7B8D($at)
    MEM_B(0X7B8D, ctx->r1) = ctx->r4;
L_800163E8:
    // 0x800163E8: sb          $zero, 0x1($a2)
    MEM_B(0X1, ctx->r6) = 0;
L_800163EC:
    // 0x800163EC: jr          $ra
    // 0x800163F0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800163F0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800163F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800163F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800163F8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800163FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016400: jal         0x80016138
    // 0x80016404: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_80016138(rdram, ctx);
        goto after_0;
    // 0x80016404: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80016408: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // 0x8001640C: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x80016410: slti        $v1, $v1, 0xA
    ctx->r3 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80016414: beq         $v1, $zero, L_80016424
    if (ctx->r3 == 0) {
        // 0x80016418: sw          $v0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r2;
            goto L_80016424;
    }
    // 0x80016418: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x8001641C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80016420: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
L_80016424:
    // 0x80016424: lbu         $v0, 0x55($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X55);
    // 0x80016428: lw          $v1, 0xE0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XE0);
    // 0x8001642C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80016430: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x80016434: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x80016438: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8001643C: sb          $v0, 0x54($s0)
    MEM_B(0X54, ctx->r16) = ctx->r2;
    // 0x80016440: jal         0x800169C8
    // 0x80016444: sw          $v1, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->r3;
    func_800169C8(rdram, ctx);
        goto after_1;
    // 0x80016444: sw          $v1, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->r3;
    after_1:
    // 0x80016448: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001644C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80016450: jal         0x80016980
    // 0x80016454: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_2;
    // 0x80016454: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    after_2:
    // 0x80016458: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001645C: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x80016460: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x80016464: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x80016468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001646C: sb          $zero, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = 0;
    // 0x80016470: sb          $v0, 0x52($s0)
    MEM_B(0X52, ctx->r16) = ctx->r2;
    // 0x80016474: sb          $v0, 0x49($s0)
    MEM_B(0X49, ctx->r16) = ctx->r2;
    // 0x80016478: sw          $zero, 0x114($s0)
    MEM_W(0X114, ctx->r16) = 0;
    // 0x8001647C: jal         0x800164AC
    // 0x80016480: sw          $zero, 0x118($s0)
    MEM_W(0X118, ctx->r16) = 0;
    func_800164AC(rdram, ctx);
        goto after_3;
    // 0x80016480: sw          $zero, 0x118($s0)
    MEM_W(0X118, ctx->r16) = 0;
    after_3:
    // 0x80016484: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80016488: sb          $zero, 0x122($a0)
    MEM_B(0X122, ctx->r4) = 0;
    // 0x8001648C: sb          $zero, 0x121($a0)
    MEM_B(0X121, ctx->r4) = 0;
    // 0x80016490: sb          $zero, 0x120($a0)
    MEM_B(0X120, ctx->r4) = 0;
    // 0x80016494: jal         0x8001628C
    // 0x80016498: sb          $zero, 0x11F($a0)
    MEM_B(0X11F, ctx->r4) = 0;
    func_8001628C(rdram, ctx);
        goto after_4;
    // 0x80016498: sb          $zero, 0x11F($a0)
    MEM_B(0X11F, ctx->r4) = 0;
    after_4:
    // 0x8001649C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800164A0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800164A4: jr          $ra
    // 0x800164A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800164A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800164AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800164AC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800164B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800164B4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800164B8: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800164BC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800164C0: lb          $v1, 0x5A($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X5A);
    // 0x800164C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800164C8: bne         $v1, $v0, L_8001658C
    if (ctx->r3 != ctx->r2) {
        // 0x800164CC: nop
    
            goto L_8001658C;
    }
    // 0x800164CC: nop

    // 0x800164D0: jal         0x800167C8
    // 0x800164D4: nop

    func_800167C8(rdram, ctx);
        goto after_0;
    // 0x800164D4: nop

    after_0:
    // 0x800164D8: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800164DC: beq         $s1, $zero, L_8001658C
    if (ctx->r17 == 0) {
        // 0x800164E0: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_8001658C;
    }
    // 0x800164E0: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800164E4: sb          $s1, 0x5B($s0)
    MEM_B(0X5B, ctx->r16) = ctx->r17;
    // 0x800164E8: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x800164EC: addiu       $s1, $s1, 0x7B7C
    ctx->r17 = ADD32(ctx->r17, 0X7B7C);
    // 0x800164F0: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x800164F4: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x800164F8: sb          $zero, 0x49($s0)
    MEM_B(0X49, ctx->r16) = 0;
    // 0x800164FC: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80016500: jal         0x8006CEB0
    // 0x80016504: sb          $v0, 0x55($s0)
    MEM_B(0X55, ctx->r16) = ctx->r2;
    func_8006CEB0(rdram, ctx);
        goto after_1;
    // 0x80016504: sb          $v0, 0x55($s0)
    MEM_B(0X55, ctx->r16) = ctx->r2;
    after_1:
    // 0x80016508: lui         $v1, 0x8421
    ctx->r3 = S32(0X8421 << 16);
    // 0x8001650C: ori         $v1, $v1, 0x843
    ctx->r3 = ctx->r3 | 0X843;
    // 0x80016510: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016514: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80016518: lbu         $a1, 0x7B85($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X7B85);
    // 0x8001651C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80016520: addiu       $v1, $v1, -0x38B4
    ctx->r3 = ADD32(ctx->r3, -0X38B4);
    // 0x80016524: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80016528: andi        $a1, $a1, 0x3
    ctx->r5 = ctx->r5 & 0X3;
    // 0x8001652C: sll         $a1, $a1, 5
    ctx->r5 = S32(ctx->r5 << 5);
    // 0x80016530: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x80016534: sra         $v1, $v0, 31
    ctx->r3 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80016538: mfhi        $a3
    ctx->r7 = hi;
    // 0x8001653C: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x80016540: sra         $a0, $a0, 4
    ctx->r4 = S32(SIGNED(ctx->r4) >> 4);
    // 0x80016544: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x80016548: sll         $v1, $a0, 5
    ctx->r3 = S32(ctx->r4 << 5);
    // 0x8001654C: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80016550: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80016554: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80016558: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8001655C: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x80016560: lb          $v0, 0x11C($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X11C);
    // 0x80016564: beq         $v0, $zero, L_80016584
    if (ctx->r2 == 0) {
        // 0x80016568: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80016584;
    }
    // 0x80016568: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8001656C: lb          $v0, 0x5A($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5A);
    // 0x80016570: bnel        $v0, $zero, L_80016584
    if (ctx->r2 != 0) {
        // 0x80016574: sb          $zero, 0x11C($s0)
        MEM_B(0X11C, ctx->r16) = 0;
            goto L_80016584;
    }
    goto skip_0;
    // 0x80016574: sb          $zero, 0x11C($s0)
    MEM_B(0X11C, ctx->r16) = 0;
    skip_0:
    // 0x80016578: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8001657C: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x80016580: sb          $zero, 0x11C($s0)
    MEM_B(0X11C, ctx->r16) = 0;
L_80016584:
    // 0x80016584: j           L_800167B0
    // 0x80016588: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
        goto L_800167B0;
    // 0x80016588: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8001658C:
    // 0x8001658C: lb          $v0, 0x5A($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5A);
    // 0x80016590: bne         $v0, $zero, L_800166CC
    if (ctx->r2 != 0) {
        // 0x80016594: nop
    
            goto L_800166CC;
    }
    // 0x80016594: nop

    // 0x80016598: jal         0x800167C8
    // 0x8001659C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800167C8(rdram, ctx);
        goto after_2;
    // 0x8001659C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800165A0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800165A4: beq         $s1, $zero, L_800166CC
    if (ctx->r17 == 0) {
        // 0x800165A8: andi        $a1, $s1, 0x7F
        ctx->r5 = ctx->r17 & 0X7F;
            goto L_800166CC;
    }
    // 0x800165A8: andi        $a1, $s1, 0x7F
    ctx->r5 = ctx->r17 & 0X7F;
    // 0x800165AC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800165B0: addiu       $v0, $v0, -0x24E0
    ctx->r2 = ADD32(ctx->r2, -0X24E0);
    // 0x800165B4: sw          $v0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->r2;
    // 0x800165B8: lb          $v0, 0x5($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5);
    // 0x800165BC: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x800165C0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800165C4: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800165C8: beq         $v0, $zero, L_80016674
    if (ctx->r2 == 0) {
        // 0x800165CC: sb          $v1, 0x55($s0)
        MEM_B(0X55, ctx->r16) = ctx->r3;
            goto L_80016674;
    }
    // 0x800165CC: sb          $v1, 0x55($s0)
    MEM_B(0X55, ctx->r16) = ctx->r3;
    // 0x800165D0: addiu       $v0, $a1, -0x23
    ctx->r2 = ADD32(ctx->r5, -0X23);
    // 0x800165D4: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800165D8: beq         $v0, $zero, L_80016674
    if (ctx->r2 == 0) {
        // 0x800165DC: nop
    
            goto L_80016674;
    }
    // 0x800165DC: nop

    // 0x800165E0: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x800165E4: lb          $a0, 0x40B4($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X40B4);
    // 0x800165E8: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x800165EC: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x800165F0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800165F4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800165F8: lb          $v0, 0x40B0($at)
    ctx->r2 = MEM_B(ctx->r1, 0X40B0);
    // 0x800165FC: bne         $v1, $v0, L_80016644
    if (ctx->r3 != ctx->r2) {
        // 0x80016600: addiu       $v0, $a0, -0x2
        ctx->r2 = ADD32(ctx->r4, -0X2);
            goto L_80016644;
    }
    // 0x80016600: addiu       $v0, $a0, -0x2
    ctx->r2 = ADD32(ctx->r4, -0X2);
    // 0x80016604: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x80016608: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001660C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80016610: lb          $v0, 0x40B0($at)
    ctx->r2 = MEM_B(ctx->r1, 0X40B0);
    // 0x80016614: bne         $v1, $v0, L_80016644
    if (ctx->r3 != ctx->r2) {
        // 0x80016618: addiu       $v0, $a0, -0x3
        ctx->r2 = ADD32(ctx->r4, -0X3);
            goto L_80016644;
    }
    // 0x80016618: addiu       $v0, $a0, -0x3
    ctx->r2 = ADD32(ctx->r4, -0X3);
    // 0x8001661C: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x80016620: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80016624: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80016628: lb          $v0, 0x40B0($at)
    ctx->r2 = MEM_B(ctx->r1, 0X40B0);
    // 0x8001662C: bne         $v1, $v0, L_80016644
    if (ctx->r3 != ctx->r2) {
        // 0x80016630: slti        $v0, $a1, 0x25
        ctx->r2 = SIGNED(ctx->r5) < 0X25 ? 1 : 0;
            goto L_80016644;
    }
    // 0x80016630: slti        $v0, $a1, 0x25
    ctx->r2 = SIGNED(ctx->r5) < 0X25 ? 1 : 0;
    // 0x80016634: bne         $v0, $zero, L_80016644
    if (ctx->r2 != 0) {
        // 0x80016638: sb          $a2, 0x55($s0)
        MEM_B(0X55, ctx->r16) = ctx->r6;
            goto L_80016644;
    }
    // 0x80016638: sb          $a2, 0x55($s0)
    MEM_B(0X55, ctx->r16) = ctx->r6;
    // 0x8001663C: addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
    // 0x80016640: sb          $v0, 0x55($s0)
    MEM_B(0X55, ctx->r16) = ctx->r2;
L_80016644:
    // 0x80016644: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x80016648: lb          $v1, 0x40B4($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X40B4);
    // 0x8001664C: lbu         $v0, 0x55($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X55);
    // 0x80016650: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80016654: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80016658: sb          $v0, 0x40B0($at)
    MEM_B(0X40B0, ctx->r1) = ctx->r2;
    // 0x8001665C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80016660: lbu         $v0, 0x40B4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X40B4);
    // 0x80016664: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80016668: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8001666C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80016670: sb          $v0, 0x40B4($at)
    MEM_B(0X40B4, ctx->r1) = ctx->r2;
L_80016674:
    // 0x80016674: lb          $v0, 0x55($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X55);
    // 0x80016678: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8001667C: xori        $v0, $v0, 0x21
    ctx->r2 = ctx->r2 ^ 0X21;
    // 0x80016680: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80016684: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80016688: beq         $v1, $zero, L_8001669C
    if (ctx->r3 == 0) {
        // 0x8001668C: addiu       $a1, $zero, 0x9
        ctx->r5 = ADD32(0, 0X9);
            goto L_8001669C;
    }
    // 0x8001668C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80016690: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    // 0x80016694: j           L_800166A8
    // 0x80016698: xori        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 ^ 0X1;
        goto L_800166A8;
    // 0x80016698: xori        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 ^ 0X1;
L_8001669C:
    // 0x8001669C: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    // 0x800166A0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800166A4: xori        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 ^ 0X1;
L_800166A8:
    // 0x800166A8: jal         0x8001C0D0
    // 0x800166AC: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    func_8001C0D0(rdram, ctx);
        goto after_3;
    // 0x800166AC: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    after_3:
    // 0x800166B0: andi        $v0, $s1, 0x80
    ctx->r2 = ctx->r17 & 0X80;
    // 0x800166B4: beq         $v0, $zero, L_800167B0
    if (ctx->r2 == 0) {
        // 0x800166B8: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_800167B0;
    }
    // 0x800166B8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800166BC: lbu         $v0, 0x55($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X55);
    // 0x800166C0: ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // 0x800166C4: j           L_800167B0
    // 0x800166C8: sb          $v0, 0x55($s0)
    MEM_B(0X55, ctx->r16) = ctx->r2;
        goto L_800167B0;
    // 0x800166C8: sb          $v0, 0x55($s0)
    MEM_B(0X55, ctx->r16) = ctx->r2;
L_800166CC:
    // 0x800166CC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800166D0: addiu       $v0, $v0, -0x33F4
    ctx->r2 = ADD32(ctx->r2, -0X33F4);
    // 0x800166D4: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x800166D8: addiu       $s1, $s1, 0x7B7C
    ctx->r17 = ADD32(ctx->r17, 0X7B7C);
    // 0x800166DC: sw          $v0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->r2;
    // 0x800166E0: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x800166E4: lb          $v1, 0x5A($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X5A);
    // 0x800166E8: bne         $v1, $zero, L_80016710
    if (ctx->r3 != 0) {
        // 0x800166EC: sb          $v0, 0x55($s0)
        MEM_B(0X55, ctx->r16) = ctx->r2;
            goto L_80016710;
    }
    // 0x800166EC: sb          $v0, 0x55($s0)
    MEM_B(0X55, ctx->r16) = ctx->r2;
    // 0x800166F0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800166F4: lbu         $v0, 0x7B8A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8A);
    // 0x800166F8: beq         $v0, $zero, L_80016710
    if (ctx->r2 == 0) {
        // 0x800166FC: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80016710;
    }
    // 0x800166FC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80016700: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80016704: sb          $v0, 0x7B8A($at)
    MEM_B(0X7B8A, ctx->r1) = ctx->r2;
    // 0x80016708: j           L_80016770
    // 0x8001670C: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
        goto L_80016770;
    // 0x8001670C: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_80016710:
    // 0x80016710: jal         0x8006CEB0
    // 0x80016714: nop

    func_8006CEB0(rdram, ctx);
        goto after_4;
    // 0x80016714: nop

    after_4:
    // 0x80016718: lui         $v1, 0x8421
    ctx->r3 = S32(0X8421 << 16);
    // 0x8001671C: ori         $v1, $v1, 0x843
    ctx->r3 = ctx->r3 | 0X843;
    // 0x80016720: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016724: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80016728: lbu         $a1, 0x7B85($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X7B85);
    // 0x8001672C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80016730: addiu       $v1, $v1, -0x38B4
    ctx->r3 = ADD32(ctx->r3, -0X38B4);
    // 0x80016734: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80016738: andi        $a1, $a1, 0x3
    ctx->r5 = ctx->r5 & 0X3;
    // 0x8001673C: sll         $a1, $a1, 5
    ctx->r5 = S32(ctx->r5 << 5);
    // 0x80016740: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x80016744: sra         $v1, $v0, 31
    ctx->r3 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80016748: mfhi        $a3
    ctx->r7 = hi;
    // 0x8001674C: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x80016750: sra         $a0, $a0, 4
    ctx->r4 = S32(SIGNED(ctx->r4) >> 4);
    // 0x80016754: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x80016758: sll         $v1, $a0, 5
    ctx->r3 = S32(ctx->r4 << 5);
    // 0x8001675C: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80016760: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80016764: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80016768: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8001676C: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
L_80016770:
    // 0x80016770: lb          $v0, 0x11C($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X11C);
    // 0x80016774: beq         $v0, $zero, L_80016798
    if (ctx->r2 == 0) {
        // 0x80016778: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_80016798;
    }
    // 0x80016778: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8001677C: lb          $v0, 0x5A($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5A);
    // 0x80016780: bnel        $v0, $zero, L_80016798
    if (ctx->r2 != 0) {
        // 0x80016784: sb          $zero, 0x11C($s0)
        MEM_B(0X11C, ctx->r16) = 0;
            goto L_80016798;
    }
    goto skip_1;
    // 0x80016784: sb          $zero, 0x11C($s0)
    MEM_B(0X11C, ctx->r16) = 0;
    skip_1:
    // 0x80016788: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8001678C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80016790: sb          $v0, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = ctx->r2;
    // 0x80016794: sb          $zero, 0x11C($s0)
    MEM_B(0X11C, ctx->r16) = 0;
L_80016798:
    // 0x80016798: lbu         $a0, 0x5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5);
    // 0x8001679C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800167A0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800167A4: xori        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 ^ 0X1;
    // 0x800167A8: jal         0x8001C0D0
    // 0x800167AC: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    func_8001C0D0(rdram, ctx);
        goto after_5;
    // 0x800167AC: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    after_5:
L_800167B0:
    // 0x800167B0: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x800167B4: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800167B8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800167BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800167C0: jr          $ra
    // 0x800167C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800167C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800167C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800167C8: lb          $a1, 0xCC($a0)
    ctx->r5 = MEM_B(ctx->r4, 0XCC);
    // 0x800167CC: lb          $v0, 0xCD($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XCD);
    // 0x800167D0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800167D4: bne         $a1, $v0, L_800167E4
    if (ctx->r5 != ctx->r2) {
        // 0x800167D8: addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
            goto L_800167E4;
    }
    // 0x800167D8: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // 0x800167DC: j           L_800167FC
    // 0x800167E0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800167FC;
    // 0x800167E0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800167E4:
    // 0x800167E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800167E8: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800167EC: sb          $v1, 0xCC($a0)
    MEM_B(0XCC, ctx->r4) = ctx->r3;
    // 0x800167F0: lb          $v0, 0xBC($v0)
    ctx->r2 = MEM_B(ctx->r2, 0XBC);
    // 0x800167F4: andi        $v1, $v1, 0xF
    ctx->r3 = ctx->r3 & 0XF;
    // 0x800167F8: sb          $v1, 0xCC($a0)
    MEM_B(0XCC, ctx->r4) = ctx->r3;
L_800167FC:
    // 0x800167FC: jr          $ra
    // 0x80016800: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80016800: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80016804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016804: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80016808: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001680C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80016810: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80016814: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80016818: lb          $a2, 0xCD($s1)
    ctx->r6 = MEM_B(ctx->r17, 0XCD);
    // 0x8001681C: lb          $v1, 0xCC($s1)
    ctx->r3 = MEM_B(ctx->r17, 0XCC);
    // 0x80016820: addiu       $v0, $a2, 0x2
    ctx->r2 = ADD32(ctx->r6, 0X2);
    // 0x80016824: andi        $a0, $v0, 0xF
    ctx->r4 = ctx->r2 & 0XF;
    // 0x80016828: bne         $a0, $v1, L_80016950
    if (ctx->r4 != ctx->r3) {
        // 0x8001682C: addu        $a3, $a2, $zero
        ctx->r7 = ADD32(ctx->r6, 0);
            goto L_80016950;
    }
    // 0x8001682C: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x80016830: lb          $v1, 0x5A($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X5A);
    // 0x80016834: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80016838: beq         $v1, $v0, L_8001696C
    if (ctx->r3 == ctx->r2) {
        // 0x8001683C: addiu       $v0, $a2, -0x1
        ctx->r2 = ADD32(ctx->r6, -0X1);
            goto L_8001696C;
    }
    // 0x8001683C: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x80016840: andi        $s0, $v0, 0xF
    ctx->r16 = ctx->r2 & 0XF;
    // 0x80016844: beq         $s0, $a0, L_80016878
    if (ctx->r16 == ctx->r4) {
        // 0x80016848: addu        $v0, $s1, $s0
        ctx->r2 = ADD32(ctx->r17, ctx->r16);
            goto L_80016878;
    }
    // 0x80016848: addu        $v0, $s1, $s0
    ctx->r2 = ADD32(ctx->r17, ctx->r16);
    // 0x8001684C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80016850:
    // 0x80016850: lb          $v0, 0xBC($v0)
    ctx->r2 = MEM_B(ctx->r2, 0XBC);
    // 0x80016854: slti        $v0, $v0, 0x23
    ctx->r2 = SIGNED(ctx->r2) < 0X23 ? 1 : 0;
    // 0x80016858: bne         $v0, $zero, L_8001686C
    if (ctx->r2 != 0) {
        // 0x8001685C: addiu       $v0, $s0, -0x1
        ctx->r2 = ADD32(ctx->r16, -0X1);
            goto L_8001686C;
    }
    // 0x8001685C: addiu       $v0, $s0, -0x1
    ctx->r2 = ADD32(ctx->r16, -0X1);
    // 0x80016860: andi        $s0, $v0, 0xF
    ctx->r16 = ctx->r2 & 0XF;
    // 0x80016864: bne         $s0, $v1, L_80016850
    if (ctx->r16 != ctx->r3) {
        // 0x80016868: addu        $v0, $s1, $s0
        ctx->r2 = ADD32(ctx->r17, ctx->r16);
            goto L_80016850;
    }
    // 0x80016868: addu        $v0, $s1, $s0
    ctx->r2 = ADD32(ctx->r17, ctx->r16);
L_8001686C:
    // 0x8001686C: lb          $v0, 0xCC($s1)
    ctx->r2 = MEM_B(ctx->r17, 0XCC);
    // 0x80016870: bne         $s0, $v0, L_80016888
    if (ctx->r16 != ctx->r2) {
        // 0x80016874: addu        $v0, $s1, $s0
        ctx->r2 = ADD32(ctx->r17, ctx->r16);
            goto L_80016888;
    }
    // 0x80016874: addu        $v0, $s1, $s0
    ctx->r2 = ADD32(ctx->r17, ctx->r16);
L_80016878:
    // 0x80016878: lb          $v0, 0xBC($v0)
    ctx->r2 = MEM_B(ctx->r2, 0XBC);
    // 0x8001687C: slti        $v0, $v0, 0x23
    ctx->r2 = SIGNED(ctx->r2) < 0X23 ? 1 : 0;
    // 0x80016880: beq         $v0, $zero, L_8001696C
    if (ctx->r2 == 0) {
        // 0x80016884: nop
    
            goto L_8001696C;
    }
    // 0x80016884: nop

L_80016888:
    // 0x80016888: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001688C: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x80016890: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80016894: beq         $v1, $v0, L_8001691C
    if (ctx->r3 == ctx->r2) {
        // 0x80016898: nop
    
            goto L_8001691C;
    }
    // 0x80016898: nop

    // 0x8001689C: lb          $v0, 0x5($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X5);
    // 0x800168A0: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800168A4: beq         $v0, $zero, L_800168E4
    if (ctx->r2 == 0) {
        // 0x800168A8: nop
    
            goto L_800168E4;
    }
    // 0x800168A8: nop

    // 0x800168AC: jal         0x8006CEB0
    // 0x800168B0: nop

    func_8006CEB0(rdram, ctx);
        goto after_0;
    // 0x800168B0: nop

    after_0:
    // 0x800168B4: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800168B8: bgez        $a1, L_800168C4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800168BC: addu        $v1, $s1, $s0
        ctx->r3 = ADD32(ctx->r17, ctx->r16);
            goto L_800168C4;
    }
    // 0x800168BC: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
    // 0x800168C0: addiu       $v0, $a1, 0xF
    ctx->r2 = ADD32(ctx->r5, 0XF);
L_800168C4:
    // 0x800168C4: sra         $v0, $v0, 4
    ctx->r2 = S32(SIGNED(ctx->r2) >> 4);
    // 0x800168C8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800168CC: subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    // 0x800168D0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800168D4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800168D8: lbu         $v0, 0x164C($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X164C);
    // 0x800168DC: j           L_80016948
    // 0x800168E0: addiu       $v0, $v0, 0x22
    ctx->r2 = ADD32(ctx->r2, 0X22);
        goto L_80016948;
    // 0x800168E0: addiu       $v0, $v0, 0x22
    ctx->r2 = ADD32(ctx->r2, 0X22);
L_800168E4:
    // 0x800168E4: jal         0x8006CEB0
    // 0x800168E8: nop

    func_8006CEB0(rdram, ctx);
        goto after_1;
    // 0x800168E8: nop

    after_1:
    // 0x800168EC: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800168F0: bgez        $a1, L_800168FC
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800168F4: addu        $v1, $s1, $s0
        ctx->r3 = ADD32(ctx->r17, ctx->r16);
            goto L_800168FC;
    }
    // 0x800168F4: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
    // 0x800168F8: addiu       $v0, $a1, 0xF
    ctx->r2 = ADD32(ctx->r5, 0XF);
L_800168FC:
    // 0x800168FC: sra         $v0, $v0, 4
    ctx->r2 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80016900: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80016904: subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    // 0x80016908: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001690C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80016910: lbu         $v0, 0x163C($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X163C);
    // 0x80016914: j           L_80016948
    // 0x80016918: addiu       $v0, $v0, 0x22
    ctx->r2 = ADD32(ctx->r2, 0X22);
        goto L_80016948;
    // 0x80016918: addiu       $v0, $v0, 0x22
    ctx->r2 = ADD32(ctx->r2, 0X22);
L_8001691C:
    // 0x8001691C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80016920: addiu       $a0, $a0, 0x558C
    ctx->r4 = ADD32(ctx->r4, 0X558C);
    // 0x80016924: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80016928: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8001692C: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x80016930: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    // 0x80016934: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80016938: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001693C: lbu         $v0, 0x163C($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X163C);
    // 0x80016940: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
    // 0x80016944: addiu       $v0, $v0, 0x22
    ctx->r2 = ADD32(ctx->r2, 0X22);
L_80016948:
    // 0x80016948: j           L_8001696C
    // 0x8001694C: sb          $v0, 0xBC($v1)
    MEM_B(0XBC, ctx->r3) = ctx->r2;
        goto L_8001696C;
    // 0x8001694C: sb          $v0, 0xBC($v1)
    MEM_B(0XBC, ctx->r3) = ctx->r2;
L_80016950:
    // 0x80016950: addiu       $v0, $a3, 0x1
    ctx->r2 = ADD32(ctx->r7, 0X1);
    // 0x80016954: sb          $v0, 0xCD($s1)
    MEM_B(0XCD, ctx->r17) = ctx->r2;
    // 0x80016958: addu        $v0, $s1, $a2
    ctx->r2 = ADD32(ctx->r17, ctx->r6);
    // 0x8001695C: sb          $a1, 0xBC($v0)
    MEM_B(0XBC, ctx->r2) = ctx->r5;
    // 0x80016960: lbu         $v0, 0xCD($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XCD);
    // 0x80016964: andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // 0x80016968: sb          $v0, 0xCD($s1)
    MEM_B(0XCD, ctx->r17) = ctx->r2;
L_8001696C:
    // 0x8001696C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80016970: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80016974: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80016978: jr          $ra
    // 0x8001697C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001697C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80016980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016980: lw          $v1, 0xDC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XDC);
    // 0x80016984: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80016988: addiu       $v0, $v0, -0x33F4
    ctx->r2 = ADD32(ctx->r2, -0X33F4);
    // 0x8001698C: beq         $v1, $v0, L_800169AC
    if (ctx->r3 == ctx->r2) {
        // 0x80016990: nop
    
            goto L_800169AC;
    }
    // 0x80016990: nop

    // 0x80016994: lb          $v0, 0x54($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X54);
    // 0x80016998: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001699C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800169A0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800169A4: j           L_800169C0
    // 0x800169A8: lb          $v0, -0x3DA7($at)
    ctx->r2 = MEM_B(ctx->r1, -0X3DA7);
        goto L_800169C0;
    // 0x800169A8: lb          $v0, -0x3DA7($at)
    ctx->r2 = MEM_B(ctx->r1, -0X3DA7);
L_800169AC:
    // 0x800169AC: lb          $v0, 0x54($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X54);
    // 0x800169B0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800169B4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800169B8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800169BC: lb          $v0, -0x3DB7($at)
    ctx->r2 = MEM_B(ctx->r1, -0X3DB7);
L_800169C0:
    // 0x800169C0: jr          $ra
    // 0x800169C4: nop

    return;
    // 0x800169C4: nop

;}
RECOMP_FUNC void func_800169C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800169C8: lw          $v1, 0xDC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XDC);
    // 0x800169CC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x800169D0: addiu       $v0, $v0, -0x33F4
    ctx->r2 = ADD32(ctx->r2, -0X33F4);
    // 0x800169D4: beq         $v1, $v0, L_800169F4
    if (ctx->r3 == ctx->r2) {
        // 0x800169D8: nop
    
            goto L_800169F4;
    }
    // 0x800169D8: nop

    // 0x800169DC: lb          $v0, 0x54($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X54);
    // 0x800169E0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800169E4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800169E8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800169EC: j           L_80016A08
    // 0x800169F0: lb          $v0, -0x3DA8($at)
    ctx->r2 = MEM_B(ctx->r1, -0X3DA8);
        goto L_80016A08;
    // 0x800169F0: lb          $v0, -0x3DA8($at)
    ctx->r2 = MEM_B(ctx->r1, -0X3DA8);
L_800169F4:
    // 0x800169F4: lb          $v0, 0x54($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X54);
    // 0x800169F8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800169FC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80016A00: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80016A04: lb          $v0, -0x3DB8($at)
    ctx->r2 = MEM_B(ctx->r1, -0X3DB8);
L_80016A08:
    // 0x80016A08: jr          $ra
    // 0x80016A0C: nop

    return;
    // 0x80016A0C: nop

;}
RECOMP_FUNC void func_80016A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016A10: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80016A14: lbu         $v1, 0x74($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X74);
    // 0x80016A18: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80016A1C: addiu       $a1, $a1, -0x3998
    ctx->r5 = ADD32(ctx->r5, -0X3998);
    // 0x80016A20: lbu         $a0, 0x64($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X64);
    // 0x80016A24: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80016A28: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80016A2C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80016A30: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80016A34: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80016A38: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80016A3C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80016A40: lbu         $v1, 0x63($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X63);
    // 0x80016A44: addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
    // 0x80016A48: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80016A4C: bne         $v1, $zero, L_80016AA8
    if (ctx->r3 != 0) {
        // 0x80016A50: addiu       $v0, $zero, 0x80
        ctx->r2 = ADD32(0, 0X80);
            goto L_80016AA8;
    }
    // 0x80016A50: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x80016A54: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80016A58: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80016A5C: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x80016A60: beq         $v0, $zero, L_80016A8C
    if (ctx->r2 == 0) {
        // 0x80016A64: nop
    
            goto L_80016A8C;
    }
    // 0x80016A64: nop

    // 0x80016A68: lbu         $v0, 0x6C($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X6C);
    // 0x80016A6C: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // 0x80016A70: sb          $v0, 0x6C($a2)
    MEM_B(0X6C, ctx->r6) = ctx->r2;
    // 0x80016A74: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80016A78: sltiu       $v0, $v0, 0xD1
    ctx->r2 = ctx->r2 < 0XD1 ? 1 : 0;
    // 0x80016A7C: bne         $v0, $zero, L_80016AAC
    if (ctx->r2 != 0) {
        // 0x80016A80: addiu       $v0, $zero, 0xD0
        ctx->r2 = ADD32(0, 0XD0);
            goto L_80016AAC;
    }
    // 0x80016A80: addiu       $v0, $zero, 0xD0
    ctx->r2 = ADD32(0, 0XD0);
    // 0x80016A84: j           L_80016AAC
    // 0x80016A88: sb          $v0, 0x6C($a2)
    MEM_B(0X6C, ctx->r6) = ctx->r2;
        goto L_80016AAC;
    // 0x80016A88: sb          $v0, 0x6C($a2)
    MEM_B(0X6C, ctx->r6) = ctx->r2;
L_80016A8C:
    // 0x80016A8C: lbu         $v0, 0x6C($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X6C);
    // 0x80016A90: addiu       $v0, $v0, -0x5
    ctx->r2 = ADD32(ctx->r2, -0X5);
    // 0x80016A94: sb          $v0, 0x6C($a2)
    MEM_B(0X6C, ctx->r6) = ctx->r2;
    // 0x80016A98: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80016A9C: sltiu       $v0, $v0, 0x30
    ctx->r2 = ctx->r2 < 0X30 ? 1 : 0;
    // 0x80016AA0: beq         $v0, $zero, L_80016AAC
    if (ctx->r2 == 0) {
        // 0x80016AA4: addiu       $v0, $zero, 0x30
        ctx->r2 = ADD32(0, 0X30);
            goto L_80016AAC;
    }
    // 0x80016AA4: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
L_80016AA8:
    // 0x80016AA8: sb          $v0, 0x6C($a2)
    MEM_B(0X6C, ctx->r6) = ctx->r2;
L_80016AAC:
    // 0x80016AAC: jr          $ra
    // 0x80016AB0: nop

    return;
    // 0x80016AB0: nop

;}
RECOMP_FUNC void func_80016AB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016AB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80016AB8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80016ABC: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80016AC0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80016AC4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80016AC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80016ACC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80016AD0: sb          $s1, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r17;
    // 0x80016AD4: sb          $zero, 0x1($s2)
    MEM_B(0X1, ctx->r18) = 0;
    // 0x80016AD8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80016ADC: sb          $zero, 0x40B3($at)
    MEM_B(0X40B3, ctx->r1) = 0;
    // 0x80016AE0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80016AE4: sb          $zero, 0x40B2($at)
    MEM_B(0X40B2, ctx->r1) = 0;
    // 0x80016AE8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80016AEC: sb          $zero, 0x40B1($at)
    MEM_B(0X40B1, ctx->r1) = 0;
    // 0x80016AF0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80016AF4: sb          $zero, 0x40B0($at)
    MEM_B(0X40B0, ctx->r1) = 0;
    // 0x80016AF8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80016AFC: sb          $zero, 0x40B4($at)
    MEM_B(0X40B4, ctx->r1) = 0;
    // 0x80016B00: sb          $zero, 0x63($s2)
    MEM_B(0X63, ctx->r18) = 0;
    // 0x80016B04: sh          $zero, 0x7E($s2)
    MEM_H(0X7E, ctx->r18) = 0;
    // 0x80016B08: jal         0x80016138
    // 0x80016B0C: sh          $zero, 0x7C($s2)
    MEM_H(0X7C, ctx->r18) = 0;
    func_80016138(rdram, ctx);
        goto after_0;
    // 0x80016B0C: sh          $zero, 0x7C($s2)
    MEM_H(0X7C, ctx->r18) = 0;
    after_0:
    // 0x80016B10: sw          $v0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r2;
    // 0x80016B14: sw          $v0, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r2;
    // 0x80016B18: jal         0x8006CEB0
    // 0x80016B1C: sw          $zero, 0x30($s2)
    MEM_W(0X30, ctx->r18) = 0;
    func_8006CEB0(rdram, ctx);
        goto after_1;
    // 0x80016B1C: sw          $zero, 0x30($s2)
    MEM_W(0X30, ctx->r18) = 0;
    after_1:
    // 0x80016B20: lui         $s0, 0x9249
    ctx->r16 = S32(0X9249 << 16);
    // 0x80016B24: ori         $s0, $s0, 0x2493
    ctx->r16 = ctx->r16 | 0X2493;
    // 0x80016B28: mult        $v0, $s0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016B2C: sra         $v1, $v0, 31
    ctx->r3 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80016B30: mfhi        $a2
    ctx->r6 = hi;
    // 0x80016B34: addu        $a0, $a2, $v0
    ctx->r4 = ADD32(ctx->r6, ctx->r2);
    // 0x80016B38: sra         $a0, $a0, 2
    ctx->r4 = S32(SIGNED(ctx->r4) >> 2);
    // 0x80016B3C: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x80016B40: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x80016B44: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80016B48: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80016B4C: jal         0x8006CEB0
    // 0x80016B50: sb          $v0, 0x54($s2)
    MEM_B(0X54, ctx->r18) = ctx->r2;
    func_8006CEB0(rdram, ctx);
        goto after_2;
    // 0x80016B50: sb          $v0, 0x54($s2)
    MEM_B(0X54, ctx->r18) = ctx->r2;
    after_2:
    // 0x80016B54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016B58: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80016B5C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80016B60: addiu       $v1, $v1, -0x33F4
    ctx->r3 = ADD32(ctx->r3, -0X33F4);
    // 0x80016B64: sw          $v1, 0xE0($s2)
    MEM_W(0XE0, ctx->r18) = ctx->r3;
    // 0x80016B68: sw          $v1, 0xDC($s2)
    MEM_W(0XDC, ctx->r18) = ctx->r3;
    // 0x80016B6C: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x80016B70: sw          $v1, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->r3;
    // 0x80016B74: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80016B78: sw          $v1, 0x10C($s2)
    MEM_W(0X10C, ctx->r18) = ctx->r3;
    // 0x80016B7C: addiu       $v1, $zero, 0x80
    ctx->r3 = ADD32(0, 0X80);
    // 0x80016B80: sb          $v1, 0x6C($s2)
    MEM_B(0X6C, ctx->r18) = ctx->r3;
    // 0x80016B84: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80016B88: sb          $v1, 0x57($s2)
    MEM_B(0X57, ctx->r18) = ctx->r3;
    // 0x80016B8C: sra         $v1, $v0, 31
    ctx->r3 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80016B90: mult        $v0, $s0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016B94: sh          $zero, 0x92($s2)
    MEM_H(0X92, ctx->r18) = 0;
    // 0x80016B98: sh          $zero, 0x90($s2)
    MEM_H(0X90, ctx->r18) = 0;
    // 0x80016B9C: sh          $zero, 0x8E($s2)
    MEM_H(0X8E, ctx->r18) = 0;
    // 0x80016BA0: sh          $zero, 0x8C($s2)
    MEM_H(0X8C, ctx->r18) = 0;
    // 0x80016BA4: sh          $zero, 0x8A($s2)
    MEM_H(0X8A, ctx->r18) = 0;
    // 0x80016BA8: sh          $zero, 0x88($s2)
    MEM_H(0X88, ctx->r18) = 0;
    // 0x80016BAC: sh          $zero, 0x86($s2)
    MEM_H(0X86, ctx->r18) = 0;
    // 0x80016BB0: sh          $zero, 0x94($s2)
    MEM_H(0X94, ctx->r18) = 0;
    // 0x80016BB4: sb          $zero, 0x6A($s2)
    MEM_B(0X6A, ctx->r18) = 0;
    // 0x80016BB8: sb          $zero, 0x5E($s2)
    MEM_B(0X5E, ctx->r18) = 0;
    // 0x80016BBC: sb          $zero, 0x5F($s2)
    MEM_B(0X5F, ctx->r18) = 0;
    // 0x80016BC0: sb          $zero, 0x61($s2)
    MEM_B(0X61, ctx->r18) = 0;
    // 0x80016BC4: sb          $zero, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = 0;
    // 0x80016BC8: sb          $zero, 0x62($s2)
    MEM_B(0X62, ctx->r18) = 0;
    // 0x80016BCC: sb          $zero, 0x67($s2)
    MEM_B(0X67, ctx->r18) = 0;
    // 0x80016BD0: sw          $zero, 0x8($s2)
    MEM_W(0X8, ctx->r18) = 0;
    // 0x80016BD4: sw          $zero, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = 0;
    // 0x80016BD8: sw          $zero, 0x38($s2)
    MEM_W(0X38, ctx->r18) = 0;
    // 0x80016BDC: sb          $s1, 0x52($s2)
    MEM_B(0X52, ctx->r18) = ctx->r17;
    // 0x80016BE0: sb          $zero, 0x6F($s2)
    MEM_B(0X6F, ctx->r18) = 0;
    // 0x80016BE4: sb          $zero, 0x6E($s2)
    MEM_B(0X6E, ctx->r18) = 0;
    // 0x80016BE8: sb          $zero, 0x4F($s2)
    MEM_B(0X4F, ctx->r18) = 0;
    // 0x80016BEC: sb          $zero, 0x59($s2)
    MEM_B(0X59, ctx->r18) = 0;
    // 0x80016BF0: sb          $zero, 0x58($s2)
    MEM_B(0X58, ctx->r18) = 0;
    // 0x80016BF4: swc1        $f0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
    // 0x80016BF8: swc1        $f0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f0.u32l;
    // 0x80016BFC: mfhi        $a2
    ctx->r6 = hi;
    // 0x80016C00: addu        $a0, $a2, $v0
    ctx->r4 = ADD32(ctx->r6, ctx->r2);
    // 0x80016C04: sra         $a0, $a0, 2
    ctx->r4 = S32(SIGNED(ctx->r4) >> 2);
    // 0x80016C08: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x80016C0C: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x80016C10: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80016C14: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80016C18: sb          $v0, 0x55($s2)
    MEM_B(0X55, ctx->r18) = ctx->r2;
    // 0x80016C1C: sb          $zero, 0x71($s2)
    MEM_B(0X71, ctx->r18) = 0;
    // 0x80016C20: sb          $zero, 0x70($s2)
    MEM_B(0X70, ctx->r18) = 0;
    // 0x80016C24: sb          $zero, 0x72($s2)
    MEM_B(0X72, ctx->r18) = 0;
    // 0x80016C28: sb          $zero, 0x73($s2)
    MEM_B(0X73, ctx->r18) = 0;
    // 0x80016C2C: sb          $zero, 0x6B($s2)
    MEM_B(0X6B, ctx->r18) = 0;
    // 0x80016C30: sb          $zero, 0x76($s2)
    MEM_B(0X76, ctx->r18) = 0;
    // 0x80016C34: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80016C38: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x80016C3C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80016C40: beq         $v1, $v0, L_80016C54
    if (ctx->r3 == ctx->r2) {
        // 0x80016C44: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_80016C54;
    }
    // 0x80016C44: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80016C48: sb          $zero, 0x4A($s2)
    MEM_B(0X4A, ctx->r18) = 0;
    // 0x80016C4C: jal         0x80014614
    // 0x80016C50: sb          $zero, 0x49($s2)
    MEM_B(0X49, ctx->r18) = 0;
    func_80014614(rdram, ctx);
        goto after_3;
    // 0x80016C50: sb          $zero, 0x49($s2)
    MEM_B(0X49, ctx->r18) = 0;
    after_3:
L_80016C54:
    // 0x80016C54: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x80016C58: addiu       $v0, $s2, 0x1C
    ctx->r2 = ADD32(ctx->r18, 0X1C);
L_80016C5C:
    // 0x80016C5C: sw          $zero, 0xE4($v0)
    MEM_W(0XE4, ctx->r2) = 0;
    // 0x80016C60: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80016C64: bgez        $v1, L_80016C5C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80016C68: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_80016C5C;
    }
    // 0x80016C68: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80016C6C: lw          $v1, 0xDC($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XDC);
    // 0x80016C70: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80016C74: addiu       $v0, $v0, -0x33F4
    ctx->r2 = ADD32(ctx->r2, -0X33F4);
    // 0x80016C78: sb          $zero, 0xCC($s2)
    MEM_B(0XCC, ctx->r18) = 0;
    // 0x80016C7C: sb          $zero, 0xCD($s2)
    MEM_B(0XCD, ctx->r18) = 0;
    // 0x80016C80: sb          $zero, 0x51($s2)
    MEM_B(0X51, ctx->r18) = 0;
    // 0x80016C84: bne         $v1, $v0, L_80016CA4
    if (ctx->r3 != ctx->r2) {
        // 0x80016C88: sb          $zero, 0x50($s2)
        MEM_B(0X50, ctx->r18) = 0;
            goto L_80016CA4;
    }
    // 0x80016C88: sb          $zero, 0x50($s2)
    MEM_B(0X50, ctx->r18) = 0;
    // 0x80016C8C: lb          $v0, 0x54($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X54);
    // 0x80016C90: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80016C94: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80016C98: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80016C9C: j           L_80016CB8
    // 0x80016CA0: lb          $v1, -0x3DB8($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X3DB8);
        goto L_80016CB8;
    // 0x80016CA0: lb          $v1, -0x3DB8($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X3DB8);
L_80016CA4:
    // 0x80016CA4: lb          $v0, 0x54($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X54);
    // 0x80016CA8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80016CAC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80016CB0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80016CB4: lb          $v1, -0x3DA8($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X3DA8);
L_80016CB8:
    // 0x80016CB8: lw          $v0, 0xDC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XDC);
    // 0x80016CBC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80016CC0: sw          $v1, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r3;
    // 0x80016CC4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80016CC8: addiu       $v1, $v1, -0x33F4
    ctx->r3 = ADD32(ctx->r3, -0X33F4);
    // 0x80016CCC: bne         $v0, $v1, L_80016CEC
    if (ctx->r2 != ctx->r3) {
        // 0x80016CD0: nop
    
            goto L_80016CEC;
    }
    // 0x80016CD0: nop

    // 0x80016CD4: lb          $v0, 0x54($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X54);
    // 0x80016CD8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80016CDC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80016CE0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80016CE4: j           L_80016D00
    // 0x80016CE8: lb          $v0, -0x3DB7($at)
    ctx->r2 = MEM_B(ctx->r1, -0X3DB7);
        goto L_80016D00;
    // 0x80016CE8: lb          $v0, -0x3DB7($at)
    ctx->r2 = MEM_B(ctx->r1, -0X3DB7);
L_80016CEC:
    // 0x80016CEC: lb          $v0, 0x54($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X54);
    // 0x80016CF0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80016CF4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80016CF8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80016CFC: lb          $v0, -0x3DA7($at)
    ctx->r2 = MEM_B(ctx->r1, -0X3DA7);
L_80016D00:
    // 0x80016D00: lw          $v1, 0xD4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0XD4);
    // 0x80016D04: sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // 0x80016D08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80016D0C: sb          $zero, 0x122($s2)
    MEM_B(0X122, ctx->r18) = 0;
    // 0x80016D10: sb          $zero, 0x121($s2)
    MEM_B(0X121, ctx->r18) = 0;
    // 0x80016D14: sb          $zero, 0x120($s2)
    MEM_B(0X120, ctx->r18) = 0;
    // 0x80016D18: sb          $zero, 0x11F($s2)
    MEM_B(0X11F, ctx->r18) = 0;
    // 0x80016D1C: sb          $zero, 0x11C($s2)
    MEM_B(0X11C, ctx->r18) = 0;
    // 0x80016D20: sw          $zero, 0x118($s2)
    MEM_W(0X118, ctx->r18) = 0;
    // 0x80016D24: sw          $zero, 0x114($s2)
    MEM_W(0X114, ctx->r18) = 0;
    // 0x80016D28: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // 0x80016D2C: lb          $v1, 0x5A($s2)
    ctx->r3 = MEM_B(ctx->r18, 0X5A);
    // 0x80016D30: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80016D34: beq         $v1, $v0, L_80016D84
    if (ctx->r3 == ctx->r2) {
        // 0x80016D38: nop
    
            goto L_80016D84;
    }
    // 0x80016D38: nop

    // 0x80016D3C: lb          $v0, 0x5($s2)
    ctx->r2 = MEM_B(ctx->r18, 0X5);
    // 0x80016D40: bgez        $v0, L_80016D84
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80016D44: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80016D84;
    }
    // 0x80016D44: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80016D48: sb          $v0, 0x64($s2)
    MEM_B(0X64, ctx->r18) = ctx->r2;
    // 0x80016D4C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80016D50: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x80016D54: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80016D58: bne         $v1, $v0, L_80016D84
    if (ctx->r3 != ctx->r2) {
        // 0x80016D5C: nop
    
            goto L_80016D84;
    }
    // 0x80016D5C: nop

    // 0x80016D60: lbu         $v0, 0x74($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X74);
    // 0x80016D64: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80016D68: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80016D6C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80016D70: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80016D74: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80016D78: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80016D7C: lbu         $v0, -0x3996($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3996);
    // 0x80016D80: sb          $v0, 0x66($s2)
    MEM_B(0X66, ctx->r18) = ctx->r2;
L_80016D84:
    // 0x80016D84: lbu         $a1, 0x5($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X5);
    // 0x80016D88: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x80016D8C: jal         0x8000637C
    // 0x80016D90: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_4;
    // 0x80016D90: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_4:
    // 0x80016D94: lbu         $a0, 0x5($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X5);
    // 0x80016D98: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80016D9C: xori        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 ^ 0X1;
    // 0x80016DA0: jal         0x8001C0D0
    // 0x80016DA4: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    func_8001C0D0(rdram, ctx);
        goto after_5;
    // 0x80016DA4: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    after_5:
    // 0x80016DA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80016DAC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80016DB0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80016DB4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80016DB8: jr          $ra
    // 0x80016DBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80016DBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80016DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016DC0: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x80016DC4: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80016DC8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x80016DCC: addiu       $a3, $a1, 0xA
    ctx->r7 = ADD32(ctx->r5, 0XA);
L_80016DD0:
    // 0x80016DD0: lbu         $v0, 0x70($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X70);
    // 0x80016DD4: bne         $v0, $zero, L_80016DF0
    if (ctx->r2 != 0) {
        // 0x80016DD8: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80016DF0;
    }
    // 0x80016DD8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80016DDC: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_80016DE0:
    // 0x80016DE0: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80016DE4: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x80016DE8: beq         $v0, $zero, L_80016DE0
    if (ctx->r2 == 0) {
        // 0x80016DEC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80016DE0;
    }
    // 0x80016DEC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80016DF0:
    // 0x80016DF0: slt         $v0, $a0, $a2
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80016DF4: bnel        $v0, $zero, L_80016DFC
    if (ctx->r2 != 0) {
        // 0x80016DF8: addu        $a2, $a0, $zero
        ctx->r6 = ADD32(ctx->r4, 0);
            goto L_80016DFC;
    }
    goto skip_0;
    // 0x80016DF8: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    skip_0:
L_80016DFC:
    // 0x80016DFC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80016E00: slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80016E04: bne         $v0, $zero, L_80016DD0
    if (ctx->r2 != 0) {
        // 0x80016E08: nop
    
            goto L_80016DD0;
    }
    // 0x80016E08: nop

    // 0x80016E0C: jr          $ra
    // 0x80016E10: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    return;
    // 0x80016E10: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
;}
RECOMP_FUNC void func_80016E14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016E14: jr          $ra
    // 0x80016E18: nop

    return;
    // 0x80016E18: nop

;}
RECOMP_FUNC void func_80016E1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016E1C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80016E20: lhu         $v0, 0x7BC0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7BC0);
    // 0x80016E24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80016E28: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80016E2C: bne         $v0, $zero, L_80016F38
    if (ctx->r2 != 0) {
        // 0x80016E30: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80016F38;
    }
    // 0x80016E30: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80016E34: lb          $v0, 0x2($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X2);
    // 0x80016E38: xori        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 ^ 0X3;
    // 0x80016E3C: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80016E40: xori        $v0, $v0, 0x5
    ctx->r2 = ctx->r2 ^ 0X5;
    // 0x80016E44: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80016E48: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x80016E4C: bne         $v1, $zero, L_80016F38
    if (ctx->r3 != 0) {
        // 0x80016E50: addiu       $a3, $zero, 0x12
        ctx->r7 = ADD32(0, 0X12);
            goto L_80016F38;
    }
    // 0x80016E50: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    // 0x80016E54: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x80016E58: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80016E5C: addiu       $t0, $a2, 0xA
    ctx->r8 = ADD32(ctx->r6, 0XA);
L_80016E60:
    // 0x80016E60: lbu         $v0, 0x70($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X70);
    // 0x80016E64: bne         $v0, $zero, L_80016E80
    if (ctx->r2 != 0) {
        // 0x80016E68: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80016E80;
    }
    // 0x80016E68: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80016E6C: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
L_80016E70:
    // 0x80016E70: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80016E74: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x80016E78: beq         $v0, $zero, L_80016E70
    if (ctx->r2 == 0) {
        // 0x80016E7C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80016E70;
    }
    // 0x80016E7C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80016E80:
    // 0x80016E80: slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80016E84: bnel        $v0, $zero, L_80016E8C
    if (ctx->r2 != 0) {
        // 0x80016E88: addu        $a3, $a1, $zero
        ctx->r7 = ADD32(ctx->r5, 0);
            goto L_80016E8C;
    }
    goto skip_0;
    // 0x80016E88: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    skip_0:
L_80016E8C:
    // 0x80016E8C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80016E90: slt         $v0, $a2, $t0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80016E94: bne         $v0, $zero, L_80016E60
    if (ctx->r2 != 0) {
        // 0x80016E98: slti        $v0, $a3, 0x2
        ctx->r2 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
            goto L_80016E60;
    }
    // 0x80016E98: slti        $v0, $a3, 0x2
    ctx->r2 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x80016E9C: bne         $v0, $zero, L_80016EF0
    if (ctx->r2 != 0) {
        // 0x80016EA0: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_80016EF0;
    }
    // 0x80016EA0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80016EA4: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x80016EA8: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    // 0x80016EAC: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80016EB0: addiu       $t0, $a2, 0xA
    ctx->r8 = ADD32(ctx->r6, 0XA);
L_80016EB4:
    // 0x80016EB4: lbu         $v0, 0x70($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X70);
    // 0x80016EB8: bne         $v0, $zero, L_80016ED4
    if (ctx->r2 != 0) {
        // 0x80016EBC: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80016ED4;
    }
    // 0x80016EBC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80016EC0: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
L_80016EC4:
    // 0x80016EC4: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80016EC8: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x80016ECC: beq         $v0, $zero, L_80016EC4
    if (ctx->r2 == 0) {
        // 0x80016ED0: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80016EC4;
    }
    // 0x80016ED0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80016ED4:
    // 0x80016ED4: slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80016ED8: bnel        $v0, $zero, L_80016EE0
    if (ctx->r2 != 0) {
        // 0x80016EDC: addu        $a3, $a1, $zero
        ctx->r7 = ADD32(ctx->r5, 0);
            goto L_80016EE0;
    }
    goto skip_1;
    // 0x80016EDC: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    skip_1:
L_80016EE0:
    // 0x80016EE0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80016EE4: slt         $v0, $a2, $t0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80016EE8: bne         $v0, $zero, L_80016EB4
    if (ctx->r2 != 0) {
        // 0x80016EEC: slti        $v1, $a3, 0x6
        ctx->r3 = SIGNED(ctx->r7) < 0X6 ? 1 : 0;
            goto L_80016EB4;
    }
    // 0x80016EEC: slti        $v1, $a3, 0x6
    ctx->r3 = SIGNED(ctx->r7) < 0X6 ? 1 : 0;
L_80016EF0:
    // 0x80016EF0: lbu         $v0, 0x6A($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X6A);
    // 0x80016EF4: beq         $v0, $v1, L_80016F38
    if (ctx->r2 == ctx->r3) {
        // 0x80016EF8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80016F38;
    }
    // 0x80016EF8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80016EFC: bne         $v1, $v0, L_80016F10
    if (ctx->r3 != ctx->r2) {
        // 0x80016F00: sb          $v1, 0x6A($a0)
        MEM_B(0X6A, ctx->r4) = ctx->r3;
            goto L_80016F10;
    }
    // 0x80016F00: sb          $v1, 0x6A($a0)
    MEM_B(0X6A, ctx->r4) = ctx->r3;
    // 0x80016F04: lbu         $a1, 0x5($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X5);
    // 0x80016F08: j           L_80016F30
    // 0x80016F0C: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
        goto L_80016F30;
    // 0x80016F0C: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
L_80016F10:
    // 0x80016F10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80016F14: bne         $v1, $v0, L_80016F28
    if (ctx->r3 != ctx->r2) {
        // 0x80016F18: nop
    
            goto L_80016F28;
    }
    // 0x80016F18: nop

    // 0x80016F1C: lbu         $a1, 0x5($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X5);
    // 0x80016F20: j           L_80016F30
    // 0x80016F24: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
        goto L_80016F30;
    // 0x80016F24: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
L_80016F28:
    // 0x80016F28: lbu         $a1, 0x5($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X5);
    // 0x80016F2C: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
L_80016F30:
    // 0x80016F30: jal         0x8000637C
    // 0x80016F34: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    func_8000637C(rdram, ctx);
        goto after_0;
    // 0x80016F34: andi        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 & 0X1;
    after_0:
L_80016F38:
    // 0x80016F38: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80016F3C: jr          $ra
    // 0x80016F40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80016F40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80016F44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016F44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80016F48: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80016F4C: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x80016F50: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    // 0x80016F54: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80016F58: addiu       $t0, $a2, 0xA
    ctx->r8 = ADD32(ctx->r6, 0XA);
L_80016F5C:
    // 0x80016F5C: lbu         $v0, 0x70($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X70);
    // 0x80016F60: bne         $v0, $zero, L_80016F7C
    if (ctx->r2 != 0) {
        // 0x80016F64: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80016F7C;
    }
    // 0x80016F64: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80016F68: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
L_80016F6C:
    // 0x80016F6C: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80016F70: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x80016F74: beq         $v0, $zero, L_80016F6C
    if (ctx->r2 == 0) {
        // 0x80016F78: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80016F6C;
    }
    // 0x80016F78: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80016F7C:
    // 0x80016F7C: slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80016F80: bnel        $v0, $zero, L_80016F88
    if (ctx->r2 != 0) {
        // 0x80016F84: addu        $a3, $a1, $zero
        ctx->r7 = ADD32(ctx->r5, 0);
            goto L_80016F88;
    }
    goto skip_0;
    // 0x80016F84: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    skip_0:
L_80016F88:
    // 0x80016F88: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80016F8C: slt         $v0, $a2, $t0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80016F90: bne         $v0, $zero, L_80016F5C
    if (ctx->r2 != 0) {
        // 0x80016F94: slti        $v0, $a3, 0x6
        ctx->r2 = SIGNED(ctx->r7) < 0X6 ? 1 : 0;
            goto L_80016F5C;
    }
    // 0x80016F94: slti        $v0, $a3, 0x6
    ctx->r2 = SIGNED(ctx->r7) < 0X6 ? 1 : 0;
    // 0x80016F98: beq         $v0, $zero, L_80016FAC
    if (ctx->r2 == 0) {
        // 0x80016F9C: addiu       $a1, $zero, 0x7
        ctx->r5 = ADD32(0, 0X7);
            goto L_80016FAC;
    }
    // 0x80016F9C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80016FA0: lbu         $a0, 0x5($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X5);
    // 0x80016FA4: j           L_80016FB8
    // 0x80016FA8: xori        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 ^ 0X1;
        goto L_80016FB8;
    // 0x80016FA8: xori        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 ^ 0X1;
L_80016FAC:
    // 0x80016FAC: lbu         $a0, 0x5($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X5);
    // 0x80016FB0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80016FB4: xori        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 ^ 0X1;
L_80016FB8:
    // 0x80016FB8: jal         0x8001C0D0
    // 0x80016FBC: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    func_8001C0D0(rdram, ctx);
        goto after_0;
    // 0x80016FBC: andi        $a0, $a0, 0x1
    ctx->r4 = ctx->r4 & 0X1;
    after_0:
    // 0x80016FC0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80016FC4: jr          $ra
    // 0x80016FC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80016FC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80016FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016FCC: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x80016FD0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80016FD4: lbu         $v1, 0x2074($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2074);
    // 0x80016FD8: beq         $v1, $zero, L_8001705C
    if (ctx->r3 == 0) {
        // 0x80016FDC: andi        $a2, $v0, 0x1
        ctx->r6 = ctx->r2 & 0X1;
            goto L_8001705C;
    }
    // 0x80016FDC: andi        $a2, $v0, 0x1
    ctx->r6 = ctx->r2 & 0X1;
    // 0x80016FE0: lb          $v1, 0x5A($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X5A);
    // 0x80016FE4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80016FE8: beq         $v1, $v0, L_8001705C
    if (ctx->r3 == ctx->r2) {
        // 0x80016FEC: nop
    
            goto L_8001705C;
    }
    // 0x80016FEC: nop

    // 0x80016FF0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80016FF4: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80016FF8: lbu         $v0, 0x2088($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2088);
    // 0x80016FFC: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80017000: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80017004: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x80017008: sb          $v0, 0x2088($at)
    MEM_B(0X2088, ctx->r1) = ctx->r2;
    // 0x8001700C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80017010: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80017014: lbu         $v0, 0x2088($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2088);
    // 0x80017018: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8001701C: slti        $v0, $v0, 0x79
    ctx->r2 = SIGNED(ctx->r2) < 0X79 ? 1 : 0;
    // 0x80017020: bne         $v0, $zero, L_80017038
    if (ctx->r2 != 0) {
        // 0x80017024: addiu       $v0, $zero, 0xF8
        ctx->r2 = ADD32(0, 0XF8);
            goto L_80017038;
    }
    // 0x80017024: addiu       $v0, $zero, 0xF8
    ctx->r2 = ADD32(0, 0XF8);
    // 0x80017028: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001702C: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x80017030: j           L_8001705C
    // 0x80017034: sb          $v0, 0x2088($at)
    MEM_B(0X2088, ctx->r1) = ctx->r2;
        goto L_8001705C;
    // 0x80017034: sb          $v0, 0x2088($at)
    MEM_B(0X2088, ctx->r1) = ctx->r2;
L_80017038:
    // 0x80017038: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001703C: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x80017040: lbu         $v1, 0x2088($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2088);
    // 0x80017044: addiu       $v0, $zero, -0x80
    ctx->r2 = ADD32(0, -0X80);
    // 0x80017048: or          $v0, $a1, $v0
    ctx->r2 = ctx->r5 | ctx->r2;
    // 0x8001704C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80017050: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80017054: addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // 0x80017058: sb          $v1, 0x2088($at)
    MEM_B(0X2088, ctx->r1) = ctx->r3;
L_8001705C:
    // 0x8001705C: jr          $ra
    // 0x80017060: nop

    return;
    // 0x80017060: nop

;}
RECOMP_FUNC void func_80017064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017064: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80017068: lbu         $v1, 0x7B98($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B98);
    // 0x8001706C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80017070: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80017074: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80017078: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001707C: bne         $v1, $v0, L_80017098
    if (ctx->r3 != ctx->r2) {
        // 0x80017080: sw          $ra, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r31;
            goto L_80017098;
    }
    // 0x80017080: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80017084: lw          $v1, 0xD0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XD0);
    // 0x80017088: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001708C: lbu         $v0, 0x7B9E($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9E);
    // 0x80017090: j           L_80017608
    // 0x80017094: sb          $v0, 0x5C($v1)
    MEM_B(0X5C, ctx->r3) = ctx->r2;
        goto L_80017608;
    // 0x80017094: sb          $v0, 0x5C($v1)
    MEM_B(0X5C, ctx->r3) = ctx->r2;
L_80017098:
    // 0x80017098: lhu         $v0, 0x86($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X86);
    // 0x8001709C: sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // 0x800170A0: lhu         $v0, 0x88($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X88);
    // 0x800170A4: sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    // 0x800170A8: lhu         $v0, 0x8A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8A);
    // 0x800170AC: sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // 0x800170B0: lhu         $v0, 0x8C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8C);
    // 0x800170B4: sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    // 0x800170B8: lhu         $v0, 0x8E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8E);
    // 0x800170BC: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // 0x800170C0: lhu         $v0, 0x90($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X90);
    // 0x800170C4: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x800170C8: sh          $zero, 0x92($s0)
    MEM_H(0X92, ctx->r16) = 0;
    // 0x800170CC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800170D0: lbu         $v0, 0x7B85($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B85);
    // 0x800170D4: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x800170D8: beq         $v0, $zero, L_80017180
    if (ctx->r2 == 0) {
        // 0x800170DC: nop
    
            goto L_80017180;
    }
    // 0x800170DC: nop

    // 0x800170E0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800170E4: lbu         $v0, 0x7B82($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B82);
    // 0x800170E8: bne         $v0, $zero, L_8001714C
    if (ctx->r2 != 0) {
        // 0x800170EC: nop
    
            goto L_8001714C;
    }
    // 0x800170EC: nop

    // 0x800170F0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800170F4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x800170F8: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
L_800170FC:
    // 0x800170FC: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x80017100: blez        $v0, L_8001713C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80017104: addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
            goto L_8001713C;
    }
    // 0x80017104: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80017108: bne         $a1, $a3, L_80017130
    if (ctx->r5 != ctx->r7) {
        // 0x8001710C: nop
    
            goto L_80017130;
    }
    // 0x8001710C: nop

    // 0x80017110: lh          $v0, 0x1A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X1A);
    // 0x80017114: lhu         $a0, 0x92($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X92);
    // 0x80017118: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8001711C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80017120: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80017124: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x80017128: j           L_8001713C
    // 0x8001712C: sh          $a0, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r4;
        goto L_8001713C;
    // 0x8001712C: sh          $a0, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r4;
L_80017130:
    // 0x80017130: lhu         $v0, 0x92($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X92);
    // 0x80017134: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80017138: sh          $v0, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r2;
L_8001713C:
    // 0x8001713C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80017140: slti        $v0, $a1, 0x6
    ctx->r2 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    // 0x80017144: bne         $v0, $zero, L_800170FC
    if (ctx->r2 != 0) {
        // 0x80017148: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_800170FC;
    }
    // 0x80017148: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_8001714C:
    // 0x8001714C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80017150: lw          $v0, 0x7B80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7B80);
    // 0x80017154: lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // 0x80017158: ori         $v1, $v1, 0xFF00
    ctx->r3 = ctx->r3 | 0XFF00;
    // 0x8001715C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80017160: addiu       $v1, $zero, 0x100
    ctx->r3 = ADD32(0, 0X100);
    // 0x80017164: bne         $v0, $v1, L_800171C0
    if (ctx->r2 != ctx->r3) {
        // 0x80017168: nop
    
            goto L_800171C0;
    }
    // 0x80017168: nop

    // 0x8001716C: lw          $v1, 0xD0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XD0);
    // 0x80017170: lbu         $v0, 0x5C($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5C);
    // 0x80017174: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80017178: j           L_800171C0
    // 0x8001717C: sb          $v0, 0x5C($v1)
    MEM_B(0X5C, ctx->r3) = ctx->r2;
        goto L_800171C0;
    // 0x8001717C: sb          $v0, 0x5C($v1)
    MEM_B(0X5C, ctx->r3) = ctx->r2;
L_80017180:
    // 0x80017180: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80017184: lbu         $v0, 0x7B80($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B80);
    // 0x80017188: bne         $v0, $zero, L_8001719C
    if (ctx->r2 != 0) {
        // 0x8001718C: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8001719C;
    }
    // 0x8001718C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80017190: lhu         $v0, 0x90($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X90);
    // 0x80017194: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80017198: sh          $v0, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r2;
L_8001719C:
    // 0x8001719C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_800171A0:
    // 0x800171A0: lhu         $v0, 0x92($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X92);
    // 0x800171A4: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x800171A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800171AC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800171B0: sh          $v0, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r2;
    // 0x800171B4: slti        $v0, $a1, 0x6
    ctx->r2 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    // 0x800171B8: bne         $v0, $zero, L_800171A0
    if (ctx->r2 != 0) {
        // 0x800171BC: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_800171A0;
    }
    // 0x800171BC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_800171C0:
    // 0x800171C0: lw          $a1, 0xD0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XD0);
    // 0x800171C4: lb          $a0, 0x5C($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X5C);
    // 0x800171C8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800171CC: addiu       $v1, $v1, -0x3F9C
    ctx->r3 = ADD32(ctx->r3, -0X3F9C);
    // 0x800171D0: lh          $a2, 0x92($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X92);
    // 0x800171D4: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800171D8: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x800171DC: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800171E0: slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800171E4: bne         $v0, $zero, L_80017214
    if (ctx->r2 != 0) {
        // 0x800171E8: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_80017214;
    }
    // 0x800171E8: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800171EC: sb          $v0, 0x5C($a1)
    MEM_B(0X5C, ctx->r5) = ctx->r2;
    // 0x800171F0: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800171F4: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800171F8: slti        $v0, $v0, 0x9
    ctx->r2 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x800171FC: bnel        $v0, $zero, L_80017240
    if (ctx->r2 != 0) {
        // 0x80017200: sh          $zero, 0x92($s0)
        MEM_H(0X92, ctx->r16) = 0;
            goto L_80017240;
    }
    goto skip_0;
    // 0x80017200: sh          $zero, 0x92($s0)
    MEM_H(0X92, ctx->r16) = 0;
    skip_0:
    // 0x80017204: lw          $v1, 0xD0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XD0);
    // 0x80017208: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8001720C: j           L_8001723C
    // 0x80017210: sb          $v0, 0x5C($v1)
    MEM_B(0X5C, ctx->r3) = ctx->r2;
        goto L_8001723C;
    // 0x80017210: sb          $v0, 0x5C($v1)
    MEM_B(0X5C, ctx->r3) = ctx->r2;
L_80017214:
    // 0x80017214: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x80017218: slt         $v0, $v0, $a2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001721C: bne         $v0, $zero, L_80017258
    if (ctx->r2 != 0) {
        // 0x80017220: addiu       $v0, $a0, -0x1
        ctx->r2 = ADD32(ctx->r4, -0X1);
            goto L_80017258;
    }
    // 0x80017220: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x80017224: sb          $v0, 0x5C($a1)
    MEM_B(0X5C, ctx->r5) = ctx->r2;
    // 0x80017228: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8001722C: bgezl       $v0, L_80017240
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80017230: sh          $zero, 0x92($s0)
        MEM_H(0X92, ctx->r16) = 0;
            goto L_80017240;
    }
    goto skip_1;
    // 0x80017230: sh          $zero, 0x92($s0)
    MEM_H(0X92, ctx->r16) = 0;
    skip_1:
    // 0x80017234: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80017238: sb          $zero, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = 0;
L_8001723C:
    // 0x8001723C: sh          $zero, 0x92($s0)
    MEM_H(0X92, ctx->r16) = 0;
L_80017240:
    // 0x80017240: sh          $zero, 0x90($s0)
    MEM_H(0X90, ctx->r16) = 0;
    // 0x80017244: sh          $zero, 0x8E($s0)
    MEM_H(0X8E, ctx->r16) = 0;
    // 0x80017248: sh          $zero, 0x8C($s0)
    MEM_H(0X8C, ctx->r16) = 0;
    // 0x8001724C: sh          $zero, 0x8A($s0)
    MEM_H(0X8A, ctx->r16) = 0;
    // 0x80017250: sh          $zero, 0x88($s0)
    MEM_H(0X88, ctx->r16) = 0;
    // 0x80017254: sh          $zero, 0x86($s0)
    MEM_H(0X86, ctx->r16) = 0;
L_80017258:
    // 0x80017258: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8001725C: lbu         $a0, 0x7B82($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B82);
    // 0x80017260: lui         $a1, 0x8888
    ctx->r5 = S32(0X8888 << 16);
    // 0x80017264: ori         $a1, $a1, 0x8889
    ctx->r5 = ctx->r5 | 0X8889;
    // 0x80017268: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001726C: lbu         $v1, 0x7B81($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B81);
    // 0x80017270: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80017274: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80017278: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001727C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80017280: mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80017284: mfhi        $t1
    ctx->r9 = hi;
    // 0x80017288: addu        $v1, $t1, $v0
    ctx->r3 = ADD32(ctx->r9, ctx->r2);
    // 0x8001728C: sra         $v1, $v1, 5
    ctx->r3 = S32(SIGNED(ctx->r3) >> 5);
    // 0x80017290: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80017294: subu        $a2, $v1, $v0
    ctx->r6 = SUB32(ctx->r3, ctx->r2);
    // 0x80017298: slti        $v0, $a2, 0x5
    ctx->r2 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
    // 0x8001729C: beql        $v0, $zero, L_800172A4
    if (ctx->r2 == 0) {
        // 0x800172A0: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_800172A4;
    }
    goto skip_2;
    // 0x800172A0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    skip_2:
L_800172A4:
    // 0x800172A4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800172A8: lbu         $a0, 0x7B85($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B85);
    // 0x800172AC: sltiu       $v0, $a0, 0x3
    ctx->r2 = ctx->r4 < 0X3 ? 1 : 0;
    // 0x800172B0: beq         $v0, $zero, L_800172DC
    if (ctx->r2 == 0) {
        // 0x800172B4: addiu       $v0, $a0, -0x1
        ctx->r2 = ADD32(ctx->r4, -0X1);
            goto L_800172DC;
    }
    // 0x800172B4: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x800172B8: lw          $a1, 0xD0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XD0);
    // 0x800172BC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800172C0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800172C4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800172C8: lbu         $v0, -0x3F78($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X3F78);
    // 0x800172CC: lb          $v1, 0x5C($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X5C);
    // 0x800172D0: slt         $v1, $v0, $v1
    ctx->r3 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800172D4: bnel        $v1, $zero, L_800172DC
    if (ctx->r3 != 0) {
        // 0x800172D8: sb          $v0, 0x5C($a1)
        MEM_B(0X5C, ctx->r5) = ctx->r2;
            goto L_800172DC;
    }
    goto skip_3;
    // 0x800172D8: sb          $v0, 0x5C($a1)
    MEM_B(0X5C, ctx->r5) = ctx->r2;
    skip_3:
L_800172DC:
    // 0x800172DC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x800172E0: addiu       $a3, $a3, 0x7B85
    ctx->r7 = ADD32(ctx->r7, 0X7B85);
    // 0x800172E4: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800172E8: lw          $a1, 0xD0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XD0);
    // 0x800172EC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800172F0: addiu       $a0, $a0, -0x3F6D
    ctx->r4 = ADD32(ctx->r4, -0X3F6D);
    // 0x800172F4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800172F8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800172FC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80017300: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80017304: lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X0);
    // 0x80017308: lb          $v0, 0x5C($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X5C);
    // 0x8001730C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80017310: beq         $v0, $zero, L_8001731C
    if (ctx->r2 == 0) {
        // 0x80017314: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_8001731C;
    }
    // 0x80017314: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80017318: sb          $a0, 0x5C($a1)
    MEM_B(0X5C, ctx->r5) = ctx->r4;
L_8001731C:
    // 0x8001731C: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x80017320: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x80017324: beq         $v0, $zero, L_8001733C
    if (ctx->r2 == 0) {
        // 0x80017328: nop
    
            goto L_8001733C;
    }
    // 0x80017328: nop

    // 0x8001732C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80017330: lbu         $v0, 0x7B82($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B82);
    // 0x80017334: beq         $v0, $zero, L_800173C8
    if (ctx->r2 == 0) {
        // 0x80017338: nop
    
            goto L_800173C8;
    }
    // 0x80017338: nop

L_8001733C:
    // 0x8001733C: lhu         $v0, 0x94($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X94);
    // 0x80017340: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80017344: sh          $v0, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r2;
    // 0x80017348: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001734C: bgtz        $v0, L_800173C8
    if (SIGNED(ctx->r2) > 0) {
        // 0x80017350: nop
    
            goto L_800173C8;
    }
    // 0x80017350: nop

    // 0x80017354: lb          $v0, 0x5E($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5E);
    // 0x80017358: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001735C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80017360: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80017364: lbu         $a0, -0x3F43($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X3F43);
    // 0x80017368: lb          $v1, 0x5E($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X5E);
    // 0x8001736C: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x80017370: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80017374: lw          $a0, 0xD0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XD0);
    // 0x80017378: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8001737C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80017380: sh          $v0, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r2;
    // 0x80017384: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80017388: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001738C: lbu         $v0, -0x3F44($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3F44);
    // 0x80017390: sb          $v0, 0x5F($a0)
    MEM_B(0X5F, ctx->r4) = ctx->r2;
    // 0x80017394: lw          $v1, 0xD0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XD0);
    // 0x80017398: lbu         $v0, 0x5C($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5C);
    // 0x8001739C: lbu         $a0, 0x5F($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X5F);
    // 0x800173A0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800173A4: sb          $v0, 0x5C($v1)
    MEM_B(0X5C, ctx->r3) = ctx->r2;
    // 0x800173A8: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x800173AC: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x800173B0: lb          $v0, 0x5E($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X5E);
    // 0x800173B4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800173B8: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x800173BC: beq         $v0, $zero, L_800173C8
    if (ctx->r2 == 0) {
        // 0x800173C0: addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
            goto L_800173C8;
    }
    // 0x800173C0: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x800173C4: sb          $v0, 0x5E($s0)
    MEM_B(0X5E, ctx->r16) = ctx->r2;
L_800173C8:
    // 0x800173C8: lw          $a0, 0xD0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XD0);
    // 0x800173CC: lb          $v0, 0x61($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X61);
    // 0x800173D0: bne         $v0, $zero, L_80017438
    if (ctx->r2 != 0) {
        // 0x800173D4: nop
    
            goto L_80017438;
    }
    // 0x800173D4: nop

    // 0x800173D8: jal         0x800176CC
    // 0x800173DC: nop

    func_800176CC(rdram, ctx);
        goto after_0;
    // 0x800173DC: nop

    after_0:
    // 0x800173E0: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800173E4: bne         $v0, $zero, L_80017424
    if (ctx->r2 != 0) {
        // 0x800173E8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80017424;
    }
    // 0x800173E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800173EC: lw          $v1, 0xD0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XD0);
    // 0x800173F0: sb          $v0, 0x61($v1)
    MEM_B(0X61, ctx->r3) = ctx->r2;
    // 0x800173F4: lw          $v1, 0xD0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XD0);
    // 0x800173F8: lbu         $v0, 0x5C($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5C);
    // 0x800173FC: sb          $v0, 0x60($v1)
    MEM_B(0X60, ctx->r3) = ctx->r2;
    // 0x80017400: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80017404: lbu         $v0, 0x7B85($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B85);
    // 0x80017408: lw          $v1, 0xD0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XD0);
    // 0x8001740C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80017410: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80017414: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017418: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001741C: lbu         $v0, -0x3F78($at)
    ctx->r2 = MEM_BU(ctx->r1, -0X3F78);
    // 0x80017420: sb          $v0, 0x5C($v1)
    MEM_B(0X5C, ctx->r3) = ctx->r2;
L_80017424:
    // 0x80017424: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80017428: lb          $v0, 0x61($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X61);
    // 0x8001742C: beq         $v0, $zero, L_8001745C
    if (ctx->r2 == 0) {
        // 0x80017430: nop
    
            goto L_8001745C;
    }
    // 0x80017430: nop

    // 0x80017434: lw          $a0, 0xD0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XD0);
L_80017438:
    // 0x80017438: jal         0x800176CC
    // 0x8001743C: nop

    func_800176CC(rdram, ctx);
        goto after_1;
    // 0x8001743C: nop

    after_1:
    // 0x80017440: bne         $v0, $zero, L_8001745C
    if (ctx->r2 != 0) {
        // 0x80017444: nop
    
            goto L_8001745C;
    }
    // 0x80017444: nop

    // 0x80017448: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x8001744C: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80017450: lw          $v1, 0xD0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XD0);
    // 0x80017454: lbu         $v0, 0x60($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X60);
    // 0x80017458: sb          $v0, 0x5C($v1)
    MEM_B(0X5C, ctx->r3) = ctx->r2;
L_8001745C:
    // 0x8001745C: lw          $v1, 0xD0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XD0);
    // 0x80017460: lb          $v0, 0x5C($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X5C);
    // 0x80017464: slti        $v0, $v0, 0x9
    ctx->r2 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x80017468: bne         $v0, $zero, L_80017478
    if (ctx->r2 != 0) {
        // 0x8001746C: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_80017478;
    }
    // 0x8001746C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80017470: sb          $v0, 0x5C($v1)
    MEM_B(0X5C, ctx->r3) = ctx->r2;
    // 0x80017474: lw          $v1, 0xD0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XD0);
L_80017478:
    // 0x80017478: lb          $v0, 0x5C($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X5C);
    // 0x8001747C: bltzl       $v0, L_80017484
    if (SIGNED(ctx->r2) < 0) {
        // 0x80017480: sb          $zero, 0x5C($v1)
        MEM_B(0X5C, ctx->r3) = 0;
            goto L_80017484;
    }
    goto skip_4;
    // 0x80017480: sb          $zero, 0x5C($v1)
    MEM_B(0X5C, ctx->r3) = 0;
    skip_4:
L_80017484:
    // 0x80017484: lw          $a1, 0xD0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XD0);
    // 0x80017488: lbu         $v0, 0x74($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X74);
    // 0x8001748C: lb          $a2, 0x4F($a1)
    ctx->r6 = MEM_B(ctx->r5, 0X4F);
    // 0x80017490: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80017494: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x80017498: lb          $t0, -0x3AC8($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X3AC8);
    // 0x8001749C: mult        $a2, $t0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800174A0: mflo        $a2
    ctx->r6 = lo;
    // 0x800174A4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800174A8: lbu         $a0, 0x7B82($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7B82);
    // 0x800174AC: lui         $a3, 0x8888
    ctx->r7 = S32(0X8888 << 16);
    // 0x800174B0: ori         $a3, $a3, 0x8889
    ctx->r7 = ctx->r7 | 0X8889;
    // 0x800174B4: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x800174B8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800174BC: lbu         $v0, 0x7B81($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B81);
    // 0x800174C0: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x800174C4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800174C8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800174CC: mult        $v1, $a3
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800174D0: lb          $a0, 0x5C($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X5C);
    // 0x800174D4: lhu         $v0, 0x7C($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X7C);
    // 0x800174D8: mfhi        $a3
    ctx->r7 = hi;
    // 0x800174DC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800174E0: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
    // 0x800174E4: lb          $a1, -0x3E0C($a1)
    ctx->r5 = MEM_B(ctx->r5, -0X3E0C);
    // 0x800174E8: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x800174EC: div         $zero, $v0, $t0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r8)));
    // 0x800174F0: bne         $t0, $zero, L_800174FC
    if (ctx->r8 != 0) {
        // 0x800174F4: nop
    
            goto L_800174FC;
    }
    // 0x800174F4: nop

    // 0x800174F8: break       7
    do_break(2147579128);
L_800174FC:
    // 0x800174FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80017500: bne         $t0, $at, L_80017514
    if (ctx->r8 != ctx->r1) {
        // 0x80017504: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80017514;
    }
    // 0x80017504: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80017508: bne         $v0, $at, L_80017514
    if (ctx->r2 != ctx->r1) {
        // 0x8001750C: nop
    
            goto L_80017514;
    }
    // 0x8001750C: nop

    // 0x80017510: break       6
    do_break(2147579152);
L_80017514:
    // 0x80017514: mflo        $t0
    ctx->r8 = lo;
    // 0x80017518: addu        $v0, $a3, $v1
    ctx->r2 = ADD32(ctx->r7, ctx->r3);
    // 0x8001751C: sra         $v0, $v0, 5
    ctx->r2 = S32(SIGNED(ctx->r2) >> 5);
    // 0x80017520: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x80017524: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80017528: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8001752C: bne         $v0, $zero, L_80017548
    if (ctx->r2 != 0) {
        // 0x80017530: slti        $v0, $t0, 0xA
        ctx->r2 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
            goto L_80017548;
    }
    // 0x80017530: slti        $v0, $t0, 0xA
    ctx->r2 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x80017534: slti        $v0, $t0, 0x12
    ctx->r2 = SIGNED(ctx->r8) < 0X12 ? 1 : 0;
    // 0x80017538: beql        $v0, $zero, L_80017550
    if (ctx->r2 == 0) {
        // 0x8001753C: addiu       $t0, $zero, 0x11
        ctx->r8 = ADD32(0, 0X11);
            goto L_80017550;
    }
    goto skip_5;
    // 0x8001753C: addiu       $t0, $zero, 0x11
    ctx->r8 = ADD32(0, 0X11);
    skip_5:
    // 0x80017540: j           L_80017554
    // 0x80017544: nor         $v0, $zero, $t0
    ctx->r2 = ~(0 | ctx->r8);
        goto L_80017554;
    // 0x80017544: nor         $v0, $zero, $t0
    ctx->r2 = ~(0 | ctx->r8);
L_80017548:
    // 0x80017548: beql        $v0, $zero, L_80017550
    if (ctx->r2 == 0) {
        // 0x8001754C: addiu       $t0, $zero, 0x9
        ctx->r8 = ADD32(0, 0X9);
            goto L_80017550;
    }
    goto skip_6;
    // 0x8001754C: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    skip_6:
L_80017550:
    // 0x80017550: nor         $v0, $zero, $t0
    ctx->r2 = ~(0 | ctx->r8);
L_80017554:
    // 0x80017554: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80017558: and         $t0, $t0, $v0
    ctx->r8 = ctx->r8 & ctx->r2;
    // 0x8001755C: lw          $a2, 0xD0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XD0);
    // 0x80017560: lbu         $v1, 0x74($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X74);
    // 0x80017564: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80017568: addiu       $a0, $a0, -0x3ABC
    ctx->r4 = ADD32(ctx->r4, -0X3ABC);
    // 0x8001756C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80017570: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80017574: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80017578: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001757C: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80017580: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x80017584: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80017588: bne         $v0, $zero, L_800175B8
    if (ctx->r2 != 0) {
        // 0x8001758C: nop
    
            goto L_800175B8;
    }
    // 0x8001758C: nop

    // 0x80017590: lbu         $v0, 0x5C($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X5C);
    // 0x80017594: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80017598: sb          $v0, 0x5C($a2)
    MEM_B(0X5C, ctx->r6) = ctx->r2;
    // 0x8001759C: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800175A0: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800175A4: slti        $v0, $v0, 0x9
    ctx->r2 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x800175A8: bne         $v0, $zero, L_800175B8
    if (ctx->r2 != 0) {
        // 0x800175AC: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_800175B8;
    }
    // 0x800175AC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800175B0: lw          $v1, 0xD0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XD0);
    // 0x800175B4: sb          $v0, 0x5C($v1)
    MEM_B(0X5C, ctx->r3) = ctx->r2;
L_800175B8:
    // 0x800175B8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800175BC: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x800175C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800175C4: bne         $v1, $v0, L_800175E4
    if (ctx->r3 != ctx->r2) {
        // 0x800175C8: nop
    
            goto L_800175E4;
    }
    // 0x800175C8: nop

    // 0x800175CC: lw          $a0, 0xD0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XD0);
    // 0x800175D0: lb          $v0, 0x5C($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X5C);
    // 0x800175D4: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800175D8: bne         $v0, $zero, L_800175E4
    if (ctx->r2 != 0) {
        // 0x800175DC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800175E4;
    }
    // 0x800175DC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800175E0: sb          $v0, 0x5C($a0)
    MEM_B(0X5C, ctx->r4) = ctx->r2;
L_800175E4:
    // 0x800175E4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800175E8: lbu         $v0, 0x2074($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2074);
    // 0x800175EC: bne         $v0, $zero, L_80017608
    if (ctx->r2 != 0) {
        // 0x800175F0: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_80017608;
    }
    // 0x800175F0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800175F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800175F8: sb          $v0, 0x25FC($at)
    MEM_B(0X25FC, ctx->r1) = ctx->r2;
    // 0x800175FC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80017600: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80017604: sb          $v0, 0x7A4C($at)
    MEM_B(0X7A4C, ctx->r1) = ctx->r2;
L_80017608:
    // 0x80017608: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8001760C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80017610: jr          $ra
    // 0x80017614: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80017614: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80017618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017618: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8001761C: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x80017620: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x80017624: lw          $a3, 0xB0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0XB0);
L_80017628:
    // 0x80017628: lbu         $v0, 0x70($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X70);
    // 0x8001762C: bne         $v0, $zero, L_80017648
    if (ctx->r2 != 0) {
        // 0x80017630: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80017648;
    }
    // 0x80017630: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80017634: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
L_80017638:
    // 0x80017638: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x8001763C: lbu         $v0, 0x70($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X70);
    // 0x80017640: beq         $v0, $zero, L_80017638
    if (ctx->r2 == 0) {
        // 0x80017644: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80017638;
    }
    // 0x80017644: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80017648:
    // 0x80017648: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001764C: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x80017650: beql        $v0, $zero, L_8001769C
    if (ctx->r2 == 0) {
        // 0x80017654: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8001769C;
    }
    goto skip_0;
    // 0x80017654: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_0:
    // 0x80017658: lw          $v1, 0xB0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XB0);
    // 0x8001765C: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x80017660: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80017664: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80017668: addu        $v1, $t0, $v1
    ctx->r3 = ADD32(ctx->r8, ctx->r3);
    // 0x8001766C: addu        $a2, $v0, $v1
    ctx->r6 = ADD32(ctx->r2, ctx->r3);
L_80017670:
    // 0x80017670: lbu         $v1, 0x70($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X70);
    // 0x80017674: bnel        $v1, $zero, L_80017688
    if (ctx->r3 != 0) {
        // 0x80017678: addu        $t2, $v1, $zero
        ctx->r10 = ADD32(ctx->r3, 0);
            goto L_80017688;
    }
    goto skip_1;
    // 0x80017678: addu        $t2, $v1, $zero
    ctx->r10 = ADD32(ctx->r3, 0);
    skip_1:
    // 0x8001767C: sltu        $v0, $zero, $t2
    ctx->r2 = 0 < ctx->r10 ? 1 : 0;
    // 0x80017680: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80017684: addu        $t2, $v1, $zero
    ctx->r10 = ADD32(ctx->r3, 0);
L_80017688:
    // 0x80017688: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001768C: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x80017690: bne         $v0, $zero, L_80017670
    if (ctx->r2 != 0) {
        // 0x80017694: addiu       $a2, $a2, 0x12
        ctx->r6 = ADD32(ctx->r6, 0X12);
            goto L_80017670;
    }
    // 0x80017694: addiu       $a2, $a2, 0x12
    ctx->r6 = ADD32(ctx->r6, 0X12);
    // 0x80017698: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_8001769C:
    // 0x8001769C: slti        $v0, $t0, 0xA
    ctx->r2 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x800176A0: bne         $v0, $zero, L_80017628
    if (ctx->r2 != 0) {
        // 0x800176A4: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80017628;
    }
    // 0x800176A4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800176A8: beq         $t1, $zero, L_800176BC
    if (ctx->r9 == 0) {
        // 0x800176AC: sll         $v1, $t1, 1
        ctx->r3 = S32(ctx->r9 << 1);
            goto L_800176BC;
    }
    // 0x800176AC: sll         $v1, $t1, 1
    ctx->r3 = S32(ctx->r9 << 1);
    // 0x800176B0: lhu         $v0, 0x8E($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X8E);
    // 0x800176B4: j           L_800176C4
    // 0x800176B8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
        goto L_800176C4;
    // 0x800176B8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_800176BC:
    // 0x800176BC: lhu         $v0, 0x8E($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X8E);
    // 0x800176C0: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
L_800176C4:
    // 0x800176C4: jr          $ra
    // 0x800176C8: sh          $v0, 0x8E($a0)
    MEM_H(0X8E, ctx->r4) = ctx->r2;
    return;
    // 0x800176C8: sh          $v0, 0x8E($a0)
    MEM_H(0X8E, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_800176CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800176CC: lb          $v1, 0xCC($a0)
    ctx->r3 = MEM_B(ctx->r4, 0XCC);
    // 0x800176D0: lb          $v0, 0xCD($a0)
    ctx->r2 = MEM_B(ctx->r4, 0XCD);
    // 0x800176D4: beq         $v1, $v0, L_80017704
    if (ctx->r3 == ctx->r2) {
        // 0x800176D8: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80017704;
    }
    // 0x800176D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800176DC: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
L_800176E0:
    // 0x800176E0: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x800176E4: lbu         $v0, 0xBC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XBC);
    // 0x800176E8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800176EC: andi        $v1, $v1, 0xF
    ctx->r3 = ctx->r3 & 0XF;
    // 0x800176F0: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800176F4: slti        $v0, $v0, 0x23
    ctx->r2 = SIGNED(ctx->r2) < 0X23 ? 1 : 0;
    // 0x800176F8: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800176FC: bne         $v1, $a2, L_800176E0
    if (ctx->r3 != ctx->r6) {
        // 0x80017700: addu        $a1, $a1, $v0
        ctx->r5 = ADD32(ctx->r5, ctx->r2);
            goto L_800176E0;
    }
    // 0x80017700: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
L_80017704:
    // 0x80017704: jr          $ra
    // 0x80017708: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    return;
    // 0x80017708: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
;}
RECOMP_FUNC void func_8001770C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001770C: sltu        $a1, $zero, $a1
    ctx->r5 = 0 < ctx->r5 ? 1 : 0;
    // 0x80017710: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x80017714: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80017718: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8001771C:
    // 0x8001771C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80017720:
    // 0x80017720: lw          $v0, 0xB0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB0);
    // 0x80017724: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80017728: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001772C: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x80017730: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x80017734: slti        $v0, $v1, 0xE
    ctx->r2 = SIGNED(ctx->r3) < 0XE ? 1 : 0;
    // 0x80017738: bne         $v0, $zero, L_80017720
    if (ctx->r2 != 0) {
        // 0x8001773C: nop
    
            goto L_80017720;
    }
    // 0x8001773C: nop

    // 0x80017740: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80017744: slti        $v0, $a3, 0x18
    ctx->r2 = SIGNED(ctx->r7) < 0X18 ? 1 : 0;
    // 0x80017748: bne         $v0, $zero, L_8001771C
    if (ctx->r2 != 0) {
        // 0x8001774C: addiu       $a2, $a2, 0x12
        ctx->r6 = ADD32(ctx->r6, 0X12);
            goto L_8001771C;
    }
    // 0x8001774C: addiu       $a2, $a2, 0x12
    ctx->r6 = ADD32(ctx->r6, 0X12);
    // 0x80017750: jr          $ra
    // 0x80017754: nop

    return;
    // 0x80017754: nop

;}
RECOMP_FUNC void func_80017760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80017764: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80017768: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8001776C: lbu         $a0, 0x2A($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X2A);
    // 0x80017770: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80017774: addiu       $v1, $zero, 0x500
    ctx->r3 = ADD32(0, 0X500);
    // 0x80017778: sb          $v0, 0x2E($a1)
    MEM_B(0X2E, ctx->r5) = ctx->r2;
    // 0x8001777C: addiu       $v0, $zero, 0x3C0
    ctx->r2 = ADD32(0, 0X3C0);
    // 0x80017780: sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // 0x80017784: sh          $v0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r2;
    // 0x80017788: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8001778C: addiu       $v0, $v0, 0x3040
    ctx->r2 = ADD32(ctx->r2, 0X3040);
    // 0x80017790: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80017794: ori         $v0, $zero, 0xFFF4
    ctx->r2 = 0 | 0XFFF4;
    // 0x80017798: sh          $v0, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r2;
    // 0x8001779C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800177A0: sh          $zero, 0x8($a1)
    MEM_H(0X8, ctx->r5) = 0;
    // 0x800177A4: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x800177A8: sh          $v1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r3;
    // 0x800177AC: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
    // 0x800177B0: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x800177B4: sh          $v1, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r3;
    // 0x800177B8: sb          $zero, 0x16($a1)
    MEM_B(0X16, ctx->r5) = 0;
    // 0x800177BC: sb          $v0, 0x17($a1)
    MEM_B(0X17, ctx->r5) = ctx->r2;
    // 0x800177C0: sh          $zero, 0x18($a1)
    MEM_H(0X18, ctx->r5) = 0;
    // 0x800177C4: beq         $a0, $zero, L_800177E0
    if (ctx->r4 == 0) {
        // 0x800177C8: sh          $zero, 0x1A($a1)
        MEM_H(0X1A, ctx->r5) = 0;
            goto L_800177E0;
    }
    // 0x800177C8: sh          $zero, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = 0;
    // 0x800177CC: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x800177D0: sh          $v0, 0x1E($a1)
    MEM_H(0X1E, ctx->r5) = ctx->r2;
    // 0x800177D4: sh          $v0, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r2;
    // 0x800177D8: j           L_800177E8
    // 0x800177DC: sw          $zero, 0x20($a1)
    MEM_W(0X20, ctx->r5) = 0;
        goto L_800177E8;
    // 0x800177DC: sw          $zero, 0x20($a1)
    MEM_W(0X20, ctx->r5) = 0;
L_800177E0:
    // 0x800177E0: jal         0x80066D30
    // 0x800177E4: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    func_80066D30(rdram, ctx);
        goto after_0;
    // 0x800177E4: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    after_0:
L_800177E8:
    // 0x800177E8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800177EC: jr          $ra
    // 0x800177F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800177F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800177F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800177F4: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x800177F8: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800177FC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80017800: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80017804: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80017808: addiu       $v1, $v1, 0x18B0
    ctx->r3 = ADD32(ctx->r3, 0X18B0);
    // 0x8001780C: addu        $a2, $v0, $v1
    ctx->r6 = ADD32(ctx->r2, ctx->r3);
    // 0x80017810: or          $v1, $a2, $a3
    ctx->r3 = ctx->r6 | ctx->r7;
    // 0x80017814: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x80017818: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001781C: sb          $v0, 0x2E($a3)
    MEM_B(0X2E, ctx->r7) = ctx->r2;
    // 0x80017820: sb          $v0, 0x2A($a3)
    MEM_B(0X2A, ctx->r7) = ctx->r2;
    // 0x80017824: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80017828: addiu       $v0, $v0, -0x2338
    ctx->r2 = ADD32(ctx->r2, -0X2338);
    // 0x8001782C: beq         $v1, $zero, L_8001788C
    if (ctx->r3 == 0) {
        // 0x80017830: sw          $v0, 0x30($a3)
        MEM_W(0X30, ctx->r7) = ctx->r2;
            goto L_8001788C;
    }
    // 0x80017830: sw          $v0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r2;
    // 0x80017834: addiu       $t0, $a2, 0x20
    ctx->r8 = ADD32(ctx->r6, 0X20);
L_80017838:
    // 0x80017838: lwl         $v0, 0x0($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r6, 0X0);
    // 0x8001783C: lwr         $v0, 0x3($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r6, 0X3);
    // 0x80017840: lwl         $v1, 0x4($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r6, 0X4);
    // 0x80017844: lwr         $v1, 0x7($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r6, 0X7);
    // 0x80017848: lwl         $a0, 0x8($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r6, 0X8);
    // 0x8001784C: lwr         $a0, 0xB($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r6, 0XB);
    // 0x80017850: lwl         $a1, 0xC($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, ctx->r6, 0XC);
    // 0x80017854: lwr         $a1, 0xF($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, ctx->r6, 0XF);
    // 0x80017858: swl         $v0, 0x0($a3)
    do_swl(rdram, 0X0, ctx->r7, ctx->r2);
    // 0x8001785C: swr         $v0, 0x3($a3)
    do_swr(rdram, 0X3, ctx->r7, ctx->r2);
    // 0x80017860: swl         $v1, 0x4($a3)
    do_swl(rdram, 0X4, ctx->r7, ctx->r3);
    // 0x80017864: swr         $v1, 0x7($a3)
    do_swr(rdram, 0X7, ctx->r7, ctx->r3);
    // 0x80017868: swl         $a0, 0x8($a3)
    do_swl(rdram, 0X8, ctx->r7, ctx->r4);
    // 0x8001786C: swr         $a0, 0xB($a3)
    do_swr(rdram, 0XB, ctx->r7, ctx->r4);
    // 0x80017870: swl         $a1, 0xC($a3)
    do_swl(rdram, 0XC, ctx->r7, ctx->r5);
    // 0x80017874: swr         $a1, 0xF($a3)
    do_swr(rdram, 0XF, ctx->r7, ctx->r5);
    // 0x80017878: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001787C: bne         $a2, $t0, L_80017838
    if (ctx->r6 != ctx->r8) {
        // 0x80017880: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_80017838;
    }
    // 0x80017880: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80017884: j           L_800178BC
    // 0x80017888: nop

        goto L_800178BC;
    // 0x80017888: nop

L_8001788C:
    // 0x8001788C: addiu       $t0, $a2, 0x20
    ctx->r8 = ADD32(ctx->r6, 0X20);
L_80017890:
    // 0x80017890: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80017894: lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X4);
    // 0x80017898: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x8001789C: lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XC);
    // 0x800178A0: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x800178A4: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x800178A8: sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // 0x800178AC: sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // 0x800178B0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800178B4: bne         $a2, $t0, L_80017890
    if (ctx->r6 != ctx->r8) {
        // 0x800178B8: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_80017890;
    }
    // 0x800178B8: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_800178BC:
    // 0x800178BC: lwl         $v0, 0x0($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r6, 0X0);
    // 0x800178C0: lwr         $v0, 0x3($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r6, 0X3);
    // 0x800178C4: lwl         $v1, 0x4($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r6, 0X4);
    // 0x800178C8: lwr         $v1, 0x7($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, ctx->r6, 0X7);
    // 0x800178CC: swl         $v0, 0x0($a3)
    do_swl(rdram, 0X0, ctx->r7, ctx->r2);
    // 0x800178D0: swr         $v0, 0x3($a3)
    do_swr(rdram, 0X3, ctx->r7, ctx->r2);
    // 0x800178D4: swl         $v1, 0x4($a3)
    do_swl(rdram, 0X4, ctx->r7, ctx->r3);
    // 0x800178D8: jr          $ra
    // 0x800178DC: swr         $v1, 0x7($a3)
    do_swr(rdram, 0X7, ctx->r7, ctx->r3);
    return;
    // 0x800178DC: swr         $v1, 0x7($a3)
    do_swr(rdram, 0X7, ctx->r7, ctx->r3);
;}
RECOMP_FUNC void func_800178E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800178E0: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x800178E4: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x800178E8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800178EC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800178F0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800178F4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800178F8: lwl         $a0, 0x1C70($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r1, 0X1C70);
    // 0x800178FC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017900: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017904: lwr         $a0, 0x1C73($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r1, 0X1C73);
    // 0x80017908: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001790C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017910: lwl         $t0, 0x1C74($at)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r1, 0X1C74);
    // 0x80017914: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017918: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001791C: lwr         $t0, 0x1C77($at)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r1, 0X1C77);
    // 0x80017920: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017924: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017928: lwl         $t1, 0x1C78($at)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r1, 0X1C78);
    // 0x8001792C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017930: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017934: lwr         $t1, 0x1C7B($at)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r1, 0X1C7B);
    // 0x80017938: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001793C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017940: lwl         $t2, 0x1C7C($at)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r1, 0X1C7C);
    // 0x80017944: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017948: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001794C: lwr         $t2, 0x1C7F($at)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r1, 0X1C7F);
    // 0x80017950: swl         $a0, 0x0($a1)
    do_swl(rdram, 0X0, ctx->r5, ctx->r4);
    // 0x80017954: swr         $a0, 0x3($a1)
    do_swr(rdram, 0X3, ctx->r5, ctx->r4);
    // 0x80017958: swl         $t0, 0x4($a1)
    do_swl(rdram, 0X4, ctx->r5, ctx->r8);
    // 0x8001795C: swr         $t0, 0x7($a1)
    do_swr(rdram, 0X7, ctx->r5, ctx->r8);
    // 0x80017960: swl         $t1, 0x8($a1)
    do_swl(rdram, 0X8, ctx->r5, ctx->r9);
    // 0x80017964: swr         $t1, 0xB($a1)
    do_swr(rdram, 0XB, ctx->r5, ctx->r9);
    // 0x80017968: swl         $t2, 0xC($a1)
    do_swl(rdram, 0XC, ctx->r5, ctx->r10);
    // 0x8001796C: swr         $t2, 0xF($a1)
    do_swr(rdram, 0XF, ctx->r5, ctx->r10);
    // 0x80017970: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017974: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017978: lwl         $a0, 0x1C80($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r1, 0X1C80);
    // 0x8001797C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017980: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017984: lwr         $a0, 0x1C83($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r1, 0X1C83);
    // 0x80017988: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001798C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017990: lwl         $t0, 0x1C84($at)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r1, 0X1C84);
    // 0x80017994: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017998: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001799C: lwr         $t0, 0x1C87($at)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r1, 0X1C87);
    // 0x800179A0: swl         $a0, 0x10($a1)
    do_swl(rdram, 0X10, ctx->r5, ctx->r4);
    // 0x800179A4: swr         $a0, 0x13($a1)
    do_swr(rdram, 0X13, ctx->r5, ctx->r4);
    // 0x800179A8: swl         $t0, 0x14($a1)
    do_swl(rdram, 0X14, ctx->r5, ctx->r8);
    // 0x800179AC: swr         $t0, 0x17($a1)
    do_swr(rdram, 0X17, ctx->r5, ctx->r8);
    // 0x800179B0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800179B4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800179B8: lwl         $a0, 0x1E08($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r1, 0X1E08);
    // 0x800179BC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800179C0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800179C4: lwr         $a0, 0x1E0B($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r1, 0X1E0B);
    // 0x800179C8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800179CC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800179D0: lwl         $a1, 0x1E0C($at)
    ctx->r5 = do_lwl(rdram, ctx->r5, ctx->r1, 0X1E0C);
    // 0x800179D4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800179D8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800179DC: lwr         $a1, 0x1E0F($at)
    ctx->r5 = do_lwr(rdram, ctx->r5, ctx->r1, 0X1E0F);
    // 0x800179E0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800179E4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800179E8: lwl         $t0, 0x1E10($at)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r1, 0X1E10);
    // 0x800179EC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800179F0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800179F4: lwr         $t0, 0x1E13($at)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r1, 0X1E13);
    // 0x800179F8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800179FC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017A00: lwl         $t1, 0x1E14($at)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r1, 0X1E14);
    // 0x80017A04: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017A08: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017A0C: lwr         $t1, 0x1E17($at)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r1, 0X1E17);
    // 0x80017A10: swl         $a0, 0x0($a2)
    do_swl(rdram, 0X0, ctx->r6, ctx->r4);
    // 0x80017A14: swr         $a0, 0x3($a2)
    do_swr(rdram, 0X3, ctx->r6, ctx->r4);
    // 0x80017A18: swl         $a1, 0x4($a2)
    do_swl(rdram, 0X4, ctx->r6, ctx->r5);
    // 0x80017A1C: swr         $a1, 0x7($a2)
    do_swr(rdram, 0X7, ctx->r6, ctx->r5);
    // 0x80017A20: swl         $t0, 0x8($a2)
    do_swl(rdram, 0X8, ctx->r6, ctx->r8);
    // 0x80017A24: swr         $t0, 0xB($a2)
    do_swr(rdram, 0XB, ctx->r6, ctx->r8);
    // 0x80017A28: swl         $t1, 0xC($a2)
    do_swl(rdram, 0XC, ctx->r6, ctx->r9);
    // 0x80017A2C: swr         $t1, 0xF($a2)
    do_swr(rdram, 0XF, ctx->r6, ctx->r9);
    // 0x80017A30: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017A34: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017A38: lwl         $a0, 0x1E18($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r1, 0X1E18);
    // 0x80017A3C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017A40: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017A44: lwr         $a0, 0x1E1B($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r1, 0X1E1B);
    // 0x80017A48: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017A4C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017A50: lwl         $a1, 0x1E1C($at)
    ctx->r5 = do_lwl(rdram, ctx->r5, ctx->r1, 0X1E1C);
    // 0x80017A54: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017A58: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017A5C: lwr         $a1, 0x1E1F($at)
    ctx->r5 = do_lwr(rdram, ctx->r5, ctx->r1, 0X1E1F);
    // 0x80017A60: swl         $a0, 0x10($a2)
    do_swl(rdram, 0X10, ctx->r6, ctx->r4);
    // 0x80017A64: swr         $a0, 0x13($a2)
    do_swr(rdram, 0X13, ctx->r6, ctx->r4);
    // 0x80017A68: swl         $a1, 0x14($a2)
    do_swl(rdram, 0X14, ctx->r6, ctx->r5);
    // 0x80017A6C: swr         $a1, 0x17($a2)
    do_swr(rdram, 0X17, ctx->r6, ctx->r5);
    // 0x80017A70: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017A74: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017A78: lwl         $a0, 0x1FB8($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r1, 0X1FB8);
    // 0x80017A7C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017A80: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017A84: lwr         $a0, 0x1FBB($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r1, 0X1FBB);
    // 0x80017A88: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017A8C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017A90: lwl         $a1, 0x1FBC($at)
    ctx->r5 = do_lwl(rdram, ctx->r5, ctx->r1, 0X1FBC);
    // 0x80017A94: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017A98: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017A9C: lwr         $a1, 0x1FBF($at)
    ctx->r5 = do_lwr(rdram, ctx->r5, ctx->r1, 0X1FBF);
    // 0x80017AA0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017AA4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017AA8: lwl         $a2, 0x1FC0($at)
    ctx->r6 = do_lwl(rdram, ctx->r6, ctx->r1, 0X1FC0);
    // 0x80017AAC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017AB0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017AB4: lwr         $a2, 0x1FC3($at)
    ctx->r6 = do_lwr(rdram, ctx->r6, ctx->r1, 0X1FC3);
    // 0x80017AB8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017ABC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017AC0: lwl         $t0, 0x1FC4($at)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r1, 0X1FC4);
    // 0x80017AC4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017AC8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017ACC: lwr         $t0, 0x1FC7($at)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r1, 0X1FC7);
    // 0x80017AD0: swl         $a0, 0x0($a3)
    do_swl(rdram, 0X0, ctx->r7, ctx->r4);
    // 0x80017AD4: swr         $a0, 0x3($a3)
    do_swr(rdram, 0X3, ctx->r7, ctx->r4);
    // 0x80017AD8: swl         $a1, 0x4($a3)
    do_swl(rdram, 0X4, ctx->r7, ctx->r5);
    // 0x80017ADC: swr         $a1, 0x7($a3)
    do_swr(rdram, 0X7, ctx->r7, ctx->r5);
    // 0x80017AE0: swl         $a2, 0x8($a3)
    do_swl(rdram, 0X8, ctx->r7, ctx->r6);
    // 0x80017AE4: swr         $a2, 0xB($a3)
    do_swr(rdram, 0XB, ctx->r7, ctx->r6);
    // 0x80017AE8: swl         $t0, 0xC($a3)
    do_swl(rdram, 0XC, ctx->r7, ctx->r8);
    // 0x80017AEC: swr         $t0, 0xF($a3)
    do_swr(rdram, 0XF, ctx->r7, ctx->r8);
    // 0x80017AF0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017AF4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017AF8: lwl         $a0, 0x1FC8($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r1, 0X1FC8);
    // 0x80017AFC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017B00: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017B04: lwr         $a0, 0x1FCB($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r1, 0X1FCB);
    // 0x80017B08: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017B0C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017B10: lwl         $a1, 0x1FCC($at)
    ctx->r5 = do_lwl(rdram, ctx->r5, ctx->r1, 0X1FCC);
    // 0x80017B14: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017B18: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017B1C: lwr         $a1, 0x1FCF($at)
    ctx->r5 = do_lwr(rdram, ctx->r5, ctx->r1, 0X1FCF);
    // 0x80017B20: swl         $a0, 0x10($a3)
    do_swl(rdram, 0X10, ctx->r7, ctx->r4);
    // 0x80017B24: swr         $a0, 0x13($a3)
    do_swr(rdram, 0X13, ctx->r7, ctx->r4);
    // 0x80017B28: swl         $a1, 0x14($a3)
    do_swl(rdram, 0X14, ctx->r7, ctx->r5);
    // 0x80017B2C: swr         $a1, 0x17($a3)
    do_swr(rdram, 0X17, ctx->r7, ctx->r5);
    // 0x80017B30: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017B34: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017B38: lwl         $a0, 0x2150($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r1, 0X2150);
    // 0x80017B3C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017B40: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017B44: lwr         $a0, 0x2153($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r1, 0X2153);
    // 0x80017B48: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017B4C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017B50: lwl         $a1, 0x2154($at)
    ctx->r5 = do_lwl(rdram, ctx->r5, ctx->r1, 0X2154);
    // 0x80017B54: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017B58: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017B5C: lwr         $a1, 0x2157($at)
    ctx->r5 = do_lwr(rdram, ctx->r5, ctx->r1, 0X2157);
    // 0x80017B60: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017B64: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017B68: lwl         $a2, 0x2158($at)
    ctx->r6 = do_lwl(rdram, ctx->r6, ctx->r1, 0X2158);
    // 0x80017B6C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017B70: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017B74: lwr         $a2, 0x215B($at)
    ctx->r6 = do_lwr(rdram, ctx->r6, ctx->r1, 0X215B);
    // 0x80017B78: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017B7C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017B80: lwl         $a3, 0x215C($at)
    ctx->r7 = do_lwl(rdram, ctx->r7, ctx->r1, 0X215C);
    // 0x80017B84: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017B88: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017B8C: lwr         $a3, 0x215F($at)
    ctx->r7 = do_lwr(rdram, ctx->r7, ctx->r1, 0X215F);
    // 0x80017B90: swl         $a0, 0x0($v1)
    do_swl(rdram, 0X0, ctx->r3, ctx->r4);
    // 0x80017B94: swr         $a0, 0x3($v1)
    do_swr(rdram, 0X3, ctx->r3, ctx->r4);
    // 0x80017B98: swl         $a1, 0x4($v1)
    do_swl(rdram, 0X4, ctx->r3, ctx->r5);
    // 0x80017B9C: swr         $a1, 0x7($v1)
    do_swr(rdram, 0X7, ctx->r3, ctx->r5);
    // 0x80017BA0: swl         $a2, 0x8($v1)
    do_swl(rdram, 0X8, ctx->r3, ctx->r6);
    // 0x80017BA4: swr         $a2, 0xB($v1)
    do_swr(rdram, 0XB, ctx->r3, ctx->r6);
    // 0x80017BA8: swl         $a3, 0xC($v1)
    do_swl(rdram, 0XC, ctx->r3, ctx->r7);
    // 0x80017BAC: swr         $a3, 0xF($v1)
    do_swr(rdram, 0XF, ctx->r3, ctx->r7);
    // 0x80017BB0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017BB4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017BB8: lwl         $a0, 0x2160($at)
    ctx->r4 = do_lwl(rdram, ctx->r4, ctx->r1, 0X2160);
    // 0x80017BBC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017BC0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017BC4: lwr         $a0, 0x2163($at)
    ctx->r4 = do_lwr(rdram, ctx->r4, ctx->r1, 0X2163);
    // 0x80017BC8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017BCC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017BD0: lwl         $a1, 0x2164($at)
    ctx->r5 = do_lwl(rdram, ctx->r5, ctx->r1, 0X2164);
    // 0x80017BD4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017BD8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80017BDC: lwr         $a1, 0x2167($at)
    ctx->r5 = do_lwr(rdram, ctx->r5, ctx->r1, 0X2167);
    // 0x80017BE0: swl         $a0, 0x10($v1)
    do_swl(rdram, 0X10, ctx->r3, ctx->r4);
    // 0x80017BE4: swr         $a0, 0x13($v1)
    do_swr(rdram, 0X13, ctx->r3, ctx->r4);
    // 0x80017BE8: swl         $a1, 0x14($v1)
    do_swl(rdram, 0X14, ctx->r3, ctx->r5);
    // 0x80017BEC: jr          $ra
    // 0x80017BF0: swr         $a1, 0x17($v1)
    do_swr(rdram, 0X17, ctx->r3, ctx->r5);
    return;
    // 0x80017BF0: swr         $a1, 0x17($v1)
    do_swr(rdram, 0X17, ctx->r3, ctx->r5);
;}
