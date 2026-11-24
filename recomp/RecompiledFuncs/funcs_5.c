#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80017BF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017BF4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80017BF8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80017BFC: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80017C00: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80017C04: lui         $s6, 0x801D
    ctx->r22 = S32(0X801D << 16);
    // 0x80017C08: addiu       $s6, $s6, 0x7B86
    ctx->r22 = ADD32(ctx->r22, 0X7B86);
    // 0x80017C0C: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80017C10: lui         $s5, 0x8008
    ctx->r21 = S32(0X8008 << 16);
    // 0x80017C14: addiu       $s5, $s5, -0x6428
    ctx->r21 = ADD32(ctx->r21, -0X6428);
    // 0x80017C18: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x80017C1C: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x80017C20: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80017C24: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80017C28: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80017C2C: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x80017C30: addiu       $s1, $s1, 0x3520
    ctx->r17 = ADD32(ctx->r17, 0X3520);
    // 0x80017C34: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80017C38: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80017C3C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80017C40: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x80017C44: addiu       $s3, $s3, 0x6AA0
    ctx->r19 = ADD32(ctx->r19, 0X6AA0);
    // 0x80017C48: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
L_80017C4C:
    // 0x80017C4C: lbu         $v0, 0x0($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X0);
    // 0x80017C50: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80017C54: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x80017C58: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80017C5C: sll         $v1, $s2, 3
    ctx->r3 = S32(ctx->r18 << 3);
    // 0x80017C60: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80017C64: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80017C68: bnel        $v0, $s7, L_80017C88
    if (ctx->r2 != ctx->r23) {
        // 0x80017C6C: sb          $s4, 0x28($s1)
        MEM_B(0X28, ctx->r17) = ctx->r20;
            goto L_80017C88;
    }
    goto skip_0;
    // 0x80017C6C: sb          $s4, 0x28($s1)
    MEM_B(0X28, ctx->r17) = ctx->r20;
    skip_0:
    // 0x80017C70: jal         0x8001D564
    // 0x80017C74: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_8001D564(rdram, ctx);
        goto after_0;
    // 0x80017C74: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_0:
    // 0x80017C78: jal         0x8001D564
    // 0x80017C7C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001D564(rdram, ctx);
        goto after_1;
    // 0x80017C7C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x80017C80: j           L_80017CF8
    // 0x80017C84: addiu       $s1, $s1, 0x70
    ctx->r17 = ADD32(ctx->r17, 0X70);
        goto L_80017CF8;
    // 0x80017C84: addiu       $s1, $s1, 0x70
    ctx->r17 = ADD32(ctx->r17, 0X70);
L_80017C88:
    // 0x80017C88: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80017C8C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80017C90: sb          $s4, 0x6AC8($at)
    MEM_B(0X6AC8, ctx->r1) = ctx->r20;
    // 0x80017C94: lbu         $v0, 0x0($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X0);
    // 0x80017C98: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80017C9C: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x80017CA0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80017CA4: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80017CA8: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80017CAC: sb          $v0, 0x29($s1)
    MEM_B(0X29, ctx->r17) = ctx->r2;
    // 0x80017CB0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80017CB4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80017CB8: sb          $v0, 0x6AC9($at)
    MEM_B(0X6AC9, ctx->r1) = ctx->r2;
    // 0x80017CBC: sb          $zero, 0x2B($s1)
    MEM_B(0X2B, ctx->r17) = 0;
    // 0x80017CC0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80017CC4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80017CC8: sb          $zero, 0x6ACB($at)
    MEM_B(0X6ACB, ctx->r1) = 0;
    // 0x80017CCC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80017CD0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80017CD4: sw          $zero, 0x6AE4($at)
    MEM_W(0X6AE4, ctx->r1) = 0;
    // 0x80017CD8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80017CDC: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80017CE0: sw          $s4, 0x3564($at)
    MEM_W(0X3564, ctx->r1) = ctx->r20;
    // 0x80017CE4: sw          $s2, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->r18;
    // 0x80017CE8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80017CEC: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80017CF0: sw          $s2, 0x6AE8($at)
    MEM_W(0X6AE8, ctx->r1) = ctx->r18;
    // 0x80017CF4: addiu       $s1, $s1, 0x70
    ctx->r17 = ADD32(ctx->r17, 0X70);
L_80017CF8:
    // 0x80017CF8: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x80017CFC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80017D00: slti        $v0, $s2, 0x7
    ctx->r2 = SIGNED(ctx->r18) < 0X7 ? 1 : 0;
    // 0x80017D04: bne         $v0, $zero, L_80017C4C
    if (ctx->r2 != 0) {
        // 0x80017D08: addiu       $s3, $s3, 0x70
        ctx->r19 = ADD32(ctx->r19, 0X70);
            goto L_80017C4C;
    }
    // 0x80017D08: addiu       $s3, $s3, 0x70
    ctx->r19 = ADD32(ctx->r19, 0X70);
    // 0x80017D0C: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80017D10: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x80017D14: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80017D18: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80017D1C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80017D20: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80017D24: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80017D28: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80017D2C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80017D30: jr          $ra
    // 0x80017D34: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80017D34: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80017D38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017D38: addu        $t3, $a0, $zero
    ctx->r11 = ADD32(ctx->r4, 0);
    // 0x80017D3C: lbu         $v0, 0x2E($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X2E);
    // 0x80017D40: beq         $v0, $zero, L_80018174
    if (ctx->r2 == 0) {
        // 0x80017D44: addu        $a3, $t3, $zero
        ctx->r7 = ADD32(ctx->r11, 0);
            goto L_80018174;
    }
    // 0x80017D44: addu        $a3, $t3, $zero
    ctx->r7 = ADD32(ctx->r11, 0);
    // 0x80017D48: addiu       $t0, $t3, 0x20
    ctx->r8 = ADD32(ctx->r11, 0X20);
    // 0x80017D4C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80017D50: lw          $v0, -0x34C0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34C0);
    // 0x80017D54: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x80017D58: lw          $a0, -0x6700($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6700);
    // 0x80017D5C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x80017D60: addiu       $a1, $a1, -0x6610
    ctx->r5 = ADD32(ctx->r5, -0X6610);
    // 0x80017D64: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80017D68: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80017D6C: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80017D70: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80017D74: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80017D78: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80017D7C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80017D80: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80017D84: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80017D88: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80017D8C: addu        $a2, $v0, $a1
    ctx->r6 = ADD32(ctx->r2, ctx->r5);
L_80017D90:
    // 0x80017D90: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80017D94: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x80017D98: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    // 0x80017D9C: lw          $a1, 0xC($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC);
    // 0x80017DA0: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80017DA4: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x80017DA8: sw          $a0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r4;
    // 0x80017DAC: sw          $a1, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r5;
    // 0x80017DB0: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80017DB4: bne         $a3, $t0, L_80017D90
    if (ctx->r7 != ctx->r8) {
        // 0x80017DB8: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_80017D90;
    }
    // 0x80017DB8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80017DBC: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80017DC0: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x80017DC4: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80017DC8: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x80017DCC: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80017DD0: lw          $a2, 0x2FE4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2FE4);
    // 0x80017DD4: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
    // 0x80017DD8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80017DDC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80017DE0: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x80017DE4: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80017DE8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80017DEC: addiu       $v0, $v0, -0x6790
    ctx->r2 = ADD32(ctx->r2, -0X6790);
    // 0x80017DF0: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x80017DF4: lbu         $v0, 0x16($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X16);
    // 0x80017DF8: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x80017DFC: addiu       $t4, $t4, -0x6610
    ctx->r12 = ADD32(ctx->r12, -0X6610);
    // 0x80017E00: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80017E04: bne         $v0, $a3, L_80017ECC
    if (ctx->r2 != ctx->r7) {
        // 0x80017E08: lui         $v0, 0xBA00
        ctx->r2 = S32(0XBA00 << 16);
            goto L_80017ECC;
    }
    // 0x80017E08: lui         $v0, 0xBA00
    ctx->r2 = S32(0XBA00 << 16);
    // 0x80017E0C: ori         $v0, $v0, 0xE02
    ctx->r2 = ctx->r2 | 0XE02;
    // 0x80017E10: lui         $v1, 0xF500
    ctx->r3 = S32(0XF500 << 16);
    // 0x80017E14: ori         $v1, $v1, 0x100
    ctx->r3 = ctx->r3 | 0X100;
    // 0x80017E18: lui         $a0, 0x73F
    ctx->r4 = S32(0X73F << 16);
    // 0x80017E1C: sw          $v0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r2;
    // 0x80017E20: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x80017E24: sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    // 0x80017E28: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x80017E2C: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // 0x80017E30: lw          $a1, 0x30($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X30);
    // 0x80017E34: ori         $a0, $a0, 0xC000
    ctx->r4 = ctx->r4 | 0XC000;
    // 0x80017E38: addiu       $v0, $a2, 0x10
    ctx->r2 = ADD32(ctx->r6, 0X10);
    // 0x80017E3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80017E40: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80017E44: addiu       $v0, $a2, 0x18
    ctx->r2 = ADD32(ctx->r6, 0X18);
    // 0x80017E48: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80017E4C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80017E50: addiu       $v0, $a2, 0x20
    ctx->r2 = ADD32(ctx->r6, 0X20);
    // 0x80017E54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80017E58: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80017E5C: lui         $v0, 0xE800
    ctx->r2 = S32(0XE800 << 16);
    // 0x80017E60: sw          $v0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r2;
    // 0x80017E64: addiu       $v0, $a2, 0x28
    ctx->r2 = ADD32(ctx->r6, 0X28);
    // 0x80017E68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80017E6C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80017E70: lui         $v0, 0x700
    ctx->r2 = S32(0X700 << 16);
    // 0x80017E74: sw          $v0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r2;
    // 0x80017E78: addiu       $v0, $a2, 0x30
    ctx->r2 = ADD32(ctx->r6, 0X30);
    // 0x80017E7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80017E80: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80017E84: lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // 0x80017E88: sw          $v0, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r2;
    // 0x80017E8C: addiu       $v0, $a2, 0x38
    ctx->r2 = ADD32(ctx->r6, 0X38);
    // 0x80017E90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80017E94: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80017E98: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x80017E9C: sw          $v0, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->r2;
    // 0x80017EA0: addiu       $v0, $a2, 0x40
    ctx->r2 = ADD32(ctx->r6, 0X40);
    // 0x80017EA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80017EA8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80017EAC: lui         $v0, 0xE700
    ctx->r2 = S32(0XE700 << 16);
    // 0x80017EB0: sw          $zero, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = 0;
    // 0x80017EB4: sw          $v1, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r3;
    // 0x80017EB8: sw          $zero, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = 0;
    // 0x80017EBC: sw          $a0, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r4;
    // 0x80017EC0: sw          $v0, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->r2;
    // 0x80017EC4: sw          $zero, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = 0;
    // 0x80017EC8: sw          $a1, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r5;
L_80017ECC:
    // 0x80017ECC: lbu         $v1, 0x2A($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X2A);
    // 0x80017ED0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80017ED4: beq         $v1, $v0, L_80017F84
    if (ctx->r3 == ctx->r2) {
        // 0x80017ED8: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80017F84;
    }
    // 0x80017ED8: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80017EDC: beq         $v0, $zero, L_80017EF4
    if (ctx->r2 == 0) {
        // 0x80017EE0: nop
    
            goto L_80017EF4;
    }
    // 0x80017EE0: nop

    // 0x80017EE4: beq         $v1, $zero, L_80017F04
    if (ctx->r3 == 0) {
        // 0x80017EE8: lui         $v1, 0xB900
        ctx->r3 = S32(0XB900 << 16);
            goto L_80017F04;
    }
    // 0x80017EE8: lui         $v1, 0xB900
    ctx->r3 = S32(0XB900 << 16);
    // 0x80017EEC: j           L_8001810C
    // 0x80017EF0: nop

        goto L_8001810C;
    // 0x80017EF0: nop

L_80017EF4:
    // 0x80017EF4: beq         $v1, $a3, L_80018028
    if (ctx->r3 == ctx->r7) {
        // 0x80017EF8: lui         $t1, 0xFC11
        ctx->r9 = S32(0XFC11 << 16);
            goto L_80018028;
    }
    // 0x80017EF8: lui         $t1, 0xFC11
    ctx->r9 = S32(0XFC11 << 16);
    // 0x80017EFC: j           L_8001810C
    // 0x80017F00: nop

        goto L_8001810C;
    // 0x80017F00: nop

L_80017F04:
    // 0x80017F04: ori         $v1, $v1, 0x31D
    ctx->r3 = ctx->r3 | 0X31D;
    // 0x80017F08: lui         $a1, 0xBA00
    ctx->r5 = S32(0XBA00 << 16);
    // 0x80017F0C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80017F10: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x80017F14: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80017F18: lw          $a2, -0x34C0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X34C0);
    // 0x80017F1C: ori         $a1, $a1, 0x1402
    ctx->r5 = ctx->r5 | 0X1402;
    // 0x80017F20: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80017F24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80017F28: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80017F2C: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x80017F30: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80017F34: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80017F38: lui         $v0, 0x20
    ctx->r2 = S32(0X20 << 16);
    // 0x80017F3C: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x80017F40: addiu       $v0, $a0, 0x18
    ctx->r2 = ADD32(ctx->r4, 0X18);
    // 0x80017F44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80017F48: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80017F4C: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x80017F50: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80017F54: sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6 << 1);
    // 0x80017F58: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x80017F5C: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80017F60: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x80017F64: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80017F68: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    // 0x80017F6C: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x80017F70: lw          $a1, -0x6700($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6700);
    // 0x80017F74: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x80017F78: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80017F7C: j           L_80018008
    // 0x80017F80: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
        goto L_80018008;
    // 0x80017F80: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_80017F84:
    // 0x80017F84: lui         $a1, 0xB900
    ctx->r5 = S32(0XB900 << 16);
    // 0x80017F88: ori         $a1, $a1, 0x31D
    ctx->r5 = ctx->r5 | 0X31D;
    // 0x80017F8C: lui         $v1, 0xF0A
    ctx->r3 = S32(0XF0A << 16);
    // 0x80017F90: ori         $v1, $v1, 0x4000
    ctx->r3 = ctx->r3 | 0X4000;
    // 0x80017F94: lui         $a3, 0xBA00
    ctx->r7 = S32(0XBA00 << 16);
    // 0x80017F98: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80017F9C: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x80017FA0: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80017FA4: lw          $a2, -0x34C0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X34C0);
    // 0x80017FA8: ori         $a3, $a3, 0x1402
    ctx->r7 = ctx->r7 | 0X1402;
    // 0x80017FAC: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80017FB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80017FB4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80017FB8: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x80017FBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80017FC0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80017FC4: addiu       $v0, $a0, 0x18
    ctx->r2 = ADD32(ctx->r4, 0X18);
    // 0x80017FC8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80017FCC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80017FD0: lui         $v0, 0x100
    ctx->r2 = S32(0X100 << 16);
    // 0x80017FD4: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x80017FD8: sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6 << 1);
    // 0x80017FDC: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x80017FE0: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80017FE4: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x80017FE8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80017FEC: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80017FF0: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x80017FF4: lw          $a1, -0x6700($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6700);
    // 0x80017FF8: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x80017FFC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80018000: sw          $a3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r7;
    // 0x80018004: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
L_80018008:
    // 0x80018008: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x8001800C: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80018010: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80018014: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80018018: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x8001801C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80018020: j           L_8001810C
    // 0x80018024: sw          $v1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r3;
        goto L_8001810C;
    // 0x80018024: sw          $v1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r3;
L_80018028:
    // 0x80018028: ori         $t1, $t1, 0x9623
    ctx->r9 = ctx->r9 | 0X9623;
    // 0x8001802C: lui         $v1, 0xFF2F
    ctx->r3 = S32(0XFF2F << 16);
    // 0x80018030: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x80018034: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x80018038: ori         $t2, $t2, 0x31D
    ctx->r10 = ctx->r10 | 0X31D;
    // 0x8001803C: lui         $a1, 0x40
    ctx->r5 = S32(0X40 << 16);
    // 0x80018040: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80018044: lw          $a0, 0x2FE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2FE4);
    // 0x80018048: ori         $a1, $a1, 0x4240
    ctx->r5 = ctx->r5 | 0X4240;
    // 0x8001804C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80018050: lw          $a2, -0x34C0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X34C0);
    // 0x80018054: lui         $t0, 0xBA00
    ctx->r8 = S32(0XBA00 << 16);
    // 0x80018058: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8001805C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80018060: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80018064: lui         $v0, 0xFA00
    ctx->r2 = S32(0XFA00 << 16);
    // 0x80018068: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8001806C: lbu         $a3, 0x2F($t3)
    ctx->r7 = MEM_BU(ctx->r11, 0X2F);
    // 0x80018070: ori         $t0, $t0, 0x1402
    ctx->r8 = ctx->r8 | 0X1402;
    // 0x80018074: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x80018078: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001807C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80018080: addiu       $v0, $a0, 0x18
    ctx->r2 = ADD32(ctx->r4, 0X18);
    // 0x80018084: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80018088: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001808C: addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
    // 0x80018090: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80018094: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80018098: addiu       $v0, $a0, 0x28
    ctx->r2 = ADD32(ctx->r4, 0X28);
    // 0x8001809C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800180A0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800180A4: lui         $v0, 0x100
    ctx->r2 = S32(0X100 << 16);
    // 0x800180A8: sw          $v1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r3;
    // 0x800180AC: sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6 << 1);
    // 0x800180B0: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x800180B4: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800180B8: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x800180BC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800180C0: sw          $a1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r5;
    // 0x800180C4: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x800180C8: lw          $a1, -0x6700($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6700);
    // 0x800180CC: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x800180D0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800180D4: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // 0x800180D8: sw          $t2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r10;
    // 0x800180DC: sw          $t0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r8;
    // 0x800180E0: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x800180E4: sw          $v0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r2;
    // 0x800180E8: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800180EC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800180F0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800180F4: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x800180F8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800180FC: addiu       $v0, $zero, -0x100
    ctx->r2 = ADD32(0, -0X100);
    // 0x80018100: or          $a3, $a3, $v0
    ctx->r7 = ctx->r7 | ctx->r2;
    // 0x80018104: sw          $v1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r3;
    // 0x80018108: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
L_8001810C:
    // 0x8001810C: lbu         $v1, 0x16($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X16);
    // 0x80018110: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80018114: bne         $v1, $v0, L_80018140
    if (ctx->r3 != ctx->r2) {
        // 0x80018118: lui         $a1, 0xBA00
        ctx->r5 = S32(0XBA00 << 16);
            goto L_80018140;
    }
    // 0x80018118: lui         $a1, 0xBA00
    ctx->r5 = S32(0XBA00 << 16);
    // 0x8001811C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80018120: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x80018124: lui         $a0, 0xBA00
    ctx->r4 = S32(0XBA00 << 16);
    // 0x80018128: ori         $a0, $a0, 0xE02
    ctx->r4 = ctx->r4 | 0XE02;
    // 0x8001812C: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x80018130: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80018134: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x80018138: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8001813C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
L_80018140:
    // 0x80018140: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80018144: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80018148: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x8001814C: lw          $a0, -0x6700($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6700);
    // 0x80018150: ori         $a1, $a1, 0x1402
    ctx->r5 = ctx->r5 | 0X1402;
    // 0x80018154: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80018158: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001815C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80018160: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80018164: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x80018168: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8001816C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80018170: sw          $a0, -0x6700($at)
    MEM_W(-0X6700, ctx->r1) = ctx->r4;
L_80018174:
    // 0x80018174: jr          $ra
    // 0x80018178: nop

    return;
    // 0x80018178: nop

;}
RECOMP_FUNC void func_8001817C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001817C: addu        $t8, $a0, $zero
    ctx->r24 = ADD32(ctx->r4, 0);
    // 0x80018180: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80018184: lw          $a0, 0x4470($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4470);
    // 0x80018188: slti        $v0, $a0, 0x4C
    ctx->r2 = SIGNED(ctx->r4) < 0X4C ? 1 : 0;
    // 0x8001818C: beq         $v0, $zero, L_8001850C
    if (ctx->r2 == 0) {
        // 0x80018190: lui         $a2, 0xBA00
        ctx->r6 = S32(0XBA00 << 16);
            goto L_8001850C;
    }
    // 0x80018190: lui         $a2, 0xBA00
    ctx->r6 = S32(0XBA00 << 16);
    // 0x80018194: ori         $a2, $a2, 0x1402
    ctx->r6 = ctx->r6 | 0X1402;
    // 0x80018198: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x8001819C: ori         $t3, $t3, 0xC02
    ctx->r11 = ctx->r11 | 0XC02;
    // 0x800181A0: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x800181A4: ori         $t5, $t5, 0x31D
    ctx->r13 = ctx->r13 | 0X31D;
    // 0x800181A8: lui         $t4, 0xF0A
    ctx->r12 = S32(0XF0A << 16);
    // 0x800181AC: ori         $t4, $t4, 0x4000
    ctx->r12 = ctx->r12 | 0X4000;
    // 0x800181B0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800181B4: lw          $v1, -0x34C0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X34C0);
    // 0x800181B8: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x800181BC: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x800181C0: addiu       $t6, $t6, 0x4580
    ctx->r14 = ADD32(ctx->r14, 0X4580);
    // 0x800181C4: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800181C8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800181CC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800181D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800181D4: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800181D8: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x800181DC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800181E0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800181E4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800181E8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800181EC: lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X0);
    // 0x800181F0: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    // 0x800181F4: lw          $a1, 0x8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X8);
    // 0x800181F8: lw          $a3, 0xC($t8)
    ctx->r7 = MEM_W(ctx->r24, 0XC);
    // 0x800181FC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80018200: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x80018204: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
    // 0x80018208: sw          $a3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r7;
    // 0x8001820C: lw          $v1, 0x10($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X10);
    // 0x80018210: lw          $a0, 0x14($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X14);
    // 0x80018214: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x80018218: sw          $a0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r4;
    // 0x8001821C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80018220: lw          $v1, -0x34C0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X34C0);
    // 0x80018224: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x80018228: addiu       $t1, $t1, 0x1230
    ctx->r9 = ADD32(ctx->r9, 0X1230);
    // 0x8001822C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80018230: lw          $a0, 0x4470($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4470);
    // 0x80018234: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80018238: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8001823C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80018240: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80018244: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80018248: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x8001824C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80018250: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80018254: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80018258: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x8001825C: lw          $v1, 0x18($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X18);
    // 0x80018260: lw          $a0, 0x1C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X1C);
    // 0x80018264: lw          $a1, 0x20($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X20);
    // 0x80018268: lw          $a3, 0x24($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X24);
    // 0x8001826C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80018270: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x80018274: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
    // 0x80018278: sw          $a3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r7;
    // 0x8001827C: lw          $v1, 0x28($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X28);
    // 0x80018280: lw          $a0, 0x2C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X2C);
    // 0x80018284: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x80018288: sw          $a0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r4;
    // 0x8001828C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80018290: lw          $v1, -0x34C0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X34C0);
    // 0x80018294: lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // 0x80018298: addiu       $t0, $t0, -0x7540
    ctx->r8 = ADD32(ctx->r8, -0X7540);
    // 0x8001829C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x800182A0: lw          $a0, 0x4470($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4470);
    // 0x800182A4: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800182A8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800182AC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800182B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800182B4: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x800182B8: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x800182BC: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800182C0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800182C4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800182C8: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800182CC: lw          $v1, 0x30($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X30);
    // 0x800182D0: lw          $a0, 0x34($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X34);
    // 0x800182D4: lw          $a1, 0x38($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X38);
    // 0x800182D8: lw          $a3, 0x3C($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X3C);
    // 0x800182DC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800182E0: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x800182E4: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
    // 0x800182E8: sw          $a3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r7;
    // 0x800182EC: lw          $v1, 0x40($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X40);
    // 0x800182F0: lw          $a0, 0x44($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X44);
    // 0x800182F4: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x800182F8: sw          $a0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r4;
    // 0x800182FC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80018300: lw          $v1, -0x34C0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X34C0);
    // 0x80018304: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x80018308: lw          $a0, 0x4470($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4470);
    // 0x8001830C: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x80018310: addiu       $a3, $a3, 0x26E0
    ctx->r7 = ADD32(ctx->r7, 0X26E0);
    // 0x80018314: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80018318: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8001831C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80018320: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80018324: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x80018328: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x8001832C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80018330: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80018334: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80018338: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8001833C: lw          $v1, 0x48($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X48);
    // 0x80018340: lw          $a0, 0x4C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4C);
    // 0x80018344: lw          $a1, 0x50($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X50);
    // 0x80018348: lw          $t7, 0x54($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X54);
    // 0x8001834C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80018350: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x80018354: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
    // 0x80018358: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x8001835C: lw          $v1, 0x58($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X58);
    // 0x80018360: lw          $a0, 0x5C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X5C);
    // 0x80018364: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x80018368: sw          $a0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r4;
    // 0x8001836C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80018370: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x80018374: ori         $t2, $t2, 0xE02
    ctx->r10 = ctx->r10 | 0XE02;
    // 0x80018378: lui         $a0, 0x600
    ctx->r4 = S32(0X600 << 16);
    // 0x8001837C: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x80018380: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80018384: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80018388: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8001838C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80018390: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80018394: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80018398: addiu       $v0, $v0, -0x6790
    ctx->r2 = ADD32(ctx->r2, -0X6790);
    // 0x8001839C: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x800183A0: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x800183A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800183A8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800183AC: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x800183B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800183B4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800183B8: lui         $v0, 0xB100
    ctx->r2 = S32(0XB100 << 16);
    // 0x800183BC: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x800183C0: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x800183C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800183C8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800183CC: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x800183D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800183D4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x800183D8: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x800183DC: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x800183E0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800183E4: sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // 0x800183E8: sw          $t3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r11;
    // 0x800183EC: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x800183F0: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x800183F4: sw          $t5, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r13;
    // 0x800183F8: sw          $t4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r12;
    // 0x800183FC: sw          $t2, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r10;
    // 0x80018400: sw          $v0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r2;
    // 0x80018404: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80018408: lw          $a2, -0x34C0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X34C0);
    // 0x8001840C: lui         $a1, 0xC100
    ctx->r5 = S32(0XC100 << 16);
    // 0x80018410: ori         $a1, $a1, 0x17
    ctx->r5 = ctx->r5 | 0X17;
    // 0x80018414: sw          $a1, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r5;
    // 0x80018418: sw          $a1, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r5;
    // 0x8001841C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x80018420: lw          $a1, 0x4470($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4470);
    // 0x80018424: addiu       $v0, $v1, 0x38
    ctx->r2 = ADD32(ctx->r3, 0X38);
    // 0x80018428: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001842C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80018430: addiu       $v0, $v1, 0x40
    ctx->r2 = ADD32(ctx->r3, 0X40);
    // 0x80018434: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80018438: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001843C: addiu       $v0, $v1, 0x48
    ctx->r2 = ADD32(ctx->r3, 0X48);
    // 0x80018440: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80018444: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80018448: lui         $v0, 0x517
    ctx->r2 = S32(0X517 << 16);
    // 0x8001844C: sw          $v0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r2;
    // 0x80018450: addiu       $v0, $v1, 0x50
    ctx->r2 = ADD32(ctx->r3, 0X50);
    // 0x80018454: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80018458: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001845C: lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // 0x80018460: sw          $v0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r2;
    // 0x80018464: addiu       $v0, $v1, 0x58
    ctx->r2 = ADD32(ctx->r3, 0X58);
    // 0x80018468: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001846C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80018470: addiu       $v0, $v1, 0x60
    ctx->r2 = ADD32(ctx->r3, 0X60);
    // 0x80018474: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80018478: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001847C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80018480: addiu       $v0, $v0, -0x6850
    ctx->r2 = ADD32(ctx->r2, -0X6850);
    // 0x80018484: sw          $v0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r2;
    // 0x80018488: addiu       $v0, $v1, 0x68
    ctx->r2 = ADD32(ctx->r3, 0X68);
    // 0x8001848C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80018490: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x80018494: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80018498: addiu       $v0, $v0, -0x6858
    ctx->r2 = ADD32(ctx->r2, -0X6858);
    // 0x8001849C: sw          $t2, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r10;
    // 0x800184A0: sw          $zero, 0x54($v1)
    MEM_W(0X54, ctx->r3) = 0;
    // 0x800184A4: sw          $a0, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r4;
    // 0x800184A8: sw          $a0, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r4;
    // 0x800184AC: sw          $v0, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r2;
    // 0x800184B0: sll         $a0, $a2, 3
    ctx->r4 = S32(ctx->r6 << 3);
    // 0x800184B4: subu        $a0, $a0, $a2
    ctx->r4 = SUB32(ctx->r4, ctx->r6);
    // 0x800184B8: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x800184BC: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x800184C0: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x800184C4: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x800184C8: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800184CC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800184D0: addu        $a3, $v0, $a3
    ctx->r7 = ADD32(ctx->r2, ctx->r7);
    // 0x800184D4: addu        $a3, $a0, $a3
    ctx->r7 = ADD32(ctx->r4, ctx->r7);
    // 0x800184D8: addu        $t0, $v0, $t0
    ctx->r8 = ADD32(ctx->r2, ctx->r8);
    // 0x800184DC: addu        $t0, $a0, $t0
    ctx->r8 = ADD32(ctx->r4, ctx->r8);
    // 0x800184E0: addu        $t1, $v0, $t1
    ctx->r9 = ADD32(ctx->r2, ctx->r9);
    // 0x800184E4: addu        $t1, $a0, $t1
    ctx->r9 = ADD32(ctx->r4, ctx->r9);
    // 0x800184E8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800184EC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800184F0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800184F4: sw          $a3, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r7;
    // 0x800184F8: sw          $t0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r8;
    // 0x800184FC: sw          $t1, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r9;
    // 0x80018500: sw          $a0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r4;
    // 0x80018504: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80018508: sw          $a1, 0x4470($at)
    MEM_W(0X4470, ctx->r1) = ctx->r5;
L_8001850C:
    // 0x8001850C: jr          $ra
    // 0x80018510: nop

    return;
    // 0x80018510: nop

;}
RECOMP_FUNC void func_80018514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018514: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80018518: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8001851C: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80018520: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80018524: andi        $s0, $a1, 0xFFFF
    ctx->r16 = ctx->r5 & 0XFFFF;
    // 0x80018528: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001852C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80018530: jal         0x80060550
    // 0x80018534: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    func_80060550(rdram, ctx);
        goto after_0;
    // 0x80018534: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // 0x80018538: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001853C: sra         $s1, $v0, 15
    ctx->r17 = S32(SIGNED(ctx->r2) >> 15);
    // 0x80018540: jal         0x80061430
    // 0x80018544: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80061430(rdram, ctx);
        goto after_1;
    // 0x80018544: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80018548: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001854C: ori         $v1, $zero, 0xFFFE
    ctx->r3 = 0 | 0XFFFE;
    // 0x80018550: bne         $s1, $v1, L_8001855C
    if (ctx->r17 != ctx->r3) {
        // 0x80018554: sra         $v0, $v0, 15
        ctx->r2 = S32(SIGNED(ctx->r2) >> 15);
            goto L_8001855C;
    }
    // 0x80018554: sra         $v0, $v0, 15
    ctx->r2 = S32(SIGNED(ctx->r2) >> 15);
    // 0x80018558: lui         $s1, 0x1
    ctx->r17 = S32(0X1 << 16);
L_8001855C:
    // 0x8001855C: beql        $v0, $v1, L_80018564
    if (ctx->r2 == ctx->r3) {
        // 0x80018560: lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
            goto L_80018564;
    }
    goto skip_0;
    // 0x80018560: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    skip_0:
L_80018564:
    // 0x80018564: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x80018568: ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
    // 0x8001856C: beql        $s1, $v1, L_80018574
    if (ctx->r17 == ctx->r3) {
        // 0x80018570: lui         $s1, 0xFFFF
        ctx->r17 = S32(0XFFFF << 16);
            goto L_80018574;
    }
    goto skip_1;
    // 0x80018570: lui         $s1, 0xFFFF
    ctx->r17 = S32(0XFFFF << 16);
    skip_1:
L_80018574:
    // 0x80018574: beql        $v0, $v1, L_8001857C
    if (ctx->r2 == ctx->r3) {
        // 0x80018578: lui         $v0, 0xFFFF
        ctx->r2 = S32(0XFFFF << 16);
            goto L_8001857C;
    }
    goto skip_2;
    // 0x80018578: lui         $v0, 0xFFFF
    ctx->r2 = S32(0XFFFF << 16);
    skip_2:
L_8001857C:
    // 0x8001857C: sw          $v0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r2;
    // 0x80018580: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80018584: sw          $s1, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r17;
    // 0x80018588: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
    // 0x8001858C: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // 0x80018590: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80018594: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80018598: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8001859C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800185A0: jr          $ra
    // 0x800185A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800185A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800185A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800185A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800185AC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800185B0: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800185B4: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800185B8: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x800185BC: addiu       $s4, $s4, 0x1660
    ctx->r20 = ADD32(ctx->r20, 0X1660);
    // 0x800185C0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800185C4: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x800185C8: addiu       $s2, $s2, 0x3520
    ctx->r18 = ADD32(ctx->r18, 0X3520);
    // 0x800185CC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800185D0: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x800185D4: addiu       $s1, $s1, 0x6AA0
    ctx->r17 = ADD32(ctx->r17, 0X6AA0);
    // 0x800185D8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800185DC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800185E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_800185E4:
    // 0x800185E4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800185E8: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800185EC: lbu         $v0, 0x6AC8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC8);
    // 0x800185F0: beq         $v0, $zero, L_80018618
    if (ctx->r2 == 0) {
        // 0x800185F4: nop
    
            goto L_80018618;
    }
    // 0x800185F4: nop

    // 0x800185F8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800185FC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80018600: lbu         $v0, 0x6AC9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6AC9);
    // 0x80018604: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80018608: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x8001860C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80018610: jalr        $v0
    // 0x80018614: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80018614: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
L_80018618:
    // 0x80018618: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001861C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80018620: lbu         $v0, 0x3548($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3548);
    // 0x80018624: beql        $v0, $zero, L_80018650
    if (ctx->r2 == 0) {
        // 0x80018628: addiu       $s2, $s2, 0x70
        ctx->r18 = ADD32(ctx->r18, 0X70);
            goto L_80018650;
    }
    goto skip_0;
    // 0x80018628: addiu       $s2, $s2, 0x70
    ctx->r18 = ADD32(ctx->r18, 0X70);
    skip_0:
    // 0x8001862C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80018630: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80018634: lbu         $v0, 0x3549($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3549);
    // 0x80018638: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001863C: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80018640: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80018644: jalr        $v0
    // 0x80018648: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x80018648: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_1:
    // 0x8001864C: addiu       $s2, $s2, 0x70
    ctx->r18 = ADD32(ctx->r18, 0X70);
L_80018650:
    // 0x80018650: addiu       $s1, $s1, 0x70
    ctx->r17 = ADD32(ctx->r17, 0X70);
    // 0x80018654: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80018658: slti        $v0, $s3, 0x23
    ctx->r2 = SIGNED(ctx->r19) < 0X23 ? 1 : 0;
    // 0x8001865C: bne         $v0, $zero, L_800185E4
    if (ctx->r2 != 0) {
        // 0x80018660: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_800185E4;
    }
    // 0x80018660: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x80018664: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80018668: lbu         $v0, 0x7B8F($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B8F);
    // 0x8001866C: bne         $v0, $zero, L_8001867C
    if (ctx->r2 != 0) {
        // 0x80018670: nop
    
            goto L_8001867C;
    }
    // 0x80018670: nop

    // 0x80018674: jal         0x8001BB14
    // 0x80018678: nop

    func_8001BB14(rdram, ctx);
        goto after_2;
    // 0x80018678: nop

    after_2:
L_8001867C:
    // 0x8001867C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80018680: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80018684: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80018688: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8001868C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80018690: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80018694: jr          $ra
    // 0x80018698: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80018698: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8001869C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001869C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800186A0: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x800186A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800186A8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800186AC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800186B0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800186B4: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x800186B8: addiu       $s2, $s2, 0x3520
    ctx->r18 = ADD32(ctx->r18, 0X3520);
    // 0x800186BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800186C0: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800186C4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800186C8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800186CC: lw          $v1, 0x48($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X48);
    // 0x800186D0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800186D4: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x800186D8: addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // 0x800186DC: lw          $s3, -0x640C($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X640C);
    // 0x800186E0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800186E4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800186E8: lw          $v0, -0x6428($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6428);
    // 0x800186EC: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800186F0: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800186F4: bne         $a0, $zero, L_80018704
    if (ctx->r4 != 0) {
        // 0x800186F8: addu        $s4, $v0, $v1
        ctx->r20 = ADD32(ctx->r2, ctx->r3);
            goto L_80018704;
    }
    // 0x800186F8: addu        $s4, $v0, $v1
    ctx->r20 = ADD32(ctx->r2, ctx->r3);
    // 0x800186FC: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x80018700: addiu       $s2, $s2, 0x6AA0
    ctx->r18 = ADD32(ctx->r18, 0X6AA0);
L_80018704:
    // 0x80018704: lbu         $s1, 0x2B($s0)
    ctx->r17 = MEM_BU(ctx->r16, 0X2B);
    // 0x80018708: beq         $s1, $zero, L_80018720
    if (ctx->r17 == 0) {
        // 0x8001870C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80018720;
    }
    // 0x8001870C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80018710: beq         $s1, $v0, L_8001880C
    if (ctx->r17 == ctx->r2) {
        // 0x80018714: nop
    
            goto L_8001880C;
    }
    // 0x80018714: nop

    // 0x80018718: j           L_800188D0
    // 0x8001871C: nop

        goto L_800188D0;
    // 0x8001871C: nop

L_80018720:
    // 0x80018720: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80018724: sb          $v1, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r3;
    // 0x80018728: sb          $v1, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r3;
    // 0x8001872C: lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X1);
    // 0x80018730: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018734: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80018738: lui         $at, 0x3B44
    ctx->r1 = S32(0X3B44 << 16);
    // 0x8001873C: ori         $at, $at, 0x9BA6
    ctx->r1 = ctx->r1 | 0X9BA6;
    // 0x80018740: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80018744: lbu         $a1, 0x2A($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2A);
    // 0x80018748: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x8001874C: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
    // 0x80018750: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x80018754: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80018758: sb          $v1, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r3;
    // 0x8001875C: addiu       $v1, $zero, 0x500
    ctx->r3 = ADD32(0, 0X500);
    // 0x80018760: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x80018764: addiu       $v0, $zero, 0x3C0
    ctx->r2 = ADD32(0, 0X3C0);
    // 0x80018768: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x8001876C: sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // 0x80018770: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80018774: addiu       $v0, $v0, 0x3040
    ctx->r2 = ADD32(ctx->r2, 0X3040);
    // 0x80018778: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x8001877C: ori         $v0, $zero, 0xFFF4
    ctx->r2 = 0 | 0XFFF4;
    // 0x80018780: sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
    // 0x80018784: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80018788: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
    // 0x8001878C: sb          $zero, 0x6A($s0)
    MEM_B(0X6A, ctx->r16) = 0;
    // 0x80018790: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x80018794: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x80018798: sh          $v1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r3;
    // 0x8001879C: sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // 0x800187A0: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x800187A4: sh          $v1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r3;
    // 0x800187A8: sb          $zero, 0x16($s0)
    MEM_B(0X16, ctx->r16) = 0;
    // 0x800187AC: sb          $v0, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r2;
    // 0x800187B0: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x800187B4: sh          $zero, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = 0;
    // 0x800187B8: sb          $a0, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r4;
    // 0x800187BC: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x800187C0: beq         $a1, $zero, L_800187DC
    if (ctx->r5 == 0) {
        // 0x800187C4: swc1        $f2, 0x38($s0)
        MEM_W(0X38, ctx->r16) = ctx->f2.u32l;
            goto L_800187DC;
    }
    // 0x800187C4: swc1        $f2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f2.u32l;
    // 0x800187C8: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x800187CC: sh          $v0, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r2;
    // 0x800187D0: sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    // 0x800187D4: j           L_800187E4
    // 0x800187D8: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
        goto L_800187E4;
    // 0x800187D8: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
L_800187DC:
    // 0x800187DC: jal         0x80066D30
    // 0x800187E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066D30(rdram, ctx);
        goto after_0;
    // 0x800187E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
L_800187E4:
    // 0x800187E4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800187E8: sb          $v0, 0x16($s0)
    MEM_B(0X16, ctx->r16) = ctx->r2;
    // 0x800187EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800187F0: sb          $v0, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r2;
    // 0x800187F4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x800187F8: addiu       $v0, $v0, -0x2538
    ctx->r2 = ADD32(ctx->r2, -0X2538);
    // 0x800187FC: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x80018800: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x80018804: j           L_800188B8
    // 0x80018808: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
        goto L_800188B8;
    // 0x80018808: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
L_8001880C:
    // 0x8001880C: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x80018810: andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // 0x80018814: beq         $v0, $zero, L_80018840
    if (ctx->r2 == 0) {
        // 0x80018818: andi        $v0, $v1, 0x7F
        ctx->r2 = ctx->r3 & 0X7F;
            goto L_80018840;
    }
    // 0x80018818: andi        $v0, $v1, 0x7F
    ctx->r2 = ctx->r3 & 0X7F;
    // 0x8001881C: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x80018820: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80018824: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80018828: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8001882C: jal         0x8001BCBC
    // 0x80018830: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001BCBC(rdram, ctx);
        goto after_1;
    // 0x80018830: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80018834: lhu         $v0, 0x6C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6C);
    // 0x80018838: andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
    // 0x8001883C: sh          $v0, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = ctx->r2;
L_80018840:
    // 0x80018840: lb          $v1, 0x68($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X68);
    // 0x80018844: bne         $v1, $s1, L_8001886C
    if (ctx->r3 != ctx->r17) {
        // 0x80018848: nop
    
            goto L_8001886C;
    }
    // 0x80018848: nop

    // 0x8001884C: lw          $v0, 0x48($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X48);
    // 0x80018850: bne         $v0, $zero, L_8001886C
    if (ctx->r2 != 0) {
        // 0x80018854: nop
    
            goto L_8001886C;
    }
    // 0x80018854: nop

    // 0x80018858: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001885C: lw          $v0, 0x2090($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2090);
    // 0x80018860: beql        $v0, $zero, L_8001886C
    if (ctx->r2 == 0) {
        // 0x80018864: sw          $v1, 0x60($s2)
        MEM_W(0X60, ctx->r18) = ctx->r3;
            goto L_8001886C;
    }
    goto skip_0;
    // 0x80018864: sw          $v1, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->r3;
    skip_0:
    // 0x80018868: sw          $zero, 0x60($s2)
    MEM_W(0X60, ctx->r18) = 0;
L_8001886C:
    // 0x8001886C: lw          $v0, 0x60($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X60);
    // 0x80018870: beq         $v0, $zero, L_800188C8
    if (ctx->r2 == 0) {
        // 0x80018874: nop
    
            goto L_800188C8;
    }
    // 0x80018874: nop

    // 0x80018878: jal         0x8001BCE0
    // 0x8001887C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001BCE0(rdram, ctx);
        goto after_2;
    // 0x8001887C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80018880: beq         $v0, $zero, L_800188D0
    if (ctx->r2 == 0) {
        // 0x80018884: nop
    
            goto L_800188D0;
    }
    // 0x80018884: nop

    // 0x80018888: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x8001888C: beq         $v0, $zero, L_8001889C
    if (ctx->r2 == 0) {
        // 0x80018890: sw          $zero, 0x4C($s0)
        MEM_W(0X4C, ctx->r16) = 0;
            goto L_8001889C;
    }
    // 0x80018890: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
    // 0x80018894: j           L_800188AC
    // 0x80018898: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_800188AC;
    // 0x80018898: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_8001889C:
    // 0x8001889C: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x800188A0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800188A4: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800188A8: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
L_800188AC:
    // 0x800188AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800188B0: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800188B4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
L_800188B8:
    // 0x800188B8: jal         0x8001BCBC
    // 0x800188BC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001BCBC(rdram, ctx);
        goto after_3;
    // 0x800188BC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x800188C0: j           L_800188D0
    // 0x800188C4: nop

        goto L_800188D0;
    // 0x800188C4: nop

L_800188C8:
    // 0x800188C8: lhu         $v0, 0x6E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6E);
    // 0x800188CC: sh          $v0, 0x6C($s0)
    MEM_H(0X6C, ctx->r16) = ctx->r2;
L_800188D0:
    // 0x800188D0: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x800188D4: lwc1        $f2, 0x38($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800188D8: lw          $v0, 0x58($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X58);
    // 0x800188DC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800188E0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800188E4: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x800188E8: bne         $v0, $zero, L_80018994
    if (ctx->r2 != 0) {
        // 0x800188EC: swc1        $f0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
            goto L_80018994;
    }
    // 0x800188EC: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x800188F0: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800188F4: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x800188F8: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x800188FC: beq         $v0, $zero, L_8001894C
    if (ctx->r2 == 0) {
        // 0x80018900: swc1        $f2, 0x38($s0)
        MEM_W(0X38, ctx->r16) = ctx->f2.u32l;
            goto L_8001894C;
    }
    // 0x80018900: swc1        $f2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f2.u32l;
    // 0x80018904: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80018908: nop

    // 0x8001890C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80018910: nop

    // 0x80018914: nop

    // 0x80018918: bc1f        L_80018940
    if (!c1cs) {
        // 0x8001891C: addiu       $v0, $zero, 0x12
        ctx->r2 = ADD32(0, 0X12);
            goto L_80018940;
    }
    // 0x8001891C: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x80018920: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018924: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80018928: lui         $at, 0x3BA3
    ctx->r1 = S32(0X3BA3 << 16);
    // 0x8001892C: ori         $at, $at, 0xD70A
    ctx->r1 = ctx->r1 | 0XD70A;
    // 0x80018930: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80018934: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
    // 0x80018938: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x8001893C: swc1        $f2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f2.u32l;
L_80018940:
    // 0x80018940: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80018944: bne         $v0, $zero, L_8001898C
    if (ctx->r2 != 0) {
        // 0x80018948: nop
    
            goto L_8001898C;
    }
    // 0x80018948: nop

L_8001894C:
    // 0x8001894C: lwc1        $f2, 0x38($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80018950: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80018954: nop

    // 0x80018958: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001895C: nop

    // 0x80018960: nop

    // 0x80018964: bc1f        L_8001898C
    if (!c1cs) {
        // 0x80018968: addiu       $v0, $zero, 0x1E
        ctx->r2 = ADD32(0, 0X1E);
            goto L_8001898C;
    }
    // 0x80018968: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x8001896C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018970: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80018974: lui         $at, 0x3B44
    ctx->r1 = S32(0X3B44 << 16);
    // 0x80018978: ori         $at, $at, 0x9BA6
    ctx->r1 = ctx->r1 | 0X9BA6;
    // 0x8001897C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80018980: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
    // 0x80018984: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80018988: swc1        $f2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f2.u32l;
L_8001898C:
    // 0x8001898C: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x80018990: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
L_80018994:
    // 0x80018994: lhu         $v0, 0x6C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6C);
    // 0x80018998: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x8001899C: beq         $v0, $zero, L_80018A10
    if (ctx->r2 == 0) {
        // 0x800189A0: nop
    
            goto L_80018A10;
    }
    // 0x800189A0: nop

    // 0x800189A4: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x800189A8: bne         $v0, $zero, L_800189DC
    if (ctx->r2 != 0) {
        // 0x800189AC: nop
    
            goto L_800189DC;
    }
    // 0x800189AC: nop

    // 0x800189B0: lb          $v0, 0x6A($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X6A);
    // 0x800189B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800189B8: addiu       $a0, $a0, -0x75C0
    ctx->r4 = ADD32(ctx->r4, -0X75C0);
    // 0x800189BC: beq         $v0, $zero, L_800189CC
    if (ctx->r2 == 0) {
        // 0x800189C0: lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
            goto L_800189CC;
    }
    // 0x800189C0: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x800189C4: ori         $v0, $v0, 0x2C00
    ctx->r2 = ctx->r2 | 0X2C00;
    // 0x800189C8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
L_800189CC:
    // 0x800189CC: lhu         $v0, 0x6($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X6);
    // 0x800189D0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800189D4: j           L_800189FC
    // 0x800189D8: sh          $v1, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r3;
        goto L_800189FC;
    // 0x800189D8: sh          $v1, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r3;
L_800189DC:
    // 0x800189DC: lb          $v0, 0x6A($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X6A);
    // 0x800189E0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800189E4: bne         $v0, $zero, L_800189F4
    if (ctx->r2 != 0) {
        // 0x800189E8: addiu       $a0, $a0, 0x4C40
        ctx->r4 = ADD32(ctx->r4, 0X4C40);
            goto L_800189F4;
    }
    // 0x800189E8: addiu       $a0, $a0, 0x4C40
    ctx->r4 = ADD32(ctx->r4, 0X4C40);
    // 0x800189EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800189F0: addiu       $a0, $a0, 0x2040
    ctx->r4 = ADD32(ctx->r4, 0X2040);
L_800189F4:
    // 0x800189F4: lhu         $v0, 0x6($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X6);
    // 0x800189F8: sh          $zero, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = 0;
L_800189FC:
    // 0x800189FC: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80018A00: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x80018A04: lbu         $v0, 0x6A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6A);
    // 0x80018A08: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80018A0C: sb          $v0, 0x6A($s0)
    MEM_B(0X6A, ctx->r16) = ctx->r2;
L_80018A10:
    // 0x80018A10: jal         0x8001BD58
    // 0x80018A14: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001BD58(rdram, ctx);
        goto after_4;
    // 0x80018A14: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x80018A18: jal         0x8001BE20
    // 0x80018A1C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001BE20(rdram, ctx);
        goto after_5;
    // 0x80018A1C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x80018A20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80018A24: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80018A28: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80018A2C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80018A30: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80018A34: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80018A38: jr          $ra
    // 0x80018A3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80018A3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80018A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018A40: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80018A44: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x80018A48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80018A4C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80018A50: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80018A54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80018A58: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80018A5C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80018A60: lw          $v1, 0x48($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X48);
    // 0x80018A64: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80018A68: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80018A6C: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x80018A70: lw          $s2, -0x640C($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X640C);
    // 0x80018A74: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80018A78: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80018A7C: lw          $v0, -0x6428($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6428);
    // 0x80018A80: lbu         $a0, 0x2B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X2B);
    // 0x80018A84: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80018A88: bne         $a0, $zero, L_80018B90
    if (ctx->r4 != 0) {
        // 0x80018A8C: addu        $s1, $v0, $v1
        ctx->r17 = ADD32(ctx->r2, ctx->r3);
            goto L_80018B90;
    }
    // 0x80018A8C: addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // 0x80018A90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80018A94: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x80018A98: sb          $zero, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = 0;
    // 0x80018A9C: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
    // 0x80018AA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018AA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80018AA8: lbu         $a1, 0x2A($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2A);
    // 0x80018AAC: addiu       $v1, $zero, 0x500
    ctx->r3 = ADD32(0, 0X500);
    // 0x80018AB0: sb          $v0, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r2;
    // 0x80018AB4: addiu       $v0, $zero, 0x3C0
    ctx->r2 = ADD32(0, 0X3C0);
    // 0x80018AB8: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x80018ABC: sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // 0x80018AC0: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80018AC4: addiu       $v0, $v0, 0x3040
    ctx->r2 = ADD32(ctx->r2, 0X3040);
    // 0x80018AC8: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x80018ACC: ori         $v0, $zero, 0xFFF4
    ctx->r2 = 0 | 0XFFF4;
    // 0x80018AD0: sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
    // 0x80018AD4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80018AD8: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x80018ADC: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x80018AE0: sh          $v1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r3;
    // 0x80018AE4: sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // 0x80018AE8: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x80018AEC: sh          $v1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r3;
    // 0x80018AF0: sb          $zero, 0x16($s0)
    MEM_B(0X16, ctx->r16) = 0;
    // 0x80018AF4: sb          $v0, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r2;
    // 0x80018AF8: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x80018AFC: sh          $zero, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = 0;
    // 0x80018B00: sb          $a0, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r4;
    // 0x80018B04: beq         $a1, $zero, L_80018B20
    if (ctx->r5 == 0) {
        // 0x80018B08: swc1        $f0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
            goto L_80018B20;
    }
    // 0x80018B08: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80018B0C: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x80018B10: sh          $v0, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r2;
    // 0x80018B14: sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    // 0x80018B18: j           L_80018B28
    // 0x80018B1C: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
        goto L_80018B28;
    // 0x80018B1C: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
L_80018B20:
    // 0x80018B20: jal         0x80066D30
    // 0x80018B24: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80066D30(rdram, ctx);
        goto after_0;
    // 0x80018B24: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
L_80018B28:
    // 0x80018B28: lw          $v1, 0x44($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X44);
    // 0x80018B2C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80018B30: sb          $v0, 0x16($s0)
    MEM_B(0X16, ctx->r16) = ctx->r2;
    // 0x80018B34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80018B38: sb          $v0, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r2;
    // 0x80018B3C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80018B40: addiu       $v0, $v0, -0x2538
    ctx->r2 = ADD32(ctx->r2, -0X2538);
    // 0x80018B44: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x80018B48: bne         $v1, $zero, L_80018B6C
    if (ctx->r3 != 0) {
        // 0x80018B4C: sw          $v0, 0x30($s0)
        MEM_W(0X30, ctx->r16) = ctx->r2;
            goto L_80018B6C;
    }
    // 0x80018B4C: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x80018B50: lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X6);
    // 0x80018B54: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80018B58: sh          $v1, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r3;
    // 0x80018B5C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80018B60: addiu       $v1, $v1, -0x75C0
    ctx->r3 = ADD32(ctx->r3, -0X75C0);
    // 0x80018B64: j           L_80018B80
    // 0x80018B68: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
        goto L_80018B80;
    // 0x80018B68: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_80018B6C:
    // 0x80018B6C: lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X6);
    // 0x80018B70: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80018B74: addiu       $v1, $v1, 0x2040
    ctx->r3 = ADD32(ctx->r3, 0X2040);
    // 0x80018B78: sh          $zero, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = 0;
    // 0x80018B7C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_80018B80:
    // 0x80018B80: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x80018B84: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80018B88: jal         0x8001BCBC
    // 0x80018B8C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001BCBC(rdram, ctx);
        goto after_1;
    // 0x80018B8C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
L_80018B90:
    // 0x80018B90: jal         0x8001BD58
    // 0x80018B94: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001BD58(rdram, ctx);
        goto after_2;
    // 0x80018B94: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80018B98: jal         0x8001BE20
    // 0x80018B9C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001BE20(rdram, ctx);
        goto after_3;
    // 0x80018B9C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80018BA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80018BA4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80018BA8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80018BAC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80018BB0: jr          $ra
    // 0x80018BB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80018BB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80018BB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018BB8: jr          $ra
    // 0x80018BBC: nop

    return;
    // 0x80018BBC: nop

;}
RECOMP_FUNC void func_80018BC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018BC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80018BC4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80018BC8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80018BCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018BD0: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x80018BD4: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x80018BD8: beq         $v0, $zero, L_80018D40
    if (ctx->r2 == 0) {
        // 0x80018BDC: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80018D40;
    }
    // 0x80018BDC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80018BE0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80018BE4: addu        $at, $at, $v0
    gpr jr_addend_80018BEC = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80018BE8: lw          $v0, -0x30F0($at)
    ctx->r2 = ADD32(ctx->r1, -0X30F0);
    // 0x80018BEC: jr          $v0
    // 0x80018BF0: nop

    switch (jr_addend_80018BEC >> 2) {
        case 0: goto L_80018BF4; break;
        case 1: goto L_80018C70; break;
        case 2: goto L_80018C8C; break;
        case 3: goto L_80018D40; break;
        case 4: goto L_80018CBC; break;
        case 5: goto L_80018D40; break;
        default: switch_error(__func__, 0x80018BEC, 0x800ACF10);
    }
    // 0x80018BF0: nop

L_80018BF4:
    // 0x80018BF4: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x80018BF8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80018BFC: sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
    // 0x80018C00: addiu       $v0, $zero, 0xB9
    ctx->r2 = ADD32(0, 0XB9);
    // 0x80018C04: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x80018C08: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80018C0C: addiu       $v0, $v0, 0xA60
    ctx->r2 = ADD32(ctx->r2, 0XA60);
    // 0x80018C10: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x80018C14: addiu       $v0, $v0, -0x800
    ctx->r2 = ADD32(ctx->r2, -0X800);
    // 0x80018C18: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x80018C1C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80018C20: sb          $v1, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r3;
    // 0x80018C24: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80018C28: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x80018C2C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80018C30: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80018C34: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80018C38: lbu         $v0, 0x1714($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X1714);
    // 0x80018C3C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80018C40: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x80018C44: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80018C48: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x80018C4C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80018C50: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80018C54: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80018C58: lbu         $v0, 0x1715($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X1715);
    // 0x80018C5C: sb          $zero, 0x17($s0)
    MEM_B(0X17, ctx->r16) = 0;
    // 0x80018C60: sb          $zero, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = 0;
    // 0x80018C64: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80018C68: j           L_80018D40
    // 0x80018C6C: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
        goto L_80018D40;
    // 0x80018C6C: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
L_80018C70:
    // 0x80018C70: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80018C74: lb          $v0, 0x5585($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5585);
    // 0x80018C78: beq         $v0, $zero, L_80018D40
    if (ctx->r2 == 0) {
        // 0x80018C7C: nop
    
            goto L_80018D40;
    }
    // 0x80018C7C: nop

    // 0x80018C80: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x80018C84: j           L_80018CB4
    // 0x80018C88: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_80018CB4;
    // 0x80018C88: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80018C8C:
    // 0x80018C8C: lbu         $v1, 0x2F($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2F);
    // 0x80018C90: sltiu       $v0, $v1, 0xB4
    ctx->r2 = ctx->r3 < 0XB4 ? 1 : 0;
    // 0x80018C94: beq         $v0, $zero, L_80018CA4
    if (ctx->r2 == 0) {
        // 0x80018C98: addiu       $v0, $v1, 0xA
        ctx->r2 = ADD32(ctx->r3, 0XA);
            goto L_80018CA4;
    }
    // 0x80018C98: addiu       $v0, $v1, 0xA
    ctx->r2 = ADD32(ctx->r3, 0XA);
    // 0x80018C9C: j           L_80018D40
    // 0x80018CA0: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
        goto L_80018D40;
    // 0x80018CA0: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
L_80018CA4:
    // 0x80018CA4: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x80018CA8: addiu       $v1, $zero, 0xB9
    ctx->r3 = ADD32(0, 0XB9);
    // 0x80018CAC: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
    // 0x80018CB0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80018CB4:
    // 0x80018CB4: j           L_80018D40
    // 0x80018CB8: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
        goto L_80018D40;
    // 0x80018CB8: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_80018CBC:
    // 0x80018CBC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80018CC0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80018CC4: jal         0x8001D578
    // 0x80018CC8: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    func_8001D578(rdram, ctx);
        goto after_0;
    // 0x80018CC8: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    after_0:
    // 0x80018CCC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80018CD0: sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
    // 0x80018CD4: addiu       $v0, $zero, 0xB9
    ctx->r2 = ADD32(0, 0XB9);
    // 0x80018CD8: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x80018CDC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80018CE0: addiu       $v0, $v0, 0xA60
    ctx->r2 = ADD32(ctx->r2, 0XA60);
    // 0x80018CE4: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x80018CE8: addiu       $v0, $v0, -0x800
    ctx->r2 = ADD32(ctx->r2, -0X800);
    // 0x80018CEC: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x80018CF0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80018CF4: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x80018CF8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80018CFC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80018D00: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80018D04: lbu         $v0, 0x1714($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X1714);
    // 0x80018D08: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80018D0C: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x80018D10: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80018D14: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x80018D18: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80018D1C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80018D20: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80018D24: lbu         $v0, 0x1715($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X1715);
    // 0x80018D28: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80018D2C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x80018D30: sb          $zero, 0x17($s0)
    MEM_B(0X17, ctx->r16) = 0;
    // 0x80018D34: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80018D38: jal         0x8001D470
    // 0x80018D3C: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    func_8001D470(rdram, ctx);
        goto after_1;
    // 0x80018D3C: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    after_1:
L_80018D40:
    // 0x80018D40: jal         0x8001D160
    // 0x80018D44: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D160(rdram, ctx);
        goto after_2;
    // 0x80018D44: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80018D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80018D4C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80018D50: jr          $ra
    // 0x80018D54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80018D54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80018D58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018D58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80018D5C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80018D60: lbu         $a1, 0x2B($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X2B);
    // 0x80018D64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80018D68: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x80018D6C: beq         $v1, $v0, L_80018E14
    if (ctx->r3 == ctx->r2) {
        // 0x80018D70: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80018E14;
    }
    // 0x80018D70: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80018D74: beql        $v0, $zero, L_80018D8C
    if (ctx->r2 == 0) {
        // 0x80018D78: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80018D8C;
    }
    goto skip_0;
    // 0x80018D78: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x80018D7C: beq         $v1, $zero, L_80018D9C
    if (ctx->r3 == 0) {
        // 0x80018D80: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_80018D9C;
    }
    // 0x80018D80: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x80018D84: j           L_80018E4C
    // 0x80018D88: nop

        goto L_80018E4C;
    // 0x80018D88: nop

L_80018D8C:
    // 0x80018D8C: beq         $v1, $v0, L_80018E2C
    if (ctx->r3 == ctx->r2) {
        // 0x80018D90: nop
    
            goto L_80018E2C;
    }
    // 0x80018D90: nop

    // 0x80018D94: j           L_80018E4C
    // 0x80018D98: nop

        goto L_80018E4C;
    // 0x80018D98: nop

L_80018D9C:
    // 0x80018D9C: sb          $v0, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r2;
    // 0x80018DA0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80018DA4: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    // 0x80018DA8: addiu       $v0, $zero, 0xB9
    ctx->r2 = ADD32(0, 0XB9);
    // 0x80018DAC: sb          $v0, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r2;
    // 0x80018DB0: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80018DB4: addiu       $v0, $v0, 0xA60
    ctx->r2 = ADD32(ctx->r2, 0XA60);
    // 0x80018DB8: sw          $v0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r2;
    // 0x80018DBC: addiu       $v0, $v0, -0x800
    ctx->r2 = ADD32(ctx->r2, -0X800);
    // 0x80018DC0: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x80018DC4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80018DC8: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x80018DCC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80018DD0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80018DD4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80018DD8: lbu         $v0, 0x1714($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X1714);
    // 0x80018DDC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80018DE0: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x80018DE4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80018DE8: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x80018DEC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80018DF0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80018DF4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80018DF8: lbu         $v0, 0x1715($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X1715);
    // 0x80018DFC: sb          $zero, 0x17($a0)
    MEM_B(0X17, ctx->r4) = 0;
    // 0x80018E00: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80018E04: sh          $v0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r2;
    // 0x80018E08: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80018E0C: j           L_80018E4C
    // 0x80018E10: sw          $zero, 0x5590($at)
    MEM_W(0X5590, ctx->r1) = 0;
        goto L_80018E4C;
    // 0x80018E10: sw          $zero, 0x5590($at)
    MEM_W(0X5590, ctx->r1) = 0;
L_80018E14:
    // 0x80018E14: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80018E18: lw          $v0, 0x5590($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5590);
    // 0x80018E1C: beq         $v0, $zero, L_80018E4C
    if (ctx->r2 == 0) {
        // 0x80018E20: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_80018E4C;
    }
    // 0x80018E20: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x80018E24: j           L_80018E4C
    // 0x80018E28: sb          $v0, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r2;
        goto L_80018E4C;
    // 0x80018E28: sb          $v0, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r2;
L_80018E2C:
    // 0x80018E2C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80018E30: lw          $v0, 0x5590($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5590);
    // 0x80018E34: lwc1        $f0, 0x34($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80018E38: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x80018E3C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80018E40: lw          $v0, 0x5590($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5590);
    // 0x80018E44: lwc1        $f0, 0x38($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80018E48: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
L_80018E4C:
    // 0x80018E4C: jal         0x8001D160
    // 0x80018E50: nop

    func_8001D160(rdram, ctx);
        goto after_0;
    // 0x80018E50: nop

    after_0:
    // 0x80018E54: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80018E58: jr          $ra
    // 0x80018E5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80018E5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80018E60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018E60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80018E64: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80018E68: lbu         $a1, 0x2B($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X2B);
    // 0x80018E6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80018E70: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x80018E74: beq         $v1, $v0, L_80018F18
    if (ctx->r3 == ctx->r2) {
        // 0x80018E78: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80018F18;
    }
    // 0x80018E78: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80018E7C: beq         $v0, $zero, L_80018F80
    if (ctx->r2 == 0) {
        // 0x80018E80: nop
    
            goto L_80018F80;
    }
    // 0x80018E80: nop

    // 0x80018E84: bne         $v1, $zero, L_80018F80
    if (ctx->r3 != 0) {
        // 0x80018E88: addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
            goto L_80018F80;
    }
    // 0x80018E88: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x80018E8C: sb          $v0, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r2;
    // 0x80018E90: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80018E94: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    // 0x80018E98: addiu       $v0, $zero, 0xB9
    ctx->r2 = ADD32(0, 0XB9);
    // 0x80018E9C: sb          $v0, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r2;
    // 0x80018EA0: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80018EA4: addiu       $v0, $v0, 0xA60
    ctx->r2 = ADD32(ctx->r2, 0XA60);
    // 0x80018EA8: sw          $v0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r2;
    // 0x80018EAC: addiu       $v0, $v0, -0x800
    ctx->r2 = ADD32(ctx->r2, -0X800);
    // 0x80018EB0: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x80018EB4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80018EB8: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x80018EBC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80018EC0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80018EC4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80018EC8: lbu         $v0, 0x1714($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X1714);
    // 0x80018ECC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80018ED0: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x80018ED4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80018ED8: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x80018EDC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80018EE0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80018EE4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80018EE8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80018EEC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80018EF0: lbu         $v0, 0x1715($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X1715);
    // 0x80018EF4: sb          $zero, 0x17($a0)
    MEM_B(0X17, ctx->r4) = 0;
    // 0x80018EF8: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x80018EFC: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x80018F00: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80018F04: sh          $v0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r2;
    // 0x80018F08: addiu       $v0, $zero, -0xE6
    ctx->r2 = ADD32(0, -0XE6);
    // 0x80018F0C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80018F10: j           L_80018F80
    // 0x80018F14: sh          $v0, 0x558E($at)
    MEM_H(0X558E, ctx->r1) = ctx->r2;
        goto L_80018F80;
    // 0x80018F14: sh          $v0, 0x558E($at)
    MEM_H(0X558E, ctx->r1) = ctx->r2;
L_80018F18:
    // 0x80018F18: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x80018F1C: addiu       $v1, $v1, 0x558E
    ctx->r3 = ADD32(ctx->r3, 0X558E);
    // 0x80018F20: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80018F24: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80018F28: ldc1        $f2, -0x30D8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X30D8);
    // 0x80018F2C: addiu       $v0, $v0, 0xE6
    ctx->r2 = ADD32(ctx->r2, 0XE6);
    // 0x80018F30: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80018F34: nop

    // 0x80018F38: cvt.d.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.d = CVT_D_W(ctx->f0.u32l);
    // 0x80018F3C: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x80018F40: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80018F44: ldc1        $f2, -0x30D0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X30D0);
    // 0x80018F48: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x80018F4C: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x80018F50: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x80018F54: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x80018F58: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80018F5C: bne         $v0, $zero, L_80018F80
    if (ctx->r2 != 0) {
        // 0x80018F60: nop
    
            goto L_80018F80;
    }
    // 0x80018F60: nop

    // 0x80018F64: lbu         $v0, 0x2B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2B);
    // 0x80018F68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018F6C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80018F70: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80018F74: sb          $v0, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r2;
    // 0x80018F78: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x80018F7C: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
L_80018F80:
    // 0x80018F80: jal         0x8001D160
    // 0x80018F84: nop

    func_8001D160(rdram, ctx);
        goto after_0;
    // 0x80018F84: nop

    after_0:
    // 0x80018F88: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80018F8C: jr          $ra
    // 0x80018F90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80018F90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80018F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018F94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80018F98: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80018F9C: lbu         $v0, 0x2B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2B);
    // 0x80018FA0: bne         $v0, $zero, L_80019014
    if (ctx->r2 != 0) {
        // 0x80018FA4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80019014;
    }
    // 0x80018FA4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80018FA8: sb          $v0, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r2;
    // 0x80018FAC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80018FB0: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    // 0x80018FB4: addiu       $v0, $zero, 0xB9
    ctx->r2 = ADD32(0, 0XB9);
    // 0x80018FB8: sb          $v0, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r2;
    // 0x80018FBC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80018FC0: addiu       $v0, $v0, 0xA60
    ctx->r2 = ADD32(ctx->r2, 0XA60);
    // 0x80018FC4: sw          $v0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r2;
    // 0x80018FC8: addiu       $v0, $v0, -0x800
    ctx->r2 = ADD32(ctx->r2, -0X800);
    // 0x80018FCC: sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // 0x80018FD0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80018FD4: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x80018FD8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80018FDC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80018FE0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80018FE4: lbu         $v0, 0x1714($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X1714);
    // 0x80018FE8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80018FEC: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x80018FF0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80018FF4: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x80018FF8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80018FFC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80019000: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80019004: lbu         $v0, 0x1715($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X1715);
    // 0x80019008: sb          $zero, 0x17($a0)
    MEM_B(0X17, ctx->r4) = 0;
    // 0x8001900C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80019010: sh          $v0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r2;
L_80019014:
    // 0x80019014: jal         0x8001D160
    // 0x80019018: nop

    func_8001D160(rdram, ctx);
        goto after_0;
    // 0x80019018: nop

    after_0:
    // 0x8001901C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80019020: jr          $ra
    // 0x80019024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80019024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80019028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019028: jr          $ra
    // 0x8001902C: nop

    return;
    // 0x8001902C: nop

;}
RECOMP_FUNC void func_80019030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019030: jr          $ra
    // 0x80019034: nop

    return;
    // 0x80019034: nop

;}
RECOMP_FUNC void func_80019038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001903C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80019040: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80019044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019048: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001904C: sltiu       $v0, $v1, 0x9
    ctx->r2 = ctx->r3 < 0X9 ? 1 : 0;
    // 0x80019050: beq         $v0, $zero, L_800192E0
    if (ctx->r2 == 0) {
        // 0x80019054: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800192E0;
    }
    // 0x80019054: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80019058: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001905C: addu        $at, $at, $v0
    gpr jr_addend_80019064 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80019060: lw          $v0, -0x30C8($at)
    ctx->r2 = ADD32(ctx->r1, -0X30C8);
    // 0x80019064: jr          $v0
    // 0x80019068: nop

    switch (jr_addend_80019064 >> 2) {
        case 0: goto L_8001906C; break;
        case 1: goto L_80019090; break;
        case 2: goto L_800190B0; break;
        case 3: goto L_80019100; break;
        case 4: goto L_8001916C; break;
        case 5: goto L_800191C0; break;
        case 6: goto L_80019214; break;
        case 7: goto L_80019268; break;
        case 8: goto L_800192C4; break;
        default: switch_error(__func__, 0x80019064, 0x800ACF38);
    }
    // 0x80019068: nop

L_8001906C:
    // 0x8001906C: lui         $at, 0x3F33
    ctx->r1 = S32(0X3F33 << 16);
    // 0x80019070: ori         $at, $at, 0x3333
    ctx->r1 = ctx->r1 | 0X3333;
    // 0x80019074: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80019078: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001907C: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x80019080: addiu       $v0, $zero, -0xA0
    ctx->r2 = ADD32(0, -0XA0);
    // 0x80019084: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x80019088: j           L_800192B8
    // 0x8001908C: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
        goto L_800192B8;
    // 0x8001908C: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
L_80019090:
    // 0x80019090: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80019094: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x80019098: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x8001909C: slti        $v0, $v0, -0x9
    ctx->r2 = SIGNED(ctx->r2) < -0X9 ? 1 : 0;
    // 0x800190A0: bne         $v0, $zero, L_800192E0
    if (ctx->r2 != 0) {
        // 0x800190A4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800192E0;
    }
    // 0x800190A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800190A8: j           L_800192E0
    // 0x800190AC: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
        goto L_800192E0;
    // 0x800190AC: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_800190B0:
    // 0x800190B0: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800190B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800190B8: ldc1        $f2, -0x30A0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X30A0);
    // 0x800190BC: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x800190C0: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x800190C4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800190C8: ldc1        $f4, -0x3098($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3098);
    // 0x800190CC: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x800190D0: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x800190D4: c.le.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d <= ctx->f2.d;
    // 0x800190D8: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x800190DC: nop

    // 0x800190E0: bc1f        L_800192E0
    if (!c1cs) {
        // 0x800190E4: swc1        $f0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
            goto L_800192E0;
    }
    // 0x800190E4: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x800190E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800190EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800190F0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800190F4: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x800190F8: j           L_800192B8
    // 0x800190FC: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
        goto L_800192B8;
    // 0x800190FC: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
L_80019100:
    // 0x80019100: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80019104: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019108: ldc1        $f2, -0x3090($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X3090);
    // 0x8001910C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80019110: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x80019114: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x80019118: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001911C: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80019120: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80019124: nop

    // 0x80019128: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001912C: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x80019130: blez        $v1, L_800192E0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80019134: sw          $v1, 0x4C($s0)
        MEM_W(0X4C, ctx->r16) = ctx->r3;
            goto L_800192E0;
    }
    // 0x80019134: sw          $v1, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r3;
    // 0x80019138: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8001913C: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x80019140: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80019144: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80019148: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x8001914C: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
    // 0x80019150: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x80019154: sw          $v0, -0x761C($at)
    MEM_W(-0X761C, ctx->r1) = ctx->r2;
    // 0x80019158: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x8001915C: jal         0x8000637C
    // 0x80019160: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8000637C(rdram, ctx);
        goto after_0;
    // 0x80019160: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_0:
    // 0x80019164: j           L_800192E0
    // 0x80019168: nop

        goto L_800192E0;
    // 0x80019168: nop

L_8001916C:
    // 0x8001916C: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80019170: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019174: ldc1        $f4, -0x3088($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3088);
    // 0x80019178: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001917C: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x80019180: add.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d + ctx->f4.d;
    // 0x80019184: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80019188: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001918C: sub.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f0.d - ctx->f4.d;
    // 0x80019190: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80019194: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80019198: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8001919C: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x800191A0: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
    // 0x800191A4: bne         $v0, $zero, L_800192E0
    if (ctx->r2 != 0) {
        // 0x800191A8: swc1        $f0, 0x38($s0)
        MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
            goto L_800192E0;
    }
    // 0x800191A8: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x800191AC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800191B0: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x800191B4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800191B8: j           L_800192E0
    // 0x800191BC: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
        goto L_800192E0;
    // 0x800191BC: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
L_800191C0:
    // 0x800191C0: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x800191C4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800191C8: ldc1        $f4, -0x3080($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3080);
    // 0x800191CC: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800191D0: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x800191D4: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x800191D8: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x800191DC: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x800191E0: add.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f0.d + ctx->f4.d;
    // 0x800191E4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800191E8: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x800191EC: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x800191F0: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x800191F4: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
    // 0x800191F8: bne         $v0, $zero, L_800192E0
    if (ctx->r2 != 0) {
        // 0x800191FC: swc1        $f0, 0x38($s0)
        MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
            goto L_800192E0;
    }
    // 0x800191FC: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80019200: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80019204: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x80019208: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8001920C: j           L_800192E0
    // 0x80019210: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
        goto L_800192E0;
    // 0x80019210: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
L_80019214:
    // 0x80019214: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80019218: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001921C: ldc1        $f4, -0x3078($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3078);
    // 0x80019220: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80019224: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x80019228: add.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d + ctx->f4.d;
    // 0x8001922C: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80019230: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80019234: sub.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f0.d - ctx->f4.d;
    // 0x80019238: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001923C: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80019240: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x80019244: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x80019248: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
    // 0x8001924C: bne         $v0, $zero, L_800192E0
    if (ctx->r2 != 0) {
        // 0x80019250: swc1        $f0, 0x38($s0)
        MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
            goto L_800192E0;
    }
    // 0x80019250: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80019254: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80019258: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x8001925C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80019260: j           L_800192E0
    // 0x80019264: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
        goto L_800192E0;
    // 0x80019264: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
L_80019268:
    // 0x80019268: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8001926C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019270: ldc1        $f4, -0x3070($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3070);
    // 0x80019274: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80019278: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001927C: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x80019280: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80019284: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80019288: add.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f0.d + ctx->f4.d;
    // 0x8001928C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80019290: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80019294: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x80019298: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001929C: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
    // 0x800192A0: bne         $v0, $zero, L_800192E0
    if (ctx->r2 != 0) {
        // 0x800192A4: swc1        $f0, 0x38($s0)
        MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
            goto L_800192E0;
    }
    // 0x800192A4: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x800192A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800192AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800192B0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800192B4: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_800192B8:
    // 0x800192B8: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x800192BC: j           L_800192E0
    // 0x800192C0: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
        goto L_800192E0;
    // 0x800192C0: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
L_800192C4:
    // 0x800192C4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x800192C8: lbu         $v1, 0x7B87($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B87);
    // 0x800192CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800192D0: bne         $v1, $v0, L_800192E0
    if (ctx->r3 != ctx->r2) {
        // 0x800192D4: nop
    
            goto L_800192E0;
    }
    // 0x800192D4: nop

    // 0x800192D8: jal         0x8001D564
    // 0x800192DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D564(rdram, ctx);
        goto after_1;
    // 0x800192DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
L_800192E0:
    // 0x800192E0: jal         0x8001D160
    // 0x800192E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D160(rdram, ctx);
        goto after_2;
    // 0x800192E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800192E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800192EC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800192F0: jr          $ra
    // 0x800192F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800192F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800192F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800192F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800192FC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80019300: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80019304: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80019308: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8001930C: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80019310: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80019314: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x80019318: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x8001931C: beq         $v0, $zero, L_800194CC
    if (ctx->r2 == 0) {
        // 0x80019320: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_800194CC;
    }
    // 0x80019320: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80019324: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019328: addu        $at, $at, $v0
    gpr jr_addend_80019330 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001932C: lw          $v0, -0x3068($at)
    ctx->r2 = ADD32(ctx->r1, -0X3068);
    // 0x80019330: jr          $v0
    // 0x80019334: nop

    switch (jr_addend_80019330 >> 2) {
        case 0: goto L_80019338; break;
        case 1: goto L_800193D0; break;
        case 2: goto L_800193F0; break;
        case 3: goto L_80019448; break;
        case 4: goto L_800194CC; break;
        default: switch_error(__func__, 0x80019330, 0x800ACF98);
    }
    // 0x80019334: nop

L_80019338:
    // 0x80019338: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001933C: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x80019340: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80019344: sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
    // 0x80019348: addiu       $v0, $zero, 0xB9
    ctx->r2 = ADD32(0, 0XB9);
    // 0x8001934C: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x80019350: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80019354: addiu       $v0, $v0, 0xA60
    ctx->r2 = ADD32(ctx->r2, 0XA60);
    // 0x80019358: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x8001935C: addiu       $v0, $v0, -0x800
    ctx->r2 = ADD32(ctx->r2, -0X800);
    // 0x80019360: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x80019364: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80019368: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x8001936C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80019370: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80019374: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80019378: lbu         $v0, 0x1714($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X1714);
    // 0x8001937C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80019380: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x80019384: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80019388: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x8001938C: lui         $at, 0x3F33
    ctx->r1 = S32(0X3F33 << 16);
    // 0x80019390: ori         $at, $at, 0x3333
    ctx->r1 = ctx->r1 | 0X3333;
    // 0x80019394: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80019398: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001939C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x800193A0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800193A4: lbu         $v1, 0x1715($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X1715);
    // 0x800193A8: addiu       $v0, $zero, -0xA0
    ctx->r2 = ADD32(0, -0XA0);
    // 0x800193AC: sb          $zero, 0x17($s0)
    MEM_B(0X17, ctx->r16) = 0;
    // 0x800193B0: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x800193B4: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x800193B8: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
    // 0x800193BC: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x800193C0: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x800193C4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800193C8: j           L_800194CC
    // 0x800193CC: sh          $v1, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r3;
        goto L_800194CC;
    // 0x800193CC: sh          $v1, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r3;
L_800193D0:
    // 0x800193D0: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x800193D4: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x800193D8: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x800193DC: slti        $v0, $v0, -0x9
    ctx->r2 = SIGNED(ctx->r2) < -0X9 ? 1 : 0;
    // 0x800193E0: bne         $v0, $zero, L_800194CC
    if (ctx->r2 != 0) {
        // 0x800193E4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800194CC;
    }
    // 0x800193E4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800193E8: j           L_800194CC
    // 0x800193EC: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
        goto L_800194CC;
    // 0x800193EC: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_800193F0:
    // 0x800193F0: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800193F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800193F8: ldc1        $f2, -0x3050($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X3050);
    // 0x800193FC: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80019400: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x80019404: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019408: ldc1        $f4, -0x3048($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3048);
    // 0x8001940C: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x80019410: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x80019414: c.le.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d <= ctx->f2.d;
    // 0x80019418: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x8001941C: nop

    // 0x80019420: bc1f        L_800194CC
    if (!c1cs) {
        // 0x80019424: swc1        $f0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
            goto L_800194CC;
    }
    // 0x80019424: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80019428: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001942C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80019430: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80019434: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x80019438: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x8001943C: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80019440: j           L_800194CC
    // 0x80019444: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
        goto L_800194CC;
    // 0x80019444: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
L_80019448:
    // 0x80019448: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8001944C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019450: ldc1        $f2, -0x3040($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X3040);
    // 0x80019454: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80019458: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8001945C: lw          $v1, 0x60($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X60);
    // 0x80019460: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x80019464: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80019468: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8001946C: nop

    // 0x80019470: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80019474: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x80019478: blez        $v1, L_800194CC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001947C: sw          $v1, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->r3;
            goto L_800194CC;
    }
    // 0x8001947C: sw          $v1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r3;
    // 0x80019480: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80019484: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x80019488: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8001948C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80019490: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
L_80019494:
    // 0x80019494: jal         0x8001D520
    // 0x80019498: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    func_8001D520(rdram, ctx);
        goto after_0;
    // 0x80019498: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    after_0:
    // 0x8001949C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800194A0: beql        $v1, $zero, L_800194C0
    if (ctx->r3 == 0) {
        // 0x800194A4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800194C0;
    }
    goto skip_0;
    // 0x800194A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800194A8: sb          $s3, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r19;
    // 0x800194AC: sb          $s2, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r18;
    // 0x800194B0: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x800194B4: sw          $s1, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r17;
    // 0x800194B8: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
    // 0x800194BC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800194C0:
    // 0x800194C0: slti        $v0, $s1, 0x3
    ctx->r2 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x800194C4: bne         $v0, $zero, L_80019494
    if (ctx->r2 != 0) {
        // 0x800194C8: nop
    
            goto L_80019494;
    }
    // 0x800194C8: nop

L_800194CC:
    // 0x800194CC: jal         0x8001D160
    // 0x800194D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D160(rdram, ctx);
        goto after_1;
    // 0x800194D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800194D4: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800194D8: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800194DC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800194E0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800194E4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800194E8: jr          $ra
    // 0x800194EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800194EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800194F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800194F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800194F4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800194F8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800194FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019500: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x80019504: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x80019508: beq         $v0, $zero, L_8001969C
    if (ctx->r2 == 0) {
        // 0x8001950C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8001969C;
    }
    // 0x8001950C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80019510: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019514: addu        $at, $at, $v0
    gpr jr_addend_8001951C = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80019518: lw          $v0, -0x3038($at)
    ctx->r2 = ADD32(ctx->r1, -0X3038);
    // 0x8001951C: jr          $v0
    // 0x80019520: nop

    switch (jr_addend_8001951C >> 2) {
        case 0: goto L_80019524; break;
        case 1: goto L_80019550; break;
        case 2: goto L_80019570; break;
        case 3: goto L_800195F4; break;
        case 4: goto L_80019674; break;
        case 5: goto L_80019694; break;
        default: switch_error(__func__, 0x8001951C, 0x800ACFC8);
    }
    // 0x80019520: nop

L_80019524:
    // 0x80019524: lui         $at, 0x3F33
    ctx->r1 = S32(0X3F33 << 16);
    // 0x80019528: ori         $at, $at, 0x3333
    ctx->r1 = ctx->r1 | 0X3333;
    // 0x8001952C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80019530: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80019534: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x80019538: addiu       $v0, $zero, -0xA0
    ctx->r2 = ADD32(0, -0XA0);
    // 0x8001953C: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x80019540: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x80019544: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80019548: j           L_8001969C
    // 0x8001954C: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
        goto L_8001969C;
    // 0x8001954C: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
L_80019550:
    // 0x80019550: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80019554: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x80019558: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x8001955C: slti        $v0, $v0, -0x9
    ctx->r2 = SIGNED(ctx->r2) < -0X9 ? 1 : 0;
    // 0x80019560: bne         $v0, $zero, L_8001969C
    if (ctx->r2 != 0) {
        // 0x80019564: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8001969C;
    }
    // 0x80019564: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80019568: j           L_8001969C
    // 0x8001956C: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
        goto L_8001969C;
    // 0x8001956C: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_80019570:
    // 0x80019570: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80019574: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019578: ldc1        $f2, -0x3020($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X3020);
    // 0x8001957C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80019580: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x80019584: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019588: ldc1        $f4, -0x3018($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X3018);
    // 0x8001958C: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x80019590: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x80019594: c.le.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d <= ctx->f2.d;
    // 0x80019598: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x8001959C: nop

    // 0x800195A0: bc1f        L_8001969C
    if (!c1cs) {
        // 0x800195A4: swc1        $f0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
            goto L_8001969C;
    }
    // 0x800195A4: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x800195A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800195AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800195B0: lw          $v1, 0x48($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X48);
    // 0x800195B4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800195B8: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x800195BC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800195C0: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x800195C4: bne         $v1, $v0, L_800195E0
    if (ctx->r3 != ctx->r2) {
        // 0x800195C8: swc1        $f0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
            goto L_800195E0;
    }
    // 0x800195C8: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x800195CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800195D0: jal         0x8001D470
    // 0x800195D4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8001D470(rdram, ctx);
        goto after_0;
    // 0x800195D4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_0:
    // 0x800195D8: j           L_8001969C
    // 0x800195DC: nop

        goto L_8001969C;
    // 0x800195DC: nop

L_800195E0:
    // 0x800195E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800195E4: jal         0x8001D470
    // 0x800195E8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_8001D470(rdram, ctx);
        goto after_1;
    // 0x800195E8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x800195EC: j           L_8001969C
    // 0x800195F0: nop

        goto L_8001969C;
    // 0x800195F0: nop

L_800195F4:
    // 0x800195F4: lw          $v1, 0x48($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X48);
    // 0x800195F8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800195FC: bne         $v1, $v0, L_80019610
    if (ctx->r3 != ctx->r2) {
        // 0x80019600: nop
    
            goto L_80019610;
    }
    // 0x80019600: nop

    // 0x80019604: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80019608: j           L_80019618
    // 0x8001960C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80019618;
    // 0x8001960C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80019610:
    // 0x80019610: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80019614: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80019618:
    // 0x80019618: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x8001961C: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80019620: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x80019624: bltzl       $v0, L_8001962C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80019628: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_8001962C;
    }
    goto skip_0;
    // 0x80019628: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_0:
L_8001962C:
    // 0x8001962C: bne         $v0, $v1, L_80019654
    if (ctx->r2 != ctx->r3) {
        // 0x80019630: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_80019654;
    }
    // 0x80019630: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80019634: lw          $v1, 0x48($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X48);
    // 0x80019638: bne         $v1, $v0, L_80019648
    if (ctx->r3 != ctx->r2) {
        // 0x8001963C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80019648;
    }
    // 0x8001963C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80019640: j           L_8001964C
    // 0x80019644: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
        goto L_8001964C;
    // 0x80019644: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_80019648:
    // 0x80019648: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
L_8001964C:
    // 0x8001964C: jal         0x8001D470
    // 0x80019650: nop

    func_8001D470(rdram, ctx);
        goto after_2;
    // 0x80019650: nop

    after_2:
L_80019654:
    // 0x80019654: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80019658: bltzl       $v0, L_80019660
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001965C: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_80019660;
    }
    goto skip_1;
    // 0x8001965C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_1:
L_80019660:
    // 0x80019660: slti        $v0, $v0, 0x11
    ctx->r2 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x80019664: bne         $v0, $zero, L_8001969C
    if (ctx->r2 != 0) {
        // 0x80019668: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8001969C;
    }
    // 0x80019668: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8001966C: j           L_8001969C
    // 0x80019670: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
        goto L_8001969C;
    // 0x80019670: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_80019674:
    // 0x80019674: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80019678: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001967C: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x80019680: slti        $v0, $v0, -0x32
    ctx->r2 = SIGNED(ctx->r2) < -0X32 ? 1 : 0;
    // 0x80019684: beq         $v0, $zero, L_8001969C
    if (ctx->r2 == 0) {
        // 0x80019688: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_8001969C;
    }
    // 0x80019688: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8001968C: j           L_8001969C
    // 0x80019690: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
        goto L_8001969C;
    // 0x80019690: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_80019694:
    // 0x80019694: jal         0x8001D564
    // 0x80019698: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D564(rdram, ctx);
        goto after_3;
    // 0x80019698: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
L_8001969C:
    // 0x8001969C: jal         0x8001D160
    // 0x800196A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D160(rdram, ctx);
        goto after_4;
    // 0x800196A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x800196A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800196A8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800196AC: jr          $ra
    // 0x800196B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800196B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800196B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800196B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800196B8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800196BC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800196C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800196C4: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x800196C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800196CC: beq         $v1, $v0, L_80019718
    if (ctx->r3 == ctx->r2) {
        // 0x800196D0: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80019718;
    }
    // 0x800196D0: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800196D4: beql        $v0, $zero, L_800196EC
    if (ctx->r2 == 0) {
        // 0x800196D8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800196EC;
    }
    goto skip_0;
    // 0x800196D8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x800196DC: beq         $v1, $zero, L_80019704
    if (ctx->r3 == 0) {
        // 0x800196E0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80019704;
    }
    // 0x800196E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800196E4: j           L_80019898
    // 0x800196E8: nop

        goto L_80019898;
    // 0x800196E8: nop

L_800196EC:
    // 0x800196EC: beq         $v1, $v0, L_800197C0
    if (ctx->r3 == ctx->r2) {
        // 0x800196F0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800197C0;
    }
    // 0x800196F0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800196F4: beq         $v1, $v0, L_8001985C
    if (ctx->r3 == ctx->r2) {
        // 0x800196F8: nop
    
            goto L_8001985C;
    }
    // 0x800196F8: nop

    // 0x800196FC: j           L_80019898
    // 0x80019700: nop

        goto L_80019898;
    // 0x80019700: nop

L_80019704:
    // 0x80019704: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x80019708: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // 0x8001970C: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x80019710: j           L_80019898
    // 0x80019714: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
        goto L_80019898;
    // 0x80019714: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
L_80019718:
    // 0x80019718: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x8001971C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80019720: bne         $v0, $zero, L_80019898
    if (ctx->r2 != 0) {
        // 0x80019724: sw          $v0, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->r2;
            goto L_80019898;
    }
    // 0x80019724: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x80019728: lw          $v0, 0x48($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X48);
    // 0x8001972C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80019730: bne         $v0, $v1, L_80019744
    if (ctx->r2 != ctx->r3) {
        // 0x80019734: sb          $a0, 0x2B($s0)
        MEM_B(0X2B, ctx->r16) = ctx->r4;
            goto L_80019744;
    }
    // 0x80019734: sb          $a0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r4;
    // 0x80019738: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001973C: j           L_80019748
    // 0x80019740: sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
        goto L_80019748;
    // 0x80019740: sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
L_80019744:
    // 0x80019744: sb          $a0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r4;
L_80019748:
    // 0x80019748: jal         0x8001D578
    // 0x8001974C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D578(rdram, ctx);
        goto after_0;
    // 0x8001974C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80019750: lw          $v1, 0x48($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X48);
    // 0x80019754: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80019758: bne         $v1, $v0, L_80019770
    if (ctx->r3 != ctx->r2) {
        // 0x8001975C: addiu       $v0, $zero, 0x740
        ctx->r2 = ADD32(0, 0X740);
            goto L_80019770;
    }
    // 0x8001975C: addiu       $v0, $zero, 0x740
    ctx->r2 = ADD32(0, 0X740);
    // 0x80019760: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80019764: sb          $v0, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r2;
    // 0x80019768: lw          $v1, 0x48($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X48);
    // 0x8001976C: addiu       $v0, $zero, 0x740
    ctx->r2 = ADD32(0, 0X740);
L_80019770:
    // 0x80019770: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x80019774: addiu       $v0, $zero, 0x3C0
    ctx->r2 = ADD32(0, 0X3C0);
    // 0x80019778: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001977C: addiu       $a0, $a0, 0x1720
    ctx->r4 = ADD32(ctx->r4, 0X1720);
    // 0x80019780: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x80019784: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80019788: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001978C: lw          $v1, 0x5C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X5C);
    // 0x80019790: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80019794: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80019798: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001979C: lb          $a1, 0x0($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X0);
    // 0x800197A0: jal         0x8001D470
    // 0x800197A4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D470(rdram, ctx);
        goto after_1;
    // 0x800197A4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800197A8: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x800197AC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800197B0: sw          $v1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r3;
    // 0x800197B4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800197B8: j           L_80019898
    // 0x800197BC: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
        goto L_80019898;
    // 0x800197BC: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
L_800197C0:
    // 0x800197C0: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x800197C4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800197C8: bne         $v0, $zero, L_80019890
    if (ctx->r2 != 0) {
        // 0x800197CC: sw          $v0, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->r2;
            goto L_80019890;
    }
    // 0x800197CC: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x800197D0: lw          $v1, 0x48($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X48);
    // 0x800197D4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800197D8: addiu       $a0, $a0, 0x1720
    ctx->r4 = ADD32(ctx->r4, 0X1720);
    // 0x800197DC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800197E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800197E4: lw          $v1, 0x5C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X5C);
    // 0x800197E8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800197EC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800197F0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800197F4: lb          $a1, 0x0($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X0);
    // 0x800197F8: beq         $a1, $zero, L_80019820
    if (ctx->r5 == 0) {
        // 0x800197FC: addiu       $a0, $zero, 0x40
        ctx->r4 = ADD32(0, 0X40);
            goto L_80019820;
    }
    // 0x800197FC: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x80019800: jal         0x8001D470
    // 0x80019804: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D470(rdram, ctx);
        goto after_2;
    // 0x80019804: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x80019808: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x8001980C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x80019810: sw          $v1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r3;
    // 0x80019814: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80019818: j           L_80019890
    // 0x8001981C: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
        goto L_80019890;
    // 0x8001981C: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
L_80019820:
    // 0x80019820: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x80019824: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80019828: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x8001982C: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x80019830: jal         0x8000637C
    // 0x80019834: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    func_8000637C(rdram, ctx);
        goto after_3;
    // 0x80019834: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    after_3:
    // 0x80019838: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x8001983C: jal         0x8000637C
    // 0x80019840: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_8000637C(rdram, ctx);
        goto after_4;
    // 0x80019840: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_4:
    // 0x80019844: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80019848: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001984C: sb          $v0, 0x7B87($at)
    MEM_B(0X7B87, ctx->r1) = ctx->r2;
    // 0x80019850: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80019854: j           L_80019890
    // 0x80019858: sb          $v0, 0x5585($at)
    MEM_B(0X5585, ctx->r1) = ctx->r2;
        goto L_80019890;
    // 0x80019858: sb          $v0, 0x5585($at)
    MEM_B(0X5585, ctx->r1) = ctx->r2;
L_8001985C:
    // 0x8001985C: lbu         $v1, 0x2F($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2F);
    // 0x80019860: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x80019864: bne         $v0, $zero, L_80019870
    if (ctx->r2 != 0) {
        // 0x80019868: addiu       $v0, $v1, -0x5
        ctx->r2 = ADD32(ctx->r3, -0X5);
            goto L_80019870;
    }
    // 0x80019868: addiu       $v0, $v1, -0x5
    ctx->r2 = ADD32(ctx->r3, -0X5);
    // 0x8001986C: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
L_80019870:
    // 0x80019870: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x80019874: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80019878: bne         $v0, $zero, L_80019890
    if (ctx->r2 != 0) {
        // 0x8001987C: sw          $v0, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->r2;
            goto L_80019890;
    }
    // 0x8001987C: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x80019880: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x80019884: sb          $zero, 0x7B87($at)
    MEM_B(0X7B87, ctx->r1) = 0;
    // 0x80019888: jal         0x8001D564
    // 0x8001988C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D564(rdram, ctx);
        goto after_5;
    // 0x8001988C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
L_80019890:
    // 0x80019890: jal         0x8001D160
    // 0x80019894: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D160(rdram, ctx);
        goto after_6;
    // 0x80019894: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
L_80019898:
    // 0x80019898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001989C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800198A0: jr          $ra
    // 0x800198A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800198A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800198A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800198A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800198AC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800198B0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800198B4: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800198B8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800198BC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800198C0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800198C4: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x800198C8: sltiu       $v0, $v1, 0xF
    ctx->r2 = ctx->r3 < 0XF ? 1 : 0;
    // 0x800198CC: beq         $v0, $zero, L_80019C7C
    if (ctx->r2 == 0) {
        // 0x800198D0: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80019C7C;
    }
    // 0x800198D0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800198D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800198D8: addu        $at, $at, $v0
    gpr jr_addend_800198E0 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800198DC: lw          $v0, -0x3010($at)
    ctx->r2 = ADD32(ctx->r1, -0X3010);
    // 0x800198E0: jr          $v0
    // 0x800198E4: nop

    switch (jr_addend_800198E0 >> 2) {
        case 0: goto L_800198E8; break;
        case 1: goto L_8001991C; break;
        case 2: goto L_8001993C; break;
        case 3: goto L_80019994; break;
        case 4: goto L_80019A00; break;
        case 5: goto L_80019A54; break;
        case 6: goto L_80019AA8; break;
        case 7: goto L_80019AFC; break;
        case 8: goto L_80019BAC; break;
        case 9: goto L_80019BD0; break;
        case 10: goto L_80019BE8; break;
        case 11: goto L_80019C30; break;
        case 12: goto L_80019C0C; break;
        case 13: goto L_80019C30; break;
        case 14: goto L_80019C5C; break;
        default: switch_error(__func__, 0x800198E0, 0x800ACFF0);
    }
    // 0x800198E4: nop

L_800198E8:
    // 0x800198E8: lui         $at, 0x3F33
    ctx->r1 = S32(0X3F33 << 16);
    // 0x800198EC: ori         $at, $at, 0x3333
    ctx->r1 = ctx->r1 | 0X3333;
    // 0x800198F0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800198F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800198F8: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x800198FC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80019900: sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
    // 0x80019904: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80019908: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x8001990C: addiu       $v0, $zero, -0xA0
    ctx->r2 = ADD32(0, -0XA0);
    // 0x80019910: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x80019914: j           L_80019988
    // 0x80019918: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
        goto L_80019988;
    // 0x80019918: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
L_8001991C:
    // 0x8001991C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80019920: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x80019924: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x80019928: slti        $v0, $v0, -0x9
    ctx->r2 = SIGNED(ctx->r2) < -0X9 ? 1 : 0;
    // 0x8001992C: bne         $v0, $zero, L_80019C7C
    if (ctx->r2 != 0) {
        // 0x80019930: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80019C7C;
    }
    // 0x80019930: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80019934: j           L_80019C7C
    // 0x80019938: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
        goto L_80019C7C;
    // 0x80019938: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_8001993C:
    // 0x8001993C: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80019940: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019944: ldc1        $f2, -0x2FD0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2FD0);
    // 0x80019948: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001994C: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x80019950: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019954: ldc1        $f4, -0x2FC8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2FC8);
    // 0x80019958: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001995C: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x80019960: c.le.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d <= ctx->f2.d;
    // 0x80019964: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80019968: nop

    // 0x8001996C: bc1f        L_80019C7C
    if (!c1cs) {
        // 0x80019970: swc1        $f0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
            goto L_80019C7C;
    }
    // 0x80019970: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80019974: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019978: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001997C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80019980: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x80019984: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
L_80019988:
    // 0x80019988: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x8001998C: j           L_80019C7C
    // 0x80019990: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
        goto L_80019C7C;
    // 0x80019990: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
L_80019994:
    // 0x80019994: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80019998: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001999C: ldc1        $f2, -0x2FC0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2FC0);
    // 0x800199A0: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x800199A4: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x800199A8: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x800199AC: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x800199B0: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800199B4: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x800199B8: nop

    // 0x800199BC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800199C0: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x800199C4: blez        $v1, L_80019C7C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800199C8: sw          $v1, 0x4C($s0)
        MEM_W(0X4C, ctx->r16) = ctx->r3;
            goto L_80019C7C;
    }
    // 0x800199C8: sw          $v1, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r3;
    // 0x800199CC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800199D0: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x800199D4: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800199D8: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x800199DC: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x800199E0: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
    // 0x800199E4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x800199E8: sw          $v0, -0x761C($at)
    MEM_W(-0X761C, ctx->r1) = ctx->r2;
    // 0x800199EC: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x800199F0: jal         0x8000637C
    // 0x800199F4: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8000637C(rdram, ctx);
        goto after_0;
    // 0x800199F4: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_0:
    // 0x800199F8: j           L_80019C7C
    // 0x800199FC: nop

        goto L_80019C7C;
    // 0x800199FC: nop

L_80019A00:
    // 0x80019A00: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80019A04: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019A08: ldc1        $f4, -0x2FB8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2FB8);
    // 0x80019A0C: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80019A10: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x80019A14: add.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d + ctx->f4.d;
    // 0x80019A18: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80019A1C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80019A20: sub.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f0.d - ctx->f4.d;
    // 0x80019A24: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80019A28: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80019A2C: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x80019A30: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x80019A34: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
    // 0x80019A38: bne         $v0, $zero, L_80019C7C
    if (ctx->r2 != 0) {
        // 0x80019A3C: swc1        $f0, 0x38($s0)
        MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
            goto L_80019C7C;
    }
    // 0x80019A3C: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80019A40: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80019A44: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x80019A48: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80019A4C: j           L_80019C7C
    // 0x80019A50: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
        goto L_80019C7C;
    // 0x80019A50: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
L_80019A54:
    // 0x80019A54: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80019A58: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019A5C: ldc1        $f4, -0x2FB0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2FB0);
    // 0x80019A60: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80019A64: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x80019A68: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x80019A6C: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80019A70: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80019A74: add.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f0.d + ctx->f4.d;
    // 0x80019A78: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80019A7C: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80019A80: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x80019A84: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x80019A88: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
    // 0x80019A8C: bne         $v0, $zero, L_80019C7C
    if (ctx->r2 != 0) {
        // 0x80019A90: swc1        $f0, 0x38($s0)
        MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
            goto L_80019C7C;
    }
    // 0x80019A90: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80019A94: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80019A98: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x80019A9C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80019AA0: j           L_80019C7C
    // 0x80019AA4: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
        goto L_80019C7C;
    // 0x80019AA4: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
L_80019AA8:
    // 0x80019AA8: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80019AAC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019AB0: ldc1        $f4, -0x2FA8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2FA8);
    // 0x80019AB4: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80019AB8: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x80019ABC: add.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d + ctx->f4.d;
    // 0x80019AC0: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80019AC4: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80019AC8: sub.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f0.d - ctx->f4.d;
    // 0x80019ACC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80019AD0: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80019AD4: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x80019AD8: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x80019ADC: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
    // 0x80019AE0: bne         $v0, $zero, L_80019C7C
    if (ctx->r2 != 0) {
        // 0x80019AE4: swc1        $f0, 0x38($s0)
        MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
            goto L_80019C7C;
    }
    // 0x80019AE4: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80019AE8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80019AEC: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x80019AF0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80019AF4: j           L_80019C7C
    // 0x80019AF8: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
        goto L_80019C7C;
    // 0x80019AF8: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
L_80019AFC:
    // 0x80019AFC: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80019B00: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019B04: ldc1        $f4, -0x2FA0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2FA0);
    // 0x80019B08: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80019B0C: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x80019B10: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x80019B14: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80019B18: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80019B1C: add.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f0.d + ctx->f4.d;
    // 0x80019B20: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80019B24: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80019B28: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x80019B2C: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x80019B30: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
    // 0x80019B34: bne         $v0, $zero, L_80019C7C
    if (ctx->r2 != 0) {
        // 0x80019B38: swc1        $f0, 0x38($s0)
        MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
            goto L_80019C7C;
    }
    // 0x80019B38: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80019B3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019B40: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80019B44: lw          $v1, 0x48($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X48);
    // 0x80019B48: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80019B4C: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x80019B50: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80019B54: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80019B58: bne         $v1, $v0, L_80019C7C
    if (ctx->r3 != ctx->r2) {
        // 0x80019B5C: swc1        $f0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
            goto L_80019C7C;
    }
    // 0x80019B5C: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80019B60: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80019B64: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80019B68: addiu       $s2, $zero, 0x28
    ctx->r18 = ADD32(0, 0X28);
L_80019B6C:
    // 0x80019B6C: jal         0x8001D520
    // 0x80019B70: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    func_8001D520(rdram, ctx);
        goto after_1;
    // 0x80019B70: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    after_1:
    // 0x80019B74: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80019B78: beql        $v1, $zero, L_80019B98
    if (ctx->r3 == 0) {
        // 0x80019B7C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80019B98;
    }
    goto skip_0;
    // 0x80019B7C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80019B80: sb          $s3, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r19;
    // 0x80019B84: sb          $s2, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r18;
    // 0x80019B88: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x80019B8C: sw          $s1, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r17;
    // 0x80019B90: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
    // 0x80019B94: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80019B98:
    // 0x80019B98: slti        $v0, $s1, 0x5
    ctx->r2 = SIGNED(ctx->r17) < 0X5 ? 1 : 0;
    // 0x80019B9C: beq         $v0, $zero, L_80019C7C
    if (ctx->r2 == 0) {
        // 0x80019BA0: nop
    
            goto L_80019C7C;
    }
    // 0x80019BA0: nop

    // 0x80019BA4: j           L_80019B6C
    // 0x80019BA8: nop

        goto L_80019B6C;
    // 0x80019BA8: nop

L_80019BAC:
    // 0x80019BAC: lbu         $v0, 0x2F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2F);
    // 0x80019BB0: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x80019BB4: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x80019BB8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80019BBC: sltiu       $v0, $v0, 0x64
    ctx->r2 = ctx->r2 < 0X64 ? 1 : 0;
    // 0x80019BC0: beq         $v0, $zero, L_80019C7C
    if (ctx->r2 == 0) {
        // 0x80019BC4: nop
    
            goto L_80019C7C;
    }
    // 0x80019BC4: nop

    // 0x80019BC8: j           L_80019C4C
    // 0x80019BCC: nop

        goto L_80019C4C;
    // 0x80019BCC: nop

L_80019BD0:
    // 0x80019BD0: lbu         $v0, 0x2F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2F);
    // 0x80019BD4: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80019BD8: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x80019BDC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80019BE0: j           L_80019C44
    // 0x80019BE4: sltiu       $v0, $v0, 0xC9
    ctx->r2 = ctx->r2 < 0XC9 ? 1 : 0;
        goto L_80019C44;
    // 0x80019BE4: sltiu       $v0, $v0, 0xC9
    ctx->r2 = ctx->r2 < 0XC9 ? 1 : 0;
L_80019BE8:
    // 0x80019BE8: lbu         $v0, 0x2F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2F);
    // 0x80019BEC: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x80019BF0: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x80019BF4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80019BF8: sltiu       $v0, $v0, 0x32
    ctx->r2 = ctx->r2 < 0X32 ? 1 : 0;
    // 0x80019BFC: beq         $v0, $zero, L_80019C7C
    if (ctx->r2 == 0) {
        // 0x80019C00: nop
    
            goto L_80019C7C;
    }
    // 0x80019C00: nop

    // 0x80019C04: j           L_80019C4C
    // 0x80019C08: nop

        goto L_80019C4C;
    // 0x80019C08: nop

L_80019C0C:
    // 0x80019C0C: lbu         $v0, 0x2F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2F);
    // 0x80019C10: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x80019C14: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x80019C18: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80019C1C: sltiu       $v0, $v0, 0x32
    ctx->r2 = ctx->r2 < 0X32 ? 1 : 0;
    // 0x80019C20: beq         $v0, $zero, L_80019C7C
    if (ctx->r2 == 0) {
        // 0x80019C24: nop
    
            goto L_80019C7C;
    }
    // 0x80019C24: nop

    // 0x80019C28: j           L_80019C4C
    // 0x80019C2C: nop

        goto L_80019C4C;
    // 0x80019C2C: nop

L_80019C30:
    // 0x80019C30: lbu         $v0, 0x2F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2F);
    // 0x80019C34: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80019C38: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x80019C3C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80019C40: sltiu       $v0, $v0, 0x65
    ctx->r2 = ctx->r2 < 0X65 ? 1 : 0;
L_80019C44:
    // 0x80019C44: bne         $v0, $zero, L_80019C7C
    if (ctx->r2 != 0) {
        // 0x80019C48: nop
    
            goto L_80019C7C;
    }
    // 0x80019C48: nop

L_80019C4C:
    // 0x80019C4C: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x80019C50: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80019C54: j           L_80019C7C
    // 0x80019C58: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
        goto L_80019C7C;
    // 0x80019C58: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_80019C5C:
    // 0x80019C5C: lbu         $v1, 0x2F($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2F);
    // 0x80019C60: sltiu       $v0, $v1, 0xB
    ctx->r2 = ctx->r3 < 0XB ? 1 : 0;
    // 0x80019C64: bne         $v0, $zero, L_80019C74
    if (ctx->r2 != 0) {
        // 0x80019C68: addiu       $v0, $v1, -0xA
        ctx->r2 = ADD32(ctx->r3, -0XA);
            goto L_80019C74;
    }
    // 0x80019C68: addiu       $v0, $v1, -0xA
    ctx->r2 = ADD32(ctx->r3, -0XA);
    // 0x80019C6C: j           L_80019C7C
    // 0x80019C70: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
        goto L_80019C7C;
    // 0x80019C70: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
L_80019C74:
    // 0x80019C74: jal         0x8001D564
    // 0x80019C78: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D564(rdram, ctx);
        goto after_2;
    // 0x80019C78: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
L_80019C7C:
    // 0x80019C7C: jal         0x8001D160
    // 0x80019C80: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D160(rdram, ctx);
        goto after_3;
    // 0x80019C80: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80019C84: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80019C88: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80019C8C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80019C90: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80019C94: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80019C98: jr          $ra
    // 0x80019C9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80019C9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80019CA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019CA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019CA4: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80019CA8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80019CAC: lbu         $v1, 0x2B($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X2B);
    // 0x80019CB0: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x80019CB4: beq         $v0, $zero, L_80019E20
    if (ctx->r2 == 0) {
        // 0x80019CB8: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80019E20;
    }
    // 0x80019CB8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80019CBC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019CC0: addu        $at, $at, $v0
    gpr jr_addend_80019CC8 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80019CC4: lw          $v0, -0x2F98($at)
    ctx->r2 = ADD32(ctx->r1, -0X2F98);
    // 0x80019CC8: jr          $v0
    // 0x80019CCC: nop

    switch (jr_addend_80019CC8 >> 2) {
        case 0: goto L_80019CD0; break;
        case 1: goto L_80019D68; break;
        case 2: goto L_80019D88; break;
        case 3: goto L_80019DE0; break;
        case 4: goto L_80019E20; break;
        default: switch_error(__func__, 0x80019CC8, 0x800AD068);
    }
    // 0x80019CCC: nop

L_80019CD0:
    // 0x80019CD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80019CD4: sb          $v0, 0x2B($a1)
    MEM_B(0X2B, ctx->r5) = ctx->r2;
    // 0x80019CD8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80019CDC: sb          $v0, 0x2A($a1)
    MEM_B(0X2A, ctx->r5) = ctx->r2;
    // 0x80019CE0: addiu       $v0, $zero, 0xB9
    ctx->r2 = ADD32(0, 0XB9);
    // 0x80019CE4: sb          $v0, 0x2F($a1)
    MEM_B(0X2F, ctx->r5) = ctx->r2;
    // 0x80019CE8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80019CEC: addiu       $v0, $v0, 0xA60
    ctx->r2 = ADD32(ctx->r2, 0XA60);
    // 0x80019CF0: sw          $v0, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r2;
    // 0x80019CF4: addiu       $v0, $v0, -0x800
    ctx->r2 = ADD32(ctx->r2, -0X800);
    // 0x80019CF8: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80019CFC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80019D00: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x80019D04: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80019D08: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80019D0C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80019D10: lbu         $v0, 0x1714($at)
    ctx->r2 = MEM_BU(ctx->r1, 0X1714);
    // 0x80019D14: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80019D18: sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // 0x80019D1C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x80019D20: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x80019D24: lui         $at, 0x3F33
    ctx->r1 = S32(0X3F33 << 16);
    // 0x80019D28: ori         $at, $at, 0x3333
    ctx->r1 = ctx->r1 | 0X3333;
    // 0x80019D2C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80019D30: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80019D34: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80019D38: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80019D3C: lbu         $v1, 0x1715($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X1715);
    // 0x80019D40: addiu       $v0, $zero, -0xA0
    ctx->r2 = ADD32(0, -0XA0);
    // 0x80019D44: sb          $zero, 0x17($a1)
    MEM_B(0X17, ctx->r5) = 0;
    // 0x80019D48: swc1        $f0, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f0.u32l;
    // 0x80019D4C: swc1        $f0, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f0.u32l;
    // 0x80019D50: sw          $zero, 0x4C($a1)
    MEM_W(0X4C, ctx->r5) = 0;
    // 0x80019D54: sw          $zero, 0x50($a1)
    MEM_W(0X50, ctx->r5) = 0;
    // 0x80019D58: sw          $v0, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->r2;
    // 0x80019D5C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80019D60: j           L_80019E20
    // 0x80019D64: sh          $v1, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r3;
        goto L_80019E20;
    // 0x80019D64: sh          $v1, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r3;
L_80019D68:
    // 0x80019D68: lw          $v0, 0x60($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X60);
    // 0x80019D6C: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x80019D70: sw          $v0, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->r2;
    // 0x80019D74: slti        $v0, $v0, -0x9
    ctx->r2 = SIGNED(ctx->r2) < -0X9 ? 1 : 0;
    // 0x80019D78: bne         $v0, $zero, L_80019E20
    if (ctx->r2 != 0) {
        // 0x80019D7C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80019E20;
    }
    // 0x80019D7C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80019D80: j           L_80019E20
    // 0x80019D84: sb          $v0, 0x2B($a1)
    MEM_B(0X2B, ctx->r5) = ctx->r2;
        goto L_80019E20;
    // 0x80019D84: sb          $v0, 0x2B($a1)
    MEM_B(0X2B, ctx->r5) = ctx->r2;
L_80019D88:
    // 0x80019D88: lwc1        $f0, 0x38($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X38);
    // 0x80019D8C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019D90: ldc1        $f2, -0x2F80($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2F80);
    // 0x80019D94: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80019D98: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x80019D9C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019DA0: ldc1        $f4, -0x2F78($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2F78);
    // 0x80019DA4: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x80019DA8: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x80019DAC: c.le.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d <= ctx->f2.d;
    // 0x80019DB0: swc1        $f0, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f0.u32l;
    // 0x80019DB4: nop

    // 0x80019DB8: bc1f        L_80019E20
    if (!c1cs) {
        // 0x80019DBC: swc1        $f0, 0x34($a1)
        MEM_W(0X34, ctx->r5) = ctx->f0.u32l;
            goto L_80019E20;
    }
    // 0x80019DBC: swc1        $f0, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f0.u32l;
    // 0x80019DC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019DC4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80019DC8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80019DCC: sb          $v0, 0x2B($a1)
    MEM_B(0X2B, ctx->r5) = ctx->r2;
    // 0x80019DD0: sw          $zero, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = 0;
    // 0x80019DD4: swc1        $f0, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f0.u32l;
    // 0x80019DD8: j           L_80019E20
    // 0x80019DDC: swc1        $f0, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f0.u32l;
        goto L_80019E20;
    // 0x80019DDC: swc1        $f0, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f0.u32l;
L_80019DE0:
    // 0x80019DE0: lwc1        $f0, 0x3C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x80019DE4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019DE8: ldc1        $f2, -0x2F70($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2F70);
    // 0x80019DEC: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80019DF0: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x80019DF4: lw          $v1, 0x60($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X60);
    // 0x80019DF8: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x80019DFC: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80019E00: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x80019E04: nop

    // 0x80019E08: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80019E0C: swc1        $f0, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f0.u32l;
    // 0x80019E10: blez        $v1, L_80019E20
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80019E14: sw          $v1, 0x60($a1)
        MEM_W(0X60, ctx->r5) = ctx->r3;
            goto L_80019E20;
    }
    // 0x80019E14: sw          $v1, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->r3;
    // 0x80019E18: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80019E1C: sb          $v0, 0x2B($a1)
    MEM_B(0X2B, ctx->r5) = ctx->r2;
L_80019E20:
    // 0x80019E20: jal         0x8001D160
    // 0x80019E24: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    func_8001D160(rdram, ctx);
        goto after_0;
    // 0x80019E24: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    after_0:
    // 0x80019E28: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80019E2C: jr          $ra
    // 0x80019E30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80019E30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80019E34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019E34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019E38: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80019E3C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80019E40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019E44: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x80019E48: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x80019E4C: beq         $v0, $zero, L_80019FA8
    if (ctx->r2 == 0) {
        // 0x80019E50: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80019FA8;
    }
    // 0x80019E50: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80019E54: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019E58: addu        $at, $at, $v0
    gpr jr_addend_80019E60 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80019E5C: lw          $v0, -0x2F68($at)
    ctx->r2 = ADD32(ctx->r1, -0X2F68);
    // 0x80019E60: jr          $v0
    // 0x80019E64: nop

    switch (jr_addend_80019E60 >> 2) {
        case 0: goto L_80019E68; break;
        case 1: goto L_80019E94; break;
        case 2: goto L_80019EB4; break;
        case 3: goto L_80019F38; break;
        case 4: goto L_80019F80; break;
        case 5: goto L_80019FA0; break;
        default: switch_error(__func__, 0x80019E60, 0x800AD098);
    }
    // 0x80019E64: nop

L_80019E68:
    // 0x80019E68: lui         $at, 0x3F33
    ctx->r1 = S32(0X3F33 << 16);
    // 0x80019E6C: ori         $at, $at, 0x3333
    ctx->r1 = ctx->r1 | 0X3333;
    // 0x80019E70: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80019E74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80019E78: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x80019E7C: addiu       $v0, $zero, -0xA0
    ctx->r2 = ADD32(0, -0XA0);
    // 0x80019E80: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x80019E84: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x80019E88: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80019E8C: j           L_80019FA8
    // 0x80019E90: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
        goto L_80019FA8;
    // 0x80019E90: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
L_80019E94:
    // 0x80019E94: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80019E98: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x80019E9C: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x80019EA0: slti        $v0, $v0, -0x9
    ctx->r2 = SIGNED(ctx->r2) < -0X9 ? 1 : 0;
    // 0x80019EA4: bne         $v0, $zero, L_80019FA8
    if (ctx->r2 != 0) {
        // 0x80019EA8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80019FA8;
    }
    // 0x80019EA8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80019EAC: j           L_80019FA8
    // 0x80019EB0: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
        goto L_80019FA8;
    // 0x80019EB0: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_80019EB4:
    // 0x80019EB4: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80019EB8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019EBC: ldc1        $f2, -0x2F50($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2F50);
    // 0x80019EC0: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x80019EC4: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x80019EC8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019ECC: ldc1        $f4, -0x2F48($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2F48);
    // 0x80019ED0: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x80019ED4: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x80019ED8: c.le.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d <= ctx->f2.d;
    // 0x80019EDC: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80019EE0: nop

    // 0x80019EE4: bc1f        L_80019FA8
    if (!c1cs) {
        // 0x80019EE8: swc1        $f0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
            goto L_80019FA8;
    }
    // 0x80019EE8: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80019EEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019EF0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80019EF4: lw          $v1, 0x48($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X48);
    // 0x80019EF8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80019EFC: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x80019F00: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80019F04: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80019F08: bne         $v1, $v0, L_80019F24
    if (ctx->r3 != ctx->r2) {
        // 0x80019F0C: swc1        $f0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
            goto L_80019F24;
    }
    // 0x80019F0C: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80019F10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80019F14: jal         0x8001D470
    // 0x80019F18: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8001D470(rdram, ctx);
        goto after_0;
    // 0x80019F18: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x80019F1C: j           L_80019FA8
    // 0x80019F20: nop

        goto L_80019FA8;
    // 0x80019F20: nop

L_80019F24:
    // 0x80019F24: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80019F28: jal         0x8001D470
    // 0x80019F2C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8001D470(rdram, ctx);
        goto after_1;
    // 0x80019F2C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_1:
    // 0x80019F30: j           L_80019FA8
    // 0x80019F34: nop

        goto L_80019FA8;
    // 0x80019F34: nop

L_80019F38:
    // 0x80019F38: lw          $v1, 0x48($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X48);
    // 0x80019F3C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80019F40: bne         $v1, $v0, L_80019F54
    if (ctx->r3 != ctx->r2) {
        // 0x80019F44: nop
    
            goto L_80019F54;
    }
    // 0x80019F44: nop

    // 0x80019F48: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80019F4C: j           L_80019F5C
    // 0x80019F50: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80019F5C;
    // 0x80019F50: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80019F54:
    // 0x80019F54: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80019F58: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80019F5C:
    // 0x80019F5C: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x80019F60: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80019F64: bltzl       $v0, L_80019F6C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80019F68: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_80019F6C;
    }
    goto skip_0;
    // 0x80019F68: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_0:
L_80019F6C:
    // 0x80019F6C: slti        $v0, $v0, 0x11
    ctx->r2 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x80019F70: bne         $v0, $zero, L_80019FA8
    if (ctx->r2 != 0) {
        // 0x80019F74: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80019FA8;
    }
    // 0x80019F74: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80019F78: j           L_80019FA8
    // 0x80019F7C: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
        goto L_80019FA8;
    // 0x80019F7C: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_80019F80:
    // 0x80019F80: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80019F84: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80019F88: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x80019F8C: slti        $v0, $v0, -0x32
    ctx->r2 = SIGNED(ctx->r2) < -0X32 ? 1 : 0;
    // 0x80019F90: beq         $v0, $zero, L_80019FA8
    if (ctx->r2 == 0) {
        // 0x80019F94: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_80019FA8;
    }
    // 0x80019F94: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80019F98: j           L_80019FA8
    // 0x80019F9C: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
        goto L_80019FA8;
    // 0x80019F9C: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_80019FA0:
    // 0x80019FA0: jal         0x8001D564
    // 0x80019FA4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D564(rdram, ctx);
        goto after_2;
    // 0x80019FA4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
L_80019FA8:
    // 0x80019FA8: jal         0x8001D160
    // 0x80019FAC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D160(rdram, ctx);
        goto after_3;
    // 0x80019FAC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80019FB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019FB4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80019FB8: jr          $ra
    // 0x80019FBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80019FBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80019FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019FC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80019FC4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80019FC8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80019FCC: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80019FD0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80019FD4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80019FD8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80019FDC: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x80019FE0: sltiu       $v0, $v1, 0xB
    ctx->r2 = ctx->r3 < 0XB ? 1 : 0;
    // 0x80019FE4: beq         $v0, $zero, L_8001A280
    if (ctx->r2 == 0) {
        // 0x80019FE8: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8001A280;
    }
    // 0x80019FE8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80019FEC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80019FF0: addu        $at, $at, $v0
    gpr jr_addend_80019FF8 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80019FF4: lw          $v0, -0x2F40($at)
    ctx->r2 = ADD32(ctx->r1, -0X2F40);
    // 0x80019FF8: jr          $v0
    // 0x80019FFC: nop

    switch (jr_addend_80019FF8 >> 2) {
        case 0: goto L_8001A000; break;
        case 1: goto L_8001A058; break;
        case 2: goto L_8001A080; break;
        case 3: goto L_8001A0A8; break;
        case 4: goto L_8001A0D0; break;
        case 5: goto L_8001A0F8; break;
        case 6: goto L_8001A120; break;
        case 7: goto L_8001A148; break;
        case 8: goto L_8001A194; break;
        case 9: goto L_8001A250; break;
        case 10: goto L_8001A278; break;
        default: switch_error(__func__, 0x80019FF8, 0x800AD0C0);
    }
    // 0x80019FFC: nop

L_8001A000:
    // 0x8001A000: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001A004: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001A008: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001A00C: sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
    // 0x8001A010: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001A014: jal         0x8001D578
    // 0x8001A018: sb          $v1, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r3;
    func_8001D578(rdram, ctx);
        goto after_0;
    // 0x8001A018: sb          $v1, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r3;
    after_0:
    // 0x8001A01C: lw          $v1, 0x48($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X48);
    // 0x8001A020: addiu       $v0, $zero, 0x520
    ctx->r2 = ADD32(0, 0X520);
    // 0x8001A024: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x8001A028: addiu       $v0, $zero, 0x724
    ctx->r2 = ADD32(0, 0X724);
    // 0x8001A02C: sb          $zero, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = 0;
    // 0x8001A030: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x8001A034: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001A038: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x8001A03C: lb          $a1, 0x1734($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X1734);
    // 0x8001A040: jal         0x8001D470
    // 0x8001A044: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D470(rdram, ctx);
        goto after_1;
    // 0x8001A044: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8001A048: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8001A04C: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x8001A050: j           L_8001A280
    // 0x8001A054: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
        goto L_8001A280;
    // 0x8001A054: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
L_8001A058:
    // 0x8001A058: lbu         $v0, 0x2F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2F);
    // 0x8001A05C: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x8001A060: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x8001A064: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001A068: sltiu       $v0, $v0, 0x97
    ctx->r2 = ctx->r2 < 0X97 ? 1 : 0;
    // 0x8001A06C: bne         $v0, $zero, L_8001A280
    if (ctx->r2 != 0) {
        // 0x8001A070: nop
    
            goto L_8001A280;
    }
    // 0x8001A070: nop

    // 0x8001A074: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001A078: j           L_8001A270
    // 0x8001A07C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8001A270;
    // 0x8001A07C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001A080:
    // 0x8001A080: lbu         $v0, 0x2F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2F);
    // 0x8001A084: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x8001A088: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x8001A08C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001A090: sltiu       $v0, $v0, 0x32
    ctx->r2 = ctx->r2 < 0X32 ? 1 : 0;
    // 0x8001A094: beq         $v0, $zero, L_8001A280
    if (ctx->r2 == 0) {
        // 0x8001A098: nop
    
            goto L_8001A280;
    }
    // 0x8001A098: nop

    // 0x8001A09C: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001A0A0: j           L_8001A270
    // 0x8001A0A4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8001A270;
    // 0x8001A0A4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001A0A8:
    // 0x8001A0A8: lbu         $v0, 0x2F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2F);
    // 0x8001A0AC: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x8001A0B0: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x8001A0B4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001A0B8: sltiu       $v0, $v0, 0xC9
    ctx->r2 = ctx->r2 < 0XC9 ? 1 : 0;
    // 0x8001A0BC: bne         $v0, $zero, L_8001A280
    if (ctx->r2 != 0) {
        // 0x8001A0C0: nop
    
            goto L_8001A280;
    }
    // 0x8001A0C0: nop

    // 0x8001A0C4: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001A0C8: j           L_8001A270
    // 0x8001A0CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8001A270;
    // 0x8001A0CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001A0D0:
    // 0x8001A0D0: lbu         $v0, 0x2F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2F);
    // 0x8001A0D4: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x8001A0D8: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x8001A0DC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001A0E0: sltiu       $v0, $v0, 0x96
    ctx->r2 = ctx->r2 < 0X96 ? 1 : 0;
    // 0x8001A0E4: beq         $v0, $zero, L_8001A280
    if (ctx->r2 == 0) {
        // 0x8001A0E8: nop
    
            goto L_8001A280;
    }
    // 0x8001A0E8: nop

    // 0x8001A0EC: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001A0F0: j           L_8001A270
    // 0x8001A0F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8001A270;
    // 0x8001A0F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001A0F8:
    // 0x8001A0F8: lbu         $v0, 0x2F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2F);
    // 0x8001A0FC: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x8001A100: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x8001A104: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001A108: sltiu       $v0, $v0, 0xC9
    ctx->r2 = ctx->r2 < 0XC9 ? 1 : 0;
    // 0x8001A10C: bne         $v0, $zero, L_8001A280
    if (ctx->r2 != 0) {
        // 0x8001A110: nop
    
            goto L_8001A280;
    }
    // 0x8001A110: nop

    // 0x8001A114: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001A118: j           L_8001A270
    // 0x8001A11C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8001A270;
    // 0x8001A11C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001A120:
    // 0x8001A120: lbu         $v0, 0x2F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2F);
    // 0x8001A124: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x8001A128: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x8001A12C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001A130: sltiu       $v0, $v0, 0x96
    ctx->r2 = ctx->r2 < 0X96 ? 1 : 0;
    // 0x8001A134: beq         $v0, $zero, L_8001A280
    if (ctx->r2 == 0) {
        // 0x8001A138: nop
    
            goto L_8001A280;
    }
    // 0x8001A138: nop

    // 0x8001A13C: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001A140: j           L_8001A270
    // 0x8001A144: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8001A270;
    // 0x8001A144: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001A148:
    // 0x8001A148: lbu         $v1, 0x2F($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2F);
    // 0x8001A14C: sltiu       $v0, $v1, 0xF0
    ctx->r2 = ctx->r3 < 0XF0 ? 1 : 0;
    // 0x8001A150: beq         $v0, $zero, L_8001A160
    if (ctx->r2 == 0) {
        // 0x8001A154: addiu       $v0, $v1, 0xA
        ctx->r2 = ADD32(ctx->r3, 0XA);
            goto L_8001A160;
    }
    // 0x8001A154: addiu       $v0, $v1, 0xA
    ctx->r2 = ADD32(ctx->r3, 0XA);
    // 0x8001A158: j           L_8001A280
    // 0x8001A15C: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
        goto L_8001A280;
    // 0x8001A15C: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
L_8001A160:
    // 0x8001A160: lw          $v0, 0x48($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X48);
    // 0x8001A164: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8001A168: beq         $v0, $zero, L_8001A17C
    if (ctx->r2 == 0) {
        // 0x8001A16C: nop
    
            goto L_8001A17C;
    }
    // 0x8001A16C: nop

    // 0x8001A170: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001A174: j           L_8001A184
    // 0x8001A178: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
        goto L_8001A184;
    // 0x8001A178: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_8001A17C:
    // 0x8001A17C: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001A180: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001A184:
    // 0x8001A184: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x8001A188: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8001A18C: j           L_8001A280
    // 0x8001A190: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
        goto L_8001A280;
    // 0x8001A190: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
L_8001A194:
    // 0x8001A194: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x8001A198: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001A19C: bne         $v0, $zero, L_8001A280
    if (ctx->r2 != 0) {
        // 0x8001A1A0: sw          $v0, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->r2;
            goto L_8001A280;
    }
    // 0x8001A1A0: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x8001A1A4: lw          $v1, 0x5C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X5C);
    // 0x8001A1A8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001A1AC: addiu       $a1, $a1, 0x173C
    ctx->r5 = ADD32(ctx->r5, 0X173C);
    // 0x8001A1B0: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    // 0x8001A1B4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001A1B8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8001A1BC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001A1C0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8001A1C4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001A1C8: sw          $v1, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r3;
    // 0x8001A1CC: lb          $a1, -0x2($v0)
    ctx->r5 = MEM_B(ctx->r2, -0X2);
    // 0x8001A1D0: bne         $a1, $zero, L_8001A23C
    if (ctx->r5 != 0) {
        // 0x8001A1D4: nop
    
            goto L_8001A23C;
    }
    // 0x8001A1D4: nop

    // 0x8001A1D8: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001A1DC: lw          $v1, 0x48($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X48);
    // 0x8001A1E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001A1E4: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x8001A1E8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8001A1EC: bne         $v1, $v0, L_8001A280
    if (ctx->r3 != ctx->r2) {
        // 0x8001A1F0: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8001A280;
    }
    // 0x8001A1F0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8001A1F4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8001A1F8: addiu       $s2, $zero, 0x29
    ctx->r18 = ADD32(0, 0X29);
L_8001A1FC:
    // 0x8001A1FC: jal         0x8001D520
    // 0x8001A200: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    func_8001D520(rdram, ctx);
        goto after_2;
    // 0x8001A200: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    after_2:
    // 0x8001A204: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8001A208: beql        $v1, $zero, L_8001A228
    if (ctx->r3 == 0) {
        // 0x8001A20C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8001A228;
    }
    goto skip_0;
    // 0x8001A20C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8001A210: sb          $s3, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r19;
    // 0x8001A214: sb          $s2, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r18;
    // 0x8001A218: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x8001A21C: sw          $s1, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r17;
    // 0x8001A220: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
    // 0x8001A224: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8001A228:
    // 0x8001A228: slti        $v0, $s1, 0x2
    ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x8001A22C: beq         $v0, $zero, L_8001A280
    if (ctx->r2 == 0) {
        // 0x8001A230: nop
    
            goto L_8001A280;
    }
    // 0x8001A230: nop

    // 0x8001A234: j           L_8001A1FC
    // 0x8001A238: nop

        goto L_8001A1FC;
    // 0x8001A238: nop

L_8001A23C:
    // 0x8001A23C: jal         0x8001D470
    // 0x8001A240: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D470(rdram, ctx);
        goto after_3;
    // 0x8001A240: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8001A244: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8001A248: j           L_8001A280
    // 0x8001A24C: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
        goto L_8001A280;
    // 0x8001A24C: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
L_8001A250:
    // 0x8001A250: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001A254: lbu         $v1, 0x7B87($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B87);
    // 0x8001A258: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001A25C: bne         $v1, $v0, L_8001A280
    if (ctx->r3 != ctx->r2) {
        // 0x8001A260: addiu       $v1, $zero, 0x3C
        ctx->r3 = ADD32(0, 0X3C);
            goto L_8001A280;
    }
    // 0x8001A260: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x8001A264: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001A268: sw          $v1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r3;
    // 0x8001A26C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001A270:
    // 0x8001A270: j           L_8001A280
    // 0x8001A274: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
        goto L_8001A280;
    // 0x8001A274: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_8001A278:
    // 0x8001A278: jal         0x8001D564
    // 0x8001A27C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D564(rdram, ctx);
        goto after_4;
    // 0x8001A27C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
L_8001A280:
    // 0x8001A280: jal         0x8001D160
    // 0x8001A284: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D160(rdram, ctx);
        goto after_5;
    // 0x8001A284: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // 0x8001A288: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8001A28C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A290: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8001A294: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8001A298: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001A29C: jr          $ra
    // 0x8001A2A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001A2A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8001A2A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A2A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001A2A8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8001A2AC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8001A2B0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8001A2B4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001A2B8: lbu         $v1, 0x2B($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X2B);
    // 0x8001A2BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001A2C0: beq         $v1, $a0, L_8001A318
    if (ctx->r3 == ctx->r4) {
        // 0x8001A2C4: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8001A318;
    }
    // 0x8001A2C4: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8001A2C8: beql        $v0, $zero, L_8001A2E0
    if (ctx->r2 == 0) {
        // 0x8001A2CC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8001A2E0;
    }
    goto skip_0;
    // 0x8001A2CC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8001A2D0: beq         $v1, $zero, L_8001A2F8
    if (ctx->r3 == 0) {
        // 0x8001A2D4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001A2F8;
    }
    // 0x8001A2D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001A2D8: j           L_8001A44C
    // 0x8001A2DC: nop

        goto L_8001A44C;
    // 0x8001A2DC: nop

L_8001A2E0:
    // 0x8001A2E0: beq         $v1, $v0, L_8001A378
    if (ctx->r3 == ctx->r2) {
        // 0x8001A2E4: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8001A378;
    }
    // 0x8001A2E4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001A2E8: beq         $v1, $v0, L_8001A410
    if (ctx->r3 == ctx->r2) {
        // 0x8001A2EC: nop
    
            goto L_8001A410;
    }
    // 0x8001A2EC: nop

    // 0x8001A2F0: j           L_8001A44C
    // 0x8001A2F4: nop

        goto L_8001A44C;
    // 0x8001A2F4: nop

L_8001A2F8:
    // 0x8001A2F8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8001A2FC: sb          $v0, 0x2B($s1)
    MEM_B(0X2B, ctx->r17) = ctx->r2;
    // 0x8001A300: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8001A304: sb          $v1, 0x2A($s1)
    MEM_B(0X2A, ctx->r17) = ctx->r3;
    // 0x8001A308: sw          $v0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r2;
    // 0x8001A30C: sw          $a0, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->r4;
    // 0x8001A310: j           L_8001A44C
    // 0x8001A314: sb          $v1, 0x2D($s1)
    MEM_B(0X2D, ctx->r17) = ctx->r3;
        goto L_8001A44C;
    // 0x8001A314: sb          $v1, 0x2D($s1)
    MEM_B(0X2D, ctx->r17) = ctx->r3;
L_8001A318:
    // 0x8001A318: lw          $v0, 0x60($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X60);
    // 0x8001A31C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001A320: bne         $v0, $zero, L_8001A44C
    if (ctx->r2 != 0) {
        // 0x8001A324: sw          $v0, 0x60($s1)
        MEM_W(0X60, ctx->r17) = ctx->r2;
            goto L_8001A44C;
    }
    // 0x8001A324: sw          $v0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r2;
    // 0x8001A328: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001A32C: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x8001A330: jal         0x8001D578
    // 0x8001A334: sb          $s0, 0x2B($s1)
    MEM_B(0X2B, ctx->r17) = ctx->r16;
    func_8001D578(rdram, ctx);
        goto after_0;
    // 0x8001A334: sb          $s0, 0x2B($s1)
    MEM_B(0X2B, ctx->r17) = ctx->r16;
    after_0:
    // 0x8001A338: lw          $v1, 0x48($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X48);
    // 0x8001A33C: addiu       $v0, $zero, 0x520
    ctx->r2 = ADD32(0, 0X520);
    // 0x8001A340: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // 0x8001A344: addiu       $v0, $zero, 0x724
    ctx->r2 = ADD32(0, 0X724);
    // 0x8001A348: sb          $s0, 0x2D($s1)
    MEM_B(0X2D, ctx->r17) = ctx->r16;
    // 0x8001A34C: sh          $v0, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r2;
    // 0x8001A350: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001A354: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001A358: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001A35C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8001A360: lb          $a1, 0x174C($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X174C);
    // 0x8001A364: jal         0x8001D470
    // 0x8001A368: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001D470(rdram, ctx);
        goto after_1;
    // 0x8001A368: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x8001A36C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8001A370: j           L_8001A44C
    // 0x8001A374: sw          $v0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r2;
        goto L_8001A44C;
    // 0x8001A374: sw          $v0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r2;
L_8001A378:
    // 0x8001A378: lw          $v0, 0x60($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X60);
    // 0x8001A37C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001A380: bne         $v0, $zero, L_8001A444
    if (ctx->r2 != 0) {
        // 0x8001A384: sw          $v0, 0x60($s1)
        MEM_W(0X60, ctx->r17) = ctx->r2;
            goto L_8001A444;
    }
    // 0x8001A384: sw          $v0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r2;
    // 0x8001A388: lw          $v1, 0x48($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X48);
    // 0x8001A38C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001A390: addiu       $a1, $a1, 0x174C
    ctx->r5 = ADD32(ctx->r5, 0X174C);
    // 0x8001A394: lw          $a0, 0x5C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X5C);
    // 0x8001A398: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001A39C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001A3A0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8001A3A4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001A3A8: lb          $a1, 0x0($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X0);
    // 0x8001A3AC: beq         $a1, $zero, L_8001A3D4
    if (ctx->r5 == 0) {
        // 0x8001A3B0: addiu       $a0, $zero, 0x40
        ctx->r4 = ADD32(0, 0X40);
            goto L_8001A3D4;
    }
    // 0x8001A3B0: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x8001A3B4: jal         0x8001D470
    // 0x8001A3B8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001D470(rdram, ctx);
        goto after_2;
    // 0x8001A3B8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x8001A3BC: lw          $v0, 0x5C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X5C);
    // 0x8001A3C0: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8001A3C4: sw          $v1, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r3;
    // 0x8001A3C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001A3CC: j           L_8001A444
    // 0x8001A3D0: sw          $v0, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->r2;
        goto L_8001A444;
    // 0x8001A3D0: sw          $v0, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->r2;
L_8001A3D4:
    // 0x8001A3D4: lw          $a1, 0x44($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X44);
    // 0x8001A3D8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001A3DC: sb          $v0, 0x2B($s1)
    MEM_B(0X2B, ctx->r17) = ctx->r2;
    // 0x8001A3E0: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8001A3E4: jal         0x8000637C
    // 0x8001A3E8: sw          $v0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r2;
    func_8000637C(rdram, ctx);
        goto after_3;
    // 0x8001A3E8: sw          $v0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r2;
    after_3:
    // 0x8001A3EC: lw          $a1, 0x44($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X44);
    // 0x8001A3F0: jal         0x8000637C
    // 0x8001A3F4: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_8000637C(rdram, ctx);
        goto after_4;
    // 0x8001A3F4: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_4:
    // 0x8001A3F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001A3FC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001A400: sb          $v0, 0x7B87($at)
    MEM_B(0X7B87, ctx->r1) = ctx->r2;
    // 0x8001A404: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001A408: j           L_8001A444
    // 0x8001A40C: sb          $v0, 0x5585($at)
    MEM_B(0X5585, ctx->r1) = ctx->r2;
        goto L_8001A444;
    // 0x8001A40C: sb          $v0, 0x5585($at)
    MEM_B(0X5585, ctx->r1) = ctx->r2;
L_8001A410:
    // 0x8001A410: lbu         $v1, 0x2F($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X2F);
    // 0x8001A414: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x8001A418: bne         $v0, $zero, L_8001A424
    if (ctx->r2 != 0) {
        // 0x8001A41C: addiu       $v0, $v1, -0x5
        ctx->r2 = ADD32(ctx->r3, -0X5);
            goto L_8001A424;
    }
    // 0x8001A41C: addiu       $v0, $v1, -0x5
    ctx->r2 = ADD32(ctx->r3, -0X5);
    // 0x8001A420: sb          $v0, 0x2F($s1)
    MEM_B(0X2F, ctx->r17) = ctx->r2;
L_8001A424:
    // 0x8001A424: lw          $v0, 0x60($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X60);
    // 0x8001A428: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001A42C: bne         $v0, $zero, L_8001A444
    if (ctx->r2 != 0) {
        // 0x8001A430: sw          $v0, 0x60($s1)
        MEM_W(0X60, ctx->r17) = ctx->r2;
            goto L_8001A444;
    }
    // 0x8001A430: sw          $v0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r2;
    // 0x8001A434: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001A438: sb          $zero, 0x7B87($at)
    MEM_B(0X7B87, ctx->r1) = 0;
    // 0x8001A43C: jal         0x8001D564
    // 0x8001A440: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001D564(rdram, ctx);
        goto after_5;
    // 0x8001A440: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
L_8001A444:
    // 0x8001A444: jal         0x8001D160
    // 0x8001A448: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001D160(rdram, ctx);
        goto after_6;
    // 0x8001A448: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_6:
L_8001A44C:
    // 0x8001A44C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8001A450: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8001A454: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001A458: jr          $ra
    // 0x8001A45C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001A45C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8001A460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A460: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001A464: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8001A468: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8001A46C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001A470: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8001A474: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001A478: lbu         $v1, 0x2B($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X2B);
    // 0x8001A47C: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x8001A480: beq         $v0, $zero, L_8001A6B0
    if (ctx->r2 == 0) {
        // 0x8001A484: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8001A6B0;
    }
    // 0x8001A484: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001A488: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001A48C: addu        $at, $at, $v0
    gpr jr_addend_8001A494 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001A490: lw          $v0, -0x2F10($at)
    ctx->r2 = ADD32(ctx->r1, -0X2F10);
    // 0x8001A494: jr          $v0
    // 0x8001A498: nop

    switch (jr_addend_8001A494 >> 2) {
        case 0: goto L_8001A49C; break;
        case 1: goto L_8001A4B4; break;
        case 2: goto L_8001A4CC; break;
        case 3: goto L_8001A508; break;
        case 4: goto L_8001A544; break;
        case 5: goto L_8001A5A0; break;
        case 6: goto L_8001A698; break;
        default: switch_error(__func__, 0x8001A494, 0x800AD0F0);
    }
    // 0x8001A498: nop

L_8001A49C:
    // 0x8001A49C: lbu         $v0, 0x2B($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2B);
    // 0x8001A4A0: addiu       $v1, $zero, 0x28
    ctx->r3 = ADD32(0, 0X28);
    // 0x8001A4A4: sw          $v1, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r3;
    // 0x8001A4A8: addiu       $v1, $zero, -0xE6
    ctx->r3 = ADD32(0, -0XE6);
    // 0x8001A4AC: j           L_8001A594
    // 0x8001A4B0: sw          $v1, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->r3;
        goto L_8001A594;
    // 0x8001A4B0: sw          $v1, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->r3;
L_8001A4B4:
    // 0x8001A4B4: lw          $v0, 0x60($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X60);
    // 0x8001A4B8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001A4BC: bne         $v0, $zero, L_8001A6B0
    if (ctx->r2 != 0) {
        // 0x8001A4C0: sw          $v0, 0x60($s1)
        MEM_W(0X60, ctx->r17) = ctx->r2;
            goto L_8001A6B0;
    }
    // 0x8001A4C0: sw          $v0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r2;
    // 0x8001A4C4: j           L_8001A590
    // 0x8001A4C8: nop

        goto L_8001A590;
    // 0x8001A4C8: nop

L_8001A4CC:
    // 0x8001A4CC: lw          $v0, 0x4C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4C);
    // 0x8001A4D0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001A4D4: bltz        $v0, L_8001A4F8
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001A4D8: sw          $v0, 0x4C($s1)
        MEM_W(0X4C, ctx->r17) = ctx->r2;
            goto L_8001A4F8;
    }
    // 0x8001A4D8: sw          $v0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->r2;
    // 0x8001A4DC: lbu         $v0, 0x2B($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2B);
    // 0x8001A4E0: lw          $a1, 0x44($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X44);
    // 0x8001A4E4: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x8001A4E8: sw          $zero, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = 0;
    // 0x8001A4EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001A4F0: jal         0x8000637C
    // 0x8001A4F4: sb          $v0, 0x2B($s1)
    MEM_B(0X2B, ctx->r17) = ctx->r2;
    func_8000637C(rdram, ctx);
        goto after_0;
    // 0x8001A4F4: sb          $v0, 0x2B($s1)
    MEM_B(0X2B, ctx->r17) = ctx->r2;
    after_0:
L_8001A4F8:
    // 0x8001A4F8: lw          $v0, 0x4C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4C);
    // 0x8001A4FC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001A500: j           L_8001A6B0
    // 0x8001A504: sh          $v0, 0x558E($at)
    MEM_H(0X558E, ctx->r1) = ctx->r2;
        goto L_8001A6B0;
    // 0x8001A504: sh          $v0, 0x558E($at)
    MEM_H(0X558E, ctx->r1) = ctx->r2;
L_8001A508:
    // 0x8001A508: lwc1        $f0, 0x34($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X34);
    // 0x8001A50C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001A510: ldc1        $f4, -0x2EF0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2EF0);
    // 0x8001A514: lwc1        $f2, 0x38($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X38);
    // 0x8001A518: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001A51C: add.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f0.d + ctx->f4.d;
    // 0x8001A520: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001A524: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x8001A528: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001A52C: swc1        $f0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
    // 0x8001A530: lwc1        $f0, 0x34($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X34);
    // 0x8001A534: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001A538: ldc1        $f4, -0x2EE8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2EE8);
    // 0x8001A53C: j           L_8001A57C
    // 0x8001A540: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
        goto L_8001A57C;
    // 0x8001A540: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
L_8001A544:
    // 0x8001A544: lwc1        $f0, 0x34($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X34);
    // 0x8001A548: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001A54C: ldc1        $f4, -0x2EE0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2EE0);
    // 0x8001A550: lwc1        $f2, 0x38($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X38);
    // 0x8001A554: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001A558: add.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f0.d + ctx->f4.d;
    // 0x8001A55C: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001A560: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x8001A564: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001A568: swc1        $f0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
    // 0x8001A56C: lwc1        $f0, 0x34($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X34);
    // 0x8001A570: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001A574: ldc1        $f4, -0x2ED8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2ED8);
    // 0x8001A578: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
L_8001A57C:
    // 0x8001A57C: c.le.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d <= ctx->f0.d;
    // 0x8001A580: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8001A584: nop

    // 0x8001A588: bc1f        L_8001A6B0
    if (!c1cs) {
        // 0x8001A58C: swc1        $f2, 0x38($s1)
        MEM_W(0X38, ctx->r17) = ctx->f2.u32l;
            goto L_8001A6B0;
    }
    // 0x8001A58C: swc1        $f2, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f2.u32l;
L_8001A590:
    // 0x8001A590: lbu         $v0, 0x2B($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2B);
L_8001A594:
    // 0x8001A594: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001A598: j           L_8001A6B0
    // 0x8001A59C: sb          $v0, 0x2B($s1)
    MEM_B(0X2B, ctx->r17) = ctx->r2;
        goto L_8001A6B0;
    // 0x8001A59C: sb          $v0, 0x2B($s1)
    MEM_B(0X2B, ctx->r17) = ctx->r2;
L_8001A5A0:
    // 0x8001A5A0: lwc1        $f2, 0x34($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X34);
    // 0x8001A5A4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001A5A8: ldc1        $f4, -0x2ED0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2ED0);
    // 0x8001A5AC: lwc1        $f0, 0x38($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X38);
    // 0x8001A5B0: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001A5B4: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x8001A5B8: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001A5BC: add.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f0.d + ctx->f4.d;
    // 0x8001A5C0: lbu         $v1, 0x29($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X29);
    // 0x8001A5C4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8001A5C8: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8001A5CC: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001A5D0: swc1        $f2, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f2.u32l;
    // 0x8001A5D4: bne         $v1, $v0, L_8001A64C
    if (ctx->r3 != ctx->r2) {
        // 0x8001A5D8: swc1        $f0, 0x38($s1)
        MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
            goto L_8001A64C;
    }
    // 0x8001A5D8: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
    // 0x8001A5DC: lwc1        $f0, 0x34($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X34);
    // 0x8001A5E0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001A5E4: ldc1        $f2, -0x2EC8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2EC8);
    // 0x8001A5E8: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001A5EC: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x8001A5F0: nop

    // 0x8001A5F4: nop

    // 0x8001A5F8: bc1f        L_8001A64C
    if (!c1cs) {
        // 0x8001A5FC: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8001A64C;
    }
    // 0x8001A5FC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8001A600: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8001A604:
    // 0x8001A604: jal         0x8001D520
    // 0x8001A608: lw          $a0, 0x44($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X44);
    func_8001D520(rdram, ctx);
        goto after_1;
    // 0x8001A608: lw          $a0, 0x44($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X44);
    after_1:
    // 0x8001A60C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8001A610: beql        $v1, $zero, L_8001A630
    if (ctx->r3 == 0) {
        // 0x8001A614: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8001A630;
    }
    goto skip_0;
    // 0x8001A614: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8001A618: addiu       $v0, $s0, 0xD
    ctx->r2 = ADD32(ctx->r16, 0XD);
    // 0x8001A61C: sb          $s2, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r18;
    // 0x8001A620: sb          $v0, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r2;
    // 0x8001A624: lw          $v0, 0x44($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X44);
    // 0x8001A628: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
    // 0x8001A62C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8001A630:
    // 0x8001A630: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8001A634: bne         $v0, $zero, L_8001A604
    if (ctx->r2 != 0) {
        // 0x8001A638: nop
    
            goto L_8001A604;
    }
    // 0x8001A638: nop

    // 0x8001A63C: jal         0x8001D564
    // 0x8001A640: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001D564(rdram, ctx);
        goto after_2;
    // 0x8001A640: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x8001A644: j           L_8001A6B8
    // 0x8001A648: nop

        goto L_8001A6B8;
    // 0x8001A648: nop

L_8001A64C:
    // 0x8001A64C: lwc1        $f0, 0x34($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X34);
    // 0x8001A650: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001A654: ldc1        $f2, -0x2EC0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2EC0);
    // 0x8001A658: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001A65C: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x8001A660: nop

    // 0x8001A664: bc1f        L_8001A6B0
    if (!c1cs) {
        // 0x8001A668: nop
    
            goto L_8001A6B0;
    }
    // 0x8001A668: nop

    // 0x8001A66C: lbu         $v0, 0x2B($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2B);
    // 0x8001A670: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001A674: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001A678: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001A67C: sb          $v0, 0x2B($s1)
    MEM_B(0X2B, ctx->r17) = ctx->r2;
    // 0x8001A680: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001A684: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
    // 0x8001A688: swc1        $f0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
    // 0x8001A68C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001A690: j           L_8001A6B0
    // 0x8001A694: sb          $v0, 0x5585($at)
    MEM_B(0X5585, ctx->r1) = ctx->r2;
        goto L_8001A6B0;
    // 0x8001A694: sb          $v0, 0x5585($at)
    MEM_B(0X5585, ctx->r1) = ctx->r2;
L_8001A698:
    // 0x8001A698: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001A69C: lbu         $v0, 0x7B87($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B87);
    // 0x8001A6A0: bne         $v0, $zero, L_8001A6B0
    if (ctx->r2 != 0) {
        // 0x8001A6A4: nop
    
            goto L_8001A6B0;
    }
    // 0x8001A6A4: nop

    // 0x8001A6A8: jal         0x8001D564
    // 0x8001A6AC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001D564(rdram, ctx);
        goto after_3;
    // 0x8001A6AC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
L_8001A6B0:
    // 0x8001A6B0: jal         0x8001D160
    // 0x8001A6B4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001D160(rdram, ctx);
        goto after_4;
    // 0x8001A6B4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
L_8001A6B8:
    // 0x8001A6B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A6BC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8001A6C0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8001A6C4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001A6C8: jr          $ra
    // 0x8001A6CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001A6CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8001A6D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A6D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A6D4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001A6D8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001A6DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A6E0: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001A6E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001A6E8: beq         $v1, $v0, L_8001A774
    if (ctx->r3 == ctx->r2) {
        // 0x8001A6EC: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8001A774;
    }
    // 0x8001A6EC: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8001A6F0: beql        $v0, $zero, L_8001A708
    if (ctx->r2 == 0) {
        // 0x8001A6F4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8001A708;
    }
    goto skip_0;
    // 0x8001A6F4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8001A6F8: beq         $v1, $zero, L_8001A720
    if (ctx->r3 == 0) {
        // 0x8001A6FC: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8001A720;
    }
    // 0x8001A6FC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001A700: j           L_8001A844
    // 0x8001A704: nop

        goto L_8001A844;
    // 0x8001A704: nop

L_8001A708:
    // 0x8001A708: beq         $v1, $v0, L_8001A7F0
    if (ctx->r3 == ctx->r2) {
        // 0x8001A70C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8001A7F0;
    }
    // 0x8001A70C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001A710: beq         $v1, $v0, L_8001A83C
    if (ctx->r3 == ctx->r2) {
        // 0x8001A714: nop
    
            goto L_8001A83C;
    }
    // 0x8001A714: nop

    // 0x8001A718: j           L_8001A844
    // 0x8001A71C: nop

        goto L_8001A844;
    // 0x8001A71C: nop

L_8001A720:
    // 0x8001A720: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001A724: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x8001A728: jal         0x8001D578
    // 0x8001A72C: sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
    func_8001D578(rdram, ctx);
        goto after_0;
    // 0x8001A72C: sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
    after_0:
    // 0x8001A730: lui         $at, 0x3F98
    ctx->r1 = S32(0X3F98 << 16);
    // 0x8001A734: ori         $at, $at, 0x51EC
    ctx->r1 = ctx->r1 | 0X51EC;
    // 0x8001A738: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001A73C: lui         $at, 0x3F4F
    ctx->r1 = S32(0X3F4F << 16);
    // 0x8001A740: ori         $at, $at, 0x5C29
    ctx->r1 = ctx->r1 | 0X5C29;
    // 0x8001A744: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001A748: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001A74C: addiu       $v0, $zero, 0x660
    ctx->r2 = ADD32(0, 0X660);
    // 0x8001A750: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x8001A754: addiu       $v0, $zero, 0x380
    ctx->r2 = ADD32(0, 0X380);
    // 0x8001A758: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8001A75C: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x8001A760: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x8001A764: jal         0x8001D470
    // 0x8001A768: swc1        $f2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f2.u32l;
    func_8001D470(rdram, ctx);
        goto after_1;
    // 0x8001A768: swc1        $f2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f2.u32l;
    after_1:
    // 0x8001A76C: j           L_8001A844
    // 0x8001A770: nop

        goto L_8001A844;
    // 0x8001A770: nop

L_8001A774:
    // 0x8001A774: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8001A778: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001A77C: ldc1        $f4, -0x2EB8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2EB8);
    // 0x8001A780: lwc1        $f2, 0x38($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001A784: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001A788: sub.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f0.d - ctx->f4.d;
    // 0x8001A78C: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001A790: add.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d + ctx->f4.d;
    // 0x8001A794: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001A798: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x8001A79C: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8001A7A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001A7A4: ldc1        $f4, -0x2EB0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2EB0);
    // 0x8001A7A8: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001A7AC: c.le.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d <= ctx->f4.d;
    // 0x8001A7B0: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8001A7B4: nop

    // 0x8001A7B8: bc1f        L_8001A844
    if (!c1cs) {
        // 0x8001A7BC: swc1        $f2, 0x38($s0)
        MEM_W(0X38, ctx->r16) = ctx->f2.u32l;
            goto L_8001A844;
    }
    // 0x8001A7BC: swc1        $f2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f2.u32l;
    // 0x8001A7C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001A7C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001A7C8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001A7CC: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x8001A7D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001A7D4: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x8001A7D8: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x8001A7DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001A7E0: sb          $v0, 0x7B87($at)
    MEM_B(0X7B87, ctx->r1) = ctx->r2;
    // 0x8001A7E4: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8001A7E8: j           L_8001A844
    // 0x8001A7EC: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
        goto L_8001A844;
    // 0x8001A7EC: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
L_8001A7F0:
    // 0x8001A7F0: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x8001A7F4: addiu       $v1, $zero, -0x64
    ctx->r3 = ADD32(0, -0X64);
    // 0x8001A7F8: sw          $v1, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r3;
    // 0x8001A7FC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001A800: bne         $v0, $zero, L_8001A844
    if (ctx->r2 != 0) {
        // 0x8001A804: sw          $v0, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->r2;
            goto L_8001A844;
    }
    // 0x8001A804: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x8001A808: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x8001A80C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001A810: jal         0x8001D520
    // 0x8001A814: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    func_8001D520(rdram, ctx);
        goto after_2;
    // 0x8001A814: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    after_2:
    // 0x8001A818: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8001A81C: beq         $v1, $zero, L_8001A844
    if (ctx->r3 == 0) {
        // 0x8001A820: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001A844;
    }
    // 0x8001A820: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001A824: sb          $v0, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r2;
    // 0x8001A828: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x8001A82C: sb          $v0, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r2;
    // 0x8001A830: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x8001A834: j           L_8001A844
    // 0x8001A838: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
        goto L_8001A844;
    // 0x8001A838: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
L_8001A83C:
    // 0x8001A83C: jal         0x8001D564
    // 0x8001A840: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D564(rdram, ctx);
        goto after_3;
    // 0x8001A840: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
L_8001A844:
    // 0x8001A844: jal         0x8001D160
    // 0x8001A848: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D160(rdram, ctx);
        goto after_4;
    // 0x8001A848: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8001A84C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A850: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001A854: jr          $ra
    // 0x8001A858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001A858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001A85C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A85C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A860: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001A864: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001A868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A86C: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001A870: beq         $v1, $zero, L_8001A888
    if (ctx->r3 == 0) {
        // 0x8001A874: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001A888;
    }
    // 0x8001A874: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001A878: beq         $v1, $v0, L_8001A8C8
    if (ctx->r3 == ctx->r2) {
        // 0x8001A87C: nop
    
            goto L_8001A8C8;
    }
    // 0x8001A87C: nop

    // 0x8001A880: j           L_8001A8E8
    // 0x8001A884: nop

        goto L_8001A8E8;
    // 0x8001A884: nop

L_8001A888:
    // 0x8001A888: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001A88C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001A890: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x8001A894: jal         0x8001D578
    // 0x8001A898: sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
    func_8001D578(rdram, ctx);
        goto after_0;
    // 0x8001A898: sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
    after_0:
    // 0x8001A89C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001A8A0: addiu       $v0, $zero, 0x660
    ctx->r2 = ADD32(0, 0X660);
    // 0x8001A8A4: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x8001A8A8: addiu       $v0, $zero, 0x380
    ctx->r2 = ADD32(0, 0X380);
    // 0x8001A8AC: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x8001A8B0: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    // 0x8001A8B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8001A8B8: jal         0x8001D470
    // 0x8001A8BC: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    func_8001D470(rdram, ctx);
        goto after_1;
    // 0x8001A8BC: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    after_1:
    // 0x8001A8C0: j           L_8001A8E8
    // 0x8001A8C4: nop

        goto L_8001A8E8;
    // 0x8001A8C4: nop

L_8001A8C8:
    // 0x8001A8C8: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8001A8CC: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8001A8D0: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x8001A8D4: slti        $v0, $v0, 0x14
    ctx->r2 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8001A8D8: beq         $v0, $zero, L_8001A8E8
    if (ctx->r2 == 0) {
        // 0x8001A8DC: nop
    
            goto L_8001A8E8;
    }
    // 0x8001A8DC: nop

    // 0x8001A8E0: jal         0x8001D564
    // 0x8001A8E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D564(rdram, ctx);
        goto after_2;
    // 0x8001A8E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
L_8001A8E8:
    // 0x8001A8E8: jal         0x8001D160
    // 0x8001A8EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D160(rdram, ctx);
        goto after_3;
    // 0x8001A8EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8001A8F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A8F4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001A8F8: jr          $ra
    // 0x8001A8FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001A8FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001A900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A900: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A904: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001A908: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001A90C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A910: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001A914: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001A918: beq         $v1, $v0, L_8001A97C
    if (ctx->r3 == ctx->r2) {
        // 0x8001A91C: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8001A97C;
    }
    // 0x8001A91C: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8001A920: beql        $v0, $zero, L_8001A938
    if (ctx->r2 == 0) {
        // 0x8001A924: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8001A938;
    }
    goto skip_0;
    // 0x8001A924: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8001A928: beq         $v1, $zero, L_8001A950
    if (ctx->r3 == 0) {
        // 0x8001A92C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8001A950;
    }
    // 0x8001A92C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001A930: j           L_8001A9DC
    // 0x8001A934: nop

        goto L_8001A9DC;
    // 0x8001A934: nop

L_8001A938:
    // 0x8001A938: beq         $v1, $v0, L_8001A9B0
    if (ctx->r3 == ctx->r2) {
        // 0x8001A93C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8001A9B0;
    }
    // 0x8001A93C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001A940: beq         $v1, $v0, L_8001A9D4
    if (ctx->r3 == ctx->r2) {
        // 0x8001A944: nop
    
            goto L_8001A9D4;
    }
    // 0x8001A944: nop

    // 0x8001A948: j           L_8001A9DC
    // 0x8001A94C: nop

        goto L_8001A9DC;
    // 0x8001A94C: nop

L_8001A950:
    // 0x8001A950: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001A954: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x8001A958: jal         0x8001D578
    // 0x8001A95C: sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
    func_8001D578(rdram, ctx);
        goto after_0;
    // 0x8001A95C: sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
    after_0:
    // 0x8001A960: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001A964: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8001A968: addiu       $v0, $zero, 0x660
    ctx->r2 = ADD32(0, 0X660);
    // 0x8001A96C: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x8001A970: addiu       $v0, $zero, 0x380
    ctx->r2 = ADD32(0, 0X380);
    // 0x8001A974: j           L_8001A99C
    // 0x8001A978: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
        goto L_8001A99C;
    // 0x8001A978: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
L_8001A97C:
    // 0x8001A97C: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x8001A980: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001A984: bne         $v0, $zero, L_8001A9DC
    if (ctx->r2 != 0) {
        // 0x8001A988: sw          $v0, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->r2;
            goto L_8001A9DC;
    }
    // 0x8001A988: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x8001A98C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001A990: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8001A994: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001A998: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_8001A99C:
    // 0x8001A99C: jal         0x8001D470
    // 0x8001A9A0: nop

    func_8001D470(rdram, ctx);
        goto after_1;
    // 0x8001A9A0: nop

    after_1:
    // 0x8001A9A4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8001A9A8: j           L_8001A9DC
    // 0x8001A9AC: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
        goto L_8001A9DC;
    // 0x8001A9AC: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
L_8001A9B0:
    // 0x8001A9B0: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x8001A9B4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001A9B8: bne         $v0, $zero, L_8001A9DC
    if (ctx->r2 != 0) {
        // 0x8001A9BC: sw          $v0, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->r2;
            goto L_8001A9DC;
    }
    // 0x8001A9BC: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x8001A9C0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001A9C4: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x8001A9C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001A9CC: j           L_8001A9DC
    // 0x8001A9D0: sb          $zero, 0x7B87($at)
    MEM_B(0X7B87, ctx->r1) = 0;
        goto L_8001A9DC;
    // 0x8001A9D0: sb          $zero, 0x7B87($at)
    MEM_B(0X7B87, ctx->r1) = 0;
L_8001A9D4:
    // 0x8001A9D4: jal         0x8001D564
    // 0x8001A9D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D564(rdram, ctx);
        goto after_2;
    // 0x8001A9D8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
L_8001A9DC:
    // 0x8001A9DC: jal         0x8001D160
    // 0x8001A9E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D160(rdram, ctx);
        goto after_3;
    // 0x8001A9E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8001A9E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A9E8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001A9EC: jr          $ra
    // 0x8001A9F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001A9F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001A9F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A9F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A9F8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001A9FC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001AA00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001AA04: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001AA08: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x8001AA0C: beq         $v0, $zero, L_8001AC00
    if (ctx->r2 == 0) {
        // 0x8001AA10: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8001AC00;
    }
    // 0x8001AA10: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001AA14: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001AA18: addu        $at, $at, $v0
    gpr jr_addend_8001AA20 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001AA1C: lw          $v0, -0x2EA8($at)
    ctx->r2 = ADD32(ctx->r1, -0X2EA8);
    // 0x8001AA20: jr          $v0
    // 0x8001AA24: nop

    switch (jr_addend_8001AA20 >> 2) {
        case 0: goto L_8001AA28; break;
        case 1: goto L_8001AA50; break;
        case 2: goto L_8001AA6C; break;
        case 3: goto L_8001AB2C; break;
        case 4: goto L_8001ABE4; break;
        default: switch_error(__func__, 0x8001AA20, 0x800AD158);
    }
    // 0x8001AA24: nop

L_8001AA28:
    // 0x8001AA28: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001AA2C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001AA30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001AA34: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x8001AA38: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8001AA3C: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x8001AA40: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x8001AA44: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001AA48: j           L_8001AC00
    // 0x8001AA4C: sh          $zero, 0x558E($at)
    MEM_H(0X558E, ctx->r1) = 0;
        goto L_8001AC00;
    // 0x8001AA4C: sh          $zero, 0x558E($at)
    MEM_H(0X558E, ctx->r1) = 0;
L_8001AA50:
    // 0x8001AA50: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001AA54: lh          $v1, 0x558E($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X558E);
    // 0x8001AA58: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001AA5C: bne         $v1, $v0, L_8001AC00
    if (ctx->r3 != ctx->r2) {
        // 0x8001AA60: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8001AC00;
    }
    // 0x8001AA60: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001AA64: j           L_8001AC00
    // 0x8001AA68: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
        goto L_8001AC00;
    // 0x8001AA68: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_8001AA6C:
    // 0x8001AA6C: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001AA70: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001AA74: ldc1        $f8, -0x2E90($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2E90);
    // 0x8001AA78: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001AA7C: sub.d       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f0.d = ctx->f0.d - ctx->f8.d;
    // 0x8001AA80: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001AA84: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x8001AA88: lwc1        $f2, 0x38($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001AA8C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001AA90: ldc1        $f6, -0x2E88($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2E88);
    // 0x8001AA94: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8001AA98: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001AA9C: sub.d       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f6.d - ctx->f2.d;
    // 0x8001AAA0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001AAA4: ldc1        $f2, -0x2E80($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2E80);
    // 0x8001AAA8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001AAAC: ldc1        $f4, -0x2E78($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2E78);
    // 0x8001AAB0: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001AAB4: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8001AAB8: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8001AABC: mul.d       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x8001AAC0: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001AAC4: add.d       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = ctx->f2.d + ctx->f8.d;
    // 0x8001AAC8: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001AACC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001AAD0: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001AAD4: nop

    // 0x8001AAD8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8001AADC: nop

    // 0x8001AAE0: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8001AAE4: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x8001AAE8: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8001AAEC: sub.d       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f4.d - ctx->f6.d;
    // 0x8001AAF0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001AAF4: ldc1        $f6, -0x2E70($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2E70);
    // 0x8001AAF8: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001AAFC: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8001AB00: c.le.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d <= ctx->f6.d;
    // 0x8001AB04: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
    // 0x8001AB08: trunc.w.d   $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x8001AB0C: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x8001AB10: bc1f        L_8001AC00
    if (!c1cs) {
        // 0x8001AB14: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8001AC00;
    }
    // 0x8001AB14: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001AB18: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8001AB1C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001AB20: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x8001AB24: j           L_8001AC00
    // 0x8001AB28: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
        goto L_8001AC00;
    // 0x8001AB28: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
L_8001AB2C:
    // 0x8001AB2C: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001AB30: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001AB34: ldc1        $f8, -0x2E68($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2E68);
    // 0x8001AB38: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001AB3C: add.d       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f0.d = ctx->f0.d + ctx->f8.d;
    // 0x8001AB40: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001AB44: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x8001AB48: lwc1        $f2, 0x38($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001AB4C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001AB50: ldc1        $f6, -0x2E60($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2E60);
    // 0x8001AB54: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8001AB58: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001AB5C: sub.d       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f6.d - ctx->f2.d;
    // 0x8001AB60: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001AB64: ldc1        $f2, -0x2E58($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2E58);
    // 0x8001AB68: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001AB6C: ldc1        $f4, -0x2E50($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2E50);
    // 0x8001AB70: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001AB74: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8001AB78: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8001AB7C: mul.d       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x8001AB80: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001AB84: sub.d       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = ctx->f2.d - ctx->f8.d;
    // 0x8001AB88: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001AB8C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001AB90: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001AB94: nop

    // 0x8001AB98: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8001AB9C: nop

    // 0x8001ABA0: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8001ABA4: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x8001ABA8: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8001ABAC: sub.d       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f4.d - ctx->f6.d;
    // 0x8001ABB0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001ABB4: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8001ABB8: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001ABBC: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8001ABC0: c.le.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d <= ctx->f6.d;
    // 0x8001ABC4: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
    // 0x8001ABC8: trunc.w.d   $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x8001ABCC: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x8001ABD0: bc1f        L_8001AC00
    if (!c1cs) {
        // 0x8001ABD4: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8001AC00;
    }
    // 0x8001ABD4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8001ABD8: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x8001ABDC: j           L_8001AC00
    // 0x8001ABE0: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
        goto L_8001AC00;
    // 0x8001ABE0: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
L_8001ABE4:
    // 0x8001ABE4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001ABE8: lbu         $v1, 0x7B87($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B87);
    // 0x8001ABEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001ABF0: bne         $v1, $v0, L_8001AC00
    if (ctx->r3 != ctx->r2) {
        // 0x8001ABF4: nop
    
            goto L_8001AC00;
    }
    // 0x8001ABF4: nop

    // 0x8001ABF8: jal         0x8001D564
    // 0x8001ABFC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D564(rdram, ctx);
        goto after_0;
    // 0x8001ABFC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
L_8001AC00:
    // 0x8001AC00: jal         0x8001D160
    // 0x8001AC04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D160(rdram, ctx);
        goto after_1;
    // 0x8001AC04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8001AC08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001AC0C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001AC10: jr          $ra
    // 0x8001AC14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001AC14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001AC18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AC18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001AC1C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001AC20: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001AC24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001AC28: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001AC2C: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x8001AC30: beq         $v0, $zero, L_8001AF6C
    if (ctx->r2 == 0) {
        // 0x8001AC34: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8001AF6C;
    }
    // 0x8001AC34: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001AC38: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001AC3C: addu        $at, $at, $v0
    gpr jr_addend_8001AC44 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001AC40: lw          $v0, -0x2E48($at)
    ctx->r2 = ADD32(ctx->r1, -0X2E48);
    // 0x8001AC44: jr          $v0
    // 0x8001AC48: nop

    switch (jr_addend_8001AC44 >> 2) {
        case 0: goto L_8001AC4C; break;
        case 1: goto L_8001AC9C; break;
        case 2: goto L_8001ACDC; break;
        case 3: goto L_8001AD50; break;
        case 4: goto L_8001AE10; break;
        case 5: goto L_8001AEF8; break;
        case 6: goto L_8001AF1C; break;
        default: switch_error(__func__, 0x8001AC44, 0x800AD1B8);
    }
    // 0x8001AC48: nop

L_8001AC4C:
    // 0x8001AC4C: lui         $at, 0x4368
    ctx->r1 = S32(0X4368 << 16);
    // 0x8001AC50: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001AC54: addiu       $v0, $zero, 0xE8
    ctx->r2 = ADD32(0, 0XE8);
    // 0x8001AC58: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x8001AC5C: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x8001AC60: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001AC64: lh          $v1, 0x558E($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X558E);
    // 0x8001AC68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001AC6C: bne         $v1, $v0, L_8001AF6C
    if (ctx->r3 != ctx->r2) {
        // 0x8001AC70: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8001AF6C;
    }
    // 0x8001AC70: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001AC74: lbu         $v0, 0x29($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X29);
    // 0x8001AC78: sb          $v1, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r3;
    // 0x8001AC7C: addiu       $v1, $zero, 0x11
    ctx->r3 = ADD32(0, 0X11);
    // 0x8001AC80: bne         $v0, $v1, L_8001AF6C
    if (ctx->r2 != ctx->r3) {
        // 0x8001AC84: nop
    
            goto L_8001AF6C;
    }
    // 0x8001AC84: nop

    // 0x8001AC88: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x8001AC8C: jal         0x8000637C
    // 0x8001AC90: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_8000637C(rdram, ctx);
        goto after_0;
    // 0x8001AC90: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_0:
    // 0x8001AC94: j           L_8001AF6C
    // 0x8001AC98: nop

        goto L_8001AF6C;
    // 0x8001AC98: nop

L_8001AC9C:
    // 0x8001AC9C: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8001ACA0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001ACA4: ldc1        $f2, -0x2E28($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2E28);
    // 0x8001ACA8: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001ACAC: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8001ACB0: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001ACB4: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001ACB8: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8001ACBC: nop

    // 0x8001ACC0: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x8001ACC4: slti        $v0, $v0, 0x1F
    ctx->r2 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x8001ACC8: beq         $v0, $zero, L_8001AF6C
    if (ctx->r2 == 0) {
        // 0x8001ACCC: swc1        $f0, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
            goto L_8001AF6C;
    }
    // 0x8001ACCC: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x8001ACD0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001ACD4: j           L_8001AF6C
    // 0x8001ACD8: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
        goto L_8001AF6C;
    // 0x8001ACD8: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_8001ACDC:
    // 0x8001ACDC: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8001ACE0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001ACE4: ldc1        $f2, -0x2E20($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2E20);
    // 0x8001ACE8: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001ACEC: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8001ACF0: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001ACF4: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001ACF8: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8001ACFC: nop

    // 0x8001AD00: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x8001AD04: slti        $v0, $v0, 0x9
    ctx->r2 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x8001AD08: beq         $v0, $zero, L_8001AF6C
    if (ctx->r2 == 0) {
        // 0x8001AD0C: swc1        $f0, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
            goto L_8001AF6C;
    }
    // 0x8001AD0C: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x8001AD10: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001AD14: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x8001AD18: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8001AD1C: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x8001AD20: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001AD24: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001AD28: sh          $v0, 0x558E($at)
    MEM_H(0X558E, ctx->r1) = ctx->r2;
    // 0x8001AD2C: lbu         $v1, 0x29($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X29);
    // 0x8001AD30: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x8001AD34: bne         $v1, $v0, L_8001AF6C
    if (ctx->r3 != ctx->r2) {
        // 0x8001AD38: nop
    
            goto L_8001AF6C;
    }
    // 0x8001AD38: nop

    // 0x8001AD3C: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x8001AD40: jal         0x8000637C
    // 0x8001AD44: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_8000637C(rdram, ctx);
        goto after_1;
    // 0x8001AD44: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_1:
    // 0x8001AD48: j           L_8001AF6C
    // 0x8001AD4C: nop

        goto L_8001AF6C;
    // 0x8001AD4C: nop

L_8001AD50:
    // 0x8001AD50: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001AD54: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001AD58: ldc1        $f8, -0x2E18($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2E18);
    // 0x8001AD5C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001AD60: sub.d       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f0.d = ctx->f0.d - ctx->f8.d;
    // 0x8001AD64: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001AD68: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x8001AD6C: lwc1        $f2, 0x38($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001AD70: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001AD74: ldc1        $f6, -0x2E10($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2E10);
    // 0x8001AD78: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8001AD7C: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001AD80: sub.d       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f6.d - ctx->f2.d;
    // 0x8001AD84: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001AD88: ldc1        $f2, -0x2E08($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2E08);
    // 0x8001AD8C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001AD90: ldc1        $f4, -0x2E00($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2E00);
    // 0x8001AD94: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001AD98: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8001AD9C: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8001ADA0: mul.d       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x8001ADA4: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001ADA8: add.d       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = ctx->f2.d + ctx->f8.d;
    // 0x8001ADAC: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001ADB0: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001ADB4: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001ADB8: nop

    // 0x8001ADBC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8001ADC0: nop

    // 0x8001ADC4: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8001ADC8: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x8001ADCC: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8001ADD0: sub.d       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f4.d - ctx->f6.d;
    // 0x8001ADD4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001ADD8: ldc1        $f6, -0x2DF8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2DF8);
    // 0x8001ADDC: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001ADE0: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8001ADE4: c.le.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d <= ctx->f6.d;
    // 0x8001ADE8: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
    // 0x8001ADEC: trunc.w.d   $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x8001ADF0: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x8001ADF4: bc1f        L_8001AF6C
    if (!c1cs) {
        // 0x8001ADF8: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8001AF6C;
    }
    // 0x8001ADF8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8001ADFC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8001AE00: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001AE04: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x8001AE08: j           L_8001AF6C
    // 0x8001AE0C: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
        goto L_8001AF6C;
    // 0x8001AE0C: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
L_8001AE10:
    // 0x8001AE10: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001AE14: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001AE18: ldc1        $f8, -0x2DF0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X2DF0);
    // 0x8001AE1C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001AE20: add.d       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f0.d = ctx->f0.d + ctx->f8.d;
    // 0x8001AE24: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001AE28: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x8001AE2C: lwc1        $f2, 0x38($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001AE30: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001AE34: ldc1        $f6, -0x2DE8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2DE8);
    // 0x8001AE38: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8001AE3C: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001AE40: sub.d       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f6.d - ctx->f2.d;
    // 0x8001AE44: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001AE48: ldc1        $f2, -0x2DE0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2DE0);
    // 0x8001AE4C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001AE50: ldc1        $f4, -0x2DD8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2DD8);
    // 0x8001AE54: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001AE58: sub.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d - ctx->f2.d;
    // 0x8001AE5C: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8001AE60: mul.d       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x8001AE64: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001AE68: sub.d       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = ctx->f2.d - ctx->f8.d;
    // 0x8001AE6C: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001AE70: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001AE74: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8001AE78: nop

    // 0x8001AE7C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8001AE80: nop

    // 0x8001AE84: cvt.d.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.d = CVT_D_W(ctx->f4.u32l);
    // 0x8001AE88: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x8001AE8C: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8001AE90: sub.d       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f4.d - ctx->f6.d;
    // 0x8001AE94: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001AE98: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8001AE9C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001AEA0: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8001AEA4: c.le.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d <= ctx->f6.d;
    // 0x8001AEA8: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
    // 0x8001AEAC: trunc.w.d   $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x8001AEB0: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x8001AEB4: bc1f        L_8001AF6C
    if (!c1cs) {
        // 0x8001AEB8: addiu       $v0, $zero, 0x12
        ctx->r2 = ADD32(0, 0X12);
            goto L_8001AF6C;
    }
    // 0x8001AEB8: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x8001AEBC: lbu         $v1, 0x29($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X29);
    // 0x8001AEC0: bne         $v1, $v0, L_8001AEEC
    if (ctx->r3 != ctx->r2) {
        // 0x8001AEC4: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_8001AEEC;
    }
    // 0x8001AEC4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8001AEC8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001AECC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8001AED0: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8001AED4: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x8001AED8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8001AEDC: jal         0x8001D470
    // 0x8001AEE0: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    func_8001D470(rdram, ctx);
        goto after_2;
    // 0x8001AEE0: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    after_2:
    // 0x8001AEE4: j           L_8001AF6C
    // 0x8001AEE8: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
        goto L_8001AF6C;
    // 0x8001AEE8: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
L_8001AEEC:
    // 0x8001AEEC: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x8001AEF0: j           L_8001AF6C
    // 0x8001AEF4: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
        goto L_8001AF6C;
    // 0x8001AEF4: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
L_8001AEF8:
    // 0x8001AEF8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001AEFC: lbu         $v1, 0x7B87($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B87);
    // 0x8001AF00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001AF04: bne         $v1, $v0, L_8001AF6C
    if (ctx->r3 != ctx->r2) {
        // 0x8001AF08: nop
    
            goto L_8001AF6C;
    }
    // 0x8001AF08: nop

    // 0x8001AF0C: jal         0x8001D564
    // 0x8001AF10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D564(rdram, ctx);
        goto after_3;
    // 0x8001AF10: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8001AF14: j           L_8001AF6C
    // 0x8001AF18: nop

        goto L_8001AF6C;
    // 0x8001AF18: nop

L_8001AF1C:
    // 0x8001AF1C: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x8001AF20: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001AF24: bne         $v0, $zero, L_8001AF6C
    if (ctx->r2 != 0) {
        // 0x8001AF28: sw          $v0, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->r2;
            goto L_8001AF6C;
    }
    // 0x8001AF28: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x8001AF2C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001AF30: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8001AF34: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8001AF38: jal         0x8001D470
    // 0x8001AF3C: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    func_8001D470(rdram, ctx);
        goto after_4;
    // 0x8001AF3C: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    after_4:
    // 0x8001AF40: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x8001AF44: jal         0x8001D520
    // 0x8001AF48: nop

    func_8001D520(rdram, ctx);
        goto after_5;
    // 0x8001AF48: nop

    after_5:
    // 0x8001AF4C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8001AF50: beq         $v1, $zero, L_8001AF6C
    if (ctx->r3 == 0) {
        // 0x8001AF54: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001AF6C;
    }
    // 0x8001AF54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001AF58: sb          $v0, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r2;
    // 0x8001AF5C: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // 0x8001AF60: sb          $v0, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r2;
    // 0x8001AF64: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x8001AF68: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
L_8001AF6C:
    // 0x8001AF6C: jal         0x8001D160
    // 0x8001AF70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D160(rdram, ctx);
        goto after_6;
    // 0x8001AF70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x8001AF74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001AF78: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001AF7C: jr          $ra
    // 0x8001AF80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001AF80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001AF84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AF84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001AF88: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8001AF8C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8001AF90: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8001AF94: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8001AF98: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8001AF9C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001AFA0: lbu         $v1, 0x2B($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X2B);
    // 0x8001AFA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001AFA8: beq         $v1, $v0, L_8001B024
    if (ctx->r3 == ctx->r2) {
        // 0x8001AFAC: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8001B024;
    }
    // 0x8001AFAC: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8001AFB0: beql        $v0, $zero, L_8001AFC8
    if (ctx->r2 == 0) {
        // 0x8001AFB4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8001AFC8;
    }
    goto skip_0;
    // 0x8001AFB4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8001AFB8: beq         $v1, $zero, L_8001AFD8
    if (ctx->r3 == 0) {
        // 0x8001AFBC: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8001AFD8;
    }
    // 0x8001AFBC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001AFC0: j           L_8001B0F8
    // 0x8001AFC4: nop

        goto L_8001B0F8;
    // 0x8001AFC4: nop

L_8001AFC8:
    // 0x8001AFC8: beq         $v1, $v0, L_8001B0F0
    if (ctx->r3 == ctx->r2) {
        // 0x8001AFCC: nop
    
            goto L_8001B0F0;
    }
    // 0x8001AFCC: nop

    // 0x8001AFD0: j           L_8001B0F8
    // 0x8001AFD4: nop

        goto L_8001B0F8;
    // 0x8001AFD4: nop

L_8001AFD8:
    // 0x8001AFD8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8001AFDC: sb          $s0, 0x2B($s1)
    MEM_B(0X2B, ctx->r17) = ctx->r16;
    // 0x8001AFE0: jal         0x8001D578
    // 0x8001AFE4: sb          $s0, 0x2A($s1)
    MEM_B(0X2A, ctx->r17) = ctx->r16;
    func_8001D578(rdram, ctx);
        goto after_0;
    // 0x8001AFE4: sb          $s0, 0x2A($s1)
    MEM_B(0X2A, ctx->r17) = ctx->r16;
    after_0:
    // 0x8001AFE8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001AFEC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8001AFF0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001AFF4: sb          $v0, 0x2D($s1)
    MEM_B(0X2D, ctx->r17) = ctx->r2;
    // 0x8001AFF8: addiu       $v0, $zero, 0x600
    ctx->r2 = ADD32(0, 0X600);
    // 0x8001AFFC: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // 0x8001B000: addiu       $v0, $zero, 0x334
    ctx->r2 = ADD32(0, 0X334);
    // 0x8001B004: jal         0x8001D470
    // 0x8001B008: sh          $v0, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r2;
    func_8001D470(rdram, ctx);
        goto after_1;
    // 0x8001B008: sh          $v0, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r2;
    after_1:
    // 0x8001B00C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8001B010: sw          $v0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r2;
    // 0x8001B014: sw          $zero, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = 0;
    // 0x8001B018: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001B01C: j           L_8001B0F8
    // 0x8001B020: sb          $s0, 0x5585($at)
    MEM_B(0X5585, ctx->r1) = ctx->r16;
        goto L_8001B0F8;
    // 0x8001B020: sb          $s0, 0x5585($at)
    MEM_B(0X5585, ctx->r1) = ctx->r16;
L_8001B024:
    // 0x8001B024: lw          $v0, 0x60($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X60);
    // 0x8001B028: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001B02C: bne         $v0, $zero, L_8001B0F8
    if (ctx->r2 != 0) {
        // 0x8001B030: sw          $v0, 0x60($s1)
        MEM_W(0X60, ctx->r17) = ctx->r2;
            goto L_8001B0F8;
    }
    // 0x8001B030: sw          $v0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r2;
    // 0x8001B034: lw          $v0, 0x5C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X5C);
    // 0x8001B038: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001B03C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001B040: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001B044: lb          $v0, 0x1758($at)
    ctx->r2 = MEM_B(ctx->r1, 0X1758);
    // 0x8001B048: bne         $v0, $zero, L_8001B058
    if (ctx->r2 != 0) {
        // 0x8001B04C: sw          $v0, 0x60($s1)
        MEM_W(0X60, ctx->r17) = ctx->r2;
            goto L_8001B058;
    }
    // 0x8001B04C: sw          $v0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r2;
    // 0x8001B050: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001B054: sb          $v0, 0x2B($s1)
    MEM_B(0X2B, ctx->r17) = ctx->r2;
L_8001B058:
    // 0x8001B058: lw          $v0, 0x5C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X5C);
    // 0x8001B05C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001B060: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001B064: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8001B068: lb          $a1, 0x1759($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X1759);
    // 0x8001B06C: jal         0x8001D470
    // 0x8001B070: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001D470(rdram, ctx);
        goto after_2;
    // 0x8001B070: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x8001B074: lw          $v1, 0x5C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X5C);
    // 0x8001B078: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8001B07C: bne         $v1, $v0, L_8001B098
    if (ctx->r3 != ctx->r2) {
        // 0x8001B080: addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
            goto L_8001B098;
    }
    // 0x8001B080: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8001B084: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001B088: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001B08C: sb          $v0, 0x7B87($at)
    MEM_B(0X7B87, ctx->r1) = ctx->r2;
    // 0x8001B090: lw          $v1, 0x5C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X5C);
    // 0x8001B094: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_8001B098:
    // 0x8001B098: bne         $v1, $v0, L_8001B0E0
    if (ctx->r3 != ctx->r2) {
        // 0x8001B09C: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8001B0E0;
    }
    // 0x8001B09C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8001B0A0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8001B0A4: addiu       $s2, $zero, 0x14
    ctx->r18 = ADD32(0, 0X14);
L_8001B0A8:
    // 0x8001B0A8: jal         0x8001D520
    // 0x8001B0AC: lw          $a0, 0x44($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X44);
    func_8001D520(rdram, ctx);
        goto after_3;
    // 0x8001B0AC: lw          $a0, 0x44($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X44);
    after_3:
    // 0x8001B0B0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8001B0B4: beql        $v1, $zero, L_8001B0D4
    if (ctx->r3 == 0) {
        // 0x8001B0B8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8001B0D4;
    }
    goto skip_1;
    // 0x8001B0B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x8001B0BC: sb          $s3, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r19;
    // 0x8001B0C0: sb          $s2, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r18;
    // 0x8001B0C4: lw          $v0, 0x44($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X44);
    // 0x8001B0C8: sw          $s0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r16;
    // 0x8001B0CC: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
    // 0x8001B0D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8001B0D4:
    // 0x8001B0D4: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8001B0D8: bne         $v0, $zero, L_8001B0A8
    if (ctx->r2 != 0) {
        // 0x8001B0DC: nop
    
            goto L_8001B0A8;
    }
    // 0x8001B0DC: nop

L_8001B0E0:
    // 0x8001B0E0: lw          $v0, 0x5C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X5C);
    // 0x8001B0E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001B0E8: j           L_8001B0F8
    // 0x8001B0EC: sw          $v0, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->r2;
        goto L_8001B0F8;
    // 0x8001B0EC: sw          $v0, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->r2;
L_8001B0F0:
    // 0x8001B0F0: jal         0x8001D564
    // 0x8001B0F4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001D564(rdram, ctx);
        goto after_4;
    // 0x8001B0F4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
L_8001B0F8:
    // 0x8001B0F8: jal         0x8001D160
    // 0x8001B0FC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001D160(rdram, ctx);
        goto after_5;
    // 0x8001B0FC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
    // 0x8001B100: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8001B104: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B108: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8001B10C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8001B110: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001B114: jr          $ra
    // 0x8001B118: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001B118: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8001B11C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B11C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B120: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8001B124: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8001B128: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8001B12C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001B130: lbu         $v1, 0x2B($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X2B);
    // 0x8001B134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001B138: beq         $v1, $v0, L_8001B1CC
    if (ctx->r3 == ctx->r2) {
        // 0x8001B13C: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8001B1CC;
    }
    // 0x8001B13C: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8001B140: beql        $v0, $zero, L_8001B158
    if (ctx->r2 == 0) {
        // 0x8001B144: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8001B158;
    }
    goto skip_0;
    // 0x8001B144: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8001B148: beq         $v1, $zero, L_8001B168
    if (ctx->r3 == 0) {
        // 0x8001B14C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8001B168;
    }
    // 0x8001B14C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001B150: j           L_8001B264
    // 0x8001B154: nop

        goto L_8001B264;
    // 0x8001B154: nop

L_8001B158:
    // 0x8001B158: beq         $v1, $v0, L_8001B23C
    if (ctx->r3 == ctx->r2) {
        // 0x8001B15C: nop
    
            goto L_8001B23C;
    }
    // 0x8001B15C: nop

    // 0x8001B160: j           L_8001B264
    // 0x8001B164: nop

        goto L_8001B264;
    // 0x8001B164: nop

L_8001B168:
    // 0x8001B168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001B16C: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x8001B170: sb          $v0, 0x2B($s1)
    MEM_B(0X2B, ctx->r17) = ctx->r2;
    // 0x8001B174: jal         0x8001D578
    // 0x8001B178: sb          $s0, 0x2A($s1)
    MEM_B(0X2A, ctx->r17) = ctx->r16;
    func_8001D578(rdram, ctx);
        goto after_0;
    // 0x8001B178: sb          $s0, 0x2A($s1)
    MEM_B(0X2A, ctx->r17) = ctx->r16;
    after_0:
    // 0x8001B17C: lw          $v1, 0x48($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X48);
    // 0x8001B180: addiu       $v0, $zero, 0x600
    ctx->r2 = ADD32(0, 0X600);
    // 0x8001B184: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // 0x8001B188: addiu       $v0, $zero, 0x334
    ctx->r2 = ADD32(0, 0X334);
    // 0x8001B18C: sh          $v0, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r2;
    // 0x8001B190: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8001B194: sb          $s0, 0x2D($s1)
    MEM_B(0X2D, ctx->r17) = ctx->r16;
    // 0x8001B198: sw          $v0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r2;
    // 0x8001B19C: sw          $zero, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = 0;
    // 0x8001B1A0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8001B1A4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001B1A8: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x8001B1AC: lb          $a1, 0x1774($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X1774);
    // 0x8001B1B0: jal         0x8001D470
    // 0x8001B1B4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001D470(rdram, ctx);
        goto after_1;
    // 0x8001B1B4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x8001B1B8: lw          $a1, 0x44($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X44);
    // 0x8001B1BC: jal         0x8000637C
    // 0x8001B1C0: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    func_8000637C(rdram, ctx);
        goto after_2;
    // 0x8001B1C0: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_2:
    // 0x8001B1C4: j           L_8001B264
    // 0x8001B1C8: nop

        goto L_8001B264;
    // 0x8001B1C8: nop

L_8001B1CC:
    // 0x8001B1CC: lw          $v0, 0x60($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X60);
    // 0x8001B1D0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001B1D4: bne         $v0, $zero, L_8001B264
    if (ctx->r2 != 0) {
        // 0x8001B1D8: sw          $v0, 0x60($s1)
        MEM_W(0X60, ctx->r17) = ctx->r2;
            goto L_8001B264;
    }
    // 0x8001B1D8: sw          $v0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r2;
    // 0x8001B1DC: lw          $a0, 0x5C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X5C);
    // 0x8001B1E0: lw          $v0, 0x48($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X48);
    // 0x8001B1E4: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8001B1E8: sw          $v1, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r3;
    // 0x8001B1EC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001B1F0: addiu       $v1, $v1, 0x1774
    ctx->r3 = ADD32(ctx->r3, 0X1774);
    // 0x8001B1F4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001B1F8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001B1FC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001B200: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001B204: sw          $a0, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->r4;
    // 0x8001B208: lb          $a1, 0x0($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X0);
    // 0x8001B20C: beq         $a1, $zero, L_8001B224
    if (ctx->r5 == 0) {
        // 0x8001B210: addiu       $a0, $zero, 0x40
        ctx->r4 = ADD32(0, 0X40);
            goto L_8001B224;
    }
    // 0x8001B210: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x8001B214: jal         0x8001D470
    // 0x8001B218: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001D470(rdram, ctx);
        goto after_3;
    // 0x8001B218: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
    // 0x8001B21C: j           L_8001B264
    // 0x8001B220: nop

        goto L_8001B264;
    // 0x8001B220: nop

L_8001B224:
    // 0x8001B224: lw          $a1, 0x44($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X44);
    // 0x8001B228: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001B22C: jal         0x8000637C
    // 0x8001B230: sb          $v0, 0x2B($s1)
    MEM_B(0X2B, ctx->r17) = ctx->r2;
    func_8000637C(rdram, ctx);
        goto after_4;
    // 0x8001B230: sb          $v0, 0x2B($s1)
    MEM_B(0X2B, ctx->r17) = ctx->r2;
    after_4:
    // 0x8001B234: j           L_8001B264
    // 0x8001B238: nop

        goto L_8001B264;
    // 0x8001B238: nop

L_8001B23C:
    // 0x8001B23C: lbu         $v1, 0x2F($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X2F);
    // 0x8001B240: sltiu       $v0, $v1, 0xB
    ctx->r2 = ctx->r3 < 0XB ? 1 : 0;
    // 0x8001B244: bne         $v0, $zero, L_8001B254
    if (ctx->r2 != 0) {
        // 0x8001B248: addiu       $v0, $v1, -0xA
        ctx->r2 = ADD32(ctx->r3, -0XA);
            goto L_8001B254;
    }
    // 0x8001B248: addiu       $v0, $v1, -0xA
    ctx->r2 = ADD32(ctx->r3, -0XA);
    // 0x8001B24C: j           L_8001B264
    // 0x8001B250: sb          $v0, 0x2F($s1)
    MEM_B(0X2F, ctx->r17) = ctx->r2;
        goto L_8001B264;
    // 0x8001B250: sb          $v0, 0x2F($s1)
    MEM_B(0X2F, ctx->r17) = ctx->r2;
L_8001B254:
    // 0x8001B254: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001B258: sb          $zero, 0x7B87($at)
    MEM_B(0X7B87, ctx->r1) = 0;
    // 0x8001B25C: jal         0x8001D564
    // 0x8001B260: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001D564(rdram, ctx);
        goto after_5;
    // 0x8001B260: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
L_8001B264:
    // 0x8001B264: jal         0x8001D160
    // 0x8001B268: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001D160(rdram, ctx);
        goto after_6;
    // 0x8001B268: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_6:
    // 0x8001B26C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8001B270: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8001B274: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001B278: jr          $ra
    // 0x8001B27C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001B27C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8001B280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B280: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001B284: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001B288: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001B28C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B290: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001B294: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x8001B298: beq         $v0, $zero, L_8001B3C4
    if (ctx->r2 == 0) {
        // 0x8001B29C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8001B3C4;
    }
    // 0x8001B29C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001B2A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001B2A4: addu        $at, $at, $v0
    gpr jr_addend_8001B2AC = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001B2A8: lw          $v0, -0x2DD0($at)
    ctx->r2 = ADD32(ctx->r1, -0X2DD0);
    // 0x8001B2AC: jr          $v0
    // 0x8001B2B0: nop

    switch (jr_addend_8001B2AC >> 2) {
        case 0: goto L_8001B2B4; break;
        case 1: goto L_8001B2F4; break;
        case 2: goto L_8001B314; break;
        case 3: goto L_8001B35C; break;
        case 4: goto L_8001B3A4; break;
        default: switch_error(__func__, 0x8001B2AC, 0x800AD230);
    }
    // 0x8001B2B0: nop

L_8001B2B4:
    // 0x8001B2B4: lbu         $v1, 0x29($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X29);
    // 0x8001B2B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001B2BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001B2C0: sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
    // 0x8001B2C4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8001B2C8: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x8001B2CC: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x8001B2D0: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x8001B2D4: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    // 0x8001B2D8: bne         $v1, $v0, L_8001B2E8
    if (ctx->r3 != ctx->r2) {
        // 0x8001B2DC: sb          $a0, 0x2B($s0)
        MEM_B(0X2B, ctx->r16) = ctx->r4;
            goto L_8001B2E8;
    }
    // 0x8001B2DC: sb          $a0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r4;
    // 0x8001B2E0: j           L_8001B3C4
    // 0x8001B2E4: sb          $a0, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r4;
        goto L_8001B3C4;
    // 0x8001B2E4: sb          $a0, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r4;
L_8001B2E8:
    // 0x8001B2E8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001B2EC: j           L_8001B3C4
    // 0x8001B2F0: sb          $v0, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r2;
        goto L_8001B3C4;
    // 0x8001B2F0: sb          $v0, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r2;
L_8001B2F4:
    // 0x8001B2F4: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x8001B2F8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001B2FC: bne         $v0, $zero, L_8001B3C4
    if (ctx->r2 != 0) {
        // 0x8001B300: sw          $v0, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->r2;
            goto L_8001B3C4;
    }
    // 0x8001B300: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x8001B304: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001B308: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x8001B30C: j           L_8001B398
    // 0x8001B310: sw          $v1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r3;
        goto L_8001B398;
    // 0x8001B310: sw          $v1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r3;
L_8001B314:
    // 0x8001B314: lbu         $v1, 0x29($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X29);
    // 0x8001B318: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
    // 0x8001B31C: bne         $v1, $v0, L_8001B330
    if (ctx->r3 != ctx->r2) {
        // 0x8001B320: nop
    
            goto L_8001B330;
    }
    // 0x8001B320: nop

    // 0x8001B324: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8001B328: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001B32C: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
L_8001B330:
    // 0x8001B330: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x8001B334: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001B338: bne         $v0, $zero, L_8001B3C4
    if (ctx->r2 != 0) {
        // 0x8001B33C: sw          $v0, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->r2;
            goto L_8001B3C4;
    }
    // 0x8001B33C: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x8001B340: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001B344: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001B348: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x8001B34C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001B350: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001B354: j           L_8001B3C4
    // 0x8001B358: sh          $v0, 0x558E($at)
    MEM_H(0X558E, ctx->r1) = ctx->r2;
        goto L_8001B3C4;
    // 0x8001B358: sh          $v0, 0x558E($at)
    MEM_H(0X558E, ctx->r1) = ctx->r2;
L_8001B35C:
    // 0x8001B35C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001B360: lh          $v1, 0x558E($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X558E);
    // 0x8001B364: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001B368: bne         $v1, $v0, L_8001B380
    if (ctx->r3 != ctx->r2) {
        // 0x8001B36C: addiu       $v0, $zero, 0x1F
        ctx->r2 = ADD32(0, 0X1F);
            goto L_8001B380;
    }
    // 0x8001B36C: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    // 0x8001B370: lbu         $v1, 0x29($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X29);
    // 0x8001B374: bne         $v1, $v0, L_8001B380
    if (ctx->r3 != ctx->r2) {
        // 0x8001B378: addiu       $v0, $zero, 0x64
        ctx->r2 = ADD32(0, 0X64);
            goto L_8001B380;
    }
    // 0x8001B378: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x8001B37C: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
L_8001B380:
    // 0x8001B380: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001B384: lbu         $v1, 0x7B87($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B87);
    // 0x8001B388: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001B38C: bne         $v1, $v0, L_8001B3C4
    if (ctx->r3 != ctx->r2) {
        // 0x8001B390: nop
    
            goto L_8001B3C4;
    }
    // 0x8001B390: nop

    // 0x8001B394: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
L_8001B398:
    // 0x8001B398: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001B39C: j           L_8001B3C4
    // 0x8001B3A0: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
        goto L_8001B3C4;
    // 0x8001B3A0: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_8001B3A4:
    // 0x8001B3A4: lbu         $v1, 0x2F($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2F);
    // 0x8001B3A8: sltiu       $v0, $v1, 0xB
    ctx->r2 = ctx->r3 < 0XB ? 1 : 0;
    // 0x8001B3AC: bne         $v0, $zero, L_8001B3BC
    if (ctx->r2 != 0) {
        // 0x8001B3B0: addiu       $v0, $v1, -0xA
        ctx->r2 = ADD32(ctx->r3, -0XA);
            goto L_8001B3BC;
    }
    // 0x8001B3B0: addiu       $v0, $v1, -0xA
    ctx->r2 = ADD32(ctx->r3, -0XA);
    // 0x8001B3B4: j           L_8001B3C4
    // 0x8001B3B8: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
        goto L_8001B3C4;
    // 0x8001B3B8: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
L_8001B3BC:
    // 0x8001B3BC: jal         0x8001D564
    // 0x8001B3C0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D564(rdram, ctx);
        goto after_0;
    // 0x8001B3C0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
L_8001B3C4:
    // 0x8001B3C4: jal         0x8001D160
    // 0x8001B3C8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D160(rdram, ctx);
        goto after_1;
    // 0x8001B3C8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8001B3CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B3D0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001B3D4: jr          $ra
    // 0x8001B3D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001B3D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001B3DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B3DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001B3E0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8001B3E4: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8001B3E8: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8001B3EC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8001B3F0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8001B3F4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001B3F8: lbu         $v1, 0x2B($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X2B);
    // 0x8001B3FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001B400: beq         $v1, $v0, L_8001B444
    if (ctx->r3 == ctx->r2) {
        // 0x8001B404: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8001B444;
    }
    // 0x8001B404: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8001B408: beql        $v0, $zero, L_8001B420
    if (ctx->r2 == 0) {
        // 0x8001B40C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8001B420;
    }
    goto skip_0;
    // 0x8001B40C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8001B410: beq         $v1, $zero, L_8001B430
    if (ctx->r3 == 0) {
        // 0x8001B414: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001B430;
    }
    // 0x8001B414: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001B418: j           L_8001B54C
    // 0x8001B41C: nop

        goto L_8001B54C;
    // 0x8001B41C: nop

L_8001B420:
    // 0x8001B420: beq         $v1, $v0, L_8001B4D4
    if (ctx->r3 == ctx->r2) {
        // 0x8001B424: nop
    
            goto L_8001B4D4;
    }
    // 0x8001B424: nop

    // 0x8001B428: j           L_8001B54C
    // 0x8001B42C: nop

        goto L_8001B54C;
    // 0x8001B42C: nop

L_8001B430:
    // 0x8001B430: sb          $v0, 0x2B($s1)
    MEM_B(0X2B, ctx->r17) = ctx->r2;
    // 0x8001B434: addiu       $v0, $zero, 0x5F
    ctx->r2 = ADD32(0, 0X5F);
    // 0x8001B438: sw          $v0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r2;
    // 0x8001B43C: j           L_8001B54C
    // 0x8001B440: sw          $zero, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = 0;
        goto L_8001B54C;
    // 0x8001B440: sw          $zero, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = 0;
L_8001B444:
    // 0x8001B444: lw          $v0, 0x60($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X60);
    // 0x8001B448: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001B44C: bne         $v0, $zero, L_8001B54C
    if (ctx->r2 != 0) {
        // 0x8001B450: sw          $v0, 0x60($s1)
        MEM_W(0X60, ctx->r17) = ctx->r2;
            goto L_8001B54C;
    }
    // 0x8001B450: sw          $v0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r2;
    // 0x8001B454: lbu         $v1, 0x29($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X29);
    // 0x8001B458: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
    // 0x8001B45C: bne         $v1, $v0, L_8001B474
    if (ctx->r3 != ctx->r2) {
        // 0x8001B460: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_8001B474;
    }
    // 0x8001B460: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8001B464: jal         0x8001D564
    // 0x8001B468: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001D564(rdram, ctx);
        goto after_0;
    // 0x8001B468: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x8001B46C: j           L_8001B554
    // 0x8001B470: nop

        goto L_8001B554;
    // 0x8001B470: nop

L_8001B474:
    // 0x8001B474: sw          $v0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->r2;
    // 0x8001B478: lw          $v0, 0x5C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X5C);
    // 0x8001B47C: xori        $v1, $v1, 0x15
    ctx->r3 = ctx->r3 ^ 0X15;
    // 0x8001B480: sltu        $s0, $zero, $v1
    ctx->r16 = 0 < ctx->r3 ? 1 : 0;
    // 0x8001B484: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001B488: addiu       $v1, $v1, 0x177C
    ctx->r3 = ADD32(ctx->r3, 0X177C);
    // 0x8001B48C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001B490: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001B494: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8001B498: lb          $s0, 0x0($v0)
    ctx->r16 = MEM_B(ctx->r2, 0X0);
    // 0x8001B49C: bne         $s0, $zero, L_8001B4BC
    if (ctx->r16 != 0) {
        // 0x8001B4A0: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8001B4BC;
    }
    // 0x8001B4A0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8001B4A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001B4A8: sb          $v0, 0x2B($s1)
    MEM_B(0X2B, ctx->r17) = ctx->r2;
    // 0x8001B4AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001B4B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001B4B4: j           L_8001B554
    // 0x8001B4B8: sb          $v0, 0x7B87($at)
    MEM_B(0X7B87, ctx->r1) = ctx->r2;
        goto L_8001B554;
    // 0x8001B4B8: sb          $v0, 0x7B87($at)
    MEM_B(0X7B87, ctx->r1) = ctx->r2;
L_8001B4BC:
    // 0x8001B4BC: jal         0x8001D470
    // 0x8001B4C0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8001D470(rdram, ctx);
        goto after_1;
    // 0x8001B4C0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8001B4C4: lw          $v0, 0x5C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X5C);
    // 0x8001B4C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001B4CC: j           L_8001B54C
    // 0x8001B4D0: sw          $v0, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->r2;
        goto L_8001B54C;
    // 0x8001B4D0: sw          $v0, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->r2;
L_8001B4D4:
    // 0x8001B4D4: jal         0x8001D564
    // 0x8001B4D8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001D564(rdram, ctx);
        goto after_2;
    // 0x8001B4D8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x8001B4DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001B4E0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001B4E4: sb          $v0, 0x5585($at)
    MEM_B(0X5585, ctx->r1) = ctx->r2;
    // 0x8001B4E8: lbu         $v1, 0x29($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X29);
    // 0x8001B4EC: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x8001B4F0: bne         $v1, $v0, L_8001B54C
    if (ctx->r3 != ctx->r2) {
        // 0x8001B4F4: addiu       $a0, $zero, 0x1F
        ctx->r4 = ADD32(0, 0X1F);
            goto L_8001B54C;
    }
    // 0x8001B4F4: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x8001B4F8: lw          $a1, 0x44($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X44);
    // 0x8001B4FC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8001B500: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8001B504: jal         0x8000637C
    // 0x8001B508: addiu       $s2, $zero, 0x18
    ctx->r18 = ADD32(0, 0X18);
    func_8000637C(rdram, ctx);
        goto after_3;
    // 0x8001B508: addiu       $s2, $zero, 0x18
    ctx->r18 = ADD32(0, 0X18);
    after_3:
    // 0x8001B50C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001B510: sh          $zero, 0x558E($at)
    MEM_H(0X558E, ctx->r1) = 0;
L_8001B514:
    // 0x8001B514: jal         0x8001D520
    // 0x8001B518: lw          $a0, 0x44($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X44);
    func_8001D520(rdram, ctx);
        goto after_4;
    // 0x8001B518: lw          $a0, 0x44($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X44);
    after_4:
    // 0x8001B51C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8001B520: beql        $v1, $zero, L_8001B540
    if (ctx->r3 == 0) {
        // 0x8001B524: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8001B540;
    }
    goto skip_1;
    // 0x8001B524: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x8001B528: sb          $s3, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r19;
    // 0x8001B52C: sb          $s2, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r18;
    // 0x8001B530: lw          $v0, 0x44($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X44);
    // 0x8001B534: sw          $s0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r16;
    // 0x8001B538: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
    // 0x8001B53C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8001B540:
    // 0x8001B540: slti        $v0, $s0, 0xF
    ctx->r2 = SIGNED(ctx->r16) < 0XF ? 1 : 0;
    // 0x8001B544: bne         $v0, $zero, L_8001B514
    if (ctx->r2 != 0) {
        // 0x8001B548: nop
    
            goto L_8001B514;
    }
    // 0x8001B548: nop

L_8001B54C:
    // 0x8001B54C: jal         0x8001D160
    // 0x8001B550: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001D160(rdram, ctx);
        goto after_5;
    // 0x8001B550: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
L_8001B554:
    // 0x8001B554: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8001B558: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B55C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8001B560: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8001B564: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001B568: jr          $ra
    // 0x8001B56C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001B56C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8001B570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B570: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B574: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001B578: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001B57C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8001B580: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8001B584: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001B588: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001B58C: beq         $v1, $v0, L_8001B67C
    if (ctx->r3 == ctx->r2) {
        // 0x8001B590: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8001B67C;
    }
    // 0x8001B590: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8001B594: beql        $v0, $zero, L_8001B5AC
    if (ctx->r2 == 0) {
        // 0x8001B598: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8001B5AC;
    }
    goto skip_0;
    // 0x8001B598: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x8001B59C: beq         $v1, $zero, L_8001B5C4
    if (ctx->r3 == 0) {
        // 0x8001B5A0: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8001B5C4;
    }
    // 0x8001B5A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8001B5A4: j           L_8001B7E0
    // 0x8001B5A8: nop

        goto L_8001B7E0;
    // 0x8001B5A8: nop

L_8001B5AC:
    // 0x8001B5AC: beq         $v1, $v0, L_8001B6F4
    if (ctx->r3 == ctx->r2) {
        // 0x8001B5B0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8001B6F4;
    }
    // 0x8001B5B0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001B5B4: beq         $v1, $v0, L_8001B7A8
    if (ctx->r3 == ctx->r2) {
        // 0x8001B5B8: nop
    
            goto L_8001B7A8;
    }
    // 0x8001B5B8: nop

    // 0x8001B5BC: j           L_8001B7E0
    // 0x8001B5C0: nop

        goto L_8001B7E0;
    // 0x8001B5C0: nop

L_8001B5C4:
    // 0x8001B5C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001B5C8: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x8001B5CC: jal         0x8001D578
    // 0x8001B5D0: sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
    func_8001D578(rdram, ctx);
        goto after_0;
    // 0x8001B5D0: sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
    after_0:
    // 0x8001B5D4: lw          $v1, 0x48($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X48);
    // 0x8001B5D8: addiu       $v0, $zero, 0x960
    ctx->r2 = ADD32(0, 0X960);
    // 0x8001B5DC: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x8001B5E0: addiu       $v0, $zero, 0x38C
    ctx->r2 = ADD32(0, 0X38C);
    // 0x8001B5E4: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x8001B5E8: lw          $v0, 0x48($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X48);
    // 0x8001B5EC: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8001B5F0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001B5F4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8001B5F8: lb          $v1, 0x17A5($at)
    ctx->r3 = MEM_B(ctx->r1, 0X17A5);
    // 0x8001B5FC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001B600: sw          $v1, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r3;
    // 0x8001B604: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001B608: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001B60C: lb          $v1, 0x17A4($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X17A4);
    // 0x8001B610: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8001B614: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001B618: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001B61C: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8001B620: lb          $a1, 0x1784($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X1784);
    // 0x8001B624: jal         0x8001D470
    // 0x8001B628: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D470(rdram, ctx);
        goto after_1;
    // 0x8001B628: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8001B62C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001B630: nop

    // 0x8001B634: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x8001B638: jal         0x8006CEB0
    // 0x8001B63C: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    func_8006CEB0(rdram, ctx);
        goto after_2;
    // 0x8001B63C: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    after_2:
    // 0x8001B640: lui         $v1, 0x8888
    ctx->r3 = S32(0X8888 << 16);
    // 0x8001B644: ori         $v1, $v1, 0x8889
    ctx->r3 = ctx->r3 | 0X8889;
    // 0x8001B648: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B64C: sra         $v1, $v0, 31
    ctx->r3 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8001B650: mfhi        $a2
    ctx->r6 = hi;
    // 0x8001B654: addu        $a0, $a2, $v0
    ctx->r4 = ADD32(ctx->r6, ctx->r2);
    // 0x8001B658: sra         $a0, $a0, 5
    ctx->r4 = S32(SIGNED(ctx->r4) >> 5);
    // 0x8001B65C: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x8001B660: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x8001B664: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8001B668: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8001B66C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8001B670: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001B674: j           L_8001B7E0
    // 0x8001B678: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
        goto L_8001B7E0;
    // 0x8001B678: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
L_8001B67C:
    // 0x8001B67C: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x8001B680: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001B684: bne         $v0, $zero, L_8001B7E0
    if (ctx->r2 != 0) {
        // 0x8001B688: sw          $v0, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->r2;
            goto L_8001B7E0;
    }
    // 0x8001B688: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x8001B68C: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x8001B690: jal         0x8006CEB0
    // 0x8001B694: sb          $s1, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r17;
    func_8006CEB0(rdram, ctx);
        goto after_3;
    // 0x8001B694: sb          $s1, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r17;
    after_3:
    // 0x8001B698: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8001B69C: bltzl       $a0, L_8001B6A4
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001B6A0: addiu       $v0, $a0, 0x7
        ctx->r2 = ADD32(ctx->r4, 0X7);
            goto L_8001B6A4;
    }
    goto skip_1;
    // 0x8001B6A0: addiu       $v0, $a0, 0x7
    ctx->r2 = ADD32(ctx->r4, 0X7);
    skip_1:
L_8001B6A4:
    // 0x8001B6A4: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8001B6A8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8001B6AC: lw          $v1, 0x48($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X48);
    // 0x8001B6B0: subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // 0x8001B6B4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001B6B8: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x8001B6BC: sb          $s1, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = ctx->r17;
    // 0x8001B6C0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8001B6C4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001B6C8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8001B6CC: lb          $v1, 0x17A4($at)
    ctx->r3 = MEM_B(ctx->r1, 0X17A4);
    // 0x8001B6D0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8001B6D4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001B6D8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001B6DC: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8001B6E0: lb          $a1, 0x1785($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X1785);
    // 0x8001B6E4: jal         0x8001D470
    // 0x8001B6E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D470(rdram, ctx);
        goto after_4;
    // 0x8001B6E8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8001B6EC: j           L_8001B7E0
    // 0x8001B6F0: nop

        goto L_8001B7E0;
    // 0x8001B6F0: nop

L_8001B6F4:
    // 0x8001B6F4: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x8001B6F8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001B6FC: sra         $v0, $v0, 18
    ctx->r2 = S32(SIGNED(ctx->r2) >> 18);
    // 0x8001B700: slti        $v0, $v0, 0xDD
    ctx->r2 = SIGNED(ctx->r2) < 0XDD ? 1 : 0;
    // 0x8001B704: bne         $v0, $zero, L_8001B710
    if (ctx->r2 != 0) {
        // 0x8001B708: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8001B710;
    }
    // 0x8001B708: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001B70C: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_8001B710:
    // 0x8001B710: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x8001B714: beq         $v0, $zero, L_8001B754
    if (ctx->r2 == 0) {
        // 0x8001B718: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8001B754;
    }
    // 0x8001B718: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001B71C: bne         $v0, $zero, L_8001B754
    if (ctx->r2 != 0) {
        // 0x8001B720: sw          $v0, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->r2;
            goto L_8001B754;
    }
    // 0x8001B720: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x8001B724: lw          $v0, 0x48($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X48);
    // 0x8001B728: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001B72C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001B730: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001B734: lb          $v1, 0x17A4($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X17A4);
    // 0x8001B738: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8001B73C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001B740: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001B744: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8001B748: lb          $a1, 0x1786($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X1786);
    // 0x8001B74C: jal         0x8001D470
    // 0x8001B750: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D470(rdram, ctx);
        goto after_5;
    // 0x8001B750: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
L_8001B754:
    // 0x8001B754: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8001B758: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001B75C: ldc1        $f2, -0x2DB8($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2DB8);
    // 0x8001B760: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001B764: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8001B768: lwc1        $f2, 0x3C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8001B76C: lw          $v0, 0x48($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X48);
    // 0x8001B770: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001B774: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8001B778: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001B77C: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x8001B780: swc1        $f2, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f2.u32l;
    // 0x8001B784: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001B788: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001B78C: lb          $v0, 0x17A5($at)
    ctx->r2 = MEM_B(ctx->r1, 0X17A5);
    // 0x8001B790: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001B794: mfc1        $v1, $f0
    ctx->r3 = (int32_t)ctx->f0.u32l;
    // 0x8001B798: nop

    // 0x8001B79C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001B7A0: j           L_8001B7E0
    // 0x8001B7A4: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
        goto L_8001B7E0;
    // 0x8001B7A4: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
L_8001B7A8:
    // 0x8001B7A8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001B7AC: addiu       $v1, $v1, 0x558E
    ctx->r3 = ADD32(ctx->r3, 0X558E);
    // 0x8001B7B0: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8001B7B4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001B7B8: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8001B7BC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001B7C0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001B7C4: slti        $v0, $v0, 0x1E
    ctx->r2 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x8001B7C8: bne         $v0, $zero, L_8001B7D8
    if (ctx->r2 != 0) {
        // 0x8001B7CC: nop
    
            goto L_8001B7D8;
    }
    // 0x8001B7CC: nop

    // 0x8001B7D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001B7D4: sb          $zero, 0x7B87($at)
    MEM_B(0X7B87, ctx->r1) = 0;
L_8001B7D8:
    // 0x8001B7D8: jal         0x8001D564
    // 0x8001B7DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D564(rdram, ctx);
        goto after_6;
    // 0x8001B7DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
L_8001B7E0:
    // 0x8001B7E0: jal         0x8001D160
    // 0x8001B7E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D160(rdram, ctx);
        goto after_7;
    // 0x8001B7E4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // 0x8001B7E8: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8001B7EC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8001B7F0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001B7F4: jr          $ra
    // 0x8001B7F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001B7F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8001B7FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B7FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001B800: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001B804: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8001B808: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B80C: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001B810: sltiu       $v0, $v1, 0xA
    ctx->r2 = ctx->r3 < 0XA ? 1 : 0;
    // 0x8001B814: beq         $v0, $zero, L_8001BAFC
    if (ctx->r2 == 0) {
        // 0x8001B818: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8001BAFC;
    }
    // 0x8001B818: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001B81C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001B820: addu        $at, $at, $v0
    gpr jr_addend_8001B828 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001B824: lw          $v0, -0x2DB0($at)
    ctx->r2 = ADD32(ctx->r1, -0X2DB0);
    // 0x8001B828: jr          $v0
    // 0x8001B82C: nop

    switch (jr_addend_8001B828 >> 2) {
        case 0: goto L_8001B830; break;
        case 1: goto L_8001B870; break;
        case 2: goto L_8001B890; break;
        case 3: goto L_8001B8B8; break;
        case 4: goto L_8001B90C; break;
        case 5: goto L_8001B95C; break;
        case 6: goto L_8001B9EC; break;
        case 7: goto L_8001BA24; break;
        case 8: goto L_8001BA50; break;
        case 9: goto L_8001BAD4; break;
        default: switch_error(__func__, 0x8001B828, 0x800AD250);
    }
    // 0x8001B82C: nop

L_8001B830:
    // 0x8001B830: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001B834: lui         $at, 0x3F33
    ctx->r1 = S32(0X3F33 << 16);
    // 0x8001B838: ori         $at, $at, 0x3333
    ctx->r1 = ctx->r1 | 0X3333;
    // 0x8001B83C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001B840: lui         $at, 0x3EB3
    ctx->r1 = S32(0X3EB3 << 16);
    // 0x8001B844: ori         $at, $at, 0x3333
    ctx->r1 = ctx->r1 | 0X3333;
    // 0x8001B848: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001B84C: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x8001B850: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x8001B854: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001B858: sb          $v1, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r3;
    // 0x8001B85C: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x8001B860: swc1        $f2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f2.u32l;
    // 0x8001B864: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001B868: j           L_8001BAFC
    // 0x8001B86C: sw          $s0, 0x5590($at)
    MEM_W(0X5590, ctx->r1) = ctx->r16;
        goto L_8001BAFC;
    // 0x8001B86C: sw          $s0, 0x5590($at)
    MEM_W(0X5590, ctx->r1) = ctx->r16;
L_8001B870:
    // 0x8001B870: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x8001B874: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001B878: bne         $v0, $zero, L_8001BAFC
    if (ctx->r2 != 0) {
        // 0x8001B87C: sw          $v0, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->r2;
            goto L_8001BAFC;
    }
    // 0x8001B87C: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x8001B880: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001B884: addiu       $v1, $zero, 0x1E
    ctx->r3 = ADD32(0, 0X1E);
    // 0x8001B888: j           L_8001B9E0
    // 0x8001B88C: sw          $v1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r3;
        goto L_8001B9E0;
    // 0x8001B88C: sw          $v1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r3;
L_8001B890:
    // 0x8001B890: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x8001B894: lw          $v1, 0x60($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X60);
    // 0x8001B898: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x8001B89C: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8001B8A0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8001B8A4: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x8001B8A8: bne         $v1, $zero, L_8001BAFC
    if (ctx->r3 != 0) {
        // 0x8001B8AC: sw          $v1, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->r3;
            goto L_8001BAFC;
    }
    // 0x8001B8AC: sw          $v1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r3;
    // 0x8001B8B0: j           L_8001B9DC
    // 0x8001B8B4: nop

        goto L_8001B9DC;
    // 0x8001B8B4: nop

L_8001B8B8:
    // 0x8001B8B8: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001B8BC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001B8C0: ldc1        $f2, -0x2D88($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2D88);
    // 0x8001B8C4: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8001B8C8: cvt.d.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f4.d = CVT_D_S(ctx->f4.fl);
    // 0x8001B8CC: add.d       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f4.d + ctx->f2.d;
    // 0x8001B8D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001B8D4: ldc1        $f2, -0x2D80($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2D80);
    // 0x8001B8D8: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001B8DC: add.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = ctx->f0.d + ctx->f2.d;
    // 0x8001B8E0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001B8E4: ldc1        $f6, -0x2D78($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2D78);
    // 0x8001B8E8: cvt.s.d     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f4.fl = CVT_S_D(ctx->f4.d);
    // 0x8001B8EC: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x8001B8F0: c.le.d      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.d <= ctx->f2.d;
    // 0x8001B8F4: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    // 0x8001B8F8: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001B8FC: bc1f        L_8001BAFC
    if (!c1cs) {
        // 0x8001B900: swc1        $f0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
            goto L_8001BAFC;
    }
    // 0x8001B900: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x8001B904: j           L_8001B9DC
    // 0x8001B908: nop

        goto L_8001B9DC;
    // 0x8001B908: nop

L_8001B90C:
    // 0x8001B90C: lwc1        $f2, 0x38($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001B910: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001B914: ldc1        $f4, -0x2D70($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2D70);
    // 0x8001B918: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8001B91C: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001B920: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x8001B924: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001B928: sub.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f0.d - ctx->f4.d;
    // 0x8001B92C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001B930: ldc1        $f6, -0x2D68($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2D68);
    // 0x8001B934: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8001B938: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8001B93C: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001B940: c.le.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d <= ctx->f6.d;
    // 0x8001B944: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x8001B948: nop

    // 0x8001B94C: bc1f        L_8001BAFC
    if (!c1cs) {
        // 0x8001B950: swc1        $f2, 0x38($s0)
        MEM_W(0X38, ctx->r16) = ctx->f2.u32l;
            goto L_8001BAFC;
    }
    // 0x8001B950: swc1        $f2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f2.u32l;
    // 0x8001B954: j           L_8001B9DC
    // 0x8001B958: nop

        goto L_8001B9DC;
    // 0x8001B958: nop

L_8001B95C:
    // 0x8001B95C: lwc1        $f2, 0x38($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8001B960: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001B964: ldc1        $f4, -0x2D60($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X2D60);
    // 0x8001B968: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8001B96C: cvt.d.s     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.d = CVT_D_S(ctx->f2.fl);
    // 0x8001B970: add.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d + ctx->f4.d;
    // 0x8001B974: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8001B978: add.d       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f0.d + ctx->f4.d;
    // 0x8001B97C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001B980: ldc1        $f6, -0x2D58($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2D58);
    // 0x8001B984: cvt.s.d     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f2.fl = CVT_S_D(ctx->f2.d);
    // 0x8001B988: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8001B98C: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    // 0x8001B990: c.le.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d <= ctx->f4.d;
    // 0x8001B994: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x8001B998: nop

    // 0x8001B99C: bc1f        L_8001BAFC
    if (!c1cs) {
        // 0x8001B9A0: swc1        $f2, 0x38($s0)
        MEM_W(0X38, ctx->r16) = ctx->f2.u32l;
            goto L_8001BAFC;
    }
    // 0x8001B9A0: swc1        $f2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f2.u32l;
    // 0x8001B9A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001B9A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001B9AC: lbu         $v1, 0x29($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X29);
    // 0x8001B9B0: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    // 0x8001B9B4: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x8001B9B8: beq         $v1, $v0, L_8001BAF4
    if (ctx->r3 == ctx->r2) {
        // 0x8001B9BC: swc1        $f0, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
            goto L_8001BAF4;
    }
    // 0x8001B9BC: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x8001B9C0: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // 0x8001B9C4: bne         $v1, $v0, L_8001B9DC
    if (ctx->r3 != ctx->r2) {
        // 0x8001B9C8: nop
    
            goto L_8001B9DC;
    }
    // 0x8001B9C8: nop

    // 0x8001B9CC: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001B9D0: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8001B9D4: j           L_8001BAFC
    // 0x8001B9D8: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
        goto L_8001BAFC;
    // 0x8001B9D8: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_8001B9DC:
    // 0x8001B9DC: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
L_8001B9E0:
    // 0x8001B9E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001B9E4: j           L_8001BAFC
    // 0x8001B9E8: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
        goto L_8001BAFC;
    // 0x8001B9E8: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
L_8001B9EC:
    // 0x8001B9EC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001B9F0: lbu         $v1, 0x7B87($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B87);
    // 0x8001B9F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001B9F8: bne         $v1, $v0, L_8001BAFC
    if (ctx->r3 != ctx->r2) {
        // 0x8001B9FC: addiu       $v0, $zero, 0x1A
        ctx->r2 = ADD32(0, 0X1A);
            goto L_8001BAFC;
    }
    // 0x8001B9FC: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
    // 0x8001BA00: lbu         $v1, 0x29($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X29);
    // 0x8001BA04: beq         $v1, $v0, L_8001BAF4
    if (ctx->r3 == ctx->r2) {
        // 0x8001BA08: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_8001BAF4;
    }
    // 0x8001BA08: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8001BA0C: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    // 0x8001BA10: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001BA14: sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
    // 0x8001BA18: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8001BA1C: j           L_8001BAFC
    // 0x8001BA20: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
        goto L_8001BAFC;
    // 0x8001BA20: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
L_8001BA24:
    // 0x8001BA24: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001BA28: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001BA2C: sb          $v0, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r2;
    // 0x8001BA30: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8001BA34: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
    // 0x8001BA38: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8001BA3C: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x8001BA40: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    // 0x8001BA44: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001BA48: j           L_8001BAFC
    // 0x8001BA4C: sb          $v1, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r3;
        goto L_8001BAFC;
    // 0x8001BA4C: sb          $v1, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r3;
L_8001BA50:
    // 0x8001BA50: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x8001BA54: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001BA58: bne         $v0, $zero, L_8001BAFC
    if (ctx->r2 != 0) {
        // 0x8001BA5C: sw          $v0, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->r2;
            goto L_8001BAFC;
    }
    // 0x8001BA5C: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x8001BA60: lw          $v1, 0x5C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X5C);
    // 0x8001BA64: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8001BA68: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x8001BA6C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001BA70: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x8001BA74: lb          $a1, 0x17C4($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X17C4);
    // 0x8001BA78: beq         $a1, $zero, L_8001BA90
    if (ctx->r5 == 0) {
        // 0x8001BA7C: addiu       $a0, $zero, 0x40
        ctx->r4 = ADD32(0, 0X40);
            goto L_8001BA90;
    }
    // 0x8001BA7C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x8001BA80: jal         0x8001D470
    // 0x8001BA84: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D470(rdram, ctx);
        goto after_0;
    // 0x8001BA84: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8001BA88: j           L_8001BAC4
    // 0x8001BA8C: nop

        goto L_8001BAC4;
    // 0x8001BA8C: nop

L_8001BA90:
    // 0x8001BA90: lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2B);
    // 0x8001BA94: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x8001BA98: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001BA9C: jal         0x8000637C
    // 0x8001BAA0: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    func_8000637C(rdram, ctx);
        goto after_1;
    // 0x8001BAA0: sb          $v0, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r2;
    after_1:
    // 0x8001BAA4: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x8001BAA8: jal         0x8000637C
    // 0x8001BAAC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_8000637C(rdram, ctx);
        goto after_2;
    // 0x8001BAAC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_2:
    // 0x8001BAB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001BAB4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001BAB8: sb          $v0, 0x7B87($at)
    MEM_B(0X7B87, ctx->r1) = ctx->r2;
    // 0x8001BABC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001BAC0: sb          $v0, 0x5585($at)
    MEM_B(0X5585, ctx->r1) = ctx->r2;
L_8001BAC4:
    // 0x8001BAC4: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    // 0x8001BAC8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001BACC: j           L_8001BAFC
    // 0x8001BAD0: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
        goto L_8001BAFC;
    // 0x8001BAD0: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
L_8001BAD4:
    // 0x8001BAD4: lbu         $v1, 0x2F($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2F);
    // 0x8001BAD8: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x8001BADC: bne         $v0, $zero, L_8001BAEC
    if (ctx->r2 != 0) {
        // 0x8001BAE0: addiu       $v0, $v1, -0x5
        ctx->r2 = ADD32(ctx->r3, -0X5);
            goto L_8001BAEC;
    }
    // 0x8001BAE0: addiu       $v0, $v1, -0x5
    ctx->r2 = ADD32(ctx->r3, -0X5);
    // 0x8001BAE4: j           L_8001BAFC
    // 0x8001BAE8: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
        goto L_8001BAFC;
    // 0x8001BAE8: sb          $v0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r2;
L_8001BAEC:
    // 0x8001BAEC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001BAF0: sb          $zero, 0x7B87($at)
    MEM_B(0X7B87, ctx->r1) = 0;
L_8001BAF4:
    // 0x8001BAF4: jal         0x8001D564
    // 0x8001BAF8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D564(rdram, ctx);
        goto after_3;
    // 0x8001BAF8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
L_8001BAFC:
    // 0x8001BAFC: jal         0x8001D160
    // 0x8001BB00: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D160(rdram, ctx);
        goto after_4;
    // 0x8001BB00: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8001BB04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001BB08: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001BB0C: jr          $ra
    // 0x8001BB10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001BB10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001BB14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BB14: lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // 0x8001BB18: lw          $v0, -0x761C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X761C);
    // 0x8001BB1C: beq         $v0, $zero, L_8001BCB4
    if (ctx->r2 == 0) {
        // 0x8001BB20: andi        $v0, $v0, 0x4
        ctx->r2 = ctx->r2 & 0X4;
            goto L_8001BCB4;
    }
    // 0x8001BB20: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x8001BB24: beq         $v0, $zero, L_8001BB38
    if (ctx->r2 == 0) {
        // 0x8001BB28: addiu       $v0, $zero, 0x80
        ctx->r2 = ADD32(0, 0X80);
            goto L_8001BB38;
    }
    // 0x8001BB28: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x8001BB2C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001BB30: j           L_8001BB40
    // 0x8001BB34: sh          $v0, -0x7658($at)
    MEM_H(-0X7658, ctx->r1) = ctx->r2;
        goto L_8001BB40;
    // 0x8001BB34: sh          $v0, -0x7658($at)
    MEM_H(-0X7658, ctx->r1) = ctx->r2;
L_8001BB38:
    // 0x8001BB38: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001BB3C: sh          $zero, -0x7658($at)
    MEM_H(-0X7658, ctx->r1) = 0;
L_8001BB40:
    // 0x8001BB40: lui         $a3, 0x801E
    ctx->r7 = S32(0X801E << 16);
    // 0x8001BB44: addiu       $a3, $a3, -0x761C
    ctx->r7 = ADD32(ctx->r7, -0X761C);
    // 0x8001BB48: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8001BB4C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001BB50: bne         $v0, $zero, L_8001BB60
    if (ctx->r2 != 0) {
        // 0x8001BB54: sw          $v0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r2;
            goto L_8001BB60;
    }
    // 0x8001BB54: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8001BB58: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001BB5C: sb          $zero, 0x20D0($at)
    MEM_B(0X20D0, ctx->r1) = 0;
L_8001BB60:
    // 0x8001BB60: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001BB64: lbu         $v0, 0x20D0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X20D0);
    // 0x8001BB68: beq         $v0, $zero, L_8001BCB4
    if (ctx->r2 == 0) {
        // 0x8001BB6C: lui         $a1, 0x5
        ctx->r5 = S32(0X5 << 16);
            goto L_8001BCB4;
    }
    // 0x8001BB6C: lui         $a1, 0x5
    ctx->r5 = S32(0X5 << 16);
    // 0x8001BB70: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8001BB74: lhu         $a0, 0x20C4($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X20C4);
    // 0x8001BB78: addiu       $a0, $a0, 0x11
    ctx->r4 = ADD32(ctx->r4, 0X11);
    // 0x8001BB7C: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8001BB80: div         $zero, $a1, $v0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r2)));
    // 0x8001BB84: bne         $v0, $zero, L_8001BB90
    if (ctx->r2 != 0) {
        // 0x8001BB88: nop
    
            goto L_8001BB90;
    }
    // 0x8001BB88: nop

    // 0x8001BB8C: break       7
    do_break(2147597196);
L_8001BB90:
    // 0x8001BB90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001BB94: bne         $v0, $at, L_8001BBA8
    if (ctx->r2 != ctx->r1) {
        // 0x8001BB98: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001BBA8;
    }
    // 0x8001BB98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001BB9C: bne         $a1, $at, L_8001BBA8
    if (ctx->r5 != ctx->r1) {
        // 0x8001BBA0: nop
    
            goto L_8001BBA8;
    }
    // 0x8001BBA0: nop

    // 0x8001BBA4: break       6
    do_break(2147597220);
L_8001BBA8:
    // 0x8001BBA8: mflo        $a1
    ctx->r5 = lo;
    // 0x8001BBAC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001BBB0: lhu         $v1, 0x20C6($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X20C6);
    // 0x8001BBB4: lui         $a2, 0x3
    ctx->r6 = S32(0X3 << 16);
    // 0x8001BBB8: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x8001BBBC: addiu       $v1, $v1, 0x66
    ctx->r3 = ADD32(ctx->r3, 0X66);
    // 0x8001BBC0: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x8001BBC4: div         $zero, $a2, $v0
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r2)));
    // 0x8001BBC8: bne         $v0, $zero, L_8001BBD4
    if (ctx->r2 != 0) {
        // 0x8001BBCC: nop
    
            goto L_8001BBD4;
    }
    // 0x8001BBCC: nop

    // 0x8001BBD0: break       7
    do_break(2147597264);
L_8001BBD4:
    // 0x8001BBD4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001BBD8: bne         $v0, $at, L_8001BBEC
    if (ctx->r2 != ctx->r1) {
        // 0x8001BBDC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001BBEC;
    }
    // 0x8001BBDC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001BBE0: bne         $a2, $at, L_8001BBEC
    if (ctx->r6 != ctx->r1) {
        // 0x8001BBE4: nop
    
            goto L_8001BBEC;
    }
    // 0x8001BBE4: nop

    // 0x8001BBE8: break       6
    do_break(2147597288);
L_8001BBEC:
    // 0x8001BBEC: mflo        $a2
    ctx->r6 = lo;
    // 0x8001BBF0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001BBF4: sh          $a0, 0x20C4($at)
    MEM_H(0X20C4, ctx->r1) = ctx->r4;
    // 0x8001BBF8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8001BBFC: lbu         $a0, 0x20D3($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X20D3);
    // 0x8001BC00: addiu       $v0, $zero, 0x140
    ctx->r2 = ADD32(0, 0X140);
    // 0x8001BC04: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001BC08: sh          $v1, 0x20C6($at)
    MEM_H(0X20C6, ctx->r1) = ctx->r3;
    // 0x8001BC0C: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8001BC10: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x8001BC14: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001BC18: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8001BC1C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001BC20: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001BC24: sh          $v0, 0x20AC($at)
    MEM_H(0X20AC, ctx->r1) = ctx->r2;
    // 0x8001BC28: addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // 0x8001BC2C: subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // 0x8001BC30: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x8001BC34: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001BC38: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8001BC3C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001BC40: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8001BC44: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001BC48: sh          $v0, 0x20B4($at)
    MEM_H(0X20B4, ctx->r1) = ctx->r2;
    // 0x8001BC4C: beq         $v1, $zero, L_8001BC64
    if (ctx->r3 == 0) {
        // 0x8001BC50: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001BC64;
    }
    // 0x8001BC50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001BC54: beq         $v1, $v0, L_8001BC8C
    if (ctx->r3 == ctx->r2) {
        // 0x8001BC58: nop
    
            goto L_8001BC8C;
    }
    // 0x8001BC58: nop

    // 0x8001BC5C: j           L_8001BCB4
    // 0x8001BC60: nop

        goto L_8001BCB4;
    // 0x8001BC60: nop

L_8001BC64:
    // 0x8001BC64: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8001BC68: slti        $v0, $v0, 0x1E
    ctx->r2 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x8001BC6C: beq         $v0, $zero, L_8001BCB4
    if (ctx->r2 == 0) {
        // 0x8001BC70: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8001BCB4;
    }
    // 0x8001BC70: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x8001BC74: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001BC78: sb          $v0, 0x20D3($at)
    MEM_B(0X20D3, ctx->r1) = ctx->r2;
    // 0x8001BC7C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001BC80: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001BC84: j           L_8001BCB4
    // 0x8001BC88: sb          $v0, 0x20D2($at)
    MEM_B(0X20D2, ctx->r1) = ctx->r2;
        goto L_8001BCB4;
    // 0x8001BC88: sb          $v0, 0x20D2($at)
    MEM_B(0X20D2, ctx->r1) = ctx->r2;
L_8001BC8C:
    // 0x8001BC8C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001BC90: lbu         $v1, 0x20D7($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X20D7);
    // 0x8001BC94: sltiu       $v0, $v1, 0x15
    ctx->r2 = ctx->r3 < 0X15 ? 1 : 0;
    // 0x8001BC98: bne         $v0, $zero, L_8001BCAC
    if (ctx->r2 != 0) {
        // 0x8001BC9C: addiu       $v0, $v1, -0xA
        ctx->r2 = ADD32(ctx->r3, -0XA);
            goto L_8001BCAC;
    }
    // 0x8001BC9C: addiu       $v0, $v1, -0xA
    ctx->r2 = ADD32(ctx->r3, -0XA);
    // 0x8001BCA0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001BCA4: j           L_8001BCB4
    // 0x8001BCA8: sb          $v0, 0x20D7($at)
    MEM_B(0X20D7, ctx->r1) = ctx->r2;
        goto L_8001BCB4;
    // 0x8001BCA8: sb          $v0, 0x20D7($at)
    MEM_B(0X20D7, ctx->r1) = ctx->r2;
L_8001BCAC:
    // 0x8001BCAC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8001BCB0: sb          $zero, 0x20D7($at)
    MEM_B(0X20D7, ctx->r1) = 0;
L_8001BCB4:
    // 0x8001BCB4: jr          $ra
    // 0x8001BCB8: nop

    return;
    // 0x8001BCB8: nop

;}
RECOMP_FUNC void func_8001BCBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BCBC: sw          $a1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r5;
    // 0x8001BCC0: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8001BCC4: sb          $v0, 0x68($a0)
    MEM_B(0X68, ctx->r4) = ctx->r2;
    // 0x8001BCC8: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
    // 0x8001BCCC: sb          $v0, 0x69($a0)
    MEM_B(0X69, ctx->r4) = ctx->r2;
    // 0x8001BCD0: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x8001BCD4: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // 0x8001BCD8: jr          $ra
    // 0x8001BCDC: sh          $v0, 0x6C($a0)
    MEM_H(0X6C, ctx->r4) = ctx->r2;
    return;
    // 0x8001BCDC: sh          $v0, 0x6C($a0)
    MEM_H(0X6C, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_8001BCE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BCE0: lbu         $v0, 0x68($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X68);
    // 0x8001BCE4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001BCE8: sb          $v0, 0x68($a0)
    MEM_B(0X68, ctx->r4) = ctx->r2;
    // 0x8001BCEC: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8001BCF0: bne         $v0, $zero, L_8001BD50
    if (ctx->r2 != 0) {
        // 0x8001BCF4: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_8001BD50;
    }
    // 0x8001BCF4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8001BCF8: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x8001BCFC: addiu       $a2, $a1, 0x4
    ctx->r6 = ADD32(ctx->r5, 0X4);
    // 0x8001BD00: sw          $a2, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r6;
    // 0x8001BD04: lbu         $v0, 0x5($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X5);
    // 0x8001BD08: andi        $v1, $v0, 0x40
    ctx->r3 = ctx->r2 & 0X40;
    // 0x8001BD0C: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8001BD10: bgez        $v0, L_8001BD28
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001BD14: sltu        $a3, $zero, $v1
        ctx->r7 = 0 < ctx->r3 ? 1 : 0;
            goto L_8001BD28;
    }
    // 0x8001BD14: sltu        $a3, $zero, $v1
    ctx->r7 = 0 < ctx->r3 ? 1 : 0;
    // 0x8001BD18: lh          $v0, 0x6($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X6);
    // 0x8001BD1C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001BD20: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x8001BD24: sw          $v0, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r2;
L_8001BD28:
    // 0x8001BD28: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8001BD2C: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x8001BD30: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x8001BD34: sb          $v0, 0x68($a0)
    MEM_B(0X68, ctx->r4) = ctx->r2;
    // 0x8001BD38: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x8001BD3C: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x8001BD40: sb          $v0, 0x69($a0)
    MEM_B(0X69, ctx->r4) = ctx->r2;
    // 0x8001BD44: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x8001BD48: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // 0x8001BD4C: sh          $v0, 0x6C($a0)
    MEM_H(0X6C, ctx->r4) = ctx->r2;
L_8001BD50:
    // 0x8001BD50: jr          $ra
    // 0x8001BD54: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    return;
    // 0x8001BD54: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
;}
RECOMP_FUNC void func_8001BD58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BD58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001BD5C: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x8001BD60: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8001BD64: lhu         $a2, 0x6C($a3)
    ctx->r6 = MEM_HU(ctx->r7, 0X6C);
    // 0x8001BD68: andi        $v0, $a2, 0x8000
    ctx->r2 = ctx->r6 & 0X8000;
    // 0x8001BD6C: beq         $v0, $zero, L_8001BE14
    if (ctx->r2 == 0) {
        // 0x8001BD70: nop
    
            goto L_8001BE14;
    }
    // 0x8001BD70: nop

    // 0x8001BD74: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8001BD78: addiu       $a1, $a1, 0x7B86
    ctx->r5 = ADD32(ctx->r5, 0X7B86);
    // 0x8001BD7C: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8001BD80: lw          $v0, 0x48($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X48);
    // 0x8001BD84: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8001BD88: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001BD8C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8001BD90: lw          $v1, -0x63F0($at)
    ctx->r3 = MEM_W(ctx->r1, -0X63F0);
    // 0x8001BD94: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001BD98: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001BD9C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8001BDA0: andi        $v0, $a2, 0x7FFF
    ctx->r2 = ctx->r6 & 0X7FFF;
    // 0x8001BDA4: sh          $v0, 0x6C($a3)
    MEM_H(0X6C, ctx->r7) = ctx->r2;
    // 0x8001BDA8: lhu         $v1, 0x6C($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X6C);
    // 0x8001BDAC: sh          $v0, 0x6E($a3)
    MEM_H(0X6E, ctx->r7) = ctx->r2;
    // 0x8001BDB0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8001BDB4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001BDB8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001BDBC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8001BDC0: lh          $a0, 0x4($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X4);
    // 0x8001BDC4: lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // 0x8001BDC8: addiu       $v1, $v1, -0x2F90
    ctx->r3 = ADD32(ctx->r3, -0X2F90);
    // 0x8001BDCC: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8001BDD0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001BDD4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001BDD8: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x8001BDDC: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8001BDE0: lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X8);
    // 0x8001BDE4: mult        $a0, $a2
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001BDE8: mflo        $a2
    ctx->r6 = lo;
    // 0x8001BDEC: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8001BDF0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001BDF4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001BDF8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001BDFC: lw          $v0, -0x6444($at)
    ctx->r2 = MEM_W(ctx->r1, -0X6444);
    // 0x8001BE00: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8001BE04: lw          $a1, 0x10($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X10);
    // 0x8001BE08: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8001BE0C: jal         0x80006B0C
    // 0x8001BE10: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_80006B0C(rdram, ctx);
        goto after_0;
    // 0x8001BE10: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_0:
L_8001BE14:
    // 0x8001BE14: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8001BE18: jr          $ra
    // 0x8001BE1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001BE1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001BE20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BE20: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001BE24: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x8001BE28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001BE2C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8001BE30: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8001BE34: lw          $v1, 0x48($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X48);
    // 0x8001BE38: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001BE3C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001BE40: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001BE44: lw          $v0, -0x63F0($at)
    ctx->r2 = MEM_W(ctx->r1, -0X63F0);
    // 0x8001BE48: lhu         $a0, 0x6C($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X6C);
    // 0x8001BE4C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8001BE50: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001BE54: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x8001BE58: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8001BE5C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001BE60: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001BE64: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x8001BE68: lh          $v1, 0x4($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X4);
    // 0x8001BE6C: addiu       $a2, $zero, 0xF6
    ctx->r6 = ADD32(0, 0XF6);
    // 0x8001BE70: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8001BE74: addiu       $a0, $a0, -0x2F90
    ctx->r4 = ADD32(ctx->r4, -0X2F90);
    // 0x8001BE78: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8001BE7C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001BE80: lw          $v1, 0x44($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X44);
    // 0x8001BE84: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001BE88: bne         $v1, $zero, L_8001BE94
    if (ctx->r3 != 0) {
        // 0x8001BE8C: addu        $a0, $v0, $a0
        ctx->r4 = ADD32(ctx->r2, ctx->r4);
            goto L_8001BE94;
    }
    // 0x8001BE8C: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // 0x8001BE90: addiu       $a2, $zero, 0x4A
    ctx->r6 = ADD32(0, 0X4A);
L_8001BE94:
    // 0x8001BE94: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8001BE98: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001BE9C: sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // 0x8001BEA0: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x8001BEA4: lhu         $v1, 0x1A($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X1A);
    // 0x8001BEA8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001BEAC: sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // 0x8001BEB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001BEB4: beq         $v1, $v0, L_8001BF0C
    if (ctx->r3 == ctx->r2) {
        // 0x8001BEB8: nop
    
            goto L_8001BF0C;
    }
    // 0x8001BEB8: nop

    // 0x8001BEBC: lh          $v0, 0x0($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X0);
    // 0x8001BEC0: lwc1        $f2, 0x34($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8001BEC4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8001BEC8: nop

    // 0x8001BECC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001BED0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001BED4: mtc1        $a2, $f2
    ctx->f2.u32l = ctx->r6;
    // 0x8001BED8: nop

    // 0x8001BEDC: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8001BEE0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8001BEE4: lwc1        $f4, 0x34($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8001BEE8: trunc.w.s   $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8001BEEC: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8001BEF0: nop

    // 0x8001BEF4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001BEF8: sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    // 0x8001BEFC: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001BF00: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001BF04: j           L_8001BF8C
    // 0x8001BF08: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
        goto L_8001BF8C;
    // 0x8001BF08: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
L_8001BF0C:
    // 0x8001BF0C: lh          $v0, 0x0($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X0);
    // 0x8001BF10: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8001BF14: lwc1        $f0, 0x34($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8001BF18: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001BF1C: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8001BF20: nop

    // 0x8001BF24: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8001BF28: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001BF2C: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x8001BF30: nop

    // 0x8001BF34: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001BF38: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8001BF3C: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001BF40: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8001BF44: nop

    // 0x8001BF48: bgez        $v1, L_8001BF78
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8001BF4C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8001BF78;
    }
    // 0x8001BF4C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001BF50: lwc1        $f2, 0x34($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8001BF54: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x8001BF58: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001BF5C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001BF60: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001BF64: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x8001BF68: nop

    // 0x8001BF6C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8001BF70: j           L_8001BF8C
    // 0x8001BF74: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_8001BF8C;
    // 0x8001BF74: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_8001BF78:
    // 0x8001BF78: lwc1        $f2, 0x34($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8001BF7C: sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    // 0x8001BF80: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001BF84: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001BF88: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
L_8001BF8C:
    // 0x8001BF8C: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001BF90: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8001BF94: nop

    // 0x8001BF98: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001BF9C: sh          $v0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r2;
    // 0x8001BFA0: lw          $v0, 0x44($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X44);
    // 0x8001BFA4: bne         $v0, $zero, L_8001BFB8
    if (ctx->r2 != 0) {
        // 0x8001BFA8: nop
    
            goto L_8001BFB8;
    }
    // 0x8001BFA8: nop

    // 0x8001BFAC: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x8001BFB0: j           L_8001BFC0
    // 0x8001BFB4: lb          $a2, 0x25F8($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X25F8);
        goto L_8001BFC0;
    // 0x8001BFB4: lb          $a2, 0x25F8($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X25F8);
L_8001BFB8:
    // 0x8001BFB8: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x8001BFBC: lb          $a2, 0x7A48($a2)
    ctx->r6 = MEM_B(ctx->r6, 0X7A48);
L_8001BFC0:
    // 0x8001BFC0: lh          $v1, 0x2($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X2);
    // 0x8001BFC4: addiu       $v0, $zero, -0x90
    ctx->r2 = ADD32(0, -0X90);
    // 0x8001BFC8: lwc1        $f0, 0x34($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8001BFCC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8001BFD0: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8001BFD4: nop

    // 0x8001BFD8: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8001BFDC: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001BFE0: addiu       $v0, $a2, 0x48
    ctx->r2 = ADD32(ctx->r6, 0X48);
    // 0x8001BFE4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8001BFE8: nop

    // 0x8001BFEC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001BFF0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8001BFF4: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001BFF8: mfc1        $v1, $f2
    ctx->r3 = (int32_t)ctx->f2.u32l;
    // 0x8001BFFC: nop

    // 0x8001C000: bgez        $v1, L_8001C03C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8001C004: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8001C03C;
    }
    // 0x8001C004: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001C008: lwc1        $f2, 0x34($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8001C00C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x8001C010: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8001C014: sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // 0x8001C018: sh          $zero, 0xC($a1)
    MEM_H(0XC, ctx->r5) = 0;
    // 0x8001C01C: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8001C020: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001C024: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001C028: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x8001C02C: nop

    // 0x8001C030: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8001C034: j           L_8001C054
    // 0x8001C038: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_8001C054;
    // 0x8001C038: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_8001C03C:
    // 0x8001C03C: lwc1        $f2, 0x34($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8001C040: sh          $zero, 0x8($a1)
    MEM_H(0X8, ctx->r5) = 0;
    // 0x8001C044: sh          $v0, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r2;
    // 0x8001C048: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8001C04C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001C050: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
L_8001C054:
    // 0x8001C054: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001C058: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8001C05C: nop

    // 0x8001C060: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001C064: sh          $v0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r2;
    // 0x8001C068: lbu         $v0, 0x2A($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X2A);
    // 0x8001C06C: beq         $v0, $zero, L_8001C0BC
    if (ctx->r2 == 0) {
        // 0x8001C070: nop
    
            goto L_8001C0BC;
    }
    // 0x8001C070: nop

    // 0x8001C074: lwc1        $f4, 0x34($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8001C078: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8001C07C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001C080: nop

    // 0x8001C084: div.s       $f4, $f2, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8001C088: lwc1        $f0, 0x34($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8001C08C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001C090: lhu         $v0, 0x8($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X8);
    // 0x8001C094: sw          $v0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r2;
    // 0x8001C098: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001C09C: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8001C0A0: nop

    // 0x8001C0A4: sh          $v0, 0x1E($a1)
    MEM_H(0X1E, ctx->r5) = ctx->r2;
    // 0x8001C0A8: trunc.w.s   $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8001C0AC: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x8001C0B0: nop

    // 0x8001C0B4: j           L_8001C0C4
    // 0x8001C0B8: sh          $v0, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r2;
        goto L_8001C0C4;
    // 0x8001C0B8: sh          $v0, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r2;
L_8001C0BC:
    // 0x8001C0BC: jal         0x80066D30
    // 0x8001C0C0: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    func_80066D30(rdram, ctx);
        goto after_0;
    // 0x8001C0C0: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    after_0:
L_8001C0C4:
    // 0x8001C0C4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8001C0C8: jr          $ra
    // 0x8001C0CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001C0CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001C0D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C0D0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8001C0D4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001C0D8: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x8001C0DC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x8001C0E0: addiu       $a3, $a3, 0x3520
    ctx->r7 = ADD32(ctx->r7, 0X3520);
    // 0x8001C0E4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001C0E8: lui         $t4, 0x8008
    ctx->r12 = S32(0X8008 << 16);
    // 0x8001C0EC: addu        $t4, $t4, $v0
    ctx->r12 = ADD32(ctx->r12, ctx->r2);
    // 0x8001C0F0: lw          $t4, -0x6428($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6428);
    // 0x8001C0F4: beq         $a0, $zero, L_8001C104
    if (ctx->r4 == 0) {
        // 0x8001C0F8: addiu       $t2, $zero, -0x1
        ctx->r10 = ADD32(0, -0X1);
            goto L_8001C104;
    }
    // 0x8001C0F8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8001C0FC: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x8001C100: addiu       $a3, $a3, 0x6AA0
    ctx->r7 = ADD32(ctx->r7, 0X6AA0);
L_8001C104:
    // 0x8001C104: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8001C108: bne         $a1, $v0, L_8001C120
    if (ctx->r5 != ctx->r2) {
        // 0x8001C10C: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_8001C120;
    }
    // 0x8001C10C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8001C110: lw          $v0, 0x50($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X50);
    // 0x8001C114: bne         $v0, $zero, L_8001C1E8
    if (ctx->r2 != 0) {
        // 0x8001C118: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_8001C1E8;
    }
    // 0x8001C118: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8001C11C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8001C120:
    // 0x8001C120: bne         $a1, $v0, L_8001C138
    if (ctx->r5 != ctx->r2) {
        // 0x8001C124: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_8001C138;
    }
    // 0x8001C124: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8001C128: lw          $v0, 0x50($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X50);
    // 0x8001C12C: beq         $v0, $zero, L_8001C1E8
    if (ctx->r2 == 0) {
        // 0x8001C130: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_8001C1E8;
    }
    // 0x8001C130: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8001C134: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
L_8001C138:
    // 0x8001C138: bne         $a1, $v0, L_8001C150
    if (ctx->r5 != ctx->r2) {
        // 0x8001C13C: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_8001C150;
    }
    // 0x8001C13C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8001C140: lw          $v0, 0x54($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X54);
    // 0x8001C144: bne         $v0, $zero, L_8001C1E8
    if (ctx->r2 != 0) {
        // 0x8001C148: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_8001C1E8;
    }
    // 0x8001C148: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8001C14C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8001C150:
    // 0x8001C150: bne         $a1, $v0, L_8001C168
    if (ctx->r5 != ctx->r2) {
        // 0x8001C154: nop
    
            goto L_8001C168;
    }
    // 0x8001C154: nop

    // 0x8001C158: lw          $v0, 0x54($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X54);
    // 0x8001C15C: beq         $v0, $zero, L_8001C1E8
    if (ctx->r2 == 0) {
        // 0x8001C160: nop
    
            goto L_8001C1E8;
    }
    // 0x8001C160: nop

    // 0x8001C164: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
L_8001C168:
    // 0x8001C168: lw          $v0, 0x4C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X4C);
    // 0x8001C16C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001C170: addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // 0x8001C174: lb          $a0, 0x17CC($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X17CC);
    // 0x8001C178: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8001C17C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001C180: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001C184: lb          $v0, 0x17CC($at)
    ctx->r2 = MEM_B(ctx->r1, 0X17CC);
    // 0x8001C188: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001C18C: lbu         $v1, 0x2074($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2074);
    // 0x8001C190: bne         $v1, $zero, L_8001C19C
    if (ctx->r3 != 0) {
        // 0x8001C194: slt         $t0, $v0, $a0
        ctx->r8 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8001C19C;
    }
    // 0x8001C194: slt         $t0, $v0, $a0
    ctx->r8 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001C198: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001C19C:
    // 0x8001C19C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8001C1A0: ori         $a1, $a1, 0x80
    ctx->r5 = ctx->r5 | 0X80;
    // 0x8001C1A4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8001C1A8: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x8001C1AC: addu        $a0, $t4, $zero
    ctx->r4 = ADD32(ctx->r12, 0);
L_8001C1B0:
    // 0x8001C1B0: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x8001C1B4: beql        $v0, $zero, L_8001C1D8
    if (ctx->r2 == 0) {
        // 0x8001C1B8: addiu       $v1, $v1, 0x70
        ctx->r3 = ADD32(ctx->r3, 0X70);
            goto L_8001C1D8;
    }
    goto skip_0;
    // 0x8001C1B8: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
    skip_0:
    // 0x8001C1BC: bnel        $t0, $zero, L_8001C1C4
    if (ctx->r8 != 0) {
        // 0x8001C1C0: sw          $a1, 0x4C($v1)
        MEM_W(0X4C, ctx->r3) = ctx->r5;
            goto L_8001C1C4;
    }
    goto skip_1;
    // 0x8001C1C0: sw          $a1, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r5;
    skip_1:
L_8001C1C4:
    // 0x8001C1C4: bnel        $t3, $t1, L_8001C1CC
    if (ctx->r11 != ctx->r9) {
        // 0x8001C1C8: sw          $t3, 0x50($v1)
        MEM_W(0X50, ctx->r3) = ctx->r11;
            goto L_8001C1CC;
    }
    goto skip_2;
    // 0x8001C1C8: sw          $t3, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r11;
    skip_2:
L_8001C1CC:
    // 0x8001C1CC: bnel        $t2, $t1, L_8001C1D4
    if (ctx->r10 != ctx->r9) {
        // 0x8001C1D0: sw          $t2, 0x54($v1)
        MEM_W(0X54, ctx->r3) = ctx->r10;
            goto L_8001C1D4;
    }
    goto skip_3;
    // 0x8001C1D0: sw          $t2, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r10;
    skip_3:
L_8001C1D4:
    // 0x8001C1D4: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
L_8001C1D8:
    // 0x8001C1D8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001C1DC: slti        $v0, $a2, 0x7
    ctx->r2 = SIGNED(ctx->r6) < 0X7 ? 1 : 0;
    // 0x8001C1E0: bne         $v0, $zero, L_8001C1B0
    if (ctx->r2 != 0) {
        // 0x8001C1E4: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_8001C1B0;
    }
    // 0x8001C1E4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_8001C1E8:
    // 0x8001C1E8: jr          $ra
    // 0x8001C1EC: nop

    return;
    // 0x8001C1EC: nop

;}
RECOMP_FUNC void func_8001C1F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C1F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001C1F4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x8001C1F8: addiu       $a0, $a0, -0x7636
    ctx->r4 = ADD32(ctx->r4, -0X7636);
    // 0x8001C1FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001C200: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001C204: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x8001C208: lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // 0x8001C20C: lbu         $a1, -0x7636($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X7636);
    // 0x8001C210: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001C214: addiu       $v1, $zero, 0x500
    ctx->r3 = ADD32(0, 0X500);
    // 0x8001C218: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C21C: sb          $v0, -0x7632($at)
    MEM_B(-0X7632, ctx->r1) = ctx->r2;
    // 0x8001C220: addiu       $v0, $zero, 0x3C0
    ctx->r2 = ADD32(0, 0X3C0);
    // 0x8001C224: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C228: sh          $v0, -0x7656($at)
    MEM_H(-0X7656, ctx->r1) = ctx->r2;
    // 0x8001C22C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C230: sh          $v0, -0x7652($at)
    MEM_H(-0X7652, ctx->r1) = ctx->r2;
    // 0x8001C234: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8001C238: addiu       $v0, $v0, 0x3040
    ctx->r2 = ADD32(ctx->r2, 0X3040);
    // 0x8001C23C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C240: sw          $v0, -0x7650($at)
    MEM_W(-0X7650, ctx->r1) = ctx->r2;
    // 0x8001C244: ori         $v0, $zero, 0xFFF4
    ctx->r2 = 0 | 0XFFF4;
    // 0x8001C248: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C24C: sh          $v0, -0x764C($at)
    MEM_H(-0X764C, ctx->r1) = ctx->r2;
    // 0x8001C250: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001C254: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C258: sh          $zero, -0x7658($at)
    MEM_H(-0X7658, ctx->r1) = 0;
    // 0x8001C25C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C260: sh          $zero, -0x7660($at)
    MEM_H(-0X7660, ctx->r1) = 0;
    // 0x8001C264: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C268: sh          $v1, -0x765E($at)
    MEM_H(-0X765E, ctx->r1) = ctx->r3;
    // 0x8001C26C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C270: sh          $zero, -0x7654($at)
    MEM_H(-0X7654, ctx->r1) = 0;
    // 0x8001C274: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C278: sh          $zero, -0x765C($at)
    MEM_H(-0X765C, ctx->r1) = 0;
    // 0x8001C27C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C280: sh          $v1, -0x765A($at)
    MEM_H(-0X765A, ctx->r1) = ctx->r3;
    // 0x8001C284: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C288: sb          $zero, -0x764A($at)
    MEM_B(-0X764A, ctx->r1) = 0;
    // 0x8001C28C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C290: sb          $v0, -0x7649($at)
    MEM_B(-0X7649, ctx->r1) = ctx->r2;
    // 0x8001C294: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C298: sh          $zero, -0x7648($at)
    MEM_H(-0X7648, ctx->r1) = 0;
    // 0x8001C29C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C2A0: sh          $zero, -0x7646($at)
    MEM_H(-0X7646, ctx->r1) = 0;
    // 0x8001C2A4: beq         $a1, $zero, L_8001C2CC
    if (ctx->r5 == 0) {
        // 0x8001C2A8: addiu       $a0, $a0, -0x2A
        ctx->r4 = ADD32(ctx->r4, -0X2A);
            goto L_8001C2CC;
    }
    // 0x8001C2A8: addiu       $a0, $a0, -0x2A
    ctx->r4 = ADD32(ctx->r4, -0X2A);
    // 0x8001C2AC: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x8001C2B0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C2B4: sh          $v0, -0x7642($at)
    MEM_H(-0X7642, ctx->r1) = ctx->r2;
    // 0x8001C2B8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C2BC: sh          $v0, -0x7644($at)
    MEM_H(-0X7644, ctx->r1) = ctx->r2;
    // 0x8001C2C0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C2C4: j           L_8001C2D4
    // 0x8001C2C8: sw          $zero, -0x7640($at)
    MEM_W(-0X7640, ctx->r1) = 0;
        goto L_8001C2D4;
    // 0x8001C2C8: sw          $zero, -0x7640($at)
    MEM_W(-0X7640, ctx->r1) = 0;
L_8001C2CC:
    // 0x8001C2CC: jal         0x80066D30
    // 0x8001C2D0: nop

    func_80066D30(rdram, ctx);
        goto after_0;
    // 0x8001C2D0: nop

    after_0:
L_8001C2D4:
    // 0x8001C2D4: lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // 0x8001C2D8: addiu       $v1, $v1, -0x764A
    ctx->r3 = ADD32(ctx->r3, -0X764A);
    // 0x8001C2DC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8001C2E0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8001C2E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001C2E8: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8001C2EC: addiu       $s0, $s0, -0x2338
    ctx->r16 = ADD32(ctx->r16, -0X2338);
    // 0x8001C2F0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C2F4: sb          $v0, -0x7649($at)
    MEM_B(-0X7649, ctx->r1) = ctx->r2;
    // 0x8001C2F8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C2FC: sh          $zero, -0x7648($at)
    MEM_H(-0X7648, ctx->r1) = 0;
    // 0x8001C300: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x8001C304: sw          $s0, -0x7630($at)
    MEM_W(-0X7630, ctx->r1) = ctx->r16;
    // 0x8001C308: jal         0x80066D30
    // 0x8001C30C: addiu       $a0, $v1, -0x16
    ctx->r4 = ADD32(ctx->r3, -0X16);
    func_80066D30(rdram, ctx);
        goto after_1;
    // 0x8001C30C: addiu       $a0, $v1, -0x16
    ctx->r4 = ADD32(ctx->r3, -0X16);
    after_1:
    // 0x8001C310: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001C314: lbu         $v1, 0x7B86($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B86);
    // 0x8001C318: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001C31C: addiu       $a0, $a0, -0x65D0
    ctx->r4 = ADD32(ctx->r4, -0X65D0);
    // 0x8001C320: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8001C324: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001C328: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001C32C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001C330: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8001C334: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x8001C338: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8001C33C: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x8001C340: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8001C344: addiu       $a2, $a2, 0x3040
    ctx->r6 = ADD32(ctx->r6, 0X3040);
    // 0x8001C348: jal         0x80053078
    // 0x8001C34C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80053078(rdram, ctx);
        goto after_2;
    // 0x8001C34C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8001C350: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    // 0x8001C354: jal         0x8001D670
    // 0x8001C358: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D670(rdram, ctx);
        goto after_3;
    // 0x8001C358: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // 0x8001C35C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C360: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001C364: jr          $ra
    // 0x8001C368: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001C368: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8001C36C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C36C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001C370: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8001C374: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8001C378: addiu       $s0, $s0, 0x7B86
    ctx->r16 = ADD32(ctx->r16, 0X7B86);
    // 0x8001C37C: sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // 0x8001C380: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8001C384: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8001C388: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8001C38C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8001C390: lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // 0x8001C394: addiu       $s1, $s1, -0x2F90
    ctx->r17 = ADD32(ctx->r17, -0X2F90);
    // 0x8001C398: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001C39C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001C3A0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8001C3A4: lw          $a0, -0x6444($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6444);
    // 0x8001C3A8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8001C3AC: addiu       $a2, $zero, 0x690
    ctx->r6 = ADD32(0, 0X690);
    // 0x8001C3B0: jal         0x80006D98
    // 0x8001C3B4: addiu       $a0, $a0, 0x200
    ctx->r4 = ADD32(ctx->r4, 0X200);
    func_80006D98(rdram, ctx);
        goto after_0;
    // 0x8001C3B4: addiu       $a0, $a0, 0x200
    ctx->r4 = ADD32(ctx->r4, 0X200);
    after_0:
    // 0x8001C3B8: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8001C3BC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001C3C0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001C3C4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8001C3C8: lw          $a0, -0x6444($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6444);
    // 0x8001C3CC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8001C3D0: addiu       $a1, $a1, -0x2538
    ctx->r5 = ADD32(ctx->r5, -0X2538);
    // 0x8001C3D4: jal         0x80006D98
    // 0x8001C3D8: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    func_80006D98(rdram, ctx);
        goto after_1;
    // 0x8001C3D8: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_1:
    // 0x8001C3DC: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x8001C3E0: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8001C3E4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001C3E8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001C3EC: lbu         $v1, -0x4D30($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X4D30);
    // 0x8001C3F0: lui         $s2, 0x8015
    ctx->r18 = S32(0X8015 << 16);
    // 0x8001C3F4: addiu       $s2, $s2, -0x1DC0
    ctx->r18 = ADD32(ctx->r18, -0X1DC0);
    // 0x8001C3F8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8001C3FC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8001C400: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001C404: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001C408: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
    // 0x8001C40C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001C410: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001C414: lw          $v0, -0x6444($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6444);
    // 0x8001C418: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8001C41C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8001C420: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // 0x8001C424: jal         0x80006D98
    // 0x8001C428: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_80006D98(rdram, ctx);
        goto after_2;
    // 0x8001C428: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_2:
    // 0x8001C42C: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x8001C430: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8001C434: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001C438: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001C43C: lbu         $v1, -0x4D2F($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X4D2F);
    // 0x8001C440: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8001C444: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8001C448: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001C44C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001C450: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
    // 0x8001C454: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001C458: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001C45C: lw          $v0, -0x6444($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6444);
    // 0x8001C460: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8001C464: addiu       $a1, $s2, 0x400
    ctx->r5 = ADD32(ctx->r18, 0X400);
    // 0x8001C468: addiu       $a2, $zero, 0x5A0
    ctx->r6 = ADD32(0, 0X5A0);
    // 0x8001C46C: jal         0x80006D98
    // 0x8001C470: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_80006D98(rdram, ctx);
        goto after_3;
    // 0x8001C470: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_3:
    // 0x8001C474: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001C478: lbu         $v1, 0x7B85($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B85);
    // 0x8001C47C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8001C480: bne         $v1, $v0, L_8001C4C4
    if (ctx->r3 != ctx->r2) {
        // 0x8001C484: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8001C4C4;
    }
    // 0x8001C484: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8001C488: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8001C48C: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x8001C490: addiu       $s1, $zero, 0x20
    ctx->r17 = ADD32(0, 0X20);
L_8001C494:
    // 0x8001C494: jal         0x8001D520
    // 0x8001C498: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D520(rdram, ctx);
        goto after_4;
    // 0x8001C498: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8001C49C: beql        $v0, $zero, L_8001C4B8
    if (ctx->r2 == 0) {
        // 0x8001C4A0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8001C4B8;
    }
    goto skip_0;
    // 0x8001C4A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8001C4A4: sb          $s3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r19;
    // 0x8001C4A8: sb          $s2, 0x2B($v0)
    MEM_B(0X2B, ctx->r2) = ctx->r18;
    // 0x8001C4AC: sb          $s1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r17;
    // 0x8001C4B0: sw          $s0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r16;
    // 0x8001C4B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8001C4B8:
    // 0x8001C4B8: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8001C4BC: bne         $v0, $zero, L_8001C494
    if (ctx->r2 != 0) {
        // 0x8001C4C0: nop
    
            goto L_8001C494;
    }
    // 0x8001C4C0: nop

L_8001C4C4:
    // 0x8001C4C4: jal         0x80017BF4
    // 0x8001C4C8: nop

    func_80017BF4(rdram, ctx);
        goto after_5;
    // 0x8001C4C8: nop

    after_5:
    // 0x8001C4CC: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x8001C4D0: addiu       $s2, $s2, 0x7B86
    ctx->r18 = ADD32(ctx->r18, 0X7B86);
    // 0x8001C4D4: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8001C4D8: lui         $s1, 0x8015
    ctx->r17 = S32(0X8015 << 16);
    // 0x8001C4DC: addiu       $s1, $s1, 0x260
    ctx->r17 = ADD32(ctx->r17, 0X260);
    // 0x8001C4E0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8001C4E4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001C4E8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001C4EC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8001C4F0: lw          $a0, -0x6648($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6648);
    // 0x8001C4F4: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    // 0x8001C4F8: lui         $s0, 0x37
    ctx->r16 = S32(0X37 << 16);
    // 0x8001C4FC: addiu       $s0, $s0, -0x170
    ctx->r16 = ADD32(ctx->r16, -0X170);
    // 0x8001C500: jal         0x80006D98
    // 0x8001C504: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    func_80006D98(rdram, ctx);
        goto after_6;
    // 0x8001C504: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    after_6:
    // 0x8001C508: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
    // 0x8001C50C: addiu       $a1, $s1, 0x800
    ctx->r5 = ADD32(ctx->r17, 0X800);
    // 0x8001C510: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8001C514: addiu       $s0, $s0, -0xC0
    ctx->r16 = ADD32(ctx->r16, -0XC0);
    // 0x8001C518: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x8001C51C: jal         0x80006D98
    // 0x8001C520: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    func_80006D98(rdram, ctx);
        goto after_7;
    // 0x8001C520: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    after_7:
    // 0x8001C524: lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X38);
    // 0x8001C528: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8001C52C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8001C530: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8001C534: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8001C538: jr          $ra
    // 0x8001C53C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8001C53C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8001C540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C540: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8001C544: lbu         $v0, 0x5($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X5);
    // 0x8001C548: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8001C54C: bne         $v0, $zero, L_8001C564
    if (ctx->r2 != 0) {
        // 0x8001C550: addiu       $a3, $zero, 0x11E
        ctx->r7 = ADD32(0, 0X11E);
            goto L_8001C564;
    }
    // 0x8001C550: addiu       $a3, $zero, 0x11E
    ctx->r7 = ADD32(0, 0X11E);
    // 0x8001C554: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    // 0x8001C558: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x8001C55C: j           L_8001C56C
    // 0x8001C560: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_8001C56C;
    // 0x8001C560: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_8001C564:
    // 0x8001C564: addu        $t4, $zero, $zero
    ctx->r12 = ADD32(0, 0);
    // 0x8001C568: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8001C56C:
    // 0x8001C56C: lb          $v0, 0x58($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X58);
    // 0x8001C570: lbu         $v1, 0x66($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X66);
    // 0x8001C574: addiu       $a2, $v0, 0x40
    ctx->r6 = ADD32(ctx->r2, 0X40);
    // 0x8001C578: addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
    // 0x8001C57C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8001C580: slt         $v0, $v0, $a2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001C584: bnel        $v0, $zero, L_8001C638
    if (ctx->r2 != 0) {
        // 0x8001C588: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_8001C638;
    }
    goto skip_0;
    // 0x8001C588: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    skip_0:
    // 0x8001C58C: addiu       $v0, $a3, 0x10
    ctx->r2 = ADD32(ctx->r7, 0X10);
    // 0x8001C590: sll         $t3, $v0, 14
    ctx->r11 = S32(ctx->r2 << 14);
    // 0x8001C594: lui         $t9, 0xE400
    ctx->r25 = S32(0XE400 << 16);
    // 0x8001C598: sll         $t2, $a3, 14
    ctx->r10 = S32(ctx->r7 << 14);
    // 0x8001C59C: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x8001C5A0: sll         $v0, $t4, 21
    ctx->r2 = S32(ctx->r12 << 21);
    // 0x8001C5A4: ori         $t1, $v0, 0x20
    ctx->r9 = ctx->r2 | 0X20;
    // 0x8001C5A8: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x8001C5AC: sll         $v0, $t5, 26
    ctx->r2 = S32(ctx->r13 << 26);
    // 0x8001C5B0: ori         $t0, $v0, 0x400
    ctx->r8 = ctx->r2 | 0X400;
    // 0x8001C5B4: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
L_8001C5B8:
    // 0x8001C5B8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8001C5BC: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8001C5C0: addiu       $a0, $a2, 0x8
    ctx->r4 = ADD32(ctx->r6, 0X8);
    // 0x8001C5C4: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8001C5C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C5CC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001C5D0: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8001C5D4: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8001C5D8: or          $v0, $v0, $t9
    ctx->r2 = ctx->r2 | ctx->r25;
    // 0x8001C5DC: or          $v0, $t3, $v0
    ctx->r2 = ctx->r11 | ctx->r2;
    // 0x8001C5E0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8001C5E4: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8001C5E8: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8001C5EC: or          $v0, $t2, $v0
    ctx->r2 = ctx->r10 | ctx->r2;
    // 0x8001C5F0: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8001C5F4: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8001C5F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C5FC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001C600: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8001C604: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x8001C608: sw          $t1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r9;
    // 0x8001C60C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C610: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001C614: sw          $t7, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r15;
    // 0x8001C618: sw          $t0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r8;
    // 0x8001C61C: lbu         $v0, 0x66($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X66);
    // 0x8001C620: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x8001C624: subu        $v0, $t6, $v0
    ctx->r2 = SUB32(ctx->r14, ctx->r2);
    // 0x8001C628: slt         $v0, $v0, $a2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001C62C: beq         $v0, $zero, L_8001C5B8
    if (ctx->r2 == 0) {
        // 0x8001C630: nop
    
            goto L_8001C5B8;
    }
    // 0x8001C630: nop

    // 0x8001C634: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
L_8001C638:
    // 0x8001C638: slti        $v0, $a2, 0xD1
    ctx->r2 = SIGNED(ctx->r6) < 0XD1 ? 1 : 0;
    // 0x8001C63C: beq         $v0, $zero, L_8001C6D8
    if (ctx->r2 == 0) {
        // 0x8001C640: addiu       $v0, $a3, 0x10
        ctx->r2 = ADD32(ctx->r7, 0X10);
            goto L_8001C6D8;
    }
    // 0x8001C640: addiu       $v0, $a3, 0x10
    ctx->r2 = ADD32(ctx->r7, 0X10);
    // 0x8001C644: sll         $t3, $v0, 14
    ctx->r11 = S32(ctx->r2 << 14);
    // 0x8001C648: lui         $t8, 0xE400
    ctx->r24 = S32(0XE400 << 16);
    // 0x8001C64C: sll         $t2, $a3, 14
    ctx->r10 = S32(ctx->r7 << 14);
    // 0x8001C650: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x8001C654: sll         $v0, $t4, 21
    ctx->r2 = S32(ctx->r12 << 21);
    // 0x8001C658: ori         $t1, $v0, 0x120
    ctx->r9 = ctx->r2 | 0X120;
    // 0x8001C65C: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x8001C660: sll         $v0, $t5, 26
    ctx->r2 = S32(ctx->r13 << 26);
    // 0x8001C664: ori         $t0, $v0, 0x400
    ctx->r8 = ctx->r2 | 0X400;
L_8001C668:
    // 0x8001C668: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8001C66C: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8001C670: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
    // 0x8001C674: sll         $a0, $a2, 2
    ctx->r4 = S32(ctx->r6 << 2);
    // 0x8001C678: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8001C67C: andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // 0x8001C680: or          $a0, $t2, $a0
    ctx->r4 = ctx->r10 | ctx->r4;
    // 0x8001C684: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8001C688: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C68C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001C690: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8001C694: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8001C698: or          $v0, $v0, $t8
    ctx->r2 = ctx->r2 | ctx->r24;
    // 0x8001C69C: or          $v0, $t3, $v0
    ctx->r2 = ctx->r11 | ctx->r2;
    // 0x8001C6A0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8001C6A4: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8001C6A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C6AC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001C6B0: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8001C6B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C6B8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001C6BC: slti        $v0, $a2, 0xD1
    ctx->r2 = SIGNED(ctx->r6) < 0XD1 ? 1 : 0;
    // 0x8001C6C0: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x8001C6C4: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x8001C6C8: sw          $t1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r9;
    // 0x8001C6CC: sw          $t6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r14;
    // 0x8001C6D0: bne         $v0, $zero, L_8001C668
    if (ctx->r2 != 0) {
        // 0x8001C6D4: sw          $t0, 0x14($v1)
        MEM_W(0X14, ctx->r3) = ctx->r8;
            goto L_8001C668;
    }
    // 0x8001C6D4: sw          $t0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r8;
L_8001C6D8:
    // 0x8001C6D8: lb          $v0, 0x58($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X58);
    // 0x8001C6DC: lbu         $v1, 0x66($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X66);
    // 0x8001C6E0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8001C6E4: lw          $a1, 0x2FE4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2FE4);
    // 0x8001C6E8: lui         $t7, 0xE400
    ctx->r15 = S32(0XE400 << 16);
    // 0x8001C6EC: lui         $t3, 0xB400
    ctx->r11 = S32(0XB400 << 16);
    // 0x8001C6F0: sll         $t2, $t4, 21
    ctx->r10 = S32(ctx->r12 << 21);
    // 0x8001C6F4: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x8001C6F8: addiu       $v0, $v0, 0xC8
    ctx->r2 = ADD32(ctx->r2, 0XC8);
    // 0x8001C6FC: subu        $a2, $v0, $v1
    ctx->r6 = SUB32(ctx->r2, ctx->r3);
    // 0x8001C700: addiu       $v1, $a2, 0x8
    ctx->r3 = ADD32(ctx->r6, 0X8);
    // 0x8001C704: sll         $a0, $a2, 2
    ctx->r4 = S32(ctx->r6 << 2);
    // 0x8001C708: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8001C70C: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8001C710: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x8001C714: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C718: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001C71C: addiu       $v0, $a3, 0x10
    ctx->r2 = ADD32(ctx->r7, 0X10);
    // 0x8001C720: sll         $t0, $v0, 14
    ctx->r8 = S32(ctx->r2 << 14);
    // 0x8001C724: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8001C728: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8001C72C: or          $v0, $v1, $t7
    ctx->r2 = ctx->r3 | ctx->r15;
    // 0x8001C730: or          $v0, $t0, $v0
    ctx->r2 = ctx->r8 | ctx->r2;
    // 0x8001C734: sll         $a3, $a3, 14
    ctx->r7 = S32(ctx->r7 << 14);
    // 0x8001C738: andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // 0x8001C73C: or          $a0, $a3, $a0
    ctx->r4 = ctx->r7 | ctx->r4;
    // 0x8001C740: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8001C744: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x8001C748: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C74C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001C750: ori         $v0, $t2, 0x20
    ctx->r2 = ctx->r10 | 0X20;
    // 0x8001C754: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x8001C758: addiu       $v0, $a1, 0x18
    ctx->r2 = ADD32(ctx->r5, 0X18);
    // 0x8001C75C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C760: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001C764: sll         $v0, $t5, 26
    ctx->r2 = S32(ctx->r13 << 26);
    // 0x8001C768: ori         $t1, $v0, 0x400
    ctx->r9 = ctx->r2 | 0X400;
    // 0x8001C76C: addiu       $v0, $a1, 0x20
    ctx->r2 = ADD32(ctx->r5, 0X20);
    // 0x8001C770: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C774: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001C778: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8001C77C: sw          $a0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r4;
    // 0x8001C780: andi        $a0, $v0, 0xFFF
    ctx->r4 = ctx->r2 & 0XFFF;
    // 0x8001C784: or          $v0, $a0, $t7
    ctx->r2 = ctx->r4 | ctx->r15;
    // 0x8001C788: or          $v0, $t0, $v0
    ctx->r2 = ctx->r8 | ctx->r2;
    // 0x8001C78C: or          $v1, $a3, $v1
    ctx->r3 = ctx->r7 | ctx->r3;
    // 0x8001C790: sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    // 0x8001C794: addiu       $v0, $a1, 0x28
    ctx->r2 = ADD32(ctx->r5, 0X28);
    // 0x8001C798: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C79C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001C7A0: addiu       $v0, $t4, 0x10
    ctx->r2 = ADD32(ctx->r12, 0X10);
    // 0x8001C7A4: sll         $v0, $v0, 21
    ctx->r2 = S32(ctx->r2 << 21);
    // 0x8001C7A8: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x8001C7AC: sw          $v0, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r2;
    // 0x8001C7B0: addiu       $v0, $a1, 0x30
    ctx->r2 = ADD32(ctx->r5, 0X30);
    // 0x8001C7B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C7B8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001C7BC: slti        $v0, $a2, 0xD1
    ctx->r2 = SIGNED(ctx->r6) < 0XD1 ? 1 : 0;
    // 0x8001C7C0: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x8001C7C4: sw          $t6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r14;
    // 0x8001C7C8: sw          $t1, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r9;
    // 0x8001C7CC: sw          $v1, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r3;
    // 0x8001C7D0: sw          $t3, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r11;
    // 0x8001C7D4: sw          $t6, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r14;
    // 0x8001C7D8: beq         $v0, $zero, L_8001C828
    if (ctx->r2 == 0) {
        // 0x8001C7DC: sw          $t1, 0x2C($a1)
        MEM_W(0X2C, ctx->r5) = ctx->r9;
            goto L_8001C828;
    }
    // 0x8001C7DC: sw          $t1, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r9;
    // 0x8001C7E0: addiu       $v0, $a1, 0x38
    ctx->r2 = ADD32(ctx->r5, 0X38);
    // 0x8001C7E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C7E8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001C7EC: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
    // 0x8001C7F0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001C7F4: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8001C7F8: or          $v0, $v0, $t7
    ctx->r2 = ctx->r2 | ctx->r15;
    // 0x8001C7FC: or          $v0, $t0, $v0
    ctx->r2 = ctx->r8 | ctx->r2;
    // 0x8001C800: sw          $v0, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r2;
    // 0x8001C804: or          $v0, $a3, $a0
    ctx->r2 = ctx->r7 | ctx->r4;
    // 0x8001C808: sw          $v0, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r2;
    // 0x8001C80C: addiu       $v0, $a1, 0x40
    ctx->r2 = ADD32(ctx->r5, 0X40);
    // 0x8001C810: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C814: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001C818: ori         $v0, $t2, 0x120
    ctx->r2 = ctx->r10 | 0X120;
    // 0x8001C81C: sw          $v0, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->r2;
    // 0x8001C820: j           L_8001C864
    // 0x8001C824: addiu       $v0, $a1, 0x48
    ctx->r2 = ADD32(ctx->r5, 0X48);
        goto L_8001C864;
    // 0x8001C824: addiu       $v0, $a1, 0x48
    ctx->r2 = ADD32(ctx->r5, 0X48);
L_8001C828:
    // 0x8001C828: lui         $v1, 0xE400
    ctx->r3 = S32(0XE400 << 16);
    // 0x8001C82C: ori         $v1, $v1, 0x360
    ctx->r3 = ctx->r3 | 0X360;
    // 0x8001C830: addiu       $v0, $a1, 0x38
    ctx->r2 = ADD32(ctx->r5, 0X38);
    // 0x8001C834: or          $v1, $t0, $v1
    ctx->r3 = ctx->r8 | ctx->r3;
    // 0x8001C838: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C83C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001C840: or          $v0, $a3, $a0
    ctx->r2 = ctx->r7 | ctx->r4;
    // 0x8001C844: sw          $v0, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r2;
    // 0x8001C848: addiu       $v0, $a1, 0x40
    ctx->r2 = ADD32(ctx->r5, 0X40);
    // 0x8001C84C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C850: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001C854: ori         $v0, $t2, 0x120
    ctx->r2 = ctx->r10 | 0X120;
    // 0x8001C858: sw          $v0, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->r2;
    // 0x8001C85C: addiu       $v0, $a1, 0x48
    ctx->r2 = ADD32(ctx->r5, 0X48);
    // 0x8001C860: sw          $v1, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r3;
L_8001C864:
    // 0x8001C864: sw          $t3, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->r11;
    // 0x8001C868: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C86C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001C870: sw          $t6, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->r14;
    // 0x8001C874: jr          $ra
    // 0x8001C878: sw          $t1, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r9;
    return;
    // 0x8001C878: sw          $t1, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r9;
;}
RECOMP_FUNC void func_8001C87C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C87C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C880: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8001C884: lui         $s0, 0xBA00
    ctx->r16 = S32(0XBA00 << 16);
    // 0x8001C888: ori         $s0, $s0, 0xE02
    ctx->r16 = ctx->r16 | 0XE02;
    // 0x8001C88C: lui         $a1, 0xF500
    ctx->r5 = S32(0XF500 << 16);
    // 0x8001C890: ori         $a1, $a1, 0x100
    ctx->r5 = ctx->r5 | 0X100;
    // 0x8001C894: lui         $t0, 0x73F
    ctx->r8 = S32(0X73F << 16);
    // 0x8001C898: ori         $t0, $t0, 0xC000
    ctx->r8 = ctx->r8 | 0XC000;
    // 0x8001C89C: lui         $t1, 0x71F
    ctx->r9 = S32(0X71F << 16);
    // 0x8001C8A0: ori         $t1, $t1, 0xF200
    ctx->r9 = ctx->r9 | 0XF200;
    // 0x8001C8A4: lui         $t2, 0xF548
    ctx->r10 = S32(0XF548 << 16);
    // 0x8001C8A8: ori         $t2, $t2, 0x800
    ctx->r10 = ctx->r10 | 0X800;
    // 0x8001C8AC: lui         $t3, 0x7
    ctx->r11 = S32(0X7 << 16);
    // 0x8001C8B0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8001C8B4: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x8001C8B8: ori         $t3, $t3, 0xC07C
    ctx->r11 = ctx->r11 | 0XC07C;
    // 0x8001C8BC: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8001C8C0: addiu       $a0, $a0, 0x25A0
    ctx->r4 = ADD32(ctx->r4, 0X25A0);
    // 0x8001C8C4: lui         $a3, 0x700
    ctx->r7 = S32(0X700 << 16);
    // 0x8001C8C8: lui         $a2, 0xE600
    ctx->r6 = S32(0XE600 << 16);
    // 0x8001C8CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C8D0: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8001C8D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C8D8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001C8DC: lui         $v1, 0x600
    ctx->r3 = S32(0X600 << 16);
    // 0x8001C8E0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8001C8E4: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001C8E8: addiu       $v1, $v1, -0x67D0
    ctx->r3 = ADD32(ctx->r3, -0X67D0);
    // 0x8001C8EC: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x8001C8F0: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x8001C8F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C8F8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001C8FC: ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // 0x8001C900: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x8001C904: addiu       $v1, $v0, 0x18
    ctx->r3 = ADD32(ctx->r2, 0X18);
    // 0x8001C908: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C90C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001C910: lui         $v1, 0xFD10
    ctx->r3 = S32(0XFD10 << 16);
    // 0x8001C914: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x8001C918: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001C91C: addiu       $v1, $v1, -0x2538
    ctx->r3 = ADD32(ctx->r3, -0X2538);
    // 0x8001C920: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // 0x8001C924: addiu       $v1, $v0, 0x20
    ctx->r3 = ADD32(ctx->r2, 0X20);
    // 0x8001C928: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C92C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001C930: lui         $v1, 0xE800
    ctx->r3 = S32(0XE800 << 16);
    // 0x8001C934: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
    // 0x8001C938: addiu       $v1, $v0, 0x28
    ctx->r3 = ADD32(ctx->r2, 0X28);
    // 0x8001C93C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C940: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001C944: addiu       $v1, $v0, 0x30
    ctx->r3 = ADD32(ctx->r2, 0X30);
    // 0x8001C948: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C94C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001C950: addiu       $v1, $v0, 0x38
    ctx->r3 = ADD32(ctx->r2, 0X38);
    // 0x8001C954: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C958: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001C95C: lui         $v1, 0xF000
    ctx->r3 = S32(0XF000 << 16);
    // 0x8001C960: sw          $v1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r3;
    // 0x8001C964: addiu       $v1, $v0, 0x40
    ctx->r3 = ADD32(ctx->r2, 0X40);
    // 0x8001C968: sw          $a1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r5;
    // 0x8001C96C: lui         $a1, 0xE700
    ctx->r5 = S32(0XE700 << 16);
    // 0x8001C970: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C974: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001C978: addiu       $v1, $v0, 0x48
    ctx->r3 = ADD32(ctx->r2, 0X48);
    // 0x8001C97C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C980: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001C984: lui         $v1, 0xFD50
    ctx->r3 = S32(0XFD50 << 16);
    // 0x8001C988: sw          $v1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r3;
    // 0x8001C98C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8001C990: addiu       $v1, $v1, -0x1DC0
    ctx->r3 = ADD32(ctx->r3, -0X1DC0);
    // 0x8001C994: sw          $v1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r3;
    // 0x8001C998: addiu       $v1, $v0, 0x50
    ctx->r3 = ADD32(ctx->r2, 0X50);
    // 0x8001C99C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C9A0: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001C9A4: lui         $v1, 0xF550
    ctx->r3 = S32(0XF550 << 16);
    // 0x8001C9A8: sw          $v1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r3;
    // 0x8001C9AC: addiu       $v1, $v0, 0x58
    ctx->r3 = ADD32(ctx->r2, 0X58);
    // 0x8001C9B0: sw          $s0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r16;
    // 0x8001C9B4: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x8001C9B8: sw          $a3, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r7;
    // 0x8001C9BC: sw          $a2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r6;
    // 0x8001C9C0: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x8001C9C4: sw          $t0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r8;
    // 0x8001C9C8: sw          $a1, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r5;
    // 0x8001C9CC: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8001C9D0: sw          $a3, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r7;
    // 0x8001C9D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C9D8: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001C9DC: addiu       $v1, $v0, 0x60
    ctx->r3 = ADD32(ctx->r2, 0X60);
    // 0x8001C9E0: sw          $a2, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r6;
    // 0x8001C9E4: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
    // 0x8001C9E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001C9EC: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001C9F0: lui         $v1, 0xF300
    ctx->r3 = S32(0XF300 << 16);
    // 0x8001C9F4: sw          $v1, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r3;
    // 0x8001C9F8: addiu       $v1, $v0, 0x68
    ctx->r3 = ADD32(ctx->r2, 0X68);
    // 0x8001C9FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CA00: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001CA04: addiu       $v1, $v0, 0x70
    ctx->r3 = ADD32(ctx->r2, 0X70);
    // 0x8001CA08: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CA0C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001CA10: addiu       $v1, $v0, 0x78
    ctx->r3 = ADD32(ctx->r2, 0X78);
    // 0x8001CA14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CA18: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001CA1C: lui         $v1, 0xF200
    ctx->r3 = S32(0XF200 << 16);
    // 0x8001CA20: sw          $t1, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r9;
    // 0x8001CA24: sw          $a1, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->r5;
    // 0x8001CA28: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    // 0x8001CA2C: sw          $t2, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r10;
    // 0x8001CA30: sw          $zero, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = 0;
    // 0x8001CA34: sw          $v1, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r3;
    // 0x8001CA38: jal         0x8001C540
    // 0x8001CA3C: sw          $t3, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->r11;
    func_8001C540(rdram, ctx);
        goto after_0;
    // 0x8001CA3C: sw          $t3, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->r11;
    after_0:
    // 0x8001CA40: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8001CA44: jal         0x8001C540
    // 0x8001CA48: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    func_8001C540(rdram, ctx);
        goto after_1;
    // 0x8001CA48: addiu       $a0, $a0, 0x79F0
    ctx->r4 = ADD32(ctx->r4, 0X79F0);
    after_1:
    // 0x8001CA4C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8001CA50: lw          $v0, 0x2FE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2FE4);
    // 0x8001CA54: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x8001CA58: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CA5C: sw          $v1, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r3;
    // 0x8001CA60: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x8001CA64: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8001CA68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CA6C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8001CA70: jr          $ra
    // 0x8001CA74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001CA74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001CA78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CA78: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x8001CA7C: ori         $t6, $t6, 0xE02
    ctx->r14 = ctx->r14 | 0XE02;
    // 0x8001CA80: lui         $a0, 0xF500
    ctx->r4 = S32(0XF500 << 16);
    // 0x8001CA84: ori         $a0, $a0, 0x100
    ctx->r4 = ctx->r4 | 0X100;
    // 0x8001CA88: lui         $a3, 0x73F
    ctx->r7 = S32(0X73F << 16);
    // 0x8001CA8C: ori         $a3, $a3, 0xC000
    ctx->r7 = ctx->r7 | 0XC000;
    // 0x8001CA90: lui         $t0, 0x72C
    ctx->r8 = S32(0X72C << 16);
    // 0x8001CA94: ori         $t0, $t0, 0xF0CD
    ctx->r8 = ctx->r8 | 0XF0CD;
    // 0x8001CA98: lui         $t1, 0xF548
    ctx->r9 = S32(0XF548 << 16);
    // 0x8001CA9C: ori         $t1, $t1, 0x1400
    ctx->r9 = ctx->r9 | 0X1400;
    // 0x8001CAA0: lui         $t2, 0x13
    ctx->r10 = S32(0X13 << 16);
    // 0x8001CAA4: ori         $t2, $t2, 0xC044
    ctx->r10 = ctx->r10 | 0XC044;
    // 0x8001CAA8: lui         $t3, 0xE41C
    ctx->r11 = S32(0XE41C << 16);
    // 0x8001CAAC: ori         $t3, $t3, 0x8000
    ctx->r11 = ctx->r11 | 0X8000;
    // 0x8001CAB0: lui         $t5, 0x8
    ctx->r13 = S32(0X8 << 16);
    // 0x8001CAB4: ori         $t5, $t5, 0x8000
    ctx->r13 = ctx->r13 | 0X8000;
    // 0x8001CAB8: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8001CABC: lw          $v1, 0x2FE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X2FE4);
    // 0x8001CAC0: lui         $t4, 0xFC00
    ctx->r12 = S32(0XFC00 << 16);
    // 0x8001CAC4: ori         $t4, $t4, 0x400
    ctx->r12 = ctx->r12 | 0X400;
    // 0x8001CAC8: lui         $a2, 0x700
    ctx->r6 = S32(0X700 << 16);
    // 0x8001CACC: lui         $a1, 0xE600
    ctx->r5 = S32(0XE600 << 16);
    // 0x8001CAD0: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x8001CAD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CAD8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CADC: lui         $v0, 0x600
    ctx->r2 = S32(0X600 << 16);
    // 0x8001CAE0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8001CAE4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001CAE8: addiu       $v0, $v0, -0x67D0
    ctx->r2 = ADD32(ctx->r2, -0X67D0);
    // 0x8001CAEC: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8001CAF0: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8001CAF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CAF8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CAFC: ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // 0x8001CB00: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8001CB04: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x8001CB08: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CB0C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CB10: lui         $v0, 0xFD10
    ctx->r2 = S32(0XFD10 << 16);
    // 0x8001CB14: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x8001CB18: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001CB1C: addiu       $v0, $v0, -0x2538
    ctx->r2 = ADD32(ctx->r2, -0X2538);
    // 0x8001CB20: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // 0x8001CB24: addiu       $v0, $v1, 0x20
    ctx->r2 = ADD32(ctx->r3, 0X20);
    // 0x8001CB28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CB2C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CB30: lui         $v0, 0xE800
    ctx->r2 = S32(0XE800 << 16);
    // 0x8001CB34: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x8001CB38: addiu       $v0, $v1, 0x28
    ctx->r2 = ADD32(ctx->r3, 0X28);
    // 0x8001CB3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CB40: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CB44: addiu       $v0, $v1, 0x30
    ctx->r2 = ADD32(ctx->r3, 0X30);
    // 0x8001CB48: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CB4C: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CB50: addiu       $v0, $v1, 0x38
    ctx->r2 = ADD32(ctx->r3, 0X38);
    // 0x8001CB54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CB58: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CB5C: lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // 0x8001CB60: sw          $v0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r2;
    // 0x8001CB64: addiu       $v0, $v1, 0x40
    ctx->r2 = ADD32(ctx->r3, 0X40);
    // 0x8001CB68: sw          $a0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r4;
    // 0x8001CB6C: lui         $a0, 0xE700
    ctx->r4 = S32(0XE700 << 16);
    // 0x8001CB70: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CB74: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CB78: addiu       $v0, $v1, 0x48
    ctx->r2 = ADD32(ctx->r3, 0X48);
    // 0x8001CB7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CB80: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CB84: lui         $v0, 0xFD50
    ctx->r2 = S32(0XFD50 << 16);
    // 0x8001CB88: sw          $v0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r2;
    // 0x8001CB8C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8001CB90: addiu       $v0, $v0, -0x19C0
    ctx->r2 = ADD32(ctx->r2, -0X19C0);
    // 0x8001CB94: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
    // 0x8001CB98: addiu       $v0, $v1, 0x50
    ctx->r2 = ADD32(ctx->r3, 0X50);
    // 0x8001CB9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CBA0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CBA4: lui         $v0, 0xF550
    ctx->r2 = S32(0XF550 << 16);
    // 0x8001CBA8: sw          $v0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r2;
    // 0x8001CBAC: addiu       $v0, $v1, 0x58
    ctx->r2 = ADD32(ctx->r3, 0X58);
    // 0x8001CBB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CBB4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CBB8: lui         $v0, 0xF300
    ctx->r2 = S32(0XF300 << 16);
    // 0x8001CBBC: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x8001CBC0: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x8001CBC4: sw          $a2, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r6;
    // 0x8001CBC8: sw          $a1, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r5;
    // 0x8001CBCC: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x8001CBD0: sw          $a3, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r7;
    // 0x8001CBD4: sw          $a0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r4;
    // 0x8001CBD8: sw          $zero, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = 0;
    // 0x8001CBDC: sw          $a2, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r6;
    // 0x8001CBE0: sw          $a1, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r5;
    // 0x8001CBE4: sw          $zero, 0x54($v1)
    MEM_W(0X54, ctx->r3) = 0;
    // 0x8001CBE8: sw          $v0, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r2;
    // 0x8001CBEC: lui         $v0, 0xF200
    ctx->r2 = S32(0XF200 << 16);
    // 0x8001CBF0: sw          $a0, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r4;
    // 0x8001CBF4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8001CBF8: addiu       $a0, $a0, 0x25F8
    ctx->r4 = ADD32(ctx->r4, 0X25F8);
    // 0x8001CBFC: sw          $t0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r8;
    // 0x8001CC00: sw          $zero, 0x64($v1)
    MEM_W(0X64, ctx->r3) = 0;
    // 0x8001CC04: sw          $t1, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->r9;
    // 0x8001CC08: sw          $zero, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = 0;
    // 0x8001CC0C: sw          $v0, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->r2;
    // 0x8001CC10: sw          $t2, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->r10;
    // 0x8001CC14: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8001CC18: lui         $a2, 0xE447
    ctx->r6 = S32(0XE447 << 16);
    // 0x8001CC1C: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8001CC20: lui         $t1, 0x33
    ctx->r9 = S32(0X33 << 16);
    // 0x8001CC24: lui         $a3, 0xB400
    ctx->r7 = S32(0XB400 << 16);
    // 0x8001CC28: addiu       $v0, $v0, 0x48
    ctx->r2 = ADD32(ctx->r2, 0X48);
    // 0x8001CC2C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001CC30: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8001CC34: or          $v0, $v0, $t3
    ctx->r2 = ctx->r2 | ctx->r11;
    // 0x8001CC38: sw          $v0, 0x78($v1)
    MEM_W(0X78, ctx->r3) = ctx->r2;
    // 0x8001CC3C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8001CC40: lui         $a1, 0xB300
    ctx->r5 = S32(0XB300 << 16);
    // 0x8001CC44: lui         $a0, 0xA00
    ctx->r4 = S32(0XA00 << 16);
    // 0x8001CC48: sw          $a0, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r4;
    // 0x8001CC4C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8001CC50: addiu       $a0, $a0, 0x7A48
    ctx->r4 = ADD32(ctx->r4, 0X7A48);
    // 0x8001CC54: sw          $a3, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r7;
    // 0x8001CC58: sw          $a1, 0x88($v1)
    MEM_W(0X88, ctx->r3) = ctx->r5;
    // 0x8001CC5C: sw          $t4, 0x8C($v1)
    MEM_W(0X8C, ctx->r3) = ctx->r12;
    // 0x8001CC60: addiu       $v0, $v0, 0x36
    ctx->r2 = ADD32(ctx->r2, 0X36);
    // 0x8001CC64: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001CC68: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8001CC6C: or          $v0, $v0, $t5
    ctx->r2 = ctx->r2 | ctx->r13;
    // 0x8001CC70: sw          $v0, 0x7C($v1)
    MEM_W(0X7C, ctx->r3) = ctx->r2;
    // 0x8001CC74: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8001CC78: ori         $t1, $t1, 0x8000
    ctx->r9 = ctx->r9 | 0X8000;
    // 0x8001CC7C: lui         $t0, 0x400
    ctx->r8 = S32(0X400 << 16);
    // 0x8001CC80: addiu       $v0, $v0, 0x48
    ctx->r2 = ADD32(ctx->r2, 0X48);
    // 0x8001CC84: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001CC88: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8001CC8C: or          $v0, $v0, $a2
    ctx->r2 = ctx->r2 | ctx->r6;
    // 0x8001CC90: sw          $v0, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r2;
    // 0x8001CC94: lb          $a0, 0x0($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X0);
    // 0x8001CC98: ori         $t0, $t0, 0x400
    ctx->r8 = ctx->r8 | 0X400;
    // 0x8001CC9C: addiu       $v0, $v1, 0x60
    ctx->r2 = ADD32(ctx->r3, 0X60);
    // 0x8001CCA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CCA4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CCA8: addiu       $v0, $v1, 0x68
    ctx->r2 = ADD32(ctx->r3, 0X68);
    // 0x8001CCAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CCB0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CCB4: addiu       $v0, $v1, 0x70
    ctx->r2 = ADD32(ctx->r3, 0X70);
    // 0x8001CCB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CCBC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CCC0: addiu       $v0, $v1, 0x78
    ctx->r2 = ADD32(ctx->r3, 0X78);
    // 0x8001CCC4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CCC8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CCCC: addiu       $v0, $v1, 0x80
    ctx->r2 = ADD32(ctx->r3, 0X80);
    // 0x8001CCD0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CCD4: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CCD8: addiu       $v0, $v1, 0x88
    ctx->r2 = ADD32(ctx->r3, 0X88);
    // 0x8001CCDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CCE0: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CCE4: addiu       $v0, $v1, 0x90
    ctx->r2 = ADD32(ctx->r3, 0X90);
    // 0x8001CCE8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CCEC: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CCF0: addiu       $v0, $v1, 0x98
    ctx->r2 = ADD32(ctx->r3, 0X98);
    // 0x8001CCF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CCF8: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CCFC: addiu       $v0, $v1, 0xA0
    ctx->r2 = ADD32(ctx->r3, 0XA0);
    // 0x8001CD00: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CD04: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CD08: addiu       $v0, $v1, 0xA8
    ctx->r2 = ADD32(ctx->r3, 0XA8);
    // 0x8001CD0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CD10: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CD14: addiu       $v0, $v1, 0xB0
    ctx->r2 = ADD32(ctx->r3, 0XB0);
    // 0x8001CD18: sw          $a3, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r7;
    // 0x8001CD1C: sw          $zero, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = 0;
    // 0x8001CD20: sw          $a1, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->r5;
    // 0x8001CD24: addiu       $a0, $a0, 0x36
    ctx->r4 = ADD32(ctx->r4, 0X36);
    // 0x8001CD28: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8001CD2C: andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // 0x8001CD30: or          $a0, $a0, $t1
    ctx->r4 = ctx->r4 | ctx->r9;
    // 0x8001CD34: sw          $a0, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->r4;
    // 0x8001CD38: sw          $t0, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->r8;
    // 0x8001CD3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CD40: sw          $v0, 0x2FE4($at)
    MEM_W(0X2FE4, ctx->r1) = ctx->r2;
    // 0x8001CD44: sw          $t6, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->r14;
    // 0x8001CD48: jr          $ra
    // 0x8001CD4C: sw          $zero, 0xAC($v1)
    MEM_W(0XAC, ctx->r3) = 0;
    return;
    // 0x8001CD4C: sw          $zero, 0xAC($v1)
    MEM_W(0XAC, ctx->r3) = 0;
;}
RECOMP_FUNC void func_8001CD50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CD50: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001CD54: lbu         $v1, 0x7B86($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B86);
    // 0x8001CD58: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8001CD5C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001CD60: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8001CD64: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001CD68: addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // 0x8001CD6C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001CD70: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001CD74: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001CD78: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001CD7C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001CD80: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001CD84: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001CD88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001CD8C: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x8001CD90: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001CD94: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x8001CD98: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // 0x8001CD9C: lw          $s2, -0x4728($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X4728);
    // 0x8001CDA0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8001CDA4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001CDA8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001CDAC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001CDB0: addiu       $v1, $v1, -0x4D20
    ctx->r3 = ADD32(ctx->r3, -0X4D20);
    // 0x8001CDB4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x8001CDB8: addu        $s6, $v0, $v1
    ctx->r22 = ADD32(ctx->r2, ctx->r3);
    // 0x8001CDBC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001CDC0: beq         $a1, $v0, L_8001CF80
    if (ctx->r5 == ctx->r2) {
        // 0x8001CDC4: addu        $s5, $zero, $zero
        ctx->r21 = ADD32(0, 0);
            goto L_8001CF80;
    }
    // 0x8001CDC4: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x8001CDC8: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8001CDCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001CDD0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8001CDD4: addiu       $a2, $zero, 0x500
    ctx->r6 = ADD32(0, 0X500);
    // 0x8001CDD8: addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // 0x8001CDDC: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x8001CDE0: addiu       $s0, $a0, 0x1A
    ctx->r16 = ADD32(ctx->r4, 0X1A);
L_8001CDE4:
    // 0x8001CDE4: sb          $s4, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r20;
    // 0x8001CDE8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001CDEC: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x8001CDF0: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x8001CDF4: addiu       $a3, $a3, -0x4794
    ctx->r7 = ADD32(ctx->r7, -0X4794);
    // 0x8001CDF8: lbu         $v1, 0x1($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X1);
    // 0x8001CDFC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001CE00: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x8001CE04: lw          $s1, 0x0($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X0);
    // 0x8001CE08: sh          $v1, 0x52($s0)
    MEM_H(0X52, ctx->r16) = ctx->r3;
    // 0x8001CE0C: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8001CE10: sb          $s4, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r20;
    // 0x8001CE14: swc1        $f20, 0x1E($s0)
    MEM_W(0X1E, ctx->r16) = ctx->f20.u32l;
    // 0x8001CE18: swc1        $f20, 0x1A($s0)
    MEM_W(0X1A, ctx->r16) = ctx->f20.u32l;
    // 0x8001CE1C: sw          $s7, 0x2A($s0)
    MEM_W(0X2A, ctx->r16) = ctx->r23;
    // 0x8001CE20: sw          $s5, 0x2E($s0)
    MEM_W(0X2E, ctx->r16) = ctx->r21;
    // 0x8001CE24: sw          $zero, 0x36($s0)
    MEM_W(0X36, ctx->r16) = 0;
    // 0x8001CE28: sw          $zero, 0x32($s0)
    MEM_W(0X32, ctx->r16) = 0;
    // 0x8001CE2C: sb          $s4, 0x13($s0)
    MEM_B(0X13, ctx->r16) = ctx->r20;
    // 0x8001CE30: sb          $s4, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r20;
    // 0x8001CE34: sh          $zero, -0x12($s0)
    MEM_H(-0X12, ctx->r16) = 0;
    // 0x8001CE38: sb          $v0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r2;
    // 0x8001CE3C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001CE40: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001CE44: sh          $zero, 0x0($s3)
    MEM_H(0X0, ctx->r19) = 0;
    // 0x8001CE48: lbu         $v1, 0x10($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X10);
    // 0x8001CE4C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001CE50: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x8001CE54: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8001CE58: addiu       $v0, $v0, 0x3040
    ctx->r2 = ADD32(ctx->r2, 0X3040);
    // 0x8001CE5C: sw          $v0, -0xA($s0)
    MEM_W(-0XA, ctx->r16) = ctx->r2;
    // 0x8001CE60: ori         $v0, $zero, 0xFFF4
    ctx->r2 = 0 | 0XFFF4;
    // 0x8001CE64: sh          $a2, -0x18($s0)
    MEM_H(-0X18, ctx->r16) = ctx->r6;
    // 0x8001CE68: sh          $a1, -0x10($s0)
    MEM_H(-0X10, ctx->r16) = ctx->r5;
    // 0x8001CE6C: sh          $zero, -0xE($s0)
    MEM_H(-0XE, ctx->r16) = 0;
    // 0x8001CE70: sh          $zero, -0x16($s0)
    MEM_H(-0X16, ctx->r16) = 0;
    // 0x8001CE74: sh          $a2, -0x14($s0)
    MEM_H(-0X14, ctx->r16) = ctx->r6;
    // 0x8001CE78: sh          $a1, -0xC($s0)
    MEM_H(-0XC, ctx->r16) = ctx->r5;
    // 0x8001CE7C: sh          $v0, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r2;
    // 0x8001CE80: sb          $zero, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = 0;
    // 0x8001CE84: sb          $fp, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r30;
    // 0x8001CE88: sh          $zero, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = 0;
    // 0x8001CE8C: beq         $v1, $zero, L_8001CEA8
    if (ctx->r3 == 0) {
        // 0x8001CE90: sh          $zero, 0x0($s0)
        MEM_H(0X0, ctx->r16) = 0;
            goto L_8001CEA8;
    }
    // 0x8001CE90: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x8001CE94: addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // 0x8001CE98: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x8001CE9C: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x8001CEA0: j           L_8001CEC0
    // 0x8001CEA4: sw          $zero, 0x6($s0)
    MEM_W(0X6, ctx->r16) = 0;
        goto L_8001CEC0;
    // 0x8001CEA4: sw          $zero, 0x6($s0)
    MEM_W(0X6, ctx->r16) = 0;
L_8001CEA8:
    // 0x8001CEA8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8001CEAC: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // 0x8001CEB0: jal         0x80066D30
    // 0x8001CEB4: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    func_80066D30(rdram, ctx);
        goto after_0;
    // 0x8001CEB4: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001CEB8: lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X14);
    // 0x8001CEBC: lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10);
L_8001CEC0:
    // 0x8001CEC0: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x8001CEC4: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8001CEC8: sh          $v0, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r2;
    // 0x8001CECC: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    // 0x8001CED0: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8001CED4: sh          $v0, -0x12($s0)
    MEM_H(-0X12, ctx->r16) = ctx->r2;
    // 0x8001CED8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001CEDC: lbu         $v0, 0x7B86($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7B86);
    // 0x8001CEE0: bne         $v0, $zero, L_8001CF20
    if (ctx->r2 != 0) {
        // 0x8001CEE4: nop
    
            goto L_8001CF20;
    }
    // 0x8001CEE4: nop

    // 0x8001CEE8: lhu         $v0, 0x52($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X52);
    // 0x8001CEEC: addiu       $v0, $v0, -0x14
    ctx->r2 = ADD32(ctx->r2, -0X14);
    // 0x8001CEF0: sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // 0x8001CEF4: beq         $v0, $zero, L_8001CF20
    if (ctx->r2 == 0) {
        // 0x8001CEF8: addiu       $v0, $zero, 0x1C0
        ctx->r2 = ADD32(0, 0X1C0);
            goto L_8001CF20;
    }
    // 0x8001CEF8: addiu       $v0, $zero, 0x1C0
    ctx->r2 = ADD32(0, 0X1C0);
    // 0x8001CEFC: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8001CF00: addiu       $a3, $a3, 0x7F40
    ctx->r7 = ADD32(ctx->r7, 0X7F40);
    // 0x8001CF04: sw          $a3, 0x16($s0)
    MEM_W(0X16, ctx->r16) = ctx->r7;
    // 0x8001CF08: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8001CF0C: addiu       $a3, $a3, 0x6DC0
    ctx->r7 = ADD32(ctx->r7, 0X6DC0);
    // 0x8001CF10: sh          $v0, -0x18($s0)
    MEM_H(-0X18, ctx->r16) = ctx->r2;
    // 0x8001CF14: addiu       $v0, $zero, 0xA0
    ctx->r2 = ADD32(0, 0XA0);
    // 0x8001CF18: j           L_8001CF4C
    // 0x8001CF1C: sw          $a3, -0xA($s0)
    MEM_W(-0XA, ctx->r16) = ctx->r7;
        goto L_8001CF4C;
    // 0x8001CF1C: sw          $a3, -0xA($s0)
    MEM_W(-0XA, ctx->r16) = ctx->r7;
L_8001CF20:
    // 0x8001CF20: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8001CF24: addiu       $v0, $v0, 0x1018
    ctx->r2 = ADD32(ctx->r2, 0X1018);
    // 0x8001CF28: sw          $v0, 0x16($s0)
    MEM_W(0X16, ctx->r16) = ctx->r2;
    // 0x8001CF2C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8001CF30: addiu       $v0, $v0, 0x3A40
    ctx->r2 = ADD32(ctx->r2, 0X3A40);
    // 0x8001CF34: sw          $v0, -0xA($s0)
    MEM_W(-0XA, ctx->r16) = ctx->r2;
    // 0x8001CF38: lhu         $v0, 0x2($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X2);
    // 0x8001CF3C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001CF40: sh          $v0, -0x18($s0)
    MEM_H(-0X18, ctx->r16) = ctx->r2;
    // 0x8001CF44: lhu         $v0, 0x4($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X4);
    // 0x8001CF48: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
L_8001CF4C:
    // 0x8001CF4C: sh          $v0, -0x10($s0)
    MEM_H(-0X10, ctx->r16) = ctx->r2;
    // 0x8001CF50: sltiu       $v0, $s7, 0x1
    ctx->r2 = ctx->r23 < 0X1 ? 1 : 0;
    // 0x8001CF54: sb          $fp, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r30;
    // 0x8001CF58: sb          $s4, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r20;
    // 0x8001CF5C: sh          $zero, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = 0;
    // 0x8001CF60: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x8001CF64: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x8001CF68: addiu       $s3, $s3, 0x70
    ctx->r19 = ADD32(ctx->r19, 0X70);
    // 0x8001CF6C: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8001CF70: lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X0);
    // 0x8001CF74: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8001CF78: bne         $v1, $v0, L_8001CDE4
    if (ctx->r3 != ctx->r2) {
        // 0x8001CF7C: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8001CDE4;
    }
    // 0x8001CF7C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_8001CF80:
    // 0x8001CF80: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001CF84: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001CF88: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001CF8C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001CF90: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001CF94: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001CF98: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001CF9C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001CFA0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CFA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001CFA8: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x8001CFAC: jr          $ra
    // 0x8001CFB0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8001CFB0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8001CFB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CFB4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001CFB8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8001CFBC: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x8001CFC0: addiu       $s2, $s2, 0x7B86
    ctx->r18 = ADD32(ctx->r18, 0X7B86);
    // 0x8001CFC4: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8001CFC8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8001CFCC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8001CFD0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001CFD4: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8001CFD8: lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    // 0x8001CFDC: addiu       $s1, $s1, -0x2F90
    ctx->r17 = ADD32(ctx->r17, -0X2F90);
    // 0x8001CFE0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001CFE4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001CFE8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8001CFEC: lw          $a0, -0x6444($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6444);
    // 0x8001CFF0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8001CFF4: addiu       $a2, $zero, 0x690
    ctx->r6 = ADD32(0, 0X690);
    // 0x8001CFF8: jal         0x80006D98
    // 0x8001CFFC: addiu       $a0, $a0, 0x200
    ctx->r4 = ADD32(ctx->r4, 0X200);
    func_80006D98(rdram, ctx);
        goto after_0;
    // 0x8001CFFC: addiu       $a0, $a0, 0x200
    ctx->r4 = ADD32(ctx->r4, 0X200);
    after_0:
    // 0x8001D000: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
    // 0x8001D004: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8001D008: addiu       $a1, $a1, 0x1018
    ctx->r5 = ADD32(ctx->r5, 0X1018);
    // 0x8001D00C: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    // 0x8001D010: lui         $s3, 0x37
    ctx->r19 = S32(0X37 << 16);
    // 0x8001D014: addiu       $s3, $s3, -0x1030
    ctx->r19 = ADD32(ctx->r19, -0X1030);
    // 0x8001D018: sll         $a0, $a0, 9
    ctx->r4 = S32(ctx->r4 << 9);
    // 0x8001D01C: jal         0x80006D98
    // 0x8001D020: addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    func_80006D98(rdram, ctx);
        goto after_1;
    // 0x8001D020: addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    after_1:
    // 0x8001D024: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
    // 0x8001D028: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8001D02C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001D030: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001D034: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001D038: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8001D03C: lbu         $v1, -0x4D20($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X4D20);
    // 0x8001D040: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8001D044: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001D048: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001D04C: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8001D050: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8001D054: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x8001D058: mult        $v1, $a2
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001D05C: mflo        $a2
    ctx->r6 = lo;
    // 0x8001D060: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8001D064: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001D068: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8001D06C: lw          $v1, -0x6444($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6444);
    // 0x8001D070: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8001D074: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8001D078: addiu       $a1, $a1, 0x3A40
    ctx->r5 = ADD32(ctx->r5, 0X3A40);
    // 0x8001D07C: jal         0x80006D98
    // 0x8001D080: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    func_80006D98(rdram, ctx);
        goto after_2;
    // 0x8001D080: addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_2:
    // 0x8001D084: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8001D088: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x8001D08C: addiu       $s0, $s0, -0x6444
    ctx->r16 = ADD32(ctx->r16, -0X6444);
    // 0x8001D090: bne         $v0, $zero, L_8001D0D4
    if (ctx->r2 != 0) {
        // 0x8001D094: addiu       $a2, $zero, 0x1180
        ctx->r6 = ADD32(0, 0X1180);
            goto L_8001D0D4;
    }
    // 0x8001D094: addiu       $a2, $zero, 0x1180
    ctx->r6 = ADD32(0, 0X1180);
    // 0x8001D098: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8001D09C: lw          $a0, 0x63C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X63C);
    // 0x8001D0A0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8001D0A4: addiu       $a1, $a1, 0x6DC0
    ctx->r5 = ADD32(ctx->r5, 0X6DC0);
    // 0x8001D0A8: jal         0x80006D98
    // 0x8001D0AC: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    func_80006D98(rdram, ctx);
        goto after_3;
    // 0x8001D0AC: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_3:
    // 0x8001D0B0: addiu       $a0, $s3, 0xC00
    ctx->r4 = ADD32(ctx->r19, 0XC00);
    // 0x8001D0B4: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8001D0B8: addiu       $s0, $s0, 0x7F40
    ctx->r16 = ADD32(ctx->r16, 0X7F40);
    // 0x8001D0BC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8001D0C0: jal         0x80006D98
    // 0x8001D0C4: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    func_80006D98(rdram, ctx);
        goto after_4;
    // 0x8001D0C4: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_4:
    // 0x8001D0C8: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    // 0x8001D0CC: jal         0x8001D670
    // 0x8001D0D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001D670(rdram, ctx);
        goto after_5;
    // 0x8001D0D0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
L_8001D0D4:
    // 0x8001D0D4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8001D0D8: addiu       $a0, $a0, 0x6DB0
    ctx->r4 = ADD32(ctx->r4, 0X6DB0);
    // 0x8001D0DC: jal         0x8001CD50
    // 0x8001D0E0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_8001CD50(rdram, ctx);
        goto after_6;
    // 0x8001D0E0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_6:
    // 0x8001D0E4: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8001D0E8: addiu       $a0, $a0, 0x3830
    ctx->r4 = ADD32(ctx->r4, 0X3830);
    // 0x8001D0EC: jal         0x8001CD50
    // 0x8001D0F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8001CD50(rdram, ctx);
        goto after_7;
    // 0x8001D0F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8001D0F4: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x8001D0F8: lui         $s1, 0x8015
    ctx->r17 = S32(0X8015 << 16);
    // 0x8001D0FC: addiu       $s1, $s1, 0x260
    ctx->r17 = ADD32(ctx->r17, 0X260);
    // 0x8001D100: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8001D104: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001D108: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001D10C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8001D110: lw          $a0, -0x6648($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6648);
    // 0x8001D114: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    // 0x8001D118: lui         $s0, 0x37
    ctx->r16 = S32(0X37 << 16);
    // 0x8001D11C: addiu       $s0, $s0, -0x170
    ctx->r16 = ADD32(ctx->r16, -0X170);
    // 0x8001D120: jal         0x80006D98
    // 0x8001D124: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    func_80006D98(rdram, ctx);
        goto after_8;
    // 0x8001D124: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    after_8:
    // 0x8001D128: lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X0);
    // 0x8001D12C: addiu       $a1, $s1, 0x800
    ctx->r5 = ADD32(ctx->r17, 0X800);
    // 0x8001D130: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8001D134: addiu       $s0, $s0, -0xC0
    ctx->r16 = ADD32(ctx->r16, -0XC0);
    // 0x8001D138: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x8001D13C: jal         0x80006D98
    // 0x8001D140: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    func_80006D98(rdram, ctx);
        goto after_9;
    // 0x8001D140: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    after_9:
    // 0x8001D144: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8001D148: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8001D14C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8001D150: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8001D154: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001D158: jr          $ra
    // 0x8001D15C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8001D15C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8001D160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D160: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8001D164: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001D168: lbu         $v1, 0x7B86($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B86);
    // 0x8001D16C: lhu         $a0, 0x6C($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X6C);
    // 0x8001D170: addiu       $a3, $zero, 0xF6
    ctx->r7 = ADD32(0, 0XF6);
    // 0x8001D174: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8001D178: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8001D17C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001D180: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001D184: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8001D188: lw          $v1, -0x4794($at)
    ctx->r3 = MEM_W(ctx->r1, -0X4794);
    // 0x8001D18C: lw          $a0, 0x44($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X44);
    // 0x8001D190: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001D194: bne         $a0, $zero, L_8001D1A0
    if (ctx->r4 != 0) {
        // 0x8001D198: addu        $a2, $v1, $v0
        ctx->r6 = ADD32(ctx->r3, ctx->r2);
            goto L_8001D1A0;
    }
    // 0x8001D198: addu        $a2, $v1, $v0
    ctx->r6 = ADD32(ctx->r3, ctx->r2);
    // 0x8001D19C: addiu       $a3, $zero, 0x4A
    ctx->r7 = ADD32(0, 0X4A);
L_8001D1A0:
    // 0x8001D1A0: lbu         $v0, 0x4($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X4);
    // 0x8001D1A4: lwc1        $f2, 0x34($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8001D1A8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8001D1AC: nop

    // 0x8001D1B0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001D1B4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001D1B8: lbu         $a0, 0x29($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X29);
    // 0x8001D1BC: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001D1C0: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8001D1C4: nop

    // 0x8001D1C8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001D1CC: sh          $v0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r2;
    // 0x8001D1D0: addiu       $v0, $a0, -0xC
    ctx->r2 = ADD32(ctx->r4, -0XC);
    // 0x8001D1D4: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8001D1D8: bne         $v0, $zero, L_8001D1F4
    if (ctx->r2 != 0) {
        // 0x8001D1DC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001D1F4;
    }
    // 0x8001D1DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001D1E0: addiu       $v0, $a0, -0x1A
    ctx->r2 = ADD32(ctx->r4, -0X1A);
    // 0x8001D1E4: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8001D1E8: bne         $v0, $zero, L_8001D1F4
    if (ctx->r2 != 0) {
        // 0x8001D1EC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001D1F4;
    }
    // 0x8001D1EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001D1F0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8001D1F4:
    // 0x8001D1F4: beq         $v0, $zero, L_8001D208
    if (ctx->r2 == 0) {
        // 0x8001D1F8: nop
    
            goto L_8001D208;
    }
    // 0x8001D1F8: nop

    // 0x8001D1FC: lbu         $v0, 0x5($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X5);
    // 0x8001D200: j           L_8001D230
    // 0x8001D204: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
        goto L_8001D230;
    // 0x8001D204: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
L_8001D208:
    // 0x8001D208: lbu         $v0, 0x5($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X5);
    // 0x8001D20C: lwc1        $f2, 0x38($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X38);
    // 0x8001D210: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8001D214: nop

    // 0x8001D218: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001D21C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001D220: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001D224: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8001D228: nop

    // 0x8001D22C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
L_8001D230:
    // 0x8001D230: sh          $v0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r2;
    // 0x8001D234: lhu         $v0, 0x1A($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X1A);
    // 0x8001D238: beq         $v0, $zero, L_8001D27C
    if (ctx->r2 == 0) {
        // 0x8001D23C: nop
    
            goto L_8001D27C;
    }
    // 0x8001D23C: nop

    // 0x8001D240: lh          $v0, 0x6($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X6);
    // 0x8001D244: lbu         $v1, 0x4($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X4);
    // 0x8001D248: lw          $a0, 0x50($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X50);
    // 0x8001D24C: lwc1        $f0, 0x34($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8001D250: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001D254: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001D258: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8001D25C: nop

    // 0x8001D260: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8001D264: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001D268: mtc1        $a3, $f0
    ctx->f0.u32l = ctx->r7;
    // 0x8001D26C: nop

    // 0x8001D270: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001D274: j           L_8001D2AC
    // 0x8001D278: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_8001D2AC;
    // 0x8001D278: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_8001D27C:
    // 0x8001D27C: lh          $v0, 0x6($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X6);
    // 0x8001D280: lw          $v1, 0x50($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X50);
    // 0x8001D284: lwc1        $f0, 0x34($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8001D288: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001D28C: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8001D290: nop

    // 0x8001D294: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8001D298: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001D29C: mtc1        $a3, $f0
    ctx->f0.u32l = ctx->r7;
    // 0x8001D2A0: nop

    // 0x8001D2A4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001D2A8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_8001D2AC:
    // 0x8001D2AC: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001D2B0: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8001D2B4: nop

    // 0x8001D2B8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001D2BC: sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    // 0x8001D2C0: lbu         $v1, 0x29($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X29);
    // 0x8001D2C4: addiu       $v0, $v1, -0xC
    ctx->r2 = ADD32(ctx->r3, -0XC);
    // 0x8001D2C8: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8001D2CC: bne         $v0, $zero, L_8001D2E8
    if (ctx->r2 != 0) {
        // 0x8001D2D0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001D2E8;
    }
    // 0x8001D2D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001D2D4: addiu       $v0, $v1, -0x1A
    ctx->r2 = ADD32(ctx->r3, -0X1A);
    // 0x8001D2D8: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8001D2DC: bne         $v0, $zero, L_8001D2E8
    if (ctx->r2 != 0) {
        // 0x8001D2E0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001D2E8;
    }
    // 0x8001D2E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001D2E4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8001D2E8:
    // 0x8001D2E8: beq         $v0, $zero, L_8001D32C
    if (ctx->r2 == 0) {
        // 0x8001D2EC: nop
    
            goto L_8001D32C;
    }
    // 0x8001D2EC: nop

    // 0x8001D2F0: lh          $v0, 0x8($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X8);
    // 0x8001D2F4: lbu         $a0, 0x5($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X5);
    // 0x8001D2F8: lw          $v1, 0x4C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4C);
    // 0x8001D2FC: lwc1        $f2, 0x38($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X38);
    // 0x8001D300: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8001D304: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001D308: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8001D30C: nop

    // 0x8001D310: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001D314: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001D318: mtc1        $a0, $f2
    ctx->f2.u32l = ctx->r4;
    // 0x8001D31C: nop

    // 0x8001D320: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8001D324: j           L_8001D34C
    // 0x8001D328: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_8001D34C;
    // 0x8001D328: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_8001D32C:
    // 0x8001D32C: lh          $v0, 0x8($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X8);
    // 0x8001D330: lw          $v1, 0x4C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4C);
    // 0x8001D334: lwc1        $f2, 0x38($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X38);
    // 0x8001D338: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001D33C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8001D340: nop

    // 0x8001D344: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001D348: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
L_8001D34C:
    // 0x8001D34C: lui         $at, 0x4358
    ctx->r1 = S32(0X4358 << 16);
    // 0x8001D350: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001D354: nop

    // 0x8001D358: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8001D35C: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001D360: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8001D364: nop

    // 0x8001D368: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001D36C: sh          $v0, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r2;
    // 0x8001D370: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x8001D374: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001D378: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001D37C: sra         $v0, $v0, 18
    ctx->r2 = S32(SIGNED(ctx->r2) >> 18);
    // 0x8001D380: slti        $v0, $v0, 0x13D
    ctx->r2 = SIGNED(ctx->r2) < 0X13D ? 1 : 0;
    // 0x8001D384: bne         $v0, $zero, L_8001D390
    if (ctx->r2 != 0) {
        // 0x8001D388: sb          $v1, 0x2E($a1)
        MEM_B(0X2E, ctx->r5) = ctx->r3;
            goto L_8001D390;
    }
    // 0x8001D388: sb          $v1, 0x2E($a1)
    MEM_B(0X2E, ctx->r5) = ctx->r3;
    // 0x8001D38C: sb          $zero, 0x2E($a1)
    MEM_B(0X2E, ctx->r5) = 0;
L_8001D390:
    // 0x8001D390: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x8001D394: lhu         $v1, 0x6($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X6);
    // 0x8001D398: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001D39C: sra         $v0, $v0, 18
    ctx->r2 = S32(SIGNED(ctx->r2) >> 18);
    // 0x8001D3A0: srl         $v1, $v1, 2
    ctx->r3 = S32(U32(ctx->r3) >> 2);
    // 0x8001D3A4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001D3A8: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8001D3AC: bnel        $v0, $zero, L_8001D3B4
    if (ctx->r2 != 0) {
        // 0x8001D3B0: sb          $zero, 0x2E($a1)
        MEM_B(0X2E, ctx->r5) = 0;
            goto L_8001D3B4;
    }
    goto skip_0;
    // 0x8001D3B0: sb          $zero, 0x2E($a1)
    MEM_B(0X2E, ctx->r5) = 0;
    skip_0:
L_8001D3B4:
    // 0x8001D3B4: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8001D3B8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001D3BC: sra         $v0, $v0, 18
    ctx->r2 = S32(SIGNED(ctx->r2) >> 18);
    // 0x8001D3C0: slti        $v0, $v0, 0xED
    ctx->r2 = SIGNED(ctx->r2) < 0XED ? 1 : 0;
    // 0x8001D3C4: beql        $v0, $zero, L_8001D3CC
    if (ctx->r2 == 0) {
        // 0x8001D3C8: sb          $zero, 0x2E($a1)
        MEM_B(0X2E, ctx->r5) = 0;
            goto L_8001D3CC;
    }
    goto skip_1;
    // 0x8001D3C8: sb          $zero, 0x2E($a1)
    MEM_B(0X2E, ctx->r5) = 0;
    skip_1:
L_8001D3CC:
    // 0x8001D3CC: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8001D3D0: lhu         $v1, 0xE($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0XE);
    // 0x8001D3D4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001D3D8: sra         $v0, $v0, 18
    ctx->r2 = S32(SIGNED(ctx->r2) >> 18);
    // 0x8001D3DC: srl         $v1, $v1, 2
    ctx->r3 = S32(U32(ctx->r3) >> 2);
    // 0x8001D3E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001D3E4: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8001D3E8: bnel        $v0, $zero, L_8001D3F0
    if (ctx->r2 != 0) {
        // 0x8001D3EC: sb          $zero, 0x2E($a1)
        MEM_B(0X2E, ctx->r5) = 0;
            goto L_8001D3F0;
    }
    goto skip_2;
    // 0x8001D3EC: sb          $zero, 0x2E($a1)
    MEM_B(0X2E, ctx->r5) = 0;
    skip_2:
L_8001D3F0:
    // 0x8001D3F0: lwc1        $f2, 0x34($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8001D3F4: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8001D3F8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001D3FC: nop

    // 0x8001D400: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001D404: lbu         $a0, 0x29($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X29);
    // 0x8001D408: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001D40C: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8001D410: nop

    // 0x8001D414: sh          $v0, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r2;
    // 0x8001D418: addiu       $v0, $a0, -0xC
    ctx->r2 = ADD32(ctx->r4, -0XC);
    // 0x8001D41C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8001D420: bne         $v0, $zero, L_8001D43C
    if (ctx->r2 != 0) {
        // 0x8001D424: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001D43C;
    }
    // 0x8001D424: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001D428: addiu       $v0, $a0, -0x1A
    ctx->r2 = ADD32(ctx->r4, -0X1A);
    // 0x8001D42C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8001D430: bne         $v0, $zero, L_8001D43C
    if (ctx->r2 != 0) {
        // 0x8001D434: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001D43C;
    }
    // 0x8001D434: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001D438: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8001D43C:
    // 0x8001D43C: bne         $v0, $zero, L_8001D468
    if (ctx->r2 != 0) {
        // 0x8001D440: nop
    
            goto L_8001D468;
    }
    // 0x8001D440: nop

    // 0x8001D444: lwc1        $f2, 0x38($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X38);
    // 0x8001D448: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8001D44C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001D450: nop

    // 0x8001D454: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001D458: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001D45C: mfc1        $v0, $f2
    ctx->r2 = (int32_t)ctx->f2.u32l;
    // 0x8001D460: nop

    // 0x8001D464: sh          $v0, 0x1E($a1)
    MEM_H(0X1E, ctx->r5) = ctx->r2;
L_8001D468:
    // 0x8001D468: jr          $ra
    // 0x8001D46C: nop

    return;
    // 0x8001D46C: nop

;}
RECOMP_FUNC void func_8001D470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D470: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x8001D474: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8001D478: lbu         $v1, 0x7B86($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7B86);
    // 0x8001D47C: addiu       $t0, $zero, 0xF6
    ctx->r8 = ADD32(0, 0XF6);
    // 0x8001D480: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8001D484: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8001D488: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8001D48C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001D490: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x8001D494: lw          $v1, -0x4794($at)
    ctx->r3 = MEM_W(ctx->r1, -0X4794);
    // 0x8001D498: lw          $a0, 0x44($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X44);
    // 0x8001D49C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8001D4A0: bne         $a0, $zero, L_8001D4AC
    if (ctx->r4 != 0) {
        // 0x8001D4A4: addu        $a2, $v1, $v0
        ctx->r6 = ADD32(ctx->r3, ctx->r2);
            goto L_8001D4AC;
    }
    // 0x8001D4A4: addu        $a2, $v1, $v0
    ctx->r6 = ADD32(ctx->r3, ctx->r2);
    // 0x8001D4A8: addiu       $t0, $zero, 0x4A
    ctx->r8 = ADD32(0, 0X4A);
L_8001D4AC:
    // 0x8001D4AC: sh          $a1, 0x6C($a3)
    MEM_H(0X6C, ctx->r7) = ctx->r5;
    // 0x8001D4B0: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x8001D4B4: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8001D4B8: sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    // 0x8001D4BC: lhu         $v0, 0x2($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2);
    // 0x8001D4C0: lhu         $v1, 0x1A($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X1A);
    // 0x8001D4C4: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8001D4C8: beq         $v1, $zero, L_8001D4E4
    if (ctx->r3 == 0) {
        // 0x8001D4CC: sh          $v0, 0x8($a3)
        MEM_H(0X8, ctx->r7) = ctx->r2;
            goto L_8001D4E4;
    }
    // 0x8001D4CC: sh          $v0, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r2;
    // 0x8001D4D0: lbu         $v1, 0x4($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X4);
    // 0x8001D4D4: lhu         $v0, 0x6($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X6);
    // 0x8001D4D8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8001D4DC: j           L_8001D4EC
    // 0x8001D4E0: subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
        goto L_8001D4EC;
    // 0x8001D4E0: subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
L_8001D4E4:
    // 0x8001D4E4: lhu         $v0, 0x6($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X6);
    // 0x8001D4E8: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
L_8001D4EC:
    // 0x8001D4EC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001D4F0: sh          $v0, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r2;
    // 0x8001D4F4: lhu         $v0, 0x8($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X8);
    // 0x8001D4F8: addiu       $v0, $v0, 0xD8
    ctx->r2 = ADD32(ctx->r2, 0XD8);
    // 0x8001D4FC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001D500: sh          $v0, 0xC($a3)
    MEM_H(0XC, ctx->r7) = ctx->r2;
    // 0x8001D504: lbu         $v0, 0x4($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X4);
    // 0x8001D508: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001D50C: sh          $v0, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r2;
    // 0x8001D510: lbu         $v0, 0x5($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X5);
    // 0x8001D514: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8001D518: jr          $ra
    // 0x8001D51C: sh          $v0, 0xE($a3)
    MEM_H(0XE, ctx->r7) = ctx->r2;
    return;
    // 0x8001D51C: sh          $v0, 0xE($a3)
    MEM_H(0XE, ctx->r7) = ctx->r2;
;}
