#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80025B98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025B98: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80025B9C: sb          $zero, 0x7B7D($at)
    MEM_B(0X7B7D, ctx->r1) = 0;
    // 0x80025BA0: jr          $ra
    // 0x80025BA4: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    return;
    // 0x80025BA4: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80025BA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025BA8: lw          $v0, 0xB8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB8);
    // 0x80025BAC: addiu       $v1, $zero, 0x400
    ctx->r3 = ADD32(0, 0X400);
    // 0x80025BB0: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x80025BB4: lw          $v0, 0x114($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X114);
    // 0x80025BB8: beql        $v0, $zero, L_80025BC0
    if (ctx->r2 == 0) {
        // 0x80025BBC: sb          $zero, 0x11E($a0)
        MEM_B(0X11E, ctx->r4) = 0;
            goto L_80025BC0;
    }
    goto skip_0;
    // 0x80025BBC: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    skip_0:
L_80025BC0:
    // 0x80025BC0: jr          $ra
    // 0x80025BC4: nop

    return;
    // 0x80025BC4: nop

;}
RECOMP_FUNC void func_80025BC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025BC8: lw          $v1, 0xB8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XB8);
    // 0x80025BCC: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x80025BD0: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80025BD4: lbu         $v0, 0x6B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X6B);
    // 0x80025BD8: sltiu       $v0, $v0, 0x9
    ctx->r2 = ctx->r2 < 0X9 ? 1 : 0;
    // 0x80025BDC: beql        $v0, $zero, L_80025BE4
    if (ctx->r2 == 0) {
        // 0x80025BE0: sb          $zero, 0x11E($a0)
        MEM_B(0X11E, ctx->r4) = 0;
            goto L_80025BE4;
    }
    goto skip_0;
    // 0x80025BE0: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    skip_0:
L_80025BE4:
    // 0x80025BE4: jr          $ra
    // 0x80025BE8: nop

    return;
    // 0x80025BE8: nop

;}
RECOMP_FUNC void func_80025BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025BEC: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x80025BF0: lbu         $v1, 0x124($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X124);
    // 0x80025BF4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80025BF8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80025BFC: sb          $v1, 0x124($a0)
    MEM_B(0X124, ctx->r4) = ctx->r3;
    // 0x80025C00: sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3 << 24);
    // 0x80025C04: bne         $v1, $zero, L_80025C10
    if (ctx->r3 != 0) {
        // 0x80025C08: sw          $v0, 0x2C($a0)
        MEM_W(0X2C, ctx->r4) = ctx->r2;
            goto L_80025C10;
    }
    // 0x80025C08: sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
    // 0x80025C0C: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
L_80025C10:
    // 0x80025C10: jr          $ra
    // 0x80025C14: nop

    return;
    // 0x80025C14: nop

;}
RECOMP_FUNC void func_80025C18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025C18: jr          $ra
    // 0x80025C1C: nop

    return;
    // 0x80025C1C: nop

;}
RECOMP_FUNC void func_80025C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025C20: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80025C24: lw          $v0, 0x2C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X2C);
    // 0x80025C28: lb          $a0, 0xCC($a1)
    ctx->r4 = MEM_B(ctx->r5, 0XCC);
    // 0x80025C2C: lb          $v1, 0xCD($a1)
    ctx->r3 = MEM_B(ctx->r5, 0XCD);
    // 0x80025C30: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80025C34: beq         $a0, $v1, L_80025C4C
    if (ctx->r4 == ctx->r3) {
        // 0x80025C38: sw          $v0, 0x2C($a1)
        MEM_W(0X2C, ctx->r5) = ctx->r2;
            goto L_80025C4C;
    }
    // 0x80025C38: sw          $v0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r2;
    // 0x80025C3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80025C40: sb          $v0, 0x4A($a1)
    MEM_B(0X4A, ctx->r5) = ctx->r2;
    // 0x80025C44: sb          $v0, 0x49($a1)
    MEM_B(0X49, ctx->r5) = ctx->r2;
    // 0x80025C48: sb          $zero, 0x11E($a1)
    MEM_B(0X11E, ctx->r5) = 0;
L_80025C4C:
    // 0x80025C4C: jr          $ra
    // 0x80025C50: nop

    return;
    // 0x80025C50: nop

;}
RECOMP_FUNC void func_80025C54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025C54: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x80025C58: lw          $v1, 0xD0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XD0);
    // 0x80025C5C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80025C60: sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
    // 0x80025C64: lb          $v1, 0x11E($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X11E);
    // 0x80025C68: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    // 0x80025C6C: bne         $v1, $v0, L_80025C80
    if (ctx->r3 != ctx->r2) {
        // 0x80025C70: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80025C80;
    }
    // 0x80025C70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80025C74: sb          $v0, 0x4A($a0)
    MEM_B(0X4A, ctx->r4) = ctx->r2;
    // 0x80025C78: sb          $v0, 0x49($a0)
    MEM_B(0X49, ctx->r4) = ctx->r2;
    // 0x80025C7C: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
L_80025C80:
    // 0x80025C80: jr          $ra
    // 0x80025C84: nop

    return;
    // 0x80025C84: nop

;}
RECOMP_FUNC void func_80025C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025C88: jr          $ra
    // 0x80025C8C: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    return;
    // 0x80025C8C: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80025C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025C90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025C94: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80025C98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025C9C: jal         0x80016AB4
    // 0x80025CA0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x80025CA0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80025CA4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80025CA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80025CAC: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x80025CB0: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x80025CB4: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x80025CB8: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // 0x80025CBC: sw          $zero, 0x104($s0)
    MEM_W(0X104, ctx->r16) = 0;
    // 0x80025CC0: jal         0x800169C8
    // 0x80025CC4: sb          $zero, 0x54($s0)
    MEM_B(0X54, ctx->r16) = 0;
    func_800169C8(rdram, ctx);
        goto after_1;
    // 0x80025CC4: sb          $zero, 0x54($s0)
    MEM_B(0X54, ctx->r16) = 0;
    after_1:
    // 0x80025CC8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80025CCC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80025CD0: jal         0x80016980
    // 0x80025CD4: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_2;
    // 0x80025CD4: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    after_2:
    // 0x80025CD8: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x80025CDC: sb          $zero, 0x55($s0)
    MEM_B(0X55, ctx->r16) = 0;
    // 0x80025CE0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80025CE4: sb          $zero, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = 0;
    // 0x80025CE8: jal         0x8001FA88
    // 0x80025CEC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001FA88(rdram, ctx);
        goto after_3;
    // 0x80025CEC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80025CF0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80025CF4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80025CF8: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80025CFC: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
L_80025D00:
    // 0x80025D00: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80025D04:
    // 0x80025D04: beql        $v1, $a3, L_80025D20
    if (ctx->r3 == ctx->r7) {
        // 0x80025D08: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80025D20;
    }
    goto skip_0;
    // 0x80025D08: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x80025D0C: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
    // 0x80025D10: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80025D14: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80025D18: sb          $a2, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r6;
    // 0x80025D1C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80025D20:
    // 0x80025D20: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80025D24: bne         $v0, $zero, L_80025D04
    if (ctx->r2 != 0) {
        // 0x80025D28: nop
    
            goto L_80025D04;
    }
    // 0x80025D28: nop

    // 0x80025D2C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80025D30: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x80025D34: bne         $v0, $zero, L_80025D00
    if (ctx->r2 != 0) {
        // 0x80025D38: addiu       $a0, $a0, 0x12
        ctx->r4 = ADD32(ctx->r4, 0X12);
            goto L_80025D00;
    }
    // 0x80025D38: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    // 0x80025D3C: sb          $zero, 0x11E($s0)
    MEM_B(0X11E, ctx->r16) = 0;
    // 0x80025D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025D44: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80025D48: jr          $ra
    // 0x80025D4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80025D4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80025D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025D50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025D54: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80025D58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025D5C: jal         0x80016AB4
    // 0x80025D60: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x80025D60: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80025D64: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80025D68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80025D6C: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x80025D70: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x80025D74: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x80025D78: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // 0x80025D7C: sw          $zero, 0x104($s0)
    MEM_W(0X104, ctx->r16) = 0;
    // 0x80025D80: jal         0x800169C8
    // 0x80025D84: sb          $zero, 0x54($s0)
    MEM_B(0X54, ctx->r16) = 0;
    func_800169C8(rdram, ctx);
        goto after_1;
    // 0x80025D84: sb          $zero, 0x54($s0)
    MEM_B(0X54, ctx->r16) = 0;
    after_1:
    // 0x80025D88: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80025D8C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80025D90: jal         0x80016980
    // 0x80025D94: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_2;
    // 0x80025D94: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    after_2:
    // 0x80025D98: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x80025D9C: sb          $zero, 0x55($s0)
    MEM_B(0X55, ctx->r16) = 0;
    // 0x80025DA0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80025DA4: sb          $zero, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = 0;
    // 0x80025DA8: jal         0x8001FA88
    // 0x80025DAC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001FA88(rdram, ctx);
        goto after_3;
    // 0x80025DAC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80025DB0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80025DB4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80025DB8: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80025DBC: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
L_80025DC0:
    // 0x80025DC0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80025DC4:
    // 0x80025DC4: beql        $v1, $a3, L_80025DE0
    if (ctx->r3 == ctx->r7) {
        // 0x80025DC8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80025DE0;
    }
    goto skip_0;
    // 0x80025DC8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x80025DCC: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
    // 0x80025DD0: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80025DD4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80025DD8: sb          $a2, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r6;
    // 0x80025DDC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80025DE0:
    // 0x80025DE0: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80025DE4: bne         $v0, $zero, L_80025DC4
    if (ctx->r2 != 0) {
        // 0x80025DE8: nop
    
            goto L_80025DC4;
    }
    // 0x80025DE8: nop

    // 0x80025DEC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80025DF0: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x80025DF4: bne         $v0, $zero, L_80025DC0
    if (ctx->r2 != 0) {
        // 0x80025DF8: addiu       $a0, $a0, 0x12
        ctx->r4 = ADD32(ctx->r4, 0X12);
            goto L_80025DC0;
    }
    // 0x80025DF8: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    // 0x80025DFC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80025E00: jal         0x80016804
    // 0x80025E04: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80016804(rdram, ctx);
        goto after_4;
    // 0x80025E04: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_4:
    // 0x80025E08: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80025E0C: jal         0x80016804
    // 0x80025E10: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_80016804(rdram, ctx);
        goto after_5;
    // 0x80025E10: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_5:
    // 0x80025E14: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80025E18: jal         0x80016804
    // 0x80025E1C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80016804(rdram, ctx);
        goto after_6;
    // 0x80025E1C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_6:
    // 0x80025E20: sb          $zero, 0x11E($s0)
    MEM_B(0X11E, ctx->r16) = 0;
    // 0x80025E24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025E28: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80025E2C: jr          $ra
    // 0x80025E30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80025E30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80025E34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025E34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80025E38: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80025E3C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80025E40: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80025E44: jal         0x80016AB4
    // 0x80025E48: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x80025E48: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80025E4C: jal         0x80014614
    // 0x80025E50: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80014614(rdram, ctx);
        goto after_1;
    // 0x80025E50: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x80025E54: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80025E58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80025E5C: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
    // 0x80025E60: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
    // 0x80025E64: sb          $zero, 0x3($s1)
    MEM_B(0X3, ctx->r17) = 0;
    // 0x80025E68: sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
    // 0x80025E6C: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x80025E70: sb          $zero, 0x4A($s1)
    MEM_B(0X4A, ctx->r17) = 0;
    // 0x80025E74: sb          $zero, 0x49($s1)
    MEM_B(0X49, ctx->r17) = 0;
    // 0x80025E78: sw          $zero, 0x104($s1)
    MEM_W(0X104, ctx->r17) = 0;
    // 0x80025E7C: jal         0x800169C8
    // 0x80025E80: sb          $s0, 0x54($s1)
    MEM_B(0X54, ctx->r17) = ctx->r16;
    func_800169C8(rdram, ctx);
        goto after_2;
    // 0x80025E80: sb          $s0, 0x54($s1)
    MEM_B(0X54, ctx->r17) = ctx->r16;
    after_2:
    // 0x80025E84: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80025E88: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80025E8C: jal         0x80016980
    // 0x80025E90: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_3;
    // 0x80025E90: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    after_3:
    // 0x80025E94: addiu       $a2, $zero, -0x6
    ctx->r6 = ADD32(0, -0X6);
    // 0x80025E98: addiu       $a1, $zero, -0x6C
    ctx->r5 = ADD32(0, -0X6C);
    // 0x80025E9C: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x80025EA0: sb          $s0, 0x55($s1)
    MEM_B(0X55, ctx->r17) = ctx->r16;
    // 0x80025EA4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80025EA8: sb          $s0, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = ctx->r16;
L_80025EAC:
    // 0x80025EAC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80025EB0: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_80025EB4:
    // 0x80025EB4: lw          $v0, 0xB0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XB0);
    // 0x80025EB8: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80025EBC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80025EC0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80025EC4: sb          $zero, 0x70($v0)
    MEM_B(0X70, ctx->r2) = 0;
    // 0x80025EC8: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80025ECC: bne         $v0, $zero, L_80025EB4
    if (ctx->r2 != 0) {
        // 0x80025ED0: nop
    
            goto L_80025EB4;
    }
    // 0x80025ED0: nop

    // 0x80025ED4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80025ED8: slti        $v0, $a2, 0x12
    ctx->r2 = SIGNED(ctx->r6) < 0X12 ? 1 : 0;
    // 0x80025EDC: bne         $v0, $zero, L_80025EAC
    if (ctx->r2 != 0) {
        // 0x80025EE0: addiu       $a1, $a1, 0x12
        ctx->r5 = ADD32(ctx->r5, 0X12);
            goto L_80025EAC;
    }
    // 0x80025EE0: addiu       $a1, $a1, 0x12
    ctx->r5 = ADD32(ctx->r5, 0X12);
    // 0x80025EE4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80025EE8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
L_80025EEC:
    // 0x80025EEC: lw          $v0, 0xB0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XB0);
    // 0x80025EF0: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80025EF4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80025EF8: sb          $a0, 0x1A2($v0)
    MEM_B(0X1A2, ctx->r2) = ctx->r4;
    // 0x80025EFC: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80025F00: bne         $v0, $zero, L_80025EEC
    if (ctx->r2 != 0) {
        // 0x80025F04: nop
    
            goto L_80025EEC;
    }
    // 0x80025F04: nop

    // 0x80025F08: lw          $v0, 0xB0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XB0);
    // 0x80025F0C: sb          $zero, 0x1A6($v0)
    MEM_B(0X1A6, ctx->r2) = 0;
    // 0x80025F10: lw          $v0, 0xB0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XB0);
    // 0x80025F14: sb          $zero, 0x1A7($v0)
    MEM_B(0X1A7, ctx->r2) = 0;
    // 0x80025F18: sb          $zero, 0x11E($s1)
    MEM_B(0X11E, ctx->r17) = 0;
    // 0x80025F1C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80025F20: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80025F24: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80025F28: jr          $ra
    // 0x80025F2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80025F2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80025F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025F30: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80025F34: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80025F38: addiu       $v1, $v1, 0x7BD0
    ctx->r3 = ADD32(ctx->r3, 0X7BD0);
L_80025F3C:
    // 0x80025F3C: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80025F40: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x80025F44: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x80025F48: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80025F4C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80025F50: slti        $v0, $a1, 0x18
    ctx->r2 = SIGNED(ctx->r5) < 0X18 ? 1 : 0;
    // 0x80025F54: bne         $v0, $zero, L_80025F3C
    if (ctx->r2 != 0) {
        // 0x80025F58: addiu       $v1, $v1, 0x68
        ctx->r3 = ADD32(ctx->r3, 0X68);
            goto L_80025F3C;
    }
    // 0x80025F58: addiu       $v1, $v1, 0x68
    ctx->r3 = ADD32(ctx->r3, 0X68);
    // 0x80025F5C: sw          $zero, 0x104($a0)
    MEM_W(0X104, ctx->r4) = 0;
    // 0x80025F60: jr          $ra
    // 0x80025F64: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    return;
    // 0x80025F64: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80025F68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025F68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025F6C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80025F70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025F74: jal         0x80016AB4
    // 0x80025F78: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x80025F78: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80025F7C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80025F80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80025F84: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x80025F88: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // 0x80025F8C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80025F90: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x80025F94: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x80025F98: sw          $zero, 0x104($s0)
    MEM_W(0X104, ctx->r16) = 0;
    // 0x80025F9C: jal         0x800169C8
    // 0x80025FA0: sb          $v0, 0x54($s0)
    MEM_B(0X54, ctx->r16) = ctx->r2;
    func_800169C8(rdram, ctx);
        goto after_1;
    // 0x80025FA0: sb          $v0, 0x54($s0)
    MEM_B(0X54, ctx->r16) = ctx->r2;
    after_1:
    // 0x80025FA4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80025FA8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80025FAC: jal         0x80016980
    // 0x80025FB0: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_2;
    // 0x80025FB0: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    after_2:
    // 0x80025FB4: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x80025FB8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80025FBC: sb          $v0, 0x55($s0)
    MEM_B(0X55, ctx->r16) = ctx->r2;
    // 0x80025FC0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80025FC4: sb          $v0, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = ctx->r2;
    // 0x80025FC8: jal         0x8001FA88
    // 0x80025FCC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001FA88(rdram, ctx);
        goto after_3;
    // 0x80025FCC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80025FD0: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80025FD4: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80025FD8: addiu       $a0, $zero, 0xFC
    ctx->r4 = ADD32(0, 0XFC);
L_80025FDC:
    // 0x80025FDC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80025FE0:
    // 0x80025FE0: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
    // 0x80025FE4: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80025FE8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80025FEC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80025FF0: sb          $a2, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r6;
    // 0x80025FF4: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80025FF8: bne         $v0, $zero, L_80025FE0
    if (ctx->r2 != 0) {
        // 0x80025FFC: nop
    
            goto L_80025FE0;
    }
    // 0x80025FFC: nop

    // 0x80026000: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026004: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x80026008: bne         $v0, $zero, L_80025FDC
    if (ctx->r2 != 0) {
        // 0x8002600C: addiu       $a0, $a0, 0x12
        ctx->r4 = ADD32(ctx->r4, 0X12);
            goto L_80025FDC;
    }
    // 0x8002600C: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    // 0x80026010: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
    // 0x80026014: sb          $zero, 0x170($v0)
    MEM_B(0X170, ctx->r2) = 0;
    // 0x80026018: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
    // 0x8002601C: sb          $zero, 0x182($v0)
    MEM_B(0X182, ctx->r2) = 0;
    // 0x80026020: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
    // 0x80026024: sb          $zero, 0x192($v0)
    MEM_B(0X192, ctx->r2) = 0;
    // 0x80026028: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
    // 0x8002602C: sb          $zero, 0x193($v0)
    MEM_B(0X193, ctx->r2) = 0;
    // 0x80026030: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
    // 0x80026034: sb          $zero, 0x1A8($v0)
    MEM_B(0X1A8, ctx->r2) = 0;
    // 0x80026038: sb          $zero, 0x11E($s0)
    MEM_B(0X11E, ctx->r16) = 0;
    // 0x8002603C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026040: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80026044: jr          $ra
    // 0x80026048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80026048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002604C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002604C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80026050: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80026054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026058: jal         0x80016AB4
    // 0x8002605C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x8002605C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80026060: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80026064: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80026068: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x8002606C: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x80026070: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x80026074: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // 0x80026078: sw          $zero, 0x104($s0)
    MEM_W(0X104, ctx->r16) = 0;
    // 0x8002607C: jal         0x800169C8
    // 0x80026080: sb          $zero, 0x54($s0)
    MEM_B(0X54, ctx->r16) = 0;
    func_800169C8(rdram, ctx);
        goto after_1;
    // 0x80026080: sb          $zero, 0x54($s0)
    MEM_B(0X54, ctx->r16) = 0;
    after_1:
    // 0x80026084: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80026088: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8002608C: jal         0x80016980
    // 0x80026090: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_2;
    // 0x80026090: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    after_2:
    // 0x80026094: addiu       $a1, $zero, -0x6
    ctx->r5 = ADD32(0, -0X6);
    // 0x80026098: addiu       $a2, $zero, -0x6C
    ctx->r6 = ADD32(0, -0X6C);
    // 0x8002609C: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x800260A0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800260A4: sb          $v0, 0x55($s0)
    MEM_B(0X55, ctx->r16) = ctx->r2;
    // 0x800260A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800260AC: sb          $v0, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = ctx->r2;
L_800260B0:
    // 0x800260B0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800260B4: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
L_800260B8:
    // 0x800260B8: lw          $v0, 0xB0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB0);
    // 0x800260BC: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800260C0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800260C4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800260C8: sb          $zero, 0x70($v0)
    MEM_B(0X70, ctx->r2) = 0;
    // 0x800260CC: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x800260D0: bne         $v0, $zero, L_800260B8
    if (ctx->r2 != 0) {
        // 0x800260D4: nop
    
            goto L_800260B8;
    }
    // 0x800260D4: nop

    // 0x800260D8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800260DC: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x800260E0: bne         $v0, $zero, L_800260B0
    if (ctx->r2 != 0) {
        // 0x800260E4: addiu       $a2, $a2, 0x12
        ctx->r6 = ADD32(ctx->r6, 0X12);
            goto L_800260B0;
    }
    // 0x800260E4: addiu       $a2, $a2, 0x12
    ctx->r6 = ADD32(ctx->r6, 0X12);
    // 0x800260E8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x800260EC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800260F0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x800260F4: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
L_800260F8:
    // 0x800260F8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800260FC:
    // 0x800260FC: beql        $v1, $a3, L_80026118
    if (ctx->r3 == ctx->r7) {
        // 0x80026100: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80026118;
    }
    goto skip_0;
    // 0x80026100: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x80026104: lw          $v0, 0xB0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB0);
    // 0x80026108: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8002610C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80026110: sb          $a2, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r6;
    // 0x80026114: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80026118:
    // 0x80026118: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x8002611C: bne         $v0, $zero, L_800260FC
    if (ctx->r2 != 0) {
        // 0x80026120: nop
    
            goto L_800260FC;
    }
    // 0x80026120: nop

    // 0x80026124: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026128: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x8002612C: bne         $v0, $zero, L_800260F8
    if (ctx->r2 != 0) {
        // 0x80026130: addiu       $a0, $a0, 0x12
        ctx->r4 = ADD32(ctx->r4, 0X12);
            goto L_800260F8;
    }
    // 0x80026130: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    // 0x80026134: lw          $v0, 0xB0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB0);
    // 0x80026138: sb          $zero, 0x192($v0)
    MEM_B(0X192, ctx->r2) = 0;
    // 0x8002613C: lw          $v0, 0xB0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB0);
    // 0x80026140: sb          $zero, 0x1A7($v0)
    MEM_B(0X1A7, ctx->r2) = 0;
    // 0x80026144: sb          $zero, 0x11E($s0)
    MEM_B(0X11E, ctx->r16) = 0;
    // 0x80026148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002614C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80026150: jr          $ra
    // 0x80026154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80026154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80026158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026158: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002615C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80026160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026164: jal         0x80016AB4
    // 0x80026168: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x80026168: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8002616C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80026170: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80026174: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x80026178: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x8002617C: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x80026180: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // 0x80026184: sb          $zero, 0x49($s0)
    MEM_B(0X49, ctx->r16) = 0;
    // 0x80026188: sb          $v0, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = ctx->r2;
    // 0x8002618C: sw          $zero, 0x104($s0)
    MEM_W(0X104, ctx->r16) = 0;
    // 0x80026190: jal         0x800169C8
    // 0x80026194: sb          $zero, 0x54($s0)
    MEM_B(0X54, ctx->r16) = 0;
    func_800169C8(rdram, ctx);
        goto after_1;
    // 0x80026194: sb          $zero, 0x54($s0)
    MEM_B(0X54, ctx->r16) = 0;
    after_1:
    // 0x80026198: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8002619C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800261A0: jal         0x80016980
    // 0x800261A4: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_2;
    // 0x800261A4: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    after_2:
    // 0x800261A8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800261AC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800261B0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x800261B4: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    // 0x800261B8: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x800261BC: sb          $zero, 0x55($s0)
    MEM_B(0X55, ctx->r16) = 0;
    // 0x800261C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800261C4: sb          $zero, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = 0;
L_800261C8:
    // 0x800261C8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800261CC:
    // 0x800261CC: beql        $v1, $a3, L_800261E8
    if (ctx->r3 == ctx->r7) {
        // 0x800261D0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800261E8;
    }
    goto skip_0;
    // 0x800261D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x800261D4: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
    // 0x800261D8: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800261DC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800261E0: sb          $a2, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r6;
    // 0x800261E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800261E8:
    // 0x800261E8: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x800261EC: bne         $v0, $zero, L_800261CC
    if (ctx->r2 != 0) {
        // 0x800261F0: nop
    
            goto L_800261CC;
    }
    // 0x800261F0: nop

    // 0x800261F4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800261F8: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x800261FC: bne         $v0, $zero, L_800261C8
    if (ctx->r2 != 0) {
        // 0x80026200: addiu       $a0, $a0, 0x12
        ctx->r4 = ADD32(ctx->r4, 0X12);
            goto L_800261C8;
    }
    // 0x80026200: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    // 0x80026204: jal         0x80016F44
    // 0x80026208: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80016F44(rdram, ctx);
        goto after_3;
    // 0x80026208: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8002620C: sb          $zero, 0x11E($s0)
    MEM_B(0X11E, ctx->r16) = 0;
    // 0x80026210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026214: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80026218: jr          $ra
    // 0x8002621C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002621C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80026220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026220: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026224: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80026228: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8002622C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80026230: jal         0x80016AB4
    // 0x80026234: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x80026234: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80026238: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8002623C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80026240: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
    // 0x80026244: sb          $zero, 0x3($s1)
    MEM_B(0X3, ctx->r17) = 0;
    // 0x80026248: sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
    // 0x8002624C: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x80026250: sb          $zero, 0x49($s1)
    MEM_B(0X49, ctx->r17) = 0;
    // 0x80026254: sb          $v0, 0x4A($s1)
    MEM_B(0X4A, ctx->r17) = ctx->r2;
    // 0x80026258: sw          $zero, 0x104($s1)
    MEM_W(0X104, ctx->r17) = 0;
    // 0x8002625C: jal         0x800169C8
    // 0x80026260: sb          $zero, 0x54($s1)
    MEM_B(0X54, ctx->r17) = 0;
    func_800169C8(rdram, ctx);
        goto after_1;
    // 0x80026260: sb          $zero, 0x54($s1)
    MEM_B(0X54, ctx->r17) = 0;
    after_1:
    // 0x80026264: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80026268: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8002626C: jal         0x80016980
    // 0x80026270: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_2;
    // 0x80026270: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    after_2:
    // 0x80026274: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80026278: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x8002627C: sb          $zero, 0x55($s1)
    MEM_B(0X55, ctx->r17) = 0;
L_80026280:
    // 0x80026280: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80026284: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // 0x80026288: lb          $a1, -0x2448($a1)
    ctx->r5 = MEM_B(ctx->r5, -0X2448);
    // 0x8002628C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80026290: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80026294: jal         0x80016804
    // 0x80026298: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    func_80016804(rdram, ctx);
        goto after_3;
    // 0x80026298: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_3:
    // 0x8002629C: slti        $v0, $s0, 0xE
    ctx->r2 = SIGNED(ctx->r16) < 0XE ? 1 : 0;
    // 0x800262A0: bne         $v0, $zero, L_80026280
    if (ctx->r2 != 0) {
        // 0x800262A4: nop
    
            goto L_80026280;
    }
    // 0x800262A4: nop

    // 0x800262A8: sb          $zero, 0x11E($s1)
    MEM_B(0X11E, ctx->r17) = 0;
    // 0x800262AC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800262B0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800262B4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800262B8: jr          $ra
    // 0x800262BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800262BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800262C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800262C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800262C4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800262C8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800262CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800262D0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800262D4: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
    // 0x800262D8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800262DC: sb          $v0, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = ctx->r2;
    // 0x800262E0: sb          $v0, 0x49($s0)
    MEM_B(0X49, ctx->r16) = ctx->r2;
    // 0x800262E4: sw          $zero, 0x104($s0)
    MEM_W(0X104, ctx->r16) = 0;
    // 0x800262E8: jal         0x800169C8
    // 0x800262EC: sb          $s1, 0x54($s0)
    MEM_B(0X54, ctx->r16) = ctx->r17;
    func_800169C8(rdram, ctx);
        goto after_0;
    // 0x800262EC: sb          $s1, 0x54($s0)
    MEM_B(0X54, ctx->r16) = ctx->r17;
    after_0:
    // 0x800262F0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800262F4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800262F8: jal         0x80016980
    // 0x800262FC: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_1;
    // 0x800262FC: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    after_1:
    // 0x80026300: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x80026304: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80026308: sb          $s1, 0x55($s0)
    MEM_B(0X55, ctx->r16) = ctx->r17;
    // 0x8002630C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80026310: sb          $v0, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = ctx->r2;
    // 0x80026314: sb          $zero, 0x11E($s0)
    MEM_B(0X11E, ctx->r16) = 0;
    // 0x80026318: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8002631C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80026320: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80026324: jr          $ra
    // 0x80026328: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80026328: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8002632C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002632C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80026330: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80026334: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80026338: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8002633C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026340: jal         0x800169C8
    // 0x80026344: sb          $v0, 0x54($s0)
    MEM_B(0X54, ctx->r16) = ctx->r2;
    func_800169C8(rdram, ctx);
        goto after_0;
    // 0x80026344: sb          $v0, 0x54($s0)
    MEM_B(0X54, ctx->r16) = ctx->r2;
    after_0:
    // 0x80026348: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8002634C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80026350: jal         0x80016980
    // 0x80026354: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_1;
    // 0x80026354: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    after_1:
    // 0x80026358: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x8002635C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80026360: sb          $zero, 0x55($s0)
    MEM_B(0X55, ctx->r16) = 0;
    // 0x80026364: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80026368: sb          $v0, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = ctx->r2;
    // 0x8002636C: sb          $zero, 0x11E($s0)
    MEM_B(0X11E, ctx->r16) = 0;
    // 0x80026370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026374: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80026378: jr          $ra
    // 0x8002637C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002637C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80026380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026380: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026384: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80026388: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8002638C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80026390: jal         0x80016AB4
    // 0x80026394: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x80026394: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80026398: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8002639C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800263A0: sb          $s0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r16;
    // 0x800263A4: sb          $zero, 0x3($s1)
    MEM_B(0X3, ctx->r17) = 0;
    // 0x800263A8: sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
    // 0x800263AC: sb          $s0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r16;
    // 0x800263B0: sw          $zero, 0x104($s1)
    MEM_W(0X104, ctx->r17) = 0;
    // 0x800263B4: jal         0x800169C8
    // 0x800263B8: sb          $zero, 0x54($s1)
    MEM_B(0X54, ctx->r17) = 0;
    func_800169C8(rdram, ctx);
        goto after_1;
    // 0x800263B8: sb          $zero, 0x54($s1)
    MEM_B(0X54, ctx->r17) = 0;
    after_1:
    // 0x800263BC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800263C0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800263C4: jal         0x80016980
    // 0x800263C8: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_2;
    // 0x800263C8: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    after_2:
    // 0x800263CC: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x800263D0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800263D4: sb          $v0, 0x55($s1)
    MEM_B(0X55, ctx->r17) = ctx->r2;
    // 0x800263D8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800263DC: sb          $s0, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = ctx->r16;
    // 0x800263E0: jal         0x8001FA88
    // 0x800263E4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001FA88(rdram, ctx);
        goto after_3;
    // 0x800263E4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
    // 0x800263E8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800263EC: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x800263F0: addiu       $a0, $zero, 0x7E
    ctx->r4 = ADD32(0, 0X7E);
L_800263F4:
    // 0x800263F4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800263F8:
    // 0x800263F8: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x800263FC: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80026400: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80026404: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80026408: sb          $a2, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r6;
    // 0x8002640C: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80026410: bne         $v0, $zero, L_800263F8
    if (ctx->r2 != 0) {
        // 0x80026414: nop
    
            goto L_800263F8;
    }
    // 0x80026414: nop

    // 0x80026418: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002641C: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x80026420: bne         $v0, $zero, L_800263F4
    if (ctx->r2 != 0) {
        // 0x80026424: addiu       $a0, $a0, 0x12
        ctx->r4 = ADD32(ctx->r4, 0X12);
            goto L_800263F4;
    }
    // 0x80026424: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    // 0x80026428: jal         0x80016F44
    // 0x8002642C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80016F44(rdram, ctx);
        goto after_4;
    // 0x8002642C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
    // 0x80026430: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026434: sb          $zero, 0xF0($v0)
    MEM_B(0XF0, ctx->r2) = 0;
    // 0x80026438: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x8002643C: sb          $zero, 0x107($v0)
    MEM_B(0X107, ctx->r2) = 0;
    // 0x80026440: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026444: sb          $zero, 0x116($v0)
    MEM_B(0X116, ctx->r2) = 0;
    // 0x80026448: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x8002644C: sb          $zero, 0x128($v0)
    MEM_B(0X128, ctx->r2) = 0;
    // 0x80026450: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026454: sb          $zero, 0x136($v0)
    MEM_B(0X136, ctx->r2) = 0;
    // 0x80026458: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x8002645C: sb          $zero, 0x137($v0)
    MEM_B(0X137, ctx->r2) = 0;
    // 0x80026460: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026464: sb          $zero, 0x148($v0)
    MEM_B(0X148, ctx->r2) = 0;
    // 0x80026468: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x8002646C: sb          $zero, 0x15A($v0)
    MEM_B(0X15A, ctx->r2) = 0;
    // 0x80026470: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026474: sb          $zero, 0x175($v0)
    MEM_B(0X175, ctx->r2) = 0;
    // 0x80026478: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x8002647C: sb          $zero, 0x187($v0)
    MEM_B(0X187, ctx->r2) = 0;
    // 0x80026480: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026484: sb          $zero, 0x199($v0)
    MEM_B(0X199, ctx->r2) = 0;
    // 0x80026488: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x8002648C: sb          $zero, 0x1AB($v0)
    MEM_B(0X1AB, ctx->r2) = 0;
    // 0x80026490: sb          $zero, 0x11E($s1)
    MEM_B(0X11E, ctx->r17) = 0;
    // 0x80026494: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80026498: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8002649C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800264A0: jr          $ra
    // 0x800264A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800264A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800264A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800264A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800264AC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800264B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800264B4: jal         0x80016AB4
    // 0x800264B8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x800264B8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x800264BC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800264C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800264C4: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x800264C8: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x800264CC: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x800264D0: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // 0x800264D4: jal         0x8001FA88
    // 0x800264D8: sb          $zero, 0x49($s0)
    MEM_B(0X49, ctx->r16) = 0;
    func_8001FA88(rdram, ctx);
        goto after_1;
    // 0x800264D8: sb          $zero, 0x49($s0)
    MEM_B(0X49, ctx->r16) = 0;
    after_1:
    // 0x800264DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800264E0: sw          $zero, 0x104($s0)
    MEM_W(0X104, ctx->r16) = 0;
    // 0x800264E4: jal         0x800169C8
    // 0x800264E8: sb          $zero, 0x54($s0)
    MEM_B(0X54, ctx->r16) = 0;
    func_800169C8(rdram, ctx);
        goto after_2;
    // 0x800264E8: sb          $zero, 0x54($s0)
    MEM_B(0X54, ctx->r16) = 0;
    after_2:
    // 0x800264EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800264F0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800264F4: jal         0x80016980
    // 0x800264F8: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_3;
    // 0x800264F8: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    after_3:
    // 0x800264FC: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x80026500: sb          $zero, 0x55($s0)
    MEM_B(0X55, ctx->r16) = 0;
    // 0x80026504: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80026508: sb          $zero, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = 0;
    // 0x8002650C: sb          $zero, 0x11E($s0)
    MEM_B(0X11E, ctx->r16) = 0;
    // 0x80026510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026514: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80026518: jr          $ra
    // 0x8002651C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002651C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80026520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026520: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026524: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80026528: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8002652C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80026530: jal         0x80016AB4
    // 0x80026534: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x80026534: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80026538: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8002653C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80026540: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80026544: sb          $s0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r16;
    // 0x80026548: sb          $zero, 0x3($s1)
    MEM_B(0X3, ctx->r17) = 0;
    // 0x8002654C: sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
    // 0x80026550: sb          $s0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r16;
    // 0x80026554: sb          $zero, 0x49($s1)
    MEM_B(0X49, ctx->r17) = 0;
    // 0x80026558: sb          $s0, 0x4A($s1)
    MEM_B(0X4A, ctx->r17) = ctx->r16;
    // 0x8002655C: sw          $zero, 0x104($s1)
    MEM_W(0X104, ctx->r17) = 0;
    // 0x80026560: jal         0x800169C8
    // 0x80026564: sb          $v0, 0x54($s1)
    MEM_B(0X54, ctx->r17) = ctx->r2;
    func_800169C8(rdram, ctx);
        goto after_1;
    // 0x80026564: sb          $v0, 0x54($s1)
    MEM_B(0X54, ctx->r17) = ctx->r2;
    after_1:
    // 0x80026568: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8002656C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80026570: jal         0x80016980
    // 0x80026574: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_2;
    // 0x80026574: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    after_2:
    // 0x80026578: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x8002657C: sb          $zero, 0x55($s1)
    MEM_B(0X55, ctx->r17) = 0;
    // 0x80026580: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80026584: sb          $s0, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = ctx->r16;
    // 0x80026588: jal         0x8001FA88
    // 0x8002658C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001FA88(rdram, ctx);
        goto after_3;
    // 0x8002658C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
    // 0x80026590: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80026594: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80026598: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
L_8002659C:
    // 0x8002659C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800265A0:
    // 0x800265A0: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x800265A4: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800265A8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800265AC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800265B0: sb          $a2, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r6;
    // 0x800265B4: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x800265B8: bne         $v0, $zero, L_800265A0
    if (ctx->r2 != 0) {
        // 0x800265BC: nop
    
            goto L_800265A0;
    }
    // 0x800265BC: nop

    // 0x800265C0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800265C4: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x800265C8: bne         $v0, $zero, L_8002659C
    if (ctx->r2 != 0) {
        // 0x800265CC: addiu       $a0, $a0, 0x12
        ctx->r4 = ADD32(ctx->r4, 0X12);
            goto L_8002659C;
    }
    // 0x800265CC: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    // 0x800265D0: jal         0x80016F44
    // 0x800265D4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80016F44(rdram, ctx);
        goto after_4;
    // 0x800265D4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
    // 0x800265D8: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x800265DC: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
    // 0x800265E0: sb          $v1, 0x100($v0)
    MEM_B(0X100, ctx->r2) = ctx->r3;
    // 0x800265E4: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x800265E8: sb          $v1, 0x104($v0)
    MEM_B(0X104, ctx->r2) = ctx->r3;
    // 0x800265EC: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x800265F0: sb          $v1, 0x109($v0)
    MEM_B(0X109, ctx->r2) = ctx->r3;
    // 0x800265F4: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x800265F8: sb          $v1, 0x112($v0)
    MEM_B(0X112, ctx->r2) = ctx->r3;
    // 0x800265FC: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026600: sb          $v1, 0x116($v0)
    MEM_B(0X116, ctx->r2) = ctx->r3;
    // 0x80026604: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026608: sb          $v1, 0x11B($v0)
    MEM_B(0X11B, ctx->r2) = ctx->r3;
    // 0x8002660C: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026610: sb          $zero, 0x127($v0)
    MEM_B(0X127, ctx->r2) = 0;
    // 0x80026614: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026618: sb          $zero, 0x129($v0)
    MEM_B(0X129, ctx->r2) = 0;
    // 0x8002661C: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026620: sb          $zero, 0x12A($v0)
    MEM_B(0X12A, ctx->r2) = 0;
    // 0x80026624: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026628: sb          $zero, 0x12B($v0)
    MEM_B(0X12B, ctx->r2) = 0;
    // 0x8002662C: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026630: sb          $zero, 0x12C($v0)
    MEM_B(0X12C, ctx->r2) = 0;
    // 0x80026634: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026638: sb          $zero, 0x139($v0)
    MEM_B(0X139, ctx->r2) = 0;
    // 0x8002663C: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026640: sb          $zero, 0x13B($v0)
    MEM_B(0X13B, ctx->r2) = 0;
    // 0x80026644: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026648: sb          $zero, 0x13C($v0)
    MEM_B(0X13C, ctx->r2) = 0;
    // 0x8002664C: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026650: sb          $zero, 0x13D($v0)
    MEM_B(0X13D, ctx->r2) = 0;
    // 0x80026654: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026658: sb          $zero, 0x13E($v0)
    MEM_B(0X13E, ctx->r2) = 0;
    // 0x8002665C: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026660: sb          $zero, 0x14F($v0)
    MEM_B(0X14F, ctx->r2) = 0;
    // 0x80026664: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026668: sb          $zero, 0x15D($v0)
    MEM_B(0X15D, ctx->r2) = 0;
    // 0x8002666C: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026670: sb          $zero, 0x173($v0)
    MEM_B(0X173, ctx->r2) = 0;
    // 0x80026674: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026678: sb          $zero, 0x187($v0)
    MEM_B(0X187, ctx->r2) = 0;
    // 0x8002667C: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026680: sb          $zero, 0x195($v0)
    MEM_B(0X195, ctx->r2) = 0;
    // 0x80026684: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026688: sb          $zero, 0x1A9($v0)
    MEM_B(0X1A9, ctx->r2) = 0;
    // 0x8002668C: lbu         $v1, 0x74($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X74);
    // 0x80026690: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80026694: addiu       $a1, $a1, -0x3998
    ctx->r5 = ADD32(ctx->r5, -0X3998);
    // 0x80026698: lbu         $a0, 0x64($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X64);
    // 0x8002669C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800266A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800266A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800266A8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800266AC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800266B0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800266B4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800266B8: sb          $zero, 0x11E($s1)
    MEM_B(0X11E, ctx->r17) = 0;
    // 0x800266BC: addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
    // 0x800266C0: sb          $v0, 0x63($s1)
    MEM_B(0X63, ctx->r17) = ctx->r2;
    // 0x800266C4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800266C8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800266CC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800266D0: jr          $ra
    // 0x800266D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800266D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800266D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800266D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800266DC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800266E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800266E4: jal         0x80016AB4
    // 0x800266E8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x800266E8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x800266EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800266F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800266F4: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x800266F8: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x800266FC: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x80026700: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // 0x80026704: jal         0x8001FA88
    // 0x80026708: sb          $zero, 0x49($s0)
    MEM_B(0X49, ctx->r16) = 0;
    func_8001FA88(rdram, ctx);
        goto after_1;
    // 0x80026708: sb          $zero, 0x49($s0)
    MEM_B(0X49, ctx->r16) = 0;
    after_1:
    // 0x8002670C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80026710: sw          $zero, 0x104($s0)
    MEM_W(0X104, ctx->r16) = 0;
    // 0x80026714: jal         0x800169C8
    // 0x80026718: sb          $zero, 0x54($s0)
    MEM_B(0X54, ctx->r16) = 0;
    func_800169C8(rdram, ctx);
        goto after_2;
    // 0x80026718: sb          $zero, 0x54($s0)
    MEM_B(0X54, ctx->r16) = 0;
    after_2:
    // 0x8002671C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80026720: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80026724: jal         0x80016980
    // 0x80026728: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_3;
    // 0x80026728: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    after_3:
    // 0x8002672C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80026730: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80026734: addiu       $v1, $v1, 0x7BD0
    ctx->r3 = ADD32(ctx->r3, 0X7BD0);
    // 0x80026738: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8002673C: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x80026740: sb          $zero, 0x55($s0)
    MEM_B(0X55, ctx->r16) = 0;
    // 0x80026744: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80026748: sb          $zero, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = 0;
    // 0x8002674C: sb          $zero, 0x11E($s0)
    MEM_B(0X11E, ctx->r16) = 0;
L_80026750:
    // 0x80026750: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80026754: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x80026758: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x8002675C: addiu       $v1, $v1, 0x68
    ctx->r3 = ADD32(ctx->r3, 0X68);
    // 0x80026760: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80026764: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80026768: sb          $zero, 0x7BD0($at)
    MEM_B(0X7BD0, ctx->r1) = 0;
    // 0x8002676C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026770: slti        $v0, $a1, 0x18
    ctx->r2 = SIGNED(ctx->r5) < 0X18 ? 1 : 0;
    // 0x80026774: bne         $v0, $zero, L_80026750
    if (ctx->r2 != 0) {
        // 0x80026778: addiu       $a0, $a0, 0x68
        ctx->r4 = ADD32(ctx->r4, 0X68);
            goto L_80026750;
    }
    // 0x80026778: addiu       $a0, $a0, 0x68
    ctx->r4 = ADD32(ctx->r4, 0X68);
    // 0x8002677C: lw          $v0, 0xD0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD0);
    // 0x80026780: sb          $zero, 0xCD($v0)
    MEM_B(0XCD, ctx->r2) = 0;
    // 0x80026784: sb          $zero, 0xCC($v0)
    MEM_B(0XCC, ctx->r2) = 0;
    // 0x80026788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002678C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80026790: jr          $ra
    // 0x80026794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80026794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80026798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026798: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002679C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800267A0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800267A4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800267A8: jal         0x80016AB4
    // 0x800267AC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x800267AC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // 0x800267B0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800267B4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800267B8: sb          $s1, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r17;
    // 0x800267BC: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x800267C0: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x800267C4: sb          $s1, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r17;
    // 0x800267C8: jal         0x8001FA88
    // 0x800267CC: sb          $zero, 0x49($s0)
    MEM_B(0X49, ctx->r16) = 0;
    func_8001FA88(rdram, ctx);
        goto after_1;
    // 0x800267CC: sb          $zero, 0x49($s0)
    MEM_B(0X49, ctx->r16) = 0;
    after_1:
    // 0x800267D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800267D4: sw          $zero, 0x104($s0)
    MEM_W(0X104, ctx->r16) = 0;
    // 0x800267D8: jal         0x800169C8
    // 0x800267DC: sb          $zero, 0x54($s0)
    MEM_B(0X54, ctx->r16) = 0;
    func_800169C8(rdram, ctx);
        goto after_2;
    // 0x800267DC: sb          $zero, 0x54($s0)
    MEM_B(0X54, ctx->r16) = 0;
    after_2:
    // 0x800267E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800267E4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800267E8: jal         0x80016980
    // 0x800267EC: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_3;
    // 0x800267EC: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    after_3:
    // 0x800267F0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800267F4: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x800267F8: sb          $zero, 0x55($s0)
    MEM_B(0X55, ctx->r16) = 0;
    // 0x800267FC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80026800: sb          $zero, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = 0;
    // 0x80026804: sb          $zero, 0x11E($s0)
    MEM_B(0X11E, ctx->r16) = 0;
    // 0x80026808: jal         0x800169C8
    // 0x8002680C: sb          $s1, 0x54($s0)
    MEM_B(0X54, ctx->r16) = ctx->r17;
    func_800169C8(rdram, ctx);
        goto after_4;
    // 0x8002680C: sb          $s1, 0x54($s0)
    MEM_B(0X54, ctx->r16) = ctx->r17;
    after_4:
    // 0x80026810: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80026814: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80026818: jal         0x80016980
    // 0x8002681C: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_5;
    // 0x8002681C: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    after_5:
    // 0x80026820: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x80026824: sb          $s1, 0x55($s0)
    MEM_B(0X55, ctx->r16) = ctx->r17;
    // 0x80026828: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002682C: sb          $s1, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = ctx->r17;
    // 0x80026830: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80026834: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80026838: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002683C: jr          $ra
    // 0x80026840: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80026840: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80026844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026844: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026848: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8002684C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80026850: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80026854: jal         0x80016AB4
    // 0x80026858: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x80026858: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8002685C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80026860: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80026864: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
    // 0x80026868: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
    // 0x8002686C: sb          $zero, 0x3($s1)
    MEM_B(0X3, ctx->r17) = 0;
    // 0x80026870: sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
    // 0x80026874: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x80026878: sb          $v0, 0x4A($s1)
    MEM_B(0X4A, ctx->r17) = ctx->r2;
    // 0x8002687C: sb          $v0, 0x49($s1)
    MEM_B(0X49, ctx->r17) = ctx->r2;
    // 0x80026880: sw          $zero, 0x104($s1)
    MEM_W(0X104, ctx->r17) = 0;
    // 0x80026884: jal         0x800169C8
    // 0x80026888: sb          $s0, 0x54($s1)
    MEM_B(0X54, ctx->r17) = ctx->r16;
    func_800169C8(rdram, ctx);
        goto after_1;
    // 0x80026888: sb          $s0, 0x54($s1)
    MEM_B(0X54, ctx->r17) = ctx->r16;
    after_1:
    // 0x8002688C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80026890: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80026894: jal         0x80016980
    // 0x80026898: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_2;
    // 0x80026898: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    after_2:
    // 0x8002689C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800268A0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x800268A4: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    // 0x800268A8: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x800268AC: sb          $s0, 0x55($s1)
    MEM_B(0X55, ctx->r17) = ctx->r16;
    // 0x800268B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800268B4: sb          $s0, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = ctx->r16;
    // 0x800268B8: sb          $s0, 0x11C($s1)
    MEM_B(0X11C, ctx->r17) = ctx->r16;
L_800268BC:
    // 0x800268BC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800268C0:
    // 0x800268C0: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x800268C4: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800268C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800268CC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800268D0: sb          $a2, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r6;
    // 0x800268D4: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x800268D8: bne         $v0, $zero, L_800268C0
    if (ctx->r2 != 0) {
        // 0x800268DC: nop
    
            goto L_800268C0;
    }
    // 0x800268DC: nop

    // 0x800268E0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800268E4: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x800268E8: bne         $v0, $zero, L_800268BC
    if (ctx->r2 != 0) {
        // 0x800268EC: addiu       $a0, $a0, 0x12
        ctx->r4 = ADD32(ctx->r4, 0X12);
            goto L_800268BC;
    }
    // 0x800268EC: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    // 0x800268F0: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x800268F4: sb          $zero, 0x197($v0)
    MEM_B(0X197, ctx->r2) = 0;
    // 0x800268F8: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x800268FC: sb          $zero, 0x198($v0)
    MEM_B(0X198, ctx->r2) = 0;
    // 0x80026900: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026904: sb          $zero, 0x1A5($v0)
    MEM_B(0X1A5, ctx->r2) = 0;
    // 0x80026908: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x8002690C: sb          $zero, 0x1A6($v0)
    MEM_B(0X1A6, ctx->r2) = 0;
    // 0x80026910: sb          $zero, 0x11E($s1)
    MEM_B(0X11E, ctx->r17) = 0;
    // 0x80026914: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80026918: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8002691C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80026920: jr          $ra
    // 0x80026924: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80026924: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80026928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026928: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002692C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80026930: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80026934: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80026938: jal         0x80016AB4
    // 0x8002693C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x8002693C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80026940: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80026944: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80026948: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x8002694C: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
    // 0x80026950: sb          $zero, 0x3($s1)
    MEM_B(0X3, ctx->r17) = 0;
    // 0x80026954: sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
    // 0x80026958: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x8002695C: sb          $v0, 0x4A($s1)
    MEM_B(0X4A, ctx->r17) = ctx->r2;
    // 0x80026960: sb          $v0, 0x49($s1)
    MEM_B(0X49, ctx->r17) = ctx->r2;
    // 0x80026964: sw          $zero, 0x104($s1)
    MEM_W(0X104, ctx->r17) = 0;
    // 0x80026968: jal         0x800169C8
    // 0x8002696C: sb          $s0, 0x54($s1)
    MEM_B(0X54, ctx->r17) = ctx->r16;
    func_800169C8(rdram, ctx);
        goto after_1;
    // 0x8002696C: sb          $s0, 0x54($s1)
    MEM_B(0X54, ctx->r17) = ctx->r16;
    after_1:
    // 0x80026970: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80026974: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80026978: jal         0x80016980
    // 0x8002697C: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_2;
    // 0x8002697C: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    after_2:
    // 0x80026980: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80026984: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x80026988: sb          $s0, 0x55($s1)
    MEM_B(0X55, ctx->r17) = ctx->r16;
    // 0x8002698C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80026990: sb          $s0, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = ctx->r16;
    // 0x80026994: lw          $v0, 0xD0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XD0);
    // 0x80026998: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8002699C: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    // 0x800269A0: sb          $s0, 0x11C($s1)
    MEM_B(0X11C, ctx->r17) = ctx->r16;
    // 0x800269A4: sb          $zero, 0xCD($v0)
    MEM_B(0XCD, ctx->r2) = 0;
    // 0x800269A8: sb          $zero, 0xCC($v0)
    MEM_B(0XCC, ctx->r2) = 0;
L_800269AC:
    // 0x800269AC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800269B0:
    // 0x800269B0: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x800269B4: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800269B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800269BC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800269C0: sb          $a2, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r6;
    // 0x800269C4: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x800269C8: bne         $v0, $zero, L_800269B0
    if (ctx->r2 != 0) {
        // 0x800269CC: nop
    
            goto L_800269B0;
    }
    // 0x800269CC: nop

    // 0x800269D0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800269D4: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x800269D8: bne         $v0, $zero, L_800269AC
    if (ctx->r2 != 0) {
        // 0x800269DC: addiu       $a0, $a0, 0x12
        ctx->r4 = ADD32(ctx->r4, 0X12);
            goto L_800269AC;
    }
    // 0x800269DC: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    // 0x800269E0: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x800269E4: sb          $zero, 0x184($v0)
    MEM_B(0X184, ctx->r2) = 0;
    // 0x800269E8: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x800269EC: sb          $zero, 0x185($v0)
    MEM_B(0X185, ctx->r2) = 0;
    // 0x800269F0: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x800269F4: sb          $zero, 0x186($v0)
    MEM_B(0X186, ctx->r2) = 0;
    // 0x800269F8: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x800269FC: sb          $zero, 0x187($v0)
    MEM_B(0X187, ctx->r2) = 0;
    // 0x80026A00: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026A04: sb          $zero, 0x196($v0)
    MEM_B(0X196, ctx->r2) = 0;
    // 0x80026A08: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026A0C: sb          $zero, 0x1A8($v0)
    MEM_B(0X1A8, ctx->r2) = 0;
    // 0x80026A10: sb          $zero, 0x11E($s1)
    MEM_B(0X11E, ctx->r17) = 0;
    // 0x80026A14: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80026A18: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80026A1C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80026A20: jr          $ra
    // 0x80026A24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80026A24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80026A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026A28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026A2C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80026A30: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80026A34: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80026A38: jal         0x80016AB4
    // 0x80026A3C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x80026A3C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80026A40: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80026A44: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80026A48: addiu       $v1, $v1, 0x7BD0
    ctx->r3 = ADD32(ctx->r3, 0X7BD0);
    // 0x80026A4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80026A50: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
    // 0x80026A54: sb          $zero, 0x3($s1)
    MEM_B(0X3, ctx->r17) = 0;
    // 0x80026A58: sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
    // 0x80026A5C: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x80026A60: sb          $v0, 0x4A($s1)
    MEM_B(0X4A, ctx->r17) = ctx->r2;
    // 0x80026A64: sb          $v0, 0x49($s1)
    MEM_B(0X49, ctx->r17) = ctx->r2;
L_80026A68:
    // 0x80026A68: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80026A6C: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x80026A70: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x80026A74: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80026A78: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80026A7C: slti        $v0, $a0, 0x18
    ctx->r2 = SIGNED(ctx->r4) < 0X18 ? 1 : 0;
    // 0x80026A80: bne         $v0, $zero, L_80026A68
    if (ctx->r2 != 0) {
        // 0x80026A84: addiu       $v1, $v1, 0x68
        ctx->r3 = ADD32(ctx->r3, 0X68);
            goto L_80026A68;
    }
    // 0x80026A84: addiu       $v1, $v1, 0x68
    ctx->r3 = ADD32(ctx->r3, 0X68);
    // 0x80026A88: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80026A8C: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x80026A90: sw          $zero, 0x104($s1)
    MEM_W(0X104, ctx->r17) = 0;
    // 0x80026A94: jal         0x800169C8
    // 0x80026A98: sb          $s0, 0x54($s1)
    MEM_B(0X54, ctx->r17) = ctx->r16;
    func_800169C8(rdram, ctx);
        goto after_1;
    // 0x80026A98: sb          $s0, 0x54($s1)
    MEM_B(0X54, ctx->r17) = ctx->r16;
    after_1:
    // 0x80026A9C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80026AA0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80026AA4: jal         0x80016980
    // 0x80026AA8: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_2;
    // 0x80026AA8: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    after_2:
    // 0x80026AAC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80026AB0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80026AB4: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    // 0x80026AB8: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x80026ABC: sb          $s0, 0x55($s1)
    MEM_B(0X55, ctx->r17) = ctx->r16;
    // 0x80026AC0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80026AC4: sb          $s0, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = ctx->r16;
    // 0x80026AC8: sb          $s0, 0x11C($s1)
    MEM_B(0X11C, ctx->r17) = ctx->r16;
L_80026ACC:
    // 0x80026ACC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80026AD0:
    // 0x80026AD0: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026AD4: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80026AD8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80026ADC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80026AE0: sb          $a2, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r6;
    // 0x80026AE4: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80026AE8: bne         $v0, $zero, L_80026AD0
    if (ctx->r2 != 0) {
        // 0x80026AEC: nop
    
            goto L_80026AD0;
    }
    // 0x80026AEC: nop

    // 0x80026AF0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026AF4: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x80026AF8: bne         $v0, $zero, L_80026ACC
    if (ctx->r2 != 0) {
        // 0x80026AFC: addiu       $a0, $a0, 0x12
        ctx->r4 = ADD32(ctx->r4, 0X12);
            goto L_80026ACC;
    }
    // 0x80026AFC: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    // 0x80026B00: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026B04: sb          $zero, 0x196($v0)
    MEM_B(0X196, ctx->r2) = 0;
    // 0x80026B08: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026B0C: sb          $zero, 0x1A8($v0)
    MEM_B(0X1A8, ctx->r2) = 0;
    // 0x80026B10: sb          $zero, 0x11E($s1)
    MEM_B(0X11E, ctx->r17) = 0;
    // 0x80026B14: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80026B18: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80026B1C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80026B20: jr          $ra
    // 0x80026B24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80026B24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80026B28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026B28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026B2C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80026B30: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80026B34: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80026B38: jal         0x80016AB4
    // 0x80026B3C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x80026B3C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80026B40: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80026B44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80026B48: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x80026B4C: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
    // 0x80026B50: sb          $zero, 0x3($s1)
    MEM_B(0X3, ctx->r17) = 0;
    // 0x80026B54: sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
    // 0x80026B58: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x80026B5C: sb          $v0, 0x4A($s1)
    MEM_B(0X4A, ctx->r17) = ctx->r2;
    // 0x80026B60: sb          $v0, 0x49($s1)
    MEM_B(0X49, ctx->r17) = ctx->r2;
    // 0x80026B64: sw          $zero, 0x104($s1)
    MEM_W(0X104, ctx->r17) = 0;
    // 0x80026B68: jal         0x800169C8
    // 0x80026B6C: sb          $s0, 0x54($s1)
    MEM_B(0X54, ctx->r17) = ctx->r16;
    func_800169C8(rdram, ctx);
        goto after_1;
    // 0x80026B6C: sb          $s0, 0x54($s1)
    MEM_B(0X54, ctx->r17) = ctx->r16;
    after_1:
    // 0x80026B70: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80026B74: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80026B78: jal         0x80016980
    // 0x80026B7C: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_2;
    // 0x80026B7C: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    after_2:
    // 0x80026B80: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80026B84: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80026B88: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    // 0x80026B8C: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x80026B90: sb          $s0, 0x55($s1)
    MEM_B(0X55, ctx->r17) = ctx->r16;
    // 0x80026B94: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80026B98: sb          $s0, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = ctx->r16;
    // 0x80026B9C: sb          $s0, 0x11C($s1)
    MEM_B(0X11C, ctx->r17) = ctx->r16;
L_80026BA0:
    // 0x80026BA0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80026BA4:
    // 0x80026BA4: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026BA8: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80026BAC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80026BB0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80026BB4: sb          $a2, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r6;
    // 0x80026BB8: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80026BBC: bne         $v0, $zero, L_80026BA4
    if (ctx->r2 != 0) {
        // 0x80026BC0: nop
    
            goto L_80026BA4;
    }
    // 0x80026BC0: nop

    // 0x80026BC4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026BC8: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x80026BCC: bne         $v0, $zero, L_80026BA0
    if (ctx->r2 != 0) {
        // 0x80026BD0: addiu       $a0, $a0, 0x12
        ctx->r4 = ADD32(ctx->r4, 0X12);
            goto L_80026BA0;
    }
    // 0x80026BD0: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    // 0x80026BD4: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026BD8: sb          $zero, 0x196($v0)
    MEM_B(0X196, ctx->r2) = 0;
    // 0x80026BDC: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026BE0: sb          $zero, 0x1A8($v0)
    MEM_B(0X1A8, ctx->r2) = 0;
    // 0x80026BE4: sb          $zero, 0x11E($s1)
    MEM_B(0X11E, ctx->r17) = 0;
    // 0x80026BE8: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80026BEC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80026BF0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80026BF4: jr          $ra
    // 0x80026BF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80026BF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80026BFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026BFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026C00: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80026C04: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80026C08: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80026C0C: jal         0x80016AB4
    // 0x80026C10: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x80026C10: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80026C14: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80026C18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80026C1C: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x80026C20: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
    // 0x80026C24: sb          $zero, 0x3($s1)
    MEM_B(0X3, ctx->r17) = 0;
    // 0x80026C28: sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
    // 0x80026C2C: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x80026C30: sb          $v0, 0x4A($s1)
    MEM_B(0X4A, ctx->r17) = ctx->r2;
    // 0x80026C34: sb          $v0, 0x49($s1)
    MEM_B(0X49, ctx->r17) = ctx->r2;
    // 0x80026C38: sw          $zero, 0x104($s1)
    MEM_W(0X104, ctx->r17) = 0;
    // 0x80026C3C: jal         0x800169C8
    // 0x80026C40: sb          $s0, 0x54($s1)
    MEM_B(0X54, ctx->r17) = ctx->r16;
    func_800169C8(rdram, ctx);
        goto after_1;
    // 0x80026C40: sb          $s0, 0x54($s1)
    MEM_B(0X54, ctx->r17) = ctx->r16;
    after_1:
    // 0x80026C44: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80026C48: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80026C4C: jal         0x80016980
    // 0x80026C50: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_2;
    // 0x80026C50: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    after_2:
    // 0x80026C54: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80026C58: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80026C5C: addiu       $a0, $zero, 0xFC
    ctx->r4 = ADD32(0, 0XFC);
    // 0x80026C60: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x80026C64: sb          $s0, 0x55($s1)
    MEM_B(0X55, ctx->r17) = ctx->r16;
    // 0x80026C68: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80026C6C: sb          $s0, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = ctx->r16;
    // 0x80026C70: sb          $s0, 0x11C($s1)
    MEM_B(0X11C, ctx->r17) = ctx->r16;
L_80026C74:
    // 0x80026C74: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80026C78:
    // 0x80026C78: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026C7C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80026C80: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80026C84: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80026C88: sb          $a2, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r6;
    // 0x80026C8C: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80026C90: bne         $v0, $zero, L_80026C78
    if (ctx->r2 != 0) {
        // 0x80026C94: nop
    
            goto L_80026C78;
    }
    // 0x80026C94: nop

    // 0x80026C98: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026C9C: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x80026CA0: bne         $v0, $zero, L_80026C74
    if (ctx->r2 != 0) {
        // 0x80026CA4: addiu       $a0, $a0, 0x12
        ctx->r4 = ADD32(ctx->r4, 0X12);
            goto L_80026C74;
    }
    // 0x80026CA4: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    // 0x80026CA8: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026CAC: sb          $zero, 0x172($v0)
    MEM_B(0X172, ctx->r2) = 0;
    // 0x80026CB0: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026CB4: sb          $zero, 0x173($v0)
    MEM_B(0X173, ctx->r2) = 0;
    // 0x80026CB8: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026CBC: sb          $zero, 0x174($v0)
    MEM_B(0X174, ctx->r2) = 0;
    // 0x80026CC0: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026CC4: sb          $zero, 0x175($v0)
    MEM_B(0X175, ctx->r2) = 0;
    // 0x80026CC8: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026CCC: sb          $zero, 0x186($v0)
    MEM_B(0X186, ctx->r2) = 0;
    // 0x80026CD0: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026CD4: sb          $zero, 0x198($v0)
    MEM_B(0X198, ctx->r2) = 0;
    // 0x80026CD8: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026CDC: sb          $zero, 0x1A8($v0)
    MEM_B(0X1A8, ctx->r2) = 0;
    // 0x80026CE0: sb          $zero, 0x11E($s1)
    MEM_B(0X11E, ctx->r17) = 0;
    // 0x80026CE4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80026CE8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80026CEC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80026CF0: jr          $ra
    // 0x80026CF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80026CF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80026CF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026CF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026CFC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80026D00: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80026D04: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80026D08: jal         0x80016AB4
    // 0x80026D0C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x80026D0C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80026D10: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80026D14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80026D18: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x80026D1C: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
    // 0x80026D20: sb          $zero, 0x3($s1)
    MEM_B(0X3, ctx->r17) = 0;
    // 0x80026D24: sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
    // 0x80026D28: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x80026D2C: sb          $v0, 0x4A($s1)
    MEM_B(0X4A, ctx->r17) = ctx->r2;
    // 0x80026D30: sb          $v0, 0x49($s1)
    MEM_B(0X49, ctx->r17) = ctx->r2;
    // 0x80026D34: sw          $zero, 0x104($s1)
    MEM_W(0X104, ctx->r17) = 0;
    // 0x80026D38: jal         0x800169C8
    // 0x80026D3C: sb          $s0, 0x54($s1)
    MEM_B(0X54, ctx->r17) = ctx->r16;
    func_800169C8(rdram, ctx);
        goto after_1;
    // 0x80026D3C: sb          $s0, 0x54($s1)
    MEM_B(0X54, ctx->r17) = ctx->r16;
    after_1:
    // 0x80026D40: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80026D44: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80026D48: jal         0x80016980
    // 0x80026D4C: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_2;
    // 0x80026D4C: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    after_2:
    // 0x80026D50: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80026D54: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80026D58: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    // 0x80026D5C: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x80026D60: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80026D64: sb          $v0, 0x55($s1)
    MEM_B(0X55, ctx->r17) = ctx->r2;
    // 0x80026D68: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80026D6C: sb          $s0, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = ctx->r16;
    // 0x80026D70: sb          $s0, 0x11C($s1)
    MEM_B(0X11C, ctx->r17) = ctx->r16;
L_80026D74:
    // 0x80026D74: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80026D78:
    // 0x80026D78: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026D7C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80026D80: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80026D84: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80026D88: sb          $a2, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r6;
    // 0x80026D8C: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80026D90: bne         $v0, $zero, L_80026D78
    if (ctx->r2 != 0) {
        // 0x80026D94: nop
    
            goto L_80026D78;
    }
    // 0x80026D94: nop

    // 0x80026D98: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026D9C: slti        $v0, $a1, 0x12
    ctx->r2 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x80026DA0: bne         $v0, $zero, L_80026D74
    if (ctx->r2 != 0) {
        // 0x80026DA4: addiu       $a0, $a0, 0x12
        ctx->r4 = ADD32(ctx->r4, 0X12);
            goto L_80026D74;
    }
    // 0x80026DA4: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    // 0x80026DA8: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026DAC: sb          $zero, 0x192($v0)
    MEM_B(0X192, ctx->r2) = 0;
    // 0x80026DB0: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026DB4: sb          $zero, 0x1A8($v0)
    MEM_B(0X1A8, ctx->r2) = 0;
    // 0x80026DB8: sb          $zero, 0x11E($s1)
    MEM_B(0X11E, ctx->r17) = 0;
    // 0x80026DBC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80026DC0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80026DC4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80026DC8: jr          $ra
    // 0x80026DCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80026DCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80026DD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026DD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026DD4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80026DD8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80026DDC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80026DE0: jal         0x80016AB4
    // 0x80026DE4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x80026DE4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80026DE8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80026DEC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80026DF0: sb          $s0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r16;
    // 0x80026DF4: sb          $zero, 0x3($s1)
    MEM_B(0X3, ctx->r17) = 0;
    // 0x80026DF8: sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
    // 0x80026DFC: sb          $s0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r16;
    // 0x80026E00: sb          $s0, 0x4A($s1)
    MEM_B(0X4A, ctx->r17) = ctx->r16;
    // 0x80026E04: sb          $s0, 0x49($s1)
    MEM_B(0X49, ctx->r17) = ctx->r16;
    // 0x80026E08: sw          $zero, 0x104($s1)
    MEM_W(0X104, ctx->r17) = 0;
    // 0x80026E0C: jal         0x800169C8
    // 0x80026E10: sb          $zero, 0x54($s1)
    MEM_B(0X54, ctx->r17) = 0;
    func_800169C8(rdram, ctx);
        goto after_1;
    // 0x80026E10: sb          $zero, 0x54($s1)
    MEM_B(0X54, ctx->r17) = 0;
    after_1:
    // 0x80026E14: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80026E18: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80026E1C: jal         0x80016980
    // 0x80026E20: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_2;
    // 0x80026E20: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    after_2:
    // 0x80026E24: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80026E28: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x80026E2C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x80026E30: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x80026E34: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80026E38: sb          $v0, 0x55($s1)
    MEM_B(0X55, ctx->r17) = ctx->r2;
    // 0x80026E3C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80026E40: sb          $s0, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = ctx->r16;
    // 0x80026E44: sb          $v0, 0x11C($s1)
    MEM_B(0X11C, ctx->r17) = ctx->r2;
L_80026E48:
    // 0x80026E48: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80026E4C: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_80026E50:
    // 0x80026E50: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026E54: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80026E58: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80026E5C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80026E60: sb          $a3, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r7;
    // 0x80026E64: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80026E68: bne         $v0, $zero, L_80026E50
    if (ctx->r2 != 0) {
        // 0x80026E6C: nop
    
            goto L_80026E50;
    }
    // 0x80026E6C: nop

    // 0x80026E70: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80026E74: slti        $v0, $a2, 0x12
    ctx->r2 = SIGNED(ctx->r6) < 0X12 ? 1 : 0;
    // 0x80026E78: bne         $v0, $zero, L_80026E48
    if (ctx->r2 != 0) {
        // 0x80026E7C: addiu       $a1, $a1, 0x12
        ctx->r5 = ADD32(ctx->r5, 0X12);
            goto L_80026E48;
    }
    // 0x80026E7C: addiu       $a1, $a1, 0x12
    ctx->r5 = ADD32(ctx->r5, 0X12);
    // 0x80026E80: jal         0x80016F44
    // 0x80026E84: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80016F44(rdram, ctx);
        goto after_3;
    // 0x80026E84: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
    // 0x80026E88: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026E8C: sb          $zero, 0xD1($v0)
    MEM_B(0XD1, ctx->r2) = 0;
    // 0x80026E90: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026E94: sb          $zero, 0xDF($v0)
    MEM_B(0XDF, ctx->r2) = 0;
    // 0x80026E98: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026E9C: sb          $zero, 0xF3($v0)
    MEM_B(0XF3, ctx->r2) = 0;
    // 0x80026EA0: lw          $v0, 0x110($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X110);
    // 0x80026EA4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80026EA8: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x80026EAC: sb          $zero, 0x101($v0)
    MEM_B(0X101, ctx->r2) = 0;
L_80026EB0:
    // 0x80026EB0: subu        $v0, $a2, $a1
    ctx->r2 = SUB32(ctx->r6, ctx->r5);
    // 0x80026EB4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80026EB8: lw          $a0, 0x110($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X110);
    // 0x80026EBC: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80026EC0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80026EC4: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80026EC8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80026ECC: bgtz        $a1, L_80026EB0
    if (SIGNED(ctx->r5) > 0) {
        // 0x80026ED0: sb          $zero, 0xD($v1)
        MEM_B(0XD, ctx->r3) = 0;
            goto L_80026EB0;
    }
    // 0x80026ED0: sb          $zero, 0xD($v1)
    MEM_B(0XD, ctx->r3) = 0;
    // 0x80026ED4: lbu         $v1, 0x74($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X74);
    // 0x80026ED8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80026EDC: addiu       $a1, $a1, -0x3998
    ctx->r5 = ADD32(ctx->r5, -0X3998);
    // 0x80026EE0: lbu         $a0, 0x64($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X64);
    // 0x80026EE4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80026EE8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80026EEC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80026EF0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80026EF4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80026EF8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80026EFC: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80026F00: lw          $v1, 0xD0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0XD0);
    // 0x80026F04: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x80026F08: sb          $v0, 0x63($s1)
    MEM_B(0X63, ctx->r17) = ctx->r2;
    // 0x80026F0C: sb          $zero, 0xCD($v1)
    MEM_B(0XCD, ctx->r3) = 0;
    // 0x80026F10: sb          $zero, 0xCC($v1)
    MEM_B(0XCC, ctx->r3) = 0;
    // 0x80026F14: sb          $zero, 0x11E($s1)
    MEM_B(0X11E, ctx->r17) = 0;
    // 0x80026F18: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80026F1C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80026F20: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80026F24: jr          $ra
    // 0x80026F28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80026F28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80026F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026F2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80026F30: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80026F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026F38: jal         0x80016AB4
    // 0x80026F3C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_80016AB4(rdram, ctx);
        goto after_0;
    // 0x80026F3C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x80026F40: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80026F44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80026F48: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x80026F4C: sb          $v0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r2;
    // 0x80026F50: sb          $v0, 0x49($s0)
    MEM_B(0X49, ctx->r16) = ctx->r2;
    // 0x80026F54: sb          $v0, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = ctx->r2;
    // 0x80026F58: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80026F5C: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x80026F60: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x80026F64: sw          $zero, 0x104($s0)
    MEM_W(0X104, ctx->r16) = 0;
    // 0x80026F68: jal         0x800169C8
    // 0x80026F6C: sb          $v0, 0x54($s0)
    MEM_B(0X54, ctx->r16) = ctx->r2;
    func_800169C8(rdram, ctx);
        goto after_1;
    // 0x80026F6C: sb          $v0, 0x54($s0)
    MEM_B(0X54, ctx->r16) = ctx->r2;
    after_1:
    // 0x80026F70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80026F74: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80026F78: jal         0x80016980
    // 0x80026F7C: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    func_80016980(rdram, ctx);
        goto after_2;
    // 0x80026F7C: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    after_2:
    // 0x80026F80: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80026F84: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80026F88: addiu       $v1, $v1, 0x7BD0
    ctx->r3 = ADD32(ctx->r3, 0X7BD0);
    // 0x80026F8C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80026F90: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x80026F94: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80026F98: sb          $v0, 0x55($s0)
    MEM_B(0X55, ctx->r16) = ctx->r2;
    // 0x80026F9C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80026FA0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80026FA4: sb          $v0, 0x7B7C($at)
    MEM_B(0X7B7C, ctx->r1) = ctx->r2;
L_80026FA8:
    // 0x80026FA8: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80026FAC: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x80026FB0: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x80026FB4: addiu       $v1, $v1, 0x68
    ctx->r3 = ADD32(ctx->r3, 0X68);
    // 0x80026FB8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80026FBC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80026FC0: sb          $zero, 0x7BD0($at)
    MEM_B(0X7BD0, ctx->r1) = 0;
    // 0x80026FC4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80026FC8: slti        $v0, $a1, 0x18
    ctx->r2 = SIGNED(ctx->r5) < 0X18 ? 1 : 0;
    // 0x80026FCC: bne         $v0, $zero, L_80026FA8
    if (ctx->r2 != 0) {
        // 0x80026FD0: addiu       $a0, $a0, 0x68
        ctx->r4 = ADD32(ctx->r4, 0X68);
            goto L_80026FA8;
    }
    // 0x80026FD0: addiu       $a0, $a0, 0x68
    ctx->r4 = ADD32(ctx->r4, 0X68);
    // 0x80026FD4: jal         0x8001FA88
    // 0x80026FD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001FA88(rdram, ctx);
        goto after_3;
    // 0x80026FD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80026FDC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80026FE0: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x80026FE4: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
L_80026FE8:
    // 0x80026FE8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80026FEC: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_80026FF0:
    // 0x80026FF0: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
    // 0x80026FF4: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80026FF8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80026FFC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80027000: sb          $a3, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r7;
    // 0x80027004: slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80027008: bne         $v0, $zero, L_80026FF0
    if (ctx->r2 != 0) {
        // 0x8002700C: nop
    
            goto L_80026FF0;
    }
    // 0x8002700C: nop

    // 0x80027010: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80027014: slti        $v0, $a2, 0x12
    ctx->r2 = SIGNED(ctx->r6) < 0X12 ? 1 : 0;
    // 0x80027018: bne         $v0, $zero, L_80026FE8
    if (ctx->r2 != 0) {
        // 0x8002701C: addiu       $a1, $a1, 0x12
        ctx->r5 = ADD32(ctx->r5, 0X12);
            goto L_80026FE8;
    }
    // 0x8002701C: addiu       $a1, $a1, 0x12
    ctx->r5 = ADD32(ctx->r5, 0X12);
    // 0x80027020: jal         0x80016F44
    // 0x80027024: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80016F44(rdram, ctx);
        goto after_4;
    // 0x80027024: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x80027028: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
    // 0x8002702C: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
    // 0x80027030: sb          $v1, 0xA6($v0)
    MEM_B(0XA6, ctx->r2) = ctx->r3;
    // 0x80027034: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
    // 0x80027038: sb          $v1, 0x94($v0)
    MEM_B(0X94, ctx->r2) = ctx->r3;
    // 0x8002703C: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
    // 0x80027040: sb          $v1, 0x82($v0)
    MEM_B(0X82, ctx->r2) = ctx->r3;
    // 0x80027044: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
    // 0x80027048: sb          $v1, 0xA7($v0)
    MEM_B(0XA7, ctx->r2) = ctx->r3;
    // 0x8002704C: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
    // 0x80027050: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80027054: addiu       $a0, $zero, 0x132
    ctx->r4 = ADD32(0, 0X132);
    // 0x80027058: sb          $v1, 0x95($v0)
    MEM_B(0X95, ctx->r2) = ctx->r3;
L_8002705C:
    // 0x8002705C: lw          $v0, 0x110($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X110);
    // 0x80027060: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80027064: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80027068: sb          $zero, 0x79($v0)
    MEM_B(0X79, ctx->r2) = 0;
    // 0x8002706C: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80027070: beq         $v0, $zero, L_8002705C
    if (ctx->r2 == 0) {
        // 0x80027074: addiu       $a0, $a0, -0x12
        ctx->r4 = ADD32(ctx->r4, -0X12);
            goto L_8002705C;
    }
    // 0x80027074: addiu       $a0, $a0, -0x12
    ctx->r4 = ADD32(ctx->r4, -0X12);
    // 0x80027078: sb          $zero, 0x11E($s0)
    MEM_B(0X11E, ctx->r16) = 0;
    // 0x8002707C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80027080: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80027084: jr          $ra
    // 0x80027088: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80027088: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002708C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002708C: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x80027090: sb          $v0, 0x127($a0)
    MEM_B(0X127, ctx->r4) = ctx->r2;
    // 0x80027094: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x80027098: sb          $v0, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = ctx->r2;
    // 0x8002709C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800270A0: sb          $zero, 0x49($a0)
    MEM_B(0X49, ctx->r4) = 0;
    // 0x800270A4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800270A8: jr          $ra
    // 0x800270AC: sb          $v0, 0x7B7D($at)
    MEM_B(0X7B7D, ctx->r1) = ctx->r2;
    return;
    // 0x800270AC: sb          $v0, 0x7B7D($at)
    MEM_B(0X7B7D, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_800270B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800270B0: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x800270B4: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x800270B8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800270BC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x800270C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800270C4: sw          $v0, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r2;
L_800270C8:
    // 0x800270C8: lw          $v1, 0xB0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XB0);
    // 0x800270CC: lb          $a0, 0x127($a2)
    ctx->r4 = MEM_B(ctx->r6, 0X127);
    // 0x800270D0: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x800270D4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800270D8: sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4 << 3);
    // 0x800270DC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800270E0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800270E4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800270E8: slti        $v0, $a1, 0xA
    ctx->r2 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    // 0x800270EC: bne         $v0, $zero, L_800270C8
    if (ctx->r2 != 0) {
        // 0x800270F0: sb          $a3, 0x70($v1)
        MEM_B(0X70, ctx->r3) = ctx->r7;
            goto L_800270C8;
    }
    // 0x800270F0: sb          $a3, 0x70($v1)
    MEM_B(0X70, ctx->r3) = ctx->r7;
    // 0x800270F4: lbu         $v0, 0x127($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X127);
    // 0x800270F8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800270FC: sb          $v0, 0x127($a2)
    MEM_B(0X127, ctx->r6) = ctx->r2;
    // 0x80027100: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80027104: bltzl       $v0, L_8002710C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80027108: sb          $zero, 0x11E($a2)
        MEM_B(0X11E, ctx->r6) = 0;
            goto L_8002710C;
    }
    goto skip_0;
    // 0x80027108: sb          $zero, 0x11E($a2)
    MEM_B(0X11E, ctx->r6) = 0;
    skip_0:
L_8002710C:
    // 0x8002710C: jr          $ra
    // 0x80027110: nop

    return;
    // 0x80027110: nop

;}
RECOMP_FUNC void func_80027114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027114: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x80027118: sb          $v0, 0x127($a0)
    MEM_B(0X127, ctx->r4) = ctx->r2;
    // 0x8002711C: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // 0x80027120: jr          $ra
    // 0x80027124: sb          $v0, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = ctx->r2;
    return;
    // 0x80027124: sb          $v0, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_80027128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027128: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x8002712C: lw          $v0, 0x2C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X2C);
    // 0x80027130: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80027134: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80027138: sw          $v0, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r2;
L_8002713C:
    // 0x8002713C: lw          $a0, 0xB0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XB0);
    // 0x80027140: lb          $a1, 0x127($a3)
    ctx->r5 = MEM_B(ctx->r7, 0X127);
    // 0x80027144: lw          $v0, 0x110($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X110);
    // 0x80027148: addu        $a0, $a2, $a0
    ctx->r4 = ADD32(ctx->r6, ctx->r4);
    // 0x8002714C: sll         $v1, $a1, 3
    ctx->r3 = S32(ctx->r5 << 3);
    // 0x80027150: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80027154: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80027158: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x8002715C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80027160: lbu         $v0, 0x70($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X70);
    // 0x80027164: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80027168: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8002716C: sb          $v0, 0x70($a0)
    MEM_B(0X70, ctx->r4) = ctx->r2;
    // 0x80027170: slti        $v0, $a2, 0xA
    ctx->r2 = SIGNED(ctx->r6) < 0XA ? 1 : 0;
    // 0x80027174: bne         $v0, $zero, L_8002713C
    if (ctx->r2 != 0) {
        // 0x80027178: nop
    
            goto L_8002713C;
    }
    // 0x80027178: nop

    // 0x8002717C: lbu         $v0, 0x127($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X127);
    // 0x80027180: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80027184: sb          $v0, 0x127($a3)
    MEM_B(0X127, ctx->r7) = ctx->r2;
    // 0x80027188: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8002718C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80027190: slti        $v0, $v0, -0x6
    ctx->r2 = SIGNED(ctx->r2) < -0X6 ? 1 : 0;
    // 0x80027194: beq         $v0, $zero, L_800271A8
    if (ctx->r2 == 0) {
        // 0x80027198: nop
    
            goto L_800271A8;
    }
    // 0x80027198: nop

    // 0x8002719C: sb          $zero, 0x11E($a3)
    MEM_B(0X11E, ctx->r7) = 0;
    // 0x800271A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800271A4: sb          $zero, 0x7B7D($at)
    MEM_B(0X7B7D, ctx->r1) = 0;
L_800271A8:
    // 0x800271A8: jr          $ra
    // 0x800271AC: nop

    return;
    // 0x800271AC: nop

;}
RECOMP_FUNC void func_800271B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800271B0: sb          $zero, 0x4A($a0)
    MEM_B(0X4A, ctx->r4) = 0;
    // 0x800271B4: sb          $zero, 0x49($a0)
    MEM_B(0X49, ctx->r4) = 0;
    // 0x800271B8: jr          $ra
    // 0x800271BC: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    return;
    // 0x800271BC: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
;}
RECOMP_FUNC void func_800271C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800271C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800271C4: sb          $v0, 0x4A($a0)
    MEM_B(0X4A, ctx->r4) = ctx->r2;
    // 0x800271C8: sb          $v0, 0x49($a0)
    MEM_B(0X49, ctx->r4) = ctx->r2;
    // 0x800271CC: jr          $ra
    // 0x800271D0: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    return;
    // 0x800271D0: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
;}
RECOMP_FUNC void func_800271D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800271D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800271D8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800271DC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800271E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800271E4: jal         0x8001D520
    // 0x800271E8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8001D520(rdram, ctx);
        goto after_0;
    // 0x800271E8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // 0x800271EC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800271F0: beq         $v1, $zero, L_8002720C
    if (ctx->r3 == 0) {
        // 0x800271F4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002720C;
    }
    // 0x800271F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800271F8: sb          $v0, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r2;
    // 0x800271FC: addiu       $v0, $zero, 0x26
    ctx->r2 = ADD32(0, 0X26);
    // 0x80027200: sb          $v0, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r2;
    // 0x80027204: lb          $v0, 0x124($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X124);
    // 0x80027208: sw          $v0, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r2;
L_8002720C:
    // 0x8002720C: lb          $v0, 0x125($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X125);
    // 0x80027210: bne         $v0, $zero, L_8002721C
    if (ctx->r2 != 0) {
        // 0x80027214: addiu       $v0, $zero, 0x1F
        ctx->r2 = ADD32(0, 0X1F);
            goto L_8002721C;
    }
    // 0x80027214: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    // 0x80027218: sb          $v0, 0x11E($s0)
    MEM_B(0X11E, ctx->r16) = ctx->r2;
L_8002721C:
    // 0x8002721C: lb          $v1, 0x125($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X125);
    // 0x80027220: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80027224: bne         $v1, $v0, L_8002723C
    if (ctx->r3 != ctx->r2) {
        // 0x80027228: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8002723C;
    }
    // 0x80027228: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8002722C: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x80027230: sb          $v0, 0x11E($s0)
    MEM_B(0X11E, ctx->r16) = ctx->r2;
    // 0x80027234: lb          $v1, 0x125($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X125);
    // 0x80027238: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8002723C:
    // 0x8002723C: beql        $v1, $v0, L_80027244
    if (ctx->r3 == ctx->r2) {
        // 0x80027240: sb          $zero, 0x11E($s0)
        MEM_B(0X11E, ctx->r16) = 0;
            goto L_80027244;
    }
    goto skip_0;
    // 0x80027240: sb          $zero, 0x11E($s0)
    MEM_B(0X11E, ctx->r16) = 0;
    skip_0:
L_80027244:
    // 0x80027244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80027248: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002724C: jr          $ra
    // 0x80027250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80027250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80027254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027254: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x80027258: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002725C: sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
    // 0x80027260: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80027264: lbu         $v0, 0x7B88($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B88);
    // 0x80027268: beql        $v0, $zero, L_80027270
    if (ctx->r2 == 0) {
        // 0x8002726C: sb          $zero, 0x11E($a0)
        MEM_B(0X11E, ctx->r4) = 0;
            goto L_80027270;
    }
    goto skip_0;
    // 0x8002726C: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    skip_0:
L_80027270:
    // 0x80027270: jr          $ra
    // 0x80027274: nop

    return;
    // 0x80027274: nop

;}
RECOMP_FUNC void func_80027278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027278: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x8002727C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80027280: sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
    // 0x80027284: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80027288: lbu         $v1, 0x7B88($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B88);
    // 0x8002728C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80027290: beql        $v1, $v0, L_80027298
    if (ctx->r3 == ctx->r2) {
        // 0x80027294: sb          $zero, 0x11E($a0)
        MEM_B(0X11E, ctx->r4) = 0;
            goto L_80027298;
    }
    goto skip_0;
    // 0x80027294: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    skip_0:
L_80027298:
    // 0x80027298: jr          $ra
    // 0x8002729C: nop

    return;
    // 0x8002729C: nop

;}
RECOMP_FUNC void func_800272A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800272A0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800272A4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800272A8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800272AC: addiu       $v1, $v1, 0x7BD0
    ctx->r3 = ADD32(ctx->r3, 0X7BD0);
L_800272B0:
    // 0x800272B0: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x800272B4: beql        $v0, $zero, L_800272C4
    if (ctx->r2 == 0) {
        // 0x800272B8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800272C4;
    }
    goto skip_0;
    // 0x800272B8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x800272BC: j           L_800272D0
    // 0x800272C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_800272D0;
    // 0x800272C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800272C4:
    // 0x800272C4: slti        $v0, $a1, 0x18
    ctx->r2 = SIGNED(ctx->r5) < 0X18 ? 1 : 0;
    // 0x800272C8: bne         $v0, $zero, L_800272B0
    if (ctx->r2 != 0) {
        // 0x800272CC: addiu       $v1, $v1, 0x68
        ctx->r3 = ADD32(ctx->r3, 0X68);
            goto L_800272B0;
    }
    // 0x800272CC: addiu       $v1, $v1, 0x68
    ctx->r3 = ADD32(ctx->r3, 0X68);
L_800272D0:
    // 0x800272D0: beql        $a2, $zero, L_800272D8
    if (ctx->r6 == 0) {
        // 0x800272D4: sb          $zero, 0x11E($a0)
        MEM_B(0X11E, ctx->r4) = 0;
            goto L_800272D8;
    }
    goto skip_1;
    // 0x800272D4: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    skip_1:
L_800272D8:
    // 0x800272D8: jr          $ra
    // 0x800272DC: nop

    return;
    // 0x800272DC: nop

;}
RECOMP_FUNC void func_800272E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800272E0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800272E4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800272E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800272EC: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    // 0x800272F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800272F4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800272F8: addiu       $v1, $v1, 0x7BD0
    ctx->r3 = ADD32(ctx->r3, 0X7BD0);
    // 0x800272FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80027300: sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
L_80027304:
    // 0x80027304: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80027308: beql        $v0, $zero, L_80027348
    if (ctx->r2 == 0) {
        // 0x8002730C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80027348;
    }
    goto skip_0;
    // 0x8002730C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x80027310: lw          $v0, 0x34($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X34);
    // 0x80027314: bnel        $v0, $a0, L_80027348
    if (ctx->r2 != ctx->r4) {
        // 0x80027318: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80027348;
    }
    goto skip_1;
    // 0x80027318: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_1:
    // 0x8002731C: lwc1        $f0, 0x14($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80027320: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80027324: nop

    // 0x80027328: nop

    // 0x8002732C: bc1fl       L_80027348
    if (!c1cs) {
        // 0x80027330: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80027348;
    }
    goto skip_2;
    // 0x80027330: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_2:
    // 0x80027334: lb          $v0, 0x5($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X5);
    // 0x80027338: beql        $v0, $a2, L_80027348
    if (ctx->r2 == ctx->r6) {
        // 0x8002733C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80027348;
    }
    goto skip_3;
    // 0x8002733C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_3:
    // 0x80027340: j           L_80027354
    // 0x80027344: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
        goto L_80027354;
    // 0x80027344: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
L_80027348:
    // 0x80027348: slti        $v0, $a1, 0x18
    ctx->r2 = SIGNED(ctx->r5) < 0X18 ? 1 : 0;
    // 0x8002734C: bne         $v0, $zero, L_80027304
    if (ctx->r2 != 0) {
        // 0x80027350: addiu       $v1, $v1, 0x68
        ctx->r3 = ADD32(ctx->r3, 0X68);
            goto L_80027304;
    }
    // 0x80027350: addiu       $v1, $v1, 0x68
    ctx->r3 = ADD32(ctx->r3, 0X68);
L_80027354:
    // 0x80027354: jr          $ra
    // 0x80027358: nop

    return;
    // 0x80027358: nop

;}
RECOMP_FUNC void func_8002735C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002735C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80027360: addiu       $v1, $v1, 0x7BA6
    ctx->r3 = ADD32(ctx->r3, 0X7BA6);
    // 0x80027364: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80027368: addiu       $v0, $v0, 0x3C
    ctx->r2 = ADD32(ctx->r2, 0X3C);
    // 0x8002736C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x80027370: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80027374: sltiu       $v0, $v0, 0x3C
    ctx->r2 = ctx->r2 < 0X3C ? 1 : 0;
    // 0x80027378: bne         $v0, $zero, L_800273C8
    if (ctx->r2 != 0) {
        // 0x8002737C: nop
    
            goto L_800273C8;
    }
    // 0x8002737C: nop

    // 0x80027380: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80027384: lbu         $v0, 0x7BA7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7BA7);
    // 0x80027388: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8002738C: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x80027390: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80027394: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80027398: sb          $v0, 0x7BA7($at)
    MEM_B(0X7BA7, ctx->r1) = ctx->r2;
    // 0x8002739C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800273A0: bne         $v0, $v1, L_800273C8
    if (ctx->r2 != ctx->r3) {
        // 0x800273A4: nop
    
            goto L_800273C8;
    }
    // 0x800273A4: nop

    // 0x800273A8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800273AC: lbu         $v0, 0x7BA8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7BA8);
    // 0x800273B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800273B4: sb          $zero, 0x7BA7($at)
    MEM_B(0X7BA7, ctx->r1) = 0;
    // 0x800273B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800273BC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x800273C0: sb          $v0, 0x7BA8($at)
    MEM_B(0X7BA8, ctx->r1) = ctx->r2;
    // 0x800273C4: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
L_800273C8:
    // 0x800273C8: jr          $ra
    // 0x800273CC: nop

    return;
    // 0x800273CC: nop

;}
RECOMP_FUNC void func_800273D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800273D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800273D4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800273D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800273DC: jal         0x80012D8C
    // 0x800273E0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_80012D8C(rdram, ctx);
        goto after_0;
    // 0x800273E0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x800273E4: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800273E8: beq         $a1, $zero, L_800274A0
    if (ctx->r5 == 0) {
        // 0x800273EC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800274A0;
    }
    // 0x800273EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800273F0: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800273F4: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // 0x800273F8: sb          $v0, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r2;
    // 0x800273FC: lbu         $v0, 0x124($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X124);
    // 0x80027400: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80027404: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80027408: nop

    // 0x8002740C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80027410: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x80027414: lbu         $v0, 0x125($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X125);
    // 0x80027418: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002741C: sw          $v1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r3;
    // 0x80027420: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80027424: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80027428: nop

    // 0x8002742C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80027430: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x80027434: lbu         $v0, 0x127($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X127);
    // 0x80027438: lui         $a0, 0xB60B
    ctx->r4 = S32(0XB60B << 16);
    // 0x8002743C: ori         $a0, $a0, 0x60B7
    ctx->r4 = ctx->r4 | 0X60B7;
    // 0x80027440: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80027444: sll         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2 << 17);
    // 0x80027448: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8002744C: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80027450: mfhi        $a2
    ctx->r6 = hi;
    // 0x80027454: addu        $v1, $a2, $v0
    ctx->r3 = ADD32(ctx->r6, ctx->r2);
    // 0x80027458: sra         $v1, $v1, 8
    ctx->r3 = S32(SIGNED(ctx->r3) >> 8);
    // 0x8002745C: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80027460: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80027464: sw          $v1, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r3;
    // 0x80027468: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002746C: lbu         $v0, 0x7B9B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9B);
    // 0x80027470: beq         $v0, $zero, L_80027494
    if (ctx->r2 == 0) {
        // 0x80027474: nop
    
            goto L_80027494;
    }
    // 0x80027474: nop

    // 0x80027478: lwc1        $f2, 0xC($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8002747C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80027480: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80027484: nop

    // 0x80027488: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8002748C: sw          $zero, 0x18($a1)
    MEM_W(0X18, ctx->r5) = 0;
    // 0x80027490: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
L_80027494:
    // 0x80027494: lbu         $v0, 0x126($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X126);
    // 0x80027498: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8002749C: sw          $v0, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r2;
L_800274A0:
    // 0x800274A0: sb          $zero, 0x11E($s0)
    MEM_B(0X11E, ctx->r16) = 0;
    // 0x800274A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800274A8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800274AC: jr          $ra
    // 0x800274B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800274B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800274B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800274B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800274B8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800274BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800274C0: jal         0x80012D8C
    // 0x800274C4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    func_80012D8C(rdram, ctx);
        goto after_0;
    // 0x800274C4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x800274C8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800274CC: beq         $a1, $zero, L_8002758C
    if (ctx->r5 == 0) {
        // 0x800274D0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8002758C;
    }
    // 0x800274D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800274D4: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800274D8: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // 0x800274DC: sb          $v0, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r2;
    // 0x800274E0: lbu         $v0, 0x124($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X124);
    // 0x800274E4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800274E8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800274EC: nop

    // 0x800274F0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800274F4: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x800274F8: lbu         $v0, 0x125($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X125);
    // 0x800274FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80027500: sw          $v1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r3;
    // 0x80027504: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80027508: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8002750C: nop

    // 0x80027510: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80027514: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x80027518: lbu         $v0, 0x127($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X127);
    // 0x8002751C: lui         $a0, 0xB60B
    ctx->r4 = S32(0XB60B << 16);
    // 0x80027520: ori         $a0, $a0, 0x60B7
    ctx->r4 = ctx->r4 | 0X60B7;
    // 0x80027524: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80027528: sll         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2 << 17);
    // 0x8002752C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80027530: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80027534: mfhi        $a2
    ctx->r6 = hi;
    // 0x80027538: addu        $v1, $a2, $v0
    ctx->r3 = ADD32(ctx->r6, ctx->r2);
    // 0x8002753C: sra         $v1, $v1, 8
    ctx->r3 = S32(SIGNED(ctx->r3) >> 8);
    // 0x80027540: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x80027544: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80027548: sw          $v1, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r3;
    // 0x8002754C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80027550: lbu         $v0, 0x7B9B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9B);
    // 0x80027554: beq         $v0, $zero, L_80027580
    if (ctx->r2 == 0) {
        // 0x80027558: nop
    
            goto L_80027580;
    }
    // 0x80027558: nop

    // 0x8002755C: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80027560: lui         $at, 0x432A
    ctx->r1 = S32(0X432A << 16);
    // 0x80027564: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80027568: lw          $v0, 0x1C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1C);
    // 0x8002756C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80027570: sw          $zero, 0x18($a1)
    MEM_W(0X18, ctx->r5) = 0;
    // 0x80027574: addiu       $v0, $v0, 0x7FFF
    ctx->r2 = ADD32(ctx->r2, 0X7FFF);
    // 0x80027578: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    // 0x8002757C: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
L_80027580:
    // 0x80027580: lbu         $v0, 0x126($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X126);
    // 0x80027584: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80027588: sw          $v0, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r2;
L_8002758C:
    // 0x8002758C: sb          $zero, 0x11E($s0)
    MEM_B(0X11E, ctx->r16) = 0;
    // 0x80027590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80027594: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80027598: jr          $ra
    // 0x8002759C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8002759C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800275A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800275A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800275A4: sb          $v0, 0x128($a0)
    MEM_B(0X128, ctx->r4) = ctx->r2;
    // 0x800275A8: jr          $ra
    // 0x800275AC: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    return;
    // 0x800275AC: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
;}
RECOMP_FUNC void func_800275B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800275B0: sb          $zero, 0x128($a0)
    MEM_B(0X128, ctx->r4) = 0;
    // 0x800275B4: jr          $ra
    // 0x800275B8: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    return;
    // 0x800275B8: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
;}
RECOMP_FUNC void func_800275BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800275BC: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x800275C0: blezl       $v0, L_800275C8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800275C4: sb          $zero, 0x11E($a0)
        MEM_B(0X11E, ctx->r4) = 0;
            goto L_800275C8;
    }
    goto skip_0;
    // 0x800275C4: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    skip_0:
L_800275C8:
    // 0x800275C8: jr          $ra
    // 0x800275CC: nop

    return;
    // 0x800275CC: nop

;}
RECOMP_FUNC void func_800275D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800275D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800275D4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800275D8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800275DC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800275E0: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800275E4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800275E8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800275EC: jal         0x8001F45C
    // 0x800275F0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_8001F45C(rdram, ctx);
        goto after_0;
    // 0x800275F0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x800275F4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800275F8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800275FC: addiu       $s2, $zero, 0x27
    ctx->r18 = ADD32(0, 0X27);
    // 0x80027600: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80027604: sh          $zero, 0x558C($at)
    MEM_H(0X558C, ctx->r1) = 0;
L_80027608:
    // 0x80027608: jal         0x8001D520
    // 0x8002760C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8001D520(rdram, ctx);
        goto after_1;
    // 0x8002760C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // 0x80027610: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80027614: beql        $v1, $zero, L_80027658
    if (ctx->r3 == 0) {
        // 0x80027618: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80027658;
    }
    goto skip_0;
    // 0x80027618: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8002761C: sb          $s3, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r19;
    // 0x80027620: sb          $s2, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r18;
    // 0x80027624: sw          $s0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r16;
    // 0x80027628: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8002762C: lbu         $v0, 0x7B9B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B9B);
    // 0x80027630: beq         $v0, $zero, L_8002764C
    if (ctx->r2 == 0) {
        // 0x80027634: nop
    
            goto L_8002764C;
    }
    // 0x80027634: nop

    // 0x80027638: lbu         $v0, 0x124($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X124);
    // 0x8002763C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80027640: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80027644: j           L_80027650
    // 0x80027648: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
        goto L_80027650;
    // 0x80027648: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
L_8002764C:
    // 0x8002764C: lb          $v0, 0x124($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X124);
L_80027650:
    // 0x80027650: sw          $v0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r2;
    // 0x80027654: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80027658:
    // 0x80027658: slti        $v0, $s0, 0x5
    ctx->r2 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x8002765C: bne         $v0, $zero, L_80027608
    if (ctx->r2 != 0) {
        // 0x80027660: nop
    
            goto L_80027608;
    }
    // 0x80027660: nop

    // 0x80027664: sb          $zero, 0x11E($s1)
    MEM_B(0X11E, ctx->r17) = 0;
    // 0x80027668: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8002766C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80027670: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80027674: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80027678: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8002767C: jr          $ra
    // 0x80027680: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80027680: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80027684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027684: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80027688: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8002768C: sh          $v0, 0x558C($at)
    MEM_H(0X558C, ctx->r1) = ctx->r2;
    // 0x80027690: jr          $ra
    // 0x80027694: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
    return;
    // 0x80027694: sb          $zero, 0x11E($a0)
    MEM_B(0X11E, ctx->r4) = 0;
;}
